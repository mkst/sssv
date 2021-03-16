#include <ultra64.h>
#include "common.h"


void func_8038C760_79DE10(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79DE10/func_8038C768_79DE18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79DE10/func_8038C98C_79E03C.s")

s16 func_8038CC28_79E2D8(void) {
    return D_803B62D0[((D_80286560 + 3) & 0x3F) >> 1];
}

s16 func_8038CC50_79E300(void) {
    return ((D_80152C78[(u8)((s16)((D_80286560 - 7) << 2) + 64)] >> 7) + 256) / 8;
}

s16 func_8038CCA4_79E354(void) {
    return (D_80286560 + 7) & 0x3F;
}

s16 func_8038CCC0_79E370(void) {
    return ((D_80286560 + 7) & 0x3F) < ((D_80286562 + 7) & 0x3F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79DE10/func_8038CCF0_79E3A0.s")
