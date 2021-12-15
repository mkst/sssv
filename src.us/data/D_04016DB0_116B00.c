#include <ultra64.h>

Vtx D_04016960_1166B0[30] = {
#include "data/inc/D_04016960_1166B0.inc.c"
};
Vtx D_04016B40_116890[31] = {
#include "data/inc/D_04016B40_116890.inc.c"
};
Vtx D_04016D30_116A80[8] = {
#include "data/inc/D_04016D30_116A80.inc.c"
};

Gfx D_04016DB0_116B00[] = {
    gsSPVertex(D_04016960_1166B0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Quadrangle(8, 9, 7, 6, 0),
    gsSP1Quadrangle(10, 11, 9, 8, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 21, 26, 0),
    gsSP1Quadrangle(27, 28, 29, 24, 0),
    gsSPVertex(D_04016B40_116890, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 9, 8, 0),
    gsSP1Quadrangle(14, 15, 13, 12, 0),
    gsSP1Quadrangle(16, 17, 15, 14, 0),
    gsSP1Quadrangle(18, 19, 17, 16, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 21, 0),
    gsSP1Quadrangle(27, 28, 29, 30, 0),
    gsSPVertex(D_04016D30_116A80, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSPEndDisplayList(),
};
