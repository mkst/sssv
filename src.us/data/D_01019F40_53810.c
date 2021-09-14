#include <ultra64.h>

Vtx D_01019D00_535D0[8] = {
#include "data/inc/D_01019D00_535D0.inc.c"
};
Vtx D_01019D80_53650[28] = {
#include "data/inc/D_01019D80_53650.inc.c"
};

const Gfx D_01019F40_53810[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01019D00_535D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_01019D80_53650, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(2, 18, 0, 0, 5, 19, 3, 0),
    gsSP2Triangles(8, 20, 6, 0, 21, 22, 23, 0),
    gsSP2Triangles(14, 24, 12, 0, 25, 26, 27, 0),
    gsSPEndDisplayList(),
};
