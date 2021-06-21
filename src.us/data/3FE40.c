#include <ultra64.h>

extern Vtx D_010064B0[];
extern Vtx D_01006510[];

const Gfx D_80051970[] = {
    gsSPVertex(D_010064B0, 6, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 2, 0, 3, 0),
    gsSP1Quadrangle(5, 2, 4, 3, 0),
    gsSP1Quadrangle(1, 2, 5, 3, 0),
    gsSPVertex(D_01006510, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
