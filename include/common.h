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

#ifdef VERSION_US
#include "common.us.h"
#endif

#ifdef VERSION_EU
#include "common.eu.h"
#endif

// levels
#define NO_LEVEL_0               0
#define SMASHING_START           1
#define HAVE_A_NICE_DAY          2
#define HONEYMOON_LAGOON         3
#define THE_BATTERY_FARM         4
#define THE_ENGINE_ROOM          5
#define FAT_BEAR_MOUNTAIN        6
#define ROCKY_HARD_PLACE         7
#define STINKY_SEWERS            8
#define RAT_O_MATIC              9
#define GIVE_A_DOG_A_BONUS       10
#define SNOW_JOKE                11
#define ICE_N_EASY_DOES_IT       12
#define PENGUIN_PLAYPEN          13
#define PINBALL_BLIZZARD         14
#define HOPPA_CHOPPA             15
#define SOMETHING_FISHY          16
#define WALRACE_64               17
#define JUNGLE_JAPES             18
#define JUNGLE_DOLDRUMS          19
#define SWAMP_OF_ETERNAL_STENCH  20
#define WEIGHT_FOR_IT            21
#define JUNGLE_JUMPS             22
#define EVOS_ESCAPE              23
#define FUN_IN_THE_SUN           24
#define HOT_CROSS_BUNS           25
#define STING_IN_THE_TAIL        26
#define BORASSIC_PARK            27
#define WHIRLWIND_TOUR           28
#define SHIFTING_SANDS           29
#define PUNCHUP_PYRAMID          30
#define BIG_CELEBRATION_PARADE   31
#define NO_LEVEL_32              32
#define NO_LEVEL_33              33
#define NO_LEVEL_34              34
#define END_CREDITS              35
#define DMA_INTRO                36

// animals
#define SEAGULL                     0
#define LION                        1
#define HIPPO                       2
#define RACING_HIPPO                3
#define RACING_DOG                  4
#define FLYING_DOG                  5
#define FOX                         6
#define FIRE_FOX                    7
#define FROG                        8
#define POLAR_BEAR_DEFENDING        9
#define RABBIT                      10
#define HELI_RABBIT                 11
#define COD                         12
#define KING_RAT                    13
#define PARROT                      14
#define PARROT_ATTACKING            15
#define MOUSE                       16
#define RACING_MOUSE_ATTACKING      17 // HARD_MOUSE
#define RACING_MOUSE                18
#define VULTURE                     19
#define MOUSE2                      20 // ear-less? mouse-attacking?
#define HELI_MOUSE                  21 // ?
#define BEAR                        22
#define BEAR_ATTACKING              23 // CRAZY_BEAR
#define MYSTERY_BEAR                24
#define SEAGULL2                    25
#define RACING_FOX                  26
#define TORTOISE_TANK               27
#define RACING_TORTOISE             28
#define TORTOISE_TANK_DEFENDING     29
#define PIRANA                      30
#define DOG                         31
#define RAT                         32
#define SHEEP                       33
#define RAM                         34
#define SPRINGY_THINGY              35
#define SPRINGY_RAM                 36
#define PENGUIN                     37
#define POLAR_BEAR                  38
#define POLAR_TANK                  39
#define HUSKY                       40
#define HUSKY_ATTACKING             41 // CRAZY_HUSKY
#define SKI_HUSKY                   42
#define CROW                        43
#define WALRUS                      44
#define VULTURE2                    45
#define CAMEL                       46
#define CANNON_CAMEL                47
#define CROW_DIVER                  48
#define POGO_KANGAROO               49
#define BOXING_KANGAROO             50
#define DESERT_FOX                  51
#define ARMED_DESERT_FOX            52
#define SCORPION                    53
#define GORILLA                     54
#define DESERT_FOX_ATTACKING        55
#define ELEPHANT                    56
#define HYENA                       57
#define HYENA_BIKER                 58
#define CHAMELEON                   59
#define CHAMELEON_DEFENDING         60 // SNEAKY_CHAMELEON
#define EVO_MICROCHIP               61
#define EVO_GLITCHY                 62
#define UNKNOWN_ANIMAL_63           63 // EVO
#define KING_PENGUIN                64
#define RACING_TORTOISE_ATTACKING   65
#define COOL_COD                    66
#define EVO_SHELLSUIT               67

// evo suit colors
#define EVO_BRONZE_SHELLSUIT        0
#define EVO_SILVER_SHELLSUIT        1
#define EVO_GOLD_SHELLSUIT          2

// biomes
#define EUROPE_BIOME                0
#define ICE_BIOME                   1
#define JUNGLE_BIOME                2
#define DESERT_BIOME                3
#define CITY_BIOME                  4

// sound effects
#define SFX_RAT_BITE                7
#define SFX_CHEAT_ENABLED           86
#define SFX_DROP_BOMB               124
#define SFX_DROP_MINE               156
#define SFX_BUGEL_CALL              184

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
