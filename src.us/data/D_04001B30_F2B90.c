#include <ultra64.h>

Vtx D_04001AF0_F2B50[4] = {
#include "data/inc/D_04001AF0_F2B50.inc.c"
};

Gfx D_04001B30_F2B90[] = {
    gsSPVertex(D_04001AF0_F2B50, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 3, 0, 0, 1, 0, 3, 0),
    gsSPEndDisplayList(),
};
