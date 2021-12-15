#include <ultra64.h>

Vtx D_04001FC0_E9570[6] = {
#include "data/inc/D_04001FC0_E9570.inc.c"
};

Gfx D_04002020_E95D0[] = {
    gsSPVertex(D_04001FC0_E9570, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(1, 3, 4, 0, 4, 5, 0, 0),
    gsSP2Triangles(2, 0, 5, 0, 5, 4, 3, 0),
    gsSPEndDisplayList(),
};
