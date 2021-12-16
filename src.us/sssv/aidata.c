#include <ultra64.h>
#include "common.h"


s16 func_802EA3E0_6FBA90(u16 X, u16 Y) {
    s16 sp5E;

    s16 Xl;
    s16 Yl;

    u8 pad[0x34];

    SSSV_ASSERT(X >= OB_TYPE_ANIMAL_OFFSET, "../src/aidata.c", 375)
    SSSV_ASSERT(Y >= OB_TYPE_ANIMAL_OFFSET, "../src/aidata.c", 376)
    SSSV_ASSERT(X-OB_TYPE_ANIMAL_OFFSET < AID_MAX_ANIMALS, "../src/aidata.c", 377)
    SSSV_ASSERT(Y-OB_TYPE_ANIMAL_OFFSET < AID_MAX_ANIMALS, "../src/aidata.c", 378)

    Xl = D_803A4B78_7B6228[X - OB_TYPE_ANIMAL_OFFSET];
    Yl = D_803A4B78_7B6228[Y - OB_TYPE_ANIMAL_OFFSET];

    if ((Xl == 99) || (Yl == 99) ){
        return 0;
    }
    if ((Xl == 100) || (Yl == 100)) {
        return 2;
    }

    if ((D_801D9ED8.unk0[(s32)X - OB_TYPE_ANIMAL_OFFSET].unkD6 != D_803F2D70) ||
        (D_801D9ED8.unk0[(s32)Y - OB_TYPE_ANIMAL_OFFSET].unkD6 != D_803F2D70)) {
        return 0;
    }

    switch (D_803F2D70) {
        case EUROPE_BIOME:
            SSSV_ASSERT(Xl < MAX_EUROPE_ANIMALS, "../src/aidata.c", 404)
            SSSV_ASSERT(Yl < MAX_EUROPE_ANIMALS, "../src/aidata.c", 405)
            sp5E = D_803A48C0_7B5F70[Xl*MAX_EUROPE_ANIMALS + Yl];
            break;
        case ICE_BIOME:
            SSSV_ASSERT(Xl < MAX_ICE_ANIMALS, "../src/aidata.c", 410)
            SSSV_ASSERT(Yl < MAX_ICE_ANIMALS, "../src/aidata.c", 411)
            sp5E = D_803A4ABC_7B616C[Xl*MAX_ICE_ANIMALS + Yl];
            break;
        case DESERT_BIOME:
            SSSV_ASSERT(Xl < MAX_DESERT_ANIMALS, "../src/aidata.c", 416)
            SSSV_ASSERT(Yl < MAX_DESERT_ANIMALS, "../src/aidata.c", 417)
            sp5E = D_803A4B38_7B61E8[Xl * MAX_DESERT_ANIMALS + Yl];
            break;
        case JUNGLE_BIOME:
            SSSV_ASSERT(Xl < MAX_JUNGLE_ANIMALS, "../src/aidata.c", 422)
            SSSV_ASSERT(Yl < MAX_JUNGLE_ANIMALS, "../src/aidata.c", 423)
            sp5E = D_803A4A2C_7B60DC[Xl * MAX_JUNGLE_ANIMALS + Yl];
            break;
        default:
            SSSV_ASSERT(FALSE, "../src/aidata.c", 428)
            break;
    }

    return sp5E;
}
