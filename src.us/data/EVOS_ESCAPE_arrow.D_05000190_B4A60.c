#include <ultra64.h>


Vtx D_05000000_B48D0[6] = {
#include "data/inc/D_05000000_B48D0.inc.c"
};
Vtx D_05000060_B4930[12] = {
#include "data/inc/D_05000060_B4930.inc.c"
};
Vtx D_05000120_B49F0[7] = {
#include "data/inc/D_05000120_B49F0.inc.c"
};


Gfx D_05000190_B4A60[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x67, 0x32, 0x21, 0xFF),
    gsSPVertex(D_05000000_B48D0, 6, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 3, 2, 0, 1, 5, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 0, 3, 0),
    gsSP1Triangle(5, 3, 4, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFC, 0xD8, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000060_B4930, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x7A, 0x81, 0x9D, 0xFF),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000120_B49F0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 1, 0, 0, 2, 1, 4, 0),
    gsSP2Triangles(4, 5, 2, 0, 3, 2, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 3, 6, 0, 0),
    gsSP2Triangles(5, 4, 0, 0, 0, 6, 5, 0),
    gsSPEndDisplayList(),
};
