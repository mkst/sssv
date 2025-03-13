#include <ultra64.h>

Vtx D_0400EDE0_D6810[31] = {
#include "data/inc/D_0400EDE0_D6810.inc.c"
};
Vtx D_0400EFD0_D6A00[13] = {
#include "data/inc/D_0400EFD0_D6A00.inc.c"
};

Gfx D_0400F0A0_D6AD0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400EDE0_D6810, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(5, 12, 3, 0, 8, 13, 6, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(16, 26, 14, 0, 22, 27, 20, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_0400EFD0_D6A00, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(5, 12, 3, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
