from Tkinter import *
from Sim_UDP_Channel import *
import PSW_Spreadsheet

as_int = PSW_Spreadsheet.as_int

DATA_CHANNEL = None
unit = {}
unit_by_widget = {}
grid_row = 0


# ##############################################################################
# This should be auto-generated from the SMD files.
#    SMD - Serialized Message Definition - TODO working title
# ##############################################################################
MSG_FIELDS = {}

MSG_FIELDS['T_LCU_Status_Response_Message'] = [
    'Overall_BIT_Passed',
# 'Lock_Sensor_Count',
# 'Lock_Sensor_Data[Lock_Sensor_Count].Lock_Busy',
# 'Lock_Sensor_Data[Lock_Sensor_Count].Lock_State',
# 'Lock_Sensor_Data[Lock_Sensor_Count].Next_Lock_State',

# 'Lock_Sensor_Count',
# { 'count':'Lock_Sensor_Count',
#   'aux': [
#       'Lock_Busy',
#       'Lock_State',
#       'Next_Lock_State'
#   ] }

    # UINT8                BIT_Passed;
    # UINT16               Lock_Sensor_Count;
    # T_Lock_Sensor_Data  * Lock_Sensor_Data;
    #     typedef struct {
    #         UINT8                Lock_Busy;
    #         UINT16               Lock_State;
    #         UINT16               Next_Lock_State;
    #     } T_Lock_Sensor_Data;
    ]
# ------------------------------------------------------------------------------
def Pack_T_LCU_Status_Response_Message(msg_struct):
    msg_name = msg_struct['']
    msg      = msg_name
    for f in MSG_FIELDS[msg_name]:
        msg += ',' + str(msg_struct[f])
    return msg
# ------------------------------------------------------------------------------
MSG_FIELDS['T_LCU_BIT_Response_Message'] = [
    'Overall_BIT_Passed',
    'Actuator_Extended',
    'Actuator_Retracted',
    'Capacitor_Charge_Disable',
    'Capacitor_Charge_State',
    'Actuator_Current',
    'Lock_Dog_Location_Sensor',
    'Lock_Dog_Displacement_Force_Sensor',
    'ADS_Trigger_Location_Sensor',
    'LCU_Point_of_Load_Power_Fault',
    'Actuator_Power_Enable_Serial_Switch_Fault',
    'Actuator_Extend_Serial_Switch_Fault',
    'Actuator_Retract_Serial_Switch_Fault',
    'Capacitor_Charge_Fault',
    'Reset_Fault',
    'Communications_Fault',
    'Actuator_Serial_Switch_State',
    'Solenoid_Serial_Switch_State',
    ]
# ------------------------------------------------------------------------------
def Pack_T_LCU_BIT_Response_Message(msg_struct):
    msg_name = msg_struct['']
    msg      = msg_name
    for f in MSG_FIELDS[msg_name]:
        msg += ',' + str(msg_struct[f])
    return msg
# ------------------------------------------------------------------------------
MSG_FIELDS['T_LCU_Force_Response_Message'] = [
    'Lock_1_Dog_Displacement_Force_Sensor',
    'Lock_2_Dog_Displacement_Force_Sensor',
    ]
# ------------------------------------------------------------------------------
def Pack_T_LCU_Force_Response_Message(msg_struct):
    msg_name = msg_struct['']
    msg      = msg_name
    for f in MSG_FIELDS[msg_name]:
        msg += ',' + str(msg_struct[f])
    return msg

# ##############################################################################
# Rx
# ##############################################################################
def Gui_Data_To_Msg_Struct(value_getter_func, msg_name):
    # The packer expects a struct-type definition.
    # So this function pulls GUI-based info together in a compatible struct.
    msg_struct = {'': msg_name}
    for f in MSG_FIELDS[msg_name]:
        msg_struct[f] = value_getter_func(f)
    return msg_struct
# ------------------------------------------------------------------------------
def Get_Field_As_Str(field_name):
    if not unit.has_key(field_name):
        print('Get_Field - no such field <%s>' % field_name)
        return 0
    return str(unit[field_name]['var'].get())
# ------------------------------------------------------------------------------
def Send_T_LCU_Status_Response_Message(value_getter_func):
    msg_struct = Gui_Data_To_Msg_Struct(value_getter_func, 'T_LCU_Status_Response_Message')
    DATA_CHANNEL.Send_Tx(Pack_T_LCU_Status_Response_Message(msg_struct))
# ------------------------------------------------------------------------------
def Send_T_LCU_BIT_Response_Message(value_getter_func):
    msg_struct = Gui_Data_To_Msg_Struct(value_getter_func, 'T_LCU_BIT_Response_Message')
    DATA_CHANNEL.Send_Tx(Pack_T_LCU_BIT_Response_Message(msg_struct))
# ------------------------------------------------------------------------------
def Send_T_LCU_Force_Response_Message(value_getter_func):
    msg_struct = Gui_Data_To_Msg_Struct(value_getter_func, 'T_LCU_Force_Response_Message')
    DATA_CHANNEL.Send_Tx(Pack_T_LCU_Force_Response_Message(msg_struct))
# ------------------------------------------------------------------------------
def Inc_Var(field_name):
    if unit.has_key(field_name):
        inc = as_int(unit[field_name]['var'].get()) + 1
        unit[field_name]['var'].set(inc)
# ------------------------------------------------------------------------------
def Set_Var(field_name, value):
    if unit.has_key(field_name):
        unit[field_name]['var'].set(value)
# ------------------------------------------------------------------------------
def Recv_Message(msg):
    if msg.startswith('T_LCU_Status_Request_Message'):
        Inc_Var('CP.REQ_STAT.count')
        Send_T_LCU_Status_Response_Message(Get_Field_As_Str)
    elif msg.startswith('T_LCU_BIT_Request_Message'):
        Inc_Var('CP.REQ_BIT.count')
        Set_Var('CP.REQ_BIT.info', 'TODO')   # TODO
        Send_T_LCU_BIT_Response_Message(Get_Field_As_Str)
    elif msg.startswith('T_LCU_Force_Request_Message'):
        Inc_Var('CP.REQ_FORCE.count')
        Send_T_LCU_Force_Response_Message(Get_Field_As_Str)
    elif msg.startswith('T_LCU_Set_Lock_State_Command_Message'):
        Set_Var('CP.Set_Lock_State', 'TODO')   # TODO
        pass   # TODO - no response for Lock message ?
    else:
        print 'Recv_Message - unknown ' + msg
# ##############################################################################
# GUI
# ##############################################################################
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
## # ------------------------------------------------------------------------------
## def Make_Tx_Lock(parent, unit_id, field_type, field_name, width=10, **options):
##     global grid_row
##     grid_row += 1
##     label   = Label(parent, text=field_name)
##     control = Button(parent, **options)
##     if width:
##         control.config(width=width)
##     label.grid(row=grid_row, column=0)
##     control.grid(row=grid_row, column=1)
##     control.bind('<Button-1>', Handle_Click)
##     unit[field_name] = {'unit_id':unit_id, 'field_name':field_name, 'field_type':field_type, 'control':control}
##     unit_by_widget[control] = field_name
## # ------------------------------------------------------------------------------
## def Make_Rx_Lock(parent, unit_id, field_type, field_name, width=10, **options):
##     global grid_row
##     grid_row += 1
##     label   = Label(parent, text=field_name)
##     control = Entry(parent, **options)
##     if width:
##         control.config(width=width)
##     label.grid(row=grid_row, column=0)
##     control.grid(row=grid_row, column=1)
##     control.bind('<Return>', Handle_Return)
##     unit[field_name] = {'unit_id':unit_id, 'field_name':field_name, 'field_type':field_type, 'control':control}
##     unit_by_widget[control] = field_name
# ------------------------------------------------------------------------------
def Make_Field(parent, unit_id, field_dir, field_type, field_name, width=10, **options):
    global grid_row
    grid_row += 1
    label = Label(parent, text=field_name)
    var   = None

    if field_type == 'BOOLEAN':
        var = IntVar()
        control = Checkbutton(parent, variable=var, **options)
        control.bind('<Button-1>', Handle_Click)

    elif field_type.startswith('UINT') or field_type.startswith('INT'):
# TODO numeric-only validator, (with optional range checking? might constrain error injection)
        var = StringVar()
        control = Entry(parent, textvariable=var, **options)
        control.bind('<Return>', Handle_Return)
    else:
        var = StringVar()
        control = Label(parent, text=field_type)

    if field_dir == 'rx':
        control.configure(state=DISABLED)

    label.grid(row=grid_row, column=0, sticky=E)
    control.grid(row=grid_row, column=1)
    unit[field_name] = {'unit_id':unit_id, 'field_name':field_name, 'field_type':field_type, 'control':control, 'var':var}
    unit_by_widget[control] = field_name

# ##############################################################################
# Main
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

Make_Field  (tk_root, lock_id, 'rx', 'UINT16',  'CP.REQ_STAT.count')
Make_Field  (tk_root, lock_id, 'rx', 'UINT16',  'CP.REQ_BIT.count')
Make_Field  (tk_root, lock_id, 'rx', 'UINT16',  'CP.REQ_BIT.info')
Make_Field  (tk_root, lock_id, 'rx', 'UINT16',  'CP.REQ_FORCE.count')
Make_Field  (tk_root, lock_id, 'rx', 'UINT16',  'CP.Set_Lock_State')

Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Overall_BIT_Passed')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Actuator_Extended')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Actuator_Retracted')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Capacitor_Charge_Disable')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Capacitor_Charge_State')
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'Actuator_Current')
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'Lock_Dog_Location_Sensor')
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'Lock_1_Dog_Displacement_Force_Sensor')
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'Lock_2_Dog_Displacement_Force_Sensor')
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'ADS_Trigger_Location_Sensor')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'LCU_Point_of_Load_Power_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Actuator_Power_Enable_Serial_Switch_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Actuator_Extend_Serial_Switch_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Actuator_Retract_Serial_Switch_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Capacitor_Charge_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Reset_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'BOOLEAN', 'Communications_Fault')
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'Actuator_Serial_Switch_State')   # ENUM-On_Off
Make_Field  (tk_root, lock_id, 'tx', 'UINT16',  'Solenoid_Serial_Switch_State')   # ENUM-On_Off

tk_root.mainloop()

# ****************************************************************************************************
## This first interface set was derived from looking at the HW context diagram.
## However, for CP / LCU development, the capability to fill in the specific
## return values is much more meaningful than having the ability to control
## the HW interface.  If the HW interface was controlled, then this LCU sim
## would have to implement some type of closed-loop feedback to pretend
## the voltages/currents/sensors were behaving like a real system.
## No need for a sim at that level now, if ever....
##
## Make_Field  (tk_root, lock_id, 'tx',  'GPIO',   'SOLENOID_CMD')
## Make_Field  (tk_root, lock_id, 'tx',  'GPIO',   'ACTUATOR_CMD')
## Make_Field  (tk_root, lock_id, 'tx',  'GPIO',   'WATCHDOG')
## Make_Field  (tk_root, lock_id, 'tx',  'PWM',    'STATUS_LEDS')
## Make_Field  (tk_root, lock_id, 'rx',  'ADC',    'ACTUATOR_CURRENT')
## Make_Field  (tk_root, lock_id, 'rx',  'ADC',    'FORCE_SENSOR')
## Make_Field  (tk_root, lock_id, 'rx',  'GPIO',   'LOCK_POS')
## Make_Field  (tk_root, lock_id, 'rx',  'GPIO',   'IDENT')
## Make_Field  (tk_root, lock_id, 'rx',  'GPIO',   'LEFT_RIGHT_IND')
## Make_Field  (tk_root, lock_id, 'rx',  'GPIO',   'SOLENOID_LOW_V')
## Make_Field  (tk_root, lock_id, 'rx',  'GPIO',   'STATUS_IND')
# ****************************************************************************************************

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
