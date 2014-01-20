#ifndef INCLUDED_locker_core_h
#define INCLUDED_locker_core_h


typedef unsigned char      BYTE;
typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned long      UINT32;
/*typedef unsigned long long UINT64;*/
typedef char               INT8;
typedef short              INT16;
typedef long               INT32;
/*typedef long long          INT64;*/
typedef float              FLOAT32;
/*typedef double             FLOAT64;*/

typedef char               CHAR;
typedef char*              STRING;

extern UINT16 Calculate_CRC16(BYTE* data_p, UINT16 length);

extern UINT16 Pack_Endian_08(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);
extern UINT16 Pack_Endian_16(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);
extern UINT16 Pack_Endian_32(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);
/*extern UINT16 Pack_Endian_64(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);*/
extern UINT16 Pack_Endian_Ch(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value, UINT16 length);
extern UINT16 Pack_Endian_Sz(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);

extern UINT16 Unpack_Endian_08(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);
extern UINT16 Unpack_Endian_16(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);
extern UINT16 Unpack_Endian_32(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);
/*extern UINT16 Unpack_Endian_64(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);*/
extern UINT16 Unpack_Endian_Ch(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value, UINT16 length);
extern UINT16 Unpack_Endian_Sz(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value);

#endif  // INCLUDED_locker_core_h
