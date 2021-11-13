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
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
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
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
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
            play_sound_effect_at_location(D_803A6470_7B7B20[D_803D5524->unk9C], D_803A6520_7B7BD0[D_803D5524->unk9C], 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DC0D4_6ED784.s")
// void func_802DC0D4_6ED784(u16 arg0) {
//     s32 temp_t8;
//     u16 tmp;
//
//     tmp = (D_803D5544 - D_803D552C->unk334);
//     if (arg0 < tmp) {
//         D_803D552C->unk364 = 0;
//         return;
//     }
//
//     if (tmp == 1) {
//         switch (D_803D5524->unk9C) {
//         case 14:
//         case 15:
//         case 16:
//
//         case 17:
//         case 18:
//         case 19:
//         case 20:
//         case 21:
//         case 22:
//         case 23:
//         case 24:
//         case 25:
//         case 26:
//         case 27:
//         case 28:
//         case 29:
//         default:
//             play_sound_effect_at_location(32, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//             break;
//         case 65:
//             break;
//         }
//     }
//
//     // this is wrong
//     temp_t8 = (-D_80152C78[((((tmp << 7) / arg0) << 2) + 64) & 0xFF] * (0x80 - ((tmp << 7) / arg0))) >> 7;
//
//     D_803F2EB0 += temp_t8;
//     D_803F2EB4 += temp_t8;
//     D_803F2EB8 += temp_t8;
//     if (D_803F2EB0 < 1024) {
//         D_803F2EB0 = 1024;
//     }
//     if (D_803F2EB4 < 1024) {
//         D_803F2EB4 = 1024;
//     }
//     if (D_803F2EB8 < 1024) {
//         D_803F2EB8 = 1024;
//     }
// }

void func_802DC2AC_6ED95C(u16 arg0) {
    s32 temp_t8;
    u16 tmp;

    tmp = (D_803D5544 - D_803D552C->unk334);
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
        return;
    }
    temp_t8 = (D_80152C78[(((s16) ((tmp << 7) / arg0) & 0xFF))] / (((tmp << 7) / arg0) + 16)) << 5;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DC3F4_6EDAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DC6A4_6EDD54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DC854_6EDF04.s")
// almost regalloc
// void func_802DC854_6EDF04(s16 arg0, u16 arg1) {
//     u16 temp_t0;
//     s16 phi_v1;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DCA28_6EE0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DCAD4_6EE184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DCB90_6EE240.s")

void func_802DCCAC_6EE35C(u16 arg0) {
    s16 temp_lo;
    u16 temp_t9;

    temp_t9 = D_803D5544 - D_803D552C->unk32A;
    if (temp_t9 >= arg0) {
        D_803D552C->unk365 = 0;
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

void func_802DD004_6EE6B4(u16 arg0) {
    u16 tmp = D_803D5544 - D_803D552C->unk334;
    if (arg0 < tmp) {
        D_803D552C->unk364 = 0;
    }
}

void func_802DD040_6EE6F0(s32 arg0) {
    s16 i;
    for (i = 0; i < 120; i++) {
        D_803E00C0[i].unk2E = 0;
    }
    D_803E1B00 = 0;
    D_803E1B02 = 1;
}

s16 func_802DD090_6EE740(s16 arg0, s32 arg1, u8 arg2, s8 arg3, s8 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, u8 arg9, s32 argA, s32 argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11) {
    u16 i;
    s32 res;

    if (((D_803E1B00 + arg0) < 1000) && (D_803E1B02 < 120)) {
        D_803E00C0[D_803E1B02].unk14 = arg0;
        D_803E00C0[D_803E1B02].unk16 = D_803E1B00;
        D_803E00C0[D_803E1B02].unk1C = ((arg0 + 1) * arg1) >> 0x10;
        D_803E00C0[D_803E1B02].unk2E = arg3;
        D_803E00C0[D_803E1B02].unk2F = arg4;
        D_803E00C0[D_803E1B02].unk32 = arg8;
        D_803E00C0[D_803E1B02].unk33 = arg9;
        D_803E00C0[D_803E1B02].unk0 = argA;
        D_803E00C0[D_803E1B02].unk4 = argB;
        D_803E00C0[D_803E1B02].unk8 = argC;
        D_803E00C0[D_803E1B02].unkA = argD;
        D_803E00C0[D_803E1B02].unkC = argE;
        D_803E00C0[D_803E1B02].unk18 = arg1;
        D_803E00C0[D_803E1B02].unk20 = arg5;
        D_803E00C0[D_803E1B02].unk24 = arg6;
        D_803E00C0[D_803E1B02].unk28 = arg7;
        D_803E00C0[D_803E1B02].unkE = argF;
        D_803E00C0[D_803E1B02].unk10 = arg10;
        D_803E00C0[D_803E1B02].unk12 = arg11;
        D_803E00C0[D_803E1B02].unk2C = 0;
        D_803E00C0[D_803E1B02].unk34 = 1;

        for (i = 0; i < arg0; i++) {
            D_803DA300[D_803E1B00 + i].unk0 = arg5;
            D_803DA300[D_803E1B00 + i].unk4 = arg6;
            D_803DA300[D_803E1B00 + i].unk8 = arg7;
            D_803DA300[D_803E1B00 + i].unkC = 0;
            D_803DA300[D_803E1B00 + i].unk10 = 0;
            D_803DA300[D_803E1B00 + i].unk14 = 0;

            if (arg2) {
                arg7 += arg1;
            } else {
                arg7 -= arg1;
            }
        }
        D_803E1B00 += arg0;
        return D_803E1B02++;
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD244_6EE8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD548_6EEBF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ED230/func_802DD994_6EF044.s")

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

void func_802DE914_6EFFC4(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    struct051 *tmp = &D_803E00C0[arg0];
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

    *arg1 = (tmp->unk0 - *(s32*)&D_803D5530->xPos) >> 14;
    *arg2 = (tmp->unk4 - *(s32*)&D_803D5530->zPos) >> 14;
    *arg3 = (tmp->unk8 - *(s32*)&D_803D5530->yPos) >> 14;

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

s32 func_802E4B0C_6F61BC(s16 arg0) {
    switch (arg0) {
    case 16:
    case 18:
    case 20:
    case 21:
    case 32:
        return func_802DD090_6EE740(6, FTOFIX32(3.125), 1, 3, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 13:
        return func_802DD090_6EE740(6, FTOFIX32(6.25), 1, 32, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 40:
    case 42:
        return func_802DD090_6EE740(4, FTOFIX32(6.875), 1, 11, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 41:
        return func_802DD090_6EE740(4, FTOFIX32(6.875), 1, 12, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 49:
    case 50:
        return func_802DD090_6EE740(4, FTOFIX32(15.0), 1, 13, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 53:
        return func_802DD090_6EE740(7, FTOFIX32(5.90625), 1, 14, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 56:
        return func_802DD090_6EE740(5, FTOFIX32(16.40625), 1, 16, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case 1:
        return func_802DD090_6EE740(4, FTOFIX32(15.625), 1, 35, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
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
