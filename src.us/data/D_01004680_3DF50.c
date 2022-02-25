#include <ultra64.h>

Gfx D_01004680_3DF50[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x80),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsSPEndDisplayList(),
};
