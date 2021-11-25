#include <ultra64.h>

Vtx D_0400C420_10C170[8] = {
#include "data/inc/D_0400C420_10C170.inc.c"
};
Vtx D_0400C4A0_10C1F0[4] = {
#include "data/inc/D_0400C4A0_10C1F0.inc.c"
};
Vtx D_0400C4E0_10C230[31] = {
#include "data/inc/D_0400C4E0_10C230.inc.c"
};
Vtx D_0400C6D0_10C420[30] = {
#include "data/inc/D_0400C6D0_10C420.inc.c"
};
Vtx D_0400C8B0_10C600[3] = {
#include "data/inc/D_0400C8B0_10C600.inc.c"
};

const Gfx D_0400C8E0_10C630[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400C420_10C170, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400C4A0_10C1F0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400C4E0_10C230, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(12, 15, 16, 17, 0),
    gsSP1Quadrangle(18, 19, 0, 20, 0),
    gsSP1Quadrangle(18, 20, 21, 7, 0),
    gsSP1Quadrangle(22, 23, 12, 24, 0),
    gsSP1Quadrangle(23, 25, 26, 27, 0),
    gsSP1Quadrangle(25, 28, 29, 30, 0),
    gsSPVertex(D_0400C6D0_10C420, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 2, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 20, 21, 22, 0),
    gsSP1Quadrangle(23, 24, 25, 26, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_0400C8B0_10C600, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
