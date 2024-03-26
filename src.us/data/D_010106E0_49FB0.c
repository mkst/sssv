#include <ultra64.h>

Vtx D_01010580_49E50[13] = {
#include "data/inc/D_01010580_49E50.inc.c"
};
Vtx D_01010650_49F20[9] = {
#include "data/inc/D_01010650_49F20.inc.c"
};

extern u8 img_objects_49650_rgba16__png[];

Gfx D_010106E0_49FB0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_objects_49650_rgba16__png), // 0x0100FD80
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_01010580_49E50, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 10, 1, 0),
    gsSP2Triangles(12, 8, 6, 0, 12, 10, 8, 0),
    gsSP2Triangles(1, 10, 12, 0, 2, 1, 12, 0),
    gsSP2Triangles(12, 4, 2, 0, 6, 4, 12, 0),
    gsSP2Triangles(2, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 9, 7, 0),
    gsSP2Triangles(10, 11, 9, 0, 1, 0, 11, 0),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_01010650_49F20, 9, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(5, 8, 6, 0, 7, 4, 6, 0),
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
