#include <ultra64.h>

Vtx D_04006E30_EE3E0[31] = {
#include "data/inc/D_04006E30_EE3E0.inc.c"
};
Vtx D_04007020_EE5D0[13] = {
#include "data/inc/D_04007020_EE5D0.inc.c"
};

Gfx D_040070F0_EE6A0[] = {
    gsSPVertex(D_04006E30_EE3E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 0, 7, 0, 0, 8, 9, 0),
    gsSP2Triangles(10, 1, 11, 0, 1, 0, 12, 0),
    gsSP2Triangles(9, 12, 0, 0, 11, 13, 10, 0),
    gsSP2Triangles(12, 11, 1, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 14, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 14, 16, 25, 0),
    gsSP2Triangles(16, 26, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_04007020_EE5D0, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 5, 0, 7, 8, 9, 0),
    gsSP1Triangle(10, 11, 12, 0),
    gsSPEndDisplayList(),
};
