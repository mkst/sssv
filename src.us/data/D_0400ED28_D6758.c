#include <ultra64.h>

Vtx D_0400EAA0_D64D0[12] = {
    #include "data/inc/D_0400EAA0_D64D0.inc.c"
};

Gfx D_0400EB60_D6590[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400EAA0_D64D0, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 0, 2, 0, 4, 3, 0, 0),
    gsSP2Triangles(5, 4, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(1, 5, 2, 0, 1, 3, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 9, 10, 0),
    gsSP2Triangles(9, 6, 11, 0, 8, 11, 6, 0),
    gsSP2Triangles(10, 8, 7, 0, 11, 10, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

Vtx D_0400EBB8_D65E8[23] = {
#include "data/inc/D_0400EBB8_D65E8.inc.c"
};

Gfx D_0400ED28_D6758[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400EBB8_D65E8, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(7, 0, 9, 0, 10, 11, 1, 0),
    gsSP2Triangles(11, 12, 3, 0, 12, 13, 5, 0),
    gsSP2Triangles(13, 14, 7, 0, 14, 10, 0, 0),
    gsSP2Triangles(9, 2, 15, 0, 2, 4, 15, 0),
    gsSP2Triangles(4, 6, 15, 0, 6, 8, 15, 0),
    gsSP2Triangles(8, 9, 15, 0, 2, 9, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 6, 4, 3, 0),
    gsSP2Triangles(8, 6, 5, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 14, 16, 0, 14, 13, 16, 0),
    gsSP2Triangles(13, 12, 16, 0, 12, 11, 16, 0),
    gsSP2Triangles(11, 10, 16, 0, 1, 0, 10, 0),
    gsSP2Triangles(3, 1, 11, 0, 5, 3, 12, 0),
    gsSP2Triangles(7, 5, 13, 0, 0, 7, 14, 0),
    gsSP2Triangles(17, 18, 19, 0, 19, 20, 21, 0),
    gsSP2Triangles(17, 19, 21, 0, 20, 22, 21, 0),
    gsSP2Triangles(19, 18, 20, 0, 22, 17, 21, 0),
    gsSP2Triangles(20, 18, 22, 0, 22, 18, 17, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
