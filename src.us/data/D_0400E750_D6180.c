#include <ultra64.h>


Vtx D_0400E2D0_D5D00[18] = {
#include "data/inc/D_0400E2D0_D5D00.inc.c"
};
Vtx D_0400E3F0_D5E20[31] = {
#include "data/inc/D_0400E3F0_D5E20.inc.c"
};
Vtx D_0400E5E0_D6010[14] = {
#include "data/inc/D_0400E5E0_D6010.inc.c"
};
Vtx D_0400E6C0_D60F0[3] = {
#include "data/inc/D_0400E6C0_D60F0.inc.c"
};
Vtx D_0400E6F0_D6120[6] = {
#include "data/inc/D_0400E6F0_D6120.inc.c"
};


Gfx D_0400E750_D6180[] = {
    gsSPVertex(D_0400E2D0_D5D00, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 5, 7, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(10, 12, 11, 0, 13, 12, 10, 0),
    gsSP2Triangles(14, 6, 2, 0, 15, 6, 14, 0),
    gsSP2Triangles(0, 6, 15, 0, 1, 2, 14, 0),
    gsSP2Triangles(9, 10, 13, 0, 8, 11, 12, 0),
    gsSP2Triangles(16, 5, 4, 0, 7, 5, 16, 0),
    gsSP2Triangles(17, 7, 16, 0, 7, 17, 3, 0),
    gsSP2Triangles(15, 14, 1, 0, 1, 0, 15, 0),
    gsSPVertex(D_0400E3F0_D5E20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 9, 10, 0),
    gsSP2Triangles(8, 9, 6, 0, 10, 11, 6, 0),
    gsSP2Triangles(11, 12, 6, 0, 13, 9, 14, 0),
    gsSP2Triangles(10, 9, 13, 0, 15, 6, 12, 0),
    gsSP2Triangles(16, 4, 17, 0, 18, 10, 13, 0),
    gsSP2Triangles(16, 17, 19, 0, 19, 17, 20, 0),
    gsSP2Triangles(20, 4, 21, 0, 17, 4, 20, 0),
    gsSP2Triangles(22, 23, 21, 0, 18, 13, 24, 0),
    gsSP2Triangles(20, 21, 23, 0, 5, 4, 16, 0),
    gsSP2Triangles(13, 14, 24, 0, 15, 7, 6, 0),
    gsSP2Triangles(2, 1, 25, 0, 21, 4, 22, 0),
    gsSP2Triangles(26, 5, 16, 0, 5, 26, 3, 0),
    gsSP2Triangles(27, 11, 10, 0, 18, 27, 10, 0),
    gsSP2Triangles(28, 24, 13, 0, 29, 30, 13, 0),
    gsSP1Triangle(13, 14, 29, 0),
    gsSPVertex(D_0400E5E0_D6010, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(3, 5, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 13, 7, 0, 13, 3, 7, 0),
    gsSP1Triangle(0, 3, 13, 0),
    gsSPVertex(D_0400E6C0_D60F0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_0400E6F0_D6120, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 0, 4, 0),
    gsSP1Triangle(1, 0, 5, 0),
    gsSPEndDisplayList(),
};
