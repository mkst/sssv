#include <ultra64.h>

Gfx D_01004600_3DED0[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, PRIMITIVE, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, PRIMITIVE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};
