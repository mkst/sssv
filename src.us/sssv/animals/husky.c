#include <ultra64.h>
#include "common.h"

#include "camera.h"


extern struct077 D_803B45D8_7C5C88;
extern struct077 D_803B4608_7C5CB8;
extern struct077 D_803B4638_7C5CE8;
extern struct077 D_803B464C_7C5CFC;
extern struct077 D_803B467C_7C5D2C;
extern struct077 D_803B46AC_7C5D5C;

extern u8  D_803B47D4_7C5E84[];
extern u8  D_803B47E4_7C5E94[];
extern s16 D_803B47F4_7C5EA4[];
extern s16 D_803B4810_7C5EC0[];
extern s16 D_803B484C_7C5EFC[];

extern Gfx D_04003D50_E1310[];
extern Gfx D_04004AE0_E20A0[];
extern Gfx D_04004E60_E2420[];
extern Gfx D_04005120_E26E0[];
extern Gfx D_04005220_E27E0[];
extern u8  D_04005260_E2820[]; // palette
extern u8  D_04005460_E2A20[]; // palette
extern Gfx D_04005500_E2AC0[];
extern Gfx D_04005520_E2AE0[];
extern Gfx D_04005830_E2DF0[]; // missile

extern Gfx D_01003548_3CE18[];

void func_80368DD0_77A480(void) {
    s16 pad[4];
    u8 temp_v0_6;

    s32 spA8;
    s32 temp_a0_3;
    s16 spA2;
    struct061 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp92 = 0;
        D_803F2EDD = 0;
    } else {
        sp92 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x8C0, 5, 0xB2, 0xB2, 0xB2, 1, CHECK_SEGMENT == 0);
    }

    if (sp92 == 0) {
        func_8034B298_75C948(0);
        func_8037FCA8_791358();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(0x10, 0x1E, 8);
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        func_8035D734_76EDE4();
        if ((D_803D5528->unk3C8.unk2 != 0) && (D_803A6CE4_7B8394 & 8)) {
            D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 0x1F;
        }

        spA8 = 0;
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp98, 0xF6, 0xA4, 0x2FD, 0);
            spA8 = MAX(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w));
            if (D_803D5524->unkA4 < (spA8 >> 0xA)) {
                D_803D552C->unk310 = 0;
                func_802C1830_6D2EE0(0x2FD, &sp98);
            } else {
                D_803D552C->unk310 = 1;
                func_802BF3C0_6D0A70(0x2FD, 0x6D, 0x80, 0, 0x80, 0, &D_803B45D8_7C5C88, &D_803B4608_7C5CB8, &D_803B4638_7C5CE8,
                                     0x2FD, 0x6D, 0x80, 0, 0x80, 0, &D_803B464C_7C5CFC, &D_803B467C_7C5D2C, &D_803B46AC_7C5D5C,
                                     &sp98);

                D_80203FE0[8].unk0  = D_80203FE0[7].unk0;  D_80203FE0[8].unk2  = D_80203FE0[7].unk2;  D_80203FE0[8].unk4  = D_80203FE0[7].unk4;
                D_80203FE0[11].unk0 = D_80203FE0[10].unk0; D_80203FE0[11].unk2 = D_80203FE0[10].unk2; D_80203FE0[11].unk4 = D_80203FE0[10].unk4;
                D_80203FE0[14].unk0 = D_80203FE0[13].unk0; D_80203FE0[14].unk2 = D_80203FE0[13].unk2; D_80203FE0[14].unk4 = D_80203FE0[13].unk4;
                D_80203FE0[17].unk0 = D_80203FE0[16].unk0; D_80203FE0[17].unk2 = D_80203FE0[16].unk2; D_80203FE0[17].unk4 = D_80203FE0[16].unk4;
            }

            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x20, 0xDA, 6);
            func_802BB938_6CCFE8(0xF6);
            func_8038CCF0_79E3A0(8, 0x14, -1, -1, -1, -1);

            temp_a0_3 = D_80203FE0[1].unk4 - D_80203FE0[2].unk4;
            if (temp_a0_3 > 0) {
                D_80203FE0[19].unk4 += temp_a0_3 >> 1;
                D_80203FE0[20].unk4 += temp_a0_3 >> 1;
                D_80203FE0[19].unk2 -= (temp_a0_3 * 3) >> 2;
                D_80203FE0[20].unk2 -= (temp_a0_3 * 3) >> 2;
            }
            spA8 = MIN(((spA8 >> 8) * 0x2FD) >> 0xC, 0x23D);
            D_80203FE0[1].unk4 -= spA8;
            D_80203FE0[19].unk4 -= spA8;
            D_80203FE0[20].unk4 -= spA8;
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B47D4_7C5E84, D_803B47E4_7C5E94, D_803B47F4_7C5EA4, D_803B4810_7C5EC0);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B47D4_7C5E84, D_803B47E4_7C5E94, D_803B47F4_7C5EA4, D_803B484C_7C5EFC);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || ((temp_v0_6 = D_803F2AA2) == 0) || (temp_v0_6 == 2) || ((temp_v0_6 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, (s32) D_803F2EB0 / 4, D_803F2EB4 / 4, (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.1f);
            load_1_tile(D_04005460_E2A20, D_04005260_E2820);

            func_802C78B0_6D8F60(2,   1, (D_803F2EBC * 0x46) >> 6, (D_803F2EC0 * 0x46) >> 6, (D_803F2EC4 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04004AE0_E20A0);
            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04004E60_E2420);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EBC) >> 4) * 0x46) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC0) >> 4) * 0x46) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC4) >> 4) * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04005830_E2DF0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleRight + 8) * D_803F2EBC) >> 4) * 0x46) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC0) >> 4) * 0x46) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC4) >> 4) * 0x46) >> 6, D_803F2ED0, 0, 1, 0, D_04005830_E2DF0); }

            func_802C78B0_6D8F60(8,  14, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 0, D_04005120_E26E0);
            func_802C78B0_6D8F60(11, 17, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 0, D_04005120_E26E0);

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 8, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003D50_E1310); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 8, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04005220_E27E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 0xE, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003D50_E1310); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 0xE, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04005220_E27E0); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xB, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003D50_E1310); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xB, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04005220_E27E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x11, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003D50_E1310); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x11, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04005220_E27E0); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp96, &sp94);
                func_8031A278_72B928(&D_803D552C->unk326, &sp96, &sp94);
                sp96 = D_803BD5B2_7CEC62[sp96]; sp94 = D_803BD66A_7CED1A[sp94];
                func_80356BD8_768288(D_01000CC0_3A590, D_01002100_3B9D0, sp96);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04005500_E2AC0);
                func_80356BD8_768288(D_01000CC0_3A590, D_01002100_3B9D0, sp94);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04005520_E2AE0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }

    if ((sp92 == 0) || (sp92 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->heading, D_01033190_6CA60, (s16) 0x19, (s16) 0xF, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }

    spA2 = D_803D5528->unk3C8.unk2;
    if (spA2 != 0) {
        if ((sp92 == 0) && (D_803F2EDB != 0)) {
            switch (D_803D5524->unk9C) {
            case HUSKY:
                D_803E00C0[spA2].tailType = 11;
                break;
            case CRAZY_HUSKY:                                /* switch 1 */
                D_803E00C0[spA2].tailType = 12;
                break;
            }

            func_802DE914_6EFFC4(spA2,
                D_803D5530->position.xPos.w + ((COS(D_803D552C->heading) * 4 * D_80203FE0[26].unk0) / 64) + ((SIN(D_803D552C->heading) * 4 * D_80203FE0[26].unk2) / 64),
                D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * 4 * D_80203FE0[26].unk2) / 64) - ((SIN(D_803D552C->heading) * 4 * D_80203FE0[26].unk0) / 64),
                D_803D5530->position.yPos.w + ((D_80203FE0[26].unk4 << 0xF) / 16),
                D_803D552C->heading);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, D_803A3990_7B5040);
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }

    }
    if (sp92 == 0) {
        D_80203FE0[1].unk4 += spA8 >> 1;
        D_80203FE0[19].unk4 += spA8 >> 1;
        D_80203FE0[20].unk4 += spA8 >> 1;
        func_803034D0_714B80(D_803D552C, 0x3D8, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0xDA, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x1EC, 0x111);
    }
}

extern s16 D_803B4564_7C5C14[];
extern s16 D_803B4594_7C5C44[];
extern s16 D_803B45C4_7C5C74[];
extern u8  D_803B46C0_7C5D70[];
extern u8  D_803B46D8_7C5D88[];
extern s16 D_803B46F0_7C5DA0[];
extern s16 D_803B471C_7C5DCC[];
extern s16 D_803B4778_7C5E28[];

extern u8  D_803B4888_7C5F38[];  // texture
extern u8  D_803B4908_7C5FB8[];

extern f32 D_803BEF64_7D0614;

extern Gfx D_010039F8_3D2C8[];

extern Gfx D_04003AE0_E10A0[];
extern Gfx D_04003BD0_E1190[];
extern Gfx D_04003C90_E1250[];
extern Gfx D_04003F70_E1530[];
extern Gfx D_04004560_E1B20[];
extern Gfx D_04004850_E1E10[];


void func_8036A05C_77B70C(void) {
    s32 pad[2];
    u8 temp_a0_4;
    u8 temp_v0_5;
    s16 temp_a0_3;

    struct061 sp104;
    s16 sp102;
    s16 sp100;
    s16 spFE;
    s16 spFC;
    s16 spFA; // pad
    s16 spF8;
    s32 spF4;
    s32 spF0;
    s32 spEC;
    s32 dl;

    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + 0x30000) & 0x7FFF,
            0x1E,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
        if (D_803D552C->unk2EC-- <= 0) {
            D_803D552C->unk36E = 0;
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spFE = 0;
        D_803F2EDD = 0;
    } else {
        spFE = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x8C0, 5, 0xB2, 0xB2, 0xB2, 1, CHECK_SEGMENT == 0);
    }

    if (spFE == 0) {
        dl = D_01003548_3CE18; // lol, thanks permuter!

        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(0x10, 0x1E, 8);
        if (D_803D5524->unk9C == HUSKY) {
            D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
            D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
            D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        }
        func_8035D734_76EDE4();
        if ((D_803D5528->unk3C8.unk2 != 0) && (D_803A6CE4_7B8394 & 8)) {
            D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 0x1F;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            D_803F2F00 = 0;
            func_802B9130_6CA7E0(&sp104, 0xF6, 0x5C, 0x2C6, 0x6D);
            func_802BD40C_6CEABC(0x111, 0x111, 0xA4, 0x6D,    0, 0x80, 0x64, 0x80, D_803B4564_7C5C14, D_803B4594_7C5C44, D_803B45C4_7C5C74,
                                 0x111, 0x111, 0xA4, 0x6D, 0x80,     0,   0, 0x1E, D_803B4564_7C5C14, D_803B4594_7C5C44, D_803B45C4_7C5C74,
                                 &sp104, 1);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x20, 0xDA, 6);
            func_8038CCF0_79E3A0(0x36, 0x14, -1, -1, -1, -1);

            switch (D_803D5524->unk9C) {
            case HUSKY:
                func_802BB938_6CCFE8(0xF6);
                break;
            case CRAZY_HUSKY:
                if (D_803D552C->unk30E > 0) {
                    D_803D552C->unk30E--;
                }
                func_802BB938_6CCFE8(0x111);
                break;
            }
            temp_a0_3 = D_80203FE0[1].unk4 - D_80203FE0[2].unk4;
            if (temp_a0_3 > 0) {
                D_80203FE0[19].unk4 += temp_a0_3 >> 1;
                D_80203FE0[20].unk4 += temp_a0_3 >> 1;
                D_80203FE0[19].unk2 -= (temp_a0_3 * 3) >> 2;
                D_80203FE0[20].unk2 -= (temp_a0_3 * 3) >> 2;
            }
            switch (D_803F2F00) {
            case 1:
                func_80374660_785D10(-5, 0, 1000);
                break;
            case 2:
                func_80374660_785D10(5, 0, 1000);
                break;
            case 3:
                func_80374660_785D10(-5, 0, 1000);
                break;
            case 4:
                func_80374660_785D10(5, 0, 1000);
                break;
            }
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B46C0_7C5D70, D_803B46D8_7C5D88, D_803B46F0_7C5DA0, D_803B471C_7C5DCC);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B46C0_7C5D70, D_803B46D8_7C5D88, D_803B46F0_7C5DA0, D_803B4778_7C5E28);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_5 = D_803F2AA2, (temp_v0_5 == 0)) || (temp_v0_5 == 2) || ((temp_v0_5 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.1f);
            load_1_tile(D_04005460_E2A20, D_04005260_E2820);

            switch (D_803D5524->unk9C) {
            case HUSKY:
                func_802C78B0_6D8F60(2,   1, (D_803F2EBC * 0x46) >> 6, (D_803F2EC0 * 0x46) >> 6, (D_803F2EC4 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04004AE0_E20A0);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04004E60_E2420);
                break;
            case CRAZY_HUSKY:
                spF8 = ((SIN(D_803D5540 << 5) >> 7) + 0x64) >> 2;
                if (D_803D5530->state == STATE_STANDING) {
                    spF8 = spF8 >> 2;
                }
                if (!((D_803D5540 << 5) & 0xFF) && (D_803D5530->unk4A == 0)) {
                    // animal within range?
                    if (func_803224C4_733B74(0x16, 0x26, 0, 0xE, 0xF, 0, 0, 0x11) != 0) {
                        play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_6, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                }
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x46) >> 6, (D_803F2EC0 * 0x46) >> 6, (s32) (D_803F2EC4 * 0x46) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 0, D_04003F70_E1530);
                D_80203FE0[20].unk4 -= spF8;
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 0, D_04004850_E1E10); }
                D_80203FE0[20].unk4 += (spF8 * 3) >> 1;
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 0, D_04004560_E1B20);
                D_80203FE0[20].unk4 -= spF8; // D_80204084
                func_8034B008_75C6B8(0x13, 0x14, 0x96, &spF4, &spF0, &spEC);

                gDPLoadTextureBlock_4b(
                  /* pkt    */ D_801D9EB8++,
                  /* timg   */ D_803B4888_7C5F38,
                  /* fmt    */ G_IM_FMT_CI,
                  /* width  */ 16,
                  /* height */ 16,
                  /* pal    */ 0,
                  /* cms    */ G_TX_NOMIRROR | G_TX_WRAP,
                  /* cmt    */ 0,
                  /* masks  */ G_TX_NOMASK,
                  /* maskt  */ G_TX_NOMASK,
                  /* shifts */ G_TX_NOLOD,
                  /* shiftt */ G_TX_NOLOD
                );

                gSPDisplayList(D_801D9EB8++, D_010039F8_3D2C8);

                gDPLoadTLUT_pal16(
                    /* pkt  */ D_801D9EB8++,
                    /* pal  */ 0,
                    /* dram */ D_803B4908_7C5FB8
                );

                gDPSetPrimColor(D_801D9EB8++, 0, 0, 0xFF, 0xFF, 0xFF, 0x00);

                func_8032E150_73F800(
                    &D_801D9EB8,
                    (SIN(D_803D5540 << 3) * 9) + spF4,
                    (COS(D_803D5540 << 3) * 7) + spF0,
                    (SIN(D_803D5540 << 5) * 3) + spEC,
                    0x10,
                    0x10,
                    1748);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    (SIN((D_803D5540 << 3) + 0x80) * 9) + spF4,
                    (SIN((D_803D5540 << 3) + 0x40) * 7) + spF0,
                    (SIN((D_803D5540 << 5) + 0x80) * 3) + spEC,
                    0x10,
                    0x10,
                    1748);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    (COS(D_803D5540 << 3) * 7) + spF4,
                    (SIN(D_803D5540 << 3) * 9) + spF0,
                    (SIN(D_803D5540 << 4) * 3) + spEC,
                    0x10,
                    0x10,
                    1748);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    (SIN((D_803D5540 << 3) + 0x40) * 7) + spF4,
                    (SIN((D_803D5540 << 3) + 0x80) * 9) + spF0,
                    (SIN((D_803D5540 << 4) + 0   ) * 3) + spEC,
                    0x10,
                    0x10,
                    1748);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    (SIN(D_803D5540 << 3) * 8) + spF4,
                    (SIN(D_803D5540 << 3) * 8) + spF0,
                    (COS(D_803D5540 << 5) * 2) + spEC,
                    0x10,
                    0x10,
                    1748);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    (COS((D_803D5540 << 3) + 0   ) * 8) + spF4,
                    (COS((D_803D5540 << 3) + 0   ) * 8) + spF0,
                    (COS((D_803D5540 << 4) + 0x80) * 3) + spEC,
                    0x10,
                    0x10,
                    1748);

                if (!(D_803D5540 & 3) && (SSSV_RAND(16) == 0)) {
                    create_particle_effect(
                        spF4 >> 0x10,
                        spF0 >> 0x10,
                        spEC >> 0x10,
                        37,
                        D_803D5530->xVelocity.w >> 1,
                        D_803D5530->zVelocity.w >> 1,
                        D_803D5530->yVelocity.w >> 1,
                        8,
                        GPACK_RGBA5551(255, 255, 255, 1),
                        GPACK_RGBA5551(255, 255, 255, 1),
                        0);
                }
                D_80203FE0[20].unk4 += spF8;
                break;
            }

            gSPDisplayList(D_801D9E88++, dl);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3,   7, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003C90_E1250); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5,  13, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003C90_E1250); }

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7,   8, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003BD0_E1190); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(13, 14, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003BD0_E1190); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4,  10, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003C90_E1250); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6,  16, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003C90_E1250); }

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(10, 11, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003BD0_E1190); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(16, 17, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003BD0_E1190); }

            gSPDisplayList(D_801D9E88++, dl);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

            func_802C78B0_6D8F60(8,   9, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003AE0_E10A0);
            func_802C78B0_6D8F60(14, 15, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 0, 0, D_04003AE0_E10A0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(11, 12, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003AE0_E10A0);
            func_802C78B0_6D8F60(17, 18, FTOFIX32(1.09375), FTOFIX32(1.09375), FTOFIX32(1.09375), D_803F2ED0, 0, 1, 0, D_04003AE0_E10A0);

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp102, &sp100);
                func_8031A278_72B928(&D_803D552C->unk326, &sp102, &sp100);
                sp102 = D_803BD5B2_7CEC62[sp102]; sp100 = D_803BD66A_7CED1A[sp100];
                func_80356BD8_768288(D_01000CC0_3A590, D_01002100_3B9D0, sp102);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04005500_E2AC0);
                func_80356BD8_768288(D_01000CC0_3A590, D_01002100_3B9D0, sp100);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, (D_803F2EC8 * 0x46) >> 6, D_803F2ED0, 0, 0, 0, D_04005520_E2AE0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spFE == 0) || (spFE == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, D_01033190_6CA60, 0x19, 0xF, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    spFC = D_803D5528->unk3C8.unk2;
    if (spFC != 0) {
        if ((spFE == 0) && (D_803F2EDB != 0)) {
            switch (D_803D5524->unk9C) {                   /* switch 4; irregular */
            case HUSKY:                                /* switch 4 */
                D_803E00C0[spFC].tailType = 11;
                break;
            case CRAZY_HUSKY:                                /* switch 4 */
                D_803E00C0[spFC].tailType = 12;
                break;
            }

            func_802DE914_6EFFC4(spFC,
                D_803D5530->position.xPos.w + ((COS(D_803D552C->heading) * 4 * D_80203FE0[26].unk0) / 64) + ((SIN(D_803D552C->heading) * 4 * D_80203FE0[26].unk2) / 64),
                D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * 4 * D_80203FE0[26].unk2) / 64) - ((SIN(D_803D552C->heading) * 4 * D_80203FE0[26].unk0) / 64),
                D_803D5530->position.yPos.w + ((D_80203FE0[26].unk4 << 0xF) / 16),
                D_803D552C->heading);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, D_803A3990_7B5040);
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (spFE == 0) {
        func_803034D0_714B80(D_803D552C, 0x3D8, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x1B4, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x1EC, 0x111);
    }
    if ((D_803D5538 == 0) && (D_803D5524->unk9C == CRAZY_HUSKY)) {
        if (D_803D552C->unk2EC <= 0) {
            load_animal(HUSKY);
        } else {
            D_803D552C->unk2EC--;
        }
    }
}

void func_8036BBB8_77D268(void) {
    D_803D552C->unk30E = 15;
    load_animal(CRAZY_HUSKY);
}

void func_8036BBE8_77D298(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + FTOFIX32(3.0)) & (FTOFIX32(0.5) - 1),
            30,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
    } else {
        set_target_speed(11);
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
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

void func_8036BCF8_77D3A8(void) {
    Animal *animal;
    s16 offset;

    animal = func_8037E9AC_79005C();
    if (get_missile_side() != 0) {
        offset = 369;
    } else {
        offset = -369;
    }
    fire_homing_missile(
        D_803D5530->position.xPos.h + ((((COS(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.zPos.h - ((((SIN(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1),
        10,
        ((D_803D552C->heading & 0xFF) * 360) >> 8,
        animal,
        2,
        16,
        0.3f,
        30,
        16,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

// 'crazy' husky
void func_8036BE70_77D520(void) {
    if (D_803D552C->unk30E <= 0) {
        load_animal(HUSKY);
    }
}

void ski_husky_fire_missile(Animal *arg0) {
    s16 offset;

    if (get_missile_side() != 0) {
        offset = 369;
    } else {
        offset = -369;
    }
    fire_homing_missile(
        D_803D5530->position.xPos.h + ((((COS(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.zPos.h - ((((SIN(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1),
        10,
        ((D_803D552C->heading & 0xFF) * 360) >> 8,
        arg0,
        4,
        16,
        0.3f,
        40,
        16,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void func_8036C014_77D6C4(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == HUSKY) {
        load_animal(CRAZY_HUSKY);
    }
}

void ski_husky_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 11;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
