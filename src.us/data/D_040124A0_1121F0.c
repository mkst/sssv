#include <ultra64.h>

Vtx D_04012260_111FB0[8] = {
#include "data/inc/D_04012260_111FB0.inc.c"
};
Vtx D_040122E0_112030[20] = {
#include "data/inc/D_040122E0_112030.inc.c"
};
Vtx D_04012420_112170[8] = {
#include "data/inc/D_04012420_112170.inc.c"
};

const Gfx D_040124A0_1121F0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04012260_111FB0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x1F, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_040122E0_112030, 20, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 3, 2, 13, 0),
    gsSP1Quadrangle(12, 13, 7, 6, 0),
    gsSP1Quadrangle(14, 1, 0, 15, 0),
    gsSP1Quadrangle(14, 15, 5, 4, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(19, 18, 12, 6, 0),
    gsSP1Quadrangle(18, 17, 15, 12, 0),
    gsSP1Quadrangle(17, 16, 5, 15, 0),
    gsSP1Quadrangle(16, 19, 6, 5, 0),
    gsSP1Quadrangle(11, 10, 7, 13, 0),
    gsSP1Quadrangle(10, 9, 4, 7, 0),
    gsSP1Quadrangle(9, 8, 14, 4, 0),
    gsSP1Quadrangle(8, 11, 13, 14, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x8A, 0x89, 0xA5, 0xFF),
    gsSPVertex(D_04012420_112170, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
