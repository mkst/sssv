#include <ultra64.h>

Vtx D_04007430_F8490[8] = {
#include "data/inc/D_04007430_F8490.inc.c"
};

Gfx D_040074B0_F8510[] = {
    gsSPVertex(D_04007430_F8490, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(1, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(4, 6, 5, 0, 4, 7, 6, 0),
    gsSP2Triangles(0, 6, 7, 0, 7, 3, 0, 0),
    gsSPEndDisplayList(),
};
