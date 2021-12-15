#include <ultra64.h>

Vtx D_04007CC0_EF270[18] = {
#include "data/inc/D_04007CC0_EF270.inc.c"
};
Vtx D_04007DE0_EF390[30] = {
#include "data/inc/D_04007DE0_EF390.inc.c"
};
Vtx D_04007FC0_EF570[14] = {
#include "data/inc/D_04007FC0_EF570.inc.c"
};
Vtx D_040080A0_EF650[30] = {
#include "data/inc/D_040080A0_EF650.inc.c"
};
Vtx D_04008280_EF830[6] = {
#include "data/inc/D_04008280_EF830.inc.c"
};

Gfx D_040082E0_EF890[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04007CC0_EF270, 18, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(7, 10, 11, 8, 0),
    gsSP1Quadrangle(10, 6, 9, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(13, 16, 17, 14, 0),
    gsSP1Quadrangle(16, 12, 15, 17, 0),
    gsSPVertex(D_04007DE0_EF390, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(0, 5, 3, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 6, 0, 11, 2, 1, 0),
    gsSP2Triangles(1, 12, 11, 0, 6, 11, 12, 0),
    gsSP2Triangles(12, 7, 6, 0, 2, 5, 0, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 13, 0),
    gsSP2Triangles(13, 18, 16, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 15, 14, 0),
    gsSP2Triangles(14, 26, 25, 0, 19, 25, 26, 0),
    gsSP2Triangles(26, 20, 19, 0, 15, 18, 13, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_04007FC0_EF570, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
    gsSP2Triangles(4, 10, 13, 0, 13, 5, 4, 0),
    gsSP1Triangle(11, 3, 2, 0),
    gsSPVertex(D_040080A0_EF650, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
    gsSP2Triangles(0, 2, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 7, 6, 0, 10, 7, 9, 0),
    gsSP2Triangles(11, 7, 10, 0, 8, 7, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 13, 12, 0),
    gsSP2Triangles(16, 15, 12, 0, 17, 16, 12, 0),
    gsSP2Triangles(12, 14, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 19, 18, 0, 22, 19, 21, 0),
    gsSP2Triangles(23, 19, 22, 0, 20, 19, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 25, 24, 0),
    gsSP2Triangles(28, 27, 24, 0, 29, 28, 24, 0),
    gsSP1Triangle(24, 26, 29, 0),
    gsSPVertex(D_04008280_EF830, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 1, 3, 0, 5, 1, 4, 0),
    gsSP1Triangle(2, 1, 5, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
