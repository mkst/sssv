#include <ultra64.h>

Vtx D_0101A3C0_53C90[8] = {
#include "data/inc/D_0101A3C0_53C90.inc.c"
};
Vtx D_0101A440_53D10[24] = {
#include "data/inc/D_0101A440_53D10.inc.c"
};

const Gfx D_0101A5C0_53E90[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101A3C0_53C90, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101A440_53D10, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(2, 18, 0, 0, 5, 19, 3, 0),
    gsSP2Triangles(8, 20, 6, 0, 11, 21, 9, 0),
    gsSP2Triangles(14, 22, 12, 0, 17, 23, 15, 0),
    gsSPEndDisplayList(),
};
