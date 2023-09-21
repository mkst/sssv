#include <ultra64.h>
#include "common.h"


extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

extern s16 D_803B3F50_7C5600[];
extern s16 D_803B3F60_7C5610[];
extern s16 D_803B3F70_7C5620[];
extern s16 D_803B3F8C_7C563C[];
extern s16 D_803B3FCC_7C567C[];

extern Gfx D_04007080_CEAB0[];
extern Gfx D_040072F0_CED20[];
extern Gfx D_04007520_CEF50[];
extern Gfx D_040073B0_CEDE0[];
extern Gfx D_040073D8_CEE08[];

#ifdef NON_MATCHING
// CURRENT (268)
void func_8035E430_76FAE0(void) {

    s16 tailIndex;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 temp_t5;
    s32 temp_t1;
    s32 temp_t8_2;
    s32 temp_lo;
    s32 temp_t3;
    u8 temp_v0_9;


    struct061 spA8;
    s16 spA6;
    u16 spA4;
    s16 spA2;
    s16 scale; // spA0

    s32 temp_a3;
    u16 ticks_remaining;
    s16 var_t9;

    switch (D_803D5524->unk9C) {
    case RAT:
        scale = 1;
        break;
    case KING_RAT:
        scale = 2;
        if (D_803D552C->unk308 > 0) {
            D_803D552C->unk308--;
        }
        break;
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spA2 = 0;
        D_803F2EDD = 0;
    } else {

        spA2 = func_802E89F0_6FA0A0(
            D_803D552C->xPos.w,
            D_803D552C->zPos.w,
            D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
            (((((scale * 15)) << 7) * 52)) / 32,
            7,
            50,
            50,
            50,
            scale,
            CHECK_SEGMENT == 0);
    }

    if (spA2 == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);

        if (D_803D552C->unk366 == 5) {
            if (D_803D5528->unk3C8.unk2 != 0) {
                if (D_803D5524->unk9C == RAT) {
                    D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 4;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 33;
                }
            }
        } else if ((D_803D5538 != 0) && (D_803F2D30.unk4 >= 17)) {
            if (D_803D5528->unk3C8.unk2 != 0) {
                if (D_803D5524->unk9C == RAT) {
                    D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 4;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 33;
                }
            }
        } else {
            if (D_803D5528->unk3C8.unk2 != 0) {
                if (D_803D5524->unk9C == RAT) {
                    D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 3;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 32;
                }
            }
        }

        if ((D_803D5528->unk3C8.unk2 != 0) && (D_803A6CE4_7B8394 & 8)) {
            D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 0x1F;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B9130_6CA7E0(&spA8, 0xCB, 0xA2, 0x16D, 0);
            func_802C1830_6D2EE0(0x11C, &spA8);
            func_802B964C_6CACFC();
        }

        switch (D_803D5524->unk9C) {
        case RAT:
            switch (D_803D552C->unk365) {
            case ATTACK_BITE:
                D_803D5528->unk3C0.unk0 = 0;
                ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                if (ticks_remaining == 2) {
                    if (func_803224C4_733B74(6, 25, 0, 22, 6, 40, 300, 7)) {
                        play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_6, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
                    }
                } else if (ticks_remaining >= 6) {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                if (ticks_remaining < 3) {
                    var_t9 = ticks_remaining << 3;
                } else {
                    var_t9 = (6 - ticks_remaining) << 2;
                }
                D_80203FE0[1].unk2 += ((var_t9) * 0x196) >> 5;
                D_80203FE0[2].unk2 += ((var_t9) * 0x196) >> 5;
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
            break;
        case KING_RAT:
            switch (D_803D552C->unk365) {
            case ATTACK_FART_CLOUD:
                create_particle_effect(
                    D_803D5530->xPos.h + (SSSV_RAND(32) - 16),
                    D_803D5530->zPos.h + (SSSV_RAND(32) - 16),
                    D_803D5530->yPos.h + 8,
                    (SSSV_RAND(2) + 25),
                    (SSSV_RAND(0x10000) - FTOFIX32(0.6103515625)),
                    (SSSV_RAND(0x10000) - FTOFIX32(0.6103515625)),
                    SSSV_RAND(0x10000) << 1,
                    SSSV_RAND(4),
                    GPACK_RGBA5551(128, (SSSV_RAND(64) + 192), 0, 1),
                    GPACK_RGBA5551(SSSV_RAND(16) + 65, 160, 72, 1),
                    (0, SSSV_RAND(32) + 10)); // slight improvement, but not correct

                if (D_803D5530->unk4A == 0) {
                    func_8032CD70_73E420(
                        D_803D5530,
                        SFX_UNKNOWN_48,
                        0x5000,
                        0,
                        ((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) / 1000.0) + 2.25,
                        D_803D5530->xPos.h,
                        D_803D5530->zPos.h,
                        D_803D5530->yPos.h);
                }
                if (SSSV_RAND(64) == 0x35) {
                    play_sound_effect_at_location(SFX_HIPPO_DROP_MINE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
                func_8037F6CC_790D7C(0x10, 0x100, 1);
                break;
            case ATTACK_KING_RAT:
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B3F50_7C5600, D_803B3F60_7C5610, D_803B3F70_7C5620, D_803B3F8C_7C563C);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B3F50_7C5600, D_803B3F60_7C5610, D_803B3F70_7C5620, D_803B3FCC_7C567C);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 250) &&
            (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_9 = D_803F2AA2, (temp_v0_9 == 0)) || (temp_v0_9 == 2) || ((temp_v0_9 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, (scale * D_803F2EB0) / 4, (scale * D_803F2EB4) / 4, (scale * D_803F2EB8) / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x80, 0x80, 0xFF);

            func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x34) >> 6, (D_803F2EC0 * 0x34) >> 6, (D_803F2EC4 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, &D_04007080_CEAB0);
            gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0x14, 0x14, 0x14, 0xFF);

            // rat wheels?
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7,  8,  FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_040072F0_CED20); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(10, 11, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_040072F0_CED20); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(13, 14, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_040072F0_CED20); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(16, 17, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_040072F0_CED20); }

            if (scale == 2) { func_802C78B0_6D8F60(2, 1, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_04007520_CEF50); }

            func_8031A150_72B800(D_803D552C->unk326++, &spA6, &spA4);
            func_8031A278_72B928(&D_803D552C->unk326, &spA6, &spA4);

            if (spA6 != 5) {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
            } else {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0x9B, 0x00, 0x00, 0xFF);
            }
            func_802C78B0_6D8F60(2, 1, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_040073B0_CEDE0);
            func_802C78B0_6D8F60(2, 1, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_040073D8_CEE08);

            temp_a3 = (((D_80203FE0[1].unk4 << 0xF) / 16) * 2) - FTOFIX32(22.0);
            temp_t5 = D_803D5530->xPos.w + scale * ((0xE00 - ABS(temp_a3 >> 0xA)) * (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7));
            temp_t1 = D_803D5530->zPos.w + scale * ((0xE00 - ABS(temp_a3 >> 0xA)) * (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7));
            temp_t8_2 = D_803D5530->yPos.w + (scale * 0x90000) + (scale * temp_a3);
            temp_lo = (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) * (scale * 0x300);
            temp_t3 = -((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * (scale * 0x300));

            if ((spA6 != 5) && (D_803F2AA2 == 0)) {
                func_8029CEF0_6AE5A0(
                    temp_t5 + temp_lo,
                    temp_t1 + temp_t3,
                    temp_t8_2,
                    (scale << 9),
                    35,
                    &D_803D2E08,
                    0,
                    0xFF,
                    0,
                    0);
                func_8029CEF0_6AE5A0(
                    temp_t5 - temp_lo,
                    temp_t1 - temp_t3,
                    temp_t8_2,
                    (scale << 9),
                    35,
                    &D_803D2E08,
                    0,
                    0xFF,
                    0,
                    0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spA2 == 0) || (spA2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + D_803D5524->unkBA, D_803D552C->unk302, &D_01033190, (scale * 0x28A) / 32, (scale * 0x177) / 32, 0x9B, 0, 0, 0, 0, D_803D5538);
    }

    tailIndex = D_803D5528->unk3C8.unk2;
    if (tailIndex != 0) {
        if ((spA2 == 0) && (D_803F2EDB)) {

            a1 = D_803D5530->xPos.w + ((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * (scale * (D_80203FE0[2].unk0       ))) / 16) + ((D_80152C78[D_803D552C->unk302 & 0xFF] * (scale * (D_80203FE0[2].unk2 - 0xCB))) / 16);
            a2 = D_803D5530->zPos.w + ((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * (scale * (D_80203FE0[2].unk2 - 0xCB))) / 16) - ((D_80152C78[D_803D552C->unk302 & 0xFF] * D_80203FE0[2].unk0 * scale) / 16);
            a3 = D_803D5530->yPos.w + (((D_80203FE0[2].unk4 * scale) << 0xF) / 16);

            func_802DE914_6EFFC4(
                tailIndex,
                a1,
                a2,
                a3,
                D_803D552C->unk302);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                if ((D_803E00C0[D_803D5528->unk3C8.unk2].tailType == 3) ||
                    (D_803E00C0[D_803D5528->unk3C8.unk2].tailType == 32)) {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3B4C_7B51FC);
                } else {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3BAC_7B525C);
                }
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (spA2 == 0) {
        if (scale == 1) {
            func_803034D0_714B80(D_803D552C, 609, 101, 0);
        } else {
            func_803034D0_714B80(D_803D552C, 609*2, 101*3 + 1, 0);
        }
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, (scale * 609) & 0xFFFF, (scale * 365));
    }

    if ((D_803D5538 == 0) && (D_803D5524->unk9C == KING_RAT)) {
        switch (D_803D552C->unk365) {
        case ATTACK_FART_CLOUD:
            if (D_803D552C->unk2EC <= 0) {
                D_803D552C->unk365 = ATTACK_NONE;
            } else {
                D_803D552C->unk2EC--;
            }
            break;
        case ATTACK_KING_RAT:
            if (D_803D552C->unk2EC <= 0) {
                D_803D552C->unk365 = ATTACK_NONE;
                D_803D552C->unk2B4.unk4 = 0;
            } else {
                D_803D552C->unk2EC--;
            }
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/rat/func_8035E430_76FAE0.s")
#endif

void func_8035F92C_770FDC(void) {
    if (((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(
            D_803D5530->xPos.h - (((D_80152C78[(u8)(D_803D552C->unk302)] >> 7) * 20) >> 8),
            D_803D5530->zPos.h - (((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * 20) >> 8),
            D_803D5530->yPos.h,
            552, 110, D_803D5530, 3, 33);
        play_sound_effect_at_location(SFX_DROP_MINE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
    } else {
        recharge_skill(0);
    }
}

void func_8035FA5C_77110C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_8035FA84_771134(void) {
    if ((D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) {
        func_8035FAEC_77119C();
    } else {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_FART_CLOUD;
    }
}

void func_8035FAEC_77119C(void) {
    if (D_803D552C->unk365 == ATTACK_FART_CLOUD) {
        D_803D552C->unk365 = ATTACK_NONE;
    }
}

// king rat
void func_8035FB10_7711C0(void) {
    Animal *a;

    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
            D_803D552C->unk308 = 80;
        } else {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x7000, 0, 1.3f);
            D_803D552C->unk308 = 80;
        }
    }
    a = func_8037E9AC_79005C();
    D_803D552C->unk2CC = a;
    if (a != NULL) {
        D_803D552C->unk2B4.unk4 = 1;
    } else {
        D_803D552C->unk2B4.unk4 = 0;
    }
}

// king rat
void func_8035FC08_7712B8(void) {
    D_803D552C->unk2B4.unk4 = 0;
    D_803D552C->unk2CC = NULL;
}

void rat_drop_mine(void) {
    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) {
        if (D_803D5530->unk6C == 0) {
            spawn_temporary_object(
                D_803D5530->xPos.h - (((D_80152C78[(u8)(D_803D552C->unk302)] >> 7) * 20) >> 8),
                D_803D5530->zPos.h - (((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * 20) >> 8),
                D_803D5530->yPos.h,
                552,
                150,
                D_803D5530,
                3,
                33);
            play_sound_effect_at_location(SFX_DROP_MINE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }
}

void rat_bite(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
    play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
}

void king_rat_bugel_call(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
        D_803D552C->unk308 = 80;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_KING_RAT;
    D_803D552C->unk2B4.unk4 = 1;
}

void king_rat_fart(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_FART_CLOUD;
}
