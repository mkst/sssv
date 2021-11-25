#include <ultra64.h>

Vtx D_040101F0_10FF40[8] = {
#include "data/inc/D_040101F0_10FF40.inc.c"
};
Vtx D_04010270_10FFC0[32] = {
#include "data/inc/D_04010270_10FFC0.inc.c"
};
Vtx D_04010470_1101C0[31] = {
#include "data/inc/D_04010470_1101C0.inc.c"
};
Vtx D_04010660_1103B0[28] = {
#include "data/inc/D_04010660_1103B0.inc.c"
};

const Gfx D_04010820_110570[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_040101F0_10FF40, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_04010270_10FFC0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 4, 0, 7, 8, 9, 0),
    gsSP2Triangles(6, 10, 4, 0, 11, 5, 12, 0),
    gsSP2Triangles(13, 14, 1, 0, 13, 15, 14, 0),
    gsSP2Triangles(15, 16, 14, 0, 15, 17, 16, 0),
    gsSP2Triangles(17, 7, 16, 0, 17, 18, 7, 0),
    gsSP2Triangles(18, 8, 7, 0, 18, 19, 8, 0),
    gsSP2Triangles(20, 11, 12, 0, 0, 2, 10, 0),
    gsSP2Triangles(11, 3, 5, 0, 6, 0, 10, 0),
    gsSP2Triangles(21, 11, 20, 0, 21, 22, 11, 0),
    gsSP2Triangles(22, 3, 11, 0, 22, 23, 3, 0),
    gsSP2Triangles(23, 6, 3, 0, 23, 24, 6, 0),
    gsSP2Triangles(24, 0, 6, 0, 24, 25, 0, 0),
    gsSP2Triangles(25, 1, 0, 0, 25, 13, 1, 0),
    gsSP2Triangles(1, 26, 2, 0, 1, 14, 26, 0),
    gsSP2Triangles(14, 27, 26, 0, 14, 16, 27, 0),
    gsSP2Triangles(16, 28, 27, 0, 16, 7, 28, 0),
    gsSP2Triangles(7, 9, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_04010470_1101C0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(0, 6, 7, 0, 3, 8, 9, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP2Triangles(3, 9, 4, 0, 18, 19, 20, 0),
    gsSP2Triangles(18, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(22, 25, 23, 0, 25, 26, 23, 0),
    gsSP2Triangles(25, 27, 26, 0, 27, 28, 26, 0),
    gsSP2Triangles(27, 29, 28, 0, 29, 30, 28, 0),
    gsSPVertex(D_04010660_1103B0, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 4, 0, 6, 7, 4, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 11, 9, 0),
    gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
    gsSP2Triangles(12, 14, 13, 0, 13, 15, 16, 0),
    gsSP2Triangles(13, 17, 15, 0, 17, 18, 15, 0),
    gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
    gsSP2Triangles(21, 22, 20, 0, 21, 2, 22, 0),
    gsSP2Triangles(5, 23, 24, 0, 5, 4, 23, 0),
    gsSP2Triangles(4, 25, 23, 0, 4, 7, 25, 0),
    gsSP2Triangles(7, 26, 25, 0, 7, 9, 26, 0),
    gsSP2Triangles(9, 27, 26, 0, 9, 11, 27, 0),
    gsSP2Triangles(11, 16, 27, 0, 11, 13, 16, 0),
    gsSP1Triangle(18, 17, 19, 0),
    gsSPEndDisplayList(),
};
