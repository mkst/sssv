#include <ultra64.h>

Vtx D_05000000_B0490[3] = {
#include "data/inc/D_05000000_B0490.inc.c"
};
Vtx D_05000030_B04C0[32] = {
#include "data/inc/D_05000030_B04C0.inc.c"
};
Vtx D_05000230_B06C0[32] = {
#include "data/inc/D_05000230_B06C0.inc.c"
};
Vtx D_05000430_B08C0[22] = {
#include "data/inc/D_05000430_B08C0.inc.c"
};

Gfx D_05000590_B0A20[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000000_B0490, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_05000030_B04C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 5, 3, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 3, 0, 9, 10, 11, 0),
    gsSP2Triangles(9, 11, 12, 0, 13, 14, 9, 0),
    gsSP1Quadrangle(15, 13, 12, 11, 0),
    gsSP2Triangles(1, 0, 5, 0, 16, 0, 2, 0),
    gsSP2Triangles(16, 2, 17, 0, 6, 5, 0, 0),
    gsSP2Triangles(6, 3, 5, 0, 16, 6, 0, 0),
    gsSP2Triangles(16, 7, 6, 0, 9, 12, 13, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 21, 22, 0),
    gsSP1Quadrangle(19, 23, 24, 20, 0),
    gsSP2Triangles(18, 22, 19, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 30, 28, 0),
    gsSP2Triangles(29, 28, 27, 0, 19, 22, 31, 0),
    gsSPVertex(D_05000230_B06C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(6, 0, 2, 7, 0),
    gsSP2Triangles(8, 0, 6, 0, 8, 9, 0, 0),
    gsSP2Triangles(5, 10, 3, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 15, 17, 18, 0),
    gsSP2Triangles(19, 14, 16, 0, 20, 16, 18, 0),
    gsSP2Triangles(16, 15, 18, 0, 17, 13, 18, 0),
    gsSP2Triangles(13, 12, 18, 0, 12, 20, 18, 0),
    gsSP2Triangles(20, 21, 19, 0, 12, 22, 21, 0),
    gsSP2Triangles(21, 20, 12, 0, 19, 16, 20, 0),
    gsSP2Triangles(11, 22, 12, 0, 23, 24, 25, 0),
    gsSP2Triangles(23, 25, 26, 0, 24, 27, 28, 0),
    gsSP2Triangles(24, 28, 25, 0, 27, 23, 26, 0),
    gsSP2Triangles(27, 26, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05000430_B08C0, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 5, 7, 6, 0),
    gsSP2Triangles(4, 7, 5, 0, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 11, 16, 18, 0),
    gsSP1Quadrangle(12, 11, 18, 13, 0),
    gsSP2Triangles(11, 17, 16, 0, 11, 14, 19, 0),
    gsSP1Quadrangle(10, 20, 21, 8, 0),
    gsSP1Triangle(11, 19, 17, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
