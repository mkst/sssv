#include <ultra64.h>

Vtx D_05004870_AF1B0[8] = {
#include "data/inc/D_05004870_AF1B0.inc.c"
};
Vtx D_050048F0_AF230[28] = {
#include "data/inc/D_050048F0_AF230.inc.c"
};

Gfx D_05004AB0_AF3F0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05004870_AF1B0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050048F0_AF230, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 2, 15, 0, 0),
    gsSP2Triangles(5, 16, 3, 0, 8, 17, 6, 0),
    gsSP2Triangles(11, 18, 9, 0, 14, 19, 12, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 20, 0),
    gsSP2Triangles(25, 23, 20, 0, 20, 26, 25, 0),
    gsSP1Triangle(22, 27, 20, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
