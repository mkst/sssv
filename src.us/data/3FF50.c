#include <ultra64.h>

extern Vtx D_010065C0[];
extern Vtx D_01006620[];

const Gfx D_80051A80[] = {
    gsSPVertex(D_010065C0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 1, 4, 0),
    gsSP1Quadrangle(5, 1, 2, 3, 0),
    gsSP1Quadrangle(5, 3, 4, 1, 0),
    gsSPVertex(D_01006620, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
