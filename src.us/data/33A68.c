#include <ultra64.h>

Gfx D_80158368[] = {
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetColorDither(G_CD_BAYER),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPClipRatio(FRUSTRATIO_4),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
