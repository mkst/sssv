#include <ultra64.h>

Vtx D_040084C0_CFEF0[3] = {
#include "data/inc/D_040084C0_CFEF0.inc.c"
};
Vtx D_040084F0_CFF20[16] = {
#include "data/inc/D_040084F0_CFF20.inc.c"
};
Vtx D_040085F0_D0020[8] = {
#include "data/inc/D_040085F0_D0020.inc.c"
};
Vtx D_04008670_D00A0[3] = {
#include "data/inc/D_04008670_D00A0.inc.c"
};
Vtx D_040086A0_D00D0[16] = {
#include "data/inc/D_040086A0_D00D0.inc.c"
};
Vtx D_040087A0_D01D0[6] = {
#include "data/inc/D_040087A0_D01D0.inc.c"
};
Vtx D_04008800_D0230[10] = {
#include "data/inc/D_04008800_D0230.inc.c"
};
Vtx D_040088A0_D02D0[10] = {
#include "data/inc/D_040088A0_D02D0.inc.c"
};
Vtx D_04008940_D0370[14] = {
#include "data/inc/D_04008940_D0370.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04008A20_D0450[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040084C0_CFEF0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xB0, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_040084F0_CFF20, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(2, 6, 1, 0, 6, 2, 7, 0),
    gsSP2Triangles(4, 7, 2, 0, 7, 4, 8, 0),
    gsSP2Triangles(9, 1, 6, 0, 1, 10, 0, 0),
    gsSP2Triangles(10, 1, 11, 0, 1, 9, 11, 0),
    gsSP2Triangles(12, 11, 9, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 13, 12, 0, 15, 11, 13, 0),
    gsSP1Triangle(11, 15, 10, 0),
    gsSPVertex(D_040085F0_D0020, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 2, 0, 5, 0),
    gsSP2Triangles(6, 2, 5, 0, 2, 6, 4, 0),
    gsSP1Triangle(3, 4, 7, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04008670_D00A0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040086A0_D00D0, 16, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 6, 5, 7, 0),
    gsSP1Quadrangle(8, 10, 9, 11, 0),
    gsSP1Quadrangle(12, 14, 13, 15, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040087A0_D01D0, 6, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(2, 4, 1, 0, 2, 5, 4, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPVertex(D_04008800_D0230, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSPVertex(D_040088A0_D02D0, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xB0, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_04008940_D0370, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 1, 2, 0, 1, 10, 11, 0),
    gsSP2Triangles(12, 11, 10, 0, 11, 12, 13, 0),
    gsSPEndDisplayList(),
};
