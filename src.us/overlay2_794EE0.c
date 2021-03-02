#include <ultra64.h>
#include "common.h"


s32 func_80383830_794EE0(u16 arg0) {
    Animal *a = D_803D552C->unk2CC;
    if (arg0 < func_803051F0_7168A0((func_801284B8(a->xPos - D_803D5530->xPos, a->zPos - D_803D5530->zPos) * 256) / 360, D_803D5530->yRotation)) {
        return 0;
    } else {
        return 1;
    }
}

s32 func_803838C8_794F78(s16 rotation, u16 arg1) {
    Animal *a = D_803D552C->unk2CC;

    if (arg1 < func_803051F0_7168A0(((func_801284B8(a->xPos - D_803D5530->xPos, a->zPos - D_803D5530->zPos) * 256) / 360), rotation)) {
        return  0;
    } else {
        return 1;
    }
}

s16 func_8038395C_79500C(void) {
    f32 xVel;
    f32 zVel;
    f32 res;

    xVel = D_803D5530->xVelocity / 65536.0f;
    zVel = D_803D5530->zVelocity / 65536.0f;

    res = sqrtf(xVel * xVel + zVel * zVel);
    res = 16 * res;
    res = res / (D_803D5524->unkA4 >> 6);
    return res;
}

void func_803839F0_7950A0(void) {
    if (0) {}; // needed for regalloc

    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 100) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 111) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 101) && (func_80383830_794EE0(5) != 0)) {
            func_802F2AA0_704150();
            D_803D552C->unk2C4 = (func_8012826C() % 40) + 50;
        } else if (D_803D552C->unk2C4 <= 0) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 200) || (D_803D552C->unk2B8++ >= 61)) {
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_80383BE4_795294(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2C0 = 0;
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 100) && (D_803D552C->unk2C0 == 0)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 1;
        } else if ((D_803D552C->unk2D0 >= 121) && (D_803D552C->unk2C0 == 1)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
        }
        if ((func_80383830_794EE0(5) != 0) && (D_803D552C->unk2D0 < 350) && (D_803D552C->unk2C4 <= 0)) {
            if (D_803D552C->unk2B8 >= 2) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B8 = 0;
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
            } else {
                func_802F0780_701E30(0, 0, 0);
                D_803D552C->unk2C4 = (guRandom() % 5) + 30;
                D_803D552C->unk2B8 += 1;
            }
        }
        break;
    case 2:
        if ((func_80383830_794EE0(80) == 0) && (D_803D552C->unk2C4 <= 0)) {
            func_802F05A4_701C54();
            D_803D552C->unk2C4 = 60;
        }
        if ((D_803D552C->unk2D0 >= 401) || (D_803D552C->unk2B8++ >= 60)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
            D_803D552C->unk2C0 = 0;
        }
    }
}

void func_80383E38_7954E8(void) {
}

void func_80383E40_7954F0(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x191) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if (D_803D552C->unk2D0 >= 0x1B9) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 0xA);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        } else if ((D_803D552C->unk2D0 < 0x12C) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0) ){
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 0x14) + 0x14;
            func_802EEDE0_700490(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0x15F) || (D_803D552C->unk2C0++ >= 0x3D) ) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x20);
        }
    }
}

void func_80384060_795710(void) {
    if ((D_803D552C->unk2CC->unk16C->unk9E == 0x40) ||
        (D_803D552C->unk2CC->unk16C->unk9E == 0x80) ||
        (D_803D552C->unk2CC->unk16C->unk9E == 0x20)) {
        rmonPrintf(D_803BF3F0, D_803D552C->unk2B4.uw >> 28, D_803D552C->unk2C4);
        switch (D_803D552C->unk2B4.uw >> 28) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
            // fallthru
        case 1:
            if (D_803D552C->unk2D0 < 100) {
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if ((func_80383830_794EE0(5) != 0) && (D_803D552C->unk2D0 < 220) && (D_803D552C->unk2C4 == 0)) {
                D_803D552C->unk2C4 = 140;
            }
            if ((D_803D552C->unk2C4 > 0) && (D_803D552C->unk2C4 >= 0x64) && ((D_803D552C->unk2C4 & 3) == 0)) {
                func_802EEF9C_70064C(0, 0, 0);
            }
            break;
        case 2:
            if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 >= 0xFB)) {
                D_803D552C->unk2B4.ub = (((u8) D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    } else {
        switch (D_803D552C->unk2B4.uw >> 28) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            // fallthru
        case 1:
            if (D_803D552C->unk2D0 < 64) {
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x30;
                func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -180, 16);
            } else if ((D_803D552C->unk2C4 == 0) && (func_80383830_794EE0(10) != 0) && (D_803D552C->unk2D0 < 0xC8)) {
                D_803D552C->unk2C4 = 80;
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
                func_80363FB8_775668(D_803D5530, (D_803D5530->yRotation * 360) >> 8, -180, 16);
            }
            break;
        case 2:
            if ((D_803D552C->unk2C4 >= 60) && ((D_803D552C->unk2C4 % 5) == 0)) {
                func_802EEFEC_70069C(0, 0, 0);
            } else if (D_803D552C->unk2C4 < 0x3C) {
                D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
                func_80363FB8_775668(D_803D5530, (D_803D5530->yRotation * 360) >> 8, -180, 16);
                return;
            }
            break;
        case 3:
            if ((D_803D552C->unk2D0 >= 0x119) || (D_803D552C->unk2C4 == 0)) {
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
            }
        }
    }
}

void func_8038448C_795B3C(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        // fallthru
    case 1:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
            if (D_803D552C->unk2C0 == 0) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        } else if ((D_803D552C->unk2C0 == 0) && ((D_803D5530->unk5C & 4) != 0) && (D_803D5530->unk60 == D_803D552C->unk2CC)) {
            D_803D552C->unk2C0 = 40;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 51) && (func_80383830_794EE0(5) != 0)) {
            func_802E88C0_6F9F70(100);
            D_803D552C->unk2C4 = (func_8012826C() & 7) + 25;
            D_803D552C->unk2BC += 1;
            if (D_803D552C->unk2BC >= 3) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 100) || (++D_803D552C->unk2C0 >= 0x1F)) {
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_803846BC_795D6C(void) {
    // regalloc
    if (1) {};

    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -70, 16);
        D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x78) {
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x20);
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 < 0xC8) && (func_80383830_794EE0(20) != 0)) {
            func_802E87B8_6F9E68(D_803D552C->unk2CC);
            D_803D552C->unk2C4 = 0x96;
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x20);
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 >= 0xF1)) {
            D_803D552C->unk2B4.ub = (((u8) D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -70, 16);
        }
    }
}

void func_80384858_795F08(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        // fallthru
    case 1:
        if ((s32) D_803D552C->unk2D0 < 0x3D) {
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x20);
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if (((s32) D_803D552C->unk2D0 >= 0x3D) && (D_803D552C->unk2BC < 4)) {
            D_803D552C->unk2B4.ub = (((u8) D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            D_803D552C->unk2BC += 1;
            if (D_803D552C->unk2BC < 4) {
                func_80302DD0_714480();
            }
            D_803D552C->unk2C4 =  (func_8012826C() & 7) + 10;
            if (D_803D552C->unk2BC >= 5) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0xFA) || (++D_803D552C->unk2C0 >= 0x29)) {
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_80384A8C_79613C(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        D_803D552C->unk2C0 = 0;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 201) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x20);
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if ((D_803D552C->unk2C0 == 0) && (D_803D552C->unk2D0 >= 0xFB)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        } else if ((D_803D552C->unk2C0 == 0) && (D_803D552C->unk2D0 < 0x64)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            func_803021A8_713858();
            D_803D552C->unk2C4 = (func_8012826C() & 0x1F) + 40;
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0x12D) || (D_803D552C->unk2C0++ >= 101)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x20);
            D_803D552C->unk2C0 = 100;
        }
    }
}

void func_80384CB8_796368(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0xC8, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x40) {
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x30;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -0xC8, 16);
        } else if ((func_80383830_794EE0(0xA) != 0) && (D_803D552C->unk2D0 < 0xB4)) {
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
            D_803D552C->unk2C4 = 0x50;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -0xC8, 16);
        }
        break;
    case 2:
        if ((D_803D552C->unk2C4 >= 0x3C) && ((D_803D552C->unk2C4 % 5) == 0)) {
            func_80302120_7137D0(0, 0, 0);
        } else if (D_803D552C->unk2C4 < 0x3C) {
            D_803D552C->unk2B4.ub = (((u8) D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -0xB4, 16);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0xC9) || ((D_803D552C->unk2C4 == 0))) {
            D_803D552C->unk2B4.ub = (((u8) D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0xB4, 16);
        }
    }
}

void func_80384F14_7965C4(void) {
}

void func_80384F1C_7965CC(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0xF0, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 5) {
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -0xF0, 16);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
            func_80314600_725CB0();
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0x15F) || ((++D_803D552C->unk2C0 >= 0x97))) {
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0xF0, 16);
        }
    }
}

void func_80385078_796728(void) {
}

void func_80385080_796730(void) {
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80385088_796738.s")

void func_803852B8_796968(void) {
}

void func_803852C0_796970(void) {
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803852C8_796978.s")

void func_80385480_796B30(void) {
}

void func_80385488_796B38(void) {
}

void func_80385490_796B40(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
            if (D_803D552C->unk2C0 == 0) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        } else {
            if (D_803D552C->unk2C0 == 0) {
                if ((D_803D5530->unk5C & 4) != 0) {
                    if (D_803D5530->unk60 == D_803D552C->unk2CC) {
                        D_803D552C->unk2C0 = 40;
                        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
                    }
                }
            }
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 51)) {
            if (func_80383830_794EE0(5) != 0) {
                D_803D552C->unk2BC += 1;
                if (D_803D552C->unk2BC < 4) {
                    func_802E88C0_6F9F70(100);
                }
                D_803D552C->unk2C4 = (func_8012826C() & 7) + 10;
                if (D_803D552C->unk2BC >= 4) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
                    D_803D552C->unk2B8 = 0;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2B8 == 0) && (func_80383830_794EE0(80) == 0)) {
            D_803D552C->unk2B8 = 1;
            if ((guRandom() & 3) == 0) {
                 func_802E89AC_6FA05C();
            }
        } else {
            if (D_803D552C->unk2D0 >= 0xFA) {
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    }
}

void func_80385710_796DC0(void) {

    rmonPrintf(D_803BF400, D_803D552C->unk2B4.uw >> 28);

    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 501) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
        }
        break;
    case 2:
        if (D_803D552C->unk2B8 > 0) {
            D_803D552C->unk2B8 -= 1;
        }
        if (D_803D552C->unk2D0 >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        } else if (((D_803D552C->unk2D0 < 280) && (D_803D552C->unk2B8 <= 0)) ||
                   (D_803D552C->unk2D0 < 120)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
            D_803D552C->unk2B8 = 0;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            func_80356134_7677E4(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 351) || (D_803D552C->unk2B8++ >= 100)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
            if (D_803D552C->unk2B8 >= 90) {
                D_803D552C->unk2B8 = 100;
            } else {
                D_803D552C->unk2B8 = 0;
            }
        } else if (D_803D552C->unk2D0 < 0x78) {
            func_803562C8_767978(32000);
        }
    }

    if (D_803D552C->unk2C0 > 0) {
        D_803D552C->unk2C0 -= 1;
    }
}

void func_803859D4_797084(void) {
    if (D_803D552C->unk2D0 >= 131) {
        func_803562C8_767978(0);
    }
}

void func_80385A0C_7970BC(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if (func_80383830_794EE0(2) != 0) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
        }
        break;
    case 2:
        if (((D_803D5530->unk5C & 4) != 0) && (D_803D5530->unk60 == D_803D552C->unk2CC)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x30;
            D_803D552C->unk2B8 = 0;
        }
        if ((D_803D552C->unk2D0 < 70) && (func_80383830_794EE0(5) != 0) && (func_8038395C_79500C() >= 12)) {
            func_80356348_7679F8(20);
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x30);
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        if (((s32) D_803D552C->unk2D0 >= 300) || (D_803D552C->unk2B8++ >= 91)) {
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
    }
}

void func_80385BE0_797290(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x28) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if (D_803D552C->unk2D0 >= 0x33) {
            if (D_803D552C->unk2C0 != 0) {
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0x33)) {
            if (func_80383830_794EE0(5) != 0) {
                D_803D552C->unk2BC = (D_803D552C->unk2BC + 1);
                if (D_803D552C->unk2BC < 4) {
                    func_802EEF74_700624();
                }
                D_803D552C->unk2C4 = (func_8012826C() & 3) + 5;
                if (D_803D552C->unk2BC >= 5) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0xC8) || (D_803D552C->unk2C0++ >= 0x3D)) {
            D_803D552C->unk2B4.ub = (u8) ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }

}

void func_80385DF0_7974A0(void) {
    switch (D_803D552C->unk2B4.uw >> 28) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        // fallthru
    case 1:
        if ((s32) D_803D552C->unk2D0 < 0xFB) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x20;
        } else if ((D_803D552C->unk2C4 <= 0) && ((s8)D_803D552C->unk2B4.h > 0)) {
            func_8035FDC0_771470(0x78);
            D_803D552C->unk2C4 = 0xFA;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 0x191) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFF0F) | 0x10;
        } else if ((D_803D552C->unk2B8 <= 0) && (D_803D552C->unk2D0 < 0xC8)) {
            func_8035FE6C_77151C(0x3C);
            D_803D552C->unk2B8 = 0xB4;
        }
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8 -= 1;
    }
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80385F90_797640.s")

void func_80386454_797B04(void) {
    switch (D_803D552C->unk2B4.uw >> 0x1C) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 0x10);
        D_803D552C->unk2B4.ub = ((D_803D552C->unk2B4.ub & 0xFF0F) | 0x10);
        // fallthrough
    case 1:
        if (--D_803D552C->unk2C0 <= 0) {
            if (D_803D552C->unk2B8++ >= 6) {
                D_803D552C->unk270 = 0;
                D_803D552C->unk272 = D_803D552C->unk2C8;
                D_803D552C->unk2B4.ub = (D_803D552C->unk2B4.ub & 0xFFF1);
                D_803D552C->unk2CC = 0;
                func_80363FF0_7756A0(D_803D5530);
            } else {
                func_8030A958_71C008();
                func_80363FB8_775668(D_803D5530, (guRandom() % 0x168), 0, 0x10);
                D_803D552C->unk2C0 = ((guRandom() % 0xF) + 0x14);
            }
        }
        break;
    case 2:
        break;
    }
}

//
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803865A0_797C50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803867B8_797E68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803867C0_797E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80386A48_7980F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80386BB8_798268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80386D80_798430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80386F84_798634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_8038710C_7987BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80387114_7987C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80387330_7989E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_8038754C_798BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80387780_798E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803879A4_799054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80387BF4_7992A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80387DE0_799490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_8038801C_7996CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80388248_7998F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80388480_799B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80388744_799DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803888F0_799FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80388B0C_79A1BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80388CC8_79A378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80388F10_79A5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80389150_79A800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80389158_79A808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80389160_79A810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803892D4_79A984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803892DC_79A98C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803892E4_79A994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803892EC_79A99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803892F4_79A9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_8038951C_79ABCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80389524_79ABD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_8038974C_79ADFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80389754_79AE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_8038975C_79AE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_80389764_79AE14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803897B0_79AE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_794EE0/func_803899E0_79B090.s")
