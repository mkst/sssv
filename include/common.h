#ifndef COMMON_H
#define COMMON_H

#define ABS(x) ((x)<0 ? -(x) : (x))
#define ABSF(x) ((x)<0.0f ? -(x) : (x))
#define ABSD(x) ((x)<0.0 ? -(x) : (x))

#define MAX_INT                0x7FFFFFFF
#define MAX_SHORT              0x7FFF

// DMA's interpretation of PI...
#define SSSV_PI                3.141579

#define SSSV_RAND(x)           (func_8012826C() & (x - 1))

#define MAX_EUROPE_ANIMALS     19
#define MAX_ICE_ANIMALS        11
#define MAX_DESERT_ANIMALS     8
#define MAX_JUNGLE_ANIMALS     12

#define OB_TYPE_ANIMAL_OFFSET  256
#define AID_MAX_ANIMALS        68

#define DEFAULT_AUDIO_VOLUME   16
#define MAX_AUDIO_VOLUME       19
#define MIN_AUDIO_VOLUME       0

#define MAX_OBJECTS            169

#define MAX_LIGHTS             5

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

// segments (per animinit.c)

#define SEGMENT_EUROPE              0
#define SEGMENT_ICE                 1
#define SEGMENT_DESERT              2
#define SEGMENT_JUNGLE              3
#define SEGMENT_4                   4
#define SEGMENT_CITY                5
#define SEGMENT_SHIP                6


// biomes (per aidata.c)
#define EUROPE_BIOME                0
#define ICE_BIOME                   1
#define DESERT_BIOME                2
#define JUNGLE_BIOME                3
#define CITY_BIOME                  4

// ui is in 'game order'
#define UI_EUROPE_BIOME             0
#define UI_ICE_BIOME                1
#define UI_JUNGLE_BIOME             2
#define UI_DESERT_BIOME             3
#define UI_CITY_BIOME               4

// fonts
#define FONT_DEFAULT                0
#define FONT_COMIC_SANS             2
#define FONT_LCD                    3

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
#define TILESET_SPACE           (TILESET_ASCII_OFFSET + ' ')
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

#define END_DEMO 0xFFFF


#define PAUSE_MENU_OPTION_CONTINUE  0
#define PAUSE_MENU_OPTION_MISSION_BRIEF 1
#define PAUSE_MENU_OPTION_REPLAY_ZONE 2
#define PAUSE_MENU_OPTION_EXIT_ZONE 3
#define PAUSE_MENU_OPTION_MUSIC     4
#define PAUSE_MENU_OPTION_SFX       5
#define PAUSE_MENU_OPTION_LANGUAGE  6
#define PAUSE_MENU_OPTION_LEAVE_SV  7

// attacks? animations? poses?

#define ATTACK_NONE         0
#define ATTACK_VULTURE      1
#define ATTACK_FROG_TONGUE  2
#define ATTACK_SHEEP_HEADBUTT 3
#define ATTACK_KANGAROO_1   4
#define ATTACK_KANGAROO_2   5
#define ATTACK_SCORPION_1   6
#define ATTACK_CHAMELEON_TONGUE 7
#define ATTACK_ROAR         8
#define ATTACK_GRAB         11
#define ATTACK_HOLD         12
#define ATTACK_BEAR_2       14
#define ATTACK_BEAR_3       15
#define ATTACK_ELEPHANT_1   16
#define ATTACK_SPIT         17
#define ATTACK_BITE         18
#define ATTACK_FART         19
#define ATTACK_FOX_DASH     20
#define ATTACK_CAMEL_1      22
#define ATTACK_CAMEL_2      23
#define ATTACK_CHAMELEON_1  24
#define ATTACK_CHAMELEON_2  25
#define ATTACK_POLAR_BEAR_1 26
#define ATTACK_POLAR_BEAR_2 27
#define ATTACK_POLAR_BEAR_3 28
#define ATTACK_RABBIT_1     29
#define ATTACK_SNOWBALL     32
#define ATTACK_KANGAROO_3   35
#define ATTACK_DESERT_FOX_1 36
#define ATTACK_DESERT_FOX_SPIN 37
#define ATTACK_SCORPION_2   38
#define ATTACK_KING_RAT     39
#define ATTACK_MOUSE_TAIL   40
#define ATTACK_MOUSE_2      41
#define ATTACK_FOX_TAIL     42
#define ATTACK_FOX_3        43
#define ATTACK_SHEEP_FLOAT  45
#define ATTACK_DOG_1        48

// objects

#define OBJECT_CANNONBALL   17
#define OBJECT_MISSILE      18
#define OBJECT_SWITCH_ON    24


// transitions

#define TRANSITION_1        1
#define TRANSITION_FADE_IN  2
#define TRANSITION_FADE_OUT_BLK 3

// ai behaviours

#define AI_IGNORE           0
#define AI_FLEE             1
#define AI_ATTACK           2
#define AI_SAME_ANIMAL      3
#define AI_HERD             4
#define AI_LEAD_HERD        5
#define AI_FOLLOWER         6
#define AI_LEADER           7
#define AI_INVISIBLE        8

// custom ASSERT

#define SSSV_ASSERT(TEST, FILE, LINE) \
    if (!(TEST)) { \
        rmonPrintf("\nASSERT: "#TEST", %s, %u\n", FILE, LINE); \
        *(volatile int*)0 = 0; \
    }


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
