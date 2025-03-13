#include <ultra64.h>
#include "common.h"


extern s16 D_803B3D50_7C5400[];
extern s16 D_803B3D80_7C5430[];
extern s16 D_803B3DB0_7C5460[];
extern s16 D_803B3DC4_7C5474[];
extern s16 D_803B3DDC_7C548C[];
extern s16 D_803B3DF4_7C54A4[];
extern s16 D_803B3E24_7C54D4[];
extern s16 D_803B3E88_7C5538[];
extern s16 D_803B3EEC_7C559C[];

extern Gfx D_01003588_3CE58[];
extern Gfx D_01004E60_3E730[];
extern Gfx D_01004E80_3E750[];
extern Gfx D_01004CC0_3E590[];
extern Gfx D_01004D90_3E660[];


// EVO_MICROCHIP
// ESA: func_8001D3D4
void update_evo_microchip(void) {
    s32 pad[3];
    u8 tmp;

    struct061 spA0;
    s16 sp9E;
    s16 sp9C;
    s16 sp9A;
    u16 ticks_remaining;
    s32 var_v1;

    if ((D_803D5524->unk9C == EVO_MICROCHIP) && ((D_803D5540 & 0xF) == 0) && (D_803F2D10.unk0 == 0)) {
        if ((D_803D5530->unk4C.unk1A == 0) && (D_803D5530->unk4A == 0)) {
            D_803D5530->health = MAX(0, D_803D5530->health - 1);
        }
        if (SSSV_RAND(4)) {
            func_80349280_75A930(D_803D5530, 4);
        } else {
            create_sparks(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0xA, GPACK_RGBA5551(224, 224, 128, 1));
        }
    }

    if ((D_803D552C->unk366 == MOVEMENT_MODE_2) || (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED)) {
        if (D_803D5524->unk9C != EVO_MICROCHIP) {
            load_animal(EVO_MICROCHIP);
        }
        D_803D552C->unk365 = ATTACK_NONE;
    }

    switch (D_803D552C->unk365) {
    case ATTACK_EVO_CHIP_2:
        D_803D5530->unk162 = 3;

        ticks_remaining = D_803D5544 - D_803D552C->unk32A;

        D_803D552C->position.xPos.w = (D_803D552C->unk308 << 0x10) + (((D_803D552C->unk320->position.xPos.w - (D_803D552C->unk308 << 0x10)) / 40) * ticks_remaining);
        D_803D552C->position.zPos.w = (D_803D552C->unk30A << 0x10) + (((D_803D552C->unk320->position.zPos.w - (D_803D552C->unk30A << 0x10)) / 40) * ticks_remaining);
        // fixme
        D_803D552C->position.yPos.w = (((D_803B3EEC_7C559C[ticks_remaining] << 0x10) >> 3) + (D_803D552C->unk30C << 0x10)) + ((((D_803D552C->unk320->position.yPos.w + ((D_801D9ED8.animals + D_803D552C->unk30E)->unk0->unkBA << 0xF)) - (D_803D552C->unk30C << 0x10)) / 40) * ticks_remaining);

        if (D_803F2D10.unk0 == 0) {
          D_803D552C->heading = (D_803D552C->heading + 5) & 0xFF;
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
            D_803D552C->heading = (D_803D552C->heading + 5) & 0xFF;
            D_803D552C->yRotation = (D_803D552C->yRotation + 5) & 0xFF;
        }

        if (ticks_remaining >= 20) {
            D_803D5520->unk0 = &D_801D9ED8.unk0[EVO_MICROCHIP];
            D_803D5530->unk16C = &D_801D9ED8.unk0[EVO_MICROCHIP];
            gCurrentAnimalId = EVO_MICROCHIP;
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
        sp9A = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x4B0, 5, 0x99, 0, 0, 1, 0);
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
            backup_joint_positions();
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

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (tmp = D_803F2AA2, (tmp == 0)) || (tmp == 2) || ((tmp == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            add_hilite();
            gSPDisplayList(D_801D9E88++, D_01003588_3CE58);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);

            SET_JOINT(1, 2, SCALE_EVO_MICROCHIP, D_803F2EBC, D_803F2EC0, D_803F2EC4, D_803F2ED0, 0, 0, 0, D_01004D90_3E660);
            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

            SET_JOINT(3,  7,  SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);
            SET_JOINT(8,  9,  SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);
            SET_JOINT(14, 15, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);
            SET_JOINT(5,  13, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 1, D_01004CC0_3E590);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            SET_JOINT(4,  10, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);
            SET_JOINT(11, 12, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);
            SET_JOINT(17, 18, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);
            SET_JOINT(6,  16, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 2, 1, D_01004CC0_3E590);

            func_8031A150_72B800(D_803D552C->unk326++, &sp9E, &sp9C);
            func_8031A278_72B928(&D_803D552C->unk326, &sp9E, &sp9C);
            sp9E = D_803BD530_7CEBE0.eyes[3][sp9E]; sp9C = D_803BD600_7CECB0.eyes[2][sp9C];
            func_80356BD8_768288(img_eyes_TLUT2_pal, img_eyes_ci4__png, sp9E);
            SET_JOINT(1,   2, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_01004E60_3E730);
            func_80356BD8_768288(img_eyes_TLUT2_pal, img_eyes_ci4__png, sp9C);
            SET_JOINT(1,   2, SCALE_EVO_MICROCHIP, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_01004E80_3E750);

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp9A == 0) || (sp9A == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + ((D_803D5524->unkBA * 3) >> 1)), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 9, 6, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp9A == 0) {
        func_803034D0_714B80(D_803D552C, 0x138, 0, 0);
        D_803D5530->unkC4[0].pos.yPos.h += 3; // 0xcc
        D_803D5530->unkC4[1].pos.yPos.h += 3; // 0xdc
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x138, 0x9C);
    }
}
