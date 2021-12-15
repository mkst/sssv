#include <ultra64.h>

Vtx D_0101B870_55140[8] = {
#include "data/inc/D_0101B870_55140.inc.c"
};
Vtx D_0101B8F0_551C0[14] = {
#include "data/inc/D_0101B8F0_551C0.inc.c"
};

Gfx D_0101B9D0_552A0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101B870_55140, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101B8F0_551C0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 5, 1, 0, 5, 3, 1, 0),
    gsSP2Triangles(0, 4, 1, 0, 2, 6, 7, 0),
    gsSP2Triangles(2, 7, 0, 0, 3, 6, 2, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
    gsSP2Triangles(12, 9, 13, 0, 8, 13, 9, 0),
    gsSP2Triangles(11, 9, 12, 0, 4, 10, 5, 0),
    gsSP2Triangles(11, 5, 10, 0, 4, 8, 10, 0),
    gsSP2Triangles(8, 0, 7, 0, 3, 11, 12, 0),
    gsSP2Triangles(11, 3, 5, 0, 0, 8, 4, 0),
    gsSPEndDisplayList(),
};
