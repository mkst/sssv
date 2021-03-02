#include <ultra64.h>

#include "common.h"


void func_80125950(s32 arg0) {
    osInitialize();
    init();
    init2();
}

// crazy multiply/divide code, loading data, decoding? how to match this?!
#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80125980.s")
#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80125FE0.s")

void func_8012635C(s32 arg0, s32 arg1, s32 arg2[]) {
    arg2[0] = (arg0 & 0xFFFF0000) | ((arg1 >> 16) & 0xFFFF);
    arg2[8] = (arg0 << 16) | (arg1 & 0xFFFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80126388.s")

// wierd offsets
#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80126CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80126FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80127640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80127994.s")

// matrix?
#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80127D30.s")


#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80127ED4.s")
// help...
// void func_80127ED4(s32 arg0[4][4], s32 arg1) {
//     s32 sp4;
//     s32 sp0;
//
//     sp0 = 0;
//     sp4 = 0xFFFF0000;
//
//     // what is this macro?
//     arg0[0][0] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[2][0] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp0 = 0;
//     sp4 = 0;
//     arg0[0][1] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[2][1] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp0 = 0x10000;
//     sp4 = 0;
//     arg0[0][2] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[2][2] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp0 = 0;
//     sp4 = 0;
//     arg0[0][3] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[2][3] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp0 = 0;
//     sp4 = 0;
//     arg0[1][0] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[3][0] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp0 = 0;
//     sp4 = 0x10000;
//     arg0[1][1] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[3][1] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp4 = arg1 << 17;
//     sp0 = 0;
//     arg0[1][2] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[3][2] = ((u16)sp4 << 16) | (u16) sp0;
//
//     sp0 = 0x10000;
//     sp4 = 0;
//     arg0[1][3] = ((u16)sp4 << 16) | (u16) sp0;
//     arg0[3][3] = ((u16)sp4 << 16) | (u16) sp0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_1050/func_80128078.s")
