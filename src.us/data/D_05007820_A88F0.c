#include <ultra64.h>

Vtx D_05007020_A80F0[8] = {
#include "data/inc/D_05007020_A80F0.inc.c"
};
Vtx D_050070A0_A8170[32] = {
#include "data/inc/D_050070A0_A8170.inc.c"
};
Vtx D_050072A0_A8370[32] = {
#include "data/inc/D_050072A0_A8370.inc.c"
};
Vtx D_050074A0_A8570[32] = {
#include "data/inc/D_050074A0_A8570.inc.c"
};
Vtx D_050076A0_A8770[24] = {
#include "data/inc/D_050076A0_A8770.inc.c"
};

Gfx D_05007820_A88F0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05007020_A80F0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_050070A0_A8170, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_050072A0_A8370, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 21, 20, 0),
    gsSP1Quadrangle(25, 26, 22, 21, 0),
    gsSP1Quadrangle(26, 27, 23, 22, 0),
    gsSP1Quadrangle(27, 24, 20, 23, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_050074A0_A8570, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_050076A0_A8770, 24, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSPEndDisplayList(),
};
