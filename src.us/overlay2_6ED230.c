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

// ESA: func_800A1754
void func_802DBB80_6ED230(u16 arg0) {
    u16 ticks_remaining = D_803D5544 - D_803D552C->attackTimer;
    if (arg0 < ticks_remaining) {
        D_803D552C->unk364 = 0;
        return;
    }
    if (ticks_remaining == 1) {
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
    }

    if (((ticks_remaining << 7) / arg0) < 17) {
        D_803F2ECC = ((ticks_remaining << 7) / arg0) * 2;
    } else if (((ticks_remaining << 7) / arg0) < 97) {
        D_803F2ECC = 32;
    } else {
        D_803F2ECC = 128 - ((ticks_remaining << 7) / arg0);
    }
}

// ESA: func_800A186C
void func_802DBCDC_6ED38C(u16 arg0) {
    s32 phi_v1;
    u16 tmp;

    tmp = D_803D5544 - D_803D552C->attackTimer;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }
    if (tmp == 1) {
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
    }

    if (((tmp << 7) / arg0) < 16) {
        phi_v1 = ((tmp << 7) / arg0) << 11;
    } else {
        phi_v1 = COS((((tmp << 7) / arg0) -16) << 2) / (((tmp << 7) / arg0) >> 4);
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

// ESA: func_800A1A20
void func_802DBED8_6ED588(u16 arg0) {
    s32 phi_v1;
    u16 ticks_remaining;

    ticks_remaining = D_803D5544 - D_803D552C->attackTimer;
    if (arg0 < ticks_remaining) {
        D_803D552C->unk364 = 0;
        return;
    }
    if (ticks_remaining == 1) {
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
    }

    if (((ticks_remaining << 7) / arg0) < 16) {
        phi_v1 = ((ticks_remaining << 7) / arg0) << 11;
    } else {
        phi_v1 = COS((((ticks_remaining << 7) / arg0) -16) << 2) / (((ticks_remaining << 7) / arg0) >> 4);
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

// ESA: func_800A1BD4
void func_802DC0D4_6ED784(u16 arg0) {
    s32 temp_t8;
    u16 ticks_remaining;

    ticks_remaining = D_803D5544 - D_803D552C->attackTimer;
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
            play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            break;
        case RACING_TORTOISE_DEFENDING:
            break;
        }
    }

    temp_t8 = (-COS(((ticks_remaining << 7) / arg0) << 2) * (128 - ((ticks_remaining << 7) / arg0))) >> 7;
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

// ESA: func_800A1D78
void func_802DC2AC_6ED95C(u16 arg0) {
    s32 temp_t8;
    u16 ticks_remaining;

    ticks_remaining = (D_803D5544 - D_803D552C->attackTimer);
    if (arg0 < ticks_remaining) {
        D_803D552C->unk364 = 0;
        return;
    }
    temp_t8 = (SIN((ticks_remaining << 7) / arg0) / (((ticks_remaining << 7) / arg0) + 16)) << 5;
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

// ESA: func_800A1E80
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

// ESA: func_800A2074
// used by hippo and camel (spit?)
void func_802DC6A4_6EDD54(u16 arg0) {
    u16 ticks_remaining;
    u16 phi_v0;

    ticks_remaining = D_803D5544 - D_803D552C->unk32A;
    if (ticks_remaining >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
    } else {
        phi_v0 = (ticks_remaining << 7) / arg0;
        if (phi_v0 > 96) {
            phi_v0 = ((96 * 4) - (phi_v0 * 3));
        }
        D_803F2EB0 = D_803F2EB0 + ((((D_803F2EB0 >> 8) * phi_v0) / 96) << 6);
        D_803F2EB4 = D_803F2EB4 - ((((D_803F2EB0 >> 8) * phi_v0) / 96) << 6);
        D_803F2EB8 = D_803F2EB8 + ((((D_803F2EB8 >> 8) * phi_v0) / 96) << 6);
    }
}

// ESA: func_800A21B0
void func_802DC854_6EDF04(s16 arg0, u16 arg1) {
    s16 phi_v1;
    u16 temp_t0;

    temp_t0 = (arg0 << 7) / arg1;
    if (temp_t0 < 96) {
        phi_v1 = (temp_t0 * 4) / 3;
    }
    else {
        phi_v1 = (128 - temp_t0) * 4;
    }

    D_803F2EBC = D_803F2EBC + (phi_v1 * (SIN(temp_t0 << 3) >> 7));
    D_803F2EC0 = D_803F2EC0 + (phi_v1 * (SIN(temp_t0 << 2) >> 7));
    D_803F2EC4 = D_803F2EC4 - (phi_v1 * (SIN(temp_t0 << 3) >> 7));
}

// ESA: func_800A22B0
void func_802DC968_6EE018(u16 arg0, s16 arg1) {
    u16 ticks_remaining = D_803D5544 - D_803D552C->attackTimer;
    if (arg0 < ticks_remaining) {
        D_803D552C->unk364 = 0;
    } else {
        D_803F2ED0 = ((SIN((ticks_remaining << 7) / arg0) >> 7) * arg1) >> 8;
    }
}

void func_802DCA28_6EE0D8(u16 arg0) {
    u16 ticks_remaining = D_803D552C->unk32A - D_803D5544;
    if (D_803D552C->unk32A >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        D_803F2ED8 = (SIN((ticks_remaining << 7) / arg0) >> 7) >> 3;
    }
}

void func_802DCAD4_6EE184(u16 arg0) {
    u16 ticks_remaining = D_803D5544 - D_803D552C->unk32A;
    if (ticks_remaining >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        D_803F2ED8 = 16 - ((COS((ticks_remaining << 8) / arg0) >> 7) >> 4);
    }
}

void func_802DCB90_6EE240(u16 arg0) {
    s16 temp_lo;
    u16 ticks_remaining;

    ticks_remaining = D_803D5544 - D_803D552C->unk32A;
    if (ticks_remaining >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        temp_lo = (ticks_remaining << 7) / arg0;
        if (temp_lo < 32) {
            D_803F2ED8 = 16 - ((COS(temp_lo << 2) >> 7) >> 4);
        } else if (temp_lo < 96) {
            D_803F2ED8 = 32;
        } else {
            D_803F2ED8 = ((COS((temp_lo - 96) << 2) >> 7) >> 4) + 16;
        }
    }
}

// ESA: func_800A2344
void func_802DCCAC_6EE35C(u16 arg0) {
    s16 temp_lo;
    u16 ticks_remaining;

    ticks_remaining = D_803D5544 - D_803D552C->unk32A;
    if (ticks_remaining >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
        D_803F2ED8 = 0;
    } else {
        temp_lo = (ticks_remaining << 7) / arg0;
        if (temp_lo < 32) {
            D_803F2ED8 = temp_lo;
        } else {
            D_803F2ED8 = 32 - ((temp_lo - 32) / 3);
        }
    }
}

// ESA: func_800A23EC
void func_802DCD70_6EE420(u16 arg0, u8 arg1) {
    s32 temp_t0;
    u16 ticks_remaining;
    u32 phi_t1;

    ticks_remaining = D_803D5544 - D_803D552C->attackTimer;

    phi_t1 = (ticks_remaining << 0xA) / arg0;
    if (phi_t1 > 512) {
        phi_t1 = 1024 - phi_t1;
    }

    if (phi_t1 < 325) {
        D_803F2EB0 = FTOFIX32(1.0) + ((SIN(phi_t1) >> 9) * phi_t1);
        D_803F2EB4 = FTOFIX32(1.0) + ((COS(phi_t1 * 2) >> 9) * phi_t1);
        D_803F2EB8 = FTOFIX32(1.0) - ((SIN((phi_t1 * 3) - 30) >> 9) * phi_t1);
    } else if (phi_t1 < 375) {
        temp_t0 = (phi_t1 - 325);

        D_803F2EB0 = FTOFIX32(1.0) + (((SIN(phi_t1)) >> 9) * 325) - (temp_t0 << 0xA);
        D_803F2EB4 = FTOFIX32(1.0) + (((COS(phi_t1 * 2)) >> 9) * 325) - (temp_t0 << 0xA);
        D_803F2EB8 = FTOFIX32(1.0) - (((SIN((phi_t1 * 3) - 30) >> 9) * phi_t1)) + (temp_t0 << 12);

        D_803F2EDB = 0;
    } else {
        D_803F2EDB = 0;
        D_803F2EDA = 0;
        D_803F2EB0 = D_803F2EB8 = D_803F2EB4 = 0; // required for matching
    }
    if ((arg1 != 0) && (ticks_remaining >= (arg0 >> 1))) {
        D_803D552C->attackTimer++;
    }
    if (ticks_remaining >= arg0) {
        D_803D552C->unk364 = 0;
    }
}

// ESA: func_800A2660
void func_802DD004_6EE6B4(u16 arg0) {
    u16 tmp = D_803D5544 - D_803D552C->attackTimer;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
    }
}
