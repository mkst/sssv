#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/husky/func_80368DD0_77A480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/husky/func_8036A05C_77B70C.s")

void func_8036BBB8_77D268(void) {
    D_803D552C->unk30E = 15;
    load_animal(HUSKY_ATTACKING);
}

void func_8036BBE8_77D298(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        func_802D5F4C_6E75FC(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos + (D_803D5530->unk42 >> 2), 21, 0, 0, (func_8012826C() + 0x30000) & 0x7FFF, 30, 1, 1, 0);
    } else {
        func_8037D994_78F044(0xB);
        func_802D5F4C_6E75FC(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos + (D_803D5530->unk42 >> 2), 21, 0, 0, (func_8012826C() + 0x30000) & 0x7FFF, 30, 1, 1, 0);
    }
}

void func_8036BCF8_77D3A8(void) {
    Animal *animal;
    s16 temp_v1;
    u8 temp_t0;
    s32 phi_t1;

    animal = func_8037E9AC_79005C();
    if (func_8037FBBC_79126C() != 0) {
        phi_t1 = 369;
    } else {
        phi_t1 = -369;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    func_802FEE98_710548(
        D_803D5530->xPos + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->zPos - ((((D_80152C78[temp_t0] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->yPos + (D_803D5530->unk42 >> 1),
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
    recoil(2);
}

void func_8036BE70_77D520(void) {
    if (D_803D552C->unk30E <= 0) {
        load_animal(HUSKY);
    }
}

void ski_husky_fire_missile(Animal *arg0) {
    s16 temp_v1;
    u8 temp_t0;
    s32 phi_t1;

    if (func_8037FBBC_79126C() != 0) {
        phi_t1 = 369;
    } else {
        phi_t1 = -369;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    func_802FEE98_710548(
        D_803D5530->xPos + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->zPos - ((((D_80152C78[temp_t0] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->yPos + (D_803D5530->unk42 >> 1),
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
    recoil(2);
}

void func_8036C014_77D6C4(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == HUSKY) {
        load_animal(HUSKY_ATTACKING);
    }
}

void func_8036C05C_77D70C(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 11;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
