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
//     s32 temp_a0;
//     s16 temp_a3;
//
//     struct078 *temp_s3;
//     struct078 *temp_v1_2;
//     s16 i;
//
//     if (D_803D5544 != D_803F2EF0) {
//         D_803F2EF0 = D_803D5544;
//
//         for (i = 0; i < 0x34; i++) {
//             temp_a0 = i * 0x10;
//             temp_v1_2 = ((s32)D_04002F28 & 0xFFFFFF) + D_801D9EC4 + temp_a0;
//             temp_s3 = ((s32)D_040029D0 & 0xFFFFFF) + D_801D9EC4 + temp_a0;
//             temp_a3 = temp_v1_2->unk0 * 0x10;
//
//             temp_s3->unk0 = ((((D_80152C78[(((temp_a3 + (D_803D5540 * 8)) & 0xFF))]) >> 7) * temp_v1_2->unk0) >> 0xC) + temp_v1_2->unk0;
//             temp_s3->unk2 = ((((D_80152C78[(((temp_a3 + (D_803D5540 * 8)) & 0xFF))]) >> 7) * temp_v1_2->unk2) >> 0xC) + temp_v1_2->unk2;
//             temp_s3->unk4 = ((((D_80152C78[(((temp_a3 + (D_803D5540 * 8)) & 0xFF))]) >> 7) * temp_v1_2->unk4) >> 0xC) + temp_v1_2->unk4;
//
//             temp_s0 = temp_v1_2->unkC + ((D_80152C78[(temp_a3 + (D_803D5540 * 8)) & 0xFF] >> 7) >> 2);
//             temp_s1 = temp_v1_2->unkD + ((D_80152C78[((temp_a3 + (D_803D5540 * 8)) + 0x40) & 0xFF] >> 7) >> 2);
//             temp_s2 = temp_v1_2->unkE - ((D_80152C78[(temp_a3 + (D_803D5540 * 8)) & 0xFF] >> 7) >> 2);
//
//             temp_t9 = sqrtf((temp_s0 * temp_s0) + (temp_s1 * temp_s1) + (temp_s2 * temp_s2));
//
//             temp_s3->unkC = (s16) ((temp_s0 * 0x7F) / temp_t9);
//             temp_s3->unkD = (s16) ((temp_s1 * 0x7F) / temp_t9);
//             temp_s3->unkE = (s16) ((temp_s2 * 0x7F) / temp_t9);
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_80362618_773CC8.s")
// JUSTREG
// void func_80362618_773CC8(void) {
//     s16 tmp;
//
//     if (D_803D552C->unk36D == 7) {
//         play_sound_effect_at_location(117, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//     }
//     if (D_803D552C->skillAEnergy[0] < 15) {
//         if (D_803D552C->unk365 != 45) {
//             tmp = D_803D5530->yPos - MAX(func_80310EE4_722594(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->unk160) >> 16, D_803C0740_7D1DF0[D_803D5530->xPos >> 16][D_803D5530->zPos >> 16].unk6 << 2);
//             if (tmp > 96) {
//                 D_803D552C->unk365 = 45;
//                 D_803D552C->unk32A = D_803D5544;
//                 play_sound_effect_at_location(107, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//             }
//         }
//     }
//     if (D_803D5530->unk162 == 3) {
//         if (D_803D552C->unk30E < 0) {
//             D_803D552C->unk30E = D_803D5540;
//         }
//         if (D_803D5530->unk162 != 1) {
//             if ((D_803D552C->unk36D == 0) || (D_803D552C->unk36D > 7)) {
//                 D_803D5530->yVelocity.w = ((((D_803D5530->yVelocity.w * 3) + 0x90000) >> 2) + 0xFFFD0000);
//             } else {
//                 D_803D5530->yVelocity.w = ((((D_803D5530->yVelocity.w * 15) + 0x2D0000) >> 4) + 0xFFFD0000);
//             }
//             if (D_803D5530->yVelocity.w < 0) {
//                 D_803D5530->yVelocity.w += (D_803A05B0_7B1C60 * 15) >> 4;
//             } else {
//                 D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
//             }
//             // this casting is likely nonsense, but 'helps' regalloc
//             D_803D5530->yVelocity.w += (D_80152C78[((u8)(((s16)(D_803D5540 - D_803D552C->unk30E) << 2) + 64))] >> 7) << 8;
//             D_803D5530->xVelocity.w += (D_80152C78[((u8)(D_803D5540 << 3) & 0xFF)& 0xFF] >> 7) << 8;
//             D_803D5530->zVelocity.w += (D_80152C78[((u8)((D_803D5540 << 2) + 64)& 0xFF)& 0xFF] >> 7) << 8;
//         }
//     } else {
//         recharge_skill(0);
//     }
// }

void func_80362964_774014(void) {
    if (D_803D5530->unk162 == 1) {
        D_803D552C->unk30E = -1;
    } else {
        D_803D552C->unk30E = (D_803D552C->unk30E + 1) & 0xFF;
    }
}

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
    D_803D552C->unk365 = 3;
    play_sound_effect_at_location(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
//
void ram_headbutt(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 3;
    play_sound_effect_at_location(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
