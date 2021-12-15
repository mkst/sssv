#include <ultra64.h>

Vtx D_05000000_C47B0[8] = {
#include "data/inc/D_05000000_C47B0.inc.c"
};
Vtx D_05000080_C4830[32] = {
#include "data/inc/D_05000080_C4830.inc.c"
};
Vtx D_05000280_C4A30[31] = {
#include "data/inc/D_05000280_C4A30.inc.c"
};
Vtx D_05000470_C4C20[32] = {
#include "data/inc/D_05000470_C4C20.inc.c"
};
Vtx D_05000670_C4E20[31] = {
#include "data/inc/D_05000670_C4E20.inc.c"
};
Vtx D_05000860_C5010[31] = {
#include "data/inc/D_05000860_C5010.inc.c"
};
Vtx D_05000A50_C5200[30] = {
#include "data/inc/D_05000A50_C5200.inc.c"
};
Vtx D_05000C30_C53E0[32] = {
#include "data/inc/D_05000C30_C53E0.inc.c"
};
Vtx D_05000E30_C55E0[31] = {
#include "data/inc/D_05000E30_C55E0.inc.c"
};
Vtx D_05001020_C57D0[32] = {
#include "data/inc/D_05001020_C57D0.inc.c"
};
Vtx D_05001220_C59D0[25] = {
#include "data/inc/D_05001220_C59D0.inc.c"
};
Vtx D_050013B0_C5B60[5] = {
#include "data/inc/D_050013B0_C5B60.inc.c"
};

Gfx D_05001400_C5BB0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_C47B0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05000080_C4830, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 0, 0, 0, 14, 15, 0),
    gsSP2Triangles(1, 15, 16, 0, 8, 17, 18, 0),
    gsSP2Triangles(6, 18, 19, 0, 13, 19, 14, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 20, 0),
    gsSP2Triangles(23, 24, 22, 0, 15, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 18, 30, 31, 0),
    gsSPVertex(D_05000280_C4A30, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(0, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 16, 15, 0, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP2Triangles(24, 20, 5, 0, 25, 26, 13, 0),
    gsSP2Triangles(27, 28, 23, 0, 29, 30, 18, 0),
    gsSPVertex(D_05000470_C4C20, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 1, 6, 0),
    gsSP2Triangles(2, 1, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 5, 13, 14, 0),
    gsSP2Triangles(6, 15, 5, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 22, 0, 22, 27, 28, 0),
    gsSP2Triangles(27, 11, 29, 0, 4, 30, 31, 0),
    gsSPVertex(D_05000670_C4E20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 6, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05000860_C5010, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 4, 1, 0),
    gsSP2Triangles(4, 7, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(7, 13, 14, 0, 6, 4, 15, 0),
    gsSP2Triangles(16, 17, 10, 0, 18, 6, 19, 0),
    gsSP2Triangles(19, 20, 18, 0, 21, 22, 9, 0),
    gsSP2Triangles(21, 7, 14, 0, 12, 20, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 1, 25, 0),
    gsSP2Triangles(19, 18, 27, 0, 28, 29, 30, 0),
    gsSP1Triangle(22, 14, 5, 0),
    gsSPVertex(D_05000A50_C5200, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 16, 18, 19, 0),
    gsSP2Triangles(19, 17, 16, 0, 18, 20, 21, 0),
    gsSP2Triangles(21, 19, 18, 0, 22, 23, 24, 0),
    gsSP2Triangles(23, 25, 22, 0, 26, 27, 5, 0),
    gsSP2Triangles(25, 28, 29, 0, 29, 22, 25, 0),
    gsSPVertex(D_05000C30_C53E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 5, 12, 0),
    gsSP2Triangles(14, 6, 3, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 11, 8, 0, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP2Triangles(23, 26, 27, 0, 28, 29, 30, 0),
    gsSP1Triangle(28, 30, 31, 0),
    gsSPVertex(D_05000E30_C55E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 2, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(2, 10, 15, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 11, 20, 0, 12, 21, 22, 0),
    gsSP2Triangles(23, 8, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 27, 0, 30, 28, 26, 0),
    gsSPVertex(D_05001020_C57D0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 6, 15, 7, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 22, 23, 0, 18, 24, 25, 0),
    gsSP1Quadrangle(26, 24, 1, 0, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 11, 31, 0),
    gsSPVertex(D_05001220_C59D0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 10, 15, 16, 0),
    gsSP2Triangles(10, 16, 11, 0, 6, 17, 18, 0),
    gsSP2Triangles(6, 8, 17, 0, 19, 11, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050013B0_C5B60, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
