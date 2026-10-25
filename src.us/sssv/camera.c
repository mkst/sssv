
#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

void set_camera_mode(u8 cameraID, u8 arg1);
void func_8032FF94_741644(u8 cameraID);
void func_80332444_743AF4(u8 cameraID);
void func_80334470_745B20(u8 cameraID, u8);
void func_8033641C_747ACC(u8 cameraID, u8, u8);
void func_803378BC_748F6C(u8 cameraID);
void func_80337ECC_74957C(u8 cameraID);
void func_80338E1C_74A4CC(u8 cameraID);
void func_803391D0_74A880(u8 cameraID);
void func_80339238_74A8E8(u8 cameraID);
void func_803392A0_74A950(u8 cameraID);
void func_80339308_74A9B8(u8 cameraID);
void func_803394E4_74AB94(u8 cameraID, u8);
void func_8033AAC8_74C178(u8 cameraID);
void update_camera_from_waypoint(f32 *arg0, f32 *arg1, f32 *arg2, WaypointData *arg3, s16 arg4); // TBD
void func_8033B118_74C7C8(u8 cameraID);
void func_8033B440_74CAF0(u8 cameraID);
void func_8033B594_74CC44(u8 cameraID);
void func_8033B9B8_74D068(u8 cameraID);
void func_8033C054_74D704(u8 cameraID);
void func_8033C320_74D9D0(u8 cameraID);
s16  func_8033C814_74DEC4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8);
s16  func_8033C8EC_74DF9C(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16  func_8033D604_74ECB4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
s16  func_8033DF88_74F638(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9); // tbd
void func_8033E430_74FAE0(void);
void func_8033E6B8_74FD68(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
void func_8033EF94_750644(OSContPad *cont, u16 arg1);
void decrease_player_camera_distance(s16 arg0);
void func_80340E08_7524B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s8 arg5, s8 arg6, u8 arg7, s16 arg8);
void func_80340EA4_752554(struct062*, s16);
void func_803415BC_752C6C(void);
void func_80342550_753C00(Camera *arg0);
void update_camera_x_y_z(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80343438_754AE8(void);
void func_80343A50_755100(void);
void func_80343C44_7552F4(s16 arg0, s16 *arg1, s16 *arg2);
void func_80343F68_755618(void);
void func_80343F78_755628(void);
s16  func_80344158_755808(s16 arg0);


// ========================================================
// .bss (D_803F28D0 to D_803F2C18)
// ========================================================

u16  gCameraVisibilityMask[8];

Camera gCameras[2];
s16  gCameraId;
s16  D_803F2A9A; // always 255, used in lights.c
s16  D_803F2A9C;
s16  D_803F2A9E;
static u8   D_803F2AA0;
static u8   D_803F2AA1 UNUSED;
u8   gCameraUiState;
u8   D_803F2AA3;
u8   D_803F2AA4;
static u8   D_803F2AA5; // always 0, effectively unused
static u8   cameraSnapFlag; // mode re-init guard: snap pose instead of easing
static u8   cinematicCameraRequest; // latch forcing CAMERA_MODE_30 takeover

static f32  scriptedEyeX; // scripted view eye
static f32  scriptedEyeZ;
static f32  scriptedEyeY;

static f32  scriptedTargetX; // scripted view target
static f32  scriptedTargetZ;
static f32  scriptedTargetY;

static s32  D_803F2AC0 UNUSED;
static u8   D_803F2AC4 UNUSED;
static u8   cameraSettledFlag; // per-frame "mode update ran / pose achieved"
static u8   cameraAreaUnchanged; // per-frame "no camera/area change needed"
static s16  gPrevCameraId; // id of the non-current "previous" camera
static s16  gCameraShakeMagnitude; // decaying shake strength
static s16  gCameraSettleTimer; // 20-frame settle countdown gating the LOS probe
static Camera *gCamera; // ptr to current camera
static struct062 sAmbientCameraTrigger[1]; // default follow-player camera descriptor
static struct062 gCameraTriggerQueue[8]; // ring queue of pending camera triggers
static struct062 sImmediateCameraTrigger; // scratch descriptor, immediate fire
s16  D_803F2C18[3];
static s16  gCameraScriptTimer; // dwell timer for the queue head
static s16  gCameraScriptHead; // queue read/head index (mod 8)
static s16  gCameraScriptTail; // queue write/tail index (mod 8)
static u8   D_803F2C24[0x4] UNUSED;
s16  D_803F2C28;
static f32  sCameraFocusWorldX; // transition-blended focus world point
static f32  sCameraFocusWorldZ;
static f32  sCameraFocusWorldY;
static u8   gCameraFocusCellIndex; // area class of the focus point, feeds region lookup
f32  D_803F2C3C;

f32  D_803F2C40;

f32  gCameraEyeWorldX;
f32  gCameraEyeWorldZ;
f32  gCameraEyeWorldY;

static f32  sLookAtTargetX; // resolved look-at target, inc pan + shake
static f32  sLookAtTargetZ;
static f32  sLookAtTargetY;
f32  D_803F2C5C;
f32  D_803F2C60;
static f32  sCameraRightX; // camera right vector, X
static f32  sCameraRightZ; // camera right vector, Z
u8   D_803F2C6C;
u8   D_803F2C6D; // terminal_background thinks its an s8
static s16  playerCameraDistance; // player zoom index, feeds Camera.zoomIndex
static s16  savedPlayerCameraDistance; // snapshot for restore (fox dash)

// ========================================================
// .data
// ========================================================

#include "camera.data.h"
#include "camera_enums.h"

// ========================================================
// .text
// ========================================================

// ESA: func_80021154
void func_8032F950_741000(void) {
    s16 i;
    s16 phi_v0_2;

    cameraSettledFlag = 0;

    if (gCameras[gCameraId].followType != 1) {
        gCameraSettleTimer = 20;
    } else if (((gAnimalState.animals[gCurrentAnimalIndex].animal->xVelocity.w != 0) ||
                (gAnimalState.animals[gCurrentAnimalIndex].animal->zVelocity.w != 0)) ||
            (ABS(gAnimalState.animals[gCurrentAnimalIndex].animal->yVelocity.h) > 1)) {
        gCameraSettleTimer = 20;
    } else if (gCameraSettleTimer > 0) {
        gCameraSettleTimer--;
    }

    phi_v0_2 = D_803F2C18[0];
    if ((phi_v0_2 != 0) && ((phi_v0_2 == 1) || (phi_v0_2 == 2))) {
        D_803F2C18[1] += 1;
        if (D_803F2C18[1] >= D_803F2C18[2]) {
            D_803F2C18[0] = 0;
            D_803F2C18[1] = 0;
            phi_v0_2 = 0;
        }
    }
    switch (phi_v0_2) {
    case 0:
        set_camera_mode(gCameraId, 0);
        break;
    case 1:
        set_camera_mode(gCameraId, 0);
        if ((func_80344158_755808(gCameras[gCameraId].cameraMode) == CAMERA_MODE_NONE) &&
            (func_80344158_755808(gCameras[gPrevCameraId].cameraMode) != CAMERA_MODE_NONE)) {
            set_camera_mode(gPrevCameraId, 1);
        } else {
            set_camera_mode(gPrevCameraId, 0);
        }
        cameraSettledFlag = 0;
        break;
    case 2:
        if ((D_803F2C18[2] / 2) >= D_803F2C18[1]) {
            set_camera_mode(gPrevCameraId, 0);
        } else {
            if (((D_803F2C18[2] / 2) + 1) == D_803F2C18[1]) {
                cameraSnapFlag = 1;
                for (i = 0; i < 5; i++) {
                    if (gCameras[gCameraId].cameraMode != 23) {
                        set_camera_mode(gCameraId, 0);
                    }
                }
                cameraSnapFlag = 0;
            }
            set_camera_mode(gCameraId, 0);
        }
        cameraSettledFlag = 0;
    }

    func_80343438_754AE8();

    switch (D_803F2C18[0]) {
    default:
        D_803F2AA0 = 0;
        break;
    case 0:
        if (gCameras[gCameraId].followType == 1) {
            D_803F2AA0 = 0;
        } else {
            D_803F2AA0 = 1;
        }
        break;
    case 1:
    case 2:
        D_803F2AA0 = 0;
        if (gCameras[0].followType != 1) {
            D_803F2AA0 = 1;
        }
        if (gCameras[1].followType != 1) {
            D_803F2AA0 = 1;
        }
        break;
    }
}

// ESA: func_800214CC
void set_camera_mode(u8 cameraID, u8 arg1) {

    func_80342550_753C00(&gCameras[cameraID]);

    switch (gCameras[cameraID].cameraMode) {
    case CAMERA_MODE_1:
        func_80332444_743AF4(cameraID);
        break;
    case CAMERA_MODE_26:
        func_8032FF94_741644(cameraID);
        break;
    case CAMERA_MODE_2:
    case CAMERA_MODE_12:
        func_803378BC_748F6C(cameraID);
        break;
    case CAMERA_MODE_BEHIND_1:     // behind animal (Z mode?)
    case CAMERA_MODE_BEHIND_2:
        func_80337ECC_74957C(cameraID);
        break;
    case CAMERA_MODE_OVERHEAD_1:     // overhead, GTA style 1
        func_80338E1C_74A4CC(cameraID);
        break;
    case CAMERA_MODE_OVERHEAD_3:    // overhead, GTA style 3
        func_803391D0_74A880(cameraID);
        break;
    case CAMERA_MODE_OVERHEAD_4:    // overhead, GTA style 4
        func_80339238_74A8E8(cameraID);
        break;
    case CAMERA_MODE_OVERHEAD_5:    // overhead, GTA style 5
        func_803392A0_74A950(cameraID);
        break;
    case CAMERA_MODE_OVERHEAD_2:     // overhead GTA style 2
        func_803394E4_74AB94(cameraID, arg1);
        break;
    case CAMERA_MODE_6:
        func_80334470_745B20(cameraID, arg1);
        break;
    case CAMERA_MODE_7:     // like 6 but a little higher
        func_8033641C_747ACC(cameraID, 0, arg1);
        break;
    case CAMERA_MODE_FIXED_0:
        fix_camera_to_angle_offset(cameraID, 0.0f);
        break;
    case CAMERA_MODE_FIXED_128:
        fix_camera_to_angle_offset(cameraID, 128.0f);
        break;
    case CAMERA_MODE_FIXED_64:
        fix_camera_to_angle_offset(cameraID, 64.0f);
        break;
    case CAMERA_MODE_FIXED_192:
        fix_camera_to_angle_offset(cameraID, 192.0f);
        break;
    case CAMERA_MODE_FIXED_32:     // looking behind player, SE-ish
        fix_camera_to_angle_offset(cameraID, 32.0f);
        break;
    case CAMERA_MODE_FIXED_96:     // fixed, looking left
        fix_camera_to_angle_offset(cameraID, 96.0f);
        break;
    case CAMERA_MODE_FIXED_160:
        fix_camera_to_angle_offset(cameraID, 160.0f);
        break;
    case CAMERA_MODE_FIXED_224:    // fixed, looking right
        fix_camera_to_angle_offset(cameraID, 224.0f);
        break;
    case CAMERA_MODE_22:
        func_80339308_74A9B8(cameraID);
        break;
    case CAMERA_MODE_WAYPOINT_1:    // seem to crash game?
    case CAMERA_MODE_WAYPOINT_2:
        func_8033AAC8_74C178(cameraID);
        break;
    case CAMERA_MODE_ZOOM_SPIN:    // zoomed in, spin around player
        func_8033B118_74C7C8(cameraID);
        break;
    case CAMERA_MODE_30:    // seems to crash game?
        func_8033B440_74CAF0(cameraID);
        break;
    case CAMERA_MODE_27:
        func_8033C320_74D9D0(cameraID);
        break;
    case CAMERA_MODE_28:
        func_8033641C_747ACC(cameraID, 1, arg1);
        break;
    case CAMERA_MODE_29:    // seems to crash game?
        func_8033B594_74CC44(cameraID);
        break;
    case CAMERA_MODE_SPIN_1:    // spinning around player
    case CAMERA_MODE_SPIN_2:
        func_8033B9B8_74D068(cameraID);
        break;
    case CAMERA_MODE_228:
        func_8033C054_74D704(cameraID);
        break;
    case CAMERA_MODE_NONE:
    default:
        break;
    }
}

// ESA: func_80021750
void func_8032FF94_741644(u8 cameraID) {
    s32 pad2[4] UNUSED;

    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;

    s32 spC4; // pad

    f32 temp_f0_2;
    f32 var_f12_2;

    // s16 spBA;
    s16 i; // spBA

    f32 spB4;

    s16 spB2;
    s16 spB0;
    s16 var_v1;
    s16 var_v0;

    f32 var_f14;
    f32 var_f16;
    f32 var_f2;

    u8 temp_a0;

    s32 sp98; // pad

    // f32 spA0;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;

    s32 sp84; // pad

    u8 sp83;

    s16 sp66;
#ifdef BUGFIX
    // probably better as a float rather than short
    f32 sp5C;
#else
    s16 sp5C;
#endif

    gCamera = &gCameras[cameraID];

    spB2 = 2;

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }

    if (gCamera->heightOverride != -1) {
        gCamera->cameraHeight = gCamera->heightOverride;
    }
    gCamera->targetDistance = (D_803A6CF0_7B83A0[gCamera->zoomIndex+3] * gCamera->baseDistance) >> 4;
    gCamera->targetDistance = (gCamera->targetDistance * 75.0f) / MAX(D_803F2D50.fovY, 5.0f);

    var_v0 = gCamera->followSpeed;
    var_v0 = (D_803A6D08_7B83B8[gCamera->zoomIndex+3] * var_v0) >> 4;
    if (var_v0 == 0) {
        var_v0 = 10;
    }

    var_f14 = MIN(0.95, var_v0 * 0.025);

    spDC = gCamera->focusX;
    spD8 = gCamera->focusZ;
    spD4 = gCamera->focusY + 4.0;

    if ((NABS(spDC - gCamera->focusX) <= 10.0f) &&
        (ABS(spD8 - gCamera->focusZ) <= 10.0f) &&
        (ABS(spD4 - gCamera->focusY) <= 10.0f)) {
        cameraSettledFlag = 1;
    }

    spD0 = (var_f14 * spDC) - (var_f14 * gCamera->targetX);
    spCC = (var_f14 * spD8) - (var_f14 * gCamera->targetZ);
    spC8 = (var_f14 * spD4) - (var_f14 * gCamera->targetY);

    if (ABSF(spD0) < 0.1) {
        spD0 = 0.0f;
    }
    if (ABSF(spCC) < 0.1) {
        spCC = 0.0f;
    }
    if (ABSF(spC8) < 0.1) {
        spC8 = 0.0f;
    }

    if (ABSF(spD0) < ABSF(gCamera->targetVelX)) {
        sp90 = 0.0f;
    } else {
        sp90 = spD0 - gCamera->targetVelX;
    }
    if (ABSF(spCC) < ABSF(gCamera->targetVelZ)) {
        sp8C = 0.0f;
    } else {
        sp8C = spCC - gCamera->targetVelZ;
    }
    if (ABSF(spC8) < ABSF(gCamera->targetVelY)) {
        sp88 = 0.0f;
    } else {
        sp88 = spC8 - gCamera->targetVelY;
    }

    temp_f0_2 = sqrtf(SQ(sp90) + SQ(sp8C) + SQ(sp88));
    var_f2 = var_v0 * 0.04;

    if ((temp_f0_2 > 0.0) && ((var_f2 / temp_f0_2) < 1.0)) {
        if (sp90 != 0.0) {
            spD0 = gCamera->targetVelX + ((sp90 * var_f2) / temp_f0_2);
        }
        if (sp8C != 0.0) {
            spCC = gCamera->targetVelZ + ((sp8C * var_f2) / temp_f0_2);
        }
        if (sp88 != 0.0) {
            spC8 = gCamera->targetVelY + ((sp88 * var_f2) / temp_f0_2);
        }
        if (0) {};
    }

    gCamera->targetVelX = spD0;
    gCamera->targetVelZ = spCC;
    gCamera->targetVelY = spC8;

    gCamera->targetX += spD0;
    gCamera->targetZ += spCC;
    gCamera->targetY += spC8;

    if (cameraSnapFlag != 0) {
        gCamera->targetX = spDC;
        gCamera->targetZ = spD8;
        gCamera->targetY = spD4;
        gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
    }

    if (gCamera->followType == 1) {
        if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 1) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetY = gCamera->focusY + 4.0;
            gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
        } else if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 4) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetVelX = gCamera->targetVelZ = 0.0f;
            if (gAnimalState.animals[gCurrentAnimalIndex].animal->movementState == MOVEMENT_STATE_SWIMMING) {
                gCamera->targetY = gCamera->focusY + 4.0;
                gCamera->targetVelY = 0.0f;
            }
        }
    }

    sp94 = 0.0f;
    spB0 = 0;
    if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        spB0 = 1;
        spB2 = 4;
    } else if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance + 20.0, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        spB0 = 1;
        spB2 = 1;
        sp94 = 20.0f;
    } else if (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0) {
        spB0 = 1;
        spB2 = 1;
    }

    if (spB0 != 0) {
        for (i = 0; i < 25; i++) {
            if (i % 2) {
                spB4 = gCamera->targetYaw + (((i / 2) + 1) * 10.0);
            } else {
                spB4 = gCamera->targetYaw - (((i / 2) + 1) * 10.0);
            }
            if (spB4 >= 256.0) {
                spB4 -= 256.0;
            }
            if (spB4 < 0.0) {
                spB4 += 256.0;
            }
            if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, spB4, gCamera->targetDistance + sp94, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) {
                if (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, spB4, gCamera->targetDistance + sp94, gCamera->panOffsetX, gCamera->panOffsetZ) == 0) {
                    gCamera->targetYaw = spB4;
                    i = 1000;
                }
            }
            gCamera->targetYawOffset = 0.0f;
        }

    } else {
        sp83 = 0;
        sp5C = gCamera->targetYaw + 40.0;
        if (sp5C >= 256.0) {
            sp5C -= 256.0;
        }
        if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1) != 0) ||
            (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0)) {
            sp83 |= 8;
        }

        sp5C = gCamera->targetYaw + 20.0;
        if (sp5C >= 256.0) {
            sp5C -= 256.0;
        }
        if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1) != 0) ||
            (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0)) {
            sp83 |= 4;
        }

        sp5C = gCamera->targetYaw - 20.0;
        if (sp5C < 0.0) {
            sp5C += 256.0;
        }
        if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1) != 0) ||
            (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0)) {
            sp83 |= 2;
        }

        sp5C = gCamera->targetYaw - 40.0;
        if (sp5C < 0.0) {
            sp5C += 256.0;
        }
        if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1) != 0) ||
            (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0)) {
            sp83 |= 1;
        }

        if (sp83 == 0) {
            sp5C = (f64)gCamera->targetYaw + 20;
            if (sp5C >= 256.0) {
                sp5C -= 256.0;
            }
            if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
                sp83 |= 8;
            }

            sp5C = (f64)gCamera->targetYaw + 10;
            if (sp5C >= 256.0) {
                sp5C -= 256.0;
            }
            if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
                sp83 |= 4;
            }

            sp5C = (f64)gCamera->targetYaw - 10;
            if (sp5C < 0.0) {
                sp5C += 256.0;
            }
            if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
                sp83 |= 2;
            }

            sp5C = (f64)gCamera->targetYaw - 20;
            if (sp5C < 0.0) {
                sp5C += 256.0;
            }
            if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
                sp83 |= 1;
            }
        }

        temp_a0 = D_803A7B14_7B91C4[sp83];

        if (gCamera->panCooldown > 0) {
            gCamera->panCooldown--;
        }

        if ((temp_a0 & 0x40) == 0) {
            if (temp_a0 & 0x3C) {   // 00111100
                if (temp_a0 & 8) {
                    var_f14 = 10.0f;
                } else if (temp_a0 & 4) {
                    var_f14 = -10.0f;
                } else if (temp_a0 & 0x20) {
                    var_f14 = 1.0f;
                } else {
                    var_f14 = -1.0f;
                }
                if (gCamera->targetYawOffset < var_f14) {
                    gCamera->targetYawOffset = MIN(gCamera->targetYawOffset + 3.0, var_f14);
                } else {
                    gCamera->targetYawOffset = MAX(gCamera->targetYawOffset - 3.0, var_f14);
                }
                gCamera->targetYaw += gCamera->targetYawOffset;
            } else {
                var_f14 = 0.0f;
                if (gCamera->targetYawOffset < var_f14) {
                    gCamera->targetYawOffset = MIN(gCamera->targetYawOffset + 3.0, var_f14);
                } else {
                    gCamera->targetYawOffset = MAX(gCamera->targetYawOffset - 3.0, var_f14);
                }
                gCamera->targetYaw += gCamera->targetYawOffset;

                if ((gCamera->followType == 1) && (cameraSnapFlag == 0) && (gCamera->panCooldown <= 0)) {
                    var_f2 = gAnimalState.animals[gCurrentAnimalIndex].animal->heading - gCamera->targetYaw;
                    if (var_f2 < -128.0) {
                        var_f2 += 256.0;
                    }
                    if (var_f2 > 128.0) {
                        var_f2 -= 256.0;
                    }

                    if (ABSF(var_f2) >= 118.0) {
                        var_f12_2 = 0.5f;
                    } else {
                        if (ABSF(var_f2) >= 78.0) {
                            var_f12_2 = ((118.0 - ABSF(var_f2)) * 0.05) + 0.5; // x / 20.0, but doesnt match (yet?)
                        } else if (ABSF(var_f2) >= 32.0) {
                            var_f12_2 = 2.5f;
                        } else if (ABSF(var_f2) <= 8.0) {
                            var_f12_2 = 0.5f;
                        } else {
                            var_f12_2 = ((ABSF(var_f2) - 8.0) * 0.08333333333333333) + 0.5; // x / 12.0, but doesnt match (yet?)
                        }
                    }

                    if (((temp_a0 & 1) == 0) && (var_f2 < 0.0f)) {
                        var_f2 = 0.0f;
                    }
                    if (((temp_a0 & 2) == 0) && (var_f2 > 0.0f)) {
                        var_f2 = 0.0f;
                    }

                    if (ABSF(var_f2) < var_f12_2) {
                        gCamera->targetYaw += var_f2;
                    } else if (var_f2 < 0.0) {
                        gCamera->targetYaw -= var_f12_2;
                    } else {
                        gCamera->targetYaw += var_f12_2;
                    }
                }
            }
        }
    }

    gCamera->targetPitch = var_f2 = (D_803A6CFC_7B83AC[gCamera->zoomIndex+3] * gCamera->cameraHeight) >> 4;
    var_v1 = 4;
    while (var_f2 > -20.0) {
        if (func_8033C8EC_74DF9C(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, var_f2, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0) {
            if ((var_f2 == gCamera->targetPitch) || (gCamera->pitch < var_f2)) {
                var_v1 = 1;
            }
            gCamera->targetPitch = var_f2;
            var_f2 = -400.0;
        }
        var_f2 -= 4.0;
    }

    var_f12_2 = ((var_v1 * 0.06) * gCamera->targetPitch) - ((var_v1 * 0.06) * gCamera->pitch);
    if (ABSF(var_f12_2) < 0.05) {
        var_f12_2 = 0.0f;
    }
    if (ABSF(var_f12_2) > ABSF(gCamera->pitchVelocity)) {
        if (var_f12_2 > 0.0f) {
            var_f12_2 = MIN(var_f12_2, gCamera->pitchVelocity + 0.4);
        } else {
            var_f12_2 = MAX(var_f12_2, gCamera->pitchVelocity - 0.4);
        }
    }
    gCamera->pitchVelocity = var_f12_2;
    gCamera->pitch += var_f12_2;

    if (gCamera->targetYaw < 0.0) {
        gCamera->targetYaw += 256.0;
    }
    if (gCamera->targetYaw >= 256.0) {
        gCamera->targetYaw -= 256.0;
    }

    var_f2 = (gCamera->targetYaw - gCamera->yaw);
    if (var_f2 > 128.0) {
        var_f2 -= 256.0;
    }
    if (var_f2 < -128.0) {
        var_f2 += 256.0;
    }
    var_f2 = var_f2 * (0.09 * spB2);
    if (ABSF(var_f2) < 0.1) {
        var_f2 = 0.0f;
    }
    if (ABSF(var_f2) > ABSF(gCamera->yawVelocity)) {
        if (var_f2 > 0.0f) {
            var_f2 = MIN(var_f2, gCamera->yawVelocity + spB2);
        } else {
            var_f2 = MAX(var_f2, gCamera->yawVelocity - spB2);
        }
    }

    gCamera->yawVelocity = var_f2;
    gCamera->yaw += var_f2;
    if (gCamera->yaw >= 256.0) {
        gCamera->yaw -= 256.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 256.0;
    }

    var_f16 = (gCamera->targetDistance - gCamera->distance) * 0.09;
    if (ABSF(var_f16) < 0.5) {
        var_f16 = 0.0f;
    }
    if ((ABSF(var_f16) > ABSF(gCamera->distanceVelocity)) || (SIGNUMF(var_f16) != SIGNUMF(gCamera->distanceVelocity))) {
        if (var_f16 > 0.0f) {
            var_f16 = MIN(var_f16, gCamera->distanceVelocity + 10.0);
        } else {
            var_f16 = MAX(var_f16, gCamera->distanceVelocity - 10.0);
        }
    }

    gCamera->distanceVelocity = var_f16;
    var_f2 = gCamera->distance;
    gCamera->distance = var_f2 + var_f16;
    gCamera->lateralPanX *= gCamera->distance / var_f2;
    gCamera->lateralPanZ *= gCamera->distance / var_f2;
    gCamera->lateralPanVelX *= gCamera->distance / var_f2;
    gCamera->lateralPanVelZ *= gCamera->distance / var_f2;
    func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY);

    if (gCamera->followSpeed != gCamera->targetFollowSpeed) {
        if (gCamera->followSpeed < gCamera->targetFollowSpeed) {
            gCamera->followSpeed++;
        } else {
            gCamera->followSpeed--;
        }
    }

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    sp5C = (gCamera->targetYaw + 32.0) + 20.0;
    if (sp5C >= 256.0) {
        sp5C -= 256.0;
    }

    if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ)) == 0) {
        gCamera->panLeftAvailable = 1;
    } else {
        gCamera->panLeftAvailable = 0;
    }

    sp5C = (gCamera->targetYaw - 32.0) - 20.0;
    if (sp5C < 0.0) {
        sp5C += 256.0;
    }
    if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, gCamera->targetPitch, sp5C, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ)) == 0) {
        gCamera->panRightAvailable = 1;
    } else {
        gCamera->panRightAvailable = 0;
    }

    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->pitch = gCamera->targetPitch;
        gCamera->pitchVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
}

void func_80332444_743AF4(u8 arg0) {
    s32 pad[4] UNUSED;

    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;

    f32 temp_f0_2;
    f32 var_f12_3;
    f32 var_f14;
    s16 i;
    f32 var_f16;    // spB4 ?

    f32 var_f2_3;   // spB0 ?
    f32 var_f2_2;   // spAC ?
    s16 spAA;

    s16 var_t0;
    s16 var_t0_2;
    s16 spA4;
    s16 var_v0;

    f32 var_f20;

    f32 var_f12_2; // sp98 ?
    f32 sp94;
    f32 sp90;
    f32 sp8C;

    f32 temp_f2_5; // sp88 ?
    f32 sp84;

    s8 var_a0;
    s8 temp_t0;
    s8 var_t1;
    s8 var_t2;

    gCamera = &gCameras[arg0];

    spAA = 2;

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }

    if (gCamera->heightOverride != -1) {
        gCamera->cameraHeight = gCamera->heightOverride;
    }

    gCamera->targetDistance = (D_803A6CF0_7B83A0[gCamera->zoomIndex+3] * gCamera->baseDistance) >> 4;
    gCamera->targetDistance = (gCamera->targetDistance * 75.0f) / MAX(D_803F2D50.fovY, 5.0f);

    var_v0 = gCamera->followSpeed;
    var_v0 = (D_803A6D08_7B83B8[gCamera->zoomIndex+3] * var_v0) >> 4;
    if (var_v0 == 0) {
        var_v0 = 10;
    }

    var_f14 = MIN(0.95, var_v0 * 0.025);

    spDC = gCamera->focusX;
    spD8 = gCamera->focusZ;
    spD4 = gCamera->focusY + 4.0;

    if ((ABS(spDC - gCamera->focusX) <= 10.0f) &&
        (ABS(spD8 - gCamera->focusZ) <= 10.0f) &&
        (ABS(spD4 - gCamera->focusY) <= 10.0f)) {
        cameraSettledFlag = 1;
    }

    spD0 = (var_f14 * spDC) - (var_f14 * gCamera->targetX);
    spCC = (var_f14 * spD8) - (var_f14 * gCamera->targetZ);
    spC8 = (var_f14 * spD4) - (var_f14 * gCamera->targetY);

    if (ABSF(spD0) < 0.1) {
        spD0 = 0.0f;
    }
    if (ABSF(spCC) < 0.1) {
        spCC = 0.0f;
    }
    if (ABSF(spC8) < 0.1) {
        spC8 = 0.0f;
    }

    if (ABSF(spD0) < ABSF(gCamera->targetVelX)) {
        sp94 = 0.0f;
    } else {
        sp94 = spD0 - gCamera->targetVelX;
    }

    if (ABSF(spCC) < ABSF(gCamera->targetVelZ)) {
        sp90 = 0.0f;
    } else {
        sp90 = spCC - gCamera->targetVelZ;
    }

    if (ABSF(spC8) < ABSF(gCamera->targetVelY)) {
        sp8C = 0.0f;
    } else {
        sp8C = spC8 - gCamera->targetVelY;
    }

    temp_f0_2 = sqrtf(SQ(sp94) + SQ(sp90) + SQ(sp8C));
    temp_f2_5 = var_v0 * 0.05;

    if (temp_f0_2 > 0.0) {
        if ((temp_f2_5 / temp_f0_2) < 1.0) {
            if (sp94 != 0.0) {
                spD0 = gCamera->targetVelX + ((sp94 * temp_f2_5) / temp_f0_2);
            }
            if (sp90 != 0.0) {
                spCC = gCamera->targetVelZ + ((sp90 * temp_f2_5) / temp_f0_2);
            }
            if (sp8C != 0.0) {
                spC8 = gCamera->targetVelY + ((sp8C * temp_f2_5) / temp_f0_2);
            }
        }
        if (0) {};
    }

    gCamera->targetVelX = spD0;
    gCamera->targetVelZ = spCC;
    gCamera->targetVelY = spC8;

    gCamera->targetX += spD0;
    gCamera->targetZ += spCC;
    gCamera->targetY += spC8;

    if (cameraSnapFlag != 0) {
        gCamera->targetX = spDC;
        gCamera->targetZ = spD8;
        gCamera->targetY = spD4;
        gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
    }

    if (gCamera->followType == 1) {
        if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 1) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetY = gCamera->focusY + 4.0;
            gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
        } else if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 4) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetVelX = gCamera->targetVelZ = 0.0f;
            if (gAnimalState.animals[gCurrentAnimalIndex].animal->movementState == MOVEMENT_STATE_SWIMMING) {
                gCamera->targetY = gCamera->focusY + 4.0;
                gCamera->targetVelY = 0.0f;
            }
        }
    }

    sp84 = 0.0f;
    var_t0 = 0;
    if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        var_t0 = 1;
        spAA = 4;
    } else if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance + 20.0, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        var_t0 = 1;
        spAA = 1;
        sp84 = 20.0f;
    } else if (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0) {
        var_t0 = 1;
        spAA = 1;
    }

    if (var_t0 != 0) {
        for (i = 0; i < 25; i++) {
            if (i % 2) {
                var_f20 = gCamera->targetYaw + (((i / 2) + 1) * 10.0);
            } else {
                var_f20 = gCamera->targetYaw - (((i / 2) + 1) * 10.0);
            }

            if (var_f20 >= 256.0) {
                var_f20 -= 256.0;
            }
            if (var_f20 < 0.0) {
                var_f20 += 256.0;
            }
            if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance + sp84, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) &&
                (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance + sp84, gCamera->panOffsetX, gCamera->panOffsetZ) == 0)){
                  gCamera->targetYaw = var_f20;
                  i = 1000;
            }
        }
    } else {
        var_f20 = gCamera->targetYaw - 20.0;
        if (var_f20 < 0.0) {
            var_f20 += 256.0;
        }

        spA4 = func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ);
        var_f20 = gCamera->targetYaw + 20.0;
        if (var_f20 >= 256.0) {
            var_f20 -= 256.0;
        }

        var_t0_2 = func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ);
        if ((spA4 == 0) && (var_t0_2 != 0)) {
            var_f20 = gCamera->targetYaw - 40.0;
            if (var_f20 < 0.0) {
                var_f20 += 256.0;
            }
            if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) &&
                (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0)) {
                gCamera->targetYaw = gCamera->targetYaw - 2.0;
                if (gCamera->targetYaw < 0.0) {
                    gCamera->targetYaw += 256.0;
                }
            }
        } else if ((spA4 != 0) && (var_t0_2 == 0)) {
            var_f20 = gCamera->targetYaw + 40.0;
            if (var_f20 >= 256.0) {
                var_f20 -= 256.0;
            }
            if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) &&
                (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0)) {
                gCamera->targetYaw = gCamera->targetYaw + 2.0;
                if (gCamera->targetYaw > 256.0) {
                    gCamera->targetYaw -= 256.0;
                }
            }
        } else if ((spA4 == 0) && (var_t0_2 == 0)) {

            temp_t0 = 0;
            var_a0 = 0;
            var_t2 = 0;
            var_t1 = 0;
            var_f12_2 = 40.0f;

            while ((var_f12_2 < 95.0) && (var_t1 == 0) && (var_t2 == 0)) {
                var_t1 = var_a0; // backup previous?
                var_t2 = temp_t0;

                var_f20 = gCamera->targetYaw - var_f12_2;
                if (var_f20 < 0.0) {
                    var_f20 += 256.0;
                }

                temp_t0 = func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1);
                var_f20 = gCamera->targetYaw + var_f12_2;
                if (var_f20 >= 256.0) {
                    var_f20 -= 256.0;
                }

                var_a0 = func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1);
                var_f12_2 += 20.0;
            }

            if (var_f12_2 < 95.0) {
                if ((var_a0 == 0) && (var_t1 == 0)) {
                    gCamera->targetYaw = gCamera->targetYaw + 0.5;
                    if (gCamera->targetYaw > 256.0) {
                        gCamera->targetYaw -= 256.0;
                    }
                } else if ((temp_t0 == 0) && (var_t2 == 0)) {
                    gCamera->targetYaw = gCamera->targetYaw - 0.5;
                    if (gCamera->targetYaw < 0.0) {
                        gCamera->targetYaw += 256.0;
                    }
                }
            }
        }
    }

    if (gCamera->targetYaw < 0.0) {
        gCamera->targetYaw += 256.0;
    }
    if (gCamera->targetYaw >= 256.0) {
        gCamera->targetYaw -= 256.0;
    }


    gCamera->targetPitch = var_f2_2 = ((D_803A6CFC_7B83AC[gCamera->zoomIndex+3]) * gCamera->cameraHeight) >> 4;
    var_t0_2 = 4;
    while (var_f2_2 > -20.0) {
        spA4 = func_8033C8EC_74DF9C(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, var_f2_2, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ);
        if (spA4 == 0) {
            if ((var_f2_2 == gCamera->targetPitch) || (gCamera->pitch < var_f2_2)) {
                var_t0_2 = 1;
            }

            gCamera->targetPitch = var_f2_2;
            // break
            var_f2_2 = -400.0;
        }
        var_f2_2 -= 4.0;
    }

    var_f12_3 = ((var_t0_2 * 0.06) * gCamera->targetPitch) - ((var_t0_2 * 0.06) * gCamera->pitch);
    if (ABSF(var_f12_3) < 0.05) {
        var_f12_3 = 0.0f;
    }

    if (ABSF(var_f12_3) > ABSF(gCamera->pitchVelocity)) {
        if (var_f12_3 > 0.0f) {
            var_f12_3 = MIN(var_f12_3, gCamera->pitchVelocity + 0.4);
        } else {
            var_f12_3 = MAX(var_f12_3, gCamera->pitchVelocity - 0.4);
        }
    }

    gCamera->pitchVelocity = var_f12_3;
    gCamera->pitch += var_f12_3;
    if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->yaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        spAA = 4;
    }

    var_f2_3 = gCamera->targetYaw - gCamera->yaw;
    if (var_f2_3 > 128.0) {
        var_f2_3 -= 256.0;
    }
    if (var_f2_3 < -128.0) {
        var_f2_3 += 256.0;
    }

    var_f2_3 = var_f2_3 * (0.09 * spAA);
    if (ABSF(var_f2_3) < 0.1) {
        var_f2_3 = 0.0f;
    }

    if (ABSF(var_f2_3) > ABSF(gCamera->yawVelocity)) {
        if (var_f2_3 > 0.0f) {
            var_f2_3 = MIN(var_f2_3, gCamera->yawVelocity + spAA);
        } else {
            var_f2_3 = MAX(var_f2_3, gCamera->yawVelocity - spAA);
        }
    }
    gCamera->yawVelocity = var_f2_3;
    gCamera->yaw += var_f2_3;
    if (gCamera->yaw >= 256.0) {
        gCamera->yaw -= 256.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 256.0;
    }

    var_f16 = (gCamera->targetDistance - gCamera->distance) * 0.18;
    if (ABSF(var_f16) < 0.5) {
        var_f16 = 0.0f;
    }

    if ((ABSF(var_f16) > ABSF(gCamera->distanceVelocity)) || (SIGNUMF(var_f16) != SIGNUMF(gCamera->distanceVelocity))) {
        if (var_f16 > 0.0f) {
            var_f16 = MIN(var_f16, gCamera->distanceVelocity + 10.0);
        } else {
            var_f16 = MAX(var_f16, gCamera->distanceVelocity - 10.0);
        }
    }

    gCamera->distanceVelocity = var_f16;
    temp_f2_5 = gCamera->distance;
    gCamera->distance += var_f16;
    gCamera->lateralPanX *= gCamera->distance / temp_f2_5;
    gCamera->lateralPanZ *= gCamera->distance / temp_f2_5;
    gCamera->lateralPanVelX *= gCamera->distance / temp_f2_5;
    gCamera->lateralPanVelZ *= gCamera->distance / temp_f2_5;
    func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY);

    if (gCamera->followSpeed != gCamera->targetFollowSpeed) {
        if (gCamera->followSpeed < gCamera->targetFollowSpeed) {
            gCamera->followSpeed++;
        } else {
            gCamera->followSpeed--;
        }
    }

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    var_f20 = gCamera->targetYaw + 32.0;
    if (var_f20 >= 256.0) {
        var_f20 -= 256.0;
    }

    if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ)) == 0) {
        gCamera->panLeftAvailable = 1;
    } else {
        gCamera->panLeftAvailable = 0;
    }
    var_f20 = gCamera->targetYaw - 32.0;
    if (var_f20 < 0.0) {
        var_f20 += 256.0;
    }

    if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 1) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, var_f20, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ)) == 0) {
        gCamera->panRightAvailable = 1;
    } else {
        gCamera->panRightAvailable = 0;
    }

    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->pitch = gCamera->targetPitch;
        gCamera->pitchVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
}

// ESA: func_80023020
void func_80334470_745B20(u8 id, u8 arg1) {
    s32 pad[3] UNUSED;

    f32 sp100;
    f32 spFC;
    f32 spF8; // pad
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;

    s32 pad2[3] UNUSED;

    s16 i; // spD2 ?
    s16 spD0; // pad

    f32 spCC;
    f32 spC8; // pad

    f32 var_f2; // spC4 ?
    s16 spC2;
    s16 spC0;
    s16 var_v1; // spBE
    s16 spBC;

    s32 spB8; // pad

    f32 spB4;
    f32 spB0;
    f32 spAC;

    s16 var_v0;

    f32 spA4;

    f32 var_f12;
    f32 var_f14;
    f32 var_f16;

    f32 sp94;
    f32 sp90;
    f32 sp8C;

    f32 var_f0;

    f32 new_var;

    gCamera = &gCameras[id];

    spC2 = 2;

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }

    if (gCamera->heightOverride != -1) {
        gCamera->cameraHeight = gCamera->heightOverride;
    }
    gCamera->targetDistance = (D_803A6CF0_7B83A0[gCamera->zoomIndex+3] * gCamera->baseDistance) >> 4;
    gCamera->targetDistance = (gCamera->targetDistance * 75.0f) / MAX(D_803F2D50.fovY, 5.0f);

    var_v0 = gCamera->followSpeed;
    var_v0 = (D_803A6D08_7B83B8[gCamera->zoomIndex+3] * var_v0) >> 4;
    if (var_v0 == 0) {
        var_v0 = 10;
    }
    var_f14 = MIN(0.95, var_v0 * 0.025);

    spF4 = gCamera->focusX;
    spF0 = gCamera->focusZ;
    spEC = gCamera->focusY + 4.0;

    if ((ABS(spF4 - gCamera->focusX) <= 10.0f) &&
        (ABS(spF0 - gCamera->focusZ) <= 10.0f) &&
        (ABS(spEC - gCamera->focusY) <= 10.0f)) {
        cameraSettledFlag = 1;
    }

    spE8 = (var_f14 * spF4) - (var_f14 * gCamera->targetX);
    spE4 = (var_f14 * spF0) - (var_f14 * gCamera->targetZ);
    spE0 = (var_f14 * spEC) - (var_f14 * gCamera->targetY);

    if (ABSF(spE8) < 0.1) {
        spE8 = 0.0f;
    }
    if (ABSF(spE4) < 0.1) {
        spE4 = 0.0f;
    }
    if (ABSF(spE0) < 0.1) {
        spE0 = 0.0f;
    }

    if (ABSF(spE8) < ABSF(gCamera->targetVelX)) {
        spB4 = 0.0f;
    } else {
        spB4 = spE8 - gCamera->targetVelX;
    }
    if (ABSF(spE4) < ABSF(gCamera->targetVelZ)) {
        spB0 = 0.0f;
    } else {
        spB0 = spE4 - gCamera->targetVelZ;
    }
    if (ABSF(spE0) < ABSF(gCamera->targetVelY)) {
        spAC = 0.0f;
    } else {
        spAC = spE0 - gCamera->targetVelY;
    }

    var_f0 = sqrtf(SQ(spB4) + SQ(spB0) + SQ(spAC));
    var_f2 = var_v0 * 0.05;
    if (var_f0 > 0.0) {
        if ((var_f2 / var_f0) < 1.0) {
            if (spB4 != 0.0) {
                spE8 = gCamera->targetVelX + ((spB4 * var_f2) / var_f0);
            }
            if (spB0 != 0.0) {
                spE4 = gCamera->targetVelZ + ((spB0 * var_f2) / var_f0);
            }
            if (spAC != 0.0) {
                spE0 = gCamera->targetVelY + ((spAC * var_f2) / var_f0);
            }
        }
        if (0) {}; // tbd
    }

    gCamera->targetVelX = spE8;
    gCamera->targetVelZ = spE4;
    gCamera->targetVelY = spE0;

    gCamera->targetX += spE8;
    gCamera->targetZ += spE4;
    gCamera->targetY += spE0;

    if (cameraSnapFlag != 0) {
        gCamera->targetX = spF4;
        gCamera->targetZ = spF0;
        gCamera->targetY = spEC;
        gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
    }
    if (gCamera->followType == 1) {
        if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 1) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetY = gCamera->focusY + 4.0;
            gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;

        } else if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 4) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetVelX = gCamera->targetVelZ = 0.0f;
            if (gAnimalState.animals[gCurrentAnimalIndex].animal->movementState == MOVEMENT_STATE_SWIMMING) {
                gCamera->targetY = gCamera->focusY + 4.0;
                gCamera->targetVelY = 0.0f;
            }
        }
    }

    spA4 = 0.0f;
    spC0 = 0;
    if (func_8033C814_74DEC4(gCamera->focusX,gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        spC0 = 1;
        spC2 = 4;
    } else if (func_8033C814_74DEC4(gCamera->focusX,gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance + 20.0, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        spC0 = 1;
        spC2 = 1;
        spA4 = 20.0f;
    } else if (func_8033D604_74ECB4(gCamera->focusX,gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) != 0) {
        spC0 = 1;
        spC2 = 1;
    }

    if (spC0 != 0) {
        for (i = 0; i < 25; i++) {
            if (i % 2) {
                spCC = gCamera->targetYaw + (((i / 2) + 1) * 10.0);
            } else {
                spCC = gCamera->targetYaw - (((i / 2) + 1) * 10.0);
            }
            if (spCC >= 256.0) {
                spCC -= 256.0;
            }
            if (spCC < 0.0) {
                spCC += 256.0;
            }
            if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance + spA4, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) &&
                (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance + spA4, gCamera->panOffsetX, gCamera->panOffsetZ) == 0)) {
                gCamera->targetYaw = spCC;
                i = 1000;
            }
        }
    } else {
        spCC = gCamera->targetYaw - 20.0;
        if (spCC < 0.0) {
            spCC += 256.0;
        }

        spBC = func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ);
        spCC = gCamera->targetYaw + 20.0;
        if (spCC >= 256.0) {
            spCC -= 256.0;
        }

        var_v1 = func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) | func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ);
        if ((spBC == 0) && (var_v1 != 0)) {
            spCC = gCamera->targetYaw - 40.0;
            if (spCC < 0.0) {
                spCC += 256.0;
            }
            if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) &&
                (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0)) {
                gCamera->targetYaw -= 2.0;
                if (gCamera->targetYaw < 0.0) {
                    gCamera->targetYaw += 256.0;
                }
            }
        } else if ((spBC != 0) && (var_v1 == 0)) {
            spCC = gCamera->targetYaw + 40.0;
            if (spCC >= 256.0) {
                spCC -= 256.0;
            }
            if ((func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) &&
                (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, spCC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0)) {
                gCamera->targetYaw += 2.00;
                if (gCamera->targetYaw > 256.0) {
                    gCamera->targetYaw -= 256.0;
                }
            }
        } else if ((spBC == 0) && (var_v1 == 0)) {

            if (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType != EVO) {
                spA4 = gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation;
                sp100 = spA4 - gCamera->targetYaw;
            } else {
                sp100 = 0.0f;
            }

            if (arg1 != 0) {
                sp100 = 0.0f;
            }
            if (sp100 < -128.0) {
                sp100 += 256.0;
            }
            if (sp100 > 128.0) {
                sp100 -= 256.0;
            }
            if (sp100 > 0.0) {
                spFC = 20.0f;
            } else {
                spFC = -20.0f;
            }
            spFC = spFC + sp100;
            if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw + sp100, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) {
                if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw + spFC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) == 0) {
                    if (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw + sp100, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0) {
                        if (func_8033D604_74ECB4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->targetYaw + spFC, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0) {
                            gCamera->targetYaw += sp100;
                        }
                    }
                }
            }
        }
    }

    if (gCamera->targetYaw < 0.0) {
        gCamera->targetYaw += 256.0;
    }
    if (gCamera->targetYaw >= 256.0) {
        gCamera->targetYaw -= 256.0;
    }

    if (func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, gCamera->targetPitch, gCamera->yaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
        spC2 = 4;
    }

    gCamera->targetPitch = var_f2 = (D_803A6CFC_7B83AC[gCamera->zoomIndex+3] * gCamera->cameraHeight) >> 4;
    var_v1 = 4;
    while (var_f2 > -20.0) {
        if (func_8033C8EC_74DF9C(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, var_f2, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0) {
            if ((var_f2 == gCamera->targetPitch) || (gCamera->pitch < var_f2)) {
                var_v1 = 1;
            }
            gCamera->targetPitch = var_f2;
            var_f2 = -400.0;
        }
        var_f2 -= 4.0;
    }

    var_f12 = ((var_v1 * 0.06) * gCamera->targetPitch) - ((var_v1 * 0.06) * gCamera->pitch);
    if (ABSF(var_f12) < 0.05) {
        var_f12 = 0.0f;
    }

    if (ABSF(var_f12) > ABSF(gCamera->pitchVelocity)) {
        if (var_f12 > 0.0f) {
            var_f12 = MIN(var_f12, gCamera->pitchVelocity + 0.4);
        } else {
            var_f12 = MAX(var_f12, gCamera->pitchVelocity - 0.4);
        }
    }

    gCamera->pitchVelocity = var_f12;
    gCamera->pitch += var_f12;

    var_f0 = gCamera->targetYaw - gCamera->yaw;
    if (var_f0 > 128.0) {
        var_f0 -= 256.0;
    }
    if (var_f0 < -128.0) {
        var_f0 += 256.0;
    }

    var_f0 *= MIN(spC2 * 0.25, 0.7);
    if (ABSF(var_f0) < 0.1) {
        var_f0 = 0.0f;
    }

    if (ABSF(var_f0) > ABSF(gCamera->yawVelocity)) {
        if (var_f0 > 0.0f) {
            var_f0 = MIN(var_f0, gCamera->yawVelocity + spC2);
        } else {
            // help
            var_f0 = MAX(var_f0, gCamera->yawVelocity - spC2);
        }
    }

    gCamera->yawVelocity = var_f0;
    gCamera->yaw += var_f0;

    if (gCamera->yaw >= 256.0) {
        gCamera->yaw -= 256.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 256.0;
    }

    var_f16 = (gCamera->targetDistance - gCamera->distance) * 0.18;
    if (ABSF(var_f16) < 0.5) {
        var_f16 = 0.0f;
    }

    if ((ABSF(var_f16) > ABSF(gCamera->distanceVelocity)) || (SIGNUMF(var_f16) != SIGNUMF(gCamera->distanceVelocity))) {
        if (var_f16 > 0.0f) {
            var_f16 = MIN(var_f16, gCamera->distanceVelocity + 10.0);
        } else {
            var_f16 = MAX(var_f16, gCamera->distanceVelocity - 10.0);
        }
    }

    gCamera->distanceVelocity = var_f16;
    var_f2 = gCamera->distance;
    gCamera->distance = var_f2 + var_f16;
    gCamera->lateralPanX *= gCamera->distance / var_f2;
    gCamera->lateralPanZ *= gCamera->distance / var_f2;
    gCamera->lateralPanVelX *= gCamera->distance / var_f2;
    gCamera->lateralPanVelZ *= gCamera->distance / var_f2;
    func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY);
    if (gCamera->followSpeed != gCamera->targetFollowSpeed) {
        if (gCamera->followSpeed < gCamera->targetFollowSpeed) {
            gCamera->followSpeed++;
        } else {
            gCamera->followSpeed--;
        }
    }
    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    if ((gCamera->followType == 1) && (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 2)) {
        func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &sp94, &sp90, &sp8C);

        sp94 = sp94 - gCamera->targetX;
        sp90 = sp90 - gCamera->targetZ;
        sp8C = sp8C - gCamera->targetY;

        var_f0 = sqrtf(SQ(sp94) + SQ(sp90) + SQ(sp8C));
        sp94 = sp94 / var_f0;
        sp90 = sp90 / var_f0;
        new_var = sp94;
        var_f2 = gAnimalState.animals[gCurrentAnimalIndex].animal->unk30C / 240.0;

        gCamera->upX += var_f2 * -sp90;
        gCamera->upZ += var_f2 * new_var;
    }

    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->pitch = gCamera->targetPitch;
        gCamera->pitchVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
}

// ESA: func_80025ECC
void func_8033641C_747ACC(u8 arg0, u8 arg1, u8 arg2) {
    s32 pad3[2] UNUSED;
    f32 var_f14;

    f32 var_f0_2;
    f32 var_f2_2;

    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;

    s32 pad4[0x3] UNUSED;
    s16 pad5 UNUSED;

    s16 var_v1; // spAC
    f32 temp_f0;
    f32 var_f0_9;

    f32 spA0;
    f32 sp9C;
    f32 sp98;

    f32 new_var;
    f32 var_f16;  // sp90
    f32 var_f12;  // sp8C

    s32 pad[4] UNUSED;

    f32 sp78;
    f32 sp74;
    f32 sp70;

    s32 pad2 UNUSED;


    gCamera = &gCameras[arg0];

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }
    if (gCamera->heightOverride != -1) {
        gCamera->cameraHeight = gCamera->heightOverride;
    }

    gCamera->targetDistance = (D_803A6CF0_7B83A0[gCamera->zoomIndex+3] * gCamera->baseDistance) >> 4;
    gCamera->targetDistance = (gCamera->targetDistance * 75.0f) / MAX(D_803F2D50.fovY, 5.0f);

    var_v1 = gCamera->followSpeed;
    var_v1 = (D_803A6D08_7B83B8[gCamera->zoomIndex+3] * var_v1) >> 4;
    if (var_v1 == 0) {
        var_v1 = 0xA;
    }

    var_f0_2 = MIN(0.95, var_v1 * 0.025);

    spD0 = gCamera->focusX;
    spCC = gCamera->focusZ;
    spC8 = D_803A7B24_7B91D4[gCamera->zoomIndex+3] + (gCamera->focusY + 4.0);

    cameraSettledFlag = 1;

    spC4 = (var_f0_2 * spD0) - (var_f0_2 * gCamera->targetX);
    spC0 = (var_f0_2 * spCC) - (var_f0_2 * gCamera->targetZ);
    spBC = (var_f0_2 * spC8) - (var_f0_2 * gCamera->targetY);

    if (ABSF(spC4) < 0.1) {
        spC4 = 0.0f;
    }
    if (ABSF(spC0) < 0.1) {
        spC0 = 0.0f;
    }
    if (ABSF(spBC) < 0.1) {
        spBC = 0.0f;
    }

    if (ABSF(spC4) < ABSF(gCamera->targetVelX)) {
        spA0 = 0.0f;
    } else {
        spA0 = spC4 - gCamera->targetVelX;
    }

    if (ABSF(spC0) < ABSF(gCamera->targetVelZ)) {
        sp9C = 0.0f;
    } else {
        sp9C = spC0 - gCamera->targetVelZ;
    }

    if (ABSF(spBC) < ABSF(gCamera->targetVelY)) {
        sp98 = 0.0f;
    } else {
        sp98 = spBC - gCamera->targetVelY;
    }

    temp_f0 = sqrtf(SQ(spA0) + SQ(sp9C) + SQ(sp98));
    var_f2_2 = var_v1 * 0.05;
    if (temp_f0 > 0.0) {
        if ((var_f2_2 / temp_f0) < 1.0) {
            if (spA0 != 0.0) {
                spC4 = gCamera->targetVelX + ((spA0 * var_f2_2) / temp_f0);
            }
            if (sp9C != 0.0) {
                spC0 = gCamera->targetVelZ + ((sp9C * var_f2_2) / temp_f0);
            }
            if (sp98 != 0.0) {
                spBC = gCamera->targetVelY + ((sp98 * var_f2_2) / temp_f0);
            }
        }
        if (0) {};
    }
    gCamera->targetVelX = spC4;
    gCamera->targetVelZ = spC0;
    gCamera->targetVelY = spBC;

    gCamera->targetX += spC4;
    gCamera->targetZ += spC0;
    gCamera->targetY += spBC;

    if (cameraSnapFlag != 0) {
        gCamera->targetX = spD0;
        gCamera->targetZ = spCC;
        gCamera->targetY = spC8;
        gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
    }

    if (gCamera->followType == 1) {
        var_v1 = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6;
        if (var_v1 & 1) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetY = gCamera->focusY + 4.0;

            gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
        } else if (var_v1 & 4) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;

            gCamera->targetVelX = gCamera->targetVelZ = 0.0f;
            if (gAnimalState.animals[gCurrentAnimalIndex].animal->movementState == MOVEMENT_STATE_SWIMMING) {
                gCamera->targetY = D_803A7B24_7B91D4[gCamera->zoomIndex+3] + (gCamera->focusY + 4.0); // s16?
                gCamera->targetVelY = 0.0f;
            }
        }
    }

    if (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType != EVO) {
        if (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType == WALRUS) {
          if (arg2 == 0) {
              var_f0_9 = gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation - gCamera->targetYaw;
              if (var_f0_9 < -128.0) {
                  var_f0_9 += 256.0;
              }
              if (var_f0_9 > 128.0) {
                  var_f0_9 -= 256.0;
              }
              gCamera->targetYaw += var_f0_9 / 5.0;
          }
        } else {
            if (arg2 == 0) {
                gCamera->targetYaw = gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation;
            }
        }
    }

    if (gCamera->targetYaw < 0.0) {
        gCamera->targetYaw += 256.0;

    }
    if (gCamera->targetYaw >= 256.0) {
        gCamera->targetYaw -= 256.0;
    }

    var_f16 = gCamera->cameraHeight;
    var_f12 = (D_803A6CF0_7B83A0[gCamera->zoomIndex+3] * gCamera->baseDistance) / 16.0;

    var_v1 = 0;
    switch (arg1) {
    case 0:
        while ((var_v1 < 20) && func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, var_f16, gCamera->targetYaw, var_f12, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
            var_f12 *= 0.93;
            var_f16 += ((63.0 - gCamera->cameraHeight) / 20.0);
            var_v1++;
        }

        if (var_v1 != 0) {
            var_f16 += 6.5;
            var_f12 = var_f12 * 0.93;
        }
        break;
    case 1:
        while ((var_f12 > 64.0) && func_8033C814_74DEC4(gCamera->focusX, gCamera->focusZ, (s16) gCamera->focusY + 4.0, var_f16, gCamera->targetYaw, var_f12, gCamera->panOffsetX, gCamera->panOffsetZ, 0) != 0) {
            var_f12 *= 0.93;
            var_v1++;
        }

        if (var_v1 != 0) {
            var_f12 *= 0.93;
        }
        break;
    }

    gCamera->targetPitch = MIN(63.0, var_f16);
    gCamera->targetDistance = var_f12;

    var_f14 = (0.26 * gCamera->targetPitch) - (0.26 * gCamera->pitch);
    if (ABSF(var_f14) < 0.05) {
        var_f14 = 0.0f;
    }

    if (ABSF(var_f14) > ABSF(gCamera->pitchVelocity)) {
        if (var_f14 > 0.0f) {
            var_f14 = MIN(var_f14, gCamera->pitchVelocity + 0.4);
        } else {
            var_f14 = MAX(var_f14, gCamera->pitchVelocity - 0.4);
        }
    }

    gCamera->pitchVelocity = var_f14;
    gCamera->pitch += var_f14;

    var_f2_2 = gCamera->targetYaw - gCamera->yaw;
    if (var_f2_2 > 128.0) {
        var_f2_2 -= 256.0;
    }
    if (var_f2_2 < -128.0) {
        var_f2_2 += 256.0;
    }

    var_f2_2 = var_f2_2 * 0.35;
    if (ABSF(var_f2_2) < 0.1) {
        var_f2_2 = 0.0f;
    }

    if (ABSF(var_f2_2) > ABSF(gCamera->yawVelocity)) {
        if (var_f2_2 > 0.0f) {
            var_f2_2 = MIN(var_f2_2, gCamera->yawVelocity + 4.0);
        } else {
            var_f2_2 = MAX(var_f2_2, gCamera->yawVelocity - 4.0);
        }
    }

    gCamera->yawVelocity = var_f2_2;
    gCamera->yaw += var_f2_2;

    if (gCamera->yaw >= 256.0) {
        gCamera->yaw -= 256.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 256.0;
    }

    var_f16 = (gCamera->targetDistance - gCamera->distance) * 0.28;
    if (ABSF(var_f16) < 0.5) {
        var_f16 = 0.0f;
    }

    if ((ABSF(var_f16) > ABSF(gCamera->distanceVelocity)) || (SIGNUMF(var_f16) != SIGNUMF(gCamera->distanceVelocity))) {
        if (var_f16 > 0.0f) {
            var_f16 = MIN(var_f16, gCamera->distanceVelocity + 10.0);
        } else {
            var_f16 = MAX(var_f16, gCamera->distanceVelocity - 10.0);
        }
    }

    gCamera->distanceVelocity = var_f16;
    var_f2_2 = gCamera->distance;
    gCamera->distance = var_f2_2 + var_f16;
    gCamera->lateralPanX *= gCamera->distance / var_f2_2;
    gCamera->lateralPanZ *= gCamera->distance / var_f2_2;
    gCamera->lateralPanVelX *= gCamera->distance / var_f2_2;
    gCamera->lateralPanVelZ *= gCamera->distance / var_f2_2;

    func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY);

    if (gCamera->followSpeed != gCamera->targetFollowSpeed) {
        if (gCamera->followSpeed < gCamera->targetFollowSpeed) {
            gCamera->followSpeed++;
        } else {
            gCamera->followSpeed--;
        }
    }

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    if ((gCamera->followType == 1) && (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 2)) {

        func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &sp78, &sp74, &sp70);

        sp78 = sp78 - gCamera->targetX;
        sp74 = sp74 - gCamera->targetZ;
        sp70 = sp70 - gCamera->targetY;

        temp_f0 = sqrtf(SQ(sp78) + SQ(sp74) + SQ(sp70));
        sp78 = sp78 / temp_f0;
        sp74 = sp74 / temp_f0;
        new_var = sp78;
        var_f2_2 = gAnimalState.animals[gCurrentAnimalIndex].animal->unk30C / 240.0;

        gCamera->upX += var_f2_2 * -sp74;
        gCamera->upZ += var_f2_2 * new_var;
    }
    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->pitch = gCamera->targetPitch;
        gCamera->pitchVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
}

// ESA: func_80026E0C
void func_803378BC_748F6C(u8 arg0) {
    f32 a, b;
    f32 temp_f0;
    f32 temp_f12;

    f32 temp_f14;
    f32 temp_f16;
    f32 sp24;
    f32 temp_f2;
    f32 sp1C;
    f32 temp_f16_2;

    gCamera = &gCameras[arg0];
    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }

    a = gCamera->focusX;
    b = gCamera->focusZ;
    temp_f12 = gCamera->focusY + 4.0;

    gCamera->targetX = a;
    gCamera->targetZ = b;
    gCamera->targetY = temp_f12;

    gCamera->eyeX = gCamera->fixPosX << 5;
    gCamera->eyeZ = gCamera->fixPosZ << 5;
    gCamera->eyeY = gCamera->fixPosY << 5;

    temp_f14 = gCamera->targetX - gCamera->eyeX;
    temp_f16 = gCamera->targetZ - gCamera->eyeZ;
    sp24 = gCamera->targetY - gCamera->eyeY;

    if ((ABSF(temp_f14) >= ABSF(temp_f16))) {
        if (temp_f14 > 0.0f) {
            gCamera->yaw = 90.0 - (f32) func_8012844C((temp_f16 * 64.0f) / temp_f14);
        } else if (temp_f14 < 0.0f) {
            gCamera->yaw = 270.0 + (f32) func_8012844C((temp_f16 * 64.0f) / -temp_f14);
        }
    } else {
        if (temp_f16 > 0.0f) {
            gCamera->yaw = func_8012844C((temp_f14 * 64.0f) / temp_f16);
        } else if (temp_f16 < 0.0f) {
            gCamera->yaw = (180.0 - (f32) func_8012844C((temp_f14 * 64.0f) / -temp_f16));
        }
    }

    gCamera->yaw = (gCamera->yaw * 256.0) / 360.0;

    if (gCamera->zoomIndex != 5) {
        f64 factor = 128.0;
        if (gCamera->zoomInterp < (gCamera->zoomIndex * 8)) {
            gCamera->zoomInterp++;
        } else if ((gCamera->zoomIndex * 8) < gCamera->zoomInterp) {
            gCamera->zoomInterp--;
        }
        sp1C = (((D_803A6CF0_7B83A0[(gCamera->zoomInterp >> 3) + 4] * (gCamera->zoomInterp & 7)) +
                 (D_803A6CF0_7B83A0[(gCamera->zoomInterp >> 3) + 3] * (8 - (gCamera->zoomInterp & 7)))) * gCamera->baseDistance) / factor;
        temp_f2 = sp1C / sqrtf(SQ(temp_f14) + SQ(temp_f16) + SQ(sp24));
        if (temp_f2 < 1.0f) {
            gCamera->eyeX = gCamera->targetX +  (temp_f2 * (gCamera->eyeX - gCamera->targetX));
            gCamera->eyeZ = gCamera->targetZ +  (temp_f2 * (gCamera->eyeZ - gCamera->targetZ));
            gCamera->eyeY = gCamera->targetY + (temp_f2 * (gCamera->eyeY - gCamera->targetY));
        }
    }
    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    temp_f16_2 = gCamera->distance;

    gCamera->distance = sqrtf(SQ(gCamera->targetX - gCamera->eyeX) + SQ(gCamera->targetZ - gCamera->eyeZ) + SQ(gCamera->targetY - gCamera->eyeY));
    gCamera->lateralPanX *= gCamera->distance / temp_f16_2;
    gCamera->lateralPanZ *= gCamera->distance / temp_f16_2;
    gCamera->lateralPanVelX *= gCamera->distance / temp_f16_2;
    gCamera->lateralPanVelZ *= gCamera->distance / temp_f16_2;
    cameraSettledFlag = 1;
}

// ESA: func_80027320
void func_80337ECC_74957C(u8 id) {
    s32 pad[2] UNUSED;

    f32 var_f12;
    f32 var_f2;
    f32 var_f0;

    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    s16 spA2;
    s16 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    s16 i; //sp92

    static f32 sSmoothedCollisionStep = 0.0f; // .data

    gCamera = &gCameras[id];

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
    } else {
        gCamera->baseDistance = 400;
    }

    gCamera->offsetXTarget = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkD0;
    gCamera->offsetYTarget = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkD2;

    switch (gCamera->zoomIndex) {
    default:
    case 0:
        spA2 = gCamera->offsetXTarget;
        spA0 = gCamera->offsetYTarget;
        break;
    case 1:
        spA2 = gCamera->offsetXTarget - 0x5D;
        spA0 = gCamera->offsetYTarget + 0x2E;
        break;
    case 2:
        spA2 = gCamera->offsetXTarget - 0xBB;
        spA0 = gCamera->offsetYTarget + 0x5D;
        break;
    case -3:
        spA2 = gCamera->offsetXTarget >> 3;
        spA0 = (gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 5) >> 2;
        break;
    }

    if (gCameras[id].cameraMode == CAMERA_MODE_BEHIND_2) {
        D_803F2A9E = 0;
    } else {
        func_8033E430_74FAE0();
    }

    var_f12 = (spA2 - gCamera->offsetX) * 0.04;
    if ((ABSF(var_f12) > ABSF(gCamera->offsetXVelocity)) || (SIGNUMF(var_f12) != SIGNUMF(gCamera->offsetXVelocity))) {
        if (var_f12 > 0.0f) {
            var_f12 = MIN(var_f12, gCamera->offsetXVelocity + 1.0);
        } else {
            var_f12 = MAX(var_f12, gCamera->offsetXVelocity - 1.0);
        }
    }
    gCamera->offsetXVelocity = var_f12;
    gCamera->offsetX += var_f12;

    var_f12 = (spA0 - gCamera->offsetY) * 0.04;
    if ((ABSF(var_f12) > ABSF(gCamera->offsetYVelocity)) || (SIGNUMF(var_f12) != SIGNUMF(gCamera->offsetYVelocity))) {
        if (var_f12 > 0.0f) {
            var_f12 = MIN(var_f12, gCamera->offsetYVelocity + 1.0);
        } else {
            var_f12 = MAX(var_f12, gCamera->offsetYVelocity - 1.0);
        }
    }
    gCamera->offsetYVelocity = var_f12;
    gCamera->offsetY += var_f12;

    if (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType == EVO) {
        gCamera->targetYaw = gCamera->yaw;
    } else {
        gCamera->targetYaw = (gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation + ((f32)D_803D5548 / 16)) * 360.0 / 256.0;
    }

    gCamera->targetYaw += gCamera->yawOffset;
    var_f2 = gCamera->targetYaw - gCamera->yaw;
    while (var_f2 > 180.0) {
        var_f2 -= 360.0;
    }
    while (var_f2 < -180.0) {
        var_f2 += 360.0;
    }

    var_f2 = var_f2 * 0.85;
    if (ABSF(var_f2) > ABSF(gCamera->yawVelocity)) {
        if (var_f2 > 0.0f) {
            var_f2 = MIN(var_f2, gCamera->yawVelocity + 5.0);
        } else {
            var_f2 = MAX(var_f2, gCamera->yawVelocity - 5.0);
        }
    }
    gCamera->yawVelocity = var_f2;
    gCamera->yaw += var_f2;

    if (gCamera->yaw >= 360.0) {
        gCamera->yaw -= 360.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 360.0;
    }

    while (gCamera->yawOffset > 180.0) {
        gCamera->yawOffset -= 360.0;
    }
    while (gCamera->yawOffset < -180.0) {
        gCamera->yawOffset += 360.0;
    }

    if (gCamera->unk68 == 0) {
        if (gCamera->yawOffset < 0.0f) {
            gCamera->yawOffset = MIN(0.0, gCamera->yawOffset + 4.0);
        } else {
            gCamera->yawOffset = MAX(0.0, gCamera->yawOffset - 4.0);
        }
    }

    spB0 = gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.w / 65536.0;
    spAC = gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.w / 65536.0;
    spA8 = gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.w / 65536.0;

    spA4 = gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 / 2.0;
    gCamera->eyeX = spB0;
    gCamera->eyeZ = spAC;
    if (gCamera->zoomIndex == -3) {
        gCamera->eyeY = spA8;
    } else {
        gCamera->eyeY = spA8 - ((f32) D_803F2A9E / gAnimalState.animals[gCurrentAnimalIndex].unk0->unkE8);
    }

    gCamera->eyeX += sinf((gCamera->yaw * 6.2832) / 360.0) * gCamera->offsetX;
    gCamera->eyeZ += cosf((gCamera->yaw * 6.2832) / 360.0) * gCamera->offsetX;
    gCamera->eyeY += gCamera->offsetY;

    sp9C = gCamera->eyeX;
    sp98 = gCamera->eyeZ;
    sp94 = gCamera->eyeY;

    for (i = 0; (i < 13) && func_8033C9CC_74E07C(gCamera->eyeX, gCamera->eyeZ, gCamera->eyeY, 0x7F, spB0, spAC, spA8 + spA4, 0x7F, 1, 0) != 0; i++) {
        gCamera->eyeX = sp9C + ((i * (spB0 - sp9C)) / 16.0);
        gCamera->eyeZ = sp98 + ((i * (spAC - sp98)) / 16.0);
        gCamera->eyeY = sp94 + ((i * ((spA8 + (2.0 * spA4)) - sp94)) / 16.0);
    }

    sSmoothedCollisionStep = sSmoothedCollisionStep + ((i - sSmoothedCollisionStep) / 2.0);
    gCamera->eyeX = sp9C + ((sSmoothedCollisionStep * (spB0 - sp9C)) / 16.0);
    gCamera->eyeZ = sp98 + ((sSmoothedCollisionStep * (spAC - sp98)) / 16.0);
    gCamera->eyeY = sp94 + ((sSmoothedCollisionStep * ((spA8 + (2.0 * spA4) - sp94))) / 16.0);

    switch (gCamera->followType) {
    default:
    case 0:
    case 1:
        gCamera->targetX = gCamera->eyeX + (sinf(((gCamera->yaw * 6.2832) / 360.0)) * 256.0);
        gCamera->targetZ = gCamera->eyeZ + (cosf(((gCamera->yaw * 6.2832) / 360.0)) * 256.0);
        gCamera->targetY = gCamera->eyeY + D_803F2A9E;
        break;
    case 2:
    case 3:
        gCamera->targetX = gCamera->followEntity->position.xPos.w / 65536.0;
        gCamera->targetZ = gCamera->followEntity->position.zPos.w / 65536.0;
        gCamera->targetY = gCamera->followEntity->position.yPos.w / 65536.0;
        break;
    case 4:
        gCamera->targetX = gCamera->fixTargetX;
        gCamera->targetZ = gCamera->fixTargetZ;
        gCamera->targetY = gCamera->fixTargetY;
        break;
    }

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;
    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->offsetX = spA2;
        gCamera->offsetXVelocity = 0.0f;
        gCamera->offsetY = spA0;
        gCamera->offsetYVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
    cameraSettledFlag = 1;
}

void func_80338E1C_74A4CC(u8 cameraID) {
    f32 phi_f0;
    f32 temp;

    gCamera = &gCameras[cameraID];

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        // defaults
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }
    if (gCamera->zoomIndex < 0) {
        gCamera->targetDistance = gCamera->baseDistance + ((gCamera->zoomIndex * gCamera->baseDistance) / 4);
    } else {
        gCamera->targetDistance = gCamera->baseDistance + ((gCamera->zoomIndex * gCamera->baseDistance) / 2);
    }

    phi_f0 = (gCamera->targetDistance - gCamera->distance) * 0.18;

    if ((ABSF(phi_f0) > ABSF(gCamera->distanceVelocity)) || SIGNUMF(phi_f0) != SIGNUMF(gCamera->distanceVelocity)) {
        if (phi_f0 > 0.0f) {
            phi_f0 = MIN(phi_f0, gCamera->distanceVelocity + 4.0);
        } else {
            phi_f0 = MAX(phi_f0, gCamera->distanceVelocity - 4.0);
        }
    }

    gCamera->distanceVelocity = phi_f0;
    temp = gCamera->distance;
    gCamera->distance += phi_f0;

    gCamera->panOffsetX = gCamera->panOffsetX * (gCamera->distance / temp);
    gCamera->panOffsetZ = gCamera->panOffsetZ * (gCamera->distance / temp);

    gCamera->panOffsetVelX = gCamera->panOffsetVelX * (gCamera->distance / temp);
    gCamera->panOffsetVelZ = gCamera->panOffsetVelZ * (gCamera->distance / temp);

    gCamera->yaw = 0.0f;
    gCamera->targetYaw = 0.0f;

    if (gCamera->distance < 1.0) {
        gCamera->distance = 1.0f;
    }

    gCamera->targetX = gCamera->focusX;
    gCamera->targetZ = gCamera->focusZ;
    gCamera->targetY = gCamera->focusY + 4.0;

    gCamera->eyeX = gCamera->targetX;
    gCamera->eyeZ = gCamera->targetZ;
    gCamera->eyeY = gCamera->targetY + gCamera->distance;

    gCamera->upX = 0.0f;
    gCamera->upZ = 1.0f;
    gCamera->upY = 0.0f;

    if (cameraSnapFlag != 0) {
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
    cameraSettledFlag = 1;
}

void func_803391D0_74A880(u8 cameraID) {
    func_80338E1C_74A4CC(cameraID);
    gCamera->upX = 0.0f;
    gCamera->upZ = -1.0f;
    gCamera->yaw = gCamera->targetYaw = 128.0f;
}

void func_80339238_74A8E8(u8 cameraID) {
    func_80338E1C_74A4CC(cameraID);
    gCamera->upX = 1.0f;
    gCamera->upZ = 0.0f;
    gCamera->yaw = gCamera->targetYaw = 64.0f;
}

void func_803392A0_74A950(u8 cameraID) {
    func_80338E1C_74A4CC(cameraID);
    gCamera->upX = -1.0f;
    gCamera->upZ = 0.0f;
    gCamera->yaw = gCamera->targetYaw = 192.0f;
}

void func_80339308_74A9B8(u8 cameraID) {
    f32 tmp;

    gCamera = &gCameras[cameraID];
    tmp = gCamera->yaw;
    func_80338E1C_74A4CC(cameraID);
    if ((tmp > 32.0) && (tmp <= 96.0)) {
        gCamera->yaw = 64.0f;
        gCamera->upX = 1.0f;
        gCamera->upZ = 0.0f;
    } else if ((tmp > 96.0) && (tmp <= 160.0)) {
        gCamera->yaw = 128.0f;
        gCamera->upX = 0.0f;
        gCamera->upZ = -1.0f;
    } else if ((tmp > 160.0) && (tmp <= 224.0)) {
        gCamera->yaw = 192.0f;
        gCamera->upX = -1.0f;
        gCamera->upZ = 0.0f;
    } else {
        gCamera->yaw = 0.0f;
        gCamera->upX = 0.0f;
        gCamera->upZ = 1.0f;
    }
    gCamera->targetYaw = gCamera->yaw;
    cameraSettledFlag = 1;
}

void func_803394E4_74AB94(u8 cameraID, u8 arg1) {
    f32 temp_f2;
    f32 var_f12;
    f32 var_f2;

    gCamera = &gCameras[cameraID];

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }

    if (gCamera->zoomIndex < 0) {
        gCamera->targetDistance = gCamera->baseDistance + ((gCamera->zoomIndex * gCamera->baseDistance) / 4);
    } else {
        gCamera->targetDistance = gCamera->baseDistance + ((gCamera->zoomIndex * gCamera->baseDistance) / 2);
    }

    var_f12 = (gCamera->targetDistance - gCamera->distance) * 0.18;

    if ((ABS(var_f12) > ABS(gCamera->distanceVelocity)) || (SIGNUMF(var_f12) != SIGNUMF(gCamera->distanceVelocity))) {
        if (var_f12 > 0.0f) {
            var_f12 = MIN(var_f12, gCamera->distanceVelocity + 4.0);
        } else {
            var_f12 = MAX(var_f12, gCamera->distanceVelocity - 4.0);
        }
    }

    gCamera->distanceVelocity = var_f12;
    temp_f2 = gCamera->distance;
    gCamera->distance += var_f12;

    if (gCamera->distance < 1.0) {
        gCamera->distance = 1.0f;
    }
    gCamera->panOffsetX *= gCamera->distance / temp_f2;
    gCamera->panOffsetZ *= gCamera->distance / temp_f2;

    gCamera->panOffsetVelX *= gCamera->distance / temp_f2;
    gCamera->panOffsetVelZ *= gCamera->distance / temp_f2;

    if (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType != EVO) {
        var_f2 = gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation - gCamera->yaw;
    } else {
        var_f2 = 0.0f;
    }

    if (arg1 != 0) {
        var_f2 = 0.0f;
    }

    if (var_f2 > 128.0) {
        var_f2 -= 256.0;
    }
    if (var_f2 < -128.0) {
        var_f2 += 256.0;
    }

    var_f2 = (var_f2 * 0.1);
    if ((ABS(var_f2) > ABS(gCamera->yawVelocity))) {
        if (var_f2 > 0.0f) {
            var_f2 = MIN(var_f2, gCamera->yawVelocity + 2.0);
        } else {
            var_f2 = MAX(var_f2, gCamera->yawVelocity - 2.0);
        }
    }
    gCamera->yawVelocity = var_f2;
    gCamera->yaw += var_f2;

    if (gCamera->yaw >= 256.0) {
        gCamera->yaw -= 256.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 256.0;
    }

    gCamera->targetYaw = gCamera->yaw;

    gCamera->targetX = gCamera->focusX;
    gCamera->targetZ = gCamera->focusZ;
    gCamera->targetY = gCamera->focusY + 4.0;

    gCamera->eyeX = gCamera->targetX;
    gCamera->eyeZ = gCamera->targetZ;
    gCamera->eyeY = gCamera->targetY + gCamera->distance;

    gCamera->upX = (f64) sinf((gCamera->yaw * 6.2832) / 256.0);
    gCamera->upZ = (f64) cosf((gCamera->yaw * 6.2832) / 256.0);
    gCamera->upY = 0.0f;

    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
    cameraSettledFlag = 1;
}

void fix_camera_to_angle_offset(u8 cameraID, f32 angle) {
    double pad2 UNUSED;
    double pad3 UNUSED;
    double pad4 UNUSED;
    f32 sp9C;
    f32 sp98;
    f32 sp94;

    f32 sp90;
    f32 sp8C;
    f32 sp88;

    f32 var_f12;
    f32 temp_f0_2;
    f32 var_f16;

    s16 temp_a0;
    s16 var_v1;
    s16 temp_v1_2;
    s16 temp_v1_3;

    f32 var_f2_2;
    s32 pad UNUSED;

    f32 sp68;
    f32 sp64;
    f32 sp60;

    gCamera = &gCameras[cameraID];

    if (gCamera->followType == 1) {
        gCamera->baseDistance = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->cameraHeight = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        gCamera->baseDistance = 400;
        gCamera->cameraHeight = 32;
    }

    if (gCamera->heightOverride != -1) {
        gCamera->cameraHeight = gCamera->heightOverride;
    }
    gCamera->targetDistance = (D_803A6CF0_7B83A0[gCamera->zoomIndex+3] * gCamera->baseDistance) >> 4;
    gCamera->targetDistance = (gCamera->targetDistance * 75.0f) / MAX(D_803F2D50.fovY, 5.0f);

    var_v1 = gCamera->followSpeed;
    var_v1 = (D_803A6D08_7B83B8[gCamera->zoomIndex+3] * var_v1) >> 4;
    if (var_v1 == 0) {
        var_v1 = 10;
    }

    var_f16 = MIN(0.95, var_v1 * 0.025);

    sp9C = gCamera->focusX;
    sp98 = gCamera->focusZ;
    sp94 = gCamera->focusY + 4.0;

    if ((ABS(sp9C - gCamera->focusX) <= 10.0f) &&
        (ABS(sp98 - gCamera->focusZ) <= 10.0f) &&
        (ABS(sp94 - gCamera->focusY) <= 10.0f)) {
        cameraSettledFlag = 1;
    }

    sp90 = (var_f16 * sp9C) - (var_f16 * gCamera->targetX);
    sp8C = (var_f16 * sp98) - (var_f16 * gCamera->targetZ);
    sp88 = (var_f16 * sp94) - (var_f16 * gCamera->targetY);

    if (ABSF(sp90) < 0.1) {
        sp90 = 0.0f;
    }
    if (ABSF(sp8C) < 0.1) {
        sp8C = 0.0f;
    }
    if (ABSF(sp88) < 0.1) {
        sp88 = 0.0f;
    }

    if (ABSF(sp90) < ABSF(gCamera->targetVelX)) {
        sp68 = 0.0f;
    } else {
        sp68 = sp90 - gCamera->targetVelX;
    }

    if (ABSF(sp8C) < ABSF(gCamera->targetVelZ)) {
        sp64 = 0.0f;
    } else {
        sp64 = sp8C - gCamera->targetVelZ;
    }

    if (ABSF(sp88) < ABSF(gCamera->targetVelY)) {
        sp60 = 0.0f;
    } else {
        sp60 = sp88 - gCamera->targetVelY;
    }

    temp_f0_2 = sqrtf(SQ(sp68) + SQ(sp64) + SQ(sp60));
    var_f2_2 = var_v1 * 0.05;
    if ((temp_f0_2 > 0.0) && ((var_f2_2 / temp_f0_2) < 1.0)) {
        if (sp68 != 0.0) {
            sp90 = gCamera->targetVelX + ((sp68 * var_f2_2) / temp_f0_2);
        }
        if (sp64 != 0.0) {
            sp8C = gCamera->targetVelZ + ((sp64 * var_f2_2) / temp_f0_2);
        }
        if (sp60 != 0.0) {
            sp88 = gCamera->targetVelY + ((sp60 * var_f2_2) / temp_f0_2);
        }
        if (0) {};
    }
    gCamera->targetVelX = sp90;
    gCamera->targetVelZ = sp8C;
    gCamera->targetVelY = sp88;

    gCamera->targetX += sp90;
    gCamera->targetZ += sp8C;
    gCamera->targetY += sp88;

    if (cameraSnapFlag != 0) {
        gCamera->targetX = sp9C;
        gCamera->targetZ = sp98;
        gCamera->targetY = sp94;
        gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
    }

    if (gCamera->followType == 1) {
        temp_v1_2 = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6;
        if (temp_v1_2 & 1) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetY = gCamera->focusY + 4.0;

            gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
        } else if (temp_v1_2 & 4) {
            gCamera->targetX = gCamera->focusX;
            gCamera->targetZ = gCamera->focusZ;
            gCamera->targetVelX = gCamera->targetVelZ = 0.0f;
            if (gAnimalState.animals[gCurrentAnimalIndex].animal->movementState == MOVEMENT_STATE_SWIMMING) {
                gCamera->targetY = gCamera->focusY + 4.0;
                gCamera->targetVelY = 0.0f;
            }
        }
    }

    gCamera->targetYaw = angle;

    var_v1 = 4;
    var_f2_2 = (D_803A6CFC_7B83AC[gCamera->zoomIndex+3] * gCamera->cameraHeight) >> 4;
    gCamera->targetPitch = var_f2_2;
    while (var_f2_2 > -20.0) {
        if (func_8033C8EC_74DF9C(gCamera->focusX, gCamera->focusZ, gCamera->focusY + 4.0, var_f2_2, gCamera->targetYaw, gCamera->targetDistance, gCamera->panOffsetX, gCamera->panOffsetZ) == 0) {
            if ((gCamera->targetPitch == var_f2_2) || (gCamera->pitch < var_f2_2)) {
                var_v1 = 1;
            }
            gCamera->targetPitch = var_f2_2;
            var_f2_2 = -400.0;
        }
        var_f2_2 -= 4.0;
    }

    var_f12 = ((var_v1 * 0.06) *  gCamera->targetPitch) - ((var_v1 * 0.06) *  gCamera->pitch);
    if (ABSF(var_f12) < 0.05) {
        var_f12 = 0.0f;
    }

    if (ABSF(var_f12) > ABSF(gCamera->pitchVelocity)) {
        if (var_f12 > 0.0f) {
            var_f12 = MIN(var_f12, gCamera->pitchVelocity + 0.4);
        } else {
            var_f12 = MAX(var_f12, gCamera->pitchVelocity - 0.4);
        }
    }
    gCamera->pitchVelocity = var_f12;
    gCamera->pitch += var_f12;

    temp_f0_2 = gCamera->targetYaw - gCamera->yaw;
    if (temp_f0_2 > 128.0) {
        temp_f0_2 = temp_f0_2 - 256.0;
    }
    if (temp_f0_2 < -128.0) {
        temp_f0_2 = temp_f0_2 + 256.0;
    }

    temp_f0_2 = temp_f0_2 * 0.18;
    if (ABSF(temp_f0_2) < 0.1) {
        temp_f0_2 = 0.0f;
    }

    if (ABSF(temp_f0_2) > ABSF(gCamera->yawVelocity)) {
        if (temp_f0_2 > 0.0f) {
            temp_f0_2 = MIN(temp_f0_2, gCamera->yawVelocity + 2.0);
        } else {
            temp_f0_2 = MAX(temp_f0_2, gCamera->yawVelocity - 2.0);
        }
    }
    gCamera->yawVelocity = temp_f0_2;
    gCamera->yaw += temp_f0_2;

    if (gCamera->yaw >= 256.0) {
        gCamera->yaw -= 256.0;
    }
    if (gCamera->yaw < 0.0) {
        gCamera->yaw += 256.0;
    }

    var_f16 = (gCamera->targetDistance - gCamera->distance) * 0.18;
    if (ABSF(var_f16) < 0.5) {
        var_f16 = 0.0f;
    }

    if ((ABSF(var_f16) > ABSF(gCamera->distanceVelocity)) || SIGNUMF(var_f16) != SIGNUMF(gCamera->distanceVelocity)) {
        if (var_f16 > 0.0f) {
            var_f16 = MIN(var_f16, gCamera->distanceVelocity + 10.0);
        } else {
            var_f16 = MAX(var_f16, gCamera->distanceVelocity - 10.0);
        }
    }

    gCamera->distanceVelocity = var_f16;
    var_f2_2 = gCamera->distance;
    gCamera->distance = var_f2_2 + var_f16;
    gCamera->lateralPanX *= gCamera->distance / var_f2_2;
    gCamera->lateralPanZ *= gCamera->distance / var_f2_2;
    gCamera->lateralPanVelX *= gCamera->distance / var_f2_2;
    gCamera->lateralPanVelZ *= gCamera->distance / var_f2_2;
    func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance, &gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY);
    if (gCamera->followSpeed != gCamera->targetFollowSpeed) {
        if (gCamera->followSpeed < gCamera->targetFollowSpeed) {
            gCamera->followSpeed += 1;
        } else {
            gCamera->followSpeed -= 1;
        }
    }
    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;
    if (cameraSnapFlag != 0) {
        gCamera->yaw = gCamera->targetYaw;
        gCamera->yawVelocity = 0.0f;
        gCamera->pitch = gCamera->targetPitch;
        gCamera->pitchVelocity = 0.0f;
        gCamera->distance = gCamera->targetDistance;
        gCamera->distanceVelocity = 0.0f;
    }
}

// ESA: func_800292B8
void func_8033AAC8_74C178(u8 cameraID) {
    f32 temp_f0;
    f32 temp_f14;
    f32 var_f2;
    u8 length;
    s32 pad[2] UNUSED;
    WaypointData *wpd;

    gCamera = &gCameras[cameraID];

    wpd = gCamera->waypoints;
    length = wpd->length;
    if (gCamera->waypointProgress < ((length << 5) - 65)) {
        gCamera->waypointProgress++;
    } else {
        cameraSettledFlag = 1;
    }

    if ((gCamera->waypointProgress + 104) == (length << 5)) {
        D_803F2C6C = D_803F2C6D = 0;
        gCamera->cameraMode = CAMERA_MODE_WAYPOINT_2;
    }
    update_camera_from_waypoint(&gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY, wpd, gCamera->waypointProgress);
    update_camera_from_waypoint(&gCamera->targetX, &gCamera->targetZ, &gCamera->targetY, wpd, gCamera->waypointProgress + 31);

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    temp_f14 = gCamera->targetX - gCamera->eyeX;
    temp_f0 = gCamera->targetZ - gCamera->eyeZ;
    if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
        var_f2 = 0.0f;
    } else {
        var_f2 = func_801286B8(-temp_f0, temp_f14);
    }
    gCamera->targetYaw = var_f2;
    gCamera->yaw = var_f2;
}

// ESA: func_80029438
void update_camera_from_waypoint(f32 *arg0, f32 *arg1, f32 *arg2, WaypointData *wpd, s16 arg4) {
    s16 sp48[4]; // why!?

    s16 tmp;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f18;

    tmp = arg4 / 32;

    sp48[0] = MAX(0, tmp - 1);               // previous
    sp48[1] = tmp;                           // current
    sp48[2] = MIN(wpd->length - 1, tmp + 1); // next
    sp48[3] = MIN(wpd->length - 1, tmp + 2); // next + 1

    temp_f18 = (f32)((s16) (arg4 - (tmp * 32))) / 32;
    temp_f12 = temp_f18 * temp_f18;
    temp_f0 = temp_f18 * temp_f12;
    temp_f10 = (temp_f0 / 6.0);

    temp_f4 = ((-temp_f0       ) + (3.0 * temp_f12) - (3.0 * temp_f18) + 1.0) / 6.0;
    temp_f6 = (( temp_f0 *  3.0) - (6.0 * temp_f12) + (4.0           )      ) / 6.0;
    temp_f8 = (( temp_f0 * -3.0) + (3.0 * temp_f12) + (3.0 * temp_f18) + 1.0) / 6.0;

    *arg0 = ((temp_f4 * wpd->waypoint[sp48[0]].x) + (temp_f6 * wpd->waypoint[sp48[1]].x) + (temp_f8 * wpd->waypoint[sp48[2]].x) + (temp_f10 * (wpd->waypoint + sp48[3])->x)) * 64.0f;
    *arg1 = ((temp_f4 * wpd->waypoint[sp48[0]].z) + (temp_f6 * wpd->waypoint[sp48[1]].z) + (temp_f8 * wpd->waypoint[sp48[2]].z) + (temp_f10 * (wpd->waypoint + sp48[3])->z)) * 64.0f;
    *arg2 = ((temp_f4 * wpd->waypoint[sp48[0]].y) + (temp_f6 * wpd->waypoint[sp48[1]].y) + (temp_f8 * wpd->waypoint[sp48[2]].y) + (temp_f10 * (wpd->waypoint + sp48[3])->y)) * 64.0f;
}

void func_8033B118_74C7C8(u8 cameraID) {
    f32 phi_f2;
    f32 sp30;
    f32 temp_f22;

    gCamera = &gCameras[cameraID];
    gCamera->yaw += D_803A6CCC_7B837C;

    if (gCamera->yaw > 256.0) {
        gCamera->yaw -= 256.0;
    }
    gCamera->targetYaw = gCamera->yaw;

    gCamera->targetX = (f32) gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.w / 65536.0;
    gCamera->targetZ = (f32) gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.w / 65536.0;
    gCamera->targetY = ((f32) gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.w / 65536.0) + ((f32)gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 0.5);

    temp_f22 = gAnimalState.animals[gCurrentAnimalIndex].unk0->unkD4;
    temp_f22 = temp_f22 * D_803A6CC4_7B8374;
    temp_f22 = (temp_f22 * 75.0f) / D_803F2D50.fovY;
    sp30 = cosf((D_803A6CC8_7B8378 * 6.2832) / 360.0);
    gCamera->eyeX = (gCamera->targetX - (sinf((gCamera->yaw * 6.2832 * 0.00390625)) * (temp_f22 * sp30)));
    sp30 = cosf((D_803A6CC8_7B8378 * 6.2832) / 360.0);
    gCamera->eyeZ = (gCamera->targetZ - (cosf((gCamera->yaw * 6.2832 * 0.00390625)) * (temp_f22 * sp30)));
    gCamera->eyeY = ((sinf(((D_803A6CC8_7B8378 * 6.2832) / 360.0)) * temp_f22) + gCamera->targetY);

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;
}

void func_8033B440_74CAF0(u8 cameraID) {
    f32 temp_f0;
    f32 temp_f14;
    f32 phi_f2;

    gCamera = &gCameras[cameraID];
    gCamera->targetX = scriptedTargetX;
    gCamera->targetZ = scriptedTargetZ;
    gCamera->targetY = scriptedTargetY;

    gCamera->eyeX = scriptedEyeX;
    gCamera->eyeZ = scriptedEyeZ;
    gCamera->eyeY = scriptedEyeY;

    gCamera->upX = D_803A6CD0_7B8380;
    gCamera->upZ = D_803A6CD4_7B8384;
    gCamera->upY = D_803A6CD8_7B8388;
    temp_f14 = gCamera->targetX - gCamera->eyeX;
    temp_f0 = gCamera->targetZ - gCamera->eyeZ;
    if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
        phi_f2 = 0.0f;
    } else {
        phi_f2 = func_801286B8(-temp_f0, temp_f14);
    }
    gCamera->targetYaw = phi_f2;
    gCamera->yaw = phi_f2;
}

void func_8033B594_74CC44(u8 arg0) {
    f32 phi_f14;
    f32 phi_f20;
    f32 sp2C;

    osSyncPrintf("ca_UpdateCamera_Watch_TV.\n");
    gCamera = &gCameras[arg0];
    D_803F6468 += 1;

    if ((gCameraUiState == 1) || (gCameraUiState == 4)) {
        phi_f20 = MAX(22.0f, 200.0 - (D_803F6468 * 1.95));

        if ((D_803F6468 * 0.5) > 30.0) {
            // wtf is this?
            phi_f14 = ((D_803F6468 * 0.5) > 30.0) * 0.0;
            // phi_f14 = 0;
        } else {
            phi_f14 = 30.0 - (D_803F6468 * 0.5);
        }

        phi_f20 = ((f32)D_803F6464->unk40 * phi_f20) / 4915.2;
    } else {
        phi_f20 = (f32) ((2.0 * D_803F6468) + 22.0f);
        phi_f20 = ((f32)D_803F6464->unk40 * phi_f20) / 4915.2;
        phi_f14 = (D_803F6468 * 0.7);
    }
    gCamera->distance = phi_f20;
    gCamera->targetDistance = phi_f20;
    gCamera->pitch = phi_f14;
    gCamera->targetPitch = phi_f14;
    gCamera->yaw = ((((s32) (D_803F6464->yRotation * 256) / 360) + 128) & 0xFF);
    gCamera->targetYaw = gCamera->yaw;

    gCamera->targetX = (f32)D_803F6464->position.xPos.w / 65536.0;
    gCamera->targetZ = (f32)D_803F6464->position.zPos.w / 65536.0;
    gCamera->targetY = ((f32)D_803F6464->position.yPos.w / 65536.0) + ((f32)D_803F6464->unk42 * 0.73);

    sp2C = cosf(((phi_f14 * 6.2832) / 360.0));
    gCamera->eyeX = (gCamera->targetX - (sinf((gCamera->yaw * 6.2832 * 0.00390625)) * (phi_f20 * sp2C)));
    sp2C = cosf(((phi_f14 * 6.2832) / 360.0));
    gCamera->eyeZ = (gCamera->targetZ - (cosf((gCamera->yaw * 6.2832 * 0.00390625)) * (phi_f20 * sp2C)));
    gCamera->eyeY = ((sinf(((phi_f14 * 6.2832) / 360.0)) * phi_f20) + gCamera->targetY);
    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;
    gCamera->panOffsetZ = 0.0f;
    gCamera->panOffsetX = gCamera->panOffsetZ;
}

void func_8033B9B8_74D068(u8 arg0) {
    s32 pad2[4] UNUSED;

    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;

    s32 pad[10] UNUSED;

    f32 sp2C;
    f32 sp28;
    f32 sp24;

    f32 temp_f0_5;
    f32 tmp;

    gCamera = &gCameras[arg0];
    gCamera->waypointProgress++;

    gCamera->targetYaw += MIN(1.7, 0.5 + (gCamera->waypointProgress / 100.0));
    tmp = gCamera->targetYaw; // regalloc helper
    gCamera->yaw = tmp;

    if (gCamera->targetPitch < 42.0) {
        gCamera->targetPitch += 0.1;
        gCamera->pitch = gCamera->targetPitch;
    }
    if (gCamera->cameraMode == CAMERA_MODE_SPIN_2) {
        if (gCamera->targetDistance < 1000.0) {
            gCamera->targetDistance += 2.0;
            gCamera->distance = gCamera->targetDistance;
        }
    }

    sp6C = gCamera->focusX;
    sp68 = gCamera->focusZ;
    sp64 = gCamera->focusY + 4.0;

    if ((NABS(sp6C - gCamera->focusX) <= 10.0f) &&
        (ABS(sp68 - gCamera->focusZ) <= 10.0f) &&
        (ABS(sp64 - gCamera->focusY) <= 10.0f)) {
        cameraSettledFlag = 1;
    }

    sp60 = (0.95f * sp6C) - (0.95f * gCamera->targetX);
    sp5C = (0.95f * sp68) - (0.95f * gCamera->targetZ);
    sp58 = (0.95f * sp64) - (0.95f * gCamera->targetY);

    if (ABSF(sp60) < 0.1) {
        sp60 = 0.0f;
    }
    if (ABSF(sp5C) < 0.1) {
        sp5C = 0.0f;
    }
    if (ABSF(sp58) < 0.1) {
        sp58 = 0.0f;
    }

    if (ABSF(sp60) < ABSF(gCamera->targetVelX)) {
        sp2C = 0.0f;
    } else {
        sp2C = sp60 - gCamera->targetVelX;
    }

    if (ABSF(sp5C) < ABSF(gCamera->targetVelZ)) {
        sp28 = 0.0f;
    } else {
        sp28 = sp5C - gCamera->targetVelZ;
    }

    if (ABSF(sp58) < ABSF(gCamera->targetVelY)) {
        sp24 = 0.0f;
    } else {
        sp24 = sp58 - gCamera->targetVelY;
    }

    temp_f0_5 = sqrtf((sp2C * sp2C) + (sp28 * sp28) + (sp24 * sp24));
    if ((temp_f0_5 > 0.0) && ((6.0f / temp_f0_5) < 1.0)) {
        if (sp2C != 0.0) {
            sp60 = gCamera->targetVelX + ((sp2C * 6.0f) / temp_f0_5);
        }
        if (sp28 != 0.0) {
            sp5C = gCamera->targetVelZ + ((sp28 * 6.0f) / temp_f0_5);
        }
        if (sp24 != 0.0) {
            sp58 = gCamera->targetVelY + ((sp24 * 6.0f) / temp_f0_5);
        }
        if (1) { }
    }
    gCamera->targetVelX = sp60;
    gCamera->targetVelZ = sp5C;
    gCamera->targetVelY = sp58;

    gCamera->targetX += sp60;
    gCamera->targetZ += sp5C;
    gCamera->targetY += sp58;

    if (cameraSnapFlag != 0) {
        gCamera->targetX = sp6C;
        gCamera->targetZ = sp68;
        gCamera->targetY = sp64;
        gCamera->targetVelX = gCamera->targetVelZ = gCamera->targetVelY = 0.0f;
    }

    func_8033E6B8_74FD68(gCamera->pitch, gCamera->yaw, gCamera->distance,
                         &gCamera->eyeX, &gCamera->eyeZ, &gCamera->eyeY);

    if (gCamera->followSpeed != gCamera->targetFollowSpeed) {
        if (gCamera->followSpeed < gCamera->targetFollowSpeed) {
            gCamera->followSpeed += 1;
        } else {
            gCamera->followSpeed -= 1;
        }
    }
    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;
}

void func_8033C054_74D704(u8 arg0) {
    f32 temp_f20;

    f64 temp_f22;
    f64 temp_f2;

    temp_f2 = 0.7111111111111111;
    temp_f22 = 6.2832;

    gCamera = &gCameras[arg0];

    gCamera->eyeX = gCamera->followEntity->position.xPos.w / 65536.0;
    gCamera->eyeZ = gCamera->followEntity->position.zPos.w / 65536.0;
    gCamera->eyeY = gCamera->followEntity->position.yPos.w / 65536.0;

    temp_f20 = gCamera->followEntity->yRotation * temp_f2;
    gCamera->yaw = temp_f20;
    gCamera->targetYaw = temp_f20;

    temp_f20 = gCamera->followEntity->zRotation * temp_f2;
    gCamera->pitch = temp_f20;
    gCamera->targetPitch = temp_f20;

    temp_f20 = sinf((gCamera->targetYaw * temp_f22 * 0.00390625));
    gCamera->targetX = ((cosf((gCamera->targetPitch * temp_f22 * 0.00390625)) * temp_f20) * 256.0) + gCamera->eyeX;
    temp_f20 = cosf((gCamera->targetYaw * temp_f22 * 0.00390625));
    gCamera->targetZ = ((cosf((gCamera->targetPitch * temp_f22 * 0.00390625)) * temp_f20) * 256.0) + gCamera->eyeZ;
    gCamera->targetY = (sinf((gCamera->targetPitch * temp_f22 * 0.00390625)) * 256.0) + gCamera->eyeY;

    gCamera->upX = 0.0f;
    gCamera->upZ = 0.0f;
    gCamera->upY = 1.0f;

    gCamera->focusX = gCamera->targetX;
    gCamera->focusZ = gCamera->targetZ;
    gCamera->focusY = gCamera->targetY;
}

// ESA: func_8002A3C0
void func_8033C320_74D9D0(u8 arg0) {
    cameraSettledFlag = 1;
}

// ESA: func_8002A3D0
void reset_camera(void) {
    s32 pad UNUSED;
    s16 i;

    memset_bytes((u8*)&gCameras, 0, sizeof(gCameras)); // zero out both camera structs
    memset_bytes((u8*)&sAmbientCameraTrigger, 0, sizeof(sAmbientCameraTrigger));
    memset_bytes((u8*)&gCameraTriggerQueue, 0, sizeof(gCameraTriggerQueue));
    memset_bytes((u8*)&D_803F2C18, 0, sizeof(D_803F2C18));

    gCameraTriggerQueue[0].unkA = -1;
    gCameraId = 0;
    gPrevCameraId = 1;
    gCameraShakeMagnitude = 0;
    D_803F2A9A = 0xFF;
    cameraSnapFlag = 0;
    D_803A6CC4_7B8374 = 1.0f;
    D_803A6CC8_7B8378 = 45.0f;
    D_803A6CCC_7B837C = 1.0f;
    gCameraUiState = 0;
    D_803A6CE0_7B8390 = 0;
    D_803A6CE4_7B8394 = 0;
    D_803A6CE8_7B8398 = 0;
    gCamera = &gCameras[0];
    gCameraScriptHead = 0;
    gCameraScriptTail = 1;
    gCameraTriggerQueue[0].unk12 = 0;
    gCameraTriggerQueue[0].unk17 = 1;
    gCameraTriggerQueue[0].unk8 = 0;

    gCameras[0].followType = 1;
    gCameras[1].followType = 1;

    func_80319F58_72B608(
        D_803A6D14_7B83C4,
        (gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h >> 6),
        (gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h >> 6),
        (gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h >> 6),
        gCameraFocusCellIndex,
        &D_803F2C6C,
        &D_803F2C6D);

    gCameraVisibilityMask[0] = D_803A7114_7B87C4[D_803F2C6D].unk4;
    gCameraVisibilityMask[1] = D_803A7114_7B87C4[D_803F2C6D].unk6;
    gCameraVisibilityMask[2] = D_803A7114_7B87C4[D_803F2C6D].unk8;
    gCameraVisibilityMask[3] = D_803A7114_7B87C4[D_803F2C6D].unkA;
    gCameraVisibilityMask[4] = D_803A7114_7B87C4[D_803F2C6D].unkC;
    gCameraVisibilityMask[5] = D_803A7114_7B87C4[D_803F2C6D].unkE;
    gCameraVisibilityMask[6] = D_803A7114_7B87C4[D_803F2C6D].unk10;
    gCameraVisibilityMask[7] = D_803A7114_7B87C4[D_803F2C6D].unk12;

    gCameras[0].zoomIndexMin = (s8)D_803A7114_7B87C4[D_803F2C6D].unk12 >> 4;
    gCameras[0].zoomIndexMax = (s8)(D_803A7114_7B87C4[D_803F2C6D].unk12 << 4) >> 4;
    gCameras[0].autoPan = (D_803A7114_7B87C4[D_803F2C6D].unk12 >> 8) & 1;
    gCameras[0].zoomIndex = gCameras[1].zoomIndex = ((gCameras[0].zoomIndexMin + gCameras[0].zoomIndexMax) - 1) >> 1;

    gCameras[0].modeId = D_803F2C6C;
    func_80343C44_7552F4(D_803F2C6C, &gCameras[0].cameraMode, &gCameras[0].heightOverride);
    gCameras[0].distance = gCameras[0].targetDistance = gCameras[0].baseDistance = 0xC8;
    gCameras[0].focusHeightOffset = 0xA;

    gCameraScriptTimer = 0;

    gCameras[0].targetX = gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h;
    gCameras[0].targetZ = gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h;
    gCameras[0].targetY = gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h;

    gCameras[0].distance = gCameras[0].targetDistance = gCameras[0].baseDistance = 0xFA;
    gCameras[0].cameraHeight = gCameras[0].targetPitch = gCameras[0].pitch = 25.0f;

    gCameras[0].offsetXTarget = -0x20;
    gCameras[0].offsetYTarget = 0x10;
    gCameras[0].targetFollowSpeed = 0x14;
    gCameras[0].unk60 = 0x10;

    playerCameraDistance = MAX(gCameras[0].zoomIndexMin, 0);
    playerCameraDistance = MIN(gCameras[0].zoomIndexMax, playerCameraDistance);
    gCameras[0].zoomIndex = playerCameraDistance;

    gCameras[0].targetYaw = (D_803F2D50.cameraHeading << 8) / 360;
    gCameras[0].yaw = (D_803F2D50.cameraHeading << 8) / 360;
    gCameras[0].useAreaVisibility = 1;

    gCameras[0].fixPosX = D_803A7114_7B87C4[D_803F2C6D].unk0;
    gCameras[0].fixPosZ = D_803A7114_7B87C4[D_803F2C6D].unk1;
    gCameras[0].fixPosY = D_803A7114_7B87C4[D_803F2C6D].unk2;

    gAnimalState.animals[gCurrentAnimalIndex].animal->heading = (D_803F2D50.startHeading << 8) / 360;
    gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation = (D_803F2D50.startHeading << 8) / 360;
    gCameras[0].zoomInterp = gCameras[0].zoomIndex * 8;

    for (i = 0; i < 50; i++) {
        set_camera_mode(0, 0);
    }
    D_803A6CEC_7B839C = -1;
}

// ESA: func_8002A8D4
s16 func_8033C814_74DEC4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C += arg6;
    sp38 += arg7;
    return func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, sp34, 127, 1, arg8);
}

s16 func_8033C8EC_74DF9C(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C += arg6;
    sp38 += arg7;
    return func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, (s16)sp34 + 34, 127, 1, 0);
}

// esa: func_8001D8F4
s16 func_8033C9CC_74E07C(s16 arg0, s16 arg1, s16 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s32 pad UNUSED;

    s16 temp;
    s16 sp78;
    s16 sp76;
    s16 mode;

    s16 var_s1;
    u8 var_a2;  // sp71?
    s16 var_s0;

    s32 pad2 UNUSED;   // sp68?
    s32 var_s3; // sp64
    s32 var_s4; // sp60

    s32 sp5C;
    s32 sp58;

    if (arg7 == 0x7F) {
        if ((arg4 < 0) || (arg4 > (72*64)) || (arg5 < 0) || ((arg5 > (128*64)) &&
            ((arg9 == 0) || ((arg4 >= 4) && (arg4 < 68))))) {
            arg7 = 0;
        } else {
            if ((arg6 < (sample_ground_height_at_xz(arg4, arg5) >> 0x10)) &&
                ((arg8 == 0) || ((D_803C0740[arg4 >> 6][arg5 >> 6].unk4 & 0x40) == 0)) &&
                ((arg9 == 0) || ((arg4 >= 4) && (arg4 < 68)))) {
                return 1;
            }
            if (D_803C0740[(arg4 >> 6)][(arg5 >> 6)].unk3 != 0) {
                if ((s16) (func_80310F58_722608(arg4, arg5) >> 0x10) < arg6) {
                    arg7 = 2;
                } else {
                    arg7 = 1;
                }
            } else {
                arg7 = 0;
            }
        }
    }

    if (arg3 == 0x7F) {
        if ((arg0 <= 64) || (arg0 >= (71*64)) || (arg1 <= 64) || (arg1 >= (127*64))) {
            arg3 = 0;
        } else {
            if ((arg2 < (sample_ground_height_at_xz(arg0, arg1) >> 0x10)) && ((arg8 == 0) || ((D_803C0740[arg0 >> 6][arg1 >> 6].unk4 & 0x40) == 0)) && ((arg9 == 0) || ((arg4 >= 4) && (arg4 < 68)))) {
                return 1;
            }
            if (D_803C0740[(arg0 >> 6)][(arg1 >> 6)].unk3 != 0) {
                if ((s16) (func_80310F58_722608(arg0, arg1) >> 0x10) < arg2) {
                    arg3 = 2;
                } else {
                    arg3 = 1;
                }
            } else {
                arg3 = 0;
            }
        }
    }

    var_a2 = arg7;
    arg2 = arg2 + 4;

    if ((arg0 > (1*64)) && (arg0 < (71*64)) &&
        (arg1 > (1*64)) && (arg1 < (127*64))) {
        arg2 = MAX((sample_ground_height_at_xz(arg0, arg1) >> 0x10) + 4, arg2);
    }

    sp78 = arg0 - arg4;
    sp76 = arg1 - arg5;
    temp = arg2 - arg6;

    if (sp78 == 0) {
        sp78 = 1;
    }
    if (sp76 == 0) {
        sp76 = 1;
    }
    if (sp78 >= 0) {
        if (sp76 >= 0) {
            mode = 0;
        } else {
            mode = 1;
        }
    } else {
        if (sp76 >= 0) {
            mode = 2;
        } else {
            mode = 3;
        }
    }

    switch (mode) {
    case 0:
        var_s3 = ((0x40 - (arg4 & 0x3F)) << 0xE) / sp78;
        sp5C = 0x100000 / sp78;
        var_s4 = ((0x40 - (arg5 & 0x3F)) << 0xE) / sp76;
        sp58 = 0x100000 / sp76;
        break;
    case 1:
        var_s3 = ((0x40 - (arg4 & 0x3F)) << 0xE) / sp78;
        sp5C = 0x100000 / sp78;
        var_s4 = ((       (arg5 & 0x3F)) << 0xE) / -sp76;
        sp58 = 0x100000 / -sp76;
        break;
    case 2:
        var_s3 = ((       (arg4 & 0x3F)) << 0xE) / -sp78;
        sp5C = 0x100000 / -sp78;
        var_s4 = ((0x40 - (arg5 & 0x3F)) << 0xE) / sp76;
        sp58 = 0x100000 / sp76;
        break;
    case 3:
        var_s3 = (((arg4 & 0x3F) << 0xE)) / -sp78;
        sp5C = 0x100000 / -sp78;
        var_s4 = (((arg5 & 0x3F) << 0xE)) / -sp76;
        sp58 = 0x100000 / -sp76;
        break;
    }

    var_s0 = arg4 >> 6;
    var_s1 = arg5 >> 6;

    while ((var_s4 < (256*64)) || (var_s3 < (256*64))) {

        if (var_s4 <= var_s3) {
            switch (mode) {
            case 0:
            case 2:
                // move camera along z axis +
                if (var_a2 == 3) {
                    var_a2 = 0;
                }

                var_a2 = func_80312A44_7240F4(
                    var_s0,
                    var_s1++,
                    (arg4 + ((var_s4 * sp78) >> 0xE)) - (var_s0 << 6),
                    (arg6 + ((var_s4 * temp) >> 0xE)),
                    var_a2,
                    arg8);
                if ((var_a2 == 3) && ((arg9 == 0) || ((var_s0 >= 4) && (var_s0 < 68)))) {
                    return 2;
                }
                break;
            case 1:
            case 3:
                // move camera along z axis -
                if (var_a2 == 3) {
                    var_a2 = 0;
                }

                var_a2 = func_803126F4_723DA4(
                    var_s0,
                    var_s1--,
                    (arg4 + ((var_s4 * sp78) >> 0xE)) - (var_s0 << 6),
                    (arg6 + ((var_s4 * temp) >> 0xE)),
                    var_a2,
                    arg8);
                if ((var_a2 == 3) && ((arg9 == 0) || ((var_s0 >= 4) && (var_s0 < 68)))) {
                    return 2;
                }
                break;

            }
            var_s4 += sp58;
        } else {
            switch (mode) {
            case 0:
            case 1:
                // move camera along x axis +
                if (var_a2 == 3) {
                    var_a2 = 0;
                }

                var_a2 = func_803123A4_723A54(
                    var_s0++,
                    var_s1,
                    (arg5 + ((var_s3 * sp76) >> 0xE)) - (var_s1 << 6),
                    arg6 + ((var_s3 * temp) >> 0xE),
                    var_a2,
                    arg8);
                if ((var_a2 == 3) && ((arg9 == 0) || ((var_s0 >= 4) && (var_s0 < 0x44)))) {
                    return 2;
                }
                break;
            case 2:
            case 3:
                // move camera along x axis -
                if (var_a2 == 3) {
                    var_a2 = 0;
                }

                var_a2 = func_80312054_723704(
                    var_s0--,
                    var_s1,
                    ((arg5 + ((var_s3 * sp76) >> 0xE)) - (var_s1 << 6)),
                    (arg6 + ((var_s3 * temp) >> 0xE)),
                    var_a2,
                    arg8);
                if ((var_a2 == 3) && ((arg9 == 0) ||
                    ((var_s0 >= 4) && (var_s0 < 0x44)))) {
                    return 2;
                }
                break;
            }
            var_s3 += sp5C;
        }
    }

    if ((((var_a2 == 2) && (arg3 == 1)) ||
         ((var_a2 == 1) && (arg3 == 2))) &&
         ((arg8 == 0) || ((D_803C0740[arg0 >> 6][arg1 >> 6].unk4 & 0x80) == 0))) {
        return 2;
    } else {
        return 0;
    }
}

// camera collision checks
// ESA: func_8002AAC8
s16 func_8033D604_74ECB4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 spA4;
    f32 spA0;
    f32 sp9C;

    s16 sp9A;
    s16 sp98;
    s16 sp96;

    s16 sp94;
    s16 sp92;
    s16 sp90;

    s16 temp_s0;
    s16 temp_s1;
    s16 temp_s2;

    s16 var_a0;
    s16 var_a1;
    s16 var_a2;

    s16 var_s5;
    s16 var_s6;

    s16 var_s7;

    s32 var_s3;
    s32 var_s4;

    s32 sp70;
    s32 sp6C;

    if (gCameraSettleTimer != 0) {
        return 0;
    }

    func_8033E6B8_74FD68(arg3, arg4, arg5, &spA4, &spA0, &sp9C);

    spA4 = spA4 + arg6;
    spA0 = spA0 + arg7;

    sp9A = spA4;
    sp98 = spA0;
    sp96 = sp9C;

    sp94 = sp9A - arg0;
    sp92 = sp98 - arg1;
    sp90 = sp96 - arg2;

    if (sp94 == 0) {
        sp94 = 1;
    }
    if (sp92 == 0) {
        sp92 = 1;
    }
    if (sp94 >= 0) {
        if (sp92 >= 0) {
            var_s7 = 0;
        } else {
            var_s7 = 1;
        }
    } else {
        if (sp92 >= 0) {
            var_s7 = 2;
        } else {
            var_s7 = 3;
        }
    }

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;

    switch (var_s7) {                               /* irregular */
    case 0:
        var_s3 = ((0x400 - (arg0 & 0x3FF)) << 0xE) / sp94;
        sp70 = 0x01000000 / sp94;
        var_s4 = ((0x400 - (arg1 & 0x3FF)) << 0xE) / sp92;
        sp6C = 0x01000000 / sp92;
        break;
    case 1:
        var_s3 = ((0x400 - (arg0 & 0x3FF)) << 0xE) / sp94;
        sp70 = 0x01000000 / sp94;
        var_s4 = ((arg1 & 0x3FF) << 0xE) / -sp92;
        sp6C = 0x01000000 / -sp92;
        break;
    case 2:
        var_s3 = ((arg0 & 0x3FF) << 0xE) / -sp94;
        sp70 = 0x01000000 / -sp94;
        var_s4 = ((0x400 - (arg1 & 0x3FF)) << 0xE) / sp92;
        sp6C = 0x01000000 / sp92;
        break;
    case 3:
        var_s3 = ((arg0 & 0x3FF) << 0xE) / -sp94;
        sp70 = 0x01000000 / -sp94;
        var_s4 = ((arg1 & 0x3FF) << 0xE) / -sp92;
        sp6C = 0x01000000 / -sp92;
        break;
    }

    var_s5 = arg0 >> 0xA;
    var_s6 = arg1 >> 0xA;

    while ((var_s4 < (256*64)) || (var_s3 < (256*64))) {
        if (var_s4 <= var_s3) {
            switch (var_s7) {                       /* switch 2; irregular */
            case 0:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                temp_s0 = arg0 + ((var_s4 * sp94) >> 0xE);
                temp_s1 = arg1 + ((var_s4 * sp92) >> 0xE);
                temp_s2 = arg2 + ((var_s4 * sp90) >> 0xE);
                if (func_8033DF88_74F638(
                    var_a0,
                    var_a1,
                    var_a2,
                    temp_s0,
                    temp_s1,
                    temp_s2,
                    var_s5,
                    var_s6++,
                    arg0,
                    arg1) == 3) {
                    return 3;
                }
                var_a0 = temp_s0;
                var_a1 = temp_s1;
                var_a2 = temp_s2;
                break;
            case 1:
            case 3:                                /* switch 2 */
                temp_s0 = arg0 + ((var_s4 * sp94) >> 0xE);
                temp_s1 = arg1 + ((var_s4 * sp92) >> 0xE);
                temp_s2 = arg2 + ((var_s4 * sp90) >> 0xE);
                if (func_8033DF88_74F638(
                    var_a0,
                    var_a1,
                    var_a2,
                    temp_s0,
                    temp_s1,
                    temp_s2,
                    var_s5,
                    var_s6--,
                    arg0,
                    arg1) == 3) {
                    return 3;
                }
                var_a0 = temp_s0;
                var_a1 = temp_s1;
                var_a2 = temp_s2;
                break;
            }
            var_s4 += sp6C;
        } else {
            switch (var_s7) {                       /* switch 1; irregular */
            case 0:                                 /* switch 1 */
            case 1:                                 /* switch 1 */
                temp_s0 = arg0 + ((var_s3 * sp94) >> 0xE);
                temp_s1 = arg1 + ((var_s3 * sp92) >> 0xE);
                temp_s2 = arg2 + ((var_s3 * sp90) >> 0xE);
                if (func_8033DF88_74F638(
                    var_a0,
                    var_a1,
                    var_a2,
                    temp_s0,
                    temp_s1,
                    temp_s2,
                    var_s5++,
                    var_s6,
                    arg0,
                    arg1) == 3) {
                    return 3;
                }
                var_a0 = temp_s0;
                var_a1 = temp_s1;
                var_a2 = temp_s2;
                break;
            case 2:                                 /* switch 1 */
            case 3:
                temp_s0 = arg0 + ((var_s3 * sp94) >> 0xE);
                temp_s1 = arg1 + ((var_s3 * sp92) >> 0xE);
                temp_s2 = arg2 + ((var_s3 * sp90) >> 0xE);
                if (func_8033DF88_74F638(
                    var_a0,
                    var_a1,
                    var_a2,
                    temp_s0,
                    temp_s1,
                    temp_s2,
                    var_s5--,
                    var_s6,
                    arg0,
                    arg1) == 3) {
                    return 3;
                }
                var_a0 = temp_s0;
                var_a1 = temp_s1;
                var_a2 = temp_s2;
                break;

            }
            var_s3 += sp70;
        }
    }

    if (func_8033DF88_74F638(
        var_a0,
        var_a1,
        var_a2,
        sp9A,
        sp98,
        sp96,
        var_s5,
        var_s6,
        arg0,
        arg1) == 3) {
        return 3;
    } else {
        return 0;
    }
}

// ESA: func_8002B0E4
s16 func_8033DF88_74F638(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    Animal *animal;
    s16 xPos;
    s16 zPos;
    s16 yPos;
    s16 temp_s3;
    s16 temp_t6;
    s16 new_var;

    s32 var_s4;

    s32 var_t2;
    CollisionNode *var_t1;

    if (arg6 < 0) {
        return 0;
    }
    if (arg7 < 0) {
        return 0;
    }
    if (arg6 >= 5) {
        return 0;
    }
    if (arg7 >= 8) {
        return 0;
    }

    // swap arg0,1,2 <> arg3,4,5
    if (arg2 > arg5) {
        temp_t6 = arg0;arg0 = arg3;arg3 = temp_t6;
        temp_t6 = arg1;arg1 = arg4;arg4 = temp_t6;
        temp_t6 = arg2;arg2 = arg5;arg5 = temp_t6;
    }

    for (var_t1 = D_803DA110[(s16) (arg6 + (arg7 * 5))].next, var_t2 = 0; var_t1 != NULL; var_t1 = var_t1->next) {
        animal = var_t1->animal;
        if ((animal->unk16C->behaviourFlags.unk6) && ((animal->unk3E < 0x40) || (animal->unk3E >= 0xC0)) && (animal->unk3E != 0x28)) {

            temp_s3 = animal->position.yPos.h + animal->unk42;
            xPos = animal->position.xPos.h; zPos = animal->position.zPos.h;  yPos = animal->position.yPos.h;
            new_var = animal->unk30;
            new_var = SQ(new_var);

            if ((arg2 < temp_s3) && (yPos < arg5)) {
                if (arg2 < yPos) {
                    arg0 += ((arg3 - arg0) * (yPos - arg2)) / (arg5 - arg2);
                    arg1 += ((arg4 - arg1) * (yPos - arg2)) / (arg5 - arg2);
                    arg2 = yPos;
                }

                if (temp_s3 < arg5) {
                    arg3 += ((arg0 - arg3) * (arg5 - temp_s3)) / (arg5 - arg2);
                    arg4 += ((arg1 - arg4) * (arg5 - temp_s3)) / (arg5 - arg2);
                    arg5 = temp_s3;
                }

                if (var_t2 == 0) {
                    var_t2 = SQ(arg3 - arg0) + SQ(arg4 - arg1);
                    if (var_t2 == 0) {
                        var_t2++;
                    }
                }

                if ((!new_var) && (!new_var)) {}; // fake

                var_s4 = ((((xPos - arg0) * (arg3 - arg0)) + ((zPos - arg1) * (arg4 - arg1))) << 8) / var_t2;
                if (var_s4 < 0) {
                    var_s4 = 0;
                }
                if (var_s4 > 0x100) {
                    var_s4 = 0x100;
                }

                if (((SQ((arg0 + (((arg3 - arg0) * var_s4) >> 8)) - xPos) + SQ((arg1 + (((arg4 - arg1) * var_s4) >> 8)) - zPos)) >= new_var) ||
                    (((SQ(arg8 - xPos)) + SQ(arg9 - zPos)) < new_var)) {
                    continue;
                }
                return 3;
            }
        }
    }
    return 0;
}

// ESA: func_8002B460
void func_8033E430_74FAE0(void) {
    Animal *animal;
    s16 xPos;
    s16 yPos;
    s16 pad UNUSED;
    s16 temp_a0_2;
    s16 sp32;
    s16 phi_v0_2;

    if (gAnimalState.animals[gCurrentAnimalIndex].unk0->unkC6 & 8) {
        D_803F2A9E = 0;
        return;
    }

    animal = gAnimalState.animals[gCurrentAnimalIndex].animal;
    if ((animal->movementState & 0xF) == MOVEMENT_STATE_GROUND) {
        xPos = animal->position.xPos.h + (((SIN(animal->yRotation + gCamera->targetYaw) >> 7) << 7) >> 8);
        yPos = animal->position.zPos.h + (((COS(animal->yRotation + gCamera->targetYaw) >> 7) << 7) >> 8);

        sp32 = (func_80310F58_722608(xPos, yPos) >> 0x10);
        temp_a0_2 = sample_ground_height_at_xz(xPos, yPos) >> 0x10;
        if (sp32 == 0x4000) {
            phi_v0_2 = temp_a0_2 - animal->position.yPos.h;
        } else {
            if (animal->unk160 == 2) {
                phi_v0_2 = sp32 - animal->position.yPos.h;
            } else if (func_8033C9CC_74E07C(
                    animal->position.xPos.h,
                    animal->position.zPos.h,
                    gAnimalState.animals[gCurrentAnimalIndex].unk0->height + animal->position.yPos.h,
                    animal->unk160,
                    xPos,
                    yPos,
                    (sp32 + temp_a0_2) >> 1,
                    0x7F,
                    1,
                    0) == 0) {
                phi_v0_2 = temp_a0_2 - animal->position.yPos.h;
            } else {
                phi_v0_2 = sp32 - animal->position.yPos.h;
            }
        }
        // clamp
        if (phi_v0_2 < -240) {
            phi_v0_2 = -240;
        }
        if (phi_v0_2 > 240) {
            phi_v0_2 = 240;
        }

        if (D_803F2A9E < phi_v0_2) {
            D_803F2A9E = MIN(phi_v0_2, D_803F2A9E + 6);
        } else if (phi_v0_2 < D_803F2A9E) {
            D_803F2A9E = MAX(phi_v0_2, D_803F2A9E - 6);
        }
    }
}

// ESA: func_8002B6A8
void func_8033E6B8_74FD68(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 tmp0;

    tmp0 = sinf(arg1 * 6.2832 * (256 / 65536.0));
    *arg3 = gCamera->targetX - cosf(arg0 * 6.2832 * (256 / 65536.0)) * (arg2 * tmp0);
    tmp0 = cosf(arg1 * 6.2832 * (256 / 65536.0));
    *arg4 = gCamera->targetZ - cosf(arg0 * 6.2832 * (256 / 65536.0)) * (arg2 * tmp0);
    *arg5 = gCamera->targetY + sinf(arg0 * 6.2832 * (256 / 65536.0)) * arg2;
}

void func_8033E7C8_74FE78(OSContPad *cont) {
    static u16 sPrevButtonState; // .bss
    s16 phi_v0;
    u16 button = cont->button;

    if (((button & D_CBUTTONS)) && (!(sPrevButtonState & D_CBUTTONS)) &&
        (button & U_CBUTTONS)) {
            gCameraUiState = 0;
            D_803F2C6C = D_803F2C6D = 0;
    }

    phi_v0 = MIN(gCameras[gCameraId].zoomIndexMax, playerCameraDistance);
    gCameras[gCameraId].zoomIndex = MAX(gCameras[gCameraId].zoomIndexMin, phi_v0);

    switch (gCameras[gCameraId].cameraMode) {
    case CAMERA_MODE_1:
    case CAMERA_MODE_26:
        if (gCameras[gCameraId].followType == 1) {
            if ((cont->button & R_CBUTTONS) && (!(sPrevButtonState & R_CBUTTONS))) {
                if (gCameras[gCameraId].panRightAvailable == 0) {
                    func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
                } else {
                    func_8032C508_73DBB8(SFX_CAMERA_PAN, 0x2A00, 0, 1.0f);
                    if ((gCameras[gCameraId].targetYaw > 0.0) &&
                        (gCameras[gCameraId].targetYaw < 32.0)) {
                        gCameras[gCameraId].targetYaw = 0.0f;
                    } else if ((gCameras[gCameraId].targetYaw > 64.0) &&
                               (gCameras[gCameraId].targetYaw < 96.0)) {
                        gCameras[gCameraId].targetYaw = 64.0f;
                    } else if ((gCameras[gCameraId].targetYaw > 128.0) &&
                               (gCameras[gCameraId].targetYaw < 160.0)) {
                        gCameras[gCameraId].targetYaw = 128.0f;
                    } else if ((gCameras[gCameraId].targetYaw > 192.0) &&
                               (gCameras[gCameraId].targetYaw < 224.0)) {
                        gCameras[gCameraId].targetYaw = 192.0f;
                    } else {
                        gCameras[gCameraId].targetYaw -= 32.0;
                    }
                    if (gCameras[gCameraId].targetYaw < 0.0) {
                        gCameras[gCameraId].targetYaw += 256.0;
                    }

                    if (gCameras[gCameraId].cameraMode == CAMERA_MODE_26) {
                        gCameras[gCameraId].panCooldown = 60;
                    } else {
                        gCameras[gCameraId].panCooldown = 200;
                    }
                }
            }
            if ((cont->button & L_CBUTTONS) && (!(sPrevButtonState & L_CBUTTONS))) {
                if (gCameras[gCameraId].panLeftAvailable == 0) {
                    func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
                } else {
                    func_8032C508_73DBB8(SFX_CAMERA_PAN, 0x2A00, 0, 1.0f);
                    if ((gCameras[gCameraId].targetYaw > 32.0) && (gCameras[gCameraId].targetYaw < 64.0)) {
                        gCameras[gCameraId].targetYaw = 64.0f;
                    } else if ((gCameras[gCameraId].targetYaw > 96.0) && (gCameras[gCameraId].targetYaw < 128.0)) {
                        gCameras[gCameraId].targetYaw = 128.0f;
                    } else if ((gCameras[gCameraId].targetYaw > 160.0) && (gCameras[gCameraId].targetYaw < 192.0)) {
                        gCameras[gCameraId].targetYaw = 192.0f;
                    } else if ((gCameras[gCameraId].targetYaw > 224.0) && (gCameras[gCameraId].targetYaw < 256.0)) {
                        gCameras[gCameraId].targetYaw = 256.0f;
                    } else {
                        gCameras[gCameraId].targetYaw += 32.0;
                    }
                    if (gCameras[gCameraId].targetYaw > 256.0) {
                        gCameras[gCameraId].targetYaw -= 256.0;
                    }

                    if (gCameras[gCameraId].cameraMode == CAMERA_MODE_26) {
                        gCameras[gCameraId].panCooldown = 60;
                    } else {
                        gCameras[gCameraId].panCooldown = 200;
                    }
                }
            }

            func_8033EF94_750644(cont, sPrevButtonState);
            if ((gGameState.unk4 > 0) && (gCameras[gCameraId].followType == 1)) {
                playerCameraDistance -= 2;
            }
        }
        break;

    case CAMERA_MODE_2:
    case CAMERA_MODE_12:
        func_8033EF94_750644(cont, sPrevButtonState);
        if ((gGameState.unk4 > 0) && (gCameras[gCameraId].followType == 1)) {
            playerCameraDistance -= 2;
        }
        break;

    case CAMERA_MODE_BEHIND_1:
    case CAMERA_MODE_BEHIND_2:
        if (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType != TORTOISE_TANK) {
            func_8033EF94_750644(cont, sPrevButtonState);
        } else {
            gCameras[gCameraId].targetPitch = 0.0f;
        }
        gCameras[gCameraId].unk68 = 0;
        gCameras[gCameraId].targetYaw = 0.0f;
        break;

    case CAMERA_MODE_OVERHEAD_1:
    case CAMERA_MODE_OVERHEAD_2:
    case CAMERA_MODE_FIXED_32:
    case CAMERA_MODE_FIXED_96:
    case CAMERA_MODE_FIXED_160:
    case CAMERA_MODE_FIXED_224:
    case CAMERA_MODE_FIXED_0:
    case CAMERA_MODE_FIXED_128:
    case CAMERA_MODE_FIXED_64:
    case CAMERA_MODE_FIXED_192:
    case CAMERA_MODE_OVERHEAD_3:
    case CAMERA_MODE_OVERHEAD_4:
    case CAMERA_MODE_OVERHEAD_5:
    case CAMERA_MODE_22:
        if ((gCameras[gCameraId].followType == 1) &&
            ((((cont->button & R_CBUTTONS)) && (!(sPrevButtonState & R_CBUTTONS))) ||
            ((cont->button & L_CBUTTONS) && (!(sPrevButtonState & L_CBUTTONS))))) {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
        }

        func_8033EF94_750644(cont, sPrevButtonState);
        break;

    case CAMERA_MODE_6:
    case CAMERA_MODE_7:
    case CAMERA_MODE_28:
        if (gCameras[gCameraId].followType == 1) {
            func_8033EF94_750644(cont, sPrevButtonState);
        }
        if (gGameState.unk4 > 0) {
            if (gCameras[gCameraId].followType == 1) {
                gCameras[gCameraId].zoomIndex = MIN(gCameras[gCameraId].zoomIndex, -2);
            }
        }
        break;

    case CAMERA_MODE_NONE:
    // case 18:
    // case 23:
    // case 24:
    // case 25:
    // case 27:
    // case 29:
    // case 30:
    case CAMERA_MODE_SPIN_2:
    case CAMERA_MODE_228:
        break;

    }
    sPrevButtonState = cont->button;
}

void func_8033EF94_750644(OSContPad *cont, u16 prevButtonState) {
    u8 res = 0;

    if ((cont->button & U_CBUTTONS) && (!(prevButtonState & U_CBUTTONS))) {
        if (playerCameraDistance < MIN(gCameras[gCameraId].zoomIndexMax, 0)) {
            playerCameraDistance = MIN(MIN(MAX(playerCameraDistance + 1, gCameras[gCameraId].zoomIndex + 1), gCameras[gCameraId].zoomIndexMax), 0);
            gCameras[gCameraId].zoomIndex = playerCameraDistance;
            res = 1;
        } else {
            res = 2;
        }
    }
    if ((cont->button & D_CBUTTONS) && (!(prevButtonState & D_CBUTTONS))) {
        if (playerCameraDistance > MAX(gCameras[gCameraId].zoomIndexMin, -2)) {
            playerCameraDistance = MAX(MAX(MIN(playerCameraDistance - 1, gCameras[gCameraId].zoomIndex - 1), gCameras[gCameraId].zoomIndexMin), -2);
            gCameras[gCameraId].zoomIndex = playerCameraDistance;
            res = 1;
        } else {
            res = 2;
        }
    }

    if (res == 2) {
        func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
    } else if (res == 1) {
        func_8032C508_73DBB8(SFX_CAMERA_PAN, 0x2A00, 0, 1.0f);
    }
}

void decrease_player_camera_distance(s16 dist) {
    if (gCameras[gCameraId].followType == 1) {
        playerCameraDistance -= dist;
    }
}

void increase_player_camera_distance(s16 dist) {
    if (gCameras[gCameraId].followType == 1) {
        playerCameraDistance += dist;
    }
}

void save_player_camera_distance(void) {
    savedPlayerCameraDistance = playerCameraDistance;
}

void restore_player_camera_distance(void) {
    savedPlayerCameraDistance = MIN(savedPlayerCameraDistance, gCameras[gCameraId].zoomIndexMax);
    savedPlayerCameraDistance = MAX(savedPlayerCameraDistance, gCameras[gCameraId].zoomIndexMin);
    playerCameraDistance = savedPlayerCameraDistance;
}

// ESA: func_8002BFF4
void update_world_camera_transform(void) {
    f32 spCC;
    f32 spC8;

    f32 spC4 UNUSED;
    f32 spC0 UNUSED;
    f32 spBC UNUSED;
    f32 spB8 UNUSED;

    f32 spB4;
    f32 spB0;
    f32 spAC;

    f32 temp_f0;
    f32 temp_f2;

    f32 spA0;
    f32 sp9C;
    f32 sp98;

    f32 sp94 UNUSED;
    f32 sp90 UNUSED;

    f32 sp8C;

    f32 sp88 UNUSED;

    f32 sp84;
    f32 sp80;

    f32 sp7C UNUSED;
    f32 sp78 UNUSED;

    f32 sp74;
    f32 sp70;
    f32 sp6C;

    f32 temp_f14;

    Camera *camera1; // sp64
    Camera *camera2; // sp60

    static f32  sBlendedPitch; // .bss
    static f32  sBlendedYaw; // .bss
    static f32  sPrevYawDelta; // .bss

    camera2 = &gCameras[gPrevCameraId];
    camera1 = &gCameras[gCameraId];

    switch (D_803F2C18[0]) {
    case 0:
        gCameraEyeWorldX = camera1->eyeX + camera1->panOffsetX;
        gCameraEyeWorldZ = camera1->eyeZ + camera1->panOffsetZ;
        gCameraEyeWorldY = camera1->eyeY;

        sLookAtTargetX = camera1->targetX + camera1->panOffsetX;
        sLookAtTargetZ = camera1->targetZ + camera1->panOffsetZ;
        sLookAtTargetY = camera1->targetY;

        D_80204200 = camera1->upX;
        D_80204204 = camera1->upZ;
        D_80204208 = camera1->upY;
        D_803F2A9A = 0x100;
        break;
    case 1:
        spCC = 0.5 - (0.5 * cosf((((f32) D_803F2C18[1] / D_803F2C18[2]) * 3.1415)));
        spC8 = 1.0 - spCC;
        gCameraEyeWorldX = (spC8 * (camera2->eyeX + camera2->panOffsetX)) + (spCC * (camera1->eyeX + camera1->panOffsetX));
        gCameraEyeWorldZ = (spC8 * (camera2->eyeZ + camera2->panOffsetZ)) + (spCC * (camera1->eyeZ + camera1->panOffsetZ));
        gCameraEyeWorldY = (spC8 * camera2->eyeY) + (spCC * camera1->eyeY);

        D_80204200 = (spC8 * camera2->upX) + (spCC * camera1->upX);
        D_80204204 = (spC8 * camera2->upZ) + (spCC * camera1->upZ);
        D_80204208 = (spC8 * camera2->upY) + (spCC * camera1->upY);

        if (((camera2->cameraMode == CAMERA_MODE_OVERHEAD_1) ||
             (camera2->cameraMode == CAMERA_MODE_OVERHEAD_3) ||
             (camera2->cameraMode == CAMERA_MODE_OVERHEAD_4) ||
             (camera2->cameraMode == CAMERA_MODE_OVERHEAD_5) ||
             (camera2->cameraMode == CAMERA_MODE_OVERHEAD_2) ||
             (camera2->cameraMode == CAMERA_MODE_22)) &&
             ((camera1->cameraMode == CAMERA_MODE_OVERHEAD_1) ||
              (camera1->cameraMode == CAMERA_MODE_OVERHEAD_3) ||
              (camera1->cameraMode == CAMERA_MODE_OVERHEAD_4) ||
              (camera1->cameraMode == CAMERA_MODE_OVERHEAD_5) ||
              (camera1->cameraMode == CAMERA_MODE_OVERHEAD_2) ||
              (camera1->cameraMode == CAMERA_MODE_22))) {

            temp_f2 = ABSF(camera2->targetYaw - camera1->targetYaw);
            if (temp_f2 == 128.0) {
                D_80204200 = (cosf(spCC * 3.141593) * camera2->upX) + (sinf(spCC * 3.141593) * camera2->upZ);
                D_80204204 = (cosf(spCC * 3.141593) * camera2->upZ) - (sinf(spCC * 3.141593) * camera2->upX);
            }
        }
        spB4 = camera2->targetX - camera2->eyeX;
        spB0 = camera2->targetZ - camera2->eyeZ;
        spAC = camera2->targetY - camera2->eyeY;
        sp84 = func_801286B8(spAC, sqrtf(SQ(spB4) + SQ(spB0)));

        if (sp84 > 180.0) {
            sp84 -= 360.0;
        }
        if ((spB0 == 0.0) && (spB4 == 0.0)) {
            sp80 = 0.0f;
        } else {
            sp80 = func_801286B8(-spB0, spB4);
        }
        spA0 = camera1->targetX - camera1->eyeX;
        sp9C = camera1->targetZ - camera1->eyeZ;
        sp98 = camera1->targetY - camera1->eyeY;

        sp8C = func_801286B8(sp98, sqrtf(SQ(spA0) + SQ(sp9C)));
        if (sp8C > 180.0) {
            sp8C -= 360.0;
        }
        if ((sp9C == 0.0) && (spA0 == 0.0)) {
            temp_f14 = 0.0f;
        } else {
            temp_f14 = func_801286B8(-sp9C, spA0);
        }
        sBlendedPitch = (spCC * sp8C) + (spC8 * sp84);

        if ((camera2->cameraMode == CAMERA_MODE_OVERHEAD_1) ||
            (camera2->cameraMode == CAMERA_MODE_OVERHEAD_3) ||
            (camera2->cameraMode == CAMERA_MODE_OVERHEAD_4) ||
            (camera2->cameraMode == CAMERA_MODE_OVERHEAD_5) ||
            (camera2->cameraMode == CAMERA_MODE_OVERHEAD_2) ||
            (camera2->cameraMode == CAMERA_MODE_22)) {
            sBlendedYaw = temp_f14;
        } else {
            if ((camera1->cameraMode == CAMERA_MODE_OVERHEAD_1) ||
                (camera1->cameraMode == CAMERA_MODE_OVERHEAD_3) ||
                (camera1->cameraMode == CAMERA_MODE_OVERHEAD_4) ||
                (camera1->cameraMode == CAMERA_MODE_OVERHEAD_5) ||
                (camera1->cameraMode == CAMERA_MODE_OVERHEAD_2) ||
                (camera1->cameraMode == CAMERA_MODE_22)) {
                sBlendedYaw = sp80;
            } else {
                temp_f2 = temp_f14 - sp80;

                if (D_803F2C18[1] == 1) {

                    while (temp_f2 > 180.0) {
                        temp_f2 -= 360.0;
                    };

                    while (temp_f2 < -180.0) {
                        temp_f2 += 360.0;
                    };

                    sBlendedYaw = sp80 + (temp_f2 * spCC);
                } else {
                    if (temp_f2 < sPrevYawDelta) {
                        while (ABSF(temp_f2 - sPrevYawDelta) > 180) {
                            temp_f2 += 360.0f;
                        }
                    } else {
                        while (ABSF(temp_f2 - sPrevYawDelta) > 180) {
                            temp_f2 -= 360.0f;
                        }
                    }
                    sBlendedYaw = sp80 + (temp_f2 * spCC);
                }
                sPrevYawDelta = temp_f2;
            }
        }
        sp74 = cosf(sBlendedPitch * (3.14159 / 180));

        sp6C = sinf(sBlendedPitch * (3.14159 / 180));
        sp70 = sinf(sBlendedYaw * (3.14159 / 180)) * -sp74;
        sp74 = cosf(sBlendedYaw * (3.14159 / 180)) * sp74;

        sLookAtTargetX = gCameraEyeWorldX + sp74;
        sLookAtTargetZ = gCameraEyeWorldZ + sp70;
        sLookAtTargetY = gCameraEyeWorldY + sp6C;

        D_803F2A9A = 256;
        break;
    case 2:
        if (D_803F2C18[1] == 1) {
            trigger_screen_transition(5);
        } else if (((D_803F2C18[2] / 2) + 1) == D_803F2C18[1]) {
            trigger_screen_transition(4);
        }
        if ((D_803F2C18[2] / 2) >= D_803F2C18[1]) {
            gCameraEyeWorldX = camera2->eyeX + camera1->panOffsetX;
            gCameraEyeWorldZ = camera2->eyeZ + camera1->panOffsetZ;
            gCameraEyeWorldY = camera2->eyeY;

            sLookAtTargetX = camera2->targetX + camera1->panOffsetX;
            sLookAtTargetZ = camera2->targetZ + camera1->panOffsetZ;
            sLookAtTargetY = camera2->targetY;

            D_80204200 = camera2->upX;
            D_80204204 = camera2->upZ;
            D_80204208 = camera2->upY;
        } else {
            gCameraEyeWorldX = camera1->eyeX + camera1->panOffsetX;
            gCameraEyeWorldZ = camera1->eyeZ + camera1->panOffsetZ;
            gCameraEyeWorldY = camera1->eyeY;

            sLookAtTargetX = camera1->targetX + camera1->panOffsetX;
            sLookAtTargetZ = camera1->targetZ + camera1->panOffsetZ;
            sLookAtTargetY = camera1->targetY;

            D_80204200 = camera1->upX;
            D_80204204 = camera1->upZ;
            D_80204208 = camera1->upY;
        }
        break;
    }

    if (gCameraShakeMagnitude > 0) {
        gCameraShakeMagnitude -= gCameraShakeMagnitude >> 3;
        gCameraShakeMagnitude -= 1;

        if ((camera1->cameraMode == CAMERA_MODE_BEHIND_1) || (camera1->cameraMode == CAMERA_MODE_BEHIND_2)) {
            temp_f0 = ((f32) (advance_random_seed() - 32768.0) * gCameraShakeMagnitude) / (6 * 65536.0f);
            gCameraEyeWorldX += temp_f0;
            sLookAtTargetX += temp_f0;

            temp_f0 = ((f32) (advance_random_seed() - 32768.0) * gCameraShakeMagnitude) / (6 * 65536.0f);
            gCameraEyeWorldZ += temp_f0;
            sLookAtTargetZ += temp_f0;

            temp_f0 = ((f32) (advance_random_seed() - 32768.0) * gCameraShakeMagnitude) / (3 * 65536.0f);
            gCameraEyeWorldY += temp_f0;
            sLookAtTargetY += temp_f0;
        } else {
            temp_f0 = ((f32) (advance_random_seed() - 32768.0) * gCameraShakeMagnitude) / (2 * 65536.0f);
            gCameraEyeWorldX += temp_f0;
            sLookAtTargetX += temp_f0;

            temp_f0 = ((f32) (advance_random_seed() - 32768.0) * gCameraShakeMagnitude) / (2 * 65536.0f);
            gCameraEyeWorldZ += temp_f0;
            sLookAtTargetZ += temp_f0;

            temp_f0 = ((f32) (advance_random_seed() - 32768.0) * gCameraShakeMagnitude) / (1 * 65536.0f);
            gCameraEyeWorldY += temp_f0;
            sLookAtTargetY += temp_f0;
        }
    }
    if ((gCameraEyeWorldX == sLookAtTargetX) && (gCameraEyeWorldZ == sLookAtTargetZ) && (gCameraEyeWorldY == sLookAtTargetY)) {
        sLookAtTargetX += 10.0;
    }
    if ((D_80204200 == 0.0) && (D_80204204 == 0.0) && (D_80204208 == 0.0)) {
        D_80204204 = 10.0f;
    }
    if ((gCameraEyeWorldX == sLookAtTargetX) && (gCameraEyeWorldZ == sLookAtTargetZ)) {
        D_80204200 += 0.0012321; // whats this? almost 5 / 0x1000
    }
    temp_f0 = sqrtf(SQ(D_80204200) + SQ(D_80204204) + SQ(D_80204208));
    D_80204200 /= temp_f0;
    D_80204204 /= temp_f0;
    D_80204208 /= temp_f0;

    D_80204218 = sLookAtTargetX - gCameraEyeWorldX;
    D_8020421C = sLookAtTargetZ - gCameraEyeWorldZ;
    D_80204220 = sLookAtTargetY - gCameraEyeWorldY;

    temp_f0 = sqrtf(SQ(D_80204218) + SQ(D_8020421C) + SQ(D_80204220));
    D_80204218 /= temp_f0;
    D_8020421C /= temp_f0;
    D_80204220 /= temp_f0;

    D_80204224 = D_80204218 * 1024.0;
    D_80204226 = D_8020421C * 1024.0;
    D_80204228 = D_80204220 * 1024.0;

    // Compute the negative cross product of these two vectors:
    // x0 = D_80204200
    // y0 = D_80204204
    // z0 = D_80204208

    // x1 = D_80204218
    // y1 = D_8020421C
    // z1 = D_80204220

    // Cross product:
    // y0 * z1 - z0 * y1
    // z0 * x1 - x0 * z1
    // x0 * y1 - y0 * x1

    // Negative cross product:
    // z0 * y1 - y0 * z1
    // x0 * z1 - z0 * x1
    // y0 * x1 - x0 * y1

    D_8020422C = (D_80204208 * D_8020421C) - (D_80204204 * D_80204220);
    D_80204230 = (D_80204200 * D_80204220) - (D_80204208 * D_80204218);
    D_80204234 = (D_80204204 * D_80204218) - (D_80204200 * D_8020421C);

    temp_f0 = sqrtf(SQ(D_8020422C) + SQ(D_80204230) + SQ(D_80204234));
    if (temp_f0 == 0.0f) {
        D_8020422C = 0.6f;
        D_80204230 = 0.6f;
        D_80204234 = 0.6f;
    } else {
        D_8020422C /= temp_f0;
        D_80204230 /= temp_f0;
        D_80204234 /= temp_f0;
    }

    if (D_803A6CE4_7B8394 & 4) {
        D_80204200 = (0.0015625 * cosf(gGameplayTick / 310.0)) * SINB(D_803F2C3C);
        D_80204204 = (0.0015625 * cosf(gGameplayTick / 310.0)) * COSB(D_803F2C3C);
        guLookAt(
            &gDisplayListContext->unk37490,
            gCameraEyeWorldX,
            gCameraEyeWorldZ,
            gCameraEyeWorldY,
            (gCameraEyeWorldX + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (gCameraEyeWorldZ - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (gCameraEyeWorldY           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204204,
            D_80204208);
    } else if (D_803A6CE4_7B8394 & 1) {
        guLookAt(
            &gDisplayListContext->unk37490,
            gCameraEyeWorldX,
            gCameraEyeWorldZ,
            gCameraEyeWorldY,
            (gCameraEyeWorldX + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (gCameraEyeWorldZ - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (gCameraEyeWorldY           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204204,
            -D_80204208);
    } else if (D_803A6CE4_7B8394 & 2) {
        guLookAt(
            &gDisplayListContext->unk37490,
            gCameraEyeWorldX,
            gCameraEyeWorldZ,
            gCameraEyeWorldY,
            (gCameraEyeWorldX + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (gCameraEyeWorldZ - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (gCameraEyeWorldY           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204208,
            D_80204204);
    } else {
        guLookAt(
            &gDisplayListContext->unk37490,
            gCameraEyeWorldX,
            gCameraEyeWorldZ,
            gCameraEyeWorldY,
            (gCameraEyeWorldX + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (gCameraEyeWorldZ - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (gCameraEyeWorldY           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204204,
            D_80204208);
    }
    D_803F2C5C = sLookAtTargetX - gCameraEyeWorldX;
    D_803F2C60 = sLookAtTargetZ - gCameraEyeWorldZ;

    temp_f0 = sqrtf(SQ(D_803F2C5C) + SQ(D_803F2C60));
    if (temp_f0 == 0.0) {
        D_803F2C5C = 0.7f;
        D_803F2C60 = 0.7f;
    } else {
        D_803F2C5C /= temp_f0;
        D_803F2C60 /= temp_f0;
    }
    sCameraRightX = -D_803F2C60;
    sCameraRightZ = D_803F2C5C;
    D_8020420C = (D_80204234 * D_8020421C) - (D_80204230 * D_80204220);
    D_80204210 = (D_8020422C * D_80204220) - (D_80204234 * D_80204218);
    D_80204214 = (D_80204230 * D_80204218) - (D_8020422C * D_8020421C);
    func_803415BC_752C6C();
    update_billboard_projection_cache();

    D_803F2C40 = func_801286B8(D_80204220, sqrtf(SQ(D_80204218) + SQ(D_8020421C)));
    if (D_803F2C40 > 180.0) {
        D_803F2C40 -= 360.0;
    }

    if ((D_8020421C == 0.0) && (D_80204218 == 0.0)) {
        D_803F2C3C = 0.0f;
    } else {
        D_803F2C3C = func_801286B8(-D_8020421C, D_80204218);
    }
    temp_f0 = gCameraEyeWorldX - sLookAtTargetX;
    temp_f2 = gCameraEyeWorldZ - sLookAtTargetZ;
    temp_f14 = gCameraEyeWorldY - sLookAtTargetY;
    D_803A6CC0_7B8370 = (256.0 * (gCameraEyeWorldY - sLookAtTargetY)) / sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
    D_803F2A9C = sqrtf((65536.0 - ((f32)D_803A6CC0_7B8370 * D_803A6CC0_7B8370)));
}

// ESA: func_8002D0CC
void func_80340E08_7524B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s8 arg5, s8 arg6, u8 arg7, s16 arg8) {
    memset_bytes((u8*)&sImmediateCameraTrigger, 0, 32);
    sImmediateCameraTrigger.unk12 = arg0;
    sImmediateCameraTrigger.unk14 = arg1;
    sImmediateCameraTrigger.unk15 = arg2;
    sImmediateCameraTrigger.unk16 = arg3;
    sImmediateCameraTrigger.unk17 = arg4;
    sImmediateCameraTrigger.unkA = arg8;
    sImmediateCameraTrigger.unk1A = arg6;
    sImmediateCameraTrigger.unk19 = arg5;
    sImmediateCameraTrigger.unk1B = arg7;
    sImmediateCameraTrigger.unk18 = 1;
    func_80340EA4_752554(&sImmediateCameraTrigger, -1);
}

void func_80340EA4_752554(struct062 *arg0, s16 arg1) {
    s16 cameraMode;
    s16 i;
    s16 cameraMode2;
    s16 sp30;
    s8  sp2F;
    s16 temp_v0_5;

    if (D_803F2C18[0] == 0) {
        func_80343C44_7552F4(arg0->unk12, &cameraMode2, &sp30);
        cameraMode = gCameras[gCameraId].cameraMode;
        gPrevCameraId = gCameraId;
        gCameraId = (gCameraId + 1) % 2;

        if (((cameraMode == CAMERA_MODE_2) || (cameraMode2 == CAMERA_MODE_2)) &&
            ((cameraMode != CAMERA_MODE_12) && (cameraMode2 != CAMERA_MODE_12))) {
            D_803F2C18[0] = 2;
        } else {
            D_803F2C18[0] = 1;
        }
        if (arg1 < 0) {
            D_803F2C18[2] = arg0->unkA;
        } else {
            D_803F2C18[2] = arg1;
        }
        D_803F2C18[1] = 0;
        if (D_803A6CEC_7B839C >= 0) {
            D_803F2C18[2] = D_803A6CEC_7B839C;
            D_803A6CEC_7B839C = -1;
        }

        if (arg0->unk12 == 0) {
            gCameras[gCameraId].modeId = gCameras[gPrevCameraId].modeId;
            gCameras[gCameraId].cameraMode = gCameras[gPrevCameraId].cameraMode;
        } else {
            gCameras[gCameraId].modeId = arg0->unk12;
            gCameras[gCameraId].cameraMode = cameraMode2;
        }
        gCameras[gCameraId].waypointProgress = 0;
        gCameras[gCameraId].heightOverride = sp30;
        gCameras[gCameraId].useAreaVisibility = arg0->unk17;
        gCameras[gCameraId].followType = arg0->unk18;
        gCameras[gCameraId].fixTargetX = arg0->unkC;
        gCameras[gCameraId].fixTargetZ = arg0->unkE;
        gCameras[gCameraId].fixTargetY = arg0->unk10;
        gCameras[gCameraId].followEntity = (Entity*)arg0->unk0;
        gCameras[gCameraId].waypoints = arg0->unk0;

        gCameras[gCameraId].cameraHeight = gCameras[gPrevCameraId].cameraHeight;
        gCameras[gCameraId].baseDistance = gCameras[gPrevCameraId].baseDistance;
        gCameras[gCameraId].followSpeed = gCameras[gPrevCameraId].followSpeed;
        gCameras[gCameraId].offsetXTarget = gCameras[gPrevCameraId].offsetXTarget;
        gCameras[gCameraId].offsetYTarget = gCameras[gPrevCameraId].offsetYTarget;
        gCameras[gCameraId].targetFollowSpeed = gCameras[gPrevCameraId].targetFollowSpeed;
        gCameras[gCameraId].autoPan = gCameras[gPrevCameraId].autoPan;
        gCameras[gCameraId].unk60 = gCameras[gPrevCameraId].unk60;

        gCameras[gCameraId].fixPosX = arg0->unk14;
        gCameras[gCameraId].fixPosZ = arg0->unk15;
        gCameras[gCameraId].fixPosY = arg0->unk16;

        gCameras[gCameraId].targetPitch = gCameras[gCameraId].cameraHeight;
        gCameras[gCameraId].pitch = gCameras[gCameraId].cameraHeight;
        gCameras[gCameraId].pitchVelocity = 0.0f;

        if ((gCameras[gPrevCameraId].cameraMode == CAMERA_MODE_BEHIND_1) || (gCameras[gPrevCameraId].cameraMode == CAMERA_MODE_BEHIND_2)) {
            gCameras[gCameraId].targetYaw = (gCameras[gPrevCameraId].targetYaw * 256.0) / 360.0;
        } else {
            gCameras[gCameraId].targetYaw = gCameras[gPrevCameraId].targetYaw;
        }

        gCameras[gCameraId].yawVelocity = 0.0f;
        gCameras[gCameraId].yaw = gCameras[gCameraId].targetYaw;
        gCameras[gCameraId].targetDistance = gCameras[gPrevCameraId].targetDistance;
        gCameras[gCameraId].distance = gCameras[gCameraId].targetDistance;
        gCameras[gCameraId].distanceVelocity = 0.0f;
        gCameras[gCameraId].offsetX = gCameras[gCameraId].offsetXTarget;
        gCameras[gCameraId].offsetXVelocity = 0.0f;
        gCameras[gCameraId].offsetY = gCameras[gCameraId].offsetYTarget;
        gCameras[gCameraId].offsetYVelocity = 0.0f;

        gCameras[gCameraId].targetX = gCameras[gPrevCameraId].targetX;
        gCameras[gCameraId].targetZ = gCameras[gPrevCameraId].targetZ;
        gCameras[gCameraId].targetY = gCameras[gPrevCameraId].targetY;
        gCameras[gCameraId].eyeX = gCameras[gPrevCameraId].eyeX;
        gCameras[gCameraId].eyeZ = gCameras[gPrevCameraId].eyeZ;
        gCameras[gCameraId].eyeY = gCameras[gPrevCameraId].eyeY;
        gCameras[gCameraId].targetVelX = gCameras[gPrevCameraId].targetVelX;
        gCameras[gCameraId].targetVelZ = gCameras[gPrevCameraId].targetVelZ;
        gCameras[gCameraId].targetVelY = gCameras[gPrevCameraId].targetVelY;
        gCameras[gCameraId].panOffsetX = gCameras[gPrevCameraId].panOffsetX;
        gCameras[gCameraId].panOffsetZ = gCameras[gPrevCameraId].panOffsetZ;
        gCameras[gCameraId].lateralPanX = gCameras[gPrevCameraId].lateralPanX;
        gCameras[gCameraId].lateralPanZ = gCameras[gPrevCameraId].lateralPanZ;
        gCameras[gCameraId].lateralPanVelX = gCameras[gPrevCameraId].lateralPanVelX;
        gCameras[gCameraId].lateralPanVelZ = gCameras[gPrevCameraId].lateralPanVelZ;
        gCameras[gCameraId].upX = gCameras[gPrevCameraId].upX;
        gCameras[gCameraId].upZ = gCameras[gPrevCameraId].upZ;
        gCameras[gCameraId].upY = gCameras[gPrevCameraId].upY;

        gCameras[gCameraId].zoomIndexMax = arg0->unk1A;
        gCameras[gCameraId].zoomIndexMin = arg0->unk19;
        gCameras[gCameraId].autoPan = arg0->unk1B;

        gCameras[gCameraId].zoomIndex = gCameras[gPrevCameraId].zoomIndex;
        gCameras[gCameraId].zoomIndex = MIN(gCameras[gCameraId].zoomIndexMax, gCameras[gCameraId].zoomIndex);
        gCameras[gCameraId].zoomIndex = MAX(gCameras[gCameraId].zoomIndexMin, gCameras[gCameraId].zoomIndex);

        gCameras[gCameraId].zoomInterp = (gCameras[gCameraId].zoomIndex * 8);

        switch (gCameras[gCameraId].followType) {
        case 1:
            if ((D_803A6CE4_7B8394 & 8)) {
                gCameras[gCameraId].focusHeightOffset = (gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 3;
            } else {
                gCameras[gCameraId].focusHeightOffset = (gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2;
            }
            break;
        case 2:
            gCameras[gCameraId].focusHeightOffset = (gCameras[gCameraId].followEntity->unk42 * 3) >> 2;
            break;
        case 3:
            gCameras[gCameraId].focusHeightOffset = (gCameras[gCameraId].followEntity->unk42 * 3) >> 2;
            break;
        }

        if ((gCameras[gCameraId].followType == 1) && (gCameras[gPrevCameraId].followType != 1)) {
            gCameras[gCameraId].zoomIndex = playerCameraDistance;
            gCameras[gCameraId].zoomIndex = MIN(gCameras[gCameraId].zoomIndexMax, gCameras[gCameraId].zoomIndex);
            gCameras[gCameraId].zoomIndex = MAX(gCameras[gCameraId].zoomIndexMin, gCameras[gCameraId].zoomIndex);
        }

        gCameras[gCameraId].targetYawOffset = 0.0f;
        if ((cameraMode2 == CAMERA_MODE_BEHIND_1) || (cameraMode2 == CAMERA_MODE_BEHIND_2)) {
            gCameras[gCameraId].targetYaw = gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation;
            gCameras[gCameraId].yaw = gCameras[gCameraId].targetYaw;
            gCameras[gCameraId].targetPitch = 0.0f;
            gCameras[gCameraId].pitch = 0.0f;
        }
        sp2F = func_80344158_755808(gCameras[gCameraId].cameraMode);
        temp_v0_5 = func_80344158_755808(gCameras[gPrevCameraId].cameraMode);
        if ((((sp2F == 1) && (temp_v0_5 == 0)) || ((temp_v0_5 == 1) && (sp2F == 0))) &&
             (gAnimalState.animals[gCurrentAnimalIndex].animal->unk4A == 0)) {
            D_803F2C28 = 8;
        }
        if ((cameraMode2 == CAMERA_MODE_BEHIND_1) ||
            (cameraMode2 == CAMERA_MODE_OVERHEAD_2) ||
            (cameraMode2 == CAMERA_MODE_6) ||
            (cameraMode2 == CAMERA_MODE_7) ||
            (cameraMode2 == CAMERA_MODE_28) ||
            (cameraMode2 == CAMERA_MODE_BEHIND_2)) {
            gAnimalState.desiredHeading = gAnimalState.animals[gCurrentAnimalIndex].animal->yRotation;
        }

        if ((gCameras[gPrevCameraId].cameraMode == CAMERA_MODE_WAYPOINT_1) ||
            (gCameras[gPrevCameraId].cameraMode == CAMERA_MODE_WAYPOINT_2)) {
            func_802B34DC_6C4B8C();
        }
        cameraSnapFlag = 1;

        for (i = 0; i < 5; i++) {
            if (gCameras[gCameraId].cameraMode != CAMERA_MODE_WAYPOINT_1) {
                set_camera_mode(gCameraId, 0);
            }
        }
        cameraSnapFlag = 0;
    }
}

// ESA: func_8002DB28
void func_803415BC_752C6C(void) {
    u8 sp57;
    u8 sp56;

    u8 sp55; // not actually used?
    u8 sp54;

    s16 phi_v0;
    s16 phi_t0;

    D_803F2AA4 = 0;
    D_803F2AA5 = 0;
    cameraAreaUnchanged = 0;
    func_80343A50_755100();
    sp57 = sp56 = 0xFF;

    if (D_803F2C18[0] == 0) {
        if (cinematicCameraRequest != 0) {
            if (gCameras[gCameraId].cameraMode != CAMERA_MODE_30) {
                func_80340E08_7524B8(30, 0, 0, 0, 0, 0, 0, 1, D_803A6CDC_7B838C);
                D_803A6CEC_7B839C = D_803A6CDC_7B838C;
            }
            D_803F2C6C = D_803F2C6D = 0;
        } else {
            if ((gCameraUiState == 3) || (gCameraUiState == 4)) {
                if (gCameras[gCameraId].cameraMode != CAMERA_MODE_ZOOM_SPIN) {
                    if (gCameraUiState == 3) {
                        phi_v0 = 30;
                    } else {
                        phi_v0 = 0;
                    }
                    func_80340E08_7524B8(45, 0, 0, 0, 1, -2, 0, 1, phi_v0);
                }
            } else if ((gCameraUiState == 1) || (gCameraUiState == 2)) {
                if (gCameras[gCameraId].cameraMode != CAMERA_MODE_29) {
                    if (gCameraUiState == 1) {
                        phi_v0 = 30;
                    } else {
                        phi_v0 = 0;
                    }
                    func_80340E08_7524B8(29, 0, 0, 0, 1, -2, 0, 1, phi_v0);
                }
            } else {
                if ((gCameraTriggerQueue[gCameraScriptHead].unk18 != 1) && (gCameraTriggerQueue[gCameraScriptHead].unk18 != 0)) {
                    if (((gCameras[gCameraId].modeId  != gCameraTriggerQueue[gCameraScriptHead].unk12) && (gCameraTriggerQueue[gCameraScriptHead].unk12 != 0)) ||
                         (gCameras[gCameraId].useAreaVisibility != gCameraTriggerQueue[gCameraScriptHead].unk17) ||
                         (gCameras[gCameraId].followType != gCameraTriggerQueue[gCameraScriptHead].unk18) ||
                         (gCameras[gCameraId].followEntity != (Entity*)gCameraTriggerQueue[gCameraScriptHead].unk0) ||
                         (gCameras[gCameraId].fixTargetX != gCameraTriggerQueue[gCameraScriptHead].unkC ) ||
                         (gCameras[gCameraId].fixTargetZ != gCameraTriggerQueue[gCameraScriptHead].unkE ) ||
                         (gCameras[gCameraId].fixTargetY != gCameraTriggerQueue[gCameraScriptHead].unk10) ||
                         (gCameras[gCameraId].fixPosX != gCameraTriggerQueue[gCameraScriptHead].unk14) ||
                         (gCameras[gCameraId].fixPosZ != gCameraTriggerQueue[gCameraScriptHead].unk15) ||
                         (gCameras[gCameraId].fixPosY != gCameraTriggerQueue[gCameraScriptHead].unk16) ||
                         (gCameras[gCameraId].zoomIndexMin != gCameraTriggerQueue[gCameraScriptHead].unk19) ||
                         (gCameras[gCameraId].zoomIndexMax != gCameraTriggerQueue[gCameraScriptHead].unk1A) ||
                         (gCameras[gCameraId].autoPan != gCameraTriggerQueue[gCameraScriptHead].unk1B)) {
                        if (gCameraTriggerQueue[gCameraScriptHead].unk12 == 0) {
                            gCameraTriggerQueue[gCameraScriptHead].unk12 = gCameras[gCameraId].modeId;
                        }
                        func_80340EA4_752554(&gCameraTriggerQueue[gCameraScriptHead], -1);
                    }
                    D_803F2C6C = D_803F2C6D = 0;
                } else {
                    if (sAmbientCameraTrigger[0].unk12 != 0) {
                        if ((gCameras[gCameraId].modeId  != sAmbientCameraTrigger[0].unk12) ||
                            (gCameras[gCameraId].useAreaVisibility != sAmbientCameraTrigger[0].unk17) ||
                            (gCameras[gCameraId].followType != sAmbientCameraTrigger[0].unk18) ||
                            (gCameras[gCameraId].followEntity != (Entity*)sAmbientCameraTrigger[0].unk0 ) ||
                            (gCameras[gCameraId].fixTargetX != sAmbientCameraTrigger[0].unkC ) ||
                            (gCameras[gCameraId].fixTargetZ != sAmbientCameraTrigger[0].unkE ) ||
                            (gCameras[gCameraId].fixTargetY != sAmbientCameraTrigger[0].unk10) ||
                            (gCameras[gCameraId].fixPosX != sAmbientCameraTrigger[0].unk14) ||
                            (gCameras[gCameraId].fixPosZ != sAmbientCameraTrigger[0].unk15) ||
                            (gCameras[gCameraId].fixPosY != sAmbientCameraTrigger[0].unk16) ||
                            (gCameras[gCameraId].zoomIndexMin != sAmbientCameraTrigger[0].unk19) ||
                            (gCameras[gCameraId].zoomIndexMax != sAmbientCameraTrigger[0].unk1A) ||
                            (gCameras[gCameraId].autoPan != sAmbientCameraTrigger[0].unk1B)) {
                            if (gCameraTriggerQueue[gCameraScriptHead].unkA >= 0) {
                                func_80340EA4_752554(sAmbientCameraTrigger, gCameraTriggerQueue[gCameraScriptHead].unkA);
                                gCameraTriggerQueue[gCameraScriptHead].unkA = -1;
                            } else {
                                func_80340EA4_752554(sAmbientCameraTrigger, -1);
                            }
                            D_803F2C6C = D_803F2C6D = 0;
                        } else {
                            D_803F2AA4 = 1;
                        }
                    } else {
                        if ((gCameraTriggerQueue[gCameraScriptHead].unk18 == 1) || (gCameraTriggerQueue[gCameraScriptHead].unk18 == 0)) {
                            if ((gControllerInput->button & Z_TRIG) &&
                                (gAnimalState.animals[gCurrentAnimalIndex].animal->state != STATE_INACTIVE) &&
                                (D_803A6CE0_7B8390 == 0) &&
                                (gAnimalState.animals[gCurrentAnimalIndex].animal->movementMode != MOVEMENT_MODE_2)) {
                                sp57 = 3;
                                sp56 = 254;
                                D_803A6CE8_7B8398 = 25;
                                func_80319F58_72B608(
                                    D_803A6D14_7B83C4,
                                    gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h >> 6,
                                    gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h >> 6,
                                    (gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h + ((gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2)) >> 6,
                                    gAnimalState.animals[gCurrentAnimalIndex].animal->unk160,
                                    &sp55,
                                    &sp54);
                            } else {
                                func_80319F58_72B608(
                                    D_803A6D14_7B83C4,
                                    gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h >> 6,
                                    gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h >> 6,
                                    (gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h + ((gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2)) >> 6,
                                    gAnimalState.animals[gCurrentAnimalIndex].animal->unk160,
                                    &sp57,
                                    &sp56);
                            }
                        } else {
                            func_80319F58_72B608(
                                D_803A6D14_7B83C4,
                                (s16)sCameraFocusWorldX >> 6,
                                (s16)sCameraFocusWorldZ >> 6,
                                (s16)sCameraFocusWorldY >> 6,
                                gCameraFocusCellIndex,
                                &sp57,
                                &sp56);
                        }

                        if ((sp57 != D_803F2C6C) || (sp56 != D_803F2C6D)) {
                            if ((sp57 == 2) || (sp57 == 12) ||
                                (sp57 == 33) || (sp57 == 40)) {
                                phi_t0 = 30;
                                if (gCameraTriggerQueue[gCameraScriptHead].unkA >= 0) {
                                    phi_t0 = gCameraTriggerQueue[gCameraScriptHead].unkA;
                                    gCameraTriggerQueue[gCameraScriptHead].unkA = -1;
                                    if (phi_t0 == 0) {
                                        func_80319F58_72B608(
                                            D_803A6D14_7B83C4,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h >> 6,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h >> 6,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h >> 6,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->unk160,
                                            &D_803F2C6C,
                                            &D_803F2C6D);
                                    }
                                }
                                if (sp56 == 254) {
                                    func_80340E08_7524B8(sp57, 0, 0, 0, 0, 0, 0, 0, 20);
                                } else {
                                    func_80340E08_7524B8(
                                        sp57,
                                        D_803A7114_7B87C4[sp56].unk0,
                                        D_803A7114_7B87C4[sp56].unk1,
                                        D_803A7114_7B87C4[sp56].unk2,
                                        1,
                                        (s8) D_803A7114_7B87C4[sp56].unk12 >> 4,
                                        (s8) (D_803A7114_7B87C4[sp56].unk12 << 4) >> 4,
                                        (D_803A7114_7B87C4[sp56].unk12 >> 8) & 1,
                                        phi_t0);
                                }
                            } else {
                                phi_t0 = 40;
                                if ((D_803F2C6C == 2) || (D_803F2C6C == 12) ||
                                    (D_803F2C6C == 33) || (D_803F2C6C == 40)) {
                                    phi_t0 = 30;
                                }
                                if (gCameraTriggerQueue[gCameraScriptHead].unkA >= 0) {
                                    phi_t0 = gCameraTriggerQueue[gCameraScriptHead].unkA;
                                    gCameraTriggerQueue[gCameraScriptHead].unkA = -1;
                                    if (phi_t0 == 0) {
                                        func_80319F58_72B608(
                                            D_803A6D14_7B83C4,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h >> 6,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h >> 6,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h >> 6,
                                            gAnimalState.animals[gCurrentAnimalIndex].animal->unk160,
                                            &D_803F2C6C,
                                            &D_803F2C6D);
                                    }
                                }
                                if (sp56 == 254) {
                                    func_80340E08_7524B8(
                                        sp57,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        20);
                                } else {
                                    func_80340E08_7524B8(
                                        sp57,
                                        0,
                                        0,
                                        0,
                                        1,
                                        (s8) D_803A7114_7B87C4[sp56].unk12 >> 4,
                                        (s8) (D_803A7114_7B87C4[sp56].unk12 << 4) >> 4,
                                        (D_803A7114_7B87C4[sp56].unk12 >> 8) & 1,
                                        phi_t0);
                                }
                            }
                            D_803F2C6C = sp57; D_803F2C6D = sp56;
                        } else {
                            cameraAreaUnchanged = 1;
                        }
                    }
                }
            }
        }
    }

    if ((sp57 == 0xFF) && (sp56 == 0xFF)) {
        func_80319F58_72B608(
            D_803A6D14_7B83C4,
            (s16)sCameraFocusWorldX >> 6,
            (s16)sCameraFocusWorldZ >> 6,
            (s16)sCameraFocusWorldY >> 6,
            gCameraFocusCellIndex,
            &sp57,
            &sp56);
    }
    if (gCameras[gCameraId].useAreaVisibility != 0) {
        gCameraVisibilityMask[0] = D_803A7114_7B87C4[sp56].unk4;
        gCameraVisibilityMask[1] = D_803A7114_7B87C4[sp56].unk6;
        gCameraVisibilityMask[2] = D_803A7114_7B87C4[sp56].unk8;
        gCameraVisibilityMask[3] = D_803A7114_7B87C4[sp56].unkA;
        gCameraVisibilityMask[4] = D_803A7114_7B87C4[sp56].unkC;
        gCameraVisibilityMask[5] = D_803A7114_7B87C4[sp56].unkE;
        gCameraVisibilityMask[6] = D_803A7114_7B87C4[sp56].unk10;
        gCameraVisibilityMask[7] = D_803A7114_7B87C4[sp56].unk12;
    } else {
        gCameraVisibilityMask[0] = (gCameraVisibilityMask[0] & 0xC0) | 0x413F;
        gCameraVisibilityMask[1] = gCameraVisibilityMask[2] = gCameraVisibilityMask[3] = gCameraVisibilityMask[4] = gCameraVisibilityMask[5] = 0x413F; // 0100000 100111111
        gCameraVisibilityMask[6] = D_803A7114_7B87C4[sp56].unk10;
        gCameraVisibilityMask[7] = D_803A7114_7B87C4[sp56].unk12;
    }
    if (D_803A6CE8_7B8398 > 0) {
        D_803A6CE8_7B8398 -= 1;
        gCameraVisibilityMask[0] = (gCameraVisibilityMask[0] & 0xC0) | 0x413F;
        gCameraVisibilityMask[1] = gCameraVisibilityMask[2] = gCameraVisibilityMask[3] = gCameraVisibilityMask[4] = gCameraVisibilityMask[5] = 0x413F;
        gCameraVisibilityMask[6] = D_803A7114_7B87C4[sp54].unk10;
        gCameraVisibilityMask[7] = D_803A7114_7B87C4[sp54].unk12;
    }
    if ((cameraAreaUnchanged != 0) && (cameraSettledFlag != 0)) {
        D_803F2AA4 = 1;
    }
}

// ESA: func_8002E6A0
void func_803421E0_753890(s16 arg0) {
    if (gCameraShakeMagnitude < arg0) {
        gCameraShakeMagnitude = arg0;
    }
}

// ESA: func_8002E6C4
void func_8034220C_7538BC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 tmp = ((ABS(arg1 - (s16)gCameraEyeWorldX) +
                ABS(arg2 - (s16)gCameraEyeWorldZ) +
                ABS(arg3 - (s16)gCameraEyeWorldY)) >> 6);
    tmp -= 5;

    if (tmp > 0) {
        arg0 -= tmp >> 1;
    }
    if (arg0 > 0) {
        func_803421E0_753890(arg0);
    }
}

// ESA: func_8002E78C
void func_80342318_7539C8(s32 x, s32 y, s32 z) {
    update_camera_x_y_z(0, x / 65536.0, y / 65536.0, z / 65536.0);
    update_camera_x_y_z(1, x / 65536.0, y / 65536.0, z / 65536.0);
}

// ESA: func_8002E7EC
void update_camera_x_y_z(s16 cameraID, f32 x, f32 y, f32 z) {
    gCameras[cameraID].targetX += x;
    gCameras[cameraID].targetZ += y;
    gCameras[cameraID].targetY += z;

    gCameras[cameraID].eyeX += x;
    gCameras[cameraID].eyeZ += y;
    gCameras[cameraID].eyeY += z;

    gCameras[cameraID].fixPosX += x * (1.0 / 64);
    gCameras[cameraID].fixPosZ += y * (1.0 / 64);
    gCameras[cameraID].fixPosY += z * (1.0 / 64);

    gCameras[cameraID].focusX += x;
    gCameras[cameraID].focusZ += y;
    gCameras[cameraID].focusY += z;

    gCameras[cameraID].fixTargetX += x;
    gCameras[cameraID].fixTargetZ += y;
    gCameras[cameraID].fixTargetY += z;
}

void func_80342550_753C00(Camera *arg0) {
    f32 sp6C UNUSED;
    f32 sp68 UNUSED;
    f32 sp64 UNUSED;
    f32 sp60;
    f32 sp5C UNUSED;
    f32 sp58 UNUSED;
    f32 sp54 UNUSED;
    f32 sp50 UNUSED;
    f32 sp4C UNUSED;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C UNUSED;
    f32 sp38 UNUSED;
    f32 sp34 UNUSED;

    f32 temp_f0;
    f32 temp_f2;    // sp2C
    f32 temp_f12;

    s16 temp_v0_3;
    s16 phi_v1;

    f32 phi_f16;
    f32 phi_f14;
    f32 phi_f12;
    f32 phi_f2;
    f32 phi_f0;

    phi_v1 = -1;

    switch (gCameras[gCameraId].followType) {
    case 1:
        if ((D_803A6CE4_7B8394 & 8) != 0) {
            phi_v1 = (gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 3;
        } else {
            phi_v1 = (gAnimalState.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2;
        }
        break;
    case 2:
        phi_v1 = (gCameras[gCameraId].followEntity->unk42 * 3) >> 2;
        break;
    case 3:
        phi_v1 = (gCameras[gCameraId].followEntity->unk42 * 3) >> 2;
        break;
    }

    if (phi_v1 != -1) {
        if (arg0->focusHeightOffset < phi_v1) {
            arg0->focusHeightOffset += 1;
        } else if (phi_v1 < arg0->focusHeightOffset) {
            arg0->focusHeightOffset -= 1;
        }
    }

    switch (arg0->followType) {
    case 1:
        arg0->focusX = ((f64) (f32) gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.w) / 65536;
        arg0->focusZ = ((f64) (f32) gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.w) / 65536;
        arg0->focusY = ((f64) (f32) gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.w) / 65536;
        if (arg0->autoPan != 0) {
            phi_f0 = (arg0->unk60 * arg0->distance * D_803F2D50.fovY) / 1200.0;
        } else {
            phi_f0 = 0.0f;
        }
        temp_v0_3 = gAnimalState.animals[gCurrentAnimalIndex].animal->heading;
        phi_f14 = ((SIN(temp_v0_3) >> 7) * phi_f0) / 600.0;
        phi_f16 = ((COS(temp_v0_3) >> 7) * phi_f0) / 600.0;

        arg0->focusY += arg0->focusHeightOffset;
        arg0->cellIndex = gAnimalState.animals[gCurrentAnimalIndex].animal->unk160;

        if ((gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType == VULTURE) ||
            (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType == SEAGULL2)) {
            arg0->focusY += gAnimalState.animals[gCurrentAnimalIndex].animal->unk308;
        }
        break;
    case 2:
        arg0->focusX = (f64) (f32) arg0->followEntity->position.xPos.w / 65536;
        arg0->focusZ = (f64) (f32) arg0->followEntity->position.zPos.w / 65536;
        arg0->focusY = (f64) (f32) arg0->followEntity->position.yPos.w / 65536;
        arg0->focusY += arg0->focusHeightOffset;
        arg0->cellIndex = (u8) arg0->followEntity->unk160;

        phi_f14 = phi_f16 = 0.0f;

        if ((Animal*)arg0->followEntity == gAnimalState.animals[gCurrentAnimalIndex].animal) {
            if (arg0->autoPan != 0) {
                phi_f0 = (arg0->unk60 * arg0->distance * D_803F2D50.fovY) / 1200.0;
            } else {
                phi_f0 = 0.0f;

            }
            temp_v0_3 = gAnimalState.animals[gCurrentAnimalIndex].animal->heading;
            phi_f14 = ((SIN(temp_v0_3) >> 7) * phi_f0) / 600.0;
            phi_f16 = ((COS(temp_v0_3) >> 7) * phi_f0) / 600.0;

            if ((gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType == VULTURE) ||
                (gAnimalState.animals[gCurrentAnimalIndex].unk0->animalType == SEAGULL2)) {
                arg0->focusY += gAnimalState.animals[gCurrentAnimalIndex].animal->unk308;
            }
        }
        break;
    case 3:
        arg0->focusX = ((f64) (f32) arg0->followEntity->position.xPos.w / 65536.0);
        arg0->focusZ = ((f64) (f32) arg0->followEntity->position.zPos.w / 65536.0);
        arg0->focusY = ((f64) (f32) arg0->followEntity->position.yPos.w / 65536.0);
        arg0->focusY += arg0->focusHeightOffset;
        arg0->cellIndex = arg0->followEntity->unk160;

        phi_f14 = phi_f16 = 0.0f;
        break;
    case 4:
        arg0->focusX = arg0->fixTargetX;
        arg0->focusZ = arg0->fixTargetZ;
        arg0->focusY = arg0->fixTargetY;
        arg0->cellIndex = func_803136FC_724DAC(arg0->focusX, arg0->focusZ, arg0->focusY);

        phi_f14 = phi_f16 = 0.0f;
        break;
    case 0:
    case 5:
        arg0->focusX = arg0->targetX;
        arg0->focusZ = arg0->targetZ;
        arg0->focusY = arg0->targetY;
        arg0->cellIndex = func_803136FC_724DAC(arg0->focusX, arg0->focusZ, arg0->focusY);

        phi_f14 = phi_f16 = 0.0f;
        break;
    default:
        if (1) {};
#ifdef AVOID_UB
        phi_f16 = 0.0f;
        phi_f14 = 0.0f;
#else
        phi_f16 = sp68; // uninitialised
        phi_f14 = sp6C; // uninitialised
#endif
        break;
    }

    switch (arg0->cameraMode) {
    case CAMERA_MODE_OVERHEAD_1:
    case CAMERA_MODE_OVERHEAD_2:
    case CAMERA_MODE_OVERHEAD_3:
    case CAMERA_MODE_OVERHEAD_4:
    case CAMERA_MODE_OVERHEAD_5:
    case CAMERA_MODE_22:
        sp48 = D_803A6CF0_7B83A0[arg0->zoomIndex+3] * 0.05;
        if ((D_803D2D90.unk0 != 0) || (D_803F2D50.unkC6 != 0) || (arg0->autoPan == 0)) {
            phi_f14 = phi_f16 = 0.0f;
        }
        phi_f14 = MAX(256.0 - gCameras[gCameraId].focusX, phi_f14);
        phi_f14 = MIN(4352.0 - gCameras[gCameraId].focusX, phi_f14);

        phi_f2 = phi_f14 - arg0->panOffsetX;
        sp60 = phi_f16 - arg0->panOffsetZ;

        temp_f12 = ABSF(phi_f2);
        if (temp_f12 <= 2.0) {
            phi_f2 = 0.0f;
        }
        temp_f12 = ABSF(sp60);
        if (temp_f12 <= 2.0) {
            sp60 = 0.0f;
        }

        temp_f12 = phi_f2 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->panOffsetVelX)) {
            arg0->panOffsetVelX = temp_f12;
            phi_f16 = 0.0f;
        } else {
            phi_f16 = temp_f12 - arg0->panOffsetVelX;
        }

        temp_f12 = sp60 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->panOffsetVelZ)) {
            arg0->panOffsetVelZ = temp_f12;
            phi_f14 = 0.0f;
        } else {
            phi_f14 = temp_f12 - arg0->panOffsetVelZ;
        }

        temp_f0 = sqrtf((phi_f16 * phi_f16) + (phi_f14 * phi_f14));
        if (temp_f0 != 0.0) {
            if (sp48 < temp_f0) {
                arg0->panOffsetVelX += (sp48 * phi_f16) / temp_f0;
                arg0->panOffsetVelZ += (sp48 * phi_f14) / temp_f0;
            } else {
                arg0->panOffsetVelX += phi_f16;
                arg0->panOffsetVelZ += phi_f14;
            }
        }
        arg0->panOffsetX += arg0->panOffsetVelX;
        arg0->panOffsetZ += arg0->panOffsetVelZ;
        break;
    case CAMERA_MODE_7:
    case CAMERA_MODE_28:
        phi_f14 *= 0.5;
        phi_f16 *= 0.5;
        /* fallthrough */
    default:
        phi_f14 = MAX(256.0 - gCameras[gCameraId].focusX, phi_f14);
        phi_f14 = MIN(4352.0 - gCameras[gCameraId].focusX, phi_f14);

        if ((arg0->cameraMode == CAMERA_MODE_ZOOM_SPIN) || (arg0->cameraMode == CAMERA_MODE_30) ||
            (arg0->cameraMode == CAMERA_MODE_228) || (arg0->cameraMode == CAMERA_MODE_29)) {
            phi_f16 = 0.0f;
            phi_f14 = 0.0f;
        }
        sp48 = D_803A6CF0_7B83A0[arg0->zoomIndex+3] * 0.05;
        phi_f0 = ((phi_f14 * sCameraRightX) + (phi_f16 * sCameraRightZ)) / 1.4;
        phi_f12 = (phi_f14 * D_803F2C5C) + (phi_f16 * D_803F2C60);
        if ((D_803D2D90.unk0 != 0) || (D_803F2D50.unkC6 != 0) ||
            (arg0->cameraMode == CAMERA_MODE_BEHIND_1) || (arg0->cameraMode == CAMERA_MODE_BEHIND_2)) {
            phi_f12 = 0.0f;
            phi_f0 = 0.0f;
        }
        sp44 = phi_f0 - arg0->lateralPanX;
        sp40 = phi_f12 - arg0->lateralPanZ;

        if (ABSF(sp44) <= 2.0) {
            sp44 = 0.0f;
        }
        if (ABSF(sp40) <= 2.0) {
            sp40 = 0.0f;
        }

        temp_f12 = sp44 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->lateralPanVelX)) {
            arg0->lateralPanVelX = temp_f12;
            temp_f0 = 0.0f;
        } else {
            temp_f0 = temp_f12 - arg0->lateralPanVelX;
        }

        temp_f12 = sp40 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->lateralPanVelZ)) {
            arg0->lateralPanVelZ = temp_f12;
            temp_f2 = 0.0f;
        } else {
            temp_f2 = temp_f12 - arg0->lateralPanVelZ;
        }

        phi_f0 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
        if (phi_f0 != 0.0) {
            if (sp48 < phi_f0) {
                arg0->lateralPanVelX += (sp48 * temp_f0) / phi_f0;
                arg0->lateralPanVelZ += (sp48 * temp_f2) / phi_f0;
            } else {
                arg0->lateralPanVelX += temp_f0;
                arg0->lateralPanVelZ += temp_f2;
            }
        }
        arg0->lateralPanX += arg0->lateralPanVelX;
        arg0->lateralPanZ += arg0->lateralPanVelZ;
        arg0->panOffsetX = (arg0->lateralPanX * sCameraRightX) + (arg0->lateralPanZ * D_803F2C5C);
        arg0->panOffsetZ = (arg0->lateralPanX * sCameraRightZ) + (arg0->lateralPanZ * D_803F2C60);
        break;
    }
}

void func_80343438_754AE8(void) {
    f32 phi_f2;
    Camera *nextCamera;
    s16 id;

    switch (D_803F2C18[0]) {
    case 0:
        sCameraFocusWorldX = gCameras[gCameraId].focusX;
        sCameraFocusWorldZ = gCameras[gCameraId].focusZ;
        sCameraFocusWorldY = gCameras[gCameraId].focusY;
        gCameraFocusCellIndex = gCameras[gCameraId].cellIndex;
        break;
    case 1:
    case 2:
        phi_f2 = (f32) D_803F2C18[1] / (f32) D_803F2C18[2];
        if (D_803F2C18[0] == 2) {
            if (phi_f2 < 0.5) {
                phi_f2 = 0.0f;
            } else {
                phi_f2 = 1.0f;
            }
        }

        id = gCameraId;
        nextCamera = &gCameras[(id + 1) % 2];

        sCameraFocusWorldX = (phi_f2 * gCameras[id].focusX) + ((1.0 - phi_f2) * nextCamera->focusX);
        sCameraFocusWorldZ = (phi_f2 * gCameras[id].focusZ) + ((1.0 - phi_f2) * nextCamera->focusZ);
        sCameraFocusWorldY = (phi_f2 * gCameras[id].focusY) + ((1.0 - phi_f2) * nextCamera->focusY);
        gCameraFocusCellIndex = func_803136FC_724DAC(sCameraFocusWorldX, sCameraFocusWorldZ, sCameraFocusWorldY);
        break;
    }

    if ((gCameras[gCameraId].cameraMode == CAMERA_MODE_WAYPOINT_1) && (D_803F2C18[0] != 1)) {
        sCameraFocusWorldX = gCameras[gCameraId].targetX;
        sCameraFocusWorldZ = gCameras[gCameraId].targetZ;
        sCameraFocusWorldY = gCameras[gCameraId].targetY;
        gCameraFocusCellIndex = func_803136FC_724DAC(sCameraFocusWorldX, sCameraFocusWorldZ, sCameraFocusWorldY);
    }
}

// ESA: func_8002F85C
void func_80343720_754DD0(s16 *arg0, s16 *arg1, s16 *arg2) {
    s32 pad UNUSED;
    s16 sp1A;
    s16 x;
    f32 temp_f0;

    switch (gCameras[gCameraId].cameraMode) {
    case CAMERA_MODE_OVERHEAD_1:
    case CAMERA_MODE_OVERHEAD_2:
    case CAMERA_MODE_OVERHEAD_3:
    case CAMERA_MODE_OVERHEAD_4:
    case CAMERA_MODE_OVERHEAD_5:
    case CAMERA_MODE_22:
        *arg0 = (gCameras[gCameraId].eyeX + SSSV_RAND(256)) - 128.0f;
        *arg1 = (gCameras[gCameraId].eyeZ + SSSV_RAND(256)) - 128.0f;
        *arg2 = (gCameras[gCameraId].eyeY                 ) - 100.0f;
        break;
    default:
        temp_f0 = (s16) SSSV_RAND(1024);
        *arg0 = gCameras[gCameraId].eyeX + (D_80204218 * temp_f0);
        *arg1 = gCameras[gCameraId].eyeZ + (D_8020421C * temp_f0);
        *arg2 = gCameras[gCameraId].eyeY + (D_80204220 * temp_f0);
        sp1A = ((temp_f0 * D_803F2D50.fovY) / 128);

        x = ((SSSV_RAND(512) - 256) * sp1A) >> 9;

        temp_f0 = (s16) ((x << 2) >> 1);
        *arg0 = *arg0 + (temp_f0 * D_8020422C);
        *arg1 = *arg1 + (temp_f0 * D_80204230);
        *arg2 = *arg2 + (temp_f0 * D_80204234) + sp1A;
        break;
    }
}

void func_80343A50_755100(void) {
    if (gCameraScriptTimer > 0) {
        gCameraScriptTimer -= 1;
    } else if (((gCameraScriptHead + 1) % 8) != gCameraScriptTail) {
        gCameraScriptHead = (gCameraScriptHead + 1) % 8;
        gCameraScriptTimer = gCameraTriggerQueue[gCameraScriptHead].unkA + gCameraTriggerQueue[gCameraScriptHead].unk8;
    } else {
        cameraAreaUnchanged = 1;
    }
}

void func_80343AE0_755190(u8 arg0, s16 arg1, s16 arg2, Entity *entity, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, s16 argA, u8 argB, s8 argC, s8 argD, u8 argE) {
    s32 pad UNUSED;
    D_803F2AA4 = D_803F2AA5 = 0;

    if (arg1 == 0x7FFF) {
        arg1 = 0;
    }
    if (gCameraScriptTail != gCameraScriptHead) {
        switch (arg0) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            memset_bytes((u8*)&gCameraTriggerQueue[gCameraScriptTail], 0, 32);
            gCameraTriggerQueue[gCameraScriptTail].unk18 = arg0;
            gCameraTriggerQueue[gCameraScriptTail].unk8 = arg1;
            gCameraTriggerQueue[gCameraScriptTail].unkA = arg2;
            gCameraTriggerQueue[gCameraScriptTail].unk0 = entity;
            gCameraTriggerQueue[gCameraScriptTail].unkC = arg4;
            gCameraTriggerQueue[gCameraScriptTail].unkE = arg5;
            gCameraTriggerQueue[gCameraScriptTail].unk10 = arg6;
            gCameraTriggerQueue[gCameraScriptTail].unk14 = arg7;
            gCameraTriggerQueue[gCameraScriptTail].unk15 = arg8;
            gCameraTriggerQueue[gCameraScriptTail].unk16 = arg9;
            gCameraTriggerQueue[gCameraScriptTail].unk12 = argA;
            gCameraTriggerQueue[gCameraScriptTail].unk17 = argB;
            gCameraTriggerQueue[gCameraScriptTail].unk19 = argC;
            gCameraTriggerQueue[gCameraScriptTail].unk1A = argD;
            gCameraTriggerQueue[gCameraScriptTail].unk1B = argE;
            gCameraScriptTail = (gCameraScriptTail + 1) % 8;
            break;
        }
    }
}

s16 D_803A7B3C_7B91EC[458] = {
    0x0000, 0x0000,
    0x0001, 0xFFFF,
    0x0002, 0x0000,
    0x0003, 0x0000,
    0x0004, 0x0000,
    0x0005, 0x0000,
    0x0006, 0xFFFF,
    0x0007, 0xFFFF,
    0x0008, 0xFFFF,
    0x0009, 0xFFFF,
    0x000A, 0xFFFF,
    0x000B, 0xFFFF,
    0x000C, 0x0000,
    0x000D, 0xFFFF,
    0x000E, 0xFFFF,
    0x000F, 0xFFFF,
    0x0010, 0xFFFF,
    0x0011, 0x0000,
    0x0012, 0x0000,
    0x0013, 0x0000,
    0x0014, 0x0000,
    0x0015, 0x0000,
    0x0016, 0x0000,
    0x0017, 0x0000,
    0x0018, 0x0000,
    0x0019, 0x0000,
    0x001A, 0xFFFF,
    0x001B, 0xFFFF,
    0x001C, 0xFFFF,
    0x001D, 0xFFFF,
    0x001E, 0xFFFF,
    0x001F, 0xFFFF,
    0x0000, 0x0000,
    0x0002, 0x0000,
    0x0003, 0x0000,
    0x0004, 0x0000,
    0x0013, 0x0000,
    0x0014, 0x0000,
    0x0015, 0x0000,
    0x0005, 0x0000,
    0x000C, 0x0000,
    0x0011, 0x0000,
    0x0012, 0x0000,
    0x0016, 0x0000,
    0x0017, 0x0000,
    0x0019, 0x0000,
    0x0001, 0xFFFF,
    0x0001, 0x0000,
    0x0001, 0x0003,
    0x0001, 0x0007,
    0x0001, 0x000B,
    0x0001, 0x000E,
    0x0001, 0x0012,
    0x0001, 0x0015,
    0x0001, 0x0019,
    0x0001, 0x001C,
    0x0001, 0x0024,
    0x0001, 0x002B,
    0x0001, 0x0032,
    0x0001, 0x0039,
    0x0006, 0xFFFF,
    0x0006, 0x0000,
    0x0006, 0x0003,
    0x0006, 0x0007,
    0x0006, 0x000B,
    0x0006, 0x000E,
    0x0006, 0x0012,
    0x0006, 0x0015,
    0x0006, 0x0019,
    0x0006, 0x001C,
    0x0006, 0x0024,
    0x0006, 0x002B,
    0x0006, 0x0032,
    0x0006, 0x0039,
    0x0007, 0xFFFF,
    0x0007, 0x0000,
    0x0007, 0x0003,
    0x0007, 0x0007,
    0x0007, 0x000B,
    0x0007, 0x000E,
    0x0007, 0x0012,
    0x0007, 0x0015,
    0x0007, 0x0019,
    0x0007, 0x001C,
    0x0007, 0x0024,
    0x0007, 0x002B,
    0x0007, 0x0032,
    0x0007, 0x0039,
    0x0008, 0xFFFF,
    0x0008, 0x0000,
    0x0008, 0x0003,
    0x0008, 0x0007,
    0x0008, 0x000B,
    0x0008, 0x000E,
    0x0008, 0x0012,
    0x0008, 0x0015,
    0x0008, 0x0019,
    0x0008, 0x001C,
    0x0008, 0x0024,
    0x0008, 0x002B,
    0x0008, 0x0032,
    0x0008, 0x0039,
    0x0009, 0xFFFF,
    0x0009, 0x0000,
    0x0009, 0x0003,
    0x0009, 0x0007,
    0x0009, 0x000B,
    0x0009, 0x000E,
    0x0009, 0x0012,
    0x0009, 0x0015,
    0x0009, 0x0019,
    0x0009, 0x001C,
    0x0009, 0x0024,
    0x0009, 0x002B,
    0x0009, 0x0032,
    0x0009, 0x0039,
    0x000A, 0xFFFF,
    0x000A, 0x0000,
    0x000A, 0x0003,
    0x000A, 0x0007,
    0x000A, 0x000B,
    0x000A, 0x000E,
    0x000A, 0x0012,
    0x000A, 0x0015,
    0x000A, 0x0019,
    0x000A, 0x001C,
    0x000A, 0x0024,
    0x000A, 0x002B,
    0x000A, 0x0032,
    0x000A, 0x0039,
    0x000B, 0xFFFF,
    0x000B, 0x0000,
    0x000B, 0x0003,
    0x000B, 0x0007,
    0x000B, 0x000B,
    0x000B, 0x000E,
    0x000B, 0x0012,
    0x000B, 0x0015,
    0x000B, 0x0019,
    0x000B, 0x001C,
    0x000B, 0x0024,
    0x000B, 0x002B,
    0x000B, 0x0032,
    0x000B, 0x0039,
    0x000D, 0xFFFF,
    0x000D, 0x0000,
    0x000D, 0x0003,
    0x000D, 0x0007,
    0x000D, 0x000B,
    0x000D, 0x000E,
    0x000D, 0x0012,
    0x000D, 0x0015,
    0x000D, 0x0019,
    0x000D, 0x001C,
    0x000D, 0x0024,
    0x000D, 0x002B,
    0x000D, 0x0032,
    0x000D, 0x0039,
    0x000E, 0xFFFF,
    0x000E, 0x0000,
    0x000E, 0x0003,
    0x000E, 0x0007,
    0x000E, 0x000B,
    0x000E, 0x000E,
    0x000E, 0x0012,
    0x000E, 0x0015,
    0x000E, 0x0019,
    0x000E, 0x001C,
    0x000E, 0x0024,
    0x000E, 0x002B,
    0x000E, 0x0032,
    0x000E, 0x0039,
    0x000F, 0xFFFF,
    0x000F, 0x0000,
    0x000F, 0x0003,
    0x000F, 0x0007,
    0x000F, 0x000B,
    0x000F, 0x000E,
    0x000F, 0x0012,
    0x000F, 0x0015,
    0x000F, 0x0019,
    0x000F, 0x001C,
    0x000F, 0x0024,
    0x000F, 0x002B,
    0x000F, 0x0032,
    0x000F, 0x0039,
    0x0010, 0xFFFF,
    0x0010, 0x0000,
    0x0010, 0x0003,
    0x0010, 0x0007,
    0x0010, 0x000B,
    0x0010, 0x000E,
    0x0010, 0x0012,
    0x0010, 0x0015,
    0x0010, 0x0019,
    0x0010, 0x001C,
    0x0010, 0x0024,
    0x0010, 0x002B,
    0x0010, 0x0032,
    0x0010, 0x0039,
    0x001A, 0xFFFF,
    0x001A, 0x0000,
    0x001A, 0x0003,
    0x001A, 0x0007,
    0x001A, 0x000B,
    0x001A, 0x000E,
    0x001A, 0x0012,
    0x001A, 0x0015,
    0x001A, 0x0019,
    0x001A, 0x001C,
    0x001A, 0x0024,
    0x001A, 0x002B,
    0x001A, 0x0032,
    0x001A, 0x0039,
    0x001C, 0xFFFF,
    0x001C, 0x0000,
    0x001C, 0x0003,
    0x001C, 0x0007,
    0x001C, 0x000B,
    0x001C, 0x000E,
    0x001C, 0x0012,
    0x001C, 0x0015,
    0x001C, 0x0019,
    0x001C, 0x001C,
    0x001C, 0x0024,
    0x001C, 0x002B,
    0x001C, 0x0032,
    0x001C, 0x0039,
    0x00E4, 0x0000,
};

// ESA: func_8002FD44
void func_80343C44_7552F4(s16 idx, s16 *cameraMode, s16 *arg2) {
    *cameraMode = D_803A7B3C_7B91EC[(idx * 2)];
    *arg2 = D_803A7B3C_7B91EC[(idx * 2) + 1];
}

// ESA: func_8002FD7C
void func_80343C74_755324(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4) {
    memset_bytes((u8*)sAmbientCameraTrigger, 0, sizeof(sAmbientCameraTrigger));
    sAmbientCameraTrigger[0].unk18 = 1;
    sAmbientCameraTrigger[0].unkA = 40;
    sAmbientCameraTrigger[0].unk12 = arg0;
    sAmbientCameraTrigger[0].unk17 = arg1;
    sAmbientCameraTrigger[0].unk19 = arg2;
    sAmbientCameraTrigger[0].unk1A = arg3;
    sAmbientCameraTrigger[0].unk1B = arg4;
    if (((gCameraScriptHead + 1) % 8) == gCameraScriptTail) {
        if ((gCameraTriggerQueue[gCameraScriptHead].unk18 != 1) && (gCameraTriggerQueue[gCameraScriptHead].unk18 != 0)) {
            gCameraTriggerQueue[gCameraScriptHead].unkA = 40;
        }
    }
}

// ESA: func_8002FE74
void func_80343D44_7553F4(WaypointData *arg0, s8 arg1) {
    func_80343AE0_755190(5, (arg0->length * 32) - 136, 40, arg0, 0, 0, 0, 0, 0, 0, 44, arg1, -2, 0, 1);
}

// ESA: func_8002FEE4
void func_80343DC0_755470(void) {
    gCameraScriptHead = 0;
    gCameraScriptTail = 1;
    memset_bytes((u8*)&gCameraTriggerQueue, 0, sizeof(gCameraTriggerQueue[0]));
    gCameraScriptTimer = 0;
    D_803F2C18[0] = 0;
    D_803F2C18[1] = 0;
    D_803F2C18[2] = 0;

    gCameras[gCameraId].cameraMode = CAMERA_MODE_27;
    gCameras[gCameraId].modeId = 0;
    gCameras[gCameraId].followType = 4;
    gCameras[gCameraId].eyeX = gCameraEyeWorldX - gCameras[gCameraId].panOffsetX;
    gCameras[gCameraId].eyeZ = gCameraEyeWorldZ - gCameras[gCameraId].panOffsetZ;
    gCameras[gCameraId].eyeY = gCameraEyeWorldY;
    gCameras[gCameraId].targetX = sLookAtTargetX - gCameras[gCameraId].panOffsetX;
    gCameras[gCameraId].targetZ = sLookAtTargetZ - gCameras[gCameraId].panOffsetZ;
    gCameras[gCameraId].targetY = sLookAtTargetY;
    gCameras[gCameraId].upX = D_80204200;
    gCameras[gCameraId].upZ = D_80204204;
    gCameras[gCameraId].upY = D_80204208;

    gCameraTriggerQueue[gCameraScriptHead].unk12 = gCameras[gCameraId].modeId;
    gCameraTriggerQueue[gCameraScriptHead].unk17 = gCameras[gCameraId].useAreaVisibility;
    gCameraTriggerQueue[gCameraScriptHead].unk18 = gCameras[gCameraId].followType;
    gCameraTriggerQueue[gCameraScriptHead].unk0 = gCameras[gCameraId].followEntity;
    gCameraTriggerQueue[gCameraScriptHead].unkC = gCameras[gCameraId].fixTargetX;
    gCameraTriggerQueue[gCameraScriptHead].unkE = gCameras[gCameraId].fixTargetZ;
    gCameraTriggerQueue[gCameraScriptHead].unk10 = gCameras[gCameraId].fixTargetY;
    gCameraTriggerQueue[gCameraScriptHead].unk14 = gCameras[gCameraId].fixPosX;
    gCameraTriggerQueue[gCameraScriptHead].unk15 = gCameras[gCameraId].fixPosZ;
    gCameraTriggerQueue[gCameraScriptHead].unk16 = gCameras[gCameraId].fixPosY;
    gCameraTriggerQueue[gCameraScriptHead].unk19 = gCameras[gCameraId].zoomIndexMin;
    gCameraTriggerQueue[gCameraScriptHead].unk1A = gCameras[gCameraId].zoomIndexMax;
    gCameraTriggerQueue[gCameraScriptHead].unk1B = gCameras[gCameraId].autoPan;
}

// ESA: func_80030070
void set_player_camera_distance(s16 dist) {
    playerCameraDistance = dist;
}

void func_80343F68_755618(void) {
    cinematicCameraRequest = 1;
}

void func_80343F78_755628(void) {
    if (cinematicCameraRequest != 0) {
        cinematicCameraRequest = 0;
        if ((D_803F2C18[0] != 0) && (gCameras[gCameraId].cameraMode == CAMERA_MODE_30)) {
            D_803F2C18[1] = D_803F2C18[2] - D_803F2C18[1];
            gCameraId = (gCameraId + 1) & 1;
            gPrevCameraId = (gPrevCameraId + 1) & 1;
            D_803A6CEC_7B839C = -1;
        }
    }
}

// ESA: func_8003007C
void func_8034401C_7556CC(void) {
    s16 i, j;

    for (i = 1; i < 128; i++) {
        for (j = 0; j < i; j++) {
            if ((D_803A7114_7B87C4[i].unk0 == D_803A7114_7B87C4[j].unk0) &&
                (D_803A7114_7B87C4[i].unk1 == D_803A7114_7B87C4[j].unk1) &&
                (D_803A7114_7B87C4[i].unk2 == D_803A7114_7B87C4[j].unk2) &&
                (D_803A7114_7B87C4[i].unk4 == D_803A7114_7B87C4[j].unk4) &&
                (D_803A7114_7B87C4[i].unk6 == D_803A7114_7B87C4[j].unk6) &&
                (D_803A7114_7B87C4[i].unk8 == D_803A7114_7B87C4[j].unk8) &&
                (D_803A7114_7B87C4[i].unkA == D_803A7114_7B87C4[j].unkA) &&
                (D_803A7114_7B87C4[i].unkC == D_803A7114_7B87C4[j].unkC) &&
                (D_803A7114_7B87C4[i].unkE == D_803A7114_7B87C4[j].unkE) &&
                (D_803A7114_7B87C4[i].unk10 == D_803A7114_7B87C4[j].unk10) &&
                (D_803A7114_7B87C4[i].unk12 == D_803A7114_7B87C4[j].unk12)) {

                D_803A6D14_7B83C4[i].unk7 = D_803A6D14_7B83C4[j].unk7;
                // break loop
                j = 128;
            }
        }
    }
}

// ESA: func_80030264
s16 func_80344158_755808(s16 cameraMode) {
    switch (cameraMode) {
    case CAMERA_MODE_BEHIND_1:
    case CAMERA_MODE_OVERHEAD_2:
    case CAMERA_MODE_6:
    case CAMERA_MODE_7:
    case CAMERA_MODE_BEHIND_2:
    case CAMERA_MODE_28:
        return 1;
    default:
        return 0;
    }
}

// ESA: func_800302AC
void func_8034419C_75584C(Entity *arg0) {
    func_80343AE0_755190(4, 0, 30, arg0, 0, 0, 0, 0, 0, 0, 228, 1, 0, 0, 0);
}

void func_803441FC_7558AC(void) {
    if (D_803F2C18[0] != 0) {
        if ((D_803F2C18[0] == 1) || (D_803F2C18[0] == 2)) {
            D_803F2C18[0] = 0;
            D_803F2C18[1] = 0;
        }
    }
}
