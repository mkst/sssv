#include <ultra64.h>

#include "common.h"

// crazy multiply/divide code, loading data, decoding? how to match this?!
#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80125980.s")
#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80125FE0.s")

void func_8012635C(s32 arg0, s32 arg1, s32 arg2[4][4]) {
    arg2[0][0] = (arg0 & 0xFFFF0000) | ((arg1 >> 16) & 0xFFFF);
    arg2[2][0] = (arg0 << 16) | (arg1 & 0xFFFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80126388.s")

// wierd offsets
#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80126CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80126FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80127640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80127994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80127D30.s")
// same issue as func_80127ED4
// void func_80127D30(Mtx *arg0, u16 arg1) {
//     s32 sp0[2];
//     s32* m1 = (s32*)&arg0->m[0][0];
//     s32* m2 = (s32*)&arg0->m[2][0];
//
//     sp0[1] = 0x10000;
//     sp0[0] = 0;
//     m1[0] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[0] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     m1[1] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[1] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0x10000;
//     m1[2] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[2] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     m1[3] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[3] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     m1[4 + 0] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[4 + 0] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0xFFFF0000;
//     sp0[0] = 0;
//     m1[4 + 1] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[4 + 1] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     m1[4 + 2] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[4 + 2] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = arg1 << 17;
//     sp0[0] = 0x10000;
//     m1[4 + 3] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     m2[4 + 3] = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80127ED4.s")
// offsets are wrong...
// void func_80127ED4(s32 arg0[4][4], s16 arg1) {
//     s32 tmp[2];
//
//     tmp[0] = 0;
//     tmp[1] = 0xFFFF0000;
//     arg0[0][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[2][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0;
//     arg0[0][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[2][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0x10000;
//     tmp[1] = 0;
//     arg0[0][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[2][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0;
//     arg0[0][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[2][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0;
//     arg0[1][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[3][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0x10000;
//     arg0[1][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[3][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[1] = arg1 << 17;
//     tmp[0] = 0;
//     arg0[1][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[3][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0x10000;
//     tmp[1] = 0;
//     arg0[1][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0[3][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_1080/func_80128078.s")
