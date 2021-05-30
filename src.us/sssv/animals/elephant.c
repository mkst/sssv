#include <ultra64.h>
#include "common.h"

// this is a biggun
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/elephant/func_8037B800_78CEB0.s")

void func_8037D06C_78E71C(void) {
    if ((D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) {
        func_8037D0EC_78E79C();
    } else if ((D_803D552C->unk365 == 0) && (D_803D552C->unk320 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 16;
    }
}

void func_8037D0EC_78E79C(void) {
    s32 tmp = 16;
    if (D_803D552C->unk365 == tmp) {
        D_803D552C->unk365 = 0U;
        if (D_803D5528->unk3CA != 0) {
            D_803E00EE[D_803D5528->unk3CA].unk0 = tmp;
        }
    }
}

void func_8037D138_78E7E8(void) {
    if ((D_803D552C->unk320 == NULL) && (D_803D552C->unk365 == 0)) {
        // FIXME: this fixes regalloc but is unlikely to be what the devs wrote:
        s32 fakematch = !D_803D552C->unk320->unk16C;
        if (fakematch) {}

        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 11;
    } else if (D_803D552C->unk320) {
        s32 tmp = func_8033C9CC_74E07C(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + (D_803D5524->unkBA >> 1),
            D_803D5530->unk160,
            D_803D552C->unk320->xPos,
            D_803D552C->unk320->zPos,
            D_803D552C->unk320->yPos + (D_803D552C->unk320->unk42 >> 1),
            0x7F, 0, 0);
        if (tmp == 0) {
            D_803D552C->unk32A = D_803D5544;
            if ((D_803D552C->unk320->unk16C->unk0 == 2) || (D_803D552C->unk320->unk16C->unk0 == 61)) {
                D_803D552C->unk365 = 14;
            } else {
                D_803D552C->unk365 = 15;
            }
        } else {
            func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
        }
    }
}

void func_8037D268_78E918(s16 arg0) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 16;
        D_803D552C->unk2EC = arg0;
    }
}
