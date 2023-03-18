#include <ultra64.h>

Vtx D_04001320_F2380[16] = {
#include "data/inc/D_04001320_F2380.inc.c"
};
Vtx D_04001420_F2480[16] = {
#include "data/inc/D_04001420_F2480.inc.c"
};
Vtx D_04001520_F2580[11] = {
#include "data/inc/D_04001520_F2580.inc.c"
};

Gfx D_040015D0_F2630[] = {
    gsDPSetPrimColor(0, 0, 0x7D, 0x33, 0xFF, 0xFF),
    gsSPVertex(D_04001320_F2380, 16, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 5, 0),
    gsSP2Triangles(1, 0, 6, 0, 6, 0, 7, 0),
    gsSP2Triangles(7, 0, 8, 0, 8, 0, 5, 0),
    gsSP2Triangles(9, 10, 11, 0, 11, 12, 9, 0),
    gsSP2Triangles(9, 12, 13, 0, 12, 11, 14, 0),
    gsSP1Triangle(13, 15, 9, 0),
    gsSPVertex(D_04001420_F2480, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(1, 3, 4, 0, 2, 5, 0, 0),
    gsSP2Triangles(4, 6, 1, 0, 1, 6, 7, 0),
    gsSP2Triangles(7, 2, 1, 0, 6, 4, 8, 0),
    gsSP2Triangles(8, 9, 6, 0, 6, 9, 10, 0),
    gsSP2Triangles(10, 7, 6, 0, 9, 8, 11, 0),
    gsSP2Triangles(11, 12, 9, 0, 9, 12, 13, 0),
    gsSP2Triangles(13, 10, 9, 0, 12, 11, 14, 0),
    gsSP1Triangle(14, 15, 12, 0),
    gsSPVertex(D_04001520_F2580, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 1, 5, 4, 0),
    gsSP2Triangles(6, 5, 1, 0, 1, 7, 6, 0),
    gsSP2Triangles(5, 6, 8, 0, 8, 9, 5, 0),
    gsSP2Triangles(5, 9, 10, 0, 10, 4, 5, 0),
    gsSPEndDisplayList(),
};
