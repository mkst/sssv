#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

s16  get_music_bounce_factor(void);

// ========================================================
// .data
// ========================================================

static s16 musicBounceCurve[32] = {
    38, 50, 60, 64, 63, 61, 59, 57,
    55, 52, 49, 46, 43, 40, 37, 34,
    31, 28, 25, 22, 18, 15, 12, 10,
    7, 5, 3, 1, 0, 5, 15, 27,
};

// ========================================================
// .bss (gAnimalBehaviourEnabled to D_803F6460)
// ========================================================

s16  gAnimalBehaviourEnabled;

// ========================================================
// .text
// ========================================================

void empty_8038C760_79DE10(void) {
}

void update_idle_head_yaw(void) {
    u16 ticksSinceInput;
    s16 yawDelta;

    ticksSinceInput = gGameplayTick - D_803D552C->lastInputTick;
    if ((gUiFlowState.unk0 == 0) && ((D_803D5530->unk4A == 0)) && (ticksSinceInput != 0)) {
        if (D_803D5538 != 0) {
            if ((ticksSinceInput & 0xFF) >= 150) {
                if (SSSV_RAND(16) == 13) {
                    D_803D552C->targetHeadYawDegrees = advance_random_seed() % 360;
                }
            } else {
                D_803D552C->targetHeadYawDegrees = 0;
            }
        } else if ((ticksSinceInput & 0xFF) >= 130) {
            D_803D552C->targetHeadYawDegrees = ((D_803D552C->heading * 360) >> 8) - func_80128C10(gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h, gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);
        } else {
            D_803D552C->targetHeadYawDegrees = 0;
        }
    } else {
        D_803D552C->targetHeadYawDegrees = 0;
    }
    if ((D_803D552C->movementMode == MOVEMENT_MODE_2) || (D_803D552C->movementMode == MOVEMENT_MODE_DEACTIVATED)) {
        D_803D552C->targetHeadYawDegrees = 0;
    }

    yawDelta = D_803D552C->targetHeadYawDegrees - D_803D552C->headYawDegrees;

    while (yawDelta >= 360) {
        yawDelta -= 360;
    }
    while (yawDelta < 0) {
        yawDelta += 360;
    }

    if (yawDelta > 180) {
        D_803D552C->headYawDegrees += MAX(yawDelta - 360, -18);
    } else {
        D_803D552C->headYawDegrees += MIN(yawDelta, 18);
    }
    D_803D552C->headYawDegrees %= 360;
}

void update_idle_head_yaw_clamped(void) {
    u16 ticksSinceInput;
    s16 yawDelta;

    ticksSinceInput = gGameplayTick - D_803D552C->lastInputTick;
    if ((gUiFlowState.unk0 == 0) && (D_803D5530->unk4A == 0) && (ticksSinceInput != 0)) {
        if (D_803D5538 != 0) {
            if ((ticksSinceInput & 0xFF) >= 150) {
                if (SSSV_RAND(32) == 13) {
                    D_803D552C->targetHeadYawDegrees = (advance_random_seed() % 140) - 70;
                    if (D_803D552C->targetHeadYawDegrees < 0) {
                        D_803D552C->targetHeadYawDegrees += 360;
                    }
                }
            } else {
                D_803D552C->targetHeadYawDegrees = 0;
            }
        } else if ((ticksSinceInput & 0xFF) >= 200) {
            D_803D552C->targetHeadYawDegrees = ((D_803D552C->heading * 360) >> 8) - func_80128C10(gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h, gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);

            if (D_803D552C->targetHeadYawDegrees > 85) {
                D_803D552C->targetHeadYawDegrees = 85;
            }
            if (D_803D552C->targetHeadYawDegrees < -85) {
                D_803D552C->targetHeadYawDegrees = -85;
            }
        } else {
            D_803D552C->targetHeadYawDegrees = 0;
        }
    } else {
        D_803D552C->targetHeadYawDegrees = 0;
    }
    if ((D_803D552C->movementMode == MOVEMENT_MODE_2) || (D_803D552C->movementMode == MOVEMENT_MODE_DEACTIVATED)) {
        D_803D552C->targetHeadYawDegrees = 0;
    }
    if ((u16)D_803D5528->unk3C0.unk0 != 0) {
        D_803D552C->targetHeadYawDegrees = 0;
    }

    yawDelta = D_803D552C->targetHeadYawDegrees - D_803D552C->headYawDegrees;

    while (yawDelta >= 360) {
        yawDelta -= 360;
    }
    while (yawDelta < 0) {
        yawDelta += 360;
    }

    if (yawDelta > 180) {
        D_803D552C->headYawDegrees += MAX(yawDelta - 360, -8);
    } else {
        D_803D552C->headYawDegrees += MIN(yawDelta, 8);
    }
    D_803D552C->headYawDegrees %= 360;
}

s16 get_music_bounce_factor(void) {
    return musicBounceCurve[((gMusicBeatPhase + 3) & 0x3F) >> 1];
}

s16 unused_8038CC50_79E300(void) {
    return ((COS((gMusicBeatPhase - 7) << 2) >> 7) + 256) / 8;
}

s16 get_music_animation_phase(void) {
    return (gMusicBeatPhase + 7) & 0x3F;
}

s16 did_music_animation_phase_wrap(void) {
    return ((gMusicBeatPhase + 7) & 0x3F) < ((gPreviousMusicBeatPhase + 7) & 0x3F);
}

s16 apply_music_bounce_to_joints(s16 amplitude, s16 joint1, s16 joint2, s16 joint3, s16 joint4, s16 joint5) {
    s16 phi_v0;
    if (gAnimalBehaviourEnabled == 0) {
        return 0;
    }
    if (D_803D552C->unk318 != 0) {
        return 0;
    }
    if ((D_803D552C->movementMode == MOVEMENT_MODE_NORMAL) ||
        (D_803D552C->movementMode == MOVEMENT_MODE_INJURED) ||
        (D_803D552C->movementMode == MOVEMENT_MODE_CRITICAL)) {
        if (gUiFlowState.unk0 == 0) {
            if ((D_803D5530->state == 2) || (D_803D5530->state == 21) ||
                (D_803D5530->state == 41) || (D_803D5530->state == 61) ||
                (D_803D5530->state == 81) || (D_803D5530->state == 101) ||
                (D_803D5530->state == 121) || (D_803D5530->state == 141) ||
                (D_803D5530->state == 181) || (D_803D5530->state == 201)) {
                if (gMusicVolumeScale == 0) {
                    if (gMusicSpeakerVolumeScale > 0.99) {
                        phi_v0 = 400;
                    } else if (gMusicSpeakerVolumeScale > 0.5) {
                        phi_v0 = 200;
                    } else {
                        phi_v0 = 0;
                    }
                } else if (gMusicVolumeScale > 1900) {
                    phi_v0 = 300;
                } else {
                    if (gMusicVolumeScale > 1000) {
                        phi_v0 = 175;
                    } else {
                        phi_v0 = 0;
                    }
                }
                if (((gGameplayTick + ((u16)D_803D552C->ambientPhaseSeed << 6)) & 0x1FF) < phi_v0) {
                    phi_v0 = (amplitude * get_music_bounce_factor()) >> 6;
                    if (joint1 >= 0) {
                        D_80203FE0[joint1].unk4 -= phi_v0;
                    }
                    if (joint2 >= 0) {
                        D_80203FE0[joint2].unk4 -= phi_v0;
                    }
                    if (joint3 >= 0) {
                        D_80203FE0[joint3].unk4 -= phi_v0;
                    }
                    if (joint4 >= 0) {
                        D_80203FE0[joint4].unk4 -= phi_v0;
                    }
                    if (joint5 >= 0) {
                        D_80203FE0[joint5].unk4 -= phi_v0;
                    }
                }
            }
        }
    }
}
