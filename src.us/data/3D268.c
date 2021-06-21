#include <ultra64.h>

const Gfx D_8004ED98[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x14),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsDPSetCombineLERP(PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsSPEndDisplayList(),
};
