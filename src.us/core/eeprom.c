#include <ultra64.h>

#include "common.h"


s16 write_eeprom(s16 bank) {
    s16 pad0; // maybe block length?
    s32 res;
    u8* eepromBytes;
    s32 checksum;
    Eeprom *eeprom;

    if (D_802912D4 == 0) {
        return 0;
    }

    if (bank == 4) {
        eeprom = &D_8023F2A0;
    } else {
        eeprom = &D_8023F260;
    }

    eepromBytes = (u8*)eeprom;
    checksum = eeprom_checksum(eepromBytes);
    if (bank == 4) {
        D_8023F2A0.checksum = checksum;
    } else {
        D_8023F260.checksum = checksum;
    }
    res = osEepromLongWrite(&D_8028D0A8, (u32)(bank * EEPROM_MAXBLOCKS) / EEPROM_BLOCK_SIZE, (u8*)eeprom, 64);
    return res;
}

s32 read_eeprom(s16 slot) {
    s32 res;
    u8 *eepromBytes;
    s32 checksum;
    Eeprom *eeprom;

    if (D_802912D4 == 0) {
        return 0;
    }
    if (slot == 4) {
        eeprom = &D_8023F2A0;
    } else {
        eeprom = &D_8023F260;
    }
    res = osEepromLongRead(&D_8028D0A8, (u32) (slot << 6) >> 3, (u8*)eeprom, 64);
    eepromBytes = (u8*)eeprom;
    checksum = eeprom_checksum(eepromBytes);
    if (slot == 4) {
        if (D_8023F2A0.unkC < 0) {
            D_8023F2A0.unkC = 16;
        }
        if (D_8023F2A0.unkC >= 20) {
            D_8023F2A0.unkC = 16;
        }
        if (D_8023F2A0.unkD < 0) {
            D_8023F2A0.unkD = 16;
        }
        if (D_8023F2A0.unkD >= 20) {
            D_8023F2A0.unkD = 16;
        }
        if (D_8023F2A0.unkE >= 9) {
            D_8023F2A0.unkE = 2;
        }
        if (D_8023F2A0.unkE < 0) {
            D_8023F2A0.unkE = 2;
        }
        if (D_8023F2A0.checksum != checksum) {
            return 1;
        }
    } else if (checksum != D_8023F260.checksum) {
        return 1;
    }
    return (s16)res;
}

s32 eeprom_checksum(u8 *eeprom) {
    s32 res;
    s16 i;

    res = 0;
    // skip checksum itself
    eeprom += 4;

    for (i = 0; i < 60U; i++) {
        res += *eeprom++;
    }
    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/eeprom/func_80130E44.s")
// NON-MATCHING: JUSTREG
// void func_80130E44(void) {
//     s16 cnt;
//     s16 i;
//     s16 res;
//     s16 requireReset;
//
//     requireReset = 0;
//     i = 0;
//
//     while (i < 4) {
//         res = read_eeprom(4);
//         i++;
//         if (res == 0) {
//             break;
//         }
//     }
//
//     if ((res != 0) || (i >= 4) || (D_8023F2A0.unk4 != 0xCF76F7E)) {
//         requireReset = 1;
//         i = 0;
//         memset_bytes(&D_8023F2A0, 0, 64);
//         D_8023F2A0.unk4 = 0xCF76F7E;
//         D_8023F2A0.unkC = 16;
//         D_8023F2A0.unkD = 16;
//
//         if (D_80204260 == 2) {
//             D_8023F2A0.unkE = 2;
//         } else {
//             D_8023F2A0.unkE = 20;
//         }
//         if (D_80204260 == 0) {
//             D_8023F2A0.unkE = 6;
//         }
//         D_8023F2A0.unk8 = 1;
//         while (i < 4) {
//             res = write_eeprom(4);
//             i++;
//             if (res == 0) {
//                 break;
//             }
//         }
//     }
//
//     for (cnt = 3; cnt >= 0; cnt--) {
//         i = 0;
//         while (i < 4) {
//             res = read_eeprom(cnt);
//             i++;
//             if (res == 0) {
//                 break;
//             }
//         }
//
//         if ((res != 0) || (requireReset == 1)) {
//             i = 0;
//             rmonPrintf(D_8015AD70, cnt); // "reset all data - %d\n"
//             if (cnt != 4) {
//                 memset_bytes(&D_8023F260, 0, 64);
//             }
//
//             while (i < 4) {
//                 res = write_eeprom(cnt);
//                 i++;
//                 if (res == 0) {
//                     break;
//                 }
//             }
//         } else if (cnt != 4) {
//             strncpy(&D_8023F260, &D_8023F2E0[cnt], 64);
//         }
//     }
// }
