#include <ultra64.h>

Vtx D_04002860_E9E10[4] = {
#include "data/inc/D_04002860_E9E10.inc.c"
};
Vtx D_040028A0_E9E50[4] = {
#include "data/inc/D_040028A0_E9E50.inc.c"
};
Vtx D_040028E0_E9E90[14] = {
#include "data/inc/D_040028E0_E9E90.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_040029C0_E9F70[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_040028E0_E9E90, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(1, 3, 4, 0, 5, 3, 2, 0),
    gsSP2Triangles(2, 5, 5, 0, 3, 5, 5, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 5, 5, 0),
    gsSP2Triangles(5, 7, 3, 0, 7, 4, 3, 0),
    gsSP2Triangles(7, 5, 5, 0, 4, 7, 8, 0),
    gsSP2Triangles(5, 9, 7, 0, 9, 8, 7, 0),
    gsSP2Triangles(9, 5, 5, 0, 8, 9, 10, 0),
    gsSP2Triangles(5, 11, 9, 0, 5, 6, 11, 0),
    gsSP2Triangles(11, 10, 9, 0, 11, 5, 5, 0),
    gsSP2Triangles(10, 11, 12, 0, 6, 12, 11, 0),
    gsSP2Triangles(12, 6, 13, 0, 2, 13, 6, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04002860_E9E10, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPVertex(D_040028A0_E9E50, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPEndDisplayList(),
};
