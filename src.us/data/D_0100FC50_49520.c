#include <ultra64.h>

Vtx D_0100FB80_49450[13] = {
#include "data/inc/D_0100FB80_49450.inc.c"
};

Gfx D_0100FC50_49520[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0x0100F980),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 512),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x003C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0100FB80_49450, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(4, 5, 2, 0, 6, 0, 7, 0),
    gsSP2Triangles(3, 8, 9, 0, 9, 5, 4, 0),
    gsSP2Triangles(7, 5, 10, 0, 8, 11, 12, 0),
    gsSP2Triangles(12, 5, 9, 0, 2, 5, 7, 0),
    gsSP2Triangles(11, 6, 10, 0, 10, 5, 12, 0),
    gsSP2Triangles(2, 7, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(7, 10, 6, 0, 9, 4, 3, 0),
    gsSP2Triangles(12, 9, 8, 0, 10, 12, 11, 0),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
