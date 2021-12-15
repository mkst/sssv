#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/seagull/func_80380920_791FD0.s")

void func_80381C60_793310(void) {
    if (D_803D552C->unk320 == NULL) {
        D_803D552C->unk320 = func_803213B0_732A60();
        if (D_803D552C->unk320 != 0) {
            D_803D552C->unk308 = (u16) D_803D552C->unk320->unk42;
            load_animal(SEAGULL2);
            D_803D552C->yPos -= D_803D552C->unk308;
            if (D_803D5530->unk160 == 2) {
                D_803D552C->yPos = MAX(D_803D552C->yPos, func_80310F58_722608(D_803D552C->xPos, D_803D552C->zPos) >> 16);
            } else {
                D_803D552C->yPos = MAX(D_803D552C->yPos, func_8031124C_7228FC(D_803D552C->xPos, D_803D552C->zPos) >> 16);
            }
        }
        if (D_803D5530->unk162 == 2) {
            if (D_803D5528->skillBEnergy[0] > 400) {
                D_803D5528->skillBEnergy[0] -= 400;
                if (func_803224C4_733B74(-58, 0, 0, 29, 20, 0, 0, 11) != 0) {
                    play_sound_effect_at_location(SFX_BIRD_CLAW_ATTACK, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
                    D_803D5530->yVelocity.h += 2;
                } else {
                    play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
                }
                if (D_803D552C->unk365 == ATTACK_NONE) {
                    D_803D552C->unk365 = ATTACK_BITE;
                    D_803D552C->unk32A = D_803D5544;
                }
            }
        }
    } else {
        func_80321920_732FD0(D_803D552C->unk320, 0, 0);
        play_sound_effect_at_location(SFX_BIRD_HURT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BF3E0);
        D_803D552C->yPos += D_803D552C->unk308;
        D_803D552C->unk18 += D_803D552C->unk308;
        load_animal(SEAGULL);
    }
}

void func_80381F14_7935C4(void) {
    if ((D_803D5530->unk162 == 2) || ((D_803D5530->unk6C != 0) && (D_803D5530->unk6C->unk16C->unk0 >= 256))) {
        if (func_803224C4_733B74(-78, 0, 0, 58, 20, 0, 0, 19) != 0) {
            play_sound_effect_at_location(SFX_BIRD_CLAW_ATTACK, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
            D_803D5530->yVelocity.h += 2;
        } else {
            play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
        }
        if (D_803D552C->unk365 == ATTACK_NONE) {
            D_803D552C->unk365 = ATTACK_BITE;
            D_803D552C->unk32A = D_803D5544;
        }
    }
}
