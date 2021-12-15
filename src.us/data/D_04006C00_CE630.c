#include <ultra64.h>

Vtx D_04006B80_CE5B0[8] = {
#include "data/inc/D_04006B80_CE5B0.inc.c"
};

Gfx D_04006C00_CE630[] = {
    gsSPVertex(D_04006B80_CE5B0, 8, 0),
    gsSP1Quadrangle(1, 0, 4, 5, 0),
    gsSP2Triangles(2, 1, 6, 0, 6, 1, 5, 0),
    gsSP2Triangles(3, 2, 7, 0, 7, 2, 6, 0),
    gsSP2Triangles(3, 7, 0, 0, 0, 7, 4, 0),
    gsSP2Triangles(3, 0, 2, 0, 1, 2, 0, 0),
    gsSP2Triangles(6, 4, 7, 0, 5, 4, 6, 0),
    gsSPEndDisplayList(),
};
