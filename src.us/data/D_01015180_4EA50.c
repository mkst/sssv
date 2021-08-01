#include <ultra64.h>


Vtx D_010144D0_4DDA0[32] = {
#include "data/inc/D_010144D0_4DDA0.inc.c"
};
Vtx D_010146D0_4DFA0[32] = {
#include "data/inc/D_010146D0_4DFA0.inc.c"
};
Vtx D_010148D0_4E1A0[32] = {
#include "data/inc/D_010148D0_4E1A0.inc.c"
};
Vtx D_01014AD0_4E3A0[31] = {
#include "data/inc/D_01014AD0_4E3A0.inc.c"
};
Vtx D_01014CC0_4E590[30] = {
#include "data/inc/D_01014CC0_4E590.inc.c"
};
Vtx D_01014EA0_4E770[31] = {
#include "data/inc/D_01014EA0_4E770.inc.c"
};
Vtx D_01015090_4E960[15] = {
#include "data/inc/D_01015090_4E960.inc.c"
};


extern u8 D_010134D0_4CDA0[];

const Gfx D_01015180_4EA50[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, D_010134D0_4CDA0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 2047, 128),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(63), 4*(31)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_010144D0_4DDA0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 4, 5, 0),
    gsSP1Quadrangle(3, 6, 7, 4, 0),
    gsSP1Quadrangle(4, 7, 8, 5, 0),
    gsSP2Triangles(5, 8, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(2, 5, 13, 0, 11, 14, 12, 0),
    gsSP2Triangles(12, 15, 16, 0, 5, 9, 17, 0),
    gsSP2Triangles(18, 19, 14, 0, 15, 20, 21, 0),
    gsSP2Triangles(15, 21, 16, 0, 16, 21, 22, 0),
    gsSP2Triangles(23, 12, 24, 0, 12, 16, 25, 0),
    gsSP2Triangles(12, 25, 24, 0, 24, 25, 26, 0),
    gsSP1Quadrangle(16, 22, 27, 25, 0),
    gsSP1Quadrangle(25, 27, 28, 26, 0),
    gsSP2Triangles(26, 28, 29, 0, 30, 24, 31, 0),
    gsSPVertex(D_010146D0_4DFA0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 1, 5, 6, 0),
    gsSP2Triangles(1, 6, 2, 0, 2, 6, 7, 0),
    gsSP2Triangles(2, 7, 4, 0, 4, 7, 8, 0),
    gsSP2Triangles(9, 3, 10, 0, 3, 4, 11, 0),
    gsSP2Triangles(3, 11, 10, 0, 10, 11, 12, 0),
    gsSP1Quadrangle(4, 8, 13, 11, 0),
    gsSP1Quadrangle(11, 13, 14, 12, 0),
    gsSP2Triangles(12, 14, 15, 0, 15, 16, 17, 0),
    gsSP1Quadrangle(16, 18, 19, 17, 0),
    gsSP2Triangles(17, 19, 20, 0, 18, 21, 22, 0),
    gsSP2Triangles(18, 22, 19, 0, 19, 22, 23, 0),
    gsSP2Triangles(19, 23, 20, 0, 20, 23, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 26, 28, 29, 0),
    gsSP2Triangles(26, 29, 27, 0, 27, 29, 30, 0),
    gsSP1Triangle(28, 24, 31, 0),
    gsSPVertex(D_010148D0_4E1A0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 12, 0),
    gsSP2Triangles(9, 12, 10, 0, 10, 12, 13, 0),
    gsSP1Quadrangle(11, 7, 14, 12, 0),
    gsSP1Quadrangle(12, 14, 15, 13, 0),
    gsSP2Triangles(13, 15, 16, 0, 17, 18, 19, 0),
    gsSP1Quadrangle(18, 20, 21, 19, 0),
    gsSP2Triangles(19, 21, 22, 0, 20, 16, 23, 0),
    gsSP2Triangles(20, 23, 21, 0, 21, 23, 24, 0),
    gsSP2Triangles(21, 24, 22, 0, 22, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 27, 29, 30, 0),
    gsSP2Triangles(27, 30, 28, 0, 28, 30, 31, 0),
    gsSPVertex(D_01014AD0_4E3A0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(3, 2, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 8, 9, 0),
    gsSP1Quadrangle(8, 10, 11, 9, 0),
    gsSP2Triangles(9, 11, 12, 0, 10, 13, 14, 0),
    gsSP2Triangles(10, 14, 11, 0, 11, 14, 15, 0),
    gsSP2Triangles(11, 15, 12, 0, 12, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 18, 20, 21, 0),
    gsSP2Triangles(18, 21, 19, 0, 19, 21, 22, 0),
    gsSP1Quadrangle(20, 23, 24, 21, 0),
    gsSP1Quadrangle(21, 24, 25, 22, 0),
    gsSP2Triangles(26, 27, 13, 0, 28, 29, 30, 0),
    gsSPVertex(D_01014CC0_4E590, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 1, 5, 6, 0),
    gsSP2Triangles(1, 6, 2, 0, 2, 6, 7, 0),
    gsSP2Triangles(2, 7, 4, 0, 4, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 10, 12, 13, 0),
    gsSP2Triangles(10, 13, 11, 0, 11, 13, 14, 0),
    gsSP1Quadrangle(12, 15, 16, 13, 0),
    gsSP1Quadrangle(13, 16, 17, 14, 0),
    gsSP2Triangles(14, 17, 5, 0, 18, 19, 20, 0),
    gsSP1Quadrangle(19, 21, 22, 20, 0),
    gsSP2Triangles(20, 22, 23, 0, 21, 24, 25, 0),
    gsSP2Triangles(21, 25, 22, 0, 22, 25, 26, 0),
    gsSP2Triangles(22, 26, 23, 0, 23, 26, 15, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_01014EA0_4E770, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 1, 7, 8, 0),
    gsSP2Triangles(9, 10, 4, 0, 4, 10, 11, 0),
    gsSP2Triangles(4, 11, 6, 0, 6, 11, 12, 0),
    gsSP2Triangles(13, 14, 0, 0, 14, 15, 16, 0),
    gsSP2Triangles(14, 16, 0, 0, 0, 16, 1, 0),
    gsSP1Quadrangle(15, 17, 18, 16, 0),
    gsSP1Quadrangle(16, 18, 19, 1, 0),
    gsSP2Triangles(1, 19, 7, 0, 20, 21, 14, 0),
    gsSP1Quadrangle(21, 22, 23, 14, 0),
    gsSP2Triangles(14, 23, 15, 0, 22, 24, 25, 0),
    gsSP2Triangles(22, 25, 23, 0, 23, 25, 26, 0),
    gsSP2Triangles(23, 26, 15, 0, 15, 26, 17, 0),
    gsSP2Triangles(27, 28, 21, 0, 28, 29, 30, 0),
    gsSP2Triangles(28, 30, 21, 0, 21, 30, 22, 0),
    gsSPVertex(D_01015090_4E960, 15, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(3, 2, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 8, 9, 0),
    gsSP1Quadrangle(8, 10, 11, 9, 0),
    gsSP2Triangles(9, 11, 0, 0, 10, 12, 13, 0),
    gsSP2Triangles(10, 13, 11, 0, 11, 13, 14, 0),
    gsSP2Triangles(11, 14, 0, 0, 0, 14, 1, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
