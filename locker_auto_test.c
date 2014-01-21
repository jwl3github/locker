#include <stdio.h>
#include "locker_auto.h"

BYTE   buffer[1024];
UINT16 buffer_max = (UINT16) sizeof(buffer);

UINT16 test_T_LCU_Status_Request_Message()
{
    UINT16 ok = 1;
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;
    T_LCU_Status_Request_Message* net_msg = 0;
    T_LCU_Status_Request_Message  out_msg;
    T_LCU_Status_Request_Message   in_msg;
    printf("----- T_LCU_Status_Request_Message\n");
    out_msg.Source_ID = 0;
    out_msg.Dest_ID = 1;
    out_msg.Packet_ID_Seq = 2;
    out_msg.Header_CR = 3;
    out_offset = Pack_T_LCU_Status_Request_Message(buffer, buffer_max, &out_msg);
    net_msg    = (T_LCU_Status_Request_Message*) buffer;
    in_offset  = Unpack_T_LCU_Status_Request_Message(buffer, buffer_max, &in_msg);
    if (in_msg.Source_ID == 0) { printf("PASS: Source_ID\n"); } else { ok=0; printf("FAIL: Source_ID\n"); }
    if (in_msg.Dest_ID == 1) { printf("PASS: Dest_ID\n"); } else { ok=0; printf("FAIL: Dest_ID\n"); }
    if (in_msg.Packet_ID_Seq == 2) { printf("PASS: Packet_ID_Seq\n"); } else { ok=0; printf("FAIL: Packet_ID_Seq\n"); }
    if (in_msg.Header_CR == 3) { printf("PASS: Header_CR\n"); } else { ok=0; printf("FAIL: Header_CR\n"); }
    return ok;
}
UINT16 test_T_LCU_BIT_Request_Message()
{
    UINT16 ok = 1;
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;
    T_LCU_BIT_Request_Message* net_msg = 0;
    T_LCU_BIT_Request_Message  out_msg;
    T_LCU_BIT_Request_Message   in_msg;
    printf("----- T_LCU_BIT_Request_Message\n");
    out_msg.Source_ID = 9;
    out_msg.Dest_ID = 10;
    out_msg.Lock_1_Actuator_Serial_Switch_IBIT = 11;
    out_msg.Lock_2_Actuator_Serial_Switch_IBIT = 12;
    out_msg.Lock_1_Actuator_Serial_Switch_State = 13;
    out_msg.Lock_2_Actuator_Serial_Switch_State = 14;
    out_msg.Lock_1_Solenoid_Serial_Switch_IBIT = 15;
    out_msg.Lock_2_Solenoid_Serial_Switch_IBIT = 16;
    out_msg.Lock_1_Solenoid_Serial_Switch_State = 17;
    out_msg.Lock_2_Solenoid_Serial_Switch_State = 18;
    out_msg.Packet_ID_Seq = 19;
    out_msg.Header_CR = 20;
    out_offset = Pack_T_LCU_BIT_Request_Message(buffer, buffer_max, &out_msg);
    net_msg    = (T_LCU_BIT_Request_Message*) buffer;
    in_offset  = Unpack_T_LCU_BIT_Request_Message(buffer, buffer_max, &in_msg);
    if (in_msg.Source_ID == 9) { printf("PASS: Source_ID\n"); } else { ok=0; printf("FAIL: Source_ID\n"); }
    if (in_msg.Dest_ID == 10) { printf("PASS: Dest_ID\n"); } else { ok=0; printf("FAIL: Dest_ID\n"); }
    if (in_msg.Lock_1_Actuator_Serial_Switch_IBIT == 11) { printf("PASS: Lock_1_Actuator_Serial_Switch_IBIT\n"); } else { ok=0; printf("FAIL: Lock_1_Actuator_Serial_Switch_IBIT\n"); }
    if (in_msg.Lock_2_Actuator_Serial_Switch_IBIT == 12) { printf("PASS: Lock_2_Actuator_Serial_Switch_IBIT\n"); } else { ok=0; printf("FAIL: Lock_2_Actuator_Serial_Switch_IBIT\n"); }
    if (in_msg.Lock_1_Actuator_Serial_Switch_State == 13) { printf("PASS: Lock_1_Actuator_Serial_Switch_State\n"); } else { ok=0; printf("FAIL: Lock_1_Actuator_Serial_Switch_State\n"); }
    if (in_msg.Lock_2_Actuator_Serial_Switch_State == 14) { printf("PASS: Lock_2_Actuator_Serial_Switch_State\n"); } else { ok=0; printf("FAIL: Lock_2_Actuator_Serial_Switch_State\n"); }
    if (in_msg.Lock_1_Solenoid_Serial_Switch_IBIT == 15) { printf("PASS: Lock_1_Solenoid_Serial_Switch_IBIT\n"); } else { ok=0; printf("FAIL: Lock_1_Solenoid_Serial_Switch_IBIT\n"); }
    if (in_msg.Lock_2_Solenoid_Serial_Switch_IBIT == 16) { printf("PASS: Lock_2_Solenoid_Serial_Switch_IBIT\n"); } else { ok=0; printf("FAIL: Lock_2_Solenoid_Serial_Switch_IBIT\n"); }
    if (in_msg.Lock_1_Solenoid_Serial_Switch_State == 17) { printf("PASS: Lock_1_Solenoid_Serial_Switch_State\n"); } else { ok=0; printf("FAIL: Lock_1_Solenoid_Serial_Switch_State\n"); }
    if (in_msg.Lock_2_Solenoid_Serial_Switch_State == 18) { printf("PASS: Lock_2_Solenoid_Serial_Switch_State\n"); } else { ok=0; printf("FAIL: Lock_2_Solenoid_Serial_Switch_State\n"); }
    if (in_msg.Packet_ID_Seq == 19) { printf("PASS: Packet_ID_Seq\n"); } else { ok=0; printf("FAIL: Packet_ID_Seq\n"); }
    if (in_msg.Header_CR == 20) { printf("PASS: Header_CR\n"); } else { ok=0; printf("FAIL: Header_CR\n"); }
    return ok;
}
UINT16 test_T_LCU_BIT_Response_Message()
{
    UINT16 ok = 1;
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;
    T_LCU_BIT_Response_Message* net_msg = 0;
    T_LCU_BIT_Response_Message  out_msg;
    T_LCU_BIT_Response_Message   in_msg;
    printf("----- T_LCU_BIT_Response_Message\n");
    out_msg.Source_ID = 21;
    out_msg.Dest_ID = 22;
    out_msg.Overall_BIT_Passed = 23;
    out_msg.Actuator_Extended = 24;
    out_msg.Actuator_Retracted = 25;
    out_msg.Capacitor_Charge_Disable = 26;
    out_msg.Capacitor_Charge_State = 27;
    out_msg.Actuator_Current = 28;
    out_msg.Lock_Dog_Location_Sensor = 29;
    out_msg.Lock_Dog_Displacement_Force_Sensor = 30;
    out_msg.ADS_Trigger_Location_Sensor = 31;
    out_msg.LCU_Point_of_Load_Power_Fault = 32;
    out_msg.Actuator_Power_Enable_Serial_Switch_Fault = 33;
    out_msg.Actuator_Extend_Serial_Switch_Fault = 34;
    out_msg.Actuator_Retract_Serial_Switch_Fault = 35;
    out_msg.Capacitor_Charge_Fault = 36;
    out_msg.Reset_Fault = 37;
    out_msg.Communications_Fault = 38;
    out_msg.Actuator_Serial_Switch_State = 39;
    out_msg.Solenoid_Serial_Switch_State = 40;
    out_msg.Packet_ID_Seq = 41;
    out_msg.Header_CR = 42;
    out_offset = Pack_T_LCU_BIT_Response_Message(buffer, buffer_max, &out_msg);
    net_msg    = (T_LCU_BIT_Response_Message*) buffer;
    in_offset  = Unpack_T_LCU_BIT_Response_Message(buffer, buffer_max, &in_msg);
    if (in_msg.Source_ID == 21) { printf("PASS: Source_ID\n"); } else { ok=0; printf("FAIL: Source_ID\n"); }
    if (in_msg.Dest_ID == 22) { printf("PASS: Dest_ID\n"); } else { ok=0; printf("FAIL: Dest_ID\n"); }
    if (in_msg.Overall_BIT_Passed == 23) { printf("PASS: Overall_BIT_Passed\n"); } else { ok=0; printf("FAIL: Overall_BIT_Passed\n"); }
    if (in_msg.Actuator_Extended == 24) { printf("PASS: Actuator_Extended\n"); } else { ok=0; printf("FAIL: Actuator_Extended\n"); }
    if (in_msg.Actuator_Retracted == 25) { printf("PASS: Actuator_Retracted\n"); } else { ok=0; printf("FAIL: Actuator_Retracted\n"); }
    if (in_msg.Capacitor_Charge_Disable == 26) { printf("PASS: Capacitor_Charge_Disable\n"); } else { ok=0; printf("FAIL: Capacitor_Charge_Disable\n"); }
    if (in_msg.Capacitor_Charge_State == 27) { printf("PASS: Capacitor_Charge_State\n"); } else { ok=0; printf("FAIL: Capacitor_Charge_State\n"); }
    if (in_msg.Actuator_Current == 28) { printf("PASS: Actuator_Current\n"); } else { ok=0; printf("FAIL: Actuator_Current\n"); }
    if (in_msg.Lock_Dog_Location_Sensor == 29) { printf("PASS: Lock_Dog_Location_Sensor\n"); } else { ok=0; printf("FAIL: Lock_Dog_Location_Sensor\n"); }
    if (in_msg.Lock_Dog_Displacement_Force_Sensor == 30) { printf("PASS: Lock_Dog_Displacement_Force_Sensor\n"); } else { ok=0; printf("FAIL: Lock_Dog_Displacement_Force_Sensor\n"); }
    if (in_msg.ADS_Trigger_Location_Sensor == 31) { printf("PASS: ADS_Trigger_Location_Sensor\n"); } else { ok=0; printf("FAIL: ADS_Trigger_Location_Sensor\n"); }
    if (in_msg.LCU_Point_of_Load_Power_Fault == 32) { printf("PASS: LCU_Point_of_Load_Power_Fault\n"); } else { ok=0; printf("FAIL: LCU_Point_of_Load_Power_Fault\n"); }
    if (in_msg.Actuator_Power_Enable_Serial_Switch_Fault == 33) { printf("PASS: Actuator_Power_Enable_Serial_Switch_Fault\n"); } else { ok=0; printf("FAIL: Actuator_Power_Enable_Serial_Switch_Fault\n"); }
    if (in_msg.Actuator_Extend_Serial_Switch_Fault == 34) { printf("PASS: Actuator_Extend_Serial_Switch_Fault\n"); } else { ok=0; printf("FAIL: Actuator_Extend_Serial_Switch_Fault\n"); }
    if (in_msg.Actuator_Retract_Serial_Switch_Fault == 35) { printf("PASS: Actuator_Retract_Serial_Switch_Fault\n"); } else { ok=0; printf("FAIL: Actuator_Retract_Serial_Switch_Fault\n"); }
    if (in_msg.Capacitor_Charge_Fault == 36) { printf("PASS: Capacitor_Charge_Fault\n"); } else { ok=0; printf("FAIL: Capacitor_Charge_Fault\n"); }
    if (in_msg.Reset_Fault == 37) { printf("PASS: Reset_Fault\n"); } else { ok=0; printf("FAIL: Reset_Fault\n"); }
    if (in_msg.Communications_Fault == 38) { printf("PASS: Communications_Fault\n"); } else { ok=0; printf("FAIL: Communications_Fault\n"); }
    if (in_msg.Actuator_Serial_Switch_State == 39) { printf("PASS: Actuator_Serial_Switch_State\n"); } else { ok=0; printf("FAIL: Actuator_Serial_Switch_State\n"); }
    if (in_msg.Solenoid_Serial_Switch_State == 40) { printf("PASS: Solenoid_Serial_Switch_State\n"); } else { ok=0; printf("FAIL: Solenoid_Serial_Switch_State\n"); }
    if (in_msg.Packet_ID_Seq == 41) { printf("PASS: Packet_ID_Seq\n"); } else { ok=0; printf("FAIL: Packet_ID_Seq\n"); }
    if (in_msg.Header_CR == 42) { printf("PASS: Header_CR\n"); } else { ok=0; printf("FAIL: Header_CR\n"); }
    return ok;
}
UINT16 test_T_LCU_Set_Lock_State_Command_Message()
{
    UINT16 ok = 1;
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;
    T_LCU_Set_Lock_State_Command_Message* net_msg = 0;
    T_LCU_Set_Lock_State_Command_Message  out_msg;
    T_LCU_Set_Lock_State_Command_Message   in_msg;
    printf("----- T_LCU_Set_Lock_State_Command_Message\n");
    out_msg.Source_ID = 43;
    out_msg.Dest_ID = 44;
    out_msg.Lock_1_State = 45;
    out_msg.Lock_2_State = 46;
    out_msg.Lock_3_State = 47;
    out_msg.Lock_4_State = 48;
    out_msg.Lock_5_State = 49;
    out_msg.Lock_6_State = 50;
    out_msg.Lock_7_State = 51;
    out_msg.Lock_8_State = 52;
    out_msg.Lock_9_State = 53;
    out_msg.Lock_10_State = 54;
    out_msg.Lock_11_State = 55;
    out_msg.Lock_12_State = 56;
    out_msg.Lock_13_State = 57;
    out_msg.Lock_14_State = 58;
    out_msg.Lock_15_State = 59;
    out_msg.Lock_16_State = 60;
    out_msg.Packet_ID_Seq = 61;
    out_msg.Header_CR = 62;
    out_offset = Pack_T_LCU_Set_Lock_State_Command_Message(buffer, buffer_max, &out_msg);
    net_msg    = (T_LCU_Set_Lock_State_Command_Message*) buffer;
    in_offset  = Unpack_T_LCU_Set_Lock_State_Command_Message(buffer, buffer_max, &in_msg);
    if (in_msg.Source_ID == 43) { printf("PASS: Source_ID\n"); } else { ok=0; printf("FAIL: Source_ID\n"); }
    if (in_msg.Dest_ID == 44) { printf("PASS: Dest_ID\n"); } else { ok=0; printf("FAIL: Dest_ID\n"); }
    if (in_msg.Lock_1_State == 45) { printf("PASS: Lock_1_State\n"); } else { ok=0; printf("FAIL: Lock_1_State\n"); }
    if (in_msg.Lock_2_State == 46) { printf("PASS: Lock_2_State\n"); } else { ok=0; printf("FAIL: Lock_2_State\n"); }
    if (in_msg.Lock_3_State == 47) { printf("PASS: Lock_3_State\n"); } else { ok=0; printf("FAIL: Lock_3_State\n"); }
    if (in_msg.Lock_4_State == 48) { printf("PASS: Lock_4_State\n"); } else { ok=0; printf("FAIL: Lock_4_State\n"); }
    if (in_msg.Lock_5_State == 49) { printf("PASS: Lock_5_State\n"); } else { ok=0; printf("FAIL: Lock_5_State\n"); }
    if (in_msg.Lock_6_State == 50) { printf("PASS: Lock_6_State\n"); } else { ok=0; printf("FAIL: Lock_6_State\n"); }
    if (in_msg.Lock_7_State == 51) { printf("PASS: Lock_7_State\n"); } else { ok=0; printf("FAIL: Lock_7_State\n"); }
    if (in_msg.Lock_8_State == 52) { printf("PASS: Lock_8_State\n"); } else { ok=0; printf("FAIL: Lock_8_State\n"); }
    if (in_msg.Lock_9_State == 53) { printf("PASS: Lock_9_State\n"); } else { ok=0; printf("FAIL: Lock_9_State\n"); }
    if (in_msg.Lock_10_State == 54) { printf("PASS: Lock_10_State\n"); } else { ok=0; printf("FAIL: Lock_10_State\n"); }
    if (in_msg.Lock_11_State == 55) { printf("PASS: Lock_11_State\n"); } else { ok=0; printf("FAIL: Lock_11_State\n"); }
    if (in_msg.Lock_12_State == 56) { printf("PASS: Lock_12_State\n"); } else { ok=0; printf("FAIL: Lock_12_State\n"); }
    if (in_msg.Lock_13_State == 57) { printf("PASS: Lock_13_State\n"); } else { ok=0; printf("FAIL: Lock_13_State\n"); }
    if (in_msg.Lock_14_State == 58) { printf("PASS: Lock_14_State\n"); } else { ok=0; printf("FAIL: Lock_14_State\n"); }
    if (in_msg.Lock_15_State == 59) { printf("PASS: Lock_15_State\n"); } else { ok=0; printf("FAIL: Lock_15_State\n"); }
    if (in_msg.Lock_16_State == 60) { printf("PASS: Lock_16_State\n"); } else { ok=0; printf("FAIL: Lock_16_State\n"); }
    if (in_msg.Packet_ID_Seq == 61) { printf("PASS: Packet_ID_Seq\n"); } else { ok=0; printf("FAIL: Packet_ID_Seq\n"); }
    if (in_msg.Header_CR == 62) { printf("PASS: Header_CR\n"); } else { ok=0; printf("FAIL: Header_CR\n"); }
    return ok;
}
UINT16 test_T_LCU_Force_Request_Message()
{
    UINT16 ok = 1;
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;
    T_LCU_Force_Request_Message* net_msg = 0;
    T_LCU_Force_Request_Message  out_msg;
    T_LCU_Force_Request_Message   in_msg;
    printf("----- T_LCU_Force_Request_Message\n");
    out_msg.Source_ID = 63;
    out_msg.Dest_ID = 64;
    out_msg.Packet_ID_Seq = 65;
    out_msg.Header_CR = 66;
    out_offset = Pack_T_LCU_Force_Request_Message(buffer, buffer_max, &out_msg);
    net_msg    = (T_LCU_Force_Request_Message*) buffer;
    in_offset  = Unpack_T_LCU_Force_Request_Message(buffer, buffer_max, &in_msg);
    if (in_msg.Source_ID == 63) { printf("PASS: Source_ID\n"); } else { ok=0; printf("FAIL: Source_ID\n"); }
    if (in_msg.Dest_ID == 64) { printf("PASS: Dest_ID\n"); } else { ok=0; printf("FAIL: Dest_ID\n"); }
    if (in_msg.Packet_ID_Seq == 65) { printf("PASS: Packet_ID_Seq\n"); } else { ok=0; printf("FAIL: Packet_ID_Seq\n"); }
    if (in_msg.Header_CR == 66) { printf("PASS: Header_CR\n"); } else { ok=0; printf("FAIL: Header_CR\n"); }
    return ok;
}
UINT16 test_T_LCU_Force_Response_Message()
{
    UINT16 ok = 1;
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;
    T_LCU_Force_Response_Message* net_msg = 0;
    T_LCU_Force_Response_Message  out_msg;
    T_LCU_Force_Response_Message   in_msg;
    printf("----- T_LCU_Force_Response_Message\n");
    out_msg.Source_ID = 67;
    out_msg.Dest_ID = 68;
    out_msg.Lock_1_Dog_Displacement_Force_Sensor = 69;
    out_msg.Lock_2_Dog_Displacement_Force_Sensor = 70;
    out_msg.Packet_ID_Seq = 71;
    out_msg.Header_CR = 72;
    out_offset = Pack_T_LCU_Force_Response_Message(buffer, buffer_max, &out_msg);
    net_msg    = (T_LCU_Force_Response_Message*) buffer;
    in_offset  = Unpack_T_LCU_Force_Response_Message(buffer, buffer_max, &in_msg);
    if (in_msg.Source_ID == 67) { printf("PASS: Source_ID\n"); } else { ok=0; printf("FAIL: Source_ID\n"); }
    if (in_msg.Dest_ID == 68) { printf("PASS: Dest_ID\n"); } else { ok=0; printf("FAIL: Dest_ID\n"); }
    if (in_msg.Lock_1_Dog_Displacement_Force_Sensor == 69) { printf("PASS: Lock_1_Dog_Displacement_Force_Sensor\n"); } else { ok=0; printf("FAIL: Lock_1_Dog_Displacement_Force_Sensor\n"); }
    if (in_msg.Lock_2_Dog_Displacement_Force_Sensor == 70) { printf("PASS: Lock_2_Dog_Displacement_Force_Sensor\n"); } else { ok=0; printf("FAIL: Lock_2_Dog_Displacement_Force_Sensor\n"); }
    if (in_msg.Packet_ID_Seq == 71) { printf("PASS: Packet_ID_Seq\n"); } else { ok=0; printf("FAIL: Packet_ID_Seq\n"); }
    if (in_msg.Header_CR == 72) { printf("PASS: Header_CR\n"); } else { ok=0; printf("FAIL: Header_CR\n"); }
    return ok;
}
int main(int argc, char** argv)
{
    UINT16 pass = 0;
    UINT16 fail = 0;
    if (test_T_LCU_Status_Request_Message() == 1) {pass++;} else {fail++;}
    if (test_T_LCU_BIT_Request_Message() == 1) {pass++;} else {fail++;}
    if (test_T_LCU_BIT_Response_Message() == 1) {pass++;} else {fail++;}
    if (test_T_LCU_Set_Lock_State_Command_Message() == 1) {pass++;} else {fail++;}
    if (test_T_LCU_Force_Request_Message() == 1) {pass++;} else {fail++;}
    if (test_T_LCU_Force_Response_Message() == 1) {pass++;} else {fail++;}
    printf("* Final pass=<%d> fail=<%d>\n", pass, fail);
    return 0;
}
