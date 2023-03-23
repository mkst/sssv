#include <ultra64.h>
#include "common.h"

u8 D_803B58A0_7C6F50[4] = { 0, 1, 2, 0 };
u8 D_803B58A4_7C6F54[4] = { 1, 2, 3, 0 };
s16 D_803B58A8_7C6F58[4] = { 500, 500, 500, 0 };
s16 D_803B58B0_7C6F60[10] = { 0, 360, 310,  90,  254, 90, 176, 78, 112, 0 };
s16 D_803B58C4_7C6F74[10] = { 0, 640, 1310, 130, 180, 90, 180, 48, 180, 0 };

#ifdef NON_MATCHING
// CURRENT (323)
void func_80382CF0_7943A0(void) {
    s32 phi_a2;
    s32 phi_a4;
    f32 temp_f2;

    s16 sp8A;
    s16 sp88; // pad
    s16 sp86;
    s16 sp84;

    s32 sp74[4]; // pad 0x10

    s16 sp68;

    if (D_803D5538 != 0) {
        phi_a2 = ABS(D_803D5530->xVelocity.h);
        phi_a4 = ABS(D_803D5530->zVelocity.h);
        if ((phi_a4 + phi_a2) > 10) {
            if ((D_803D5530->yPos.h + 0x60) < (func_8031124C_7228FC(
                D_803D5530->xPos.h + ((D_803D5530->xVelocity.h * 3) >> 1),
                D_803D5530->zPos.h + ((D_803D5530->zVelocity.h * 3) >> 1)) >> 16)) {
                D_803D5530->xVelocity.h = -D_803D5530->xVelocity.h >> 1;
                D_803D5530->zVelocity.h = -D_803D5530->zVelocity.h >> 1;
                do_rumble(0, 0xD, 0x19, 5, 0);
            }
        }
    }
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
            D_803D552C->unk369 = 2;
            D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 19;
            D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * 19;
            temp_f2 = sqrtf((D_803D5530->xVelocity.w / 65536.0) * (D_803D5530->xVelocity.w / 65536.0) + (D_803D5530->zVelocity.w / 65536.0) * (D_803D5530->zVelocity.w / 65536.0));
            if (temp_f2 > 20.0) {
                D_803D5530->xVelocity.w = (D_803D5530->xVelocity.w * 20.0) / temp_f2;
                D_803D5530->zVelocity.w = (D_803D5530->zVelocity.w * 20.0) / temp_f2;
            }
            D_803D5530->yVelocity.h = MAX(7, D_803D5530->yVelocity.h + 4);
            D_803D552C->unk308 = MAX(0, D_803D552C->unk308 - 25);

            play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp8A = 0;
        D_803F2EDD = 0;
    } else {
        sp8A = func_802E89F0_6FA0A0(
            D_803D552C->xPos.w,
            D_803D552C->zPos.w,
            D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
            0x800,
            0,
            60,
            60,
            120,
            1,
            CHECK_SEGMENT == 0);
    }

    if (sp8A == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_80302E50_714500(500, 500, 500);
            if (D_803D5530->state == 0x3F) {
                // help
                phi_a4 = MIN(40, phi_a2 = D_803D552C->unk308++);
                // stack is wrong here :(
                sp68 = (40 - (phi_a4 * 2));
                func_8030322C_7148DC(0, -sp68);
                func_8030322C_7148DC(1, -sp68);
                func_8030322C_7148DC(2, -sp68);
                func_8030322C_7148DC(3, -sp68);
            }
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
                case 1:
                    func_802DB670_6ECD20(D_803B58A0_7C6F50, D_803B58A4_7C6F54, D_803B58A8_7C6F58, D_803B58B0_7C6F60);
                    break;
                case 2:
                    func_802DB670_6ECD20(D_803B58A0_7C6F50, D_803B58A4_7C6F54, D_803B58A8_7C6F58, D_803B58C4_7C6F74);
                    break;
            }
        }
        func_8038064C_791CFC();
        if ((((D_80204278->usedModelViewMtxs + 30) < 250)) &&
            (D_803F2EDA != 0) &&
            (((D_803D5538 != 0)) || (D_803F2AA2 == 0) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
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

            load_1_tile(D_04007DD0_E5390, D_04007BD0_E5190);
            func_802C78B0_6D8F60(0, 1, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04007500_E4AC0);
            func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040077E0_E4DA0);
            func_802C78B0_6D8F60(2, 3, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04007AE0_E50A0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, (u16*)&sp86, (u16*)&sp84);
                func_8031A278_72B928(&D_803D552C->unk326, (u16*)&sp86, (u16*)&sp84);
#pragma _permuter sameline start
                sp86 = D_803BD54A_7CEBFA[sp86];sp84 = D_803BD602_7CECB2[sp84];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000D00, D_01000620, sp86);
                func_802C78B0_6D8F60(1, 0, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04007E70);
                func_80356BD8_768288(D_01000D00, D_01000620, sp84);
                func_802C78B0_6D8F60(1, 0, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04007E90);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp8A == 0) || (sp8A == 2)) {
        func_8034BD20_75D3D0(
            D_803D552C->xPos.h,
            D_803D552C->zPos.h,
            (D_803D552C->yPos.h + D_803D5524->unkBA),
            D_803D552C->unk302,
            D_01033190,
            21,
            9,
            155,
            0, // r
            0, // g
            0, // b
            0,
            D_803D5538);
    }
    func_80303D00_7153B0(D_803D552C, 500, 500);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/cool_cod/func_80382CF0_7943A0.s")
#endif

void func_80383804_794EB4(void) {
}

void func_8038380C_794EBC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8038381C_794ECC(void) {
}
