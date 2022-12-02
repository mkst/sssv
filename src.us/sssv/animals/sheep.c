#include <ultra64.h>
#include "common.h"

extern s16 D_803B41D8_7C5888[];
extern s16 D_803B4010_7C56C0[];
extern s16 D_803B4040_7C56F0[];
extern s16 D_803B4070_7C5720[];
extern s16 D_803B40B4_7C5764[];
extern s16 D_803B40E4_7C5794[];
extern s16 D_803B40F8_7C57A8[];
extern s16 D_803B4084_7C5734[];
extern s16 D_803B4108_7C57B8[];
extern s16 D_803B4118_7C57C8[];
extern s16 D_803B4130_7C57E0[];
extern s16 D_803B4168_7C5818[];

extern Gfx D_040029D0_CA400[];
extern Gfx D_04002D90_CA7C0[];
extern Gfx D_04002F28_CA958[];
extern Gfx D_040032E8_CAD18[];
extern Gfx D_04003580_EAB30[];
extern Gfx D_040036B0_CB0E0[];
extern Gfx D_040037A0_CB1D0[];
extern Gfx D_040037C0_CB1F0[];
extern Gfx D_04003DE0_CB810[];

void func_8038C484_79DB34(s16 arg0, s16 arg1, s16 arg2, f32 arg3, s16 arg4);


// load_sheep_or_ram
void func_8035FE90_771540(void) {
    u8  var_v1;
    u8  temp_v0_11;
    s16 sp94;   // pretty sure this should be struct061
    s16 sp92;
    s16 sp90;
    s16 sp8E;
    s16 sp8C;

    u16 temp_t7;
    s16 pad[2];

    // only sheep can float
    if ((D_803D5538 == 0) && (D_803D5524->unk9C == SHEEP)) {
        if ((D_803D5530->unk162 == 3) && (D_803D552C->unk366 != 5)) {

            D_803D5530->yVelocity.w = (((D_803D5530->yVelocity.w * 3) + FTOFIX32(9.0)) >> 2) - FTOFIX32(3.0);

            if (D_803D5530->yVelocity.w < 0) {
                D_803D5530->yVelocity.w += (D_803A05B0_7B1C60 * 0xF) >> 4;
            } else {
                D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
            }
            D_803D5530->yVelocity.w += (D_80152C78[((s16)(D_803D5540 * 4) + 64) & 0xFF] >> 7) << 8;
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }

        if (var_v1 != 0) {
            sp8C = 0;
            D_803F2EDD = 0;
            goto block_17;
        }
    }
    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    // label has to be on this line for regalloc!
    sp8C = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x5F0, 0, 0x94, 0x94, 0x94, 1, var_v1 == 0); block_17:
    if (sp8C == 0) {
        if (((D_803D5538 != 0) && (D_803D5524->unk9C == SHEEP)) && (D_803D5530->unk162 == 1)) {
            D_803D552C->energy[0].unk0 = MIN(0x400, D_803D552C->energy[0].unk0 + 50);
        }
        func_8034B298_75C948(0);

        if (D_803D552C->unk366 != 5) {
            func_803622DC_77398C();
        }
        func_8035D120_76E7D0();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0xFF);

        if (((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4)) && (SSSV_RAND(256) == 156) && (D_803F2D50.unk52 != 3)) {
            func_8037FEDC_79158C();
        }

        switch (D_803D552C->unk365) {                        /* irregular */
        case ATTACK_NONE:
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        case ATTACK_SHEEP_HEADBUTT:
            func_802DCCAC_6EE35C(16);
            if (((D_803D5544 - D_803D552C->unk32A) == 4) && (func_803224C4_733B74(27, 46, 0, 20, 12, 0, 0, 16))) {
                play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            }
            break;
        case ATTACK_SHEEP_FLOAT:
            temp_t7 = (D_803D5544 - D_803D552C->unk32A);
            if (temp_t7 > 15) {
                D_803D552C->unk365 = ATTACK_NONE;
            } else {
                D_803F2ECE = 1;
                D_803F2ECC = D_803B41D8_7C5888[temp_t7];
            }
            break;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B9130_6CA7E0(&sp94, 178, 118, 831, 0);
            func_802BF3C0_6D0A70(831, 0, 0, 0x80, 0, 0x80, D_803B4010_7C56C0, D_803B4040_7C56F0, D_803B4070_7C5720, 831, 0, 0, 0x80, 0x80, 0, D_803B4084_7C5734, D_803B40B4_7C5764, D_803B40E4_7C5794, &sp94);
            func_802B964C_6CACFC();

            D_80203FE0[26].unk0 = D_80203FE0[27].unk0 = D_80203FE0[0].unk0;
            D_80203FE0[26].unk4 = D_80203FE0[0].unk4 + 593;
            D_80203FE0[27].unk4 = D_80203FE0[0].unk4 - 593;
            D_80203FE0[26].unk2 = D_80203FE0[27].unk2 = D_80203FE0[0].unk2;
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B40F8_7C57A8, D_803B4108_7C57B8, D_803B4118_7C57C8, D_803B4130_7C57E0);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B40F8_7C57A8, D_803B4108_7C57B8, D_803B4118_7C57C8, D_803B4168_7C5818);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_11 = D_803F2AA2, (temp_v0_11 == 0)) || (temp_v0_11 == 2) || ((temp_v0_11 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.38f);
            if (D_803D552C->unk366 != 5) {
                func_802C78B0_6D8F60(26, 27, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_04002D90_CA7C0);
            } else {
                func_802C78B0_6D8F60(26, 27, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_040032E8_CAD18);
            }
            if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x8F) || (D_803D5530->state == 0x8D)) {
                func_803032DC_71498C(0x1A, 0, -D_803D552C->unk35A / 110.0);
                func_803032DC_71498C(0x1B, 0, -D_803D552C->unk35A / 110.0);
            }
            func_8038CCF0_79E3A0(0x164, 0x1A, 0x1B, -1, -1, -1);

            // determine which head to draw
            switch (D_803D5524->unk9C) {
            case SHEEP:
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x1A, 0x1B, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_040036B0_CB0E0); }
                break;
            case RAM:
                // head with horns
                D_80203FE0[26].unk2 += D_803F2ED8 << 5;
                D_80203FE0[27].unk2 += D_803F2ED8 << 5;
                func_802C78B0_6D8F60(0x1A, 0x1B, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_04003DE0_CB810);
                D_80203FE0[26].unk2 -= D_803F2ED8 << 5;
                D_80203FE0[27].unk2 -= D_803F2ED8 << 5;
                break;
            }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_04003580_EAB30); }
            func_802C78B0_6D8F60(5, 13, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_04003580_EAB30);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(4, 10, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 1, 0, D_04003580_EAB30);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x10, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 1, 0, D_04003580_EAB30); }
            if ((D_803D5524->unk9C == SHEEP) && (D_803F2EDD == 0)) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp90, &sp8E);
                func_8031A278_72B928(&D_803D552C->unk326, &sp90, &sp8E);
                if (D_803D552C->unk365 == ATTACK_SHEEP_FLOAT) {
                    sp90 = sp8E = 6;
                }
                sp90 = D_803BD54A_7CEBFA[sp90]; sp8E = D_803BD602_7CECB2[sp8E];
                func_80356BD8_768288(D_01000CC0, &D_01000620, sp90);
                func_802C78B0_6D8F60(0x1A, 0x1B, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_040037A0_CB1D0);
                func_80356BD8_768288(D_01000CC0, &D_01000620, sp8E);
                func_802C78B0_6D8F60(0x1A, 0x1B, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_040037C0_CB1F0);
            }
            if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x8F) || (D_803D5530->state == 0x8D)) {
                func_803032DC_71498C(0x1A, 0, D_803D552C->unk35A / 110.0);
                func_803032DC_71498C(0x1B, 0, D_803D552C->unk35A / 110.0);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp8C == 0) || (sp8C == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (D_803D552C->yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190, 0x15, 0x15, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp8C == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 593, 0);
        func_80303D50_715400(D_803D552C, 1);
    } else {
        func_80303D00_7153B0(D_803D552C, 890, 1009);
    }
}

extern f64 D_803BEC48_7D02F8;
extern f64 D_803BEC50_7D0300;
extern f32 D_803BEC58_7D0308;

extern s16 D_803B41A0_7C5850[];
extern s16 D_803B41A4_7C5854[];
extern s16 D_803B41A8_7C5858[];
extern s16 D_803B41B0_7C5860[];
extern s16 D_803B41C4_7C5874[];

extern Gfx D_040032E8_CAD18[];
extern Gfx D_040039E0_CB410[];

#if 0
// load_springy_thing_or_springy_ram
void func_80360D94_772444(void) {
    s16 spB4; // struct061
    s16 spB2;
    s16 spB0;
    s16 spAE;
    s16 spAC;
    s16 spAA;
    s16 spA6;
    // u16 sp70;
    // u16 sp6E;
    // u16 sp6C;
    // f64 sp58;
    f32 temp_f12_2;
    s32 temp_v0_6;
    s16 var_s0;
    s16 var_v0;
    u16 temp_t9;
    u8 var_v0_3;

    switch (D_803D5530->state) {
    case 0x8E:
        var_v0 = 80;
        break;
    case 0x8F:
        var_v0 = 96;
        break;
    default:
        var_v0 = 8;
        break;
    }

    if (D_803D5530->unk162 == 5) {
        if (D_803D552C->unk30C < var_v0) {
            D_803D552C->unk30C = MIN(var_v0, D_803D552C->unk30C + 9);
        } else if (var_v0 < D_803D552C->unk30C) {
            D_803D552C->unk30C = MAX(var_v0, D_803D552C->unk30C - 1);
        }
        temp_f12_2 = MAX(0.0, MIN(1.0, (D_803D552C->unk30C - 8) / 88.0));
        temp_f12_2 = temp_f12_2 * temp_f12_2;

        if (temp_f12_2 != 0.0) {
            if (D_803D5530->unk4A == 0) {
                // D_803BEC48_7D02F8
                func_8032CED0_73E580(
                    D_803D5530,
                    0x7D,
                    temp_f12_2 * 23040.0f,
                    MAX(0.1, ABS(D_803D552C->unk30C / 40.0)) / 3.0,
                    0,
                    D_803D5538,
                    D_803D5530->xPos.h,
                    D_803D5530->zPos.h,
                    D_803D5530->yPos.h,
                    D_803D5530->xVelocity.w,
                    D_803D5530->zVelocity.w,
                    D_803D5530->yVelocity.w);
            }
        }
        if ((D_803D5538 != 0) && (temp_f12_2 > 0.5) && !(D_803D5544 & 1) && SSSV_RAND(33)) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
        }
    }
    if ((D_803D5538 != 0) && (D_803D5530->unk162 == 3)) {
        if (D_803D552C->unk369 == 0) {
            if (D_801E9E8A == 0) {
                D_803D552C->unk369 = 1;
            }
        } else if ((D_803D552C->unk369 == 1) && (D_801E9E8A != 0) && (D_803D552C->unk36D >= 0xB)) {
            D_803D552C->unk369 = 2;
            func_802DBA58_6ED108(5, D_803D552C);

            D_803D5530->yVelocity.h = MAX(0xE, D_803D5530->yVelocity.h + 9);
            play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    } else {
        D_803D552C->unk369 = 0;
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0_3 = 1;
        } else {
            var_v0_3 = 0;
        }
        if (var_v0_3 != 0) {
            spAC = 0;
            D_803F2EDD = 0;
            goto block_64;
        }
    }

    if ((D_803D5524->biome) == D_803F2D50.segment ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0_3 = 1;
    } else {
        var_v0_3 = 0;
    }
    spAC = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x5F0, 0, 0x94, 0x94, 0x94, 1, var_v0_3 == 0);
block_64:
    if (spAC == 0) {
        temp_t9 = D_803D5544 - D_803D552C->unk35E;
        if ((D_803F2D10.unk0 == 0) && (D_803D5530->unk4A == 0) && (temp_t9 != 0) && (((D_803D552C->unk366 == 1)) || (D_803D552C->unk366 == 3))) {
            if (D_803D552C->unk312 != 0) {
                D_803D552C->unk312--;
                D_803D5530->yRotation = (D_803D5530->yRotation + D_803D552C->unk310) & 0xFF;
            }
            if ((D_803D552C->unk312 == 0) && ((temp_v0_6 = temp_t9 & 0xFF, (temp_v0_6 == 0xFA)) || (temp_v0_6 == 0x8C) || (temp_v0_6 == 0xA0) || (temp_v0_6 == 0xAA) || (temp_v0_6 == 0xB4) || (temp_v0_6 == 0xC8) || ((temp_v0_6 == 0xDC) && ((D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 3)))) && ((D_803D5538 == 0) ||
                ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 17) &&
                 (D_803F28E0[D_803F2A98].cameraMode != 5) && (D_803F28E0[D_803F2A98].cameraMode != 6) &&
                 (D_803F28E0[D_803F2A98].cameraMode != 7) && (D_803F28E0[D_803F2A98].cameraMode != 28) &&
                 (D_803F28E0[D_803F2A98].cameraMode != 26)))) {
                if (SSSV_RAND(2)) {
                    D_803D552C->unk310 = 12;
                } else {
                    D_803D552C->unk310 = -12;
                }
                D_803D552C->unk312 = 64;
            }
        } else {
            D_803D552C->unk312 = 0;
        }
        func_8034B298_75C948(0);
        if (D_803D552C->unk366 != 5) {
            func_803622DC_77398C();
        }
        func_8035D120_76E7D0();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0xFA);
        if (((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4)) && (SSSV_RAND(256) == 0x9C) && (D_803F6450 != 0)) {
            func_8037FEDC_79158C();
        }
        switch (D_803D552C->unk365) {
        case ATTACK_NONE:
            break;
        case ATTACK_SHEEP_HEADBUTT:
            func_802DCCAC_6EE35C(16);
            if (((D_803D5544 - D_803D552C->unk32A) == 4) && (func_803224C4_733B74(0x2E, 0x2E, 0, 0x14, 0xC, 0, 0, 0x10))) {
                play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);

                // regalloc helper / hinderer
                if (D_803F28E0[D_803F2A98].cameraMode && D_803F28E0[D_803F2A98].cameraMode) {}
            }
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B96D0_6CAD80(&spB4, 593, 1009, 0);
            func_802C1A44_6D30F4(1009, 0, &spB4);
        }

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B41A0_7C5850, D_803B41A4_7C5854, D_803B41A8_7C5858, D_803B41B0_7C5860);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B41A0_7C5850, D_803B41A4_7C5854, D_803B41A8_7C5858, D_803B41C4_7C5874);
                break;
            }
        }
        func_8038064C_791CFC();


        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && ((D_803D5538) || (D_803F2AA2 == 0) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            if (D_803D552C->unk369 == 2) {
                if (D_803D5530->yVelocity.w > FTOFIX32(-4.0)) {
                    D_803D5530->yVelocity.w -= FTOFIX32(2.0);
                }
                if (D_803D5530->yVelocity.w < FTOFIX32(-8.0)) {
                    D_803D5530->yVelocity.w = (((D_803D5530->yVelocity.w * 3) + FTOFIX32(24.0)) >> 2) - FTOFIX32(8.0);
                }
                D_803D5530->xVelocity.w = D_803D5530->xVelocity.w >> 1;
                D_803D5530->zVelocity.w = D_803D5530->zVelocity.w >> 1;
                if (D_803D5530->unk4A == 0) {
                    func_8032CD70_73E420(
                        D_803D5530,
                        SFX_UNKNOWN_31,
                        0x5000,
                        0,
                        ((D_80152C78[(D_803D5540 << 5) & 0xFF] >> 7) * 0.001953125) + 1.2,
                        D_803D5530->xPos.h,
                        D_803D5530->zPos.h,
                        D_803D5530->yPos.h);
                }
                create_particle_effect(
                    D_803D5530->xPos.h + SSSV_RAND(16) - 8,
                    D_803D5530->zPos.h + SSSV_RAND(16) - 8,
                    D_803D5530->yPos.h + D_803D5530->unk42,
                    0x15,
                    D_803D5530->xVelocity.w,
                    D_803D5530->zVelocity.w,
                    D_803D5530->yVelocity.w,
                    0x1E,
                    GPACK_RGBA5551(152, 152, 152, 1),
                    GPACK_RGBA5551(96, 96, 96, 1),
                    0);
                if (SSSV_RAND(16) == 0) {
                    create_particle_effect(
                        (D_803D5530->xPos.h + SSSV_RAND(4)) - 1,
                        (D_803D5530->zPos.h + SSSV_RAND(4)) - 2,
                        D_803D5530->yPos.h,
                        0x24,
                        D_803D5530->xVelocity.w,
                        D_803D5530->zVelocity.w,
                        D_803D5530->yVelocity.w,
                        0x1E,
                        GPACK_RGBA5551(248, 248, 0, 1),
                        GPACK_RGBA5551(248, 248, 128, 1),
                        0);
                }
                spAA = D_803D5540 << 5;
                if (func_80322A58_734108(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 0x12, 0xA, 0, 0, 0x14) == 2) {

                    D_803D552C->unk369 = 0;
                    for (spA6 = 0; spA6 < 4; spA6++) {
                        // another regalloc helper
                        if ((D_803D5538 && D_803D5538) && D_803D5538) {};
                        create_particle_effect(
                            D_803D5530->xPos.h,
                            D_803D5530->zPos.h,
                            D_803D5530->yPos.h,
                            0x18,
                            (SSSV_RAND(16) - 7) << 0x10,
                            (SSSV_RAND(16) - 7) << 0x10,
                            SSSV_RAND(16) << 0x10,
                            SSSV_RAND(4) + 4,
                            GPACK_RGBA5551(248, 248, 0, 1),
                            GPACK_RGBA5551(200, 200, 96, 1),
                            0);
                        play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    }
                }
            } else {
                spAA = 0;
            }

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, spAA - D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            // D_803BEC58_7D0308
            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.38f);
            func_8038C484_79DB34(2, 1, 3, -0.38f, 0xBB8);
            if ((D_803F2D10.unk0 == 0) && (D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
                spB2 = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.h * 0x10);
                func_80300130_7117E0(&spB2, &D_803D552C->unk30A, 0x60, -0x100, 3, 3, D_803D5530->yVelocity.h * 0x10, 4);
            } else {
                spB2 = D_803D552C->unk308;
            }
            D_803D552C->unk308 = spB2;

            if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90)) {
                var_s0 = (D_803D5540 << 5) & 0xFF;
                func_8034B848_75CEF8(0);
            } else if (D_803D5530->state == 0x8F) {
                var_s0 = (D_803D5540 << 6) & 0xFF;
                func_8034B848_75CEF8(0);
            } else {
                var_s0 = 0;
            }

            func_802C78B0_6D8F60(2, 0xE, ((FTOFIX32(1.0) - (spB2 << 6)) * 0x4C) >> 6, ((FTOFIX32(1.0) - (spB2 << 6)) * 0x4C) >> 6, (((spB2 << 7) * 0x4C) + FTOFIX32(76.0)) >> 6, D_803F2ED0, var_s0, 0, 0, D_040039E0_CB410);

            D_80203FE0[2].unk4 += (spB2 << 7) / 32;
            D_80203FE0[1].unk4 += (spB2 << 7) / 32;

            if (D_803D552C->unk366 != 5) {
                func_802C78B0_6D8F60(1, 2, ((FTOFIX32(1.0) - (spB2 * 0x10)) * 0x4C) >> 6, ((FTOFIX32(1.0) - (spB2 * 0x10)) * 0x4C) >> 6, (((spB2 << 5) * 0x4C) + FTOFIX32(76.0)) >> 6, D_803F2ED0, 0, 0, 0, D_04002D90_CA7C0);
            } else {
                func_802C78B0_6D8F60(1, 2, ((FTOFIX32(1.0) - (spB2 * 0x10)) * 0x4C) >> 6, ((FTOFIX32(1.0) - (spB2 * 0x10)) * 0x4C) >> 6, (((spB2 << 5) * 0x4C) + FTOFIX32(76.0)) >> 6, D_803F2ED0, 0, 0, 0, D_040032E8_CAD18);
            }
            switch (D_803D5524->unk9C) {
            case SPRINGY_THINGY:
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 2, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_040036B0_CB0E0); }
                if (D_803F2EDD == 0) {
                    func_8031A150_72B800(D_803D552C->unk326++, &spB0, &spAE);
                    func_8031A278_72B928(&D_803D552C->unk326, &spB0, &spAE);
#pragma _permuter sameline start
                    spB0 = D_803BD54A_7CEBFA[spB0]; spAE = D_803BD602_7CECB2[spAE];
#pragma _permuter sameline end
                    func_80356BD8_768288(&D_01000CC0, &D_01000620, spB0);
                    func_802C78B0_6D8F60(1, 2, ((D_803F2EC8 - (spB2 * 0x10)) * 0x4C) >> 6, ((D_803F2EC8 - (spB2 * 0x10)) * 0x4C) >> 6, (((spB2 << 5) + D_803F2EC8) * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, D_040037A0_CB1D0);
                    func_80356BD8_768288(&D_01000CC0, &D_01000620, spAE);
                    func_802C78B0_6D8F60(1, 2, ((D_803F2EC8 - (spB2 * 0x10)) * 0x4C) >> 6, ((D_803F2EC8 - (spB2 * 0x10)) * 0x4C) >> 6, (((spB2 << 5) + D_803F2EC8) * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, D_040037C0_CB1F0);
                }
                break;
            case SPRINGY_RAM:
                D_80203FE0[1].unk2 += D_803F2ED8 << 5;
                D_80203FE0[2].unk2 += D_803F2ED8 << 5;
                func_802C78B0_6D8F60(1, 2, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, D_04003DE0_CB810);
                D_80203FE0[1].unk2 -= D_803F2ED8 << 5;
                D_80203FE0[2].unk2 -= D_803F2ED8 << 5;
                break;
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spAC == 0) || (spAC == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, &D_01033190, 0x15, 0x15, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spAC == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 593, 0);
        func_80303D50_715400(D_803D552C, 1);
    } else {
        func_80303D00_7153B0(D_803D552C, 890, 1009);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_80360D94_772444.s")
#endif

#if 0
void func_803622DC_77398C(void) {
    s16 temp_s0;
    s16 temp_s1;
    s16 temp_s2;
    s16 temp_f6;

    s16 i;

    Vtx *vtx1;
    Vtx *vtx2;

    static u16 D_803F2EF0;

    if (D_803F2EF0 != D_803D5544) {
        D_803F2EF0 = D_803D5544;

        vtx1 = (Vtx*)(D_801D9EC4 + SEGMENT_OFFSET(D_04002F28_CA958));
        vtx2 = (Vtx*)(D_801D9EC4 + SEGMENT_OFFSET(D_040029D0_CA400));

        for (i = 0; i < 52; i++) {
            // to check
            // vtx2[i].v.ob[0] = vtx1[i].v.ob[0] + (((D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3)) & 0xFF] >> 7) * vtx1[i].v.ob[0]) >> 0xC);
            // vtx2[i].v.ob[1] = vtx1[i].v.ob[1] + (((D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3)) & 0xFF] >> 7) * vtx1[i].v.ob[1]) >> 0xC);
            // vtx2[i].v.ob[2] = vtx1[i].v.ob[2] + (((D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3)) & 0xFF] >> 7) * vtx1[i].v.ob[2]) >> 0xC);

            vtx2[i].v.ob[0] = vtx1[i].v.ob[0] + ((vtx1[i].v.ob[0] * (D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3)) & 0xFF] >> 7)) >> 0xC);
            vtx2[i].v.ob[1] = vtx1[i].v.ob[1] + ((vtx1[i].v.ob[1] * (D_80152C78[((vtx1[i].v.ob[1] << 4) + (D_803D5540 << 3)) & 0xFF] >> 7)) >> 0xC);
            vtx2[i].v.ob[2] = vtx1[i].v.ob[2] + ((vtx1[i].v.ob[2] * (D_80152C78[((vtx1[i].v.ob[2] << 4) + (D_803D5540 << 3)) & 0xFF] >> 7)) >> 0xC);

            temp_s0 = (s8)vtx1[i].v.cn[0] + ((D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3)       ) & 0xFF] >> 7) >> 2);
            temp_s1 = (s8)vtx1[i].v.cn[1] + ((D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3) + 0x40) & 0xFF] >> 7) >> 2);
            temp_s2 = (s8)vtx1[i].v.cn[2] - ((D_80152C78[((vtx1[i].v.ob[0] << 4) + (D_803D5540 << 3)       ) & 0xFF] >> 7) >> 2);

            temp_f6 = sqrtf((temp_s0 * temp_s0) + (temp_s1 * temp_s1) + (temp_s2 * temp_s2));;

            vtx2[i].v.cn[0] = (s16) ((temp_s0 * 0x7F) / temp_f6);
            vtx2[i].v.cn[1] = (s16) ((temp_s1 * 0x7F) / temp_f6);
            vtx2[i].v.cn[2] = (s16) ((temp_s2 * 0x7F) / temp_f6);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_803622DC_77398C.s")
#endif

void func_80362618_773CC8(void) {
    s16 tmp;

    if (D_803D552C->unk36D == 7) {
        play_sound_effect_at_location(SFX_SHEEP_FLOAT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
    }
    if (D_803D552C->energy[0].unk0 < 15) {
        if (D_803D552C->unk365 != ATTACK_SHEEP_FLOAT) {
            tmp = D_803D5530->yPos.h - MAX(func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 16, D_803C0740[D_803D5530->xPos.h >> 16][D_803D5530->zPos.h >> 16].unk6 << 2);
            if (tmp > 96) {
                D_803D552C->unk365 = ATTACK_SHEEP_FLOAT;
                D_803D552C->unk32A = D_803D5544;
                play_sound_effect_at_location(SFX_SHEEP_HURT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
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
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}
//
void ram_headbutt(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_SHEEP_HEADBUTT;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}
