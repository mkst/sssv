#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/evo/func_80389B30_79B1E0.s")

// evo shellsuit function?
void func_8038B330_79C9E0(void) {
    s16 tmp;

    if (D_803D5530->unk162 != 1) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                SFX_UNKNOWN_103,
                0x7000,
                0,
                0.25f,
                D_803D552C->xPos.h,
                D_803D552C->zPos.h,
                D_803D552C->yPos.h);
        }

        if (D_803D5530->yVelocity.w > FTOFIX32(2.0)) {
            D_803D5530->yVelocity.w = MAX(D_803D5530->yVelocity.w + FTOFIX32(1.0), FTOFIX32(3.75));
        } else if (D_803D5530->yVelocity.w > FTOFIX32(-10.0)) {
            D_803D5530->yVelocity.w += FTOFIX32(1.875);
        } else {
            D_803D5530->yVelocity.w += FTOFIX32(4.0);
        }

        tmp = -16;
        do {
            // smoke
            create_particle_effect(
                (SSSV_RAND(16) + D_803D5530->xPos.h + ((tmp * (D_80152C78[(((s16)-D_803D552C->unk302) + 64) & 0xFF] >> 7)) >> 8)) - (0, 8),
                (SSSV_RAND(16) + D_803D5530->zPos.h + ((tmp * (D_80152C78[((s16)-D_803D552C->unk302) & 0xFF] >> 7)) >> 8)) - (0, 8),
                D_803D5530->yPos.h,
                (SSSV_RAND(2) + 25),
                (SSSV_RAND(FTOFIX32(0.5)) << 1) + D_803D5530->xVelocity.w + FTOFIX32(-0.6103515625),
                (SSSV_RAND(FTOFIX32(0.5)) << 1) + D_803D5530->zVelocity.w + FTOFIX32(-0.6103515625),
                (D_803D5530->yVelocity.w >> 1) + FTOFIX32(-3.0517578125),
                SSSV_RAND(13),
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(56, 56, 56, 1), // grey
                SSSV_RAND(16) + 15);

            // flames
            create_particle_effect(
                (SSSV_RAND(16) + D_803D5530->xPos.h + ((tmp * (D_80152C78[(((s16)-D_803D552C->unk302) + 64) & 0xFF] >> 7)) >> 8)) - (0, 8),
                (SSSV_RAND(16) + D_803D5530->zPos.h + ((tmp * (D_80152C78[((s16)-D_803D552C->unk302) & 0xFF] >> 7)) >> 8)) - (0, 8),
                D_803D5530->yPos.h,
                63,
                D_803D5530->xVelocity.w,
                D_803D5530->zVelocity.w,
                D_803D5530->yVelocity.w + FTOFIX32(-4.57763671875),
                SSSV_RAND(16) + 25,
                GPACK_RGBA5551(SSSV_RAND(64) + 192, SSSV_RAND(32) + 192, 0, 1), // red/orange
                GPACK_RGBA5551(SSSV_RAND(64) + 192, 0, 0, 1), // red
                0);

            tmp += 32;
        } while (tmp < 17);
    } else {
        recharge_skill(0);
    }
}

void func_8038B730_79CDE0(void) {
    D_803D5528->unk3C0.unk0 = 0;
    D_803D552C->unk30C = 1;
    if (D_803D5530->unk4A != 0) {
        D_803D552C->unk30C = 0;
    }
}

void func_8038B774_79CE24(void) {
    D_803D552C->unk30C = 0;
    D_803D552C->unk30E = 0;
    D_803D552C->unk310 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/evo/func_8038B798_79CE48.s")
// void func_8038B798_79CE48(void) {
//     s16 temp_a0;
//     struct036 *temp_v0;
//
//     temp_a0 = gCurrentAnimalIndex;
//     temp_v0 = (u8*)&D_801D9ED8 + 8 * temp_a0; // what is this variable?!
//     D_803D5520 = &temp_v0->unk3EB0;
//     D_803D5524 = &temp_v0->unk3EB0;
//     D_803D5528 = temp_v0->animal;
//     D_803D552C = temp_v0->animal;
//     D_803D5530 = temp_v0->animal;
//     D_803D5538 = 1;
//     D_803D553C = temp_a0;
//     D_803D553A = 0;
//     if (D_803D5530->unk162 == 1) {
//         func_802A6390_6B7A40();
//     }
// }
