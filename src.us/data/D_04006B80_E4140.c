#include <ultra64.h>

Vtx D_04006A80_E4040[8] = {
#include "data/inc/D_04006A80_E4040.inc.c"
};
Vtx D_04006B00_E40C0[4] = {
#include "data/inc/D_04006B00_E40C0.inc.c"
};
Vtx D_04006B40_E4100[4] = {
#include "data/inc/D_04006B40_E4100.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04006B80_E4140[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04006A80_E4040, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSPVertex(D_04006B00_E40C0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPVertex(D_04006B40_E4100, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPEndDisplayList(),
};
