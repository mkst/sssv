#include <ultra64.h>
#include "common.h"


s32 func_802E89F0_6FA0A0(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (func_8029A334_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return 0;
        } else {
            return 4;
        }
    }
    if ((D_803F28DC & 3) != 0) {
        if ((D_803F28DC & 1) != 0) {
            if ((func_802E9B90_6FB240(xPos, zPos, ((D_803F28DC & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
                return 0;
            } else {
                return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
            }
        }
        if ((func_802E9B90_6FB240(((D_803F28DC & 0xFFC) << 0x12) -xPos, zPos, yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return 0;
        } else {
            return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        }
    } else {
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }
}

s32 func_802E8BBC_6FA26C(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (func_8029A334_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return 0;
        } else {
            return 4;
        }
    }
    if ((D_803F28DC & 1) != 0) {
        if ((func_802E9B90_6FB240(xPos, zPos, ((D_803F28DC & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return 0;
        }
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    } else {
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6FA0A0/func_802E8CF4_6FA3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6FA0A0/func_802E9B90_6FB240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6FA0A0/func_802EA004_6FB6B4.s")
