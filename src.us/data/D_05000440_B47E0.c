#include <ultra64.h>

Vtx D_05000000_B43A0[31] = {
#include "data/inc/D_05000000_B43A0.inc.c"
};
Vtx D_050001F0_B4590[32] = {
#include "data/inc/D_050001F0_B4590.inc.c"
};
Vtx D_050003F0_B4790[5] = {
#include "data/inc/D_050003F0_B4790.inc.c"
};

const Gfx D_05000440_B47E0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000000_B43A0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 9, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 13, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 17, 16, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 20, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 25, 24, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_050001F0_B4590, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 7, 8, 9, 0),
    gsSP1Quadrangle(10, 7, 9, 11, 0),
    gsSP2Triangles(10, 11, 8, 0, 8, 11, 9, 0),
    gsSP2Triangles(8, 7, 10, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 13, 12, 0, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 16, 18, 20, 0),
    gsSP2Triangles(19, 20, 17, 0, 17, 20, 18, 0),
    gsSP2Triangles(17, 16, 19, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 22, 21, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 26, 25, 0, 29, 30, 31, 0),
    gsSPVertex(D_050003F0_B4790, 5, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 4, 3, 2, 0),
    gsSP1Triangle(4, 1, 0, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
