#include <ultra64.h>
#include "common.h"

extern Gfx D_010025A0[];
extern Gfx D_01002C20[];
extern Gfx D_010034C0[];
extern Gfx D_01003548[];
extern Gfx D_010037F0[];
extern Gfx D_01003840[];

extern Gfx D_04009FC0[];
extern Gfx D_0400A4E0[];
extern Gfx D_0400A720[];
extern Gfx D_0400A840[];
extern Gfx D_0400ACE0[];
extern u8 D_0400AD80[];
extern Gfx D_0400AF80[];
extern Gfx D_0400B020[];
extern Gfx D_0400B040[];
extern Gfx D_0400B420[];
extern Gfx D_0400B470[];
extern Gfx D_0400B4C0[];
extern Gfx D_0400B510[];
extern Gfx D_0400B560[];
extern Gfx D_0400B5B0[];
extern u8 D_0400B600[];
extern Gfx D_0400B800[];

extern u8 D_0400B820[];
extern Gfx D_0400BA20[];

extern s16 D_803A4EF0_7B65A0[];
extern s16 D_803A4F20_7B65D0[];
extern s16 D_803A4F50_7B6600[];
extern s16 D_803A4F64_7B6614[];
extern s16 D_803A4F94_7B6644[];
extern s16 D_803A4FC4_7B6674[];

extern u8 D_803A4FD8_7B6688[];
extern u8 D_803A4FEC_7B669C[];
extern s16 D_803A5000_7B66B0[];
extern struct076 D_803A5020_7B66D0[];
extern struct076 D_803A506C_7B671C[];

#if 0
// NON_MATCHING ?
void func_802EF0C0_700770(void) {
    struct086 sp100;
    s16 spFE;
    s16 spFC;
    s16 spFA;
    s16 spF8;
    s16 spF6;
    s16 spF4;
    s16 spF2;
    s16 spF0;
    s16 spEE;
    s32 sp78;

    s32 temp_v0_5;

    s16 var_t5;

    u8 var_v0;
    s32 var_v1;

    s32 tmp;

    sp78 = FTOFIX32(1.0);

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) || ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            spFA = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }
    if ((D_803D5524->biome == D_803F2D50.segment) || ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    spFA = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x15E0, 5, 0x99, 0x46, 0x46, 1, var_v1 == 0);

done:
    if (D_803D552C->unk365 == 0x11) {
        spFA = 0;
    }
    if (spFA == 0) {
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        spF8 = 0;
        if (D_803D552C->unk365 == 0x11) {
            D_803D5528->unk3C0.unk0 = 0;
            var_t5 = D_803D5544 - D_803D552C->unk32A;
            if (var_t5 == 1) {
                play_sound_effect_at_location(157, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            } else if (var_t5 == 10) {
                play_sound_effect_at_location(30, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 0.71f);
            }
            spF6 = var_t5;
            func_802DC6A4_6EDD54(0x10);
            // var_t5_2 = var_t5;
            if (var_t5 >= 9) {
                temp_v0_5 = 0xB2 - (var_t5 * 0x10);
                if (temp_v0_5 >= 0) {
                    spF8 = temp_v0_5;
                } else {

                }
            } else if (var_t5 >= 3) {
                spF8 = (var_t5 * 0xC) - 0x18;
            }
            if (var_t5 == 0xA) {
                spF6 = var_t5;
                apply_recoil(3);
            }
            if (var_t5 >= 0xA) {
                spF6 = var_t5;
                tmp = func_80322D68_734418(
                    D_803D5530->xPos.h,
                    D_803D5530->zPos.h,
                    D_803D5530->yPos.h + 0x3C,
                    D_803D5530->xPos.h + (((D_80152C78[D_803D552C->unk32C & 0xFF] >> 7) * ((var_t5 << 6) - 0x240)) >> 8),
                    D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk32C + 0x40) & 0xFF]) >> 7) * ((var_t5 << 6) - 0x240) >> 8),
                    D_803D5530->yPos.h + 0x3C,
                    &spF2,
                    &spF0,
                    &spEE,
                    0x14,
                    0x1E,
                    0,
                    2);
                if (tmp) {
                    for (spF4 = 0; spF4 < 5; spF4++) {
                        create_particle_effect(
                            spF2,
                            spF0,
                            spEE,
                            0x18,
                            (SSSV_RAND(16) - 7) << 0x10,
                            (SSSV_RAND(16) - 7) << 0x10,
                            SSSV_RAND(8) << 0x10,
                            SSSV_RAND(4) + 4,
                            GPACK_RGBA5551(200, 248, 200, 1),
                            GPACK_RGBA5551(96, 216, 96, 1),
                            0);
                    }
                    D_803D552C->unk365 = 0U;
                    spF6 = 0;
                    var_t5 = spF6;
                    play_sound_effect_at_location(0x1D, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
            }
            if (var_t5 >= 0xA) {
                if (var_t5 == 0xA) {
                    D_803D552C->unk32C = (s16) D_803D552C->unk302;
                }

                gSPDisplayList(D_801D9E88++, D_01003548);
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0xB4, 0xFF, 0xB4, 0xFF);

                func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk32C, sp78, sp78, sp78, 0, 0);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                switch (var_t5) {
                case 10:
                    gSPDisplayList(D_801D9E88++, D_0400B420);
                    break;
                case 11:
                    gSPDisplayList(D_801D9E88++, D_0400B470);
                    break;
                case 12:
                    gSPDisplayList(D_801D9E88++, D_0400B4C0);
                    break;
                case 13:
                    gSPDisplayList(D_801D9E88++, D_0400B510);
                    break;
                case 14:
                    gSPDisplayList(D_801D9E88++, D_0400B560);
                    break;
                case 15:
                    gSPDisplayList(D_801D9E88++, D_0400B5B0);
                    break;
                }
                gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
            }
        } else {
            D_803D552C->unk365 = 0;
        }
        if (spF8 == 0) {
            if (D_803D5540 < 64) {
                var_v1 = (D_80152C78[(D_803D5540 << 4) & 0xFF] >> 7) >> 6;
                spF8 = var_v1; // regalloc helper
            }
        }
        if ((D_803F2ECE == 0) || ((s32) D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp100, 0x35B, 0x298, 0x7EE, 0xDA);
            func_802BD40C_6CEABC(0x493, 0x35B, 0, 0xDA, 0, 0x80, 0x64, 0x80, &D_803A4EF0_7B65A0, &D_803A4F20_7B65D0, &D_803A4F50_7B6600, 0x493, 0x35B, 0, 0xDA, 0, 0x80, 0, 0x1E, &D_803A4F64_7B6614, &D_803A4F94_7B6644, &D_803A4FC4_7B6674, &sp100, 0);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x1D4, 0x445, 4);
            func_8038CCF0_79E3A0(0xEA, 0x14, -1, -1, -1, -1);
            func_802C7600_6D8CB0(0x445, 0x1C);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                   /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                func_802DB670_6ECD20(&D_803A4FD8_7B6688, &D_803A4FEC_7B669C, &D_803A5000_7B66B0, &D_803A5020_7B66D0);
                break;
            case 2:                                 /* switch 1 */
                func_802DB670_6ECD20(&D_803A4FD8_7B6688, &D_803A4FEC_7B669C, &D_803A5000_7B66B0, &D_803A506C_7B671C);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            (((D_803D5538 != 0)) || ((D_803F2AA2 == 0)) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            load_1_tile(D_0400BA20, D_0400B820);
            func_802C78B0_6D8F60(0x14, 1, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_0400A4E0);
            D_80203FE0[20].unk4 -= ((spF8 * 0x445) >> 5);
            if (D_803F2EDD == 0) {
                // regalloc help
                do { func_802C78B0_6D8F60(0x14, 1, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), D_803F2ED0, 0, 0, 0, D_0400ACE0); } while (0);
            }
            D_80203FE0[20].unk4 += ((spF8 * 0x445) >> 5);
            load_1_tile(D_0400AF80, D_0400AD80);
            func_802C78B0_6D8F60(1, 2, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), D_803F2ED0, 0, 0, 0, D_0400A720);
            load_1_tile(D_0400B800, D_0400B600);
            gSPDisplayList(D_801D9E88++, D_01003548);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x71, 0x7B, 0xFF);

            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(3, 7, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 0, 0, D_0400A840);
            }
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(5, 0xD, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 0, 0, D_0400A840);
            }

            gSPDisplayList(D_801D9E88++, D_010034C0);

            func_802C78B0_6D8F60(7, 8, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 0, 0, D_04009FC0);
            func_802C78B0_6D8F60(0xD, 0xE, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 0, 0, D_04009FC0);

            gSPDisplayList(D_801D9E88++, D_01003548);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(4, 0xA, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 1, 0, D_0400A840);
            }
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(6, 0x10, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 1, 0, D_0400A840);
            }

            gSPDisplayList(D_801D9E88++, D_010034C0);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(0xA, 0xB, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 1, 0, D_04009FC0);
            func_802C78B0_6D8F60(0x10, 0x11, FTOFIX32(1.5625), FTOFIX32(1.5625), FTOFIX32(1.5625), (s32) D_803F2ED0, 0, 1, 0, D_04009FC0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spFE, &spFC);
                func_8031A278_72B928(&D_803D552C->unk326, &spFE, &spFC);
                spFE = D_803BD5CC_7CEC7C[spFE]; spFC = D_803BD684_7CED34[spFC];
                func_80356BD8_768288(D_01002C20, D_010025A0, spFE);
                gSPDisplayList(D_801D9E88++, D_010037F0);

                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_0400B020);
                func_80356BD8_768288(D_01002C20, D_010025A0, spFC);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_0400B040);
                gSPDisplayList(D_801D9E88++, D_01003840);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spFA == 0) || (spFA == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (D_803D552C->yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->unk302, D_01033190, 0x3E, 0x2E, 0x9B, 0, 0, 0, 0, (s32) D_803D5538);
    }
    if (spFA == 0) {
        func_803034D0_714B80(D_803D552C, 0xC95, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x333, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x6B6, 0x35B);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/hippo/func_802EF0C0_700770.s")
#endif

void func_802F036C_701A1C(void) {
}

void func_802F0374_701A24(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_SPIT;
        D_803D552C->unk32C = D_803D552C->unk302;
    }
}

void func_802F03B8_701A68(void) {
    s16 xPos;
    s16 zPos;
    s16 yPos;
    s16 i;

    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        xPos = D_803D5530->xPos.h - ((((D_80152C78[((D_803D552C->unk302 & 0xFF))]) >> 7) << 6) >> 8);
        zPos = D_803D5530->zPos.h - ((((D_80152C78[(((D_803D552C->unk302 + 64) & 0xFF))]) >> 7) << 6) >> 8);
        yPos = D_803D5530->yPos.h;
        spawn_temporary_object(xPos, zPos, yPos, 1228, 180, D_803D5530, 40, 78);
        play_sound_effect_at_location(0x6D, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);

        for (i = 0; i < 4; i++) {
            create_particle_effect(
                (SSSV_RAND(64) + xPos) - 32,
                (SSSV_RAND(64) + zPos) - 32,
                SSSV_RAND(64) + yPos,
                21,
                0,
                0,
                0,
                35,
                GPACK_RGBA5551(16, 16, 16, 1),
                GPACK_RGBA5551(192, 128, 64, 1),
                0);
        }
    } else {
        recharge_skill(1);
    }
}

void drop_sticky_mine(void) {
    s16 xPos;
    s16 zPos;
    s16 yPos;
    s16 i;

    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        xPos = D_803D5530->xPos.h - ((((D_80152C78[((D_803D552C->unk302 & 0xFF))]) >> 7) << 6) >> 8);
        zPos = D_803D5530->zPos.h - ((((D_80152C78[(((D_803D552C->unk302 + 64) & 0xFF))]) >> 7) << 6) >> 8);
        yPos = D_803D5530->yPos.h;
        spawn_temporary_object(xPos, zPos, yPos, 1228, 220, D_803D5530, 40, 78);
        play_sound_effect_at_location(0x6D, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);

        for (i = 0; i < 4; i++) {
            create_particle_effect(
                (SSSV_RAND(64) + xPos) - 32,
                (SSSV_RAND(64) + zPos) - 32,
                SSSV_RAND(64) + yPos,
                21,
                0,
                0,
                0,
                35,
                GPACK_RGBA5551(16, 16, 16, 1),
                GPACK_RGBA5551(192, 128, 64, 1),
                0);
        }
    }
}

void hippo_spit(s32 arg0, s32 arg1, s32 arg2) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_SPIT;
        D_803D552C->unk32C = D_803D552C->unk302;
    }
}
