#include <ultra64.h>

Vtx D_0400BA40_FCAA0[10] = {
#include "data/inc/D_0400BA40_FCAA0.inc.c"
};
Vtx D_0400BAE0_FCB40[3] = {
#include "data/inc/D_0400BAE0_FCB40.inc.c"
};
Vtx D_0400BB10_FCB70[10] = {
#include "data/inc/D_0400BB10_FCB70.inc.c"
};
Vtx D_0400BBB0_FCC10[21] = {
#include "data/inc/D_0400BBB0_FCC10.inc.c"
};

extern Gfx D_01003508_3CDD8[];
extern Gfx D_010034C0_3CD90[];

Gfx D_0400BD00_FCD60[] = {
    gsSPDisplayList(D_01003508_3CDD8),
    gsSPTexture(0xFFFF, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_0400BA40_FCAA0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 7, 0),
    gsSPVertex(D_0400BAE0_FCB40, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_0400BB10_FCB70, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 7, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPTexture(0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400BBB0_FCC10, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 3, 1, 0, 4, 5, 3, 0),
    gsSP2Triangles(3, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 9, 7, 0, 11, 6, 8, 0),
    gsSP2Triangles(2, 3, 11, 0, 6, 11, 3, 0),
    gsSP1Quadrangle(8, 9, 12, 11, 0),
    gsSP1Quadrangle(13, 12, 9, 10, 0),
    gsSP2Triangles(10, 14, 13, 0, 15, 13, 14, 0),
    gsSP2Triangles(15, 0, 2, 0, 15, 16, 13, 0),
    gsSP2Triangles(12, 13, 16, 0, 15, 17, 16, 0),
    gsSP2Triangles(15, 2, 17, 0, 17, 11, 12, 0),
    gsSP2Triangles(11, 17, 2, 0, 12, 16, 17, 0),
    gsSP2Triangles(15, 14, 18, 0, 7, 15, 18, 0),
    gsSP2Triangles(14, 10, 19, 0, 18, 19, 7, 0),
    gsSP2Triangles(19, 10, 7, 0, 19, 18, 14, 0),
    gsSP2Triangles(1, 0, 20, 0, 15, 7, 20, 0),
    gsSP1Quadrangle(5, 4, 20, 7, 0),
    gsSP2Triangles(20, 4, 1, 0, 20, 0, 15, 0),
    gsSPEndDisplayList(),
};
