#include <ultra64.h>


Vtx D_01011A30_4B300[8] = {
#include "data/inc/D_01011A30_4B300.inc.c"
};


const Gfx D_01011AB0_4B380[] = {
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
