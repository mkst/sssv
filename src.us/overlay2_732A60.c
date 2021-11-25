#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803213B0_732A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803215DC_732C8C.s")

Animal *func_803218D8_732F88(Animal *arg0) {
    if (arg0 != 0) {
        D_803D552C->unk324 = arg0->state;
        D_803D552C->unk320 = arg0;
        arg0->state = 30;
        arg0->unk4C.unk25 = 1;
        return arg0;
    }
    return NULL;
}

void func_80321920_732FD0(Animal *arg0, s16 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg0->xVelocity.h = D_803D5530->xVelocity.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8);
        arg0->zVelocity.h = D_803D5530->zVelocity.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8);
        arg0->yVelocity.h = (D_803D5530->yVelocity.h + arg2) - 1;
        arg0->unk4C.unk25 = 1;
        arg0->unk160 = D_803D5530->unk160;
        if (arg0->unk160 != 0) {
            if (((arg0->unk160 == 1) || (arg0->unk160 == 2)) && (D_803C0740_7D1DF0[arg0->xPos >> 6][arg0->zPos >> 6].unk3 == 0)) {
                arg0->unk160 = 0U;
            }
        } else {
            if (D_803C0740_7D1DF0[arg0->xPos >> 6][arg0->zPos >> 6].unk3 != 0) {
                if ((func_80310F58_722608(arg0->xPos, arg0->zPos) >> 0x10) < arg0->yPos) {
                    arg0->unk160 = 2U;
                } else {
                    arg0->unk160 = 1U;
                }
            }
        }

        arg0->state = D_803D552C->unk324;
        D_803D552C->unk320 = 0;

        if (arg0->yRotation < 45) {
            arg0->yRotation = 0;
        } else if (arg0->yRotation < 135) {
            arg0->yRotation = 90;
        } else if (arg0->yRotation < 225) {
            arg0->yRotation = 180;
        } else if (arg0->yRotation < 315) {
            arg0->yRotation = 270;
        } else {
            arg0->yRotation = 0;
        }
        if (arg0->unk16C->unk80.bit == 0) {
            if ((arg0->unk163 & 0x20) == 0) {
                arg0->unk163 &= 0xFFF7;
            }
        }
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80321B70_733220.s")

void func_80321D74_733424(s16 arg0, s16 arg1) {
    Animal *a = D_803D552C->unk320;
    if (a != NULL) {
        a->xPos = D_803D5530->xPos + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->zPos = D_803D5530->zPos + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8);
        a->yPos = D_803D5530->yPos + arg1;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80321E60_733510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322064_733714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_8032225C_73390C.s")

void recoil(s16 arg0) {
    s32 temp_t2 = D_80152C78[(u8)D_803D552C->unk302] >> 7;
    s32 temp_t7 = D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7;

    if (arg0 < 0) {
        D_803D5530->xVelocity.w += temp_t2 << (8 - arg0);
        D_803D5530->zVelocity.w += temp_t7 << (8 - arg0);
    } else {
        D_803D5530->xVelocity.w -= temp_t2 << (arg0 + 8);
        D_803D5530->zVelocity.w -= temp_t7 << (arg0 + 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803224C4_733B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322A58_734108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322D68_734418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80323040_7346F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803233A0_734A50.s")
