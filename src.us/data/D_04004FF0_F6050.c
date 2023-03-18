#include <ultra64.h>

Vtx D_04004F90_F5FF0[6] = {
#include "data/inc/D_04004F90_F5FF0.inc.c"
};

Gfx D_04004FF0_F6050[] = {
    gsSPVertex(D_04004F90_F5FF0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 2, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 2, 3, 0),
    gsSP2Triangles(0, 5, 1, 0, 3, 1, 5, 0),
    gsSP1Triangle(5, 0, 4, 0),
    gsSPEndDisplayList(),
};
