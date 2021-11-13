#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/parrot/func_80313790_724E40.s")

void func_803144F8_725BA8(void) {
    if ((D_803D5530->unk162 != 1) && (func_803224C4_733B74(0, 0, 0, 0, 32, 0, 0, 11) == 0) && (func_802B2580_6C3C30() >= 49)) {
        load_animal(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}

void func_80314590_725C40(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    load_animal(PARROT);
    play_sound_effect_at_location(SFX_UNKNOWN_141, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BD114_7CE7C4);
    func_802A6100_6B77B0();
}

void parrot_fly(void) {
    if (D_803D5530->unk162 != 1) {
        load_animal(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}
