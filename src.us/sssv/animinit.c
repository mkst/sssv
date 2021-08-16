#include <ultra64.h>
#include "common.h"

extern u8  *D_801D9E58;
extern u8  *D_801D9E5C;
extern u8  *D_801D9E60;
extern u8  *D_801D9E64;
extern u8  *D_801D9E68;
extern u8  *D_801D9EC4;

extern u8  D_800B0B20[];

extern u8  data_7F790_ROM_END[];

extern u8  data_C7A30_ROM_START[];
extern u8  data_C7A30_ROM_END[];

extern u8  data_DD5C0_ROM_START[];
extern u8  data_DD5C0_ROM_END[];
extern u8  data_E75B0_ROM_START[];
extern u8  data_E75B0_ROM_END[];
extern u8  data_F1060_ROM_START[];
extern u8  data_F1060_ROM_END[];
extern u8  data_FFD50_ROM_START[];
extern u8  data_FFD50_ROM_END[];
extern u8  data_116BD0_ROM_START[];
extern u8  data_116BD0_ROM_END[];
extern char D_803BF364_7D0A14[];

extern u8  data_7F790_ROM_START[];


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/load_data_section.s")
// void load_data_section(u8 arg0) {
//     char *new_var;
//     u32 available, available2;
//     s32 len;
//     s32 pad[2]; // urgh
//
//     available = D_800B0B20 - D_80099600;
//     osWritebackDCacheAll();
//     bzero_sssv(D_80099600, available);
//
//     new_var = "../src/animinit.c";
//
//     switch (arg0) {
//     case 5:
//         // city animals?
//         if (((len = data_FFD50_ROM_END - data_FFD50_ROM_START) >= available)) {
//             rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", new_var, 0x72);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E5C[0] = D_80099600;
//         dma_read(data_FFD50_ROM_START, D_80099600, len);
//         D_801D9EC4 = D_801D9E5C;
//         break;
//     case 0:
//         // europe animals (?)
//         if ((len = data_C7A30_ROM_END - data_C7A30_ROM_START) >= available) {
//             rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", new_var, 0x84);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E58[0] = D_80099600;
//         dma_read(data_C7A30_ROM_START, D_80099600, len);
//         D_801D9EC4 = D_801D9E58;
//         break;
//     case 1:
//         // ice animals
//         if ((len = data_DD5C0_ROM_END - data_DD5C0_ROM_START) > available) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", new_var, 0x96);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E60[0] = D_80099600;
//         dma_read(data_DD5C0_ROM_START, D_80099600, len);
//         D_801D9EC4 = D_801D9E60;
//         break;
//
//     case 2:
//         // desert animals
//         if ((len = data_E75B0_ROM_END - data_E75B0_ROM_START) > available) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", new_var, 0xA8);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E64[0] = D_80099600;
//         dma_read(data_E75B0_ROM_START, D_80099600, len);
//         D_801D9EC4 = D_801D9E64;
//         break;
//     case 3:
//         // jungle animals
//         if ((len = data_F1060_ROM_END - data_F1060_ROM_START) > available) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", new_var, 0xBA);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E68[0] = D_80099600;
//         dma_read(data_F1060_ROM_START, D_80099600, len);
//         D_801D9EC4 = D_801D9E68;
//         break;
//     case 6:
//         // dan
//         available2 = ((u8*)D_800BA760 - D_800B0B20);
//         if ((len = data_7F790_ROM_END - data_7F790_ROM_START) > available2) {
//             rmonPrintf("\nASSERT: len <= (_gfxspecificSegmentEnd - _gfxspecificSegmentStart), %s, %u\n", new_var, 0xCE);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E78[0] = D_800B0B20;
//         dma_read(data_7F790_ROM_START, D_800B0B20, len);
//
//         // menu
//         if ((len = data_116BD0_ROM_END - data_116BD0_ROM_START) > available) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", new_var, 0xDA);
//             *(volatile s32*)NULL = 0;
//         }
//         D_801D9E6C[0] = D_80099600;
//         dma_read(data_116BD0_ROM_START, D_80099600, len);
//         D_801D9EC4 = D_801D9E6C;
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
