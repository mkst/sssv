#include <ultra64.h>

Vtx D_0400D3E0_123FB0[14] = {
#include "data/inc/D_0400D3E0_123FB0.inc.c"
};

extern u8 D_0400CBE0_1237B0[];

Gfx D_0400D4C0_124090[] = {
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_AA_ZB_OPA_INTER2),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400CBE0_1237B0),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400D3E0_123FB0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 9, 11, 12, 0),
    gsSP2Triangles(2, 13, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(6, 4, 3, 0, 8, 6, 5, 0),
    gsSP2Triangles(10, 8, 7, 0, 12, 10, 9, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
