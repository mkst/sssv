#include <ultra64.h>

Vtx D_04003CD0_E1290[8] = {
#include "data/inc/D_04003CD0_E1290.inc.c"
};

Gfx D_04003D50_E1310[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04003CD0_E1290, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 2, 1, 0),
    gsSP2Triangles(3, 2, 5, 0, 1, 6, 5, 0),
    gsSP2Triangles(6, 4, 7, 0, 7, 5, 6, 0),
    gsSP2Triangles(3, 7, 4, 0, 5, 7, 3, 0),
    gsSPEndDisplayList(),
};
