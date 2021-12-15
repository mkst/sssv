#include <ultra64.h>


Vtx D_05001750_A0460[8] = {
#include "data/inc/D_05001750_A0460.inc.c"
};
Vtx D_050017D0_A04E0[32] = {
#include "data/inc/D_050017D0_A04E0.inc.c"
};
Vtx D_050019D0_A06E0[32] = {
#include "data/inc/D_050019D0_A06E0.inc.c"
};
Vtx D_05001BD0_A08E0[30] = {
#include "data/inc/D_05001BD0_A08E0.inc.c"
};
Vtx D_05001DB0_A0AC0[18] = {
#include "data/inc/D_05001DB0_A0AC0.inc.c"
};
Vtx D_05001ED0_A0BE0[16] = {
#include "data/inc/D_05001ED0_A0BE0.inc.c"
};


Gfx D_05001FD0_A0CE0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05001750_A0460, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_050017D0_A04E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 6, 4, 3, 0),
    gsSP2Triangles(9, 8, 13, 0, 13, 8, 7, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 15, 16, 0),
    gsSP2Triangles(18, 15, 19, 0, 20, 15, 16, 0),
    gsSP2Triangles(21, 15, 16, 0, 22, 15, 16, 0),
    gsSP2Triangles(23, 15, 24, 0, 25, 15, 16, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 27, 28, 0),
    gsSP1Triangle(30, 27, 31, 0),
    gsSPVertex(D_050019D0_A06E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 2, 0),
    gsSP2Triangles(2, 1, 4, 0, 5, 1, 6, 0),
    gsSP2Triangles(7, 1, 2, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05001BD0_A08E0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 2, 0),
    gsSP2Triangles(8, 9, 2, 0, 9, 10, 2, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 0, 2, 0),
    gsSP2Triangles(15, 16, 17, 0, 16, 18, 17, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 17, 0),
    gsSP2Triangles(23, 24, 17, 0, 24, 25, 17, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 15, 17, 0),
    gsSPVertex(D_05001DB0_A0AC0, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05001ED0_A0BE0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(2, 12, 0, 0, 5, 13, 3, 0),
    gsSP2Triangles(8, 14, 6, 0, 11, 15, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
