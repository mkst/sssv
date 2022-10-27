#include <ultra64.h>
#include "common.h"

// BOXING_KANGAROO
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/kangaroo/func_8036F7A0_780E50.s")

// POGO_KANGAROO
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/kangaroo/func_80370C84_782334.s")

void func_80372510_783BC0(void) {
    D_803D552C->unk32A = D_803D5544;
    if (SSSV_RAND(2) == 0) {
        D_803D552C->unk365 = ATTACK_KANGAROO_1;
    } else {
        D_803D552C->unk365 = ATTACK_KANGAROO_2;
    }
    play_sound_effect_at_location(57, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_803725A4_783C54(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_KANGAROO_3;
        D_803D552C->unk32C = D_803D552C->unk302;
    } else {
        recharge_skill(1);
    }
}

void func_80372604_783CB4(void) {
    D_803D552C->unk32A = D_803D5544;
    if (SSSV_RAND(2) == 0) {
        D_803D552C->unk365 = ATTACK_KANGAROO_1;
    } else {
        D_803D552C->unk365 = ATTACK_KANGAROO_2;
    }
    play_sound_effect_at_location(57, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_80372698_783D48(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_KANGAROO_3;
        D_803D552C->unk32C = D_803D552C->unk302;
    }
}
