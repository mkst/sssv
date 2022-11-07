#include <ultra64.h>
#include "common.h"


void func_80382050_793700(void) {
    s32 phi_a2;
    s32 phi_a3;
    s32 phi_a4;

    s16 sp7A;
    s16 sp78; // pad
    s16 sp76;
    s16 sp74;
    s16 sp72;
    s16 sp70; // pad
    s16 sp6E; // pad

    if (D_803D553A == 8) {
        play_sound_effect_at_location(SFX_UNKNOWN_9, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
    }
    if (D_803D553A == 9) {
        play_sound_effect_at_location(SFX_UNKNOWN_10, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
    }
    if ((D_803D5530->unk162 == 3) && (D_803D5538 != 0)) {
        if (D_803D552C->unk369 == 0) {
            if (D_801E9E8E == 0) {
                D_803D552C->unk369 = 1;
            }
        } else if ((D_803D552C->unk369 == 1) && (D_801E9E8E != 0) && (D_803D5530->yVelocity.h < 5)) {
            D_803D552C->unk369 = 2U;
            D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 0x13;
            D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * 0x13;
            D_803D5530->yVelocity.h = MAX(7, D_803D5530->yVelocity.h + 4);

            D_803D552C->unk308 = MAX(0, D_803D552C->unk308 - 25);
            play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            phi_a4 = 1;
        } else {
            phi_a4 = 0;
        }
        if (phi_a4 != 0) {
            sp7A = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        phi_a2 = 1;
    } else {
        phi_a2 = 0;
    }
    sp7A = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        (0, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF)),
        0x800,
        0,
        62,
        62,
        124,
        1,
        phi_a2 == 0);

done:
    if (sp7A == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_80302E50_714500(10, 1000, 500);
            if (D_803D5530->state == 0x3F) {
                if (phi_a2 = (D_803D552C->unk308++) > 40) {
                    phi_a4 = 40;
                } else {
                    phi_a4 = D_803D552C->unk308++;
                }

                sp6E = (40 - (phi_a4 * 2));
                func_8030322C_7148DC(0, -sp6E);
                func_8030322C_7148DC(1, -sp6E);
                func_8030322C_7148DC(2, -sp6E);
                func_8030322C_7148DC(3, -sp6E);
            }
        }

        sp76 = ((D_80152C78[(s16)(D_803D5540 << 4) & 0xFF] >> 7) + 256) >> 6;
        if (D_803D552C->unk365 == ATTACK_BITE) {
            sp76 = ((D_80152C78[(s16)(D_803D5540 << 5) & 0xFF] >> 7) + 256) >> 3;
            if ((D_803D5540 & 7) == 0) {
                if (func_803224C4_733B74(0, 0x1F, 0, 0x1F, 6, 0, 0, 0xD)) {
                    play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                } else {
                    play_sound_effect_at_location(SFX_UNKNOWN_6, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
            }
        } else {
            D_803D552C->unk365 = ATTACK_NONE;
        }

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B5860_7C6F10, D_803B5864_7C6F14, D_803B5868_7C6F18, D_803B5870_7C6F20);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B5860_7C6F10, D_803B5864_7C6F14, D_803B5868_7C6F18, D_803B5884_7C6F34);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
             (D_803F2EDA != 0) &&
             ((D_803D5538 != 0) || (D_803F2AA2 == 0) || ((phi_a3 = D_803F2AA2) == 2) || ((phi_a3 == 1) && (D_803F2AA3 >= 0xB))) &&
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

            load_2_tiles(D_0400C480, D_0400C6A0, D_0400C280);

            D_80203FE0[1].unk4 += ((sp76 * 1000) >> 9) + ((sp76 * 1000) >> 12);
            D_80203FE0[2].unk4 -= ((sp76 * 3000) >> 11) + ((sp76 * 1000) >> 12);

            func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_0400BD00_FCD60); // lower jaw?
            D_80203FE0[1].unk4 -= ((sp76 * 1000) >> 9) + ((sp76 * 1000) >> 12);
            D_80203FE0[2].unk4 += ((sp76 * 3000) >> 11) + ((sp76 * 1000) >> 12);

            D_80203FE0[1].unk4 -= ((sp76 * 1000) >> 6) + ((sp76 * 1000) >> 8);
            D_80203FE0[2].unk4 += ((sp76 * 3000) >> 8) + ((sp76 * 1000) >> 8);

            D_80203FE0[1].unk2 += ((sp76 * 1000) >> 8);
            D_80203FE0[2].unk2 += ((sp76 * 1000) >> 8);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_0400C010_FD070); }
            D_80203FE0[1].unk4 += ((sp76 * 1000) >> 6) + ((sp76 * 1000) >> 8);
            D_80203FE0[2].unk4 -= ((sp76 * 3000) >> 8) + ((sp76 * 1000) >> 8);

            D_80203FE0[1].unk2 -= ((sp76 * 1000) >> 8);
            D_80203FE0[2].unk2 -= ((sp76 * 1000) >> 8);

            load_1_tile(D_0400C8C0, D_0400C6C0);
            func_802C78B0_6D8F60(2, 3, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_0400C170_FD1D0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp74, &sp72);
                func_8031A278_72B928(&D_803D552C->unk326, &sp74, &sp72);
                sp74 = D_803BD54A_7CEBFA[sp74]; sp72 = D_803BD602_7CECB2[sp72];
                func_80356BD8_768288(D_01000CC0, D_01000620, sp74);
                func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_0400C240_FD2A0);
                func_80356BD8_768288(D_01000CC0, D_01000620, sp72);
                func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_0400C260_FD2C0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp7A == 0) || (sp7A == 2)) {
        func_8034BD20_75D3D0(
            D_803D552C->xPos.h,
            D_803D552C->zPos.h,
            D_803D552C->yPos.h + ((D_803D5524->unkBA * 3) >> 2),
            D_803D552C->unk302,
            D_01033190,
            28,
            9,
            155,
            0,
            0,
            0,
            0,
            D_803D5538);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk365 == ATTACK_BITE) {
            if (D_803D552C->unk2EC > 0) {
                D_803D552C->unk2EC--;
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
        }
    }
    func_80303D00_7153B0(D_803D552C, 625, 625);
}

void func_80382C9C_79434C(void) {
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_80382CB0_794360(void) {
    D_803D552C->unk365 = ATTACK_NONE;
}

void func_80382CC0_794370(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_80382CE4_794394(void) {
}
