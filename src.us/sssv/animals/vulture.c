#include <ultra64.h>
#include "common.h"

extern Gfx D_01033190_6CA60[];
extern Gfx D_040000A0_E7650[];
extern Gfx D_040006F0_E7CA0[];

#if 0
// 99.9% there
// cannot "ifdef NON_MATCHING" as has rodata
void func_8036C0B0_77D760(void) {
    s32 sp94;
    s32 sp90;
    s32 pad2;
    s16 phi_v1;
    u8  tmp2;
    u8  tmp;
    s16 sp86;
    s16 sp84;
    s16 sp82;
    s16 tmp3;

    s16 pad[3];

    if (D_803D553A == 4) {
        play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0 - (MIN(256, D_803D552C->unk30E) * 0.0009765625));
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            tmp2 = 1;
        } else {
            tmp2 = 0;
        }

        if (tmp2) {
            sp82 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        tmp = 1;
    } else {
        tmp = 0;
    }
    sp82 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x800, 0, 20, 20, 20, 1, tmp == 0);

done:
    if (sp82 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4)) {
            if (SSSV_RAND(256) == 156) {
                play_sound_effect_at_location(SFX_BIRD_HURT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            }
        }
        if (D_803D5524->unk9C == VULTURE) {
            if ((D_803D552C->unk320 == 0) || ((D_803D552C->unk320 != 0) && (D_803D552C->unk320->unk26C != 0))) {
                play_sound_effect_at_location(SFX_BIRD_HURT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.1892f);
                D_803D552C->unk320 = 0;
                D_803D552C->yPos.h += D_803D552C->unk308;
                D_803D552C->unk18.h += D_803D552C->unk308;
                load_animal(VULTURE2);
            }
        }

        switch (D_803D552C->unk365) {
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        case ATTACK_VULTURE: // 1
            func_802DCCAC_6EE35C(16);
            D_803F2ECC = D_803F2ED8;
            D_803F2ECE = 3;
            break;
        case ATTACK_BITE: // 18
            if ((D_803D5544 - D_803D552C->unk32A) >= 9) {
                D_803D552C->unk365 = 0;
            }
            break;
        case ATTACK_NONE: // 0
            break;
        }

        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0xC8);
        if (D_803D5528->unk3C0.unk4 == 12) {
            sp94 = FTOFIX32(1.0) - ((D_803D5528->unk3C0.unk6 << 0x10) / 0x14);
        } else {
            sp94 = FTOFIX32(1.0);
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802BAD60_6CC410(250, 650);
            func_802C5F34_6D75E4(1200, 500, 1);
            func_802BB1F0_6CC8A0(900, 100);
            func_802BC1F4_6CD8A4(600);
            func_802C44E8_6D5B98(650, 200, 250, 250);
            func_8038CCF0_79E3A0(62, 19, 20, -1, -1, -1);
            func_8038CCF0_79E3A0(-125, 26, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B4930_7C5FE0, D_803B4944_7C5FF4, D_803B4958_7C6008, &D_803B497C_7C602C);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4930_7C5FE0, D_803B4944_7C5FF4, D_803B4958_7C6008, &D_803B49CC_7C607C);
                break;
            }
        }
        func_8038064C_791CFC();
        if (D_803D5524->unk9C == VULTURE) {
            D_80203FE0[0].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[1].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[2].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[19].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[20].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[26].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[22].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[24].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[3].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[4].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[7].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[8].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[9].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[13].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[10].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[11].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[12].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[14].unk4 += D_803D552C->unk308 << 5;
        }

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) && ((tmp2 = D_803D5538, (tmp2)) || ((tmp3 = D_803F2AA2, tmp3 == 0)) || (tmp3 == 2) || ((tmp3 == 1) && (D_803F2AA3 >= 11))) &&
            ((D_803F2C18[0] != 0) || (tmp2 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302,
                D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            if (D_803D5524->unk9C == VULTURE2) { // attacking?
                func_8038C230_79D8E0((D_803D5524->unkBA * 4) / 5, 2, 3, 3, 0.3f);
            } else {
                func_8038C230_79D8E0((D_803D5524->unkBA * 12) / 5, 2, 3, 3, 0.1f);
            }
            load_1_tile(D_04000D10, D_04000B10);

            gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);

            func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040009D0_E7F80);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0x7D, 0x33, 0xFF, 0xFF); // purple

            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000230_E77E0);
            // same line for regalloc
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 19, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04000370_E7920); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 26, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040004B0_E7A60); }
#pragma _permuter sameline end
            if (sp94 != 0) {
                func_802C78B0_6D8F60(0, 22, (sp94 << 6) >> 6, (sp94 << 6) >> 6, (sp94 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000600_E7BB0); // wing 1
                func_802C78B0_6D8F60(0, 24, (sp94 << 6) >> 6, (sp94 << 6) >> 6, (sp94 << 6) >> 6, D_803F2ED0, 0, 1, 0, D_04000600_E7BB0); // wing 2
            }
            if (D_803D5524->unk9C == VULTURE) {
                sp90 = FTOFIX32(2.0);
            } else {
                sp90 = FTOFIX32(1.0);
            }
            phi_v1 = 0;
            if (D_803D552C->unk365 == ATTACK_BITE) {
                switch (D_803D5544 - D_803D552C->unk32A) {
                case 1:
                case 5:
                    sp90 = FTOFIX32(2.0);
                    phi_v1 = 0x177;
                    break;
                case 2:
                case 4:
                    sp90 = FTOFIX32(2.5);
                    phi_v1 = 0x271;
                    break;
                case 3:
                    sp90 = FTOFIX32(3.0);
                    phi_v1 = 0x2EE;
                    break;
                }
            }

            D_80203FE0[3].unk4  -= phi_v1;
            D_80203FE0[7].unk4  -= phi_v1;
            D_80203FE0[8].unk4  -= phi_v1;
            D_80203FE0[9].unk4  -= phi_v1;
            D_80203FE0[13].unk4 -= phi_v1;
            D_80203FE0[4].unk4  -= phi_v1;
            D_80203FE0[10].unk4 -= phi_v1;
            D_80203FE0[11].unk4 -= phi_v1;
            D_80203FE0[12].unk4 -= phi_v1;
            D_80203FE0[14].unk4 -= phi_v1;

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0x00, 0xFF); // yellow

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 13, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040000A0_E7650); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040006F0_E7CA0); }
            func_802C78B0_6D8F60(3, 8, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040006F0_E7CA0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 9, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040006F0_E7CA0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 14, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040000A0_E7650); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040006F0_E7CA0); }
            func_802C78B0_6D8F60(4, 11, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040006F0_E7CA0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 12, (sp90 << 6) >> 6, (sp90 << 6) >> 6, (sp90 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040006F0_E7CA0); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp86, &sp84);
                func_8031A278_72B928(&D_803D552C->unk326, &sp86, &sp84);
#pragma _permuter sameline start
                // same line for regalloc
                sp86 = D_803BD54A_7CEBFA[sp86]; sp84 = D_803BD602_7CECB2[sp84];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000CC0, D_01000620, sp86);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000DB0);
                func_80356BD8_768288(D_01000CC0, D_01000620, sp84);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000DD0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if (D_803D552C->unk320 != NULL) {
        func_80321B70_733220(0, 0, 0);
        D_803D552C->unk320->unk68 = D_803D5530->unk68;
        D_803D552C->unk320->unk70 = D_803D5530;
    }
    func_8034BD20_75D3D0(
        D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1),
        D_803D552C->unk302, D_01033190_6CA60, 0x12, 0x12, 0x9B, 0, 0, 0, 0, D_803D5538);
    if (sp82 == 0) {
        func_80303820_714ED0(D_803D552C, 0, 1, 750, 1);
        func_80303820_714ED0(D_803D552C, 1, 19, 0x177, 0);
        if (D_803D552C->unk320 != 0) {
            func_80303C44_7152F4(D_803D552C, 2, 0, -D_803D552C->unk308 / 64);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_80303D50_715400(D_803D552C, 2);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 750, 0);
    }
    if (D_803D5524->unk9C == VULTURE) {
        if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
            load_animal(VULTURE2);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/vulture/func_8036C0B0_77D760.s")
#endif

void func_8036D30C_77E9BC(void) {
    if (D_803D552C->unk320 == NULL) {
        D_803D552C->unk320 = func_803213B0_732A60();
        if (D_803D552C->unk320 != NULL) {
            D_803D552C->unk308 = D_803D552C->unk320->unk42;
            load_animal(VULTURE);
            D_803D552C->yPos.h -= D_803D552C->unk308;
            if (D_803D5530->unk160 == 2) {
                D_803D552C->yPos.h = MAX(D_803D552C->yPos.h, func_80310F58_722608(D_803D552C->xPos.h, D_803D552C->zPos.h) >> 16);
            } else {
                D_803D552C->yPos.h = MAX(D_803D552C->yPos.h, func_8031124C_7228FC(D_803D552C->xPos.h, D_803D552C->zPos.h) >> 16);
            }
        } else if (D_803D5530->unk162 == 2) {
            if (D_803D5528->skillBEnergy[0] > 400) {
                D_803D5528->skillBEnergy[0] -= 400;
                if (func_803224C4_733B74(-62, 0, 0, 15, 20, 0, 0, 19) != 0) {
                    play_sound_effect_at_location(SFX_BIRD_CLAW_ATTACK, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    D_803D5530->yVelocity.h += 2;
                } else {
                    play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                }
                if (D_803D552C->unk365 == ATTACK_NONE) {
                    D_803D552C->unk365 = ATTACK_BITE;
                    D_803D552C->unk32A = D_803D5544;
                }
            }
        }
    } else {
        play_sound_effect_at_location(SFX_BIRD_HURT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803BEF90);
        func_80321920_732FD0(D_803D552C->unk320, 0, 0);
        D_803D552C->yPos.h += D_803D552C->unk308;
        D_803D552C->unk18.h += D_803D552C->unk308;
        load_animal(VULTURE2);
    }
}

void func_8036D5CC_77EC7C(void) {
    // check object is an animal?
    if ((D_803D5530->unk162 == 2) || ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET))) {
        if (func_803224C4_733B74(-62, 0, 0, 46, 20, 0, 0, 19) != 0) {
            play_sound_effect_at_location(SFX_BIRD_CLAW_ATTACK, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            D_803D5530->yVelocity.h += 2;
        } else {
            play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
        if (D_803D552C->unk365 == ATTACK_NONE) {
            D_803D552C->unk365 = ATTACK_BITE;
            D_803D552C->unk32A = D_803D5544;
        }
    }
}
