#include <ultra64.h>

Vtx D_01015520_4EDF0[31] = {
#include "data/inc/D_01015520_4EDF0.inc.c"
};
Vtx D_01015710_4EFE0[16] = {
#include "data/inc/D_01015710_4EFE0.inc.c"
};
Vtx D_01015810_4F0E0[16] = {
#include "data/inc/D_01015810_4F0E0.inc.c"
};
Vtx D_01015910_4F1E0[31] = {
#include "data/inc/D_01015910_4F1E0.inc.c"
};
Vtx D_01015B00_4F3D0[28] = {
#include "data/inc/D_01015B00_4F3D0.inc.c"
};
Vtx D_01015CC0_4F590[28] = {
#include "data/inc/D_01015CC0_4F590.inc.c"
};
Vtx D_01015E80_4F750[6] = {
#include "data/inc/D_01015E80_4F750.inc.c"
};

Gfx D_01015EE0_4F7B0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_01015520_4EDF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 0, 4, 0, 6, 1, 0, 0),
    gsSP2Triangles(3, 7, 6, 0, 2, 4, 0, 0),
    gsSP2Triangles(2, 7, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 6, 5, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 11, 12, 0),
    gsSP2Triangles(11, 10, 13, 0, 10, 9, 14, 0),
    gsSP2Triangles(14, 15, 12, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 15, 8, 0, 13, 12, 11, 0),
    gsSP2Triangles(14, 13, 10, 0, 12, 13, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 17, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 27, 30, 28, 0),
    gsSPVertex(D_01015710_4EFE0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 5, 7, 0, 6, 8, 7, 0),
    gsSP1Quadrangle(9, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 14, 12, 15, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x5D, 0x32, 0x14, 0xFF),
    gsSPVertex(D_01015810_4F0E0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 2, 6, 0),
    gsSP2Triangles(3, 0, 7, 0, 6, 2, 1, 0),
    gsSP2Triangles(2, 7, 0, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 5, 3, 0, 1, 4, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 14, 12, 0, 15, 10, 14, 0),
    gsSP2Triangles(11, 8, 15, 0, 14, 10, 9, 0),
    gsSP2Triangles(10, 15, 8, 0, 9, 8, 11, 0),
    gsSP2Triangles(12, 11, 13, 0, 14, 13, 15, 0),
    gsSP2Triangles(15, 13, 11, 0, 9, 12, 14, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFE, 0xFF, 0xFD, 0xFF),
    gsSPVertex(D_01015910_4F1E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 0, 4, 0, 6, 1, 0, 0),
    gsSP2Triangles(3, 7, 6, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 10, 0, 13, 8, 12, 0),
    gsSP2Triangles(14, 9, 8, 0, 11, 15, 14, 0),
    gsSP2Triangles(2, 4, 0, 0, 2, 7, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 0, 5, 6, 0),
    gsSP2Triangles(6, 5, 3, 0, 10, 12, 8, 0),
    gsSP2Triangles(10, 15, 11, 0, 12, 11, 13, 0),
    gsSP2Triangles(8, 13, 14, 0, 14, 13, 11, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 19, 20, 0),
    gsSP2Triangles(19, 18, 21, 0, 22, 17, 18, 0),
    gsSP2Triangles(22, 23, 20, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 24, 0, 29, 26, 28, 0),
    gsSP1Triangle(26, 25, 30, 0),
    gsSPVertex(D_01015B00_4F3D0, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 6, 4, 0),
    gsSP2Triangles(3, 8, 9, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 1, 2, 0),
    gsSP2Triangles(11, 2, 13, 0, 0, 13, 12, 0),
    gsSP2Triangles(2, 13, 0, 0, 14, 15, 16, 0),
    gsSP2Triangles(15, 14, 17, 0, 18, 17, 19, 0),
    gsSP2Triangles(20, 17, 14, 0, 21, 14, 22, 0),
    gsSP2Triangles(23, 22, 24, 0, 25, 24, 19, 0),
    gsSP2Triangles(26, 19, 17, 0, 24, 27, 18, 0),
    gsSP2Triangles(22, 16, 27, 0, 16, 22, 14, 0),
    gsSP2Triangles(14, 21, 20, 0, 22, 23, 21, 0),
    gsSP2Triangles(24, 25, 23, 0, 19, 26, 25, 0),
    gsSP2Triangles(17, 20, 26, 0, 18, 19, 24, 0),
    gsSP1Triangle(27, 24, 22, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xC0, 0x96, 0xFF),
    gsSPVertex(D_01015CC0_4F590, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 3, 2, 0, 4, 5, 6, 0),
    gsSP1Quadrangle(4, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 14, 12, 0, 15, 10, 14, 0),
    gsSP2Triangles(14, 10, 9, 0, 10, 15, 8, 0),
    gsSP2Triangles(9, 8, 11, 0, 12, 11, 13, 0),
    gsSP2Triangles(14, 13, 15, 0, 9, 12, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
    gsSP2Triangles(19, 20, 18, 0, 20, 21, 18, 0),
    gsSP2Triangles(21, 16, 18, 0, 16, 22, 23, 0),
    gsSP2Triangles(17, 23, 24, 0, 19, 24, 25, 0),
    gsSP2Triangles(20, 25, 26, 0, 21, 26, 22, 0),
    gsSP2Triangles(27, 23, 22, 0, 27, 24, 23, 0),
    gsSP2Triangles(27, 25, 24, 0, 27, 26, 25, 0),
    gsSP2Triangles(27, 22, 26, 0, 23, 17, 16, 0),
    gsSP2Triangles(24, 19, 17, 0, 25, 20, 19, 0),
    gsSP2Triangles(26, 21, 20, 0, 22, 16, 21, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x67, 0xA2, 0xFF, 0xFF),
    gsSPVertex(D_01015E80_4F750, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP1Triangle(5, 0, 2, 0),
    gsSPEndDisplayList(),
};
