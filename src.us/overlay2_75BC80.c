#include <ultra64.h>
#include "common.h"


s8 D_803A8350_7B9A00[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0xFF, 0xFF, 0xFF, }; // reds
s8 D_803A8358_7B9A08[8] = { 0xFF, 0xFF, 0xC8, 0xFF, 0xFA, 0xFF, 0xC8, 0xFF, }; // greens
s8 D_803A8360_7B9A10[8] = { 0x00, 0x80, 0x64, 0xB4, 0x00, 0x64, 0xC8, 0xD4, }; // blues

void func_8034A5D0_75BC80(void) {
    func_802D760C_6E8CBC(
        D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void func_8034A60C_75BCBC(void) {
    func_802D760C_6E8CBC(
        D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void func_8034A648_75BCF8(void) {
    func_802D760C_6E8CBC(
        D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void spawn_dizzy_stars_big(void) {
    s16 i;
    s16 sp64;

    sp64 = SSSV_RAND(256);
    for (i = 0; i < 8; i++) {
        create_particle_effect(
            D_803D5530->position.xPos.h + (((SIN((i << 5) + sp64) >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->position.zPos.h + (((COS((i << 5) + sp64) >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->position.yPos.h + D_803D5524->unkBA,
            36,
            ((SIN((i << 5) + sp64) >> 7) << 9) + (D_803D5530->xVelocity.w >> 1),
            ((COS((i << 5) + sp64) >> 7) << 9) + (D_803D5530->zVelocity.w >> 1),
            (SSSV_RAND(32768) << 2) + FTOFIX32(3.0),
            8,
            (((D_803A8350_7B9A00[i] << 8) & 0xF800) | ((D_803A8358_7B9A08[i] << 3) & 0x7C0) | ((D_803A8360_7B9A10[i] >> 2) & 0x3E) | 1),
            (((D_803A8350_7B9A00[i] << 8) & 0xF800) | ((D_803A8358_7B9A08[i] << 3) & 0x7C0) | ((D_803A8360_7B9A10[i] >> 2) & 0x3E) | 1),
            0);
        create_particle_effect(
            (SSSV_RAND(32) + D_803D5530->position.xPos.h) - 16,
            (SSSV_RAND(32) + D_803D5530->position.zPos.h) - 16,
            SSSV_RAND(32) + D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
            35,
            0,
            0,
            0,
            6,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            0);
    }
}

void spawn_dizzy_stars_medium(void) {
    s16 i;
    s16 sp64;

    sp64 = SSSV_RAND(256);
    for (i = 0; i < 4; i++) {
        create_particle_effect(
            D_803D5530->position.xPos.h + (((SIN((i << 6) + sp64) >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->position.zPos.h + (((COS((i << 6) + sp64) >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->position.yPos.h + D_803D5524->unkBA,
            36,
            ((SIN((i << 6) + sp64) >> 7) << 9) + (D_803D5530->xVelocity.w >> 1),
            ((COS((i << 6) + sp64) >> 7) << 9) + (D_803D5530->zVelocity.w >> 1),
            (SSSV_RAND(32768) << 1) + FTOFIX32(3.0),
            6,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            0);
        create_particle_effect(
            (SSSV_RAND(32) + D_803D5530->position.xPos.h) - 16,
            (SSSV_RAND(32) + D_803D5530->position.zPos.h) - 16,
            SSSV_RAND(32) + D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
            35,
            0,
            0,
            0,
            4,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            0);
    }
}

void spawn_dizzy_starts_small(void) {
    s16 i;
    s16 sp64;

    sp64 = SSSV_RAND(256);
    for (i = 0; i < 2; i++) {
        create_particle_effect(
            D_803D5530->position.xPos.h + (((SIN((i << 6) + sp64) >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->position.zPos.h + (((COS((i << 6) + sp64) >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->position.yPos.h + D_803D5524->unkBA,
            36,
            ((SIN((i << 6) + sp64) >> 7) << 9) + (D_803D5530->xVelocity.w >> 1),
            ((COS((i << 6) + sp64) >> 7) << 9) + (D_803D5530->zVelocity.w >> 1),
            (SSSV_RAND(32768) << 1) + FTOFIX32(3.0),
            4,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1), //
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1), //
            0);
        create_particle_effect(
            (SSSV_RAND(32) + D_803D5530->position.xPos.h) - 16,
            (SSSV_RAND(32) + D_803D5530->position.zPos.h) - 16,
            SSSV_RAND(32) + D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
            35,
            0,
            0,
            0,
            4,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1), //
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1), //
            0);
    }
}

// ESA: func_800A32EC
void kick_up_dust_small(s32 arg0, s32 arg1) {
    s16 temp_v0;
    s16 i;

    for (i = 0; i < 2; i++) {
        temp_v0 = func_8012826C();
        if (temp_v0 & 1) {
            create_particle_effect(
                (D_803D5530->position.xPos.h + (temp_v0 & 0xF)) - 8,
                (D_803D5530->position.zPos.h + ((temp_v0 >> 8) & 0xF)) - 8,
                D_803D5530->position.yPos.h,
                20,
                arg0,
                arg1,
                0x8000,
                10,
                GPACK_RGBA5551(120, 120, 96, 1),
                GPACK_RGBA5551(136, 136, 136, 1),
                0);
        }
    }
}

// ESA: func_800A3404
void kick_up_dust_big(s32 xVelocity, s32 zVelocity) {
    u16 temp_v0;
    u16 i;

    for (i = 0; i < 4; i++) {
        temp_v0 = func_8012826C();
        if ((temp_v0 & 1) != 0) {
            create_particle_effect(
                (D_803D5530->position.xPos.h + (temp_v0 & 0xF)) - 8,
                (D_803D5530->position.zPos.h + ((temp_v0 & 0xF0) >> 4)) - 8,
                D_803D5530->position.yPos.h,
                20,
                xVelocity,
                zVelocity,
                0x8000,
                7,
                GPACK_RGBA5551(120, 120, 96, 1),
                GPACK_RGBA5551(136, 136, 136, 1),
                0);
        }
    }
}

void func_8034AFE0_75C690(void) {
}

void func_8034AFE8_75C698(s32 arg0, Animal *arg1) {
}

void func_8034AFF4_75C6A4(s32 arg0, Animal *arg1) {
}

void func_8034B000_75C6B0(s32 arg0) {
}

// used by husky and bear, foaming mouth particle locations?
void func_8034B008_75C6B8(u8 arg0, u8 arg1, s16 arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;

    s32 sp38;
    s32 sp34;
    s32 sp30;

    sp44 = D_803D5530->position.xPos.w + ((COS(D_803D552C->heading) * D_80203FE0[arg0].unk0) / 16) + ((SIN(D_803D552C->heading) * D_80203FE0[arg0].unk2) / 16);
    sp40 = D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * D_80203FE0[arg0].unk2) / 16) - ((SIN(D_803D552C->heading) * D_80203FE0[arg0].unk0) / 16);
    sp3C = D_803D5530->position.yPos.w + ((D_80203FE0[arg0].unk4 << 0xF) / 16);

    sp38 = D_803D5530->position.xPos.w + ((COS(D_803D552C->heading) * D_80203FE0[arg1].unk0) / 16) + ((SIN(D_803D552C->heading) * D_80203FE0[arg1].unk2) / 16);
    sp34 = D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * D_80203FE0[arg1].unk2) / 16) - ((SIN(D_803D552C->heading) * D_80203FE0[arg1].unk0) / 16);
    sp30 = D_803D5530->position.yPos.w + ((D_80203FE0[arg1].unk4 << 0xF) / 16);

    *arg3 = sp44 + (((sp38 - sp44) * arg2) >> 6);
    *arg4 = sp40 + (((sp34 - sp40) * arg2) >> 6);
    *arg5 = sp3C + (((sp30 - sp3C) * arg2) >> 6);
}

void func_8034B298_75C948(s16 arg0) {
    s16 sp2E;
    s16 sp2C;

    if ((arg0 == 0) || ((D_803D5540 & 2) == 0)) {
        if ((D_803D5530->state == 143) || (((D_803D5530->state == 142) || (D_803D5530->state == 144)) && ((D_803D5540 & 1) != 0))) {
            sp2E = ((SSSV_RAND(16) - 7) * (u16)D_803D5524->unkBE) >> 3;
            sp2C = ((SSSV_RAND(16) - 7) * (u16)D_803D5524->unkBE) >> 3;
            create_particle_effect_2(D_803D5530->position.xPos.h + sp2E, D_803D5530->position.zPos.h + sp2C, D_803D5530->position.yPos.h, 28, SSSV_RAND(4) + 4, 0, 0, 0);
        }
    }
}

void func_8034B3A8_75CA58(s16 arg0) {
    if ((arg0 == 0) || ((D_803D5540 & 2) == 0)) {
        if ((D_803D552C->unk366 == 3) ||
            (D_803D552C->unk366 == 4) ||
            (D_803D552C->unk366 == 1)) {
            if ((D_803D5530->state == 0x8F) ||
                (((D_803D5530->state == 0x8E) ||
                  (D_803D5530->state == 0x90) ||
                  (D_803D5530->state == 0x8D)) && (D_803D5540 & 1))) {
                func_8012826C();
                func_8012826C();
            }
        }
    }
}

// ESA: func_800A3630
void func_8034B45C_75CB0C(void) {
    s16 i = 0;

    if ((SSSV_RAND(128) == 73) &&
        ((D_803D5530->unk162 == 4) || (D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) &&
        ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4) || (D_803D552C->unk366 == 1))) {

        s16 tmp1 = (((SIN(D_803D552C->heading) >> 7) * D_803D5524->unkBE * 3) >> 9);
        s16 tmp2 = (((COS(D_803D552C->heading) >> 7) * D_803D5524->unkBE * 3) >> 9);

        for (i = 0; i < 3; i++) {
            create_particle_effect_2(
                (SSSV_RAND(16) + D_803D5530->position.xPos.h + tmp1) - 8,
                (SSSV_RAND(16) + D_803D5530->position.zPos.h + tmp2) - 8,
                 SSSV_RAND(16) + D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
                28,
                SSSV_RAND(4) + 4,
                0,
                0,
                0);
        }
    }
}

// ESA: func_800A3828
void func_8034B64C_75CCFC(s16 arg0, s16 arg1, s16 arg2) {
    if ((D_803F2EDE != 0) &&
        (((D_803D5530->unk162 != 4) && (D_803D5530->unk162 == 6)) || (D_803D5530->unk162 != 7)) &&
        ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4) || (D_803D552C->unk366 == 1))) {
        s16 tmp1 = ((((SIN(D_803D552C->heading)) >> 7) * ((D_803D5524->unkBE * arg1) >> 4)) >> 8);
        s16 tmp2 = ((((COS(D_803D552C->heading)) >> 7) * ((D_803D5524->unkBE * arg1) >> 4)) >> 8);
        create_particle_effect(
            D_803D5530->position.xPos.h + tmp1,
            D_803D5530->position.zPos.h + tmp2,
            D_803D5530->position.yPos.h + ((D_803D5524->unkBA * arg2) >> 4),
            25,
            (SIN(D_803D552C->heading) >> 7) << 8,
            (COS(D_803D552C->heading) >> 7) << 8,
            -0x8000,
            1,
            GPACK_RGBA5551(248, 248, 248, 0),
            GPACK_RGBA5551(248, 248, 248, 0),
            (RAND(arg0) >> 2) + arg0);
    }
}

void func_8034B848_75CEF8(s16 arg0) {
    s16 sp4E;
    s16 sp4C;
    s16 temp_a3;
    s16 temp_t7;
    s16 phi_t3;

    if (((arg0 == 0) || ((D_803D5540 & 2) == 0)) && ((D_803D5540 & 1) == 0)) {
        phi_t3 = 0;
        if (D_803D5530->state == 143) {
            phi_t3 = 2;
        } else if (D_803D5530->state == 142) {
            phi_t3 = 1;
        }
        if (phi_t3 != 0) {
            temp_a3 = -((SIN(D_803D552C->heading)) >> 7);
            temp_t7 = -((COS(D_803D552C->heading)) >> 7);
            sp4E = (temp_a3 * D_803D5524->unkBE) >> 8;
            sp4C = (temp_t7 * D_803D5524->unkBE) >> 8;

            create_particle_effect(
                D_803D5530->position.xPos.h + sp4E,
                D_803D5530->position.zPos.h + sp4C,
                MAX(func_80298E98_6AA548(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h), D_803D5530->position.yPos.h) + 10,
                24,
                (SSSV_RAND(33) + (phi_t3 * 3 * temp_a3)) << 7,
                (SSSV_RAND(33) + (phi_t3 * 3 * temp_t7)) << 7,
                (phi_t3 << 4) << 0xE,
                SSSV_RAND(16) + 4,
                GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
                GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
                0);
        }
    }
}

// ESA: func_800A3A38
void func_8034BB38_75D1E8(u8 arg0) {
    switch (D_803D5530->unk162) {
    case 1:
    case 2:
    case 3:
        if ((D_803D552C->unk36C != 0)) {
            D_803D552C->unk36C--;
            if (SSSV_RAND(32) == 17) {
                s16 tmp = D_803D5530->position.yPos.h - MAX(func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 16, D_803C0740[D_803D5530->position.xPos.h >> 16][D_803D5530->position.zPos.h >> 16].unk6 << 2);
                if (tmp > 10) {
                    create_particle_effect(
                        D_803D5530->position.xPos.h,
                        D_803D5530->position.zPos.h,
                        D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
                        24,
                        D_803D5530->xVelocity.w,
                        D_803D5530->zVelocity.w,
                        D_803D5530->yVelocity.w,
                        SSSV_RAND(8) + 4,
                        0,
                        0,
                        0);
                } else {
                    create_particle_effect_2(
                        D_803D5530->position.xPos.h,
                        D_803D5530->position.zPos.h,
                        D_803D5530->position.yPos.h - tmp,
                        99,
                        0,
                        0,
                        0,
                        SSSV_RAND(64) + 50);
                }
            }
        }
        break;
    default:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        D_803D552C->unk36C = arg0;
        break;
    }
}
