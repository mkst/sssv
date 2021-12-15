#include <ultra64.h>

Vtx D_04007400_CEE30[18] = {
#include "data/inc/D_04007400_CEE30.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

Gfx D_04007520_CEF50[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x5C, 0xFF),
    gsSPVertex(D_04007400_CEE30, 18, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 2, 0, 0, 4, 5, 2, 0),
    gsSP1Quadrangle(3, 1, 6, 7, 0),
    gsSP1Quadrangle(7, 6, 8, 9, 0),
    gsSP1Quadrangle(9, 8, 10, 11, 0),
    gsSP1Quadrangle(11, 10, 5, 4, 0),
    gsSP2Triangles(3, 12, 0, 0, 0, 13, 4, 0),
    gsSP2Triangles(4, 14, 11, 0, 11, 15, 9, 0),
    gsSP2Triangles(16, 3, 7, 0, 17, 7, 9, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPEndDisplayList(),
};
