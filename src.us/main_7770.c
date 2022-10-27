#include <ultra64.h>

#include "common.h"

extern u8 overlay1_ROM_START[];
extern u8 overlay1_ROM_END[];

extern u8 overlay1_TEXT_START[];
extern u8 overlay1_TEXT_END[];

extern u8 overlay2_ROM_START[];
extern u8 overlay2_ROM_END[];

extern u8 overlay2_TEXT_START[];
extern u8 overlay2_TEXT_END[];

extern u8 overlay1_data_VRAM[];
extern u8 overlay2_data_VRAM[];

extern u8 overlay1_data_VRAM_end[]; // D_80302E60
extern u8 overlay2_data_VRAM_end[]; // D_803C0420

extern u8 overlay1_BSS_START[]; // D_80302E60
extern u8 overlay2_BSS_START[]; // D_803C0420

extern u8 overlay1_BSS_END[];      // D_803B05A0
extern u8 fake_overlay2_BSS_END[]; // D_803FDEC0

#if 0
//ifdef NON_MATCHING
// VRAM offsets are gone from linker script :(
// just reg, but something is wrong
void load_overlay(u8 arg0) {
    s32 pad[2];
    u32 len;

    stop_all_sounds();

    switch(arg0) {
    case 0: // overlay 2
        len = overlay2_TEXT_END - overlay2_TEXT_START;

        osInvalICache(overlay2_TEXT_START, overlay2_TEXT_END - overlay2_TEXT_START);
        osInvalDCache(overlay2_data_VRAM, overlay2_data_VRAM_end - overlay2_data_VRAM);
        // load overlay2 code from ROM
        dma_read(overlay2_ROM_START, overlay2_TEXT_START, overlay2_ROM_END - overlay2_ROM_START);
        // zero out bss
        bzero(overlay2_BSS_START, fake_overlay2_BSS_END - overlay2_BSS_START);
        break;
    case 1: // overlay 1
        len = overlay1_TEXT_END - overlay1_TEXT_START;

        osInvalICache(overlay1_TEXT_START, len);
        osInvalDCache(overlay1_data_VRAM, overlay1_data_VRAM_end - overlay1_data_VRAM);
        // load overlay1 code from ROM
        dma_read(overlay1_ROM_START, overlay1_TEXT_START, overlay1_ROM_END - overlay1_ROM_START);
        // zero out bss
        bzero(overlay1_BSS_START, overlay1_BSS_END - overlay1_BSS_START);
        break;
    }

    if (!len) {
        if (!len) {
        }
    }; // force stack
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/load_overlay.s")
#endif
