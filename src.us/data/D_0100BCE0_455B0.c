#include <ultra64.h>

Vtx D_0100B330_44C00[8] = {
#include "data/inc/D_0100B330_44C00.inc.c"
};
Vtx D_0100B3B0_44C80[32] = {
#include "data/inc/D_0100B3B0_44C80.inc.c"
};
Vtx D_0100B5B0_44E80[31] = {
#include "data/inc/D_0100B5B0_44E80.inc.c"
};
Vtx D_0100B7A0_45070[30] = {
#include "data/inc/D_0100B7A0_45070.inc.c"
};
Vtx D_0100B980_45250[32] = {
#include "data/inc/D_0100B980_45250.inc.c"
};
Vtx D_0100BB80_45450[22] = {
#include "data/inc/D_0100BB80_45450.inc.c"
};

Gfx D_0100BCE0_455B0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0100B330_44C00, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0100B3B0_44C80, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 15, 17, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 19, 21, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_0100B5B0_44E80, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 4, 11, 6, 0),
    gsSP2Triangles(12, 6, 11, 0, 13, 7, 14, 0),
    gsSP2Triangles(9, 14, 7, 0, 11, 15, 12, 0),
    gsSP2Triangles(16, 12, 15, 0, 17, 13, 18, 0),
    gsSP2Triangles(14, 18, 13, 0, 15, 19, 16, 0),
    gsSP2Triangles(20, 16, 19, 0, 21, 17, 22, 0),
    gsSP2Triangles(18, 22, 17, 0, 19, 23, 20, 0),
    gsSP2Triangles(24, 20, 23, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_0100B7A0_45070, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 16, 15, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_0100B980_45250, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 20, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 25, 27, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_0100BB80_45450, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 14, 13, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 17, 19, 0, 8, 21, 9, 0),
    gsSPEndDisplayList(),
};
