#ifndef INCLUDED_Gen_Structs_h
#define INCLUDED_Gen_Structs_h
#include "locker_core.h"
/* -- Enums -- */
typedef enum {
    E_1140_OFF                     = 0,
    E_1141_RED                     = 1,
    E_1142_YELLOW                  = 2,
    E_1143_GREEN                   = 3,
    T_ENUM_Light_MAX
} T_ENUM_Light;
typedef enum {
    E_1205_Pos_425                 = 0,
    E_1206_Pos_435                 = 1,
    E_1207_Pos_445                 = 2,
    T_ENUM_Frame_Position_Type_MAX
} T_ENUM_Frame_Position_Type;
typedef enum {
    E_1280_LOCAL                   = 0,
    E_1281_REMOTE                  = 1,
    T_ENUM_LOCAL_REMOTE_MAX
} T_ENUM_LOCAL_REMOTE;
typedef enum {
    E_1217_DEPLOYED_ICON           = 0,
    E_1218_STOWED_ICON             = 1,
    E_1219_ARMED_ICON              = 2,
    E_1220_DROGUE_DEPLOYED_ICON    = 3,
    E_1221_FAULT_ICON              = 4,
    T_ENUM_PDM_Icon_MAX
} T_ENUM_PDM_Icon;
typedef enum {
    E_1229_No_Lock                 = 0,
    E_1230_ADS_Lock_Pair_1         = 1,
    E_1231_ADS_2                   = 2,
    E_1232_ADS_3                   = 3,
    E_1233_ADS_4                   = 4,
    E_1234_ADS_5                   = 5,
    E_1235_ADS_6                   = 6,
    E_1236_ADS_7                   = 7,
    E_1237_ADS_8                   = 8,
    E_1238_ADS_9                   = 9,
    E_1239_ADS_10                  = 10,
    E_1240_ADS_11                  = 11,
    E_1241_ADS_12                  = 12,
    E_1242_Logistics_Lock_Pair_13  = 13,
    E_1243_Logistics_14            = 14,
    E_1244_Logistics_15            = 15,
    E_1245_Logistics_16            = 16,
    T_ENUM_Lock_Button_MAX
} T_ENUM_Lock_Button;
typedef enum {
    E_1198_Left                    = 0,
    E_1199_Right                   = 1,
    E_1200_Both                    = 2,
    T_ENUM_Side_LRB_MAX
} T_ENUM_Side_LRB;
typedef enum {
    E_1089_NAK_negative_acknowledgement = 0,
    E_1090_ACK_positive_acknowledgement = 1,
    T_ENUM_ACK_NAK_MAX
} T_ENUM_ACK_NAK;
typedef enum {
    E_1257_No_PDM                  = 0,
    E_1258_Left_PDM                = 1,
    E_1259_Right_PDM               = 2,
    T_ENUM_PDM_Release_Button_MAX
} T_ENUM_PDM_Release_Button;
typedef enum {
    E_1296__1L                     = 1,
    E_1297__2L                     = 2,
    E_1298__3L                     = 3,
    E_1299__4L                     = 4,
    E_1300__5L_ramp                = 5,
    E_1301__6L_ramp                = 6,
    E_1302__1R                     = 7,
    E_1303__2R                     = 8,
    E_1304__3R                     = 9,
    E_1305__4R                     = 10,
    T_ENUM_CRG_MAX
} T_ENUM_CRG;
typedef enum {
    E_1173_dropdown_hide_list_of_menu_items__numeric_show_normal = 0,
    E_1174_dropdown_show_list_of_menu_items__numeric_show_outside_of_standards_yellow___not_used = 1,
    E_1175_dropdown_Unused__numeric_show_outside_of_standards_red = 2,
    T_ENUM_DropDown_or_Numeric_State_MAX
} T_ENUM_DropDown_or_Numeric_State;
typedef enum {
    E_1266_FAULT                   = 0,
    E_1267_LOCKED                  = 1,
    E_1268_UNLOCKED                = 2,
    E_1269_ARMED_ADS_only          = 3,
    T_ENUM_ADS_Lock_MAX
} T_ENUM_ADS_Lock;
typedef enum {
    E_1274_no_fault                = 0,
    E_1275_LCU_C_Fault             = 1,
    E_1276_LCU_M_Fault             = 2,
    E_1277_Both_LCU_C___LCU_M_faulted_or_general_LCU_fault = 3,
    T_ENUM_LCU_Fault_Type_MAX
} T_ENUM_LCU_Fault_Type;
typedef enum {
    E_1344_LOCKED                  = 1,
    E_1345_UNLOCKED                = 2,
    E_1346_ARMED_ADS_only          = 3,
    T_ENUM_Lock_State_MAX
} T_ENUM_Lock_State;
typedef enum {
    E_1187_Pallet_88_inch_wide     = 0,
    E_1188_Pallet_108_inch_wide    = 1,
    T_ENUM_Pallet_Orientation_MAX
} T_ENUM_Pallet_Orientation;
typedef enum {
    E_1359_SAFE                    = 0,
    E_1360_ACTIVE                  = 1,
    T_ENUM_Safe_Active_MAX
} T_ENUM_Safe_Active;
typedef enum {
    E_1222_CLOSED_ICON             = 0,
    E_1223_OPEN_ICON               = 1,
    E_1224_ARMED_ICON              = 2,
    E_1225_JETTISONED_ICON         = 3,
    E_1226_FAULT_ICON              = 4,
    T_ENUM_Towplate_Icon_MAX
} T_ENUM_Towplate_Icon;
typedef enum {
    E_1189__8_feet                 = 0,
    E_1190__12_feet                = 1,
    E_1191__16_feet                = 2,
    E_1192__20_feet                = 3,
    E_1193__24_feet                = 4,
    E_1194__28_feet                = 5,
    E_1195__32_feet                = 6,
    T_ENUM_Platform_Type_MAX
} T_ENUM_Platform_Type;
typedef enum {
    E_1246_none                    = 0,
    E_1247_CRG_Left_1              = 1,
    E_1248_CRG_Left_2              = 2,
    E_1249_CRG_Left_3              = 3,
    E_1250_CRG_Left_4              = 4,
    E_1251_CRG_Left_5_Ramp         = 5,
    E_1252_CRG_Left_6_Ramp         = 6,
    E_1253_CRG_Right_1             = 7,
    E_1254_CRG_Right_2             = 8,
    E_1255_CRG_Right_3             = 9,
    E_1256_CRG_Right_4             = 10,
    T_ENUM_CRG_Button_MAX
} T_ENUM_CRG_Button;
typedef enum {
    E_1176_OK_Button_1___Button_2_is_not_visible = 0,
    E_1177_Yes_No_Button_2_Button_1 = 1,
    E_1178_Edit_Delete_Button_2_Button1 = 2,
    T_ENUM_Button_Type_MAX
} T_ENUM_Button_Type;
typedef enum {
    E_1270_FAULT                   = 0,
    E_1271_LOCKED                  = 1,
    E_1272_UNLOCKED                = 2,
    E_1273_Unused                  = 3,
    T_ENUM_Logistic_Lock_MAX
} T_ENUM_Logistic_Lock;
typedef enum {
    E_1227_NORMAL                  = 0,
    E_1228_RED_JETTISON            = 1,
    T_ENUM_Event_Color_MAX
} T_ENUM_Event_Color;
typedef enum {
    E_1306_pallet_platform         = 0,
    E_1307_CDS                     = 1,
    E_1308_logistics               = 2,
    E_1309_buffer_stop             = 3,
    T_ENUM_Cargo_Type_MAX
} T_ENUM_Cargo_Type;
typedef enum {
    E_1213_NOT_PRESENT             = 0,
    E_1214_PRESENT                 = 1,
    E_1215_ARMED                   = 2,
    E_1216_FAULT                   = 3,
    T_ENUM_CRG_Icon_MAX
} T_ENUM_CRG_Icon;
typedef enum {
    E_1170_LCAS_Area               = 1,
    E_1171_Cargo_Area              = 2,
    E_1172_Button_Bar              = 3,
    T_ENUM_Field_ID_MAX
} T_ENUM_Field_ID;
typedef enum {
    E_1278_ACTIVE                  = 0,
    E_1279_SAFE                    = 1,
    T_ENUM_ACTIVE_SAFE_MAX
} T_ENUM_ACTIVE_SAFE;
typedef enum {
    E_1182_READY                   = 1,
    E_1183_DELIVERY                = 2,
    E_1184_CARGO_EDIT              = 3,
    E_1185_EVENT_EDIT              = 4,
    E_1186_DEVICE_CONTROL          = 5,
    T_ENUM_Mode_MAX
} T_ENUM_Mode;
typedef enum {
    E_1310_Type_V__8_foot          = 0,
    E_1311_Type_V__12_foot         = 1,
    E_1312_Type_V__16_foot         = 2,
    E_1313_Type_V__20_foot         = 3,
    E_1314_Type_V__24_foot         = 4,
    E_1315___Type_V_28_foot        = 5,
    E_1316_Type_V__32_foot         = 6,
    E_1317__463L__108_inch_wide    = 7,
    E_1318__463L__88_inch_wide     = 8,
    T_ENUM_Pallet_Type_MAX
} T_ENUM_Pallet_Type;
typedef enum {
    E_1319_Not_Used                = 0,
    E_1320_ADS_Lock_Left_1         = 1,
    E_1321_ADS_Lock_Left_2         = 2,
    E_1322_ADS_Lock_Left_3         = 3,
    E_1323_ADS_Lock_Left_4         = 4,
    E_1324_ADS_Lock_Left_5         = 5,
    E_1325_ADS_Lock_Left_6         = 6,
    E_1326_ADS_Lock_Left_7         = 7,
    E_1327_ADS_Lock_Left_8         = 8,
    E_1328_ADS_Lock_Left_9         = 9,
    E_1329_ADS_Lock_Left_10        = 10,
    E_1330_ADS_Lock_Left_11        = 11,
    E_1331_ADS_Lock_Left_12        = 12,
    E_1332_ADS_Lock_Right_1        = 13,
    E_1333_ADS_Lock_Right_2        = 14,
    E_1334_ADS_Lock_Right_3        = 15,
    E_1335_ADS_Lock_Right_4        = 16,
    E_1336_ADS_Lock_Right_5        = 17,
    E_1337_ADS_Lock_Right_6        = 18,
    E_1338_ADS_Lock_Right_7        = 19,
    E_1339_ADS_Lock_Right_8        = 20,
    E_1340_ADS_Lock_Right_9        = 21,
    E_1341_ADS_Lock_Right_10       = 22,
    E_1342_ADS_Lock_Right_11       = 23,
    E_1343_ADS_Lock_Right_12       = 24,
    T_ENUM_Lock_ID_MAX
} T_ENUM_Lock_ID;
typedef enum {
    E_1196_Left                    = 0,
    E_1197_Right                   = 1,
    T_ENUM_Side_LR_MAX
} T_ENUM_Side_LR;
typedef enum {
    E_1201__48_X_48_inches_        = 0,
    E_1202__54_X_48_inches         = 1,
    E_1203__72_X_48_inches         = 2,
    E_1204__96_X48_inches          = 3,
    T_ENUM_CDS_Skidboard_Type_MAX
} T_ENUM_CDS_Skidboard_Type;
typedef enum {
    E_1288__15_foot                = 1,
    E_1289__22_foot                = 2,
    E_1290__28_foot                = 3,
    E_1291__2_x_28_foot            = 4,
    T_ENUM_Extraction_Chute_MAX
} T_ENUM_Extraction_Chute;
typedef enum {
    E_1147_Main_Screen             = 0,
    E_1148_Pallet_Platform_Onload  = 1,
    E_1149_LVAD_LAPES              = 2,
    E_1150_CDS_Onload              = 3,
    E_1151_CDS_Event               = 4,
    E_1152_Logistics_Onload        = 5,
    E_1153_Combat_Offload          = 6,
    E_1154_Event_Manager           = 7,
    E_1155_Device_Control          = 8,
    E_1156_Lock_Control            = 9,
    E_1157_CRG_Control             = 10,
    E_1158_PDM_Control             = 11,
    E_1159_Towplate_Control        = 12,
    E_1160_Engineering_Data_Selection = 13,
    E_1161_ARINC_429               = 14,
    E_1162_Discretes               = 15,
    E_1163_Maintenance             = 16,
    E_1164_BIT_Status              = 17,
    E_1165_CHADS_Part_Numbers      = 18,
    E_1166_CHC_IBIT                = 19,
    E_1167_Lock_IBIT               = 20,
    E_1168_Device_IBIT             = 21,
    E_1169_Cargo_Jettison          = 22,
    T_ENUM_Window_ID_MAX
} T_ENUM_Window_ID;
typedef enum {
    E_1144_BUTTONS                 = 0,
    E_1145_CARGO                   = 1,
    E_1146_LCAS                    = 2,
    T_ENUM_Main_Screen_Area_MAX
} T_ENUM_Main_Screen_Area;
typedef enum {
    E_1000_Acknowledge_Message     = 1,
    E_1001_Ping_Message            = 2,
    E_1002_BIT_Request_Message     = 3,
    E_1003_BIT_Response_Message    = 4,
    E_1004_Control_Panel_State_Request_Message = 10,
    E_1005_Control_Panel_State_Response_Message = 11,
    E_1006_Control_Panel_BIT_Request_Message = 12,
    E_1007_Control_Panel_BIT_Response_Message = 13,
    E_1008_Display_Configuration_Command_Message = 50,
    E_1009_Set_LCAS_Command_Message = 51,
    E_1010_Set_SPDU_Command_Message = 52,
    E_1011_Set_Event_Text_Command_Message = 53,
    E_1012_Set_Main_Selection_Command_Message = 54,
    E_1013_Update_Window_Command_Message = 55,
    E_1014_Update_Window_Command_Message = 55,
    E_1015_Show_Dialog_Command_Message = 56,
    E_1016_Set_Mode_Command_Message = 57,
    E_1017_Add_Pallet_Command_Message = 58,
    E_1018_Add_Platform_Command_Message = 59,
    E_1019_Add_CDS_Command_Message = 60,
    E_1020_Add_Logistics_Command_Message = 61,
    E_1021_Delete_Cargo_Command_Message = 62,
    E_1022_Add_Buffer_Stop_Command_Message = 63,
    E_1023_Delete_Buffer_Stop_Command_Message = 64,
    E_1024_Set_Lock_Icons_Command_Message = 65,
    E_1025_Set_CRG_Icons_Command_Message = 66,
    E_1026_Set_PDM_Icons_Command_Message = 67,
    E_1027_Set_Towplate_Icon_Command_Message = 68,
    E_1028_Highlight_Button_Command_Message = 69,
    E_1029_Highlight_Cargo_Command_Message = 70,
    E_1030_Highlight_Event_Command_Message = 71,
    E_1031_Add_Event_Command_Message = 72,
    E_1032_Delete_Event_Command_Message = 73,
    E_1033_Control_Panel_Button_Press_Message = 78,
    E_1034_CHC_Display_BIT_Request_Message = 79,
    E_1035_CHC_Display_BIT_Response_Message = 80,
    E_1036_System_Status_Periodic_Message = 81,
    E_1037_Lock_Status_Periodic_Message = 82,
    E_1038_Device_Status_Periodic_Message = 83,
    E_1039_LRU_Status_Periodic_Message = 84,
    E_1040_Commands_Periodic_Message = 85,
    E_1041_Event_Data_Periodic_Message = 86,
    E_1042_Cargo_Periodic_Message  = 87,
    E_1043_Release_Force_Periodic_Message = 88,
    E_1044_Set_Lock_State_Command_Message = 100,
    E_1045_Set_PDM_State_Command_Message = 101,
    E_1046_Set_Towplate_State_Command_Message = 102,
    E_1047_Set_CRG_State_Command_Message = 103,
    E_1048_Monitor_BIT_Request_Message = 104,
    E_1049_Monitor_BIT_Response_Message = 105,
    E_1050_Command_Status_Periodic_Message = 106,
    E_1051_Monitor_Status_Periodic_Message = 107,
    E_1052_Mission_Parameter_Command_Message = 108,
    E_1053_LCU_Status_Request_Message = 150,
    E_1054_LCU_Status_Response_Message = 151,
    E_1055_LCU_BIT_Request_Message = 152,
    E_1056_LCU_BIT_Response_Message = 153,
    E_1057_LCU_Set_Lock_State_Command_Message = 154,
    E_1058_LCU_Force_Request_Message = 155,
    E_1059_LCU_Force_Response_Message = 156,
    E_1060_SOFTWARE_FIELD_LOAD_Message = 250,
    E_1061_Maintenance_Data_Request_Message = 200,
    E_1062_Maintenance_Data_ARINC_Periodic_Message = 201,
    T_ENUM_Message_ID_MAX
} T_ENUM_Message_ID;
typedef enum {
    E_1091_message_was_acknowledged = 0,
    E_1092_unable_to_execute_command_or_respond_to_request = 1,
    E_1093_unrecognized_message    = 2,
    E_1094_corrupted_message       = 3,
    E_1095_boot_loader_running     = 4,
    T_ENUM_NAK_Reason_MAX
} T_ENUM_NAK_Reason;
typedef enum {
    E_1096_BIT_passed              = 0,
    E_1097_BIT_failed_for_control_applications_full_BIT_results_can_be_requested = 1,
    E_1098_image_load_error        = 2,
    T_ENUM_BIT_Status_MAX
} T_ENUM_BIT_Status;
typedef enum {
    E_1063_Invalid                 = 0,
    E_1064_CHC_D                   = 1,
    E_1065_CHC_C                   = 2,
    E_1066_CHC_M                   = 3,
    E_1067_FIELD_LOADER            = 4,
    E_1068_LCU_C_1                 = 5,
    E_1069_LCU_M_1                 = 6,
    E_1070_LCU_C_2                 = 7,
    E_1071_LCU_M_2                 = 8,
    E_1072_LCU_C_3                 = 9,
    E_1073_LCU_M_3                 = 10,
    E_1074_LCU_C_4                 = 11,
    E_1075_LCU_M_4                 = 12,
    E_1076_LCU_C_5                 = 13,
    E_1077_LCU_M_5                 = 14,
    E_1078_LCU_C_6                 = 15,
    E_1079_LCU_M_6                 = 16,
    E_1080_LCU_C_7                 = 17,
    E_1081_LCU_M_7                 = 18,
    E_1082_LCU_C_8                 = 19,
    E_1083_LCU_M_8                 = 20,
    E_1084_CP_1                    = 21,
    E_1085_CP_2                    = 22,
    E_1086_CP_3                    = 23,
    E_1087_CP_4                    = 24,
    E_1088_CP_5                    = 25,
    T_ENUM_LRU_ID_MAX
} T_ENUM_LRU_ID;
typedef enum {
    E_1292_None                    = 0,
    E_1293_Custom_1                = 1,
    E_1294_Custom_2                = 2,
    E_1295_Custom_3                = 3,
    T_ENUM_Recovery_Chute_MAX
} T_ENUM_Recovery_Chute;
typedef enum {
    E_1099_Boot_Failure_Fault      = 1,
    E_1100_CHC_CCA_Reset_Fault     = 2,
    E_1101_AC_Input_Power_Fault    = 3,
    E_1102_DC_Output_Power_Fault   = 4,
    E_1103_DC_Point_of_Load_Power_Fault = 5,
    E_1104_Aircraft_Discrete_Input_Fault = 6,
    E_1105_Keypad_Communication_Fault = 7,
    E_1106_Keypad_Key_Check_Fault  = 8,
    E_1107_CHC_Switch_Check_Fault  = 9,
    E_1108_CHC_Serial_Switch_Status_Fault = 10,
    E_1109_CHC_Command_Serial_Switch_Fault = 11,
    E_1110_CHC_Monitor_Serial_Switch_Fault = 12,
    E_1111_CHC_Display_Fault       = 13,
    E_1112_Aircraft_Serial_Bus_Fault = 14,
    E_1113_Force_Sensor_Fault      = 15,
    E_1114_PDM_Status_Fault        = 16,
    E_1115_PDM_Operation_Fault     = 17,
    E_1116_Towplate_Status_Fault   = 18,
    E_1117_Towplate_Drogue_Link_Fault = 19,
    E_1118_Towplate_Jettison_Link_Fault = 20,
    E_1119_CRG_Operation_Fault     = 21,
    E_1120_Aerial_Delivery_Light_Fault = 22,
    E_1121_ADS_Lock_State_Fault    = 23,
    E_1122_ADS_Lock_Operation_Fault = 24,
    E_1123_Logistic_Lock_State_Fault = 25,
    E_1124_Logistic_Lock_Operation_Fault = 26,
    E_1125_LCU_DC_Point_of_Load_Power_Fault = 27,
    E_1126_LCU_Serial_Switch_Status_Fault = 28,
    E_1127_LCU_Command_Serial_Switch_Fault = 29,
    E_1128_LCU_Monitor_Serial_Switch_Fault = 30,
    E_1129_LCU_Actuator_Current_Fault = 31,
    E_1130_LCU_Ultra_Capacitor_Fault = 32,
    E_1131_LCU_Reset_Fault         = 33,
    E_1132_Control_Panel_DC_Point_of_Load_Power_Fault = 34,
    E_1133_Control_Panel_Reset_Fault = 35,
    E_1134_Control_Panel_Button_Fault = 36,
    E_1135_CSCI_Serial_Communication_Fault = 37,
    E_1136_Compatibility_Fault     = 38,
    E_1137_Reserved                = 39,
    E_1138_Reserved                = 40,
    E_1139_PAD                     = 41,
    T_ENUM_LCAS_Message_ID_MAX
} T_ENUM_LCAS_Message_ID;
typedef enum {
    E_1282_LVAD                    = 0,
    E_1283_LAPES                   = 1,
    E_1284_CDS                     = 2,
    E_1285_Combat_Offload          = 3,
    E_1286_Air_Drop                = 4,
    E_1287_Cargo_Jettison          = 5,
    T_ENUM_Event_Type_MAX
} T_ENUM_Event_Type;
typedef enum {
    E_1179_Bkg_Normal              = 0,
    E_1180_Bkg_Yellow              = 1,
    E_1181_Bkg_Red                 = 2,
    T_ENUM_Background_Color_MAX
} T_ENUM_Background_Color;
typedef enum {
    E_1260_black                   = 0,
    E_1261_white                   = 1,
    T_ENUM_Display_Color_MAX
} T_ENUM_Display_Color;
typedef enum {
    E_1347__1L                     = 1,
    E_1348__2L                     = 2,
    E_1349__3L                     = 3,
    E_1350__4L                     = 4,
    E_1351__5L                     = 5,
    E_1352__6L_ramp                = 6,
    E_1353__1R                     = 7,
    E_1354__2R                     = 8,
    E_1355__3R                     = 9,
    E_1356__4R                     = 10,
    T_ENUM_CRG_Position_MAX
} T_ENUM_CRG_Position;
typedef enum {
    E_1208_FAULT                   = 0,
    E_1209_LOCKED                  = 1,
    E_1210_UNLOCKED                = 2,
    E_1211_ARMED_ADS_only          = 3,
    E_1212_LCU_FAULT               = 4,
    T_ENUM_Lock_Icon_MAX
} T_ENUM_Lock_Icon;
typedef enum {
    E_1357_open                    = 0,
    E_1358_close                   = 1,
    T_ENUM_Open_Close_MAX
} T_ENUM_Open_Close;
typedef enum {
    E_1262_OFF                     = 0,
    E_1263_RED                     = 1,
    E_1264_YELLOW                  = 2,
    E_1265_GREEN                   = 3,
    T_ENUM_SPDA_State_MAX
} T_ENUM_SPDA_State;
typedef enum {
    E_1361_Off                     = 0,
    E_1362_On                      = 1,
    T_ENUM_Off_On_MAX
} T_ENUM_Off_On;
/* -- Aux Structs -- */
typedef struct {
    UINT16               LCAS_Message_ID;
    UINT8                Acknowledged;
    UINT8                SPARE;
} T_LCAS_Message_Data;
typedef struct {
    UINT16               Field_ID;
    UINT8                Enabled;
    UINT16               Field_Value;
    UINT16               Display_State;
    STRING              * Text;
} T_Field_Data;
typedef struct {
    UINT16               Cargo_ID;
    UINT16               Pallet_Number;
    UINT16               Weight;
    UINT16               Height;
    UINT16               Orientation;
    UINT16               Forward_Lock_Pair;
    UINT16               Detent_Offset;
} T_Pallet_Data;
typedef struct {
    UINT16               Cargo_ID;
    UINT16               Platform_Number;
    UINT16               Weight;
    UINT16               Height;
    UINT16               Type;
    UINT16               Forward_Lock_Pair;
    UINT16               Detent_Offset;
} T_Platform_Data;
typedef struct {
    UINT16               Cargo_ID;
    UINT16               CDS_Bundle_Number;
    UINT16               Side;
    UINT16               CDS_Skidboard_Type;
    UINT16               Weight;
    UINT16               Height;
    UINT16               Frame_Position;
    UINT8                Frame_Position_Offset;
} T_Bundle_Data;
typedef struct {
    UINT16               Cargo_Number;
    UINT8                Highlight;
} T_Highlight_Cargo_Data;
typedef struct {
    UINT16               Event_Number;
    UINT8                Highlight;
} T_Highlight_Event_Data;
typedef struct {
    UINT16               Event_Type;
} T_Event_Data_Variant;
typedef struct {
    UINT16               Event_ID;
    UINT8                Event_Number;
    T_Event_Data_Variant Event_Varaiant;
} T_Event_Data;
typedef struct {
    UINT16               LVAD_Extraction_Chute;
    UINT16               LVAD_PDM;
    UINT8                LVAD_Towplate;
    UINT16               LVAD_Platform_1_ID;
    UINT16               LVAD_Recovery_Chute_1;
    UINT16               LVAD_Platform_2_ID;
    UINT16               LVAD_Recovery_Chute_2;
    UINT16               LVAD_Platform_3_ID;
    UINT16               LVAD_Recovery_Chute_3;
    UINT16               LVAD_Platform_4_ID;
    UINT16               LVAD_Recovery_Chute_4;
} T_LVAD_Event;
typedef struct {
    UINT16               LAPES_Extraction_Chute;
    UINT16               LAPES_PDM;
    UINT16               LAPES_Platform_ID;
} T_LAPES_Event;
typedef struct {
    UINT16               CRG_1;
    UINT16               CRG_2;
    UINT16               Sequential_CRG_1;
    UINT16               CDS_Bundle_Count;
    UINT16              * CDS_Bundle_ID;
} T_CDS_Event;
typedef struct {
    UINT16               Platform_Count;
    UINT16              * Platform_ID;
} T_Combat_Offload_Event;
typedef struct {
    UINT16               Cargo_ID;
    UINT16               Pallet_Number;
    UINT16               Pallet_Type;
    UINT16               Forward_Lock_Pair;
    UINT16               Detent_Offset;
    UINT16               Weight;
    UINT16               Height;
} T_Pallet_Platform_Data_Fields;
typedef struct {
    UINT16               Cargo_ID;
    UINT16               Cargo_Number;
    UINT16               Position;
    UINT16               CDS_Skidboard_Type;
    UINT16               Side;
    UINT16               Weight;
    UINT16               Height;
    UINT16               Recovery_Chute;
    UINT16               Static_Line_Length;
} T_CDS_Data_Fields;
typedef struct {
    UINT16               Cargo_ID;
    UINT16               Cargo_Number;
    UINT16               Position;
    UINT16               Weight;
    UINT16               Height;
    UINT16               Length;
    UINT16               Side;
} T_Logistic_Data_Fields;
typedef struct {
    UINT16               Lock_1;
    UINT16               Lock_1_Actual_Force;
} T_Lock_Force_Data;
typedef struct {
    UINT16               LCU_Number;
    UINT16               LCU_Side;
    UINT8                Overall_LCU_BIT_Passed;
    UINT8                Boot_Fault;
    UINT8                Communications_Fault;
    UINT8                LCU_DC_Point_of_Load_Power_BIT_Fault;
    UINT8                Reset_Fault;
    CHAR                 LCU_Software_Part_Number[20];
    UINT16               LCU_Software_Part_ID;
    CHAR                 LCU_Hardware_Part_Number[20];
    UINT16               LCU_Hardware_Part_ID;
    UINT8                Overall_Lock_BIT_Fail;
    UINT8                LCU_Serial_Switch_Status_BIT_Fault_Actuator;
    UINT8                LCU_Serial_Switch_Status_BIT_Fault_Actuator_Extend;
    UINT8                LCU_Serial_Switch_Status_BIT_Fault_Actuator_Retract;
    UINT8                LCU_Serial_Switch_Status_BIT_Fault_Solenoid;
    UINT8                Lock_State_BIT_Fault;
    UINT8                Actuator_Current_BIT_Fault;
    UINT8                LCU_Ultra_Capacitor_BIT_Fault;
} T_LCU_Bit_Data;
typedef struct {
    UINT8                Lock_BIT_Passed;
    UINT8                Actuator_Power_Enable;
    UINT8                Actuator_Power_Enable_Feedback;
    UINT8                Actuator_Extend;
    UINT8                Actuator_Extend_Feedback;
    UINT8                Actuator_Extended;
    UINT8                Actuator_Retract;
    UINT8                Actuator_Retracted;
    UINT8                Actuator_Retract_Feedback;
    UINT8                Solenoid_Enable;
    UINT8                Solenoid_Enable_Feedback;
    UINT8                Solenoid_Continuity;
    UINT16               Actuator_Current;
    UINT16               Lock_Dog_Location_Sensor;
    UINT16               Lock_Dog_Displacement_Force_Sensor;
    UINT16               ADS_Trigger_Location_Sensor;
    UINT8                Lock_Busy;
    UINT16               Lock_State;
    UINT16               Next_Lock_State;
} T_Lock_Status_Data;
typedef struct {
    UINT16               Event_Type;
} T_Mission_Parameter_Event;
typedef struct {
    UINT16               Platform_Count_UNNEEDED;
    UINT16               PDM;
    UINT8                Towplate_Selected;
    UINT16               Platform_Count;
    UINT16               Platform_1_Forward_Lock_Pair;
    UINT16               Platform_1_Aft_Lock_Pair;
    UINT16               Extraction_Chute_1_Type;
    UINT16               Extraction_Force_1;
    UINT16               Platform_2_Forward_Lock_Pair;
    UINT16               Platform_2_Aft_Lock_Pair;
    UINT16               Extraction_Chute_2_Type;
    UINT16               Extraction_Force_2;
    UINT16               Platform_3_Forward_Lock_Pair;
    UINT16               Platform_3_Aft_Lock_Pair;
    UINT16               Extraction_Chute_3_Type;
    UINT16               Extraction_Force_3;
    UINT16               Platform_4_Forward_Lock_Pair;
    UINT16               Platform_4_Aft_Lock_Pair;
    UINT16               Extraction_Chute_4_Type;
    UINT16               Extraction_Force_4;
} T_LVAD_Mission_Parameter_Event;
typedef struct {
    UINT16               Weight;
    UINT16               Forward_Lock_Pair;
    UINT8                Aft_Lock_Pair;
    UINT16               Extraction_Force;
} T_LAPES_Mission_Parameter_Event;
typedef struct {
    UINT16               Pallet_Count;
    UINT16               Pallet_1_Forward_Lock_Pair;
    UINT16               Pallet_1_Aft_Lock_Pair;
    UINT16               Pallet_2_Forward_Lock_Pair;
    UINT16               Pallet_2_Aft_Lock_Pair;
    UINT16               Pallet_3_Forward_Lock_Pair;
    UINT16               Pallet_3_Aft_Lock_Pair;
    UINT16               Pallet_4_Forward_Lock_Pair;
    UINT16               Pallet_4_Aft_Lock_Pair;
    UINT16               Pallet_5_Forward_Lock_Pair;
    UINT16               Pallet_5_Aft_Lock_Pair;
    UINT16               Pallet_6_Forward_Lock_Pair;
    UINT16               Pallet_6_Aft_Lock_Pair;
    UINT16               Pallet_7_Forward_Lock_Pair;
    UINT16               Pallet_7_Aft_Lock_Pair;
} T_Combat_Offload_Mission_Parameter_Event;
typedef struct {
    UINT8                CRG_1L_Used;
    UINT8                CRG_2L_Used;
    UINT8                CRG_3L_Used;
    UINT8                CRG_4L_Used;
    UINT8                CRG_5L_Used;
    UINT8                CRG_6L_Used;
    UINT8                CRG_1R_Used;
    UINT8                CRG_2R_Used;
    UINT8                CRG_3R_Used;
    UINT8                CRG_4R_Used;
    UINT16               CRG_1L_Delay;
    UINT16               CRG_2L_Delay;
    UINT16               CRG_3L_Delay;
    UINT16               CRG_4L_Delay;
    UINT16               CRG_5L_Delay;
    UINT16               CRG_6L_Delay;
    UINT16               CRG_1R_Delay;
    UINT16               CRG_2R_Delay;
    UINT16               CRG_3R_Delay;
    UINT16               CRG_4R_Delay;
} T_CDS_Mission_Parameter_Event;
typedef struct {
    UINT8                Lock_Busy;
    UINT16               Lock_State;
    UINT16               Next_Lock_State;
} T_Lock_Sensor_Data;
typedef struct {
    UINT16               Word_1;
    UINT16               Word_2;
    UINT16               Word_3;
    UINT16               Word_4;
} T_Bit_64_Data;
typedef struct {
    UINT16               Word_1;
    UINT16               Word_2;
} T_Bit_32_Data;
typedef struct {
    UINT16               Subformat_Type;
} T_Field_Load_Variant;
typedef struct {
} T_Field_Load_Request;
typedef struct {
    CHAR                 Software_Part_Number[20];
    UINT16               Software_Part_ID;
    CHAR                 Hardware_Part_Number[20];
    UINT16               Hardware_Part_ID;
} T_Field_Load_Response;
typedef struct {
    UINT16               Total_Data_Blocks;
    UINT16               Current_Data_Block;
    UINT16               Data_Word_Count;
    UINT16              * Data_Words;
} T_Field_Load_Data;
typedef struct {
    T_Bit_64_Data        File_CRC_64;
    T_Bit_64_Data        Calculated_CRC_64;
} T_Field_Load_Complete_Response;
/* -- Rec Structs -- */
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               ACK_NAK;
    UINT16               NAK_Reason;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Acknowledge_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Ping_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_BIT_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Boot_Loader_Active;
    UINT16               BIT_Status;
    CHAR                 Software_Part_Number[20];
    UINT16               Software_Part_ID;
    CHAR                 Hardware_Part_Number[20];
    UINT16               Hardware_Part_ID;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_BIT_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Aft_Pair_16_Locked_LED;
    UINT8                Aft_Pair_16_Fault_LED;
    UINT8                Aft_Pair_15_Locked_LED;
    UINT8                Aft_Pair_15_Fault_LED;
    UINT8                Aft_Pair_14_Locked_LED;
    UINT8                Aft_Pair_14_Fault_LED;
    UINT8                Aft_Pair_13_Locked_LED;
    UINT8                Aft_Pair_13_Fault_LED;
    UINT8                LEDs_Off;
    UINT8                DIM_BRIGHT;
    UINT8                NVG_MODE;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Control_Panel_State_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CBIT_Passed;
    UINT8                Button_1_Pressed;
    UINT8                Button_2_Pressed;
    UINT8                Button_3_Pressed;
    UINT8                Button_4_Pressed;
    UINT8                Button_5_Pressed;
    UINT8                Button_6_Pressed;
    UINT8                Button_7_Pressed;
    UINT8                Button_8_Pressed;
    UINT8                Button_9_Pressed;
    UINT8                Button_10_Pressed;
    UINT8                DIM_BRIGHT;
    UINT8                NVG_MODE;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Control_Panel_State_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Control_Panel_BIT_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Overall_BIT_Passed;
    UINT8                Power_Fault;
    UINT8                Communications_Fault;
    UINT8                Reset_Fault;
    CHAR                 Software_Part_Number[20];
    UINT16               Software_Part_ID;
    CHAR                 Hardware_Part_Number[20];
    UINT16               Hardware_Part_ID;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Control_Panel_BIT_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Display_Configuration_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               LCAS_Message_Count;
    UINT16               First_LCAS_Message;
    UINT16               Selected_LCAS_Message;
    T_LCAS_Message_Data * LCAS_Message_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_LCAS_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Light;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_SPDU_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    CHAR                 Title[16];
    UINT16               Number_of_Lines;
    CHAR                * Line[24];
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Event_Text_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Area;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Main_Selection_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Window_ID;
    UINT8                Visible;
    UINT16               Highlighted_Field;
    UINT16               Field_Update_Count;
    T_Field_Data        * Field_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Update_Window_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    CHAR                 Title[26];
    CHAR                 Line_1[26];
    CHAR                 Line_2[26];
    CHAR                 Line_3[26];
    UINT16               Button_Type;
    UINT16               Background_Color;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Show_Dialog_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Mode;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Mode_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Pallets;
    T_Pallet_Data       * Pallet_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Add_Pallet_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Platforms;
    T_Platform_Data     * Platform_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Add_Platform_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Bundles;
    T_Bundle_Data       * Bundle_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Add_CDS_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Logistic_Items;
    UINT16              * Cargo_ID;
    UINT16              * Logistic_Item_Number;
    UINT16              * Side;
    UINT16              * Size;
    UINT16              * Weight;
    UINT16              * Height;
    UINT16              * Frame_Position;
    UINT8               * Offset;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Add_Logistics_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Cargo_Items;
    UINT16              * Cargo_ID;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Delete_Cargo_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Cargo_ID;
    UINT16               Forward_Lock_Position;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Add_Buffer_Stop_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Cargo_ID;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Delete_Buffer_Stop_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Locks;
    UINT16              * Position;
    UINT16              * Side;
    UINT16              * Icon;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Lock_Icons_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_CRGs;
    UINT16              * Position;
    UINT16              * Side;
    UINT16              * Icon;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_CRG_Icons_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Left_PDM_Icon;
    UINT16               Right_PDM_Icon;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_PDM_Icons_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Icon;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Towplate_Icon_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Button_Number;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Highlight_Button_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Cargo_Items;
    T_Highlight_Cargo_Data* Cargo_Highlight_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Highlight_Cargo_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Events;
    T_Highlight_Event_Data* Event_Highlight_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Highlight_Event_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Event_ID;
    UINT16               Event_Number;
    CHAR                 Event_Name[10];
    UINT16               Color;
    UINT16               Number_of_Cargo_Items;
    UINT16              * Cargo_Number;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Add_Event_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Number_of_Events;
    UINT16              * Event_Number;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Delete_Event_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Lock_Button;
    UINT16               CRG_Button;
    UINT16               PDM_Release_Button;
    UINT8                Towplate_Release_Button;
    UINT8                Towplate_Jettison_Button;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Control_Panel_Button_Press_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CHC_D_BIT;
    UINT8                LCP_RCP_BIT;
    UINT8                Display_Check;
    UINT16               Display_Color;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_CHC_Display_BIT_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Overall_CHC_D_BIT_Passed;
    UINT16               Overall_CP_BIT_Fail;
    UINT8                COM_Fault___CHC_Command_Interface;
    UINT8                COM_Fault___CP_Interface;
    UINT8                COM_Fault___CHC_Maintenance_Interface;
    UINT8                CHC_D_Reset_Fault;
    CHAR                 CHC_D_Software_Part_Number[20];
    UINT16               CHC_D_Software_Part_ID;
    CHAR                 CHC_D_Hardware_Part_Number[20];
    UINT16               CHC_D_Hardware_Part_ID;
    UINT8                Control_Panel_DC_Point_of__Load_Power_BIT_Fault;
    UINT8                COM_Fault___CHC_Display_Interface;
    UINT8                CP_Reset_Fault;
    UINT8                CP_Boot_Fault;
    CHAR                 CP_Software_Part_Number[20];
    UINT16               CP_Software_Part_ID;
    CHAR                 CP_Hardware_Part_Number[20];
    UINT16               CP_Hardware_Part_ID;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_CHC_Display_BIT_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CHADS_Operational;
    UINT8                CHADS_Active;
    UINT8                CHADS_Armed;
    UINT16               SPDA_State;
    UINT16               Current_Aerial_Delivery_Event;
    UINT8                WOW;
    UINT8                ADS_OK;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_System_Status_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               ADS_Lock_Left_1;
    UINT16               ADS_Lock_Left_2;
    UINT16               ADS_Lock_Left_3;
    UINT16               ADS_Lock_Left_4;
    UINT16               ADS_Lock_Left_5;
    UINT16               ADS_Lock_Left_6;
    UINT16               ADS_Lock_Left_7;
    UINT16               ADS_Lock_Left_8;
    UINT16               ADS_Lock_Left_9;
    UINT16               ADS_Lock_Left_10;
    UINT16               ADS_Lock_Left_11;
    UINT16               ADS_Lock_Left_12;
    UINT16               ADS_Lock_Right_1;
    UINT16               ADS_Lock_Right_2;
    UINT16               ADS_Lock_Right_3;
    UINT16               ADS_Lock_Right_4;
    UINT16               ADS_Lock_Right_5;
    UINT16               ADS_Lock_Right_6;
    UINT16               ADS_Lock_Right_7;
    UINT16               ADS_Lock_Right_8;
    UINT16               ADS_Lock_Right_9;
    UINT16               ADS_Lock_Right_10;
    UINT16               ADS_Lock_Right_11;
    UINT16               ADS_Lock_Right_12;
    UINT16               Logistic_Lock_Left_13;
    UINT16               Logistic_Lock_Left_14;
    UINT16               Logistic_Lock_Left_15;
    UINT16               Logistic_Lock_Left_16;
    UINT16               Logistic_Lock_Right_13;
    UINT16               Logistic_Lock_Right_14;
    UINT16               Logistic_Lock_Right_15;
    UINT16               Logistic_Lock_Right_16;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Lock_Status_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CRG_Left_1;
    UINT8                CRG_Left_2;
    UINT8                CRG_Left_3;
    UINT8                CRG_Left_4;
    UINT8                CRG_Left_5_Ramp;
    UINT8                CRG_Left_6_Ramp;
    UINT8                CRG_Right_1;
    UINT8                CRG_Right_2;
    UINT8                CRG_Right_3;
    UINT8                CRG_Right_4;
    UINT8                Left_PDM_Fault;
    UINT8                Right_PDM_Fault;
    UINT8                Left_PDM_Present;
    UINT8                Right_PDM_Present;
    UINT8                Left_PDM_Stowed;
    UINT8                Right_PDM_Stowed;
    UINT8                Towplate_Fault;
    UINT8                Towplate_Solenoid_1_Present;
    UINT8                Towplate_Solenoid_2_Present;
    UINT8                Towplate_Link_LOCK_Status;
    UINT8                Towplate_Jettison_Status;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Device_Status_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CHC_C_Fault;
    UINT8                CHC_M_Fault;
    UINT8                CHC_D_Fault;
    UINT8                CHC_VP_Fault;
    UINT8                LCP_1_Fault;
    UINT8                LCP_2_Fault;
    UINT8                LCP_3_Fault;
    UINT8                LCP_4_Fault;
    UINT8                LCP_5_Fault;
    UINT8                LCP_6_Fault;
    UINT8                RCP_Fault;
    UINT16               LCU_Left_1_Fault;
    UINT16               LCU_Left_2_Fault;
    UINT16               LCU_Left_3_Fault;
    UINT16               LCU_Left_4_Fault;
    UINT16               LCU_Left_5_Fault;
    UINT16               LCU_Left_6_Fault;
    UINT16               LCU_Left_7_Fault_Ramp;
    UINT16               LCU_Left_8_Fault_Ramp;
    UINT16               LCU_Right_1_Fault;
    UINT16               LCU_Right_2_Fault;
    UINT16               LCU_Right_3_Fault;
    UINT16               LCU_Right_4_Fault;
    UINT16               LCU_Right_5_Fault;
    UINT16               LCU_Right_6_Fault;
    UINT16               LCU_Right_7_Fault_Ramp;
    UINT16               LCU_Right_8_Fault_Ramp;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LRU_Status_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               ACTIVE_SAFE;
    UINT8                CHC_RED;
    UINT8                CHC_RED_Command;
    UINT8                CHC_RED_Monitor;
    UINT8                ARM;
    UINT8                CHC_YELLOW;
    UINT8                CHC_YELLOW_Command;
    UINT8                CHC_YELLOW_Monitor;
    UINT8                CHC_GREEN;
    UINT8                CHC_GREEN_Command;
    UINT8                CHC_GREEN_Monitor;
    UINT8                Master_Alert;
    UINT8                CHC_Drogue_Jettison;
    UINT8                CHC_Drogue_Jettison_Command;
    UINT8                CHC_Drogue_Jettison_Monitor;
    UINT8                CHC_Cargo_Jettison;
    UINT8                CHC_Cargo_Jettison_Command;
    UINT8                CHC_Cargo_Jettison_Monitor;
    UINT8                CHADS_Electrical_Override;
    UINT8                ADP_LOCAL_REMOTE;
    UINT8                ADP_RED;
    UINT8                ADP_RED_Command;
    UINT8                ADP_RED_Monitor;
    UINT8                ADP_YELLOW;
    UINT8                ADP_YELLOW_Command;
    UINT8                ADP_YELLOW_Monitor;
    UINT8                ADP_GREEN;
    UINT8                ADP_GREEN_Command;
    UINT8                ADP_GREEN_Monitor;
    UINT8                ADP_Drogue_Jettison;
    UINT8                ADP_Drogue_Jettison_Command;
    UINT8                ADP_Drogue_Jettison_Monitor;
    UINT8                Mission_Computer_RED;
    UINT8                Mission_Computer_YELLOW;
    UINT8                Mission_Computer_GREEN;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Commands_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Event_Count;
    T_Event_Data        * Event_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Event_Data_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Cargo_Type;
    UINT16               Pallet_Platform_Count;
    UINT16               Logistic_Count;
    UINT16               CDS_Count;
    UINT8                Buffer_Stop;
    UINT16               Buffer_Stop_Forward_Lock_Pair;
    T_Pallet_Platform_Data_Fields* Pallet_Platform_Data;
    T_CDS_Data_Fields   * CDS_Data;
    T_Logistic_Data_Fields* Logistic_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Cargo_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Event_Sequence;
    UINT16               Lock_Count;
    UINT16               Expected_Force;
    T_Lock_Force_Data   * Lock_Force_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Release_Force_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Lock_Number;
    UINT16               Lock_Side;
    UINT16               Lock_State;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Lock_State_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               PDM;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_PDM_State_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Open_Link;
    UINT8                Close_Link;
    UINT8                Jettison;
    UINT8                Reset_Jettison;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_Towplate_State_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Position;
    UINT16               Operation;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Set_CRG_State_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CHC_M_BIT_Included;
    UINT16               Left_Lock_BIT;
    UINT16               Right_Lock_BIT;
    UINT8                CHC_Serial_Switch_Command;
    UINT16               CHC_Serial_Switch_State;
    UINT8                Force_Comparison_Command;
    UINT8                LCU_Serial_Switch_Command;
    UINT16               LCU_Actuator_Serial_Switch_State;
    UINT16               LCU_Solenoid_Serial_Switch_State;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Monitor_BIT_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Overall_BIT_Passed;
    UINT8                CHC_M_BIT_Passed;
    UINT8                AC_Input_Power_BIT_Fault;
    UINT8                DC_Output_Power_BIT_Fault;
    UINT8                DC_Point_of_Load_Power_BIT_Fault;
    UINT8                CHC_Serial_Switch_Status_BIT_Fault;
    UINT8                Aircraft_Bus_BIT_Fault___Primary_Mission_Computer;
    UINT8                Aircraft_Bus_BIT_Fault___Backup_Mission_Computer;
    UINT8                COM_Fault___CHC_Command_Interface;
    UINT8                COM_Fault___LCU_Left_Interface;
    UINT8                COM_Fault___LCU_Right_Interface;
    UINT8                Reset_Fault;
    CHAR                 Software_Part_Number[20];
    UINT16               Software_Part_ID;
    CHAR                 Hardware_Part_Number[20];
    UINT16               Hardware_Part_ID;
    UINT16               LCU_Count;
    T_LCU_Bit_Data      * LCU_Bit_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Monitor_BIT_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                WOW;
    UINT8                ADS_OK;
    UINT8                CHC_Enable_Switch;
    UINT8                CHC_RED_Button;
    UINT8                CHC_ARM_Button;
    UINT8                CHC_YELLOW_Button;
    UINT8                CHC_GREEN_Button;
    UINT8                CHC_Drogue_Jettison_Button;
    UINT8                CHC_Cargo_Jettison_Switch;
    UINT16               ADP_Local_Remote_Switch;
    UINT8                ADP_RED_Button;
    UINT8                ADP_ARM_Button;
    UINT8                ADP_YELLOW_Button;
    UINT8                ADP_GREEN_Button;
    UINT8                ADP_Drogue_Jettison_Button;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Command_Status_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                CHC_M_BIT_Passed;
    UINT16               LCU_BIT;
    UINT8                WOW;
    UINT8                ADS_OK;
    UINT16               CHC_Enable_Switch;
    UINT8                CHC_RED_Button;
    UINT8                CHC_ARM_Button;
    UINT8                CHC_YELLOW_Button;
    UINT8                CHC_GREEN_Button;
    UINT8                CHC_Drogue_Jettison_Button;
    UINT8                CHC_Cargo_Jettison_Switch;
    UINT16               ADP_Local_Remote_Switch;
    UINT8                ADP_RED_Button;
    UINT8                ADP_ARM_Button;
    UINT8                ADP_YELLOW_Button;
    UINT8                ADP_GREEN_Button;
    UINT8                ADP_Drogue_Jettison_Button;
    UINT8                Left_PDM_Solenoid_Continuity;
    UINT8                Left_PDM_Deployed;
    UINT8                Right_PDM_Solenoid_Continuity;
    UINT8                Right_PDM_Deployed;
    UINT8                Towplate_Primary_Solenoid_Continuity;
    UINT8                Towplate_Secondary_Solenoid_Continuity;
    UINT8                Towplate_Drogue_Link_Latch_State;
    UINT8                Towplate_Jettison_Actuator_Extended;
    UINT8                Towplate_Jettison_Actuator_Retracted;
    UINT8                CRG_Present;
    T_Lock_Status_Data   Lock_Status_Data[32];
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Monitor_Status_Periodic_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    T_Mission_Parameter_Event Event_Variant;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Mission_Parameter_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_Status_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                BIT_Passed;
    UINT16               Lock_Sensor_Count;
    T_Lock_Sensor_Data  * Lock_Sensor_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_Status_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Lock_1_Actuator_Serial_Switch_IBIT;
    UINT8                Lock_2_Actuator_Serial_Switch_IBIT;
    UINT16               Lock_1_Actuator_Serial_Switch_State;
    UINT16               Lock_2_Actuator_Serial_Switch_State;
    UINT8                Lock_1_Solenoid_Serial_Switch_IBIT;
    UINT8                Lock_2_Solenoid_Serial_Switch_IBIT;
    UINT16               Lock_1_Solenoid_Serial_Switch_State;
    UINT16               Lock_2_Solenoid_Serial_Switch_State;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_BIT_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Overall_BIT_Passed;
    UINT8                Actuator_Extended;
    UINT8                Actuator_Retracted;
    UINT8                Capacitor_Charge_Disable;
    UINT8                Capacitor_Charge_State;
    UINT16               Actuator_Current;
    UINT16               Lock_Dog_Location_Sensor;
    UINT16               Lock_Dog_Displacement_Force_Sensor;
    UINT16               ADS_Trigger_Location_Sensor;
    UINT8                LCU_Point_of_Load_Power_Fault;
    UINT8                Actuator_Power_Enable_Serial_Switch_Fault;
    UINT8                Actuator_Extend_Serial_Switch_Fault;
    UINT8                Actuator_Retract_Serial_Switch_Fault;
    UINT8                Capacitor_Charge_Fault;
    UINT8                Reset_Fault;
    UINT8                Communications_Fault;
    UINT16               Actuator_Serial_Switch_State;
    UINT16               Solenoid_Serial_Switch_State;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_BIT_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Lock_1_State;
    UINT16               Lock_2_State;
    UINT16               Lock_3_State;
    UINT16               Lock_4_State;
    UINT16               Lock_5_State;
    UINT16               Lock_6_State;
    UINT16               Lock_7_State;
    UINT16               Lock_8_State;
    UINT16               Lock_9_State;
    UINT16               Lock_10_State;
    UINT16               Lock_11_State;
    UINT16               Lock_12_State;
    UINT16               Lock_13_State;
    UINT16               Lock_14_State;
    UINT16               Lock_15_State;
    UINT16               Lock_16_State;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_Set_Lock_State_Command_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_Force_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               Lock_1_Dog_Displacement_Force_Sensor;
    UINT16               Lock_2_Dog_Displacement_Force_Sensor;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_LCU_Force_Response_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    T_Field_Load_Variant Subformat_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_SOFTWARE_FIELD_LOAD_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT8                Transmit_Data;
    UINT8                Tx_ARINC_Data;
    UINT8                Rx_ARINC_Data;
    UINT8                CHADS_Message_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Maintenance_Data_Request_Message;
typedef struct {
    UINT16               Sync;
    UINT16               Message_ID;
    UINT16               Source_ID;
    UINT16               Dest_ID;
    UINT16               Word_Count;
    UINT16               ARINC_Message_Count;
    T_Bit_32_Data       * ARINC_Message_32_Bit_Data;
    UINT16               Packet_ID_Seq;
    UINT16               Header_CR;
} T_Maintenance_Data_ARINC_Periodic_Message;
/* -- Prototypes -- */
UINT16 Pack_T_Acknowledge_Message(BYTE buffer[], const UINT16 buffer_max, T_Acknowledge_Message* data);
UINT16 Unpack_T_Acknowledge_Message(BYTE buffer[], const UINT16 buffer_max, T_Acknowledge_Message* data);
UINT16 Pack_T_Ping_Message(BYTE buffer[], const UINT16 buffer_max, T_Ping_Message* data);
UINT16 Unpack_T_Ping_Message(BYTE buffer[], const UINT16 buffer_max, T_Ping_Message* data);
UINT16 Pack_T_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Request_Message* data);
UINT16 Unpack_T_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Request_Message* data);
UINT16 Pack_T_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Response_Message* data);
UINT16 Unpack_T_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_BIT_Response_Message* data);
UINT16 Pack_T_Control_Panel_State_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Request_Message* data);
UINT16 Unpack_T_Control_Panel_State_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Request_Message* data);
UINT16 Pack_T_Control_Panel_State_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Response_Message* data);
UINT16 Unpack_T_Control_Panel_State_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_State_Response_Message* data);
UINT16 Pack_T_Control_Panel_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Request_Message* data);
UINT16 Unpack_T_Control_Panel_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Request_Message* data);
UINT16 Pack_T_Control_Panel_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Response_Message* data);
UINT16 Unpack_T_Control_Panel_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_BIT_Response_Message* data);
UINT16 Pack_T_Display_Configuration_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Display_Configuration_Command_Message* data);
UINT16 Unpack_T_Display_Configuration_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Display_Configuration_Command_Message* data);
UINT16 Pack_T_Set_LCAS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_LCAS_Command_Message* data);
UINT16 Unpack_T_Set_LCAS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_LCAS_Command_Message* data);
UINT16 Pack_T_LCAS_Message_Data(BYTE buffer[], const UINT16 buffer_max, T_LCAS_Message_Data* data);
UINT16 Unpack_T_LCAS_Message_Data(BYTE buffer[], const UINT16 buffer_max, T_LCAS_Message_Data* data);
UINT16 Pack_T_Set_SPDU_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_SPDU_Command_Message* data);
UINT16 Unpack_T_Set_SPDU_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_SPDU_Command_Message* data);
UINT16 Pack_T_Set_Event_Text_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Event_Text_Command_Message* data);
UINT16 Unpack_T_Set_Event_Text_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Event_Text_Command_Message* data);
UINT16 Pack_T_Set_Main_Selection_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Main_Selection_Command_Message* data);
UINT16 Unpack_T_Set_Main_Selection_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Main_Selection_Command_Message* data);
UINT16 Pack_T_Update_Window_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Update_Window_Command_Message* data);
UINT16 Unpack_T_Update_Window_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Update_Window_Command_Message* data);
UINT16 Pack_T_Field_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Data* data);
UINT16 Unpack_T_Field_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Data* data);
UINT16 Pack_T_Show_Dialog_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Show_Dialog_Command_Message* data);
UINT16 Unpack_T_Show_Dialog_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Show_Dialog_Command_Message* data);
UINT16 Pack_T_Set_Mode_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Mode_Command_Message* data);
UINT16 Unpack_T_Set_Mode_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Mode_Command_Message* data);
UINT16 Pack_T_Add_Pallet_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Pallet_Command_Message* data);
UINT16 Unpack_T_Add_Pallet_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Pallet_Command_Message* data);
UINT16 Pack_T_Pallet_Data(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Data* data);
UINT16 Unpack_T_Pallet_Data(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Data* data);
UINT16 Pack_T_Add_Platform_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Platform_Command_Message* data);
UINT16 Unpack_T_Add_Platform_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Platform_Command_Message* data);
UINT16 Pack_T_Platform_Data(BYTE buffer[], const UINT16 buffer_max, T_Platform_Data* data);
UINT16 Unpack_T_Platform_Data(BYTE buffer[], const UINT16 buffer_max, T_Platform_Data* data);
UINT16 Pack_T_Add_CDS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_CDS_Command_Message* data);
UINT16 Unpack_T_Add_CDS_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_CDS_Command_Message* data);
UINT16 Pack_T_Bundle_Data(BYTE buffer[], const UINT16 buffer_max, T_Bundle_Data* data);
UINT16 Unpack_T_Bundle_Data(BYTE buffer[], const UINT16 buffer_max, T_Bundle_Data* data);
UINT16 Pack_T_Add_Logistics_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Logistics_Command_Message* data);
UINT16 Unpack_T_Add_Logistics_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Logistics_Command_Message* data);
UINT16 Pack_T_Delete_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Cargo_Command_Message* data);
UINT16 Unpack_T_Delete_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Cargo_Command_Message* data);
UINT16 Pack_T_Add_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Buffer_Stop_Command_Message* data);
UINT16 Unpack_T_Add_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Buffer_Stop_Command_Message* data);
UINT16 Pack_T_Delete_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Buffer_Stop_Command_Message* data);
UINT16 Unpack_T_Delete_Buffer_Stop_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Buffer_Stop_Command_Message* data);
UINT16 Pack_T_Set_Lock_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_Icons_Command_Message* data);
UINT16 Unpack_T_Set_Lock_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_Icons_Command_Message* data);
UINT16 Pack_T_Set_CRG_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_Icons_Command_Message* data);
UINT16 Unpack_T_Set_CRG_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_Icons_Command_Message* data);
UINT16 Pack_T_Set_PDM_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_Icons_Command_Message* data);
UINT16 Unpack_T_Set_PDM_Icons_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_Icons_Command_Message* data);
UINT16 Pack_T_Set_Towplate_Icon_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_Icon_Command_Message* data);
UINT16 Unpack_T_Set_Towplate_Icon_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_Icon_Command_Message* data);
UINT16 Pack_T_Highlight_Button_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Button_Command_Message* data);
UINT16 Unpack_T_Highlight_Button_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Button_Command_Message* data);
UINT16 Pack_T_Highlight_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Command_Message* data);
UINT16 Unpack_T_Highlight_Cargo_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Command_Message* data);
UINT16 Pack_T_Highlight_Cargo_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Data* data);
UINT16 Unpack_T_Highlight_Cargo_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Cargo_Data* data);
UINT16 Pack_T_Highlight_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Command_Message* data);
UINT16 Unpack_T_Highlight_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Command_Message* data);
UINT16 Pack_T_Highlight_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Data* data);
UINT16 Unpack_T_Highlight_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Highlight_Event_Data* data);
UINT16 Pack_T_Add_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Event_Command_Message* data);
UINT16 Unpack_T_Add_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Add_Event_Command_Message* data);
UINT16 Pack_T_Delete_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Event_Command_Message* data);
UINT16 Unpack_T_Delete_Event_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Delete_Event_Command_Message* data);
UINT16 Pack_T_Control_Panel_Button_Press_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_Button_Press_Message* data);
UINT16 Unpack_T_Control_Panel_Button_Press_Message(BYTE buffer[], const UINT16 buffer_max, T_Control_Panel_Button_Press_Message* data);
UINT16 Pack_T_CHC_Display_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Request_Message* data);
UINT16 Unpack_T_CHC_Display_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Request_Message* data);
UINT16 Pack_T_CHC_Display_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Response_Message* data);
UINT16 Unpack_T_CHC_Display_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_CHC_Display_BIT_Response_Message* data);
UINT16 Pack_T_System_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_System_Status_Periodic_Message* data);
UINT16 Unpack_T_System_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_System_Status_Periodic_Message* data);
UINT16 Pack_T_Lock_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Periodic_Message* data);
UINT16 Unpack_T_Lock_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Periodic_Message* data);
UINT16 Pack_T_Device_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Device_Status_Periodic_Message* data);
UINT16 Unpack_T_Device_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Device_Status_Periodic_Message* data);
UINT16 Pack_T_LRU_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_LRU_Status_Periodic_Message* data);
UINT16 Unpack_T_LRU_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_LRU_Status_Periodic_Message* data);
UINT16 Pack_T_Commands_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Commands_Periodic_Message* data);
UINT16 Unpack_T_Commands_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Commands_Periodic_Message* data);
UINT16 Pack_T_Event_Data_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Periodic_Message* data);
UINT16 Unpack_T_Event_Data_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Periodic_Message* data);
UINT16 Pack_T_Event_Data_Variant(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Variant* data);
UINT16 Unpack_T_Event_Data_Variant(BYTE buffer[], const UINT16 buffer_max, T_Event_Data_Variant* data);
UINT16 Pack_T_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Event_Data* data);
UINT16 Unpack_T_Event_Data(BYTE buffer[], const UINT16 buffer_max, T_Event_Data* data);
UINT16 Pack_T_LVAD_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Event* data);
UINT16 Unpack_T_LVAD_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Event* data);
UINT16 Pack_T_LAPES_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Event* data);
UINT16 Unpack_T_LAPES_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Event* data);
UINT16 Pack_T_CDS_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Event* data);
UINT16 Unpack_T_CDS_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Event* data);
UINT16 Pack_T_Combat_Offload_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Event* data);
UINT16 Unpack_T_Combat_Offload_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Event* data);
UINT16 Pack_T_Cargo_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Cargo_Periodic_Message* data);
UINT16 Unpack_T_Cargo_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Cargo_Periodic_Message* data);
UINT16 Pack_T_Pallet_Platform_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Platform_Data_Fields* data);
UINT16 Unpack_T_Pallet_Platform_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Pallet_Platform_Data_Fields* data);
UINT16 Pack_T_CDS_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_CDS_Data_Fields* data);
UINT16 Unpack_T_CDS_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_CDS_Data_Fields* data);
UINT16 Pack_T_Logistic_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Logistic_Data_Fields* data);
UINT16 Unpack_T_Logistic_Data_Fields(BYTE buffer[], const UINT16 buffer_max, T_Logistic_Data_Fields* data);
UINT16 Pack_T_Release_Force_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Release_Force_Periodic_Message* data);
UINT16 Unpack_T_Release_Force_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Release_Force_Periodic_Message* data);
UINT16 Pack_T_Lock_Force_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Force_Data* data);
UINT16 Unpack_T_Lock_Force_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Force_Data* data);
UINT16 Pack_T_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_State_Command_Message* data);
UINT16 Unpack_T_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Lock_State_Command_Message* data);
UINT16 Pack_T_Set_PDM_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_State_Command_Message* data);
UINT16 Unpack_T_Set_PDM_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_PDM_State_Command_Message* data);
UINT16 Pack_T_Set_Towplate_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_State_Command_Message* data);
UINT16 Unpack_T_Set_Towplate_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_Towplate_State_Command_Message* data);
UINT16 Pack_T_Set_CRG_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_State_Command_Message* data);
UINT16 Unpack_T_Set_CRG_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Set_CRG_State_Command_Message* data);
UINT16 Pack_T_Monitor_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Request_Message* data);
UINT16 Unpack_T_Monitor_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Request_Message* data);
UINT16 Pack_T_Monitor_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Response_Message* data);
UINT16 Unpack_T_Monitor_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_BIT_Response_Message* data);
UINT16 Pack_T_LCU_Bit_Data(BYTE buffer[], const UINT16 buffer_max, T_LCU_Bit_Data* data);
UINT16 Unpack_T_LCU_Bit_Data(BYTE buffer[], const UINT16 buffer_max, T_LCU_Bit_Data* data);
UINT16 Pack_T_Command_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Command_Status_Periodic_Message* data);
UINT16 Unpack_T_Command_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Command_Status_Periodic_Message* data);
UINT16 Pack_T_Monitor_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_Status_Periodic_Message* data);
UINT16 Unpack_T_Monitor_Status_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Monitor_Status_Periodic_Message* data);
UINT16 Pack_T_Lock_Status_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Data* data);
UINT16 Unpack_T_Lock_Status_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Status_Data* data);
UINT16 Pack_T_Mission_Parameter_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Command_Message* data);
UINT16 Unpack_T_Mission_Parameter_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Command_Message* data);
UINT16 Pack_T_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Event* data);
UINT16 Unpack_T_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Mission_Parameter_Event* data);
UINT16 Pack_T_LVAD_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Mission_Parameter_Event* data);
UINT16 Unpack_T_LVAD_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LVAD_Mission_Parameter_Event* data);
UINT16 Pack_T_LAPES_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Mission_Parameter_Event* data);
UINT16 Unpack_T_LAPES_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_LAPES_Mission_Parameter_Event* data);
UINT16 Pack_T_Combat_Offload_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Mission_Parameter_Event* data);
UINT16 Unpack_T_Combat_Offload_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_Combat_Offload_Mission_Parameter_Event* data);
UINT16 Pack_T_CDS_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Mission_Parameter_Event* data);
UINT16 Unpack_T_CDS_Mission_Parameter_Event(BYTE buffer[], const UINT16 buffer_max, T_CDS_Mission_Parameter_Event* data);
UINT16 Pack_T_LCU_Status_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Request_Message* data);
UINT16 Unpack_T_LCU_Status_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Request_Message* data);
UINT16 Pack_T_LCU_Status_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Response_Message* data);
UINT16 Unpack_T_LCU_Status_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Status_Response_Message* data);
UINT16 Pack_T_Lock_Sensor_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Sensor_Data* data);
UINT16 Unpack_T_Lock_Sensor_Data(BYTE buffer[], const UINT16 buffer_max, T_Lock_Sensor_Data* data);
UINT16 Pack_T_LCU_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Request_Message* data);
UINT16 Unpack_T_LCU_BIT_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Request_Message* data);
UINT16 Pack_T_LCU_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Response_Message* data);
UINT16 Unpack_T_LCU_BIT_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_BIT_Response_Message* data);
UINT16 Pack_T_LCU_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Set_Lock_State_Command_Message* data);
UINT16 Unpack_T_LCU_Set_Lock_State_Command_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Set_Lock_State_Command_Message* data);
UINT16 Pack_T_LCU_Force_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Request_Message* data);
UINT16 Unpack_T_LCU_Force_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Request_Message* data);
UINT16 Pack_T_LCU_Force_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Response_Message* data);
UINT16 Unpack_T_LCU_Force_Response_Message(BYTE buffer[], const UINT16 buffer_max, T_LCU_Force_Response_Message* data);
UINT16 Pack_T_Bit_64_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_64_Data* data);
UINT16 Unpack_T_Bit_64_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_64_Data* data);
UINT16 Pack_T_Bit_32_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_32_Data* data);
UINT16 Unpack_T_Bit_32_Data(BYTE buffer[], const UINT16 buffer_max, T_Bit_32_Data* data);
UINT16 Pack_T_SOFTWARE_FIELD_LOAD_Message(BYTE buffer[], const UINT16 buffer_max, T_SOFTWARE_FIELD_LOAD_Message* data);
UINT16 Unpack_T_SOFTWARE_FIELD_LOAD_Message(BYTE buffer[], const UINT16 buffer_max, T_SOFTWARE_FIELD_LOAD_Message* data);
UINT16 Pack_T_Field_Load_Variant(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Variant* data);
UINT16 Unpack_T_Field_Load_Variant(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Variant* data);
UINT16 Pack_T_Field_Load_Request(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Request* data);
UINT16 Unpack_T_Field_Load_Request(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Request* data);
UINT16 Pack_T_Field_Load_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Response* data);
UINT16 Unpack_T_Field_Load_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Response* data);
UINT16 Pack_T_Field_Load_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Data* data);
UINT16 Unpack_T_Field_Load_Data(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Data* data);
UINT16 Pack_T_Field_Load_Complete_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Complete_Response* data);
UINT16 Unpack_T_Field_Load_Complete_Response(BYTE buffer[], const UINT16 buffer_max, T_Field_Load_Complete_Response* data);
UINT16 Pack_T_Maintenance_Data_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_Request_Message* data);
UINT16 Unpack_T_Maintenance_Data_Request_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_Request_Message* data);
UINT16 Pack_T_Maintenance_Data_ARINC_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_ARINC_Periodic_Message* data);
UINT16 Unpack_T_Maintenance_Data_ARINC_Periodic_Message(BYTE buffer[], const UINT16 buffer_max, T_Maintenance_Data_ARINC_Periodic_Message* data);
#endif /* INCLUDED_Gen_Structs_h */
