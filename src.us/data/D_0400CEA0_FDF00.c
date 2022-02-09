#include <ultra64.h>

Vtx D_0400CAB0_FDB10[30] = {
#include "data/inc/D_0400CAB0_FDB10.inc.c"
};
Vtx D_0400CC90_FDCF0[30] = {
#include "data/inc/D_0400CC90_FDCF0.inc.c"
};
Vtx D_0400CE70_FDED0[3] = {
#include "data/inc/D_0400CE70_FDED0.inc.c"
};

Gfx D_0400CEA0_FDF00[] = {
    gsSPVertex(D_0400CAB0_FDB10, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_0400CC90_FDCF0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_0400CE70_FDED0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
