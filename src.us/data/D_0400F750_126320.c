#include <ultra64.h>

Vtx D_0400F600_1261D0[21] = {
#include "data/inc/D_0400F600_1261D0.inc.c"
};

extern u8 D_0400EE00_1259D0[];

const Gfx D_0400F750_126320[] = {
    gsDPPipeSync(),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400EE00_1259D0),
    gsSPVertex(D_0400F600_1261D0, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 4, 5, 0, 2, 1, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 5, 4, 7, 0),
    gsSP2Triangles(6, 8, 9, 0, 7, 6, 9, 0),
    gsSP2Triangles(8, 10, 11, 0, 9, 8, 11, 0),
    gsSP2Triangles(10, 12, 13, 0, 11, 10, 13, 0),
    gsSP2Triangles(12, 14, 15, 0, 13, 12, 15, 0),
    gsSP2Triangles(14, 16, 17, 0, 15, 14, 17, 0),
    gsSP2Triangles(16, 18, 19, 0, 17, 16, 19, 0),
    gsSP2Triangles(20, 10, 8, 0, 20, 12, 10, 0),
    gsSP2Triangles(20, 14, 12, 0, 16, 14, 20, 0),
    gsSP2Triangles(20, 0, 16, 0, 1, 0, 20, 0),
    gsSP2Triangles(20, 4, 1, 0, 6, 4, 20, 0),
    gsSP1Triangle(20, 8, 6, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
