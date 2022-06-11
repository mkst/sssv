#include <ultra64.h>
#include "common.h"

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/hyena/func_803574E0_768B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/hyena/func_80358E3C_76A4EC.s")

// hyena
void func_8035A130_76B7E0(void) {
    func_8037E1C4_78F874();
    func_80380620_791CD0(D_803D552C, 15, 12, 40, 10);
}

void func_8035A170_76B820(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
                21,
                0,
                0,
                (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
                30,
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(0, 0, 0, 1),
                0);
        }
    } else {
        func_8037D994_78F044(24);
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
                21,
                0,
                0,
                (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
                30,
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(0, 0, 0, 1),
                0);
        }
    }
}

// hyena biker
void func_8035A2A8_76B958(void) {
    Animal *animal;
    s16 tmp;

    animal = func_8037E9AC_79005C();

    if (func_8037FBBC_79126C()) {
        tmp = 712;
    } else {
        tmp = -713;
    }

    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
        D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
        5,
        ((u8)D_803D552C->unk302 * 360) >> 8,
        animal,
        2,
        40,
        0.25f,
        200,
        8,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void biker_hyena_fire_missile(Animal *animal) {
    s16 tmp;

    if (func_8037FBBC_79126C()) {
        tmp = 712;
    } else {
        tmp = -713;
    }

    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
        D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
        5,
        ((u8)D_803D552C->unk302 * 360) >> 8,
        animal,
        3,
        40,
        0.25f,
        200,
        8,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void func_8035A590_76BC40(s16 arg0) {
    D_803D552C->unk2EC = arg0;
}

void func_8035A5A4_76BC54(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 24;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
