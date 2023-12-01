#include <ultra64.h>
#include "common.h"


u8 bss_padding_chameleon_pre[0x150];


extern s16 D_803B3B60_7C5210[];
extern s16 D_803B3C34_7C52E4[];
extern s16 D_803B3BD4_7C5284[];

extern u8 D_803B3C48_7C52F8[];
extern u8 D_803B3C60_7C5310[];

extern s16 D_803B3CA0_7C5350[];
extern s16 D_803B3CF8_7C53A8[];
extern s16 D_803B3C78_7C5328[];

extern Gfx D_04008AD0_F9B30[];
extern Gfx D_04008C70_F9CD0[];
extern Gfx D_04008D70_F9DD0[];
extern Gfx D_04008EF0_F9F50[];
extern Gfx D_04008FF0_FA050[];
extern Gfx D_04009500_FA560[];
extern Gfx D_04009870_FA8D0[];
extern Gfx D_040099B0_FAA10[];
extern u8  D_040099F0_FAA50[];
extern u8  D_04009BF0_FAC50[]; // palette
extern u8  D_04009C10_FAC70[];
extern u8  D_04009E10_FAE70[];

#if 0
// CURRENT (5624)
void func_8035A5F0_76BCA0(void) {
    struct061 spD0;
    s16 spCA;
    s16 spC4;
    s16 spC2;
    s16 spC0;
    // u16 sp8C;
    u16 ticks_remaining; // sp7C

    s16 var_a0;
    s32 var_s0;
    s16 var_s0_3;
    s16 var_s1;
    s16 var_s2;
    s16 var_s3;
    s16 var_v1_3;
    u8 temp_v0_8;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spCA = 0;
        D_803F2EDD = 0;
    } else {
        spCA = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0xA00, 0, 0x9E, 0x9E, 0x4F, 1, CHECK_SEGMENT == 0);
    }

    if (spCA == 0) {
        func_8035BDC0_76D470();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        func_8035D734_76EDE4();

        switch (D_803D5524->unk9C) {                        /* irregular */
        case CHAMELEON:
            switch (D_803D552C->unk365) {                    /* switch 1; irregular */
            case ATTACK_CHAMELEON_TONGUE:                                 /* switch 1 */
                func_802DCCAC_6EE35C(16);
                if (D_803D5544 - D_803D552C->unk32A == 4) {
                    func_803224C4_733B74(0x13, 0x49, 0, 0x10, 0xB, 0, 0, 0x17);
                    func_803224C4_733B74(0x13, 0x30, 0, 0x10, 0xB, 0, 0, 0x17);
                    func_803224C4_733B74(0x13, 0x18, 0, 0x10, 0xB, 0, 0, 0x17);
                }
                break;
            case ATTACK_CHAMELEON_1:                                /* switch 1 */
                if (D_803D5530->unk4A != 0) {
                    D_803D552C->unk32A++;
                } else {
                    ticks_remaining = D_803D5544 - D_803D552C->unk32A; // & 0xFFFF;
                    if (ticks_remaining < 17) {
                        if (D_803D5530->unk4A == 0) {
                            func_8032CD70_73E420(
                                D_803D5530,
                                SFX_UNKNOWN_51,
                                ((16 - ticks_remaining) * 0x7000) >> 4,
                                0,
                                ((ticks_remaining * ticks_remaining) / 16.0) + 1.0,
                                D_803D5530->position.xPos.h,
                                D_803D5530->position.zPos.h,
                                D_803D5530->position.yPos.h);
                        }

                        // same issues as camel

                        var_s0 = 0;
                        var_s3 = ticks_remaining;
                        while (var_s3 > 4) {
                            var_s3 -= 4;

                            spC4 = SSSV_RAND(256) - 0x80;
                            spC2 = SSSV_RAND(256) - 0x80;

                            var_s0++; // er???

                            spC4 = (spC4 * (var_s0+1)) >> 3;
                            spC2 = (spC2 * (var_s0+1)) >> 3;

                            spC0 = SSSV_RAND(32);
                            spC0 = (spC0 + ((var_s0+1) << 5));
                            spC0 = (spC0 * D_803D5530->unk42) >> 6;

                            create_particle_effect(
                                D_803D5530->position.xPos.h + spC4,
                                D_803D5530->position.zPos.h + spC2,
                                D_803D5530->position.yPos.h + spC0,
                                0x15,
                                0,
                                0,
                                0,
                                0x1E,
                                GPACK_RGBA5551(64, ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                                GPACK_RGBA5551(0,  ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                                0);
                        }

                        spC4 = SIN((SSSV_RAND(32) + ((ticks_remaining & 7) << 5))) >> 7;
                        spC2 = COS((SSSV_RAND(32) + ((ticks_remaining & 7) << 5))) >> 7;

                        spC4 = (spC4 * ticks_remaining) >> 6;
                        spC2 = (spC2 * ticks_remaining) >> 6;

                        create_particle_effect(
                            D_803D5530->position.xPos.h + spC4,
                            D_803D5530->position.zPos.h + spC2,
                            D_803D5530->position.yPos.h + ((ticks_remaining * D_803D5530->unk42) >> 1),
                            0x15,
                            0,
                            0,
                            0,
                            0x1E,
                            GPACK_RGBA5551(64, ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                            GPACK_RGBA5551(0,  ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                            0);
                    } else {
                        load_animal(SNEAKY_CHAMELEON);
                        D_803D552C->unk365 = ATTACK_NONE;
                    }
                }
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
            break;
        case SNEAKY_CHAMELEON:
            switch (D_803D552C->unk365) {
            case ATTACK_CHAMELEON_2:
                if (D_803D5530->unk4A != 0) {
                    D_803D552C->unk32A++;
                } else {
                    ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                    if (ticks_remaining < 17) {
                        if (D_803D5530->unk4A == 0) {
                            func_8032CD70_73E420(
                                D_803D5530,
                                SFX_UNKNOWN_51,
                                (ticks_remaining * 0x7000) >> 4,
                                0,
                                ((ticks_remaining * ticks_remaining) / 16.0) + 1.0,
                                D_803D5530->position.xPos.h,
                                D_803D5530->position.zPos.h,
                                D_803D5530->position.yPos.h);
                        }

                        ticks_remaining = (16 - ticks_remaining);

                        var_s0 = 0;
                        var_s3 = ticks_remaining;
                        while (var_s3 > 4) {
                            var_s3 -= 4;

                            spC4 = SSSV_RAND(256) - 0x80;
                            spC2 = SSSV_RAND(256) - 0x80;

                            var_s0++;

                            spC4 = spC4 * (var_s0+1) >> 3;
                            spC2 = spC2 * (var_s0+1) >> 3;

                            spC0 = SSSV_RAND(32);
                            spC0 = (spC0 + ((var_s0+1) << 5));
                            spC0 = (spC0 * D_803D5530->unk42) >> 6;

                            create_particle_effect(
                                D_803D5530->position.xPos.h + spC4,
                                D_803D5530->position.zPos.h + spC2,
                                D_803D5530->position.yPos.h + spC0,
                                0x15,
                                0,
                                0,
                                0,
                                0x1E,
                                GPACK_RGBA5551(64, ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                                GPACK_RGBA5551(0,  ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                                0);
                        }

                        spC4 = SIN((SSSV_RAND(32) + ((ticks_remaining & 7) << 5))) >> 7;
                        spC2 = COS((SSSV_RAND(32) + ((ticks_remaining & 7) << 5))) >> 7;

                        spC4 = (spC4 * ticks_remaining) >> 6;
                        spC2 = (spC2 * ticks_remaining) >> 6;

                        create_particle_effect(
                            D_803D5530->position.xPos.h + spC4,
                            D_803D5530->position.zPos.h + spC2,
                            D_803D5530->position.yPos.h + ((ticks_remaining * D_803D5530->unk42) >> 1),
                            0x15,
                            0,
                            0,
                            0,
                            0x1E,
                            GPACK_RGBA5551(64, ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                            GPACK_RGBA5551(0,  ((SSSV_RAND(4) << 5) + 0x60), 0, 1),
                            0);
                    } else {
                        load_animal(CHAMELEON);
                        D_803D552C->unk365 = ATTACK_NONE;
                    }
                }
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
            break;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            D_803F2F00 = 0;
            func_802B9130_6CA7E0(&spD0, 0x138, 0x177, 0x1F4, 0x7D);
            func_802BD40C_6CEABC(250, 250, 0, 0x7D, 0, 0x80, 0, 0x80, &D_803B3B60_7C5210, &D_803B3B60_7C5210, &D_803B3C34_7C52E4, 250, 250, 0, 0x7D, 0x40, 0xC0, 0x40, 0xC0, &D_803B3BD4_7C5284, &D_803B3BD4_7C5284, &D_803B3C34_7C52E4, &spD0, 1);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0, 0x2AF, 7);
            func_802BBC90_6CD340(0x271);

            if (((D_803D5530->state == 3) || (D_803D5530->state == 6)) && ((D_803D552C->unk366 != 5)) && (D_803D552C->unk366 != 2)) {
                var_s1 = D_803D552C->unk2F6;
                var_s2 = (s16)(COS(var_s1) >> 7) / 16;
                var_s0_3 = ((s16)(COS(var_s1) >> 7) * 250) >> 9;
            } else if ((D_803D5530->state == 4) && ((D_803D552C->unk366 != 5)) && (D_803D552C->unk366 != 2)) {
                var_s1 = D_803D552C->unk2F6;
                var_s2 = (s16)(COS(var_s1) >> 7) / 12;
                var_s0_3 = ((s16)(COS(var_s1) >> 7) * 250) >> 9;
            } else {

                if ((D_803D5530->unk162 == 5) && (D_803D552C->unk366 != 2)) {
                    var_s1 = (D_803D5540 << 5) & 0xFF;
                    var_s2 = (s16)(COS(var_s1) >> 7) / 12;
                    var_s0_3 = ((s16)(COS(var_s1) >> 7) * 250) >> 9;
                } else {
                    var_s1 = -1;
                    var_s0_3 = 0;
                    var_s2 = 0;
                }
            }
            func_803033D4_714A84(0x14, 1, var_s2);
            func_803033D4_714A84(0x1A, 2, -var_s2);

            if (var_s1 >= 0) {
                var_a0 = MAX(0, ((SIN(var_s1) >> 7) * 250) >> 8);
                var_v1_3 = MAX(0, (-(SIN(var_s1) >> 7) * 250) >> 8);
            } else {
                var_v1_3 = 0;
                var_a0 = 0;
            }

            D_80203FE0[7].unk4 += var_v1_3;
            D_80203FE0[8].unk4 += var_v1_3;
            D_80203FE0[13].unk4 += var_a0;
            D_80203FE0[14].unk4 += var_a0;
            D_80203FE0[10].unk4 += var_a0;
            D_80203FE0[11].unk4 += var_a0;

            D_80203FE0[16].unk4 += var_v1_3;
            D_80203FE0[17].unk4 += var_v1_3;
            D_80203FE0[3].unk2 += var_s0_3;
            D_80203FE0[7].unk2 += var_s0_3;
            D_80203FE0[8].unk2 += var_s0_3;
            D_80203FE0[6].unk2 += var_s0_3;

            D_80203FE0[16].unk2 += var_s0_3;
            D_80203FE0[17].unk2 += var_s0_3;

            D_80203FE0[4].unk2 -= var_s0_3;
            D_80203FE0[10].unk2 -= var_s0_3;
            D_80203FE0[11].unk2 -= var_s0_3;

            D_80203FE0[5].unk2 -= var_s0_3;
            D_80203FE0[13].unk2 -= var_s0_3;
            D_80203FE0[14].unk2 -= var_s0_3;

            if (D_803D5524->unk9C == SNEAKY_CHAMELEON) {
                switch (D_803F2F00) {
                case 1:
                    func_80374660_785D10(-11, 0, 0x514);
                    break;
                case 2:
                    func_80374660_785D10(11, 0, 0x514);
                    break;
                case 3:
                    func_80374660_785D10(-11, 0, 0x514);
                    break;
                case 4:
                    func_80374660_785D10(11, 0, 0x514);
                    break;
                }
            }
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B3C48_7C52F8, D_803B3C60_7C5310, D_803B3C78_7C5328, D_803B3CA0_7C5350);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B3C48_7C52F8, D_803B3C60_7C5310, D_803B3C78_7C5328, D_803B3CF8_7C53A8);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_8 = D_803F2AA2, (temp_v0_8 == 0)) || (temp_v0_8 == 2) || ((temp_v0_8 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (s16) (s32) -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 3, 3, 0.09f);
            if (D_803D5524->unk9C == CHAMELEON) {

                gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);

                load_1_tile(D_04009BF0_FAC50, D_040099F0_FAA50);
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x50) >> 6, (D_803F2EC0 * 0x50) >> 6, (D_803F2EC4 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04008C70_F9CD0);
                func_802C78B0_6D8F60(2, 0x1A, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04009870_FA8D0);
                load_1_tile(D_04009E10_FAE70, D_04009C10_FAC70);

                // temp_v0_12 = D_801D9E88;
                // D_801D9E88 = temp_v0_12 + 8;
                // temp_v0_12->words.w1 = 0;
                // temp_v0_12->words.w0 = (D_803D5540 & 0xFFF) | 0xF2000000;
                gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, D_803D5540, 0, 0); // tbd

                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04009500_FA560);
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04008FF0_FA050); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04008EF0_F9F50); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 0xD, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04008D70_F9DD0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xD, 0xE, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04008AD0_F9B30); }
#pragma _permuter sameline end

                gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
                gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xA, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 1, 0, D_04008FF0_FA050); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xA, 0xB, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 1, 0, D_04008EF0_F9F50); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x10, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 1, 0, D_04008D70_F9DD0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x10, 0x11, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 1, 0, D_04008AD0_F9B30); }
#pragma _permuter sameline end
            }
            if (D_803F2ED8 != 0) {
                func_802C78B0_6D8F60(
                    1,
                    0x14,
                    ((D_803F2ED8 << 0xB) * 0x50) >> 6,
                    ((D_803F2ED8 << 0xB) * 0x50) >> 6,
                    ((D_803F2ED8 << 0xB) * 0x50) >> 6,
                    D_803F2ED0,
                    0,
                    0,
                    0,
                    D_040099B0_FAA10);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spCA == 0) || (spCA == 2)) {
        if (D_803D5524->unk9C != SNEAKY_CHAMELEON) {
            func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + D_803D5524->unkBA), D_803D552C->unk302, &D_01033190, 0x19, 0xC, 0x9B, 0, 0, 0, 0, D_803D5538);
        }
    }
    if (spCA == 0) {
        func_803034D0_714B80(D_803D552C, 0x3A9, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 1, 0x14, 0x157, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x271, 0x271);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            if ((D_803D552C->unk365 != ATTACK_CHAMELEON_1) && (D_803D552C->unk365 != ATTACK_CHAMELEON_2) && (D_803D5524->unk9C != CHAMELEON)) {
                D_803D552C->unk32A = D_803D5544;
                D_803D552C->unk365 = ATTACK_CHAMELEON_2;
            }
        } else {
            if ((D_803D552C->unk365 != ATTACK_CHAMELEON_1) && (D_803D552C->unk365 != ATTACK_CHAMELEON_2)) {
                D_803D552C->unk32A = D_803D5544;
                D_803D552C->unk365 = ATTACK_CHAMELEON_1;
            }
            D_803D552C->unk2EC--;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/chameleon/func_8035A5F0_76BCA0.s")
#endif

void func_8035BDC0_76D470(void) {
    static u16 D_803F2EA0; // .bss
    u16 *palette;
    s16 temp_t7;
    s16 temp_t8;
    s16 i;

    if (D_803F2EA0 != D_803D5544) {
        D_803F2EA0 = D_803D5544;

        palette = (u16*)(D_801D9EC4 + SEGMENT_OFFSET(D_04009BF0_FAC50));

        temp_t7 = ((SIN(D_803D5540) >> 7) + 0x100) >> 1;
        temp_t8 = ((COS(((D_803D5544 & 0xFFF) * 7) >> 3) >> 7) + 0x100) >> 1;

        for (i = 0; i < 7; i++) {
            // rgba16
            palette[i+1] = ((s16)(((i * 7) * temp_t7) / 1536) << 11) | ((s16)((((i * 18) * temp_t7) / 1536) + 13) << 6) | ((s16)(((i * 7) * temp_t7) / 1536) << 1) | 1;
            palette[i+8] = ((s16)(((i * 7) * temp_t8) / 1536) << 11) | ((s16)((((i * 18) * temp_t8) / 1536) + 13) << 6) | ((s16)(((i * 7) * temp_t8) / 1536) << 1) | 1;
        }
    }
}

void func_8035C018_76D6C8(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CHAMELEON_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_8035C08C_76D73C(void) {
    if ((D_803D552C->unk365 != ATTACK_CHAMELEON_1) &&
        (D_803D552C->unk365 != ATTACK_CHAMELEON_2)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CHAMELEON_1;
    }
}

void func_8035C0CC_76D77C(void) {
    if ((D_803D552C->unk365 != ATTACK_CHAMELEON_1) && (D_803D552C->unk365 != ATTACK_CHAMELEON_2)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CHAMELEON_2;
    }
}

void func_8035C10C_76D7BC(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CHAMELEON_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_8035C180_76D830(s16 arg0) {
    D_803D552C->unk2EC = arg0;
}
