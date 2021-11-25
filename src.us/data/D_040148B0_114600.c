#include <ultra64.h>

Vtx D_04012DA0_112AF0[8] = {
#include "data/inc/D_04012DA0_112AF0.inc.c"
};
Vtx D_04012E20_112B70[31] = {
#include "data/inc/D_04012E20_112B70.inc.c"
};
Vtx D_04013010_112D60[31] = {
#include "data/inc/D_04013010_112D60.inc.c"
};
Vtx D_04013200_112F50[31] = {
#include "data/inc/D_04013200_112F50.inc.c"
};
Vtx D_040133F0_113140[30] = {
#include "data/inc/D_040133F0_113140.inc.c"
};
Vtx D_040135D0_113320[12] = {
#include "data/inc/D_040135D0_113320.inc.c"
};
Vtx D_04013690_1133E0[32] = {
#include "data/inc/D_04013690_1133E0.inc.c"
};
Vtx D_04013890_1135E0[32] = {
#include "data/inc/D_04013890_1135E0.inc.c"
};
Vtx D_04013A90_1137E0[32] = {
#include "data/inc/D_04013A90_1137E0.inc.c"
};
Vtx D_04013C90_1139E0[32] = {
#include "data/inc/D_04013C90_1139E0.inc.c"
};
Vtx D_04013E90_113BE0[12] = {
#include "data/inc/D_04013E90_113BE0.inc.c"
};
Vtx D_04013F50_113CA0[31] = {
#include "data/inc/D_04013F50_113CA0.inc.c"
};
Vtx D_04014140_113E90[30] = {
#include "data/inc/D_04014140_113E90.inc.c"
};
Vtx D_04014320_114070[32] = {
#include "data/inc/D_04014320_114070.inc.c"
};
Vtx D_04014520_114270[27] = {
#include "data/inc/D_04014520_114270.inc.c"
};
Vtx D_040146D0_114420[30] = {
#include "data/inc/D_040146D0_114420.inc.c"
};

extern u8 D_040125A0_1122F0[];

const Gfx D_040148B0_114600[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04012DA0_112AF0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_040125A0_1122F0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04012E20_112B70, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 0, 6, 0, 1, 4, 2, 0),
    gsSP2Triangles(6, 0, 7, 0, 5, 8, 0, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(3, 15, 4, 0, 11, 12, 16, 0),
    gsSP2Triangles(17, 13, 12, 0, 10, 17, 12, 0),
    gsSP2Triangles(6, 10, 9, 0, 18, 6, 9, 0),
    gsSP2Triangles(7, 17, 10, 0, 6, 7, 10, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 19, 21, 0),
    gsSP2Triangles(20, 5, 18, 0, 21, 20, 18, 0),
    gsSP2Triangles(23, 24, 20, 0, 19, 23, 20, 0),
    gsSP2Triangles(24, 8, 5, 0, 20, 24, 5, 0),
    gsSP2Triangles(25, 26, 24, 0, 23, 25, 24, 0),
    gsSP2Triangles(26, 27, 8, 0, 24, 26, 8, 0),
    gsSP2Triangles(28, 29, 26, 0, 25, 28, 26, 0),
    gsSP2Triangles(29, 30, 27, 0, 26, 29, 27, 0),
    gsSPVertex(D_04013010_112D60, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 1, 0, 0, 4, 1, 0),
    gsSP2Triangles(6, 0, 3, 0, 7, 6, 3, 0),
    gsSP2Triangles(8, 4, 0, 0, 6, 8, 0, 0),
    gsSP2Triangles(9, 6, 7, 0, 10, 9, 7, 0),
    gsSP2Triangles(11, 8, 6, 0, 9, 11, 6, 0),
    gsSP2Triangles(12, 9, 10, 0, 13, 12, 10, 0),
    gsSP2Triangles(14, 11, 9, 0, 12, 14, 9, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 15, 17, 0),
    gsSP2Triangles(16, 19, 13, 0, 17, 16, 13, 0),
    gsSP2Triangles(20, 21, 16, 0, 15, 20, 16, 0),
    gsSP2Triangles(21, 22, 19, 0, 16, 21, 19, 0),
    gsSP2Triangles(23, 24, 21, 0, 20, 23, 21, 0),
    gsSP2Triangles(24, 25, 22, 0, 21, 24, 22, 0),
    gsSP2Triangles(26, 27, 24, 0, 23, 26, 24, 0),
    gsSP2Triangles(27, 2, 25, 0, 24, 27, 25, 0),
    gsSP2Triangles(28, 27, 26, 0, 29, 28, 26, 0),
    gsSP2Triangles(3, 2, 27, 0, 28, 3, 27, 0),
    gsSP1Triangle(30, 28, 29, 0),
    gsSPVertex(D_04013200_112F50, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 3, 5, 0, 6, 1, 0, 0),
    gsSP2Triangles(7, 6, 0, 0, 8, 3, 1, 0),
    gsSP2Triangles(6, 8, 1, 0, 9, 6, 7, 0),
    gsSP2Triangles(10, 9, 7, 0, 11, 8, 6, 0),
    gsSP2Triangles(9, 11, 6, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 12, 14, 0, 13, 16, 10, 0),
    gsSP2Triangles(14, 13, 10, 0, 17, 18, 13, 0),
    gsSP2Triangles(12, 17, 13, 0, 18, 19, 16, 0),
    gsSP2Triangles(13, 18, 16, 0, 20, 21, 18, 0),
    gsSP2Triangles(17, 20, 18, 0, 21, 22, 19, 0),
    gsSP2Triangles(18, 21, 19, 0, 23, 24, 21, 0),
    gsSP2Triangles(20, 23, 21, 0, 24, 25, 22, 0),
    gsSP2Triangles(21, 24, 22, 0, 26, 24, 23, 0),
    gsSP2Triangles(27, 26, 23, 0, 2, 25, 24, 0),
    gsSP2Triangles(26, 2, 24, 0, 28, 26, 27, 0),
    gsSP2Triangles(29, 28, 27, 0, 0, 2, 26, 0),
    gsSP2Triangles(28, 0, 26, 0, 30, 28, 29, 0),
    gsSPVertex(D_040133F0_113140, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 3, 5, 0, 6, 1, 0, 0),
    gsSP2Triangles(7, 6, 0, 0, 8, 3, 1, 0),
    gsSP2Triangles(6, 8, 1, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 10, 9, 0, 13, 12, 9, 0),
    gsSP2Triangles(14, 13, 9, 0, 15, 14, 9, 0),
    gsSP2Triangles(16, 15, 9, 0, 17, 16, 9, 0),
    gsSP2Triangles(11, 17, 9, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(20, 15, 16, 0, 27, 28, 19, 0),
    gsSP2Triangles(23, 22, 28, 0, 27, 23, 28, 0),
    gsSP2Triangles(21, 10, 22, 0, 25, 21, 29, 0),
    gsSP2Triangles(28, 22, 13, 0, 29, 21, 23, 0),
    gsSPVertex(D_040135D0_113320, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
    gsSP1Triangle(10, 6, 11, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x0F, 0x00, 0x71, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_04013690_1133E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_04013890_1135E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_04013A90_1137E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_04013C90_1139E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_04013E90_113BE0, 12, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04013F50_113CA0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 6, 13, 0, 9, 8, 7, 0),
    gsSP2Triangles(14, 6, 8, 0, 19, 3, 5, 0),
    gsSP2Triangles(17, 20, 15, 0, 10, 21, 11, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP2Triangles(22, 26, 27, 0, 27, 28, 22, 0),
    gsSP2Triangles(29, 14, 8, 0, 20, 17, 30, 0),
    gsSP1Triangle(13, 12, 18, 0),
    gsSPVertex(D_04014140_113E90, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(9, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(13, 15, 16, 0, 17, 5, 7, 0),
    gsSP2Triangles(1, 0, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 22, 0, 2, 23, 0, 0),
    gsSP2Triangles(7, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(26, 28, 29, 0),
    gsSPVertex(D_04014320_114070, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 1, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 1, 16, 11, 0),
    gsSP2Triangles(17, 2, 18, 0, 18, 19, 17, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 4, 0),
    gsSP2Triangles(23, 4, 3, 0, 2, 17, 0, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_04014520_114270, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(3, 4, 5, 0, 6, 0, 2, 0),
    gsSP2Triangles(6, 2, 3, 0, 7, 8, 0, 0),
    gsSP2Triangles(7, 0, 6, 0, 9, 10, 8, 0),
    gsSP2Triangles(9, 8, 7, 0, 4, 11, 12, 0),
    gsSP2Triangles(4, 12, 13, 0, 14, 15, 16, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP2Triangles(14, 21, 22, 0, 23, 24, 10, 0),
    gsSP2Triangles(23, 10, 9, 0, 25, 26, 24, 0),
    gsSP2Triangles(25, 24, 23, 0, 20, 19, 26, 0),
    gsSP1Triangle(20, 26, 25, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x2A, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040146D0_114420, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 1, 0, 8, 18, 6, 0),
    gsSP2Triangles(19, 20, 21, 0, 7, 6, 22, 0),
    gsSP2Triangles(23, 24, 4, 0, 11, 2, 9, 0),
    gsSP2Triangles(4, 3, 23, 0, 5, 25, 3, 0),
    gsSP2Triangles(18, 8, 26, 0, 26, 27, 18, 0),
    gsSP2Triangles(2, 11, 0, 0, 1, 0, 16, 0),
    gsSP2Triangles(21, 28, 19, 0, 22, 29, 7, 0),
    gsSPEndDisplayList(),
};
