#include <ultra64.h>


Vtx D_05000000_9ED10[8] = {
#include "data/inc/D_05000000_9ED10.inc.c"
};
Vtx D_05000080_9ED90[32] = {
#include "data/inc/D_05000080_9ED90.inc.c"
};
Vtx D_05000280_9EF90[16] = {
#include "data/inc/D_05000280_9EF90.inc.c"
};
Vtx D_05000380_9F090[3] = {
#include "data/inc/D_05000380_9F090.inc.c"
};
Vtx D_050003B0_9F0C0[24] = {
#include "data/inc/D_050003B0_9F0C0.inc.c"
};


Gfx D_05000530_9F240[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_9ED10, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000080_9ED90, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(1, 4, 7, 2, 0),
    gsSP2Triangles(4, 1, 0, 0, 8, 9, 10, 0),
    gsSP2Triangles(8, 10, 11, 0, 12, 11, 10, 0),
    gsSP1Quadrangle(13, 8, 11, 12, 0),
    gsSP1Quadrangle(9, 14, 15, 10, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 19, 23, 0, 24, 25, 23, 0),
    gsSP2Triangles(23, 21, 24, 0, 26, 24, 21, 0),
    gsSP2Triangles(26, 21, 27, 0, 28, 29, 26, 0),
    gsSP2Triangles(30, 29, 28, 0, 23, 30, 28, 0),
    gsSP2Triangles(25, 30, 23, 0, 27, 21, 20, 0),
    gsSP2Triangles(21, 23, 19, 0, 23, 28, 31, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x25, 0x2A, 0x2B, 0xFF),
    gsSPVertex(D_05000280_9EF90, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 0, 6, 0, 7, 5, 8, 0),
    gsSP2Triangles(3, 7, 9, 0, 10, 2, 4, 0),
    gsSP2Triangles(6, 2, 10, 0, 10, 11, 6, 0),
    gsSP2Triangles(8, 6, 11, 0, 11, 12, 8, 0),
    gsSP2Triangles(9, 8, 12, 0, 12, 13, 9, 0),
    gsSP2Triangles(4, 9, 13, 0, 13, 14, 4, 0),
    gsSP2Triangles(15, 10, 4, 0, 2, 6, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 6, 8, 5, 0),
    gsSP2Triangles(8, 9, 7, 0, 9, 4, 3, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x4C, 0x39, 0x0E, 0xFF),
    gsSPVertex(D_05000380_9F090, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050003B0_9F0C0, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
    gsSP2Triangles(5, 10, 3, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 4, 3, 15, 0),
    gsSP2Triangles(17, 18, 19, 0, 15, 14, 4, 0),
    gsSP2Triangles(20, 21, 22, 0, 16, 23, 14, 0),
    gsSPEndDisplayList(),
};
