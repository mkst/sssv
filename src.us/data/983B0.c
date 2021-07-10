#include <ultra64.h>


Vtx D_05001060_98080[31] = {
#include "data/inc/D_05001060_98080.inc.c"
};
Vtx D_05001250_98270[20] = {
#include "data/inc/D_05001250_98270.inc.c"
};


const Gfx D_05001390_983B0[] = {
    gsSPVertex(D_05001060_98080, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(0, 4, 1, 0, 0, 5, 6, 0),
    gsSP2Triangles(0, 3, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 15, 19, 13, 0),
    gsSP2Triangles(9, 20, 7, 0, 12, 21, 10, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05001250_98270, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 3, 2, 0, 1, 6, 2, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 18, 0),
    gsSP1Triangle(18, 19, 16, 0),
    gsSPEndDisplayList(),
};
