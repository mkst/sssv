#include <ultra64.h>
#include "common.h"

extern Gfx D_040053F0[];
extern Gfx D_04005B10_F6B70[];
extern Gfx D_04005FB0[];
extern Gfx D_04006130[];
extern Gfx D_04006380[];
extern Gfx D_040063A0[];
extern u8  D_040063C0[];
extern u8  D_040067C0[];
extern u8  D_040067E0[];

extern s32 D_803B55B0_7C6C60;
extern struct077 D_803B55E0_7C6C90;
extern struct077 D_803B5610_7C6CC0;
extern s32 D_803B5624_7C6CD4;
extern s32 D_803B5654_7C6D04;
extern s32 D_803B5684_7C6D34;

extern u8  D_803B5698_7C6D48[];
extern u8  D_803B56A8_7C6D58[];
extern s16 D_803B56B8_7C6D68[];
extern s16 D_803B56D0_7C6D80[];
extern s16 D_803B5708_7C6DB8[];

void func_8037B800_78CEB0(void) {
    s32 pad2[2];
    s16 temp_t6;
    s32 var_v0;
    struct061 spB0;
    s16 spAE;
    s16 spAC;
    s16 spAA;
    s16 spA8;
    s16 spA6; // pad
    s16 spA4;
    s16 spA2;

    s16 pad[4];
    Animal *sp94;
    s16 sp92;
    u16 sp74;

    u16 ticks_remaining;
    u8 temp_v0_17;

    spA4 = 0x38;
    spA2 = 0;

    if (D_803D552C->unk365 == 0x10) {
        D_803D5528->unk3C0.unk0 = 0;
        if (D_803D5528->unk3C8.unk2 != 0) {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x12;
        }
        if (D_803D5530->unk4A != 0) {
            D_803D552C->unk32A += 1;
        } else {
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            var_v0 = MIN(0x10, ticks_remaining);

            func_8032CD70_73E420(
                D_803D5530,
                0xC,
                (var_v0 * 0x5000) >> 4,
                0,
                (f32) (((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) / 700.0) + 1.0),
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);

            if (ticks_remaining >= 0xD) {
                sp92 = D_803D552C->unk302;
                if (((ticks_remaining & 1) == 1) && ((((D_803D5530->state < 0xB5))) || (D_803D5530->state >= 0xBB))) {
                    D_803D552C->unk302 = (sp92 - (func_8012826C() & 0xF)) + 8;
                    func_80321E60_733510(
                        0x4F,
                        0x5A,
                        0,
                        0x2D,
                        ((func_8012826C()) & 3) + 0x11,
                        18 - SSSV_RAND(16),
                        3,
                        3);
                }
                D_803D552C->unk302 = sp92;
            }
            if (D_803D5538 == 0) {
                if (D_803D552C->unk2EC > 0) {
                    D_803D552C->unk2EC = D_803D552C->unk2EC - 1;
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                    if (D_803D5528->unk3C8.unk2 != 0) {
                        D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x10;
                    }
                }
            }
        }

        if (1) {}; // regalloc helper
    }

    if ((D_803D552C->unk366 == 5) || (D_803D552C->unk366 == 2)) {
        if (D_803D5528->unk3C8.unk2 != 0) {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x10;
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            spAA = 0;
            D_803F2EDD = 0;
            goto block_33;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
          var_v0 = 1;
      } else {
          var_v0 = 0;
      }
      spAA = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x1400, (u8) 0, (s16) 0x5A, (s16) 0x5A, (s16) 0x5A, (s8) 1, (u8) (var_v0 == 0));

block_33:
    if (spAA == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        func_8035D734_76EDE4();
        if (D_803D552C->unk320 != NULL) {
            D_803D5528->unk3C0.unk0 = 0;
        }

        switch (D_803D552C->unk365) {                        /* irregular */
        case ATTACK_GRAB:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x12;
            }
            if (ticks_remaining == 8) {
                D_803D552C->unk320 = func_803215DC_732C8C(0x64, 0x46);
                D_803D552C->unk365 = ATTACK_NONE;
                if (D_803D552C->unk320 != NULL) {
                    if (D_803D5528->unk3C8.unk2 != 0) {
                        D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x1F;
                    }
                    D_803D552C->unk308 = D_803D552C->unk320->unk40;
                    D_803D552C->unk320->unk40 = MIN(D_803D552C->unk320->unk40, 0x898);
                } else {
                    if (D_803D5528->unk3C8.unk2 != 0) {
                        D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x10;
                    }
                    if (func_803224C4_733B74(0x16, 0x34, 0, 0x23, 5, 0, 0,5) != 0) {
                        play_sound_effect_at_location(SFX_UNKNOWN_26, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    } else {
                        if ((D_803D5530->state < 0xB5) || (D_803D5530->state >= 0xBB)) {
                            play_sound_effect_at_location(SFX_ELEPHANT_TRUMP, 0x6000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                        }
                    }
                }
            }
            break;
        case ATTACK_BEAR_2:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 0x10) {
                if (ticks_remaining == 0xC) {
                    if (D_803D5528->unk3C8.unk2 != 0) {
                        D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x12;
                    }
                }

                spA2 =  (0x7D0 - (((D_80152C78[((s16)(ticks_remaining << 2) + 0x40) & 0xFF] >> 7) * 0x7D0) >> 8)) / 32;
                spA4 = ((        (((D_80152C78[ (s16)(ticks_remaining << 2)         & 0xFF] >> 7) * 0x7D0) >> 8)) / 32) + 0x38;

                if (ticks_remaining >= 9) {
                    spA4 = spA4 - (((ticks_remaining - 8) * 0x64) / 32);
                }
            } else {
                if (func_8033C9CC_74E07C(D_803D5530->xPos.h, D_803D5530->zPos.h, (s16) (D_803D5530->yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D5530->unk160, (s16) (s32) D_803D552C->unk320->xPos.h, (s16) (s32) D_803D552C->unk320->zPos.h, (s16) (D_803D552C->unk320->yPos.h + ((s32) D_803D552C->unk320->unk42 >> 1)), (u8) 0x7F, (u8) 0, (u8) 0) == 0) {
                    sp94 = D_803D552C->unk320;
                    D_803D552C->unk320->unk40 = D_803D552C->unk308;
                    func_80321920_732FD0(D_803D552C->unk320, 0x1E, 0);
                    sp94->unk10 += sp94->xVelocity.w;
                    sp94->unk14 += sp94->zVelocity.w;
                    sp94->unk18.w += sp94->yVelocity.w;
                    if ((D_803D5530->state < 0xB5) || (D_803D5530->state >= 0xBB)) {
                        play_sound_effect_at_location(SFX_ELEPHANT_TRUMP, 0x6000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    }
                    D_803D552C->unk365 = ATTACK_NONE;
                    if (D_803D5528->unk3C8.unk2 != 0) {
                        D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x10;
                    }
                } else {
                    if (D_803D5528->unk3C8.unk2 != 0) {
                        D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x1F;
                    }
                    func_8032C508_73DBB8(0x10, 0x4000, 0, 1.0f);
                    D_803D552C->unk365 = ATTACK_NONE;
                }
            }
            break;
        case ATTACK_BEAR_3:
            D_803D552C->unk320->unk40 = D_803D552C->unk308;
            func_80321920_732FD0(D_803D552C->unk320, 0, 0);
            D_803D552C->unk365 = ATTACK_NONE;
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x10;
            }
            break;
        case ATTACK_ELEPHANT_1:
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }
        if ((D_803D5528->unk3C8.unk2 != 0) && (D_803A6CE4_7B8394 & 8)) {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x1F;
        }

        if (((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4)) && (SSSV_RAND(256) == 0x9C) && ((D_803D5530->state < 0xB5) || (D_803D5530->state >= 0xBB))) {
            play_sound_effect_at_location(SFX_ELEPHANT_TRUMP, 0x6000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spB0, 0x271, 0x232, 0xB3B, 0x64);

            temp_t6 = ((D_80203FE0[3].unk4 + D_80203FE0[4].unk4) - D_80203FE0[5].unk4) - D_80203FE0[6].unk4;

            D_80203FE0[3].unk4 -= (temp_t6 * 6) >> 5;
            D_80203FE0[4].unk4 -= (temp_t6 * 6) >> 5;
            D_80203FE0[1].unk4 -= (temp_t6 * 6) >> 5;

            D_80203FE0[5].unk4 += (temp_t6 * 6) >> 5;
            D_80203FE0[6].unk4 += (temp_t6 * 6) >> 5;
            D_80203FE0[2].unk4 += (temp_t6 * 6) >> 5;

            func_802BF3C0_6D0A70(0xB3B, 0x64, 0x80, 0xB4, 0x80, 0xA0, &D_803B55B0_7C6C60, &D_803B55E0_7C6C90, &D_803B5610_7C6CC0, 0xB3B, 0x64, 0xE4, 0x64, 0xE4, 4, &D_803B5624_7C6CD4, &D_803B5654_7C6D04, &D_803B5684_7C6D34, &spB0);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0xFA, 0x2EE, 8);
            func_802C56D0_6D6D80(0x37);

            if (D_803D552C->unk320 != NULL) {
                D_80203FE0[19].unk4 += ((D_803D552C->unk320->unk40 * 0x2EE) - FTOFIX32(17.1661376953125)) / 600;
                D_80203FE0[20].unk4 += ((D_803D552C->unk320->unk40 * 0x2EE) - FTOFIX32(17.1661376953125)) / 600;
                D_80203FE0[19].unk2 -= ((D_803D552C->unk320->unk40 * 0x2EE) - FTOFIX32(17.1661376953125)) / 1600;
                D_80203FE0[20].unk2 -= ((D_803D552C->unk320->unk40 * 0x2EE) - FTOFIX32(17.1661376953125)) / 1600;
            } else {
                func_8038CCF0_79E3A0(0x177, 0x13, 0x14, -1, -1, -1);
            }
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B5698_7C6D48, D_803B56A8_7C6D58, D_803B56B8_7C6D68, D_803B56D0_7C6D80);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B5698_7C6D48, D_803B56A8_7C6D58, D_803B56B8_7C6D68, D_803B5708_7C6DB8);
                break;
            }
        }
        func_8038064C_791CFC();
        D_80203FE0[19].unk4 += (D_803F63E0 * 0x2EE) >> 7;
        D_80203FE0[20].unk4 += (D_803F63E0 * 0x2EE) >> 7;

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_17 = D_803F2AA2, (temp_v0_17 == 0)) || (temp_v0_17 == 2) || ((temp_v0_17 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((*D_803F2C18 != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4 / 3);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0xA0) >> 6, (D_803F2EC0 * 0xA0) >> 6, (D_803F2EC4 * 0xA0) >> 6, D_803F2ED0, 0, 0, 0, D_040053F0);
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0xA0) >> 6, (D_803F2EC8 * 0xA0) >> 6, (D_803F2EC8 * 0xA0) >> 6, D_803F2ED0, 0, 0, 0, D_04005B10_F6B70);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0xA0) >> 6, (D_803F2EC0 * 0xA0) >> 6, (D_803F2EC4 * 0xA0) >> 6, D_803F2ED0, 0, 0, 0, D_04006130); }
            load_2_tiles(D_040067C0, D_040067E0, D_040063C0);
            gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);

            func_802C78B0_6D8F60(3,  7, 0x28000, 0x28000, 0x28000, D_803F2ED0, 0, 0, 0, D_04005FB0);
            func_802C78B0_6D8F60(5, 13, 0x28000, 0x28000, 0x28000, D_803F2ED0, 0, 0, 0, D_04005FB0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(4, 10, 0x28000, 0x28000, 0x28000, D_803F2ED0, 0, 1, 0, D_04005FB0);
            func_802C78B0_6D8F60(6, 16, 0x28000, 0x28000, 0x28000, D_803F2ED0, 0, 1, 0, D_04005FB0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spAE, &spAC);
                func_8031A278_72B928(&D_803D552C->unk326, &spAE, &spAC);
                spAE = D_803BD5B2_7CEC62[spAE]; spAC = D_803BD66A_7CED1A[spAC];
                func_80356BD8_768288(&D_01000CA0, &D_01002100, spAE);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0xA0) >> 6, (D_803F2EC8 * 0xA0) >> 6, (D_803F2EC8 * 0xA0) >> 6, D_803F2ED0, 0, 0, 0, D_04006380);
                func_80356BD8_768288(&D_01000CA0, &D_01002100, spAC);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0xA0) >> 6, (D_803F2EC8 * 0xA0) >> 6, (D_803F2EC8 * 0xA0) >> 6, D_803F2ED0, 0, 0, 0, D_040063A0);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }

    if ((spAA == 0) || (spAA == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, &D_01033190, 0x25, 0x25,  0x9B, 0, 0, 0, 0, D_803D5538);
    }

    spA8 = D_803D5528->unk3C8.unk2;
    if (spA8 != 0) {
        if ((spAA == 0) && (D_803F2EDB != 0)) {
            if (!(func_8012826C() & 0x7F)) {
                // swap?
                if (D_803E00C0[spA8].unk2E == 0x10) {
                    D_803E00C0[spA8].unk2E = 0x11;
                } else if (D_803E00C0[spA8].unk2E == 0x11) {
                    D_803E00C0[spA8].unk2E = 0x10;
                }
            }

            func_802DE914_6EFFC4(
                spA8,
                D_803D5530->xPos.w + ((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * D_80203FE0[20].unk0) / 16) + ((D_80152C78[D_803D552C->unk302 & 0xFF] * D_80203FE0[20].unk2) / 16),
                D_803D5530->zPos.w + ((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * D_80203FE0[20].unk2) / 16) - ((D_80152C78[D_803D552C->unk302 & 0xFF] * D_80203FE0[20].unk0) / 16),
                D_803D5530->yPos.w + ((D_80203FE0[20].unk4 << 0x10) / 32) + 0xFFE4A800,
                D_803D552C->unk302);

            if (D_803F2D10.unk0 == 0) {
                func_802DE7F4_6EFEA4(spA8, D_803D5530->xVelocity.w, D_803D5530->zVelocity.w, D_803D5530->yVelocity.w);
            }
            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A39C0_7B5070);
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    func_80321B70_733220(0, spA4, spA2);
    if (spAA == 0) {
        func_803034D0_714B80(D_803D552C, 0xE09, -0x271, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x2EE, 0);
        D_803D5530->unkC0.a.unkC0[0][6] -= 0xA;
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x4E2, 0xFA);
    }
}

void func_8037D06C_78E71C(void) {
    if ((D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) {
        func_8037D0EC_78E79C();
    } else if ((D_803D552C->unk365 == ATTACK_NONE) && (D_803D552C->unk320 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_ELEPHANT_1;
    }
}

void func_8037D0EC_78E79C(void) {
    s32 tmp = ATTACK_ELEPHANT_1;
    if (D_803D552C->unk365 == tmp) {
        D_803D552C->unk365 = ATTACK_NONE;
        if (D_803D5528->unk3C8.unk2 != 0) {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = tmp;
        }
    }
}

void func_8037D138_78E7E8(void) {
    if ((D_803D552C->unk320 == NULL) && (D_803D552C->unk365 == ATTACK_NONE)) {
        // FIXME: this fixes regalloc but is unlikely to be what the devs wrote:
        s32 fakematch = !D_803D552C->unk320->unk16C;
        if (fakematch) {}

        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_GRAB;
    } else if (D_803D552C->unk320) {
        s32 tmp = func_8033C9CC_74E07C(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5524->unkBA >> 1),
            D_803D5530->unk160,
            D_803D552C->unk320->xPos.h,
            D_803D552C->unk320->zPos.h,
            D_803D552C->unk320->yPos.h + (D_803D552C->unk320->unk42 >> 1),
            0x7F,
            0, 0);
        if (tmp == 0) {
            D_803D552C->unk32A = D_803D5544;
            if ((D_803D552C->unk320->unk16C->objectType == OBJECT_BOULDER) ||
                (D_803D552C->unk320->unk16C->objectType == 61)) {
                D_803D552C->unk365 = ATTACK_BEAR_2;
            } else {
                D_803D552C->unk365 = ATTACK_BEAR_3;
            }
        } else {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
        }
    }
}

void func_8037D268_78E918(s16 arg0) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_ELEPHANT_1;
        D_803D552C->unk2EC = arg0;
    }
}
