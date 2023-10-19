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
extern Gfx D_04002720_CA150[];

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003A58_3D328[];
extern Gfx D_01033190_6CA60[];

void func_80313790_724E40(void) {
    s32 sp6C;
    s16 pad;
    u8 temp_v0_8;
    u8 temp_a0_2;
    s16 var_v0;
    s16 temp_a3;
    s16 sp62;
    s32 var_v0_2;

    if (D_803D553A == 4) {
        play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
    }

    if (D_803D5530->state == 0x6A) {
        if (D_803D5530->unk4A == 0) {
            func_8032CED0_73E580(D_803D5530, SFX_UNKNOWN_128, 0x5800, 1.0f, 0, D_803D5538, D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h, D_803D552C->xVelocity.w,  D_803D552C->zVelocity.w, D_803D552C->yVelocity.w);
        }

        if (func_803224C4_733B74(0, 0, 0, MAX(4, -D_803D5530->yVelocity.h), (s16) 0x20, (s16) 0, (s16) 0, (u8) 0xB) != 0) {
            if (D_803D5530->yVelocity.h < -20) {
                do_rumble(0, 0xF, 0x46, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
            } else if (D_803D5530->yVelocity.h < -10) {
                do_rumble(0, 0xA, 0x28, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
            }
            load_animal(PARROT);
            D_803D5530->state = 0x68;
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) || ((D_803D5524->biome == 0) &&
            ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0_2 = 1;
        } else {
            var_v0_2 = 0;
        }
        if (var_v0_2 != 0) {
            sp62 = 0;
            D_803F2EDD = 0;
            goto block_23;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) || ((D_803D5524->biome == 0) &&
        ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0_2 = 1;
    } else {
        var_v0_2 = 0;
    }
    sp62 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x780, (u8) 5, (s16) 0x4E, (s16) 0x20, (s16) 0x9E, (s8) 1, (u8) (var_v0_2 == 0));

block_23:
    if (sp62 == 0) {
        func_8035D120_76E7D0();

        switch (D_803D552C->unk365) {
        case ATTACK_NONE:
            break;
        case ATTACK_VULTURE:
            func_802DCCAC_6EE35C(16);
            D_803F2ECC = (u16) D_803F2ED8;
            D_803F2ECE = 3;
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        func_8034B298_75C948(0);
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        if (D_803D5528->unk3C0.unk4 == 0xC) {
            sp6C = 0x10000 - ((D_803D5528->unk3C0.unk6 << 0x10) / 20);
        } else {
            sp6C = 0x10000;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802BAC24_6CC2D4(0xEA, 0x261);
            func_802C5F34_6D75E4(0x1D4, 0x1D4, 0);
            func_802BB1F0_6CC8A0(0x177, 0x232);
            func_802BC1F4_6CD8A4(0x232);
            func_802C4448_6D5AF8(0x261);
            func_8038CCF0_79E3A0(0xEA, 0x13, -1, -1, -1, -1);
            func_8038CCF0_79E3A0(-0xEA, 0x1A, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {                    /* irregular */
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
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((temp_a0_2 = D_803D5538, temp_a0_2) || (temp_v0_8 = D_803F2AA2, (temp_v0_8 == 0)) || (temp_v0_8 == 2) || ((temp_v0_8 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (temp_a0_2 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (u32) D_803D5530->xPos.w, (u32) D_803D5530->zPos.w, (u32) D_803D5530->yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (u32) ((s32) D_803F2EB8 / 4), (s16) (s32) D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.2f);
            if (D_803D5530->state == 0x6A) {
                func_802C78B0_6D8F60(1, 2, (s32) (D_803F2EBC * 0x3C) >> 6, (s32) (D_803F2EC0 * 0x3C) >> 6, (s32) (D_803F2EC4 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04002720_CA150);
                create_particle_effect((s32) D_803D5530->xPos.h, (s32) D_803D5530->zPos.h, (s32) D_803D5530->yPos.h, 0x15, (s16) 0, (s16) 0, 0x30000, (s16) 0x1E, (u16) GPACK_RGBA5551(248, 248, 0, 1), (u16) GPACK_RGBA5551(120, 48, 248, 1), (s16) 0);
                D_803D552C->unk2EE += 1;
            } else {
                func_802C78B0_6D8F60(1, 2, (s32) (D_803F2EBC * 0x3C) >> 6, (s32) (D_803F2EC0 * 0x3C) >> 6, (s32) (D_803F2EC4 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04001250_F22B0);
                func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_040015D0_F2630);
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_040016F0_F2750); }
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, (D_803F2EC8 * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04001B30_F2B90); }

                gSPDisplayList(D_801D9E88++, &D_01003618_3CEE8);

                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 0x1A, 0xF000, 0xF000, 0xF000, D_803F2ED0, 0, 0, 0, D_04001760_E8D10); }
                func_802C78B0_6D8F60(2, 0x1A, 0xF000, 0xF000, 0xF000, D_803F2ED0, 0, 0, 0, D_04001C10_F2C70);
                if (sp6C != 0) {
                    if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0, 0x16, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_040019E0_F2A40); }
                    func_802C78B0_6D8F60(0x16, 0x17, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, D_803F2ED0, 0, 0, 0, D_04001AC0_F2B20);
                    if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0, 0x18, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, D_803F2ED0, 0, 1, 0, D_040019E0_F2A40); }
                    func_802C78B0_6D8F60(0x18, 0x19, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, (sp6C * 0x3C) >> 6, D_803F2ED0, 0, 1, 0, D_04001AC0_F2B20);
                }
                if ((D_803D5530->unk162 == 1) && (D_803F2EDD == 0)) {
                    func_802C78B0_6D8F60(0, 5, 0xF000, 0xF000, 0xF000, D_803F2ED0, 0, 0, 0, D_040020C0_F3120);
                }
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp62 == 0) || (sp62 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190_6CA60, (s16) 0x12, (s16) 0xC, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (sp62 == 0) {
        func_803034D0_714B80(D_803D552C, 0x2BE, 0, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x15F, (u16) 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x2BE, 0);
    }
    if ((D_803D5524->unk9C == PARROT_ATTACKING) && ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5))) {
        load_animal(PARROT);
    }
}

void func_803144F8_725BA8(void) {
    if ((D_803D5530->unk162 != 1) && (func_803224C4_733B74(0, 0, 0, 0, 32, 0, 0, 11) == 0) && (get_distance_from_ground() >= 49)) {
        load_animal(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}

void func_80314590_725C40(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    load_animal(PARROT);
    play_sound_effect_at_location(SFX_UNKNOWN_141, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.1892f);
    func_802A6100_6B77B0();
}

void parrot_fly(void) {
    if (D_803D5530->unk162 != 1) {
        load_animal(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}
