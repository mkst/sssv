#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355130_7667E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355918_766FC8.s")

void func_80355E14_7674C4(void) {
    func_80321E60_733510(17, 32, 0, 30, 10, 0, 2, 45);
    func_8034220C_7538BC(17, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);
    play_sound_effect_at_location(75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_80355EDC_76758C(void) {
    recharge_skill(0);
}

void func_80355EFC_7675AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(123, 0x7FFF, 0, D_803D5530->xPos,  D_803D5530->zPos, D_803D5530->yPos, D_803BEB0C);
    load_animal(TORTOISE_TANK_DEFENDING);
}

void func_80355F64_767614(void) {
    func_8037D994_78F044(20);
    if ((D_803D5540 & 1) == 0) {
        func_802D5F4C_6E75FC(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos + (D_803D5530->unk42 >> 2), 21, 0, 0, (func_8012826C() + 0x30000) & 0x7FFF, 30, 1, 1, 0);
    }
}

void func_80355FFC_7676AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB10);
    load_animal(RACING_TORTOISE_ATTACKING);
}

void func_80356064_767714(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(101, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB14);
    load_animal(TORTOISE_TANK);
}

void func_803560CC_76777C(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(101, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB18);
    load_animal(RACING_TORTOISE);
}

void func_80356134_7677E4(Animal *a) {
    s32 temp_v0;
    s16 rot;

    temp_v0 = func_802F8160_709810(D_803D5530, a, 32, 20, 30, 0x59, -4, 3, (f32)D_803A05B0 / 65536.0);
    if (temp_v0 == -1) {
        rot = 32;
    } else {
        rot = (temp_v0 * 256) / 360;
    }
    func_80322064_733714(17, 32, 0, 20, 30, D_803D5530->yRotation, rot, 2, 45);
    func_801373CC(0, 10, 40, 5, func_8029B7D0_6ACE80(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos));
    func_8034220C_7538BC(0xE, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

    play_sound_effect_at_location(75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_803562C8_767978(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == TORTOISE_TANK) {
        play_sound_effect_at_location(123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB1C);
        load_animal(TORTOISE_TANK_DEFENDING);
    }
}

void func_80356348_7679F8(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_TORTOISE) {
        play_sound_effect_at_location(123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB20);
        load_animal(RACING_TORTOISE_ATTACKING);
    }
}

void func_803563C8_767A78(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 20;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
