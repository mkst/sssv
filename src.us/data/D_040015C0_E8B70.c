#include <ultra64.h>

Vtx D_04001510_E8AC0[5] = {
#include "data/inc/D_04001510_E8AC0.inc.c"
};
Vtx D_04001560_E8B10[6] = {
#include "data/inc/D_04001560_E8B10.inc.c"
};

Gfx D_040015C0_E8B70[] = {
    gsSPVertex(D_04001510_E8AC0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(0, 4, 1, 0, 4, 3, 1, 0),
    gsSP2Triangles(0, 2, 4, 0, 2, 3, 4, 0),
    gsSPVertex(D_04001560_E8B10, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(1, 3, 4, 0, 4, 2, 1, 0),
    gsSP2Triangles(3, 0, 5, 0, 2, 5, 0, 0),
    gsSP1Triangle(5, 4, 3, 0),
    gsSPEndDisplayList(),
};
