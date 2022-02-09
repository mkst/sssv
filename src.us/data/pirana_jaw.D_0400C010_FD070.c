#include <ultra64.h>

Vtx D_0400BE10_FCE70[9] = {
#include "data/inc/D_0400BE10_FCE70.inc.c"
};
Vtx D_0400BEA0_FCF00[9] = {
#include "data/inc/D_0400BEA0_FCF00.inc.c"
};
Vtx D_0400BF30_FCF90[9] = {
#include "data/inc/D_0400BF30_FCF90.inc.c"
};
Vtx D_0400BFC0_FD020[5] = {
#include "data/inc/D_0400BFC0_FD020.inc.c"
};

extern Gfx D_01003508_3CDD8[];
extern Gfx D_01003548_3CE18[];

Gfx D_0400C010_FD070[] = {
    gsSPVertex(D_0400BE10_FCE70, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(2, 4, 3, 0, 4, 5, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 2, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 7, 6, 0),
    gsSP2Triangles(2, 8, 6, 0, 1, 8, 2, 0),
    gsSP1Triangle(8, 1, 7, 0),
    gsSPDisplayList(D_01003508_3CDD8),
    gsSPTexture(0xFFFF, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_0400BEA0_FCF00, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPVertex(D_0400BF30_FCF90, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xC8, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0400BFC0_FD020, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP1Triangle(2, 4, 0, 0),
    gsSPEndDisplayList(),
};
