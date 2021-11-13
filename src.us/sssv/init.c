#include <ultra64.h>

#include "common.h"


void load_ingame_objects(void) {
    s32 pad[2];
    u32 len = D_0007F790 - D_000398D0;

    if (len >= D_80099600 - D_8004B400) {
        // "\nASSERT: len < (_gfxdlistSegmentEnd - _gfxdlistSegmentStart), %s, %u\n"
        // "../src/init.c"
        rmonPrintf(D_803BE9F0, D_803BEA38, 93);
        // die
        *(volatile int*)0 = 0;
    }
    D_801D9E74 = &D_8004B400;
    dma_read(D_000398D0, D_801D9E74, len);
}

void load_water_texture(void) {
    s32 pad[2];
    u32 len = D_00546BC0 - D_005449C0;

    if (len >= 0x2201U) {
        // "\nASSERT: len <= sizeof(WaterTexture), %s, %u\n"
        // "../src/init.c"
        rmonPrintf(D_803BEA48, D_803BEA78, 115);
        *(volatile int*)0 = 0;
    }
    dma_read(D_005449C0, &D_800DCC20, len);
}

// 2000 lines
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80352380_763A30.s")

void func_8034B45C_75CB0C();
void func_8035D120_76E7D0();
void func_8035DA60_76F110();
void func_8035D734_76EDE4();
void func_8035D6D0_76ED80();
extern u8 D_803A843C_7B9AEC[]; // tbd
extern u8 D_803A8450_7B9B00[];

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80354188_765838.s")
// void func_80354188_765838(void) {
//     s32 sp9C;
//     s16 sp90[4];
//     s16 sp8C;
//     s16 sp88;
//
//     s32 temp_a3;
//     u8 temp_t0;
//     u16 temp_t1;
//     s32 temp_t6_2;
//     s32 temp_t9;
//     s32 temp_t9_3;
//     u32 phi_v0;
//     s8 phi_v0_2;
//
//     s8 phi_a1;
//     s8 phi_t1;
//     s8 phi_v1;
//     s16 phi_v1_6;
//     s16 phi_v1_7;
//     s16 phi_v0_3;
//     s16 phi_v1_8;
//     s16 phi_t4;
//     s32 phi_t3;
//     s32 phi_t0;
//
//     if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
//         if ((D_803D5540 & 1) == 0) {
//             create_particle_effect(
//                 D_803D5530->xPos,
//                 D_803D5530->zPos,
//                 D_803D5530->yPos + (D_803D5530->unk42 >> 2),
//                 21,
//                 0,
//                 0,
//                 (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
//                 30,
//                 GPACK_RGBA5551(0, 0, 0, 1),
//                 GPACK_RGBA5551(0, 0, 0, 1),
//                 0);
//         }
//         D_803D552C->unk2EC--;
//         if (D_803D552C->unk2EC <= 0) {
//             D_803D552C->unk36E = 0;
//         }
//     }
//     temp_t0 = D_803D552C->unk310; // & 0xFF;
//     phi_v1 = D_803D552C->unk310 >> 8;
//     if (D_803D5538 != 0) {
//         phi_v0 = D_801E9EB2;
//     } else {
//         phi_v0 = MIN(D_803D552C->unk368 >> 2, 18);
//     }
//     switch (phi_v0) {
//     case 0:
//         phi_v0_2 = -5;
//         phi_a1 = 0;
//         phi_t1 = temp_t0;
//         break;
//     case 1:
//         phi_v0_2 = 2;
//         phi_a1 = 0;
//         phi_t1 = temp_t0;
//         break;
//     case 2:
//         phi_v0_2 = 5;
//         phi_a1 = 10;
//         phi_t1 = temp_t0;
//         break;
//     case 3:
//         phi_v0_2 = 8;
//         phi_a1 = 20;
//         phi_t1 = MAX(temp_t0, 95); // tbd
//         // phi_t1 = temp_t0;
//         // if (temp_t0 < 95) {
//         //     phi_t1 = 95;
//         // }
//         break;
//     default:
//         phi_v0_2 = 11;
//         phi_a1 = 30;
//         phi_t1 = MAX(temp_t0, 110);
//         // phi_t1 = temp_t0;
//         // if (temp_t0 < 110) {
//         //     phi_t1 = 110;
//         // }
//         break;
//     }
//
//     // phi_v1 vs temp_v1_2 ?
//     if (phi_v1 < phi_v0_2) {
//         phi_v1 = MIN(phi_v1 + 5, phi_v0_2);
//     } else if (phi_v0_2 < phi_v1) {
//         phi_v1 = MAX(phi_v1 - 1, phi_v0_2);
//     }
//     if (phi_v1 > 3) {
//         phi_v1 -= 1;
//     }
//     if (phi_v1 > 6) {
//         phi_v1 -= 1;
//     }
//     if (phi_v1 < -3) {
//         phi_v1 += 1;
//     }
//     if (phi_v1 < -6) {
//         phi_v1 += 1;
//     }
//
//     if ((phi_a1 + 110) < phi_t1) {
//         phi_v1 -= ((phi_t1 - phi_a1) - 110) / 5;
//     }
//     if (phi_t1 < 20) {
//         phi_v1 += (20 - phi_t1) / 2;
//     }
//
//     temp_t1 = (phi_t1 + phi_v1) & 0xFF;
//     D_803D552C->unk310 = (s16) ((phi_v1 << 8) | temp_t1);
//     // temp_a1 = D_803D5538;
//     phi_v1_6 = 0;
//     // phi_a1_2 = temp_a1;
//     phi_v1_7 = 0;
//     phi_v1_8 = 0;
//     if (D_803D5538 != 0) {
//         phi_v1_6 = D_803D554C << 1; // (s32) (D_803D554C << 17) >> 16;
//     }
//     if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 4)) {
//         if (D_803D5530->unk4A == 0) {
//             func_8032CD70_73E420(
//                 D_803D5530,
//                 100,
//                 ((temp_t1 / 300.0) + 0.3) * 20480.0,
//                 0,
//                 ((temp_t1 + phi_v1_6) / 200.0) + 0.3,
//                 D_803D5530->xPos,
//                 D_803D5530->zPos,
//                 D_803D5530->yPos);
//         }
//     }
//     if (D_803D5538 != 0) {
//         // temp_v1_3 = D_803F2D70;
//         // temp_v0_4 = D_803D5524->unkD6;
//         if ((D_803F2D70 == D_803D5524->unkD6) ||
//             ((D_803D5524->unkD6 == 0) && ((D_803F2D70 == 4) || (D_803F2D70 == 5)))) {
//             phi_v1_7 = 1;
//         }
//         if (phi_v1_7 != 0) {
//             sp88 = 0;
//             D_803F2EDD = 0;
//         } else {
//             goto block_57;
//         }
//     } else {
// block_57:
//         // temp_t0_2 = D_803D5524;
//         // temp_v1_4 = D_803F2D70;
//         // temp_v0_5 = D_803D5524->unkD6;
//         // temp_t2_3 = D_803D552C;
//         if ((D_803F2D70 == D_803D5524->unkD6) ||
//             ((D_803D5524->unkD6 == 0) && ((D_803F2D70 == 4) || (D_803F2D70 == 5)))) {
//             phi_v0_3 = 1;
//         } else {
//             phi_v0_3 = 0;
//         }
//         sp88 = func_802E89F0_6FA0A0(
//             *(s32*)&D_803D552C->xPos,
//             *(s32*)&D_803D552C->zPos,
//             *(s32*)&D_803D552C->yPos + (D_803D5524->unkBA << 0xF),
//             0x740,
//             0,
//             0,
//             0x5A,
//             0,
//             1,
//             phi_v0_3 == 0);
//     }
//     if (sp88 == 0) {
//         func_8034B45C_75CB0C();
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if ((D_803F2ECE == 0) || (((D_803F2ECC < 31)))) {
//             if (D_803D5538 != 0) {
//                 phi_v1_8 = ((D_803D554C * 362) / 20);
//             }
//             // sp86 = phi_v1_8;
//             func_802B9130_6CA7E0(sp90, 453, 308, 498, 0);
//             D_80203FE0[5].unk4 += 271;
//             D_80203FE0[6].unk4 += 271;
//             D_80203FE0[0].unk4 += 135;
//             func_802C18FC_6D2FAC(phi_v1_8 + 362, 634, sp90);
//             func_802B964C_6CACFC();
//             D_80203FE0[0].unk4 += phi_v1_8 >> 1;
//             D_80203FE0[1].unk4 += phi_v1_8;
//             func_802C5EF4_6D75A4(181, 362);
//             func_8038CCF0_79E3A0(90, 20, -1, -1, -1, -1);
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {
//             case 1:
//                 func_802DB670_6ECD20(&D_803A843C_7B9AEC, &D_803A8450_7B9B00, &D_803A8464_7B9B14, &D_803A8484_7B9B34);
//                 break;
//             case 2:
//                 func_802DB670_6ECD20(&D_803A843C_7B9AEC, &D_803A8450_7B9B00, &D_803A8464_7B9B14, &D_803A84CC_7B9B7C);
//                 break;
//             }
//         }
//         func_8038064C_791CFC();
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || ((D_803F2AA2 == 0)) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 > 10))) && ((D_803F2C18 != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].unk0 != 3)) && (D_803F28E0[D_803F2A98].unk0 != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
//
//             func_80127640(
//                 &D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)],
//                 *(s32*)&D_803D5530->xPos,
//                 *(s32*)&D_803D5530->zPos,
//                 *(s32*)&D_803D5530->yPos,
//                 -(s32) D_803D552C->unk302,
//                 D_803F2EB0 / 4,
//                 D_803F2EB4 / 4,
//                 D_803F2EB8 / 4,
//                 D_803F2ED2,
//                 D_803F2ED4);
//             gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//
//             D_80204278->usedModelViewMtxs++;
//
//             switch (D_803D5530->state) {
//             case 22:
//             case 24:
//                 phi_t4 = 0;
//                 temp_t9 = D_803D5540 * 8;
//                 temp_t6_2 = (temp_t9 & 0xFF) << 5;
//                 phi_t3 = ((temp_t9 + 0x80) & 0xFF) << 5;
//                 if (temp_t6_2 == 0) {
//                     phi_t4 = -5;
//                 }
//                 if (phi_t3 == 0) {
//                     phi_t4 = 5;
//                 }
//                 phi_t0 = temp_t6_2 + FTOFIX32(1.0);
//                 phi_t3 = phi_t3 + FTOFIX32(1.0);
//                 break;
//             case 23:
//                 phi_t4 = 0;
//                 temp_t9 = D_803D5540 * 16;
//                 temp_t6_2 = (temp_t9 & 0xFF) << 6;
//                 phi_t3 = ((temp_t9 + 0x80) & 0xFF) << 6;
//                 // phi_t3_2 = temp_t3;
//                 if (temp_t6_2 == 0) {
//                     phi_t4 = -5;
//                 }
//                 if (phi_t3 == 0) {
//                     phi_t4 = 5;
//                 }
//                 phi_t0 = temp_t6_2 + FTOFIX32(1.0);
//                 phi_t3 = phi_t3 + FTOFIX32(1.0);
//                 break;
//             default:
//                 phi_t4 = 0;
//                 phi_t0 = FTOFIX32(1.0);
//                 phi_t3 = FTOFIX32(1.0);
//                 break;
//             }
//
//             if (phi_t4 != 0) {
//                 temp_t9_3 = (D_80152C78[(-D_803D552C->unk302 + 64) & 0xFF]) >> 7;
//                 sp8C = (D_80152C78[-D_803D552C->unk302 & 0xFF]) >> 7;
//                 // sp8E = (s16) temp_t9_3;
//                 // sp9C = phi_t0;
//                 // temp_v1_10 = D_803D5530;
//                 create_particle_effect(
//                     D_803D5530->xPos + ((((sp8C * 0xA9E) / 0xE8) + (temp_t9_3 * phi_t4)) >> 8),
//                     D_803D5530->zPos + ((((-temp_t9_3 * 0xA9E) / 0xE8) + (sp8C * phi_t4)) >> 8),
//                     D_803D5530->yPos + 0xC,
//                     21,
//                     0,
//                     0,
//                     (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
//                     25,
//                     GPACK_RGBA5551(96, 96, 96, 1),
//                     GPACK_RGBA5551(96, 96, 96, 1),
//                     0);
//             }
//             // sp9C = phi_t0;
//             // sp98 = phi_t3;
//             func_80356410_767AC0(D_04003A50, D_04003850);
//             func_802C78B0_6D8F60(
//                 2,
//                 1,
//                 (D_803F2EBC * 0x3A) >> 6,
//                 (D_803F2EC0 * 0x3A) >> 6,
//                 (D_803F2EC4 * 0x3A) >> 6,
//                 D_803F2ED0,
//                 0,
//                 0,
//                 0,
//                 D_04002D70);
//             // temp_v0_9 = D_803F2EDD;
//             // phi_v0_4 = temp_v0_9;
//             if (D_803F2EDD == 0) {
//                 temp_a3 = (phi_t0 * 58) >> 6;
//                 func_802C78B0_6D8F60(2, 1, temp_a3, temp_a3, temp_a3, D_803F2ED0, 0, 0, 0, D_04003140);
//             }
//             if (D_803F2EDD == 0) {
//                 temp_a3 = (phi_t3 * 58) >> 6;
//                 func_802C78B0_6D8F60(2, 1, temp_a3, temp_a3, temp_a3, D_803F2ED0, 0, 1, 0, D_04003140);
//             }
//             func_802C78B0_6D8F60(1, 20, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_040033C0);
//             gSPClearGeometryMode(D_801D9E88++, G_CULL_BOTH);
//
//             if (D_803F2EDD == 0) {
//                 func_802C78B0_6D8F60(1, 20, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04003530);
//             }
//             func_80356410_767AC0(D_04004070, D_04003E70);
//
//             gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);
//             gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD);
//             gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));
//
//             func_802C78B0_6D8F60(7,   8, FTOFIX32(0.90625),   FTOFIX32(0.90625),   FTOFIX32(0.90625),   D_803F2ED0, 0, 0, 0, D_04003650);
//             func_802C78B0_6D8F60(10, 11, FTOFIX32(0.90625),   FTOFIX32(0.90625),   FTOFIX32(0.90625),   D_803F2ED0, 0, 0, 0, D_04003650);
//             func_802C78B0_6D8F60(13, 14, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04003650);
//             func_802C78B0_6D8F60(16, 17, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04003650);
//             gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if ((sp88 == 0) || (sp88 == 2)) {
//         func_8034BD20_75D3D0(
//             D_803D552C->xPos,
//             D_803D552C->zPos,
//             (D_803D552C->yPos + (D_803D5524->unkBA >> 1)),
//             D_803D552C->unk302,
//             D_01033190,
//             25,
//             25,
//             155,
//             0,
//             0,
//             0,
//             0,
//             D_803D5538);
//     }
//     if (sp88 == 0) {
//         func_803034D0_714B80(D_803D552C, 679, 0, 0);
//         func_80303D50_715400(D_803D552C, 2);
//     } else {
//         func_80303D00_7153B0(D_803D552C, 1359, 453);
//     }
// }
