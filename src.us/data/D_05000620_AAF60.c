#include <ultra64.h>

Vtx D_050003F0_AAD30[32] = {
#include "data/inc/D_050003F0_AAD30.inc.c"
};
Vtx D_050005F0_AAF30[3] = {
#include "data/inc/D_050005F0_AAF30.inc.c"
};

Gfx D_05000620_AAF60[] = {
    gsSPVertex(D_050003F0_AAD30, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 14, 21, 0),
    gsSP2Triangles(18, 22, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 29, 31, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050005F0_AAF30, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
