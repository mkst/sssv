#include <ultra64.h>


Vtx D_0100BE50_45720[15] = {
#include "data/inc/D_0100BE50_45720.inc.c"
};
Vtx D_0100BF40_45810[14] = {
#include "data/inc/D_0100BF40_45810.inc.c"
};
Vtx D_0100C020_458F0[12] = {
#include "data/inc/D_0100C020_458F0.inc.c"
};
Vtx D_0100C0E0_459B0[4] = {
#include "data/inc/D_0100C0E0_459B0.inc.c"
};


Gfx D_0100C120_459F0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x0A, 0x0A, 0x7D, 0xFF),
    gsSPVertex(D_0100BE50_45720, 15, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 3, 2, 0, 1, 5, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 0, 3, 0),
    gsSP2Triangles(5, 3, 4, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 10, 9, 12, 0),
    gsSP2Triangles(12, 13, 10, 0, 10, 13, 11, 0),
    gsSP2Triangles(8, 7, 14, 0, 14, 7, 6, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0100BF40_45810, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(2, 3, 0, 0, 1, 3, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 5, 7, 6, 0),
    gsSP2Triangles(7, 5, 4, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x91, 0x09, 0x05, 0xFF),
    gsSPVertex(D_0100C020_458F0, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(1, 5, 6, 0, 2, 6, 7, 0),
    gsSP2Triangles(8, 4, 7, 0, 1, 8, 9, 0),
    gsSP2Triangles(5, 9, 7, 0, 10, 3, 4, 0),
    gsSP2Triangles(0, 2, 4, 0, 0, 11, 1, 0),
    gsSP2Triangles(10, 8, 1, 0, 1, 9, 5, 0),
    gsSP2Triangles(4, 2, 7, 0, 2, 1, 6, 0),
    gsSP2Triangles(6, 5, 7, 0, 8, 7, 9, 0),
    gsSP2Triangles(10, 4, 8, 0, 11, 10, 1, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0x80),
    gsDPSetRenderMode(G_AC_DITHER | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | GBL_c1(G_BL_CLR_FOG, G_BL_0, G_BL_CLR_IN, G_BL_1), G_AC_DITHER | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_PASS2, G_CC_PRIMITIVE),
    gsSPVertex(D_0100C0E0_459B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsDPPipeSync(),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};
