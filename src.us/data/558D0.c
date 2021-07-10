#include <ultra64.h>

Vtx D_0101BDC0_55690[] = {
#include "data/inc/D_0101BDC0_55690.inc.c"
};
Vtx D_0101BE40_55710[] = {
#include "data/inc/D_0101BE40_55710.inc.c"
};

Gfx D_0101C000_558D0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101BDC0_55690, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101BE40_55710, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 4, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 11, 0, 15, 12, 16, 0),
    gsSP2Triangles(17, 16, 18, 0, 19, 18, 14, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(23, 21, 20, 0, 24, 20, 26, 0),
    gsSP2Triangles(25, 26, 22, 0, 27, 22, 21, 0),
    gsSP2Triangles(2, 5, 0, 0, 1, 0, 3, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 9, 7, 0),
    gsSP2Triangles(4, 3, 9, 0, 12, 15, 10, 0),
    gsSP2Triangles(11, 10, 13, 0, 16, 17, 15, 0),
    gsSP2Triangles(18, 19, 17, 0, 14, 13, 19, 0),
    gsSP2Triangles(22, 26, 20, 0, 25, 27, 23, 0),
    gsSP2Triangles(20, 24, 23, 0, 26, 25, 24, 0),
    gsSP2Triangles(22, 27, 25, 0, 21, 23, 27, 0),
    gsSPEndDisplayList(),
};
