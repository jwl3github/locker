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

        field = { 'type':        Make_Valid_C_Var(row['TYPE']),
                  'name':        Make_Valid_C_Var(row['NAME']),
                  'fmt':         Make_Valid_C_Var(row['FORMAT']),
                  'rel_count':   0,
                  'abs_count':   0,
                  'value':       str(row['FIXED_VALUE']),
                  'msg_id':      row['SPECIAL_CONTROL'] == 'MSG_ID',
                  'msg_size_16': row['SPECIAL_CONTROL'] == 'MSG_SIZE_16',
                  'msg_size_32': row['SPECIAL_CONTROL'] == 'MSG_SIZE_32',
                  'crc_16':      row['SPECIAL_CONTROL'] == 'CRC_16',
                  'crc_32':      row['SPECIAL_CONTROL'] == 'CRC_32',
        }

        count = str(row['COUNT_DEFINED_BY'])
        if count != '':
            if count[0] == '#':
                field['abs_count'] = PSW_Spreadsheet.as_int(count[1:])
            else:
                field['rel_count'] = PSW_Spreadsheet.as_int(count)

        if row['INDEX'] == 0:
            Log_Debug('Processing new block Record Type <%s> Record Name <%s>' % (field['type'], field['fmt']))
            rec_name = field['fmt']
            if field['type'] != 'Message' and field['type'] != 'Aux':
                Log_Error('Unrecognized Record TYPE <%s> - start_row <%d>' % (field['type'], block_start_row))
                Log_Error('Expected "Message" or "Aux".  Cannot process this block.')
                return None, None

        rec_fields.append(field)
        field_index += 1

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
def Get_C_Field_Coder(dir_suffix, size_suffix, field_parent, field_name, field_loop_index, fixed_size=0):
    fixed_size_str = (', %d' % fixed_size) if fixed_size > 0 else ''
    return 'byte_offset = %s_Endian_%s(buffer, buffer_max, byte_offset, (BYTE*)&(%s%s%s)%s);\n' % \
            (dir_suffix, size_suffix, field_parent, field_name, field_loop_index, fixed_size_str)
# ------------------------------------------------------------------------------
def Create_C_Struct_Coder(dir_suffix, rec_name, rec_fields, field_parent='data->'):
    pack_8  = ['UINT8',  'INT8']
    pack_16 = ['UINT16', 'INT16']
    pack_32 = ['UINT32', 'INT32', 'FLOAT32']
    pack_64 = ['UINT64', 'INT64', 'FLOAT64']

    # Note: All fields are assumed to be validated by this point, so
    #       many possible integrity checks are omitted.

    in1 = '    '
    in2 = in1 + in1
    body = ''
    for field in rec_fields[1:]:

        field_loop_max   = Get_Value_For_Defined_By(field['abs_count'], field['rel_count'], rec_fields)
        field_loop_index = '[f]' if field_loop_max else ''

        if field['abs_count'] > 0:   # Absolute count; max is an integer.
            body += in2 + '{ int f; for(f = 0; f < %s; f++) {\n' % field_loop_max
        elif field_loop_max:         # Relative count; max is a field name.
            body += in2 + '{ int f; for(f = 0; f < %s%s; f++) {\n' % (field_parent, field_loop_max)

# TODO - For DYNAMIC SIZE Unpack, need to do the malloc for the value holder.
# TODO - For VARIANT_XXX, really need to have size info but the current ICD omits this.

        if   field['type'] in pack_8:   body += in2 + Get_C_Field_Coder(dir_suffix, '08', field_parent, field['name'], field_loop_index)
        elif field['type'] in pack_16:  body += in2 + Get_C_Field_Coder(dir_suffix, '16', field_parent, field['name'], field_loop_index)
        elif field['type'] in pack_32:  body += in2 + Get_C_Field_Coder(dir_suffix, '32', field_parent, field['name'], field_loop_index)
        elif field['type'] in pack_64:  body += in2 + Get_C_Field_Coder(dir_suffix, '64', field_parent, field['name'], field_loop_index)
        elif field['type'] == 'CHAR':
            # User may select 'CHAR' to me 1 CHAR, or may combine it with the SIZE_DEFINED_BY cell.
            body  += in2 + Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, field['abs_count'])
        elif field['type'].startswith('CHAR'):
            fixed_size = PSW_Spreadsheet.as_int(field['type'].replace('CHAR', ''))
            body      += in2 + Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, fixed_size)
        elif field['type'] == 'STRING':
            # User could easily choose STRING instead of CHAR for dynamically-sized strings, so allow either one.
            if field['abs_count'] > 0:
                body  += in2 + Get_C_Field_Coder(dir_suffix, 'Ch', field_parent, field['name'], field_loop_index, field['abs_count'])
            else:
                # This is for null-terminated strings only.
#TODO How to handle the packing boundary?? Maybe STRING8/STRING16/etc??
                body  += in2 + Get_C_Field_Coder(dir_suffix, 'Sz', field_parent, field['name'], field_loop_index)
        elif field['type'] == 'STRUCT':
            if g_rec_fields_by_name.has_key(field['fmt']):
                child_rec_name, child_rec_fields = field['name'], g_rec_fields_by_name[field['fmt']]
                body += Create_C_Struct_Coder(dir_suffix, child_rec_name, child_rec_fields, field_parent + field['name'] + field_loop_index + '.')
            else:
                body += in2 + '// Cannot handle unknown STRUCT name <%s> fmt <%s>\n' % (field['name'], field['fmt'])
        else:
            body += in2 + '// Cannot handle field type <%s> name <%s>\n' % (field['type'], field['name'])

        if field_loop_max:
            body += in2 + '}}\n' # For loop and scoping block closure.

    global g_Proto, g_Coder
    if field_parent == 'data->':
        g_Proto += 'UINT16 %s_%s(BYTE buffer[], const UINT16 buffer_max, %s* data);\n' % (dir_suffix, rec_name, rec_name)
        g_Coder += 'UINT16 %s_%s(BYTE buffer[], const UINT16 buffer_max, %s* data)\n' % (dir_suffix, rec_name, rec_name)
        g_Coder += '{\n'
        g_Coder += in1 + 'UINT16 byte_offset = 0;\n'
        g_Coder += in1 + 'if (data != 0) {\n'
        g_Coder += body + in1 + '}\n'
        g_Coder += in1 + 'return byte_offset;  // Actual length of processed buffer.\n'
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
            value = PSW_Spreadsheet.as_int(row['ENUM_A'])

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
    t_text  = '#include "locker_core.h"\n'
    t_text += 'int main(int argc, char** argv)\n'
    t_text += '{\n'
    t_text += '    return 0;\n'
    t_text += '}\n'

    auto_gen_test_c = auto_gen_basename + '_test.c'
    #print 'Creating %s ...' % auto_gen_test_c
    #t_file = open(auto_gen_test_c, 'w')
    #t_file.write(t_text)
    #t_file.close()
