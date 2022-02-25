#include <ultra64.h>

Gfx D_01004970_3E240[] = {
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};
