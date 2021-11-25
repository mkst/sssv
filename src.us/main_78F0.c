#include <ultra64.h>
#include "common.h"
#include "pp.h"

extern u8 lang_lang1_dat_rnc_ROM_START[], lang_lang1_dat_rnc_ROM_END[];
extern u8 lang_lang2_dat_rnc_ROM_START[], lang_lang2_dat_rnc_ROM_END[];
extern u8 lang_lang3_dat_rnc_ROM_START[], lang_lang3_dat_rnc_ROM_END[];
extern u8 lang_lang4_dat_rnc_ROM_START[], lang_lang4_dat_rnc_ROM_END[];
extern u8 lang_lang5_dat_rnc_ROM_START[], lang_lang5_dat_rnc_ROM_END[];
extern u8 lang_lang6_dat_rnc_ROM_START[], lang_lang6_dat_rnc_ROM_END[];
extern u8 lang_lang7_dat_rnc_ROM_START[], lang_lang7_dat_rnc_ROM_END[];
extern u8 lang_lang8_dat_rnc_ROM_START[], lang_lang8_dat_rnc_ROM_END[];
extern u8 lang_lang9_dat_rnc_ROM_START[], lang_lang9_dat_rnc_ROM_END[];
extern u8 lang_lang10_dat_rnc_ROM_START[], lang_lang10_dat_rnc_ROM_END[];
extern u8 lang_lang11_dat_rnc_ROM_START[], lang_lang11_dat_rnc_ROM_END[];
extern u8 lang_lang12_dat_rnc_ROM_START[], lang_lang12_dat_rnc_ROM_END[];
extern u8 lang_lang13_dat_rnc_ROM_START[], lang_lang13_dat_rnc_ROM_END[];
extern u8 lang_lang14_dat_rnc_ROM_START[], lang_lang14_dat_rnc_ROM_END[];
extern u8 lang_lang15_dat_rnc_ROM_START[], lang_lang15_dat_rnc_ROM_END[];
extern u8 lang_lang16_dat_rnc_ROM_START[], lang_lang16_dat_rnc_ROM_END[];
extern u8 lang_lang17_dat_rnc_ROM_START[], lang_lang17_dat_rnc_ROM_END[];
extern u8 lang_lang18_dat_rnc_ROM_START[], lang_lang18_dat_rnc_ROM_END[];
extern u8 lang_lang19_dat_rnc_ROM_START[], lang_lang19_dat_rnc_ROM_END[];
extern u8 lang_lang20_dat_rnc_ROM_START[], lang_lang20_dat_rnc_ROM_END[];
extern u8 lang_lang21_dat_rnc_ROM_START[], lang_lang21_dat_rnc_ROM_END[];
extern u8 lang_lang22_dat_rnc_ROM_START[], lang_lang22_dat_rnc_ROM_END[];
extern u8 lang_lang23_dat_rnc_ROM_START[], lang_lang23_dat_rnc_ROM_END[];
extern u8 lang_lang24_dat_rnc_ROM_START[], lang_lang24_dat_rnc_ROM_END[];
extern u8 lang_lang25_dat_rnc_ROM_START[], lang_lang25_dat_rnc_ROM_END[];
extern u8 lang_lang26_dat_rnc_ROM_START[], lang_lang26_dat_rnc_ROM_END[];
extern u8 lang_lang27_dat_rnc_ROM_START[], lang_lang27_dat_rnc_ROM_END[];
extern u8 lang_lang28_dat_rnc_ROM_START[], lang_lang28_dat_rnc_ROM_END[];
extern u8 lang_lang29_dat_rnc_ROM_START[], lang_lang29_dat_rnc_ROM_END[];
extern u8 lang_lang30_dat_rnc_ROM_START[], lang_lang30_dat_rnc_ROM_END[];
extern u8 lang_lang31_dat_rnc_ROM_START[], lang_lang31_dat_rnc_ROM_END[];
extern u8 lang_lang32_dat_rnc_ROM_START[], lang_lang32_dat_rnc_ROM_END[];
extern u8 lang_lang33_dat_rnc_ROM_START[], lang_lang33_dat_rnc_ROM_END[];
extern u8 lang_lang34_dat_rnc_ROM_START[], lang_lang34_dat_rnc_ROM_END[];
extern u8 lang_lang35_dat_rnc_ROM_START[], lang_lang35_dat_rnc_ROM_END[];
extern u8 lang_lang36_dat_rnc_ROM_START[], lang_lang36_dat_rnc_ROM_END[];

// language file offsets at ROM 0x2fc00
struct066 D_80154500[37] = {
    {lang_lang1_dat_rnc_ROM_START, lang_lang1_dat_rnc_ROM_END},
    {lang_lang2_dat_rnc_ROM_START, lang_lang2_dat_rnc_ROM_END},
    {lang_lang3_dat_rnc_ROM_START, lang_lang3_dat_rnc_ROM_END},
    {lang_lang4_dat_rnc_ROM_START, lang_lang4_dat_rnc_ROM_END},
    {lang_lang5_dat_rnc_ROM_START, lang_lang5_dat_rnc_ROM_END},
    {lang_lang6_dat_rnc_ROM_START, lang_lang6_dat_rnc_ROM_END},
    {lang_lang7_dat_rnc_ROM_START, lang_lang7_dat_rnc_ROM_END},
    {lang_lang8_dat_rnc_ROM_START, lang_lang8_dat_rnc_ROM_END},
    {lang_lang9_dat_rnc_ROM_START, lang_lang9_dat_rnc_ROM_END},
    {lang_lang10_dat_rnc_ROM_START, lang_lang10_dat_rnc_ROM_END},
    {lang_lang11_dat_rnc_ROM_START, lang_lang11_dat_rnc_ROM_END},
    {lang_lang12_dat_rnc_ROM_START, lang_lang12_dat_rnc_ROM_END},
    {lang_lang13_dat_rnc_ROM_START, lang_lang13_dat_rnc_ROM_END},
    {lang_lang14_dat_rnc_ROM_START, lang_lang14_dat_rnc_ROM_END},
    {lang_lang15_dat_rnc_ROM_START, lang_lang15_dat_rnc_ROM_END},
    {lang_lang16_dat_rnc_ROM_START, lang_lang16_dat_rnc_ROM_END},
    {lang_lang17_dat_rnc_ROM_START, lang_lang17_dat_rnc_ROM_END},
    {lang_lang18_dat_rnc_ROM_START, lang_lang18_dat_rnc_ROM_END},
    {lang_lang19_dat_rnc_ROM_START, lang_lang19_dat_rnc_ROM_END},
    {lang_lang20_dat_rnc_ROM_START, lang_lang20_dat_rnc_ROM_END},
    {lang_lang21_dat_rnc_ROM_START, lang_lang21_dat_rnc_ROM_END},
    {lang_lang22_dat_rnc_ROM_START, lang_lang22_dat_rnc_ROM_END},
    {lang_lang23_dat_rnc_ROM_START, lang_lang23_dat_rnc_ROM_END},
    {lang_lang24_dat_rnc_ROM_START, lang_lang24_dat_rnc_ROM_END},
    {lang_lang25_dat_rnc_ROM_START, lang_lang25_dat_rnc_ROM_END},
    {lang_lang26_dat_rnc_ROM_START, lang_lang26_dat_rnc_ROM_END},
    {lang_lang27_dat_rnc_ROM_START, lang_lang27_dat_rnc_ROM_END},
    {lang_lang28_dat_rnc_ROM_START, lang_lang28_dat_rnc_ROM_END},
    {lang_lang29_dat_rnc_ROM_START, lang_lang29_dat_rnc_ROM_END},
    {lang_lang30_dat_rnc_ROM_START, lang_lang30_dat_rnc_ROM_END},
    {lang_lang31_dat_rnc_ROM_START, lang_lang31_dat_rnc_ROM_END},
    {lang_lang32_dat_rnc_ROM_START, lang_lang32_dat_rnc_ROM_END},
    {lang_lang33_dat_rnc_ROM_START, lang_lang33_dat_rnc_ROM_END},
    {lang_lang34_dat_rnc_ROM_START, lang_lang34_dat_rnc_ROM_END},
    {lang_lang35_dat_rnc_ROM_START, lang_lang35_dat_rnc_ROM_END},
    {lang_lang36_dat_rnc_ROM_START, lang_lang36_dat_rnc_ROM_END},
    {0, 0} /* might just be alignment? */
};

// at ROM 0x2fd28
Gfx D_80154628[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetColorDither(G_CD_NOISE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};

void load_default_display_list(Gfx **arg0) {
    gSPDisplayList((*arg0)++, D_80154628);
}

// does not appear to be used for cutscenes
void set_menu_text_color(u8 r, u8 g, u8 b, u8 a) {
    D_8023F1F0 = r; // textColorR
    D_8023F1F1 = g; // textColorG
    D_8023F1F2 = b; // textColorB
    D_8023F1F3 = a; // textColorA
}

void select_font(u8 arg0, u8 fontType, u8 arg2, u8 arg3) {
    D_8023F1F4 = arg0;
    D_8023F1F5 = arg2;
    if (fontType == FONT_LCD) {
        select_lcd_font();
    } else {
        select_comic_sans_font();
    }
}

void select_comic_sans_font(void) {
    D_8023F1E0.unk0 = D_80154370;
    D_8023F1E0.fontAddress = D_800E1220; // _fontbufferSegmentStart
    D_8023F1E0.unk8 = 16; // width?
    D_8023F1E0.unk9 = 16; // height?
    D_8023F1E0.unkA = 4;  // color bitdepth?
    D_8023F1E0.glyphBytes = 128; // 16*16*0.5
}

void select_lcd_font(void) {
    D_8023F1E0.fontAddress = D_80158550; // 7-segment display font
    D_8023F1E0.unk8 = 16; // width?
    D_8023F1E0.unk9 = 16; // height?
    D_8023F1E0.unkA = 16; // color bitdepth?
    D_8023F1E0.glyphBytes = 512; // 16*16*2
}

s16 func_8012C314(f32 arg0) {
    f32 a = arg0 / D_8023F1E0.unk8;
    s16 res = D_8023F1F8 * a;
    return res;
}

u8 convert_text_to_int(s16 *arg0) {
    u8 ret = 0, i = 0;

    while ((arg0[i] >= TILESET_ZERO) && (arg0[i] <= TILESET_NINE)) {
        ret = (ret*10 + arg0[i]) - TILESET_ZERO;
        i++;
    }
    return ret;
}

// get_message_length ?
s16 func_8012C3D8(s16 *arg0) {
    u16 res = 0;
    s16 time[4];
    char spFC[80];
    s16 sp5C[80];
    s16 tmp;

    while (*arg0 != EOM) {
        tmp = *arg0;
        if (*arg0 == TEXT_CONTROL_CHAR) {
            arg0 += 1;
            if (*arg0 == TEXT_TIMER) {
                // parse timer text
                time[0] = arg0[1];
                time[1] = arg0[2];
                time[2] = EOM;

                sprintf(spFC, "%d", D_8023F206[convert_text_to_int(time)]);
                prepare_text((u8*)spFC, sp5C);
                res += func_8012C3D8(sp5C);
                arg0 += 3;
            } else if (*arg0 == TEXT_COLOR) {
                arg0 = arg0 + 2;
            }
        } else {
            switch (D_8023F1F4) {
            case 0:
                D_8023F1E0.unk0 += tmp;
                res += func_8012C314(*D_8023F1E0.unk0);
                D_8023F1E0.unk0 -= tmp;
                // if character width less than 14px?
                if (D_8023F1F8 < 14.0f) {
                    res += 1;
                }
                break;
            case 1:
                // increment by pixel width?
                res += D_8023F1F8;
                break;
            }
            arg0 += 1;
        }
    }
    return res;
}

s32 func_8012C678(s16 *arg0, u16 x, u16 y) {
    u8  spD8[80];
    s16 sp30[84];

    u8 i;
    s16 num = 0;

    if (*arg0 == TEXT_CONTROL_CHAR) {
        if (*++arg0 == TEXT_TIMER) {
            sp30[0] = *++arg0;
            sp30[1] = *++arg0;
            sp30[2] = EOM;

            i = 0;
            while ((sp30[i] >= TILESET_ZERO) && (sp30[i] <= TILESET_NINE)) {
                num = (num*10 + sp30[i]) - TILESET_ZERO;
                i++;
            }
            sprintf((char*)spD8, "%d", D_8023F206[num]);
            prepare_text(spD8, D_8023F248);
            func_8012D374(&D_801D9E7C, D_8023F248, x, y, D_8023F1F8, D_8023F1FC, -1);
            return 1;
        }
        // change text color
        if (*arg0 == TEXT_COLOR) {
            switch (*++arg0) {
            case TEXT_COLOR_RED:
                D_8023F1F0 = 200;
                D_8023F1F1 = 40;
                D_8023F1F2 = 40;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_GREEN:
                D_8023F1F0 = 0;
                D_8023F1F1 = 255;
                D_8023F1F2 = 0;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_BLUE:
                D_8023F1F0 = 120;
                D_8023F1F1 = 120;
                D_8023F1F2 = 255;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_YELLOW:
                D_8023F1F0 = 255;
                D_8023F1F1 = 255;
                D_8023F1F2 = 0;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_WHITE:
                D_8023F1F0 = 255;
                D_8023F1F1 = 255;
                D_8023F1F2 = 255;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_BLACK:
                D_8023F1F0 = 0;
                D_8023F1F1 = 0;
                D_8023F1F2 = 0;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_PURPLE:
                D_8023F1F0 = 255;
                D_8023F1F1 = 0;
                D_8023F1F2 = 255;
                D_8023F1F3 = 255;
                break;
            case TEXT_COLOR_CYAN:
                D_8023F1F0 = 0;
                D_8023F1F1 = 255;
                D_8023F1F2 = 255;
                D_8023F1F3 = 255;
                break;
            }
            return 2;
        }
    } else if (*arg0 == 20000) { // newline
        return 3;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/display_text.s")
// NON-MATCHING: plenty to do
// void display_text(Gfx **arg0, s16 *text, u16 x, u16 y, f32 width, f32 height) {
//     s16 tmp;
//     u16 temp_a3;
//     s32 temp_s1_2;
//     u16 temp_s2;
//     s32 temp_s5_2;
//     s32 temp_v0_2;
//     s16 phi_s1;
//     u16 phi_s4;
//     // s16 phi_v0;
//
//     D_8023F1F8 = width;
//     D_8023F1FC = height;
//
//     temp_s2 = func_8012C3D8(text) / 2;
//
//     phi_s1 = (x - temp_s2) + ((((s32) D_8023F1F8 - func_8012C314(*D_8023F1E0.unk0)) * D_8023F1F4) / 2);
//
//     gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//     gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//
//     // load tile
//     func_8012FA78(arg0);
//
//     phi_s4 = x;
//
//     while (*text != EOM) {
//         switch (func_8012C678(text, phi_s1, y)) {
//         case 0:
//             phi_s4 += func_8012C3D8(D_8023F248);
//             text += 4;
//             break;
//         case 1:
//             gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//
//             tmp = *text;
//             D_8023F1E0.unk0 += tmp;
//             load_glyph(arg0, tmp);
//
//             temp_a3 = ((s32) D_8023F1F8 - func_8012C314(*D_8023F1E0.unk0)) * D_8023F1F4;
//
//             // add drop shadow?
//             if (D_8023F1F5 != 0) {
//
//                 gDPSetPrimColor((*arg0)++, 0, 0, 0, 0, 0, 255);
//                 gDPSetEnvColor((*arg0)++, 0, 0, 0, 0);
//
//                 temp_v0_2 = (phi_s4 - temp_s2) + (temp_a3 / 2);
//                 gSPTextureRectangle(
//                     (*arg0)++,
//                     (temp_v0_2 + 1),
//                     (y + 1),
//                     (temp_v0_2 + (s32) D_8023F1F8 + 1),
//                     (y + (s32) D_8023F1FC + 1),
//                     G_TX_LOADTILE,
//                     0,
//                     0,
//                     (16384.0f / D_8023F1F8),
//                     (16384.0f / D_8023F1FC)
//                 );
//
//                 gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//                 gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             }
//
//             temp_v0_2 = (phi_s4 - temp_s2)  + (temp_a3 / 2);
//             gSPTextureRectangle(
//                 (*arg0)++,
//                 (temp_v0_2),
//                 (y),
//                 (temp_v0_2 + (s32) D_8023F1F8),
//                 (y + (s32) D_8023F1FC),
//                 G_TX_LOADTILE,
//                 0,
//                 0,
//                 (16384.0f / D_8023F1F8),
//                 (16384.0f / D_8023F1FC)
//             );
//
//             switch (D_8023F1F4) {
//             case 0:
//                 phi_s4 += func_8012C314(*D_8023F1E0.unk0);
//                 if (width < 14.0f) {
//                     phi_s4 += 1;
//                 }
//                 break;
//             case 1:
//                 phi_s4 += D_8023F1F8;
//                 break;
//             }
//
//             D_8023F1E0.unk0 = (D_8023F1E0.unk0 - tmp);
//             text += 1;
//             // phi_s1 = (phi_s4 - sp74) + temp_s1_2;
//             phi_s1 = (phi_s4 - temp_s2) + (temp_a3 / 2);
//
//             break;
//         case 2:
//             text += 3;
//             break;
//         default:
//             text += 1;
//             break;
//         }
//     }
//
//     gDPPipeSync((*arg0)++);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012D374.s")

void draw_glyph(Gfx **arg0, s16 *arg1, u16 x, u16 y, f32 width, f32 height) {
    D_8023F1F8 = width;
    D_8023F1FC = height;
    func_8012FA78(arg0);
    load_glyph(arg0, *arg1);

    gSPTextureRectangle((*arg0)++, x * 4, y * 4, (x + (s32) D_8023F1F8) * 4, (y + (s32) D_8023F1FC) * 4, G_TX_RENDERTILE, 0, 0, 16384.0f / D_8023F1F8, 16384.0f / D_8023F1FC);
    gDPPipeSync((*arg0)++);
}

// write text to screen
#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012DEF8.s")
// NON-MATCHING: 60%
// void func_8012DEF8(Gfx **arg0, s16 *text, u16 x, u16 y, f32 width, f32 height) {
//     s16 msgLen;
//     u16 temp_a3;
//     u16 temp_a2;
//     s16 phi_v0;
//
//
//     D_8023F1F8 = width;
//     D_8023F1FC = height;
//
//     gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//     gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//
//     msgLen = func_8012C3D8(text);
//     // load tile
//     func_8012FA78(arg0);
//
//     while (*text != EOM) {
//         phi_v0 = *text;
//         D_8023F1E0.unk0 += *text;
//         load_glyph(arg0, phi_v0);
//
//         temp_a3 = ((s32) D_8023F1F8 - func_8012C314(*D_8023F1E0.unk0)) * D_8023F1F4;
//         if (D_8023F1F5 != 0) {
//             gDPSetPrimColor((*arg0)++, 0, 0, 0, 0, 0, 255);
//             gDPSetEnvColor((*arg0)++, 0, 0, 0, 0);
//
//             temp_a2 = (x - msgLen) + (temp_a3 / 2);
//             gSPTextureRectangle(
//                 (*arg0)++,
//                 (temp_a2 + 1),
//                 (y + 1),
//                 (temp_a2 + 1 + (s32) D_8023F1F8),
//                 (y + 1 + (s32) D_8023F1FC),
//                 G_TX_LOADTILE,
//                 0,
//                 0,
//                 (16384.0f / D_8023F1F8),
//                 (16384.0f / D_8023F1FC)
//                 );
//
//             gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//         }
//
//         temp_a2 = (x - msgLen) + (temp_a3 / 2);
//         gSPTextureRectangle(
//             (*arg0)++,
//             (temp_a2),
//             (y),
//             (temp_a2 + (s32) D_8023F1F8),
//             (y + (s32) D_8023F1FC),
//             G_TX_LOADTILE,
//             0,
//             0,
//             (16384.0f / D_8023F1F8),
//             (16384.0f / D_8023F1FC)
//             );
//
//         switch (D_8023F1F4) {
//         case 0:
//             x += func_8012C314(*D_8023F1E0.unk0);
//             if (width < 14.0f) {
//                 x += 1;
//             }
//             break;
//         case 1:
//             x += D_8023F1F8;
//             break;
//         }
//
//         D_8023F1E0.unk0 -= phi_v0;
//         text += 1;
//     }
//
//     gDPPipeSync((*arg0)++);
// }

s32 func_8012E724(u16 *arg0, s32 arg1, s32 arg2) {
    s16 tmp = *arg0;
    if (tmp == TEXT_CONTROL_CHAR) {
        tmp = *++arg0;
        if (tmp == TEXT_TIMER) {
            return 1;
        } else if (tmp == TEXT_COLOR) {
            return 2;
        }
    } else if ((u16)tmp == NEWLINE) {
        return 3;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012E78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012EB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012F160.s")

void func_8012FA78(Gfx **arg0) {
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE,   0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b,  1, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 60, 60);
}

void func_8012FAD4(Gfx **dl, s32 arg1) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, arg1 & 0x1FFFFFFF);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

void load_glyph(Gfx **arg0, s16 tileId) {
    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (tileId * D_8023F1E0.glyphBytes + (s32)D_8023F1E0.fontAddress) & 0x1FFFFFFF);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*arg0)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FBEC.s")
// NON-MATCHING: quite a long way to go here...
// s16 func_8012FBEC(Gfx **arg0, s16 *arg1, s16 arg2, u16 arg3, f32 arg4, f32 arg5, u16 arg6, u8 arg7) {
//     s16 phi_v0;
//     s32 phi_s5;
//     s32 phi_s6;
//     s16 tmp;
//
//     D_8023F1F8 = arg4;
//     D_8023F1FC = arg5;
//
//     gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//     gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//
//     func_8012FA78(arg0);
//
//     while (*arg1 != EOM) {
//         tmp = *arg1;
//         switch (func_8012C678(arg1, arg2, arg3)) {
//         case 0:
//             gDPSetPrimColor((*arg0)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             gDPSetEnvColor((*arg0)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             load_glyph(arg0, tmp);
//             if (D_8023F1F5 != 0) {
//                 gDPSetPrimColor((*arg0)++, 0, 0, 0, 0, 0, 255);
//                 gDPSetEnvColor((*arg0)++, 0, 0, 0, 0);
//
//                 gSPTextureRectangle(
//                     (*arg0)++,
//                     4*(arg2 + 1),
//                     4*(arg3 + 1),
//                     4*(arg2 + (s32) D_8023F1F8 + 1),
//                     4*(arg3 + (s32) D_8023F1FC + 1),
//                     G_TX_LOADTILE,
//                     0,
//                     0,
//                     (16384.0f / D_8023F1F8),
//                     (16384.0f / D_8023F1FC)
//                 );
//                 gDPSetPrimColor((*arg0)++, 0, 0, 0, 0, 0, 255);
//                 gDPSetEnvColor((*arg0)++, 0, 0, 0, 0);
//             }
//
//             gSPTextureRectangle(
//                 (*arg0)++,
//                 4*arg2,
//                 4*arg3,
//                 4*(arg2 + (s32) D_8023F1F8),
//                 4*(arg3 + (s32) D_8023F1FC),
//                 G_TX_LOADTILE,
//                 0,
//                 0,
//                 (16384.0f / D_8023F1F8),
//                 (16384.0f / D_8023F1FC)
//             );
//
//             D_8023F1E0.unk0 += tmp;
//             arg3 = (arg3 + func_8012C314(*D_8023F1E0.unk0));
//             D_8023F1E0.unk0 -= tmp;
//             if (arg4 < 13.0f) {
//                 arg3 = arg3 + 1;
//             }
//
//             phi_s6 = arg3 - 1;
//
//             if (tmp == 0x130) {
//                 arg1 += 1;
//                 phi_s5 = 0;
//                 while ((*arg1 != 0x130) && (*arg1 != EOM) && (phi_s5 == 0)) {
//                     phi_v0 = *arg1;
//                     D_8023F1E0.unk0 = D_8023F1E0.unk0 + phi_v0;
//                     arg3 = (arg3 + func_8012C314(*D_8023F1E0.unk0));
//                     if (arg3 >= (s32) arg6) {
//                         arg3 = arg3 + arg7;
//                         phi_s5 = 1;
//                     }
//                     D_8023F1E0.unk0 = (D_8023F1E0.unk0 - phi_v0);
//                     arg1 += 1;
//                 }
//             }
//             arg1 += 1;
//             if (D_8023F2A0.language == LANG_JAPANESE) {
//                 if (phi_s6 >= (arg6 - 10)) {
//                     if (*arg1 != EOM) {
//                         arg3 = (arg3 + arg7);
//                     }
//                 }
//             }
//             break;
//         case 2: // color
//             arg1 += 3;
//             break;
//         case 3: // newline
//             arg1 += 1;
//             break;
//         }
//     }
//
//     gDPPipeSync((*arg0)++);
//
//     return arg3;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/display_score.s")
// void display_score(Gfx **arg0, u8 *text, u16 x_offset, u16 y_offset) {
//     s16 temp_t3;
//     u8 temp_t7;
//     s16 digits;
//     s16 temp_s3;
//
//     D_8023F1F8 = 16.0f;
//     D_8023F1FC = 16.0f;
//
//     digits = 0;
//     while (*text != 0) {
//         temp_t7 = (*text - 32) & 0xffff; // probably not it
//         D_8023F1E0.unk0 += temp_t7;
//         D_8023F1E0.unk0 -= temp_t7;
//         digits += 16; // how many.. chars? bytes? horizontal pixels?
//         text++;
//     }
//
//     gDPPipeSync((*arg0)++);
//     gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
//     gDPSetCombineMode((*arg0)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
//     gDPSetRenderMode((*arg0)++, Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
//     gDPSetDepthSource((*arg0)++, G_ZS_PRIM);
//     gDPSetPrimDepth((*arg0)++, 0, 0);
//     gDPSetTexturePersp((*arg0)++, G_TP_NONE);
//     gDPSetTextureLUT((*arg0)++, G_TT_NONE);
//     gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
//
//     while (*text != 0) {
//
//         temp_t7 = (*text - 32); // ASCII to ?
//         D_8023F1E0.unk0 += temp_t7;
//
//         if (temp_t7 != 0) {
//             s32 img = &D_80158550[(temp_t7 << 8)];
//             gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img - 4096);
//             gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
//             gDPLoadSync((*arg0)++);
//             gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 255, 512);
//             gDPPipeSync((*arg0)++);
//             gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
//             gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 60, 60);
//
//             // temp_t3 = x_offset - digits;
//             // temp_s3 = y_offset;
//             // temp_v0_18->unk0 = (s32) (((((temp_t3 + 0x18) * 4) & 0xFFF) << 12) | 0xE4000000 | (((temp_s3 + 0x10) * 4) & 0xFFF));
//             // temp_v0_18->unk4 = (s32) (((((temp_t3 + 8) * 4) & 0xFFF) << 12) | ((temp_s3 * 4) & 0xFFF));
//             gSPTextureRectangle(
//                 (*arg0)++,
//                 4*(((x_offset - digits) + 8)),
//                 4*((y_offset)),
//                 4*(((x_offset - digits) + 16)),
//                 4*((y_offset + 24)),
//                 G_TX_RENDERTILE,
//                 0,
//                 0,
//                 1024,
//                 1024);
//         }
//         D_8023F1E0.unk0 -= temp_t7;
//         x_offset += 16;
//         text++;
//     }
//
//     gDPPipeSync((*arg0)++);
// }

// naive map of ASCII to in-game font tilemap
void prepare_text(u8 *src, s16 *dst) {
    u8 tmp;
    while (*src != NULL) {
        tmp = *src;
        *dst++ = tmp + 272;
        src++;
    }

    *dst = 30000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/load_level_text_data.s")
// NON-MATCHING: language file offsets :(
// s16 load_level_text_data(s16 language, s16 level, u16 *msg_offsets, s16 *dst) {
//     s16 copied;
//     s16 msg_length;
//     s16 i;
//     s16 *src;
//     s32 start;
//     s32 end;
//     s16 num_msgs;
//     struct066 *lvl;
//
//     if (gRegion == REGION_EU) {
//         if (language < LANG_MIN) {
//             language = LANG_ENGLISH;
//         }
//         if (language > LANG_MAX) {
//             language = LANG_ENGLISH;
//         }
//         // pointless check?
//         if (language == LANG_DEFAULT) {
//             language = LANG_ENGLISH;
//         }
//     }
//     if (gRegion == REGION_US) {
//         language = LANG_ENGLISH;
//     }
//     if (gRegion == REGION_JP) {
//         language = LANG_JAPANESE;
//     }
//
//     // D_8022E3F0 is a scratch area:
//     // 1. read into D_8022E3F0
//     // 2. decompress from D_8022E3F0 into D_80235410
//     // 3. copy 12000 bytes from D_80235410 into D_8022E3F0
//
//     // each langXX.dat starts with header
//     // the header contains 9 s16s that indicate the start of each language segment
//     // each language segment starts with an s16 containing the number of messages
//     // each message starts with an s16 containing the message length in bytes
//     // each message ends with 0x7350 (30000)
//
//     lvl = &D_80154500[level];
//     dma_read(lvl->start, D_8022E3F0, lvl->end - lvl->start);
//     UnpackRNC((RNC_fileptr)D_8022E3F0, (u8*)D_80235410);
//     memcpy_sssv((u8*)D_80235410 + D_80235410[language], (u8*)D_8022E3F0, 12000);
//
//     src = &D_8022E3F0[1]; // first message in segment
//     copied = 0;
//
//     // first s16 contains number of messages in segment
//     num_msgs = D_8022E3F0[0];
//     for (i = 0; i < num_msgs; i++) {
//         // first field is message length
//         msg_length = *src++;
//         // update offset as end of previous message
//         msg_offsets[i] = copied;
//         memcpy_sssv((u8*)src, &dst[copied], msg_length);
//         copied += msg_length;
//         // message length is in bytes but source is shorts
//         src += msg_length / 2;
//     }
//
//     return num_msgs;
// }

// ========== file split? ========== //

s16 *get_message_address_by_id(s16 id) {
    return &D_8022E3F0[D_8022E3F0[id + 7000] + 7350];
}

s16 get_raw_message_length(s16 *msg) {
    s16 cnt = 0;

    while (*msg != EOM) {
        cnt++;
        msg++;
    };

    return cnt;
}
