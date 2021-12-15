#include <ultra64.h>

Vtx D_04003680_EAC30[5] = {
#include "data/inc/D_04003680_EAC30.inc.c"
};

Gfx D_040036D0_EAC80[] = {
    gsSPVertex(D_04003680_EAC30, 5, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 4, 2, 0, 4, 1, 2, 0),
    gsSPEndDisplayList(),
};
