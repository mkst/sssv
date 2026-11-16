#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

s16 gSiLockInitialized = 0;
s32 numControllers = 0;

// ========================================================
// .bss
// ========================================================

Controller   gRumbleState;
OSContPad   *gControllerInput;
OSContStatus gControllerStatus[MAXCONTROLLERS];
OSContPad    gControllerPads[MAXCONTROLLERS];

RumbleMotorMessage gRumbleMotorMessage;
s32 D_80291108; // unused?
s32 D_8029110C; // unused?

OSPfs       gControllerPakHandles[MAXCONTROLLERS];
OSMesgQueue gRumbleMotorQueue;
OSMesg      gRumbleMotorQueueBuffer;
OSMesg      gSiLockReceivedMessage;
s32  D_802912D0;
s32  gEepromType;
s16  gControllerConnected;
u16  D_802912DA;
s16  gRumblePakProbeCounter;
u8   gPrevStartButtonUp; // 1 when up in the previous sample
u8   gPrevAButtonUp; // 1 when up in the previous sample
u8   gPrevBButtonUp; // 1 when up in the previous sample
u8   gPrevDpadUpButtonUp; // 1 when up in the previous sample
u8   gPrevDpadDownButtonUp; // 1 when up in the previous sample
u8   gPrevDpadLeftButtonUp; // 1 when up in the previous sample
u8   gPrevDpadRightButtonUp; // 1 when up in the previous sample
u8   gPrevZButtonUp; // 1 when up in the previous sample

// ========================================================
// .text
// ========================================================

s32 init_controllers(void) {
    s16 i;
    s32 pad;
    u8 pattern; // sp57
    s32 status;

    D_802912DA = 0;
    gRumblePakProbeCounter = 0;
    gPrevStartButtonUp = 1;
    gPrevAButtonUp = 1;
    gPrevBButtonUp = 1;
    gPrevDpadUpButtonUp = 1;
    gPrevDpadDownButtonUp = 1;
    gPrevDpadLeftButtonUp = 1;
    gPrevDpadRightButtonUp = 1;
    gPrevZButtonUp = 1;

    osCreateMesgQueue(&gSiEventQueue, gSiEventQueueBuffer, 1);
    osSetEventMesg(5U, &gSiEventQueue, (void *)1);
    osContInit(&gSiEventQueue, &pattern, gControllerStatus);

    numControllers = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if ((pattern & (1 << i)) && !(gControllerStatus[i].errno & 8)) {
            numControllers++;
        }
    }
    osContSetCh(1U);
    osCreateMesgQueue(&gRumbleMotorQueue, &gRumbleMotorQueueBuffer, 1);

    osCreateThread(&gThread9, 9, (void (*)(void *)) thread9, NULL, &thread9_stack[sizeof(thread9_stack) / sizeof(u64)], 9);
    osStartThread(&gThread9);

    for (i = 0; i < MAXCONTROLLERS; i++) {
        gRumbleState.hasRumblePak[i] = 0;

        if ((pattern >> i) & 1) {
            if (gControllerStatus[i].type & CONT_JOYPORT) {
                if (gControllerStatus[i].status & CONT_CARD_ON) {
                    status = osPfsInit(&gSiEventQueue, (s32)&gControllerPakHandles[i], i);
                    if ((status == 10) || (status == 11)) {}
                    if (((status == PFS_ERR_ID_FATAL)) || (status == PFS_ERR_DEVICE)) {
                        if (osMotorInit(&gSiEventQueue, (s32)&gControllerPakHandles[i], i) == 0) {
                            gRumbleState.hasRumblePak[i] = 1;
                        }
                    }
                }
            }
        }
    }

    gEepromType = osEepromProbe(&gSiEventQueue);
    reset_rumble_state();
    return numControllers;
}

void snapshot_controller_button_history(void) {
    OSContPad *ci = gControllerInput;

    if (ci != 0) {
        if (ci->button & CONT_START) {
            gPrevStartButtonUp = 0;
        } else {
            gPrevStartButtonUp = 1;
        }
        if (ci->button & CONT_A) {
            gPrevAButtonUp = 0;
        } else {
            gPrevAButtonUp = 1;
        }
        if (ci->button & CONT_B) {
            gPrevBButtonUp = 0;
        } else {
            gPrevBButtonUp = 1;
        }
        if (ci->button & CONT_UP) {
            gPrevDpadUpButtonUp = 0;
        } else {
            gPrevDpadUpButtonUp = 1;
        }
        if (ci->button & CONT_DOWN) {
            gPrevDpadDownButtonUp = 0;
        } else {
            gPrevDpadDownButtonUp = 1;
        }
        if (ci->button & CONT_LEFT) {
            gPrevDpadLeftButtonUp = 0;
        } else {
            gPrevDpadLeftButtonUp = 1;
        }
        if (ci->button & CONT_RIGHT) {
            gPrevDpadRightButtonUp = 0;
        } else {
            gPrevDpadRightButtonUp = 1;
        }
        if (ci->button & Z_TRIG) {
            gPrevZButtonUp = 0;
        } else {
            gPrevZButtonUp = 1;
        }
    }
}

void init_si_lock(void) {
    gSiLockInitialized = 1;
    osCreateMesgQueue(&gSiLockQueue, gSiLockQueueBuffer, 1);
    osSendMesg(&gSiLockQueue, 0, OS_MESG_NOBLOCK);
}

void acquire_si_lock(void) {
    if (gSiLockInitialized == 0) {
        // if message queue not created, create it
        init_si_lock();
    }
    osRecvMesg(&gSiLockQueue, &gSiLockReceivedMessage, OS_MESG_BLOCK);
}

void release_si_lock(void) {
    osSendMesg(&gSiLockQueue, 0, OS_MESG_NOBLOCK);
}

void reset_rumble_state(void) {
    s16 i;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        gRumbleState.state.motorRunning[i] = 0;
        gRumbleState.state.startIntensity[i] = 0;
        gRumbleState.state.endIntensity[i] = 0;
        gRumbleState.state.durationTicks[i] = 0;
        gRumbleState.state.remainingTicks[i] = 0;
        gRumbleState.state.unk28[i] = 0;
        gRumbleState.state.pulseAccumulator[i] = 0;
        gRumbleState.unk3C = 0;
        if (gRumbleState.hasRumblePak[i] == 1) {
            request_rumble_motor_stop(i);
        }
    }
}

void request_rumble_motor_start(s16 cont) {
    gRumbleMotorMessage.status = 2; // MOTOR_START
    gRumbleMotorMessage.controller = cont;
    osSendMesg(&gRumbleMotorQueue, (OSMesg)&gRumbleMotorMessage, OS_MESG_BLOCK);
}

void request_rumble_motor_stop(s16 cont) {
    gRumbleMotorMessage.status = 1; // MOTOR_STOP
    gRumbleMotorMessage.controller = cont;
    osSendMesg(&gRumbleMotorQueue, (OSMesg)&gRumbleMotorMessage, OS_MESG_BLOCK);
}

// motorMain
void thread9(void) {
    RumbleMotorMessage *msg;
    s32 padding;
    s16 status;
    s16 controller;

    do {
        osRecvMesg(&gRumbleMotorQueue, (OSMesg)&msg, OS_MESG_BLOCK);
        acquire_si_lock();
        controller = msg->controller;
        status = msg->status;

        switch (status) {
        case 2: // MOTOR_START
            if ((s16)osMotorStart(&gControllerPakHandles[controller]) == 0) {
                gRumbleState.state.motorRunning[controller] = 1;
            } else {
                gRumbleState.hasRumblePak[controller]= 0;
            }
            break;
        case 1: // MOTOR_STOP
            if ((s16)osMotorStop(&gControllerPakHandles[controller]) == 0) {
                gRumbleState.state.motorRunning[controller] = 0;
            } else {
                gRumbleState.hasRumblePak[controller] = 0;
            }
        }

        release_si_lock();
    }
    while (TRUE);
}

void do_rumble(s16 cont, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    s16 res;
    s16 tmp1;
    s16 tmp2;

    arg4 = arg4 >> 6;

    if ((gRumbleState.hasRumblePak[cont] != 0) && (arg4 < 21)) {
        if (gAttractModeState == 0) {
            arg4 = arg4 >> 2;

            if (arg4 == 0) {
                arg4 = 1;
            }

            if (((gRumbleState.state.durationTicks[cont] == 0))) {
                goto work;
            }

            tmp1 = ((arg1 * (arg2 + arg3)) / (arg4 * 2));
            tmp2 = (((((gRumbleState.state.endIntensity[cont] - gRumbleState.state.startIntensity[cont]) *
                       (gRumbleState.state.durationTicks[cont] - gRumbleState.state.remainingTicks[cont])) / gRumbleState.state.durationTicks[cont]) >> 1) + gRumbleState.state.startIntensity[cont]) * gRumbleState.state.remainingTicks[cont];
            if ((tmp1 >= tmp2)) {
                goto work;
            }
            return;

work:
            gRumbleState.state.motorRunning[cont] = 0;
            gRumbleState.state.startIntensity[cont] = arg2 / arg4;
            gRumbleState.state.endIntensity[cont] = arg3 / arg4;
            gRumbleState.state.unk28[cont] = 0;
            gRumbleState.state.durationTicks[cont] = arg1;
            gRumbleState.state.remainingTicks[cont] = arg1;
            gRumbleState.state.pulseAccumulator[cont] = 0x100;
            if (gRumbleState.state.motorRunning[cont] != 0) {
                res = osMotorStart(gControllerPakHandles);
                if (res == 0) {
                    gRumbleState.state.motorRunning[cont] = 1;
                }
            }
        }
    }
}

void update_rumble(s16 cont) {
    s32 tmp;
    s16 pad0[2] UNUSED;

    if (gRumbleState.hasRumblePak[cont] == 0) {
        if ((++gRumblePakProbeCounter > 60) ) {
            if (osMotorInit(&gSiEventQueue, gControllerPakHandles, 0) == 0) {
                gRumbleState.hasRumblePak[0] = 1;
            } else {
                gRumbleState.hasRumblePak[0] = 0;
            }
            if (gRumbleState.hasRumblePak[0] == 1) {
                osMotorStop(gControllerPakHandles);
            }
            gRumblePakProbeCounter = 0;
        }
        return;
    }

    if (gRumbleState.state.durationTicks[cont] != 0) {
        tmp = (((gRumbleState.state.endIntensity[cont] - gRumbleState.state.startIntensity[cont]) *
                (gRumbleState.state.durationTicks[cont] - gRumbleState.state.remainingTicks[cont])) /
                gRumbleState.state.durationTicks[cont]) + gRumbleState.state.startIntensity[cont];

        if (--gRumbleState.state.remainingTicks[cont] == 0) {
            gRumbleState.state.durationTicks[cont] = 0;
        }
    } else {
        tmp = 0;
    }

    if (tmp >= 71) {
        if (gRumbleState.state.motorRunning[cont] == 0) {
            request_rumble_motor_start(cont);
        }
    }
    if ((tmp < 6) && (gRumbleState.state.motorRunning[cont] != 0)) {
        request_rumble_motor_stop(cont);
    }
    if ((tmp >= 6) && (tmp < 71)) {
        if (gRumbleState.state.pulseAccumulator[cont] >= 256) {
            gRumbleState.state.pulseAccumulator[cont] -= 256;
            if (gRumbleState.state.motorRunning[cont] == 0) {
                request_rumble_motor_start(cont);
            }
        } else {
            gRumbleState.state.pulseAccumulator[cont] += (((tmp * tmp * tmp) / 512) + 4);
            if (gRumbleState.state.motorRunning[cont] != 0) {
                request_rumble_motor_stop(cont);
            }
        }
    }
}

void init_rumble_pak(void) {
    if (gRumbleState.hasRumblePak[0] != 0) {
        if (osMotorInit(&gSiEventQueue, gControllerPakHandles, 0) == 0) {
            gRumbleState.hasRumblePak[0] = 1;
        } else {
            gRumbleState.hasRumblePak[0] = 0;
        }
        if (gRumbleState.hasRumblePak[0] == 1) {
            osMotorStop(gControllerPakHandles);
        }
    }
}
