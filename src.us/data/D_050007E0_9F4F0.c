#include <ultra64.h>


Vtx D_050006C0_9F3D0[8] = {
#include "data/inc/D_050006C0_9F3D0.inc.c"
};
Vtx D_05000740_9F450[10] = {
#include "data/inc/D_05000740_9F450.inc.c"
};


Gfx D_050007E0_9F4F0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_050006C0_9F3D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000740_9F450, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 7, 0, 8, 6, 2, 0),
    gsSP2Triangles(9, 8, 1, 0, 4, 9, 0, 0),
    gsSP2Triangles(0, 2, 5, 0, 2, 7, 5, 0),
    gsSP2Triangles(5, 7, 3, 0, 7, 2, 6, 0),
    gsSP2Triangles(2, 1, 8, 0, 1, 0, 9, 0),
    gsSP1Triangle(0, 5, 4, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
