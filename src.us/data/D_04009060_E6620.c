#include <ultra64.h>

Vtx D_04008DE0_E63A0[30] = {
#include "data/inc/D_04008DE0_E63A0.inc.c"
};
Vtx D_04008FC0_E6580[10] = {
#include "data/inc/D_04008FC0_E6580.inc.c"
};

const Gfx D_04009060_E6620[] = {
    gsSPVertex(D_04008DE0_E63A0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(0, 3, 4, 0, 3, 2, 5, 0),
    gsSP2Triangles(5, 2, 6, 0, 5, 7, 3, 0),
    gsSP2Triangles(3, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(14, 13, 16, 0, 17, 16, 18, 0),
    gsSP2Triangles(12, 18, 10, 0, 11, 10, 19, 0),
    gsSP2Triangles(20, 19, 21, 0, 22, 21, 23, 0),
    gsSP2Triangles(24, 23, 25, 0, 26, 25, 27, 0),
    gsSP2Triangles(28, 27, 29, 0, 15, 29, 13, 0),
    gsSP2Triangles(19, 20, 11, 0, 21, 22, 20, 0),
    gsSP2Triangles(23, 24, 22, 0, 25, 26, 24, 0),
    gsSP2Triangles(29, 15, 28, 0, 27, 28, 26, 0),
    gsSP2Triangles(16, 17, 14, 0, 18, 12, 17, 0),
    gsSPVertex(D_04008FC0_E6580, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(0, 2, 3, 0, 3, 5, 0, 0),
    gsSP2Triangles(0, 5, 6, 0, 7, 5, 3, 0),
    gsSP2Triangles(8, 9, 3, 0, 9, 7, 3, 0),
    gsSPEndDisplayList(),
};
