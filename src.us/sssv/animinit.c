#include <ultra64.h>
#include "common.h"

extern u8  *D_801D9E58;
extern u8  *D_801D9E5C;
extern u8  *D_801D9E60;
extern u8  *D_801D9E64;
extern u8  *D_801D9E68;
extern u8  *D_801D9EC4;

extern u8  D_800B0B20[];

extern u8  D_00085790[];
extern u8  D_000C7A30[];
extern u8  D_000DD5C0[];
extern u8  D_000E75B0[];
extern u8  D_000F1060[];
extern u8  D_000FFD50[];
extern u8  D_00116BD0[];

extern char D_803BF364_7D0A14[];


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/load_data_section.s")
// void load_data_section(u8 arg0) {
//     s32 pad[4]; // urgh
//     u32 available;
//     u32 len;
//
//     osWritebackDCacheAll();
//     available = D_800B0B20 - D_80099600;
//     bzero_sssv(D_80099600, available);
//
//     switch (arg0) {
//     case 0:
//         len = D_00116BD0 - D_000FFD50;
//         if ((len >= available)) {
//             rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0x72, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E5C = D_80099600;
//         dma_read(D_000FFD50, &D_80099600, len);
//         D_801D9EC4 = D_801D9E5C;
//     case 1:
//         len = D_000DD5C0 - D_000C7A30;
//         if (len >= available) {
//             rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0x84, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E58 = D_80099600;
//         dma_read(D_000C7A30, &D_80099600, len);
//         D_801D9EC4 = D_801D9E58;
//         break;
//     case 2:
//         len = D_000E75B0 - D_000DD5C0;
//         if ((len > available)) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0x96, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E60 = D_80099600;
//         dma_read(D_000DD5C0, &D_80099600, len);
//         D_801D9EC4 = D_801D9E60;
//         break;
//
//     case 3:
//         len = D_000F1060 - D_000E75B0;
//         if ((len > available)) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xA8, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E64 = D_80099600;
//         dma_read(D_000E75B0, &D_80099600, len);
//         D_801D9EC4 = D_801D9E64;
//         break;
//     case 5:
//         len = D_000FFD50 - D_000F1060;
//         if ((len > available)) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xba, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E68 = D_80099600;
//         dma_read(D_000F1060, &D_80099600, len);
//         D_801D9EC4 = D_801D9E68;
//         break;
//         // len = D_00116BD0 - D_000FFD50;
//         // if ((len > available)) {
//         //     rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xba, available);
//         //     *(volatile int*)0 = 0;
//         // }
//         // D_801D9E5C = D_80099600;
//         // dma_read(D_000FFD50, &D_80099600, len);
//         // D_801D9EC4 = D_801D9E5C;
//         // break;
//     case 6:
//         len = D_00085790 - D_0007F790;
//         if (((u8*)D_800BA760 - D_800B0B20) < len) {
//             rmonPrintf("\nASSERT: len <= (_gfxspecificSegmentEnd - _gfxspecificSegmentStart), %s, %u\n", "../src/animinit.c", 0xCE, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E78 = D_800B0B20;
//         dma_read(D_0007F790, D_800B0B20, len);
//         len = D_0012A390 - D_00116BD0;
//         if (len > available) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xDA, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E6C = D_80099600;
//         dma_read(D_00116BD0, &D_80099600, len);
//         D_801D9EC4 = D_801D9E6C;
//         break;
//     case 4:
//         break;
//     }
// }

void func_80380490_791B40(Gfx **arg0, s32 arg1) {
    switch (D_803F2D70) {
    case 5:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E5C));
        break;
    case 0:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E58));
        break;
    case 1:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E60));
        break;
    case 2:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E64));
        break;
    case 3:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E68));
        break;
    case 6:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E6C));
        break;
    default:
        rmonPrintf(D_803BF364_7D0A14, arg0); // "Undefined segment - hware.c\n"
        break;
    }
}
