#include <ultra64.h>

Vtx D_04006960_F79C0[7] = {
#include "data/inc/D_04006960_F79C0.inc.c"
};

Gfx D_040069D0_F7A30[] = {
    gsSPVertex(D_04006960_F79C0, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(4, 1, 2, 0, 0, 5, 3, 0),
    gsSP2Triangles(5, 4, 3, 0, 5, 1, 4, 0),
    gsSP2Triangles(6, 4, 2, 0, 3, 6, 2, 0),
    gsSP1Triangle(3, 4, 6, 0),
    gsSPEndDisplayList(),
};
