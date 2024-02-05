#include <ultra64.h>
#include "common.h"
#include "pp.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (D_803F63D0 to D_803F63E0)
// ========================================================

static u16  D_803F63D0; // laughter check?

// ========================================================
// .text
// ========================================================

void func_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D2E4_78E994(s32 arg0) {
    u8 *nonsense;
    UnpackRNC((RNC_fileptr)nonsense, (u8*)D_800DF220);
}

void func_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D320_78E9D0(s32 arg0, s32 arg1) {
}

void func_8037D32C_78E9DC(s32 arg0, u8 arg1, s32 arg2, u16 arg3, s32 arg4) {
}

// file split?

// ESA: func_80076864
void func_8037D340_78E9F0(s16 arg0, s16 arg1) {
    s16 temp_a0_2;
    s16 temp_t7;
    s16 sp9A;
    s16 sp98;
    Animal *animal;
    s16 temp_v0_3;
    s16 phi_t2;
    s16 sp8E;
    s16 sp8C;

    s16 temp_t5;
    s16 phi_a2;
    s32 damage;
    s16 temp_v1_2;

    s16 phi_a3;
    s16 phi_t0;
    s16 phi_v0;
    struct065 *phi_s1;
    s16 phi_a0;

    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk162 == 1) {
        if (arg0 > 20) {
            do_rumble(0, 25, 55, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h)); //, temp_a3));
        } else {
            do_rumble(0, 13, 25, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h)); //, temp_a3_2));
        }
    }
    sp8E = D_803D5530->position.xPos.h;
    sp8C = D_803D5530->position.zPos.h;
    func_80374C38_7862E8(sp8E, sp8C, D_803D5530->position.yPos.h);

    temp_t5 = sp8E >> 0xA;
    temp_t7 = sp8C >> 0xA;

    phi_t0 = -1;
    phi_a2 = -1;
    phi_t2 = 1;
    phi_a3 = 1;

    if ((temp_t5 + 1) >= 5) {
        phi_a3 = 0;
    }
    if (temp_t5 <= 0) {
        phi_a2 = 0;
    }
    if ((temp_t7 + 1) >= 8) {
        phi_t2 = 0;
    }
    if (temp_t7 <= 0) {
        phi_t0 = 0;
    }

    for (sp9A = temp_t5 + phi_a2; sp9A <= temp_t5 + phi_a3; sp9A++) {
        for (sp98 = temp_t7 + phi_t0; sp98 <= (temp_t7 + phi_t2); sp98++) {
            for (phi_s1 = D_803DA110[(s16) (sp9A + (sp98 * 5))].next; phi_s1 != NULL; phi_s1 = phi_s1->next) {
                if (phi_s1 == &phi_s1->animal->unk11C[0]) {
                    if (phi_s1->animal != D_803D5530) {

                        animal = phi_s1->animal;
                        if ((animal->unk162 == 6) || (animal->unk162 == 1)) {
                            temp_v0_3 = sp8E - animal->position.xPos.h;
                            temp_v1_2 = sp8C - animal->position.zPos.h;

                            phi_a0 = ABS(temp_v0_3);
                            phi_v0 = ABS(temp_v1_2);

                            temp_a0_2 = MAX(phi_a0, phi_v0) + (MIN(phi_a0, phi_v0) >> 1);
                            if (ABS(D_803D5530->position.yPos.h - animal->position.yPos.h) < 128) {
                                if (temp_a0_2 < arg1) {
                                    if (animal->unk16C->unk82.unk2) {
                                        if ((animal->unk16C->unk9C != EVO_TRANSFER) &&
                                            (animal->unk16C->unk9C != D_803D5524->unk9C) &&
                                            (animal->unk16C->unk9C != RACING_TORTOISE_DEFENDING) &&
                                            (animal->unk16C->unk9C != TORTOISE_TANK_DEFENDING)) {

                                            animal->yVelocity.w += FTOFIX32(10.0);
                                            switch (animal->unk16C->unkE6) {
                                            case 0:
                                                damage = (arg0 * 8) >> 3;
                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);
                                                break;
                                            case 1:
                                                damage = (arg0 * 6) >> 3;
                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);
                                                break;
                                            case 2:
                                                damage = (arg0 * 4) >> 3;
                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);
                                                break;
                                            case 3:
                                                damage = (arg0 * 3) >> 3;
                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);
                                                break;
                                            case 4:
                                                damage = (arg0 * 2) >> 3;
                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);
                                                break;
                                            }
                                            if (D_803D5538 != 0) {
                                                animal->unk2EB++;
                                            }
                                        }
                                    } else {
                                        if ((animal->unk4A == 0) && animal->unk4C.unk1D) {
                                            animal->yVelocity.w += FTOFIX32(10.0);
                                            animal->unk4C.unk19 = 1;
                                        }
                                        if ((animal->unk4A == 0) && (animal->unk4C.unk1A == 0)) {
                                            animal->health = MAX(0, animal->health - 1);
                                        }
                                    }
                                    animal->unk54.unk3 = 21;
                                } else if ((temp_a0_2 < (arg1 * 2)) && (animal->unk4A == 0) && animal->unk4C.unk1D) {
                                    animal->yVelocity.w += FTOFIX32(6.0);
                                    animal->unk4C.unk19 = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    func_8034220C_7538BC(0xF, sp8E, sp8C, D_803D5530->position.yPos.h);
}

// velocity related?
// ESA: func_80076D60
void set_target_speed(s8 speed) {
    D_803D554B = speed;
    D_803D554C = MIN(D_803D554C + 2, 20);
}

// ESA: func_80076D94
void func_8037D9D4_78F084(void) {
    D_803D554C = MIN(D_803D554C + 1, 5);
}

// ESA: func_80076DC4
void func_8037DA08_78F0B8(s16 arg0, s16 arg1, s16 damage) {

    s16 xPos;
    s16 zPos;

    s16 temp_s1_2;
    s16 temp_s2;
    s16 temp_s7;
    s16 temp_v0_4;
    s16 temp_fp;
    s16 var_a0;
    s16 var_a0_2;
    s16 temp_lo;

    s16 spB0;
    s16 var_s5;
    s16 var_v0;
    s16 temp_t1;
    s16 spAA;
    s16 spA8;
    s16 temp_a0;
    s16 temp_v1;
    s16 var_t2;
    s16 spA0;
    s16 var_t3;
    s16 var_t5;

    Animal *animal;
    struct065 *var_s6;

    temp_s7 = SIN(D_803D552C->heading) >> 9;
    temp_fp = COS(D_803D552C->heading) >> 9;

    xPos = D_803D5530->position.xPos.h;
    temp_v1 = xPos >> 10;
    zPos = D_803D5530->position.zPos.h;
    temp_t1 = zPos >> 10;

    var_t5 = -1;
    var_t2 = -1;
    spA0 = 1;
    var_t3 = 1;

    if ((temp_v1 + 1) >= 5) {
        var_t3 = 0;
    }
    if (temp_v1 <= 0) {
        var_t2 = 0;
    }

    if ((temp_t1 + 1) >= 8) {
        spA0 = 0;
    }

    if (temp_t1 <= 0) {
        var_t5 = 0;
    }

    for (spAA = temp_v1 + var_t2; spAA <= (temp_v1 + var_t3); spAA++) {
        spB0 = var_s5; // pointless assignment
        for (spA8 = temp_t1 + var_t5; spA8 <= temp_t1 + spA0; spA8++) {
            for (var_s6 = D_803DA110[(s16) (spAA + (spA8 * 5))].next; var_s6 != NULL; var_s6 = var_s6->next) {
                if ((var_s6 == (&var_s6->animal->unk11C[0])) && (D_803D5530 != var_s6->animal)) {
                    animal = var_s6->animal;

                    temp_s1_2 = xPos - animal->position.xPos.h;
                    temp_s2 = zPos - animal->position.zPos.h;

                    var_a0 = ABS(temp_s1_2);
                    var_v0 = ABS(temp_s2);

                    temp_v0_4 = MAX(var_a0, var_v0) + (MIN(var_a0, var_v0) >> 1);
                    if (temp_v0_4 < arg1 * 2) {
                        if (ABS(D_803D5530->position.yPos.h - animal->position.yPos.h) < arg1 / 2) {
                            var_a0_2 = sqrtf((f32) ((temp_s1_2 * temp_s1_2) + (temp_s2 * temp_s2)));
                            if (var_a0_2 == 0) {
                                var_a0_2 = 1;
                            }
                            temp_lo = -((temp_s1_2 * temp_s7) + (temp_s2 * temp_fp)) / var_a0_2;
                            if (temp_lo > 0) {
                                if (animal->unk16C->unk82.unk2) { // & 0x2000) {
                                    if (animal->unk16C->unk9C != EVO_TRANSFER) {
                                        if (temp_v0_4 < arg1) {
                                            animal->unk54.unk3 = 1;
                                            animal->xVelocity.w += temp_lo * 2 * temp_s7 * arg0;
                                            animal->zVelocity.w += temp_lo * 2 * temp_fp * arg0;
                                            if (temp_lo >= 33) {
                                                switch (animal->unk16C->unkE6) {
                                                case 0:
                                                    var_s5 = 0;
                                                    animal->yVelocity.h += SSSV_RAND(16) - 8;
                                                    break;
                                                case 1:
                                                    var_s5 = 0;
                                                    animal->yVelocity.h += SSSV_RAND(8) - 4;
                                                    break;
                                                case 2:
                                                    var_s5 = 1;
                                                    break;
                                                case 3:
                                                    var_s5 = 3;
                                                    break;
                                                case 4:
                                                    var_s5 = 7;
                                                    break;
                                                }
                                                if (!(D_803D5544 & var_s5)) {
                                                    if ((animal->unk16C->unk9C != RACING_TORTOISE_DEFENDING) &&
                                                        (animal->unk16C->unk9C != TORTOISE_TANK_DEFENDING)) {
                                                        animal->health = MAX(animal->health - damage, 0);
                                                        func_80349280_75A930(animal, damage);
                                                    }
                                                }
                                            }
                                        } else {
                                            animal->xVelocity.w += temp_lo * temp_s7 * arg0;
                                            animal->zVelocity.w += temp_lo * temp_fp * arg0;
                                        }
                                    }
                                } else if ((temp_v0_4 < arg1) && (temp_lo >= 33)) {
                                    animal->unk54.unk3 = 1;
                                    //  << 0x1A
                                    if ((animal->unk4A == 0) && (animal->unk4C.unk1A == 0)) {
                                        animal->health = MAX(0, animal->health - 1);
                                    }
                                    //  & 8
                                    if ((animal->unk4A == 0) && (animal->unk4C.unk1C != 0)) {
                                        if (animal->unk44 < 50) {
                                            animal->xVelocity.w += (temp_lo * temp_s7 * arg0) >> 1;
                                            animal->zVelocity.w += (temp_lo * temp_fp * arg0) >> 1;
                                        } else if (animal->unk44 < 100){
                                            animal->xVelocity.w += (temp_lo * temp_s7 * arg0);
                                            animal->zVelocity.w += (temp_lo * temp_fp * arg0);
                                        }
                                        animal->unk4C.unk19 = 1;
                                    }
                                }
                            }
                        }
                    }
                    // regalloc helper
                    if (1) {};
                }
            }
        }
    }
    D_803D5530->xVelocity.w -= temp_s7 << 0xA;
    D_803D5530->zVelocity.w -= temp_fp << 0xA;

    create_particle_effect(
        D_803D5530->position.xPos.h + temp_s7,
        D_803D5530->position.zPos.h + temp_fp,
        D_803D5530->position.yPos.h + ((D_803D5530->unk42 * 3) >> 2),
        0x23,
        ((SSSV_RAND(32) + temp_s7) - 16) << 0xE,
        ((SSSV_RAND(32) + temp_fp) - 16) << 0xE,
        (SSSV_RAND(32) - 16) << 0xE,
        3,
        0,
        0,
        0);
}

#ifdef NON_MATCHING
// not quite there...
// ESA: func_800775B8
void trigger_contagious_laughter(void) {

    s16 temp_t8;
    s16 i; // spB2
    s16 j; // spB0

    s16 temp_a2;
    s16 temp_t6;
    s16 temp_v0_5;
    s16 var_a0;
    s16 var_t2;
    s16 var_v1;
    s16 var_a2;
    s16 temp_a1;

    s16 var_t0;
    s16 do_laughter;
    s16 var_a3;

    s16 sp9A;
    s16 sp98;

    struct065 *var_s1;
    struct035 *temp_t0;
    s32 animalId;
    Animal *animal;


    if (D_803D5524->unk9C != MYSTERY_BEAR) {
        func_8032CD70_73E420(
            (u8*)D_803D5530 + 0x15,
            SFX_CONTAGIOUS_LAUGHTER,
            0x7000,
            0,
            1.0f,
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h);
    }

    sp9A = D_803D5530->position.xPos.h;
    sp98 = D_803D5530->position.zPos.h;
    temp_t6 = sp9A >> 0xA;
    temp_t8 = sp98 >> 0xA;

    var_t0 = -1;
    var_a2 = -1;
    var_t2 = 1;
    var_a3 = 1;

    if ((temp_t6 + 1) >= 5) {
        var_a3 = 0;
    }
    if (temp_t6 <= 0) {
        var_a2 = 0;
    }
    if ((temp_t8 + 1) >= 8) {
        var_t2 = 0;
    }
    if (temp_t8 <= 0) {
        var_t0 = 0;
    }

    for (i = temp_t6 + var_a2; i <= (temp_t6 + var_a3); i++) {
        for (j = temp_t8 + var_t0; j <= temp_t8 + var_t2; j++) {
            for (var_s1 = D_803DA110[(s16) (i + (j * 5))].next; var_s1 != NULL; var_s1 = var_s1->next) {
                if (var_s1 == (&var_s1->animal->unk11C[0])) {
                    if (D_803D5530 != var_s1->animal) {
                        animal = var_s1->animal;
                        if (ABS(animal->position.yPos.h - D_803D5530->position.yPos.h) < 192) {
                            temp_v0_5 = sp9A - animal->position.xPos.h;
                            temp_a1 = sp98 - animal->position.zPos.h;

                            var_a0 = ABS(temp_v0_5);
                            var_v1 = ABS(temp_a1);

                            temp_a2 = MAX(var_a0, var_v1) + (MIN(var_a0, var_v1) >> 1);
                            if (temp_a2 < 0x200) {
                                if (animal->unk16C->unk82.unk2) {
                                    if ((animal->unk366 != 2) && (animal->unk366 != 5)) {
                                        animalId = animal->unk16C->unk9C;
                                        if ((animalId != EVO_TRANSFER) &&
                                            (animalId != HYENA) &&
                                            (animalId != HYENA_BIKER)) {

                                            do_laughter = 0;
                                            if (D_801D9ED8.animals[gCurrentAnimalIndex].animal == animal) {
                                                if (D_803F63D0 != D_803D5544) {
                                                    do { D_803F63D0 = D_803D5544; } while (0);
                                                    do_laughter = 1;
                                                }
                                            } else {
                                                do_laughter = 1;
                                            }

                                            if ((do_laughter != 0) &&
                                                (animalId != RACING_TORTOISE_DEFENDING) &&
                                                (animalId != TORTOISE_TANK_DEFENDING) &&
                                                (animalId != HYENA) &&
                                                (animalId != HYENA_BIKER)) {

                                                if (animal->laughterThreshold < 100) {
                                                    animal->laughterThreshold++;
                                                    if (temp_a2 < 256) {
                                                        animal->laughterThreshold++;
                                                    }
                                                }

                                                temp_t0 = animal->unk16C;
                                                if (animal->laughterThreshold > 80) {
                                                    animal->isLaughing = 1;
                                                    func_8032CD70_73E420(
                                                        (u8*)animal + 0x17,
                                                        SFX_LAUGHTER,
                                                        ((temp_t0->unkE6 << 0xB) + 0x5000),
                                                        0,
                                                        (1.3 - (temp_t0->unkE6 * 0.2)),
                                                        D_803D5530->position.xPos.h,
                                                        D_803D5530->position.zPos.h,
                                                        D_803D5530->position.yPos.h);

                                                    if (!(D_803D5540 & 3)) {
                                                        animal->health = MAX(animal->health - 1, 0);
                                                        func_80349280_75A930(animal, 1);
                                                    }
                                                }
                                            }
                                            goto dummy_label_101032; dummy_label_101032: ;
                                        }
                                    }
                                }
                                if (animal->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+HYENA) {
                                    animal->unk54.unk3 = 0x16;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/trigger_contagious_laughter.s")
#endif

// only used by MOUSE2
void func_8037E6DC_78FD8C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    s16 tmp;
    s16 temp_a2;    // sp74
    s16 temp_v1_2;
    s16 var_a0;
    s16 var_v0;
    s16 temp_a1;
    s16 temp_v1;
    s16 var_s7;
    s16 var_t0;
    s16 var_t1;
    s16 var_t2;
    s16 var_t5; // sp48?
    s16 var_t3; // sp74?
    s16 pad;
    struct065 *var_a3;
    Animal *animal;

    temp_v1 = arg0 >> 0xA;
    temp_a2 = arg1 >> 0xA;

    var_t0 = -1;
    var_t1 = -1;
    var_s7 = 1;
    var_t2 = 1;

    if ((temp_v1 + 1) >= 5) {
        var_t2 = 0;
    }
    if (temp_v1 <= 0) {
        var_t1 = 0;
    }
    if ((temp_a2 + 1) >= 8) {
        var_s7 = 0;
    }
    if (temp_a2 <= 0) {
        var_t0 = 0;
    }

    for (var_t5 = temp_v1 + var_t1; var_t5 <= (temp_v1 + var_t2); var_t5++) {
        for (var_t3 = temp_a2 + var_t0; var_t3 <= temp_a2 + var_s7; var_t3++) {
            for (var_a3 = D_803DA110[((s16) (var_t5 + (var_t3 * 5)))].next; var_a3 != NULL; var_a3 = var_a3->next) {
                if (var_a3 == &var_a3->animal->unk11C[0]) {
                    if (var_a3->animal != D_803D5530) {
                        animal = var_a3->animal;
                        temp_v1_2 = arg0 - animal->position.xPos.h;
                        temp_a1 = arg1 - animal->position.zPos.h;
                        var_a0 = ABS(temp_v1_2);
                        var_v0 = ABS(temp_a1);
                        tmp = (MAX(var_a0, var_v0) + (MIN(var_a0, var_v0) >> 1));

                        if (ABS(D_803D5530->position.yPos.h - animal->position.yPos.h) < arg3) {
                            if (tmp < arg3) {
                                animal->unk54.unk3 = arg4;
                            }
                        }
                    }
                    if (1) {}; // needed for regalloc
                }
            }
        }
    }
}

// ESA: func_800779AC
Animal *func_8037E9AC_79005C(void) {
    s32 pad2[4];
    s16 sp56;
    s16 sp54;
    s32 pad[2];
    s16 xPosDelta, zPosDelta;
    Animal *ret;
    Animal *a;
    s16 temp_f6;
    s16 temp_lo;
    s16 phi_v0;
    s16 phi_v1;
    s16 phi_s5;
    s16 phi_v1_3;
    s16 i;

    s16 tmp;

    s16 xPos;
    s16 zPos;


    ret = NULL;
    phi_s5 = 0; // best distance?

    xPos = D_803D5530->position.xPos.h;
    zPos = D_803D5530->position.zPos.h;

    sp56 = SIN(D_803D552C->heading) >> 9;
    sp54 = COS(D_803D552C->heading) >> 9;

    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != 0) && (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER)) {
            if ((D_801D9ED8.animals[i].animal->unk366 != 6) && (D_801D9ED8.animals[i].animal->unk366 != 2) && (D_801D9ED8.animals[i].animal->unk366 != 5)) {
                if ((D_803D5530 != D_801D9ED8.animals[i].animal) && (get_ai_behaviour(D_803D5530->unk16C->objectType, D_801D9ED8.animals[i].animal->unk16C->objectType) != AI_LEADER)) {

                    a = D_801D9ED8.animals[i].animal;

                    xPosDelta = xPos - a->position.xPos.h;
                    zPosDelta = zPos - a->position.zPos.h;

                    phi_v0 = ABS(xPosDelta);
                    phi_v1 = ABS(zPosDelta);

                    if ((s16) (MAX(phi_v0, phi_v1) + (MIN(phi_v0, phi_v1) >> 1)) < 0x500) {
                        temp_f6 = sqrtf((xPosDelta * xPosDelta) + (zPosDelta * zPosDelta));
                        tmp = temp_f6;
                        if (temp_f6 == 0) {
                            tmp = 1;
                        }
                        temp_lo = -((xPosDelta * sp56) + (zPosDelta * sp54)) / tmp;
                        if (temp_lo > 32) {
                            phi_v1_3 = ((temp_lo * 3) / 4) + 16;
                        } else {
                            phi_v1_3 = 0;
                        }
                        temp_lo = (s16) (((0x500 - temp_f6) << 6) / 1280) * phi_v1_3;
                        if (phi_s5 < temp_lo) {
                            phi_s5 = temp_lo;
                            ret = a;
                        }
                    }
                }
            }
        }
    }

    return ret;
}

// only used by scorpion
// ESA: func_80077CD8
Animal *func_8037ED1C_7903CC(void) {
    s32 pad[4];
    s16 temp_fp;
    s16 var_a3;
    s32 pad2[2];

    s16 xPosDelta, zPosDelta;

    Animal *ret;
    Animal *animal;

    s16 temp_f6;
    s16 temp_lo;

    s16 var_a0;
    s16 var_s4;
    s16 var_v0;
    s16 var_v1_3;
    s16 var_v1_4;

    s16 i;

    s16 xPos;
    s16 zPos;

    var_s4 = 0;
    ret = NULL;

    xPos = D_803D5530->position.xPos.h;
    zPos = D_803D5530->position.zPos.h;

    temp_fp = SIN(D_803D552C->heading) >> 9;
    var_a3 = COS(D_803D552C->heading) >> 9;

    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != NULL) && (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) && (D_801D9ED8.animals[i].animal->unk366 != 6)) {
            if (D_803D5530 != D_801D9ED8.animals[i].animal) {

                animal = D_801D9ED8.animals[i].animal;
                xPosDelta = xPos - animal->position.xPos.h;
                zPosDelta = zPos - animal->position.zPos.h;

                var_a0 = ABS(xPosDelta);
                var_v0 = ABS(zPosDelta);

                if ((s16) ((MAX(var_a0, var_v0)) + (MIN(var_a0, var_v0) >> 1)) < 320) {
                    if (ABS(D_803D5530->position.yPos.h - animal->position.yPos.h) < 320) {
                        temp_f6 = sqrtf((xPosDelta * xPosDelta) + (zPosDelta * zPosDelta));
                        var_v1_3 = temp_f6;
                        if (temp_f6 == 0) {
                            var_v1_3 = 1;
                        }
                        temp_lo = -((xPosDelta * temp_fp) + (zPosDelta * var_a3)) / var_v1_3;
                        if (temp_lo > 20) {
                            var_v1_4 = temp_lo;
                        } else {
                            var_v1_4 = 0;
                        }

                        temp_lo = (s16) (((0x500 - temp_f6) << 6) / 1280) * var_v1_4;
                        if (var_s4 < temp_lo) {
                            var_s4 = temp_lo;
                            ret = animal;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

// used by fox + camel (warp?)
// ESA: func_80077FD0
s16 func_8037F07C_79072C(s16 arg0, s16 arg1) {
    u8 temp_s1;
    s16 xPos;
    s16 yPosNew;

    s16 sp88;
    s16 sp86;

    s16 xPosNew;
    s32 var_a3; // unused

    s16 zPosNew;
    s16 zPos; // sp7C
    s16 sp7A;

    s16 i;
    s16 sp76; // xVel
    s16 sp74; // zVel
    s16 sp72;

    sp88 = SIN(arg1) >> 7;
    sp86 = COS(arg1) >> 7;

    xPos = D_803D5530->position.xPos.h;
    zPos = D_803D5530->position.zPos.h;
    sp7A = D_803D5530->position.yPos.h;

    for (i = 0x20; i < arg0; i += 0x20) {
        xPosNew = xPos + ((sp88 * i) >> 8);
        zPosNew = zPos + ((sp86 * i) >> 8);

        if (D_803D5530->unk162 != 1) {
            yPosNew = MAX(sp7A, func_8031124C_7228FC(xPosNew, zPosNew) >> 0x10) + 8;
        } else {
            if ((D_803D5530->unk160 == 0) || (D_803D5530->unk160 == 1)) {
                yPosNew = (func_8031124C_7228FC(xPosNew, zPosNew) + 8) >> 0x10;
            } else {
                yPosNew = func_80310F58_722608(xPosNew, zPosNew) >> 0x10;
                if (yPosNew == 0x4000) {
                    yPosNew = (func_8031124C_7228FC(xPosNew, zPosNew) + 8) >> 0x10;
                } else {
                    yPosNew = yPosNew + 8;
                }
            }
        }

        temp_s1 = func_803136FC_724DAC(xPosNew, zPosNew, yPosNew);
        if (!((temp_s1 == 1) && (D_803D5530->unk160 == 2)) && !((temp_s1 == 2) && (D_803D5530->unk160 == 1))) {

            func_80311A2C_7230DC(xPosNew, zPosNew, &sp76, &sp74, temp_s1);

            if (func_8033C9CC_74E07C(xPos, zPos, sp7A + 0x10, D_803D5530->unk160, xPosNew, zPosNew, yPosNew, temp_s1, 0, 0) == 0) {
                if ((ABS(yPosNew - sp7A) < 0x50) && (func_802B75CC_6C8C7C(D_803D5530, 0, xPosNew << 0x10, zPosNew << 0x10, yPosNew << 0x10, &sp72, 1) == 0) && ((ABS(sp76) < 0x18) && (ABS(sp74) < 0x18))) {
                  continue;
                }
            }
        }

        break;
    }

    i = MIN(i - 0x30, arg0);

    if (i > 16) {
        xPosNew = xPos + ((sp88 * i) >> 8);
        zPosNew = zPos + ((sp86 * i) >> 8);

        if (D_803D5530->unk160 == 2) {

            yPosNew = func_80310F58_722608(xPosNew, zPosNew) >> 0x10;
            if (yPosNew == 0x4000) {
                sp7A = MAX(sp7A, func_8031124C_7228FC(xPosNew, zPosNew) >> 0x10) + 0x10;
            } else {
                sp7A = MAX(sp7A, yPosNew) + 0x10;
            }
        } else {
            sp7A = MAX(sp7A, func_8031124C_7228FC(xPosNew, zPosNew) >> 0x10) + 0x10;
        }

        D_803D5530->position.xPos.h = xPosNew;
        D_803D5530->position.zPos.h = zPosNew;
        D_803D5530->position.yPos.h = sp7A;

        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        D_803D5530->yVelocity.w = 0;

        D_803D5530->unk160 = func_803136FC_724DAC(xPosNew, zPosNew, sp7A);
        return i;
    }
    return 0;
}

// used by rat, poisonous gas cloud?
void func_8037F6CC_790D7C(s32 arg0, s16 arg1, s16 damage) {
    s16 pad2;
    s16 temp_a3;
    s16 sp9A;
    s16 sp98;
    s16 pad3;
    s16 temp_a3_2;
    s16 temp_v1;
    s16 sp90;
    s16 var_a0;
    s16 var_t1;
    s16 var_t2;
    s16 temp_a2;
    s16 var_v1;
    s16 temp_v0;
    s16 var_t3;
    s16 var_t4;
    s16 var_t5;

    Animal *animal;
    struct065 *var_s2;
    s32 pad;

    var_t1 = D_803D5530->position.xPos.h;
    temp_v0 = var_t1 >> 0xA;
    var_t2 = D_803D5530->position.zPos.h;
    temp_a3 = var_t2 >> 0xA;

    var_t5 = -1;
    var_t3 = -1;
    sp90 = 1;
    var_t4 = 1;

    if ((temp_v0 + 1) >= 5) {
        var_t4 = 0;
    }
    if (temp_v0 <= 0) {
        var_t3 = 0;
    }
    if ((temp_a3 + 1) >= 8) {
        sp90 = 0;
    }
    if (temp_a3 <= 0) {
        var_t5 = 0;
    }

    for (sp9A = temp_v0 + var_t3; sp9A <= (temp_v0 + var_t4); sp9A++) {
        for (sp98 = temp_a3 + var_t5; sp98 <= (temp_a3 + sp90); sp98++) {

            for (var_s2 = D_803DA110[(s16) (sp9A + (sp98 * 5))].next; var_s2 != NULL; var_s2 = var_s2->next) {
                if (var_s2 == &var_s2->animal->unk11C[0]) {
                    if (var_s2->animal != D_803D5530) {
                        animal = var_s2->animal;

                        if (1) { } if (1) { } // regalloc!

                        temp_a2 = var_t1 - animal->position.xPos.h;
                        temp_a3_2 = var_t2 - animal->position.zPos.h;

                        var_a0 = ABS(temp_a2);
                        var_v1 = ABS(temp_a3_2);

                        temp_v1 = MAX(var_a0, var_v1) + (MIN(var_a0, var_v1) >> 1);
                        if (animal->unk16C->unk82.unk2) {
                            if ((animal->unk16C->unk9C != EVO_TRANSFER) && (animal->unk16C->unk9C != KING_RAT) && (animal->unk16C->unk9C != RAT)) {
                                if (temp_v1 < arg1 * 2) {
                                    if (ABS(D_803D5530->position.yPos.h - animal->position.yPos.h) < arg1) {
                                        if (temp_v1 < arg1) {
                                            animal->xVelocity.w -= (temp_a2 << 0x10) / temp_v1;
                                            animal->zVelocity.w -= (temp_a3_2 << 0x10) / temp_v1;
                                            if ((D_803D5544 & 3) == 0) {

                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);

                                                animal->unk348 = MAX(100, animal->unk348);
                                                animal->unk34A = MAX(40, animal->unk34A);
                                            }
                                        } else {
                                            animal->xVelocity.w -= (temp_a2 << 0xF) / temp_v1;
                                            animal->zVelocity.w -= (temp_a3_2 << 0xF) / temp_v1;
                                        }
                                    }
                                }
                            }
                        }
                        if (temp_v1 < arg1 * 2) {
                            if (ABS(D_803D5530->position.yPos.h - animal->position.yPos.h) < arg1) {
                                animal->unk54.unk3 = 6;
                            }
                        }
                    }
                }
            }
        }
    }
}

// missile model (on animal) disappearing and left-right missile selector function
// ESA: func_80078478
u8 get_missile_side(void) {
    switch (D_803D5524->unk9C) {
    case RACING_DOG:
    case SKI_HUSKY:
    case WALRUS:
    case HYENA_BIKER:
        if ((D_803D552C->missileScaleLeft == 8) && (D_803D552C->missileScaleRight == 8)) {
            if (D_803D552C->missileSide != 0) {
                D_803D552C->missileSide = 0; // *next* missile should come from right side
                D_803D552C->missileScaleLeft = 0;
            } else {
                D_803D552C->missileSide = 1; // *next* missile should come from left side
                D_803D552C->missileScaleRight = 0;
            }
        } else if (D_803D552C->missileScaleRight < D_803D552C->missileScaleLeft) {
            D_803D552C->missileSide = 0;
            D_803D552C->missileScaleLeft = 0;
        } else {
            D_803D552C->missileSide = 1;
            D_803D552C->missileScaleRight = 0;
        }
        break;
    case FIRE_FOX:
        D_803D552C->missileScaleLeft = 0;
    }

    return D_803D552C->missileSide;
}

void func_8037FCA8_791358(void) {
    s32 phi_a0;
    s16 tmp;

    if (D_803D552C->missileScaleLeft != 0) {
        D_803D552C->missileScaleLeft = MIN(D_803D552C->missileScaleLeft + 1, 8);
    }
    if (D_803D552C->missileScaleRight != 0) {
        D_803D552C->missileScaleRight = MIN(D_803D552C->missileScaleRight + 1, 8);
    }
    if (D_803D5524->unk9C == POLAR_TANK) {
        phi_a0 = 0;
    } else {
        phi_a0 = 1;
    }
    tmp = ((D_803D552C->energy[phi_a0].unk0 + (D_803D5524->unkDA[phi_a0][1] * 8)) / D_803D5524->unkDA[phi_a0][0]);
    if (tmp == 1) {
        if ((D_803D552C->missileScaleLeft == 0) && (D_803D552C->missileScaleRight == 0)) {
            if (D_803D552C->missileSide == 0) {
                D_803D552C->missileScaleRight = 1;
            } else {
                D_803D552C->missileScaleLeft = 1;
            }
        }
    } else if (tmp >= 2) {
        if (D_803D552C->missileScaleLeft == 0) {
            D_803D552C->missileScaleLeft += 1;
        }
        if (D_803D552C->missileScaleRight == 0) {
            D_803D552C->missileScaleRight += 1;
        }
    }
}

void func_8037FE24_7914D4(void) {
    s16 tmp;

    if (D_803D552C->missileScaleLeft != 0) {
        D_803D552C->missileScaleLeft = MIN(D_803D552C->missileScaleLeft + 1, 8);
    }
    tmp = ((D_803D552C->energy[1].unk0 + (D_803D5524->unkDA[1][1] * 8)) / D_803D5524->unkDA[1][0]);
    if ((tmp > 0) && (D_803D552C->missileScaleLeft == 0)) {
        D_803D552C->missileScaleLeft = 1;
    }
}

// used by sheep
// ESA: func_80078550
void sheep_follow_leader(void) {
    s16 i;
    s16 zPosDelta;
    s16 xPosDelta;

    play_sound_effect_at_location(SFX_SHEEP_BAA, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);

    // iterate over all animals in the level
    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != NULL) &&
            (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) &&
            (D_801D9ED8.animals[i].animal->unk366 != 6) &&
            (D_801D9ED8.animals[i].animal != D_803D5530) &&
            ((u8)D_801D9ED8.animals[i].animal->unk2A0 == 0) &&
            ((D_801D9ED8.animals[i].unk0->unk9C == SHEEP) || (D_801D9ED8.animals[i].unk0->unk9C == SPRINGY_THINGY))) {
            xPosDelta = ABS(D_801D9ED8.animals[i].animal->position.xPos.h - D_803D5530->position.xPos.h);
            if (xPosDelta < 200) {
                zPosDelta = ABS(D_801D9ED8.animals[i].animal->position.zPos.h - D_803D5530->position.zPos.h);
                if (zPosDelta < 200) {
                    if ((D_801D9ED8.animals[i].animal->unk287 == 0) && (D_803D552C->unk28A == 0)) {
                        D_801D9ED8.animals[i].animal->unk287 = 1;
                        if (D_803D5530) {};
                        D_801D9ED8.animals[i].animal->unk288 = (xPosDelta + zPosDelta) >> 3;
                        // swarm? follow?
                        func_80363E88_775538(D_801D9ED8.animals[i].animal, D_803D5530);
                    }
                }
            }
        }
    }
    func_8037E6DC_78FD8C(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 200, 15);
}
