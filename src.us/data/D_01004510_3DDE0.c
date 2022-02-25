#include <ultra64.h>

Gfx D_01004510_3DDE0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
    gsDPSetTextureLOD(G_TL_LOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1),
    gsDPSetTileSize(1, 0, 0, 0x003C, 0x003C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2),
    gsDPSetTileSize(2, 0, 0, 0x001C, 0x001C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3),
    gsDPSetTileSize(3, 0, 0, 0x000C, 0x000C),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4),
    gsDPSetTileSize(4, 0, 0, 0x0004, 0x0004),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5),
    gsDPSetTileSize(5, 0, 0, 0, 0),
    gsSPEndDisplayList(),
};
