#include <ultra64.h>

Vtx D_040035C0_EAB70[8] = {
#include "data/inc/D_040035C0_EAB70.inc.c"
};

Gfx D_04003640_EABF0[] = {
    gsSPVertex(D_040035C0_EAB70, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(3, 4, 1, 0, 2, 1, 4, 0),
    gsSP2Triangles(5, 4, 3, 0, 4, 5, 2, 0),
    gsSP2Triangles(2, 5, 6, 0, 3, 6, 5, 0),
    gsSP2Triangles(6, 7, 2, 0, 7, 6, 3, 0),
    gsSP2Triangles(2, 7, 0, 0, 3, 0, 7, 0),
    gsSPEndDisplayList(),
};
