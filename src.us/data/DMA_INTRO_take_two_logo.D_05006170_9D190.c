#include <ultra64.h>

extern u8 img_take_two_logo_D_05001410_98430_rgba16_D_05001410_98430__rgba16__png[];

Vtx D_05001C10_98C30[32] = {
#include "data/inc/D_05001C10_98C30.inc.c"
};
Vtx D_05001E10_98E30[32] = {
#include "data/inc/D_05001E10_98E30.inc.c"
};
Vtx D_05002010_99030[32] = {
#include "data/inc/D_05002010_99030.inc.c"
};
Vtx D_05002210_99230[32] = {
#include "data/inc/D_05002210_99230.inc.c"
};
Vtx D_05002410_99430[31] = {
#include "data/inc/D_05002410_99430.inc.c"
};
Vtx D_05002600_99620[31] = {
#include "data/inc/D_05002600_99620.inc.c"
};
Vtx D_050027F0_99810[31] = {
#include "data/inc/D_050027F0_99810.inc.c"
};
Vtx D_050029E0_99A00[31] = {
#include "data/inc/D_050029E0_99A00.inc.c"
};
Vtx D_05002BD0_99BF0[31] = {
#include "data/inc/D_05002BD0_99BF0.inc.c"
};
Vtx D_05002DC0_99DE0[31] = {
#include "data/inc/D_05002DC0_99DE0.inc.c"
};
Vtx D_05002FB0_99FD0[32] = {
#include "data/inc/D_05002FB0_99FD0.inc.c"
};
Vtx D_050031B0_9A1D0[31] = {
#include "data/inc/D_050031B0_9A1D0.inc.c"
};
Vtx D_050033A0_9A3C0[32] = {
#include "data/inc/D_050033A0_9A3C0.inc.c"
};
Vtx D_050035A0_9A5C0[32] = {
#include "data/inc/D_050035A0_9A5C0.inc.c"
};
Vtx D_050037A0_9A7C0[32] = {
#include "data/inc/D_050037A0_9A7C0.inc.c"
};
Vtx D_050039A0_9A9C0[31] = {
#include "data/inc/D_050039A0_9A9C0.inc.c"
};
Vtx D_05003B90_9ABB0[31] = {
#include "data/inc/D_05003B90_9ABB0.inc.c"
};
Vtx D_05003D80_9ADA0[32] = {
#include "data/inc/D_05003D80_9ADA0.inc.c"
};
Vtx D_05003F80_9AFA0[31] = {
#include "data/inc/D_05003F80_9AFA0.inc.c"
};
Vtx D_05004170_9B190[31] = {
#include "data/inc/D_05004170_9B190.inc.c"
};
Vtx D_05004360_9B380[31] = {
#include "data/inc/D_05004360_9B380.inc.c"
};
Vtx D_05004550_9B570[30] = {
#include "data/inc/D_05004550_9B570.inc.c"
};
Vtx D_05004730_9B750[32] = {
#include "data/inc/D_05004730_9B750.inc.c"
};
Vtx D_05004930_9B950[30] = {
#include "data/inc/D_05004930_9B950.inc.c"
};
Vtx D_05004B10_9BB30[31] = {
#include "data/inc/D_05004B10_9BB30.inc.c"
};
Vtx D_05004D00_9BD20[32] = {
#include "data/inc/D_05004D00_9BD20.inc.c"
};
Vtx D_05004F00_9BF20[31] = {
#include "data/inc/D_05004F00_9BF20.inc.c"
};
Vtx D_050050F0_9C110[32] = {
#include "data/inc/D_050050F0_9C110.inc.c"
};
Vtx D_050052F0_9C310[32] = {
#include "data/inc/D_050052F0_9C310.inc.c"
};
Vtx D_050054F0_9C510[32] = {
#include "data/inc/D_050054F0_9C510.inc.c"
};
Vtx D_050056F0_9C710[31] = {
#include "data/inc/D_050056F0_9C710.inc.c"
};
Vtx D_050058E0_9C900[31] = {
#include "data/inc/D_050058E0_9C900.inc.c"
};
Vtx D_05005AD0_9CAF0[31] = {
#include "data/inc/D_05005AD0_9CAF0.inc.c"
};
Vtx D_05005CC0_9CCE0[32] = {
#include "data/inc/D_05005CC0_9CCE0.inc.c"
};
Vtx D_05005EC0_9CEE0[32] = {
#include "data/inc/D_05005EC0_9CEE0.inc.c"
};
Vtx D_050060C0_9D0E0[11] = {
#include "data/inc/D_050060C0_9D0E0.inc.c"
};


const Gfx D_05006170_9D190[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_take_two_logo_D_05001410_98430_rgba16_D_05001410_98430__rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05001C10_98C30, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
    gsSP1Quadrangle(5, 3, 6, 7, 0),
    gsSP2Triangles(5, 7, 8, 0, 8, 7, 9, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP2Triangles(11, 10, 12, 0, 12, 10, 13, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 19, 23, 24, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP2Triangles(26, 25, 14, 0, 25, 28, 29, 0),
    gsSP2Triangles(29, 28, 30, 0, 30, 28, 31, 0),
    gsSPVertex(D_05001E10_98E30, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 1, 7, 0, 8, 9, 10, 0),
    gsSP1Quadrangle(8, 10, 11, 12, 0),
    gsSP2Triangles(12, 11, 13, 0, 13, 11, 14, 0),
    gsSP1Quadrangle(13, 14, 15, 16, 0),
    gsSP1Quadrangle(16, 15, 17, 18, 0),
    gsSP2Triangles(16, 18, 19, 0, 19, 18, 20, 0),
    gsSP1Quadrangle(20, 18, 21, 22, 0),
    gsSP2Triangles(20, 22, 23, 0, 23, 22, 5, 0),
    gsSP1Quadrangle(5, 22, 24, 3, 0),
    gsSP2Triangles(7, 1, 25, 0, 26, 9, 8, 0),
    gsSP2Triangles(7, 25, 27, 0, 4, 3, 28, 0),
    gsSP2Triangles(4, 28, 29, 0, 29, 28, 30, 0),
    gsSP1Triangle(30, 28, 31, 0),
    gsSPVertex(D_05002010_99030, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 8, 9, 0),
    gsSP1Quadrangle(10, 2, 11, 12, 0),
    gsSP2Triangles(12, 11, 13, 0, 13, 11, 14, 0),
    gsSP1Quadrangle(13, 14, 15, 16, 0),
    gsSP2Triangles(16, 15, 17, 0, 17, 15, 18, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP1Quadrangle(5, 6, 21, 22, 0),
    gsSP2Triangles(20, 23, 24, 0, 24, 23, 25, 0),
    gsSP1Quadrangle(25, 23, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 28, 27, 29, 0),
    gsSP1Quadrangle(29, 27, 30, 31, 0),
    gsSPVertex(D_05002210_99230, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 2, 0),
    gsSP2Triangles(2, 1, 9, 0, 10, 9, 11, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP2Triangles(13, 12, 14, 0, 14, 12, 15, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP2Triangles(17, 16, 18, 0, 18, 16, 19, 0),
    gsSP1Quadrangle(19, 16, 20, 21, 0),
    gsSP2Triangles(21, 20, 22, 0, 22, 20, 23, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP2Triangles(25, 24, 26, 0, 26, 24, 27, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSP1Quadrangle(29, 28, 30, 31, 0),
    gsSPVertex(D_05002410_99430, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 5, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 10, 9, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 13, 15, 0, 17, 13, 16, 0),
    gsSP2Triangles(18, 13, 17, 0, 19, 18, 17, 0),
    gsSP2Triangles(20, 19, 17, 0, 21, 19, 20, 0),
    gsSP2Triangles(22, 19, 21, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 23, 21, 0, 25, 23, 24, 0),
    gsSP2Triangles(26, 23, 25, 0, 27, 26, 25, 0),
    gsSP2Triangles(28, 27, 25, 0, 29, 27, 28, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(D_05002600_99620, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(6, 7, 4, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 2, 1, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 6, 16, 0),
    gsSP2Triangles(17, 6, 15, 0, 18, 17, 15, 0),
    gsSP2Triangles(19, 17, 18, 0, 20, 19, 18, 0),
    gsSP2Triangles(21, 20, 18, 0, 22, 20, 21, 0),
    gsSP2Triangles(23, 20, 22, 0, 24, 23, 22, 0),
    gsSP2Triangles(25, 24, 22, 0, 26, 24, 25, 0),
    gsSP2Triangles(27, 24, 26, 0, 28, 27, 26, 0),
    gsSP2Triangles(29, 28, 26, 0, 30, 28, 29, 0),
    gsSPVertex(D_050027F0_99810, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 7, 5, 0, 9, 7, 8, 0),
    gsSP2Triangles(10, 9, 8, 0, 11, 9, 10, 0),
    gsSP2Triangles(12, 9, 11, 0, 13, 12, 11, 0),
    gsSP2Triangles(14, 13, 11, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 15, 14, 0, 17, 15, 16, 0),
    gsSP2Triangles(18, 15, 17, 0, 19, 18, 17, 0),
    gsSP2Triangles(20, 19, 17, 0, 21, 19, 20, 0),
    gsSP2Triangles(22, 19, 21, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 23, 21, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 26, 25, 0, 29, 26, 28, 0),
    gsSP1Triangle(30, 29, 28, 0),
    gsSPVertex(D_050029E0_99A00, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
    gsSP2Triangles(6, 4, 5, 0, 7, 4, 6, 0),
    gsSP2Triangles(8, 7, 6, 0, 9, 8, 6, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 2, 1, 0),
    gsSP2Triangles(14, 15, 16, 0, 14, 17, 15, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 19, 18, 0),
    gsSP2Triangles(22, 21, 18, 0, 23, 22, 18, 0),
    gsSP2Triangles(24, 22, 23, 0, 25, 22, 24, 0),
    gsSP2Triangles(26, 25, 24, 0, 27, 26, 24, 0),
    gsSP2Triangles(28, 26, 27, 0, 29, 28, 27, 0),
    gsSP1Triangle(30, 28, 29, 0),
    gsSPVertex(D_05002BD0_99BF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 7, 5, 0, 9, 7, 8, 0),
    gsSP2Triangles(10, 7, 9, 0, 11, 10, 9, 0),
    gsSP2Triangles(12, 11, 9, 0, 13, 11, 12, 0),
    gsSP2Triangles(14, 11, 13, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 15, 13, 0, 17, 15, 16, 0),
    gsSP2Triangles(18, 15, 17, 0, 19, 18, 17, 0),
    gsSP2Triangles(20, 19, 17, 0, 21, 19, 20, 0),
    gsSP2Triangles(22, 21, 20, 0, 23, 21, 22, 0),
    gsSP2Triangles(24, 21, 23, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 26, 25, 0, 29, 26, 28, 0),
    gsSP1Triangle(30, 26, 29, 0),
    gsSPVertex(D_05002DC0_99DE0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(3, 0, 4, 0, 5, 3, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 6, 7, 0, 9, 8, 7, 0),
    gsSP1Quadrangle(10, 8, 9, 11, 0),
    gsSP2Triangles(11, 9, 12, 0, 13, 11, 12, 0),
    gsSP2Triangles(12, 14, 13, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(20, 22, 21, 0, 20, 23, 22, 0),
    gsSP2Triangles(20, 24, 23, 0, 24, 25, 23, 0),
    gsSP1Quadrangle(26, 20, 19, 27, 0),
    gsSP1Quadrangle(28, 26, 27, 29, 0),
    gsSP1Triangle(30, 28, 29, 0),
    gsSPVertex(D_05002FB0_99FD0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 5, 6, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 7, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 9, 10, 0),
    gsSP2Triangles(11, 10, 12, 0, 12, 10, 13, 0),
    gsSP2Triangles(14, 12, 13, 0, 14, 15, 16, 0),
    gsSP1Quadrangle(17, 14, 16, 18, 0),
    gsSP1Quadrangle(19, 17, 18, 20, 0),
    gsSP2Triangles(21, 19, 20, 0, 22, 19, 21, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 23, 25, 0),
    gsSP2Triangles(27, 23, 26, 0, 28, 27, 26, 0),
    gsSP2Triangles(29, 27, 28, 0, 30, 27, 29, 0),
    gsSP1Triangle(25, 24, 31, 0),
    gsSPVertex(D_050031B0_9A1D0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 7, 6, 3, 0),
    gsSP2Triangles(8, 7, 3, 0, 8, 9, 7, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 9, 10, 0),
    gsSP2Triangles(12, 1, 0, 0, 13, 11, 10, 0),
    gsSP2Triangles(14, 11, 13, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 15, 13, 0, 17, 15, 16, 0),
    gsSP2Triangles(18, 15, 17, 0, 19, 12, 0, 0),
    gsSP2Triangles(20, 19, 0, 0, 21, 18, 17, 0),
    gsSP2Triangles(22, 18, 21, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 23, 21, 0, 25, 23, 24, 0),
    gsSP2Triangles(26, 23, 25, 0, 27, 26, 25, 0),
    gsSP2Triangles(28, 27, 25, 0, 29, 27, 28, 0),
    gsSP1Triangle(30, 27, 29, 0),
    gsSPVertex(D_050033A0_9A3C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 3, 4, 0),
    gsSP2Triangles(6, 5, 4, 0, 7, 6, 4, 0),
    gsSP2Triangles(8, 6, 7, 0, 9, 6, 8, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(15, 14, 16, 0, 16, 14, 13, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP1Quadrangle(20, 19, 21, 22, 0),
    gsSP2Triangles(22, 21, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(24, 26, 27, 0, 22, 23, 28, 0),
    gsSP1Quadrangle(28, 23, 29, 30, 0),
    gsSP1Triangle(28, 30, 31, 0),
    gsSPVertex(D_050035A0_9A5C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 4, 9, 10, 0),
    gsSP2Triangles(8, 10, 11, 0, 11, 10, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 11, 12, 16, 0),
    gsSP1Quadrangle(16, 12, 17, 18, 0),
    gsSP2Triangles(16, 18, 19, 0, 19, 18, 20, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 19, 0),
    gsSP2Triangles(19, 21, 22, 0, 13, 15, 5, 0),
    gsSP1Quadrangle(5, 15, 24, 6, 0),
    gsSP2Triangles(23, 22, 25, 0, 25, 22, 26, 0),
    gsSP2Triangles(25, 26, 27, 0, 27, 26, 28, 0),
    gsSP2Triangles(28, 26, 13, 0, 29, 30, 31, 0),
    gsSPVertex(D_050037A0_9A7C0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(5, 4, 3, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 3, 10, 11, 0),
    gsSP2Triangles(11, 12, 3, 0, 13, 9, 14, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 11, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 20, 19, 0),
    gsSP2Triangles(21, 19, 22, 0, 15, 21, 22, 0),
    gsSP2Triangles(22, 13, 15, 0, 6, 9, 13, 0),
    gsSP2Triangles(23, 24, 25, 0, 24, 26, 27, 0),
    gsSP2Triangles(24, 27, 25, 0, 23, 28, 6, 0),
    gsSP2Triangles(6, 28, 7, 0, 0, 4, 1, 0),
    gsSP1Quadrangle(18, 20, 29, 30, 0),
    gsSP1Triangle(18, 30, 31, 0),
    gsSPVertex(D_050039A0_9A9C0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 8, 7, 0, 11, 6, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 5, 17, 0),
    gsSP2Triangles(12, 6, 18, 0, 16, 17, 19, 0),
    gsSP2Triangles(16, 19, 10, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 20, 22, 0, 24, 20, 23, 0),
    gsSP2Triangles(25, 24, 23, 0, 26, 24, 25, 0),
    gsSP2Triangles(27, 24, 26, 0, 28, 27, 26, 0),
    gsSP2Triangles(29, 28, 26, 0, 30, 28, 29, 0),
    gsSPVertex(D_05003B90_9ABB0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 7, 5, 0, 9, 7, 8, 0),
    gsSP2Triangles(10, 9, 8, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 12, 11, 0, 15, 9, 10, 0),
    gsSP2Triangles(16, 9, 15, 0, 17, 16, 15, 0),
    gsSP2Triangles(18, 17, 15, 0, 19, 17, 18, 0),
    gsSP2Triangles(20, 17, 19, 0, 21, 20, 19, 0),
    gsSP2Triangles(22, 21, 19, 0, 23, 21, 24, 0),
    gsSP2Triangles(21, 22, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(27, 26, 28, 0, 29, 14, 11, 0),
    gsSP2Triangles(30, 29, 11, 0, 13, 12, 27, 0),
    gsSP1Triangle(12, 25, 27, 0),
    gsSPVertex(D_05003D80_9ADA0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
    gsSP2Triangles(8, 4, 7, 0, 9, 4, 8, 0),
    gsSP2Triangles(10, 9, 8, 0, 11, 10, 8, 0),
    gsSP2Triangles(12, 10, 11, 0, 13, 10, 12, 0),
    gsSP2Triangles(14, 13, 12, 0, 15, 14, 12, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP2Triangles(19, 18, 20, 0, 20, 18, 21, 0),
    gsSP2Triangles(21, 18, 22, 0, 22, 18, 23, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP2Triangles(25, 24, 26, 0, 16, 27, 17, 0),
    gsSP2Triangles(28, 29, 30, 0, 25, 26, 31, 0),
    gsSPVertex(D_05003F80_9AFA0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 4, 3, 5, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 8, 6, 9, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP2Triangles(9, 6, 14, 0, 14, 6, 15, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP1Quadrangle(17, 16, 18, 19, 0),
    gsSP2Triangles(17, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(20, 21, 22, 0, 10, 13, 23, 0),
    gsSP2Triangles(20, 22, 24, 0, 24, 22, 25, 0),
    gsSP2Triangles(24, 25, 11, 0, 26, 27, 28, 0),
    gsSP2Triangles(29, 26, 28, 0, 30, 26, 29, 0),
    gsSPVertex(D_05004170_9B190, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 9, 0, 11, 6, 5, 0),
    gsSP2Triangles(12, 6, 11, 0, 13, 12, 11, 0),
    gsSP2Triangles(14, 13, 11, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 13, 15, 0, 17, 16, 15, 0),
    gsSP2Triangles(18, 17, 15, 0, 19, 7, 10, 0),
    gsSP2Triangles(20, 19, 10, 0, 21, 17, 18, 0),
    gsSP2Triangles(22, 17, 21, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 23, 21, 0, 25, 23, 24, 0),
    gsSP2Triangles(26, 23, 25, 0, 27, 26, 25, 0),
    gsSP2Triangles(28, 27, 25, 0, 29, 27, 28, 0),
    gsSP1Triangle(30, 27, 29, 0),
    gsSPVertex(D_05004360_9B380, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 0, 4, 0),
    gsSP2Triangles(6, 5, 4, 0, 7, 6, 4, 0),
    gsSP2Triangles(8, 6, 7, 0, 9, 6, 8, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(10, 14, 15, 0, 13, 11, 16, 0),
    gsSP1Quadrangle(17, 13, 16, 18, 0),
    gsSP2Triangles(18, 16, 19, 0, 19, 16, 20, 0),
    gsSP2Triangles(20, 11, 10, 0, 21, 19, 20, 0),
    gsSP2Triangles(20, 22, 21, 0, 10, 22, 20, 0),
    gsSP1Quadrangle(23, 24, 25, 26, 0),
    gsSP2Triangles(26, 25, 27, 0, 28, 26, 27, 0),
    gsSP2Triangles(28, 27, 29, 0, 27, 30, 29, 0),
    gsSPVertex(D_05004550_9B570, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 5, 7, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 12, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 19, 21, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 24, 26, 0),
    gsSP2Triangles(28, 22, 23, 0, 29, 27, 26, 0),
    gsSP2Triangles(16, 18, 26, 0, 26, 25, 16, 0),
    gsSPVertex(D_05004730_9B750, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 1, 2, 0),
    gsSP2Triangles(10, 3, 5, 0, 11, 3, 10, 0),
    gsSP2Triangles(12, 11, 10, 0, 13, 12, 10, 0),
    gsSP2Triangles(14, 10, 13, 0, 15, 14, 10, 0),
    gsSP2Triangles(16, 14, 15, 0, 17, 0, 2, 0),
    gsSP2Triangles(18, 17, 2, 0, 14, 13, 10, 0),
    gsSP2Triangles(19, 6, 8, 0, 20, 21, 16, 0),
    gsSP2Triangles(16, 21, 14, 0, 4, 22, 5, 0),
    gsSP2Triangles(23, 20, 16, 0, 24, 23, 16, 0),
    gsSP2Triangles(25, 24, 16, 0, 26, 24, 25, 0),
    gsSP2Triangles(27, 6, 19, 0, 28, 27, 19, 0),
    gsSP2Triangles(29, 26, 25, 0, 9, 30, 1, 0),
    gsSP1Triangle(5, 22, 31, 0),
    gsSPVertex(D_05004930_9B950, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 8, 0),
    gsSP2Triangles(10, 6, 9, 0, 11, 10, 9, 0),
    gsSP2Triangles(12, 10, 11, 0, 13, 10, 12, 0),
    gsSP2Triangles(14, 13, 12, 0, 15, 14, 12, 0),
    gsSP2Triangles(16, 14, 15, 0, 17, 16, 15, 0),
    gsSP2Triangles(18, 16, 17, 0, 19, 16, 18, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 20, 0),
    gsSP2Triangles(24, 19, 18, 0, 25, 19, 24, 0),
    gsSP2Triangles(26, 25, 24, 0, 27, 26, 24, 0),
    gsSP2Triangles(28, 26, 27, 0, 29, 26, 28, 0),
    gsSPVertex(D_05004B10_9BB30, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 1, 0, 0),
    gsSP2Triangles(8, 1, 7, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 9, 7, 0, 11, 9, 10, 0),
    gsSP2Triangles(12, 9, 11, 0, 13, 12, 11, 0),
    gsSP2Triangles(14, 13, 11, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 13, 15, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 17, 19, 0, 21, 16, 15, 0),
    gsSP2Triangles(22, 16, 21, 0, 23, 22, 21, 0),
    gsSP2Triangles(24, 23, 21, 0, 25, 23, 24, 0),
    gsSP2Triangles(26, 25, 24, 0, 27, 25, 26, 0),
    gsSP2Triangles(28, 25, 27, 0, 29, 28, 27, 0),
    gsSP1Triangle(30, 29, 27, 0),
    gsSPVertex(D_05004D00_9BD20, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
    gsSP2Triangles(6, 4, 5, 0, 7, 4, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 11, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 21, 23, 0),
    gsSP2Triangles(17, 24, 18, 0, 16, 21, 20, 0),
    gsSP2Triangles(18, 25, 26, 0, 23, 27, 28, 0),
    gsSP2Triangles(21, 27, 23, 0, 16, 27, 21, 0),
    gsSP2Triangles(16, 26, 27, 0, 22, 23, 28, 0),
    gsSP2Triangles(18, 26, 16, 0, 29, 30, 31, 0),
    gsSPVertex(D_05004F00_9BF20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(11, 9, 0, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 14, 18, 0, 19, 20, 12, 0),
    gsSP2Triangles(12, 21, 19, 0, 18, 22, 16, 0),
    gsSP2Triangles(17, 21, 15, 0, 15, 21, 12, 0),
    gsSP1Quadrangle(14, 13, 23, 18, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(27, 30, 28, 0),
    gsSPVertex(D_050050F0_9C110, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 3, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 0, 4, 1, 0),
    gsSP2Triangles(2, 1, 11, 0, 11, 1, 12, 0),
    gsSP2Triangles(13, 11, 12, 0, 14, 11, 13, 0),
    gsSP2Triangles(15, 16, 17, 0, 7, 5, 3, 0),
    gsSP2Triangles(15, 17, 14, 0, 9, 7, 8, 0),
    gsSP2Triangles(18, 5, 7, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 19, 21, 0, 21, 23, 22, 0),
    gsSP1Quadrangle(24, 23, 21, 25, 0),
    gsSP2Triangles(26, 24, 25, 0, 27, 24, 26, 0),
    gsSP2Triangles(27, 28, 24, 0, 29, 30, 31, 0),
    gsSPVertex(D_050052F0_9C310, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 9, 0, 11, 12, 10, 0),
    gsSP1Quadrangle(13, 12, 11, 14, 0),
    gsSP2Triangles(15, 13, 14, 0, 16, 17, 18, 0),
    gsSP2Triangles(16, 19, 17, 0, 20, 21, 22, 0),
    gsSP2Triangles(20, 23, 21, 0, 20, 22, 24, 0),
    gsSP2Triangles(24, 22, 25, 0, 25, 22, 26, 0),
    gsSP2Triangles(27, 25, 26, 0, 28, 25, 27, 0),
    gsSP2Triangles(28, 27, 29, 0, 30, 29, 31, 0),
    gsSPVertex(D_050054F0_9C510, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 6, 4, 0),
    gsSP2Triangles(5, 7, 6, 0, 8, 9, 10, 0),
    gsSP2Triangles(8, 11, 9, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 14, 15, 0, 15, 14, 16, 0),
    gsSP2Triangles(17, 1, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 24, 23, 0, 23, 19, 26, 0),
    gsSP2Triangles(23, 20, 19, 0, 27, 22, 21, 0),
    gsSP1Quadrangle(28, 22, 27, 29, 0),
    gsSP1Quadrangle(30, 28, 29, 31, 0),
    gsSPVertex(D_050056F0_9C710, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 2, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 8, 7, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 11, 13, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 16, 15, 0, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 20, 19, 23, 0),
    gsSP2Triangles(24, 22, 23, 0, 24, 25, 22, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 27, 26, 0),
    gsSP1Triangle(26, 28, 30, 0),
    gsSPVertex(D_050058E0_9C900, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 1, 3, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 6, 5, 0, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 10, 9, 13, 0),
    gsSP1Quadrangle(14, 12, 13, 15, 0),
    gsSP1Quadrangle(16, 14, 15, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
    gsSP2Triangles(19, 18, 20, 0, 21, 19, 20, 0),
    gsSP2Triangles(21, 20, 22, 0, 23, 21, 22, 0),
    gsSP2Triangles(23, 22, 24, 0, 25, 23, 24, 0),
    gsSP2Triangles(24, 26, 25, 0, 27, 26, 24, 0),
    gsSP1Quadrangle(28, 26, 27, 29, 0),
    gsSP1Triangle(30, 28, 29, 0),
    gsSPVertex(D_05005AD0_9CAF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(3, 4, 1, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 7, 8, 0),
    gsSP1Quadrangle(10, 7, 9, 11, 0),
    gsSP1Quadrangle(12, 10, 11, 13, 0),
    gsSP1Quadrangle(14, 12, 13, 15, 0),
    gsSP2Triangles(15, 13, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 18, 17, 0, 5, 18, 20, 0),
    gsSP2Triangles(5, 20, 6, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 22, 21, 0, 21, 23, 25, 0),
    gsSP2Triangles(26, 21, 25, 0, 27, 28, 29, 0),
    gsSP2Triangles(30, 28, 27, 0, 22, 24, 22, 0),
    gsSPVertex(D_05005CC0_9CCE0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSP2Triangles(7, 4, 8, 0, 9, 7, 8, 0),
    gsSP1Quadrangle(10, 7, 9, 11, 0),
    gsSP1Quadrangle(11, 9, 12, 13, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 13, 15, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 19, 20, 0, 21, 17, 20, 0),
    gsSP2Triangles(20, 22, 21, 0, 23, 24, 25, 0),
    gsSP2Triangles(25, 21, 23, 0, 25, 24, 26, 0),
    gsSP2Triangles(26, 24, 27, 0, 27, 28, 26, 0),
    gsSP2Triangles(17, 25, 26, 0, 26, 18, 17, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05005EC0_9CEE0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 10, 9, 0),
    gsSP1Quadrangle(12, 11, 9, 13, 0),
    gsSP1Quadrangle(14, 12, 13, 15, 0),
    gsSP2Triangles(16, 14, 15, 0, 17, 14, 16, 0),
    gsSP1Quadrangle(18, 17, 16, 19, 0),
    gsSP2Triangles(19, 16, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(22, 24, 23, 0, 25, 26, 27, 0),
    gsSP2Triangles(26, 28, 27, 0, 29, 30, 31, 0),
    gsSPVertex(D_050060C0_9D0E0, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 3, 4, 0, 0, 6, 7, 0),
    gsSP2Triangles(8, 0, 7, 0, 8, 4, 9, 0),
    gsSP1Triangle(10, 8, 9, 0),
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};