#include <ultra64.h>

#include "common.h"

// 1 tile
void func_80356410_767AC0(s32 arg0, s32 arg1) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x110, arg0);

    // customised
    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ arg1 & 0x1FFFFFFF,
        /* fmt    */ G_IM_FMT_CI,
        /* line   */ 2,
        /* siz    */ G_IM_SIZ_16b,
        /* width  */ 32,
        /* height */ 32,
        /* pal    */ 1,
        /* cms    */ G_TX_NOMIRROR | G_TX_CLAMP,
        /* cmt    */ G_TX_NOMIRROR | G_TX_WRAP,
        /* masks  */ G_TX_NOMASK,
        /* maskt  */ 2,
        /* shifts */ G_TX_NOLOD,
        /* shiftt */ G_TX_NOLOD
    );

    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
}

// 2 tiles
void func_803565D4_767C84(s32 arg0, s32 arg1, s32 arg2) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, arg0);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0120, arg1);

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ arg2 & 0x1FFFFFFF,
        /* fmt    */ G_IM_FMT_CI,
        /* line   */ 2,
        /* siz    */ G_IM_SIZ_16b,
        /* width  */ 32,
        /* height */ 64,
        /* pal    */ 1,
        /* cms    */ G_TX_NOMIRROR | G_TX_CLAMP,
        /* cmt    */ G_TX_NOMIRROR | G_TX_WRAP,
        /* masks  */ G_TX_NOMASK,
        /* maskt  */ 2,
        /* shifts */ G_TX_NOLOD,
        /* shiftt */ G_TX_NOLOD
    );

    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0040,               1, 2, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
}

// 3 tiles (unused?)
void func_80356870_767F20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, arg0);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0120, arg1);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0130, arg1); // bug?

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ arg3 & 0x1FFFFFFF,
        /* fmt    */ G_IM_FMT_CI,
        /* line   */ 2,
        /* siz    */ G_IM_SIZ_16b,
        /* width  */ 32,
        /* height */ 96,
        /* pal    */ 1,
        /* cms    */ G_TX_NOMIRROR | G_TX_CLAMP,
        /* cmt    */ G_TX_NOMIRROR | G_TX_WRAP,
        /* masks  */ G_TX_NOMASK,
        /* maskt  */ 2,
        /* shifts */ G_TX_NOLOD,
        /* shiftt */ G_TX_NOLOD
    );

    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0040,               1, 1, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0080,               2, 1, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
}

void func_80356BD8_768288(s32 arg0, s32 arg1, s16 arg2) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, arg0);

    gDPSetTextureImage(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, ((arg2 << 7) + arg1));
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(D_801D9E88++);
    gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*15, 4*15);
}

void func_80356D84_768434(s32 arg0, s32 arg1) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, arg0);

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ arg1 & 0x1FFFFFFF,
        /* fmt    */ G_IM_FMT_CI,
        /* line   */ 4,
        /* siz    */ G_IM_SIZ_16b,
        /* width  */ 64,
        /* height */ 64,
        /* pal    */ 1,
        /* cms    */ G_TX_NOMIRROR | G_TX_CLAMP,
        /* cmt    */ G_TX_NOMIRROR | G_TX_WRAP,
        /* masks  */ G_TX_NOMASK,
        /* maskt  */ 2,
        /* shifts */ G_TX_NOLOD,
        /* shiftt */ G_TX_NOLOD
    );

    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0x0080,               1, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
}

void func_80356F64_768614(s32 arg0, s32 arg1, s32 arg2) {

    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0100, arg0);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, arg1);

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ arg2 & 0x1FFFFFFF,
        /* fmt    */ G_IM_FMT_CI,
        /* line   */ 3,
        /* siz    */ G_IM_SIZ_16b,
        /* width  */ 48,
        /* height */ 64,
        /* pal    */ 1,
        /* cms    */ G_TX_NOMIRROR | G_TX_CLAMP,
        /* cmt    */ G_TX_NOMIRROR | G_TX_WRAP,
        /* masks  */ G_TX_NOMASK,
        /* maskt  */ 2,
        /* shifts */ G_TX_NOLOD,
        /* shiftt */ G_TX_NOLOD
    );

    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 3, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 3, 0x0060,               1, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
}
