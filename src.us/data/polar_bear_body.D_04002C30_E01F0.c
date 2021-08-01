#include <ultra64.h>

Vtx D_04002630_DFBF0[32] = {
#include "data/inc/D_04002630_DFBF0.inc.c"
};
Vtx D_04002830_DFDF0[16] = {
#include "data/inc/D_04002830_DFDF0.inc.c"
};
Vtx D_04002930_DFEF0[32] = {
#include "data/inc/D_04002930_DFEF0.inc.c"
};
Vtx D_04002B30_E00F0[16] = {
#include "data/inc/D_04002B30_E00F0.inc.c"
};

extern Gfx D_01003548_3CE18[];

const Gfx D_04002C30_E01F0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04002930_DFEF0, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 2, 0, 0, 5, 1, 3, 0),
    gsSP2Triangles(6, 2, 4, 0, 7, 2, 6, 0),
    gsSP2Triangles(8, 7, 6, 0, 9, 2, 7, 0),
    gsSP2Triangles(3, 2, 10, 0, 10, 2, 11, 0),
    gsSP2Triangles(11, 2, 9, 0, 12, 9, 7, 0),
    gsSP2Triangles(7, 8, 12, 0, 13, 4, 0, 0),
    gsSP2Triangles(14, 6, 4, 0, 4, 13, 14, 0),
    gsSP2Triangles(6, 14, 8, 0, 15, 0, 1, 0),
    gsSP2Triangles(0, 15, 13, 0, 1, 5, 15, 0),
    gsSP2Triangles(3, 16, 5, 0, 16, 3, 10, 0),
    gsSP2Triangles(17, 10, 11, 0, 10, 17, 16, 0),
    gsSP2Triangles(5, 18, 15, 0, 15, 19, 13, 0),
    gsSP2Triangles(19, 15, 18, 0, 20, 13, 19, 0),
    gsSP2Triangles(13, 20, 14, 0, 21, 14, 20, 0),
    gsSP2Triangles(14, 21, 8, 0, 22, 8, 21, 0),
    gsSP2Triangles(8, 22, 12, 0, 23, 12, 22, 0),
    gsSP2Triangles(24, 23, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(9, 12, 26, 0, 26, 11, 9, 0),
    gsSP2Triangles(12, 23, 26, 0, 11, 26, 17, 0),
    gsSP2Triangles(16, 27, 5, 0, 18, 5, 27, 0),
    gsSP2Triangles(17, 28, 16, 0, 27, 16, 28, 0),
    gsSP2Triangles(26, 29, 17, 0, 28, 17, 29, 0),
    gsSP2Triangles(29, 26, 23, 0, 25, 29, 23, 0),
    gsSP2Triangles(29, 25, 30, 0, 30, 28, 29, 0),
    gsSP2Triangles(24, 31, 25, 0, 25, 31, 30, 0),
    gsSPVertex(D_04002B30_E00F0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(1, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 1, 4, 0, 1, 6, 0, 0),
    gsSP2Triangles(7, 4, 5, 0, 4, 7, 6, 0),
    gsSP2Triangles(5, 3, 8, 0, 9, 3, 2, 0),
    gsSP2Triangles(10, 9, 2, 0, 2, 0, 10, 0),
    gsSP2Triangles(11, 5, 8, 0, 5, 11, 7, 0),
    gsSP2Triangles(12, 3, 9, 0, 13, 12, 9, 0),
    gsSP2Triangles(9, 10, 13, 0, 14, 3, 12, 0),
    gsSP2Triangles(15, 14, 12, 0, 12, 13, 15, 0),
    gsSPEndDisplayList(),
};

const Gfx D_04002D78_E0338[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04002630_DFBF0, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 2, 0, 0, 5, 1, 3, 0),
    gsSP2Triangles(6, 2, 4, 0, 7, 2, 6, 0),
    gsSP2Triangles(8, 7, 6, 0, 9, 2, 7, 0),
    gsSP2Triangles(3, 2, 10, 0, 10, 2, 11, 0),
    gsSP2Triangles(11, 2, 9, 0, 12, 9, 7, 0),
    gsSP2Triangles(7, 8, 12, 0, 13, 4, 0, 0),
    gsSP2Triangles(14, 6, 4, 0, 4, 13, 14, 0),
    gsSP2Triangles(6, 14, 8, 0, 15, 0, 1, 0),
    gsSP2Triangles(0, 15, 13, 0, 1, 5, 15, 0),
    gsSP2Triangles(3, 16, 5, 0, 16, 3, 10, 0),
    gsSP2Triangles(17, 10, 11, 0, 10, 17, 16, 0),
    gsSP2Triangles(5, 18, 15, 0, 15, 19, 13, 0),
    gsSP2Triangles(19, 15, 18, 0, 20, 13, 19, 0),
    gsSP2Triangles(13, 20, 14, 0, 21, 14, 20, 0),
    gsSP2Triangles(14, 21, 8, 0, 22, 8, 21, 0),
    gsSP2Triangles(8, 22, 12, 0, 23, 12, 22, 0),
    gsSP2Triangles(24, 23, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(9, 12, 26, 0, 26, 11, 9, 0),
    gsSP2Triangles(12, 23, 26, 0, 11, 26, 17, 0),
    gsSP2Triangles(16, 27, 5, 0, 18, 5, 27, 0),
    gsSP2Triangles(17, 28, 16, 0, 27, 16, 28, 0),
    gsSP2Triangles(26, 29, 17, 0, 28, 17, 29, 0),
    gsSP2Triangles(29, 26, 23, 0, 25, 29, 23, 0),
    gsSP2Triangles(29, 25, 30, 0, 30, 28, 29, 0),
    gsSP2Triangles(24, 31, 25, 0, 25, 31, 30, 0),
    gsSPVertex(D_04002830_DFDF0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(1, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 1, 4, 0, 1, 6, 0, 0),
    gsSP2Triangles(7, 4, 5, 0, 4, 7, 6, 0),
    gsSP2Triangles(5, 3, 8, 0, 9, 3, 2, 0),
    gsSP2Triangles(10, 9, 2, 0, 2, 0, 10, 0),
    gsSP2Triangles(11, 5, 8, 0, 5, 11, 7, 0),
    gsSP2Triangles(12, 3, 9, 0, 13, 12, 9, 0),
    gsSP2Triangles(9, 10, 13, 0, 14, 3, 12, 0),
    gsSP2Triangles(15, 14, 12, 0, 12, 13, 15, 0),
    gsSPEndDisplayList(),
};
