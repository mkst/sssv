#include <ultra64.h>

Vtx D_05005210_8E470[31] = {
#include "data/inc/D_05005210_8E470.inc.c"
};
Vtx D_05005400_8E660[31] = {
#include "data/inc/D_05005400_8E660.inc.c"
};
Vtx D_050055F0_8E850[6] = {
#include "data/inc/D_050055F0_8E850.inc.c"
};
Vtx D_05005650_8E8B0[30] = {
#include "data/inc/D_05005650_8E8B0.inc.c"
};
Vtx D_05005830_8EA90[4] = {
#include "data/inc/D_05005830_8EA90.inc.c"
};

extern u8 D_05004210_8D470[];
extern u8 D_05004A10_8DC70[];

Gfx D_05005870_8EAD0[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_05004210_8D470),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05005210_8E470, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05005400_8E660, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 13, 29, 11, 0),
    gsSP1Triangle(19, 30, 17, 0),
    gsSPVertex(D_050055F0_8E850, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_05004A10_8DC70),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(1, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_05005650_8E8B0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 0, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 8, 19, 6, 0),
    gsSP2Triangles(12, 20, 10, 0, 18, 21, 16, 0),
    gsSP2Triangles(22, 23, 24, 0, 24, 25, 22, 0),
    gsSP2Triangles(26, 27, 28, 0, 28, 29, 26, 0),
    gsSPVertex(D_05005830_8EA90, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
