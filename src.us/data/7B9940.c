#include <ultra64.h>

Vtx D_803A7ED0[32] = {
#include "data/inc/D_803A7ED0.inc.c"
};

Vtx D_803A80D0[28] = {
#include "data/inc/D_803A80D0.inc.c"
};

const Gfx D_803A8290_7B9940[21] = {
    gsSPVertex(D_803A7ED0, 32, 0),
    gsDPPipeSync(),
    gsSP2Triangles(1, 0, 2, 0, 3, 2, 0, 0),
    gsSP2Triangles(5, 4, 6, 0, 4, 7, 5, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 6, 4, 0),
    gsSP2Triangles(8, 5, 7, 0, 11, 9, 8, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 14, 12, 0),
    gsSP2Triangles(17, 16, 18, 0, 19, 18, 16, 0),
    gsSP2Triangles(21, 20, 22, 0, 22, 20, 23, 0),
    gsSP2Triangles(25, 24, 26, 0, 26, 24, 27, 0),
    gsSP2Triangles(29, 28, 30, 0, 30, 28, 31, 0),
    gsSPVertex(D_803A80D0, 28, 0),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 3, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 4, 7, 0),
    gsSP2Triangles(9, 8, 10, 0, 10, 8, 11, 0),
    gsSP2Triangles(2, 3, 12, 0, 12, 3, 13, 0),
    gsSP2Triangles(15, 14, 9, 0, 9, 14, 8, 0),
    gsSP2Triangles(17, 16, 18, 0, 19, 18, 16, 0),
    gsSP2Triangles(21, 20, 22, 0, 23, 22, 20, 0),
    gsSP2Triangles(25, 24, 26, 0, 27, 26, 24, 0),
    gsSPEndDisplayList(),
};
