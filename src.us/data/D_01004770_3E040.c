#include <ultra64.h>

Gfx D_01004770_3E040[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIMITIVE, 0),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPLoadSync(),
    gsDPTileSync(),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPEndDisplayList(),
};
