#include <ultra64.h>

Vtx D_050029C0_C7170[8] = {
#include "data/inc/D_050029C0_C7170.inc.c"
};
Vtx D_05002A40_C71F0[32] = {
#include "data/inc/D_05002A40_C71F0.inc.c"
};
Vtx D_05002C40_C73F0[25] = {
#include "data/inc/D_05002C40_C73F0.inc.c"
};
Vtx D_05002DD0_C7580[31] = {
#include "data/inc/D_05002DD0_C7580.inc.c"
};
Vtx D_05002FC0_C7770[3] = {
#include "data/inc/D_05002FC0_C7770.inc.c"
};

const Gfx D_05002FF0_C77A0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_050029C0_C7170, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05002A40_C71F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 2, 3, 0, 4, 5, 6, 0),
    gsSP2Triangles(5, 7, 6, 0, 7, 8, 6, 0),
    gsSP2Triangles(8, 4, 6, 0, 4, 9, 10, 0),
    gsSP2Triangles(5, 10, 11, 0, 7, 11, 12, 0),
    gsSP2Triangles(8, 12, 9, 0, 13, 10, 9, 0),
    gsSP2Triangles(13, 11, 10, 0, 13, 12, 11, 0),
    gsSP2Triangles(13, 9, 12, 0, 14, 15, 16, 0),
    gsSP2Triangles(15, 17, 16, 0, 17, 18, 16, 0),
    gsSP2Triangles(18, 14, 16, 0, 14, 19, 20, 0),
    gsSP2Triangles(15, 20, 21, 0, 17, 21, 22, 0),
    gsSP2Triangles(18, 22, 19, 0, 23, 20, 19, 0),
    gsSP2Triangles(23, 21, 20, 0, 23, 22, 21, 0),
    gsSP2Triangles(23, 19, 22, 0, 24, 25, 26, 0),
    gsSP2Triangles(25, 27, 26, 0, 27, 28, 26, 0),
    gsSP2Triangles(28, 24, 26, 0, 24, 29, 30, 0),
    gsSP1Triangle(25, 30, 31, 0),
    gsSPVertex(D_05002C40_C73F0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 6, 4, 0, 5, 1, 6, 0),
    gsSP2Triangles(5, 2, 1, 0, 5, 4, 2, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 11, 0, 14, 9, 13, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 16, 0),
    gsSP2Triangles(20, 21, 19, 0, 22, 17, 21, 0),
    gsSP2Triangles(6, 23, 24, 0, 1, 0, 23, 0),
    gsSP2Triangles(2, 3, 0, 0, 4, 24, 3, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05002DD0_C7580, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 8, 9, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 12, 13, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 16, 17, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 20, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 24, 25, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05002FC0_C7770, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
