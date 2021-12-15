#include <ultra64.h>

Vtx D_05002DB0_959A0[8] = {
#include "data/inc/D_05002DB0_959A0.inc.c"
};
Vtx D_05002E30_95A20[32] = {
#include "data/inc/D_05002E30_95A20.inc.c"
};
Vtx D_05003030_95C20[31] = {
#include "data/inc/D_05003030_95C20.inc.c"
};
Vtx D_05003220_95E10[19] = {
#include "data/inc/D_05003220_95E10.inc.c"
};

Gfx D_05003350_95F40[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05002DB0_959A0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05002E30_95A20, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05003030_95C20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 5, 9, 3, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 12, 11, 0, 11, 13, 16, 0),
    gsSP2Triangles(17, 5, 4, 0, 15, 16, 13, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(4, 6, 17, 0, 8, 17, 6, 0),
    gsSP2Triangles(12, 24, 10, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05003220_95E10, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 5, 4, 0, 7, 15, 6, 0),
    gsSP2Triangles(4, 16, 14, 0, 10, 17, 8, 0),
    gsSP2Triangles(13, 18, 11, 0, 12, 8, 17, 0),
    gsSP1Triangle(17, 13, 12, 0),
    gsSPEndDisplayList(),
};
