#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714500/func_80302E50_714500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714500/func_8030322C_7148DC.s")
// likely uses macro as whitespace affects codegen :(
// void func_8030322C_7148DC(s16 arg0, s32 arg1) {
//     s32 tmp4;
//     s32 tmp2;
//
//     s32 temp_t6;
//     s32 temp_t2;
//
//     tmp2 = D_80203FE0[arg0].unk2;
//     tmp4 = D_80203FE0[arg0].unk4;
//
//     temp_t6 = D_80152C78[arg1 & 0xFF] >> 7;
//     temp_t2 = D_80152C78[(arg1 + 64) & 0xFF] >> 7;
//
//     D_80203FE0[arg0].unk2 = ((temp_t6 * tmp4) + (temp_t2 * tmp2)) >> 8;
//     D_80203FE0[arg0].unk4 = ((tmp4 * temp_t2) - (temp_t6 * tmp2)) >> 8;
// }

#ifdef NON_MATCHING // JUSTREG
// permuter matches if via dereferencing temp_t8...
void func_803032DC_71498C(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;
    s16 temp_t1;
    s32 temp_t8;
    s32 temp_t9;

    temp_v0 = D_80203FE0[arg0].unk2 - D_80203FE0[arg1].unk2;
    temp_t1 = D_80203FE0[arg0].unk4 - D_80203FE0[arg1].unk4;

    temp_t8 = D_80152C78[arg2 & 0xFF] >> 7;
    temp_t9 = D_80152C78[(arg2 + 64) & 0xFF] >> 7;

    D_80203FE0[arg0].unk2 = D_80203FE0[arg1].unk2 + (((temp_t8 * temp_t1) + (temp_v0 * temp_t9)) >> 8);
    D_80203FE0[arg0].unk4 = D_80203FE0[arg1].unk4 + (((temp_t1 * temp_t9) - (temp_t8 * temp_v0)) >> 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714500/func_803032DC_71498C.s")
#endif

#ifdef NON_MATCHING // JUSTREG
// same as previous
void func_803033D4_714A84(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_t1;
    s16 temp_v0;
    s32 temp_t8;
    s32 temp_t9;

    temp_v0 = D_80203FE0[arg0].unk0 - D_80203FE0[arg1].unk0;
    temp_t1 = D_80203FE0[arg0].unk2 - D_80203FE0[arg1].unk2;
    temp_t8 = D_80152C78[arg2 & 0xFF] >> 7;
    temp_t9 = D_80152C78[(arg2 + 64) & 0xFF] >> 7;
    D_80203FE0[arg0].unk0 = (((temp_t8 * temp_t1) + (temp_v0 * temp_t9)) >> 8) + D_80203FE0[arg1].unk0;
    D_80203FE0[arg0].unk2 = (((temp_t1 * temp_t9) - (temp_t8 * temp_v0)) >> 8) + D_80203FE0[arg1].unk2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714500/func_803033D4_714A84.s")
#endif
