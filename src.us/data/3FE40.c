#include <ultra64.h>

Vtx D_010064B0_3FD80[] = {
#include "data/inc/D_010064B0_3FD80.inc.c"
};

Vtx D_01006510_3FDE0[] = {
#include "data/inc/D_01006510_3FDE0.inc.c"
};

Gfx D_01006570_3FE40[] = {
    gsSPVertex(D_010064B0_3FD80, 6, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 2, 0, 3, 0),
    gsSP1Quadrangle(5, 2, 4, 3, 0),
    gsSP1Quadrangle(1, 2, 5, 3, 0),
    gsSPVertex(D_01006510_3FDE0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
