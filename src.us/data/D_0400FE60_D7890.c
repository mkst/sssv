#include <ultra64.h>

Vtx D_0400F770_D71A0[30] = {
#include "data/inc/D_0400F770_D71A0.inc.c"
};
Vtx D_0400F950_D7380[31] = {
#include "data/inc/D_0400F950_D7380.inc.c"
};
Vtx D_0400FB40_D7570[32] = {
#include "data/inc/D_0400FB40_D7570.inc.c"
};
Vtx D_0400FD40_D7770[18] = {
#include "data/inc/D_0400FD40_D7770.inc.c"
};

Gfx D_0400FE60_D7890[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400F770_D71A0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 1, 0, 5, 3, 2, 0),
    gsSP2Triangles(5, 4, 3, 0, 5, 1, 4, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(6, 9, 10, 7, 0),
    gsSP2Triangles(11, 8, 7, 0, 11, 9, 8, 0),
    gsSP2Triangles(11, 10, 9, 0, 11, 7, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 13, 15, 16, 0),
    gsSP2Triangles(15, 12, 17, 0, 14, 17, 12, 0),
    gsSP2Triangles(16, 14, 13, 0, 17, 16, 15, 0),
    gsSP2Triangles(18, 19, 20, 0, 19, 21, 22, 0),
    gsSP2Triangles(21, 18, 23, 0, 20, 23, 18, 0),
    gsSP2Triangles(22, 20, 19, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(28, 27, 26, 0),
    gsSPVertex(D_0400F950_D7380, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 16, 15, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 23, 22, 17, 0),
    gsSP2Triangles(21, 20, 24, 0, 19, 22, 20, 0),
    gsSP2Triangles(19, 17, 22, 0, 19, 21, 17, 0),
    gsSP2Triangles(18, 23, 16, 0, 18, 24, 23, 0),
    gsSP2Triangles(18, 15, 24, 0, 25, 0, 26, 0),
    gsSP2Triangles(2, 1, 27, 0, 25, 28, 29, 0),
    gsSP2Triangles(2, 26, 0, 0, 5, 30, 3, 0),
    gsSPVertex(D_0400FB40_D7570, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 9, 15, 16, 0),
    gsSP2Triangles(12, 11, 10, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 17, 23, 24, 0),
    gsSP2Triangles(17, 22, 21, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 30, 29, 31, 0),
    gsSPVertex(D_0400FD40_D7770, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 1, 8, 0),
    gsSP2Triangles(7, 2, 1, 0, 7, 9, 2, 0),
    gsSP2Triangles(4, 0, 5, 0, 4, 3, 0, 0),
    gsSP2Triangles(4, 6, 3, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 14, 13, 12, 0),
    gsSP2Triangles(16, 17, 15, 0, 11, 10, 15, 0),
    gsSP2Triangles(2, 9, 6, 0, 3, 6, 9, 0),
    gsSP2Triangles(2, 5, 0, 0, 3, 8, 1, 0),
    gsSP1Triangle(12, 16, 10, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
