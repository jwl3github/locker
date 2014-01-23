from Tkinter import *
from Sim_UDP_Channel import *

DATA_CHANNEL = None
unit = {}
unit_by_widget = {}
grid_row = 0

# ------------------------------------------------------------------------------
def Handle_Click(event):
    # http://effbot.org/tkinterbook/tkinter-events-and-bindings.htm
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
def Make_Tx_Lock(parent, unit_id, io_type, io_name, width=10, **options):
    global grid_row
    grid_row += 1
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
def Make_Rx_Lock(parent, unit_id, io_type, io_name, width=10, **options):
    global grid_row
    grid_row += 1
    label   = Label(parent, text=io_name)
    control = Entry(parent, **options)
    if width:
        control.config(width=width)
    label.grid(row=grid_row, column=0)
    control.grid(row=grid_row, column=1)
    control.bind('<Return>', Handle_Return)
    unit[io_name] = {'unit_id':unit_id, 'io_name':io_name, 'io_type':io_type, 'control':control}
    unit_by_widget[control] = io_name
# ------------------------------------------------------------------------------
def Make_Field(parent, unit_id, field_type, field_name, width=10, **options):
    global grid_row
    grid_row += 1
    label = Label(parent, text=field_name)
    if field_type == 'BOOLEAN':
        control = Checkbutton(parent, **options)
        control.bind('<Button-1>', Handle_Click)
    elif field_type == 'UINT16':
        control = Entry(parent, **options)
        control.bind('<Return>', Handle_Return)
    label.grid(row=grid_row, column=0)
    control.grid(row=grid_row, column=1)
    unit[field_name] = {'unit_id':unit_id, 'io_name':field_name, 'io_type':field_type, 'control':control}
    unit_by_widget[control] = field_name
# ##############################################################################
def Send_T_LCU_Status_Response_Message():
    DATA_CHANNEL.Send_Tx('T_LCU_Status_Response_Message')
# ------------------------------------------------------------------------------
def Send_T_LCU_BIT_Response_Message():
    DATA_CHANNEL.Send_Tx('T_LCU_BIT_Response_Message')
# ------------------------------------------------------------------------------
def Send_T_LCU_BIT_Response_Message():
    DATA_CHANNEL.Send_Tx('T_LCU_BIT_Response_Message')
# ------------------------------------------------------------------------------
def Send_T_LCU_Force_Response_Message():
    DATA_CHANNEL.Send_Tx('T_LCU_Force_Response_Message')
# ------------------------------------------------------------------------------
def Recv_Message(msg):
    if msg.startswith('T_LCU_Status_Request_Message'):
        Send_T_LCU_Status_Response_Message()
    elif msg.startswith('T_LCU_BIT_Request_Message'):
        Send_T_LCU_BIT_Response_Message()
    elif msg.startswith('T_LCU_Set_Lock_State_Command_Message'):
        pass   # TODO - no response for Lock message ?
    elif msg.startswith('T_LCU_Force_Request_Message'):
        Send_T_LCU_Force_Response_Message()
    else:
        print 'Recv_Message - unknown ' + msg
# ##############################################################################

first_lock_id = 1
lru_id        = 5   # TODO value is faked one for LCU-C-1

tk_root = Tk()
tk_root.wm_title('LCU for Lock %d/%d' % (first_lock_id, first_lock_id+1))


DATA_CHANNEL = Sim_UDP_Channel('224.1.1.1', 5006,  # Tx: LCU (Slave) Response channel
                               '224.1.1.2', 5007)  # Rx: CP (Master) Command channel
DATA_CHANNEL.Start_Tx()
DATA_CHANNEL.Start_Rx(Recv_Message)

lock_id = first_lock_id

Make_Tx_Lock(tk_root, lock_id, 'GPIO', 'SOLENOID_CMD')
Make_Tx_Lock(tk_root, lock_id, 'GPIO', 'ACTUATOR_CMD')
Make_Tx_Lock(tk_root, lock_id, 'GPIO', 'WATCHDOG')
Make_Tx_Lock(tk_root, lock_id, 'PWM',  'STATUS_LEDS')

Make_Rx_Lock(tk_root, lock_id, 'ADC',  'ACTUATOR_CURRENT')
Make_Rx_Lock(tk_root, lock_id, 'ADC',  'FORCE_SENSOR')
Make_Rx_Lock(tk_root, lock_id, 'GPIO', 'LOCK_POS')
Make_Rx_Lock(tk_root, lock_id, 'GPIO', 'IDENT')
Make_Rx_Lock(tk_root, lock_id, 'GPIO', 'LEFT_RIGHT_IND')
Make_Rx_Lock(tk_root, lock_id, 'GPIO', 'SOLENOID_LOW_V')
Make_Rx_Lock(tk_root, lock_id, 'GPIO', 'STATUS_IND')

Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Overall_BIT_Passed')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Actuator_Extended')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Actuator_Retracted')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Capacitor_Charge_Disable')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Capacitor_Charge_State')
Make_Field  (tk_root, lock_id, 'UINT16',  'Actuator_Current')
Make_Field  (tk_root, lock_id, 'UINT16',  'Lock_Dog_Location_Sensor')
Make_Field  (tk_root, lock_id, 'UINT16',  'Lock_Dog_Displacement_Force_Sensor')
Make_Field  (tk_root, lock_id, 'UINT16',  'ADS_Trigger_Location_Sensor')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'LCU_Point_of_Load_Power_Fault')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Actuator_Power_Enable_Serial_Switch_Fault')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Actuator_Extend_Serial_Switch_Fault')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Actuator_Retract_Serial_Switch_Fault')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Capacitor_Charge_Fault')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Reset_Fault')
Make_Field  (tk_root, lock_id, 'BOOLEAN', 'Communications_Fault')
Make_Field  (tk_root, lock_id, 'UINT16',  'Actuator_Serial_Switch_State')   # ENUM-On_Off
Make_Field  (tk_root, lock_id, 'UINT16',  'Solenoid_Serial_Switch_State')   # ENUM-On_Off

tk_root.mainloop()

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
