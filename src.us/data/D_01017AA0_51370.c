#include <ultra64.h>

Vtx D_010176E0_50FB0[8] = {
#include "data/inc/D_010176E0_50FB0.inc.c"
};
Vtx D_01017760_51030[30] = {
#include "data/inc/D_01017760_51030.inc.c"
};
Vtx D_01017940_51210[14] = {
#include "data/inc/D_01017940_51210.inc.c"
};
Vtx D_01017A20_512F0[4] = {
    #include "data/inc/D_01017A20_512F0.inc.c"
};
Vtx D_01017A60_51330[4] = {
#include "data/inc/D_01017A60_51330.inc.c"
};

Gfx D_01017AA0_51370[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_010176E0_50FB0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_01017760_51030, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(6, 20, 21, 22, 0),
    gsSP1Quadrangle(23, 24, 25, 26, 0),
    gsSP1Quadrangle(27, 7, 28, 29, 0),
    gsSPVertex(D_01017940_51210, 14, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 1, 0),
    gsSP1Quadrangle(7, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 12, 0, 13, 0),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_PASS2, G_CC_PRIMITIVE),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x80),
    gsDPPipeSync(),
    gsSPVertex(D_01017A60_51330, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0x80),
    gsDPSetRenderMode(G_AC_DITHER | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | GBL_c1(G_BL_CLR_FOG, G_BL_0, G_BL_CLR_IN, G_BL_1), G_AC_DITHER | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_PASS2, G_CC_PRIMITIVE),
    gsDPPipeSync(),
    gsSPVertex(D_01017A20_512F0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsDPPipeSync(),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};
