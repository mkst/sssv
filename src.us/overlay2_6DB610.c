#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DB610/func_802C9F60_6DB610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DB610/func_802CA8D4_6DBF84.s")

void func_802CAACC_6DC17C(Animal *arg0, s16 arg1) {
    arg0->yVelocity.w = (arg0->yVelocity.w * 7) / 8;
    arg0->yVelocity.w -= ((arg0->yPos + (arg0->unk42 >> 1)) - arg1) << 10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DB610/func_802CAB20_6DC1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DB610/func_802CB180_6DC830.s")
