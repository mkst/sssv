#include <ultra64.h>
#include "common.h"


void reset_screen_transition(void) {
    D_803E1B10.unk0 = 0;
    D_803E1B10.unk2 = 0;
    D_803E1B10.overlayTV = 0;
}

void func_802F07E8_701E98(s16 arg0) {
    if ((arg0 == 23) || (arg0 == 24)) {
        if (arg0 == 23) {
            D_803E1B10.overlayTV = 1;
            hide_osd();
        }
        if (arg0 == 24) {
            D_803E1B10.overlayTV = 0;
            show_osd();
        }
    } else if ((arg0 == 6) || (arg0 == 7) || (arg0 == 19) || (arg0 == 20)) {
        if (arg0 == 6) {
            func_8012ABF0(); // resize screen?
        }
        if (arg0 == 7) {
            func_8012AC40();
        }
        if (arg0 == 19) {
            show_osd();
        }
        if (arg0 == 20) {
            hide_osd();
        }
    } else {
        if ((D_803E1B10.unk0 == 0) || (D_803E1B10.unk0 == 1)) {
            D_803E1B10.unk0 = 2;
            D_803E1B10.unk2 = 1;
            D_803E1B10.unk6 = 0;
            D_803E1B10.transitionId = arg0;
        }
    }
}

void perform_screen_transition(void) {
    s32 phi_v1;
    s32 alpha;
    s8 phi_t1;
    u16 i, j;

    alpha = 0xff;

    func_802F13B8_702A68();
    if ((D_803E1B10.unk0 == 2) || (D_803E1B10.unk0 == 1)) {
        switch (D_803E1B10.transitionId) {
        case 0:
            // alpha = 0xff;
            if (D_803E1B10.unk6 < 240) {
                draw_rectangle(&D_801D9E7C, 0, D_803E1B10.unk6, 320, 240, 0, 0, 0, alpha);
            }
            if (D_803E1B10.unk6 < 240) {
                D_803E1B10.unk6 += 6;
            }
            if (D_803E1B10.unk2 < 100) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk6 >= 240) {
                D_803E1B10.unk0 = 1;
            }
            break;
        case 1:
            // alpha = 0xff;
            draw_rectangle(&D_801D9E7C, 0, 0, 320, D_803E1B10.unk6 + 1, 0, 0, 0, alpha);
            if (D_803E1B10.unk6 < 240) {
                D_803E1B10.unk6 += 6;
            }
            if (D_803E1B10.unk2 < 100) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk6 >= 240) {
                D_803E1B10.unk0 = 1;
            }
            break;
        case 2: // fade in?
            phi_v1 = 100 - (D_803E1B10.unk2 * 10);
            if (phi_v1 > 89) {
                phi_v1 = 89;
            }
            alpha = D_80152620[(s16)phi_v1];
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, D_803E1B1A, D_803E1B1B, D_803E1B1C, alpha);
            if (D_803E1B10.unk2 < 100) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk2 > 9) {
                D_803E1B10.unk0 = 0;
            }
            break;
        case 3:     // black screen (fade out?)
        case 14:    // black screen
        case 16:    // red screen
        case 17:    // green screen
        case 18:    // blue screen
            if ((D_803E1B10.transitionId == 3) || (D_803E1B10.transitionId == 14)) {
                D_803E1B1A = 0; // black
                D_803E1B1B = 0;
                D_803E1B1C = 0;
            }
            // unreachable. covered in case 15/22
            if (D_803E1B10.transitionId == 15) {
                D_803E1B1A = 0xFF; // white
                D_803E1B1B = 0xFF;
                D_803E1B1C = 0xFF;
            }
            if (D_803E1B10.transitionId == 16) {
                D_803E1B1A = 0xFF; // red
                D_803E1B1B = 0;
                D_803E1B1C = 0;
            }
            if (D_803E1B10.transitionId == 17) {
                D_803E1B1A = 0;
                D_803E1B1B = 0xFF; // green
                D_803E1B1C = 0;
            }
            if (D_803E1B10.transitionId == 18) {
                D_803E1B1A = 0;
                D_803E1B1B = 0;
                D_803E1B1C = 0xFF; // blue
            }
            if (D_803E1B10.unk2 < 11) {
                phi_v1 = (D_803E1B10.unk2 - 1) * 10;
                if (phi_v1 > 89) {
                    phi_v1 = 89;
                }
                alpha = D_80152620[(s16) (89 - phi_v1)];
                alpha = 0xFF - alpha;
            } else {
                alpha = 0xFF; // alpha?
                D_803E1B10.unk0 = 1;
            }
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, D_803E1B1A, D_803E1B1B, D_803E1B1C, alpha);
            if (D_803E1B10.unk2 < 100) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk2 >= 99) {
                D_803E1B10.unk0 = 0;
            }
            break;
        case 21: // dim screen?
            phi_v1 = 1.5 * ((61 - D_803E1B10.unk2) * 1.0f);
            if (phi_v1 > 89) {
                phi_v1 = 89;
            }
            alpha = D_80152620[(s16)phi_v1];
            if (alpha < 0) {
                alpha = 0;
            }
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, alpha);
            if (D_803E1B10.unk2 < 100) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk2 >= 99) {
                D_803E1B10.unk0 = 0;
            }
            break;
        case 15: // white screen
        case 22:
            if (D_803E1B10.unk2 < 60) {
                phi_v1 = 1.5 * ((D_803E1B10.unk2 - 1) * 1.0f);
                if (phi_v1 > 89) {
                    phi_v1 = 89;
                }
                alpha = D_80152620[(s16) (89 - phi_v1)];
                alpha = 0xFF - alpha;
            } else {
                alpha = 0xFF;
                D_803E1B10.unk0 = 1;
            }
            if (D_803E1B10.transitionId == 22) {
                draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, alpha);
            } else {
                draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0xFF, 0xFF, 0xFF, alpha);
            }
            if (D_803E1B10.unk2 < 200) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk2 >= 180) {
                D_803E1B10.unk0 = 0;
            }
            break;
        case 5:
            phi_t1 = D_803E1B10.unk6;
            if (phi_t1 > 8) {
                phi_t1 = 8;
            }
            gDPPipeSync(D_801D9E7C++);
            gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            gDPSetEnvColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
            gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPPipeSync(D_801D9E7C++);
            gDPSetTexturePersp(D_801D9E7C++, G_TP_NONE);
            gDPSetFillColor(D_801D9E7C++, 0x00000000);

            for (i = 0; i <= gScreenWidth; i += 16) {
                for (j = 0; j <= gScreenHeight; j += 16) {
                    gDPFillRectangle(
                        D_801D9E7C++,
                        i - phi_t1 + 8,
                        j - phi_t1 + 8,
                        i + phi_t1 + 8,
                        j + phi_t1 + 8
                    );
                }
            }
            if (D_803E1B10.unk6 < 9) {
                D_803E1B10.unk6 += 1;
            } else {
                D_803E1B10.unk0 = 1;
            }
            D_803E1B10.unk2 += 1;
            break;
        case 4: // square-folding transition
            phi_t1 = 8 - D_803E1B10.unk6;
            if (phi_t1 < 0) {
                phi_t1 = 0;
            }
            gDPPipeSync(D_801D9E7C++);
            gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            gDPSetEnvColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
            gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPPipeSync(D_801D9E7C++);
            gDPSetTexturePersp(D_801D9E7C++, G_TP_NONE);
            gDPSetFillColor(D_801D9E7C++, 0x00000000);

            for (i = 0; i <= gScreenWidth; i += 16) {
                for (j = 0; j <= gScreenHeight; j += 16) {
                    gDPFillRectangle(
                        D_801D9E7C++,
                        i - phi_t1 + 8,
                        j - phi_t1 + 8,
                        i + phi_t1 + 8,
                        j + phi_t1 + 8
                    );
                }
            }

            if (D_803E1B10.unk6 < 9) {
                D_803E1B10.unk6 += 1;
            } else {
                D_803E1B10.unk0 = 1;
            }
            D_803E1B10.unk2 += 1;
            break;
        case 8:
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, alpha);
            D_803E1B10.unk0 = 1;
            if (D_803E1B10.unk2 < 100) {
                D_803E1B10.unk2 += 1;
            }
            break;
        case 12:
            D_803E1B10.unk0 = 0;
            break;
        case 25:
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, alpha);
            if (D_803E1B10.unk2 < 200) {
                D_803E1B10.unk2 += 1;
            }
            if (D_803E1B10.unk2 > 9) {
                D_803E1B10.unk0 = 1;
            }
            break;
        case 26:
            D_803E1B10.unk0 = 0;
            break;
        }
        if (D_803E1B10.unk2 > 180) {
            D_803E1B10.unk0 = 0;
        }
    }
}

s16 func_802F1388_702A38(void) {
    if ((D_803E1B10.unk0 == 0) || (D_803E1B10.unk0 == 1)) {
        return 1;
    } else {
        return 0;
    }
}

void func_802F13B8_702A68(void) {
    if (D_803E1B10.overlayTV != 0) {
        func_8039D034_7AE6E4(&D_801D9E7C, 0);
        D_803A50C0_7B6770.unk0 = gScreenWidth * 2;
        D_803A50C0_7B6770.unk2 = gScreenHeight * 2;
        D_803A50C0_7B6770.unk8 = gScreenWidth * 2;
        D_803A50C0_7B6770.unkA = gScreenHeight * 2;
        func_80129594(&D_801D9E7C, D_80204278);
        guPerspective(&D_80204278->unk37550, &D_803E1B1E, 33.0f, 1.0f, 5.0f, 100.0f, 1.0f);
        guScale(&D_80204278->unk37590, 0.5f, 0.5f, 0.5f);
        guScale(&D_80204278->unk37610, 0.9f, 1.0f, 1.0f);
        guLookAt(&D_80204278->unk375D0, -1.0f, 105.0f, -3.0f, -1.0f, 0.0f, -3.0f, 0.0f, 0.0f, 1.0f);

        gSPMatrix(D_801D9E7C++, &D_80204278->unk37550, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37590, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk375D0, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37610, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPPerspNormalize(D_801D9E7C++, D_803E1B1E);

        load_segments(&D_801D9E7C, D_80204278);
        func_80380490_791B40(&D_801D9E7C, D_80204278);

        gSPViewport(D_801D9E7C++, &D_803A50C0_7B6770);

        gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
        gSPDisplayList(D_801D9E7C++, D_01004270);
        gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCombineLERP(D_801D9E7C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
        gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

        func_802F30A4_704754();
        gSPSetGeometryMode(D_801D9E7C++, G_LIGHTING);
        gSPDisplayList(D_801D9E7C++, D_01013370_4CC40); // tv screen
    }
}
