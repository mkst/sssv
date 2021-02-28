#include <ultra64.h>
#include "common.h"


extern u8 D_803BCA70[];
extern u8 D_803BCAA0[];
extern u8 D_803BCAB0[];
extern u8 D_803BCAE0[];
extern u8 D_803BCAF0[];
extern u8 D_803BCB2C[];
extern u8 D_803BCB3C[];
extern u8 D_803BCB78[];
extern u8 D_803BCB88[];
extern u8 D_803BCBB4[];
extern u8 D_803BCBC4[];
extern u8 D_803BCBF0[];
extern u8 D_803BCC00[];
extern u8 D_803BCC28[];
extern u8 D_803BCC38[];
extern u8 D_803BCC60[];
extern u8 D_803BCC70[];
extern u8 D_803BCC9C[];
extern u8 D_803BCCAC[];
extern u8 D_803BCCD8[];
extern u8 D_803BCCE8[];
extern u8 D_803BCD14[];
extern u8 D_803BCD24[];
extern u8 D_803BCD50[];
extern u8 D_803BCD60[];
extern u8 D_803BCD78[];

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/aidata/func_802EA3E0_6FBA90.s")
// NON-MATCHING: maybe 60% there?
// s32 func_802EA3E0_6FBA90(u16 arg0, u16 arg1) {
//     // wierd struct or?
//     s16 sp5E;
//     // s16 sp5C;
//     // s16 sp5A;
//     // s32 sp1C;
//     // s32 sp18;
//
//     u8 temp_t0;
//     u8 temp_t1;
//     struct029 *temp_t2;
//     struct029 *temp_t9;
//
//     // sp1C = arg0;
//     if (arg0 < OB_TYPE_ANIMAL_OFFSET) {
//         // "\nASSERT: X >= OB_TYPE_ANIMAL_OFFSET, %s, %u\n"
//         // "../src/aidata.c"
//         rmonPrintf(&D_803BCA70, &D_803BCAA0, 0x177);
//         *(volatile int*)0 = 0;
//     }
//     if (arg1 < OB_TYPE_ANIMAL_OFFSET) {
//         // "\nASSERT: Y >= OB_TYPE_ANIMAL_OFFSET, %s, %u\n"
//         // "../src/aidata.c"
//         rmonPrintf(D_803BCAB0, D_803BCAE0, 0x178, arg1);
//         *(volatile int*)0 = 0;
//     }
//     if ((arg0 - OB_TYPE_ANIMAL_OFFSET) >= AID_MAX_ANIMALS) {
//         // "\nASSERT: X-OB_TYPE_ANIMAL_OFFSET < AID_MAX_ANIMALS, %s, %u\n"
//         // "../src/aidata.c"
//         rmonPrintf(D_803BCAF0, D_803BCB2C, 0x179, arg1);
//         *(volatile int*)0 = 0;
//     }
//     if ((arg1 - OB_TYPE_ANIMAL_OFFSET) >= AID_MAX_ANIMALS) {
//         // "\nASSERT: Y-OB_TYPE_ANIMAL_OFFSET < AID_MAX_ANIMALS, %s, %u\n"
//         rmonPrintf(D_803BCB3C, D_803BCB78, 0x17A, arg1);
//         *(volatile int*)0 = 0;
//     }
//
//     // ???
//     temp_t9 = &D_803A4B78[arg0];
//     temp_t0 = (temp_t9 - 1)->unk0;
//     temp_t2 = &D_803A4B78[arg1];
//     temp_t1 = (temp_t2 - 1)->unk0;
//
//     if ((temp_t0 == 99) || (temp_t1 == 99) ){
//         return 0;
//     }
//     if ((temp_t0 == 100) || (temp_t1 == 100)) {
//         return 2;
//     }
//
//     if ((D_803F2D70 != (s32)(&D_801D9ED8[arg0] + 0xFFFF0000) + 0x14D6) ||
//         (D_803F2D70 != (s32)(&D_801D9ED8[arg1] + 0xFFFF0000) + 0x14D6)) {
//         return 0;
//     }
//
//     switch (D_803F2D70) {
//         case 0:
//             if (temp_t0 >= MAX_EUROPE_ANIMALS) {
//                 // "\nASSERT: Xl < MAX_EUROPE_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCB88, D_803BCBB4, 0x194, arg1);
//                 *(volatile int*)0 = 0;
//             }
//             if (temp_t1 >= MAX_EUROPE_ANIMALS) {
//                 // "\nASSERT: Yl < MAX_EUROPE_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCBC4, D_803BCBF0, 0x195);
//                 *(volatile int*)0 = 0;
//             }
//             sp5E = D_803A48C0[((((temp_t0 * 4) + temp_t0) * 4) - temp_t0) + temp_t1];
//             break;
//         case 1:
//             if (temp_t0 >= MAX_ICE_ANIMALS) {
//                 // "\nASSERT: Xl < MAX_ICE_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCC00, D_803BCC28, 0x19A, arg1);
//                 *(volatile int*)0 = 0;
//             }
//             if (temp_t1 >= MAX_ICE_ANIMALS) {
//                 // "\nASSERT: Yl < MAX_ICE_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCC38, D_803BCC60, 0x19B);
//                 *(volatile int*)0 = 0;
//             }
//             sp5E = D_803A4ABC[((((temp_t0 * 4) - temp_t0) * 4) - temp_t0) + temp_t1];
//
//             break;
//         case 2:
//             if (temp_t0 >= MAX_DESERT_ANIMALS) {
//                 // "\nASSERT: Xl < MAX_DESERT_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCC70, D_803BCC9C, 0x1A0, arg1);
//                 *(volatile int*)0 = 0;
//             }
//             if (temp_t1 >= MAX_DESERT_ANIMALS) {
//                 // "\nASSERT: Yl < MAX_DESERT_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCCAC, D_803BCCD8, 0x1A1);
//                 *(volatile int*)0 = 0;
//             }
//             sp5E = D_803A4B38[(temp_t0 * 8) + temp_t1];
//             break;
//         case 3:
//             if (temp_t0 >= MAX_JUNGLE_ANIMALS) {
//                 // "\nASSERT: Xl < MAX_JUNGLE_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCCE8, D_803BCD14, 0x1A6, arg1);
//                 *(volatile int*)0 = 0;
//             }
//             if (temp_t1 >= MAX_JUNGLE_ANIMALS) {
//                 // "\nASSERT: Yl < MAX_JUNGLE_ANIMALS, %s, %u\n"
//                 // "../src/aidata.c"
//                 rmonPrintf(D_803BCD24, D_803BCD50, 0x1A7);
//                 *(volatile int*)0 = 0;
//             }
//             sp5E = D_803A4A2C[(((temp_t0 * 4) - temp_t0) * 4) + temp_t1];
//             break;
//         default:
//             // "\nASSERT: FALSE, %s, %u\n"
//             // "../src/aidata.c"
//             rmonPrintf(D_803BCD60, D_803BCD78, 0x1AC, arg1);
//             *(volatile int*)0 = 0;
//             break;
//     }
//
//     return sp5E;
// }
