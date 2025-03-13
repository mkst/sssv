#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

#pragma intrinsic sqrtf

// ========================================================
// .bss
// ========================================================

static s32  D_803E1BE0;
static struct085  D_803E1BE8[10];

static s32  D_803E1CD8; // unused
static s32  D_803E1CDC; // unused

// -- bss split ? -- //

static Fog  D_803E1CE0;
static Fog  D_803E1CE8;
static Fog  D_803E1CF0;
Fog  D_803E1CF8;
static u16  D_803E1D00;
static u16  D_803E1D02;
static u8   D_803E1D04;
static s16  D_803E1D06;
static s16  D_803E1D08;
static s16  D_803E1D0A;
static s16  D_803E1D0C;
static struct063 D_803E1D10;
static struct063 D_803E1D18;
static struct063 D_803E1D20;
static u16  D_803E1D28;
static u16  D_803E1D2A;
static u8   D_803E1D2C;

struct064 D_803E1D30[256]; // additional layer for level data

// ========================================================
// .text
// ========================================================

// ESA: func_8004E918
void func_802F5C60_707310(Animal *arg0) {

    s64 x;

    s64 temp_ret_3;
    s64 temp_ret_6;

    s64 temp_t3;
    s64 temp_t1;
    s64 temp_t6;
    s64 temp_t4;

    s16 i;
    struct043 *var_s1;

    if (arg0->unk16C->unk15 != 1) {
        arg0->unkC4[0].pos.xPos.w = arg0->unk74[0].pos.xPos.w;
        arg0->unkC4[0].pos.zPos.w = arg0->unk74[0].pos.zPos.w;
        arg0->unkC4[0].pos.yPos.w = arg0->unk74[0].pos.yPos.w;
        arg0->unkC4[0].unkC = arg0->unk74[0].unkC;
        return;
    }

    if (arg0->unk16C->unk15 == 1) {
        temp_t3 = D_80152350.unk2D0[arg0->zRotation];
        temp_t6 = D_80152350.unk384[arg0->zRotation];

        temp_t1 = D_80152350.unk2D0[arg0->yRotation];
        temp_t4 = D_80152350.unk384[arg0->yRotation];

        i = 0;
        var_s1 = &arg0->unk74;

        while ((i < 5) && (var_s1->unkC != 0)) {
            x = var_s1->pos.xPos.w;

            temp_ret_3 = ((var_s1->pos.zPos.w * temp_t6) - (var_s1->pos.yPos.w * temp_t3)) >> 8;
            temp_ret_6 = ((var_s1->pos.zPos.w * temp_t3) + (var_s1->pos.yPos.w * temp_t6)) >> 8;

            arg0->unkC4[i].pos.xPos.w = (( x * temp_t4) + (temp_ret_3 * temp_t1)) >> 8;
            arg0->unkC4[i].pos.zPos.w = ((-x * temp_t1) + (temp_ret_3 * temp_t4)) >> 8;
            arg0->unkC4[i].pos.yPos.w = (arg0->unk42 << 0xF) + temp_ret_6;
            arg0->unkC4[i].unkC = var_s1->unkC;

            i++;
            var_s1++;
        }

        while (i < 5) {
            // clear others
            arg0->unkC4[i++].unkC = 0;
        }
    }
}

// ESA: func_8004EE24
void func_802F5F44_7075F4(s16 x, s16 y, s16 z, s16 yRotation, s16 zRotation, struct077 *res) {
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t3;
    s16 temp_v0;
    s32 temp_t7;

    temp_v0 = D_80152350.unk2D0[yRotation];
    temp_t0 = D_80152350.unk384[yRotation];

    temp_t1 = D_80152350.unk2D0[zRotation];
    temp_t3 = D_80152350.unk384[zRotation];

    temp_t7 = ((y * temp_t0) - (z * temp_v0)) >> 8;

    res->unk0 = (( x * temp_t3) + (temp_t7 * temp_t1)) >> 8;
    res->unk2 = ((-x * temp_t1) + (temp_t7 * temp_t3)) >> 8;
    res->unk4 = ((y * temp_v0) + (z * temp_t0)) >> 8;
}

// ESA: func_8004EF24
void func_802F603C_7076EC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u16 arg5, struct077 *res) {
    s64 pad;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    s64 sp50;
    s64 sp48;
    s64 sp40;
    s64 sp38;
    s64 sp30;

    sp38 = D_80152350.unk2D0[arg3];
    sp48 = D_80152350.unk384[arg3];

    sp30 = D_80152350.unk2D0[arg4];
    sp40 = D_80152350.unk384[arg4];

    sp60 = (arg0 * (s64)arg5) >> 0xB;
    sp58 = (arg1 * (s64)arg5) >> 0xB;
    sp50 = (arg2 * (s64)arg5) >> 0xB;

    sp70 = ((sp58 * sp48) - (sp50 * sp38)) >> 8;
    sp68 = ((sp58 * sp38) + (sp50 * sp48)) >> 8;
    res->unk0 = (( sp60 * sp40) + (sp70 * sp30)) >> 8;
    res->unk2 = ((-sp60 * sp30) + (sp70 * sp40)) >> 8;
    res->unk4 = sp68;
}

// ESA: func_8004F3C0
struct071 *func_802F62E4_707994(s16 x, s16 z, s16 y, u8 id, s16 arg4, s16 arg5, s16 arg6, s16 vAngle, s16 rotation, s16 arg9, s32 scale) {
    struct071 *obj;
    struct077 sp3C;
    struct077 sp34;

    func_802F5F44_7075F4(arg4,      arg5, arg6, vAngle, rotation, &sp3C);
    func_802F5F44_7075F4(0,    arg9 << 8,    0, vAngle, rotation, &sp34);
    obj = spawn_object(
        id,
        x + sp3C.unk0,
        z + sp3C.unk2,
        y + sp3C.unk4,
        sp34.unk0 << 8, // xVel
        sp34.unk2 << 8, // zVel
        sp34.unk4 << 8, // yVel
        vAngle,
        rotation,
        scale);

    if (obj == NULL) {
        return NULL;
    }
    obj->zRotation = vAngle;
    return obj;
}

// ESA: func_8004F6EC
s16 func_802F63F8_707AA8(s16 arg0, s16 arg1, s16 arg2) {
    s16 diff;

    diff = arg1 - arg0;
    if (diff < 0) {
        diff += 360;
    }
    if (diff == 0) {
        return 0;
    }
    if (diff >= 180) {
        if ((diff + arg2) >= 360) {
            return 360 - diff;
        }
        return arg2;
    }
    if ((diff - arg2) < 0) {
        return -diff;
    }
    return -arg2;
}

// ESA: func_8004F780
s16 func_802F649C_707B4C(s16 arg0, s16 arg1, s16 arg2) {
    s16 diff;

    diff = arg1 - arg0;
    if (diff < 0) {
        diff += 360;
    }

    if (diff != 0) {
        if (diff >= 180) {
            if ((diff + arg2) >= 360) {
                arg1 = (arg1 - (diff - 360));
            } else {
                arg1 = (arg1 + arg2);
            }
            if (arg1 >= 360) {
                arg1 = (arg1 - 360);
            }
        } else {
            if ((diff - arg2) < 0) {
                arg1 = (arg1 - diff);
            } else {
                arg1 = (arg1 - arg2);
            }
            if (arg1 < 0) {
                arg1 = (arg1 + 360);
            }
        }
    }
    return arg1;
}

// ESA: func_8004F828
void func_802F657C_707C2C(Animal *arg0, s16 targetXPos, s16 targetZPos, s16 targetYPos, s16 speed) {
    arg0->waypointTargetXPos = targetXPos;
    arg0->waypointTargetZPos = targetZPos;
    arg0->waypointTargetYPos = targetYPos;
    arg0->waypointFudgeFactor = speed;
    arg0->waypointStartXPos = arg0->position.xPos.h;
    arg0->waypointStartZPos = arg0->position.zPos.h;
    arg0->waypointStartYPos = arg0->position.yPos.h;
    arg0->waypointVelocity = 0;
}

// ESA: func_8004F85C
void func_802F65BC_707C6C(Animal *arg0) {
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t8;

    s32 phi_t2;

    s32 xVel, zVel, yVel;

    if (arg0->waypointVelocity >= 256) {
        arg0->unk170 = 0;
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if ((arg0->unk4C.unk1D == 0)) {
            arg0->yVelocity.w = 0;
        }
    } else if (arg0->state == 0) {
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if ((arg0->unk4C.unk1D == 0)) {
            arg0->yVelocity.w = 0;
        }
    } else {

        arg0->waypointVelocity += arg0->waypointFudgeFactor;

        temp_t6 = (arg0->waypointTargetXPos - arg0->waypointStartXPos) >> 1;
        temp_t8 = (arg0->waypointTargetZPos - arg0->waypointStartZPos) >> 1;
        temp_t5 = (arg0->waypointTargetYPos - arg0->waypointStartYPos) >> 1;

        if (arg0->waypointVelocity >= 256) {
            phi_t2 = FTOFIX32(-0.5);
        } else if (arg0->waypointVelocity == 0) {
            phi_t2 = FTOFIX32(0.5);
        } else {
            phi_t2 = COS(arg0->waypointVelocity >> 1);
        }

        if (((arg0->waypointVelocity) & 1)) { // odd?
            phi_t2 = (phi_t2 + COS( (arg0->waypointVelocity >> 1) + 1)) >> 1;
        }

        xVel = ((arg0->waypointStartXPos + temp_t6) << 16) - (temp_t6 * 2 * phi_t2);
        zVel = ((arg0->waypointStartZPos + temp_t8) << 16) - (temp_t8 * 2 * phi_t2);
        yVel = ((arg0->waypointStartYPos + temp_t5) << 16) - (temp_t5 * 2 * phi_t2);

        arg0->xVelocity.w = xVel - arg0->position.xPos.w;
        arg0->zVelocity.w = zVel - arg0->position.zPos.w;

        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = yVel - arg0->position.yPos.w;
        }
    }
}

// ESA: func_8004FA08
void func_802F6750_707E00(Animal *arg0) {
    s32 temp_a2;
    s32 temp_t1;
    s32 temp_v0_2;

    s32 xVel;
    s32 zVel;
    s32 yVel;

    if (arg0->waypointVelocity >= 256) {
        arg0->unk170 = 0;
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = 0;
        }
    } else if (arg0->state == 0) {
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = 0;
        }
    } else {
        arg0->waypointVelocity += arg0->waypointFudgeFactor;
        if (arg0->waypointVelocity > 256) {
            arg0->waypointVelocity = 256;
        }

        temp_v0_2 = arg0->waypointTargetXPos - arg0->waypointStartXPos;
        temp_a2 = arg0->waypointTargetZPos - arg0->waypointStartZPos;
        temp_t1 = arg0->waypointTargetYPos - arg0->waypointStartYPos;

        if (temp_v0_2 == 0) {
            xVel = arg0->waypointTargetXPos << 16;
        } else {
            xVel = (arg0->waypointStartXPos << 16) + ((temp_v0_2 * arg0->waypointVelocity) << 8);
        }
        if (temp_a2 == 0) {
            zVel = arg0->waypointTargetZPos << 16;
        } else {
            zVel = (arg0->waypointStartZPos << 16) + ((temp_a2 * arg0->waypointVelocity) << 8);
        }
        if (temp_t1 == 0) {
            yVel = arg0->waypointTargetYPos << 16;
        } else {
            yVel = (arg0->waypointStartYPos << 16) + ((temp_t1 * arg0->waypointVelocity) << 8);
        }
        arg0->xVelocity.w = xVel - arg0->position.xPos.w;
        arg0->zVelocity.w = zVel - arg0->position.zPos.w;
        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = yVel - arg0->position.yPos.w;
        }
    }
}

// ESA: func_8004FB78
void head_towards_waypoint(Animal *arg0) {
    s32 x, z, y;

    if ((arg0->position.xPos.h == arg0->waypointTargetXPos) &&
        (arg0->position.zPos.h == arg0->waypointTargetZPos) &&
        ((arg0->unk4C.unk1D != 0) || (arg0->position.yPos.h == arg0->waypointTargetYPos))) {
        arg0->unk170 = 0;
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = 0;
        }
    } else if (arg0->state == 0) {
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = 0;
        }
    } else {
        if (arg0->position.xPos.h < arg0->waypointTargetXPos) {
            x = arg0->position.xPos.h + arg0->waypointFudgeFactor;
            if (arg0->waypointTargetXPos < x) {
                x = arg0->waypointTargetXPos;
            }
        } else if (arg0->waypointTargetXPos < arg0->position.xPos.h) {
            x = arg0->position.xPos.h - arg0->waypointFudgeFactor;
            if (x < arg0->waypointTargetXPos) {
                x = arg0->waypointTargetXPos;
            }
        } else {
            x = arg0->position.xPos.h;
        }

        if (arg0->position.zPos.h < arg0->waypointTargetZPos) {
            z = arg0->position.zPos.h + arg0->waypointFudgeFactor;
            if (arg0->waypointTargetZPos < z) {
                z = arg0->waypointTargetZPos;
            }
        } else if (arg0->waypointTargetZPos < arg0->position.zPos.h) {
            z = arg0->position.zPos.h - arg0->waypointFudgeFactor;
            if (z < arg0->waypointTargetZPos) {
                z = arg0->waypointTargetZPos;
            }
        } else {
            z = arg0->position.zPos.h;
        }

        if (arg0->position.yPos.h < arg0->waypointTargetYPos) {
            y = arg0->position.yPos.h + arg0->waypointFudgeFactor;
            if (arg0->waypointTargetYPos < y) {
                y = arg0->waypointTargetYPos;
            }
        } else if (arg0->waypointTargetYPos < arg0->position.yPos.h) {
            y = arg0->position.yPos.h - arg0->waypointFudgeFactor;
            if (y < arg0->waypointTargetYPos) {
                y = arg0->waypointTargetYPos;
            }
        } else {
            y = arg0->position.yPos.h;
        }

        arg0->xVelocity.w = (x << 16) - arg0->position.xPos.w;
        arg0->zVelocity.w = (z << 16) - arg0->position.zPos.w;
        if (arg0->unk4C.unk1D == 0) {
            arg0->yVelocity.w = (y << 16) - arg0->position.yPos.w;
        }
    }
}

// ESA: func_8004FD48
void func_802F6A5C_70810C(Animal *arg0) {
    s16 phi_a2;
    s16 phi_v0_4;

    f32 sqrt;
    f32 phi_f14;
    f32 phi_f2;
    f32 phi_f16;

    if ((arg0->state != 30) && (arg0->state != 31)) {
        if ((arg0->unk161 == 1) && (arg0->unk6C != NULL)) {
            phi_f14 = (f32) (arg0->xVelocity.w - arg0->unk6C->xVelocity.w) / arg0->unk30;
            phi_f2 = (f32) (arg0->zVelocity.w - arg0->unk6C->zVelocity.w) / arg0->unk30;
        } else {
            phi_f14 = (f32) arg0->xVelocity.w / arg0->unk30;
            phi_f2 = (f32) arg0->zVelocity.w / arg0->unk30;
        }

        // why are we doing this twice?
        sqrt = sqrtf(SQ(phi_f14) + SQ(phi_f2));

        if (sqrtf(SQ(phi_f14) + SQ(phi_f2)) == 0.0) {
            phi_f16 = 0.0f;
        } else {
            phi_f16 = func_801286B8(-phi_f2, phi_f14) + 90.0;
            if (360.0 < phi_f16) {
                phi_f16 -= 360.0;
            }
        }
        if (500.0 < sqrt) {
            phi_v0_4 = (s16) phi_f16 - arg0->yRotation;
            while (phi_v0_4 < -90) {
                phi_v0_4 += 180;
            }
            while (phi_v0_4 > 90) {
                phi_v0_4 -= 180;
            }

            phi_a2 = MIN(10.0, sqrt / 500.0);
            if (phi_a2 >= ABS(phi_v0_4)) {
                arg0->yRotation += phi_v0_4;
            } else if (phi_v0_4 < 0) {
                arg0->yRotation -= phi_a2;
            } else {
                arg0->yRotation += phi_a2;
            }
        }
        phi_v0_4 = arg0->yRotation - (s16) phi_f16;
        while (phi_v0_4 < -180) {
            phi_v0_4 += 360;
        }
        while (phi_v0_4 > 180) {
            phi_v0_4 -= 360;
        }
        if (ABS(phi_v0_4) < 90) {
            arg0->zRotation -= (s16) (sqrt * (1 / 1143.7852444444445)); // ???
        } else {
            arg0->zRotation += (s16) (sqrt * (1 / 1143.7852444444445)); // ???
        }

        while (arg0->zRotation >= 360) {
            arg0->zRotation -= 360;
        }
        while (arg0->zRotation < 0) {
            arg0->zRotation += 360;
        }

        while (arg0->yRotation >= 360) {
            arg0->yRotation -= 360;
        }
        while (arg0->yRotation < 0) {
            arg0->yRotation += 360;
        }
    }
}

// ESA: func_80050148
void func_802F6DEC_70849C(Animal *arg0, s16 arg1) {
    struct077 sp68;
    s16 temp_f4;
    s32 y;
    s32 z;
    s32 x;

    func_802F5F44_7075F4(
        0,
        arg1 << 8,
        0,
        arg0->zRotation,
        arg0->yRotation,
        &sp68);

    x = (sp68.unk0 << 8) - arg0->xVelocity.w;
    z = (sp68.unk2 << 8) - arg0->zVelocity.w;
    y = (sp68.unk4 << 8) - arg0->yVelocity.w;

    temp_f4 = sqrtf(SQ((s64)x) + SQ((s64)z) + SQ((s64)y));
    if (temp_f4 < FTOFIX32(5.0)) {
        arg0->xVelocity.w += x;
        arg0->zVelocity.w += z;
        arg0->yVelocity.w += y;
    } else {
        arg0->xVelocity.w += (x * FTOFIX32(5.0)) / temp_f4;
        arg0->zVelocity.w += (z * FTOFIX32(5.0)) / temp_f4;
        arg0->yVelocity.w += (y * FTOFIX32(5.0)) / temp_f4;
    }
}

// ESA: func_800502E8
void func_802F7054_708704(s32 arg0) {
}

// not in ESA?
void func_802F705C_70870C(Animal *arg0, s16 zRotation, s16 yRotation, s16 height, s16 arg4, s16 arg5, s16 arg6, u16 flags) {
    Animal *a;

    s16 sp13A;
    s16 sp138;

    s32 pad[10];

    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f12_2;
    f32 temp_f14_2;
    f32 temp_f16_2;
    f32 var_f20;
    f32 var_f22;
    f32 var_f28;
    f32 var_f2;
    f32 var_f30;

    Vertex spD4;
    Vertex spC8;
    Vertex *var_s1;
    f32 spC0;

    CollisionNode *var_s3;

    s16 var_t0;
    s16 var_t1;
    s16 var_t2;
    s16 var_t3;
    s16 temp_s7;
    s16 xPos;
    s16 zPos;

    if (arg4 != 0) {

        if (flags & 0x200) {
            spC0 = ((f32)arg4 / 2048);
            spC0 = -spC0;
        } else if (flags & 0x100) {
            spC0 = (f32)arg4 / 2048;
        } else {
            spC0 = 0.0f;
        }

        if (flags & 0x200) {
            var_f30 = ((f32)arg4 / 2048);
            var_f30 = -var_f30;
        } else if (flags & 0x100) {
            var_f30 = (f32)arg4 / 2048;
        } else {
            var_f30 = 0.0f;
        }

        if (arg6 == 0) {
            var_f28 = ((f32)arg4 / 2048) * 64;
        } else {
            var_f28 = arg6;
        }

        xPos = arg0->position.xPos.h >> 0xA;
        zPos = arg0->position.zPos.h >> 0xA;

        var_t0 = var_t2 = -(var_f28 / (1.0f * 1024.0f));
        var_t1 = var_t3 =  (var_f28 / (1.0f * 1024.0f));

        if ((xPos + 1) >= 5) {
            var_t1--;
        }
        if (xPos < 1) {
            var_t0++;
        }
        if ((zPos + 1) >= 8) {
            var_t3--;
        }
        if (zPos < 1) {
            var_t2++;
        }

        spD4.y = (f32)D_80152350.unk384[zRotation] / 256;
        spD4.z = (f32)D_80152350.unk2D0[zRotation] / 256;

        spD4.x = (f32)D_80152350.unk2D0[yRotation] * spD4.y / 256;
        spD4.y = (f32)D_80152350.unk384[yRotation] * spD4.y / 256;

        for (sp13A = (xPos + var_t0); sp13A <= (xPos + var_t1); sp13A++) {
            for (sp138 = (zPos + var_t2); sp138 <= (zPos + var_t3); sp138++) {

                temp_s7 = sp13A + (sp138 * 5);

                for (var_s3 = D_803DA110[temp_s7].next; var_s3 != NULL; var_s3 = var_s3->next) {
                    a = var_s3->animal;
                    if (a != arg0) {
                        if ((a->unk4C.unk1B) && (a->unk4C.unk1C) && (temp_s7 == a->unk114[0])) {
                            temp_f12 = a->position.xPos.h - arg0->position.xPos.h;
                            temp_f14 = a->position.zPos.h - arg0->position.zPos.h;
                            temp_f16 = a->position.yPos.h - arg0->position.yPos.h - height;

                            temp_f0 = sqrtf(SQ(temp_f12) + SQ(temp_f14) + SQ(temp_f16));

                            if (!(temp_f0 > var_f28) && (temp_f0 != 0.0f)) {
                                spC8.x = temp_f12 / temp_f0;
                                spC8.y = temp_f14 / temp_f0;
                                spC8.z = temp_f16 / temp_f0;

                                if ((flags & 8) == 0) {
                                    var_f22 = temp_f0;
                                    var_s1 = &spC8;
                                    var_f2 = (f32) D_80152350.unk384[(s16)(arg5 >> 1)] / 256;
                                } else {
                                    var_f2 = (temp_f12 * spD4.x) + (temp_f14 * spD4.y) + (temp_f16 * spD4.z);
                                    if ((var_f28 < var_f2) || (var_f2 <= 0.0f)) {
                                        continue;
                                    }

                                    var_f22 = var_f2;
                                    var_s1 = &spD4;

                                    temp_f12_2 = (arg0->position.xPos.h + (var_f22 * spD4.x)) - a->position.xPos.h;
                                    temp_f14_2 = (arg0->position.zPos.h + (var_f22 * spD4.y)) - a->position.zPos.h;
                                    temp_f16_2 = (arg0->position.yPos.h + (var_f22 * spD4.z) + height) - a->position.yPos.h;
                                    temp_f0 = sqrtf(SQ(temp_f12_2) + SQ(temp_f14_2) + SQ(temp_f16_2));

                                    if (arg5 < temp_f0) {
                                        continue;
                                    }

                                    var_f2 = 0.0f;
                                }

                                if ((((flags & (0x200|0x100)) && (var_f2 <= ((spC8.x * spD4.x) + (spC8.y * spD4.y) + (spC8.z * spD4.z))) && (var_f20 = spC0, (var_f20 != 0.0f))) ||
                                    ((flags & 3) && (((spC8.x * spD4.x) + (spC8.y * spD4.y) + (spC8.z * spD4.z)) <= -var_f2) && (var_f20 = var_f30, (var_f20 != 0.0f))))) {

                                    if ((flags & 4) && ((func_8033C9CC_74E07C(a->position.xPos.h, a->position.zPos.h, a->position.yPos.h, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + height, 0, 0, 0) != 0))) {
                                        continue;
                                    }

                                    temp_f0 = ((var_f20 / (1.0f * 4.0f)) * (var_f28 - var_f22)) / var_f28;
                                    if (a->unk44 != 0) {
                                        temp_f0 = (temp_f0 * 100.0f) / a->unk44;
                                    }
                                    if (((var_s1->x > 0.0f) && ((a->xVelocity.w < (var_f20 * 65536.0f)))) ||
                                        ((var_s1->x < 0.0f) && ((-(var_f20 * 65536.0f) < a->xVelocity.w)))) {
                                        a->xVelocity.w += temp_f0 * var_s1->x * 65536.0f;
                                    }
                                    if (((var_s1->y > 0.0f) && ((a->zVelocity.w < (var_f20 * 65536.0f)))) ||
                                        ((var_s1->y < 0.0f) && ((-(var_f20 * 65536.0f) < a->zVelocity.w)))) {
                                        a->zVelocity.w += temp_f0 * var_s1->y * 65536.0f;
                                    }
                                    if (((var_s1->z > 0.0f) && ((a->yVelocity.w < (var_f20 * 65536.0f)))) ||
                                        ((var_s1->z < 0.0f) && ((-(var_f20 * 65536.0f) < a->yVelocity.w)))) {
                                        a->yVelocity.w += temp_f0 * var_s1->z * 65536.0f;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// ESA: func_800502F0 ?
void func_802F7940_708FF0(Animal *arg0, s16 xPos, s16 zPos, s16 yPos, s16 damage, s16 minDistance, s16 maxDistance, s16 arg7) {
    s16 temp_t6;
    s16 temp_t8;
    s16 spD2;
    s16 spD0;
    Animal *a;
    u16 sp68;
    s16 spC8;
    s32 var_v0;
    s32 x;
    s32 y;
    s32 z;
    CollisionNode *var_s7;
    struct035 *temp_v1;
    s32 pad;
    s32 var_a0;
    s16 var_s1;
    s32 var_s3;
    s16 temp_v0_10;
    s32 temp_v1_3;
    s32 var_a2;
    s32 var_a3;
    s32 var_t0;
    s32 sp88;

    temp_t6 = xPos >> 0xA;
    temp_t8 = zPos >> 0xA;

    if (damage != 0) {
        var_t0 = -1;
        var_a3 = -1;
        spC8 = 1;
        var_a2 = 1;

        if ((temp_t6 + 1) >= 5) {
            var_a2--;
        }
        if (temp_t6 < 1) {
            var_a3++;
        }
        if ((temp_t8 + 1) >= 8) {
            spC8--;
        }
        if (temp_t8 < 1) {
            var_t0++;
        }

        // determine if owner is user's current animal?
        if ((sp88 = (arg0->owner != NULL))) {
            if ((sp88 = (arg0->owner->unk16C != NULL))) {
                if ((sp88 = (arg0->owner->unk16C->objectType >= 0x100))) {
                    sp88 = (arg0->owner == D_801D9ED8.animals[gCurrentAnimalIndex].animal);
                }
            }
        }

        for (spD2 = temp_t6 + var_a3; spD2 <= (temp_t6 + var_a2); spD2++) {

            for (spD0 = temp_t8 + var_t0; spD0 <= (temp_t8 + spC8); spD0++) {

                sp68 = (spD2 + (spD0 * 5));
                for (var_s7 = D_803DA110[sp68].next; var_s7 != NULL; var_s7 = var_s7->next) {
                    a = var_s7->animal;
                    if ((sp68 == a->unk114[0]) && (a->unk16C->objectType != OBJECT_ROCKET) &&
                        (a != arg0) && (a != arg0->owner)) {
                        x = a->position.xPos.h - xPos;
                        z = a->position.zPos.h - zPos;
                        y = (a->position.yPos.h + (a->unk42 >> 1)) - yPos;

                        if (x > 0) {
                            x = MAX(0, x - a->unk30);
                        } else {
                            x = MIN(0, a->unk30 + x);
                        }

                        if (z > 0) {
                            z = MAX(0, z - a->unk32);
                        } else {
                            z = MIN(0, a->unk32 + z);
                        }

                        if (y > 0) {
                            y = MAX(0, y - (a->unk42 >> 1));
                        } else {
                            y = MIN(0, (a->unk42 >> 1) + y);
                        }

                        var_s3 = (s16)sqrtf((SQ(x) + SQ(z) + SQ(y)));
                        if (var_s3 <= 0) {
                            var_s3 = 1;
                        }
                        var_s1 = ABS(var_s3);
                        if ((var_s1 >= maxDistance) || (minDistance >= var_s1)) {
                            continue;
                        }

                        // skip if off-screen?
                        if (func_8033C9CC_74E07C(xPos, zPos, yPos,                     arg0->unk160, a->position.xPos.h, a->position.zPos.h, a->position.yPos.h, a->unk160, 0, 0)) {
                            continue;
                        }
                        if (func_8033C9CC_74E07C(xPos, zPos, yPos + (arg0->unk42 * 2), arg0->unk160, a->position.xPos.h, a->position.zPos.h,a->position.yPos.h + a->unk42, a->unk160, 0, 0)) {
                            continue;
                        }

                        if ((a->unk16C->objectType == OBJECT_MINE) || (a->unk16C->objectType == OBJECT_77) || (a->unk16C->objectType == OBJECT_78)) {
                            temp_v0_10 = var_s1 >> 4;

                            if (temp_v0_10 < a->unk154) {
                                if (temp_v0_10 >= 2) {
                                    a->unk154 = temp_v0_10;
                                } else {
                                    a->unk154 = 2;
                                }
                            }
                        } else {

                            var_v0 = ((x * 65536) / var_s3);
                            if (damage != 0) {
                                func_802B356C_6C4C1C(a, damage, arg7, 1);
                            }

                            // is owner and is animal?
                            if (((u8)sp88 != 0) && (a->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET)) {
                                a->unk2EB++;
                            }

                            if ((a->unk4C.unk1B != 0) && (a->unk4C.unk1C != 0)) {
                                if ((a->unk44 > 0) && (a->unk44 <= 100)) {

                                    var_v0 = ((var_v0 * 4) * (100 - a->unk44)) / 100;
                                    var_a0 = ((z * 65536) / var_s3);
                                    var_a0 = ((var_a0 * 4) * (100 - a->unk44)) / 100;

                                    if ((var_v0 < 0) && (var_v0 < a->xVelocity.w)) {
                                        a->xVelocity.w += var_v0;
                                        if (a->xVelocity.w < var_v0) {
                                            a->xVelocity.w = var_v0;
                                        }
                                    } else if ((var_v0 > 0) && (a->xVelocity.w < var_v0)) {
                                        a->xVelocity.w += var_v0;
                                        if (var_v0 < a->xVelocity.w) {
                                            a->xVelocity.w = var_v0;
                                        }
                                    }

                                    if ((var_a0 < 0) && (var_a0 < a->zVelocity.w)) {
                                        a->zVelocity.w += var_a0;
                                        if (a->zVelocity.w < var_a0) {
                                            a->zVelocity.w = var_a0;
                                        }
                                    } else if ((var_a0 > 0) && (a->zVelocity.w < var_a0)) {
                                        a->zVelocity.w += var_a0;
                                        if (var_a0 < a->zVelocity.w) {
                                            a->zVelocity.w = var_a0;
                                        }
                                    }
                                }
                            }
                            a->unk54.unk4 = NULL;
                            a->unk4C.unk19 = 1;
                            a->unk54.unk0 |= 9;
                            a->unk54.unk1 = arg0->unk16C->objectType;
                            a->unk54.unk2 = 0xA;
                        }
                    }
                }
            }
        }
    }
}

// ESA: func_800509BC
s16 func_802F804C_7096FC(u8 arg0, f32 arg1, f32 arg2, f32 yDelta, f32 arg4) {
    f32 temp;
    f32 phi_f18;

    if (arg1 == 0.0f) {
        return 90;
    }
    temp = 1.0 - (((2.0f * arg4) / SQ(arg2)) * (((arg4 * SQ(arg1)) / (2.0f * SQ(arg2))) + yDelta));
    if (temp < 0.0f) {
        return 9999;
    }
    temp = sqrtf(temp);
    if (arg0 != 0) {
        phi_f18 = (SQ(arg2) / (arg4 * arg1)) * (1.0 + temp);
    } else {
        phi_f18 = (SQ(arg2) / (arg4 * arg1)) * (1.0 - temp);
    }
    // clamp -2048-2048 to +-90
    return func_8012844C(phi_f18 * 64.0f);
}

// ESA: func_80050BF0
s16 func_802F8160_709810(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, f32 arg8) {
    s32 var_v0;  // pad
    s16 var_a0;

    f32 xzDiff;
    f32 yDiff;

    s16 var_t1;
    s16 ret;       // sp4C
    s16 var_t2;    // sp4A
    s16 var_v1;    // sp48
    s16 pad;       // sp46
    u8  sp45;

    xzDiff = sqrtf(SQ((f32) arg0->position.xPos.h - arg1->position.xPos.h) + SQ((f32) arg0->position.zPos.h - arg1->position.zPos.h)) - arg2;
    if (xzDiff < 0) {
        return -1;
    }

    yDiff = (arg1->position.yPos.h - arg0->position.yPos.h) - arg3;
    if (arg7 == 3) {
        sp45 = ((yDiff > 32.0f) || (xzDiff > 256.0f) && ((func_80128200() & 3) == 1));
    } else if (arg7 == 4) {
        sp45 = 0;
    } else {
        sp45 = arg7;
    }

    var_t1 = func_802F804C_7096FC(sp45, xzDiff, arg4, yDiff, arg8);
    if (var_t1 == 9999) {
        return -1;
    }

    if (arg5 < var_t1) {
        var_t2 = ABS(var_t1 - arg5);
        var_t1 = arg5;
    } else if (var_t1 < arg6) {
        var_t2 = ABS(ABS(var_t1) - ABS(arg6));
        var_t1 = arg6;
    } else {
        if (var_t1 < 0) {
            var_t1 += 360;
        }
        return var_t1;
    }

    if ((arg7 == 4) && (xzDiff < 70.0f)) {
        if (var_t1 < 0) {
            var_t1 += 360;
        }
        return var_t1;
    }

    var_a0 = func_802F804C_7096FC(!sp45, xzDiff, arg4, yDiff, arg8);
    if (var_a0 == 9999) {
        return -1;
    }

    if (arg5 < var_a0) {
        var_v1 = ABS(var_a0 - arg5);
        var_a0 = arg5;
    } else if (var_a0 < arg6) {
        var_v1 = ABS(ABS(var_a0) - ABS(arg6));
        var_a0 = arg6;
    } else {
        if (var_a0 < 0) {
            var_a0 += 360;
        }
        return var_a0;
    }

    if ((var_t2 < var_v1) && (var_t2 < 5)) {
        ret = var_t1;
    } else if (var_v1 < 5) {
        ret = var_a0;
    } else {
        return -1;
    }

    if (ret < 0) {
        ret += 360;
    }
    return ret;
}

// ESA: func_80050EA4
u8 func_802F8658_709D08(Animal *arg0, Animal *arg1, f32 arg2, f32 arg3, struct077 *arg4) {
    f32 tmp;
    f32 sp60;
    f32 sp5C;

    Vertex sp50;
    Vertex sp44;
    Vertex sp38;

    s16 temp_v0;

    f32 var_f12;
    f32 var_f2;
    s16 sp2A;
    f32 temp_f0;


    sp44.x = (arg0->position.xPos.h - arg1->position.xPos.h);
    sp44.y = (arg0->position.zPos.h - arg1->position.zPos.h);
    sp44.z = (arg0->position.yPos.h + arg0->unk42) - (arg1->position.yPos.h + arg1->unk42);

    sp50.x = sqrtf(SQ(sp44.x) + SQ(sp44.y) + SQ(sp44.z));

    if (arg3 < sp50.x) {
        return 0;
    }

    sp38.x = arg1->xVelocity.h;
    sp38.y = arg1->zVelocity.h;
    sp38.z = arg1->yVelocity.h;

    sp60 = sqrtf(SQ(sp38.x) + SQ(sp38.y) + SQ(sp38.z)) / arg2;
    sp2A = get_angle_between_vectors(&sp44, &sp38);

    temp_v0 = func_8012835C(sinf((f32) sp2A * (M_PI / 180.0)) * sp60 * 256.0f);
    // what?
    tmp = 0;
    if (tmp > 0.0f) {
        temp_v0 = -temp_v0;
    }

    temp_f0 = (f32) (D_80152350.unk384[temp_v0] + (s16) (s32) (D_80152350.unk384[sp2A] * sp60)) / 256;

    if (temp_f0 == 0.0f) {
        return 0;
    }

    sp5C = sp50.x / temp_f0;
    temp_f0 = get_magnitude((Vertex *) &sp38);
    if (temp_f0 == 0.0f) {
        var_f2 = 0.0f;
        var_f12 = 0.0f;
    } else {
        var_f12 = sp38.x / temp_f0;
        var_f2 = sp38.y / temp_f0;
    }

    temp_f0 = sp60 * sp5C;
    arg4->unk0 = arg1->position.xPos.h + (s16)(temp_f0 * var_f12);
    arg4->unk2 = arg1->position.zPos.h + (s16)(temp_f0 * var_f2);
    arg4->unk4 = arg1->position.yPos.h + ( arg1->unk42 >> 1);
    return 1;
}

// ESA: func_80051334
s32 func_802F8918_709FC8(Animal *arg0, Animal *arg1) {
    u8 i, j;

    if (arg0->unk18C == 0) {
        return 1;
    }
    for (i = 0; i < arg0->unk18C; i++) {
        for (j = 0; j < arg1->unk192; j++) {
            if (arg0->unk18D[i] == arg1->unk193[j]) {
                return 1;
            }
        }
    }

    return 0;
}

// ESA: func_800513C0
struct071 *find_closest_animal(struct071 *arg0) {
    s16 i;
    s16 zDist;
    s16 xDist;

    s16 best_distance;
    s16 distance;

    Animal *animal;
    struct071 *ret;

    best_distance = MAX_SHORT;
    ret = NULL;

    for (i = 0; i < gNumAnimalsInLevel; i++) {
        if (D_801D9ED8.animals[i].animal != NULL) {
            if ((D_801D9ED8.animals[i].animal->unk366 != MOVEMENT_MODE_DELETED) && (D_801D9ED8.animals[i].animal->unk366 != MOVEMENT_MODE_2) && (D_801D9ED8.animals[i].animal->unk366 != MOVEMENT_MODE_DEACTIVATED)) {
                if ((D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) &&
                    (D_801D9ED8.animals[i].unk0->unk9C != EVO)) {

                    animal = D_801D9ED8.animals[i].animal;

                    xDist = ABS(arg0->position.xPos.h - animal->position.xPos.h);
                    zDist = ABS(arg0->position.zPos.h - animal->position.zPos.h);
                    distance = MAX(xDist, zDist) + (MIN(xDist, zDist) >> 1);

                    if ((distance < best_distance) && func_802F8918_709FC8(arg0, animal)) {
                        // found a new closer animal
                        best_distance = distance;
                        ret = animal;
                    }
                }
            }
        }
    }
    return ret;
}

// ESA: func_80051544
void func_802F8B4C_70A1FC(struct071 *arg0) {
    s16 pad[6];
    struct071 *obj2;
    s16 angle;
    s16 temp_t0;
    struct071 *obj;
    s32 x;
    s32 z;

    struct077 sp48; // probably a bigger struct?

    if (arg0->Info.Counter2 > 0) {
        arg0->Info.Counter2 -= 2;
    }
    if ((arg0->unk0 == 1)) {
        obj = find_closest_animal(arg0);
        if ((obj != NULL) && (func_802F8658_709D08(arg0, obj, 16.0f, 512.0f, &sp48) != 0)) {
            x = sp48.unk0 - arg0->position.xPos.h;
            z = sp48.unk2 - arg0->position.zPos.h;

            // this is not in the assembly...
            if (sqrtf((x * x) + (z * z))) {};

            angle = func_801284B8(x, z);

            temp_t0 = func_802F8160_709810(arg0, obj, 0, 0, 16, 89, -4, 4, (f32) gGravity / (512.0 * 1024));
            arg0->yRotation = ((angle + 180) % 360);
            if (temp_t0 != -1) {
                if (temp_t0 <= 90) {
                    arg0->zRotation = 90 - temp_t0;
                } else {
                    arg0->zRotation = 90;
                }
            }
            if (arg0->Info.unk14E <= 0) {
                if (arg0->Info.unk152 > 0) {
                    arg0->Info.unk152--;
                    arg0->Info.Counter2 = 256;
                    if (((arg0->Info.unk152 & 1) == 1)) {
                        play_sound_effect_at_location(SFX_UNKNOWN_74, 0x5000, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
                        obj2 = func_802F62E4_707994(
                            arg0->position.xPos.h,
                            arg0->position.zPos.h,
                            arg0->position.yPos.h + ((arg0->unk40 * 6) >> 0xB),
                            0x26,
                            0,
                            (arg0->unk40 * 40) >> 11,
                            0,
                            temp_t0,
                            angle,
                            0x10,
                            (arg0->unk40 << 0xB) >> 0xB);

                        if (obj2 != NULL) {
                            obj2->unk154 = 200;
                        }
                    }
                } else {
                    arg0->Info.unk14E = (func_80128200() & 0x1F) + (arg0->unk158 + 0x18);
                    arg0->Info.unk152 = 6;
                }
            } else {
                arg0->Info.unk14E--;
            }
        }
    }
}

// homing missile turret (object63)
// ESA: func_800517C8
void func_802F8DCC_70A47C(struct071 *arg0) {
    s32 x_dist;
    s32 z_dist;
    s32 temp_t0;
    s32 temp_t2;
    s16 yRotation;
    s16 zRotation;
    s16 pad[2];
    struct071 *target;

    if (arg0->Info.Counter2 > 0) {
        arg0->Info.Counter2 -= 2;
    }
    if (arg0->unk0 == 1) {
        target = find_closest_animal(arg0);
        if (target != NULL) {
            if (arg0->Info.unk14E > 0) {
                arg0->Info.unk14E -= 1;
            }
            x_dist = target->position.xPos.h - arg0->position.xPos.h;
            z_dist = target->position.zPos.h - arg0->position.zPos.h;
            temp_t0 = ((target->position.yPos.h - arg0->position.yPos.h) - arg0->unk42) + (target->unk42 >> 1);
            temp_t2 = (s16)sqrtf(SQ(x_dist) + SQ(z_dist));
            if (temp_t2 < 640) {
                yRotation = func_801284B8(x_dist, z_dist);
                zRotation = func_801284B8(temp_t0, temp_t2);
                if (zRotation > 180) {
                    zRotation = 0;
                } else if (zRotation > 90) {
                    zRotation = 90;
                }
                arg0->yRotation = func_802F649C_707B4C((yRotation + 180) % 360, arg0->yRotation, 6);
                arg0->zRotation = func_802F649C_707B4C(90 - zRotation         , arg0->zRotation, 6);
                if (arg0->Info.unk14E <= 0) {
                    arg0->Info.unk14E = arg0->unk158 + 250;
                    arg0->Info.Counter2 = 256;
                    play_sound_effect_at_location(SFX_UNKNOWN_74, 0x5000, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
                    func_802FED68_710418(
                        arg0,
                        target,
                        arg0->position.xPos.h,
                        arg0->position.zPos.h,
                        arg0->position.yPos.h + ((arg0->unk40 * 6) >> 11),
                        0,
                        (arg0->unk40 * 40) >> 11,
                        0,
                        zRotation,
                        yRotation,
                        0,
                        (f32)arg0->unk40 / 2048 * 0.3,
                        10);
                }
            }
        }
    }
}

// ESA: func_80051A8C
void func_802F9084_70A734(Animal * arg0) {
}

// ESA: func_80051A94
void func_802F908C_70A73C(Animal *arg0) {
    if (arg0->unk154 == 0) {
        arg0->unk154 = 100;
    }
}

// used by dead scientists
// ESA: func_80051AB0
void func_802F90A8_70A758(Animal *arg0) {
    arg0->position.xPos.w += arg0->xVelocity.w;
    arg0->position.zPos.w += arg0->zVelocity.w;
    if (!arg0->unk4C.unk1D) {
        arg0->position.yPos.w += arg0->yVelocity.w;
    }
    func_803136B0_724D60(arg0);
}

// used by object34
// ESA: func_80051B1C
void func_802F9104_70A7B4(struct071 *arg0) {
    arg0->Info.Counter2 = (arg0->Info.Counter2 + 4) & 0xFF;
    arg0->unk40 = (((COS(arg0->Info.Counter2) >> 7) * 0x66) >> 8) + 0x533;
    func_802C9BA4_6DB254(arg0);
}

// mouse radar?
// ESA: func_80051B8C
s32 func_802F9178_70A828(struct071 *arg0) {
    Animal *target;
    s16 zDist;
    s16 xDist;
    s32 phi_t0;
    s32 phi_a3;
    s16 i;

    for (i = 0; i < gNumAnimalsInLevel; i++) {
        if ((D_801D9ED8.animals[i].animal != NULL) &&
            (D_801D9ED8.animals[i].unk0->unk9C == MOUSE2)) {
            if ((D_801D9ED8.animals[i].animal->unk366 != MOVEMENT_MODE_DELETED) &&
                (D_801D9ED8.animals[i].animal->unk366 != MOVEMENT_MODE_2) &&
                (D_801D9ED8.animals[i].animal->unk366 != MOVEMENT_MODE_DEACTIVATED)) {

                target = D_801D9ED8.animals[i].animal;

                xDist = ABS(arg0->position.xPos.h - target->position.xPos.h);
                zDist = ABS(arg0->position.zPos.h - target->position.zPos.h);
                phi_a3 = MAX(xDist, zDist);
                phi_t0 = MIN(xDist, zDist);

                // found a close animal
                if ((s16) ((phi_t0 >> 1) + phi_a3) < 0x280) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// ESA: func_80051CD0
// used by missile
void func_802F92B0_70A960(struct071 *arg0) {
    s32 pad[4];
    s32 x_dist;
    s32 z_dist;
    s32 sp54;
    s32 sp50;
    s16 sp4E;
    s16 sp4C;
    s16 phi_a1;
    s16 sp48;
    u8  sp47;
    Animal *a;

    sp47 = func_802F9178_70A828(arg0);

    if (arg0->target != NULL) {
        a = arg0->target;

        x_dist = a->position.xPos.h - arg0->position.xPos.h;
        z_dist = a->position.zPos.h - arg0->position.zPos.h;

        sp54 = (a->position.yPos.h - arg0->position.yPos.h) + (a->unk42 >> 1);
        sp50 = sqrtf((x_dist * x_dist) + (z_dist * z_dist));
        sp50 = (s16)sp50;

        sp4E = func_801284B8(x_dist, z_dist);
        sp4C = func_801284B8(sp54, sp50);

        if (arg0->Info.Counter2 != 0) {
            sp48 = arg0->Info.Counter2;
        } else {
            sp48 = 7;
        }
        arg0->yRotation = func_802F649C_707B4C(sp4E, arg0->yRotation, sp48);
        arg0->zRotation = func_802F649C_707B4C(sp4C, arg0->zRotation, MAX((sp48 * 3) / 4, 1));
    }

    if (arg0->Info.unk152 != 0) {
        phi_a1 = arg0->Info.unk152;
    } else {
        phi_a1 = 18;
    }

    if (sp47 != 0) {
        arg0->yRotation += D_80152350.unk2D0[(s16) ((arg0->Info.unk14E << 4) % 360)] >> 5;
    }
    if (arg0->yRotation >= 360) {
        arg0->yRotation -= 360;
    } else if (arg0->yRotation < 0) {
        arg0->yRotation += 360;
    }

    func_802F6DEC_70849C(arg0, phi_a1);

    if (arg0->Info.unk14E++) {
        // something debug?
    }

    if (arg0->unk154 == 0) {
        arg0->unk154 = 160;
    }
    func_8032CED0_73E580(arg0, SFX_UNKNOWN_103, 0x4000, 0.4f, 0, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, arg0->unk1C.w, arg0->unk20.w, arg0->unk24.w);
}

// used by object 30
// stubbed out in ESA
void func_802F951C_70ABCC(Animal *arg0) {
    u8 red;
    u8 blue;
    u8 green;
    s16 pad[3];

    if (arg0->state == 1) {
        red = arg0->unk200[0];
        blue = arg0->unk200[1];
        green = arg0->unk200[2];
        if ((red != 0) || (blue != 0) || (green != 0)) {
            add_light_at_location(
                arg0->position.xPos.h,
                arg0->position.zPos.h,
                arg0->position.yPos.h,
                0xFF,
                red,
                blue,
                green);
            func_8029CEF0_6AE5A0(
                arg0->position.xPos.h << 16,
                arg0->position.zPos.h << 16,
                (arg0->position.yPos.h << 16) + (arg0->unk40 * 570),
                arg0->unk40 << 1,
                34,
                &D_803D2E08,
                0,
                red,
                blue,
                green);
        }
    }
}

// used by OBJECT_FLAME_TORCH
// ESA: func_80051F00
void func_802F9624_70ACD4(Animal *arg0) {
    if (arg0->state == 1) {
        arg0->unk14E++;
        arg0->unk14E &= 3;
        if (arg0->unk14E == 0) {
            create_particle_effect(
                arg0->position.xPos.h,
                arg0->position.zPos.h,
                arg0->position.yPos.h + arg0->unk42 + (arg0->unk42 / 2),
                63,
                0,
                0,
                FTOFIX32(4.0),
                (arg0->unk40 * 0x28) >> 0xB,
                GPACK_RGBA5551(0, 0, 0, 0),
                GPACK_RGBA5551(0, 0, 0, 0),
                0);
        }
    }
}

// used by OBJECT_GRAVITY_SWITCH
// esa: func_80051F98
void func_802F96E0_70AD90(struct071 *psMoveObj) {
    if (psMoveObj->Info.Counter2 == 0) {
        psMoveObj->Info.Counter2 = psMoveObj->unk40;
        psMoveObj->Info.unk152 = (func_80128200() & 0xFF);
    }

    if (psMoveObj->unk0 == 1) {
        if (psMoveObj->Info.unk14E < 256) {
            psMoveObj->Info.unk14E += 8;
            if (psMoveObj->Info.unk14E > 256) {
                psMoveObj->Info.unk14E = 256;
            }
        }
    } else {
        if (psMoveObj->Info.unk14E > 0) {
            psMoveObj->Info.unk14E -= 8;
            if (psMoveObj->Info.unk14E < 0) {
                psMoveObj->Info.unk14E = 0;
            }
        }
    }

    if (psMoveObj->Info.unk14E > 0) {
        psMoveObj->Info.unk152 += 4;
        psMoveObj->Info.unk152 &= 0xFF;
        psMoveObj->unk40 = psMoveObj->Info.Counter2 + (((COS(psMoveObj->Info.unk152 & 0xFFFF) >> 7)) / 1.5);
        func_802C9BA4_6DB254(psMoveObj);
    }
}

// used by object 45
// ESA: func_800520C4
void func_802F9880_70AF30(Animal *arg0) {
    if (arg0->state == 1) {
        if (arg0->unk150 == 0) {
            arg0->unk150 = 1;
            if (arg0->unk152 != 0) {
                play_sound_effect_at_location(SFX_UNKNOWN_82, 0x7FFF, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
            }
        }
        if (arg0->unk14E < 128) {
            arg0->unk14E += 8;
            if (arg0->unk14E >= 128) {
                arg0->unk14E = 128;
            }
        }
    } else {
        if (arg0->unk150 == 1) {
            arg0->unk150 = 0;
            if (arg0->unk152 != 0) {
                play_sound_effect_at_location(SFX_UNKNOWN_82, 0x7FFF, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 0.8f);
            }
        }
        if (arg0->unk14E > 0) {
            arg0->unk14E -= 8;
            if (arg0->unk14E < 0) {
                arg0->unk14E = 0;
            }
        }
    }
    if (arg0->unk152 == 0) {
        arg0->unk152 = 1;
    }
    arg0->unk152 = (((COS(arg0->unk14E) >> 7) * 0x2D) >> 8) + arg0->zRotation;
    arg0->unk152 %= 360;
}

// used by OBJECT_WHEEL_SWITCH
// ESA: func_80052250
void func_802F9A08_70B0B8(Animal *arg0) {
    if (arg0->state == 1) {
        if (arg0->unk14E == 0) {
            arg0->unk23C.unknown2.unk0 = 13;
            arg0->unk23C.unknown2.unk1 = 128;
            arg0->unk23C.unknown2.unk2 = 128;
            arg0->unk23C.unknown2.unk3 = 96;
            arg0->unk23C.unknown2.unk4 = 128;
            arg0->unk23C.unknown2.unk5 = 5;
            arg0->unk23C.unknown2.unk6 = 64;
            arg0->unk244 = 0;
        }
        if (arg0->unk14E < 0xFF) {
            arg0->unk14E += 4;
            if (arg0->unk14E >= 256) {
                arg0->unk14E = 0xFF;
            }
        }
    } else {
        if (arg0->unk14E >= 0xFF) {
            arg0->unk23C.unknown2.unk0 = 13;
            arg0->unk23C.unknown2.unk1 = 128;
            arg0->unk23C.unknown2.unk2 = 128;
            arg0->unk23C.unknown2.unk3 = 128;
            arg0->unk23C.unknown2.unk4 = 96;
            arg0->unk23C.unknown2.unk5 = 5;
            arg0->unk23C.unknown2.unk6 = 64;
            arg0->unk244 = 0;
        }
        if (arg0->unk14E > 0) {
            arg0->unk14E -= 4;
            if (arg0->unk14E < 0) {
                arg0->unk14E = 0;
            }
        }
    }
    arg0->yRotation = ((arg0->unk14E * 360) / 128) % 360;
}

// used by OBJECT_BUTTON
// ESA: func_80052324
void func_802F9B4C_70B1FC(struct071 *arg0) {
    if (arg0->unk0 == 1) {
        add_light_at_location(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 0xFF, 255 /* red */, 0, 0);
        if (arg0->Info.unk14E == 0) {
            arg0->Info.unk14E = 1;
            if (arg0->Info.unk152 != 0) {
                play_sound_effect_at_location(SFX_UNKNOWN_82, 0x7FFF, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
            }
        }
    } else if (arg0->Info.unk14E == 1) {
        arg0->Info.unk14E = 0;
        if (arg0->Info.unk152 != 0) {
            play_sound_effect_at_location(SFX_UNKNOWN_82, 0x7FFF, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 0.8f);
        }
    }
    if (arg0->Info.unk152 == 0) {
        arg0->Info.unk152 = 1;
    }
}

// used by OBJECT_ACTIVE_SWITCH
// ESA: func_800523EC
void func_802F9C50_70B300(struct071 *arg0) {
    u8 red;
    u8 green;
    u8 blue;

    s16 temp_t3;

    if (arg0->unk0 == 1) { // is active? enable-able?
        red = 255; green = 0; blue = 0;
        if (arg0->Info.unk14E == 0) {
            arg0->Info.unk14E = 1; // enabled?
            if (arg0->Info.unk152 != 0) {
                play_sound_effect_at_location(82, 0x7FFF, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
            }
        }
    } else {
        red = 0; green = 0; blue = 255;
        if (arg0->Info.unk14E == 1) {
            arg0->Info.unk14E = 0; // disabled
            if (arg0->Info.unk152 != 0) {
                play_sound_effect_at_location(82, 0x7FFF, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 0.8f);
            }
        }
    }

    if (arg0->Info.unk152 == 0) {
        arg0->Info.unk152 = 1;
    }

    add_light_at_location(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 0xFF, red, green, blue);

    temp_t3 = (arg0->unk40 << 6) >> 0xB;
    func_8034C8F8_75DFA8(
        arg0->position.xPos.h,
        arg0->position.zPos.h,
        arg0->position.yPos.h + (arg0->unk42 >> 1),
        0,
        img_D_01033190_6CA60_i4__png,
        temp_t3,
        temp_t3,
        0x20,
        red,
        green,
        blue,
        0,
        0);
}

// ESA: func_800524A4
void func_802F9E10_70B4C0(Animal *arg0, u8 arg1, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
    WaypointData *wpd;
    wpd = D_803E8E60[arg1];

    arg0->unk170 = 3;

    arg0->unk174.unk8 = arg1;
    arg0->unk174.unk0 = arg3;
    arg0->waypointFudgeFactor = (arg2 * arg3);
    arg0->unk174.unk4 = arg4;

    if (arg5 == 0) {
        if (arg3 > 0) {
            arg0->unk176 = 0;
        } else {
            arg0->unk176 = (wpd->length + 1) * 128;
        }
    }
}

// ESA: func_80052548
// similar to SSSV: update_camera_from_waypoint
void func_802F9EB8_70B568(s32 *arg0, s32 *arg1, s32 *arg2, WaypointData *arg3, s16 arg4, u8 arg5) {
    s16 sp58[4];

    s16 var_v1;
    s16 tmp;

    f32 temp_f10;
    f32 temp_f18;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;

    f32 temp_f0;
    f32 temp_f12;


    var_v1 = arg4 / 128;
    tmp = var_v1 - 1;

    if (arg5 != 0) {

        if (tmp - 1 < 0) {
            sp58[0] = arg3->length + tmp - 1;
        } else {
            sp58[0] = tmp - 1;
        }

        if (tmp < 0) {
            sp58[1] = arg3->length + tmp;
        } else if (tmp >= arg3->length) {
            sp58[1] = tmp - arg3->length;
        } else {
            sp58[1] = tmp;
        }

        if (tmp + 1 < 0) {
            sp58[2] = arg3->length + tmp + 1;
        } else if (tmp + 1 >= arg3->length) {
            sp58[2] = (tmp + 1) - arg3->length;
        } else {
            sp58[2] = tmp + 1;
        }

        if (tmp + 2 >= arg3->length) {
            sp58[3] = (tmp - arg3->length) + 2;
        } else {
            sp58[3] = tmp + 2;
        }
    } else {
        sp58[0] = MAX(0, tmp - 1);
        sp58[1] = MAX(0, MIN(arg3->length - 1, tmp));
        sp58[2] = MAX(0, MIN(arg3->length - 1, tmp + 1));
        sp58[3] = MIN(arg3->length - 1, tmp + 2);
    }


    temp_f18 = (f32) ((s16) (arg4 - (var_v1 * 128))) / 128;
    temp_f12 = temp_f18 * temp_f18;
    temp_f0 = temp_f18 * temp_f12;
    temp_f8 = temp_f0 / 6.0;

    temp_f6 =  ((-temp_f0       ) + (3.0 * temp_f12) - (3.0 *  temp_f18) + 1.0) / 6.0;
    temp_f10 = (( temp_f0 *  3.0) - (6.0 * temp_f12) + (4.0            )      ) / 6.0;
    temp_f4 =  (( temp_f0 * -3.0) + (3.0 * temp_f12) + (3.0 *  temp_f18) + 1.0) / 6.0;

    *arg0 = (s32) (((temp_f6 * arg3->waypoint[sp58[0]].x) + (temp_f10 * arg3->waypoint[sp58[1]].x) + (temp_f4 * arg3->waypoint[sp58[2]].x) + (temp_f8 * (arg3->waypoint + sp58[3])->x)) * FTOFIX32(64.0)) + FTOFIX32(32.0);
    *arg1 = (s32) (((temp_f6 * arg3->waypoint[sp58[0]].z) + (temp_f10 * arg3->waypoint[sp58[1]].z) + (temp_f4 * arg3->waypoint[sp58[2]].z) + (temp_f8 * (arg3->waypoint + sp58[3])->z)) * FTOFIX32(64.0)) + FTOFIX32(32.0);
    *arg2 = (s32) (((temp_f6 * arg3->waypoint[sp58[0]].y) + (temp_f10 * arg3->waypoint[sp58[1]].y) + (temp_f4 * arg3->waypoint[sp58[2]].y) + (temp_f8 * (arg3->waypoint + sp58[3])->y)) * FTOFIX32(64.0));
}

// ESA: func_80052C74
void func_802FA4F8_70BBA8(Animal *arg0) {
    s32 xPos;
    s32 zPos;
    s32 yPos;
    WaypointData *wpd;
    u8 check;

    wpd = D_803E8E60[(u8)arg0->unk174.unk8];

    switch (arg0->unk174.unk4) {
    case 1:
        if (arg0->unk174.unk0 > 0) {
            check = (arg0->unk176 >= ((wpd->length + 1) * 128));
        } else {
            check = arg0->unk176 < 1;
        }
        if (check != 0) {
            arg0->unk170 = 0;
            arg0->xVelocity.w = 0;
            arg0->zVelocity.w = 0;
            if ((arg0->unk4C.unk1D == 0)) {
                arg0->yVelocity.w = 0;
            }
            return;
        }

        arg0->unk176 += arg0->waypointFudgeFactor;
        if (arg0->unk174.unk0 > 0) {
            if (arg0->unk176 >= (wpd->length + 1) * 128) {
                arg0->unk176 = (wpd->length + 1) * 128;
            }
        } else if (arg0->unk176 <= 0) {
            arg0->unk176 = 0;
        }
        func_802F9EB8_70B568(&xPos, &zPos, &yPos, wpd, arg0->unk176, 0);
        break;
    default:
        arg0->unk176 += arg0->waypointFudgeFactor;

        if (arg0->unk176 < 0) {
            arg0->unk176 += wpd->length * 128;
        } else if (arg0->unk176 >= (wpd->length * 128)) {
            arg0->unk176 -= (wpd->length * 128);
        }

        func_802F9EB8_70B568(&xPos, &zPos, &yPos, wpd, arg0->unk176, 1);
        break;
    }

    if (arg0->unk16C->unk82.unk0 != 0) {
        yPos = 0;
    }
    arg0->xVelocity.w = xPos - arg0->position.xPos.w;
    arg0->zVelocity.w = zPos - arg0->position.zPos.w;
    if (arg0->unk4C.unk1D == 0) {
        arg0->yVelocity.w = yPos - arg0->position.yPos.w;
    }
}

// ESA: func_80052E6C
void func_802FA6D8_70BD88(void) {
    D_80204278->unk3B308 = 0;
    D_803E97C0 = 0;
    D_803A5760_7B6E10 += 4;
    D_803A5760_7B6E10 &= 0xFF;
    D_803A52D0_7B6980 += 1;
    D_803E1BE0 = 0;
}

#ifdef NON_MATCHING
// CURRENT (250)
// ESA: func_80052EA4
void func_802FA730_70BDE0(Animal *arg0) {
    struct077 spB8; // size 0x6

    s32 pad[13];

    s32 tmp1;
    s32 tmp2;
    s32 tmp3;

    s32 pad2;

    s32 var_s1;
    u8 var_s2;
    u8 var_s3;
    s32 var_v0;

    s16 i;

    if (arg0->unk21E.type24.F & 0x10) {
        arg0->unk21E.type24.Time--;
        if (arg0->unk21E.type24.Time == 0) {
            arg0->unk21E.type24.F = 0;
            return;
        }
    }

    if (arg0->unk21E.type24.F & 8) {
        if (arg0->unk22A > 0) {
            arg0->unk22A--;
            return;
        }

        if (arg0->unk22A == 0) {
            i = 1;
        } else if (arg0->unk22A < 0) {
            i = -arg0->unk22A;
        }

        if (arg0->unk21E.type24.F & 4) {
            if (arg0->unk158 == 0) {
                arg0->unk22A = arg0->unk21E.type24.Fq;
                return;
            } else {
                arg0->unk22A = (arg0->unk21E.type24.Fq << 0xB) / arg0->unk158;
            }
        } else {
            arg0->unk22A = arg0->unk21E.type24.Fq;
        }
    } else {
        i = 1;
    }

    while (i-- > 0) {
        if (arg0->unk22A < 0) {
            arg0->unk22A++;
        }

        spB8.unk0 = arg0->unk212;
        spB8.unk2 = arg0->unk213;
        spB8.unk4 = arg0->unk214;

        if (arg0->unk215 != 0) {
            spB8.unk0 += ((s16) (((s32)func_80128200() >> 4) % ((s16) arg0->unk215 * 2))) - arg0->unk215;
        }
        if (arg0->unk216 != 0) {
            spB8.unk2 += ((s16) (((s32)func_80128200() >> 4) % ((s16) arg0->unk216 * 2))) - arg0->unk216;
        }
        if (arg0->unk217 != 0) {
            spB8.unk4 += ((s16) (((s32)func_80128200() >> 4) % ((s16) arg0->unk217 * 2))) - arg0->unk217;
        }
        if ((arg0->unk21E.type24.F & 0x40) && ((spB8.unk0 | spB8.unk2 | spB8.unk4) != 0)) {
            func_802F5F44_7075F4(
                spB8.unk0,
                spB8.unk2,
                spB8.unk4,
                arg0->zRotation,
                arg0->yRotation,
                &spB8);
        }
        if (arg0->unk21E.type24.F & 0x80) {
            spB8.unk0 = (spB8.unk0 * arg0->unk40) >> 0xB;
            spB8.unk2 = (spB8.unk2 * arg0->unk40) >> 0xB;
            spB8.unk4 = (spB8.unk4 * arg0->unk40) >> 0xB;
        }
        spB8.unk0 += arg0->position.xPos.h;
        spB8.unk2 += arg0->position.zPos.h;
        spB8.unk4 += arg0->position.yPos.h + (arg0->unk42 >> 1);

        var_s1 = arg0->unk21A;
        var_s2 = arg0->unk218;
        var_s3 = arg0->unk219;

        if (arg0->unk21D != 0) {
            var_s1 += ((((s32)func_80128200() >> 4) % (     arg0->unk21D * 2))) - arg0->unk21D;
        }
        if (arg0->unk21B != 0) {
            var_s2 = var_s2 + ((((s32)func_80128200() >> 4) % ((s16)arg0->unk21B * 2))) - arg0->unk21B;
        }
        if (arg0->unk21C != 0) {
            var_s3 = var_s3 + ((((s32)func_80128200() >> 4) % ((s16)arg0->unk21C * 2))) - arg0->unk21C;
        }

        // help?
        if (arg0->unk21E.type24.F & 0x20) {
            var_s2 += (arg0->zRotation * 256) / 360;
            var_s3 += (arg0->yRotation * 256) / 360;
        }

        if (arg0->unk21E.type24.F & 2)  {
            if (arg0->unk158 == 0) {
                break;
            }
            var_s1 *= arg0->unk158;
            var_s1 = var_s1 >> 2;
        } else {
            var_s1 *= 256;
        }

        tmp2 = (var_s1 * COS(var_s2)) >> 0xF;
        tmp3 = (var_s1 * SIN(var_s2)) >> 0xF;

        tmp1 = (tmp2 * SIN(var_s3)) >> 0xF;
        tmp2 = (tmp2 * COS(var_s3)) >> 0xF;

        if (arg0->unk21E.type24.F & 0x80) {
            var_v0 = (arg0->unk21E.type24.S * arg0->unk40);
            var_v0 = var_v0 >> 0xB;
        } else {
            var_v0 = arg0->unk21E.type24.S;
        }

        create_particle_effect(
            spB8.unk0,
            spB8.unk2,
            spB8.unk4,
            arg0->unk21E.type24.State, // particle id
            tmp1 << 8,
            tmp2 << 8,
            tmp3 << 8,
            var_v0,       // size
            arg0->unk226, // rgba16 color
            arg0->unk228, // rgba16 color
            arg0->unk21E.type24.unk5);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_707310/func_802FA730_70BDE0.s")
#endif

// ESA: func_80053494
void func_802FADBC_70C46C(Animal *arg0) {
    s32 pad[2];

    s16 temp_v1_3;
    s16 sp44;
    s16 sp42;

    s32 var_t0;
    f32 var_f0;

    if ((arg0->unk23C.unknown2.unk5 & 4)) {
        f32 factor = 128.0f;

        if (arg0->unk23C.unknown2.unk6 > 0) {
            var_t0 = ((((arg0->unk23C.unknown2.unk2 - arg0->unk23C.unknown2.unk1) * arg0->unk244) / arg0->unk23C.unknown2.unk6) + arg0->unk23C.unknown2.unk1 + 0) << 7;
            var_f0 = ((((arg0->unk23C.unknown2.unk4 - arg0->unk23C.unknown2.unk3) * arg0->unk244) / arg0->unk23C.unknown2.unk6) + arg0->unk23C.unknown2.unk3 + 1) / factor;
        } else {
            var_t0 = (arg0->unk23C.unknown2.unk1 + 0) << 7;
            var_f0 = (arg0->unk23C.unknown2.unk3 + 1) / factor;
        }

        if (arg0->unk23C.unknown2.unk5 & 1) {
            func_8032CED0_73E580(
                arg0,
                arg0->unk23C.unknown2.unk0,  // sound effect id ?
                var_t0,
                var_f0,
                0,
                0,
                arg0->position.xPos.h,
                arg0->position.zPos.h,
                arg0->position.yPos.h,
                arg0->xVelocity.w,
                arg0->zVelocity.w,
                arg0->yVelocity.w);
        } else {
            func_8032CD20_73E3D0(arg0, arg0->unk23C.unknown2.unk0, var_t0, 0, var_f0);
        }

        if (arg0->unk23C.unknown2.unk6 >= 0) {
            if (arg0->unk244++ >= arg0->unk23C.unknown2.unk6) {
                arg0->unk23C.unknown2.unk5 = 0;
            }
        }
    }

    if ((arg0->unk20C != 0) && (arg0->unk16C->objectType != 5)) {
        func_802F705C_70870C(
            arg0,
            arg0->zRotation,
            arg0->yRotation,
            arg0->unk42 >> 1,
            arg0->unk158,
            arg0->unk20C,
            arg0->unk210,
            arg0->unk20E);
    }

    if (arg0->unk170 == 3) {
        func_802FA4F8_70BBA8(arg0);
    } else if (arg0->unk170 == 1) {
        func_802F65BC_707C6C(arg0);
    } else if (arg0->unk170 == 2) {
        func_802F6750_707E00(arg0);
    } else if (arg0->unk170 == 5) {
        head_towards_waypoint(arg0);
    } else if (arg0->unk170 == 6) {
        head_towards_waypoint(arg0);
    }

    if (arg0->unk21E.type24.F & 1) {
        func_802FA730_70BDE0(arg0);
    }

    if (arg0->unk22C != 0) {
        if ((arg0->unk22C & 0x10)) {
            sp44 = arg0->zRotation + arg0->unk22E;
            sp42 = arg0->yRotation + arg0->unk232;
        } else {
            if ((arg0->unk22C & 4)) {
                sp44 = arg0->unk236 + ((arg0->unk22E * arg0->unk230) >> 8);
                sp42 = arg0->unk23A + ((arg0->unk232 * arg0->unk230) >> 8);
            } else {
                temp_v1_3 = COS(arg0->unk230 >> 1);
                sp44 = (arg0->unk236 + (arg0->unk22E >> 1)) - (((arg0->unk22E >> 1) * temp_v1_3) >> 0xF);
                sp42 = (arg0->unk23A + (arg0->unk232 >> 1)) - (((arg0->unk232 >> 1) * temp_v1_3) >> 0xF);
            }
            if (arg0->unk230 >= 256) {
                arg0->unk22C = 0U;
                sp44 = arg0->unk236 + arg0->unk22E;
                sp42 = arg0->unk23A + arg0->unk232;
            } else {
                arg0->unk230 += arg0->unk22D;
                if (arg0->unk230 > 256) {
                    arg0->unk230 = 256;
                }
            }
        }

        sp44 = sp44 % 360;
        sp42 = sp42 % 360;
        if (arg0->unk16C->unk15 == 4) {
            func_802C9918_6DAFC8(arg0, sp44, sp42);
        } else {
            arg0->zRotation = sp44;
            arg0->yRotation = sp42;
        }
    }
}

// used in collist2
// ESA: func_800537C4
void func_802FB270_70C920(Animal *arg0) {

    if ((arg0->unk4C.unk1C != 0) || (arg0->unk4C.unk1D != 0)) {
        func_802C9F60_6DB610(arg0);
    }
    if ((arg0->unk4C.unk1C == 0) || (arg0->unk4C.unk1D == 0)) {
        func_802F90A8_70A758(arg0);
    }
    if (arg0->commands.unk1A8 != NULL) {
        func_803191B0_72A860(arg0);
    }
    func_802FADBC_70C46C(arg0);
    arg0->newPosition.xPos.w = arg0->position.xPos.w + arg0->xVelocity.w;
    arg0->newPosition.zPos.w = arg0->position.zPos.w + arg0->zVelocity.w;
    arg0->newPosition.yPos.w = arg0->position.yPos.w + arg0->yVelocity.w;
    func_802F5C60_707310(arg0);

    if (arg0->unk4C.unk1A == 0) {
        switch (arg0->unk16C->unk88) {
        case 0:
            if (arg0->health <= 0) {
                run_commands(arg0);
            }
            break;
        case 1:
            if ((arg0->unk5C.unk0 & 4) && (arg0->unk5C.unk4 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
                run_commands(arg0);
            }
            break;
        case 3:
            if (arg0->unk5C.unk0 & 8) {
                run_commands(arg0);
            }
            break;
        case 4:
            if (arg0->unk5C.unk0 & (1|4)) {
                run_commands(arg0);
            }
            break;
        case 5:
            if (((arg0->unk5C.unk0 & 1) && (arg0->unk5C.unk1 != arg0->unk16C->objectType)) ||
                 (arg0->unk5C.unk0 & (2|4))) {
                run_commands(arg0);
            }
            break;
        }
        if (arg0->unk26C != 0) {
            return;
        }
    }

    if ((arg0->unk4C.unk1A == 0) && (arg0->unk154 != 0)) {
        arg0->unk154--;
        if (arg0->unk154 == 1) {
            run_commands(arg0);
        }
    }
    func_802FB49C_70CB4C(arg0);
    arg0->unk65 = 0;
    if (arg0->unk15C > 0) {
        arg0->unk15C--;
    }
}

// ESA: func_80053A0C
void func_802FB49C_70CB4C(Animal *arg0) {
    // struct copy
    arg0->unk5C = arg0->unk54;

    arg0->unk54.unk0 = 0;
    arg0->unk54.unk1 = 0;
    arg0->unk54.unk2 = 0;
    arg0->unk54.unk3 = 0;
}

// ESA: func_80053A30
void func_802FB4C0_70CB70(Animal *arg0) {
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_t0 = (arg0->unk40 << 4) >> 11;
    } else {
        phi_t0 = arg0->unk15E;
    }
    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v0 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v0 = -1;
    }
    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 0x32, phi_t0, phi_v0);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 0x20;
    } else {
        phi_a1 = 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), arg0->unk30 >> 2, 0);
}

// ESA: func_80053D34
void func_802FB680_70CD30(Animal *arg0) {
    s16 phi_v1;
    s16 phi_v0;
    s16 phi_a3;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_v0 = (arg0->unk40 << 5) >> 11;
        if (arg0->unk158 != 0) {
            phi_v0 *= arg0->unk158;
        }
    } else {
        phi_v0 = arg0->unk15E;
    }
    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v1 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v1 = -1;
    }
    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 0x64, phi_v0, phi_v1);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 4 | 2 | 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + ((s32) arg0->unk42 >> 1), arg0->unk30 >> 2, 0);
}

// ESA: func_80054084
void func_802FB85C_70CF0C(Animal *arg0) {
    s16 phi_v1;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_v0 = (arg0->unk40 << 5) >> 11;
        if (arg0->unk158 != 0) {
            phi_v0 *= arg0->unk158;
        }
    } else {
        phi_v0 = arg0->unk15E;
    }

    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v1 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v1 = -1;
    }

    func_802FF184_710834(
        arg0,
        1,
        arg0->position.xPos.h,
        arg0->position.zPos.h,
        arg0->position.yPos.h + (arg0->unk42 >> 1),
        0,
        0,
        100,
        phi_v0,
        phi_v1);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 4 | 2 | 1;
    }

    phi_a1 |= 64;

    func_802D7BE0_6E9290(
        0,
        phi_a1,
        arg0->position.xPos.h,
        arg0->position.zPos.h,
        arg0->position.yPos.h + (arg0->unk42 >> 1),
        arg0->unk30 >> 2,
        0);
}

// ESA: func_800543AC
void func_802FBA40_70D0F0(Animal *arg0) {
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_t0 = (arg0->unk40 << 5) >> 11;
    } else {
        phi_t0 = arg0->unk15E;
    }
    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v0 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v0 = -1;
    }
    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), arg0->yRotation, 0x5A, 0x64, phi_t0, phi_v0);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, arg0->unk30 >> 4, 0);
}

// ESA: func_8005471C
void func_802FBBF8_70D2A8(Animal *arg0) {
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_t0 = (arg0->unk40 << 5) >> 11;
    } else {
        phi_t0 = arg0->unk15E;
    }

    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v0 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v0 = -1;
    }

    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + ((s32) arg0->unk42 >> 1), 0, 0, 0x64, phi_t0, phi_v0);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, (s32) arg0->unk30 >> 2, 0);
}

// ESA: func_80054A0C (tbd)
void func_802FBDA8_70D458(Animal *arg0) {
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_t0 = (arg0->unk40 * 0x10) >> 11;
    } else {
        phi_t0 = arg0->unk15E;
    }
    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v0 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v0 = -1;
    }

    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 0x64, phi_t0, phi_v0);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 2 | 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, (s32) arg0->unk30 >> 2, 0);
}

// ESA: func_80054CFC (tbd)
void func_802FBF58_70D608(Animal *arg0) {
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_t0 = (arg0->unk40 << 5) >> 11;
    } else {
        phi_t0 = arg0->unk15E;
    }
    if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
        phi_v0 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v0 = -1;
    }

    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 0x64, phi_t0, phi_v0);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 4 | 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, arg0->unk30 >> 2, 0);
}

// ESA: func_80054FEC (tbd)
void func_802FC108_70D7B8(Animal *arg0) {
    s16 phi_t0;
    s16 phi_v0;
    s16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_t0 = (arg0->unk40 << 5) >> 11;
    } else {
        phi_t0 = arg0->unk15E;
    }
    if ((arg0->owner != NULL) && ((arg0->owner->unk16C->unk82.unk2))) {
        phi_v0 = arg0->owner->unk16C->unkE6;
    } else {
        phi_v0 = -1;
    }
    func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 0x64, phi_t0, phi_v0);

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 4 | 2 | 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, arg0->unk30 >> 2, 0);
}

// ESA: func_800552DC
void func_802FC2B8_70D968(s16 x, s16 z, s16 y) {
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s16 i;

    for (i = 0; i < 11; i++) {
        temp_s1 = ((s32)func_80128200() % FTOFIX32(6.0)) - FTOFIX32(3.0);
        temp_s2 = ((s32)func_80128200() % FTOFIX32(6.0)) - FTOFIX32(3.0);
        temp_s3 = ((s32)func_80128200() % FTOFIX32(2.0)) + FTOFIX32(3.0);
        create_particle_effect(
            x,
            z,
            y,
            35,
            temp_s1,
            temp_s2,
            temp_s3,
            8,
            GPACK_RGBA5551(0, 0, 0, 0),
            GPACK_RGBA5551(0, 0, 0, 0),
            0);
    }
}

// ESA: func_80055430
void func_802FC438_70DAE8(s16 x, s16 z, s16 y) {
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s16 i;

    for (i = 0; i < 3; i++) {
        temp_s1 = ((s32)func_80128200() % FTOFIX32(6.0)) - FTOFIX32(3.0);
        temp_s2 = ((s32)func_80128200() % FTOFIX32(6.0)) - FTOFIX32(3.0);
        temp_s3 = ((s32)func_80128200() % FTOFIX32(2.0)) + FTOFIX32(3.0);
        create_particle_effect(
            x,
            z,
            y,
            35,
            temp_s1, // ?
            temp_s2, // ?
            temp_s3, // ?
            8,       // particle size
            GPACK_RGBA5551(0, 248, 0, 1),
            GPACK_RGBA5551(8,  56, 0, 1),
            0);
    }
}

// ESA: func_8005558C
void func_802FC5C0_70DC70(Animal *arg0) {
    s16 phi_a1;

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 32 | 8;
    } else {
        phi_a1 = 8 | 1;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, arg0->unk30, func_8029A52C_6ABBDC(arg0->unk3E));
}

// ESA: func_80055814
void func_802FC6E4_70DD94(Animal *arg0) {
    s16 phi_a1;

    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        phi_a1 = 64 | 32 | 8;
    } else {
        phi_a1 = 64 | 8;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, arg0->unk30, func_8029A52C_6ABBDC(arg0->unk3E));
}

// ESA: func_80055A9C
void func_802FC808_70DEB8(Animal *arg0) {
  s16 i;
  s32 temp_s4;

  temp_s4 = (arg0->unk40 * 18) >> 0xB;

  for (i = 0; i < 10; i++) {
      create_particle_effect(
          arg0->position.xPos.h,
          arg0->position.zPos.h,
          arg0->position.yPos.h + (arg0->unk42 >> 1),
          0x17,
          (D_803A52E8_7B6998[i*2] * arg0->unk40) >> 0xB,
          (D_803A52E8_7B6998[i*2+1] * arg0->unk40) >> 0xB,
          0,
          temp_s4,
          GPACK_RGBA5551(176, 176, 176, 0),
          GPACK_RGBA5551(176, 176, 176, 0),
          0);
  }
}

void func_802FC8F4_70DFA4(Animal *arg0) {
    s32 tmp = (arg0->unk40 * 18) >> 11;
    create_particle_effect(
        arg0->position.xPos.h,
        arg0->position.zPos.h,
        arg0->position.yPos.h + (arg0->unk42 >> 1),
        23,
        0,
        0,
        0,
        tmp,
        GPACK_RGBA5551(176, 176, 176, 0),
        GPACK_RGBA5551(176, 176, 176, 0),
        0);
}

void func_802FC970_70E020(Animal *arg0) {
    func_802FCA08_70E0B8(arg0, arg0->unk164);
}

void run_commands(Animal *arg0) {
    if (arg0->unk26C != 1) {
        func_802FCA08_70E0B8(arg0, arg0->unk164);
        arg0->unk26C = 1;
        if (arg0->cmdIndex != 0) {
            load_commands_into_object(arg0, &D_803E4D40[arg0->cmdIndex - 1], 0);
            func_803191B0_72A860(arg0);
        }
    }
}

// ESA: func_80055C04
void func_802FCA08_70E0B8(Animal *arg0, s16 arg1) {
    u32 tmp;
    s16 tmp2;

    s16 phi_v0;
    s8 phi_v1;

    // 0x4000 -> 0100000000000000
    // 0xBFFF -> 1011111111111111
    if (tmp = (!(arg1 & 0x4000)) & 0xFF) {};
    if (tmp2 = (arg1 & (~0x4000)) & 0xFFFF) {};

    switch (tmp2) {
    case 0:
        break;
    case 1: // dust cloud
        func_802FC808_70DEB8(arg0);
        break;
    case 2: // bomb/explosion air
        func_802FB4C0_70CB70(arg0);
        break;
    case 3: // bomb/explosion ground
        func_802FBBF8_70D2A8(arg0);
        break;
    case 4: // powerup?
        switch (arg0->unk16C->objectType) {
        case 0x22: // powercell
            if (tmp) {
                D_803F2D30.powercells++;
                D_803F2D30.powercells2++;
                D_803F2D30.score += 1000;
            }
            do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, (arg0->position.yPos.h + ((arg0->unk40) >> 7) * 2), 2);
            return;
            break;
        case 0x3A: // energy ball + 16 hp
            if (tmp) {
                if (D_803F2D30.unk4 == 0) {
                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = MIN(D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 0x10, 0x7F);
                }
                D_803D552C->unk348 = 0;
                D_803D552C->unk34A = 0;
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->laughterThreshold = 0;
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->isLaughing = 0;
            }
            do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + ((arg0->unk40) >> 7) * 2, 1);
            return;
            break;
        case 0x3B:  // energy ball + 32 hp
            if (tmp) {
                if (D_803F2D30.unk4 == 0) {
                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = MIN(D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 0x20, 0x7F);
                }
                D_803D552C->unk348 = 0;
                D_803D552C->unk34A = 0;
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->laughterThreshold = 0;
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->isLaughing = 0;
            }
            do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, (arg0->position.yPos.h + ((arg0->unk40) >> 7) * 2), 1);
            return;
            break;
        case 0x3C: // energy ball + 64hp
            if (tmp) {
                if (D_803F2D30.unk4 == 0) {
                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = MIN(D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 0x40, 0x7F);
                }
                D_803D552C->unk348 = 0;
                D_803D552C->unk34A = 0;
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->laughterThreshold = 0;
                D_801D9ED8.animals[gCurrentAnimalIndex].animal->isLaughing = 0;
            }
            do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + ((arg0->unk40) >> 7) * 2, 1);
            return;
            break;
        default:
            do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + ((arg0->unk40) >> 7) * 2, 2);
            return;
            break;
        }
        break;
    case 5:
        break;
    case 6: // white sparks?
        func_802FC2B8_70D968(arg0->position.xPos.h, arg0->position.zPos.h, (arg0->position.yPos.h + (arg0->unk42 >> 1)));
        break;
    case 7: // explosion with red debris
        func_802FBF58_70D608(arg0);
        break;
    case 8: // ground explosion
        func_802FBDA8_70D458(arg0);
        break;
    case 9: // explosion
        func_802FC108_70D7B8(arg0);
        break;
    case 10: // big explosion, brown debris
        func_802FC5C0_70DC70(arg0);
        break;
    case 11: // water splash
        func_802D760C_6E8CBC(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), arg0->unk30, 8);
        break;
    case 12: // small explosion
        create_particle_effect_2(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 0, 0, 0);
        break;
    case 13: // explosion
        func_802FB680_70CD30(arg0);
        break;
    case 14: // explosion vertical (wall hit?)
        func_802FBA40_70D0F0(arg0);
        break;
    case 15: // radioactive
        func_802FC438_70DAE8(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1));
        break;
    case 16: // cardboard/earthquake debris?
        func_802FC6E4_70DD94(arg0);
        play_sound_effect_at_location(SFX_UNKNOWN_121, 0x6000, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
        break;
    case 17: // trophy?
        do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 3);
        break;
    case 18: // key?
        do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 4);
        break;
    case 19: // shockwave
        if (arg0->unk15E == 0) {
            phi_v0 = ((arg0->unk40 << 5) >> 11);
            if (arg0->unk158 != 0) {
                phi_v0 *= arg0->unk158;
            }
        } else {
            phi_v0 = arg0->unk15E;
        }
        if ((arg0->owner != NULL) && (arg0->owner->unk16C->unk82.unk2)) {
            phi_v1 = arg0->owner->unk16C->unkE6;
        } else {
            phi_v1 = -1;
        }
        func_802FF184_710834(arg0, 1, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0, 0, 100, phi_v0, phi_v1);
        func_802D7BE0_6E9290(0, 32, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), arg0->unk30 >> 1, 0);
        break;
    case 20: // objective with sound?
        do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 5);
        break;
    case 21: // big splash?
        create_particle_effect_2(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), 0x3A, arg0->unk30 << 2, 0, 0, 0);
        break;
    case 22: // objective no sound?
        do_item_collected_effect(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 6);
        break;
    case 23: // nuts & bolts (evo exploding?)
        func_802D7BE0_6E9290(0, 16, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h + (arg0->unk42 >> 1), arg0->unk30 >> 2, 0);
        break;
    case 24: // brown debris
        func_802FC6E4_70DD94(arg0);
        play_sound_effect_at_location(SFX_UNKNOWN_75, 0x6000, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
        break;
    case 25: // ground explosion
        func_802FB85C_70CF0C(arg0);
        break;
    default:
        break;
    }
}

void set_floor_level(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, s16 value) {
    s16 i, j;

    for (i = 0; i <= xEnd; i++) {
        for (j = 0; j <= yEnd; j++) {
            D_803C0740[xStart + i][yStart + j].unk0 = value;
        }
    }
    func_802DAFAC_6EC65C(xStart, yStart, xEnd, yEnd);
}

void set_water_level(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, s16 value) {
    s16 i, j;

    for (i = 0; i <= xEnd; i++) {
        for (j = 0; j <= yEnd; j++) {
            D_803C0740[xStart + i][yStart + j].unk6 = value;
        }
    }
    func_802DAFAC_6EC65C(xStart, yStart, xEnd, yEnd);
}

// ESA: func_80056474
s32 func_802FD348_70E9F8(Animal *arg0, u16 arg1) {
    CollisionNode *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].next; tmp != NULL; tmp = tmp->next) {
        if ((arg0 == tmp->animal->unk6C) && (tmp->animal->unk16C->objectType == arg1)) {
            return 1;
        }
    }
    return 0;
}

// ESA: func_800564F4
s32 func_802FD3B8_70EA68(Animal *arg0) {
    CollisionNode *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].next; tmp != NULL; tmp = tmp->next) {
        if (arg0 == tmp->animal->unk6C) {
            return 1;
        }
    }
    return 0;
}

// is_target_of ?
// ESA: func_8005655C
s32 func_802FD40C_70EABC(Animal *arg0, Animal *arg1) {
    CollisionNode *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].next; tmp != NULL; tmp = tmp->next) {
        if ((arg0 == tmp->animal->unk6C) && (arg1 == tmp->animal)) {
            return 1;
        }
    }
    return 0;
}

// ESA: func_800565BC
s32 func_802FD468_70EB18(Animal *arg0) {
    CollisionNode *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].next; tmp != NULL; tmp = tmp->next) {
        if ((arg0 == tmp->animal->unk6C) && (tmp->animal->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET)) {
            return 1;
        }
    }
    return 0;
}

// ESA: func_80056640
s32 func_802FD4D0_70EB80(Animal *arg0) {
    CollisionNode *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].next; tmp != NULL; tmp = tmp->next) {
        if ((arg0 == tmp->animal->unk6C) && (tmp->animal->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET)) {
            return 1;
        }
    }
    return 0;
}

// ESA: func_800566C4
s32 func_802FD538_70EBE8(Animal *arg0) {
    s16 i;

    if ((D_803E1B02 > 0) && (D_801D9ED8.animals[gCurrentAnimalIndex].animal->state == 0xDD)) {
        for (i = 0; i < 120; i++) {
            if ((D_803E00C0[i].unk2F == 2) &&
                ((arg0 == D_803E00C0[i].unk4) || (arg0 == D_803E00C0[i].unk0))) {
                return 1;
            }
        }
    }
    return 0;
}

// stubbed out in ESA
s16 func_802FD5DC_70EC8C(Animal *arg0) {
    CollisionNode *tmp;
    s16 res;

    res = 0;

    for (tmp = D_803DA110[arg0->unk114[0]].next; tmp != NULL; tmp = tmp->next) {
        if (arg0 == tmp->animal->unk6C) {
            res += tmp->animal->unk44 + func_802FD5DC_70EC8C(tmp->animal);
        }
    }

    return res;
}

// ESA: func_80056774
void func_802FD674_70ED24(Animal *arg0, Animal *arg1) {
    s16 tmp;

    if ((arg1->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) && (arg0->unk54.unk2 < 5)) {
        arg0->unk54.unk0 |= 0x8 | 0x4;
        arg0->unk54.unk1 = arg1->unk16C->objectType - OB_TYPE_ANIMAL_OFFSET;
        arg0->unk54.unk4 = arg1;
        arg0->unk54.unk2 = 5U;
        if (arg1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            arg0->unk54.unk0 |= 0x10;
        }
    } else {
        if ((arg1->unk16C->unk2 != 9) || (arg1->unk16C->objectType == OBJECT_UNKNOWN_9)) {
            if ((arg1->unk16C->unk2 == 1) || (arg1->unk16C->unk2 == 2)) {
                tmp = 10;
            } else {
                tmp = 2;
            }
            if (arg0->unk54.unk2 < tmp) {
                arg0->unk54.unk0 |= 9;
                arg0->unk54.unk1 = arg1->unk16C->objectType;
                arg0->unk54.unk4 = arg1;
                arg0->unk54.unk2 = tmp;
            }
            if ((arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) && (arg1->owner == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
                arg0->unk2EB++;
            }
        }
    }
    if ((arg0->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) && (arg1->unk54.unk2 < 5)) {
        arg1->unk54.unk0 |= 0x8 | 0x4;
        arg1->unk54.unk1 = arg0->unk16C->objectType - OB_TYPE_ANIMAL_OFFSET;
        arg1->unk54.unk4 = arg0;
        arg1->unk54.unk2 = 5U;
        if (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            arg1->unk54.unk0 |= 0x10;
        }
    } else {
        if ((arg0->unk16C->unk2 != 9) || (arg0->unk16C->objectType == OBJECT_UNKNOWN_9)) {
            if ((arg0->unk16C->unk2 == 1) || ((arg0->unk16C->unk2 == 2))) {
                tmp = 10;
            } else {
                tmp = 2;
            }
            if (arg1->unk54.unk2 < tmp) {
                arg1->unk54.unk0 |= 0x8|0x1;
                arg1->unk54.unk1 = arg0->unk16C->objectType;
                arg1->unk54.unk4 = arg0;
                arg1->unk54.unk2 = tmp;
            }
            if ((arg1->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) &&
                (arg0->owner == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
                arg1->unk2EB++;
            }
        }
    }
}

// set_fog_from_level_data
void func_802FD8CC_70EF7C(void) {
    D_803E1CF8.min = D_803E1CE8.min = D_803F2D50.unk2;
    D_803E1CF8.max = D_803E1CE8.max = D_803F2D50.unk4;

    D_803E1CF8.r = D_803E1CE8.r = D_803F2D50.unk6;
    D_803E1CF8.g = D_803E1CE8.g = D_803F2D50.unk8;
    D_803E1CF8.b = D_803E1CE8.b = D_803F2D50.unkA;

    D_803E1D00 = D_803E1D02 = 0;
    D_803E1D04 = 1;
}

void func_802FD94C_70EFFC(s16 min, s16 max, u8 r, u8 g, u8 b, s16 arg5) {
    D_803E1CE0 = D_803E1CF8;

    D_803E1CE8.min = min;
    D_803E1CE8.max = max;
    D_803E1CE8.r = r;
    D_803E1CE8.g = g;
    D_803E1CE8.b = b;
    D_803E1D00 = arg5;
    D_803E1D02 = 0;
    D_803E1D04 = 0;
    D_803E1D0C = 0;
}

void func_802FD9C4_70F074(s16 min, s16 max, u8 r, u8 g, u8 b, s16 arg5, s16 arg6) {
    // struct copy
    D_803E1CE0 = D_803E1CF8;

    D_803E1CF0.min = min;
    D_803E1CF0.max = max;
    D_803E1CF0.r = r;
    D_803E1CF0.g = g;
    D_803E1CF0.b = b;
    D_803E1D06 = arg5;
    D_803E1D08 = arg6;
    D_803E1D0A = 0;
    D_803E1D0C = 1;
}

void func_802FDA44_70F0F4(void) {
    f32 temp_f0;

    if (D_803E1D04 == 0) {
        if (D_803E1D02 == D_803E1D00) {
            D_803E1CF8.min = D_803E1CE8.min;
            D_803E1CF8.max = D_803E1CE8.max;
            D_803E1CF8.r = D_803E1CE8.r;
            D_803E1CF8.g = D_803E1CE8.g;
            D_803E1CF8.b = D_803E1CE8.b;
            D_803E1D04 = 1;
        } else {
            temp_f0 = (f32) D_803E1D02 / (f32) D_803E1D00;
            D_803E1CF8.min = (D_803E1CE0.min + (((f32) D_803E1CE8.min - D_803E1CE0.min) * temp_f0));
            D_803E1CF8.max = (D_803E1CE0.max + (((f32) D_803E1CE8.max - D_803E1CE0.max) * temp_f0));
            D_803E1CF8.r = (D_803E1CE0.r + (((f32) D_803E1CE8.r - D_803E1CE0.r) * temp_f0));
            D_803E1CF8.g = (D_803E1CE0.g + (((f32) D_803E1CE8.g - D_803E1CE0.g) * temp_f0));
            D_803E1CF8.b = (D_803E1CE0.b + (((f32) D_803E1CE8.b - D_803E1CE0.b) * temp_f0));
            D_803E1D02++;
        }
    } else {
        D_803E1CF8.min = D_803E1CE8.min;
        D_803E1CF8.max = D_803E1CE8.max;
        D_803E1CF8.r = D_803E1CE8.r;
        D_803E1CF8.g = D_803E1CE8.g;
        D_803E1CF8.b = D_803E1CE8.b;
    }
    if (D_803E1D0C != 0) {
        if (D_803E1D06 >= D_803E1D0A) {
            if (D_803E1D06 == 0) {
                temp_f0 = 1.0f;
            } else {
                temp_f0 = (f32) D_803E1D0A / (f32) D_803E1D06;
            }
            D_803E1CF8.min = (D_803E1CF8.min + (((f32) D_803E1CF0.min - D_803E1CF8.min) * temp_f0));
            D_803E1CF8.max = (D_803E1CF8.max + (((f32) D_803E1CF0.max - D_803E1CF8.max) * temp_f0));
            D_803E1CF8.r = (D_803E1CF8.r + (((f32) D_803E1CF0.r - D_803E1CF8.r) * temp_f0));
            D_803E1CF8.g = (D_803E1CF8.g + (((f32) D_803E1CF0.g - D_803E1CF8.g) * temp_f0));
            D_803E1CF8.b = (D_803E1CF8.b + (((f32) D_803E1CF0.b - D_803E1CF8.b) * temp_f0));
        } else {
            if ((D_803E1D06 + D_803E1D08) >= (s32) D_803E1D0A) {
                if (D_803E1D06 == 0) {
                    temp_f0 = 1.0f;
                } else {
                    temp_f0 = ((f32) D_803E1D0A - (f32) D_803E1D06) / (f32) D_803E1D08;
                }
                D_803E1CF8.min = (D_803E1CF0.min + (((f32) D_803E1CF8.min - D_803E1CF0.min) * temp_f0));
                D_803E1CF8.max = (D_803E1CF0.max + (((f32) D_803E1CF8.max - D_803E1CF0.max) * temp_f0));
                D_803E1CF8.r = (D_803E1CF0.r + (((f32) D_803E1CF8.r - D_803E1CF0.r) * temp_f0));
                D_803E1CF8.g = (D_803E1CF0.g + (((f32) D_803E1CF8.g - D_803E1CF0.g) * temp_f0));
                D_803E1CF8.b = (D_803E1CF0.b + (((f32) D_803E1CF8.b - D_803E1CF0.b) * temp_f0));
            } else {
                D_803E1D0C = 0;
            }
        }
        D_803E1D0A++;
    }
}

void func_802FE4C4_70FB74(void) {
    D_803E1D20.unk0 = D_803E1D18.unk0 = D_803F2D50.unk54;
    D_803E1D20.unk1 = D_803E1D18.unk1 = D_803F2D50.unk55;
    D_803E1D20.unk2 = D_803E1D18.unk2 = D_803F2D50.unk56;
    D_803E1D20.unk3 = D_803E1D18.unk3 = D_803F2D50.unk57;
    D_803E1D20.unk4 = D_803E1D18.unk4 = D_803F2D50.unk58;
    D_803E1D20.unk5 = D_803E1D18.unk5 = D_803F2D50.unk59;
    D_803E1D20.unk6 = D_803E1D18.unk6 = D_803F2D50.unk5A;
    D_803E1D20.unk7 = D_803E1D18.unk7 = D_803F2D50.unk5B;

    D_803E1D28 = D_803E1D2A = 0;
    D_803E1D2C = 1;
}

void func_802FE560_70FC10(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, u8 arg7, s16 arg8) {
    D_803E1D10 = D_803E1D20;

    D_803E1D18.unk0 = arg0;
    D_803E1D18.unk1 = arg1;
    D_803E1D18.unk2 = arg2;
    D_803E1D18.unk3 = arg3;
    D_803E1D18.unk4 = arg4;
    D_803E1D18.unk5 = arg5;
    D_803E1D18.unk6 = arg6;
    D_803E1D18.unk7 = arg7;
    D_803E1D28 = arg8;
    D_803E1D2A = 0;
    D_803E1D2C = 0;
}

void func_802FE5E8_70FC98(void) {
    f32 temp_f0;

    if (D_803E1D2C == 0) {
        if (D_803E1D2A == D_803E1D28) {
            D_803E1D2C = 1;
        }
        temp_f0 = (f32) D_803E1D2A / D_803E1D28;
        D_803E1D20.unk0 = (D_803E1D10.unk0 + (((f32) D_803E1D18.unk0 - D_803E1D10.unk0) * temp_f0));
        D_803E1D20.unk1 = (D_803E1D10.unk1 + (((f32) D_803E1D18.unk1 - D_803E1D10.unk1) * temp_f0));
        D_803E1D20.unk2 = (D_803E1D10.unk2 + (((f32) D_803E1D18.unk2 - D_803E1D10.unk2) * temp_f0));
        D_803E1D20.unk3 = (D_803E1D10.unk3 + (((f32) D_803E1D18.unk3 - D_803E1D10.unk3) * temp_f0));
        D_803E1D20.unk4 = (D_803E1D10.unk4 + (((f32) D_803E1D18.unk4 - D_803E1D10.unk4) * temp_f0));
        D_803E1D20.unk5 = (D_803E1D10.unk5 + (((f32) D_803E1D18.unk5 - D_803E1D10.unk5) * temp_f0));
        D_803E1D20.unk6 = (D_803E1D10.unk6 + (((f32) D_803E1D18.unk6 - D_803E1D10.unk6) * temp_f0));
        D_803E1D20.unk7 = (D_803E1D10.unk7 + (((f32) D_803E1D18.unk7 - D_803E1D10.unk7) * temp_f0));

        D_803E1D2A++;

        D_803F2D50.unk54 = D_803E1D20.unk0;
        D_803F2D50.unk55 = D_803E1D20.unk1;
        D_803F2D50.unk56 = D_803E1D20.unk2;
        D_803F2D50.unk57 = D_803E1D20.unk3;
        D_803F2D50.unk58 = D_803E1D20.unk4;
        D_803F2D50.unk59 = D_803E1D20.unk5;
        D_803F2D50.unk5A = D_803E1D20.unk6;
        D_803F2D50.unk5B = D_803E1D20.unk7;
    }
}

// ESA: func_80056A2C
void func_802FED68_710418(struct071 *owner, Animal *target, s16 x, s16 z, s16 y, s16 arg5, s16 arg6, s16 arg7, s16 angle, s16 rotation, s16 unkA, f32 scale, u8 argC) {
    struct077 position;
    struct077 velocity;

    func_802F5F44_7075F4(arg5, arg6,      arg7, angle, rotation, &position);
    func_802F5F44_7075F4(0,    unkA << 8, 0,    angle, rotation, &velocity);
    fire_homing_missile(
    /* x         */ x + position.unk0,
    /* z         */ z + position.unk2,
    /* y         */ y + position.unk4,
    /* angle     */ angle,
    /* rotation  */ rotation,
    /* target    */ target,
    /*           */ 3,
    /*           */ 10,
    /* scale     */ scale,
    /* lifetime  */ 250,
    /*           */ (owner->unk40 * 0xA) >> 0xB,
    /* xVelocity */ velocity.unk0 << 8,
    /* zVelocity */ velocity.unk2 << 8,
    /* yVelocity */ velocity.unk4 << 8,
    /* owner     */ owner);
}

void fire_homing_missile(s16 x, s16 z, s16 y, s16 vAngle, s16 rotation, Animal* target, s16 arg6, s16 arg7, f32 scale, s16 lifetime, s16 argA, s16 xVel, s16 zVel, s16 yVel, Animal* owner) {
    // spawn missile
    struct071 *obj = spawn_object(18, x, z, y, xVel << 16, zVel << 16, yVel << 16, vAngle, rotation, (s32) (s16) (scale * 2048.0f));

    if (obj != NULL) {
        obj->unk15C = 15;
        obj->owner = owner;
        obj->Info.Counter2 = arg6;
        obj->Info.unk152 = arg7;
        obj->target = target;
        obj->unk154 = lifetime;
        obj->unk15E = argA;
        obj->Info.unk14E = func_80128200();
        if (arg7 < 20) {
            add_regular_trail(obj, 2, (obj->unk40 * 25) >> 11, 16, 0, (obj->unk40 * -30) >> 11, 0, 0xFF, 0, 0, 0xFF, 0xB9, 0, 0, 0, 0, 2, 1, 0);
        } else {
            add_regular_trail(obj, 2, (obj->unk40 * 25) >> 11,  8, 0, (obj->unk40 * -30) >> 11, 0, 0xFF, 0, 0, 0xFF, 0x9B, 0, 0, 0, 0, 1, 1, 0);
        }
    }
}

void spawn_temporary_object(s16 x, s16 z, s16 y, s16 scale, u8 lifetime, Animal *owner, s16 arg6, u8 id) {
    struct071 *obj = spawn_object(id, x, z, func_80310EE4_722594(x, z, owner->unk160) >> 16, 0, 0, 0, 0, 0, scale);
    if (obj != NULL) {
        obj->unk15C = 50;
        obj->owner = owner;
        obj->unk154 = lifetime;
        obj->unk15E = arg6 * 8;
    }
}

// free all things, unused?
void func_802FF140_7107F0(void) {
    s16 i;

    D_803A5330_7B69E0 = 0;
    for (i = 0; i < 10; i++) {
        D_803E1BE8[i].used = 0;
    }
}

// add <thing>
// ESA: func_80056F70
void func_802FF184_710834(Animal *arg0, s16 used, s16 x, s16 y, s16 z, s16 arg5, s16 arg6, s16 size, s16 arg8, s16 arg9) {
    s16 i;

    if (D_803A5330_7B69E0 < 10) {
        for (i = 0; i < 10; i++) {
            if (D_803E1BE8[i].used == 0) {
                D_803E1BE8[i].x = x;
                D_803E1BE8[i].y = y;
                D_803E1BE8[i].used = used; // ? always 1
                D_803E1BE8[i].unk1 = 0;
                D_803E1BE8[i].z = z;
                D_803E1BE8[i].unkC = size; // size?
                D_803E1BE8[i].unkE = arg8;
                D_803E1BE8[i].unk10 = arg9;
                D_803E1BE8[i].unk14 = arg0;
                D_803E1BE8[i].unkA = arg5;
                D_803E1BE8[i].unk8 = arg6;
                D_803A5330_7B69E0 += 1;
                break;
            }
        }
    }
}

void func_802FF25C_71090C(void) {
    s16 i;
    s16 enabled;
    s32 temp_t4;

    for (i = 0; i < 10; i++) {
        if (D_803E1BE8[i].used == 1) {
            do { temp_t4 = (((D_803E1BE8[i].unkC * D_803E1BE8[i].unk1) * 65536) / 100) / 16; } while (0);
            func_80125FE0(
                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                D_803E1BE8[i].x << 16,
                D_803E1BE8[i].y << 16,
                D_803E1BE8[i].z << 16,
                D_803E1BE8[i].unk8,
                D_803E1BE8[i].unkA,
                temp_t4,
                temp_t4,
                temp_t4);

            gSPMatrix(D_801D9E90++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPPipeSync(D_801D9E90++);

            gSPDisplayList(D_801D9E90++, D_01004970_3E240);

            gDPSetPrimColor(D_801D9E90++, 0, 0, 255, MIN(255, 256 - (D_803E1BE8[i].unk1 << 4)), 0, 128 - (D_803E1BE8[i].unk1 << 3));

            gSPDisplayList(D_801D9E90++, D_0101B000_548D0);
            gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

            if (D_803E1BE8[i].unk1 == 0) {
                enabled = D_803E1BE8[i].unkE;
            } else {
                enabled = 0;
            }

            func_802F7940_708FF0(
                D_803E1BE8[i].unk14,
                D_803E1BE8[i].x,
                D_803E1BE8[i].y,
                D_803E1BE8[i].z,
                enabled,
                0,                    // minDistance?
                D_803E1BE8[i].unkC,   // maxDistance?
                D_803E1BE8[i].unk10); // animal class maybe?

            D_803E1BE8[i].unk1++;

            if (D_803E1BE8[i].unk1 >= 16) {
                D_803E1BE8[i].used = 0;
                D_803A5330_7B69E0 -= 1;
            }
        }
    }
}

// used by OBJECT_SPEAKER
// ESA: func_8005764C
void func_802FF540_710BF0(struct071 *arg0) {
    s32 dist;
    s32 phi_t2;

    if (D_803A52D4_7B6984 != 0) {
        D_803A52D4_7B6984 -= 1;
    }

    if (D_803E8E57 != 0) {
        dist = ABS(arg0->position.xPos.h - (s16) (s32) D_803F2C44) +
               ABS(arg0->position.zPos.h - (s16) (s32) D_803F2C48) +
               ABS(arg0->position.yPos.h - (s16) (s32) D_803F2C4C);
        if (dist < 512) {
            phi_t2 = 256;
        } else if (dist < 5120) {
            phi_t2 = 256 - (((dist << 8) - FTOFIX32(2.0)) / FTOFIX32(0.0703125));
        } else {
            phi_t2 = 0;
        }
    } else {
        phi_t2 = 256;
    }

    dist = ABS(arg0->position.xPos.h - D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.xPos.h) +
           ABS(arg0->position.zPos.h - D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.zPos.h) +
           ABS(arg0->position.yPos.h - D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.yPos.h);

    if ((dist < 192) && (D_803A52D4_7B6984 == 0) &&
        ((D_801552B0 != 0) || (D_803F2D24 != 0))) {
        if (dist < 128) {
            do_rumble(0, 2, 40, 40, dist * 4);
        } else {
            do_rumble(0, 1, 40, 40, dist * 4);
        }
        D_803A52D4_7B6984 = 5;
    }
    if (D_803E1BE0 < phi_t2) {
        D_803E1BE0 = phi_t2;
    }
    D_8015517C = (f32)D_803E1BE0 / 256;
    D_8028645A += 1;
}

// used by object 140
// ESA: func_800578EC
void func_802FF7D4_710E84(struct071 *arg0) {
    create_particle_effect(
        arg0->position.xPos.h,
        arg0->position.zPos.h,
        arg0->position.yPos.h,
        124,
        0,
        0,
        0,
        20,
        GPACK_RGBA5551(0, 0, 0, 0),
        GPACK_RGBA5551(0, 0, 0, 0),
        0);
}

// used by object 79
// ESA: func_8005793C
void func_802FF828_710ED8(struct071 *arg0) {
    // trigger if below water?
    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        run_commands(arg0);
    }

    add_regular_trail(arg0, 0, (arg0->unk40 * 0x28) >> 11, 16, 0, 0, 0, 0, 0, 0xFF, 0x9B, 0x9B, 0xFF, 0xFF, 0xFF, 0xFF, 1, 1, arg0);
    add_regular_trail(arg0, 1, (arg0->unk40 * 0x28) >> 11, 16, 0, 0, 0, 0, 0, 0xFF, 0x9B, 0x9B, 0xFF, 0xFF, 0xFF, 0xFF, 1, 1, arg0 + 5);
}

// used by object 39
// ESA: func_80057D0C
void func_802FFA20_7110D0(struct071 *arg0) {
    if (arg0->position.yPos.h < (GET_WATER_LEVEL(D_803C0740, arg0->position.xPos.h, arg0->position.zPos.h) * 4)) {
        run_commands(arg0);
        return;
    }
    if (arg0->unk154 == 0) {
        arg0->unk154 = 100;
    }
    add_regular_trail(arg0, 0, (arg0->unk40 * 0x28) >> 11, 8, 0, 0, 0, 0x64, 0x64, 0xFF, 0x9B, 0x9B, 0xFF, 0xFF, 0xFF, 0xFF, 1, 1, arg0);
    add_regular_trail(arg0, 1, (arg0->unk40 * 0x28) >> 11, 8, 0, 0, 0, 0x64, 0x64, 0xFF, 0x9B, 0x9B, 0xFF, 0xFF, 0xFF, 0xFF, 1, 1, arg0 + 5);
}

u8 *D_803A8370_7B9A20[];
// used by object 168
// stubbed out in ESA?
void func_802FFC34_7112E4(struct071 *arg0) {
    s32 pad;
    s32 phi_v1;
    s32 temp_t4;

    if (arg0->unk0 == 1) {
        phi_v1 = MIN(arg0->unk158, 0xFF);
        add_light_at_location(
            arg0->position.xPos.h,
            arg0->position.zPos.h,
            arg0->position.yPos.h,
            phi_v1,
            arg0->unk200,
            arg0->unk204,
            arg0->unk208);

        if ((arg0->unk163 & 8) == 0) { // probably a bitfield
            temp_t4 = (arg0->unk40 << 6) >> 0xB;
            func_8034BD20_75D3D0(
                arg0->position.xPos.h,
                arg0->position.zPos.h,
                arg0->position.yPos.h,
                (s16) ((arg0->yRotation << 8) / 360),
                D_803A8370_7B9A20[1],
                (s16) temp_t4,
                (s16) temp_t4,
                (s16) phi_v1,
                arg0->unk200,
                arg0->unk204,
                arg0->unk208,
                2,
                0);
        }
    }
}

// ESA: func_80058048
void func_802FFD50_711400(struct071 *arg0) {
    f32 sp34;
    f32 sp1C; // pad
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;

    temp_f16 = arg0->unk1C.w / 65536.0f;
    temp_f12 = arg0->unk20.w / 65536.0f;
    temp_f18 = arg0->unk24.w / 65536.0f;
    sp34 = sqrtf((temp_f16 * temp_f16) + (temp_f12 * temp_f12) + (temp_f18 * temp_f18));

    if (ABSF(sp34) > 0.0f) {
        temp_f14 = temp_f12 / sp34;
        if (temp_f14 == 0.0f) {
            temp_f14 = 0.001f;
        }

        arg0->yRotation = func_801286B8(temp_f16 / sp34, temp_f14);
        arg0->zRotation = func_8012835C((temp_f18 / sp34) * 256.0f);

        if ((arg0->zRotation < 0) || (arg0->zRotation > 360)) {
            arg0->zRotation = (arg0->zRotation + 1440) % 360;
        }
    }
}

// used by objects 74 & 180
// ESA: func_800581DC
void func_802FFE94_711544(struct071 *arg0) {
    arg0->Info.unk14E = (arg0->Info.unk14E + 1) & 0x1F;
    if ((arg0->unk200 & 1) != 0) {
        func_802FFD50_711400(arg0);
    }
}

// used by objects 200, 201, 202, 203, 204, 205, 206, 207, 225, 226
// ESA: func_80058218
void func_802FFED0_711580(struct071 *arg0) {
    if (arg0->unk158 != 0) {
        func_802FFD50_711400(arg0);
    }
}

// used by object 151
// ESA: func_80058248
void func_802FFEFC_7115AC(struct071 *arg0) {
    if (arg0->unk0 == 1) {
        if (arg0->Info.unk14E == 0) {
            arg0->Info.unk14E = 1;
            func_8034419C_75584C(arg0);
        }
    } else if (arg0->Info.unk14E == 1) {
        arg0->Info.unk14E = 0;
    }
}

// used by object 177
// ESA: func_800582A0
void func_802FFF50_711600(struct071 *arg0) {
    func_802FFED0_711580(arg0);
}

// used by OBJECT_RED_TV and OBJECT_TV_SCREEN
void func_802FFF70_711620(struct071 *arg0) {
    func_8032CED0_73E580(&arg0->unk20.h[1], SFX_UNKNOWN_159, 0x3000, 1.0f, 0, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 0, 0, 0);
}

// used by OBJECT_ENERGY_BALL*
void func_802FFFD0_711680(struct071 *arg0) {
    u8 red, green, blue;

    // same line required for regalloc
    if (arg0->unk16C->objectType == OBJECT_ENERGY_BALL) {
        // white
        red = 255; green = 255; blue = 255;
    } else if (arg0->unk16C->objectType == OBJECT_ENERGY_BALL_PURPLE_2) {
        // light pink
        red = 255; green = 160; blue = 255;
    } else if (arg0->unk16C->objectType == OBJECT_ENERGY_BALL_PURPLE) {
        // bright pink
        red = 255; green = 0; blue = 255;
    }

    add_light_at_location(
        arg0->position.xPos.h,
        arg0->position.zPos.h,
        arg0->position.yPos.h,
        128,
        red,
        green,
        blue);
    if ((arg0->unk163 & 8) == 0) {
        s32 tmp = (arg0->unk40 << 5) >> 11;
        func_8034BD20_75D3D0(
            arg0->position.xPos.h,
            arg0->position.zPos.h,
            arg0->position.yPos.h,
            ((arg0->yRotation << 8) / 360),
            D_803A8370_7B9A20[1],
            tmp,
            tmp,
            64,
            red,
            green,
            blue,
            2,
            0);
    }
}
