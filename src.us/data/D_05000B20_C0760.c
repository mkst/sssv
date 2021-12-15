#include <ultra64.h>

Vtx D_05000000_BFC40[32] = {
#include "data/inc/D_05000000_BFC40.inc.c"
};
Vtx D_05000200_BFE40[30] = {
#include "data/inc/D_05000200_BFE40.inc.c"
};
Vtx D_050003E0_C0020[31] = {
#include "data/inc/D_050003E0_C0020.inc.c"
};
Vtx D_050005D0_C0210[30] = {
#include "data/inc/D_050005D0_C0210.inc.c"
};
Vtx D_050007B0_C03F0[30] = {
#include "data/inc/D_050007B0_C03F0.inc.c"
};
Vtx D_05000990_C05D0[25] = {
#include "data/inc/D_05000990_C05D0.inc.c"
};


Gfx D_05000B20_C0760[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000000_BFC40, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_05000200_BFE40, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 13, 12, 0),
    gsSP2Triangles(15, 12, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 19, 3, 0, 20, 21, 22, 0),
    gsSP1Quadrangle(23, 24, 25, 26, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_050003E0_C0020, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 12, 11, 17, 0),
    gsSP2Triangles(18, 17, 19, 0, 5, 20, 21, 0),
    gsSP2Triangles(4, 22, 20, 0, 21, 23, 5, 0),
    gsSP2Triangles(6, 5, 23, 0, 4, 20, 5, 0),
    gsSP2Triangles(18, 24, 25, 0, 17, 25, 12, 0),
    gsSP2Triangles(17, 11, 19, 0, 13, 26, 11, 0),
    gsSP2Triangles(27, 28, 29, 0, 28, 30, 29, 0),
    gsSPVertex(D_050005D0_C0210, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
    gsSP2Triangles(10, 7, 6, 0, 11, 12, 13, 0),
    gsSP2Triangles(9, 13, 12, 0, 10, 6, 12, 0),
    gsSP2Triangles(12, 6, 9, 0, 13, 14, 11, 0),
    gsSP2Triangles(10, 12, 11, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 21, 22, 0),
    gsSP2Triangles(23, 17, 24, 0, 25, 20, 19, 0),
    gsSP2Triangles(26, 27, 28, 0, 27, 19, 29, 0),
    gsSP1Triangle(15, 17, 23, 0),
    gsSPVertex(D_050007B0_C03F0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 4, 3, 9, 0),
    gsSP2Triangles(9, 0, 4, 0, 10, 0, 9, 0),
    gsSP2Triangles(11, 2, 1, 0, 10, 12, 1, 0),
    gsSP2Triangles(13, 14, 8, 0, 15, 16, 17, 0),
    gsSP2Triangles(10, 1, 0, 0, 4, 2, 6, 0),
    gsSP2Triangles(7, 18, 13, 0, 2, 4, 0, 0),
    gsSP2Triangles(11, 19, 18, 0, 2, 11, 7, 0),
    gsSP2Triangles(1, 12, 11, 0, 17, 5, 15, 0),
    gsSP2Triangles(8, 14, 20, 0, 20, 14, 15, 0),
    gsSP2Triangles(15, 14, 16, 0, 10, 9, 21, 0),
    gsSP2Triangles(20, 15, 5, 0, 6, 5, 4, 0),
    gsSP2Triangles(19, 11, 12, 0, 13, 8, 7, 0),
    gsSP2Triangles(22, 23, 24, 0, 24, 25, 22, 0),
    gsSP2Triangles(26, 27, 23, 0, 22, 28, 29, 0),
    gsSP2Triangles(29, 23, 22, 0, 27, 24, 23, 0),
    gsSP2Triangles(28, 22, 25, 0, 23, 29, 26, 0),
    gsSPVertex(D_05000990_C05D0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(1, 3, 2, 0, 4, 0, 2, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 7, 0),
    gsSP2Triangles(6, 8, 7, 0, 9, 5, 7, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(12, 16, 10, 0, 13, 15, 12, 0),
    gsSP2Triangles(13, 12, 11, 0, 11, 17, 13, 0),
    gsSP2Triangles(14, 13, 17, 0, 16, 12, 15, 0),
    gsSP2Triangles(18, 19, 20, 0, 19, 21, 22, 0),
    gsSP2Triangles(18, 21, 19, 0, 23, 24, 20, 0),
    gsSP1Triangle(18, 20, 24, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
