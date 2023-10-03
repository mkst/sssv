#include <ultra64.h>
#include "common.h"
#include "pp.h"


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

// ========================================================
// .data
// ========================================================

// rgba16 mipmapped textures?
u8 *D_803A5770_7B6E20[] = {
    // img_europe_mipmap_rnc_ROM_START, img_europe_mipmap_rnc_ROM_END,  // europe
    rnc_42DCA0_ROM_START, rnc_42DCA0_ROM_END,  // europe
    rnc_435320_ROM_START, rnc_435320_ROM_END,  // ice
    rnc_43CB60_ROM_START, rnc_43CB60_ROM_END,  // desert
    rnc_4457F0_ROM_START, rnc_4457F0_ROM_END,  // jungle
    empty_rnc_44E790_ROM_START, empty_rnc_44E790_ROM_END,  // empty
    rnc_44E7B0_ROM_START, rnc_44E7B0_ROM_END,  // city / credits
};

// ia16 textures?
u8 *D_803A57A0_7B6E50[] = {
    rnc_4571A0_ROM_START, rnc_4571A0_ROM_END,
    rnc_459590_ROM_START, rnc_459590_ROM_END,
    rnc_45D550_ROM_START, rnc_45D550_ROM_END,
    rnc_45EDC0_ROM_START, rnc_45EDC0_ROM_END,
    rnc_461900_ROM_START, rnc_461900_ROM_END,
    rnc_461950_ROM_START, rnc_461950_ROM_END,
    //
    rnc_461A20_ROM_START, rnc_461A20_ROM_END,
    rnc_465F90_ROM_START, rnc_465F90_ROM_END,
    rnc_46BA30_ROM_START, rnc_46BA30_ROM_END,
    rnc_470670_ROM_START, rnc_470670_ROM_END,
    rnc_474EE0_ROM_START, rnc_474EE0_ROM_END,
    rnc_47A0F0_ROM_START, rnc_47A0F0_ROM_END,
    rnc_47F1E0_ROM_START, rnc_47F1E0_ROM_END,
    rnc_484450_ROM_START, rnc_484450_ROM_END,
    rnc_488A70_ROM_START, rnc_488A70_ROM_END,
    rnc_48DD20_ROM_START, rnc_48DD20_ROM_END,
    rnc_4927E0_ROM_START, rnc_4927E0_ROM_END,
    rnc_497B90_ROM_START, rnc_497B90_ROM_END,
    //
    rnc_49C950_ROM_START, rnc_49C950_ROM_END,
    rnc_4A1690_ROM_START, rnc_4A1690_ROM_END,
    rnc_4A5170_ROM_START, rnc_4A5170_ROM_END,
    rnc_4A97E0_ROM_START, rnc_4A97E0_ROM_END,
    rnc_4AE610_ROM_START, rnc_4AE610_ROM_END,
    empty_rnc_4B3440_ROM_START, empty_rnc_4B3440_ROM_END,
    rnc_4B3460_ROM_START, rnc_4B3460_ROM_END,
    empty_rnc_4B79A0_ROM_START, empty_rnc_4B79A0_ROM_END,
    empty_rnc_4B79C0_ROM_START, empty_rnc_4B79C0_ROM_END,
    // desert
    rnc_4B79E0_ROM_START, rnc_4B79E0_ROM_END,
    rnc_4BC330_ROM_START, rnc_4BC330_ROM_END,
    rnc_4C12C0_ROM_START, rnc_4C12C0_ROM_END,
    rnc_4C4CD0_ROM_START, rnc_4C4CD0_ROM_END,
    rnc_4C91B0_ROM_START, rnc_4C91B0_ROM_END,
    rnc_4CD3A0_ROM_START, rnc_4CD3A0_ROM_END,
    rnc_4D1770_ROM_START, rnc_4D1770_ROM_END,
    rnc_4D68D0_ROM_START, rnc_4D68D0_ROM_END,
    empty_rnc_4D6960_ROM_START, empty_rnc_4D6960_ROM_END, // empty
    empty_rnc_4D6980_ROM_START, empty_rnc_4D6980_ROM_END, // empty
    rnc_4D69A0_ROM_START, rnc_4D69A0_ROM_END,
    empty_rnc_4DB210_ROM_START, empty_rnc_4DB210_ROM_END, // empty
    rnc_4DB230_ROM_START, rnc_4DB230_ROM_END,
    rnc_4E0B80_ROM_START, rnc_4E0B80_ROM_END,
    rnc_4E57F0_ROM_START, rnc_4E57F0_ROM_END,
    rnc_4EABE0_ROM_START, rnc_4EABE0_ROM_END,
    rnc_4EFC40_ROM_START, rnc_4EFC40_ROM_END,
    empty_rnc_4F5470_ROM_START, empty_rnc_4F5470_ROM_END, // empty
    empty_rnc_4F5490_ROM_START, empty_rnc_4F5490_ROM_END, // empty
    empty_rnc_4F54B0_ROM_START, empty_rnc_4F54B0_ROM_END, // empty
};

u8** D_803A5918_7B6FC8[4] = {
    &D_803A57A0_7B6E50[6*2],   // 0x803a57d0
    &D_803A57A0_7B6E50[17*2],  // 0x803a5828
    &D_803A57A0_7B6E50[27*2],  // 0x803a5878
    &D_803A57A0_7B6E50[37*2],  // 0x803a58c8
};

// different to ROM ordering
u8* D_803A5928_7B6FD8[90] = {
    rnc_4F54D0_ROM_START, rnc_4F54D0_ROM_END,
    rnc_4F95B0_ROM_START, rnc_4F95B0_ROM_END,
    rnc_4F8010_ROM_START, rnc_4F8010_ROM_END,
    rnc_4F6A70_ROM_START, rnc_4F6A70_ROM_END,

    rnc_4FAF70_ROM_START, rnc_4FAF70_ROM_END,
    rnc_4FC110_ROM_START, rnc_4FC110_ROM_END,
    rnc_4FD1E0_ROM_START, rnc_4FD1E0_ROM_END,
    rnc_4FDF70_ROM_START, rnc_4FDF70_ROM_END,
    rnc_4FF2B0_ROM_START, rnc_4FF2B0_ROM_END,
    rnc_500020_ROM_START, rnc_500020_ROM_END,
    rnc_500050_ROM_START, rnc_500050_ROM_END,
    rnc_501040_ROM_START, rnc_501040_ROM_END,
    rnc_502360_ROM_START, rnc_502360_ROM_END,
    rnc_503930_ROM_START, rnc_503930_ROM_END,
    rnc_504E70_ROM_START, rnc_504E70_ROM_END,

    rnc_505F00_ROM_START, rnc_505F00_ROM_END,
    rnc_505F30_ROM_START, rnc_505F30_ROM_END,
    rnc_506550_ROM_START, rnc_506550_ROM_END,
    rnc_506DD0_ROM_START, rnc_506DD0_ROM_END,
    rnc_507F00_ROM_START, rnc_507F00_ROM_END,
    rnc_507F30_ROM_START, rnc_507F30_ROM_END,
    rnc_507F60_ROM_START, rnc_507F60_ROM_END,
    rnc_507F90_ROM_START, rnc_507F90_ROM_END,
    rnc_507FC0_ROM_START, rnc_507FC0_ROM_END,
    rnc_509220_ROM_START, rnc_509220_ROM_END,

    rnc_509250_ROM_START, rnc_509250_ROM_END,
    rnc_50A4A0_ROM_START, rnc_50A4A0_ROM_END,
    rnc_50A4D0_ROM_START, rnc_50A4D0_ROM_END,
    rnc_50BDB0_ROM_START, rnc_50BDB0_ROM_END,
    rnc_50D230_ROM_START, rnc_50D230_ROM_END,
    rnc_50ECD0_ROM_START, rnc_50ECD0_ROM_END,
    rnc_5106E0_ROM_START, rnc_5106E0_ROM_END,
    rnc_512240_ROM_START, rnc_512240_ROM_END,
    rnc_512270_ROM_START, rnc_512270_ROM_END,
    rnc_5122A0_ROM_START, rnc_5122A0_ROM_END,

    rnc_5122D0_ROM_START, rnc_5122D0_ROM_END,
    rnc_5137C0_ROM_START, rnc_5137C0_ROM_END,
    rnc_514CB0_ROM_START, rnc_514CB0_ROM_END,
    rnc_515730_ROM_START, rnc_515730_ROM_END,
    rnc_516C20_ROM_START, rnc_516C20_ROM_END,
    rnc_518110_ROM_START, rnc_518110_ROM_END,
    rnc_519600_ROM_START, rnc_519600_ROM_END,
    rnc_51AAF0_ROM_START, rnc_51AAF0_ROM_END,
    rnc_51AB20_ROM_START, rnc_51AB20_ROM_END,
    rnc_51AB50_ROM_START, rnc_51AB50_ROM_END,
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
    HAVE_A_NICE_DAY_ROM_START, HAVE_A_NICE_DAY_ROM_END,
    HONEYMOON_LAGOON_ROM_START, HONEYMOON_LAGOON_ROM_END,
    SMASHING_START_ROM_START, SMASHING_START_ROM_END,
    THE_BATTERY_FARM_ROM_START, THE_BATTERY_FARM_ROM_END,
    GIVE_A_DOG_A_BONUS_ROM_START, GIVE_A_DOG_A_BONUS_ROM_END,
    DMA_INTRO_ROM_START, DMA_INTRO_ROM_END,
    STINKY_SEWERS_ROM_START, STINKY_SEWERS_ROM_END,
    RAT_O_MATIC_ROM_START, RAT_O_MATIC_ROM_END,
    ROCKY_HARD_PLACE_ROM_START, ROCKY_HARD_PLACE_ROM_END,
    FAT_BEAR_MOUNTAIN_ROM_START, FAT_BEAR_MOUNTAIN_ROM_END,
    // final
    BIG_CELEBRATION_PARADE_ROM_START, BIG_CELEBRATION_PARADE_ROM_END,
    // ice
    SOMETHING_FISHY_ROM_START, SOMETHING_FISHY_ROM_END,
    ICE_N_EASY_DOES_IT_ROM_START, ICE_N_EASY_DOES_IT_ROM_END,
    PINBALL_BLIZZARD_ROM_START, PINBALL_BLIZZARD_ROM_END,
    WALRACE_64_ROM_START, WALRACE_64_ROM_END,
    PENGUIN_PLAYPEN_ROM_START, PENGUIN_PLAYPEN_ROM_END,
    SNOW_JOKE_ROM_START, SNOW_JOKE_ROM_END,
    UNUSED_ICE_SLOT_7_ROM_START, UNUSED_ICE_SLOT_7_ROM_END,
    HOPPA_CHOPPA_ROM_START, HOPPA_CHOPPA_ROM_END,
    UNUSED_ICE_SLOT_9_ROM_START, UNUSED_ICE_SLOT_9_ROM_END,
    UNUSED_ICE_SLOT_10_ROM_START, UNUSED_ICE_SLOT_10_ROM_END,
    // jungle
    WEIGHT_FOR_IT_ROM_START, WEIGHT_FOR_IT_ROM_END,
    UNUSED_JUNGLE_SLOT_2_ROM_START, UNUSED_JUNGLE_SLOT_2_ROM_END,
    JUNGLE_JUMPS_ROM_START, JUNGLE_JUMPS_ROM_END,
    SWAMP_OF_ETERNAL_STENCH_ROM_START, SWAMP_OF_ETERNAL_STENCH_ROM_END,
    JUNGLE_DOLDRUMS_ROM_START, JUNGLE_DOLDRUMS_ROM_END,
    EVOS_ESCAPE_ROM_START, EVOS_ESCAPE_ROM_END,
    JUNGLE_JAPES_ROM_START, JUNGLE_JAPES_ROM_END,
    UNUSED_JUNGLE_SLOT_8_ROM_START, UNUSED_JUNGLE_SLOT_8_ROM_END,
    UNUSED_JUNGLE_SLOT_9_ROM_START, UNUSED_JUNGLE_SLOT_9_ROM_END,
    UNUSED_JUNGLE_SLOT_10_ROM_START, UNUSED_JUNGLE_SLOT_10_ROM_END,
    // desert
    FUN_IN_THE_SUN_ROM_START, FUN_IN_THE_SUN_ROM_END,
    HOT_CROSS_BUNS_ROM_START, HOT_CROSS_BUNS_ROM_END,
    PUNCHUP_PYRAMID_ROM_START, PUNCHUP_PYRAMID_ROM_END,
    STING_IN_THE_TAIL_ROM_START, STING_IN_THE_TAIL_ROM_END,
    SHIFTING_SANDS_ROM_START, SHIFTING_SANDS_ROM_END,
    WHIRLWIND_TOUR_ROM_START, WHIRLWIND_TOUR_ROM_END,
    BORASSIC_PARK_ROM_START, BORASSIC_PARK_ROM_END,
    UNUSED_DESERT_SLOT_8_ROM_START, UNUSED_DESERT_SLOT_8_ROM_END,
    UNUSED_DESERT_SLOT_9_ROM_START, UNUSED_DESERT_SLOT_9_ROM_END,
    UNUSED_DESERT_SLOT_10_ROM_START, UNUSED_DESERT_SLOT_10_ROM_END,
};

u8** D_803A5BE8_7B7298[4] = {
    &D_803A5AA0_7B7150[0*2],  // europe
    &D_803A5AA0_7B7150[11*2], // ice
    &D_803A5AA0_7B7150[31*2], // desert
    &D_803A5AA0_7B7150[21*2], // jungle
};

// levels
u8 *D_803A5BF8_7B72A8[72] = {
    levels_SMASHING_START_ROM_START, levels_SMASHING_START_ROM_END,
    levels_HAVE_A_NICE_DAY_ROM_START, levels_HAVE_A_NICE_DAY_ROM_END,
    levels_HONEYMOON_LAGOON_ROM_START, levels_HONEYMOON_LAGOON_ROM_END,
    levels_THE_BATTERY_FARM_ROM_START, levels_THE_BATTERY_FARM_ROM_END,
    levels_THE_ENGINE_ROOM_ROM_START, levels_THE_ENGINE_ROOM_ROM_END,
    levels_FAT_BEAR_MOUNTAIN_ROM_START, levels_FAT_BEAR_MOUNTAIN_ROM_END,
    levels_ROCKY_HARD_PLACE_ROM_START, levels_ROCKY_HARD_PLACE_ROM_END,
    levels_STINKY_SEWERS_ROM_START, levels_STINKY_SEWERS_ROM_END,
    levels_RAT_O_MATIC_ROM_START, levels_RAT_O_MATIC_ROM_END,
    levels_GIVE_A_DOG_A_BONUS_ROM_START, levels_GIVE_A_DOG_A_BONUS_ROM_END,

    levels_SNOW_JOKE_ROM_START, levels_SNOW_JOKE_ROM_END,
    levels_ICE_N_EASY_DOES_IT_ROM_START, levels_ICE_N_EASY_DOES_IT_ROM_END,
    levels_PENGUIN_PLAYPEN_ROM_START, levels_PENGUIN_PLAYPEN_ROM_END,
    levels_PINBALL_BLIZZARD_ROM_START, levels_PINBALL_BLIZZARD_ROM_END,
    levels_HOPPA_CHOPPA_ROM_START, levels_HOPPA_CHOPPA_ROM_END,
    levels_SOMETHING_FISHY_ROM_START, levels_SOMETHING_FISHY_ROM_END,
    levels_WALRACE_64_ROM_START, levels_WALRACE_64_ROM_END,

    levels_JUNGLE_JAPES_ROM_START, levels_JUNGLE_JAPES_ROM_END,
    levels_JUNGLE_DOLDRUMS_ROM_START, levels_JUNGLE_DOLDRUMS_ROM_END,
    levels_SWAMP_OF_ETERNAL_STENCH_ROM_START, levels_SWAMP_OF_ETERNAL_STENCH_ROM_END,
    levels_WEIGHT_FOR_IT_ROM_START, levels_WEIGHT_FOR_IT_ROM_END,
    levels_JUNGLE_JUMPS_ROM_START, levels_JUNGLE_JUMPS_ROM_END,
    levels_EVOS_ESCAPE_ROM_START, levels_EVOS_ESCAPE_ROM_END,

    levels_FUN_IN_THE_SUN_ROM_START, levels_FUN_IN_THE_SUN_ROM_END,
    levels_HOT_CROSS_BUNS_ROM_START, levels_HOT_CROSS_BUNS_ROM_END,
    levels_STING_IN_THE_TAIL_ROM_START, levels_STING_IN_THE_TAIL_ROM_END,
    levels_BORASSIC_PARK_ROM_START, levels_BORASSIC_PARK_ROM_END,
    levels_WHIRLWIND_TOUR_ROM_START, levels_WHIRLWIND_TOUR_ROM_END,
    levels_SHIFTING_SANDS_ROM_START, levels_SHIFTING_SANDS_ROM_END,
    levels_PUNCHUP_PYRAMID_ROM_START, levels_PUNCHUP_PYRAMID_ROM_END,

    levels_BIG_CELEBRATION_PARADE_ROM_START, levels_BIG_CELEBRATION_PARADE_ROM_END,

    levels_rnc_60E920_ROM_START, levels_rnc_60E920_ROM_END,
    levels_rnc_60FFD0_ROM_START, levels_rnc_60FFD0_ROM_END,
    levels_rnc_6104A0_ROM_START, levels_rnc_6104A0_ROM_END,
    levels_rnc_6109D0_ROM_START, levels_rnc_6109D0_ROM_END,

    levels_INTRO_ROM_START, levels_INTRO_ROM_END
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


#ifdef NON_MATCHING

// load_level_texture_data()
// CURRENT (30)
void load_level_texture_data(u8 arg0, u8 arg1) {
    u8 **temp_v0;

    s32 pad[2];

    u8 **sp38;
    u8 **sp34;
    u8 **sp30;

    u8 var_v0;
    u8 var_t0;

    var_v0 = arg0;
    var_t0 = arg0;

    if (arg0 == 4) {
        var_v0 = arg0 = 5; // handle BIG_CELEBRATION_PARADE/CREDITS
    }

    if ((arg0 == 4) || (arg0 == 5)) {
        var_t0 = arg0 = 0;
    }

    rmonPrintf("Bank - %d Texture - %d\n", arg0, var_v0);

    arg1 -= 1; // level index?

    // load rgba16 mipmapped textures
    temp_v0 = &D_803A5770_7B6E20[(u16)(var_v0 + var_v0)];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800BA760);

    // load ia16 textures
    temp_v0 = &D_803A57A0_7B6E50[(u16)(var_v0 + var_v0)];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800CFE60);

    // load biome textures (?)
    temp_v0 = &D_803A5928_7B6FD8[(u16)(var_t0 + var_t0)];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800D7C20);

    // load level ia16 textures
    sp38 = D_803A5918_7B6FC8[arg0];
    // load level textures
    sp34 = D_803A5A90_7B7140[arg0];
    // load level objects
    sp30 = D_803A5BE8_7B7298[arg0];

    temp_v0 = &sp38[(u16)(arg1 + arg1)];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800C7DC0);

    temp_v0 = &sp34[(u16)(arg1 + arg1)];
    dma_read(temp_v0[0], &D_80100000, temp_v0[1] - temp_v0[0]);
    UnpackRNC((RNC_fileptr)&D_80100000, D_800D5420);

    D_801D9E78 = D_800B0B20;

    temp_v0 = &sp30[(u16)(arg1 + arg1)];
    dma_read(temp_v0[0], D_801D9E78, temp_v0[1] - temp_v0[0]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/load_level_texture_data.s")
#endif

void load_level_data(u8 level) {
    u8 **tmp;
    s32 len;

    func_8031C374_72DA24();

    // 0-indexed so subtract 1
    level = level - 1;

    tmp = &D_803A5BF8_7B72A8[level+level];
    len = tmp[1] - tmp[0];

    dma_read(tmp[0], &D_80100000, len);
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
    u8 *base;

    u8 *paf;
    u8 *paf2;

    Animal *temp_s1;

    u16 pafBytesUsed;
    s16 j;

    s32 temp_v0;
    s16 i;

    u8  done; // sp85
    s32 length2;
    s16 length;
    u16 count;
    u16 sp7A;
    s16 *payload;

    base = &D_80100000;

    copy_or_extract(base, gFramebuffer, 0x25800);
    buf = gFramebuffer;

    sp7A = D_803D553E;
    done = 0;

    do {
        temp_v0 = *buf++; // payloadType

        switch (temp_v0) {
        case 0: /* .cob */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = ((DataSectionSigned*)base)->count;
            cob = (struct090*) ((DataSectionSigned*)base)->payload;

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

                if (cob->id == OBJECT_TELEPORTER_ACTIVE_NO_TRIGGER) {
                    D_803F2E0C = obj;
                } else if (cob->id == OBJECT_TELEPORTER_ACTIVE) {
                    D_803F2E10 = obj;
                }

                obj->unk3E = cob->unkC;

                // load object commands?
                if (cob->commandReferenceIdx != 0) {
                    load_commands_into_object(
                        (Animal *) obj,
                        &D_803E4D40[cob->commandReferenceIdx] - 1,
                        cob->commandsLength);
                }
                obj->unk246 = cob->unk12;
                cob++;
            }
            break;

        case 1: /* .can */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = ((DataSectionSigned*)base)->count;
            can = (struct091*) ((DataSectionSigned*)base)->payload;

            while (length-- > 0) {
                spawn_animal(
                    can->x,
                    can->z,
                    can->y,
                    can->rotation,
                    can->health,
                    can->id,
                    0);

                temp_s1 = D_801D9ED8.animals[D_803D553E - 1].animal;
                if (can->unkC != 0) {
                    load_commands_into_object(
                        temp_s1,
                        &D_803E4D40[can->unkC] - 1,
                        0U);
                }

                temp_s1->unk246 = can->unkE;
                can++;
            }
            break;

        case 2: /* .joi */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = ((DataSectionUnsigned*)base)->count;
            joi = (struct092*) ((DataSectionSigned*)base)->payload;

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
        case 3:  /* end of data sentinel */
            done = 1;
            break;
        case 4:  /* .cmd */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            count = ((DataSectionUnsigned*)base)->count;
            length2 = sizeof(struct112);

            func_80314788_725E38(); // zero out D_803E4D40 amongst other things
            memcpy_sssv(((DataSectionSigned*)base)->payload, (u8*)D_803E4D40, count);

            D_803E8E54 = count / (u32)length2; // gNumCommands
            for (j = 0; j < D_803E8E54; j++) {
                if (D_803E4D40[(u32)j].type == 24) {
                    rmonPrintf(
                        "Partcle State: %d F $%X Fq %d Time %d S %d\n",
                        D_803E4D40[(u32)j].cmd.type24.State,
                        D_803E4D40[(u32)j].cmd.type24.F,
                        D_803E4D40[(u32)j].cmd.type24.Fq,
                        D_803E4D40[(u32)j].cmd.type24.Time,
                        D_803E4D40[(u32)j].cmd.type24.S);
                }
            }
            break;
        case 5: /* .rng */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            length = ((DataSectionUnsigned*)base)->count;

            memcpy_sssv(((DataSectionSigned*)base)->payload, (u8*)&D_803E93B0, length * sizeof(struct067));

            D_803E93B0[length].unk2 = 245;
            D_803E93B0[length].unk5 = 245;

            func_803198B0_72AF60();
            break;
        case 6: /* .paf */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            paf = ((DataSectionSigned*)base)->payload;
            paf2 = ((DataSectionSigned*)base)->payload;

            count = *((s16*)base + 0); // number of entries

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

            if (!base) {};

            rmonPrintf("Path thingies: %d (%d).\n", pafBytesUsed, sizeof(D_803E8F60));
            // no boundary check here!
            memcpy_sssv(paf2, (u8*)D_803E8F60, pafBytesUsed);
            D_803A5750_7B6E00 = i;
            break;

        case 7: /* .cha */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            cha = (struct097*) ((DataSectionSigned*)base)->payload;
            length = ((DataSectionUnsigned*)base)->count;

            while (length-- > 0) {
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
                    func_802DD090_6EE740(
                        8,
                        FTOFIX32(31.25),
                        1,
                        6,
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
                    func_802DD090_6EE740(
                        16,
                        FTOFIX32(31.25),
                        1,
                        7,
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
                    func_802DD090_6EE740(
                        0x10,
                        FTOFIX32(31.25),
                        0,
                        cha->unk0,
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
                    func_802DD090_6EE740(
                        0x10,
                        FTOFIX32(31.25),
                        0,
                        cha->unk0,
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
                    func_802DD090_6EE740(
                        8,
                        FTOFIX32(31.25),
                        0,
                        cha->unk0,
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
                    func_802DD090_6EE740(
                        8,
                        FTOFIX32(31.25),
                        0,
                        cha->unk0,
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
                    func_802DD090_6EE740(
                        4,
                        FTOFIX32(9.375),
                        0,
                        9,
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
                    func_802DD090_6EE740(
                        4,
                        FTOFIX32(9.375),
                        0,
                        cha->unk0, // was 10
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
                    func_802DD090_6EE740(
                        0x10,
                        FTOFIX32(10.828125),
                        0,
                        8,
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

            func_80344240_7558F0();
            break;
        case 11: /* .mat */
            func_80304170_715820();

            length2 = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            memcpy_sssv(base, (u8*)&D_803E1D30, length2);
            break;
        case 12: /* .dat */
            func_80304194_715844();

            length2 = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            memcpy_sssv(base, (u8*)&D_803F2D50, length2);
            D_803F2D50.unkE0 = D_803F2D50.unk40;
            load_level_texture_data(D_803F2D50.segment, D_803F2D50.unk52);
            break;
        case 13: /* .cam */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            payload = ((DataSectionSigned*)base)->payload;
            length2 = ((DataSectionSigned*)base)->count;

            bzero_sssv((u8*)&D_803A6D14_7B83C4, sizeof(D_803A6D14_7B83C4));
            bzero_sssv((u8*)&D_803A7114_7B87C4, sizeof(D_803A7114_7B87C4));

            memcpy_sssv(payload,                                        (u8*)&D_803A6D14_7B83C4, length2 * sizeof(struct105));
            memcpy_sssv(payload + ((length2 * sizeof(struct105)) >> 1), (u8*)&D_803A7114_7B87C4, length2 * sizeof(struct074));

            func_8034401C_7556CC();
            break;
        case 14: /* tbd */
            length2 = get_uncompressed_size(buf);
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);
            memcpy_sssv(base, (u8*)&D_803E2930,  length2);
            break;
        case 15: /* tbd */
            copy_or_extract(buf, base, 0x25800);
            buf += get_compressed_size(buf);

            payload = ((DataSectionSigned*)base)->payload;
            length2 = ((DataSectionSigned*)base)->count;

            memcpy_sssv(payload, (u8*)D_803B1D20_7C33D0, length2 * 8U);
            break;
        default:
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
    D_803F2D50.unkBC = NULL;
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

#if 0
void func_8031C48C_72DB3C(void) {
    int offset;

    s16 i;
    u16 id;
    s16 id2;

    if (D_803F2D50.unkBC != NULL) {
        func_8029B9B8_6AD068(D_801D9ED8.animals[gCurrentAnimalIndex].animal, D_803F2D50.unkBC);
    }

    load_data_section(D_803F2D50.segment);
    func_802FD8CC_70EF7C();
    func_8033C334_74D9E4();
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
    for (i = 0; i < D_803D553E; i++) {

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
    dma_read(rnc_637160_ROM_START, D_80100000, rnc_637160_ROM_END - rnc_637160_ROM_START);
    UnpackRNC(D_80100000, gFramebuffer);

    offset = 1;

    // objects
    for (i = 0; i < 170; i++) {
        if ((D_801E9EB8.objects[i].unk16C != NULL) && (D_801E9EB8.objects[i].unk26C == 0)) {
            id = D_801E9EB8.objects[i].unk16C->id;
            if ((id != 0) && (D_801E9EB8.objects[i].unk16C->collision == NULL)) {
                // link the collision?
                s32 idx = (((s16) id - offset));
                func_8031C3C0_72DA70(((Collision*)gFramebuffer) + idx, id);
            }
        }
    }

    // commands
    for (i = 0; i < D_803E8E54; i++) {

        s32 at = 17;

        struct112 *cmd;

        cmd = &D_803E4D40[i];

        if ((cmd->type != 16) && (cmd->type != 17)) {

        } else {
            // object has custom collision
            id2 = D_803E4D40[i].cmd.type16.id;
            id = D_803A8528_7B9BD8[id2].collisionIndex;
            if ((id != 0) && (D_803A8528_7B9BD8[id2].collision == NULL)) {
                s32 idx = (((s16) id - offset));
                func_8031C3C0_72DA70(((Collision*)gFramebuffer) + idx, id);
            }

            if (0) {};

        }
    }

    func_8031C32C_72D9DC();
    func_802963D0_6A7A80((s32) D_80162658);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031C48C_72DB3C.s")
#endif
