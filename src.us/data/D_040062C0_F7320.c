#include <ultra64.h>

Vtx D_04006240_F72A0[8] = {
#include "data/inc/D_04006240_F72A0.inc.c"
};

Gfx D_040062C0_F7320[] = {
    gsSPVertex(D_04006240_F72A0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 4, 1, 2, 0),
    gsSP2Triangles(4, 5, 3, 0, 0, 3, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 0, 5, 0),
    gsSP2Triangles(4, 7, 6, 0, 2, 0, 7, 0),
    gsSP2Triangles(0, 6, 7, 0, 7, 4, 2, 0),
    gsSPEndDisplayList(),
};
