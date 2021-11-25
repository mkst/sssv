#include <ultra64.h>

Vtx D_04006080_E3640[6] = {
#include "data/inc/D_04006080_E3640.inc.c"
};
Vtx D_040060E0_E36A0[9] = {
#include "data/inc/D_040060E0_E36A0.inc.c"
};

const Gfx D_04006170_E3730[] = {
    gsSPVertex(D_04006080_E3640, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 3, 4, 0, 3, 5, 1, 0),
    gsSPVertex(D_040060E0_E36A0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(2, 1, 4, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 4, 6, 0, 1, 0, 6, 0),
    gsSP2Triangles(6, 4, 1, 0, 6, 7, 5, 0),
    gsSP2Triangles(7, 3, 2, 0, 2, 5, 7, 0),
    gsSP2Triangles(8, 3, 7, 0, 8, 0, 3, 0),
    gsSP2Triangles(8, 6, 0, 0, 8, 7, 6, 0),
    gsSPEndDisplayList(),
};
