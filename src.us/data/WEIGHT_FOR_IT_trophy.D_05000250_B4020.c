#include <ultra64.h>

Vtx D_05000000_B3DD0[32] = {
#include "data/inc/D_05000000_B3DD0.inc.c"
};
Vtx D_05000200_B3FD0[5] = {
#include "data/inc/D_05000200_B3FD0.inc.c"
};

Gfx D_05000250_B4020[] = {
    gsSPVertex(D_05000000_B3DD0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 10, 12, 0, 4, 12, 13, 0),
    gsSP2Triangles(1, 13, 6, 0, 7, 14, 15, 0),
    gsSP2Triangles(16, 14, 7, 0, 17, 11, 4, 0),
    gsSP2Triangles(2, 18, 0, 0, 15, 14, 19, 0),
    gsSP2Triangles(18, 2, 7, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 4, 11, 0, 13, 1, 5, 0),
    gsSP2Triangles(13, 5, 4, 0, 6, 2, 1, 0),
    gsSP2Triangles(20, 11, 17, 0, 7, 6, 16, 0),
    gsSP2Triangles(4, 3, 17, 0, 5, 1, 0, 0),
    gsSP1Quadrangle(21, 3, 5, 0, 0),
    gsSP1Quadrangle(22, 18, 7, 15, 0),
    gsSP2Triangles(23, 11, 20, 0, 8, 11, 23, 0),
    gsSP2Triangles(24, 8, 23, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 28, 29, 0, 25, 30, 31, 0),
    gsSPVertex(D_05000200_B3FD0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSPEndDisplayList(),
};
