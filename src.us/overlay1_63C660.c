#include <ultra64.h>
#include "common.h"

// #define TEXEL0 1
// #define PRIMITIVE 1

u8 overlay1_bss_padding[0xad730]; // 0x10 in overlay1_6384F0

#if 0
// JUSTREG but uses rodata
u8 language_select_menu(s16 arg0) {
    s16 used;
    s16 lang;
    s16 verticalOffset;
    s16 selected;
    s16 *dst;
    s16 *src;
    uSprite *flagTexture;

    // init?
    if (arg0 == 0) {
        used = 0;
        // copy in language strings
        for (lang = 0; lang < 9; lang++) { // '!= 0' helps with regalloc
            // load lang33.dat
            load_level_text_data(lang, 32, D_80231AA0, D_80231D5C);
            if ((lang != LANG_JAPANESE) && (lang != LANG_AMERICAN)) {
                src = get_message_address_by_id(MSG_LANGUAGE); // e.g. "ENGLISH"
                dst = D_803B0400[used];
                COPY_MESSAGE(src, dst);
                used += 1;
            }
        }

        D_803B0590 = 1;
        D_803B0592 = 0;
        D_803B0594 = 0;
        D_803B0596 = D_803B0590;
        return 0;
    }

    if (D_803B0594 != 0) {
        D_803B0594 -= 8; // fade alpha if not selected?
    }

    if (D_803B0592 != 248) {
        D_803B0592 += 8; // increase alpha if selected?
    }

    // current selection
    switch (D_803B0590) {
    case 0:
        flagTexture = D_80301520_6A4BC0; // Dutch
        break;
    case 1:
        flagTexture = D_802FD920_6A0FC0; // English
        break;
    case 2:
        flagTexture = D_802FE520_6A1BC0; // French
        break;
    case 3:
        flagTexture = D_802FF120_6A27C0; // German
        break;
    case 4:
        flagTexture = D_802FFD20_6A33C0; // Italian
        break;
    case 5:
        flagTexture = D_80300920_6A3FC0; // Portugese
        break;
    case 6:
        flagTexture = D_80302120_6A57C0; // Spanish
        break;
    }
    func_801366BC(&D_801D9E7C, D_803B0592, D_803B0592, D_803B0592, D_803B0592);
    gDPPipeSync(D_801D9E7C++);

    gDPSetCombineLERP(D_801D9E7C++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 128, 128, 128, D_803B0592);
    gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

    verticalOffset = 50;
    draw_sprite(&D_801D9E7C, flagTexture, 48, 31, 180, 140, 0, 0, 70, verticalOffset, 16);

    // previous selection?
    switch (D_803B0596) {
    case 0: // Dutch
        flagTexture = D_80301520_6A4BC0;
        break;
    case 1: // English
        flagTexture = D_802FD920_6A0FC0;
        break;
    case 2: // French
        flagTexture = D_802FE520_6A1BC0;
        break;
    case 3: // German
        flagTexture = D_802FF120_6A27C0;
        break;
    case 4: // Italian
        flagTexture = D_802FFD20_6A33C0;
        break;
    case 5: // Portugese
        flagTexture = D_80300920_6A3FC0;
        break;
    case 6: // Spanish
        flagTexture = D_80302120_6A57C0;
        break;
    }

    func_801366BC(&D_801D9E7C, D_803B0595, D_803B0595, D_803B0595, D_803B0595);
    gDPPipeSync(D_801D9E7C++);

    gDPSetCombineLERP(D_801D9E7C++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 128, 128, 128, D_803B0594);
    gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

    draw_sprite(&D_801D9E7C, flagTexture, 48, 31, 180, 140, 0, 0, 70, verticalOffset, 16);

    load_segments(&D_801D9E7C, D_80204278);
    gDPPipeSync(D_801D9E7C++);

    // write language strings
    verticalOffset += 16;
    load_default_display_list(&D_801D9E7C);
    select_font(0, FONT_COMIC_SANS, 1, 0);

    for (lang = 0; lang < 7; lang++) {
        if (lang == D_803B0590) {
            set_menu_text_color(255, 255, 255, 255); // selected
        } else {
            set_menu_text_color(128, 128, 128, 255);
        }
        display_text_centered(&D_801D9E7C, D_803B0400[lang], 160, verticalOffset, 16.0f, 16.0f);
        verticalOffset += 16;
    }

    selected = D_803B0590; // save current selection

    // analogue stick up or dpad up or c-up
    if ((gControllerInput->stick_y > 50) ||
        (gControllerInput->button & CONT_UP) ||
        (gControllerInput->button & U_CBUTTONS)) {
        if (D_801D9ED4 == 0) {
            if (D_803B0590 > 0) {
                play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                D_801D9ED4 = 10;
                D_803B0590 -= 1;
            }
        }
    }
    // analogue stick down or dpad down or c-down
    if ((gControllerInput->stick_y < -50) ||
        ((gControllerInput->button & CONT_DOWN)) ||
        (gControllerInput->button & D_CBUTTONS)) {
        if (D_801D9ED4 == 0) {
            if (D_803B0590 < 6) {
                play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
                D_801D9ED4 = 10;
                D_803B0590 += 1;
            }
        }
    }
    if (D_803B0590 != selected) {
        D_803B0596 = selected;
        D_803B0592 = 0;
        D_803B0594 = 248;
    }

    if ((gControllerInput->button & A_BUTTON) ||
        (gControllerInput->button & START_BUTTON)) {
        switch (D_803B0590) {
        case 0: // Dutch
            return LANG_DUTCH;
        case 1: // English
            return LANG_ENGLISH;
        case 2: // French
            return LANG_FRENCH;
        case 3: // German
            return LANG_GERMAN;
        case 4: // Italian
            return LANG_ITALIAN;
        case 5: // Portugese
            return LANG_PORTUGESE;
        case 6: // Spanish
            return LANG_SPANISH;
        }
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_63C660/language_select_menu.s")
#endif
