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
            res = (arg0 - 133)->pad33C[arg1 - 133];
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

void copy_command_struct(struct112 *source, struct112 *dest) {
    dest->cmd.regular.unk2 = source->cmd.regular.unk2;
    dest->cmd.regular.unk4 = source->cmd.regular.unk4;
    dest->cmd.regular.unk6 = source->cmd.regular.unk6;
    dest->cmd.regular.unk8 = source->cmd.regular.unk8;
    dest->type = source->type;
}

void load_commands_into_object(Animal *arg0, struct112 cmds[], u8 count) {
    arg0->unk1A8 = cmds;
    arg0->unk19C.count = count;
    arg0->numCommandsToCopy = 0;
    arg0->unk1CC = 0;
    arg0->unk248[0] = arg0;
    if (cmds != NULL) {
        copy_command_struct(&cmds[count], &arg0->unk19C.payload);
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

s32 func_80315870_726F20(Animal *arg0, s16 arg1) {
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

// is_animal_helper
s32 func_80315924_726FD4(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
        return 1;
    } else {
        return 0;
    }
}

// is_animal
s32 func_80315950_727000(s16 arg0) {
    return func_80315658_726D08(arg0, &func_80315924_726FD4, 0);
}

// is_object_helper
s32 func_80315984_727034(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET) {
        return 1;
    } else {
        return 0;
    }
}

// is_object
s32 func_803159B0_727060(s16 arg0) {
    return func_80315658_726D08(arg0, &func_80315984_727034, 0);
}


// regalloc is really off...
#if 0

typedef struct {
    u8  unk0;
    u8  unk1;
    u8  unk2;
    u8  unk3;
    u8  unk4;
    u8  unk5;
    u16 alignment;
} DefaultCmd;

typedef struct {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    u16 alignment;
} Cmd4;


u8 func_803159E4_727094(Animal *arg0, DefaultCmd *arg1) {
    u16 res;
    u16 sp3C;
    s16 sp26;
    s32 water_level;
    u8  pad[0xC];

    res = 0;

    sp3C = arg1->unk0 & 0x80;     // 10000000

    switch (arg1->unk0 & ~0xC0) { // 00111111
    case 0:
        if (arg1->unk2 & 8) {
            if (func_80315880_726F30(arg1->unk3)) { // always returns true
                res = 1;
                break;
            }
        }
        if (arg1->unk2 & 1) {
            if (func_803159B0_727060(arg1->unk3)) {
                res = 1;
                break;
            }
        }
        if (arg1->unk2 & 2) {
            res = 1;
            break;
        }
        if (arg1->unk2 & 0x10) {
            if (func_80319E1C_72B4CC(
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h >> 6,
                arg1->unk3,
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160)) {

                res = 1;
                break;
            }
        }
        if (arg1->unk2 & 4) {
            if (func_80315950_727000(arg1->unk3)) {
                res = 1;
                break;
            }
        }
        if (arg1->unk2 & 0x20) {
            if (func_803158E4_726F94(arg1->unk3, arg1->unk5 + OB_TYPE_ANIMAL_OFFSET)) {
                res = 1;
                break;
            }
        }
        if (arg1->unk2 & 0x40) {
            if (func_803158E4_726F94(arg1->unk3, arg1->unk4)) {
                res = 1;
                break;
            }
        }
        break;

    case 1:
        if ((arg0->unk162 != 4) && (arg0->unk162 != 5) && (arg0->unk162 != 6) && (arg0->unk162 != 7)) {

            if (1) {}; // ?

            water_level = GET_WATER_LEVEL(D_803C0740, arg0->xPos.h, arg0->zPos.h);

            if (arg0->yPos.h < (water_level * 4)) {
                res = 1;
                break;
            }
        }
        // m2c things there is an else here?
        break;
    case 2:
        if (((Cmd4*)arg1)->unk2 == arg0->state) {
            res = 1;
        }
        break;
    case 3:
        water_level = GET_WATER_LEVEL(D_803C0740, arg1->unk4 << 6, arg1->unk5 << 6);
        if (get_game_state(arg0, ((Cmd4*)arg1)->unk2) < (water_level * 4)) {
            res = 1;
        }
        break;
    case 4:
        // state matches?
        if ((arg1->unk2 & 8) && (arg0->unk5C & 8)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 1) && (arg0->unk5C & 1)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 2) && (arg0->unk5C & 2)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x10) && (arg0->unk5C & 0x10)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 4) && (arg0->unk5C & 4)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x20) && (arg0->unk5C & 4) && (arg0->unk5D == arg1->unk5)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x40) && (arg0->unk5C & 1) && (arg0->unk5D == arg1->unk4)) {
            res = 1;
            break;
        }
        break;

    case 5:
        if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
            // it's an animal
            if (arg0->waypointType == 0) {
                res = 1;
            }
        } else if (arg0->unk170 == 0) {
            res = 1;
        }
        break;
    case 6:
        if ((arg0 != NULL) && (arg0->unk26C != 1)) {
            res = 1;
        }
        break;
    case 7:
    case 8:
        if (D_803F2AA4 != 0) {
            res = 1;
        }
        break;
    case 9:
        sp26 = func_802FD5DC_70EC8C(arg0);
        if (sp26 >= get_game_state(arg0, ((Cmd4*)arg1)->unk2)) {
            res = 1;
        }
        break;
    case 11:
        if ((arg1->unk2 & 8) && (func_802FD3B8_70EA68(arg0))) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 1) && (func_802FD4D0_70EB80(arg0))) {
            res = 1;
            break;
        }
        if (((arg1->unk2 & 0x10) && ((func_802FD40C_70EABC(arg0, D_801D9ED8.animals[gCurrentAnimalIndex].animal)))) || (func_802FD538_70EBE8(arg0))) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 4) && (func_802FD468_70EB18(arg0))) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x20) && (func_802FD348_70E9F8(arg0, (arg1->unk5 + OB_TYPE_ANIMAL_OFFSET)))) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x40) && (func_802FD348_70E9F8(arg0, arg1->unk4))) {
            res = 1;
            break;
        }
        break;
    case 14:
        if (D_803A52B8_7B6968 != 0) {
            res = 1;
        }
        break;
    case 15:
        if (arg0->unk22C == 0) {
            res = 1;
        }
        break;
    case 16:
        if (func_80319E1C_72B4CC(
              arg0->xPos.h >> 6,
              arg0->zPos.h >> 6,
              arg0->yPos.h >> 6,
              arg1->unk3,
              arg0->unk160)) {
            res = 1;
        }
        break;

    case 17:
        if (get_game_state(arg0, ((Cmd4*)arg1)->unk2) <  get_game_state(arg0, ((Cmd4*)arg1)->unk4)) {
            res = 1;
        }
        break;
    case 18:
        if (get_game_state(arg0, ((Cmd4*)arg1)->unk2) <= get_game_state(arg0, ((Cmd4*)arg1)->unk4)) {
            res = 1;
        }
        break;
    case 19:
        if (get_game_state(arg0, ((Cmd4*)arg1)->unk2) == get_game_state(arg0, ((Cmd4*)arg1)->unk4)) {
            res = 1;
        }
        break;
    case 20:
        if (get_game_state(arg0, ((Cmd4*)arg1)->unk2) >= get_game_state(arg0, ((Cmd4*)arg1)->unk4)) {
            res = 1;
        }
        break;
    case 21:
        if (get_game_state(arg0, ((Cmd4*)arg1)->unk2) >  get_game_state(arg0, ((Cmd4*)arg1)->unk4)) {
            res = 1;
        }
        break;
    case 22:
        if ((arg1->unk2 & 1) && (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x10) && (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 4) && (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET)) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x20) && (arg0->unk16C->objectType == (arg1->unk5 + OB_TYPE_ANIMAL_OFFSET))) {
            res = 1;
            break;
        }
        if ((arg1->unk2 & 0x40) && (arg0->unk16C->objectType == arg1->unk4)) {
            res = 1;
            break;
        }
        if (arg1->unk2 & 8) {
            res = 1;
            break;
        }
        break;
    case 23:
        if (((Cmd4*)arg1)->unk2 == arg0->unk5F) {
            res = 1;
        }
        break;
    }

    if (sp3C) {
        res ^= 1; // & 0xFFFF;
    }

    return res; // & 0xFF;
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_803159E4_727094.s")
#endif

// absolutely huge function
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80316408_727AB8.s")

// unsure how correct this is?
void func_803190FC_72A7AC(Animal *arg0) {
    struct070 *cmds;
    s8 i;

    cmds = &arg0->unk1AC;
    for (i = 0; i < arg0->numCommandsToCopy; i++) {
        if (func_803159E4_727094(func_803146A8_725D58(arg0, cmds->unk1, 0), cmds) != 0) {
            // finished?
            arg0->unk19C.count = cmds->unk6 + 1;
            copy_command_struct(&arg0->unk1A8[arg0->unk19C.count], &arg0->unk19C.payload);
            arg0->numCommandsToCopy = 0;
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
    if (arg0->numCommandsToCopy != 0) {
        func_803190FC_72A7AC(arg0);
    }

    do {
        // get_next_command?
        temp_v0 = func_80316408_727AB8(arg0);
        if (temp_v0 != 0) {
            arg0->unk19C.count++;
            copy_command_struct(&arg0->unk1A8[arg0->unk19C.count], &arg0->unk19C.payload);
        }
    } while (temp_v0 == 69);
}
