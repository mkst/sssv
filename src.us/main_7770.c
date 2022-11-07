#include <ultra64.h>

#include "common.h"


#ifdef NON_MATCHING
// just reg, but something is wrong
void load_overlay(u8 arg0) {
    s32 pad;
    s32 rom_len;
    s32 text_len;
    s32 data_len;
    s32 bss_len;

    stop_all_sounds();

    switch(arg0) {
    case 0: // overlay 2
        text_len = overlay2_TEXT_END - overlay2_TEXT_START;
        data_len = overlay2_RODATA_END - overlay2_DATA_START;
        bss_len = overlay2_BSS_END - overlay2_BSS_START;
        rom_len = overlay2_ROM_END - overlay2_ROM_START;

        osInvalICache(overlay2_TEXT_START, text_len);
        osInvalDCache(overlay2_DATA_START, data_len);
        // load overlay2 code from ROM
        dma_read(overlay2_ROM_START, overlay2_TEXT_START, rom_len);
        // zero out bss
        bzero(overlay2_BSS_START, bss_len);
        break;
    case 1: // overlay 1
        text_len = overlay1_TEXT_END - overlay1_TEXT_START;
        data_len = overlay1_RODATA_END - overlay1_DATA_START;
        bss_len = overlay1_BSS_END - overlay1_BSS_START;
        rom_len = overlay1_ROM_END - overlay1_ROM_START;
        osInvalICache(overlay1_TEXT_START, text_len);
        osInvalDCache(overlay1_DATA_START, data_len);
        // load overlay1 code from ROM
        dma_read(overlay1_ROM_START, overlay1_TEXT_START, rom_len);
        // zero out bss
        bzero(overlay1_BSS_START, bss_len);
        break;
    }

    if (!text_len) {
        if (!text_len) {
        };
    }; // force stack
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/load_overlay.s")
#endif
