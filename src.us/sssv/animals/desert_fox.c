#include <ultra64.h>
#include "common.h"


// ARMED_DESERT_FOX
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_803726E0_783D90.s")

// DESERT_FOX_ATTACKING
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_80373788_784E38.s")

void func_80374470_785B20(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_DESERT_FOX_1;
    } else {
        recharge_skill(1);
    }
}

void func_803744C4_785B74(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_BEAR_2;
    } else {
        recharge_skill(1);
    }
}

//Desert fox dizziness function
void func_80374518_785BC8(void) {
    load_animal(DESERT_FOX);

    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_DESERT_FOX_SPIN;

    if (D_803D5528->energy[1].unk0 < 900) {
        D_803D552C->unk348 = 512;
        D_803D552C->unk34A = 50;
    } else {
        D_803D552C->unk348 = MAX(D_803D552C->unk30A, D_803D552C->unk348);
        D_803D552C->unk30A = 0;
    }
}

void func_803745BC_785C6C(void) {
}

void func_803745C4_785C74(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == DESERT_FOX) {
        load_animal(DESERT_FOX_ATTACKING);
    }
}

void func_8037460C_785CBC(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_BEAR_2;
    } else {
        recharge_skill(1);
    }
}
