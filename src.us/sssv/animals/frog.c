#include <ultra64.h>
#include "common.h"


void func_80302200_7138B0(void) {
    s16 temp_t5;
    s16 sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6E;
    s16 tmp;
    s16 phi_v1;
    s16 phi_t0;
    u8  phi_v0;
    u8  tmp2;
    s16 pad[2];

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            phi_v0 = 1;
        } else {
            phi_v0 = 0;
        }
        if (phi_v0 != 0) {
            sp70 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }
    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        phi_v0 = 1;
    } else {
        phi_v0 = 0;
    }
    sp70 = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
        0x730,
        0,
        0,
        0x9E,
        0,
        1,
        phi_v0 == 0);

done:
    if (sp70 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035D734_76EDE4();
        switch (D_803D552C->unk365) {
        case ATTACK_NONE:
            break;
        case ATTACK_FROG_TONGUE:
            func_802DCCAC_6EE35C(16);
            if ((D_803D5544 - D_803D552C->unk32A) == 4) {
                tmp = func_803224C4_733B74(0x16, 0x54, 0, 0x1A, 0xF, 0, 0, 4);
                phi_v1 = tmp;
                if (tmp != 2) {
                    tmp = func_803224C4_733B74(0x16, 0x38, 0, 0x1A, 0xF, 0, 0, 4);
                    phi_v1 |= tmp;
                    if (tmp != 2) {
                        tmp = func_803224C4_733B74(0x16, 0x1C, 0, 0x1A, 0xF, 0, 0, 4);
                        phi_v1 |= tmp;
                    }
                }
                if (phi_v1 & 2) {
                    play_sound_effect_at_location(68, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
            }
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B96D0_6CAD80(&sp74, 0x167, 0x262, 0);
            func_802C1A44_6D30F4(0x262, 0x6B, &sp74);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A5520_7B6BD0, D_803A5524_7B6BD4, D_803A5528_7B6BD8, D_803A5530_7B6BE0);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A5520_7B6BD0, D_803A5524_7B6BD4, D_803A5528_7B6BD8, D_803A5544_7B6BF4);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || ((tmp2 = D_803F2AA2) == 0) || (tmp2 == 2) || ((tmp2 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

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

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.38f);
            func_8038C484_79DB34(2, 1, 3, -0.38f, -0xBB8);
            if ((D_803D5530->state < 0x2C) && (D_803D5530->state >= 0x29)) {
                D_803D552C->unk30A -= D_803D552C->unk30E * 7;
            }
            if ((D_803F2D10.unk0 == 0) && (D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
                sp72 = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.h * 0x10);
                func_80300130_7117E0(&sp72, &D_803D552C->unk30A, 0x60, -0x100, 3, 3, D_803D5530->yVelocity.h * 0x10, 4);
            } else {
                sp72 = D_803D552C->unk308;
            }
            D_803D552C->unk308 = sp72;

            if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90)) {
                sp6E = (D_803D5540 << 5) & 0xFF;
                func_8034B848_75CEF8(0);
            } else if (D_803D5530->state == 0x8F) {
                sp6E = (D_803D5540 << 6) & 0xFF;
                func_8034B848_75CEF8(0);
            } else {
                sp6E = 0;
            }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 14, FTOFIX32(0.71875), FTOFIX32(0.71875), ((0x10000 + (sp72 << 5)) * 0x2E) >> 6, D_803F2ED0, sp6E, 0, 0, D_040088F0_F9950); }
            D_80203FE0[2].unk4 += sp72 * 3;
            D_80203FE0[1].unk4 += sp72 * 3;
            if (D_803F2ED8 != 0) { func_802C78B0_6D8F60(1, 2, (((D_803F2ED8 << 0xB) - (sp72 << 5)) * 0x2E) >> 6, (((D_803F2ED8 << 0xB) - (sp72 << 5)) * 0x2E) >> 6, (((D_803F2ED8 << 0xB) + (sp72 << 6)) * 0x2E) >> 6, D_803F2ED0, 0, 0, 0, D_040089E0_108730); }
            load_1_tile(D_04008C10, D_04008A10);
            func_802C78B0_6D8F60(1, 2, ((0x10000 - (sp72 << 5)) * 0x2E) >> 6, ((0x10000 - (sp72 << 5)) * 0x2E) >> 6, ((0x10000 + (sp72 << 6)) * 0x2E) >> 6, D_803F2ED0, 0, 0, 0, D_04008290);

            phi_t0 = D_803D552C->unk30E * 50;
            if ((D_803D5540 & 0x7F) < 8) {
                phi_t0 = MAX(phi_t0, (D_803D5540 & 0x7F) << 5);
            } else if ((D_803D5540 & 0x7F) < 16) {
                phi_t0 = 0x100;
            } else if ((D_803D5540 & 0x7F) < 24) {
                phi_t0 = MAX(phi_t0, 768 - ((D_803D5540 & 0x7F) << 5));
            }
            if ((D_803D552C->unk366 == 5) || (D_803D552C->unk366 == 2)) {
                phi_t0 = 0xFF;
            }
            D_80203FE0[1].unk4 += (phi_t0 * 0xB38) >> 0xC;
            D_80203FE0[2].unk4 += (phi_t0 * 0xB38) >> 0xC;
            if (phi_t0 < 256) {
                func_802C78B0_6D8F60(
                    1,
                    2,
                    ((D_803F2EC8 - (sp72 << 5)) * 0x2E) >> 6,
                    ((D_803F2EC8 - (sp72 << 5)) * 0x2E) >> 6,
                    ((((0x100 - phi_t0) * (D_803F2EC8 + (sp72 << 6))) >> 8) * 0x2E) >> 6,
                    D_803F2ED0,
                    0,
                    0,
                    0,
                    D_04008420);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp70 == 0) || (sp70 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, D_01033190, 0xF, 0xF, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp70 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 0x21A, 0);
        func_80303D50_715400(D_803D552C, 1);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x21A, 0x262);
    }
}

void func_80302D5C_71440C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_FROG_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void frog_croak(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_FROG_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}
