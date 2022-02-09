#include <ultra64.h>
#include "common.h"
#include "pp.h"

void func_8037E6DC_78FD8C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4);


void func_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D2E4_78E994(s32 arg0) {
    u8 *nonsense;
    UnpackRNC((RNC_fileptr)nonsense, (u8*)D_800DF220);
}

void func_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D320_78E9D0(s32 arg0, s32 arg1) {
}

void func_8037D32C_78E9DC(s32 arg0, u8 arg1, s32 arg2, u16 arg3, s32 arg4) {
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037D340_78E9F0.s")

// velocity related?
void func_8037D994_78F044(s8 arg0) {
    D_803D554B = arg0;
    D_803D554C = MIN(D_803D554C + 2, 20);
}

void func_8037D9D4_78F084(void) {
    D_803D554C = MIN(D_803D554C + 1, 5);
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037DA08_78F0B8.s")

// some loops
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E1C4_78F874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E6DC_78FD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E9AC_79005C.s")
// 605 away but sqrt etc is not quite right
// Animal *func_8037E9AC_79005C(void) {
//     s32 pad2[4];
//     s16 sp56;
//     s16 sp54;
//     s32 pad[2];
//     s16 xPosDelta, zPosDelta;
//     Animal *ret;
//     s16 temp_f6;
//     s16 temp_lo;
//     s16 phi_v0;
//     s16 phi_v1;
//     s16 phi_s5;
//     s16 phi_v1_3;
//     s16 i;
//
//     s16 xPos;
//     s16 zPos;
//
//
//     ret = NULL;
//     phi_s5 = 0; // best distance?
//
//     xPos = D_803D5530->xPos;
//     zPos = D_803D5530->zPos;
//
//     sp56 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 9;
//     sp54 = D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 9;
//
//     for (i = 0; i < D_803D553E; i++) {
//         if ((D_801D9ED8.animals[i].animal != 0) && (D_801D9ED8.animals[i].unk0->unk9C != 62)) {
//             if ((D_801D9ED8.animals[i].animal->unk366 != 6) && (D_801D9ED8.animals[i].animal->unk366 != 2) && (D_801D9ED8.animals[i].animal->unk366 != 5)) {
//                 if ((D_803D5530 != D_801D9ED8.animals[i].animal) && (func_802EA3E0_6FBA90(D_803D5530->unk16C->unk0, D_801D9ED8.animals[i].animal->unk16C->unk0) != 7)) {
//
//                     Animal *a = D_801D9ED8.animals[i].animal;
//
//                     xPosDelta = xPos - a->xPos;
//                     zPosDelta = zPos - a->zPos;
//
//                     phi_v0 = ABS(xPosDelta);
//                     phi_v1 = ABS(zPosDelta);
//
//                     if ((s16) (MAX(phi_v0, phi_v1) + (MIN(phi_v0, phi_v1) >> 1)) < 0x500) {
//                         temp_f6 = sqrtf((xPosDelta * xPosDelta) + (zPosDelta * zPosDelta));
//                         if (temp_f6 == 0) {
//                             temp_f6 = 1;
//                         }
//                         temp_lo = -((xPosDelta * sp56) + (zPosDelta * sp54)) / temp_f6;
//                         if (temp_lo > 32) {
//                             phi_v1_3 = ((temp_lo * 3) / 4) + 16;
//                         } else {
//                             phi_v1_3 = 0;
//                         }
//                         temp_lo = (s16) (((0x500 - temp_f6) << 6) / 1280) * phi_v1_3;
//                         if (phi_s5 < temp_lo) {
//                             phi_s5 = temp_lo;
//                             ret = a;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//
//     return ret;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037ED1C_7903CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037F07C_79072C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037F6CC_790D7C.s")

//missile model (on animal) disappearing and left-right missile selector function
u8 func_8037FBBC_79126C(void) {
    switch (D_803D5524->unk9C) {
    case RACING_DOG:
    case SKI_HUSKY:
    case WALRUS:
    case HYENA_BIKER:
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
//     s32 phi_a0;
//     s16 tmp;
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
//     tmp = ((D_803D552C->skillAEnergy[phi_a0 * 2] + (D_803D5524->unkDA[1+phi_a0] * 8)) / D_803D5524->unkDA[0+phi_a0]);
//     if (tmp == 1) {
//         if ((D_803D552C->missileScaleLeft == 0) && (D_803D552C->missileScaleRight == 0)) {
//             if (D_803D552C->missileSide == 0) {
//                 D_803D552C->missileScaleRight = 1;
//             } else {
//                 D_803D552C->missileScaleLeft = 1;
//             }
//         }
//     } else if (tmp >= 2) {
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

void func_8037FEDC_79158C(void) {
    s16 i;
    s16 zDist;
    s16 xDist;

    play_sound_effect_at_location(SFX_SHEEP_BAA, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);

    // iterate over all animals in the level
    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != NULL) &&
            (D_801D9ED8.animals[i].unk0->unk9C != EVO_GLITCHY) &&
            (D_801D9ED8.animals[i].animal->unk366 != 6) &&
            (D_801D9ED8.animals[i].animal != D_803D5530) &&
            ((u8)D_801D9ED8.animals[i].animal->unk2A0 == 0) &&
            ((D_801D9ED8.animals[i].unk0->unk9C == SHEEP) || (D_801D9ED8.animals[i].unk0->unk9C == SPRINGY_THINGY))) {
            xDist = ABS(D_801D9ED8.animals[i].animal->xPos - D_803D5530->xPos);
            if (xDist < 200) {
                zDist = ABS(D_801D9ED8.animals[i].animal->zPos - D_803D5530->zPos);
                if (zDist < 200) {
                    if ((D_801D9ED8.animals[i].animal->unk287 == 0) && (D_803D552C->unk28A == 0)) {
                        D_801D9ED8.animals[i].animal->unk287 = 1;
                        if (D_803D5530) {};
                        D_801D9ED8.animals[i].animal->unk288 = (xDist + zDist) >> 3;
                        // swarm? follow?
                        func_80363E88_775538(D_801D9ED8.animals[i].animal, D_803D5530);
                    }
                }
            }
        }
    }
    func_8037E6DC_78FD8C(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 200, 15);
}
