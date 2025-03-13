#include <ultra64.h>

Vtx D_05006810_8FA70[8] = {
#include "data/inc/D_05006810_8FA70.inc.c"
};
Vtx D_05006890_8FAF0[7] = {
#include "data/inc/D_05006890_8FAF0.inc.c"
};
Vtx D_05006900_8FB60[31] = {
#include "data/inc/D_05006900_8FB60.inc.c"
};
Vtx D_05006AF0_8FD50[32] = {
#include "data/inc/D_05006AF0_8FD50.inc.c"
};
Vtx D_05006CF0_8FF50[32] = {
#include "data/inc/D_05006CF0_8FF50.inc.c"
};
Vtx D_05006EF0_90150[31] = {
#include "data/inc/D_05006EF0_90150.inc.c"
};
Vtx D_050070E0_90340[31] = {
#include "data/inc/D_050070E0_90340.inc.c"
};
Vtx D_050072D0_90530[30] = {
#include "data/inc/D_050072D0_90530.inc.c"
};
Vtx D_050074B0_90710[31] = {
#include "data/inc/D_050074B0_90710.inc.c"
};
Vtx D_050076A0_90900[21] = {
#include "data/inc/D_050076A0_90900.inc.c"
};
Vtx D_050077F0_90A50[30] = {
#include "data/inc/D_050077F0_90A50.inc.c"
};
Vtx D_050079D0_90C30[23] = {
#include "data/inc/D_050079D0_90C30.inc.c"
};
Vtx D_05007B40_90DA0[25] = {
#include "data/inc/D_05007B40_90DA0.inc.c"
};
Vtx D_05007CD0_90F30[31] = {
#include "data/inc/D_05007CD0_90F30.inc.c"
};
Vtx D_05007EC0_91120[31] = {
#include "data/inc/D_05007EC0_91120.inc.c"
};
Vtx D_050080B0_91310[31] = {
#include "data/inc/D_050080B0_91310.inc.c"
};
Vtx D_050082A0_91500[31] = {
#include "data/inc/D_050082A0_91500.inc.c"
};
Vtx D_05008490_916F0[31] = {
#include "data/inc/D_05008490_916F0.inc.c"
};
Vtx D_05008680_918E0[32] = {
#include "data/inc/D_05008680_918E0.inc.c"
};
Vtx D_05008880_91AE0[30] = {
#include "data/inc/D_05008880_91AE0.inc.c"
};
Vtx D_05008A60_91CC0[5] = {
#include "data/inc/D_05008A60_91CC0.inc.c"
};
Vtx D_05008AB0_91D10[8] = {
#include "data/inc/D_05008AB0_91D10.inc.c"
};
Vtx D_05008B30_91D90[20] = {
#include "data/inc/D_05008B30_91D90.inc.c"
};
Vtx D_05008C70_91ED0[8] = {
#include "data/inc/D_05008C70_91ED0.inc.c"
};
Vtx D_05008CF0_91F50[6] = {
#include "data/inc/D_05008CF0_91F50.inc.c"
};
extern u8 img_intro_spaceship_interior_0_16_rgba16__png[];
extern u8 img_intro_tigerprint_16_rgba16__png[];
extern u8 img_intro_tbd_D_05005E10_8F070_D_05005E10_8F070__rgba16__png[];
extern u8 img_intro_spaceship_interior_4_16_rgba16__png[];

Gfx D_05008D50_91FB0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x16, 0x0A, 0xFF, 0xFF),
    gsSPVertex(D_05006810_8FA70, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 0, 7, 5, 0),
    gsSP2Triangles(2, 7, 0, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 3, 0, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x07, 0x00, 0xFF),
    gsSPVertex(D_05006890_8FAF0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(1, 0, 5, 0, 2, 3, 0, 0),
    gsSP1Triangle(4, 6, 3, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, img_intro_spaceship_interior_0_16_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 512),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x003C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05006900_8FB60, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(10, 14, 8, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 10, 20, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP2Triangles(13, 22, 11, 0, 17, 26, 15, 0),
    gsSP2Triangles(27, 28, 29, 0, 29, 30, 27, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x96, 0xFF, 0xFF),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_05006AF0_8FD50, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 9, 10, 0),
    gsSP2Triangles(11, 3, 12, 0, 1, 6, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05006CF0_8FF50, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(10, 18, 19, 0, 18, 20, 21, 0),
    gsSP2Triangles(22, 9, 23, 0, 5, 12, 3, 0),
    gsSP2Triangles(24, 14, 13, 0, 25, 26, 27, 0),
    gsSP2Triangles(14, 3, 12, 0, 17, 28, 15, 0),
    gsSP2Triangles(13, 22, 24, 0, 29, 30, 31, 0),
    gsSPVertex(D_05006EF0_90150, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 10, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(2, 16, 17, 0, 16, 18, 19, 0),
    gsSP2Triangles(5, 20, 21, 0, 22, 7, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 18, 13, 27, 0),
    gsSP2Triangles(25, 28, 29, 0, 10, 9, 30, 0),
    gsSPVertex(D_050070E0_90340, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(10, 12, 24, 0, 13, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 19, 27, 30, 0),
    gsSPVertex(D_050072D0_90530, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 8, 7, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 22, 26, 0),
    gsSP2Triangles(20, 27, 28, 0, 21, 29, 19, 0),
    gsSP2Triangles(29, 28, 27, 0, 28, 21, 20, 0),
    gsSP1Triangle(27, 19, 29, 0),
    gsSPVertex(D_050074B0_90710, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 5, 0, 20, 21, 4, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_050076A0_90900, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(16, 12, 18, 0, 19, 15, 20, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x50, 0x02, 0x00, 0xFF),
    gsSPVertex(D_050077F0_90A50, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 4, 0, 4, 2, 1, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 7, 0),
    gsSP2Triangles(11, 8, 10, 0, 6, 11, 9, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 17, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 22, 16, 0),
    gsSP2Triangles(27, 28, 24, 0, 29, 25, 28, 0),
    gsSP2Triangles(13, 12, 19, 0, 14, 20, 12, 0),
    gsSP2Triangles(2, 5, 0, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 8, 11, 6, 0),
    gsSP2Triangles(7, 6, 9, 0, 10, 9, 11, 0),
    gsSP2Triangles(17, 21, 15, 0, 20, 14, 18, 0),
    gsSP2Triangles(22, 26, 21, 0, 25, 29, 23, 0),
    gsSP2Triangles(16, 15, 26, 0, 24, 23, 27, 0),
    gsSP2Triangles(28, 27, 29, 0, 19, 18, 13, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x6E, 0x36, 0xFF, 0xFF),
    gsSPVertex(D_050079D0_90C30, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 4, 0, 6, 2, 1, 0),
    gsSP2Triangles(1, 8, 6, 0, 4, 8, 1, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 16, 0),
    gsSP2Triangles(19, 20, 21, 0, 13, 21, 20, 0),
    gsSP2Triangles(20, 10, 13, 0, 12, 22, 10, 0),
    gsSP2Triangles(15, 21, 13, 0, 2, 5, 0, 0),
    gsSP2Triangles(1, 0, 3, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 7, 0, 4, 3, 9, 0),
    gsSP1Triangle(21, 15, 19, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_05007B40_90DA0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 11, 8, 0, 13, 8, 7, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 15, 0),
    gsSP2Triangles(19, 16, 20, 0, 21, 20, 22, 0),
    gsSP2Triangles(23, 22, 18, 0, 20, 16, 15, 0),
    gsSP2Triangles(15, 22, 20, 0, 18, 22, 15, 0),
    gsSP2Triangles(0, 2, 4, 0, 2, 5, 4, 0),
    gsSP2Triangles(6, 8, 10, 0, 8, 11, 10, 0),
    gsSP2Triangles(11, 12, 9, 0, 8, 13, 12, 0),
    gsSP2Triangles(7, 24, 13, 0, 16, 19, 14, 0),
    gsSP2Triangles(15, 14, 17, 0, 20, 21, 19, 0),
    gsSP2Triangles(22, 23, 21, 0, 18, 17, 23, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, img_intro_tigerprint_16_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0040, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 512),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPSetTileSize(1, 0, 0, 0x003C, 0x003C),
    gsSPTexture(0x8000, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_05007CD0_90F30, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 5, 0, 1, 7, 8, 0),
    gsSP2Triangles(9, 1, 10, 0, 11, 8, 12, 0),
    gsSP2Triangles(8, 13, 12, 0, 13, 14, 12, 0),
    gsSP2Triangles(14, 11, 12, 0, 11, 15, 16, 0),
    gsSP2Triangles(8, 16, 17, 0, 13, 17, 18, 0),
    gsSP2Triangles(14, 18, 15, 0, 19, 20, 21, 0),
    gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
    gsSP2Triangles(23, 19, 21, 0, 19, 24, 25, 0),
    gsSP2Triangles(20, 25, 26, 0, 22, 26, 27, 0),
    gsSP2Triangles(23, 27, 24, 0, 5, 6, 28, 0),
    gsSP2Triangles(2, 1, 9, 0, 7, 1, 29, 0),
    gsSP2Triangles(16, 15, 18, 0, 5, 28, 30, 0),
    gsSP2Triangles(18, 17, 16, 0, 27, 25, 24, 0),
    gsSPVertex(D_05007EC0_91120, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(3, 10, 2, 0, 11, 8, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 16, 12, 0),
    gsSP2Triangles(17, 18, 16, 0, 19, 14, 18, 0),
    gsSP2Triangles(5, 20, 21, 0, 4, 22, 20, 0),
    gsSP2Triangles(6, 23, 22, 0, 24, 21, 23, 0),
    gsSP2Triangles(25, 26, 27, 0, 26, 28, 27, 0),
    gsSP2Triangles(28, 29, 27, 0, 29, 30, 27, 0),
    gsSP1Triangle(30, 25, 27, 0),
    gsSPVertex(D_050080B0_91310, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 1, 0, 10, 2, 1, 0),
    gsSP2Triangles(10, 4, 2, 0, 10, 6, 4, 0),
    gsSP2Triangles(10, 8, 6, 0, 10, 1, 8, 0),
    gsSP2Triangles(11, 12, 13, 0, 12, 14, 13, 0),
    gsSP2Triangles(14, 15, 13, 0, 15, 16, 13, 0),
    gsSP2Triangles(16, 11, 13, 0, 11, 17, 18, 0),
    gsSP2Triangles(12, 18, 19, 0, 14, 19, 20, 0),
    gsSP2Triangles(15, 20, 21, 0, 16, 21, 17, 0),
    gsSP2Triangles(22, 18, 17, 0, 22, 19, 18, 0),
    gsSP2Triangles(22, 20, 19, 0, 22, 21, 20, 0),
    gsSP2Triangles(22, 17, 21, 0, 23, 24, 25, 0),
    gsSP2Triangles(24, 26, 25, 0, 26, 27, 25, 0),
    gsSP2Triangles(27, 28, 25, 0, 28, 29, 25, 0),
    gsSP2Triangles(29, 30, 25, 0, 30, 23, 25, 0),
    gsSPVertex(D_050082A0_91500, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 10, 12, 0),
    gsSP2Triangles(13, 12, 1, 0, 14, 15, 16, 0),
    gsSP2Triangles(15, 17, 16, 0, 17, 18, 16, 0),
    gsSP2Triangles(18, 19, 16, 0, 19, 20, 16, 0),
    gsSP2Triangles(20, 21, 16, 0, 21, 14, 16, 0),
    gsSP2Triangles(14, 22, 23, 0, 15, 24, 25, 0),
    gsSP2Triangles(17, 25, 26, 0, 18, 26, 27, 0),
    gsSP2Triangles(19, 27, 28, 0, 20, 29, 30, 0),
    gsSP1Triangle(21, 30, 22, 0),
    gsSPVertex(D_05008490_916F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 0, 2, 0, 0, 6, 7, 0),
    gsSP2Triangles(1, 7, 8, 0, 3, 8, 9, 0),
    gsSP2Triangles(4, 9, 10, 0, 5, 10, 6, 0),
    gsSP2Triangles(11, 7, 6, 0, 11, 8, 7, 0),
    gsSP2Triangles(11, 9, 8, 0, 11, 10, 9, 0),
    gsSP2Triangles(11, 6, 10, 0, 12, 13, 14, 0),
    gsSP2Triangles(13, 15, 14, 0, 15, 16, 14, 0),
    gsSP2Triangles(16, 17, 14, 0, 17, 12, 14, 0),
    gsSP2Triangles(12, 18, 19, 0, 13, 19, 20, 0),
    gsSP2Triangles(15, 20, 21, 0, 16, 21, 22, 0),
    gsSP2Triangles(17, 22, 18, 0, 23, 19, 18, 0),
    gsSP2Triangles(23, 20, 19, 0, 23, 21, 20, 0),
    gsSP2Triangles(23, 22, 21, 0, 23, 18, 22, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 25, 0),
    gsSP1Triangle(29, 30, 28, 0),
    gsSPVertex(D_05008680_918E0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 6, 0),
    gsSP2Triangles(10, 11, 9, 0, 12, 13, 11, 0),
    gsSP2Triangles(14, 7, 13, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 16, 0, 20, 21, 19, 0),
    gsSP2Triangles(22, 23, 21, 0, 24, 25, 23, 0),
    gsSP2Triangles(26, 27, 25, 0, 28, 17, 27, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05008880_91AE0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 8, 6, 0),
    gsSP2Triangles(9, 10, 8, 0, 11, 12, 10, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 14, 0),
    gsSP2Triangles(18, 19, 17, 0, 20, 21, 19, 0),
    gsSP2Triangles(22, 15, 21, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 24, 0, 28, 29, 27, 0),
    gsSPVertex(D_05008A60_91CC0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x09, 0x58, 0x00, 0xFF),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_05008AB0_91D10, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(4, 2, 1, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 5, 6, 0, 6, 7, 0, 0),
    gsSP2Triangles(2, 5, 0, 0, 0, 7, 3, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_intro_tbd_D_05005E10_8F070_D_05005E10_8F070__rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0080, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0080, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(2, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, 2, G_ON),
    gsSPVertex(D_05008B30_91D90, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(13, 16, 14, 0, 17, 18, 19, 0),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, img_intro_spaceship_interior_4_16_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0180, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 512),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0180, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD),
    gsDPSetTileSize(3, 0, 0, 0x003C, 0x003C),
    gsSPTexture(0x8000, 0x8000, 0, 3, G_ON),
    gsSPVertex(D_05008C70_91ED0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 5, 7, 3, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x1A, 0x1B, 0x4D, 0xFF),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_05008CF0_91F50, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 1, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 1, 0, 5, 0),
    gsSPEndDisplayList(),
};
