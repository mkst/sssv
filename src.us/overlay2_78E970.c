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

u8 func_8037FBBC_79126C(void) {
    switch (D_803D5524->unk9C) {
    case RACING_DOG:
    case SKI_HUSKY:
    case WALRUS:
    case BIKER_HYENA:
        if ((D_803D552C->unk2E8 == 8) && (D_803D552C->unk2E9 == 8)) {
            if (D_803D552C->unk2EA != 0) {
                D_803D552C->unk2EA = 0U;
                D_803D552C->unk2E8 = 0;
            } else {
                D_803D552C->unk2EA = 1U;
                D_803D552C->unk2E9 = 0;
            }
        } else if (D_803D552C->unk2E9 < D_803D552C->unk2E8) {
            D_803D552C->unk2EA = 0U;
            D_803D552C->unk2E8 = 0;
        } else {
            D_803D552C->unk2EA = 1U;
            D_803D552C->unk2E9 = 0;
        }
        break;
    case FIRE_FOX:
        D_803D552C->unk2E8 = 0;
    }

    return D_803D552C->unk2EA;
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037FCA8_791358.s")
// NON-MATCHING: not quite right...
// void func_8037FCA8_791358(void) {
//     s16 temp_t8;
//     struct035 *temp_a2;
//     s32 phi_a0;
//
//     if (D_803D552C->unk2E8 != 0) {
//         D_803D552C->unk2E8 = MIN(D_803D552C->unk2E8 + 1, 8);
//     }
//     if (D_803D552C->unk2E9 != 0) {
//         D_803D552C->unk2E9 = MIN(D_803D552C->unk2E9 + 1, 8);
//     }
//     if (D_803D5524->unk9C == POLAR_TANK) {
//         phi_a0 = 0;
//     } else {
//         phi_a0 = 1;
//     }
//     temp_a2 = &D_803D5524 + (phi_a0 * 3);//((phi_a0 * 4) - phi_a0);
//     temp_t8 = (D_803D552C->skillAEnergy[phi_a0] + (temp_a2->unkDA[1] * 8)) / temp_a2->unkDA[0];
//     if (temp_t8 == 1) {
//         if ((D_803D552C->unk2E8 == 0) && (D_803D552C->unk2E9 == 0)) {
//             if (D_803D552C->unk2EA == 0) {
//                 D_803D552C->unk2E9 = 1U;
//             } else {
//                 D_803D552C->unk2E8 = 1U;
//             }
//         }
//     } else if (temp_t8 >= 2) {
//         if (D_803D552C->unk2E8 == 0) {
//             D_803D552C->unk2E8 += 1;
//         }
//         if (D_803D552C->unk2E9 == 0) {
//             D_803D552C->unk2E9 += 1;
//         }
//     }
// }

void func_8037FE24_7914D4(void) {
    s16 tmp;

    if (D_803D552C->unk2E8 != 0) {
        if ((D_803D552C->unk2E8 + 1) < 8) {
            D_803D552C->unk2E8 += 1;
        } else {
            D_803D552C->unk2E8 = 8U;
        }
    }
    tmp = ((D_803D552C->skillBEnergy[0] + (D_803D5524->unkE2 * 8)) / D_803D5524->unkE0);
    if ((tmp > 0) && (D_803D552C->unk2E8 == 0)) {
        D_803D552C->unk2E8 = 1U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037FEDC_79158C.s")
