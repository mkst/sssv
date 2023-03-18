#include <ultra64.h>

Vtx D_04006E70_F7ED0[7] = {
#include "data/inc/D_04006E70_F7ED0.inc.c"
};

Gfx D_04006EE0_F7F40[] = {
    gsSPVertex(D_04006E70_F7ED0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(2, 4, 3, 0, 2, 1, 4, 0),
    gsSP2Triangles(4, 1, 3, 0, 0, 5, 1, 0),
    gsSP2Triangles(3, 1, 5, 0, 3, 6, 0, 0),
    gsSP1Triangle(3, 5, 6, 0),
    gsSPEndDisplayList(),
};
