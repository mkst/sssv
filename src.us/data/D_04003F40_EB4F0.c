#include <ultra64.h>

Vtx D_04003EE0_EB490[6] = {
#include "data/inc/D_04003EE0_EB490.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04003F40_EB4F0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04003EE0_EB490, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(0, 4, 1, 0, 4, 5, 1, 0),
    gsSPEndDisplayList(),
};
