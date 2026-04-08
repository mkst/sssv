#include <ultra64.h>
#include "common.h"


// ESA: func_80060D74
s32 func_80362B00_7741B0(Animal *a) {
    if ((a->unk4A != 0) || (a->movementMode == MOVEMENT_MODE_DEACTIVATED) || (a->movementMode == MOVEMENT_MODE_2)) {
        return 1;
    } else {
        return 0;
    }
}

s32 can_swim(Animal *a) {
    if (a->unk16C->waterClass & WATER_SWIM) {
        return 1;
    } else {
        return 0;
    }
}

// ESA: func_80060DC8
s32 func_80362B60_774210(Animal *a) {
    s32 movementState = a->movementState & 0xF;
    if ((movementState == 4) || (movementState == 5) || (movementState == 6) || (movementState == 7)) {
        return 1;
    } else {
        return 0;
    }
}

s32 water_hurts(Animal *a) {
    if (a->unk16C->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
        return 1;
    } else {
        return 0;
    }
}

s32 can_fly(Animal *a) {
    if (a->unk16C->class & (CLASS_BIRD | CLASS_FLYING | CLASS_HELI)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362BEC_77429C(Animal *a) {
    if (a->movementState == 2) {
        return 1;
    } else {
        return 0;
    }
}

// ESA: func_80060DFC
void func_80362C10_7742C0(Animal *arg0) {
    if (func_80305084_716734(arg0->position.xPos.h - arg0->xPosTarget, arg0->position.zPos.h - arg0->zPosTarget, arg0->unk2D4, arg0->unk2D8) > 100) {
        if (arg0->unk2DC == 0) {
            arg0->navTimer = 10;
            arg0->unk2D4 = arg0->position.xPos.h - arg0->xPosTarget;
            arg0->unk2D8 = arg0->position.zPos.h - arg0->zPosTarget;
            arg0->unk2DC = 1;
        } else {
            arg0->navState = NAVIGATION_STATE_TURN_THEN_MOVE;
            arg0->navTimer = -1;
            arg0->unk2DC = 0;
        }
    }
}

// ESA: func_80060EB0
void func_80362CC4_774374(Animal *arg0) {
    s16 pad;
    s16 sp54;
    s16 sp52;
    s16 temp_t3;
    s16 temp_t7;
    s16 tmp1;
    s16 tmp2;
    s16 phi_v1;
    s16 phi_t0;
    s16 *new_var;
    u8 length;
    s32 xPos;
    s32 zPos;
    s32 xPos2;
    s32 zPos2;
    Animal *target;

    switch (arg0->waypointMode) {
    case WAYPOINT_MODE_NONE:
        break;
    case WAYPOINT_MODE_PATH:
        if (arg0->navState == NAVIGATION_STATE_IDLE) {
            if (arg0->unk294.type1.unk2.unk0 > 0) {
                length = (arg0->unk294.type1.unk1 >= arg0->waypointData->length);
            } else {
                length = (arg0->unk294.type1.unk1 < 0);
            }

            if (length != 0) {
                if (arg0->unk294.type1.unk2.unk4 == 1) {
                    set_nav_state_idle(arg0);
                    arg0->waypointMode = WAYPOINT_MODE_NONE;
                } else if (arg0->unk294.type1.unk2.unk0 > 0) {
                    arg0->unk294.type1.unk1 = 0;
                } else {
                    arg0->unk294.type1.unk1 = arg0->waypointData->length - 1;
                }
            } else {
                set_nav_state_goto_point(
                    arg0,
                    (arg0->waypointData->waypoint[arg0->unk294.type1.unk1].x << 6) + 32,
                    (arg0->waypointData->waypoint[arg0->unk294.type1.unk1].z << 6) + 32,
                    (arg0->waypointData->waypoint[arg0->unk294.type1.unk1].y << 6) + 32,
                    arg0->unk294.type1.unk4,
                    arg0->unk294.type1.unk3
                    );
                arg0->unk294.type1.unk1 += arg0->unk294.type1.unk2.unk0;
            }
        }
        break;
    case WAYPOINT_MODE_MOVE:
        if (arg0->navState == NAVIGATION_STATE_IDLE) {
            reset_waypoint_mode(arg0);
        }
        break;
    case WAYPOINT_MODE_PATROL:
        if (arg0->navState == NAVIGATION_STATE_IDLE) {
            temp_t7 = (D_803E93B0[arg0->unk294.type3.unk0].unk3 - D_803E93B0[arg0->unk294.type3.unk0].unk0) >> 2;
            temp_t3 = (D_803E93B0[arg0->unk294.type3.unk0].unk4 - D_803E93B0[arg0->unk294.type3.unk0].unk1) >> 2;
            switch (arg0->unk290) {
            case 0:
                sp54 = D_803E93B0[arg0->unk294.type3.unk0].unk0 + temp_t7;
                sp52 = D_803E93B0[arg0->unk294.type3.unk0].unk1 + temp_t3;
                break;
            case 1:
                sp54 = D_803E93B0[arg0->unk294.type3.unk0].unk3 - temp_t7;
                sp52 = D_803E93B0[arg0->unk294.type3.unk0].unk1 + temp_t3;
                break;
            case 2:
                sp54 = D_803E93B0[arg0->unk294.type3.unk0].unk3 - temp_t7;
                sp52 = D_803E93B0[arg0->unk294.type3.unk0].unk4 - temp_t3;
                break;
            case 3:
                sp54 = D_803E93B0[arg0->unk294.type3.unk0].unk0 + temp_t7;
                sp52 = D_803E93B0[arg0->unk294.type3.unk0].unk4 - temp_t3;
                break;
            }

            set_nav_state_goto_point(
                arg0,
                (sp54 << 6) + 32,
                (sp52 << 6) + 32,
                -1,
                10,
                32);
            arg0->unk290 += 1;
            arg0->unk290 &= 3;
        }
        break;
    case WAYPOINT_MODE_RANDOM:
        switch (arg0->unk28E) {

        case 1:
            if (arg0->unk290 == 0) {
                phi_v1 = ((D_803E93B0[arg0->unk294.type4.unk0].unk3 - D_803E93B0[arg0->unk294.type4.unk0].unk0) - 1) << 6;
                phi_t0 = ((D_803E93B0[arg0->unk294.type4.unk0].unk4 - D_803E93B0[arg0->unk294.type4.unk0].unk1) - 1) << 6;
                if (phi_v1 <= 0) {
                    phi_v1 = 1;
                }
                if (phi_t0 <= 0) {
                    phi_t0 = 1;
                }
                tmp1 = (((D_803E93B0[arg0->unk294.type4.unk0].unk0) + 1) << 6) + (advance_random_seed() % phi_v1);
                tmp2 = (((D_803E93B0[arg0->unk294.type4.unk0].unk1) + 1) << 6) + (advance_random_seed() % phi_t0);
                set_nav_state_goto_point(
                    arg0,
                    tmp1,
                    tmp2,
                    -1,
                    10,
                    32);
                arg0->unk28E = 0;
            } else {
                arg0->unk290 -= 1;
            }
            break;
        case 0:
            if (arg0->navState == NAVIGATION_STATE_IDLE) {
              arg0->unk290 = SSSV_RAND(64) + 60;
              arg0->unk28E = 1;
              set_nav_state_idle(arg0);
            }
            break;
        }
        break;
    case WAYPOINT_MODE_CHASE:
        if (arg0->navState == NAVIGATION_STATE_IDLE) {
            reset_waypoint_mode(arg0);
        }
        break;
    case WAYPOINT_MODE_ROTATE:
        new_var = &arg0->unk294.type6.unk0;
        if (arg0->yRotation == (((*new_var) * 256) / 360)) {
            reset_waypoint_mode(arg0);
        }
        break;
    case WAYPOINT_MODE_FOLLOW:
        xPos = arg0->unk294.type7.unk0->position.xPos.h - arg0->position.xPos.h;
        zPos = arg0->unk294.type7.unk0->position.zPos.h - arg0->position.zPos.h;
        if (func_803051F0_7168A0((func_801284B8(xPos, zPos) << 8) / 360, arg0->yRotation) < 6) {
            reset_waypoint_mode(arg0);
        }
        break;
    case WAYPOINT_MODE_ENGAGE_PLAYER:
        if (arg0->unk294.type8.unk6 != 0) {
            arg0->unk294.type8.target = gAnimalState.animals[gCurrentAnimalIndex].animal;
            arg0->unk2AC = gAnimalState.animals[gCurrentAnimalIndex].animal;
            arg0->unk2CC = gAnimalState.animals[gCurrentAnimalIndex].animal;
        }
        if (func_803099BC_71B06C() == 0) {
            reset_waypoint_mode(arg0);
        }
        break;
    case WAYPOINT_MODE_ENGAGE_OTHER:
        target = arg0->unk294.type9.target;
        if (target->unk26C != NULL) {
            load_commands_into_object((Entity*)arg0, NULL, 0);
            reset_waypoint_mode(arg0);
            break;
          }
        switch (arg0->unk28E) {
        case 0:
            if (arg0->navState == NAVIGATION_STATE_IDLE) {
                if ((target->xVelocity.h | target->zVelocity.h | target->yVelocity.h) == 0) {
                    set_nav_state_follow_target(arg0, target);
                    arg0->unk28E = 1;
                } else {
                    set_nav_state_chase_attack(arg0, target, -1, arg0->unk294.type9.unk4);
                }
            }
            break;
        case 1:
            xPos2 = target->position.xPos.h - arg0->position.xPos.h;
            zPos2 = target->position.zPos.h - arg0->position.zPos.h;
            if (func_803051F0_7168A0((func_801284B8(xPos2, zPos2) << 8) / 360, arg0->yRotation) < 4) {
                func_8037B754_78CE04(arg0, arg0->unk294.type9.target);
                arg0->unk290 = 0;
                arg0->unk28E = 2;
            }
            break;
        case 2:
            if (++arg0->unk290 > 20) {
                reset_waypoint_mode(arg0);
            }
            break;
        }
        break;
    case WAYPOINT_MODE_WAIT:
        if (++arg0->unk290 > 60) {
            reset_waypoint_mode(arg0);
        }
        break;
    }
}

// ESA: func_80061318
void func_803633C4_774A74(Animal *arg0) {
    s32 xDist, zDist;

    switch (arg0->navState) {
    case NAVIGATION_STATE_IDLE:
        break;
    case NAVIGATION_STATE_GOTO_POINT:
        if ((ABS(arg0->xPosTarget - arg0->position.xPos.h) < arg0->unk2A2) && (ABS(arg0->zPosTarget - arg0->position.zPos.h) < arg0->unk2A2)) {
            set_nav_state_idle(arg0);
        } else {
            func_80362C10_7742C0(arg0);
        }
        break;
    case NAVIGATION_STATE_CHASE_TARGET:
        if (arg0->targetIsPlayer != 0) {
            arg0->unk2AC = gAnimalState.animals[gCurrentAnimalIndex].animal;
        }
        if (arg0->unk2AC->unk26C != NULL) {
            set_nav_state_idle(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->position.xPos.h;
            arg0->unk27A = arg0->unk2AC->position.zPos.h;
            if ((can_fly(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = (arg0->unk2AC->position.yPos.h + (arg0->unk2AC->unk42 >> 1)) - arg0->yPosTarget;
            }
        }
        break;
    case NAVIGATION_STATE_FOLLOW_TARGET:
        if (arg0->targetIsPlayer != 0) {
            arg0->unk2AC = gAnimalState.animals[gCurrentAnimalIndex].animal;
        }
        arg0->unk278 = arg0->unk2AC->position.xPos.h;
        arg0->unk27A = arg0->unk2AC->position.zPos.h;
        break;
    case NAVIGATION_STATE_FOLLOW_TARGET_2:
        if (arg0->targetIsPlayer != 0) {
            arg0->unk2AC = gAnimalState.animals[gCurrentAnimalIndex].animal;
        }
        if (arg0->unk2AC->unk26C != NULL) {
            set_nav_state_idle(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->position.xPos.h;
            arg0->unk27A = arg0->unk2AC->position.zPos.h;
            if ((can_fly(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = (arg0->unk2AC->position.yPos.h + (arg0->unk2AC->unk42 >> 1)) - arg0->yPosTarget;
            }
        }
        break;
    case NAVIGATION_STATE_SCRIPTED:
        break;
    case NAVIGATION_STATE_TURN_THEN_MOVE:
        xDist = arg0->xPosTarget - arg0->position.xPos.h;
        zDist = arg0->zPosTarget - arg0->position.zPos.h;

        if (func_803051F0_7168A0((func_801284B8(xDist, zDist) << 8) / 360, arg0->yRotation) < 6) {
            arg0->navState = NAVIGATION_STATE_GOTO_POINT;
            arg0->navTimer = arg0->unk2A1;
        }
        break;
    case NAVIGATION_STATE_UNUSED_7:
        break;
    case NAVIGATION_STATE_CHASE_ATTACK:
        if (arg0->targetIsPlayer != 0) {
            arg0->unk2AC = gAnimalState.animals[gCurrentAnimalIndex].animal;
        }
        if (arg0->unk2AC->unk26C != NULL) {
            set_nav_state_idle(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->position.xPos.h;
            arg0->unk27A = arg0->unk2AC->position.zPos.h;
            if ((can_fly(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = ((arg0->unk2AC->position.yPos.h + (arg0->unk2AC->unk42 >> 1)) - arg0->yPosTarget);
            }
            if (((arg0->unk5C.unk0 & (0x4|0x1)) != 0) && ((Animal*)arg0->unk5C.unk4 == arg0->unk2AC)) {
                set_nav_state_idle(arg0);
            }
        }
        break;
    }
}

// ESA: func_80061610
void set_nav_state_engage_other(Animal *arg0, Animal *target, u16 arg2) {
    if (arg0->unk320 == 0) {
        arg0->unk28E = 0;
        arg0->waypointMode = WAYPOINT_MODE_ENGAGE_OTHER;
        arg0->unk294.type9.unk4 = arg2;
        arg0->unk294.type9.target = target;
        set_nav_state_chase_attack(arg0, target, -1, arg2);
    } else {
        reset_waypoint_mode(arg0);
    }
}

// ESA: func_80061670
void func_8036379C_774E4C(Animal *arg0) {
    arg0->waypointMode = WAYPOINT_MODE_WAIT;
    arg0->unk290 = 0;
    func_8037B784_78CE34(arg0);
    arg0->unk2AC = arg0->unk320;
}

// ESA: func_80061688
void set_nav_state_engage_player(Animal *arg0, Animal *target, u16 arg2) {
    arg0->waypointMode = WAYPOINT_MODE_ENGAGE_PLAYER;
    arg0->unk294.type8.unk4 = arg2;
    arg0->unk294.type8.target = target;
    arg0->unk294.type8.unk6 = gAnimalState.animals[gCurrentAnimalIndex].animal == target;
    set_nav_state_idle(arg0);
    func_80309E4C_71B4FC(target);
    arg0->unk270 = 1;
}

// ESA: func_80061700
void func_80363844_774EF4(Animal *arg0, s16 arg1) {
    arg0->waypointMode = WAYPOINT_MODE_ROTATE;
    arg0->unk294.type6.unk0 = arg1;
    set_nav_state_scripted(arg0, arg1, -0x80, -1);
}

// ESA: func_8006173C
void set_waypoint_follow_target(Animal *arg0, Animal *target) {
    arg0->waypointMode = WAYPOINT_MODE_FOLLOW;
    arg0->unk294.type7.unk0 = target;
    set_nav_state_follow_target(arg0, target);
}

// ESA: func_80061764
void func_803638A8_774F58(Animal *arg0, Animal *target, s16 arg2) {
    arg0->waypointMode = WAYPOINT_MODE_CHASE;
    arg0->unk294.type5.unk0 = target;
    arg0->unk294.type5.unk4 = arg2;
    set_nav_state_chase_attack(arg0, target, -1, arg2);
}

// ESA: func_8006179C
void reset_waypoint_mode(Animal *arg0) {
    arg0->waypointMode = WAYPOINT_MODE_NONE;
    arg0->unk2CC = NULL;
    set_nav_state_idle(arg0);
}

// ESA: func_800617C0
void func_8036390C_774FBC(Animal *arg0, u8 pathId, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
    WaypointData *wp_data;
    s16 next_wp_idx;

    wp_data = D_803E8E60[pathId];
    if (arg3 < 0) {
        next_wp_idx = wp_data->length - 2;
    } else {
        next_wp_idx = 1;
    }
    arg0->waypointMode = WAYPOINT_MODE_PATH;
    arg0->unk294.type1.pathId = pathId;
    arg0->unk294.type1.unk1 = next_wp_idx;
    arg0->unk294.type1.unk2.unk0 = arg3;
    arg0->unk294.type1.unk4 = arg2;
    arg0->unk294.type1.unk2.unk4 = arg4;
    arg0->unk294.type1.unk3 = arg5;
    arg0->waypointData = wp_data;

    set_nav_state_goto_point(
        arg0,
        (wp_data->waypoint[next_wp_idx].x << 6) + 32,
        (wp_data->waypoint[next_wp_idx].z << 6) + 32,
        (wp_data->waypoint[next_wp_idx].y << 6) + 32,
        arg2,
        arg5);
}

// ESA: func_800618C0
void func_80363A0C_7750BC(Animal *arg0, u8 pathId, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
    WaypointData *wp_data;
    s16 next_wp_idx;

    wp_data = D_803E8E60[pathId];
    next_wp_idx = get_closest_waypoint_index(wp_data, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h);

    arg0->waypointMode = WAYPOINT_MODE_PATH;
    arg0->unk294.type1.pathId = pathId;
    arg0->unk294.type1.unk1 = next_wp_idx;
    arg0->unk294.type1.unk2.unk0 = arg3;
    arg0->unk294.type1.unk4 = arg2;
    arg0->unk294.type1.unk2.unk4 = arg4;
    arg0->unk294.type1.unk3 = arg5;
    arg0->waypointData = wp_data;

    set_nav_state_goto_point(
        arg0,
        (wp_data->waypoint[next_wp_idx].x << 6) + 32,
        (wp_data->waypoint[next_wp_idx].z << 6) + 32,
        (wp_data->waypoint[next_wp_idx].y << 6) + 32,
        arg2,
        arg5);
    arg0->unk294.type1.unk1 += arg3;
}

// ESA: func_800619FC
void func_80363B34_7751E4(Animal *arg0, u16 arg1) {
    arg0->waypointMode = WAYPOINT_MODE_PATROL;
    arg0->unk294.type3.unk0 = arg1;
    set_nav_state_goto_point(arg0, arg0->position.xPos.h, arg0->position.zPos.h, -1, 10, 32);
    arg0->unk290 = SSSV_RAND(4);
}

// ESA: func_80061A58
void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 yPos, s8 arg4, u8 arg5) {
    arg0->waypointMode = WAYPOINT_MODE_MOVE;
    arg0->unk294.type2.xPos = xPos;
    arg0->unk294.type2.zPos = zPos;
    arg0->unk294.type2.yPos = yPos;
    arg0->unk294.type2.unk0 = arg4;
    arg0->unk294.type2.unk1 = arg5;
    set_nav_state_goto_point(arg0, xPos, zPos, yPos, arg4, arg5);
}

// ESA: func_80061AB8
void func_80363C0C_7752BC(Animal *arg0, u8 arg1) {
    arg0->waypointMode = WAYPOINT_MODE_RANDOM;
    arg0->unk28E = 1;
    arg0->unk290 = 30;
    arg0->unk294.type4.unk0 = arg1;
    set_nav_state_idle(arg0);
}

// ESA: func_80061AF0
void set_nav_state_goto_point(Animal *arg0, s16 xPos, s16 zPos, s16 yPos, s8 arg4, u8 arg5) {
    arg0->navState = NAVIGATION_STATE_GOTO_POINT;
    arg0->xPosTarget = xPos;
    arg0->zPosTarget = zPos;
    arg0->yPosTarget = yPos;
    arg0->unk2A1 = arg4;
    arg0->unk2A2 = arg5;
    arg0->unk2AC = 0;
    arg0->navMode = 2;
    arg0->navTimer = arg4;
    arg0->unk278 = xPos;
    arg0->unk27A = zPos;
    arg0->unk27C = yPos;
    arg0->unk2D4 = arg0->position.xPos.h - xPos;
    arg0->unk2D8 = arg0->position.zPos.h - zPos;
    arg0->unk2DC = 0;
}

// ESA: func_80061B68
void set_nav_state_idle(Animal *arg0) {
    arg0->navState = NAVIGATION_STATE_IDLE;
    arg0->unk2A1 = 0;
    arg0->unk2AC = 0;
    arg0->navMode = 0;
    arg0->navTimer = 0;
}

// ESA: func_80061B80
void set_nav_state_chase_target(Animal *arg0, Animal *target, s16 yPos, s16 arg3) {
    arg0->yPosTarget = yPos;
    arg0->unk2AC = target;
    arg0->navState = NAVIGATION_STATE_CHASE_TARGET;
    arg0->targetIsPlayer = target == gAnimalState.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = target->position.xPos.h;
    arg0->unk27A = target->position.zPos.h;
    if (can_fly(target) || func_80362B60_774210(target)) {
        arg0->unk27C = target->position.yPos.h + (target->unk42 >> 1) + yPos;
    } else {
        arg0->unk27C = yPos;
    }
    arg0->navMode = 2;
    arg0->navTimer = arg3;
}

// ESA: func_80061C60
void set_nav_state_chase_attack(Animal *arg0, Animal *target, s16 yPos, s16 arg3) {
    arg0->yPosTarget = yPos;
    arg0->unk2AC = target;
    arg0->navState = NAVIGATION_STATE_CHASE_ATTACK;
    arg0->targetIsPlayer = target == gAnimalState.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = target->position.xPos.h;
    arg0->unk27A = target->position.zPos.h;
    if (can_fly(target) || func_80362B60_774210(arg0->unk2AC)) {
        arg0->unk27C = target->position.yPos.h + (target->unk42 >> 1) + yPos;
    } else {
        arg0->unk27C = yPos;
    }
    arg0->navMode = 2;
    arg0->navTimer = arg3;
}

// ESA: func_80061D44
void set_nav_state_follow_target(Animal *arg0, Animal *target) {
    arg0->unk2AC = target;
    arg0->navState = NAVIGATION_STATE_FOLLOW_TARGET;
    arg0->targetIsPlayer = target == gAnimalState.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = target->position.xPos.h;
    arg0->unk27A = target->position.zPos.h;
    arg0->navMode = 2;
    arg0->navTimer = -1;
}

// ESA: func_80061D9C
void func_80363EDC_77558C(Animal *arg0, s16 yPos, Animal *target) {
    arg0->yPosTarget = yPos;
    arg0->unk2AC = target;
    arg0->navState = NAVIGATION_STATE_FOLLOW_TARGET_2;
    arg0->unk2A1 = 16;
    arg0->targetIsPlayer = target == gAnimalState.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = target->position.xPos.h;
    arg0->unk27A = target->position.zPos.h;
    arg0->navMode = 3;
    arg0->navTimer = 16;
    if (can_fly(target) || func_80362B60_774210(target)) {
        arg0->unk27C = target->position.yPos.h + (target->unk42 >> 1) + yPos;
    } else {
        arg0->unk27C = yPos;
    }
}

// ESA: func_80061E74
void set_nav_state_scripted(Animal *arg0, u16 arg1, s16 yPos, s16 arg3) {
    arg0->yPosTarget = yPos;
    arg0->unk2A1 = arg3;
    arg0->navState = NAVIGATION_STATE_SCRIPTED;
    arg0->unk2AC = 0;
    arg0->unk276 = arg1;
    arg0->unk27C = yPos;
    arg0->navTimer = arg3;
    arg0->navMode = 1;
}

// ESA: func_80061EB0
void func_80363FF0_7756A0(Animal *arg0) {
    switch (arg0->waypointMode) {
    case WAYPOINT_MODE_NONE:
        reset_waypoint_mode(arg0);
        break;
    case WAYPOINT_MODE_PATH:
        func_80363A0C_7750BC(arg0, arg0->unk294.type1.pathId, arg0->unk294.type1.unk4, arg0->unk294.type1.unk2.unk0, arg0->unk294.type1.unk2.unk4, arg0->unk294.type1.unk3);
        break;
    case WAYPOINT_MODE_MOVE:
        func_80363B98_775248(arg0, arg0->unk294.type2.xPos, arg0->unk294.type2.zPos, arg0->unk294.type2.yPos, arg0->unk294.type2.unk0, arg0->unk294.type2.unk1);
        break;
    case WAYPOINT_MODE_PATROL:
        func_80363B34_7751E4(arg0, arg0->unk294.type3.unk0);
        break;
    case WAYPOINT_MODE_RANDOM:
        func_80363C0C_7752BC(arg0, arg0->unk294.type4.unk0);
        break;
    case WAYPOINT_MODE_CHASE:
        func_803638A8_774F58(arg0, arg0->unk294.type5.unk0, arg0->unk294.type5.unk4);
        break;
    case WAYPOINT_MODE_ROTATE:
        func_80363844_774EF4(arg0, arg0->unk294.type6.unk0);
        break;
    case WAYPOINT_MODE_FOLLOW:
        set_waypoint_follow_target(arg0, arg0->unk294.type7.unk0);
        break;
    case WAYPOINT_MODE_ENGAGE_PLAYER:
        set_nav_state_engage_player(arg0, arg0->unk294.type8.target, arg0->unk294.type8.unk4);
        break;
    case WAYPOINT_MODE_ENGAGE_OTHER:
        set_nav_state_engage_other(arg0, arg0->unk294.type9.target, arg0->unk294.type9.unk4);
        break;
    case WAYPOINT_MODE_WAIT:
        reset_waypoint_mode(arg0);
        break;
    }
}

void func_80364120_7757D0(u8 arg0, s16 arg1, s16 arg2, Animal *arg3) {
    // skill A
    if (arg0 == 0) {
        switch (D_803D5524->unk9C) {
        case SEAGULL:
            break;
        case LION:
            animal_jump();
            break;
        case HIPPO:
            hippo_spit(0, 0, 0);
            break;
        case RACING_DOG:
            racing_dog_turbo(arg1);
            break;
        case FLYING_DOG:
            flying_dog_fire_gun(0, 0, 0);
            break;
        case FOX:
            fox_warp();
            break;
        case FROG:
            animal_jump();
            break;
        case RABBIT:
            animal_jump();
            break;
        case KING_RAT:
            king_rat_fart(60);
            break;
        case PARROT:
            parrot_fly();
            break;
        case MOUSE:
            animal_jump();
            break;
        case RACING_MOUSE:
            racing_mouse_turbo(arg1);
            break;
        case MOUSE2:
            animal_jump();
            break;
        case RACING_FOX:
            fox_warp();
            break;
        case RACING_TORTOISE:
            racing_tortoise_turbo(arg1);
            break;
        case PIRANA:
            animal_jump();
            break;
        case DOG:
            animal_jump();
            break;
        case RAT:
            rat_drop_mine();
            break;
        case SHEEP:
            animal_jump();
            break;
        case RAM:
            animal_jump();
            break;
        case SPRINGY_THINGY:
            animal_jump();
            break;
        case SPRINGY_RAM:
            animal_jump();
            break;
        case PENGUIN:
            animal_jump();
            break;
        case POLAR_BEAR:
            polar_bear_jump_thump();
            break;
        case POLAR_TANK:
            polar_tank_fire_cannon();
            break;
        case HUSKY:
            animal_jump();
            break;
        case SKI_HUSKY:
            ski_husky_turbo(arg1);
            break;
        case WALRUS:
            walrus_turbo(arg1);
            break;
        case CAMEL:
            animal_jump();
            break;
        case CANNON_CAMEL:
            cannon_camel_dash(D_803D5530->yRotation);
            break;
        case POGO_KANGAROO:
            animal_jump();
            break;
        case BOXING_KANGAROO:
            animal_jump();
            break;
        case DESERT_FOX:
            animal_jump();
            break;
        case ARMED_DESERT_FOX:
            animal_jump();
            break;
        case SCORPION:
            func_803791AC_78A85C();
            break;
        case GORILLA:
            animal_jump();
            break;
        case ELEPHANT:
            func_8037D268_78E918(arg1);
            break;
        case HYENA:
            animal_jump();
            break;
        case HYENA_BIKER:
            func_8035A5A4_76BC54(arg1);
            break;
        case CHAMELEON:
            chameleon_attack_2();
            break;
        case COOL_COD:
            break;
        }
    } else {
        // skill B
        switch (D_803D5524->unk9C) {
        case SEAGULL:
        case LION:
            lion_roar();
            break;
        case HIPPO:
            drop_sticky_mine();
            break;
        case RACING_DOG:
            racing_dog_fire_missile(arg3);
            break;
        case FLYING_DOG:
            flying_dog_drop_bomb(0, 0, 0);
            break;
        case FOX:
            func_802E88C0_6F9F70(arg1);
            break;
        case FIRE_FOX:
            fire_fox_fire_missile(arg3);
            break;
        case FROG:
            frog_croak();
            break;
        case POLAR_BEAR_DEFENDING:
            func_80368D60_77A410(arg1);
            break;
        case RABBIT:
            func_803021A8_713858();
            break;
        case HELI_RABBIT:
            heli_rabbit_drop_bomb(0, 0, 0);
            break;
        case MOUSE:
            func_8031FB30_7311E0(arg1);
            break;
        case RACING_MOUSE:
            func_8031FB78_731228(arg1);
            break;
        case MOUSE2:
            func_8031FB30_7311E0(arg1);
            break;
        case BEAR:
            func_80327B94_739244(arg1);
            break;
        case RACING_FOX:
            func_802E88C0_6F9F70(arg1);
            break;
        case TORTOISE_TANK:
            tortoise_tank_defend(arg1);
            break;
        case RACING_TORTOISE:
            racing_tortoise_defend(arg1);
            break;
        case PIRANA:
            func_80382CC0_794370(arg1);
            break;
        case DOG:
            dog_bite();
            break;
        case RAT:
            rat_bite();
            break;
        case SHEEP:
            sheep_follow_leader();
            break;
        case RAM:
            ram_headbutt();
            break;
        case SPRINGY_RAM:
            ram_headbutt();
            break;
        case PENGUIN:
            penguin_throw_snowball(arg3);
            break;
        case POLAR_BEAR:
            func_80368D60_77A410(arg1);
            break;
        case POLAR_TANK:
            polar_tank_drop_mine();
            break;
        case HUSKY:
            func_8036C014_77D6C4(arg1);
            break;
        case SKI_HUSKY:
            ski_husky_fire_missile(arg3);
            break;
        case WALRUS:
            walrus_fire_missile(arg3);
            break;
        case CAMEL:
            camel_fire_water_cannon(arg3);
            break;
        case CANNON_CAMEL:
            cannon_camel_fire_cannon(arg3);
            break;
        case POGO_KANGAROO:
            func_80372698_783D48();
            break;
        case BOXING_KANGAROO:
            func_80372604_783CB4();
            break;
        case DESERT_FOX:
            func_803745C4_785C74(arg1);
            break;
        case ARMED_DESERT_FOX:
            func_8037460C_785CBC();
            break;
        case SCORPION:
            func_80379148_78A7F8(arg3);
            break;
        case HYENA:
            func_8035A590_76BC40(arg1);
            break;
        case HYENA_BIKER:
            biker_hyena_fire_missile(arg3);
            break;
        case CHAMELEON:
            func_8035C180_76D830(arg1);
            break;
        case SNEAKY_CHAMELEON:
            func_8035C180_76D830(arg1);
            break;
        case COOL_COD:
            break;
        }
    }
}
