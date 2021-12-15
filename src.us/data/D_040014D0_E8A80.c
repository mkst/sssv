#include <ultra64.h>

Vtx D_04001440_E89F0[9] = {
#include "data/inc/D_04001440_E89F0.inc.c"
};

Gfx D_040014D0_E8A80[] = {
    gsSPVertex(D_04001440_E89F0, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 2, 0, 2, 7, 5, 0),
    gsSP2Triangles(7, 2, 6, 0, 5, 8, 3, 0),
    gsSP2Triangles(6, 3, 8, 0, 8, 5, 7, 0),
    gsSPEndDisplayList(),
};
