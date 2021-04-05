#include <ultra64.h>

#include "common.h"

// unused
void func_80130BA0(void) {
    s16 i = 0;
    do { i++; } while (i < 60U);
}

// junk out eeprom?
void func_80130BC4(void) {
    s16 i;
    u16 c;
    u8 *e;

    c = 0;
    e = (u8*)&D_8023F260.unk4;

    for (i = 0; i < 60U; i++) {
        *e++ = c;
        c++;
    }
}

void func_80130C04(void) {
    // zero out Eeprom?
    memset_bytes((u8*)&D_8023F260, 0, 64);
}
