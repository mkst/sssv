#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_803800F0_7917A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_80380490_791B40.s")

void func_80380620_791CD0(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    arg0->unk34C = arg1;
    arg0->unk352 = arg2;
    arg0->unk356 = arg3;
    arg0->unk362 = arg4;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_80380644_791CF4.s")
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

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_80380920_791FD0.s")

void func_80321920_732FD0(void *arg0, s16 arg1, s16 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_80381C60_793310.s")
// void func_80381C60_793310(void) {
//     s16 temp_a0;
//     s16 temp_a0_2;
//     s16 temp_v1_7;
//     s32 temp_a3;
//     void *temp_a3_2;
//     void *temp_v0;
//     void *temp_v0_2;
//     void *temp_v0_3;
//     void *temp_v0_4;
//     void *temp_v0_5;
//     void *temp_v1;
//     void *temp_v1_10;
//     void *temp_v1_2;
//     void *temp_v1_3;
//     void *temp_v1_4;
//     void *temp_v1_5;
//     void *temp_v1_6;
//     void *temp_v1_8;
//     void *temp_v1_9;
//     void *phi_return;
//     void *phi_return_2;
//
//     temp_a3 = D_803D552C->unk320;
//     if (temp_a3 == NULL) {
//         D_803D552C->unk320 = func_803213B0_732A60(); //temp_a3, 0, temp_a3);
//         temp_v1 = D_803D552C;
//         temp_a3_2 = temp_v1->unk320;
//         if (temp_a3_2 != 0) {
//             temp_v1->unk308 = (u16) temp_a3_2->unk42;
//             func_8032AAF0_73C1A0(0x19);
//             temp_v1_2 = D_803D552C;
//             temp_v1_2->unkC = (s16) (temp_v1_2->unkC - temp_v1_2->unk308);
//             if ((*(void *)0x803D5530)->unk160 == 2) {
//                 temp_v1_3 = D_803D552C;
//                 temp_v1_4 = D_803D552C;
//                 temp_a0 = temp_v1_4->unkC;
//                 if ((func_80310F58_722608(temp_v1_3->unk4, temp_v1_3->unk8) >> 0x10) < (s32) temp_a0) {
//                     temp_v1_4->unkC = temp_a0;
//                 } else {
//                     D_803D552C->unkC = (s16) (func_80310F58_722608(temp_v1_4->unk4, temp_v1_4->unk8) >> 0x10);
//                 }
//             } else {
//                 temp_v1_5 = D_803D552C;
//                 temp_v1_6 = D_803D552C;
//                 temp_a0_2 = temp_v1_6->unkC;
//                 if ((func_8031124C_7228FC(temp_v1_5->unk4, temp_v1_5->unk8) >> 0x10) < (s32) temp_a0_2) {
//                     temp_v1_6->unkC = temp_a0_2;
//                 } else {
//                     D_803D552C->unkC = (s16) (func_8031124C_7228FC(temp_v1_6->unk4, temp_v1_6->unk8) >> 0x10);
//                 }
//             }
//         }
//         phi_return_2 = &D_803D5528;
//         if (D_803D5530->unk162 == 2) {
//             temp_v0 = D_803D5528;
//             temp_v1_7 = temp_v0->unk2E4;
//             phi_return_2 = temp_v0;
//             if ((s32) temp_v1_7 >= 0x191) {
//                 temp_v0->unk2E4 = (s16) (temp_v1_7 - 0x190);
//                 if (func_803224C4_733B74(-0x3A, 0, 0, 0x1D, 0x14, 0, 0, 0xB) != 0) {
//                     temp_v0_2 = D_803D5530;
//                     func_8032C360_73DA10(0x44, 0x5000, 0, temp_v0_2->unk4, (?32) temp_v0_2->unk8, (?32) temp_v0_2->unkC, 1.0f);
//                     temp_v0_3 = D_803D5530;
//                     temp_v0_3->unk24 = (s16) (temp_v0_3->unk24 + 2);
//                 } else {
//                     temp_v0_4 = D_803D5530;
//                     func_8032C360_73DA10(0x4F, 0x5000, 0, temp_v0_4->unk4, (?32) temp_v0_4->unk8, (?32) temp_v0_4->unkC, 1.0f);
//                 }
//                 temp_v1_8 = D_803D552C;
//                 phi_return_2 = phi_return;
//                 if (temp_v1_8->unk365 == 0) {
//                     temp_v1_8->unk365 = (u8)0x12U;
//                     D_803D552C->unk32A = (u16) *(void *)0x803D5544;
//                     return;// phi_return;
//                 }
//             }
//         }
//     } else {
//         func_80321920_732FD0(temp_a3, 0, 0); //, temp_a3);
//         temp_v0_5 = D_803D5530;
//         func_8032C360_73DA10(0x63, 0x5000, 0, temp_v0_5->unk4, (?32) temp_v0_5->unk8, (?32) temp_v0_5->unkC, D_803BF3E0);
//         temp_v1_9 = D_803D552C;
//         temp_v1_9->unkC = (s16) (temp_v1_9->unkC + temp_v1_9->unk308);
//         temp_v1_10 = D_803D552C;
//         temp_v1_10->unk18 = (s16) (temp_v1_10->unk18 + temp_v1_10->unk308);
//         func_8032AAF0_73C1A0(0);
//     }
//     // return phi_return_2;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animinit/func_80381F14_7935C4.s")
