#include <ultra64.h>

Vtx D_01016200_4FAD0[30] = {
#include "data/inc/D_01016200_4FAD0.inc.c"
};
Vtx D_010163E0_4FCB0[31] = {
#include "data/inc/D_010163E0_4FCB0.inc.c"
};
Vtx D_010165D0_4FEA0[5] = {
#include "data/inc/D_010165D0_4FEA0.inc.c"
};
Vtx D_01016620_4FEF0[30] = {
#include "data/inc/D_01016620_4FEF0.inc.c"
};
Vtx D_01016800_500D0[8] = {
#include "data/inc/D_01016800_500D0.inc.c"
};
Vtx D_01016880_50150[30] = {
#include "data/inc/D_01016880_50150.inc.c"
};
Vtx D_01016A60_50330[21] = {
#include "data/inc/D_01016A60_50330.inc.c"
};
Vtx D_01016BB0_50480[16] = {
#include "data/inc/D_01016BB0_50480.inc.c"
};
Vtx D_01016CB0_50580[4] = {
#include "data/inc/D_01016CB0_50580.inc.c"
};
Vtx D_01016CF0_505C0[16] = {
#include "data/inc/D_01016CF0_505C0.inc.c"
};
Vtx D_01016DF0_506C0[10] = {
#include "data/inc/D_01016DF0_506C0.inc.c"
};

Gfx D_01016E90_50760[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xE7, 0xB4, 0xA4, 0xFF),
    gsSPVertex(D_01016200_4FAD0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 0, 3, 0, 2, 4, 5, 0),
    gsSP2Triangles(0, 5, 4, 0, 6, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 7, 6, 9, 0),
    gsSP2Triangles(8, 10, 11, 0, 6, 11, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(1, 0, 3, 0, 2, 4, 5, 0),
    gsSP2Triangles(0, 5, 4, 0, 6, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 7, 6, 9, 0),
    gsSP2Triangles(8, 10, 11, 0, 6, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 13, 12, 15, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 12, 14, 0),
    gsSP2Triangles(12, 18, 19, 0, 19, 16, 15, 0),
    gsSP2Triangles(20, 18, 14, 0, 18, 20, 21, 0),
    gsSP2Triangles(21, 16, 19, 0, 22, 20, 14, 0),
    gsSP2Triangles(20, 22, 23, 0, 23, 16, 21, 0),
    gsSP2Triangles(24, 22, 14, 0, 22, 24, 25, 0),
    gsSP2Triangles(25, 16, 23, 0, 13, 24, 14, 0),
    gsSP2Triangles(24, 13, 17, 0, 17, 16, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
    gsSP1Triangle(26, 28, 29, 0),
    gsSPVertex(D_010163E0_4FCB0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 3, 5, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 10, 14, 0, 13, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 16, 20, 0),
    gsSP2Triangles(19, 21, 18, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 10, 14, 0, 13, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 16, 20, 0),
    gsSP2Triangles(19, 21, 18, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 22, 26, 0, 27, 25, 28, 0),
    gsSP1Triangle(29, 27, 30, 0),
    gsSPVertex(D_010165D0_4FEA0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xF3, 0xFF, 0xEC, 0xFF),
    gsSPVertex(D_01016620_4FEF0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 7, 0, 4, 3, 7, 0),
    gsSP2Triangles(6, 5, 2, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 13, 0),
    gsSP2Triangles(15, 14, 10, 0, 16, 8, 13, 0),
    gsSP2Triangles(17, 18, 19, 0, 18, 20, 19, 0),
    gsSP2Triangles(20, 21, 19, 0, 21, 22, 19, 0),
    gsSP2Triangles(22, 17, 19, 0, 17, 22, 23, 0),
    gsSP2Triangles(22, 21, 24, 0, 21, 20, 25, 0),
    gsSP2Triangles(20, 18, 26, 0, 18, 17, 27, 0),
    gsSP2Triangles(27, 23, 28, 0, 23, 24, 28, 0),
    gsSP2Triangles(24, 25, 28, 0, 25, 26, 28, 0),
    gsSP2Triangles(26, 27, 28, 0, 2, 4, 0, 0),
    gsSP2Triangles(2, 5, 3, 0, 7, 3, 5, 0),
    gsSP2Triangles(7, 0, 4, 0, 2, 1, 6, 0),
    gsSP2Triangles(10, 14, 8, 0, 13, 15, 11, 0),
    gsSP2Triangles(13, 8, 14, 0, 10, 11, 15, 0),
    gsSP2Triangles(9, 29, 12, 0, 29, 8, 16, 0),
    gsSP2Triangles(16, 12, 29, 0, 23, 27, 17, 0),
    gsSP2Triangles(24, 23, 22, 0, 25, 24, 21, 0),
    gsSP2Triangles(26, 25, 20, 0, 27, 26, 18, 0),
    gsSPVertex(D_01016800_500D0, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x03, 0x03, 0x03, 0xFF),
    gsSPVertex(D_01016880_50150, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 5, 2, 0, 6, 7, 2, 0),
    gsSP2Triangles(7, 6, 3, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 12, 11, 10, 0),
    gsSP2Triangles(14, 15, 10, 0, 9, 8, 13, 0),
    gsSP2Triangles(2, 7, 0, 0, 3, 4, 1, 0),
    gsSP2Triangles(2, 1, 4, 0, 2, 5, 6, 0),
    gsSP2Triangles(3, 0, 7, 0, 10, 15, 8, 0),
    gsSP2Triangles(13, 14, 11, 0, 10, 9, 12, 0),
    gsSP2Triangles(10, 11, 14, 0, 13, 12, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSPVertex(D_01016A60_50330, 21, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(4, 3, 8, 9, 0),
    gsSP1Quadrangle(10, 11, 11, 12, 0),
    gsSP1Quadrangle(13, 14, 10, 15, 0),
    gsSP1Quadrangle(16, 11, 17, 18, 0),
    gsSP1Quadrangle(13, 18, 19, 20, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8B, 0x00, 0xFF),
    gsSPVertex(D_01016BB0_50480, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 0, 2, 0, 4, 3, 0, 0),
    gsSP2Triangles(1, 4, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 5, 8, 6, 0),
    gsSP2Triangles(9, 5, 7, 0, 9, 8, 5, 0),
    gsSP2Triangles(6, 9, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xCF, 0x4F, 0x46, 0xFF),
    gsSPVertex(D_01016CB0_50580, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP1Triangle(3, 0, 2, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x71, 0x35, 0x00, 0xFF),
    gsSPVertex(D_01016CF0_505C0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 3, 2, 0, 1, 0, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsSP2Triangles(9, 8, 13, 0, 14, 15, 13, 0),
    gsSP2Triangles(2, 3, 0, 0, 5, 0, 3, 0),
    gsSP2Triangles(2, 6, 4, 0, 5, 7, 1, 0),
    gsSP2Triangles(5, 4, 6, 0, 10, 12, 8, 0),
    gsSP2Triangles(10, 14, 11, 0, 13, 8, 12, 0),
    gsSP2Triangles(13, 15, 9, 0, 13, 11, 14, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xB5, 0x33, 0xFF, 0xFF),
    gsSPVertex(D_01016DF0_506C0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 0, 0),
    gsSPEndDisplayList(),
};
