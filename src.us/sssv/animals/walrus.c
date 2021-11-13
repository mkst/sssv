#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/walrus/func_80374C70_786320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/walrus/func_803766E8_787D98.s")

void func_803769E0_788090(void) {
    Animal *animal;
    s32 tmp;

    animal = func_8037E9AC_79005C();
    if (func_8037FBBC_79126C() != 0) {
        tmp = 861;
    } else {
        tmp = -861;
    }

    func_802FEE98_710548(D_803D5530->xPos + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->zPos - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->yPos + (D_803D5530->unk42 >> 1),
                         20,
                         ((u8)D_803D552C->unk302 * 360) >> 8, // divide by 256
                         animal,
                         1, 17, D_803BF028, 110, 96,
                         D_803D5530->xVelocity.h, D_803D5530->zVelocity.h, D_803D5530->yVelocity.h, D_803D5530);
    recoil(2);
    func_801373CC(0, 25, 30, 5, func_8029B7D0_6ACE80(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos));
}

void walrus_fire_missile(Animal *arg0) {
    s32 tmp;

    if (func_8037FBBC_79126C() != 0) {
        tmp = 861;
    } else {
        tmp = -861;
    }

    func_802FEE98_710548(D_803D5530->xPos + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->zPos - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->yPos + (D_803D5530->unk42 >> 1),
                         20,
                         ((u8)D_803D552C->unk302 * 360) >> 8,
                         arg0,
                         2, 17, D_803BF02C, 120, 96,
                         D_803D5530->xVelocity.h, D_803D5530->zVelocity.h, D_803D5530->yVelocity.h, D_803D5530);
    recoil(2);
}

void walrus_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 24;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
