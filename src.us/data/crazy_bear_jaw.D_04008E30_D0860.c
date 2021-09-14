#include <ultra64.h>

Vtx D_04008BF0_D0620[3] = {
#include "data/inc/D_04008BF0_D0620.inc.c"
};
Vtx D_04008C20_D0650[3] = {
#include "data/inc/D_04008C20_D0650.inc.c"
};
Vtx D_04008C50_D0680[4] = {
#include "data/inc/D_04008C50_D0680.inc.c"
};
Vtx D_04008C90_D06C0[14] = {
#include "data/inc/D_04008C90_D06C0.inc.c"
};
Vtx D_04008D70_D07A0[12] = {
#include "data/inc/D_04008D70_D07A0.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_04008E30_D0860[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04008BF0_D0620, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_04008C20_D0650, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04008C50_D0680, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPVertex(D_04008C90_D06C0, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04008D70_D07A0, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(0, 3, 4, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 6, 9, 0),
    gsSP2Triangles(10, 9, 6, 0, 9, 10, 11, 0),
    gsSPEndDisplayList(),
};
