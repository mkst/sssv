#include <ultra64.h>
#include "common.h"

typedef struct {
    u8 pad0[0x36B0];
    /* 0x36B0 */ u16 unk36B0[350];
    /* 0x396C */ u16 unk396C[350];
} foobar;

extern s16 D_801D9EF0;
extern foobar D_8022E410; // tbd
extern s32 D_802FEE20_6A3D50; // tbd
extern s32 D_802FFA20_6A4950; // tbd
extern s32 D_80300620_6A5550; // tbd
extern s32 D_80301220_6A6150; // tbd
extern s32 D_80301E20_6A6D50; // tbd
extern s32 D_80302A20_6A7950; // tbd
extern s32 D_80303620_6A8550; // tbd
extern s16 D_803B1900[20]; // tbd
extern s16 D_803B1A90;
extern s16 D_803B1A92;
extern s16 D_803B1A94;
extern s16 D_803B1A96;

extern s16 D_80231AC0[];
extern s16 D_80231D7C[];

extern s16 D_803B0592; // gScreenWidth
extern s16 D_803B0594; // gScreenHeight

void func_8013309C(s16, s16, s16, f32, u8);
s16  load_level_text_data(s16 language, s16 level, u16 *msg_lengths, s16 *dst);
s16 *get_message_address_by_id(s16);
void func_801366DC(Gfx **dl, u8 r, u8 g, u8 b, u8 a);
void func_80136958(Gfx **dl, uSprite *sprite, u16 width, u16 height, u16 scale_x, u16 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y, u8 depth);
void func_8012C998(Gfx **, s16*, u16, u16, f32, f32);

s16 language_select_menu(s16 arg0) {
    s16 sp86;
    s16 sp84;
    s16 *sp80;
    s16 *sp7C;
    s16 sp7A;
    s32 *sp74;
    s16 sp72;

    if (arg0 == 0) {
        sp86 = 0;
        for (sp84 = 0; sp84 < 9; sp84++) {
            load_level_text_data(sp84, 0x20, &D_8022E410.unk36B0, &D_8022E410.unk396C);
            if ((sp84 != 6) && (sp84 != 0)) {
                sp80 = get_message_address_by_id(MSG_LANGUAGE);
                sp7C = D_803B1900 + (sp86 * 20);
                while (*sp80 != 0x7530) {
                    *sp7C++ = *sp80++;
                }
                *sp7C = 0x7530;
                sp86++;
            }
        }
        D_803B1A90 = 1;
        D_803B1A92 = 0;
        D_803B1A94 = 0;
        D_803B1A96 = D_803B1A90;
        return 0;
    }
    if (D_803B1A94 != 0) {
        D_803B1A94 -= 8;
    }
    if (D_803B1A92 != 0xF8) {
        D_803B1A92 += 8;
    }

    switch (D_803B1A90) {
    case 0:
        sp74 = &D_80302A20_6A7950;
        break;
    case 1:
        sp74 = &D_802FEE20_6A3D50;
        break;
    case 2:
        sp74 = &D_802FFA20_6A4950;
        break;
    case 3:
        sp74 = &D_80300620_6A5550;
        break;
    case 4:
        sp74 = &D_80301220_6A6150;
        break;
    case 5:
        sp74 = &D_80301E20_6A6D50;
        break;
    case 6:
        sp74 = &D_80303620_6A8550;
        break;
    }
    func_801366DC(&D_801D9E9C, D_803B1A92, D_803B1A92, D_803B1A92, (s32) D_803B1A92);

    gDPPipeSync(D_801D9E9C++);

    gDPSetCombineLERP(D_801D9E9C++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_801D9E9C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(D_801D9E9C++, 0, 0, 128, 128, 128, D_803B1A92);
    gDPSetColorDither(D_801D9E9C++, G_CD_BAYER);
    gDPSetAlphaDither(D_801D9E9C++, G_AD_PATTERN);

    func_80136958(&D_801D9E9C, sp74, 0x30, 0x1F, 0xB4, 0x8C, 0, 0, 0x46, 0x32, 0x10);

    switch (D_803B1A96) {
    case 0:
        sp74 = &D_80302A20_6A7950;
        break;
    case 1:
        sp74 = &D_802FEE20_6A3D50;
        break;
    case 2:
        sp74 = &D_802FFA20_6A4950;
        break;
    case 3:
        sp74 = &D_80300620_6A5550;
        break;
    case 4:
        sp74 = &D_80301220_6A6150;
        break;
    case 5:
        sp74 = &D_80301E20_6A6D50;
        break;
    case 6:
        sp74 = &D_80303620_6A8550;
        break;
    }

    func_801366DC(&D_801D9E9C, D_803B1A94, D_803B1A94, D_803B1A94, (s32) D_803B1A94);
    gDPPipeSync(D_801D9E9C++);
    gDPSetCombineLERP(D_801D9E9C++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_801D9E9C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(D_801D9E9C++, 0, 0, 128, 128, 128, D_803B1A94);
    gDPSetColorDither(D_801D9E9C++, G_CD_BAYER);
    gDPSetAlphaDither(D_801D9E9C++, G_AD_PATTERN);

    func_80136958(&D_801D9E9C, sp74, 0x30, 0x1F, 0xB4, 0x8C, 0, 0, 0x46, 0x32, 0x10);
    func_80129300(&D_801D9E9C, D_80204298);

    sp7A = 0x42;

    gDPPipeSync(D_801D9E9C++);
    func_8012C210(&D_801D9E9C);
    func_8012C268(0, FONT_COMIC_SANS, 1, 0);

    for (sp84 = 0; sp84 < 7; sp84++) {
        if (sp84 == D_803B1A90) {
            func_8012C234(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8012C234(0x80, 0x80, 0x80, 0xFF);
        }
        func_8012C998(&D_801D9E9C, D_803B1900 + (sp84 * 0x14), 0xA0, sp7A, 16.0f, 16.0f);
        sp7A += 0x10;
    }

    sp72 = D_803B1A90; // store current
    if (((gControllerInput->stick_y > 50) || (((gControllerInput->button & CONT_UP))) || ((gControllerInput->button & U_CBUTTONS))) && (D_801D9EF0 == 0) && (D_803B1A90 > 0)) {
        func_8013309C(0x90, 0, 0x5000, 1.0f, 0x40);
        D_801D9EF0 = 0xA;
        D_803B1A90--;
    }
    if (((gControllerInput->stick_y < -50) || (((gControllerInput->button & 0x400) != 0)) || ((gControllerInput->button & 4) != 0)) && (D_801D9EF0 == 0) && (D_803B1A90 < 6)) {
        func_8013309C(0x91, 0, 0x5000, 1.0f, 0x40);
        D_801D9EF0 = 0xA;
        D_803B1A90++;
    }
    if (sp72 != D_803B1A90) {
        D_803B1A96 = sp72;
        D_803B1A92 = 0;
        D_803B1A94 = 0xF8;
    }
    if ((gControllerInput->button & A_BUTTON) ||
        (gControllerInput->button & START_BUTTON)) {

        switch (D_803B1A90) {
        case 0:
            return LANG_DUTCH;
            break;
        case 1:
            return LANG_ENGLISH;
            break;
        case 2:
            return LANG_FRENCH;
            break;
        case 3:
            return LANG_GERMAN;
            break;
        case 4:
            return LANG_ITALIAN;
            break;
        case 5:
            return LANG_PORTUGESE;
            break;
        case 6:
            return LANG_SPANISH;
            break;
        }
    }
    return 0xFF;
}
