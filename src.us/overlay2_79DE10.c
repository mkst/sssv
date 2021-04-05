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

s16 func_8038CCF0_79E3A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s16 phi_v0;
    if (D_803F6450 == 0) {
        return 0;
    }
    if (D_803D552C->unk318 != 0) {
        return 0;
    }
    if ((D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 3) || ((D_803D552C->unk366 == 4))) {
        if (D_803F2D10.unk0 == 0) {
            if ((D_803D5530->state == 2) || (D_803D5530->state == 21) ||
                (D_803D5530->state == 41) || (D_803D5530->state == 61) ||
                (D_803D5530->state == 81) || (D_803D5530->state == 101) ||
                (D_803D5530->state == 121) || (D_803D5530->state == 141) ||
                (D_803D5530->state == 181) || (D_803D5530->state == 201)) {
                if (D_801546D8 == 0) {
                    if (D_803BFB60 < D_8015517C) {
                        phi_v0 = 400;
                    } else if (D_8015517C > 0.5) {
                        phi_v0 = 200;
                    } else {
                        phi_v0 = 0;
                    }
                } else if (D_801546D8 > 1900) {
                    phi_v0 = 300;
                } else {
                    if (D_801546D8 > 1000) {
                        phi_v0 = 175;
                    } else {
                        phi_v0 = 0;
                    }
                }
                if (((D_803D5544 + ((u16)D_803D552C->unk31C << 6)) & 0x1FF) < phi_v0) {
                    phi_v0 = (arg0 * func_8038CC28_79E2D8()) >> 6;
                    if (arg1 >= 0) {
                        D_80203FE0[arg1].unk4 -= phi_v0;
                    }
                    if (arg2 >= 0) {
                        D_80203FE0[arg2].unk4 -= phi_v0;
                    }
                    if (arg3 >= 0) {
                        D_80203FE0[arg3].unk4 -= phi_v0;
                    }
                    if (arg4 >= 0) {
                        D_80203FE0[arg4].unk4 -= phi_v0;
                    }
                    if (arg5 >= 0) {
                        D_80203FE0[arg5].unk4 -= phi_v0;
                    }
                }
            }
        }
    }
}
