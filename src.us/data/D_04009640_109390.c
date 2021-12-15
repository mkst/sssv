#include <ultra64.h>

Vtx D_04009430_109180[8] = {
#include "data/inc/D_04009430_109180.inc.c"
};
Vtx D_040094B0_109200[25] = {
#include "data/inc/D_040094B0_109200.inc.c"
};

extern u8 D_04008C30_108980[]; // img/actors/brain/brain.rgba16

Gfx D_04009640_109390[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04009430_109180, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_04008C30_108980),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_040094B0_109200, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 5, 3, 0, 2, 6, 5, 0),
    gsSP2Triangles(2, 1, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(8, 10, 11, 0, 8, 12, 9, 0),
    gsSP2Triangles(8, 5, 6, 0, 11, 3, 5, 0),
    gsSP2Triangles(11, 10, 13, 0, 2, 7, 6, 0),
    gsSP2Triangles(8, 11, 5, 0, 4, 14, 1, 0),
    gsSP2Triangles(4, 15, 16, 0, 4, 3, 15, 0),
    gsSP2Triangles(4, 16, 14, 0, 7, 17, 6, 0),
    gsSP2Triangles(7, 14, 18, 0, 7, 1, 14, 0),
    gsSP2Triangles(13, 19, 15, 0, 9, 20, 10, 0),
    gsSP2Triangles(9, 21, 22, 0, 9, 12, 21, 0),
    gsSP2Triangles(0, 2, 5, 0, 13, 15, 3, 0),
    gsSP2Triangles(13, 20, 19, 0, 13, 10, 20, 0),
    gsSP2Triangles(19, 22, 23, 0, 16, 23, 18, 0),
    gsSP2Triangles(16, 15, 23, 0, 16, 18, 14, 0),
    gsSP2Triangles(18, 23, 17, 0, 19, 20, 22, 0),
    gsSP2Triangles(24, 17, 23, 0, 19, 23, 15, 0),
    gsSP2Triangles(9, 22, 20, 0, 7, 18, 17, 0),
    gsSP2Triangles(0, 4, 1, 0, 11, 13, 3, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
