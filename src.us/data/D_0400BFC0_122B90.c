#include <ultra64.h>

Vtx D_0400BEC0_122A90[16] = {
#include "data/inc/D_0400BEC0_122A90.inc.c"
};

const Gfx D_0400BFC0_122B90[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_AA_ZB_OPA_INTER2),
    gsSPVertex(D_0400BEC0_122A90, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 12, 4, 0),
    gsSP2Triangles(8, 7, 11, 0, 9, 14, 7, 0),
    gsSP2Triangles(2, 5, 0, 0, 1, 0, 3, 0),
    gsSP2Triangles(6, 15, 5, 0, 11, 10, 8, 0),
    gsSP2Triangles(12, 13, 10, 0, 4, 3, 13, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
