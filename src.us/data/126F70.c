#include <ultra64.h>

extern u8 D_0400F7F0[];

Vtx D_0400FFF0[31] = {
#include "data/inc/D_0400FFF0.inc.c"
};

Vtx D_040101E0[28] = {
#include "data/inc/D_040101E0.inc.c"
};

Gfx D_8013A900[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_CULL_BACK | G_TEXTURE_GEN),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_INTER, G_RM_AA_ZB_XLU_INTER2),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADING_SMOOTH),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsDPSetEnvColor(0x00, 0xFF, 0x00, 0x00),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_16b, 32, D_0400F7F0),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 124, 124),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400FFF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 3, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 0, 0),
    gsSP2Triangles(10, 22, 23, 0, 13, 24, 25, 0),
    gsSP2Triangles(16, 26, 27, 0, 19, 28, 29, 0),
    gsSP1Triangle(2, 30, 0, 0),
    gsSPVertex(D_040101E0, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 5, 0),
    gsSP2Triangles(22, 23, 8, 0, 24, 25, 11, 0),
    gsSP1Triangle(26, 27, 14, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
