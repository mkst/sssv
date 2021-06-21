#include <ultra64.h>

extern u8  D_040104B0[];

Vtx D_04010CB0[31] = {
#include "data/inc/D_04010CB0.inc.c"
};

Vtx D_04010EA0[31] = {
#include "data/inc/D_04010EA0.inc.c"
};

Vtx D_04011090[30] = {
#include "data/inc/D_04011090.inc.c"
};

Vtx D_04011270[6] = {
#include "data/inc/D_04011270.inc.c"
};

const Gfx D_801399D0[] = {
    gsDPPipeSync(),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_16b, 32, D_040104B0),
    gsSPVertex(D_04010CB0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 4, 3, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(5, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(11, 4, 9, 0, 21, 22, 23, 0),
    gsSP2Triangles(7, 6, 24, 0, 25, 1, 0, 0),
    gsSP2Triangles(26, 5, 17, 0, 23, 27, 21, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_04010EA0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 1, 9, 10, 0),
    gsSP2Triangles(11, 5, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 9, 0, 18, 19, 20, 0),
    gsSP2Triangles(1, 10, 2, 0, 21, 22, 23, 0),
    gsSP2Triangles(16, 9, 15, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 29, 4, 0),
    gsSP1Triangle(4, 3, 30, 0),
    gsSPVertex(D_04011090, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 6, 0),
    gsSP2Triangles(0, 10, 1, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 12, 17, 18, 0),
    gsSP2Triangles(19, 18, 17, 0, 3, 0, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 26, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_04011270, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
