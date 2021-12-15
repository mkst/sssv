#include <ultra64.h>

Vtx D_04005510_F6570[11] = {
#include "data/inc/D_04005510_F6570.inc.c"
};
Vtx D_040055C0_F6620[11] = {
#include "data/inc/D_040055C0_F6620.inc.c"
};
Vtx D_04005670_F66D0[32] = {
#include "data/inc/D_04005670_F66D0.inc.c"
};
Vtx D_04005870_F68D0[30] = {
#include "data/inc/D_04005870_F68D0.inc.c"
};
Vtx D_04005A50_F6AB0[6] = {
#include "data/inc/D_04005A50_F6AB0.inc.c"
};
Vtx D_04005AB0_F6B10[6] = {
#include "data/inc/D_04005AB0_F6B10.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04005B10_F6B70[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04005510_F6570, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 0, 2, 0, 1, 0, 6, 0),
    gsSP2Triangles(6, 7, 1, 0, 3, 1, 7, 0),
    gsSP2Triangles(7, 8, 3, 0, 4, 3, 8, 0),
    gsSP2Triangles(8, 9, 4, 0, 5, 4, 9, 0),
    gsSP2Triangles(9, 10, 5, 0, 10, 6, 0, 0),
    gsSP1Triangle(0, 5, 10, 0),
    gsSPVertex(D_040055C0_F6620, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 3, 2, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 2, 1, 0),
    gsSP2Triangles(1, 7, 6, 0, 5, 6, 8, 0),
    gsSP2Triangles(8, 6, 7, 0, 7, 9, 8, 0),
    gsSP2Triangles(9, 4, 10, 0, 5, 8, 10, 0),
    gsSP2Triangles(5, 10, 3, 0, 10, 8, 9, 0),
    gsSP1Triangle(3, 10, 4, 0),
    gsDPSetPrimColor(0, 0, 0x94, 0x94, 0x94, 0xFF),
    gsSPVertex(D_04005670_F66D0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 2, 1, 0),
    gsSP2Triangles(1, 6, 5, 0, 7, 5, 6, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 4, 9, 0),
    gsSP2Triangles(9, 7, 8, 0, 3, 9, 4, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
    gsSP2Triangles(14, 10, 13, 0, 15, 12, 11, 0),
    gsSP2Triangles(11, 16, 15, 0, 17, 15, 16, 0),
    gsSP2Triangles(16, 18, 17, 0, 18, 14, 19, 0),
    gsSP2Triangles(19, 17, 18, 0, 13, 19, 14, 0),
    gsSP2Triangles(20, 21, 22, 0, 21, 20, 23, 0),
    gsSP2Triangles(20, 24, 23, 0, 24, 20, 25, 0),
    gsSP2Triangles(22, 25, 20, 0, 24, 26, 23, 0),
    gsSP2Triangles(26, 24, 27, 0, 25, 27, 24, 0),
    gsSP2Triangles(26, 28, 23, 0, 28, 26, 29, 0),
    gsSP2Triangles(27, 29, 26, 0, 28, 30, 23, 0),
    gsSP2Triangles(30, 28, 31, 0, 29, 31, 28, 0),
    gsSPVertex(D_04005870_F68D0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(1, 4, 2, 0, 4, 1, 5, 0),
    gsSP2Triangles(3, 5, 1, 0, 6, 0, 2, 0),
    gsSP2Triangles(0, 6, 7, 0, 7, 3, 0, 0),
    gsSP2Triangles(3, 7, 8, 0, 5, 3, 9, 0),
    gsSP2Triangles(8, 9, 3, 0, 9, 8, 10, 0),
    gsSP2Triangles(5, 11, 4, 0, 11, 5, 12, 0),
    gsSP2Triangles(9, 12, 5, 0, 12, 9, 13, 0),
    gsSP2Triangles(10, 13, 9, 0, 10, 14, 13, 0),
    gsSP1Quadrangle(15, 14, 10, 8, 0),
    gsSP2Triangles(16, 14, 15, 0, 17, 14, 16, 0),
    gsSP2Triangles(18, 14, 17, 0, 8, 19, 15, 0),
    gsSP2Triangles(16, 15, 19, 0, 19, 8, 7, 0),
    gsSP2Triangles(19, 20, 16, 0, 17, 16, 20, 0),
    gsSP2Triangles(20, 21, 17, 0, 18, 17, 21, 0),
    gsSP2Triangles(21, 22, 18, 0, 7, 23, 19, 0),
    gsSP2Triangles(23, 7, 6, 0, 20, 19, 23, 0),
    gsSP2Triangles(23, 24, 20, 0, 21, 20, 24, 0),
    gsSP2Triangles(24, 25, 21, 0, 22, 21, 25, 0),
    gsSP2Triangles(25, 26, 22, 0, 13, 14, 27, 0),
    gsSP2Triangles(13, 27, 12, 0, 28, 12, 27, 0),
    gsSP2Triangles(26, 11, 28, 0, 12, 28, 11, 0),
    gsSP2Triangles(28, 22, 26, 0, 27, 14, 29, 0),
    gsSP2Triangles(29, 14, 18, 0, 22, 28, 29, 0),
    gsSP2Triangles(27, 29, 28, 0, 29, 18, 22, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04005A50_F6AB0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSPVertex(D_04005AB0_F6B10, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSPEndDisplayList(),
};
