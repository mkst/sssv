#include <ultra64.h>
#include "common.h"

u16 D_803A5750_7B6E00 = 0;

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
    tmp = &D_803E93B0[0];

    while ((tmp->unk2 != 245) && (*arg4 < 4)) {
        if ((arg0 >= tmp->unk0) && (tmp->unk3 >= arg0) &&
            (arg1 >= tmp->unk1) && (tmp->unk4 >= arg1)) {
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

    if ((arg0 >= tmp->unk0) && (tmp->unk3 >= arg0) &&
        (arg1 >= tmp->unk1) && (tmp->unk4 >= arg1)) {

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

u16 func_80319F58_72B608(struct105 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s8 *arg5, s8 *arg6) {
    u16 ret;
    struct105 *phi_t0;

    ret = 0;
    phi_t0 = arg0;

    while (phi_t0->unk2 != 245) {
        if ((arg1 >= phi_t0->unk0) && (phi_t0->unk3 >= arg1) &&
            (arg2 >= phi_t0->unk1) && (phi_t0->unk4 >= arg2)) {
            switch (phi_t0->unk2) {
            case 240:
                *arg5 = phi_t0->unk6;
                *arg6 = phi_t0->unk7;
                return ret;
            case 241:
                if (arg4 == 2) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            case 242:
                if (arg4 == 1) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            case 243:
                if ((arg4 == 2) || (arg4 == 0)) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            case 244:
                if ((arg4 == 1) || (arg4 == 0)) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            default:
                if ((arg3 >= phi_t0->unk2) &&
                    (phi_t0->unk5 >= arg3)) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            }
        }
        phi_t0++;
        ret++;
    }

    *arg5 = phi_t0->unk6;
    *arg6 = phi_t0->unk7;
    return 0xFFFF;
}
