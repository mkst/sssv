#include <ultra64.h>

#include "common.h"

void load_1_tile(u8 *tlut, s32 timg) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(
        /* pkt      */ D_801D9E88++,
        /* count    */ 16,
        /* tmemAddr */ 0x110,
        /* dram     */ tlut);

    // customised
    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ timg & 0x1FFFFFFF,
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

void load_2_tiles(u8 *tlut1, u8 *tlut2, s32 timg) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, tlut1);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0120, tlut2);

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ timg & 0x1FFFFFFF,
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
void load_3_tiles(u8 *tlut1, u8 *tlut2, u8 *tlut3, s32 timg) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, tlut1);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0120, tlut2);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0130, tlut2); // bug?

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ timg & 0x1FFFFFFF,
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

void func_80356BD8_768288(u8 *tlut, u8 *img_base, s16 id) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, tlut);

    gDPSetTextureImage(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, ((id << 7) + img_base));
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(D_801D9E88++);
    gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*15, 4*15);
}

void func_80356D84_768434(u8 *tlut, s32 timg) {
    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, tlut);

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ timg & 0x1FFFFFFF,
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

void func_80356F64_768614(u8* tlut1, u8* tlut2, s32 timg) {

    gDPLoadSync(D_801D9E88++);

    gDPLoadTLUT(D_801D9E88++, 16, 0x0100, tlut1);
    gDPLoadTLUT(D_801D9E88++, 16, 0x0110, tlut2);

    gDPLoadTextureBlock2(
        /* pkt    */ D_801D9E88++,
        /* timg   */ timg & 0x1FFFFFFF,
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
