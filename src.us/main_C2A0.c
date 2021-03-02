#include <ultra64.h>

#include "common.h"

// unused
void func_80130BA0(void) {
    s16 phi_v0 = 0;
    do { phi_v0++; } while (phi_v0 < 60U);
}

// unused
#pragma GLOBAL_ASM("asm/nonmatchings/main_C2A0/func_80130BC4.s")

void func_80130C04(void) {
    // zero out Eeprom?
    func_80129090(&D_8023F260, 0, 64);
}
