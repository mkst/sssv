#include <ultra64.h>

Vtx D_0100FD20_495F0[4] = {
#include "data/inc/D_0100FD20_495F0.inc.c"
};

Gfx D_0100FD60_49630[] = {
    gsSPVertex(D_0100FD20_495F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP1Triangle(2, 1, 3, 0),
    gsSPEndDisplayList(),
};
