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
u8* D_80154500[36][2] = {
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
};

u8 *D_80154620[2] = {0, 0}; /* might just be alignment? */

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

void load_default_display_list(Gfx **dl) {
    gSPDisplayList((*dl)++, D_80154628);
}

// does not appear to be used for cutscenes
void set_menu_text_color(u8 r, u8 g, u8 b, u8 a) {
    D_8023F1F0 = r; // textColorR
    D_8023F1F1 = g; // textColorG
    D_8023F1F2 = b; // textColorB
    D_8023F1F3 = a; // textColorA
}

void select_font(u8 arg0, u8 fontType, u8 shadow, u8 arg3) {
    D_8023F1F4 = arg0;
    D_8023F1F5 = shadow;
    if (fontType == FONT_LCD) {
        select_lcd_font();
    } else {
        select_comic_sans_font();
    }
}

void select_comic_sans_font(void) {
    D_8023F1E0.unk0 = D_80154370;
    D_8023F1E0.fontAddress = _fontbufferSegmentStart;
    D_8023F1E0.width = 16; // width?
    D_8023F1E0.height = 16; // height?
    D_8023F1E0.bits = 4;  // color bitdepth?
    D_8023F1E0.glyphBytes = 128; // 16*16*0.5
}

void select_lcd_font(void) {
    D_8023F1E0.fontAddress = D_80158550; // 7-segment display font
    D_8023F1E0.width = 16;
    D_8023F1E0.height = 16;
    D_8023F1E0.bits = 16; // color bitdepth?
    D_8023F1E0.glyphBytes = 512; // 16*16*2
}

s16 func_8012C314(f32 arg0) {
    f32 a = arg0 / D_8023F1E0.width;
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

// get_message_width?
s16 func_8012C3D8(s16 *text) {
    u16 res = 0;
    s16 time[4];
    char spFC[80];
    s16 sp5C[80];
    s16 tmp;

    while (*text != EOM) {
        tmp = *text;
        if (*text == TEXT_CONTROL_CHAR) {
            text += 1;
            if (*text == TEXT_TIMER) {
                // parse timer text
                time[0] = text[1];
                time[1] = text[2];
                time[2] = EOM;

                sprintf(spFC, "%d", D_8023F206[convert_text_to_int(time)]);
                prepare_text((u8*)spFC, sp5C);
                res += func_8012C3D8(sp5C);
                text += 3;
            } else if (*text == TEXT_COLOR) {
                text += 2;
            }
        } else {
            switch (D_8023F1F4) {
            case 0:
                D_8023F1E0.unk0 += tmp;
                res += func_8012C314(*D_8023F1E0.unk0);
                D_8023F1E0.unk0 -= tmp;
                // if font width less than 14px?
                if (D_8023F1F8 < 14.0f) {
                    res += 1;
                }
                break;
            case 1:
                // increment by font width?
                res += D_8023F1F8;
                break;
            }
            text += 1;
        }
    }
    return res;
}

s32 func_8012C678(s16 *text, u16 x, u16 y) {
    u8  spD8[80];
    s16 sp30[84];

    u8 i;
    s16 num = 0;

    if (*text == TEXT_CONTROL_CHAR) {
        if (*++text == TEXT_TIMER) {
            sp30[0] = *++text;
            sp30[1] = *++text;
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
        if (*text == TEXT_COLOR) {
            switch (*++text) {
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
    } else if (*text == 20000) { // newline
        return 3;
    }
    return 0;
}

void display_text_centered(Gfx **dl, s16 *text, u16 x, u16 y, f32 width, f32 height) {
    s16 chr;
    s16 ypos;
    s32 tmp_xpos;
    s16 xpos;
    u16 chr_width;
    u16 msg_width;

    s16 two = 2; // filth

    D_8023F1F8 = width;
    D_8023F1FC = height;

    // calculate half the width of the text
    msg_width = func_8012C3D8(text) / 2;

    chr_width = ((s32) D_8023F1F8 - func_8012C314(*D_8023F1E0.unk0)) * D_8023F1F4;
    xpos = (x - msg_width) + (chr_width / 2);
    ypos = y;

    gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
    gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);

    // load tile
    func_8012FA78(dl);

    while (*text != EOM) {
        switch (func_8012C678(text, xpos, ypos)) {
        case 1: // timer
            // increment xpos by length of timer text
            x += func_8012C3D8(D_8023F248);
            text += 4; // skip over 4 chars
            break;
        case 2: // color change
            // no change to xpos
            text += 3; // skip over 3 chars
            break;
        case 0: // regular character
            gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
            gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);

            chr = *text;
            D_8023F1E0.unk0 += chr;
            load_glyph(dl, chr);

            chr_width = ((s32) D_8023F1F8 - func_8012C314(*D_8023F1E0.unk0)) * D_8023F1F4;

            // add drop shadow?
            if (D_8023F1F5) {

                gDPSetPrimColor((*dl)++, 0, 0, 0, 0, 0, 255);
                gDPSetEnvColor((*dl)++, 0, 0, 0, 0);

                tmp_xpos = (x - msg_width) + (chr_width / 2);
                gSPTextureRectangle(
                    (*dl)++,
                    (tmp_xpos + 1) << 2,
                    (y + 1) << 2,
                    ((tmp_xpos + 1) + (s32) D_8023F1F8) << 2,
                    ((y + 1) + (s32) D_8023F1FC) << 2,
                    G_TX_RENDERTILE,
                    0,
                    0,
                    (16384.0f / D_8023F1F8),
                    (16384.0f / D_8023F1FC)
                );

                gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
                gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
            }

            tmp_xpos = (x - msg_width) + (chr_width / two);
            gSPTextureRectangle(
                (*dl)++,
                (tmp_xpos) << two,
                (y) << two,
                ((s32)tmp_xpos + (s32) D_8023F1F8) << two, // regalloc
                (y + (s32) D_8023F1FC) << two,
                G_TX_RENDERTILE,
                0,
                0,
                (16384.0f / D_8023F1F8),
                (16384.0f / D_8023F1FC)
            );

            switch (D_8023F1F4) {
            case 0:
                x += func_8012C314(*D_8023F1E0.unk0);
                if (width < 14.0f) {
                    x += 1;
                }
                break;
            case 1:
                x += D_8023F1F8;
                break;
            }

            xpos = (x - msg_width) + (chr_width / 2);
            text++;
            D_8023F1E0.unk0 -= chr;
            break;
        case 3: // newline
            // no change (not even to y?)
            text++; // skip over 1 char
            break;
        }
    }

    gDPPipeSync((*dl)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012D374.s")

void draw_glyph(Gfx **dl, s16 *text, u16 x, u16 y, f32 width, f32 height) {
    D_8023F1F8 = width;
    D_8023F1FC = height;
    func_8012FA78(dl);
    load_glyph(dl, *text);

    gSPTextureRectangle((*dl)++, x * 4, y * 4, (x + (s32) D_8023F1F8) * 4, (y + (s32) D_8023F1FC) * 4, G_TX_RENDERTILE, 0, 0, 16384.0f / D_8023F1F8, 16384.0f / D_8023F1FC);
    gDPPipeSync((*dl)++);
}

void display_text(Gfx **dl, s16 *text, u16 x, u16 y, f32 width, f32 height) {
    s16 chr;
    s16 msg_width;
    u16 chr_width;

    D_8023F1F8 = width;
    D_8023F1FC = height;

    gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
    gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);

    msg_width = func_8012C3D8(text);

    // load tile
    func_8012FA78(dl);

    while (*text != EOM) {
        chr = *text;
        D_8023F1E0.unk0 += chr;
        load_glyph(dl, chr);

        chr_width = ((s32) D_8023F1F8 - func_8012C314(*D_8023F1E0.unk0)) * D_8023F1F4;

        // add drop shadow?
        if (D_8023F1F5) {

            gDPSetPrimColor((*dl)++, 0, 0, 0, 0, 0, 255);
            gDPSetEnvColor((*dl)++, 0, 0, 0, 0);

            gSPTextureRectangle(
                (*dl)++,
                ((s32)((x - msg_width) + (chr_width / 2)) + 1) << 2,
                (y + 1) << 2,
                (((s32)((x - msg_width) + (chr_width / 2)) + 1) + (s32) D_8023F1F8) << 2,
                ((y + 1) + (s32) D_8023F1FC) << 2,
                G_TX_RENDERTILE,
                0,
                0,
                (16384.0f / D_8023F1F8),
                (16384.0f / D_8023F1FC)
                );

            gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
            gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
        }

        gSPTextureRectangle(
            (*dl)++,
            ((s32)((x - msg_width) + (chr_width / 2))) << 2,
            (y) << 2,
            ((s32)((x - msg_width) + (chr_width / 2)) + (s32) D_8023F1F8) << 2,
            (y + (s32) D_8023F1FC) << 2,
            G_TX_RENDERTILE,
            0,
            0,
            (16384.0f / D_8023F1F8),
            (16384.0f / D_8023F1FC)
            );

        switch (D_8023F1F4) {
        case 0:
            x += func_8012C314(*D_8023F1E0.unk0);
            if (width < 14.0f) {
                x += 1;
            }
            break;
        case 1:
            x += D_8023F1F8;
            break;
        }

        text++;
        D_8023F1E0.unk0 -= chr;
    }

    gDPPipeSync((*dl)++);
}

s32 func_8012E724(s16 *text, s32 arg1, s32 arg2) {
    if (*text == TEXT_CONTROL_CHAR) {
        // next char
        text++;
        if (*text == TEXT_TIMER) {
            return 1;
        } else if (*text == TEXT_COLOR) {
            return 2;
        }
    } else if ((*text & 0xFFFF) == NEWLINE) {
        return 3;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012E78C.s")

// contains delay slot
#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012EB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012F160.s")

void func_8012FA78(Gfx **dl) {
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE,   0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b,  1, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 60, 60);
}

void func_8012FAD4(Gfx **dl, s32 arg1) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, arg1 & 0x1FFFFFFF);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

void load_glyph(Gfx **dl, s16 tileId) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (tileId * D_8023F1E0.glyphBytes + (s32)D_8023F1E0.fontAddress) & 0x1FFFFFFF);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/display_text_wrapped.s")
// NON-MATCHING: quite a long way to go here...
// returns updated vertical offset
// s16 display_text_wrapped(Gfx **dl, s16 *text, u16 x, u16 y, f32 xs, f32 ys, u16 maxWidth, u8 lineSpacing) {
//     s16 phi_v0;
//     s16 end;
//     u16 phi_s6;
//     s32 chr;
//     u16 x_start;
//
//     D_8023F1F8 = xs;
//     D_8023F1FC = ys;
//
//     gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//     gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//
//     func_8012FA78(dl);
//
//     x_start = x;
//     while (*text != EOM) {
//         switch (func_8012C678(text, x, y)) {
//         case 2: // color
//             text += 3;
//             break;
//         case 0: // normal char
//             gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//
//             chr = *text;
//             load_glyph(dl, chr);
//
//             if (D_8023F1F5) { // drop shadow
//                 gDPSetPrimColor((*dl)++, 0, 0, 0, 0, 0, 255);
//                 gDPSetEnvColor((*dl)++, 0, 0, 0, 0);
//
//                 gSPTextureRectangle(
//                     (*dl)++,
//                     (x + 1) << 2,
//                     (y + 1) << 2,
//                     (x + 1 + (s32) D_8023F1F8) << 2,
//                     (y + 1 + (s32) D_8023F1FC) << 2,
//                     G_TX_RENDERTILE,
//                     0,
//                     0,
//                     (16384.0f / D_8023F1F8),
//                     (16384.0f / D_8023F1FC)
//                 );
//
//                 gDPSetPrimColor((*dl)++, 0, 0, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//                 gDPSetEnvColor((*dl)++, D_8023F1F0, D_8023F1F1, D_8023F1F2, D_8023F1F3);
//             }
//
//             gSPTextureRectangle(
//                 (*dl)++,
//                 x << 2,
//                 y << 2,
//                 (x + (s32) D_8023F1F8) << 2,
//                 (y + (s32) D_8023F1FC) << 2,
//                 G_TX_RENDERTILE,
//                 0,
//                 0,
//                 (16384.0f / D_8023F1F8),
//                 (16384.0f / D_8023F1FC)
//             );
//
//             D_8023F1E0.unk0 += chr;
//             x += func_8012C314(*D_8023F1E0.unk0);
//             D_8023F1E0.unk0 -= chr;
//
//             if (xs < 13.0f) {
//                 x++;
//             }
//
//             if (chr == TILESET_SPACE) {
//                 text += 1;
//                 end = 0;
//                 while ((*text != TILESET_SPACE) && (*text != EOM) && (end == 0)) {
//                     chr = *text;
//                     D_8023F1E0.unk0 += chr;
//                     x += func_8012C314(*D_8023F1E0.unk0);
//                     // if we have exceeded desired line length, wrap
//                     if (x >= maxWidth) {
//                         y += lineSpacing;
//                         x = 0; // x_start ?
//                         end = 1;
//                     }
//                     text += 1;
//                     D_8023F1E0.unk0 -= chr;
//                 }
//             }
//
//             if (D_8023F2A0.language == LANG_JAPANESE) {
//                 if (x >= (maxWidth - 10)) {
//                     if (*text != EOM) {
//                         y += lineSpacing;
//                         x = 0; // x_start ?
//                     }
//                 }
//             }
//             text += 1;
//             break;
//         case 3: // newline
//             text += 1;
//             break;
//         }
//     }
//
//     gDPPipeSync((*dl)++);
//
//     return y;
// }

void display_score(Gfx **dl, u8 *score, u16 x_offset, u16 y_offset) {
    u8 digit;
    s16 width;
    u8 *text;

    D_8023F1F8 = 16.0f;
    D_8023F1FC = 16.0f;

    text = score;

    // calculate width required to draw score?
    width = 0;
    while (*text != '\0') {
        digit = (*text - ' ');
        D_8023F1E0.unk0 += digit;
        // anything missing here?
        width += 16;
        text++;
        D_8023F1E0.unk0 -= digit;
    }

    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
    gDPSetCombineMode((*dl)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode((*dl)++, Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
    gDPSetDepthSource((*dl)++, G_ZS_PRIM);
    gDPSetPrimDepth((*dl)++, 0, 0);
    gDPSetTexturePersp((*dl)++, G_TP_NONE);
    gDPSetTextureLUT((*dl)++, G_TT_NONE);
    gDPSetAlphaCompare((*dl)++, G_AC_NONE);

    while (*score != '\0') {
        // 0 is ascii 48 so.. why -32?
        digit = (*score - ' ');
        D_8023F1E0.unk0 += digit;

        if (digit != 0) {
            gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_80158550[((digit - 16) * 256) << 1]);
            gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
            gDPLoadSync((*dl)++);
            gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 255, 512);
            gDPPipeSync((*dl)++);
            gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
            gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 60, 60);

            gSPTextureRectangle(
                (*dl)++,
                ((x_offset - width) + 8) << 2,
                y_offset << 2,
                ((x_offset - width) + 24) << 2,
                (y_offset + 16) << 2,
                G_TX_RENDERTILE,
                0,
                0,
                1024,
                1024);
        }

        x_offset += 16;
        score++;
        D_8023F1E0.unk0 -= digit;
    }

    gDPPipeSync((*dl)++);
}

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
//     s16 num_msgs;
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
//     dma_read(D_80154500[level][0], D_8022E3F0, D_80154500[level][1] - D_80154500[level][0]);
//
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
