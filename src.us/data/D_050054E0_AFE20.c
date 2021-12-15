#include <ultra64.h>

Vtx D_05004B30_AF470[8] = {
#include "data/inc/D_05004B30_AF470.inc.c"
};
Vtx D_05004BB0_AF4F0[31] = {
#include "data/inc/D_05004BB0_AF4F0.inc.c"
};
Vtx D_05004DA0_AF6E0[32] = {
#include "data/inc/D_05004DA0_AF6E0.inc.c"
};
Vtx D_05004FA0_AF8E0[32] = {
#include "data/inc/D_05004FA0_AF8E0.inc.c"
};
Vtx D_050051A0_AFAE0[32] = {
#include "data/inc/D_050051A0_AFAE0.inc.c"
};
Vtx D_050053A0_AFCE0[20] = {
#include "data/inc/D_050053A0_AFCE0.inc.c"
};

Gfx D_050054E0_AFE20[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05004B30_AF470, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x96, 0xFF, 0xFF),
    gsSPVertex(D_05004BB0_AF4F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(4, 3, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(8, 7, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 15, 14, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 6, 20, 9, 0),
    gsSP2Triangles(9, 20, 8, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 23, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 23, 24, 26, 0),
    gsSP1Triangle(22, 30, 24, 0),
    gsSPVertex(D_05004DA0_AF6E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 8, 7, 0, 11, 12, 13, 0),
    gsSP2Triangles(12, 14, 13, 0, 15, 16, 17, 0),
    gsSP2Triangles(16, 18, 17, 0, 18, 15, 17, 0),
    gsSP2Triangles(11, 14, 15, 0, 12, 11, 18, 0),
    gsSP2Triangles(14, 12, 16, 0, 7, 8, 9, 0),
    gsSP2Triangles(14, 11, 13, 0, 11, 12, 13, 0),
    gsSP2Triangles(9, 8, 10, 0, 10, 8, 7, 0),
    gsSP2Triangles(5, 4, 6, 0, 3, 4, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 20, 19, 0, 23, 24, 25, 0),
    gsSP2Triangles(5, 26, 27, 0, 28, 26, 5, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05004FA0_AF8E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 1, 3, 0, 4, 5, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 8, 7, 0),
    gsSP2Triangles(0, 11, 3, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 13, 12, 0, 16, 17, 18, 0),
    gsSP2Triangles(7, 19, 20, 0, 21, 19, 7, 0),
    gsSP2Triangles(22, 23, 24, 0, 2, 1, 3, 0),
    gsSP2Triangles(23, 22, 25, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 24, 0, 4, 5, 6, 0),
    gsSP2Triangles(29, 28, 30, 0, 7, 8, 9, 0),
    gsSP1Triangle(30, 26, 31, 0),
    gsSPVertex(D_050051A0_AFAE0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(9, 12, 13, 0, 2, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 21, 20, 25, 0),
    gsSP2Triangles(4, 3, 22, 0, 26, 27, 28, 0),
    gsSP2Triangles(29, 11, 10, 0, 30, 29, 12, 0),
    gsSP2Triangles(30, 29, 12, 0, 29, 11, 10, 0),
    gsSP2Triangles(11, 30, 9, 0, 27, 22, 3, 0),
    gsSP1Triangle(24, 26, 31, 0),
    gsSPVertex(D_050053A0_AFCE0, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(6, 7, 7, 8, 0),
    gsSP1Quadrangle(9, 10, 11, 9, 0),
    gsSP1Quadrangle(12, 7, 7, 13, 0),
    gsSP1Quadrangle(13, 7, 7, 14, 0),
    gsSP1Quadrangle(9, 15, 16, 9, 0),
    gsSP1Quadrangle(9, 16, 10, 9, 0),
    gsSP1Quadrangle(9, 17, 18, 9, 0),
    gsSP1Quadrangle(8, 7, 7, 19, 0),
    gsSP1Quadrangle(14, 7, 7, 6, 0),
    gsSP1Quadrangle(9, 18, 15, 9, 0),
    gsSP1Quadrangle(9, 11, 17, 9, 0),
    gsSP1Quadrangle(19, 7, 7, 12, 0),
    gsSPEndDisplayList(),
};
