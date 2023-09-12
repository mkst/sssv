#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

// used in func_80309F38_71B5E8
#pragma intrinsic sqrtf


void func_80362CC4_774374(Animal*);
void func_803633C4_774A74(Animal*);
void func_80305368_716A18(struct079 *);
void func_803071BC_71886C(void);

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

struct079 D_803E4BE0;


// ========================================================
// .text
// ========================================================

// ESA: func_80078710
void func_80305250_716900(struct079_inner *arg0, Animal *animal, s16 distance, u8 arg3) {
    s16 i;
    u8 j;

    if (distance < 0) {
        distance = 0;
    }

    if (arg0->used == 0) {
        arg0->distance[0] = distance;
        arg0->animal[0] = animal;
        arg0->used++;
    }

    for (i = 0; i < arg0->used; i++) {
        if ((animal == arg0->animal[i])) {
            return;
        }
        if ((distance < arg0->distance[i])) {
            break;
        }
    }

    if (i < arg3) {
        if (i == arg0->used) {
            // append new stuff
            arg0->distance[i] = distance;
            arg0->animal[i] = animal;
            arg0->used++;
        } else {
            // move everything and insert stuff
            j = i;
            while (i < (arg3 - 1)) {
                arg0->animal[i+1] = arg0->animal[i];
                arg0->distance[i+1] = arg0->distance[i];
                i++;
            }
            arg0->animal[j] = animal;
            arg0->distance[j] = distance;

            if (arg0->used < arg3) {
                arg0->used++;
            }
        }
    }
}

// ESA: func_80078890
void func_80305368_716A18(struct079 *arg0) {

    s16 start_2;
    s16 end_2;      // sp84
    s16 start_1;
    s16 end_1;
    s32 pad2;
    s16 k;          // sp7A
    s16 j;          // sp78
    u16 idx;
    s32 dist;
    Animal *animal;
    struct065 *var_s5;
    u8 ai_behavior;
    s16 i;
    s16 x_pos;
    s16 z_pos;
    struct035 *temp_v1_4;
    s16 pad1;
    s16 max_height; // sp58
    s16 min_height; // sp56


    if ((D_803D5524->class == 0x40) || (D_803D5524->waterClass & WATER_SWIM)) {
        max_height = D_803D5530->yPos.h + 0x190;
        min_height = D_803D5530->yPos.h - 0x1F4;
    } else {
        max_height = D_803D5530->yPos.h + 0xC8;
        min_height = D_803D5530->yPos.h - 0xC8;
    }

    x_pos = D_803D5530->xPos.h;
    z_pos = D_803D5530->zPos.h;

    start_2 = (s16)(x_pos >> 6) - 1;
    end_2   = (s16)(x_pos >> 6) + 1;

    start_1 = (s16)(z_pos >> 6) - 1;
    end_1 = (s16)(z_pos >> 6) + 1;

    // check within bounds
    if (start_2 < 0) {
        start_2 = 0;
    } else if (end_2 > 72) {
        end_2 = 72;
    }
    if (start_1 < 0) {
        start_1 = 0;
    } else if (end_1 > 128) {
        end_1 = 128;
    }

    start_2 = start_2 >> 4; // start 2
    end_2 = end_2 >> 4;     // end 2

    start_1 = start_1 >> 4; // start 1
    end_1 = end_1 >> 4;     // end 1

    for (i = 0; i < 3; i++) {
        arg0->unk0.distance[i] = arg0->unk1C.distance[i] = arg0->unk38.distance[i] = MAX_INT;
    }

    arg0->unk0.used = arg0->unk1C.used = arg0->unk38.used = 0;
    arg0->unk54 = arg0->unk5C = MAX_INT;
    arg0->unk60 = arg0->unk58 = NULL;

    for (j = start_1; j <= end_1; j++) {
        for (k = start_2; k <= end_2; k++) {
            idx = (k + (j * 5));
            for (var_s5 = D_803DA110[idx].next; var_s5 != NULL; var_s5 = var_s5->next) {
                animal = var_s5->animal;
                temp_v1_4 = animal->unk16C;

                if (temp_v1_4->objectType < OB_TYPE_ANIMAL_OFFSET) {
                    // it's an object
                    if ((temp_v1_4->unk82.unk1 == 0) && (temp_v1_4->objectType != OBJECT_TELEPORTER_BASE) && (temp_v1_4->objectType != OBJECT_TELEPORTER_ACTIVE_NO_TRIGGER) && (temp_v1_4->objectType != OBJECT_TELEPORTER_ACTIVE)) {
                        if ((temp_v1_4->unk2 != 1) && (temp_v1_4->unk2 != 9) && (temp_v1_4->unk15 != 2) && (animal != D_803D552C->unk2AC) && (animal != D_803D552C->unk320)) {
                            dist = ABS(animal->xPos.h - x_pos) + ABS(animal->zPos.h - z_pos);
                            dist = dist - D_803D5524->unkBE;
                            if (temp_v1_4->unk2 == 2) {
                                if ((D_803D5524->unk9C == RAT) || (D_803D5524->unk9C == POLAR_BEAR) || (D_803D5524->unk9C == HIPPO) || (D_803D5524->unk9C == KING_RAT) || (D_803D5524->unk9C == POLAR_TANK)) {
                                    if (animal->unk15C < 25) {
                                        dist = dist - (animal->unk30 + 100);
                                        func_80305250_716900(&arg0->unk38, animal, dist, 2);
                                    }
                                } else {
                                    dist = dist - (animal->unk30 + 100);
                                    func_80305250_716900(&arg0->unk1C, animal, dist, 2);
                                }
                            } else {
                                func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            }
                        }
                    }
                } else if ((animal != D_803D5530) && (temp_v1_4->objectType != OB_TYPE_ANIMAL_OFFSET+EVO_TRANSFER)) {
                    // its an animal
                    if ((animal->yPos.h < max_height) && (min_height < animal->yPos.h)) {
                        if ((func_80362B00_7741B0(animal) != 0) || ((can_swim(D_803D5530) != 0) && (func_80362B60_774210(animal) == 0))) {
                            ai_behavior = 0;
                        } else {
                            ai_behavior = func_802EA3E0_6FBA90(D_803D5530->unk16C->objectType, animal->unk16C->objectType);
                        }

                        dist = ABS(animal->xPos.h - x_pos) + ABS(animal->zPos.h - z_pos);
                        dist = dist - (D_803D5524->unkBE);
                        dist = dist - animal->unk16C->unkBE;
                        if (dist < 0) {
                            dist = 0;
                        }

                        switch (ai_behavior) {
                        case AI_IGNORE: // 0
                            func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            break;
                        case AI_FLEE: // 1
                            if (D_803D552C->unk272 & 4) {
                                func_80305250_716900(&arg0->unk1C, animal, dist, 2);
                            }
                            func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            break;
                        case AI_ATTACK: // 2
                            if (D_803D552C->unk272 & 1) {
                                if (dist < arg0->unk54) {
                                    arg0->unk54 = dist;
                                    arg0->unk58 = animal;
                                }
                            } else {
                                func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            }
                            break;
                        case AI_SAME_ANIMAL: // 3
                            func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            break;
                        case AI_HERD: // 4
                            if (D_803D552C->unk272 & 8) {
                                func_80305250_716900(&arg0->unk0, animal, dist, 2);
                            } else {
                                func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            }
                            break;
                        case AI_LEAD_HERD: // 5
                            if (D_803D552C->unk272 & 8) {
                                if (dist < arg0->unk5C) {
                                    arg0->unk5C = dist;
                                    arg0->unk60 = animal;
                                    arg0->unk64 = 0; // isFollowing?
                                }
                            } else {
                                func_80305250_716900(&arg0->unk38, animal, dist, 2);
                            }
                            break;
                        case AI_FOLLOWER: // 6
                            if (dist < arg0->unk5C) {
                                arg0->unk5C = dist;
                                arg0->unk60 = animal;
                                arg0->unk64 = 1; // isFollowing?
                            }
                            break;
                        case AI_LEADER: // 7
                            break;
                        case AI_INVISIBLE: // 8
                            break;
                        }
                    }
                }
            }
        }
    }
}

// ESA: func_80305A70_717120
s32 func_80305A70_717120(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u8 arg4) {
    u8 sp4F;
    u8 sp4E;

    s16 var_v1;
    s32 sp30;
    s16 tmp2;
    s16 tmp1;
    u8 sp43;

    s32 temp_t8;
    s32 sp20;
    s32 sp1C;

    switch (arg4) {
    case 0:
        sp4F = 3;
        sp4E = 1;
        break;
    case 1:
        sp4F = 2;
        sp4E = 1;
        break;
    case 2:
        sp4F = 2;
        sp4E = 0;
        break;
    case 3:
        sp4F = 3;
        sp4E = 0;
        break;
    }

    tmp1 = D_803A5560_7B6C10[arg4] * arg3;
    tmp2 = D_803A5568_7B6C18[arg4] * arg3;

    sp20 = arg0 + tmp1;
    sp1C = arg1 + tmp2;

    if (D_803C0740[sp20 >> 6][sp1C >> 6].unk3 != 0) {
        temp_t8 = (arg2 - func_80310F58_722608(sp20, sp1C)) >> 0x10;

        if (ABS(temp_t8) < 49) {
            if ((D_803D552C->unk272 & 0x20) &&
                (D_803C0740[sp20 >> 6][sp1C >> 6].unk5 & (0x10 << (sp4F ^ 1))) &&
                (D_803C0740[sp20 >> 6][sp1C >> 6].unk5 & (0x10 << (sp4E ^ 1)))) {
                sp43 = 1;
            } else {
                sp43 = 0;
            }
        } else if ((D_803D552C->unk272 & 0x20) &&
                   (D_803C0740[sp20 >> 6][sp1C >> 6].unk5 & (1 << (sp4F ^ 1))) &&
                   (D_803C0740[sp20 >> 6][sp1C >> 6].unk5 & (1 << (sp4E ^ 1))) &&
                   (ABS(temp_t8) <= ((D_803E1D30[(D_803C0740[sp20 >> 6][sp1C >> 6].unk3)].unk2) * 8))) {
            sp43 = 1;
        } else {
            temp_t8 = (func_8031124C_7228FC(sp20, sp1C) - func_8031124C_7228FC(arg0, arg1)) >> 0x10;
            if (ABS(temp_t8) < 97) {
                sp43 = 0;
            } else if ((D_803D552C->unk272 & 0x20) && (temp_t8 < 0)) {
                sp43 = 1;
            }
      }
    } else {
        temp_t8 = (arg2 - func_8031124C_7228FC(sp20, sp1C)) >> 0x10;
        if (ABS(temp_t8) < 97) {
            sp43 = 0;
        } else {
            sp43 = 1;
        }
    }
    return sp43;
}

// plenty of work still to do here
#if 0
// ESA: func_80305DA4_717454
s32 func_80305DA4_717454(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u8 arg4) {
    Animal *sp50;
    s32 sp4C;

    s32 sp28;
    s32 sp24;
    s16 temp_t0;

    s32 temp_t6;
    s32 temp_t6_2;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 var_a1_2;
    s32 var_a1_3;
    u16 temp_a0;

    Animal *animal;
    struct065 *var_a1_4;

    sp28 = arg0 + (D_803A5570_7B6C20[arg4] * arg3);
    sp24 = arg1 + (D_803A5578_7B6C28[arg4] * arg3);

    temp_t0 = GET_WATER_LEVEL(D_803C0740, sp28, sp24) * 4;

    if ((D_803D5524->waterClass & WATER_SWIM) && (temp_t0 <= 0)) {
        return 1;
    }

    if (D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk3 != 0) {

        var_a1_2 = func_80310F58_722608(sp28, sp24);
        if ((D_803D5524->waterClass & (WATER_SWIM|WATER_FLOAT))) {
            temp_t7 = temp_t0 << 0x10;
            if (var_a1_2 < temp_t7) {
                var_a1_2 = temp_t7;
                if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
                    return 1;
                }
            }
        }

        temp_t8 = (arg2 - var_a1_2) >> 0x10;
        if (ABS(temp_t8) < 0x31) {
            if (((D_803D552C->unk272 & 0x20) != 0) && ((D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk5 & (0x10 << (arg4 ^ 1))) != 0)) {
                return 1;
            }
            return 0;
        }
        if ((D_803D552C->unk272 & 0x20) && ((D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk5 & (1 << (arg4 ^ 1))) != 0)) {
            if ((D_803E1D30[D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk3].unk2 * 8) >= ABS(temp_t8)) {
                return 1;
            }
        }
        if ((D_803D5524->waterClass & (WATER_SWIM|WATER_FLOAT)) &&
            (func_8031124C_7228FC(sp28, sp24) < (temp_t0 << 0x10)) &&
            (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2))) {
            return 1;
        }

        sp4C = func_8031124C_7228FC(sp28, sp24);
        temp_t9 = (sp4C - func_8031124C_7228FC(arg0, arg1)) >> 0x10;
        if (ABS(temp_t9) < 97) {
            return 0;
        }
        if ((D_803D552C->unk272 & 0x20) && (temp_t9 < 0)) {
            return 1;
        }
        goto block_60;
    }

    var_a1_3 = func_8031124C_7228FC(sp28, sp24);
    if (D_803D5524->waterClass & WATER_SWIM) {
        if (var_a1_3 >= arg2) {
            return 1;
        }
        return 0;
    }
    temp_t6_2 = temp_t0 << 0x10;
    if (((D_803D5524->waterClass & (WATER_SWIM|WATER_FLOAT)) != 0) && (var_a1_3 < temp_t6_2)) {
        var_a1_3 = temp_t6_2;
        if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
            return 1;
        }
    }

    temp_t9_2 = (s32) (arg2 - var_a1_3) >> 0x10;
    if (ABS(temp_t9_2) < 97) {
        return 0;
    }
    if (temp_t9_2 < 0) {
        return 1; // goto block_99;
    }

block_60:
    if (((D_803D552C->unk272 & 0x10) == 0) && ((D_803D5524->waterClass & WATER_SWIM) == 0)) {
        return 0;
    }

    for (var_a1_4 = D_803DA110[(s16) ((arg0 >> 0xA) + ((arg1 >> 0xA) * 5))].next; var_a1_4 != NULL; var_a1_4 = var_a1_4->next) {
        animal = var_a1_4->animal;
        if ((animal->unk16C->unk82.unk1) && (animal != sp50) && (animal->xVelocity.h == 0) && (animal->zVelocity.h == 0) && (animal->yVelocity.h == 0)) {

            if (ABS((animal->yPos.w + (animal->unk42 << 0x10)) - arg2) <= FTOFIX32(16.0)) {
                switch (arg4) {
                case 0:
                    if ((ABS(animal->zPos.h - arg1) < (animal->unk32 >> 1)) &&
                        ((arg0 - (arg3 >> 1)) < (animal->xPos.h + animal->unk30 + 2))) {
                        return 0;
                    }
                    break;
                case 1:
                    if ((ABS(animal->zPos.h - arg1) < (animal->unk32 >> 1)) &&
                        ((arg0 + (arg3 >> 1)) > ((animal->xPos.h - animal->unk30) - 2))) {
                        return 0;
                    }
                    break;
                case 2:
                    if ((ABS(animal->xPos.h - arg0) < (animal->unk30 >> 1)) &&
                        ((arg1 - (arg3 >> 1)) < (animal->zPos.h + animal->unk32 + 2))) {
                        return 0;
                    }
                    break;
                case 3:
                    if ((ABS(animal->xPos.h - arg0) < (animal->unk30 >> 1)) &&
                        ((arg1 + (arg3 >> 1)) > ((animal->zPos.h - animal->unk32) - 2))) {
                        return 0;
                    }
                    break;
                }
            }
        }
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305DA4_717454.s")
#endif

// ESA: func_80079984
s16 func_803064BC_717B6C(s16 arg0, s16 arg1, s32 arg2, s16 arg3, s16 arg4) {
    u8 i;
    s16 phi_s1;
    s16 res;
    Animal *temp_v0;

    temp_v0 = D_803D5530->unk6C;
    if ((temp_v0 != NULL) && (temp_v0->unk16C->unk82.unk1) && ((temp_v0->xVelocity.w | temp_v0->zVelocity.w | (temp_v0->yVelocity.w != 0)) != 0)) {
        return 0xF;
    }

    res = 0;
    i = 0;

    phi_s1 = 1;
    while (i < 4) {
        if (func_80305DA4_717454(arg0, arg1, arg2, arg4, i)) {
            res |= phi_s1;
        }
        i++; phi_s1 = phi_s1 << 1; // required for instruction order
    }

    return res;
}

// ESA: func_80079A84
s16 func_803065F0_717CA0(s16 arg0, s16 arg1, s32 arg2, s16 arg3, s16 arg4) {

    if ((arg3 != 0x40) || ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk16C->unk82.unk1))) { //  & 0x4000
        return 0;
    }

    switch (arg4) {
    case 0:
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 3) == 0) && (func_80305A70_717120(arg0, arg1, arg2, arg3, 1) != 0) && (func_80305DA4_717454(arg0 - arg3, arg1, arg2, arg3, 0) != 0) && (func_80305DA4_717454(arg0, arg1 + arg3, arg2, arg3, 3) != 0)) {
            return 6;
        }
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 0) == 0) && (func_80305A70_717120(arg0, arg1, arg2, arg3, 2) != 0) && (func_80305DA4_717454(arg0 + arg3, arg1, arg2, arg3, 1) != 0) && (func_80305DA4_717454(arg0, arg1 + arg3, arg2, arg3, 3) != 0)) {
            return 5;
        }
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 1) == 0) && (func_80305A70_717120(arg0, arg1, arg2, arg3, 3) != 0) && (func_80305DA4_717454(arg0 + arg3, arg1, arg2, arg3, 1) != 0) && (func_80305DA4_717454(arg0, arg1 - arg3, arg2, arg3, 2) != 0)) {
            return 9;
        }
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 2) == 0) && (func_80305A70_717120(arg0, arg1, arg2, arg3, 0) != 0) && (func_80305DA4_717454(arg0 - arg3, arg1, arg2, arg3, 0) != 0) && (func_80305DA4_717454(arg0, arg1 - arg3, arg2, arg3, 2) != 0)) {
            return 0xA;
        }
        return 0; // !!
        break;
    case 1:
        if (func_80305DA4_717454(arg0 + arg3, arg1, arg2, arg3, 1) != 0) {
            return 1;
        }
        else if ((func_80305DA4_717454(arg0, (s16) (arg1 + arg3), arg2, arg3, 3) != 0) && (func_80305A70_717120(arg0 + arg3, arg1, arg2, arg3, 1) != 0)) {
            return 5;
        }
        else if ((func_80305DA4_717454(arg0, (s16) (arg1 - arg3), arg2, arg3, 2) != 0) && (func_80305A70_717120(arg0 + arg3, arg1, arg2, arg3, 0) != 0)) {
            return 9;
        }
        break;
    case 2:
        if (func_80305DA4_717454(arg0 - arg3, arg1, arg2, arg3, 0) != 0) {
            return 2;
        }
        if ((func_80305DA4_717454(arg0, (s16) (arg1 + arg3), arg2, arg3, 3) != 0) && (func_80305A70_717120(arg0 - arg3, arg1, arg2, arg3, 2) != 0)) {
            return 6;
        }
        if ((func_80305DA4_717454(arg0, (s16) (arg1 - arg3), arg2, arg3, 2) != 0) && (func_80305A70_717120(arg0 - arg3, arg1, arg2, arg3, 3) != 0)) {
            return 0xA;
        }
        break;
    case 3:
        return 0;
        break;
    case 4:
        if (func_80305DA4_717454(arg0, arg1 + arg3, arg2, arg3, 3) != 0) {
            return 4;
        }
        if ((func_80305DA4_717454(arg0 - arg3, arg1, arg2, arg3, 0) != 0) && (func_80305A70_717120(arg0, arg1 + arg3, arg2, arg3, 0) != 0)) {
            return 6;
        }
        if ((func_80305DA4_717454(arg0 + arg3, arg1, arg2, arg3, 1) != 0) && (func_80305A70_717120(arg0, arg1 + arg3, arg2, arg3, 3) != 0)) {
            return 5;
        }
        break;
    case 5:
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 0) == 0) && (((func_80305DA4_717454(arg0 + arg3, arg1 + arg3, arg2, arg3, 1) != 0)) || (func_80305DA4_717454(arg0 + arg3, arg1 + arg3, arg2, arg3, 3) != 0))) {
            return 5;
        }
        break;
    case 6:
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 3) != 0) || (((func_80305DA4_717454(arg0 - arg3, arg1 + arg3, arg2, arg3, 0) == 0)) && (func_80305DA4_717454(arg0 - arg3, arg1 + arg3, arg2, arg3, 3) == 0))) {
            // fallthrough to case 7?
        } else {
            break;
        }
    case 7:
        return 0;
        break;
    case 8:
        if (func_80305DA4_717454(arg0, arg1 - arg3, arg2, arg3, 2) != 0) {
            return 8;
        }
        if ((func_80305DA4_717454(arg0 - arg3, arg1, arg2, arg3, 0) != 0) && (func_80305A70_717120(arg0, arg1 - arg3, arg2, arg3, 1) != 0)) {
            return 0xA;
        }
        if ((func_80305DA4_717454(arg0 + arg3, arg1, arg2, arg3, 1) != 0) && (func_80305A70_717120(arg0, arg1 - arg3, arg2, arg3, 2) != 0)) {
            return 9;
        }
        break;
    case 9:
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 1) != 0) || (((func_80305DA4_717454(arg0 + arg3, arg1 - arg3, arg2, arg3, 1) == 0)) && (func_80305DA4_717454(arg0 + arg3, arg1 - arg3, arg2, arg3, 2) == 0))) {
            // fallthrough to case 10
        } else {
            break; // break also works
        }
    case 10:
    // fallthrough
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 2) != 0) || (((func_80305DA4_717454(arg0 - arg3, arg1 - arg3, arg2, arg3, 0) == 0)) && (func_80305DA4_717454(arg0 - arg3, arg1 - arg3, arg2, arg3, 2) == 0))) {
            // else fallthrough
        } else {
            break;
        }
    case 11:
        return 0;
    case 12:
        return 0;
    case 13:
        return 0;
    case 14:
        return 0;
    case 15:
        return 0;
    }

    return 0;
}


#if 0
// ESA: func_8007A280
// CURRENT (96635)
void func_803071BC_71886C(void) {
    struct039 spBC;
    struct039 spB4;
    s16 yOffset; // sp9A

    s16 sp8A; // uninitialised?
    s16 sp88; // uninitialised?
    s16 sp86;
    s16 sp84;

    Animal *temp_v0_14;

    s16 xPos;
    s16 zPos;
    s16 temp_t5;
    s16 temp_v0_17;
    s16 temp_v0_7;
    s16 var_a0;
    s16 posDiff;
    s16 var_a0_4;
    s16 i;
    s16 yRotation;
    s16 var_s0;
    s16 var_s1;
    s16 var_s2;
    s16 var_s5;
    s16 yRotation2;
    s16 var_t4_3;
    s16 zPosDiff;
    s16 yPosDiff;
    s16 var_v0_5;
    s32 temp_a0_7;
    s32 temp_a0_9;
    s32 temp_lo_3;
    s32 temp_t6_2;
    s32 temp_t7;
    s32 temp_t8_2;
    s32 temp_t8_3;
    s32 temp_t9;
    s32 temp_v0_11;
    s32 temp_v0_15;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a2;
    s32 var_t1;
    s32 var_t2;

    u8 defaultYRotation;
    s32 var_v1_2;
    u8 var_v1_3;

    xPos = D_803D5530->xPos.h;
    zPos = D_803D5530->zPos.h;

    var_t1 = 0;
    var_t2 = 0;

    if (D_803D5524->waterClass & WATER_SWIM) {
        var_s5 = 10;
        var_v1_2 = MAX(MAX(D_803C0740[(xPos >> 6) + 0][(zPos >> 6) + 0].unk6,
                           D_803C0740[(xPos >> 6) + 1][(zPos >> 6) + 0].unk6),
                       MAX(D_803C0740[(xPos >> 6) + 0][(zPos >> 6) + 1].unk6,
                           D_803C0740[(xPos >> 6) + 1][(zPos >> 6) + 1].unk6));

        yOffset = (((func_80310EE4_722594(xPos, zPos, D_803D5530->unk160) >> 0x10) + (var_v1_2 * 4)) >> 1);
    } else if (D_803D5524->class & CLASS_FLYING) {
        var_s5 = 10;
        yOffset = -200;
    } else {
        var_s5 = -1;
        yOffset = 0;
    }

    switch (D_803D552C->unk274) {
    case 0:
        break;
    case 1:
        spBC.unk0 = D_80152350.unk2D0[D_803D552C->unk276];
        spBC.unk4 = D_80152350.unk384[D_803D552C->unk276];

        yOffset = D_803D552C->unk27C;

        if (var_s5 < D_803D552C->unk275) {
            var_s5 = D_803D552C->unk275;
        }

        func_80304EC4_716574(&spBC, &spB4);
        var_t2 = (spB4.unk0 << 7) >> 8;
        var_t1 = (spB4.unk4 << 7) >> 8;
        break;
    case 2:
        yOffset = D_803D552C->unk27C;
        spBC.unk0 = D_803D552C->unk278 - xPos;
        spBC.unk4 = D_803D552C->unk27A - zPos;

        if (var_s5 < D_803D552C->unk275) {
            var_s5 = D_803D552C->unk275;
        }
        if ((D_803D5524->class == CLASS_POGO) && (var_s5 > 8)) {
            if (calculate_hypotenuse(&spBC) < 0x100) {
                var_s5 = 8;
            }
        }

        func_80304EC4_716574(&spBC, &spB4);
        var_t2 = (spB4.unk0 << 7) >> 8;
        var_t1 = (spB4.unk4 << 7) >> 8;
        break;
    case 3:
        yOffset = D_803D552C->unk27C;
        spBC.unk0 = -(D_803D552C->unk278 - xPos);
        spBC.unk4 = -(D_803D552C->unk27A - zPos);

        if (var_s5 < D_803D552C->unk275) {
            var_s5 = D_803D552C->unk275;
        }

        func_80304EC4_716574(&spBC, &spB4);
        var_t2 = (spB4.unk0 << 7) >> 8;
        var_t1 = (spB4.unk4 << 7) >> 8;
        break;
    }

    if ((D_803D552C->unk2A0 != 3) && ((D_803D552C->unk2A0 != 5) || (D_803D552C->unk2A1 != -1))) {
        if ((D_803E4BE0.unk5C < 0x280) && (D_803D552C->unk272 & 8)) {
            if (D_803D552C->unk2CC != D_803E4BE0.unk60) {
                spBC.unk0 = D_803E4BE0.unk60->xPos.h - xPos;
                spBC.unk4 = D_803E4BE0.unk60->zPos.h - zPos;
                if (D_803E4BE0.unk5C < 0xC) {
                    func_80304EC4_716574(&spBC, &spB4);
                    var_t2 = var_t2 - (spB4.unk0 * 0xC0) >> 8;
                    var_t1 = var_t1 - (spB4.unk4 * 0xC0) >> 8;

                    if (var_s5 < (((12 - D_803E4BE0.unk5C) << 4) / 12)) {
                        var_s5 = (((12 - D_803E4BE0.unk5C) << 4) / 12);
                    }
                } else if ((D_803D552C->unk274 == 0) && (D_803E4BE0.unk5C >= 0x4D)) {
                    func_80304EC4_716574(&spBC, &spB4);
                    var_t2 = var_t2 + (spB4.unk0 * 0xA0) >> 8;
                    var_t1 = var_t1 + (spB4.unk4 * 0xA0) >> 8;

                    temp_v0_7 = ((s32) ((D_803E4BE0.unk5C - 0x4C) * 6) / 141) + 0xE;
                    var_a0 = temp_v0_7;
                    if (temp_v0_7 > 0x14) {
                        var_a0 = 0x14;
                    }

                    if (var_s5 < var_a0) {
                        var_s5 = var_a0;
                    }
                }
            }
        }
    }

    if ((D_803D552C->unk2A0 != 3) && ((D_803D552C->unk2A0 != 5) || (D_803D552C->unk2A1 != -1))) {
        if ((D_803E4BE0.unk0.used != 0) && (D_803D552C->unk272 & 8)) {
            for (i = 0; i < D_803E4BE0.unk0.used; i++) {
                temp_v0_14 = D_803E4BE0.unk0.animal[i];
                if (temp_v0_14 == D_803D552C->unk2CC) {

                } else {
                    temp_v1_2 = D_803E4BE0.unk0.distance[i];
                    spBC.unk0 = temp_v0_14->xPos.h - xPos;
                    spBC.unk4 = temp_v0_14->zPos.h - zPos;
                    if (temp_v1_2 < 0x140) {
                        if (temp_v1_2 < 0x40) {
                            func_80304EC4_716574(&spBC, &spB4);
                            temp_v0_11 = 0xC0 - ((temp_v1_2 * 0xC0) / 64);
                            var_t2 -= (temp_v0_11 * spB4.unk0) >> 8;
                            var_t1 -= (temp_v0_11 * spB4.unk4) >> 8;
                            temp_t8_2 = (s32) ((temp_v1_2 * -10) + 0x280) / 64;
                            if (var_s5 < (s16) temp_t8_2) {
                                var_s5 = (s16) temp_t8_2;
                            }
                        } else if ((D_803D552C->unk274 == 0) && (temp_v1_2 > 0x80)) {
                            if (temp_v1_2 > 0x100) {
                                var_a2 = (s32) (0x5000 - (temp_v1_2 << 6)) / 64;
                            } else {
                                var_a2 = 0x40;
                            }

                            func_80304EC4_716574(&spBC, &spB4);
                            var_t2 += (var_a2 * spB4.unk0) >> 8;
                            var_t1 += (var_a2 * spB4.unk4) >> 8;
                            var_a0 = ((temp_v1_2 * 0x10) - 0x800) / 96;
                            if (var_a0 > 16) {
                                var_a0 = 0x10;
                            }
                            if (var_s5 < var_a0) {
                                var_s5 = var_a0;
                            }
                        }
                    }
                }
            }
        }
    }
    D_803D552C->unk28A = 0;
    if (D_803D552C->unk272 & 4) {
        for (i = 0; i < D_803E4BE0.unk1C.used; i++) {
            temp_v0_14 = D_803E4BE0.unk1C.animal[i];
            if (temp_v0_14 != D_803D552C->unk2CC) {
                temp_v1_3 = D_803E4BE0.unk1C.distance[i];
                spBC.unk0 = temp_v0_14->xPos.h - xPos;
                spBC.unk4 = temp_v0_14->zPos.h - zPos;
                if (temp_v1_3 < 0x180) {
                    D_803D552C->unk28A = 1;
                    func_80304EC4_716574(&spBC, &spB4);
                    temp_lo_3 = (s32) ((0x180 - temp_v1_3) * 0x180) / 384;
                    var_t2 -= (temp_lo_3 * spB4.unk0) >> 8;
                    var_t1 -= (temp_lo_3 * spB4.unk4) >> 8;
                    if (var_s5 < 0x10) {
                        var_s5 = 0x10;
                    }
                }
            }
        }
    }

    if ((D_803D552C->unk2A0 != 3) && ((D_803D552C->unk2A0 != 5) || (D_803D552C->unk2A1 != -1)) && (D_803D552C->unk272 & 2)) {
        for (i = 0; i < D_803E4BE0.unk38.used; i++) {
            temp_v0_14 = D_803E4BE0.unk38.animal[i];
            if ((temp_v0_14 == D_803D552C->unk2CC) || (temp_v0_14 == D_803D552C->unk2AC)) {
                // debug? or just weird logic
            } else {
                temp_v1_4 = D_803E4BE0.unk38.distance[i];
                spBC.unk0 = temp_v0_14->xPos.h - xPos;
                spBC.unk4 = temp_v0_14->zPos.h - zPos;
                if (temp_v1_4 < 0x80) {
                    func_80304EC4_716574(&spBC, &spB4);
                    temp_v0_15 = 0xC0 - ((s32) (temp_v1_4 * 0xC0) / 128);
                    var_t2 = var_t2 - ((s32) (temp_v0_15 * spB4.unk0) >> 8);
                    var_t1 = var_t1 - ((s32) (temp_v0_15 * spB4.unk4) >> 8);
                    temp_t7 = (s32) ((temp_v1_4 * -0xA) + 0x500) / 128;
                    if (var_s5 < temp_t7) {
                        var_s5 = temp_t7;
                    }
                }
            }
        }
    }

    if ((D_803D5524->class != CLASS_FLYING) && (D_803D5524->class != CLASS_BIRD) && (D_803D5524->class != CLASS_HELI) && (D_803D552C->unk272 & 0x30)) {
        if ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk16C->unk82.unk1)) { //  & 0x4000
            temp_t5 = D_803D5530->unk6C->unk30 * 2;
            sp86 = temp_t5;
            sp84 = temp_t5 - 1;
            var_t4_3 = ((temp_t5 * 5) >> 6);
            var_s1 = D_803D5530->unk6C->xPos.h;
            var_s0 = D_803D5530->unk6C->zPos.h;
        } else {
            sp86 = 0x40;
            sp84 = 0x3F;
            var_t4_3 = 5;
            var_s1 = (xPos & 0xFFC0) + 0x20;
            var_s0 = (zPos & 0xFFC0) + 0x20;
        }

        var_v1_3 = func_803064BC_717B6C(var_s1, var_s0, D_803D5530->yPos.w, D_803D5530->unk160, sp86); // & 0xFF;

        if ((D_803D5530->unk6C == NULL) || ((D_803D5530->unk6C->unk16C->unk82.unk2))) { //  << 0x11 >= 0
            temp_v0_17 = func_803065F0_717CA0(var_s1, var_s0, D_803D5530->yPos.w, sp86, var_v1_3);
            if (temp_v0_17 != 0) {
                sp86 = 0x48;
                sp84 = 0x47;
                var_s1 = xPos & ~0x3F;
                var_s0 = zPos & ~0x3F;
                if (temp_v0_17 & 4) {
                    var_s0 += 64;
                }
                if (temp_v0_17 & 1) {
                    var_s1 += 64;
                }
                var_t4_3 = 0xA;
                var_v1_3 = func_803064BC_717B6C(var_s1, var_s0, D_803D5530->yPos.w, D_803D5530->unk160, (s16) 0x48) ;
            }
        }
    } else {
        var_v1_3 = 0;
        var_s1 = sp8A; // ???
        var_s0 = sp88; // ???
    }

    if ((var_t2 | var_t1) == 0) {
        yRotation2 = D_803D5530->yRotation;
    } else {
        yRotation2 = (func_801284B8(var_t2, var_t1) << 8) / 360;
    }
    var_s2 = -1;

    switch (var_v1_3) {
    case 0:
        break;
    case 1:
        if ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 0) != 0) || ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 1) != 0))) {
            if ((yRotation2 >= 0x60) || (yRotation2 < 0x21)) {
block_147:
                // var_a2_2 = D_803D5530->yRotation;
                if ((yRotation2 < 0x40) || (yRotation2 >= 0xC0)) {
                    if (xPos < (var_s1 - var_t4_3)) {
                        var_s2 = 0x408;
                    } else if ((var_s1 + var_t4_3) < xPos) {
                        var_s2 = 0x4C8;
                    } else {
                        var_s2 = 0;
                    }
                } else if (xPos < (var_s1 - var_t4_3)) {
                    var_s2 = 0x448;
                } else if ((var_s1 + var_t4_3) < xPos) {
                    var_s2 = 0x488;
                } else {
                    var_s2 = 0x80;
                }
            } else {
            case 13:
                if (yRotation2 >= 0x80) {
                    if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                            var_s5 = -1;
                    } else {
                        var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                    }
                } else {
                    var_s2 = ((s32) (func_801284B8((var_s1 + (sp86 >> 1)) - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                }
            }
        } else {
            if ((var_s1 < xPos) || (yRotation2 < 0x80)) {
                yRotation2 = (func_801284B8(var_t2 + 0x280, var_t1) << 8) / 360;
                if (var_s5 < 0xA) {
                    var_s5 = 0xA;
                }
            } else {
                var_s2 = 0x428;
            }
        }
        break;
    case 2:
        if ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 3) != 0) || ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 2) != 0))) {
            if ((yRotation2 < 0xA0) || (yRotation2 >= 0xE0)) {
                goto block_147;
            }
        case 14:
            if (yRotation2 < 0x80) {
                if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                    var_s5 = -1;
                } else {
                    var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                }
            } else {
                var_s2 = ((s32) (func_801284B8((var_s1 - (sp86 >> 1)) - xPos, var_s0 - zPos) << 8) / 360) + 1000;
            }
        } else {
            if ((xPos < var_s1) || (yRotation2 >= 0x80)) {
                yRotation2 = (s16) ((s32) (func_801284B8(var_t2 - 0x280, (s16) var_t1) << 8) / 360);
                if (var_s5 < 0xA) {
                    var_s5 = 0xA;
                }
            } else {
                var_s2 = 0x4A8;
            }
        }
        break;
    case 3:
        goto block_147;
    case 4:
        // sp82 = var_t4_3;
        // sp8E = yRotation2;
        // spAC = var_t2;
        // spB0 = var_t1;
        if ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 3) != 0) || ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 0) != 0))) {
            if ((yRotation2 >= 0x20) && (yRotation2 < 0xE0)) {
block_354:
                // var_a2_2 = D_803D5530->yRotation;
                if (yRotation2 < 0x80) {
                    if (zPos < (var_s0 - var_t4_3)) {
                        var_s2 = 0x408;
                    } else if ((var_s0 + var_t4_3) < zPos) {
                        var_s2 = 0x448;
                    } else {
                        var_s2 = 0x40;
                    }
                } else if (zPos < (var_s0 - var_t4_3)) {
                    var_s2 = 0x4C8;
                } else if ((var_s0 + var_t4_3) < zPos) {
                    var_s2 = 0x488;
                } else {
                    var_s2 = 0xC0;
                }
            } else {
            case 7:
                if ((yRotation2 >= 0x40) && (((yRotation2 < 0xC0) != 0))) {
                    if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                        var_s5 = -1;
                    } else {
                        var_s2 = ((func_801284B8(var_s1 - xPos, (var_s0 - zPos)) << 8) / 360) + 1000;
                    }
                } else {
                    var_s2 = ((func_801284B8(var_s1 - xPos, ((var_s0 + (sp86 >> 1)) - zPos)) << 8) / 360) + 1000;
                }
            }
        } else {
            if ((var_s0 < zPos) || (yRotation2 < 0x40) || (yRotation2 >= 0xC0)) {
                yRotation2 = (func_801284B8(var_t2, (var_t1 + 0x280)) << 8) / 360;
                if (var_s5 < 0xA) {
                    var_s5 = 0xA;
                }
            } else {
                var_s2 = 1000;
            }
        }
        break;
    case 5:
        if (func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 0) != 0) {
            if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                if ((yRotation2 < 0x20) || (yRotation2 >= 0xA0)) {
                    var_s2 = 0;
                } else {
                    var_s2 = 0x40;
                }
            } else {
                temp_t5 = sp86 >> 1;
                if (((((((sp84 - xPos) + var_s1) - temp_t5) + zPos) - var_s0) + temp_t5) >= sp84) {
                    if ((yRotation2 < 0x20) || (yRotation2 >= 0xA0)) {
                        if (xPos < (var_s1 - var_t4_3)) {
                            // goto block_205;
                            var_s2 = 0x408;
                        }
                        else if ((var_s1 + var_t4_3) < xPos) {
                            var_s2 = 0x4C8;
                        } else {
                            var_s2 = 0;
                        }
                    } else {
                        // sp8E = yRotation2;
                        var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                    }
                } else if ((yRotation2 >= 0x20) && (yRotation2 < 0xA0)) {
                    if (zPos < (var_s0 - var_t4_3)) {
                        // goto block_205;
                        var_s2 = 0x408;
                    }
                    else if ((var_s0 + var_t4_3) < zPos) {
                        var_s2 = 0x448;
                    } else {
                        var_s2 = 0x40;
                    }
                } else {
                    var_s2 = ((func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                }
            }
        } else if ((var_s1 < xPos) && (var_s0 < zPos)) {
            yRotation2 = (func_801284B8(var_t2 + 0x280, var_t1 + 0x280) << 8) / 360;
            if (var_s5 <= 0xA) {
                var_s5 = 0xA;
            }
        } else {
            var_s2 = 0x408;
        }
        break;
    case 6:
        if (func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 3) != 0) {
            if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                if ((yRotation2 < 0x60) || (yRotation2 >= 0xE0)) {
                    var_s2 = 0;
                } else {
                    var_s2 = 0xC0;
                }
            } else {
                temp_t6_2 = sp86 >> 1;
                if ((((temp_a0_7 + temp_t6_2 + zPos) - var_s0) + temp_t6_2) >= sp84) {
                    if ((yRotation2 < 0x60) || (yRotation2 >= 0xE0)) {
                        if (xPos < (var_s1 - var_t4_3)) {
                            var_s2 = 0x408;
                        } else {
                            if ((var_s1 + var_t4_3) < xPos) {
                                // goto block_241;
                                var_s2 = 0x4C8;
                            } else {
                                var_s2 = 0;
                            }
                        }
                    } else {
                        var_s2 = ((func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                    }
                } else if ((yRotation2 >= 0x60) && (yRotation2 < 0xE0)) {
                    if (zPos < (var_s0 - var_t4_3)) {
                        var_s2 = 0x4C8;
                    } else
                    if ((var_s0 + var_t4_3) < zPos) {
                        var_s2 = 0x488;
                    } else {
                        var_s2 = 0xC0;
                    }
                } else {
                    var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                }
            }
        } else if ((xPos < var_s1) && (var_s0 < zPos)) {
            yRotation2 = (func_801284B8(var_t2 - 0x280, var_t1 + 0x280) << 8) / 360;
            if (var_s5 <= 0xA) {
                var_s5 = 0xA;
            }
        } else {
            var_s2 = 0x4C8;
        }
        break;
    case 8:
        if ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 2) != 0) || ((func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 1) != 0))) {
            if ((yRotation2 < 0x60) || (yRotation2 >= 0xA0)) {
                goto block_354;
            }
        case 11:
            if ((yRotation2 < 0x40) || (yRotation2 >= 0xC0)) {
                if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                    var_s5 = -1;
                } else {
                    var_s2 = ((func_801284B8(var_s1 - xPos, (var_s0 - zPos)) << 8) / 360) + 1000;
                }
            } else {
                var_s2 = ((func_801284B8(var_s1 - xPos, ((var_s0 - (sp86 >> 1)) - zPos)) << 8) / 360) + 1000;
            }
        } else {
            if ((zPos < var_s0) || ((yRotation2 >= 0x40) && (yRotation2 < 0xC0))) {
                yRotation2 = ((func_801284B8(var_t2, (var_t1 - 0x280)) << 8) / 360);
                if (var_s5 <= 0xA) {
                    var_s5 = 0xA;
                }
            } else {
                var_s2 = 0x468;
            }
        }
        break; // goto block_400;
    case 9:

        if (func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 1) != 0) {
            // TODO: check this logic
            if (((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3))) {
                if ((yRotation2 < 0x60) || (yRotation2 >= 0xE0)) {
                    var_s2 = 0x40;
                } else {
                    var_s2 = 0x80;
                }
            } else {
                temp_t8_3 = sp86 >> 1;
                if ((((temp_a0_9 + temp_t8_3 + zPos) - var_s0) + temp_t8_3) >= sp84) {
                    if ((yRotation2 < 0x60) || (yRotation2 >= 0xE0)) {
                        if (zPos < (var_s0 - var_t4_3)) {
                            var_s2 = 0x408;
                        } else {
                            if ((var_s0 + var_t4_3) < zPos) {
                                var_s2 = 0x448;
                            } else {
                                var_s2 = 0x40;
                            }
                        }
                    } else {
                        var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                    }
                } else if ((yRotation2 >= 0x60) && (yRotation2 < 0xE0)) {
                    if (xPos < (var_s1 - var_t4_3)) {
                        var_s2 = 0x448;
                    } else
                    if ((var_s1 + var_t4_3) < xPos) {
                        var_s2 = 0x488;
                    } else {
                        var_s2 = 0x80;
                    }
                } else {
                    var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                }
            }
        } else if ((var_s1 < xPos) && (zPos < var_s0)) {
            yRotation2 = (s16) ((s32) (func_801284B8(var_t2 + 0x280, (s16) (var_t1 - 0x280)) << 8) / 360);
            if (var_s5 <= 0xA) {
                var_s5 = 0xA;
            }
        } else {
            var_s2 = 0x448;
        }
        break;
    case 10:

        if (func_80305A70_717120(var_s1, var_s0, D_803D5530->yPos.w, sp86, 2) != 0) {
            if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
                if ((yRotation2 < 0x20) || (yRotation2 >= 0xA0)) {
                    var_s2 = 0xC0;
                } else {
                    var_s2 = 0x80;
                }
            } else {
                temp_t9 = sp86 >> 1;
                if (((((((sp84 - xPos) + var_s1) - temp_t9) + zPos) - var_s0) + temp_t9) >= sp84) {
                    if ((yRotation2 < 0x20) || (yRotation2 >= 0xA0)) {
                        if (zPos < (var_s0 - var_t4_3)) {
                            var_s2 = 0x4C8;
                        } else {
                            if ((var_s0 + var_t4_3) < zPos) {
                                var_s2 = 0x488;
                            } else {
                                var_s2 = 0xC0;
                            }
                        }
                    } else {
                        var_s2 = ((s32) (func_801284B8(var_s1 - xPos, var_s0 - zPos) << 8) / 360) + 1000;
                    }
                } else if ((yRotation2 >= 0x20) && (yRotation2 < 0xA0)) {
                    if (xPos < (var_s1 - var_t4_3)) {
                        var_s2 = 0x448;
                    } else {
                        if ((var_s1 + var_t4_3) < xPos) {
                            var_s2 = 0x488;
                        } else {
                            var_s2 = 0x80;
                        }
                    }
                } else {
                    var_s2 = ((func_801284B8((var_s1 - xPos), (var_s0 - zPos)) << 8) / 360) + 1000;
                }
            }
        } else if ((xPos < var_s1) && (zPos < var_s0)) {
            yRotation2 = (func_801284B8((var_t2 - 0x280), (var_t1 - 0x280)) << 8) / 360;
            if (var_s5 <= 0xA) {
                var_s5 = 0xA;
            }
        } else {
            var_s2 = 0x488;
        }
        break;
    case 12:
        goto block_354;
    case 15:
        if ((ABS(xPos - var_s1) < var_t4_3) && (ABS(zPos - var_s0) < var_t4_3)) {
            var_s5 = -1;
        } else {
            var_s2 = ((func_801284B8((var_s1 - xPos), (var_s0 - zPos)) << 8) / 360) + 1000;
        }
        break;
    default:
        break;
    }

    if ((var_s2 >= 0) && (var_s5 > 0)) {
        if (var_s2 >= 1000) {
            var_s2 -= 1000;
            if (var_s5 <= 0xA) {
                var_s5 = 0xA;
            }
        }
        if (func_803051F0_7168A0(D_803D5530->yRotation, var_s2) >= 6) {
            var_s5 = -1;
        }
        yRotation2 = var_s2;
    }

    if (D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == MOUSE2) {
        posDiff = ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h - D_803D5530->xPos.h);
        if (posDiff < 0x280) {
            zPosDiff = ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h - D_803D5530->zPos.h);
            if (zPosDiff < 0x280) {
                if (zPosDiff >= posDiff) {
                    posDiff = zPosDiff;
                }
                yPosDiff = ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h - D_803D5530->yPos.h);
                if (yPosDiff < 0x280) {
                    if (yPosDiff >= posDiff) {
                        posDiff = yPosDiff;
                    }
                    if (D_803D5540 & 0x40) {
                        yRotation2 += 0x80 - ((s32) (posDiff << 7) / 640);
                    } else {
                        yRotation2 -= 0x80 - ((s32) (posDiff << 7) / 640);
                    }
                }
            }
        }
    }

    yRotation = D_803D5530->yRotation;
    var_a0_4 = (D_803D5530->yRotation - (yRotation2 + ((s32) (((s16) D_803D5528->unk348 >> 2) * ((s16) D_80152C78[(s16)(D_803D5540 << 2) & 0xFF] >> 7)) >> 0xA))) & 0xFF;

    if (var_a0_4 != 0) {
        defaultYRotation = D_803A47F4_7B5EA4[D_803D5524->unk9C];
        if (var_a0_4 >= 0x80) {
            var_a0_4 = 0x100 - var_a0_4;
            if (var_a0_4 < defaultYRotation) {
                yRotation += var_a0_4;
            } else {
                yRotation += defaultYRotation;
            }
        } else if (var_a0_4 < defaultYRotation) {
            yRotation -= var_a0_4;
        } else {
            yRotation -= defaultYRotation;
        }
    }

    if (var_s5 > 0) {
        if (D_803D552C->unk272 & 0xC0) {
            var_v0_5 = 7;
            if (D_803D552C->unk272 & 0x40) {
                var_v0_5 = 6;
            }
            if (D_803D552C->unk272 & 0x80) {
                var_v0_5 -= 1;
            }
            var_s5 -= (s32) (var_s5 * var_a0_4) >> var_v0_5;
            if (var_s5 <= 0) {
                var_s5 = -1;
            }
        }
    }

    if ((var_s5 > 0) && (var_s5 < 4)) {
        var_s5 = 4;
    }
    func_802AB8EC_6BCF9C(yRotation, var_s5, yOffset);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803071BC_71886C.s")
#endif

// ESA: func_8007BD9C
s32 func_80309798_71AE48(Animal *arg0) {
    u8 i, j;
    Animal *tmp;

    tmp = arg0;
    if (tmp->unk4A == 0) {
        if ((tmp->unk16C->objectType != (OB_TYPE_ANIMAL_OFFSET+EVO_TRANSFER)) &&
            (tmp->unk16C->objectType != (OB_TYPE_ANIMAL_OFFSET+EVO)) &&
            (tmp->unk16C->objectType != (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP))) {
            if ((tmp->unk366 != 5) && (tmp->unk366 != 2)) {
                if (D_803D5530->unk18C == 0) {
                    return 1;
                }
                for (i = 0; i < D_803D5530->unk18C; i++) {
                    for (j = 0; j < tmp->unk192; j++) {
                        if (D_803D5530->unk18D[i] == tmp->unk193[j]) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// ESA: func_8007BE84
s32 func_80309868_71AF18(void) {
    if ((D_803D552C->unk272 & 1) != 0) {
        if ((D_803E4BE0.unk58 != 0) && (D_803E4BE0.unk54 < D_803A4638_7B5CE8[D_803D5530->unk16C->objectType])) {
            return func_80309798_71AE48(D_803E4BE0.unk58);
        }
    }
    return 0;
}

// ESA: func_8007BF20
s32 func_803098F0_71AFA0(void) {
    s32 xDist = ABS(D_803D5530->xPos.h - D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h);
    s32 zDist = ABS(D_803D5530->zPos.h - D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h);

    if ((D_803D552C->unk272 & 1)) {
        if ((s16) (zDist + xDist) < D_803A4638_7B5CE8[D_803D5530->unk16C->objectType]) {
            return func_80309798_71AE48(D_801D9ED8.animals[gCurrentAnimalIndex].animal);
        }
    }
    return 0;
}

// ESA: func_8007C038
s32 func_803099BC_71B06C(void) {
    if (D_803D552C->waypointType == 8) {
        if (D_803D552C->unk272 & 1) {
            if (D_803D552C->unk2CC != 0) {
                if ((D_803D5524->unk9C != EVO_TRANSFER) &&
                    (D_803D5524->unk9C != EVO) &&
                    (D_803D5524->unk9C != EVO_MICROCHIP)) {
                    if ((D_803D552C->unk2CC->unk366 != 5) && (D_803D552C->unk2CC->unk366 != 2)) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    if (D_803D552C->unk272 & 1) {
        if ((D_803D552C->unk2CC != 0) &&
            (D_803D552C->unk2CC->unk16C->objectType != (OB_TYPE_ANIMAL_OFFSET+SNEAKY_CHAMELEON)) &&
            (D_803D552C->unk2D0 < D_803A4638_7B5CE8[D_803D5530->unk16C->objectType])) {
            return func_80309798_71AE48(D_803D552C->unk2CC);
        }
    }
    return 0;
}

// ESA: func_8007C164
s32 func_80309ACC_71B17C(void) {
    if (D_803E4BE0.unk64 != 0) {
        if ((D_803E4BE0.unk60 != NULL) && ((D_803D552C->unk272 & 8) != 0) && (D_803E4BE0.unk5C < 0x280)) {
            return func_80309798_71AE48(D_803E4BE0.unk60);
        }
    }
    return 0;
}

// ESA: func_8007C1E0
s32 func_80309B40_71B1F0(void) {
    if ((D_803D552C->unk272 & 8) != 0) {
        if ((D_803D552C->unk280 != NULL) && (D_803D552C->unk284 < 640)) {
            return func_80309798_71AE48(D_803D552C->unk280);
        }
    }
    return 0;
}

s32 func_80309BA0_71B250(void) {
    s32 phi_v1;
    s32 phi_a3;
    s32 phi_v0;
    Animal *a;
    Animal *a2;


    if ((D_803D552C->unk272 & 1)) {
        a = D_803E4BE0.unk58;
        if (a != NULL) {
            a2 = a;
            phi_a3 = ABS(D_803D552C->unk280->xPos.h - a2->xPos.h);
            phi_v1 = ABS(D_803D552C->unk280->zPos.h - a2->zPos.h);

            // typo? function looks completely different without the double assignment
            phi_a3 = ABS(D_803D552C->unk280->xPos.h - a2->xPos.h);
            if ((D_803D552C->unk280 && D_803D552C->unk280) && D_803D552C->unk280) {}; // fakematch/regalloc fix
            phi_v1 = ABS(D_803D552C->unk280->zPos.h - a2->zPos.h);

            phi_v0 = (phi_v1 + phi_a3) - (D_803D552C->unk280->unk30 + a2->unk30);
            phi_v0 = MAX(1, phi_v0);

            if ((phi_v0 < 320) && (D_803E4BE0.unk54 < D_803A4638_7B5CE8[D_803D5530->unk16C->objectType])) {
                return func_80309798_71AE48(a2);
            }
        }
    }
    return 0;
}

// ESA: func_8007C240
void func_80309C8C_71B33C(void) {
    static s8 D_803A5580_7B6C30 = 0; // .data

    if (D_803D552C->unk270 != 0) {
        D_803D552C->unk287 = 0;
    }
    switch (D_803D552C->unk287) {
    case 0:
        break;
    case 1:
        if ((D_803D552C->unk28A != 0) || (D_803E4BE0.unk5C < 640)) {
            D_803D552C->unk287 = 0;
            func_80363CC8_775378(D_803D5530);
            break;
        }
        D_803D552C->unk288--;
        if (D_803D552C->unk288 <= 0) {
            // do "sheep follow leader" every 4 iterations
            if ((D_803A5580_7B6C30++ & 3) == 0) {
                func_8037FEDC_79158C();
            }
            D_803D552C->unk287 = 2;
            D_803D552C->unk288 = 0;
        }
        break;
    case 2:
        if ((D_803D552C->unk28A != 0) || (++D_803D552C->unk288 >= 70)) {
            D_803D552C->unk287 = 0;
            func_80363CC8_775378(D_803D5530);
        }
        break;
    }
}

// functionally similar to func_802F8918_709FC8
// ESA: func_8007C398
s32 func_80309DC4_71B474(void) {
    s16 i, j;

    if (D_803D5530->unk18C == 0) {
        return 1;
    }
    for (i = 0; i < D_803D5530->unk18C; i++) {
        for (j = 0; j < D_803D5530->unk192; j++) {
            if (D_803D5530->unk193[j] == D_803D5530->unk18D[i]) {
                return 1;
            }
        }
    }

    return 0;
}

// ESA: func_8007C444
void func_80309E4C_71B4FC(Animal *arg0) {
    D_803D552C->unk2B8 = 0;
    D_803D552C->unk2BC = 0;
    D_803D552C->unk2C0 = 0;
    D_803D552C->unk2B4.state = 0;
    D_803D552C->unk2C8 = D_803D552C->unk272;

    D_803D552C->unk2CC = arg0;
    if (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        D_803D552C->unk2B4.unk7 = 1;
    } else {
        D_803D552C->unk2B4.unk7 = 0;
    }
}

// ESA: func_8007C4B0
void func_80309EDC_71B58C(Animal *arg0) {
    D_803D552C->unk2CC = arg0;
    if (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        D_803D552C->unk2B4.unk7 = 1;
    } else {
        D_803D552C->unk2B4.unk7 = 0;
    }
}

void func_80309F38_71B5E8(void) {
    struct067 *tmp;

    if (D_803D552C->unk2C4 > 0) {
        D_803D552C->unk2C4--;
    }

    func_80319C38_72B2E8(
        D_803D5530->xPos.h >> 6,
        D_803D5530->zPos.h >> 6,
        D_803D5530->yPos.h >> 6,
        D_803D5530->unk193,
        &D_803D5530->unk192,
        D_803D5530->unk160);

    D_803D5530->unk193[4] = func_80309DC4_71B474();

    if (D_803D552C->unk270 != 2) {
        if (D_803D5530->unk193[4] == 0) {
            tmp = &D_803E93B0[D_803D5530->unk18D[4]];
            func_80363C48_7752F8(
                D_803D5530,
                (tmp->unk3 + tmp->unk0) << 5,
                (tmp->unk4 + tmp->unk1) << 5,
                -1,
                16,
                32);
            D_803D552C->unk270 = 2;
            D_803D552C->unk2CC = 0;
        } else {
            D_803D5530->unk18D[4] = D_803D5530->unk193[0];
        }
    }
    func_80305368_716A18(&D_803E4BE0);

    if (D_803D552C->unk2CC != NULL) {
        D_803D552C->unk2D0 = sqrtf(
            ((D_803D552C->unk2CC->xPos.h - D_803D5530->xPos.h) * (D_803D552C->unk2CC->xPos.h - D_803D5530->xPos.h)) +
            ((D_803D552C->unk2CC->zPos.h - D_803D5530->zPos.h) * (D_803D552C->unk2CC->zPos.h - D_803D5530->zPos.h)));
        D_803D552C->unk2D0 = ((D_803D552C->unk2D0 - D_803D5524->unkBE) - D_803D552C->unk2CC->unk30);
        if (D_803D552C->unk2D0 < 0) {
            D_803D552C->unk2D0 = 1;
        }
    }

    if (D_803D552C->unk280 != NULL) {
        D_803D552C->unk284 = sqrtf(
            ((D_803D552C->unk280->xPos.h - D_803D5530->xPos.h) * (D_803D552C->unk280->xPos.h - D_803D5530->xPos.h)) +
            ((D_803D552C->unk280->zPos.h - D_803D5530->zPos.h) * (D_803D552C->unk280->zPos.h - D_803D5530->zPos.h)));
        D_803D552C->unk284 = ((D_803D552C->unk284 - D_803D5524->unkBE) - D_803D552C->unk280->unk30);
        if (D_803D552C->unk284 < 0) {
            D_803D552C->unk284 = 1;
        }
    }

    switch (D_803D552C->unk270) {
    case 0:
        if (D_803D552C->waypointType != 8) {
            if (func_80309868_71AF18() != 0) {
                func_80309E4C_71B4FC(D_803E4BE0.unk58);
                D_803D552C->unk270 = 1;
                break;
            }
            if (func_80309ACC_71B17C() != 0) {
                D_803D552C->unk280 = D_803E4BE0.unk60;
                D_803D552C->unk270 = 3;
                break;
            }
            if (D_803D552C->unk2EB != 0) {
                D_803D552C->unk271 += D_803D552C->unk2EB;
                D_803D552C->unk2EB = 0;
                if ((D_803D552C->unk271 >= 3) && (func_803098F0_71AFA0() != 0)) {
                    func_80309E4C_71B4FC(D_801D9ED8.animals[gCurrentAnimalIndex].animal);
                    D_803D552C->unk270 = 1;
                    D_803D552C->unk271 = 2;
                    break;
                }
                if ((D_803D552C->unk272 & 0x400) != 0) {
                    D_803D552C->unk2B4.state = 0;
                    D_803D552C->unk270 = 6;
                    break;
                }
            }
        }

        if (D_803D5530->commands.unk1A8 != NULL) {
            func_803191B0_72A860(D_803D5530);
        }
        func_80309C8C_71B33C();
        func_80362CC4_774374(D_803D5530);
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        break;
    case 1:
        if (func_803099BC_71B06C() != 0) {
            if (((D_803D552C->waypointType != 8) && (D_803E4BE0.unk58 != D_803D552C->unk2CC)) && (func_80309868_71AF18() != 0)) {
                func_80309EDC_71B58C(D_803E4BE0.unk58);
            }
        } else {
            D_803D552C->unk270 = 0;
            D_803D552C->unk272 = D_803D552C->unk2C8;
            D_803D552C->unk2B4.unk4 = 0;
            D_803D552C->unk2CC = 0;
            D_803D552C->unk287 = 0;

            if (D_803D552C->unk271 > 2) {
                D_803D552C->unk271 = 0;
            }
            func_80363FF0_7756A0(D_803D5530);
            break;
        }

        func_80389764_79AE14(0);
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        break;
    case 2:
        if (D_803D5530->unk193[4] != 0) {
            func_80363FF0_7756A0(D_803D5530);
            D_803D552C->unk270 = 0;
            D_803D552C->unk287 = 0;
        }

        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        break;
    case 3:
        if (func_80309B40_71B1F0() == 0) {
            func_80363FF0_7756A0(D_803D5530);
            D_803D552C->unk270 = 0;
            D_803D552C->unk280 = NULL;
            D_803D552C->unk287 = 0;
            break;
        }
        if ((D_803E4BE0.unk60 != D_803D552C->unk280) && (D_803E4BE0.unk64 != 0)) {
            D_803D552C->unk280 = D_803E4BE0.unk60;
            break;
        }
        if ((D_803D552C->unk280->unk2B4.unk4 != 0) && (D_803D552C->unk284 < 480)) {
            func_80309E4C_71B4FC(D_803D552C->unk280->unk2CC); // , &D_803E4BE0
            D_803D552C->unk270 = 4;
        }
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        D_803D552C->unk280->unk2B4.unk8++;
        break;
    case 4:
        if (func_80309B40_71B1F0() == 0) {
            D_803D552C->unk270 = 0;
            D_803D552C->unk272 = D_803D552C->unk2C8;
            D_803D552C->unk2CC = 0;
            D_803D552C->unk280 = NULL;
            D_803D552C->unk287 = 0;
            func_80363FF0_7756A0(D_803D5530);
            break;
        }

        D_803D552C->unk280->unk2B4.unk8++;

        if ((D_803D552C->unk284 > 490) || (D_803D552C->unk280->unk2CC == 0) || (D_803D552C->unk280->unk2B4.unk4 == 0)) {
            D_803D552C->unk270 = 3;
            D_803D552C->unk272 = D_803D552C->unk2C8;
            D_803D552C->unk2CC = 0;
            func_80363CC8_775378(D_803D5530);
            break;
        }

        func_80389764_79AE14(1);
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();

        break;
    case 5:
        if (func_80309B40_71B1F0() == 0) {
            D_803D552C->unk270 = 0;
            D_803D552C->unk272 = D_803D552C->unk2C8;
            D_803D552C->unk2CC = 0;
            D_803D552C->unk280 = NULL;
            D_803D552C->unk287 = 0;
            func_80363FF0_7756A0(D_803D5530);
            break;
        }

        D_803D552C->unk280->unk2B4.unk8++;

        if ((D_803D552C->unk280->unk2D0 > 320) ||
            (D_803E4BE0.unk5C > 490) ||
            (func_80362B00_7741B0(D_803D552C->unk2CC))) {
            D_803D552C->unk270 = 3;
            D_803D552C->unk272 = D_803D552C->unk2C8;
            D_803D552C->unk2CC = 0;
            func_80363CC8_775378(D_803D5530);
            break;
        }

        func_80389764_79AE14(2);
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        break;
    case 6:
        if ((D_803D552C->unk272 & 0x400) == 0) {
            func_80363FF0_7756A0(D_803D5530);
            D_803D552C->unk270 = 0;
            D_803D552C->unk2EB = 0;
            D_803D552C->unk287 = 0;
        } else if (func_803897B0_79AE60(D_803D552C->unk271) != 0) {
            func_80363FF0_7756A0(D_803D5530);
            D_803D552C->unk270 = 0;
            D_803D552C->unk287 = 0;
        } else if (D_803D552C->unk2EB != 0) {
            D_803D552C->unk271 += D_803D552C->unk2EB;
            D_803D552C->unk2EB = 0;
            if (D_803D552C->unk271 >= 3) {
                func_80309E4C_71B4FC(D_801D9ED8.animals[gCurrentAnimalIndex].animal);
                D_803D552C->unk270 = 1;
                D_803D552C->unk271 = 2;
            }
        }
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        break;
    }

    D_803D552C->unk2B4.unk8 = 0;
}

// ESA: func_8007CE7C
void func_8030A8EC_71BF9C(void) {
    Animal *animal = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    func_80319C38_72B2E8(animal->xPos.h >> 6, animal->zPos.h >> 6, animal->yPos.h >> 6,
                         animal->unk193, &animal->unk192, animal->unk160);
}

void animal_jump(void) {
    if ((D_803D5524->canJump & 1) && (D_803D5524->class == CLASS_WALK)) {
        if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) {
            switch (D_803D5530->state) {
            case STATE_STANDING:
                func_802A6390_6B7A40();
                break;
            case STATE_WALKING:
                func_802A6390_6B7A40();
                break;
            case STATE_RUNNING:
                func_802A63C0_6B7A70();
                break;
            default:
                break;
            }
        }
    }
}

// ESA: func_8007CFAC
s32 func_8030AA08_71C0B8(Animal *arg0, Animal *arg1) {
    if (arg0 == arg1->unk2CC) {
        return 0;
    }
    if ((arg1->unk272 & 1) || (arg1->unk272 & 4)) {
        // get behaviour
        s16 tmp = func_802EA3E0_6FBA90(arg1->unk16C->objectType, arg0->unk16C->objectType);
        // attack or flee
        if ((tmp == 2) || (tmp == 1))
            return 0;
    }
    return 1;
}
