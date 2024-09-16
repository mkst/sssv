#include <ultra64.h>
#include "common.h"


// TBD figure out types
extern struct077 D_803B5E30_7C74E0[];
extern struct077 D_803B5E60_7C7510[];
extern s16 D_803B5E90_7C7540[];
extern struct077 D_803B5ED4_7C7584[];
extern s16 D_803B5F04_7C75B4[];
extern s16 D_803B5F40_7C75F0[];
extern s16 D_803B5F64_7C7614[];
extern s16 D_803B5FB0_7C7660[];
extern struct077 D_803B5EA4_7C7554[];
extern s16 D_803B5F2C_7C75DC[];

extern u8  D_803B5F18_7C75C8[];

extern Gfx D_01004F70_3E840[];
extern Gfx D_01005060_3E930[];
extern Gfx D_010054C0_3ED90[];
extern Gfx D_01005750_3F020[];
extern Gfx D_01005E50_3F720[];
extern Gfx D_01005FC0_3F890[];
extern Gfx D_01006260_3FB30[];
extern Gfx D_01006430_3FD00[];
extern Gfx D_01006570_3FE40[];
extern Gfx D_01006680_3FF50[];
extern Gfx D_010069D0_402A0[];
extern Gfx D_01006A08_402D8[];
extern Gfx D_01006A40_40310[];
extern Gfx D_01006A78_40348[];
extern Gfx D_01006AB0_40380[];
extern Gfx D_01006AE8_403B8[];

// EVO_SHELLSUIT
#ifdef NON_MATCHING
// CURRENT (172)
void func_80389B30_79B1E0(void) {
    s32 pad[2];

    struct061 sp148;
    s32 padd[2];

    s16 tmp;
    s16 temp_s0;
    u8 temp_v0_3;

    s16 sp138; // evo texture
    s16 sp136;
    s16 sp134;
    s16 sp132;
    s16 sp130;
    s16 sp12E;
    s16 sp12C;
    s16 sp12A;
    s16 sp128;
    s16 sp126;
    s16 sp124;
    s16 sp122;
    s16 sp120;
    s16 sp11E;
    s16 sp11C;
    s16 sp11A;
    s16 sp118;
    s32 zDelta;
    s32 xDelta;
    s32 sp10C;

    s32 paddd;

    Animal *target;

    f32 sp100;

    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 5)) {
        D_803D552C->energy[0].unk0 = MIN(0x400, D_803D552C->energy[0].unk0 + 0x32);
    }

    func_8034B298_75C948(0);
    func_8035D120_76E7D0();
    func_8035DA60_76F110();
    D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
    D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
    D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
    func_8035D734_76EDE4();

    if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F) || (D_803F2ECE >= 3)) {
        func_802BA220_6CB8D0(&sp148, 0x222, 0x4C1, 0x1FB, 0x15F, 0x138);
        func_802C353C_6D4BEC(0x29F, 0x222, 0x138, &D_803B5E30_7C74E0, &D_803B5E60_7C7510, &D_803B5E90_7C7540, &sp148);
        func_8031FE40_7314F0(0x1D4, 0x271, &D_803B5EA4_7C7554, &D_803B5ED4_7C7584, &D_803B5F04_7C75B4);
        func_802C6C00_6D82B0(0x138, 0xEA);
    }
    if (D_803F2ECC != 0) {
        backup_joint_positions();
        switch (D_803F2ECE) {
        case 1:
            func_802DB670_6ECD20(D_803B5F18_7C75C8, D_803B5F2C_7C75DC, D_803B5F40_7C75F0, D_803B5F64_7C7614);
            break;
        case 2:
            func_802DB670_6ECD20(D_803B5F18_7C75C8, D_803B5F2C_7C75DC, D_803B5F40_7C75F0, D_803B5FB0_7C7660);
            break;
        }
    }
    func_8038064C_791CFC();

    if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_3 = D_803F2AA2, (temp_v0_3 == 0)) || (temp_v0_3 == 2) || ((temp_v0_3 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
        func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);

        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPMatrix(D_801D9E90++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        D_80204278->usedModelViewMtxs += 1;

        func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 3, 3, -0.32f);

        guLookAtReflect(
            &D_80204278->unk38CD0[D_80204278->unk39310],
            &D_80204278->unk38A50[D_80204278->unk39310],
            D_803F2C44,
            D_803F2C48,
            D_803F2C4C,
            (f32) D_803D5530->position.xPos.w / 65536.0,
            (f32) D_803D5530->position.zPos.w / 65536.0,
            (f32) D_803D5530->position.yPos.w / 65536.0,
            D_80204200,
            D_80204204,
            D_80204208);

        gDPSetTextureLUT(D_801D9E88++, G_TT_NONE);
        gSPLookAtX(D_801D9E88++, &D_80204278->unk38A50[D_80204278->unk39310].l[0]);
        gSPLookAtY(D_801D9E88++, &D_80204278->unk38A50[D_80204278->unk39310].l[1]);
        gDPPipeSync(D_801D9E88++);
        D_80204278->unk39310++;

        gSPDisplayList(D_801D9E88++, D_01004270_3DB40);
        gSPDisplayList(D_801D9E88++, D_01004AF8_3E3C8);
        gDPSetRenderMode(D_801D9E88++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);

        switch (D_803F2D50.evoSuitColor) {

        case EVO_BRONZE_SHELLSUIT:
            sp138 = 2;  // bronze texture
            sp12E = 4;
            sp12C = 0xAA;
            sp12A = 0x28;
            sp134 = 0x4000;
            sp100 = 0.8f;
            D_803D5524->unkA4 = 0x180;
            D_803D5524->unkAA = 0x140;
            D_803D5524->unkA6 = 0x16;
            D_803D5524->unkA8 = 0x18;
            break;
        case EVO_SILVER_SHELLSUIT:
            sp138 = 3; // silver texture
            sp12E = 7;
            sp12C = 0xD2;
            sp12A = 0x5A;
            sp134 = 0x5800;
            sp100 = 1.1f;
            D_803D5524->unkA4 = 0x1C0;
            D_803D5524->unkAA = 0x180;
            D_803D5524->unkA6 = 0x18;
            D_803D5524->unkA8 = 0x1A;
            break;
        case EVO_GOLD_SHELLSUIT:
            sp138 = 1; // gold texture
            sp12E = 10;
            sp12C = 0xFF;
            sp12A = 0x8C;
            sp134 = 0x6000;
            sp100 = 1.3f;
            D_803D5524->unkA4 = 0x200;
            D_803D5524->unkAA = 0x1C0;
            D_803D5524->unkA6 = 0x1A;
            D_803D5524->unkA8 = 0x1C;
            break;
        default:
            sp138 = 0; // (?) texture
            sp12E = 0;
            sp12C = 0;
            sp12A = 0xFF;
            sp134 = 0x7000;
            sp100 = 1.5f;
            D_803D5524->unkA4 = 0x780;
            D_803D5524->unkAA = 0x780;
            D_803D5524->unkA6 = 0x28;
            D_803D5524->unkA8 = 0x3C;
            break;
        }

        if (D_803D552C->unk30C != 0) {
            s16 var_v1_2;
            s16 var_v1;

            target = func_80323040_7346F0();
            if (target != NULL) {
                temp_s0 = ((D_803D5530->position.yPos.h - target->position.yPos.h) - (target->unk42 >> 1)) + 0x56;
                xDelta = D_803D5530->position.xPos.h - target->position.xPos.h;
                zDelta = D_803D5530->position.zPos.h - target->position.zPos.h;

                var_v1 = sqrtf(SQ(xDelta) + SQ(zDelta));
                if (var_v1 <= 0) {
                    var_v1 = 1;
                }
                var_v1_2 = func_8012844C((temp_s0 << 5) / var_v1) * -1;
            } else {
                var_v1_2 = 0;
            }

            if (D_803D552C->unk310 < var_v1_2) {
                D_803D552C->unk310 = MIN(var_v1_2, D_803D552C->unk310 + 3);
            } else if (D_803D552C->unk310 > var_v1_2) {
                D_803D552C->unk310 = MAX(var_v1_2, D_803D552C->unk310 - 3);
            }

            // location of laser?
            sp128 = D_803D5530->position.xPos.h;
            sp126 = D_803D5530->position.zPos.h;
            sp124 = D_803D5530->position.yPos.h + 0x56;

            for (sp10C = 0; sp10C < 5; sp10C++) {
                sp122 = sp128 + (((COS(D_803D552C->unk310) >> 7) * (COS(0x40 - D_803D552C->heading) >> 7) * (sp10C + 1)) / 1536);
                sp120 = sp126 + (((COS(D_803D552C->unk310) >> 7) * (SIN(0x40 - D_803D552C->heading) >> 7) * (sp10C + 1)) / 1536);
                sp11E = sp124 + (((SIN(D_803D552C->unk310) >> 7) * (sp10C + 1)) / 6);
                if (func_8033C9CC_74E07C(sp122, sp120, sp11E, func_803136FC_724DAC(sp122, sp120, sp124), sp128, sp126, sp124, D_803D5530->unk160, 0, 0)) {
                    break;
                }
            }

            sp130 = 0;
            if (func_80322D68_734418(sp128, sp126, sp124, sp122, sp120, sp11E, &sp11C, &sp11A, &sp118, 0xF, sp12E, 1, 0xA)) {
                sp130 = 1;

                for (sp132 = 0; sp132 < 1; sp132++) {
                    create_particle_effect(
                        sp11C,
                        sp11A,
                        sp118,
                        0x18,
                        (SSSV_RAND(16) - 7) << 0x10,
                        (SSSV_RAND(16) - 7) << 0x10,
                        SSSV_RAND(16) << 0x10,
                        SSSV_RAND(4) + 4,
                        GPACK_RGBA5551(248, 248, 248, 1),
                        GPACK_RGBA5551(248, 248, 248, 1),
                        0);
                }
            }
        }

        gDPSetTextureImage(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_0102F010_688E0 + ((sp138 << 8) << 3));

        gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPLoadSync(D_801D9E88++);
        gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 1023, 256);
        gDPPipeSync(D_801D9E88++);
        gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 124, 124);

        tmp = (D_80203FE0[4].unk2 - D_80203FE0[3].unk2) >> 5;
        func_802C78B0_6D8F60(0,  1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, tmp, 0, 0, D_01006430_3FD00);
        func_802C78B0_6D8F60(0,  2, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_01006260_3FB30);
        func_802C78B0_6D8F60(1,  19, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_01005FC0_3F890);
        func_802C78B0_6D8F60(20, 26, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_01005750_3F020);
        func_802C78B0_6D8F60(20, 26, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_01004F70_3E840);

        func_802C78B0_6D8F60(5,  13, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_01006680_3FF50);
        func_802C78B0_6D8F60(13, 14, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_010054C0_3ED90);

        gSPClearGeometryMode(D_801D9E88++, G_CULL_BOTH);
        gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

        func_802C78B0_6D8F60(6,  16, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_01006680_3FF50);
        func_802C78B0_6D8F60(16, 17, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_010054C0_3ED90);

        gSPClearGeometryMode(D_801D9E88++, G_CULL_BOTH);
        gSPSetGeometryMode(D_801D9E88++, G_CULL_BACK);

        func_802C78B0_6D8F60(7, 8, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_01005E50_3F720);
        func_802C78B0_6D8F60(3, 7, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_01006570_3FE40);

        gSPClearGeometryMode(D_801D9E88++, G_CULL_BOTH);
        gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

        func_802C78B0_6D8F60(4,  10, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_01006570_3FE40);
        func_802C78B0_6D8F60(10, 11, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_01005E50_3F720);

        gSPDisplayList(D_801D9E88++, D_01003460_3CD30);
        gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

        gDPSetPrimColor(D_801D9E88++, 0, 0, (((SIN(D_803D5540 << 4) >> 7) >> 3) + 0xDF), 0, 0, 0xFF);

        func_802C78B0_6D8F60(20, 26, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_01005060_3E930);

        if (D_803D552C->unk30C != 0) {
            D_80203FE0[27].unk0 = D_80203FE0[19].unk0;
            D_80203FE0[27].unk2 = D_80203FE0[19].unk2 + ((COS(D_803D552C->unk310) >> 7) * 2);
            D_80203FE0[27].unk4 = D_80203FE0[19].unk4 + ((SIN(D_803D552C->unk310) >> 7) * 2);

            sp136 = sp12C; // red-ness
            if (SSSV_RAND(16) == 11) {
                sp136 = (sp12C / 2);
            }

            gSPDisplayList(D_801D9E90++, D_01004970_3E240);
            gDPSetPrimColor(D_801D9E90++, 0, 0, sp136, 0, 0, sp12A);

            if (func_80126388(0x13, 0x1B, D_803F2EC8, D_803F2EC8, D_803F2EC8, D_803F2ED0, 0, 0, 0, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                gSPMatrix(D_801D9E90++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                switch (sp10C) {
                case 0:
                    gSPDisplayList(D_801D9E90++, D_01006AE8_403B8);
                    break;
                case 1:
                    gSPDisplayList(D_801D9E90++, D_01006AB0_40380);
                    break;
                case 2:
                    gSPDisplayList(D_801D9E90++, D_01006A78_40348);
                    break;
                case 3:
                    gSPDisplayList(D_801D9E90++, D_01006A40_40310);
                    break;
                case 4:
                    gSPDisplayList(D_801D9E90++, D_01006A08_402D8);
                    break;
                case 5:
                    gSPDisplayList(D_801D9E90++, D_010069D0_402A0);
                    break;
                }
            }

            if (sp130 != 0) {
                func_8032CD70_73E420(D_803D5530, 282, sp134 + 0xF00, 0, sp100, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            } else {
                func_8032CD70_73E420(D_803D5530, 281, sp134,         0,  1.0f, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
        }

        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
    }

    func_8035D6A0_76ED50();
    func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, D_01033190_6CA60, 0xC, 0x1C, 0x9B, 0, 0, 0, 0, D_803D5538);
    func_80303820_714ED0(D_803D552C, 1, 2,  0x2BF, 0);
    func_80303820_714ED0(D_803D552C, 2, 2,  0x2BF, 1);
    func_80303820_714ED0(D_803D552C, 1, 19, 0x1D4, 2);
    func_80303D50_715400(D_803D552C, 3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/evo/func_80389B30_79B1E0.s")
#endif

// evo shellsuit jetpack
void func_8038B330_79C9E0(void) {
    s16 tmp;

    if (D_803D5530->unk162 != 1) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                SFX_UNKNOWN_103,
                0x7000,
                0,
                0.25f,
                D_803D552C->position.xPos.h,
                D_803D552C->position.zPos.h,
                D_803D552C->position.yPos.h);
        }

        if (D_803D5530->yVelocity.w > FTOFIX32(2.0)) {
            D_803D5530->yVelocity.w = MAX(D_803D5530->yVelocity.w + FTOFIX32(1.0), FTOFIX32(3.75));
        } else if (D_803D5530->yVelocity.w > FTOFIX32(-10.0)) {
            D_803D5530->yVelocity.w += FTOFIX32(1.875);
        } else {
            D_803D5530->yVelocity.w += FTOFIX32(4.0);
        }

        tmp = -16;
        do {
            // smoke
            create_particle_effect(
                (SSSV_RAND(16) + D_803D5530->position.xPos.h + ((tmp * (COS(-D_803D552C->heading) >> 7)) >> 8)) - (0, 8),
                (SSSV_RAND(16) + D_803D5530->position.zPos.h + ((tmp * (SIN(-D_803D552C->heading) >> 7)) >> 8)) - (0, 8),
                D_803D5530->position.yPos.h,
                (SSSV_RAND(2) + 25),
                (SSSV_RAND(FTOFIX32(0.5)) << 1) + D_803D5530->xVelocity.w + FTOFIX32(-0.6103515625),
                (SSSV_RAND(FTOFIX32(0.5)) << 1) + D_803D5530->zVelocity.w + FTOFIX32(-0.6103515625),
                (D_803D5530->yVelocity.w >> 1) + FTOFIX32(-3.0517578125),
                SSSV_RAND(13),
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(56, 56, 56, 1), // grey
                SSSV_RAND(16) + 15);

            // flames
            create_particle_effect(
                (SSSV_RAND(16) + D_803D5530->position.xPos.h + ((tmp * (COS(-D_803D552C->heading) >> 7)) >> 8)) - (0, 8),
                (SSSV_RAND(16) + D_803D5530->position.zPos.h + ((tmp * (SIN(-D_803D552C->heading) >> 7)) >> 8)) - (0, 8),
                D_803D5530->position.yPos.h,
                63,
                D_803D5530->xVelocity.w,
                D_803D5530->zVelocity.w,
                D_803D5530->yVelocity.w + FTOFIX32(-4.57763671875),
                SSSV_RAND(16) + 25,
                GPACK_RGBA5551(SSSV_RAND(64) + 192, SSSV_RAND(32) + 192, 0, 1), // red/orange
                GPACK_RGBA5551(SSSV_RAND(64) + 192, 0, 0, 1), // red
                0);

            tmp += 32;
        } while (tmp < 17);
    } else {
        recharge_skill(0);
    }
}

void func_8038B730_79CDE0(void) {
    D_803D5528->unk3C0.unk0 = 0;
    D_803D552C->unk30C = 1;
    if (D_803D5530->unk4A != 0) {
        D_803D552C->unk30C = 0;
    }
}

void func_8038B774_79CE24(void) {
    D_803D552C->unk30C = 0;
    D_803D552C->unk30E = 0;
    D_803D552C->unk310 = 0;
}

void func_8038B798_79CE48(void) {
    Animal *a;

    D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
    D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

    D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;

    a = D_803D5528;
    D_803D552C = a;
    D_803D5530 = a;
    if (a == NULL) {};

    D_803D5538 = 1;
    D_803D553C = gCurrentAnimalIndex;
    D_803D553A = 0;
    if (D_803D5530->unk162 == 1) {
        func_802A6390_6B7A40();
    }
}
