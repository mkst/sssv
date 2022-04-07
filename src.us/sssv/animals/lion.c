#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/lion/func_802F1730_702DE0.s")

void func_802F2A2C_7040DC(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_ROAR;
    play_sound_effect_at_location(SFX_LION_ROAR, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void lion_roar(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_ROAR;
    play_sound_effect_at_location(SFX_LION_ROAR, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}
