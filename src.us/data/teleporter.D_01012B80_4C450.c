#include <ultra64.h>

Vtx D_01012790_4C060[8] = {
#include "data/inc/D_01012790_4C060.inc.c"
};
Vtx D_01012810_4C0E0[7] = {
#include "data/inc/D_01012810_4C0E0.inc.c"
};
Vtx D_01012880_4C150[32] = {
#include "data/inc/D_01012880_4C150.inc.c"
};
Vtx D_01012A80_4C350[16] = {
#include "data/inc/D_01012A80_4C350.inc.c"
};

Gfx D_01012B80_4C450[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01012790_4C060, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsSPVertex(D_01012880_4C150, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_01012A80_4C350, 16, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0),
    gsSPVertex(D_01012810_4C0E0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 6, 0, 2, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
