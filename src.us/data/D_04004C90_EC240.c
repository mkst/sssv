#include <ultra64.h>

Vtx D_04004B70_EC120[18] = {
#include "data/inc/D_04004B70_EC120.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04004C90_EC240[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04004B70_EC120, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 8, 7, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 14, 13, 0, 15, 17, 16, 0),
    gsSPEndDisplayList(),
};
