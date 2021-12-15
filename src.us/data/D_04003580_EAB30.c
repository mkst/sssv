#include <ultra64.h>

Vtx D_04003500_EAAB0[8] = {
#include "data/inc/D_04003500_EAAB0.inc.c"
};

Gfx D_04003580_EAB30[] = {
    gsSPVertex(D_04003500_EAAB0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(3, 4, 1, 0, 2, 1, 4, 0),
    gsSP2Triangles(5, 4, 3, 0, 4, 5, 2, 0),
    gsSP2Triangles(2, 5, 6, 0, 3, 6, 5, 0),
    gsSP2Triangles(7, 6, 3, 0, 6, 7, 2, 0),
    gsSP2Triangles(2, 7, 0, 0, 3, 0, 7, 0),
    gsSPEndDisplayList(),
};
