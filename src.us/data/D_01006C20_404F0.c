#include <ultra64.h>

Vtx D_01006B20_403F0[16] = {
#include "data/inc/D_01006B20_403F0.inc.c"
};

Gfx D_01006C20_404F0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_01006B20_403F0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
    gsSP2Triangles(6, 14, 4, 0, 9, 15, 7, 0),
    gsSPEndDisplayList(),
};
