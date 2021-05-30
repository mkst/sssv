#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/fox/func_802E5000_6F66B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/fox/func_802E620C_6F78BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/fox/func_802E7394_6F8A44.s")

void func_802E84E0_6F9B90(void) {
    func_8037D994_78F044(16);
}

void func_802E8500_6F9BB0(void) {
    Animal *animal = func_8037E9AC_79005C();
    if (animal != NULL) {
        play_sound_effect_at_location(2, 0x3700, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
    // scale missile to zero
    func_8037FBBC_79126C();
    // fire missile
    func_802FEE98_710548(
        D_803D5530->xPos,
        D_803D5530->zPos,
        D_803D5530->yPos - D_803D5530->unk42,
        0x161,
        D_803D552C->unk302*360 >> 8,
        animal,
        1,
        16,
        0.5f,
        0xC8,
        0x60,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    play_sound_effect_at_location(2, 0x3700, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_802E864C_6F9CFC(void) {
    if (D_803D552C->unk365 != 20) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 20;
        func_8033F2EC_75099C();
        func_8033F294_750944(2);
    } else {
        D_803D5528->skillAEnergy[0] += D_803D5524->unkDA[0];
    }
}

void func_802E86C8_6F9D78(void) {
    if (D_803D552C->unk365 == 43) {
        D_803D552C->unk365 = 42;
    } else if (D_803D552C->unk365 != 42) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 42;
        play_sound_effect_at_location(0, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
}

void func_802E8760_6F9E10(void) {
    if (((D_803D5544 - D_803D552C->unk32A) >= 13) && (D_803D552C->unk365 == 42)) {
        D_803D552C->unk365 = 43;
        D_803D552C->unk32A = D_803D5544;
    }
}

void fire_fox_fire_missile(Animal *animal) {
    play_sound_effect_at_location(2, 0x3700, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    // scale missile to zero
    func_8037FBBC_79126C();
    // fire missile
    func_802FEE98_710548(
        D_803D5530->xPos,
        D_803D5530->zPos,
        (D_803D5530->yPos - D_803D5530->unk42),
        0x161,
        (D_803D552C->unk302 * 360) >> 8,
        animal,
        2,
        16,
        0.5f,
        0xC8,
        0x60,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
}

// fox_tail_attack
void func_802E88C0_6F9F70(s16 arg0) {
    if (D_803D552C->unk365 == 42) {
        D_803D552C->unk2EC = MAX(D_803D552C->unk2EC, arg0);
    } else if (D_803D552C->unk365 == 43) {
        D_803D552C->unk2EC = arg0;
        D_803D552C->unk365 = 42;
        D_803D552C->unk32A -= 8;
    } else {
        D_803D552C->unk2EC = arg0;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 42;
        play_sound_effect_at_location(0, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
}

void func_802E89AC_6FA05C(void) {
    if (D_803D552C->unk365 != 20) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 20;
    }
}
