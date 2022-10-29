#include <ultra64.h>

#include "common.h"

/*
    Guess so far:

    5 banks (64 bytes each)

    0, 1, 2, 3 used for User save state

    4th bank used for "Global" save state e.g. language
*/

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
        if (D_8023F2A0.musicVol < MIN_AUDIO_VOLUME) {
            D_8023F2A0.musicVol = DEFAULT_AUDIO_VOLUME;
        }
        if (D_8023F2A0.musicVol > MAX_AUDIO_VOLUME) {
            D_8023F2A0.musicVol = DEFAULT_AUDIO_VOLUME;
        }
        if (D_8023F2A0.sfxVol < MIN_AUDIO_VOLUME) {
            D_8023F2A0.sfxVol = DEFAULT_AUDIO_VOLUME;
        }
        if (D_8023F2A0.sfxVol > MAX_AUDIO_VOLUME) {
            D_8023F2A0.sfxVol = DEFAULT_AUDIO_VOLUME;
        }
        if (D_8023F2A0.language > LANG_MAX) {
            D_8023F2A0.language = LANG_ENGLISH;
        }
        if (D_8023F2A0.language < LANG_MIN) {
            D_8023F2A0.language = LANG_ENGLISH;
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
    // skip over checksum
    eeprom += 4;

    for (i = 0; i < 60U; i++) {
        res += *eeprom++;
    }
    return res;
}

#ifdef NON_MATCHING
void func_80130E44(void) {
    s16 res_s16;
    s16 i;
    s16 bank;
    s16 requireReset;

    s32 res;
    s16 j;

    requireReset = 0;
    i = 0;

    // 4 attempts to read eeprom
    do {
        if (res_s16 = res = read_eeprom(4));
        i++;
    } while (res && i < 4);

    if ((res_s16 != 0) || (i > 3) || (D_8023F2A0.unk4 != 0xCF76F7E)) {
        j = 0;
        requireReset = 1;

        // bad eeprom, so zero out
        memset_bytes((u8*)&D_8023F2A0, 0, 64);

        D_8023F2A0.unk4 = 0xCF76F7E;
        D_8023F2A0.musicVol = DEFAULT_AUDIO_VOLUME;
        D_8023F2A0.sfxVol = DEFAULT_AUDIO_VOLUME;

        if (gRegion == REGION_US) {
            D_8023F2A0.language = LANG_ENGLISH;
        } else {
            D_8023F2A0.language = LANG_DEFAULT;
        }
        if (gRegion == REGION_JP) {
            D_8023F2A0.language = LANG_JAPANESE;
        }
        D_8023F2A0.unk8 = 1;
        // four attempts to write eeprom
        do {
            res = write_eeprom(4);
            j++;
        } while (res && j < 4);
    }

    // read each user bank
    for (bank = 3; bank >= 0; bank--) {
        i = 0;
        // four attempts to read each bank
        do {
            if (res_s16 = res = read_eeprom(bank)) {
                // debug?
            }
            i++;
        } while (res && i < 4);

        if ((res_s16 != 0) || (requireReset == 1)) {
            rmonPrintf("reset all data - %d\n", bank);
            j = 0;
            if (bank != 4) {
                memset_bytes((u8*)&D_8023F260, 0, 64);
            }

            while (j < 4) {
                res = write_eeprom(bank);
                j++;
                if (res == 0) {
                    break;
                }
            }
        } else if (bank != 4) {
            memcpy_sssv((u8*)&D_8023F260, (u8*)&D_8023F2E0[bank], 64);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/eeprom/func_80130E44.s")
#endif
