#include <ultra64.h>

Vtx D_04010000_D7A30[8] = {
#include "data/inc/D_04010000_D7A30.inc.c"
};

Gfx D_04010080_D7AB0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04010000_D7A30, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 3, 5, 0, 2, 6, 0, 0),
    gsSP2Triangles(1, 5, 3, 0, 5, 7, 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 4, 3, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 1, 5, 3, 0),
    gsSP1Triangle(5, 7, 4, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
