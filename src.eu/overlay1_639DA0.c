#include <ultra64.h>
#include "common.h"

void func_802998D0_63E800(void);

void func_80294E70_639DA0(void) {
    func_802998D0_63E800();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80294E98_639DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80294EFC_639E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80295184_63A0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_802953C4_63A2F4.s")

void func_802956AC_63A5DC(void) {
}

// #pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_802956BC_63A5EC.s")
void func_802956BC_63A5EC(Gfx **arg0, u16 arg1) {
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    u16 sp66;
    u16 sp64;

    sp66 = 160;
    sp64 = 120;

    D_8029B2C4_6401F4 = D_8029B2B8_6401E8;
    D_8029B2C8_6401F8 = D_8029B2BC_6401EC;

    func_80294EFC_639E2C(&D_801D9E9C);
    gSPDisplayList((*arg0)++, &D_80158388);
    gSPNumLights((*arg0)++, 1);
    gSPLight((*arg0)++, &D_8029B250_640180.l[0], 1);
    gSPLight((*arg0)++, &D_8029B250_640180.a, 2);

    if ((s32) arg1 < 0x14) {
        sp74 = (sp66 - (arg1 << 3)) - 1;
        sp6C = sp66 + (arg1 << 3) + 1;
        if (sp74 < 8) {
            sp74 = 8;
        }
        if (sp6C > 312) {
            sp6C = 312;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, sp74, 120, sp6C, 121);

    } else if (arg1 < 0x28) {
        sp70 = (sp64 - ((arg1 / 2) * 0xC)) + 119;
        sp68 = (sp64 + ((arg1 / 2) * 0xC)) - 120;
        if (sp70 < 8) {
            sp74 = 8; // unused but important
        }
        if (sp68 > 232) {
            sp68 = 232;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, sp70, 312, sp68);
    } else {
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, D_80203FF0 - 8, D_80203FF2 - 8);
    }

    func_80125980(&D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs], 0, 0, 0, 0, 0, 0, FTOFIX32(8.0), FTOFIX32(8.0), FTOFIX32(8.0));

    gSPMatrix((*arg0)++, &D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gDPSetRenderMode((*arg0)++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
    gSPDisplayList((*arg0)++, &D_8029B1D0_640100);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, D_80203FF0 - 8, D_80203FF2 - 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80295CCC_63ABFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80295E00_63AD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80296114_63B044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80296464_63B394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80296590_63B4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_802998D0_63E800.s")

void func_80299B28_63EA58(void) {
    gSPClearGeometryMode(D_801D9E9C++, -1);
    gSPSetGeometryMode(D_801D9E9C++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH | G_CLIPPING);

    gDPSetColorDither(D_801D9E9C++, G_CD_BAYER);

    gDPSetTextureLOD(D_801D9E9C++, G_TL_TILE);
    gDPSetTextureDetail(D_801D9E9C++, G_TD_CLAMP);
    gDPSetTextureLUT(D_801D9E9C++, G_TT_NONE);
    gDPSetTexturePersp(D_801D9E9C++, G_TP_PERSP);
    gDPSetTextureConvert(D_801D9E9C++, G_TC_FILT);

    gDPSetAlphaCompare(D_801D9E9C++, G_AC_NONE);
    gSPClipRatio(D_801D9E9C++, FRUSTRATIO_4);
    gDPSetDepthSource(D_801D9E9C++, G_ZS_PIXEL);
}
