#include <ultra64.h>

Vtx D_0101C0B0_55980[8] = {
#include "data/inc/D_0101C0B0_55980.inc.c"
};
Vtx D_0101C130_55A00[18] = {
#include "data/inc/D_0101C130_55A00.inc.c"
};

Gfx D_0101C250_55B20[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101C0B0_55980, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101C130_55A00, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 1, 0, 0, 4, 0, 6, 0),
    gsSP2Triangles(5, 6, 2, 0, 7, 2, 1, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 10, 14, 0, 15, 14, 16, 0),
    gsSP2Triangles(17, 16, 12, 0, 2, 6, 0, 0),
    gsSP2Triangles(5, 7, 3, 0, 0, 4, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 2, 7, 5, 0),
    gsSP2Triangles(1, 3, 7, 0, 10, 13, 8, 0),
    gsSP2Triangles(9, 8, 11, 0, 14, 15, 13, 0),
    gsSP2Triangles(16, 17, 15, 0, 12, 11, 17, 0),
    gsSPEndDisplayList(),
};
