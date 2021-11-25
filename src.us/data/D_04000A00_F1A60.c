#include <ultra64.h>

Vtx D_04000640_F16A0[17] = {
#include "data/inc/D_04000640_F16A0.inc.c"
};
Vtx D_04000750_F17B0[19] = {
#include "data/inc/D_04000750_F17B0.inc.c"
};
Vtx D_04000880_F18E0[4] = {
#include "data/inc/D_04000880_F18E0.inc.c"
};
Vtx D_040008C0_F1920[8] = {
#include "data/inc/D_040008C0_F1920.inc.c"
};
Vtx D_04000940_F19A0[6] = {
#include "data/inc/D_04000940_F19A0.inc.c"
};
Vtx D_040009A0_F1A00[6] = {
#include "data/inc/D_040009A0_F1A00.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_04000A00_F1A60[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xAA, 0x64, 0x1C, 0xFF),
    gsSPVertex(D_04000640_F16A0, 17, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 2, 3, 0, 5, 3, 1, 0),
    gsSP2Triangles(5, 1, 6, 0, 7, 6, 1, 0),
    gsSP2Triangles(8, 3, 5, 0, 6, 7, 9, 0),
    gsSP2Triangles(7, 10, 9, 0, 1, 10, 7, 0),
    gsSP2Triangles(1, 0, 10, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 5, 6, 0, 12, 5, 11, 0),
    gsSP2Triangles(12, 11, 13, 0, 11, 10, 13, 0),
    gsSP1Quadrangle(13, 8, 5, 12, 0),
    gsSP2Triangles(6, 9, 14, 0, 14, 9, 11, 0),
    gsSP2Triangles(14, 11, 6, 0, 0, 15, 10, 0),
    gsSP2Triangles(2, 15, 0, 0, 2, 4, 15, 0),
    gsSP2Triangles(4, 16, 15, 0, 3, 16, 4, 0),
    gsSP2Triangles(13, 10, 16, 0, 15, 16, 10, 0),
    gsSP2Triangles(8, 13, 16, 0, 3, 8, 16, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xDA, 0x1C, 0xFF),
    gsSPVertex(D_04000750_F17B0, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 2, 5, 3, 0),
    gsSP1Quadrangle(6, 5, 2, 1, 0),
    gsSP2Triangles(1, 7, 6, 0, 8, 5, 6, 0),
    gsSP2Triangles(8, 6, 7, 0, 7, 9, 8, 0),
    gsSP1Quadrangle(3, 5, 10, 4, 0),
    gsSP2Triangles(11, 5, 8, 0, 10, 5, 11, 0),
    gsSP2Triangles(11, 8, 9, 0, 9, 12, 11, 0),
    gsSP2Triangles(12, 4, 10, 0, 10, 11, 12, 0),
    gsSP2Triangles(4, 12, 13, 0, 12, 9, 14, 0),
    gsSP2Triangles(14, 13, 12, 0, 17, 14, 9, 0),
    gsSP2Triangles(13, 16, 4, 0, 9, 7, 17, 0),
    gsSP2Triangles(16, 18, 0, 0, 0, 4, 16, 0),
    gsDPSetPrimColor(0, 0, 0xDC, 0xDC, 0x96, 0xFF),
    gsSP2Triangles(17, 15, 14, 0, 14, 15, 13, 0),
    gsSP2Triangles(13, 15, 16, 0, 16, 15, 18, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000880_F18E0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xDA, 0x1C, 0xFF),
    gsSPVertex(D_040008C0_F1920, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04000940_F19A0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040009A0_F1A00, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 2, 0),
    gsSP1Quadrangle(4, 1, 3, 5, 0),
    gsSPEndDisplayList(),
};
