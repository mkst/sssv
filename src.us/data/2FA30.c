#include <ultra64.h>

Gfx D_80154330[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_SHADE | G_LIGHTING),
    gsDPSetRenderMode(G_RM_AA_XLU_LINE, G_RM_AA_XLU_LINE2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPEndDisplayList(),
};
