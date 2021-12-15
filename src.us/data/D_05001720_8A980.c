#include <ultra64.h>

Vtx D_05000800_89A60[8] = {
#include "data/inc/D_05000800_89A60.inc.c"
};
Vtx D_05000880_89AE0[31] = {
#include "data/inc/D_05000880_89AE0.inc.c"
};
Vtx D_05000A70_89CD0[31] = {
#include "data/inc/D_05000A70_89CD0.inc.c"
};
Vtx D_05000C60_89EC0[31] = {
#include "data/inc/D_05000C60_89EC0.inc.c"
};
Vtx D_05000E50_8A0B0[31] = {
#include "data/inc/D_05000E50_8A0B0.inc.c"
};
Vtx D_05001040_8A2A0[32] = {
#include "data/inc/D_05001040_8A2A0.inc.c"
};
Vtx D_05001240_8A4A0[10] = {
#include "data/inc/D_05001240_8A4A0.inc.c"
};
Vtx D_050012E0_8A540[32] = {
#include "data/inc/D_050012E0_8A540.inc.c"
};
Vtx D_050014E0_8A740[16] = {
#include "data/inc/D_050014E0_8A740.inc.c"
};
Vtx D_050015E0_8A840[20] = {
#include "data/inc/D_050015E0_8A840.inc.c"
};

extern u8 D_05000000_89260[];

Gfx D_05001720_8A980[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000800_89A60, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_05000000_89260),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05000880_89AE0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 7, 8, 0),
    gsSP2Triangles(0, 9, 10, 0, 11, 1, 12, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 3, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 5, 18, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 7, 21, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 9, 24, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 26, 30, 0),
    gsSPVertex(D_05000A70_89CD0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 0, 0),
    gsSP2Triangles(10, 2, 1, 0, 11, 10, 12, 0),
    gsSP2Triangles(9, 5, 4, 0, 8, 11, 6, 0),
    gsSP2Triangles(5, 13, 3, 0, 4, 0, 9, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 24, 26, 0, 20, 19, 18, 0),
    gsSP2Triangles(23, 22, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_05000C60_89EC0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 1, 9, 5, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 13, 15, 0),
    gsSP2Triangles(13, 20, 21, 0, 14, 13, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 4, 25, 26, 0),
    gsSP2Triangles(16, 6, 8, 0, 27, 28, 29, 0),
    gsSP1Triangle(30, 23, 22, 0),
    gsSPVertex(D_05000E50_8A0B0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 7, 8, 0, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 10, 9, 0, 16, 17, 18, 0),
    gsSP2Triangles(8, 19, 20, 0, 12, 21, 22, 0),
    gsSP2Triangles(23, 9, 24, 0, 1, 8, 20, 0),
    gsSP2Triangles(25, 8, 7, 0, 25, 21, 26, 0),
    gsSP2Triangles(21, 12, 14, 0, 25, 26, 19, 0),
    gsSP2Triangles(27, 28, 7, 0, 1, 15, 2, 0),
    gsSP2Triangles(21, 14, 26, 0, 28, 4, 29, 0),
    gsSP2Triangles(29, 7, 28, 0, 30, 27, 0, 0),
    gsSP1Triangle(4, 6, 22, 0),
    gsSPVertex(D_05001040_8A2A0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 5, 15, 0),
    gsSP2Triangles(15, 13, 12, 0, 1, 16, 17, 0),
    gsSP2Triangles(0, 18, 1, 0, 6, 8, 19, 0),
    gsSP2Triangles(17, 20, 14, 0, 16, 20, 17, 0),
    gsSP2Triangles(7, 21, 8, 0, 22, 19, 23, 0),
    gsSP2Triangles(3, 20, 24, 0, 19, 25, 23, 0),
    gsSP2Triangles(26, 19, 22, 0, 27, 6, 26, 0),
    gsSP2Triangles(28, 29, 30, 0, 1, 17, 31, 0),
    gsSPVertex(D_05001240_8A4A0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 1, 0, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 7, 1, 9, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x26, 0xA6, 0xD8, 0xFF),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPVertex(D_050012E0_8A540, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 7, 0, 7, 4, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 11, 12, 13, 0),
    gsSP2Triangles(0, 14, 15, 0, 16, 1, 0, 0),
    gsSP2Triangles(17, 1, 18, 0, 19, 20, 0, 0),
    gsSP2Triangles(13, 2, 21, 0, 14, 10, 9, 0),
    gsSP2Triangles(10, 12, 11, 0, 2, 22, 21, 0),
    gsSP2Triangles(23, 12, 10, 0, 2, 12, 0, 0),
    gsSP2Triangles(0, 15, 19, 0, 8, 4, 24, 0),
    gsSP2Triangles(24, 4, 3, 0, 25, 10, 14, 0),
    gsSP2Triangles(12, 2, 13, 0, 26, 15, 27, 0),
    gsSP2Triangles(0, 20, 16, 0, 1, 16, 18, 0),
    gsSP2Triangles(28, 4, 29, 0, 16, 20, 30, 0),
    gsSP2Triangles(15, 14, 27, 0, 5, 4, 31, 0),
    gsSPVertex(D_050014E0_8A740, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 1, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 3, 5, 0, 12, 13, 11, 0),
    gsSP2Triangles(5, 4, 14, 0, 4, 15, 14, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x09, 0xB2, 0xF5, 0xFF),
    gsSPVertex(D_050015E0_8A840, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 1, 0, 0),
    gsSP2Triangles(7, 10, 11, 0, 12, 6, 8, 0),
    gsSP2Triangles(8, 7, 11, 0, 13, 6, 12, 0),
    gsSP2Triangles(11, 10, 14, 0, 5, 4, 15, 0),
    gsSP2Triangles(2, 13, 12, 0, 4, 9, 15, 0),
    gsSP2Triangles(10, 16, 14, 0, 14, 16, 17, 0),
    gsSP2Triangles(16, 18, 17, 0, 19, 3, 5, 0),
    gsSP2Triangles(15, 9, 0, 0, 1, 13, 2, 0),
    gsSPEndDisplayList(),
};
