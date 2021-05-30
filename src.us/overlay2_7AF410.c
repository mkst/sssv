#include <ultra64.h>

#include "common.h"


// initialise/reset
void func_8039DD60_7AF410(void) {
    D_803FDEA0 = 0; // structs used = 0
    bzero_sssv((u8*)D_803F7E10, sizeof(D_803F7E10)); // 24720
}

void func_8039DD90_7AF440(u8 *arg0) {
    *arg0 = (*arg0 & 0xFFF0) | 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039DDA4_7AF454.s")
// miles away
// struct045 *func_8039DDA4_7AF454(s32 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, u8 argF, u8 arg10, u8 arg11, s32 arg12) {
//     s32 temp_t9;
//     s8 temp_t5;
//     u8 temp_t8;
//     struct045 *temp_v1;
//     s16 i;
//
//     if (arg12 != 0) {
//         for (i = 0; i < 30; i++) {
//             temp_v1 = &D_803F7E10[i];
//             if ((arg12 == temp_v1->unk4) && ((temp_v1->unk0.uw >> 28) != 0) && ((temp_v1->unk0.ub[0] & 0xF) != 2)) {
//                 temp_v1->unk0.ub[1] = (temp_v1->unk0.ub[1] & 0xFFF0) | 1;
//                 return temp_v1;
//             }
//         }
//     }
//
//     for (i = 0; i < 30; i++) {
//         temp_v1 = &D_803F7E10[i];
//         if ((temp_v1->unk0.uw >> 28) == 0) {
//             temp_v1->unk248 = arg0;
//             temp_t5 = (temp_v1->unk0.ub[0] & 0xFF0F) | 0x10;
//             temp_v1->unk0.ub[0] = temp_t5;
//             temp_v1->unk0.ub[0] =  ((temp_t5 & 0xF0) | 1);
//             temp_t8 = (arg11 * 0x10) | (temp_v1->unk0.ub[1] & 0xFF0F);
//             temp_t9 = temp_t8 & 0xF0;
//             temp_v1->unk0.ub[1] = temp_t8;
//             temp_v1->unk8 = (((arg1 &0xff) * 0x10) | (temp_v1->unk8 & 0xFF0F));
//             temp_v1->unk10 = arg9;
//             temp_v1->unk11 = argA;
//             temp_v1->unk0.ub[1] = temp_t9 | 1;
//             temp_v1->unk242 = arg5;
//             temp_v1->unk240 = arg4;
//             temp_v1->unk244 = arg6;
//             temp_v1->unk13 = argC;
//             temp_v1->unkE = arg7;
//             temp_v1->unkF = arg8;
//             temp_v1->unk12 = argB;
//             temp_v1->unk14 = argD;
//             temp_v1->unk4 = arg12;
//             temp_v1->unkB = 0;
//             temp_v1->unkC = 0;
//             temp_v1->unkD = arg2;
//             temp_v1->unk17 = 0x80 / (arg3 * arg10);
//             temp_v1->unk18 = arg10;
//             temp_v1->unk15 = argE;
//             temp_v1->unk16 = argF;
//             D_803FDEA0 += 1;
//             return temp_v1;
//         }
//     }
//     return i;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039DFD4_7AF684.s")
// struct045 *func_8039DFD4_7AF684(Animal *arg0 /* a guess */, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, s32 argF) {
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s8 temp_t8;
//     u8 temp_t4;
//     struct045 *temp_v1;
//     s16 i;
//
//     if (argF != 0) {
//         for (i = 0; i < 30; i++) {
//             temp_v1 = &D_803F7E10[i];
//             if ((argF == temp_v1->unk4) && ((temp_v1->unk0.uw >> 0x1C) != 0) && ((temp_v1->unk0.ub[0] & 0xF) != 2)) {
//                 temp_v1->unk0.ub[1] = ((temp_v1->unk0.ub[1] & 0xFFF0) | 1);
//                 return temp_v1;
//             }
//         }
//         if ((arg0->xVelocity | arg0->zVelocity) == 0) {
//             return NULL;
//         }
//     }
//
//     for (i = 0; i < 30; i++) {
//         temp_v1 = &D_803F7E10[i];
//         if (((u32) temp_v1->unk0.uw >> 0x1C) == 0) {
//             temp_v1->unk330 = arg0;
//             temp_t8 = ((u8) temp_v1->unk0.ub[0] & 0xFF0F) | 0x30;
//             temp_v1->unk0.uw = temp_t8;
//             temp_t4 = (argE * 0x10) | (temp_v1->unk0.ub[1] & 0xFF0F);
//             temp_v1->unk0.ub[0] = (s8) ((temp_t8 & 0xF0) | 1);
//             temp_v1->unk32C = arg6;
//             temp_v1->unk0.ub[1] = temp_t4;
//             temp_v1->unkE = arg7;
//             temp_v1->unkF = arg8;
//             temp_v1->unk0.ub[1] = (u8) ((temp_t4 & 0xF0) | 1);
//             temp_v1->unk8 = (u8) (((arg1 & 0xFF) * 0x10) | (temp_v1->unk8 & 0xFF0F));
//             temp_v1->unk328 = arg4;
//             temp_v1->unk11 = argA;
//             temp_v1->unk32A = arg5;
//             temp_v1->unk10 = arg9;
//             temp_v1->unk12 = argB;
//             temp_v1->unk4 = argF;
//             temp_v1->unkB = (u8)0;
//             temp_v1->unkC = (u8)0;
//             temp_v1->unkD = (s8) (arg2 & 0xFF);
//             temp_v1->unk14 = (s8) (0x80 / (s32) (((arg3 & 0xFF) - 2) * argD));
//             D_803FDEA0 = (s16) (D_803FDEA0 + 1);
//             temp_v1->unk15 = argD;
//             temp_v1->unk13 = argC;
//             return temp_v1;
//         }
//     }
//     return (void *) temp_v0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E20C_7AF8BC.s")
// similar to previous
// void *func_8039E20C_7AF8BC(s32 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD) {
//     s32 temp_t8;
//     s8 temp_t7;
//     struct045 *temp_v1;
//     s16 i;
//
//     for (i = 0 ; i < 30; i++) {
//         temp_v1 = &D_803F7E10[i];
//         if ((temp_v1->unk0.uw >> 0x1C) == 0) {
//             temp_t7 = (temp_v1->unk0.ub[0] & 0xFF0F) | 64;
//             temp_t8 = temp_t7 & 0xF0;
//             temp_v1->unk0.ub[0] = temp_t7;
//             temp_v1->unk0.ub[1] = (argD * 0x10) | (temp_v1->unk0.ub[1] & 0xFF0F);
//             temp_v1->unk248 = arg0;
//             temp_v1->unk0.ub[0] = temp_t8 | 1;
//             temp_v1->unk242 = arg5;
//             temp_v1->unk8 = (((arg1 & 0xFF) * 0x10) | (temp_v1->unk8 & 0xFF0F));
//             temp_v1->unk240 = arg4;
//             temp_v1->unk244 = arg6;
//             temp_v1->unk9 = 0;
//             temp_v1->unkA = 0;
//             temp_v1->unkB = arg2;
//             temp_v1->unk12 = arg3;
//             D_803FDEA0 += 1;
//             temp_v1->unkC = arg7;
//             temp_v1->unkD = arg8;
//             temp_v1->unkE = arg9;
//             temp_v1->unkF = argA;
//             temp_v1->unk10 = argB;
//             temp_v1->unk11 = argC;
//             return temp_v1;
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E33C_7AF9EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E6D4_7AFD84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039EBFC_7B02AC.s")
