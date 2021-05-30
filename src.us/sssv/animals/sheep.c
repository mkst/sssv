#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_8035FE90_771540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_80360D94_772444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_803622DC_77398C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/sheep/func_80362618_773CC8.s")

void func_80362964_774014(void) {
    if (D_803D5530->unk162 == 1) {
        D_803D552C->unk30E = -1;
    } else {
        D_803D552C->unk30E = (D_803D552C->unk30E + 1) & 0xFF;
    }
}

void func_803629B0_774060(void) {
    if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 5)) {
        func_8037FEDC_79158C();
    } else {
        recharge_skill(1);
    }
}

void func_80362A00_7740B0(void) {
}

void func_80362A08_7740B8(void) {
}

// springy_ram_headbutt (or vice versa?)
void func_80362A10_7740C0(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 3;
    play_sound_effect_at_location(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
//
void ram_headbutt(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 3;
    play_sound_effect_at_location(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
