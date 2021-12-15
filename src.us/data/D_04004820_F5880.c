#include <ultra64.h>

Vtx D_040045A0_F5600[5] = {
#include "data/inc/D_040045A0_F5600.inc.c"
};
Vtx D_040045F0_F5650[19] = {
#include "data/inc/D_040045F0_F5650.inc.c"
};
Vtx D_04004720_F5780[5] = {
#include "data/inc/D_04004720_F5780.inc.c"
};
Vtx D_04004770_F57D0[5] = {
#include "data/inc/D_04004770_F57D0.inc.c"
};
Vtx D_040047C0_F5820[6] = {
#include "data/inc/D_040047C0_F5820.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

Gfx D_04004820_F5880[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xE6, 0x87, 0xB0, 0xFF),
    gsSPVertex(D_040045A0_F5600, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
    gsSPVertex(D_04004770_F57D0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x6E, 0x00, 0x7E, 0xFF),
    gsSPVertex(D_040045F0_F5650, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 2, 5, 0),
    gsSP2Triangles(2, 3, 5, 0, 6, 0, 4, 0),
    gsSP2Triangles(0, 6, 7, 0, 8, 7, 6, 0),
    gsSP2Triangles(6, 9, 8, 0, 10, 8, 9, 0),
    gsSP2Triangles(10, 11, 8, 0, 8, 11, 7, 0),
    gsSP1Quadrangle(12, 11, 10, 13, 0),
    gsSP2Triangles(9, 13, 10, 0, 13, 14, 12, 0),
    gsSP2Triangles(1, 14, 3, 0, 15, 3, 14, 0),
    gsSP2Triangles(3, 15, 5, 0, 14, 13, 15, 0),
    gsSP2Triangles(16, 12, 14, 0, 14, 1, 16, 0),
    gsSP2Triangles(16, 11, 12, 0, 13, 9, 17, 0),
    gsSP2Triangles(15, 17, 5, 0, 17, 15, 13, 0),
    gsSP2Triangles(17, 9, 6, 0, 18, 16, 1, 0),
    gsSP2Triangles(1, 0, 18, 0, 7, 11, 18, 0),
    gsSP2Triangles(18, 11, 16, 0, 7, 18, 0, 0),
    gsDPSetPrimColor(0, 0, 0xE6, 0x87, 0xB0, 0xFF),
    gsSPVertex(D_04004720_F5780, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(3, 1, 4, 0, 1, 0, 4, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040047C0_F5820, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
