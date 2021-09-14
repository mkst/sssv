#include <ultra64.h>

Vtx D_040010D0_C8B00[8] = {
#include "data/inc/D_040010D0_C8B00.inc.c"
};

const Gfx D_04001150_C8B80[] = {
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_040010D0_C8B00, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 3, 4, 0),
    gsSP2Triangles(4, 0, 5, 0, 2, 5, 0, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 2, 1, 0),
    gsSP2Triangles(1, 4, 6, 0, 5, 7, 6, 0),
    gsSP2Triangles(6, 7, 2, 0, 2, 7, 5, 0),
    gsSPEndDisplayList(),
};
