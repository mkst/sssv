#include <ultra64.h>

Vtx D_040002E0_E7890[9] = {
#include "data/inc/D_040002E0_E7890.inc.c"
};

Gfx D_04000370_E7920[] = {
    gsSPVertex(D_040002E0_E7890, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(3, 2, 6, 0, 2, 5, 7, 0),
    gsSP2Triangles(7, 6, 2, 0, 5, 3, 8, 0),
    gsSP2Triangles(6, 8, 3, 0, 8, 7, 5, 0),
    gsSPEndDisplayList(),
};
