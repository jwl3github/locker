#include "locker_core.h"

#ifdef CPU_BIG_ENDIAN
#define G_SWAP_ENDIAN  (0 == 1) /* Packed buffers are always big (network) endian. */
#else
#define G_SWAP_ENDIAN  (1 == 1) /* Packed buffers are always big (network) endian. */
#endif 

/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
/* -- CRC-16 -- */
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
#define CRC16_POLY 0x8408

UINT16 Calculate_CRC16(BYTE* data_p, UINT16 num_bytes)
{
    /*
                                            16   12   5
       This is the CCITT CRC 16 polynomial X  + X  + X  + 1.
       This works out to be 0x1021, but the way the algorithm works
       lets us use 0x8408 (the reverse of the bit pattern).  The high
       bit is always assumed to be set, thus we only use 16 bits to
       represent the 17 bit value.
    */
    UINT8  i;
    UINT32 data;
    UINT32 crc = 0xffff;

    if (num_bytes == 0) {
        return (~crc);
    }

    for ( ; num_bytes > 0; num_bytes--) {
        data = (UINT32) *data_p; 
        data_p++;
        for (i = 0; i < 8; i++) {
            if ((crc & 0x0001) ^ (data & 0x0001)) {
                crc = (crc >> 1) ^ CRC16_POLY;
            }
            else  {
                crc >>= 1;
            }
            data >>= 1;
        }
    }

    crc = ~crc;
    data = crc;
    crc = (crc << 8) | (data >> 8 & 0xff);

    return (crc);
}

/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
/* -- Pack -- */
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
UINT16 Pack_Endian_08(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT8) - 1) {
            buffer[byte_offset++] = value[0];
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
UINT16 Pack_Endian_16(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT16) - 1) {
            if (G_SWAP_ENDIAN) {
                buffer[byte_offset++] = value[1];
                buffer[byte_offset++] = value[0];
            }
            else {
                buffer[byte_offset++] = value[0];
                buffer[byte_offset++] = value[1];
            }
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
UINT16 Pack_Endian_32(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT32) - 1) {
            if (G_SWAP_ENDIAN) {
                buffer[byte_offset++] = value[3];
                buffer[byte_offset++] = value[2];
                buffer[byte_offset++] = value[1];
                buffer[byte_offset++] = value[0];
            }
            else {
                buffer[byte_offset++] = value[0];
                buffer[byte_offset++] = value[1];
                buffer[byte_offset++] = value[2];
                buffer[byte_offset++] = value[3];
            }
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
/*
UINT16 Pack_Endian_64(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT64) - 1) {
            if (G_SWAP_ENDIAN) {
                buffer[byte_offset++] = value[7];
                buffer[byte_offset++] = value[6];
                buffer[byte_offset++] = value[5];
                buffer[byte_offset++] = value[4];
                buffer[byte_offset++] = value[3];
                buffer[byte_offset++] = value[2];
                buffer[byte_offset++] = value[1];
                buffer[byte_offset++] = value[0];
            }
            else {
                buffer[byte_offset++] = value[0];
                buffer[byte_offset++] = value[1];
                buffer[byte_offset++] = value[2];
                buffer[byte_offset++] = value[3];
                buffer[byte_offset++] = value[4];
                buffer[byte_offset++] = value[5];
                buffer[byte_offset++] = value[6];
                buffer[byte_offset++] = value[7];
            }
        }
    }
    return byte_offset;
}
*/
/* ---------------------------------------------------------------------------- */
UINT16 Pack_Endian_Ch(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value, UINT16 length)
{
    if (value != 0) {
        if (length > buffer_max - byte_offset - 1) {
            length = buffer_max - byte_offset - 1;
        }
        if (byte_offset < buffer_max - length - 1) {
            /* Endian swapping is not used for char data. */
            int i;
            for (i = 0; i < length; i++) {
                buffer[byte_offset++] = value[i];
            }
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
UINT16 Pack_Endian_Sz(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        int i = 0;
        while ((byte_offset < buffer_max - 2) && (value[i] != 0)) {
            /* Endian swapping is not used for char data. */
            buffer[byte_offset++] = value[i++];
        }
        /* Force 0-termination even if data buffer filled up. */
        buffer[byte_offset++] = 0;
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
/* -- Unpack -- */
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
UINT16 Unpack_Endian_08(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT8) - 1) {
            value[0] = buffer[byte_offset++];
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
UINT16 Unpack_Endian_16(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT16) - 1) {
            if (G_SWAP_ENDIAN) {
                value[1] = buffer[byte_offset++];
                value[0] = buffer[byte_offset++];
            }
            else {
                value[0] = buffer[byte_offset++];
                value[1] = buffer[byte_offset++];
            }
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
UINT16 Unpack_Endian_32(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT32) - 1) {
            if (G_SWAP_ENDIAN) {
                value[3] = buffer[byte_offset++];
                value[2] = buffer[byte_offset++];
                value[1] = buffer[byte_offset++];
                value[0] = buffer[byte_offset++];
            }
            else {
                value[0] = buffer[byte_offset++];
                value[1] = buffer[byte_offset++];
                value[2] = buffer[byte_offset++];
                value[3] = buffer[byte_offset++];
            }
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
/*
UINT16 Unpack_Endian_64(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        if (byte_offset < buffer_max - sizeof(INT64) - 1) {
            if (G_SWAP_ENDIAN) {
                value[7] = buffer[byte_offset++];
                value[6] = buffer[byte_offset++];
                value[5] = buffer[byte_offset++];
                value[4] = buffer[byte_offset++];
                value[3] = buffer[byte_offset++];
                value[2] = buffer[byte_offset++];
                value[1] = buffer[byte_offset++];
                value[0] = buffer[byte_offset++];
            }
            else {
                value[0] = buffer[byte_offset++];
                value[1] = buffer[byte_offset++];
                value[2] = buffer[byte_offset++];
                value[3] = buffer[byte_offset++];
                value[4] = buffer[byte_offset++];
                value[5] = buffer[byte_offset++];
                value[6] = buffer[byte_offset++];
                value[7] = buffer[byte_offset++];
            }
        }
    }
    return byte_offset;
}
*/
/* ---------------------------------------------------------------------------- */
UINT16 Unpack_Endian_Ch(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value, UINT16 length)
{
    if (value != 0) {
        if (length > buffer_max - byte_offset - 1) {
            length = buffer_max - byte_offset - 1;
        }
        if (byte_offset < buffer_max - length - 1) {
            /* Endian swapping is not used for char data. */
            int i;
            for (i = 0; i < length; i++) {
                value[i] = buffer[byte_offset++];
            }
        }
    }
    return byte_offset;
}
/* ---------------------------------------------------------------------------- */
UINT16 Unpack_Endian_Sz(BYTE buffer[], const UINT16 buffer_max, UINT16 byte_offset, BYTE* value)
{
    if (value != 0) {
        int i = 0;
        while ((byte_offset < buffer_max - 2) && (buffer[i] != 0)) {
            /* Endian swapping is not used for char data. */
            value[i++] = buffer[byte_offset++];
        }
        /* Force 0-termination even if data buffer filled up. */
        value[i] = 0;
    }
    return byte_offset;
}
