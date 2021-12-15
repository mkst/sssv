#include <ultra64.h>

Vtx D_04006680_EDC30[8] = {
#include "data/inc/D_04006680_EDC30.inc.c"
};
Vtx D_04006700_EDCB0[31] = {
#include "data/inc/D_04006700_EDCB0.inc.c"
};
Vtx D_040068F0_EDEA0[32] = {
#include "data/inc/D_040068F0_EDEA0.inc.c"
};
Vtx D_04006AF0_EE0A0[20] = {
#include "data/inc/D_04006AF0_EE0A0.inc.c"
};
Vtx D_04006C30_EE1E0[13] = {
#include "data/inc/D_04006C30_EE1E0.inc.c"
};

Gfx D_04006D00_EE2B0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04006680_EDC30, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04006700_EDCB0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP1Quadrangle(5, 4, 3, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 7, 0),
    gsSP1Quadrangle(12, 11, 10, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 17, 0, 22, 21, 20, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 26, 0),
    gsSPVertex(D_040068F0_EDEA0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 3, 0, 8, 7, 6, 0),
    gsSP2Triangles(8, 6, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 14, 13, 0),
    gsSP2Triangles(16, 13, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 22, 21, 0),
    gsSP2Triangles(24, 21, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_04006AF0_EE0A0, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(5, 10, 11, 0, 4, 10, 5, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP1Quadrangle(18, 16, 15, 19, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04006C30_EE1E0, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 3, 10, 0),
    gsSP2Triangles(11, 6, 10, 0, 12, 0, 10, 0),
    gsSP2Triangles(2, 11, 0, 0, 5, 12, 3, 0),
    gsSP1Triangle(8, 9, 6, 0),
    gsSPEndDisplayList(),
};
