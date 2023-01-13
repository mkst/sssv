#include <ultra64.h>
#include "common.h"


s32 func_80316408_727AB8(Animal *arg0);

void func_80314660_725D10(void) {
    s16 i;
    for (i = 0; i < 32; i++) {
        D_8023F208[i] = D_803E4CA8[i];
    }
}

Animal *func_803146A8_725D58(Animal *arg0, s16 arg1, u16 arg2) {
    Animal *ret;

    switch (arg1) {
    case 0:
        ret = arg0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        ret = arg0->unk248[arg1];
        break;
    case 8:
        ret = arg0->unk60;
        break;
    case 9:
        ret = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        break;
    case 10:
        ret = func_8031540C_726ABC(arg2, 1);
        break;
    case 11:
        ret = func_8031540C_726ABC(arg2, 0);
        break;
    case 12:
        ret = arg0->unk248[0];
        break;
    }
    return ret;
}

void func_80314788_725E38(void) {
    bzero_sssv((u8*)D_803E4CA8, sizeof(D_803E4CA8));
    bzero_sssv((u8*)D_803E4D40, sizeof(D_803E4D40));
    D_803E8E54 = 0;
    D_803E4CA4 = 0;
    D_803E4CA5 = 0;
    D_803E4CA6 = 0;
    D_803E8E56 = 0;
    func_803497DC_75AE8C(); // initialise ...something osd related
    D_803A05B0_7B1C60 = 0x20000;
    D_803A05B4_7B1C64 = D_803A05B0_7B1C60 * 2;
    D_803E4D2C = 0;
    D_803E4D30 = 16;
    D_803E4D38[0] = D_8023F260.unk30;
    D_803E4D38[1] = D_8023F260.unk34;
    D_803E4D28 = 0;
    D_803E4CA0 = 0;
    D_801546E0 = 0x800;
    D_801546D8 = 0x800;
    func_803976E0_7A8D90(); // initialise something...
    D_803E8E57 = 1;
    D_803E8E58 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/set_game_state.s")
extern s32 D_FFFE0404[];
extern s32 D_803C4DAC[];
// void set_game_state(Animal *arg0, s16 arg1, s32 arg2) {
//     // arg1 gets 0x7F7F added before being passed
//     s16 temp_v1;
//     s32 temp_hi;
//     s32 temp_t6;
//     struct035 *temp_v0_3;
//     s32 phi_v0;
//     s16 phi_v1;
//     struct035 *phi_t1;
//     s16 phi_v1_2;
//     Animal *tmp;
//     s16 i;
//
//     switch (arg1) {
//     case 0+0x7F7F:    // 0
//     case 1+0x7F7F:    // 1
//     case 2+0x7F7F:    // 2
//         // wtf is this
//         // D_FFFE0404[(s32)arg0 + (arg1)] = arg2; // -130044 , -0x1fbfc?
//         (arg0 - 133)->pad33C[arg1 + 1] = arg2;
//         break;
//     case 3+0x7F7F:    // 3
//         arg0->unk158 = arg2;
//         arg0->unk15E = arg2;
//         break;
//     case ST_SET_HEALTH:    // 4
//         if (!(arg0->unk4C.pad30 /* & 0x20 */) || (arg0->health < arg2)) {
//             if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
//                 if (arg2 < arg0->health) {
//                     func_80349280_75A930(arg0, arg0->health - arg2);
//                 }
//             }
//             arg0->health = MIN(0x7F, MAX(0, arg2));
//         }
//         break;
//     case 5+0x7F7F:
//         func_8012822C(arg2); // update game time?
//         break;
//     case ST_SET_XPOS:
//         arg0->xPos.h = arg2 << 16;
//         func_803136B0_724D60(arg0);
//         break;
//     case ST_SET_ZPOS:
//         arg0->zPos.h = arg2 << 16;
//         func_803136B0_724D60(arg0);
//         break;
//     case ST_SET_YPOS:
//         arg0->yPos.h = arg2 << 16;
//         func_803136B0_724D60(arg0);
//         break;
//     case 9+0x7F7F:
//         arg0->unk40 = arg2;
//         func_802C9BA4_6DB254(arg0);
//         break;
//     case 10+0x7F7F:
//         func_80349AA0_75B150(arg2);
//         break;
//     case ST_SET_XVEL:
//         arg0->xVelocity.w = arg2 << 5;
//         break;
//     case ST_SET_ZVEL:
//         arg0->zVelocity.w = arg2 << 5;
//         break;
//     case ST_SET_YVEL:
//         arg0->yVelocity.w = arg2 << 5;
//         break;
//     case ST_SET_ZROT:
//         if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
//             arg0->zRotation = (s16) (((s32) (arg2 << 8) / 360) & 0xFF);
//         } else {
//             // is 1800 a typo?
//             func_802C9918_6DAFC8(arg0, (s16) ((s32) (arg2 + 1800) % 360), arg0->yRotation);
//         }
//         break;
//     case ST_SET_YROT:
//         if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
//             arg0->yRotation = (s16) (((s32) (arg2 * 256) / 360) & 0xFF);
//             arg0->unk302 = (s16) arg0->yRotation;
//         } else {
//             func_802C9918_6DAFC8(arg0, arg0->zRotation, (s16) ((s32) (arg2 + 1800) % 360));
//         }
//         break;
//     case 16+0x7F7F:
//         temp_hi = arg2 % 100;
//         arg0->unk248[0] = func_803146A8_725D58(arg0, (s16) temp_hi, (arg2 / 100) & 0xFFFF);
//         arg0->unk1CC = (s8) temp_hi;
//         break;
//     case 17+0x7F7F:
//         if (arg2 & 1) {
//             arg0->unk163 &= ~0x8;
//         } else {
//             arg0->unk163 |= 0x8;
//         }
//         if (arg2 & 2) {
//             arg0->unk163 |= 0x10;
//         } else {
//             arg0->unk163 &= ~0x10;
//         }
//         if (arg2 & 4) {
//             arg0->unk163 |= 0x40;
//         } else {
//             arg0->unk163 &= ~0x40;
//         }
//         if (arg2 & 8) {
//             arg0->unk163 |= 0x80;
//         } else {
//             arg0->unk163 &= ~0x80;
//         }
//         break;
//     case 18+0x7F7F: // set mass?
//         arg0->unk46 = arg2;
//         arg0->unk44 = (s16) ((s32) ((arg2) * arg0->unk40) >> 0xB);
//         break;
//     case ST_SET_SCORE:    // 19
//         D_803F2D30.score = arg2;
//         break;
//     case 20+0x7F7F:
//         arg0->unk3E = arg2;
//         break;
//     case ST_SET_STATE:
//         arg0->state = arg2;
//         break;
//     case 22+0x7F7F:
//         D_803F2CD8 = ABS(arg2);
//         D_803F2CD6 = arg2 < 0 ? -1 : 1;
//         break;
//     case 23+0x7F7F:
//         temp_t6 = arg2 << 6;
//         D_803A05B0_7B1C60 = temp_t6;
//         D_803A05B4_7B1C64 = temp_t6 * 2;
//         break;
//     case 28+0x7F7F:
//         D_803E4D2C = arg2;
//         break;
//     case 29+0x7F7F:
//         D_803F2D50.unkE0 = (f32) arg2 / 100.0f;
//         break;
//     case 30+0x7F7F:
//         D_803E4D30 = arg2;
//         break;
//     case 31+0x7F7F:
//         D_803E4D38[0] = arg2;
//         D_8023F260.unk30 = arg2;
//         write_eeprom(D_803F7DD6);
//         break;
//     case 32+0x7F7F:
//         // is arg2 an object ID?
//         if (arg2 < OB_TYPE_ANIMAL_OFFSET) {
//             arg0->unk16C = &D_801E9EB8.unk0[arg2];
//             func_802C9BA4_6DB254(arg0);
//         } else {
//             // arg2 is an animal ID
//             phi_t1 = NULL;
//             for (i = 0; i < D_803D553E; i++) {
//                 tmp = D_801D9ED8.animals[i].animal;
//                 if ((arg0 == tmp) && (tmp->unk366 != 6)) {
//                     phi_t1 = D_801D9ED8.unk0;
//                     break;
//                 }
//             }
//             if (phi_t1 != NULL) {
//                 temp_v0_3 = &D_801D9ED8.unk0[arg2]; // + (arg2 * 0xEC) + 0xFFFF1400;
//                 phi_t1->objectType = temp_v0_3;
//                 arg0->unk16C = temp_v0_3;
//                 // help
//                 D_803D5520 = &D_801D9ED8.unk0[arg2];
//                 D_803D5524 = &D_801D9ED8.unk0; //phi_t1->unk0;
//                 D_803D5528 = &D_801D9ED8.animals;  //phi_t1->unk4;
//                 D_803D552C = &D_801D9ED8.animals;  //phi_t1->unk4;
//                 D_803D5530 = &D_801D9ED8.animals;  //phi_t1->unk4;
//                 if (i == gCurrentAnimalIndex) {
//                     D_803D5538 = 1;
//                 } else {
//                     D_803D5538 = 0;
//                 }
//                 D_803D553C = i;
//                 D_803D553A = 0;
//                 // arg0 = arg0;
//                 func_802B2EA8_6C4558();
//                 if (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) { // + (gCurrentAnimalIndex * 8))->
//                     D_803E9824 = arg2 - OB_TYPE_ANIMAL_OFFSET;
//                     // temp_v0_4 = (D_803E9824 * 2) + &D_803A63B0_7B7A60;
//                     // arg0 = arg0;
//                     D_803E9820 = (s16) D_803A63B0_7B7A60[D_803E9824].unk0;
//                     D_803E9822 = (s16) D_803A63B0_7B7A60[D_803E9824].unk1;
//                     func_80327DA8_739458();
//                 }
//                 func_802C9BA4_6DB254(arg0);
//             }
//         }
//         break;
//     case 33+0x7F7F:
//         D_801546E0 = (s16) arg2;
//         break;
//     case 34+0x7F7F:
//         D_801546D8 = MAX(arg2, 0);
//         break;
//     case 35+0x7F7F:
//         D_803E4D38[1] = arg2;
//         D_8023F260.unk34 = arg2;
//         write_eeprom(D_803F7DD6); //, arg1, arg0);
//         break;
//     case 36+0x7F7F:
//         D_803E4D28 = arg2;
//         break;
//     default:
//         D_803C4DAC[arg1] = arg2; // + (arg1 * 4)) = arg2;
//         break;
//     }
// }

extern s32 D_803E4D3C;
extern s32 D_803C4DAC_7D645C[];

s32 get_game_state(Animal *arg0, s32 arg1) {
    s32 res;

    if (arg1 < 0x7F7F) {
        res = arg1;
    } else {
        switch (arg1) { // arg1 - 0x7F7F
        case 0+0x7F7F:
        case 1+0x7F7F:
        case 2+0x7F7F:
            // FIXME!
            res = (arg0 - 133)->pad33C[arg1];
            // res = *(s32*)&D_FFFE0400[(s32)(((s32*)&arg0->xPos.h) + arg1)];
            break;
        case 3+0x7F7F:
            res = arg0->unk158;
            break;
        case ST_GET_HEALTH:
            res = arg0->health;
            break;
        case ST_GET_RANDOM:
            res = (s32) (func_80128200() & 0x7FFF) % 0x7F7E;
            break;
        case ST_GET_XPOS:
            res = arg0->xPos.h;
            break;
        case ST_GET_ZPOS:
            res = arg0->zPos.h;
            break;
        case ST_GET_YPOS:
            res = arg0->yPos.h;
            break;
        case 9+0x7F7F:
            res = arg0->unk40;
            break;
        case 10+0x7F7F:
            if (D_803F2CD6 < 0) {
                res = D_803F2CD2;
            } else {
                res = D_803F2CD2 - 1;
                if ((D_803F2CD8 >> 1) < D_803F2CD4) {
                    res += 1;
                }
            }
            break;
        case ST_GET_XVEL:
            res = arg0->xVelocity.w >> 5;
            break;
        case ST_GET_ZVEL:
            res = arg0->zVelocity.w >> 5;
            break;
        case ST_GET_YVEL:
            res = arg0->yVelocity.w >> 5;
            break;
        case ST_GET_ZROT:
            if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
                res = (arg0->zRotation * 360) / 256;
            } else {
                res = arg0->zRotation;
            }
            break;
        case ST_GET_YROT:
            if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
                res = (arg0->yRotation * 360) / 256;
            } else {
                res = arg0->yRotation;
            }
            break;
        case 16+0x7F7F:
            res = arg0->unk1CC;
            break;
        case 17+0x7F7F:
            res = (arg0->unk163 & 0x18) >> 3;
            break;
        case 18+0x7F7F: // get mass?
            res = arg0->unk46;
            break;
        case ST_GET_SCORE:
            res = D_803F2D30.score;
            break;
        case 20+0x7F7F:
            res = arg0->unk3E;
            break;
        case ST_GET_STATE:
            res = arg0->state;
            break;
        case 22+0x7F7F:
            res = D_803F2CD8 * D_803F2CD6;
            break;
        case 23+0x7F7F:
            res = D_803A05B0_7B1C60 >> 6;
            break;
        case ST_GET_CONT_STICK_X:
            if ((gControllerInput->stick_x < -8) || (gControllerInput->stick_x > 8)) {
                res = gControllerInput->stick_x;
            } else {
                res = 0;
            }
            break;
        case ST_GET_CONT_STICK_Y:
            if ((gControllerInput->stick_y < -8) || (gControllerInput->stick_y > 8)) {
                res = gControllerInput->stick_y;
            } else {
                res = 0;
            }
            break;
        case ST_GET_CONT_BUTTON_A:
            if ((gControllerInput->button & A_BUTTON)) {
                res = 1;
            } else {
                res = 0;
            }
            break;
        case ST_GET_CONT_BUTTON_B:
            if ((gControllerInput->button & B_BUTTON)) {
                res = 1;
            } else {
                res = 0;
            }
            break;
        case 28+0x7F7F:
            res = D_803E4D2C;
            break;
        case 29+0x7F7F:
            res = D_803F2D50.unkE0 * 100.0f;
            break;
        case 30+0x7F7F:
            res = D_803E4D30;
            break;
        case 31+0x7F7F:
            res = D_803E4D38[0];
            break;
        case ST_GET_OBJECT_TYPE:
            res = arg0->unk16C->objectType;
            break;
        case 33+0x7F7F:
            res = D_801546E0;
            break;
        case 34+0x7F7F:
            res = D_801546D8;
            break;
        case 35+0x7F7F:
            res = D_803E4D38[1];
            break;
        case 36+0x7F7F:
            res = D_803E4D28;
            break;
        default:
            res = D_803C4DAC_7D645C[arg1];
        }
    }
    return res;
}

s32 func_803152A4_726954(s32 left, u8 op, s32 right) {
    switch (op) {
    case CMD_ADD:
        left = left + right;
        break;
    case CMD_SUBTRACT:
        left = left - right;
        break;
    case CMD_MULTIPLY:
        left = left * right;
        break;
    case CMD_DIVIDE:
        left = left / right;
        break;
    case CMD_LOGICAL_AND:
        left = left & right;
        break;
    case CMD_LOGICAL_OR:
        left = left | right;
        break;
    case CMD_MODULO:
        left = left % right;
        break;
    case CMD_RSHIFT:
        left = left >> right;
        break;
    case CMD_LSHIFT:
        left = left << right;
        break;
    case CMD_NOOP:
        // left = left;
        break;
    }
    return left;
}

// copy_command_struct
void copy_command_struct(struct069 *arg0, struct069 *arg1) {
    arg1->unk2 = arg0->unk2;
    arg1->unk4 = arg0->unk4;
    arg1->unk6 = arg0->unk6;
    arg1->unk8 = arg0->unk8;
    arg1->unk0 = arg0->unk0;
}

void func_803153B0_726A60(Animal *arg0, struct069 arg1[], u8 arg2) {
    arg0->unk1A8 = arg1;
    arg0->unk19C = arg2;
    arg0->unk1CD = 0;
    arg0->unk1CC = 0;
    arg0->unk248[0] = arg0;
    if (arg1 != 0) {
        copy_command_struct(&arg1[arg2], &arg0->unk19E);
    }
}

#if 0
// plenty to figure out here..
Animal *func_8031540C_726ABC(s16 arg0, u8 arg1) {
    u64 sp48;
    s16 j;
    s16 i;
    Animal *ret; // sp40

    s32 done;
    struct065 *var_s0;

    static Animal *D_803E8E5C;

    if (arg1 != 0) {
        D_803E8E5C = NULL;
        done = 1;
    } else {
        done = 0;
    }

    ret = NULL;

    for (sp48 = D_803E95B8[arg0], i = 0; ((i < 40) && (sp48 != 0)); sp48 >>= 8, i += 8) {
        if (sp48 & 0xFF) {
            for (j = 0; j < 8; j++) {
                if (sp48 & ((s64)1 << i)) {
                    for (var_s0 = D_803DA110[i+j].next; var_s0 != NULL; var_s0 = var_s0->next) {
                        if ((var_s0->animal->unk16C->objectType != (256+EVO_TRANSFER)) && (var_s0->animal->unk114[0] == (i + j)) && (var_s0->animal != D_803E8E5C)) {
                            if ((func_80319E1C_72B4CC(var_s0->animal->xPos.h >> 6, var_s0->animal->zPos.h >> 6, var_s0->animal->yPos.h >> 6, arg0, var_s0->animal->unk160))) {
                                if (done != 0) {
                                    ret = var_s0->animal;
                                    D_803E8E5C = var_s0->animal;
                                    // goto done;
                                } else if (D_803E8E5C == var_s0->animal) {
                                    done = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (ret == NULL) {
        D_803E8E5C = NULL;
    }
done:
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_8031540C_726ABC.s")
#endif

#if 1
u8 func_80315658_726D08(s16 arg0, s32 func(Animal *, s16), s16 arg2) {
    u64 sp50;
    s32 pad; // sp
    u8  ret; // sp4B
    s16 j;
    s16 i;
    struct065 *var_s1;

    ret = 0;

    for (sp50 = D_803E95B8[arg0], i = 0; ((i < 0x28) && (sp50 != 0)); sp50 >>= 8, i += 8) {
        if (sp50 & 0xFF) {
            for (j = 0; j < 8; j++) {
                if (sp50 & ((s64)1 << j)) {
                    for (var_s1 = D_803DA110[i + j].next; var_s1 != NULL; var_s1 = var_s1->next) {
                        if ((var_s1->animal->unk16C->objectType != (256+EVO_TRANSFER)) && (var_s1->animal->unk114[0] == (i + j)) && (func(var_s1->animal, arg2))) {
                            if (func_80319E1C_72B4CC(var_s1->animal->xPos.h >> 6, var_s1->animal->zPos.h >> 6, var_s1->animal->yPos.h >> 6, arg0, var_s1->animal->unk160) != 0) {
                                ret = 1;
                                goto done;
                            }
                        }
                    }
                }
            }
        }
    }

done:
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80315658_726D08.s")
#endif

s32 func_80315870_726F20(s32 arg0, s32 arg1) {
    return 1;
}

s32 func_80315880_726F30(s16 arg0) {
    return func_80315658_726D08(arg0, &func_80315870_726F20, 0);
}

s32 func_803158B4_726F64(Animal *arg0, s16 arg1) {
    if (arg1 == arg0->unk16C->objectType) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_803158E4_726F94(s16 arg0, s16 arg1) {
    return func_80315658_726D08(arg0, &func_803158B4_726F64, arg1);
}

// is_animal
s32 func_80315924_726FD4(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80315950_727000(s16 arg0) {
    return func_80315658_726D08(arg0, &func_80315924_726FD4, 0);
}

// is_object
s32 func_80315984_727034(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_803159B0_727060(s16 arg0) {
    return func_80315658_726D08(arg0, &func_80315984_727034, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_803159E4_727094.s")
// u8 func_803159E4_727094(Animal *arg0, struct070 *arg1) {
//     u16 changed;
//     u16 sp3C;
//     s32 phi_v1;
//
//     sp3C = arg1->unk0 & 0x80;
//
//     changed = 0;
//
//     switch (arg1->unk0 & ~0xC0) {
//     case 0:
//         if ((arg1->unk2.b[0] & 8) && (func_80315880_726F30(arg1->unk2.b[1]))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 1) && (func_803159B0_727060(arg1->unk2.b[1]))) {
//             changed = 1;
//         } else if (arg1->unk2.b[0] & 2) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 16) && (func_80319E1C_72B4CC(
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h >> 6,
//                     arg1->unk2.b[1],
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 4) && (func_80315950_727000(arg1->unk2.b[1]))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 32) && (func_803158E4_726F94(arg1->unk2.b[1], (arg1->unk4.b[1] + 0x100)))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 64) && (func_803158E4_726F94(arg1->unk2.b[1], arg1->unk4.b[0]))) {
//             changed = 1;
//         }
//         break;
//     case 1:
//         if ((arg0->unk162 != 4) && (arg0->unk162 != 5) && (arg0->unk162 != 6) && (arg0->unk162 != 7)) {
//             phi_v1 = MIN(MIN(D_803C0740[(arg0->xPos.h >> 6) + 1][(arg0->zPos.h >> 6) + 0].unk6, D_803C0740[(arg0->xPos.h >> 6) + 0][(arg0->zPos.h >> 6) + 0].unk6),
//                          MIN(D_803C0740[(arg0->xPos.h >> 6) + 1][(arg0->zPos.h >> 6) + 1].unk6, D_803C0740[(arg0->xPos.h >> 6) + 0][(arg0->zPos.h >> 6) + 1].unk6));
//
//             if (arg0->yPos.h < (phi_v1 * 4)) {
//                 changed = 1;
//             }
//         } else {
//             // wrong?
//             changed = 1;
//         }
//         break;
//     case 2:
//         if (arg1->unk2.h == arg0->state) {
//             changed = 1;
//         }
//         break;
//     case 3:
//         phi_v1 = MIN(MIN(D_803C0740[(arg0->xPos.h >> 6) + 1][(arg0->zPos.h >> 6) + 0].unk6, D_803C0740[(arg0->xPos.h >> 6) + 0][(arg0->zPos.h >> 6) + 0].unk6),
//                      MIN(D_803C0740[(arg0->xPos.h >> 6) + 1][(arg0->zPos.h >> 6) + 1].unk6, D_803C0740[(arg0->xPos.h >> 6) + 0][(arg0->zPos.h >> 6) + 1].unk6));
//         if (get_game_state(arg0, arg1->unk2.h) < (phi_v1 * 4)) {
//             changed = 1;
//         }
//         break;
//     case 4:
//         if ((arg1->unk2.b[0] & 8) && ((arg0->unk5C & 8))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 1) && (arg0->unk5C & 1)) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 2) && (arg0->unk5C & 2)) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 16) && ((arg0->unk5C & 16))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 4) && (arg0->unk5C & 4)) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 32) && (arg0->unk5C & 4) && (arg0->unk5D == arg1->unk4.b[1])) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 64) && (arg0->unk5C & 1) && (arg0->unk5D == arg1->unk4.b[0])) {
//             changed = 1;
//         }
//         break;
//     case 5:
//         if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
//             if (arg0->unk28C == 0) {
//                 changed = 1;
//             }
//         } else if ((u8)arg0->unk170 == 0) {
//             changed = 1;
//         }
//         break;
//     case 6:
//         if ((arg0 != NULL) && (arg0->unk26C != 1)) {
//             changed = 1;
//         }
//         break;
//     case 7:
//     case 8:
//         if (D_803F2AA4 != 0) {
//             changed = 1;
//         }
//         break;
//     case 9:
//         if (func_802FD5DC_70EC8C(arg0) >= get_game_state(arg0, arg1->unk2.h)) {
//             changed = 1;
//         }
//         break;
//     case 11:
//         if ((arg1->unk2.b[0] & 8) && (func_802FD3B8_70EA68(arg0))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 1) && (func_802FD4D0_70EB80(arg0))) {
//             changed = 1;
//         } else if (((arg1->unk2.b[0] & 16) && (func_802FD40C_70EABC(arg0, D_801D9ED8.animals[gCurrentAnimalIndex].animal))) || (func_802FD538_70EBE8(arg0))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 4) && (func_802FD468_70EB18(arg0))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 32) && (func_802FD348_70E9F8(arg0, (arg1->unk4.b[1] + 0x100)))) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 64) && (func_802FD348_70E9F8(arg0, arg1->unk4.b[0]))) {
//             changed = 1;
//         }
//         break;
//     case 14:
//         if (D_803A52B8_7B6968 != 0) {
//             changed = 1;
//         }
//         break;
//     case 15:
//         if (arg0->unk22C == 0) {
//             changed = 1;
//         }
//         break;
//     case 16:
//         if (func_80319E1C_72B4CC(
//                 arg0->xPos.h >> 6,
//                 arg0->zPos.h >> 6,
//                 arg0->yPos.h >> 6,
//                 arg1->unk2.b[1],
//                 arg0->unk160)) {
//             changed = 1;
//         }
//         break;
//     case 17:
//         if (get_game_state(arg0, arg1->unk2.h) < get_game_state(arg0, arg1->xPos.h)) {
//             changed = 1;
//         }
//         break;
//     case 18:
//         if (get_game_state(arg0, arg1->unk2.h) >= get_game_state(arg0, arg1->xPos.h)) {
//             changed = 1;
//         }
//         break;
//     case 19:
//         if (get_game_state(arg0, arg1->unk2.h) == get_game_state(arg0, arg1->xPos.h)) {
//             changed = 1;
//         }
//         break;
//     case 20:
//         if (get_game_state(arg0, arg1->unk2.h) >= get_game_state(arg0, arg1->xPos.h)) {
//             changed = 1;
//         }
//         break;
//     case 21:
//         if (get_game_state(arg0, arg1->unk2.h) < get_game_state(arg0, arg1->xPos.h)) {
//             changed = 1;
//         }
//         break;
//     case 22:
//         if (((arg1->unk2.b[0] & 1)) && (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET)) {
//             changed = 1;
//         } else if (((arg1->unk2.b[0] & 0x10)) && (arg0 == (D_801D9ED8.animals[gCurrentAnimalIndex].animal))) {
//             changed = 1;
//         } else if (((arg1->unk2.b[0] & 4)) && (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET)) {
//             changed = 1;
//         } else if (((arg1->unk2.b[0] & 32)) && ((arg1->unk4.b[1] + 0x100) == arg0->unk16C->objectType)) {
//             changed = 1;
//         } else if (((arg1->unk2.b[0] & 64)) && (arg1->xPos.h == arg0->unk16C->objectType)) {
//             changed = 1;
//         } else if ((arg1->unk2.b[0] & 8)) {
//             changed = 1;
//         }
//         break;
//     case 23:
//         if (arg1->unk2.h == arg0->unk5F) {
//             changed = 1;
//             break;
//         }
//         break;
//     }
//
//     if (sp3C) {
//         // invert result?
//         changed ^= 1;
//     }
//     return changed;
// }

// absolutely huge function
#if 0

typedef struct {
  s32 unk0;
  s32 unk4;
  s16 unk8;
} Cmd1;

typedef struct {
  u8  unk0;
  u8  unk1;
  u8  pad2[0x2];
  s16 unk4;
  s16 unk6;
  s16 unk8;
} Cmd2;

extern struct116 D_803E2930[];

s32 func_80316408_727AB8(Animal *arg0) {
    struct077 sp148;
    struct077 sp140;
    s16 sp13E;
    s16 sp13C;
    s32 sp134;
    s32 sp130;
    s32 sp12C;
    s16 sp120;
    s32 sp110;
    s32 sp10C;
    s32 spF8;
    s32 spF4;
    f32 spEC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spC8;
    struct077 spA4;
    struct077 sp9C;
    s16 sp9A;
    s16 sp98;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp74;
    s32 temp_t2;
    Animal *temp_a0;
    Animal *temp_a0_2;
    Animal *temp_a1_3;
    Animal *temp_s1;
    Animal *temp_s1_2;
    Animal *temp_t8;
    Animal *temp_v0_16;
    Animal *temp_v0_3;
    Animal *temp_v0_4;
    Animal2 *var_a2_2;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;
    f32 var_f2;
    s16 temp_a0_3;
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_a1_4;
    s16 temp_a1_5;
    s16 temp_a3;
    s16 temp_a3_2;
    s16 temp_s0_35;
    s16 temp_s2;
    s16 temp_s2_2;
    s16 temp_s2_3;
    s16 temp_s2_4;
    s16 temp_s2_5;
    s16 temp_s2_6;
    s16 temp_s2_7;
    s16 temp_s2_8;
    s16 temp_s2_9;
    s16 temp_t4;
    s16 temp_t6_3;
    s16 temp_t7_2;
    s16 temp_t9;
    s16 temp_v0_14;
    s16 temp_v0_15;
    s16 temp_v0_20;
    s16 temp_v0_21;
    s16 temp_v0_2;
    s16 var_a0_3;
    s16 var_a2_3;
    s16 var_a3;
    s16 var_a3_2;
    s16 var_a3_4;
    s16 var_a3_5;
    s16 var_s1;
    s16 var_v0_10;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v0_5;
    s16 var_v0_6;
    s16 var_v0_7;
    s16 var_v0_8;
    s16 var_v0_9;
    s16 var_v1_2;
    s16 var_v1_3;
    s16 var_v1_4;
    s32 temp_t3;
    s32 temp_t5_2;
    s32 temp_t5_3;
    s32 temp_t5_4;
    s32 temp_t6_2;
    s32 temp_t7_3;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_22;
    s32 temp_v0_23;
    s32 temp_v0_24;
    s32 temp_v1_12;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_v1;
    s8 var_a0;
    s8 var_a2;
    s8 var_a3_3;
    s8 var_t0;
    s8 var_t0_2;
    s8 var_t1;
    s8 var_t1_2;
    struct050 *temp_v0_26;
    struct050 *temp_v0_27;
    struct069 *temp_v1;
    struct112 *temp_t5;
    u16 temp_t6;
    u16 temp_t6_4;
    u16 temp_v0_10;
    u16 temp_v0_28;
    u16 temp_v0_5;
    u16 temp_v0_7;
    u16 temp_v0_8;
    u16 temp_v0_9;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u32 temp_v0_25;
    u32 temp_v1_11;
    Cmd1 *temp_s0;
    u8 *temp_s0_10;
    u8 *temp_s0_11;
    u8 *temp_s0_12;
    u8 *temp_s0_13;
    u8 *temp_s0_14;
    u8 *temp_s0_15;
    u8 *temp_s0_16;
    u8 *temp_s0_17;
    u8 *temp_s0_18;
    u8 *temp_s0_19;
    u8 *temp_s0_20;
    u8 *temp_s0_21;
    u8 *temp_s0_22;
    u8 *temp_s0_23;
    u8 *temp_s0_24;
    u8 *temp_s0_25;
    u8 *temp_s0_26;
    u8 *temp_s0_27;
    u8 *temp_s0_28;
    u8 *temp_s0_29;
    u8 *temp_s0_2;
    u8 *temp_s0_30;
    u8 *temp_s0_31;
    u8 *temp_s0_32;
    u8 *temp_s0_33;
    u8 *temp_s0_34;
    u8 *temp_s0_36;
    u8 *temp_s0_37;
    u8 *temp_s0_38;
    u8 *temp_s0_39;
    u8 *temp_s0_3;
    u8 *temp_s0_40;
    u8 *temp_s0_41;
    u8 *temp_s0_42;
    u8 *temp_s0_43;
    u8 *temp_s0_44;
    u8 *temp_s0_45;
    u8 *temp_s0_46;
    u8 *temp_s0_47;
    u8 *temp_s0_48;
    u8 *temp_s0_49;
    u8 *temp_s0_4;
    u8 *temp_s0_50;
    u8 *temp_s0_51;
    u8 *temp_s0_52;
    u8 *temp_s0_53;
    u8 *temp_s0_54;
    u8 *temp_s0_55;
    u8 *temp_s0_56;
    u8 *temp_s0_57;
    u8 *temp_s0_58;
    u8 *temp_s0_59;
    u8 *temp_s0_5;
    u8 *temp_s0_60;
    u8 *temp_s0_6;
    u8 *temp_s0_7;
    u8 *temp_s0_8;
    u8 *temp_s0_9;
    u8 temp_t2_2;
    u8 temp_t3_2;
    u8 temp_t3_3;
    u8 temp_t4_2;
    u8 temp_t5_5;
    u8 temp_t7;
    u8 temp_v0;
    u8 temp_v0_17;
    u8 temp_v0_6;
    u8 temp_v1_10;
    u8 temp_v1_3;
    u8 temp_v1_8;
    u8 temp_v1_9;
    u8 var_a0_2;
    u8 var_v0;
    void *temp_v0_18;
    void *temp_v0_19;
    Cmd2 *temp_v1_2;

    temp_t6 = arg0->unk19E.unk0;
    temp_s1 = arg0->unk248[0];
    switch (temp_t6) {                              /* switch 1 */
    case 0x1:                                       /* switch 1 */
        temp_s0 = &arg0->unk19C;
        if (func_803159E4_727094(temp_s1, (struct070 *) (temp_s0[0].unk4)) != 0) {
            if ((temp_s0[0].unk4 & 0x40) == 0) {
                temp_s0[0].unk0 = temp_s0[1].unk0;
            }
            return;
        }

        if (temp_s0[0].unk4 & 0x40) {
            while (arg0->unk1A8[arg0->unk19C+1].unk0 == 1) { // unkA
                arg0->unk19C++;
            }
        }
        break;
#if 0
    case 0x2:                                       /* switch 1 */
        temp_s0_2 = &arg0->unk19C;
        temp_v1_2 = temp_s0_2[temp_s0_2->unk31]; // + (temp_s0_2->unk31 * 8);
        temp_v1_2->unk10 = (s16) temp_s0_2->unk4;
        temp_v1_2->unk12 = (s16) temp_s0_2->unk6;
        temp_v1_2->unk14 = (s16) temp_s0_2->unk8;

        temp_v1_2->unk16 = (s16) temp_s0_2->unkA;
        temp_v1_2->unk11 = (u8) arg0->unk1CC;

        temp_s0_2->unk31 = (u8) (temp_s0_2->unk31 + 1);
        return;
#endif
#if 0
    case 0x3:                                       /* switch 1 */
        temp_s0_3 = &arg0->unk19C;
        temp_v0 = func_803159E4_727094(temp_s1, (struct070 *) (temp_s0_3 + 4));
        temp_v1_3 = temp_s0_3->unk38;
        temp_t3 = temp_v0 & 0xFF;
        if (temp_v1_3 == 0) {
            if (temp_t3 != 0) {
                if (temp_s0_3->unk4 & 0x40) {
                    temp_s0_3->unk38 = (u8) (temp_s0_3->unk0 + 1);
                }
                return;
            }
        } else {
            if (temp_v0 & 0xFF) {
                if (!(temp_s0_3->unk4 & 0x40)) {
                    temp_s0_3->unk38 = 0U;
                }
                return;
            }
            temp_t3_2 = temp_v1_3 - 1;
            temp_s0_3->unk0 = temp_t3_2;
            copy_command_struct(temp_s0_3->unkC + ((temp_t3_2 & 0xFF) * 0xA), (struct069 *) (temp_s0_3 + 2));
        default:                                    /* switch 1 */
            return;
        }
        break;
    case 0x4:                                       /* switch 1 */
        // store some state
        temp_s0_4 = &arg0->unk19C;
        temp_s0_4->unk32 = get_game_state(temp_s1, (s16) temp_s0_4->unk4);
        temp_s0_4->unk34 = (u8) temp_s0_4->unk0;
        return;
    case 0x5:                                       /* switch 1 */
        // get some state
        temp_s0_5 = &arg0->unk19C;
        temp_s0_5->unk32 = (s16) (temp_s0_5->unk32 - 1);
        if (temp_s0_5->unk32 > 0) {
            temp_s0_5->unk0 = temp_s0_5->unk34;
        }
        return;
    case 0x6:                                       /* switch 1 */
        temp_s0_6 = &arg0->unk19C;
        temp_a1 = (s16) temp_s0_6->unk4;
        if (temp_a1 != -1) {
            temp_s0_6->unk36 = get_game_state(arg0, temp_a1);
            temp_s0_6->unk4 = -1;
        }
        temp_v0_2 = temp_s0_6->unk36;
        temp_s0_6->unk36 = (s16) (temp_v0_2 - 1);
        if (temp_v0_2 <= 0) {
            return;
        }
        break;
    case 0x8:                                       /* switch 1 */
        temp_s0_7 = &arg0->unk19C;
        temp_s0_7->unk0 = (u8) (s16) temp_s0_7->unk4;
        return;
    case 0x9:                                       /* switch 1 */
        arg0->unk1A8 = NULL;
        break;
    case 0xB:                                       /* switch 1 */
        temp_s1->unk158 = get_game_state(temp_s1, arg0->unk19E.unk2);
        return;
    case 0xC:                                       /* switch 1 */
        temp_s0_8 = &arg0->unk19C;
        func_802FD190_70E840((temp_s0_8->unk4 + 4) & 0xFF, (temp_s0_8->unk5 + 8) & 0xFF, (u8) temp_s0_8->unk6, temp_s0_8->unk7, (s16) (get_game_state(temp_s1, temp_s0_8->unk8) >> 3));
        return;
    case 0xD:                                       /* switch 1 */
        temp_s0_9 = &arg0->unk19C;
        temp_s1->unk20C = get_game_state(temp_s1, (s16) temp_s0_9->unk4);
        temp_s1->unk210 = get_game_state(temp_s1, temp_s0_9->unk8);
        temp_s1->unk20E = get_game_state(temp_s1, (s16) (u16) temp_s0_9->unk6);
        return;
    case 0xE:                                       /* switch 1 */
        temp_s1->unk1CD = 0;
        temp_s1->unk1CE = 0;
        temp_s1->pad1CE[2] = 0;
        temp_s1->unk1D2 = 0;
        temp_s1->unk248[0] = temp_s1;
        temp_t5 = &D_803E4D40[(u16) arg0->unk19E.unk2];
        temp_s1->unk1A8 = (struct069 *) temp_t5;
        temp_s1->unk4F = (u8) (temp_s1->unk4F | 0x40);
        if (temp_s1 != arg0) {
            copy_command_struct((struct069 *) temp_t5, &temp_s1->unk19E);
            temp_s1->unk19C = 0;
            return;
        }
        temp_s1->unk19C = 0xFF;
        return;
    case 0xF:                                       /* switch 1 */
        temp_s1->state = (u16) arg0->unk19E.unk2;
        return;
    case 0x10:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType >= 0x100) {
            var_a3 = (s16) ((s32) (temp_s1->zRotation * 0x168) >> 8);
            var_v0_2 = (s16) ((s32) (temp_s1->yRotation * 0x168) >> 8);
        } else {
            sp13E = temp_s1->zRotation;
            var_a3 = sp13E;
            var_v0_2 = temp_s1->yRotation;
        }
        temp_s0_10 = &arg0->unk19C;
        temp_a3 = var_a3 + ((s32) (temp_s0_10->unk9 * 0x168) >> 8);
        var_a3_2 = temp_a3;
        var_v0_3 = var_v0_2 + ((s32) ((s8) temp_s0_10->unk8 * 0x168) >> 8);
        if (temp_a3 >= 0x168) {
            var_a3_2 = temp_a3 - 0x168;
        } else if (var_a3_2 < 0) {
            var_a3_2 += 0x168;
        }
        if (var_v0_3 >= 0x168) {
            var_v0_3 -= 0x168;
        } else if (var_v0_3 < 0) {
            var_v0_3 += 0x168;
        }
        sp13E = var_a3_2;
        sp13C = var_v0_3;
        func_802F603C_7076EC((s16) (s8) temp_s0_10->unk5, (s16) (s8) temp_s0_10->unk6, (s16) (s8) temp_s0_10->unk7, var_a3_2, (s16) (s32) var_v0_3, (u16) (s32) temp_s1->unk40, &sp148);
        func_802F5F44_7075F4(0, (s16) ((u8) temp_s0_10->unkA << 8), 0, sp13E, (s16) (s32) sp13C, &sp140);
        temp_v0_3 = func_802C9564_6DAC14(temp_s0_10->unk4, (s16) (temp_s1->xPos.h + (s16) sp148), (s16) (temp_s1->zPos.h + sp148.unk2), (s16) (temp_s1->yPos.h + sp148.unk4), (s16) ((s16) sp140 << 8), (s16) (sp140.unk2 << 8), (s16) (sp140.unk4 << 8), (s16) (s32) sp13E, (s16) (s32) sp13C, (s16) 0x800);
        arg0->unk248[7] = temp_v0_3;
        if (temp_v0_3 == NULL) {

        } else {
            return;
        }
        break;
    case 0x11:                                      /* switch 1 */
        temp_s0_11 = &arg0->unk19C;
        temp_v0_4 = func_802C9564_6DAC14(temp_s0_11->unk4, temp_s0_11->unk6, temp_s0_11->unk8, temp_s0_11->unkA, (s16) 0, (s16) 0, (s16) 0, (s16) 0, (s16) 0, (s16) 0x800);
        arg0->unk248[7] = temp_v0_4;
        if (temp_v0_4 == NULL) {

        } else {
            return;
        }
        break;
    case 0x12:                                      /* switch 1 */
        temp_a0 = arg0->unk248[7];
        func_802FCA08_70E0B8(temp_a0, (s16) (temp_a0->unk164 | 0x4000));
        return;
    case 0x13:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType >= 0x100) {
            func_802C83CC_6D9A7C(temp_s1);
        } else {
            func_802FC990_70E040(temp_s1);
        }
        if (arg0 == temp_s1) {

        } else {
            return;
        }
        break;
    case 0x14:                                      /* switch 1 */
        temp_s0_12 = &arg0->unk19C;
        arg0->unk248[0] = func_803146A8_725D58(arg0, (s16) temp_s0_12->unk4, (u16) temp_s0_12->unk6);
        arg0->unk1CC = (u8) (u16) temp_s0_12->unk4;
        return;
    case 0x15:                                      /* switch 1 */
        temp_s0_13 = &arg0->unk19C;
        temp_s1->unk212 = (s8) temp_s0_13->unk4;
        temp_s1->unk213 = (s8) temp_s0_13->unk5;
        temp_s1->unk214 = (s8) temp_s0_13->unk6;
        temp_s1->unk215 = temp_s0_13->unk7;
        temp_s1->unk216 = (u8) temp_s0_13->unk8;
        temp_s1->unk217 = (u8) temp_s0_13->unk9;
        return;
    case 0x16:                                      /* switch 1 */
        temp_s0_14 = &arg0->unk19C;
        temp_s1->unk218 = temp_s0_14->unk4;
        temp_s1->unk219 = temp_s0_14->unk5;
        temp_s1->unk21A = (u8) temp_s0_14->unk6;
        temp_s1->unk21B = temp_s0_14->unk7;
        temp_s1->unk21C = (u8) temp_s0_14->unk8;
        temp_s1->unk21D = (u8) temp_s0_14->unk9;
        return;
    case 0x17:                                      /* switch 1 */
        temp_s0_15 = &arg0->unk19C;
        temp_s1->unk21E = (u16) temp_s0_15->unk4;
        temp_s1->unk220 = (u8) temp_s0_15->unk6;
        temp_s1->unk221 = (s8) temp_s0_15->unk7 - 0x14;
        temp_s1->unk222 = (u8) temp_s0_15->unk8;
        temp_s1->unk223 = (u8) temp_s0_15->unk9;
        temp_s1->unk22A = 0;
        temp_s1->unk224 = (u16) temp_s0_15->unkA;
        return;
    case 0x18:                                      /* switch 1 */
        temp_s1->unk21E = (unaligned s32) arg0->unk1A0;
        temp_v0_5 = temp_s1->unk21E;
        temp_s1->unk222 = (unaligned s32) arg0->unk1A4;
        temp_s1->unk21E = temp_v0_5 & 0xFFFE;
        temp_s1->unk22A = 0;
        if (!(temp_v0_5 & 1) & 0xFF) {
            temp_a0_2 = temp_s1->unk248[8];
            if (temp_a0_2 != NULL) {
                func_8039DD90_7AF440(temp_a0_2);
                temp_s1->unk248[8] = NULL;
                return;
            }
        }
        temp_v0_6 = temp_s1->unk220;
        switch ((s32) temp_v0_6) {                  /* switch 4; irregular */
        case 0x8C:                                  /* switch 4 */
            temp_v0_7 = temp_s1->unk226;
            temp_v1_4 = temp_s1->unk228;
            temp_s1->unk248[8] = func_8039DDA4_7AF454((struct071 *) temp_s1, 0U, temp_s1->unk222, temp_s1->unk223, (s16) (s32) temp_s1->unk212, (s16) (s32) temp_s1->unk213, (s16) (s32) temp_s1->unk214, (u8) (((s32) temp_v0_7 >> 8) & 0xF8), (u8) (((s32) temp_v0_7 >> 3) & 0xF8), (u8) ((temp_v0_7 * 4) & 0xF8), (u8) (((s32) temp_v1_4 >> 8) & 0xF8), (u8) (((s32) temp_v1_4 >> 3) & 0xF8), (u8) ((temp_v1_4 * 4) & 0xF8), (u8) 0, (u8) 0, (u8) 0, (u8) 1, (u8) 0, 0);
            return;
        case 0x8D:                                  /* switch 4 */
            temp_v0_8 = temp_s1->unk226;
            temp_v1_5 = temp_s1->unk228;
            temp_s1->unk248[8] = func_8039DDA4_7AF454((struct071 *) temp_s1, 1U, temp_s1->unk222, temp_s1->unk223, (s16) (s32) temp_s1->unk212, (s16) (s32) temp_s1->unk213, (s16) (s32) temp_s1->unk214, (u8) (((s32) temp_v0_8 >> 8) & 0xF8), (u8) (((s32) temp_v0_8 >> 3) & 0xF8), (u8) ((temp_v0_8 * 4) & 0xF8), (u8) (((s32) temp_v1_5 >> 8) & 0xF8), (u8) (((s32) temp_v1_5 >> 3) & 0xF8), (u8) ((temp_v1_5 * 4) & 0xF8), (u8) 0, (u8) 0, (u8) 0, (u8) 1, (u8) 0, 0);
            return;
        case 0x8E:                                  /* switch 4 */
            temp_v0_9 = temp_s1->unk226;
            temp_v1_6 = temp_s1->unk228;
            temp_s1->unk248[8] = func_8039DDA4_7AF454((struct071 *) temp_s1, 2U, temp_s1->unk222, temp_s1->unk223, (s16) (s32) temp_s1->unk212, (s16) (s32) temp_s1->unk213, (s16) (s32) temp_s1->unk214, (u8) (((s32) temp_v0_9 >> 8) & 0xF8), (u8) (((s32) temp_v0_9 >> 3) & 0xF8), (u8) ((temp_v0_9 * 4) & 0xF8), (u8) (((s32) temp_v1_6 >> 8) & 0xF8), (u8) (((s32) temp_v1_6 >> 3) & 0xF8), (u8) ((temp_v1_6 * 4) & 0xF8), (u8) 0, (u8) 0, (u8) 0, (u8) 1, (u8) 0, 0);
            return;
        case 0x91:                                  /* switch 4 */
            temp_v0_10 = temp_s1->unk226;
            temp_v1_7 = temp_s1->unk228;
            temp_s1->unk248[8] = func_8039E20C_7AF8BC(temp_s1, 2, temp_s1->unk222, 0x20, (s32) temp_s1->unk212, (s32) temp_s1->unk213, (s32) temp_s1->unk214, ((s32) temp_v0_10 >> 8) & 0xF8, ((s32) temp_v0_10 >> 3) & 0xF8, (temp_v0_10 * 4) & 0xF8, ((s32) temp_v1_7 >> 8) & 0xF8, ((s32) temp_v1_7 >> 3) & 0xF8, (temp_v1_7 * 4) & 0xF8, 1);
            return;
        default:                                    /* switch 4 */
            func_802FA730_70BDE0(temp_s1);
            /* fallthrough */
            return;
        }
        break;
    case 0x19:                                      /* switch 1 */
        temp_s0_16 = &arg0->unk19C;
        func_802F657C_707C2C(temp_s1, (s16) temp_s0_16->unk4, temp_s0_16->unk6, temp_s0_16->unk8, (s16) (s32) temp_s0_16->unkA);
        temp_s1->unk170 = 1;
        return;
    case 0x1A:                                      /* switch 1 */
        temp_s0_17 = &arg0->unk19C;
        func_802F657C_707C2C(temp_s1, (s16) temp_s0_17->unk4, temp_s0_17->unk6, temp_s0_17->unk8, (s16) (s32) temp_s0_17->unkA);
        temp_s1->unk170 = 2;
        return;
    case 0x1B:                                      /* switch 1 */
        temp_s0_18 = &arg0->unk19C;
        sp74 = get_game_state(temp_s1, (s16) temp_s0_18->unk4);
        temp_s2 = get_game_state(temp_s1, temp_s0_18->unk6);
        sp7C = get_game_state(temp_s1, temp_s0_18->unk8);
        func_802F657C_707C2C(temp_s1, (s16) (sp74 + temp_s1->xPos.h), (s16) (temp_s2 + temp_s1->zPos.h), (s16) (sp7C + temp_s1->yPos.h), (s16) get_game_state(temp_s1, temp_s0_18->unkA));
        temp_s1->unk170 = 1;
        return;
    case 0x1C:                                      /* switch 1 */
        temp_s0_19 = &arg0->unk19C;
        sp74 = get_game_state(temp_s1, (s16) temp_s0_19->unk4);
        temp_s2_2 = get_game_state(temp_s1, temp_s0_19->unk6);
        sp7C = get_game_state(temp_s1, temp_s0_19->unk8);
        func_802F657C_707C2C(temp_s1, (s16) (sp74 + temp_s1->xPos.h), (s16) (temp_s2_2 + temp_s1->zPos.h), (s16) (sp7C + temp_s1->yPos.h), (s16) get_game_state(temp_s1, temp_s0_19->unkA));
        temp_s1->unk170 = 2;
        return;
    case 0x1D:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType < 0x100) {
            temp_s0_20 = &arg0->unk19C;
            if (temp_s1->unk170 != 6) {
                func_802F9EB8_70B568(&sp12C, &sp130, &sp134, D_803E8E60[(u16) temp_s0_20->unk4], 0, ((u8) temp_s0_20->unkA == 1) == 0);
                temp_t5_2 = sp12C >> 0x10;
                sp12C = temp_t5_2;
                sp130 = sp130 >> 0x10;
                sp134 = sp134 >> 0x10;
                temp_v0_11 = temp_s1->xPos.h - temp_t5_2;
                if (temp_v0_11 < 0) {
                    var_v1 = -temp_v0_11;
                } else {
                    var_v1 = temp_v0_11;
                }
                if (var_v1 < 5) {
                    temp_v0_12 = temp_s1->zPos.h - sp130;
                    if (temp_v0_12 < 0) {
                        sp7C = -temp_v0_12;
                    } else {
                        sp7C = temp_v0_12;
                    }
                    if (sp7C < 5) {
                        if (!(temp_s1->unk4C & 4)) {
                            temp_v0_13 = temp_s1->yPos.h - sp134;
                            if (temp_v0_13 < 0) {
                                var_s2 = -temp_v0_13;
                            } else {
                                var_s2 = temp_v0_13;
                            }
                            if (var_s2 >= 5) {
                                goto block_102;
                            }
                            goto block_103;
                        }
block_103:
                        func_802F9E10_70B4C0(temp_s1, temp_s0_20->unk5, temp_s0_20->unk7, temp_s0_20->unk9, (u8) (s32) (u8) temp_s0_20->unkA, (u8) 0);
                        return;
                    }
                    goto block_102;
                }
block_102:
                temp_s1->unk170 = 6;
                func_802F657C_707C2C(temp_s1, unksp12E, unksp132, unksp136, (s16) (s32) (u16) temp_s0_20->unk6);
            }
        } else {
            temp_s0_21 = &arg0->unk19C;
            func_8036390C_774FBC(temp_s1, temp_s0_21->unk5, temp_s0_21->unk7, temp_s0_21->unk9, (s32) (u8) temp_s0_21->unkA, (s32) temp_s0_21->unkB);
            return;
        }
        break;
    case 0x1E:                                      /* switch 1 */
        temp_s0_22 = &arg0->unk19C;
        func_80363B98_775248(temp_s1, (s16) temp_s0_22->unk4, temp_s0_22->unk6, temp_s0_22->unk8, (s8) (s32) (s8) temp_s0_22->unkB, (u8) (s32) (u8) temp_s0_22->unkA);
        return;
    case 0x1F:                                      /* switch 1 */
        func_80363B34_7751E4(temp_s1, (u16) arg0->unk19E.unk2);
        return;
    case 0x20:                                      /* switch 1 */
        func_80363C0C_7752BC(temp_s1, arg0->unk1A1);
        return;
    case 0x21:                                      /* switch 1 */
        func_80319AA0_72B150(&temp_s1->unk18C, arg0->unk1A1);
        return;
    case 0x22:                                      /* switch 1 */
        func_80319AC4_72B174(&temp_s1->unk18C, arg0->unk1A1);
        return;
    case 0x24:                                      /* switch 1 */
        if (func_80349A14_75B0C4() != 0) {
            temp_v0_14 = get_game_state(temp_s1, arg0->unk19E.unk2);
            if (temp_v0_14 == 0) {
                func_80349AA0_75B150(0U);
                return;
            }
            if (D_803E4CA5 == 0) {
                func_80349AA0_75B150(temp_v0_14 & 0xFFFF);
                D_803E4CA5 = 1;
            } else if (D_803F2CDC == 1) {
                D_803E4CA5 = 0;
                return;
            }
        }
        break;
    case 0x25:                                      /* switch 1 */
        temp_s0_23 = &arg0->unk19C;
        func_802F2EEC_70459C(temp_s0_23->unk4, temp_s0_23->unk5, (u8) temp_s0_23->unk6, temp_s0_23->unk7, (u8) (s32) (u8) temp_s0_23->unk8, (u8) (s32) (u8) temp_s0_23->unk9, (u16) get_game_state(temp_s1, (s16) (u16) temp_s0_23->unkA));
        return;
    case 0x26:                                      /* switch 1 */
        temp_s0_24 = &arg0->unk19C;
        if ((u8) temp_s0_24->unkA != 0) {
            play_sound_effect_at_location((s16) temp_s0_24->unk4, temp_s0_24->unk6, 0, temp_s1->xPos.h, (s16) (s32) temp_s1->zPos.h, (s16) (s32) temp_s1->yPos.h, (f32) (u16) temp_s0_24->unk8 / 32767.0f);
            return;
        }
        func_8032C508_73DBB8((s16) temp_s0_24->unk4, temp_s0_24->unk6, 0, (f32) (u16) temp_s0_24->unk8 / 32767.0f);
        return;
    case 0x27:                                      /* switch 1 */
        temp_v1_8 = (u8) arg0->unk1A0;
        if (temp_v1_8 == -1U) {
            var_a0 = 1;
        } else {
            var_a0 = (s8) temp_v1_8;
        }
        func_803572B0_768960(var_a0);
        return;
        return;
    case 0x29:                                      /* switch 1 */
        D_803F2D50.unk1E = get_game_state(temp_s1, (s16) (u16) arg0->unk19E.unk2);
        return;
    case 0x2A:                                      /* switch 1 */
        D_803F2D50.unk1C = get_game_state(temp_s1, (s16) (u16) arg0->unk19E.unk2);
        return;
    case 0x2B:                                      /* switch 1 */
        // update score
        D_803F2D30.score += get_game_state(temp_s1, arg0->unk19E.unk2);
        return;
    case 0x2C:                                      /* switch 1 */
        temp_v0_15 = get_game_state(temp_s1, arg0->unk19E.unk2);
        temp_t6_2 = temp_v0_15 << 0x10;
        if (!(arg0->unk4C & 0x20) || ((temp_t6_2 >> 0x10) > 0)) {
            temp_s1->health += temp_v0_15;
        }
        return;
    case 0x2E:                                      /* switch 1 */
        func_80343AE0_755190(1U, 0, arg0->unk19E.unk2, NULL, (s16) 0, (s16) 0, (s16) 0, (u8) 0, (u8) 0, (u8) 0, (s16) 0, (u8) 1, (s8) -3, (s8) 5, (u8) 1);
        return;
    case 0x2F:                                      /* switch 1 */
        temp_s0_25 = &arg0->unk19C;
        temp_a0_3 = get_game_state(temp_s1, (s16) temp_s0_25->unk4);
        if (temp_s0_25->unk6 != 0) {
            func_803421E0_753890(temp_a0_3);
            return;
        }
        func_8034220C_7538BC(temp_a0_3, temp_s1->xPos.h, temp_s1->zPos.h, temp_s1->yPos.h);
        return;
    case 0x31:                                      /* switch 1 */
        temp_s0_26 = &arg0->unk19C;
        sp7C = get_game_state(temp_s1, temp_s0_26->unk6);
        func_802FF184_710834(temp_s1, 1, temp_s1->xPos.h, temp_s1->zPos.h, (s16) (temp_s1->yPos.h + ((s32) arg0->unk42 >> 1)), (s16) 0, (s16) 0, (s16) sp7C, (s16) get_game_state(temp_s1, (s16) temp_s0_26->unk4), (s16) -1);
        return;
    case 0x23:                                      /* switch 1 */
        temp_s0_27 = &arg0->unk19C;
        temp_s1->unk272 = (u16) temp_s0_27->unk4;
        temp_s1->unk2C8 = (u16) temp_s0_27->unk4;
        return;
    case 0x32:                                      /* switch 1 */
        temp_s0_28 = &arg0->unk19C;
        temp_s2_3 = get_game_state(temp_s1, temp_s0_28->unk6);
        var_v0_4 = get_game_state(temp_s1, temp_s0_28->unkA);
        temp_v1_9 = temp_s0_28->unk4;
        if (temp_v1_9 & 0x20) {
            if (temp_v1_9 & 1) {
                temp_s1->yRotation = var_v0_4;
                temp_s1->zRotation = temp_s2_3;
                return;
            }
            temp_s1->yRotation += var_v0_4;
            temp_s1->zRotation += temp_s2_3;
            temp_s1->yRotation = (s16) ((s16) temp_s1->yRotation % 360);
            temp_s1->zRotation = (s16) ((s16) temp_s1->zRotation % 360);
            return;
        }
        temp_a1_2 = temp_s1->zRotation;
        temp_s1->unk234[1] = 0;
        temp_s1->unk236 = temp_a1_2;
        temp_s1->unk23A = temp_s1->yRotation;
        temp_v1_10 = temp_s0_28->unk4;
        if ((temp_v1_10 & 1) && !(temp_v1_10 & 0x10)) {
            sp120 = var_v0_4;
            temp_s1->unk22E = func_802F63F8_707AA8(temp_s2_3, temp_a1_2, 0xB5);
            var_v0_4 = func_802F63F8_707AA8(var_v0_4, temp_s1->yRotation, 0xB5);
        } else {
            temp_s1->unk22E = temp_s2_3;
        }
        temp_s1->unk232 = var_v0_4;
        temp_s1->unk230 = 0;
        temp_s1->unk22C = temp_s0_28->unk4;
        temp_s1->unk22D = temp_s0_28->unk5;
        return;
    case 0x33:                                      /* switch 1 */
        temp_s1->unk3E = get_game_state(temp_s1, (s16) (u16) arg0->unk19E.unk2);
        return;
    case 0x34:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType < 0x100) {
            temp_s0_29 = &arg0->unk19C;
            if (temp_s1->unk170 != 6) {
                func_802F9E10_70B4C0(temp_s1, temp_s0_29->unk5, temp_s0_29->unk7, temp_s0_29->unk9, (u8) (s32) (u8) temp_s0_29->unkA, (u8) 1);
                return;
            }
        } else {
            temp_s0_30 = &arg0->unk19C;
            func_80363A0C_7750BC(temp_s1, (s16) temp_s0_30->unk5, (s16) temp_s0_30->unk7, (s16) temp_s0_30->unk9, (s8) (s32) (u8) temp_s0_30->unkA, (u8) (s32) temp_s0_30->unkB);
            return;
        }
        break;
    case 0x35:                                      /* switch 1 */
        temp_s0_31 = &arg0->unk19C;
        func_802FD26C_70E91C((temp_s0_31->unk4 + 4) & 0xFF, (temp_s0_31->unk5 + 8) & 0xFF, (u8) temp_s0_31->unk6, temp_s0_31->unk7, (s16) (get_game_state(temp_s1, temp_s0_31->unk8) >> 2));
        return;
    case 0x36:                                      /* switch 1 */
        temp_s1->unk40 = (u16) arg0->unk19E.unk2;
        func_802C9BA4_6DB254((struct071 *) temp_s1);
        return;
        return;
    case 0x37:                                      /* switch 1 */
        if (arg0 == D_803E4CA0) {
            D_803E4CA0 = 0;
            D_803E4CA4 = 0;
        }
        D_803F2CD0 = 0;
        return;
        return;
    case 0x39:                                      /* switch 1 */
        temp_s0_32 = &arg0->unk19C;
        if (temp_s0_32->unkA != 0) {
            func_80342318_7539C8(((s16) temp_s0_32->unk4 - temp_s1->xPos.h) << 0x10, (temp_s0_32->unk6 - temp_s1->zPos.h) << 0x10, (temp_s0_32->unk8 - temp_s1->yPos.h) << 0x10);
        }
        temp_s1->xPos.h = (s16) temp_s0_32->unk4;
        temp_s1->zPos.h = temp_s0_32->unk6;
        temp_s1->yPos.h = temp_s0_32->unk8;
        func_80311554_722C04(temp_s1->xPos.h, temp_s1->zPos.h, &sp10C, &sp110);
        if (((s32) temp_s1->unk16C->objectType >= 0x100) && (temp_s1->yPos.w < sp110)) {
            temp_s1->yPos.w = sp110;
        }
        if (sp10C == 0x40000000) {
            temp_s1->unk160 = 0;
            return;
        }
        if (temp_s1->yPos.w >= sp10C) {
            temp_s1->unk160 = 2;
            return;
        }
        temp_s1->unk160 = 1;
        return;
    case 0x3A:                                      /* switch 1 */
        temp_s0_33 = &arg0->unk19C;
        func_803638A8_774F58(temp_s1, func_803146A8_725D58(temp_s1, temp_s0_33->unk6, 0U), (s16) temp_s0_33->unk4);
        return;
    case 0x3B:                                      /* switch 1 */
        temp_s1->unk1CD = 0;
        return;
    case 0x3C:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType < 0x100) {
            temp_s1->unk170 = 4;
            temp_s1->yVelocity.w = 0;
            temp_s1->zVelocity.w = 0;
            temp_s1->xVelocity.w = 0;
            return;
        }
        func_803638E8_774F98(temp_s1);
        return;
    case 0x3D:                                      /* switch 1 */
        // do some maths
        temp_s0_34 = &arg0->unk19C;
        if (((u8) temp_s0_34->unkB >> 4) == 0) {
            // single operation
            var_s2_2 = get_game_state(temp_s1, (s16) temp_s0_34->unk4);
        } else {
            // double operation
            sp7C = get_game_state(temp_s1, (s16) temp_s0_34->unk4);
            var_s2_2 = func_803152A4_726954(sp7C, ((u8) temp_s0_34->unkB >> 4) & 0xFF, get_game_state(temp_s1, temp_s0_34->unk6));
            if ((s32) temp_s0_34->unk8 & 0xF) {
                var_s2_2 = func_803152A4_726954(var_s2_2, (s32) temp_s0_34->unk8 & 0xF, get_game_state(temp_s1, temp_s0_34->unk8));
            }
        }
        set_game_state(temp_s1, (s16) ((u8) temp_s0_34->unkA + 0x7F7F), var_s2_2);
        return;
    case 0x3E:                                      /* switch 1 */
        if ((D_803E8E56 == 0) && (func_802F1388_702A38() != 0)) {
            trigger_screen_transition(arg0->unk19E.unk2);
            D_803E8E56 = 1;
        }
        if (func_802F1388_702A38() != 0) {
            D_803E8E56 = 0;
            return;
        }
        break;
    case 0x3F:                                      /* switch 1 */
        func_80363844_774EF4(temp_s1, get_game_state(temp_s1, arg0->unk19E.unk2));
        return;
    case 0x40:                                      /* switch 1 */
        temp_a1_3 = func_803146A8_725D58(temp_s1, arg0->unk19E.unk2, 0U);
        if ((s32) temp_s1->unk16C->objectType >= 0x100) {
            func_80363880_774F30(temp_s1, temp_a1_3);
            return;
        }
        temp_s0_35 = temp_a1_3->xPos.h - temp_s1->xPos.h;
        temp_s2_4 = temp_a1_3->zPos.h - temp_s1->zPos.h;
        spF8 = (temp_a1_3->yPos.h + ((s32) temp_a1_3->unk42 >> 1)) - temp_s1->yPos.h;
        spF4 = (s32) (s16) (s32) sqrtf((f32) ((temp_s0_35 * temp_s0_35) + (temp_s2_4 * temp_s2_4)));
        temp_s1->yRotation = func_801284B8(temp_s0_35, temp_s2_4);
        temp_s1->zRotation = func_801284B8(spF8, spF4);
        return;
    case 0x41:                                      /* switch 1 */
        // set_level_complete
        func_8035739C_768A4C();
        return;
    case 0x42:                                      /* switch 1 */
        // increment unk4A
        func_802B33D0_6C4A80(func_803146A8_725D58(temp_s1, arg0->unk19E.unk2, 0U));
        return;
    case 0x43:                                      /* switch 1 */
        // decrement unk4A
        func_802B34B8_6C4B68(func_803146A8_725D58(temp_s1, arg0->unk19E.unk2, 0U));
        return;
    case 0x44:                                      /* switch 1 */
        temp_s0_36 = &arg0->unk19C;
        if ((s32) (u16) temp_s0_36->unk4 >= D_803F63C0) {
            return;
        }
        if ((D_803E4CA4 != 0) && (D_803E8E58 != 0)) {
            if ((arg0 == D_803E4CA0) && (func_80349874_75AF24() != 0)) {
                D_803E4CA4 = 0;
                D_803E4CA0 = 0;
                return;
            }
        } else if (func_80349874_75AF24() != 0) {
            D_803E4CA4 = 1;
            D_803E4CA0 = (s32) arg0;
            func_80314660_725D10();
            func_80349900_75AFB0(&D_803F34C0[D_803F3330[(u16) temp_s0_36->unk4]], (u16) temp_s0_36->unk6);
            D_803A8340_7B99F0 = (u16) temp_s0_36->unk4;
            if (D_803E8E58 == 0) {
                D_803E4CA4 = 0;
                return;
            }
        }
        break;
    case 69:                                      /* switch 1 */
        temp_s0_37 = &arg0->unk19C;
        temp_a1_4 = (s16) temp_s0_37->unk4;
        if (temp_a1_4 == 100) {
            func_80397734_7A8DE4(temp_s0_37->unk6, 0U);
            return;
        }
        if (temp_a1_4 == 101) {
            func_80397734_7A8DE4(temp_s0_37->unk6, 1U);
            return;
        }
        if (temp_a1_4 == 102) {
            func_80397734_7A8DE4(temp_s0_37->unk6, 2U);
            return;
        }
        if (temp_a1_4 == 300) {
            func_80328ACC_73A17C(temp_a1_4);
            return;
        }
        if (temp_a1_4 == 400) {
            D_803F6450 = temp_s0_37->unk6;
            return;
        }
        if (temp_a1_4 == 500) {
            D_803F2D50.pad5C[0x19] = 0;
            D_803F2DC6 = (s8) temp_s0_37->unk6;
            D_803F2DC7 = (s8) temp_s0_37->unk8;
            D_803F2DC8 = (s8) temp_s0_37->unkA;
            return;
        }
        if (temp_a1_4 == 600) {
            D_803F2D50.pad5C[0x19] = 1;
            return;
        }
        if (temp_a1_4 == 700) {
            D_803E8E57 = (u8) temp_s0_37->unk6;
            return;
        }
        if (temp_a1_4 == 800) {
            D_803E8E58 = (u8) temp_s0_37->unk6;
            return;
        }
        if (temp_a1_4 == 900) {
            func_8038B798_79CE48(temp_a1_4);
            return;
        }
        if (temp_a1_4 == 1000) {
            set_game_state(temp_s1, (s16) (temp_s0_37->unk8 + 0x7FBE), (s32) (cosf((f32) ((f64) (f32) get_game_state(temp_s1, temp_s0_37->unk6 + 0x7FBE) * 0.017453216666666667)) * 2048.0f));
            return;
        }
        if (temp_a1_4 == 1100) {
            set_game_state(temp_s1, (s16) (temp_s0_37->unk8 + 0x7FBE), (s32) (sinf((f32) ((f64) (f32) get_game_state(temp_s1, temp_s0_37->unk6 + 0x7FBE) * 0.017453216666666667)) * 2048.0f));
            return;
        }
        if (temp_a1_4 == 1200) {
            D_803A6CE0_7B8390 = temp_s0_37->unk6;
            return;
        }
        if (temp_a1_4 == 1300) {
            if (temp_s0_37->unk6 != 0) {
                D_803A6CE4_7B8394 |= 4;
                return;
            }
            D_803A6CE4_7B8394 &= 0xFFFB; // -4 ?
            return;
        }
        if (temp_a1_4 == 1400) {
            func_803441FC_7558AC();
        }
        return;
    case 0x46:                                      /* switch 1 */
        temp_s0_38 = &arg0->unk19C;
        temp_s1->unk23C = (s16) temp_s0_38->unk4;
        temp_s1->unk23E = (s16) temp_s0_38->unk6;
        temp_s1->unk240 = (s16) temp_s0_38->unk8;
        temp_s1->unk242 = temp_s0_38->unkA;
        temp_s1->unk242 = get_game_state(temp_s1, temp_s0_38->unkA);
        temp_s1->unk244 = 0;
        temp_s1->unk241 |= 4;
        return;
    case 0x47:                                      /* switch 1 */
        temp_s0_39 = &arg0->unk19C;
        if ((u8) temp_s0_39->unk8 != 0) {
            var_f2 = 1.0f;
        } else {
            temp_v0_16 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
            temp_f0 = (f32) (temp_s1->xPos.h - temp_v0_16->xPos.h);
            temp_f2 = (f32) (temp_s1->zPos.h - temp_v0_16->zPos.h);
            temp_f14 = (f32) (temp_s1->yPos.h - temp_v0_16->yPos.h);
            var_f2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14));
        }
        spEC = var_f2;
        do_rumble(0, get_game_state(temp_s1, (s16) (u16) temp_s0_39->unk4), (s16) (u8) temp_s0_39->unk6, (s16) temp_s0_39->unk7, (s32) var_f2);
        return;
    case 0x48:                                      /* switch 1 */
        temp_v0_17 = arg0->unk1CD;
        arg0->pad1D5[0] = temp_v0_17;
        arg0->unk1D6 = (s16) arg0->unk1CE;
        arg0->pad1D5[3] = arg0->pad1CE[2];
        arg0->pad1D5[4] = arg0->unk19C;
        arg0->unk1FC = (struct069 *) arg0->unk1A8;
        if (temp_v0_17 != 0) {
            var_v1_2 = 0;
            do {
                temp_v0_18 = arg0 + (var_v1_2 * 8);
                temp_t2 = (unaligned s32) arg0->unk1AC[var_v1_2].unk4.b[0];
                temp_v0_18->unk1DA = (unaligned s32) arg0->unk1AC[var_v1_2].unk0;
                var_v1_2 += 1;
                temp_v0_18->unk1DE = (unaligned s32) temp_t2;
            } while (var_v1_2 < 4);
        }
        arg0->unk1CD = 0;
        arg0->unk1CE = 0;
        arg0->pad1CE[2] = 0;
        arg0->unk248[0] = temp_s1;
        arg0->unk1A8 = (struct069 *) &D_803E4D40[(u16) arg0->unk19E.unk2];
        arg0->unk4F = (u8) (arg0->unk4F | 0x40);
        arg0->unk19C = 0xFF;
        return;
    case 0x49:                                      /* switch 1 */
        temp_t2_2 = arg0->pad1D5[0];
        arg0->unk19C = arg0->pad1D5[4] + 1;
        arg0->unk1CD = temp_t2_2;
        arg0->unk1CE = (s16) arg0->unk1D6;
        arg0->pad1CE[2] = arg0->pad1D5[3];
        arg0->unk1A8 = arg0->unk1FC;
        if (temp_t2_2 & 0xFF) {
            var_v1_3 = 0;
            do {
                temp_v0_19 = arg0 + (var_v1_3 * 8);
                temp_t4 = temp_v0_19->unk1DA;
                temp_t7_2 = temp_v0_19->unk1DC;
                temp_t9 = temp_v0_19->unk1DE;
                temp_t6_3 = temp_v0_19->unk1E0;
                var_v1_3 += 1;
                temp_v0_19->unk1AC = temp_t4;
                temp_v0_19->unk1AE = temp_t7_2;
                temp_v0_19->unk1B0 = temp_t9;
                temp_v0_19->unk1B2 = temp_t6_3;
            } while (var_v1_3 < 4);
        }
        arg0->unk248[0] = temp_s1;
        arg0->unk4F = (u8) (arg0->unk4F | 0x40);
        arg0->unk19C -= 1;
        return;
    case 0x4A:                                      /* switch 1 */
        temp_s1->unk246 = (u16) arg0->unk19E.unk2 + 1;
        return;
    case 0x4B:                                      /* switch 1 */
        temp_s0_40 = &arg0->unk19C;
        spD0 = get_game_state(temp_s1, (s16) temp_s0_40->unk4);
        temp_s2_5 = get_game_state(temp_s1, temp_s0_40->unk6);
        temp_v0_20 = get_game_state(temp_s1, temp_s0_40->unk8);
        var_v1_4 = temp_v0_20;
        if (temp_s0_40->unkA != 0) {
            spC8 = (s32) temp_v0_20;
            func_80342318_7539C8(spD0 << 0x10, temp_s2_5 << 0x10, temp_v0_20 << 0x10);
            var_v1_4 = (s16) spC8;
        }
        temp_s1->xPos.h += spD0;
        temp_s1->zPos.h += temp_s2_5;
        temp_s1->yPos.h += var_v1_4;
        func_80311554_722C04(temp_s1->xPos.h, temp_s1->zPos.h, &spD4, &spD8);
        if (((s32) temp_s1->unk16C->objectType >= 0x100) && (temp_s1->yPos.w < spD8)) {
            temp_s1->yPos.w = spD8;
        }
        if (spD4 == 0x40000000) {
            temp_s1->unk160 = 0;
            return;
        }
        if (temp_s1->yPos.w >= spD4) {
            temp_s1->unk160 = 2;
            return;
        }
        temp_s1->unk160 = 1;
        return;
    case 0x4C:                                      /* switch 1 */
        temp_s0_41 = &arg0->unk19C;
        temp_s2_6 = get_game_state(temp_s1, temp_s0_41->unk6);
        temp_v0_21 = get_game_state(temp_s1, temp_s0_41->unk8);
        if ((temp_s2_6 | temp_v0_21) == 0) {
            D_803E4AD0[(s16) temp_s0_41->unk4] = 0;
            return;
        }
        D_803E4AD0[(s16) temp_s0_41->unk4] = 1;
        D_803E2930[(s16) temp_s0_41->unk4].unk0 = (s32) temp_s2_6;
        D_803E2930[(s16) temp_s0_41->unk4].unk4 = (s32) temp_v0_21;
        return;
    case 0x4D:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType >= 0x100) {
            var_a0_2 = 2;
        } else if (temp_s1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            var_a0_2 = 1;
        } else {
            var_a0_2 = 3;
        }
        temp_s0_42 = &arg0->unk19C;
        temp_t5_3 = (s16) temp_s0_42->unkA >> 0xB;
        if (temp_t5_3 == 0xF) {
            var_t0 = -3;
            var_t1 = 5;
        } else {
            var_t0 = temp_t5_3 - 3;
            var_t1 = ((u8) temp_s0_42->unkB >> 3) - 3;
        }
        temp_v0_22 = (s32) temp_s0_42->unk8;
        func_80343AE0_755190(var_a0_2, (s16) temp_s0_42->unk4, (s16) temp_s0_42->unk5, (struct071 *) temp_s1, (s16) 0, (s16) 0, (s16) 0, (u8) (s32) (u8) temp_s0_42->unk6, (u8) (s32) temp_s0_42->unk7, (u8) (s32) (u8) temp_s0_42->unk8, (s16) (s32) (u8) temp_s0_42->unk9, (u8) (((u32) (temp_v0_22 << 0x15) >> 0x1F) == 0), (s8) (s32) var_t0, (s8) (s32) var_t1, (u8) ((u32) (temp_v0_22 << 0x16) >> 0x1F));
        return;
    case 0x4E:                                      /* switch 1 */
        temp_s0_43 = &arg0->unk19C;
        temp_t5_4 = (s16) temp_s0_43->unkA >> 0xB;
        if (temp_t5_4 == 0xF) {
            var_t0_2 = -3;
            var_t1_2 = 5;
        } else {
            var_t0_2 = temp_t5_4 - 3;
            var_t1_2 = ((u8) temp_s0_43->unkB >> 3) - 3;
        }
        temp_v0_23 = (s32) temp_s0_43->unk8;
        func_80343AE0_755190(4U, (s16) temp_s0_43->unk4, (s16) temp_s0_43->unk5, NULL, (s16) ((u8) temp_s0_43->unk6 << 5), (s16) (temp_s0_43->unk7 << 5), (s16) ((u8) temp_s0_43->unk8 << 5), (u8) 0, (u8) 0, (u8) 0, (s16) (s32) (u8) temp_s0_43->unk9, (u8) (((u32) (temp_v0_23 << 0x15) >> 0x1F) == 0), (s8) (s32) var_t0_2, (s8) (s32) var_t1_2, (u8) ((u32) (temp_v0_23 << 0x16) >> 0x1F));
        return;
    case 0x4F:                                      /* switch 1 */
        temp_s0_44 = &arg0->unk19C;
        temp_t7_3 = (s16) temp_s0_44->unkA >> 0xB;
        if (temp_t7_3 == 0xF) {
            var_a2 = -3;
            var_a3_3 = 5;
        } else {
            var_a2 = temp_t7_3 - 3;
            var_a3_3 = ((u8) temp_s0_44->unkB >> 3) - 3;
        }
        temp_v0_24 = (s32) temp_s0_44->unk8;
        func_80343C74_755324((s16) (u8) temp_s0_44->unk9, (s8) (((u32) (temp_v0_24 << 0x15) >> 0x1F) == 0), var_a2, var_a3_3, (u8) ((u32) (temp_v0_24 << 0x16) >> 0x1F));
        return;
    case 0x50:                                      /* switch 1 */
        temp_s0_45 = &arg0->unk19C;
        func_80343D44_7553F4((struct071 *) D_803E8E60[temp_s0_45->unk4], (s8) (temp_s0_45->unk5 == 0));
        return;
    case 0x51:                                      /* switch 1 */
        func_803637D4_774E84(temp_s1, func_803146A8_725D58(temp_s1, arg0->unk19E.unk4, 0U), 0x10U);
        return;
    case 0x52:                                      /* switch 1 */
        temp_s0_46 = &arg0->unk19C;
        temp_a1_5 = (s16) temp_s0_46->unk4;
        var_a0_3 = 0x24A;
        if (temp_a1_5 == 0) {
            var_s1 = 0x24A;
        } else {
            var_a0_3 = temp_a1_5;
            var_s1 = 0x3E8;
        }
        func_802FD94C_70EFFC(var_a0_3, var_s1, (u8) temp_s0_46->unk8, (u8) temp_s0_46->unk9, (u8) (s32) (u8) temp_s0_46->unkA, (s16) (s32) temp_s0_46->unk6);
        return;
    case 0x53:                                      /* switch 1 */
        temp_s0_47 = &arg0->unk19C;
        if ((u16) temp_s0_47->unk4 & 1) {
            temp_s1->unk4F = (u8) (temp_s1->unk4F | 0x20);
        } else {
            temp_s1->unk4F = (u8) (temp_s1->unk4F & 0xFFDF);
        }
        temp_s1->unk163 = (temp_s1->unk163 & 0xFFF8) | (u16) temp_s0_47->unk4;
        return;
    case 0x54:                                      /* switch 1 */
        temp_s0_48 = &arg0->unk19C;
        if ((s32) temp_s1->unk16C->objectType >= 0x100) {
            sp74 = get_game_state(temp_s1, (s16) temp_s0_48->unk4);
            temp_s2_7 = get_game_state(temp_s1, temp_s0_48->unk6);
            sp7C = get_game_state(temp_s1, temp_s0_48->unk8);
            func_80380620_791CD0(temp_s1, sp74, temp_s2_7, sp7C, (u8) get_game_state(temp_s1, temp_s0_48->unkA));
        }
        return;
    case 0x55:                                      /* switch 1 */
        func_80380644_791CF4(temp_s1);
        return;
    case 0x56:                                      /* switch 1 */
        temp_s0_49 = &arg0->unk19C;
        temp_s1_2 = func_803146A8_725D58(func_803146A8_725D58(arg0, temp_s0_49->unk8, 0U), temp_s0_49->unkA, 0U);
        (func_803146A8_725D58(arg0, (s16) temp_s0_49->unk4, 0U) + (temp_s0_49->unk6 * 4))->unk248 = temp_s1_2;
        return;
    case 0x57:                                      /* switch 1 */
        temp_s0_50 = &arg0->unk19C;
        temp_t3_3 = (((((s16) temp_s0_50->unk4 & 1) != 0) * 0x10) & 0x10) | (temp_s1->unk4F & 0xFFEF);
        temp_s1->unk4F = temp_t3_3;
        temp_t4_2 = (((((s16) temp_s0_50->unk4 & 4) != 0) * 8) & 8) | (temp_t3_3 & 0xF7);
        temp_s1->unk4F = temp_t4_2;
        temp_s1->unk4F = (u8) ((((((s16) temp_s0_50->unk4 & 2) != 0) * 4) & 4) | (temp_t4_2 & 0xFB));
        return;
    case 0x58:                                      /* switch 1 */
        temp_s0_51 = &arg0->unk19C;
        D_803F2D50.unkC = get_game_state(temp_s1, (s16) temp_s0_51->unk4);
        D_803F2D50.unkE = get_game_state(temp_s1, temp_s0_51->unk6);
        return;
    case 0x59:                                      /* switch 1 */
        temp_s0_52 = &arg0->unk19C;
        temp_v1_11 = (u32) temp_s0_52->unk4;
        temp_v0_25 = (u32) temp_s0_52->unk8;
        func_802FE560_70FC10((temp_s0_52->unk4 * 2) & 0xFF, ((u16) temp_s0_52->unk4 * 2) & 0xFF, ((u8) temp_s0_52->unk6 * 2) & 0xFF, (temp_v1_11 * 2) & 0xFF, (u8) (((u8) temp_s0_52->unk8 & 0x7F) * 2), (u8) (((u16) temp_s0_52->unk8 & 0x7F) * 2), (s16) (((u8) temp_s0_52->unkA & 0x7F) * 2), (u8) ((temp_v0_25 & 0x7F) * 2), (s16) ((temp_v1_11 >> 0x1F) | (((u8) temp_s0_52->unk5 >> 7) * 2) | (((u16) temp_s0_52->unk6 >> 0xF) * 4) | (((u8) temp_s0_52->unk7 >> 7) * 8) | ((temp_v0_25 >> 0x1F) * 0x10) | (((u8) temp_s0_52->unk9 >> 7) << 5) | (((u16) temp_s0_52->unkA >> 0xF) << 6) | (((u8) temp_s0_52->unkB >> 7) << 7)));
        return;
    case 0x5A:                                      /* switch 1 */
        func_80343DC0_755470();
        return;
    case 0x5B:                                      /* switch 1 */
        temp_s1->unk164 = get_game_state(temp_s1, arg0->unk19E.unk2);
        return;
    case 0x5C:                                      /* switch 1 */
        temp_s0_53 = &arg0->unk19C;
        func_80363738_774DE8(temp_s1, func_803146A8_725D58(temp_s1, temp_s0_53->unk6, 0U), (u16) temp_s0_53->unk4);
        return;
    case 0x5D:                                      /* switch 1 */
        func_8036379C_774E4C(temp_s1);
        return;
    case 0x5E:                                      /* switch 1 */
        temp_s0_54 = &arg0->unk19C;
        sp74 = get_game_state(temp_s1, (s16) temp_s0_54->unk4);
        temp_s2_8 = get_game_state(temp_s1, temp_s0_54->unk6);
        sp7C = get_game_state(temp_s1, temp_s0_54->unk8);
        func_802F657C_707C2C(temp_s1, (s16) (sp74 + temp_s1->xPos.h), (s16) (temp_s2_8 + temp_s1->zPos.h), (s16) (sp7C + temp_s1->yPos.h), (s16) get_game_state(temp_s1, temp_s0_54->unkA));
        temp_s1->unk170 = 5;
        return;
    case 0x5F:                                      /* switch 1 */
        if ((s32) temp_s1->unk16C->objectType >= 0x100) {
            var_a3_4 = (s16) ((s32) (temp_s1->zRotation * 0x168) >> 8);
            var_v0_6 = (s16) ((s32) (temp_s1->yRotation * 0x168) >> 8);
        } else {
            var_a3_4 = temp_s1->zRotation;
            var_v0_6 = temp_s1->yRotation;
        }
        temp_s0_55 = &arg0->unk19C;
        temp_a3_2 = var_a3_4 + ((s32) (temp_s0_55->unk9 * 0x168) >> 8);
        var_a3_5 = temp_a3_2;
        var_v0_7 = var_v0_6 + ((s32) ((s8) temp_s0_55->unk8 * 0x168) >> 8);
        if (temp_a3_2 >= 0x168) {
            var_a3_5 = temp_a3_2 - 0x168;
        } else if (var_a3_5 < 0) {
            var_a3_5 += 0x168;
        }
        if (var_v0_7 >= 0x168) {
            var_v0_7 -= 0x168;
        } else if (var_v0_7 < 0) {
            var_v0_7 += 0x168;
        }
        sp9A = var_a3_5;
        sp98 = var_v0_7;
        func_802F5F44_7075F4((s16) (s8) temp_s0_55->unk5, (s16) (s8) temp_s0_55->unk6, (s16) (s8) temp_s0_55->unk7, var_a3_5, (s16) (s32) var_v0_7, &spA4);
        func_802F5F44_7075F4(0, (s16) ((u8) temp_s0_55->unkA << 8), 0, sp9A, (s16) (s32) sp98, &sp9C);
        temp_v0_26 = spawn_animal((s16) (temp_s1->xPos.h + (s16) spA4), (s16) (temp_s1->zPos.h + spA4.unk2), (s16) (temp_s1->yPos.h + spA4.unk4), (s16) ((s32) (sp98 << 8) / 360), (s16) 0x7F, (s16) (s32) temp_s0_55->unk4, (s8) 0);
        if (temp_v0_26 != NULL) {
            arg0->unk248[7] = (Animal *) temp_v0_26->unk0[0].unk4;
            temp_v0_26->unk0[0].unk4->unk1C = (s32) ((s16) sp9C << 8);
            temp_v0_26->unk0[0].unk4->unk20 = (s32) (sp9C.unk2 << 8);
            temp_v0_26->unk0[0].unk4->unk24 = (s32) (sp9C.unk4 << 8);
        } else {
            arg0->unk248[7] = NULL;
        }
        if (arg0->unk248[7] == NULL) {

        } else {
            return;
        }
        break;
    case 0x60:                                      /* switch 1 */
        temp_s0_56 = &arg0->unk19C;
        temp_v0_27 = spawn_animal(temp_s0_56->unk6, temp_s0_56->unk8, temp_s0_56->unkA, 0, (s16) 0x7F, (s16) (s32) temp_s0_56->unk4, (s8) 0);
        if (temp_v0_27 != NULL) {
            arg0->unk248[7] = (Animal *) temp_v0_27->unk0[0].unk4;
        } else {
            arg0->unk248[7] = NULL;
        }
        if (arg0->unk248[7] == NULL) {

        } else {
            return;
        }
        break;
    case 0x61:                                      /* switch 1 */
        temp_s0_57 = &arg0->unk19C;
        func_802F657C_707C2C(temp_s1, (s16) temp_s0_57->unk4, temp_s0_57->unk6, temp_s0_57->unk8, (s16) (s32) temp_s0_57->unkA);
        temp_s1->unk170 = 5;
        return;
    case 0x62:                                      /* switch 1 */
        func_80343F58_755608(arg0->unk19E.unk2);
        return;
    case 0x63:                                      /* switch 1 */
        var_a2_2 = NULL;
        var_v0_8 = 0;
        if (D_803D553E > 0) {
loop_335:
            if (temp_s1 == D_801D9ED8.animals[var_v0_8].animal) {
                var_a2_2 = &D_801D9ED8.animals[var_v0_8];
            } else {
                var_v0_8 += 1;
                if (var_v0_8 < D_803D553E) {
                    goto loop_335;
                }
            }
        }
        D_803D5520 = var_a2_2;
        D_803D5524 = var_a2_2->unk0;
        temp_t8 = var_a2_2->animal;
        D_803D5528 = temp_t8;
        D_803D552C = temp_t8;
        D_803D5530 = temp_t8;
        if (var_v0_8 == gCurrentAnimalIndex) {
            D_803D5538 = 1;
        } else {
            D_803D5538 = 0;
        }
        D_803D553C = var_v0_8;
        D_803D553A = 0;
        temp_s0_58 = &arg0->unk19C;
        sp74 = (s16) temp_s0_58->unk4 == 0;
        temp_s2_9 = get_game_state(temp_s1, temp_s0_58->unk6, var_a2_2);
        sp7C = get_game_state(temp_s1, temp_s0_58->unk8);
        func_80364120_7757D0(unksp77, temp_s2_9, unksp7E, func_803146A8_725D58(temp_s1, temp_s0_58->unkA, 0U));
        return;
    case 0x64:                                      /* switch 1 */
        temp_s0_59 = &arg0->unk19C;
        temp_s1->unk226 = ((temp_s0_59->unk4 << 8) & 0xF800) | ((temp_s0_59->unk5 * 8) & 0x7C0) | (((s32) (u8) temp_s0_59->unk6 >> 2) & 0x3E);
        temp_t6_4 = ((temp_s0_59->unk7 << 8) & 0xF800) | (((u8) temp_s0_59->unk8 * 8) & 0x7C0) | (((s32) (u8) temp_s0_59->unk9 >> 2) & 0x3E);
        temp_v1_12 = temp_t6_4 & 0xFFFF;
        temp_s1->unk228 = temp_t6_4;
        if (temp_v1_12 != 0) {
            temp_s1->unk228 = temp_v1_12 | 1;
        }
        temp_v0_28 = temp_s1->unk226;
        if (temp_v0_28 != 0) {
            temp_s1->unk226 = temp_v0_28 | 1;
        }
        return;
    case 0x65:                                      /* switch 1 */
        temp_s0_60 = &arg0->unk19C;
        temp_t5_5 = temp_s0_60->unk5;
        switch (temp_t5_5) {                        /* switch 3 */
        case 0:                                     /* switch 3 */
            if (get_game_state(temp_s1, temp_s0_60->unk6) < 0) {
                var_a2_3 = -get_game_state(temp_s1, temp_s0_60->unk6);
            } else {
                var_a2_3 = get_game_state(temp_s1, temp_s0_60->unk6);
            }
// block_367:
            sp84 = (s32) var_a2_3;
            break;
        case 1:                                     /* switch 3 */
            var_a2_3 = (s16) (s32) sqrtf((f32) get_game_state(temp_s1, temp_s0_60->unk6));
            // goto block_367;
            sp84 = (s32) var_a2_3;
            break;
        case 2:                                     /* switch 3 */
            if (get_game_state(temp_s1, temp_s0_60->unk6) < 0) {
                var_a2_3 = -1;
            } else {
                var_a2_3 = 1;
            }
            // goto block_367;
            sp84 = (s32) var_a2_3;
            break;
        case 3:                                     /* switch 3 */
            sp80 = get_game_state(temp_s1, temp_s0_60->unk6);
            if (get_game_state(temp_s1, temp_s0_60->unk8) < sp80) {
                var_v0_9 = get_game_state(temp_s1, temp_s0_60->unk6);
            } else {
                var_v0_9 = get_game_state(temp_s1, temp_s0_60->unk8);
            }
            var_a2_3 = var_v0_9;
            // goto block_367;
            sp84 = (s32) var_a2_3;
            break;
        case 4:                                     /* switch 3 */
            sp80 = get_game_state(temp_s1, temp_s0_60->unk6);
            if (sp80 < get_game_state(temp_s1, temp_s0_60->unk8)) {
                var_v0_10 = get_game_state(temp_s1, temp_s0_60->unk6);
            } else {
                var_v0_10 = get_game_state(temp_s1, temp_s0_60->unk8);
            }
            var_a2_3 = var_v0_10;
            // goto block_367;
            sp84 = (s32) var_a2_3;
            break;
        case 5:                                     /* switch 3 */
            var_a2_3 = ~get_game_state(temp_s1, temp_s0_60->unk6);
            // goto block_367;
            sp84 = (s32) var_a2_3;
            break;
        }
        set_game_state(temp_s1, (s16) (temp_s0_60->unk4 + 0x7F7F), sp84);
        return;
#endif
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80316408_727AB8.s")
#endif

// unsure how correct this is?
void func_803190FC_72A7AC(Animal *arg0) {
    struct070 *cmds;
    s8 i;

    cmds = &arg0->unk1AC;
    for (i = 0; i < arg0->unk1CD; i++) {
        if (func_803159E4_727094(func_803146A8_725D58(arg0, cmds->unk1, 0), cmds) != 0) {
            arg0->unk19C = cmds->unk6 + 1;
            copy_command_struct(&arg0->unk1A8[arg0->unk19C], &arg0->unk19E);
            arg0->unk1CD = 0;
            arg0->unk1D4 = 0;
            return;
        }
        cmds++;
    }
}

void func_803191B0_72A860(Animal *arg0) {
    s8 temp_v0;

    if (arg0->unk1CC == 9) {
        arg0->unk248[0] = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    }
    if (arg0->unk1CD != 0) {
        func_803190FC_72A7AC(arg0);
    }

    do {
        temp_v0 = func_80316408_727AB8(arg0);
        if (temp_v0 != 0) {
            arg0->unk19C++;
            copy_command_struct(&arg0->unk1A8[arg0->unk19C], &arg0->unk19E);
        }
    } while (temp_v0 == 69);
}
