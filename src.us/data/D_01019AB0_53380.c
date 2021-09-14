#include <ultra64.h>

Vtx D_010198B0_53180[8] = {
#include "data/inc/D_010198B0_53180.inc.c"
};
Vtx D_01019930_53200[24] = {
#include "data/inc/D_01019930_53200.inc.c"
};

const Gfx D_01019AB0_53380[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_010198B0_53180, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01019930_53200, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(2, 12, 0, 0, 5, 13, 3, 0),
    gsSP2Triangles(8, 14, 6, 0, 11, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(18, 22, 16, 0, 21, 23, 19, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
