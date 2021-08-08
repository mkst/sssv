#include <ultra64.h>


Vtx D_05000000_C4510[8] = {
#include "data/inc/D_05000000_C4510.inc.c"
};
Vtx D_05000080_C4590[21] = {
#include "data/inc/D_05000080_C4590.inc.c"
};


const Gfx D_050001D0_C46E0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_C4510, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05000080_C4590, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 10, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 14, 7, 0),
    gsSP2Triangles(7, 16, 17, 0, 8, 17, 18, 0),
    gsSP2Triangles(10, 18, 19, 0, 12, 19, 20, 0),
    gsSP2Triangles(14, 20, 16, 0, 16, 2, 1, 0),
    gsSP2Triangles(17, 1, 3, 0, 18, 3, 4, 0),
    gsSP2Triangles(19, 4, 5, 0, 20, 5, 2, 0),
    gsSP2Triangles(8, 9, 6, 0, 10, 11, 9, 0),
    gsSP2Triangles(12, 13, 11, 0, 14, 15, 13, 0),
    gsSP2Triangles(7, 6, 15, 0, 17, 8, 7, 0),
    gsSP2Triangles(18, 10, 8, 0, 19, 12, 10, 0),
    gsSP2Triangles(20, 14, 12, 0, 16, 7, 14, 0),
    gsSP2Triangles(1, 17, 16, 0, 3, 18, 17, 0),
    gsSP2Triangles(4, 19, 18, 0, 5, 20, 19, 0),
    gsSP1Triangle(2, 16, 20, 0),
    gsSPEndDisplayList(),
};
