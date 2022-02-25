#include <ultra64.h>

Gfx D_01004270_3DB40[] = {
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH | G_CLIPPING),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetColorDither(G_CD_BAYER),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPClipRatio(FRUSTRATIO_3),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01004308_3DBD8[] = {
    gsDPPipeSync(),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureLOD(G_TL_TILE),
    gsSPEndDisplayList(),
};
