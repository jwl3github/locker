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
g_rec_fields_by_name = {}
g_rec_fields_by_order = []
g_Coder    = ''
g_Proto    = ''
g_Aux_Dec  = ''
g_Rec_Dec  = ''
g_Enum_Dec = ''
g_Enum_Cnt = 1000
g_Test_Funcs = ''
g_Test_Calls = ''

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
def Indent(indent, text):
    count = text.count('\n')
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

    # COUNT_DEFINED_BY must be '#<num>' or else INDEX [1 .. this_row_index-1] to field of [U]INT type
    # SPECIAL_CONTROL fields must be regular [U]INT#
    # Cannot have an FIXED_VALUE or DEFAULT_VALUE for field with COUNT_DEFINED_BY or type STRUCT
    # MIN_RANGE/MAX_RANGE only work for [U]INT and FLOAT

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
        }

        count = str(row['COUNT_DEFINED_BY'])
        if count != '':
            if count[0] == '#':
                field['abs_count'] = as_int(count[1:])
            else:
                field['rel_count'] = as_int(count)

        if row['INDEX'] == 0:
            Log_Debug('Processing new block Record Type <%s> Record Name <%s>' % (field['type'], field['fmt']))
            rec_name = field['fmt']
            if field['type'] != 'Message' and field['type'] != 'Aux':
                Log_Error('Unrecognized Record TYPE <%s> - start_row <%d>' % (field['type'], block_start_row))
                Log_Error('Expected "Message" or "Aux".  Cannot process this block.')
                return None, None

        rec_fields.append(field)
        field_index += 1

    for field in rec_fields:
        if field['special'] in ('MSG_SIZE_16', 'MSG_SIZE_32'):
            fixed, size = Compute_Fixed_Size(rec_name, rec_fields)
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
def Get_Value_For_Defined_By(abs_count, rel_count, rec_fields):
    ''' Used for COUNT_DEFINED_BY to resolve absolute (#) versus relative references to the usable value. '''
    if abs_count > 0:
       return abs_count
    elif rel_count in range(1, len(rec_fields)):
       return rec_fields[rel_count]['name']
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
        if field['type'].startswith('CHAR'):
            field_type = 'CHAR'
            fixed_size = field['type'].replace('CHAR', '')
            if fixed_size != '':
                ary = '[%s]' % fixed_size

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

    global g_Aux_Dec, g_Rec_Dec
    if rec_fields[0]['type'] == 'Aux':
        g_Aux_Dec += 'typedef struct {\n' + body + '} ' + rec_name + ';\n'
    else:
        g_Rec_Dec += 'typedef struct {\n' + body + '} ' + rec_name + ';\n'
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
        elif field['type'].startswith('CHAR'):
            bit_size += as_int(field['type'].replace('CHAR','')) * 8
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
def Create_C_Test_Function(rec_name, rec_fields):
    # Skip rec_field[0] since it is the structure name field.
    if rec_fields[0]['type'] == 'Aux':
        return  # No test driver needed for Aux

    fixed, size = Compute_Fixed_Size(rec_name, rec_fields)
    field_num = 0
    body = ''
    for field in rec_fields[1:]:
        field_type = field['type']
        field_fmt  = field['fmt']
        field_num += 1
        #ptr, ary = '', ''
        #if field['abs_count'] > 0:
        #    ary = '[%d]' % field['abs_count']
        #elif field['rel_count'] > 0:
        #    ptr = '*'
        #if field['type'].startswith('CHAR'):
        #    field_type = 'CHAR'
        #    fixed_size = field['type'].replace('CHAR', '')
        #    if fixed_size != '':
        #        ary = '[%s]' % fixed_size

        if field_type == 'VARIANT_ARRAY':
            return # TODO
        elif field_type == 'VARIANT_LIST':
            return # TODO
        elif field_type == 'VARIANT_ITEM':
            return # TODO
        elif field_type == 'STRUCT':
            return # TODO
        elif field['value']:   # Handle Sync and MSG_ID and any specified MSG_SIZE_x
            out_body += '    out_msg.%-20s = %s;\n' % (field['name'], field['value'])
        elif field['msg_size_8']:
            size_fixed, size_offset = Compute_Fixed_Size(rec_name, rec_fields[1:field_num])
            size_bytes = 1
        elif field['msg_size_16']:
            size_fixed, size_offset = Compute_Fixed_Size(rec_name, rec_fields[1:field_num])
            size_bytes = 2
        elif field['msg_size_32']:
            size_fixed, size_offset = Compute_Fixed_Size(rec_name, rec_fields[1:field_num])
            size_bytes = 4
        elif field['crc_16'] or field['crc_32']:
            if fixed:
                out_body += '    out_msg.%-20s = Calculate_CRC16((BYTE*)&out_msg, %d - sizeof(UINT16));\n' % (field['name'], size, div)
            else:
                out_body += '    out_msg.%-20s = 0; // TODO - Not a fixed size, need CRC compute method.\n' % (field['name'])

    global g_Test_Funcs, g_Test_Calls
    msg_name = rec_fields[0]['format']
    g_Test_Calls += '    if (test_%s() == 1) {pass++;} else {fail++;}\n' % msg_name

    g_Test_Funcs += 'UINT16 test_%s()\n' % msg_name
    g_Test_Funcs += '{\n'
    g_Test_Funcs += '    UINT16 ok = 1;\n'
    g_Test_Funcs += '    UINT16 out_offset = 0;\n'
    g_Test_Funcs += '    UINT16 in_offset = 0;\n'
    g_Test_Funcs += '    %s* net_msg = 0;\n' % msg_name
    g_Test_Funcs += '    %s  out_msg = 0;\n' % msg_name
    g_Test_Funcs += '    %s   in_msg = 0;\n' % msg_name
    g_Test_Funcs += out_body
    g_Test_Funcs += '    out_offset = Pack_%s(buffer, buffer_max, &out_msg);\n' % msg_name
    g_Test_Funcs += '    net_msg    = (%s*) buffer;\n' % msg_name
    g_Test_Funcs += '    in_offset  = Unpack_%s(buffer, buffer_max, &in_msg);\n' % msg_name
    g_Test_Funcs += in_body
    g_Test_Funcs += '    return ok;\n'
    g_Test_Funcs += '}\n'

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
        field_loop_max   = Get_Value_For_Defined_By(field['abs_count'], field['rel_count'], rec_fields)
        field_loop_index = '[f]' if field_loop_max else ''
        size_suffix      = Get_C_Struct_Coder_Size_Suffix(field['type'])

        if field['abs_count'] > 0:   # Absolute count; max is an integer.
            body += '{ int f; for(f = 0; f < %s; f++) {\n' % field_loop_max
        elif field_loop_max:         # Relative count; max is a field name.
            body += '{ int f; for(f = 0; f < %s%s; f++) {\n' % (field_parent, field_loop_max)

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
                msg_crc_field_num = field_num
                continue # Do not output a CRC coder... it will be done last in the subsequent code block.
        else:
            pass # TODO - For DYNAMIC SIZE Unpack, need to do the malloc for the value holder.

        # Handle standard type-based encoder/decoder calls.
        if size_suffix != '':
            body += Get_C_Field_Coder(dir_suffix, size_suffix, field_parent, field['name'], field_loop_index)

        elif field['type'] == 'CHAR':
            # User may select 'CHAR' to me 1 CHAR, or may combine it with the SIZE_DEFINED_BY cell.
            body  += Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, field['abs_count'])

        elif field['type'].startswith('CHAR'):
            fixed_size = as_int(field['type'].replace('CHAR', ''))
            body      += Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, fixed_size)

        elif field['type'] == 'STRING':
            # User could easily choose STRING instead of CHAR for dynamically-sized strings, so allow either one.
            if field['abs_count'] > 0:
                # Treat the same as CHARx if a fixed length is given.
                body  += Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, field['abs_count'])
            else:
                # This is for null-terminated strings only.
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
    global g_Proto, g_Coder
    if field_parent == 'data->':
        in1 = '    '
        in2 = in1 + in1
        g_Proto += 'UINT16 %s_%s(BYTE buffer[], const UINT16 buffer_max, %s* data);\n' % (dir_suffix, rec_name, rec_name)
        g_Coder += 'UINT16 %s_%s(BYTE buffer[], const UINT16 buffer_max, %s* data)\n' % (dir_suffix, rec_name, rec_name)
        g_Coder += '{\n'
        g_Coder += Indent(in1, 'UINT16 byte_offset = 0;\n')
        g_Coder += Indent(in1, 'if (data != 0) {\n')
        g_Coder += Indent(in2, body)
        g_Coder += Indent(in2, Create_C_Msg_Size_Coder(rec_name, rec_fields, msg_size_field_num, field_parent))
        g_Coder += Indent(in2, Create_C_Msg_Crc_Coder(rec_name, rec_fields, msg_crc_field_num, field_parent))
        g_Coder += Indent(in1, '}\n')
        g_Coder += Indent(in1, 'return byte_offset;  // Actual length of processed buffer.\n')
        g_Coder += '}\n'
    else:
        return body
# ------------------------------------------------------------------------------
def Load_Recs_Spreadsheet(filename):
    ''' Loads the indicated Recs spreadsheet file and enters data into internal globals. '''
    Log_Info('Loading Recs Spreadsheet: ' + filename)

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

# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# Enum Processing
# ------------------------------------------------------------------------------
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
# ------------------------------------------------------------------------------
# MAIN
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
if __name__=='__main__':

    filename = 'KC-390_DBD_Enums.xlsx'
    Load_Enums_Spreadsheet(filename)
    Create_Enums()

    filename = 'KC-390_DBD_Messages.xlsx'
    Load_Recs_Spreadsheet(filename)

    h_text  = '#ifndef INCLUDED_Gen_Structs_h\n'
    h_text += '#define INCLUDED_Gen_Structs_h\n'
    h_text += '#include "locker_core.h"\n'
    h_text += '/* -- Enums -- */\n'
    h_text += g_Enum_Dec
    h_text += '/* -- Aux Structs -- */\n'
    h_text += g_Aux_Dec
    h_text += '/* -- Rec Structs -- */\n'
    h_text += g_Rec_Dec
    h_text += '/* -- Prototypes -- */\n'
    h_text += g_Proto
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
    c_file.write(g_Coder)
    c_file.close()

    t_text  = '#include <stdio.h>\n'
    t_text += '#include "locker_core.h"\n'
    t_text += 'BYTE   buffer[1024];\n'
    t_text += 'UINT16 buffer_max = (UINT16) sizeof(buffer);\n'
    t_text += g_Test_Funcs
    t_text += 'int main(int argc, char** argv)\n'
    t_text += '{\n'
    t_text += '    UINT16 pass = 0;\n'
    t_text += '    UINT16 fail = 0;\n'
    t_text += g_Test_Calls
    t_text += '    printf("* Final pass=<%d> fail=<%d>\n", pass, fail);\n'
    t_text += '    return 0;\n'
    t_text += '}\n'

    auto_gen_test_c = auto_gen_basename + '_test.c'
    #print 'Creating %s ...' % auto_gen_test_c
    #t_file = open(auto_gen_test_c, 'w')
    #t_file.write(t_text)
    #t_file.close()
