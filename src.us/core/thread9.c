#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

s16 D_80158540 = 0;
s32 numControllers = 0;

// ========================================================
// .bss
// ========================================================

Controller   gRumbleState;
OSContPad   *gControllerInput;
OSContStatus gControllerStatus[MAXCONTROLLERS];
OSContPad    D_802910E8[MAXCONTROLLERS];

RumbleMotorMessage D_80291100;
s32 D_80291108; // unused?
s32 D_8029110C; // unused?

OSPfs       D_80291110[MAXCONTROLLERS];
OSMesgQueue D_802912B0;
OSMesg      D_802912C8;
OSMesg      D_802912CC;
s32  D_802912D0;
s32  gEepromType;
s16  gControllerConnected;
u16  D_802912DA;
s16  D_802912DC;
u8   D_802912DE; // start pressed
u8   D_802912DF; // a pressed
u8   D_802912E0; // b pressed
u8   D_802912E1; // d-up pressed
u8   D_802912E2; // d-down pressed
u8   D_802912E3; // d-left pressed
u8   D_802912E4; // d-right pressed
u8   D_802912E5; // z pressed

// ========================================================
// .text
// ========================================================

s32 init_controllers(void) {
    s16 i;
    s32 pad;
    u8 pattern; // sp57
    s32 status;

    D_802912DA = 0;
    D_802912DC = 0;
    D_802912DE = 1;
    D_802912DF = 1;
    D_802912E0 = 1;
    D_802912E1 = 1;
    D_802912E2 = 1;
    D_802912E3 = 1;
    D_802912E4 = 1;
    D_802912E5 = 1;

    osCreateMesgQueue(&D_8028D0A8, D_8029104C, 1);
    osSetEventMesg(5U, &D_8028D0A8, (void *)1);
    osContInit(&D_8028D0A8, &pattern, gControllerStatus);

    numControllers = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if ((pattern & (1 << i)) && !(gControllerStatus[i].errno & 8)) {
            numControllers++;
        }
    }
    osContSetCh(1U);
    osCreateMesgQueue(&D_802912B0, &D_802912C8, 1);

    osCreateThread(&gThread9, 9, (void (*)(void *)) thread9, NULL, &thread9_stack[sizeof(thread9_stack) / sizeof(u64)], 9);
    osStartThread(&gThread9);

    for (i = 0; i < MAXCONTROLLERS; i++) {
        gRumbleState.hasRumblePak[i] = 0;

        if ((pattern >> i) & 1) {
            if (gControllerStatus[i].type & CONT_JOYPORT) {
                if (gControllerStatus[i].status & CONT_CARD_ON) {
                    status = osPfsInit(&D_8028D0A8, (s32)&D_80291110[i], i);
                    if ((status == 10) || (status == 11)) {}
                    if (((status == PFS_ERR_ID_FATAL)) || (status == PFS_ERR_DEVICE)) {
                        if (osMotorInit(&D_8028D0A8, (s32)&D_80291110[i], i) == 0) {
                            gRumbleState.hasRumblePak[i] = 1;
                        }
                    }
                }
            }
        }
    }

    gEepromType = osEepromProbe(&D_8028D0A8);
    func_80137168();
    return numControllers;
}

void func_80136F64(void) {
    OSContPad *ci = gControllerInput;

    if (ci != 0) {
        if (ci->button & CONT_START) {
            D_802912DE = 0;
        } else {
            D_802912DE = 1;
        }
        if (ci->button & CONT_A) {
            D_802912DF = 0;
        } else {
            D_802912DF = 1;
        }
        if (ci->button & CONT_B) {
            D_802912E0 = 0;
        } else {
            D_802912E0 = 1;
        }
        if (ci->button & CONT_UP) {
            D_802912E1 = 0;
        } else {
            D_802912E1 = 1;
        }
        if (ci->button & CONT_DOWN) {
            D_802912E2 = 0;
        } else {
            D_802912E2 = 1;
        }
        if (ci->button & CONT_LEFT) {
            D_802912E3 = 0;
        } else {
            D_802912E3 = 1;
        }
        if (ci->button & CONT_RIGHT) {
            D_802912E4 = 0;
        } else {
            D_802912E4 = 1;
        }
        if (ci->button & Z_TRIG) {
            D_802912E5 = 0;
        } else {
            D_802912E5 = 1;
        }
    }
}

void init_si_lock(void) {
    D_80158540 = 1;
    osCreateMesgQueue(&D_8028D090, D_80291048, 1);
    osSendMesg(&D_8028D090, 0, OS_MESG_NOBLOCK);
}

void acquire_si_lock(void) {
    if (D_80158540 == 0) {
        // if message queue not created, create it
        init_si_lock();
    }
    osRecvMesg(&D_8028D090, &D_802912CC, OS_MESG_BLOCK);
}

void release_si_lock(void) {
    osSendMesg(&D_8028D090, 0, OS_MESG_NOBLOCK);
}

void func_80137168(void) {
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
    D_80291100.status = 2; // MOTOR_START
    D_80291100.controller = cont;
    osSendMesg(&D_802912B0, (OSMesg)&D_80291100, OS_MESG_BLOCK);
}

void request_rumble_motor_stop(s16 cont) {
    D_80291100.status = 1; // MOTOR_STOP
    D_80291100.controller = cont;
    osSendMesg(&D_802912B0, (OSMesg)&D_80291100, OS_MESG_BLOCK);
}

// motorMain
void thread9(void) {
    RumbleMotorMessage *msg;
    s32 padding;
    s16 status;
    s16 controller;

    do {
        osRecvMesg(&D_802912B0, (OSMesg)&msg, OS_MESG_BLOCK);
        acquire_si_lock();
        controller = msg->controller;
        status = msg->status;

        switch (status) {
        case 2: // MOTOR_START
            if ((s16)osMotorStart(&D_80291110[controller]) == 0) {
                gRumbleState.state.motorRunning[controller] = 1;
            } else {
                gRumbleState.hasRumblePak[controller]= 0;
            }
            break;
        case 1: // MOTOR_STOP
            if ((s16)osMotorStop(&D_80291110[controller]) == 0) {
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
                res = osMotorStart(D_80291110);
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
        if ((++D_802912DC > 60) ) {
            if (osMotorInit(&D_8028D0A8, D_80291110, 0) == 0) {
                gRumbleState.hasRumblePak[0] = 1;
            } else {
                gRumbleState.hasRumblePak[0] = 0;
            }
            if (gRumbleState.hasRumblePak[0] == 1) {
                osMotorStop(D_80291110);
            }
            D_802912DC = 0;
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
        if (osMotorInit(&D_8028D0A8, D_80291110, 0) == 0) {
            gRumbleState.hasRumblePak[0] = 1;
        } else {
            gRumbleState.hasRumblePak[0] = 0;
        }
        if (gRumbleState.hasRumblePak[0] == 1) {
            osMotorStop(D_80291110);
        }
    }
}
