#include <ultra64.h>

Vtx D_04006C40_106990[8] = {
#include "data/inc/D_04006C40_106990.inc.c"
};
Vtx D_04006CC0_106A10[26] = {
#include "data/inc/D_04006CC0_106A10.inc.c"
};
Vtx D_04006E60_106BB0[6] = {
#include "data/inc/D_04006E60_106BB0.inc.c"
};
Vtx D_04006EC0_106C10[5] = {
#include "data/inc/D_04006EC0_106C10.inc.c"
};
Vtx D_04006F10_106C60[17] = {
#include "data/inc/D_04006F10_106C60.inc.c"
};
Vtx D_04007020_106D70[6] = {
#include "data/inc/D_04007020_106D70.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

Gfx D_04007080_106DD0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04006C40_106990, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x24, 0x24, 0x24, 0xFF),
    gsSPVertex(D_04006CC0_106A10, 26, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(0, 1, 4, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 3, 0, 3, 6, 5, 0),
    gsSP2Triangles(0, 4, 7, 0, 4, 8, 7, 0),
    gsSP2Triangles(8, 4, 5, 0, 5, 9, 8, 0),
    gsSP1Quadrangle(9, 5, 6, 10, 0),
    gsSP2Triangles(6, 11, 10, 0, 6, 3, 11, 0),
    gsSP2Triangles(12, 11, 3, 0, 3, 2, 12, 0),
    gsSP2Triangles(11, 13, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(0, 7, 14, 0, 7, 15, 14, 0),
    gsSP2Triangles(15, 7, 8, 0, 8, 16, 15, 0),
    gsSP2Triangles(16, 9, 10, 0, 16, 8, 9, 0),
    gsSP2Triangles(0, 14, 17, 0, 14, 18, 17, 0),
    gsSP2Triangles(18, 14, 15, 0, 15, 19, 18, 0),
    gsSP2Triangles(19, 16, 10, 0, 19, 15, 16, 0),
    gsSP2Triangles(0, 17, 20, 0, 17, 21, 20, 0),
    gsSP2Triangles(21, 17, 18, 0, 18, 22, 21, 0),
    gsSP2Triangles(22, 19, 10, 0, 22, 18, 19, 0),
    gsSP1Quadrangle(0, 20, 23, 2, 0),
    gsSP2Triangles(23, 12, 2, 0, 20, 24, 23, 0),
    gsSP2Triangles(24, 13, 12, 0, 24, 20, 21, 0),
    gsSP2Triangles(12, 23, 24, 0, 21, 25, 24, 0),
    gsSP2Triangles(25, 22, 10, 0, 13, 25, 10, 0),
    gsSP2Triangles(25, 21, 22, 0, 13, 24, 25, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x9F, 0x9F, 0xFF),
    gsSPVertex(D_04006E60_106BB0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x10, 0x10, 0xFF),
    gsSPVertex(D_04006EC0_106C10, 5, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(0, 4, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(0, 1, 4, 0, 3, 2, 4, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04006F10_106C60, 17, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 11, 10, 9, 0),
    gsSP2Triangles(10, 8, 12, 0, 13, 15, 14, 0),
    gsSP1Triangle(15, 13, 16, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x9F, 0x9F, 0xFF),
    gsSPVertex(D_04007020_106D70, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSPEndDisplayList(),
};
