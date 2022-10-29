#include <ultra64.h>
#include "common.h"

extern s16 D_8020407A;
extern s16 D_80204082;

extern s16 D_803A4C34_7B62E4[];
extern s16 D_803A4C64_7B6314[];
extern s16 D_803A4C94_7B6344[];

extern s16 D_803A4CA8_7B6358[];
extern s16 D_803A4CC0_7B6370[];
extern s16 D_803A4CD8_7B6388[];
extern s16 D_803A4D00_7B63B0[];
extern s16 D_803A4D58_7B6408[];

extern f32 D_803BCDD4_7CE484;

extern Gfx D_04001C80[];
extern Gfx D_04001E90[];

extern Gfx D_04000420_C7E50[];
extern Gfx D_04000870_C82A0[];
extern Gfx D_04000FB0_C89E0[];
extern Gfx D_04001080_C8AB0[];
extern Gfx D_04001150_C8B80[];
extern Gfx D_04001220_C8C50[];
extern Gfx D_040013A0_C8DD0[];
extern Gfx D_04001A20_C9450[];
extern Gfx D_04001A40_C9470[];

extern Gfx D_01003548[];

#if 0
s16 D_803A4D00_7B63B0[] = {
    0x0000, 0x000A, 0x00F0, // header
    0x003C, 0x0000,
    0x0034, 0x00B4,
    0x0045, 0x0000,
    0x00A8, 0x0000,
    0x0058, 0x0124,
    0x0058, 0x005A,
    0x005A, 0x0112,
    0x0056, 0x005E,
    0x000C, 0x0134,
    0x008E, 0x012C,
    0x0076, 0x012E,
    0x000A, 0x0028,
    0x0064, 0x008E,
    0x006C, 0x003C,
    0x006C, 0x0122,
    0x0066, 0x00C2,
    0x0054, 0x00CA,
    0x005E, 0x00A6,
    0x0056, 0x00D4,
    0x0082, 0x00A0,
};
s16 junk = 0x0; // unecessary?;
#endif


// delay slot
// RACING_DOG
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802EA7F0_6FBEA0.s")

// FLYING_DOG
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802EBB34_6FD1E4.s")

// DOG
#if 0
void func_802ED108_6FE7B8(void) {
    struct061 spB8;
    s16 spB6;
    s16 spB4;
    s16 spB2;
    s16 spB0;
    s16 spAC;
    // s16 spAA;
    // u16 sp88;
    // u16 sp86;
    // u16 sp84;
    // u16 sp82;
    // s32 sp78;

    // s16 temp_t4;
    // s16 temp_t5;
    // s16 temp_t7;
    // s16 temp_t9;

    s16 var_a1;
    s16 var_t0;

    u16 temp_t6;
    u16 temp_t8;
    // s32 temp_t9_2;
    s32 temp_v0_9;
    // s32 temp_v1_10;
    s32 temp_v1_5;
    // s32 var_t1;
    u16 var_t1_2;
    u8 var_v0;
    // u8 temp_v0_4;

    if (((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4)) && (SSSV_RAND(256) == 0x9C) && (D_803F6450 != 0)) {
        play_sound_effect_at_location(0xB6, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            spB2 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    spB2 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x800, 0, 0x9E, 0x9E, 0x4F, 1, var_v0 == 0);
done:
    if (spB2 == 0) {
        temp_t6 = (D_803D5544 - D_803D552C->unk35E);// & 0xFFFF;
        if ((D_803F6450 != 0) && (D_803F2D10.unk0 == 0) && (D_803D5530->unk4A == 0) && (temp_t6 != 0) && ((D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 3))) {
            if (D_803D552C->unk30A != 0) {
                D_803D552C->unk30A--;
                D_803D5530->yRotation = (D_803D5530->yRotation + D_803D552C->unk308) % 255;
            }
            temp_v1_5 = temp_t6 & 0xFF;
            if (D_803D552C->unk30A == 0) {
                if (((temp_v1_5 == 0xFA) || (temp_v1_5 == 0x8C) || (temp_v1_5 == 0xA0) || (temp_v1_5 == 0xAA) || (temp_v1_5 == 0xB4) || (temp_v1_5 == 0xC8) || ((temp_v1_5 == 0xDC) && (((D_803D552C->unk366 == 1)) || (D_803D552C->unk366 == 3)))) && ((D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11) && (D_803F28E0[D_803F2A98].cameraMode != 5) && (D_803F28E0[D_803F2A98].cameraMode != 6) && (D_803F28E0[D_803F2A98].cameraMode != 7) && (D_803F28E0[D_803F2A98].cameraMode != 0x1C) && (D_803F28E0[D_803F2A98].cameraMode != 0x1A)))) {
                    if ((temp_v1_5 == 0x8C) || (temp_v1_5 == 0xDC)) {
                        play_sound_effect_at_location(8, 0x4000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    }
                    D_803D552C->unk308 = (s16) (SSSV_RAND(8) - 4);
                    D_803D552C->unk30A = 7;
                    if (D_803D552C->unk308 <= 0) {
                        D_803D5528->unk370.unk4 = 25;
                        D_803D5528->unk3AC.unk4 = 25;
                        D_803D5528->unk384.unk6 = -25;
                        D_803D5528->unk398.unk6 = -25;
                    } else {
                        D_803D5528->unk370.unk4 = -25;
                        D_803D5528->unk3AC.unk4 = -25;
                        D_803D5528->unk384.unk6 = 25;
                        D_803D5528->unk398.unk6 = 25;
                    }
                }
                func_802C7BB4_6D9264(8);
            }
        } else {
            D_803D552C->unk30A = 0;
        }
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DEC4_76F574();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spB8, 0x12C, 0x96, 0x3CE, 0x96);
            func_802BD40C_6CEABC(0x1DA, 0xC8, 0x12C, 0x96, 0, 0x34, 0, 0x20, &D_803A4C34_7B62E4, &D_803A4C64_7B6314, &D_803A4C94_7B6344, 0x1DA, 0xC8, 0x12C, 0x96, 0x64, 0xE4, 0x64, 0x84, &D_803A4C34_7B62E4, &D_803A4C64_7B6314, &D_803A4C94_7B6344, &spB8, 1);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x22C, 0x1BB, 0);
            func_8038CCF0_79E3A0(0xDD, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();

            if (D_803D5528->unk3C0.unk0 == 16) {
                if (D_803D5528->unk3C0.unk2 < 7) {
                    D_80203FE0[19].unk2 -= (D_803D5528->unk3C0.unk2 * 556) / 6;
                    D_80203FE0[20].unk2 -= (D_803D5528->unk3C0.unk2 * 556) / 6;
                } else if (D_803D5528->unk3C0.unk2 < 17) {
                    D_80203FE0[19].unk2 -= ((D_803D5528->unk3C0.unk2 * -556) + 8896) / 10;
                    D_80203FE0[20].unk2 -= ((D_803D5528->unk3C0.unk2 * -556) + 8896) / 10;
                }
            }
        }

        spAC = 0;
        switch (D_803D552C->unk365) {
        case 18:
            D_803D5528->unk3C0.unk0 = 0;
            temp_t8 = (D_803D5544 - D_803D552C->unk32A);
            if (temp_t8 == 4) {
                if (func_803224C4_733B74(0x1E, 0x45, 0, 0x22, 7, 0, 0, 0xE) != 0) {
                    play_sound_effect_at_location(7, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                } else {
                    play_sound_effect_at_location(182, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
            } else if (temp_t8 >= 12) {
                D_803D552C->unk365 = 0;
            }
            if (temp_t8 < 5) {
                var_a1 = temp_t8 * 4;
                if (temp_t8 == 1) {
                    apply_recoil(-3);
                }
            } else {
                var_a1 = (12 - temp_t8) * 2;
            }
            temp_v0_9 = var_a1 * 0x22C;

            // not right
            D_80203FE0[0].unk0 += temp_v0_9 >> 4;
            D_80203FE0[0].unk0 -= temp_v0_9 >> 5;

            D_80203FE0[0].unk0 += temp_v0_9 >> 4;
            D_80203FE0[0].unk0 -= temp_v0_9 >> 6;
            break;
        case 44:
            var_t1_2 = (D_803D5544 - D_803D552C->unk32A);// & 0xFFFF;
            if (var_t1_2 == 1) {
                play_sound_effect_at_location(34, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            }
            if (var_t1_2 < 60) {
                if ((D_803D5538 != 0) && (var_t1_2 == 1)) {
                    D_803D554A += 1;
                }
                spAC = (D_80152C78[(s16)(var_t1_2 << 5) & 0xFF] >> 7) >> 2;

                create_particle_effect(
                    (SSSV_RAND(32) + D_803D5530->xPos.h) - 0x10,
                    (SSSV_RAND(32) + D_803D5530->zPos.h) - 0x10,
                    D_803D5530->yPos.h + (D_803D5524->unkBA >> 1),
                    0x18,
                    ((SSSV_RAND(64) - 32) << 0xC) + D_803D5530->xVelocity.w,
                    ((SSSV_RAND(64) - 32) << 0xC) + D_803D5530->zVelocity.w,
                    D_803D5530->yVelocity.w + 0x60000,
                    SSSV_RAND(4) + 2,
                    0,
                    0,
                    0);
                D_803D5530->xVelocity.w += (SSSV_RAND(64) - 32) << 12;
                D_803D5530->zVelocity.w += (SSSV_RAND(64) - 32) << 12;
            } else {
                D_803D552C->unk365 = 0;
                if (D_803D5538 != 0) {
                    D_803D554A -= 1;
                }
            }
            break;
        default:
            if ((D_803D552C->unk36C != 0) && (D_803D5530->state == 2) && ((D_803D5544 - D_803D552C->unk35E) >= 0x51) && (SSSV_RAND(64) == 0x1B)) {
                D_803D552C->unk36C = 0U;
                D_803D552C->unk32A = D_803D5544;
                D_803D552C->unk365 = 0x2CU;
                D_803D5528->unk3C0.unk0 = 0x11U;
                D_803D5528->unk3C0.unk2 = 0;
            } else {
                D_803D552C->unk365 = 0U;
            }
            break;
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A4CA8_7B6358, D_803A4CC0_7B6370, D_803A4CD8_7B6388, D_803A4D00_7B63B0);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A4CA8_7B6358, D_803A4CC0_7B6370, D_803A4CD8_7B6388, D_803A4D58_7B6408);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs +  30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || ((D_803F2AA2 == 0)) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
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
            func_8038C230_79D8E0((D_803D5524->unkBA * 8 / 5), 2, 3, 3, D_803BCDD4_7CE484);
            load_1_tile(D_04001E90, D_04001C80);
            func_802C78B0_6D8F60(2, 1, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, spAC, 0, 0, D_04000420_C7E50);
            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000870_C82A0);
            if ((D_803D5540 >= 0xB5) && ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1))) {
                var_t0 = ((D_80152C78[(D_803D5540 << 6) & 0xFF] >> 7) * 600) >> 0xC;
            } else {
                var_t0 = 0;
            }
            D_80203FE0[2].unk0 += var_t0;
            D_80203FE0[1].unk0 += var_t0;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040013A0_C8DD0); }
            D_80203FE0[2].unk0 -= var_t0;
            D_80203FE0[1].unk0 -= var_t0;

            gDPSetPrimColor(D_801D9E88++, 0, 0, 0x14, 0x14, 0x14, 0xFF);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 19, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001220_C8C50); }

            gSPDisplayList(D_801D9E88++, &D_01003548);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7,  0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 13, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 16, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            func_802C78B0_6D8F60(7,  8,  0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            func_802C78B0_6D8F60(10, 11, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            func_802C78B0_6D8F60(13, 14, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            func_802C78B0_6D8F60(16, 17, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(8,  9,  0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(11, 12, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(14, 15, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(17, 18, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spB6, &spB4);
                func_8031A278_72B928(&D_803D552C->unk326, &spB6, &spB4);
#pragma _permuter sameline start
                spB6 = D_803BD54A_7CEBFA[spB6]; spB4 = D_803BD602_7CECB2[spB4];
#pragma _permuter sameline end
                func_80356BD8_768288(&D_01000CC0, &D_01000620, spB6);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A20_C9450);
                func_80356BD8_768288(&D_01000CC0, &D_01000620, spB4);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A40_C9470);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spB2 == 0) || (spB2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, &D_01033190, 0x15, 0x12, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spB2 == 0) {
        if ((D_803D5528->unk3C0.unk0 == 0x10) && (D_803D5528->unk3C0.unk2 < 9)) {
            func_803034D0_714B80(D_803D552C, 0x384, 0, 0);
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, ((D_803D5528->unk3C0.unk2 * -0x1BB) + 0xF93) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else if ((D_803D5528->unk3C0.unk0 == 0x10) && (D_803D5528->unk3C0.unk2 < 0x10)) {
            func_803034D0_714B80(D_803D552C, 0x384, 0, 1);
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, ((D_803D5528->unk3C0.unk2 * 0x1BB) - 0xC1D) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_803034D0_714B80(D_803D552C, 0x384, 0, 1);
            func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x1BB, 0);
            func_80303D50_715400(D_803D552C, 3);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 0x258, 0x384);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802ED108_6FE7B8.s")
#endif

void func_802EE89C_6FFF4C(void) {
    if (D_803D552C->missileSide != 0) {
        D_803D552C->missileSide = 0;
    } else {
        D_803D552C->missileSide = 1;
    }
    if (D_803D5538 != 0) {
        play_sound_effect_at_location(0x94, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
    }
    D_803D552C->unk30E = 1;
    D_803D552C->unk312 = 4;

    if (D_803D552C->unk310 == 0) {
        play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        func_80321E60_733510(OBJECT_CANNONBALL, 0, 0, -28, 0, 0, -9, 8);
        D_803D552C->unk310 = 20;
    }
    D_803D552C->unk310 = MAX(3, D_803D552C->unk310 - 1);
}

void func_802EE9EC_70009C(void) {
    D_803D552C->unk310 = MAX(0, D_803D552C->unk310 - 1);
}

void func_802EEA18_7000C8(void) {
    if (D_803D552C->unk365 != ATTACK_DOG_1) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_DOG_1;
    }
}

void func_802EEA54_700104(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_802EEA7C_70012C(void) {

    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 15,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 15
        );
    } else {
        func_8037D994_78F044(16);
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 15,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 15
        );
    }
}

void func_802EEC44_7002F4(void) {
    Animal * animal;
    s16 temp_v1;
    u8 temp_t0;
    s32 phi_t1;

    animal = func_8037E9AC_79005C();
    if (animal == NULL) {
        func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
    }
    if (func_8037FBBC_79126C()) {
        phi_t1 = 450;
    } else {
        phi_t1 = -450;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[temp_t0] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->yPos.h + ((D_803D5530->unk42 * 3) >> 2),
        0,
        temp_t0*360 >> 8,
        animal,
        3,
        30,
        0.23f,
        23,
        15,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void racing_dog_fire_missile(Animal *animal) {
    s16 temp_v1;
    u8 temp_t0;
    s32 phi_t1;

    if (animal == NULL) {
        func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
    }
    if (func_8037FBBC_79126C() != 0) {
        phi_t1 = 450;
    } else {
        phi_t1 = -450;
    }
    temp_v1 = D_803D552C->unk302;
    temp_t0 = D_803D552C->unk302;
    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(temp_v1 + 64)] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[temp_t0] >> 7) * phi_t1) / 32) >> 8),
        D_803D5530->yPos.h + ((D_803D5530->unk42 * 3) >> 2),
        10,
        temp_t0*360 >> 8,
        animal,
        4,
        30,
        0.23f,
        35,
        15,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void dog_bite(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
}

void flying_dog_fire_gun(s32 arg0, s32 arg1, s32 arg2) {
    if (D_803D552C->missileSide != 0) {
        D_803D552C->missileSide = 0;
    } else {
        D_803D552C->missileSide = 1;
    }
    D_803D552C->unk30E = 1;
    D_803D552C->unk312 = 4;
}

void flying_dog_drop_bomb(s32 arg0, s32 arg1, s32 arg2) {
    func_80321E60_733510(OBJECT_CANNONBALL, 0, 0, -28, 0, 0, -9, 8);
    play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void racing_dog_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 16;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
