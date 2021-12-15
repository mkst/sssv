#include <ultra64.h>

Vtx D_05001AA0_B2630[19] = {
#include "data/inc/D_05001AA0_B2630.inc.c"
};

Gfx D_05001BD0_B2760[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPVertex(D_05001AA0_B2630, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 6, 0, 2, 0),
    gsSP2Triangles(0, 7, 8, 0, 1, 8, 9, 0),
    gsSP2Triangles(3, 9, 10, 0, 4, 10, 11, 0),
    gsSP2Triangles(5, 11, 12, 0, 6, 12, 7, 0),
    gsSP2Triangles(7, 13, 14, 0, 8, 14, 15, 0),
    gsSP2Triangles(9, 15, 16, 0, 10, 16, 17, 0),
    gsSP2Triangles(11, 17, 18, 0, 12, 18, 13, 0),
    gsSP2Triangles(8, 1, 0, 0, 9, 3, 1, 0),
    gsSP2Triangles(10, 4, 3, 0, 11, 5, 4, 0),
    gsSP2Triangles(12, 6, 5, 0, 7, 0, 6, 0),
    gsSP2Triangles(14, 8, 7, 0, 15, 9, 8, 0),
    gsSP2Triangles(16, 10, 9, 0, 17, 11, 10, 0),
    gsSP2Triangles(18, 12, 11, 0, 13, 7, 12, 0),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};
