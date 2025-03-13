#include <ultra64.h>

Vtx D_04001260_100FB0[12] = {
#include "data/inc/D_04001260_100FB0.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04001320_101070[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04001260_100FB0, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 2, 3, 0, 2, 4, 5, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 6, 9, 0),
    gsSP2Triangles(10, 8, 9, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};
