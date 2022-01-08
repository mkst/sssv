#include <ultra64.h>
#include "common.h"


void func_80319A50_72B100(void) {
    bzero_sssv((u8*)D_803E8F60, 1100); // raw waypoint data
    bzero_sssv((u8*)D_803E8E60, 256);  // pointers to waypoints
    D_803E93B0[0].unk5 = D_803E93B0[0].unk2 = 245;
    D_803A5750_7B6E00 = 0;
}

void func_80319AA0_72B150(u8 *arg0, u8 arg1) {
    *(arg0 + *arg0 + 1) = arg1;
    *(arg0 + 5) = arg1;
    *arg0 = *arg0 + 1;
}

// might be waypoint too?
void func_80319AC4_72B174(u8 *arg0, u8 arg1) {
    s8 i;
    s32 idx; // regalloc

    for (i = 0; i < arg0[0]; i++) {
        idx = i + 1;
        if (arg1 == arg0[idx]) {
            break;
        }
    }

    arg0[0]--;

    for (; i < arg0[0]; i++) {
        idx = i + 2;
        arg0[i + 1] = arg0[idx];
    }
}

u16 get_closest_waypoint_index(WaypointData *arg0, s16 x, s16 z, s16 y) {
    u16 i;
    u16 res;
    Waypoint *wp;
    s32 max_dist;
    s32 dist;

    max_dist = MAX_INT;

    wp = arg0->waypoint;

    x = x >> 6;
    z = z >> 6;
    y = y >> 6;

    for (i = 0; i < arg0->length; i++) {
        dist = ABS(x - wp->x) + ABS(z - wp->z) + ABS(y - wp->y);
        if (dist < max_dist) {
            res = i;        // closest waypoint number
            max_dist = dist;
        }
        wp++;
    }
    return res;
}

void func_80319C38_72B2E8(u8 arg0, u8 arg1, u8 arg2, u8 *arg3, u8 *arg4, u8 arg5) {
    struct063 *tmp;
    u8 i;

    i = 0;

    *arg4 = 0;
    tmp = &D_803E93B0;

    while ((tmp->unk2 != 245) && (*arg4 < 4)) {
        if ((arg0 >= tmp->unk0) &&
            (tmp->unk3 >= arg0) &&
            (arg1 >= tmp->unk1) &&
            (tmp->unk4 >= arg1)) {
            switch (tmp->unk2) {
            case 240:
                *arg3 = i;
                *arg4 += 1;
                arg3 += 1;
                break;
            case 241:
                if (arg5 == 2) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            case 242:
                if (arg5 == 1) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            case 243:
                if ((arg5 == 2) || (arg5 == 0)) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            case 244:
                if ((arg5 == 1) || (arg5 == 0)) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            default:
                if ((arg2 >= tmp->unk2) &&
                    (tmp->unk5 >= arg2)) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            }
        }
        i++;
        tmp++;
    }
}

u8 func_80319E1C_72B4CC(u8 arg0, u8 arg1, u8 arg2, u8 idx, u8 arg4) {
    struct063 *tmp;
    u8 ret;

    ret = 0;
    tmp = &D_803E93B0[idx];

    if ((arg0 >= tmp->unk0) &&
        (tmp->unk3 >= arg0) &&
        (arg1 >= tmp->unk1) &&
        (tmp->unk4 >= arg1)) {

        switch (tmp->unk2) {
        case 240:
            ret = 1;
            break;
        case 241:
            if (arg4 == 2) {
                ret = 1;
            }
            break;
        case 242:
            if (arg4 == 1) {
                ret = 1;
            }
            break;
        case 243:
            if ((arg4 == 2) || (arg4 == 0)) {
                ret = 1;
            }
            break;
        case 244:
            if ((arg4 == 1) || (arg4 == 0)) {
                ret = 1;
            }
            break;
        default:
            if ((arg2 >= tmp->unk2) && (tmp->unk5 >= arg2)) {
                ret = 1;
            }
            break;
        }
    } else {
        ret = 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319F58_72B608.s")

void func_8031A150_72B800(s16 arg0, u16 *arg1, u16 *arg2) {
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_v0;
    s32 temp_v0_2;

    *arg1 = 0;
    *arg2 = 0;
    if ((arg0 & 0x3F) >= 0x3A) {
        *arg1 = 5;
        *arg2 = 5;
    }
    if (((arg0 & 0x4FF) >= 0x46A) || ((arg0 & 0xFFF) >= 0xE0C)) {
        *arg1 = 7;
        *arg2 = 7;
    }
    temp_v0 = arg0 & 0x2FF; // 767
    temp_v1 = temp_v0 - 737;
    if (temp_v0 > 737) {
        if (temp_v1 < 7) {
            *arg1 = 1;
            *arg2 = 0;
        } else if (temp_v1 < 14) {
            *arg1 = 0;
            *arg2 = 1;
        } else if (temp_v1 < 21) {
            *arg1 = 2;
            *arg2 = 0;
        } else {
            *arg1 = 0;
            *arg2 = 2;
        }
    }
    temp_v0_2 = arg0 & 0x3FF;
    temp_v1_2 = temp_v0_2 - 960;
    if (temp_v0_2 > 960) {
        if ((temp_v1_2 > 10) && (temp_v1_2 < 25)) {
            *arg1 = 3;
            *arg2 = 3;
        } else if ((temp_v1_2 > 40) && (temp_v1_2 < 55)) {
            *arg1 = 4;
            *arg2 = 4;
        } else {
            *arg1 = 0;
            *arg2 = 0;
        }
    }
}

// yucky switch
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A278_72B928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A370_72BA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A4E0_72BB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031AA0C_72C0BC.s")

// huh?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031AE7C_72C52C.s")
