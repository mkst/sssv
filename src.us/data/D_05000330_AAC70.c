#include <ultra64.h>

Vtx D_05000000_AA940[31] = {
#include "data/inc/D_05000000_AA940.inc.c"
};
Vtx D_050001F0_AAB30[20] = {
#include "data/inc/D_050001F0_AAB30.inc.c"
};

Gfx D_05000330_AAC70[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000000_AA940, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 7, 8, 2, 0),
    gsSP2Triangles(9, 10, 2, 0, 11, 12, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(23, 25, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(D_050001F0_AAB30, 20, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(4, 6, 7, 5, 0),
    gsSP1Quadrangle(6, 8, 9, 7, 0),
    gsSP1Quadrangle(8, 0, 3, 9, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(11, 14, 15, 12, 0),
    gsSP1Quadrangle(14, 16, 17, 15, 0),
    gsSP1Quadrangle(16, 18, 19, 17, 0),
    gsSP1Quadrangle(18, 10, 13, 19, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
