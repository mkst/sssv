#include <ultra64.h>
#include "common.h"


// delay slot
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802EA7F0_6FBEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802EBB34_6FD1E4.s")
// delay slot
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802ED108_6FE7B8.s")

void func_802EE89C_6FFF4C(void) {
    if (D_803D552C->missileSide != 0) {
        D_803D552C->missileSide = 0;
    } else {
        D_803D552C->missileSide = 1;
    }
    if (D_803D5538 != 0) {
        play_sound_effect_at_location(0x94, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
    D_803D552C->unk30E = 1;
    D_803D552C->unk312 = 4;

    if (D_803D552C->unk310 == 0) {
        play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
        func_80321E60_733510(17, 0, 0, -28, 0, 0, -9, 8);
        D_803D552C->unk310 = 20;
    }
    D_803D552C->unk310 = MAX(3, D_803D552C->unk310 - 1);
}

void func_802EE9EC_70009C(void) {
    D_803D552C->unk310 = MAX(0, D_803D552C->unk310 - 1);
}

void func_802EEA18_7000C8(void) {
    if (D_803D552C->unk365 != 48) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 48;
    }
}

void func_802EEA54_700104(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 18;
}

void func_802EEA7C_70012C(void) {
    u16 tmp[9];

    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        tmp[5] = func_8012826C();
        tmp[6] = func_8012826C();
        tmp[7] = func_8012826C();
        tmp[8] = func_8012826C();
        func_802D5F4C_6E75FC(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + ((s32) D_803D5530->unk42 >> 2),
            (tmp[5] & 1) + 25,
            ((tmp[6] & 0x7FFF) * 2) - 40000,
            ((tmp[7] & 0x7FFF) * 2) - 40000,
            0, (tmp[8] & 0xF) + 15, 1, 1, (func_8012826C() & 0x1F) + 15);
    } else {
        func_8037D994_78F044(16);
        tmp[5] = func_8012826C();
        tmp[6] = func_8012826C();
        tmp[7] = func_8012826C();
        tmp[8] = func_8012826C();
        func_802D5F4C_6E75FC(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + ((s32) D_803D5530->unk42 >> 2),
            (tmp[5] & 1) + 25, ((tmp[6] & 0x7FFF) * 2) - 40000, ((tmp[7] & 0x7FFF) * 2) - 40000,
            0, (tmp[8] & 0xF) + 15, 1, 1, (func_8012826C() & 0x1F) + 15);
    }
}

void func_802EEC44_7002F4(void) {
    Animal * animal;
    s16 temp_v1;
    u8 temp_t0;
    s32 phi_t1;

    animal = func_8037E9AC_79005C();
    if (animal == NULL) {
        func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
    }
    if (func_8037FBBC_79126C() != 0) {
        phi_t1 = 450;
    } else {
        phi_t1 = -450;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    func_802FEE98_710548(
        D_803D5530->xPos + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->zPos - ((((D_80152C78[temp_t0] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->yPos + ((D_803D5530->unk42 * 3) >> 2),
        0,
        temp_t0*360 >> 8,
        animal,
        3,
        30,
        D_803BCDD8_7CE488,
        23,
        15,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    recoil(2);
}

void racing_dog_fire_missile(Animal *animal) {
    s16 temp_v1;
    u8 temp_t0;
    s32 phi_t1;

    if (animal == NULL) {
        func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
    }
    if (func_8037FBBC_79126C() != 0) {
        phi_t1 = 450;
    } else {
        phi_t1 = -450;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    func_802FEE98_710548(
        D_803D5530->xPos + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->zPos - ((((D_80152C78[temp_t0] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->yPos + ((D_803D5530->unk42 * 3) >> 2),
        10,
        temp_t0*360 >> 8,
        animal,
        4,
        30,
        D_803BCDDC_7CE48C,
        35,
        15,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    recoil(2);
}

// dog_bark? or set dog_bark_state? seems to do nothing
void func_802EEF74_700624(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 18;
}

void flying_dog_fire_gun(s32 arg0, s32 arg1, s32 arg2) {
    if (D_803D552C->missileSide != 0) {
        D_803D552C->missileSide = 0;
    } else {
        D_803D552C->missileSide = 1;
    }
    D_803D552C->unk30E = 1;
    D_803D552C->unk312 = 4;
}

void flying_dog_drop_bomb(s32 arg0, s32 arg1, s32 arg2) {
    func_80321E60_733510(0x11, 0, 0, -28, 0, 0, -9, 8);
    play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_802EF074_700724(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 16;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
