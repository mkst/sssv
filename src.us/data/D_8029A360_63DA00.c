#include <ultra64.h>

Vtx D_8029A060_63D700[24] = {
#include "data/inc/D_8029A060_63D700.inc.c"
};
Vtx D_8029A1E0_63D880[24] = {
#include "data/inc/D_8029A1E0_63D880.inc.c"
};

Gfx D_8029A360_63DA00[] = {
    gsDPPipeSync(),
    gsSPVertex(D_8029A060_63D700, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSPVertex(D_8029A1E0_63D880, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSPEndDisplayList(),
};
