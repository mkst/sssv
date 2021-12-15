#include <ultra64.h>

Vtx D_01005F60_3F830[6] = {
#include "data/inc/D_01005F60_3F830.inc.c"
};

Gfx D_01005FC0_3F890[] = {
    gsSPVertex(D_01005F60_3F830, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 3, 5, 4, 0),
    gsSPEndDisplayList(),
};
