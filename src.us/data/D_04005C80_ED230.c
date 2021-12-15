#include <ultra64.h>

Vtx D_04005BF0_ED1A0[9] = {
#include "data/inc/D_04005BF0_ED1A0.inc.c"
};

Gfx D_04005C80_ED230[] = {
    gsSPVertex(D_04005BF0_ED1A0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(1, 0, 6, 0, 4, 1, 7, 0),
    gsSP2Triangles(6, 7, 1, 0, 0, 4, 8, 0),
    gsSP2Triangles(7, 8, 4, 0, 8, 6, 0, 0),
    gsSP1Triangle(8, 6, 7, 0),
    gsSPEndDisplayList(),
};
