#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/husky/func_80368DD0_77A480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/husky/func_8036A05C_77B70C.s")

void func_8036BBB8_77D268(void) {
    D_803D552C->unk30E = 15;
    load_animal(CRAZY_HUSKY);
}

void func_8036BBE8_77D298(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + FTOFIX32(3.0)) & (FTOFIX32(0.5) - 1),
            30,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
    } else {
        func_8037D994_78F044(11);
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + FTOFIX32(3.0)) & (FTOFIX32(0.5) - 1),
            30,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
    }
}

void func_8036BCF8_77D3A8(void) {
    Animal *animal;
    s16 temp_v1;
    u8 temp_t0;
    s32 twist;

    animal = func_8037E9AC_79005C();
    if (func_8037FBBC_79126C() != 0) {
        twist = 369;
    } else {
        twist = -369;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * twist) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[temp_t0] >> 7) * twist) / 32) >> 8),
        D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
        10,
        temp_t0*360 >> 8,
        animal,
        2,
        16,
        D_803BEF68,
        30,
        16,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

// 'crazy' husky
void func_8036BE70_77D520(void) {
    if (D_803D552C->unk30E <= 0) {
        load_animal(HUSKY);
    }
}

void ski_husky_fire_missile(Animal *arg0) {
    s16 temp_v1;
    u8 temp_t0;
    s32 twist;

    if (func_8037FBBC_79126C() != 0) {
        twist = 369;
    } else {
        twist = -369;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * twist) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[temp_t0] >> 7) * twist) / 32) >> 8),
        D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
        10,
        (temp_t0 * 360) >> 8,
        arg0,
        4,
        16,
        D_803BEF6C,
        40,
        16,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void func_8036C014_77D6C4(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == HUSKY) {
        load_animal(CRAZY_HUSKY);
    }
}

void ski_husky_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 11;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
