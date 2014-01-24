# ##############################################################################
# This should be auto-generated from the SMD files.
#    SMD - Serialized Message Definition - TODO working title
# ##############################################################################
MSG_FIELDS = {}

# ------------------------------------------------------------------------------
MSG_FIELDS['T_LCU_Status_Request_Message'] = []
MSG_FIELDS['T_LCU_BIT_Request_Message'] = []
MSG_FIELDS['T_LCU_Force_Request_Message'] = []
# ------------------------------------------------------------------------------
MSG_FIELDS['T_LCU_Set_Lock_State_Command_Message'] = [
    'Lock_1_State',
    'Lock_2_State',
    ]
# ------------------------------------------------------------------------------
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
MSG_FIELDS['T_LCU_Force_Response_Message'] = [
    'Lock_1_Dog_Displacement_Force_Sensor',
    'Lock_2_Dog_Displacement_Force_Sensor',
    ]
# ------------------------------------------------------------------------------
def Pack_Message(msg_struct):
# TODO Only works for flat structures so far...
    msg_name = msg_struct['']
    msg      = msg_name
    for f in MSG_FIELDS[msg_name]:
        msg += ',' + str(msg_struct[f])
    return msg
# ------------------------------------------------------------------------------
def Unpack_Message(msg):
# TODO Only works for flat structures so far...
    values = msg.split(',')

    msg_struct = {}
    if MSG_FIELDS.has_key(values[0]):
        msg_name       = values[0]
        msg_struct[''] = msg_name
        v = 1
        for f in MSG_FIELDS[msg_name]:
            msg_struct[f] = values[v]
            v += 1
    else:
        msg_struct[''] = msg
    return msg_struct
