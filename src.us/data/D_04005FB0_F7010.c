#include <ultra64.h>

Vtx D_04005D50_F6DB0[12] = {
#include "data/inc/D_04005D50_F6DB0.inc.c"
};
Vtx D_04005E10_F6E70[10] = {
#include "data/inc/D_04005E10_F6E70.inc.c"
};
Vtx D_04005EB0_F6F10[12] = {
#include "data/inc/D_04005EB0_F6F10.inc.c"
};
Vtx D_04005F70_F6FD0[4] = {
#include "data/inc/D_04005F70_F6FD0.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003508_3CDD8[];

Gfx D_04005FB0_F7010[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x5A, 0x52, 0x52, 0xFF),
    gsSPVertex(D_04005D50_F6DB0, 12, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSP1Quadrangle(5, 4, 6, 7, 0),
    gsSP1Quadrangle(7, 6, 8, 9, 0),
    gsSP1Quadrangle(9, 8, 10, 11, 0),
    gsSPVertex(D_04005EB0_F6F10, 12, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSP1Quadrangle(5, 4, 6, 7, 0),
    gsSP1Quadrangle(7, 6, 8, 9, 0),
    gsSP1Quadrangle(9, 8, 10, 11, 0),
    gsSPDisplayList(D_01003508_3CDD8),
    gsSPTexture(0x8000, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_04005E10_F6E70, 10, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(8, 6, 7, 9, 0),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04005F70_F6FD0, 4, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSPEndDisplayList(),
};
