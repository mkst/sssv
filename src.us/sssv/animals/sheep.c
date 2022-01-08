#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_8035FE90_771540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_80360D94_772444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_803622DC_77398C.s")
// NON-MATCHING: miles away
// void func_803622DC_77398C(void) {
//
//     s16 temp_s0;
//     s16 temp_s1;
//     s16 temp_s2;
//
//     s16 temp_t9;
//     s16 temp_a3;
//
//     Vtx *temp_s3;
//     Vtx *temp_v1_2;
//     s16 i;
//
//     if (D_803D5544 != D_803F2EF0) {
//         Vtx **base, **base2;
//         D_803F2EF0 = D_803D5544;
//
//         base = D_801D9EC4 + ((s32)D_04002F28_CA958 & 0xFFFFFF);
//         base2 = D_801D9EC4 + ((s32)D_040029D0_CA400 & 0xFFFFFF);
//
//         for (i = 0; i < 52; i++) {
//             temp_v1_2 = base[i];
//             temp_s3 = base2[i];
//
//             temp_a3 = temp_v1_2->v.ob[0] * 0x10;
//
//             temp_s3->v.ob[0] = ((((D_80152C78[(((temp_a3 + (D_803D5540 * 8)) & 0xFF))]) >> 7) * temp_v1_2->v.ob[0]) >> 0xC) + temp_v1_2->v.ob[0];
//             temp_s3->v.ob[1] = ((((D_80152C78[(((temp_a3 + (D_803D5540 * 8)) & 0xFF))]) >> 7) * temp_v1_2->v.ob[1]) >> 0xC) + temp_v1_2->v.ob[1];
//             temp_s3->v.ob[2] = ((((D_80152C78[(((temp_a3 + (D_803D5540 * 8)) & 0xFF))]) >> 7) * temp_v1_2->v.ob[2]) >> 0xC) + temp_v1_2->v.ob[2];
//
//             temp_s0 = temp_v1_2->v.cn[0] + ((D_80152C78[(temp_a3 + (D_803D5540 * 8)) & 0xFF] >> 7) >> 2);
//             temp_s1 = temp_v1_2->v.cn[1] + ((D_80152C78[((temp_a3 + (D_803D5540 * 8)) + 64) & 0xFF] >> 7) >> 2);
//             temp_s2 = temp_v1_2->v.cn[2] - ((D_80152C78[(temp_a3 + (D_803D5540 * 8)) & 0xFF] >> 7) >> 2);
//
//             temp_t9 = sqrtf((temp_s0 * temp_s0) + (temp_s1 * temp_s1) + (temp_s2 * temp_s2));
//
//             temp_s3->v.cn[0] = (s16) ((temp_s0 * 0x7F) / temp_t9);
//             temp_s3->v.cn[1] = (s16) ((temp_s1 * 0x7F) / temp_t9);
//             temp_s3->v.cn[2] = (s16) ((temp_s2 * 0x7F) / temp_t9);
//         }
//     }
// }

void func_80362618_773CC8(void) {
    s16 tmp;

    if (D_803D552C->unk36D == 7) {
        play_sound_effect_at_location(SFX_SHEEP_FLOAT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
    if (D_803D552C->skillAEnergy[0] < 15) {
        if (D_803D552C->unk365 != ATTACK_SHEEP_FLOAT) {
            tmp = D_803D5530->yPos - MAX(func_80310EE4_722594(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->unk160) >> 16, D_803C0740[D_803D5530->xPos >> 16][D_803D5530->zPos >> 16].unk6 << 2);
            if (tmp > 96) {
                D_803D552C->unk365 = ATTACK_SHEEP_FLOAT;
                D_803D552C->unk32A = D_803D5544;
                play_sound_effect_at_location(SFX_SHEEP_HURT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
            }
        }
    }
    if (D_803D5530->unk162 == 3) {
        if (D_803D552C->unk30E < 0) {
            D_803D552C->unk30E = D_803D5540;
        }
        if (D_803D5530->unk162 != 1) {
            if ((D_803D552C->unk36D == 0) || (D_803D552C->unk36D > 7)) {
                D_803D5530->yVelocity.w = ((((D_803D5530->yVelocity.w * 3) + FTOFIX32(9.0)) >> 2) + FTOFIX32(-3.0));
            } else {
                D_803D5530->yVelocity.w = ((((D_803D5530->yVelocity.w * 15) + FTOFIX32(45.0)) >> 4) + FTOFIX32(-3.0));
            }
            if (D_803D5530->yVelocity.w < 0) {
                D_803D5530->yVelocity.w += (D_803A05B0_7B1C60 * 15) >> 4;
            } else {
                D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
            }
            D_803D5530->yVelocity.w += (D_80152C78[((s16)((D_803D5540 - D_803D552C->unk30E) << 2) + 64) & 0xff] >> 7) << 8;
            D_803D5530->xVelocity.w += (D_80152C78[((s16)(D_803D5540 << 3)) & 0xff] >> 7) << 8;
            D_803D5530->zVelocity.w += (D_80152C78[(((s16)(D_803D5540 << 2)) + 64) & 0xff] >> 7) << 8;
        }
    } else {
        recharge_skill(0);
    }
}

void func_80362964_774014(void) {
    if (D_803D5530->unk162 == 1) {
        D_803D552C->unk30E = -1;
    } else {
        D_803D552C->unk30E = (D_803D552C->unk30E + 1) & 0xFF;
    }
}

// sheep / springy thing
void func_803629B0_774060(void) {
    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 5)) {
        func_8037FEDC_79158C();
    } else {
        recharge_skill(1);
    }
}

void func_80362A00_7740B0(void) {
}

void func_80362A08_7740B8(void) {
}

// springy_ram_headbutt (or vice versa?)
void func_80362A10_7740C0(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SHEEP_HEADBUTT;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
//
void ram_headbutt(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SHEEP_HEADBUTT;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
