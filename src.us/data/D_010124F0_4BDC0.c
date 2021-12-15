#include <ultra64.h>

Vtx D_01012330_4BC00[8] = {
#include "data/inc/D_01012330_4BC00.inc.c"
};
Vtx D_010123B0_4BC80[20] = {
#include "data/inc/D_010123B0_4BC80.inc.c"
};

Gfx D_010124F0_4BDC0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01012330_4BC00, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_010123B0_4BC80, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 6, 0, 6, 10, 8, 0),
    gsSP2Triangles(11, 12, 2, 0, 2, 13, 11, 0),
    gsSP2Triangles(14, 15, 6, 0, 6, 16, 14, 0),
    gsSP2Triangles(17, 18, 2, 0, 2, 19, 17, 0),
    gsSPEndDisplayList(),
};
