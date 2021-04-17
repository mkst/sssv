#include <ultra64.h>
#include "common.h"


void func_8029ACB0_6AC360(void) {
}

s32 func_8029ACB8_6AC368(s32 arg0, s32 arg1) {
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029ACC8_6AC378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B000_6AC6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B56C_6ACC1C.s")

s16 func_8029B7D0_6ACE80(s16 x, s16 z, s16 y) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    Animal *temp_v0;
    s32 yDiff;
    s32 xDiff;
    s32 zDiff;

    temp_v0 = (&D_801DDD8C[gCurrentAnimalIndex])->unk0;
    temp_v1 = z - temp_v0->zPos;
    if (temp_v1 < 0) {
        zDiff = -temp_v1;
    } else {
        zDiff = temp_v1;
    }
    temp_v1_2 = x - temp_v0->xPos;    
    if (temp_v1_2 < 0) {
        xDiff = -temp_v1_2;
    } else {
        xDiff = temp_v1_2;
    }
    temp_v1_3 = y - temp_v0->yPos;    
    if (temp_v1_3 < 0) {
        yDiff = -temp_v1_3;
    } else {
      yDiff = temp_v1_3;  
    }
    return yDiff + xDiff + zDiff;
}

