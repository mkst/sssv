#include <ultra64.h>

Vtx D_010065C0_3FE90[] = {
#include "data/inc/D_010065C0_3FE90.inc.c"
};

Vtx D_01006620_3FEF0[] = {
#include "data/inc/D_01006620_3FEF0.inc.c"
};

const Gfx D_01006680_3FF50[] = {
    gsSPVertex(D_010065C0_3FE90, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 1, 4, 0),
    gsSP1Quadrangle(5, 1, 2, 3, 0),
    gsSP1Quadrangle(5, 3, 4, 1, 0),
    gsSPVertex(D_01006620_3FEF0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
