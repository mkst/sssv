#include <ultra64.h>

Vtx D_04007230_CEC60[12] = {
#include "data/inc/D_04007230_CEC60.inc.c"
};

const Gfx D_040072F0_CED20[] = {
    gsSPVertex(D_04007230_CEC60, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(1, 0, 4, 0, 4, 3, 1, 0),
    gsSP2Triangles(5, 3, 4, 0, 3, 5, 2, 0),
    gsSP2Triangles(6, 2, 5, 0, 2, 7, 0, 0),
    gsSP2Triangles(2, 6, 7, 0, 7, 6, 8, 0),
    gsSP2Triangles(5, 8, 6, 0, 7, 9, 0, 0),
    gsSP2Triangles(9, 7, 10, 0, 4, 10, 5, 0),
    gsSP2Triangles(10, 8, 5, 0, 8, 10, 7, 0),
    gsSP2Triangles(0, 9, 11, 0, 4, 11, 10, 0),
    gsSP2Triangles(10, 11, 9, 0, 11, 4, 0, 0),
    gsSPEndDisplayList(),
};
