#include <ultra64.h>

Vtx D_0101E850_58120[8] = {
#include "data/inc/D_0101E850_58120.inc.c"
};
Vtx D_0101E8D0_581A0[10] = {
#include "data/inc/D_0101E8D0_581A0.inc.c"
};

Gfx D_0101E970_58240[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101E850_58120, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101E8D0_581A0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 3, 2, 4, 0),
    gsSP2Triangles(1, 0, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 5, 0, 5, 4, 9, 0),
    gsSP2Triangles(8, 9, 7, 0, 6, 7, 1, 0),
    gsSPEndDisplayList(),
};
