#include <ultra64.h>

Vtx D_05003450_96040[8] = {
#include "data/inc/D_05003450_96040.inc.c"
};
Vtx D_050034D0_960C0[30] = {
#include "data/inc/D_050034D0_960C0.inc.c"
};
Vtx D_050036B0_962A0[31] = {
#include "data/inc/D_050036B0_962A0.inc.c"
};
Vtx D_050038A0_96490[32] = {
#include "data/inc/D_050038A0_96490.inc.c"
};

Gfx D_05003AA0_96690[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05003450_96040, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050034D0_960C0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_050036B0_962A0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 0, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(1, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_050038A0_96490, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(5, 10, 3, 0, 7, 5, 4, 0),
    gsSP2Triangles(9, 7, 6, 0, 11, 12, 13, 0),
    gsSP2Triangles(12, 14, 15, 0, 14, 16, 17, 0),
    gsSP2Triangles(13, 18, 11, 0, 15, 13, 12, 0),
    gsSP2Triangles(17, 15, 14, 0, 19, 20, 21, 0),
    gsSP2Triangles(20, 22, 23, 0, 22, 24, 25, 0),
    gsSP2Triangles(21, 26, 19, 0, 23, 21, 20, 0),
    gsSP2Triangles(25, 23, 22, 0, 27, 28, 29, 0),
    gsSP1Triangle(28, 30, 31, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
