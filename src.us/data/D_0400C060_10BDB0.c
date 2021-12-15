#include <ultra64.h>

Vtx D_0400B320_10B070[8] = {
#include "data/inc/D_0400B320_10B070.inc.c"
};
Vtx D_0400B3A0_10B0F0[32] = {
#include "data/inc/D_0400B3A0_10B0F0.inc.c"
};
Vtx D_0400B5A0_10B2F0[32] = {
#include "data/inc/D_0400B5A0_10B2F0.inc.c"
};
Vtx D_0400B7A0_10B4F0[31] = {
#include "data/inc/D_0400B7A0_10B4F0.inc.c"
};
Vtx D_0400B990_10B6E0[32] = {
#include "data/inc/D_0400B990_10B6E0.inc.c"
};
Vtx D_0400BB90_10B8E0[32] = {
#include "data/inc/D_0400BB90_10B8E0.inc.c"
};
Vtx D_0400BD90_10BAE0[19] = {
#include "data/inc/D_0400BD90_10BAE0.inc.c"
};
Vtx D_0400BEC0_10BC10[4] = {
#include "data/inc/D_0400BEC0_10BC10.inc.c"
};
Vtx D_0400BF00_10BC50[22] = {
#include "data/inc/D_0400BF00_10BC50.inc.c"
};

extern u8 D_0400A320_10A070[];

Gfx D_0400C060_10BDB0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400B320_10B070, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400A320_10A070),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 2047, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x00FC),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400B3A0_10B0F0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(1, 6, 7, 2, 0),
    gsSP1Quadrangle(3, 2, 7, 5, 0),
    gsSP1Quadrangle(1, 0, 4, 6, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(11, 10, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSP1Quadrangle(30, 26, 29, 31, 0),
    gsSPVertex(D_0400B5A0_10B2F0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 5, 3, 2, 0),
    gsSP1Quadrangle(4, 7, 1, 0, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 11, 14, 0),
    gsSP1Quadrangle(9, 8, 15, 16, 0),
    gsSP1Quadrangle(9, 16, 17, 10, 0),
    gsSP1Quadrangle(11, 10, 17, 14, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSP1Quadrangle(26, 29, 30, 31, 0),
    gsSPVertex(D_0400B7A0_10B4F0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(5, 6, 7, 1, 0),
    gsSP1Quadrangle(6, 8, 9, 7, 0),
    gsSP1Quadrangle(10, 4, 0, 11, 0),
    gsSP1Quadrangle(12, 13, 5, 4, 0),
    gsSP1Quadrangle(13, 14, 6, 5, 0),
    gsSP1Quadrangle(14, 15, 8, 6, 0),
    gsSP1Quadrangle(16, 12, 4, 10, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP1Quadrangle(21, 17, 20, 22, 0),
    gsSP1Quadrangle(23, 21, 22, 24, 0),
    gsSP1Quadrangle(18, 23, 24, 19, 0),
    gsSP1Quadrangle(20, 19, 24, 22, 0),
    gsSP1Quadrangle(18, 17, 21, 23, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP1Quadrangle(29, 25, 28, 30, 0),
    gsSPVertex(D_0400B990_10B6E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 5, 3, 2, 0),
    gsSP1Quadrangle(4, 7, 1, 0, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 14, 16, 17, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 18, 21, 23, 0),
    gsSP1Quadrangle(24, 22, 23, 25, 0),
    gsSP1Quadrangle(19, 24, 25, 20, 0),
    gsSP1Quadrangle(21, 20, 25, 23, 0),
    gsSP1Quadrangle(19, 18, 22, 24, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSP1Quadrangle(30, 26, 29, 31, 0),
    gsSPVertex(D_0400BB90_10B8E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 5, 3, 2, 0),
    gsSP1Quadrangle(4, 7, 1, 0, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 8, 11, 13, 0),
    gsSP1Quadrangle(14, 12, 13, 15, 0),
    gsSP1Quadrangle(9, 14, 15, 10, 0),
    gsSP1Quadrangle(11, 10, 15, 13, 0),
    gsSP1Quadrangle(9, 8, 12, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 16, 19, 0),
    gsSP2Triangles(19, 20, 17, 0, 17, 20, 18, 0),
    gsSP1Quadrangle(21, 22, 23, 24, 0),
    gsSP1Quadrangle(22, 25, 26, 23, 0),
    gsSP1Quadrangle(25, 27, 28, 26, 0),
    gsSP1Quadrangle(27, 21, 24, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_0400BD90_10BAE0, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 1, 0, 4, 6, 7, 0),
    gsSP2Triangles(4, 7, 5, 0, 6, 0, 2, 0),
    gsSP2Triangles(6, 2, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(8, 10, 11, 0, 9, 12, 13, 0),
    gsSP2Triangles(9, 13, 10, 0, 12, 14, 15, 0),
    gsSP2Triangles(12, 15, 13, 0, 14, 8, 11, 0),
    gsSP2Triangles(14, 11, 15, 0, 16, 17, 18, 0),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400BEC0_10BC10, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400BF00_10BC50, 22, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 5, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 7, 20, 21, 0),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
