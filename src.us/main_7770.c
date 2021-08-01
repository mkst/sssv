#include <ultra64.h>

#include "common.h"

extern u8 overlay1_ROM_START[];
extern u8 overlay1_ROM_END[];
extern u8 overlay1_TEXT_START[];

extern u8 overlay2_ROM_START[];
extern u8 overlay2_TEXT_START[];
extern u8 overlay2_ROM_END[];

extern u8 overlay1_data_VRAM[];
extern u8 overlay2_data_VRAM[];
// extern u8 D_80302E60[]; // overlay1 bss start
// extern u8 D_803C0420[]; // overlay2 bss start
extern u8 D_803B05A0[]; // overlay1 bss end
extern u8 D_803FDEC0[]; // overlay2 bss end

// #ifdef NON_MATCHING
// // regalloc but functionally equivalent
// void load_overlay(u8 arg0) {
//     s32 pad[2];
//     s32 len1;
//     s32 len2;
//     s32 len3;
//     s32 len4;
//
//     // stop all sounds
//     func_80133738();
//
//     switch(arg0){
//     case 0: // overlay 2
//         len1 = overlay2_data_VRAM - overlay2_TEXT_START;
//         len2 = (u8*)D_803C0420 - (u8*)overlay2_data_VRAM;
//         len3 = overlay2_ROM_END - overlay2_ROM_START;
//         len4 = D_803FDEC0 - (u8*)D_803C0420;
//
//         osInvalICache(overlay2_TEXT_START, len1);
//         osInvalDCache(overlay2_data_VRAM, len2);
//         dma_read(overlay2_ROM_START, func_80294E50_6A6500, len3);
//         // zero out bss
//         bzero((u8*)D_803C0420, len4);
//
//         break;
//     case 1: // overlay 1
//         len1 = overlay1_data_VRAM - overlay1_TEXT_START;
//         len2 = (u8*)D_80302E60 - overlay1_data_VRAM;
//         len3 = overlay1_ROM_END - overlay1_ROM_START;
//         len4 = D_803B05A0 - (u8*)D_80302E60;
//
//         osInvalICache(overlay1_TEXT_START, len1);
//         osInvalDCache(overlay1_data_VRAM, len2);
//         dma_read(overlay1_ROM_START, func_80294E50_6384F0, len3);
//         // zero out bss
//         bzero((u8*)D_80302E60, len4);
//         break;
//     }
//
//     if (!len1) {};
// }
// #else
#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/load_overlay.s")
// #endif
