#include <ultra64.h>

Gfx D_010045A0_3DE70[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, PRIMITIVE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
