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

// rgba16 mipmapped textures?
u8 *D_803A5770_7B6E20[] = {
    // img_europe_mipmap_rncSegmentRomStart, img_europe_mipmap_rncSegmentRomEnd,  // europe
    _rnc_42DCA0SegmentRomStart, _rnc_42DCA0SegmentRomEnd,  // europe
    _rnc_435320SegmentRomStart, _rnc_435320SegmentRomEnd,  // ice
    _rnc_43CB60SegmentRomStart, _rnc_43CB60SegmentRomEnd,  // desert
    _rnc_4457F0SegmentRomStart, _rnc_4457F0SegmentRomEnd,  // jungle
    _empty_rnc_44E790SegmentRomStart, _empty_rnc_44E790SegmentRomEnd,  // empty
    _rnc_44E7B0SegmentRomStart, _rnc_44E7B0SegmentRomEnd,  // city / credits
};

// ia16 textures?
u8 *D_803A57A0_7B6E50[] = {
    _rnc_4571A0SegmentRomStart, _rnc_4571A0SegmentRomEnd,
    _rnc_459590SegmentRomStart, _rnc_459590SegmentRomEnd,
    _rnc_45D550SegmentRomStart, _rnc_45D550SegmentRomEnd,
    _rnc_45EDC0SegmentRomStart, _rnc_45EDC0SegmentRomEnd,
    _rnc_461900SegmentRomStart, _rnc_461900SegmentRomEnd,
    _rnc_461950SegmentRomStart, _rnc_461950SegmentRomEnd,
    //
    _rnc_461A20SegmentRomStart, _rnc_461A20SegmentRomEnd,
    _rnc_465F90SegmentRomStart, _rnc_465F90SegmentRomEnd,
    _rnc_46BA30SegmentRomStart, _rnc_46BA30SegmentRomEnd,
    _rnc_470670SegmentRomStart, _rnc_470670SegmentRomEnd,
    _rnc_474EE0SegmentRomStart, _rnc_474EE0SegmentRomEnd,
    _rnc_47A0F0SegmentRomStart, _rnc_47A0F0SegmentRomEnd,
    _rnc_47F1E0SegmentRomStart, _rnc_47F1E0SegmentRomEnd,
    _rnc_484450SegmentRomStart, _rnc_484450SegmentRomEnd,
    _rnc_488A70SegmentRomStart, _rnc_488A70SegmentRomEnd,
    _rnc_48DD20SegmentRomStart, _rnc_48DD20SegmentRomEnd,
    _rnc_4927E0SegmentRomStart, _rnc_4927E0SegmentRomEnd,
    _rnc_497B90SegmentRomStart, _rnc_497B90SegmentRomEnd,
    //
    _rnc_49C950SegmentRomStart, _rnc_49C950SegmentRomEnd,
    _rnc_4A1690SegmentRomStart, _rnc_4A1690SegmentRomEnd,
    _rnc_4A5170SegmentRomStart, _rnc_4A5170SegmentRomEnd,
    _rnc_4A97E0SegmentRomStart, _rnc_4A97E0SegmentRomEnd,
    _rnc_4AE610SegmentRomStart, _rnc_4AE610SegmentRomEnd,
    _empty_rnc_4B3440SegmentRomStart, _empty_rnc_4B3440SegmentRomEnd,
    _rnc_4B3460SegmentRomStart, _rnc_4B3460SegmentRomEnd,
    _empty_rnc_4B79A0SegmentRomStart, _empty_rnc_4B79A0SegmentRomEnd,
    _empty_rnc_4B79C0SegmentRomStart, _empty_rnc_4B79C0SegmentRomEnd,
    // desert
    _rnc_4B79E0SegmentRomStart, _rnc_4B79E0SegmentRomEnd,
    _rnc_4BC330SegmentRomStart, _rnc_4BC330SegmentRomEnd,
    _rnc_4C12C0SegmentRomStart, _rnc_4C12C0SegmentRomEnd,
    _rnc_4C4CD0SegmentRomStart, _rnc_4C4CD0SegmentRomEnd,
    _rnc_4C91B0SegmentRomStart, _rnc_4C91B0SegmentRomEnd,
    _rnc_4CD3A0SegmentRomStart, _rnc_4CD3A0SegmentRomEnd,
    _rnc_4D1770SegmentRomStart, _rnc_4D1770SegmentRomEnd,
    _rnc_4D68D0SegmentRomStart, _rnc_4D68D0SegmentRomEnd,
    _empty_rnc_4D6960SegmentRomStart, _empty_rnc_4D6960SegmentRomEnd, // empty
    _empty_rnc_4D6980SegmentRomStart, _empty_rnc_4D6980SegmentRomEnd, // empty
    _rnc_4D69A0SegmentRomStart, _rnc_4D69A0SegmentRomEnd,
    _empty_rnc_4DB210SegmentRomStart, _empty_rnc_4DB210SegmentRomEnd, // empty
    _rnc_4DB230SegmentRomStart, _rnc_4DB230SegmentRomEnd,
    _rnc_4E0B80SegmentRomStart, _rnc_4E0B80SegmentRomEnd,
    _rnc_4E57F0SegmentRomStart, _rnc_4E57F0SegmentRomEnd,
    _rnc_4EABE0SegmentRomStart, _rnc_4EABE0SegmentRomEnd,
    _rnc_4EFC40SegmentRomStart, _rnc_4EFC40SegmentRomEnd,
    _empty_rnc_4F5470SegmentRomStart, _empty_rnc_4F5470SegmentRomEnd, // empty
    _empty_rnc_4F5490SegmentRomStart, _empty_rnc_4F5490SegmentRomEnd, // empty
    _empty_rnc_4F54B0SegmentRomStart, _empty_rnc_4F54B0SegmentRomEnd, // empty
};

u8** D_803A5918_7B6FC8[4] = {
    &D_803A57A0_7B6E50[6*2],   // 0x803a57d0
    &D_803A57A0_7B6E50[17*2],  // 0x803a5828
    &D_803A57A0_7B6E50[27*2],  // 0x803a5878
    &D_803A57A0_7B6E50[37*2],  // 0x803a58c8
};

// different to ROM ordering
u8* D_803A5928_7B6FD8[90] = {
    _rnc_4F54D0SegmentRomStart, _rnc_4F54D0SegmentRomEnd,
    _rnc_4F95B0SegmentRomStart, _rnc_4F95B0SegmentRomEnd,
    _rnc_4F8010SegmentRomStart, _rnc_4F8010SegmentRomEnd,
    _rnc_4F6A70SegmentRomStart, _rnc_4F6A70SegmentRomEnd,

    _rnc_4FAF70SegmentRomStart, _rnc_4FAF70SegmentRomEnd,
    _rnc_4FC110SegmentRomStart, _rnc_4FC110SegmentRomEnd,
    _rnc_4FD1E0SegmentRomStart, _rnc_4FD1E0SegmentRomEnd,
    _rnc_4FDF70SegmentRomStart, _rnc_4FDF70SegmentRomEnd,
    _rnc_4FF2B0SegmentRomStart, _rnc_4FF2B0SegmentRomEnd,
    _rnc_500020SegmentRomStart, _rnc_500020SegmentRomEnd,
    _rnc_500050SegmentRomStart, _rnc_500050SegmentRomEnd,
    _rnc_501040SegmentRomStart, _rnc_501040SegmentRomEnd,
    _rnc_502360SegmentRomStart, _rnc_502360SegmentRomEnd,
    _rnc_503930SegmentRomStart, _rnc_503930SegmentRomEnd,
    _rnc_504E70SegmentRomStart, _rnc_504E70SegmentRomEnd,

    _rnc_505F00SegmentRomStart, _rnc_505F00SegmentRomEnd,
    _rnc_505F30SegmentRomStart, _rnc_505F30SegmentRomEnd,
    _rnc_506550SegmentRomStart, _rnc_506550SegmentRomEnd,
    _rnc_506DD0SegmentRomStart, _rnc_506DD0SegmentRomEnd,
    _rnc_507F00SegmentRomStart, _rnc_507F00SegmentRomEnd,
    _rnc_507F30SegmentRomStart, _rnc_507F30SegmentRomEnd,
    _rnc_507F60SegmentRomStart, _rnc_507F60SegmentRomEnd,
    _rnc_507F90SegmentRomStart, _rnc_507F90SegmentRomEnd,
    _rnc_507FC0SegmentRomStart, _rnc_507FC0SegmentRomEnd,
    _rnc_509220SegmentRomStart, _rnc_509220SegmentRomEnd,

    _rnc_509250SegmentRomStart, _rnc_509250SegmentRomEnd,
    _rnc_50A4A0SegmentRomStart, _rnc_50A4A0SegmentRomEnd,
    _rnc_50A4D0SegmentRomStart, _rnc_50A4D0SegmentRomEnd,
    _rnc_50BDB0SegmentRomStart, _rnc_50BDB0SegmentRomEnd,
    _rnc_50D230SegmentRomStart, _rnc_50D230SegmentRomEnd,
    _rnc_50ECD0SegmentRomStart, _rnc_50ECD0SegmentRomEnd,
    _rnc_5106E0SegmentRomStart, _rnc_5106E0SegmentRomEnd,
    _rnc_512240SegmentRomStart, _rnc_512240SegmentRomEnd,
    _rnc_512270SegmentRomStart, _rnc_512270SegmentRomEnd,
    _rnc_5122A0SegmentRomStart, _rnc_5122A0SegmentRomEnd,

    _rnc_5122D0SegmentRomStart, _rnc_5122D0SegmentRomEnd,
    _rnc_5137C0SegmentRomStart, _rnc_5137C0SegmentRomEnd,
    _rnc_514CB0SegmentRomStart, _rnc_514CB0SegmentRomEnd,
    _rnc_515730SegmentRomStart, _rnc_515730SegmentRomEnd,
    _rnc_516C20SegmentRomStart, _rnc_516C20SegmentRomEnd,
    _rnc_518110SegmentRomStart, _rnc_518110SegmentRomEnd,
    _rnc_519600SegmentRomStart, _rnc_519600SegmentRomEnd,
    _rnc_51AAF0SegmentRomStart, _rnc_51AAF0SegmentRomEnd,
    _rnc_51AB20SegmentRomStart, _rnc_51AB20SegmentRomEnd,
    _rnc_51AB50SegmentRomStart, _rnc_51AB50SegmentRomEnd,
};

u8** D_803A5A90_7B7140[4] = {
    &D_803A5928_7B6FD8[4*2],  // 0x803A5948,
    &D_803A5928_7B6FD8[15*2], // 0x803A59A0,
    &D_803A5928_7B6FD8[35*2], // 0x803A5A40,
    &D_803A5928_7B6FD8[25*2], // 0x803A59F0,
};

// level objects
u8* D_803A5AA0_7B7150[(10+1+10+10+10)*2] = {
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

u8** D_803A5BE8_7B7298[4] = {
    &D_803A5AA0_7B7150[0*2],  // europe
    &D_803A5AA0_7B7150[11*2], // ice
    &D_803A5AA0_7B7150[31*2], // desert
    &D_803A5AA0_7B7150[21*2], // jungle
};

// levels
u8 *D_803A5BF8_7B72A8[72] = {
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
// .bss
// ========================================================

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
        UnpackRNC(src, dst);
    } else {
        // swap endianness
        memcpy_sssv(src + 4, dst, src[3] | (src[2] << 8) | (src[1] << 16) | (src[0] << 24));
    }
    return 1;
}

void load_level_texture_data(u8 bank, u8 arg1) {
    u8 **temp_v0;

    s32 pad[2];

    u8 **sp38;
    u8 **sp34;
    u8 **sp30;

    u8 var_v0;
    u8 var_t0;

    var_v0 = bank;
    var_t0 = bank;

    if (bank == 4) {
        var_v0 = bank = 5; // handle BIG_CELEBRATION_PARADE/CREDITS
    }

    if ((bank == 4) || (bank == 5)) {
        var_t0 = bank = 0;
    }

    osSyncPrintf("Bank - %d Texture - %d\n", bank, var_v0);

    arg1 -= 1; // level index?

    // load rgba16 mipmapped textures
    temp_v0 = &D_803A5770_7B6E20[(var_v0 + var_v0) & 0xFFFF];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800BA760);

    // load ia16 textures
    temp_v0 = &D_803A57A0_7B6E50[(var_v0 + var_v0) & 0xFFFF];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800CFE60);

    // load biome textures (?)
    temp_v0 = &D_803A5928_7B6FD8[(var_t0 + var_t0) & 0xFFFF];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800D7C20);

    // load level ia16 textures
    sp38 = D_803A5918_7B6FC8[bank];
    // load level textures
    sp34 = D_803A5A90_7B7140[bank];
    // load level objects
    sp30 = D_803A5BE8_7B7298[bank];

    temp_v0 = sp38;
    temp_v0 += (arg1 + arg1) & 0xFFFF;
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800C7DC0);

    temp_v0 = sp34;
    temp_v0 += (arg1 + arg1) & 0xFFFF;
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800D5420);

    D_801D9E78 = D_800B0B20;

    temp_v0 = sp30;
    temp_v0 += (arg1 + arg1) & 0xFFFF;
    dma_read(temp_v0[0], D_801D9E78, temp_v0[1] - temp_v0[0]);
}

void load_level_data(u8 level) {
    u8 **rom_addr;
    s32 len;

    func_8031C374_72DA24();

    // 0-indexed so subtract 1
    level = level - 1;

    rom_addr = &D_803A5BF8_7B72A8[level+level];
    len = rom_addr[1] - rom_addr[0];

    dma_read(rom_addr[0], &D_80100000, len);
    load_level_data_sections();
    func_8031C48C_72DB3C();
}

#ifdef NON_MATCHING
void load_level_data_sections(void) {
    struct071 *obj;
    struct071 *child;
    struct071 *parent;
    struct071 *object1;
    struct071 *object2;

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
    s16 length3;
    u16 sp7A;
    s16 *payload;

    s32 length_s32;
    s32 payloadType;

    u16 pafBytesUsed;
    u8 *paf;
    u8 *paf2;

    DataSection *base;

    s16 length2;

    base = &D_80100000;

    copy_or_extract(base, gFramebuffer, 0x25800);
    buf = gFramebuffer;

    sp7A = gNumAnimalsInLevel; // animals in level
    done = 0;

    do {
        payloadType = *buf++;

        switch (payloadType) {
        case 0: /* .cob */
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
                        (Animal *) obj,
                        &D_803E4D40[cob->commandReferenceIdx] - 1,
                        cob->commandsLength);
                }
                obj->cmdIndex = cob->unk12;
                cob++;
            }
            break;

        case 1: /* .can */
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

                obj = D_801D9ED8.animals[gNumAnimalsInLevel - 1].animal;

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

        case 2: /* .joi */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = base->s.count;
            joi = (struct092*) base->s.payload;

            while (length-- > 0) {
                if (joi->parent >= 1000) {
                    parent = D_801D9ED8.animals[(joi->parent - 1000) + sp7A].animal;
                } else {
                    parent = func_802C93E8_6DAA98(joi->parent);
                }
                if (joi->child >= 1000) {
                    child = D_801D9ED8.animals[(joi->child - 1000) + sp7A].animal;
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
            length_s32 = sizeof(CmdWrapper);

            func_80314788_725E38(); // zero out D_803E4D40 amongst other things
            memcpy_sssv(base->s.payload, (u8*)D_803E4D40, count);

            D_803E8E54 = count / (u32)length_s32; // gNumCommands
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

            length3 = base->u.count;

            memcpy_sssv(base->s.payload, (u8*)&D_803E93B0, length3 * sizeof(struct067));

            D_803E93B0[length3].unk2 = 245;
            D_803E93B0[length3].unk5 = 245;

            func_803198B0_72AF60();
            break;

        case 6: /* .paf */
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

        case 7: /* .cha */
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

        case 9: /* level collision */
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

        case 11: /* .mat */
            func_80304170_715820();

            length_s32 = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            memcpy_sssv(base, (u8*)&D_803E1D30, length_s32);
            break;

        case 12: /* .dat */
            func_80304194_715844();

            length_s32 = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            memcpy_sssv(base, (u8*)&D_803F2D50, length_s32);
            D_803F2D50.fovY = D_803F2D50.unk40;
            load_level_texture_data(D_803F2D50.segment, D_803F2D50.unk52);
            break;
        case 13: /* .cam */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length_s32 = base->s.count;
            payload = base->s.payload;

            bzero_sssv((u8*)&D_803A6D14_7B83C4, sizeof(D_803A6D14_7B83C4));
            bzero_sssv((u8*)&D_803A7114_7B87C4, sizeof(D_803A7114_7B87C4));

            memcpy_sssv(payload, (u8*)&D_803A6D14_7B83C4, length_s32 * sizeof(struct105));
            payload += ((length_s32 * sizeof(struct105)) >> 1);
            memcpy_sssv(payload, (u8*)&D_803A7114_7B87C4, length_s32 * sizeof(struct074));

            func_8034401C_7556CC();
            break;
        case 14: /* tbd */
            length_s32 = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);
            memcpy_sssv(base, (u8*)&D_803E2930,  length_s32);
            break;
        case 15: /* tbd */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length2 = base->s.count;
            payload = base->s.payload;

            memcpy_sssv(payload, (u8*)D_803B1D20_7C33D0, length2 * sizeof(u64));
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
    D_803E1B10.unk0 = 1;
    D_803E1B10.unk2 = 100;
    D_803E1B10.unk6 = 8;
    D_803E1B10.transitionId = 5; // square-folding transition
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
    int offset;

    s16 i;
    s16 id2;
    s16 idx;

    if (D_803F2D50.entranceTeleporter != NULL) {
        func_8029B9B8_6AD068(D_801D9ED8.animals[gCurrentAnimalIndex].animal, D_803F2D50.entranceTeleporter);
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
        if (D_801E9EB8.objects[i].unk1A8 != 0) {
            // load in commands
            func_803191B0_72A860((Animal *) &D_801E9EB8.objects[i]);
        }
    }

    // animals
    for (i = 0; i < gNumAnimalsInLevel; i++) {
        if (D_801D9ED8.animals[i].animal->commands.unk1A8 != NULL) {
            // load in commands
            func_803191B0_72A860(D_801D9ED8.animals[i].animal);
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
    UnpackRNC(D_80100000, gFramebuffer);

    offset = 1;

    // objects
    for (i = 0; i < 170; i++) {
        if ((D_801E9EB8.objects[i].unk16C != NULL) && (D_801E9EB8.objects[i].unk26C == 0)) {
            if ((D_801E9EB8.objects[i].unk16C->id != 0) && (D_801E9EB8.objects[i].unk16C->collision == NULL)) {
                idx = D_801E9EB8.objects[i].unk16C->id;
                // link the collision?
                func_8031C3C0_72DA70(((Collision*)gFramebuffer) + (idx - offset), idx);
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
                func_8031C3C0_72DA70(((Collision*)gFramebuffer) +  (idx - offset), idx);
            }
        } else {
            // required!
        }
    }

    func_8031C32C_72D9DC();
    func_802963D0_6A7A80((s32) D_80162658);
}
