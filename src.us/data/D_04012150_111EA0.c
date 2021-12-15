#include <ultra64.h>

Vtx D_04011AB0_111800[32] = {
#include "data/inc/D_04011AB0_111800.inc.c"
};
Vtx D_04011CB0_111A00[32] = {
#include "data/inc/D_04011CB0_111A00.inc.c"
};
Vtx D_04011EB0_111C00[30] = {
#include "data/inc/D_04011EB0_111C00.inc.c"
};
Vtx D_04012090_111DE0[12] = {
#include "data/inc/D_04012090_111DE0.inc.c"
};

Gfx D_04012150_111EA0[] = {
    gsSPVertex(D_04011AB0_111800, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_04011CB0_111A00, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 2, 6, 0),
    gsSP1Quadrangle(7, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 20, 21, 22, 0),
    gsSP1Quadrangle(20, 23, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSP1Triangle(23, 30, 31, 0),
    gsSPVertex(D_04011EB0_111C00, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 4, 0),
    gsSP2Triangles(7, 4, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(10, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(14, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(18, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(22, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(26, 28, 29, 0),
    gsSPVertex(D_04012090_111DE0, 12, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSPEndDisplayList(),
};
