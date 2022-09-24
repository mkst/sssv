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

Vtx D_0100F548_48E18[15] = {
#include "data/inc/D_0100F548_48E18.inc.c"
};

Gfx D_0100F638_48F08[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x23, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0100F548_48E18, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(7, 0, 9, 0, 9, 2, 10, 0),
    gsSP2Triangles(2, 4, 11, 0, 4, 6, 12, 0),
    gsSP2Triangles(6, 8, 13, 0, 8, 9, 14, 0),
    gsSP2Triangles(2, 9, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(6, 4, 3, 0, 8, 6, 5, 0),
    gsSP2Triangles(9, 8, 7, 0, 10, 14, 9, 0),
    gsSP2Triangles(11, 10, 2, 0, 12, 11, 4, 0),
    gsSP2Triangles(13, 12, 6, 0, 14, 13, 8, 0),
    gsSPEndDisplayList(),
};
