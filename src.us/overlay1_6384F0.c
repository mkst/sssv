#include <ultra64.h>

#include "common.h"

#include "pp.h"

// .data
s16 D_80299FC0_63D660 = 0;
s16 D_80299FC4_63D664 = 360;
s16 D_80299FC8_63D668 = 0;

// .bss
u16  D_80302E60[2];
u8*  D_80302E64;

void func_80294E50_6384F0(void) {
    func_802988E8_63BF88();
}

void func_80294E70_638510(Gfx **dl, u8 alpha) {
    draw_rectangle(dl, 0, 0, 320, 240, 0, 0, 0, alpha);
}

void func_80294EB8_638558(Gfx **dl) {
    guPerspective(&D_80204278->unk37410, D_80302E60, 33.0f, 1.33333333f, 100.0f, 15000.0f, 1.0f); // D_80302D20_6A63C0, 15000.0f

    gSPPerspNormalize((*dl)++, *D_80302E60);

    guScale(&D_80204278->unk37450, D_80299DDC, D_80299DE0, D_80299DE4);
    guScale(&D_80204278->unk374D0, D_80299DDC, D_80299DE0, D_80299DE4);
    guLookAt(&D_80204278->unk37490, D_80299DB8_63D458, D_80299DBC, D_80299DC0, 0.0f, 0.0f, 0.0f, D_80299DE8, D_80299DEC, D_80299DF0);

    gSPMatrix((*dl)++, &D_80204278->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204278->unk37450, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204278->unk37490, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204278->unk374D0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_802950B8_638758(void) {
    s16 *src;
    s16 *dst;

    font_init();
    if (gRegion == REGION_EU) {
        language_select_menu(0);
    }
    UnpackRNC((RNC_fileptr)D_802B64A0, D_80302E88); // newscaster "video"
    UnpackRNC((RNC_fileptr)D_802AFBD0, D_8039E2E8);
    UnpackRNC((RNC_fileptr)D_802B12D0, D_803A38D8);
    UnpackRNC((RNC_fileptr)D_802B2930, D_803A8EC8);
    UnpackRNC((RNC_fileptr)D_802B3F90, D_80338688);
    UnpackRNC((RNC_fileptr)D_802C11C0, D_8033CE88); // newsflash?
    UnpackRNC((RNC_fileptr)D_802BC430, D_8032AE88); // splash space_background
    UnpackRNC((RNC_fileptr)D_802F4CA0, D_80376ED8);

    // load "lang34.dat"
    load_level_text_data(D_8023F2A0.language, 33, D_80231AA0, D_80231D5C);

    src = get_message_address_by_id(MSG_CONTROLLER_NOT_CONNECTED);
    dst = D_802042F0;
    COPY_MESSAGE(src, dst);

    src = get_message_address_by_id(MSG_PRESS_START);
    dst = D_80204368;
    COPY_MESSAGE(src, dst);
}

void func_80295234_6388D4(void) {
    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, 312, 232);
    gSPDisplayList(D_801D9E7C++, &D_80158368);

    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_80299DC4_63D464, D_80299DC8_63D468, D_80299DCC);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, D_80299DD0, D_80299DD4, D_80299DD8, 0x10000, 0x10000, 0x10000);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    gSPDisplayList(D_801D9E7C++, &D_801542D0);        // load spaceship texture
    gSPDisplayList(D_801D9E7C++, &D_802EEB20_6921C0); // load spaceship model

    gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);
}

void func_8029548C_638B2C(void) {
}

void func_80295494_638B34(Gfx **arg0, u16 arg1) {
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    u16 sp66;
    u16 sp64;

    sp66 = 160;
    sp64 = 120;

    D_80299DC4_63D464 = D_80299DB8_63D458;
    D_80299DC8_63D468 = D_80299DBC_63D45C;

    func_80294EB8_638558(&D_801D9E7C);
    gSPDisplayList((*arg0)++, &D_80158368);
    gSPNumLights((*arg0)++, 1);
    gSPLight((*arg0)++, &D_80299D50_63D3F0.l[0], 1);
    gSPLight((*arg0)++, &D_80299D50_63D3F0.a, 2);

    if ((s32) arg1 < 0x14) {
        sp74 = (sp66 - (arg1 << 3)) - 1;
        sp6C = sp66 + (arg1 << 3) + 1;
        if (sp74 < 8) {
            sp74 = 8;
        }
        if (sp6C > 312) {
            sp6C = 312;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, sp74, 120, sp6C, 121);

    } else if (arg1 < 0x28) {
        sp70 = (sp64 - ((arg1 / 2) * 0xC)) + 119;
        sp68 = (sp64 + ((arg1 / 2) * 0xC)) - 120;
        if (sp70 < 8) {
            sp74 = 8; // unused but important for eu
        }
        if (sp68 > 232) {
            sp68 = 232;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, sp70, 312, sp68);
    } else {
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    }

    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, 0, 0, 0, FTOFIX32(8.0), FTOFIX32(8.0), FTOFIX32(8.0));

    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gDPSetRenderMode((*arg0)++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
    gSPDisplayList((*arg0)++, &D_80299CD0_63D370);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void black_out_screen(Gfx **dl) {
    gSPDisplayList((*dl)++, &D_801582C0);
    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, 320, 240);
    gDPSetPrimColor((*dl)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
    gDPSetCombineMode((*dl)++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetRenderMode((*dl)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPFillRectangle((*dl)++, 0, 0, 321, 241);
}

void func_8029597C_63901C(uSprite *sprite, u8 thumbnail) {
    static u8   D_80299FCC_63D66C = 0;  // .data
    static s16  D_80299FD0_63D670 = 60; // .data
    s16 temp_t2;
    u8 flip_x = 0;

    if (thumbnail != 0) { // 0 for spin in, 1 for thumbnail
        D_80299FD0_63D670 = 60;
        D_80299FCC_63D66C = 0;
    }

    temp_t2 = ((D_80299FCC_63D66C * 260.0f) / 48.0) + 60.0;

    if (D_80299FCC_63D66C < 24) {
        flip_x = 1;
    }

    func_801366BC(&D_801D9E7C, 0xFF, 0xFF, 0xFF, 0xFF);
    draw_sprite(
        &D_801D9E7C,
        sprite,
        320,
        240,
        ABS(D_80299FD0_63D670), // scale_x
        (D_80299FCC_63D66C * 195.0f / 48.0) + 45.0, //D_80302D28_6A63C8,
        flip_x,
        0,
        (48 - D_80299FCC_63D66C) + ((temp_t2 - ABS(D_80299FD0_63D670)) / 2),
        (48 - D_80299FCC_63D66C),
        16);

    if (D_80299FCC_63D66C < 49) {
        if (D_80299FCC_63D66C < 24) {
            D_80299FD0_63D670 -= temp_t2 / 48;
        } else {
            D_80299FD0_63D670 += temp_t2 / 19;
        }
        D_80299FCC_63D66C++;
    }
}

void func_80295C38_6392D8(u8 arg0, u8 arg1) {
    gSPDisplayList(D_801D9E7C++, &D_801582C0);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, D_80299E10, D_80299E10, D_80299E10, 0xFF);

    func_80135CD8(0, 0, 320, 256, &D_801D9E7C, D_80302E88);

    switch (arg0) {
    case 1:
        D_80302E64 = D_8039E2E8;
        break;
    case 2:
        D_80302E64 = D_803A38D8;
        break;
    case 3:
        D_80302E64 = D_803A8EC8;
        break;
    }

    if (arg0) {
        func_80135CD8(112, 20, 96, 96, &D_801D9E7C, D_80302E64);
    }
    if (arg1) {
        func_80135CD8(112, 131, 96, 96, &D_801D9E7C, D_80338688);
    }

    if ((D_80299E14 >= D_80299C84[2]) && ((D_80299C84[2] + 7) >= D_80299E14)) {
        switch ((D_80299E14 - D_80299C84[2]) / 2) {
        case 0:
            D_80302E64 = D_802B58A0;
            break;
        case 1:
        case 3:
            D_80302E64 = D_802B60A0;
            break;
        case 2:
            D_80302E64 = D_802B5CA0;
            break;
        }
        func_801356C0(D_80299C84[0], D_80299C84[1], 32, 32, &D_801D9E7C, D_80302E64, 32.0f, 32.0f, 8);
        D_80299E14 += 1;
    } else {
        D_80299E14 = 0;
    }
}

// draw_space_background_image_at_x
void func_80295EB0_639550(s32 x) {
    func_801366BC(&D_801D9E7C, 0xFF, 0xFF, 0xFF, 0xFF);
    draw_sprite(&D_801D9E7C, (uSprite *)D_8032AE88, 160, 128, 320, 241, 0, 0, x, 0, 16);
    func_80129594(&D_801D9E7C, D_80204278);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
}

// TODO: this isnt quite right offset-wise?
s16 D_80299FD4_63D674 = 0;
s16 D_80299FD8_63D678 = 0;
s32 D_80299FDC_63D67C = 0;

s32 D_80299FE0_63D680 = 0;
s32 D_80299FE4_63D684 = 0;
s32 D_80299FE8_63D688 = 0;
u8  D_80299FEC_63D68C = 0;

u8  D_80299FF0_63D690 = 0;
s16 D_80299FF4_63D694 = 1;
s8  D_80299FF8_63D698 = 0;
s16 D_80299FFC_63D69C = 320;

s16 D_8029A000_63D6A0 = 0;
f32 D_8029A004_63D6A4 = 1.0f;
f32 D_8029A008_63D6A8 = 1.0f;
u8  D_8029A00C_63D6AC = 0;

s8  D_8029A010_63D6B0 = 251;
u8  D_8029A014_63D6B4 = 46;
u16 D_8029A018_63D6B8 = 0;
u8  D_8029A01C_63D6BC = 1;

u8  D_8029A020_63D6C0 = 0;
u16 D_8029A024_63D6C4 = 0;
u16 D_8029A028_63D6C8 = 0;
f32 D_8029A02C_63D6CC = 0;

s8  D_8029A030_63D6D0 = 0;
u16 D_8029A034_63D6D4 = 0;
u16 D_8029A038_63D6D8 = 0;
s16 D_8029A03C_63D6DC = 0;

s16 D_8029A040_63D6E0 = 100;
s16 D_8029A044_63D6E4 = 100;
s16 D_8029A048_63D6E8 = 4000;

#if 0
void func_80295FAC_63964C(struct018 *arg0) {
    // ??
    static u8 D_80299FF0_63D690 = 0;

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f6;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a1_2;
    s16 temp_ra;
    s16 language;
    s32 temp_f8_2;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_v1_13;
    u8 temp_a3;
    u8 temp_t6;
    struct016 *temp_a1;
    s16 phi_ra;
    u8 phi_a1;
    f32 phi_f0;
    f32 phi_f0_2;
    s32 phi_a2;
    f32 phi_f0_3;

    if (D_80204284 == 5) {
        D_80299DFC_63D49C = 6;
        D_80204284 = 1;
        D_80299E1C_63D4BC = 0;
        D_8029A038_63D6D8 = 0;
        D_80299E08_63D4A8 = 0;
        D_80299E0C_63D4AC = 0xFF;

        D_80299DD0_63D470 = 270.0f;
        D_80299DD4_63D474 = 180.0f;
        D_80299DD8_63D478 = 180.0f;

        D_80299DB8_63D458 = 0.0f;
        D_80299DBC_63D45C = 0.0f;
        D_80299DC0_63D460 = 3800.0f;

        D_80299DE8_63D488 = -1.0f;
        D_80299DF4_63D494 = 0.0f;

        D_8029A024_63D6C4 = 0;
        D_8029A028_63D6C8 = 0;
        D_80299FFC_63D69C = 8;
        D_8029A000_63D6A0 = 2;
    }
    if (D_80299FEC_63D68C == 0) {
        func_802950B8_638758(); // decompress newscaster video
        D_80299FEC_63D68C = 1;
        D_80299E10_63D4B0 = 254; // red level
    }

    gControllerInput = &D_802910E8[D_801D9ED0]; // (D_801D9ED0 * 6) +

    switch (D_80299DFC_63D49C) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        black_out_screen(&D_801D9E7C);
        if (D_8023F2A0.language == LANG_DEFAULT) {
            if (gRegion == REGION_EU) {
                if ((gControllerConnected == 0) && (D_80204270 != 0)) {
                    D_8023F2A0.language = LANG_ENGLISH;
                    write_eeprom(4);
                } else {
                    language = language_select_menu(1);
                    if (language != 0xFF) {
                        D_8023F2A0.language = language;
                        write_eeprom(4);
                    }
                }
            }
        } else if ((gControllerConnected == 0) && ((D_80204270 != 0))) {
            phi_ra = D_80152350.unk0[D_80204270];
            if (phi_ra >= 256) {
                phi_ra = 0xFF;
            }
            D_80204270 += 1;
            if (D_80204270 >= 180) {
                D_80204270 = 0;
            }

            func_80294EB8_638558(&D_801D9E7C);
            D_80299DB8_63D458 = 0.0f;
            D_80299DBC_63D45C = 0.0f;
            D_80299DC0_63D460 = 12000.0f;
            D_80299FD8_63D678 = (s16) (D_80299FD8_63D678 + 1) % 360;
            D_80299FD4_63D674 = (s16) (D_80299FD4_63D674 + 1) % 360;
            func_80298AC0_63C160();
            // temp_v0_3 = D_801D9E7C;

            gDPPipeSync(D_801D9E7C++);
            gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
            gSPNumLights(D_801D9E7C++, 1);
            gSPLight(D_801D9E7C++, &D_80299D98_63D438, 1);
            gSPLight(D_801D9E7C++, &D_80299D90_63D430, 2);

            temp_lo = (phi_ra * 170) / 255;
            D_80299D98_63D438.l.colc[0] = temp_lo; // unkC
            D_80299D98_63D438.l.col[0] = temp_lo; // unk8
            D_80299D98_63D438.l.colc[1] = temp_lo; // unkD
            D_80299D98_63D438.l.col[1] = temp_lo; // unk9
            D_80299D98_63D438.l.colc[2] = temp_lo; // unkE
            D_80299D98_63D438.l.col[2] = temp_lo; // unkA

            gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCombineLERP(D_801D9E7C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
            gDPSetRenderMode(D_801D9E7C++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gSPSetGeometryMode(D_801D9E7C++, G_CULL_BACK | G_LIGHTING);

            func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, 0, 0, 0x2710, 0x2710, 0x2710);
            gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            D_80204278->usedModelViewMtxs += 1;

            guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (f32) D_80299FD4_63D674, 0, 1.0f, 0.0f);
            gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            D_80204278->usedModelViewMtxs += 1;

            gSPDisplayList(D_801D9E7C++, &D_802F3C20_6972C0);
            gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);
        } else {
            if (D_8029A020_63D6C0 == 0) {
                D_80299E08_63D4A8++;
                if (D_80299E08_63D4A8 >= 11) {
                    if (D_80299E08_63D4A8 < 249) {
                        phi_a1 = 0xFF;
                        if (D_80299E08_63D4A8 > 160) {
                            phi_a1 = (0xFF - (*(s16*)&D_80152212 + (D_80299E08_63D4A8 * 2))) & 0xFF;
                        }
                        if (phi_a1 == 0) {
                            D_80299E08_63D4A8 = 260;
                        }
                        func_801366BC(&D_801D9E7C, phi_a1, phi_a1, phi_a1, 0xFF);
                        draw_sprite(&D_801D9E7C, D_80376ED8, 0x140, 0xF0, 0x140, 0xF0, 0, 0, 0, 0, 0x10);
                        if (gRegion == REGION_EU) {
                            // add Copyright C
                            draw_sprite(&D_801D9E7C, (uSprite*)D_80299E44_63D4E4, 0xA, 0xC, 0xA, 0xC, 0, 0, 0x71, 0x90, 0x10);
                        }
                        D_80299DB8_63D458 = 1.0f;
                        D_80299DBC_63D45C = 501.0f;
                        D_80299DC0_63D460 = 6000.0f;
                        // phi_v0 = (s32) D_80299E08_63D4A8;
                    }
                }
                if ((D_80299E08_63D4A8 > 260) && (D_80299E08_63D4A8 < 750)) {
                    D_80299E08_63D4A8 = 761;
                    if (D_80299E08_63D4A8 == 500) {
                        D_80299E08_63D4A8 = 760;
                    }
                }
                if ((D_80299E08_63D4A8 >= 0x2F9) && (D_80299E08_63D4A8 < 0x3E8)) {
                    D_80152E90 = 0;
                    D_80204284 = 4;
                    D_80204288 = 10;
                }
                if (D_80299E08_63D4A8 >= 1000) {
                    if ((D_8023F2A0.unk8 & 1) == 0) {
                        D_8029A020_63D6C0 = 1;
                        D_8029A038_63D6D8 = 0;
                        D_80299E08_63D4A8 = 0;
                        D_80299E0C_63D4AC = 0xFF;
                        D_80299DD0_63D470 = 270.0f;
                        D_80299DD4_63D474 = 180.0f;
                        D_80299DD8_63D478 = 180.0f;
                        D_80299DB8_63D458 = 0.0f;
                        D_80299DBC_63D45C = 0.0f;
                        D_80299DC0_63D460 = 3800.0f;
                        D_80299DE8_63D488 = -1.0f;
                        D_80299DF4_63D494 = 0.0f;
                    } else {
                        D_80299E08_63D4A8 = 0;
                        D_80299E10_63D4B0 = 55;
                        D_80299DFC_63D49C = 1;
                        D_80299DC0_63D460 = 6000.0f;
                        D_8029A014_63D6B4 = 0x2E;
                    }
                }
            }
            gDPPipeSync(D_801D9E7C++);
        }
        break;
    case 1:                                         /* switch 1 */
        if (D_80299E08_63D4A8 == 20) {
            D_8028645C = 0;
            func_801337DC(0, 2.0f, 1.0f, 20.0f);
            func_8013385C(2.0f, 1.0f, 20.0f);
        }
        D_80299E08_63D4A8 += 1;
        if (D_80299E08_63D4A8 < 200) {
            black_out_screen(&D_801D9E7C);
            func_80295494_638B34(&D_801D9E7C, D_80299E08_63D4A8);
            if (D_80299E08_63D4A8 > 40) {
                func_8013328C(0x2C23, 0x9F, 0x40, 1.0f, (D_8029A014_63D6B4 * 100) + 0x1000, 0);
            }
            if (D_80299E08_63D4A8 > 50) {
                gSPDisplayList(D_801D9E7C++, &D_801582C0);

                D_8029A004_63D6A4 = 30.0f;
                phi_f0 = 30.0f;
                if (phi_f0 <= 260.0f) { // 30.0f
                    do {
                        if (phi_f0 <= D_8029A014_63D6B4) {
                            func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, &D_80156AC0, 22.0f, 22.0f, 16);
                        } else {
                            func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, &D_801562C0, 22.0f, 22.0f, 16);
                        }
                        phi_f0 = D_8029A004_63D6A4 + 8.0f;
                    } while (phi_f0 <= 260.0f);
                    D_8029A004_63D6A4 = phi_f0;
                }
                func_801356C0(0xC8, 0x28, 0x20, 0x20, &D_801D9E7C, &D_801552C0, 22.0f, 22.0f, 0x10);
                func_801356C0(0xDC, 0x28, 0x20, 0x20, &D_801D9E7C, &D_80155AC0, 22.0f, 22.0f, 0x10);
                func_801356C0(0xFA, 0x28, 0x20, 0x20, &D_801D9E7C, &D_80157AC0, 22.0f, 22.0f, 0x10);
            }
            if (D_80299E08_63D4A8 >= 0x83) {
                D_8029A014_63D6B4 = 0x60;
            } else if (D_80299E08_63D4A8 >= 0x51) {
                D_8029A014_63D6B4 = 0x58;
            } else if (D_80299E08_63D4A8 >= 0x47) {
                D_8029A014_63D6B4 = 0x50;
            } else if (D_80299E08_63D4A8 >= 0x3D) {
                D_8029A014_63D6B4 = 0x48;
            } else if (D_80299E08_63D4A8 >= 0x33) {
                D_8029A014_63D6B4 = 0x40;
            } else if (D_80299E08_63D4A8 >= 0x24) {
                D_8029A014_63D6B4 = 0x38;
            }
        } else {
            D_801546E0 = 2048;
            D_8028645C = 18;
            D_8015517C = 1.0f;
            D_801546D8 = 1936; // volume related
            if (gRefreshRate == 50) {
                D_801546E0 = 1706; // (50 / 60) * 2048
            }
            gSPDisplayList(D_801D9E7C++, &D_801582C0);

            if ((s32) D_80299E10_63D4B0 < 56) {
                D_80299E10_63D4B0 = 255; // pulse back to 255
            }
            D_80299E10_63D4B0 = D_80299E10_63D4B0 - 5;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, D_80299E10_63D4B0, 125, 125, 255);
            func_80135CD8(0, 0, 0x140, 0x100, &D_801D9E7C, &D_8033CE88);
            if (D_80299E08_63D4A8 < 0x140) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

                D_8029A004_63D6A4 = 30.0f;
                phi_f0_2 = 30.0f;
                if (phi_f0_2 <= 260.0f) { // 30.0f
                    do {
                        if (phi_f0_2 <= D_8029A014_63D6B4) {
                            func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, &D_80156AC0, 22.0f, 22.0f, 16);
                        } else {
                            func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, &D_801562C0, 22.0f, 22.0f, 16);
                        }
                        phi_f0_2 = D_8029A004_63D6A4 + 8.0f;
                    } while (phi_f0_2 <= 260.0f);
                    D_8029A004_63D6A4 = phi_f0_2;
                }
                if (D_80299E08_63D4A8 >= 0xF1) {
                    D_8029A014_63D6B4 = 0x58;
                } else if (D_80299E08_63D4A8 >= 0x105) {
                    D_8029A014_63D6B4 = 0x60;
                }
                func_801356C0(0xC8, 0x28, 0x20, 0x20, &D_801D9E7C, &D_801552C0, 22.0f, 22.0f, 16);
                func_801356C0(0xDC, 0x28, 0x20, 0x20, &D_801D9E7C, &D_80155AC0, 22.0f, 22.0f, 16);
                func_801356C0(0xFA, 0x28, 0x20, 0x20, &D_801D9E7C, &D_801572C0, 22.0f, 22.0f, 16);
            }
        }
        if (D_80299E08_63D4A8 == 436) { // ? end? length of what?
            D_80299E08_63D4A8 = 0;
            D_80299DFC_63D49C = 2;
            D_80302E70 = 0;
            D_80302E71 = 0;
            D_80299E10_63D4B0 = 255;
            D_80299E18_63D4B8 = 0;
            D_80299FF0_63D690 = 0;
            D_8029A01C_63D6BC = 1;
            D_80299FF8_63D698 = 0;
        }
        gDPPipeSync(D_801D9E7C++);
        break;
    case 2:  // tv announcer                                       /* switch 1 */
        D_80299E08_63D4A8++;
        D_8029A038_63D6D8++;
        if (D_80299FF0_63D690 != 0xFF) {
            temp_a1 = *(&D_80299960_63D000 + (D_80299FF0_63D690 * 8)) + (D_80299E18_63D4B8 * 6);
            if ((D_80299E08_63D4A8) == temp_a1->unk0) {
                D_80299E34_63D4D4 = 0;
                D_80299E2C_63D4CC = temp_a1->unk4;
                D_80299E3C_63D4DC = 0;
                D_80299E40_63D4E0 = 1;
                switch (D_80299E2C_63D4CC) {         /* switch 2; irregular */
                case 0x57:                      /* switch 3 */
                    D_80302E74 = &D_80299C70_63D310; // D_80302E74 = phi_t7;
                    break;
                case 0xFF:                      /* switch 3 */
                    D_80302E74 = &D_80299A40_63D0E0; //- 0x6390;
                    break;
                case 0x120:                         /* switch 2 */
                    D_80302E74 = &D_80299A58_63D0F8;
                    break;
                case 0x121:                         /* switch 2 */
                    D_80302E74 = &D_80299A88_63D128;
                    break;
                case 0x122:                         /* switch 2 */
                    D_80302E74 = &D_80299ACC_63D16C;
                    break;
                case 0x123:                         /* switch 2 */
                    D_80302E74 = &D_80299AF8_63D198;
                    break;
                case 0x124:                         /* switch 2 */
                    D_80302E74 = &D_80299B30_63D1D0;
                    break;
                case 0x125:                         /* switch 2 */
                    D_80302E74 = &D_80299B74_63D214;
                    break;
                case 0x126:                         /* switch 2 */
                    D_80302E74 = &D_80299B94_63D234;
                    break;
                case 0x127:                         /* switch 2 */
                    D_80302E74 = &D_80299BC4_63D264;
                    break;
                case 0x128:                         /* switch 2 */
                    D_80302E74 = &D_80299BF0_63D290;
                    break;
                case 0x129:                         /* switch 2 */
                    D_80302E74 = &D_80299C20_63D2C0;
                    break;
                case 0x12A:                         /* switch 2 */
                    D_80302E74 = &D_80299C50_63D2F0;
                    break;
                }
                temp_a0 = temp_a1->unk4;
                if (temp_a0 != 0xFF) {
                    phi_a2 = 0x5500;
                    if (temp_a0 == 0x57) {
                        phi_a2 = 0x2500;
                    }
                    if (D_8029A020_63D6C0 == 0) {
                        if (gRefreshRate == 60) {
                            play_sound_effect(temp_a0, 0, phi_a2, 1.2f, 0); // 0x3F99999A
                        } else {
                            play_sound_effect(temp_a0, 0, phi_a2, 1.0f, 0);
                        }
                    }
                }
                D_80299E18_63D4B8++;
            } else if ((temp_a1->unk0 == 0) && (D_80299FF0_63D690 < 28)) {
                D_80299E18_63D4B8 = 0;
                D_80299E08_63D4A8 = 0;
                D_80299FF0_63D690++;
            }
            if (D_80299E40_63D4E0 != 0) {
                if (D_80299E34_63D4D4 == D_80302E74[D_80299E3C_63D4DC].length) { // unk0
                    D_80302E70 = D_80302E74[D_80299E3C_63D4DC].tile; // unk2
                    D_80302E71 = D_80302E74[D_80299E3C_63D4DC].unk6; // unk4
                    D_80299E3C_63D4DC++;
                }
                D_80299E34_63D4D4++;
            }
        }
        if (D_80299FF0_63D690 == 17) {
            D_80299FF0_63D690++;
            D_80299DFC_63D49C = 9;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            D_80299E10_63D4B0 = 105;
            D_80299E0C_63D4AC = 0;
            D_8029A010_63D6B0 = -2;
            D_8029A018_63D6B8 = 0;
            UnpackRNC(&D_802C6C90_66A330, &D_8033CE88); // heroes_for_hire image
        }

        if (D_80299FF0_63D690 == 0x1C) {
            D_80299FF0_63D690 = 0xFF;
            D_80299E14_63D4B4 = 1;
            func_80132F70(0x56, 0x5000);
            D_80302E70 = 1;
        }
        func_80295C38_6392D8(D_80302E70, D_80302E71);

        if ((D_80299FF0_63D690 > 0) && (D_80299FF0_63D690 < 4)) {
            if (D_8029A01C_63D6BC != 0) {
                UnpackRNC(&D_802DA900_67DFA0, &D_8033CE88); // space_station img
                func_8029597C_63901C(&D_8033CE88, 1); // thumbnail
            } else if (D_80299FF0_63D690 == 1) {
                func_8029597C_63901C(&D_8033CE88, 1); // thumbnail
            } else {
                func_8029597C_63901C(&D_8033CE88, 0); // spin into full screen
            }
            D_8029A01C_63D6BC = 0;
        }
        if ((D_80299FF0_63D690 > 4) && (D_80299FF0_63D690 < 8)) {
            if (D_8029A01C_63D6BC != 0) {
                UnpackRNC(&D_802D00F0_673790, &D_8033CE88); // professor_cheese
                func_8029597C_63901C(&D_8033CE88, 1);
            } else if (D_80299FF0_63D690 == 5) {
                func_8029597C_63901C(&D_8033CE88, 1);
            } else {
                func_8029597C_63901C(&D_8033CE88, 0);
            }
            D_8029A01C_63D6BC = 0;
        }
        if ((D_80299FF0_63D690 > 13) && (D_80299FF0_63D690 < 17)) {
            if (D_8029A01C_63D6BC != 0) {
                UnpackRNC(&D_802A37E0_646E80, &D_8033CE88); // president_frank_bloke
                func_8029597C_63901C(&D_8033CE88, 1);
            } else if (D_80299FF0_63D690 == 14) {
                func_8029597C_63901C(&D_8033CE88, 1);
            } else {
                func_8029597C_63901C(&D_8033CE88, 0);
            }
            D_8029A01C_63D6BC = 0;
        }
        if ((D_80299FF0_63D690 == 4) || (D_80299FF0_63D690 == 8)) {
            D_8029A01C_63D6BC = 1; // need to decompress next image
        }
        if (D_80299FF0_63D690 != 0xFF) {
            if (D_80299964_63D004[D_80299FF0_63D690].id != MSG_DUMMY) {
                load_default_display_list(&D_801D9E7C);
                set_menu_text_color(255, 255, 255, 255);
                select_font(0, 1, 1, 0);
                // update subtitle text
                func_8012EB4C(&D_801D9E7C, get_message_address_by_id(D_80299964_63D004[D_80299FF0_63D690].id), 160, 202, 16.0f, 16.0f, 16);
            }
        } else if (D_80299E08_63D4A8 >= 0x2E) {
            D_8029A020_63D6C0 = 1;
            D_8029A038_63D6D8 = 0;
            D_80299E08_63D4A8 = 0;
            D_80299E0C_63D4AC = 0xFF;
            D_80299DD0_63D470 = 270.0f;
            D_80299DD4_63D474 = 180.0f;
            D_80299DD8_63D478 = 180.0f;
            D_80299DB8_63D458 = 0.0f;
            D_80299DBC_63D45C = 0.0f;
            D_80299DC0_63D460 = 3800.0f;
            D_80299DE8_63D488 = -1.0f;
            D_80299DF4_63D494 = 0.0f;
            if ((D_8023F2A0.unk8 & 1) != 0) {
                D_8023F2A0.unk8 = 0;
                write_eeprom(4);
            }
        }
        break;
    case 9: // heroes for hire?
        gSPDisplayList(D_801D9E7C++, &D_801582C0);

        if ((D_80299E10_63D4B0 == 255) || (D_80299E10_63D4B0 == 105)) {
            D_8029A010_63D6B0 = -D_8029A010_63D6B0;
        }
        // is this really blue, or is it red?
        gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, D_80299E10_63D4B0, 255);

        D_80299E10_63D4B0 += D_8029A010_63D6B0;
        // newsflash
        func_80135CD8(0, 0, 0x140, 0x100, &D_801D9E7C, &D_8033CE88);
        if (D_80299E0C_63D4AC++ > 20) {
            // show 200 credz popup
            func_80135CD8(0xDC, 0x8C, 0x40, 0x40, &D_801D9E7C, &D_802BF170_662810); // 200_credz
            if (D_80299E0C_63D4AC == 40) {
                D_80299E0C_63D4AC = 0;
            }
        }
        if (D_8029A018_63D6B8++ == 300) {
            D_80299DFC_63D49C = 2;
            D_80299E10_63D4B0 = 0xFF;
        }
        break;
    case 3:  // title screen
        if (D_80299E1C_63D4BC == 1) {
            D_8028645C = 19;
            D_8015517C = 1.0f;
            D_801546E0 = 2048;
            D_801546D8 = 2048;
        }
        D_80299DD4_63D474++;
        if (D_80299DD4_63D474 > 359.0) {
            D_80299DD4_63D474 = 0.0f;
        }
        D_80299DF4_63D494++;
        if (D_80299DF4_63D494 > 359.0f) {
            D_80299DF4_63D494 = 0.0f;
        }
        if (D_80299E1C_63D4BC < 1800) {
            D_80299DD8_63D478++;
            if (D_80299DD8_63D478 > 359.0) {
                D_80299DD8_63D478 = 0.0f;
            }
            D_80299DC4_63D464 = D_80152350.unk2D0[(s32)D_80299DF4_63D494] * D_80299DF8_63D498;
            D_80299DC8_63D468 = 0.0f;
            D_80299DCC_63D46C = (D_80152350.unk384[(s32)D_80299DF4_63D494] * D_80299DF8_63D498) - 2500;
        }
        if (D_80299E1C_63D4BC >= 1800) {
            if (D_80299E1C_63D4BC == 1800) {
                func_801337DC(0, 4.0f, 20.0f, 0);
            }
            D_80299DC4_63D464 += 42.0f; //  D_80299DC4_63D464 + 42.0f;
            D_80299E10_63D4B0 = 0x1617 - (D_80299E1C_63D4BC * 3); // *phi_t0_2
        }
        func_80294EB8_638558(&D_801D9E7C);
        func_80295234_6388D4();

        func_80136418(&D_801D9E7C, D_80299E11_63D4B1);
        func_801360C8(&D_801D9E7C, &D_80352E88, 0x100, 0x80, 0x100, 0x7E, 0, 0, 0x20, 0x20, 0xFDE8);
        func_80136418(&D_801D9E7C, D_80299E11_63D4B1);
        func_801360C8(&D_801D9E7C, &D_8032AE88, 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);

        load_segments(&D_801D9E7C, D_80204278);
        load_default_display_list(&D_801D9E7C);
        set_menu_text_color(D_80299E11_63D4B1, D_80299E11_63D4B1, 0, 0xFF);
        select_font(0, 0, 0, 0);
        if ((D_80299E1C_63D4BC < 1800) && (gControllerConnected != 0)) {
            // PRESS START
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_PRESS_START), 0xA0, 0xC8, 16.0f, 16.0f);
        }
        D_80299E1C_63D4BC++;
        if (D_80299E1C_63D4BC >= 1885) {
            if (D_80204288 >= 6) {
                D_80204288 = 0;
            }
            D_80204288++;
            if (D_80204288 == 1) {
                D_80299E08_63D4A8 = 0;
                D_80299E10_63D4B0 = 55;
                D_80299DFC_63D49C = 1;
                D_80299DC0_63D460 = 6000.0f;
                D_8029A014_63D6B4 = 46;
                D_80299FEC_63D68C = 0;
            } else {
                func_801337DC(0, 10.0f, 20.0f, 0);
                func_80298F1C_63C5BC(arg0->unk3BBE8, &D_80364E88);
                D_80299DFC_63D49C = 10;
                D_80299FF8_63D698 = 0;
                D_80299E04_63D4A4 = 1;
                D_8029A00C_63D6AC = 32;
                D_8028645C = 0;
            }
        }
        break;
    case 5:  // title screen logo pop-in
        D_8015517C = 1.0f;
        D_801546E0 = 2048;
        D_801546D8 = 1;
        D_8028645C = 18;
        D_80299E10_63D4B0 = 0xFF;
        if (D_80299DC4_63D464 == -2616.0f) {
            UnpackRNC(&D_802AA7B0_64DE50, &D_80352E88); // sssv_logo
        }
        gSPDisplayList(D_801D9E7C++, &D_801582C0);

        D_80299DC4_63D464 += 42.0f;
        D_80299DD4_63D474++; // += 1.0f;
        if (D_80299DD4_63D474 >= 359.0) {
            D_80299DD4_63D474 = 0.0f;
        }
        D_80299E08_63D4A8++;
        func_80294EB8_638558(&D_801D9E7C);
        func_80295234_6388D4();
        D_80302E64 = &D_8032AE88;
        func_80136418(&D_801D9E7C, D_80299E11_63D4B1);
        func_801360C8(&D_801D9E7C, &D_8032AE88, 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);

        temp_v1_13 = D_80299E08_63D4A8 * 2;
        func_801360C8(&D_801D9E7C, &D_80352E88, 0x100, 0x80, D_80299FFC_63D69C + (D_80299E08_63D4A8 * 4), D_8029A000_63D6A0 + temp_v1_13, 0, 0, 0x9C - temp_v1_13, 0x5E - D_80299E08_63D4A8, 0xFDE8);
        if (D_8029A00C_63D6AC != 0) {
            func_80298C70_63C310(D_8029A00C_63D6AC);
            D_8029A00C_63D6AC--;
        }
        if (D_80299DC4_63D464 == -12.0f) {
            D_80299DFC_63D49C = 3;
            D_80299E10_63D4B0 = 0xFF;
            D_80299E1C_63D4BC = 0;
            D_80299E08_63D4A8 = 0;
            D_8029A004_63D6A4 = 1.0f;
        }
        break;
    case 6:  // loading something? immediately before 5
        D_80299E1C_63D4BC = 0;
        D_80299E08_63D4A8 = 0;
        D_80299E0C_63D4AC = 0xFF;
        D_80299DD0_63D470 = 270.0f;
        D_80299DD8_63D478 = 180.0f;
        D_80299DB8_63D458 = 0.0f;
        D_80299DBC_63D45C = 0.0f;
        D_80299DC0_63D460 = 3800.0f;
        D_80299DE8_63D488 = -1.0f;
        D_80299DF4_63D494 = 0.0f;
        if (D_80299E1C_63D4BC == 0) {
            D_80299E10_63D4B0 = 0;
        }
        D_8028645C = 0;
        D_80204290 = 1;
        D_80299E28_63D4C8 = 0;
        D_80299FEC_63D68C = 0;
        D_80299E10_63D4B0 = 0xFF;
        D_80299FF4_63D694 = 1;
        D_8029A008_63D6A8 = 1.0f;
        D_80299DFC_63D49C = 5;  // title screen
        D_80299FF8_63D698 = (s8) 1;
        D_80299E04_63D4A4 = 1;
        D_80299DD4_63D474 = 110.0f;
        D_80299DC4_63D464 = -2616.0f;
        D_80299DC8_63D468 = 0.0f;
        D_80299DCC_63D46C = -196.0f;
        D_8029A00C_63D6AC = 0;
        D_8029A004_63D6A4 = 1.0f;
        if ((D_80204288 == 10) && ((D_8023F2A0.unk8 & 1) == 1)) {
            D_80204288 = 0;
            D_80299E10_63D4B0 = 55;
            D_80299DFC_63D49C = 1;
            D_80299DC0_63D460 = 6000.0f;
            D_8029A014_63D6B4 = 46;
        }
        break;
    case 10:                                        /* switch 1 */
        black_out_screen(&D_801D9E7C);
        if (D_8029A00C_63D6AC != 0) {
            func_80298C70_63C310(D_8029A00C_63D6AC);
            D_8029A00C_63D6AC--; // = D_8029A00C_63D6AC - 1;
            if (D_8029A00C_63D6AC == 0) {
                stop_all_sounds();
                D_80299E24_63D4C4 = 1;
            }
        }
        break;
    case 8:                                         /* switch 1 */
        black_out_screen(&D_801D9E7C);
        func_80294EB8_638558(&D_801D9E7C);
        func_80295234_6388D4();
        func_80136418(&D_801D9E7C, D_80299E11_63D4B1);
        func_801360C8(&D_801D9E7C, &D_8032AE88, 160, 128, 320, 241, 0, 0, 0, 0, 0xFFFF);
        func_801360C8(&D_801D9E7C, &D_80352E88, 256, 128, 256, 126, 0, 0, 32, 32, 0xFDE8);
        D_80299DCC_63D46C = 0.0f;
        D_80299DC8_63D468 = 0.0f;
        D_80299DC4_63D464 = 0.0f;
        D_80299DBC_63D45C = 0.0f;
        D_80299DB8_63D458 = 0.0f;
        D_80299DC0_63D460 = 4000.0f;

        if (D_80299DD8_63D478++ > 359.0f) {
            D_80299DD8_63D478 = 0.0f;
        }
        if (D_80299DD4_63D474++ > 359.0f) {
            D_80299DD4_63D474 = 0.0f;
        }
        if (D_80299DD0_63D470++ > 359.0f) {
            D_80299DD0_63D470 = 0.0f;
        }
        break;
    default:                                        /* switch 1 */
        break;
    }

    if (D_8029A020_63D6C0 != 0) {
        D_8029A030_63D6D0 = 0xFF;
        if (D_80299FF8_63D698 == 0) {
            D_80299FF8_63D698 = 1;
            D_8029A034_63D6D4 = 0;
            D_8029A024_63D6C4 = 320;
            D_8029A028_63D6C8 = 0;
            D_8029A02C_63D6CC = 180.0f;
        }
        temp_f0_6 = D_8029A02C_63D6CC;
        phi_f0_3 = temp_f0_6;
        if (D_8029A034_63D6D4 == 0) {
            if (D_8029A024_63D6C4 <= 0) {
                D_8029A034_63D6D4 = 1;
            } else {
                D_8029A024_63D6C4 = D_8029A024_63D6C4 - 20; // *(s16 *)0x
            }
        } else {
            if (D_8029A02C_63D6CC >= 359.0f) {
                D_8029A02C_63D6CC = 0.0f;
            }
            temp_f8_2 = (s32) D_8029A02C_63D6CC;
            if ((temp_f8_2 % 180) == 0) {
                D_8029A028_63D6C8 += 4; //= D_8029A028_63D6C8 + 4;
            }
            // temp_a0_6 = D_8029A028_63D6C8; // *(u16 *)0x
            temp_lo_2 = (s32) (D_80152620[temp_f8_2]) / (s32) D_8029A028_63D6C8;
            // if (temp_lo_2 < 0) {
            //     D_8029A024_63D6C4 = (u16) -temp_lo_2;
            // } else {
            //     D_8029A024_63D6C4 = (s16) temp_lo_2;
            // }
            D_8029A024_63D6C4 = ABS(temp_lo_2);
            D_8029A02C_63D6CC = phi_f0_3;
            if (D_8029A028_63D6C8 < 5) {
                D_8029A02C_63D6CC += 6.0f;
            }
        }
        black_out_screen(&D_801D9E7C); // phi_s0
        D_80302E64 = &D_8032AE88;
        func_80295EB0_639550(D_8029A024_63D6C4);
        if (D_8029A028_63D6C8 >= 5) {
            D_80299DFC_63D49C = 5;
            D_8029A020_63D6C0 = 0;
            D_80299E08_63D4A8 = 0;
            D_80299E0C_63D4AC = 0xFF;
            D_80299DD0_63D470 = 270.0f;
            D_80299DD4_63D474 = 110.0f;
            D_80299DD8_63D478 = 180.0f;
            D_80299DB8_63D458 = 0.0f;
            D_80299DBC_63D45C = 0.0f;
            D_80299DC0_63D460 = 3800.0f;
            D_80299DE8_63D488 = -1.0f;
            D_80299DF4_63D494 = 0.0f;
            D_80299DC4_63D464 = -2616.0f;
            D_80299DC8_63D468 = 0.0f;
            D_80299DCC_63D46C = -196.0f;
            D_80299FFC_63D69C = 8;
            D_8029A000_63D6A0 = 2;
        }
    }

    if ((gControllerInput->button & START_BUTTON) &&
        (D_80299DFC_63D49C == 3) &&
        (D_8029A00C_63D6AC == 0) &&
        (D_8029A020_63D6C0 == 0)) {
        play_sound_effect(0x8F, 0, 0x5000, 1.0f, 0);
        func_801337DC(0, 30.0f, 20.0f, 0);
        func_8012A400();
        func_80298F1C_63C5BC(D_8019E240[D_80152EB8 ^ 1], &D_80364E88);
        D_80299DFC_63D49C = 10;
        D_80299FF8_63D698 = 0;
        D_80299E04_63D4A4 = 1;
        D_8029A00C_63D6AC = 32;
        D_8028645C = 0;
        D_80204288 = 0;
    }
    if ((D_80299E04_63D4A4 > 0) && (D_80299E04_63D4A4 < 5)) {
        D_80299E04_63D4A4++;
    } else {
        if (((gControllerInput->button & START_BUTTON) == 0) &&
            ((gControllerInput->button & A_BUTTON) == 0)) {
            D_80299E04_63D4A4 = 0;
        }
    }
    if (gControllerInput->button & START_BUTTON) {
        if ((D_80299DFC_63D49C != 7) && (D_80299DFC_63D49C != 10) && (D_80299E04_63D4A4 == 0) && (D_80299E20_63D4C0 == 0) && ((D_80204288 = 0, (D_80299DFC_63D49C != 0)) || ((s32) D_80299E08_63D4A8 >= 0x104)) && (D_80299DFC_63D49C != 3) && (D_8029A020_63D6C0 == 0) && (D_80299DFC_63D49C != 5) && (((D_80299DFC_63D49C != 0) && (D_80299DFC_63D49C != 1) && (D_80299DFC_63D49C != 2) && (D_80299DFC_63D49C != 9)) || ((D_8023F2A0.unk8 & 1) != 1))) {
            play_sound_effect(0x8F, 0, 0x5000, 1.0f, 0);
            func_8013385C(2.0f, 20.0f, 0);
            func_801337DC(0, 2.0f, 20.0f, 0);
            D_8029A020_63D6C0 = 1;
            D_80299FF8_63D698 = 0;
            D_80299E04_63D4A4 = 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295FAC_63964C.s")
#endif

void func_802988E8_63BF88(void) {
    gScreenWidth = 320;
    gScreenHeight = 240;
    load_segments(&D_801D9E7C, D_80204278);
    func_80129430(&D_801D9E7C);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gDPPipeSync(D_801D9E7C++);

    D_80152EA8.vp.vscale[0] = gScreenWidth * 2;
    D_80152EA8.vp.vscale[1] = gScreenHeight * 2;
    D_80152EA8.vp.vtrans[0] = gScreenWidth * 2;
    D_80152EA8.vp.vtrans[1] = gScreenHeight * 2;

    gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    // reset used counters
    D_80204278->usedSprites = 0;
    D_80204278->usedModelViewMtxs = 0;
    D_80204278->usedSprites = 0;
    D_80204278->unk39310 = 0;
    D_80204278->usedHilites = 0;

    func_80295FAC_63964C(&D_80162658[D_80152EB8]);
    if (D_80299E24 != 0) {
        D_80152E90 = 0;  // select game overlay
        D_80204284 = 4;
    }
}

void func_80298AC0_63C160(void) {
    gSPClearGeometryMode(D_801D9E7C++, -1);
    gSPSetGeometryMode(D_801D9E7C++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH | G_CLIPPING);

    gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);

    gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
    gDPSetTextureDetail(D_801D9E7C++, G_TD_CLAMP);
    gDPSetTextureLUT(D_801D9E7C++, G_TT_NONE);
    gDPSetTexturePersp(D_801D9E7C++, G_TP_PERSP);
    gDPSetTextureConvert(D_801D9E7C++, G_TC_FILT);

    gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_4);
    gDPSetDepthSource(D_801D9E7C++, G_ZS_PIXEL);
}

// split here?

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80298C70_63C310.s")
// miles and miles away...
// void func_80298C70_63C310(u8 arg0) {
//     u8 spAA;
//     s32 sp84;
//     s32 sp80;
//     s32 sp70;
//     s32 sp68;
//     s32 sp64;
//     s32 sp20;
//
//     f32 sp1C;
//     f32 sp18;
//     void *sp14;
//     void *sp10;
//     f32 temp_f20;
//     s32 temp_t7;
//     s32 temp_v0_3;
//     s32 temp_v0_4;
//     s32 temp_v1;
//
//     s16 i;
//     s16 j;
//
//     gSPDisplayList(arg0++, &D_801582C0);
//
//     func_801356C0(1, 1, 1, 1, &D_80364E88, D_801D9E7C, 1.0f, 1.0f, 8);
//     temp_t7 = ((arg0 * 8) - 1) & 0xFF;
//     spAA = 0;
//     temp_v0_3 = arg0 / 2;
//     sp68 = (temp_t7 << 24) | (temp_t7 << 16) | (temp_t7 << 8) | 0xFF;
//     temp_f20 = (f32) (u32) arg0;
//     sp84 = arg0;
//     sp80 = 0x11 - temp_v0_3;
//     sp70 = 0xF - temp_v0_3;
//     sp64 = 0x10 - temp_v0_3;
//
//     for (i = 0; i < 8; i++) {
//         // temp_v0_4 = i << 5;
//         for (j = 0; j < 10; j ++) {
//             // temp_v1 = j << 5;
//
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, 0, 0, 0, 255);
//             gDPFillRectangle(D_801D9E7C++, j + sp80 + sp84, i + sp80 + sp84, j + sp70, i + sp70);
//             // temp_v0_6->unk0 = (s32) ((((temp_v1 + sp80 + sp84) & 0x3FF) << 0xE) | 0xF6000000 | (((temp_v0_4 + sp80 + sp84) & 0x3FF) * 4));
//             // temp_v0_6->unk4 = (s32) ((((temp_v1 + sp70) & 0x3FF) << 0xE) | (((temp_v0_4 + sp70) & 0x3FF) * 4));
//             gDPSetPrimColor(arg0++, 0, 0, temp_t7, temp_t7, temp_t7, 0xff);
//             // temp_v0_7->unk4 = sp68;
//
//             // sp20 = 16;
//             // sp1C = temp_f20;
//             // sp18 = temp_f20;
//             // sp14 = i + 0x62000 + &D_80302E88;
//             // sp10 = &D_801D9E7C;
//             func_801356C0(j + sp64, i + sp64, arg0, arg0, &D_801D9E7C, i + 0x62000 + &D_80302E88, temp_f20, temp_f20, 16);
//         }
//         spAA = i;
//     }
//
//     gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0xff, 0xff, 0xff)
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80298F1C_63C5BC.s")
// not quite this...
// void func_80298F1C_63C5BC(s32 *arg0, s32 *arg1) {
//     s32 *src, *dst;
//     u8 a, b, c, d;
//
//     src = arg0; dst = arg1;
//
//     a = 7;
//     b = 9;
//     c = 31;
//     d = 15;
//
//     do {
//         do  {
//             do {
//                 do {
//                     *dst++ = *src++;
//                 } while (d--);
//                 src += 144;
//             } while (c--);
//             src -= (144 * 35) + 64;
//         } while (b--);
//         src += (144 * 34) + 64;
//     } while (a--);
// }
