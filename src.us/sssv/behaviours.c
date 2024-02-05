#include <ultra64.h>
#include "common.h"


#define BEHAVIOUR_DEFEND 2

// ========================================================
// .data
// ========================================================

#if 0
// NOTE: where is this defined?

// animal stats (message ids)
struct107 D_803B58E0_7C6F90[68] = {
    { 125,  53,  88, 118, 198, 205, 211 }, // seagull, low, flight, claw attack, kerosene, excellent, little lift
    { 126,  57,  76,  77, 195, 206, 210 },
    { 127,  53,  78,  79, 196, 206, 210 },
    { 128,  53,  98,  98, 201, 206, 210 },
    { 129,  53,  80,  81, 193, 206,  56 },
    { 130,  88,  88,  83, 198,  66,  56 },
    { 131,  60,  99,  94, 202, 206,  56 },
    { 132,  60,  80,  81, 200, 206,  56 },
    { 133,  56,  76,  86, 203, 205,  56 },
    { 134,  56, 109, 101,  98, 206, 210 },
    { 135,  56,  76,  87, 203, 206,  56 },
    { 136,  56,  88,  82, 198, 206,  56 },
    { 137,  53,  80,  76, 196, 205, 209 },
    { 138,  60,  90,  91, 201, 206,  56 },
    { 139,  56,  88,  92, 204, 205, 209 },
    { 140,  56,  88,  92, 204, 205, 209 },
    { 141,  57,  76,  93, 202,  66, 209 },
    { 142,  57,  80,  94, 194,  66, 209 },
    { 143,  57,  80,  94, 194,  66, 209 },
    { 144,  56,  88,  95, 198, 205, 211 },
    { 145,  57,  76,  93, 202,  66, 209 },
    { 146,  57,  98,  98, 198,  66, 209 },
    { 147,  53,  95,  96, 196,  66, 212 },
    { 148,  53,  95,  96, 196,  66, 210 },
    { 149,  53,  98,  98, 197,  66, 210 },
    { 150,  53,  88, 118, 198, 205, 211 },
    { 151,  60,  99,  94, 193, 206,  56 },
    { 152,  57, 100, 101, 201, 206, 210 },
    { 153,  57,  80, 102, 193, 206,  56 },
    { 154,  57, 100, 101,  98, 206, 210 },
    { 155,  53,  76,  84, 197, 205,  56 },
    { 156,  53,  76,  84, 202, 205,  56 },
    { 157,  57, 103,  84, 201, 205, 209 },
    { 158,  50, 104, 105, 204, 206, 209 },
    { 159,  53,  76, 106, 202, 206,  56 },
    { 160,  50,  76, 105, 203, 206, 209 },
    { 161,  53,  76, 106, 203, 206,  56 },
    { 162,  56,  76, 108, 202, 205, 209 },
    { 163,  50, 109, 101, 197, 205, 210 },
    { 164,  50, 100, 112, 197, 205, 210 },
    { 165,  56,  76, 113, 202, 206,  56 },
    { 166,  53,  76, 113, 202, 206,  56 },
    { 167,  56,  80,  81, 202,  66,  56 },
    { 168,  57,  88,  82, 198, 206, 209 },
    { 169,  57,  80, 114, 196, 205, 210 },
    { 170,  56,  88,  95, 198, 205, 211 },
    { 171,  57,  76,  89, 204, 206, 210 },
    { 172,  57, 100, 115, 197, 206, 210 },
    { 173,  57,  98,  98, 204, 206, 209 },
    { 174,  56,  76, 116, 203, 206,  56 },
    { 175,  56,  76, 117, 195, 206,  56 },
    { 176,  57,  76, 124, 202,  66, 209 },
    { 177,  57,  76, 100, 202,  66, 209 },
    { 178,  60, 118, 119, 195, 208,  56 },
    { 179,  50, 109,  95, 196, 206, 212 },
    { 180,  57,  76, 124, 195,  66,  56 },
    { 181,  57, 120,  95, 201, 206, 210 },
    { 182,  57,  76, 121, 202, 206,  56 },
    { 183,  57,  80,  81, 194, 206,  56 },
    { 184,  56,  86, 122, 197,  66, 209 },
    { 185,  56,  86, 122, 197,  66, 209 },
    { 186,  60,  98,  98, 202, 206, 209 },
    { 187,  60,  98,  98, 202, 206, 209 },
    { 188,  60,  98,  98, 202, 206, 209 },
    { 189,  57, 107, 123, 199, 205,  56 },
    { 190,  57,  80, 102, 197, 206,  56 },
    { 191,  56,  76,  80, 199, 205, 209 },
    { 192,  56,  88,  98, 202, 206, 210 },
};
#endif

void (*behaviour_lut[AID_MAX_ANIMALS])(void) = {
    perform_behavior_seagull,
    perform_behavior_lion,
    perform_behavior_hippo,
    perform_behavior_racing_hippo,
    perform_behavior_racing_dog,
    perform_behavior_flying_dog,
    perform_behavior_fox,
    perform_behavior_fire_fox,
    perform_behavior_frog,
    perform_behavior_polar_bear_defending,
    perform_behavior_rabbit,
    perform_behavior_heli_rabbit,
    perform_behavior_cod,
    perform_behavior_king_rat,
    perform_behavior_parrot,
    perform_behavior_parrot_attacking,
    perform_behavior_mouse,
    perform_behavior_hard_mouse,
    perform_behavior_racing_mouse,
    perform_behavior_vulture,
    perform_behavior_mouse2,
    perform_behavior_heli_mouse,
    perform_behavior_bear,
    perform_behavior_bear_attacking,
    perform_behavior_mystery_bear,
    perform_behavior_seagull2,
    perform_behavior_racing_fox,
    perform_behavior_tortoise_tank,
    perform_behavior_racing_tortoise,
    perform_behavior_tortoise_tank_defending,
    perform_behavior_pirana,
    perform_behavior_dog,
    perform_behavior_rat,
    perform_behavior_sheep,
    perform_behavior_ram,
    perform_behavior_springy_thingy,
    perform_behavior_springy_ram,
    perform_behavior_penguin,
    perform_behavior_polar_bear,
    perform_behavior_polar_tank,
    perform_behavior_husky,
    perform_behavior_crazy_husky,
    perform_behavior_ski_husky,
    perform_behavior_crow,
    perform_behavior_walrus,
    perform_behavior_vulture2,
    perform_behavior_camel,
    perform_behavior_cannon_camel,
    perform_behavior_crow_diver,
    perform_behavior_pogo_kangaroo,
    perform_behavior_boxing_kangaroo,
    perform_behavior_desert_fox,
    perform_behavior_armed_desert_fox,
    perform_behavior_scorpion,
    perform_behavior_gorilla,
    perform_behavior_desert_fox,
    perform_behavior_elephant,
    perform_behavior_hyena,
    perform_behavior_hyena_biker,
    perform_behavior_chameleon,
    perform_behavior_sneaky_chameleon,
    perform_behavior_evo,
    perform_behavior_evo,
    perform_behavior_evo,
    perform_behavior_king_penguin,
    perform_behavior_racing_tortoise_defending,
    perform_behavior_cool_cod,
    perform_behavior_evo
};

// ========================================================
// .bss (D_803F63F0 to D_803F6400)
// ========================================================

static s16  D_803F63F0; // only used by RAT

// ========================================================
// .text
// ========================================================

// ESA: func_80064DC4
s32 target_within_current_fov(u16 fov) {
    Animal *target = D_803D552C->unk2CC;
    if (fov < func_803051F0_7168A0((func_801284B8(target->position.xPos.h - D_803D5530->position.xPos.h, target->position.zPos.h - D_803D5530->position.zPos.h) * 256) / 360, D_803D5530->yRotation)) {
        return 0;
    } else {
        return 1;
    }
}

// ESA: func_80064E6C
s32 target_within_custom_fov(u16 rotation, u16 fov) {
    Animal *a = D_803D552C->unk2CC;

    if (fov < func_803051F0_7168A0(((func_801284B8(a->position.xPos.h - D_803D5530->position.xPos.h, a->position.zPos.h - D_803D5530->position.zPos.h) * 256) / 360), rotation)) {
        return 0;
    } else {
        return 1;
    }
}

// ESA: func_80064F18
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

// ESA: func_80064FB4
void perform_behavior_lion(void) {
    if (1) {}; // needed for regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 100) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 111) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 101) && (target_within_current_fov(5) != 0)) {
            lion_roar();
            D_803D552C->unk2C4 = (func_8012826C() % 40) + 50;
        } else if (D_803D552C->unk2C4 <= 0) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 200) || (D_803D552C->unk2B8++ >= 61)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

// ESA: func_8006521C
void perform_behavior_hippo(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2C0 = 0;
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 100) && (D_803D552C->unk2C0 == 0)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 1;
        } else if ((D_803D552C->targetDistance >= 121) && (D_803D552C->unk2C0 == 1)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
        }
        if ((target_within_current_fov(5) != 0) && (D_803D552C->targetDistance < 350) && (D_803D552C->unk2C4 <= 0)) {
            if (D_803D552C->unk2B8 >= 2) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B8 = 0;
                D_803D552C->unk2B4.state = 2;
            } else {
                hippo_spit(0, 0, 0);
                D_803D552C->unk2C4 = RAND(5) + 30;
                D_803D552C->unk2B8 += 1;
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((target_within_current_fov(80) == 0) && (D_803D552C->unk2C4 <= 0)) {
            drop_sticky_mine();
            D_803D552C->unk2C4 = 60;
        }
        if ((D_803D552C->targetDistance >= 401) || (D_803D552C->unk2B8++ >= 60)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
        }
    }
}

void perform_behavior_racing_hippo(void) {
    // no racing hippo behavior
}

void perform_behavior_racing_dog(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 401) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if (D_803D552C->targetDistance >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->targetDistance < 300) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0) ){
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            racing_dog_fire_missile(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 351) || (D_803D552C->unk2C0++ >= 61) ) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void perform_behavior_flying_dog(void) {
    if ((D_803D552C->unk2CC->unk16C->class == CLASS_FLYING) ||
        (D_803D552C->unk2CC->unk16C->class == CLASS_HELI) ||
        (D_803D552C->unk2CC->unk16C->class == CLASS_BIRD)) {
        // typo
        rmonPrintf("staet %d FC %d\n", D_803D552C->unk2B4.state, D_803D552C->unk2C4);
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if (D_803D552C->targetDistance < 100) {
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.state = 2;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if ((target_within_current_fov(5) != 0) && (D_803D552C->targetDistance < 220) && (D_803D552C->unk2C4 == 0)) {
                D_803D552C->unk2C4 = 140;
            }
            if ((D_803D552C->unk2C4 > 0) && (D_803D552C->unk2C4 >= 100) && ((D_803D552C->unk2C4 & 3) == 0)) {
                flying_dog_fire_gun(0, 0, 0);
            }
            break;
        case BEHAVIOUR_DEFEND:
            if ((D_803D552C->unk2C4 == 0) && (D_803D552C->targetDistance > 250)) {
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
            if (D_803D552C->targetDistance < 64) {
                D_803D552C->unk2B4.state = 3;
                func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -180, 16);
            } else if ((D_803D552C->unk2C4 == 0) && (target_within_current_fov(10) != 0) && (D_803D552C->targetDistance < 200)) {
                D_803D552C->unk2C4 = 80;
                D_803D552C->unk2B4.state = 2;
                func_80363FB8_775668(D_803D5530, (D_803D5530->yRotation * 360) >> 8, -180, 16);
            }
            break;
        case BEHAVIOUR_DEFEND:
            if ((D_803D552C->unk2C4 >= 60) && ((D_803D552C->unk2C4 % 5) == 0)) {
                flying_dog_drop_bomb(0, 0, 0);
            } else if (D_803D552C->unk2C4 < 60) {
                D_803D552C->unk2B4.state = 3;
                func_80363FB8_775668(D_803D5530, (D_803D5530->yRotation * 360) >> 8, -180, 16);
                return;
            }
            break;
        case 3:
            if ((D_803D552C->targetDistance >= 0x119) || (D_803D552C->unk2C4 == 0)) {
                D_803D552C->unk2B4.state = 1;
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
            }
        }
    }
}

void perform_behavior_fox(void) {
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
        } else if ((D_803D552C->unk2C0 == 0) && ((D_803D5530->unk5C.unk0 & 4) != 0) && (D_803D5530->unk5C.unk4 == D_803D552C->unk2CC)) {
            D_803D552C->unk2C0 = 40;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 51) && (target_within_current_fov(5) != 0)) {
            func_802E88C0_6F9F70(100);
            D_803D552C->unk2C4 = SSSV_RAND(8) + 25;
            D_803D552C->unk2BC += 1;
            if (D_803D552C->unk2BC >= 3) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.state = 2;
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 100) || (++D_803D552C->unk2C0 >= 0x1F)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_fire_fox(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -70, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0x78) {
            D_803D552C->unk2B4.state = 2;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->targetDistance < 200) && (target_within_current_fov(20) != 0)) {
            fire_fox_fire_missile(D_803D552C->unk2CC);
            D_803D552C->unk2C4 = 0x96;
            D_803D552C->unk2B4.state = 2;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->targetDistance >= 0xF1)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -70, 16);
        }
    }
}

void perform_behavior_frog(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 61) {
            D_803D552C->unk2B4.state = 2;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 61) && (D_803D552C->unk2BC < 4)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            D_803D552C->unk2BC += 1;
            if (D_803D552C->unk2BC < 4) {
                frog_croak();
            }
            D_803D552C->unk2C4 =  SSSV_RAND(8) + 10;
            if (D_803D552C->unk2BC >= 5) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2B4.state = 3;
                D_803D552C->unk2BC = 0;
            }
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 250) || (++D_803D552C->unk2C0 >= 0x29)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_rabbit(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        D_803D552C->unk2C0 = 0;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 201) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if ((D_803D552C->unk2C0 == 0) && (D_803D552C->targetDistance >= 0xFB)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2C0 == 0) && (D_803D552C->targetDistance < 100)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            func_803021A8_713858();
            D_803D552C->unk2C4 = SSSV_RAND(32) + 40;
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 301) || (D_803D552C->unk2C0++ >= 101)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 100;
        }
    }
}

void perform_behavior_heli_rabbit(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -200, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 64) {
            D_803D552C->unk2B4.state = 3;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -200, 16);
        } else if ((target_within_current_fov(10) != 0) && (D_803D552C->targetDistance < 180)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C4 = 80;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -200, 16);
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->unk2C4 >= 60) && ((D_803D552C->unk2C4 % 5) == 0)) {
            heli_rabbit_drop_bomb(0, 0, 0);
        } else if (D_803D552C->unk2C4 < 60) {
            D_803D552C->unk2B4.state = 3;
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -180, 16);
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 0xC9) || ((D_803D552C->unk2C4 == 0))) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -180, 16);
        }
    }
}

void perform_behavior_cod(void) {
}

void perform_behavior_parrot(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -240, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 5) {
            func_80363FB8_775668(D_803D5530, ((D_803D5530->yRotation * 360) >> 8), -240, 16);
            D_803D552C->unk2B4.state = 2;
            parrot_fly();
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 351) || ((++D_803D552C->unk2C0 >= 151))) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -240, 16);
        }
    }
}

void perform_behavior_parrot_attacking(void) {
}

void perform_behavior_mouse(void) {
}

void perform_behavior_racing_mouse(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C4 == 0) && (target_within_current_fov(2) != 0)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 2;
        } else if ((D_803D552C->unk2C4 != 0) && (D_803D552C->targetDistance < 70)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 4;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance < 70) && (D_803D552C->unk2C4 == 0)) {
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
        if ((D_803D552C->targetDistance >= 0xFA) || (D_803D552C->unk2B8++ >= 0x1F) || (D_803D552C->unk2C4 == 0)) {
            D_803D552C->unk2B4.state = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;

    }
}

void perform_behavior_mouse2(void) {
}

void perform_behavior_heli_mouse(void) {
}

void perform_behavior_bear(void) {
    if (1) {};

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 20);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((target_within_current_fov(0xA) != 0) && (D_803D552C->targetDistance < 0x2E)) {
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->targetDistance >= 0x38) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 20);
            D_803D552C->unk2B4.state = 1;
        } else {
            func_80327B94_739244(70);
            D_803D552C->unk2B4.state = 3; // ATTACKING
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 4;
        // fallthru
    case 4:
        if ((D_803D552C->targetDistance >= 0xC8) || (D_803D552C->unk2B8++ >= 0x3D)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 20);
        }
    }
}

void perform_behavior_bear_attacking(void) {
}

void perform_behavior_mystery_bear(void) {
}

void perform_behavior_racing_fox(void) {
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
                if ((D_803D5530->unk5C.unk0 & 4) != 0) {
                    if (D_803D5530->unk5C.unk4 == D_803D552C->unk2CC) {
                        D_803D552C->unk2C0 = 40;
                        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
                    }
                }
            }
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 51)) {
            if (target_within_current_fov(5) != 0) {
                D_803D552C->unk2BC += 1;
                if (D_803D552C->unk2BC < 4) {
                    func_802E88C0_6F9F70(100);
                }
                D_803D552C->unk2C4 = SSSV_RAND(8) + 10;
                if (D_803D552C->unk2BC >= 4) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2B8 = 0;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->unk2B8 == 0) && (target_within_current_fov(80) == 0)) {
            D_803D552C->unk2B8 = 1;
            if ((guRandom() & 3) == 0) {
                 fox_warp();
            }
        } else {
            if (D_803D552C->targetDistance >= 250) {
                D_803D552C->unk2B4.state = 1;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    }
}

void perform_behavior_tortoise_tank(void) {
    rmonPrintf("state %d\n", D_803D552C->unk2B4.state);

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 501) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2B8 > 0) {
            D_803D552C->unk2B8--;
        }
        if (D_803D552C->targetDistance >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if (((D_803D552C->targetDistance < 280) && (D_803D552C->unk2B8 <= 0)) ||
                   (D_803D552C->targetDistance < 120)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            tortoise_tank_attack(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 351) || (D_803D552C->unk2B8++ >= 100)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            if (D_803D552C->unk2B8 >= 90) {
                D_803D552C->unk2B8 = 100;
            } else {
                D_803D552C->unk2B8 = 0;
            }
        } else if (D_803D552C->targetDistance < 0x78) {
            tortoise_tank_defend(32000);
        }
    }

    if (D_803D552C->unk2C0 > 0) {
        D_803D552C->unk2C0 -= 1;
    }
}

void perform_behavior_tortoise_tank_defending(void) {
    if (D_803D552C->targetDistance >= 131) {
        tortoise_tank_defend(0);
    }
}

void perform_behavior_racing_tortoise(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (target_within_current_fov(2) != 0) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (((D_803D5530->unk5C.unk0 & 4) != 0) && (D_803D5530->unk5C.unk4 == D_803D552C->unk2CC)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        }
        if ((D_803D552C->targetDistance < 70) && (target_within_current_fov(5) != 0) && (func_8038395C_79500C() >= 12)) {
            racing_tortoise_defend(20);
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 300) || (D_803D552C->unk2B8++ >= 91)) {
            D_803D552C->unk2B4.state = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
    }
}

void perform_behavior_dog(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x28) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if (D_803D552C->targetDistance >= 0x33) {
            if (D_803D552C->unk2C0 != 0) {
                D_803D552C->unk2C0 = 0;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0x33)) {
            if (target_within_current_fov(5) != 0) {
                D_803D552C->unk2BC = (D_803D552C->unk2BC + 1);
                if (D_803D552C->unk2BC < 4) {
                    dog_bite();
                }
                D_803D552C->unk2C4 = SSSV_RAND(4) + 5;
                if (D_803D552C->unk2BC >= 5) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 200) || (D_803D552C->unk2C0++ >= 61)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

// ESA: func_800676D4
void perform_behavior_king_rat(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0xFB) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 2;
        } else if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2B4.unk8 > 0)) {
            king_rat_bugel_call(0x78);
            D_803D552C->unk2C4 = 250;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->targetDistance >= 401) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2B8 <= 0) && (D_803D552C->targetDistance < 200)) {
            king_rat_fart(60);
            D_803D552C->unk2B8 = 180;
        }
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8--;
    }
}

void perform_behavior_rat(void) {
    if (D_803F63F0 == 0) {
        switch (D_803D552C->unk2B4.state) {
        case 0:
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 1;
            // fallthru
        case 1:
            if (D_803D552C->targetDistance < 0x65) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.state = 2;
            }
            break;
        case BEHAVIOUR_DEFEND:
            if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(80) == 0)) {
                rat_drop_mine();
                D_803D552C->unk2C4 = 0x3C;
            }
            if (D_803D552C->unk2C0 > 0) {
                if (D_803D552C->targetDistance < 0x96) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2C0 = 0;
                } else if (--D_803D552C->unk2C0 <= 0) {
                    func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
                    D_803D552C->unk2C0 = 0;
                    D_803D552C->unk2B4.state = 1;
                }
            } else if (D_803D552C->targetDistance >= 0x12C) {
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
        case BEHAVIOUR_DEFEND:
            if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0x29) && (target_within_current_fov(15) != 0)) {
                rat_bite();
                D_803D552C->unk2C4 = SSSV_RAND(4) + 5;
                D_803D552C->unk2BC += 1;
                if (D_803D552C->unk2BC >= 6) {
                    func_80363CE0_775390(D_803D5530, D_803D552C->unk280, -1, 16);
                    D_803D552C->unk2B4.state = 3;
                    D_803D552C->unk2BC = 0;
                }
            }
            break;
        case 3:
            if (D_803E4BE0.distance < 101) {
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
            if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0x47) && (target_within_current_fov(15) != 0)) {
                rat_bite();
                D_803D552C->unk2C4 = SSSV_RAND(4) + 5;
                if (++D_803D552C->unk2BC >= 6) {
                    func_80363CC8_775378(D_803D5530);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                    D_803D552C->unk2C0 = guRandom() & 0x3F;
                }
            }
            break;
        case BEHAVIOUR_DEFEND:
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
                func_80363FB8_775668(D_803D5530, RAND(360), 0, 16);
                D_803D552C->unk2C0 = (RAND(0xF) + 20);
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        break;
    }
}

void perform_behavior_ram(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 40) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0x33) && (D_803D552C->unk2C0 != 0)){
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0x33)) {
            if (target_within_current_fov(5) != 0) {
                if (++D_803D552C->unk2BC < 4) {
                    ram_headbutt();
                }
                D_803D552C->unk2C4 = SSSV_RAND(4) + 5;
                if (D_803D552C->unk2BC >= 3) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 200) || (++D_803D552C->unk2C0 >= 0x1E)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_springy_thingy(void) {
}

void perform_behavior_springy_ram(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x28) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0x33) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0x33)) {
            if (target_within_current_fov(5) != 0) {
                if (++D_803D552C->unk2BC < 5) {
                    ram_headbutt();
                }
                D_803D552C->unk2C4 = SSSV_RAND(4) + 5;
                if (D_803D552C->unk2BC >= 5) {
                    func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                    D_803D552C->unk2B4.state = 2;
                    D_803D552C->unk2BC = 0;
                }
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 200) || (++D_803D552C->unk2C0 >= 0x33)) {
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

void perform_behavior_penguin(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->unk2C0 == 1) {
            if (D_803D552C->targetDistance >= 351) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
                D_803D552C->unk2B4.state = 1;
                D_803D552C->unk2C0 = 0;
            }
        } else if (D_803D552C->targetDistance < 250) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 1;
        }
        if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
            penguin_throw_snowball(D_803D552C->unk2CC);
        }
    }
}

void perform_behavior_polar_bear(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        D_803D552C->unk2B4.state = 1;
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x32) && (D_803D552C->unk2C0 <= 0) && (D_803D552C->unk2B8 >= 2)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(24) != 0)) {
            polar_bear_jump_thump();
            D_803D552C->unk2C4 = ((guRandom() & 60) + 25);
            D_803D552C->unk2B8 += 1;
        }
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 0xAB) || (D_803D552C->unk2C0++ >= 61)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2C0 = 80;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        }
    }
}

void perform_behavior_polar_tank(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 301) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->targetDistance >= 301) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if (D_803D552C->targetDistance < 200) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if (D_803D552C->unk2C4 <= 0) {
            if (target_within_current_fov(5) != 0) {
                D_803D552C->unk2C4 = ((guRandom() >> 8) % 20) + 20;
                polar_tank_fire_cannon();
            }
        }
        break;
    case 3:
        if (D_803D552C->unk2C4 <= 0) {
            polar_tank_drop_mine();
            D_803D552C->unk2C4 = (guRandom() & 0xF) + 70;
        }
        if (D_803D552C->targetDistance >= 0xFB) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void perform_behavior_husky(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C4 == 0) && (D_803D552C->targetDistance < 0x53) && (target_within_current_fov(5) != 0)) {
            func_8036C014_77D6C4(0x1E);
            D_803D552C->unk2C4 = 60;
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        D_803D552C->unk2C0 = 0;
        D_803D552C->unk2B4.state = 3;
        // fallthru
    case 3:
        if (D_803D552C->unk2C4 == 0) {
            if ((D_803D552C->targetDistance >= 200) || (D_803D552C->unk2C0++ >= 0x1E)) {
                D_803D552C->unk2B4.state = 1;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
            }
        }
    }
}

void perform_behavior_crazy_husky(void) {
}

void perform_behavior_ski_husky(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 401) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if (D_803D552C->targetDistance >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->targetDistance < 250) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else {
            if (D_803D552C->unk2C4 <= 0) {
                if (target_within_current_fov(20) != 0) {
                    D_803D552C->unk2C4 = RAND(20) + 20;
                    ski_husky_fire_missile(D_803D552C->unk2CC);
                }
            }
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 351) || (D_803D552C->unk2C0++ >= 71)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void perform_behavior_walrus(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0x191) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 = (D_803D552C->unk2C0 - 1);
        }
        if (D_803D552C->targetDistance >= 441) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->targetDistance < 0xFA) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(0x14) != 0)) {
            D_803D552C->unk2C4 = (RAND(30) + 30);
            walrus_fire_missile(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 0x15F) || (D_803D552C->unk2C0++ >= 0x47)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void perform_behavior_vulture2(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, (-80 - D_803D552C->unk2CC->unk42), 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 2) {
            func_80363CC8_775378(D_803D5530);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((((D_803D5530->position.yPos.h - D_803D552C->unk2CC->position.yPos.h) - D_803D552C->unk2CC->unk42) < 0xA) || (D_803D552C->unk2B8++ >= 0x3D)) {
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
        if ((D_803D552C->targetDistance >= 0xC9) || (++D_803D552C->unk2C0 >= 0x79)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, (-0x50 - D_803D552C->unk2CC->unk42), 16);
        }
    }
}

void perform_behavior_camel(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0xE6) && (D_803D552C->unk2C0 != 1)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0xFB) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if (D_803D552C->unk2C4 == 1) {
            if (++D_803D552C->unk2BC >= ((guRandom() & 1) + 2)) {
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
                D_803D552C->unk2C0 = 0;
                D_803D552C->unk2B4.state = 2;
            }
        } else if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0xFB)) {
            if (target_within_current_fov(5) != 0) {
                camel_fire_water_cannon(D_803D552C->unk2CC);
                D_803D552C->unk2C4 = 20;
            }
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 0x172) || ((++D_803D552C->unk2C0 >= 0x3C))) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2BC = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_cannon_camel(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C0 != 2) && (D_803D552C->targetDistance < 0xFA)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 2;
        } else if ((D_803D552C->unk2C0 != 1) && (D_803D552C->targetDistance < 300) && (D_803D552C->targetDistance >= 251)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->unk2C0 != 0) && (D_803D552C->targetDistance >= 0x15F)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }

        if ((D_803D552C->unk2B8 <= 0) && (D_803D552C->targetDistance < 70)) {
            cannon_camel_dash((func_801284B8(D_803D552C->unk2CC->position.xPos.h - D_803D5530->position.xPos.h, D_803D552C->unk2CC->position.zPos.h - D_803D5530->position.zPos.h) * 256) / 360);
            D_803D552C->unk2B8 = 0x14A;
        }
        if ((D_803D552C->unk2C4 <= 0) && (target_within_custom_fov(D_803D552C->unk308, 5) != 0)) {
            if (D_803D552C->targetDistance < 0x17D) {
                cannon_camel_fire_cannon(D_803D552C->unk2CC);
                D_803D552C->unk2C4 = (RAND(0x24) + 25);
            }
        }
        if (D_803D552C->unk2B8 > 0) {
            D_803D552C->unk2B8--;
        }
    }
}

void perform_behavior_pogo_kangaroo(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0x12D) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->targetDistance >= 0x15F) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if (D_803D552C->targetDistance < 0x96) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            func_80372698_783D48();
            D_803D552C->unk2C4 = RAND(0x14) + 0x5A;
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 0xB5) || (++D_803D552C->unk2C0 >= 0x3D)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
    }
}

void perform_behavior_boxing_kangaroo(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0x28) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance < 0x28) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0x3D) && (D_803D552C->unk2C0 != 0)) {
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
        if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(40) != 0)) {
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

void perform_behavior_desert_fox(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 251) && (target_within_current_fov(20) != 0)) {
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
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2C0 == 0) {
            if (D_803D552C->targetDistance >= 0x15F) {
                D_803D552C->unk2C0 = 1U;
                func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            }
        } else if (D_803D552C->unk2C0 == 1) {
            if (D_803D552C->targetDistance < 0x12C) {
                D_803D552C->unk2C0 = 0U;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if (D_803D552C->targetDistance >= 0x1C3) {
                D_803D552C->unk2C0 = 2;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            }
        } else if (D_803D552C->targetDistance < 0x190) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        if (D_803D552C->unk2C4 <= 0) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_armed_desert_fox(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x64) && (D_803D552C->unk2B8 <= 0)) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2BC = 0;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance < 0xC8) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0x12D) && (1 == D_803D552C->unk2C0)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 0xFB) || (++D_803D552C->unk2C0 >= 0x29)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B8 = 0x14;
            D_803D552C->unk2B4.state = 1;
        }
        break;
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8--;
    }
    if (D_803D552C->targetDistance < 0x191) {
        if (D_803D552C->unk2C4 <= 0) {
            if (target_within_current_fov(0xA) != 0) {
                func_8037460C_785CBC();
                D_803D552C->unk2C4 = (RAND(5) + 0x11);
            }
        }
    }
}

void perform_behavior_scorpion(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x32) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if (D_803D552C->targetDistance >= 0x3D) {
            if (D_803D552C->unk2C0 == 1) {
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
                D_803D552C->unk2C0 = 0;
            }
        }
        if ((D_803D552C->targetDistance < 0xFB) && (D_803D552C->unk2C4 <= 0) && (target_within_current_fov(2) != 0)) {
            func_80379148_78A7F8(D_803D552C->unk2CC);
            D_803D552C->unk2C4 = (RAND(0x32) + 0x96);
        } else if ((D_803D552C->targetDistance < 0x3D) && (D_803D552C->unk2B8 <= 0)) {
            if ((D_803D552C->unk2BC < 6) && (D_803D552C->unk2C4 < 0x33)) {
                func_803791AC_78A85C();
                D_803D552C->unk2B8 = RAND(8) + 9;
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
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 401) || (D_803D552C->unk2C0++ >= 90)) { // regalloc here
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 1;
        }
        break;
    }

    if (D_803D552C->unk2B8 > 0) {
        D_803D552C->unk2B8--;
    }
}

void perform_behavior_gorilla(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x32) && (D_803D552C->unk2C0 <= 0)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 0;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(32) != 0)) {
            func_8037B70C_78CDBC();
            D_803D552C->unk2C4 = RAND(0x14) + 0x1E;
        }
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 0xAB) || (D_803D552C->unk2C0++ >= 0x1F)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0x50;
        }
    }
}

void perform_behavior_elephant(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0xFB) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->targetDistance >= 0x137) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            func_8037D268_78E918(0x5A);
            D_803D552C->unk2B4.state = 3;
            D_803D552C->unk2C4 = (guRandom() & 0xF) + 0x5A;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case 3:
        if ((D_803D552C->unk2C4 < 0x3D)) {
            if (( D_803D552C->targetDistance < 0x96)) {
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
        if ((D_803D552C->targetDistance >= 0xAB) || (D_803D552C->unk2B8++ >= 0x3D)) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    }
}

void perform_behavior_hyena(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        D_803D552C->unk2C0 = 2;
        // fallthru
    case 1:
        if (D_803D552C->unk2C0 == 0) {
            if (D_803D552C->targetDistance >= 0xA1) {
                D_803D552C->unk2C0 = 1;
                func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            }
        } else if (D_803D552C->unk2C0 == 1) {
            if (D_803D552C->targetDistance < 0x64) {
                D_803D552C->unk2C0 = 0U;
                func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            } else if (D_803D552C->targetDistance >= 0xB5) {
                D_803D552C->unk2C0 = 2U;
                func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            }
        } else if (D_803D552C->targetDistance < 0xA0) {
            D_803D552C->unk2C0 = 1U;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }

        if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->targetDistance < 0xC9)) {
            func_8035A590_76BC40(0x10E);
            D_803D552C->unk2C4 = 0x1E0;
        }
        break;
    }
}

void perform_behavior_hyena_biker(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        D_803D552C->unk2C0 = 0;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0x1F5) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->unk2C0 > 0) {
            D_803D552C->unk2C0 -= 1;
        }
        if ((D_803D552C->unk2C0 == 0) && (D_803D552C->targetDistance >= 0x227)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 10);
            D_803D552C->unk2B4.state = 1;
        } else if ((D_803D552C->unk2C0 == 0) && (D_803D552C->targetDistance < 0x12C)) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 3;
        } else if ((D_803D552C->unk2C4 <= 0) && (target_within_current_fov(5) != 0)) {
            D_803D552C->unk2C4 = ((guRandom() >> 8) % 0x14) + 0x14;
            biker_hyena_fire_missile(D_803D552C->unk2CC);
        }
        break;
    case 3:
        if ((D_803D552C->targetDistance >= 0x15F) || (D_803D552C->unk2C0++ >= 0x47)){
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C0 = 70;
        }
    }
}

void perform_behavior_chameleon(void) {
    if (1) {}; // regalloc

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if ((D_803D552C->targetDistance < 0x32) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0x3D) && (D_803D552C->unk2C0 == 1)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
        }
        if ((D_803D552C->targetDistance < 0x3D) && (D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2BC < 3)) {
            chameleon_attack_2();
            D_803D552C->unk2C4 = RAND(8) + 9;
            D_803D552C->unk2BC += 1;
        } else if (D_803D552C->unk2BC >= 3) {
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2BC = 0;
            D_803D552C->unk2C0 = 0;
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance >= 0xC9) || (D_803D552C->unk2C0++ >= 0x5A)) {
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 1;
        }
    }
}

void perform_behavior_sneaky_chameleon(void) {
}

void perform_behavior_evo(void) {
}

void perform_behavior_king_penguin(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0xFB) {
            func_80363EDC_77558C(D_803D5530, 0, D_803D552C->unk2CC);
            D_803D552C->unk2C0 = 0;
            D_803D552C->unk2B4.state = 2;
        } else if ((D_803D552C->unk2C4 <= 0) && (D_803D552C->unk2B4.unk8 > 0)) {
            func_80365E70_777520(0x78);
            D_803D552C->unk2C4 = 0xFA;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (D_803D552C->targetDistance >= 0x191) {
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
            D_803D552C->unk2B4.state = 1;
        } else if (D_803D552C->unk2C4 <= 0) {
            func_80365E70_777520(0x78);
            D_803D552C->unk2C4 = 0xFA;
        }
    }
}

void perform_behavior_racing_tortoise_defending(void) {
}

void perform_behavior_polar_bear_defending(void) {
}

void perform_behavior_hard_mouse(void) {
}

void perform_behavior_vulture(void) {
}

void perform_behavior_seagull(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0x50 - D_803D552C->unk2CC->unk42, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 2) {
            func_80363CC8_775378(D_803D5530);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2B8 = 0;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (((D_803D5530->position.yPos.h - D_803D552C->unk2CC->position.yPos.h) - D_803D552C->unk2CC->unk42) < 10) {
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
            func_80381F14_7935C4();
        }
        break;
    case 4:
        if ((D_803D552C->targetDistance >= 0xC9) || (++D_803D552C->unk2C0 >= 0x79)) {
            D_803D552C->unk2B4.state = 1;
            D_803D552C->unk2C0 = 0;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -0x50 - D_803D552C->unk2CC->unk42, 16);
        }
    }
}

void perform_behavior_seagull2(void) {
}

void perform_behavior_pirana(void) {
    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, -1, 16);
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (D_803D552C->targetDistance < 0x28) {
            func_80382CC0_794370(0x96);
            D_803D552C->unk2B4.state = 2;
            D_803D552C->unk2C4 = 0x96;
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        }
        break;
    case BEHAVIOUR_DEFEND:
        if ((D_803D552C->targetDistance < 0x1E) && (D_803D552C->unk2C0 == 0)) {
            D_803D552C->unk2C0 = 1;
            func_80363E88_775538(D_803D5530, D_803D552C->unk2CC);
        } else if ((D_803D552C->targetDistance >= 0x3D) && (D_803D552C->unk2C0 != 0)) {
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
        if ((D_803D552C->targetDistance >= 0xC8) || (++D_803D552C->unk2C0 >= 0x5B)) {
            D_803D552C->unk2B4.state = 1;
            func_80363CE0_775390(D_803D5530, D_803D552C->unk2CC, 0, 16);
        }
    }
}

void perform_behavior_crow(void) {
    // no behavior for crow
}

void perform_behavior_crow_diver(void) {
    // no behavior for pogo kangaroo
}

void perform_behavior_cool_cod(void) {
    // no behaviour for cool cod
}

// ESA: func_8006B844
void func_80389764_79AE14(u8 arg0) {
    D_803F63F0 = arg0;
    behaviour_lut[D_803D5524->unk9C]();
}

// file split ?

s32 func_803897B0_79AE60(u8 arg0) {
    s16 phi_a3;
    s16 delay;
    s16 allowJump;

    if (arg0 == 1) {
        phi_a3 = 10;
        delay = 20;
        allowJump = 0;
    } else {
        phi_a3 = 16;
        delay = 15;
        allowJump = 1;
    }

    switch (D_803D552C->unk2B4.state) {
    case 0:
        func_80363FB8_775668(D_803D5530, guRandom() % 360, -180, phi_a3);
        D_803D552C->unk2B8 = (guRandom() & 0xF) + 20;
        D_803D552C->unk2B4.state = 1;
        // fallthru
    case 1:
        if (--D_803D552C->unk2B8 <= 0) {
            func_80363FB8_775668(D_803D5530, guRandom() % 360, -128, -1);
            D_803D552C->unk2B8 = 0;
            D_803D552C->unk2BC = (guRandom() & 3) + 4;
            D_803D552C->unk2B4.state = 2;
        }
        break;
    case BEHAVIOUR_DEFEND:
        if (++D_803D552C->unk2B8 >= delay) {
            func_80363FB8_775668(D_803D5530, guRandom() % 360, -128, -1);
            D_803D552C->unk2B8 = 0;
            if (--D_803D552C->unk2BC <= 0) {
                return 1;
            }
        }
    }

    if (allowJump) {
        if (--D_803D552C->unk2C0 <= 0) {
            animal_jump();
            D_803D552C->unk2C0 = (guRandom() & 0xF) + 70;
        }
    }
    return 0;
}
