#include <ultra64.h>

Vtx D_0400DCC0_FED20[11] = {
#include "data/inc/D_0400DCC0_FED20.inc.c"
};

Gfx D_0400DD70_FEDD0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400DCC0_FED20, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 1, 3, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 4, 5, 0, 7, 4, 8, 0),
    gsSP2Triangles(1, 4, 7, 0, 7, 9, 1, 0),
    gsSP2Triangles(10, 1, 9, 0, 2, 1, 10, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
