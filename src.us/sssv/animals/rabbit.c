#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/rabbit/func_80300210_7118C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/rabbit/func_80301248_7128F8.s")

void func_80302018_7136C8(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D552C->unk365 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 29;
    } else {
        recharge_skill(1);
    }
}

void func_80302080_713730(void) {
    if (D_803D5530->unk162 != 1) {
        func_80321E60_733510(17, 0, 0, -30, 0, 0, -9, 24);
        play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    } else {
        recharge_skill(1);
    }
}

void heli_rabbit_drop_bomb(s32 arg0, s32 arg1, s32 arg2) {
    func_80321E60_733510(17, 0, 0, -30, 0, 0, -9, 20);
    play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_803021A8_713858(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D552C->unk365 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 29;
    }
}
