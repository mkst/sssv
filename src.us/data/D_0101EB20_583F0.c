#include <ultra64.h>

Vtx D_0101E9D0_582A0[14] = {
#include "data/inc/D_0101E9D0_582A0.inc.c"
};
Vtx D_0101EAB0_58380[7] = {
#include "data/inc/D_0101EAB0_58380.inc.c"
};

const Gfx D_0101EB20_583F0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0101E9D0_582A0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(0, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 9, 0, 12, 13, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0101EAB0_58380, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
    gsSP1Triangle(5, 1, 6, 0),
    gsSPEndDisplayList(),
};
