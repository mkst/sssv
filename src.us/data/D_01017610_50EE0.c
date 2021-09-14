#include <ultra64.h>

Vtx D_01017270_50B40[8] = {
#include "data/inc/D_01017270_50B40.inc.c"
};
Vtx D_010172F0_50BC0[30] = {
#include "data/inc/D_010172F0_50BC0.inc.c"
};
Vtx D_010174D0_50DA0[8] = {
#include "data/inc/D_010174D0_50DA0.inc.c"
};
Vtx D_01017550_50E20[12] = {
#include "data/inc/D_01017550_50E20.inc.c"
};

const Gfx D_01017610_50EE0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01017270_50B40, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_010172F0_50BC0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 6, 7, 2, 0),
    gsSP2Triangles(1, 3, 2, 0, 8, 9, 2, 0),
    gsSP2Triangles(10, 8, 2, 0, 9, 5, 2, 0),
    gsSP2Triangles(7, 0, 2, 0, 4, 10, 2, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 13, 0),
    gsSP2Triangles(16, 17, 13, 0, 17, 18, 13, 0),
    gsSP2Triangles(12, 14, 13, 0, 19, 20, 13, 0),
    gsSP2Triangles(21, 19, 13, 0, 20, 16, 13, 0),
    gsSP2Triangles(18, 11, 13, 0, 15, 21, 13, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 24, 0),
    gsSP2Triangles(27, 28, 24, 0, 28, 29, 24, 0),
    gsSP1Triangle(23, 25, 24, 0),
    gsSPVertex(D_010174D0_50DA0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 6, 2, 0),
    gsSP1Triangle(7, 3, 2, 0),
    gsSPVertex(D_01017550_50E20, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSPEndDisplayList(),
};
