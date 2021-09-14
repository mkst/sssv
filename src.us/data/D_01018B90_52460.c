#include <ultra64.h>

Vtx D_010187D0_520A0[8] = {
#include "data/inc/D_010187D0_520A0.inc.c"
};
Vtx D_01018850_52120[30] = {
#include "data/inc/D_01018850_52120.inc.c"
};
Vtx D_01018A30_52300[22] = {
#include "data/inc/D_01018A30_52300.inc.c"
};

const Gfx D_01018B90_52460[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_010187D0_520A0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01018850_52120, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 0, 5, 0, 2, 5, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 9, 14, 15, 0),
    gsSP2Triangles(14, 16, 17, 0, 18, 11, 19, 0),
    gsSP2Triangles(16, 20, 21, 0, 20, 18, 22, 0),
    gsSP2Triangles(8, 23, 6, 0, 10, 8, 7, 0),
    gsSP2Triangles(13, 19, 11, 0, 15, 10, 9, 0),
    gsSP2Triangles(17, 15, 14, 0, 19, 22, 18, 0),
    gsSP2Triangles(21, 17, 16, 0, 22, 21, 20, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_01018A30_52300, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(2, 18, 0, 0, 5, 19, 3, 0),
    gsSP2Triangles(8, 20, 6, 0, 11, 21, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
