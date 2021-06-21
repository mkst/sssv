#include <ultra64.h>

extern Vtx D_010066D0[];

const Gfx D_80051DD0[] = {
    gsSPVertex(D_010066D0, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
