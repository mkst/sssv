#include <ultra64.h>

Vtx D_04001060_E8610[3] = {
#include "data/inc/D_04001060_E8610.inc.c"
};
Vtx D_04001090_E8640[3] = {
#include "data/inc/D_04001090_E8640.inc.c"
};
Vtx D_040010C0_E8670[28] = {
#include "data/inc/D_040010C0_E8670.inc.c"
};
Vtx D_04001280_E8830[8] = {
#include "data/inc/D_04001280_E8830.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04001300_E88B0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x64, 0x32, 0x32, 0xFF),
    gsSPVertex(D_04001060_E8610, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_04001090_E8640, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFC, 0xDC, 0x5C, 0xFF),
    gsSPVertex(D_040010C0_E8670, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(3, 0, 4, 0, 5, 4, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 0, 7, 5, 0),
    gsSP2Triangles(2, 7, 0, 0, 7, 2, 8, 0),
    gsSP2Triangles(6, 9, 4, 0, 10, 4, 9, 0),
    gsSP2Triangles(4, 10, 3, 0, 6, 11, 9, 0),
    gsSP1Quadrangle(9, 11, 12, 10, 0),
    gsSP2Triangles(13, 10, 12, 0, 14, 11, 6, 0),
    gsSP2Triangles(14, 6, 5, 0, 5, 15, 14, 0),
    gsSP2Triangles(15, 5, 7, 0, 15, 13, 16, 0),
    gsSP1Quadrangle(16, 11, 14, 15, 0),
    gsSP2Triangles(12, 16, 13, 0, 12, 11, 16, 0),
    gsSP2Triangles(10, 13, 17, 0, 17, 3, 10, 0),
    gsSP2Triangles(3, 17, 18, 0, 19, 18, 17, 0),
    gsSP2Triangles(18, 20, 3, 0, 17, 21, 19, 0),
    gsSP2Triangles(13, 15, 21, 0, 21, 17, 13, 0),
    gsSP2Triangles(7, 21, 15, 0, 21, 7, 22, 0),
    gsSP2Triangles(22, 19, 21, 0, 8, 22, 7, 0),
    gsSP2Triangles(23, 3, 20, 0, 3, 23, 1, 0),
    gsSP2Triangles(20, 24, 23, 0, 19, 22, 25, 0),
    gsSP2Triangles(18, 19, 25, 0, 20, 18, 25, 0),
    gsSP2Triangles(24, 20, 25, 0, 25, 26, 24, 0),
    gsSP2Triangles(26, 25, 22, 0, 22, 8, 26, 0),
    gsSP2Triangles(27, 24, 26, 0, 27, 1, 23, 0),
    gsSP2Triangles(27, 2, 1, 0, 27, 26, 8, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04001280_E8830, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 1, 0, 0, 4, 5, 6, 0),
    gsSP2Triangles(6, 5, 7, 0, 7, 5, 4, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPEndDisplayList(),
};
