#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/pirana/func_80382050_793700.s")

void func_80382C9C_79434C(void) {
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_80382CB0_794360(void) {
    D_803D552C->unk365 = ATTACK_NONE;
}

void func_80382CC0_794370(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_80382CE4_794394(void) {
}
