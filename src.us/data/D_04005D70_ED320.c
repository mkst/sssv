#include <ultra64.h>

Vtx D_04005CD0_ED280[10] = {
#include "data/inc/D_04005CD0_ED280.inc.c"
};

Gfx D_04005D70_ED320[] = {
    gsSPVertex(D_04005CD0_ED280, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(1, 3, 4, 0, 2, 5, 3, 0),
    gsSP2Triangles(1, 4, 6, 0, 6, 4, 3, 0),
    gsSP2Triangles(6, 3, 7, 0, 7, 3, 5, 0),
    gsSP2Triangles(1, 6, 8, 0, 8, 6, 7, 0),
    gsSP2Triangles(1, 8, 0, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 7, 5, 0, 0, 8, 9, 0),
    gsSP2Triangles(0, 9, 2, 0, 2, 9, 5, 0),
    gsSPEndDisplayList(),
};
