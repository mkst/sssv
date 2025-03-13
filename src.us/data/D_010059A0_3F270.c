#include <ultra64.h>

/* Vtxs not actually used by this displaylist */
Vtx D_010057F0_3F0C0[] = {
#include "data/inc/D_010057F0_3F0C0.inc.c"
};


extern Vtx D_010055A0_3EE70[];

Gfx D_010059A0_3F270[] = {
    gsSPVertex(D_010055A0_3EE70, 27, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 0, 0, 0, 4, 3, 0),
    gsSP2Triangles(3, 5, 1, 0, 5, 3, 4, 0),
    gsSP2Triangles(1, 6, 0, 0, 4, 0, 6, 0),
    gsSP2Triangles(6, 1, 5, 0, 7, 9, 8, 0),
    gsSP2Triangles(9, 7, 10, 0, 11, 10, 7, 0),
    gsSP2Triangles(8, 12, 11, 0, 12, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 13, 9, 0),
    gsSP2Triangles(9, 13, 12, 0, 12, 13, 10, 0),
    gsSP2Triangles(14, 16, 15, 0, 16, 14, 17, 0),
    gsSP2Triangles(18, 17, 14, 0, 19, 18, 14, 0),
    gsSP2Triangles(19, 14, 15, 0, 19, 20, 18, 0),
    gsSP2Triangles(19, 21, 20, 0, 19, 22, 21, 0),
    gsSP2Triangles(19, 15, 22, 0, 15, 23, 22, 0),
    gsSP2Triangles(23, 15, 16, 0, 24, 22, 23, 0),
    gsSP2Triangles(22, 24, 21, 0, 25, 21, 24, 0),
    gsSP2Triangles(21, 25, 20, 0, 26, 20, 25, 0),
    gsSP2Triangles(17, 18, 26, 0, 20, 26, 18, 0),
    gsSPEndDisplayList(),
};
