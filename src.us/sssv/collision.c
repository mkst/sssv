#include <ultra64.h>
#include "common.h"



#if 0

extern u16 D_803A0510_7B1BC0[];
extern u8  D_803D60E8;
static u16 D_803D60E2;

// CURRENT (15670)
void func_802B4D20_6C63D0(void) {
    s16 i; // sp136
    struct065 *sp130;
    struct065 *sp12C;

    s32 sp11C;
    s32 sp118;
    s32 sp114;

    s32 sp110;
    s32 sp10C;
    s32 sp108;

    Vertex spF8;
    Vertex spEC;
    Vertex spE0;
    Vertex spD4;

    Animal *animal1;
    Animal *animal2;
    f32 var_f2;
    s16 temp_s2;
    s32 temp_a0_6;
    s32 temp_lo;
    s32 totalMass;
    s32 temp_v1_6;
    s32 var_s5;
    u16 var_s3;
    u16 var_s4;

    s32  (*collision_func)(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2);

    for (i = 0; i < 40; i++) {
        for (sp130 = D_803DA110[i].next; sp130 != NULL; sp130 = sp130->next) {
            for (sp12C = sp130->next; sp12C != NULL; sp12C = sp12C->next) {

                if ((((i == sp130->animal->unk114[0]) && ((i == sp12C->animal->unk114[0]))) ||
                     ((i == sp130->animal->unk114[0]) && (sp12C->animal->unk114[0] < i)) ||
                     ((i == sp12C->animal->unk114[0]) && (sp130->animal->unk114[0] < i)))
                    && (D_803B1BAC_7C325C[sp130->animal->unk16C->unk2] & (1 << (0xF - sp12C->animal->unk16C->unk2)))) {

                    animal1 = sp130->animal;
                    animal2 = sp12C->animal;

                    if ((ABS(animal1->unk10.h - animal2->unk10.h) < (animal1->unk34 + animal2->unk34)) &&
                        (ABS(animal1->unk14.h - animal2->unk14.h) < (animal1->unk34 + animal2->unk34)) &&
                        (ABS(((animal1->unk18.h + (animal1->unk42 >> 1)) - animal2->unk18.h) - (animal2->unk42 >> 1)) < (animal1->unk36 + animal2->unk36))) {

                        if (((animal2 != animal1->unk68) || (((D_803A0510_7B1BC0[(animal1->unk16C->unk2)]) & (1 << (0xF - animal2->unk16C->unk2))) == 0)) &&
                            ((animal1 != animal2->unk68) || (((D_803A0510_7B1BC0[(animal2->unk16C->unk2)]) & (1 << (0xF - animal1->unk16C->unk2))) == 0)) &&
                            ((animal2 != animal1->unk70) || (animal2->unk16C->unk15 != 4) || (animal1->unk16C->unk2 != 5)) &&
                            ((animal1 != animal2->unk70) || (animal1->unk16C->unk15 != 4) || (animal2->unk16C->unk2 != 5))) {

                            if ((animal1->state != 0x1E) && (animal2->state != 0x1E) &&
                                (animal1->state != 0x1F) && (animal2->state != 0x1F) &&
                                ((animal1->unk15C == 0) || (animal2 != animal1->unk168)) &&
                                ((animal2->unk15C == 0) || (animal1 != animal2->unk168))) {

                                temp_s2 = func_802B5E48_6C74F8(animal1, animal2, &D_803D60D0, &D_803D60D4);

                                collision_func = D_803D60D0;

                                if (((D_803D60D4 != 0) && (collision_func(animal2, animal1, D_803D60D8, D_803D60DC, animal2->unk10.w, animal2->unk14.w, animal2->unk18.w, animal1->unk10.w, animal1->unk14.w, animal1->unk18.w) != 0)) ||
                                    ((D_803D60D4 == 0) && (collision_func(animal1, animal2, D_803D60D8, D_803D60DC, animal1->unk10.w, animal1->unk14.w, animal1->unk18.w, animal2->unk10.w, animal2->unk14.w, animal2->unk18.w) != 0))) {

                                    animal1->unk4C.unk25 = 1;
                                    animal2->unk4C.unk25 = 1;

                                    if ((animal1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (animal2->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                        func_8038F5F8_7A0CA8(animal2);
                                    }
                                    if ((animal2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (animal1->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                        func_8038F5F8_7A0CA8(animal1);
                                    }

                                    func_802FD674_70ED24(animal2, animal1);
                                    sp11C = animal1->xVelocity.w;
                                    sp114 = animal1->zVelocity.w;
                                    sp10C = animal1->yVelocity.w;

                                    sp118 = animal2->xVelocity.w;
                                    sp110 = animal2->zVelocity.w;
                                    sp108 = animal2->yVelocity.w;

                                    if ((animal1->unk16C->unk2 == 9) || (animal2->unk16C->unk2 == 9) ||
                                        (animal1->unk16C->unk2 == 8) || (animal2->unk16C->unk2 == 8)) {
                                        func_802CAB20_6DC1D0(animal1, animal2, sp11C, sp114, (s16) (s32) (s16) sp10C, (s16) (s32) (s16) sp118, (s16) (s32) (s16) sp110, (s16) (s32) (s16) sp108);
                                    } else {
                                        var_f2 = 1.0f;
                                        spF8.x = animal1->xPos.w / 65536.0;
                                        spF8.y = animal1->zPos.w / 65536.0;
                                        spF8.z = (animal1->yPos.w / 65536.0) + (animal1->unk42 >> 1);

                                        spEC.x = animal1->xVelocity.w / 65536.0;
                                        spEC.y = animal1->zVelocity.w / 65536.0;
                                        spEC.z = animal1->yVelocity.w / 65536.0;

                                        spE0.x = animal2->xPos.w / 65536.0;
                                        spE0.y = animal2->zPos.w / 65536.0;
                                        spE0.z = (animal2->yPos.w / 65536.0) + (animal2->unk42 >> 1);

                                        spD4.x = animal2->xVelocity.w / 65536.0;
                                        spD4.y = animal2->zVelocity.w / 65536.0;
                                        spD4.z = animal2->yVelocity.w / 65536.0;

                                        if ((((temp_s2 == 5) || (temp_s2 == 4)) && (D_803D60E8 == 1) && (((animal1->unk16C->unk80.unk12 != 0)) || (animal2->unk16C->unk80.unk12 != 0))) ||
                                            (((temp_s2 == 1) || (temp_s2 == 2)) && (D_803D60DC->unk8.w == 0) &&
                                              (((animal1->unk16C->unk80.unk12 != 0) && (((animal2->yPos.h < (animal1->yPos.h + (animal1->unk42 >> 1))))) && ((animal1->yPos.h + (animal1->unk42 >> 1)) < (animal2->yPos.h + animal2->unk42))) ||
                                               ((animal2->unk16C->unk80.unk12 != 0) && (((animal1->yPos.h < (animal2->yPos.h + (animal2->unk42 >> 1))))) && ((animal2->yPos.h + (animal2->unk42 >> 1)) < (animal1->yPos.h + animal1->unk42)))))) {
                                            var_f2 = 0.125f;
                                            var_s5 = 1;
                                        } else {
                                            var_s5 = 0;
                                        }

                                        if (((animal1->unk16C->unk80.unk12 != 0) && (animal1->unkC4 == D_803D60D8) && (((animal1->unk162 == 1)) || (animal1->unk162 == 6)) && ((animal2->unk162 == 1) || (animal2->unk162 == 6)) && (animal2->unk4C.unk27 != 0) && (animal2->unk16C->unk80.unk12 == 0)) ||
                                            ((animal2->unk16C->unk80.unk12 != 0) && (animal2->unkC4 == D_803D60D8) && (((animal1->unk162 == 1)) || (animal1->unk162 == 6)) && ((animal2->unk162 == 1) || (animal2->unk162 == 6)) && (animal1->unk4C.unk27 != 0) && (animal1->unk16C->unk80.unk12 == 0))) {

                                            var_s3 = animal1->unk44;
                                            var_s4 = animal2->unk44;

                                            if (animal1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
                                                var_s3 = 0;
                                            } else if (animal2->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
                                                var_s4 = 0;
                                            }

                                            if ((animal1->unk16C->unk80.unk12 != 0) && (animal2->unk16C->unk80.unk12 != 0)) { // & 0x2000
                                                if ((animal1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (animal1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
                                                    var_s3 *= 3;
                                                    play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, animal1->xPos.h, animal1->zPos.h, animal1->yPos.h, 1.0f);
                                                }
                                                if ((animal2->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (animal2->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
                                                    var_s4 *= 3;
                                                    play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, animal2->xPos.h, animal2->zPos.h, animal2->yPos.h, 1.0f);
                                                }
                                            } else if ((var_s4 * 3) < var_s3) {
                                                var_s4 = 0;
                                            } else if ((var_s3 * 3) < var_s4) {
                                                var_s3 = 0;
                                            }

                                            totalMass = var_s3 + var_s4;
                                            if (totalMass == 0) {
                                                rmonPrintf("\nASSERT: TotalMass != 0, %s, %u\n", "../src/collsion.c", 326);
                                                *(volatile int*)0 = 0;
                                            }

                                            animal1->xVelocity.w = animal2->xVelocity.w = ((var_s3 * animal1->xVelocity.w) + (var_s4 * animal2->xVelocity.w)) / totalMass;
                                            animal1->zVelocity.w = animal2->zVelocity.w = ((var_s3 * animal1->zVelocity.w) + (var_s4 * animal2->zVelocity.w)) / totalMass;

                                            if (var_s5 == 0) {
                                                temp_v1_6 = animal1->yVelocity.w;
                                                temp_a0_6 = animal2->yVelocity.w;
                                                if ((animal1->unk4C.unk27 != 0) && (animal1->unk16C->unk80.unk11 == 0)) { // unk4C << 0x1B) >> 0x1F .. unk80 << 0x11) >> 0x1F
                                                    animal1->yVelocity.w = ((var_s3 * temp_v1_6) + (var_s4 * temp_a0_6)) / totalMass;
                                                }
                                                if ((animal2->unk4C.unk27 != 0) && (animal2->unk16C->unk80.unk11 == 0)) { // unk4C << 0x1B) >> 0x1F .. unk80 << 0x11) >> 0x1F
                                                    animal2->yVelocity.w = ((var_s3 * temp_v1_6) + (var_s4 * temp_a0_6)) / totalMass;
                                                }
                                            }
                                        } else {
                                            if (var_s5 != 0) {
                                                spEC.z = 0.0f;
                                                spD4.z = 0.0f;
                                                spF8.z = 0.0f;
                                                spE0.z = 0.0f;
                                            }
                                            func_80319280_72A930(animal1, &spF8, &spEC, animal2, &spE0, &spD4, var_f2 * 0.6, var_f2 * 0.8);

                                            if ((animal1->unk4C.unk27) && (animal1->unk16C->unk80.unk11 == 0)) { // unk4C & 0x10 ... unk80 & 0x4000
                                                animal1->xVelocity.w = spEC.x * 65536.0f;
                                                animal1->zVelocity.w = spEC.y * 65536.0f;
                                                if (var_s5 == 0) {
                                                    animal1->yVelocity.w = spEC.z * 65536.0f;
                                                }
                                                if (animal1->unk16C->unk2 == 5) {
                                                    func_802B8304_6C99B4(animal1, animal2);
                                                }
                                            }
                                            if ((animal2->unk4C.unk27) && (animal2->unk16C->unk80.unk11 == 0)) { // unk4C & 0x10 ... unk80 & 0x4000
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

                                        if ((animal1->unk16C->unk80.unk12) && (animal1->unkC4 == D_803D60D8) && ((animal2->unk16C->unk80.unk11) || ((animal2->unk16C->unk18 != NULL) && (animal2->unk40 > 0x1000))) && ((animal1->unk16C->unk9C == HYENA) || (animal1->unk16C->unk9C == HYENA_BIKER) || (animal1->unk16C->unk9C == DOG) || (animal1->unk16C->unk9C == RACING_DOG)) && (animal1->unk3C0.unk0 != 0x10)) {
                                            animal1->unk3C0.unk0 = 0x10;
                                            animal1->unk3C0.unk2 = 0;
                                        }
                                        if ((animal2->unk16C->unk80.unk12) && (animal2->unkC4 == D_803D60DC) && (animal1->unk16C->unk80.unk11) && (((animal2->unk16C->unk9C == HYENA)) || (animal2->unk16C->unk9C == HYENA_BIKER) || (animal2->unk16C->unk9C == DOG) || (animal2->unk16C->unk9C == RACING_DOG)) && (animal2->unk3C0.unk0 != 0x10)) {
                                            animal2->unk3C0.unk0 = 0x10;
                                            animal2->unk3C0.unk2 = 0;
                                        }

                                        animal1->unk48 = animal2->unk48 = D_803D5544;
                                        // animal1->unk48 = D_803D5544;

                                        if (animal1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
                                            if ((D_803D5544 - D_803D60E2) >= 5) {
                                                D_803D5546 = MAX(2, D_803D5546);
                                                goto block_157;
                                            }
                                        } else if ((animal2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && ((D_803D5544 - D_803D60E2) >= 5)) {
                                            D_803D5546 = MAX(2, D_803D5546);
block_157:
                                            D_803D60E2 = D_803D5544;
                                        }
                                        func_802CAB20_6DC1D0(animal1, animal2, sp11C, sp114, (s16) (s32) (s16) sp10C, (s16) (s32) (s16) sp118, (s16) (s32) (s16) sp110, (s16) (s32) (s16) sp108);

                                        animal1->unk10.w = animal1->xPos.w + animal1->xVelocity.w;
                                        animal1->unk14.w = animal1->zPos.w + animal1->zVelocity.w;
                                        animal1->unk18.w = animal1->yPos.w + animal1->yVelocity.w;

                                        animal2->unk10.w = animal2->xPos.w + animal2->xVelocity.w;
                                        animal2->unk14.w = animal2->zPos.w + animal2->zVelocity.w;
                                        animal2->unk18.w = animal2->yPos.w + animal2->yVelocity.w;

                                        if (((D_803D60D4 != 0) && (collision_func(animal2, animal1, D_803D60D8, D_803D60DC, animal2->xPos.w, animal2->zPos.w, animal2->yPos.w, animal1->xPos.w, animal1->zPos.w, animal1->yPos.w) == 0)) ||
                                            ((D_803D60D4 == 0) && (collision_func(animal1, animal2, D_803D60D8, D_803D60DC, animal1->xPos.w, animal1->zPos.w, animal1->yPos.w, animal2->xPos.w, animal2->zPos.w, animal2->yPos.w) != 0))) {
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
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B4D20_6C63D0.s")
#endif

s32 func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, s32 (**collision_func)(Animal *arg0, Animal *arg1, struct043**, struct043**, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z3), u8 *arg3) {
    struct035 *a0; // arg0
    struct035 *a1; // arg1
    s32 res = 0;

    *collision_func = NULL;
    a0 = arg0->unk16C;
    if (a0->unk15 == 4) {
        a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            res = 6;
            *collision_func = func_802B750C_6C8BBC;
            *arg3 = 0;
        } else if (a1->unk18 != 0) {
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
    } else if (a0->unk18 != 0) {
        a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            if (arg1->unkC4[0].unkC != 0) {
                res = 7;
                *collision_func = func_802B6F6C_6C861C;
                *arg3 = 1;
            } else {
                res = 8;
                *collision_func = func_802B6F6C_6C861C;
                *arg3 = 1;
            }
        } else if (a1->unk18 != 0) {
            if ((arg0->unkC4[0].unkC != 0) && (arg1->unkC4[0].unkC != 0)) {
                res = 1;
                *collision_func = func_802B6088_6C7738;
                if ((u32) arg0 < (u32) arg1) { // memory address lower!
                    *arg3 = 0;
                } else {
                    *arg3 = 1;
                }
            } else {
                if (arg0->unkC4[0].unkC != 0) {
                    res = 1;
                    *collision_func = func_802B6088_6C7738;
                    *arg3 = 0;
                } else {
                    res = 9;
                    *collision_func = func_802B75B4_6C8C64;
                    *arg3 = 0;
                }

            }
        } else {
            res = 0;
            if (arg1->unkC4[0].unkC != 0) {
                res = 2;
                *collision_func = func_802B6088_6C7738;
                *arg3 = 1;
            }
        }
    } else {
        res = 0;
        if (arg0->unkC4[0].unkC != 0) {
            a1 = arg1->unk16C;
            if (a1->unk15 == 4) {
                res = 4;
                *collision_func = func_802B6B5C_6C820C;
                *arg3 = 0;
            } else if (a1->unk18 != 0) {
                res = 1;
                *collision_func = func_802B6088_6C7738;
                *arg3 = 0;
            } else {
                res = 0;
                if (arg1->unkC4[0].unkC != 0) {
                    res = 3;
                    *collision_func = func_802B6948_6C7FF8;
                    *arg3 = 0;
                }
            }
        }
    }

    // default collision func?
    if (res == 0) {
        *collision_func = func_802B6948_6C7FF8;
        *arg3 = 0;
    }
    return res;
}

#if 0
u8 func_802B6088_6C7738(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {

    static struct043 D_803D60E8;

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
    struct035_ptr *temp_t2;
    s32 temp_t5;

    u8 changed;
    s32 i;

    *arg2 = *arg3 = NULL;

    temp_t2 = arg1->unk16C->unk18;

    D_803D60E8.unk0.w = 0;
    D_803D60E8.unk4.w = 0;
    D_803D60E8.unk8.w = 0;

    changed = 0;

    for (i = 0; ((arg0->unkC4[i].unkC != 0) && (i < 5)); i++) {

        temp_a0 =  (arg1->unk40 << 6) >> 0xB;

        temp_t5 = ((arg0->unkC4[i].unk8.w + arg6) - arg9) - (arg1->unk42 << 0xF);

        var_a2 = ((((arg0->unkC4[i].unk0.w + arg4) - arg7) >> 0xB) / (temp_a0)) + 16;
        var_a1 = ((((arg0->unkC4[i].unk4.w + arg5) - arg8) >> 0xB) / (temp_a0)) + 16;

        var_t1 = MAX(1, (arg0->unkC4[i].unkC << 5) / (temp_a0));
        var_t3 = MAX(1, (var_t1 * 3) >> 2);

        // increment i here?

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
                var_t6 = 32 - var_a2;
                var_a2 = var_a1;
                var_a1 = var_t6;
                break;
            }
        }

        temp_a3 = ((temp_t5 >> 0xB) / temp_a0) + 0x10;
        if ((var_a2 >= 0) && (var_a2 < 32) && (var_a1 >= 0) && (var_a1 < 32)) {
            temp_v0 = temp_a3 + var_t1;
            // ((temp_t2 + (temp_a0_3 * 4) + (temp_v1_2 << 7))->unk8
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[var_a2][var_a1] & (1 << temp_v0))) {
                D_803D60E8.unk8.h += 2;
                changed = 1;
                *arg2 = arg0->unkC4;
            }
            temp_v0 = temp_a3 - var_t1;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[var_a2][var_a1] & (1 << temp_v0))) {
                D_803D60E8.unk8.h -= 2;
                changed = 1;
                *arg2 = arg0->unkC4;
            }
        }

        if ((temp_a3 >= 0) && (temp_a3 < 32)) {
            if ((var_a2 >= 0) && (var_a2 < 32)) {
                temp_v0 = var_a1 + var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[var_a2][temp_v0] & (1 << temp_a3))) {
                    D_803D60E8.unk4.h += 2;
                    changed = 1;
                    *arg2 = arg0->unkC4;
                }
                temp_v0 = var_a1 - var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[var_a2][temp_v0] & (1 << temp_a3))) {
                    D_803D60E8.unk4.h -= 2;
                    changed = 1;
                    *arg2 = arg0->unkC4;
                }
            }
            if ((var_a1 >= 0) && (var_a1 < 32)) {
                temp_v0 = var_a2 + var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[temp_v0][var_a1] & (1 << temp_a3))) {
                    D_803D60E8.unk0.h += 2;
                    changed = 1;
                    *arg2 = arg0->unkC4; // var_t0 + 0xC4;
                }
                temp_v0 = var_a2 - var_t1;
                if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[temp_v0][var_a1] & (1 << temp_a3))) {
                    D_803D60E8.unk0.h -= 2 ;
                    changed = 1;
                    *arg2 = arg0->unkC4;
                }
            }
            if (changed == 0) {
                temp_a0_2 = var_a2 + var_t3;
                if ((temp_a0_2 >= 0) && (temp_a0_2 < 32)) {
                    temp_v0 = var_a1 + var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[temp_a0_2][temp_v0] & (1 << temp_a3))) {
                        D_803D60E8.unk0.h += 2;
                        D_803D60E8.unk4.h += 2;
                        *arg2 = arg0->unkC4; // var_t0 + 0xC4;
                        changed = 1;
                    }
                    temp_v0 = var_a1 - var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[temp_a0_2][temp_v0] & (1 << temp_a3))) {
                        D_803D60E8.unk0.h += 2;
                        D_803D60E8.unk4.h -= 2;
                        *arg2 = arg0->unkC4;
                        changed = 1;
                    }
                }

                temp_a0_2 = var_a2 - var_t3;
                if ((temp_a0_2 >= 0) && (temp_a0_2 < 32)) {
                    temp_v0 = var_a1 + var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[temp_a0_2][temp_v0] & (1 << temp_a3))) {
                        D_803D60E8.unk0.h -= 2;
                        D_803D60E8.unk4.h += 2;
                        *arg2 = arg0->unkC4;
                        changed = 1;
                    }
                    temp_v0 = var_a1 - var_t3;
                    if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t2->unk8[temp_a0_2][temp_v0] & (1 << temp_a3))) {
                        D_803D60E8.unk0.h -= 2;
                        D_803D60E8.unk4.h -= 2;
                        *arg2 = arg0->unkC4;
                        changed = 1;
                    }
                }
            }
        }

        if (changed != 0) {
            break;
        }
    }

    if (changed != 0) {
        switch (arg1->yRotation) {
        case 90:
            temp_t9 = D_803D60E8.unk4.h;
            D_803D60E8.unk4.h = -D_803D60E8.unk0.h;
            D_803D60E8.unk4.h = temp_t9;
            break;
        case 180:
            D_803D60E8.unk0.h = -D_803D60E8.unk0.h;
            D_803D60E8.unk0.h = -D_803D60E8.unk4.h;
            break;
        case 270:
            temp_t9 = D_803D60E8.unk0.h;
            D_803D60E8.unk0.h = -D_803D60E8.unk4.h;
            D_803D60E8.unk0.h = temp_t9;
            break;
        }

        // randomise collision?
        if ((D_803D60E8.unk0.h == 0) && (D_803D60E8.unk4.h == 0) && (D_803D60E8.unk8.h == 0)) {
            D_803D60E8.unk0.w = (SSSV_RAND(256) - 128) << 0xA;
            D_803D60E8.unk4.w = (SSSV_RAND(256) - 128) << 0xA;
        }
        *arg3 = &D_803D60E8;
    }
    return changed;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6088_6C7738.s")
#endif

#if 0
// CURRENT (6287)
s32 func_802B6948_6C7FF8(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s16 i;
    s16 j;

    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_v0;

    s16 var_t6;
    s16 var_t7;
    s16 var_t8;
    u8 var_v0;

    var_v0 = 0;

    for (i = 0; ((var_v0 == 0) && (arg0->unkC4[i].unkC != 0) && (i < 5)); i++) {

        for (j = 0; ((var_v0 == 0) && (arg1->unkC4[j].unkC != 0) && (j < 5)); j++) {

            temp_v0 = arg1->unkC4[j].unkC + arg0->unkC4[i].unkC;

            temp_a3 = ((arg1->unkC4[j].unk0.w + arg7) - arg0->unkC4[i].unk0.w) - arg4;
            if (temp_a3 < 0) {
                var_t8 = (temp_a3 + 0xFFFF) >> 0x10;
            } else {
                var_t8 = temp_a3 >> 0x10;
            }

            temp_t0 = ((arg1->unkC4[j].unk4.w + arg8) - arg0->unkC4[i].unk4.w) - arg5;
            if (temp_t0 < 0) {
                var_t7 = (temp_t0 + 0xFFFF) >> 0x10;
            } else {
                var_t7 = temp_t0 >> 0x10;
            }

            temp_t1 = ((arg1->unkC4[j].unk8.w + arg9) - arg0->unkC4[i].unk8.w) - arg6;
            if (temp_t1 < 0) {
                var_t6 = (temp_t1 + 0xFFFF) >> 0x10;
            } else {
                var_t6 = temp_t1 >> 0x10;
            }

            var_v0 = (u32)(SQ(var_t8) + SQ(var_t7) + SQ(var_t6)) < (u32)SQ(temp_v0);

            if (var_v0 != 0) {
                *arg2 = &arg0->unkC4[i];
                *arg3 = &arg1->unkC4[j];
            }
        }

    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6948_6C7FF8.s")
#endif

#if 0
// CURRENT (3649)
extern u8 D_803D60E0;
s32 func_802B6B5C_6C820C(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    s16 temp_a1_2;
    s16 temp_a2;
    s16 temp_t4;
    s16 temp_t5;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t3;
    s32 temp_t3_2;
    s32 temp_t6;
    s32 temp_v0;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_5;
    u8 var_s0;
    s32 i;
    s32 var_v0;
    u8 var_v0_2;

    *arg2 = NULL;
    D_803D60E0 = 0;

    var_s0 = 0;

    for (i = 0; (arg0->unkC4[i].unkC != 0) && (var_s0 == 0) && (i < 5); i++) {

        temp_a0 = arg0->unkC4[i].unkC + arg1->unk30;
        temp_a1 = arg0->unkC4[i].unkC + arg1->unk32;

        var_s0 = (((arg0->unkC4[i].unk0.h + arg4) > (arg7 - temp_a0)) &&
                  ((arg0->unkC4[i].unk0.h + arg4) < (arg7 + temp_a0)) &&
                  ((arg0->unkC4[i].unk4.h + arg5) > (arg8 - temp_a1)) &&
                  ((arg0->unkC4[i].unk4.h + arg5) < (arg8 + temp_a1)) &&
                  ((arg6 + arg0->unkC4[i].unk8.h) > (arg9 - arg0->unkC4[i].unkC)) &&
                  ((arg6 + arg0->unkC4[i].unk8.h) < (arg9 + arg0->unkC4[i].unkC + arg1->unk42)));

        if (var_s0 != 0) {
            var_v0_2 = 0;

            *arg2 = &arg0->unkC4[i];

            temp_t5 = arg1->unk30;
            temp_a2 = arg0->unkC4[i].unk0.h;
            temp_t1 = arg7 - temp_t5;
            temp_t2_2 = temp_a2 + arg4;

            if (temp_t2_2 < temp_t1) {
                var_v0_2 = (0x4 | 0x8);
            } else if ((arg7 + temp_t5) < temp_t2_2) {
                var_v0_2 = 0x8;
            }
            temp_a1_2 = arg0->unkC4[i].unk4.h;
            temp_t4 = arg1->unk32;
            temp_t3_2 = temp_a1_2 + arg5;
            temp_a3 = arg8 - temp_t4;

            if (temp_t3_2 < temp_a3) {
                var_v0_2 |= (0x1 | 0x2);
            } else if ((arg8 + temp_t4) < temp_t3_2) {
                var_v0_2 |= 0x2;
            }

            switch (var_v0_2) {
            default:
                break; // tbd
            case (0x2 | 0x8): // 0xA
                temp_v0 = arg0->unkC4[i].unkC;
                temp_v1 = ((arg7 + temp_t5) - arg4) + temp_a2;
                temp_a0_3 = ((arg8 + temp_t4) - arg5) + temp_a1_2;
                if (SQ(temp_v0) < (SQ(temp_v1) + SQ(temp_a0_3))) {
                    var_s0 = 0;
                }
                break;
            case (0x1 | 0x2 | 0x8): // 0xB
                temp_v0 = arg0->unkC4[i].unkC;
                temp_v1 = ((arg7 + temp_t5) - arg4) + temp_a2;
                temp_a0_3 = (temp_a3 - arg5) + temp_a1_2;
                if (SQ(temp_v0) < (SQ(temp_v1) + SQ(temp_a0_3))) {
                    var_s0 = 0;
                }
                break;
            case (0x2 | 0x4 | 0x8): // 0xE
                temp_v0 = arg0->unkC4[i].unkC;
                temp_v1 = (temp_t1 - arg4) + temp_a2;
                temp_a0_3 = ((arg8 + temp_t4) - arg5) + temp_a1_2;
                if (SQ(temp_v0) < (SQ(temp_v1) + SQ(temp_a0_3))) {
                    var_s0 = 0;
                }
                break;
            case (0x1 | 0x2 | 0x4 | 0x8): // 0xF
                temp_v0 = arg0->unkC4[i].unkC;
                temp_v1 = (temp_t1 - arg4) + temp_a2;
                temp_a0_3 = (temp_a3 - arg5) + temp_a1_2;
                if (SQ(temp_v0) < (SQ(temp_v1) + SQ(temp_a0_3))) {
                    var_s0 = 0;
                }
                break;
            }

            if (var_s0 != 0) {
                temp_t6 = arg1->unk42 >> 1;
                temp_v0_5 = ((arg0->unkC4[i].unk8.h + arg6) - arg9) - temp_t6;

                if ((ABS(temp_v0_5) - temp_t6) < MAX((ABS(temp_t2_2 - arg7) - temp_t5), (ABS(temp_t3_2 - arg8) - temp_t4))) {
                    D_803D60E0 = 1;
                } else {
                    D_803D60E0 = 0;
                }
            }
        }
    }
    return var_s0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6B5C_6C820C.s")
#endif

#if 0
// need to figure out struct035_ptr
// CURRENT (3500)
s32 func_802B6F6C_6C861C(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    static struct043 D_803D60F8;
    s16 temp_t9;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_a0;
    s16 var_t0;
    s16 var_t1;
    struct035_ptr *temp_t4;
    s32 temp_t2;
    s32 temp_t5;
    s32 ret;

    s32 pad[2];

    ret = 0;
    temp_t4 = arg1->unk16C->unk18;

    D_803D60F8.unk0.w = 0;
    D_803D60F8.unk4.w = 0;
    D_803D60F8.unk8.w = 0;

    temp_t2 = (arg1->unk40 << 6) >> 0xB;
    temp_t5 = (((arg0->unk42 << 0xF) + arg6) - arg9) - (arg1->unk42 << 0xF);

    var_t0 = temp_v0 = (((arg4 - arg7) >> 0xB) / temp_t2) + 0x10;
    var_t1 = temp_v1 = (((arg5 - arg8) >> 0xB) / temp_t2) + 0x10;

    var_a0 = MAX(1, ((arg0->unk30 + arg0->unk32) * 0x10) / temp_t2);

    switch (arg1->yRotation) {                              /* irregular */
    case 90:
        var_t0 = 32 - temp_v1;
        var_t1 = temp_v0;
        break;
    case 180:
        var_t0 = 32 - temp_v0;
        var_t1 = 32 - temp_v1;
        break;
    case 270:
        var_t0 = temp_v1;
        var_t1 = 32 - temp_v0;
        break;
    }

    temp_v1 = ((temp_t5 >> 0xB) / temp_t2) + 0x10;
    if ((var_t0 >= 0) && (var_t0 < 32)) {
        if ((var_t1 >= 0) && (var_t1 < 32)) {
            temp_v0 = temp_v1 + var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t4->unk8[var_t1][var_t0] & (1 << temp_v0))) {
                ret = 1;
                D_803D60F8.unk8.h += 2;
            }
            temp_v0 = temp_v1 - var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t4->unk8[var_t1][var_t0] & (1 << temp_v0))) {
                ret = 1;
                D_803D60F8.unk8.h -= 2;
            }
        }
    }

    if ((temp_v1 >= 0) && (temp_v1 < 32)) {
        if ((var_t0 >= 0) && (var_t0 < 32)) {
            temp_v0 = var_t1 + var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t4->unk8[var_t0][temp_v0] & (1 << temp_v1))) {
                ret = 1;
                D_803D60F8.unk4.h += 2;
            }
            temp_v0 = var_t1 - var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t4->unk8[var_t0][temp_v0] & (1 << temp_v1))) {
                ret = 1;
                D_803D60F8.unk4.h -= 2;
            }
        }
        if ((var_t1 >= 0) && (var_t1 < 32)) {
            temp_v0 = var_t0 + var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t4->unk8[temp_v0][var_t1] & (1 << temp_v1))) {
                ret = 1;
                D_803D60F8.unk0.h += 2;
            }
            temp_v0 = var_t0 - var_a0;
            if ((temp_v0 >= 0) && (temp_v0 < 32) && (temp_t4->unk8[temp_v0][var_t1] & (1 << temp_v1))) {
                ret = 1;
                D_803D60F8.unk0.h -= 2;
            }
        }
    }

    if (ret != 0) {
        switch (arg1->yRotation) {
        case 90:
            // swap x/y (flip x)
            temp_t9 = D_803D60F8.unk4.h;
            D_803D60F8.unk4.h = -D_803D60F8.unk0.h;
            D_803D60F8.unk0.h = temp_t9;
            break;
        case 180:
            // invert x/y
            D_803D60F8.unk0.h = -D_803D60F8.unk0.h;
            D_803D60F8.unk4.h = -D_803D60F8.unk4.h;
            break;
        case 270:
            // swap x/y (flip y)
            temp_t9 = D_803D60F8.unk0.h;
            D_803D60F8.unk0.h = -D_803D60F8.unk4.h;
            D_803D60F8.unk4.h = temp_t9;
            break;
        }
        *arg2 = &D_803D60F8;
        *arg3 = &D_803D60F8;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6F6C_6C861C.s")
#endif

#ifdef NON_MATCHING
// is the function definition wrong??
// CURRENT (12)
u8 func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    u8 check0;
    u8 check1;
    s32 velocity0;
    s32 velocity1;

    velocity0 = arg0->unk30 + arg1->unk30;
    velocity1 = arg0->unk32 + arg1->unk32;

    check0 = ((((s16)arg4 - velocity0) < (s16)arg7) && (((s16)arg4 + velocity0) > (s16)arg7) &&
              (((s16)arg5 - velocity1) < (s16)arg8) && (((s16)arg5 + velocity1) > (s16)arg8));

    check1 = ((((s16)arg9 - arg0->unk42) < (s16)arg6) && (((s16)arg6 - arg1->unk42) < (s16)arg9));

    return check0 && check1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B750C_6C8BBC.s")
#endif

s32 func_802B75B4_6C8C64(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    return 0;
}

// broken expansion pak function?
#if 0
s32 func_802B75CC_6C8C7C(Animal *arg0, Animal *arg1, s32 x, s32 y, s32 z, u8 *arg5, u16 arg6) {
    Animal *animal2;
    struct065 *var_s5;
    s32  (*collision_func)(Animal *arg0, Animal *arg1, struct043 **arg2, struct043 **arg3, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2);

    for (var_s5 = D_803DA110[arg0->unk114[0]].next; var_s5 != NULL; var_s5 = var_s5->next) {
        if ((arg0 != var_s5->animal) && (arg0 != arg1) && ((D_803B1BAC_7C325C[var_s5->animal->unk16C->unk2]) & (1 << (0xF - arg0->unk16C->unk2)))) {
            // tbd
            animal2 = var_s5->animal;

            if ((ABS(animal2->xPos.h - x) < (animal2->unk34 + arg0->unk34)) &&
                (ABS(animal2->zPos.h - y) < (animal2->unk34 + arg0->unk34)) &&
                ((ABS((animal2->yPos.h + (animal2->unk42 >> 1)) - (z + arg0->unk42 >> 1)) < (animal2->unk36 + arg0->unk36)))) {

                if ((arg0 != animal2->unk68) && (animal2 != arg0->unk68) && ((arg0 != animal2->unk70) || (arg0->unk16C->unk15 != 4)) && ((animal2 != arg0->unk70) || (animal2->unk16C->unk15 != 4)) && (animal2->state != 0x1E) && (arg0->state != 0x1E) && (animal2->state != 0x1F) && (arg0->state != 0x1F) && ((animal2->unk15C == 0) || (arg0 != animal2->unk168)) && ((arg0->unk15C == 0) || (animal2 != arg0->unk168)) && ((arg6 == 0) || (animal2->unk16C->objectType < 0x100))) {
                    func_802B5E48_6C74F8(animal2, arg0, &D_803D60D0, &D_803D60D4);

                    collision_func = D_803D60D0;

                    if (((D_803D60D4 != 0) && (collision_func(arg0, animal2, &D_803D60D8, &D_803D60DC, x, y, z, animal2->xPos.w, animal2->zPos.w, animal2->yPos.w) != 0)) ||
                        ((D_803D60D4 == 0) && (collision_func(animal2, arg0, &D_803D60D8, &D_803D60DC, animal2->xPos.w, animal2->zPos.w, animal2->yPos.w, x, y, z) != 0)))  {

                        if ((arg0->unk16C->unk2 == 9) || (animal2->unk16C->unk2 == 9) || (arg0->unk16C->unk2 == 8) || (animal2->unk16C->unk2 == 8)) {
                            return 0;
                        }

                        z += D_803A05B4_7B1C64;

                        if ((((D_803D60D4 != 0) && (collision_func(arg0, animal2, &D_803D60D8, &D_803D60DC, x, y, z, animal2->xPos.w, animal2->zPos.w, animal2->yPos.w) != 0))) ||
                             ((D_803D60D4 == 0) && (collision_func(animal2, arg0, &D_803D60D8, &D_803D60DC, animal2->xPos.w, animal2->zPos.w, animal2->yPos.w, x, y, z) != 0))) {
                            *arg5 = 1;
                            if ((arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (animal2->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(animal2);
                            }
                            if ((animal2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (arg0->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(arg0);
                            }
                            func_802FD674_70ED24(arg0, animal2);
                            return 1;
                        } else {
                            *arg5 = 0;
                            if ((arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (animal2->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(animal2);
                            }
                            if ((animal2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (arg0->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(arg0);
                            }
                            func_802FD674_70ED24(arg0, animal2);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B75CC_6C8C7C.s")
#endif

#if 0
// so so far away it hurts
u8 func_802B7BC8_6C9278(Animal *arg0, Animal *arg1) {
    Vertex spC4;
    Vertex spB4;
    Vertex spA8;
    Vertex sp9C;

    s32 x1;
    s32 y1;
    s32 z1;
    s32 x2;
    s32 y2;
    s32 z2; // sp84?

    u8 sp82;
    u8 sp80;

    s16 i;

    s32 var_s3;
    u8 var_v0;

    u16 temp_v0_2;
    u16 temp_v1_4;
    u8 var_a1;

    s32 *xPos1, *zPos1, *yPos1, *xPos2, *zPos2, *yPos2;

    if ((void*)D_803D60D0 == (void*)func_802B6088_6C7738) {
        if (D_803D60D4 != 0) {
            x1 = D_803D60DC->unk0.w;
            y1 = D_803D60DC->unk4.w;
            z1 = D_803D60DC->unk8.w;
            x2 = -x1;
            y2 = -y1;
            z2 = -z1;
        } else {
            x2 = D_803D60DC->unk0.w;
            y2 = D_803D60DC->unk4.w;
            z1 = D_803D60DC->unk8.w; // is this correct?
            x1 = -x2;
            y1 = -y2;
            z2 = -z1;
        }
    } else {
        spB4.x = arg0->xPos.w / 65536.0;
        spB4.y = arg0->zPos.w / 65536.0;
        spB4.z = (arg0->yPos.w + (arg0->unk42 << 0xF)) / 65536.0;

        spA8.x = arg1->xPos.w / 65536.0;
        spA8.y = arg1->zPos.w / 65536.0;
        spA8.z = (arg1->yPos.w + (arg1->unk42 << 0xF)) / 65536.0;

        vector_subtract(&spA8, &spB4, &sp9C);
        normalize_vector(&sp9C, &spC4);
        vector_multiply_by(&spC4, 2.0f, &sp9C);

        spC4.x = sp9C.x;
        spC4.y = sp9C.y;
        spC4.z = sp9C.z;

        x1 = -spC4.x * 65536.0;
        y1 = -spC4.y * 65536.0;
        z1 = -spC4.z * 65536.0;

        x2 = spC4.x * 65536.0;
        y2 = spC4.y * 65536.0;
        z2 = spC4.z * 65536.0;
    }

    if ((arg0->unk16C->unk80.unk11 != 0) || (arg0->unk4C.unk27 == 0) || (arg0->unk4A != 0) || ((x1 == 0) && (y1 == 0) && (z1 == 0))) {
        var_a1 = 0;
    } else {
        var_a1 = 1;
    }

    var_s3 = 1;

    if ((arg1->unk16C->unk80.unk11 != 0) || (arg1->unk4C.unk27 == 0) || (arg1->unk4A != 0) || ((x2 == 0) && (y2 == 0) && (z2 == 0))) {
        var_s3 = 0;
    }
    if (arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        var_s3 = 0;
    }
    if (arg1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        var_a1 = 0;
    }

    temp_v0_2 = arg0->unk44;
    temp_v1_4 = arg1->unk44;
    if ((temp_v0_2 * 3) < temp_v1_4) {
        if (var_a1 == 1) {
            var_s3 = 0;
        }
    } else if ((temp_v1_4 * 3) < temp_v0_2) {
        if (var_s3 == 1) {
            var_a1 = 0;
        }
    } else if ((temp_v0_2 * 2) < temp_v1_4) {
        x2 >>= 1;
        y2 >>= 1;
        z2 >>= 1;
    } else if ((temp_v1_4 * 2) < temp_v0_2) {
        x1 >>= 1;
        y1 >>= 1;
        z1 >>= 1;
    }


    i = 0;
    var_v0 = 1;

    while (((var_a1 != 0) || (var_s3 != 0)) && (var_v0 != 0) && (i < 16)) {
        xPos1 = &arg0->xPos.w;
        zPos1 = &arg0->zPos.w;
        yPos1 = &arg0->yPos.w;

        xPos2 = &arg1->xPos.w;
        zPos2 = &arg1->zPos.w;
        yPos2 = &arg1->yPos.w;

        if (var_a1 != 0) {
            if ((func_802B75CC_6C8C7C(arg0, arg1, x1, y1, z1, &sp80, 0) == 0) && (func_80313448_724AF8(arg0, x1, y1, z1) != 0)) {
                arg0->yPos.w = MAX(arg0->yPos.w, func_80310EE4_722594(arg0->xPos.h, arg0->zPos.h, arg0->unk160));
            } else {
                var_a1 = 0; // break
            }
        }
        if (var_s3 != 0) {
            if ((func_802B75CC_6C8C7C(arg1, arg0, x2, y2, z2, &sp80, 0) == 0) && (func_80313448_724AF8(arg1, x2, y2, z2) != 0)) {
                arg1->yPos.w = MAX(arg1->yPos.w, func_80310EE4_722594(arg1->xPos.h, arg1->zPos.h, arg1->unk160));
            } else {
                var_s3 = 0; // break
            }
        }

        if (D_803D60D4 != 0) {
           var_v0 = D_803D60D0(arg1, arg0, &D_803D60D8, &D_803D60DC, *xPos2, *zPos2, *yPos2, *xPos1, *zPos1, *yPos1);
        } else {
           var_v0 = D_803D60D0(arg0, arg1, &D_803D60D8, &D_803D60DC, *xPos1, *zPos1, *yPos1, *xPos2, *zPos2, *yPos2);
        }

        if (((void*)D_803D60D0 == (void*)func_802B6088_6C7738) && (var_v0 != 0)) {
            if (D_803D60D4 != 0) {
                x1 = D_803D60DC->unk0.w;
                y1 = D_803D60DC->unk4.w;
                z1 = D_803D60DC->unk8.w;
                x2 = -x1;
                y2 = -y1;
                z2 = -z1;
            } else {
                x2 = D_803D60DC->unk0.w;
                y2 = D_803D60DC->unk4.w;
                z1 = D_803D60DC->unk8.w;
                x1 = -x2;
                y1 = -y2;
                z2 = -z1;
            }
        }
        i++;
    }

    arg0->unk10.w = arg0->xPos.w + arg0->xVelocity.w;
    arg0->unk14.w = arg0->zPos.w + arg0->zVelocity.w;
    arg0->unk18.w = arg0->yPos.w + arg0->yVelocity.w;
    arg1->unk10.w = arg1->xPos.w + arg1->xVelocity.w;
    arg1->unk14.w = arg1->zPos.w + arg1->zVelocity.w;
    arg1->unk18.w = arg1->yPos.w + arg1->yVelocity.w;

    return (var_v0 == 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B7BC8_6C9278.s")
#endif

void func_802B8304_6C99B4(Animal *arg0, Animal *arg1) {
    f32 var_f2;
    f32 var_f14;

    f32 sp24;
    f32 sp20;
    f32 sp1C;

    f32 var_f16;
    f32 var_f12;
    s16 var_v1;

    if (arg1->unk16C->unk18 != NULL) {
        var_v1 = MAX(0x800, arg1->unk40);
        if (((arg0->yPos.h + (arg0->unk42 >> 1)) < (arg1->yPos.h + (arg1->unk42 >> 1)))) {
            var_v1 = MIN(var_v1, 0x800);
        }

        arg0->xVelocity.w -= (D_803D60DC->unk0.w * var_v1) >> 0xB;
        arg0->zVelocity.w -= (D_803D60DC->unk4.w * var_v1) >> 0xB;
        arg0->yVelocity.w -= (D_803D60DC->unk8.w * var_v1) >> 0xB;
        return;
    }

    var_f2 = (arg0->xPos.w - arg1->xPos.w) / 65536.0;
    var_f14 = (arg0->zPos.w - arg1->zPos.w) / 65536.0;

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
