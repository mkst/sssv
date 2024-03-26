#include <ultra64.h>

#include "common.h"

void load_overlay(u8 id) {
    s32 pad;

    stop_all_sounds();

    switch (id) {
    case 0:
        osInvalICache(overlay2_TEXT_START, overlay2_TEXT_END - overlay2_TEXT_START);
        if (id == 0) {};
        osInvalDCache(overlay2_DATA_START, overlay2_RODATA_END - overlay2_DATA_START);
        dma_read(overlay2_ROM_START, func_80294E50_6A6500, overlay2_ROM_END - overlay2_ROM_START);
        bzero(overlay2_BSS_START, overlay2_BSS_END - overlay2_BSS_START);
        break;
    case 1:
        osInvalICache(overlay1_TEXT_START, overlay1_TEXT_END - overlay1_TEXT_START);
        if (id == 0) {};
        osInvalDCache(overlay1_DATA_START, overlay1_RODATA_END - overlay1_DATA_START);
        dma_read(overlay1_ROM_START, func_80294E50_6384F0, overlay1_ROM_END - overlay1_ROM_START);
        bzero(overlay1_BSS_START, overlay1_BSS_END - overlay1_BSS_START);
        break;
    }

    if ((!pad) && (!pad)) {};
}
