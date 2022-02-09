#include <ultra64.h>
#include "common.h"

#include "aidata.h"

// animal X vs animal Y
s16 func_802EA3E0_6FBA90(u16 X, u16 Y) {
    s16 res;

    s16 Xl;
    s16 Yl;

    u8 pad[0x34];

    SSSV_ASSERT(X >= OB_TYPE_ANIMAL_OFFSET, "../src/aidata.c", 375)
    SSSV_ASSERT(Y >= OB_TYPE_ANIMAL_OFFSET, "../src/aidata.c", 376)
    SSSV_ASSERT(X-OB_TYPE_ANIMAL_OFFSET < AID_MAX_ANIMALS, "../src/aidata.c", 377)
    SSSV_ASSERT(Y-OB_TYPE_ANIMAL_OFFSET < AID_MAX_ANIMALS, "../src/aidata.c", 378)

    Xl = D_803A4B78_7B6228[X - OB_TYPE_ANIMAL_OFFSET];
    Yl = D_803A4B78_7B6228[Y - OB_TYPE_ANIMAL_OFFSET];

    // evo chip behaviour
    if ((Xl == 99) || (Yl == 99) ) {
        return AI_IGNORE;
    }

    // evo shellsuit behaviour
    if ((Xl == 100) || (Yl == 100)) {
        return AI_ATTACK; // attack
    }

    // ignore if biome mis-match
    if ((D_801D9ED8.unk0[(s32)X - OB_TYPE_ANIMAL_OFFSET].biome != D_803F2D70) ||
        (D_801D9ED8.unk0[(s32)Y - OB_TYPE_ANIMAL_OFFSET].biome != D_803F2D70)) {
        return AI_IGNORE;
    }

    switch (D_803F2D70) {
        case EUROPE_BIOME:
            SSSV_ASSERT(Xl < MAX_EUROPE_ANIMALS, "../src/aidata.c", 404)
            SSSV_ASSERT(Yl < MAX_EUROPE_ANIMALS, "../src/aidata.c", 405)
            res = ai_map_europe[Xl][Yl];
            break;
        case ICE_BIOME:
            SSSV_ASSERT(Xl < MAX_ICE_ANIMALS, "../src/aidata.c", 410)
            SSSV_ASSERT(Yl < MAX_ICE_ANIMALS, "../src/aidata.c", 411)
            res = ai_map_ice[Xl][Yl];
            break;
        case DESERT_BIOME:
            SSSV_ASSERT(Xl < MAX_DESERT_ANIMALS, "../src/aidata.c", 416)
            SSSV_ASSERT(Yl < MAX_DESERT_ANIMALS, "../src/aidata.c", 417)
            res = ai_map_desert[Xl][Yl];
            break;
        case JUNGLE_BIOME:
            SSSV_ASSERT(Xl < MAX_JUNGLE_ANIMALS, "../src/aidata.c", 422)
            SSSV_ASSERT(Yl < MAX_JUNGLE_ANIMALS, "../src/aidata.c", 423)
            res = ai_map_jungle[Xl][Yl];
            break;
        default:
            SSSV_ASSERT(FALSE, "../src/aidata.c", 428)
            break;
    }

    return res;
}
