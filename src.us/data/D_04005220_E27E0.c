#include <ultra64.h>

Vtx D_040051A0_E2760[8] = {
#include "data/inc/D_040051A0_E2760.inc.c"
};

Gfx D_04005220_E27E0[] = {
    gsSPVertex(D_040051A0_E2760, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 2, 1, 0),
    gsSP2Triangles(3, 2, 5, 0, 1, 6, 5, 0),
    gsSP2Triangles(6, 4, 7, 0, 7, 5, 6, 0),
    gsSP2Triangles(3, 7, 4, 0, 5, 7, 3, 0),
    gsSPEndDisplayList(),
};
