#include <ultra64.h>

Vtx D_0101BA50_55320[8] = {
#include "data/inc/D_0101BA50_55320.inc.c"
};
Vtx D_0101BAD0_553A0[30] = {
#include "data/inc/D_0101BAD0_553A0.inc.c"
};
Vtx D_0101BCB0_55580[6] = {
#include "data/inc/D_0101BCB0_55580.inc.c"
};

Gfx D_0101BD10_555E0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101BA50_55320, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101BAD0_553A0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
    gsSP2Triangles(5, 1, 0, 0, 5, 3, 1, 0),
    gsSP2Triangles(5, 4, 3, 0, 5, 0, 4, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(8, 24, 6, 0, 11, 25, 9, 0),
    gsSP2Triangles(14, 26, 12, 0, 17, 27, 15, 0),
    gsSP2Triangles(20, 28, 18, 0, 23, 29, 21, 0),
    gsSPVertex(D_0101BCB0_55580, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
    gsSP2Triangles(5, 1, 0, 0, 5, 3, 1, 0),
    gsSP2Triangles(5, 4, 3, 0, 5, 0, 4, 0),
    gsSPEndDisplayList(),
};
