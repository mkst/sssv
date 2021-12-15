#include <ultra64.h>

Vtx D_04003350_EA900[9] = {
#include "data/inc/D_04003350_EA900.inc.c"
};
Vtx D_040033E0_EA990[9] = {
#include "data/inc/D_040033E0_EA990.inc.c"
};

Gfx D_04003470_EAA20[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPVertex(D_04003350_EA900, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(3, 2, 6, 0, 2, 5, 7, 0),
    gsSP2Triangles(7, 6, 2, 0, 5, 3, 8, 0),
    gsSP2Triangles(6, 8, 3, 0, 8, 7, 5, 0),
    gsSPVertex(D_040033E0_EA990, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(0, 2, 4, 0, 4, 3, 0, 0),
    gsSP2Triangles(3, 4, 5, 0, 2, 1, 6, 0),
    gsSP2Triangles(3, 6, 1, 0, 6, 4, 2, 0),
    gsSP2Triangles(6, 3, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(4, 6, 8, 0, 7, 8, 6, 0),
    gsSP1Triangle(8, 5, 4, 0),
    gsSPEndDisplayList(),
};
