"""
PSW_Basic_Log

Performance Software Basic Logging Module
Oct 15, 2013
John Lyons

Simple set of basic named logging functions.
Everything is sent to STDERR (so that redirectable output can go to STDOUT).

Enable/disable of Debugging output is controlled through setting
PSW_Basic_Log.g_debug = 0/1

Use this code block to alias the available commands to their matching names:

Log_Debug = PSW_Basic_Log.Log_Debug
Log_Info  = PSW_Basic_Log.Log_Info
Log_Warn  = PSW_Basic_Log.Log_Warn
Log_Error = PSW_Basic_Log.Log_Error
Log_Fatal = PSW_Basic_Log.Log_Fatal
Quit      = PSW_Basic_Log.Quit

"""

import sys

g_debug = 1

# ------------------------------------------------------------------------------
def Log_Debug(msg):
    if g_debug:
        sys.stdout.write("DEBUG: %s\n" % msg)

# ------------------------------------------------------------------------------
def Log_Info(msg):
    sys.stdout.write("%s\n" % msg)

# ------------------------------------------------------------------------------
def Log_Warn(msg):
    sys.stdout.write("WARNING: %s\n" % msg)

# ------------------------------------------------------------------------------
def Log_Error(msg):
    sys.stdout.write("ERROR: %s\n" % msg)

# ------------------------------------------------------------------------------
def Log_Fatal(msg):
    sys.stdout.write("FATAL: %s\n" % msg)
    exit(0)

# ------------------------------------------------------------------------------
def Quit(msg):
    if (msg.__len__() > 0):
        Log_Info(msg)
    exit(0)

