#include <ultra64.h>
#include "common.h"


s16 D_803A04F0_7B1BA0[8] = {0, 0, 0, 0, 1, 0, 0, 0};

// weird offsets
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802963D0_6A7A80.s")

void func_80296544_6A7BF4(void) {
    f64 temp_f20;
    f64 temp_f22;
    f64 temp_f24;

    u8 i;

    D_803C0430.unk202 = 0;
    D_803C0430.unk204 = 0;

    if (D_803F2D50.unk22 == 0) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 1;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 3;
        }
    }
    if ((D_803F2D50.unk22 == 1) || (D_803F2D50.unk22 == 2)) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 7;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80296C8C_6A833C.s")
// million miles away
// void func_80296C8C_6A833C(struct063 **arg0) {
//     s16 sp96;
//     s16 sp84;
//     s16 sp80;
//     s16 sp78;
//     // u32 sp64;
//     // s32 sp60;
//     s16 temp_s0_2;
//     s16 temp_s2;
//     // s16 temp_s2_2;
//     s16 temp_s2_4;
//     s16 temp_s3_2;
//     s16 temp_s4_2;
//     s16 temp_s7;
//     s16 temp_t0;
//     // s16 temp_t8;
//     s16 temp_v1_3;
//     s32 temp_s4;
//     s32 temp_s5;
//     s32 temp_t6;
//     s32 temp_t6_2;
//     s32 temp_v0_2;
//     s32 temp_v0_4;
//     u16 temp_a1;
//     u16 temp_v1;
//     u8 temp_a0;
//     u8 temp_a0_2;
//     u8 temp_a0_3;
//     u8 temp_s0;
//     u8 temp_s2_3;
//     u8 temp_s3;
//     u8 temp_v0;
//     // u8 temp_v0_3;
//     u8 temp_v1_2;
//     u8 temp_v1_4;
//     s16 phi_s7;
//     s32 phi_s3;
//     s16 phi_v1;
//     s16 phi_v1_2;
//     u8 phi_s2;
//     s32 phi_s0;
//     s16 phi_v1_3;
//     // s32 phi_v1_4;
//     s32 phi_s2_2;
//     u8 new_var;
//
//     D_803C063D = (D_803C063D + 1) & 3;
//     sp96 = D_803F2D50.unk10 + D_803F2D50.unk14;
//     sp78 = D_803F2D50.unk12 + D_803F2D50.unk16;
//     sp84 = D_803F2D50.unk10;
//     sp80 = D_803F2D50.unk12;
//
//     while (sp84 < sp96) {
//         while (sp80 < sp78) {
//             temp_v0 = arg0[sp96][sp78].unk6;
//             arg0[sp96][sp78].unk7 = 0U;
//             if (temp_v0 != 0) {
//                 temp_s3 = arg0[sp96+1][sp78].unk6; //.unk40E;
//                 if (SSSV_RAND(128) == 20) {
//                     func_802D7AD4_6E9184(
//                         (SSSV_RAND(64) + (sp96 << 6)),
//                         (SSSV_RAND(64) + (sp78 << 6)),
//                         (D_803C0740[sp96][sp78].unk0) * 8,
//                         0);
//                 }
//                 if (temp_s3 < temp_v0) {
//                     temp_v1_2 = arg0[sp96+1][sp78].unk0; //unk408;
//                     temp_v0_2 = temp_v1_2 * 2;
//                     if (temp_v0_2 < temp_v0) {
//                         phi_s3 = temp_s3;
//                         if (temp_s3 == 0) {
//                             if (D_803C063F == 0) {
//                                 phi_s3 = temp_v0_2;
//                             }
//                         }
//                         temp_a0 = arg0[sp96][sp78].unk0;
//                         if ((temp_v1_2 < (temp_a0 - 0x10)) && (phi_s3 < (temp_a0 * 2))) {
//                             phi_v1 = 0;
//                         } else {
//                             phi_v1 = (temp_v0 - phi_s3) / 2;
//                             if (phi_v1 >= 2) {
//                                 phi_v1 += SSSV_RAND(2);
//                             }
//                         }
//                         if (phi_v1 < 0) {
//                             phi_v1 = 0;
//                         }
//                         temp_s2 = temp_v0 - phi_v1;
//                         temp_s3_2 = phi_s3 + phi_v1;
//                         arg0[sp96][sp78].unk7 = (u8) ((arg0[sp96][sp78].unk7 & 0xF) + ((phi_v1 & 7) * 0x10));
//                         phi_s2 = temp_s2;
//                         if ((arg0[sp96][sp78].unk0 * 2) >= temp_s2) {
//                             phi_s2 = 0U;
//                         }
//                         if ((arg0[sp96+1][sp78].unk6 == 0) && (temp_s3_2 != 0)) { // unk40E
//                             arg0[sp96+1][sp78].unk4 |= 2;
//                         } else {
//                             arg0[sp96+1][sp78].unk4 &= ~2;
//                         }
//                         if ((arg0[sp96][sp78].unk6 != 0) && (phi_s2 == 0)) {
//                             arg0[sp96][sp78].unk4 |= 4;
//                         } else {
//                             arg0[sp96][sp78].unk4 &= ~4;
//                         }
//                         arg0[sp96][sp78].unk6 = phi_s2;
//                         arg0[sp96+1][sp78].unk6 = (u8) temp_s3_2; // unk40E
//                     }
//                 }
//                 temp_s2 = arg0[sp96][sp78].unk6;
//                 temp_s0 = arg0[sp96][sp78+1].unk6; // unkE ?
//                 phi_s0 = temp_s0;
//                 if (temp_s0 < temp_s2) {
//                     temp_v0 = arg0[sp96][sp78+1].unk0; // unk8
//                     if (((temp_v0 + 1) * 2) < (s32) temp_s2) {
//                         if ((temp_s0 == 0) && (D_803C063F == 0)) {
//                             phi_s0 = (temp_v0 * 2);
//                         }
//                         temp_a0_2 = arg0[sp96][sp78].unk0;
//                         temp_v0_4 = temp_a0_2 * 2;
//                         if ((temp_v0 < temp_a0_2) && (phi_s0 < temp_v0_4)) {
//                             phi_v1_3 = (temp_s2 - temp_v0_4);
//                         } else {
//                             phi_v1_3 = (temp_s2 - phi_s0) / 2;
//                             // phi_v1_3 = (s32) (s16) temp_t6_2;
//                             if (phi_v1_3 >= 2) {
//                                 phi_v1_3 += SSSV_RAND(2);
//                             }
//                         }
//                         // phi_v1_3 = phi_v1_3;
//                         if (phi_v1_3 <= 0) {
//                             phi_v1_3 = 0;
//                         }
//                         temp_s2 = temp_s2 - phi_v1_3;
//                         arg0[sp96][sp78].unk7 = ((arg0[sp96][sp78].unk7 & 0xF0) + (phi_v1_3 & 7));
//                         phi_s2_2 = (u8) temp_s2;
//                         if ((arg0[sp96][sp78].unk0 * 2) >= temp_s2) {
//                             phi_s2_2 = 0U;
//                         }
//                         arg0[sp96][sp78+1].unk6 = (s16) (phi_s0 + phi_v1_3); // unkE
//                         arg0[sp96][sp78].unk6 = phi_s2_2;
//                     }
//                 }
//                 if (((guRandom() % 31) == 4)) {
//                     temp_s4_2 = (guRandom() % 63) + (sp96 << 6);
//                     temp_s0_2 = (guRandom() % 63) + (sp78 << 6);
//
//                     if (((((1 - (((D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7 >> 4) & 8) >> 2)) * (((D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7 & 0xF0) >> 4) & 7)))) ||
//                          (((1 -  ((D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7       & 8) >> 2)) *   (D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7               & 7)))) {
//
//                         create_particle_effect(
//                             temp_s4_2,
//                             temp_s0_2,
//                             0,
//                             0xD,
//                             ((1 - (((D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7 >> 4) & 8) >> 2)) * (((D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7 & 0xF0) >> 4) & 7)) << 0x10,
//                             ((1 - ( (D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7       & 8) >> 2)) *  ( D_803C0740[temp_s4_2 >> 6][temp_s0_2 >> 6].unk7               & 7)) << 0x10,
//                             0,
//                             SSSV_RAND(4) + 4,
//                             0,
//                             0,
//                             0);
//                     }
//                 }
//             }
//             if ((arg0[sp96][sp78].unk0 * 2) >= (s32) arg0[sp96][sp78].unk6) {
//                 arg0[sp96][sp78].unk6 = 0U;
//             }
//             sp78--;
//         }
//         sp96--;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_8029726C_6A891C.s")
// void func_8029726C_6A891C(struct063 **arg0) {
//     s32 sp54;
//     u32 sp50;
//     u32 sp4C;
//     u32 sp44;
//     s16 temp_s0;
//     s16 temp_s0_2;
//     s16 temp_s4;
//     s16 temp_s7;
//     s32 temp_t3;
//     s32 temp_t4;
//     s32 temp_t6;
//     s32 temp_t8;
//     s32 temp_v0_3;
//     s32 temp_v0_4;
//     s32 temp_v0_5;
//     s32 temp_v0_6;
//     u16 temp_v0;
//     u16 temp_v1;
//     u8 temp_a0;
//     u8 temp_a0_2;
//     u8 temp_s2;
//     u8 temp_s2_2;
//     u8 temp_v0_2;
//     u8 temp_v1_2;
//     u8 temp_v1_3;
//     void *temp_s1;
//     s16 xPos;
//     s16 zPos;
//     s32 phi_s2;
//     s16 phi_v1;
//     u8 phi_s0;
//     s32 phi_s0_2;
//     s32 phi_s2_2;
//     s32 phi_v1_2;
//     s32 phi_v1_3;
//     s16 phi_s0_3;
//     u8 phi_s0_4;
//     s16 phi_v1_4;
//
//     // temp_v0 = D_803F2D50.unk10;
//     // temp_v1 = D_803F2D50.unk12;
//     sp50 = D_803F2D50.unk10 + D_803F2D50.unk14;
//     sp4C = D_803F2D50.unk12 + D_803F2D50.unk16;
//     xPos = D_803F2D50.unk10;
//     zPos = D_803F2D50.unk12;
//
//     while (xPos < sp50) {
//         while (zPos <= sp4C) {
//             temp_v0_2 = arg0[xPos][zPos].unk6;
//             if (temp_v0_2 != 0) {
//                 temp_s2 = arg0[xPos-1][zPos].unk6; //temp_s1->unk-402;
//                 phi_s2 = (s32) temp_s2;
//                 phi_s0_2 = (s32) (s16) temp_v0_2;
//                 if ((s32) temp_s2 < (s32) (s16) temp_v0_2) {
//                     temp_v1_2 = arg0[xPos+1][zPos].unk0; //temp_s1->unk-408;
//                     temp_v0_3 = temp_v1_2 * 2;
//                     if (temp_v0_3 < (s32) (s16) temp_v0_2) {
//                         if ((temp_s2 == 0) && (D_803C0430.unk20F == 0)) {
//                             phi_s2 = (s32) (s16) temp_v0_3;
//                         }
//                         temp_a0 = arg0[xPos][zPos].unk0; //temp_s1->unk0;
//                         temp_v0_4 = temp_a0 * 2;
//                         if (((s32) temp_v1_2 < (temp_a0 - 0x10)) && (phi_s2 < temp_v0_4)) {
//                             temp_t3 = (s32) ((s16) temp_v0_2 - temp_v0_4) / 2;
//                             phi_v1 = (s16) temp_t3;
//                             if ((s32) (s16) temp_t3 <= 0) {
//                                 phi_v1 = 0;
//                             }
//                         } else {
//                             temp_t8 = (s32) (((s16) temp_v0_2 - phi_s2) + (xPos & 1)) / 2;
//                             phi_v1 = (s16) temp_t8;
//                             if ((s32) (s16) temp_t8 >= 2) {
//                                 phi_v1 = (s16) ((s16) temp_t8 + SSSV_RAND(2));
//                             }
//                         }
//                         temp_s0 = (s16) temp_v0_2 - phi_v1;
//                         arg0[xPos][zPos].unk7 = (u8) (((arg0[xPos][zPos].unk7 & 0xF) + ((phi_v1 & 7) * 0x10)) | 0x80);
//                         phi_s0 = (u8) temp_s0;
//                         if ((arg0[xPos][zPos].unk0 * 2) >= (s32) temp_s0) {
//                             phi_s0 = 0U;
//                         }
//                         arg0[xPos][zPos].unk6 = phi_s0;
//                         arg0[xPos-1][zPos].unk6 = (u8) (s16) (phi_s2 + phi_v1); // temp_s1->unk-402
//                         phi_s0_2 = phi_s0 & 0xFF;
//                     }
//                 }
//                 temp_s2_2 = arg0[xPos][zPos-1].unk6; //temp_s1->unk-2;
//                 phi_s2_2 = (s32) temp_s2_2;
//                 if ((s32) temp_s2_2 < phi_s0_2) {
//                     temp_v1_3 = arg0[xPos][zPos-1].unk0; //temp_s1->unk-8;
//                     temp_v0_5 = temp_v1_3 * 2;
//                     if (temp_v0_5 < phi_s0_2) {
//                         if ((temp_s2_2 == 0) && (D_803C0430.unk20F == 0)) {
//                             phi_s2_2 = (s32) (s16) temp_v0_5;
//                         }
//                         temp_a0_2 = arg0[xPos][zPos].unk0; //temp_s1->unk0;
//                         temp_v0_6 = temp_a0_2 * 2;
//                         if (((temp_v1_3 + 4) < (s32) temp_a0_2) && (temp_v0_6 >= phi_s2_2)) {
//                             temp_t4 = (s32) (phi_s0_2 - temp_v0_6) / 2;
//                             phi_v1_4 = (s16) temp_t4;
//                             if ((s32) (s16) temp_t4 < 2) {
//                                 phi_v1_4 = 2;
//                             }
//                             phi_v1_2 = 0;
//                             phi_s0_2 = (s16) (phi_s0_2 - phi_v1_4);
//                         } else {
//                             temp_t6 = (s32) ((phi_s0_2 + (zPos & 1)) - phi_s2_2) / 2;
//                             phi_v1_2 = (s32) (s16) temp_t6;
//                             if ((s32) (s16) temp_t6 >= 2) {
//                                 phi_v1_2 = (s32) (s16) ((s16) temp_t6 + SSSV_RAND(2));
//                             }
//                         }
//                         phi_v1_3 = phi_v1_2;
//                         if (phi_v1_2 < 0) {
//                             phi_v1_3 = 0;
//                         }
//                         temp_s0_2 = phi_s0_2 - phi_v1_3;
//                         arg0[xPos][zPos].unk7 = (u8) (((arg0[xPos][zPos].unk7 & 0xF0) + (phi_v1_3 & 7)) | 8);
//                         phi_s0_4 = (u8) temp_s0_2;
//                         if ((arg0[xPos][zPos].unk0 * 2) >= (s32) temp_s0_2) {
//                             phi_s0_4 = 0U;
//                         }
//                         arg0[xPos][zPos].unk6 = phi_s0_4;
//                         arg0[xPos-1][zPos].unk6 = (u8) (s16) (phi_s2_2 + phi_v1_3); // temp_s1->unk-2
//                     }
//                 }
//             }
//             zPos++;
//         }
//         xPos++;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80297628_6A8CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802983D0_6A9A80.s")
// return is wrong
// s32 func_802983D0_6A9A80(void) {
//     if (MAX(D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6, D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6) >
//         MAX(D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6, D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6)) {
//
//         if (D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6 >
//             D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6) {
//             return 0;
//         } else {
//             return 0;
//         }
//     } else {
//         if (D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6 <
//             D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6) {
//             return 0;
//         } else {
//             return 0;
//         }
//     }
// }

// draw_water
void func_802985AC_6A9C5C(Gfx **dl) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_800DCC20[D_803C0430.unk202]);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 1024);
    gDPPipeSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(63));
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

    gDPSetEnvColor((*dl)++, D_803E1BBD, D_803E1BBE, D_803E1BBF, D_803F2D50.unk5B);

    gDPSetPrimColor((*dl)++, 128, D_803C0430.unk200, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2D50.unk57);
}

void func_8029877C_6A9E2C(void) {
    // maximum 64
    D_803C0430.unk204 += 1;
    D_803C0430.unk204 &= 0x3F;

    // maximum 255
    D_803C0430.unk200 += 64;
    if (D_803C0430.unk200 >= 256) {
        D_803C0430.unk200 &= 0xFF;
        D_803C0430.unk202 += 1;
        D_803C0430.unk202 &= 0xF;
    }

    D_803C0430.unk208 = 0;

    D_803C0430.unk206 += D_803C0430.unk20A;

    if (D_803C0430.unk206 == 240) {
        D_803C0430.unk20A = -8;
    }
    if (D_803C0430.unk206 == 0) {
        D_803C0430.unk20A = 8;
    }
    // maximum 31
    D_803C0430.unk20C += 1;
    D_803C0430.unk20C &= 0x1F;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298818_6A9EC8.s")
// miles away
// s16 func_80298818_6A9EC8(s16 arg0, s16 arg1) {
//     s32 temp_t1_2;
//     s32 temp_t9;
//
//     s16 phi_v1;
//     s16 phi_t3;
//     s16 phi_t4;
//     s16 phi_a2;
//
//     s16 a0, a1;
//
//     // s32 tmp0, tmp1, tmp2, tmp3;
//
//     temp_t1_2 = D_803C0430.unk204 + ((((arg0 >> 6) * (arg1 >> 6)) + ((arg0 >> 6) * (arg0 >> 6))) * 8);
//     phi_v1 = (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2) + D_803C0430.unk0[(((arg0 >> 6) * (arg1 >> 6)) + 0) & 7][(temp_t1_2 + 0) & 0x3F];
//     phi_t3 = (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2) + D_803C0430.unk0[(((arg0 >> 6) * (arg1 >> 6)) + 1) & 7][(temp_t1_2 + 8) & 0x3F];
//
//     temp_t9 = D_803C0430.unk204 + ((((arg0 >> 6) + (arg1 >> 6)) + (arg0 >> 6) + (arg0 >> 6)) * 8);
//     phi_t4 = (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2) + D_803C0430.unk0[(((arg0 >> 6) + (arg1 >> 6)) + 1) & 7][(temp_t9 + 16) & 0x3F];
//     phi_a2 = (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2) + D_803C0430.unk0[(((arg0 >> 6) + (arg1 >> 6)) + 0) & 7][(temp_t9 +  8) & 0x3F];
//
//     // is this necessary?
//     // tmp0 = phi_v1;
//     // tmp1 = phi_t3;
//     // tmp2 = phi_t4;
//     // tmp3 = phi_a2;
//
//     if (phi_v1 < 16) {
//         phi_v1 = MAX(phi_a2, MAX(phi_t4, phi_t3));
//     }
//     if (phi_t3 < 16) {
//         phi_t3 = MAX(phi_v1, MAX(phi_a2, phi_t4));
//     }
//     if (phi_t4 < 16) {
//         phi_t4 = MAX(phi_v1, MAX(phi_a2, phi_t3));
//     }
//     if (phi_a2 < 16) {
//         phi_a2 = MAX(phi_v1, MAX(phi_t4, phi_t3));
//     }
//
//     a0 = arg0 & 0x3F;
//     a1 = arg1 & 0x3F;
//
//     if (a0 < a1) {
//         return (phi_v1 + ((((phi_t4 - phi_t3) * a0) + ((phi_t3 - phi_v1) * a1)) >> 6));
//     } else {
//         return (phi_v1 + ((((phi_a2 - phi_v1) * a0) + ((phi_t4 - phi_a2) * a1)) >> 6));
//     }
// }

s16 func_80298B70_6AA220(s16 arg0, s16 arg1) {
    s16 temp_t3;
    s16 temp_v0;

    s16 temp_a2;
    s16 temp_a3;
    s16 temp_t0;
    s16 temp_v1;

    temp_v1 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2;
    temp_a2 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2;
    temp_a3 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2;
    temp_t0 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2;

    if ((temp_v1 + temp_a2 + temp_a3 + temp_t0) == 0) {
        return 0;
    }

    temp_v0 = arg0 & 0x3F;
    temp_t3 = arg1 & 0x3F;
    if (temp_v0 < temp_t3) {
        return (D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_a3 - temp_a2) * temp_v0) + ((temp_a2 - temp_v1) * temp_t3)) >> 6);
    } else {
        return (D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_t0 - temp_v1) * temp_v0) + ((temp_a3 - temp_t0) * temp_t3)) >> 6);
    }
}

void func_80298D44_6AA3F4(Animal *arg0) {
    s16 x;
    s16 z;
    s32 tmp;
    s32 tmp2;

    x = (((D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk7 & 0xF0) >> 4) & 7) * (1 - (((D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk7 >> 4) & 8) >> 2));
    z = (u16)(((D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk7       )     ) & 7) * (1 - (((D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk7     ) & 8) >> 2));

    if (x != 0) {
        tmp = (arg0->xVelocity.w - (x << 17));
        arg0->xVelocity.w -= tmp >> 1;
    }
    if (z != 0) {
        tmp2 = (arg0->zVelocity.w - (z << 17));
        tmp = tmp2; // regalloc fix
        arg0->zVelocity.w -= tmp >> 1;
    }
}

s32 func_80298E08_6AA4B8(s16 arg0, s16 arg1) {
    // equivalent to dividing by 64
    arg0 >>= 6;
    arg1 >>= 6;

    if ((arg0 < D_803F2D50.unk10) ||
        (arg1 < D_803F2D50.unk12) ||
        ((D_803F2D50.unk10 + D_803F2D50.unk14) < arg0) ||
        ((D_803F2D50.unk12 + (u16)D_803F2D50.unk16) < arg1)) {
        return 0;
    }

    return 1;
}

s16 func_80298E98_6AA548(s16 arg0, s16 arg1) {
    s16 tmp;
    s16 res;

    res = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;

    if (func_80298E08_6AA4B8(arg0, arg1)) {
        tmp = D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63];
        return res + tmp;
    } else {
        return res;
    }
}

s16 func_80298F78_6AA628(s16 arg0, s16 arg1) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 temp_t4;
    s16 temp_t6;

    func_80299640_6AACF0(arg0 >> 6, arg1 >> 6, &sp36, &sp34, &sp32, &sp30);
    temp_t4 = arg0 & 0x3F;
    temp_t6 = arg1 & 0x3F;
    if ((temp_t4 + temp_t6) < 64) {
        return sp36 + ((((sp32 - sp36) * temp_t4) + ((sp34 - sp36) * temp_t6)) >> 6);
    } else {
        return sp30 + ((((sp34 - sp30) * (64 - temp_t4)) + ((sp32 - sp30) * (64 - temp_t6))) >> 6);
    }
}

s16 func_802990A4_6AA754(s16 arg0, s16 arg1) {
    s16 tmp0;
    s16 tmp1;

    tmp0 = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;
    tmp1 = D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63] >> 1;

    return tmp0 + tmp1;
}

#ifdef NON_MATCHING
// tbd if equivalent
void func_80299140_6AA7F0(void) {
    s32 pad[2];
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s16 i, j;
    s32 maxPoint;
    s16 temp_a3;
    s16 maxX;
    s16 maxZ;
    s16 minX;
    s16 minZ;

    s32 tmp;

    s32 yDistance;
    s32 xDistance;
    s32 zDistance;

    s32 phi_v0;
    s16 phi_a1_2;

    maxPoint = 100000;

    minX = ((s32)D_803F28E0[D_803F2A98].unk74 >> 6) - 25;
    minZ = ((s32)D_803F28E0[D_803F2A98].unk78 >> 6) - 25;
    maxX = ((s32)D_803F28E0[D_803F2A98].unk74 >> 6) + 25;
    maxZ = ((s32)D_803F28E0[D_803F2A98].unk78 >> 6) + 25;

    if (minX < 4) {
        minX = 4;
    }
    if (minZ < 8) {
        minZ = 8;
    }
    if (maxX > 68) {
        maxX = 68;
    }
    if (maxZ > 104) {
        maxZ = 104;
    }

    for (i = minX; i <= maxX; i += 3) {
        for (j = minZ; j <= maxZ; j += 3) {
            temp_a3 = D_803C0740[i][j].unk6 << 2;
            if (temp_a3 != 0) {
                zDistance = ABS((j << 6) - (s16) D_803F28E0[D_803F2A98].unk78);
                xDistance = ABS((i << 6) - (s16) D_803F28E0[D_803F2A98].unk74);
                yDistance = ABS(temp_a3 - (s16) D_803F28E0[D_803F2A98].unk7C);

                // why is this not just ABS...
                phi_v0 = (yDistance + xDistance + zDistance);
                if (phi_v0 < 0) {
                    phi_v0 = -phi_v0;
                }

                if (phi_v0 < maxPoint) {
                    maxPoint = phi_v0;
                    sp5C = (i << 6); // new x
                    sp58 = (j << 6); // new z
                    sp54 = temp_a3;  // new y
                }
            }
        }
    }

    if (maxPoint != 100000) {
        if ((D_803F2D50.unk4C == 0) || (D_803F2D50.unk4C == 2)) {
            phi_a1_2 = 4 * MAX(MAX(D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6,
                               D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6),
                           MAX(D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6,
                               D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6));

            if (phi_a1_2 > (D_803F28E0[D_803F2A98].unk7C - 12.0f)) {
                func_8032CD70_73E420(&D_803C0634, SFX_UNKNOWN_12, 0x4718, 0, 0.28f, sp5C, sp58, sp54); // D_803BAD00_7CC3B0
            } else {
                func_8032CD70_73E420(&D_803C0634, SFX_UNKNOWN_12, 0x2800, 0, 1.0f, sp5C, sp58, sp54);
            }
        }
        if (D_803F2D50.unk4C == 1) {
            func_8032CD70_73E420(&D_803C0634, SFX_UNKNOWN_64, 0x7FFF, 0, 0.25f, sp5C, sp58, sp54);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80299140_6AA7F0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80299640_6AACF0.s")
// no idea
// void func_80299640_6AACF0(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
//     s16 temp_a0;
//     s16 temp_a0_2;
//     s16 temp_a1;
//     s16 temp_a2;
//     s16 temp_t7;
//     s16 temp_v0_2;
//     s16 temp_v1;
//
//     s16 temp_t6;
//     s16 temp_t7_2;
//
//     if (func_80298E08_6AA4B8(arg0 << 6, arg1 << 6) == 0) {
//         temp_a0 = D_803C0740[arg0 + 0][arg1 + 0].unk6 << 2;
//         temp_a1 = D_803C0740[arg0 + 0][arg1 + 1].unk6 << 2;
//         temp_a2 = D_803C0740[arg0 + 1][arg1 + 0].unk6 << 2;
//         temp_t7 = D_803C0740[arg0 + 1][arg1 + 1].unk6 << 2;
//
//         *arg2 = temp_a0;
//         if (*arg2 == 0) {
//             *arg2 = temp_a1;
//             if (*arg2 == 0) {
//                 *arg2 = temp_a2;
//                 if (*arg2 == 0) {
//                     *arg2 = temp_t7;
//                 }
//             }
//         }
//         *arg4 = temp_a2;
//         if (*arg4 == 0) {
//             *arg4 = temp_a0;
//             if (*arg4 == 0) {
//                 *arg4 = temp_t7;
//                 if (*arg4 == 0) {
//                     *arg4 = temp_a1;
//                 }
//             }
//         }
//         *arg3 = temp_a1;
//         if (*arg3 == 0) {
//             *arg3 = temp_t7;
//             if (*arg3 == 0) {
//                 *arg3 = temp_a0;
//                 if (*arg3 == 0) {
//                     *arg3 = temp_a2;
//                 }
//             }
//         }
//         *arg5 = temp_t7;
//         if (*arg5 == 0) {
//             *arg5 = temp_a1;
//             if (*arg5 == 0) {
//                 *arg5 = temp_a2;
//                 if (*arg5 == 0) {
//                     *arg5 = temp_a0;
//                 }
//             }
//         }
//
//         *arg2 += D_803C0430.unk0[((arg0 + 0) * (arg1 + 0)) & 7][(u16)(D_803C0430.unk204 + ((((arg0 + 0) * (arg1 + 0)) + ((arg0 + 0) * (arg0 + 0))) << 3)) & 63] << 1; // * 2;
//         *arg4 += D_803C0430.unk0[((arg0 + 1) * (arg1 + 0)) & 7][(u16)(D_803C0430.unk204 + ((((arg0 + 1) * (arg1 + 0)) + ((arg0 + 1) * (arg0 + 1))) << 3)) & 63] << 1; // * 2;
//         *arg3 += D_803C0430.unk0[((arg0 + 0) * (arg1 + 1)) & 7][(u16)(D_803C0430.unk204 + ((((arg0 + 0) * (arg1 + 1)) + ((arg0 + 0) * (arg0 + 0))) << 3)) & 63] << 1; // * 2;
//         *arg5 += D_803C0430.unk0[((arg0 + 1) * (arg1 + 1)) & 7][(u16)(D_803C0430.unk204 + ((((arg0 + 1) * (arg1 + 1)) + ((arg0 + 1) * (arg0 + 1))) << 3)) & 63] << 1; // * 2;
//     } else {
//         temp_v1 = arg1 - D_803F2D50.unk12;
//         temp_v0_2 = D_803F2D50.unk14 + 1;
//         temp_a0_2 = arg0 - D_803F2D50.unk10;
//         // temp_t7_2 = ((temp_v1 * temp_v0_2) + temp_a0_2); // * 0x10;
//         // temp_t6 = (((temp_v1 + 1) * temp_v0_2) + temp_a0_2); // * 0x10;
//         *arg2 = D_80204278->unk286E4[(((temp_v1 + 0) * temp_v0_2) + temp_a0_2) * 8];
//         *arg3 = D_80204278->unk286E4[(((temp_v1 + 1) * temp_v0_2) + temp_a0_2) * 8];
//         *arg4 = D_80204278->unk286F4[(((temp_v1 + 0) * temp_v0_2) + temp_a0_2) * 8];
//         *arg5 = D_80204278->unk286F4[(((temp_v1 + 1) * temp_v0_2) + temp_a0_2) * 8];
//     }
// }
