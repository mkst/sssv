#include <ultra64.h>

Vtx D_04005FE0_ED590[7] = {
#include "data/inc/D_04005FE0_ED590.inc.c"
};

Gfx D_04006050_ED600[] = {
    gsSPVertex(D_04005FE0_ED590, 7, 0),
    gsSP2Triangles(0, 1, 0, 0, 0, 2, 1, 0),
    gsSP2Triangles(0, 2, 0, 0, 2, 3, 1, 0),
    gsSP2Triangles(2, 3, 3, 0, 1, 3, 3, 0),
    gsSP2Triangles(0, 4, 2, 0, 4, 3, 2, 0),
    gsSP2Triangles(4, 3, 3, 0, 0, 4, 0, 0),
    gsSP2Triangles(0, 5, 4, 0, 5, 3, 4, 0),
    gsSP2Triangles(5, 3, 3, 0, 0, 5, 0, 0),
    gsSP2Triangles(0, 1, 5, 0, 1, 3, 5, 0),
    gsSPEndDisplayList(),
};
