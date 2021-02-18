#include <ultra64.h>

#include "common.h"


void func_80294E50_6384F0(void) {
    func_802988E8_63BF88();
}

void func_80294E70_638510(Gfx **dl, u8 alpha) {
    func_8012AD30(dl, 0, 0, 320, 240, 0, 0, 0, alpha);
}

void func_80294EB8_638558(Gfx **dl) {
    guPerspective(&D_80204278->unk37410, &D_80302E60, 33.0f, 1.33333333f, 100.0f, D_80302D20, 1.0f);

    gSPPerspNormalize((*dl)++, D_80302E60);

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
    if (D_80204260 == 1) {
        func_80298FC0_63C660(0);
    }
    rnc_decompress(&D_802B64A0, &D_80302E88); // newscaster video
    rnc_decompress(&D_802AFBD0, &D_8039E2E8);
    rnc_decompress(&D_802B12D0, &D_803A38D8);
    rnc_decompress(&D_802B2930, &D_803A8EC8);
    rnc_decompress(&D_802B3F90, &D_80338688);
    rnc_decompress(&D_802C11C0, &D_8033CE88);
    rnc_decompress(&D_802BC430, &D_8032AE88);
    rnc_decompress(&D_802F4CA0, &D_80376ED8);

    func_801308E8(D_8023F2AE, 0x21, &D_80231AA0, &D_80231D5C);

    src = func_80130A90(16);
    dst = &D_802042F0;
    while (*src != 30000) {
        *dst++ = *src++;
    }
    *dst = 30000;

    src = func_80130A90(14);
    dst = &D_80204368;
    while (*src != 30000) {
        *dst++ = *src++;
    }
    *dst = 30000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295234_6388D4.s")
// needs some love
// void func_80295234_6388D4(void) {
//     DisplayList *temp_v0;
//
//     gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, 312, 232);
//     gSPDisplayList(D_801D9E7C++, &D_80158368);
//
//     temp_v0 = D_80204278;
//
//     guTranslate(&temp_v0->unk33590[temp_v0->unk38918], D_80299DC4, D_80299DC8, D_80299DCC);
//     gSPMatrix(D_801D9E7C++, &temp_v0->unk33590[temp_v0->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//     temp_v0->unk38918 += 1;
//
//     func_80125980(&temp_v0->unk33590[temp_v0->unk38918], 0, 0, 0, D_80299DD0, D_80299DD4, D_80299DD8, 0x10000, 0x10000, 0x10000);
//     gSPMatrix(D_801D9E7C++, &temp_v0->unk33590[temp_v0->unk38918], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//     temp_v0->unk38918 += 1;
//
//     gSPDisplayList(D_801D9E7C++, &D_801542D0);
//     gSPDisplayList(D_801D9E7C++, &D_802EEB20);
//
//     gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);
// }

void func_8029548C_638B2C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295494_638B34.s")
// NON-MATCHING: long way to go...
// void func_80295494_638B34(Gfx **arg0, u16 arg1) {
//     s32 phi_a1;
//     s32 phi_a2;
//
//     D_80299DC4 = (f32) D_80299DB8;
//     D_80299DC8 = (f32) D_80299DBC;
//
//     func_80294EB8_638558(&D_801D9E7C);
//
//     gSPDisplayList((*arg0)++, &D_80158368);
//     gSPNumLights((*arg0)++, 1);
//     gSPLight((*arg0)++, &D_80299D58, 1);
//     gSPLight((*arg0)++, &D_80299D50, 2);
//
//     if (arg1 < 20) {
//         phi_a1 = 159 - (arg1 * 8);
//         phi_a2 = (arg1 * 8) + 161;
//         if (phi_a1 < 8) {
//             phi_a1 = 8;
//         }
//         if (phi_a2 >= 313) {
//             phi_a2 = 312;
//         }
//         gDPSetScissorFrac((*arg0)++, G_SC_EVEN_INTERLACE, phi_a1 * 4.0f, 480, phi_a2 * 4.0f, 484);
//     } else if (arg1 < 40) {
//         phi_a1 = (arg1 / 2) * 12;
//         if (phi_a1 >= 233) {
//             phi_a1 = 232;
//         }
//         gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, (239 - phi_a1) * 4.0f, 312, phi_a1 * 4.0f);
//     } else {
//         gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
//     }
//
//     func_80125980(D_80204278 + (D_80204278->unk38918 << 6) + 0x33590, 0, 0, 0, 0, 0, 0, 0x80000, 0x80000, 0x80000);
//
//     gSPMatrix((*arg0)++, (D_80204278 + (D_80204278->unk38918 << 6) + 0x33590), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//     D_80204278->unk38918 += 1;
//
//     gDPSetRenderMode((*arg0)++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
//     gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
//     gSPDisplayList((*arg0)++, &D_80299CD0);
//     gDPSetScissorFrac((*arg0)++, G_SC_EVEN_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_802958B8_638F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_8029597C_63901C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295C38_6392D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295EB0_639550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295FAC_63964C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_802988E8_63BF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80298AC0_63C160.s")

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
//
//     s32 i;
//     s32 j;
//
//     gSPDisplayList(arg0++, &D_801582C0);
//
//     sp20 = 8;
//     sp14 = &D_80364E88;
//     sp10 = &D_801D9E7C;
//     sp18 = 1.0f;
//     sp1C = 1.0f;
//     func_801356C0(1, 1, 1, 1);
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
//         temp_v0_4 = i << 5;
//         for (j = 0; j < 10; j ++) {
//             temp_v1 = j << 5;
//
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
//             gDPFillRectangle(D_801D9E7C++, 0, 0, 0, 0);
//             // temp_v0_6->unk0 = (s32) ((((temp_v1 + sp80 + sp84) & 0x3FF) << 0xE) | 0xF6000000 | (((temp_v0_4 + sp80 + sp84) & 0x3FF) * 4));
//             // temp_v0_6->unk4 = (s32) ((((temp_v1 + sp70) & 0x3FF) << 0xE) | (((temp_v0_4 + sp70) & 0x3FF) * 4));
//
//             gDPSetPrimColor(arg0++, 0, 0, temp_t7, temp_t7, temp_t7, 0xff);
//             // temp_v0_7->unk4 = sp68;
//
//             sp20 = 16;
//             sp1C = temp_f20;
//             sp18 = temp_f20;
//             sp14 = i + 0x62000 + &D_80302E88;
//             sp10 = &D_801D9E7C;
//             func_801356C0(temp_v1 + sp64, temp_v0_4 + sp64, arg0, arg0);
//         }
//         spAA = i;
//     }
//
//     gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0xff, 0xff, 0xff)
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80298F1C_63C5BC.s")
