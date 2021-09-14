#include <ultra64.h>

Vtx D_05000BB0_B3A80[8] = {
#include "data/inc/D_05000BB0_B3A80.inc.c"
};
Vtx D_05000C30_B3B00[6] = {
#include "data/inc/D_05000C30_B3B00.inc.c"
};
Vtx D_05000C90_B3B60[25] = {
#include "data/inc/D_05000C90_B3B60.inc.c"
};

const Gfx D_05000E20_B3CF0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000BB0_B3A80, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000C30_B3B00, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000C90_B3B60, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(11, 21, 9, 0, 14, 22, 12, 0),
    gsSP2Triangles(17, 23, 15, 0, 20, 24, 18, 0),
    gsSPEndDisplayList(),
};
