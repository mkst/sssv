#include <ultra64.h>
#include "common.h"

#include "pp.h"

typedef struct {
    u8 pad0[0x36B0];
    /* 0x36B0 */ u16 unk36B0[350];
    /* 0x396C */ u16 unk396C[350];
} foobar;

extern foobar D_8022E410; // tbd

extern s32 D_80151448;
extern s16 D_80152232; // ?
extern s16 D_80152370; // ?
extern s16 D_80152640; // ?
extern s16 D_801526F4; // ?
extern u16 D_80152ED8;
extern Gfx D_801542F0[];
extern s16 D_801546F8;
extern s16 D_80154700;
extern f32 D_8015519C;
extern s32 D_801552E0; //?
extern s32 D_80155AE0; //?
extern s32 D_801562E0; //?
extern s32 D_80156AE0; //?
extern s32 D_801572E0; //?
extern s32 D_80157AE0; //?
extern Gfx D_801582E0[]; //?
extern u8 D_8019E260[2][0x3BBF0]; //?
extern s16 D_80204280;
extern s16 D_80204290;
extern s16 D_802042A4;
extern s8 D_802042A8;
extern s16 D_802042B0;
extern s16 D_802042B4;
extern Eeprom D_8023F2C0;
extern s16 D_8028647C;
extern s16 D_802912F8;

extern struct014 D_8029AE64_63FD94[]; // ?
extern s32 D_8029AF40_63FE70; // ?
extern s32 D_8029AF58_63FE88; // ?
extern s32 D_8029AF88_63FEB8; // ?
extern s32 D_8029AFCC_63FEFC; // ?
extern s32 D_8029AFF8_63FF28; // ?
extern s32 D_8029B030_63FF60; // ?
extern s32 D_8029B074_63FFA4; // ?
extern s32 D_8029B094_63FFC4; // ?
extern s32 D_8029B0C4_63FFF4; // ?
extern s32 D_8029B0F0_640020; // ?
extern s32 D_8029B120_640050; // ?
extern s32 D_8029B150_640080; // ?
extern s32 D_8029B170_6400A0; // ?
extern Lights1 D_8029B290_6401C0; // ?
extern f32 D_8029B2B8_6401E8;
extern f32 D_8029B2BC_6401EC;
extern f32 D_8029B2C0_6401F0;
extern f32 D_8029B2C4_6401F4;
extern f32 D_8029B2C8_6401F8;
extern f32 D_8029B2CC_6401FC;
extern f32 D_8029B2D0_640200;
extern f32 D_8029B2D4_640204;
extern f32 D_8029B2D8_640208;
extern f32 D_8029B2E8_640218;
extern f32 D_8029B2F4_640224;
extern u8 D_8029B2F8_640228;
extern u8 D_8029B2FC_64022C;
extern u8 D_8029B304_640234;
extern u16 D_8029B308_640238;
extern u16 D_8029B30C_64023C;
extern u16 D_8029B310_640240;
extern s8 D_8029B314_640244;
extern u8 D_8029B318_640248;
extern u16 D_8029B31C_64024C;
extern s8 D_8029B320_640250;
extern s8 D_8029B324_640254;
extern s8 D_8029B328_640258;
extern s16 D_8029B32C_64025C;
extern s16 D_8029B334_640264;
extern s16 D_8029B33C_64026C;
extern s16 D_8029B340_640270;
extern s32 D_8029B344_640274; // ?
extern s16 D_8029B4D4_640404;
extern s16 D_8029B4D8_640408;
extern u8 D_8029B4EC_64041C;
extern u8 D_8029B4F0_640420;
extern s16 D_8029B4F4_640424;
extern s8 D_8029B4F8_640428;
extern s16 D_8029B4FC_64042C;
extern s16 D_8029B500_640430;
extern f32 D_8029B504_640434;
extern f32 D_8029B508_640438;
extern u8 D_8029B50C_64043C;
extern s8 D_8029B510_640440;
extern u8 D_8029B514_640444;
extern u16 D_8029B518_640448;
extern u8 D_8029B51C_64044C;
extern u8 D_8029B520_640450;
extern u16 D_8029B524_640454;
extern u16 D_8029B528_640458;
extern f32 D_8029B52C_64045C;
extern u8 D_8029B530_640460;
extern u16 D_8029B534_640464;
extern u16 D_8029B538_640468;
extern s32 D_802A4CE0_649C10; // ?
extern s32 D_802ABCB0_650BE0; // ?
extern s32 D_802C0670_6655A0; // ?
extern s32 D_802C8190_66D0C0; // ?
extern s32 D_802D15F0_676520; // ?
extern s32 D_802DBE00_680D30; // ?
extern Gfx D_802F0020_694F50[];
extern s32 D_802F5120_69A050; // ?
extern u8 D_80304360;
extern u8 D_80304361;

extern void *D_80304370;
extern u8 D_80304388[]; // ?

extern struct120 D_8029AE60_63FD90[]; // ?

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} tmp123_inner3;

extern struct026 *D_80304364; // ?

void func_8029A144_63F074(s32*, s32*);
void func_8013FB94(Mtx*, f32, f32, f32, f32);
void func_801337FC(s32, f32, f32, f32);
void func_8013387C(f32, f32, f32);
void func_802998D0_63E800(void);
void func_80299B28_63EA58(void);
void draw_rectangle(Gfx **dl, s16 x0, s16 y0, s16 x1, s16 y1, u8 r, u8 g, u8 b, u8 a);
void func_80125980(Mtx*, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9);
void func_8012C998(Gfx**, void*, s32, s32, f32, f32);
void func_8012EB6C(Gfx**, void*, s32, s32, f32, f32, s32);
s16 *get_message_address_by_id(s16);
void func_8013309C(s32, s32, s32, f32, s32);
void func_801332AC(s32, s32, s32, f32, void*, s32);
void func_801356E0(s32, s32, s32, s32, void*, void*, f32, f32, s32);

void func_80294E70_639DA0(void) {
    func_802998D0_63E800();
}

void func_80294E98_639DC8(Gfx **dl, u8 alpha) {
    draw_rectangle(dl++, 0, 0, 320, 240, 0, 0, 0, alpha);
}

void func_80294EFC_639E2C(Gfx **dl) {
    guPerspective(&D_80204298->unk37410, &D_8030436C, 33.0f, 1.33333333f, 100.0f, D_80304220_6A9150, 1.0f);

    gSPPerspNormalize((*dl)++, D_8030436C);

    guScale(&D_80204298->unk37450, D_8029B2DC_64020C, D_8029B2E0_640210, D_8029B2E4_640214);
    guScale(&D_80204298->unk374D0, D_8029B2DC_64020C, D_8029B2E0_640210, D_8029B2E4_640214);
    guLookAt(&D_80204298->unk37490, D_8029B2B8_6401E8, D_8029B2BC_6401EC, D_8029B2C0_6401F0, 0.0f, 0.0f, 0.0f, D_8029B2E8_640218, D_8029B2EC_64021C, D_8029B2F0_640220);

    gSPMatrix((*dl)++, &D_80204298->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204298->unk37450, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204298->unk37490, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204298->unk374D0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_80295184_63A0B4(void) {
    s16 *sp1C;
    s16 *sp18;

    font_init();
    if (D_80204280 == REGION_EU) {
        language_select_menu(0);
    }
    UnpackRNC(&D_802B79A0_65C8D0, D_80304388);
    UnpackRNC(&D_802B10D0_656000, D_80304388 + 0x9B460);
    UnpackRNC(&D_802B27D0_657700, D_80304388 + 0xA0A50);
    UnpackRNC(&D_802B3E30_658D60, D_80304388 + 0xA6040);
    UnpackRNC(&D_802B5490_65A3C0, D_80304388 + 0x35800);
    UnpackRNC(&D_802C26C0_6675F0, D_80304388 + 0x3A000);
    UnpackRNC(&D_802BD930_662860, D_80304388 + 0x28000);
    UnpackRNC(&D_802F61A0_69B0D0, D_80304388 + 0x74050);
    load_level_text_data(D_8023F2C0.language, 33, D_8022E410.unk36B0, D_8022E410.unk396C);
    sp1C = get_message_address_by_id(MSG_CONTROLLER_NOT_CONNECTED);
    sp18 = &D_80204310;
    COPY_MESSAGE(sp1C, sp18);

    sp1C = get_message_address_by_id(MSG_PRESS_START);
    sp18 = &D_80204388;
    COPY_MESSAGE(sp1C, sp18);
}

void func_802953C4_63A2F4(void) {
    s32 pad;

    gDPSetScissor(D_801D9E9C++, G_SC_NON_INTERLACE, 8, 8, 312, 232);
    gSPDisplayList(D_801D9E9C++, D_80158388);

    guTranslate(&D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs], D_8029B2C4_6401F4, D_8029B2C8_6401F8, D_8029B2CC_6401FC);
    gSPMatrix(D_801D9E9C++, &D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    func_80125980(&D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs], 0, 0, 0, D_8029B2D0_640200, D_8029B2D4_640204, D_8029B2D8_640208, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0));
    gSPMatrix(D_801D9E9C++, &D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(D_801D9E9C++, D_801542F0);        // load spaceship texture
    gSPDisplayList(D_801D9E9C++, D_802F0020_694F50);
    gSPPopMatrix(D_801D9E9C++, G_MTX_MODELVIEW);
}

void func_802956AC_63A5DC(void) {
}

void func_802956BC_63A5EC(Gfx **arg0, u16 arg1) {
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    u16 sp66;
    u16 sp64;

    sp66 = 160;
    sp64 = 120;

    D_8029B2C4_6401F4 = D_8029B2B8_6401E8;
    D_8029B2C8_6401F8 = D_8029B2BC_6401EC;

    func_80294EFC_639E2C(&D_801D9E9C);
    gSPDisplayList((*arg0)++, &D_80158388);
    gSPNumLights((*arg0)++, 1);
    gSPLight((*arg0)++, &D_8029B250_640180.l[0], 1);
    gSPLight((*arg0)++, &D_8029B250_640180.a, 2);

    if (arg1 < 20) {
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
            sp74 = 8; // unused but important
        }
        if (sp68 > 232) {
            sp68 = 232;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, sp70, 312, sp68);
    } else {
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    }

    func_80125980(&D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs], 0, 0, 0, 0, 0, 0, FTOFIX32(8.0), FTOFIX32(8.0), FTOFIX32(8.0));

    gSPMatrix((*arg0)++, &D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gDPSetRenderMode((*arg0)++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
    gSPDisplayList((*arg0)++, &D_8029B1D0_640100);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80295CCC_63ABFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80295E00_63AD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80296114_63B044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_80296464_63B394.s")

void func_80296590_63B4C0(struct018 *arg0) {
    u8  padXX[0x28];
    u8  spC7;
    s16 spC4;
    s8  spC3;
    s16 spC0;
    u8  padBB[0x2];
    u8  padCC[0x2];
    s16 spB6;
    u8  padDD[0x1];
    s16 spB2;
    u8  padAA[10];

    spC3 = 0;
    if (D_802042A4 == 5) {
        D_8029B2FC_64022C = 6;
        D_802042A4 = 1;
        D_8029B31C_64024C = 0;
        D_8029B538_640468 = 0;
        D_8029B308_640238 = 0;
        D_8029B30C_64023C = 0xFF;
        D_8029B2D0_640200 = 270.0f;
        D_8029B2D4_640204 = 180.0f;
        D_8029B2D8_640208 = 180.0f;
        D_8029B2B8_6401E8 = 0.0f;
        D_8029B2BC_6401EC = 0.0f;
        D_8029B2C0_6401F0 = 3800.0f;
        D_8029B2E8_640218 = -1.0f;
        D_8029B2F4_640224 = 0.0f;
        D_8029B524_640454 = 0;
        D_8029B528_640458 = 0;
        D_8029B4FC_64042C = 8;
        D_8029B500_640430 = 2;
    }
    if (D_8029B4EC_64041C == 0) {
        func_80295184_63A0B4();
        D_8029B4EC_64041C = 1;
        D_8029B310_640240 = 0xFE;
    }
    gControllerInput = &D_80291108[D_80151448];
    switch (D_8029B2FC_64022C) {
    case 0:
        func_80295CCC_63ABFC(&D_801D9E9C);
        if (D_8023F2C0.language == LANG_DEFAULT) {
            if (D_80204280 == REGION_EU) {
                if ((D_802912F8 == 0) && (D_80204290 != 0)) {
                    D_8023F2C0.language = LANG_ENGLISH;
                    spB6 = func_80130C50(4);
                } else if ((spC4 = language_select_menu(1)) != 0xFF) {
                    D_8023F2C0.language = (s8) spC4;
                    spB6 = func_80130C50(4);
                }
            }
        } else if ((D_802912F8 == 0) && (D_80204290 != 0)) {
            spB2 = *(&D_80152370 + (D_80204290));
            if ((s32) spB2 >= 0x100) {
                spB2 = 0xFF;
            }
            D_80204290 = D_80204290 + 1;
            if ((s32) D_80204290 >= 0xB4) {
                D_80204290 = 0;
            }
            func_80294EFC_639E2C(&D_801D9E9C);
            D_8029B4D4_640404 = D_8029B4D4_640404 + 1;
            D_8029B4D4_640404 = (s16) (D_8029B4D4_640404 % 360);
            D_8029B4D8_640408 = D_8029B4D8_640408 + 1;
            D_8029B4D8_640408 = (s16) (D_8029B4D8_640408 % 360);
            D_8029B2B8_6401E8 = 0.0f;
            D_8029B2BC_6401EC = 0.0f;
            D_8029B2C0_6401F0 = 12000.0f;
            func_80299B28_63EA58();

            gDPPipeSync(D_801D9E9C++);

            gDPSetCycleType(D_801D9E9C++, G_CYC_1CYCLE);

            gSPNumLights(D_801D9E9C++, 1);
            gSPLight(D_801D9E9C++, &D_8029B290_6401C0.l[0], 1);
            gSPLight(D_801D9E9C++, &D_8029B290_6401C0.a, 2);

            D_8029B290_6401C0.l[0].l.col[0] = D_8029B290_6401C0.l[0].l.colc[0] = ((spB2 * 0xAA) / 255); // unkC
            D_8029B290_6401C0.l[0].l.col[1] = D_8029B290_6401C0.l[0].l.colc[1] = ((spB2 * 0xAA) / 255); // unkD
            D_8029B290_6401C0.l[0].l.col[2] = D_8029B290_6401C0.l[0].l.colc[2] = ((spB2 * 0xAA) / 255); // unkE

            gSPTexture(D_801D9E9C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCombineLERP(D_801D9E9C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
            gDPSetRenderMode(D_801D9E9C++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gSPSetGeometryMode(D_801D9E9C++, G_CULL_BACK | G_LIGHTING);

            func_80125FE0(&D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs], 0, 0, 0, 0, 0, 0x2710, 0x2710, 0x2710);
            gSPMatrix(D_801D9E9C++, &D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8013FB94(&D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs], (f32) D_8029B4D4_640404, 0, 1.0f, 0.0f);
            gSPMatrix(D_801D9E9C++, &D_80204298->modelViewMtx[D_80204298->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            gSPDisplayList(D_801D9E9C++, &D_802F5120_69A050);
            gSPPopMatrix(D_801D9E9C++, G_MTX_MODELVIEW);
        } else {
            if (D_8029B520_640450 == 0) {
                D_8029B308_640238++;
                if ((D_8029B308_640238 >= 0xB) && (D_8029B308_640238 < 0xF9)) {
                    spC7 = 0xFF;
                    if (D_8029B308_640238 >= 0xA1) {
                        spC7 = 0xFF - *(&D_80152232 + (D_8029B308_640238));
                    }
                    if (spC7 == 0) {
                        D_8029B308_640238 = 0x104;
                    }
                    func_801366DC(&D_801D9E9C, spC7, spC7, spC7, 0xFF);
                    func_80136958(&D_801D9E9C, D_80304388 + 0x74050, 0x140, 0xF0, 0x140, 0xF0, 0, 0, 0, 0, 0x10);
                    if (D_80204280 == REGION_EU) {
                        func_80136958(&D_801D9E9C, &D_8029B344_640274, 0xA, 0xC, 0xA, 0xC, 0, 0, 0x71, 0x90, 0x10);
                    }
                    D_8029B2B8_6401E8 = 1.0f;
                    D_8029B2BC_6401EC = 501.0f;
                    D_8029B2C0_6401F0 = 6000.0f;
                }
                if ((D_8029B308_640238 >= 0x105) && (D_8029B308_640238 < 0x2EE)) {
                    D_8029B308_640238 = 0x2F9;
                    if (D_8029B308_640238 == 0x1F4) {
                        D_8029B308_640238 = 0x2F8;
                    }
                }
                if ((D_8029B308_640238 >= 0x2F9) && (D_8029B308_640238 < 0x3E8)) {
                    D_80152EB0 = 0;
                    D_802042A4 = 4;
                    D_802042A8 = 0xA;
                }
                if (D_8029B308_640238 >= 1000) {
                    if ((D_8023F2C0.unk8 & 1) == 0) {
                        D_8029B520_640450 = 1;
                        D_8029B538_640468 = 0;
                        D_8029B308_640238 = 0;
                        D_8029B30C_64023C = 0xFF;
                        D_8029B2D0_640200 = 270.0f;
                        D_8029B2D4_640204 = 180.0f;
                        D_8029B2D8_640208 = 180.0f;
                        D_8029B2B8_6401E8 = 0.0f;
                        D_8029B2BC_6401EC = 0.0f;
                        D_8029B2C0_6401F0 = 3800.0f;
                        D_8029B2E8_640218 = -1.0f;
                        D_8029B2F4_640224 = 0.0f;
                    } else {
                        D_8029B308_640238 = 0;
                        D_8029B310_640240 = 0x37;
                        D_8029B2FC_64022C = 1;
                        D_8029B2C0_6401F0 = 6000.0f;
                        D_8029B514_640444 = 0x2E;
                    }
                }
            }
            gDPPipeSync(D_801D9E9C++);
        }
        break;
    case 1:
        if (D_8029B308_640238 == 0x14) {
            D_8028647C = 0;
            func_801337FC(0, 2.0f, 1.0f, 20.0f);
            func_8013387C(2.0f, 1.0f, 20.0f);
        }
        D_8029B308_640238 = D_8029B308_640238 + 1;
        if (D_8029B308_640238 == 0xC8) {

        }
        if (D_8029B308_640238 < 0xC8) {
            func_80295CCC_63ABFC(&D_801D9E9C);
            func_802956BC_63A5EC(&D_801D9E9C, D_8029B308_640238);
            if (D_8029B308_640238 < 0x5F) {

            }
            if (D_8029B308_640238 >= 0x29) {
                func_801332AC(0x2C23, 0x9F, 0x40, 1.0f, (D_8029B514_640444 * 0x64) + 0x1000, 0);
            }
            if (D_8029B308_640238 >= 0x33) {
                gSPDisplayList(D_801D9E9C++, &D_801582E0);
                for (D_8029B504_640434 = 30.0f; D_8029B504_640434 <= 260.0f; D_8029B504_640434 += 8.0f) {
                    if (D_8029B504_640434 <= (f32) D_8029B514_640444) {
                        func_801356E0(D_8029B504_640434, 0xAA, 0x20, 0x20, &D_801D9E9C, &D_80156AE0, 22.0f, 22.0f, 0x10);
                    } else {
                        func_801356E0(D_8029B504_640434, 0xAA, 0x20, 0x20, &D_801D9E9C, &D_801562E0, 22.0f, 22.0f, 0x10);
                    }
                }
                func_801356E0(0xC8, 0x28, 0x20, 0x20, &D_801D9E9C, &D_801552E0, 22.0f, 22.0f, 0x10);
                func_801356E0(0xDC, 0x28, 0x20, 0x20, &D_801D9E9C, &D_80155AE0, 22.0f, 22.0f, 0x10);
                func_801356E0(0xFA, 0x28, 0x20, 0x20, &D_801D9E9C, &D_80157AE0, 22.0f, 22.0f, 0x10);
            }
            if (D_8029B308_640238 >= 0x83) {
                D_8029B514_640444 = 0x60;
            } else if (D_8029B308_640238 >= 0x51) {
                D_8029B514_640444 = 0x58;
            } else if (D_8029B308_640238 >= 0x47) {
                D_8029B514_640444 = 0x50;
            } else if (D_8029B308_640238 >= 0x3D) {
                D_8029B514_640444 = 0x48;
            } else if (D_8029B308_640238 >= 0x33) {
                D_8029B514_640444 = 0x40;
            } else if (D_8029B308_640238 >= 0x24) {
                D_8029B514_640444 = 0x38;
            }
        } else {
            D_8015519C = 1.0f;
            D_80154700 = 0x800;
            D_801546F8 = 0x790;
            D_8028647C = 0x12;

            D_8015519C = 1.0f;
            D_801546F8 = 0x790;
            if (D_802042B4 == 0x32) {
                D_80154700 = 0x6AA;
            }

            gSPDisplayList(D_801D9E9C++, &D_801582E0);
            if ((s32) D_8029B310_640240 < 0x38) {
                D_8029B310_640240 = 0xFF;
            }
            D_8029B310_640240 = D_8029B310_640240 - 5;

            gDPSetPrimColor(D_801D9E9C++, 0, 0, D_8029B310_640240, 125, 125, 255);
            func_80135CF8(0, 0, 0x140, 0x100, &D_801D9E9C, D_80304388 + 0x3A000);
            if ((s32) D_8029B308_640238 < 0x140) {
                gDPSetPrimColor(D_801D9E9C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                for (D_8029B504_640434 = 30.0f; D_8029B504_640434 <= 260.0f; D_8029B504_640434 += 8.0f) {
                    if (D_8029B504_640434 <= (f32) D_8029B514_640444) {
                        func_801356E0((s32) D_8029B504_640434, 0xAA, 0x20, 0x20, &D_801D9E9C, &D_80156AE0, 22.0f, 22.0f, 0x10);
                    } else {
                        func_801356E0((s32) D_8029B504_640434, 0xAA, 0x20, 0x20, &D_801D9E9C, &D_801562E0, 22.0f, 22.0f, 0x10);
                    }
                }
                if (D_8029B308_640238 >= 0xF1) {
                    D_8029B514_640444 = 0x58;
                } else if (D_8029B308_640238 >= 0x105) {
                    D_8029B514_640444 = 0x60;
                }
                func_801356E0(0xC8, 0x28, 0x20, 0x20, &D_801D9E9C, &D_801552E0, 22.0f, 22.0f, 0x10);
                func_801356E0(0xDC, 0x28, 0x20, 0x20, &D_801D9E9C, &D_80155AE0, 22.0f, 22.0f, 0x10);
                func_801356E0(0xFA, 0x28, 0x20, 0x20, &D_801D9E9C, &D_801572E0, 22.0f, 22.0f, 0x10);
            }
        }
        if (D_8029B308_640238 == 0x1B4) {
            D_8029B308_640238 = 0;
            D_8029B2FC_64022C = 2;
            D_80304360 = 0;
            D_80304361 = 0;
            D_8029B310_640240 = 0xFF;
            D_8029B318_640248 = 0;
            D_8029B4F0_640420 = 0;
            D_8029B51C_64044C = 1;
            D_8029B4F8_640428 = 0;
        }

        gDPPipeSync(D_801D9E9C++);
        break;
    case 2:
        D_8029B308_640238 = D_8029B308_640238 + 1;
        D_8029B538_640468 = D_8029B538_640468 + 1;
        if (D_8029B4F0_640420 != 0xFF) {

            if (D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk0 == D_8029B308_640238) {
                D_8029B32C_64025C = D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk4;
                D_8029B334_640264 = 0;
                D_8029B33C_64026C = 0;
                D_8029B340_640270 = 1;

                switch (D_8029B32C_64025C) {
                case 0x57:
                    D_80304364 = &D_8029AF40_63FE70;
                    break;
                case 0x120:
                    D_80304364 = &D_8029AF58_63FE88;
                    break;
                case 0x121:
                    D_80304364 = &D_8029AF88_63FEB8;
                    break;
                case 0x122:
                    D_80304364 = &D_8029AFCC_63FEFC;
                    break;
                case 0x123:
                    D_80304364 = &D_8029AFF8_63FF28;
                    break;
                case 0x124:
                    D_80304364 = &D_8029B030_63FF60;
                    break;
                case 0x125:
                    D_80304364 = &D_8029B074_63FFA4;
                    break;
                case 0x126:
                    D_80304364 = &D_8029B094_63FFC4;
                    break;
                case 0x127:
                    D_80304364 = &D_8029B0C4_63FFF4;
                    break;
                case 0x128:
                    D_80304364 = &D_8029B0F0_640020;
                    break;
                case 0x129:
                    D_80304364 = &D_8029B120_640050;
                    break;
                case 0x12A:
                    D_80304364 = &D_8029B150_640080;
                    break;
                case 0xFF:
                    D_80304364 = &D_8029B170_6400A0;
                    break;
                }

                if (D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk4 != 0xFF) {
                    if (D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk4 == 0x57) {
                        spC0 = 0x2500;
                    } else {
                        spC0 = 0x5500;
                    }
                    if (D_8029B520_640450 == 0) {
                        if (D_802042B4 == 0x3C) {
                            func_8013309C(D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk4, 0, spC0, 1.2f, 0);
                        } else {
                            func_8013309C(D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk4, 0, spC0, 1.0f, 0);
                        }
                    }
                }
                D_8029B318_640248 = D_8029B318_640248 + 1;
            } else {
                if ((D_8029AE60_63FD90[D_8029B4F0_640420].unk0[D_8029B318_640248].unk0 == 0) && (D_8029B4F0_640420 < 0x1C)) {
                    D_8029B318_640248 = 0;
                    D_8029B308_640238 = 0;
                    D_8029B4F0_640420++;
                }
            }
            if (D_8029B340_640270 != 0) {
                if (D_80304364[D_8029B33C_64026C].length == D_8029B334_640264) {
                    D_80304360 = D_80304364[D_8029B33C_64026C].tile;
                    D_80304361 = D_80304364[D_8029B33C_64026C].unk6;
                    D_8029B33C_64026C = D_8029B33C_64026C + 1;
                }
                D_8029B334_640264 = D_8029B334_640264 + 1;
            }
        }
        if (D_8029B4F0_640420 == 0x11) {
            D_8029B4F0_640420++;
            D_8029B2FC_64022C = 9;
            gDPSetPrimColor(D_801D9E9C++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            D_8029B518_640448 = 0;
            D_8029B310_640240 = 0x69;
            D_8029B30C_64023C = 0;
            D_8029B510_640440 = -2;
            UnpackRNC(&D_802C8190_66D0C0, D_80304388 + 0x3A000);
        }
        if (D_8029B4F0_640420 == 0x1C) {
            D_8029B4F0_640420 = 0xFF;
            D_8029B314_640244 = 1;
            func_80132F90(0x56, 0x5000);
            D_80304360 = 1;
        }
        func_80296114_63B044(D_80304360, D_80304361);
        if ((D_8029B4F0_640420 > 0) && (D_8029B4F0_640420 < 4)) {
            if (D_8029B51C_64044C != 0) {
                UnpackRNC(&D_802DBE00_680D30, D_80304388 + 0x3A000);
                func_80295E00_63AD30(D_80304388 + 0x3A000, 1);
            } else if (D_8029B4F0_640420 == 1) {
                func_80295E00_63AD30(D_80304388 + 0x3A000, 1);
            } else {
                func_80295E00_63AD30(D_80304388 + 0x3A000, 0);
            }
            D_8029B51C_64044C = 0;
        }
        if ((D_8029B4F0_640420 >= 5) && (D_8029B4F0_640420 < 8)) {
            if (D_8029B51C_64044C != 0) {
                UnpackRNC(&D_802D15F0_676520, D_80304388 + 0x3A000);
                func_80295E00_63AD30(D_80304388 + 0x3A000, 1);
            } else if (D_8029B4F0_640420 == 5) {
                func_80295E00_63AD30(D_80304388 + 0x3A000, 1);
            } else {
                func_80295E00_63AD30(D_80304388 + 0x3A000, 0);
            }
            D_8029B51C_64044C = 0;
        }
        if (((s32) D_8029B4F0_640420 >= 0xE) && ((s32) D_8029B4F0_640420 < 0x11)) {
            if (D_8029B51C_64044C != 0) {
                UnpackRNC(&D_802A4CE0_649C10, D_80304388 + 0x3A000);
                func_80295E00_63AD30(D_80304388 + 0x3A000, 1);
            } else if (D_8029B4F0_640420 == 0xE) {
                func_80295E00_63AD30(D_80304388 + 0x3A000, 1);
            } else {
                func_80295E00_63AD30(D_80304388 + 0x3A000, 0);
            }
            D_8029B51C_64044C = 0;
        }
        if ((D_8029B4F0_640420 == 4) || (D_8029B4F0_640420 == 8)) {
            D_8029B51C_64044C = 1;
        }
        if (D_8029B4F0_640420 != 0xFF) {
            if (D_8029AE64_63FD94[D_8029B4F0_640420].id != 0xD) {
                func_8012C210(&D_801D9E9C);
                func_8012C234(0xFFU, 0xFFU, 0xFF, 0xFF);
                func_8012C268(0, 1, 1, 0);
                func_8012EB6C(&D_801D9E9C, get_message_address_by_id(D_8029AE64_63FD94[D_8029B4F0_640420].id), 0xA0, 0xCA, 16.0f, 16.0f, 0x10);
            }
        } else if ((s32) D_8029B308_640238 >= 0x2E) {
            D_8029B520_640450 = 1;
            D_8029B538_640468 = 0;
            D_8029B308_640238 = 0;
            D_8029B30C_64023C = 0xFF;
            D_8029B2D0_640200 = 270.0f;
            D_8029B2D4_640204 = 180.0f;
            D_8029B2D8_640208 = 180.0f;
            D_8029B2B8_6401E8 = 0.0f;
            D_8029B2BC_6401EC = 0.0f;
            D_8029B2C0_6401F0 = 3800.0f;
            D_8029B2E8_640218 = -1.0f;
            D_8029B2F4_640224 = 0.0f;
            if ((D_8023F2C0.unk8 & 1) != 0) {
                D_8023F2C0.unk8 = 0;
                spB6 = func_80130C50(4);
            }
        }
        break;
    case 9:
        gSPDisplayList(D_801D9E9C++, &D_801582E0);
        if ((D_8029B310_640240 == 0xFF) || (D_8029B310_640240 == 0x69)) {
            D_8029B510_640440 = -D_8029B510_640440;
        }
        gDPSetPrimColor(D_801D9E9C++, 0, 0, 255, 255, D_8029B310_640240, 255);
        D_8029B310_640240 = D_8029B310_640240 + D_8029B510_640440;
        func_80135CF8(0, 0, 0x140, 0x100, &D_801D9E9C, D_80304388 + 0x3A000);
        if (D_8029B30C_64023C++ > 0x14) {
            func_80135CF8(0xDC, 0x8C, 0x40, 0x40, &D_801D9E9C, &D_802C0670_6655A0);
            if (D_8029B30C_64023C == 0x28) {
                D_8029B30C_64023C = 0;
            }
        }
        if (D_8029B518_640448++ == 0x12C) {
            D_8029B2FC_64022C = 2;
            D_8029B310_640240 = 0xFF;
        }
        break;
    case 3:
        if (D_8029B31C_64024C == 1) {
            D_8015519C = 1.0f;
            D_80154700 = 0x800;
            D_801546F8 = 0x800;
            D_8028647C = 0x13;
            // dupe
            D_8015519C = 1.0f;
            D_80154700 = 0x800;
            D_801546F8 = 0x800;
        }
        spC3 = 0;
        D_8029B2D4_640204 = D_8029B2D4_640204 + 1.0f;
        if ((f64) D_8029B2D4_640204 > 359.0) {
            D_8029B2D4_640204 = 0.0f;
        }
        D_8029B2F4_640224 = D_8029B2F4_640224 + 1.0f;
        if (D_8029B2F4_640224 > 359.0f) {
            D_8029B2F4_640224 = 0.0f;
        }
        if ((s32) D_8029B31C_64024C < 0x708) {
            D_8029B2D8_640208 = D_8029B2D8_640208 + 1.0f;
            if ((f64) D_8029B2D8_640208 > 359.0) {
                D_8029B2D8_640208 = 0.0f;
            }
            D_8029B2C4_6401F4 = (*(&D_80152640 + ((s16) (s32) D_8029B2F4_640224)) * D_8029B2F8_640228);
            D_8029B2C8_6401F8 = 0.0f;
            D_8029B2CC_6401FC = ((*(&D_801526F4 + ((s16) (s32) D_8029B2F4_640224)) * D_8029B2F8_640228) - 0x9C4);
        }
        if ((s32) D_8029B31C_64024C >= 0x708) {
            if (D_8029B31C_64024C == 0x708) {
                func_801337FC(0, 4.0f, 20.0f, 0);
            }
            D_8029B2C4_6401F4 = D_8029B2C4_6401F4 + 42.0f;
            D_8029B310_640240 = 0x1617 - (D_8029B31C_64024C * 3);
        }
        func_80294EFC_639E2C(&D_801D9E9C);
        func_802953C4_63A2F4();
        func_80136438(&D_801D9E9C, D_8029B310_640240);
        func_801360E8(&D_801D9E9C, D_80304388 + 0x50000, 0x100, 0x80, 0x100, 0x7E, 0, 0, 0x20, 0x20, 0xFDE8);
        func_80136438(&D_801D9E9C, D_8029B310_640240);
        func_801360E8(&D_801D9E9C, D_80304388 + 0x28000, 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);
        func_80129300(&D_801D9E9C, D_80204298);
        func_8012C210(&D_801D9E9C);
        func_8012C234(D_8029B310_640240, D_8029B310_640240, 0, 0xFF);
        func_8012C268(0, 0, 0, 0);
        if (((s32) D_8029B31C_64024C < 0x708) && (D_802912F8 != 0)) {
            func_8012C998(&D_801D9E9C, get_message_address_by_id(0xE), 0xA0, 0xC8, 16.0f, 16.0f);
        }
        D_8029B31C_64024C++;
        if (D_8029B31C_64024C >= 0x75D) {
            if (D_802042A8 >= 6) {
                D_802042A8 = 0;
            }
            D_802042A8++;
            if (D_802042A8 == 1) {
                D_8029B308_640238 = 0;
                D_8029B310_640240 = 0x37;
                D_8029B2FC_64022C = 1;
                D_8029B2C0_6401F0 = 6000.0f;
                D_8029B514_640444 = 0x2E;
                D_8029B4EC_64041C = 0;
            } else {
                func_801337FC(0, 10.0f, 20.0f, 0);
                func_8029A144_63F074(arg0->unk3BBE8, D_80304388 + 0x62000);
                D_8029B2FC_64022C = 0xA;
                D_8029B4F8_640428 = 0;
                D_8029B304_640234 = 1;
                D_8029B50C_64043C = 0x20;
                D_8028647C = 0;
            }
        }
        break; // urgh
        break;
    case 5:
        D_8015519C = 1.0f;
        D_80154700 = 0x800;
        D_801546F8 = 1;
        D_8028647C = 0x12;
        D_8029B310_640240 = 0xFF;
        if (D_8029B2C4_6401F4 == -2616.0f) {
            UnpackRNC(&D_802ABCB0_650BE0, D_80304388 + 0x50000);
        }

        gSPDisplayList(D_801D9E9C++, &D_801582E0);
        D_8029B2C4_6401F4 = D_8029B2C4_6401F4 + 42.0f;
        D_8029B2D4_640204 = D_8029B2D4_640204 + 1.0f;
        if ((f64) D_8029B2D4_640204 >= 359.0) {
            D_8029B2D4_640204 = 0.0f;
        }
        D_8029B308_640238 = D_8029B308_640238 + 1;
        func_80294EFC_639E2C(&D_801D9E9C);
        func_802953C4_63A2F4();
        D_80304370 = D_80304388 + 0x28000;
        func_80136438(&D_801D9E9C, D_8029B310_640240);
        func_801360E8(&D_801D9E9C, D_80304388 + 0x28000, 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);
        func_801360E8(
            &D_801D9E9C,
            D_80304388 + 0x50000,
            0x100,
            0x80,
            D_8029B4FC_64042C + D_8029B308_640238 * 4,
            D_8029B500_640430 + D_8029B308_640238 * 2,
            0,
            0,
            0x9C - D_8029B308_640238 * 2,
            0x5E - D_8029B308_640238,
            0xFDE8);
        if (D_8029B50C_64043C != 0) {
            func_80299E00_63ED30(D_8029B50C_64043C);
            D_8029B50C_64043C = D_8029B50C_64043C - 1;
        }
        if (D_8029B2C4_6401F4 == -12.0f) {
            D_8029B2FC_64022C = 3;
            D_8029B504_640434 = 1.0f;
            D_8029B310_640240 = 0xFF;
            D_8029B31C_64024C = 0;
            D_8029B308_640238 = 0;
        }
        break;
    case 6:
        if (D_8029B31C_64024C == 0) {
            D_8029B310_640240 = 0;
        }
        D_8028647C = 0;
        D_802042B0 = 1;
        D_8029B328_640258 = 0;
        D_8029B31C_64024C = 0;
        D_8029B30C_64023C = 0;
        D_8029B4EC_64041C = 0;
        D_8029B310_640240 = 0xFF;
        D_8029B4F4_640424 = 1;
        D_8029B504_640434 = 1.0f;
        D_8029B508_640438 = 1.0f;
        D_8029B2FC_64022C = 5;
        D_8029B4F8_640428 = 1;
        D_8029B304_640234 = 1;
        D_8029B308_640238 = 0;
        D_8029B30C_64023C = 0xFF;
        D_8029B2D0_640200 = 270.0f;
        D_8029B2D4_640204 = 110.0f;
        D_8029B2D8_640208 = 180.0f;
        D_8029B2B8_6401E8 = 0.0f;
        D_8029B2BC_6401EC = 0.0f;
        D_8029B2C0_6401F0 = 3800.0f;
        D_8029B2E8_640218 = -1.0f;
        D_8029B2F4_640224 = 0.0f;
        D_8029B2C4_6401F4 = -2616.0f;
        D_8029B2C8_6401F8 = 0.0f;
        D_8029B2CC_6401FC = -196.0f;
        D_8029B50C_64043C = 0;

        if ((D_802042A8 == 0xA) && ((D_8023F2C0.unk8 & 1) == 1)) {
            D_802042A8 = 0;
            D_8029B308_640238 = 0;
            D_8029B310_640240 = 0x37;
            D_8029B2FC_64022C = 1;
            D_8029B2C0_6401F0 = 6000.0f;
            D_8029B514_640444 = 0x2E;
        }
        break;
    case 10:
        func_80295CCC_63ABFC(&D_801D9E9C);
        if (D_8029B50C_64043C != 0) {
            func_80299E00_63ED30(D_8029B50C_64043C);
            D_8029B50C_64043C = D_8029B50C_64043C - 1;
            if (D_8029B50C_64043C == 0) {
                func_80133758();
                D_8029B324_640254 = 1;
            }
        }
        break;
    case 8:
        func_80295CCC_63ABFC(&D_801D9E9C);
        func_80294EFC_639E2C(&D_801D9E9C);
        func_802953C4_63A2F4();
        func_80136438(&D_801D9E9C, D_8029B310_640240);
        func_801360E8(&D_801D9E9C, D_80304388 + 0x28000, 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);
        func_801360E8(&D_801D9E9C, D_80304388 + 0x50000, 0x100, 0x80, 0x100, 0x7E, 0, 0, 0x20, 0x20, 0xFDE8);

        D_8029B2C4_6401F4 = D_8029B2C8_6401F8 = D_8029B2CC_6401FC = 0.0f;
        D_8029B2B8_6401E8 = D_8029B2BC_6401EC = 0.0f;
        D_8029B2C0_6401F0 = 4000.0f;

        if (D_8029B2D8_640208++ >= 359.0f) {
            D_8029B2D8_640208 = 0.0f;
        }
        if (D_8029B2D4_640204++ >= 359.0f) {
            D_8029B2D4_640204 = 0.0f;
        }
        if (D_8029B2D0_640200++ >= 359.0f) {
            D_8029B2D0_640200 = 0.0f;
        }
        break;
    default:
        break;
    }
    if (D_8029B520_640450 != 0) {
        D_8029B530_640460 = 0xFF;
        if (D_8029B4F8_640428 == 0) {
            D_8029B4F8_640428 = 1;
            D_8029B534_640464 = 0;
            D_8029B52C_64045C = 180.0f;
            D_8029B524_640454 = 320;
            D_8029B528_640458 = 0;
        }
        if (D_8029B534_640464 == 0) {
            if (D_8029B524_640454 <= 0) {
                D_8029B534_640464 = 1;
            } else {
                D_8029B524_640454 = D_8029B524_640454 - 0x14;
            }
        } else {
            if (D_8029B52C_64045C >= 359.0f) {
                D_8029B52C_64045C = 0.0f;
            }
            if (((s32) D_8029B52C_64045C % 180) == 0) {
                D_8029B528_640458 = D_8029B528_640458 + 4;
            }
            D_8029B524_640454 = ABS(*(&D_80152640 + ((s16) (s32) D_8029B52C_64045C)) / (s32) D_8029B528_640458);
            if ((s32) D_8029B528_640458 < 5) {
                D_8029B52C_64045C = D_8029B52C_64045C + 6.0f;
            }
        }
        func_80295CCC_63ABFC(&D_801D9E9C);
        D_80304370 = D_80304388 + 0x28000;
        func_80296464_63B394(D_8029B524_640454);
        if ((s32) D_8029B528_640458 >= 5) {
            D_8029B2FC_64022C = 5;
            D_8029B520_640450 = 0;
            D_8029B308_640238 = 0;
            D_8029B30C_64023C = 0xFF;
            D_8029B2D0_640200 = 270.0f;
            D_8029B2D4_640204 = 110.0f;
            D_8029B2D8_640208 = 180.0f;
            D_8029B2B8_6401E8 = 0.0f;
            D_8029B2BC_6401EC = 0.0f;
            D_8029B2C0_6401F0 = 3800.0f;
            D_8029B2E8_640218 = -1.0f;
            D_8029B2F4_640224 = 0.0f;
            D_8029B2C4_6401F4 = -2616.0f;
            D_8029B2C8_6401F8 = 0.0f;
            D_8029B2CC_6401FC = -196.0f;
            D_8029B4FC_64042C = 8;
            D_8029B500_640430 = 2;
        }
    }
    if (((gControllerInput->button & START_BUTTON) != 0) && (D_8029B2FC_64022C == 3) && (D_8029B50C_64043C == 0) && (D_8029B520_640450 == 0)) {
        func_8013309C(0x8F, 0, 0x5000, 1.0f, 0);
        func_801337FC(0, 30.0f, 20.0f, 0);
        func_8012A420();
        // hack
        func_8029A144_63F074(*(s32*)&D_8019E260[(D_80152ED8 ^ 1)], D_80304388 + 0x62000);
        D_8029B2FC_64022C = 0xA;
        D_8029B4F8_640428 = 0;
        D_8029B304_640234 = 1;
        D_8029B50C_64043C = 0x20;
        D_8028647C = 0;
        D_802042A8 = 0;
    }
    if ((D_8029B304_640234 > 0) && (D_8029B304_640234 < 5)) {
        D_8029B304_640234++;
    } else {
        if (((gControllerInput->button & 0x1000) == 0) && ((gControllerInput->button & 0x8000) == 0)) {
            D_8029B304_640234 = 0;
        }
    }
    if ((gControllerInput->button & 0x1000) != 0) {
        if ((D_8029B2FC_64022C != 7) && (D_8029B2FC_64022C != 0xA) && (D_8029B304_640234 == 0) && (D_8029B320_640250 == 0)) {
            D_802042A8 = 0;
            if ((D_8029B2FC_64022C == 0) && ((s32) D_8029B308_640238 < 0x104)) {

            } else {
                if ((D_8029B2FC_64022C != 3) && (D_8029B520_640450 == 0) && (D_8029B2FC_64022C != 5)) {
                    if (((D_8029B2FC_64022C == 0) || (D_8029B2FC_64022C == 1) || (D_8029B2FC_64022C == 2) || (D_8029B2FC_64022C == 9)) && ((D_8023F2C0.unk8 & 1) == 1)) {

                    } else {
                        func_8013309C(0x8F, 0, 0x5000, 1.0f, 0);
                        func_8013387C(2.0f, 20.0f, 0);
                        func_801337FC(0, 2.0f, 20.0f, 0);
                        D_8029B520_640450 = 1;
                        D_8029B4F8_640428 = 0;
                        D_8029B304_640234 = 1;
                    }
                }
            }
        }
    }
}

extern Vp D_80152EC8;
extern struct018 *D_80204294;
extern struct018 D_80162678[2];

// #pragma GLOBAL_ASM("asm/nonmatchings/overlay1_639DA0/func_802998D0_63E800.s")
void func_802998D0_63E800(void) {
    gScreenWidth = 320;
    gScreenHeight = 240;

    func_80129300(&D_801D9E9C, D_80204298);
    func_80129430(&D_801D9E9C);

    gSPViewport(D_801D9E9C++, &D_80152EC8);
    gDPSetColorImage(D_801D9E9C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204294->unk3BBE8));
    gDPPipeSync(D_801D9E9C++);

    D_80152EC8.vp.vscale[0] = gScreenWidth * 2;
    D_80152EC8.vp.vscale[1] = gScreenHeight * 2;
    D_80152EC8.vp.vtrans[0] = gScreenWidth * 2;
    D_80152EC8.vp.vtrans[1] = gScreenHeight * 2;

    gSPTexture(D_801D9E9C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    D_80204298->usedSprites = 0;
    D_80204298->usedModelViewMtxs = 0;
    D_80204298->usedSprites = 0; // set twice
    D_80204298->unk39310 = 0;
    D_80204298->usedHilites = 0;

    func_80296590_63B4C0(&D_80162678[D_80152ED8]);
    if (D_8029B324_640254 != 0) {
        D_80152EB0 = 0;
        D_802042A4 = 4;
    }
}

void func_80299B28_63EA58(void) {
    gSPClearGeometryMode(D_801D9E9C++, -1);
    gSPSetGeometryMode(D_801D9E9C++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH | G_CLIPPING);

    gDPSetColorDither(D_801D9E9C++, G_CD_BAYER);

    gDPSetTextureLOD(D_801D9E9C++, G_TL_TILE);
    gDPSetTextureDetail(D_801D9E9C++, G_TD_CLAMP);
    gDPSetTextureLUT(D_801D9E9C++, G_TT_NONE);
    gDPSetTexturePersp(D_801D9E9C++, G_TP_PERSP);
    gDPSetTextureConvert(D_801D9E9C++, G_TC_FILT);

    gDPSetAlphaCompare(D_801D9E9C++, G_AC_NONE);
    gSPClipRatio(D_801D9E9C++, FRUSTRATIO_4);
    gDPSetDepthSource(D_801D9E9C++, G_ZS_PIXEL);
}
