#include <ultra64.h>

#include "common.h"

#include "pp.h"

u16 D_80302E60[2];
u8*  D_80302E64;

void func_80294E50_6384F0(void) {
    func_802988E8_63BF88();
}

void func_80294E70_638510(Gfx **dl, u8 alpha) {
    draw_rectangle(dl, 0, 0, 320, 240, 0, 0, 0, alpha);
}

void func_80294EB8_638558(Gfx **dl) {
    guPerspective(&D_80204278->unk37410, D_80302E60, 33.0f, 1.33333333f, 100.0f, D_80302D20, 1.0f);

    gSPPerspNormalize((*dl)++, *D_80302E60);

    guRotateRPY(&D_80204278->unk37450, D_80299DDC, D_80299DE0, D_80299DE4);
    guRotateRPY(&D_80204278->unk374D0, D_80299DDC, D_80299DE0, D_80299DE4);
    guLookAt(&D_80204278->unk37490, D_80299DB8, D_80299DBC, D_80299DC0, 0.0f, 0.0f, 0.0f, D_80299DE8, D_80299DEC, D_80299DF0);

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
    UnpackRNC((RNC_fileptr)D_802C11C0, D_8033CE88);
    UnpackRNC((RNC_fileptr)D_802BC430, D_8032AE88);
    UnpackRNC((RNC_fileptr)D_802F4CA0, D_80376ED8);

    // load "lang34.dat"
    load_level_text_data(D_8023F2A0.language, 33, D_80231AA0, D_80231D5C);

    // load "CONTROLLER NOT CONNECTED" text
    src = get_message_address_by_id(16); // message 16
    dst = D_802042F0;
    while (*src != 30000) {
        *dst++ = *src++;
    }
    *dst = 30000;

    // load "PRESS START" text
    src = get_message_address_by_id(14); // message 14
    dst = D_80204368;
    while (*src != 30000) {
        *dst++ = *src++;
    }
    *dst = 30000;
}

void func_80295234_6388D4(void) {
    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, 312, 232);
    gSPDisplayList(D_801D9E7C++, &D_80158368);

    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_80299DC4, D_80299DC8, D_80299DCC);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, D_80299DD0, D_80299DD4, D_80299DD8, 0x10000, 0x10000, 0x10000);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    gSPDisplayList(D_801D9E7C++, &D_801542D0); // load spaceship texture
    gSPDisplayList(D_801D9E7C++, &D_802EEB20_6921C0); // load spaceship model

    gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);
}

void func_8029548C_638B2C(void) {
}

#ifdef NON_MATCHING
void func_80295494_638B34(Gfx **arg0, u16 arg1) {
    s32 phi_a1;
    s32 phi_a2;

    D_80299DC4 = D_80299DB8;
    D_80299DC8 = D_80299DBC;

    func_80294EB8_638558(&D_801D9E7C);

    gSPDisplayList((*arg0)++, &D_80158368);
    gSPNumLights((*arg0)++, 1);
    gSPLight((*arg0)++, &D_80299D58_63D3F8, 1);
    gSPLight((*arg0)++, &D_80299D50_63D3F0, 2);

    if (arg1 < 20) {
        phi_a1 = 159 - (arg1 * 8);
        phi_a2 = (arg1 * 8) + 161;
        if (phi_a1 < 8) {
            phi_a1 = 8;
        }
        if (phi_a2 > 312) {
            phi_a2 = 312;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, phi_a1, 120, phi_a2, 121);
    } else if (arg1 < 40) {
        phi_a1 = (arg1 / 2) * 12;
        if (phi_a1 > 232) {
            phi_a1 = 232;
        }
        // this line is slightly off...
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 239 - phi_a1, 312, phi_a1);
    } else {
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    }

    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, 0, 0, 0, 0x80000, 0x80000, 0x80000);

    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    gDPSetRenderMode((*arg0)++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
    gSPDisplayList((*arg0)++, &D_80299CD0_63D370);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295494_638B34.s")
#endif

void func_802958B8_638F58(Gfx **dl) {
    gSPDisplayList((*dl)++, &D_801582C0);
    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, 320, 240);
    gDPSetPrimColor((*dl)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
    gDPSetCombineMode((*dl)++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetRenderMode((*dl)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPFillRectangle((*dl)++, 0, 0, 321, 241);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_8029597C_63901C.s")
// void func_8029597C_63901C(u8 *arg0, u8 arg1) {
//     s16 temp_t2;
//     u8 phi_t3 = 0;
//     s32 tmp;
//
//     if (arg1 != 0) {
//         D_80299FD0_63D670 = 60;
//         D_80299FCC_63D66C = 0;
//     }
//
//     temp_t2 = ((D_80299FCC_63D66C * 260.0f) / 48.0) + 60.0;
//
//     if (D_80299FCC_63D66C < 24) {
//         phi_t3 = 1;
//     } else if (D_80299FCC_63D66C) {
//         //
//     };
//
//
//     func_801366BC(&D_801D9E7C, 0xFF, 0xFF, 0xFF, 0xFF);
//     func_80136938(
//         &D_801D9E7C,
//         arg0,
//         320,
//         240,
//         ABS(D_80299FD0_63D670),
//         (D_80299FCC_63D66C * 195.0f / 48.0) + D_80302D28,
//         phi_t3,
//         0,
//         (48 - D_80299FCC_63D66C) + ((temp_t2 - ABS(D_80299FD0_63D670)) / 2),
//         (48 - D_80299FCC_63D66C),
//         16);
//
//     if (D_80299FCC_63D66C < 49) {
//         tmp = temp_t2;
//
//         if (D_80299FD0_63D670) {};
//
//         if (D_80299FCC_63D66C < 24) {
//             D_80299FD0_63D670 -= tmp / 48;
//         } else {
//             D_80299FD0_63D670 += tmp / 19;
//         }
//         D_80299FCC_63D66C++;
//     }
// }

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

void func_80295EB0_639550(s32 arg0) {
    func_801366BC(&D_801D9E7C, 0xFF, 0xFF, 0xFF, 0xFF);
    func_80136938(&D_801D9E7C, D_8032AE88, 160, 128, 320, 241, 0, 0, arg0, 0, 16);
    func_80129594(&D_801D9E7C, D_80204278);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
}

// 2700 lines...
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295FAC_63964C.s")

void func_802988E8_63BF88(void) {
    gScreenWidth = 320;
    gScreenHeight = 240;
    load_segments(&D_801D9E7C, D_80204278);
    func_80129430(&D_801D9E7C);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gDPPipeSync(D_801D9E7C++);

    D_80152EA8.vp.vscale[0] = D_80203FD0 * 2;
    D_80152EA8.vp.vscale[1] = gScreenHeight * 2;
    D_80152EA8.vp.vtrans[0] = D_80203FD0 * 2;
    D_80152EA8.vp.vtrans[1] = gScreenHeight * 2;

    gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    // reset used counters
    D_80204278->unk38914 = 0;
    D_80204278->usedModelViewMtxs = 0;
    D_80204278->unk38914 = 0;
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

// loopy
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80298F1C_63C5BC.s")
