#include <ultra64.h>

Vtx D_0101D4C0_56D90[8] = {
#include "data/inc/D_0101D4C0_56D90.inc.c"
};
Vtx D_0101D540_56E10[24] = {
#include "data/inc/D_0101D540_56E10.inc.c"
};

Gfx D_0101D6C0_56F90[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101D4C0_56D90, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0101D540_56E10, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 2, 21, 0, 0),
    gsSP2Triangles(5, 22, 3, 0, 8, 23, 6, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
