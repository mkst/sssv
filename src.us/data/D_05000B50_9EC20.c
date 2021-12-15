#include <ultra64.h>

Vtx D_05000A70_9EB40[14] = {
#include "data/inc/D_05000A70_9EB40.inc.c"
};

extern u8 D_05000870_9E940[];

Gfx D_05000B50_9EC20[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, D_05000870_9E940),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 512),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(15), 4*(15)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05000A70_9EB40, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 0, 2, 0, 0, 4, 5, 0),
    gsSP2Triangles(1, 5, 6, 0, 3, 6, 4, 0),
    gsSP2Triangles(4, 7, 8, 0, 5, 8, 9, 0),
    gsSP2Triangles(6, 9, 7, 0, 7, 10, 11, 0),
    gsSP2Triangles(8, 11, 12, 0, 9, 12, 10, 0),
    gsSP2Triangles(13, 11, 10, 0, 13, 12, 11, 0),
    gsSP2Triangles(13, 10, 12, 0, 5, 1, 0, 0),
    gsSP2Triangles(6, 3, 1, 0, 4, 0, 3, 0),
    gsSP2Triangles(8, 5, 4, 0, 9, 6, 5, 0),
    gsSP2Triangles(7, 4, 6, 0, 11, 8, 7, 0),
    gsSP2Triangles(12, 9, 8, 0, 10, 7, 9, 0),
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
