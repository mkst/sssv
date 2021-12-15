#include <ultra64.h>

Vtx D_0100F250_48B20[24] = {
#include "data/inc/D_0100F250_48B20.inc.c"
};

Gfx D_0100F3D0_48CA0[] = {
    gsSPVertex(D_0100F250_48B20, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 16, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 23, 20, 0),
    gsSPEndDisplayList(),
};
