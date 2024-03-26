#include <ultra64.h>


Vtx D_05000A50_B5320[8] = {
#include "data/inc/D_05000A50_B5320.inc.c"
};
Vtx D_05000AD0_B53A0[30] = {
#include "data/inc/D_05000AD0_B53A0.inc.c"
};
Vtx D_05000CB0_B5580[32] = {
#include "data/inc/D_05000CB0_B5580.inc.c"
};
Vtx D_05000EB0_B5780[31] = {
#include "data/inc/D_05000EB0_B5780.inc.c"
};
Vtx D_050010A0_B5970[31] = {
#include "data/inc/D_050010A0_B5970.inc.c"
};
Vtx D_05001290_B5B60[8] = {
#include "data/inc/D_05001290_B5B60.inc.c"
};
Vtx D_05001310_B5BE0[30] = {
#include "data/inc/D_05001310_B5BE0.inc.c"
};
Vtx D_050014F0_B5DC0[15] = {
#include "data/inc/D_050014F0_B5DC0.inc.c"
};
Vtx D_050015E0_B5EB0[30] = {
#include "data/inc/D_050015E0_B5EB0.inc.c"
};
Vtx D_050017C0_B6090[30] = {
#include "data/inc/D_050017C0_B6090.inc.c"
};
Vtx D_050019A0_B6270[31] = {
#include "data/inc/D_050019A0_B6270.inc.c"
};
Vtx D_05001B90_B6460[30] = {
#include "data/inc/D_05001B90_B6460.inc.c"
};
Vtx D_05001D70_B6640[30] = {
#include "data/inc/D_05001D70_B6640.inc.c"
};
Vtx D_05001F50_B6820[21] = {
#include "data/inc/D_05001F50_B6820.inc.c"
};
Vtx D_050020A0_B6970[30] = {
#include "data/inc/D_050020A0_B6970.inc.c"
};
Vtx D_05002280_B6B50[20] = {
#include "data/inc/D_05002280_B6B50.inc.c"
};
Vtx D_050023C0_B6C90[31] = {
#include "data/inc/D_050023C0_B6C90.inc.c"
};
Vtx D_050025B0_B6E80[30] = {
#include "data/inc/D_050025B0_B6E80.inc.c"
};
Vtx D_05002790_B7060[31] = {
#include "data/inc/D_05002790_B7060.inc.c"
};
Vtx D_05002980_B7250[30] = {
#include "data/inc/D_05002980_B7250.inc.c"
};
Vtx D_05002B60_B7430[32] = {
#include "data/inc/D_05002B60_B7430.inc.c"
};
Vtx D_05002D60_B7630[30] = {
#include "data/inc/D_05002D60_B7630.inc.c"
};
Vtx D_05002F40_B7810[32] = {
#include "data/inc/D_05002F40_B7810.inc.c"
};
Vtx D_05003140_B7A10[32] = {
#include "data/inc/D_05003140_B7A10.inc.c"
};
Vtx D_05003340_B7C10[31] = {
#include "data/inc/D_05003340_B7C10.inc.c"
};
Vtx D_05003530_B7E00[32] = {
#include "data/inc/D_05003530_B7E00.inc.c"
};
Vtx D_05003730_B8000[31] = {
#include "data/inc/D_05003730_B8000.inc.c"
};
Vtx D_05003920_B81F0[30] = {
#include "data/inc/D_05003920_B81F0.inc.c"
};
Vtx D_05003B00_B83D0[31] = {
#include "data/inc/D_05003B00_B83D0.inc.c"
};
Vtx D_05003CF0_B85C0[30] = {
#include "data/inc/D_05003CF0_B85C0.inc.c"
};
Vtx D_05003ED0_B87A0[30] = {
#include "data/inc/D_05003ED0_B87A0.inc.c"
};
Vtx D_050040B0_B8980[31] = {
#include "data/inc/D_050040B0_B8980.inc.c"
};
Vtx D_050042A0_B8B70[32] = {
#include "data/inc/D_050042A0_B8B70.inc.c"
};
Vtx D_050044A0_B8D70[32] = {
#include "data/inc/D_050044A0_B8D70.inc.c"
};
Vtx D_050046A0_B8F70[8] = {
#include "data/inc/D_050046A0_B8F70.inc.c"
};
Vtx D_05004720_B8FF0[8] = {
#include "data/inc/D_05004720_B8FF0.inc.c"
};
Vtx D_050047A0_B9070[4] = {
#include "data/inc/D_050047A0_B9070.inc.c"
};
Vtx D_050047E0_B90B0[28] = {
#include "data/inc/D_050047E0_B90B0.inc.c"
};
Vtx D_050049A0_B9270[24] = {
#include "data/inc/D_050049A0_B9270.inc.c"
};
Vtx D_05004B20_B93F0[31] = {
#include "data/inc/D_05004B20_B93F0.inc.c"
};
Vtx D_05004D10_B95E0[8] = {
#include "data/inc/D_05004D10_B95E0.inc.c"
};
Vtx D_05004D90_B9660[8] = {
#include "data/inc/D_05004D90_B9660.inc.c"
};

extern u8 img_D_05000250_B4B20_rgba16__png[];

Gfx D_05004E10_B96E0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000A50_B5320, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_D_05000250_B4B20_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05000AD0_B53A0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05000CB0_B5580, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 1, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05000EB0_B5780, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_050010A0_B5970, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 7, 0, 8, 9, 7, 0),
    gsSP2Triangles(10, 9, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 20, 0, 23, 24, 18, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 27, 26, 0),
    gsSP1Triangle(29, 28, 30, 0),
    gsSPVertex(D_05001290_B5B60, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 5, 0, 7, 0),
    gsSP1Triangle(2, 7, 0, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x2E, 0xFF, 0xFF),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_05001310_B5BE0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_050014F0_B5DC0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_050015E0_B5EB0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 4, 0, 7, 6, 3, 0),
    gsSP2Triangles(3, 8, 7, 0, 3, 5, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 26, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_050017C0_B6090, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_050019A0_B6270, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 17, 21, 15, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 25, 23, 0),
    gsSP2Triangles(26, 25, 22, 0, 22, 27, 26, 0),
    gsSP2Triangles(22, 24, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_05001B90_B6460, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 0, 5, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 9, 12, 10, 0),
    gsSP2Triangles(13, 12, 9, 0, 9, 14, 13, 0),
    gsSP2Triangles(9, 11, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 18, 21, 19, 0),
    gsSP2Triangles(22, 21, 18, 0, 18, 23, 22, 0),
    gsSP2Triangles(18, 20, 23, 0, 24, 25, 26, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_05001D70_B6640, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05001F50_B6820, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP1Triangle(18, 19, 20, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_050020A0_B6970, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 2, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(4, 3, 8, 0, 9, 8, 1, 0),
    gsSP2Triangles(2, 6, 0, 0, 8, 9, 4, 0),
    gsSP2Triangles(1, 0, 9, 0, 7, 5, 6, 0),
    gsSP1Quadrangle(5, 4, 9, 6, 0),
    gsSP2Triangles(9, 0, 6, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 12, 17, 0),
    gsSP2Triangles(15, 17, 13, 0, 14, 13, 18, 0),
    gsSP2Triangles(19, 18, 11, 0, 12, 16, 10, 0),
    gsSP2Triangles(18, 19, 14, 0, 11, 10, 19, 0),
    gsSP2Triangles(17, 15, 16, 0, 15, 14, 19, 0),
    gsSP2Triangles(15, 19, 16, 0, 19, 10, 16, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 22, 27, 0, 25, 27, 23, 0),
    gsSP2Triangles(24, 23, 28, 0, 29, 28, 21, 0),
    gsSP2Triangles(22, 26, 20, 0, 28, 29, 24, 0),
    gsSP2Triangles(21, 20, 29, 0, 27, 25, 26, 0),
    gsSP1Quadrangle(25, 24, 29, 26, 0),
    gsSP1Triangle(29, 20, 26, 0),
    gsSPVertex(D_05002280_B6B50, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 2, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(4, 3, 8, 0, 9, 8, 1, 0),
    gsSP2Triangles(2, 6, 0, 0, 8, 9, 4, 0),
    gsSP2Triangles(1, 0, 9, 0, 7, 5, 6, 0),
    gsSP1Quadrangle(5, 4, 9, 6, 0),
    gsSP2Triangles(9, 0, 6, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 12, 17, 0),
    gsSP2Triangles(15, 17, 13, 0, 14, 13, 18, 0),
    gsSP2Triangles(19, 18, 11, 0, 12, 16, 10, 0),
    gsSP2Triangles(18, 19, 14, 0, 11, 10, 19, 0),
    gsSP2Triangles(17, 15, 16, 0, 15, 14, 19, 0),
    gsSP2Triangles(15, 19, 16, 0, 19, 10, 16, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_050023C0_B6C90, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 11, 14, 15, 0),
    gsSP2Triangles(14, 16, 17, 0, 16, 2, 18, 0),
    gsSP2Triangles(6, 19, 20, 0, 9, 21, 22, 0),
    gsSP2Triangles(12, 23, 24, 0, 15, 25, 26, 0),
    gsSP2Triangles(17, 27, 28, 0, 18, 29, 30, 0),
    gsSPVertex(D_050025B0_B6E80, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05002790_B7060, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 1, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 2, 27, 0),
    gsSP2Triangles(6, 28, 7, 0, 29, 25, 30, 0),
    gsSPVertex(D_05002980_B7250, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 2, 20, 21, 0),
    gsSP2Triangles(0, 21, 22, 0, 23, 22, 19, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05002B60_B7430, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 7, 14, 0),
    gsSP2Triangles(0, 14, 9, 0, 15, 9, 8, 0),
    gsSP2Triangles(16, 8, 7, 0, 1, 10, 17, 0),
    gsSP2Triangles(2, 17, 12, 0, 18, 12, 11, 0),
    gsSP2Triangles(19, 11, 10, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05002D60_B7630, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(16, 8, 18, 0, 19, 20, 13, 0),
    gsSP2Triangles(21, 22, 23, 0, 22, 18, 24, 0),
    gsSP2Triangles(25, 26, 20, 0, 27, 28, 29, 0),
    gsSP2Triangles(28, 24, 7, 0, 10, 14, 26, 0),
    gsSP2Triangles(16, 15, 8, 0, 11, 7, 6, 0),
    gsSP2Triangles(17, 13, 12, 0, 14, 10, 9, 0),
    gsSP2Triangles(22, 21, 18, 0, 28, 27, 24, 0),
    gsSP2Triangles(23, 20, 19, 0, 29, 26, 25, 0),
    gsSPVertex(D_05002F40_B7810, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 2, 1, 0),
    gsSP2Triangles(3, 0, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 19, 18, 20, 0),
    gsSP2Triangles(21, 11, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05003140_B7A10, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 15, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 25, 0),
    gsSP2Triangles(28, 0, 29, 0, 30, 3, 31, 0),
    gsSPVertex(D_05003340_B7C10, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(8, 7, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(8, 11, 9, 0, 12, 13, 14, 0),
    gsSP2Triangles(13, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(18, 16, 15, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(26, 29, 30, 0),
    gsSPVertex(D_05003530_B7E00, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 0, 17, 0, 18, 3, 19, 0),
    gsSP2Triangles(20, 6, 5, 0, 21, 8, 7, 0),
    gsSP2Triangles(22, 11, 10, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05003730_B8000, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 17, 19, 0, 20, 19, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05003920_B81F0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 4, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 18, 0),
    gsSP2Triangles(22, 23, 21, 0, 24, 19, 23, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 27, 29, 0),
    gsSPVertex(D_05003B00_B83D0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(7, 2, 1, 0, 6, 12, 2, 0),
    gsSP2Triangles(13, 14, 12, 0, 8, 1, 14, 0),
    gsSP2Triangles(10, 0, 15, 0, 9, 16, 0, 0),
    gsSP2Triangles(17, 18, 16, 0, 11, 15, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_05003CF0_B85C0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 8, 10, 0),
    gsSP2Triangles(11, 10, 12, 0, 13, 12, 7, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 13, 18, 0),
    gsSP2Triangles(19, 18, 15, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 19, 24, 0, 25, 24, 21, 0),
    gsSP2Triangles(26, 9, 27, 0, 28, 25, 29, 0),
    gsSPVertex(D_05003ED0_B87A0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 3, 5, 7, 0),
    gsSP2Triangles(1, 6, 4, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 9, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 13, 17, 0, 18, 19, 16, 0),
    gsSP2Triangles(19, 20, 21, 0, 14, 22, 23, 0),
    gsSP2Triangles(22, 8, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(20, 28, 29, 0),
    gsSPVertex(D_050040B0_B8980, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 14, 0, 20, 17, 16, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 24, 0),
    gsSP2Triangles(1, 24, 25, 0, 5, 4, 25, 0),
    gsSP2Triangles(8, 7, 26, 0, 11, 10, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_050042A0_B8B70, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(8, 10, 11, 0, 12, 13, 14, 0),
    gsSP1Quadrangle(12, 14, 15, 16, 0),
    gsSP1Quadrangle(12, 16, 17, 18, 0),
    gsSP2Triangles(12, 18, 10, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 18, 0, 22, 23, 24, 0),
    gsSP1Quadrangle(22, 24, 25, 26, 0),
    gsSP1Quadrangle(22, 26, 27, 11, 0),
    gsSP2Triangles(22, 11, 21, 0, 28, 29, 30, 0),
    gsSP1Triangle(28, 30, 31, 0),
    gsSPVertex(D_050044A0_B8D70, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 9, 17, 18, 0),
    gsSP1Quadrangle(19, 20, 21, 22, 0),
    gsSP1Quadrangle(20, 23, 24, 21, 0),
    gsSP1Quadrangle(25, 26, 27, 28, 0),
    gsSP1Quadrangle(29, 1, 30, 31, 0),
    gsSPVertex(D_050046A0_B8F70, 8, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x20, 0x10, 0x0A, 0xFF),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_05004720_B8FF0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 2, 6, 0),
    gsSP2Triangles(3, 0, 7, 0, 6, 2, 1, 0),
    gsSP2Triangles(2, 7, 0, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 5, 3, 0, 1, 4, 6, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x2E, 0xFF, 0xFF),
    gsSPVertex(D_050047A0_B9070, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(1, 3, 2, 0, 3, 0, 2, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x7A, 0x81, 0x9D, 0xFF),
    gsSPVertex(D_050047E0_B90B0, 28, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 1, 0, 0, 2, 1, 4, 0),
    gsSP2Triangles(4, 5, 2, 0, 3, 2, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 3, 6, 0, 0),
    gsSP2Triangles(5, 4, 0, 0, 0, 6, 5, 0),
    gsSP2Triangles(7, 8, 9, 0, 9, 10, 7, 0),
    gsSP2Triangles(11, 8, 7, 0, 9, 8, 11, 0),
    gsSP2Triangles(11, 12, 9, 0, 10, 9, 12, 0),
    gsSP2Triangles(12, 13, 10, 0, 10, 13, 7, 0),
    gsSP2Triangles(12, 11, 7, 0, 7, 13, 12, 0),
    gsSP2Triangles(14, 15, 16, 0, 16, 17, 14, 0),
    gsSP2Triangles(18, 15, 14, 0, 16, 15, 18, 0),
    gsSP2Triangles(18, 19, 16, 0, 17, 16, 19, 0),
    gsSP2Triangles(19, 20, 17, 0, 17, 20, 14, 0),
    gsSP2Triangles(19, 18, 14, 0, 14, 20, 19, 0),
    gsSP2Triangles(21, 22, 23, 0, 23, 24, 21, 0),
    gsSP2Triangles(25, 22, 21, 0, 23, 22, 25, 0),
    gsSP2Triangles(25, 26, 23, 0, 24, 23, 26, 0),
    gsSP2Triangles(26, 27, 24, 0, 24, 27, 21, 0),
    gsSP2Triangles(26, 25, 21, 0, 21, 27, 26, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x67, 0x32, 0x21, 0xFF),
    gsSPVertex(D_050049A0_B9270, 24, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 3, 2, 0, 1, 5, 4, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 0, 3, 0),
    gsSP2Triangles(5, 3, 4, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 8, 9, 0, 10, 9, 8, 0),
    gsSP1Quadrangle(7, 11, 10, 8, 0),
    gsSP1Quadrangle(11, 6, 9, 10, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 15, 14, 0, 13, 17, 16, 0),
    gsSP2Triangles(13, 16, 14, 0, 17, 12, 15, 0),
    gsSP2Triangles(17, 15, 16, 0, 18, 19, 20, 0),
    gsSP2Triangles(18, 20, 21, 0, 22, 21, 20, 0),
    gsSP1Quadrangle(19, 23, 22, 20, 0),
    gsSP1Quadrangle(23, 18, 21, 22, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFC, 0xD8, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05004B20_B93F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 1, 2, 0, 2, 5, 4, 0),
    gsSP2Triangles(6, 1, 2, 0, 2, 7, 6, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 9, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 13, 14, 0, 14, 17, 16, 0),
    gsSP2Triangles(18, 13, 14, 0, 14, 19, 18, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 23, 20, 0),
    gsSP2Triangles(24, 21, 22, 0, 22, 25, 24, 0),
    gsSP2Triangles(26, 21, 22, 0, 22, 27, 26, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05004D10_B95E0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(0, 5, 3, 0, 6, 4, 0, 0),
    gsSP1Triangle(0, 7, 6, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x23, 0x11, 0x0B, 0xFF),
    gsSPVertex(D_05004D90_B9660, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
