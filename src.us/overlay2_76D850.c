#include <ultra64.h>
#include "common.h"

const s16 D_803BEB70_7D0220[16] = {
    0, 7, 12, 14, 16, 14, 12, 10,
    8, 6,  5,  4,  3,  2,  2,  1,
};
const s16 D_803BEB90_7D0240[16] = {
     0, -5, -7, -8, -8, -7, -7, -6,
    -5, -5, -4, -4, -3, -3, -2, -2,
};


extern s16 D_803B3D50_7C5400[];
extern s16 D_803B3D80_7C5430[];
extern s16 D_803B3DB0_7C5460[];
extern s16 D_803B3DC4_7C5474[];
extern s16 D_803B3DDC_7C548C[];
extern s16 D_803B3DF4_7C54A4[];
extern s16 D_803B3E24_7C54D4[];
extern s16 D_803B3E88_7C5538[];
extern s16 D_803B3EEC_7C559C[];
extern s16 D_803BD57E_7CEC2E[];
extern s16 D_803BD636_7CECE6[];

extern Gfx D_01003548[];
extern Gfx D_01003588_3CE58[];
extern Gfx D_01004E60_3E730[];
extern Gfx D_01004E80_3E750[];
extern Gfx D_01004CC0_3E590[];
extern Gfx D_01004D90_3E660[];

extern struct035 *D_801DD714;
extern s32 D_801DDD8C;


// evo chip?
void func_8035C1A0_76D850(void) {
    s32 pad[3];
    u8 tmp;

    struct061 spA0;
    s16 sp9E;
    s16 sp9C;
    s16 sp9A;
    u16 ticks_remaining;
    s32 var_v1;

    if ((D_803D5524->unk9C == EVO_MICROCHIP) && ((D_803D5540 & 0xF) == 0) && (D_803F2D10.unk0 == 0)) {
        if ((D_803D5530->unk4C.unk26 == 0) && (D_803D5530->unk4A == 0)) {
            D_803D5530->health = MAX(0, D_803D5530->health - 1);
        }
        if (SSSV_RAND(4)) {
            func_80349280_75A930(D_803D5530, 4);
        } else {
            func_802D9C64_6EB314(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 0xA, GPACK_RGBA5551(224, 224, 128, 1));
        }
    }

    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        if (D_803D5524->unk9C != EVO_MICROCHIP) {
            load_animal(EVO_MICROCHIP);
        }
        D_803D552C->unk365 = ATTACK_NONE;
    }

    switch (D_803D552C->unk365) {
    case ATTACK_EVO_CHIP_2:
        D_803D5530->unk162 = 3;

        ticks_remaining = D_803D5544 - D_803D552C->unk32A;

        D_803D552C->xPos.w = (D_803D552C->unk308 << 0x10) + (((D_803D552C->unk320->xPos.w - (D_803D552C->unk308 << 0x10)) / 40) * ticks_remaining);
        D_803D552C->zPos.w = (D_803D552C->unk30A << 0x10) + (((D_803D552C->unk320->zPos.w - (D_803D552C->unk30A << 0x10)) / 40) * ticks_remaining);
        // fixme
        D_803D552C->yPos.w = (((D_803B3EEC_7C559C[ticks_remaining] << 0x10) >> 3) + (D_803D552C->unk30C << 0x10)) + ((((D_803D552C->unk320->yPos.w + ((D_801D9ED8.animals + D_803D552C->unk30E)->unk0->unkBA << 0xF)) - (D_803D552C->unk30C << 0x10)) / 40) * ticks_remaining);

        if (D_803F2D10.unk0 == 0) {
          D_803D552C->unk302 = (D_803D552C->unk302 + 5) & 0xFF;
          D_803D552C->yRotation = (D_803D552C->yRotation + 5) & 0xFF;
        }

        D_803D552C->xVelocity.w = 0;
        D_803D552C->zVelocity.w = 0;
        D_803D552C->yVelocity.w = 0;

        func_803136B0_724D60(D_803D5530);
        if (ticks_remaining >= 40) {
          D_803D552C->unk365 = ATTACK_NONE;
          func_8032A710_73BDC0();
          return;
        }
        break;

    case ATTACK_EVO_CHIP_1:

        D_803D5530->unk162 = 3;

        ticks_remaining = D_803D5544 - D_803D552C->unk32A;

        D_803D552C->xVelocity.w = D_803D552C->unk308 << 8;
        D_803D552C->zVelocity.w = D_803D552C->unk30A << 8;

        D_803D552C->yVelocity.w = ((D_803B3EEC_7C559C[ticks_remaining]) - (D_803B3EEC_7C559C[MAX(0, ticks_remaining - 1)])) << 0xE;
        if (D_803F2D10.unk0 == 0) {
            D_803D552C->unk302 = (D_803D552C->unk302 + 5) & 0xFF;
            D_803D552C->yRotation = (D_803D552C->yRotation + 5) & 0xFF;
        }

        if (ticks_remaining >= 20) {
            D_803D5520->unk0 = &D_801DD714;
            D_803D5530->unk16C = &D_801DD714;
            D_803E9824 = EVO_MICROCHIP;
            D_803E9820 = 27;
            D_803E9822 = 0;
            func_80327DA8_739458();
            func_802C9BA4_6DB254((struct071*)D_801D9ED8.animals[0].animal);
            D_803D552C->unk365 = ATTACK_NONE;
        }
        break;
    default:
        break;
    }

    if (D_803D5538 != 0) {
        sp9A = 0;
        D_803F2EDD = 0;
    } else {
        sp9A = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x4B0, 5, 0x99, 0, 0, 1, 0);
    }

    if (sp9A == 0) {
        func_8035D120_76E7D0();
        func_8035DA60_76F110();

        D_803F2EBC = 0x10000;
        D_803F2EC0 = 0x10000;
        D_803F2EC4 = 0x10000;

        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B9130_6CA7E0(&spA0, 0x9C, 0x57, 0x9C, 0x27);

            D_80203FE0[8].unk0 = D_80203FE0[3].unk0 + ((D_80203FE0[5].unk0 - D_80203FE0[3].unk0) / 3);
            D_80203FE0[8].unk2 = D_80203FE0[3].unk2 + ((D_80203FE0[5].unk2 - D_80203FE0[3].unk2) / 3);
            D_80203FE0[8].unk4 = D_80203FE0[3].unk4 + ((D_80203FE0[5].unk4 - D_80203FE0[3].unk4) / 3);

            D_80203FE0[14].unk0 = D_80203FE0[3].unk0 + (((D_80203FE0[5].unk0 - D_80203FE0[3].unk0) * 2) / 3);
            D_80203FE0[14].unk2 = D_80203FE0[3].unk2 + (((D_80203FE0[5].unk2 - D_80203FE0[3].unk2) * 2) / 3);
            D_80203FE0[14].unk4 = D_80203FE0[3].unk4 + (((D_80203FE0[5].unk4 - D_80203FE0[3].unk4) * 2) / 3);

            D_80203FE0[11].unk0 = D_80203FE0[4].unk0 + ((D_80203FE0[6].unk0 - D_80203FE0[4].unk0) / 3);
            D_80203FE0[11].unk2 = D_80203FE0[4].unk2 + ((D_80203FE0[6].unk2 - D_80203FE0[4].unk2) / 3);
            D_80203FE0[11].unk4 = D_80203FE0[4].unk4 + ((D_80203FE0[6].unk4 - D_80203FE0[4].unk4) / 3);

            D_80203FE0[17].unk0 = D_80203FE0[4].unk0 + (((D_80203FE0[6].unk0 - D_80203FE0[4].unk0) * 2) / 3);
            D_80203FE0[17].unk2 = D_80203FE0[4].unk2 + (((D_80203FE0[6].unk2 - D_80203FE0[4].unk2) * 2) / 3);
            D_80203FE0[17].unk4 = D_80203FE0[4].unk4 + (((D_80203FE0[6].unk4 - D_80203FE0[4].unk4) * 2) / 3);

            func_802C0364_6D1A14(0x9C, 0x27, 0, 0, 0, 0, D_803B3D50_7C5400, D_803B3D80_7C5430, D_803B3DB0_7C5460, 0x9C, 0x27, 0xC0, 0xC0, 0xC0, 0xC0, D_803B3D50_7C5400, D_803B3D80_7C5430, D_803B3DB0_7C5460, &spA0);
            func_802B964C_6CACFC();
        }

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B3DC4_7C5474, D_803B3DDC_7C548C, D_803B3DF4_7C54A4, D_803B3E24_7C54D4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B3DC4_7C5474, D_803B3DDC_7C548C, D_803B3DF4_7C54A4, D_803B3E88_7C5538);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (tmp = D_803F2AA2, (tmp == 0)) || (tmp == 2) || ((tmp == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8034A320_75B9D0();
            gSPDisplayList(D_801D9E88++, D_01003588_3CE58);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);

            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x19) >> 6, (D_803F2EC0 * 0x19) >> 6, (D_803F2EC4 * 0x19) >> 6, D_803F2ED0, 0, 0, 0, D_01004D90_3E660);
            gSPDisplayList(D_801D9E88++, D_01003548);

            func_802C78B0_6D8F60(3,  7,  0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);
            func_802C78B0_6D8F60(8,  9,  0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);
            func_802C78B0_6D8F60(14, 15, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);
            func_802C78B0_6D8F60(5,  13, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(4,  10, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);
            func_802C78B0_6D8F60(11, 12, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);
            func_802C78B0_6D8F60(17, 18, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);
            func_802C78B0_6D8F60(6,  16, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);

            func_8031A150_72B800(D_803D552C->unk326++, &sp9E, &sp9C);
            func_8031A278_72B928(&D_803D552C->unk326, &sp9E, &sp9C);
            sp9E = D_803BD57E_7CEC2E[sp9E]; sp9C = D_803BD636_7CECE6[sp9C];
            func_80356BD8_768288(D_01000CC0, D_01000620, sp9E);
            func_802C78B0_6D8F60(1, 2, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 0, 0, D_01004E60_3E730);
            func_80356BD8_768288(D_01000CC0, D_01000620, sp9C);
            func_802C78B0_6D8F60(1, 2, 0x6400, 0x6400, 0x6400, D_803F2ED0, 0, 0, 0, D_01004E80_3E750);

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp9A == 0) || (sp9A == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (D_803D552C->yPos.h + ((D_803D5524->unkBA * 3) >> 1)), D_803D552C->unk302, &D_01033190, 9, 6, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp9A == 0) {
        func_803034D0_714B80(D_803D552C, 0x138, 0, 0);
        D_803D5530->unkC0.a.unkC0[0][6] += 3;
        D_803D5530->unkC0.b.unkDC += 3;
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x138, 0x9C);
    }
}

// score: 5255
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035D120_76E7D0.s")
// void func_8035D120_76E7D0(void) {
//     s16 idx;
//
//     if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
//         D_803D552C->unk365 = ATTACK_NONE;
//     }
//
//     D_803F2ED8 = D_803F2ED0 = D_803F2ECC = 0;
//     D_803F2EC4 = D_803F2EC8 = D_803F2EBC = D_803F2EC0 = FTOFIX32(1.0);
//
//     D_803F2EB8 = FTOFIX32(1.0) - (D_803D5530->unk4B * FTOFIX32(0.01171875));
//     D_803F2EB0 = D_803F2EB4 = FTOFIX32(1.0) + (D_803D5530->unk4B * FTOFIX32(0.015625));
//
//     if ((D_803A6CE4_7B8394 & 8)) {
//         D_803F2EC8 = FTOFIX32(3.0);
//         D_803F2EB0 /= 3;
//         D_803F2EB4 /= 3;
//         D_803F2EB8 /= 3;
//     }
//
//     D_803F2EDA = D_803F2EDB = 1;
//     D_803F2EDE = D_803F2EDC = 0;
//
//     switch (D_803D552C->unk360) {
//     case 0:
//         break;
//     case 1:
//         D_803F2EB8 = (D_803F2EB8 * 8) >> 4;
//         break;
//     case 2:
//         D_803F2EB8 = (D_803F2EB8 * 11) >> 4;
//         break;
//     case 3:
//         D_803F2EB8 = (D_803F2EB8 * 14) >> 4;
//         break;
//     }
//
//     if (D_803D552C->unk36D != 0) {
//         idx = (D_803D552C->unk36D << 4) / (s8)D_803D5524->unkE9;
//         D_803F2EB0 = ((((D_803BEB90_7D0240[idx] * (s8)D_803D5524->unkEA) >> 4) + 0x10) * D_803F2EB0) >> 4;
//         D_803F2EB4 = ((((D_803BEB90_7D0240[idx] * (s8)D_803D5524->unkEA) >> 4) + 0x10) * D_803F2EB4) >> 4;
//         if ((D_803D5530->unk70 == NULL) || ((D_803D5530->unk42 * 2) < (D_803D5530->unk70->yPos.h - D_803D5530->yPos.h))) {
//             D_803F2EB8 = ((((D_803BEB70_7D0220[idx] * (s8)D_803D5524->unkEA) >> 4) + 0x10) * D_803F2EB8) >> 4;
//         }
//         if (++D_803D552C->unk36D >= (s8)D_803D5524->unkE9) {
//             D_803D552C->unk36D = 0U;
//         }
//     }
//     switch (D_803D552C->unk364) {
//     case 0:
//     case 4:
//         if ((D_803D5544 - D_803D552C->unk334) > 9) {
//             D_803D552C->unk364 = 0U;
//         }
//         break;
//     case 8:
//         func_802DBCDC_6ED38C(0x18);
//         break;
//     case 9:
//         func_802DBED8_6ED588(0x18);
//         break;
//     case 15:
//         func_802DC0D4_6ED784(0x10);
//         break;
//     case 6:
//         func_802DC2AC_6ED95C(0xA);
//         break;
//     case 7:
//         func_802DD004_6EE6B4(0x10);
//         break;
//     case 13:
//         func_802DBB80_6ED230(0xE);
//         func_802DC968_6EE018(16, 1);
//         D_803F2ECE = 2;
//         break;
//     case 14:
//         func_802DBB80_6ED230(0x14);
//         func_802DC968_6EE018(32, 3);
//         D_803F2ECE = 2;
//         break;
//     case 16:
//         func_802DCD70_6EE420(300, 0);
//         break;
//     case 17:
//         func_802DCD70_6EE420(300, 1);
//         break;
//     default:
//         D_803D552C->unk364 = 0U;
//         break;
//     }
//
//     if (D_803D552C->unk348 != 0) {
//         if (D_803D552C->unk34A != 0) {
//             D_803D552C->unk34A -= 1;
//         } else {
//             D_803D552C->unk348 -= 1;
//         }
//     }
//     if ((D_803D5540 & 2) && (D_803D552C->unk36B > 0)) {
//         D_803F2EDC = 1;
//         if (D_803D552C->unk36B < 3) {
//             set_fog_factor_and_color(&D_801D9E88, 160, 160, 160);
//         } else {
//             set_fog_factor_and_color(&D_801D9E88, 200, 200, 200);
//         }
//         D_803D552C->unk36B = MAX(0, D_803D552C->unk36B - 2);
//     }
// }

void func_8035D6A0_76ED50(void) {
    if (D_803F2EDC != 0) {
        set_fog_position_and_color(&D_801D9E88);
    }
}

void func_8035D6D0_76ED80(void) {
    if (D_803D552C->unk348 != 0) {
        if (D_803D552C->unk34A != 0) {
            D_803D552C->unk34A -= 1;
        } else {
            D_803D552C->unk348 -= 1;
        }
    }
    if ((D_803D552C->unk36B - 1) < 0) {
        D_803D552C->unk36B = 0;
    } else {
        D_803D552C->unk36B -= 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035D734_76EDE4.s")
// miles away
// void func_8035D734_76EDE4(void) {
//     s32 temp_v0_3;
//
//     if (D_803D552C->unk366 == 5) {
//         if ((s8)D_803D552C->unk36A == 1) {
//             D_803F2ECC = MIN((D_803D5544 - D_803D552C->unk328) & 0xffff, 32);
//             if (D_803F2ECC >= 32) {
//                 D_803D552C->unk36A = 0;
//             }
//         } else {
//             D_803F2ECC = 32;
//             D_803D552C->unk369 = 0;
//             D_803D552C->unk365 = ATTACK_NONE;
//         }
//         D_803F2ECE = 1;
//         if ((D_803F2D10.unk0 == 0) && (SSSV_RAND(64) == 0)) {
//             func_802D9C64_6EB314(
//                 D_803D5530->xPos.h,
//                 D_803D5530->zPos.h,
//                 D_803D5530->yPos.h,
//                 D_803D5530->unk30,
//                 GPACK_RGBA5551(248, 248, 0, 1));
//         }
//     }
//     if ((D_803D5538 != 0) && ((s8)D_803D552C->unk36A == 1) && (D_803F2D30.unk4 > 17)) {
//         D_803F2ECC = MIN(((D_803F2D30.unk4 - 16) >> 1), 32);
//         D_803F2ECE = 1;
//     }
//     if ((s8)D_803D552C->unk36A == 2) {
//         temp_v0_3 = D_803D5544 - D_803D552C->unk328;
//         if ((temp_v0_3 >= 0) && (temp_v0_3 < 24)) {
//             D_803F2ECC = (32 - (temp_v0_3 << 2) & 0xffff);
//             if ((D_803F2ECC > 0) && (D_803F2ECC < 33)) {
//                 D_803F2ECE = 1;
//             } else {
//                 D_803F2ECC = 0;
//             }
//             func_802DC854_6EDF04(temp_v0_3, 24);
//         } else {
//             D_803D552C->unk36A = 0;
//         }
//     }
//     if ((D_803D552C->unk366 == 4) || ((D_803D5538 != 0) && (D_803D5530->health < 15))) {
//         D_803F2ED2 = (D_803D5540 * 3) & 0xFF;
//         D_803F2ED4 = ((D_80152C78[D_803D5540 & 0xFF] >> 7) * 80) / 4;
//     } else if (D_803D552C->unk348 != 0) {
//         D_803F2ED2 = (D_803D5540 * 3) & 0xFF;
//         D_803F2ED4 = ((D_80152C78[D_803D5540 & 0xFF] >> 7) * D_803D552C->unk348);
//         D_803F2ED4 /= 20;
//     } else {
//         D_803F2ED4 = 0;
//         D_803F2ED2 = 0;
//     }
// }

void func_8035DA60_76F110(void) {
    if (D_803D552C->unk366 == 4) {
        D_803F2EBC += D_80152C78[(s16)((D_803D552C->unk2EE % 16) << 4) & 0xFF] >> 1;
        D_803F2EC0 += D_80152C78[(s16)((D_803D552C->unk2EE % 16) << 4) & 0xFF] >> 1;
        D_803F2EC4 += D_80152C78[(s16)((D_803D552C->unk2EE % 16) << 4) & 0xFF] >> 1;
        if (D_803F2D10.unk0 == 0) {
            if ((D_803D552C->unk2EE % 16) == 8) {
                D_803F2EDE = 1;
            }
            D_803D552C->unk2EE++;
        }
    } else if (D_803D552C->unk366 != 5) {
        if (D_803D552C->unk2EE <= 192) {
            D_803F2EBC += D_80152C78[(s16)((D_803D552C->unk2EE % 32) << 3) & 0xFF] >> 2;
            D_803F2EC0 += D_80152C78[(s16)((D_803D552C->unk2EE % 32) << 3) & 0xFF] >> 2;
            D_803F2EC4 += D_80152C78[(s16)((D_803D552C->unk2EE % 32) << 3) & 0xFF] >> 2;
            if (D_803F2D10.unk0 == 0) {
                if ((D_803D552C->unk2EE % 32) == 16) {
                    D_803F2EDE = 1;
                }
                D_803D552C->unk2EE++;
            }
        } else {
            D_803F2EBC += D_80152C78[(s16)((D_803D552C->unk2EE % 64) << 2) & 0xFF] >> 3;
            D_803F2EC0 += D_80152C78[(s16)((D_803D552C->unk2EE % 64) << 2) & 0xFF] >> 3;
            D_803F2EC4 += D_80152C78[(s16)((D_803D552C->unk2EE % 64) << 2) & 0xFF] >> 3;
            if (D_803F2D10.unk0 == 0) {
                if ((D_803D552C->unk2EE % 64) == 32) {
                    D_803F2EDE = 1;
                }
                D_803D552C->unk2EE++;
            }
        }
        if (D_803D5530->state == 23) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 4) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 42) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 105) {
            D_803D552C->unk2EE %= 64;
        }
    }
}

#ifdef NON_MATCHING
// CURRENT (40)
void func_8035DEC4_76F574(void) {
    if (D_803D552C->unk366 != 5) {
        if (D_803D552C->unk2EE < 385) {
            D_803F2EBC += D_80152C78[((s16)(D_803D552C->unk2EE << 4) & 0xff) & 0xff] >> 2;
            D_803F2EC0 += D_80152C78[((s16)(D_803D552C->unk2EE << 4) & 0xff) & 0xff] >> 2;
            D_803F2EC4 += D_80152C78[((s16)(D_803D552C->unk2EE << 4) & 0xff) & 0xff] >> 2;
        } else {
            D_803F2EBC += D_80152C78[((s16)(D_803D552C->unk2EE << 3) & 0xff) & 0xff] >> 2;
            D_803F2EC0 += D_80152C78[((s16)(D_803D552C->unk2EE << 3) & 0xff) & 0xff] >> 2;
            D_803F2EC4 += D_80152C78[((s16)(D_803D552C->unk2EE << 3) & 0xff) & 0xff] >> 2;
        }
        if (D_803F2D10.unk0 == 0) {
            D_803D552C->unk2EE += 1;
        }
        if (D_803D5530->state == 23) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 4) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 42) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 105) {
            D_803D552C->unk2EE %= 64;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035DEC4_76F574.s")
#endif
