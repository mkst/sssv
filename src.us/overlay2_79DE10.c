#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (D_803F6450 to D_803F6460)
// ========================================================

s16  D_803F6450;

// ========================================================
// .text
// ========================================================

void func_8038C760_79DE10(void) {
}

void func_8038C768_79DE18(void) {
    u16 tmp1;
    s16 tmp2;

    tmp1 = D_803D5544 - D_803D552C->unk35E;
    if ((D_803F2D10.unk0 == 0) && ((D_803D5530->unk4A == 0)) && (tmp1 != 0)) {
        if (D_803D5538 != 0) {
            if ((tmp1 & 0xFF) >= 150) {
                if (SSSV_RAND(16) == 13) {
                    D_803D552C->unk314 = func_8012826C() % 360;
                }
            } else {
                D_803D552C->unk314 = 0;
            }
        } else if ((tmp1 & 0xFF) >= 130) {
            D_803D552C->unk314 = ((D_803D552C->heading * 360) >> 8) - func_80128C10(D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.xPos.h, D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.zPos.h, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);
        } else {
            D_803D552C->unk314 = 0;
        }
    } else {
        D_803D552C->unk314 = 0;
    }
    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        D_803D552C->unk314 = 0;
    }

    tmp2 = D_803D552C->unk314 - D_803D552C->unk316;

    while (tmp2 >= 360) {
        tmp2 -= 360;
    }
    while (tmp2 < 0) {
        tmp2 += 360;
    }

    if (tmp2 > 180) {
        D_803D552C->unk316 += MAX(tmp2 - 360, -18);
    } else {
        D_803D552C->unk316 += MIN(tmp2, 18);
    }
    D_803D552C->unk316 %= 360;
}

void func_8038C98C_79E03C(void) {
    u16 tmp1;
    s16 tmp2;

    tmp1 = D_803D5544 - D_803D552C->unk35E;
    if ((D_803F2D10.unk0 == 0) && (D_803D5530->unk4A == 0) && (tmp1 != 0)) {
        if (D_803D5538 != 0) {
            if ((tmp1 & 0xFF) >= 150) {
                if (SSSV_RAND(32) == 13) {
                    D_803D552C->unk314 = (func_8012826C() % 140) - 70;
                    if (D_803D552C->unk314 < 0) {
                        D_803D552C->unk314 += 360;
                    }
                }
            } else {
                D_803D552C->unk314 = 0;
            }
        } else if ((tmp1 & 0xFF) >= 200) {
            D_803D552C->unk314 = ((D_803D552C->heading * 360) >> 8) - func_80128C10(D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.xPos.h, D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.zPos.h, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);

            if (D_803D552C->unk314 > 85) {
                D_803D552C->unk314 = 85;
            }
            if (D_803D552C->unk314 < -85) {
                D_803D552C->unk314 = -85;
            }
        } else {
            D_803D552C->unk314 = 0;
        }
    } else {
        D_803D552C->unk314 = 0;
    }
    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        D_803D552C->unk314 = 0;
    }
    if ((u16)D_803D5528->unk3C0.unk0 != 0) {
        D_803D552C->unk314 = 0;
    }

    tmp2 = D_803D552C->unk314 - D_803D552C->unk316;

    while (tmp2 >= 360) {
        tmp2 -= 360;
    }
    while (tmp2 < 0) {
        tmp2 += 360;
    }

    if (tmp2 > 180) {
        D_803D552C->unk316 += MAX(tmp2 - 360, -8);
    } else {
        D_803D552C->unk316 += MIN(tmp2, 8);
    }
    D_803D552C->unk316 %= 360;
}

s16 func_8038CC28_79E2D8(void) {
    return D_803B62D0[((D_80286560 + 3) & 0x3F) >> 1];
}

s16 func_8038CC50_79E300(void) {
    return ((COS((D_80286560 - 7) << 2) >> 7) + 256) / 8;
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
                    if (D_8015517C > 0.99) {
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
