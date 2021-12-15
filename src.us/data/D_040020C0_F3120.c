#include <ultra64.h>

Vtx D_04001C40_F2CA0[16] = {
#include "data/inc/D_04001C40_F2CA0.inc.c"
};
Vtx D_04001D40_F2DA0[8] = {
#include "data/inc/D_04001D40_F2DA0.inc.c"
};
Vtx D_04001DC0_F2E20[16] = {
#include "data/inc/D_04001DC0_F2E20.inc.c"
};
Vtx D_04001EC0_F2F20[8] = {
#include "data/inc/D_04001EC0_F2F20.inc.c"
};
Vtx D_04001F40_F2FA0[16] = {
#include "data/inc/D_04001F40_F2FA0.inc.c"
};
Vtx D_04002040_F30A0[8] = {
#include "data/inc/D_04002040_F30A0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_040020C0_F3120[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04001C40_F2CA0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSPVertex(D_04001D40_F2DA0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSPVertex(D_04001DC0_F2E20, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSPVertex(D_04001EC0_F2F20, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSPVertex(D_04001F40_F2FA0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSPVertex(D_04002040_F30A0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSPEndDisplayList(),
};
