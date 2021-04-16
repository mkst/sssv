#include <ultra64.h>
#include "common.h"
#include "pp.h"

void func_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D2E4_78E994(s32 arg0) {
    u8 *nonsense;
    UnpackRNC(nonsense, D_800DF220);
}

void func_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D320_78E9D0(s32 arg0, s32 arg1) {
}

void func_8037D32C_78E9DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037D340_78E9F0.s")

void func_8037D994_78F044(s8 arg0) {
    D_803D554B = arg0;

    if ((D_803D554C + 2) < 20) {
        D_803D554C += 2;
    } else {
        D_803D554C = 20;
    }
}

void func_8037D9D4_78F084(void) {
    if ((D_803D554C + 1) < 5) {
        D_803D554C += 1;
    } else {
        D_803D554C = 5;
      }
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037DA08_78F0B8.s")

// some loops
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E1C4_78F874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E6DC_78FD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E9AC_79005C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037ED1C_7903CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037F07C_79072C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037F6CC_790D7C.s")

//missile model (on animal) disappearing and left-right missile selector function
u8 func_8037FBBC_79126C(void) {
    switch (D_803D5524->unk9C) {
    case RACING_DOG:
    case SKI_HUSKY:
    case WALRUS:
    case BIKER_HYENA:
        if ((D_803D552C->missileScaleLeft == 8) && (D_803D552C->missileScaleRight == 8)) {
            if (D_803D552C->missileSide != 0) {
                D_803D552C->missileSide = 0; // *next* missile should come from right side
                D_803D552C->missileScaleLeft = 0;
            } else {
                D_803D552C->missileSide = 1; // *next* missile should come from left side
                D_803D552C->missileScaleRight = 0;
            }
        } else if (D_803D552C->missileScaleRight < D_803D552C->missileScaleLeft) {
            D_803D552C->missileSide = 0;
            D_803D552C->missileScaleLeft = 0;
        } else {
            D_803D552C->missileSide = 1;
            D_803D552C->missileScaleRight = 0;
        }
        break;
    case FIRE_FOX:
        D_803D552C->missileScaleLeft = 0;
    }

    return D_803D552C->missileSide;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037FCA8_791358.s")
// NON-MATCHING: almost...
// void func_8037FCA8_791358(void) {
//     s16 temp_t8;
//     s32 phi_a0;
//
//     if (D_803D552C->missileScaleLeft != 0) {
//         D_803D552C->missileScaleLeft = MIN(D_803D552C->missileScaleLeft + 1, 8);
//     }
//     if (D_803D552C->missileScaleRight != 0) {
//         D_803D552C->missileScaleRight = MIN(D_803D552C->missileScaleRight + 1, 8);
//     }
//     if (D_803D5524->unk9C == POLAR_TANK) {
//         phi_a0 = 0;
//     } else {
//         phi_a0 = 1;
//     }
//     // this isnt right
//     phi_a0 = (phi_a0 << 2) - phi_a0;
//     temp_t8 = ((D_803D552C->skillAEnergy[phi_a0] + (D_803D5524->unkDA[1] * 8)) / D_803D5524->unkDA[0]);
//     if (temp_t8 == 1) {
//         if ((D_803D552C->missileScaleLeft == 0) && (D_803D552C->missileScaleRight == 0)) {
//             if (D_803D552C->missileSide == 0) {
//                 D_803D552C->missileScaleRight = 1;
//             } else {
//                 D_803D552C->missileScaleLeft = 1;
//             }
//         }
//     } else if (temp_t8 >= 2) {
//         if (D_803D552C->missileScaleLeft == 0) {
//             D_803D552C->missileScaleLeft += 1;
//         }
//         if (D_803D552C->missileScaleRight == 0) {
//             D_803D552C->missileScaleRight += 1;
//         }
//     }
// }

void func_8037FE24_7914D4(void) {
    s16 tmp;

    if (D_803D552C->missileScaleLeft != 0) {
        D_803D552C->missileScaleLeft = MIN(D_803D552C->missileScaleLeft + 1, 8);
    }
    tmp = ((D_803D552C->skillBEnergy[0] + (D_803D5524->unkE0[1] * 8)) / D_803D5524->unkE0[0]);
    if ((tmp > 0) && (D_803D552C->missileScaleLeft == 0)) {
        D_803D552C->missileScaleLeft = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037FEDC_79158C.s")
