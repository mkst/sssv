#include <ultra64.h>

Vtx D_0100F6B0_48F80[12] = {
#include "data/inc/D_0100F6B0_48F80.inc.c"
};
Vtx D_0100F770_49040[6] = {
#include "data/inc/D_0100F770_49040.inc.c"
};
Vtx D_0100F7D0_490A0[15] = {
#include "data/inc/D_0100F7D0_490A0.inc.c"
};

Gfx D_0100F8C0_49190[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x2E, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0100F6B0_48F80, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0100F770_49040, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 0, 5, 4, 0),
    gsSP1Triangle(0, 2, 5, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_0100F7D0_490A0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 2, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(4, 3, 8, 0, 9, 8, 1, 0),
    gsSP2Triangles(2, 6, 0, 0, 8, 9, 4, 0),
    gsSP2Triangles(1, 0, 9, 0, 7, 5, 6, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Triangle(12, 14, 13, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
