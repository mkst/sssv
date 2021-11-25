#include <ultra64.h>

Vtx D_04002EC0_E0480[8] = {
#include "data/inc/D_04002EC0_E0480.inc.c"
};
Vtx D_04002F40_E0500[8] = {
#include "data/inc/D_04002F40_E0500.inc.c"
};
Vtx D_04002FC0_E0580[30] = {
#include "data/inc/D_04002FC0_E0580.inc.c"
};
Vtx D_040031A0_E0760[11] = {
#include "data/inc/D_040031A0_E0760.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

const Gfx D_04003250_E0810[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xC0, 0x7B, 0x4D, 0xFF),
    gsSPVertex(D_04002EC0_E0480, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 2, 7, 0),
    gsSP1Triangle(7, 2, 0, 0),
    gsSPVertex(D_04002F40_E0500, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 2, 7, 0),
    gsSP1Triangle(7, 2, 0, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_04002FC0_E0580, 30, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(0, 3, 4, 0, 1, 5, 3, 0),
    gsSP2Triangles(6, 1, 2, 0, 1, 6, 7, 0),
    gsSP2Triangles(5, 1, 7, 0, 7, 8, 5, 0),
    gsSP2Triangles(8, 7, 9, 0, 7, 10, 9, 0),
    gsSP2Triangles(10, 7, 6, 0, 8, 11, 5, 0),
    gsSP2Triangles(3, 11, 4, 0, 5, 11, 3, 0),
    gsSP2Triangles(12, 11, 8, 0, 9, 12, 8, 0),
    gsSP2Triangles(12, 9, 13, 0, 14, 11, 12, 0),
    gsSP2Triangles(13, 14, 12, 0, 14, 13, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 15, 17, 16, 0),
    gsSP2Triangles(18, 11, 14, 0, 16, 18, 14, 0),
    gsSP2Triangles(18, 16, 19, 0, 16, 20, 19, 0),
    gsSP2Triangles(20, 16, 17, 0, 19, 21, 18, 0),
    gsSP2Triangles(21, 11, 18, 0, 22, 19, 20, 0),
    gsSP2Triangles(19, 22, 23, 0, 21, 19, 23, 0),
    gsSP2Triangles(23, 24, 21, 0, 24, 11, 21, 0),
    gsSP2Triangles(4, 11, 24, 0, 25, 4, 24, 0),
    gsSP2Triangles(4, 25, 0, 0, 24, 23, 25, 0),
    gsSP2Triangles(23, 26, 25, 0, 26, 23, 22, 0),
    gsSP2Triangles(25, 27, 0, 0, 2, 0, 27, 0),
    gsSP2Triangles(27, 25, 26, 0, 17, 15, 28, 0),
    gsSP2Triangles(13, 28, 15, 0, 28, 13, 29, 0),
    gsSP2Triangles(29, 9, 10, 0, 9, 29, 13, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_040031A0_E0760, 11, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 2, 0, 0, 3, 2, 5, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 2, 7, 0),
    gsSP2Triangles(7, 2, 8, 0, 8, 2, 9, 0),
    gsSP2Triangles(9, 2, 10, 0, 10, 2, 4, 0),
    gsSPEndDisplayList(),
};
