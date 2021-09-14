#include <ultra64.h>

Vtx D_0101C2E0_55BB0[8] = {
#include "data/inc/D_0101C2E0_55BB0.inc.c"
};
Vtx D_0101C360_55C30[31] = {
#include "data/inc/D_0101C360_55C30.inc.c"
};
Vtx D_0101C550_55E20[22] = {
#include "data/inc/D_0101C550_55E20.inc.c"
};

const Gfx D_0101C6B0_55F80[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101C2E0_55BB0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101C360_55C30, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 7, 0),
    gsSP2Triangles(10, 11, 12, 0, 7, 9, 5, 0),
    gsSP2Triangles(13, 14, 15, 0, 5, 16, 3, 0),
    gsSP2Triangles(4, 3, 17, 0, 7, 6, 8, 0),
    gsSP2Triangles(12, 18, 10, 0, 5, 4, 7, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 20, 19, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_0101C550_55E20, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(9, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(11, 17, 18, 0, 2, 1, 8, 0),
    gsSP2Triangles(2, 19, 0, 0, 5, 20, 3, 0),
    gsSP2Triangles(8, 21, 6, 0, 8, 1, 0, 0),
    gsSP1Triangle(0, 20, 8, 0),
    gsSPEndDisplayList(),
};
