#include <ultra64.h>

Vtx D_040021A0_F3200[16] = {
#include "data/inc/D_040021A0_F3200.inc.c"
};
Vtx D_040022A0_F3300[16] = {
#include "data/inc/D_040022A0_F3300.inc.c"
};
Vtx D_040023A0_F3400[16] = {
#include "data/inc/D_040023A0_F3400.inc.c"
};
Vtx D_040024A0_F3500[12] = {
#include "data/inc/D_040024A0_F3500.inc.c"
};
Vtx D_04002560_F35C0[3] = {
#include "data/inc/D_04002560_F35C0.inc.c"
};
Vtx D_04002590_F35F0[8] = {
#include "data/inc/D_04002590_F35F0.inc.c"
};
Vtx D_04002610_F3670[3] = {
#include "data/inc/D_04002610_F3670.inc.c"
};
Vtx D_04002640_F36A0[3] = {
#include "data/inc/D_04002640_F36A0.inc.c"
};
Vtx D_04002670_F36D0[3] = {
#include "data/inc/D_04002670_F36D0.inc.c"
};
Vtx D_040026A0_F3700[8] = {
#include "data/inc/D_040026A0_F3700.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_04002720_F3780[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_040021A0_F3200, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(0, 3, 4, 0, 3, 2, 5, 0),
    gsSP2Triangles(4, 6, 0, 0, 6, 4, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
    gsSP2Triangles(7, 10, 9, 0, 10, 7, 11, 0),
    gsSP2Triangles(11, 7, 4, 0, 4, 12, 11, 0),
    gsSP2Triangles(12, 4, 3, 0, 3, 13, 12, 0),
    gsSP2Triangles(5, 13, 3, 0, 11, 14, 10, 0),
    gsSP2Triangles(14, 11, 15, 0, 15, 11, 12, 0),
    gsSPVertex(D_040022A0_F3300, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(2, 1, 4, 0, 4, 5, 2, 0),
    gsSP2Triangles(6, 4, 1, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 9, 4, 0),
    gsSP2Triangles(5, 4, 9, 0, 9, 10, 5, 0),
    gsSP2Triangles(6, 11, 8, 0, 12, 8, 11, 0),
    gsSP2Triangles(11, 6, 13, 0, 1, 13, 6, 0),
    gsSP2Triangles(14, 13, 1, 0, 1, 0, 14, 0),
    gsSP1Triangle(15, 8, 12, 0),
    gsSPVertex(D_040023A0_F3400, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(3, 2, 4, 0, 5, 2, 1, 0),
    gsSP2Triangles(1, 6, 5, 0, 2, 5, 7, 0),
    gsSP2Triangles(7, 4, 2, 0, 8, 4, 7, 0),
    gsSP2Triangles(4, 8, 9, 0, 10, 6, 1, 0),
    gsSP2Triangles(1, 11, 10, 0, 6, 10, 12, 0),
    gsSP2Triangles(7, 13, 8, 0, 13, 7, 14, 0),
    gsSP2Triangles(14, 7, 5, 0, 5, 15, 14, 0),
    gsSP1Triangle(15, 5, 6, 0),
    gsSPVertex(D_040024A0_F3500, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(2, 1, 4, 0, 2, 5, 0, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
    gsSP2Triangles(9, 8, 10, 0, 10, 11, 9, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x7D, 0x33, 0xFF, 0xFF),
    gsSPVertex(D_04002560_F35C0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04002590_F35F0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(0, 2, 4, 0, 2, 3, 4, 0),
    gsSP1Triangle(5, 6, 7, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04002610_F3670, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04002640_F36A0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04002670_F36D0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040026A0_F3700, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSPEndDisplayList(),
};
