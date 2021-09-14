#include <ultra64.h>

Vtx D_01017BB0_51480[10] = {
#include "data/inc/D_01017BB0_51480.inc.c"
};

const Gfx D_01017C50_51520[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01017BB0_51480, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 3, 4, 5, 0),
    gsSP2Triangles(7, 8, 9, 0, 3, 7, 8, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
