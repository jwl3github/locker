"""
PSW_Spreadsheet.py

Performance Software Spreadsheet Access Module
Oct 15, 2013
John Lyons

Basic functions for loading and processing input spreadsheet files.
Files can be in .xls, .xlsx, or .csv (comma-separated) format.

Restrictions:
a) The CSV processing is built-in and has limited handling for multi-line
quoted cell values.

b) Does not provide any output services, outside of a formatted table
dumping routine for debugging purposes.

Requires the 'xlrd' module.  This module is not available as part of the
standard ActiveState Python suite, and it must be downloaded and installed
separately.


"""
import sys
import xlrd
import re
import PSW_Basic_Log

# ------------------------------------------------------------------------------
Log_Debug = PSW_Basic_Log.Log_Debug
Log_Info  = PSW_Basic_Log.Log_Info
Log_Warn  = PSW_Basic_Log.Log_Warn
Log_Error = PSW_Basic_Log.Log_Error
Log_Fatal = PSW_Basic_Log.Log_Fatal
Quit      = PSW_Basic_Log.Quit

# ------------------------------------------------------------------------------
# General Utility Methods ------------------------------------------------------
# ------------------------------------------------------------------------------
def Find_Header_Col(row, name, warn=True):
    for i in range (0,len(row)):
        #Log_Debug("<%s> =? <%s>" % (row[i], name))
        if row[i] == name:
            return i
    if warn:
        Log_Warn("Find_Header_Col: Searched %d columns, did not find: <%s>" % (len(row),name))
    return -1

# ------------------------------------------------------------------------------
# Coerce an unknown format variable to an int.
# ------------------------------------------------------------------------------
def as_int(x):
    ''' Produces a resonable integer value (default 0) when given a value of unknown format. '''
    y = 0
    try:
        y = int(x)
    except:
        y = int(float(x))
    finally:
        return y

# ------------------------------------------------------------------------------
# Coerce an unknown format variable to a float.
# ------------------------------------------------------------------------------
def as_float(x):
    ''' Produces a resonable float value (default 0.0) when given a value of unknown format. '''
    y = 0.0
    try:
        y = float(x)
    except:
        y = 0.0
    finally:
        return y

# ------------------------------------------------------------------------------
# Coerce an unknown format variable to a truncated string.
# ------------------------------------------------------------------------------
def Truncate(x, length):
    ''' Produces a string version of the provided value, truncated to the given length. '''
    y = x
    try:
        y = x[:length]
    except:
        y = "%d" % int(y)
    finally:
        return y

# ------------------------------------------------------------------------------
# Finds the subset of starting characters that is common to all of the
# provided string list.
# Returns '' if there are no starting characters in common.
# ------------------------------------------------------------------------------
def Get_Common_Prefix(str_list):
    shortest = min(str_list, key=len)
    max_len  = len(shortest)

    for i in range (0,max_len):
        c = str_list[0][i:i+1]
        for s in str_list:
            if (c != s[i:i+1]):
                s = str_list[0][0:i]
                # Log_Debug("Get_Common_Prefix: <%s>" % s)
                return s

    # Log_Debug("Get_Common_Prefix: <%s>" % shortest)
    return shortest

# ------------------------------------------------------------------------------
# Given a row (list of column values), returns the column value at the
# indicated position, truncated to the given number of maximum characters.
#
# The column index is 0-based.
#
# Returns '' if the column index is out-of-range.
# ------------------------------------------------------------------------------
def Get_Row_Field(row, col_index, max_len=999):
    if (col_index >= 0 and col_index < len(row)):
        return row[col_index][0:max_len]
    else:
        return ''

# ------------------------------------------------------------------------------
# CSV Methods ------------------------------------------------------------------
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Splits a row of text from an input CSV (comma-separated values) file
# with awareness of the comma character and of single-line string quoting (").
#
# RESTRICTION: Does not currently handle multi-line string quotes correctly.
# ------------------------------------------------------------------------------
def Parse_CSV_Row(line):
    row = []

    while (line.__len__() > 0):
        matches = re.match(r'"(.*?)",?(.*)', line)
        if matches:
            row.append(matches.group(1))
            line = matches.group(2)
            continue

        matches = re.match(r'"', line)
        if matches:
            Log_Error("Load_CSV_File: Cannot handle multi-line strings yet.")
            row.append(line)
            line = ''
            continue

        matches = re.match(r'([^,]*),?(.*)', line)
        if matches:
            row.append(matches.group(1))
            line = matches.group(2)
            continue

        row.append(line)
        line = ''

    return row

# ------------------------------------------------------------------------------
# Given a full row (as a list of column values), does a positional filter
# so that the returned row list only contains the indicated columns.
#
# The column index list is 0-based.
#
# For any invalid column index, the filtered row is filled with a ''.
# ------------------------------------------------------------------------------
def Filter_Row_By_Index(row, col_index_list):
    filtered_row = []
    for col in col_index_list:
        filtered_row.append(Get_Row_Field(row, col))
    return filtered_row

# ------------------------------------------------------------------------------
# Given a full row (as a list of column values), does a positional filter
# so that the returned row dictionary only contains the indicated columns.
#
# The column index dictionary maps:
#
#     col_index_dict = { 'name_A':index_A, 'name_B':index_B, [...] }
#
#     where each column index list is 0-based.
#
# The returned dictionary maps:
#
#     filtered_row = { 'name_A':value_A, 'name_B':value_B, [...] }
#
# For any invalid column index, the value_X is set to ''.
# ------------------------------------------------------------------------------
def Filter_Row_By_Named_Index(row, col_index_dict):
    filtered_row = {}
    for key in col_index_dict.keys():
        col = int(col_index_dict[key])
        filtered_row[key] = Get_Row_Field(row, col)
        #Log_Debug("Filter_Row_By_Named_Index: find <%s> index <%d> => <%s>" % (key, col, filtered_row[key]))
    return filtered_row

# ------------------------------------------------------------------------------
# Load a CSV file into a table of filtered rows.
#
# Each row is a dicationary that maps short access names (e.g. table['size'])
# onto the contents of the column that matches the full header name
# (e.g. 'Size of Data (bytes)')
#
# hdr_row_num is the ** 1-based ** (per Excel standard) row number for
# checking column titles.
#
# hdr_name_dict is the mapping of 'actual column title' to 'short_name'
# to use for the filtering.
# ------------------------------------------------------------------------------
def Load_CSV_Cols(filename, hdr_row_num, hdr_name_dict):
    table = []
    rows  = 0
    cols  = 0
    col_index_dict = {}

    Log_Info("Loading: %s" % filename)

    # Find the header row and get the column indexes for the hdr_name_dict
    f = open(filename, 'r')
    for line in f:
        rows += 1
        if rows % 1000 == 0:
            Log_Info("%d rows loaded..." % rows)

        if rows < hdr_row_num:
            continue
        elif rows == hdr_row_num:
            row = Parse_CSV_Row(line)
            for hdr_name in hdr_name_dict.keys():
                col_name = hdr_name_dict[hdr_name]
                col_index_dict[col_name] = Find_Header_Col(row, hdr_name)
                #Log_Debug("Load_CSV_Cols: <%s> = <%s>" % (col_name, col_index_dict[col_name]))
                cols += 1
        else:
            # Now in the data section, so add the filtered rows to the data table.
            #Log_Debug("Load_CSV_Cols: Parse data line <%s>" % line)
            row = Parse_CSV_Row(line)
            table.append(Filter_Row_By_Named_Index(row, col_index_dict))

    Log_Info("Done. [rows=%d/cols=%d]: %s" % (rows, cols, filename))
    return table

# ------------------------------------------------------------------------------
# Generically load a CSV file into a table that is a list of lists (values).
#
# Note that row and col access are both 0-based, so the row number in
# particular will NOT match the Excel 1-based standard.
# ------------------------------------------------------------------------------
def Load_CSV_File(filename):
    table = []
    rows = 0
    cols = 0
    Log_Info("Loading: %s" % filename)
    f = open(filename, 'r')
    for line in f:
        rows += 1
        row = Parse_CSV_Row(line)
        table.append(row)
        if cols == 0:
            cols = len(row)
        if rows % 1000 == 0:
            Log_Info("%d rows loaded..." % rows)

    Log_Info("Done. [rows=%d/cols=%d]: %s" % (rows, cols, filename))
    return table


# ------------------------------------------------------------------------------
# Excel Methods ----------------------------------------------------------------
# ------------------------------------------------------------------------------
def Load_Excel_File(filename):
    book = xlrd.open_workbook(filename)
    sheet = book.sheet_by_index(0)
    Log_Info("Loading [rows=%d/cols=%d]: %s" % (sheet.nrows, sheet.ncols, filename))
    table = []
    for r in range (0,sheet.nrows):
        row = []
        table.append(row)
        for c in range (0,sheet.ncols):
            value = sheet.cell_value(rowx=r, colx=c)
            row.append(value)
    Log_Info("Done.")
    return table

# ------------------------------------------------------------------------------
# The hdr_name_dict is a mapping of { 'Literal column name' => 'short_col_name' }
# The returned table is then a set of row objects, each row of which can be
# accessed by 'short_col_name' to get the cell value.
#
# This avoids typical issues with positional (array-based) access, especially
# if the filtered header list changes.
# ------------------------------------------------------------------------------
def Load_Excel_Cols(filename, hdr_row_num, hdr_name_dict):
    book  = xlrd.open_workbook(filename)
    sheet = book.sheet_by_index(0)
    table = []
    col_index_dict = {}

    Log_Info("Loading [rows=%d/cols=%d]: %s" % (sheet.nrows, sheet.ncols, filename))

    for r in range (0,sheet.nrows):
        if r < hdr_row_num-1:      # Before the header row
            continue

        elif r == hdr_row_num-1:   # Process the header row
            row = []
            for c in range (0,sheet.ncols):
                row.append(sheet.cell_value(rowx=r, colx=c))
            for hdr_name in hdr_name_dict.keys():
                col_name = hdr_name_dict[hdr_name]
                col_index_dict[col_name] = Find_Header_Col(row, hdr_name)

        else:                      # Process the data rows
            row_dict = {}
            for col_name in col_index_dict.keys():
                c = col_index_dict[col_name]
                if c == -1:
                    row_dict[col_name] = ''
                else:
                    row_dict[col_name] = sheet.cell_value(rowx=r, colx=c)
                #Log_Debug("Load_Excel_Cols: Add <%s> => <%s>" % (col_name, row_dict[col_name]))
            #Log_Debug("Load_Excel_Cols: Row done")
            table.append(row_dict)


    Log_Info("Done.")
    return table

# ------------------------------------------------------------------------------
# Spreadsheet Methods ----------------------------------------------------------
# ------------------------------------------------------------------------------
def Load_Spreadsheet_File(filename):
    if re.search(r'.xlsx?$', filename):
        return Load_Excel_File(filename)

    if re.search(r'.csv$', filename):
        return Load_CSV_File(filename)

    Quit("Load_Spreadsheet_File: Spreadsheet filename must be .xls, .xlsx, or .csv.")

# ------------------------------------------------------------------------------
def Load_Spreadsheet_Cols(filename, hdr_row_num, hdr_list):
    if re.search(r'.xlsx?$', filename):
        return Load_Excel_Cols(filename, hdr_row_num, hdr_list)

    if re.search(r'.csv$', filename):
        return Load_CSV_Cols(filename, hdr_row_num, hdr_list)

    Quit("Load_Spreadsheet_File: Spreadsheet filename must be .xls, .xlsx, or .csv.")

# ------------------------------------------------------------------------------
def Dump_Spreadsheet_Table(table, title=''):
    Log_Info(">>> Dump_Spreadsheet_Table %s" % title)

    sorted_cols = None
    if (len(table) > 0 and isinstance(table[0], dict)):
        sorted_cols = sorted(table[0].keys())
        Log_Info("    (is-dict) %s" % sorted_cols)

    for row in table:
        row_text = ''
        if not sorted_cols:
            for col in row:
                row_text += col
                row_text += ','
        else:
            for col in sorted_cols:
                row_text += row[col]
                row_text += ','
        Log_Info("    %s" % row_text)
    Log_Info("<<< END Dump_Spreadsheet_Table %s" % title)

# ------------------------------------------------------------------------------
# Self-test --------------------------------------------------------------------
# ------------------------------------------------------------------------------
def main(argv):
    ex1_hdr  = 2
    ex1_cols = { 'Column A Title' : 'A',
                 'Column C Title' : 'C',
                 'Bad-bad'        : 'all-blank' }
    table1a = Load_Spreadsheet_File('PSW_Spreadsheet_ex1.xlsx')
    table1b = Load_Spreadsheet_Cols('PSW_Spreadsheet_ex1.xlsx', ex1_hdr, ex1_cols)

    Dump_Spreadsheet_Table(table1a, 'full XLS')
    Dump_Spreadsheet_Table(table1b, 'filtered XLS')

    ex2_hdr  = 1
    ex2_cols = { 'Name of Data'   : 'name',
                 'Label of Data'  : 'label' }
    table2a = Load_Spreadsheet_File('PSW_Spreadsheet_ex2.csv')
    table2b = Load_Spreadsheet_Cols('PSW_Spreadsheet_ex2.csv', ex2_hdr, ex2_cols)

    Dump_Spreadsheet_Table(table2a, 'full CSV')
    Dump_Spreadsheet_Table(table2b, 'filtered CSV')

if __name__ == "__main__":
    main(sys.argv)
