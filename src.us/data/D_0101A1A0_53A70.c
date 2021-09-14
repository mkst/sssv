#include <ultra64.h>

Vtx D_01019FA0_53870[8] = {
#include "data/inc/D_01019FA0_53870.inc.c"
};
Vtx D_0101A020_538F0[24] = {
#include "data/inc/D_0101A020_538F0.inc.c"
};

const Gfx D_0101A1A0_53A70[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01019FA0_53870, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101A020_538F0, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(2, 12, 0, 0, 5, 13, 3, 0),
    gsSP2Triangles(8, 14, 6, 0, 11, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(18, 22, 16, 0, 21, 23, 19, 0),
    gsSPEndDisplayList(),
};
