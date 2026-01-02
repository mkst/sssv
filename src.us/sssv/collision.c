#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

extern u16 D_803A0510_7B1BC0[];


// ========================================================
// .bss
// ========================================================

u8  (*D_803D60D0)(Animal *arg0, Animal *arg1, Position**, Position**, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2);
u8   D_803D60D4;

Position *D_803D60D8;
Position *D_803D60DC;

u8  D_803D60E0;
u16 D_803D60E2;


// ========================================================
// .text
// ========================================================

#if 0
// CURRENT (14669)
// ESA: func_80070A6C
void func_802B4D20_6C63D0(void) {
    s16 i; // sp136
    CollisionNode *sp130;
    CollisionNode *sp12C;

    Pos sp11C;
    Pos sp118;
    Pos sp114;

    Pos sp110;
    Pos sp10C;
    Pos sp108;

    s32 pad[4];

    Vertex spF8;
    Vertex spEC;
    Vertex spE0;
    Vertex spD4;

    Animal *animal1;
    Animal *animal2;
    f32 var_f2;
    s16 mode;
    s32 temp_a0_6;
    s32 totalMass;
    s32 temp_v1_6;
    s32 var_s5;
    u16 var_s3;
    u16 var_s4;
    s32 res1, res2;

    for (i = 0; i < 40; i++) {
        for (sp130 = D_803DA110[i].next; sp130 != NULL; sp130 = sp130->next) {
            for (sp12C = sp130->next; sp12C != NULL; sp12C = sp12C->next) {

                if ((((sp130->animal->unk114[0] == i) && (sp12C->animal->unk114[0] == i)) ||
                     ((sp130->animal->unk114[0] == i) && (sp12C->animal->unk114[0] < i)) ||
                     ((sp12C->animal->unk114[0] == i) && (sp130->animal->unk114[0] < i)))) {

                    animal1 = sp130->animal;
                    animal2 = sp12C->animal;

                    if ((D_803B1BAC_7C325C[sp130->animal->unk16C->unk2] & (1 << (0xF - sp12C->animal->unk16C->unk2))) != 0) {

                        if ((ABS(animal1->newPosition.xPos.h - animal2->newPosition.xPos.h) < (animal1->unk34 + animal2->unk34)) &&
                            (ABS(animal1->newPosition.zPos.h - animal2->newPosition.zPos.h) < (animal1->unk34 + animal2->unk34)) &&
                            (ABS(((animal1->newPosition.yPos.h + (animal1->unk42 >> 1)) - animal2->newPosition.yPos.h) - (animal2->unk42 >> 1)) < (animal1->unk36 + animal2->unk36))) {

                            if (((animal1->unk68 != animal2) || (((D_803A0510_7B1BC0[(animal1->unk16C->unk2)]) & (1 << (0xF - animal2->unk16C->unk2))) == 0)) &&
                                ((animal2->unk68 != animal1) || (((D_803A0510_7B1BC0[(animal2->unk16C->unk2)]) & (1 << (0xF - animal1->unk16C->unk2))) == 0)) &&
                                ((animal1->unk70 != animal2) || (animal2->unk16C->unk15 != 4) || (animal1->unk16C->unk2 != 5)) &&
                                ((animal2->unk70 != animal1) || (animal1->unk16C->unk15 != 4) || (animal2->unk16C->unk2 != 5))) {

                                if ((animal1->state != 0x1E) && (animal2->state != 0x1E) &&
                                    (animal1->state != 0x1F) && (animal2->state != 0x1F) &&
                                    ((animal1->unk15C == 0) || (animal2 != animal1->owner)) &&
                                    ((animal2->unk15C == 0) || (animal1 != animal2->owner))) {


                                    mode = func_802B5E48_6C74F8(animal1, animal2, &D_803D60D0, &D_803D60D4);

                                    res1 = ((D_803D60D4 != 0) && (D_803D60D0(animal2, animal1, &D_803D60D8, &D_803D60DC, animal2->newPosition.xPos, animal2->newPosition.zPos, animal2->newPosition.yPos, animal1->newPosition.xPos, animal1->newPosition.zPos, animal1->newPosition.yPos)));
                                    res2 = ((D_803D60D4 == 0) && (D_803D60D0(animal1, animal2, &D_803D60D8, &D_803D60DC, animal1->newPosition.xPos, animal1->newPosition.zPos, animal1->newPosition.yPos, animal2->newPosition.xPos, animal2->newPosition.zPos, animal2->newPosition.yPos)));

                                    if (res1 || res2) {

                                        animal1->unk4C.unk19 = 1;
                                        animal2->unk4C.unk19 = 1;

                                        if ((animal1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (animal2->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                            func_8038F5F8_7A0CA8(animal2);
                                        }
                                        if ((animal2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (animal1->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                            func_8038F5F8_7A0CA8(animal1);
                                        }

                                        func_802FD674_70ED24(animal2, animal1);

                                        // store original velocities...
                                        sp11C = animal1->xVelocity;
                                        sp114 = animal1->zVelocity;
                                        sp10C = animal1->yVelocity;

                                        sp118 = animal2->xVelocity;
                                        sp110 = animal2->zVelocity;
                                        sp108 = animal2->yVelocity;

                                        if ((animal1->unk16C->unk2 == 9) || (animal2->unk16C->unk2 == 9) ||
                                            (animal1->unk16C->unk2 == 8) || (animal2->unk16C->unk2 == 8)) {
                                            func_802CAB20_6DC1D0(animal1, animal2, sp11C.h, sp114.h, sp10C.h, sp118.h, sp110.h, sp108.h);
                                        } else {
                                            var_f2 = 1.0f;
                                            spF8.x = animal1->position.xPos.w / 65536.0;
                                            spF8.y = animal1->position.zPos.w / 65536.0;
                                            spF8.z = (animal1->position.yPos.w / 65536.0) + (animal1->unk42 >> 1);

                                            spEC.x = animal1->xVelocity.w / 65536.0;
                                            spEC.y = animal1->zVelocity.w / 65536.0;
                                            spEC.z = animal1->yVelocity.w / 65536.0;

                                            spE0.x = animal2->position.xPos.w / 65536.0;
                                            spE0.y = animal2->position.zPos.w / 65536.0;
                                            spE0.z = (animal2->position.yPos.w / 65536.0) + (animal2->unk42 >> 1);

                                            spD4.x = animal2->xVelocity.w / 65536.0;
                                            spD4.y = animal2->zVelocity.w / 65536.0;
                                            spD4.z = animal2->yVelocity.w / 65536.0;

                                            if ((((mode == 5) || (mode == 4)) && (D_803D60E0 == 1) && (((animal1->unk16C->unk82.unk2 != 0)) || (animal2->unk16C->unk82.unk2 != 0))) ||
                                                (((mode == 1) || (mode == 2)) && (D_803D60DC->yPos.w == 0) &&
                                                  (((animal1->unk16C->unk82.unk2 != 0) && (((animal2->position.yPos.h < (animal1->position.yPos.h + (animal1->unk42 >> 1))))) && ((animal1->position.yPos.h + (animal1->unk42 >> 1)) < (animal2->position.yPos.h + animal2->unk42))) ||
                                                   ((animal2->unk16C->unk82.unk2 != 0) && (((animal1->position.yPos.h < (animal2->position.yPos.h + (animal2->unk42 >> 1))))) && ((animal2->position.yPos.h + (animal2->unk42 >> 1)) < (animal1->position.yPos.h + animal1->unk42)))))) {
                                                var_f2 = 0.125f;
                                                var_s5 = 1;
                                            } else {
                                                var_s5 = 0;
                                            }

                                            if (((animal1->unk16C->unk82.unk2 != 0) && ((Position*)animal1->unkC4 == D_803D60D8) && (((animal1->unk162 == 1)) || (animal1->unk162 == 6)) && ((animal2->unk162 == 1) || (animal2->unk162 == 6)) && (animal2->unk4C.unk1B) && (animal2->unk16C->unk82.unk2 == 0)) ||
                                                ((animal2->unk16C->unk82.unk2 != 0) && ((Position*)animal2->unkC4 == D_803D60D8) && (((animal1->unk162 == 1)) || (animal1->unk162 == 6)) && ((animal2->unk162 == 1) || (animal2->unk162 == 6)) && (animal1->unk4C.unk1B) && (animal1->unk16C->unk82.unk2 == 0))) {

                                                var_s3 = animal1->unk44;
                                                var_s4 = animal2->unk44;

                                                if (animal1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
                                                    var_s3 = 0;
                                                } else if (animal2->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
                                                    var_s4 = 0;
                                                }

                                                if ((animal1->unk16C->unk82.unk2 != 0) && (animal2->unk16C->unk82.unk2 != 0)) { // & 0x2000
                                                    if ((animal1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (animal1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
                                                        var_s3 *= 3;
                                                        play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, animal1->position.xPos.h, animal1->position.zPos.h, animal1->position.yPos.h, 1.0f);
                                                    }
                                                    if ((animal2->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (animal2->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
                                                        var_s4 *= 3;
                                                        play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, animal2->position.xPos.h, animal2->position.zPos.h, animal2->position.yPos.h, 1.0f);
                                                    }
                                                } else if ((var_s4 * 3) < var_s3) {
                                                    var_s4 = 0;
                                                } else if ((var_s3 * 3) < var_s4) {
                                                    var_s3 = 0;
                                                }

                                                totalMass = var_s3 + var_s4;
                                                if (!(totalMass != 0)) {
                                                    osSyncPrintf("\nASSERT: TotalMass != 0, %s, %u\n", "../src/collsion.c", 326);
                                                    *(volatile int*)0 = 0;
                                                }

                                                animal1->xVelocity.w = animal2->xVelocity.w = ((var_s3 * animal1->xVelocity.w) + (var_s4 * animal2->xVelocity.w)) / totalMass;
                                                animal1->zVelocity.w = animal2->zVelocity.w = ((var_s3 * animal1->zVelocity.w) + (var_s4 * animal2->zVelocity.w)) / totalMass;

                                                if (var_s5 == 0) {
                                                    temp_v1_6 = animal1->yVelocity.w;
                                                    temp_a0_6 = animal2->yVelocity.w;
                                                    if ((animal1->unk4C.unk1B != 0) && (!animal1->unk16C->unk82.unk1)) { // unk4C << 0x1B) >> 0x1F .. unk80 << 0x11) >> 0x1F
                                                        animal1->yVelocity.w = ((var_s3 * temp_v1_6) + (var_s4 * temp_a0_6)) / totalMass;
                                                    }
                                                    if ((animal2->unk4C.unk1B != 0) && (!animal2->unk16C->unk82.unk1)) { // unk4C << 0x1B) >> 0x1F .. unk80 << 0x11) >> 0x1F
                                                        animal2->yVelocity.w = ((var_s3 * temp_v1_6) + (var_s4 * temp_a0_6)) / totalMass;
                                                    }
                                                }
                                            } else if (1) { // permuter suggestion
                                                if (var_s5 != 0) {
                                                    spEC.z = 0.0f;
                                                    spD4.z = 0.0f;
                                                    spF8.z = 0.0f;
                                                    spE0.z = 0.0f;
                                                }
                                                func_80319280_72A930(animal1, &spF8, &spEC,
                                                                     animal2, &spE0, &spD4, var_f2 * 0.6, var_f2 * 0.8);

                                                if ((animal1->unk4C.unk1B) && (!animal1->unk16C->unk82.unk1)) { // unk4C & 0x10 ... unk80 & 0x4000
                                                    animal1->xVelocity.w = spEC.x * 65536.0f;
                                                    animal1->zVelocity.w = spEC.y * 65536.0f;
                                                    if (var_s5 == 0) {
                                                        animal1->yVelocity.w = spEC.z * 65536.0f;
                                                    }
                                                    if (animal1->unk16C->unk2 == 5) {
                                                        func_802B8304_6C99B4(animal1, animal2);
                                                    }
                                                }
                                                if ((animal2->unk4C.unk1B) && (!animal2->unk16C->unk82.unk1)) { // unk4C & 0x10 ... unk80 & 0x4000
                                                    animal2->xVelocity.w = spD4.x * 65536.0f;
                                                    animal2->zVelocity.w = spD4.y * 65536.0f;
                                                    if (var_s5 == 0) {
                                                        animal2->yVelocity.w = spD4.z * 65536.0f;
                                                    }
                                                    if (animal2->unk16C->unk2 == 5) {
                                                        func_802B8304_6C99B4(animal2, animal1);
                                                    }
                                                }
                                            }

                                            if ((animal1->unk16C->unk82.unk2 != 0) && ((Position*)animal1->unkC4 == D_803D60D8) && ((animal2->unk16C->unk82.unk1) || ((animal2->unk16C->collision != NULL) && (animal2->unk40 > 0x1000))) && ((animal1->unk16C->unk9C == HYENA) || (animal1->unk16C->unk9C == HYENA_BIKER) || (animal1->unk16C->unk9C == DOG) || (animal1->unk16C->unk9C == RACING_DOG)) && (animal1->unk3C0.unk0 != 0x10)) {
                                                animal1->unk3C0.unk0 = 0x10;
                                                animal1->unk3C0.unk2 = 0;
                                            }
                                            if ((animal2->unk16C->unk82.unk2 != 0) && ((Position*)animal2->unkC4 == D_803D60DC) && (animal1->unk16C->unk82.unk1) && (((animal2->unk16C->unk9C == HYENA)) || (animal2->unk16C->unk9C == HYENA_BIKER) || (animal2->unk16C->unk9C == DOG) || (animal2->unk16C->unk9C == RACING_DOG)) && (animal2->unk3C0.unk0 != 0x10)) {
                                                animal2->unk3C0.unk0 = 0x10;
                                                animal2->unk3C0.unk2 = 0;
                                            }

                                            animal1->unk48 = animal2->unk48 = D_803D5544;
                                            // animal1->unk48 = D_803D5544;

                                            if (animal1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
                                                if ((D_803D5544 - D_803D60E2) >= 5) {
                                                    D_803D5546 = MAX(2, D_803D5546);
                                                    D_803D60E2 = D_803D5544;
                                                }
                                            } else if (animal2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
                                                if ((D_803D5544 - D_803D60E2) >= 5) {
                                                    D_803D5546 = MAX(2, D_803D5546);
                                                    D_803D60E2 = D_803D5544;
                                                }
                                            }
                                            func_802CAB20_6DC1D0(animal1, animal2, sp11C.h, sp114.h, sp10C.h, sp118.h, sp110.h, sp108.h);

                                            animal1->newPosition.xPos.w = animal1->position.xPos.w + animal1->xVelocity.w;
                                            animal1->newPosition.zPos.w = animal1->position.zPos.w + animal1->zVelocity.w;
                                            animal1->newPosition.yPos.w = animal1->position.yPos.w + animal1->yVelocity.w;

                                            animal2->newPosition.xPos.w = animal2->position.xPos.w + animal2->xVelocity.w;
                                            animal2->newPosition.zPos.w = animal2->position.zPos.w + animal2->zVelocity.w;
                                            animal2->newPosition.yPos.w = animal2->position.yPos.w + animal2->yVelocity.w;

                                            if (((D_803D60D4 != 0) && (D_803D60D0(animal2, animal1, &D_803D60D8, &D_803D60DC, animal2->newPosition.xPos, animal2->newPosition.zPos, animal2->newPosition.yPos, animal1->newPosition.xPos, animal1->newPosition.zPos, animal1->newPosition.yPos) != 0)) ||
                                                ((D_803D60D4 == 0) && (D_803D60D0(animal1, animal2, &D_803D60D8, &D_803D60DC, animal1->newPosition.xPos, animal1->newPosition.zPos, animal1->newPosition.yPos, animal2->newPosition.xPos, animal2->newPosition.zPos, animal2->newPosition.yPos) != 0))) {
                                                func_802B7BC8_6C9278(animal1, animal2);
                                            }
                                        }
                                    }
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
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B4D20_6C63D0.s")
#endif

// ESA: func_80071AC0
s32 func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, u8 (**collision_func)(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2), u8 *arg3) {
    struct035 *a0; // arg0
    struct035 *a1; // arg1
    s32 res = 0;

    *collision_func = NULL;
    a0 = arg0->unk16C;
    if (a0->unk15 == 4) {
        a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            // simple collision?
            res = 6;
            *collision_func = func_802B750C_6C8BBC;
            *arg3 = 0;
        } else if (a1->collision != NULL) {
            // custom collision data
            if (arg1->unkC4[0].unkC != 0) {
                res = 7;
                *collision_func = func_802B6F6C_6C861C;
                *arg3 = 0;
            } else {
                res = 7;
                *collision_func = func_802B6F6C_6C861C;
                *arg3 = 0;
            }
        } else {
            if (arg1->unkC4[0].unkC != 0) {
                res = 5;
                *collision_func = func_802B6B5C_6C820C;
                *arg3 = 1;
            }
        }
    } else if (a0->collision != NULL) {
        a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            // custom collision data
            if (arg1->unkC4[0].unkC != 0) {
                res = 7;
                *collision_func = func_802B6F6C_6C861C;
                *arg3 = 1;
            } else {
                res = 8;
                *collision_func = func_802B6F6C_6C861C;
                *arg3 = 1;
            }
        } else if (a1->collision != NULL) {
            if ((arg0->unkC4[0].unkC != 0) && (arg1->unkC4[0].unkC != 0)) {
                res = 1;
                *collision_func = func_802B6088_6C7738;
                if ((u32) arg0 < (u32) arg1) { // memory address lower!
                    *arg3 = 0;
                } else {
                    *arg3 = 1;
                }
            } else if (arg0->unkC4[0].unkC != 0) {
                res = 1;
                *collision_func = func_802B6088_6C7738;
                *arg3 = 0;
            } else {
                res = 9;
                *collision_func = func_802B75B4_6C8C64;
                *arg3 = 0;
            }
        } else {
            if (arg1->unkC4[0].unkC != 0) {
                res = 2;
                *collision_func = func_802B6088_6C7738;
                *arg3 = 1;
            } else {
                res = 0;
            }
        }
    } else {
        if (arg0->unkC4[0].unkC != 0) {
            a1 = arg1->unk16C;
            if (a1->unk15 == 4) {
                res = 4;
                *collision_func = func_802B6B5C_6C820C;
                *arg3 = 0;
            } else if (a1->collision != NULL) {
                res = 1;
                *collision_func = func_802B6088_6C7738;
                *arg3 = 0;
            } else  if (arg1->unkC4[0].unkC != 0) {
                res = 3;
                *collision_func = func_802B6948_6C7FF8;
                *arg3 = 0;
            } else {
                res = 0;
            }
        } else {
            res = 0;
        }
    }

    // default collision func?
    if (res == 0) {
        *collision_func = func_802B6948_6C7FF8;
        *arg3 = 0;
    }
    return res;
}

// ESA: func_80071CBC
u8 func_802B6088_6C7738(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2) {

    static Position D_803D60E8;

    s16 temp_a0_2;
    s16 temp_a3;
    s16 temp_t9;
    s16 temp_v0;

    s16 var_a1;
    s16 var_a2;
    s16 var_t1;
    s16 var_t3;
    s16 var_t6;

    s32 temp_a0;
    s32 temp_t5;
    Collision *collision;

    s32 i = 0;
    u8 changed = 0;

    *p1 = *p2 = NULL;

    collision = arg1->unk16C->collision;

    D_803D60E8.xPos.w = 0;
    D_803D60E8.zPos.w = 0;
    D_803D60E8.yPos.w = 0;

    for (;((changed == 0) && (arg0->unkC4[i].unkC != 0) && (i < 5));) {

        temp_a0 = (arg1->unk40 << 6) >> 0xB;
        temp_t5 = ((arg0->unkC4[i].pos.yPos.w + yPos1.w) - yPos2.w) - (arg1->unk42 << 0xF);

        var_a2 = ((((arg0->unkC4[i].pos.xPos.w + xPos1.w) - xPos2.w) >> 0xB) / (temp_a0)) + 16;
        var_a1 = ((((arg0->unkC4[i].pos.zPos.w + zPos1.w) - zPos2.w) >> 0xB) / (temp_a0)) + 16;
        temp_a3 = ((temp_t5 >> 0xB) / temp_a0) + 16;

        var_t1 = MAX(1, (arg0->unkC4[i].unkC << 5) / (temp_a0));
        var_t3 = MAX(1, (var_t1 * 3) >> 2);

        if ((arg1->unk28 == 0) && (arg1->unk2A == 0)) {
            switch (arg1->yRotation) {

            case 90:
                var_t6 = var_a2;
                var_a2 = 32 - var_a1;
                var_a1 = var_t6;
                break;
            case 180:
                var_t6 = 32 - var_a1;
                var_a2 = 32 - var_a2;
                var_a1 = var_t6;
                break;
            case 270:
                var_t6 = var_a2;
                var_a2 = var_a1;
                var_a1 = 32 - var_t6;
                break;
            }
        }

        if ((var_a2 >= 0) && (var_a2 < 32) && (var_a1 >= 0) && (var_a1 < 32)) {
            temp_v0 = temp_a3 + var_t1;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_a2 + (var_a1 * 32)] & (1 << temp_v0))) {
                D_803D60E8.yPos.h += 2;
                changed = 1;
                *p1 = &arg0->unkC4[i];
            }
            temp_v0 = temp_a3 - var_t1;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_a2 + (var_a1 * 32)] & (1 << temp_v0))) {
                D_803D60E8.yPos.h -= 2;
                changed = 1;
                *p1 = &arg0->unkC4[i];
            }
        }

        if ((temp_a3 >= 0) && (temp_a3 < 32)) {
            if ((var_a2 >= 0) && (var_a2 < 32)) {
                temp_v0 = var_a1 + var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_a2 + (temp_v0 * 32)] & (1 << temp_a3))) {
                    D_803D60E8.zPos.h += 2;
                    changed = 1;
                    *p1 = &arg0->unkC4[i];
                }
                temp_v0 = var_a1 - var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_a2 + (temp_v0 * 32)] & (1 << temp_a3))) {
                    D_803D60E8.zPos.h -= 2;
                    changed = 1;
                    *p1 = &arg0->unkC4[i];
                }
            }
            if ((var_a1 >= 0) && (var_a1 < 32)) {
                temp_v0 = var_a2 + var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_v0 + (var_a1 * 32)] & (1 << temp_a3))) {
                    D_803D60E8.xPos.h += 2;
                    changed = 1;
                    *p1 = &arg0->unkC4[i];
                }
                temp_v0 = var_a2 - var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_v0 + (var_a1 * 32)] & (1 << temp_a3))) {
                    D_803D60E8.xPos.h -= 2;
                    changed = 1;
                    *p1 = &arg0->unkC4[i];
                }
            }
            if (changed == 0) {
                temp_a0_2 = var_a2 + var_t3;
                if ((temp_a0_2 >= 0) && (temp_a0_2 < 32)) {
                    temp_v0 = var_a1 + var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_a0_2 + (temp_v0 * 32)] & (1 << temp_a3))) {
                        D_803D60E8.xPos.h += 2;
                        D_803D60E8.zPos.h += 2;
                        *p1 = &arg0->unkC4[i];
                        changed = 1;
                    }
                    temp_v0 = var_a1 - var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_a0_2 + (temp_v0 * 32)] & (1 << temp_a3))) {
                        D_803D60E8.xPos.h += 2;
                        D_803D60E8.zPos.h -= 2;
                        *p1 = &arg0->unkC4[i];
                        changed = 1;
                    }
                }

                temp_a0_2 = var_a2 - var_t3;
                if ((temp_a0_2 >= 0) && (temp_a0_2 < 32)) {
                    temp_v0 = var_a1 + var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_a0_2 + (temp_v0 * 32)] & (1 << temp_a3))) {
                        D_803D60E8.xPos.h -= 2;
                        D_803D60E8.zPos.h += 2;
                        *p1 = &arg0->unkC4[i];
                        changed = 1;
                    }
                    temp_v0 = var_a1 - var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_a0_2 + (temp_v0 * 32)] & (1 << temp_a3))) {
                        D_803D60E8.xPos.h -= 2;
                        D_803D60E8.zPos.h -= 2;
                        *p1 = &arg0->unkC4[i];
                        changed = 1;
                    }
                }
            }
        }

        i++;
    }

    if (changed != 0) {
        switch (arg1->yRotation) {
        case 90:
            // x becomes z, z becomes -x
            temp_t9 = D_803D60E8.xPos.h;
            D_803D60E8.xPos.h = D_803D60E8.zPos.h;
            D_803D60E8.zPos.h = -temp_t9;
            break;
        case 180:
            // x becomes -x, z becomes -z
            D_803D60E8.xPos.h = -D_803D60E8.xPos.h;
            D_803D60E8.zPos.h = -D_803D60E8.zPos.h;
            break;
        case 270:
            // x becomes -z, z becomes x
            temp_t9 = D_803D60E8.xPos.h;
            D_803D60E8.xPos.h = -D_803D60E8.zPos.h;
            D_803D60E8.zPos.h = temp_t9;
            break;
        }

        // randomise collision?
        if ((D_803D60E8.xPos.h == 0) && (D_803D60E8.zPos.h == 0) && (D_803D60E8.yPos.h == 0)) {
            D_803D60E8.xPos.w = (SSSV_RAND(256) - 128) << 0xA;
            D_803D60E8.zPos.w = (SSSV_RAND(256) - 128) << 0xA;
        }
        *p2 = &D_803D60E8;
    }
    return changed;
}

// ESA: func_800724D4
u8 func_802B6948_6C7FF8(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2) {
    s16 i;
    s16 j;

    s16 temp_a3;
    s16 temp_t0;
    s16 temp_t1;
    u32 temp_v0;

    u8 res;

    i = 0;
    res = 0;

    for (; ((res == 0) && (arg0->unkC4[i].unkC != 0) && (i < 5)); i++) {
        for (j = 0; ((res == 0) && (arg1->unkC4[j].unkC != 0) && (j < 5)); j++) {

            temp_a3 = ((arg1->unkC4[j].pos.xPos.w + xPos2.w) - (arg0->unkC4[i].pos.xPos.w + xPos1.w)) / 0x10000;
            temp_t0 = ((arg1->unkC4[j].pos.zPos.w + zPos2.w) - (arg0->unkC4[i].pos.zPos.w + zPos1.w)) / 0x10000;
            temp_t1 = ((arg1->unkC4[j].pos.yPos.w + yPos2.w) - (arg0->unkC4[i].pos.yPos.w + yPos1.w)) / 0x10000;

            temp_v0 = arg0->unkC4[i].unkC + arg1->unkC4[j].unkC; // dupe line is required for match
            temp_v0 = arg0->unkC4[i].unkC + arg1->unkC4[j].unkC;
            temp_v0 = SQ(temp_v0);
            res = ((SQ(temp_a3) + SQ(temp_t0)) + SQ(temp_t1)) < temp_v0;

            if (res != 0) {
                *p1 = &arg0->unkC4[i];
                *p2 = &arg1->unkC4[j];
            }
        }

    }
    return res;
}

#ifdef NON_MATCHING
// CURRENT (75)
// ESA: func_800726C8
u8 func_802B6B5C_6C820C(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2) {

    s32 temp_a0;
    s32 temp_a1;

    s32 i;

    u8 changed;
    u8 flags;

    s16 new_var;

    *p1 = NULL;

    D_803D60E0 = 0;

    for (changed = 0, i = 0; (changed == 0) && (i < 5) && (arg0->unkC4[i].unkC != 0); i++) {

        temp_a0 = arg1->unk30 + arg0->unkC4[i].unkC;
        temp_a1 = arg1->unk32 + arg0->unkC4[i].unkC;

        if (changed = (
            ((xPos1.h + arg0->unkC4[i].pos.xPos.h) > (xPos2.h - temp_a0)) &&
            ((xPos1.h + arg0->unkC4[i].pos.xPos.h) < (xPos2.h + temp_a0)) &&
            ((zPos1.h + arg0->unkC4[i].pos.zPos.h) > (zPos2.h - temp_a1)) &&
            ((zPos1.h + arg0->unkC4[i].pos.zPos.h) < (zPos2.h + temp_a1)) &&
            ((yPos1.h + arg0->unkC4[i].pos.yPos.h) > (yPos2.h - arg0->unkC4[i].unkC)) &&
            ((yPos1.h + arg0->unkC4[i].pos.yPos.h) < (yPos2.h + arg0->unkC4[i].unkC + arg1->unk42)))) {
            *p1 = &arg0->unkC4[i];

            flags = 0;
            if ((xPos1.h + arg0->unkC4[i].pos.xPos.h) < (xPos2.h - arg1->unk30)) {
                flags = (0x4 | 0x8);
            } else if ((xPos1.h + arg0->unkC4[i].pos.xPos.h) > (xPos2.h + arg1->unk30)) {
                flags = 0x8;
            }
            new_var = arg0->unkC4[i].pos.zPos.h; // this aint the solution..

            if ((new_var + zPos1.h) < (zPos2.h - arg1->unk32)) {
                flags |= (0x1 | 0x2);
            } else if ((new_var + zPos1.h) > (zPos2.h + arg1->unk32)) {
                flags |= 0x2;
            }

            switch (flags) {
            case (0x1 | 0x2 | 0x4 | 0x8): // 0xF
                if (SQ(arg0->unkC4[i].unkC) < (SQ((xPos2.h - arg1->unk30) - (xPos1.h - arg0->unkC4[i].pos.xPos.h)) + SQ((zPos2.h - arg1->unk32) - (zPos1.h - new_var)))) {
                    changed = 0;
                }
                break;
            case (0x2 | 0x4 | 0x8): // 0xE
                if (SQ(arg0->unkC4[i].unkC) < (SQ((xPos2.h - arg1->unk30) - (xPos1.h - arg0->unkC4[i].pos.xPos.h)) + SQ((zPos2.h + arg1->unk32) - (zPos1.h - new_var)))) {
                    changed = 0;
                }
                break;
            case (0x1 | 0x2 | 0x8): // 0xB
                if (SQ(arg0->unkC4[i].unkC) < (SQ((xPos2.h + arg1->unk30) - (xPos1.h - arg0->unkC4[i].pos.xPos.h)) + SQ((zPos2.h - arg1->unk32) - (zPos1.h - new_var)))) {
                    changed = 0;
                }
                break;
            case (0x2 | 0x8):  // 0xA
                if (SQ(arg0->unkC4[i].unkC) < (SQ((xPos2.h + arg1->unk30) - (xPos1.h - arg0->unkC4[i].pos.xPos.h)) + SQ((zPos2.h + arg1->unk32) - (zPos1.h - new_var)))) {
                    changed = 0;
                }
            }

            if (changed != (arg1->unk30 * 0)) {
                if (ABS(((arg0->unkC4[i].pos.yPos.h + yPos1.h) - yPos2.h) - (arg1->unk42 >> 1)) - (arg1->unk42 >> 1) <
                    MAX(ABS((xPos1.h + arg0->unkC4[i].pos.xPos.h) - xPos2.h) - arg1->unk30,
                        ABS((zPos1.h + new_var) - zPos2.h) - arg1->unk32)) {
                    D_803D60E0 = 1;
                } else {
                    D_803D60E0 = 0;
                }
            }
        }

    }
    return changed;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6B5C_6C820C.s")
#endif

// ESA: func_80072B88
// collision with object that has custom collision data
u8 func_802B6F6C_6C861C(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2) {
    static Position D_803D60F8;

    Collision *collision;

    s16 temp_t9;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_a0;
    s16 var_t0;
    s16 var_t1;

    s32 temp_t2;
    s32 temp_t5;

    u8 ret;
    s16 pad[3];

    s16 var_t6;

    ret = 0;

    collision = arg1->unk16C->collision;

    D_803D60F8.xPos.w = 0;
    D_803D60F8.zPos.w = 0;
    D_803D60F8.yPos.w = 0;

    temp_t2 = (arg1->unk40 << 6) >> 0xB;
    temp_t5 = (((arg0->unk42 << 0xF) + yPos1.w) - yPos2.w) - (arg1->unk42 << 0xF);

    var_t0 = (((xPos1.w - xPos2.w) >> 0xB) / temp_t2) + 0x10;
    var_t1 = (((zPos1.w - zPos2.w) >> 0xB) / temp_t2) + 0x10;
    temp_v1 = ((temp_t5 >> 0xB) / temp_t2) + 0x10;

    var_a0 = MAX(1, ((arg0->unk30 + arg0->unk32) * 0x10) / temp_t2);

    switch (arg1->yRotation) {                              /* irregular */
    case 90:
        var_t6 = var_t0;
        var_t0 = 32 - var_t1;
        var_t1 = var_t6;
        break;
    case 180:
        var_t6 = 32 - var_t1;
        var_t0 = 32 - var_t0;
        var_t1 = var_t6;
        break;
    case 270:
        var_t6 = var_t0;
        var_t0 = var_t1;
        var_t1 = 32 - var_t6;
        break;
    }

    if ((var_t0 >= 0) && (var_t0 < 32) && (var_t1 >= 0) && (var_t1 < 32)) {
        temp_v0 = temp_v1 + var_a0;
        if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_t0 + (var_t1 << 5)] & (1 << temp_v0))) {
            D_803D60F8.yPos.h += 2;
            ret = 1;
        }
        temp_v0 = temp_v1 - var_a0;
        if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_t0 + (var_t1 << 5)] & (1 << temp_v0))) {
            D_803D60F8.yPos.h -= 2;
            ret = 1;
        }
    }

    if ((temp_v1 >= 0) && (temp_v1 < 32)) {
        if ((var_t0 >= 0) && (var_t0 < 32)) {
            temp_v0 = var_t1 + var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_t0 + (temp_v0 << 5)] & (1 << temp_v1))) {
                D_803D60F8.zPos.h += 2;
                ret = 1;
            }
            temp_v0 = var_t1 - var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[var_t0 + (temp_v0 << 5)] & (1 << temp_v1))) {
                D_803D60F8.zPos.h -= 2;
                ret = 1;
            }
        }
        if ((var_t1 >= 0) && (var_t1 < 32)) {
            temp_v0 = var_t0 + var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_v0 + (var_t1 << 5)] & (1 << temp_v1))) {
                D_803D60F8.xPos.h += 2;
                ret = 1;
            }
            temp_v0 = var_t0 - var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (collision->data[temp_v0 + (var_t1 << 5)] & (1 << temp_v1))) {
                D_803D60F8.xPos.h -= 2;
                ret = 1;
            }
        }
    }

    if (ret != 0) {
        switch (arg1->yRotation) {
        case 90:
            // swap x/y (flip x)
            temp_t9 = D_803D60F8.xPos.h;
            D_803D60F8.xPos.h = D_803D60F8.zPos.h;
            D_803D60F8.zPos.h = -temp_t9;
            break;
        case 180:
            // invert x/y
            D_803D60F8.xPos.h = -D_803D60F8.xPos.h;
            D_803D60F8.zPos.h = -D_803D60F8.zPos.h;
            break;
        case 270:
            // swap x/y (flip y)
            temp_t9 = D_803D60F8.xPos.h;
            D_803D60F8.xPos.h = -D_803D60F8.zPos.h;
            D_803D60F8.zPos.h = temp_t9;
            break;
        }
        *p1 = &D_803D60F8;
        *p2 = &D_803D60F8;
    }
    return ret;
}

// ESA: func_80072FF4
u8 func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2) {
    u8 check0;
    u8 check1;
    s32 velocity0;
    s32 velocity1;

    velocity0 = arg0->unk30 + arg1->unk30;
    velocity1 = arg0->unk32 + arg1->unk32;

    check0 = (((xPos1.h - velocity0) < xPos2.h) && ((xPos1.h + velocity0) > xPos2.h) &&
              ((zPos1.h - velocity1) < zPos2.h) && ((zPos1.h + velocity1) > zPos2.h));

    check1 = (((yPos2.h - arg0->unk42) < yPos1.h) && ((yPos1.h - arg1->unk42) < yPos2.h));

    return check0 && check1;
}

// ESA: func_800730AC
u8 func_802B75B4_6C8C64(Animal *arg0, Animal *arg1, Position** p1, Position** p2, Pos xPos1, Pos zPos1, Pos yPos1, Pos xPos2, Pos zPos2, Pos yPos2) {
    return 0;
}

// ESA: func_800730B4
u8 func_802B75CC_6C8C7C(Animal *arg0, Animal *arg1, s32 x, s32 y, s32 z, u8 *arg5, u16 arg6) {
    s32 pad[2];
    CollisionNode *var_s5;
    Animal *other;

    Pos xx; // sp7C
    Pos yy; // sp78
    Pos zz; // sp74

    s16 tmp;
    tmp = arg0->unk114[0];

#ifdef VERSION_EU
    // extra check only in EU
    if (arg0->unk114[0] == 0x7FFF) {
        // ignore?
        return 0;
    }
#endif

    for (var_s5 = D_803DA110[tmp].next; var_s5 != NULL; var_s5 = var_s5->next) {
        if ((arg0 != var_s5->animal) && (arg0 != arg1) && ((D_803B1BAC_7C325C[var_s5->animal->unk16C->unk2]) & (1 << (0xF - arg0->unk16C->unk2)))) {
            xx.w = x;
            if (ABS(var_s5->animal->position.xPos.h - xx.h) < (var_s5->animal->unk34 + arg0->unk34)) {
                yy.w = y;
                if (ABS(var_s5->animal->position.zPos.h - yy.h) < (var_s5->animal->unk34 + arg0->unk34)) {
                    zz.w = z;
                    if (ABS((var_s5->animal->position.yPos.h + (var_s5->animal->unk42 >> 1)) - zz.h - (arg0->unk42 >> 1)) < (var_s5->animal->unk36 + arg0->unk36)) {

                        if ((var_s5->animal->unk68 != arg0) && (arg0->unk68 != var_s5->animal) && ((var_s5->animal->unk70 != arg0) || (arg0->unk16C->unk15 != 4)) && ((arg0->unk70 != var_s5->animal) || (var_s5->animal->unk16C->unk15 != 4))) {

                            if ((var_s5->animal->state != 0x1E) && (arg0->state != 0x1E) && (var_s5->animal->state != 0x1F) && (arg0->state != 0x1F) && ((var_s5->animal->unk15C == 0) || (var_s5->animal->owner != arg0)) && ((arg0->unk15C == 0) || (arg0->owner != var_s5->animal)) && ((arg6 == 0) || (var_s5->animal->unk16C->objectType < 0x100))) {

                                other = var_s5->animal;
                                func_802B5E48_6C74F8(other, arg0, &D_803D60D0, &D_803D60D4);

                                if (((D_803D60D4 != 0) && (D_803D60D0(arg0, other, &D_803D60D8, &D_803D60DC, xx, yy, zz, other->position.xPos, other->position.zPos, other->position.yPos) != 0)) ||
                                    ((D_803D60D4 == 0) && (D_803D60D0(other, arg0, &D_803D60D8, &D_803D60DC, other->position.xPos, other->position.zPos, other->position.yPos, xx, yy, zz) != 0))) {

                                    if ((arg0->unk16C->unk2 == 9) || (other->unk16C->unk2 == 9) ||
                                        (arg0->unk16C->unk2 == 8) || (other->unk16C->unk2 == 8)) {
                                        return 0;
                                    } else{
                                        zz.w += D_803A05B4_7B1C64; // gravity*2

                                        if (((D_803D60D4 != 0) && (D_803D60D0(arg0, other, &D_803D60D8, &D_803D60DC, xx, yy, zz, other->position.xPos, other->position.zPos, other->position.yPos) != 0)) ||
                                            ((D_803D60D4 == 0) && (D_803D60D0(other, arg0, &D_803D60D8, &D_803D60DC, other->position.xPos, other->position.zPos, other->position.yPos, xx, yy, zz) != 0))) {
                                            *arg5 = 1;

                                            if ((arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (other->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                                func_8038F5F8_7A0CA8(other);
                                            }
                                            if ((other == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (arg0->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                                func_8038F5F8_7A0CA8(arg0);
                                            }
                                            func_802FD674_70ED24(arg0, other);
                                            return 1;
                                        } else {
                                            *arg5 = 0;

                                            if ((arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (other->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                                func_8038F5F8_7A0CA8(other);
                                            }
                                            if ((other == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (arg0->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                                func_8038F5F8_7A0CA8(arg0);
                                            }
                                            func_802FD674_70ED24(arg0, other);
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// ESA: func_8007374C
u8 func_802B7BC8_6C9278(Animal *arg0, Animal *arg1) {
    Vertex spC4; // 0xC
    s32    spC0; // pad
    Vertex spB4; // 0xC
    Vertex spA8; // 0xC
    Vertex res;  // sp9C; // 0xC

    s32 x0;
    s32 z0;
    s32 y0;

    s32 x1;
    s32 z1;
    s32 y1; // sp84 ?

    u8 var_v0;
    u8 checkAnimal0; // sp82
    u8 checkAnimal1;
    u8 sp80;

    s16 i;

    if ((void*)func_802B6088_6C7738 == (void*)D_803D60D0) {
        if (D_803D60D4 != 0) {
            x0 =  D_803D60DC->xPos.w;
            z0 =  D_803D60DC->zPos.w;
            y0 =  D_803D60DC->yPos.w;

            x1 = -D_803D60DC->xPos.w;
            z1 = -D_803D60DC->zPos.w;
            y1 = -D_803D60DC->yPos.w;
        } else {
            x0 = -D_803D60DC->xPos.w;
            z0 = -D_803D60DC->zPos.w;
            y0 = -D_803D60DC->yPos.w;

            x1 =  D_803D60DC->xPos.w;
            z1 =  D_803D60DC->zPos.w;
            y1 =  D_803D60DC->yPos.w;
        }
    } else {
        spB4.x = arg0->position.xPos.w / 65536.0;
        spB4.y = arg0->position.zPos.w / 65536.0;
        spB4.z = (arg0->position.yPos.w + (arg0->unk42 << 0xF)) / 65536.0;

        spA8.x = arg1->position.xPos.w / 65536.0;
        spA8.y = arg1->position.zPos.w / 65536.0;
        spA8.z = (arg1->position.yPos.w + (arg1->unk42 << 0xF)) / 65536.0;

        vector_subtract(&spA8, &spB4, &res);
        normalize_vector(&res, &spC4);
        vector_multiply_by(&spC4, 2.0f, &res);

        // struct copy, why not just use res?
        spC4 = res;

        x0 = -spC4.x * 65536.0;
        z0 = -spC4.y * 65536.0;
        y0 = -spC4.z * 65536.0;

        x1 = spC4.x * 65536.0;
        z1 = spC4.y * 65536.0;
        y1 = spC4.z * 65536.0;
    }

    if ((arg0->unk16C->unk82.unk1 != 0) || (arg0->unk4C.unk1B == 0) || (arg0->unk4A != 0) || ((x0 == 0) && (z0 == 0) && (y0 == 0))) {
        checkAnimal0 = 0;
    } else {
        checkAnimal0 = 1;
    }

    if ((arg1->unk16C->unk82.unk1 != 0) || (arg1->unk4C.unk1B == 0) || (arg1->unk4A != 0) || ((x1 == 0) && (z1 == 0) && (y1 == 0))) {
        checkAnimal1 = 0;
    } else {
        checkAnimal1 = 1;
    }

    // no collision for microchip?
    if (arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        checkAnimal1 = 0;
    }
    if (arg1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        checkAnimal0 = 0;
    }

    if ((arg0->unk44 * 3) < arg1->unk44) {
        if (checkAnimal0 == 1) {
            checkAnimal1 = 0;
        }
    } else if ((arg1->unk44 * 3) < arg0->unk44) {
        if (checkAnimal1 == 1) {
            checkAnimal0 = 0;
        }
    } else if ((arg0->unk44 * 2) < arg1->unk44) {
        x1 >>= 1;
        z1 >>= 1;
        y1 >>= 1;
    } else if ((arg1->unk44 * 2) < arg0->unk44) {
        x0 >>= 1;
        z0 >>= 1;
        y0 >>= 1;
    }

    for (i = 0, var_v0 = 1; (((checkAnimal0) || (checkAnimal1)) && (var_v0 != 0) && (i < 16)); i++) {
        if (checkAnimal0) {
            if ((func_802B75CC_6C8C7C(arg0, arg1, x0, z0, y0, &sp80, 0) == 0) && (func_80313448_724AF8(arg0, x0, z0, y0) != 0)) {
                arg0->position.yPos.w = MAX(arg0->position.yPos.w, func_80310EE4_722594(arg0->position.xPos.h, arg0->position.zPos.h, arg0->unk160));
            } else {
                checkAnimal0 = 0; // break
            }
        }
        if (checkAnimal1) {
            if ((func_802B75CC_6C8C7C(arg1, arg0, x1, z1, y1, &sp80, 0) == 0) && (func_80313448_724AF8(arg1, x1, z1, y1) != 0)) {
                arg1->position.yPos.w = MAX(arg1->position.yPos.w, func_80310EE4_722594(arg1->position.xPos.h, arg1->position.zPos.h, arg1->unk160));
            } else {
                checkAnimal1 = 0; // break
            }
        }

        if (D_803D60D4 != 0) {
           var_v0 = D_803D60D0(arg1, arg0, &D_803D60D8, &D_803D60DC, arg1->position.xPos, arg1->position.zPos, arg1->position.yPos, arg0->position.xPos, arg0->position.zPos, arg0->position.yPos);
        } else {
           var_v0 = D_803D60D0(arg0, arg1, &D_803D60D8, &D_803D60DC, arg0->position.xPos, arg0->position.zPos, arg0->position.yPos, arg1->position.xPos, arg1->position.zPos, arg1->position.yPos);
        }

        if (((void*)func_802B6088_6C7738 == (void*)D_803D60D0) && (var_v0 != 0)) {
            if (D_803D60D4 != 0) {
                x0 = D_803D60DC->xPos.w;
                z0 = D_803D60DC->zPos.w;
                y0 = D_803D60DC->yPos.w;
                x1 = -D_803D60DC->xPos.w;
                z1 = -D_803D60DC->zPos.w;
                y1 = -D_803D60DC->yPos.w;
            } else {
                x0 = -D_803D60DC->xPos.w;
                z0 = -D_803D60DC->zPos.w;
                y0 = -D_803D60DC->yPos.w;
                x1 = D_803D60DC->xPos.w;
                z1 = D_803D60DC->zPos.w;
                y1 = D_803D60DC->yPos.w;
            }
        }
    }

    arg0->newPosition.xPos.w = arg0->position.xPos.w + arg0->xVelocity.w;
    arg0->newPosition.zPos.w = arg0->position.zPos.w + arg0->zVelocity.w;
    arg0->newPosition.yPos.w = arg0->position.yPos.w + arg0->yVelocity.w;

    arg1->newPosition.xPos.w = arg1->position.xPos.w + arg1->xVelocity.w;
    arg1->newPosition.zPos.w = arg1->position.zPos.w + arg1->zVelocity.w;
    arg1->newPosition.yPos.w = arg1->position.yPos.w + arg1->yVelocity.w;

    return (var_v0 == 0);
}

// ESA: func_80073D48
void func_802B8304_6C99B4(Animal *arg0, Animal *arg1) {
    f32 var_f2;
    f32 var_f14;

    f32 sp24;
    f32 sp20;
    f32 sp1C;

    f32 var_f16;
    f32 var_f12;
    s16 var_v1;

    if (arg1->unk16C->collision != NULL) {
        var_v1 = MAX(0x800, arg1->unk40);
        if (((arg0->position.yPos.h + (arg0->unk42 >> 1)) < (arg1->position.yPos.h + (arg1->unk42 >> 1)))) {
            var_v1 = MIN(var_v1, 0x800);
        }

        arg0->xVelocity.w -= (D_803D60DC->xPos.w * var_v1) >> 0xB;
        arg0->zVelocity.w -= (D_803D60DC->zPos.w * var_v1) >> 0xB;
        arg0->yVelocity.w -= (D_803D60DC->yPos.w * var_v1) >> 0xB;
        return;
    }

    var_f2 = (arg0->position.xPos.w - arg1->position.xPos.w) / 65536.0;
    var_f14 = (arg0->position.zPos.w - arg1->position.zPos.w) / 65536.0;

    if (arg1->unk16C->unk15 == 4) {
        if (var_f2 < 0.0f) {
            var_f2 = MIN(0.0f, var_f2 + (arg1->unk30 - 2));
        } else {
            var_f2 = MAX(0.0f, var_f2 - (arg1->unk30 - 2));
        }

        if (var_f14 < 0.0f) {
            var_f14 = MIN(0.0f, var_f14 + (arg1->unk32 - 2));
        } else {
            var_f14 = MAX(0.0f, var_f14 - (arg1->unk32 - 2));
        }
    }

    sp24 = sqrtf((var_f2 * var_f2) + (var_f14 * var_f14));
    sp20 = ((arg0->xVelocity.w - arg1->xVelocity.w) / 65536.0);
    sp1C = ((arg0->zVelocity.w - arg1->zVelocity.w) / 65536.0);
    if (sqrtf(SQ(sp20) + SQ(sp1C)) < 4.0) {
        if (sp24 != 0.0) {
            var_f16 = ((MAX(0x800, arg1->unk40) * (var_f2 * 0.7)) / (sp24 * 2048.0f));
            var_f12 = ((MAX(0x800, arg1->unk40) * (var_f14 * 0.7)) / (sp24 * 2048.0f));
            if (((sp20 * var_f16) + (sp1C * var_f12)) < 0.0f) {
                arg0->xVelocity.w = arg1->xVelocity.w;
                arg0->zVelocity.w = arg1->zVelocity.w;
            }
        } else {
            var_f16 = 0.7f;
            var_f12 = -0.7f;
        }
        arg0->xVelocity.w += (s32) (var_f16 * 65536.0);
        arg0->zVelocity.w += (s32) (var_f12 * 65536.0);
    }
}
