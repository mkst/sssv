#include <ultra64.h>
#include "common.h"


void func_8034A5D0_75BC80(void) {
    func_802D760C_6E8CBC(
        D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void func_8034A60C_75BCBC(void) {
    func_802D760C_6E8CBC(
        D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void func_8034A648_75BCF8(void) {
    func_802D760C_6E8CBC(
        D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

// spawn 'dizzy' stars (lots)
void func_8034A684_75BD34(void) {
    s16 i;
    s16 sp64;

    sp64 = func_8012826C() & 0xFF;
    for (i = 0; i < 8; i++) {
        create_particle_effect(
            D_803D5530->xPos + (((D_80152C78[(s16)((i << 5) + sp64) & 0xFF] >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->zPos + (((D_80152C78[((s16)((i << 5) + sp64) + 64) & 0xFF] >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->yPos + D_803D5524->unkBA,
            36,
            ((D_80152C78[(s16)((i << 5) + sp64) & 0xFF] >> 7) << 9) + (D_803D5530->xVelocity.w >> 1),
            ((D_80152C78[((s16)((i << 5) + sp64) + 64) & 0xFF] >> 7) << 9) + (D_803D5530->zVelocity.w >> 1),
            ((func_8012826C() & 0x7FFF) << 2) + FTOFIX32(3.0),
            8,
            (((D_803A8350_7B9A00[i] << 8) & 0xF800) | ((D_803A8358_7B9A08[i] << 3) & 0x7C0) | ((D_803A8360_7B9A10[i] >> 2) & 0x3E) | 1),
            (((D_803A8350_7B9A00[i] << 8) & 0xF800) | ((D_803A8358_7B9A08[i] << 3) & 0x7C0) | ((D_803A8360_7B9A10[i] >> 2) & 0x3E) | 1),
            0);
        create_particle_effect(
            ((func_8012826C() & 0x1F) + D_803D5530->xPos) - 16,
            ((func_8012826C() & 0x1F) + D_803D5530->zPos) - 16,
            (func_8012826C() & 0x1F) + D_803D5530->yPos + (D_803D5524->unkBA >> 1),
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

// spawn 'dizzy' stars (medium)
void func_8034A914_75BFC4(void) {
    s16 i;
    s16 sp64;

    sp64 = func_8012826C() & 0xFF;
    for (i = 0; i < 4; i++) {
        create_particle_effect(
            D_803D5530->xPos + (((D_80152C78[(s16)((i << 6) + sp64) & 0xFF] >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->zPos + (((D_80152C78[((s16)((i << 6) + sp64) + 64) & 0xFF] >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->yPos + D_803D5524->unkBA,
            36,
            ((D_80152C78[(s16)((i << 6) + sp64) & 0xFF] >> 7) << 9) + (D_803D5530->xVelocity.w >> 1),
            ((D_80152C78[((s16)((i << 6) + sp64) + 64) & 0xFF] >> 7) << 9) + (D_803D5530->zVelocity.w >> 1),
            ((func_8012826C() & 0x7FFF) << 1) + FTOFIX32(3.0),
            6,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1),
            0);
        create_particle_effect(
            ((func_8012826C() & 0x1F) + D_803D5530->xPos) - 16,
            ((func_8012826C() & 0x1F) + D_803D5530->zPos) - 16,
            (func_8012826C() & 0x1F) + D_803D5530->yPos + (D_803D5524->unkBA >> 1),
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

// spawn 'dizzy' stars (small)
void func_8034ABA4_75C254(void) {
    s16 i;
    s16 sp64;

    sp64 = func_8012826C() & 0xFF;
    for (i = 0; i < 2; i++) {
        create_particle_effect(
            D_803D5530->xPos + (((D_80152C78[(s16)((i << 6) + sp64) & 0xFF] >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->zPos + (((D_80152C78[((s16)((i << 6) + sp64) + 64) & 0xFF] >> 7) * D_803D5524->unkBE) >> 9),
            D_803D5530->yPos + D_803D5524->unkBA,
            36,
            ((D_80152C78[(s16)((i << 6) + sp64) & 0xFF] >> 7) << 9) + (D_803D5530->xVelocity.w >> 1),
            ((D_80152C78[((s16)((i << 6) + sp64) + 64) & 0xFF] >> 7) << 9) + (D_803D5530->zVelocity.w >> 1),
            ((func_8012826C() & 0x7FFF) << 1) + FTOFIX32(3.0),
            4,
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1), //
            GPACK_RGBA5551(D_803A8350_7B9A00[i], D_803A8358_7B9A08[i], D_803A8360_7B9A10[i], 1), //
            0);
        create_particle_effect(
            ((func_8012826C() & 0x1F) + D_803D5530->xPos) - 16,
            ((func_8012826C() & 0x1F) + D_803D5530->zPos) - 16,
            (func_8012826C() & 0x1F) + D_803D5530->yPos + (D_803D5524->unkBA >> 1),
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

void func_8034AE34_75C4E4(s32 arg0, s32 arg1) {
    s16 temp_v0;
    s16 i;

    for (i = 0; i < 2; i++) {
        temp_v0 = func_8012826C();
        if (temp_v0 & 1) {
            create_particle_effect(
                (D_803D5530->xPos + (temp_v0 & 0xF)) - 8,
                (D_803D5530->zPos + ((temp_v0 >> 8) & 0xF)) - 8,
                D_803D5530->yPos,
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

void func_8034AF0C_75C5BC(s32 arg0, s32 arg1) {
    u16 temp_v0;
    u16 i;

    for (i = 0; i < 4; i++) {
        temp_v0 = func_8012826C();
        if ((temp_v0 & 1) != 0) {
            create_particle_effect(
                (D_803D5530->xPos + (temp_v0 & 0xF)) - 8,
                (D_803D5530->zPos + ((temp_v0 & 0xF0) >> 4)) - 8,
                D_803D5530->yPos,
                20,
                arg0,
                arg1,
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

// matrix
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034B008_75C6B8.s")

void func_8034B298_75C948(s16 arg0) {
    s16 sp2E;
    s16 sp2C;

    if ((arg0 == 0) || ((D_803D5540 & 2) == 0)) {
        if ((D_803D5530->state == 143) || (((D_803D5530->state == 142) || (D_803D5530->state == 144)) && ((D_803D5540 & 1) != 0))) {
            sp2E = (((func_8012826C() & 0xF) - 7) * (u16)D_803D5524->unkBE) >> 3;
            sp2C = (((func_8012826C() & 0xF) - 7) * (u16)D_803D5524->unkBE) >> 3;
            func_802D5B88_6E7238(D_803D5530->xPos + sp2E, D_803D5530->zPos + sp2C, D_803D5530->yPos, 28, (func_8012826C() & 3) + 4, 0, 0, 0);
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

void func_8034B45C_75CB0C(void) {
    s16 i = 0;

    if (((func_8012826C() & 0x7F) == 73) &&
        ((D_803D5530->unk162 == 4) || (D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) &&
        ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4) || (D_803D552C->unk366 == 1))) {

        s16 tmp1 = (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * D_803D5524->unkBE * 3) >> 9);
        s16 tmp2 = (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * D_803D5524->unkBE * 3) >> 9);

        for (i = 0; i < 3; i++) {
            func_802D5B88_6E7238(
                ((func_8012826C() & 0xF) + D_803D5530->xPos + tmp1) - 8,
                ((func_8012826C() & 0xF) + D_803D5530->zPos + tmp2) - 8,
                 (func_8012826C() & 0xF) + D_803D5530->yPos + (D_803D5524->unkBA >> 1),
                28,
                (func_8012826C() & 3) + 4,
                0,
                0,
                0);
        }
    }
}

void func_8034B64C_75CCFC(s16 arg0, s16 arg1, s16 arg2) {
    if ((D_803F2EDE != 0) &&
        (((D_803D5530->unk162 != 4) && (D_803D5530->unk162 == 6)) || (D_803D5530->unk162 != 7)) &&
        ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4) || (D_803D552C->unk366 == 1))) {
        s16 tmp1 = ((((D_80152C78[D_803D552C->unk302 & 0xFF]) >> 7) * ((D_803D5524->unkBE * arg1) >> 4)) >> 8);
        s16 tmp2 = ((((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF]) >> 7) * ((D_803D5524->unkBE * arg1) >> 4)) >> 8);
        create_particle_effect(
            D_803D5530->xPos + tmp1,
            D_803D5530->zPos + tmp2,
            D_803D5530->yPos + ((D_803D5524->unkBA * arg2) >> 4),
            25,
            (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) << 8,
            (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) << 8,
            -0x8000,
            1,
            GPACK_RGBA5551(248, 248, 248, 0),
            GPACK_RGBA5551(248, 248, 248, 0),
            ((guRandom() % arg0) >> 2) + arg0);
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
            temp_a3 = -((D_80152C78[D_803D552C->unk302 & 0xFF]) >> 7);
            temp_t7 = -((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF]) >> 7);
            sp4E = (temp_a3 * D_803D5524->unkBE) >> 8;
            sp4C = (temp_t7 * D_803D5524->unkBE) >> 8;

            create_particle_effect(
                D_803D5530->xPos + sp4E,
                D_803D5530->zPos + sp4C,
                MAX(func_80298E98_6AA548(D_803D5530->xPos, D_803D5530->zPos), D_803D5530->yPos) + 10,
                24,
                ((func_8012826C() & 0x20) + (phi_t3 * 3 * temp_a3)) << 7,
                ((func_8012826C() & 0x20) + (phi_t3 * 3 * temp_t7)) << 7,
                (phi_t3 << 4) << 0xE,
                (func_8012826C() & 0xF) + 4,
                GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
                GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
                0);
        }
    }
}

void func_8034BB38_75D1E8(u8 arg0) {
    switch (D_803D5530->unk162) {
    case 1:
    case 2:
    case 3:
        if ((D_803D552C->unk36C != 0)) {
            D_803D552C->unk36C--;
            if ((func_8012826C() & 0x1F) == 17) {
                s16 tmp = D_803D5530->yPos - MAX(func_80310EE4_722594(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->unk160) >> 16, D_803C0740_7D1DF0[D_803D5530->xPos >> 16][D_803D5530->zPos >> 16].unk6 << 2);
                if (tmp > 10) {
                    create_particle_effect(
                        D_803D5530->xPos,
                        D_803D5530->zPos,
                        D_803D5530->yPos + (D_803D5524->unkBA >> 1),
                        24,
                        D_803D5530->xVelocity.w,
                        D_803D5530->zVelocity.w,
                        D_803D5530->yVelocity.w,
                        (func_8012826C() & 7) + 4,
                        0,
                        0,
                        0);
                } else {
                    func_802D5B88_6E7238(
                        D_803D5530->xPos,
                        D_803D5530->zPos,
                        D_803D5530->yPos - tmp,
                        99,
                        0,
                        0,
                        0,
                        (func_8012826C() & 0x3F) + 50);
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
