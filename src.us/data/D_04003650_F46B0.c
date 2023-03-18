#include <ultra64.h>

Vtx D_04003570_F45D0[14] = {
#include "data/inc/D_04003570_F45D0.inc.c"
};

Gfx D_04003650_F46B0[] = {
    gsSPVertex(D_04003570_F45D0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 3, 4, 0, 1, 5, 3, 0),
    gsSP2Triangles(5, 1, 6, 0, 1, 0, 6, 0),
    gsSP2Triangles(3, 7, 4, 0, 7, 3, 5, 0),
    gsSP2Triangles(7, 8, 4, 0, 8, 9, 4, 0),
    gsSP2Triangles(0, 10, 6, 0, 9, 11, 4, 0),
    gsSP2Triangles(11, 9, 10, 0, 11, 2, 4, 0),
    gsSP2Triangles(2, 11, 0, 0, 10, 0, 11, 0),
    gsSP2Triangles(12, 5, 6, 0, 5, 12, 7, 0),
    gsSP2Triangles(8, 7, 12, 0, 12, 13, 8, 0),
    gsSP2Triangles(13, 12, 6, 0, 9, 8, 13, 0),
    gsSP2Triangles(10, 13, 6, 0, 13, 10, 9, 0),
    gsSPEndDisplayList(),
};
