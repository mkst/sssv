#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/polar_bear/func_80365F10_7775C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/polar_bear/func_803677C4_778E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/polar_bear/func_80368840_779EF0.s")

void func_80368AC4_77A174(void) {
    if ((D_803D552C->unk365 != 27) && (D_803D552C->unk365 != 28)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 27;
    }
}

void func_80368B04_77A1B4(void) {
    if ((D_803D552C->unk365 != 27) && (D_803D552C->unk365 != 28)) {
        load_animal(POLAR_BEAR);
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 28;
        func_802A4390_6B5A40();
        func_802B2834_6C3EE4();
    }
}

void func_80368B78_77A228(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 26;
}

void func_80368BA0_77A250(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 0x599, 0xB4, D_803D5530, 0x32, 0x21);
        play_sound_effect_at_location(38, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    } else {
        recharge_skill(1);
    }
}

void polar_tank_drop_mine(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 0x599, 0xDC, D_803D5530, 0x32, 0x21);
        play_sound_effect_at_location(0x26, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
}

void func_80368CF0_77A3A0(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 26;
}

void func_80368D18_77A3C8(void) {
    if (D_803D5530->unk162 == 1) {
        func_802A467C_6B5D2C(0);
        D_803D552C->unk369 = 1;
    }
}

void func_80368D60_77A410(s16 arg0) {
    if (arg0 == 0) {
        D_803D552C->unk2EC = 0;
    } else {
        if (D_803D552C->unk365 != 0x1B) {
            D_803D552C->unk2EC = arg0;
            D_803D552C->unk32A = D_803D5544;
            D_803D552C->unk365 = 27;
        } else {
            D_803D552C->unk2EC = arg0;
        }
    }
}
