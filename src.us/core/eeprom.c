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
        eeprom = &gEepromGlobal;
    } else {
        eeprom = &D_8023F260;
    }

    eepromBytes = (u8*)eeprom;
    checksum = eeprom_checksum(eepromBytes);
    if (bank == 4) {
        gEepromGlobal.checksum = checksum;
    } else {
        D_8023F260.checksum = checksum;
    }
    return osEepromLongWrite(&D_8028D0A8, (u32)(bank * EEPROM_MAXBLOCKS) / EEPROM_BLOCK_SIZE, (u8*)eeprom, sizeof(D_8023F260));
}

s16 read_eeprom(s16 slot) {
    s32 res;
    u8 *eepromBytes;
    s32 checksum;
    Eeprom *eeprom;

    if (D_802912D4 == 0) {
        return 0;
    }
    if (slot == 4) {
        eeprom = &gEepromGlobal;
    } else {
        eeprom = &D_8023F260;
    }
    res = osEepromLongRead(&D_8028D0A8, (u32) (slot << 6) >> 3, (u8*)eeprom, 64);
    eepromBytes = (u8*)eeprom;
    checksum = eeprom_checksum(eepromBytes);
    if (slot == 4) {
        if (gEepromGlobal.musicVol < MIN_AUDIO_VOLUME) {
            gEepromGlobal.musicVol = DEFAULT_AUDIO_VOLUME;
        }
        if (gEepromGlobal.musicVol > MAX_AUDIO_VOLUME) {
            gEepromGlobal.musicVol = DEFAULT_AUDIO_VOLUME;
        }
        if (gEepromGlobal.sfxVol < MIN_AUDIO_VOLUME) {
            gEepromGlobal.sfxVol = DEFAULT_AUDIO_VOLUME;
        }
        if (gEepromGlobal.sfxVol > MAX_AUDIO_VOLUME) {
            gEepromGlobal.sfxVol = DEFAULT_AUDIO_VOLUME;
        }
        if (gEepromGlobal.language > LANG_MAX) {
            gEepromGlobal.language = LANG_ENGLISH;
        }
        if (gEepromGlobal.language < LANG_MIN) {
            gEepromGlobal.language = LANG_ENGLISH;
        }
        if (gEepromGlobal.checksum != checksum) {
            return 1;
        }
    } else if (checksum != D_8023F260.checksum) {
        return 1;
    }
    return (s16) res; // hmmm
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


void func_80130E44(void) {
    s16 i;
    s16 badRead;
    s16 bank;
    s16 requireReset;
    s16 badWrite;
    s32 res;

    requireReset = 0;

    // 4 attempts to read eeprom
    badRead = 1;
    i = 0;
    while (badRead && i < 4) {
        badRead = read_eeprom(4);
        i++;
    }

    if (badRead || (i > 3) || (gEepromGlobal.unk4 != 0xCF76F7E)) {
        requireReset = 1;

        // bad eeprom, so zero out
        memset_bytes((u8*)&gEepromGlobal, 0, sizeof(gEepromGlobal));

        gEepromGlobal.unk4 = 0xCF76F7E;
        gEepromGlobal.musicVol = DEFAULT_AUDIO_VOLUME;
        gEepromGlobal.sfxVol = DEFAULT_AUDIO_VOLUME;

        if (gRegion == REGION_US) {
            gEepromGlobal.language = LANG_ENGLISH;
        } else {
            gEepromGlobal.language = LANG_DEFAULT;
        }
        if (gRegion == REGION_JP) {
            gEepromGlobal.language = LANG_JAPANESE;
        }
        gEepromGlobal.unk8 = 1; // isReset?

        // four attempts to write eeprom
        badWrite = 1;
        i = 0;
        while (badWrite && i < 4) {
            badWrite = write_eeprom(4);
            i++;
        }
    }

    // read each user bank
    for (bank = 3; bank >= 0; bank--) {
        // four attempts to read each bank
        badRead = 1;
        i = 0;
        while (badRead && i < 4) {
            badRead = read_eeprom(bank);
            i++;
        }

        if (badRead || (requireReset == 1)) {
            osSyncPrintf("reset all data - %d\n", bank);
            if (bank != 4) {
                memset_bytes((u8*)&D_8023F260, 0, sizeof(D_8023F260));
            }
            badWrite = 1;
            i = 0;
            while (badWrite && i < 4) {
                badWrite = write_eeprom(bank);
                i++;
            }
        } else if (bank != 4) {
            memcpy_sssv((u8*)&D_8023F260, (u8*)&D_8023F2E0[bank], sizeof(D_8023F260));
        }
    }
}
