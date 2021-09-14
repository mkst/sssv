#include <ultra64.h>

Vtx D_0100ECD0_485A0[30] = {
#include "data/inc/D_0100ECD0_485A0.inc.c"
};
Vtx D_0100EEB0_48780[31] = {
#include "data/inc/D_0100EEB0_48780.inc.c"
};
Vtx D_0100F0A0_48970[16] = {
#include "data/inc/D_0100F0A0_48970.inc.c"
};

const Gfx D_0100F1A0_48A70[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0100ECD0_485A0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 0, 0),
    gsSP2Triangles(5, 10, 3, 0, 8, 11, 6, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_0100EEB0_48780, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 23, 22, 19, 0),
    gsSP2Triangles(2, 27, 0, 0, 5, 28, 3, 0),
    gsSP2Triangles(8, 29, 6, 0, 11, 30, 9, 0),
    gsSPVertex(D_0100F0A0_48970, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 11, 13, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
