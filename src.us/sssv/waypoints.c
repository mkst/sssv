#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

u16 gWaypointPathCount = 0;

// ========================================================
// .bss
// ========================================================

WaypointData *gWaypointPaths[64];
u8   gWaypointPathBuffer[1100];
LevelRegion gLevelRegions[65];
s64  gLevelRegionCollisionMasks[65];

// ========================================================
// .text
// ========================================================

// ESA: func_8004C944
void build_level_region_collision_masks(void) {
    s16 maxTileZ;
    s16 minTileZ;
    s16 maxTileX;
    s16 minTileX;

    s16 k;
    s16 j;
    s16 i; 

    for (i = 0; i < 65; i++){
        gLevelRegionCollisionMasks[i] = 0;
    }

    for (i = 0; gLevelRegions[i].unk2 != WAYPOINT_END; i++) {
        minTileX = gLevelRegions[i].minTileX;
        maxTileX = gLevelRegions[i].maxTileX;
        minTileZ = gLevelRegions[i].minTileZ;
        maxTileZ = gLevelRegions[i].maxTileZ;

        for (j = minTileX; j <= maxTileX; j++) {
            for (k = minTileZ; k <= maxTileZ; k++) {
                gLevelRegionCollisionMasks[i] |= (s64)1 << (s16)((j >> 4) + ((k >> 4) * 5));
            }
        }
    }
}

void reset_waypoints(void) {
    bzero_sssv((u8*)gWaypointPathBuffer, sizeof(gWaypointPathBuffer)); // raw waypoint data
    bzero_sssv((u8*)gWaypointPaths, sizeof(gWaypointPaths)); // pointers to waypoints
    gLevelRegions[0].unk5 = gLevelRegions[0].unk2 = WAYPOINT_END;
    gWaypointPathCount = 0;
}

// ESA: func_8004CAEC
void func_80319AA0_72B150(struct002 *arg0, u8 arg1) {
    arg0->unk1[arg0->length] = arg1;
    arg0->unk1[4] = arg1;
    arg0->length += 1;
}

// ESA: func_8004CB10
void func_80319AC4_72B174(struct002 *arg0, u8 arg1) {
    s8 i;

    for (i = 0; i < arg0->length; i++) {
        if (arg1 == arg0->unk1[i]) {
            break;
        }
    }
    arg0->length--;

    for (; i < arg0->length; i++) {
        arg0->unk1[i] = arg0->unk1[i+1];
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

// ESA: func_8004CCCC
void get_level_regions_at_point(u8 arg0, u8 arg1, u8 arg2, u8 *arg3, u8 *arg4, u8 unk160) {
    LevelRegion *tmp;
    u8 i;

    *arg4 = 0;

    i = 0;
    tmp = &gLevelRegions[i];

    while ((tmp->unk2 != WAYPOINT_END) && (*arg4 < 4)) {
        if ((arg0 >= tmp->minTileX) && (tmp->maxTileX >= arg0) &&
            (arg1 >= tmp->minTileZ) && (tmp->maxTileZ >= arg1)) {
            switch (tmp->unk2) {
            case 240: // WAYPOINT_REGION_ALL_MODES
                *arg3 = i;
                *arg4 += 1;
                arg3 += 1;
                break;
            case 241: // WAYPOINT_REGION_MODE_2_ONLY
                if (unk160 == 2) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            case 242: // WAYPOINT_REGION_MODE_1_ONLY
                if (unk160 == 1) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            case 243: // WAYPOINT_REGION_MODE_0_OR_2
                if ((unk160 == 2) || (unk160 == 0)) {
                    *arg3 = i;
                    *arg4 += 1;
                    arg3 += 1;
                }
                break;
            case 244: // WAYPOINT_REGION_MODE_0_OR_1
                if ((unk160 == 1) || (unk160 == 0)) {
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

// ESA: func_8004CE44
u8 point_matches_level_region(u8 arg0, u8 arg1, u8 arg2, u8 idx, u8 unk160) {
    LevelRegion *tmp;
    u8 ret;

    ret = 0;
    tmp = &gLevelRegions[idx];

    if ((arg0 >= tmp->minTileX) && (tmp->maxTileX >= arg0) &&
        (arg1 >= tmp->minTileZ) && (tmp->maxTileZ >= arg1)) {

        switch (tmp->unk2) {
        case 240:
            ret = 1;
            break;
        case 241:
            if (unk160 == 2) {
                ret = 1;
            }
            break;
        case 242:
            if (unk160 == 1) {
                ret = 1;
            }
            break;
        case 243:
            if ((unk160 == 2) || (unk160 == 0)) {
                ret = 1;
            }
            break;
        case 244:
            if ((unk160 == 1) || (unk160 == 0)) {
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

// ESA: func_8004CF6C
u16 func_80319F58_72B608(struct105 *arg0, u8 arg1, u8 arg2, u8 arg3, u8 unk160, u8 *arg5, u8 *arg6) {
    u16 ret;
    struct105 *phi_t0;

    ret = 0;
    phi_t0 = arg0;

    while (phi_t0->unk2 != WAYPOINT_END) {
        if ((arg1 >= phi_t0->unk0) && (phi_t0->unk3 >= arg1) &&
            (arg2 >= phi_t0->unk1) && (phi_t0->unk4 >= arg2)) {
            switch (phi_t0->unk2) {
            case 240:
                *arg5 = phi_t0->unk6;
                *arg6 = phi_t0->unk7;
                return ret;
            case 241:
                if (unk160 == 2) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            case 242:
                if (unk160 == 1) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            case 243:
                if ((unk160 == 2) || (unk160 == 0)) {
                    *arg5 = phi_t0->unk6;
                    *arg6 = phi_t0->unk7;
                    return ret;
                }
                break;
            case 244:
                if ((unk160 == 1) || (unk160 == 0)) {
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
