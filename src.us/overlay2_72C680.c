#include <ultra64.h>
#include "common.h"
#include "pp.h"


extern u8 rnc_637160_ROM_START[], rnc_637160_ROM_END[];

#if 1

// rgba16 textures?
u8* D_803A5770_7B6E20[][2] = {
    { 0x42DCA0, 0x435320, }, // europe
    { 0x435320, 0x43cb60, }, // ice
    { 0x43CB60, 0x4457f0, }, // desert
    { 0x4457F0, 0x44e790, }, // jungle
    { 0x44E790, 0x44e7b0, }, // empty
    { 0x44E7B0, 0x4571a0, }, // city / credits
};

// ia16 textures?
u8* D_803A57A0_7B6E50[][2] = {
    { 0x4571A0, 0x459590, },
    { 0x459590, 0x45d550, },
    { 0x45d550, 0x45edc0, },
    { 0x45edc0, 0x461900, },
    { 0x461900, 0x461950, },
    { 0x461950, 0x461A20, },
    { 0x461A20, 0x465f90, },
    { 0x465f90, 0x46ba30, },
    { 0x46ba30, 0x470670, },
    { 0x470670, 0x474ee0, },
    { 0x474ee0, 0x47a0f0, },
    { 0x47a0f0, 0x47f1e0, },
    { 0x47f1e0, 0x484450, },
    { 0x484450, 0x488a70, },
    { 0x488a70, 0x48dd20, },
    { 0x48dd20, 0x4927e0, },
    // ice
    { 0x4927e0, 0x497b90, },
    { 0x497b90, 0x49c950, },
    { 0x49c950, 0x4a1690, },
    { 0x4a1690, 0x4a5170, },
    { 0x4a5170, 0x4a97e0, },
    { 0x4a97e0, 0x4ae610, },
    { 0x4ae610, 0x4b3440, },
    { 0x4b3440, 0x4b3460, },
    { 0x4b3460, 0x4b79a0, },
    { 0x4b79a0, 0x4b79c0, },
    { 0x4b79c0, 0x4b79e0, },
    // desert
    { 0x4b79e0, 0x4bc330, },
    { 0x4bc330, 0x4c12c0, },
    { 0x4c12c0, 0x4c4cd0, },
    { 0x4c4cd0, 0x4c91b0, },
    { 0x4c91b0, 0x4cd3a0, },
    { 0x4cd3a0, 0x4d1770, },
    { 0x4d1770, 0x4d68d0, },
    { 0x4d68d0, 0x4d6960, },
    { 0x4d6960, 0x4d6980, }, // empty
    { 0x4d6980, 0x4d69a0, }, // empty
    { 0x4d69a0, 0x4db210, },
    { 0x4db210, 0x4db230, }, // empty
    { 0x4db230, 0x4e0b80, },
    { 0x4e0b80, 0x4e57f0, },
    { 0x4e57f0, 0x4eabe0, },
    { 0x4eabe0, 0x4efc40, },
    { 0x4efc40, 0x4f5470, },
    { 0x4f5470, 0x4f5490, }, // empty
    { 0x4f5490, 0x4f54b0, }, // empty
    { 0x4f54b0, 0x4f54d0, }, // empty
};

u8* D_803A5918_7B6FC8[4] = {
    0x803A57D0,
    0x803A5828,
    0x803A5878,
    0x803A58C8,
};

// different to ROM ordering
u8* D_803A5928_7B6FD8[45][2] = {
    { 0x4F54D0, 0x4f6a70, },
    { 0x4f95b0, 0x4faf70, },
    { 0x4f8010, 0x4f95b0, },
    { 0x4f6a70, 0x4f8010, },
    { 0x4faf70, 0x4fc110, },
    { 0x4fc110, 0x4fd1e0, },
    { 0x4fd1e0, 0x4fdf70, },
    { 0x4fdf70, 0x4ff2b0, },
    { 0x4ff2b0, 0x500020, },
    { 0x500020, 0x500050, },
    { 0x500050, 0x501040, },
    { 0x501040, 0x502360, },
    { 0x502360, 0x503930, },
    { 0x503930, 0x504e70, },
    { 0x504e70, 0x505f00, },
    { 0x505f00, 0x505f30, },
    { 0x505f30, 0x506550, },
    { 0x506550, 0x506dd0, },
    { 0x506dd0, 0x507f00, },
    { 0x507f00, 0x507f30, },
    { 0x507f30, 0x507f60, },
    { 0x507f60, 0x507f90, },
    { 0x507f90, 0x507fc0, },
    { 0x507fc0, 0x509220, },
    { 0x509220, 0x509250, },
    { 0x509250, 0x50a4a0, },
    { 0x50a4a0, 0x50a4d0, },
    { 0x50a4d0, 0x50bdb0, },
    { 0x50bdb0, 0x50d230, },
    { 0x50d230, 0x50ecd0, },
    { 0x50ecd0, 0x5106e0, },
    { 0x5106e0, 0x512240, },
    { 0x512240, 0x512270, },
    { 0x512270, 0x5122a0, },
    { 0x5122a0, 0x5122d0, },
    { 0x5122d0, 0x5137c0, },
    { 0x5137c0, 0x514cb0, },
    { 0x514cb0, 0x515730, },
    { 0x515730, 0x516c20, },
    { 0x516c20, 0x518110, },
    { 0x518110, 0x519600, },
    { 0x519600, 0x51aaf0, },
    { 0x51aaf0, 0x51ab20, },
    { 0x51ab20, 0x51ab50, },
    { 0x51ab50, 0x51ab80, },
};

u8* D_803A5A90_7B7140[4] = {
    0x803A5948,
    0x803A59A0,
    0x803A5A40,
    0x803A59F0,
};

// level objects
u8 *D_803A5AA0_7B7150[41][2] = {
    // europe
    { 0x85790, 0x87b80, }, // HAVE_A_NICE_DAY
    { 0x87b80, 0x89260, }, // HONEYMOON_LAGOON
    { 0x89260, 0x92bf0, }, // SMASHING_START + intro
    { 0x92bf0, 0x96790, }, // THE_BATTERY_FARM
    { 0x96790, 0x97020, }, // GIVE_A_DOG_A_BONUS
    { 0x97020, 0x9e0d0, }, // DMA_INTRO
    { 0x9e0d0, 0x9ed10, }, // STINKY_SEWERS
    { 0x9ed10, 0xa0e40, }, // RAT_O_MATIC
    { 0xa0e40, 0xa10c0, }, // ROCKY_HARD_PLACE
    { 0xa10c0, 0xa10d0, }, // empty
    { 0xa10d0, 0xaa940, }, // BIG_CELEBRATION_PARADE?
    // ice
    { 0xaa940, 0xb0490, }, // SOMETHING_FISHY
    { 0xb0490, 0xb0b90, }, // HOPPA_CHOPPA
    { 0xb0b90, 0xb2ed0, }, // PENGUIN_PLAYPEN
    { 0xb2ed0, 0xb3d70, }, // WALRACE_64
    { 0xb3d70, 0xb3d80, }, // empty
    { 0xb3d80, 0xb3d90, }, // empty
    { 0xb3d90, 0xb3da0, }, // empty
    { 0xb3da0, 0xb3db0, }, // empty
    { 0xb3db0, 0xb3dc0, }, // empty
    { 0xb3dc0, 0xb3dd0, }, // empty
    // desert / jungle ?
    { 0xb3dd0, 0xb40c0, },
    { 0xb40c0, 0xb40d0, },
    { 0xb40d0, 0xb43a0, },
    { 0xb43a0, 0xb48c0, },
    { 0xb48c0, 0xb48d0, }, // EVOS_ESCAPE
    { 0xb48d0, 0xbd090, },
    { 0xbd090, 0xbd0a0, },
    { 0xbd0a0, 0xbd0b0, },
    { 0xbd0b0, 0xbd0c0, },
    { 0xbd0c0, 0xbd0d0, },
    // jungle / desert ?
    { 0xbd0d0, 0xbd2b0, },
    { 0xbd2b0, 0xbfc40, },
    { 0xbfc40, 0xc4500, }, // PUNCHUP_PYRAMID
    { 0xc4500, 0xc4510, },
    { 0xc4510, 0xc47a0, },
    { 0xc47a0, 0xc47b0, },
    { 0xc47b0, 0xc7a00, },
    { 0xc7a00, 0xc7a10, },
    { 0xc7a10, 0xc7a20, },
    { 0xc7a20, 0xc7a30, },
};

u8* D_803A5BE8_7B7298[4] = {
    D_803A5AA0_7B7150[0],  // 0x803A5AA0,
    D_803A5AA0_7B7150[11], // 0x803A5AF8, // 0x7b71a8
    D_803A5AA0_7B7150[31], // 0x803A5B98, // 0x7b7248
    D_803A5AA0_7B7150[21], // 0x803A5B48, // 0x7b71f8
};

extern u8 levels_SMASHING_START_ROM_START[], levels_SMASHING_START_ROM_END[];
extern u8 levels_HAVE_A_NICE_DAY_ROM_START[], levels_HAVE_A_NICE_DAY_ROM_END[];
extern u8 levels_HONEYMOON_LAGOON_ROM_START[], levels_HONEYMOON_LAGOON_ROM_END[];
extern u8 levels_THE_BATTERY_FARM_ROM_START[], levels_THE_BATTERY_FARM_ROM_END[];
extern u8 levels_THE_ENGINE_ROOM_ROM_START[], levels_THE_ENGINE_ROOM_ROM_END[];
extern u8 levels_FAT_BEAR_MOUNTAIN_ROM_START[], levels_FAT_BEAR_MOUNTAIN_ROM_END[];
extern u8 levels_ROCKY_HARD_PLACE_ROM_START[], levels_ROCKY_HARD_PLACE_ROM_END[];
extern u8 levels_STINKY_SEWERS_ROM_START[], levels_STINKY_SEWERS_ROM_END[];
extern u8 levels_RAT_O_MATIC_ROM_START[], levels_RAT_O_MATIC_ROM_END[];
extern u8 levels_GIVE_A_DOG_A_BONUS_ROM_START[], levels_GIVE_A_DOG_A_BONUS_ROM_END[];
extern u8 levels_SNOW_JOKE_ROM_START[], levels_SNOW_JOKE_ROM_END[];
extern u8 levels_ICE_N_EASY_DOES_IT_ROM_START[], levels_ICE_N_EASY_DOES_IT_ROM_END[];
extern u8 levels_PENGUIN_PLAYPEN_ROM_START[], levels_PENGUIN_PLAYPEN_ROM_END[];
extern u8 levels_PINBALL_BLIZZARD_ROM_START[], levels_PINBALL_BLIZZARD_ROM_END[];
extern u8 levels_HOPPA_CHOPPA_ROM_START[], levels_HOPPA_CHOPPA_ROM_END[];
extern u8 levels_SOMETHING_FISHY_ROM_START[], levels_SOMETHING_FISHY_ROM_END[];
extern u8 levels_WALRACE_64_ROM_START[], levels_WALRACE_64_ROM_END[];
extern u8 levels_JUNGLE_JAPES_ROM_START[], levels_JUNGLE_JAPES_ROM_END[];
extern u8 levels_JUNGLE_DOLDRUMS_ROM_START[], levels_JUNGLE_DOLDRUMS_ROM_END[];
extern u8 levels_SWAMP_OF_ETERNAL_STENCH_ROM_START[], levels_SWAMP_OF_ETERNAL_STENCH_ROM_END[];
extern u8 levels_WEIGHT_FOR_IT_ROM_START[], levels_WEIGHT_FOR_IT_ROM_END[];
extern u8 levels_JUNGLE_JUMPS_ROM_START[], levels_JUNGLE_JUMPS_ROM_END[];
extern u8 levels_EVOS_ESCAPE_ROM_START[], levels_EVOS_ESCAPE_ROM_END[];
extern u8 levels_FUN_IN_THE_SUN_ROM_START[], levels_FUN_IN_THE_SUN_ROM_END[];
extern u8 levels_HOT_CROSS_BUNS_ROM_START[], levels_HOT_CROSS_BUNS_ROM_END[];
extern u8 levels_STING_IN_THE_TAIL_ROM_START[], levels_STING_IN_THE_TAIL_ROM_END[];
extern u8 levels_BORASSIC_PARK_ROM_START[], levels_BORASSIC_PARK_ROM_END[];
extern u8 levels_WHIRLWIND_TOUR_ROM_START[], levels_WHIRLWIND_TOUR_ROM_END[];
extern u8 levels_SHIFTING_SANDS_ROM_START[], levels_SHIFTING_SANDS_ROM_END[];
extern u8 levels_PUNCHUP_PYRAMID_ROM_START[], levels_PUNCHUP_PYRAMID_ROM_END[];
extern u8 levels_BIG_CELEBRATION_PARADE_ROM_START[], levels_BIG_CELEBRATION_PARADE_ROM_END[];

extern u8 levels_rnc_60E920_ROM_START[], levels_rnc_60E920_ROM_END[];
extern u8 levels_rnc_60FFD0_ROM_START[], levels_rnc_60FFD0_ROM_END[];
extern u8 levels_rnc_6104A0_ROM_START[], levels_rnc_6104A0_ROM_END[];
extern u8 levels_rnc_6109D0_ROM_START[], levels_rnc_6109D0_ROM_END[];
extern u8 levels_INTRO_ROM_START[], levels_INTRO_ROM_END[];

// levels
u8* D_803A5BF8_7B72A8[36][2] = {
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

#endif

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
    void *temp_a3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_5;
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
    dma_read(D_803A5770_7B6E20[texture][0], &D_80100000, D_803A5770_7B6E20[texture][1] - D_803A5770_7B6E20[texture][0]);
    UnpackRNC(&D_80100000, &D_800BA760);

    // difference is 0x15700

    // temp_v0_2 = sp28 + &D_803A57A0_7B6E50;
    // temp_a0_2 = temp_v0_2->unk0;
    dma_read(D_803A57A0_7B6E50[texture][0], &D_80100000, D_803A57A0_7B6E50[texture][1] - D_803A57A0_7B6E50[texture][0]);
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
    temp_a0_4 = temp_a3->unk0;
    sp28 = ((arg1 * 2) & 0xFFFF) * 4;
    dma_read(temp_a0_4, &D_80100000, temp_a3->unk4 - temp_a0_4);
    UnpackRNC(&D_80100000, &D_800C7DC0);
    temp_v0_4 = sp34 + sp28;
    temp_a0_5 = temp_v0_4->unk0;
    dma_read(temp_a0_5, &D_80100000, temp_v0_4->unk4 - temp_a0_5);
    UnpackRNC(&D_80100000, &D_800D5420);
    D_801D9E78 = &D_800B0B20;
    temp_v0_5 = sp30 + sp28;
    temp_a0_6 = temp_v0_5->unk0;
    dma_read(temp_a0_6, &D_800B0B20, temp_v0_5->unk4 - temp_a0_6);
#endif
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/load_level_data.s")
// void load_level_data(u8 level) {
//     func_8031C374_72DA24();
//     // 0-indexed so subtract 1
//     level = level - 1;
//     //
//     dma_read(
//         D_803A5BF8_7B72A8[level][0],
//         &D_80100000,
//         D_803A5BF8_7B72A8[level][1] - D_803A5BF8_7B72A8[level][0]);
//     func_8031B400_72CAB0();
//     func_8031C48C_72DB3C();
// }

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
    D_803F2E0C = 0;
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
//     load_data_section(D_803F2D50.biome);
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
//     // load a bunch of textures
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
