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
    Animal *a = (&D_801DDD8C[gCurrentAnimalIndex])->unk0;
    return ABS(x - a->xPos) + ABS(z - a->zPos) + ABS(y - a->yPos);
}
