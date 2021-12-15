#include <ultra64.h>

Vtx D_010203F0_59CC0[30] = {
#include "data/inc/D_010203F0_59CC0.inc.c"
};
Vtx D_010205D0_59EA0[25] = {
#include "data/inc/D_010205D0_59EA0.inc.c"
};
Vtx D_01020760_5A030[8] = {
#include "data/inc/D_01020760_5A030.inc.c"
};

Gfx D_010207E0_5A0B0[] = {
    gsSPVertex(D_010203F0_59CC0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(1, 7, 12, 2, 0),
    gsSP1Quadrangle(13, 14, 12, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 19, 22, 0),
    gsSP1Quadrangle(23, 24, 25, 26, 0),
    gsSP1Quadrangle(17, 27, 28, 29, 0),
    gsSP1Quadrangle(19, 18, 26, 25, 0),
    gsSP1Quadrangle(17, 16, 24, 23, 0),
    gsSPVertex(D_010205D0_59EA0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 7, 8, 2, 0),
    gsSP2Triangles(9, 10, 2, 0, 11, 12, 2, 0),
    gsSP2Triangles(13, 14, 2, 0, 15, 16, 2, 0),
    gsSP2Triangles(17, 18, 2, 0, 19, 20, 2, 0),
    gsSP2Triangles(21, 22, 2, 0, 23, 24, 2, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01020760_5A030, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 0, 4, 5, 0),
    gsSP1Quadrangle(5, 4, 6, 7, 0),
    gsSP1Quadrangle(3, 2, 7, 6, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
