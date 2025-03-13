#include <ultra64.h>

Vtx D_05008170_A9240[8] = {
#include "data/inc/D_05008170_A9240.inc.c"
};
Vtx D_050081F0_A92C0[30] = {
#include "data/inc/D_050081F0_A92C0.inc.c"
};
Vtx D_050083D0_A94A0[30] = {
#include "data/inc/D_050083D0_A94A0.inc.c"
};
Vtx D_050085B0_A9680[32] = {
#include "data/inc/D_050085B0_A9680.inc.c"
};
Vtx D_050087B0_A9880[32] = {
#include "data/inc/D_050087B0_A9880.inc.c"
};
Vtx D_050089B0_A9A80[32] = {
#include "data/inc/D_050089B0_A9A80.inc.c"
};
Vtx D_05008BB0_A9C80[30] = {
#include "data/inc/D_05008BB0_A9C80.inc.c"
};
Vtx D_05008D90_A9E60[32] = {
#include "data/inc/D_05008D90_A9E60.inc.c"
};
Vtx D_05008F90_AA060[30] = {
#include "data/inc/D_05008F90_AA060.inc.c"
};
Vtx D_05009170_AA240[31] = {
#include "data/inc/D_05009170_AA240.inc.c"
};
Vtx D_05009360_AA430[16] = {
#include "data/inc/D_05009360_AA430.inc.c"
};
extern u8 img_shrink_ray_D_05007970_A8A40_D_05007970_A8A40__rgba16__png[];

Gfx D_05009460_AA530[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05008170_A9240, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_shrink_ray_D_05007970_A8A40_D_05007970_A8A40__rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_050081F0_A92C0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(7, 10, 11, 8, 0),
    gsSP1Quadrangle(10, 6, 9, 11, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(13, 16, 17, 14, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(19, 22, 23, 20, 0),
    gsSP1Quadrangle(22, 18, 21, 23, 0),
    gsSP1Quadrangle(16, 12, 15, 17, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(25, 28, 29, 26, 0),
    gsSPVertex(D_050083D0_A94A0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(11, 14, 15, 12, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(17, 20, 21, 18, 0),
    gsSP1Quadrangle(20, 16, 19, 21, 0),
    gsSP1Quadrangle(14, 10, 13, 15, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSPVertex(D_050085B0_A9680, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP2Triangles(12, 4, 13, 0, 8, 1, 12, 0),
    gsSP2Triangles(12, 14, 5, 0, 15, 9, 12, 0),
    gsSP2Triangles(16, 12, 0, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(21, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_050087B0_A9880, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 3, 0, 22, 23, 24, 0),
    gsSP2Triangles(22, 24, 21, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 19, 30, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_050089B0_A9A80, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 2, 0),
    gsSP1Quadrangle(7, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 0, 12, 13, 0),
    gsSP1Quadrangle(14, 15, 1, 16, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP1Quadrangle(21, 22, 23, 24, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05008BB0_A9C80, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 16, 10, 0),
    gsSP2Triangles(15, 10, 9, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(21, 23, 24, 0, 18, 25, 6, 0),
    gsSP2Triangles(18, 6, 19, 0, 26, 27, 28, 0),
    gsSP1Triangle(26, 28, 29, 0),
    gsSPVertex(D_05008D90_A9E60, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_05008F90_AA060, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(13, 16, 17, 14, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(19, 22, 23, 20, 0),
    gsSP1Quadrangle(22, 18, 21, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(25, 28, 29, 26, 0),
    gsSP1Quadrangle(28, 24, 27, 29, 0),
    gsSPVertex(D_05009170_AA240, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(13, 16, 17, 14, 0),
    gsSP1Quadrangle(16, 12, 15, 17, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(23, 26, 27, 24, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05009360_AA430, 16, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 7, 8, 0),
    gsSP2Triangles(4, 9, 10, 0, 11, 11, 11, 0),
    gsSP2Triangles(11, 11, 11, 0, 12, 11, 11, 0),
    gsSP2Triangles(12, 11, 13, 0, 11, 11, 12, 0),
    gsSP1Quadrangle(11, 12, 14, 15, 0),
    gsSP1Quadrangle(11, 15, 11, 15, 0),
    gsSP1Triangle(11, 15, 13, 0),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
