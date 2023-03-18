#include <ultra64.h>

Vtx D_04001720_F2780[4] = {
#include "data/inc/D_04001720_F2780.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04001760_F27C0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04001720_F2780, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};
