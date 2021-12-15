#include <ultra64.h>

Vtx D_040058F0_ECEA0[6] = {
#include "data/inc/D_040058F0_ECEA0.inc.c"
};

Gfx D_04005950_ECF00[] = {
    gsSPVertex(D_040058F0_ECEA0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(0, 2, 4, 0, 4, 3, 0, 0),
    gsSP2Triangles(2, 1, 5, 0, 3, 5, 1, 0),
    gsSP1Triangle(5, 4, 2, 0),
    gsSPEndDisplayList(),
};
