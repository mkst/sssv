#include <ultra64.h>
#include "common.h"
#include "pp.h"


// rgba16 mipmapped textures?
struct066 D_803A5770_7B6E20[] = {
    { rnc_42DCA0_ROM_START, rnc_42DCA0_ROM_END, }, // europe
    { rnc_435320_ROM_START, rnc_435320_ROM_END, }, // ice
    { rnc_43CB60_ROM_START, rnc_43CB60_ROM_END, }, // desert
    { rnc_4457F0_ROM_START, rnc_4457F0_ROM_END, }, // jungle
    { empty_rnc_44E790_ROM_START, empty_rnc_44E790_ROM_END, }, // empty
    { rnc_44E7B0_ROM_START, rnc_44E7B0_ROM_END, }, // city / credits
};

// ia16 textures?
struct066 D_803A57A0_7B6E50[] = {
    { rnc_4571A0_ROM_START, rnc_4571A0_ROM_END, },
    { rnc_459590_ROM_START, rnc_459590_ROM_END, },
    { rnc_45D550_ROM_START, rnc_45D550_ROM_END, },
    { rnc_45EDC0_ROM_START, rnc_45EDC0_ROM_END, },
    { rnc_461900_ROM_START, rnc_461900_ROM_END, },
    { rnc_461950_ROM_START, rnc_461950_ROM_END, },
    //
    { rnc_461A20_ROM_START, rnc_461A20_ROM_END, },
    { rnc_465F90_ROM_START, rnc_465F90_ROM_END, },
    { rnc_46BA30_ROM_START, rnc_46BA30_ROM_END, },
    { rnc_470670_ROM_START, rnc_470670_ROM_END, },
    { rnc_474EE0_ROM_START, rnc_474EE0_ROM_END, },
    { rnc_47A0F0_ROM_START, rnc_47A0F0_ROM_END, },
    { rnc_47F1E0_ROM_START, rnc_47F1E0_ROM_END, },
    { rnc_484450_ROM_START, rnc_484450_ROM_END, },
    { rnc_488A70_ROM_START, rnc_488A70_ROM_END, },
    { rnc_48DD20_ROM_START, rnc_48DD20_ROM_END, },
    { rnc_4927E0_ROM_START, rnc_4927E0_ROM_END, },
    { rnc_497B90_ROM_START, rnc_497B90_ROM_END, },
    //
    { rnc_49C950_ROM_START, rnc_49C950_ROM_END, },
    { rnc_4A1690_ROM_START, rnc_4A1690_ROM_END, },
    { rnc_4A5170_ROM_START, rnc_4A5170_ROM_END, },
    { rnc_4A97E0_ROM_START, rnc_4A97E0_ROM_END, },
    { rnc_4AE610_ROM_START, rnc_4AE610_ROM_END, },
    { empty_rnc_4B3440_ROM_START, empty_rnc_4B3440_ROM_END, },
    { rnc_4B3460_ROM_START, rnc_4B3460_ROM_END, },
    { empty_rnc_4B79A0_ROM_START, empty_rnc_4B79A0_ROM_END, },
    { empty_rnc_4B79C0_ROM_START, empty_rnc_4B79C0_ROM_END, },
    // desert
    { rnc_4B79E0_ROM_START, rnc_4B79E0_ROM_END, },
    { rnc_4BC330_ROM_START, rnc_4BC330_ROM_END, },
    { rnc_4C12C0_ROM_START, rnc_4C12C0_ROM_END, },
    { rnc_4C4CD0_ROM_START, rnc_4C4CD0_ROM_END, },
    { rnc_4C91B0_ROM_START, rnc_4C91B0_ROM_END, },
    { rnc_4CD3A0_ROM_START, rnc_4CD3A0_ROM_END, },
    { rnc_4D1770_ROM_START, rnc_4D1770_ROM_END, },
    { rnc_4D68D0_ROM_START, rnc_4D68D0_ROM_END, },
    { empty_rnc_4D6960_ROM_START, empty_rnc_4D6960_ROM_END, }, // empty
    { empty_rnc_4D6980_ROM_START, empty_rnc_4D6980_ROM_END, }, // empty
    { rnc_4D69A0_ROM_START, rnc_4D69A0_ROM_END, },
    { empty_rnc_4DB210_ROM_START, empty_rnc_4DB210_ROM_END, }, // empty
    { rnc_4DB230_ROM_START, rnc_4DB230_ROM_END, },
    { rnc_4E0B80_ROM_START, rnc_4E0B80_ROM_END, },
    { rnc_4E57F0_ROM_START, rnc_4E57F0_ROM_END, },
    { rnc_4EABE0_ROM_START, rnc_4EABE0_ROM_END, },
    { rnc_4EFC40_ROM_START, rnc_4EFC40_ROM_END, },
    { empty_rnc_4F5470_ROM_START, empty_rnc_4F5470_ROM_END, }, // empty
    { empty_rnc_4F5490_ROM_START, empty_rnc_4F5490_ROM_END, }, // empty
    { empty_rnc_4F54B0_ROM_START, empty_rnc_4F54B0_ROM_END, }, // empty
};

struct066* D_803A5918_7B6FC8[4] = {
    &D_803A57A0_7B6E50[6],   // 0x803a57d0
    &D_803A57A0_7B6E50[17],  // 0x803a5828
    &D_803A57A0_7B6E50[27],  // 0x803a5878
    &D_803A57A0_7B6E50[37],  // 0x803a58c8
};

// different to ROM ordering
u8* D_803A5928_7B6FD8[45][2] = {
    { rnc_4F54D0_ROM_START, rnc_4F54D0_ROM_END, },
    { rnc_4F95B0_ROM_START, rnc_4F95B0_ROM_END, },
    { rnc_4F8010_ROM_START, rnc_4F8010_ROM_END, },
    { rnc_4F6A70_ROM_START, rnc_4F6A70_ROM_END, },
    { rnc_4FAF70_ROM_START, rnc_4FAF70_ROM_END, },
    { rnc_4FC110_ROM_START, rnc_4FC110_ROM_END, },
    { rnc_4FD1E0_ROM_START, rnc_4FD1E0_ROM_END, },
    { rnc_4FDF70_ROM_START, rnc_4FDF70_ROM_END, },
    { rnc_4FF2B0_ROM_START, rnc_4FF2B0_ROM_END, },
    { rnc_500020_ROM_START, rnc_500020_ROM_END, },
    { rnc_500050_ROM_START, rnc_500050_ROM_END, },
    { rnc_501040_ROM_START, rnc_501040_ROM_END, },
    { rnc_502360_ROM_START, rnc_502360_ROM_END, },
    { rnc_503930_ROM_START, rnc_503930_ROM_END, },
    { rnc_504E70_ROM_START, rnc_504E70_ROM_END, },
    { rnc_505F00_ROM_START, rnc_505F00_ROM_END, },
    { rnc_505F30_ROM_START, rnc_505F30_ROM_END, },
    { rnc_506550_ROM_START, rnc_506550_ROM_END, },
    { rnc_506DD0_ROM_START, rnc_506DD0_ROM_END, },
    { rnc_507F00_ROM_START, rnc_507F00_ROM_END, },
    { rnc_507F30_ROM_START, rnc_507F30_ROM_END, },
    { rnc_507F60_ROM_START, rnc_507F60_ROM_END, },
    { rnc_507F90_ROM_START, rnc_507F90_ROM_END, },
    { rnc_507FC0_ROM_START, rnc_507FC0_ROM_END, },
    { rnc_509220_ROM_START, rnc_509220_ROM_END, },
    { rnc_509250_ROM_START, rnc_509250_ROM_END, },
    { rnc_50A4A0_ROM_START, rnc_50A4A0_ROM_END, },
    { rnc_50A4D0_ROM_START, rnc_50A4D0_ROM_END, },
    { rnc_50BDB0_ROM_START, rnc_50BDB0_ROM_END, },
    { rnc_50D230_ROM_START, rnc_50D230_ROM_END, },
    { rnc_50ECD0_ROM_START, rnc_50ECD0_ROM_END, },
    { rnc_5106E0_ROM_START, rnc_5106E0_ROM_END, },
    { rnc_512240_ROM_START, rnc_512240_ROM_END, },
    { rnc_512270_ROM_START, rnc_512270_ROM_END, },
    { rnc_5122A0_ROM_START, rnc_5122A0_ROM_END, },
    { rnc_5122D0_ROM_START, rnc_5122D0_ROM_END, },
    { rnc_5137C0_ROM_START, rnc_5137C0_ROM_END, },
    { rnc_514CB0_ROM_START, rnc_514CB0_ROM_END, },
    { rnc_515730_ROM_START, rnc_515730_ROM_END, },
    { rnc_516C20_ROM_START, rnc_516C20_ROM_END, },
    { rnc_518110_ROM_START, rnc_518110_ROM_END, },
    { rnc_519600_ROM_START, rnc_519600_ROM_END, },
    { rnc_51AAF0_ROM_START, rnc_51AAF0_ROM_END, },
    { rnc_51AB20_ROM_START, rnc_51AB20_ROM_END, },
    { rnc_51AB50_ROM_START, rnc_51AB50_ROM_END, },
};

u8* D_803A5A90_7B7140[4] = {
    D_803A5928_7B6FD8[4],  // 0x803A5948,
    D_803A5928_7B6FD8[15], // 0x803A59A0,
    D_803A5928_7B6FD8[35], // 0x803A5A40,
    D_803A5928_7B6FD8[25], // 0x803A59F0,
};

// level objects
u8* D_803A5AA0_7B7150[41][2] = {
    // europe
    { HAVE_A_NICE_DAY_ROM_START, HAVE_A_NICE_DAY_ROM_END, },
    { HONEYMOON_LAGOON_ROM_START, HONEYMOON_LAGOON_ROM_END, },
    { SMASHING_START_ROM_START, SMASHING_START_ROM_END, },
    { THE_BATTERY_FARM_ROM_START, THE_BATTERY_FARM_ROM_END, },
    { GIVE_A_DOG_A_BONUS_ROM_START, GIVE_A_DOG_A_BONUS_ROM_END, },
    { DMA_INTRO_ROM_START, DMA_INTRO_ROM_END, },
    { STINKY_SEWERS_ROM_START, STINKY_SEWERS_ROM_END, },
    { RAT_O_MATIC_ROM_START, RAT_O_MATIC_ROM_END, },
    { ROCKY_HARD_PLACE_ROM_START, ROCKY_HARD_PLACE_ROM_END, },
    { data_A10C0_ROM_START, data_A10C0_ROM_END, }, // empty
    // final
    { BIG_CELEBRATION_PARADE_ROM_START, BIG_CELEBRATION_PARADE_ROM_END, },
    // ice
    { SOMETHING_FISHY_ROM_START, SOMETHING_FISHY_ROM_END, },
    { HOPPA_CHOPPA_ROM_START, HOPPA_CHOPPA_ROM_END, },
    { PENGUIN_PLAYPEN_ROM_START, PENGUIN_PLAYPEN_ROM_END, },
    { WALRACE_64_ROM_START, WALRACE_64_ROM_END, },
    { data_B3D70_ROM_START, data_B3D70_ROM_END, }, // empty
    { data_B3D80_ROM_START, data_B3D80_ROM_END, }, // empty
    { data_B3D90_ROM_START, data_B3D90_ROM_END, }, // empty
    { data_B3DA0_ROM_START, data_B3DA0_ROM_END, }, // empty
    { data_B3DB0_ROM_START, data_B3DB0_ROM_END, }, // empty
    { data_B3DC0_ROM_START, data_B3DC0_ROM_END, }, // empty
    // jungle
    { WEIGHT_FOR_IT_ROM_START, WEIGHT_FOR_IT_ROM_END, },
    { data_B40C0_ROM_START, data_B40C0_ROM_END, },
    { JUNGLE_JUMPS_ROM_START, JUNGLE_JUMPS_ROM_END, },
    { JUNGLE_JAPES_ROM_START, JUNGLE_JAPES_ROM_END, }, // JUNGLE_JAPES ?
    { data_B48C0_ROM_START, data_B48C0_ROM_END, },
    { EVOS_ESCAPE_ROM_START, EVOS_ESCAPE_ROM_END, }, // EVOS_ESCAPE
    { data_BD090_ROM_START, data_BD090_ROM_END, },
    { data_BD0A0_ROM_START, data_BD0A0_ROM_END, },
    { data_BD0B0_ROM_START, data_BD0B0_ROM_END, },
    { data_BD0C0_ROM_START, data_BD0C0_ROM_END, },
    // desert
    { data_BD0D0_ROM_START, data_BD0D0_ROM_END, },
    { HOT_CROSS_BUNS_ROM_START, HOT_CROSS_BUNS_ROM_END, },
    { PUNCHUP_PYRAMID_ROM_START, PUNCHUP_PYRAMID_ROM_END, },
    { data_C4500_ROM_START, data_C4500_ROM_END, },
    { data_C4510_ROM_START, data_C4510_ROM_END, },
    { data_C47A0_ROM_START, data_C47A0_ROM_END, },
    { data_C47B0_ROM_START, data_C47B0_ROM_END, },
    { data_C7A00_ROM_START, data_C7A00_ROM_END, },
    { data_C7A10_ROM_START, data_C7A10_ROM_END, },
    { data_C7A20_ROM_START, data_C7A20_ROM_END, },
};

u8* D_803A5BE8_7B7298[4] = {
    &D_803A5AA0_7B7150[0],  // 0x803A5AA0, europe
    &D_803A5AA0_7B7150[11], // 0x803A5AF8, ice
    &D_803A5AA0_7B7150[31], // 0x803A5B98, desert
    &D_803A5AA0_7B7150[21], // 0x803A5B48, jungle
};

// levels
struct066 D_803A5BF8_7B72A8[36] = {
    { levels_SMASHING_START_ROM_START, levels_SMASHING_START_ROM_END },
    { levels_HAVE_A_NICE_DAY_ROM_START, levels_HAVE_A_NICE_DAY_ROM_END },
    { levels_HONEYMOON_LAGOON_ROM_START, levels_HONEYMOON_LAGOON_ROM_END },
    { levels_THE_BATTERY_FARM_ROM_START, levels_THE_BATTERY_FARM_ROM_END },
    { levels_THE_ENGINE_ROOM_ROM_START, levels_THE_ENGINE_ROOM_ROM_END },
    { levels_FAT_BEAR_MOUNTAIN_ROM_START, levels_FAT_BEAR_MOUNTAIN_ROM_END },
    { levels_ROCKY_HARD_PLACE_ROM_START, levels_ROCKY_HARD_PLACE_ROM_END },
    { levels_STINKY_SEWERS_ROM_START, levels_STINKY_SEWERS_ROM_END },
    { levels_RAT_O_MATIC_ROM_START, levels_RAT_O_MATIC_ROM_END },
    { levels_GIVE_A_DOG_A_BONUS_ROM_START, levels_GIVE_A_DOG_A_BONUS_ROM_END },

    { levels_SNOW_JOKE_ROM_START, levels_SNOW_JOKE_ROM_END },
    { levels_ICE_N_EASY_DOES_IT_ROM_START, levels_ICE_N_EASY_DOES_IT_ROM_END },
    { levels_PENGUIN_PLAYPEN_ROM_START, levels_PENGUIN_PLAYPEN_ROM_END },
    { levels_PINBALL_BLIZZARD_ROM_START, levels_PINBALL_BLIZZARD_ROM_END },
    { levels_HOPPA_CHOPPA_ROM_START, levels_HOPPA_CHOPPA_ROM_END },
    { levels_SOMETHING_FISHY_ROM_START, levels_SOMETHING_FISHY_ROM_END },
    { levels_WALRACE_64_ROM_START, levels_WALRACE_64_ROM_END },

    { levels_JUNGLE_JAPES_ROM_START, levels_JUNGLE_JAPES_ROM_END },
    { levels_JUNGLE_DOLDRUMS_ROM_START, levels_JUNGLE_DOLDRUMS_ROM_END },
    { levels_SWAMP_OF_ETERNAL_STENCH_ROM_START, levels_SWAMP_OF_ETERNAL_STENCH_ROM_END },
    { levels_WEIGHT_FOR_IT_ROM_START, levels_WEIGHT_FOR_IT_ROM_END },
    { levels_JUNGLE_JUMPS_ROM_START, levels_JUNGLE_JUMPS_ROM_END },
    { levels_EVOS_ESCAPE_ROM_START, levels_EVOS_ESCAPE_ROM_END },

    { levels_FUN_IN_THE_SUN_ROM_START, levels_FUN_IN_THE_SUN_ROM_END },
    { levels_HOT_CROSS_BUNS_ROM_START, levels_HOT_CROSS_BUNS_ROM_END },
    { levels_STING_IN_THE_TAIL_ROM_START, levels_STING_IN_THE_TAIL_ROM_END },
    { levels_BORASSIC_PARK_ROM_START, levels_BORASSIC_PARK_ROM_END },
    { levels_WHIRLWIND_TOUR_ROM_START, levels_WHIRLWIND_TOUR_ROM_END },
    { levels_SHIFTING_SANDS_ROM_START, levels_SHIFTING_SANDS_ROM_END },
    { levels_PUNCHUP_PYRAMID_ROM_START, levels_PUNCHUP_PYRAMID_ROM_END },

    { levels_BIG_CELEBRATION_PARADE_ROM_START, levels_BIG_CELEBRATION_PARADE_ROM_END },

    { levels_rnc_60E920_ROM_START, levels_rnc_60E920_ROM_END },
    { levels_rnc_60FFD0_ROM_START, levels_rnc_60FFD0_ROM_END },
    { levels_rnc_6104A0_ROM_START, levels_rnc_6104A0_ROM_END },
    { levels_rnc_6109D0_ROM_START, levels_rnc_6109D0_ROM_END },

    { levels_INTRO_ROM_START, levels_INTRO_ROM_END }
};

s32 get_uncompressed_size(u8 *arg0) {
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
        memcpy_sssv(src + 4, dst, src[3] | (src[2] << 8) | (src[1] << 16) | (src[0] << 24));
    }
    return 1;
}

// extern u32 D_803A5770_7B6E20[][2];
// extern u32 D_803A57A0_7B6E50[][2];
// extern u32 D_803A5928_7B6FD8[][2];
//
// extern char D_803BD880_7CEF30[];
//
// extern u8 D_800CFE60[];
// extern u8 D_800D7C20[];

// load_texture_bank()
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B174_72C824.s")
#if 0
// so much to figure out here
void func_8031B174_72C824(u8 arg0, u8 arg1) {
    s32 sp34;
    s32 sp30;
    u8 sp2E;
    s32 sp28;
    s32 sp24;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_s1;
    s32 temp_t1;
    s32 temp_v0_3;
    s32 temp_v1;
    struct066 *temp_a3;
    void *temp_v0;
    void *temp_v0_2;
    struct066 *temp_v0_4;
    struct066 *temp_v0_5;
    void *temp_v1_2;
    s32 bank;
    s32 texture;
    u8 phi_t0;
    s32 bank_2;
    s32 phi_s1;

    // D_800BA760->unk1ACC0 == D_800D5420
    // D_800BA760->unk1D4C0 == D_800D7C20

    // temp_s1 = arg0 & 0xFF;
    bank = arg0 & 0xFF;
    texture = arg0 & 0xFF;
    phi_t0 = arg0 & 0xFF;
    phi_s1 = arg0;
    if (arg0 == 4) {
        bank = 5;
        texture = 5;
        phi_s1 = 5;
    }

    if ((bank == 4) || (bank == 5)) {
        phi_t0 = 0;
        bank = 0;
        phi_s1 = 0;
    }
    sp24 = texture;
    sp2E = phi_t0;

    // "Bank - %d Texture - %d\n" &D_803BD880_7CEF30
    rmonPrintf("Bank - %d Texture - %d\n", bank, texture);
    // temp_v1 = ((sp24 * 2) & 0xFFFF) * 4;
    // temp_v0 = temp_v1 + &D_803A5770_7B6E20;
    // temp_a0 = temp_v0->unk0;
    arg1 += -1;
    // sp28 = temp_v1;
    dma_read(D_803A5770_7B6E20[texture].start, &D_80100000, D_803A5770_7B6E20[texture].end - D_803A5770_7B6E20[texture].start);
    UnpackRNC(&D_80100000, &D_800BA760);

    // difference is 0x15700

    // temp_v0_2 = sp28 + &D_803A57A0_7B6E50;
    // temp_a0_2 = temp_v0_2->unk0;
    dma_read(D_803A57A0_7B6E50[texture].start, &D_80100000, D_803A57A0_7B6E50[texture].end - D_803A57A0_7B6E50[texture].start);
    UnpackRNC(&D_80100000, &D_800CFE60);

    // difference is 0x7dc0
    // temp_v1_2 = (((sp2E * 2) & 0xFFFF) * 4) + &D_803A5928_7B6FD8;
    // temp_a0_3 = temp_v1_2->unk0;
    dma_read(D_803A5928_7B6FD8[bank][0], &D_80100000, D_803A5928_7B6FD8[bank][1] - D_803A5928_7B6FD8[bank][0]);
    UnpackRNC(&D_80100000, &D_800D7C20);
#if 0
    temp_v0_3 = phi_s1 * 4;
    // temp_t1 = ((arg1 * 2) & 0xFFFF) * 4;
    temp_a3 = *(&D_803A5918_7B6FC8[bank]; // + temp_v0_3) + ((arg1 * 2) & 0xFFFF) * 4;
    sp34 = *(&D_803A5A90_7B7140[bank]; // + temp_v0_3);
    sp30 = *(&D_803A5BE8_7B7298[bank]; // + temp_v0_3);
    temp_a0_4 = temp_a3->start;
    sp28 = ((arg1 * 2) & 0xFFFF) * 4;
    dma_read(temp_a0_4, &D_80100000, temp_a3->end - temp_a0_4);
    UnpackRNC(&D_80100000, &D_800C7DC0);
    temp_v0_4 = sp34 + sp28;
    temp_a0_5 = temp_v0_4->start;
    dma_read(temp_a0_5, &D_80100000, temp_v0_4->end - temp_a0_5);
    UnpackRNC(&D_80100000, &D_800D5420);
    D_801D9E78 = &D_800B0B20;
    temp_v0_5 = sp30 + sp28;
    temp_a0_6 = temp_v0_5->start;
    dma_read(temp_a0_6, &D_800B0B20, temp_v0_5->end - temp_a0_6);
#endif
}
#endif

#ifdef NON_MATCHING
void load_level_data(u8 level) {
    func_8031C374_72DA24();
    // 0-indexed so subtract 1
    level = level - 1;

    // FIXME: the s16 cast is wrong but adds enough asm to avoid shifting
    dma_read(
        D_803A5BF8_7B72A8[(s16)level].start,
        &D_80100000,
        D_803A5BF8_7B72A8[(s16)level].end - D_803A5BF8_7B72A8[(s16)level].start);
    func_8031B400_72CAB0();
    func_8031C48C_72DB3C();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/load_level_data.s")
#endif

// load all level data sections
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B400_72CAB0.s")

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
    D_803F2D50.unkBC = NULL;
}

void func_8031C3C0_72DA70(u8 *arg0, s16 id) {
    s16 i;

    memcpy_sssv(arg0, (u8*)&D_803E9840[D_803F28C2], sizeof(Particle));

    for (i = 0; i < 247; i++) {
        if (id == D_803A8528_7B9BD8[i].unk1C) {
            // link particle?
            D_803A8528_7B9BD8[i].unk18 = &D_803E9840[D_803F28C2];
        }
    }
    D_803F28C2 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031C48C_72DB3C.s")
// void func_8031C48C_72DB3C(void) {
//
//     struct071 *temp_v0;
//     struct068 *temp_v0_6;
//     struct035 *tmp;
//     s16 i;
//
//     if (D_803F2D50.unkBC != 0) {
//         func_8029B9B8_6AD068(D_801D9ED8.animals[gCurrentAnimalIndex].animal, D_803F2D50.unkBC);
//     }
//
//     load_data_section(D_803F2D50.segment);
//     func_802FD8CC_70EF7C();
//     func_8033C334_74D9E4();
//     func_802F2DF8_7044A8();
//     func_802FE4C4_70FB74();
//     func_8039DD60_7AF410(); // reset used objects, zero out memory
//     func_802C85EC_6D9C9C();
//
//     // all game objects
//     for (i = 0; i < 170; i++) {
//         if (D_801E9EB8.unk4[i].unk1A8 != 0) {
//             func_803191B0_72A860(&D_801E9EB8.unk4[i]);
//         }
//     }
//
//     // animals in level
//     for (i = 0; i < D_803D553E; i++) {
//         if (D_801D9ED8.animals[i].animal->unk1A8 != 0) {
//             func_803191B0_72A860(D_801D9ED8.animals[i].animal);
//         }
//     }
//
//     for (i = 0; i < 247; i++) {
//         D_803A8528_7B9BD8[i].unk18 = 0; // null them out
//     }
//
//     D_803F28C2 = 0;
//     osWritebackDCacheAll();
//     // load a bunch of particles?
//     dma_read(rnc_637160_ROM_START, &D_80100000, rnc_637160_ROM_START - rnc_637160_ROM_START);
//     UnpackRNC(&D_80100000, gFramebuffer);
//
//     // starts falling apart around here...
//     for (i = 0; i < 170; i++) {
//         tmp = D_801E9EB8.unk4[i].unk16C;
//         if ((tmp != NULL) && (D_801E9EB8.unk4[i].unk26C == 0)) {
//             if ((tmp->unk1C != 0) && (tmp->unk18 == 0)) {
//                 func_8031C3C0_72DA70(&((Particle*)gFramebuffer)[(s16)tmp->unk1C - 1], tmp->unk1C);
//             }
//         }
//     }
//
//     // particles
//     for (i = 0; i < D_803E8E54; i++) {
//         if ((D_803E4D40[i].type == 16) || (D_803E4D40[i].type == 17)) {
//             s16 id = D_803E4D40[i].id;
//             if ((D_803A8528_7B9BD8[id].unk1C != 0) && (D_803A8528_7B9BD8[id].unk18 == NULL)) {
//                 func_8031C3C0_72DA70(&((Particle*)gFramebuffer)[(s16)D_803A8528_7B9BD8[id].unk1C - 1], D_803A8528_7B9BD8[id].unk1C);
//             }
//         }
//     }
//
//     func_8031C32C_72D9DC();
//     func_802963D0_6A7A80(&D_80162658);
// }
