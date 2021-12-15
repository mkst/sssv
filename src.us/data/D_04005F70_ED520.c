#include <ultra64.h>

Vtx D_04005E80_ED430[7] = {
#include "data/inc/D_04005E80_ED430.inc.c"
};
Vtx D_04005EF0_ED4A0[8] = {
#include "data/inc/D_04005EF0_ED4A0.inc.c"
};

Gfx D_04005F70_ED520[] = {
    gsSPVertex(D_04005E80_ED430, 7, 0),
    gsSP1Quadrangle(0, 0, 1, 2, 0),
    gsSP2Triangles(0, 0, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 3, 0, 1, 3, 3, 0),
    gsSP2Triangles(0, 2, 4, 0, 4, 2, 3, 0),
    gsSP2Triangles(4, 3, 3, 0, 0, 0, 4, 0),
    gsSP2Triangles(0, 4, 5, 0, 5, 4, 3, 0),
    gsSP2Triangles(5, 3, 3, 0, 0, 0, 5, 0),
    gsSP2Triangles(0, 5, 1, 0, 1, 5, 3, 0),
    gsSPVertex(D_04005EF0_ED4A0, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSPEndDisplayList(),
};
