#include <ultra64.h>

#include "common.h"

#if 0
void func_801356C0(s32 x, s32 y, s32 x_size, s32 y_size, Gfx **dl, u8 *img, f32 sizeX, f32 sizeY, u8 depth) {

    s16 xl;
    s16 yl;

    gDPPipeSync((*dl)++);

    switch (depth) {
    case 16:
        gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img);
        gDPLoadSync((*dl)++);

        gDPLoadTextureBlock((*dl)++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        break;
    case 8:
        gDPLoadSync((*dl)++);
        gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 1, img);

        gDPLoadTextureBlock((*dl)++, img, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        break;
    default:
        rmonPrintf("Wrong texture size");
    }


    xl = x * 4;
    yl = y * 4;

    gSPScisTextureRectangle(
    /* gdl  */ (*dl)++,
    /* xl   */ xl,
    /* yl   */ yl,
    /* xh   */ (x + x_size) * 4,
    /* yh   */ (y + y_size) * 4,
    /* tile */ G_TX_RENDERTILE,
    /* s    */ 0,
    /* t    */ 0,
    /* dsdx */ 16384.0f / (sizeX / 2),
    /* dtdy */ 16384.0f / (sizeY / 2));

    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_10DC0/func_801356C0.s")
#endif

// draw chunked images (e.g. 200 credz)
#if 0
// CURRENT (2725)
void func_80135CD8(u32 startX, u32 startY, u32 width, u32 height, Gfx **dl, u8 *img) {
    u32 sp8C;

    s32 yOffset;

    s32 xx;
    s32 yy;
    s16 xh, yh;
    s16 xl, yl;

    s32 x;
    s32 y;
    void *imgAddr;

    s32 foo;
    s32 bar;

    gDPPipeSync((*dl)++);

    y = startY;
    sp8C = width / 32;

    while (y < (startY + height)) {

        if ((startY + height) < (y + 32)) {
            yOffset = (startY - y) + height;
        } else {
            yOffset = 32;
        }

        for (x = startX; x < (startX + width); x += 0x20) {

            xl = (x*4);
            yl = (y*4);

            xh = ((x + 32) * 4);
            yh = ((y + yOffset) * 4);

            xx = x - startX;
            yy = y - startY;

            imgAddr = img + (((((s8) (yy / 32) * sp8C) + ((xx * x) / 32) & 0xFF)) * 32 * 32);

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

            gSPScisTextureRectangle(
            /* pkt  */  (*dl)++,
            /* xl   */  xl,
            /* yl   */  yl,
            /* xh   */  xh,
            /* yh   */  yh,
            /* tile */  G_TX_RENDERTILE,
            /* s    */  0,
            /* t    */  0,
            /* dsdx */  0x400,
            /* dtdy */  0x400);

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
