#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/rat/func_8035E430_76FAE0.s")

void func_8035F92C_770FDC(void) {
    if (((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(
            D_803D5530->xPos - (((D_80152C78[(u8)(D_803D552C->unk302)] >> 7) * 20) >> 8),
            D_803D5530->zPos - (((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * 20) >> 8),
            D_803D5530->yPos,
            552, 110, D_803D5530, 3, 33);
        play_sound_effect_at_location(SFX_DROP_MINE, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
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

void func_8035FB10_7711C0(void) {
    Animal *a;

    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEC10);
            D_803D552C->unk308 = 80;
        } else {
            func_8032C508_73DBB8(16, 0x7000, 0, 1.3f);
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

void func_8035FC08_7712B8(void) {
    D_803D552C->unk2B4.unk4 = 0;
    D_803D552C->unk2CC = NULL;
}

void rat_drop_mine(void) {
    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) {
        if (D_803D5530->unk6C == 0) {
            spawn_temporary_object(
                D_803D5530->xPos - (((D_80152C78[(u8)(D_803D552C->unk302)] >> 7) * 20) >> 8),
                D_803D5530->zPos - (((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * 20) >> 8),
                D_803D5530->yPos,
                552,
                150,
                D_803D5530,
                3,
                33);
            play_sound_effect_at_location(SFX_DROP_MINE, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
        }
    }
}

void rat_bite(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
    play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEC14);
}

void king_rat_bugel_call(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEC18);
        D_803D552C->unk308 = 80;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = 39;
    D_803D552C->unk2B4.unk4 = 1;
}

void king_rat_fart(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_FART;
}
