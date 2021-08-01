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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80321920_732FD0.s")

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
