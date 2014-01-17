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

# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# Utilities
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
def Make_Valid_C_Var(text, is_type = False):
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
    if is_type:
        var = 'T_' + var    # Choosing this convention for struct/enum type names.  NOT UNIVERSAL
    #Log_Debug('Make_Valid_C_Var  text <%s> -> var <%s>' % (text, var))
    return var
# ------------------------------------------------------------------------------
def Is_Valid_C_Var(text):
    return text == Make_Valid_C_Var(text)
# ------------------------------------------------------------------------------
def Make_Valid_C_Enum(text, is_type = False):
    var = Make_Valid_C_Var(text)
    if is_type:
        var = 'T_' + var    # Choosing this convention for enum values.  NOT UNIVERSAL
    else:
        var = 'E_' + var    # Choosing this convention for enum values.  NOT UNIVERSAL
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

    if not Is_Valid_C_Var(row['TYPE_CATEGORY']):
        Log_Warn('TYPE field has invalid chars <%s> - start_row <%d>' %
                (row['TYPE_CATEGORY'], block_start_row))
        row['TYPE_CATEGORY'] = Make_Valid_C_Var(row['TYPE_CATEGORY'])

    if row['FORMAT_TYPE'] != '':
        fmt = row['FORMAT_TYPE']
        if fmt.startswith('STRUCT-'): fmt = fmt.replace('STRUCT-', '')
        if fmt.startswith('ENUM-'):   fmt = fmt.replace('ENUM-', '')
        if not Is_Valid_C_Var(fmt):
            Log_Warn('FORMAT field has invalid chars <%s> - start_row <%d>' %
                    (row['FORMAT_TYPE'], block_start_row))
            row['TYPE_CATEGORY'] = Make_Valid_C_Var(row['TYPE_CATEGORY'])

    if row['COUNT_DEFINED_BY'] != '' and row['EXPECTED_VALUE'] != '':
        Log_Warn('COUNT_DEFINED_BY and EXPECTED_VALUE are mutually exclusive.  EXPECTED_VALUE <%s> ignored - start_row <%d>' %
                (row['EXPECTED_VALUE'], block_start_row))
        row['EXPECTED_VALUE'] = ''

    # COUNT_DEFINED_BY must be '#<num>' or else INDEX [1 .. this_row_index-1] to field of [U]INT type
    # DEFINES_RECORD_TYPE and DEFINES_RECORD_TYPE must be regular [U]INT#
    # Cannot have an EXPECTED_VALUE or DEFAULT_VALUE for field with COUNT_DEFINED_BY
    # MIN_RANGE/MAX_RANGE only work for [U]INT and FLOAT
    # Various must be 'TRUE' or (blank)

    return True  # No error or error can be ignored/worked around.
# ------------------------------------------------------------------------------
def Process_Block(block_start_row, block_cells):
    rec_name    = ''
    rec_fields  = []
    field_index = 0    # Counter to validate the expected sequential INDEX value.

    for row in block_cells:
        if not Validate_Row(block_start_row, field_index, row):
            continue

        field = { 'type':     Make_Valid_C_Var(row['TYPE_CATEGORY']),
                  'name':     Make_Valid_C_Var(row['FIELD_NAME']),
                  'fmt':      Make_Valid_C_Var(row['FORMAT_TYPE']),
                  'count':    str(row['COUNT_DEFINED_BY']),
                  'size':     str(row['SIZE_DEFINED_BY']),
                  'value':    str(row['EXPECTED_VALUE']),
                  'def_type': row['DEFINES_RECORD_TYPE'] == 'TRUE',
                  'def_size': row['DEFINES_RECORD_SIZE'] == 'TRUE', }

        if row['INDEX'] == 0:
            Log_Debug('Processing new block Record Type <%s> Record Name <%s>' % (field['type'], field['fmt']))
            if field['type'] == 'CommandRecord' or field['type'] == 'Aux':
                rec_name = field['fmt'].replace('STRUCT_', '')
            else:
                Log_Error('Unrecognized Record TYPE_CATEGORY <%s> - start_row <%d>' % (field['type'], block_start_row))
                Log_Error('Expected "CommandRecord" or "Aux".  Cannot process this block.')
                return

        elif rec_name == '':
                Log_Error('Missing INDEX [0] Record TYPE_CATEGORY or FORMAT_TYPE - start_row <%d>' % (block_start_row))
                Log_Error('Expected "CommandRecord" or "Aux" with a name in FORMAT_TYPE.  Cannot process this block.')
                return

        elif field['type'] == 'STRUCT':
            field['type'] = field['type'].replace('T_STRUCT_','T_')

        elif field['type'] == 'VARIANT':
            # TODO What else?
            field['type'] = field['type'].replace('T_STRUCT_','T_')

        rec_fields.append(field)
        field_index += 1

    return rec_name, rec_fields
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
def Output_C_Struct(rec_name, rec_fields):
    # Skip rec_field[0] since it is the structure name field.
    body = ''
    for field in rec_fields[1:]:
        fmt = field['fmt'].replace('STRUCT_', '')  # TODO kludge
        if field['type'] == 'STRUCT':
            body += '    %-20s %s;\n' % (fmt, field['name'])
        elif field['type'] == 'VARIANT':
            body += '    %-20s %s;\n' % (fmt, field['name'])
        else:
            body += '    %-20s %s;\n' % (field['type'], field['name'])
    print('struct ' + rec_name + ' {\n' + body + '};\n')
# ------------------------------------------------------------------------------
def Output_C_Struct_Unpack(rec_name, rec_fields, field_parent='data->'):
    pack_8  = ['UINT8',  'INT8']
    pack_16 = ['UINT16', 'INT16']
    pack_32 = ['UINT32', 'INT32', 'FLOAT32']
    pack_64 = ['UINT64', 'INT64', 'FLOAT64']

# TODO Check for COUNT_DEFINED_BY and loop with appended [#]

    in1 = '    '
    in2 = in1 + in1
    body = ''
    for field in rec_fields[1:]:
        if field['type'] in pack_8:
            body += in2 + 'in_offset = Get_Endian_08(in_buffer, in_max, in_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'] in pack_16:
            body += in2 + 'in_offset = Get_Endian_16(in_buffer, in_max, in_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'] in pack_32:
            body += in2 + 'in_offset = Get_Endian_32(in_buffer, in_max, in_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'] in pack_64:
            body += in2 + 'in_offset = Get_Endian_64(in_buffer, in_max, in_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'].startswith('CHAR'):
            try:
                length = int(field['type'].replace('CHAR', ''))  # TODO allow 'CHAR' or require 'CHAR1'?
                body += in2 + 'in_offset = Get_Endian_Ch(in_buffer, in_max, in_offset, %s%s, %d);\n' % (field_parent, field['name'], length)
            except:
                body += in2 + '// Cannot handle invalid CHAR# field type <%s>\n' % field['type']
        elif field['type'] == 'STRUCT':
            fmt = field['fmt'].replace('STRUCT_', '')  # TODO kludge
            if g_rec_fields_by_name.has_key(fmt):
                child_rec_name, child_rec_fields = field['name'], g_rec_fields_by_name[fmt]
                body += Output_C_Struct_Unpack(child_rec_name, child_rec_fields, field_parent + field['name'] + '->')
            else:
                body += in2 + '// Cannot handle unknown STRUCT name <%s> fmt <%s>\n' % (field['name'], fmt)
        else:
            body += in2 + '// Cannot yet handle field type <%s> name <%s>\n' % (field['type'], field['name'])

    if field_parent == 'data->':
        print('UINT16 Unpack_%s(BYTE in_buffer[], const UINT16 in_max, %s* data)' % (rec_name, rec_name))
        print('{')
        print(in1 + 'UINT16 in_offset = 0;')
        print(in1 + 'if (data != 0) {')
        print(body + in1 + '}')
        print(in1 + 'return in_offset;  // Actual length of processed buffer.')
        print('}')
    else:
        return body
# ------------------------------------------------------------------------------
def Output_C_Struct_Pack(rec_name, rec_fields, field_parent='data->'):
    pack_8  = ['UINT8',  'INT8']
    pack_16 = ['UINT16', 'INT16']
    pack_32 = ['UINT32', 'INT32', 'FLOAT32']
    pack_64 = ['UINT64', 'INT64', 'FLOAT64']

    in1 = '    '
    in2 = in1 + in1
    body = ''
    for field in rec_fields[1:]:

# TODO Check for COUNT_DEFINED_BY and loop with appended [#]

        if field['type'] in pack_8:
            body += in2 + 'out_offset = Put_Endian_08(out_buffer, out_max, out_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'] in pack_16:
            body += in2 + 'out_offset = Put_Endian_16(out_buffer, out_max, out_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'] in pack_32:
            body += in2 + 'out_offset = Put_Endian_32(out_buffer, out_max, out_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'] in pack_64:
            body += in2 + 'out_offset = Put_Endian_64(out_buffer, out_max, out_offset, %s%s);\n' % (field_parent, field['name'])
        elif field['type'].startswith('CHAR'):
            try:
                length = int(field['type'].replace('CHAR', ''))  # TODO allow 'CHAR' or require 'CHAR1'?
                body += in2 + 'out_offset = Put_Endian_Ch(out_buffer, out_max, out_offset, %s%s, %d);\n' % (field_parent, field['name'], length)
            except:
                body += in2 + '// Cannot handle invalid CHAR# field type <%s>\n' % field['type']
        elif field['type'] == 'STRUCT':
            fmt = field['fmt'].replace('STRUCT_', '')  # TODO kludge
            if g_rec_fields_by_name.has_key(fmt):
                child_rec_name, child_rec_fields = field['name'], g_rec_fields_by_name[fmt]
                body += Output_C_Struct_Pack(child_rec_name, child_rec_fields, field_parent + field['name'] + '->')
            else:
                body += in2 + '// Cannot handle unknown STRUCT name <%s> fmt <%s>\n' % (field['name'], fmt)
        else:
            body += in2 + '// Cannot yet handle field type <%s> name <%s>\n' % (field['type'], field['name'])

    if field_parent == 'data->':
        print('UINT16 Pack_%s(BYTE out_buffer[], const UINT16 out_max, %s* data)' % (rec_name, rec_name))
        print('{')
        print(in1 + 'UINT16 out_offset = 0;')
        print(in1 + 'if (data != 0) {')
        print(body + in1 + '}')
        print(in1 + 'return out_offset;  // Actual length of packed buffer.')
        print('}')
    else:
        return body
# ------------------------------------------------------------------------------
def Load_Recs_Spreadsheet(filename):
    ''' Loads the indicated Recs spreadsheet file and enters data into internal globals. '''
    Log_Info('Loading Recs Spreadsheet: ' + filename)

    hdr_row_num = 1
    hdr_name_dict = {
        'INDEX'               : 'INDEX',
        'FIELD_NAME'          : 'FIELD_NAME',
        'TYPE_CATEGORY'       : 'TYPE_CATEGORY',
        'UNITS'               : 'UNITS',
        'FORMAT_TYPE'         : 'FORMAT_TYPE',
        'COUNT_DEFINED_BY'    : 'COUNT_DEFINED_BY',
        'SIZE_DEFINED_BY'     : 'SIZE_DEFINED_BY',
        'EXPECTED_VALUE'      : 'EXPECTED_VALUE',
        'DEFINES_RECORD_TYPE' : 'DEFINES_RECORD_TYPE',
        'DEFINES_RECORD_SIZE' : 'DEFINES_RECORD_SIZE',
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
        start_row = end_row

    print g_rec_fields_by_name.keys()
    for rec_name in g_rec_fields_by_name.keys():
        rec_fields = g_rec_fields_by_name[rec_name]
# TODO skip Aux
        Output_C_Struct(rec_name, rec_fields)
        Output_C_Struct_Pack(rec_name, rec_fields)
        Output_C_Struct_Unpack(rec_name, rec_fields)

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
def Output_Enums():
    in1 = '    '
    in2 = in1 + in1
    for enum_type in g_enum:
        if enum_type == '': continue   # Ignore generic default enum
        body = ''
        for enum in g_enum[enum_type]:
            body += in1 + '%-30s = %s,\n' % (enum[1], enum[0])
        print('typedef enum %s {\n%s};\n' % (enum_type, body))
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# MAIN
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
if __name__=='__main__':

    filename = 'KC-390_DBD_Enums.xlsx'
    Load_Enums_Spreadsheet(filename)
    #Output_Enums()

    filename = 'KC-390_DBD_Recs.xlsx'
    Load_Recs_Spreadsheet(filename)
