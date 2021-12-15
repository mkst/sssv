#include <ultra64.h>

Vtx D_04001610_E8BC0[4] = {
#include "data/inc/D_04001610_E8BC0.inc.c"
};

Gfx D_04001650_E8C00[] = {
    gsSPVertex(D_04001610_E8BC0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 2, 3, 0, 3, 2, 0, 0),
    gsSPEndDisplayList(),
};
