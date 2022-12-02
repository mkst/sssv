#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/scorpion/func_80376D40_7883F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/scorpion/func_80378B84_78A234.s")
// miles away
// void func_80378B84_78A234(s16 arg0, s16 *arg1, s16 *arg2, s16 *arg3, s16 *arg4, Animal *arg5) {
//     s16 sp44;
//     s16 sp3C;
//     s16 sp3A;
//     s16 sp38;
//     s32 sp32;
//     s16 sp30;
//     s16 sp2E;
//     s16 sp2C;
//     s16 temp_s0;
//     s16 temp_s1;
//     s32 temp_t9;
//     s32 temp_t7;
//     s32 temp_t2;
//     s16 temp_t7_3;
//     s16 temp_t7_4;
//
//
//     temp_t2 = (D_80203FE0[2].unk2 >> 2) + D_80203FE0[2].unk2;
//     temp_t7 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 7;
//     temp_t9 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7;
//     temp_t7_3 = (((temp_t7 * temp_t2) / 32) + ((temp_t9 * ((D_80203FE0[4].unk0 >> 2) + D_80203FE0[4].unk0)) / 32)) >> 7;
//     temp_t7_4 = (((temp_t9 * temp_t2) / 32) - ((temp_t7 * ((D_80203FE0[4].unk0 >> 2) + D_80203FE0[4].unk0)) / 32)) >> 7;
//
//     temp_s0 = D_803D552C->xPos.h - temp_t7_3;
//     temp_s1 = D_803D552C->zPos.h - temp_t7_4;
//     sp3C = D_803D552C->xPos.h + temp_t7_3;
//     sp3A = D_803D552C->zPos.h + temp_t7_4;
//     sp32 = D_803D552C->yPos.h + D_803D5524->unkBA;
//     sp44 = D_803D552C->yPos.h;
//     sp38 = D_803D552C->yPos.h;
//     sp30 = arg5->xPos.h;
//     sp2E = arg5->zPos.h;
//     sp2C = D_803D552C->unk30C;
//
//     if (arg0 < 5) {
//         *arg2 = temp_s0 + (((sp3C - temp_s0) * arg0) / 4);
//         *arg3 = temp_s1 + (((sp3A - temp_s1) * arg0) / 4);
//         *arg4 = sp44 + (((sp38 - sp44) * arg0) / 4);
//     } else if (arg0 < 11) {
//         *arg2 = sp3C + (((temp_s0 - sp3C) * (arg0 - 4)) / 6);
//         *arg3 = sp3A + (((temp_s1 - sp3A) * (arg0 - 4)) / 6);
//         *arg4 = sp38 + (((sp32 - sp38) * (arg0 - 4)) / 6);
//     } else if (arg0 < 17) {
//         *arg2 = temp_s0 + (((sp2E - temp_s0) * (arg0 - 10)) / 6);
//         *arg3 = temp_s1 + (((sp2E - temp_s1) * (arg0 - 10)) / 6);
//         *arg4 = sp32 + (((sp2C - sp32) * (arg0 - 10)) / 6);
//     } else {
//         *arg2 = sp30;
//         *arg3 = sp2E;
//         *arg4 = sp2C;
//     }
//     *arg1 = D_803B52FC[arg0];
// }

void func_80378FF8_78A6A8(void) {
    if (!D_803D552C) {
        // is this fakematch or debug stub?
    };

    if ((D_801D9ED8.unkFFBC == 0) && (D_801D9ED8.unkFFB6 != 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_SCORPION_1;
    }
}

void func_80379048_78A6F8(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SCORPION_1;
}

void func_80379070_78A720(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        Animal *a = func_8037ED1C_7903CC();
        if (a == NULL) {
            recharge_skill(1);
        } else {
            D_803D552C->unk330 = a;
            D_803D552C->unk365 = ATTACK_SCORPION_2;
            D_803D552C->unk32A = D_803D5544;
            D_803D552C->unk30C = D_803D552C->unk330->yPos.h + (D_803D552C->unk330->unk42 >> 1);
            do_rumble(0, 25, 5, 60, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
        }
    } else {
        recharge_skill(1);
    }
}

void func_80379148_78A7F8(Animal *a) {
    if ((D_803D552C->unk365 == 0) && (a != NULL)) {
        D_803D552C->unk330 = a;
        D_803D552C->unk365 = ATTACK_SCORPION_2;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk30C = D_803D552C->unk330->yPos.h + (D_803D552C->unk330->unk42 >> 1);
    }
}

void func_803791AC_78A85C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SCORPION_1;
}
