#include "locker_code_base.h"

#ifdef CPU_BIG_ENDIAN
#define G_SWAP_ENDIAN  (0 == 1) // Packed buffers are always big (network) endian.
#else
#define G_SWAP_ENDIAN  (1 == 1) // Packed buffers are always big (network) endian.
#endif 

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
            // Endian swapping is not used for char data.
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
            // Endian swapping is not used for char data.
            buffer[byte_offset++] = value[i++];
        }
        // Force 0-termination even if data buffer filled up.
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
            // Endian swapping is not used for char data.
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
            // Endian swapping is not used for char data.
            value[i++] = buffer[byte_offset++];
        }
        // Force 0-termination even if data buffer filled up.
        value[i] = 0;
    }
    return byte_offset;
}
