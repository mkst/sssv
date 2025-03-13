#include <ultra64.h>


Vtx D_04009AA0_D14D0[8] = {
#include "data/inc/D_04009AA0_D14D0.inc.c"
};
Vtx D_04009B20_D1550[15] = {
#include "data/inc/D_04009B20_D1550.inc.c"
};
Vtx D_04009C10_D1640[26] = {
#include "data/inc/D_04009C10_D1640.inc.c"
};


Gfx D_04009DB0_D17E0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04009AA0_D14D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04009B20_D1550, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 4, 0, 2, 5, 0, 0),
    gsSP2Triangles(1, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 7, 0),
    gsSP2Triangles(10, 11, 12, 0, 8, 13, 6, 0),
    gsSP2Triangles(7, 12, 14, 0, 12, 7, 10, 0),
    gsSP2Triangles(14, 8, 7, 0, 10, 9, 13, 0),
    gsSP2Triangles(11, 10, 8, 0, 13, 8, 10, 0),
    gsSP2Triangles(8, 14, 11, 0, 7, 6, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04009C10_D1640, 26, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 4, 0, 2, 5, 0, 0),
    gsSP2Triangles(1, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 6, 8, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 7, 6, 0, 8, 9, 11, 0),
    gsSP2Triangles(7, 10, 9, 0, 6, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(17, 12, 14, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 13, 12, 0, 14, 15, 17, 0),
    gsSP2Triangles(13, 16, 15, 0, 12, 17, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 19, 21, 20, 0),
    gsSP2Triangles(21, 18, 20, 0, 18, 22, 23, 0),
    gsSP2Triangles(19, 23, 24, 0, 21, 24, 22, 0),
    gsSP2Triangles(25, 23, 22, 0, 25, 24, 23, 0),
    gsSP2Triangles(25, 22, 24, 0, 23, 19, 18, 0),
    gsSP2Triangles(24, 21, 19, 0, 22, 18, 21, 0),
    gsSPEndDisplayList(),
};
