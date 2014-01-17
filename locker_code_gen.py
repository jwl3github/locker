import string

# ------------------------------------------------------------------------------
K_INDEX               = 0
K_FIELD_NAME          = 1
K_TYPE_CATEGORY       = 2
K_UNITS               = 3
K_FORMAT_TYPE         = 4
K_COUNT_DEFINED_BY    = 5
K_SIZE_DEFINED_BY     = 6
K_EXPECTED_VALUE      = 7
K_DEFINES_RECORD_TYPE = 8
K_DEFINES_RECORD_SIZE = 9
K_EXCLUDE_FROM_SIZE   = 10
K_MIN_RANGE           = 11
K_MAX_RANGE           = 12
K_DEFAULT_VALUE       = 13
K_NOTES               = 14
# ------------------------------------------------------------------------------
def Make_Valid_C_Var(text):
    # Characters to ignore/remove.
    # This is based on the current practices of the ICD in use and is not universal.
    # All other non-alphanum are swapped with underscore.
    to_ignore = ['#', '(', ')', "'", '"']
    var = ''
    for c in text:
        if c not in to_ignore:
            var += c if c.isalnum() else '_'
    # The leading character must be a non-digit, so prefix with '_' if needed.
    if var == '':
        var = '_var'
    elif not var[0].isalpha():
        var = '_' + var
    #print('Make_Valid_C_Var  text <%s> -> var <%s>' % (text, var))
    return var
# ------------------------------------------------------------------------------
def Is_Valid_C_Var(text):
    return text == Make_Valid_C_Var(text)
# ------------------------------------------------------------------------------
def Validate_Row(block_start_row, field_index, row):
    try:
        row[K_INDEX] = int(row[K_INDEX])
    except:
        print('ERROR: INDEX must be a number not <%s> - start_row <%d>' %
                (row[K_INDEX], block_start_row))
        return False

    if row[K_INDEX] < 0:
        print('ERROR: INDEX cannot be negative <%d> - start_row <%d>' %
                (row[K_INDEX], block_start_row))
        return False

    if row[K_INDEX] != field_index:
        print('WARN: Index is not sequential - found <%d> expected <%d> - start_row <%d>' %
                (row[K_INDEX], field_index, block_start_row))

    if not Is_Valid_C_Var(row[K_TYPE_CATEGORY]):
        print('WARN: TYPE field has invalid chars <%s> - start_row <%d>' %
                (row[K_TYPE_CATEGORY], block_start_row))
        row[K_TYPE_CATEGORY] = Make_Valid_C_Var(row[K_TYPE_CATEGORY])

    if row[K_FORMAT_TYPE] != '':
        fmt = row[K_FORMAT_TYPE]
        if fmt.startswith('STRUCT-'): fmt = fmt.replace('STRUCT-', '')
        if fmt.startswith('ENUM-'):   fmt = fmt.replace('ENUM-', '')
        if not Is_Valid_C_Var(fmt):
            print('WARN: FORMAT field has invalid chars <%s> - start_row <%d>' %
                    (row[K_FORMAT_TYPE], block_start_row))
            row[K_TYPE_CATEGORY] = Make_Valid_C_Var(row[K_TYPE_CATEGORY])

    if row[K_COUNT_DEFINED_BY] != '' and row[K_EXPECTED_VALUE] != '':
        print('WARN: COUNT_DEFINED_BY and EXPECTED_VALUE are mutually exclusive.  EXPECTED_VALUE <%s> ignored - start_row <%d>' %
                (row[K_EXPECTED_VALUE], block_start_row))
        row[K_EXPECTED_VALUE] = ''

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

        field = { 'type':     Make_Valid_C_Var(row[K_TYPE_CATEGORY]),
                  'name':     Make_Valid_C_Var(row[K_FIELD_NAME]),
                  'fmt':      Make_Valid_C_Var(row[K_FORMAT_TYPE]),
                  'count':    row[K_COUNT_DEFINED_BY],
                  'size':     row[K_SIZE_DEFINED_BY],
                  'value':    row[K_EXPECTED_VALUE],
                  'def_type': row[K_DEFINES_RECORD_TYPE] == 'TRUE',
                  'def_size': row[K_DEFINES_RECORD_SIZE] == 'TRUE', }

        if row[K_INDEX] == 0:
            print 'Processing new block Record Type <%s> Record Name <%s>' % (field['type'], field['fmt'])
            if field['type'] == 'CommandRecord' or field['type'] == 'Aux':
                rec_name = field['fmt'].replace('STRUCT_', '')
            else:
                print('Unrecognized Record TYPE_CATEGORY <%s> - start_row <%d>' % (row[K_TYPE_CATEGORY], block_start_row))
                print('Expected "CommandRecord" or "Aux".  Cannot process this block.')
                return

        elif rec_name == '':
                print('Missing INDEX [0] Record TYPE_CATEGORY or FORMAT_TYPE - start_row <%d>' % (block_start_row))
                print('Expected "CommandRecord" or "Aux" with a name in FORMAT_TYPE.  Cannot process this block.')
                return

        elif field['type'] == 'STRUCT':
            field['type'] = field['type'].replace('STRUCT_','')

        elif field['type'] == 'VARIANT':
            # TODO What else?
            field['type'] = field['type'].replace('STRUCT_','')

        rec_fields.append(field)
        field_index += 1

    return rec_name, rec_fields
# ------------------------------------------------------------------------------
def Find_Next_Block(data_cells, start_row):
    # Find next non-blank row or end of table.
    while (start_row < len(data_cells)) and data_cells[0] == '':
        start_row += 1
    # Process until blank row or end of table.
    end_row = start_row
    while (end_row < len(data_cells)) and data_cells[0] != '':
        end_row += 1
    return (start_row, end_row)
# ------------------------------------------------------------------------------
def Output_C_Struct(rec_name, rec_fields):
    # Skip rec_field[0] since it is the structure name field.
    body = ''
    for field in rec_fields[1:]:
        body += '    %-20s %s;\n' % (field['type'], field['name'])
    print('struct ' + rec_name + ' {\n' + body + '};\n')
# ------------------------------------------------------------------------------
def Output_C_Struct_Unpack(rec_name, rec_fields):
    pack_8  = ['UINT8',  'INT8']
    pack_16 = ['UINT16', 'INT16']
    pack_32 = ['UINT32', 'INT32', 'FLOAT32']
    pack_64 = ['UINT64', 'INT64', 'FLOAT64']

    in1 = '    '
    in2 = in1 + in1
    body = ''
    for field in rec_fields[1:]:
        if field['type'] in pack_8:
            body += in2 + 'in_offset = Get_Endian_08(in_buffer, in_max, out_offset, data->%s);\n' % field['name']
        elif field['type'] in pack_16:
            body += in2 + 'in_offset = Get_Endian_16(in_buffer, in_max, out_offset, data->%s);\n' % field['name']
        elif field['type'] in pack_32:
            body += in2 + 'in_offset = Get_Endian_32(in_buffer, in_max, out_offset, data->%s);\n' % field['name']
        elif field['type'] in pack_64:
            body += in2 + 'in_offset = Get_Endian_64(in_buffer, in_max, out_offset, data->%s);\n' % field['name']
        elif field['type'].startswith('CHAR'):
            try:
                length = int(field['type'].replace('CHAR', ''))  # TODO allow 'CHAR' or require 'CHAR1'?
                body += in2 + 'in_offset = Get_Endian_Char(out_buffer, out_offset, %d, %s);\n' % (length, field['name'])
            except:
                body += in2 + '// Invalid CHAR# field type <%s>' % field['type']
        else:
            body += in2 + '// Cannot yet handle field type <%s>' % field['type']

    print('UINT16 Unpack_%s(BYTE in_buffer[], const UINT16 in_max, %s* data)' % (rec_name, rec_name))
    print('{')
    print(in1 + 'UINT16 in_offset = 0;')
    print(in1 + 'if (data != 0) {')
    print(body + in1 + '}')
    print(in1 + 'return in_offset;  // Actual length of processed buffer.')
    print('}')

# ------------------------------------------------------------------------------
def Output_C_Struct_Pack(rec_name, rec_fields):
    pack_8  = ['UINT8',  'INT8']
    pack_16 = ['UINT16', 'INT16']
    pack_32 = ['UINT32', 'INT32', 'FLOAT32']
    pack_64 = ['UINT64', 'INT64', 'FLOAT64']

    in1 = '    '
    in2 = in1 + in1
    body = ''
    for field in rec_fields[1:]:
        if field['type'] in pack_8:
            body += in2 + 'out_offset = Put_Endian_08(out_buffer, out_max, out_offset, data->%s);\n' % field['name']
        elif field['type'] in pack_16:
            body += in2 + 'out_offset = Put_Endian_16(out_buffer, out_max, out_offset, data->%s);\n' % field['name']
        elif field['type'] in pack_32:
            body += in2 + 'out_offset = Put_Endian_32(out_buffer, out_max, out_offset, data->%s);\n' % field['name']
        elif field['type'] in pack_64:
            body += in2 + 'out_offset = Put_Endian_64(out_buffer, out_max, out_offset, data->%s);\n' % field['name']
        elif field['type'].startswith('CHAR'):
            try:
                length = int(field['type'].replace('CHAR', ''))  # TODO allow 'CHAR' or require 'CHAR1'?
                body += in2 + 'out_offset = Put_Endian_Char(out_buffer, out_offset, %d, %s);\n' % (length, field['name'])
            except:
                body += in2 + '// Invalid CHAR# field type <%s>' % field['type']
        else:
            body += in2 + '// Cannot yet handle field type <%s>' % field['type']

    print('UINT16 Pack_%s(BYTE out_buffer[], const UINT16 out_max, %s* data)' % (rec_name, rec_name))
    print('{')
    print(in1 + 'UINT16 out_offset = 0;')
    print(in1 + 'if (data != 0) {')
    print(body + in1 + '}')
    print(in1 + 'return out_offset;  // Actual length of packed buffer.')
    print('}')

# ------------------------------------------------------------------------------
if __name__=='__main__':
    data_cells = [
        [ '0', 'RECORD_CATEGORY', 'CommandRecord',  '', 'Ping_Message',    '', '',        '',     '',      '',      '', ],
        [ '1', 'Sync',            'UINT16',         '', '',                '', '0x55AA',  '',     '',      'TRUE',  '', ],
        [ '2', 'Message_ID',      'UINT16',         '', 'ENUM-Message_ID', '', '2',       'TRUE', '',      'TRUE',  '', ],
        [ '3', 'Source_ID',       'UINT16',         '', 'ENUM-LRU_ID',     '', '',        '',     '',      'TRUE',  '', ],
        [ '4', 'Dest_ID',         'UINT16',         '', 'ENUM-LRU_ID',     '', '',        '',     '',      'TRUE',  '', ],
        [ '5', 'Word_Count',      'UINT16',         '', '',                '', '',        '',     'TRUE',  'TRUE',  '', ],
        [ '6', 'Packet_ID_Seq',   'UINT16',         '', '',                '', '',        '',     '',      '',      '', ],
        [ '7', 'Header_CR',       'UINT16',         '', '',                '', '',        '',     '',      '',      '', ],
    ]
    rec_fields_by_name = {}
    start_row = 0
    while start_row < len(data_cells) - 1:
        start_row, end_row = Find_Next_Block(data_cells, start_row)
        rec_name, rec_fields = Process_Block(start_row, data_cells[start_row:end_row])
        rec_fields_by_name[rec_name] = rec_fields
        Output_C_Struct(rec_name, rec_fields)
        Output_C_Struct_Pack(rec_name, rec_fields)
        Output_C_Struct_Unpack(rec_name, rec_fields)
        start_row = end_row

