#include <ultra64.h>
#include "common.h"


static s16  languageBuffer[200];
static s16  currentSelection;
static s16  D_803B0592; // current alpha
static s16  D_803B0594; // current colour
static s16  previousSelection;


s16 language_select_menu(s16 arg0) {
    s16 used;
    s16 lang;
    s16 verticalOffset;
    s16 selected;
    s16 *dst;
    s16 *src;
    uSprite *flagTexture;

    if (arg0 == 0) {
        used = 0;
        // copy in language strings
        for (lang = 0; lang < 9; lang++) {
            // load lang33.dat
            load_level_text_data(lang, 32, D_8022E3F0.messages, D_8022E3F0.data);

            if ((lang != LANG_JAPANESE) && (lang != LANG_AMERICAN)) {
                src = get_message_address_by_id(MSG_LANGUAGE); // e.g. "ENGLISH"
                dst = languageBuffer + used * 20;
                COPY_MESSAGE(src, dst);
                used++;
            }
        }

        currentSelection = 1; // English
        D_803B0592 = 0;
        D_803B0594 = 0;
        previousSelection = currentSelection;
        return 0;
    }

    if (D_803B0594 != 0) {
        D_803B0594 -= 8; // fade alpha if not zero
    }

    if (D_803B0592 != 248) {
        D_803B0592 += 8; // increase alpha if not max?
    }

    // current selection
    switch (currentSelection) {
    case 0:
        flagTexture = (uSprite *)img_flags_dutch_rgba16__png; // Dutch
        break;
    case 1:
        flagTexture = (uSprite *)img_flags_english_rgba16__png; // English
        break;
    case 2:
        flagTexture = (uSprite *)img_flags_french_rgba16__png; // French
        break;
    case 3:
        flagTexture = (uSprite *)img_flags_german_rgba16__png; // German
        break;
    case 4:
        flagTexture = (uSprite *)img_flags_italian_rgba16__png; // Italian
        break;
    case 5:
        flagTexture = (uSprite *)img_flags_portugese_rgba16__png; // Portugese
        break;
    case 6:
        flagTexture = (uSprite *)img_flags_spanish_rgba16__png; // Spanish
        break;
    }
    init_sprite2d_render(&gMainDL, D_803B0592, D_803B0592, D_803B0592, D_803B0592);
    gDPPipeSync(gMainDL++);

    gDPSetCombineLERP(gMainDL++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(gMainDL++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMainDL++, 0, 0, 128, 128, 128, D_803B0592);
    gDPSetColorDither(gMainDL++, G_CD_BAYER);
    gDPSetAlphaDither(gMainDL++, G_AD_PATTERN);

    draw_sprite(&gMainDL, flagTexture, 48, 31, 180, 140, 0, 0, 70, 0x32, 16);

    // previous selection?
    switch (previousSelection) {
    case 0: // Dutch
        flagTexture = (uSprite *)img_flags_dutch_rgba16__png;
        break;
    case 1: // English
        flagTexture = (uSprite *)img_flags_english_rgba16__png;
        break;
    case 2: // French
        flagTexture = (uSprite *)img_flags_french_rgba16__png;
        break;
    case 3: // German
        flagTexture = (uSprite *)img_flags_german_rgba16__png;
        break;
    case 4: // Italian
        flagTexture = (uSprite *)img_flags_italian_rgba16__png;
        break;
    case 5: // Portugese
        flagTexture = (uSprite *)img_flags_portugese_rgba16__png;
        break;
    case 6: // Spanish
        flagTexture = (uSprite *)img_flags_spanish_rgba16__png;
        break;
    }

    init_sprite2d_render(&gMainDL, D_803B0594, D_803B0594, D_803B0594, D_803B0594);
    gDPPipeSync(gMainDL++);

    gDPSetCombineLERP(gMainDL++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(gMainDL++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMainDL++, 0, 0, 128, 128, 128, D_803B0594);
    gDPSetColorDither(gMainDL++, G_CD_BAYER);
    gDPSetAlphaDither(gMainDL++, G_AD_PATTERN);

    draw_sprite(&gMainDL, flagTexture, 48, 31, 180, 140, 0, 0, 70, 0x32, 16);
    load_segments(&gMainDL, gDisplayListContext);

    verticalOffset = 0x42;

    gDPPipeSync(gMainDL++);

    // write language strings
    load_default_display_list(&gMainDL);
    select_font(0, FONT_COMIC_SANS, 1, 0);

    for (lang = 0; lang < 7; lang++) {
        if (lang == currentSelection) {
            set_menu_text_color(255, 255, 255, 255); // selected
        } else {
            set_menu_text_color(128, 128, 128, 255);
        }
        display_text_centered(&gMainDL, languageBuffer + lang * 20, 160, verticalOffset, 16.0f, 16.0f);
        verticalOffset += 16;
    }

    selected = currentSelection; // save current selection

    // analogue stick up or dpad up or c-up
    if ((gControllerInput->stick_y > 50) ||
        (gControllerInput->button & CONT_UP) ||
        (gControllerInput->button & U_CBUTTONS)) {
        if (D_801D9ED4 == 0) {
            if (currentSelection > 0) {
                play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                D_801D9ED4 = 10;
                currentSelection--;
            }
        }
    }
    // analogue stick down or dpad down or c-down
    if ((gControllerInput->stick_y < -50) ||
        ((gControllerInput->button & CONT_DOWN)) ||
        (gControllerInput->button & D_CBUTTONS)) {
        if (D_801D9ED4 == 0) {
            if (currentSelection < 6) {
                play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
                D_801D9ED4 = 10;
                currentSelection++;
            }
        }
    }
    // change of selection
    if (currentSelection != selected) {
        previousSelection = selected;
        D_803B0592 = 0;
        D_803B0594 = 248;
    }

    if ((gControllerInput->button & A_BUTTON) ||
        (gControllerInput->button & START_BUTTON)) {
        switch (currentSelection) {
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
