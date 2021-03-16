#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80327BE0_739290.s")

void func_80327DA0_739450(void) {
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80327DA8_739458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328258_739908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_803283DC_739A8C.s")

struct025* func_803284C4_739B74(void) {
    struct035 *temp_v1;
    struct025 *temp_v0;

    temp_v1 = D_803D5524;
    temp_v0 = &D_803F28E0[D_803F2A98];
    temp_v0->unk4E = temp_v1->unkCA;
    temp_v0->unk54 = temp_v1->unkD0;
    temp_v0->unk56 = temp_v1->unkD2;
    temp_v0->unk58 = temp_v1->unkCC;
    temp_v0->unk60 = temp_v1->unkCE;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328520_739BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328918_739FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328ACC_73A17C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80329BAC_73B25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80329F44_73B5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032A164_73B814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032A710_73BDC0.s")
// miles away
// void func_8032A710_73BDC0(void) {
//     s16 temp_a0;
//     s16 temp_t0;
//     s16 temp_v0_6;
//     s16 temp_v1;
//     s16 temp_v1_2;
//     s16 temp_v1_3;
//     Animal *temp_a1;
//     struct036 *temp_a2;
//     void *temp_t7;
//     void *temp_t9;
//     void *temp_t9_2;
//     void *temp_v0;
//     Animal *temp_v0_2;
//     s8 *temp_v0_7;
//     Animal *temp_v0_8;
//     s16 phi_v0;
//
//     // temp_v0 = D_803D552C;
//     temp_t0 = D_803D552C->unk30E;
//     D_803D552C->unk320 = 0;
//     func_8032AA94_73C144();
//     temp_a2 = &D_801D9ED8 + temp_t0; // + ( * 8);
//     temp_v0_2 = temp_a2->animal;
//     temp_v1 = temp_v0_2->health;
//     temp_v0_2->health = (s16) D_801D9ED8.animal->health;
//     D_801D9ED8.animal->health = temp_v1;
//     temp_v1_2 = temp_v0_2->skillAEnergy;
//     temp_v0_2->skillAEnergy = (s16) D_801D9ED8.animal->skillAEnergy;
//     D_801D9ED8.animal->skillAEnergy = temp_v1_2;
//     temp_v1_3 = temp_v0_2->skillBEnergy;
//     temp_v0_2->skillBEnergy = (s16) D_801D9ED8.animal->skillBEnergy;
//     D_801D9ED8.animal->skillBEnergy = temp_v1_3;
//     D_801D9ED8.animal->unk4A = (u8)0;
//     temp_a2->animal->unk4A = (u8)0;
//     temp_a1 = D_801D9ED8.animal;
//     temp_a1->unk4F = (u8) (((((u32) (temp_a2->animal->unk4C << 0x1A) >> 0x1F) << 5) & 0x20) | (temp_a1->unk4F & 0xFFDF));
//     temp_v0_2 = temp_a2->animal;
//     temp_v0_2->unk4F = (u8) (((((u32) (temp_a1->unk4C << 0x1A) >> 0x1F) << 5) & 0x20) | (temp_v0_2->unk4F & 0xFFDF));
//     D_803D5520 = &D_801DDD88;
//     D_803D5524 = (s32) D_801D9ED8.unk3EB0;
//     temp_t7 = D_801D9ED8.animal;
//     D_803D5528 = temp_t7;
//     D_803D552C = temp_t7;
//     D_803D5530 = temp_t7;
//     if (gCurrentAnimalIndex == 0) {
//         D_803D5538 = (u8)1;
//     } else {
//         D_803D5538 = (u8)0;
//     }
//     D_803D553C = (u16)0;
//     D_803D553A = (u16)0;
//     D_803D5520 = &D_801DD800;
//     D_803D5530->unk16C = &D_801DD800;
//     gCurrentAnimalIndex = temp_t0;
//     D_803D5520 = (void *) temp_a2->unk3EB0;
//     D_803D5524 = (void *) temp_a2->unk3EB0;
//     temp_t9 = temp_a2->animal;
//     D_803D5528 = temp_t9;
//     D_803D552C = temp_t9;
//     D_803D5530 = temp_t9;
//     if (temp_t0 == gCurrentAnimalIndex) {
//         D_803D5538 = (u8)1;
//     } else {
//         D_803D5538 = (u8)0;
//     }
//     D_803D553C = temp_t0;
//     D_803D553A = (u16)0;
//     D_803D552C->unk366 = (u8)1;
//     D_803D552C->unk328 = (u16) D_803D5544;
//     D_803D552C->unk36A = (u8)2;
//     D_803D5530->unk163 = (u8) D_801D9ED8.animal->unk163;
//     D_803D5530->unk18C = (u8) D_801D9ED8.animal->unk18C;
//     phi_v0 = (u16)0;
// loop_7:
//     temp_v0_6 = phi_v0 + 1;
//     // (D_803D5530 + phi_v0)->unk18D = (u8) (D_801D9ED8.animal + phi_v0)->unk18D;
//     phi_v0 = temp_v0_6;
//     if ((s32) temp_v0_6 < 4) {
//         goto loop_7;
//     }
//     D_803D5530->unk18C = (u8) D_801D9ED8.animal->unk18C;
//     D_803E9824 = (u16) temp_a2->unk3EB0->unk9C;
//     temp_a0 = (s16) D_803E9824;
//     temp_v0_7 = (temp_a0 * 2) + &D_803A63B0;
//     D_803E9820 = temp_v0_7[0];
//     D_803E9822 = temp_v0_7[1];
//     func_8032ABB8_73C268(temp_a0, &D_803D5538, temp_a2, (u8)1);
//     func_80327DA8_739458();
//     func_803283DC_739A8C();
//     func_802B2EA8_6C4558();
//     func_802C9BA4_6DB254(D_803D5530);
//     D_803D5520 = &D_801DDD88;
//     D_803D5524 = (s32) D_801D9ED8.unk3EB0;
//     temp_t9_2 = D_801D9ED8.animal;
//     D_803D5528 = temp_t9_2;
//     D_803D552C = temp_t9_2;
//     D_803D5530 = temp_t9_2;
//     if (gCurrentAnimalIndex == 0) {
//         D_803D5538 = (u8)1;
//     } else {
//         D_803D5538 = (u8)0;
//     }
//     D_803D553C = (u16)0;
//     D_803D553A = (u16)0;
//     func_8032C360_73DA10(0x28, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos,  D_803D5530->yPos, 1.0f);
// }

void func_8032AA94_73C144(void) {
    func_80321920_732FD0(D_803D552C->unk320, 0, 0);
    D_803D552C->unk320 = 0;
    if (D_803D5530->state == 0xDD) {
        func_802E4AB8_6F6168();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032AAF0_73C1A0.s")
// NON-MATCHING: JUSTREG
// void func_8032AAF0_73C1A0(s16 arg0) {
//     s8  *temp_v1;
//     struct035* ptr;
//
//     ptr = &D_801D9ED8[arg0];
//     D_803D5520->unk0 = ptr;
//     D_803D5530->unk16C = ptr;
//     D_803E9824 = arg0;
//     temp_v1 = &D_803A63B0[D_803E9824 << 1];
//     D_803E9820 = temp_v1[0];
//     D_803E9822 = temp_v1[1];
//     func_80327DA8_739458(&D_803E9824);
//     D_803D5530->unk46 = D_803D5530->unk16C->unk7C;
//     func_802C9BA4_6DB254(D_803D5530);
//     D_803D5524 = D_803D5520->unk0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032ABB8_73C268.s")
// void func_8032ABB8_73C268(s16 arg0) {
//     s32 temp_a0;
//     Eeprom *temp_v0;
//
//     if ((D_803E4D28 & 8) == 0) {
//         temp_v0 = &D_8023F260[((s8)(arg0 >> 3))];
//         temp_a0 = 1 << (s8)(arg0 % 7);
//         if (((temp_v0->unk28 & temp_a0) == 0) && (D_803E1BC0 == 0)) {
//             temp_v0->unk28 |= temp_a0;
//             func_8038F694_7A0D44();
//         }
//     }
// }

// same issue as above function
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032AC48_73C2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032AC98_73C348.s")
// void func_8032AC98_73C348(void) {
//     Animal *temp_a0;
//     struct035 *temp_a1;
//     struct036 *temp_v1;
//     s16 i;
//
//     for (i = 0; i < D_803D553E; i++) {
//         temp_v1 = &D_801D9ED8[i];
//         temp_a0 = temp_v1->animal;
//         if (temp_a0 != NULL) {
//             temp_a1 = temp_v1->unk3EB0;
//             if ((temp_a1->unk9C != 0x3E) && (temp_a0->unk366 != 6)) {
//                 D_803D5520 = &temp_v1->unk3EB0;
//                 D_803D5524 = temp_a1;
//                 D_803D552C = temp_a0;
//                 D_803D5528 = temp_a0;
//                 D_803D5530 = temp_a0;
//                 if (gCurrentAnimalIndex == i) {
//                     D_803D5538 = 1;
//                 } else {
//                     D_803D5538 = 0;
//                 }
//                 D_803D553C = i;
//                 D_803D553A = 0;
//                 func_80380620_791CD0(D_803D552C, 2000, 20, 512, 0);
//                 D_803D552C->unk348 = 512;
//                 D_803D552C->unk34A = 512;
//                 D_803D552C->unk36B = 100;
//             }
//         }
//   }
//     if ((D_803A6CE4 & 6) == 0) {
//         D_803A6CE4 |= 2;
//     } else {
//         D_803A6CE4 |= 4;
//     }
// }

// reset or initialise something?
// #pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032AE34_73C4E4.s")
void func_8032AE34_73C4E4(void) {
    struct035 *tmp;
    s16 i;

    for (i = 0; i < 68; i++) { // AID_MAX_ANIMALS
        tmp = &D_801D9ED8.unk0[i];
        tmp->unkDA = 1;
        tmp->unkE0 = 1;
    }
    if ((D_803A6CE4 & 5) == 0) {
        D_803A6CE4 |= 1;
    } else {
        D_803A6CE4 |= 4;
    }
}

void func_8032AEA0_73C550(void) {
    struct035 *tmp;
    s16 i;

    if ((D_803A6CE4 & 8) != 0) {
        func_803421E0_753890(100);
        return;
    }

    for (i = 0; i < 68; i++) {
        tmp = &D_801D9ED8.unk0[i];
        tmp->unkC8 = tmp->unkC8 / 3;
        tmp->unkA4 = tmp->unkA4 / 3;
        tmp->unkAA = tmp->unkAA / 3;
        tmp->unkAC = tmp->unkAC / 3;
        tmp->unkC2 = tmp->unkC2 / 3;
        tmp->unkC4 = tmp->unkC4 / 3;
        tmp->unkD0 = tmp->unkD0 / 2;
        tmp->unkD2 = tmp->unkD2 / 2;
    }

    D_803A6CE4 |= 12;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032B084_73C734.s")
// more of the same nonsense...
// void func_8032B084_73C734(void) {
//     s16 temp_a1;
//     u16 temp_v1;
//     Animal *temp_a0;
//     struct050 *temp_v0;
//
//     temp_a1 = gCurrentAnimalIndex;
//     temp_v0 = &D_801D9ED8.unk0[gCurrentAnimalIndex];
//     temp_a0 = temp_v0->animal;
//     temp_v1 = temp_a0->unk16C->unk0;
//     if (temp_v1 == 278) {
//         D_803D5520->unk0 = &D_801D9ED8.animal;
//         D_803D5524 = D_801D9ED8.animal;
//         D_803D5528 = temp_a0;
//         D_803D552C = temp_a0;
//         D_803D5530 = temp_a0;
//         D_803D5538 = 1;
//         D_803D553C = temp_a1;
//         D_803D553A = 0;
//         func_8032AAF0_73C1A0(24);
//         func_802B2EA8_6C4558();
//         D_803A6CE4 |= 4;
//     } else if (temp_v1 == 280) {
//         // D_803D5520->unk0 = temp_v0->unk3EB0;
//         // D_803D5524 = &temp_v0->unk3EB0;
//         D_803D5528 = temp_a0;
//         D_803D552C = temp_a0;
//         D_803D5530 = temp_a0;
//         D_803D5538 = 1;
//         D_803D553C = temp_a1;
//         D_803D553A = 0;
//         func_8032AAF0_73C1A0(22);
//         func_802B2EA8_6C4558();
//         D_803A6CE4 &= 0xFFFB;
//     } else {
//         func_803421E0_753890(100);
//     }
// }

void func_8032B1C8_73C878(void) {
    D_803A6CE4 &= 0xFFF8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032B1E0_73C890.s")

// check some flag?
u8 func_8032BCF8_73D3A8(s32 arg0, s16 arg1) {
    if (arg1 >= 0) {
        while ((2 << arg1) & arg0) {
            if (--arg1 < 0) {
                break;
            }
        }
    }
    return (arg1 + 1) == 0;
}

s32 func_8032BD5C_73D40C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5) {
    if (arg0 == 0) {
        if ((func_8032BCF8_73D3A8(arg1, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg1 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg2 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg1, arg4) == 0)) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032BE28_73D4D8.s")

void func_8032C0EC_73D79C(s32 arg0, s16 x, s16 y, s16 z, s16 r, s16 g, s16 b) {

    if (D_803D3434->unk38918 < 240) {
        gDPSetPrimColor(D_801D9E8C++, 0, 0, r, g, b, 0xFF);
        guTranslate(&D_803D3434->unk33590[D_803D3434->unk38918], (2.0 * (f32) x) - 30.0, (2.0 * (f32) y) - 30.0, (2.0 * (f32)z) - 32.0);
        gSPMatrix(D_801D9E8C++, &D_803D3434->unk33590[D_803D3434->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        D_803D3434->unk38918 += 1; // used matrices?

        gSPDisplayList(D_801D9E8C++, D_0103B6F0);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}

void func_8032C2D0_73D980(s16 arg0, s16 arg1, f32 arg2) {
    s16 *tmp;

    if (arg0 != 255) {
        tmp = &D_803A69F0[arg0];
        if ((*tmp == 8) || (func_80132D54() < *tmp)) {
            func_8013307C(arg0, 0, arg1, arg2, 64);
        }
    }
}

void func_8032C360_73DA10(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6) {
    s32 sqrt;
    s16 tmp;

    if ((D_803F2D10.unk0 == 0) && (arg0 != 255)) {
        if ((D_803A69F0[arg0] == 8) || (func_80132D54() < D_803A69F0[arg0])) {
            sqrt = sqrtf(((arg3 - (s16) D_803F2C44) * (arg3 - (s16) D_803F2C44)) +
                         ((arg4 - (s16) D_803F2C48) * (arg4 - (s16) D_803F2C48)) +
                         ((arg5 - (s16) D_803F2C4C) * (arg5 - (s16) D_803F2C4C)));
            if (sqrt < D_803A6730[arg0]) {
                tmp = 256 - ((sqrt * 256) / D_803A6730[arg0]);
                func_8013307C(arg0, 0, (tmp * arg1) >> 8, arg6, 64);
            }
        }
    }
}

void func_8032C508_73DBB8(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    if (D_803F2D10.unk0 == 0) {
        if ((D_803A69F0[arg0] == 8) || (func_80132D54() < D_803A69F0[arg0])) {
            if (arg0 != 0xFF) {
                func_8013307C(arg0, 0, arg1, arg3, 64);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032C5A8_73DC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032CA90_73E140.s")

void func_8032CD20_73E3D0(s32 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    if (arg1 != 0xFF) {
        func_8013328C(arg0, arg1, 64, arg4, arg2, arg3);
    }
}

void func_8032CD70_73E420(s32 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, s16 arg5, s16 arg6, s16 arg7) {
    s16 tmp;
    s32 sqrt;

    if (arg1 != 0xFF) {
        sqrt = sqrtf(((arg5 - (s16) D_803F2C44) * (arg5 - (s16) D_803F2C44)) +
                     ((arg6 - (s16) D_803F2C48) * (arg6 - (s16) D_803F2C48)) +
                     ((arg7 - (s16) D_803F2C4C) * (arg7 - (s16) D_803F2C4C)));
        if (sqrt < D_803A6730[arg1]) {
            tmp = 256 - ((sqrt * 256) / D_803A6730[arg1]);
            // fakematch? or just a typo?
            sqrt = (tmp * arg2) >> 8;
            sqrt = (tmp * arg2) >> 8;
            func_8013328C(arg0, arg1, 64, arg4, sqrt, arg3);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032CED0_73E580.s")
