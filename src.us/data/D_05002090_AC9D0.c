#include <ultra64.h>

Vtx D_05001790_AC0D0[31] = {
#include "data/inc/D_05001790_AC0D0.inc.c"
};
Vtx D_05001980_AC2C0[31] = {
#include "data/inc/D_05001980_AC2C0.inc.c"
};
Vtx D_05001B70_AC4B0[11] = {
#include "data/inc/D_05001B70_AC4B0.inc.c"
};
Vtx D_05001C20_AC560[32] = {
#include "data/inc/D_05001C20_AC560.inc.c"
};
Vtx D_05001E20_AC760[30] = {
#include "data/inc/D_05001E20_AC760.inc.c"
};
Vtx D_05002000_AC940[9] = {
#include "data/inc/D_05002000_AC940.inc.c"
};

Gfx D_05002090_AC9D0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05001790_AC0D0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 2, 27, 0, 0),
    gsSP2Triangles(5, 28, 3, 0, 8, 29, 6, 0),
    gsSP1Triangle(11, 30, 9, 0),
    gsSPVertex(D_05001980_AC2C0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(16, 18, 17, 0, 18, 19, 17, 0),
    gsSP2Triangles(19, 20, 17, 0, 20, 15, 17, 0),
    gsSP2Triangles(21, 22, 23, 0, 22, 24, 23, 0),
    gsSP2Triangles(24, 25, 23, 0, 25, 26, 23, 0),
    gsSP2Triangles(26, 21, 23, 0, 27, 28, 29, 0),
    gsSP1Triangle(28, 30, 29, 0),
    gsSPVertex(D_05001B70_AC4B0, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 5, 6, 7, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
    gsSP2Triangles(9, 10, 7, 0, 10, 5, 7, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05001C20_AC560, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 5, 3, 2, 0),
    gsSP2Triangles(3, 4, 0, 0, 1, 0, 4, 0),
    gsSP2Triangles(2, 1, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(13, 11, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(14, 9, 12, 0, 10, 14, 13, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 16, 0, 20, 18, 17, 0),
    gsSP2Triangles(18, 19, 15, 0, 16, 15, 19, 0),
    gsSP2Triangles(17, 16, 20, 0, 7, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP2Triangles(27, 25, 24, 0, 25, 26, 23, 0),
    gsSP2Triangles(28, 23, 26, 0, 24, 28, 27, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05001E20_AC760, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 3, 5, 0),
    gsSP2Triangles(1, 5, 3, 0, 6, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 10, 9, 0),
    gsSP2Triangles(10, 8, 7, 0, 8, 11, 6, 0),
    gsSP2Triangles(9, 6, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(19, 17, 16, 0, 17, 18, 15, 0),
    gsSP2Triangles(20, 15, 18, 0, 16, 20, 19, 0),
    gsSP2Triangles(21, 14, 13, 0, 22, 21, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 27, 28, 0),
    gsSP2Triangles(27, 24, 29, 0, 26, 29, 24, 0),
    gsSP2Triangles(28, 26, 25, 0, 29, 28, 27, 0),
    gsSPVertex(D_05002000_AC940, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 2, 1, 0, 2, 4, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 1, 3, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPEndDisplayList(),
};
