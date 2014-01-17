
K_INDEX               = 0
K_FIELD_NAME          = 1
K_TYPE                = 2
K_FORMAT              = 3
K_COUNT_DEFINED_BY    = 4

# ------------------------------------------------------------------------------
def Find_Next_Block(data_cells, start_row):
    # Find next non-blank row or end of table.
    while (curr_row < len(data_cells)) and row[0] == '':
        start_row += 1
    # Process until blank row or end of table.
    curr_row = start_row
    while (curr_row < len(data_cells)) and row[0] != '':
        curr_row += 1
    return (start_row, curr_row)
# ------------------------------------------------------------------------------
def Process_Block(block_start_row, block_cells):
    struct_name = ''
    struct_def = []
    index = 0
    for row in block_cells:
        # Validations
        if index != row[K_INDEX]:
            print('WARN: Index is not sequential - found <%d> expected <%d> - start_row <%d>' % (row[0], index, block_start_row))
            index = row[K_INDEX]
        if Contains_Invalid_Char(row[K_TYPE]):
            print('WARN: TYPE field has invalid chars <%s> - start_row <%d>' % (row[K_TYPE], block_start_row))
        if Contains_Invalid_Char(row[K_FORMAT]):
            print('WARN: FORMAT field has invalid chars <%s> - start_row <%d>' % (row[K_FORMAT], block_start_row))
        # Processing
        if index == 0:
            struct_name = row[K_FORMAT]
        elif row[K_TYPE] == 'STRUCT':
            struct_def.append(row[K_TYPE] + ' ' + row[K_FIELD_NAME])
        elif row[K_TYPE] == 'VARIANT':
            struct_def.append(row[K_TYPE] + ' ' + row[K_FIELD_NAME])
        elif row[K_FORMAT].startswith('ENUM-'):
            struct_def.append(row[K_TYPE] + ' ' + row[K_FIELD_NAME])
