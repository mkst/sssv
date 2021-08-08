#include <ultra64.h>


Vtx D_01012550_4BE20[27] = {
#include "data/inc/D_01012550_4BE20.inc.c"
};

const Gfx D_01012700_4BFD0[] = {
    gsSPVertex(D_01012550_4BE20, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 4, 5, 0),
    gsSP2Triangles(0, 2, 6, 0, 2, 7, 8, 0),
    gsSP2Triangles(2, 8, 6, 0, 6, 8, 9, 0),
    gsSP2Triangles(0, 6, 10, 0, 6, 9, 11, 0),
    gsSP2Triangles(6, 11, 10, 0, 10, 11, 12, 0),
    gsSP2Triangles(0, 10, 1, 0, 10, 13, 14, 0),
    gsSP2Triangles(10, 14, 1, 0, 1, 14, 3, 0),
    gsSP2Triangles(15, 16, 17, 0, 16, 18, 4, 0),
    gsSP2Triangles(16, 4, 17, 0, 17, 4, 3, 0),
    gsSP2Triangles(19, 20, 21, 0, 20, 9, 8, 0),
    gsSP2Triangles(20, 8, 21, 0, 21, 8, 22, 0),
    gsSP2Triangles(19, 23, 20, 0, 23, 24, 11, 0),
    gsSP2Triangles(23, 11, 20, 0, 20, 11, 9, 0),
    gsSP2Triangles(15, 17, 25, 0, 17, 3, 14, 0),
    gsSP2Triangles(17, 14, 25, 0, 25, 14, 26, 0),
    gsSPEndDisplayList(),
};
