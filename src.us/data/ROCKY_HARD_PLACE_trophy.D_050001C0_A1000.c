#include <ultra64.h>


Vtx D_05000000_A0E40[8] = {
#include "data/inc/D_05000000_A0E40.inc.c"
};
Vtx D_05000080_A0EC0[20] = {
#include "data/inc/D_05000080_A0EC0.inc.c"
};

const Gfx D_050001C0_A1000[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_A0E40, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05000080_A0EC0, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(0, 2, 4, 0, 2, 5, 6, 0),
    gsSP2Triangles(5, 7, 8, 0, 7, 1, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 3, 12, 0),
    gsSP2Triangles(9, 14, 15, 0, 16, 9, 1, 0),
    gsSP2Triangles(13, 9, 16, 0, 17, 3, 0, 0),
    gsSP2Triangles(12, 4, 10, 0, 3, 17, 12, 0),
    gsSP2Triangles(18, 4, 2, 0, 10, 6, 11, 0),
    gsSP2Triangles(4, 18, 10, 0, 19, 6, 5, 0),
    gsSP2Triangles(11, 8, 14, 0, 6, 19, 11, 0),
    gsSP2Triangles(15, 8, 7, 0, 8, 15, 14, 0),
    gsSP2Triangles(7, 5, 1, 0, 5, 2, 1, 0),
    gsSP2Triangles(1, 3, 16, 0, 0, 4, 17, 0),
    gsSP2Triangles(2, 6, 18, 0, 5, 8, 19, 0),
    gsSP2Triangles(7, 9, 15, 0, 14, 13, 11, 0),
    gsSP2Triangles(13, 12, 11, 0, 13, 16, 3, 0),
    gsSP2Triangles(9, 13, 14, 0, 12, 17, 4, 0),
    gsSP2Triangles(10, 18, 6, 0, 11, 19, 8, 0),
    gsSPEndDisplayList(),
};
