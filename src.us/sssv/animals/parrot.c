#include <ultra64.h>
#include "common.h"

#include "parrot.h"

extern Gfx D_04001250_F22B0[];
extern Gfx D_040015D0_F2630[];
extern Gfx D_040016F0_F2750[];
extern Gfx D_04001760_E8D10[];
extern Gfx D_040019E0_F2A40[];
extern Gfx D_04001AC0_F2B20[];
extern Gfx D_04001B30_F2B90[];
extern Gfx D_04001C10_F2C70[];
extern Gfx D_040020C0_F3120[];
extern Gfx dog_missile_pod[];

extern Gfx D_01003618_3CEE8[];

void func_80313790_724E40(void) {
    s32 scale;
    u8 temp_v0_8;
    u8 temp_a0_2;
    s32 pad;
    s16 sp62;

    if (D_803D553A == 4) {
        play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }

    if (D_803D5530->state == STATE_BIRD_LANDING) {
        if (D_803D5530->unk4A == 0) {
            func_8032CED0_73E580(D_803D5530, SFX_UNKNOWN_128, 0x5800, 1.0f, 0, D_803D5538, D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h, D_803D552C->xVelocity.w,  D_803D552C->zVelocity.w, D_803D552C->yVelocity.w);
        }

        if (func_803224C4_733B74(0, 0, 0, MAX(4, -D_803D5530->yVelocity.h), 0x20, 0, 0, 0xB) != 0) {
            if (D_803D5530->yVelocity.h < -20) {
                do_rumble(0, 0xF, 0x46, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h));
            } else if (D_803D5530->yVelocity.h < -10) {
                do_rumble(0, 0xA, 0x28, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h));
            }
            load_animal(PARROT);
            D_803D5530->state = STATE_BIRD_TURNING;
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
            sp62 = 0;
            gLodDetailState = 0;
    } else {
       sp62 = classify_object_visibility_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x780, 5, 0x4E, 0x20, 0x9E, 1, CHECK_SEGMENT == 0);
    }

    if (sp62 == 0) {
        func_8035D120_76E7D0();

        switch (D_803D552C->unk365) {
        case ATTACK_NONE:
            break;
        case ATTACK_VULTURE:
            func_802DCCAC_6EE35C(16);
            D_803F2ECC = D_803F2ED8;
            gAnimBlendMode = ANIM_BLEND_ATTACK;
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        func_8034B298_75C948(0);
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        if (D_803D5528->unk3C4.unk0 == 0xC) {
            scale = 0x10000 - ((D_803D5528->unk3C4.unk2 << 0x10) / 20);
        } else {
            scale = 0x10000;
        }
        if ((gAnimBlendMode == 0) || (D_803F2ECC < 0x1F)) {
            func_802BAC24_6CC2D4(0xEA, 0x261);
            func_802C5F34_6D75E4(0x1D4, 0x1D4, 0);
            func_802BB1F0_6CC8A0(0x177, 0x232);
            func_802BC1F4_6CD8A4(0x232);
            func_802C4448_6D5AF8(0x261);
            func_8038CCF0_79E3A0( 0xEA, 0x13, -1, -1, -1, -1);
            func_8038CCF0_79E3A0(-0xEA, 0x1A, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (gAnimBlendMode) {
            case 1:
                func_802DB670_6ECD20(D_803A56B0_7B6D60, D_803A56BC_7B6D6C, D_803A56C8_7B6D78, D_803A56D8_7B6D88);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A56B0_7B6D60, D_803A56BC_7B6D6C, D_803A56C8_7B6D78, D_803A5700_7B6DB0);
                break;
            case 3:
                func_802DB670_6ECD20(D_803A56B0_7B6D60, D_803A56BC_7B6D6C, D_803A56C8_7B6D78, D_803A5728_7B6DD8);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((gDisplayListContext->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((temp_a0_2 = D_803D5538, temp_a0_2) || (temp_v0_8 = gCameraUiState, (temp_v0_8 == 0)) || (temp_v0_8 == 2) || ((temp_v0_8 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (temp_a0_2 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);

            gSPMatrix(gOpaqueDL++, OS_K0_TO_PHYSICAL(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.2f);
            if (D_803D5530->state == STATE_BIRD_LANDING) {
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x3C) >> 6, (D_803F2EC0 * 0x3C) >> 6, (D_803F2EC4 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, dog_missile_pod);
                create_particle_effect(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0x15, 0, 0, 0x30000, 0x1E, GPACK_RGBA5551(248, 248, 0, 1), GPACK_RGBA5551(120, 48, 248, 1), 0);
                D_803D552C->unk2EE += 1;
            } else {
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x3C) >> 6, (D_803F2EC0 * 0x3C) >> 6, (D_803F2EC4 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04001250_F22B0);
                func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_040015D0_F2630);
                if (gLodDetailState == 0) { func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_040016F0_F2750); }
                if (gLodDetailState == 0) { func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04001B30_F2B90); }

                gSPDisplayList(gOpaqueDL++, &D_01003618_3CEE8);

                if (gLodDetailState == 0) { func_802C78B0_6D8F60(2, 0x1A, 0xF000, 0xF000, 0xF000, D_803F2ED0, 0, 0, 0, D_04001760_E8D10); }
                func_802C78B0_6D8F60(2, 0x1A, 0xF000, 0xF000, 0xF000, D_803F2ED0, 0, 0, 0, D_04001C10_F2C70);
                if (scale != 0) {
                    if (gLodDetailState == 0) { func_802C78B0_6D8F60(0, 0x16, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_040019E0_F2A40); }
                    func_802C78B0_6D8F60(0x16, 0x17, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04001AC0_F2B20);
                    if (gLodDetailState == 0) { func_802C78B0_6D8F60(0, 0x18, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, D_803F2ED0, 0, 1, 0, D_040019E0_F2A40); }
                    func_802C78B0_6D8F60(0x18, 0x19, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, (scale * 0x3C) >> 6, D_803F2ED0, 0, 1, 0, D_04001AC0_F2B20);
                }
                if ((D_803D5530->movementState == MOVEMENT_STATE_GROUND) && (gLodDetailState == 0)) {
                    func_802C78B0_6D8F60(0, 5, 0xF000, 0xF000, 0xF000, D_803F2ED0, 0, 0, 0, D_040020C0_F3120);
                }
            }
            gSPPopMatrix(gOpaqueDL++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp62 == 0) || (sp62 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 0x12, 0xC, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp62 == 0) {
        func_803034D0_714B80(D_803D552C, 0x2BE, 0, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x15F, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x2BE, 0);
    }
    if ((D_803D5524->unk9C == PARROT_ATTACKING) && ((D_803D552C->movementMode == MOVEMENT_MODE_2) || (D_803D552C->movementMode == MOVEMENT_MODE_DEACTIVATED))) {
        load_animal(PARROT);
    }
}

void func_803144F8_725BA8(void) {
    if ((D_803D5530->movementState != MOVEMENT_STATE_GROUND) && (func_803224C4_733B74(0, 0, 0, 0, 32, 0, 0, 11) == 0) && (get_distance_from_ground() >= 49)) {
        load_animal(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}

void func_80314590_725C40(void) {
    func_802DBA58_6ED108(ATTACK_STATE_BIG_HIT, D_803D552C);
    load_animal(PARROT);
    play_sound_effect_at_location(SFX_UNKNOWN_141, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.1892f);
    func_802A6100_6B77B0();
}

void parrot_fly(void) {
    if (D_803D5530->movementState != MOVEMENT_STATE_GROUND) {
        load_animal(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}
