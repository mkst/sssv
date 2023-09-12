#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

extern s32 D_803C4DAC_7D645C[]; // is this D_803E4BA8 - 0x7F7F?

// ========================================================
// .bss
// ========================================================

Animal *D_803E4CA0;
u8   D_803E4CA4;
u8   D_803E4CA5;
u8   D_803E4CA6;
s32  D_803E4CA8[32];
s32  D_803E4D28;
s32  D_803E4D2C; // completed tasks?
s32  D_803E4D30;
s32  D_803E4D38[2];
struct112 D_803E4D40[1666]; // BIG_DAY_PARADE is 1666 commands long
u16  D_803E8E54;
u8   D_803E8E56;
u8   D_803E8E57;
u8   D_803E8E58;

// ========================================================
// .text
// ========================================================

void func_80314660_725D10(void) {
    s16 i;
    for (i = 0; i < 32; i++) {
        D_8023F208[i] = D_803E4CA8[i];
    }
}

// ESA: func_80047108
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
    case 10: // get_first?
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

// ESA: func_800471D8
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
    D_803E4CA0 = NULL;
    D_801546E0 = 0x800;
    D_801546D8 = 0x800;
    func_803976E0_7A8D90(); // initialise something...
    D_803E8E57 = 1;
    D_803E8E58 = 1;
}

void set_game_state(Animal *arg0, s16 arg1, s32 arg2) {
    Animal2 *var_t1;
    s16 new_var;
    s16 i;

    switch (arg1) {
    case 0+0x7F7F:    // 0
    case 1+0x7F7F:    // 1
    case 2+0x7F7F:    // 2
        arg0->unk200[arg1-0x7F7F] = arg2;
        break;

    case 3+0x7F7F:    // 3
        arg0->unk158 = arg2;
        arg0->unk15E = arg2;
        break;

    case ST_SET_HEALTH:    // 4
        if (!(arg0->unk4C.unk1A /* & 0x20 */) || (arg0->health < arg2)) {
            if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
                if (arg2 < arg0->health) {
                    func_80349280_75A930(arg0, arg0->health - arg2);
                }
            }
            arg0->health = MIN(0x7F, MAX(0, arg2));
        }
        break;

    case 5+0x7F7F:
        func_8012822C(arg2); // update game time?
        break;

    case ST_SET_XPOS:
        arg0->xPos.w = arg2 << 16;
        func_803136B0_724D60(arg0);
        break;

    case ST_SET_ZPOS:
        arg0->zPos.w = arg2 << 16;
        func_803136B0_724D60(arg0);
        break;

    case ST_SET_YPOS:
        arg0->yPos.w = arg2 << 16;
        func_803136B0_724D60(arg0);
        break;

    case 9+0x7F7F:
        arg0->unk40 = arg2;
        func_802C9BA4_6DB254(arg0);
        break;

    case 10+0x7F7F:
        func_80349AA0_75B150(arg2);
        break;

    case ST_SET_XVEL:
        arg0->xVelocity.w = arg2 << 5;
        break;

    case ST_SET_ZVEL:
        arg0->zVelocity.w = arg2 << 5;
        break;

    case ST_SET_YVEL:
        arg0->yVelocity.w = arg2 << 5;
        break;

    case ST_SET_ZROT:
        if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
            arg0->zRotation = (s16) (((arg2 << 8) / 360) & 0xFF);
        } else {
            // is 1800 a typo?
            func_802C9918_6DAFC8(arg0, (s16) ((arg2 + 1800) % 360), arg0->yRotation);
        }
        break;

    case ST_SET_YROT:
        if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
            arg0->yRotation = (s16) (((s32) (arg2 * 256) / 360) & 0xFF);
            arg0->unk302 = (s16) arg0->yRotation;
        } else {
            func_802C9918_6DAFC8(arg0, arg0->zRotation, (s16) ((s32) (arg2 + 1800) % 360));
        }
        break;

    case 16+0x7F7F:
        arg0->unk248[0] = func_803146A8_725D58(arg0, arg2 % 100, (arg2 / 100));
        arg0->commands.unk1CC = arg2 % 100;
        break;

    case 17+0x7F7F:
        if (arg2 & 1) {
            arg0->unk163 &= ~0x8;
        } else {
            arg0->unk163 |= 0x8;
        }
        if (arg2 & 2) {
            arg0->unk163 |= 0x10;
        } else {
            arg0->unk163 &= ~0x10;
        }
        if (arg2 & 4) {
            arg0->unk163 |= 0x40;
        } else {
            arg0->unk163 &= ~0x40;
        }
        if (arg2 & 8) {
            arg0->unk163 |= 0x80;
        } else {
            arg0->unk163 &= ~0x80;
        }
        break;

    case 18+0x7F7F: // set mass?
        arg0->unk46 = arg2;
        arg0->unk44 = (arg0->unk46 * arg0->unk40) >> 0xB;
        break;

    case ST_SET_SCORE:    // 19
        D_803F2D30.score = arg2;
        break;

    case 20+0x7F7F:
        arg0->unk3E = arg2;
        break;

    case ST_SET_STATE:
        arg0->state = arg2;
        break;

    case 22+0x7F7F:
        D_803F2CD8 = ABS(arg2);
        new_var = SIGNUM(arg2);
        D_803F2CD6 = new_var;
        break;

    case 23+0x7F7F:
        D_803A05B0_7B1C60 = arg2 << 6;
        D_803A05B4_7B1C64 = D_803A05B0_7B1C60 << 1;
        break;

    case 24+0x7F7F:
    case 25+0x7F7F:
    case 26+0x7F7F:
    case 27+0x7F7F:
        break;

    case 28+0x7F7F:
        D_803E4D2C = arg2;
        break;

    case 29+0x7F7F:
        D_803F2D50.unkE0 = arg2 / 100.0f;
        break;

    case 30+0x7F7F:
        D_803E4D30 = arg2;
        break;

    case 31+0x7F7F:
        D_8023F260.unk30 = D_803E4D38[0] = arg2;
        write_eeprom(D_803F7DD6);
        break;

    case 32+0x7F7F:
        // is arg2 an object ID?
        if (arg2 < OB_TYPE_ANIMAL_OFFSET) {
            arg0->unk16C = &D_801E9EB8.unk0[arg2];
            func_802C9BA4_6DB254(arg0);
        } else {
            // arg2 is an animal ID
            var_t1 = NULL;
            for (i = 0; i < D_803D553E; i++) {
                if ((arg0 == D_801D9ED8.animals[i].animal) && (D_801D9ED8.animals[i].animal->unk366 != 6)) {
                    var_t1 = &D_801D9ED8.animals[i];
                    break;
                }
            }
            if (var_t1 != NULL) {
                arg0->unk16C = var_t1->unk0 = &D_801D9ED8.unk0[arg2-OB_TYPE_ANIMAL_OFFSET];

                D_803D5520 = var_t1;
                D_803D5524 = var_t1->unk0;
                D_803D5528 = var_t1->animal;
                D_803D552C = D_803D5528;
                D_803D5530 = D_803D5528;
                if (i == gCurrentAnimalIndex) {
                    D_803D5538 = 1;
                } else {
                    D_803D5538 = 0;
                }
                D_803D553C = i;
                D_803D553A = 0;

                func_802B2EA8_6C4558();
                if (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
                    D_803E9824 = arg2 - OB_TYPE_ANIMAL_OFFSET;
                    D_803E9820 = D_803A63B0_7B7A60[D_803E9824].unk0;
                    D_803E9822 = D_803A63B0_7B7A60[D_803E9824].unk1;
                    func_80327DA8_739458();
                }
                func_802C9BA4_6DB254(arg0);
            }
        }
        break;
    case 33+0x7F7F:
        D_801546E0 = arg2;
        break;

    case 34+0x7F7F:
        D_801546D8 = MAX(arg2, 0);
        break;

    case 35+0x7F7F:
        D_8023F260.unk34 = D_803E4D38[1] = arg2;
         // arg2;
        write_eeprom(D_803F7DD6);
        break;

    case 36+0x7F7F:
        D_803E4D28 = arg2;
        break;

    default:
        D_803C4DAC_7D645C[arg1] = arg2;
        break;
    }
}

s32 get_game_state(Animal *arg0, s32 arg1) {
    s32 res;

    if (arg1 < 0x7F7F) {
        res = arg1;
    } else {
        switch (arg1) {
        case 0+0x7F7F:
        case 1+0x7F7F:
        case 2+0x7F7F:
            res = arg0->unk200[arg1 - 0x7F7F]; // some color?
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
            res = arg0->commands.unk1CC;
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

s32 do_maths_op(s32 left, u8 op, s32 right) {
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
    dest->cmd.regular.unk0 = source->cmd.regular.unk0;
    dest->cmd.regular.unk2 = source->cmd.regular.unk2;
    dest->cmd.regular.unk4 = source->cmd.regular.unk4;
    dest->cmd.regular.unk6 = source->cmd.regular.unk6;
    dest->type = source->type;
}

void load_commands_into_object(Animal *arg0, struct112 cmds[], u8 count) {
    arg0->commands.unk1A8 = cmds;
    arg0->commands.unk19C.count = count;
    arg0->commands.numCommandsToCopy = 0;
    arg0->commands.unk1CC = 0;
    arg0->unk248[0] = arg0;
    if (cmds != NULL) {
        copy_command_struct(&cmds[count], &arg0->commands.unk19C.payload);
    }
}

// ESA: func_80047DC4
Animal *func_8031540C_726ABC(s16 arg0, u8 arg1) {
    u64 sp48;
    s16 j;
    s16 i;
    Animal *ret;
    s32 var_s2;
    struct065 *var_s0;

    static Animal *D_803E8E5C;

    if (arg1) {
        D_803E8E5C = NULL;
        var_s2 = 1;
    } else {
        var_s2 = 0;
    }

    i = 0;
    ret = NULL;
    sp48 = D_803E95B8[arg0];

    while ((i < 0x28) && (sp48 != 0)) {
        if (sp48 & 0xFF) {
            for (j = 0; j < 8; j++) {
                if (((sp48 & ((s64)1 << j)))) {
                    for (var_s0 = D_803DA110[i+j].next; var_s0 != NULL; var_s0 = var_s0->next) {
                        if ((var_s0->animal->unk16C->objectType != (256+EVO_TRANSFER)) && ((i + j) == var_s0->animal->unk114[0])) {
                            if ((D_803E8E5C == var_s0->animal) || (func_80319E1C_72B4CC(var_s0->animal->xPos.h >> 6, var_s0->animal->zPos.h >> 6, var_s0->animal->yPos.h >> 6, arg0 , var_s0->animal->unk160) != 0)) {
                                if (var_s2 != 0) {
                                    D_803E8E5C = var_s0->animal;
                                    ret = var_s0->animal;
                                    goto done;
                                } else {
                                    if (D_803E8E5C == var_s0->animal) {
                                        var_s2 = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        sp48 = sp48 >> 8;
        i += 8;
    }

done:
    if (ret == NULL) {
        D_803E8E5C = NULL;
    }
    return ret;
}

// ESA: func_80048040
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

// ESA: func_8004826C
s32 func_80315870_726F20(Animal *arg0, s16 arg1) {
    return 1;
}

// ESA: func_80048274
s32 func_80315880_726F30(s16 arg0) {
    return func_80315658_726D08(arg0, &func_80315870_726F20, 0);
}

// ESA: func_800482A4
s32 is_object_type_helper(Animal *arg0, s16 arg1) {
    if (arg1 == arg0->unk16C->objectType) {
        return 1;
    } else {
        return 0;
    }
}

// ESA: func_80048040
s32 is_object_type(s16 arg0, s16 arg1) {
    return func_80315658_726D08(arg0, &is_object_type_helper, arg1);
}

// ESA: func_800482F4
s32 is_animal_helper(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
        return 1;
    } else {
        return 0;
    }
}

// ESA: func_80048040
s32 is_animal(s16 arg0) {
    return func_80315658_726D08(arg0, &is_animal_helper, 0);
}

// ESA: func_80048340
s32 is_object_helper(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET) {
        return 1;
    } else {
        return 0;
    }
}

// ESA: func_80048354
s32 is_object(s16 arg0) {
    return func_80315658_726D08(arg0, &is_object_helper, 0);
}

u8 run_single_command(Animal *arg0, Cmd *arg1) {
    u16 res;
    u16 sp3C;

    res = 0;

    sp3C = arg1->dummy.unk0 & 0x80;     // 10000000 // is a multi-step command?

    switch (arg1->dummy.unk0 & ~0xC0) { // 00111111
    case 0:
        if (arg1->dummy.unk2 & 8) {
            if (func_80315880_726F30(arg1->dummy.unk3)) { // always returns true
                res = 1;
                break;
            }
        }
        if (arg1->dummy.unk2 & 1) {
            if (is_object(arg1->dummy.unk3)) {
                res = 1;
                break;
            }
        }
        if (arg1->dummy.unk2 & 2) {
            res = 1;
            break;
        }
        if (arg1->dummy.unk2 & 0x10) {
            if (func_80319E1C_72B4CC(
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h >> 6,
                arg1->dummy.unk3,
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160)) {

                res = 1;
                break;
            }
        }
        if (arg1->dummy.unk2 & 4) {
            if (is_animal(arg1->dummy.unk3)) {
                res = 1;
                break;
            }
        }
        if (arg1->dummy.unk2 & 0x20) {
            if (is_object_type(arg1->dummy.unk3, arg1->dummy.unk5 + OB_TYPE_ANIMAL_OFFSET)) {
                res = 1;
                break;
            }
        }
        if (arg1->dummy.unk2 & 0x40) {
            if (is_object_type(arg1->dummy.unk3, arg1->dummy.unk4)) {
                res = 1;
                break;
            }
        }
        break;

    case 1:
        if ((arg0->unk162 == 4) || (arg0->unk162 == 5) || (arg0->unk162 == 6) || (arg0->unk162 == 7) || (arg0->yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->xPos.h, arg0->zPos.h) * 4))) {
            res = 1;
        }
        break;
    case 2:
        if (arg0->state == arg1->regular.unk2) {
            res = 1;
        }
        break;
    case 3:
        if ((GET_WATER_LEVEL(D_803C0740, arg1->dummy.unk4 << 6, arg1->dummy.unk5 << 6) * 4) > get_game_state(arg0, arg1->regular.unk2)) {
            res = 1;
        }
        break;
    case 4:
        // state matches?
        if ((arg1->dummy.unk2 & 8) && (arg0->unk5C & 8)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 1) && (arg0->unk5C & 1)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 2) && (arg0->unk5C & 2)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x10) && (arg0->unk5C & 0x10)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 4) && (arg0->unk5C & 4)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x20) && (arg0->unk5C & 4) && (arg1->dummy.unk5 == arg0->unk5D)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x40) && (arg0->unk5C & 1) && (arg1->dummy.unk4 == arg0->unk5D)) {
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
        if (func_802FD5DC_70EC8C(arg0) >= get_game_state(arg0, arg1->regular.unk2)) {
            res = 1;
        }
        break;
    case 11:
        if ((arg1->dummy.unk2 & 8) && (func_802FD3B8_70EA68(arg0))) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 1) && (func_802FD4D0_70EB80(arg0))) {
            res = 1;
            break;
        }
        if (((arg1->dummy.unk2 & 0x10) && ((func_802FD40C_70EABC(arg0, D_801D9ED8.animals[gCurrentAnimalIndex].animal)))) || (func_802FD538_70EBE8(arg0))) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 4) && (func_802FD468_70EB18(arg0))) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x20) && (func_802FD348_70E9F8(arg0, (arg1->dummy.unk5 + OB_TYPE_ANIMAL_OFFSET)))) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x40) && (func_802FD348_70E9F8(arg0, arg1->dummy.unk4))) {
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
              arg1->dummy.unk3,
              arg0->unk160)) {
            res = 1;
        }
        break;

    case 17:
        if (get_game_state(arg0, arg1->regular.unk2) <  get_game_state(arg0, arg1->regular.unk4)) {
            res = 1;
        }
        break;
    case 18:
        if (get_game_state(arg0, arg1->regular.unk2) <= get_game_state(arg0, arg1->regular.unk4)) {
            res = 1;
        }
        break;
    case 19:
        if (get_game_state(arg0, arg1->regular.unk2) == get_game_state(arg0, arg1->regular.unk4)) {
            res = 1;
        }
        break;
    case 20:
        if (get_game_state(arg0, arg1->regular.unk2) >= get_game_state(arg0, arg1->regular.unk4)) {
            res = 1;
        }
        break;
    case 21:
        if (get_game_state(arg0, arg1->regular.unk2) >  get_game_state(arg0, arg1->regular.unk4)) {
            res = 1;
        }
        break;
    case 22:
        if ((arg1->dummy.unk2 & 1) && (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x10) && (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 4) && (arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET)) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x20) && (arg0->unk16C->objectType == (arg1->dummy.unk5 + OB_TYPE_ANIMAL_OFFSET))) {
            res = 1;
            break;
        }
        if ((arg1->dummy.unk2 & 0x40) && (arg0->unk16C->objectType == arg1->dummy.unk4)) {
            res = 1;
            break;
        }
        if (arg1->dummy.unk2 & 8) {
            res = 1;
            break;
        }
        break;
    case 23:
        if (arg1->regular.unk2 == arg0->unk5F) {
            res = 1;
        }
        break;
    }

    if (sp3C) {
        // invert result
        res ^= 1;
    }

    return res;
}

// get_next_command?
#ifdef NON_MATCHING
s32 func_80316408_727AB8(Animal *arg0) {
    s32 pad[0x6];

    struct077 sp148;
    struct077 sp140;
    s16 sp13E;
    s16 sp13C;

    s16 sp138[2]; // pad

    s32 sp134;
    s32 sp130;
    s32 sp12C;

    s32 sp124[6]; // pad

    s16 sp120;

    s32 sp110;
    s32 sp10C;

    Animal *tmp2;
    Animal *tmp3;

    Animal2 *var_a2_2;
    Animal *tmp;

    s32 spF8;
    s32 spF4;

    f32 var_f2;

    Animal *temp_s1;
    Commands *temp_s0;

    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;

    s16 temp_s2_3;
    s16 temp_a1;

    s16 temp_v0_14;
    s16 var_a0_3;

    struct050 *temp_v0_26;
    s32 temp_s0_35;

    s16 var_s1;
    s16 i;
    s16 i2;

    u8 track_id;
    u8 temp_t3;
    s8 var_a0;
    s8 var_a2;
    s8 var_a3;

    u8 temp_v0_5; // unused
    u8 var_a0_2;
    s8 var_t0;
    s8 var_t1;

    struct077 spA4;
    struct077 sp9C;
    s16 sp9A;
    s16 sp98;
    s32 sp84;

    s32 sp7C;
    s32 sp78;
    s32 sp74;

    temp_s0 = &arg0->commands;
    temp_s1 = arg0->unk248[0];

    switch (temp_s0->unk19C.payload.type) {
    case 0:
        return 69;

    case 0x1:

        if (run_single_command(temp_s1, &temp_s0->unk19C.payload.cmd) != 0) {
            if ((temp_s0->unk19C.payload.cmd.type1.unk0 & 0x40) == 0) {
                temp_s0->unk19C.count = temp_s0->unk19C.payload.cmd.type1.unk6;
            }
            return 69;
        }

        if (temp_s0->unk19C.payload.cmd.type1.unk0 & 0x40) {
            while (arg0->commands.unk1A8[arg0->commands.unk19C.count+1].type == 1) {
                arg0->commands.unk19C.count++;
            }
        }
        return 69;

    case 0x2:
        var_a0_2 = temp_s0->numCommandsToCopy;
        temp_s0->unk1AC[var_a0_2].regular.unk0 = temp_s0->unk19C.payload.cmd.regular.unk0;
        temp_s0->unk1AC[var_a0_2].regular.unk2 = temp_s0->unk19C.payload.cmd.regular.unk2;
        temp_s0->unk1AC[var_a0_2].regular.unk4 = temp_s0->unk19C.payload.cmd.regular.unk4;
        temp_s0->unk1AC[var_a0_2].regular.unk6 = temp_s0->unk19C.payload.cmd.regular.unk6;

        temp_s0->unk1AC[var_a0_2].unknown.unk0.ub[1] = arg0->commands.unk1CC;
        temp_s0->numCommandsToCopy++;
        return 69;

    case 0x3:
        temp_t3 = run_single_command(temp_s1, &temp_s0->unk19C.payload.cmd);

        if (temp_s0->unk1D4 == 0) {
            if (temp_t3 != 0) {
                if ((temp_s0->unk19C.payload.cmd.type1.unk0 & 0x40) != 0) {
                    temp_s0->unk1D4 = temp_s0->unk19C.count + 1; // unk38
                }
                return 69;
            }
            return 0;
        } else {
            if (temp_t3 != 0) {
                if ((temp_s0->unk19C.payload.cmd.type1.unk0 & 0x40) == 0) {
                    temp_s0->unk1D4 = 0; // unk38
                }
                return 69;
            }

            temp_s0->unk19C.count = temp_s0->unk1D4 - 1;
            copy_command_struct(&temp_s0->unk1A8[temp_s0->unk19C.count], &temp_s0->unk19C.payload);
            return 0;
        }

    case 0x4:
        temp_s0->unk1CE = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.simple.unk0);
        temp_s0->unk1D0 = temp_s0->unk19C.count;
        return 69;

    case 0x5:
        if (--temp_s0->unk1CE > 0) {
            temp_s0->unk19C.count = temp_s0->unk1D0;
        }
        return 69;

    case 0x6:
        if (temp_s0->unk19C.payload.cmd.simple.unk0 != -1) {
            temp_s0->unk1D2 = get_game_state(arg0, temp_s0->unk19C.payload.cmd.simple.unk0);
            temp_s0->unk19C.payload.cmd.simple.unk0 = -1;
        }
        if (temp_s0->unk1D2-- < 1) {
            return 69;
        }
        return 0;

    case 0x7:
        return 0;

    case 0x8:
        temp_s0->unk19C.count = temp_s0->unk19C.payload.cmd.simple.unk0;
        return 69;

    case 0x9:
        temp_s0->unk1A8 = NULL;
        return 0;

    case 0xA:
        return 0;

    case 0xB:
        temp_s1->unk158 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.simple.unk0);
        return 69;

    case 0xC:
        set_floor_level(
            temp_s0->unk19C.payload.cmd.type12.xStart + 4,
            temp_s0->unk19C.payload.cmd.type12.yStart + 8,
            temp_s0->unk19C.payload.cmd.type12.xEnd,
            temp_s0->unk19C.payload.cmd.type12.yEnd,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type12.action) >> 3
            );
        return 69;

    case 0xD:
        // out of order?
        temp_s1->unk20C = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type13.unk0);
        temp_s1->unk210 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type13.unk4);
        temp_s1->unk20E = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type13.unk2);
        return 69;

    case 0xE:
        temp_s1->commands.numCommandsToCopy = 0;
        temp_s1->commands.unk1CE = 0;
        temp_s1->commands.unk1D0 = 0;
        temp_s1->commands.unk1D2 = 0;
        temp_s1->unk248[0] = temp_s1;
        temp_s1->commands.unk1A8 = &D_803E4D40[temp_s0->unk19C.payload.cmd.type14.unk0];
        temp_s1->unk4C.unk19 = 1;
        if (temp_s1 != arg0) {
            copy_command_struct(temp_s1->commands.unk1A8, &temp_s1->commands.unk19C.payload);
            temp_s1->commands.unk19C.count = 0;
        } else {
            temp_s1->commands.unk19C.count = 0xFF;
        }
        return 69;

    case 0xF:
        temp_s1->state = temp_s0->unk19C.payload.cmd.regular.unk0;
        return 69;

    case 0x10:
        if (temp_s1->unk16C->objectType >= 0x100) { // animal
            sp13E = (temp_s1->zRotation * 360) >> 8;
            sp13C = (temp_s1->yRotation * 360) >> 8;
        } else {
            sp13E = temp_s1->zRotation;
            sp13C = temp_s1->yRotation;
        }

        sp13E += (temp_s0->unk19C.payload.cmd.type16.unk5 * 360) >> 8;
        sp13C += (temp_s0->unk19C.payload.cmd.type16.unk4 * 360) >> 8;

        if (sp13E >= 360) {
            sp13E -= 360;
        } else if (sp13E < 0) {
            sp13E += 360;
        }

        if (sp13C >= 360) {
            sp13C -= 360;
        } else if (sp13C < 0) {
            sp13C += 360;
        }

        func_802F603C_7076EC(
            temp_s0->unk19C.payload.cmd.type16.unk1,
            temp_s0->unk19C.payload.cmd.type16.unk2,
            temp_s0->unk19C.payload.cmd.type16.unk3,
            sp13E,
            sp13C,
            temp_s1->unk40,
            &sp148);

        func_802F5F44_7075F4(
            0,
            temp_s0->unk19C.payload.cmd.type16.unk6 << 8,  // y
            0,
            sp13E,
            sp13C,
            &sp140);

        arg0->unk248[7] = spawn_object(
        /* id    */ temp_s0->unk19C.payload.cmd.type16.id,
        /* xPos  */ temp_s1->xPos.h + sp148.unk0,
        /* zPos  */ temp_s1->zPos.h + sp148.unk2,
        /* yPos  */ temp_s1->yPos.h + sp148.unk4,
        /* xVel  */ sp140.unk0 << 8,
        /* zVel  */ sp140.unk2 << 8,
        /* yVel  */ sp140.unk4 << 8,
        /* zRot  */ sp13E,
        /* yRot  */ sp13C,
        /* scale */ 0x800);

        if (arg0->unk248[7] == NULL) {
            return 0;
        }
        return 69;

    case 0x11:
        arg0->unk248[7] = spawn_object(
            temp_s0->unk19C.payload.cmd.type17.id,
            temp_s0->unk19C.payload.cmd.type17.x,
            temp_s0->unk19C.payload.cmd.type17.z,
            temp_s0->unk19C.payload.cmd.type17.y,
            0,
            0,
            0,
            0,
            0,
            0x800);

        if (arg0->unk248[7] == NULL) {
            return 0;
        }
        return 69;

    case 0x12:
        tmp = arg0->unk248[7];
        func_802FCA08_70E0B8(tmp, tmp->unk164 | 0x4000);
        return 69;

    case 0x13:
        if (temp_s1->unk16C->objectType >= 0x100) {
            func_802C83CC_6D9A7C(temp_s1);
        } else {
            run_commands(temp_s1);
        }

        if (arg0 == temp_s1) {
            return 0;
        }
        return 69;

    case 0x14:
        arg0->unk248[0] = func_803146A8_725D58(
            arg0,
            temp_s0->unk19C.payload.cmd.type20.unk0,
            temp_s0->unk19C.payload.cmd.type20.unk2);

        arg0->commands.unk1CC = temp_s0->unk19C.payload.cmd.type20.unk0;
        return 69;

    case 0x15:
        temp_s1->unk212 = temp_s0->unk19C.payload.cmd.type21.unk0;
        temp_s1->unk213 = temp_s0->unk19C.payload.cmd.type21.unk1;
        temp_s1->unk214 = temp_s0->unk19C.payload.cmd.type21.unk2;
        temp_s1->unk215 = temp_s0->unk19C.payload.cmd.type21.unk3;
        temp_s1->unk216 = temp_s0->unk19C.payload.cmd.type21.unk4;
        temp_s1->unk217 = temp_s0->unk19C.payload.cmd.type21.unk5;
        return 69;

    case 0x16:
        temp_s1->unk218 = temp_s0->unk19C.payload.cmd.type22.unk0;
        temp_s1->unk219 = temp_s0->unk19C.payload.cmd.type22.unk1;
        temp_s1->unk21A = temp_s0->unk19C.payload.cmd.type22.unk2;
        temp_s1->unk21B = temp_s0->unk19C.payload.cmd.type22.unk3;
        temp_s1->unk21C = temp_s0->unk19C.payload.cmd.type22.unk4;
        temp_s1->unk21D = temp_s0->unk19C.payload.cmd.type22.unk5;
        return 69;

    case 0x17:
        temp_s1->unk21E.type23.unk0 = temp_s0->unk19C.payload.cmd.type23.unk0;
        temp_s1->unk21E.type23.unk2 = temp_s0->unk19C.payload.cmd.type23.unk2;
        temp_s1->unk21E.type23.unk3 = temp_s0->unk19C.payload.cmd.type23.unk3 - 20;
        temp_s1->unk21E.type23.unk4 = temp_s0->unk19C.payload.cmd.type23.unk4;
        temp_s1->unk21E.type23.unk5 = temp_s0->unk19C.payload.cmd.type23.unk5;
        temp_s1->unk21E.type23.unk6 = temp_s0->unk19C.payload.cmd.type23.unk6;
        temp_s1->unk22A = 0;
        return 69;

    case 0x18:
        temp_s1->unk21E = arg0->commands.unk19C.payload.cmd;

        // TODO: feels more like a bitfield, but cant get it to work...
        temp_t3 = (temp_s1->unk21E.type24.F & 1) == 0; // save top bit
        temp_s1->unk21E.type24.F &= 0xFFFE;              // clear top bit
        temp_s1->unk22A = 0;

        if (temp_t3) {
            if (temp_s1->unk248[8] != NULL) {
                func_8039DD90_7AF440((Trail *) temp_s1->unk248[8]);
                temp_s1->unk248[8] = NULL;
                return 69;
            }
        }

        // TODO: can this be done implicitly?
        if (temp_s1->unk21E.type24.State >= 0x8C) {
            switch (temp_s1->unk21E.type24.State) { // unk220
            case 0x8C: // L80316BCC_72827C
                temp_s1->unk248[8] = add_regular_trail(
                    temp_s1,
                    0,
                    temp_s1->unk21E.type24.S,
                    temp_s1->unk21E.type24.unk5,
                    temp_s1->unk212,
                    temp_s1->unk213,
                    temp_s1->unk214,
                    (temp_s1->unk226 >> 8) & 0xF8,
                    (temp_s1->unk226 >> 3) & 0xF8,
                    (temp_s1->unk226 << 2) & 0xF8,
                    (temp_s1->unk228 >> 8) & 0xF8,
                    (temp_s1->unk228 >> 3) & 0xF8,
                    (temp_s1->unk228 << 2) & 0xF8,
                    0,
                    0,
                    0,
                    1,
                    0,
                    0);
                break;
            case 0x8D: // L80316C70_728320
                temp_s1->unk248[8] = add_regular_trail(
                    temp_s1,
                    1,
                    temp_s1->unk21E.type24.S,
                    temp_s1->unk21E.type24.unk5,
                    temp_s1->unk212,
                    temp_s1->unk213,
                    temp_s1->unk214,
                    (temp_s1->unk226 >> 8) & 0xF8,
                    (temp_s1->unk226 >> 3) & 0xF8,
                    (temp_s1->unk226 << 2) & 0xF8,
                    (temp_s1->unk228 >> 8) & 0xF8,
                    (temp_s1->unk228 >> 3) & 0xF8,
                    (temp_s1->unk228 << 2) & 0xF8,
                    0,
                    0,
                    0,
                    1,
                    0,
                    0);
                break;
            case 0x8E: // L80316D14_7283C4
                temp_s1->unk248[8] = add_regular_trail(
                    temp_s1,
                    2,
                    temp_s1->unk21E.type24.S,
                    temp_s1->unk21E.type24.unk5,
                    temp_s1->unk212,
                    temp_s1->unk213,
                    temp_s1->unk214,
                    (temp_s1->unk226 >> 8) & 0xF8,
                    (temp_s1->unk226 >> 3) & 0xF8,
                    (temp_s1->unk226 << 2) & 0xF8,
                    (temp_s1->unk228 >> 8) & 0xF8,
                    (temp_s1->unk228 >> 3) & 0xF8,
                    (temp_s1->unk228 << 2) & 0xF8,
                    0,
                    0,
                    0,
                    1,
                    0,
                    0);
                break;
            case 0x8F: // L80316E50_728500
            case 0x90: // L80316E50_728500
                break;
            case 0x91: // L80316DB8_728468
                temp_s1->unk248[8] = add_simple_trail(
                    temp_s1,
                    2,
                    temp_s1->unk21E.type24.S,
                    32,
                    temp_s1->unk212,
                    temp_s1->unk213,
                    temp_s1->unk214,
                    (temp_s1->unk226 >> 8) & 0xF8,
                    (temp_s1->unk226 >> 3) & 0xF8,
                    (temp_s1->unk226 << 2) & 0xF8,
                    (temp_s1->unk228 >> 8) & 0xF8,
                    (temp_s1->unk228 >> 3) & 0xF8,
                    (temp_s1->unk228 << 2) & 0xF8,
                    1);
                break;
            }
        } else {
            func_802FA730_70BDE0(temp_s1);
        }
        return 69;

    case 0x19:
        func_802F657C_707C2C(
            temp_s1,
            temp_s0->unk19C.payload.cmd.regular.unk0,
            temp_s0->unk19C.payload.cmd.regular.unk2,
            temp_s0->unk19C.payload.cmd.regular.unk4,
            temp_s0->unk19C.payload.cmd.regular.unk6);
        temp_s1->unk170 = 1;
        return 69;

    case 0x1A:
        func_802F657C_707C2C(
            temp_s1,
            temp_s0->unk19C.payload.cmd.regular.unk0,
            temp_s0->unk19C.payload.cmd.regular.unk2,
            temp_s0->unk19C.payload.cmd.regular.unk4,
            temp_s0->unk19C.payload.cmd.regular.unk6);
        temp_s1->unk170 = 2;
        return 69;

    case 0x1B:
        func_802F657C_707C2C(
            temp_s1,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0) + temp_s1->xPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2) + temp_s1->zPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4) + temp_s1->yPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk6));

        temp_s1->unk170 = 1;
        return 69;

    case 0x1C:
        func_802F657C_707C2C(
            temp_s1,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0) + temp_s1->xPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2) + temp_s1->zPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4) + temp_s1->yPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk6));

        temp_s1->unk170 = 2;
        return 69;

    case 0x1D:
        if (temp_s1->unk16C->objectType < 0x100) {

            if (temp_s1->unk170 != 6) {
                func_802F9EB8_70B568(
                    &sp12C,
                    &sp130,
                    &sp134,
                    D_803E8E60[temp_s0->unk19C.payload.cmd.type29.unk0],
                    0,
                    !(temp_s0->unk19C.payload.cmd.type29.unk6 == 1)); // unkA

                sp12C = sp12C >> 0x10;
                sp130 = sp130 >> 0x10;
                sp134 = sp134 >> 0x10;

                // compiler managed temps or what?
                if ((ABS(temp_s1->xPos.h - sp12C) > 4) ||
                    (sp7C = ABS(temp_s1->zPos.h - sp130), sp7C > 4) ||
                    ((temp_s1->unk4C.unk1D == 0) && (sp78 = ABS(temp_s1->yPos.h - sp134), sp78 > 4))) {
                    temp_s1->unk170 = 6;
                    func_802F657C_707C2C(
                        temp_s1,
                        sp12C,
                        sp130,
                        sp134,
                        temp_s0->unk19C.payload.cmd.type29.unk2);
                    return 0;
                } else {
                    func_802F9E10_70B4C0(
                        temp_s1,
                        temp_s0->unk19C.payload.cmd.type29.unk0,
                        temp_s0->unk19C.payload.cmd.type29.unk2,
                        temp_s0->unk19C.payload.cmd.type29.unk5,
                        temp_s0->unk19C.payload.cmd.type29.unk6,
                        0);
                    return 1;
                }
            }
            return 0;
        } else {
            func_8036390C_774FBC(
                temp_s1,
                temp_s0->unk19C.payload.cmd.type29.unk0,
                temp_s0->unk19C.payload.cmd.type29.unk2,
                temp_s0->unk19C.payload.cmd.type29.unk5,
                temp_s0->unk19C.payload.cmd.type29.unk6,
                temp_s0->unk19C.payload.cmd.type29.unk7);

        }
        return 69;

    case 0x1E:
        func_80363B98_775248(
            temp_s1,
            temp_s0->unk19C.payload.cmd.type30.unk0,
            temp_s0->unk19C.payload.cmd.type30.unk2,
            temp_s0->unk19C.payload.cmd.type30.unk4,
            temp_s0->unk19C.payload.cmd.type30.unk7,
            temp_s0->unk19C.payload.cmd.type30.unk6);
        return 69;

    case 0x1F:
        func_80363B34_7751E4(temp_s1, temp_s0->unk19C.payload.cmd.simple.unk0);
        return 69;

    case 0x20:
        func_80363C0C_7752BC(temp_s1, temp_s0->unk19C.payload.cmd.simple.unk0);
        return 69;

    case 0x21:
        func_80319AA0_72B150(&temp_s1->unk18C, temp_s0->unk19C.payload.cmd.simple.unk0);
        return 69;

    case 0x22:
        func_80319AC4_72B174(&temp_s1->unk18C, temp_s0->unk19C.payload.cmd.simple.unk0);
        return 69;

    case 0x24:
        if (func_80349A14_75B0C4() != 0) {
            temp_v0_14 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.simple.unk0);
            if (temp_v0_14 == 0) {
                func_80349AA0_75B150(0);
                return 69;
            }

            if (D_803E4CA5 == 0) {
                func_80349AA0_75B150(temp_v0_14);
                D_803E4CA5 = 1;
                return 0;
            }

            if (D_803F2CDC == 1) {
                D_803E4CA5 = 0;
                return 69;
            }
        }
        return 0;

    case 0x25:
        // create light? update environment light?
        func_802F2EEC_70459C(
            temp_s0->unk19C.payload.cmd.type37.unk0,
            temp_s0->unk19C.payload.cmd.type37.unk1,
            temp_s0->unk19C.payload.cmd.type37.unk2,
            temp_s0->unk19C.payload.cmd.type37.unk3,
            temp_s0->unk19C.payload.cmd.type37.unk4,
            temp_s0->unk19C.payload.cmd.type37.unk5,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type37.unk6));
        return 69;

    case 0x26:
        if (temp_s0->unk19C.payload.cmd.type38.atLocation != 0) { // unkA
            play_sound_effect_at_location(
                temp_s0->unk19C.payload.cmd.type38.id,
                temp_s0->unk19C.payload.cmd.type38.volume,
                0,
                temp_s1->xPos.h,
                temp_s1->zPos.h,
                temp_s1->yPos.h,
                temp_s0->unk19C.payload.cmd.type38.pitch / 32767.0f);
        } else {
            func_8032C508_73DBB8(
                temp_s0->unk19C.payload.cmd.type38.id,
                temp_s0->unk19C.payload.cmd.type38.volume,
                0,
                temp_s0->unk19C.payload.cmd.type38.pitch / 32767.0f);
        }
        return 69;

    case 0x27:
        track_id = arg0->commands.unk19C.payload.cmd.type39.id;
        if (track_id == -1) {
            var_a0 = 1;
        } else {
            var_a0 = track_id;
        }
        set_music_track(var_a0);
        return 69;

    case 0x28:
        return 69;

    case 0x29:
        D_803F2D50.unk1E = get_game_state(temp_s1, (s32) (u16) temp_s0->unk19C.payload.cmd.regular.unk0);
        return 69;

    case 0x2A:
        D_803F2D50.unk1C = get_game_state(temp_s1, (s32) (u16) temp_s0->unk19C.payload.cmd.regular.unk0);
        return 69;

    case 0x2B:
        D_803F2D30.score += get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0);
        return 69;

    case 0x2C:
        temp_v0_14 = get_game_state(temp_s1, arg0->commands.unk19C.payload.cmd.regular.unk0);
        if (!(arg0->unk4C.unk1A) || (temp_v0_14 > 0)) { // unk4C & 0x20
            temp_s1->health += temp_v0_14;
        }
        return 69;

    case 0x2D:
        // UB???
        return;

    case 0x2E:

        func_80343AE0_755190(
            1U,
            0,
            arg0->commands.unk19C.payload.cmd.regular.unk0,
            NULL,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            -3,
            5,
            1);
        return 69;

    case 0x2F:
        // zoom camera in/out?
        temp_a1 = get_game_state(temp_s1, (s32) temp_s0->unk19C.payload.cmd.regular.unk0);
        if (temp_s0->unk19C.payload.cmd.regular.unk2 != 0) {
            func_803421E0_753890(temp_a1);
        } else {
            func_8034220C_7538BC(temp_a1, temp_s1->xPos.h, temp_s1->zPos.h, temp_s1->yPos.h);
        }
        return 69;

    case 0x31:
        // add_thing?
        sp7C = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2);
        func_802FF184_710834(
            temp_s1,
            1,
            temp_s1->xPos.h,
            temp_s1->zPos.h,
            temp_s1->yPos.h + (arg0->unk42 >> 1),
            0,
            0,
            sp7C,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0),
            -1
        );
        return 69;

    case 0x23:
        temp_s1->unk272 = temp_s0->unk19C.payload.cmd.type35.unk0;
        temp_s1->unk2C8 = temp_s0->unk19C.payload.cmd.type35.unk0;
        return 69;

    case 0x32:
        temp_s2_3 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type50.unk2);
        sp120 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type50.unk6);
        if (temp_s0->unk19C.payload.cmd.type50.unk0 & 0x20) {
            if (temp_s0->unk19C.payload.cmd.type50.unk0 & 1) {
                temp_s1->yRotation = sp120;
                temp_s1->zRotation = temp_s2_3;
                // return 69;
            } else {
                temp_s1->yRotation += sp120;
                temp_s1->zRotation += temp_s2_3;
                temp_s1->yRotation = temp_s1->yRotation % 360;
                temp_s1->zRotation = temp_s1->zRotation % 360;
            }

        } else {
            temp_s1->unk234[1] = 0;
            temp_s1->unk236 = temp_s1->zRotation;
            temp_s1->unk23A = temp_s1->yRotation;

            if ((temp_s0->unk19C.payload.cmd.type50.unk0 & 1) && !(temp_s0->unk19C.payload.cmd.type50.unk0 & 0x10)) {
                temp_s1->unk22E = func_802F63F8_707AA8(temp_s2_3, temp_s1->zRotation, 0xB5);
                sp120 = func_802F63F8_707AA8(sp120, temp_s1->yRotation, 0xB5);
            } else {
                temp_s1->unk22E = temp_s2_3;
            }

            temp_s1->unk232 = sp120;
            temp_s1->unk230 = 0;
            temp_s1->unk22C = temp_s0->unk19C.payload.cmd.type50.unk0;
            temp_s1->unk22D = temp_s0->unk19C.payload.cmd.type50.unk1;
        }
        return 69;

    case 0x33:
        temp_s1->unk3E = get_game_state(temp_s1, arg0->commands.unk19C.payload.cmd.type51.unk0);
        return 69;

    case 0x34:
        if (temp_s1->unk16C->objectType < 0x100) {
            if (temp_s1->unk170 != 6) {
                func_802F9E10_70B4C0(
                    temp_s1,
                    temp_s0->unk19C.payload.cmd.dummy.unk1,
                    temp_s0->unk19C.payload.cmd.dummy.unk3,
                    temp_s0->unk19C.payload.cmd.dummy.unk5,
                    temp_s0->unk19C.payload.cmd.dummy.unk6,
                    1);
                return 1;
            }
            return 0;
        } else {
            func_80363A0C_7750BC(
                temp_s1,
                temp_s0->unk19C.payload.cmd.dummy.unk1,
                temp_s0->unk19C.payload.cmd.dummy.unk3,
                temp_s0->unk19C.payload.cmd.dummy.unk5,
                temp_s0->unk19C.payload.cmd.dummy.unk6,
                temp_s0->unk19C.payload.cmd.dummy.unk7);
            return 69;
        }

        return 69;

    case 0x35:
        set_water_level(
            temp_s0->unk19C.payload.cmd.type53.xStart + 4,
            temp_s0->unk19C.payload.cmd.type53.yStart + 8, // unk5
            temp_s0->unk19C.payload.cmd.type53.xEnd,
            temp_s0->unk19C.payload.cmd.type53.yEnd,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type53.action) >> 2
            );
        return 69;

    case 0x36:
        temp_s1->unk40 = arg0->commands.unk19C.payload.cmd.type54.unk0;
        func_802C9BA4_6DB254((struct071 *) temp_s1);
        return 69;

    case 0x30: // not here
        return 69;

    case 0x37:
        if (arg0 == D_803E4CA0) {
            D_803E4CA0 = NULL;
            D_803E4CA4 = 0;
        }
        D_803F2CD0 = 0;
        return 69;

    case 0x38:
        return 1;

    case 0x39:
        if (temp_s0->unk19C.payload.cmd.regular.unk6 != 0) {
            func_80342318_7539C8(
                (temp_s0->unk19C.payload.cmd.regular.unk0 - temp_s1->xPos.h) << 0x10,
                (temp_s0->unk19C.payload.cmd.regular.unk2 - temp_s1->zPos.h) << 0x10,
                (temp_s0->unk19C.payload.cmd.regular.unk4 - temp_s1->yPos.h) << 0x10
            );
        }
        temp_s1->xPos.h = temp_s0->unk19C.payload.cmd.regular.unk0;
        temp_s1->zPos.h = temp_s0->unk19C.payload.cmd.regular.unk2;
        temp_s1->yPos.h = temp_s0->unk19C.payload.cmd.regular.unk4;
        func_80311554_722C04(temp_s1->xPos.h, temp_s1->zPos.h, &sp10C, &sp110);
        if ((temp_s1->unk16C->objectType >= 0x100) && (temp_s1->yPos.w < sp110)) {
            temp_s1->yPos.w = sp110;
        }
        if (sp10C == 0x40000000) {
            temp_s1->unk160 = 0;
        } else if (temp_s1->yPos.w >= sp10C) {
            temp_s1->unk160 = 2;
        } else {
            temp_s1->unk160 = 1;
        }
        return 69;

    case 0x3A:
        func_803638A8_774F58(temp_s1, func_803146A8_725D58(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2, 0U), temp_s0->unk19C.payload.cmd.regular.unk0);
        return 69;
    case 0x3B:
        temp_s1->commands.numCommandsToCopy = 0;
        return 69;

    case 0x3C:
        if (temp_s1->unk16C->objectType < 0x100) {
            temp_s1->unk170 = 4;
            temp_s1->xVelocity.w = temp_s1->zVelocity.w = temp_s1->yVelocity.w = 0;
            return 69;
        } else {
            func_803638E8_774F98(temp_s1);
        }
        return 69;

    case 0x3D:

        if ((temp_s0->unk19C.payload.cmd.type61.unk7.unk0) == 0) {
            sp78 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type61.unk0);
        } else {
            sp7C = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type61.unk0);
            sp78 = do_maths_op(
                sp7C,
                temp_s0->unk19C.payload.cmd.type61.unk7.unk0,
                get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type61.unk2)
            );

            if (temp_s0->unk19C.payload.cmd.type61.unk7.unk4) {
                sp78 = do_maths_op(
                    sp78,
                    temp_s0->unk19C.payload.cmd.type61.unk7.unk4,
                    get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type61.unk4)
                );
            }
        }
        set_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type61.unk6 + 0x7F7F, sp78);
        return 69;

    case 0x3E:
        if ((D_803E8E56 == 0) && (func_802F1388_702A38() != 0)) {
            trigger_screen_transition(arg0->commands.unk19C.payload.cmd.regular.unk0);
            D_803E8E56 = 1;
        }
        if (func_802F1388_702A38() != 0) {
            D_803E8E56 = 0;
            return 69;
        }
        return 0;

    case 0x3F:
        func_80363844_774EF4(
            temp_s1,
            get_game_state(
                temp_s1,
                arg0->commands.unk19C.payload.cmd.regular.unk0
            )
        );
        return 69;

    case 0x40:
        tmp2 = func_803146A8_725D58(temp_s1, arg0->commands.unk19C.payload.cmd.regular.unk0, 0);

        if (temp_s1->unk16C->objectType >= 0x100) {
            func_80363880_774F30(temp_s1, tmp2);
        } else {
            // object
            temp_s0_35 = tmp2->xPos.h - temp_s1->xPos.h;
            sp78 = tmp2->zPos.h - temp_s1->zPos.h;
            spF8 = (tmp2->yPos.h + (tmp2->unk42 >> 1)) - temp_s1->yPos.h;
            spF4 = (s16) sqrtf(SQ(temp_s0_35) + SQ(sp78));
            temp_s1->yRotation = func_801284B8(temp_s0_35, sp78);
            temp_s1->zRotation = func_801284B8(spF8, spF4);
        }
        return 69;

    case 0x41:
        // level_passed?
        func_8035739C_768A4C();
        return 1;

    case 0x42:
        func_802B33D0_6C4A80(func_803146A8_725D58(temp_s1, arg0->commands.unk19C.payload.cmd.regular.unk0, 0));
        return 69;

    case 0x43:
        func_802B34B8_6C4B68(func_803146A8_725D58(temp_s1, arg0->commands.unk19C.payload.cmd.regular.unk0, 0));
        return 69;

    case 0x44:
        if (temp_s0->unk19C.payload.cmd.type68.unk0 >= D_803F63C0) {
            return 69;
        }
        if ((D_803E4CA4 != 0) && (D_803E8E58 != 0)) {
            if ((arg0 == D_803E4CA0) && (func_80349874_75AF24() != 0)) {
                D_803E4CA4 = 0;
                D_803E4CA0 = 0;
                return 69;
            }
        } else if (func_80349874_75AF24() != 0) {
            D_803E4CA4 = 1;
            D_803E4CA0 = arg0;
            func_80314660_725D10();
            func_80349900_75AFB0(
                &D_803F34C0[D_803F3330[temp_s0->unk19C.payload.cmd.type68.unk0]],
                temp_s0->unk19C.payload.cmd.type68.unk2);
            D_803A8340_7B99F0 = temp_s0->unk19C.payload.cmd.type68.unk0;
            if (D_803E8E58 == 0) {
                D_803E4CA4 = 0;

                return 69;
            }
        }
        return 0;

    case 0x45:

        if (temp_s0->unk19C.payload.cmd.regular.unk0 == 100) {
            func_80397734_7A8DE4(temp_s0->unk19C.payload.cmd.regular.unk2, 0);
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 101) {
            func_80397734_7A8DE4(temp_s0->unk19C.payload.cmd.regular.unk2, 1);
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 102) {
            func_80397734_7A8DE4(temp_s0->unk19C.payload.cmd.regular.unk2, 2);
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 300) { // 0x12C
            func_80328ACC_73A17C();
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 400) { // 0x190
            D_803F6450 = temp_s0->unk19C.payload.cmd.regular.unk2;
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 500) { // 0x1F4
            D_803F2D50.unk75 = 0;
            D_803F2D50.unk76 = temp_s0->unk19C.payload.cmd.regular.unk2; // D_803F2DC6
            D_803F2D50.unk77 = temp_s0->unk19C.payload.cmd.regular.unk4; // D_803F2DC7
            D_803F2D50.unk78 = temp_s0->unk19C.payload.cmd.regular.unk6; // D_803F2DC8
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 600) { // 0x258
            D_803F2D50.unk75 = 1;
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 700) { // 0x2BC
            D_803E8E57 = temp_s0->unk19C.payload.cmd.regular.unk2;
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 800) { // 0x320
            D_803E8E58 = temp_s0->unk19C.payload.cmd.regular.unk2;
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 900) { // 0x384
            func_8038B798_79CE48();
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 1000) { // 0x3E8
            set_game_state(temp_s1, (s16) (temp_s0->unk19C.payload.cmd.regular.unk4 + 0x7FBE), (s32) (cosf((f32) ((f64) (f32) get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2 + 0x7FBE) * 0.017453216666666667)) * 2048.0f));
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 1100) { // 0x44C
            set_game_state(temp_s1, (s16) (temp_s0->unk19C.payload.cmd.regular.unk4 + 0x7FBE), (s32) (sinf((f32) ((f64) (f32) get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2 + 0x7FBE) * 0.017453216666666667)) * 2048.0f));
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 1200) { // 0x4B0
            D_803A6CE0_7B8390 = temp_s0->unk19C.payload.cmd.regular.unk2;
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 1300) { // 0x514
            if (temp_s0->unk19C.payload.cmd.regular.unk2 != 0) {
                D_803A6CE4_7B8394 |= 4;
            } else {
                D_803A6CE4_7B8394 &= ~4;
            }
        } else if (temp_s0->unk19C.payload.cmd.regular.unk0 == 1400) { // 0x578
            func_803441FC_7558AC();
        }

        return 69;

    case 0x46:
        temp_s1->unk23C.regular.unk0 = temp_s0->unk19C.payload.cmd.regular.unk0;
        temp_s1->unk23C.regular.unk2 = temp_s0->unk19C.payload.cmd.regular.unk2;
        temp_s1->unk23C.regular.unk4 = temp_s0->unk19C.payload.cmd.regular.unk4;
        temp_s1->unk23C.regular.unk6 = temp_s0->unk19C.payload.cmd.regular.unk6;
        // overwrite?
        temp_s1->unk23C.regular.unk6 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk6);
        temp_s1->unk244 = 0;
        temp_s1->unk23C.unknown2.unk5 |= 4; // unk240.ub[1]
        return 69;

    case 0x47:
        if (temp_s0->unk19C.payload.cmd.type71.unk4 != 0) {
            var_f2 = 1.0f;
        } else {
            tmp3 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
            var_f2 = sqrtf(SQ((f32)(temp_s1->xPos.h - tmp3->xPos.h)) + SQ((f32)(temp_s1->zPos.h - tmp3->zPos.h)) + SQ((f32)(temp_s1->yPos.h - tmp3->yPos.h)));
        }

        do_rumble(
            0,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type71.unk0),
            temp_s0->unk19C.payload.cmd.type71.unk2,
            temp_s0->unk19C.payload.cmd.type71.unk3,
            var_f2);
        return 69;

    case 0x48:

        arg0->commands.unk1D5 = arg0->commands.numCommandsToCopy;
        arg0->commands.unk1D6 = arg0->commands.unk1CE;
        arg0->commands.unk1D8 = arg0->commands.unk1D0;
        arg0->commands.unk1D9 = arg0->commands.unk19C.count;
        arg0->commands.unk1FC = arg0->commands.unk1A8;

        if (arg0->commands.numCommandsToCopy != 0) {
            for (i = 0; i < 4; i++) {
                // struct copy
                arg0->commands.unk1DA[i] = arg0->commands.unk1AC[i];
            }
        }
        arg0->commands.numCommandsToCopy = 0;
        arg0->commands.unk1CE = 0;
        arg0->commands.unk1D0 = 0;

        arg0->unk248[0] = temp_s1;
        arg0->commands.unk1A8 = &D_803E4D40[arg0->commands.unk19C.payload.cmd.type72.unk0];
        arg0->unk4C.unk19 = 1;
        arg0->commands.unk19C.count = -1;
        return 69;

    case 0x49:
        arg0->commands.unk1CE = arg0->commands.unk1D6;
        arg0->commands.unk1D0 = arg0->commands.unk1D8;

        arg0->commands.unk19C.count = arg0->commands.unk1D9 + 1;
        arg0->commands.unk1A8 = arg0->commands.unk1FC;

        arg0->commands.numCommandsToCopy = arg0->commands.unk1D5;
        if (arg0->commands.numCommandsToCopy != 0) {
            for (i = 0; i < 4; i++) {
                arg0->commands.unk1AC[i].regular.unk0 = arg0->commands.unk1DA[i].regular.unk0;
                arg0->commands.unk1AC[i].regular.unk2 = arg0->commands.unk1DA[i].regular.unk2;
                arg0->commands.unk1AC[i].regular.unk4 = arg0->commands.unk1DA[i].regular.unk4;
                arg0->commands.unk1AC[i].regular.unk6 = arg0->commands.unk1DA[i].regular.unk6;
            }
        }

        arg0->unk248[0] = temp_s1;
        arg0->unk4C.unk19 = 1;
        arg0->commands.unk19C.count--;
        return 69;

    case 0x4A:
        temp_s1->unk246 = arg0->commands.unk19C.payload.cmd.type74.unk0 + 1;
        return 69;

    case 0x4B:
        spD0 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0);
        spCC = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2);
        spC8 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4);
        if (temp_s0->unk19C.payload.cmd.regular.unk6 != 0) {
            func_80342318_7539C8(spD0 << 0x10, spCC << 0x10, spC8 << 0x10);
        }

        temp_s1->xPos.h += spD0;
        temp_s1->zPos.h += spCC;
        temp_s1->yPos.h += spC8;
        func_80311554_722C04(temp_s1->xPos.h, temp_s1->zPos.h, &spD4, &spD8);
        if ((temp_s1->unk16C->objectType >= 0x100) && (temp_s1->yPos.w < spD8)) {
            temp_s1->yPos.w = spD8;
        }
        if (spD4 == 0x40000000) {
            temp_s1->unk160 = 0;
            return 69;
        }
        if (temp_s1->yPos.w >= spD4) {
            temp_s1->unk160 = 2;
            return 69;
        }
        temp_s1->unk160 = 1;
        return 69;

    case 0x4C:
        sp78 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2);
        sp7C = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4);
        if ((sp78 | sp7C) == 0) {
            D_803E4AD0[temp_s0->unk19C.payload.cmd.regular.unk0] = 0;
        } else {
            D_803E4AD0[temp_s0->unk19C.payload.cmd.regular.unk0] = 1;
            D_803E2930[temp_s0->unk19C.payload.cmd.regular.unk0].unk0 = sp78;
            D_803E2930[temp_s0->unk19C.payload.cmd.regular.unk0].unk4 = sp7C;
        }
        return 69;

    case 0x4D:

        if (temp_s1->unk16C->objectType >= 0x100) {
            var_a0_2 = 2;
        } else if (temp_s1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            var_a0_2 = 1;
        } else {
            var_a0_2 = 3;
        }

        if (temp_s0->unk19C.payload.cmd.type77.unk6.unk0 == 0xF) {
            var_t0 = -3;
            var_t1 = 5;
        } else {
            var_t0 = temp_s0->unk19C.payload.cmd.type77.unk6.unk0 - 3;
            var_t1 = temp_s0->unk19C.payload.cmd.type77.unk7.unk0 - 3;
        }
        func_80343AE0_755190(
            var_a0_2,
            temp_s0->unk19C.payload.cmd.type77.unk0,
            temp_s0->unk19C.payload.cmd.type77.unk1,
            temp_s1,
            0,
            0,
            0,
            temp_s0->unk19C.payload.cmd.type77.unk2,
            temp_s0->unk19C.payload.cmd.type77.unk3,
            temp_s0->unk19C.payload.cmd.type77.unk4,
            temp_s0->unk19C.payload.cmd.type77.unk5,
            !temp_s0->unk19C.payload.cmd.type77.unk6.unk5,
            var_t0,
            var_t1,
            temp_s0->unk19C.payload.cmd.type77.unk6.unk6);

        return 69;

    case 0x4E:

        if (temp_s0->unk19C.payload.cmd.type77.unk6.unk0 == 0xF) {
            var_t0 = -3;
            var_t1 = 5;
        } else {
            var_t0 = temp_s0->unk19C.payload.cmd.type77.unk6.unk0;
            var_t1 = temp_s0->unk19C.payload.cmd.type77.unk7.unk0;
            var_t0 = var_t0 - 3;
            var_t1 = var_t1 - 3;
        }

        func_80343AE0_755190(
            4,
            temp_s0->unk19C.payload.cmd.type77.unk0,
            temp_s0->unk19C.payload.cmd.type77.unk1,
            NULL,
            temp_s0->unk19C.payload.cmd.type77.unk2 << 5,
            temp_s0->unk19C.payload.cmd.type77.unk3 << 5,
            temp_s0->unk19C.payload.cmd.type77.unk4 << 5,
            0,
            0,
            0,
            temp_s0->unk19C.payload.cmd.type77.unk5,
            !temp_s0->unk19C.payload.cmd.type77.unk6.unk5,
            var_t0,
            var_t1,
            temp_s0->unk19C.payload.cmd.type77.unk6.unk6);

        return 69;

    case 0x4F:
        if (temp_s0->unk19C.payload.cmd.type77.unk6.unk0 == 0xF) {
            var_a2 = -3;
            var_a3 = 5;
        } else {
            var_a2 = temp_s0->unk19C.payload.cmd.type77.unk6.unk0;
            var_a3 = temp_s0->unk19C.payload.cmd.type77.unk7.unk0;
            var_a2 = var_a2 - 3;
            var_a3 = var_a3 - 3;
        }
        func_80343C74_755324(
          temp_s0->unk19C.payload.cmd.type77.unk5,
          !temp_s0->unk19C.payload.cmd.type77.unk6.unk5,
          var_a2,
          var_a3,
          temp_s0->unk19C.payload.cmd.type77.unk6.unk6);
        return 69;

    case 0x50:
        // camera related
        func_80343D44_7553F4(
            &D_803E8E60[temp_s0->unk19C.payload.cmd.dummy.unk0]->length,
            !temp_s0->unk19C.payload.cmd.dummy.unk1);
        return 69;

    case 0x51:
        // not used
        func_803637D4_774E84(temp_s1, func_803146A8_725D58(temp_s1, arg0->commands.unk19C.payload.cmd.regular.unk2, 0), 16);
        return 69;

    case 0x52:

        if (temp_s0->unk19C.payload.cmd.type82.unk0 == 0) {
            var_a0_3 = 586;
            var_s1 = 586;
        } else {
            var_a0_3 = temp_s0->unk19C.payload.cmd.type82.unk0;
            var_s1 = 1000;
        }

        func_802FD94C_70EFFC(
            var_a0_3, // min
            var_s1,   // max
            temp_s0->unk19C.payload.cmd.type82.unk4,
            temp_s0->unk19C.payload.cmd.type82.unk5,
            temp_s0->unk19C.payload.cmd.type82.unk6,
            temp_s0->unk19C.payload.cmd.type82.unk2);

        return 69;

    case 0x53:
        if (temp_s0->unk19C.payload.cmd.type83.unk0 & 1) {
            temp_s1->unk4C.unk1A = 1;
        } else {
            temp_s1->unk4C.unk1A = 0;
        }
        temp_s1->unk163 = (temp_s1->unk163 & 0xFFF8) | temp_s0->unk19C.payload.cmd.type83.unk0;
        return 69;

    case 0x54:
        if (temp_s1->unk16C->objectType >= 0x100) {
            sp74 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0);
            sp78 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2);
            sp7C = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4);
            func_80380620_791CD0(
                temp_s1,
                sp74,
                sp78,
                sp7C,
                get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk6));
        }
        return 69;

    case 0x55:
        // only used in HOPPA_CHOPPA
        func_80380644_791CF4(temp_s1);
        return 69;

    case 0x56:
        temp_s1 = func_803146A8_725D58(func_803146A8_725D58(arg0, temp_s0->unk19C.payload.cmd.regular.unk4, 0), temp_s0->unk19C.payload.cmd.regular.unk6, 0);
        tmp = func_803146A8_725D58(arg0, temp_s0->unk19C.payload.cmd.regular.unk0, 0);
        tmp->unk248[temp_s0->unk19C.payload.cmd.regular.unk2] = temp_s1;
        return 69;

    case 0x57:
        // doesn't appear to be bitfields
        temp_s1->unk4C.unk1B = (temp_s0->unk19C.payload.cmd.regular.unk0 & 1) != 0;
        temp_s1->unk4C.unk1C = (temp_s0->unk19C.payload.cmd.regular.unk0 & 4) != 0;
        temp_s1->unk4C.unk1D = (temp_s0->unk19C.payload.cmd.regular.unk0 & 2) != 0;
        return 69;

    case 0x58:
        // only used in FUN_IN_THE_SUN
        D_803F2D50.unkC = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0);
        D_803F2D50.unkE = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2);
        return 69;

    case 0x59:
        // only used in WEIGHT_FOR_IT
        func_802FE560_70FC10(
            (temp_s0->unk19C.payload.cmd.type89.unk0.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk1.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk2.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk3.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk4.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk5.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk6.unk1 << 1),
            (temp_s0->unk19C.payload.cmd.type89.unk7.unk1 << 1),
            ((temp_s0->unk19C.payload.cmd.type89.unk0.unk0 << 0) |
             (temp_s0->unk19C.payload.cmd.type89.unk1.unk0 << 1) |
             (temp_s0->unk19C.payload.cmd.type89.unk2.unk0 << 2) |
             (temp_s0->unk19C.payload.cmd.type89.unk3.unk0 << 3) |
             (temp_s0->unk19C.payload.cmd.type89.unk4.unk0 << 4) | // 0x1F
             (temp_s0->unk19C.payload.cmd.type89.unk5.unk0 << 5) |
             (temp_s0->unk19C.payload.cmd.type89.unk6.unk0 << 6) |
             (temp_s0->unk19C.payload.cmd.type89.unk7.unk0 << 7)));
        return 69;

    case 0x5A:
        // something camera related
        func_80343DC0_755470();
        return 69;

    case 0x5B:
        temp_s1->unk164 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0);
        return 69;

    case 0x5C:
        // not used
        func_80363738_774DE8(
            temp_s1,
            func_803146A8_725D58(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2, 0),
            temp_s0->unk19C.payload.cmd.regular.unk0);
        return 69;

    case 0x5D:
        // not used
        func_8036379C_774E4C(temp_s1);
        return 69;

    case 0x5E:
        func_802F657C_707C2C(
            temp_s1,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk0) + temp_s1->xPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2) + temp_s1->zPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4) + temp_s1->yPos.h,
            get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk6));

        temp_s1->unk170 = 5;
        return 69;

    case 0x5F:
        if (temp_s1->unk16C->objectType >= 0x100) {
            sp9A = (temp_s1->zRotation * 360) >> 8;
            sp98 = (temp_s1->yRotation * 360) >> 8;
        } else {
            sp9A = temp_s1->zRotation;
            sp98 = temp_s1->yRotation;
        }

        sp9A += (temp_s0->unk19C.payload.cmd.type95.unk5 * 360) >> 8;
        sp98 += (temp_s0->unk19C.payload.cmd.type95.unk4 * 360) >> 8;

        if (sp9A >= 360) {
            sp9A -= 360;
        } else if (sp9A < 0) {
            sp9A += 360;
        }
        if (sp98 >= 360) {
            sp98 -= 360;
        } else if (sp98 < 0) {
            sp98 += 360;
        }

        func_802F5F44_7075F4(
            temp_s0->unk19C.payload.cmd.type95.unk1,
            temp_s0->unk19C.payload.cmd.type95.unk2,
            temp_s0->unk19C.payload.cmd.type95.unk3,
            sp9A,
            sp98,
            &spA4);
        func_802F5F44_7075F4(
            0,
            temp_s0->unk19C.payload.cmd.type95.unk6 << 8,
            0,
            sp9A,
            sp98,
            &sp9C);

        temp_v0_26 = spawn_animal(
            temp_s1->xPos.h + spA4.unk0,
            temp_s1->zPos.h + spA4.unk2,
            temp_s1->yPos.h + spA4.unk4,
            (sp98 << 8) / 360,
            0x7F,
            temp_s0->unk19C.payload.cmd.type95.unk0,
            0);

        if (temp_v0_26 != NULL) {
            arg0->unk248[7] = (Animal *) temp_v0_26->unk0[0].unk4;
            ((Animal*)temp_v0_26->unk0[0].unk4)->xVelocity.w = sp9C.unk0 << 8;
            ((Animal*)temp_v0_26->unk0[0].unk4)->zVelocity.w = sp9C.unk2 << 8;
            ((Animal*)temp_v0_26->unk0[0].unk4)->yVelocity.w = sp9C.unk4 << 8;
        } else {
            arg0->unk248[7] = NULL;
        }
        if (arg0->unk248[7] == NULL) {
            return 0;
        } else {
            return 69;
        }
        break;

    case 0x60:
        temp_v0_26 = spawn_animal(
            temp_s0->unk19C.payload.cmd.type96.x,
            temp_s0->unk19C.payload.cmd.type96.z,
            temp_s0->unk19C.payload.cmd.type96.y,
            0,
            0x7F,
            temp_s0->unk19C.payload.cmd.type96.id,
            0);

        if (temp_v0_26 != NULL) {
            arg0->unk248[7] = (Animal *) temp_v0_26->unk0[0].unk4;
        } else {
            arg0->unk248[7] = NULL;
        }

        if (arg0->unk248[7] == NULL) {
            return 0;
        } else {
            return 69;
        }
        break;

    case 0x61:
        // only used in SMASHING_START and EVOS_ESCAPE
        func_802F657C_707C2C(
            temp_s1,
            temp_s0->unk19C.payload.cmd.regular.unk0,
            temp_s0->unk19C.payload.cmd.regular.unk2,
            temp_s0->unk19C.payload.cmd.regular.unk4,
            temp_s0->unk19C.payload.cmd.regular.unk6);
        temp_s1->unk170 = 5;
        return 69;

    case 0x62:
        // set camera <something>
        func_80343F58_755608(arg0->commands.unk19C.payload.cmd.regular.unk0);
        return 69;

    case 0x63:
        var_a2_2 = NULL;

        for (i2 = 0; i2 < D_803D553E; i2++) {
            if (temp_s1 == D_801D9ED8.animals[i2].animal) {
                var_a2_2 = &D_801D9ED8.animals[i2];
                break;
            }
        }

        D_803D5520 = var_a2_2;
        D_803D5524 = var_a2_2->unk0;

        D_803D5528 = var_a2_2->animal;
        D_803D552C = D_803D5528;
        D_803D5530 = D_803D5528;

        if (i2 == gCurrentAnimalIndex) {
            D_803D5538 = 1;
        } else {
            D_803D5538 = 0;
        }

        D_803D553C = i2;
        D_803D553A = 0;

        sp74 = temp_s0->unk19C.payload.cmd.regular.unk0 == 0; // is B action
        sp78 = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk2);
        sp7C = get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk4);
        // do_animal_action
        func_80364120_7757D0(
            sp74,
            sp78,
            sp7C,
            func_803146A8_725D58(temp_s1, temp_s0->unk19C.payload.cmd.regular.unk6, 0));
        return 69;

    case 0x64:
        temp_s1->unk226 = ((temp_s0->unk19C.payload.cmd.dummy.unk0 << 8) & 0xF800) | ((temp_s0->unk19C.payload.cmd.dummy.unk1 << 3) & 0x7C0) | ((temp_s0->unk19C.payload.cmd.dummy.unk2 >> 2) & 0x3E);
        temp_s1->unk228 = ((temp_s0->unk19C.payload.cmd.dummy.unk3 << 8) & 0xF800) | ((temp_s0->unk19C.payload.cmd.dummy.unk4 << 3) & 0x7C0) | ((temp_s0->unk19C.payload.cmd.dummy.unk5 >> 2) & 0x3E);

        // force alpha bit to be set?
        if (temp_s1->unk228 != 0) {
            temp_s1->unk228 |= 1;
        }
        if (temp_s1->unk226 != 0) {
            temp_s1->unk226 |= 1;
        }
        return 69;

    case 0x65:
        switch (temp_s0->unk19C.payload.cmd.type101.op) {
        case 0:
            sp84 = ABS(get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk2));
            break;
        case 1:
            sp84 = sqrtf(get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk2));
            break;
        case 2:
            sp84 = SIGNUM(get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk2));
            break;
        case 3:
            sp84 = MAX(get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk2), get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk4));
            break;
        case 4:
            sp84 = MIN(get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk2), get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk4));
            break;
        case 5:
            sp84 = ~get_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.unk2);
            break;
        }

        set_game_state(temp_s1, temp_s0->unk19C.payload.cmd.type101.action + 0x7F7F, sp84);

        return 69;
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80316408_727AB8.s")
#endif

// ESA: func_8004C7B4
void func_803190FC_72A7AC(Animal *arg0) {
    CmdUnknown *cmds;
    s8 i;

    cmds = (CmdUnknown*)&arg0->commands.unk1AC;
    for (i = 0; i < arg0->commands.numCommandsToCopy; i++) {
        if (run_single_command(func_803146A8_725D58(arg0, cmds->unk0.ub[1], 0), cmds) != 0) {
            // finished?
            arg0->commands.unk19C.count = cmds->unk6 + 1;
            copy_command_struct(&arg0->commands.unk1A8[arg0->commands.unk19C.count], &arg0->commands.unk19C.payload);
            arg0->commands.numCommandsToCopy = 0;
            arg0->commands.unk1D4 = 0;
            return;
        }
        cmds++;
    }
}

// ESA: func_8004C87C
void func_803191B0_72A860(Animal *arg0) {
    s8 temp_v0;

    if (arg0->commands.unk1CC == 9) {
        arg0->unk248[0] = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    }
    if (arg0->commands.numCommandsToCopy != 0) {
        func_803190FC_72A7AC(arg0);
    }

    do {
        // get_next_command?
        temp_v0 = func_80316408_727AB8(arg0);
        if (temp_v0 != 0) {
            arg0->commands.unk19C.count++;
            copy_command_struct(&arg0->commands.unk1A8[arg0->commands.unk19C.count], &arg0->commands.unk19C.payload);
        }
    } while (temp_v0 == 69);
}
