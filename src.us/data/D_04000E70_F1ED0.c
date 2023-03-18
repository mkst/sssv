#include <ultra64.h>

Vtx D_04000E10_F1E70[6] = {
#include "data/inc/D_04000E10_F1E70.inc.c"
};

Gfx D_04000E70_F1ED0[] = {
    gsSPVertex(D_04000E10_F1E70, 6, 0),
    gsSP2Triangles(0, 1, 3, 0, 1, 4, 3, 0),
    gsSP1Quadrangle(1, 2, 5, 4, 0),
    gsSP2Triangles(2, 0, 3, 0, 3, 5, 2, 0),
    gsSPEndDisplayList(),
};
