#include <ultra64.h>

Gfx D_8004EBB8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_RA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_CLIPPING),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PASS2),
    gsSPEndDisplayList(),
};
