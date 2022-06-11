#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/walrus/func_80374C70_786320.s")

void func_803766E8_787D98(void) {
    s32 phi_v1;
    s16 tmp;

    if (D_803D5530->state < 26) {
        if (D_803D5530->state == 21) {
            func_8037D9D4_78F084();
        } else {
            func_8037D994_78F044(24);
        }
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
                1,
                1,
                0);
        }
    } else {
        if (D_803D5530->state == 141) {
            func_8037D9D4_78F084();
        } else {
            func_8037D994_78F044(16);
        }

        phi_v1 = MAX(MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 0].unk6,
                         D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 0].unk6),
                     MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 1].unk6,
                         D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 1].unk6));

        tmp = D_803C0430.unk0[(D_803D5530->xPos.h * D_803D5530->zPos.h) & 7][(u16)(D_803C0430.unk204 + (((D_803D5530->xPos.h * D_803D5530->zPos.h) + (D_803D5530->xPos.h * D_803D5530->xPos.h)) << 3)) & 63] + (4 * phi_v1);
        phi_v1 = ABS(tmp - D_803D5530->yPos.h);
        if (phi_v1 < 48) {
            func_8039DFD4_7AF684(D_803D5530, 1, 10, 16, 0, -10, 0, 0xFF, 0xFF, 0xFF, 0, 185, 0xFF, 1, 2, D_803D5530);
            func_8039DFD4_7AF684(D_803D5530, 2, 10, 16, 0, -10, 0, 0xFF, 0xFF, 0xFF, 0, 185, 0xFF, 1, 2, ((struct071*)D_803D5530) + 1);
        }
    }
}

void func_803769E0_788090(void) {
    Animal *animal;
    s32 tmp;

    animal = func_8037E9AC_79005C();
    // twist animal Z based on missile side fired?
    if (func_8037FBBC_79126C() != 0) {
        tmp = 861;
    } else {
        tmp = -861;
    }

    fire_homing_missile(D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
                         20,
                         ((u8)D_803D552C->unk302 * 360) >> 8, // divide by 256
                         animal,
                         1, 17, D_803BF028, 110, 96,
                         D_803D5530->xVelocity.h, D_803D5530->zVelocity.h, D_803D5530->yVelocity.h, D_803D5530);
    apply_recoil(2);
    do_rumble(0, 25, 30, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
}

void walrus_fire_missile(Animal *arg0) {
    s32 tmp;

    if (func_8037FBBC_79126C() != 0) {
        tmp = 861;
    } else {
        tmp = -861;
    }

    fire_homing_missile(D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
                         20,
                         ((u8)D_803D552C->unk302 * 360) >> 8,
                         arg0,
                         2, 17, D_803BF02C, 120, 96,
                         D_803D5530->xVelocity.h, D_803D5530->zVelocity.h, D_803D5530->yVelocity.h, D_803D5530);
    apply_recoil(2);
}

void walrus_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 24;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
