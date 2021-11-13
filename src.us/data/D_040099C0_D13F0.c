#include <ultra64.h>

Vtx D_04009780_D11B0[12] = {
#include "data/inc/D_04009780_D11B0.inc.c"
};
Vtx D_04009840_D1270[24] = {
#include "data/inc/D_04009840_D1270.inc.c"
};

const Gfx D_040099C0_D13F0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFB, 0xFF, 0xBA, 0xFF),
    gsSPVertex(D_04009780_D11B0, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 8, 1, 0),
    gsSP2Triangles(7, 9, 10, 0, 5, 6, 10, 0),
    gsSP2Triangles(5, 3, 4, 0, 0, 2, 4, 0),
    gsSP2Triangles(0, 11, 1, 0, 5, 9, 7, 0),
    gsSP2Triangles(5, 11, 0, 0, 5, 7, 11, 0),
    gsSP2Triangles(5, 0, 3, 0, 9, 5, 10, 0),
    gsSP2Triangles(7, 10, 8, 0, 11, 7, 1, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x53, 0x3D, 0x0F, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04009840_D1270, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(8, 10, 11, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 0, 17, 18, 0),
    gsSP2Triangles(5, 19, 20, 0, 12, 21, 22, 0),
    gsSP2Triangles(2, 23, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(6, 3, 4, 0, 9, 14, 7, 0),
    gsSP2Triangles(11, 9, 8, 0, 13, 10, 11, 0),
    gsSP2Triangles(16, 7, 14, 0, 18, 23, 0, 0),
    gsSP2Triangles(20, 6, 5, 0, 22, 13, 12, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
