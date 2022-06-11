#include <ultra64.h>

#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DC0/func_801356C0.s")
// void func_801356C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Gfx **dl, u8 *arg5, f32 sizeX, f32 sizeY, u8 depth) {
//
//     gDPPipeSync((*dl)++);
//
//     switch (depth) {
//     case 16:
//         gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, arg5);
//         gDPLoadSync((*dl)++);
//
//         gDPLoadTextureBlock((*dl)++, arg5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
//             G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
//             G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         break;
//     case 8:
//         gDPLoadSync((*dl)++);
//         gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 1, arg5);
//
//         gDPLoadTextureBlock((*dl)++, arg5, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
//             G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
//             G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         break;
//     default:
//         rmonPrintf("Wrong texture size"); //D_8015B050);
//     }
//
// #if 1
//     // this is *completely* wrong
//     gSPTextureRectangle(
//         (*dl)++,
//         MAX(arg0 * 4, 0),
//         MAX(arg1 * 4, 0),
//         MAX((arg0 + arg2) * 4, 0),
//         MAX((arg1 + arg3) * 4, 0),
//         G_TX_RENDERTILE,
//         MAX(MAX(arg0 * 4, 0) * (s16)(16384.0f / (sizeX / 2.0f)) >> 7, 0),
//         MAX(MAX(arg1 * 4, 0) * (s16)(16384.0f / (sizeY / 2.0f)) >> 7, 0),
//         16384.0f / (sizeX / 2.0f),
//         16384.0f / (sizeY / 2.0f)
//         );
// #endif
//
//     gDPPipeSync((*dl)++);
//     gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
// }

// interesting looping over images
#pragma GLOBAL_ASM("asm/nonmatchings/main_10DC0/func_80135CD8.s")

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
