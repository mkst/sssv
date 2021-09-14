#include <ultra64.h>

Vtx D_0101D730_57000[31] = {
#include "data/inc/D_0101D730_57000.inc.c"
};
Vtx D_0101D920_571F0[31] = {
#include "data/inc/D_0101D920_571F0.inc.c"
};
Vtx D_0101DB10_573E0[18] = {
#include "data/inc/D_0101DB10_573E0.inc.c"
};

const Gfx D_0101DC30_57500[] = {
    gsSPVertex(D_0101D730_57000, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 2, 6, 0),
    gsSP2Triangles(3, 0, 7, 0, 6, 2, 1, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 14, 12, 0, 15, 10, 14, 0),
    gsSP2Triangles(11, 8, 15, 0, 14, 10, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 17, 0),
    gsSP2Triangles(21, 22, 20, 0, 23, 18, 22, 0),
    gsSP2Triangles(19, 16, 23, 0, 22, 18, 17, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 27, 28, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(D_0101D920_571F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 1, 0, 7, 0),
    gsSP2Triangles(8, 9, 2, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 14, 16, 0),
    gsSP2Triangles(17, 16, 11, 0, 11, 16, 14, 0),
    gsSP2Triangles(13, 15, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 20, 22, 0, 23, 22, 24, 0),
    gsSP2Triangles(25, 24, 19, 0, 19, 24, 22, 0),
    gsSP2Triangles(21, 23, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 28, 30, 0),
    gsSPVertex(D_0101DB10_573E0, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(4, 2, 1, 0, 5, 0, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 10, 0),
    gsSP2Triangles(11, 9, 12, 0, 13, 11, 14, 0),
    gsSP2Triangles(15, 13, 16, 0, 7, 15, 17, 0),
    gsSP2Triangles(12, 8, 16, 0, 12, 10, 8, 0),
    gsSP2Triangles(8, 17, 16, 0, 13, 7, 9, 0),
    gsSP2Triangles(7, 6, 9, 0, 13, 15, 7, 0),
    gsSPEndDisplayList(),
};
