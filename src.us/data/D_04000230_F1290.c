#include <ultra64.h>

Vtx D_040001B0_F1210[8] = {
#include "data/inc/D_040001B0_F1210.inc.c"
};

Gfx D_04000230_F1290[] = {
    gsSPVertex(D_040001B0_F1210, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(2, 0, 4, 0, 3, 4, 0, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 2, 4, 0),
    gsSP2Triangles(3, 6, 5, 0, 2, 5, 6, 0),
    gsSP2Triangles(6, 3, 7, 0, 7, 2, 6, 0),
    gsSP2Triangles(2, 7, 1, 0, 3, 1, 7, 0),
    gsSPEndDisplayList(),
};
