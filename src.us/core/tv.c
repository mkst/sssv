#include <ultra64.h>

#include "common.h"

void initialise_tv_mode(void) {
    s32 vStart;
    s32 vScale;

    switch ((s16)D_80000300) {
    case OS_TV_PAL:
        D_802053E0.VIModeType = OS_VI_PAL_LPN1;
        D_802053E0.screenWidth = 304;
        gRefreshRate = 50; // hz
        D_802053F0.vStart = 0x7A0210;
        D_802053F0.yScale = 1200;
        D_80205400.vStart = 0x34025A;
        D_80205400.yScale = 878;

        if (((D_80204240.region == REGION_US) || (D_80204240.region == REGION_JP)) && (D_80204240.countryCode != 0)) {
            *(volatile s16*)0 = 0; // shit our pants?
        }

        // regalloc
        if (osViModeTable[D_802053E0.VIModeType].fldRegs) {};

        break;
    case OS_TV_NTSC:
        D_802053E0.VIModeType = OS_VI_NTSC_LPN1;
        D_802053E0.screenWidth = 304;
        gRefreshRate = 60; // hz

        D_802053F0.vStart = 0x6501BF;
        D_802053F0.yScale = 0x587;

        vStart = osViModeTable[D_802053E0.VIModeType].fldRegs[0].vStart;
        vScale = osViModeTable[D_802053E0.VIModeType].fldRegs[0].yScale;
        D_80205400.vStart = vStart;
        D_80205400.yScale = vScale;

        if ((D_80204240.region == REGION_EU) && (D_80204240.countryCode != 0)) {
            *(volatile s16*)0 = 0;
        }
        break;
    case OS_TV_MPAL:
        D_802053E0.VIModeType = OS_VI_MPAL_LPN1;
        D_802053E0.screenWidth = 304;
        gRefreshRate = 60; // hz

        D_802053F0.vStart = 0x6501BF;
        D_802053F0.yScale = 0x587; // 1415

        vStart = osViModeTable[D_802053E0.VIModeType].fldRegs[0].vStart;
        vScale = osViModeTable[D_802053E0.VIModeType].fldRegs[0].yScale;

        D_80205400.vStart = vStart;
        D_80205400.yScale = vScale;

        if ((D_80204240.region == REGION_EU) && (D_80204240.countryCode != 0) ){
            *(volatile s16*)0 = 0;
        }
        break;
    default:
        D_802053E0.VIModeType = OS_VI_NTSC_LPN1;
        D_802053E0.screenWidth = 304;
        gRefreshRate = 60;

        D_802053F0.vStart = 0x6501BF;
        D_802053F0.yScale = 1415;

        vStart = osViModeTable[D_802053E0.VIModeType].fldRegs[0].vStart;
        vScale = osViModeTable[D_802053E0.VIModeType].fldRegs[0].yScale;

        D_80205400.vStart = vStart;
        D_80205400.yScale = vScale;

        if ((D_80204240.region == REGION_EU) && (D_80204240.countryCode != 0)) {
            *(volatile s16*)0 = 0;
        }
        break;
    }

    vStart = osViModeTable[D_802053E0.VIModeType].fldRegs[0].vStart;
    vScale = osViModeTable[D_802053E0.VIModeType].fldRegs[0].yScale;
    D_802053E0.vStart = vStart;
    D_802053E0.yScale = vScale;

    osViModeTable[D_802053E0.VIModeType].fldRegs[0].vStart = D_80205400.vStart;
    osViModeTable[D_802053E0.VIModeType].fldRegs[1].vStart = D_80205400.vStart;
    osViModeTable[D_802053E0.VIModeType].fldRegs[0].yScale = D_80205400.yScale;
    osViModeTable[D_802053E0.VIModeType].fldRegs[1].yScale = D_80205400.yScale;
    D_8020540C = (u16)0;
}

void set_screen_scaling(void) {
    osViSetXScale(gScreenWidth / 320.0f);
    osViSetYScale(gScreenHeight / 240.0f);
}

void set_tv_mode_widescreen(void) {
    OSViMode *mode;
    s32 vStart;
    s32 yScale;

    mode = &osViModeTable[D_802053E0.VIModeType];
    vStart = D_802053F0.vStart;
    yScale = D_802053F0.yScale;
    mode->fldRegs[0].vStart = vStart;
    mode->fldRegs[1].vStart = vStart;
    mode->fldRegs[0].yScale = yScale;
    mode->fldRegs[1].yScale = yScale;

    D_8020540C = 1;
}

void set_tv_mode_normal(void) {
    OSViMode *mode;
    s32 vStart;
    s32 yScale;

    mode = &osViModeTable[D_802053E0.VIModeType];
    vStart = D_80205400.vStart;
    yScale = D_80205400.yScale;
    mode->fldRegs[0].vStart = vStart;
    mode->fldRegs[1].vStart = vStart;
    mode->fldRegs[0].yScale = yScale;
    mode->fldRegs[1].yScale = yScale;

    D_8020540C = 0;
}

void func_8012AC8C(void) {
    OSViMode *mode;
    s32 vStart;
    s32 yScale;

    osViSetXScale(1.0f);
    osViSetYScale(1.0f);

    mode = &osViModeTable[D_802053E0.VIModeType];
    vStart = D_802053E0.vStart;
    yScale = D_802053E0.yScale;
    mode->fldRegs[0].vStart = vStart;
    mode->fldRegs[1].vStart = vStart;
    mode->fldRegs[0].yScale = yScale;
    mode->fldRegs[1].yScale = yScale;

    osViBlack(1);
}

void func_8012AD08(void) {
    osViBlack(0);
    set_tv_mode_normal();
}

// file split here?

void draw_rectangle(Gfx **dl, s16 x0, s16 y0, s16 x1, s16 y1, u8 r, u8 g, u8 b, u8 alpha) {
    s32 color;

    if (alpha != 0) {
        gDPPipeSync((*dl)++);
        gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 0, 0, 320, 241);

        gDPPipeSync((*dl)++);
        gDPSetAlphaCompare((*dl)++, G_AC_NONE);

        if (alpha == 0xFF) {
            // rgba5551
            gDPPipeSync((*dl)++);
            gDPSetCycleType((*dl)++, G_CYC_FILL);
            gDPPipeSync((*dl)++);

            gDPSetRenderMode((*dl)++, G_RM_NOOP, G_RM_NOOP2);

            gDPSetFillColor((*dl)++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
            gDPFillRectangle((*dl)++, x0, y0, x1 - 1, y1 - 1);
        } else {
            // rgba32
            gDPPipeSync((*dl)++);
            gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
            gDPSetColorDither((*dl)++, G_CD_NOISE);
            gDPSetAlphaDither((*dl)++, G_AD_DISABLE);

            gDPSetPrimColor((*dl)++, 0, 0, r, g, b, alpha);

            if (D_80204288 == 10) {
                gDPSetRenderMode((*dl)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
            } else {
                gDPSetRenderMode((*dl)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            }

            gDPSetCombineMode((*dl)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPFillRectangle((*dl)++, x0, y0, x1, y1);
        }

        gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
        gDPPipeSync((*dl)++);
    }
}
