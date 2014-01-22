import string
import xlrd
import PSW_Basic_Log
import PSW_Spreadsheet

Log_Debug = PSW_Basic_Log.Log_Debug
Log_Info  = PSW_Basic_Log.Log_Info
Log_Warn  = PSW_Basic_Log.Log_Warn
Log_Error = PSW_Basic_Log.Log_Error
Log_Fatal = PSW_Basic_Log.Log_Fatal
Quit      = PSW_Basic_Log.Quit
as_int    = PSW_Spreadsheet.as_int

# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# Global data
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
g_enum = {}
g_rec_fields_by_order = []
g_rec_fields_by_name  = {}
g_rec_size_by_name    = {}    # 0 if message is dynamic size
g_Py_Pack      = ''
g_Py_Unpack    = ''
g_C_Coder      = ''
g_C_Proto      = ''
g_Aux_Dec      = ''
g_Msg_Dec      = ''
g_Enum_Dec     = ''
g_Enum_Cnt     = 1000
g_Test_Funcs   = ''
g_Test_Calls   = ''
g_Test_Counter = 0

# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# Utilities
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
def Make_Valid_C_Var(text):
    # Characters to ignore/remove.
    # This is based on the current practices of the ICD in use and is not universal.
    # All other non-alphanum are swapped with underscore.
    to_ignore = '#()"'
    var = ''
    try:
        for c in text:
            if c not in to_ignore:
                var += c if c.isalnum() else '_'
    except Exception as ex:
        Log_Debug('Make_Valid_C_Var - Cannot parse text <%s>' % text)
        Log_Debug(ex)
    # The leading character must be a non-digit, so prefix with '_' if needed.
    if var == '':
        var = '_var'
    elif not var[0].isalpha():
        var = '_' + var
    #Log_Debug('Make_Valid_C_Var  text <%s> -> var <%s>' % (text, var))
    return var
# ------------------------------------------------------------------------------
def Is_Valid_C_Var(text):
    return text == Make_Valid_C_Var(text)
# ------------------------------------------------------------------------------
def Make_Valid_C_Enum(text, is_type = False):
    var = Make_Valid_C_Var(text)
    if is_type:
        var = 'T_%s' % var    # Choosing this convention for enum values.  NOT UNIVERSAL
    else:
        global g_Enum_Cnt
        var = 'E_%d_%s' % (g_Enum_Cnt, var)   # Choosing this convention for enum values.  NOT UNIVERSAL
        g_Enum_Cnt += 1
    return var
# ------------------------------------------------------------------------------
def Indent(level, text):
    if level > 0:
        indent = level * '    '
        count  = text.count('\n')
        if count > 1:   # Do not add spaces to any final '\n'
            text = string.replace(text, '\n', '\n' + indent, count-1)
        if count >= 1:
            text = indent + text
    return text
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# Record Processing
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
def Validate_Row(block_start_row, field_index, row):
    try:
        row['INDEX'] = int(row['INDEX'])
    except:
        Log_Error('INDEX must be a number not <%s> - start_row <%d>' %
                (row['INDEX'], block_start_row))
        return False

    if row['INDEX'] < 0:
        Log_Error('INDEX cannot be negative <%d> - start_row <%d>' %
                (row['INDEX'], block_start_row))
        return False

    if row['INDEX'] != field_index:
        Log_Warn('Index is not sequential - found <%d> expected <%d> - start_row <%d>' %
                (row['INDEX'], field_index, block_start_row))

    if not Is_Valid_C_Var(row['TYPE']):
        Log_Warn('TYPE field has invalid chars <%s> - start_row <%d>' %
                (row['TYPE'], block_start_row))
        row['TYPE'] = Make_Valid_C_Var(row['TYPE'])

    if row['FORMAT'] != '':
        if not Is_Valid_C_Var(row['FORMAT'].replace('ENUM-', '')):
            Log_Warn('FORMAT field has invalid chars <%s> - start_row <%d>' %
                    (row['FORMAT'], block_start_row))
            row['TYPE'] = Make_Valid_C_Var(row['TYPE'])

    if row['COUNT_DEFINED_BY'] != '' and row['FIXED_VALUE'] != '':
        Log_Warn('COUNT_DEFINED_BY and FIXED_VALUE are mutually exclusive.  FIXED_VALUE <%s> ignored - start_row <%d>' %
                (row['FIXED_VALUE'], block_start_row))
        row['FIXED_VALUE'] = ''

    # TODO STRING cannot have a COUNT_DEFINED_BY; if it occurs, error with message 'use CHAR instead'
    # TODO COUNT_DEFINED_BY must be '#<num>' or else INDEX [1 .. this_row_index-1] to field of [U]INT type
    # TODO SPECIAL_CONTROL fields must be regular [U]INT#
    # TODO Cannot have an FIXED_VALUE or DEFAULT_VALUE for field with COUNT_DEFINED_BY or type STRUCT
    # TODO MIN_RANGE/MAX_RANGE only work for [U]INT and FLOAT

    return True  # No error or error can be ignored/worked around.
# ------------------------------------------------------------------------------
def Find_Next_Block(table, start_row):
    ''' Finds the next set of contiguous non-blank rows. '''
    # Find next non-blank row or end of table.
    while (start_row < len(table)) and table[start_row]['INDEX'] == '':
        start_row += 1
    # Process until blank row or end of table.
    end_row = start_row
    while (end_row < len(table)) and table[end_row]['INDEX'] != '':
        end_row += 1
    return (start_row, end_row)
# ------------------------------------------------------------------------------
def Process_Block(block_start_row, block_cells):
    rec_name    = ''
    rec_fields  = []
    field_index = 0    # Counter to validate the expected sequential INDEX value.

    for row in block_cells:
        if not Validate_Row(block_start_row, field_index, row):
            continue

        field = { 'type':          Make_Valid_C_Var(row['TYPE']),
                  'name':          Make_Valid_C_Var(row['NAME']),
                  'fmt':           Make_Valid_C_Var(row['FORMAT']),
                  'rel_count':     0,
                  'abs_count':     0,
                  'value':         str(row['FIXED_VALUE']),
                  'special':       row['SPECIAL_CONTROL'],
                  'msg_id':        row['SPECIAL_CONTROL'] == 'MSG_ID',
                  'msg_size_8':    row['SPECIAL_CONTROL'] == 'MSG_SIZE_8',
                  'msg_size_16':   row['SPECIAL_CONTROL'] == 'MSG_SIZE_16',
                  'msg_size_32':   row['SPECIAL_CONTROL'] == 'MSG_SIZE_32',
                  'crc_16':        row['SPECIAL_CONTROL'] == 'CRC_16',
                  'crc_32':        row['SPECIAL_CONTROL'] == 'CRC_32',
                  'size_excludes': row['EXCLUDE_FROM_SIZE'] == 'TRUE',
                  'fixed_size':    0,
        }

        count = str(row['COUNT_DEFINED_BY'])
        if count != '':
            if count[0] == '#':
                field['abs_count'] = as_int(count[1:])
            else:
                field['rel_count'] = as_int(count)

        # Treat 'CHARx' as shorthand for 'CHAR' plus COUNT_DEFINED_BY = '#x'.
        # This simplifies a lot of subsequent handling.
        if field['type'].startswith('CHAR'):
             if field['type'] == 'CHAR':
                 field['abs_count'] = 1  # Single char should be rare, but treat it as CHAR[1] for simplicity.
                 field['type']      = 'CHAR'
             else:
                 field['abs_count'] = as_int(field['type'].replace('CHAR',''))
                 field['type']      = 'CHAR'

        if row['INDEX'] == 0:
            Log_Debug('Processing new block Record Type <%s> Record Name <%s>' % (field['type'], field['fmt']))
            rec_name = field['fmt']
            if field['type'] != 'Message' and field['type'] != 'Aux':
                Log_Error('Unrecognized Record TYPE <%s> - start_row <%d>' % (field['type'], block_start_row))
                Log_Error('Expected "Message" or "Aux".  Cannot process this block.')
                return None, None

        rec_fields.append(field)
        field_index += 1

    fixed, size = Compute_Fixed_Size(rec_name, rec_fields)
    g_rec_size_by_name[rec_name] = size

    for field in rec_fields:
        if field['special'] in ('MSG_SIZE_16', 'MSG_SIZE_32'):
            if fixed and (field['value'] == ''):
                field['value'] = str(size)
            elif fixed and (as_int(field['value']) != size):
                Log_Warn('FIXED_VALUE <%s> for SPECIAL_CONTROL <%s> does not match computed value <%d>' %
                        (field['value'], field['special'], size))
                field['value'] = str(size)
            elif not fixed and (row['FIXED_VALUE'] != ''):
                Log_Warn('FIXED_VALUE <%s> for SPECIAL_CONTROL <%s> - ignored since message struct is not a fixed size.' %
                        (field['value'], field['special']))
                field['value'] = ''

    if rec_name == '':
        Log_Error('Missing INDEX [0] Record TYPE or FORMAT - start_row <%d>' % (block_start_row))
        Log_Error('Expected "Message" or "Aux" in TYPE with a message name in FORMAT.  Cannot process this block.')
        return None, None
    else:
        return rec_name, rec_fields
# ------------------------------------------------------------------------------
def Get_Value_For_Defined_By(abs_count, rel_count, rec_fields, field_parent):
    ''' Used for COUNT_DEFINED_BY to resolve absolute (#) versus relative references to the usable value. '''
    if abs_count > 0:
       return abs_count
    elif rel_count in range(1, len(rec_fields)):
       return field_parent + rec_fields[rel_count]['name']
    # Parsing/range error.
    return None
# ------------------------------------------------------------------------------
def Create_C_Struct(rec_name, rec_fields):
    # Skip rec_field[0] since it is the structure name field.
    body = ''
    for field in rec_fields[1:]:
        field_type = field['type']
        field_fmt  = field['fmt']
        ptr, ary = '', ''
        if field['abs_count'] > 0:
            ary = '[%d]' % field['abs_count']
        elif field['rel_count'] > 0:
            ptr = '*'

        if field_type == 'STRUCT':
            body += '    %-20s%s %s%s;\n' % (field_fmt, ptr, field['name'], ary)
        elif field_type == 'VARIANT_ARRAY':
            #body += '    %-20s%s %s%s;\n' % (field_fmt, ptr, field['name'], ary)
            pass # TODO
        elif field_type == 'VARIANT_LIST':
            #body += '    %-20s%s %s%s;\n' % (field_fmt, ptr, field['name'], ary)
            pass # TODO
        elif field_type == 'VARIANT_ITEM':
            #body += '    %-20s%s %s%s;\n' % (field_fmt, ptr, field['name'], ary)
            pass  # TODO
        else:
            body += '    %-20s%s %s%s;\n' % (field_type, ptr, field['name'], ary)

    global g_Aux_Dec, g_Msg_Dec
    if rec_fields[0]['type'] == 'Aux':
        g_Aux_Dec += 'typedef struct {\n' + body + '} ' + rec_name + ';\n'
    else:
        g_Msg_Dec += 'typedef struct {\n' + body + '} ' + rec_name + ';\n'
# ------------------------------------------------------------------------------
def Compute_Fixed_Size(rec_name, rec_fields):
    type_sizes = {
            'UINT8':8,   'INT8':8,  'CHAR':8,
            'UINT16':16, 'INT16':16,
            'UINT32':32, 'INT32':32, 'FLOAT32':32,
            'UINT64':64, 'INT64':64, 'FLOAT64':64,
            }
    bit_size = 0
    for field in rec_fields[1:]:
        if field['size_excludes']:
            continue
        elif field['rel_count'] > 0:
            return False, 0
        else:
            mult = field['abs_count'] if field['abs_count'] > 0 else 1

        if type_sizes.has_key(field['type']):
            bit_size += type_sizes[field['type']] * mult
        elif field['type'] == 'STRING':
            return False, 0
        elif field['type'] == 'STRUCT':
            if g_rec_fields_by_name.has_key(field['fmt']):
                aux_fixed, aux_size = Compute_Fixed_Size(field['fmt'], g_rec_fields_by_name[field['fmt']])
                if aux_fixed:
                    bit_size += aux_size
                else:
                    return False, 0
    return True, bit_size/8
# ------------------------------------------------------------------------------
def Get_C_Field_Coder(dir_suffix, size_suffix, field_parent, field_name, field_loop_index, fixed_size=0):
    fixed_size_str = (', %d' % fixed_size) if fixed_size > 0 else ''
    return 'byte_offset = %s_Endian_%s(buffer, buffer_max, byte_offset, (BYTE*)&(%s%s%s)%s);\n' % \
            (dir_suffix, size_suffix, field_parent, field_name, field_loop_index, fixed_size_str)
# ------------------------------------------------------------------------------
def Get_C_Field_Value_Coder(dir_suffix, size_suffix, field_parent, field_name, field_loop_index, field_type, fixed_value, fixed_size=0):
    ''' Used for fields that have a FIXED_VALUE. '''
    body  = '%s%s%s = (%s) %s;\n' % (field_parent, field_name, field_loop_index, field_type, fixed_value)
    fixed_size_str = (', %d' % fixed_size) if fixed_size > 0 else ''
    body += 'byte_offset = %s_Endian_%s(buffer, buffer_max, byte_offset, (BYTE*)&(%s%s%s)%s);\n' % \
             (dir_suffix, size_suffix, field_parent, field_name, field_loop_index, fixed_size_str)
    return body
# ------------------------------------------------------------------------------
def Get_C_Field_Value_Coder_Keep_Offset(dir_suffix, size_suffix, field_parent, field_name, field_loop_index, field_type, fixed_value, fixed_size=0):
    ''' Used for MSG_SIZE assignments that need to preserve the byte_offset. '''
    # The byte_offset indicates the complete computed size of the message,
    # and this value is used in MSG_SIZE and CRC calculations.
    # If the standard method were used, then the call would have to be wrapped
    # in a bunch of kludgy temp assignments to restore it.
    body  = '%s%s%s = (%s) %s;\n' % (field_parent, field_name, field_loop_index, field_type, fixed_value)
    fixed_size_str = (', %d' % fixed_size) if fixed_size > 0 else ''
    body += '(void) %s_Endian_%s(buffer, buffer_max, byte_offset, (BYTE*)&(%s%s%s)%s);\n' % \
             (dir_suffix, size_suffix, field_parent, field_name, field_loop_index, fixed_size_str)
    return body
# ------------------------------------------------------------------------------
def Get_C_Struct_Coder_Size_Suffix(field_type):
    ''' Determine the XX part of "[Un]Pack_Endian_XX" based on field type. '''
    if field_type in ('UINT8',  'INT8'):              return '08'
    if field_type in ('UINT16', 'INT16'):             return '16'
    if field_type in ('UINT32', 'INT32', 'FLOAT32'):  return '32'
    if field_type in ('UINT64', 'INT64', 'FLOAT64'):  return '64'
    return ''
# ------------------------------------------------------------------------------
def Create_C_Msg_Size_Coder(rec_name, rec_fields, msg_size_field_num, field_parent):
    if msg_size_field_num > 0:
        field = rec_fields[msg_size_field_num]
        fixed, msg_size_offset = Compute_Fixed_Size(rec_name, rec_fields[1:msg_size_field_num])
        if fixed:
            field_suffix = Get_C_Struct_Coder_Size_Suffix(field['type'])
            return Get_C_Field_Value_Coder_Keep_Offset('Pack', field_suffix, field_parent, field['name'], '', field['type'], 'byte_offset')
        else:
            Log_Error('The MSG_SIZE field for message <%s> is not at a fixed offset and cannot be correctly populated.' % rec_name)
            return ''
    else:
        return ''
# ------------------------------------------------------------------------------
def Create_C_Msg_Crc_Coder(rec_name, rec_fields, msg_crc_field_num, field_parent):
    if msg_crc_field_num > 0:
        field = rec_fields[msg_crc_field_num]
        if field['type'] == 'UINT16':
            msg_crc_call = 'Calculate_CRC16(buffer, byte_offset)'
            field_suffix  = '16'
        elif field['type'] == 'UINT32':
            msg_crc_call = 'Calculate_CRC32(buffer, byte_offset)'
            field_suffix  = '32'
        else:
            Log_Error('The CRC field for message <%s> is not UINT16 or UINT32 and cannot be correctly populated.' % rec_name)
            return ''
        return Get_C_Field_Value_Coder('Pack', field_suffix, field_parent, field['name'], '', field['type'], msg_crc_call)
    else:
        return ''
# ------------------------------------------------------------------------------
def Create_C_Struct_Coder(dir_suffix, rec_name, rec_fields, field_parent='data->'):

    # Note: All fields are assumed to be validated by this point, so
    #       many possible integrity checks are omitted.

    body                     = ''
    field_num                = 0
    msg_crc_field_num        = 0
    msg_size_field_num       = 0

    for field in rec_fields[1:]:
        field_num       += 1
        field_loop_max   = Get_Value_For_Defined_By(field['abs_count'], field['rel_count'], rec_fields, field_parent)
        field_loop_index = '[f]' if field_loop_max else ''
        size_suffix      = Get_C_Struct_Coder_Size_Suffix(field['type'])

        if field_loop_max:   # Absolute count; max is an integer.
            body += '{ int f; for(f = 0; f < %s; f++) {\n' % field_loop_max

        # Handle special conditions:
        #    1) For Pack: assign any FIXED_VALUE directly to the struct field   TODO - Uh oh... what about error testing?!
        #    2) For Pack: Note the CRC field, if any, so it can be calculated/assigned last.
        #    3) For Pack: Note the CRC field, if any, so it can be calculated/assigned last.
        #    4) For Unpack: for dynamic sized structs, create the memory for the dynamic parts (i.e. pointer mallocs).
        if dir_suffix == 'Pack':
            if field['value'] != '':
                body += Get_C_Field_Value_Coder(dir_suffix, size_suffix, field_parent, field['name'], field_loop_index, field['type'], field['value'])
                continue
            elif field['special'].startswith('MSG_SIZE'):
                # If the message size is fixed, then field['value'] was already assigned and handled above.
                # This will block will therefore only be used for dynamic sized messages.
                msg_size_field_num = field_num
            elif field['special'].startswith('CRC'):
# TODO - This method only works well with CRC as last field.
# TODO - A more general method would be a DBD-based EXCLUDE_FROM_CRC method that allows any initial/final fields to be omitted.
# TODO - In this case, the loader should calculate field['crc_start_field'] and field['crc_end_field'] and the byte offsets would need to be determined last.
# TODO - In fact, this implementation is bugged... to get size correct, must output a bogus CRC but then the CRC calculation is thrown off :(
                msg_crc_field_num = field_num

        elif dir_suffix == 'Unpack':
            alloc_type = field['fmt'] if field['type'] == 'STRUCT' else field['type']

            if field['abs_count'] > 0:
#               if field['type'] == 'STRUCT' or field['type'] == 'STRING':
#                   body += '%s%s[f] = (%s*) Mem_Alloc(%d, sizeof(%s));\n' % (field_parent, field['name'], alloc_type, field['abs_count'], alloc_type)
                pass
            elif field_loop_max:         # Relative count; field_loop_max is a field name.
# TODO The 'sizeof()' will not work if Aux STRUCT is dynamic sized
#               if field['type'] == 'STRUCT' or field['type'] == 'STRING':
#                   body += '%s%s[f] = (%s*) Mem_Alloc(%d, sizeof(%s));\n' % (field_parent, field['name'], alloc_type, field['abs_count'], alloc_type)
                pass

        elif field['type'] == 'STRING':
            # Pure null-terminated string.
            body += '%s%s = (CHAR*) Mem_Alloc(1+Buffer_Strlen(buffer, buffer_offset, buffer_max), 1));\n' % (field_parent, field['name'], field_loop_max)

            pass # TODO - For DYNAMIC SIZE Unpack, need to do the malloc for the value holder.

        # Handle standard type-based encoder/decoder calls.
        if size_suffix != '':
            body += Get_C_Field_Coder(dir_suffix, size_suffix, field_parent, field['name'], field_loop_index)

        elif field['type'] == 'CHAR':
            # User may select 'CHAR' to me 1 CHAR, or may combine it with the SIZE_DEFINED_BY cell.
            body  += Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, field['abs_count'])

        elif field['type'] == 'STRING':
            # Only allow STRING for null-terminated data with no fixed length.
            # Allowing STRING to be an alias for CHAR# creates many complicating if/then checks in this script.
#TODO How to handle the packing boundary?? Maybe STRING8/STRING16/etc??
            body  += Get_C_Field_Coder(dir_suffix, 'Sz', field_parent, field['name'], field_loop_index)

        elif field['type'] == 'STRUCT':
            if g_rec_fields_by_name.has_key(field['fmt']):
                child_rec_name, child_rec_fields = field['name'], g_rec_fields_by_name[field['fmt']]
                body += Create_C_Struct_Coder(dir_suffix, child_rec_name, child_rec_fields, field_parent + field['name'] + field_loop_index + '.')
            else:
                body += '// Cannot handle unknown STRUCT name <%s> fmt <%s>\n' % (field['name'], field['fmt'])

        else:   # Unknown TYPE
            body += '// Cannot handle field type <%s> name <%s>\n' % (field['type'], field['name'])

        if field_loop_max:
            body += '}}\n' # For loop and scoping block closure.

    # Wrap the created body with the function prototype text and other fixed wrapper code.
    global g_C_Proto, g_C_Coder
    if field_parent == 'data->':
        in1 = '    '
        in2 = in1 + in1
        g_C_Proto += 'UINT16 %s_%s(BYTE buffer[], const UINT16 buffer_max, %s* data);\n' % (dir_suffix, rec_name, rec_name)
        g_C_Coder += 'UINT16 %s_%s(BYTE buffer[], const UINT16 buffer_max, %s* data)\n' % (dir_suffix, rec_name, rec_name)
        g_C_Coder += '{\n'
        g_C_Coder += Indent(1, 'UINT16 byte_offset = 0;\n')
        g_C_Coder += Indent(1, 'if (data != 0) {\n')
        g_C_Coder += Indent(2, body)
        g_C_Coder += Indent(2, Create_C_Msg_Size_Coder(rec_name, rec_fields, msg_size_field_num, field_parent))
        g_C_Coder += Indent(2, Create_C_Msg_Crc_Coder(rec_name, rec_fields, msg_crc_field_num, field_parent))
        g_C_Coder += Indent(1, '}\n')
        g_C_Coder += Indent(1, 'return byte_offset;  // Actual length of processed buffer.\n')
        g_C_Coder += '}\n'
    else:
        return body
# ------------------------------------------------------------------------------
def Create_Py_Struct_Coder(dir_suffix, rec_name, rec_fields, field_parent=''):
    endian = '!'   # Network (Big) # see http://docs.python.org/2/library/struct.html
    packer = {
            'CHAR':    'c',
            'INT8':    'c',
            'UINT8':   'B',
            'INT16':   'h',
            'UINT16':  'H',
            'INT32':   'i',
            'UINT32':  'I',
            'INT64':   'q',
            'UINT64':  'Q',
            'FLOAT32': 'f',
            'FLOAT64': 'd',
            'STRING':  's',
            }
    into    = ''
    fmt     = ''
    msg_id  = -1
    for field in rec_fields[1:]:
        if field['msg_id']:
            msg_id = as_int(field['value'])
        field_loop_max = Get_Value_For_Defined_By(field['abs_count'], field['rel_count'], rec_fields, field_parent)
        if field_loop_max:
            Log_Info('Cannot handle indexes yet - rec %s field %s' % (rec_name, field['name']))
            return
        elif packer.has_key(field['type']):
            assign  = 'rec["%s%s"]' % (field_parent, field['name'])
            into   += (',' + assign) if into else assign
            fmt    += packer[field['type']]
        else:
            Log_Info('No packer for field; skipping record - rec %s field %s' % (rec_name, field['name']))
            return

    global g_Py_Pack, g_Py_Unpack
    if into and fmt:  # A few VARIANTS are empty and yield no value here.
        if dir_suffix == 'Pack':
            g_Py_Pack   += Indent(1, 'elif msg_type == %d:  #### %s\n' % (msg_id, rec_fields[0]['fmt']))
            g_Py_Pack   += Indent(2, 'struct.pack_into("%s", buffer, %s)\n\n' % (fmt,into))
        else:
            g_Py_Unpack += Indent(1, 'elif msg_type == %d:  #### %s\n' % (msg_id, rec_fields[0]['fmt']))
            g_Py_Unpack += Indent(2, '%s = struct.unpack_from("%s", buffer)\n\n' % (into, fmt))

# ------------------------------------------------------------------------------
# Test
# ------------------------------------------------------------------------------
def Create_Test_Out_Setter(field_parent, field_name, field_type, field_index=None):

    # Truncate to fit in INT8 since this counter is just confidence boosting anyway.
    global g_Test_Counter
    g_Test_Counter = (g_Test_Counter + 1) % 127

    if field_index == None:
        str_index = ''
    else:
        str_index = '[%s]' % str(field_index)   # Allowed to use digit or index variable.

    # TODO - use enum instead of int for enum fields...

    if string.find(field_type, 'INT') != -1:
        return '%s%s%s = %d;\n' % (field_parent, field_name, str_index, g_Test_Counter)
    elif string.find(field_type, 'FLOAT') != -1:
        return '%s%s%s = %d.%d;\n' % (field_parent, field_name, str_index, g_Test_Counter, g_Test_Counter)
    elif field_type == 'CHAR':
        if not chr(g_Test_Counter).isalnum(): g_Test_Counter = ord('A')
        return '%s%s%s = \'%c\';\n' % (field_parent, field_name, str_index, g_Test_Counter)
    elif field_type == 'STRING':
        return '%s%s%s = strdup("s%d");\n' % (field_parent, field_name, str_index, g_Test_Counter)
    return ''
# ------------------------------------------------------------------------------
def Create_Test_In_Getter(field_parent, field_name, field_type, field_index=None):
    comp = ''
    if field_index == None:
        str_index = ''
    else:
        str_index = '[%s]' % str(field_index)   # Allowed to use digit or index variable.

    # TODO - use enum instead of int for enum fields...

    if string.find(field_type, 'INT') != -1:
        comp = '%s%s%s == %d' % (field_parent, field_name, str_index, g_Test_Counter)
    elif string.find(field_type, 'FLOAT') != -1:
        comp = '%s%s%s == %d.%d' % (field_parent, field_name, str_index, g_Test_Counter, g_Test_Counter)
    elif field_type == 'CHAR':
        comp = '%s%s%s == \'%c\'' % (field_parent, field_name, str_index, g_Test_Counter)
    elif field_type == 'STRING':
        comp = '!strcmp(%s%s%s, "s%d")' % (field_parent, field_name, str_index, g_Test_Counter)

    if comp == '': return ''
    return 'if (%s) { printf("PASS: %s\\n"); } else { ok=0; printf("FAIL: %s\\n"); }\n' % (comp, field_name, field_name)
# ------------------------------------------------------------------------------
def Create_C_Test_Function(rec_name, rec_fields, out_field_parent='out_msg.', in_field_parent='in_msg.'):
    # Skip rec_field[0] since it is the structure name field.
    if rec_fields[0]['type'] == 'Aux':
        return  # No test driver needed for Aux

    global g_Test_Counter

    field_num = 0
    out_body = ''
    in_body = ''
    for field in rec_fields[1:]:
        field_type = field['type']
        field_fmt  = field['fmt']
        field_num += 1

        if field_type == 'VARIANT_ARRAY':
            return # TODO
        elif field_type == 'VARIANT_LIST':
            return # TODO
        elif field_type == 'VARIANT_ITEM':
            return # TODO
        elif field_type == 'STRUCT':
            return # TODO
        elif not field['value']:
            out_field_loop_max = Get_Value_For_Defined_By(field['abs_count'], field['rel_count'], rec_fields, out_field_parent)
            in_field_loop_max = Get_Value_For_Defined_By(field['abs_count'], field['rel_count'], rec_fields, in_field_parent)
            if field['abs_count'] > 0:
                for i in range(field['abs_count']):
                    out_body += Create_Test_Out_Setter(out_field_parent, field['name'], field_type, i)
                    in_body  += Create_Test_In_Getter(in_field_parent, field['name'], field_type, i)
            elif not out_field_loop_max:
                out_body += Create_Test_Out_Setter(out_field_parent, field['name'], field_type)
                in_body  += Create_Test_In_Getter(in_field_parent, field['name'], field_type)
            else:
                out_body += '{ UINT16 f; for (f = 0; f < %s; f++) {\n' % out_field_loop_max
                out_body += Create_Test_Out_Setter(out_field_parent, field['name'], field_type, 'f')
                out_body += '}}\n'
                in_body  += '{ UINT16 f; for (f = 0; f < %s; f++) {\n' % in_field_loop_max
                in_body  += Create_Test_In_Getter(in_field_parent, field['name'], field_type, 'f')
                in_body  += '}}\n'

    global g_Test_Funcs, g_Test_Calls
    if out_field_parent == 'out_msg.':
        in1 = '    '
        msg_name = rec_fields[0]['fmt']
        g_Test_Calls += Indent(1, 'if (test_%s() == 1) {pass++;} else {fail++;}\n' % msg_name)

        g_Test_Funcs += 'UINT16 test_%s()\n' % msg_name
        g_Test_Funcs += '{\n'
        g_Test_Funcs += Indent(1, 'UINT16 ok = 1;\n')
        g_Test_Funcs += Indent(1, 'UINT16 out_offset = 0;\n')
        g_Test_Funcs += Indent(1, 'UINT16 in_offset = 0;\n')
        g_Test_Funcs += Indent(1, '%s* net_msg = 0;\n' % msg_name)
        g_Test_Funcs += Indent(1, '%s  out_msg;\n' % msg_name)
        g_Test_Funcs += Indent(1, '%s   in_msg;\n' % msg_name)
        g_Test_Funcs += Indent(1, 'printf("----- %s\\n");\n' % rec_name)
        g_Test_Funcs += Indent(1, out_body)
        g_Test_Funcs += Indent(1, 'out_offset = Pack_%s(buffer, buffer_max, &out_msg);\n' % msg_name)
        g_Test_Funcs += Indent(1, 'net_msg    = (%s*) buffer;\n' % msg_name)
        g_Test_Funcs += Indent(1, 'in_offset  = Unpack_%s(buffer, buffer_max, &in_msg);\n' % msg_name)
        g_Test_Funcs += Indent(1, in_body)
        g_Test_Funcs += Indent(1, 'return ok;\n')
        g_Test_Funcs += '}\n'
    else:
        return out_body, in_body
# ------------------------------------------------------------------------------
# Load
# ------------------------------------------------------------------------------
def Load_Messages_Spreadsheet(filename):
    ''' Loads the indicated Messages spreadsheet file and enters data into internal globals. '''
    Log_Info('Loading Messages Spreadsheet: ' + filename)

    hdr_row_num = 1
    hdr_name_dict = {
        'INDEX'               : 'INDEX',
        'NAME'                : 'NAME',
        'TYPE'                : 'TYPE',
        'FORMAT'              : 'FORMAT',
        'COUNT_DEFINED_BY'    : 'COUNT_DEFINED_BY',
        'SPECIAL_CONTROL'     : 'SPECIAL_CONTROL',   # MSG_ID, MSG_SIZE[_16|_32], CRC_[16|32]
        'UNITS'               : 'UNITS',
        'FIXED_VALUE'         : 'FIXED_VALUE',
        'EXCLUDE_FROM_SIZE'   : 'EXCLUDE_FROM_SIZE',
        'MIN_RANGE'           : 'MIN_RANGE',
        'MAX_RANGE'           : 'MAX_RANGE',
        'DEFAULT_VALUE'       : 'DEFAULT_VALUE',
        'NOTES'               : 'NOTES',
    }
    table = PSW_Spreadsheet.Load_Spreadsheet_Cols(filename, hdr_row_num, hdr_name_dict)

    start_row = 0

    while start_row < len(table) - 1:
        start_row, end_row = Find_Next_Block(table, start_row)
        rec_name, rec_fields = Process_Block(start_row, table[start_row:end_row])
        g_rec_fields_by_name[rec_name] = rec_fields
        g_rec_fields_by_order.append(rec_name)
        start_row = end_row

    for rec_name in g_rec_fields_by_order:
        rec_fields = g_rec_fields_by_name[rec_name]

        Create_C_Struct(rec_name, rec_fields)
        Create_C_Struct_Coder('Pack',   rec_name, rec_fields)
        Create_C_Struct_Coder('Unpack', rec_name, rec_fields)
        Create_C_Test_Function(rec_name, rec_fields)

        Create_Py_Struct_Coder('Pack',   rec_name, rec_fields)
        Create_Py_Struct_Coder('Unpack', rec_name, rec_fields)
        #Create_Py_Test_Function(rec_name, rec_fields)

    print g_Py_Pack
    print g_Py_Unpack

# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# Enum Processing
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
def Create_Enums():
    global g_Enum_Dec
    in1 = '    '
    in2 = in1 + in1
    for enum_type in g_enum:
        if enum_type == '': continue   # Ignore generic default enum
        body = ''
        for enum in g_enum[enum_type]:
            body += in1 + '%-30s = %s,\n' % (enum[1], enum[0])
        body += in1 + enum_type + '_MAX\n'
        g_Enum_Dec += 'typedef enum {\n%s} %s;\n' % (body, enum_type)
# ------------------------------------------------------------------------------
# Load
# ------------------------------------------------------------------------------
def Load_Enums_Spreadsheet(filename):
    ''' Loads the indicated Enums spreadsheet file and enters data into internal globals. '''
    Log_Info('Loading Enums Spreadsheet: ' + filename)

    hdr_row_num = 1
    hdr_name_dict = {
        'ENUM_INT_OR_NAME' : 'ENUM_A',  # Column A
        'ENUM_TEXT'        : 'ENUM_B',  # Column B
    }
    table = PSW_Spreadsheet.Load_Spreadsheet_Cols(filename, hdr_row_num, hdr_name_dict)

    global g_enum
    g_enum[''] = []
    curr_enum  = ''
    row_num    = hdr_row_num

    for row in table:
        row_num += 1
        # Note that this enum file standard requires an int to be given for each enum.
        # So blank row can be detected by checking column A only. Blank rows are ignored.
        if row['ENUM_A'] == '':
            continue # Ignore blank rows.

        # Test column A for int (enum value) versus string (new enum type name).
        try:
            if (row['ENUM_A'][0].isalpha()) :
                curr_enum = Make_Valid_C_Enum(row['ENUM_A'], True)
                if g_enum.has_key(curr_enum):
                    Log_Error('%s(%d) - Enum <%s> already defined.' % (filename, row_num, curr_enum))
                    curr_enum = ''
                else:
                    g_enum[curr_enum] = []
                continue
        except Exception as ex:
            #Log_Debug(ex)
            value = as_int(row['ENUM_A'])

        if (row['ENUM_B'] == ''):
            Log_Error('%s(%d) - Enum value <%d> text is blank (invalid).' % (filename, row_num, value))
        else:
            # TODO Validate that the enum names are unique within this type (or possibly within whole file!)
            # TODO Note that C allows for more than 1 enum name to be assigned to a given int value.
            g_enum[curr_enum].append([int(value), Make_Valid_C_Enum(row['ENUM_B'])])
    Create_Enums()
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# MAIN
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
if __name__=='__main__':

    filename = 'KC-390_DBD_Enums.xlsx'
    Load_Enums_Spreadsheet(filename)

    filename = 'KC-390_DBD_Messages.xlsx'
    Load_Messages_Spreadsheet(filename)

    h_text  = '#ifndef INCLUDED_Gen_Structs_h\n'
    h_text += '#define INCLUDED_Gen_Structs_h\n'
    h_text += '#include "locker_core.h"\n'
    h_text += '/* -- Enums -- */\n'
    h_text += g_Enum_Dec
    h_text += '/* -- Aux Structs -- */\n'
    h_text += g_Aux_Dec
    h_text += '/* -- Msg Structs -- */\n'
    h_text += g_Msg_Dec
    h_text += '/* -- Prototypes -- */\n'
    h_text += g_C_Proto
    h_text += '#endif /* INCLUDED_Gen_Structs_h */\n'

    auto_gen_basename = 'locker_auto'

    auto_gen_h = auto_gen_basename + '.h'
    print 'Creating %s ...' % auto_gen_h
    h_file = open(auto_gen_h, 'w')
    h_file.write(h_text)
    h_file.close()

    auto_gen_c = auto_gen_basename + '.c'
    print 'Creating %s ...' % auto_gen_c
    c_file = open(auto_gen_c, 'w')
    c_file.write('#include "%s"\n' % auto_gen_h)
    c_file.write(g_C_Coder)
    c_file.close()

    t_text  = '#include <stdio.h>\n'
    t_text += '#include "locker_auto.h"\n\n'
    t_text += 'BYTE   buffer[1024];\n'
    t_text += 'UINT16 buffer_max = (UINT16) sizeof(buffer);\n\n'
    t_text += g_Test_Funcs
    t_text += 'int main(int argc, char** argv)\n'
    t_text += '{\n'
    t_text += '    UINT16 pass = 0;\n'
    t_text += '    UINT16 fail = 0;\n'
    t_text += g_Test_Calls
    t_text += '    printf("* Final pass=<%d> fail=<%d>\\n", pass, fail);\n'
    t_text += '    return 0;\n'
    t_text += '}\n'

    ## auto_gen_test_c = auto_gen_basename + '_test.c'
    ## print 'Creating %s ...' % auto_gen_test_c
    ## t_file = open(auto_gen_test_c, 'w')
    ## t_file.write(t_text)
    ## t_file.close()
