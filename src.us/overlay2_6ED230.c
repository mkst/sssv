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
    u16 tmp;

    tmp = (D_803D5544 - D_803D552C->unk334);
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }

    if (tmp == 1) {
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
            play_sound_effect_at_location(32, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            break;
        case RACING_TORTOISE_DEFENDING:
            break;
        }
    }

    temp_t8 = (-D_80152C78[((s16)(((tmp << 7) / arg0) << 2) + 64) & 0xFF] * (128 - ((tmp << 7) / arg0))) >> 7;
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
    u16 tmp;

    tmp = (D_803D5544 - D_803D552C->unk334);
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }
    temp_t8 = (D_80152C78[(s16) ((tmp << 7) / arg0) & 0xFF] / (((tmp << 7) / arg0) + 16)) << 5;
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
    u16 temp_t9;
    u16 temp_v0;

    temp_t9 = (D_803D5544 - D_803D552C->unk32A);
    if (temp_t9 >= arg0) {
        D_803D552C->unk365 = ATTACK_NONE;
    } else {
        temp_v0 = (temp_t9 * 128) / arg0;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DC854_6EDF04.s")
// *almost* just regalloc
// void func_802DC854_6EDF04(s16 arg0, u16 arg1) {
//     s16 phi_v1;
//     u16 temp_t0;
//
//     temp_t0 = (arg0 << 7) / arg1;
//
//     if (temp_t0 < 96) {
//         phi_v1 = (temp_t0 << 2) / 3;
//     } else {
//         phi_v1 = (-temp_t0 << 2) + 512;
//     }
//
//     D_803F2EBC += (D_80152C78[(temp_t0 * 8) & 0xFF] >> 7) * phi_v1;
//     D_803F2EC0 += (D_80152C78[(temp_t0 * 4) & 0xFF] >> 7) * phi_v1;
//     D_803F2EC4 -= (D_80152C78[(temp_t0 * 8) & 0xFF] >> 7) * phi_v1;
// }

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DCD70_6EE420.s")
// void func_802DCD70_6EE420(u16 arg0, u8 arg1) {
//     s32 temp_t0;
//     s32 temp_t6;
//     u16 temp_t6_2;
//     u32 phi_t1;
//
//     temp_t6_2 = (D_803D5544 - D_803D552C->unk334); // & 0xFFFF;
//     phi_t1 = (temp_t6_2 << 0xA) / arg0;
//     if (phi_t1 > 512) {
//         phi_t1 = 1024 - phi_t1;
//     }
//
//     if (phi_t1 < 325) {
//         D_803F2EB0 = (((D_80152C78[(s16)phi_t1 & 0xFF]) >> 9) * phi_t1) + FTOFIX32(1.0);
//         D_803F2EB4 = (((D_80152C78[((s16)(phi_t1 << 1) + 64) & 0xFF]) >> 9) * phi_t1) + FTOFIX32(1.0);
//         D_803F2EB8 = D_80152C78[(((s16)(phi_t1 * 3)) - 30) & 0xFF] >> 9;
//         D_803F2EB8 = FTOFIX32(1.0) - (D_803F2EB8 * phi_t1);
//     } else if (phi_t1 < 375) {
//         temp_t0 = (phi_t1 - 325) << 0xA;
//         D_803F2EB0 = ((((D_80152C78[(s16)phi_t1 & 0xFF]) >> 9) * 325) - temp_t0) + FTOFIX32(1.0);
//         D_803F2EB4 = ((((D_80152C78[((s16)(phi_t1 << 1) + 64) & 0xFF]) >> 9) * 325) - temp_t0);
//         D_803F2EB4 += FTOFIX32(1.0);
//         D_803F2EB8 = (FTOFIX32(1.0) - (((D_80152C78[((s16)(phi_t1 * 3) - 30) & 0xFF]) >> 9) * phi_t1)) + ((phi_t1 - 325) << 12);
//         D_803F2EDB = 0;
//     } else {
//         D_803F2EDB = 0;
//         D_803F2EDA = 0;
//         D_803F2EB4 = 0;
//         D_803F2EB8 = 0;
//         D_803F2EB0 = 0;
//     }
//     if (((arg1) != 0) && (temp_t6_2 >= (arg0 >> 1))) {
//         D_803D552C->unk334 += 1;
//     }
//     if (temp_t6_2 >= arg0) {
//         D_803D552C->unk364 = 0;
//     }
// }

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
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD244_6EE8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD548_6EEBF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD994_6EF044.s")
