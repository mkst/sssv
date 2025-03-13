#include <ultra64.h>

Vtx D_0400A610_FB670[17] = {
#include "data/inc/D_0400A610_FB670.inc.c"
};

extern Gfx D_010034C0_3CD90[];

Gfx D_0400A720_FB780[] = {
    gsSPVertex(D_0400A610_FB670, 17, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 0, 5, 4, 0),
    gsSP2Triangles(2, 5, 0, 0, 4, 5, 2, 0),
    gsSP2Triangles(6, 4, 3, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 4, 7, 0, 4, 8, 0, 0),
    gsSP2Triangles(0, 8, 9, 0, 9, 1, 0, 0),
    gsSP2Triangles(9, 3, 1, 0, 10, 9, 8, 0),
    gsSP2Triangles(10, 11, 9, 0, 11, 6, 3, 0),
    gsSP2Triangles(3, 9, 11, 0, 11, 10, 12, 0),
    gsSP2Triangles(8, 13, 10, 0, 7, 13, 8, 0),
    gsSP2Triangles(12, 10, 13, 0, 14, 13, 7, 0),
    gsSP2Triangles(13, 14, 12, 0, 15, 12, 14, 0),
    gsSP2Triangles(6, 11, 15, 0, 12, 15, 11, 0),
    gsSP2Triangles(6, 15, 16, 0, 7, 6, 16, 0),
    gsSP2Triangles(7, 16, 14, 0, 14, 16, 15, 0),
    gsSPEndDisplayList(),
};
