#include <ultra64.h>
#include "common.h"
#include "pp.h"

#include "camera.h"


// ========================================================
// definitions
// ========================================================

void *func_802C93E8_6DAA98(s32); // mismatch / missing?

typedef struct {
  u16 count;
  u8  payload[1];
} DataSectionUnsigned;

typedef struct {
  s16 count;
  s16 payload[1];
} DataSectionSigned;

typedef union {
    DataSectionUnsigned u;
    DataSectionSigned s;
} DataSection;

// ========================================================
// .data
// ========================================================

static u8 *biomeRgba16MipmapTextures[6*2] = {
    _img_levels_europe_rgba16_mipmapSegmentRomStart, _img_levels_europe_rgba16_mipmapSegmentRomEnd,
    _img_levels_ice_rgba16_mipmapSegmentRomStart,    _img_levels_ice_rgba16_mipmapSegmentRomEnd,
    _img_levels_desert_rgba16_mipmapSegmentRomStart, _img_levels_desert_rgba16_mipmapSegmentRomEnd,
    _img_levels_jungle_rgba16_mipmapSegmentRomStart, _img_levels_jungle_rgba16_mipmapSegmentRomEnd,
    _empty_rnc_44E790SegmentRomStart,                _empty_rnc_44E790SegmentRomEnd,  // empty
    _img_levels_city_rgba16_mipmapSegmentRomStart,   _img_levels_city_rgba16_mipmapSegmentRomEnd,
};
static u8 *biomeIa16MipmapTextures[6*2] = {
    _img_levels_europe_ia16_mipmapSegmentRomStart, _img_levels_europe_ia16_mipmapSegmentRomEnd,
    _img_levels_ice_ia16_mipmapSegmentRomStart,    _img_levels_ice_ia16_mipmapSegmentRomEnd,
    _img_levels_desert_ia16_mipmapSegmentRomStart, _img_levels_desert_ia16_mipmapSegmentRomEnd,
    _img_levels_jungle_ia16_mipmapSegmentRomStart, _img_levels_jungle_ia16_mipmapSegmentRomEnd,
    _img_levels_unused_ia16_mipmapSegmentRomStart, _img_levels_unused_ia16_mipmapSegmentRomEnd,
    _img_levels_city_ia16_mipmapSegmentRomStart,   _img_levels_city_ia16_mipmapSegmentRomEnd,
};
static u8 *levelRgba16MipmapTextures[2*(10+1+10+10+10)] = {
    // europe
    _img_levels_HAVE_A_NICE_DAY_mipmapSegmentRomStart,       _img_levels_HAVE_A_NICE_DAY_mipmapSegmentRomEnd, // 0
    _img_levels_HONEYMOON_LAGOON_mipmapSegmentRomStart,      _img_levels_HONEYMOON_LAGOON_mipmapSegmentRomEnd, // 1
    _img_levels_SMASHING_START_mipmapSegmentRomStart,        _img_levels_SMASHING_START_mipmapSegmentRomEnd, // 2
    _img_levels_THE_BATTERY_FARM_mipmapSegmentRomStart,      _img_levels_THE_BATTERY_FARM_mipmapSegmentRomEnd, // 3
    _img_levels_GIVE_A_DOG_A_BONUS_mipmapSegmentRomStart,    _img_levels_GIVE_A_DOG_A_BONUS_mipmapSegmentRomEnd, // 4
    _img_levels_THE_ENGINE_ROOM_mipmapSegmentRomStart,       _img_levels_THE_ENGINE_ROOM_mipmapSegmentRomEnd, // 5
    _img_levels_STINKY_SEWERS_mipmapSegmentRomStart,         _img_levels_STINKY_SEWERS_mipmapSegmentRomEnd, // 6
    _img_levels_RAT_O_MATIC_mipmapSegmentRomStart,           _img_levels_RAT_O_MATIC_mipmapSegmentRomEnd, // 7
    _img_levels_ROCKY_HARD_PLACE_mipmapSegmentRomStart,      _img_levels_ROCKY_HARD_PLACE_mipmapSegmentRomEnd, // 8
    _img_levels_FAT_BEAR_MOUNTAIN_mipmapSegmentRomStart,     _img_levels_FAT_BEAR_MOUNTAIN_mipmapSegmentRomEnd, // 9
    // final
    _img_levels_BIG_CELEBRATION_PARADE_mipmapSegmentRomStart, _img_levels_BIG_CELEBRATION_PARADE_mipmapSegmentRomEnd, // 10
    // ice
    _img_levels_SOMETHING_FISHY_mipmapSegmentRomStart,       _img_levels_SOMETHING_FISHY_mipmapSegmentRomEnd, // 11
    _img_levels_ICE_N_EASY_DOES_IT_mipmapSegmentRomStart,    _img_levels_ICE_N_EASY_DOES_IT_mipmapSegmentRomEnd, // 12
    _img_levels_PINBALL_BLIZZARD_mipmapSegmentRomStart,      _img_levels_PINBALL_BLIZZARD_mipmapSegmentRomEnd, // 13
    _img_levels_WALRACE_64_mipmapSegmentRomStart,            _img_levels_WALRACE_64_mipmapSegmentRomEnd, // 14
    _img_levels_PENGUIN_PLAYPEN_mipmapSegmentRomStart,       _img_levels_PENGUIN_PLAYPEN_mipmapSegmentRomEnd, // 15
    _img_levels_SNOW_JOKE_mipmapSegmentRomStart,             _img_levels_SNOW_JOKE_mipmapSegmentRomEnd, // 16
    _empty_rnc_4B3440SegmentRomStart, _empty_rnc_4B3440SegmentRomEnd, // 17
    _img_levels_HOPPA_CHOPPA_mipmapSegmentRomStart,          _img_levels_HOPPA_CHOPPA_mipmapSegmentRomEnd, // 18
    _empty_rnc_4B79A0SegmentRomStart, _empty_rnc_4B79A0SegmentRomEnd, // 19
    _empty_rnc_4B79C0SegmentRomStart, _empty_rnc_4B79C0SegmentRomEnd, // 20
    // desert
    _img_levels_FUN_IN_THE_SUN_mipmapSegmentRomStart,        _img_levels_FUN_IN_THE_SUN_mipmapSegmentRomEnd, // 21
    _img_levels_HOT_CROSS_BUNS_mipmapSegmentRomStart,        _img_levels_HOT_CROSS_BUNS_mipmapSegmentRomEnd, // 22
    _img_levels_PUNCHUP_PYRAMID_mipmapSegmentRomStart,       _img_levels_PUNCHUP_PYRAMID_mipmapSegmentRomEnd, // 23
    _img_levels_STING_IN_THE_TAIL_mipmapSegmentRomStart,     _img_levels_STING_IN_THE_TAIL_mipmapSegmentRomEnd, // 24
    _img_levels_SHIFTING_SANDS_mipmapSegmentRomStart,        _img_levels_SHIFTING_SANDS_mipmapSegmentRomEnd, // 25
    _img_levels_WHIRLWIND_TOUR_mipmapSegmentRomStart,        _img_levels_WHIRLWIND_TOUR_mipmapSegmentRomEnd, // 26
    _img_levels_BORASSIC_PARK_mipmapSegmentRomStart,         _img_levels_BORASSIC_PARK_mipmapSegmentRomEnd, // 27
    _img_levels_UNUSED_DESERT_SLOT_8_mipmapSegmentRomStart,  _img_levels_UNUSED_DESERT_SLOT_8_mipmapSegmentRomEnd, // 28
    _empty_rnc_4D6960SegmentRomStart, _empty_rnc_4D6960SegmentRomEnd, // 29
    _empty_rnc_4D6980SegmentRomStart, _empty_rnc_4D6980SegmentRomEnd, // 30
    // jungle
    _img_levels_WEIGHT_FOR_IT_mipmapSegmentRomStart,         _img_levels_WEIGHT_FOR_IT_mipmapSegmentRomEnd, // 31
    _empty_rnc_4DB210SegmentRomStart, _empty_rnc_4DB210SegmentRomEnd, // 32
    _img_levels_JUNGLE_JUMPS_mipmapSegmentRomStart,          _img_levels_JUNGLE_JUMPS_mipmapSegmentRomEnd, // 33
    _img_levels_SWAMP_OF_ETERNAL_STENCH_mipmapSegmentRomStart, _img_levels_SWAMP_OF_ETERNAL_STENCH_mipmapSegmentRomEnd, // 34
    _img_levels_JUNGLE_DOLDRUMS_mipmapSegmentRomStart,       _img_levels_JUNGLE_DOLDRUMS_mipmapSegmentRomEnd, // 35
    _img_levels_EVOS_ESCAPE_mipmapSegmentRomStart,           _img_levels_EVOS_ESCAPE_mipmapSegmentRomEnd, // 36
    _img_levels_JUNGLE_JAPES_mipmapSegmentRomStart,          _img_levels_JUNGLE_JAPES_mipmapSegmentRomEnd, // 37
    _empty_rnc_4F5470SegmentRomStart, _empty_rnc_4F5470SegmentRomEnd, // 38
    _empty_rnc_4F5490SegmentRomStart, _empty_rnc_4F5490SegmentRomEnd, // 39
    _empty_rnc_4F54B0SegmentRomStart, _empty_rnc_4F54B0SegmentRomEnd, // 40
};

// level mipmap
static u8** levelRgba16MipmapTexturesLUT[4] = {
    &levelRgba16MipmapTextures[0*2],
    &levelRgba16MipmapTextures[(10+1)*2],
    &levelRgba16MipmapTextures[(10+1+10)*2],
    &levelRgba16MipmapTextures[(10+1+10+10)*2],
};

static u8 *biomeRgba16Textures[8] = {
    _img_levels_europe_rgba16_regularSegmentRomStart,          _img_levels_europe_rgba16_regularSegmentRomEnd,
    _img_levels_ice_rgba16_regularSegmentRomStart,             _img_levels_ice_rgba16_regularSegmentRomEnd,
    _img_levels_desert_rgba16_regularSegmentRomStart,          _img_levels_desert_rgba16_regularSegmentRomEnd,
    _img_levels_jungle_rgba16_regularSegmentRomStart,          _img_levels_jungle_rgba16_regularSegmentRomEnd,
};
static u8 *levelRgba16Textures[82] = {
    _img_levels_HAVE_A_NICE_DAY_regularSegmentRomStart,        _img_levels_HAVE_A_NICE_DAY_regularSegmentRomEnd,
    _img_levels_HONEYMOON_LAGOON_regularSegmentRomStart,       _img_levels_HONEYMOON_LAGOON_regularSegmentRomEnd,
    _img_levels_SMASHING_START_regularSegmentRomStart,         _img_levels_SMASHING_START_regularSegmentRomEnd,
    _img_levels_THE_BATTERY_FARM_regularSegmentRomStart,       _img_levels_THE_BATTERY_FARM_regularSegmentRomEnd,
    _img_levels_GIVE_A_DOG_A_BONUS_regularSegmentRomStart,     _img_levels_GIVE_A_DOG_A_BONUS_regularSegmentRomEnd,
    _img_levels_THE_ENGINE_ROOM_regularSegmentRomStart,        _img_levels_THE_ENGINE_ROOM_regularSegmentRomEnd,
    _img_levels_STINKY_SEWERS_regularSegmentRomStart,          _img_levels_STINKY_SEWERS_regularSegmentRomEnd,
    _img_levels_RAT_O_MATIC_regularSegmentRomStart,            _img_levels_RAT_O_MATIC_regularSegmentRomEnd,
    _img_levels_ROCKY_HARD_PLACE_regularSegmentRomStart,       _img_levels_ROCKY_HARD_PLACE_regularSegmentRomEnd,
    _img_levels_FAT_BEAR_MOUNTAIN_regularSegmentRomStart,      _img_levels_FAT_BEAR_MOUNTAIN_regularSegmentRomEnd,

    _img_levels_BIG_CELEBRATION_PARADE_regularSegmentRomStart, _img_levels_BIG_CELEBRATION_PARADE_regularSegmentRomEnd,

    _img_levels_SOMETHING_FISHY_regularSegmentRomStart,        _img_levels_SOMETHING_FISHY_regularSegmentRomEnd,
    _img_levels_ICE_N_EASY_DOES_IT_regularSegmentRomStart,     _img_levels_ICE_N_EASY_DOES_IT_regularSegmentRomEnd,
    _img_levels_PINBALL_BLIZZARD_regularSegmentRomStart,       _img_levels_PINBALL_BLIZZARD_regularSegmentRomEnd,
    _img_levels_WALRACE_64_regularSegmentRomStart,             _img_levels_WALRACE_64_regularSegmentRomEnd,
    _img_levels_PENGUIN_PLAYPEN_regularSegmentRomStart,        _img_levels_PENGUIN_PLAYPEN_regularSegmentRomEnd,
    _img_levels_SNOW_JOKE_regularSegmentRomStart,              _img_levels_SNOW_JOKE_regularSegmentRomEnd,
    _rnc_507F60_regularSegmentRomStart, _rnc_507F60_regularSegmentRomEnd,
    _img_levels_HOPPA_CHOPPA_regularSegmentRomStart,           _img_levels_HOPPA_CHOPPA_regularSegmentRomEnd,
    _rnc_507FC0_regularSegmentRomStart, _rnc_507FC0_regularSegmentRomEnd,
    _rnc_509220_regularSegmentRomStart, _rnc_509220_regularSegmentRomEnd,

    _img_levels_FUN_IN_THE_SUN_regularSegmentRomStart,         _img_levels_FUN_IN_THE_SUN_regularSegmentRomEnd,
    _img_levels_HOT_CROSS_BUNS_regularSegmentRomStart,         _img_levels_HOT_CROSS_BUNS_regularSegmentRomEnd,
    _img_levels_PUNCHUP_PYRAMID_regularSegmentRomStart,        _img_levels_PUNCHUP_PYRAMID_regularSegmentRomEnd,
    _img_levels_STING_IN_THE_TAIL_regularSegmentRomStart,      _img_levels_STING_IN_THE_TAIL_regularSegmentRomEnd,
    _img_levels_SHIFTING_SANDS_regularSegmentRomStart,         _img_levels_SHIFTING_SANDS_regularSegmentRomEnd,
    _img_levels_WHIRLWIND_TOUR_regularSegmentRomStart,         _img_levels_WHIRLWIND_TOUR_regularSegmentRomEnd,
    _img_levels_BORASSIC_PARK_regularSegmentRomStart,          _img_levels_BORASSIC_PARK_regularSegmentRomEnd,
    _rnc_512240_regularSegmentRomStart, _rnc_512240_regularSegmentRomEnd,
    _rnc_512270_regularSegmentRomStart, _rnc_512270_regularSegmentRomEnd,
    _rnc_5122A0_regularSegmentRomStart, _rnc_5122A0_regularSegmentRomEnd,

    _img_levels_WEIGHT_FOR_IT_regularSegmentRomStart,          _img_levels_WEIGHT_FOR_IT_regularSegmentRomEnd,
    _rnc_5137C0_regularSegmentRomStart,                        _rnc_5137C0_regularSegmentRomEnd,
    _img_levels_JUNGLE_JUMPS_regularSegmentRomStart,           _img_levels_JUNGLE_JUMPS_regularSegmentRomEnd,
    _img_levels_SWAMP_OF_ETERNAL_STENCH_regularSegmentRomStart, _img_levels_SWAMP_OF_ETERNAL_STENCH_regularSegmentRomEnd,
    _img_levels_JUNGLE_DOLDRUMS_regularSegmentRomStart,        _img_levels_JUNGLE_DOLDRUMS_regularSegmentRomEnd,
    _img_levels_EVOS_ESCAPE_regularSegmentRomStart,            _img_levels_EVOS_ESCAPE_regularSegmentRomEnd,
    _img_levels_JUNGLE_JAPES_regularSegmentRomStart,           _img_levels_JUNGLE_JAPES_regularSegmentRomEnd,
    _rnc_51AAF0_regularSegmentRomStart, _rnc_51AAF0_regularSegmentRomEnd,
    _rnc_51AB20_regularSegmentRomStart, _rnc_51AB20_regularSegmentRomEnd,
    _rnc_51AB50_regularSegmentRomStart, _rnc_51AB50_regularSegmentRomEnd,
};

static u8** levelRgba16TexturesLUT[4] = {
    &levelRgba16Textures[0*2],  // 0x803A5948,
    &levelRgba16Textures[(10+1)*2], // 0x803A59A0,
    &levelRgba16Textures[(10+1+10+10)*2], // 0x803A5A40,
    &levelRgba16Textures[(10+1+10)*2], // 0x803A59F0,
};

// level objects
static u8 *levelObjects[(10+1+10+10+10)*2] = {
    // europe
    _HAVE_A_NICE_DAYSegmentRomStart, _HAVE_A_NICE_DAYSegmentRomEnd,
    _HONEYMOON_LAGOONSegmentRomStart, _HONEYMOON_LAGOONSegmentRomEnd,
    _SMASHING_STARTSegmentRomStart, _SMASHING_STARTSegmentRomEnd,
    _THE_BATTERY_FARMSegmentRomStart, _THE_BATTERY_FARMSegmentRomEnd,
    _GIVE_A_DOG_A_BONUSSegmentRomStart, _GIVE_A_DOG_A_BONUSSegmentRomEnd,
    _DMA_INTROSegmentRomStart, _DMA_INTROSegmentRomEnd,
    _STINKY_SEWERSSegmentRomStart, _STINKY_SEWERSSegmentRomEnd,
    _RAT_O_MATICSegmentRomStart, _RAT_O_MATICSegmentRomEnd,
    _ROCKY_HARD_PLACESegmentRomStart, _ROCKY_HARD_PLACESegmentRomEnd,
    _FAT_BEAR_MOUNTAINSegmentRomStart, _FAT_BEAR_MOUNTAINSegmentRomEnd,
    // final
    _BIG_CELEBRATION_PARADESegmentRomStart, _BIG_CELEBRATION_PARADESegmentRomEnd,
    // ice
    _SOMETHING_FISHYSegmentRomStart, _SOMETHING_FISHYSegmentRomEnd,
    _ICE_N_EASY_DOES_ITSegmentRomStart, _ICE_N_EASY_DOES_ITSegmentRomEnd,
    _PINBALL_BLIZZARDSegmentRomStart, _PINBALL_BLIZZARDSegmentRomEnd,
    _WALRACE_64SegmentRomStart, _WALRACE_64SegmentRomEnd,
    _PENGUIN_PLAYPENSegmentRomStart, _PENGUIN_PLAYPENSegmentRomEnd,
    _SNOW_JOKESegmentRomStart, _SNOW_JOKESegmentRomEnd,
    _UNUSED_ICE_SLOT_7SegmentRomStart, _UNUSED_ICE_SLOT_7SegmentRomEnd,
    _HOPPA_CHOPPASegmentRomStart, _HOPPA_CHOPPASegmentRomEnd,
    _UNUSED_ICE_SLOT_9SegmentRomStart, _UNUSED_ICE_SLOT_9SegmentRomEnd,
    _UNUSED_ICE_SLOT_10SegmentRomStart, _UNUSED_ICE_SLOT_10SegmentRomEnd,
    // jungle
    _WEIGHT_FOR_ITSegmentRomStart, _WEIGHT_FOR_ITSegmentRomEnd,
    _UNUSED_JUNGLE_SLOT_2SegmentRomStart, _UNUSED_JUNGLE_SLOT_2SegmentRomEnd,
    _JUNGLE_JUMPSSegmentRomStart, _JUNGLE_JUMPSSegmentRomEnd,
    _SWAMP_OF_ETERNAL_STENCHSegmentRomStart, _SWAMP_OF_ETERNAL_STENCHSegmentRomEnd,
    _JUNGLE_DOLDRUMSSegmentRomStart, _JUNGLE_DOLDRUMSSegmentRomEnd,
    _EVOS_ESCAPESegmentRomStart, _EVOS_ESCAPESegmentRomEnd,
    _JUNGLE_JAPESSegmentRomStart, _JUNGLE_JAPESSegmentRomEnd,
    _UNUSED_JUNGLE_SLOT_8SegmentRomStart, _UNUSED_JUNGLE_SLOT_8SegmentRomEnd,
    _UNUSED_JUNGLE_SLOT_9SegmentRomStart, _UNUSED_JUNGLE_SLOT_9SegmentRomEnd,
    _UNUSED_JUNGLE_SLOT_10SegmentRomStart, _UNUSED_JUNGLE_SLOT_10SegmentRomEnd,
    // desert
    _FUN_IN_THE_SUNSegmentRomStart, _FUN_IN_THE_SUNSegmentRomEnd,
    _HOT_CROSS_BUNSSegmentRomStart, _HOT_CROSS_BUNSSegmentRomEnd,
    _PUNCHUP_PYRAMIDSegmentRomStart, _PUNCHUP_PYRAMIDSegmentRomEnd,
    _STING_IN_THE_TAILSegmentRomStart, _STING_IN_THE_TAILSegmentRomEnd,
    _SHIFTING_SANDSSegmentRomStart, _SHIFTING_SANDSSegmentRomEnd,
    _WHIRLWIND_TOURSegmentRomStart, _WHIRLWIND_TOURSegmentRomEnd,
    _BORASSIC_PARKSegmentRomStart, _BORASSIC_PARKSegmentRomEnd,
    _UNUSED_DESERT_SLOT_8SegmentRomStart, _UNUSED_DESERT_SLOT_8SegmentRomEnd,
    _UNUSED_DESERT_SLOT_9SegmentRomStart, _UNUSED_DESERT_SLOT_9SegmentRomEnd,
    _UNUSED_DESERT_SLOT_10SegmentRomStart, _UNUSED_DESERT_SLOT_10SegmentRomEnd,
};

static u8** levelObjectsLUT[4] = {
    &levelObjects[0*2],  // europe
    &levelObjects[11*2], // ice
    &levelObjects[31*2], // desert
    &levelObjects[21*2], // jungle
};

// levels
static u8 *levelData[72] = {
    _levels_SMASHING_STARTSegmentRomStart, _levels_SMASHING_STARTSegmentRomEnd,
    _levels_HAVE_A_NICE_DAYSegmentRomStart, _levels_HAVE_A_NICE_DAYSegmentRomEnd,
    _levels_HONEYMOON_LAGOONSegmentRomStart, _levels_HONEYMOON_LAGOONSegmentRomEnd,
    _levels_THE_BATTERY_FARMSegmentRomStart, _levels_THE_BATTERY_FARMSegmentRomEnd,
    _levels_THE_ENGINE_ROOMSegmentRomStart, _levels_THE_ENGINE_ROOMSegmentRomEnd,
    _levels_FAT_BEAR_MOUNTAINSegmentRomStart, _levels_FAT_BEAR_MOUNTAINSegmentRomEnd,
    _levels_ROCKY_HARD_PLACESegmentRomStart, _levels_ROCKY_HARD_PLACESegmentRomEnd,
    _levels_STINKY_SEWERSSegmentRomStart, _levels_STINKY_SEWERSSegmentRomEnd,
    _levels_RAT_O_MATICSegmentRomStart, _levels_RAT_O_MATICSegmentRomEnd,
    _levels_GIVE_A_DOG_A_BONUSSegmentRomStart, _levels_GIVE_A_DOG_A_BONUSSegmentRomEnd,

    _levels_SNOW_JOKESegmentRomStart, _levels_SNOW_JOKESegmentRomEnd,
    _levels_ICE_N_EASY_DOES_ITSegmentRomStart, _levels_ICE_N_EASY_DOES_ITSegmentRomEnd,
    _levels_PENGUIN_PLAYPENSegmentRomStart, _levels_PENGUIN_PLAYPENSegmentRomEnd,
    _levels_PINBALL_BLIZZARDSegmentRomStart, _levels_PINBALL_BLIZZARDSegmentRomEnd,
    _levels_HOPPA_CHOPPASegmentRomStart, _levels_HOPPA_CHOPPASegmentRomEnd,
    _levels_SOMETHING_FISHYSegmentRomStart, _levels_SOMETHING_FISHYSegmentRomEnd,
    _levels_WALRACE_64SegmentRomStart, _levels_WALRACE_64SegmentRomEnd,

    _levels_JUNGLE_JAPESSegmentRomStart, _levels_JUNGLE_JAPESSegmentRomEnd,
    _levels_JUNGLE_DOLDRUMSSegmentRomStart, _levels_JUNGLE_DOLDRUMSSegmentRomEnd,
    _levels_SWAMP_OF_ETERNAL_STENCHSegmentRomStart, _levels_SWAMP_OF_ETERNAL_STENCHSegmentRomEnd,
    _levels_WEIGHT_FOR_ITSegmentRomStart, _levels_WEIGHT_FOR_ITSegmentRomEnd,
    _levels_JUNGLE_JUMPSSegmentRomStart, _levels_JUNGLE_JUMPSSegmentRomEnd,
    _levels_EVOS_ESCAPESegmentRomStart, _levels_EVOS_ESCAPESegmentRomEnd,

    _levels_FUN_IN_THE_SUNSegmentRomStart, _levels_FUN_IN_THE_SUNSegmentRomEnd,
    _levels_HOT_CROSS_BUNSSegmentRomStart, _levels_HOT_CROSS_BUNSSegmentRomEnd,
    _levels_STING_IN_THE_TAILSegmentRomStart, _levels_STING_IN_THE_TAILSegmentRomEnd,
    _levels_BORASSIC_PARKSegmentRomStart, _levels_BORASSIC_PARKSegmentRomEnd,
    _levels_WHIRLWIND_TOURSegmentRomStart, _levels_WHIRLWIND_TOURSegmentRomEnd,
    _levels_SHIFTING_SANDSSegmentRomStart, _levels_SHIFTING_SANDSSegmentRomEnd,
    _levels_PUNCHUP_PYRAMIDSegmentRomStart, _levels_PUNCHUP_PYRAMIDSegmentRomEnd,

    _levels_BIG_CELEBRATION_PARADESegmentRomStart, _levels_BIG_CELEBRATION_PARADESegmentRomEnd,

    _levels_SECRET_LEVELSegmentRomStart, _levels_SECRET_LEVELSegmentRomEnd,

    _levels_EMPTY_LEVEL_1SegmentRomStart, _levels_EMPTY_LEVEL_1SegmentRomEnd,
    _levels_EMPTY_LEVEL_2SegmentRomStart, _levels_EMPTY_LEVEL_2SegmentRomEnd,

    _levels_CREDITSSegmentRomStart, _levels_CREDITSSegmentRomEnd,

    _levels_INTROSegmentRomStart, _levels_INTROSegmentRomEnd
};

// ========================================================
// .text
// ========================================================

u32 get_uncompressed_size(u8 *arg0) {
    if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
        // return uncompressed length length
        return arg0[7] | (arg0[6] << 8) | (arg0[5] << 16) | (arg0[4] << 24);
    } else {
        return arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24);
    }
}

s32 get_compressed_size(u8 *arg0) {
    if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
        // return compressed length length + RNC header size (18 bytes)
        return (arg0[11] | (arg0[10] << 8) | (arg0[9] << 16) | (arg0[8] << 24)) + HEADERLEN;
    } else {
        return (arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24)) + 4;
    }
}

s32 copy_or_extract(u8 *src, u8 *dst, s32 unused) {
    if ((src[0] == 'R') && (src[1] == 'N') && (src[2] == 'C')) {
        UnpackRNC((RNC_fileptr)src, dst);
    } else {
        // swap endianness
        memcpy_sssv(src + 4, dst, src[3] | (src[2] << 8) | (src[1] << 16) | (src[0] << 24));
    }
    return 1;
}

void load_level_texture_data(u8 bank, u8 level) {
    u8 **rom_addr;

    s32 pad[2] UNUSED;

    u8 **rgba16mipmap;
    u8 **rgba16regular;
    u8 **objects;

    u8 textureBank;
    u8 var_t0;

    textureBank = bank;
    var_t0 = bank;

    if (bank == SEGMENT_4) {
        // unused segment...
        textureBank = bank = SEGMENT_CITY;
    }

    if ((bank == SEGMENT_4) || (bank == SEGMENT_CITY)) {
        var_t0 = bank = 0;
    }

    osSyncPrintf("Bank - %d Texture - %d\n", bank, textureBank);

    level -= 1; // level index?

    // biome tetures
    rom_addr = &biomeRgba16MipmapTextures[(textureBank + textureBank) & 0xFFFF];
    dma_read(rom_addr[0], &D_80100000, rom_addr[1] - rom_addr[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, TEXTURES_BIOME_RGBA16_MIPMAP);

    rom_addr = &biomeIa16MipmapTextures[(textureBank + textureBank) & 0xFFFF];
    dma_read(rom_addr[0], &D_80100000, rom_addr[1] - rom_addr[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, TEXTURES_BIOME_IA16_MIPMAP);
    // load biome rgba16 non-mipmap textures
    rom_addr = &biomeRgba16Textures[(var_t0 + var_t0) & 0xFFFF];
    dma_read(rom_addr[0], &D_80100000, rom_addr[1] - rom_addr[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, TEXTURES_BIOME_RGBA16);

    // load level rgba16 mipmapped textures
    rgba16mipmap = levelRgba16MipmapTexturesLUT[bank];
    // load level rgba16 textures
    rgba16regular = levelRgba16TexturesLUT[bank];
    // load level objects
    objects = levelObjectsLUT[bank];

    rom_addr = rgba16mipmap;
    rom_addr += (level + level) & 0xFFFF;
    dma_read(rom_addr[0], &D_80100000, rom_addr[1] - rom_addr[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, TEXTURES_LEVEL_RGBA16_MIPMAP);

    rom_addr = rgba16regular;
    rom_addr += (level + level) & 0xFFFF;
    dma_read(rom_addr[0], &D_80100000, rom_addr[1] - rom_addr[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, TEXTURES_LEVEL_RGBA16);

    gSegment5Base = gfxspecific;

    rom_addr = objects;
    rom_addr += (level + level) & 0xFFFF;
    dma_read(rom_addr[0], gSegment5Base, rom_addr[1] - rom_addr[0]);
}

void load_level_data(u8 level) {
    u8 **rom_addr;
    s32 len;

    func_8031C374_72DA24();

    // 0-indexed so subtract 1
    level = level - 1;

    rom_addr = &levelData[level+level];
    len = rom_addr[1] - rom_addr[0];

    dma_read(rom_addr[0], D_80100000, len);
    load_level_data_sections();
    func_8031C48C_72DB3C();
}

#ifdef NON_MATCHING
// Level streams are a sequence of tagged payloads; svle writes them in this
// order: .dat, .mat, .map, .cmd, .cob, .can, .joi, .rng, .cha, .paf,
// geo, .cam, type 14, type 15, then type 3 as the terminator.
void load_level_data_sections(void) {
    Entity *obj;
    Entity *child;
    Entity *parent;
    Entity *object1;
    Entity *object2;

    struct092 *joi;
    struct097 *cha;
    struct090 *cob;
    struct091 *can;
    u8 *buf;

    s16 i;
    u8  done; // sp85
    s16 j;

    u16 count;
    s16 length;
    s16 rangeCount;
    u16 startingAnimalIndex;
    s16 *payload;

    s32 payloadLength;
    s32 sectionType;

    u16 pafBytesUsed;
    u8 *paf;
    u8 *paf2;

    DataSection *base;

    s16 type15EntryCount;

    base = &D_80100000;

    copy_or_extract(base, gFramebuffer, 0x25800);
    buf = gFramebuffer;

    startingAnimalIndex = gNumAnimalsInLevel;
    done = 0;

    do {
        sectionType = *buf++;

        switch (sectionType) {
        case 0: /* .cob: static objects */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = base->s.count;
            cob = (struct090*) base->s.payload;

            while (length-- > 0) {
                if (D_801E9EB8.unk0[cob->id].unk15 == 5) {
                    cob->zRotation = 0;
                    cob->angle = (cob->angle + 720) % 360; // force positive

                    if ((cob->angle >= 45) && (cob->angle < 135)) {
                        cob->angle = 90;
                    } else if ((cob->angle >= 135) && (cob->angle < 225)) {
                        cob->angle = 180;
                    } else if ((cob->angle >= 225) && (cob->angle < 315)) {
                        cob->angle = 270;
                    } else {
                        cob->angle = 0;
                    }
                }

                obj = spawn_object(
                    cob->id,
                    cob->x,
                    cob->z,
                    cob->y,
                    0, // xVel
                    0, // zVel
                    0, // yVel
                    cob->zRotation,
                    cob->angle,
                    cob->scale);

                if (cob->id == OBJECT_ENTRANCE_TELEPORTER) {
                    D_803F2D50.entranceTeleporter = obj;
                } else if (cob->id == OBJECT_EXIT_TELEPORTER) {
                    D_803F2D50.exitTeleporter = obj;
                }

                obj->unk3E = cob->unkC;

                // load object commands?
                if (cob->commandReferenceIdx != 0) {
                    load_commands_into_object(
                        obj,
                        &D_803E4D40[cob->commandReferenceIdx] - 1,
                        cob->commandsLength);
                }
                obj->cmdIndex = cob->unk12;
                cob++;
            }
            break;

        case 1: /* .can: animal spawns */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = base->s.count;
            can = (struct091*) base->s.payload;

            while (length-- > 0) {
                CmdWrapper *cmdWrapper;
                spawn_animal(
                    can->x,
                    can->z,
                    can->y,
                    can->rotation,
                    can->health,
                    can->id,
                    0);

                obj = gAnimalState.animals[gNumAnimalsInLevel - 1].animal;

                if (can->unkC != 0) {
                    cmdWrapper = &D_803E4D40[can->unkC] - 1;
                    load_commands_into_object(
                        obj,
                        cmdWrapper,
                        0);
                }

                obj->cmdIndex = can->unkE;
                can++;
            }
            break;

        case 2: /* .joi: links/joints between objects and animals */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = base->s.count;
            joi = (struct092*) base->s.payload;

            while (length-- > 0) {
                if (joi->parent >= 1000) {
                    parent = gAnimalState.animals[(joi->parent - 1000) + startingAnimalIndex].animal;
                } else {
                    parent = func_802C93E8_6DAA98(joi->parent);
                }
                if (joi->child >= 1000) {
                    child = gAnimalState.animals[(joi->child - 1000) + startingAnimalIndex].animal;
                } else {
                    child = func_802C93E8_6DAA98(joi->child);
                }
                func_802C9900_6DAFB0(parent, child, joi->referenceIdx); // implicitly lbu
                joi++;
            }
            break;
        case 3:  /* "end of data" sentinel */
            done = 1;
            break;

        case 4:  /* .cmd */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            count = base->u.count;
            payloadLength = sizeof(CmdWrapper);

            func_80314788_725E38(); // zero out D_803E4D40 amongst other things
            memcpy_sssv(base->s.payload, (u8*)D_803E4D40, count);

            D_803E8E54 = count / (u32)payloadLength; // gNumCommands
            for (j = 0; j < D_803E8E54; j++) {
                if (D_803E4D40[(u32)j].type == 24) {
                    if (1) {
                        osSyncPrintf(
                            "Partcle State: %d F $%X Fq %d Time %d S %d\n",
                            D_803E4D40[(u32)j].cmd.type24.State,
                            D_803E4D40[(u32)j].cmd.type24.F,
                            D_803E4D40[(u32)j].cmd.type24.Fq,
                            D_803E4D40[(u32)j].cmd.type24.Time,
                            D_803E4D40[(u32)j].cmd.type24.S);
                        }
                }
            }
            break;

        case 5: /* .rng */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            rangeCount = base->u.count;

            memcpy_sssv(base->s.payload, (u8*)&D_803E93B0, rangeCount * sizeof(struct067));

            D_803E93B0[rangeCount].unk2 = 245;
            D_803E93B0[rangeCount].unk5 = 245;

            func_803198B0_72AF60();
            break;

        case 6: /* .paf: variable-length waypoint paths */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            count = base->u.count;
            paf2 = paf = base->s.payload;

            pafBytesUsed = 0;
            for (i = 0; i < count; i++) {
                // record the start of each waypoint in D_803E8E60
                D_803E8E60[i] = (Waypoint*)&D_803E8F60[pafBytesUsed];
                // each waypoint starts with the count followed by count*xyz entries, e.g.
                //    B BBB BBB BBB ... =>
                //    3 123 456 789
                pafBytesUsed += (paf[0] * 3) + 1;
                // move pointer along
                paf = paf2 + pafBytesUsed;
            }

            // improves score by 30, but is likely unhelpful overall
            if (1) {
                osSyncPrintf("Path thingies: %d (%d).\n", pafBytesUsed, sizeof(D_803E8F60));
            }

            // NOTE: no boundary check that pafBytesUsed < sizeof(D_803E8F60)!
            memcpy_sssv(paf2, (u8*)D_803E8F60, pafBytesUsed);
            D_803A5750_7B6E00 = i;
            break;

        case 7: /* .cha: dynamic/hanging objects */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = base->s.count;
            cha = (struct097*) base->s.payload;

            while (length-- > 0) {
                // s32 a0, a1, a2, a3;
                s16 a0;
                s32 a1;
                u8 a2;
                s8 a3;

                object1 = NULL;
                object2 = NULL;
                if (cha->unkE != -1) {
                    object1 = func_802C93E8_6DAA98(cha->unkE);
                }
                if (cha->unk16 != -1) {
                    object2 = func_802C93E8_6DAA98(cha->unk16);
                }

                switch (cha->unk0) {
                case 6:
                    a0 = 8;
                    a1 = FTOFIX32(31.25);
                    a2 = 1;
                    a3 = 6;
                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        0,
                        0,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;

                case 7:
                    a0 = 16;
                    a1 = FTOFIX32(31.25);
                    a2 = 1;
                    a3 = 7;

                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        0,
                        0,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;

                case 19:
                case 20:
                case 21:
                    a0 = 0x10;
                    a1 = FTOFIX32(31.25);
                    a2 = 0;
                    a3 = cha->unk0;

                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        1,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;
                case 22:
                case 23:
                case 24:
                case 36:
                    a0 = 16;
                    a1 = FTOFIX32(31.25);
                    a2 = 0;
                    a3 = cha->unk0;

                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;
                case 25:
                case 26:
                case 27:
                    a0 = 8;
                    a1 = FTOFIX32(31.25);
                    a2 = 0;
                    a3 = cha->unk0;

                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        1,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;
                case 28:
                case 29:
                case 30:
                case 37:
                    a0 = 8;
                    a1 = FTOFIX32(31.25);
                    a2 = 0;
                    a3 = cha->unk0;

                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;
                case 9:
                    a0 = 4;
                    a1 = FTOFIX32(9.375);
                    a2 = 0;
                    a3 = 9;
                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;

                case 10:
                    a0 = 4;
                    a1 = FTOFIX32(9.375);
                    a2 = 0;
                    a3 = cha->unk0;
                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;
                case 8:
                    a0 = 0x10;
                    a1 = FTOFIX32(10.828125);
                    a2 = 0;
                    a3 = 8;
                    func_802DD090_6EE740(
                        a0,
                        a1,
                        a2,
                        a3,
                        0,
                        cha->unk2 << 0x10,
                        cha->unk4 << 0x10,
                        cha->unk6 << 0x10,
                        cha->unk18,
                        cha->unk19,
                        object2,
                        object1,
                        cha->unk10,
                        cha->unk12,
                        cha->unk14,
                        cha->unk8,
                        cha->unkA,
                        cha->unkC);
                    break;
                }
                cha++;
            }
            break;

        case 8: /* ignored */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);
            break;

        case 9: /* .map: 65x97 terrain points copied into D_803C0740[4..68][8..104] */
            func_80296544_6A7BF4();

            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            func_8029ACC8_6AC378();
            break;

        case 10: /* level geo */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            // process_level_geo()
            func_80344240_7558F0();
            break;

        case 11: /* .mat: 256 material entries; map cells index this table via unk2/unk3 */
            func_80304170_715820();

            payloadLength = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            memcpy_sssv(base, (u8*)&D_803E1D30, payloadLength);
            break;

        case 12: /* .dat: first 0xA0 bytes of LevelConfig */
            func_80304194_715844();

            payloadLength = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            memcpy_sssv(base, (u8*)&D_803F2D50, payloadLength);
            D_803F2D50.fovY = D_803F2D50.sourceFovY;
            load_level_texture_data(D_803F2D50.segment, D_803F2D50.textureBank);
            break;
        case 13: /* .cam: count followed by struct105 camera regions and struct074 camera config */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            payloadLength = base->s.count;
            payload = base->s.payload;

            bzero_sssv((u8*)&D_803A6D14_7B83C4, sizeof(D_803A6D14_7B83C4));
            bzero_sssv((u8*)&D_803A7114_7B87C4, sizeof(D_803A7114_7B87C4));

            memcpy_sssv(payload, (u8*)&D_803A6D14_7B83C4, payloadLength * sizeof(struct105));
            payload += ((payloadLength * sizeof(struct105)) >> 1);
            memcpy_sssv(payload, (u8*)&D_803A7114_7B87C4, payloadLength * sizeof(struct074));

            func_8034401C_7556CC();
            break;
        case 14: /* unknown 2048-byte table copied to D_803E2930 */
            payloadLength = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);
            memcpy_sssv(base, (u8*)&D_803E2930,  payloadLength);
            break;
        case 15: /* unknown; every svle-unpacked level seen has the same payload */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            type15EntryCount = base->s.count;
            payload = base->s.payload;

            memcpy_sssv(payload, (u8*)D_803B1D20_7C33D0, type15EntryCount * sizeof(u64));
            break;
        default:
            // unknown type
            done = 1;
            break;
        }
    } while (!done);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/load_level_data_sections.s")
#endif

void func_8031C304_72D9B4(void) {
    func_8012A400(); // receive messages, synchronization?
    func_8012AC8C();
}

void func_8031C32C_72D9DC(void) {
    // zero out framebuffer 1
    bzero_sssv(gFramebuffer[0], sizeof(gFramebuffer[0]));
    // zero out framebuffer 2
    bzero_sssv(gFramebuffer[1], sizeof(gFramebuffer[0]));
    // cancel blackout
    osViBlack(0);
}

void func_8031C374_72DA24() {
    func_8031C304_72D9B4();
    gScreenTransition.unk0 = 1;
    gScreenTransition.unk2 = 100;
    gScreenTransition.unk6 = 8;
    gScreenTransition.transitionId = 5; // square-folding transition
    D_803F2D50.entranceTeleporter = NULL; // clear entrance teleporter pointer?
}

// ESA: func_8005BE44 (tbd)
void func_8031C3C0_72DA70(u8 *arg0, s16 idx) {
    s16 i;

    memcpy_sssv(arg0, (u8*)&D_803E9840[D_803F28C2], sizeof(Collision));

    for (i = 0; i < 247; i++) {
        if (idx == D_803A8528_7B9BD8[i].collisionIndex) {
            D_803A8528_7B9BD8[i].collision = &D_803E9840[D_803F28C2];
        }
    }
    D_803F28C2++;
}

void func_8031C48C_72DB3C(void) {
    s32 offset;

    s16 i;
    s16 id2;
    s16 idx;

    if (D_803F2D50.entranceTeleporter != NULL) {
        func_8029B9B8_6AD068(gAnimalState.animals[gCurrentAnimalIndex].animal, D_803F2D50.entranceTeleporter);
    }

    load_data_section(D_803F2D50.segment);
    func_802FD8CC_70EF7C();
    reset_camera();
    func_802F2DF8_7044A8();
    func_802FE4C4_70FB74();
    reset_trails();
    func_802C85EC_6D9C9C();

    // objects
    for (i = 0; i < 170; i++) {
        if (D_801E9EB8.objects[i].commands.unk1A8 != NULL) {
            // load in commands
            func_803191B0_72A860((Entity *) &D_801E9EB8.objects[i]);
        }
    }

    // animals
    for (i = 0; i < gNumAnimalsInLevel; i++) {
        if (gAnimalState.animals[i].animal->commands.unk1A8 != NULL) {
            // load in commands
            func_803191B0_72A860((Entity *) gAnimalState.animals[i].animal);
        }
    }
    //
    for (i = 0; i < 247; i++) {
        // reset collision link
        D_803A8528_7B9BD8[i].collision = NULL;
    }

    D_803F28C2 = 0;

    osWritebackDCacheAll();
    dma_read(_model_collision_rncSegmentRomStart, D_80100000, _model_collision_rncSegmentRomEnd - _model_collision_rncSegmentRomStart);
    UnpackRNC((RNC_fileptr)D_80100000, (u8*)gFramebuffer);

    offset = 1;

    // objects
    for (i = 0; i < 170; i++) {
        if ((D_801E9EB8.objects[i].unk16C != NULL) && (D_801E9EB8.objects[i].unk26C == 0)) {
            if ((D_801E9EB8.objects[i].unk16C->collisionIdx != 0) && (D_801E9EB8.objects[i].unk16C->collision == NULL)) {
                idx = D_801E9EB8.objects[i].unk16C->collisionIdx;
                // link the collision?
                func_8031C3C0_72DA70((u8*)(((Collision*)gFramebuffer) + (idx - offset)), idx);
            }
        }
    }

    // commands
    for (i = 0; i < D_803E8E54; i++) {
        CmdWrapper *cmdWrapper = &D_803E4D40[i];

        if (cmdWrapper->type == 16) {
            id2 = cmdWrapper->cmd.type16.id;
            goto custom;
        }

        if (cmdWrapper->type == 17) {
            // object has custom collision
            id2 = cmdWrapper->cmd.type16.id;
custom:
            if ((D_803A8528_7B9BD8[id2].collisionIndex != 0) && (D_803A8528_7B9BD8[id2].collision == NULL)) {
                idx = D_803A8528_7B9BD8[id2].collisionIndex;
                func_8031C3C0_72DA70((u8*)(((Collision*)gFramebuffer) +  (idx - offset)), idx);
            }
        } else {
            // required!
        }
    }

    func_8031C32C_72D9DC();
    func_802963D0_6A7A80(gFrameContext);
}
