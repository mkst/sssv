#include <ultra64.h>

extern Gfx D_01003548_3CE18[];

Vtx D_04005730_105480[4] = {
#include "data/inc/D_04005730_105480.inc.c"
};
Vtx D_04005770_1054C0[12] = {
#include "data/inc/D_04005770_1054C0.inc.c"
};
Vtx D_04005830_105580[8] = {
#include "data/inc/D_04005830_105580.inc.c"
};
Vtx D_040058B0_105600[26] = {
#include "data/inc/D_040058B0_105600.inc.c"
};

Gfx D_04005A50_1057A0[] = {
    gsDPSetPrimColor(0, 0, 0x66, 0x82, 0xFF, 0xFF),
    gsSPVertex(D_04005730_105480, 4, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSP1Quadrangle(0, 2, 1, 1, 0),
    gsSP2Triangles(2, 1, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(3, 1, 1, 0, 2, 3, 1, 0),
    gsSPVertex(D_04005770_1054C0, 12, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 8, 7, 0, 9, 11, 10, 0),
    gsSP2Triangles(2, 0, 1, 0, 5, 3, 4, 0),
    gsSP2Triangles(8, 6, 7, 0, 11, 9, 10, 0),
    gsSPVertex(D_04005830_105580, 8, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(2, 0, 1, 0, 0, 2, 3, 0),
    gsSP2Triangles(6, 4, 5, 0, 4, 6, 7, 0),
    gsSPVertex(D_040058B0_105600, 26, 0),
    gsDPSetPrimColor(0, 0, 0x66, 0x82, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(2, 0, 4, 0, 4, 5, 2, 0),
    gsSP2Triangles(6, 4, 0, 0, 3, 6, 0, 0),
    gsSP2Triangles(5, 4, 7, 0, 8, 5, 7, 0),
    gsSP2Triangles(8, 9, 5, 0, 9, 2, 5, 0),
    gsSP2Triangles(2, 9, 10, 0, 10, 1, 2, 0),
    gsSP2Triangles(1, 10, 11, 0, 3, 1, 11, 0),
    gsSP2Triangles(8, 12, 9, 0, 12, 10, 9, 0),
    gsSP2Triangles(10, 12, 13, 0, 13, 11, 10, 0),
    gsSP2Triangles(11, 13, 14, 0, 3, 11, 14, 0),
    gsSP2Triangles(8, 15, 12, 0, 15, 13, 12, 0),
    gsSP2Triangles(13, 15, 16, 0, 16, 14, 13, 0),
    gsSP2Triangles(14, 16, 17, 0, 3, 14, 17, 0),
    gsSP2Triangles(8, 18, 15, 0, 18, 16, 15, 0),
    gsSP2Triangles(16, 18, 19, 0, 19, 17, 16, 0),
    gsSP2Triangles(17, 19, 20, 0, 3, 17, 20, 0),
    gsSP2Triangles(8, 21, 18, 0, 21, 19, 18, 0),
    gsSP2Triangles(19, 21, 22, 0, 22, 20, 19, 0),
    gsSP2Triangles(20, 22, 23, 0, 3, 20, 23, 0),
    gsSP2Triangles(3, 23, 6, 0, 23, 24, 6, 0),
    gsSP2Triangles(24, 7, 4, 0, 24, 23, 22, 0),
    gsSP2Triangles(4, 6, 24, 0, 22, 25, 24, 0),
    gsSP2Triangles(8, 25, 21, 0, 8, 7, 25, 0),
    gsSP2Triangles(25, 22, 21, 0, 7, 24, 25, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPEndDisplayList(),
};
