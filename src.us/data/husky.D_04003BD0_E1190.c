#include <ultra64.h>

Vtx D_04003B50_E1110[8] = {
#include "data/inc/D_04003B50_E1110.inc.c"
};

Gfx D_04003BD0_E1190[] = {
    gsSPVertex(D_04003B50_E1110, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 1, 2, 0),
    gsSP2Triangles(3, 5, 2, 0, 1, 5, 6, 0),
    gsSP2Triangles(6, 7, 4, 0, 7, 6, 5, 0),
    gsSP2Triangles(3, 4, 7, 0, 5, 3, 7, 0),
    gsSPEndDisplayList(),
};
