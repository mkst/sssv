#include <ultra64.h>

Gfx D_010047D0_3E0A0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01004828_3E0F8[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x00),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsSPEndDisplayList(),
};
