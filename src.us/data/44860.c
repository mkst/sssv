#include <ultra64.h>


Vtx D_0100AB30_44400[31] = {
#include "data/inc/D_0100AB30_44400.inc.c"
};
Vtx D_0100AD20_445F0[23] = {
#include "data/inc/D_0100AD20_445F0.inc.c"
};
Vtx D_0100AE90_44760[16] = {
#include "data/inc/D_0100AE90_44760.inc.c"
};

Gfx D_0100AF90_44860[] = {
    gsSPVertex(D_0100AB30_44400, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 1, 8, 0),
    gsSP1Quadrangle(9, 10, 11, 12, 0),
    gsSP2Triangles(13, 1, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 22, 0, 23, 1, 24, 0),
    gsSP2Triangles(25, 1, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(D_0100AD20_445F0, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 1, 12, 0),
    gsSP1Quadrangle(13, 14, 15, 16, 0),
    gsSP2Triangles(17, 1, 18, 0, 19, 20, 21, 0),
    gsSP1Triangle(19, 21, 22, 0),
    gsSPVertex(D_0100AE90_44760, 16, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSPEndDisplayList(),
};
