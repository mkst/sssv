#include <ultra64.h>

Vtx D_01018C60_52530[30] = {
#include "data/inc/D_01018C60_52530.inc.c"
};
Vtx D_01018E40_52710[30] = {
#include "data/inc/D_01018E40_52710.inc.c"
};
Vtx D_01019020_528F0[30] = {
#include "data/inc/D_01019020_528F0.inc.c"
};
Vtx D_01019200_52AD0[32] = {
#include "data/inc/D_01019200_52AD0.inc.c"
};
Vtx D_01019400_52CD0[3] = {
#include "data/inc/D_01019400_52CD0.inc.c"
};

Gfx D_01019430_52D00[] = {
    gsSPVertex(D_01018C60_52530, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(8, 0, 10, 0, 2, 10, 0, 0),
    gsSP2Triangles(5, 11, 3, 0, 7, 5, 4, 0),
    gsSP2Triangles(9, 7, 6, 0, 10, 9, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_01018E40_52710, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_01019020_528F0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_01019200_52AD0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(11, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_01019400_52CD0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
