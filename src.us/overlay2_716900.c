#include <ultra64.h>
#include "common.h"

// used in func_80309F38_71B5E8
#pragma intrinsic sqrtf

s32  func_8030AAE0_71C190(struct071 *arg0);
s32  func_8030EBF0_7202A0(void);
s16  func_803102BC_72196C(void);
void func_80362CC4_774374(Animal*);
void func_803633C4_774A74(Animal*);
void func_80305368_716A18(struct079 *);
void func_803071BC_71886C(void);


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

// delay slot + jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305368_716A18.s")
// void func_80305368_716A18(struct079 *arg0) {
//     s16 sp86;
//     s16 sp84;
//     s16 sp80;
//     s16 sp7A;
//     s16 sp78;
//     s16 sp60;
//     s16 sp58;
//     s16 sp56;
//     // s32 sp40;
//
//     s16 temp_fp;
//     s32 temp_s0;
//     s16 temp_t0;
//     s16 temp_t1;
//     s16 temp_t4;
//     s16 var_a3;
//     s32 var_s0;
//     s16 var_t2;
//     s16 var_t3;
//     s16 i;
//     s16 temp_t7;
//     s16 temp_t9;
//
//     u8 var_a1;
//
//     Animal *animal;
//     struct035 *temp_v1_4;
//     struct065 *var_s5;
//
//     if ((D_803D5524->class == 0x40) || (D_803D5524->waterClass & WATER_SWIM)) {
//         sp58 = D_803D5530->yPos.h + 0x190;
//         sp56 = D_803D5530->yPos.h - 0x1F4;
//     } else {
//         sp58 = D_803D5530->yPos.h + 0xC8;
//         sp56 = D_803D5530->yPos.h - 0xC8;
//     }
//
//     temp_fp = D_803D5530->xPos.h;
//     temp_t4 = D_803D5530->zPos.h;
//
//     var_t2 = (s16)(temp_fp >> 6) - 1;
//     temp_t0 = (s16)(temp_t4 >> 6) - 1;
//
//     sp84 = (s16)(temp_fp >> 6) + 1;
//     temp_t1 = (s16)(temp_t4 >> 6) + 1;
//
//     var_a3 = temp_t0;
//     var_t3 = temp_t1;
//
//     if (var_t2 < 0) {
//         var_t2 = 0;
//     } else if (sp84 > 72) {
//         sp84 = 72;
//     }
//
//     if (var_a3 < 0) {
//         var_a3 = 0;
//     } else if (var_t3 > 128) {
//         var_t3 = 128;
//     }
//
//     var_t2 = var_t2 >> 4;
//     sp84 = sp84 >> 4;
//
//     temp_t9 = (s16)(var_a3 >> 4);
//     temp_t7 = (s16)(var_t3 >> 4);
//
//     for (i = 0; i < 3; i++) {
//         arg0->unk38.distance[i] = MAX_INT;
//         arg0->unk1C.distance[i] = MAX_INT;
//         arg0->unk0.distance[i] = MAX_INT;
//     }
//
//     arg0->unk38.used = 0;
//     arg0->unk1C.used = 0;
//     arg0->unk0.used = 0;
//
//     arg0->unk5C = MAX_INT;
//     arg0->unk54 = MAX_INT;
//
//     arg0->unk58 = NULL;
//     arg0->unk60 = NULL;
//
//     for (sp78 = temp_t9; sp78 <= temp_t7; sp78++) {
//         for (sp7A = var_t2; sp7A <= sp84; sp7A++) {
//             for (var_s5 = D_803DA110[(sp7A + (sp78 * 5)) & 0xFFFF].next; var_s5 != NULL; var_s5 = var_s5->next) {
//                 animal = var_s5->animal;
//                 temp_v1_4 = animal->unk16C;
//
//                 if (temp_v1_4->objectType < OB_TYPE_ANIMAL_OFFSET) {
//
//                     // it's an object
//
//                     if ((temp_v1_4->unk80.unk11 == 0) && (temp_v1_4->objectType != 0x36) && (temp_v1_4->objectType != 0x37) && (temp_v1_4->objectType != 0x38)) {
//                         if ((temp_v1_4->unk2 != 1) && (temp_v1_4->unk2 != 9) && (temp_v1_4->unk15 != 2)) {
//                             if ((animal != D_803D552C->unk2AC) && (animal != D_803D552C->unk320)) {
//                                 temp_s0 = (ABS(animal->xPos.h - temp_t4) + ABS(animal->zPos.h - temp_fp)) - D_803D5524->unkBE;
//                                 if (temp_v1_4->unk2 == 2) {
//                                     if ((D_803D5524->unk9C == RAT) || (D_803D5524->unk9C == POLAR_BEAR) || (D_803D5524->unk9C == HIPPO) || (D_803D5524->unk9C == KING_RAT) || (D_803D5524->unk9C == POLAR_TANK)) {
//                                         if (animal->unk15C < 25) {
//                                             func_80305250_716900(&arg0->unk38, animal, (temp_s0 - animal->unk30) - 100, 2);
//                                         }
//                                     } else {
//                                         func_80305250_716900(&arg0->unk1C, animal, (temp_s0 - animal->unk30) - 100, 2);
//                                     }
//                                 } else {
//                                     func_80305250_716900(&arg0->unk38, animal, temp_s0, 2);
//                                 }
//                             }
//                         }
//                     }
//                 } else if ((animal != D_803D5530) && (temp_v1_4->objectType != OB_TYPE_ANIMAL_OFFSET+EVO_TRANSFER)) {
//
//                     // its an animal
//
//                     if ((animal->yPos.h < sp58) && (sp56 < animal->yPos.h)) {
//                         if ((func_80362B00_7741B0(animal) != 0) || ((can_swim(D_803D5530) != 0) && (func_80362B60_774210(animal) == 0))) {
//                             var_a1 = 0;
//                         } else {
//                             var_a1 = func_802EA3E0_6FBA90(D_803D5530->unk16C->objectType, animal->unk16C->objectType);
//                         }
//
//                         // tbd if this is the right order
//                         var_s0 = ((ABS(animal->xPos.h - temp_t4) + ABS(animal->zPos.h - temp_fp)) - D_803D5524->unkBE) - animal->unk16C->unkBE;
//                         if (var_s0 < 0) {
//                             var_s0 = 0;
//                         }
//                         switch (var_a1) {
//                         case AI_IGNORE:
//                             func_80305250_716900(&arg0->unk38, animal, var_s0, 2);
//                             break;
//                         case AI_FLEE:
//                             if (D_803D552C->unk272 & 4) {
//                                 func_80305250_716900(&arg0->unk1C, animal, var_s0, 2);
//                             }
//                             func_80305250_716900(&arg0->unk38, animal, var_s0, 2);
//                             break;
//                         case AI_ATTACK:
//                             if (D_803D552C->unk272 & 1) {
//                                 if (var_s0 < arg0->unk54) {
//                                     arg0->unk54 = var_s0;
//                                     arg0->unk58 = animal;
//                                 }
//                             } else {
//                                 func_80305250_716900(&arg0->unk38, animal, var_s0, 2);
//                             }
//                             break;
//                         case AI_SAME_ANIMAL:
//                             func_80305250_716900(&arg0->unk38, animal, var_s0, 2);
//                             break;
//                         case AI_HERD:
//                             if (D_803D552C->unk272 & 8) {
//                                 func_80305250_716900(&arg0->unk0, animal, var_s0, 2);
//                             } else {
//                                 func_80305250_716900(&arg0->unk38, animal, var_s0, 2);
//                             }
//                             break;
//                         case AI_LEAD_HERD:
//                             if (D_803D552C->unk272 & 8) {
//                                 if (var_s0 < arg0->unk5C) {
//                                     arg0->unk5C = var_s0;
//                                     arg0->unk60 = animal;
//                                     arg0->unk64 = 0;
//                                 }
//                             } else {
//                                 func_80305250_716900(&arg0->unk38, animal, var_s0, 2);
//                             }
//                             break;
//                         case AI_FOLLOWER:
//                             if (var_s0 < arg0->unk5C) {
//                                 arg0->unk5C = var_s0;
//                                 arg0->unk60 = animal;
//                                 arg0->unk64 = 1;
//                             }
//                             break;
//                         case AI_LEADER:
//                         case AI_INVISIBLE:
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305A70_717120.s")
// jank logic again
// s32 func_80305A70_717120(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u8 arg4) {
//     u8 sp4F;
//     u8 sp4E;
//
//     u8 sp43;
//
//     s32 sp30;
//     // void *sp24;
//     s32 sp20;
//     s32 sp1C;
//
//     s32 temp_a2;
//     s32 temp_a3;
//
//     s32 temp_t3;
//     s32 temp_t5;
//     s32 temp_t8;
//     s32 temp_v0;
//     s16 var_v1;
//
//     switch (arg4) {                                 /* irregular */
//     case 0:
//         sp4F = 3;
//         sp4E = 1;
//         break;
//     case 1:
//         sp4F = 2;
//         sp4E = 1;
//         break;
//     case 2:
//         sp4F = 2;
//         sp4E = 0;
//         break;
//     case 3:
//         sp4F = 3;
//         sp4E = 0;
//         break;
//     }
//
//     temp_a2 = arg0 + (D_803A5560_7B6C10[arg4] * arg3);
//     temp_a3 = arg1 + (D_803A5568_7B6C18[arg4] * arg3);
//
//     if (D_803C0740[temp_a2 >> 6][temp_a3 >> 6].unk3) {
//         sp20 = temp_a2;
//         sp1C = temp_a3;
//
//         temp_t3 = (arg2 - func_80310F58_722608(temp_a2, temp_a3)) >> 0x10;
//
//         if (ABS(temp_t3) < 49) {
//             // var_v1 = 0;
//             if (D_803D552C->unk272 & 0x20) {
//                 if ((D_803C0740[temp_a2 >> 6][temp_a3 >> 6].unk5 & (0x10 << (sp4F ^ 1))) &&
//                     (D_803C0740[temp_a2 >> 6][temp_a3 >> 6].unk5 & (0x10 << (sp4E ^ 1)))) {
//                     var_v1 = 1;
//                 } else {
//                     var_v1 = 0;
//                 }
//             } else {
//                 var_v1 = 0;
//             }
//         } else if (D_803D552C->unk272 & 0x20) {
//             if ((D_803C0740[temp_a2 >> 6][temp_a3 >> 6].unk5 & (1 << (sp4F ^ 1))) &&
//                 (D_803C0740[temp_a2 >> 6][temp_a3 >> 6].unk5 & (1 << (sp4E ^ 1)))) {
//
//                 if (ABS(temp_t3) <= ((D_803E1D30[(D_803C0740[temp_a2 >> 6][temp_a3 >> 6].unk3)].unk2) * 8)) {
//                     sp43 = 1;
//                 }
//             }
//         }
//
//         sp30 = func_8031124C_7228FC(sp20, sp1C);
//         temp_t8 = (sp30 - func_8031124C_7228FC(arg0, arg1)) >> 0x10;
//
//         if (ABS(temp_t8) < 97) {
//             sp43 = 0;
//         } else if ((D_803D552C->unk272 & 0x20) && (temp_t8 < 0)) {
//             sp43 = 1;
//         }
//         var_v1 = sp43;
//     } else {
//         temp_t5 = (arg2 - func_8031124C_7228FC(temp_a2, temp_a3)) >> 0x10;
//         if (ABS(temp_t5) < 97) {
//             var_v1 = 0;
//         } else {
//             var_v1 = 1;
//         }
//     }
//     return var_v1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305DA4_717454.s")
// plenty of work still to do here
// s32 func_80305DA4_717454(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u8 arg4) {
//     Animal *sp50;
//     s32 sp4C;
//
//     s32 sp28;
//     s32 sp24;
//     s16 temp_t0;
//
//     s32 temp_t6;
//     s32 temp_t6_2;
//     s32 temp_t7;
//     s32 temp_t8;
//     s32 temp_t9;
//     s32 temp_t9_2;
//     s32 var_a1_2;
//     s32 var_a1_3;
//     u16 temp_a0;
//
//     Animal *animal;
//     struct065 *var_a1_4;
//
//     sp28 = arg0 + (D_803A5570_7B6C20[arg4] * arg3);
//     sp24 = arg1 + (D_803A5578_7B6C28[arg4] * arg3);
//
//     temp_t0 = GET_WATER_LEVEL(D_803C0740, sp28, sp24) * 4;
//
//     if ((D_803D5524->waterClass & WATER_SWIM) && (temp_t0 <= 0)) {
//         return 1;
//     }
//
//     if (D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk3 != 0) {
//
//         var_a1_2 = func_80310F58_722608(sp28, sp24);
//         if ((D_803D5524->waterClass & (WATER_SWIM|WATER_FLOAT))) {
//             temp_t7 = temp_t0 << 0x10;
//             if (var_a1_2 < temp_t7) {
//                 var_a1_2 = temp_t7;
//                 if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
//                     return 1;
//                 }
//             }
//         }
//
//         temp_t8 = (arg2 - var_a1_2) >> 0x10;
//         if (ABS(temp_t8) < 0x31) {
//             if (((D_803D552C->unk272 & 0x20) != 0) && ((D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk5 & (0x10 << (arg4 ^ 1))) != 0)) {
//                 return 1;
//             }
//             return 0;
//         }
//         if ((D_803D552C->unk272 & 0x20) && ((D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk5 & (1 << (arg4 ^ 1))) != 0)) {
//             if ((D_803E1D30[D_803C0740[(sp28 >> 6)+1][(sp24 >> 6)+1].unk3].unk2 * 8) >= ABS(temp_t8)) {
//                 return 1;
//             }
//         }
//         if ((D_803D5524->waterClass & (WATER_SWIM|WATER_FLOAT)) &&
//             (func_8031124C_7228FC(sp28, sp24) < (temp_t0 << 0x10)) &&
//             (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2))) {
//             return 1;
//         }
//
//         sp4C = func_8031124C_7228FC(sp28, sp24);
//         temp_t9 = (sp4C - func_8031124C_7228FC(arg0, arg1)) >> 0x10;
//         if (ABS(temp_t9) < 97) {
//             return 0;
//         }
//         if ((D_803D552C->unk272 & 0x20) && (temp_t9 < 0)) {
//             return 1;
//         }
//         goto block_60;
//     }
//
//     var_a1_3 = func_8031124C_7228FC(sp28, sp24);
//     if (D_803D5524->waterClass & WATER_SWIM) {
//         if (var_a1_3 >= arg2) {
//             return 1;
//         }
//         return 0;
//     }
//     temp_t6_2 = temp_t0 << 0x10;
//     if (((D_803D5524->waterClass & (WATER_SWIM|WATER_FLOAT)) != 0) && (var_a1_3 < temp_t6_2)) {
//         var_a1_3 = temp_t6_2;
//         if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
//             return 1;
//         }
//     }
//
//     temp_t9_2 = (s32) (arg2 - var_a1_3) >> 0x10;
//     if (ABS(temp_t9_2) < 97) {
//         return 0;
//     }
//     if (temp_t9_2 < 0) {
//         return 1; // goto block_99;
//     }
//
// block_60:
//     if (((D_803D552C->unk272 & 0x10) == 0) && ((D_803D5524->waterClass & WATER_SWIM) == 0)) {
//         return 0;
//     }
//
//     for (var_a1_4 = D_803DA110[(s16) ((arg0 >> 0xA) + ((arg1 >> 0xA) * 5))].next; var_a1_4 != NULL; var_a1_4 = var_a1_4->next) {
//         animal = var_a1_4->animal;
//         if ((animal->unk16C->unk80.unk11) && (animal != sp50) && (animal->xVelocity.h == 0) && (animal->zVelocity.h == 0) && (animal->yVelocity.h == 0)) {
//
//             if (ABS((animal->yPos.w + (animal->unk42 << 0x10)) - arg2) <= FTOFIX32(16.0)) {
//                 switch (arg4) {
//                 case 0:
//                     if ((ABS(animal->zPos.h - arg1) < (animal->unk32 >> 1)) &&
//                         ((arg0 - (arg3 >> 1)) < (animal->xPos.h + animal->unk30 + 2))) {
//                         return 0;
//                     }
//                     break;
//                 case 1:
//                     if ((ABS(animal->zPos.h - arg1) < (animal->unk32 >> 1)) &&
//                         ((arg0 + (arg3 >> 1)) > ((animal->xPos.h - animal->unk30) - 2))) {
//                         return 0;
//                     }
//                     break;
//                 case 2:
//                     if ((ABS(animal->xPos.h - arg0) < (animal->unk30 >> 1)) &&
//                         ((arg1 - (arg3 >> 1)) < (animal->zPos.h + animal->unk32 + 2))) {
//                         return 0;
//                     }
//                     break;
//                 case 3:
//                     if ((ABS(animal->xPos.h - arg0) < (animal->unk30 >> 1)) &&
//                         ((arg1 + (arg3 >> 1)) > ((animal->zPos.h - animal->unk32) - 2))) {
//                         return 0;
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     return 1;
// }

s16 func_803064BC_717B6C(s16 arg0, s16 arg1, s32 arg2, s16 arg3, s16 arg4) {
    u8 i;
    s16 phi_s1;
    s16 res;
    Animal *temp_v0;

    temp_v0 = D_803D5530->unk6C;
    if ((temp_v0 != NULL) && (temp_v0->unk16C->unk80.unk11) && ((temp_v0->xVelocity.w | temp_v0->zVelocity.w | (temp_v0->yVelocity.w != 0)) != 0)) {
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

#if 0
// logic nightmare...
s32 func_803065F0_717CA0(s16 arg0, s16 arg1, s32 arg2, s16 arg3, u16 arg4) {

    if ((arg3 != 0x40) || ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk16C->unk80.unk11))) { //  & 0x4000
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
        return 0;
    case 1:
        if (func_80305DA4_717454(arg0 + arg3, arg1, arg2, arg3, 1) != 0) {
            return 1;
        }
        if ((func_80305DA4_717454(arg0, (s16) (arg1 + arg3), arg2, arg3, 3) != 0) && (func_80305A70_717120(arg0 + arg3, arg1, arg2, arg3, 1) != 0)) {
            return 5;
        }
        if ((func_80305DA4_717454(arg0, (s16) (arg1 - arg3), arg2, arg3, 2) != 0) && (func_80305A70_717120(arg0 + arg3, arg1, arg2, arg3, 0) != 0)) {
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
            // return 0;
        }
        break;
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
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 1) != 0) || (((func_80305DA4_717454(arg0 + arg3, arg1 - arg3, arg2, arg3, 1) == 0)) && (func_80305DA4_717454(arg0 + arg3, arg1 - arg3, arg2, arg3, 2) != 0))) {
            // ?
        }
    case 10:
        // fall through?
        if ((func_80305A70_717120(arg0, arg1, arg2, arg3, 2) != 0) || (((func_80305DA4_717454(arg0 - arg3, arg1 - arg3, arg2, arg3, 0) == 0)) && (func_80305DA4_717454(arg0 - arg3, arg1 - arg3, arg2, arg3, 2) == 0))) {
            // ?
        }
        break;
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
    // default:
    //     break;
    }
    return 0;

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803065F0_717CA0.s")
#endif

#if 0
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
            if (func_80304E80_716530(&spBC) < 0x100) {
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
        if ((D_803E4C3C < 0x280) && (D_803D552C->unk272 & 8)) {
            if (D_803D552C->unk2CC != D_803E4C40) {
                spBC.unk0 = D_803E4C40->xPos.h - xPos;
                spBC.unk4 = D_803E4C40->zPos.h - zPos;
                if (D_803E4C3C < 0xC) {
                    func_80304EC4_716574(&spBC, &spB4);
                    var_t2 = var_t2 - (spB4.unk0 * 0xC0) >> 8;
                    var_t1 = var_t1 - (spB4.unk4 * 0xC0) >> 8;

                    if (var_s5 < (((12 - D_803E4C3C) << 4) / 12)) {
                        var_s5 = (((12 - D_803E4C3C) << 4) / 12);
                    }
                } else if ((D_803D552C->unk274 == 0) && (D_803E4C3C >= 0x4D)) {
                    func_80304EC4_716574(&spBC, &spB4);
                    var_t2 = var_t2 + (spB4.unk0 * 0xA0) >> 8;
                    var_t1 = var_t1 + (spB4.unk4 * 0xA0) >> 8;

                    temp_v0_7 = ((s32) ((D_803E4C3C - 0x4C) * 6) / 141) + 0xE;
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
        if ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk16C->unk80.unk11)) { //  & 0x4000
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

        if ((D_803D5530->unk6C == NULL) || ((D_803D5530->unk6C->unk16C->unk80.unk12))) { //  << 0x11 >= 0
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

s32 func_80309868_71AF18(void) {
    if ((D_803D552C->unk272 & 1) != 0) {
        if ((D_803E4BE0.unk58 != 0) && (D_803E4BE0.unk54 < D_803A4638_7B5CE8[D_803D5530->unk16C->objectType])) {
            return func_80309798_71AE48(D_803E4BE0.unk58);
        }
    }
    return 0;
}

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

s32 func_80309ACC_71B17C(void) {
    if (D_803E4BE0.unk64 != 0) {
        if ((D_803E4BE0.unk60 != NULL) && ((D_803D552C->unk272 & 8) != 0) && (D_803E4BE0.unk5C < 0x280)) {
            return func_80309798_71AE48(D_803E4BE0.unk60);
        }
    }
    return 0;
}

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

void func_80309C8C_71B33C(void) {
    static s8 D_803A5580_7B6C30 = 0;

    if (D_803D552C->unk270 != 0) {
        D_803D552C->unk287 = 0;
    }
    switch (D_803D552C->unk287) {
    case 0:
        break;
    case 1:
        if ((D_803D552C->unk28A != 0) || (D_803E4C3C < 640)) {
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
                func_80309E4C_71B4FC(D_803E4C38);
                D_803D552C->unk270 = 1;
                break;
            }
            if (func_80309ACC_71B17C() != 0) {
                D_803D552C->unk280 = D_803E4C40;
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

        if (D_803D5530->unk1A8 != 0) {
            func_803191B0_72A860(D_803D5530);
        }
        func_80309C8C_71B33C();
        func_80362CC4_774374(D_803D5530);
        func_803633C4_774A74(D_803D5530);
        func_803071BC_71886C();
        break;
    case 1:
        if (func_803099BC_71B06C() != 0) {
            if (((D_803D552C->waypointType != 8) && (D_803E4C38 != D_803D552C->unk2CC)) && (func_80309868_71AF18() != 0)) {
                func_80309EDC_71B58C(D_803E4C38);
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
            (D_803E4C3C > 490) ||
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

s32 func_8030AA90_71C140(struct071 *arg0) {
    if (!arg0->unk4C.unk30) {
        return 0;
    }
    if (!arg0->unk4C.unk29) {
        return func_8030E8AC_71FF5C(arg0);
    }
    return func_8030AAE0_71C190(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030AAE0_71C190.s")
// s32 func_8030AAE0_71C190(struct071 *arg0) {
//     s16 sp2E;
//     s16 sp2C;
//     s16 sp2A;
//     s16 sp28;
//     s16 sp26;
//     u8  sp25;
//     u8  sp24; // pad
//     s32 sp20;
//     s32 sp1C;
//
//     s32 temp_t9;
//     s32 phi_a3;
//     s32 phi_a3_2;
//
//     func_803899E0_79B090(arg0);
//     D_803E4C94 = arg0;
//     D_803E4C52 = arg0->xPos.h;
//     D_803E4C54 = arg0->zPos.h;
//
//     if ((arg0->unk162 & 0x10) != 0) {
//         D_803E4C5C = arg0->xPos.w;
//         D_803E4C60 = arg0->zPos.w;
//         D_803E4C64 = arg0->yPos.w;
//         D_803E4C56 = D_803E4C84;
//         D_803E4C58 = D_803E4C54;
//         phi_a3 = D_803E4C84;
//         // phi_t0 = D_803E4C54;
//     } else {
//         D_803E4C5C = (arg0->xPos.w + arg0->unk18);
//         D_803E4C60 = (arg0->zPos.w + arg0->unk1C.w);
//         D_803E4C64 = (arg0->yPos.w + arg0->unk20.w);
//         D_803E4C56 = D_803E4C5C >> 0x10;
//         D_803E4C58 = D_803E4C60 >> 0x10;
//         phi_a3 = D_803E4C52;
//     }
//
//     D_803E4C68 = (phi_a3 >> 6);
//     D_803E4C6A = (D_803E4C54 >> 6);
//     D_803E4C6C = (D_803E4C56 >> 6);
//     D_803E4C6E = (D_803E4C58 >> 6);
//     D_803E4C70 = (phi_a3 & 0x3F);
//     D_803E4C72 = (D_803E4C54 & 0x3F);
//     D_803E4C74 = (D_803E4C56 & 0x3F);
//     D_803E4C76 = (D_803E4C58 & 0x3F);
//
//     D_803E4C7C = arg0->unk1C.w;
//     D_803E4C80 = arg0->unk20.w;
//     D_803E4C78 = D_803E4C94->unk160;
//
//     sp25 = func_80310E10_7224C0(D_803E4C68, D_803E4C6A);
//     sp2E = func_8030B494_71CB44();
//     sp26 = func_80310030_7216E0();
//     sp2C = func_8030EA98_720148();
//     sp2A = func_8030EBF0_7202A0();
//     sp28 = func_803102BC_72196C();
//     temp_t9 = sp25 == 0;
//     sp20 = temp_t9;
//     phi_a3_2 = temp_t9;
//     if (temp_t9 == 0) {
//         sp1C = temp_t9;
//         sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
//         phi_a3_2 = sp1C;
//     }
//     if ((sp2E == 0) &&
//         (sp26 == 0) &&
//         (sp2C == 0) &&
//         (sp2A == 0) &&
//         (sp28 == 0) &&
//         ((u8)sp20 != 0)) {
//         func_8030E208_71F8B8();
//     } else if ((sp2E != 1) &&
//                (sp26 != 1) &&
//                (sp2C != 1) &&
//                (sp2A != 1) &&
//                (sp28 != 1) &&
//                (sp2E != 2) &&
//                (sp26 != 2) &&
//                (sp2C != 2) &&
//                (sp2A != 2) &&
//                (sp28 != 2)) {
//
//         D_803E4C5C = (D_803E4C94->xPos.w + D_803E4C94->unk18.w);
//         D_803E4C60 = D_803E4C94->zPos.w;
//         D_803E4C7C = D_803E4C94->unk18.w;
//         D_803E4C80 = 0;
//         D_803E4C56 = D_803E4C5C >> 0x10;
//         D_803E4C58 = D_803E4C60 >> 0x10;
//         D_803E4C78 = (u8) D_803E4C94->unk160;
//         D_803E4C6C = (D_803E4C5C >> 0x10) >> 6;
//         D_803E4C6E = (D_803E4C60 >> 0x10) >> 6;
//         D_803E4C74 = (D_803E4C5C >> 0x10) & 0x3F;
//         D_803E4C76 = (D_803E4C60 >> 0x10) & 0x3F;
//         sp20 = phi_a3_2;
//         if (phi_a3_2 == 0) {
//             sp1C = phi_a3_2;
//             sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
//         }
//         sp1C = phi_a3_2;
//         phi_a3_2 = phi_a3_2;
//         if ((func_8030B494_71CB44() == 0) &&
//             ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
//             ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
//             ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
//             ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
//             ((u8)sp20 != 0)) {
//             D_803E4C60 = D_803E4C94->zPos.w;
//             func_8030E208_71F8B8();
//             func_80313064_724714();
//         } else {
//             D_803E4C5C = D_803E4C94->xPos.w;
//             D_803E4C60 = (D_803E4C94->zPos.w + D_803E4C94->zVelocity.w);
//             D_803E4C7C = 0;
//             D_803E4C80 = D_803E4C94->zVelocity.w;
//             D_803E4C56 = (D_803E4C5C >> 0x10);
//             D_803E4C58 = (D_803E4C60 >> 0x10);
//             D_803E4C78 = (u8) D_803E4C94->unk160;
//             D_803E4C6C = (D_803E4C56 >> 6);
//             D_803E4C6E = (D_803E4C58 >> 6);
//             D_803E4C74 = (D_803E4C56 & 0x3F);
//             D_803E4C76 = (D_803E4C58 & 0x3F);
//             sp20 = phi_a3_2;
//             if (sp20 == 0) {
//                 sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
//             }
//             if ((func_8030B494_71CB44() == 0) &&
//                 ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
//                 ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
//                 ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
//                 ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
//                 ((u8)sp20 != 0)) {
//                 D_803E4C5C = D_803E4C94->xPos.w;
//                 func_8030E208_71F8B8();
//                 func_80312D94_724444();
//             } else {
//                 func_8030E69C_71FD4C();
//                 func_80313334_7249E4();
//             }
//         }
//     } else if ((sp2E != 1) &&
//                (sp26 != 1) &&
//                (sp2C != 1) &&
//                (sp2A != 1) &&
//                (sp28 != 1)) {
//
//         D_803E4C5C = (D_803E4C94->xPos.w + D_803E4C94->unk18.w);
//         D_803E4C60 = D_803E4C94->zPos.w;
//         D_803E4C7C = D_803E4C94->unk18.w;
//         D_803E4C80 = 0;
//         D_803E4C56 = (D_803E4C5C >> 0x10);
//         D_803E4C58 = (D_803E4C60 >> 0x10);
//         sp20 = phi_a3_2;
//         D_803E4C78 = (u8) D_803E4C94->unk160;
//         D_803E4C6C = (D_803E4C56 >> 6);
//         D_803E4C6E = (D_803E4C58 >> 6);
//         D_803E4C74 = (D_803E4C56 & 0x3F);
//         D_803E4C76 = (D_803E4C58 & 0x3F);
//         if (phi_a3_2 == 0) {
//             sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
//         }
//         if ((func_8030B494_71CB44() == 0) &&
//             ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
//             ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
//             ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
//             ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
//             ((u8)sp20 != 0)) {
//             D_803E4C60 = D_803E4C94->zPos.w;
//             func_8030E208_71F8B8();
//             func_80313064_724714();
//         } else {
//             func_8030E69C_71FD4C();
//             func_80313334_7249E4();
//         }
//     } else if ((sp2E != 2) &&
//                (sp26 != 2) &&
//                (sp2C != 2) &&
//                (sp2A != 2) &&
//                (sp28 != 2)) {
//
//         D_803E4C5C = D_803E4C94->xPos.w;
//         D_803E4C60 = (D_803E4C94->zPos.w + D_803E4C94->zVelocity.w);
//         D_803E4C7C = 0;
//         D_803E4C80 = D_803E4C94->zVelocity.w;
//         D_803E4C56 = D_803E4C5C >> 0x10;
//         D_803E4C58 = D_803E4C60 >> 0x10;
//         D_803E4C78 = (u8) D_803E4C94->unk160;
//         D_803E4C6C = (D_803E4C5C >> 0x10) >> 6;
//         D_803E4C6E = (D_803E4C60 >> 0x10) >> 6;
//         D_803E4C74 = (D_803E4C5C >> 0x10) & 0x3F;
//         D_803E4C76 = (D_803E4C60 >> 0x10) & 0x3F;
//         sp20 = phi_a3_2;
//         if (phi_a3_2 == 0) {
//             sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
//         }
//         if ((func_8030B494_71CB44() == 0) &&
//             ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
//             ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
//             ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
//             ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
//             ((u8)sp20 != 0)) {
//             D_803E4C5C = D_803E4C94->xPos.w;
//             func_8030E208_71F8B8();
//             func_80312D94_724444();
//         } else {
//             func_8030E69C_71FD4C();
//             func_80313334_7249E4();
//         }
//     } else {
//         func_8030E69C_71FD4C(); // sp2E
//         func_80313334_7249E4();
//     }
//     return D_803E4C84;
// }

s32 func_8030B494_71CB44(void) {
    s16 sp3E;
    s16 sp3C;
    s16 sp3A; // pad
    s16 sp38; // pad
    s16 sp36;
    s16 ret = 0;


    if ((D_803E4C68 != D_803E4C6C) || (D_803E4C6A != D_803E4C6E)) {
        if (D_803E4C6A == D_803E4C6E) {
            if (D_803E4C68 < D_803E4C6C) {
                sp3C = (((D_803E4C76 * D_803E4C74) + (D_803E4C72 * (0x40 - D_803E4C70))) / (D_803E4C74 + (0x40 - D_803E4C70)));
                sp3E = 0;
                sp36 = 1;
            } else {
                sp3C = (((D_803E4C76 * (0x40 - D_803E4C74)) + (D_803E4C72 * D_803E4C70)) / ((0x40 - D_803E4C74) + D_803E4C70));
                sp3E = 0x3F;
                sp36 = 2;
            }
        } else {
            if (D_803E4C68 == D_803E4C6C) {
                if (D_803E4C6A < D_803E4C6E) {
                    sp3E = ((D_803E4C74 * D_803E4C76) + (D_803E4C70 * (0x40 - D_803E4C72))) / (D_803E4C76 + (0x40 - D_803E4C72));
                    sp3C = 0;
                    sp36 = 3;
                } else {
                    sp3E = ((D_803E4C74 * (0x40 - D_803E4C76)) + (D_803E4C70 * D_803E4C72)) / ((0x40 - D_803E4C76) + D_803E4C72);
                    sp3C = 0x3F;
                    sp36 = 4;
                }
                // sp3E = var_a2;
                // goto block_19;
            }
            else if (D_803E4C6A < D_803E4C6E) {
                if (D_803E4C68 < D_803E4C6C) {
                    sp36 = 5;
                    sp3E = 0;
                    sp3C = 0;
                } else {
                    sp36 = 6;
                    sp3E = 0x3F;
                    sp3C = 0;
                }
            }

            else if (D_803E4C68 < D_803E4C6C) {
                sp36 = 7;
                sp3E = 0;
                sp3C = 0x3F;
            } else {
                sp36 = 8;
                sp3E = 0x3F;
                sp3C = 0x3F;
            }
        }

        ret = func_8030BE20_71D4D0(sp36, sp3E, sp3C);
        if (ret != 0) {
            return ret;
        }

        switch (D_803E4C94->unk160) {                        /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if ((D_803C0740[D_803E4C6C][D_803E4C6E].unk3) != 0) {
                if (func_8030BC50_71D300(D_803E4C6C, D_803E4C6E, sp3E, sp3C, &D_803E4C78) != 0) {
                    if ((sp36 != 3) && (sp36 != 4)) {
                        ret = 1;
                    }
                    if ((sp36 != 1) && (sp36 != 2)) {
                        ret = 2;
                    }
                }
            }
            break;
        case 1:
            if (D_803C0740[D_803E4C6C][D_803E4C6E].unk3 == 0) {
                switch (sp36) {
                case 1:
                    if (func_8030BD50_71D400(D_803E4C6C - 1, D_803E4C6E, 0x3F, sp3C, &D_803E4C94->unk160) != 0) {
                        ret = 1;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 2:
                    if (func_8030BD50_71D400(D_803E4C6C + 1, D_803E4C6E, 0, sp3C, &D_803E4C79) != 0) {
                        ret = 1;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 3:
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E - 1, sp3E, 0x3F, &D_803E4C79) != 0) {
                        ret = 2;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 4:
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E + 1, sp3E, 0, &D_803E4C79) != 0) {
                        ret = 2;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 5:
                    if (func_8030BD50_71D400(D_803E4C6C - 1, D_803E4C6E - 1, 0x3F, 0x3F, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 6:
                    if (func_8030BD50_71D400(D_803E4C6C + 1, D_803E4C6E - 1, 0, 0x3F, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 7:
                    if (func_8030BD50_71D400(D_803E4C6C - 1, D_803E4C6E + 1, 0x3F, 0, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 8:
                    if (func_8030BD50_71D400(D_803E4C6C + 1, D_803E4C6E + 1, 0, 0, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                }
            }
            break;
        case 2:
            if ((D_803C0740[D_803E4C6C][D_803E4C6E].unk3) == 0) {
                if (D_803E4C94->unk163 & 2) {
                    if (((func_8031124C_7228FC(D_803E4C56, D_803E4C58) >> 0x10) - (func_80310F58_722608(D_803E4C52, D_803E4C54) >> 0x10)) < -9) {
                        ret = 3;
                    }
                }
                D_803E4C78 = 0;
            }
            break;
        }
    }

    return ret;
}

s32 func_8030BC50_71D300(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4) {
    s16 phi_v0;

    s32 sp20;
    s32 sp1C;

    phi_v0 = D_803E4C94->yPos.h;
    func_80311554_722C04((arg0 << 6) + arg2, (arg1 << 6) + arg3, &sp1C, &sp20);

    sp20 = sp20 >> 16;
    sp1C = sp1C >> 16;

    if (phi_v0 < sp20) {
        phi_v0 = sp20;
    }

    if ((phi_v0 + 10) > sp1C) {
        *arg4 = 2;
        return 0;
    }

    if ((phi_v0 + D_803E4C94->unk42) < sp1C) {
        *arg4 = 1;
        return 0;
    }
    return 1;
}

s32 func_8030BD50_71D400(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4) {
    s16 temp_v1;
    s16 temp_a2;

    s16 temp_a0;
    s16 temp_a1;

    temp_a0 = (arg0 << 6) + arg2;
    temp_a1 = (arg1 << 6) + arg3;

    temp_v1 = D_803E4C94->yPos.h;
    temp_a2 = func_8031124C_7228FC(temp_a0, temp_a1) >> 0x10;

    if (temp_v1 < temp_a2) {
        temp_v1 = temp_a2;
    }

    if ((s16) (func_80310F58_722608(temp_a0, temp_a1) >> 0x10) < (temp_v1 + D_803E4C94->unk42)) {
        return 1;
    }
    return 0;
}

s16 func_8030BE20_71D4D0(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;
    s16 var_t1;
    s16 var_a1;
    s16 var_v0;
    s16 temp_t8;


    temp_v0 = D_803E4C94->yPos.h;

    switch (arg0) {
    case 1:
        temp_t8 = ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - arg2)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg2)) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg2) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - arg2))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * (0x40 - arg2)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * arg2)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, temp_t8 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, temp_t8 + (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
        return 0;

    case 2:
        temp_t8 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg2)) + (D_803C0740[D_803E4C68][D_803E4C6A+1].unk1 * arg2)) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68][D_803E4C6A+1].unk1 * arg2) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg2))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - arg2)) + (D_803C0740[D_803E4C68][D_803E4C6A+1].unk0 * arg2)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
        return 0;

    case 3:
        temp_t8 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg1)) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg1) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - arg1))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * arg1)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }

        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
        return 0;

    case 4:
        temp_t8 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * arg1) ) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * arg1) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg1))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * arg1)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
        return 0;
    case 5:

        temp_t8 = D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * 8;

        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }

        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    case 6:

        temp_t8 = D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * 8;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    case 7:
        temp_t8 = D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * 8;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    case 8:
        temp_t8 = D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * 8;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030DD34_71F3E4.s")
// long way to go here...
// void func_8030DD34_71F3E4(void) {
//     s32 sp5C;
//     s32 sp58;
//     s32 sp54;
//     s32 sp50;
//     s32 sp4C;
//     s32 sp48;
//
//     s32 var_t0;
//     s32 var_t1;
//
//     Animal *var_v1;
//
//     D_803E4C84 = 1;
//     D_803E4C88 = NULL;
//     D_803E4C8C = NULL;
//     D_803E4C90 = NULL;
//
//     D_803E4C7A = 0;
//     D_803E4C86 = 0;
//
//     var_v1 = NULL;
//     var_t0 = 0;
//     var_t1 = 0x7FFF8000;
//
//     if (D_803E4C94->unk4C.unk27) { //  & 0x10
//         sp50 = 0x7FFF8000; // FTOFIX32(32767.5) ?
//
//         if (((!D_803E4C8C->unk16C) && (!D_803E4C8C->unk16C)) && (!D_803E4C8C->unk16C)) {};
//         sp54 = 0;
//         func_8029B000_6AC6B0((s16) (D_803E4C5C >> 0x10), (s16) (D_803E4C60 >> 0x10), (D_803E4C94->unk42 << 0xF) + D_803E4C64, D_803E4C94, D_803E4C94->unk68, &D_803E4C88, &sp4C, D_803E4C94->unk70, &D_803E4C8C, &sp48);
//         var_v1 = D_803E4C8C;
//         var_t0 = sp54;
//         var_t1 = sp50;
//     }
//     if (D_803E4C88 != NULL) {
//         var_t0 = sp4C;
//     }
//     if (var_v1 != NULL) {
//         var_t1 = sp48;
//     }
//
//     switch (D_803E4C78) {                              /* irregular */
//     case 0:
//         sp54 = var_t0;
//         sp50 = var_t1;
//         sp5C = func_8031124C_7228FC(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10) - (D_803E4C94->unk4C.unk16 << 0x10);
//         if (sp5C >= var_t0) {
//             var_t0 = sp5C;
//         }
//         break;
//     case 1:
//         sp54 = var_t0;
//         sp50 = var_t1;
//
//         func_80311554_722C04(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10, &sp58, &sp5C);
//         var_t0 = sp54;
//         var_t1 = sp50;
//         sp5C -= D_803E4C94->unk4C.unk16 << 0x10;
//         if (D_803C0740[D_803E4C5C >> 0x16][D_803E4C60 >> 0x16].unk4 & 4) {
//             sp58 -= D_803E1D30[D_803C0740[D_803E4C5C >> 0x16][D_803E4C60 >> 0x16].unk3].unk2 << 0x13;
//         }
//         if (var_t0 < sp5C) {
//             var_t0 = sp5C;
//         }
//         if (sp58 < var_t1) {
//             var_t1 = sp58;
//         }
//         break;
//     case 2:
//         sp54 = var_t0;
//         sp50 = var_t1;
//         sp58 = func_80310F58_722608(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10);
//         sp58 = sp58 - (D_803E4C94->unk4C.unk16 << 0x10);
//         if (sp58 >= var_t0) {
//             var_t0 = sp58;
//         }
//         break;
//     }
//
//     if ((var_t1 - var_t0) < (D_803E4C94->unk42 << 0x10)) {
//         D_803E4C84 = 0;
//         D_803E4C64 = var_t0;
//
//         if (((var_t0 != sp4C) || (D_803E4C88 == NULL) || (D_803E4C88->unk16C->unk2 != 5)) && ((var_t1 != sp48) || (D_803E4C8C == NULL) || (D_803E4C8C->unk16C->unk2 != 5))) {
//             D_803E4C86 = 0x40 - (((var_t1 - var_t0) >> 0xA) / D_803E4C94->unk42);
//         }
//         if ((D_803E4C88 != NULL) && (var_t0 == sp4C)) {
//             D_803E4C7A = 1;
//             D_803E4C90 = D_803E4C94->unk68;
//         }
//     } else {
//         if (var_t1 < ((D_803E4C94->unk42 << 0x10) + D_803E4C64)) {
//             D_803E4C84 = 2;
//             D_803E4C64 = var_t1 - (D_803E4C94->unk42 << 0x10);
//         } else if (D_803E4C64 < var_t0) {
//             D_803E4C64 = var_t0;
//             D_803E4C84 = 0;
//             if ((D_803E4C88 != NULL) && (var_t0 == sp4C)) {
//                 D_803E4C7A = 1;
//                 D_803E4C90 = D_803E4C88;
//             }
//         }
//     }
// }

void func_8030E208_71F8B8(void) {
    u8  pad;
    u8  sp3E; // FIXME: this should be s16

    func_8030DD34_71F3E4();
    if (func_802B75CC_6C8C7C(D_803E4C94, 0, D_803E4C5C, D_803E4C60, D_803E4C64, &sp3E, 0) == 0) {
        D_803E4C94->xPos.w = D_803E4C5C;
        D_803E4C94->zPos.w = D_803E4C60;
        D_803E4C94->yPos.w = D_803E4C64;
        D_803E4C94->unk160 = D_803E4C78;
        D_803E4C94->unk161 = D_803E4C7A;
        if ((D_803E4C86 >= 0x20) && (D_803E4C94->unk4B < 0x20)) {
            play_sound_effect_at_location(0x17, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
        D_803E4C94->unk4B = D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = (Animal *) D_803E4C90;
        if (D_803E4C90 != NULL) {
            func_802FD674_70ED24(D_803E4C94, (Animal *) D_803E4C90);
        } else {
            if (D_803E4C84 == 0) {
                D_803E4C94->unk54 |= 0xA; //var_t3;
            } else if (D_803E4C84 == 2) {
                D_803E4C94->unk54 |= 0xA;
            }
        }
    } else if (sp3E == 0) {
        D_803E4C94->xPos.w = D_803E4C5C;
        D_803E4C94->zPos.w = D_803E4C60;
        D_803E4C94->yPos.w = D_803E4C64 + D_803A05B4_7B1C64;
        D_803E4C94->unk160 = D_803E4C78;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = (u8) D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = (Animal *) D_803E4C90;
        if (D_803E4C90 != NULL) {
            func_802FD674_70ED24(D_803E4C94, (Animal *) D_803E4C90);
        } else if (D_803E4C84 == 0) {
            D_803E4C94->unk54 |= 0xA;
        }
    } else {
        D_803E4C5C = D_803E4C94->xPos.w;
        D_803E4C60 = D_803E4C94->zPos.w;
        D_803E4C64 = D_803E4C94->yPos.w;
        D_803E4C78 = D_803E4C94->unk160;
        D_803E4C94->xVelocity.w = 0;
        D_803E4C94->zVelocity.w = 0;
        D_803E4C94->yVelocity.w = 0;
        func_8030DD34_71F3E4();
        D_803E4C94->xPos.w = D_803E4C5C;
        D_803E4C94->zPos.w = D_803E4C60;
        D_803E4C94->yPos.w = D_803E4C64;
        D_803E4C94->unk160 = D_803E4C78;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = (u8) D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = (Animal *) D_803E4C90;
        if (D_803E4C90 != NULL) {
            func_802FD674_70ED24(D_803E4C94, (Animal *) D_803E4C90);
        } else {
            if (D_803E4C84 == 0) {
                D_803E4C94->unk54 |= 0xA;
            } else if (D_803E4C84 == 2) {
                D_803E4C94->unk54 |= 0xA;
            }
        }
    }
    if (D_803E4C94->unk4B > 0) {
        if ((D_803E4C94->unk70 != NULL) && (D_803E4C94->unk70->unk4C.unk29)) { //  & 4
            D_803E4C94->unk70->yVelocity.w += D_803E4C94->unk4B << 0xA;
        }
    }
    if ((D_803E4C94->unk6C != NULL) && (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        if (D_803E4C94->unk6C->unk16C->objectType == 54) {
            func_8029B870_6ACF20(D_803E4C94, D_803E4C94->unk6C);
        }
        if ( D_803E4C94->unk6C->unk16C->objectType == OBJECT_TELEPORTER_ACTIVE) {
            func_8029BA70_6AD120(D_803E4C94, D_803E4C94->unk6C);
        }
    }
}

void func_8030E69C_71FD4C(void) {
    D_803E4C5C = D_803E4C94->xPos.w;
    D_803E4C60 = D_803E4C94->zPos.w;
    D_803E4C64 = D_803E4C94->yPos.w + D_803E4C94->yVelocity.w;
    D_803E4C78 = D_803E4C94->unk160;
    func_8030DD34_71F3E4();
    D_803E4C94->xPos.w = D_803E4C5C;
    D_803E4C94->zPos.w = D_803E4C60;
    D_803E4C94->yPos.w = D_803E4C64;
    D_803E4C94->unk160 = D_803E4C78;
    D_803E4C94->unk161 = D_803E4C7A;
    D_803E4C94->unk4B = D_803E4C86;
    D_803E4C94->unk68 = D_803E4C88;
    D_803E4C94->unk70 = D_803E4C8C;
    D_803E4C94->unk6C = D_803E4C90;

    if (D_803E4C90 != 0) {
        func_802FD674_70ED24(D_803E4C94, D_803E4C90);
    } else {
        if (D_803E4C84 == 0) {
            D_803E4C94->unk54 |= 0xA;
        } else if (D_803E4C84 == 2) {
            D_803E4C94->unk54 |= 0xA;
        }
    }

    if (D_803E4C94->unk4B > 0) {
        if ((D_803E4C94->unk70 != 0) && (D_803E4C94->unk70->unk4C.unk29)) {
            D_803E4C94->unk70->yVelocity.w += D_803E4C94->unk4B << 0xA;
        }
    }

    if ((D_803E4C94->unk6C != NULL) && (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        if (D_803E4C94->unk6C->unk16C->objectType == 54) {
            func_8029B870_6ACF20(D_803E4C94, D_803E4C94->unk6C);
        }
        if (D_803E4C94->unk6C->unk16C->objectType == OBJECT_TELEPORTER_ACTIVE) {
            func_8029BA70_6AD120(D_803E4C94, D_803E4C94->unk6C);
        }
    }
}

s16 func_8030E8AC_71FF5C(struct071 *arg0) {
    u8 pad;
    u8 sp2E;

    D_803E4C94 = arg0;
    D_803E4C5C = D_803E4C94->xPos.w;
    D_803E4C60 = D_803E4C94->zPos.w;
    D_803E4C64 = D_803E4C94->yPos.w + D_803E4C94->yVelocity.w;
    D_803E4C56 = D_803E4C5C >> 16;
    D_803E4C58 = D_803E4C60 >> 16;
    D_803E4C78 = D_803E4C94->unk160;
    func_8030DD34_71F3E4();
    if ((func_802B75CC_6C8C7C(D_803E4C94, 0, D_803E4C5C, D_803E4C60, D_803E4C64, &sp2E, 0) == 0) || (sp2E != 0)) {
        D_803E4C94->yPos.w = D_803E4C64;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = D_803E4C90;
        if (D_803E4C90 != 0) {
            func_802FD674_70ED24(D_803E4C94, D_803E4C90);
        }
    } else {
        D_803E4C94->yPos.w = (D_803E4C64 + D_803A05B4_7B1C64);
        D_803E4C94->yVelocity.w = 0;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = D_803E4C90;
        if (D_803E4C90 != 0) {
            func_802FD674_70ED24(D_803E4C94, D_803E4C90);
        }
    }
    return D_803E4C84;
}

s32 func_8030EA98_720148(void) {
    s32 sp24;
    s32 sp20;
    s32 phi_v1;

    if (D_803E4C78 == 1) {
        func_80311554_722C04(D_803E4C56, D_803E4C58, &sp24, &sp20);
        if (D_803C0740[D_803E4C6C][D_803E4C6E].unk4 & 4) {
            phi_v1 = D_803E1D30[D_803C0740[D_803E4C6C][D_803E4C6E].unk3].unk2 << 3;
        } else {
            phi_v1 = 0;
        }
        if ((((sp24 - sp20) - phi_v1) >> 16) < D_803E4C94->unk42) {
            return 3;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s32 func_8030EB88_720238(s16 arg0, s16 arg1) {
    s32 pad;
    s32 sp20;
    s32 sp1C;

    func_80311554_722C04(arg0, arg1, &sp20, &sp1C);
    if (((sp20 - sp1C) >> 16) < D_803E4C94->unk42) {
        return 3;
    }
    return 0;
}

s32 func_8030EBF0_7202A0(void) {
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    u8 sp37;

    func_80311A2C_7230DC(D_803E4C56, D_803E4C58, &sp3A, &sp38, D_803E4C78);

    if ((((D_803E4C94->unk162 & 0xF) != 1) && ((D_803E4C94->unk162 & 0xF) != 6)) || (D_803E4C94->unk161 == 0)) {
        sp38 = 0;
        sp3A = 0;
    }

    if ((D_803E4C7C > 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) {
        if ((D_803E4C74 + D_803E4C94->unk30) >= 0x40) {
            sp37 = D_803E4C78;
            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C+1][D_803E4C6E].unk3) != 0) && (func_8030BC50_71D300((s16) (D_803E4C6C + 1), D_803E4C6E, 0, D_803E4C76, &sp37) != 0)) {
                    return 1;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C+1][D_803E4C6E].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, 0x3F, D_803E4C76, &sp37) != 0) {
                        return 1;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C+1][D_803E4C6E].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC((s16) ((D_803E4C56 & 0xFFC0) + 0x41), D_803E4C58) >> 0x10) - (func_80310F58_722608((D_803E4C52 & 0xFFC0) + 0x3F, D_803E4C54) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56 + D_803E4C94->unk30, D_803E4C58) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, sp37) >> 0x10)) && (D_803E4C7C != 0) && (sp3E < -0x17) && (sp3E < sp3A)) {
              return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E >= 0x18) && (sp3A < sp3E)) {
              return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56 + D_803E4C94->unk30, D_803E4C58) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, D_803E4C78) >> 0x10)) && (D_803E4C7C != 0) && (sp3E < -0x17) && (sp3E < sp3A)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E >= 0x18) && (sp3A < sp3E)) {
                return 3;
            }
        }
    }

    if ((D_803E4C7C < 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) {
        if ((D_803E4C74 - D_803E4C94->unk30) < 0) {
            sp37 = D_803E4C78;
            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C - 1][D_803E4C6E].unk3) != 0) && (func_8030BC50_71D300(D_803E4C6C - 1, D_803E4C6E, 0x3F, D_803E4C76, &sp37) != 0)) {
                    return 1;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C - 1][D_803E4C6E].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, 0, D_803E4C76, &sp37) != 0) {
                        return 1;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C - 1][D_803E4C6E].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC((s16) ((D_803E4C56 & 0xFFC0) - 1), D_803E4C58) >> 0x10) - (func_80310F58_722608((s16) ((D_803E4C52 & 0xFFC0) + 1), D_803E4C54) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56 - D_803E4C94->unk30, D_803E4C58) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, sp37) >> 0x10)) && (D_803E4C7C != 0) && (sp3E >= 0x18) && (sp3A < sp3E)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E < -0x17) && (sp3E < sp3A)) {
                return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56 - D_803E4C94->unk30, D_803E4C58) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, D_803E4C78) >> 0x10)) && (D_803E4C7C != 0) && (sp3E >= 0x18) && (sp3A < sp3E)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E < -0x17) && (sp3E < sp3A)) {
                return 3;
            }
        }
    }

    if ((D_803E4C80 > 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) {
        if ((D_803E4C76 + D_803E4C94->unk32) >= 0x40) {
            sp37 = D_803E4C78;

            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C][D_803E4C6E+1].unk3) != 0) && (func_8030BC50_71D300(D_803E4C6C, (s16) (D_803E4C6E + 1), D_803E4C74, 0, &sp37) != 0)) {
                    return 2;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E+1].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, D_803E4C76 , 0x3F, &sp37) != 0) {
                        return 2;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E+1].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC(D_803E4C56, (s16) ((D_803E4C58 & 0xFFC0) + 0x41)) >> 0x10) - (func_80310F58_722608(D_803E4C52, (s16) ((D_803E4C54 & 0xFFC0) + 0x3F)) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56, D_803E4C58 + D_803E4C94->unk32) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, sp37) >> 0x10)) && (D_803E4C80 != 0) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56, D_803E4C58 + D_803E4C94->unk32) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, D_803E4C78) >> 0x10)) && (D_803E4C80 != 0) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
        }
    }

    if ((D_803E4C80 < 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) {
        if ((D_803E4C76 - D_803E4C94->unk32) < 0) {
            sp37 = D_803E4C78;
            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C][D_803E4C6E - 1].unk3) != 0) && (func_8030BC50_71D300(D_803E4C6C, D_803E4C6E - 1, D_803E4C74, 0x3F, &sp37) != 0)) {
                    return 2;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E-1].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, D_803E4C74, 0, &sp37) != 0) {
                        return 2;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E-1].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC(D_803E4C56, (s16) ((D_803E4C58 & 0xFFC0) - 1)) >> 0x10) - (func_80310F58_722608(D_803E4C52, (s16) ((D_803E4C54 & 0xFFC0) + 1)) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56, D_803E4C58 - D_803E4C94->unk32) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, sp37) >> 0x10)) && (D_803E4C80 != 0) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56, D_803E4C58 - D_803E4C94->unk32) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, D_803E4C78) >> 0x10)) && (D_803E4C80 != 0) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
        }
    }

    return 0;
}

s32 func_80310030_7216E0(void) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;

    s32 pad;

    func_80311A2C_7230DC(D_803E4C52, D_803E4C54, &sp32, &sp30, D_803E4C94->unk160);

    if ((((D_803E4C94->unk162 & 0xF) != 1) && ((D_803E4C94->unk162 & 0xF) != 6)) || (D_803E4C94->unk161 == 1)) {
        sp30 = 0;
        sp32 = 0;
    }
    func_80311A2C_7230DC(D_803E4C56, D_803E4C58, &sp36, &sp34, D_803E4C78);
    if ((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58, D_803E4C78) >> 0x10)) {
        if (((D_803E4C7C > 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) && (sp36 < -0x17) && (sp36 < sp32)) {
            return 3;
        }
        if (((D_803E4C7C < 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) && (sp36 >= 0x18) && (sp32 < sp36)) {
            return 3;
        }
        if (((D_803E4C80 > 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) && (sp34 < -0x17) && (sp34 < sp30)) {
            return 3;
        }
        if (((D_803E4C80 < 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) && (sp34 >= 0x18) && (sp30 < sp34)) {
            return 3;
        }
    }

    if ((D_803E4C94->unk163 & 2) != 0) {
        if ((D_803E4C7C >= 0) && (sp36 >= 0x18) && (sp32 < sp36)) {
            return 3;
        }
        if ((D_803E4C7C <= 0) && (sp36 < -0x17) && (sp36 < sp32)) {
            return 3;
        }
        if ((D_803E4C80 >= 0) && (sp34 >= 0x18) && (sp30 < sp34)) {
            return 3;
        }
        if ((D_803E4C80 <= 0) && (sp34 < -0x17) && (sp34 < sp30)) {
            return 3;
        }
    }
    return 0;
}

s16 func_803102BC_72196C(void) {
    s16 var_t1;
    s16 var_a2;
    s16 sp12;
    s16 var_v1;
    s16 temp_t7;
    u8 spD;


    sp12 = D_803E4C94->yPos.h;
    spD = 0;

    if ((D_803E4C94->unk162 == 1) && (D_803E4C94->unk6C == NULL)) {
        if (D_803E4C78 == 2) {
            if (D_803E1D30[D_803C0740[D_803E4C56 >> 6][D_803E4C58 >> 6].unk3].unk0 == 0) {
                spD = 1;
            }
        } else if (D_803E1D30[D_803C0740[D_803E4C56 >> 6][D_803E4C58 >> 6].unk2].unk0 == 0) {
            spD = 1;
        }
    }

    if (((D_803E4C7C > 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0) && (spD == 0))) && ((D_803E4C74 + D_803E4C94->unk30) >= 0x40)) {

        temp_t7 = ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3;

        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * D_803E4C72)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3);
        }

        // store originals
        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }

        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
    }

    if (((D_803E4C7C < 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0) && (spD == 0))) && ((D_803E4C74 - D_803E4C94->unk30) < 0)) {
        temp_t7 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3;
        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * D_803E4C72)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3);
        }

        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
    }

    if (((D_803E4C80 > 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0) && (spD == 0))) && ((D_803E4C76 + D_803E4C94->unk32) >= 0x40)) {
        temp_t7 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C70)) >> 3;
        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * D_803E4C70)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C70)) >> 3);
        }

        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }

        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
    }

    if (((D_803E4C80 < 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0) && (spD == 0))) && ((D_803E4C76 - D_803E4C94->unk32) < 0)) {
        temp_t7 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * D_803E4C70)) >> 3;
        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * D_803E4C70)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * D_803E4C70)) >> 3);
        }

        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }

        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
    }

    return 0;
}

s32 func_80310E10_7224C0(s16 arg0, s16 arg1) {
    s16 i;

    if ((D_803E4C94->unk18C == 0) || ((D_803E4C94->unk163 & 4) == 0)) {
        return 1;
    }

    for (i = 0; i < D_803E4C94->unk18C; i++) {
        if ((arg0 >= D_803E93B0[D_803E4C94->unk18D[i]].unk0) && (arg0 <= D_803E93B0[D_803E4C94->unk18D[i]].unk3) &&
            (arg1 >= D_803E93B0[D_803E4C94->unk18D[i]].unk1) && (arg1 <= D_803E93B0[D_803E4C94->unk18D[i]].unk4)) {
            return 1;
        }
    }
    return 0;
}

s32 func_80310EE4_722594(s16 x, s16 z, u8 arg2) {
    switch (arg2) {
    case 0:
    case 1:
        return func_8031124C_7228FC(x, z);
    case 2:
        return func_80310F58_722608(x, z);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80310F58_722608.s")
// same regalloc as next few funcs
// s32 func_80310F58_722608(s16 arg0, s16 arg1) {
//     s16 temp_t0;
//     s16 temp_v0;
//
//     s32 temp_t3;
//     s32 temp_t4;
//     s32 temp_t5;
//     s32 temp_t6;
//     s32 temp_t6_2;
//     s32 temp_t9;
//
//     s16 temp_v0_2;
//     s16 temp_v1;
//
//     if (D_803C0740[(s16)(arg0 >> 6)][(s16)(arg1 >> 6)].unk3 == 0) {
//         return 0x40000000;
//     }
//     if ((s16)(arg0 >> 6) < 0) {
//         return D_803C0740[0][MIN(MAX(0, (s16)(arg1 >> 6)), 128)].unk1 << 0x13;
//     }
//     if ((s16)(arg0 >> 6) >= 0x48) {
//         return D_803C0740[0][MIN(MAX(0, (s16)(arg1 >> 6)), 128)].unk1 << 0x13;
//     }
//     if ((s16)(arg1 >> 6) < 0) {
//         return D_803C0740[(s16)(arg0 >> 6)][0].unk1 << 0x13;
//     }
//     if ((s16)(arg1 >> 6) >= 0x80) {
//         return D_803C0740[(s16)(arg0 >> 6)+1][-1].unk1 << 0x13;
//     }
//
//     temp_v0 = arg0 & 0x3F;
//     temp_t0 = arg1 & 0x3F;
//
//     if (D_803C0740[(s16)(arg0 >> 6)][(s16)(arg1 >> 6)].unk4 & 2) {
//         if (temp_v0 < temp_t0) {
//             temp_t3 = D_803C0740[(s16)(arg0 >> 6)+0][(s16)(arg1 >> 6)+0].unk1 << 0xD;
//             temp_t4 = D_803C0740[(s16)(arg0 >> 6)+0][(s16)(arg1 >> 6)+1].unk1 << 0xD;
//             return (temp_t3 << 6) + (((D_803C0740[(s16)(arg0 >> 6)+1][(s16)(arg1 >> 6)+1].unk1 << 0xD) - temp_t4) * temp_v0) + ((temp_t4 - temp_t3) * temp_t0);
//         } else {
//             temp_t5 = D_803C0740[(s16)(arg0 >> 6)+0][(s16)(arg1 >> 6)+0].unk1 << 0xD;
//             temp_t6_2 = D_803C0740[(s16)(arg0 >> 6)+1][(s16)(arg1 >> 6)+0].unk1 << 0xD;
//             return (temp_t5 << 6) + ((temp_t6_2 - temp_t5) * temp_v0) + (((D_803C0740[(s16)(arg0 >> 6)+1][(s16)(arg1 >> 6)+1].unk1 << 0xD) - temp_t6_2) * temp_t0);
//         }
//     } else if ((temp_v0 + temp_t0) < 0x40) {
//         temp_t9 = D_803C0740[(s16)(arg0 >> 6)+0][(s16)(arg1 >> 6)+0].unk1 << 0xD;
//         return (temp_t9 << 6) + (((D_803C0740[(s16)(arg0 >> 6)+1][(s16)(arg1 >> 6)].unk1 << 0xD) - temp_t9) * temp_v0) + (((D_803C0740[(s16)(arg0 >> 6)][(s16)(arg1 >> 6)+1].unk1 << 0xD) - temp_t9) * temp_t0);
//     } else {
//         temp_t6 = D_803C0740[(s16)(arg0 >> 6)+1][(s16)(arg1 >> 6)+1].unk1 << 0xD;
//         return (temp_t6 << 6) + (((D_803C0740[(s16)(arg0 >> 6)][(s16)(arg1 >> 6)+1].unk1 << 0xD) - temp_t6) * (0x40 - temp_v0)) + (((D_803C0740[(s16)(arg0 >> 6)+1][(s16)(arg1 >> 6)].unk1 << 0xD) - temp_t6) * (0x40 - temp_t0));
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8031124C_7228FC.s")
// similar to next function but worse diff
// s32 func_8031124C_7228FC(s16 x, s16 y) {
//     s16 temp_t0;
//     s16 temp_v0;
//
//     s32 temp_t3;
//     s32 temp_t4;
//     s32 temp_t5;
//     s32 temp_t6;
//     s32 temp_t9;
//
//     s16 _x;
//     s16 _y;
//
//     _x = x >> 6;
//     _y = y >> 6;
//
//     if (_x < 0) {
//         return D_803C0740[0][MIN(MAX(0, (s16)(y >> 6)), 128)].unk0 << 0x13;
//     }
//     if (_x >= 0x48) {
//         return D_803C0740[0][MIN(MAX(0, (s16)(y >> 6)), 128)].unk0 << 0x13;
//     }
//     if (_y < 0) {
//         return D_803C0740[_x][0].unk0 << 0x13;
//     }
//     if (_y >= 0x80) {
//         return D_803C0740[_x][0].unk0 << 0x13;
//     }
//
//     temp_v0 = x & 0x3F;
//     temp_t0 = y & 0x3F;
//
//     if (D_803C0740[_x][_y].unk4 & 1) {
//         if (temp_v0 < temp_t0) {
//             temp_t3 = D_803C0740[_x+0][_y+0].unk0 << 0xD;
//             temp_t4 = D_803C0740[_x+0][_y+1].unk0 << 0xD;
//             temp_t6 = D_803C0740[_x+1][_y+1].unk0 << 0xD;
//             return (temp_t3 << 6) + (((temp_t6) - temp_t4) * temp_v0) + ((temp_t4 - temp_t3) * temp_t0);
//         } else {
//             temp_t3 = D_803C0740[_x+0][_y+0].unk0 << 0xD;
//             temp_t5 = D_803C0740[_x+1][_y+0].unk0 << 0xD;
//             temp_t6 = D_803C0740[_x+1][_y+1].unk0 << 0xD;
//             return (temp_t3 << 6) + ((temp_t5 - temp_t3) * temp_v0) + (((temp_t6) - temp_t5) * temp_t0);
//         }
//     } else if ((temp_v0 + temp_t0) < 0x40) {
//         temp_t3 = D_803C0740[_x+0][_y+0].unk0 << 0xD;
//         temp_t5 = D_803C0740[_x+1][_y+0].unk0 << 0xD;
//         temp_t4 = D_803C0740[_x+0][_y+1].unk0 << 0xD;
//         return (temp_t3 << 6) + (((temp_t5) - temp_t3) * temp_v0) + (((temp_t4) - temp_t3) * temp_t0);
//     } else {
//         // temp_t4 = D_803C0740[_x+0][_y+1].unk0 << 0xD;
//         // temp_t5 = D_803C0740[_x+1][_y+0].unk0 << 0xD;
//         temp_t6 = D_803C0740[_x+1][_y+1].unk0 << 0xD;
//         return (temp_t6 << 6) + (((D_803C0740[_x+0][_y+1].unk0 << 0xD) - temp_t6) * (0x40 - temp_v0)) + (((D_803C0740[_x+1][_y+0].unk0 << 0xD) - temp_t6) * (0x40 - (temp_t0)));
//     }
// }

#ifdef NON_MATCHING
// need to figure out all the temp var regalloc fun
void func_80311554_722C04(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3) {
    s16 temp_t0;
    s16 temp_t2;
    s16 temp_t3;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_t9;
    s16 temp_v0;

    temp_v0 = arg0 >> 6;
    if (temp_v0 < 0) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[0][MIN(MAX(0, (s16)(arg1 >> 6)), 128)].unk1 << 0x13;
        return;
    }

    if (temp_v0 >= 0x48) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[0][MIN(MAX(0, (s16)(arg1 >> 6)), 128)].unk1 << 0x13;
        return;
    }

    temp_t3 = arg1 >> 6;
    if (temp_t3 < 0) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[temp_v0][0].unk1 << 0x13;
        return;
    }
    if (temp_t3 >= 0x80) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[temp_v0+1][-1].unk1 << 0x13;
        return;
    }

    temp_t0 = arg0 & 0x3F;
    temp_t2 = arg1 & 0x3F;

    if ((D_803C0740[temp_v0][temp_t3].unk4 & 1) != 0) {
        if (temp_t0 < temp_t2) {
            temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk0 << 0xD;
            temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk0 << 0xD;
            temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk0 << 0xD;
            *arg3 = (temp_t8 << 6) + ((temp_t7 - temp_t9) * temp_t0) + ((temp_t9 - temp_t8) * temp_t2);
        } else {
            temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk0 << 0xD;
            temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk0 << 0xD;
            temp_t9 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk0 << 0xD;
            *arg3 = (temp_t8 << 6) + ((temp_t9 - temp_t8) * temp_t0) + ((temp_t7 - temp_t9) * temp_t2);
        }
    } else if ((temp_t0 + temp_t2) < 0x40) {
        temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk0 << 0xD;
        temp_t7 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk0 << 0xD;
        temp_t9 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk0 << 0xD;
        *arg3 = (temp_t8 << 6) + ((temp_t9 - temp_t8) * temp_t0) + ((temp_t7 - temp_t8) * temp_t2);
    } else {
        temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk0 << 0xD;
        temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk0 << 0xD;
        temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk0 << 0xD;
        *arg3 = (temp_t7 << 6) + ((temp_t9 - temp_t7) * (0x40 - temp_t0)) + ((temp_t6 - temp_t7) * (0x40 - temp_t2));
    }

    if (D_803C0740[temp_v0+0][temp_t3+0].unk3 == 0) {
        *arg2 = 0x40000000;
        return;
    }
    if ((D_803C0740[temp_v0+0][temp_t3+0].unk4 & 2) != 0) {
        if (temp_t0 < temp_t2) {
            temp_t9 = D_803C0740[temp_v0+0][temp_t3+0].unk1 << 0xD;
            temp_t8 = D_803C0740[temp_v0+0][temp_t3+1].unk1 << 0xD;
            temp_t7 = D_803C0740[temp_v0+1][temp_t3+1].unk1 << 0xD;
            *arg2 = (temp_t9 << 6) + ((temp_t7 - temp_t8) * temp_t0) + ((temp_t8 - temp_t9) * temp_t2);
        } else {
            temp_t9 = D_803C0740[temp_v0+0][temp_t3+0].unk1 << 0xD;
            temp_t7 = D_803C0740[temp_v0+1][temp_t3+1].unk1 << 0xD;
            temp_t6 = D_803C0740[temp_v0+1][temp_t3+0].unk1 << 0xD;
            *arg2 = (temp_t9 << 6) + ((temp_t6 - temp_t9) * temp_t0) + ((temp_t7 - temp_t6) * temp_t2);
        }
    } else if ((temp_t0 + temp_t2) < 0x40) {
        temp_t6 = D_803C0740[temp_v0+0][temp_t3+0].unk1 << 0xD;
        temp_t9 = D_803C0740[temp_v0+1][temp_t3+0].unk1 << 0xD;
        temp_t7 = D_803C0740[temp_v0+0][temp_t3+1].unk1 << 0xD;
        *arg2 = (temp_t6 << 6) + ((temp_t9 - temp_t6) * temp_t0) + ((temp_t7 - temp_t6) * temp_t2);
    } else {
        temp_t6 = D_803C0740[temp_v0+0][temp_t3+1].unk1 << 0xD;
        temp_t7 = D_803C0740[temp_v0+1][temp_t3+1].unk1 << 0xD;
        temp_t9 = D_803C0740[temp_v0+1][temp_t3+0].unk1 << 0xD;
        *arg2 = (temp_t7 << 6) + ((temp_t6 - temp_t7) * (0x40 - temp_t0)) + ((temp_t9 - temp_t7) * (0x40 - temp_t2));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80311554_722C04.s")
#endif

void func_80311A2C_7230DC(s16 xPos, s16 zPos, s16 *xVel, s16 *zVel, u8 arg4) {
    switch (arg4) {
    case 1:
        func_80311BF8_7232A8(xPos, zPos, xVel, zVel);
        break;
    case 0:
        func_80311BF8_7232A8(xPos, zPos, xVel, zVel);
        break;
    case 2:
        func_80311AA8_723158(xPos, zPos, xVel, zVel);
        break;
    }
}

void func_80311AA8_723158(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3) {
    s16 x;
    s16 y;

    u8 x0y1;
    u8 x1y1;
    u8 x1y0;
    u8 x0y0;

    *arg2 = *arg3 = 0;

    x = arg0 >> 6;
    y = arg1 >> 6;

    if ((x >= 0) && (x < 72)) {
        if ((y >= 0) && (y < 128)) {
            x0y0 = D_803C0740[x][y].unk1;
            x0y1 = D_803C0740[x][y+1].unk1;
            x1y1 = D_803C0740[x+1][y+1].unk1;
            x1y0 = D_803C0740[x+1][y].unk1;

            if ((D_803C0740[x][y].unk4 & 0x2) != 0) {
                if ((s16)(arg0 & 0x3F) < (s16)(arg1 & 0x3F)) {
                    *arg2 = (x0y1 - x1y1) * 2;
                    *arg3 = (x0y0 - x0y1) * 2;
                } else {
                    *arg2 = (x0y0 - x1y0) * 2;
                    *arg3 = (x1y0 - x1y1) * 2;
                }
            } else if (((s16)(arg0 & 0x3F) + (s16)(arg1 & 0x3F)) < 64) {
                *arg2 = (x0y0 - x1y0) * 2;
                *arg3 = (x0y0 - x0y1) * 2;
            } else {
                *arg2 = (x0y1 - x1y1) * 2;
                *arg3 = (x1y0 - x1y1) * 2;
            }
        }
    }
}

void func_80311BF8_7232A8(s16 xPos, s16 zPos, s16 *xVel, s16 *zVel) {
    u8 x0y1;
    u8 x1y1;
    u8 x1y0;
    u8 x0y0;

    s16 x;
    s16 y;

    *xVel = *zVel = 0;

    x = xPos >> 6;
    y = zPos >> 6;

    if ((x >= 0) && (x < 72) &&
        (y >= 0) && (y < 128)) {

        x0y0 = D_803C0740[x+0][y+0].unk0;
        x0y1 = D_803C0740[x+0][y+1].unk0;
        x1y1 = D_803C0740[x+1][y+1].unk0;
        x1y0 = D_803C0740[x+1][y+0].unk0;
        if (D_803C0740[x][y].unk4 & 0x1) {
            if ((s16) (xPos & 0x3F) < (s16) (zPos & 0x3F)) {
                *xVel = (x0y1 - x1y1) * 2;
                *zVel = (x0y0 - x0y1) * 2;
            } else {
                *xVel = (x0y0 - x1y0) * 2;
                *zVel = (x1y0 - x1y1) * 2;
            }
        } else if (((s16) (xPos & 0x3F) + (s16) (zPos & 0x3F)) < 64) {
            *xVel = (x0y0 - x1y0) * 2;
            *zVel = (x0y0 - x0y1) * 2;
        } else {
            *xVel = (x0y1 - x1y1) * 2;
            *zVel = (x1y0 - x1y1) * 2;
        }
    }
}

s16 func_80311D48_7233F8(Animal *arg0) {
    s16 sp2E;
    s16 sp2C;
    s16 res;

    D_803E4C94 = arg0;
    res = 0;

    func_80311A2C_7230DC(D_803E4C94->xPos.h, D_803E4C94->zPos.h, &sp2E, &sp2C, D_803E4C94->unk160);

    if (D_803E4C94->xVelocity.w > 0) {
        if (sp2E <= -24) {
            func_80312D94_724444();
            res = 1;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2E <= -12) {
                D_803E4C94->xVelocity.w = 0;
            } else if (sp2E < 0) {
                D_803E4C94->xVelocity.w = (D_803E4C94->xVelocity.w * (24 + (sp2E * 2))) / 24;
            }
        }
    } else if (D_803E4C94->xVelocity.w < 0) {
        if (sp2E >= 24) {
            func_80312D94_724444();
            res = 1;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2E >= 12) {
                D_803E4C94->xVelocity.w = 0;
            } else if (sp2E > 0) {
                D_803E4C94->xVelocity.w = (D_803E4C94->xVelocity.w * (24 - (sp2E * 2))) / 24;
            }
        }
    }

    if (D_803E4C94->zVelocity.w > 0) {
        if (sp2C <= -24) {
            func_80313064_724714();
            res = 2;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2C <= -12) {
                D_803E4C94->zVelocity.w = 0;
            } else if (sp2C < 0) {
                D_803E4C94->zVelocity.w = (D_803E4C94->zVelocity.w * (24 + (sp2C * 2))) / 24;
            }
        }
    } else if (D_803E4C94->zVelocity.w < 0) {
        if (sp2C >= 24) {
            func_80313064_724714();
            res = 2;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2C >= 12) {
                D_803E4C94->zVelocity.w = 0;
            } else if (sp2C > 0) {
                D_803E4C94->zVelocity.w = (D_803E4C94->zVelocity.w * (24 - (sp2C * 2))) / 24;
            }
        }
    }
    return res;
}

s32 func_80312054_723704(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x > 71) || (y > 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x - 1][y + 0].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk0 * 8;
    temp_t8 = D_803C0740[x + 0][y + 1].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk1 * 8;
    temp_t8 = D_803C0740[x + 0][y + 1].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x10)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 0x1)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x - 1][y + 0].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x - 1][y + 0].unk5 & 0x20)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x - 1][y + 0].unk5 & 0x2)) && ((var_a3 & 0x80) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

s32 func_803123A4_723A54(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x > 70) || (y > 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x + 1][y + 0].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 1][y + 0].unk0 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 1][y + 0].unk1 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x20)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 0x2)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x + 1][y + 0].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x + 1][y + 0].unk5 & 0x10)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x + 1][y + 0].unk5 & 0x1)) && ((var_a3 & 0x10) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

s32 func_803126F4_723DA4(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x >= 72) || (y > 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x + 0][y - 1].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk0 * 8;
    temp_t8 = D_803C0740[x + 1][y + 0].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk1 * 8;
    temp_t8 = D_803C0740[x + 1][y + 0].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x40)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 0x4)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x + 0][y - 1].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x][y - 1].unk5 & 0x80)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x][y - 1].unk5 & 0x8)) && ((var_a3 & 0x10) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

s32 func_80312A44_7240F4(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x >= 72) || (y >= 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x + 0][y + 1].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 0][y + 1].unk0 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 0][y + 1].unk1 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x80)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 8)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x + 0][y + 1].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x + 0][y + 1].unk5 & 0x40)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x + 0][y + 1].unk5 & 4)) && ((var_a3 & 0x10) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

// handle_x_velocity_something
void func_80312D94_724444(void) {
    if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        if (ABS(D_803E4C94->xVelocity.h) > 10) {
            do_rumble(0, 0x19, 0x37, 5, 0);
        } else if (ABS(D_803E4C94->xVelocity.h) > 3) {
            do_rumble(0, 0xD, 0x19, 5, 0);
        }
    }

    if ((ABS(D_803E4C94->xVelocity.w) >= FTOFIX32(6.0)) && (D_803E4C94->unk16C->unk80.unk12)) {
        func_802DBA58_6ED108(8, D_803D552C);
        func_8034ABA4_75C254();
    }

    if ((D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FLYING_DOG) || (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FIRE_FOX)) {
        if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->xVelocity.h >> 1) - 4), -1, 0);
        } else {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->xVelocity.h >> 2) - 4), -1, 0);
        }

    } else if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+HELI_RABBIT) {
        func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->xVelocity.h) - 4), -1, 0);
    }

    if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+WALRUS) {
        D_803E4C94->xVelocity.w = -(D_803E4C94->xVelocity.w >> 2);
    } else {
        D_803E4C94->xVelocity.w = -((D_803E4C94->xVelocity.w * 3) >> 2);
    }

    D_803E4C94->unk54 |= (2|8);
}

// handle_z_velocity_something
void func_80313064_724714(void) {

    if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        if (ABS(D_803E4C94->zVelocity.h) > 10) {
            do_rumble(0, 0x19, 0x37, 5, 0);
        } else if (ABS(D_803E4C94->zVelocity.h) > 3) {
            do_rumble(0, 0xD, 0x19, 5, 0);
        }
    }

    if ((ABS(D_803E4C94->zVelocity.w) >= FTOFIX32(6.0)) && (D_803E4C94->unk16C->unk80.unk12)) {
        func_802DBA58_6ED108(9, D_803D552C);
        func_8034ABA4_75C254();
    }

    if ((D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FLYING_DOG) || (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FIRE_FOX)) {
        if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->zVelocity.h >> 1) - 4), -1, 0);
        } else {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->zVelocity.h >> 2) - 4), -1, 0);
        }

    } else if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+HELI_RABBIT) {
        func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->zVelocity.h) - 4), -1, 0);
    }

    if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+WALRUS) {
        D_803E4C94->zVelocity.w = -(D_803E4C94->zVelocity.w >> 2);
    } else {
        D_803E4C94->zVelocity.w = -((D_803E4C94->zVelocity.w * 3) >> 2);
    }

    D_803E4C94->unk54 |= (2|8);
}

// some collision?
void func_80313334_7249E4(void) {
    if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        if ((ABS(D_803E4C94->xVelocity.h) + ABS(D_803E4C94->zVelocity.h)) > 15) {
            do_rumble(0, 25, 55, 5, 0);
        } else if ((ABS(D_803E4C94->xVelocity.h) + ABS(D_803E4C94->zVelocity.h)) > 5) {
            do_rumble(0, 13, 25, 5, 0);
        }
    }
    D_803E4C94->xVelocity.h = 0;
    D_803E4C94->zVelocity.h = 0;
    D_803E4C94->unk54 |= (2|8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80313448_724AF8.s")
// currently nonsense
// s32 func_80313448_724AF8(Animal *arg0, s32 arg1, s32 arg2, s32 arg3) {
//     D_803E4C94 = arg0;
//
//     D_803E4C52 = D_803E4C94->xPos.h; // er?
//     D_803E4C54 = D_803E4C94->zPos.h;
//     D_803E4C5C = D_803E4C94->xPos.w + arg1;
//     D_803E4C60 = D_803E4C94->zPos.w + arg2;
//     D_803E4C64 = D_803E4C94->yPos.w + arg3;
//
//     D_803E4C56 = D_803E4C5C >> 16;
//     D_803E4C58 = D_803E4C60 >> 16;
//     D_803E4C68 = D_803E4C52 >> 6;
//     D_803E4C6A = D_803E4C54 >> 6;
//     D_803E4C6C = D_803E4C6A >> 6;
//     D_803E4C6E = (D_803E4C5C >> 16) >> 6;
//
//     D_803E4C70 = D_803E4C52 & 0x3F;
//     D_803E4C72 = D_803E4C54 & 0x3F;
//     D_803E4C74 = D_803E4C6A & 0x3F;
//     D_803E4C76 = D_803E4C58 & 0x3F;
//
//     D_803E4C7C = D_803D5530->xVelocity.w;
//     D_803E4C80 = D_803D5530->zVelocity.w;
//     D_803E4C78 = D_803E4C94->unk160;
//
//     if ((func_8030B494_71CB44() == 0) && (func_8030EA98_720148() == 0)) {
//         D_803E4C94->xPos.w = D_803E4C5C;
//         D_803E4C94->zPos.w = D_803E4C60;
//         D_803E4C94->yPos.w = D_803E4C64;
//         D_803E4C94->unk160 = D_803E4C78;
//         return 1;
//     } else {
//         return 0;
//     }
// }

#if 0
s32 D_803A5590_7B6C40[] = {
    0x00000300, 0x00000300, 0x00000300, 0x000006D6,
    0x00000708, 0x0000073A, 0x000007A0, 0x00000850,
    0x00000900, 0x00000938, 0x00000970, 0x000009A8,
    0x000009E0, 0x00000A18, 0x00000A50, 0x00000A88,
    0x00000AC0, 0x00000B00, 0x00000B0A, 0x00000B14,
    0x00000B1E, 0x00000B28, 0x00000B32, 0x00000B3C,
    0x00000B46, 0x00000B50, 0x00000B5A, 0x00000B64,
    0x00000B6E, 0x00000B78, 0x00000B82, 0x00000B8C,
    0x00000B96, 0x00000BA0, 0x00000BAA, 0x00000BC0,
    0x00000BC0, 0x00000BB6, 0x00000BAC, 0x00000BA2,
    0x00000B98, 0x00000B8E, 0x00000B84, 0x00000B7A,
    0x00000B70, 0x00000B66, 0x00000B5C, 0x00000B52,
    0x00000B48, 0x00000B3E, 0x00000B34, 0x00000B2A,
    0x00000B20, 0x00000B16, 0x00000B00, 0x00000AC8,
    0x00000A90, 0x00000A58, 0x00000A20, 0x000009E8,
    0x000009B0, 0x00000978, 0x00000940, 0x00000900,
    0x00000850, 0x000007A0, 0x0000073A, 0x00000708,
    0x000006D6, 0x00000300, 0x00000300, 0x00000300
};
#endif

#ifdef NON_MATCHING // JUSTREG
// ~45 away
void func_803135FC_724CAC(Animal *arg0) {
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_v0;
    s32 phi_a2;
    s32 phi_a3;
    s32 tmp;

    temp_v0 = arg0->xPos.h >> 6;
    temp_t2 = 36; // regalloc helper
    if (temp_v0 < temp_t2) {
        phi_a2 = D_803A5590_7B6C40[temp_v0 - 1];
        phi_a3 = D_803A5590_7B6C40[temp_v0];
    } else {
        phi_a2 = D_803A5590_7B6C40[temp_v0];
        phi_a3 = D_803A5590_7B6C40[temp_v0 + 1];
    }

    if ((phi_a2 < (arg0->yPos.h + arg0->unk42)) || (phi_a3 < (arg0->yPos.h + arg0->unk42))) {
        temp_t2 = phi_a2 + (((phi_a3 - phi_a2) * (arg0->xPos.h - (temp_v0 << 6))) >> 6);
        if (temp_t2 < (arg0->yPos.h + arg0->unk42)) {
            arg0->yPos.h = temp_t2 - arg0->unk42;
            arg0->yVelocity.w = MIN(arg0->yVelocity.w, 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803135FC_724CAC.s")
#endif

void func_803136B0_724D60(Animal *arg0) {
    arg0->unk160 = func_803136FC_724DAC(arg0->xPos.h, arg0->zPos.h, (arg0->yPos.h + (arg0->unk42 >> 1)));
}

u8 func_803136FC_724DAC(s16 x, s16 z, s16 y) {
    if (D_803C0740[x >> 6][z >> 6].unk3 == 0) {
        return 0;
    }
    if ((func_80310F58_722608(x, z) >> 16) < y) {
        return 2;
    } else {
        return 1;
    }
}
