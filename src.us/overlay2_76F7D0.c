#include <ultra64.h>
#include "common.h"


void func_8035E120_76F7D0(void) {

    D_803D552C->skillAEnergy[0] = MIN(1024, D_803D552C->skillAEnergy[0] + D_803D5524->unkDA[1]);

    if ((D_803D552C->skillAEnergy[1] != 0x7FFF) && (D_803D552C->skillAEnergy[1] != 0x7FFE)) {
        D_803D552C->skillAEnergy[1] = MAX(0, D_803D552C->skillAEnergy[1] - 1);
    }

    // D_803D552C->skillBEnergy[0] = MIN(1024, D_803D552C->skillBEnergy[0] + D_803D5524->unkE2);
    if ((D_803D5524->unkE2 + D_803D552C->skillBEnergy[0]) > (0,1024)) {
        D_803D552C->skillBEnergy[0] = 1024;
    } else {
        D_803D552C->skillBEnergy[0] += D_803D5524->unkE2;
    }

    if ((D_803D552C->skillBEnergy[1] != 0x7FFF) && (D_803D552C->skillBEnergy[1] != 0x7FFE)) {
        D_803D552C->skillBEnergy[1] = MAX(0, D_803D552C->skillBEnergy[1] - 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E200_76F8B0.s")
// void func_8035E200_76F8B0(void) {
//     // void *ret;
//     s16 skillAEnergy;
//     s16 skillBEnergy;
//
//     skillAEnergy = D_803D552C->skillAEnergy[0];
//     if ((skillAEnergy + D_803D5524->unkDC) > (1024)) {
//         D_803D552C->skillAEnergy[0] = 1024;
//     } else {
//         D_803D552C->skillAEnergy[0] += D_803D5524->unkDC;
//     }
//
//     if ((D_803D552C->skillAEnergy[1] != 0x7FFF) && (D_803D552C->skillAEnergy[1] != 0x7FFE)) {
//         if (((D_803D552C->skillAEnergy[1] - 1)) < 0) {
//             D_803D552C->skillAEnergy[1] = 0;
//         } else {
//             D_803D552C->skillAEnergy[1] -= 1;
//         }
//     }
//
//     skillBEnergy = D_803D552C->skillBEnergy[0];
//     if ((skillBEnergy + D_803D5524->unkE2) > 1024) {
//         D_803D552C->skillBEnergy[0] = 1024;
//     } else {
//         D_803D552C->skillBEnergy[0] += D_803D5524->unkE2;
//     }
//     if ((D_803D552C->skillBEnergy[1] != 0x7FFF) && (D_803D552C->skillBEnergy[1] != 0x7FFE)) {
//         if ((D_803D552C->skillBEnergy[1] - 1) < 0) {
//             D_803D552C->skillBEnergy[1] = 0;
//         } else {
//             D_803D552C->skillBEnergy[1] -= 1;
//         }
//     }
//     if ((skillAEnergy < D_803D552C->skillAEnergy[0]) && (D_803D552C->skillAEnergy[0] == 1024)) {
//         // ret = D_803D5524;
//     }
//     if (skillBEnergy < D_803D552C->skillBEnergy[0]) {
//         D_803F2EE0[1] = 0;
//         D_803F2EE0[0] = D_803F2EE0[1];
//         // return;
//     }
//
//     // return ret;
// }

// urghhh
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E344_76F9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E3E8_76FA98.s")
// "JUST" regalloc but likely this is complete balls
// void func_8035E3E8_76FA98(s16 arg0) {
//     D_803D552C->skillAEnergy[arg0 * 2] += D_803D5524->unkDA[arg0 * 3];
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E430_76FAE0.s")

void func_8035F92C_770FDC(void) {
    if (((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) && (D_803D5530->unk6C == 0)) {
        func_802FF0A4_710754(
            D_803D5530->xPos - (((D_80152C78[(u8)(D_803D552C->unk302)] >> 7) * 20) >> 8),
            D_803D5530->zPos - (((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * 20) >> 8),
            D_803D5530->yPos,
            552, 110, D_803D5530, 3, 33);
        func_8032C360_73DA10(156, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    } else {
        func_8035E3E8_76FA98(0);
    }
}

void func_8035FA5C_77110C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 18;
}

void func_8035FA84_771134(void) {
    if ((D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) {
        func_8035FAEC_77119C();
    } else {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 19;
    }
}

void func_8035FAEC_77119C(void) {
    if (D_803D552C->unk365 == 19) {
        D_803D552C->unk365 = 0;
    }
}

void func_8035FB10_7711C0(void) {
    Animal *a;

    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            func_8032C360_73DA10(184, 0x7000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEC10);
            D_803D552C->unk308 = 80;
        } else {
            func_8032C508_73DBB8(16, 0x7000, 0, 1.3f);
            D_803D552C->unk308 = 80;
        }
    }
    a = func_8037E9AC_79005C();
    D_803D552C->unk2CC = a;
    if (a != NULL) {
        D_803D552C->unk2B4.unk4 = 1;
    } else {
        D_803D552C->unk2B4.unk4 = 0;
    }
}

void func_8035FC08_7712B8(void) {
    D_803D552C->unk2B4.unk4 = 0;
    D_803D552C->unk2CC = NULL;
}

void func_8035FC2C_7712DC(void) {
    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) {
        if (D_803D5530->unk6C == 0) {
            func_802FF0A4_710754(
                D_803D5530->xPos - (((D_80152C78[(u8)(D_803D552C->unk302)] >> 7) * 20) >> 8),
                D_803D5530->zPos - (((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * 20) >> 8),
                D_803D5530->yPos,
                552, 150, D_803D5530, 3, 33);
            func_8032C360_73DA10(156, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
        }
    }
}

void func_8035FD4C_7713FC(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 18;
    func_8032C360_73DA10(7, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEC14);
}

void func_8035FDC0_771470(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        func_8032C360_73DA10(184, 0x7000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEC18);
        D_803D552C->unk308 = 80;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = 39;
    D_803D552C->unk2B4.unk4 = 1;
}

void func_8035FE6C_77151C(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = 19;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035FE90_771540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_80360D94_772444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_803622DC_77398C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_80362618_773CC8.s")

void func_80362964_774014(void) {
    if (D_803D5530->unk162 == 1) {
        D_803D552C->unk30E = -1;
    } else {
        D_803D552C->unk30E = (D_803D552C->unk30E + 1) & 0xFF;
    }
}

void func_803629B0_774060(void) {
    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 5)) {
        func_8037FEDC_79158C();
    } else {
        func_8035E3E8_76FA98(1);
    }
}

void func_80362A00_7740B0(void) {
}

void func_80362A08_7740B8(void) {
}

// dupe of func_80362A84_774134
void func_80362A10_7740C0(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 3;
    func_8032C360_73DA10(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
//
void func_80362A84_774134(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 3;
    func_8032C360_73DA10(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
