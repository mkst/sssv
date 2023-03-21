#include <ultra64.h>
#include "common.h"

extern s16 D_803A50D0_7B6780[];
extern s16 D_803A5100_7B67B0[];
extern s16 D_803A5130_7B67E0[];
extern s16 D_803A5144_7B67F4[];
extern s16 D_803A5174_7B6824[];
extern s16 D_803A51A4_7B6854[];
extern s16 D_803A51B8_7B6868[];
extern s16 D_803A51CC_7B687C[];
extern s16 D_803A51E0_7B6890[];
extern s16 D_803A5204_7B68B4[];
extern s16 D_803A51B8_7B6868[];

extern s16 D_803A5250_7B6900[];

extern f32 D_803BCE70_7CE520;

extern Gfx D_010025A0[];
extern Gfx D_01002C20[];
extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

extern Gfx D_04000130_F1190[];
extern Gfx D_04000350_F13B0[];
extern Gfx D_04000500_F1560[];
extern Gfx D_04000A00_F1A60[];
extern Gfx D_04000D70_F1DD0[];
extern Gfx D_04000F60_F1FC0[];
extern Gfx D_04000FC0_F2020[];


#ifdef NON_MATCHING
void func_802F1730_702DE0(void) {
    struct061 spC4;
    s16 spC2;                                       /* compiler-managed */
    s16 spC0;                                       /* compiler-managed */
    s16 spBE;
    s16 spBC;
    s16 spBA;
    s16 spB2;
    s16 spB0;


    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t2;
    s16 temp_t3;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t7;
    s16 var_t2;
    s32 temp_t9_2;

    u8 var_v0;
    u8 var_v0_2;
    u8 temp_v0_8;
    s32 var_v0_3;

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            spBE = 0;
            D_803F2EDD = 0;
            goto block_9;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0_2 = 1;
    } else {
        var_v0_2 = 0;
    }
    spBE = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x1500, (u8) 5, (s16) 0x9E, (s16) 0x9E, (s16) 0, (s8) 1, var_v0_2 == 0);

block_9:
    if (spBE == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0xC8);
        spB0 = 0;
        spB2 = 0;
        if (D_803A6CE4_7B8394 & 8) {
            D_803D5528->unk3C8.unk2 = 0;
        }

        switch (D_803D552C->unk365) {
        case ATTACK_NONE:
            break;
        case ATTACK_ROAR:
            if (D_803D5530->unk4A != 0) {
                D_803D552C->unk32A += 1;
            } else {
                func_802DC3F4_6EDAA4(0x50, &spB2, &spB0);
                var_v0_3 = D_803D5544 - D_803D552C->unk32A;
                if (var_v0_3 == 20) {
                    play_sound_effect_at_location(SFX_UNKNOWN_118, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    do_rumble(0, 0x3C, 0x3C, 0x14, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
                    // ??
                    var_v0_3 = D_803D5544 - D_803D552C->unk32A;
                }
                if ((var_v0_3 > 14) && (var_v0_3 < 70)) {
                    func_803421E0_753890(4);
                    func_8037DA08_78F0B8(16, 320, 2);
                    func_8037E9AC_79005C();
                }
                D_803D5528->unk3C0.unk0 = 0;
            }
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        if (spB2 == 0) {
            if (D_803D5540 < 0x40) {
                spB2 = (D_80152C78[(D_803D5540 << 4) & 0xFF] >> 7) >> 6;
            }
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spC4, 0x1C2, 600, 0x4B0, 0xD2);
            func_802BD40C_6CEABC(0x20D, 0x2A3, 0, 0xD2, 0, 0x80, 0x64, 0x80, &D_803A50D0_7B6780, &D_803A5100_7B67B0, &D_803A5130_7B67E0, 0x20D, 0x2A3, 0, 0xD2, 0, 0x80, 0, 0x1E, &D_803A5144_7B67F4, &D_803A5174_7B6824, &D_803A51A4_7B6854, &spC4, 0);
            func_802B964C_6CACFC();
            func_802BB840_6CCEF0(0x2EE);
            func_802C4A70_6D6120(0xF, 0x384, 4);
            func_8038CCF0_79E3A0(0xE1, 0x14, -1, -1, -1, -1);
            D_80203FE0[19].unk2 += 600;
            D_80203FE0[20].unk2 += 600;
            func_802C7600_6D8CB0(600, 0x1C);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {                    /* irregular */
            case 1:
                func_802DB670_6ECD20(D_803A51B8_7B6868, D_803A51CC_7B687C, D_803A51E0_7B6890, D_803A5204_7B68B4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A51B8_7B6868, D_803A51CC_7B687C, D_803A51E0_7B6890, D_803A5250_7B6900);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_8 = D_803F2AA2, (temp_v0_8 == 0)) || (temp_v0_8 == 2) || ((temp_v0_8 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4,  (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 3, 3, 0.22f);
            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0x0, 0xFF);

            if ((D_803D5530->state == 3) && (D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
                // bleurgh
                var_t2 =    (D_80152C78[(D_803D552C->unk2F6 + 0x40) & 0xFF] >> 7) / 16;
                temp_t7 =   ((0x100 + (D_80152C78[(D_803D552C->unk2F6 + 0x40) & 0xFF] >> 7)) * 0x20D) >> 0xA;
                temp_t9_2 = ((0x100 - (D_80152C78[(D_803D552C->unk2F6 + 0x40) & 0xFF] >> 7)) * 0x20D) >> 0xA;
                spBA =      ((D_80152C78[(D_803D552C->unk2F6 + 0x40) & 0xFF] >> 7) * -0x20D) >> 0xA;
                temp_t6 =   ((D_80152C78[(D_803D552C->unk2F6 * 2) & 0xFF] >> 7) * 0x20D) >> 0xB;

                D_80203FE0[4].unk4  += temp_t7;
                D_80203FE0[10].unk4 += temp_t7;
                D_80203FE0[11].unk4 += temp_t7;
                D_80203FE0[6].unk4  += temp_t7;
                D_80203FE0[16].unk4 += temp_t7;
                D_80203FE0[17].unk4 += temp_t7;

                D_80203FE0[3].unk4  += temp_t9_2;
                D_80203FE0[7].unk4  += temp_t9_2;
                D_80203FE0[8].unk4  += temp_t9_2;
                D_80203FE0[5].unk4  += temp_t9_2;
                D_80203FE0[13].unk4 += temp_t9_2;
                D_80203FE0[14].unk4 += temp_t9_2;

                D_80203FE0[1].unk4  += temp_t6;
                D_80203FE0[2].unk4  += temp_t6;
                D_80203FE0[19].unk4 += temp_t6;
                D_80203FE0[20].unk4 += temp_t6;
            } else {
                var_t2 = 0;
                spBA = 0;
            }
            D_80203FE0[1].unk0  += spBA;
            D_80203FE0[20].unk0 += spBA;
            D_80203FE0[20].unk4 += (spB0 * 600) >> 5;

            func_802C78B0_6D8F60(0x14, 1, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, D_803F2ED0, 0, 0, 0, D_04000A00_F1A60);

            D_80203FE0[20].unk4 -= ((spB2 + spB0) * 600) >> 5;
            D_80203FE0[1].unk4  += (spB0 * 600) >> 3;
            D_80203FE0[1].unk2  += (spB0 * 600) >> 5;
            D_80203FE0[20].unk2 += (spB0 * 600) >> 5;

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x14, 1, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, D_803F2ED0, 0, 0, 0, D_04000D70_F1DD0); }

            D_80203FE0[20].unk4 += (spB2 * 600) >> 5;
            D_80203FE0[1].unk4  -= (spB0 * 600) >> 3;
            D_80203FE0[1].unk2  -= (spB0 * 600) >> 5;
            D_80203FE0[20].unk2 -= (spB0 * 600) >> 5;

            D_80203FE0[1].unk0  -= spBA;
            D_80203FE0[20].unk0 -= spBA;

            func_802C78B0_6D8F60(1, 2, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, var_t2, 0, 0, D_04000350_F13B0);

            gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3,  7, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 0, 0, D_04000600_E7BB0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 13, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 0, 0, D_04000230_E77E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 1, 0, D_04000600_E7BB0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 16, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 1, 0, D_04000230_E77E0); }

            gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);

            func_802C78B0_6D8F60(7,   8, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 0, 0, D_04000500_F1560);
            func_802C78B0_6D8F60(13, 14, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 0, 0, D_04000130_F1190);
            func_802C78B0_6D8F60(10, 11, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 1, 0, D_04000500_F1560);
            func_802C78B0_6D8F60(16, 17, FTOFIX32(1.5), FTOFIX32(1.5), FTOFIX32(1.5), D_803F2ED0, 0, 1, 0, D_04000130_F1190);

            D_80203FE0[20].unk4 += (spB0 * 600) >> 5;
            D_80203FE0[1].unk0  += spBA;
            D_80203FE0[20].unk0 += spBA;

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spC2, &spC0);
                func_8031A278_72B928(&D_803D552C->unk326, &spC2, &spC0);
                if (D_803D552C->unk365 == ATTACK_ROAR) {
                    spC0 = spC2 = 2;
                }
#pragma _permuter sameline start
                spC2 = D_803BD5CC_7CEC7C[spC2]; spC0 = D_803BD684_7CED34[spC0];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01002C20, D_010025A0, spC2);
                gSPDisplayList(D_801D9E88++, D_010037F0_3D0C0);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, D_803F2ED0, 0, 0, 0, D_04000F60_F1FC0);
                func_80356BD8_768288(D_01002C20, D_010025A0, spC0);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, (D_803F2EC8 * 0x60) >> 6, D_803F2ED0, 0, 0, 0, D_04000FC0_F2020);

                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spBE == 0) || (spBE == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, &D_01033190, 0x32, 0x22, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    spBC = D_803D5528->unk3C8.unk2;
    if (spBC != 0) {
        if ((spBE == 0) && (D_803F2EDB != 0)) {
            temp_t0 = D_80203FE0[26].unk2;
            temp_t1 = D_80152C78[D_803D552C->unk302 & 0xFF];
            temp_t2 = D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF];
            temp_t3 = D_80203FE0[26].unk0;

            temp_t4 = (D_803D5530->xPos.w + ((temp_t0 * temp_t1) / 32)) + ((temp_t2 * temp_t3) / 32);
            temp_t5 = (D_803D5530->zPos.w + ((temp_t2 * temp_t0) / 32)) - ((temp_t3 * temp_t1) / 32);
            temp_t6 = D_803D5530->yPos.w + ((D_80203FE0[26].unk4 << 0x10) / 32);

            func_802DE914_6EFFC4(
                spBC,
                temp_t4,
                temp_t5,
                temp_t6,
                D_803D552C->unk302);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3C0C_7B52BC);
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (spBE == 0) {
        func_803034D0_714B80(D_803D552C, 0x384, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x2A3, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x384, 0x1C2);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/lion/func_802F1730_702DE0.s")
#endif

void func_802F2A2C_7040DC(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_ROAR;
    play_sound_effect_at_location(SFX_LION_ROAR, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void lion_roar(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_ROAR;
    play_sound_effect_at_location(SFX_LION_ROAR, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}
