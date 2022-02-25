#include <ultra64.h>

Gfx D_01004720_3DFF0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsSPEndDisplayList(),
};
