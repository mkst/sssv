#include <ultra64.h>

#include "common.h"


// save_to_eeprom
s16 func_80130C30(s16 arg0) {
    s32 pad0;
    s32 pad1;
    s16 pad2;
    s16 res;
    s32 temp_v0;
    u8 *eepromAddr;

    if (D_802912D4 == 0) {
        return 0;
    }

    if (arg0 == 4) {
        eepromAddr = D_8023F2A0; // eeprom address
    } else {
        eepromAddr = D_8023F260;
    }

    temp_v0 = func_80130E10(eepromAddr);
    if (arg0 == 4) {
        *D_8023F2A0 = temp_v0;
    } else {
        *D_8023F260 = temp_v0;
    }
    return osEepromLongWrite(&D_8028D0A8, (u32)(arg0 * EEPROM_MAXBLOCKS) / EEPROM_BLOCK_SIZE, eepromAddr, 64);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/eeprom/func_80130CD4.s")

// checksum?
s32 func_80130E10(u8 *arg0) {
    u8 *phi_a0;
    s32 res;
    s16 i;

    res = 0;
    // skip first 4 bytes
    arg0 += 4;

    for (i = 0; i < 60U; i++) {
        res += *arg0++;
    }

    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/eeprom/func_80130E44.s")
