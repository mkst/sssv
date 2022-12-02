#include <ultra64.h>
#include "common.h"

#if 0
// miles away, structs need to be figured out
void func_803034D0_714B80(Animal *arg0, u16 arg1, s16 arg2, u16 arg3) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp34;
    s32 sp28;

    s16 temp_t9;
    s16 temp_t9_2;

    temp_t9 = D_80152C78[(arg0->unk302 + 0x40) & 0xFF] >> 8;
    temp_t9_2 = D_80152C78[(arg0->unk302 & 0xFF)] >> 8;

    sp4C = ((D_80203FE0[1].unk2 * temp_t9_2) + (D_80203FE0[1].unk0 * temp_t9)) >> 7;
    sp48 = ((D_80203FE0[1].unk2 * temp_t9) - (D_80203FE0[1].unk0 * temp_t9_2)) >> 7;
    sp44 = ((D_80203FE0[2].unk2 * temp_t9_2) + (D_80203FE0[2].unk0 * temp_t9)) >> 7;
    sp40 = ((D_80203FE0[2].unk2 * temp_t9) - (D_80203FE0[2].unk0 * temp_t9_2)) >> 7;

    sp28 = ((D_80203FE0[2].unk4 * 5) + D_80203FE0[1].unk4) / 192;
    sp34 = (D_80203FE0[2].unk4 + (D_80203FE0[1].unk4 * 5)) / 192;

    arg0->unkC0.a.unkC0[arg3][2] = ((sp4C * 5) + sp44) / 192;
    arg0->unkC0.a.unkC0[arg3][4] = ((sp48 * 5) + sp40) / 192;
    arg0->unkC0.a.unkC0[arg3][6] = (arg2 / 32) + sp34;
    arg0->unkC0.a.unkC0[arg3][8] = (arg1 * 7) / 512;

    arg0->unkC0.a.unkD0.m[arg3][1] = ((sp44 * 5) + sp4C) / 192;
    arg0->unkC0.a.unkD0.m[arg3][2] = ((sp40 * 5) + sp48) / 192;
    arg0->unkC0.a.unkD0.m[arg3][3] = (arg2 / 32) + sp28;
    arg0->unkC0.a.unkD0.m[arg3][4] = (arg1 * 7) / 512;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714B80/func_803034D0_714B80.s")
#endif

void func_80303820_714ED0(Animal *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4) {
    s32 tmp0;
    s32 tmp2;
    s32 tmp4;

    s16 temp_t3; // cosine?
    s16 temp_t6; // sine?

    tmp0 = (D_80203FE0[arg1].unk0 + D_80203FE0[arg2].unk0) >> 1;
    tmp2 = (D_80203FE0[arg1].unk2 + D_80203FE0[arg2].unk2) >> 1;
    tmp4 = (D_80203FE0[arg1].unk4 + D_80203FE0[arg2].unk4) >> 1;

    temp_t3 = D_80152C78[(arg0->unk302 + 64) & 0xFF] >> 8;
    temp_t6 = D_80152C78[arg0->unk302 & 0xFF] >> 8;

    tmp4 = tmp4 / 32;

    arg0->unkC0.a.unkC0[arg4][2] = ((((tmp0 * temp_t3) + (tmp2 * temp_t6))) >> 7) / 32;
    arg0->unkC0.a.unkC0[arg4][4] = ((((tmp2 * temp_t3) - (tmp0 * temp_t6))) >> 7) / 32;
    arg0->unkC0.a.unkC0[arg4][6] = tmp4;

    arg0->unkC0.a.unkD0.m[arg4][0] = arg3 / 32;
}

void func_80303990_715040(Animal *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6) {
    s32 tmp0;
    s32 tmp2;
    s32 tmp4;

    s16 temp_t3; // cosine?
    s16 temp_t6; // sine?

    tmp0 = (D_80203FE0[arg1].unk0 + D_80203FE0[arg2].unk0) >> 1;
    tmp2 = (D_80203FE0[arg1].unk2 + D_80203FE0[arg2].unk2) >> 1;
    tmp4 = (D_80203FE0[arg3].unk4 + D_80203FE0[arg4].unk4) >> 1;

    temp_t3 = D_80152C78[(arg0->unk302 + 64) & 0xFF] >> 8;
    temp_t6 = D_80152C78[arg0->unk302 & 0xFF] >> 8;

    tmp4 = tmp4 / 32;

    arg0->unkC0.a.unkC0[arg6][2] = ((((tmp0 * temp_t3) + (tmp2 * temp_t6))) >> 7) / 32;
    arg0->unkC0.a.unkC0[arg6][4] = ((((tmp2 * temp_t3) - (tmp0 * temp_t6))) >> 7) / 32;
    arg0->unkC0.a.unkC0[arg6][6] = tmp4;

    arg0->unkC0.a.unkD0.m[arg6][0] = arg5 / 32;
}

void func_80303B18_7151C8(Animal *arg0, u16 arg1, s16 arg2, u16 arg3, u16 arg4) {
    s32 tmp0;
    s32 tmp2;
    s32 tmp4;

    s16 temp_t2;
    s16 temp_t7;

    tmp0 = D_80203FE0[arg1].unk0;
    tmp2 = D_80203FE0[arg1].unk2;
    tmp4 = D_80203FE0[arg1].unk4 + arg2;

    temp_t2 = D_80152C78[(arg0->unk302 + 64) & 0xFF] >> 8;
    temp_t7 = D_80152C78[arg0->unk302 & 0xFF] >> 8;

    tmp4 = tmp4 / 32;

    arg0->unkC0.a.unkC0[arg4][2] = (((temp_t2 * tmp0) + (tmp2 * temp_t7)) >> 7) / 32;
    arg0->unkC0.a.unkC0[arg4][4] = (((temp_t2 * tmp2) - (tmp0 * temp_t7)) >> 7) / 32;
    arg0->unkC0.a.unkC0[arg4][6] = tmp4;
    arg0->unkC0.a.unkD0.m[arg4][0] = arg3 / 32;
}

void func_80303C44_7152F4(Animal *arg0, u16 arg1, s16 arg2, s16 arg3) {
    Animal *temp_v0 = D_803D552C->unk320;
    arg0->unkC0.a.unkC0[arg1][2] = ((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg2) >> 8;
    arg0->unkC0.a.unkC0[arg1][4] = ((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg2) >> 8;
    arg0->unkC0.a.unkC0[arg1][6] = temp_v0->unk7C + arg3;
    arg0->unkC0.a.unkD0.m[arg1][0] = (temp_v0->unk80 * 3) >> 2;
}

void func_80303D00_7153B0(Animal *arg0, u16 arg1, u16 arg2) {
    arg0->unkC0.a.unkC0[0][2] = 0;
    arg0->unkC0.a.unkC0[0][4] = 0;
    arg0->unkC0.a.unkC0[0][6] = arg2 / 32;
    arg0->unkC0.a.unkD0.m[0][0] = arg1 / 32;
    arg0->unkC0.a.unkD0.m[1][0] = 0;
}

void func_80303D50_715400(Animal *arg0, u16 arg1) {
    arg0->unkC0.a.unkD0.m[arg1][0] = 0;
}

void func_80303D68_715418(Animal *arg0, u16 arg1, DisplayList *arg2) {
    guTranslate(
        &arg2->modelViewMtx[arg2->usedModelViewMtxs],
        arg0->unkC0.a.unkC0[arg1][2] + arg0->xPos.h,
        arg0->unkC0.a.unkC0[arg1][4] + arg0->zPos.h,
        arg0->unkC0.a.unkC0[arg1][6] + arg0->yPos.h);

    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guScale(&arg2->modelViewMtx[arg2->usedModelViewMtxs], (f64)arg0->unkC0.a.unkD0.m[arg1][0] * 1.0f, (f64)arg0->unkC0.a.unkD0.m[arg1][0] * 1.0f, (f64)arg0->unkC0.a.unkD0.m[arg1][0] * 1.0f);

    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);
    gDPSetPrimColor(D_801D9E88++, 0, 0, 255, 0, 0, 255);
    gSPDisplayList(D_801D9E88++, D_01037700);
    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
}

void func_80303F90_715640(Animal *arg0, DisplayList *arg1) {
    s16 i;
    for (i = 0; (i < 5) && (arg0->unkC0.a.unkD0.m[i][0] != 0); i++) {
        func_80303D68_715418(arg0, i, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714B80/func_8030400C_7156BC.s")
