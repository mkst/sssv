#include <ultra64.h>

Vtx D_04008F00_D0930[16] = {
#include "data/inc/D_04008F00_D0930.inc.c"
};
Vtx D_04009000_D0A30[16] = {
#include "data/inc/D_04009000_D0A30.inc.c"
};
Vtx D_04009100_D0B30[16] = {
#include "data/inc/D_04009100_D0B30.inc.c"
};
Vtx D_04009200_D0C30[12] = {
#include "data/inc/D_04009200_D0C30.inc.c"
};
Vtx D_040092C0_D0CF0[16] = {
#include "data/inc/D_040092C0_D0CF0.inc.c"
};
Vtx D_040093C0_D0DF0[16] = {
#include "data/inc/D_040093C0_D0DF0.inc.c"
};
Vtx D_040094C0_D0EF0[8] = {
#include "data/inc/D_040094C0_D0EF0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04009540_D0F70[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04008F00_D0930, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 11, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 13, 12, 0, 13, 14, 15, 0),
    gsSPVertex(D_04009000_D0A30, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 7, 4, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 11, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 13, 12, 0, 13, 14, 15, 0),
    gsSPVertex(D_04009100_D0B30, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 8, 11, 0),
    gsSP2Triangles(12, 9, 10, 0, 9, 12, 13, 0),
    gsSP2Triangles(14, 13, 12, 0, 13, 14, 15, 0),
    gsSPVertex(D_04009200_D0C30, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 1, 2, 0, 1, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 9, 10, 11, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040092C0_D0CF0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsSP2Triangles(13, 14, 12, 0, 14, 13, 15, 0),
    gsSPVertex(D_040093C0_D0DF0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsSP2Triangles(13, 14, 12, 0, 14, 13, 15, 0),
    gsSPVertex(D_040094C0_D0EF0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSPEndDisplayList(),
};
