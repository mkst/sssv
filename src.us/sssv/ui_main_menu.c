#include <ultra64.h>
#include "common.h"

#include "pp.h"


// ========================================================
// structs
// ========================================================

typedef struct {
    s8 xPos;
    s8 yPos;
    u8 width;
    u8 height;
    u8 idx;
} LevelRingPosition;

// ========================================================
// externs
// ========================================================

extern LevelRingPosition D_803B71D0_7C8880[];

// ========================================================
// .data
// ========================================================

#if 0
LevelRingPosition D_803B71D0_7C8880[30] = {
    { 0xE1, 0xF9, 0x09, 0x07, 0x07, },
    { 0xE2, 0xF3, 0x0A, 0x09, 0x06, },
    { 0xE4, 0xED, 0x0A, 0x0B, 0x05, },
    { 0xE6, 0xE8, 0x0C, 0x0C, 0x04, },
    { 0xEB, 0xE5, 0x0A, 0x0C, 0x03, },
    { 0xF0, 0xE2, 0x09, 0x0B, 0x02, },
    { 0xF6, 0xE1, 0x07, 0x0B, 0x01, },
    { 0xFD, 0xE1, 0x07, 0x0A, 0x00, },
    { 0x03, 0xE1, 0x07, 0x0B, 0x01, },
    { 0x07, 0xE2, 0x09, 0x0B, 0x02, },
    { 0x0B, 0xE5, 0x0A, 0x0C, 0x03, },
    { 0x0E, 0xE8, 0x0C, 0x0C, 0x04, },
    { 0x12, 0xED, 0x0A, 0x0B, 0x05, },
    { 0x14, 0xF3, 0x0A, 0x09, 0x06, },
    { 0x16, 0xF9, 0x09, 0x07, 0x07, },
    { 0x16, 0xFF, 0x09, 0x07, 0x07, },
    { 0x14, 0x03, 0x0A, 0x09, 0x06, },
    { 0x12, 0x07, 0x0A, 0x0B, 0x05, },
    { 0x0E, 0x0B, 0x0C, 0x0C, 0x04, },
    { 0x0B, 0x0E, 0x0A, 0x0C, 0x03, },
    { 0x07, 0x12, 0x09, 0x0B, 0x02, },
    { 0x03, 0x13, 0x07, 0x0B, 0x01, },
    { 0xFD, 0x14, 0x07, 0x0A, 0x00, },
    { 0xF6, 0x13, 0x07, 0x0B, 0x01, },
    { 0xF0, 0x12, 0x09, 0x0B, 0x02, },
    { 0xEB, 0x0E, 0x0A, 0x0C, 0x03, },
    { 0xE6, 0x0B, 0x0C, 0x0C, 0x04, },
    { 0xE4, 0x07, 0x0A, 0x0B, 0x05, },
    { 0xE2, 0x03, 0x0A, 0x09, 0x06, },
    { 0xE1, 0xFF, 0x09, 0x07, 0x07, },
};

// 2 extra bytes, presumably just padding

u8 *D_803B7268_7C8918[32*2] = {
    img_thumbnails_SMASHING_START_rgba16_rnc_ROM_START, img_thumbnails_SMASHING_START_rgba16_rnc_ROM_END,
    img_thumbnails_HAVE_A_NICE_DAY_rgba16_rnc_ROM_START, img_thumbnails_HAVE_A_NICE_DAY_rgba16_rnc_ROM_END,
    img_thumbnails_HONEYMOON_LAGOON_rgba16_rnc_ROM_START, img_thumbnails_HONEYMOON_LAGOON_rgba16_rnc_ROM_END,
    img_thumbnails_THE_BATTERY_FARM_rgba16_rnc_ROM_START, img_thumbnails_THE_BATTERY_FARM_rgba16_rnc_ROM_END,
    img_thumbnails_THE_ENGINE_ROOM_rgba16_rnc_ROM_START, img_thumbnails_THE_ENGINE_ROOM_rgba16_rnc_ROM_END,
    img_thumbnails_FAT_BEAR_MOUNTAIN_rgba16_rnc_ROM_START, img_thumbnails_FAT_BEAR_MOUNTAIN_rgba16_rnc_ROM_END,
    img_thumbnails_ROCKY_HARD_PLACE_rgba16_rnc_ROM_START, img_thumbnails_ROCKY_HARD_PLACE_rgba16_rnc_ROM_END,
    img_thumbnails_STINKY_SEWERS_rgba16_rnc_ROM_START, img_thumbnails_STINKY_SEWERS_rgba16_rnc_ROM_END,
    img_thumbnails_RAT_O_MATIC_rgba16_rnc_ROM_START, img_thumbnails_RAT_O_MATIC_rgba16_rnc_ROM_END,
    img_thumbnails_GIVE_A_DOG_A_BONUS_rgba16_rnc_ROM_START, img_thumbnails_GIVE_A_DOG_A_BONUS_rgba16_rnc_ROM_END,
    img_thumbnails_SNOW_JOKE_rgba16_rnc_ROM_START, img_thumbnails_SNOW_JOKE_rgba16_rnc_ROM_END,
    img_thumbnails_ICE_N_EASY_DOES_IT_rgba16_rnc_ROM_START, img_thumbnails_ICE_N_EASY_DOES_IT_rgba16_rnc_ROM_END,
    img_thumbnails_PENGUIN_PLAYPEN_rgba16_rnc_ROM_START, img_thumbnails_PENGUIN_PLAYPEN_rgba16_rnc_ROM_END,
    img_thumbnails_PINBALL_BLIZZARD_rgba16_rnc_ROM_START, img_thumbnails_PINBALL_BLIZZARD_rgba16_rnc_ROM_END,
    img_thumbnails_HOPPA_CHOPPA_rgba16_rnc_ROM_START, img_thumbnails_HOPPA_CHOPPA_rgba16_rnc_ROM_END,
    img_thumbnails_SOMETHING_FISHY_rgba16_rnc_ROM_START, img_thumbnails_SOMETHING_FISHY_rgba16_rnc_ROM_END,
    img_thumbnails_WALRACE_64_rgba16_rnc_ROM_START, img_thumbnails_WALRACE_64_rgba16_rnc_ROM_END,
    img_thumbnails_JUNGLE_JAPES_rgba16_rnc_ROM_START, img_thumbnails_JUNGLE_JAPES_rgba16_rnc_ROM_END,
    img_thumbnails_JUNGLE_DOLDRUMS_rgba16_rnc_ROM_START, img_thumbnails_JUNGLE_DOLDRUMS_rgba16_rnc_ROM_END,
    img_thumbnails_SWAMP_OF_ETERNAL_STENCH_rgba16_rnc_ROM_START, img_thumbnails_SWAMP_OF_ETERNAL_STENCH_rgba16_rnc_ROM_END,
    img_thumbnails_WEIGHT_FOR_IT_rgba16_rnc_ROM_START, img_thumbnails_WEIGHT_FOR_IT_rgba16_rnc_ROM_END,
    img_thumbnails_JUNGLE_JUMPS_rgba16_rnc_ROM_START, img_thumbnails_JUNGLE_JUMPS_rgba16_rnc_ROM_END,
    img_thumbnails_EVOS_ESCAPE_rgba16_rnc_ROM_START, img_thumbnails_EVOS_ESCAPE_rgba16_rnc_ROM_END,
    img_thumbnails_FUN_IN_THE_SUN_rgba16_rnc_ROM_START, img_thumbnails_FUN_IN_THE_SUN_rgba16_rnc_ROM_END,
    img_thumbnails_HOT_CROSS_BUNS_rgba16_rnc_ROM_START, img_thumbnails_HOT_CROSS_BUNS_rgba16_rnc_ROM_END,
    img_thumbnails_STING_IN_THE_TAIL_rgba16_rnc_ROM_START, img_thumbnails_STING_IN_THE_TAIL_rgba16_rnc_ROM_END,
    img_thumbnails_BORASSIC_PARK_rgba16_rnc_ROM_START, img_thumbnails_BORASSIC_PARK_rgba16_rnc_ROM_END,
    img_thumbnails_WHIRLWIND_TOUR_rgba16_rnc_ROM_START, img_thumbnails_WHIRLWIND_TOUR_rgba16_rnc_ROM_END,
    img_thumbnails_SHIFTING_SANDS_rgba16_rnc_ROM_START, img_thumbnails_SHIFTING_SANDS_rgba16_rnc_ROM_END,
    img_thumbnails_PUNCHUP_PYRAMID_rgba16_rnc_ROM_START, img_thumbnails_PUNCHUP_PYRAMID_rgba16_rnc_ROM_END,
    img_thumbnails_BIG_CELEBRATION_PARADE_rgba16_rnc_ROM_START, img_thumbnails_BIG_CELEBRATION_PARADE_rgba16_rnc_ROM_END,
    img_thumbnails_SECRET_LEVEL_rgba16_rnc_ROM_START, img_thumbnails_SECRET_LEVEL_rgba16_rnc_ROM_END,
};

u8 *D_803B7368_7C8A18[32] = {
    img_trophies_SMASHING_START_rgba16_rnc_ROM_START,     img_trophies_SMASHING_START_rgba16_rnc_ROM_END,
    img_trophies_HAVE_A_NICE_DAY_rgba16_rnc_ROM_START,    img_trophies_HAVE_A_NICE_DAY_rgba16_rnc_ROM_END,
    img_trophies_HONEYMOON_LAGOON_rgba16_rnc_ROM_START,   img_trophies_HONEYMOON_LAGOON_rgba16_rnc_ROM_END,
    img_trophies_THE_BATTERY_FARM_rgba16_rnc_ROM_START,   img_trophies_THE_BATTERY_FARM_rgba16_rnc_ROM_END,
    img_trophies_THE_ENGINE_ROOM_rgba16_rnc_ROM_START,    img_trophies_THE_ENGINE_ROOM_rgba16_rnc_ROM_END,
    img_trophies_FAT_BEAR_MOUNTAIN_rgba16_rnc_ROM_START,  img_trophies_FAT_BEAR_MOUNTAIN_rgba16_rnc_ROM_END,
    img_trophies_ROCKY_HARD_PLACE_rgba16_rnc_ROM_START,   img_trophies_ROCKY_HARD_PLACE_rgba16_rnc_ROM_END,
    img_trophies_STINKY_SEWERS_rgba16_rnc_ROM_START,      img_trophies_STINKY_SEWERS_rgba16_rnc_ROM_END,
    img_trophies_RAT_O_MATIC_rgba16_rnc_ROM_START,        img_trophies_RAT_O_MATIC_rgba16_rnc_ROM_END,
    img_trophies_GIVE_A_DOG_A_BONUS_rgba16_rnc_ROM_START, img_trophies_GIVE_A_DOG_A_BONUS_rgba16_rnc_ROM_END,
    img_trophies_SNOW_JOKE_rgba16_rnc_ROM_START,          img_trophies_SNOW_JOKE_rgba16_rnc_ROM_END,
    img_trophies_ICE_N_EASY_DOES_IT_rgba16_rnc_ROM_START, img_trophies_ICE_N_EASY_DOES_IT_rgba16_rnc_ROM_END,
    img_trophies_PENGUIN_PLAYPEN_rgba16_rnc_ROM_START,    img_trophies_PENGUIN_PLAYPEN_rgba16_rnc_ROM_END,
    img_trophies_PINBALL_BLIZZARD_rgba16_rnc_ROM_START,   img_trophies_PINBALL_BLIZZARD_rgba16_rnc_ROM_END,
    img_trophies_HOPPA_CHOPPA_rgba16_rnc_ROM_START,       img_trophies_HOPPA_CHOPPA_rgba16_rnc_ROM_END,
    img_trophies_SOMETHING_FISHY_rgba16_rnc_ROM_START,    img_trophies_SOMETHING_FISHY_rgba16_rnc_ROM_END,
    img_trophies_WALRACE_64_rgba16_rnc_ROM_START,         img_trophies_WALRACE_64_rgba16_rnc_ROM_END,
    img_trophies_JUNGLE_JAPES_rgba16_rnc_ROM_START,       img_trophies_JUNGLE_JAPES_rgba16_rnc_ROM_END,
    img_trophies_JUNGLE_DOLDRUMS_rgba16_rnc_ROM_START,    img_trophies_JUNGLE_DOLDRUMS_rgba16_rnc_ROM_END,
    img_trophies_SWAMP_OF_ETERNAL_STENCH_rgba16_rnc_ROM_START, img_trophies_SWAMP_OF_ETERNAL_STENCH_rgba16_rnc_ROM_END,
    img_trophies_WEIGHT_FOR_IT_rgba16_rnc_ROM_START,      img_trophies_WEIGHT_FOR_IT_rgba16_rnc_ROM_END,
    img_trophies_JUNGLE_JUMPS_rgba16_rnc_ROM_START,       img_trophies_JUNGLE_JUMPS_rgba16_rnc_ROM_END,
    img_trophies_EVOS_ESCAPE_rgba16_rnc_ROM_START,        img_trophies_EVOS_ESCAPE_rgba16_rnc_ROM_END,
    img_trophies_FUN_IN_THE_SUN_rgba16_rnc_ROM_START,     img_trophies_FUN_IN_THE_SUN_rgba16_rnc_ROM_END,
    img_trophies_HOT_CROSS_BUNS_rgba16_rnc_ROM_START,     img_trophies_HOT_CROSS_BUNS_rgba16_rnc_ROM_END,
    img_trophies_STING_IN_THE_TAIL_rgba16_rnc_ROM_START,  img_trophies_STING_IN_THE_TAIL_rgba16_rnc_ROM_END,
    img_trophies_BORASSIC_PARK_rgba16_rnc_ROM_START,      img_trophies_BORASSIC_PARK_rgba16_rnc_ROM_END,
    img_trophies_WHIRLWIND_TOUR_rgba16_rnc_ROM_START,     img_trophies_WHIRLWIND_TOUR_rgba16_rnc_ROM_END,
    img_trophies_SHIFTING_SANDS_rgba16_rnc_ROM_START,     img_trophies_SHIFTING_SANDS_rgba16_rnc_ROM_END,
    img_trophies_PUNCHUP_PYRAMID_rgba16_rnc_ROM_START,    img_trophies_PUNCHUP_PYRAMID_rgba16_rnc_ROM_END,
    img_trophies_BIG_CELEBRATION_PARADE_rgba16_rnc_ROM_START, img_trophies_BIG_CELEBRATION_PARADE_rgba16_rnc_ROM_END,
    img_trophies_SECRET_LEVEL_rgba16_rnc_ROM_START,       img_trophies_SECRET_LEVEL_rgba16_rnc_ROM_END,
};

#if 0
glabel D_803B7468_7C8B18
/* 7C8B18 803B7468 */ .word 0x00000000
/* 7C8B1C 803B746C */ .word 0x00000000
/* 7C8B20 803B7470 */ .word 0x00000000
/* 7C8B24 803B7474 */ .word 0x09C40000
/* 7C8B28 803B7478 */ .word 0x41300000
/* 7C8B2C 803B747C */ .word 0xC1C80000
#endif

#endif

char D_803B7480_7C8B30[4][10] = {
    "Europe",
    "Ice",
    "Jungle",
    "Desert",
};

f32 D_803B74A8_7C8B58 = 0.0f; // junk/padding/alignment

// .data
f32 D_803B74AC_7C8B5C = 11.0f;
f32 D_803B74B0_7C8B60 = 16.0f;
f32 D_803B74B4_7C8B64 = 10.5f;
f32 D_803B74B8_7C8B68 = 12.84f;
f32 D_803B74BC_7C8B6C = 12.0f;
f32 D_803B74C0_7C8B70 = 16.0f;
f32 D_803B74C4_7C8B74 = 12.0f;

// ========================================================
// .bss (from D_803F7160 to D_803F7E10)
// ========================================================

u8   D_803F7160[0xC00]; // what is this?

s32  D_803F7D60; // static in draw_level_rings_segment
static s32  D_803F7D64; // unused
static f32  D_803F7D68;
static f32  D_803F7D6C; // unused
static f32  D_803F7D70;
static struct008 D_803F7D78;
static s16  D_803F7D9C;
static s16  D_803F7D9E;
static s8   D_803F7DA0;
static s8   D_803F7DA1;
static s8   D_803F7DA2;
static s8   D_803F7DA3;
struct030 D_803F7DA8;
static s8   D_803F7DE0[0x1E]; // levels available
static s8   D_803F7DFE;
static s16  D_803F7E00; // europe levels completed
static s16  D_803F7E02; // levels
static s16  D_803F7E04; // levels
static s16  D_803F7E06; // levels

// ========================================================
// .text
// ========================================================

void func_80398630_7A9CE0(void) {
    load_data_section(6);
    // unpack menu graphics
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04006EC0_11DA90)), D_800BA760); // central piece of SSSV
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007FA0_11EB70)), D_800BDC80); // "SSSV" Header graphic
    // unpack powercell
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04000000_116BD0)), D_800DE390); // powercell
    // unpack evo bodyparts
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04013060_129C30)), D_800C3A40); // evo head trophy
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040133C0_129F90)), D_800C5240); // evo arms trophy
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040131B0_129D80)), D_800C4240); // evo legs trophy
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04013580_12A150)), D_800C4A40); // evo torso trophy
    // unpack 'silver' level ring pieces
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007700_11E2D0)), D_800BB700); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040077A0_11E370)), D_800BBBB0); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040078C0)), D_800BC060); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040079F0)), D_800BC510); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007B40)), D_800BC9C0); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007C60)), D_800BCE70); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007D90)), D_800BD320); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007EC0)), D_800BD7D0); // silver ring piece
}

void func_8039884C_7A9EFC(void) {
    s16 sp18[44];

    determine_available_levels();
    D_803F7DA8.previousLevel = 99;
    D_803F7D78.unk0 = 0;
    D_803F7D78.unk4 = 0;
    D_803F7D78.unk8 = 0;
    D_803F7D78.unkC = 0;
    D_803F7D78.unk10 = 0;
    D_803F7D78.unk14 = 0;
    D_803F7D78.unk18 = 0;
    D_803F7D78.unk1C = 0;
    D_803F7D78.unk20 = 0;
    D_803F7D70 = 0.1f;
    prepare_text(sp18, (u8*)D_803F2D50.titleText); // zero out title?
    D_803F7DA8.unk8 = 1.0f;
    D_803B7468_7C8B18 = D_803F7DA8.currentLevel * 12;
    D_803F7D68 = D_803F7DA8.currentLevel * 12;
    D_803F7DA8.unk0 = 40.0f;
    D_803F7DA8.unk4 = 30.0f;
    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DA0 = 6;
    D_803F7DA1 = 6;
    D_803F7DA2 = 0;
    D_803F7DA3 = 0;
    D_803F2D50.evoSuitColor = get_evo_suit_color();
}

void func_8039895C_7AA00C(void) {
    s16 i;

    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DA8.unk2F = 0;
    generate_stars();

    for (i = 0; i < 4; i++) {
        read_eeprom(i);
        memcpy_sssv((u8*)&D_8023F260, (u8*) &D_8023F2E0[i], 64);
    }
    read_eeprom(D_803F7DA8.bank);
}

void func_80398A00_7AA0B0(void) {
    D_803F7DA8.unk30 = 0;
}

void display_zone_select_screen(void) {
    char ascii[38];
    s16  wide_text[26];

    f32 spE0;
    f32 spDC;

    s16 vertical_offset;
    s32 score;
    s16 level;
    s16 pad1;

    s16 secs;
    s16 mins;
    s32 pad2;

    u8 evo_r;
    u8 evo_b;
    u8 evo_g;
    s32 pad3;

    gTasksCompleted = 0;
    if (gCurrentMusicTrack != MUSIC_TRACK_MAIN_THEME) {
        gCurrentMusicTrack = MUSIC_TRACK_MAIN_THEME;
        D_801546D8 = 1600; // volume related
        D_801546E0 = 2048;
        D_8015517C = 1.0f;
    }
    D_803B74C4_7C8B74 = 12.0f; // font scale
    if ((gEepromGlobal.language == LANG_ITALIAN) ||
        (gEepromGlobal.language == LANG_FRENCH) ||
        (gEepromGlobal.language == LANG_SPANISH) ||
        (gEepromGlobal.language == LANG_PORTUGESE)) {
        D_803B74C4_7C8B74 = 9.7f; //D_803C03F8_7D1AA8;
    }

    func_8039CE38_7AE4E8(&D_801D9E7C);
    func_8039CAB8_7AE168(1);
    render_stars(&D_801D9E7C);

    gDPPipeSync(D_801D9E7C++);

    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    D_803F7DA8.unk0 = 94.0f;
    D_803F7DA8.unk4 = 134.0f;
    D_803F7DA8.unk0 = func_8039CDE8_7AE498(D_803F7DA8.unk0, 94.0f);
    D_803F7DA8.unk4 = func_8039CDE8_7AE498(D_803F7DA8.unk4, 134.0f);
    D_803F7DA8.unk8 += (2.0 - D_803F7DA8.unk8) / 16;
    if ((1.95 < D_803F7DA8.unk8) && (D_803F7DA8.unk8 < 2.05)) {
        D_803F7DA8.unk8 = 2.0f;
    }

    spE0 = D_803F7DA8.unk0 - 21.5f * D_803F7DA8.unk8;
    spDC = D_803F7DA8.unk4 - 21.5f * D_803F7DA8.unk8;

    gDPPipeSync(D_801D9E7C++);

    load_default_display_list(&D_801D9E7C);
    select_font(0, FONT_COMIC_SANS, 0, 0);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
    func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_ZONE_SELECT), 0x18, 0x1F, 24.0f, 16.0f, -1);

    gSPDisplayList(D_801D9E7C++, D_801584A0);

    gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

    // decompress ZONE SELECT image
    UnpackRNC(SEGMENT_OFFSET(D_04012B20_1296F0) + D_801D9E6C, D_800DD3F0); // ZONE_SELECT rgba16

    if (D_803F7DA8.previousLevel != D_803F7DA8.currentLevel) {
        // level thumbnails
        dma_read(D_803B7268_7C8918[D_803F7DA8.currentLevel*2], D_800B0B20, D_803B7268_7C8918[D_803F7DA8.currentLevel*2+1] - D_803B7268_7C8918[D_803F7DA8.currentLevel*2]);
        UnpackRNC(D_800B0B20, D_800B49A0);
        D_803F7DA8.previousLevel = D_803F7DA8.currentLevel;
        // trophy images
        dma_read(D_803B7368_7C8A18[D_803F7DA8.currentLevel*2], D_800B0B20, D_803B7368_7C8A18[D_803F7DA8.currentLevel*2+1] - D_803B7368_7C8A18[D_803F7DA8.currentLevel*2]);
        UnpackRNC(D_800B0B20, D_800B68E0);

        gLoadedMessageCount = load_level_text_data(gEepromGlobal.language, D_803F7DA8.currentLevel, D_803F3330, D_803F34C0);
        load_level_title();
    }
    gDPPipeSync(D_801D9E7C++);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0x80);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPPipeSync(D_801D9E7C++);

    func_803962EC_7A799C(&D_801D9E7C, 800, 592, 1200, 888, D_800B49A0, 64, 47);
    gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0x1A);

    level = D_803F7DA8.currentLevel + 1;

    if ((level == GIVE_A_DOG_A_BONUS) ||
        (level == WALRACE_64) ||
        (level == EVOS_ESCAPE) ||
        (level == PUNCHUP_PYRAMID) ||
        (level == BIG_CELEBRATION_PARADE)) {
        switch (D_803F2D50.evoSuitColor) {
        case EVO_BRONZE_SHELLSUIT:
            evo_r = 200;
            evo_g = 200;
            evo_b = 0;
            break;
        case EVO_SILVER_SHELLSUIT:
            evo_r = 180;
            evo_g = 180;
            evo_b = 180;
            break;
        case EVO_GOLD_SHELLSUIT:
            evo_r = 255;
            evo_g = 255;
            evo_b = 20;
            break;
        }

        func_803967D4_7A7E84(276, 102, evo_r, evo_g, evo_b, D_8023F260.evoPartsCollected & EVO_HEAD, D_8023F260.evoPartsCollected & EVO_TORSO, D_8023F260.evoPartsCollected & EVO_ARMS, D_8023F260.evoPartsCollected & EVO_LEGS, 0);
    } else if (D_8023F260.level[D_803F7DA8.currentLevel].trophy) {
        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        func_803962EC_7A799C(&D_801D9E7C, 1072, 448, 1200, 576, D_800B68E0, 32, 31);
    }

    if (D_803F7DA2 != 0) {
        D_803F7DA2 -= 1;
    }
    if (D_803F7DA3 != 0) {
        D_803F7DA3 -= 1;
    }
    if ((D_802912E4 == 1) && (gControllerInput->stick_x <= 20)) {
        D_803F7DA3 = 0;
    }
    if ((D_802912E3 == 1) && (gControllerInput->stick_x >= -20)) {
        D_803F7DA2 = 0;
    }
    if (((gControllerInput->button & CONT_LEFT) || (gControllerInput->stick_x < -20)) && (D_803F7DA2 == 0)) {
        if (D_803F7DA0 < 8) {
            D_803F7DA0 = 8;
        } else {
            D_803F7DA0--;
        }

        level = D_803F7DA8.currentLevel;
        D_803F7DA2 = D_803F7DA0;
        D_803F7DA8.currentLevel = get_next_available_level(D_803F7DA8.currentLevel, -1);
        if (level != D_803F7DA8.currentLevel) {
            if (D_803F7DA8.currentLevel == PUNCHUP_PYRAMID) {
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
            } else if (get_biome_for_level(D_803F7DA8.currentLevel) != D_803F7DA8.biome) {
                play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
            } else {
                play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
            }
        }
        if (level != D_803F7DA8.currentLevel) {
            func_80395074_7A6724(0);
        } else {
            func_80395074_7A6724(1);
        }
    }
    if (((gControllerInput->button & CONT_RIGHT) || (gControllerInput->stick_x > 20)) && (D_803F7DA3 == 0)) {
        if (D_803F7DA1 < 8) {
            D_803F7DA1 = 8;
        } else {
            D_803F7DA1 -= 1;
        }
        level = D_803F7DA8.currentLevel;
        D_803F7DA3 = D_803F7DA1;
        D_803F7DA8.currentLevel = get_next_available_level(D_803F7DA8.currentLevel, 1);
        if (level != D_803F7DA8.currentLevel) {
            if (D_803F7DA8.currentLevel == PUNCHUP_PYRAMID) {
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
            } else if (get_biome_for_level(D_803F7DA8.currentLevel) != D_803F7DA8.biome) {
                play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
            } else {
                play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
            }
        }
        if (level != D_803F7DA8.currentLevel) {
            func_80395074_7A6724(0);
        } else {
            func_80395074_7A6724(1);
        }
    }
    if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
        ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
        play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
        func_80395074_7A6724(0);
        D_803F6680.unk18 += 1;
        D_803F2D30.level = D_803F7DA8.currentLevel + 1;
    }
    if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1)) {
        play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
        func_80395074_7A6724(0);
        D_803F6680.unk18 -= 1;
        func_8039895C_7AA00C();
    }

    D_803F7DA8.biome = get_biome_for_level(D_803F7DA8.currentLevel);
    if (D_803F7DA8.biome == UI_EUROPE_BIOME) {
        D_803F7DA8.unkC += (-6.0 - D_803F7DA8.unkC) / 2;     // pop out ring
        D_803F7DA8.unk10 += (-12.0 - D_803F7DA8.unk10) / 2;  // pop out ring
        D_803F7DA8.unkC = func_8039CDE8_7AE498(D_803F7DA8.unkC, -6.0f);
        D_803F7DA8.unk10 = func_8039CDE8_7AE498(D_803F7DA8.unk10, -12.0f);
    } else {
        D_803F7DA8.unkC += (0.0f - D_803F7DA8.unkC) / 2;
        D_803F7DA8.unk10 += (0.0f - D_803F7DA8.unk10) / 2;
        D_803F7DA8.unkC = func_8039CDE8_7AE498(D_803F7DA8.unkC, 0.0f);
        D_803F7DA8.unk10 = func_8039CDE8_7AE498(D_803F7DA8.unk10, 0.0f);
    }

    if (D_803F7DA8.biome == UI_ICE_BIOME) {
        D_803F7DA8.unk24 += (12.0 - D_803F7DA8.unk24) / 2;
        D_803F7DA8.unk28 += (-4.0 - D_803F7DA8.unk28) / 2;
        D_803F7DA8.unk24 = func_8039CDE8_7AE498(D_803F7DA8.unk24, 12.0f);
        D_803F7DA8.unk28 = func_8039CDE8_7AE498(D_803F7DA8.unk28, -4.0f);
    } else {
        D_803F7DA8.unk24 += (0.0f - D_803F7DA8.unk24) / 2;
        D_803F7DA8.unk28 += (0.0f - D_803F7DA8.unk28) / 2;
        D_803F7DA8.unk24 = func_8039CDE8_7AE498(D_803F7DA8.unk24, 0.0f);
        D_803F7DA8.unk28 = func_8039CDE8_7AE498(D_803F7DA8.unk28, 0.0f);
    }

    if (D_803F7DA8.biome == UI_JUNGLE_BIOME) {
        D_803F7DA8.unk1C += (3.0 - D_803F7DA8.unk1C) / 2;
        D_803F7DA8.unk20 += (12.0 - D_803F7DA8.unk20) / 2;
        D_803F7DA8.unk1C = func_8039CDE8_7AE498(D_803F7DA8.unk1C, 3.0f);
        D_803F7DA8.unk20 = func_8039CDE8_7AE498(D_803F7DA8.unk20, 12.0f);
    } else {
        D_803F7DA8.unk1C += (0.0f - D_803F7DA8.unk1C) / 2;
        D_803F7DA8.unk20 += (0.0f - D_803F7DA8.unk20) / 2;
        D_803F7DA8.unk1C = func_8039CDE8_7AE498(D_803F7DA8.unk1C, 0.0f);
        D_803F7DA8.unk20 = func_8039CDE8_7AE498(D_803F7DA8.unk20, 0.0f);
    }

    if (D_803F7DA8.biome == UI_DESERT_BIOME) {
        D_803F7DA8.unk14 += (-12.0 - D_803F7DA8.unk14) / 2;
        D_803F7DA8.unk18 += (6.0 - D_803F7DA8.unk18) / 2;
        D_803F7DA8.unk14 = func_8039CDE8_7AE498(D_803F7DA8.unk14, -12.0f);
        D_803F7DA8.unk18 = func_8039CDE8_7AE498(D_803F7DA8.unk18, 6.0f);
    } else {
        D_803F7DA8.unk14 += (0.0f - D_803F7DA8.unk14) / 2;
        D_803F7DA8.unk18 += (0.0f - D_803F7DA8.unk18) / 2;
        D_803F7DA8.unk14 = func_8039CDE8_7AE498(D_803F7DA8.unk14, 0.0f);
        D_803F7DA8.unk18 = func_8039CDE8_7AE498(D_803F7DA8.unk18, 0.0f);
    }

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

    // big celebration parade
    draw_level_rings_segment(180, 180, 180, 128, 30, 30, &D_8023F260,                              spE0,                                spDC, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // europe
    draw_level_rings_segment(180,  40, 120, 128, 0,   9, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unkC,  D_803F7DA8.unk4 + D_803F7DA8.unk10, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // ice
    draw_level_rings_segment(0,   180, 255, 128, 10, 16, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unk24, D_803F7DA8.unk4 + D_803F7DA8.unk28, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // jungle
    draw_level_rings_segment(0,   160,   0, 128, 17, 22, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unk1C, D_803F7DA8.unk4 + D_803F7DA8.unk20, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // desert
    draw_level_rings_segment(200, 200,   0, 128, 23, 29, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unk14, D_803F7DA8.unk4 + D_803F7DA8.unk18, D_803F7DA8.unk8, D_803F7DA8.currentLevel);

    load_default_display_list(&D_801D9E7C);
    set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
    select_font(0, FONT_COMIC_SANS, 0, 0);

    vertical_offset = 60;

    if (D_803F7DA8.currentLevel != SECRET_LEVEL-1) {
        // write title text
        display_text(&D_801D9E7C, (s16*)D_803F2D50.titleText, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
    }
    vertical_offset += D_803B74B0_7C8B60 + 1.0f;

    if (D_803F7DA8.currentLevel != SECRET_LEVEL-1) {
        if (D_8023F260.level[D_803F7DA8.currentLevel].completed == 1) {
            display_text(&D_801D9E7C, get_message_address_by_id(MSG_SECURED), 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        } else {
            display_text(&D_801D9E7C, get_message_address_by_id(MSG_AVAILABLE), 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        }
        vertical_offset += D_803B74B0_7C8B60 + 1.0f;
    }

    level = D_803F7DA8.currentLevel + 1;

    if ((level == GIVE_A_DOG_A_BONUS) ||
        (level == WALRACE_64) ||
        (level == EVOS_ESCAPE) ||
        (level == PUNCHUP_PYRAMID) ||
        (level == BIG_CELEBRATION_PARADE) ||
        (level == SECRET_LEVEL)) {

        if (level == GIVE_A_DOG_A_BONUS) {
            score = (D_8023F260.unk30 >> 13) & 0x1FF;
            if (score) {
                seconds_to_mins_secs(score, &mins, &secs);
                if (secs < 10) {
                    sprintf(ascii, "%d:0%d", mins, secs);
                } else {
                    sprintf(ascii, "%d:%d", mins, secs);
                }
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_1), 264, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (level == WALRACE_64) {
            score = D_8023F260.unk30 & 0xFF;
            if (score) {
                seconds_to_mins_secs(score, &mins, &secs);
                if (secs < 10) {
                    sprintf(ascii, "%d:0%d", mins, secs);
                } else {
                    sprintf(ascii, "%d:%d", mins, secs);
                }
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                if ((gEepromGlobal.language == LANG_ITALIAN) || (gEepromGlobal.language == LANG_FRENCH)) {
                    display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_2), 264, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                } else {
                    display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_2), 270, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                }
            }
        }
        if (level == EVOS_ESCAPE) {
            score = (D_8023F260.unk30 >> 24) * 100;
            if (score) {
                sprintf(ascii, "%d", score);
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_HIGH_SCORE), 257, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (level == PUNCHUP_PYRAMID) {
            score = (D_8023F260.unk30 >> 8) & 0x1F;
            if (score) {
                sprintf(ascii, "%d", score);
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_ROUNDS), 285, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (level == BIG_CELEBRATION_PARADE) {
            score = (D_8023F260.unk34 >> 8) & 0x1FF;
            if (score) {
                seconds_to_mins_secs(score, &mins, &secs);
                if (secs < 10) {
                    sprintf(ascii, "%d:0%d", mins, secs);
                } else {
                    sprintf(ascii, "%d:%d", mins, secs);
                }
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_1), 264, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (level == SECRET_LEVEL) {
            score = ((D_8023F260.unk34 >> 21) & 0x7FF) * 100;
            sprintf(ascii, "%d", score );
            prepare_text((u8*)ascii, wide_text);
            display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
            display_text(&D_801D9E7C, get_message_address_by_id(MSG_HIGH_SCORE), 240, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        }
    } else {
        sprintf(ascii, "%2d", D_8023F260.level[D_803F7DA8.currentLevel].powercells);
        prepare_text((u8*)ascii, wide_text);
        display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);

        gSPDisplayList(D_801D9E7C++, D_801584A0);

        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);
        gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x80);

        // draw powercell
        func_803962EC_7A799C(&D_801D9E7C, 1040, (vertical_offset - 2) << 2, 1104, (vertical_offset + 14) << 2, D_800DE390, 32, 32);
    }
    func_8039D034_7AE6E4(&D_801D9E7C, 0);
}

void func_8039A2DC_7AB98C(void) {
    s8 ascii[26];
    s16 wide_text[26];
    s16 vertical_offset;

    s8 cont_up;
    s8 cont_down;
    s8 cont_left;
    s8 cont_right;
    s8 stick_input;

    s16 x_offset;
    s16 y_offset;
    s16 progress[3];

    if (D_803F7DA8.unk2F == 0) {
        D_803F7DA8.unk31 = 99; // initialise default?
    }
    func_8039CE38_7AE4E8(&D_801D9E7C);
    func_8039CAB8_7AE168(1);

    render_stars(&D_801D9E7C);
    gDPPipeSync(D_801D9E7C++);

    load_default_display_list(&D_801D9E7C);

    select_font(0, FONT_COMIC_SANS, 0, 0);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
    if (gEepromGlobal.language == LANG_FRENCH) {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_BANK_SELECT), 24, 31, 22.0f, 16.0f, -1);
        D_803B74AC_7C8B5C = 11.0f; // glyph height
        D_803B74B0_7C8B60 = 16.0f; // glyph width
    } else {
        D_803B74AC_7C8B5C = 12.0f; // glyph height
        D_803B74B0_7C8B60 = 16.0f; // glyph width
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_BANK_SELECT), 24, 31, 24.0f, 16.0f, -1);
    }

    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    gSPDisplayList(D_801D9E7C++, D_801584A0);

    func_8039C5F8_7ADCA8(56,   88, 1.0f, (PlayerEeprom*)&D_8023F2E0[0], (D_803F7DA8.bank == 0) || (D_803F7DA8.unk31 == 0));
    func_8039C5F8_7ADCA8(132,  88, 1.0f, (PlayerEeprom*)&D_8023F2E0[1], (D_803F7DA8.bank == 1) || (D_803F7DA8.unk31 == 1));
    func_8039C5F8_7ADCA8(56,  164, 1.0f, (PlayerEeprom*)&D_8023F2E0[2], (D_803F7DA8.bank == 2) || (D_803F7DA8.unk31 == 2));
    func_8039C5F8_7ADCA8(132, 164, 1.0f, (PlayerEeprom*)&D_8023F2E0[3], (D_803F7DA8.bank == 3) || (D_803F7DA8.unk31 == 3));

    // get user progress
    if (D_803F7DA8.unk2F == 2) {
        get_player_progress((PlayerEeprom *) &D_8023F2E0[D_803F7DA8.unk31], (s16*)&progress);
    } else {
        get_player_progress((PlayerEeprom *) &D_8023F2E0[D_803F7DA8.bank], (s16*)&progress);
    }
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);

    if (D_802912E4 == 1) {
        D_803F7DA3 = 0;
    }
    if (D_802912E3 == 1) {
        D_803F7DA2 = 0;
    }

    cont_up = cont_down = cont_left = cont_right = stick_input = 0;

    if (gControllerInput->stick_x < -0x1E) {
        if (D_801D9ED4 == 0) {
            cont_left = 1;
        } else {
            stick_input = 1;
        }
    }
    if (gControllerInput->stick_x > 0x1E) {
        if (D_801D9ED4 == 0) {
            cont_right = 1;
        } else {
            stick_input = 1;
        }
    }
    if (gControllerInput->stick_y > 0x1E) {
        if (D_801D9ED4 == 0) {
            cont_up = 1;
        } else {
            stick_input = 1;
        }
    }
    if (gControllerInput->stick_y < -0x1E) {
        if (D_801D9ED4 == 0) {
            cont_down = 1;
        } else {
            stick_input = 1;
        }
    }
    if ((cont_up != 0) || (cont_down != 0) || (cont_left != 0) || (cont_right != 0)) {
        D_801D9ED4 = 17;
    }

    if (stick_input == 0) {
        if (((gControllerInput->button & CONT_LEFT) != 0) && (D_802912E3 == 1)) {
            cont_left = 1;
        } else if (((gControllerInput->button & CONT_RIGHT) != 0) && (D_802912E4 == 1)) {
            cont_right = 1;
        } else if (((gControllerInput->button & CONT_UP) != 0) && (D_802912E1 == 1)) {
            cont_up = 1;
        } else if (((gControllerInput->button & CONT_DOWN) != 0) && (D_802912E2 == 1)) {
            cont_down = 1;
        }
    }
    switch (D_803F7DA8.unk2F) { // BANK SELECT
    case 0: // NO MENU OPEN
        if ((cont_left) && ((D_803F7DA8.bank == 1) || (D_803F7DA8.bank == 3))) {
            D_803F7DA8.bank -= 1;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((cont_right) && (((D_803F7DA8.bank == 0)) || (D_803F7DA8.bank == 2))) {
            D_803F7DA8.bank += 1;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((cont_up) && (((D_803F7DA8.bank == 2)) || (D_803F7DA8.bank == 3))) {
            D_803F7DA8.bank -= 2;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((cont_down) && (((D_803F7DA8.bank == 0)) || (D_803F7DA8.bank == 1))) {
            D_803F7DA8.bank += 2;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1) && (D_803F6680.unk24 == 0)) {
            play_sound_effect(164, 0, 0x5000, 1.0f, 64);
            func_80395074_7A6724(0);
            func_8038F708_7A0DB8();
        }
        if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
            ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
            play_sound_effect(0x93, 0, 0x5000, 1.0f, 64);
            func_80395074_7A6724(0);
            if (D_803F7DA8.unk2F == 0) {
                D_803F7DA8.unk2F = 1;
                D_803F7DA8.unk30 = 0; // SELECT
            }
        }
        break;
    case 1: // "SELECT / COPY / DELETE" MENU OPEN
        if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
            ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
            func_80395074_7A6724(0);
            if (D_803F7DA8.unk30 == 0) { // SELECT
                play_sound_effect(0x8F, 0, 0x5000, 1.0f, 64);
                memcpy_sssv((u8 *) &D_8023F2E0[D_803F7DA8.bank], (u8 *) &D_8023F260, 64);

                D_803F7DA8.unk8 = 1.0f; // scale
                switch (D_803F7DA8.bank) {
                case 0:
                    D_803F7DA8.unk0 = 56.0f;
                    D_803F7DA8.unk4 = 88.0f;
                    break;
                case 1:
                    D_803F7DA8.unk0 = 132.0f;
                    D_803F7DA8.unk4 = 88.0f;
                    break;
                case 2:
                    D_803F7DA8.unk0 = 56.0f;
                    D_803F7DA8.unk4 = 164.0f;
                    break;
                case 3:
                    D_803F7DA8.unk0 = 132.0f;
                    D_803F7DA8.unk4 = 164.0f;
                    break;
                }

                D_803F6680.unk18 += 1;
                func_8039884C_7A9EFC();
                D_803F7DA8.currentLevel = 0;
            }
            if (D_803F7DA8.unk30 == 1) { // COPY
                play_sound_effect(0x93, 0, 0x5000, 1.0f, 64);

                D_803F7DA8.unk2F = 2;
                if (D_803F7DA8.bank == 0) {
                    D_803F7DA8.unk31 = 1;
                }
                if (D_803F7DA8.bank == 1) {
                    D_803F7DA8.unk31 = 3;
                }
                if (D_803F7DA8.bank == 2) {
                    D_803F7DA8.unk31 = 0;
                }
                if (D_803F7DA8.bank == 3) {
                    D_803F7DA8.unk31 = 2;
                }
            }
            if (D_803F7DA8.unk30 == 2) { // DELETE
                play_sound_effect(0x93, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 3;
                D_803F7DA8.unk30 = 0;
            }
        } else {
            if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1)) {
                play_sound_effect(164, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 0;
            }
            if (cont_up != 0) {
                if (D_803F7DA8.unk30 > 0) {
                    D_803F7DA8.unk30 -= 1;
                    play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
                }
            }
            if (cont_down != 0) {
                if (D_803F7DA8.unk30 < 2) {
                    D_803F7DA8.unk30 += 1;
                    play_sound_effect(0x91, 0, 0x5000, 1.0f, 64);
                }
            }
        }

        if (D_803F7DA8.bank == 0) {
            x_offset = 58;
            y_offset = 88;
        }
        if (D_803F7DA8.bank == 1) {
            x_offset = 134;
            y_offset = 88;
        }
        if (D_803F7DA8.bank == 2) {
            x_offset = 58;
            y_offset = 164;
        }
        if (D_803F7DA8.bank == 3) {
            x_offset = 134;
            y_offset = 164;
        }

        draw_rectangle(&D_801D9E7C, x_offset - 38, y_offset - 24, x_offset + 36, y_offset + 20, 0, 0, 0, 0xA8);
        load_default_display_list(&D_801D9E7C);
        select_font(0, FONT_COMIC_SANS, 0, 0);

        if (D_803F7DA8.unk30 == 0) { // SELECT
            set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF); // white
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, 0xFF); // grey
        }
        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_SELECT), x_offset, (y_offset - 0x12), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

        if (D_803F7DA8.unk30 == 1) { // COPY
            set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, 0xFF);
        }
        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_COPY), x_offset, (y_offset - 6), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

        if (D_803F7DA8.unk30 == 2) { // DELETE
            set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, 0xFF);
        }
        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_DELETE), x_offset, (y_offset + 6), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

        break;
    case 2: // "COPY TO" MENU
        if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
            ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
            func_80395074_7A6724(0);
            memcpy_sssv((u8 *) &D_8023F2E0[D_803F7DA8.bank], (u8 *) &D_8023F2E0[D_803F7DA8.unk31], 64);
            memcpy_sssv((u8 *) &D_8023F2E0[D_803F7DA8.bank], (u8 *) &D_8023F260, 0x40);
            write_eeprom((s16) D_803F7DA8.unk31);
            D_803F7DA8.unk2F = 0;
            play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
        } else {
            if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1)) {
                play_sound_effect(164, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 0;
            }
            if ((cont_left != 0) && (((D_803F7DA8.unk31 == 1)) || (D_803F7DA8.unk31 == 3))) {
                D_803F7DA8.unk31 = (s8) (D_803F7DA8.unk31 - 1);
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 += 1;
                }
            }
            if ((cont_right != 0) && (((D_803F7DA8.unk31 == 0)) || (D_803F7DA8.unk31 == 2))) {
                D_803F7DA8.unk31 = (s8) (D_803F7DA8.unk31 + 1);
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);

                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 -= 1;
                }
            }
            if ((cont_up != 0) && (((D_803F7DA8.unk31 == 2)) || (D_803F7DA8.unk31 == 3))) {
                D_803F7DA8.unk31 -= 2;
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);

                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 += 2;
                }
            }
            if ((cont_down != 0) && (((D_803F7DA8.unk31 == 0)) || (D_803F7DA8.unk31 == 1))) {
                D_803F7DA8.unk31 += 2;
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 -= 2;
                }
            }
            if (D_803F7DA8.bank == 0) {
                x_offset = 58;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 1) {
                x_offset = 134;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 2) {
                x_offset = 58;
                y_offset = 164;
            }
            if (D_803F7DA8.bank == 3) {
                x_offset = 134;
                y_offset = 164;
            }
            draw_rectangle(&D_801D9E7C, (x_offset - 0x1E), (y_offset - 0x18), (x_offset + 0x1C), (s16) (y_offset + 0x14), (u8) 0, (u8) 0, (u8) 0, (u8) 0xA8);
            load_default_display_list(&D_801D9E7C);
            select_font(0, FONT_COMIC_SANS, 0, 0);
            set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_COPY2), x_offset, (y_offset - 0xC), D_803B74B4_7C8B64, D_803B74B8_7C8B68);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_TO), x_offset, y_offset, D_803B74B4_7C8B64, D_803B74B8_7C8B68);
        }
        break;
    case 3:
        if ((((gControllerInput->button & START_BUTTON)) && (D_802912DE == 1)) ||
            (((gControllerInput->button & A_BUTTON)) && (D_802912DF == 1))) {
            play_sound_effect(164, 0, 0x5000, 1.0f, 64);
            func_80395074_7A6724(0);
            if (D_803F7DA8.unk30 == 0) { // SELECT
                D_803F7DA8.unk2F = 0;
            } // else
            if (D_803F7DA8.unk30 == 1) { // COPY
                memset_bytes((u8 *) &D_8023F260, 0, 0x40);
                memset_bytes((u8 *) &D_8023F2E0[D_803F7DA8.bank], 0, 0x40);
                write_eeprom((s16) D_803F7DA8.bank);
                D_803F7DA8.unk2F = 0;
            }
        } else {
            if (((gControllerInput->button & B_BUTTON)) && (D_802912E0 == 1)) {
                play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 0;
            }
            if ((cont_up != 0) || (cont_down != 0)) {
                D_803F7DA8.unk30 = (1 - D_803F7DA8.unk30);
                if (D_803F7DA8.unk30 == 0) { // SELECT
                    play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                }
                if (D_803F7DA8.unk30 == 1) { // COPY
                    play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                }
            }

            if (D_803F7DA8.bank == 0) {
                x_offset = 58;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 1) {
                x_offset = 134;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 2) {
                x_offset = 58;
                y_offset = 164;
            }
            if (D_803F7DA8.bank == 3) {
                x_offset = 134;
                y_offset = 164;
            }
            draw_rectangle(&D_801D9E7C, (s16) (x_offset - 0x1E), (s16) (y_offset - 0x18), (s16) (x_offset + 0x1C), (s16) (y_offset + 0x14), (u8) 0, (u8) 0, (u8) 0, (u8) 0xA8);
            load_default_display_list(&D_801D9E7C);
            gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);

            select_font(0, FONT_COMIC_SANS, 0, 0);

            if (D_803F7DA8.unk30 == 0) { // SELECT
                set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                set_menu_text_color(0x80, 0x80, 0x80, 0xFF);
            }
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_CANCEL), x_offset, (y_offset - 0xC), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

            if (D_803F7DA8.unk30 == 1) { // COPY
                set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                set_menu_text_color(0x80, 0x80, 0x80, 0xFF);
            }
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_DELETE2), x_offset, y_offset, D_803B74B4_7C8B64, D_803B74B8_7C8B68);
        }
        break;
    }

    load_default_display_list(&D_801D9E7C);
    select_font(0, FONT_COMIC_SANS, 1, 0);
    set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);

    if ((gEepromGlobal.language == LANG_FRENCH) || (gEepromGlobal.language == LANG_SPANISH)) {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_SELECT_A_BANK), 0x17, 0xD0, 15.2f, 16.0f, -1);
    } else if ((gEepromGlobal.language == LANG_PORTUGESE) || (gEepromGlobal.language == LANG_JAPANESE)) {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_SELECT_A_BANK), 0x17, 0xD0, 10.0f, 16.0f, -1);
    } else {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_SELECT_A_BANK), 0x17, 0xD0, 16.0f, 16.0f, -1);
    }

    vertical_offset = 56;

    // write "Secure Zones"
    display_text(&D_801D9E7C, get_message_address_by_id(MSG_SECURE_ZONES), 264, vertical_offset, D_803B74AC_7C8B5C, D_803B74B0_7C8B60);

    // write "Species"
    vertical_offset += D_803B74B0_7C8B60 + 6.0f;
    display_text(&D_801D9E7C, get_message_address_by_id(MSG_SPECIES), 264, vertical_offset, D_803B74AC_7C8B5C, D_803B74B0_7C8B60);

    // write "Encountered"
    vertical_offset += D_803B74B0_7C8B60;
    display_text(&D_801D9E7C, get_message_address_by_id(MSG_ENCOUNTERED), 264, vertical_offset, D_803B74AC_7C8B5C, D_803B74B0_7C8B60);

    vertical_offset = 56;
    // write ":" for "Secure Zones"
    sprintf(ascii, "%s", ":");
    prepare_text((u8 *) ascii, wide_text);
    func_8012D374(&D_801D9E7C, wide_text, 268, vertical_offset, 12.0f, D_803B74B0_7C8B60, -1);

    // write ":" for "Species Encountered"
    vertical_offset += D_803B74B0_7C8B60 + 6.0f;
    vertical_offset += D_803B74B0_7C8B60;
    func_8012D374(&D_801D9E7C, wide_text, 268, vertical_offset, 12.0f, D_803B74B0_7C8B60, -1);

    // write ":" for Powercell icon
    vertical_offset += D_803B74B0_7C8B60 + 6.0f;
    func_8012D374(&D_801D9E7C, wide_text, 268, vertical_offset, 12.0f, D_803B74B0_7C8B60, -1);

    // write levels
    vertical_offset = 56;
    sprintf(ascii, "%2d", progress[0]); // levels
    prepare_text((u8 *) ascii, wide_text);
    display_text(&D_801D9E7C, wide_text, 300, vertical_offset, 12.0f, D_803B74B0_7C8B60);

    vertical_offset += D_803B74B0_7C8B60 + 6.0f;
    vertical_offset += D_803B74B0_7C8B60;

    // write species
    sprintf(ascii, "%2d", progress[1]); // species
    prepare_text((u8 *) ascii, wide_text);
    display_text(&D_801D9E7C, wide_text, 300, vertical_offset, 12.0f, D_803B74B0_7C8B60);

    // write powercells
    vertical_offset += D_803B74B0_7C8B60 + 6.0f;
    sprintf(ascii, "%3d", progress[2]); // powercells
    prepare_text((u8 *) ascii, wide_text);
    display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);

    gSPDisplayList(D_801D9E7C++, D_801584A0);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0xff, 0xff, 0xff);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);
    gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x80);

    // draw powercell
    func_803962EC_7A799C(&D_801D9E7C, 968, (vertical_offset - 2) << 2, 1032, (vertical_offset + 14) << 2, D_800DE390, 32, 32);
    func_8039D034_7AE6E4(&D_801D9E7C, 0);
}

void func_8039BBB8_7AD268(void) {
    s16 level;

    if (D_803F2D50.unkC6 != 0) {
        if (D_803E4D28 & 1) { // souvenir collected
            level = D_803F7DA8.currentLevel + 1;
            if ((level != GIVE_A_DOG_A_BONUS) &&
                (level != WALRACE_64) &&
                (level != EVOS_ESCAPE) &&
                (level != PUNCHUP_PYRAMID) &&
                (level != BIG_CELEBRATION_PARADE)) {
                D_8023F260.level[D_803F2D30.level - 1].trophy = 1;
            }
            // regalloc helper
            if (1) {}
        }
        level = D_803F7DA8.currentLevel + 1;
        if (D_803E4D28 & 2) { // level completed
            if (level == GIVE_A_DOG_A_BONUS) {
                D_8023F260.evoPartsCollected |= EVO_TORSO;
            }
            if (level == WALRACE_64) {
                D_8023F260.evoPartsCollected |= EVO_HEAD;
            }
            if (level == EVOS_ESCAPE) {
                D_8023F260.evoPartsCollected |= EVO_ARMS;
            }
            if (level == PUNCHUP_PYRAMID) {
                D_8023F260.evoPartsCollected |= EVO_LEGS;
            }
        }
        if ((level == GIVE_A_DOG_A_BONUS) ||
            (level == WALRACE_64) ||
            (level == EVOS_ESCAPE) ||
            (level == PUNCHUP_PYRAMID)) {
            if (D_803E4D28 & 2) {
                D_8023F260.level[D_803F2D30.level - 1].completed = 1;
            }
        } else {
            D_8023F260.level[D_803F2D30.level - 1].completed = 1;
            // 'powercells' element used to store 'time' in bonus levels
            if (D_8023F260.level[D_803F2D30.level - 1].powercells < D_803F2D30.powercells) {
                D_8023F260.level[D_803F2D30.level - 1].powercells = D_803F2D30.powercells;
            }
        }
        D_803F2D50.unkC6 = 0;
        memcpy_sssv((u8*)&D_8023F260, (u8*)&D_8023F2E0[D_803F7DA8.bank], 64);
        write_eeprom(D_803F7DA8.bank);

        level = D_803F7DA8.currentLevel + 1;
        if ((level == GIVE_A_DOG_A_BONUS) ||
            (level == WALRACE_64) ||
            (level == EVOS_ESCAPE) ||
            (level == PUNCHUP_PYRAMID)) {
            if (D_803E4D28 & 2) {
                if (level == PUNCHUP_PYRAMID) {
                    // only increment level counter if we have collected all bodyparts
                    if (D_8023F260.evoPartsCollected == (EVO_TORSO | EVO_HEAD | EVO_ARMS | EVO_LEGS)) {
                        D_803F7DA8.currentLevel += 1;
                    }
                } else {
                    D_803F7DA8.currentLevel += 1;
                }
            }
        } else {
            D_803F7DA8.currentLevel += 1;
        }
        // there is no level 32, so trigger end credits
        if (D_803F7DA8.currentLevel == SECRET_LEVEL-1) {
            D_803F7DA8.currentLevel = END_CREDITS-1;
        }
    } else {
        if (D_8023F260.score < D_803F2D30.score) {
            D_8023F260.score = D_803F2D30.score;
        }
        memcpy_sssv((u8*)&D_8023F260, (u8*)&D_8023F2E0[D_803F7DA8.bank], 64);
        write_eeprom(D_803F7DA8.bank);
    }
}

#if 0
// NEEDS_BSS
void draw_level_rings_segment(u8 red, u8 green, u8 blue, u8 alpha, s16 start, s16 end, PlayerEeprom *eeprom, s16 xRot, s16 yRot, f32 scale, u8 currentLevel) {
    u8 flipx;
    u8 flipy;
    u8 idx;
    u16 img;
    s16 i;
    f32 scale2;
    f32 xPos;
    f32 yPos;
    static s32 D_803F7D60;

    D_803F7D60 += 1;
    D_803F7D60 = D_803F7D60 % 100; // pulse

    if (start == 30) {
        if (currentLevel == (i = 30)) {
            if (eeprom->level[30].completed == 1) {
                if (D_803F7D60 < 50) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240); // orange (selected)
                }
            } else {
                if (D_803F7D60 < 50) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240); // orange (selected)
                }
            }
        } else if ((D_803F7DFE == 0) && (currentLevel != 0xFF)) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        } else if (currentLevel == 0xFF) {
            if (eeprom->level[30].completed == 1) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red - 0xF, 0x28, 0x28, 0xFF);
            } else {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 0xFF);
            }
        } else {
            if (eeprom->level[30].completed == 1) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
            } else {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 70);
            }
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800BA760, 43, 43, scale, scale, 0, 0, xRot, yRot);
    } else {

        scale2 = scale / 2;

        for (i = start; i <= end; i++) {
            flipy = flipx = 0;
            idx = i;

            img = D_803B71D0_7C8880[idx].idx * 0x4B0; // sizeof(RingSegment)

            if (D_803B71D0_7C8880[idx].xPos < 0) {
                flipx = 1;
            }
            if (D_803B71D0_7C8880[idx].yPos < -1) {
                flipy = 1;
            }

            if (i == currentLevel) {
                if (eeprom->level[idx].completed == 1) {
                    if (D_803F7D60 < 50) {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                    } else {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240);
                    }
                } else {
                    if (D_803F7D60 < 50) {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                    } else {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240);
                    }
                }
            } else if ((D_803F7DE0[idx] == 0) && (currentLevel != 0xFF)) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
            } else if (currentLevel == 0xFF) {
                if (eeprom->level[idx].completed == 1) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red + 15, 0, 0, 255);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 255);
                }
            } else {
                if (eeprom->level[idx].completed == 1) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 70);
                }
            }

            yPos = (D_803B71D0_7C8880[idx].yPos * scale);
            xPos = (D_803B71D0_7C8880[idx].xPos * scale);

            func_8039C834_7ADEE4(
                /* dl     */ &D_801D9E7C,
                /* img    */ (u8*)D_800BA760 + 0xFA0 + img,
                /* width  */ (D_803B71D0_7C8880[idx].width << 1),
                /* height */ (D_803B71D0_7C8880[idx].height << 1),
                /* xscale */ scale2,
                /* yscale */ scale2,
                /* flipx  */ flipx,
                /* flipy  */ flipy,
                /* xpos   */ (s16) (s32) (xRot + xPos),
                /* ypos   */ (s16) (s32) (yRot + yPos)
            );
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/ui_main_menu/draw_level_rings_segment.s")
#endif

void func_8039C5F8_7ADCA8(s16 xRot, s16 yRot, f32 scale, PlayerEeprom *eeprom, s16 active) {
    s32 xRot2, yRot2;
    u8 evo_r, evo_g, evo_b, col;

    if (active == 1) {
        evo_r = 200;
        evo_g = 200;
        evo_b = 255;
        col = 255;
    } else {
        evo_r = 60;
        evo_g = 60;
        evo_b = 100;
        col = 128;
    }
    gDPSetPrimColor(D_801D9E7C++, 0, 0, col, col, col, 255);

    xRot2 = xRot - (21.5f * scale);
    yRot2 = yRot - (21.5f * scale);
    // BIG_CELEBRATION_PARADE
    draw_level_rings_segment(evo_r, evo_g, evo_b, 128, 30, 30, eeprom, xRot2, yRot2, scale, -1);
    // EUROPE
    draw_level_rings_segment(evo_r, evo_g, evo_b, 128,  0,  9, eeprom, xRot, yRot, scale, -1);
    // ICE
    draw_level_rings_segment(evo_r, evo_g, evo_b, 128, 10, 16, eeprom, xRot, yRot, scale, -1);
    // JUNGLE
    draw_level_rings_segment(evo_r, evo_g, evo_b, 128, 17, 22, eeprom, xRot, yRot, scale, -1);
    // DESERT
    draw_level_rings_segment(evo_r, evo_g, evo_b, 128, 23, 29, eeprom, xRot, yRot, scale, -1);
}

// draw sprite
void func_8039C834_7ADEE4(Gfx **dl, u8 *src, u16 width, u16 height, f32 scale_x, f32 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y) {
    guSprite2DInit(
    /* sprite ptr */    &D_80204278->sprites[D_80204278->usedSprites],
    /* source ptr */    src,
    /* tlut ptr */      0,
    /* stride */        width,
    /* width */         width,
    /* height */        height - 1,
    /* img type */      0,
    /* bitsize */       2,
    /* s */             0,
    /* t */             0);

    gSPSprite2DBase((*dl)++, OS_K0_TO_PHYSICAL(&D_80204278->sprites[D_80204278->usedSprites]));
    gSPSprite2DScaleFlip((*dl)++, 1024.0f / scale_x, 1024.0f / scale_y, flip_x, flip_y);

    gSPSprite2DDraw((*dl)++, p_screen_x * 4, p_screen_y * 4);

    D_80204278->usedSprites += 1;
}

void func_8039CAB8_7AE168(s16 arg0) {
    if (arg0 == 1) {
        draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 40);
    }

    gSPDisplayList(D_801D9E7C++, D_801584A0);
    gDPPipeSync(D_801D9E7C++);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);

    gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
    gDPSetRenderMode(D_801D9E7C++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, 255, 80);

    gDPSetColorDither(D_801D9E7C++, G_CD_NOISE);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_DISABLE);

    func_8039C834_7ADEE4(&D_801D9E7C, D_800BDC80, 320, 36, 1.0f, 1.0f, 0, 0, 0, 12);

    gDPPipeSync(D_801D9E7C++);
}

void get_player_progress(PlayerEeprom *e, s16 *arg1) {
    s16 levels;
    s16 powercells;
    s16 species;
    s16 i;

    levels = species = powercells = 0;

    for (i = 0; i < 31; i++) {
        if (e->level[i].completed) {
            levels += 1;
        }
        if ((i != GIVE_A_DOG_A_BONUS-1) &&
            (i != WALRACE_64-1) &&
            (i != EVOS_ESCAPE-1) &&
            (i != PUNCHUP_PYRAMID-1) &&
            (i != BIG_CELEBRATION_PARADE-1)) {
            powercells += e->level[i].powercells;
        }
    }

    for (i = 0; i < AID_MAX_ANIMALS; i++) {
        if (e->speciesSeen[(s8)(i >> 3)] & (1 << (s8)(i % 7))) {
            species += 1;
        }
    }

    arg1[0] = levels;
    arg1[1] = species;
    arg1[2] = powercells;
}

// min/max with tolerance?
f32 func_8039CDE8_7AE498(f32 arg0, f32 arg1) {
    if (((arg1 - 0.25) < arg0) && (arg0 < (arg1 + 0.25))) {
        return arg1;
    } else {
        return arg0;
    }
}

void func_8039CE38_7AE4E8(Gfx **arg0) {
    D_803B66F0_7C7DA0.vp.vscale[0] = 640;
    D_803B66F0_7C7DA0.vp.vscale[1] = 480;
    D_803B66F0_7C7DA0.vp.vtrans[0] = 640;
    D_803B66F0_7C7DA0.vp.vtrans[1] = 480;

    gDPPipeSync((*arg0)++);
    gSPLoadUcode((*arg0)++, &gspSprite2D_fifoTextStart, &gspSprite2D_fifoDataStart);
    gDPPipeSync((*arg0)++);

    load_segments(arg0, D_80204278);

    gSPViewport((*arg0)++, &D_803B66F0_7C7DA0);
    gDPSetDepthImage((*arg0)++, osVirtualToPhysical(&D_80100000));
    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
    gSPDisplayList((*arg0)++, D_01004270_3DB40);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPPipeSync((*arg0)++);
}

void func_8039D034_7AE6E4(Gfx **arg0, s16 arg1) {
    if (D_803F6680.unk24 == 0) {
        if (D_803F7D9E == 0) {
            if (RAND(1000) < 10) {
                D_803F7D9E = 1;
            }
        } else {
            D_803F7D9E += 1;
        }

        if ((RAND(2) + 1) < D_803F7D9E) {
            D_803F7D9E = 0;
        }
        if (D_803F7D9C == 0) {
            if (RAND(2000) < 10) {
                D_803F7D9C = 1;
                func_8032CD20_73E3D0(0x283B, 116, 0x4000, 0, 1.0f);
            }
        } else {
            D_803F7D9C += 1;
        }
        if ((RAND(5) + 9) < D_803F7D9C) {
            D_803F7D9C = 0;
        }

        if ((D_803F7D9C != 0) || (arg1 != 0)) {
            gDPPipeSync((*arg0)++);
            gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
            gDPSetBlendColor((*arg0)++, 0, 0, 0, 128);
            gDPSetRenderMode((*arg0)++, G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_NOOP2);
            gSPClearGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
            gDPSetTexturePersp((*arg0)++, G_TP_NONE);
            gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

            if (arg1 != 0) {
                gDPSetPrimColor((*arg0)++, 0, 0, 120, 120, 120, arg1);

            } else {
                gDPSetPrimColor((*arg0)++, 0, 0, 120, 120, 120, 5);

            }
            gDPPipeSync((*arg0)++);
            gDPFillRectangle((*arg0)++, 0, 0, 320, 239);
            gDPPipeSync(D_801D9E7C++);
        }
    }
}

void render_stars(Gfx **arg0) {
    s16 _i;

    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
    gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode((*arg0)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (_i = 0; _i < 180; _i++) {
        s16 x, y, i;

        // FIXME: fakematch
        i = _i;
        if (0) {};

        gDPSetPrimColor((*arg0)++, 0, 0, D_800DF220[i].brightness, D_800DF220[i].brightness, D_800DF220[i].brightness, 0);

        D_800DF220[i].x -= D_800DF220[i].speed * D_80204290;
        if (D_800DF220[i].x < 40) {
            // wrap around if moving off left side of screen
            D_800DF220[i].x += 1280;
        }

        x = D_800DF220[i].x;
        y = D_800DF220[i].y * 4;
        gSPTextureRectangle((*arg0)++, x, y, x + 4, y + 4, G_TX_RENDERTILE, 0, 0, 0, 0);
    }

    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPPipeSync((*arg0)++);
}

void generate_stars(void) {
    s16 i;
    for (i = 0; i < 180; i++) {
        D_800DF220[i].x = RAND(320) * 4;
        D_800DF220[i].y = RAND(240) * 4;
        D_800DF220[i].speed = RAND(4) + 1;
        D_800DF220[i].brightness = (D_800DF220[i].speed * 15) + 70;
    }
}

void determine_available_levels(void) {
    s16 i;
    s16 trophies_collected;

    for (i = 0; i < 31; i++) {
        if (i == 30) {
            if (D_8023F260.evoPartsCollected == (EVO_TORSO | EVO_HEAD | EVO_ARMS | EVO_LEGS)) {
                D_803F7DE0[i] = 1; // BIG_CELEBRATION_PARADE available
            } else {
                D_803F7DE0[i] = 0;
            }
        } else {
            if (D_8023F260.level[i].completed) {
                D_803F7DE0[i] = 1;
            } else {
                D_803F7DE0[i] = 0;
            }
            if ((i != 0) && (D_8023F260.level[i-1].completed)) {
                // eeprom says level completed, so enable it
                D_803F7DE0[i] = 1;
            }
        }
    }

    // initialise level counts to zero
    D_803F7E00 = D_803F7E02 = D_803F7E04 = D_803F7E06 = 0;

    // first level is always available
    D_803F7DE0[0] = 1;

    // determine europe levels completed
    for (i = 0; i < 10; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E00++;
        }
    }

    // if 3+ europe levels are complete, enable ice biome
    if (D_803F7E00 >= 3) {
        for (i = 10; i < D_803F7E00 + 9; i++) {
            if (i == 10) {
                D_803F7DE0[i] = 1;
            } else if (D_8023F260.level[i-1].completed) {
                D_803F7DE0[i] = 1;
            }
        }
    }
    for (i = 10; i < 17; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E02++;
        }
    }

    // if 3+ ice levels are complete, enable jungle biome
    if (D_803F7E02 >= 3) {
        for (i = 17; i < D_803F7E02 + 16; i++) {
            if (i == 17) {
                D_803F7DE0[i] = 1;
            } else if (D_8023F260.level[i-1].completed) {
                D_803F7DE0[i] = 1;
            }
        }
    }
    for (i = 17; i < 23; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E04++;
        }
    }

    // if 3+ jungle levels are complete, enable desert biome
    if (D_803F7E04 > 2) {
        for (i = 23; i < D_803F7E04 + 22; i++) {
            if (i == 23) {
                D_803F7DE0[i] = 1;
            } else if (D_8023F260.level[i-1].completed) {
                D_803F7DE0[i] = 1;
            }
        }
    }
    for (i = 23; i < 30; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E06++; // unused
        }
    }

    trophies_collected = 0;
    for (i = 0; i < 30; i++) {
        if (D_8023F260.level[i].trophy) {
            trophies_collected++;
        }
    }
    // if all trophies collected enable hidden level
    if (trophies_collected >= 26) {
        D_803F7DE0[31] = 1;
    } else {
        D_803F7DE0[31] = 0;
    }

    // check cheats / overrides
    if (gCheats.europe) {
        for (i = 0; i < 10; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (gCheats.ice) {
        for (i = 10; i < 17; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (gCheats.jungle) {
        for (i = 17; i < 23; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (gCheats.desert) {
        for (i = 23; i < 30; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (gCheats.bcp) {
        D_803F7DE0[30] = 1;
    }
    if (gCheats.hidden) {
        D_803F7DE0[31] = 1;
    }
}

// e.g. get_next_available_level(JUNGLE_JUMPS, -1)
s16 get_next_available_level(s16 current_level, s16 offset) {
    s16 level;
    s16 new_level;

    new_level = 99;
    level = current_level + offset;

    while (level != current_level) {
        // can this cause OOB?
        if ((D_803F7DE0[level] != 0) && (new_level == 99)) {
            new_level = level; // found available level?
        }
        level += offset;

        // wraparound
        if (level < 0) {
            level = 31;
        }
        if (level >= 32) {
            level = 0;
        }
    };

    if (new_level != 99) {
        return new_level;
    }
    return current_level;
}

void seconds_to_mins_secs(const s16 seconds, s16 *mins, s16 *secs) {
    s16 _div = seconds / 60;
    *mins = _div;
    *secs = seconds - (s16) (_div * 60);
}

void load_level_title(void) {
    s16 found;
    s16 i;
    s16 *msg;

    found = 0;
    // iterate over each message
    for (i = 0; i < gLoadedMessageCount; i++) {
        msg = &D_803F34C0[(s16)D_803F3330[i]];
        if ((msg[0] == TEXT_CONTROL_CHAR) &&
            (msg[1] == TEXT_NEWLINE)) {
            // we found e.g. <N>Smashing Start
            msg = &msg[2];
            memcpy_sssv((u8*)msg, (u8*)D_803F2D50.titleText, 84);
            found = 1;
        }
    }

    if (found == 0) {
        D_803F2D50.titleText[0] = 304; // ' '
        D_803F2D50.titleText[1] = EOM;
    }
}

// note that levels appear to be in-game order (1-indexed) rather than common.h
// SMASHING_START (level 1) would be considered 0 here
s16 get_biome_for_level(s16 arg0) {
    if ((arg0 >= SMASHING_START-1) && (arg0 < SNOW_JOKE-1)) {
        return UI_EUROPE_BIOME;
    }
    if ((arg0 >= SNOW_JOKE-1) && (arg0 < JUNGLE_JAPES-1)) {
        return UI_ICE_BIOME;
    }
    if ((arg0 >= JUNGLE_JAPES-1) && (arg0 < FUN_IN_THE_SUN-1)) {
        return UI_JUNGLE_BIOME;
    }
    if ((arg0 >= FUN_IN_THE_SUN-1) && (arg0 < BIG_CELEBRATION_PARADE-1)) {
        return UI_DESERT_BIOME;
    }
    // TODO: understand why this is not END_CREDITS-1
    if ((arg0 == BIG_CELEBRATION_PARADE-1) || (arg0 == SECRET_LEVEL-1)) {
        return UI_CITY_BIOME;
    }
}
