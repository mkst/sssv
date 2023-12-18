#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

const s16 D_803BEB70_7D0220[16] = {
    0, 7, 12, 14, 16, 14, 12, 10,
    8, 6,  5,  4,  3,  2,  2,  1,
};
const s16 D_803BEB90_7D0240[16] = {
     0, -5, -7, -8, -8, -7, -7, -6,
    -5, -5, -4, -4, -3, -3, -2, -2,
};

// ========================================================
// .bss (D_803F2EB0 to D_803F2EE0)
// ========================================================

s32  D_803F2EB0;
s32  D_803F2EB4;
s32  D_803F2EB8;
s32  D_803F2EBC;
s32  D_803F2EC0;
s32  D_803F2EC4;
s32  D_803F2EC8;

u16  D_803F2ECC;
u16  D_803F2ECE;
s16  D_803F2ED0;

s16  D_803F2ED2;
s32  D_803F2ED4;
s16  D_803F2ED8;
u8   D_803F2EDA;
u8   D_803F2EDB;
u8   D_803F2EDC;
u8   D_803F2EDD;
u8   D_803F2EDE;

// ========================================================
// .text
// ========================================================

// ESA: func_800A0ADC
void func_8035D120_76E7D0(void) {
    s16 idx;
    s8 tmp;

    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        D_803D552C->unk365 = ATTACK_NONE;
    }

    D_803F2ECC = 0;
    D_803F2ED0 = 0;
    D_803F2ED8 = 0;

    D_803F2EC8 = D_803F2EBC = D_803F2EC0 = D_803F2EC4 = FTOFIX32(1.0);

    D_803F2EB8 = FTOFIX32(1.0) - (D_803D5530->unk4B * FTOFIX32(0.01171875));
    D_803F2EB0 = D_803F2EB4 = FTOFIX32(1.0) + (D_803D5530->unk4B * FTOFIX32(0.015625));

    if ((D_803A6CE4_7B8394 & 8)) {
        D_803F2EC8 = FTOFIX32(3.0);
        D_803F2EB0 /= 3;
        D_803F2EB4 /= 3;
        D_803F2EB8 /= 3;
    }

    D_803F2EDA = D_803F2EDB = 1;
    D_803F2EDE = D_803F2EDC = 0;

    if (D_803D552C->unk360 != 0) {
    switch (D_803D552C->unk360) {
        case 3:
            D_803F2EB8 = (D_803F2EB8 * 14) >> 4;
            break;
        case 2:
            D_803F2EB8 = (D_803F2EB8 * 11) >> 4;
            break;
        case 1:
            D_803F2EB8 = (D_803F2EB8 * 8) >> 4;
            break;
        }
    }

    if (D_803D552C->unk36D != 0) {
        tmp = D_803D5524->unkE9;
        idx = (D_803D552C->unk36D << 4) / tmp;
        D_803F2EB0 = (D_803F2EB0 * (((D_803BEB90_7D0240[idx] * D_803D5524->unkEA) >> 4) + 0x10)) >> 4;
        D_803F2EB4 = (D_803F2EB4 * (((D_803BEB90_7D0240[idx] * D_803D5524->unkEA) >> 4) + 0x10)) >> 4;

        if ((D_803D5530->unk70 == NULL) || ((D_803D5530->unk70->position.yPos.h - D_803D5530->position.yPos.h) > (D_803D5530->unk42 * 2))) {
            D_803F2EB8 = (D_803F2EB8 * (((D_803BEB70_7D0220[idx] * D_803D5524->unkEA) >> 4) + 0x10)) >> 4;
        }
        if (++D_803D552C->unk36D >= tmp) {
            D_803D552C->unk36D = 0;
        }
    }
    switch (D_803D552C->unk364) {
    case 0:
    case 3:
        break;
    case 4:
        if ((D_803D5544 - D_803D552C->unk334) > 9) {
            D_803D552C->unk364 = 0;
        }
        break;
    case 8:
        func_802DBCDC_6ED38C(0x18);
        break;
    case 9:
        func_802DBED8_6ED588(0x18);
        break;
    case 15:
        func_802DC0D4_6ED784(0x10);
        break;
    case 6:
        func_802DC2AC_6ED95C(0xA);
        break;
    case 7:
        func_802DD004_6EE6B4(0x10);
        break;
    case 13:
        func_802DBB80_6ED230(0xE);
        func_802DC968_6EE018(16, 1);
        D_803F2ECE = 2;
        break;
    case 14:
        func_802DBB80_6ED230(0x14);
        func_802DC968_6EE018(32, 3);
        D_803F2ECE = 2;
        break;
    case 16:
        func_802DCD70_6EE420(300, 0);
        break;
    case 17:
        func_802DCD70_6EE420(300, 1);
        break;
    default:
        D_803D552C->unk364 = 0U;
        break;
    }

    if (D_803D552C->unk348 != 0) {
        if (D_803D552C->unk34A != 0) {
            D_803D552C->unk34A--;
        } else {
            D_803D552C->unk348--;
        }
    }
    if ((D_803D5540 & 2) && (D_803D552C->unk36B > 0)) {
        Animal *a = D_803D552C;
        D_803F2EDC = 1;
        if (a->unk36B < 3) {
            set_fog_factor_and_color(&D_801D9E88, 160, 160, 160);
        } else {
            set_fog_factor_and_color(&D_801D9E88, 200, 200, 200);
        }
        D_803D552C->unk36B = MAX(0, D_803D552C->unk36B - 2);
    }
}

void func_8035D6A0_76ED50(void) {
    if (D_803F2EDC != 0) {
        set_fog_position_and_color(&D_801D9E88);
    }
}

void func_8035D6D0_76ED80(void) {
    if (D_803D552C->unk348 != 0) {
        if (D_803D552C->unk34A != 0) {
            D_803D552C->unk34A -= 1;
        } else {
            D_803D552C->unk348 -= 1;
        }
    }
    if ((D_803D552C->unk36B - 1) < 0) {
        D_803D552C->unk36B = 0;
    } else {
        D_803D552C->unk36B -= 1;
    }
}

// ESA: func_800A0F8C
void func_8035D734_76EDE4(void) {
    s32 temp_v0_3;

    if (D_803D552C->unk366 == 5) {
        if (D_803D552C->unk36A == 1) {
            D_803F2ECC = MIN((D_803D5544 - D_803D552C->unk328) & 0xFFFF, 32);
            if (D_803F2ECC >= 32) {
                D_803D552C->unk36A = 0;
            }
        } else {
            D_803F2ECC = 32;
            D_803D552C->unk369 = 0;
            D_803D552C->unk365 = ATTACK_NONE;
        }
        D_803F2ECE = 1;
        if ((D_803F2D10.unk0 == 0) && (SSSV_RAND(64) == 0)) {
            func_802D9C64_6EB314(
                D_803D5530->position.xPos.h,
                D_803D5530->position.zPos.h,
                D_803D5530->position.yPos.h,
                D_803D5530->unk30,
                GPACK_RGBA5551(248, 248, 0, 1));
        }
    } else if ((D_803D5538 != 0) && (D_803D552C->unk36A == 1) && (D_803F2D30.unk4 > 16)) {
        D_803F2ECC = MIN(((D_803F2D30.unk4 - 16) >> 1), 32);
        D_803F2ECE = 1;
    } else if (D_803D552C->unk36A == 2) {
        temp_v0_3 = D_803D5544 - D_803D552C->unk328;
        if ((temp_v0_3 >= 0) && (temp_v0_3 < 24)) {
            D_803F2ECC = (32 - (temp_v0_3 * 4));
            if ((D_803F2ECC > 0) && (D_803F2ECC < 33)) {
                D_803F2ECE = 1;
            } else {
                D_803F2ECC = 0;
            }
            func_802DC854_6EDF04(temp_v0_3, 24);
        } else {
            D_803D552C->unk36A = 0;
        }
    }

    if ((D_803D552C->unk366 == 4) || ((D_803D5538 != 0) && (D_803D5530->health < 15))) {
        D_803F2ED2 = (D_803D5540 * 3) & 0xFF;
        D_803F2ED4 = ((SIN(D_803D5540) >> 7) * 80) / 4;
    } else if (D_803D552C->unk348 != 0) {
        D_803F2ED2 = (D_803D5540 * 3) & 0xFF;
        D_803F2ED4 = ((SIN(D_803D5540) >> 7) * D_803D552C->unk348) / 20;
    } else {
        D_803F2ED2 = D_803F2ED4 = 0;
    }
}

// ESA: func_800A1294
void func_8035DA60_76F110(void) {
    if (D_803D552C->unk366 == 4) {
        D_803F2EBC += SIN((D_803D552C->unk2EE % 16) << 4) >> 1;
        D_803F2EC0 += SIN((D_803D552C->unk2EE % 16) << 4) >> 1;
        D_803F2EC4 += SIN((D_803D552C->unk2EE % 16) << 4) >> 1;
        if (D_803F2D10.unk0 == 0) {
            if ((D_803D552C->unk2EE % 16) == 8) {
                D_803F2EDE = 1;
            }
            D_803D552C->unk2EE++;
        }
    } else if (D_803D552C->unk366 != 5) {
        if (D_803D552C->unk2EE <= 192) {
            D_803F2EBC += SIN((D_803D552C->unk2EE % 32) << 3) >> 2;
            D_803F2EC0 += SIN((D_803D552C->unk2EE % 32) << 3) >> 2;
            D_803F2EC4 += SIN((D_803D552C->unk2EE % 32) << 3) >> 2;
            if (D_803F2D10.unk0 == 0) {
                if ((D_803D552C->unk2EE % 32) == 16) {
                    D_803F2EDE = 1;
                }
                D_803D552C->unk2EE++;
            }
        } else {
            D_803F2EBC += SIN((D_803D552C->unk2EE % 64) << 2) >> 3;
            D_803F2EC0 += SIN((D_803D552C->unk2EE % 64) << 2) >> 3;
            D_803F2EC4 += SIN((D_803D552C->unk2EE % 64) << 2) >> 3;
            if (D_803F2D10.unk0 == 0) {
                if ((D_803D552C->unk2EE % 64) == 32) {
                    D_803F2EDE = 1;
                }
                D_803D552C->unk2EE++;
            }
        }
        if (D_803D5530->state == 23) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 4) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 42) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 105) {
            D_803D552C->unk2EE %= 64;
        }
    }
}

// ESA: func_800A15BC
// used by dog
void func_8035DEC4_76F574(void) {
    if (D_803D552C->unk366 != 5) {
        if (D_803D552C->unk2EE < 385) {
            D_803F2EBC += SIN((D_803D552C->unk2EE & 0xF) << 4) >> 2;
            D_803F2EC0 += SIN((D_803D552C->unk2EE & 0xF) << 4) >> 2;
            D_803F2EC4 += SIN((D_803D552C->unk2EE & 0xF) << 4) >> 2;
        } else {
            D_803F2EBC += SIN((D_803D552C->unk2EE & 0x1F) << 3) >> 2;
            D_803F2EC0 += SIN((D_803D552C->unk2EE & 0x1F) << 3) >> 2;
            D_803F2EC4 += SIN((D_803D552C->unk2EE & 0x1F) << 3) >> 2;
        }
        if (D_803F2D10.unk0 == 0) {
            D_803D552C->unk2EE++;
        }
        if (D_803D5530->state == 23) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 4) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 42) {
            D_803D552C->unk2EE %= 64;
        }
        if (D_803D5530->state == 105) {
            D_803D552C->unk2EE %= 64;
        }
    }
}
