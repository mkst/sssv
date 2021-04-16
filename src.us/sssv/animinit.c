#include <ultra64.h>
#include "common.h"

extern s32 D_801D9E5C;
extern s32 D_801D9EC4;
extern s32 D_801D9E58;
extern s32 D_801D9E60;
extern s32 D_801D9E64;
extern s32 D_801D9E68;

extern u8  D_800B0B20[];
extern u8  D_000C7A30[];
extern u8  D_000DD5C0[];
extern u8  D_000E75B0[];
extern u8  D_000F1060[];
extern u8  D_000FFD50[];
extern u8  D_00116BD0[];
extern u8  D_00085790[];

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_803800F0_7917A0.s")
// void func_803800F0_7917A0(u8 arg0) {
//     s32 pad[4]; // urgh
//     u32 available;
//     u32 len;
//
//     osWritebackDCacheAll();
//     available = D_800B0B20 - D_80099600;
//     fancy_bzero(D_80099600, available);
//     switch (arg0) {
//     case 5:
//         len = D_00116BD0 - D_000FFD50;
//         if ((available <= len)) {
//             rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0x72, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E5C = D_80099600;
//         dma_read(D_000FFD50, D_80099600, len);
//         D_801D9EC4 = D_801D9E5C;
//         break;
//     case 0:
//         len = D_000DD5C0 - D_000C7A30;
//         if ((available <= len)) {
//             rmonPrintf("\nASSERT: len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0x84, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E58 = D_80099600;
//         dma_read(D_000C7A30, D_80099600, len);
//         D_801D9EC4 = D_801D9E58;
//         break;
//     case 1:
//         len = D_000E75B0 - D_000DD5C0;
//         if ((available > len)) { // huh
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0x96, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E60 = D_80099600;
//         dma_read(D_000DD5C0, D_80099600, len);
//         D_801D9EC4 = D_801D9E60;
//         break;
//     case 2:
//         len = D_000F1060 - D_000E75B0;
//         if ((available > len)) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xA8, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E64 = D_80099600;
//         dma_read(D_000E75B0, D_80099600, len);
//         D_801D9EC4 = D_801D9E64;
//         break;
//     case 3:
//         len = D_000FFD50 - D_000F1060;
//         if ((available > len)) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xBA, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E68 = D_80099600;
//         dma_read(D_000F1060, D_80099600, len);
//         D_801D9EC4 = D_801D9E68;
//         break;
//     case 4: // maybe?
//     case 6:
//         len = D_00085790 - D_0007F790;
//         if (((u32)D_800BA760 - (u32)D_800B0B20) < len) {
//             rmonPrintf("\nASSERT: len <= (_gfxspecificSegmentEnd - _gfxspecificSegmentStart), %s, %u\n", "../src/animinit.c", 0xCE, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E78 = D_800B0B20;
//         dma_read(D_0007F790, D_800B0B20, len);
//         available = D_800B0B20 - D_80099600;
//         len = D_0012A390 - D_00116BD0;
//         if ((available <= len) != 0) {
//             rmonPrintf("\nASSERT: len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), %s, %u\n", "../src/animinit.c", 0xDA, available);
//             *(volatile int*)0 = 0;
//         }
//         D_801D9E6C = D_80099600;
//         dma_read(D_00116BD0, D_80099600, len);
//         D_801D9EC4 = D_801D9E6C;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_80380490_791B40.s")

void func_80380620_791CD0(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    arg0->unk34C = arg1;
    arg0->unk352 = arg2;
    arg0->unk356 = arg3;
    arg0->unk362 = arg4;
}

void func_80380644_791CF4(Animal *arg0) {
    arg0->unk34C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_8038064C_791CFC.s")
// 80% there?
// void func_8038064C_791CFC(void) {
//     s32 temp_v0_2;
//     s32 tmp;
//     s32 phi_v1;
//
//     if (D_803F2D10.unk0 == 0) {
//         if ((D_803D552C->unk358 - 1) < 0) {
//             D_803D552C->unk358 = 0;
//         } else {
//             D_803D552C->unk358 -= 1;
//         }
//         if (D_803D552C->unk358 <= 0) {
//             D_803D552C->unk363 = 0;
//         }
//     }
//     if (D_803D552C->unk363 != 0) {
//         if ((D_803D552C->unk358 >> 1) >= 51) {
//             phi_v1 = 50;
//         } else {
//             phi_v1 = D_803D552C->unk358 >> 1;
//         }
//         func_80380620_791CD0(D_803D552C, 150, 15, phi_v1, 10);
//     }
//     D_803F63E0 = 0;
//     if ((D_803D552C->unk34C != 0) || (D_803D552C->unk34E != 0)) {
//         if (D_803D552C->unk34E != 0) {
//             D_803D552C->unk34E -= 1;
//             tmp = D_80152C78[(((D_803D552C->unk34E << 8) / D_803D552C->unk354) + 64) & 0xFF];
//             temp_v0_2 = (tmp >> 7);
//             temp_v0_2 = (256 - temp_v0_2);
//             temp_v0_2 = (( temp_v0_2 * D_803D552C->unk350) >> 9) + 256;
//             D_803F2EB0 = (D_803F2EB0 * temp_v0_2) >> 8;
//             D_803F2EB4 = (D_803F2EB4 * temp_v0_2) >> 8;
//             D_803F2EB8 = (D_803F2EB8 * temp_v0_2) >> 8;
//
//             tmp = D_80152C78[((D_803D552C->unk34E << 8) / D_803D552C->unk354) & 0xFF];
//             D_803F63E0 = ((tmp >> 7) * D_803D552C->unk350) >> 8;
//         } else {
//             D_803D552C->unk354 = (((((64 - (func_8012826C() & 0x7F)) * D_803D552C->unk362) >> 6) + 64) * D_803D552C->unk352) >> 6;
//             D_803D552C->unk34E = D_803D552C->unk354;
//             D_803D552C->unk350 = (((((64 - (func_8012826C() & 0x7F)) * D_803D552C->unk362) >> 6) + 64) * D_803D552C->unk356) >> 6;
//         }
//         if (D_803D552C->unk34C > 0) {
//             D_803D552C->unk34C -= 1;
//         }
//     }
// }
