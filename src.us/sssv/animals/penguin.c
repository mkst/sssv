#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/penguin/func_80364780_775E30.s")

// king_penguin_jetpack
void func_80365954_777004(void) {
    if ((D_803D5530->unk162 != 1) && (D_803D5530->unk4A == 0)) {
        func_8032CD70_73E420(
            (void*)D_803D5530,
            SFX_UNKNOWN_103,
            0x7000,
            0,
            0.25f,
            D_803D552C->xPos.h,
            D_803D552C->zPos.h,
            D_803D552C->yPos.h
            );

        if (D_803D5530->yVelocity.w > FTOFIX32(4.0)) {
            D_803D5530->yVelocity.w += FTOFIX32(1.0);
        } else {
            D_803D5530->yVelocity.w += FTOFIX32(2.5);
        }

        create_particle_effect(
            (SSSV_RAND(16) + D_803D5530->xPos.h) - 8,
            (SSSV_RAND(16) + D_803D5530->zPos.h) - 8,
            D_803D5530->yPos.h,
            (SSSV_RAND(2) + 25),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            (D_803D5530->yVelocity.w >> 1) - FTOFIX32(3.0517578125),
            SSSV_RAND(13),
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(56, 56, 56, 1),
            SSSV_RAND(16) + 20);

        create_particle_effect(
            (SSSV_RAND(16) + D_803D5530->xPos.h) - 8,
            (SSSV_RAND(16) + D_803D5530->zPos.h) - 8,
            D_803D5530->yPos.h,
            63,
            (D_803D5530->xVelocity.w >> 2) * -1,
            (D_803D5530->zVelocity.w >> 2) * -1,
            (D_803D5530->yVelocity.w >> 1) - FTOFIX32(4.57763671875),
            SSSV_RAND(32) + 30,
            GPACK_RGBA5551(SSSV_RAND(64) + 192, SSSV_RAND(64) + 192, 0, 1),
            GPACK_RGBA5551(SSSV_RAND(64) + 192, 0, 0, 1),
            0);

    } else {
        recharge_skill(0);
    }
}

void func_80365C28_7772D8(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk365 = ATTACK_SNOWBALL;
        D_803D552C->unk32A = D_803D5544;
    } else {
        recharge_skill(1);
    }
}

void func_80365C7C_77732C(void) {
    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
            D_803D552C->unk308 = 80;
        } else {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x7000, 0, 1.3f);
            D_803D552C->unk308 = 80;
        }
    }
    if (D_803D552C->unk2CC = func_8037E9AC_79005C()) {
        D_803D552C->unk2B4.unk4 = 1;
    } else {
        D_803D552C->unk2B4.unk4 = 0;
    }
}

// king penguin
void func_80365D74_777424(void) {
    D_803D552C->unk2B4.unk4 = 0;
}

// penguin?
void penguin_throw_snowball(Animal *arg0) {
    if (D_803D552C->unk365 != ATTACK_SNOWBALL) {
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 0xA, 0x14, 0x23, 0x59, 0, 3, (f32) D_803A05B0 / 65536.0);
        if (tmp == -1) {
            tmp = 32;
        } else {
            tmp = (s16) ((tmp * 256) / 360);
        }
        D_803D552C->unk365 = ATTACK_SNOWBALL;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk338 = tmp;
    }
}

// king penguin attack
void func_80365E70_777520(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
        D_803D552C->unk308 = 50;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk2B4.unk4 = 1;
}
