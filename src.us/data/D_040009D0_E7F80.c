#include <ultra64.h>

Vtx D_04000750_E7D00[20] = {
#include "data/inc/D_04000750_E7D00.inc.c"
};
Vtx D_04000890_E7E40[20] = {
#include "data/inc/D_04000890_E7E40.inc.c"
};

Gfx D_040009D0_E7F80[] = {
    gsSPVertex(D_04000750_E7D00, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 1, 4, 0, 4, 1, 5, 0),
    gsSP2Triangles(5, 1, 6, 0, 6, 1, 0, 0),
    gsSP2Triangles(7, 0, 2, 0, 8, 2, 3, 0),
    gsSP2Triangles(2, 8, 7, 0, 9, 3, 4, 0),
    gsSP2Triangles(3, 9, 8, 0, 10, 4, 5, 0),
    gsSP2Triangles(4, 10, 9, 0, 11, 5, 6, 0),
    gsSP2Triangles(5, 11, 10, 0, 12, 6, 0, 0),
    gsSP2Triangles(6, 12, 11, 0, 0, 7, 12, 0),
    gsSP2Triangles(12, 7, 13, 0, 11, 12, 14, 0),
    gsSP2Triangles(13, 14, 12, 0, 10, 11, 15, 0),
    gsSP2Triangles(14, 15, 11, 0, 9, 10, 16, 0),
    gsSP2Triangles(15, 16, 10, 0, 8, 9, 17, 0),
    gsSP2Triangles(16, 17, 9, 0, 7, 8, 18, 0),
    gsSP2Triangles(17, 18, 8, 0, 18, 13, 7, 0),
    gsSP2Triangles(13, 18, 19, 0, 18, 17, 19, 0),
    gsSP2Triangles(17, 16, 19, 0, 16, 15, 19, 0),
    gsSP2Triangles(15, 14, 19, 0, 14, 13, 19, 0),
    gsSPVertex(D_04000890_E7E40, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 1, 4, 0, 4, 1, 5, 0),
    gsSP2Triangles(5, 1, 6, 0, 6, 1, 0, 0),
    gsSP1Quadrangle(0, 2, 7, 8, 0),
    gsSP2Triangles(6, 0, 8, 0, 2, 9, 7, 0),
    gsSP2Triangles(2, 3, 9, 0, 3, 10, 9, 0),
    gsSP2Triangles(3, 4, 10, 0, 4, 11, 10, 0),
    gsSP2Triangles(4, 5, 11, 0, 5, 12, 11, 0),
    gsSP2Triangles(5, 6, 12, 0, 6, 8, 12, 0),
    gsSP2Triangles(8, 13, 12, 0, 8, 14, 13, 0),
    gsSP2Triangles(7, 14, 8, 0, 12, 15, 11, 0),
    gsSP2Triangles(12, 13, 15, 0, 11, 16, 10, 0),
    gsSP2Triangles(11, 15, 16, 0, 10, 17, 9, 0),
    gsSP2Triangles(10, 16, 17, 0, 9, 18, 7, 0),
    gsSP2Triangles(9, 17, 18, 0, 7, 18, 14, 0),
    gsSP2Triangles(14, 18, 19, 0, 18, 17, 19, 0),
    gsSP2Triangles(17, 16, 19, 0, 16, 15, 19, 0),
    gsSP2Triangles(15, 13, 19, 0, 13, 14, 19, 0),
    gsSPEndDisplayList(),
};
