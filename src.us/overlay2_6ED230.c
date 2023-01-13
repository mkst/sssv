#include <ultra64.h>
#include "common.h"


// hurt animal noises
s16 D_803A6470_7B7B20[88] = { // FIXME: should be 68
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_DOG_HURT,       // 4 RACING_DOG
    SFX_DOG_HURT,       // 5 FLYING_DOG
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_BEAR_HURT,      // 13 KING_RAT!?
    SFX_PARROT_HURT,    // 14 PARROT
    SFX_NONE,
    SFX_NONE,
    SFX_MOUSE_HURT,     // 17 HARD_MOUSE
    SFX_MOUSE_HURT,     // 18 RACING_MOUSE
    SFX_BIRD_HURT,      // 19 VULTURE
    SFX_MOUSE_HURT,     // 20 MOUSE2
    SFX_MOUSE_HURT,     // 21 HELI_MOUSE
    SFX_BEAR_HURT,      // 22 BEAR
    SFX_BEAR_HURT,      // 23 CRAZY_BEAR
    SFX_BEAR_HURT,      // 24 MYSTERY_BEAR
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_DOG_HURT,       // 31 DOG
    SFX_NONE,
    SFX_SHEEP_HURT,     // 33 SHEEP
    SFX_SHEEP_HURT,     // 34 RAM
    SFX_SHEEP_HURT,     // 35 SPRINGY_THINGY
    SFX_SHEEP_HURT,     // 36 SPRINGY_RAM
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_BIRD_HURT,      // 43 CROW
    SFX_NONE,
    SFX_BIRD_HURT,      // 45 VULTURE2
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_DOG_HURT,       // 57 HYENA
    SFX_DOG_HURT,       // 58 HYENA_BIKER
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    SFX_NONE,
    0,
};

s16 D_803A6520_7B7BD0[88] = {
    0x00ff, 0x0000, 0x0000, 0x0000, 0x5000, 0x5000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x5000, 0x0000, 0x7000, 0x0000,
    0x5000, 0x5000, 0x5000, 0x5000, 0x5000, 0x5000, 0x5000, 0x5000,
    0x5000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5000,
    0x0000, 0x5000, 0x5000, 0x5000, 0x5000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x5000, 0x0000, 0x5000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x5000, 0x5000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

void func_802DBB80_6ED230(u16 arg0) {
    u16 tmp = D_803D5544 - D_803D552C->unk334;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }
    if (tmp == 1) {
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }

    if (((tmp << 7) / arg0) < 17) {
        D_803F2ECC = ((tmp << 7) / arg0) * 2;
    } else if (((tmp << 7) / arg0) < 97) {
        D_803F2ECC = 32;
    } else {
        D_803F2ECC = 128 - ((tmp << 7) / arg0);
    }
}

void func_802DBCDC_6ED38C(u16 arg0) {
    s32 phi_v1;
    u16 tmp;

    tmp = D_803D5544 - D_803D552C->unk334;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }
    if (tmp == 1) {
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }

    if (((tmp << 7) / arg0) < 16) {
        phi_v1 = ((tmp << 7) / arg0) << 11;
    } else {
        phi_v1 = D_80152C78[((s16)((((tmp << 7) / arg0) -16) << 2) + 64) & 0xFF] / (((tmp << 7) / arg0) >> 4);
    }
    D_803F2EB0 = D_803F2EB0 + phi_v1;
    D_803F2EB4 = D_803F2EB4 - phi_v1;
    D_803F2EB8 = D_803F2EB8 + phi_v1;
    if (D_803F2EB0 < 1024) {
        D_803F2EB0 = 1024;
    }
    if (D_803F2EB4 < 1024) {
        D_803F2EB4 = 1024;
    }
    if (D_803F2EB8 < 1024) {
        D_803F2EB8 = 1024;
    }
}

void func_802DBED8_6ED588(u16 arg0) {
    s32 phi_v1;
    u16 tmp;

    tmp = D_803D5544 - D_803D552C->unk334;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }
    if (tmp == 1) {
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }

    if (((tmp << 7) / arg0) < 16) {
        phi_v1 = ((tmp << 7) / arg0) << 11;
    } else {
        phi_v1 = D_80152C78[((s16)((((tmp << 7) / arg0) -16) << 2) + 64) & 0xFF] / (((tmp << 7) / arg0) >> 4);
    }
    D_803F2EB0 = D_803F2EB0 - phi_v1;
    D_803F2EB4 = D_803F2EB4 + phi_v1;
    D_803F2EB8 = D_803F2EB8 + phi_v1;
    if (D_803F2EB0 < 1024) {
        D_803F2EB0 = 1024;
    }
    if (D_803F2EB4 < 1024) {
        D_803F2EB4 = 1024;
    }
    if (D_803F2EB8 < 1024) {
        D_803F2EB8 = 1024;
    }
}

void func_802DC0D4_6ED784(u16 arg0) {
    s32 temp_t8;
    u16 ticks_remaining;

    ticks_remaining = D_803D5544 - D_803D552C->unk334;
    if (arg0 < ticks_remaining) {
        D_803D552C->unk364 = 0;
        return;
    }

    if (ticks_remaining == 1) {
        switch (D_803D5524->unk9C) {
        case PARROT:
        case PARROT_ATTACKING:
        case TORTOISE_TANK:
        case RACING_TORTOISE:
        case TORTOISE_TANK_DEFENDING:
            break;
        case MOUSE:
        case HARD_MOUSE:
        case RACING_MOUSE:
        case VULTURE:
        case MOUSE2:
        case HELI_MOUSE:
        case BEAR:
        case CRAZY_BEAR:
        case MYSTERY_BEAR:
        case SEAGULL2:
        case RACING_FOX:
        default:
            play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            break;
        case RACING_TORTOISE_DEFENDING:
            break;
        }
    }

    temp_t8 = (-D_80152C78[((s16)(((ticks_remaining << 7) / arg0) << 2) + 64) & 0xFF] * (128 - ((ticks_remaining << 7) / arg0))) >> 7;
    D_803F2EB0 += temp_t8;
    D_803F2EB4 += temp_t8;
    D_803F2EB8 += temp_t8;

    if (D_803F2EB0 < 1024) {
        D_803F2EB0 = 1024;
    }
    if (D_803F2EB4 < 1024) {
        D_803F2EB4 = 1024;
    }
    if (D_803F2EB8 < 1024) {
        D_803F2EB8 = 1024;
    }
}

void func_802DC2AC_6ED95C(u16 arg0) {
    s32 temp_t8;
    u16 ticks_remaining;

    ticks_remaining = (D_803D5544 - D_803D552C->unk334);
    if (arg0 < ticks_remaining) {
        D_803D552C->unk364 = 0;
        return;
    }
    temp_t8 = (D_80152C78[(s16) ((ticks_remaining << 7) / arg0) & 0xFF] / (((ticks_remaining << 7) / arg0) + 16)) << 5;
    D_803F2EB0 += temp_t8;
    D_803F2EB4 += temp_t8;
    D_803F2EB8 -= temp_t8;
    if (D_803F2EB0 < 1024) {
        D_803F2EB0 = 1024;
    }
    if (D_803F2EB4 < 1024) {
        D_803F2EB4 = 1024;
    }
    if (D_803F2EB8 < 1024) {
        D_803F2EB8 = 1024;
    }
}

// used by lion
void func_802DC3F4_6EDAA4(u16 arg0, s16 *arg1, s16 *arg2) {
    u16 ticks_remaining;
    u16 temp_v0;

    ticks_remaining = D_803D5544 - D_803D552C->unk32A;
    if (ticks_remaining >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
    } else {
        temp_v0 = (ticks_remaining * 128) / arg0;
        if (temp_v0 < 16) {
            D_803F2EB0 = ((temp_v0 * -FTOFIX32(0.5)) / 16) + FTOFIX32(1.0);
            D_803F2EB4 = ((temp_v0 * -FTOFIX32(0.25)) / 16) + FTOFIX32(1.0);
            D_803F2EB8 = ((temp_v0 * FTOFIX32(0.5)) / 16) + FTOFIX32(1.0);
        } else if (temp_v0 < 96) {
            temp_v0 -= 16;
            D_803F2EB0 = ((temp_v0 * FTOFIX32(0.25)) / 80) + FTOFIX32(0.5);
            D_803F2EB4 = ((temp_v0 * FTOFIX32(0.75)) / 80) + FTOFIX32(0.75);
            D_803F2EB8 = ((temp_v0 * -FTOFIX32(0.75)) / 80) + FTOFIX32(1.5);
            *arg1 = (temp_v0 * 32) / 80;
            *arg2 = *arg1 >> 1;
        } else {
            temp_v0 -= 96;
            D_803F2EB0 = ((temp_v0 * FTOFIX32(0.25)) / 32) + FTOFIX32(0.75);
            D_803F2EB4 = ((temp_v0 * -FTOFIX32(0.5)) / 32) + FTOFIX32(1.5);
            D_803F2EB8 = ((temp_v0 * FTOFIX32(0.25)) / 32) + FTOFIX32(0.75);
            *arg1 = 32 - temp_v0;
            *arg2 = *arg1 >> 1;
        }
    }
}

// used by hippo and camel (spit?)
void func_802DC6A4_6EDD54(u16 arg0) {
    u16 temp_t9;
    u16 phi_v0;

    temp_t9 = (D_803D5544 - D_803D552C->unk32A);
    if (temp_t9 >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
    } else {
        phi_v0 = (temp_t9 << 7) / arg0;
        if (phi_v0 > 96) {
            phi_v0 = ((96 * 4) - (phi_v0 * 3));
        }
        D_803F2EB0 = ((((D_803F2EB0 >> 8) * phi_v0) / 96) << 6) + D_803F2EB0;
        D_803F2EB4 -= (((D_803F2EB0 >> 8) * phi_v0) / 96) << 6;
        D_803F2EB8 = ((((D_803F2EB8 >> 8) * phi_v0) / 96) << 6) + D_803F2EB8;
    }
}

#ifdef NON_MATCHING
// *almost* just regalloc
void func_802DC854_6EDF04(s16 arg0, u16 arg1) {
    s16 phi_v1;
    u16 temp_t0;

    temp_t0 = (arg0 << 7) / arg1;

    if (temp_t0 < 96) {
        phi_v1 = (temp_t0 * 4) / 3;
    } else {
        phi_v1 = (-temp_t0 * 4);
        phi_v1 += 512;
         // + 512;
    }

    D_803F2EBC = D_803F2EBC + (phi_v1 * (D_80152C78[(temp_t0 << 3) & 0xFF] >> 7));
    D_803F2EC0 = D_803F2EC0 + (phi_v1 * (D_80152C78[(temp_t0 << 2) & 0xFF] >> 7));
    D_803F2EC4 = D_803F2EC4 - (phi_v1 * (D_80152C78[(temp_t0 << 3) & 0xFF] >> 7));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DC854_6EDF04.s")
#endif

void func_802DC968_6EE018(u16 arg0, s16 arg1) {
    u16 tmp = D_803D5544 - D_803D552C->unk334;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
    } else {
        D_803F2ED0 = ((D_80152C78[(s16)((tmp << 7) / arg0) & 0xFF] >> 7) * arg1) >> 8;
    }
}

void func_802DCA28_6EE0D8(u16 arg0) {
    u16 tmp = D_803D552C->unk32A - D_803D5544;
    if (D_803D552C->unk32A >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        D_803F2ED8 = (D_80152C78[(s16)((tmp << 7) / arg0) & 0xFF] >> 7) >> 3;
    }
}

void func_802DCAD4_6EE184(u16 arg0) {
    u16 temp_t9 = (D_803D5544 - D_803D552C->unk32A);
    if (temp_t9 >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        D_803F2ED8 = 16 - (((D_80152C78[((s16)((temp_t9 << 8) / arg0) + 64) & 0xFF]) >> 7) >> 4);
    }
}

void func_802DCB90_6EE240(u16 arg0) {
    s16 temp_lo;
    u16 temp_t9;

    temp_t9 = D_803D5544 - D_803D552C->unk32A;
    if (temp_t9 >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        temp_lo = (temp_t9 << 7) / arg0;
        if (temp_lo < 32) {
            D_803F2ED8 = 16 - ((D_80152C78[((s16)(temp_lo << 2) + 64) & 0xFF] >> 7) >> 4);
        } else if (temp_lo < 96) {
            D_803F2ED8 = 32;
        } else {
            D_803F2ED8 = ((D_80152C78[((s16)((temp_lo - 96) << 2) + 64) & 0xFF] >> 7) >> 4) + 16;
        }
    }
}

void func_802DCCAC_6EE35C(u16 arg0) {
    s16 temp_lo;
    u16 temp_t9;

    temp_t9 = D_803D5544 - D_803D552C->unk32A;
    if (temp_t9 >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        temp_lo = (temp_t9 << 7) / arg0;
        if (temp_lo < 32) {
            D_803F2ED8 = temp_lo;
        } else {
            D_803F2ED8 = 32 - ((temp_lo - 32) / 3);
        }
    }
}

#if 0
// a mystery
void func_802DCD70_6EE420(u16 arg0, u8 arg1) {
    s32 temp_t0;
    s32 temp_t6;
    u16 remaining_ticks;
    u32 phi_t1;

    remaining_ticks = D_803D5544 - D_803D552C->unk334;

    phi_t1 = (remaining_ticks << 0xA) / arg0;
    if (phi_t1 > 512) {
        phi_t1 = 1024 - phi_t1;
    }

    if (phi_t1 < 325) {
        D_803F2EB0 = ((D_80152C78[(s16)phi_t1 & 0xFF] >> 9) * phi_t1) + FTOFIX32(1.0);

        D_803F2EB4 = ((D_80152C78[((s16)(phi_t1 << 1) + 64) & 0xFF] >> 9) * phi_t1) + FTOFIX32(1.0);

        D_803F2EB8 = D_80152C78[(s16)((phi_t1 * 3) - 30) & 0xFF] >> 9;
        D_803F2EB8 = FTOFIX32(1.0) - (D_803F2EB8 * phi_t1);
    } else if (phi_t1 < 375) {
        temp_t0 = (phi_t1 - 325) << 0xA;
        D_803F2EB0 = ((((D_80152C78[(s16)phi_t1 & 0xFF]) >> 9) * 325) - temp_t0) + FTOFIX32(1.0);

        D_803F2EB4 = ((((D_80152C78[(s16)((phi_t1 << 1) + 64) & 0xFF]) >> 9) * 325) - temp_t0);
        D_803F2EB4 += FTOFIX32(1.0);

        D_803F2EB8 = (FTOFIX32(1.0) - ((D_80152C78[(s16)((phi_t1 * 3) - 30) & 0xFF] >> 9) * phi_t1)) + ((phi_t1 - 325) << 12);
        D_803F2EDB = 0;
    } else {
        D_803F2EDB = 0;
        D_803F2EDA = 0;
        D_803F2EB4 = 0;
        D_803F2EB8 = 0;
        D_803F2EB0 = 0;
    }
    if ((arg1 != 0) && (remaining_ticks >= (arg0 >> 1))) {
        D_803D552C->unk334 += 1;
    }
    if (remaining_ticks >= arg0) {
        D_803D552C->unk364 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DCD70_6EE420.s")
#endif

void func_802DD004_6EE6B4(u16 arg0) {
    u16 tmp = D_803D5544 - D_803D552C->unk334;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
    }
}

// file split?

void func_802DD040_6EE6F0(s32 arg0) {
    s16 i;
    for (i = 0; i < 120; i++) {
        D_803E00C0[i].unk2E = 0;
    }
    D_803E1B00 = 0;
    D_803E1B02 = 1;
}

s16 func_802DD090_6EE740(s16 numSegments, s32 length, u8 arg2, s8 arg3, s8 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, u8 arg9, s32 argA, s32 argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11) {
    u16 i;
    s32 res;

    if (((D_803E1B00 + numSegments) < 1000) && (D_803E1B02 < 120)) {
        D_803E00C0[D_803E1B02].unk14 = numSegments;
        D_803E00C0[D_803E1B02].unk16 = D_803E1B00;
        D_803E00C0[D_803E1B02].unk1C = ((numSegments + 1) * length) >> 0x10;
        D_803E00C0[D_803E1B02].unk2E = arg3;
        D_803E00C0[D_803E1B02].unk2F = arg4;
        D_803E00C0[D_803E1B02].unk32 = arg8;
        D_803E00C0[D_803E1B02].unk33 = arg9;
        D_803E00C0[D_803E1B02].unk0 = argA;
        D_803E00C0[D_803E1B02].unk4 = argB;
        D_803E00C0[D_803E1B02].unk8 = argC;
        D_803E00C0[D_803E1B02].unkA = argD;
        D_803E00C0[D_803E1B02].unkC = argE;
        D_803E00C0[D_803E1B02].unk18 = length;
        D_803E00C0[D_803E1B02].unk20 = arg5;
        D_803E00C0[D_803E1B02].unk24 = arg6;
        D_803E00C0[D_803E1B02].unk28 = arg7;
        D_803E00C0[D_803E1B02].unkE = argF;
        D_803E00C0[D_803E1B02].unk10 = arg10;
        D_803E00C0[D_803E1B02].unk12 = arg11;
        D_803E00C0[D_803E1B02].unk2C = 0;
        D_803E00C0[D_803E1B02].unk34 = 1;

        for (i = 0; i < numSegments; i++) {
            D_803DA300[D_803E1B00 + i].unk0 = arg5;
            D_803DA300[D_803E1B00 + i].unk4 = arg6;
            D_803DA300[D_803E1B00 + i].unk8 = arg7;
            D_803DA300[D_803E1B00 + i].unkC = 0;
            D_803DA300[D_803E1B00 + i].unk10 = 0;
            D_803DA300[D_803E1B00 + i].unk14 = 0;

            if (arg2) {
                arg7 += length;
            } else {
                arg7 -= length;
            }
        }
        D_803E1B00 += numSegments;
        return D_803E1B02++;
    } else {
        return 0;
    }
}

// dynamic tail related? used by kangaroo, husky, lion, elephant, mouse, scorpion and rat
void func_802DD244_6EE8F4(s16 arg0, struct118 *arg1) {
    struct051 *temp_s1;
    struct088 *var_t1;
    s16 i;

    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_s2;
    s32 var_s7;
    s32 var_a0;

    temp_s1 = &D_803E00C0[arg0];
    var_t1 = &D_803DA300[temp_s1->unk16];

    var_s3 = temp_s1->unk20;
    var_s4 = temp_s1->unk24;
    var_s5 = temp_s1->unk28;

    // iterate over each segment
    for (i = 0; i < temp_s1->unk14; i++) {

        var_t1[i].unk0 = var_s3; // startx?
        var_t1[i].unk4 = var_s4; // startz?
        var_t1[i].unk8 = var_s5; // starty?
        var_t1[i].unkC = 0;
        var_t1[i].unk10 = 0;
        var_t1[i].unk14 = 0;

        // whilst it's not the final segment
        if (i < (temp_s1->unk14 - 1)) {
            var_s6 = (( arg1[i+1].unk0 * (D_80152C78[(temp_s1->unk2C + 0x40) & 0xFF] >> 7)) + (arg1[i+1].unk4 * (D_80152C78[temp_s1->unk2C & 0xFF] >> 7))) >> 8;
            var_s2 = ((-arg1[i+1].unk0 * (D_80152C78[temp_s1->unk2C & 0xFF] >> 7)) + (arg1[i+1].unk4 * (D_80152C78[(temp_s1->unk2C + 0x40) & 0xFF] >> 7))) >> 8;
            var_s7 = arg1[i+1].unk8;

            var_a0 = sqrtf(SQ((f32)var_s6) + SQ((f32)var_s2) + SQ((f32)var_s7));
            if (var_a0 < FTOFIX32(0.0625)) {
                var_s2 = FTOFIX32(1.0);
                var_a0 = FTOFIX32(1.0);
            }
        }

        var_s3 += (var_s6 * (temp_s1->unk18 >> 8)) / (var_a0 >> 8);
        var_s4 += (var_s2 * (temp_s1->unk18 >> 8)) / (var_a0 >> 8);
        var_s5 += (var_s7 * (temp_s1->unk18 >> 8)) / (var_a0 >> 8);
    }
}

#if 0
// miles away
void func_802DD548_6EEBF8(s16 arg0, struct118 *arg1, s16 arg2, s16 arg3) {

    Animal *temp_v0;
    f32 temp_f0_2;
    s16 temp_a0;
    s16 i;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_t6;
    s32 temp_t8_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 var_t4;

    struct051 *temp_fp;
    struct088 *var_t5;

    if (D_803F2D10.unk0 == 0) {
        temp_fp = &D_803E00C0[arg0];
        var_t5 = &D_803DA300[temp_fp->unk16];

        if (temp_fp->unk4 != NULL) {
            temp_fp->unk20 = temp_fp->unk4->xPos.w + (temp_fp->unkE << 0x10);
            temp_fp->unk24 = temp_fp->unk4->zPos.w + (temp_fp->unk10 << 0x10);
            temp_fp->unk28 = temp_fp->unk4->yPos.w + (temp_fp->unk12 << 0x10);
        }
        var_t5->unk0 = temp_fp->unk20;
        var_t5->unk4 = temp_fp->unk24;
        var_t5->unk8 = temp_fp->unk28;

        if (arg3 == 1) {
            var_t4 = MAX(temp_fp->unk28, ((D_803C0740[temp_fp->unk20 >> 0x16][temp_fp->unk24 >> 0x16].unk6 * 4) - 0x20) << 0x10);
        }

        var_s5 = temp_fp->unk20;
        var_s6 = temp_fp->unk24;
        var_s7 = temp_fp->unk28;

        for (i = 1; i < temp_fp->unk14; i++) {
            temp_t6 = D_80152C78[temp_fp->unk2C & 0xFF] >> 7;
            temp_t8_2 = D_80152C78[(temp_fp->unk2C + 0x40) & 0xFF] >> 7;

            temp_s2 = var_s5 - ((((arg1[i].unk4 * temp_t6) + (arg1[i].unk0 * temp_t8_2)) >> 8) + var_t5[i].unk0 + ((var_t5[i].unkC * arg2) / 256));

            var_a2 = arg1[i].unk8 + var_t5[i].unk8 + ((var_t5[i].unk14 * arg2) / 256);
            if ((arg3 == 1) && (var_t4 < var_a2)) {
                var_a2 = var_t4;
            }

            temp_s3 = var_s6 - (((s32) ((temp_t8_2 * arg1[i].unk4) + (-arg1[i].unk0 * temp_t6)) >> 8) + var_t5[i].unk4 + ((var_t5[i].unk10 * arg2) / 256));
            temp_s4 = var_s7 - var_a2;

            temp_f0_2 = sqrtf(SQ((f32)temp_s2) + SQ((f32)temp_s3) + SQ((f32)temp_s4));
            if (temp_f0_2 != 0.0f) {
                var_a1 = temp_fp->unk18 / (s32) (temp_f0_2 / 1024.0);
            } else {
                var_a1 = 1;
            }
            var_s5 = var_s5 - ((temp_s2 * var_a1) >> 0xA);
            var_s6 = var_s6 - ((temp_s3 * var_a1) >> 0xA);
            var_s7 = var_s7 - ((temp_s4 * var_a1) >> 0xA);

            var_t5[i].unkC = var_s5 - var_t5[i].unk0;
            var_t5[i].unk10 = var_s6 - var_t5[i].unk4;
            var_t5[i].unk14 = var_s7 - var_t5[i].unk8;

            var_t5[i].unk0 = var_s5;
            var_t5[i].unk4 = var_s6;
            var_t5[i].unk8 = var_s7;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD548_6EEBF8.s")
#endif

#if 0
// long way away
void func_802DD994_6EF044(s16 arg0, struct118 *arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 sp1E6;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    // padding?
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    // padding ? // sp170;
    s32 sp130[16];
    s32 spF0[16];
    s32 spB0[16];

    f32 sp88;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;

    f32 temp_f2;
    f32 var_f12;
    f32 var_f14;
    f32 var_f16;
    f32 var_f2;
    f32 temp_f0_10;
    f64 var_f12_2;

    s16 i;
    s16 var_s1;

    s32 temp_s2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_t0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;

    struct051 *temp_v0;
    struct088 *var_t5;

    temp_v0 = &D_803E00C0[arg0];
    var_t5 = &D_803DA300[temp_v0->unk16];

    if (temp_v0->unk4 != NULL) {
        temp_v0->unk20 = temp_v0->unk4->xPos.w + (temp_v0->unkE << 0x10);
        temp_v0->unk24 = temp_v0->unk4->zPos.w + (temp_v0->unk10 << 0x10);
        temp_v0->unk28 = temp_v0->unk4->yPos.w + (temp_v0->unk12 << 0x10);
    }

    var_t5->unk0 = temp_v0->unk20;
    var_t5->unk4 = temp_v0->unk24;
    var_t5->unk8 = temp_v0->unk28;

    var_s2 = temp_v0->unk20;
    var_s3 = temp_v0->unk24;
    var_s4 = temp_v0->unk28;

    for (i = 1; i < arg4; i++) {
        s32 a = var_t5[i].unk0;
        s32 b = var_t5[i].unk4;
        s32 c = var_t5[i].unk8;

        sp130[i] = a; //  var_t5[i].unk0;
        spF0[i]  = b; // var_t5[i].unk4;
        spB0[i]  = c; // var_t5[i].unk8;

        temp_s5 = var_s2 - ((((D_80152C78[temp_v0->unk2C & 0xFF] * arg1[i].unk4) + (arg1[i].unk0 * D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF])) >> 0xF) + a + ((var_t5[i].unkC * arg2) / 256));
        temp_s6 = var_s3 - ((((D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF] * arg1[i].unk4) + (-arg1[i].unk0 * D_80152C78[temp_v0->unk2C & 0xFF])) >> 0xF) + b + ((var_t5[i].unk10 * arg2) / 256));
        temp_s7 = var_s4 - (arg1[i].unk8 + c + ((var_t5[i].unk14 * arg2) / 256));

        temp_f0 = sqrtf(SQ((f32)temp_s5) + SQ((f32)temp_s6) + SQ((f32)temp_s7));
        if (temp_f0 != 0.0f) {
            var_v1 = temp_v0->unk18 / (s32) (temp_f0 / 1024.0);
        } else {
            var_v1 = 1;
        }

        var_s2 -= (temp_s5 * var_v1) >> 0xA;
        var_s3 -= (temp_s6 * var_v1) >> 0xA;
        var_s4 -= (temp_s7 * var_v1) >> 0xA;

        var_t5[i].unkC = var_s2 - var_t5[i].unk0;
        var_t5[i].unk10 = var_s3 - var_t5[i].unk4;
        var_t5[i].unk14 = var_s4 - var_t5[i].unk8;

        var_t5[i].unk0 = var_s2;
        var_t5[i].unk4 = var_s3;
        var_t5[i].unk8 = var_s4;
    }

    if (temp_v0->unk32 & 2) {
        if (temp_v0->unk32 & 1) {
            var_t5[arg4].unk10 = (var_t5[arg4].unk10 * 0xF) >> 4;
        } else {
            var_t5[arg4].unkC = (var_t5[arg4].unkC * 0xF) >> 4;
        }
    }

    sp194 = ((((D_80152C78[temp_v0->unk2C & 0xFF] * arg1[arg4].unk4) + ( arg1[arg4].unk0 * D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF])) >> 0xF) + var_t5[arg4].unk0 + ((var_t5[arg4].unkC * arg3) / 256));
    sp190 = ((((D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF] * arg1[arg4].unk4) + (-arg1[arg4].unk0 * D_80152C78[temp_v0->unk2C & 0xFF])) >> 0xF) + var_t5[arg4].unk4 + ((var_t5[arg4].unk10 * arg3) / 256));
    sp18C = arg1[arg4].unk8 + var_t5[arg4].unk8 + ((var_t5[arg4].unk14 * arg3) / 256);

    sp1B8 = sp194 - temp_v0->unk20;
    sp1B4 = sp190 - temp_v0->unk24;
    sp1B0 = sp18C - temp_v0->unk28;

    temp_f0 = sqrtf(SQ(sp1B8) + SQ(sp1B4) + SQ(sp1B0));
    if ((arg4 * temp_v0->unk18) < temp_f0) {
        sp194 = temp_v0->unk20 + (sp1B8 * ((arg4 * temp_v0->unk18) / temp_f0));
        sp190 = temp_v0->unk24 + (sp1B4 * ((arg4 * temp_v0->unk18) / temp_f0));
        sp18C = temp_v0->unk28 + (sp1B0 * ((arg4 * temp_v0->unk18) / temp_f0));
        sp1E6 = 1;
    } else {
        sp1E6 = 0;
    }

    var_s2 = sp194;
    var_s3 = sp190;
    var_s4 = sp18C;

    var_t5[arg4].unkC = var_s2 - (f32) var_t5[arg4].unk0;
    var_t5[arg4].unk10 = var_s3 - (f32) var_t5[arg4].unk4;
    var_t5[arg4].unk14 = var_s4 - (f32) var_t5[arg4].unk8;

    var_t5[arg4].unk0 = var_s2;
    var_t5[arg4].unk4 = var_s3;
    var_t5[arg4].unk8 = var_s4;


    for (i = arg4 + 1; i < temp_v0->unk14; i++) {
        s32 a = var_t5[i].unk0;
        s32 b = var_t5[i].unk4;
        s32 c = var_t5[i].unk8;

        temp_s5 = var_s2 - ((((D_80152C78[temp_v0->unk2C & 0xFF] * arg1[i].unk4) + ( arg1[i].unk0 * D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF])) >> 0xF) + a + ((var_t5[i].unkC * arg2) / 256));
        temp_s6 = var_s3 - ((((D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF] * arg1[i].unk4) + (-arg1[i].unk0 * D_80152C78[temp_v0->unk2C & 0xFF])) >> 0xF) + b + ((var_t5[i].unk10 * arg2) / 256));
        temp_s7 = var_s4 - (arg1[i].unk8 + c + ((var_t5[i].unk14 * arg2) / 256));

        temp_f2 = sqrtf(SQ((f32)temp_s5) + SQ((f32)temp_s6) + SQ((f32)temp_s7));
        if (temp_f2 != 0.0) {
            var_v1 = temp_v0->unk18 / (s32) (temp_f2 / 1024.0);
        } else {
            var_v1 = 1;
        }

        var_s2 -= (temp_s5 * var_v1) >> 0xA;
        var_s3 -= (temp_s6 * var_v1) >> 0xA;
        var_s4 -= (temp_s7 * var_v1) >> 0xA;

        var_t5[i].unkC = var_s2 - var_t5[i].unk0;
        var_t5[i].unk10 = var_s3 - var_t5[i].unk4;
        var_t5[i].unk14 = var_s4 - var_t5[i].unk8;

        var_t5[i].unk0 = var_s2;
        var_t5[i].unk4 = var_s3;
        var_t5[i].unk8 = var_s4;
    }

    if (sp1E6 != 0) {
        var_s1 = 0;
    } else {
        for (var_s1 = arg4 - 1; var_s1 >= 0; var_s1--) {
            temp_f0 = var_t5[var_s1].unk0 - var_t5[arg4].unk0;
            temp_f2 = var_t5[var_s1].unk4 - var_t5[arg4].unk4;
            temp_f14 = var_t5[var_s1].unk8 - var_t5[arg4].unk8;
            if ((sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14)) <= (f32) (temp_v0->unk18 * (arg4 - var_s1)))) {
                break;
            }
        }
    }

    temp_s2 = arg4 - var_s1;

    temp_f2 = var_t5[var_s1].unk0 - var_t5[arg4].unk0;
    temp_f14 = var_t5[var_s1].unk4 - var_t5[arg4].unk4;
    temp_f16 = var_t5[var_s1].unk8 - var_t5[arg4].unk8;

    var_f12 = sqrtf(SQ(temp_f2) + SQ(temp_f14) + SQ(temp_f16));
    if (var_f12 < 1.0) {
        var_f12 = 1.0;
    }

    if (var_f12 < temp_v0->unk18 * temp_s2) {
        var_f2 = temp_f2 / temp_s2;
        var_f14 = temp_f14 / temp_s2;
        var_f16 = temp_f16 / temp_s2;
    } else {
        var_f2 = (temp_v0->unk18 * temp_f2) / var_f12;
        var_f14 = (temp_v0->unk18 * temp_f14) / var_f12;
        var_f16 = (temp_v0->unk18 * temp_f16) / var_f12;
    }

    for (i = arg4 - 1; i > var_s1; i--) {
        var_t5[i].unk0 = var_t5[i+1].unk0 + var_f2;
        var_t5[i].unk4 = var_t5[i+1].unk4 + var_f14;
        var_t5[i].unk8 = var_t5[i+1].unk8 + var_f16;

        var_t5[i].unkC = var_t5[i].unk0 - sp130[i];
        var_t5[i].unk10 = var_t5[i].unk4 - spF0[i];
        var_t5[i].unk14 = var_t5[i].unk8 - spB0[i];
    }

    temp_f0_10 = (ABS(var_t5[arg4].unkC) + ABS(var_t5[arg4].unk10) + ABS(var_t5[arg4].unk14)) / 1310720.0;
    var_f12_2 = MIN(1.0, temp_f0_10 / 2.0);

    func_8032CD70_73E420(
        temp_v0,
        SFX_UNKNOWN_35,
        var_f12_2 * 28672.0,
        0,
        (temp_f0_10 / 1.5) + 0.7,
        var_t5[arg4].unk0 >> 0x10,
        var_t5[arg4].unk4 >> 0x10,
        var_t5[arg4].unk8 >> 0x10);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD994_6EF044.s")
#endif

void func_802DE770_6EFE20(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unkC += arg2;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk10 += arg3;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk14 += arg4;
}

void func_802DE7F4_6EFEA4(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 i;

    for (i = D_803E00C0[arg0].unk16; i < D_803E00C0[arg0].unk16 + D_803E00C0[arg0].unk14; i++) {
        D_803DA300[i].unk0 += arg1;
        D_803DA300[i].unk4 += arg2;
        D_803DA300[i].unk8 += arg3;
    }
}

void func_802DE890_6EFF40(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk0 = arg2;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk4 = arg3;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk8 = arg4;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unkC = arg5;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk10 = arg6;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk14 = arg7;
}

void func_802DE914_6EFFC4(s16 idx, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    struct051 *tmp = &D_803E00C0[idx];
    tmp->unk20 = arg1;
    tmp->unk24 = arg2;
    tmp->unk28 = arg3;
    tmp->unk2C = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DE950_6F0000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802E072C_6F1DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802E3C88_6F5338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802E414C_6F57FC.s")

void func_802E497C_6F602C(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    struct088 *tmp;

    tmp = &D_803DA300[D_803E00C0[arg0].unk16];

    *arg1 = (tmp->unk0 - D_803D5530->xPos.w) >> 14;
    *arg2 = (tmp->unk4 - D_803D5530->zPos.w) >> 14;
    *arg3 = (tmp->unk8 - D_803D5530->yPos.w) >> 14;

    if ((ABS(*arg3) < 100) &&
        (ABS(*arg1) < 100) &&
        (ABS(*arg2) < 100)) {
        *arg3 = 100;
    }
}

void func_802E4A78_6F6128(s16 arg0) {
    D_803E00C0[arg0].unk2F = 1;
    D_803E1B06 = 15;
    D_803E1B08 = arg0;
}

void func_802E4AB8_6F6168(void) {
    s16 i;
    for (i = 0; i < 120; i++) {
        if (D_803E00C0[i].unk2F == 2) {
            D_803E00C0[i].unk2F = 1;
        }
    }
}

// load_dynamic_tail
s32 func_802E4B0C_6F61BC(s16 animalId) {
    switch (animalId) {
    case MOUSE:
    case RACING_MOUSE:
    case MOUSE2:
    case HELI_MOUSE:
    case RAT:
        return func_802DD090_6EE740(6, FTOFIX32(3.125), 1, 3, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case KING_RAT:
        return func_802DD090_6EE740(6, FTOFIX32(6.25), 1, 32, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case HUSKY:
    case SKI_HUSKY:
        return func_802DD090_6EE740(4, FTOFIX32(6.875), 1, 11, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case CRAZY_HUSKY:
        return func_802DD090_6EE740(4, FTOFIX32(6.875), 1, 12, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case POGO_KANGAROO:
    case BOXING_KANGAROO:
        return func_802DD090_6EE740(4, FTOFIX32(15.0), 1, 13, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case SCORPION:
        return func_802DD090_6EE740(7, FTOFIX32(5.90625), 1, 14, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case ELEPHANT:
        return func_802DD090_6EE740(5, FTOFIX32(16.40625), 1, 16, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case LION:
        return func_802DD090_6EE740(4, FTOFIX32(15.625), 1, 35, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    default:
        return 0;
    }
}

void func_802E4EB4_6F6564(s16 arg0) {
    if (arg0 != 0) {
        D_803E00C0[arg0].unk2E = 0;
    }
    if ((D_803E1B02 >= 2) && D_803E00C0[D_803E1B02 - 1].unk2E == 0) {
        D_803E1B02--;
    }
}

void func_802E4F20_6F65D0(s32 img) {
    gDPSetTextureImage(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, img);
    gDPTileSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(D_801D9E88++);
    gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 1024, 0);
    gDPTileSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
}
