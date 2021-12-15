#include <ultra64.h>

Vtx D_0400B420_121FF0[31] = {
#include "data/inc/D_0400B420_121FF0.inc.c"
};
Vtx D_0400B610_1221E0[31] = {
#include "data/inc/D_0400B610_1221E0.inc.c"
};
Vtx D_0400B800_1223D0[30] = {
#include "data/inc/D_0400B800_1223D0.inc.c"
};
Vtx D_0400B9E0_1225B0[31] = {
#include "data/inc/D_0400B9E0_1225B0.inc.c"
};
Vtx D_0400BBD0_1227A0[5] = {
#include "data/inc/D_0400BBD0_1227A0.inc.c"
};

extern u8 D_0400AC20_1217F0[];

Gfx D_0400BC20_1227F0[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400AC20_1217F0),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400B420_121FF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 4, 5, 0, 2, 1, 5, 0),
    gsSP2Triangles(6, 7, 1, 0, 0, 6, 1, 0),
    gsSP2Triangles(7, 8, 4, 0, 1, 7, 4, 0),
    gsSP2Triangles(9, 10, 7, 0, 6, 9, 7, 0),
    gsSP2Triangles(10, 11, 8, 0, 7, 10, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 12, 14, 0),
    gsSP2Triangles(13, 16, 17, 0, 14, 13, 17, 0),
    gsSP2Triangles(18, 13, 12, 0, 19, 18, 12, 0),
    gsSP2Triangles(20, 16, 13, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 21, 25, 0, 26, 24, 25, 0),
    gsSP2Triangles(27, 22, 21, 0, 24, 27, 21, 0),
    gsSP2Triangles(28, 24, 26, 0, 29, 28, 26, 0),
    gsSP2Triangles(30, 27, 24, 0, 28, 30, 24, 0),
    gsSP2Triangles(2, 28, 29, 0, 3, 2, 29, 0),
    gsSP2Triangles(5, 30, 28, 0, 2, 5, 28, 0),
    gsSPVertex(D_0400B610_1221E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 4, 5, 0, 2, 1, 5, 0),
    gsSP2Triangles(6, 7, 1, 0, 0, 6, 1, 0),
    gsSP2Triangles(7, 8, 4, 0, 1, 7, 4, 0),
    gsSP2Triangles(9, 10, 7, 0, 6, 9, 7, 0),
    gsSP2Triangles(10, 11, 8, 0, 7, 10, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 12, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
    gsSP2Triangles(20, 13, 12, 0, 21, 20, 12, 0),
    gsSP2Triangles(22, 17, 16, 0, 23, 22, 16, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 24, 26, 0),
    gsSP2Triangles(28, 29, 25, 0, 24, 28, 25, 0),
    gsSP1Triangle(30, 24, 27, 0),
    gsSPVertex(D_0400B800_1223D0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 3, 5, 0, 6, 1, 0, 0),
    gsSP2Triangles(7, 6, 0, 0, 8, 3, 1, 0),
    gsSP2Triangles(6, 8, 1, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 9, 11, 0, 10, 13, 7, 0),
    gsSP2Triangles(11, 10, 7, 0, 14, 15, 10, 0),
    gsSP2Triangles(9, 14, 10, 0, 15, 16, 13, 0),
    gsSP2Triangles(10, 15, 13, 0, 17, 18, 15, 0),
    gsSP2Triangles(14, 17, 15, 0, 18, 19, 16, 0),
    gsSP2Triangles(15, 18, 16, 0, 20, 21, 18, 0),
    gsSP2Triangles(17, 20, 18, 0, 21, 22, 19, 0),
    gsSP2Triangles(18, 21, 19, 0, 23, 21, 20, 0),
    gsSP2Triangles(24, 23, 20, 0, 25, 22, 21, 0),
    gsSP2Triangles(23, 25, 21, 0, 26, 23, 24, 0),
    gsSP2Triangles(27, 26, 24, 0, 2, 25, 23, 0),
    gsSP2Triangles(26, 2, 23, 0, 28, 26, 27, 0),
    gsSP2Triangles(29, 28, 27, 0, 0, 2, 26, 0),
    gsSP2Triangles(28, 0, 26, 0, 11, 28, 29, 0),
    gsSP2Triangles(12, 11, 29, 0, 7, 0, 28, 0),
    gsSP1Triangle(11, 7, 28, 0),
    gsSPVertex(D_0400B9E0_1225B0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 4, 5, 0, 2, 1, 5, 0),
    gsSP2Triangles(6, 7, 1, 0, 0, 6, 1, 0),
    gsSP2Triangles(7, 8, 4, 0, 1, 7, 4, 0),
    gsSP2Triangles(9, 10, 7, 0, 6, 9, 7, 0),
    gsSP2Triangles(10, 11, 8, 0, 7, 10, 8, 0),
    gsSP2Triangles(12, 13, 10, 0, 9, 12, 10, 0),
    gsSP2Triangles(13, 14, 11, 0, 10, 13, 11, 0),
    gsSP2Triangles(15, 13, 12, 0, 16, 15, 12, 0),
    gsSP2Triangles(17, 14, 13, 0, 15, 17, 13, 0),
    gsSP2Triangles(18, 15, 16, 0, 19, 18, 16, 0),
    gsSP2Triangles(20, 17, 15, 0, 18, 20, 15, 0),
    gsSP2Triangles(21, 18, 19, 0, 22, 21, 19, 0),
    gsSP2Triangles(23, 20, 18, 0, 21, 23, 18, 0),
    gsSP2Triangles(2, 21, 22, 0, 3, 2, 22, 0),
    gsSP2Triangles(5, 23, 21, 0, 2, 5, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 25, 24, 0),
    gsSP2Triangles(28, 27, 24, 0, 29, 28, 24, 0),
    gsSP1Triangle(30, 29, 24, 0),
    gsSPVertex(D_0400BBD0_1227A0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP1Triangle(4, 3, 2, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
