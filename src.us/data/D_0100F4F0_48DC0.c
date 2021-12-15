#include <ultra64.h>

Vtx D_0100F410_48CE0[14] = {
#include "data/inc/D_0100F410_48CE0.inc.c"
};

Gfx D_0100F4F0_48DC0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0100F410_48CE0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 8, 2, 0),
    gsSP2Triangles(9, 10, 11, 0, 2, 8, 0, 0),
    gsSP2Triangles(1, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(2, 12, 7, 0, 11, 13, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
