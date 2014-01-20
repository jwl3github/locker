#include <stdio.h>
#include "locker_auto.h"

BYTE   buffer[1024];
UINT16 buffer_max = 1024;

void test_T_Ping_Message()
{
    UINT16 out_offset = 0;
    UINT16 in_offset = 0;

    T_Ping_Message* net_msg = 0;
    T_Ping_Message out_msg;
    T_Ping_Message in_msg;

    out_msg.Sync            = 0x55AA;
    out_msg.Message_ID      = (UINT16) E_1001_Ping_Message;
    out_msg.Source_ID       = (UINT16) E_1064_CHC_D;
    out_msg.Dest_ID         = (UINT16) E_1068_LCU_C_1;
    out_msg.Word_Count      = (UINT16) sizeof(out_msg);   /* Fixed length */
    out_msg.Packet_ID_Seq   = 1;
    out_msg.Header_CR       = Calculate_CRC16((BYTE*)&out_msg, sizeof(out_msg) - sizeof(UINT16));  /* TODO is this correct size for CRC16 compute? */

    out_offset = Pack_T_Ping_Message(buffer, buffer_max, &out_msg);

    net_msg = (T_Ping_Message*) buffer;

    printf("-- Ping -- network\n");
    printf("--         net_msg.Sync            = x%x\n", net_msg->Sync           );
    printf("--         net_msg.Message_ID      = %d\n",  net_msg->Message_ID     );
    printf("--         net_msg.Source_ID       = %d\n",  net_msg->Source_ID      );
    printf("--         net_msg.Dest_ID         = %d\n",  net_msg->Dest_ID        );
    printf("--         net_msg.Word_Count      = %d\n",  net_msg->Word_Count     );
    printf("--         net_msg.Packet_ID_Seq   = %d\n",  net_msg->Packet_ID_Seq  );
    printf("--         net_msg.Header_CR       = x%x\n", net_msg->Header_CR      );


    in_offset = Unpack_T_Ping_Message(buffer, buffer_max, &in_msg);

    printf("-- Ping -- out_offset <%d>  in_offset <%d>\n", out_offset, in_offset);
    printf("--         in_msg.Sync            = x%x\n", in_msg.Sync           );
    printf("--         in_msg.Message_ID      = %d\n",  in_msg.Message_ID     );
    printf("--         in_msg.Source_ID       = %d\n",  in_msg.Source_ID      );
    printf("--         in_msg.Dest_ID         = %d\n",  in_msg.Dest_ID        );
    printf("--         in_msg.Word_Count      = %d\n",  in_msg.Word_Count     );
    printf("--         in_msg.Packet_ID_Seq   = %d\n",  in_msg.Packet_ID_Seq  );
    printf("--         in_msg.Header_CR       = x%x\n", in_msg.Header_CR      );

}

int main(int argc, char** argv)
{
    /*
    Highlight_Button_Command_Message m1001;
    LRU_Status_Periodic_Message m1002;
    Set_Main_Selection_Command_Message m1003;
    Delete_Event_Command_Message m1004;
    Control_Panel_State_Request_Message m1005;
    SOFTWARE_FIELD_LOAD_Message m1006;
    Release_Force_Periodic_Message m1007;
    Set_CRG_State_Command_Message m1008;
    Show_Dialog_Command_Message m1009;
    Highlight_Event_Command_Message m1010;
    _var m1000;
    Add_Platform_Command_Message m1000;
    Acknowledge_Message m1000;
    Add_Buffer_Stop_Command_Message m1000;
    Set_SPDU_Command_Message m1000;
    Control_Panel_State_Response_Message m1000;
    Set_Lock_Icons_Command_Message m1000;
    Delete_Cargo_Command_Message m1000;
    Update_Window_Command_Message m1000;
    Display_Configuration_Command_Message m1000;
    Set_CRG_Icons_Command_Message m1000;
    BIT_Response_Message m1000;
    Control_Panel_BIT_Response_Message m1000;
    Maintenance_Data_ARINC_Periodic_Message m1000;
    LCU_Force_Request_Message m1000;
    CHC_Display_BIT_Response_Message m1000;
    Set_Towplate_Icon_Command_Message m1000;
    Device_Status_Periodic_Message m1000;
    Control_Panel_Button_Press_Message m1000;
    Event_Data_Periodic_Message m1000;
    Add_Pallet_Command_Message m1000;
    Set_Mode_Command_Message m1000;
    Commands_Periodic_Message m1000;
    Lock_Status_Periodic_Message m1000;
    Add_Event_Command_Message m1000;
    Mission_Parameter_Command_Message m1000;
    LCU_Status_Request_Message m1000;
    Set_Lock_State_Command_Message m1000;
    Cargo_Periodic_Message m1000;
    BIT_Request_Message m1000;
    Add_CDS_Command_Message m1000;
    Monitor_Status_Periodic_Message m1000;
    LCU_BIT_Request_Message m1000;
    LCU_Set_Lock_State_Command_Message m1000;
    Delete_Buffer_Stop_Command_Message m1000;
    Add_Logistics_Command_Message m1000;
    Control_Panel_BIT_Request_Message m1000;
    LCU_Force_Response_Message m1000;
    System_Status_Periodic_Message m1000;
    Set_Event_Text_Command_Message m1000;
    Set_PDM_Icons_Command_Message m1000;
    Set_PDM_State_Command_Message m1000;
    Set_LCAS_Command_Message m1000;
    Command_Status_Periodic_Message m1000;
    Monitor_BIT_Response_Message m1000;
    LCU_BIT_Response_Message m1000;
    Maintenance_Data_Request_Message m1000;
    CHC_Display_BIT_Request_Message m1000;
    LCU_Status_Response_Message m1000;
    Set_Towplate_State_Command_Message m1000;
    */
    test_T_Ping_Message();
    return 0;
}
