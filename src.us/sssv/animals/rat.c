#include <ultra64.h>
#include "common.h"


extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

extern s16 D_803B3F50_7C5600[];
extern s16 D_803B3F60_7C5610[];
extern s16 D_803B3F70_7C5620[];
extern s16 D_803B3F8C_7C563C[];
extern s16 D_803B3FCC_7C567C[];

// extern f32 D_803BEC00_7D02B0 = 1.3f;
// extern f32 D_803BEC04_7D02B4 = 1.3f;
// extern f64 D_803BEC08_7D02B8 = 1000.0;

extern Gfx D_04007080_CEAB0[];
extern Gfx D_040072F0_CED20[];
extern Gfx D_04007520_CEF50[];
extern Gfx D_040073B0_CEDE0[];
extern Gfx D_040073D8_CEE08[];

#if 0
void func_8035E430_76FAE0(void) {
    // s16 spD6;
    // s32 spC4;
    // s32 spC0;
    // s32 spBC;
    // s32 spB8;
    // s32 spB4;
    struct061 spA8;
    s16 spA6;
    u16 spA4;
    s16 spA2;
    s16 spA0;
    // u16 sp70;
    // u16 sp6E;
    // u16 sp6C;
    // u16 sp6A;
    // u16 sp68;
    // u16 sp66;
    // u16 sp64;
    // u16 sp62;
    // u16 sp60;
    // s32 sp5C;
    // s32 sp54;
    // s32 sp40;

    s16 temp_t1_2;
    s16 temp_t3_2;
    s16 temp_v1_10;
    s32 temp_a3;
    s32 temp_lo;
    s32 temp_lo_2;
    u16 temp_t0;
    s32 temp_t1;
    s32 temp_t3;
    s32 temp_t5;
    s32 temp_t8_2;
    s32 var_t9;

    u8 var_v1;
    u8 var_v1_2;

    u8 temp_a0_4;
    u8 temp_v0_9;

    switch (D_803D5524->unk9C) {
    case RAT:
        spA0 = 1;
        break;
    case KING_RAT:
        spA0 = 2;
        if (D_803D552C->unk308 > 0) {
            D_803D552C->unk308--;
        }
        break;
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
        if (var_v1 != 0) {
            spA2 = 0;
            D_803F2EDD = 0;
            goto block_14;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }

    spA2 = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
        (spA0 * 0x6180 * 4) / 32,
        7,
        50,
        50,
        50,
        spA0,
        var_v1 == 0);

block_14:
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
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 4;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 33;
                }
            }
        } else if ((D_803D5538 != 0) && (D_803F2D30.unk4 >= 17)) {
            if (D_803D5528->unk3C8.unk2 != 0) {
                if (D_803D5524->unk9C == RAT) {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 4;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 33;
                }
            }
        } else {
            if (D_803D5528->unk3C8.unk2 != 0) {
                if (D_803D5524->unk9C == RAT) {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 3;
                } else {
                    D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 32;
                }
            }
        }

        if ((D_803D5528->unk3C8.unk2 != 0) && (D_803A6CE4_7B8394 & 8)) {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 0x1F;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B9130_6CA7E0(&spA8, 0xCB, 0xA2, 0x16D, 0);
            func_802C1830_6D2EE0(0x11C, &spA8);
            func_802B964C_6CACFC();
        }

        switch (D_803D5524->unk9C) {
        case RAT:
            switch (D_803D552C->unk365) {
            case 18:
                D_803D5528->unk3C0.unk0 = 0;
                temp_t0 = D_803D5544 - D_803D552C->unk32A;
                if (temp_t0 == 2) {
                    if (func_803224C4_733B74(6, 25, 0, 22, 6, 40, 300, 7)) {
                        play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_6, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
                    }
                } else if (temp_t0 >= 6) {
                    D_803D552C->unk365 = 0;
                }
                if (temp_t0 < 3) {
                    var_t9 = temp_t0 << 0x13;
                } else {
                    var_t9 = (6 - temp_t0) << 0x12;
                }
                D_80203FE0[1].unk2 += ((var_t9 >> 0x10) * 0x196) >> 5;
                D_80203FE0[2].unk2 += ((var_t9 >> 0x10) * 0x196) >> 5;
                break;
            default:
                D_803D552C->unk365 = 0;
                break;
            }
            break;
        case 13: // KING_RAT
            switch (D_803D552C->unk365) {
            case 25:
                // fart cloud
                create_particle_effect(
                    (SSSV_RAND(32) + D_803D5530->xPos.h) - 16,
                    (SSSV_RAND(32) + D_803D5530->zPos.h) - 16,
                    D_803D5530->yPos.h + 8,
                    (SSSV_RAND(2) + 25),
                    (func_8012826C() - FTOFIX32(0.6103515625)),
                    (func_8012826C() - FTOFIX32(0.6103515625)),
                    func_8012826C() * 2,
                    SSSV_RAND(4),
                    GPACK_RGBA5551(128, (SSSV_RAND(64) + 192), 0, 1), // // ((((SSSV_RAND(64) + 0xC0) << 3) & 0x7C0) | 0x8001),
                    GPACK_RGBA5551((SSSV_RAND(16) + 65), 160, 72, 1), // ((((SSSV_RAND(16) + 0x41) << 8) & 0xF800) | 0x513),
                    (SSSV_RAND(32) + 10));

                if (D_803D5530->unk4A == 0) {
                    func_8032CD70_73E420(D_803D5530, SFX_UNKNOWN_48, 0x5000, 0, (((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) / 1000.0) + 2.25), D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
                }
                if (SSSV_RAND(64) == 0x35) {
                    play_sound_effect_at_location(SFX_HIPPO_DROP_MINE, 0x5000, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
                }
                func_8037F6CC_790D7C(0x10, 0x100, 1);
                break;
            case 39:
                break;
            default:
                D_803D552C->unk365 = 0;
                break;
            }
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(&D_803B3F50_7C5600, &D_803B3F60_7C5610, &D_803B3F70_7C5620, &D_803B3F8C_7C563C);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803B3F50_7C5600, &D_803B3F60_7C5610, &D_803B3F70_7C5620, &D_803B3FCC_7C567C);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 250) &&
            (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_9 = D_803F2AA2, (temp_v0_9 == 0)) || (temp_v0_9 == 2) || ((temp_v0_9 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, (spA0 * D_803F2EB0) / 4, (spA0 * D_803F2EB4) / 4, (spA0 * D_803F2EB8) / 4, D_803F2ED2, D_803F2ED4);
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

            if (spA0 == 2) { func_802C78B0_6D8F60(2, 1, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, &D_04007520_CEF50); }

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
            temp_t5 = D_803D5530->xPos.w + ((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * (0xE00 - ABS(temp_a3 >> 0xA)) * spA0);
            temp_t1 = D_803D5530->zPos.w + ((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) * (0xE00 - ABS(temp_a3 >> 0xA)) * spA0);
            temp_t8_2 = D_803D5530->yPos.w + (spA0 * 0x90000) + (spA0 * temp_a3);
            temp_lo = (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) * (spA0 * 0x300);
            temp_t3 = -((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * (spA0 * 0x300));
            if ((spA6 != 5) && (D_803F2AA2 == 0)) {
                func_8029CEF0_6AE5A0(temp_t5 + temp_lo, temp_t1 + temp_t3, temp_t8_2, (spA0 << 9), 35, &D_803D2E08, 0, 0xFF, 0, 0);
                func_8029CEF0_6AE5A0(temp_t5 - temp_lo, temp_t1 - temp_t3, temp_t8_2, (spA0 << 9), 35, &D_803D2E08, 0, 0xFF, 0, 0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spA2 == 0) || (spA2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + D_803D5524->unkBA, D_803D552C->unk302, &D_01033190, (spA0 * 0x28A) / 32, (spA0 * 0x177) / 32, 0x9B, 0, 0, 0, 0, D_803D5538);
    }

    if (D_803D5528->unk3C8.unk2 != 0) {
        if ((spA2 == 0) && (D_803F2EDB)) {
            temp_lo_2 = (D_80203FE0[2].unk2 - 0xCB) * spA0;
            temp_t3_2 = D_80203FE0[2].unk0;
            temp_v1_10 = D_80152C78[D_803D552C->unk302 & 0xFF];
            temp_t1_2 = D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF];
            func_802DE914_6EFFC4(
                D_803D5528->unk3C8.unk2,
                ((temp_lo_2 * temp_v1_10) / 16) + D_803D5530->xPos.w + ((s32) (temp_t1_2 * spA0 * temp_t3_2) / 16),
                (D_803D5530->zPos.w + ((s32) (temp_t1_2 * temp_lo_2) / 16)) - ((s32) (temp_t3_2 * temp_v1_10 * spA0) / 16),
                (((D_80203FE0[2].unk4 * spA0) << 0xF) / 16) + D_803D5530->yPos.w,
                D_803D552C->unk302);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                if ((D_803E00C0[D_803D5528->unk3C8.unk2].unk2E == 3) ||
                    (D_803E00C0[D_803D5528->unk3C8.unk2].unk2E == 32)) {
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
        if (spA0 == 1) {
            func_803034D0_714B80(D_803D552C, 609, 101, 0);
        } else {
            func_803034D0_714B80(D_803D552C, 609*2, 101*3 + 1, 0);
        }
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, spA0 * 609, spA0 * 365);
    }

    if ((D_803D5538 == 0) && (D_803D5524->unk9C == KING_RAT)) {
        if (D_803D552C->unk365 != 19) {
            if (D_803D552C->unk365 != 39) {
                D_803D552C->unk365 = 0;
            } else if (D_803D552C->unk2EC <= 0) {
                D_803D552C->unk365 = 0;
                D_803D552C->unk2B4.unk4 = 1; //(u8) (D_803D552C->unk2B4.unk0 & 0xFFF1);
            } else {
                D_803D552C->unk2EC--;
            }
        } else {
            if (D_803D552C->unk2EC <= 0) {
                D_803D552C->unk365 = 0;
            } else {
                D_803D552C->unk2EC--;
            }
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
        D_803D552C->unk365 = ATTACK_FART;
    }
}

void func_8035FAEC_77119C(void) {
    if (D_803D552C->unk365 == ATTACK_FART) {
        D_803D552C->unk365 = ATTACK_NONE;
    }
}

// king rat
void func_8035FB10_7711C0(void) {
    Animal *a;

    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803BEC10);
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
    play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803BEC14);
}

void king_rat_bugel_call(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803BEC18);
        D_803D552C->unk308 = 80;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_KING_RAT;
    D_803D552C->unk2B4.unk4 = 1;
}

void king_rat_fart(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_FART;
}
