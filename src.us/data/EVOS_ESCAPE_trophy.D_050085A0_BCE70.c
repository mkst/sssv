#include <ultra64.h>

Vtx D_05007A30_BC300[30] = {
#include "data/inc/D_05007A30_BC300.inc.c"
};
Vtx D_05007C10_BC4E0[32] = {
#include "data/inc/D_05007C10_BC4E0.inc.c"
};
Vtx D_05007E10_BC6E0[30] = {
#include "data/inc/D_05007E10_BC6E0.inc.c"
};
Vtx D_05007FF0_BC8C0[32] = {
#include "data/inc/D_05007FF0_BC8C0.inc.c"
};
Vtx D_050081F0_BCAC0[31] = {
#include "data/inc/D_050081F0_BCAC0.inc.c"
};
Vtx D_050083E0_BCCB0[28] = {
#include "data/inc/D_050083E0_BCCB0.inc.c"
};

const Gfx D_050085A0_BCE70[] = {
    gsSPVertex(D_05007A30_BC300, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 0, 2, 0, 6, 7, 8, 0),
    gsSP2Triangles(7, 9, 8, 0, 9, 10, 8, 0),
    gsSP2Triangles(10, 11, 8, 0, 11, 6, 8, 0),
    gsSP2Triangles(0, 5, 7, 0, 5, 4, 9, 0),
    gsSP2Triangles(4, 3, 10, 0, 3, 1, 11, 0),
    gsSP2Triangles(1, 0, 6, 0, 7, 6, 0, 0),
    gsSP2Triangles(9, 7, 5, 0, 10, 9, 4, 0),
    gsSP2Triangles(11, 10, 3, 0, 6, 11, 1, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(12, 15, 16, 13, 0),
    gsSP2Triangles(17, 14, 13, 0, 17, 15, 14, 0),
    gsSP2Triangles(17, 16, 15, 0, 17, 13, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
    gsSP2Triangles(27, 28, 26, 0, 28, 29, 26, 0),
    gsSP1Triangle(29, 24, 26, 0),
    gsSPVertex(D_05007C10_BC4E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 0, 2, 0, 6, 7, 1, 0),
    gsSP2Triangles(7, 8, 3, 0, 8, 9, 4, 0),
    gsSP2Triangles(9, 10, 5, 0, 10, 6, 0, 0),
    gsSP2Triangles(1, 0, 6, 0, 3, 1, 7, 0),
    gsSP2Triangles(4, 3, 8, 0, 5, 4, 9, 0),
    gsSP2Triangles(0, 5, 10, 0, 11, 12, 13, 0),
    gsSP1Quadrangle(11, 13, 14, 15, 0),
    gsSP2Triangles(11, 15, 12, 0, 16, 13, 12, 0),
    gsSP2Triangles(16, 14, 13, 0, 16, 15, 14, 0),
    gsSP2Triangles(16, 12, 15, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05007E10_BC6E0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(11, 24, 9, 0, 14, 25, 12, 0),
    gsSP2Triangles(23, 26, 21, 0, 27, 28, 29, 0),
    gsSPVertex(D_05007FF0_BC8C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 2, 15, 0, 0),
    gsSP2Triangles(11, 16, 9, 0, 17, 18, 19, 0),
    gsSP2Triangles(18, 20, 21, 0, 20, 17, 22, 0),
    gsSP2Triangles(19, 22, 17, 0, 21, 19, 18, 0),
    gsSP2Triangles(22, 21, 20, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_050081F0_BCAC0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(5, 12, 3, 0, 13, 14, 15, 0),
    gsSP2Triangles(14, 16, 17, 0, 16, 13, 18, 0),
    gsSP2Triangles(15, 18, 13, 0, 17, 15, 14, 0),
    gsSP2Triangles(18, 17, 16, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_050083E0_BCCB0, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 0, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 12, 25, 10, 0),
    gsSP2Triangles(15, 26, 13, 0, 24, 27, 22, 0),
    gsSPEndDisplayList(),
};
