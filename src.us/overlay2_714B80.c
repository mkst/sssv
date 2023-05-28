#include <ultra64.h>
#include "common.h"


void func_803034D0_714B80(Animal *arg0, u16 arg1, s16 arg2, u16 arg3) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp38[2];
    s32 sp34;
    s16 temp_t9;
    s16 temp_t9_2;
    s16 new_var;
    s16 new_var2;
    s32 sp28;
    s32 pad;

    temp_t9 = D_80152C78[(arg0->unk302 + 0x40) & 0xFF] >> 8;
    temp_t9_2 = D_80152C78[(arg0->unk302 & 0xFF)] >> 8;

    new_var2 = D_80203FE0[1].unk2;
    new_var = D_80203FE0[1].unk0;

    sp4C = ((D_80203FE0[1].unk2 * temp_t9_2) + (new_var * temp_t9)) >> 7;
    sp48 = ((new_var2 * temp_t9) - (new_var * temp_t9_2)) >> 7;

    sp44 = ((D_80203FE0[2].unk0 * temp_t9) + (D_80203FE0[2].unk2 * temp_t9_2)) >> 7;
    sp40 = ((D_80203FE0[2].unk2 * temp_t9) - (D_80203FE0[2].unk0 * temp_t9_2)) >> 7;

    sp28 = (D_80203FE0[1].unk4 + (D_80203FE0[2].unk4 * 5)) / 192;
    sp34 = ((D_80203FE0[1].unk4 * 5) + D_80203FE0[2].unk4) / 192;

    arg0->unkC4[arg3].unk0.h = ((sp4C * 5) + sp44) / 192;
    if (0) { }
    arg0->unkC4[arg3].unk4.h = ((sp48 * 5) + sp40) / 192;
    arg0->unkC4[arg3].unk8.h = (arg2 / 32) + sp34;
    arg0->unkC4[arg3].unkC = ((arg1 * 7) / 32) >> 4;

    arg0->unkC4[arg3+1].unk0.h = ((sp44 * 5) + sp4C) / 192;
    arg0->unkC4[arg3+1].unk4.h = ((sp40 * 5) + sp48) / 192;
    arg0->unkC4[arg3+1].unk8.h = (arg2 / 32) + sp28;
    arg0->unkC4[arg3+1].unkC = ((arg1 * 7) / 32) >> 4;
}

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

    arg0->unkC4[arg4].unk0.h = ((((tmp0 * temp_t3) + (tmp2 * temp_t6))) >> 7) / 32;
    arg0->unkC4[arg4].unk4.h = ((((tmp2 * temp_t3) - (tmp0 * temp_t6))) >> 7) / 32;
    arg0->unkC4[arg4].unk8.h = tmp4;

    arg0->unkC4[arg4].unkC = arg3 / 32;
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

    arg0->unkC4[arg6].unk0.h = ((((tmp0 * temp_t3) + (tmp2 * temp_t6))) >> 7) / 32;
    arg0->unkC4[arg6].unk4.h = ((((tmp2 * temp_t3) - (tmp0 * temp_t6))) >> 7) / 32;
    arg0->unkC4[arg6].unk8.h = tmp4;

    arg0->unkC4[arg6].unkC = arg5 / 32;
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

    arg0->unkC4[arg4].unk0.h = (((temp_t2 * tmp0) + (tmp2 * temp_t7)) >> 7) / 32;
    arg0->unkC4[arg4].unk4.h = (((temp_t2 * tmp2) - (tmp0 * temp_t7)) >> 7) / 32;
    arg0->unkC4[arg4].unk8.h = tmp4;
    arg0->unkC4[arg4].unkC = arg3 / 32;
}

void func_80303C44_7152F4(Animal *arg0, u16 arg1, s16 arg2, s16 arg3) {
    Animal *temp_v0 = D_803D552C->unk320;
    arg0->unkC4[arg1].unk0.h = ((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg2) >> 8;
    arg0->unkC4[arg1].unk4.h = ((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg2) >> 8;
    arg0->unkC4[arg1].unk8.h = temp_v0->unk74[0].unk8.h + arg3;
    arg0->unkC4[arg1].unkC = (temp_v0->unk74[0].unkC * 3) >> 2;
}

void func_80303D00_7153B0(Animal *arg0, u16 arg1, u16 arg2) {
    arg0->unkC4[0].unk0.h = 0;
    arg0->unkC4[0].unk4.h = 0;
    arg0->unkC4[0].unk8.h = arg2 / 32;
    arg0->unkC4[0].unkC = arg1 / 32;
    arg0->unkC4[1].unkC = 0;
}

void func_80303D50_715400(Animal *arg0, u16 arg1) {
    arg0->unkC4[arg1].unkC = 0;
}

void func_80303D68_715418(Animal *arg0, u16 arg1, DisplayList *arg2) {
    guTranslate(
        &arg2->modelViewMtx[arg2->usedModelViewMtxs],
        arg0->unkC4[arg1].unk0.h + arg0->xPos.h,
        arg0->unkC4[arg1].unk4.h + arg0->zPos.h,
        arg0->unkC4[arg1].unk8.h + arg0->yPos.h);

    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guScale(&arg2->modelViewMtx[arg2->usedModelViewMtxs], (f64)arg0->unkC4[arg1].unkC * 1.0f, (f64)arg0->unkC4[arg1].unkC * 1.0f, (f64)arg0->unkC4[arg1].unkC * 1.0f);

    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);
    gDPSetPrimColor(D_801D9E88++, 0, 0, 255, 0, 0, 255);
    gSPDisplayList(D_801D9E88++, D_01037700);
    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
}

void func_80303F90_715640(Animal *arg0, DisplayList *arg1) {
    s16 i;
    for (i = 0; (i < 5) && (arg0->unkC4[i].unkC != 0); i++) {
        func_80303D68_715418(arg0, i, arg1);
    }
}

// ESA: func_8001C944
s32 func_8030400C_7156BC(Animal *arg0, s16 x, s16 z, s32 *arg3, s32 *arg4) {
    s32 temp_t2;
    s32 temp_t3;
    s16 i;
    struct043 *var_t0;

    s16 tmp1;
    s16 tmp2;

    s16 dist;

    s32 res;

    res = 0;

    *arg4 = 0x40000000;
    *arg3 = 0;

    x = x - arg0->xPos.h;
    z = z - arg0->zPos.h;

    i = 1;
    var_t0 = &arg0->unkC4[i];

    while ((i < 5) && (var_t0->unkC != 0)) {
        tmp1 = x - var_t0->unk0.h;
        tmp2 = z - var_t0->unk4.h;
        dist = SQ(tmp1) + SQ(tmp2);

        if (dist < SQ(var_t0->unkC)) {
            temp_t2 = (arg0->yPos.w + var_t0->unk8.w) + (var_t0->unkC << 0x10);
            temp_t3 = (arg0->yPos.w + var_t0->unk8.w) - (var_t0->unkC << 0x10);

            if (res != 0) {
                *arg3 = MAX(*arg3, temp_t2);
                *arg4 = MIN(*arg4, temp_t3);
            } else {
                *arg3 = temp_t2;
                *arg4 = temp_t3;
                res = 1;
            }
        }
        var_t0++;
        i++;
    }

    return res;
}
