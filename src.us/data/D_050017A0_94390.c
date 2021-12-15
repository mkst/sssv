#include <ultra64.h>

Vtx D_05001680_94270[12] = {
#include "data/inc/D_05001680_94270.inc.c"
};
Vtx D_05001740_94330[6] = {
#include "data/inc/D_05001740_94330.inc.c"
};

Gfx D_050017A0_94390[] = {
    gsSPVertex(D_05001680_94270, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(5, 4, 10, 0, 10, 9, 5, 0),
    gsSP2Triangles(6, 1, 7, 0, 2, 1, 6, 0),
    gsSPVertex(D_05001740_94330, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 3, 4, 0),
    gsSPEndDisplayList(),
};
