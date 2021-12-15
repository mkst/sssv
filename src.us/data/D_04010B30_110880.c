#include <ultra64.h>

Vtx D_040109B0_110700[16] = {
#include "data/inc/D_040109B0_110700.inc.c"
};
Vtx D_04010AB0_110800[8] = {
#include "data/inc/D_04010AB0_110800.inc.c"
};

Gfx D_04010B30_110880[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x43, 0x8A, 0xFF),
    gsSPVertex(D_040109B0_110700, 16, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(1, 6, 7, 2, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 4, 6, 0),
    gsSP1Quadrangle(13, 14, 0, 4, 0),
    gsSP1Quadrangle(14, 15, 1, 0, 0),
    gsSP1Quadrangle(15, 12, 6, 1, 0),
    gsSP1Quadrangle(11, 10, 13, 12, 0),
    gsSP1Quadrangle(10, 9, 14, 13, 0),
    gsSP1Quadrangle(9, 8, 15, 14, 0),
    gsSP1Quadrangle(8, 11, 12, 15, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFA, 0xBF, 0xFF),
    gsSPVertex(D_04010AB0_110800, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(1, 6, 7, 2, 0),
    gsSP1Quadrangle(1, 0, 4, 6, 0),
    gsSPEndDisplayList(),
};
