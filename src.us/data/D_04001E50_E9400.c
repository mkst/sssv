#include <ultra64.h>

Vtx D_04001AE0_E9090[22] = {
#include "data/inc/D_04001AE0_E9090.inc.c"
};
Vtx D_04001C40_E91F0[3] = {
#include "data/inc/D_04001C40_E91F0.inc.c"
};
Vtx D_04001C70_E9220[3] = {
#include "data/inc/D_04001C70_E9220.inc.c"
};
Vtx D_04001CA0_E9250[17] = {
#include "data/inc/D_04001CA0_E9250.inc.c"
};
Vtx D_04001DB0_E9360[10] = {
#include "data/inc/D_04001DB0_E9360.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04001E50_E9400[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_04001CA0_E9250, 17, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 0, 2, 0, 6, 1, 0, 0),
    gsSP2Triangles(0, 7, 6, 0, 7, 0, 5, 0),
    gsSP2Triangles(1, 6, 8, 0, 8, 3, 1, 0),
    gsSP2Triangles(3, 8, 9, 0, 9, 4, 3, 0),
    gsSP2Triangles(4, 9, 10, 0, 5, 10, 7, 0),
    gsSP2Triangles(10, 5, 4, 0, 11, 12, 13, 0),
    gsSP2Triangles(12, 14, 13, 0, 14, 15, 13, 0),
    gsSP2Triangles(15, 16, 13, 0, 16, 11, 13, 0),
    gsDPSetPrimColor(0, 0, 0xD4, 0xC0, 0x4E, 0xFF),
    gsSPVertex(D_04001DB0_E9360, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 2, 1, 0),
    gsSP2Triangles(1, 6, 5, 0, 7, 5, 6, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 4, 9, 0),
    gsSP2Triangles(9, 7, 8, 0, 3, 9, 4, 0),
    gsDPSetPrimColor(0, 0, 0x64, 0x32, 0x32, 0xFF),
    gsSPVertex(D_04001C40_E91F0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_04001C70_E9220, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFC, 0xDC, 0x5C, 0xFF),
    gsSPVertex(D_04001AE0_E9090, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(3, 4, 1, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 5, 3, 0),
    gsSP2Triangles(5, 7, 8, 0, 8, 9, 5, 0),
    gsSP2Triangles(10, 8, 7, 0, 7, 11, 10, 0),
    gsSP2Triangles(12, 5, 9, 0, 6, 5, 12, 0),
    gsSP2Triangles(12, 13, 6, 0, 13, 12, 14, 0),
    gsSP2Triangles(15, 6, 13, 0, 15, 1, 4, 0),
    gsSP2Triangles(15, 2, 1, 0, 14, 11, 16, 0),
    gsSP2Triangles(11, 14, 17, 0, 17, 10, 11, 0),
    gsSP2Triangles(14, 12, 18, 0, 18, 17, 14, 0),
    gsSP2Triangles(9, 18, 12, 0, 3, 19, 7, 0),
    gsSP2Triangles(19, 16, 11, 0, 11, 7, 19, 0),
    gsSP2Triangles(19, 3, 0, 0, 16, 19, 0, 0),
    gsSP2Triangles(16, 20, 14, 0, 20, 16, 0, 0),
    gsSP2Triangles(2, 20, 0, 0, 20, 2, 21, 0),
    gsSP2Triangles(21, 14, 20, 0, 14, 21, 13, 0),
    gsSP1Triangle(15, 13, 21, 0),
    gsSPEndDisplayList(),
};
