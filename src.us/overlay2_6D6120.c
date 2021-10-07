#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C4A70_6D6120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C56D0_6D6D80.s")

void func_802C5824_6D6ED4(s16 arg0, s16 arg1, s16 arg2) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;

    D_80203FE0[19].unk2 = D_80203FE0[1].unk2 + (D_80152350.unk2D0[arg2] * arg0 / 256);
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + (D_80152350.unk384[arg2] * arg0 / 256);

    D_80203FE0[20].unk0 = D_80203FE0[19].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[19].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C58E4_6D6F94.s")

#ifdef NON_MATCHING_TODO // JUSTREG?
void func_802C5EF4_6D75A4(s16 arg0, s16 arg1) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[19].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + arg0;

    D_80203FE0[20].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[1].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[1].unk4 + arg0;

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5EF4_6D75A4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5F34_6D75E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6468_6D7B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C64E0_6D7B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C652C_6D7BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6C00_6D82B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6FF4_6D86A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C71BC_6D886C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C7310_6D89C0.s")

void func_802C75A4_6D8C54(s16 arg0) {
    D_80203FE0[19].unk2 -= arg0 * 90;
    D_80203FE0[19].unk4 += arg0 * 90;
    D_80203FE0[20].unk2 -= arg0 * 90;
    D_80203FE0[20].unk4 += arg0 * 90;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C7600_6D8CB0.s")

void func_802C78B0_6D8F60(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, Gfx *arg9) {
    if (func_80126388(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        D_80204278->usedModelViewMtxs += 1;
        gSPDisplayList(D_801D9E88++, arg9);
        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
    }
}

void func_802C79E0_6D9090(struct016 *arg0, s16 arg1) {
    s16 temp_v0 = arg0->unk2;
    s16 temp_v1 = arg0->unk4;

    arg0->unk2 = ((temp_v0 * D_80152350.unk384[arg1]) + (D_80152350.unk2D0[arg1] * temp_v1)) / 256;
    arg0->unk4 = ((temp_v1 * D_80152350.unk384[arg1]) - (D_80152350.unk2D0[arg1] * temp_v0)) / 256;
}

void func_802C7A7C_6D912C(struct016 *arg0, s16 arg1) {
    s16 temp_v0 = arg0->unk0;
    s16 temp_v1 = arg0->unk4;

    arg0->unk0 = ((temp_v0 * D_80152350.unk384[arg1]) + (D_80152350.unk2D0[arg1] * temp_v1)) / 256;
    arg0->unk4 = ((temp_v1 * D_80152350.unk384[arg1]) - (D_80152350.unk2D0[arg1] * temp_v0)) / 256;
}

void func_802C7B18_6D91C8(struct016 *arg0, s16 arg1) {
    s16 temp_v0 = arg0->unk0;
    s16 temp_v1 = arg0->unk2;

    arg0->unk0 = ((temp_v0 * D_80152350.unk384[arg1]) + (temp_v1 * D_80152350.unk2D0[arg1])) / 256;
    arg0->unk2 = ((temp_v1 * D_80152350.unk384[arg1]) - (temp_v0 * D_80152350.unk2D0[arg1])) / 256;
}

void func_802C7BB4_6D9264(u16 arg0) {
    D_803D5528->unk37A = D_803D5528->unk374;
    D_803D5528->unk37C = D_803D5528->unk376;
    D_803D5528->unk37E = D_803D5528->unk378;
    D_803D5528->unk38E = D_803D5528->unk388;
    D_803D5528->unk390 = D_803D5528->unk38A;
    D_803D5528->unk392 = D_803D5528->unk38C;
    D_803D5528->unk3A2 = D_803D5528->unk39C;
    D_803D5528->unk3A4 = D_803D5528->unk39E;
    D_803D5528->unk3A6 = D_803D5528->unk3A0;
    D_803D5528->unk3B6 = D_803D5528->unk3B0;
    D_803D5528->unk3B8 = D_803D5528->unk3B2;
    D_803D5528->unk3BA = D_803D5528->unk3B4;
    D_803D552C->unk2FE = D_803D552C->unk2F2;
    D_803D552C->unk300 = arg0;
}
