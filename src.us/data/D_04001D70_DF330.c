#include <ultra64.h>

Vtx D_04001BB0_DF170[10] = {
#include "data/inc/D_04001BB0_DF170.inc.c"
};
Vtx D_04001C50_DF210[18] = {
#include "data/inc/D_04001C50_DF210.inc.c"
};

extern Gfx D_01003548_3CE18[];

const Gfx D_04001D70_DF330[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xD9, 0xE9, 0xF4, 0xFF),
    gsSPVertex(D_04001BB0_DF170, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(2, 4, 3, 0, 0, 4, 2, 0),
    gsSP2Triangles(4, 5, 3, 0, 6, 5, 4, 0),
    gsSP2Triangles(4, 0, 6, 0, 0, 7, 6, 0),
    gsSP2Triangles(7, 0, 8, 0, 8, 9, 7, 0),
    gsDPSetPrimColor(0, 0, 0xAB, 0xB8, 0xC1, 0xFF),
    gsSPVertex(D_04001C50_DF210, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 5, 3, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 7, 5, 0),
    gsSP2Triangles(7, 6, 8, 0, 8, 9, 7, 0),
    gsSP2Triangles(3, 10, 1, 0, 11, 1, 10, 0),
    gsSP2Triangles(1, 11, 0, 0, 10, 3, 12, 0),
    gsSP2Triangles(5, 12, 3, 0, 12, 13, 10, 0),
    gsSP2Triangles(10, 13, 11, 0, 12, 5, 14, 0),
    gsSP2Triangles(7, 14, 5, 0, 14, 13, 12, 0),
    gsSP2Triangles(9, 15, 7, 0, 14, 7, 15, 0),
    gsSP2Triangles(15, 13, 14, 0, 15, 9, 16, 0),
    gsSP2Triangles(16, 13, 15, 0, 4, 2, 17, 0),
    gsSP2Triangles(8, 6, 17, 0, 6, 4, 17, 0),
    gsSPEndDisplayList(),
};
