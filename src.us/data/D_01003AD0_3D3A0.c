#include <ultra64.h>

Gfx D_01003AD0_3D3A0[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetPrimDepth(1, 0),
    gsSPEndDisplayList(),
};
