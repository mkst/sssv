#include <ultra64.h>

extern u8 D_010209B0_5A280[];

Gfx D_010049A0_3E270[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_010049E8_3E2B8[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_BLENDPE, G_CC_BLENDPEDECALA),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsDPLoadTextureBlock_4b(D_010209B0_5A280, G_IM_FMT_I, 128, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList(),
};
