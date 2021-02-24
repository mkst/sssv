#ifndef COMMON_H
#define COMMON_H

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
