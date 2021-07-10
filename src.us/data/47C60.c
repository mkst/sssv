#include <ultra64.h>

extern u8 D_0100C3E0_45CB0[];
extern u8 D_0100CBE0_464B0[];

Vtx D_0100D3E0_46CB0[31] = {
#include "data/inc/D_0100D3E0_46CB0.inc.c"
};
Vtx D_0100D5D0_46EA0[32] = {
#include "data/inc/D_0100D5D0_46EA0.inc.c"
};
Vtx D_0100D7D0_470A0[32] = {
#include "data/inc/D_0100D7D0_470A0.inc.c"
};
Vtx D_0100D9D0_472A0[32] = {
#include "data/inc/D_0100D9D0_472A0.inc.c"
};
Vtx D_0100DBD0_474A0[31] = {
#include "data/inc/D_0100DBD0_474A0.inc.c"
};
Vtx D_0100DDC0_47690[24] = {
#include "data/inc/D_0100DDC0_47690.inc.c"
};
Vtx D_0100DF40_47810[32] = {
#include "data/inc/D_0100DF40_47810.inc.c"
};
Vtx D_0100E140_47A10[31] = {
#include "data/inc/D_0100E140_47A10.inc.c"
};
Vtx D_0100E330_47C00[6] = {
#include "data/inc/D_0100E330_47C00.inc.c"
};

const Gfx D_0100E390_47C60[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0100C3E0_45CB0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0100D3E0_46CB0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 7, 8, 2, 0),
    gsSP2Triangles(9, 10, 2, 0, 11, 12, 2, 0),
    gsSP2Triangles(13, 14, 2, 0, 15, 16, 2, 0),
    gsSP1Quadrangle(17, 18, 3, 16, 0),
    gsSP1Quadrangle(19, 20, 5, 1, 0),
    gsSP1Quadrangle(21, 22, 7, 4, 0),
    gsSP1Quadrangle(23, 24, 9, 6, 0),
    gsSP1Quadrangle(25, 26, 11, 8, 0),
    gsSP1Quadrangle(27, 28, 13, 10, 0),
    gsSP1Quadrangle(29, 30, 15, 12, 0),
    gsSPVertex(D_0100D5D0_46EA0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0100D7D0_470A0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0100D9D0_472A0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0100DBD0_474A0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 7, 8, 0),
    gsSP2Triangles(4, 9, 10, 0, 4, 11, 12, 0),
    gsSP2Triangles(4, 13, 14, 0, 4, 15, 16, 0),
    gsSP2Triangles(4, 17, 18, 0, 4, 1, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 22, 0, 22, 27, 28, 0),
    gsSP1Triangle(29, 30, 22, 0),
    gsSPVertex(D_0100DDC0_47690, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(0, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 7, 0, 7, 12, 13, 0),
    gsSP2Triangles(14, 15, 7, 0, 7, 16, 17, 0),
    gsSP2Triangles(18, 19, 7, 0, 7, 20, 21, 0),
    gsSP1Triangle(22, 23, 7, 0),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0100CBE0_464B0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(1, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, 1, G_ON),
    gsSPVertex(D_0100DF40_47810, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0100E140_47A10, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 1, 3, 0, 5, 6, 7, 0),
    gsSP2Triangles(0, 2, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(4, 3, 8, 0, 12, 13, 11, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 15, 18, 0),
    gsSP2Triangles(4, 19, 20, 0, 4, 21, 19, 0),
    gsSP2Triangles(0, 21, 22, 0, 23, 18, 24, 0),
    gsSP2Triangles(4, 20, 22, 0, 21, 4, 22, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_0100E330_47C00, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 5, 0, 2, 4, 5, 0),
    gsSP2Triangles(0, 2, 5, 0, 3, 0, 5, 0),
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
