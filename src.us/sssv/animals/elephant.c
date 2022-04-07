#include <ultra64.h>
#include "common.h"

// this is a biggun
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/elephant/func_8037B800_78CEB0.s")

void func_8037D06C_78E71C(void) {
    if ((D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) {
        func_8037D0EC_78E79C();
    } else if ((D_803D552C->unk365 == ATTACK_NONE) && (D_803D552C->unk320 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_ELEPHANT_1;
    }
}

void func_8037D0EC_78E79C(void) {
    s32 tmp = ATTACK_ELEPHANT_1;
    if (D_803D552C->unk365 == tmp) {
        D_803D552C->unk365 = ATTACK_NONE;
        if (D_803D5528->unk3C8.unk2 != 0) {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = tmp;
        }
    }
}

void func_8037D138_78E7E8(void) {
    if ((D_803D552C->unk320 == NULL) && (D_803D552C->unk365 == ATTACK_NONE)) {
        // FIXME: this fixes regalloc but is unlikely to be what the devs wrote:
        s32 fakematch = !D_803D552C->unk320->unk16C;
        if (fakematch) {}

        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_GRAB;
    } else if (D_803D552C->unk320) {
        s32 tmp = func_8033C9CC_74E07C(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5524->unkBA >> 1),
            D_803D5530->unk160,
            D_803D552C->unk320->xPos.h,
            D_803D552C->unk320->zPos.h,
            D_803D552C->unk320->yPos.h + (D_803D552C->unk320->unk42 >> 1),
            0x7F,
            0, 0);
        if (tmp == 0) {
            D_803D552C->unk32A = D_803D5544;
            if ((D_803D552C->unk320->unk16C->unk0 == 2) || (D_803D552C->unk320->unk16C->unk0 == 61)) {
                D_803D552C->unk365 = ATTACK_BEAR_2;
            } else {
                D_803D552C->unk365 = ATTACK_BEAR_3;
            }
        } else {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
        }
    }
}

void func_8037D268_78E918(s16 arg0) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_ELEPHANT_1;
        D_803D552C->unk2EC = arg0;
    }
}
