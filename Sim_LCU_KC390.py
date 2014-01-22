from Tkinter import *

unit = {}
unit_by_widget = {}

# ------------------------------------------------------------------------------
def Handle_Click(event):
    # http://effbot.org/tkinterbook/tkinter-events-and-bindings.htm
    print dir(event)
    print event.widget
    if unit_by_widget.has_key(event.widget):
        print 'Handle_Click ' + unit_by_widget[event.widget]
    else:
        print 'Handle_Click unknown-widget'
# ------------------------------------------------------------------------------
def Handle_Return(event):
    # http://effbot.org/tkinterbook/tkinter-events-and-bindings.htm
    if unit_by_widget.has_key(event.widget):
        print 'Handle_Return ' + unit_by_widget[event.widget]
    else:
        print 'Handle_Return unknown-widget'
# ------------------------------------------------------------------------------
def Make_Tx_Lock(parent, grid_row, unit_id, io_type, io_name, width=10, **options):
    label   = Label(parent, text=io_name)
    control = Button(parent, **options)
    if width:
        control.config(width=width)
    label.grid(row=grid_row, column=0)
    control.grid(row=grid_row, column=1)
    control.bind('<Button-1>', Handle_Click)

    unit[io_name] = {'unit_id':unit_id, 'io_name':io_name, 'io_type':io_type, 'control':control}
    unit_by_widget[control] = io_name
# ------------------------------------------------------------------------------
def Make_Rx_Lock(parent, grid_row, unit_id, io_type, io_name, width=10, **options):
    label   = Label(parent, text=io_name)
    control = Entry(parent, **options)
    if width:
        control.config(width=width)
    label.grid(row=grid_row, column=0)
    control.grid(row=grid_row, column=1)
    control.bind('<Return>', Handle_Return)

    unit[io_name] = {'unit_id':unit_id, 'io_name':io_name, 'io_type':io_type, 'control':control}
    unit_by_widget[control] = io_name
# ==============================================================================
master = Tk()

Make_Tx_Lock(master,  0, -1, 'GPIO', 'SOLENOID_CMD')
Make_Tx_Lock(master,  1, -1, 'GPIO', 'ACTUATOR_CMD')
Make_Tx_Lock(master,  2, -1, 'GPIO', 'WATCHDOG')
Make_Tx_Lock(master,  3, -1, 'PWM',  'STATUS_LEDS')
Make_Rx_Lock(master,  4, -1, 'ADC',  'ACTUATOR_CURRENT')
Make_Rx_Lock(master,  5, -1, 'ADC',  'FORCE_SENSOR')
Make_Rx_Lock(master,  6, -1, 'GPIO', 'LOCK_POS')
Make_Rx_Lock(master,  7, -1, 'GPIO', 'IDENT')
Make_Rx_Lock(master,  8, -1, 'GPIO', 'LEFT_RIGHT_IND')
Make_Rx_Lock(master,  9, -1, 'GPIO', 'SOLENOID_LOW_V')
Make_Rx_Lock(master, 10, -1, 'GPIO', 'STATUS_IND')

mainloop()

# CSCI List
#
# CHC Display
#     Provide control of the GUI and process operator inputs
# CHC Display Boot Loader
#     Provides power up loading and integrity check of CHC Display CSCI and provides field loading support.
# CHC Command
#     Provide control of CHADS components during aerial delivery operations
# CHC Command Boot Loader
#     Provides power up loading and integrity check of CHC Command CSCI and provides field loading support.
# CHC Monitor
#     Provide control of CHADS components during aerial delivery operations
# CHC Monitor Boot Loader
#     Provides power up loading and integrity check of CHC Monitor CSCI and provides field loading support.
# CHC Video Processor
#     Provide display or real-time streaming video
# CHC Video Processor Boot Loader
#     Provides power up loading and integrity check of CHC Video Processor CSCI and provides field loading support.
# LCU Command
#     Provide control of electro-mechanical locks
# LCU Command Boot Loader
#     Provides power up loading and integrity check of LCU Command CSCI and provides field loading support.
# LCU Monitor
#     Provide control of electro-mechanical locks
# LCU Monitor Boot Loader
#     Provides power up loading and integrity check of LCU Monitor CSCI and provides field loading support.
# CP
#     Provide operator control of CHADS components during ground loading operations
# CP Boot Loader
#     Provides power up loading and integrity check of CP CSCI and provides field loading support.
# Software Field Loader
#     Field loads CSCI software and software updates onto the CHADS system (excepting boot loaders).
#
