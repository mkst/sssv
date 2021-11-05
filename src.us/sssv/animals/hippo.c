#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/hippo/func_802EF0C0_700770.s")

void func_802F036C_701A1C(void) {
}

void func_802F0374_701A24(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 17;
        D_803D552C->unk32C = D_803D552C->unk302;
    }
}

void func_802F03B8_701A68(void) {
    s16 xPos;
    s16 zPos;
    s16 yPos;
    s16 i;

    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        xPos = D_803D5530->xPos - ((((D_80152C78[((D_803D552C->unk302 & 0xFF))]) >> 7) << 6) >> 8);
        zPos = D_803D5530->zPos - ((((D_80152C78[(((D_803D552C->unk302 + 64) & 0xFF))]) >> 7) << 6) >> 8);
        yPos = D_803D5530->yPos;
        spawn_temporary_object(xPos, zPos, yPos, 1228, 180, D_803D5530, 40, 78);
        play_sound_effect_at_location(0x6D, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);

        for (i = 0; i < 4; i++) {
            create_particle_effect(
                ((func_8012826C() & 0x3F) + xPos) - 32,
                ((func_8012826C() & 0x3F) + zPos) - 32,
                (func_8012826C() & 0x3F) + yPos,
                21,
                0,
                0,
                0,
                35,
                4229,
                50193,
                0);
        }
    } else {
        recharge_skill(1);
    }
}

void drop_sticky_mine(void) {
    s16 xPos;
    s16 zPos;
    s16 yPos;
    s16 i;

    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        xPos = D_803D5530->xPos - ((((D_80152C78[((D_803D552C->unk302 & 0xFF))]) >> 7) << 6) >> 8);
        zPos = D_803D5530->zPos - ((((D_80152C78[(((D_803D552C->unk302 + 64) & 0xFF))]) >> 7) << 6) >> 8);
        yPos = D_803D5530->yPos;
        spawn_temporary_object(xPos, zPos, yPos, 1228, 220, D_803D5530, 40, 78);
        play_sound_effect_at_location(0x6D, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);

        for (i = 0; i < 4; i++) {
            create_particle_effect(
                ((func_8012826C() & 0x3F) + xPos) - 32,
                ((func_8012826C() & 0x3F) + zPos) - 32,
                (func_8012826C() & 0x3F) + yPos,
                21,
                0,
                0,
                0,
                35,
                4229,
                50193,
                0);
        }
    }
}

void func_802F0780_701E30(s32 arg0, s32 arg1, s32 arg2) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 17;
        D_803D552C->unk32C = D_803D552C->unk302;
    }
}
