#include <ultra64.h>

Vtx D_010183F0_51CC0[32] = {
#include "data/inc/D_010183F0_51CC0.inc.c"
};
Vtx D_010185F0_51EC0[3] = {
#include "data/inc/D_010185F0_51EC0.inc.c"
};

Gfx D_01018620_51EF0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_010183F0_51CC0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 2, 1, 0, 7, 2, 6, 0),
    gsSP2Triangles(5, 7, 6, 0, 6, 4, 5, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 16, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP1Quadrangle(21, 22, 23, 24, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_010185F0_51EC0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
