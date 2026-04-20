#include <ultra64.h>
#include "common.h"
#include "pp.h"

// ========================================================
// definitions
// ========================================================

typedef struct {
    /* 0x0 */ u8 *glyphWidths;
    /* 0x4 */ u8 *glyphBitmapBase;
    /* 0x8 */ u8  width;
    /* 0x9 */ u8  height;
    /* 0xA */ u8  bitsPerPixel;
    /* 0xC */ u16 bytesPerGlyph;
} FontInfo;

s16  get_glyph_width(f32 width);
s16  process_text_token(s16 *text, u16 x, u16 y);
s16  get_char_type(s16 *text, u16 x, u16 y);
void func_8012FA78(Gfx **dl);
void func_8012FAD4(Gfx **dl, s32 addr);

// ========================================================
// .data
// ========================================================

// language file offsets at ROM 0x2fc00
u8* D_80154500[36*2] = {
    _lang_lang1_dat_rncSegmentRomStart, _lang_lang1_dat_rncSegmentRomEnd,
    _lang_lang2_dat_rncSegmentRomStart, _lang_lang2_dat_rncSegmentRomEnd,
    _lang_lang3_dat_rncSegmentRomStart, _lang_lang3_dat_rncSegmentRomEnd,
    _lang_lang4_dat_rncSegmentRomStart, _lang_lang4_dat_rncSegmentRomEnd,
    _lang_lang5_dat_rncSegmentRomStart, _lang_lang5_dat_rncSegmentRomEnd,
    _lang_lang6_dat_rncSegmentRomStart, _lang_lang6_dat_rncSegmentRomEnd,
    _lang_lang7_dat_rncSegmentRomStart, _lang_lang7_dat_rncSegmentRomEnd,
    _lang_lang8_dat_rncSegmentRomStart, _lang_lang8_dat_rncSegmentRomEnd,
    _lang_lang9_dat_rncSegmentRomStart, _lang_lang9_dat_rncSegmentRomEnd,
    _lang_lang10_dat_rncSegmentRomStart, _lang_lang10_dat_rncSegmentRomEnd,
    _lang_lang11_dat_rncSegmentRomStart, _lang_lang11_dat_rncSegmentRomEnd,
    _lang_lang12_dat_rncSegmentRomStart, _lang_lang12_dat_rncSegmentRomEnd,
    _lang_lang13_dat_rncSegmentRomStart, _lang_lang13_dat_rncSegmentRomEnd,
    _lang_lang14_dat_rncSegmentRomStart, _lang_lang14_dat_rncSegmentRomEnd,
    _lang_lang15_dat_rncSegmentRomStart, _lang_lang15_dat_rncSegmentRomEnd,
    _lang_lang16_dat_rncSegmentRomStart, _lang_lang16_dat_rncSegmentRomEnd,
    _lang_lang17_dat_rncSegmentRomStart, _lang_lang17_dat_rncSegmentRomEnd,
    _lang_lang18_dat_rncSegmentRomStart, _lang_lang18_dat_rncSegmentRomEnd,
    _lang_lang19_dat_rncSegmentRomStart, _lang_lang19_dat_rncSegmentRomEnd,
    _lang_lang20_dat_rncSegmentRomStart, _lang_lang20_dat_rncSegmentRomEnd,
    _lang_lang21_dat_rncSegmentRomStart, _lang_lang21_dat_rncSegmentRomEnd,
    _lang_lang22_dat_rncSegmentRomStart, _lang_lang22_dat_rncSegmentRomEnd,
    _lang_lang23_dat_rncSegmentRomStart, _lang_lang23_dat_rncSegmentRomEnd,
    _lang_lang24_dat_rncSegmentRomStart, _lang_lang24_dat_rncSegmentRomEnd,
    _lang_lang25_dat_rncSegmentRomStart, _lang_lang25_dat_rncSegmentRomEnd,
    _lang_lang26_dat_rncSegmentRomStart, _lang_lang26_dat_rncSegmentRomEnd,
    _lang_lang27_dat_rncSegmentRomStart, _lang_lang27_dat_rncSegmentRomEnd,
    _lang_lang28_dat_rncSegmentRomStart, _lang_lang28_dat_rncSegmentRomEnd,
    _lang_lang29_dat_rncSegmentRomStart, _lang_lang29_dat_rncSegmentRomEnd,
    _lang_lang30_dat_rncSegmentRomStart, _lang_lang30_dat_rncSegmentRomEnd,
    _lang_lang31_dat_rncSegmentRomStart, _lang_lang31_dat_rncSegmentRomEnd,
    _lang_lang32_dat_rncSegmentRomStart, _lang_lang32_dat_rncSegmentRomEnd,
    _lang_lang33_dat_rncSegmentRomStart, _lang_lang33_dat_rncSegmentRomEnd,
    _lang_lang34_dat_rncSegmentRomStart, _lang_lang34_dat_rncSegmentRomEnd,
    _lang_lang35_dat_rncSegmentRomStart, _lang_lang35_dat_rncSegmentRomEnd,
    _lang_lang36_dat_rncSegmentRomStart, _lang_lang36_dat_rncSegmentRomEnd,
};

s32 D_80154620 = 0; // alignment?

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


// ========================================================
// .bss
// ========================================================

s16 D_8022E3F0[7000]; // rnc decompress scratch area

// this should be 350?
u16 D_80231AA0[342];  // level text message offsets

LevelText D_80231D50; // level text data loaded into here

static u8  D_80235410[0x9dd0]; // holds decompressed rnc

static FontInfo currentFont;

static u8   textColorR;
static u8   textColorG;
static u8   textColorB;
static u8   textColorA;
static u8   useMonospacedFont; // 0 or 1
static u8   useDropShadow;
static f32  D_8023F1F8; // current font width / scale
static f32  D_8023F1FC; // current font height / scale

static s16  D_8023F200[3]; // unused
static s16  D_8023F206[1];
s16  D_8023F208[32];
static s16  D_8023F248[12];


// ========================================================
// .text
// ========================================================


void load_default_display_list(Gfx **dl) {
    gSPDisplayList((*dl)++, D_80154628);
}

// does not appear to be used for cutscenes
void set_menu_text_color(u8 r, u8 g, u8 b, u8 a) {
    textColorR = r; // textColorR
    textColorG = g; // textColorG
    textColorB = b; // textColorB
    textColorA = a; // textColorA
}

void select_font(u8 isMonospace, u8 fontType, u8 shadow, u8 arg3) {
    useMonospacedFont = isMonospace;
    useDropShadow = shadow;
    if (fontType == FONT_LCD) {
        select_lcd_font();
    } else {
        select_comic_sans_font();
    }
}

void select_comic_sans_font(void) {
    currentFont.glyphWidths = D_80154370;
    currentFont.glyphBitmapBase = _fontbufferSegmentStart;
    currentFont.width = 16;
    currentFont.height = 16;
    currentFont.bitsPerPixel = 4;
    currentFont.bytesPerGlyph = 128; // 16*16*0.5
}

void select_lcd_font(void) {
    currentFont.glyphBitmapBase = img_fonts_lcd_tileset_rgba16__png; // 7-segment display font
    currentFont.width = 16;
    currentFont.height = 16;
    currentFont.bitsPerPixel = 16;
    currentFont.bytesPerGlyph = 512; // 16*16*2
}

s16 get_glyph_width(f32 width) {
    f32 a = width / currentFont.width;
    s16 res = D_8023F1F8 * a;
    return res;
}

u8 convert_text_to_int(s16 *text) {
    u8 ret = 0, i = 0;

    while ((text[i] >= TILESET_ZERO) && (text[i] <= TILESET_NINE)) {
        ret = (ret*10 + text[i]) - TILESET_ZERO;
        i++;
    }
    return ret;
}

s16 get_message_width(s16 *text) {
    u16 res = 0;
    s16 time[4];
    char spFC[80];
    s16 sp5C[80];
    s16 tmp;

    while (*text != EOM) {
        tmp = *text;
        if (*text == TEXT_CONTROL_CHAR) {
            text++;
            if (*text == TEXT_TIMER) {
                // parse timer text
                time[0] = text[1];
                time[1] = text[2];
                time[2] = EOM;

                sprintf(spFC, "%d", D_8023F206[convert_text_to_int(time)]);
                prepare_text((u8*)spFC, sp5C);
                res += get_message_width(sp5C);
                text += 3;
            } else if (*text == TEXT_COLOR) {
                text += 2;
            }
        } else {
            switch (useMonospacedFont) {
            case 0:
                currentFont.glyphWidths += tmp;
                res += get_glyph_width(*currentFont.glyphWidths);
                currentFont.glyphWidths -= tmp;
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
            text++;
        }
    }
    return res;
}

s16 process_text_token(s16 *text, u16 x, u16 y) {
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
            func_8012D374(&gMainDL, D_8023F248, x, y, D_8023F1F8, D_8023F1FC, -1);
            return 1;
        }
        // change text color
        if (*text == TEXT_COLOR) {
            switch (*++text) {
            case TEXT_COLOR_RED:
                textColorR = 200;
                textColorG = 40;
                textColorB = 40;
                textColorA = 255;
                break;
            case TEXT_COLOR_GREEN:
                textColorR = 0;
                textColorG = 255;
                textColorB = 0;
                textColorA = 255;
                break;
            case TEXT_COLOR_BLUE:
                textColorR = 120;
                textColorG = 120;
                textColorB = 255;
                textColorA = 255;
                break;
            case TEXT_COLOR_YELLOW:
                textColorR = 255;
                textColorG = 255;
                textColorB = 0;
                textColorA = 255;
                break;
            case TEXT_COLOR_WHITE:
                textColorR = 255;
                textColorG = 255;
                textColorB = 255;
                textColorA = 255;
                break;
            case TEXT_COLOR_BLACK:
                textColorR = 0;
                textColorG = 0;
                textColorB = 0;
                textColorA = 255;
                break;
            case TEXT_COLOR_PURPLE:
                textColorR = 255;
                textColorG = 0;
                textColorB = 255;
                textColorA = 255;
                break;
            case TEXT_COLOR_CYAN:
                textColorR = 0;
                textColorG = 255;
                textColorB = 255;
                textColorA = 255;
                break;
            }
            return 2;
        }
    } else if (*text == NEWLINE) {
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
    msg_width = get_message_width(text) / 2;

    chr_width = ((s32) D_8023F1F8 - get_glyph_width(*currentFont.glyphWidths)) * useMonospacedFont;
    xpos = (x - msg_width) + (chr_width / 2);
    ypos = y;

    gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
    gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);

    // load tile
    func_8012FA78(dl);

    while (*text != EOM) {
        switch (process_text_token(text, xpos, ypos)) {
        case 1: // timer
            // increment xpos by length of timer text
            x += get_message_width(D_8023F248);
            text += 4; // skip over 4 chars
            break;
        case 2: // color change
            // no change to xpos
            text += 3; // skip over 3 chars
            break;
        case 0: // regular character
            gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
            gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);

            chr = *text;
            currentFont.glyphWidths += chr;
            load_glyph(dl, chr);

            chr_width = ((s32) D_8023F1F8 - get_glyph_width(*currentFont.glyphWidths)) * useMonospacedFont;

            // add drop shadow?
            if (useDropShadow) {

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

                gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
                gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);
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

            switch (useMonospacedFont) {
            case 0:
                x += get_glyph_width(*currentFont.glyphWidths);
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
            currentFont.glyphWidths -= chr;
            break;
        case 3: // newline
            // no change (not even to y?)
            text++; // skip over 1 char
            break;
        }
    }

    gDPPipeSync((*dl)++);
}

void func_8012D374(Gfx **dl, s16 *text, u16 x, u16 y, f32 width, f32 height, s16 maxChars) {
    u16 chr_width;
    s16 chr;
    s16 xpos;

    D_8023F1F8 = width;
    D_8023F1FC = height;

    gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
    gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);

    chr_width = ((s32) D_8023F1F8 - get_glyph_width(*currentFont.glyphWidths)) * useMonospacedFont;

    xpos = x + (chr_width / 2);

    func_8012FA78(dl);

    while ((*text != EOM) && (maxChars != 0)) {
        switch (process_text_token(text, xpos, y)) {
        case 1: // timer
            x += get_message_width(D_8023F248); // write out time
            text += 4;
            break;
        case 2: // change color
            text += 3;
            break;
        case 0:
            if (maxChars > 0) {
                maxChars += -1;
            }

            chr = *text;
            if (chr != TILESET_SPACE) {

                load_glyph(dl, chr);
                chr_width = (((s32) D_8023F1F8 - get_glyph_width(*(currentFont.glyphWidths + chr))) * useMonospacedFont);

                if (useDropShadow) {
                    gDPSetPrimColor((*dl)++, 0, 0, 0, 0, 0, 255);
                    gDPSetEnvColor((*dl)++, 0, 0, 0, 0);

                    gSPTextureRectangle(
                        (*dl)++,
                        ((s32)(x + (chr_width / 2)) + 1) << 2,
                        (y + 1) << 2,
                        (((s32)(x + (chr_width / 2)) + 1) + (s32) D_8023F1F8) << 2,
                        (y + 1 + (s32) D_8023F1FC) << 2,
                        G_TX_RENDERTILE,
                        0,
                        0,
                        16384.0f / D_8023F1F8,
                        16384.0f / D_8023F1FC
                    );

                    gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
                    gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);
                }

                gSPTextureRectangle(
                    (*dl)++,
                    ((s32)(x + (chr_width / 2))) << 2,
                    (y) << 2,
                    ((s32)(x + (chr_width / 2)) + (s32) D_8023F1F8) << 2,
                    (y + (s32) D_8023F1FC) << 2,
                    G_TX_RENDERTILE,
                    0,
                    0,
                    16384.0f / D_8023F1F8,
                    16384.0f / D_8023F1FC
                    );
            }

            switch (useMonospacedFont) {
            case 0:
                x += get_glyph_width(*(currentFont.glyphWidths + chr));
                if (width < 14.0f) {
                    x += 1;
                }
                break;
            case 1:
                x += D_8023F1F8;
                break;
            default:
                break; // required for matching
            }

            xpos = x + (chr_width / 2);
            text++;
            break;
        case 3:
            text++;
            break;
        }
    }

    gDPPipeSync((*dl)++);
}

void draw_glyph(Gfx **dl, s16 *text, u16 x, u16 y, f32 width, f32 height) {
    D_8023F1F8 = width;
    D_8023F1FC = height;
    func_8012FA78(dl);
    load_glyph(dl, *text);

    gSPTextureRectangle(
    /* pkt  */  (*dl)++,
    /* xl   */  x << 2,
    /* yl   */  y << 2,
    /* xh   */  (x + (s32) D_8023F1F8) << 2,
    /* yh   */  (y + (s32) D_8023F1FC) << 2,
    /* tile */  G_TX_RENDERTILE,
    /* s    */  0,
    /* t    */  0,
    /* dsdx */  16384.0f / D_8023F1F8,
    /* dtdy */  16384.0f / D_8023F1FC);
    gDPPipeSync((*dl)++);
}

void display_text(Gfx **dl, s16 *text, u16 x, u16 y, f32 width, f32 height) {
    s16 chr;
    s16 msg_width;
    u16 chr_width;

    D_8023F1F8 = width;
    D_8023F1FC = height;

    gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
    gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);

    msg_width = get_message_width(text);

    // load tile
    func_8012FA78(dl);

    while (*text != EOM) {
        chr = *text;
        currentFont.glyphWidths += chr;
        load_glyph(dl, chr);

        chr_width = ((s32) D_8023F1F8 - get_glyph_width(*currentFont.glyphWidths)) * useMonospacedFont;

        // add drop shadow
        if (useDropShadow) {
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

            gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
            gDPSetEnvColor((*dl)++, textColorR, textColorG, textColorB, textColorA);
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
            16384.0f / D_8023F1F8,
            16384.0f / D_8023F1FC
            );

        switch (useMonospacedFont) {
        case 0:
            x += get_glyph_width(*currentFont.glyphWidths);
            if (width < 14.0f) {
                x += 1;
            }
            break;
        case 1:
            x += D_8023F1F8;
            break;
        }

        text++;
        currentFont.glyphWidths -= chr;
    }

    gDPPipeSync((*dl)++);
}

s16 get_char_type(s16 *text, u16 arg1, u16 arg2) {
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

s16 func_8012E78C(s16 *text, f32 fontWidth, f32 fontHeight, u8 lineHeight) {
    s16 wchr;
    s16 xPos;
    u16 xPos2;
    u16 xStart;
    u16 var_s1;

    u8 chr;
    s32 shouldBreak;

    s16 *tmp;
    s16 xPos3;
    s16 yPos;
    s16 numLines;

    D_8023F1F8 = fontWidth;   // current font width / scale
    D_8023F1FC = fontHeight;  // current font height / scale

    xPos = 0;
    yPos = 0;
    numLines = 0;
    xStart = 0;
    xPos3 = 0;

    while (*text != EOM) {
        switch (get_char_type(text, xPos3, yPos)) {
        case 1:  // TEXT_TIMER
            xPos += 20;
            text += 4;  // skip over timer info
            break;
        case 2:  // TEXT_COLOR
            text += 3;  // skip over color info
            break;
        case 0: // normal text
            wchr = *text;
            currentFont.glyphWidths += wchr;

            xPos += get_glyph_width(*currentFont.glyphWidths);

            if (fontWidth < 14.0f) {
                xPos++;
            }
            xPos2 = xPos - 1;

            shouldBreak = 0;
            if (*text == TILESET_SPACE) {
                var_s1 = xPos2;
                tmp = text + 1;

                while ((*tmp != TILESET_SPACE) && (*tmp != EOM) && (!shouldBreak) && (*tmp != NEWLINE)) {
                    chr = *tmp;
                    currentFont.glyphWidths += chr;

                    var_s1 += get_glyph_width(*currentFont.glyphWidths);

                    if (var_s1 >= (gScreenWidth - 50)) {
                        // reset cursor position
                        xPos2 = xStart;
                        yPos += lineHeight;
                        xPos = xStart;
                        shouldBreak = 1;
                        numLines++;
                    }
                    currentFont.glyphWidths -= chr;
                    tmp++;
                }
            }

            if ((gEepromGlobal.language == LANG_JAPANESE) && (xPos2 >= (gScreenWidth - 60))) {
                yPos += lineHeight;
                xPos = xStart;
            }

            text++;

            xPos3 = xPos;

            // consume leading whitespace
            while ((*text == TILESET_SPACE) && (xPos == xStart)) { text++; }

            currentFont.glyphWidths -= wchr;
            break;
        case 3: // NEWLINE
            yPos += lineHeight;
            xPos = xStart;

            numLines++;
            text++;

            // consume leading whitespace
            while ((*text == TILESET_SPACE) && (xPos == xStart)) { text++; }
            break;
        }
    }

    numLines++;
    return numLines * lineHeight;
}

void display_text_word_wrapped(Gfx **dl, s16 *text, u16 xStart, u16 yStart, f32 arg4, f32 arg5, u8 lineHeight) {
    s16 wchr;       // sp256
    u8  sp154[0x102];

    u16 xPos2;
    u16 sp150;
    s16 *tmp;
    s16 *sp148;

    s16 pad[2];
    s16 pad4;

    s16 wchr2;
    s16 pad2;
    s16 xPos; // sp144?
    s16 yPos; // sp142

    s16 pad3;

    s16 sp124[10]; // col starts?
    s16 sp110[10]; // row starts?
    s16 numLines; // sp10E

    s16 var_s4;
    s16 var_s7;
    s16 xPos3;
    s16 i;
    s16 msgLength;
    u16 var_s1;

    s16 sp68[0x4C];

    s32 shouldBreak;
    s16 j;

    sp148 = text;

    xPos = 0;
    yPos = 0;

    bzero_sssv((u8*)&sp124, sizeof(sp124));
    bzero_sssv((u8*)&sp110, sizeof(sp110));

    var_s7 = 0;
    numLines = 0;
    xPos3 = 0;
    sp150 = xPos * 0; // bollox

    D_8023F1F8 = arg4;
    D_8023F1FC = arg5;

    while (*text != EOM) {
        switch (get_char_type(text, xPos3, yPos)) {                      /* irregular */
        case 1:  // TEXT_TIMER
            xPos += 20;
            var_s7 += 4;
            text += 4;
            sp124[numLines] += 4;
            break;
        case 2:  // TEXT_COLOR
            var_s7 += 3;
            text += 3;
            sp124[numLines] += 3;
            break;
        case 0:  // normal text
            wchr = *text;
            currentFont.glyphWidths += wchr;

            xPos += get_glyph_width(*currentFont.glyphWidths);

            xPos2 = xPos - 1;

            shouldBreak = 0;
            if (*text == TILESET_SPACE) {
                var_s1 = xPos2;
                tmp = text + 1;

                currentFont.glyphWidths -= wchr;

                while ((*tmp != TILESET_SPACE) && (*tmp != EOM) && (shouldBreak == 0) && (*tmp != NEWLINE)) {
                    wchr2 = *tmp;
                    currentFont.glyphWidths += wchr2;

                    var_s1 += get_glyph_width(*currentFont.glyphWidths);

                    if (var_s1 >= (gScreenWidth - 50)) {
                        xPos2 = 0; // xStart?
                        yPos += lineHeight;
                        xPos = sp150;
                        shouldBreak = 1;
                        numLines++;
                    }
                    currentFont.glyphWidths -= wchr2;
                    tmp++;
                }
                currentFont.glyphWidths += wchr;
            }

            // force correct register with temp var (a1/s3)
            tmp = text + 1;
            if ((gEepromGlobal.language == LANG_JAPANESE) && (xPos2 >= (gScreenWidth - 58)) && (*tmp != EOM)) {
                yPos += lineHeight;
                xPos = sp150;
            }

            xPos3 = xPos;

            var_s7++;
            text++;
            sp124[numLines]++;

            while ((*text == TILESET_SPACE) && (xPos == sp150)) {
                var_s7++;
                text++;
                sp124[numLines]++;
            }

            currentFont.glyphWidths -= wchr;
            if (xPos == sp150) {
                sp110[numLines] = var_s7;
            }
            break;
        case 3:
            yPos += lineHeight;
            xPos = sp150;

            numLines++;
            text++;
            var_s7++;

            while ((*text == TILESET_SPACE) && (xPos == sp150)) {
                text++;
                var_s7++;
            }

            sp110[numLines] = var_s7;
            break;
        }
    }

    numLines++;
    var_s4 = yStart - ((numLines - 1) * lineHeight);

    for (j = 0; j < numLines; j++) {

        memcpy_sssv((u8 *) &sp148[sp110[j]], (u8*)&sp68, sp124[j] * 2);
        sp68[sp124[j]] = EOM;

        // count spaces
        for (i = 0; sp68[i] == TILESET_SPACE; i++) {};

        // fill in spaces with EOMs
        msgLength = sp124[j] - 1;
        while ((i < msgLength) && (sp68[msgLength] == TILESET_SPACE)) {
            sp68[msgLength--] = EOM;
        }

        display_text_centered(dl, &sp68[i], xStart, var_s4, arg4, arg5);

        var_s4 += lineHeight;
    }
}

void func_8012F160(Gfx **dl, s16 *text, u16 x, u16 y, f32 fontWidth, f32 fontHeight, u16 maxWidth, u8 lineHeight) {
    s16 wchr;
    s16 chr;
    u16 xPos2;
    u16 sp48;
    s16 shouldBreak;
    s16 tmp;
    s16 *next;

    sp48 = x;

    D_8023F1F8 = fontWidth;
    D_8023F1FC = fontHeight;

    gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
    gDPSetEnvColor((*dl)++,        textColorR, textColorG, textColorB, textColorA);

    tmp = x;

    func_8012FA78(dl);

    while (*text != EOM) {

        switch (process_text_token(text, tmp, y)) {
        case 1: // timer
            x += get_message_width(D_8023F248);
            text += 4;
            break;
        case 2: // color change
            text += 3;
            break;
        case 0: // regular character
            gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
            gDPSetEnvColor((*dl)++,        textColorR, textColorG, textColorB, textColorA);

            shouldBreak = 0;

            wchr = *text;
            currentFont.glyphWidths += wchr;
            load_glyph(dl, wchr);

            // add drop-shadow
            if (useDropShadow) {
                gDPSetPrimColor((*dl)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
                gDPSetEnvColor((*dl)++,        0x00, 0x00, 0x00, 0x00);

                gSPTextureRectangle(
                /* pkt  */  (*dl)++,
                /* xl   */  (x + 1) << 2,
                /* yl   */  (y + 1) << 2,
                /* xh   */  ((x + 1) + (s32) D_8023F1F8) << 2,
                /* yh   */  ((y + 1) + (s32) D_8023F1FC) << 2,
                /* tile */  G_TX_RENDERTILE,
                /* s    */  0,
                /* t    */  0,
                /* dsdx */  16384.0f / D_8023F1F8,
                /* dtdy */  16384.0f / D_8023F1FC);

                gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
                gDPSetEnvColor((*dl)++,        textColorR, textColorG, textColorB, textColorA);
            }

            gSPTextureRectangle(
            /* pkt  */  (*dl)++,
            /* xl   */  x << 2,
            /* yl   */  y << 2,
            /* xh   */  (x + (s32) D_8023F1F8) << 2,
            /* yh   */  (y + (s32) D_8023F1FC) << 2,
            /* tile */  G_TX_RENDERTILE,
            /* s    */  0,
            /* t    */  0,
            /* dsdx */  16384.0f / D_8023F1F8,
            /* dtdy */  16384.0f / D_8023F1FC);

            x += get_glyph_width(*currentFont.glyphWidths);

            // check if next word will fit on current line
            if (*text == TILESET_SPACE) {

                xPos2 = x - 1;
                next = text + 1;
                while ((*next != TILESET_SPACE) && (*next != EOM) && (!shouldBreak)) {
                    chr = *next;
                    currentFont.glyphWidths += chr;

                    xPos2 += get_glyph_width(*currentFont.glyphWidths);

                    if (xPos2 >= maxWidth) {
                        y += lineHeight;
                        x = sp48; // reset xpos?
                        shouldBreak = 1;
                    }
                    currentFont.glyphWidths -= chr;
                    next++;
                }
            }

            tmp = x;
            text++;

            // consume leading whitespace
            while ((*text == TILESET_SPACE) && (x == sp48) && (*text != EOM)) { text++; }

            currentFont.glyphWidths -= wchr;
            break;
        case 3: // NEWLINE
            text++;
            break;
        }
    }

    gDPPipeSync((*dl)++);
}

void func_8012FA78(Gfx **dl) {
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE,   0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b,  1, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 60, 60);
}

void func_8012FAD4(Gfx **dl, s32 addr) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, K0_TO_PHYS(addr));
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

void load_glyph(Gfx **dl, s16 tileId) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, K0_TO_PHYS(currentFont.glyphBitmapBase + tileId * currentFont.bytesPerGlyph));
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

// returns updated vertical offset
s16 display_text_wrapped(Gfx **dl, s16 *text, u16 x, u16 y, f32 fontWidth, f32 fontHeight, u16 maxWidth, u8 lineHeight) {
    u8 shouldBreak;
    s16 var_s1;
    u16 chr;
    u16 xStart;
    s16 wchr;
    u16 xPos2, xPos3;
    s16 *next;
    char language;

    xStart = x;

    D_8023F1F8 = fontWidth;
    D_8023F1FC = fontHeight;

    gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
    gDPSetEnvColor((*dl)++,        textColorR, textColorG, textColorB, textColorA);

    // load tile
    func_8012FA78(dl);

    while (*text != EOM) {
        var_s1 = x;
        switch (process_text_token(text, var_s1, y)) {
        case 2: // color
            // no change to xpos
            text += 3;
            break;
        case 0: // normal char
            gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
            gDPSetEnvColor((*dl)++,        textColorR, textColorG, textColorB, textColorA);

            shouldBreak = 0;

            wchr = *text;
            load_glyph(dl, wchr);

            // add drop-shadow
            if (useDropShadow) {
                gDPSetPrimColor((*dl)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
                gDPSetEnvColor((*dl)++,        0x00, 0x00, 0x00, 0x00);

                gSPTextureRectangle(
                /* pkt  */  (*dl)++,
                /* xl   */  (x + 1) << 2,
                /* yl   */  (y + 1) << 2,
                /* xh   */  ((x + 1) + (s32) D_8023F1F8) << 2,
                /* yh   */  ((y + 1) + (s32) D_8023F1FC) << 2,
                /* tile */  G_TX_RENDERTILE,
                /* s    */  0,
                /* t    */  0,
                /* dsdx */  (16384.0f / D_8023F1F8),
                /* dtdy */  (16384.0f / D_8023F1FC)
                );

                gDPSetPrimColor((*dl)++, 0, 0, textColorR, textColorG, textColorB, textColorA);
                gDPSetEnvColor((*dl)++,        textColorR, textColorG, textColorB, textColorA);
            }

            gSPTextureRectangle(
            /* pkt  */  (*dl)++,
            /* xl   */  x << 2,
            /* yl   */  y << 2,
            /* xh   */  (x + (s32) D_8023F1F8) << 2,
            /* yh   */  (y + (s32) D_8023F1FC) << 2,
            /* tile */  G_TX_RENDERTILE,
            /* s    */  0,
            /* t    */  0,
            /* dsdx */  (16384.0f / D_8023F1F8),
            /* dtdy */  (16384.0f / D_8023F1FC)
            );

            currentFont.glyphWidths += wchr;
            x += get_glyph_width(*currentFont.glyphWidths);
            currentFont.glyphWidths -= wchr;

            if (fontWidth < 13.0f) {
                x++;
            }

            xPos2 = x - 1;

            if (*text == TILESET_SPACE) {
                // check if next word will fit on current line
                xPos3 = x - 1;

                next = text + 1;
                while ((*next != TILESET_SPACE) && (*next != EOM) && (!shouldBreak)) {
                    chr = *next;
                    currentFont.glyphWidths += chr;
                    xPos3 += get_glyph_width(*currentFont.glyphWidths);
                    // wrap if we have exceeded desired line length
                    if (!(maxWidth > xPos3)) {
                        xPos2 = 0;
                        // move down to next line
                        y += lineHeight;
                        x = xStart;
                        shouldBreak = 1;
                    }
                    currentFont.glyphWidths -= chr;
                    next++;
                }
            }

            next = text + 1;
            if (gEepromGlobal.language == LANG_JAPANESE) {
                // japanese glyphs are wider so reduce threshold for end-of-line
                if (!(maxWidth - 10 > xPos2)) {
                    if (*next != EOM) {
                        y += lineHeight;
                        x = xStart;
                    }
                }
            }

            text++;
            break;

        case 3: // newline
            text++;
            break;
        }
    }

    gDPPipeSync((*dl)++);

    return y;
}

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
        currentFont.glyphWidths += digit;
        // anything missing here?
        width += 16;
        text++;
        currentFont.glyphWidths -= digit;
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
        currentFont.glyphWidths += digit;

        if (digit != 0) {
            gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &img_fonts_lcd_tileset_rgba16__png[((digit - 16) * 256) << 1]);
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
        currentFont.glyphWidths -= digit;
    }

    gDPPipeSync((*dl)++);
}

// naive map of ASCII to in-game font tilemap
void prepare_text(u8 *src, s16 *dst) {
    u8 tmp;
    while (*src != NULL) {
        tmp = *src;
        *dst++ = tmp + TILESET_ASCII_OFFSET;
        src++;
    }

    *dst = EOM;
}

s16 load_level_text_data(s16 language, s16 level, u16 *msg_offsets, s16 *dst) {
    s16 copied;
    s16 msg_length;
    s16 i;
    s16 *src;
    s16 num_msgs;
    u8 **lang;
    u8 (*new_var)[];

    if (D_80204240.region == REGION_EU) {
        if (language < LANG_MIN) {
            language = LANG_ENGLISH;
        }
        if (language > LANG_MAX) {
            language = LANG_ENGLISH;
        }
        // pointless check?
        if (language == LANG_DEFAULT) {
            language = LANG_ENGLISH;
        }
    }
    if (D_80204240.region == REGION_US) {
        language = LANG_ENGLISH;
    }
    if (D_80204240.region == REGION_JP) {
        language = LANG_JAPANESE;
    }

    // D_8022E3F0 is a scratch area:
    // 1. read into D_8022E3F0
    // 2. decompress from D_8022E3F0 into D_80235410
    // 3. copy 12000 bytes from D_80235410 into D_8022E3F0

    // each langXX.dat starts with header
    // the header contains 9 s32s that indicate the start of each language segment
    // each language segment starts with an s16 containing the number of messages
    // each message starts with an s16 containing the message length in bytes
    // each message ends with 0x7350 (30000)

    lang = &D_80154500[level+level];
    dma_read(lang[0], D_8022E3F0, lang[1] - lang[0]);
    UnpackRNC((RNC_fileptr)D_8022E3F0, D_80235410);

    // TODO: can this be replaced with a cast?
    new_var = &D_80235410;
    memcpy_sssv(((s32*)D_80235410)[language] + *new_var, (u8*)D_8022E3F0, 12000);

    num_msgs = D_8022E3F0[0];
    src = &D_8022E3F0[1]; // first message in segment

    // first s16 contains number of messages in segment
    for (i = 0, copied = 0; i < num_msgs; i++) {
        // first field is message length
        msg_length = *src++;
        // update offset as end of previous message
        msg_offsets[i] = copied;
        memcpy_sssv((u8*)src, (u8*)&dst[copied], msg_length);
        copied += msg_length;
        // message length is in bytes but source is characters (i.e. s16s)
        src += msg_length / 2;
    }

    return num_msgs;
}

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
