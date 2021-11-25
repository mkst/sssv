#include <ultra64.h>

Vtx D_04000580_F15E0[8] = {
#include "data/inc/D_04000580_F15E0.inc.c"
};

const Gfx D_04000600_F1660[] = {
    gsSPVertex(D_04000580_F15E0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(2, 0, 4, 0, 3, 4, 0, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 2, 4, 0),
    gsSP2Triangles(3, 6, 5, 0, 2, 5, 6, 0),
    gsSP2Triangles(6, 3, 7, 0, 7, 2, 6, 0),
    gsSP2Triangles(2, 7, 1, 0, 3, 1, 7, 0),
    gsSPEndDisplayList(),
};
