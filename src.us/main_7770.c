#include <ultra64.h>

#include "common.h"

#if 0
void load_overlay(u8 arg0) {

    stop_all_sounds();
    switch (arg0) {
    case 0:
        osInvalICache(overlay2_TEXT_START, overlay2_TEXT_END - overlay2_TEXT_START);
        osInvalDCache(overlay2_DATA_START, overlay2_DATA_END - overlay2_DATA_START);
        dma_read(overlay2_ROM_START, func_80294E50, overlay2_ROM_END - overlay2_ROM_START);
        bzero(overlay2_BSS_START, overlay2_BSS_END - overlay2_BSS_START);
        break;
    case 1:
        osInvalICache(overlay1_TEXT_START, overlay1_TEXT_END - overlay1_TEXT_START);
        osInvalDCache(overlay1_DATA_START, overlay1_DATA_END - overlay1_DATA_START);
        dma_read(overlay1_ROM_START, func_80294E50, overlay1_ROM_END - overlay1_ROM_START);
        bzero(overlay1_BSS_START, overlay1_BSS_END - overlay1_BSS_START);
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/load_overlay.s")
#endif
