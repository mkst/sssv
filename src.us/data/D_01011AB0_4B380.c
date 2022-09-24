#include <ultra64.h>


Vtx D_01011A30_4B300[8] = {
#include "data/inc/D_01011A30_4B300.inc.c"
};

Gfx D_01011AB0_4B380[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01011A30_4B300, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(1, 6, 7, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

Vtx D_01011AF8_4B3C8[] = {
#include "data/inc/D_01011AF8_4B3C8.inc.c"
};

Gfx D_01011B78_4B448[] = {
    gsDPPipeSync(),
    gsSPVertex(D_01011AF8_4B3C8, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 3, 4, 0),
    gsSP2Triangles(4, 6, 5, 0, 2, 5, 6, 0),
    gsSP2Triangles(6, 7, 2, 0, 0, 2, 7, 0),
    gsSPEndDisplayList(),
};
