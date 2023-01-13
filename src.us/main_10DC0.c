#include <ultra64.h>

#include "common.h"

#if 0
void func_801356C0(s32 x, s32 y, s32 x_size, s32 y_size, Gfx **dl, u8 *arg5, f32 sizeX, f32 sizeY, u8 depth) {
    f32 var_f0;
    f32 var_f2;
    s16 temp_t2;
    s16 temp_t6;
    s16 temp_t7;
    s16 temp_t9;
    s16 var_a0;
    s16 var_a0_2;
    s16 var_v1;
    s16 var_v1_2;
    s32 temp_f10;
    s32 temp_f16;
    s32 temp_t6_2;
    s32 temp_t6_3;
    s32 temp_t8;
    s32 temp_t8_2;
    s32 var_t0;
    s32 var_t6;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;

    gDPPipeSync((*dl)++);

    switch (depth) {
    case 16:
        gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, arg5);
        gDPLoadSync((*dl)++);

        gDPLoadTextureBlock((*dl)++, arg5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        break;
    case 8:
        gDPLoadSync((*dl)++);
        gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 1, arg5);

        gDPLoadTextureBlock((*dl)++, arg5, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        break;
    default:
        rmonPrintf("Wrong texture size"); //D_8015B050);
    }

    temp_t9 = x << 2;
    temp_t2 = y << 2;
    temp_t7 = (x + x_size) << 2;
    temp_t6 = (y + y_size) << 2;

#if 0
    if (temp_t9 < 0) {
        var_f2 = 16384.0f / (sizeX / 2.0f);
        if ((s16) var_f2 < 0) {
            var_t0 = MAX(0, (s32) (temp_t9 * (s16) var_f2) >> 7);
        } else {
            var_t0 = MIN(0, (s32) (temp_t9 * (s16) var_f2) >> 7);
        }
    } else {
        var_t0 = 0;
        var_f2 = 16384.0f / (sizeX / 2.0f);
    }

    if (temp_t2 < 0) {
        var_f0 = 16384.0f / (sizeY / 2.0f);
        if ((s16) var_f0 < 0) {
            var_v1_4 = MAX(0, (s32) (temp_t2 * (s16) var_f0) >> 7);
        } else {
            var_v1_4 = MIN(0, (s32) (temp_t2 * (s16) var_f0) >> 7);
        }
    } else {
        var_v1_4 = 0;
        var_f0 = 16384.0f / (sizeY / 2.0f);
    }
#endif

    gSPTextureRectangle(
    /* pkt  */ (*dl)++,
    /* xl   */ MAX(0, temp_t9),
    /* yl   */ MAX(0, temp_t2),
    /* xh   */ MAX(0, temp_t7),
    /* yh   */ MAX(0, temp_t6),
    /* tile */ G_TX_RENDERTILE,
    /* s    */ -((temp_t9 < 0) ? ((16384.0f / (sizeY / 2.0f)) < 0 ? MAX(0, (s32) (temp_t2 * (s16) var_f0) >> 7) : MIN(0, (s32) (temp_t2 * (s16) var_f0) >> 7)) : 0),
    /* t    */ -((temp_t2 < 0) ? ((16384.0f / (sizeY / 2.0f)) < 0 ? MAX(0, (s32) (temp_t2 * (s16) var_f0) >> 7) : MIN(0, (s32) (temp_t2 * (s16) var_f0) >> 7)) : 0),
    /* dsdx */ 16384.0f / (sizeX / 2.0f),
    /* dtdy */ 16384.0f / (sizeY / 2.0f));

#if 0
    // this is also *completely* wrong
    gSPTextureRectangle(
        (*dl)++,
        MAX(x * 4, 0),
        MAX(y * 4, 0),
        MAX((x + x_size) * 4, 0),
        MAX((y + y_size) * 4, 0),
        G_TX_RENDERTILE,
        MAX(MAX(x * 4, 0) * (s16)(16384.0f / (sizeX / 2.0f)) >> 7, 0),
        MAX(MAX(y * 4, 0) * (s16)(16384.0f / (sizeY / 2.0f)) >> 7, 0),
        16384.0f / (sizeX / 2.0f),
        16384.0f / (sizeY / 2.0f)
        );
#endif

    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_10DC0/func_801356C0.s")
#endif

// draw chunked images (e.g. 200 credz)
#if 0
// miles away
void func_80135CD8(u32 arg0, u32 arg1, u32 arg2, u32 arg3, Gfx **dl, u8 *arg5) {
    u32 sp8C;

    s32 yOffset;
    s16 var_v1_4;

    s16 tmpx;
    s16 tmpy;

    s32 x;
    s32 y;
    void *imgAddr;

    gDPPipeSync((*dl)++);

    y = arg1;
    sp8C = arg2 >> 5;

    while (y < (arg1 + arg3)) {

        if ((arg1 + arg3) < (y + 32)) {
            yOffset = (arg1 - y) + arg3;
        } else {
            yOffset = 32;
        }

        x = arg0;
        while (x < (arg0 + arg2)) {
            s32 xx;
            s32 yy;
            xx = x - arg0;
            yy = y - arg1;

            imgAddr = arg5 + (((((s8) (yy / 32) * sp8C) + ((xx * x) / 32) & 0xFF)) << 0xB);

            gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, imgAddr);
            gDPLoadSync((*dl)++);

            gDPLoadTextureBlock(
            /* pkt    */ (*dl)++,
            /* timg   */ imgAddr,
            /* fmt    */ G_IM_FMT_RGBA,
            /* siz    */ G_IM_SIZ_16b,
            /* width  */ 32,
            /* height */ 32,
            /* pal    */ 0,
            /* cms    */ G_TX_NOMIRROR | G_TX_CLAMP,
            /* cmt    */ G_TX_NOMIRROR | G_TX_CLAMP,
            /* masks  */ G_TX_NOMASK,
            /* maskt  */ G_TX_NOMASK,
            /* shifts */ G_TX_NOLOD,
            /* shiftt */ G_TX_NOLOD);

            tmpx = x << 2;
            tmpy = y << 2;

            gSPTextureRectangle(
            /* pkt  */  (*dl)++,
            /* xl   */  MIN(0, tmpx),
            /* yl   */  MIN(0, y << 2), // urgh
            /* xh   */  MIN(0, tmpx),
            /* yh   */  MIN(0, ((y + yOffset) << 2)),
            /* tile */  G_TX_RENDERTILE,
            /* s    */  -((tmpx < 0) ? MAX(0, (tmpx << 0xA) >> 7) : 0),
            /* t    */  -((tmpy < 0) ? MAX(0, (tmpy << 0xA) >> 7) : 0),
            /* dsdx */  0x400,
            /* dtdy */  0x400);

            x += 0x20;
        }
        y += 0x20;
    }
    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_10DC0/func_80135CD8.s")
#endif

void func_801360C8(Gfx **dl, uSprite *arg1, u16 width, u16 height, u16 scale_x, u16 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y, u16 z) {
    gDPPipeSync((*dl)++);
    gDPSetPrimDepth((*dl)++, z, 0);

    guSprite2DInit(&D_80204278->sprites[D_80204278->usedSprites], arg1, 0, width, width, height, 0, 2, 0, 0);
    gSPSprite2DBase((*dl)++, OS_K0_TO_PHYSICAL(&D_80204278->sprites[D_80204278->usedSprites]));
    gSPSprite2DScaleFlip((*dl)++, (width / (f32)scale_x) * 1024.0f, (height / (f32)scale_y) * 1024.0f, flip_x, flip_y);
    gSPSprite2DDraw((*dl)++, p_screen_x * 4, p_screen_y * 4);

    D_80204278->usedSprites += 1;
    gDPPipeSync((*dl)++);
}

void func_80136418(Gfx **dl, u8 color) {
    gSPLoadUcodeEx((*dl)++, &D_8014E300, &D_8015C750, 2048);
    gDPPipeSync((*dl)++);
    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));

    gSPViewport((*dl)++, &D_80152EA8);
    gSPSetGeometryMode((*dl)++, G_ZBUFFER);
    gSPClipRatio((*dl)++, FRUSTRATIO_4);

    gSPDisplayList((*dl)++, &D_801584A0);

    gDPSetPrimColor((*dl)++, 0, 0, color, color, color, color);
    gDPSetDepthSource((*dl)++, G_ZS_PRIM);
    gDPSetRenderMode((*dl)++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
    gDPSetTextureFilter((*dl)++, G_TF_AVERAGE);

    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void func_801366BC(Gfx **dl, u8 r, u8 g, u8 b, u8 a) {
    gDPPipeSync((*dl)++);

    gSPLoadUcodeEx((*dl)++, &D_8014E300, &D_8015C750, 2048);
    gDPPipeSync((*dl)++);

    load_segments(dl, D_80204278);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gSPViewport((*dl)++, &D_80152EA8);
    gSPClipRatio((*dl)++, FRUSTRATIO_4);

    gSPDisplayList((*dl)++, &D_801584A0);
    gDPSetPrimColor((*dl)++, 0, 0, r, g, b, a);
    gDPSetTextureFilter((*dl)++, G_TF_AVERAGE);

    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void draw_sprite(Gfx **dl, uSprite *sprite, u16 width, u16 height, u16 scale_x, u16 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y, u8 depth) {
    gDPPipeSync((*dl)++);

    switch (depth) {
    case 8:
        guSprite2DInit(&D_80204278->sprites[D_80204278->usedSprites], sprite, 0, width, width, height, G_IM_FMT_I, G_IM_SIZ_8b, 0, 0);
        break;
    case 16:
        guSprite2DInit(&D_80204278->sprites[D_80204278->usedSprites], sprite, 0, width, width, height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0);
        break;
    }

    gSPSprite2DBase((*dl)++, OS_K0_TO_PHYSICAL(&D_80204278->sprites[D_80204278->usedSprites]));
    gSPSprite2DScaleFlip((*dl)++, (width / (f32)scale_x) * 1024.0f, (height / (f32)scale_y) * 1024.0f, flip_x, flip_y);
    gSPSprite2DDraw((*dl)++, p_screen_x * 4, p_screen_y * 4);

    D_80204278->usedSprites += 1;
}
