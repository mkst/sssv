#include <ultra64.h>

Vtx D_04003E50_EB400[6] = {
#include "data/inc/D_04003E50_EB400.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04003EB0_EB460[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04003E50_EB400, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(0, 4, 1, 0, 4, 5, 1, 0),
    gsSPEndDisplayList(),
};
