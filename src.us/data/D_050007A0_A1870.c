#include <ultra64.h>

Vtx D_05000000_A10D0[8] = {
#include "data/inc/D_05000000_A10D0.inc.c"
};
Vtx D_05000080_A1150[31] = {
#include "data/inc/D_05000080_A1150.inc.c"
};
Vtx D_05000270_A1340[31] = {
#include "data/inc/D_05000270_A1340.inc.c"
};
Vtx D_05000460_A1530[32] = {
#include "data/inc/D_05000460_A1530.inc.c"
};
Vtx D_05000660_A1730[20] = {
#include "data/inc/D_05000660_A1730.inc.c"
};

const Gfx D_050007A0_A1870[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_A10D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05000080_A1150, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Quadrangle(8, 9, 7, 6, 0),
    gsSP1Quadrangle(10, 11, 9, 8, 0),
    gsSP1Quadrangle(12, 13, 11, 10, 0),
    gsSP1Quadrangle(1, 14, 15, 2, 0),
    gsSP1Quadrangle(5, 16, 14, 1, 0),
    gsSP1Quadrangle(7, 17, 16, 5, 0),
    gsSP1Quadrangle(9, 18, 17, 7, 0),
    gsSP1Quadrangle(11, 19, 18, 9, 0),
    gsSP1Quadrangle(13, 20, 19, 11, 0),
    gsSP1Quadrangle(14, 21, 22, 15, 0),
    gsSP1Quadrangle(16, 23, 21, 14, 0),
    gsSP1Quadrangle(17, 24, 23, 16, 0),
    gsSP1Quadrangle(18, 25, 24, 17, 0),
    gsSP1Quadrangle(19, 26, 25, 18, 0),
    gsSP1Quadrangle(20, 27, 26, 19, 0),
    gsSP1Quadrangle(28, 0, 3, 29, 0),
    gsSP1Quadrangle(30, 4, 0, 28, 0),
    gsSPVertex(D_05000270_A1340, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Quadrangle(8, 9, 7, 6, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(14, 15, 11, 10, 0),
    gsSP1Quadrangle(16, 17, 15, 14, 0),
    gsSP1Quadrangle(18, 19, 17, 16, 0),
    gsSP1Quadrangle(20, 21, 19, 18, 0),
    gsSP1Quadrangle(22, 23, 21, 20, 0),
    gsSP1Quadrangle(11, 24, 25, 12, 0),
    gsSP1Quadrangle(15, 26, 24, 11, 0),
    gsSP1Quadrangle(17, 27, 26, 15, 0),
    gsSP1Quadrangle(19, 28, 27, 17, 0),
    gsSP1Quadrangle(21, 29, 28, 19, 0),
    gsSP1Quadrangle(23, 30, 29, 21, 0),
    gsSPVertex(D_05000460_A1530, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Quadrangle(8, 9, 7, 6, 0),
    gsSP1Quadrangle(10, 11, 9, 8, 0),
    gsSP1Quadrangle(12, 13, 11, 10, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP1Quadrangle(18, 19, 15, 14, 0),
    gsSP1Quadrangle(20, 21, 19, 18, 0),
    gsSP1Quadrangle(22, 23, 21, 20, 0),
    gsSP1Quadrangle(24, 25, 23, 22, 0),
    gsSP1Quadrangle(26, 27, 25, 24, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_05000660_A1730, 20, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Quadrangle(8, 9, 7, 6, 0),
    gsSP1Quadrangle(10, 11, 9, 8, 0),
    gsSP1Quadrangle(12, 3, 13, 14, 0),
    gsSP1Quadrangle(15, 0, 3, 12, 0),
    gsSP1Quadrangle(16, 4, 0, 15, 0),
    gsSP1Quadrangle(17, 6, 4, 16, 0),
    gsSP1Quadrangle(18, 8, 6, 17, 0),
    gsSP1Quadrangle(19, 10, 8, 18, 0),
    gsSPEndDisplayList(),
};
