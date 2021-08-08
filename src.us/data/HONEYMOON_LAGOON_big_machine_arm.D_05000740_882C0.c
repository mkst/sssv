#include <ultra64.h>


Vtx D_05000100_87C80[8] = {
#include "data/inc/D_05000100_87C80.inc.c"
};
Vtx D_05000180_87D00[4] = {
#include "data/inc/D_05000180_87D00.inc.c"
};
Vtx D_050001C0_87D40[30] = {
#include "data/inc/D_050001C0_87D40.inc.c"
};
Vtx D_050003A0_87F20[31] = {
#include "data/inc/D_050003A0_87F20.inc.c"
};
Vtx D_05000590_88110[27] = {
#include "data/inc/D_05000590_88110.inc.c"
};


const Gfx D_05000740_882C0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000100_87C80, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000180_87D00, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050001C0_87D40, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_050003A0_87F20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05000590_88110, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP1Triangle(24, 25, 26, 0),
    gsSPEndDisplayList(),
};
