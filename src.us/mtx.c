#include <ultra64.h>

#include "common.h"

// crazy multiply/divide code, matrix math?
#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80125980.s")
#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80125FE0.s")

void func_8012635C(s32 arg0, s32 arg1, Mtx *arg2) {
    arg2->m[0][0] = (arg0 & 0xFFFF0000) | ((arg1 >> 16) & 0xFFFF);
    arg2->m[2][0] = (arg0 << 16) | (arg1 & 0xFFFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80126388.s")

// wierd offsets
#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80126CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80126FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80127640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80127994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80127D30.s")
// same issue as func_80127ED4
// void func_80127D30(Mtx *arg0, u16 arg1) {
//     s32 sp0[2];
//     s32* m1 = (s32*)&arg0->m[0][0];
//     s32* m2 = (s32*)&arg0->m[2][0];
//
//     sp0[1] = FTOFIX32(1.0);
//     sp0[0] = 0;
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = FTOFIX32(1.0);
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = FTOFIX32(-1.0);
//     sp0[0] = 0;
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = 0;
//     sp0[0] = 0;
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//
//     sp0[1] = arg1 << 17;
//     sp0[0] = FTOFIX32(1.0);
//     *m1++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
//     *m2++ = (((u16) sp0[1] << 0x10) | (u16) sp0[0]);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80127ED4.s")
// offsets are wrong...
// void func_80127ED4(Mtx *arg0, s16 arg1) {
//     s32 tmp[2];
//
//     tmp[0] = 0;
//     tmp[1] = FTOFIX32(-1.0);
//     arg0->m[0][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[2][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0;
//     arg0->m[0][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[2][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = FTOFIX32(1.0);
//     tmp[1] = 0;
//     arg0->m[0][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[2][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0;
//     arg0->m[0][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[2][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = 0;
//     arg0->m[1][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[3][0] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = 0;
//     tmp[1] = FTOFIX32(1.0);
//     arg0->m[1][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[3][1] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[1] = arg1 << 17;
//     tmp[0] = 0;
//     arg0->m[1][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[3][2] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//
//     tmp[0] = FTOFIX32(1.0);
//     tmp[1] = 0;
//     arg0->m[1][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
//     arg0->m[3][3] = ((u16)tmp[1] << 16) | (u16) tmp[0];
// }

#pragma GLOBAL_ASM("asm/nonmatchings/mtx/func_80128078.s")
// nonsense
// void func_80128078(Mtx *arg0, s16 arg1, s16 arg2) {
//     u32 sp44;
//     s32 sp40;
//     u32 sp3C;
//     s32 sp38;
//     s16 unksp36;
//     u32 sp34;
//     s16 unksp32;
//     u32 sp30;
//     void *sp2C;
//     s32 sp24;
//     s32 sp20;
//     Mtx mtx;
//     s32 temp_a0;
//     s32 temp_v0;
//     u32 temp_v1;
//     u32 temp_v1_2;
//
//     sp44 = (s64)D_80152350.unk2D0[arg2] << 8;
//     temp_v1_2 = (s64)D_80152350.unk384[arg2] << 8;
//
//     sp34 = FTOFIX32(1.0);
//     // sp38 = temp_v0;
//     sp3C = temp_v1_2;
//     arg0->m[0][0] = (s32) ((u16) sp34 << 0x10); // unk0
//     arg0->m[0][1] = 0; // unk4
//
//     arg0->m[2][1] = 0; // unk24
//     arg0->m[2][0] = (s32) (unksp36 << 0x10); // unk20
//
//     sp30 = temp_v1_2;
//     arg0->m[0][2] = (s32) (u16) sp30; // unk8
//     arg0->m[2][2] = (s32) unksp32; // unk28
//
//     sp34 = sp44;
//     arg0->m[0][3] = (s32) ((u16) sp34 << 0x10); // unkC
//     arg0->m[2][3]  = (s32) (unksp36 << 0x10); // unk2C
//
//     sp30 = (u32) -(s32) sp44;
//     arg0->m[1][0] = (s32) (u16) sp30; // unk10
//     arg0->m[3][0] = (s32) unksp32; // unk30
//
//     sp34 = temp_v1_2;
//     arg0->m[1][1] = (s32) ((u16) sp34 << 0x10); // unk14
//     arg0->m[3][1] = (s32) (unksp36 << 0x10); // unk34
//
//     temp_a0 = (s32) arg1 >> 0x1F;
//     // sp20 = temp_a0;
//     // sp24 = (s32) arg1;
//     sp30 = (u32) (s64)arg1 * sp44; //__ll_mul(temp_a0, arg1, sp40, sp44);
//
//     arg0->m[1][2] = (s32) (u16) sp30; // unk18
//     arg0->m[3][2] = (s32) unksp32; // unk38
//
//     sp34 = (arg1 << 0x10) - (s64)arg1 * sp3C; // (u32) __ll_mul(temp_a0, arg1, sp38, sp3C);
//     arg0->m[1][3] = (s32) (((u16) sp34 << 0x10) | 1); // unk1C
//     arg0->m[3][3] = (s32) (unksp36 << 0x10); // unk3C
// }
