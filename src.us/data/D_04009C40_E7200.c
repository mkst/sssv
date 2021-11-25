#include <ultra64.h>

Vtx D_04009110_E66D0[30] = {
#include "data/inc/D_04009110_E66D0.inc.c"
};
Vtx D_040092F0_E68B0[32] = {
#include "data/inc/D_040092F0_E68B0.inc.c"
};
Vtx D_040094F0_E6AB0[31] = {
#include "data/inc/D_040094F0_E6AB0.inc.c"
};
Vtx D_040096E0_E6CA0[31] = {
#include "data/inc/D_040096E0_E6CA0.inc.c"
};
Vtx D_040098D0_E6E90[32] = {
#include "data/inc/D_040098D0_E6E90.inc.c"
};
Vtx D_04009AD0_E7090[23] = {
#include "data/inc/D_04009AD0_E7090.inc.c"
};

const Gfx D_04009C40_E7200[] = {
    gsSPVertex(D_04009110_E66D0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(5, 4, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 11, 13, 0, 14, 13, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(11, 21, 22, 0, 13, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(29, 12, 14, 0),
    gsSPVertex(D_040092F0_E68B0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 1, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 15, 17, 0, 18, 8, 15, 0),
    gsSP2Triangles(19, 20, 8, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 16, 25, 0, 26, 18, 16, 0),
    gsSP2Triangles(27, 28, 18, 0, 29, 30, 31, 0),
    gsSPVertex(D_040094F0_E6AB0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(5, 6, 7, 0, 4, 7, 1, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 4, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 0, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(22, 24, 25, 0, 24, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_040096E0_E6CA0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 9, 13, 0),
    gsSP2Triangles(14, 12, 15, 0, 16, 14, 17, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP2Triangles(2, 22, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(6, 4, 3, 0, 8, 6, 5, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP2Triangles(0, 18, 26, 0, 18, 21, 27, 0),
    gsSP1Quadrangle(0, 22, 19, 18, 0),
    gsSP2Triangles(23, 25, 21, 0, 29, 30, 25, 0),
    gsSP2Triangles(21, 25, 30, 0, 15, 13, 11, 0),
    gsSPVertex(D_040098D0_E6E90, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 10, 0),
    gsSP2Triangles(11, 9, 12, 0, 13, 14, 2, 0),
    gsSP2Triangles(4, 7, 15, 0, 5, 16, 3, 0),
    gsSP2Triangles(15, 5, 4, 0, 17, 15, 7, 0),
    gsSP2Triangles(18, 17, 6, 0, 7, 6, 17, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 23, 0, 24, 27, 28, 0),
    gsSP2Triangles(23, 29, 27, 0, 12, 29, 30, 0),
    gsSP1Triangle(12, 30, 31, 0),
    gsSPVertex(D_04009AD0_E7090, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 1, 0, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 0, 14, 3, 0),
    gsSP2Triangles(7, 15, 5, 0, 16, 11, 17, 0),
    gsSP2Triangles(11, 16, 18, 0, 12, 18, 19, 0),
    gsSP2Triangles(14, 19, 20, 0, 18, 12, 11, 0),
    gsSP1Triangle(21, 22, 7, 0),
    gsSPEndDisplayList(),
};
