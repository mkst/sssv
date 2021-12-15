#include <ultra64.h>

Vtx D_040038D0_E0E90[6] = {
#include "data/inc/D_040038D0_E0E90.inc.c"
};

Gfx D_04003930_E0EF0[] = {
    gsSPVertex(D_040038D0_E0E90, 6, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 1, 0, 5, 3, 2, 0),
    gsSP2Triangles(5, 4, 3, 0, 5, 1, 4, 0),
    gsSPEndDisplayList(),
};
