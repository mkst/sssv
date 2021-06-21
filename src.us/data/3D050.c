#include <ultra64.h>

Gfx D_8004EB80[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_CLIPPING),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PASS2),
    gsSPEndDisplayList(),
};
