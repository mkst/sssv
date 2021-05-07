#include <ultra64.h>
#include "common.h"


void (*D_803B5D20[AID_MAX_ANIMALS])(void) = {
    perform_behavior_seagull,
    perform_behavior_lion,
    perform_behavior_hippo,
    func_80383E38_7954E8,
    func_80383E40_7954F0,
    func_80384060_795710, // 5 FLYING_DOG
    func_8038448C_795B3C,
    func_803846BC_795D6C, // 7 FIRE_FOX
    func_80384858_795F08,
    func_803892DC_79A98C, // 9 POLAR_BEAR_DEFENDING
    func_80384A8C_79613C,
    func_80384CB8_796368, // HELI_RABBIT
    func_80384F14_7965C4,
    func_80385DF0_7974A0, // KING_RAT
    func_80384F1C_7965CC,
    func_80385078_796728,
    func_80385080_796730,
    func_803892E4_79A994,
    func_80385088_796738,
    func_803892EC_79A99C,
    func_803852B8_796968,
    func_803852C0_796970,
    func_803852C8_796978,
    func_80385480_796B30, // 23 BEAR_ATTACKING
    func_80385488_796B38,
    func_8038951C_79ABCC,
    func_80385490_796B40,
    func_80385710_796DC0, // TORTOISE_TANK
    func_80385A0C_7970BC,
    func_803859D4_797084,
    func_80389524_79ABD4,
    func_80385BE0_797290,
    func_80385F90_797640, // RAT
    perform_behavior_sheep,
    func_803865A0_797C50,
    func_803867B8_797E68,
    func_803867C0_797E70,
    func_80386A48_7980F8, // PENGUIN
    func_80386BB8_798268,
    func_80386D80_798430,
    func_80386F84_798634,
    func_8038710C_7987BC,
    func_80387114_7987C4,
    func_8038974C_79ADFC,
    func_80387330_7989E0,
    func_8038754C_798BFC,
    func_80387780_798E30,
    func_803879A4_799054,
    func_80389754_79AE04,
    func_80387BF4_7992A4,
    func_80387DE0_799490,
    func_8038801C_7996CC,
    func_80388248_7998F8,
    func_80388480_799B30,
    func_80388744_799DF4,
    func_8038801C_7996CC,
    func_803888F0_799FA0,
    func_80388B0C_79A1BC,
    func_80388CC8_79A378, // HYENA_BIKER
    func_80388F10_79A5C0,
    func_80389150_79A800,
    func_80389158_79A808,
    func_80389158_79A808,
    func_80389158_79A808,
    func_80389160_79A810, // KING_PENGUIN
    func_803892D4_79A984,
    func_8038975C_79AE0C,
    func_80389158_79A808
};

s32 func_80383830_794EE0(u16 arg0) {
    Animal *a = D_803D552C->unk2CC;
    if (arg0 < func_803051F0_7168A0((func_801284B8(a->xPos - D_803D5530->xPos, a->zPos - D_803D5530->zPos) * 256) / 360, D_803D5530->yRotation)) {
        return 0;
    } else {
        return 1;
    }
}

s32 func_803838C8_794F78(u16 rotation, u16 arg1) {
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

    xVel = D_803D5530->xVelocity.w / 65536.0f;
    zVel = D_803D5530->zVelocity.w / 65536.0f;

    res = sqrtf(xVel * xVel + zVel * zVel);
    res = 16 * res;
    res = res / (D_803D5524->unkA4 >> 6);
    return res;
}

// all animal behaviours

void perform_behavior_lion(void) {
    if (1) {}; // needed for regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
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
            lion_roar();
            D_803D552C->unk2C4 = (func_8012826C() % 40) + 50;
        } else if (D_803D552C->unk2C4 <= 0) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 200) || (D_803D552C->unk2B8++ >= 61)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_hippo(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2C0 = 0;
        D_803D552C->unk2B4.state = 1;
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
                D_803D552C->unk2B4.state = 2;
            } else {
                func_802F0780_701E30(0, 0, 0);
                D_803D552C->unk2C4 = (guRandom() % 5) + 30;
                D_803D552C->unk2B8 += 1;
            }
        }
        break;
    case 2:
        if ((func_80383830_794EE0(80) == 0) && (D_803D552C->unk2C4 <= 0)) {
            drop_sticky_mine();
            D_803D552C->unk2C4 = 60;
        }
        if ((D_803D552C->unk2D0 >= 401) || (D_803D552C->unk2B8++ >= 60)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
        }
    }
}

void func_80383E38_7954E8(void) {
}

void func_80383E40_7954F0(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 401) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if (D_803D552C->unk2D0 >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2D0 < 300) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0) ){
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            func_802EEDE0_700490(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 351) || (D_803D552C->unk2C0++ >= 61) ) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

// perform_behavior_flying_fox
void func_80384060_795710(void) {
    if ((D_803D552C->unk2CC->unk16C->unk9E == 64) ||
        (D_803D552C->unk2CC->unk16C->unk9E == 128) ||
        (D_803D552C->unk2CC->unk16C->unk9E == 32)) {
        // typo
        rmonPrintf("staet %d FC %d\n", D_803D552C->unk2B4.state, D_803D552C->unk2C4);
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if (D_803D552C->unk2D0 < 100) {
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.state = 2;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if ((func_80383830_794EE0(5) != 0) && (D_803D552C->unk2D0 < 220) && (D_803D552C->unk2C4 == 0)) {
                D_803D552C->unk2C4 = 140;
            }
            if ((D_803D552C->unk2C4 > 0) && (D_803D552C->unk2C4 >= 100) && ((D_803D552C->unk2C4 & 3) == 0)) {
                func_802EEF9C_70064C(0, 0, 0);
            }
            break;
        case 2:
            if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 > 250)) {
                D_803D552C->unk2B4.state = 1;
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    } else {
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if (D_803D552C->unk2D0 < 64) {
                D_803D552C->unk2B4.state = 3;
                func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -180, 16);
            } else if ((D_803D552C->unk2C4 == 0) && (func_80383830_794EE0(10) != 0) && (D_803D552C->unk2D0 < 200)) {
                D_803D552C->unk2C4 = 80;
                D_803D552C->unk2B4.state = 2;
                func_80363FB8_775668(D_803D5530, (D_803D5530->yRotation * 360) >> 8, -180, 16);
            }
            break;
        case 2:
            if ((D_803D552C->unk2C4 >= 60) && ((D_803D552C->unk2C4 % 5) == 0)) {
                func_802EEFEC_70069C(0, 0, 0);
            } else if (D_803D552C->unk2C4 < 60) {
                D_803D552C->unk2B4.state = 3;
                func_80363FB8_775668(D_803D5530, (D_803D5530->yRotation * 360) >> 8, -180, 16);
                return;
            }
            break;
        case 3:
            if ((D_803D552C->unk2D0 >= 0x119) || (D_803D552C->unk2C4 == 0)) {
                D_803D552C->unk2B4.state = 1;
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
            }
        }
    }
}

void func_8038448C_795B3C(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
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
                D_803D552C->unk2B4.state = 2;
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 100) || (++D_803D552C->unk2C0 >= 0x1F)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_803846BC_795D6C(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -70, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x78) {
            D_803D552C->unk2B4.state = 2;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 < 200) && (func_80383830_794EE0(20) != 0)) {
            flying_fox_fire_missile(D_803D552C->unk2CC);
            D_803D552C->unk2C4 = 0x96;
            D_803D552C->unk2B4.state = 2;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 >= 0xF1)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -70, 16);
        }
    }
}

void func_80384858_795F08(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 61) {
            D_803D552C->unk2B4.state = 2;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 61) && (D_803D552C->unk2BC < 4)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            D_803D552C->unk2BC += 1;
            if (D_803D552C->unk2BC < 4) {
                frog_croak();
            }
            D_803D552C->unk2C4 =  (func_8012826C() & 7) + 10;
            if (D_803D552C->unk2BC >= 5) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.state = 3;
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 250) || (++D_803D552C->unk2C0 >= 0x29)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_80384A8C_79613C(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        D_803D552C->unk2C0 = 0;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 201) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if ((D_803D552C->unk2C0 == 0) && (D_803D552C->unk2D0 >= 0xFB)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2C0 == 0) && (D_803D552C->unk2D0 < 100)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            func_803021A8_713858();
            D_803D552C->unk2C4 = (func_8012826C() & 0x1F) + 40;
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 301) || (D_803D552C->unk2C0++ >= 101)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 100;
        }
    }
}

void func_80384CB8_796368(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -200, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 64) {
            D_803D552C->unk2B4.state = 3;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -200, 16);
        } else if ((func_80383830_794EE0(10) != 0) && (D_803D552C->unk2D0 < 180)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C4 = 80;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -200, 16);
        }
        break;
    case 2:
        if ((D_803D552C->unk2C4 >= 60) && ((D_803D552C->unk2C4 % 5) == 0)) {
            heli_rabbit_drop_bomb(0, 0, 0);
        } else if (D_803D552C->unk2C4 < 60) {
            D_803D552C->unk2B4.state = 3;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -180, 16);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0xC9) || ((D_803D552C->unk2C4 == 0))) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
        }
    }
}

void func_80384F14_7965C4(void) {
}

void func_80384F1C_7965CC(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -240, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 5) {
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -240, 16);
            D_803D552C->unk2B4.state = 2;
            func_80314600_725CB0();
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 351) || ((++D_803D552C->unk2C0 >= 151))) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -240, 16);
        }
    }
}

void func_80385078_796728(void) {
}

void func_80385080_796730(void) {
}

void func_80385088_796738(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C4 == 0) && (func_80383830_794EE0(2) != 0)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 2;
        } else if ((D_803D552C->unk2C4 != 0) && (D_803D552C->unk2D0 < 70)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 4;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 < 70) && (D_803D552C->unk2C4 == 0)) {
            if (func_8038395C_79500C() >= 10) {
                D_803D552C->unk2C4 = 70;
                D_803D552C->unk2B4.state = 3;
                func_8031FB78_731228(20);
            }
        }
        break;
    case 3:
        func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 4;
        D_803D552C->unk2B8 = 0;
        break;
    case 4:
        if ((D_803D552C->unk2D0 >= 0xFA) || (D_803D552C->unk2B8++ >= 0x1F) || (D_803D552C->unk2C4 == 0)) {
            D_803D552C->unk2B4.state = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;

    }
}

void func_803852B8_796968(void) {
}

void func_803852C0_796970(void) {
}

void func_803852C8_796978(void) {
    if (1) {};

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 20);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((func_80383830_794EE0(0xA) != 0) && (D_803D552C->unk2D0 < 0x2E)) {
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 0x38) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 20);
            D_803D552C->unk2B4.state = 1;
        } else {
            func_80327B94_739244(70);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 4;
        // fallthru
    case 4:
        if ((D_803D552C->unk2D0 >= 0xC8) || (D_803D552C->unk2B8++ >= 0x3D)) {
                D_803D552C->unk2B4.state = 1;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 20);
        }
    }
}

void func_80385480_796B30(void) {
}

void func_80385488_796B38(void) {
}

void func_80385490_796B40(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
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
                    D_803D552C->unk2B4.state = 2;
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
            if (D_803D552C->unk2D0 >= 250) {
                D_803D552C->unk2B4.state = 1;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    }
}

void func_80385710_796DC0(void) {
    rmonPrintf("state %d\n", D_803D552C->unk2B4.state);

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 501) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2B8 > 0) {
            D_803D552C->unk2B8 -= 1;
        }
        if (D_803D552C->unk2D0 >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if (((D_803D552C->unk2D0 < 280) && (D_803D552C->unk2B8 <= 0)) ||
                   (D_803D552C->unk2D0 < 120)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            func_80356134_7677E4(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 351) || (D_803D552C->unk2B8++ >= 100)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
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
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (func_80383830_794EE0(2) != 0) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (((D_803D5530->unk5C & 4) != 0) && (D_803D5530->unk60 == D_803D552C->unk2CC)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        }
        if ((D_803D552C->unk2D0 < 70) && (func_80383830_794EE0(5) != 0) && (func_8038395C_79500C() >= 12)) {
            func_80356348_7679F8(20);
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 300) || (D_803D552C->unk2B8++ >= 91)) {
            D_803D552C->unk2B4.state = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
    }
}

void func_80385BE0_797290(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
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
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 200) || (D_803D552C->unk2C0++ >= 61)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_80385DF0_7974A0(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0xFB) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 2;
        } else if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2B4.unk8 > 0)) {
            king_rat_bugel_call(0x78);
            D_803D552C->unk2C4 = 250;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 401) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2B8 <= 0) && (D_803D552C->unk2D0 < 200)) {
            func_8035FE6C_77151C(60);
            D_803D552C->unk2B8 = 180;
        }
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8 -= 1;
    }
}

void func_80385F90_797640(void) {
    if (D_803F63F0 == 0) {
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if (D_803D552C->unk2D0 < 0x65) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.state = 2;
            }
            break;
        case 2:
            if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(80) == 0)) {
                rat_drop_mine();
                D_803D552C->unk2C4 = 0x3C;
            }
            if (D_803D552C->unk2C0 > 0) {
                if (D_803D552C->unk2D0 < 0x96) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2C0 = 0;
                } else if (--D_803D552C->unk2C0 <= 0) {
                    func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
                    D_803D552C->unk2C0 = 0;
                    D_803D552C->unk2B4.state = 1;
                }
            } else if (D_803D552C->unk2D0 >= 0x12C) {
                func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
                D_803D552C->unk2C0 = ((guRandom() & 0x3F) + 0x96);
            }
            break;
        }
    } else if (D_803F63F0 == 1) {
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if (--D_803D552C->unk2C0 <= 0) {
                D_803D552C->unk2B4.state = 2;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            }
            break;
        case 2:
            if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0x29) && (func_80383830_794EE0(15) != 0)) {
                rat_bite();
                D_803D552C->unk2C4 = (func_8012826C() & 3) + 5;
                D_803D552C->unk2BC += 1;
                if (D_803D552C->unk2BC >= 6) {
                    func_80363CE0_775390(D_803D5530, D_803D552C->unk280, -1, 16);
                    D_803D552C->unk2B4.state = 3;
                    D_803D552C->unk2BC = 0;
                }
            }
            break;
        case 3:
            if (D_803E4C3C < 101) {
                func_80363CC8_775378(D_803D5530);
                D_803D552C->unk2B4.state = 4;
                break;
            }
        case 4:
            break;
        }
    } else if (D_803F63F0 == 2) {
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0x47) && (func_80383830_794EE0(15) != 0)) {
                rat_bite();
                D_803D552C->unk2C4 = (func_8012826C() & 3) + 5;
                if (++D_803D552C->unk2BC >= 6) {
                    func_80363CC8_775378(D_803D5530);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                    D_803D552C->unk2C0 = guRandom() & 0x3F;
                }
            }
            break;
        case 2:
            if (--D_803D552C->unk2C0 <= 0) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
                D_803D552C->unk2B4.state = 1;
            }
        }
    }
}

void perform_behavior_sheep(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (--D_803D552C->unk2C0 <= 0) {
            if (D_803D552C->unk2B8++ >= 6) {
                D_803D552C->unk270 = 0;
                D_803D552C->unk272 = D_803D552C->unk2C8;
                D_803D552C->unk2B4.unk4 = 0;
                D_803D552C->unk2CC = 0;
                func_80363FF0_7756A0(D_803D5530);
            } else {
                animal_jump();
                func_80363FB8_775668(D_803D5530, (guRandom() % 360), 0, 16);
                D_803D552C->unk2C0 = ((guRandom() % 0xF) + 20);
            }
        }
        break;
    case 2:
        break;
    }
}

void func_803865A0_797C50(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 40) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0x33) && (D_803D552C->unk2C0 != 0)){
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0x33)) {
            if (func_80383830_794EE0(5) != 0) {
                if (++D_803D552C->unk2BC < 4) {
                    ram_headbutt();
                }
                D_803D552C->unk2C4 = (func_8012826C() & 3) + 5;
                if (D_803D552C->unk2BC >= 3) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 200) || (++D_803D552C->unk2C0 >= 0x1E)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_803867B8_797E68(void) {
}

void func_803867C0_797E70(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x28) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0x33) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0x33)) {
            if (func_80383830_794EE0(5) != 0) {
                if (++D_803D552C->unk2BC < 5) {
                    ram_headbutt();
                }
                D_803D552C->unk2C4 = (func_8012826C() & 3) + 5;
                if (D_803D552C->unk2BC >= 5) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 200) || (++D_803D552C->unk2C0 >= 0x33)) {
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2C0 = 0;
            func_80363CC8_775378(D_803D5530);
        }
        break;
    case 3:
        if (++D_803D552C->unk2C0 >= 71) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_80386A48_7980F8(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2C0 == 1) {
            if (D_803D552C->unk2D0 >= 351) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
                D_803D552C->unk2B4.state = 1;
                D_803D552C->unk2C0 = 0;
            }
        } else if (D_803D552C->unk2D0 < 250) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 1;
        }
        if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            penguin_throw_snowball(D_803D552C->unk2CC);
        }
    }
}

void func_80386BB8_798268(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        D_803D552C->unk2B4.state = 1;
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x32) && (D_803D552C->unk2C0 <= 0) && (D_803D552C->unk2B8 >= 2)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(24) != 0)) {
            func_80368D18_77A3C8();
            D_803D552C->unk2C4 = ((guRandom() & 60) + 25);
            D_803D552C->unk2B8 += 1;
        }
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0xAB) || (D_803D552C->unk2C0++ >= 61)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2C0 = 80;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        }
    }
}

void func_80386D80_798430(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 301) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 301) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if (D_803D552C->unk2D0 < 200) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if (D_803D552C->unk2C4 <= 0) {
            if (func_80383830_794EE0(5) != 0) {
                D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
                func_80368CF0_77A3A0();
            }
        }
        break;
    case 3:
        if (D_803D552C->unk2C4 <= 0) {
            polar_tank_drop_mine();
            D_803D552C->unk2C4 = (guRandom() & 0xF) + 70;
        }
        if (D_803D552C->unk2D0 >= 0xFB) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void func_80386F84_798634(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->unk2D0 < 0x53) && (func_80383830_794EE0(5) != 0)) {
            func_8036C014_77D6C4(0x1E);
            D_803D552C->unk2C4 = 60;
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        D_803D552C->unk2C0 = 0;
        D_803D552C->unk2B4.state = 3;
        // fallthru
    case 3:
        if (D_803D552C->unk2C4 == 0) {
            if ((D_803D552C->unk2D0 >= 200) || (D_803D552C->unk2C0++ >= 0x1E)) {
                D_803D552C->unk2B4.state = 1;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    }
}

void func_8038710C_7987BC(void) {
}

void func_80387114_7987C4(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 401) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if (D_803D552C->unk2D0 >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2D0 < 250) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else {
            if (D_803D552C->unk2C4 <= 0) {
                if (func_80383830_794EE0(20) != 0) {
                    D_803D552C->unk2C4 = (guRandom() % 20) + 20;
                    ski_husky_fire_missile(D_803D552C->unk2CC);
                }
            }
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 351) || (D_803D552C->unk2C0++ >= 71)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void func_80387330_7989E0(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x191) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 = (D_803D552C->unk2C0 - 1);
        }
        if (D_803D552C->unk2D0 >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2D0 < 0xFA) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(0x14) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() % 30) + 30);
            walrus_fire_missile(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0x15F) || (D_803D552C->unk2C0++ >= 0x47)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void func_8038754C_798BFC(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, (-80 - D_803D552C->unk2CC->unk42), 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 2) {
            func_80363CC8_775378(D_803D5530);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 2:
        if ((((D_803D5530->yPos - D_803D552C->unk2CC->yPos) - D_803D552C->unk2CC->unk42) < 0xA) || (D_803D552C->unk2B8++ >= 0x3D)) {
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2C4 = 0x10;
        }
        break;
    case 3:
        if (D_803D552C->unk2C4 <= 0) {
            D_803D552C->unk2B4.state = 4;
            func_80363EDC_77558C(D_803D5530, (-80 - D_803D552C->unk2CC->unk42), D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2C4 % 15) == 0) {
            func_8036D5CC_77EC7C();
        }
        break;
    case 4:
        if ((D_803D552C->unk2D0 >= 0xC9) || (++D_803D552C->unk2C0 >= 0x79)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, (-0x50 - D_803D552C->unk2CC->unk42), 16);
        }
    }
}

void func_80387780_798E30(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0xE6) && (D_803D552C->unk2C0 != 1)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0xFB) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if (D_803D552C->unk2C4 == 1) {
            if (++D_803D552C->unk2BC >= ((guRandom() & 1) + 2)) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.state = 2;
            }
        } else if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0xFB)) {
            if (func_80383830_794EE0(5) != 0) {
                func_8036F50C_780BBC(D_803D552C->unk2CC);
                D_803D552C->unk2C4 = 20;
            }
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0x172) || ((++D_803D552C->unk2C0 >= 0x3C))) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2BC = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_803879A4_799054(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C0 != 2) && (D_803D552C->unk2D0 < 0xFA)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 2;
        } else if ((D_803D552C->unk2C0 != 1) && (D_803D552C->unk2D0 < 300) && (D_803D552C->unk2D0 >= 251)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2C0 != 0) && (D_803D552C->unk2D0 >= 0x15F)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }

        if ((D_803D552C->unk2B8 <= 0) && (D_803D552C->unk2D0 < 70)) {
            func_8036F740_780DF0((func_801284B8(D_803D552C->unk2CC->xPos - D_803D5530->xPos, D_803D552C->unk2CC->zPos - D_803D5530->zPos) * 256) / 360);
            D_803D552C->unk2B8 = 0x14A;
        }
        if ((D_803D552C->unk2C4 <= 0) && (func_803838C8_794F78(D_803D552C->unk308, 5) != 0)) {
            if (D_803D552C->unk2D0 < 0x17D) {
                camel_cannon_fire_cannon(D_803D552C->unk2CC);
                D_803D552C->unk2C4 = ((guRandom() % 0x24) + 25);
            }
        }
        if (D_803D552C->unk2B8 > 0) {
            D_803D552C->unk2B8 -= 1;
        }
    }
}

void func_80387BF4_7992A4(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x12D) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 0x15F) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if (D_803D552C->unk2D0 < 0x96) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            func_80372698_783D48();
            D_803D552C->unk2C4 = (guRandom() % 0x14) + 0x5A;
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0xB5) || (++D_803D552C->unk2C0 >= 0x3D)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void func_80387DE0_799490(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x28) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 < 0x28) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0x3D) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(40) != 0)) {
            func_80372604_783CB4();
            D_803D552C->unk2C4 = ((func_8012826C() % 4)) + 5;
            if (++D_803D552C->unk2BC >= 9) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.state = 3;
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case 3:
        if (++D_803D552C->unk2C0 >= 0x65) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_8038801C_7996CC(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 251) && (func_80383830_794EE0(20) != 0)) {
            func_803745C4_785C74(0x78); // attack?
            D_803D552C->unk2C4 = 0xB4;
        } else if (D_803D552C->unk2C4 > 0) {
            if (D_803D552C->unk2C4 < 0x3D) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.state = 2;
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2C4 = 0xF0;
            }
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 == 0) {
            if (D_803D552C->unk2D0 >= 0x15F) {
                D_803D552C->unk2C0 = 1U;
                func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            }
        } else if (D_803D552C->unk2C0 == 1) {
            if (D_803D552C->unk2D0 < 0x12C) {
                D_803D552C->unk2C0 = 0U;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if (D_803D552C->unk2D0 >= 0x1C3) {
                D_803D552C->unk2C0 = 2;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            }
        } else if (D_803D552C->unk2D0 < 0x190) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        if (D_803D552C->unk2C4 <= 0) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_80388248_7998F8(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x64) && (D_803D552C->unk2B8 <= 0)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2BC = 0;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 < 0xC8) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0x12D) && (1 == D_803D552C->unk2C0)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0xFB) || (++D_803D552C->unk2C0 >= 0x29)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B8 = 0x14;
            D_803D552C->unk2B4.state = 1;
        }
        break;
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8 -= 1;
    }
    if (D_803D552C->unk2D0 < 0x191) {
        if (D_803D552C->unk2C4 <= 0) {
            if (func_80383830_794EE0(0xA) != 0) {
                func_8037460C_785CBC();
                D_803D552C->unk2C4 = ((guRandom() % 5) + 0x11);
            }
        }
    }
}

void func_80388480_799B30(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x32) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if (D_803D552C->unk2D0 >= 0x3D) {
            if (D_803D552C->unk2C0 == 1) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
                D_803D552C->unk2C0 = 0;
            }
        }
        if ((D_803D552C->unk2D0 < 0xFB) && (D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(2) != 0)) {
            func_80379148_78A7F8(D_803D552C->unk2CC);
            D_803D552C->unk2C4 = ((guRandom() % 0x32) + 0x96);
        } else if ((D_803D552C->unk2D0 < 0x3D) && (D_803D552C->unk2B8 <= 0)) {
            if ((D_803D552C->unk2BC < 6) && (D_803D552C->unk2C4 < 0x33)) {
                func_803791AC_78A85C();
                D_803D552C->unk2B8 = (guRandom() % 8) + 9;
                D_803D552C->unk2BC = D_803D552C->unk2BC + 1;
            }
        }
        if ((D_803D552C->unk2C4 > 0) && (D_803D552C->unk2BC >= 6)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2BC = 0;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 401) || (D_803D552C->unk2C0++ >= 90)) { // regalloc here
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 1;
        }
        break;
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8 -= 1;
    }
}

void func_80388744_799DF4(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x32) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 0;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(32) != 0)) {
            func_8037B70C_78CDBC();
            D_803D552C->unk2C4 = (guRandom() % 0x14) + 0x1E;
        }
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0xAB) || (D_803D552C->unk2C0++ >= 0x1F)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0x50;
        }
    }
}

void func_803888F0_799FA0(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0xFB) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 0x137) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            func_8037D268_78E918(0x5A);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2C4 = (guRandom() & 0xF) + 0x5A;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        if ((D_803D552C->unk2C4 < 0x3D)) {
            if (( D_803D552C->unk2D0 < 0x96)) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B8 = 0;
                D_803D552C->unk2B4.state = 4;
            } else {
                func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
                D_803D552C->unk2B4.state = 2;
            }
        }
        break;
    case 4:
        if ((D_803D552C->unk2D0 >= 0xAB) || (D_803D552C->unk2B8++ >= 0x3D)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    }
}

void func_80388B0C_79A1BC(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        D_803D552C->unk2C0 = 2;
        // fallthru
    case 1:
        if (D_803D552C->unk2C0 == 0) {
            if (D_803D552C->unk2D0 >= 0xA1) {
                D_803D552C->unk2C0 = 1;
                func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            }
        } else if (D_803D552C->unk2C0 == 1) {
            if (D_803D552C->unk2D0 < 0x64) {
                D_803D552C->unk2C0 = 0U;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if (D_803D552C->unk2D0 >= 0xB5) {
                D_803D552C->unk2C0 = 2U;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            }
        } else if (D_803D552C->unk2D0 < 0xA0) {
            D_803D552C->unk2C0 = 1U;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }

        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2D0 < 0xC9)) {
            func_8035A590_76BC40(0x10E);
            D_803D552C->unk2C4 = 0x1E0;
        }
        break;
    }
}

void func_80388CC8_79A378(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        D_803D552C->unk2C0 = 0;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x1F5) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if ((D_803D552C->unk2C0 == 0) && (D_803D552C->unk2D0 >= 0x227)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2C0 == 0) && (D_803D552C->unk2D0 < 0x12C)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (func_80383830_794EE0(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 0x14) + 0x14;
            biker_hyena_fire_missile(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0x15F) || (D_803D552C->unk2C0++ >= 0x47)){
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 70;
        }
    }
}

void func_80388F10_79A5C0(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2D0 < 0x32) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0x3D) && (D_803D552C->unk2C0 == 1)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
        }
        if ((D_803D552C->unk2D0 < 0x3D) && (D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2BC < 3)) {
            func_8035C10C_76D7BC();
            D_803D552C->unk2C4 = (guRandom() % 8) + 9;
            D_803D552C->unk2BC += 1;
        } else if (D_803D552C->unk2BC >= 3) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2BC = 0;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 >= 0xC9) || (D_803D552C->unk2C0++ >= 0x5A)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 1;
        }
    }
}

void func_80389150_79A800(void) {
}

void func_80389158_79A808(void) {
}

void func_80389160_79A810(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0xFB) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 2;
        } else if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2B4.unk8 > 0)) {
            func_80365E70_777520(0x78);
            D_803D552C->unk2C4 = 0xFA;
        }
        break;
    case 2:
        if (D_803D552C->unk2D0 >= 0x191) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 1;
        } else if (D_803D552C->unk2C4 <= 0) {
            func_80365E70_777520(0x78);
            D_803D552C->unk2C4 = 0xFA;
        }
    }
}

void func_803892D4_79A984(void) {
}

void func_803892DC_79A98C(void) {
}

void func_803892E4_79A994(void) {
}

void func_803892EC_79A99C(void) {
}

void perform_behavior_seagull(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0x50 - D_803D552C->unk2CC->unk42, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 2) {
            func_80363CC8_775378(D_803D5530);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 2:
        if (((D_803D5530->yPos - D_803D552C->unk2CC->yPos) - D_803D552C->unk2CC->unk42) < 10) {
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2C4 = 0x5B;
        }
        break;
    case 3:
        if (D_803D552C->unk2C4 < 60) {
            D_803D552C->unk2B4.state = 4;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, -0x50 - D_803D552C->unk2CC->unk42, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2C4 % 0xF) == 0) {
            func_80381F14_7935C4(D_803D552C->unk2C4);
        }
        break;
    case 4:
        if ((D_803D552C->unk2D0 >= 0xC9) || (++D_803D552C->unk2C0 >= 0x79)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0x50 - D_803D552C->unk2CC->unk42, 16);
        }
    }
}

void func_8038951C_79ABCC(void) {
}

void func_80389524_79ABD4(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2D0 < 0x28) {
            func_80382CC0_794370(0x96);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C4 = 0x96;
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case 2:
        if ((D_803D552C->unk2D0 < 0x1E) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2D0 >= 0x3D) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if (D_803D552C->unk2C4 <= 0) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2BC = 0;
        }
        break;
    case 3:
        if ((D_803D552C->unk2D0 >= 0xC8) || (++D_803D552C->unk2C0 >= 0x5B)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void func_8038974C_79ADFC(void) {
}

void func_80389754_79AE04(void) {
}

void func_8038975C_79AE0C(void) {
}

void func_80389764_79AE14(u8 arg0) {
    D_803F63F0 = arg0;
    D_803B5D20[D_803D5524->unk9C]();
}

s32 func_803897B0_79AE60(u8 arg0) {
    s16 phi_a3;
    s16 phi_a0;
    s16 sp22;

    if (arg0 == 1) {
        phi_a3 = 10;
        phi_a0 = 20;
        sp22 = 0;
    } else {
        phi_a3 = 16;
        phi_a0 = 15;
        sp22 = 1;
    }

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363FB8_775668(D_803D5530, (guRandom() %  360), -180, phi_a3);
        D_803D552C->unk2B8 = (guRandom() & 0xF) + 20;
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (--D_803D552C->unk2B8 <= 0) {
            func_80363FB8_775668(D_803D5530, (guRandom() %  360), -128, -1);
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2BC = (guRandom() & 3) + 4;
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case 2:
        if (++D_803D552C->unk2B8 >= phi_a0) {
            func_80363FB8_775668(D_803D5530, (guRandom() %  360), -128, -1);
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2BC -= 1;
            if (D_803D552C->unk2BC <= 0) {
                return 1;
            }
        }
    }

    if (sp22 != 0) {
        if (--D_803D552C->unk2C0 <= 0) {
            animal_jump();
            D_803D552C->unk2C0 = (guRandom() & 0xF) + 70;
        }
    }
    return 0;
}

// file boundary?
void func_803899E0_79B090(Animal *arg0) {
    s32 phi_v0;

    if (arg0->unk6C == NULL) {
        if (arg0->unk160 == 2) {
            phi_v0 = D_803E1D3B[D_803C0740_7D1DF0[arg0->xPos >> 6][arg0->zPos >> 6].unk3].unk0;
        } else {
            phi_v0 = D_803E1D3B[D_803C0740_7D1DF0[arg0->xPos >> 6][arg0->zPos >> 6].unk2].unk0;
        }
        if (phi_v0 != arg0->unk4E) {
            if (phi_v0 < arg0->unk4E) {
                if ((ABS(arg0->xVelocity.w) > 32768) || (ABS(arg0->zVelocity.w) > 32768) || (ABS(arg0->yVelocity.w) > 327680)) {
                    arg0->unk4E -= 1;
                }
            } else {
                arg0->unk4E += 1;
            }
        }
    }
}
