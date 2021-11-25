#include <ultra64.h>

Vtx D_0400FF10_10FC60[8] = {
#include "data/inc/D_0400FF10_10FC60.inc.c"
};
Vtx D_0400FF90_10FCE0[24] = {
#include "data/inc/D_0400FF90_10FCE0.inc.c"
};

const Gfx D_04010110_10FE60[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400FF10_10FC60, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400FF90_10FCE0, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 1, 0, 0, 7, 0, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 10, 12, 0),
    gsSP2Triangles(13, 12, 2, 0, 14, 2, 1, 0),
    gsSP2Triangles(15, 6, 7, 0, 16, 7, 9, 0),
    gsSP2Triangles(17, 9, 11, 0, 18, 11, 13, 0),
    gsSP2Triangles(19, 13, 14, 0, 20, 14, 6, 0),
    gsSP2Triangles(3, 15, 16, 0, 4, 16, 17, 0),
    gsSP2Triangles(5, 17, 18, 0, 21, 18, 19, 0),
    gsSP2Triangles(22, 19, 20, 0, 23, 20, 15, 0),
    gsSP2Triangles(2, 10, 0, 0, 10, 8, 0, 0),
    gsSP2Triangles(2, 12, 10, 0, 5, 22, 3, 0),
    gsSP2Triangles(22, 23, 3, 0, 5, 21, 22, 0),
    gsSP2Triangles(0, 7, 6, 0, 8, 9, 7, 0),
    gsSP2Triangles(10, 11, 9, 0, 12, 13, 11, 0),
    gsSP2Triangles(2, 14, 13, 0, 1, 6, 14, 0),
    gsSP2Triangles(7, 16, 15, 0, 9, 17, 16, 0),
    gsSP2Triangles(11, 18, 17, 0, 13, 19, 18, 0),
    gsSP2Triangles(14, 20, 19, 0, 6, 15, 20, 0),
    gsSP2Triangles(16, 4, 3, 0, 17, 5, 4, 0),
    gsSP2Triangles(18, 21, 5, 0, 19, 22, 21, 0),
    gsSP2Triangles(20, 23, 22, 0, 15, 3, 23, 0),
    gsSPEndDisplayList(),
};
