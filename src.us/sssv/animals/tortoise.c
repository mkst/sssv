#include <ultra64.h>
#include "common.h"

s32 func_8035E344_76F9F4(struct035 **arg0, s16 arg1);
void func_8034B45C_75CB0C();
void func_8035D120_76E7D0();
void func_8035DA60_76F110();
void func_8035D734_76EDE4();
void func_8035D6D0_76ED80();
extern u8 D_803A843C_7B9AEC[]; // tbd
extern u8 D_803A8450_7B9B00[];

// tortoise tank
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80352380_763A30.s")

// racing tortoise
#if 0
void func_80354188_765838(void) {
    s32 sp9C;
    s16 sp90[4];
    s16 sp8C;
    s16 sp88;

    s32 temp_a3;
    u8 temp_t0;
    u16 temp_t1;
    s32 temp_t6_2;
    s32 temp_t9;
    s32 temp_t9_3;
    u32 phi_v0;
    s8 phi_v0_2;

    s8 phi_a1;
    s8 phi_t1;
    s8 phi_v1;
    s16 phi_v1_6;
    s16 phi_v1_7;
    s16 phi_v0_3;
    s16 phi_v1_8;
    s16 phi_t4;
    s32 phi_t3;
    s32 phi_t0;

    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
                21,
                0,
                0,
                (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF, // typo?
                30,
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(0, 0, 0, 1),
                0);
        }
        D_803D552C->unk2EC--;
        if (D_803D552C->unk2EC <= 0) {
            D_803D552C->unk36E = 0;
        }
    }
    temp_t0 = D_803D552C->unk310; // & 0xFF;
    phi_v1 = D_803D552C->unk310 >> 8;

    if (D_803D5538 != 0) {
        phi_v0 = D_801E9EB2;
    } else {
        phi_v0 = MIN(D_803D552C->unk368 >> 2, 18);
    }
    switch (phi_v0) {
    case 0:
        phi_v0_2 = -5;
        phi_a1 = 0;
        phi_t1 = temp_t0;
        break;
    case 1:
        phi_v0_2 = 2;
        phi_a1 = 0;
        phi_t1 = temp_t0;
        break;
    case 2:
        phi_v0_2 = 5;
        phi_a1 = 10;
        phi_t1 = temp_t0;
        break;
    case 3:
        phi_v0_2 = 8;
        phi_a1 = 20;
        phi_t1 = MAX(temp_t0, 95); // tbd
        // phi_t1 = temp_t0;
        // if (temp_t0 < 95) {
        //     phi_t1 = 95;
        // }
        break;
    default:
        phi_v0_2 = 11;
        phi_a1 = 30;
        phi_t1 = MAX(temp_t0, 110);
        // phi_t1 = temp_t0;
        // if (temp_t0 < 110) {
        //     phi_t1 = 110;
        // }
        break;
    }

    // phi_v1 vs temp_v1_2 ?
    if (phi_v1 < phi_v0_2) {
        phi_v1 = MIN(phi_v1 + 5, phi_v0_2);
    } else if (phi_v0_2 < phi_v1) {
        phi_v1 = MAX(phi_v1 - 1, phi_v0_2);
    }
    if (phi_v1 > 3) {
        phi_v1 -= 1;
    }
    if (phi_v1 > 6) {
        phi_v1 -= 1;
    }
    if (phi_v1 < -3) {
        phi_v1 += 1;
    }
    if (phi_v1 < -6) {
        phi_v1 += 1;
    }

    if ((phi_a1 + 110) < phi_t1) {
        phi_v1 -= ((phi_t1 - phi_a1) - 110) / 5;
    }
    if (phi_t1 < 20) {
        phi_v1 += (20 - phi_t1) / 2;
    }

    temp_t1 = (phi_t1 + phi_v1) & 0xFF;
    D_803D552C->unk310 = (s16) ((phi_v1 << 8) | temp_t1);
    // temp_a1 = D_803D5538;
    phi_v1_6 = 0;
    // phi_a1_2 = temp_a1;
    // phi_v1_7 = 0;
    phi_v1_8 = 0;
    if (D_803D5538 != 0) {
        phi_v1_6 = D_803D554C << 1; // (s32) (D_803D554C << 17) >> 16;
    }
    if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 4)) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                100,
                ((temp_t1 / 300.0) + 0.3) * 20480.0,
                0,
                ((temp_t1 + phi_v1_6) / 200.0) + 0.3,
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            phi_v1_7 = 1;
        } else {
            phi_v1_7 = 0;
        }
        if (phi_v1_7 != 0) {
            sp88 = 0;
            D_803F2EDD = 0;
            goto block_57;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        phi_v0_3 = 1;
    } else {
        phi_v0_3 = 0;
    }
    sp88 = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
        0x740,
        0,
        0,
        0x5A,
        0,
        1,
        phi_v0_3 == 0);

block_57:
    if (sp88 == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        if ((D_803F2ECE == 0) || (((D_803F2ECC < 31)))) {
            if (D_803D5538 != 0) {
                phi_v1_8 = ((D_803D554C * 362) / 20);
            }
            // sp86 = phi_v1_8;
            func_802B9130_6CA7E0(sp90, 453, 308, 498, 0);
            D_80203FE0[5].unk4 += 271;
            D_80203FE0[6].unk4 += 271;
            D_80203FE0[0].unk4 += 135;
            func_802C18FC_6D2FAC(phi_v1_8 + 362, 634, sp90);
            func_802B964C_6CACFC();
            D_80203FE0[0].unk4 += phi_v1_8 >> 1;
            D_80203FE0[1].unk4 += phi_v1_8;
            func_802C5EF4_6D75A4(181, 362);
            func_8038CCF0_79E3A0(90, 20, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(&D_803A843C_7B9AEC, &D_803A8450_7B9B00, &D_803A8464_7B9B14, &D_803A8484_7B9B34);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803A843C_7B9AEC, &D_803A8450_7B9B00, &D_803A8464_7B9B14, &D_803A84CC_7B9B7C);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
             (D_803F2EDA != 0) &&
             (((D_803D5538 != 0)) || ((D_803F2AA2 == 0)) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 > 10))) &&
             ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)],
                D_803D5530->xPos.w,
                D_803D5530->zPos.w,
                D_803D5530->yPos.w,
                -D_803D552C->unk302,
                D_803F2EB0 / 4,
                D_803F2EB4 / 4,
                D_803F2EB8 / 4,
                D_803F2ED2,
                D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            switch (D_803D5530->state) {
            case 22:
            case 24:
                phi_t4 = 0;
                temp_t9 = D_803D5540 * 8;
                temp_t6_2 = (temp_t9 & 0xFF) << 5;
                phi_t3 = ((temp_t9 + 0x80) & 0xFF) << 5;
                if (temp_t6_2 == 0) {
                    phi_t4 = -5;
                }
                if (phi_t3 == 0) {
                    phi_t4 = 5;
                }
                phi_t0 = temp_t6_2 + FTOFIX32(1.0);
                phi_t3 = phi_t3 + FTOFIX32(1.0);
                break;
            case 23:
                phi_t4 = 0;
                temp_t9 = D_803D5540 * 16;
                temp_t6_2 = (temp_t9 & 0xFF) << 6;
                phi_t3 = ((temp_t9 + 0x80) & 0xFF) << 6;
                // phi_t3_2 = temp_t3;
                if (temp_t6_2 == 0) {
                    phi_t4 = -5;
                }
                if (phi_t3 == 0) {
                    phi_t4 = 5;
                }
                phi_t0 = temp_t6_2 + FTOFIX32(1.0);
                phi_t3 = phi_t3 + FTOFIX32(1.0);
                break;
            default:
                phi_t4 = 0;
                phi_t0 = FTOFIX32(1.0);
                phi_t3 = FTOFIX32(1.0);
                break;
            }

            if (phi_t4 != 0) {
                temp_t9_3 = (D_80152C78[(-D_803D552C->unk302 + 64) & 0xFF]) >> 7;
                sp8C = (D_80152C78[-D_803D552C->unk302 & 0xFF]) >> 7;
                // sp8E = (s16) temp_t9_3;
                // sp9C = phi_t0;
                // temp_v1_10 = D_803D5530;
                create_particle_effect(
                    D_803D5530->xPos.h + ((((sp8C * 0xA9E) / 0xE8) + (temp_t9_3 * phi_t4)) >> 8),
                    D_803D5530->zPos.h + ((((-temp_t9_3 * 0xA9E) / 0xE8) + (sp8C * phi_t4)) >> 8),
                    D_803D5530->yPos.h + 0xC,
                    21,
                    0,
                    0,
                    (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
                    25,
                    GPACK_RGBA5551(96, 96, 96, 1),
                    GPACK_RGBA5551(96, 96, 96, 1),
                    0);
            }
            // sp9C = phi_t0;
            // sp98 = phi_t3;
            load_1_tile(D_04003A50, D_04003850);
            func_802C78B0_6D8F60(
                2,
                1,
                (D_803F2EBC * 0x3A) >> 6,
                (D_803F2EC0 * 0x3A) >> 6,
                (D_803F2EC4 * 0x3A) >> 6,
                D_803F2ED0,
                0,
                0,
                0,
                D_04002D70);
            // temp_v0_9 = D_803F2EDD;
            // phi_v0_4 = temp_v0_9;
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(2, 1, (phi_t0 * 58) >> 6, (phi_t0 * 58) >> 6, (phi_t0 * 58) >> 6, D_803F2ED0, 0, 0, 0, D_04003140);
            }
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(2, 1, (phi_t3 * 58) >> 6, (phi_t3 * 58) >> 6, (phi_t3 * 58) >> 6, D_803F2ED0, 0, 1, 0, D_04003140);
            }
            func_802C78B0_6D8F60(1, 20, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_040033C0);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BOTH);

            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(1, 20, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04003530);
            }
            load_1_tile(D_04004070, D_04003E70);

            gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);
            gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD);
            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));

            func_802C78B0_6D8F60(7,   8, FTOFIX32(0.90625),   FTOFIX32(0.90625),   FTOFIX32(0.90625),   D_803F2ED0, 0, 0, 0, D_04003650);
            func_802C78B0_6D8F60(10, 11, FTOFIX32(0.90625),   FTOFIX32(0.90625),   FTOFIX32(0.90625),   D_803F2ED0, 0, 0, 0, D_04003650);
            func_802C78B0_6D8F60(13, 14, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04003650);
            func_802C78B0_6D8F60(16, 17, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04003650);
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp88 == 0) || (sp88 == 2)) {
        func_8034BD20_75D3D0(
            D_803D552C->xPos.h,
            D_803D552C->zPos.h,
            (D_803D552C->yPos.h + (D_803D5524->unkBA >> 1)),
            D_803D552C->unk302,
            D_01033190,
            25,
            25,
            155,
            0,
            0,
            0,
            0,
            D_803D5538);
    }
    if (sp88 == 0) {
        func_803034D0_714B80(D_803D552C, 679, 0, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 1359, 453);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80354188_765838.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355130_7667E0.s")
// close but no cigar
// void func_80355130_7667E0(void) {
//     s32 sp88;
//     s32 phi_t0_2;
//     s16 sp86;
//     f32 temp_f0;
//     s32 phi_v1_2;
//
//
//     if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
//         func_8032CD70_73E420(D_803D5530, 175, 0x6000, 0, 1.0f, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
//     }
//
//     if (D_803D5530->unk162 == 1) {
//         phi_t0_2 = ABS(D_803D5530->xVelocity.w) + ABS(D_803D5530->zVelocity.w);
//         temp_f0 = (phi_t0_2) / 655360.0;
//         if (0.2 < temp_f0) {
//             func_8032CD70_73E420(
//                 (u8*)D_803D5530 + 0x22, // ->zVelocity.h, // unaligned?
//                 0x3F,
//                 (MIN(temp_f0 - 0.2, 1.3) * 8192.0),
//                 0,
//                 (temp_f0 * 0.5) + D_803BEAF8_7D01A8, // D_803BEAF8_7D01A8 // 1.8f
//                 D_803D5530->xPos.h,
//                 D_803D5530->zPos.h,
//                 D_803D5530->yPos.h);
//         }
//     }
//
//     switch (D_803D5538) {
//     default:
//     case 1:
//         if ((D_803F2D50.segment == D_803D5524->biome) || (D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5))) {
//             phi_v1_2 = 1;
//         } else {
//             phi_v1_2 = 0;
//         }
//
//         if (phi_v1_2 != 0) {
//             sp86 = 0;
//             D_803F2EDD = (u8)0;
//             break;
//         }
//         // fallthrough
//     case 0:
//         if ((D_803F2D50.segment == D_803D5524->biome) ||
//             (D_803F2D50.segment == (D_803D5538 * 0)) && // FAKEMATCH
//             ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5))) {
//             phi_t0_2 = 1;
//         } else {
//             phi_t0_2 = 0;
//         }
//         sp86 = func_802E89F0_6FA0A0(
//             D_803D552C->xPos.w,
//             D_803D552C->zPos.w,
//             D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
//             0x740,
//             0,
//             0,
//             0x5A,
//             0,
//             1,
//             phi_t0_2 == 0);
//     }
//
//     if (sp86 == 0) {
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
//             func_802B9130_6CA7E0(&sp88, 0x1C5, 0x134, 0xB5, 0);
//             func_802B964C_6CACFC();
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {
//             case 1:
//                 func_802DB670_6ECD20(&D_803A8514_7B9BC4, &D_803A8518_7B9BC8, &D_803A8464_7B9B14, &D_803A8484_7B9B34);
//                 break;
//             case 2:
//                 func_802DB670_6ECD20(&D_803A8514_7B9BC4, &D_803A8518_7B9BC8, &D_803A8464_7B9B14, &D_803A84CC_7B9B7C);
//                 break;
//             }
//         }
//         func_803224C4_733B74(0x15, 0x15, 0, 0x10, 0, 0, 0, 0x10);
//         func_8038064C_791CFC();
//
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
//              (D_803F2EDA != 0) &&
//              ((D_803D5538 != 0) || (D_803F2AA2 == 0) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) &&
//              ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
//             func_80127640(
//                 &D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)],
//                 D_803D5530->xPos.w,
//                 D_803D5530->zPos.w,
//                 D_803D5530->yPos.w, -(s32) D_803D552C->unk302,
//                 (s32) D_803F2EB0 / 4,
//                 (s32) D_803F2EB4 / 4,
//                 (s32) D_803F2EB8 / 4,
//                 D_803F2ED2,
//                 D_803F2ED4);
//             gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//             D_80204278->usedModelViewMtxs++;
//
//             load_1_tile(D_04003A50, D_04003850);
//             func_802C78B0_6D8F60(2, 1, (s32) (D_803F2EBC * 0x3A) >> 6, (s32) (D_803F2EC0 * 0x3A) >> 6, (s32) (D_803F2EC4 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_04002D70);
//             gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//
//             func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + D_803D5524->unkBA), D_803D552C->unk302, D_01033190, 0x19, 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if (sp86 == 0) {
//         func_803034D0_714B80(D_803D552C, 0x7F6, 0, 0);
//         func_80303D50_715400(D_803D552C, 2);
//     } else {
//         func_80303D00_7153B0(D_803D552C, 0x54F, 0x1C5);
//     }
//     if (D_803D5538 == 0) {
//         if (D_803D552C->unk2EC <= 0) {
//             play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803BEB00_7D01B0 /* 1.8f */);
//             if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
//                 load_animal(TORTOISE_TANK);
//             } else {
//                 load_animal(RACING_TORTOISE);
//             }
//         } else {
//             D_803D552C->unk2EC -= 1;
//         }
//     }
//     if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
//         if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
//             load_animal(TORTOISE_TANK);
//         } else if (D_803D5524->unk9C == RACING_TORTOISE_DEFENDING) {
//             load_animal(RACING_TORTOISE);
//         }
//     }
// }

#ifdef NON_MATCHING
// is this equivalent?
void func_80355918_766FC8(void) {
    s16 temp_t0;
    s16 temp_v1;
    s16 phi_v1;

    if ((D_803F28E0[D_803F2A98].cameraMode == 3) || (D_803F28E0[D_803F2A98].cameraMode == 17)) {
        D_803D552C->unk30E = 0;
        if (D_801D9ED8.unkFFC6 != 0) {
            D_803D552C->unk30C -= 4;
        }
        if (D_801D9ED8.unkFFC8 != 0) {
            D_803D552C->unk30C += 4;
        }

        D_803D552C->unk30C = MAX(-100, D_803D552C->unk30C);
        D_803D552C->unk30C = MIN(100, D_803D552C->unk30C);

        if ((D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0) && (func_8035E344_76F9F4(D_803D5520, 0))) {
            func_80321E60_733510(
                OBJECT_CANNONBALL,
                32,
                0,
                20,
                25 - (D_803D552C->unk30C >> 3),
                (25 - (D_803D552C->unk30C >> 2)) + (D_803F2A9E / 3),
                2,
                45);
            func_803421E0_753890(17);

            D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
        }
    } else {
        if ((D_801D9ED8.unkFFB2 == 0) && (D_801D9ED8.unkFFB8 != 0) && (func_8035E344_76F9F4(D_803D5520, 0))) {

            if (D_803D552C->unk30E < 60) {
                phi_v1 = -D_803D552C->unk30E;
            } else {
                phi_v1 = (-120 - -D_803D552C->unk30E);
            }
            temp_v1 = phi_v1 - ((D_803D552C->unk312 * 360) >> 8);
            temp_t0 = -temp_v1;

            phi_v1 = (((D_80152C78[(temp_v1 + 64) & 0xFF] >> 7) << 5) >> 8);

            func_80321E60_733510(
                OBJECT_CANNONBALL,
                (phi_v1),
                0,
                (s16) (((((D_80152C78[temp_t0 & 0xFF]) >> 7) << 5) >> 8) + 16),
                10 - (temp_v1 / 3),
                temp_t0,
                2,
                45);
            func_803421E0_753890(17);

            D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
        }
        if (D_801D9ED8.unkFFB2 != 0) {
            D_803D552C->unk30E = ((D_803D552C->unk30E + 1) % 120);
            if ((D_803D552C->unk30E < 60) && (D_803D5530->unk4A == 0)) {
                func_8032CD70_73E420(&D_803D5530->unk2, 0x55, 0x3C00, 0, D_803BEB08_7D01B8 /* 0.7f */, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
            } else {
                func_8032CD70_73E420(&D_803D5530->unk2, 0x55, 0x3C00, 0, D_803BEB04_7D01B4 /* 0.4f */, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
            }
        } else {
            D_803D552C->unk30E = (u16)0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355918_766FC8.s")
#endif

void func_80355E14_7674C4(void) {
    func_80321E60_733510(OBJECT_CANNONBALL, 32, 0, 30, 10, 0, 2, 45);
    func_8034220C_7538BC(17, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_80355EDC_76758C(void) {
    recharge_skill(0);
}

// tortoise tank
void func_80355EFC_7675AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h,  D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(TORTOISE_TANK_DEFENDING);
}

void func_80355F64_767614(void) {
    func_8037D994_78F044(20);
    if ((D_803D5540 & 1) == 0) {
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + FTOFIX32(3.0)) & (FTOFIX32(0.5) - 1),
            30,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
    }
}

// racing tortoise
void func_80355FFC_7676AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(RACING_TORTOISE_DEFENDING);
}

// tortoise tank
void func_80356064_767714(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(TORTOISE_TANK);
}

// racing tortoise
void func_803560CC_76777C(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(RACING_TORTOISE);
}

void func_80356134_7677E4(Animal *a) {
    s32 temp_v0;
    s16 rot;

    temp_v0 = func_802F8160_709810(D_803D5530, a, 32, 20, 30, 0x59, -4, 3, (f32)D_803A05B0 / 65536.0);
    if (temp_v0 == -1) {
        rot = 32;
    } else {
        rot = (temp_v0 * 256) / 360;
    }
    func_80322064_733714(OBJECT_CANNONBALL, 32, 0, 20, 30, D_803D5530->yRotation, rot, 2, 45);
    do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
    func_8034220C_7538BC(14, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_803562C8_767978(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == TORTOISE_TANK) {
        play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
        load_animal(TORTOISE_TANK_DEFENDING);
    }
}

void func_80356348_7679F8(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_TORTOISE) {
        play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
        load_animal(RACING_TORTOISE_DEFENDING);
    }
}

void racing_tortoise_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 20;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
