#ifndef COMMON_H
#define COMMON_H

#define ABS(x) ((x)<0 ? -(x) : (x))
#define ABSF(x) ((x)<0.0f ? -(x) : (x))

#define MAX_EUROPE_ANIMALS     19
#define MAX_ICE_ANIMALS        11
#define MAX_DESERT_ANIMALS     8
#define MAX_JUNGLE_ANIMALS     12

#define OB_TYPE_ANIMAL_OFFSET  256
#define AID_MAX_ANIMALS        68

#define DEFAULT_AUDIO_VOLUME   16
#define MAX_AUDIO_VOLUME       19
#define MIN_AUDIO_VOLUME       0

#ifdef VERSION_US
#include "common.us.h"
#endif

#ifdef VERSION_EU
#include "common.eu.h"
#endif

#include "sfx.h"
#include "messages.h"
#include "levels.h"
#include "animals.h"


// evo suit colors
#define EVO_BRONZE_SHELLSUIT        0
#define EVO_SILVER_SHELLSUIT        1
#define EVO_GOLD_SHELLSUIT          2

// evo body parts
#define EVO_TORSO                   1
#define EVO_HEAD                    2
#define EVO_ARMS                    4
#define EVO_LEGS                    8

// biomes
#define EUROPE_BIOME                0
#define ICE_BIOME                   1
#define JUNGLE_BIOME                2
#define DESERT_BIOME                3
#define CITY_BIOME                  4



// states
#define STATE_STANDING               2
#define STATE_WALKING                3
#define STATE_RUNNING                4
#define STATE_IN_AIR                 5
// #define STATE_06 - collecting something? collsion?
// #define STATE_FISH_IN_WATER          62
// #define STATE_FISH_OUT_OF_WATER      63
#define STATE_FISH_IN_WATER          141
#define STATE_FISH_SWIMMING_SLOW     142
#define STATE_FISH_SWIMMING          143

#define STATE_FISH_STANDING_ON_LAND  161
#define STATE_FISH_WALKING_ON_LAND   162

#define STATE_STANDING_IN_WATER      181
#define STATE_WALKING_IN_WATER       182

// unknown states
// 6, 21, 23, 41, 43, 61, 81, 101, 121, 144, 183, 185, 201, 0x3F, 0x90,

#define TILESET_ASCII_OFFSET    272
#define TILESET_ZERO (TILESET_ASCII_OFFSET + '0')
#define TILESET_NINE (TILESET_ASCII_OFFSET + '9')

#define TEXT_CONTROL_CHAR       336
#define TEXT_TIMER              343
#define TEXT_COLOR              339
#define TEXT_NEWLINE            350

#define TEXT_COLOR_BLUE         338
#define TEXT_COLOR_CYAN         339
#define TEXT_COLOR_GREEN        343
#define TEXT_COLOR_PURPLE       352
#define TEXT_COLOR_RED          354
#define TEXT_COLOR_WHITE        359
#define TEXT_COLOR_BLACK        360
#define TEXT_COLOR_YELLOW       361

// region
#define REGION_JP       0
#define REGION_EU       1
#define REGION_US       2

// languages

#define LANG_AMERICAN   0
#define LANG_DUTCH      1
#define LANG_ENGLISH    2
#define LANG_FRENCH     3
#define LANG_GERMAN     4
#define LANG_ITALIAN    5
#define LANG_JAPANESE   6
#define LANG_PORTUGESE  7
#define LANG_SPANISH    8
#define LANG_DEFAULT    20

#define LANG_MIN        LANG_AMERICAN
#define LANG_MAX        LANG_SPANISH

#define NEWLINE         20000
#define EOM             30000


#define PAUSE_MENU_OPTION_CONTINUE  0
#define PAUSE_MENU_OPTION_MISSION_BRIEF 1
#define PAUSE_MENU_OPTION_REPLAY_ZONE 2
#define PAUSE_MENU_OPTION_EXIT_ZONE 3
#define PAUSE_MENU_OPTION_MUSIC     4
#define PAUSE_MENU_OPTION_SFX       5
#define PAUSE_MENU_OPTION_LANGUAGE  6
#define PAUSE_MENU_OPTION_LEAVE_SV  7

// extra gbi macros

#define gDPLoadTextureBlock2(pkt, timg, fmt, line, siz, width, height, \
    pal, cms, cmt, masks, maskt, shifts, shiftt) \
{ \
    gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); \
    gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, \
        0 , cmt, maskt, shiftt, cms, masks, shifts); \
    gDPLoadSync(pkt); \
    gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, \
        (((width*height)>>2) - 1), \
        CALC_DXT_4b(width) ); \
    gDPPipeSync(pkt); \
    gDPSetTile(pkt, fmt, G_IM_SIZ_4b /* TODO: take as param? */, \
      line, 0, \
      G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, \
      shifts); \
    gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, \
      ((width)-1) << G_TEXTURE_IMAGE_FRAC, \
      ((height)-1) << G_TEXTURE_IMAGE_FRAC) \
}

#endif
