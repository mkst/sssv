#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

ScreenTransition gScreenTransition;
static u8   D_803E1B1A; // r
static u8   D_803E1B1B; // g
static u8   D_803E1B1C; // b
static u16  D_803E1B1E; // perspective

// ========================================================
// .text
// ========================================================

void reset_screen_transition(void) {
    gScreenTransition.unk0 = 0;
    gScreenTransition.unk2 = 0;
    gScreenTransition.overlayTV = 0;
}

void trigger_screen_transition(s16 id) {
    if ((id == 23) || (id == 24)) {
        if (id == 23) {
            gScreenTransition.overlayTV = 1;
            hide_osd();
        }
        if (id == 24) {
            gScreenTransition.overlayTV = 0;
            show_osd();
        }
    } else if ((id == 6) || (id == 7) || (id == 19) || (id == 20)) {
        if (id == 6) {
            set_tv_mode_widescreen();
        }
        if (id == 7) {
            set_tv_mode_normal();
        }
        if (id == 19) {
            show_osd();
        }
        if (id == 20) {
            hide_osd();
        }
    } else {
        if ((gScreenTransition.unk0 == 0) || (gScreenTransition.unk0 == 1)) {
            gScreenTransition.unk0 = 2;
            gScreenTransition.unk2 = 1;
            gScreenTransition.unk6 = 0;
            gScreenTransition.transitionId = id;
        }
    }
}

void perform_screen_transition(void) {
    s32 phi_v1;
    s32 alpha;
    s8 size;
    u16 i, j;

    alpha = 0xff;

    render_screen_transition_tv_702A68();
    if ((gScreenTransition.unk0 == 2) || (gScreenTransition.unk0 == 1)) {
        switch (gScreenTransition.transitionId) {
        case 0:
            if (gScreenTransition.unk6 < 240) {
                draw_rectangle(&gMainDL, 0, gScreenTransition.unk6, 320, 240, 0, 0, 0, alpha);
            }
            if (gScreenTransition.unk6 < 240) {
                gScreenTransition.unk6 += 6;
            }
            if (gScreenTransition.unk2 < 100) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk6 >= 240) {
                gScreenTransition.unk0 = 1;
            }
            break;
        case 1:
            draw_rectangle(&gMainDL, 0, 0, 320, gScreenTransition.unk6 + 1, 0, 0, 0, alpha);
            if (gScreenTransition.unk6 < 240) {
                gScreenTransition.unk6 += 6;
            }
            if (gScreenTransition.unk2 < 100) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk6 >= 240) {
                gScreenTransition.unk0 = 1;
            }
            break;
        case 2: // fade in?
            phi_v1 = 100 - (gScreenTransition.unk2 * 10);
            if (phi_v1 > 89) {
                phi_v1 = 89;
            }
            alpha = D_80152350.unk2D0[(s16)phi_v1];
            draw_rectangle(&gMainDL, 0, 0, 320, 240, D_803E1B1A, D_803E1B1B, D_803E1B1C, alpha);
            if (gScreenTransition.unk2 < 100) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk2 > 9) {
                gScreenTransition.unk0 = 0;
            }
            break;
        case 3:     // black screen (fade out?)
        case 14:    // black screen
        case 16:    // red screen
        case 17:    // green screen
        case 18:    // blue screen
            if ((gScreenTransition.transitionId == 3) || (gScreenTransition.transitionId == 14)) {
                D_803E1B1A = 0; // black
                D_803E1B1B = 0;
                D_803E1B1C = 0;
            }
            // unreachable. covered in case 15/22
            if (gScreenTransition.transitionId == 15) {
                D_803E1B1A = 255; // white
                D_803E1B1B = 255;
                D_803E1B1C = 255;
            }
            if (gScreenTransition.transitionId == 16) {
                D_803E1B1A = 255; // red
                D_803E1B1B = 0;
                D_803E1B1C = 0;
            }
            if (gScreenTransition.transitionId == 17) {
                D_803E1B1A = 0;
                D_803E1B1B = 255; // green
                D_803E1B1C = 0;
            }
            if (gScreenTransition.transitionId == 18) {
                D_803E1B1A = 0;
                D_803E1B1B = 0;
                D_803E1B1C = 255; // blue
            }
            if (gScreenTransition.unk2 < 11) {
                phi_v1 = (gScreenTransition.unk2 - 1) * 10;
                if (phi_v1 > 89) {
                    phi_v1 = 89;
                }
                alpha = D_80152350.unk2D0[(s16) (89 - phi_v1)];
                alpha = 255 - alpha;
            } else {
                alpha = 255;
                gScreenTransition.unk0 = 1;
            }
            draw_rectangle(&gMainDL, 0, 0, 320, 240, D_803E1B1A, D_803E1B1B, D_803E1B1C, alpha);
            if (gScreenTransition.unk2 < 100) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk2 >= 99) {
                gScreenTransition.unk0 = 0;
            }
            break;
        case 21: // dim screen?
            phi_v1 = 1.5 * ((61 - gScreenTransition.unk2) * 1.0f);
            if (phi_v1 > 89) {
                phi_v1 = 89;
            }
            alpha = D_80152350.unk2D0[(s16)phi_v1];
            if (alpha < 0) {
                alpha = 0;
            }
            draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, alpha);
            if (gScreenTransition.unk2 < 100) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk2 >= 99) {
                gScreenTransition.unk0 = 0;
            }
            break;
        case 15: // white screen
        case 22:
            if (gScreenTransition.unk2 < 60) {
                phi_v1 = 1.5 * ((gScreenTransition.unk2 - 1) * 1.0f);
                if (phi_v1 > 89) {
                    phi_v1 = 89;
                }
                alpha = D_80152350.unk2D0[(s16) (89 - phi_v1)];
                alpha = 0xFF - alpha;
            } else {
                alpha = 0xFF;
                gScreenTransition.unk0 = 1;
            }
            if (gScreenTransition.transitionId == 22) {
                // fill screen with black + alpha
                draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, alpha);
            } else {
                // fill screen with white + alpha
                draw_rectangle(&gMainDL, 0, 0, 320, 240, 255, 255, 255, alpha);
            }
            if (gScreenTransition.unk2 < 200) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk2 >= 180) {
                gScreenTransition.unk0 = 0;
            }
            break;
        case 5:
            size = gScreenTransition.unk6;
            if (size > 8) {
                size = 8;
            }
            gDPPipeSync(gMainDL++);
            gDPSetCycleType(gMainDL++, G_CYC_1CYCLE);
            gDPSetPrimColor(gMainDL++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            gDPSetEnvColor(gMainDL++, 0x00, 0x00, 0x00, 0x00);
            gDPSetCombineMode(gMainDL++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetRenderMode(gMainDL++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPPipeSync(gMainDL++);
            gDPSetTexturePersp(gMainDL++, G_TP_NONE);
            gDPSetFillColor(gMainDL++, 0x00000000);

            for (i = 0; i <= gScreenWidth; i += 16) {
                for (j = 0; j <= gScreenHeight; j += 16) {
                    gDPFillRectangle(
                        gMainDL++,
                        i - size + 8,
                        j - size + 8,
                        i + size + 8,
                        j + size + 8
                    );
                }
            }
            if (gScreenTransition.unk6 < 9) {
                gScreenTransition.unk6 += 1;
            } else {
                gScreenTransition.unk0 = 1;
            }
            gScreenTransition.unk2 += 1;
            break;
        case 4: // square-folding transition
            size = 8 - gScreenTransition.unk6;
            if (size < 0) {
                size = 0;
            }
            gDPPipeSync(gMainDL++);
            gDPSetCycleType(gMainDL++, G_CYC_1CYCLE);
            gDPSetPrimColor(gMainDL++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            gDPSetEnvColor(gMainDL++, 0x00, 0x00, 0x00, 0x00);
            gDPSetCombineMode(gMainDL++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetRenderMode(gMainDL++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPPipeSync(gMainDL++);
            gDPSetTexturePersp(gMainDL++, G_TP_NONE);
            gDPSetFillColor(gMainDL++, 0x00000000);

            for (i = 0; i <= gScreenWidth; i += 16) {
                for (j = 0; j <= gScreenHeight; j += 16) {
                    gDPFillRectangle(
                        gMainDL++,
                        i - size + 8,
                        j - size + 8,
                        i + size + 8,
                        j + size + 8
                    );
                }
            }

            if (gScreenTransition.unk6 < 9) {
                gScreenTransition.unk6 += 1;
            } else {
                gScreenTransition.unk0 = 1;
            }
            gScreenTransition.unk2 += 1;
            break;
        case 8:
            draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, alpha);
            gScreenTransition.unk0 = 1;
            if (gScreenTransition.unk2 < 100) {
                gScreenTransition.unk2 += 1;
            }
            break;
        case 12:
            gScreenTransition.unk0 = 0;
            break;
        case 25:
            draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, alpha);
            if (gScreenTransition.unk2 < 200) {
                gScreenTransition.unk2 += 1;
            }
            if (gScreenTransition.unk2 > 9) {
                gScreenTransition.unk0 = 1;
            }
            break;
        case 26:
            gScreenTransition.unk0 = 0;
            break;
        }
        if (gScreenTransition.unk2 > 180) {
            gScreenTransition.unk0 = 0;
        }
    }
}

s16 func_802F1388_702A38(void) {
    if ((gScreenTransition.unk0 == 0) || (gScreenTransition.unk0 == 1)) {
        return 1;
    } else {
        return 0;
    }
}

void render_screen_transition_tv_702A68(void) {
    if (gScreenTransition.overlayTV != 0) {
        func_8039D034_7AE6E4(&gMainDL, 0);
        D_803A50C0_7B6770.unk0 = gScreenWidth * 2;
        D_803A50C0_7B6770.unk2 = gScreenHeight * 2;
        D_803A50C0_7B6770.unk8 = gScreenWidth * 2;
        D_803A50C0_7B6770.unkA = gScreenHeight * 2;
        init_f3dex_render(&gMainDL, gDisplayListContext);
        guPerspective(&gDisplayListContext->unk37550, &D_803E1B1E, 33.0f, 1.0f, 5.0f, 100.0f, 1.0f);
        guScale(&gDisplayListContext->unk37590, 0.5f, 0.5f, 0.5f);
        guScale(&gDisplayListContext->unk37610, 0.9f, 1.0f, 1.0f);
        guLookAt(&gDisplayListContext->unk375D0, -1.0f, 105.0f, -3.0f, -1.0f, 0.0f, -3.0f, 0.0f, 0.0f, 1.0f);

        gSPMatrix(gMainDL++, &gDisplayListContext->unk37550, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk37590, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk375D0, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk37610, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPPerspNormalize(gMainDL++, D_803E1B1E);

        load_segments(&gMainDL, gDisplayListContext);
        switch_to_current_segment(&gMainDL, gDisplayListContext);

        gSPViewport(gMainDL++, &D_803A50C0_7B6770);

        gDPSetColorImage(gMainDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(gFrameContextPtr->framebuffer));
        gSPDisplayList(gMainDL++, D_01004270_3DB40);
        gSPTexture(gMainDL++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCombineLERP(gMainDL++,
            SHADE, 0, PRIMITIVE, 0,
            SHADE, 0, PRIMITIVE, 0,
            SHADE, 0, PRIMITIVE, 0,
            SHADE, 0, PRIMITIVE, 0);
        gDPSetRenderMode(gMainDL++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

        func_802F30A4_704754();
        gSPSetGeometryMode(gMainDL++, G_LIGHTING);
        gSPDisplayList(gMainDL++, D_01013370_4CC40); // tv screen
    }
}
