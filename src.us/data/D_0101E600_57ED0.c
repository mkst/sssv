#include <ultra64.h>

Vtx D_0101E3B0_57C80[31] = {
#include "data/inc/D_0101E3B0_57C80.inc.c"
};
Vtx D_0101E5A0_57E70[6] = {
#include "data/inc/D_0101E5A0_57E70.inc.c"
};

Gfx D_0101E600_57ED0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0101E3B0_57C80, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 6, 5, 4, 0),
    gsSP2Triangles(0, 7, 1, 0, 2, 1, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 10, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 17, 12, 0, 10, 13, 8, 0),
    gsSP2Triangles(9, 8, 11, 0, 14, 19, 13, 0),
    gsSP2Triangles(17, 18, 15, 0, 12, 11, 18, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 22, 21, 0),
    gsSP2Triangles(20, 22, 23, 0, 24, 15, 18, 0),
    gsSP2Triangles(25, 19, 26, 0, 13, 19, 25, 0),
    gsSP2Triangles(27, 13, 25, 0, 8, 13, 27, 0),
    gsSP2Triangles(28, 8, 27, 0, 11, 8, 28, 0),
    gsSP2Triangles(29, 11, 28, 0, 18, 11, 29, 0),
    gsSP2Triangles(30, 18, 29, 0, 24, 18, 30, 0),
    gsSPVertex(D_0101E5A0_57E70, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 4, 0, 0),
    gsSP1Triangle(0, 2, 5, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
