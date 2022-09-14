#include <ultra64.h>

Vtx D_040029D0_CA400[32] = {
#include "data/inc/D_040029D0_CA400.inc.c"
};
Vtx D_04002BD0_CA600[20] = {
#include "data/inc/D_04002BD0_CA600.inc.c"
};
Vtx D_04002D10_CA740[8] = {
#include "data/inc/D_04002D10_CA740.inc.c"
};
extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04002D90_CA7C0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040029D0_CA400, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 2, 5, 0),
    gsSP2Triangles(6, 0, 4, 0, 3, 0, 6, 0),
    gsSP2Triangles(5, 7, 4, 0, 7, 5, 8, 0),
    gsSP2Triangles(9, 4, 7, 0, 4, 9, 6, 0),
    gsSP2Triangles(10, 6, 9, 0, 3, 6, 10, 0),
    gsSP2Triangles(8, 11, 7, 0, 12, 11, 8, 0),
    gsSP2Triangles(12, 8, 13, 0, 13, 8, 5, 0),
    gsSP2Triangles(5, 14, 13, 0, 14, 5, 2, 0),
    gsSP2Triangles(2, 15, 14, 0, 15, 2, 1, 0),
    gsSP2Triangles(1, 16, 15, 0, 3, 16, 1, 0),
    gsSP2Triangles(12, 13, 17, 0, 17, 13, 14, 0),
    gsSP2Triangles(14, 18, 17, 0, 18, 14, 15, 0),
    gsSP2Triangles(15, 19, 18, 0, 19, 15, 16, 0),
    gsSP2Triangles(16, 20, 19, 0, 3, 20, 16, 0),
    gsSP2Triangles(12, 17, 21, 0, 21, 17, 18, 0),
    gsSP2Triangles(18, 22, 21, 0, 22, 18, 19, 0),
    gsSP2Triangles(19, 23, 22, 0, 23, 19, 20, 0),
    gsSP2Triangles(20, 24, 23, 0, 3, 24, 20, 0),
    gsSP2Triangles(12, 21, 25, 0, 25, 21, 22, 0),
    gsSP2Triangles(22, 26, 25, 0, 26, 22, 23, 0),
    gsSP2Triangles(23, 27, 26, 0, 27, 23, 24, 0),
    gsSP2Triangles(24, 28, 27, 0, 3, 28, 24, 0),
    gsSP2Triangles(12, 25, 29, 0, 29, 25, 26, 0),
    gsSP2Triangles(26, 30, 29, 0, 30, 26, 27, 0),
    gsSP2Triangles(27, 31, 30, 0, 31, 27, 28, 0),
    gsSPVertex(D_04002BD0_CA600, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(3, 4, 1, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 2, 5, 6, 0),
    gsSP2Triangles(6, 7, 2, 0, 7, 6, 8, 0),
    gsSP2Triangles(8, 9, 7, 0, 10, 9, 8, 0),
    gsSP2Triangles(10, 8, 11, 0, 11, 8, 6, 0),
    gsSP2Triangles(6, 12, 11, 0, 12, 6, 5, 0),
    gsSP2Triangles(5, 13, 12, 0, 13, 5, 4, 0),
    gsSP2Triangles(4, 14, 13, 0, 3, 14, 4, 0),
    gsSP2Triangles(10, 11, 15, 0, 15, 11, 12, 0),
    gsSP2Triangles(12, 16, 15, 0, 16, 12, 13, 0),
    gsSP2Triangles(13, 17, 16, 0, 17, 13, 14, 0),
    gsSP2Triangles(10, 15, 18, 0, 18, 15, 16, 0),
    gsSP2Triangles(16, 19, 18, 0, 19, 16, 17, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04002D10_CA740, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 1, 5, 4, 0),
    gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
    gsSPEndDisplayList(),
};

Vtx D_04002F28_CA958[32] = {
#include "data/inc/D_04002F28_CA958.inc.c"
};
Vtx D_04003128_CAB58[20] = {
#include "data/inc/D_04003128_CAB58.inc.c"
};
Vtx D_04003268_CAC98[8] = {
#include "data/inc/D_04003268_CAC98.inc.c"
};

Gfx D_040032E8_CAD18[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04002F28_CA958, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 2, 5, 0),
    gsSP2Triangles(6, 0, 4, 0, 3, 0, 6, 0),
    gsSP2Triangles(5, 7, 4, 0, 7, 5, 8, 0),
    gsSP2Triangles(9, 4, 7, 0, 4, 9, 6, 0),
    gsSP2Triangles(10, 6, 9, 0, 3, 6, 10, 0),
    gsSP2Triangles(8, 11, 7, 0, 12, 11, 8, 0),
    gsSP2Triangles(12, 8, 13, 0, 13, 8, 5, 0),
    gsSP2Triangles(5, 14, 13, 0, 14, 5, 2, 0),
    gsSP2Triangles(2, 15, 14, 0, 15, 2, 1, 0),
    gsSP2Triangles(1, 16, 15, 0, 3, 16, 1, 0),
    gsSP2Triangles(12, 13, 17, 0, 17, 13, 14, 0),
    gsSP2Triangles(14, 18, 17, 0, 18, 14, 15, 0),
    gsSP2Triangles(15, 19, 18, 0, 19, 15, 16, 0),
    gsSP2Triangles(16, 20, 19, 0, 3, 20, 16, 0),
    gsSP2Triangles(12, 17, 21, 0, 21, 17, 18, 0),
    gsSP2Triangles(18, 22, 21, 0, 22, 18, 19, 0),
    gsSP2Triangles(19, 23, 22, 0, 23, 19, 20, 0),
    gsSP2Triangles(20, 24, 23, 0, 3, 24, 20, 0),
    gsSP2Triangles(12, 21, 25, 0, 25, 21, 22, 0),
    gsSP2Triangles(22, 26, 25, 0, 26, 22, 23, 0),
    gsSP2Triangles(23, 27, 26, 0, 27, 23, 24, 0),
    gsSP2Triangles(24, 28, 27, 0, 3, 28, 24, 0),
    gsSP2Triangles(12, 25, 29, 0, 29, 25, 26, 0),
    gsSP2Triangles(26, 30, 29, 0, 30, 26, 27, 0),
    gsSP2Triangles(27, 31, 30, 0, 31, 27, 28, 0),
    gsSPVertex(D_04003128_CAB58, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(3, 4, 1, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 2, 5, 6, 0),
    gsSP2Triangles(6, 7, 2, 0, 7, 6, 8, 0),
    gsSP2Triangles(8, 9, 7, 0, 10, 9, 8, 0),
    gsSP2Triangles(10, 8, 11, 0, 11, 8, 6, 0),
    gsSP2Triangles(6, 12, 11, 0, 12, 6, 5, 0),
    gsSP2Triangles(5, 13, 12, 0, 13, 5, 4, 0),
    gsSP2Triangles(4, 14, 13, 0, 3, 14, 4, 0),
    gsSP2Triangles(10, 11, 15, 0, 15, 11, 12, 0),
    gsSP2Triangles(12, 16, 15, 0, 16, 12, 13, 0),
    gsSP2Triangles(13, 17, 16, 0, 17, 13, 14, 0),
    gsSP2Triangles(10, 15, 18, 0, 18, 15, 16, 0),
    gsSP2Triangles(16, 19, 18, 0, 19, 16, 17, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04003268_CAC98, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 1, 5, 4, 0),
    gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
    gsSPEndDisplayList(),
};
