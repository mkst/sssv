#include <ultra64.h>

Vtx D_04000EA0_F1F00[5] = {
#include "data/inc/D_04000EA0_F1F00.inc.c"
};

Gfx D_04000EF0_F1F50[] = {
#ifdef AVOID_UB
    gsSPVertex(D_04000EA0_F1F00, 5, 0),
#else
    gsSPVertex(D_04000EA0_F1F00, 12, 0),
#endif
    gsSP1Quadrangle(0, 2, 3, 4, 0),
    gsSP2Triangles(0, 4, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(1, 4, 3, 0, 1, 2, 4, 0),
    gsSPEndDisplayList(),
};
