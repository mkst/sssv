#include <ultra64.h>
#include "common.h"


s32 func_80362B00_7741B0(Animal *a) {
    if ((a->unk4A != 0) || (a->unk366 == 5) || (a->unk366 == 2)) {
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

s32 func_80362B60_774210(Animal *a) {
    s32 tmp = a->unk162 & 0xF;
    if ((tmp == 4) || (tmp == 5) || (tmp == 6) || (tmp == 7)) {
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
    if (a->unk162 == 2) {
        return 1;
    } else {
        return 0;
    }
}

void func_80362C10_7742C0(Animal *arg0) {
    if (func_80305084_716734(arg0->xPos.h - arg0->xPosTarget, arg0->zPos.h - arg0->zPosTarget, arg0->unk2D4, arg0->unk2D8) > 100) {
        if (arg0->unk2DC == 0) {
            arg0->unk275 = 10;
            arg0->unk2D4 = arg0->xPos.h - arg0->xPosTarget;
            arg0->unk2D8 = arg0->zPos.h - arg0->zPosTarget;
            arg0->unk2DC = 1;
        } else {
            arg0->unk2A0 = 6;
            arg0->unk275 = -1;
            arg0->unk2DC = 0;
        }
    }
}

#ifdef NON_MATCHING
// stack + 1 regalloc
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
    s16 pad2[2];
    Animal *sp28; // help!

    switch (arg0->waypointType) {
    case 0:
        break;
    case 1:
        if (arg0->unk2A0 == 0) {
            if (arg0->unk294.type1.unk2.unk0 > 0) {
                length = (arg0->unk294.type1.unk1 >= arg0->unk29C->length);
            } else {
                length = (arg0->unk294.type1.unk1 < 0);
            }

            if (length != 0) {
                if (arg0->unk294.type1.unk2.unk4 == 1) {
                    func_80363CC8_775378(arg0);
                    arg0->waypointType = 0;
                } else if (arg0->unk294.type1.unk2.unk0 > 0) {
                    arg0->unk294.type1.unk1 = 0;
                } else {
                    arg0->unk294.type1.unk1 = arg0->unk29C->length - 1;
                }
            } else {
                func_80363C48_7752F8(
                    arg0,
                    (arg0->unk29C->waypoint[arg0->unk294.type1.unk1].x << 6) + 32,
                    (arg0->unk29C->waypoint[arg0->unk294.type1.unk1].z << 6) + 32,
                    (arg0->unk29C->waypoint[arg0->unk294.type1.unk1].y << 6) + 32,
                    arg0->unk294.type1.unk4,
                    arg0->unk294.type1.unk3
                    );
                arg0->unk294.type1.unk1 += arg0->unk294.type1.unk2.unk0;
            }
        }
        break;
    case 2:
        if (arg0->unk2A0 == 0) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 3:
        if (arg0->unk2A0 == 0) {
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

            func_80363C48_7752F8(
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
    case 4:
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
                tmp1 = (((D_803E93B0[arg0->unk294.type4.unk0].unk0) + 1) << 6) + (func_8012826C() % phi_v1);
                tmp2 = (((D_803E93B0[arg0->unk294.type4.unk0].unk1) + 1) << 6) + (func_8012826C() % phi_t0);
                func_80363C48_7752F8(
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
            if (arg0->unk2A0 == 0) {
              arg0->unk290 = SSSV_RAND(64) + 60;
              arg0->unk28E = 1;
              func_80363CC8_775378(arg0);
            }
            break;
        }
        break;
    case 5:
        if (arg0->unk2A0 == 0) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 6:
        new_var = &arg0->unk294.type6.unk0;
        if (arg0->yRotation == (((*new_var) * 256) / 360)) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 7:
        xPos = arg0->unk294.type7.unk0->xPos.h - arg0->xPos.h;
        zPos = arg0->unk294.type7.unk0->zPos.h - arg0->zPos.h;
        if (func_803051F0_7168A0((func_801284B8(xPos, zPos) << 8) / 360, arg0->yRotation) < 6) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 8:
        if (arg0->unk294.type8.unk6 != 0) {
            arg0->unk294.type8.unk0 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
            arg0->unk2AC = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
            arg0->unk2CC = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        }
        if (func_803099BC_71B06C() == 0) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 9:
        sp28 = arg0->unk294.type9.unk0;
        if (sp28->unk26C != 0) {
            load_commands_into_object(arg0, NULL, 0);
            func_803638E8_774F98(arg0);
            break;
          }
        switch (arg0->unk28E) {
        case 0:
            if (arg0->unk2A0 == 0) {
                if ((sp28->xVelocity.h | sp28->zVelocity.h | sp28->yVelocity.h) == 0) {
                    func_80363E88_775538(arg0, sp28);
                    arg0->unk28E = 1;
                } else {
                    func_80363DB4_775464(arg0, sp28, -1, arg0->unk294.type9.unk4);
                }
            }
            break;
        case 1:
            xPos = sp28->xPos.h - arg0->xPos.h;
            zPos = sp28->zPos.h - arg0->zPos.h;
            if (func_803051F0_7168A0(((func_801284B8(xPos, zPos) << 8) / 360), arg0->yRotation) < 4) {
                func_8037B754_78CE04(arg0, arg0->unk294.type9.unk0);
                arg0->unk290 = 0;
                arg0->unk28E = 2;
            }
            break;
        case 2:
            if (++arg0->unk290 > 20) {
                func_803638E8_774F98(arg0);
            }
            break;
        }
        break;
    case 10:
        if (++arg0->unk290 > 60) {
            func_803638E8_774F98(arg0);
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80362CC4_774374.s")
#endif

void func_803633C4_774A74(Animal *arg0) {
    s32 tmp0, tmp1;

    switch (arg0->unk2A0) {
    case 0:
        break;
    case 1:
        if ((ABS(arg0->xPosTarget - arg0->xPos.h) < arg0->unk2A2) && (ABS(arg0->zPosTarget - arg0->zPos.h) < arg0->unk2A2)) {
            func_80363CC8_775378(arg0);
        } else {
            func_80362C10_7742C0(arg0);
        }
        break;
    case 2:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        }
        if (arg0->unk2AC->unk26C != 0) {
            func_80363CC8_775378(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->xPos.h;
            arg0->unk27A = arg0->unk2AC->zPos.h;
            if ((can_fly(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = (arg0->unk2AC->yPos.h + (arg0->unk2AC->unk42 >> 1)) - arg0->yPosTarget;
            }
        }
        break;
    case 3:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        }
        arg0->unk278 = arg0->unk2AC->xPos.h;
        arg0->unk27A = arg0->unk2AC->zPos.h;
        break;
    case 4:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        }
        if (arg0->unk2AC->unk26C != 0) {
            func_80363CC8_775378(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->xPos.h;
            arg0->unk27A = arg0->unk2AC->zPos.h;
            if ((can_fly(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = (arg0->unk2AC->yPos.h + (arg0->unk2AC->unk42 >> 1)) - arg0->yPosTarget;
            }
        }
        break;
    case 5:
        break;
    case 6:
        tmp0 = arg0->xPosTarget - arg0->xPos.h;
        tmp1 = arg0->zPosTarget - arg0->zPos.h;

        if (func_803051F0_7168A0((func_801284B8(tmp0, tmp1) << 8) / 360, arg0->yRotation) < 6) {
            arg0->unk2A0 = 1;
            arg0->unk275 = arg0->unk2A1;
        }
        break;
    case 7:
        break;
    case 8:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        }
        if (arg0->unk2AC->unk26C != 0) {
            func_80363CC8_775378(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->xPos.h;
            arg0->unk27A = arg0->unk2AC->zPos.h;
            if ((can_fly(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = ((arg0->unk2AC->yPos.h + (arg0->unk2AC->unk42 >> 1)) - arg0->yPosTarget);
            }
            if (((arg0->unk5C & 5) != 0) && (arg0->unk60 == arg0->unk2AC)) {
                func_80363CC8_775378(arg0);
            }
        }
        break;
    }
}

void func_80363738_774DE8(Animal *arg0, Animal *arg1, u16 arg2) {
    if (arg0->unk320 == 0) {
        arg0->unk28E = 0;
        arg0->waypointType = 9;
        arg0->unk294.type9.unk4 = arg2;
        arg0->unk294.type9.unk0 = arg1;
        func_80363DB4_775464(arg0, arg1, -1, arg2);
    } else {
        func_803638E8_774F98(arg0);
    }
}

void func_8036379C_774E4C(Animal *arg0) {
    arg0->waypointType = 10;
    arg0->unk290 = 0;
    func_8037B784_78CE34(arg0);
    arg0->unk2AC = arg0->unk320;
}

void func_803637D4_774E84(Animal *arg0, Animal *arg1, u16 arg2) {
    arg0->waypointType = 8;
    arg0->unk294.type8.unk4 = arg2;
    arg0->unk294.type8.unk0 = arg1;
    arg0->unk294.type8.unk6 = D_801D9ED8.animals[gCurrentAnimalIndex].animal == arg1;
    func_80363CC8_775378(arg0);
    func_80309E4C_71B4FC(arg1);
    arg0->unk270 = 1;
}

void func_80363844_774EF4(Animal *arg0, s16 arg1) {
    arg0->waypointType = 6;
    arg0->unk294.type6.unk0 = arg1;
    func_80363FB8_775668(arg0, arg1, -0x80, -1);
}

void func_80363880_774F30(Animal *arg0, Animal *arg1) {
    arg0->waypointType = 7;
    arg0->unk294.type7.unk0 = arg1;
    func_80363E88_775538(arg0, arg1);
}

void func_803638A8_774F58(Animal *arg0, Animal *arg1, s16 arg2) {
    arg0->waypointType = 5;
    arg0->unk294.type5.unk0 = arg1;
    arg0->unk294.type5.unk4 = arg2;
    func_80363DB4_775464(arg0, arg1, -1, arg2);
}

void func_803638E8_774F98(Animal *arg0) {
    arg0->waypointType = 0;
    arg0->unk2CC = 0;
    func_80363CC8_775378(arg0);
}

void func_8036390C_774FBC(Animal *arg0, u8 pathId, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
    WaypointData *wp_data;
    s16 next_wp_idx;

    wp_data = D_803E8E60[pathId];
    if (arg3 < 0) {
        next_wp_idx = wp_data->length - 2;
    } else {
        next_wp_idx = 1;
    }
    arg0->waypointType = 1;
    arg0->unk294.type1.pathId = pathId;
    arg0->unk294.type1.unk1 = next_wp_idx;
    arg0->unk294.type1.unk2.unk0 = arg3;
    arg0->unk294.type1.unk4 = arg2;
    arg0->unk294.type1.unk2.unk4 = arg4;
    arg0->unk294.type1.unk3 = arg5;
    arg0->unk29C = wp_data;

    func_80363C48_7752F8(
        arg0,
        (wp_data->waypoint[next_wp_idx].x << 6) + 32,
        (wp_data->waypoint[next_wp_idx].z << 6) + 32,
        (wp_data->waypoint[next_wp_idx].y << 6) + 32,
        arg2,
        arg5);
}

void func_80363A0C_7750BC(Animal *arg0, u8 pathId, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
    WaypointData *wp_data;
    s16 next_wp_idx;

    wp_data = D_803E8E60[pathId];
    next_wp_idx = get_closest_waypoint_index(wp_data, arg0->xPos.h, arg0->zPos.h, arg0->yPos.h);

    arg0->waypointType = 1;
    arg0->unk294.type1.pathId = pathId;
    arg0->unk294.type1.unk1 = next_wp_idx;
    arg0->unk294.type1.unk2.unk0 = arg3;
    arg0->unk294.type1.unk4 = arg2;
    arg0->unk294.type1.unk2.unk4 = arg4;
    arg0->unk294.type1.unk3 = arg5;
    arg0->unk29C = wp_data;

    func_80363C48_7752F8(
        arg0,
        (wp_data->waypoint[next_wp_idx].x << 6) + 32,
        (wp_data->waypoint[next_wp_idx].z << 6) + 32,
        (wp_data->waypoint[next_wp_idx].y << 6) + 32,
        arg2,
        arg5);
    arg0->unk294.type1.unk1 += arg3;
}

void func_80363B34_7751E4(Animal *arg0, u16 arg1) {
    arg0->waypointType = 3;
    arg0->unk294.type3.unk0 = arg1;
    func_80363C48_7752F8(arg0, arg0->xPos.h, arg0->zPos.h, -1, 10, 32);
    arg0->unk290 = SSSV_RAND(4);
}

void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 yPos, s8 arg4, u8 arg5) {
    arg0->waypointType = 2;
    arg0->unk294.type2.xPos = xPos;
    arg0->unk294.type2.zPos = zPos;
    arg0->unk294.type2.yPos = yPos;
    arg0->unk294.type2.unk0 = arg4;
    arg0->unk294.type2.unk1 = arg5;
    func_80363C48_7752F8(arg0, xPos, zPos, yPos, arg4, arg5);
}

void func_80363C0C_7752BC(Animal *arg0, u8 arg1) {
    arg0->waypointType = 4;
    arg0->unk28E = 1;
    arg0->unk290 = 30;
    arg0->unk294.type4.unk0 = arg1;
    func_80363CC8_775378(arg0);
}

void func_80363C48_7752F8(Animal *arg0, s16 xPos, s16 zPos, s16 yPos, s8 arg4, u8 arg5) {
    arg0->unk2A0 = 1;
    arg0->xPosTarget = xPos;
    arg0->zPosTarget = zPos;
    arg0->yPosTarget = yPos;
    arg0->unk2A1 = arg4;
    arg0->unk2A2 = arg5;
    arg0->unk2AC = 0;
    arg0->unk274 = 2;
    arg0->unk275 = arg4;
    arg0->unk278 = xPos;
    arg0->unk27A = zPos;
    arg0->unk27C = yPos;
    arg0->unk2D4 = arg0->xPos.h - xPos;
    arg0->unk2D8 = arg0->zPos.h - zPos;
    arg0->unk2DC = 0;
}

void func_80363CC8_775378(Animal *arg0) {
    arg0->unk2A0 = 0;
    arg0->unk2A1 = 0;
    arg0->unk2AC = 0;
    arg0->unk274 = 0;
    arg0->unk275 = 0;
}

void func_80363CE0_775390(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3) {
    arg0->yPosTarget = arg2;
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 2;
    arg0->unk2B0 = arg1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = arg1->xPos.h;
    arg0->unk27A = arg1->zPos.h;
    if (can_fly(arg1) || func_80362B60_774210(arg1)) {
        arg0->unk27C = arg1->yPos.h + (arg1->unk42 >> 1) + arg2;
    } else {
        arg0->unk27C = arg2;
    }
    arg0->unk274 = 2;
    arg0->unk275 = arg3;
}

void func_80363DB4_775464(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3) {
    arg0->yPosTarget = arg2;
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 8;
    arg0->unk2B0 = arg1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = arg1->xPos.h;
    arg0->unk27A = arg1->zPos.h;
    if (can_fly(arg1) || func_80362B60_774210(arg0->unk2AC)) {
        arg0->unk27C = arg1->yPos.h + (arg1->unk42 >> 1) + arg2;
    } else {
        arg0->unk27C = arg2;
    }
    arg0->unk274 = 2;
    arg0->unk275 = arg3;
}

void func_80363E88_775538(Animal *arg0, Animal *leader) {
    arg0->unk2AC = leader;
    arg0->unk2A0 = 3;
    arg0->unk2B0 = leader == D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = leader->xPos.h;
    arg0->unk27A = leader->zPos.h;
    arg0->unk274 = 2;
    arg0->unk275 = -1;
}

void func_80363EDC_77558C(Animal *arg0, s16 arg1, Animal *arg2) {
    arg0->yPosTarget = arg1;
    arg0->unk2AC = arg2;
    arg0->unk2A0 = 4;
    arg0->unk2A1 = 16;
    arg0->unk2B0 = arg2 == D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    arg0->unk278 = arg2->xPos.h;
    arg0->unk27A = arg2->zPos.h;
    arg0->unk274 = 3;
    arg0->unk275 = 16;
    if (can_fly(arg2) || func_80362B60_774210(arg2)) {
        arg0->unk27C = arg2->yPos.h + (arg2->unk42 >> 1) + arg1;
    } else {
        arg0->unk27C = arg1;
    }
}

void func_80363FB8_775668(Animal *arg0, u16 arg1, s16 arg2, s16 arg3) {
    arg0->yPosTarget = arg2;
    arg0->unk2A1 = arg3;
    arg0->unk2A0 = 5;
    arg0->unk2AC = 0;
    arg0->unk276 = arg1;
    arg0->unk27C = arg2;
    arg0->unk275 = arg3;
    arg0->unk274 = 1;
}

void func_80363FF0_7756A0(Animal *arg0) {
    switch (arg0->waypointType) {
    case 0:
        func_803638E8_774F98(arg0);
        break;
    case 1:
        func_80363A0C_7750BC(arg0, arg0->unk294.type1.pathId, arg0->unk294.type1.unk4, arg0->unk294.type1.unk2.unk0, arg0->unk294.type1.unk2.unk4, arg0->unk294.type1.unk3);
        break;
    case 2:
        func_80363B98_775248(arg0, arg0->unk294.type2.xPos, arg0->unk294.type2.zPos, arg0->unk294.type2.yPos, arg0->unk294.type2.unk0, arg0->unk294.type2.unk1);
        break;
    case 3:
        func_80363B34_7751E4(arg0, arg0->unk294.type3.unk0);
        break;
    case 4:
        func_80363C0C_7752BC(arg0, arg0->unk294.type4.unk0);
        break;
    case 5:
        func_803638A8_774F58(arg0, arg0->unk294.type5.unk0, arg0->unk294.type5.unk4);
        break;
    case 6:
        func_80363844_774EF4(arg0, arg0->unk294.type6.unk0);
        break;
    case 7:
        func_80363880_774F30(arg0, arg0->unk294.type7.unk0); // follow leader
        break;
    case 8:
        func_803637D4_774E84(arg0, arg0->unk294.type8.unk0, arg0->unk294.type8.unk4);
        break;
    case 9:
        func_80363738_774DE8(arg0, arg0->unk294.type9.unk0, arg0->unk294.type9.unk4);
        break;
    case 10:
        func_803638E8_774F98(arg0);
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
            func_8036F740_780DF0(D_803D5530->yRotation);
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
            func_8035C10C_76D7BC();
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
            func_803562C8_767978(arg1);
            break;
        case RACING_TORTOISE:
            func_80356348_7679F8(arg1);
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
            func_8037FEDC_79158C();
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
            func_8036F50C_780BBC(arg3);
            break;
        case CANNON_CAMEL:
            camel_cannon_fire_cannon(arg3);
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
