#include "locker_auto.h"
UINT16 Pack_T_Acknowledge_Message(BYTE buffer[], const UINT16 buffer_max, T_Acknowledge_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 1.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ACK_NAK));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->NAK_Reason));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Acknowledge_Message(BYTE buffer[], const UINT16 buffer_max, T_Acknowledge_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ACK_NAK));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->NAK_Reason));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Ping_Message(BYTE buffer[], const UINT16 buffer_max, T_Ping_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 2.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Ping_Message(BYTE buffer[], const UINT16 buffer_max, T_Ping_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 3.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 4.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 61;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Boot_Loader_Active));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->BIT_Status));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Boot_Loader_Active));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->BIT_Status));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Control_Panel_State_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 10.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 25;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_16_Locked_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_16_Fault_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_15_Locked_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_15_Fault_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_14_Locked_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_14_Fault_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_13_Locked_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_13_Fault_LED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LEDs_Off));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DIM_BRIGHT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->NVG_MODE));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Control_Panel_State_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_16_Locked_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_16_Fault_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_15_Locked_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_15_Fault_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_14_Locked_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_14_Fault_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_13_Locked_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Pair_13_Fault_LED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LEDs_Off));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DIM_BRIGHT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->NVG_MODE));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Control_Panel_State_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 11.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 27;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CBIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_1_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_2_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_3_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_4_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_5_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_6_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_7_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_8_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_9_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_10_Pressed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DIM_BRIGHT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->NVG_MODE));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Control_Panel_State_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CBIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_1_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_2_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_3_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_4_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_5_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_6_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_7_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_8_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_9_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_10_Pressed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DIM_BRIGHT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->NVG_MODE));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Control_Panel_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 12.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Control_Panel_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Control_Panel_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 13.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 62;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Power_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Communications_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Control_Panel_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Power_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Communications_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Display_Configuration_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Display_Configuration_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 50.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Display_Configuration_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Display_Configuration_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_LCAS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_LCAS_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 51.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->First_LCAS_Message));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Selected_LCAS_Message));
        { int f; for(f = 0; f < data->LCAS_Message_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Data[f].LCAS_Message_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Data[f].Acknowledged));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Data[f].SPARE));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_LCAS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_LCAS_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->First_LCAS_Message));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Selected_LCAS_Message));
        { int f; for(f = 0; f < data->LCAS_Message_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Data[f].LCAS_Message_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Data[f].Acknowledged));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_Data[f].SPARE));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCAS_Message_Data(BYTE buffer[], const UINT16 buffer_max, T_LCAS_Message_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Acknowledged));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->SPARE));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCAS_Message_Data(BYTE buffer[], const UINT16 buffer_max, T_LCAS_Message_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCAS_Message_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Acknowledged));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->SPARE));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_SPDU_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_SPDU_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 52.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Light));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_SPDU_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_SPDU_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Light));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Event_Text_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Event_Text_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 53.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Title), 16);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Lines));
        { int f; for(f = 0; f < data->Number_of_Lines; f++) {
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line[f]), 24);
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Event_Text_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Event_Text_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Title), 16);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Lines));
        { int f; for(f = 0; f < data->Number_of_Lines; f++) {
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line[f]), 24);
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Main_Selection_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Main_Selection_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 54.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Area));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Main_Selection_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Main_Selection_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Area));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Update_Window_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Update_Window_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 55.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Window_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Visible));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Highlighted_Field));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Update_Count));
        { int f; for(f = 0; f < data->Field_Update_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Field_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Enabled));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Field_Value));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Display_State));
        { int f; for(f = 0; f < data->Field_Data[f].Field_Value; f++) {
        byte_offset = Pack_Endian_Sz(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Text[f]));
        }}
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Update_Window_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Update_Window_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Window_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Visible));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Highlighted_Field));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Update_Count));
        { int f; for(f = 0; f < data->Field_Update_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Field_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Enabled));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Field_Value));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Display_State));
        { int f; for(f = 0; f < data->Field_Data[f].Field_Value; f++) {
        byte_offset = Unpack_Endian_Sz(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Data[f].Text[f]));
        }}
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Field_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Enabled));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Value));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Display_State));
        { int f; for(f = 0; f < data->Field_Value; f++) {
        byte_offset = Pack_Endian_Sz(buffer, buffer_max, byte_offset, (BYTE*)&(data->Text[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Field_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Enabled));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Field_Value));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Display_State));
        { int f; for(f = 0; f < data->Field_Value; f++) {
        byte_offset = Unpack_Endian_Sz(buffer, buffer_max, byte_offset, (BYTE*)&(data->Text[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Show_Dialog_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Show_Dialog_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 56.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 122;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Title), 26);
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line_1), 26);
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line_2), 26);
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line_3), 26);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Background_Color));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Show_Dialog_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Show_Dialog_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Title), 26);
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line_1), 26);
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line_2), 26);
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Line_3), 26);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Background_Color));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Mode_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Mode_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 57.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mode));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Mode_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Mode_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mode));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Add_Pallet_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Pallet_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 58.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Pallets));
        { int f; for(f = 0; f < data->Number_of_Pallets; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Pallet_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Orientation));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Detent_Offset));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Add_Pallet_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Pallet_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Pallets));
        { int f; for(f = 0; f < data->Number_of_Pallets; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Pallet_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Orientation));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Data[f].Detent_Offset));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Pallet_Data(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Orientation));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Detent_Offset));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Pallet_Data(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Orientation));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Detent_Offset));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Add_Platform_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Platform_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 59.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Platforms));
        { int f; for(f = 0; f < data->Number_of_Platforms; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Platform_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Detent_Offset));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Add_Platform_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Platform_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Platforms));
        { int f; for(f = 0; f < data->Number_of_Platforms; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Platform_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Data[f].Detent_Offset));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Platform_Data(BYTE buffer[], const UINT16 buffer_max, T_Platform_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Detent_Offset));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Platform_Data(BYTE buffer[], const UINT16 buffer_max, T_Platform_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Detent_Offset));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Add_CDS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_CDS_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 60.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Bundles));
        { int f; for(f = 0; f < data->Number_of_Bundles; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].CDS_Bundle_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Side));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].CDS_Skidboard_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Frame_Position));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Frame_Position_Offset));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Add_CDS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_CDS_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Bundles));
        { int f; for(f = 0; f < data->Number_of_Bundles; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].CDS_Bundle_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Side));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].CDS_Skidboard_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Frame_Position));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Bundle_Data[f].Frame_Position_Offset));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Bundle_Data(BYTE buffer[], const UINT16 buffer_max, T_Bundle_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Bundle_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Skidboard_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Frame_Position));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Frame_Position_Offset));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Bundle_Data(BYTE buffer[], const UINT16 buffer_max, T_Bundle_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Bundle_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Skidboard_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Frame_Position));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Frame_Position_Offset));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Add_Logistics_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Logistics_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 61.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Logistic_Items));
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Item_Number[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Size[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Frame_Position[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Offset[f]));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Add_Logistics_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Logistics_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Logistic_Items));
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Item_Number[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Size[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Frame_Position[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Logistic_Items; f++) {
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Offset[f]));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Delete_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Cargo_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 62.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Cargo_Items));
        { int f; for(f = 0; f < data->Number_of_Cargo_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID[f]));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Delete_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Cargo_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Cargo_Items));
        { int f; for(f = 0; f < data->Number_of_Cargo_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID[f]));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Add_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Buffer_Stop_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 63.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Position));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Add_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Buffer_Stop_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Position));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Delete_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Buffer_Stop_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 64.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Delete_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Buffer_Stop_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Lock_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_Icons_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 65.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Locks));
        { int f; for(f = 0; f < data->Number_of_Locks; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Locks; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Locks; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Icon[f]));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Lock_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_Icons_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Locks));
        { int f; for(f = 0; f < data->Number_of_Locks; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Locks; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_Locks; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Icon[f]));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_CRG_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_Icons_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 66.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_CRGs));
        { int f; for(f = 0; f < data->Number_of_CRGs; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_CRGs; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_CRGs; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Icon[f]));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_CRG_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_Icons_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_CRGs));
        { int f; for(f = 0; f < data->Number_of_CRGs; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_CRGs; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side[f]));
        }}
        { int f; for(f = 0; f < data->Number_of_CRGs; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Icon[f]));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_PDM_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_Icons_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 67.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Icon));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Icon));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_PDM_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_Icons_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Icon));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Icon));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Towplate_Icon_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_Icon_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 68.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Icon));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Towplate_Icon_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_Icon_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Icon));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Highlight_Button_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Button_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 69.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Highlight_Button_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Button_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Button_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Highlight_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 70.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Cargo_Items));
        { int f; for(f = 0; f < data->Number_of_Cargo_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Highlight_Data[f].Cargo_Number));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Highlight_Data[f].Highlight));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Highlight_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Cargo_Items));
        { int f; for(f = 0; f < data->Number_of_Cargo_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Highlight_Data[f].Cargo_Number));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Highlight_Data[f].Highlight));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Highlight_Cargo_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Highlight));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Highlight_Cargo_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Highlight));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Highlight_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 71.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Events));
        { int f; for(f = 0; f < data->Number_of_Events; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Highlight_Data[f].Event_Number));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Highlight_Data[f].Highlight));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Highlight_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Events));
        { int f; for(f = 0; f < data->Number_of_Events; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Highlight_Data[f].Event_Number));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Highlight_Data[f].Highlight));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Highlight_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Highlight));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Highlight_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Highlight));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Add_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Event_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 72.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Name), 10);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Color));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Cargo_Items));
        { int f; for(f = 0; f < data->Number_of_Cargo_Items; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number[f]));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Add_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Event_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Name), 10);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Color));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Cargo_Items));
        { int f; for(f = 0; f < data->Number_of_Cargo_Items; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number[f]));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Delete_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Event_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 73.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Events));
        { int f; for(f = 0; f < data->Number_of_Events; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number[f]));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Delete_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Event_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Number_of_Events));
        { int f; for(f = 0; f < data->Number_of_Events; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number[f]));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Control_Panel_Button_Press_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_Button_Press_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 78.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 22;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Button));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Button));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->PDM_Release_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Release_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Button));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Control_Panel_Button_Press_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_Button_Press_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Button));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Button));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->PDM_Release_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Release_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Button));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_CHC_Display_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 79.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 19;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_BIT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_RCP_BIT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Display_Check));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Display_Color));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_CHC_Display_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_BIT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_RCP_BIT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Display_Check));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Display_Color));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_CHC_Display_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 80.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 113;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_CHC_D_BIT_Passed));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_CP_BIT_Fail));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Command_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CP_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Maintenance_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Reset_Fault));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Hardware_Part_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Control_Panel_DC_Point_of__Load_Power_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Display_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Reset_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Boot_Fault));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Hardware_Part_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_CHC_Display_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_CHC_D_BIT_Passed));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_CP_BIT_Fail));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Command_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CP_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Maintenance_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Reset_Fault));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Hardware_Part_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Control_Panel_DC_Point_of__Load_Power_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Display_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Reset_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Boot_Fault));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CP_Hardware_Part_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_System_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_System_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 81.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 23;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Operational));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Active));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Armed));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->SPDA_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Current_Aerial_Delivery_Event));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->WOW));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_OK));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_System_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_System_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Operational));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Active));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Armed));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->SPDA_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Current_Aerial_Delivery_Event));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->WOW));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_OK));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Lock_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 82.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 78;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_4));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_5));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_6));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_7));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_8));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_9));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_10));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_11));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_12));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_4));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_5));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_6));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_7));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_8));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_9));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_10));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_11));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_12));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_13));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_14));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_15));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_16));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_13));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_14));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_15));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_16));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Lock_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_4));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_5));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_6));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_7));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_8));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_9));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_10));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_11));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Left_12));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_4));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_5));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_6));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_7));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_8));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_9));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_10));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_11));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Lock_Right_12));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_13));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_14));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_15));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Left_16));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_13));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_14));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_15));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Lock_Right_16));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Device_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Device_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 83.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 35;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_1));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_2));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_3));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_4));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_5_Ramp));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_6_Ramp));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_1));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_2));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_3));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_4));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Present));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Present));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Stowed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Stowed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Solenoid_1_Present));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Solenoid_2_Present));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Link_LOCK_Status));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Status));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Device_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Device_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_1));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_2));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_3));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_4));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_5_Ramp));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Left_6_Ramp));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_1));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_2));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_3));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Right_4));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Present));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Present));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Stowed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Stowed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Solenoid_1_Present));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Solenoid_2_Present));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Link_LOCK_Status));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Status));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LRU_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_LRU_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 84.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 57;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_C_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_VP_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_1_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_2_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_3_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_4_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_5_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_6_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->RCP_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_1_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_2_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_3_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_4_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_5_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_6_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_7_Fault_Ramp));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_8_Fault_Ramp));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_1_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_2_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_3_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_4_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_5_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_6_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_7_Fault_Ramp));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_8_Fault_Ramp));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LRU_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_LRU_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_C_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_D_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_VP_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_1_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_2_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_3_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_4_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_5_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCP_6_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->RCP_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_1_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_2_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_3_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_4_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_5_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_6_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_7_Fault_Ramp));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Left_8_Fault_Ramp));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_1_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_2_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_3_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_4_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_5_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_6_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_7_Fault_Ramp));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Right_8_Fault_Ramp));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Commands_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Commands_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 85.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 50;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ACTIVE_SAFE));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARM));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Master_Alert));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Electrical_Override));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_LOCAL_REMOTE));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Monitor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mission_Computer_RED));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mission_Computer_YELLOW));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mission_Computer_GREEN));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Commands_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Commands_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ACTIVE_SAFE));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARM));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Master_Alert));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Electrical_Override));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_LOCAL_REMOTE));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Monitor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mission_Computer_RED));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mission_Computer_YELLOW));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Mission_Computer_GREEN));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Event_Data_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 86.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Count));
        { int f; for(f = 0; f < data->Event_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Data[f].Event_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Data[f].Event_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Data[f].Event_Varaiant.Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Typed_Data>
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Event_Data_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Count));
        { int f; for(f = 0; f < data->Event_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Data[f].Event_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Data[f].Event_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Data[f].Event_Varaiant.Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Typed_Data>
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Event_Data_Variant(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Variant* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Typed_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Event_Data_Variant(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Variant* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Typed_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Event_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Varaiant.Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Typed_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Event_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Varaiant.Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Typed_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LVAD_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Extraction_Chute));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_PDM));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Towplate));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_1_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_2_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_3_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_4_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LVAD_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Extraction_Chute));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_PDM));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Towplate));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_1_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_2_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_3_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Platform_4_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LVAD_Recovery_Chute_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LAPES_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LAPES_Extraction_Chute));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LAPES_PDM));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LAPES_Platform_ID));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LAPES_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LAPES_Extraction_Chute));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LAPES_PDM));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LAPES_Platform_ID));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_CDS_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sequential_CRG_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Bundle_Count));
        { int f; for(f = 0; f < data->CDS_Bundle_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Bundle_ID[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_CDS_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sequential_CRG_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Bundle_Count));
        { int f; for(f = 0; f < data->CDS_Bundle_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Bundle_ID[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Combat_Offload_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Count));
        { int f; for(f = 0; f < data->Platform_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_ID[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Combat_Offload_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Count));
        { int f; for(f = 0; f < data->Platform_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_ID[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Cargo_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Cargo_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 87.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Buffer_Stop));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Buffer_Stop_Forward_Lock_Pair));
        { int f; for(f = 0; f < data->Pallet_Platform_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Pallet_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Pallet_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Detent_Offset));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Height));
        }}
        { int f; for(f = 0; f < data->CDS_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Cargo_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Position));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].CDS_Skidboard_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Side));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Recovery_Chute));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Static_Line_Length));
        }}
        { int f; for(f = 0; f < data->Logistic_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Cargo_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Position));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Length));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Side));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Cargo_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Cargo_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Buffer_Stop));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Buffer_Stop_Forward_Lock_Pair));
        { int f; for(f = 0; f < data->Pallet_Platform_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Pallet_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Pallet_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Detent_Offset));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Platform_Data[f].Height));
        }}
        { int f; for(f = 0; f < data->CDS_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Cargo_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Position));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].CDS_Skidboard_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Side));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Recovery_Chute));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Data[f].Static_Line_Length));
        }}
        { int f; for(f = 0; f < data->Logistic_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Cargo_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Position));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Length));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Logistic_Data[f].Side));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Pallet_Platform_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Platform_Data_Fields* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Detent_Offset));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Pallet_Platform_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Platform_Data_Fields* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Detent_Offset));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_CDS_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_CDS_Data_Fields* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Skidboard_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Recovery_Chute));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Static_Line_Length));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_CDS_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_CDS_Data_Fields* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CDS_Skidboard_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Recovery_Chute));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Static_Line_Length));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Logistic_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Logistic_Data_Fields* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Length));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Logistic_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Logistic_Data_Fields* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Cargo_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Height));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Length));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Side));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Release_Force_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Release_Force_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 88.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Sequence));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Expected_Force));
        { int f; for(f = 0; f < data->Lock_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Force_Data[f].Lock_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Force_Data[f].Lock_1_Actual_Force));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Release_Force_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Release_Force_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Sequence));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Expected_Force));
        { int f; for(f = 0; f < data->Lock_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Force_Data[f].Lock_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Force_Data[f].Lock_1_Actual_Force));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Lock_Force_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Force_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Actual_Force));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Lock_Force_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Force_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Actual_Force));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 100.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 20;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Side));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Side));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_PDM_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 101.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 16;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->PDM));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_PDM_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->PDM));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_Towplate_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 102.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Open_Link));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Close_Link));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Jettison));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Jettison));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_Towplate_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Open_Link));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Close_Link));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Jettison));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Jettison));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Set_CRG_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 103.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Operation));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Set_CRG_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Position));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Operation));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Monitor_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 104.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 28;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_BIT_Included));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_Lock_BIT));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_Lock_BIT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Serial_Switch_Command));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Serial_Switch_State));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Force_Comparison_Command));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Command));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Actuator_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Solenoid_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Monitor_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_BIT_Included));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_Lock_BIT));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_Lock_BIT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Serial_Switch_Command));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Serial_Switch_State));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Force_Comparison_Command));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Command));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Actuator_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Solenoid_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Monitor_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 105.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->AC_Input_Power_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DC_Output_Power_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DC_Point_of_Load_Power_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Serial_Switch_Status_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aircraft_Bus_BIT_Fault___Primary_Mission_Computer));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aircraft_Bus_BIT_Fault___Backup_Mission_Computer));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Command_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___LCU_Left_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___LCU_Right_Interface));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Count));
        { int f; for(f = 0; f < data->LCU_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Side));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Overall_LCU_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Boot_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Communications_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_DC_Point_of_Load_Power_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Reset_Fault));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Hardware_Part_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Overall_Lock_BIT_Fail));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Actuator));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Actuator_Extend));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Actuator_Retract));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Solenoid));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Lock_State_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Actuator_Current_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Ultra_Capacitor_BIT_Fault));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Monitor_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->AC_Input_Power_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DC_Output_Power_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->DC_Point_of_Load_Power_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Serial_Switch_Status_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aircraft_Bus_BIT_Fault___Primary_Mission_Computer));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aircraft_Bus_BIT_Fault___Backup_Mission_Computer));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___CHC_Command_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___LCU_Left_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->COM_Fault___LCU_Right_Interface));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Count));
        { int f; for(f = 0; f < data->LCU_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Side));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Overall_LCU_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Boot_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Communications_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_DC_Point_of_Load_Power_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Reset_Fault));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Hardware_Part_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Overall_Lock_BIT_Fail));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Actuator));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Actuator_Extend));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Actuator_Retract));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Serial_Switch_Status_BIT_Fault_Solenoid));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Lock_State_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].Actuator_Current_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Bit_Data[f].LCU_Ultra_Capacitor_BIT_Fault));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_Bit_Data(BYTE buffer[], const UINT16 buffer_max, T_LCU_Bit_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Number));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Side));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_LCU_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Boot_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Communications_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_DC_Point_of_Load_Power_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Hardware_Part_ID));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_Lock_BIT_Fail));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Actuator));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Actuator_Extend));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Actuator_Retract));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Solenoid));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Current_BIT_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Ultra_Capacitor_BIT_Fault));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_Bit_Data(BYTE buffer[], const UINT16 buffer_max, T_LCU_Bit_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Number));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Side));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_LCU_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Boot_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Communications_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_DC_Point_of_Load_Power_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Hardware_Part_ID));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_Lock_BIT_Fail));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Actuator));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Actuator_Extend));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Actuator_Retract));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Serial_Switch_Status_BIT_Fault_Solenoid));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Current_BIT_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Ultra_Capacitor_BIT_Fault));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Command_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Command_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 106.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 30;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->WOW));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_OK));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Enable_Switch));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_ARM_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Switch));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Local_Remote_Switch));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_ARM_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Button));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Command_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Command_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->WOW));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_OK));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Enable_Switch));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_ARM_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Switch));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Local_Remote_Switch));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_ARM_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Button));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Monitor_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 107.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 44;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_BIT_Passed));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_BIT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->WOW));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_OK));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Enable_Switch));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_ARM_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Switch));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Local_Remote_Switch));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_ARM_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Button));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Solenoid_Continuity));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Deployed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Solenoid_Continuity));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Deployed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Primary_Solenoid_Continuity));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Secondary_Solenoid_Continuity));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Drogue_Link_Latch_State));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Actuator_Extended));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Actuator_Retracted));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Present));
        { int f; for(f = 0; f < 32; f++) {
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Power_Enable));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Power_Enable_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Extend));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Extend_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Extended));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Retract));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Retracted));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Retract_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Solenoid_Enable));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Solenoid_Enable_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Solenoid_Continuity));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Current));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_Dog_Location_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_Dog_Displacement_Force_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].ADS_Trigger_Location_Sensor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_Busy));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Next_Lock_State));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Monitor_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_Status_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_M_BIT_Passed));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_BIT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->WOW));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_OK));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Enable_Switch));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_RED_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_ARM_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_YELLOW_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_GREEN_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Drogue_Jettison_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHC_Cargo_Jettison_Switch));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Local_Remote_Switch));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_RED_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_ARM_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_YELLOW_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_GREEN_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADP_Drogue_Jettison_Button));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Solenoid_Continuity));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Left_PDM_Deployed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Solenoid_Continuity));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Right_PDM_Deployed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Primary_Solenoid_Continuity));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Secondary_Solenoid_Continuity));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Drogue_Link_Latch_State));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Actuator_Extended));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Jettison_Actuator_Retracted));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_Present));
        { int f; for(f = 0; f < 32; f++) {
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Power_Enable));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Power_Enable_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Extend));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Extend_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Extended));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Retract));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Retracted));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Retract_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Solenoid_Enable));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Solenoid_Enable_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Solenoid_Continuity));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Actuator_Current));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_Dog_Location_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_Dog_Displacement_Force_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].ADS_Trigger_Location_Sensor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_Busy));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Lock_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Status_Data[f].Next_Lock_State));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Lock_Status_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Power_Enable));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Power_Enable_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extend));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extend_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extended));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retract));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retracted));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retract_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Enable));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Enable_Feedback));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Continuity));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Current));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Location_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Displacement_Force_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Trigger_Location_Sensor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Busy));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Next_Lock_State));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Lock_Status_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Power_Enable));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Power_Enable_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extend));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extend_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extended));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retract));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retracted));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retract_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Enable));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Enable_Feedback));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Continuity));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Current));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Location_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Displacement_Force_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Trigger_Location_Sensor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Busy));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Next_Lock_State));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Mission_Parameter_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 108.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Variant.Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Data>
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Mission_Parameter_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Variant.Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Data>
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Event_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Event_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LVAD_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Count_UNNEEDED));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->PDM));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Selected));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_1_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_1_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_1_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_2_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_2_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_2_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_3_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_3_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_3_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_4_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_4_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_4_Type));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LVAD_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Count_UNNEEDED));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->PDM));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Towplate_Selected));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_1_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_1_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_1_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_2_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_2_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_2_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_3_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_3_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_3_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_4_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Platform_4_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Chute_4_Type));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LAPES_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LAPES_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Weight));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Forward_Lock_Pair));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Extraction_Force));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Combat_Offload_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_1_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_1_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_2_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_2_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_3_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_3_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_4_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_4_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_5_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_5_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_6_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_6_Aft_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_7_Forward_Lock_Pair));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_7_Aft_Lock_Pair));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Combat_Offload_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_1_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_1_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_2_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_2_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_3_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_3_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_4_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_4_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_5_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_5_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_6_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_6_Aft_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_7_Forward_Lock_Pair));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Pallet_7_Aft_Lock_Pair));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_CDS_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1L_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2L_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3L_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4L_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_5L_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_6L_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1R_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2R_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3R_Used));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4R_Used));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1L_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2L_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3L_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4L_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_5L_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_6L_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1R_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2R_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3R_Delay));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4R_Delay));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_CDS_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Mission_Parameter_Event* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1L_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2L_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3L_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4L_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_5L_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_6L_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1R_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2R_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3R_Used));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4R_Used));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1L_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2L_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3L_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4L_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_5L_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_6L_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_1R_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_2R_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_3R_Delay));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->CRG_4R_Delay));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_Status_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 150.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_Status_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_Status_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 151.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->BIT_Passed));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Count));
        { int f; for(f = 0; f < data->Lock_Sensor_Count; f++) {
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Data[f].Lock_Busy));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Data[f].Lock_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Data[f].Next_Lock_State));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_Status_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->BIT_Passed));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Count));
        { int f; for(f = 0; f < data->Lock_Sensor_Count; f++) {
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Data[f].Lock_Busy));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Data[f].Lock_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Sensor_Data[f].Next_Lock_State));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Lock_Sensor_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Sensor_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Busy));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Next_Lock_State));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Lock_Sensor_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Sensor_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Busy));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Next_Lock_State));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 152.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 26;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Actuator_Serial_Switch_IBIT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Actuator_Serial_Switch_IBIT));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Actuator_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Actuator_Serial_Switch_State));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Solenoid_Serial_Switch_IBIT));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Solenoid_Serial_Switch_IBIT));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Solenoid_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Solenoid_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Actuator_Serial_Switch_IBIT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Actuator_Serial_Switch_IBIT));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Actuator_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Actuator_Serial_Switch_State));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Solenoid_Serial_Switch_IBIT));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Solenoid_Serial_Switch_IBIT));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Solenoid_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Solenoid_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 153.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 38;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_BIT_Passed));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extended));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retracted));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Capacitor_Charge_Disable));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Capacitor_Charge_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Current));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Location_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Displacement_Force_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Trigger_Location_Sensor));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Point_of_Load_Power_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Power_Enable_Serial_Switch_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extend_Serial_Switch_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retract_Serial_Switch_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Capacitor_Charge_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Communications_Fault));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Serial_Switch_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Overall_BIT_Passed));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extended));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retracted));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Capacitor_Charge_Disable));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Capacitor_Charge_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Current));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Location_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_Dog_Displacement_Force_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ADS_Trigger_Location_Sensor));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->LCU_Point_of_Load_Power_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Power_Enable_Serial_Switch_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Extend_Serial_Switch_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Retract_Serial_Switch_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Capacitor_Charge_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Reset_Fault));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Communications_Fault));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Actuator_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Solenoid_Serial_Switch_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Set_Lock_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 154.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 46;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_3_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_4_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_5_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_6_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_7_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_8_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_9_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_10_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_11_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_12_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_13_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_14_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_15_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_16_State));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Set_Lock_State_Command_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_3_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_4_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_5_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_6_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_7_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_8_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_9_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_10_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_11_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_12_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_13_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_14_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_15_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_16_State));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_Force_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 155.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_Force_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_LCU_Force_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 156.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Dog_Displacement_Force_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Dog_Displacement_Force_Sensor));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_LCU_Force_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Response_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_1_Dog_Displacement_Force_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Lock_2_Dog_Displacement_Force_Sensor));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Bit_64_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_64_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Bit_64_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_64_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Bit_32_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_32_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_2));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Bit_32_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_32_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_2));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_SOFTWARE_FIELD_LOAD_Message(BYTE buffer[], const UINT16 buffer_max, T_SOFTWARE_FIELD_LOAD_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 250.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 14;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Subformat_Data.Subformat_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Subformat_Data>
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_SOFTWARE_FIELD_LOAD_Message(BYTE buffer[], const UINT16 buffer_max, T_SOFTWARE_FIELD_LOAD_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Subformat_Data.Subformat_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Subformat_Data>
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Field_Load_Variant(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Variant* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Subformat_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Subformat_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Field_Load_Variant(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Variant* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Subformat_Type));
        // Cannot handle field type <VARIANT_ITEM> name <Subformat_Data>
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Field_Load_Request(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Request* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Field_Load_Request(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Request* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Field_Load_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Response* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Pack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Field_Load_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Response* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Software_Part_ID));
        byte_offset = Unpack_Endian_Ch(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_Number), 20);
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Hardware_Part_ID));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Field_Load_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Total_Data_Blocks));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Current_Data_Block));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Data_Word_Count));
        { int f; for(f = 0; f < data->Data_Word_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Data_Words[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Field_Load_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Data* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Total_Data_Blocks));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Current_Data_Block));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Data_Word_Count));
        { int f; for(f = 0; f < data->Data_Word_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Data_Words[f]));
        }}
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Field_Load_Complete_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Complete_Response* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_4));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_2));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_3));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Field_Load_Complete_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Complete_Response* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->File_CRC_64.Word_4));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_2));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_3));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Calculated_CRC_64.Word_4));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Maintenance_Data_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 200.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        data->Word_Count = (UINT16) 18;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Transmit_Data));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Tx_ARINC_Data));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Rx_ARINC_Data));
        byte_offset = Pack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Message_Data));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Maintenance_Data_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_Request_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Transmit_Data));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Tx_ARINC_Data));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->Rx_ARINC_Data));
        byte_offset = Unpack_Endian_08(buffer, buffer_max, byte_offset, (BYTE*)&(data->CHADS_Message_Data));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Pack_T_Maintenance_Data_ARINC_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_ARINC_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        data->Sync = (UINT16) 0x55AA;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        data->Message_ID = (UINT16) 201.0;
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARINC_Message_Count));
        { int f; for(f = 0; f < data->ARINC_Message_Count; f++) {
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARINC_Message_32_Bit_Data[f].Word_1));
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARINC_Message_32_Bit_Data[f].Word_2));
        }}
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        data->Word_Count = (UINT16) byte_offset;
        (void) Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        data->Header_CR = (UINT16) Calculate_CRC16(buffer, byte_offset);
        byte_offset = Pack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
UINT16 Unpack_T_Maintenance_Data_ARINC_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_ARINC_Periodic_Message* data)
{
    UINT16 byte_offset = 0;
    if (data != 0) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Sync));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Message_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Source_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Dest_ID));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Word_Count));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARINC_Message_Count));
        { int f; for(f = 0; f < data->ARINC_Message_Count; f++) {
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARINC_Message_32_Bit_Data[f].Word_1));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->ARINC_Message_32_Bit_Data[f].Word_2));
        }}
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Packet_ID_Seq));
        byte_offset = Unpack_Endian_16(buffer, buffer_max, byte_offset, (BYTE*)&(data->Header_CR));
    }
    return byte_offset;  // Actual length of processed buffer.
}
