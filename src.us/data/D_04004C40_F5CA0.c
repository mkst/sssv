#include <ultra64.h>

Vtx D_04004BE0_F5C40[6] = {
#include "data/inc/D_04004BE0_F5C40.inc.c"
};

Gfx D_04004C40_F5CA0[] = {
    gsSPVertex(D_04004BE0_F5C40, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(3, 0, 4, 0, 1, 4, 0, 0),
    gsSP2Triangles(5, 2, 3, 0, 4, 1, 5, 0),
    gsSP1Triangle(2, 5, 1, 0),
    gsSPEndDisplayList(),
};
