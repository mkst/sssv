#include <ultra64.h>


Vtx D_0400E780_FF7E0[8] = {
#include "data/inc/D_0400E780_FF7E0.inc.c"
};
Vtx D_0400E800_FF860[32] = {
#include "data/inc/D_0400E800_FF860.inc.c"
};
Vtx D_0400EA00_FFA60[21] = {
#include "data/inc/D_0400EA00_FFA60.inc.c"
};
Vtx D_0400EB50_FFBB0[7] = {
#include "data/inc/D_0400EB50_FFBB0.inc.c"
};


const Gfx D_0400EBC0_FFC20[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400E780_FF7E0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400E800_FF860, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 9, 10, 0),
    gsSP2Triangles(7, 10, 8, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 13, 15, 16, 0),
    gsSP2Triangles(13, 16, 14, 0, 14, 16, 9, 0),
    gsSP2Triangles(12, 17, 13, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 19, 13, 0, 13, 19, 15, 0),
    gsSP2Triangles(6, 8, 20, 0, 8, 11, 21, 0),
    gsSP2Triangles(8, 21, 20, 0, 20, 21, 18, 0),
    gsSP2Triangles(22, 23, 24, 0, 23, 25, 26, 0),
    gsSP2Triangles(23, 26, 24, 0, 24, 26, 27, 0),
    gsSP2Triangles(22, 24, 28, 0, 24, 29, 30, 0),
    gsSP2Triangles(24, 30, 28, 0, 28, 30, 31, 0),
    gsSPVertex(D_0400EA00_FFA60, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 4, 5, 0),
    gsSP2Triangles(0, 2, 6, 0, 2, 7, 8, 0),
    gsSP2Triangles(2, 8, 6, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 12, 11, 0),
    gsSP2Triangles(11, 14, 13, 0, 3, 9, 8, 0),
    gsSP2Triangles(5, 3, 8, 0, 3, 15, 9, 0),
    gsSP2Triangles(16, 15, 3, 0, 3, 17, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 10, 19, 18, 0),
    gsSP2Triangles(12, 19, 10, 0, 5, 4, 3, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400EB50_FFBB0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP1Triangle(5, 6, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
