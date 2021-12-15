#include <ultra64.h>

Vtx D_01017DB0_51680[16] = {
#include "data/inc/D_01017DB0_51680.inc.c"
};

Gfx D_01017EB0_51780[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01017DB0_51680, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(3, 1, 0, 0, 4, 0, 2, 0),
    gsSP2Triangles(4, 2, 3, 0, 4, 0, 3, 0),
    gsSP2Triangles(5, 6, 7, 0, 6, 5, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 8, 0),
    gsSP2Triangles(10, 9, 14, 0, 13, 12, 15, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
