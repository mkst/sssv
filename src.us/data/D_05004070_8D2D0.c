#include <ultra64.h>

Vtx D_050039A0_8CC00[30] = {
#include "data/inc/D_050039A0_8CC00.inc.c"
};
Vtx D_05003B80_8CDE0[31] = {
#include "data/inc/D_05003B80_8CDE0.inc.c"
};
Vtx D_05003D70_8CFD0[32] = {
#include "data/inc/D_05003D70_8CFD0.inc.c"
};
Vtx D_05003F70_8D1D0[16] = {
#include "data/inc/D_05003F70_8D1D0.inc.c"
};
extern u8 img_intro_asteroid_rgba16__png[];

Gfx D_05004070_8D2D0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_intro_asteroid_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_050039A0_8CC00, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 1, 0, 7, 8, 1, 0),
    gsSP2Triangles(9, 10, 11, 0, 2, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 8, 12, 2, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 28, 12, 0),
    gsSPVertex(D_05003B80_8CDE0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 3, 11, 0, 3, 10, 4, 0),
    gsSP2Triangles(8, 7, 6, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 14, 16, 0, 17, 16, 13, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 19, 21, 0),
    gsSP2Triangles(22, 21, 18, 0, 4, 2, 1, 0),
    gsSP2Triangles(5, 1, 0, 0, 6, 0, 2, 0),
    gsSP2Triangles(9, 23, 24, 0, 25, 24, 26, 0),
    gsSP2Triangles(27, 26, 23, 0, 25, 28, 29, 0),
    gsSP2Triangles(5, 29, 30, 0, 3, 30, 28, 0),
    gsSPVertex(D_05003D70_8CFD0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 1, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 10, 7, 0),
    gsSP2Triangles(12, 13, 6, 0, 14, 15, 13, 0),
    gsSP2Triangles(16, 6, 15, 0, 17, 18, 15, 0),
    gsSP2Triangles(19, 9, 18, 0, 20, 15, 9, 0),
    gsSP2Triangles(21, 0, 22, 0, 23, 24, 0, 0),
    gsSP2Triangles(25, 22, 24, 0, 26, 3, 27, 0),
    gsSP2Triangles(28, 29, 3, 0, 30, 27, 31, 0),
    gsSPVertex(D_05003F70_8D1D0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 4, 0, 6, 2, 1, 0),
    gsSP2Triangles(7, 8, 2, 0, 9, 1, 8, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 11, 0),
    gsSP1Triangle(15, 12, 14, 0),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
