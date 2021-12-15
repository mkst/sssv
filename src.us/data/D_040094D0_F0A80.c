#include <ultra64.h>

Vtx D_04008470_EFA20[31] = {
#include "data/inc/D_04008470_EFA20.inc.c"
};
Vtx D_04008660_EFC10[30] = {
#include "data/inc/D_04008660_EFC10.inc.c"
};
Vtx D_04008840_EFDF0[30] = {
#include "data/inc/D_04008840_EFDF0.inc.c"
};
Vtx D_04008A20_EFFD0[31] = {
#include "data/inc/D_04008A20_EFFD0.inc.c"
};
Vtx D_04008C10_F01C0[32] = {
#include "data/inc/D_04008C10_F01C0.inc.c"
};
Vtx D_04008E10_F03C0[32] = {
#include "data/inc/D_04008E10_F03C0.inc.c"
};
Vtx D_04009010_F05C0[30] = {
#include "data/inc/D_04009010_F05C0.inc.c"
};
Vtx D_040091F0_F07A0[25] = {
#include "data/inc/D_040091F0_F07A0.inc.c"
};
Vtx D_04009380_F0930[21] = {
#include "data/inc/D_04009380_F0930.inc.c"
};

Gfx D_040094D0_F0A80[] = {
    gsSPVertex(D_04008470_EFA20, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 1, 0),
    gsSP2Triangles(1, 4, 5, 0, 4, 3, 5, 0),
    gsSP2Triangles(3, 2, 5, 0, 2, 1, 5, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(6, 9, 10, 7, 0),
    gsSP2Triangles(7, 10, 11, 0, 10, 9, 11, 0),
    gsSP2Triangles(9, 8, 11, 0, 8, 7, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(12, 15, 16, 13, 0),
    gsSP2Triangles(13, 16, 17, 0, 16, 15, 17, 0),
    gsSP2Triangles(15, 14, 17, 0, 14, 13, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 18, 20, 0),
    gsSP2Triangles(22, 23, 18, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 27, 29, 0),
    gsSPVertex(D_04008660_EFC10, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(2, 12, 0, 0, 13, 14, 3, 0),
    gsSP2Triangles(6, 13, 3, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 18, 20, 0),
    gsSP2Triangles(22, 21, 20, 0, 19, 22, 20, 0),
    gsSP2Triangles(23, 22, 19, 0, 22, 21, 23, 0),
    gsSP2Triangles(23, 18, 21, 0, 23, 19, 18, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 26, 24, 0),
    gsSP2Triangles(28, 27, 24, 0, 25, 28, 24, 0),
    gsSP2Triangles(29, 28, 25, 0, 28, 27, 29, 0),
    gsSP2Triangles(29, 26, 27, 0, 29, 25, 26, 0),
    gsSPVertex(D_04008840_EFDF0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 1, 4, 2, 0),
    gsSP2Triangles(1, 4, 5, 0, 5, 3, 4, 0),
    gsSP2Triangles(5, 0, 3, 0, 5, 1, 0, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 7, 10, 8, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 14, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 11, 13, 6, 0),
    gsSP2Triangles(8, 10, 21, 0, 22, 13, 23, 0),
    gsSP2Triangles(12, 23, 13, 0, 23, 24, 14, 0),
    gsSP2Triangles(17, 23, 14, 0, 25, 26, 15, 0),
    gsSP2Triangles(16, 15, 26, 0, 26, 7, 27, 0),
    gsSP2Triangles(9, 7, 26, 0, 14, 24, 18, 0),
    gsSP2Triangles(15, 14, 18, 0, 28, 16, 26, 0),
    gsSP2Triangles(17, 29, 23, 0, 15, 18, 25, 0),
    gsSP2Triangles(23, 12, 24, 0, 9, 26, 25, 0),
    gsSP2Triangles(25, 18, 20, 0, 19, 18, 24, 0),
    gsSPVertex(D_04008A20_EFFD0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 6, 15, 16, 0),
    gsSP2Triangles(10, 6, 16, 0, 11, 10, 16, 0),
    gsSP2Triangles(8, 17, 15, 0, 1, 3, 7, 0),
    gsSP2Triangles(9, 1, 7, 0, 8, 5, 17, 0),
    gsSP2Triangles(18, 2, 11, 0, 0, 4, 1, 0),
    gsSP2Triangles(3, 1, 4, 0, 6, 10, 7, 0),
    gsSP2Triangles(9, 7, 10, 0, 3, 5, 8, 0),
    gsSP2Triangles(7, 3, 8, 0, 18, 0, 2, 0),
    gsSP2Triangles(1, 11, 2, 0, 9, 11, 1, 0),
    gsSP2Triangles(4, 17, 5, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 18, 11, 16, 0),
    gsSP1Triangle(15, 6, 8, 0),
    gsSPVertex(D_04008C10_F01C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(0, 30, 31, 0),
    gsSPVertex(D_04008E10_F03C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 3, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 6, 8, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 11, 10, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 15, 14, 0, 18, 19, 20, 0),
    gsSP2Triangles(18, 20, 21, 0, 22, 18, 21, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 23, 25, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 27, 29, 0),
    gsSP1Triangle(5, 4, 31, 0),
    gsSPVertex(D_04009010_F05C0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 9, 11, 0, 13, 14, 10, 0),
    gsSP2Triangles(15, 13, 10, 0, 0, 16, 14, 0),
    gsSP2Triangles(17, 0, 14, 0, 2, 11, 16, 0),
    gsSP2Triangles(18, 11, 2, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 21, 20, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 23, 25, 0, 24, 27, 28, 0),
    gsSP1Triangle(29, 28, 27, 0),
    gsSPVertex(D_040091F0_F07A0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 1, 0),
    gsSP2Triangles(10, 12, 15, 0, 1, 9, 13, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 3, 0),
    gsSP2Triangles(16, 18, 21, 0, 19, 3, 22, 0),
    gsSP2Triangles(23, 17, 16, 0, 3, 20, 24, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04009380_F0930, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 3, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 1, 13, 4, 0),
    gsSP2Triangles(14, 13, 1, 0, 5, 15, 16, 0),
    gsSP2Triangles(0, 17, 1, 0, 14, 1, 10, 0),
    gsSP2Triangles(3, 2, 4, 0, 1, 4, 2, 0),
    gsSP2Triangles(4, 15, 5, 0, 13, 15, 4, 0),
    gsSP2Triangles(10, 12, 14, 0, 11, 9, 12, 0),
    gsSP2Triangles(5, 16, 18, 0, 0, 2, 19, 0),
    gsSP1Triangle(8, 7, 20, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
