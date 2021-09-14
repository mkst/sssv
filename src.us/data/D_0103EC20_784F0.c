#include <ultra64.h>

Vtx D_0103EB20_783F0[16] = {
#include "data/inc/D_0103EB20_783F0.inc.c"
};

const Gfx D_0103EC20_784F0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0103EB20_783F0, 16, 0),
    gsDPPipeSync(),
    gsSP2Triangles(1, 0, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(7, 6, 8, 0, 6, 9, 10, 0),
    gsSP2Triangles(9, 11, 12, 0, 11, 0, 5, 0),
    gsSP2Triangles(0, 1, 4, 0, 1, 2, 3, 0),
    gsSP2Triangles(2, 13, 14, 0, 13, 7, 15, 0),
    gsSP2Triangles(0, 6, 13, 0, 0, 11, 6, 0),
    gsSP2Triangles(13, 2, 0, 0, 7, 13, 6, 0),
    gsSP2Triangles(9, 6, 11, 0, 3, 8, 12, 0),
    gsSP2Triangles(3, 14, 8, 0, 12, 5, 3, 0),
    gsSP2Triangles(10, 12, 8, 0, 15, 8, 14, 0),
    gsSP2Triangles(10, 8, 6, 0, 12, 10, 9, 0),
    gsSP2Triangles(5, 12, 11, 0, 4, 5, 0, 0),
    gsSP2Triangles(3, 4, 1, 0, 14, 3, 2, 0),
    gsSP2Triangles(15, 14, 13, 0, 8, 15, 7, 0),
    gsSPEndDisplayList(),
};
