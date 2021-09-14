#include <ultra64.h>

Vtx D_05002560_C21A0[8] = {
#include "data/inc/D_05002560_C21A0.inc.c"
};
Vtx D_050025E0_C2220[30] = {
#include "data/inc/D_050025E0_C2220.inc.c"
};
Vtx D_050027C0_C2400[31] = {
#include "data/inc/D_050027C0_C2400.inc.c"
};
Vtx D_050029B0_C25F0[32] = {
#include "data/inc/D_050029B0_C25F0.inc.c"
};
Vtx D_05002BB0_C27F0[31] = {
#include "data/inc/D_05002BB0_C27F0.inc.c"
};
Vtx D_05002DA0_C29E0[31] = {
#include "data/inc/D_05002DA0_C29E0.inc.c"
};
Vtx D_05002F90_C2BD0[30] = {
#include "data/inc/D_05002F90_C2BD0.inc.c"
};
Vtx D_05003170_C2DB0[30] = {
#include "data/inc/D_05003170_C2DB0.inc.c"
};
Vtx D_05003350_C2F90[31] = {
#include "data/inc/D_05003350_C2F90.inc.c"
};
Vtx D_05003540_C3180[12] = {
#include "data/inc/D_05003540_C3180.inc.c"
};
Vtx D_05003600_C3240[12] = {
#include "data/inc/D_05003600_C3240.inc.c"
};

const Gfx D_050036C0_C3300[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05002560_C21A0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_050025E0_C2220, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 8, 11, 13, 0),
    gsSP1Quadrangle(3, 14, 15, 16, 0),
    gsSP1Quadrangle(17, 5, 9, 8, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 23, 0),
    gsSP2Triangles(27, 24, 21, 0, 28, 18, 29, 0),
    gsSP2Triangles(28, 21, 19, 0, 29, 20, 26, 0),
    gsSP2Triangles(20, 29, 18, 0, 21, 23, 20, 0),
    gsSP2Triangles(23, 26, 20, 0, 21, 24, 23, 0),
    gsSP2Triangles(24, 27, 22, 0, 23, 22, 25, 0),
    gsSP2Triangles(21, 28, 27, 0, 29, 22, 28, 0),
    gsSP2Triangles(22, 27, 28, 0, 29, 25, 22, 0),
    gsSP2Triangles(19, 18, 28, 0, 26, 25, 29, 0),
    gsSPVertex(D_050027C0_C2400, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 1, 0, 0, 0, 4, 3, 0),
    gsSP2Triangles(0, 2, 4, 0, 4, 2, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 10, 12, 0),
    gsSP2Triangles(9, 7, 6, 0, 12, 5, 7, 0),
    gsSP2Triangles(10, 6, 5, 0, 10, 13, 8, 0),
    gsSP2Triangles(9, 8, 11, 0, 12, 11, 13, 0),
    gsSP2Triangles(6, 10, 9, 0, 7, 9, 12, 0),
    gsSP2Triangles(5, 12, 10, 0, 14, 15, 16, 0),
    gsSP2Triangles(15, 17, 18, 0, 17, 14, 19, 0),
    gsSP2Triangles(19, 16, 20, 0, 16, 18, 21, 0),
    gsSP2Triangles(18, 19, 22, 0, 16, 19, 14, 0),
    gsSP2Triangles(18, 16, 15, 0, 19, 18, 17, 0),
    gsSP2Triangles(20, 22, 19, 0, 21, 20, 16, 0),
    gsSP2Triangles(22, 21, 18, 0, 23, 24, 25, 0),
    gsSP2Triangles(24, 26, 27, 0, 23, 25, 28, 0),
    gsSP1Triangle(29, 27, 30, 0),
    gsSPVertex(D_050029B0_C25F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 2, 1, 5, 0),
    gsSP2Triangles(3, 5, 1, 0, 8, 9, 10, 0),
    gsSP2Triangles(2, 10, 0, 0, 3, 1, 0, 0),
    gsSP2Triangles(8, 7, 9, 0, 10, 9, 11, 0),
    gsSP2Triangles(3, 0, 11, 0, 6, 11, 9, 0),
    gsSP2Triangles(9, 7, 6, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 16, 15, 14, 0),
    gsSP2Triangles(13, 12, 17, 0, 17, 16, 13, 0),
    gsSP2Triangles(18, 19, 17, 0, 19, 18, 14, 0),
    gsSP2Triangles(14, 15, 19, 0, 14, 18, 12, 0),
    gsSP2Triangles(17, 19, 15, 0, 14, 13, 16, 0),
    gsSP2Triangles(17, 12, 18, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 22, 24, 0, 25, 24, 22, 0),
    gsSP2Triangles(22, 21, 25, 0, 20, 2, 21, 0),
    gsSP2Triangles(2, 25, 21, 0, 20, 22, 23, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05002BB0_C27F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 6, 0, 0, 6, 7, 1, 0),
    gsSP2Triangles(7, 5, 3, 0, 8, 4, 3, 0),
    gsSP2Triangles(2, 8, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(0, 3, 5, 0, 1, 0, 6, 0),
    gsSP2Triangles(3, 1, 7, 0, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 14, 18, 0),
    gsSP2Triangles(10, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 26, 0),
    gsSP2Triangles(29, 30, 23, 0, 25, 23, 30, 0),
    gsSP1Triangle(27, 26, 30, 0),
    gsSPVertex(D_05002DA0_C29E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 0, 2, 4, 0),
    gsSP2Triangles(0, 3, 8, 0, 6, 5, 2, 0),
    gsSP2Triangles(2, 5, 4, 0, 7, 9, 8, 0),
    gsSP2Triangles(6, 2, 1, 0, 0, 10, 1, 0),
    gsSP2Triangles(1, 10, 11, 0, 6, 1, 11, 0),
    gsSP2Triangles(0, 8, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 14, 18, 0),
    gsSP2Triangles(14, 13, 19, 0, 22, 23, 24, 0),
    gsSP2Triangles(19, 25, 26, 0, 12, 14, 21, 0),
    gsSP2Triangles(27, 28, 29, 0, 25, 30, 15, 0),
    gsSPVertex(D_05002F90_C2BD0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 7, 6, 0),
    gsSP2Triangles(10, 3, 11, 0, 9, 12, 13, 0),
    gsSP2Triangles(14, 15, 2, 0, 16, 6, 17, 0),
    gsSP2Triangles(9, 13, 7, 0, 8, 18, 0, 0),
    gsSP2Triangles(1, 10, 14, 0, 5, 15, 11, 0),
    gsSP2Triangles(19, 20, 10, 0, 18, 19, 1, 0),
    gsSP2Triangles(13, 12, 19, 0, 4, 21, 22, 0),
    gsSP2Triangles(2, 15, 23, 0, 23, 15, 22, 0),
    gsSP2Triangles(22, 15, 5, 0, 9, 6, 16, 0),
    gsSP2Triangles(23, 22, 21, 0, 3, 10, 20, 0),
    gsSP2Triangles(20, 19, 12, 0, 24, 20, 25, 0),
    gsSP2Triangles(4, 3, 24, 0, 18, 8, 7, 0),
    gsSP2Triangles(21, 4, 17, 0, 2, 23, 0, 0),
    gsSP2Triangles(5, 11, 3, 0, 8, 17, 6, 0),
    gsSP2Triangles(11, 14, 10, 0, 17, 24, 16, 0),
    gsSP2Triangles(0, 21, 8, 0, 14, 2, 1, 0),
    gsSP2Triangles(10, 1, 19, 0, 1, 0, 18, 0),
    gsSP2Triangles(19, 18, 13, 0, 22, 5, 4, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSPVertex(D_05003170_C2DB0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 1, 0, 7, 0),
    gsSP2Triangles(8, 3, 2, 0, 9, 10, 7, 0),
    gsSP2Triangles(7, 8, 9, 0, 5, 4, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(7, 10, 1, 0, 2, 9, 8, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 16, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(23, 26, 27, 0, 20, 28, 29, 0),
    gsSP2Triangles(28, 20, 24, 0, 28, 23, 27, 0),
    gsSPVertex(D_05003350_C2F90, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 7, 0, 4, 0, 2, 0),
    gsSP2Triangles(8, 5, 2, 0, 0, 3, 7, 0),
    gsSP2Triangles(4, 3, 0, 0, 8, 9, 6, 0),
    gsSP2Triangles(1, 0, 7, 0, 1, 10, 2, 0),
    gsSP1Quadrangle(11, 10, 1, 7, 0),
    gsSP2Triangles(10, 8, 2, 0, 10, 11, 9, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
    gsSP2Triangles(16, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 23, 0, 27, 24, 26, 0),
    gsSP2Triangles(28, 22, 27, 0, 29, 25, 22, 0),
    gsSP2Triangles(30, 27, 25, 0, 24, 27, 22, 0),
    gsSP2Triangles(23, 22, 25, 0, 26, 25, 27, 0),
    gsSP2Triangles(27, 30, 28, 0, 22, 28, 29, 0),
    gsSP1Triangle(25, 29, 30, 0),
    gsSPVertex(D_05003540_C3180, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(3, 4, 9, 0, 10, 2, 11, 0),
    gsSP2Triangles(1, 3, 11, 0, 7, 0, 10, 0),
    gsSP2Triangles(2, 10, 0, 0, 0, 5, 3, 0),
    gsSP2Triangles(0, 7, 5, 0, 5, 4, 3, 0),
    gsSP1Triangle(6, 9, 4, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05003600_C3240, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 4, 1, 0, 0, 5, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 9, 10, 0),
    gsSP2Triangles(6, 10, 7, 0, 6, 11, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
