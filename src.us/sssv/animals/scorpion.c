#include <ultra64.h>
#include "common.h"

extern Gfx D_01003548[];
extern Gfx D_01003588[];
extern Gfx D_01003780_3D050[];

extern Vtx D_04006190[];
extern Vtx D_040063D0[];

extern Gfx D_04005950_ECF00[];
extern Gfx D_04005B20_ED0D0[];
extern Gfx D_04005C80_ED230[];
extern Gfx D_04005D70_ED320[];
extern Gfx D_04005E40_ED3F0[];
extern Gfx D_04006140_ED6F0[];
extern Gfx D_04006610_EDBC0[];
extern Gfx D_04006620_EDBD0[];
extern Gfx D_04006638_EDBE8[];
extern Gfx D_04006658_EDC08[];
extern Gfx D_04005E60_ED410[];

extern s16 D_803B5160_7C6810[];
extern s16 D_803B5190_7C6840[];
extern s16 D_803B51C0_7C6870[];
extern u8  D_803B51D4_7C6884[];
extern u8  D_803B51EC_7C689C[];

extern s16 D_803B5204_7C68B4[];
extern s16 D_803B5234_7C68E4[];
extern u8  D_803B5298_7C6948[];
extern s16 D_803B52FC_7C69AC[];


void func_80378B84_78A234(s16 arg0, s16 *arg1, s16 *arg2, s16 *arg3, s16 *arg4, Animal *arg5);

#if 0
// CURRENT (3799)
void func_80376D40_7883F0(void) {
    struct061 sp120;
    s16 sp11E;
    s16 sp11C;
    s16 sp11A;
    s16 sp114;
    s16 sp112;
    s16 sp110;
    s16 sp10E;
    s16 sp108;
    s16 sp106;
    s16 sp104;
    Vtx *spF8;
    u32 spF4;
    s32 tailIndex;

    s16 temp_s1;
    s16 temp_t2;
    s16 temp_t3;

    s16 var_s2;
    s16 var_s3;
    s16 var_v0_2;

    s32 temp_t1_2;
    s32 temp_t5;
    u16 ticks_remaining;
    u8 temp_v0_17;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp11A = 0;
        D_803F2EDD = 0;
    } else {
        sp11A = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x780, 5, 0x99, 0, 0, 1, CHECK_SEGMENT == 0);
    }

    if (D_803D552C->unk365 == ATTACK_SCORPION_2) {
        sp11A = 0;
    }

    if (sp11A == 0) {
        func_8034B298_75C948(1);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 3) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 3) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 3) + FTOFIX32(1.0);
        func_8035D734_76EDE4();

        switch (D_803D552C->unk365) {                        /* irregular */
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        case ATTACK_SCORPION_1:
            func_802DCCAC_6EE35C(0x10);
            if ((D_803D5544 - D_803D552C->unk32A) == 4) {
                if (func_803224C4_733B74(7, 0x1B, 0, 0x20, 0x14, 0, 0, 9) != 0) {
                    play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                } else {
                    play_sound_effect_at_location(SFX_UNKNOWN_6, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
            }
            if (D_803D5528->unk3C8.unk2 != 0) {
                if ((D_803D5544 - D_803D552C->unk32A) < 8) {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 15;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 14;
                }
            }
            break;
        case ATTACK_SCORPION_2:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if ((D_803D552C->unk330 == NULL) || (D_803D552C->unk330->unk366 == 6)) {
                D_803D552C->unk365 = ATTACK_NONE;
            } else {
                if (ticks_remaining < 22) {
                    if (ticks_remaining == 1) {
                        play_sound_effect_at_location(SFX_UNKNOWN_83, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    }
                    if ((ticks_remaining == 13) && (D_803D5538 == 0)) {
                        rmonPrintf("mapStatus12:%d %d\n", D_803D5530->unk160, D_803D552C->unk330->unk160);

                        if (func_8033C9CC_74E07C(
                            D_803D5530->xPos.h,
                            D_803D5530->zPos.h,
                            D_803D5530->yPos.h + D_803D5530->unk42,
                            D_803D5530->unk160,
                            D_803D552C->unk330->xPos.h,
                            D_803D552C->unk330->zPos.h,
                            D_803D552C->unk330->yPos.h + D_803D552C->unk330->unk42,
                            D_803D552C->unk330->unk160,
                            0,
                            0)) {
                            rmonPrintf("ATTACK ABANDONED\n");
                            D_803D552C->unk365 = ATTACK_NONE;
                        }
                    }
                    if (ticks_remaining == 14) {
                        play_sound_effect_at_location(SFX_UNKNOWN_84, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    }
                    if (ticks_remaining >= 18) {
                        D_803D552C->unk30A = MAX(0, 0x14 - (ABS((s16)((D_803D552C->unk30C - D_803D552C->unk330->yPos.h) - (D_803D552C->unk330->unk42 >> 1))) >> 2));

                        if (ticks_remaining == 19) {
                            if ((D_803D552C->unk330->unk366 == 2) || (D_803D552C->unk330->unk366 == 5)) {
                                D_803D552C->unk330->yVelocity.w += D_803D552C->unk30A << 0xF;
                            } else if (D_803D552C->unk30A >= 0xB) {
                                func_802DBA58_6ED108(0xE, D_803D552C->unk330);
                            }
                        } else if (ticks_remaining == 21) {
                            if (D_803D552C->unk330->unk16C->unk9C == DESERT_FOX_ATTACKING) {
                                func_802B356C_6C4C1C(D_803D552C->unk330, D_803D552C->unk30A / 3, D_803D5524->unkE6, 0);
                            } else {
                                func_802B356C_6C4C1C(D_803D552C->unk330, D_803D552C->unk30A, D_803D5524->unkE6, 0);
                            }
                            if (D_803D5538 != 0) {
                                D_803D552C->unk330->unk2EB++;
                            }
                        }

                        for (sp104 = 0; sp104 < (D_803D552C->unk30A / 6); sp104++) {
                            temp_s1 = func_8012826C() & 0xFF;
                            create_particle_effect(
                                (SSSV_RAND(16) + D_803D552C->unk330->xPos.h) - 7,
                                (SSSV_RAND(16) + D_803D552C->unk330->zPos.h) - 7,
                                (SSSV_RAND(16) + D_803D552C->unk330->yPos.h + (D_803D552C->unk330->unk42 >> 1)) - 7,
                                24,
                                (SSSV_RAND(16) - 7) << 0xF,
                                (SSSV_RAND(16) - 7) << 0xF,
                                SSSV_RAND(16) << 0xF,
                                6,
                                GPACK_RGBA5551(temp_s1, temp_s1, 248, 1),
                                GPACK_RGBA5551(temp_s1, temp_s1, 248, 1),
                                0);
                        }
                    }
                    if ((D_803F3310 + 12) < 37) {
                        gSPDisplayList(D_801D9E88++, D_01003780_3D050);
                        gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

                        if (D_80152EB8 == 0) {
                            spF4 = &D_04006190[D_803F3310]; // (D_803F3310 * 0x10) +
                        } else {
                            spF4 = &D_040063D0[D_803F3310]; // (D_803F3310 * 0x10) +
                        }

                        spF8 = &D_801D9EC4[spF4 & 0xFFFFFF];
                        var_s2 = 0;

                        var_s3 = MAX(0, ticks_remaining - 4);
                        sp108 = MIN(20, ticks_remaining + 2);

                        if ((sp108 - var_s3) >= 3) {
                            for (sp106 = var_s3; sp106 < sp108; sp106++) {
                                func_80378B84_78A234(sp106, &sp114, &sp112, &sp110, &sp10E, D_803D552C->unk330);

                                if ((sp106 == var_s3) || (sp106 == sp108)) {
                                    // if first or last
                                    spF8[var_s2].v.ob[0] = sp112;
                                    spF8[var_s2].v.ob[1] = sp110;
                                    spF8[var_s2].v.ob[2] = sp10E;
                                    spF8[var_s2].v.tc[0] = 0;
                                    spF8[var_s2].n.n[0] = -1;
                                    spF8[var_s2].n.n[1] = -1;
                                    spF8[var_s2].n.n[2] = -1;
                                    spF8[var_s2].v.cn[3] = 0xFF;
                                    var_s2++;
                                } else {
                                    // otherwise
                                    spF8[var_s2].v.ob[0] = (((SSSV_RAND(16) - 7) * sp114) >> 4) + sp112;
                                    spF8[var_s2].v.ob[1] = (((SSSV_RAND(16) - 7) * sp114) >> 4) + sp110;
                                    spF8[var_s2].v.ob[2] = (((SSSV_RAND(16) - 7) * sp114) >> 4) + sp10E;
                                    spF8[var_s2].v.tc[0] = 0;
                                    spF8[var_s2].n.n[0] = 0xFF;
                                    spF8[var_s2].n.n[1] = 0xFF;
                                    spF8[var_s2].n.n[2] = 0xFF;
                                    spF8[var_s2].v.cn[3] = 0xFF;
                                    var_s2++;

                                    spF8[var_s2].v.ob[0] = (((SSSV_RAND(16) - 7) * sp114) >> 4) + sp112;
                                    spF8[var_s2].v.ob[1] = (((SSSV_RAND(16) - 7) * sp114) >> 4) + sp110;
                                    spF8[var_s2].v.ob[2] = (((SSSV_RAND(16) - 7) * sp114) >> 4) + sp10E;
                                    spF8[var_s2].v.tc[0] = 0;
                                    spF8[var_s2].n.n[0] = 0xFF;
                                    spF8[var_s2].n.n[1] = 0xFF;
                                    spF8[var_s2].n.n[2] = 0xFF;
                                    spF8[var_s2].v.cn[3] = 0xFF;
                                    var_s2++;
                                }
                            }

                            switch (sp108 - var_s3) {
                            case 3:
                                gSPVertex(D_801D9E88++, spF4, 4, 0);
                                gSPDisplayList(D_801D9E88++, D_04006610_EDBC0);
                                D_803F3310 += 4;
                                break;
                            case 4:
                                gSPVertex(D_801D9E88++, spF4, 6, 0);
                                gSPDisplayList(D_801D9E88++, D_04006620_EDBD0);
                                D_803F3310 += 6;
                                break;
                            case 5:
                                gSPVertex(D_801D9E88++, spF4, 8, 0);
                                gSPDisplayList(D_801D9E88++, D_04006638_EDBE8);
                                D_803F3310 += 8;
                                break;
                            case 6:
                                gSPVertex(D_801D9E88++, spF4, 10, 0);
                                gSPDisplayList(D_801D9E88++, D_04006658_EDC08);
                                D_803F3310 += 10;
                                break;
                            }
                        }
                    }
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
            }
            break;
        case ATTACK_NONE:
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0xE;
            }
            break;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp120, 0xFA, 0x8C, 0xFA, 0x3E);

            D_80203FE0[8].unk0 = D_80203FE0[3].unk0 + ((D_80203FE0[5].unk0 - D_80203FE0[3].unk0) / 3);
            D_80203FE0[8].unk2 = D_80203FE0[3].unk2 + ((D_80203FE0[5].unk2 - D_80203FE0[3].unk2) / 3);
            D_80203FE0[8].unk4 = D_80203FE0[3].unk4 + ((D_80203FE0[5].unk4 - D_80203FE0[3].unk4) / 3);

            D_80203FE0[14].unk0 =D_80203FE0[3].unk0 + (((D_80203FE0[5].unk0 - D_80203FE0[3].unk0) * 2) / 3);
            D_80203FE0[14].unk2 =D_80203FE0[3].unk2 + (((D_80203FE0[5].unk2 - D_80203FE0[3].unk2) * 2) / 3);
            D_80203FE0[14].unk4 =D_80203FE0[3].unk4 + (((D_80203FE0[5].unk4 - D_80203FE0[3].unk4) * 2) / 3);

            D_80203FE0[11].unk0 =D_80203FE0[4].unk0 + ((D_80203FE0[6].unk0 - D_80203FE0[4].unk0) / 3);
            D_80203FE0[11].unk2 =D_80203FE0[4].unk2 + ((D_80203FE0[6].unk2 - D_80203FE0[4].unk2) / 3);
            D_80203FE0[11].unk4 =D_80203FE0[4].unk4 + ((D_80203FE0[6].unk4 - D_80203FE0[4].unk4) / 3);

            D_80203FE0[17].unk0 =D_80203FE0[4].unk0 + (((D_80203FE0[6].unk0 - D_80203FE0[4].unk0) * 2) / 3);
            D_80203FE0[17].unk2 =D_80203FE0[4].unk2 + (((D_80203FE0[6].unk2 - D_80203FE0[4].unk2) * 2) / 3);
            D_80203FE0[17].unk4 =D_80203FE0[4].unk4 + (((D_80203FE0[6].unk4 - D_80203FE0[4].unk4) * 2) / 3);

            func_802C0364_6D1A14(0xFA, 0x3E, 0, 0, 0, 0, D_803B5160_7C6810, D_803B5190_7C6840, D_803B51C0_7C6870, 0xFA, 0x3E, 0xC0, 0xC0, 0xC0, 0xC0, D_803B5160_7C6810, D_803B5190_7C6840, D_803B51C0_7C6870, &sp120);
            func_802B964C_6CACFC();

            D_80203FE0[22].unk0 = D_80203FE0[1].unk0 - 250;
            D_80203FE0[22].unk2 = D_80203FE0[1].unk2 + ((D_803F2ED8 * 250) >> 7);
            D_80203FE0[24].unk0 = D_80203FE0[1].unk0 + 250;

            D_80203FE0[23].unk0 = D_80203FE0[22].unk0;
            D_80203FE0[23].unk2 = D_80203FE0[22].unk2 + 250;
            D_80203FE0[22].unk4 = D_80203FE0[1].unk4;

            D_80203FE0[24].unk2 = D_80203FE0[1].unk2 + ((D_803F2ED8 * 250) >> 7);
            D_80203FE0[23].unk4 = D_80203FE0[22].unk4 - ((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) >> 1);
            D_80203FE0[24].unk4 = D_80203FE0[1].unk4;

            D_80203FE0[25].unk0 = D_80203FE0[24].unk0;
            D_80203FE0[25].unk2 = D_80203FE0[24].unk2 + 250;
            D_80203FE0[25].unk4 = D_80203FE0[24].unk4 - ((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) >> 1);

            func_8034B3A8_75CA58(0);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B51D4_7C6884, D_803B51EC_7C689C, D_803B5204_7C68B4, D_803B5234_7C68E4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B51D4_7C6884, D_803B51EC_7C689C, D_803B5204_7C68B4, D_803B5298_7C6948);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_17 = D_803F2AA2, (temp_v0_17 == 0)) || (temp_v0_17 == 2) || ((temp_v0_17 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA << 3) / 5, 2, 3, 3, -0.1f);
            func_8034A320_75B9D0();
            gSPDisplayList(D_801D9E88++, D_01003588);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF); // RED

            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x28) >> 6, (D_803F2EC0 * 0x28) >> 6, (D_803F2EC4 * 0x28) >> 6, D_803F2ED0, 0, 0, 0, D_04005B20_ED0D0);
            gSPDisplayList(D_801D9E88++, D_01003548);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(22, 23, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, D_803F2ED0, 0, 0, 0, D_04005950_ECF00); }

            func_802C78B0_6D8F60(3, 7, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 0, 1, D_04005C80_ED230);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(8, 9, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 0, 1, D_04005C80_ED230); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(14, 15, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 0, 1, D_04005C80_ED230); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 13, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 0, 1, D_04005C80_ED230); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(24, 25, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_04005950_ECF00); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4,  10, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 2, 1, D_04005C80_ED230); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(11, 12, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 2, 1, D_04005C80_ED230); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(17, 18, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 2, 1, D_04005C80_ED230); }
            func_802C78B0_6D8F60(6, 0x10, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 2, 1, D_04005C80_ED230);

            var_v0_2 = ((((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) + 0x100) >> 4) * 0xFA) >> 8;
            if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
                var_v0_2 = 0;
            }

            D_80203FE0[22].unk0 -= var_v0_2;
            D_80203FE0[23].unk0 -= var_v0_2;
            D_80203FE0[24].unk0 += var_v0_2;
            D_80203FE0[25].unk0 += var_v0_2;

            D_80203FE0[22].unk2 += (D_803F2ED8 * 0xFA) >> 7;
            D_80203FE0[23].unk2 += (D_803F2ED8 * 0xFA) >> 7;
            D_80203FE0[24].unk2 += (D_803F2ED8 * 0xFA) >> 7;
            D_80203FE0[25].unk2 += (D_803F2ED8 * 0xFA) >> 7;

            gSPDisplayList(D_801D9E88++, D_01003588);

            func_802C78B0_6D8F60(0x16, 0x17, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, D_803F2ED0, 0, 0, 0, D_04006140_ED6F0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(0x18, 0x19, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, D_803F2ED0, 0, 1, 0, D_04006140_ED6F0);

            D_80203FE0[22].unk0 += ((((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) + 0x100) >> 4) * 250) >> 6;
            D_80203FE0[23].unk0 += ((((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) + 0x100) >> 4) * 250) >> 6;
            D_80203FE0[24].unk0 -= ((((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) + 0x100) >> 4) * 250) >> 6;
            D_80203FE0[25].unk0 -= ((((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) + 0x100) >> 4) * 250) >> 6;

            gSPDisplayList(D_801D9E88++, D_01003548);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(22, 23, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, D_803F2ED0, 0, 0, 0, D_04005D70_ED320); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(24, 25, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, (D_803F2EC8 * 0x28) >> 6, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_04005D70_ED320); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp11E, &sp11C);
                func_8031A278_72B928(&D_803D552C->unk326, &sp11E, &sp11C);
                sp11E = D_803BD5B2_7CEC62[sp11E]; sp11C = D_803BD66A_7CED1A[sp11C];
                func_80356BD8_768288(&D_01000CA0, &D_01002100, sp11E);
                func_802C78B0_6D8F60(1, 2, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 0, 0, D_04005E40_ED3F0);
                func_80356BD8_768288(&D_01000CA0, &D_01002100, sp11C);
                func_802C78B0_6D8F60(1, 2, FTOFIX32(0.625), FTOFIX32(0.625), FTOFIX32(0.625), D_803F2ED0, 0, 0, 0, D_04005E60_ED410);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp11A == 0) || (sp11A == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (D_803D552C->yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->unk302, D_01033190, 0x12, 0xF, 0x9B, 0, 0, 0, 0, D_803D5538);
    }

    tailIndex = D_803D5528->unk3C8.unk2;
    if (tailIndex != 0) {
        if ((sp11A == 0) && (D_803F2EDB != 0)) {
            temp_t1_2 = (D_80203FE0[2].unk2 >> 2) + D_80203FE0[2].unk2;
            temp_t2 = D_80152C78[D_803D552C->unk302 & 0xFF];
            temp_t3 = D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF];
            temp_t5 = D_80203FE0[2].unk0 + (D_80203FE0[2].unk0 >> 2);

            func_802DE914_6EFFC4(
                tailIndex,
                D_803D5530->xPos.w + ((temp_t1_2 * temp_t2) / 16) + ((temp_t3 * temp_t5) / 16),
                D_803D5530->zPos.w + ((temp_t3 * temp_t1_2) / 16) - ((temp_t5 * temp_t2) / 16),
                D_803D5530->yPos.w + ((D_80203FE0[2].unk4 << 0x10) / 32),
                D_803D552C->unk302);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3A74_7B5124);
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (sp11A == 0) {
        func_803034D0_714B80(D_803D552C, 500, 0, 0);
        D_803D5530->unkC4[0].unk8.h += 3;
        D_803D5530->unkC4[1].unk8.h += 3;
        func_80303D50_715400(D_803D552C, 2);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 500, 250);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/scorpion/func_80376D40_7883F0.s")
#endif

#if 0
void func_80378B84_78A234(s16 arg0, s16 *arg1, s16 *arg2, s16 *arg3, s16 *arg4, Animal *arg5) {
    s16 temp_t7_3;
    s16 temp_t7_4;

    s16 temp_s0;
    s16 temp_s1;

    s32 pad[2];

    s16 sp44;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp32;
    s16 sp30;
    s16 sp2E;
    volatile s16 sp2C;
    s32 pad2;

    temp_t7_3 = ((((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * ((D_80203FE0[4].unk0 >> 2) + D_80203FE0[4].unk0)) / 32) + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * (D_80203FE0[2].unk2 + (D_80203FE0[2].unk2 >> 2))) / 32)) >> 7;
    temp_t7_4 = ((((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * ((D_80203FE0[2].unk2 >> 2) + D_80203FE0[2].unk2)) / 32) - (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * (D_80203FE0[4].unk0 + (D_80203FE0[4].unk0 >> 2))) / 32)) >> 7;

    temp_s0 = D_803D552C->xPos.h - temp_t7_3;
    temp_s1 = D_803D552C->zPos.h - temp_t7_4;

    sp44 = D_803D552C->yPos.h;
    sp3C = D_803D552C->xPos.h + temp_t7_3;
    sp3A = D_803D552C->zPos.h + temp_t7_4;
    sp38 = D_803D552C->yPos.h;
    sp32 = D_803D552C->yPos.h + D_803D5524->unkBA;
    sp30 = arg5->xPos.h;
    sp2E = arg5->zPos.h;
    sp2C = D_803D552C->unk30C;

    if (arg0 < 5) {
        *arg2 = temp_s0 + (((sp3C - temp_s0) * arg0) / 4);
        *arg3 = temp_s1 + (((sp3A - temp_s1) * arg0) / 4);
        *arg4 = sp44 + (((sp38 - sp44) * arg0) / 4);
    } else if (arg0 < 11) {
        *arg2 = sp3C + (((temp_s0 - sp3C) * (arg0 - 4)) / 6);
        *arg3 = sp3A + (((temp_s1 - sp3A) * (arg0 - 4)) / 6);
        *arg4 = sp38 + (((sp32 - sp38) * (arg0 - 4)) / 6);
    } else if (arg0 < 17) {
        *arg2 = temp_s0 + (((sp2E - temp_s0) * (arg0 - 10)) / 6);
        *arg3 = temp_s1 + (((sp2E - temp_s1) * (arg0 - 10)) / 6);
        *arg4 = sp32 + (((sp2C - sp32) * (arg0 - 10)) / 6);
    } else {
        *arg2 = sp30;
        *arg3 = sp2E;
        *arg4 = sp2C;
    }
    *arg1 = D_803B52FC_7C69AC[arg0];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/scorpion/func_80378B84_78A234.s")
#endif

void func_80378FF8_78A6A8(void) {
    if (!D_803D552C) {
        // is this fakematch or debug stub?
    };

    if ((D_801D9ED8.unkFFBC == 0) && (D_801D9ED8.unkFFB6 != 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_SCORPION_1;
    }
}

void func_80379048_78A6F8(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SCORPION_1;
}

void func_80379070_78A720(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        Animal *a = func_8037ED1C_7903CC();
        if (a == NULL) {
            recharge_skill(1);
        } else {
            // perform lightning attack
            D_803D552C->unk330 = a;
            D_803D552C->unk365 = ATTACK_SCORPION_2;
            D_803D552C->unk32A = D_803D5544;
            D_803D552C->unk30C = D_803D552C->unk330->yPos.h + (D_803D552C->unk330->unk42 >> 1);
            do_rumble(0, 25, 5, 60, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
        }
    } else {
        recharge_skill(1);
    }
}

void func_80379148_78A7F8(Animal *a) {
    if ((D_803D552C->unk365 == ATTACK_NONE) && (a != NULL)) {
        D_803D552C->unk330 = a;
        D_803D552C->unk365 = ATTACK_SCORPION_2;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk30C = D_803D552C->unk330->yPos.h + (D_803D552C->unk330->unk42 >> 1);
    }
}

void func_803791AC_78A85C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SCORPION_1;
}
