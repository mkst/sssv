#include <ultra64.h>

Vtx D_04003A80_CB4B0[14] = {
#include "data/inc/D_04003A80_CB4B0.inc.c"
};
Vtx D_04003B60_CB590[6] = {
#include "data/inc/D_04003B60_CB590.inc.c"
};
Vtx D_04003BC0_CB5F0[31] = {
#include "data/inc/D_04003BC0_CB5F0.inc.c"
};
Vtx D_04003DB0_CB7E0[3] = {
#include "data/inc/D_04003DB0_CB7E0.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04003DE0_CB810[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x1E, 0x1E, 0x1E, 0xFF),
    gsSPVertex(D_04003A80_CB4B0, 14, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 5, 0),
    gsSP1Quadrangle(0, 5, 6, 2, 0),
    gsSP2Triangles(2, 7, 1, 0, 7, 2, 8, 0),
    gsSP2Triangles(6, 8, 2, 0, 9, 1, 7, 0),
    gsSP2Triangles(1, 9, 3, 0, 10, 3, 9, 0),
    gsSP2Triangles(3, 10, 4, 0, 11, 4, 10, 0),
    gsSP2Triangles(4, 11, 5, 0, 12, 5, 11, 0),
    gsSP2Triangles(8, 6, 12, 0, 5, 12, 6, 0),
    gsSP2Triangles(13, 7, 8, 0, 13, 9, 7, 0),
    gsSP2Triangles(13, 10, 9, 0, 13, 11, 10, 0),
    gsSP2Triangles(13, 12, 11, 0, 13, 8, 12, 0),
    gsSPVertex(D_04003B60_CB590, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04003BC0_CB5F0, 31, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 1, 2, 0, 1, 4, 5, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsSP2Triangles(14, 16, 15, 0, 16, 14, 17, 0),
    gsSP2Triangles(17, 18, 16, 0, 18, 17, 19, 0),
    gsSP2Triangles(19, 20, 18, 0, 20, 19, 21, 0),
    gsSP2Triangles(21, 22, 20, 0, 22, 21, 23, 0),
    gsSP2Triangles(23, 24, 22, 0, 24, 23, 25, 0),
    gsSP2Triangles(25, 26, 24, 0, 26, 25, 27, 0),
    gsSP1Triangle(28, 30, 29, 0),
    gsSPVertex(D_04003DB0_CB7E0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};
