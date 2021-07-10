#include <ultra64.h>


Vtx D_05000A10_97A30[31] = {
#include "data/inc/D_05000A10_97A30.inc.c"
};
Vtx D_05000C00_97C20[31] = {
#include "data/inc/D_05000C00_97C20.inc.c"
};
Vtx D_05000DF0_97E10[26] = {
#include "data/inc/D_05000DF0_97E10.inc.c"
};


const Gfx D_05000F90_97FB0[] = {
    gsSPVertex(D_05000A10_97A30, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(0, 2, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 1, 0, 18, 19, 20, 0),
    gsSP2Triangles(8, 7, 21, 0, 22, 3, 23, 0),
    gsSP2Triangles(17, 2, 1, 0, 0, 6, 24, 0),
    gsSP1Quadrangle(0, 24, 21, 7, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_05000C00_97C20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(8, 22, 6, 0, 23, 24, 25, 0),
    gsSP2Triangles(15, 26, 13, 0, 27, 28, 29, 0),
    gsSP1Triangle(21, 30, 19, 0),
    gsSPVertex(D_05000DF0_97E10, 26, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 5, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 4, 24, 0, 25, 3, 5, 0),
    gsSP1Triangle(19, 25, 5, 0),
    gsSPEndDisplayList(),
};
