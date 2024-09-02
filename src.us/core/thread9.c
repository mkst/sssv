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

u8 main_bss_padding[0xabB0];

ControllerMesg D_80291100;
s32 D_80291108; // unused?
s32 D_8029110C; // unused?

OSPfs       D_80291110[MAXCONTROLLERS];
OSMesgQueue D_802912B0;
OSMesg      D_802912C8;
OSMesg      D_802912CC;
s32  D_802912D0;
s32  D_802912D4;
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

#ifdef NON_MATCHING
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

    osCreateMesgQueue(&D_8028D0A8, &D_8029104C, 1);
    osSetEventMesg(5U, &D_8028D0A8, (void *)1);

    if((s32)&D_80291110[0]) {};
    if (0) { }

    osContInit(&D_8028D0A8, &pattern, gControllerStatus);

    numControllers = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if ((pattern & (1 << i)) && !(gControllerStatus[i].errno & 8)) {
            numControllers++;
        }
    }
    osContSetCh(1U);
    osCreateMesgQueue(&D_802912B0, &D_802912C8, 1);

    osCreateThread(&gThread9, 9, (void (*)(void *)) thread9, NULL, &D_8028E230, 9);
    osStartThread(&gThread9);

    for (i = 0; i < MAXCONTROLLERS; i++) {
        D_80291090.hasRumblePak[i] = 0;

        if ((pattern >> i) & 1) {
            if (gControllerStatus[i].type & CONT_JOYPORT) {
                if (gControllerStatus[i].status & CONT_CARD_ON) {
                    status = osPfsInit(&D_8028D0A8, (s32)&D_80291110[i], i);
                    if (((status == PFS_ERR_ID_FATAL)) || (status == PFS_ERR_DEVICE)) {
                        if (osMotorInit(&D_8028D0A8, (s32)&D_80291110[i], i) == 0) {
                            D_80291090.hasRumblePak[i] = 1;
                        }
                    }
                }
            }
        }
    }

    D_802912D4 = osEepromProbe(&D_8028D0A8);
    func_80137168();
    return numControllers;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/thread9/init_controllers.s")
#endif

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

void func_801370A4(void) {
    D_80158540 = 1;
    osCreateMesgQueue(&D_8028D090, &D_80291048, 1);
    osSendMesg(&D_8028D090, 0, OS_MESG_NOBLOCK);
}

void func_801370F4(void) {
    if (D_80158540 == 0) {
        // if message queue not created, create it
        func_801370A4();
    }
    osRecvMesg(&D_8028D090, &D_802912CC, OS_MESG_BLOCK);
}

void func_8013713C(void) {
    osSendMesg(&D_8028D090, 0, OS_MESG_NOBLOCK);
}

void func_80137168(void) {
    s16 i;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        D_80291090.state.unk0[i] = 0;
        D_80291090.state.unk8[i] = 0;
        D_80291090.state.unk10[i] = 0;
        D_80291090.state.unk18[i] = 0;
        D_80291090.state.unk20[i] = 0;
        D_80291090.state.unk28[i] = 0;
        D_80291090.state.unk30[i] = 0;
        D_80291090.unk3C = 0;
        if (D_80291090.hasRumblePak[i] == 1) {
            func_8013724C(i);
        }
    }
}

void func_80137204(s16 cont) {
    D_80291100.status = 2; // MOTOR_OFF
    D_80291100.controller = cont;
    osSendMesg(&D_802912B0, (OSMesg)&D_80291100, OS_MESG_BLOCK);
}

void func_8013724C(s16 cont) {
    D_80291100.status = 1; // MOTOR_ON
    D_80291100.controller = cont;
    osSendMesg(&D_802912B0, (OSMesg)&D_80291100, OS_MESG_BLOCK);
}

// motorMain
void thread9(void) {
    ControllerMesg *msg;
    s32 padding;
    s16 status;
    s16 controller;

    do {
        osRecvMesg(&D_802912B0, (OSMesg)&msg, OS_MESG_BLOCK);
        func_801370F4();
        controller = msg->controller;
        status = msg->status;

        switch (status) {
        case 2: // MOTOR_OFF
            if ((s16)osMotorStart(&D_80291110[controller]) == 0) { // are these functions backwards?
                D_80291090.state.unk0[controller] = 1;
            } else {
                D_80291090.hasRumblePak[controller]= 0;
            }
            break;
        case 1: // MOTOR_ON
            if ((s16)osMotorStop(&D_80291110[controller]) == 0) {
                D_80291090.state.unk0[controller] = 0;
            } else {
                D_80291090.hasRumblePak[controller] = 0;
            }
        }

        func_8013713C();
    }
    while (TRUE);
}

void do_rumble(s16 cont, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    s16 res;
    s16 tmp1;
    s16 tmp2;

    arg4 = arg4 >> 6;

    if ((D_80291090.hasRumblePak[cont] != 0) && (arg4 < 21)) {
        if (D_80204288 == 0) {
            arg4 = arg4 >> 2;

            if (arg4 == 0) {
                arg4 = 1;
            }

            if (((D_80291090.state.unk18[cont] == 0))) {
                goto work;
            }

            tmp1 = ((arg1 * (arg2 + arg3)) / (arg4 * 2));
            tmp2 = (((((D_80291090.state.unk10[cont] - D_80291090.state.unk8[cont]) *
                       (D_80291090.state.unk18[cont] - D_80291090.state.unk20[cont])) / D_80291090.state.unk18[cont]) >> 1) + D_80291090.state.unk8[cont]) * D_80291090.state.unk20[cont];
            if ((tmp1 >= tmp2)) {
                goto work;
            }
            return;

work:
            D_80291090.state.unk0[cont] = 0;
            D_80291090.state.unk8[cont] = arg2 / arg4;
            D_80291090.state.unk10[cont] = arg3 / arg4;
            D_80291090.state.unk28[cont] = 0;
            D_80291090.state.unk18[cont] = arg1;
            D_80291090.state.unk20[cont] = arg1;
            D_80291090.state.unk30[cont] = 0x100;
            if (D_80291090.state.unk0[cont] != 0) {
                res = osMotorStart(D_80291110);
                if (res == 0) {
                    D_80291090.state.unk0[cont] = 1;
                }
            }
        }
    }
}

void func_801375E8(s16 cont) {
    s32 tmp;
    s16 pad0[2];

    if (D_80291090.hasRumblePak[cont] == 0) {
        if ((++D_802912DC > 60) ) {
            if (osMotorInit(&D_8028D0A8, D_80291110, 0) == 0) {
                D_80291090.hasRumblePak[0] = 1;
            } else {
                D_80291090.hasRumblePak[0] = 0;
            }
            if (D_80291090.hasRumblePak[0] == 1) {
                osMotorStop(D_80291110);
            }
            D_802912DC = 0;
        }
        return;
    }

    if (D_80291090.state.unk18[cont] != 0) {
        tmp = (((D_80291090.state.unk10[cont] - D_80291090.state.unk8[cont]) *
                (D_80291090.state.unk18[cont] - D_80291090.state.unk20[cont])) /
                D_80291090.state.unk18[cont]) + D_80291090.state.unk8[cont];

        if (--D_80291090.state.unk20[cont] == 0) {
            D_80291090.state.unk18[cont] = 0;
        }
    } else {
        tmp = 0;
    }

    if (tmp >= 71) {
        if (D_80291090.state.unk0[cont] == 0) {
            func_80137204(cont);
        }
    }
    if ((tmp < 6) && (D_80291090.state.unk0[cont] != 0)) {
        func_8013724C(cont);
    }
    if ((tmp >= 6) && (tmp < 71)) {
        if (D_80291090.state.unk30[cont] >= 256) {
            D_80291090.state.unk30[cont] -= 256;
            if (D_80291090.state.unk0[cont] == 0) {
                func_80137204(cont);
            }
        } else {
            D_80291090.state.unk30[cont] += (((tmp * tmp * tmp) / 512) + 4);
            if (D_80291090.state.unk0[cont] != 0) {
                func_8013724C(cont);
            }
        }
    }
}

void init_rumble_pak(void) {
    if (D_80291090.hasRumblePak[0] != 0) {
        if (osMotorInit(&D_8028D0A8, D_80291110, 0) == 0) {
            D_80291090.hasRumblePak[0] = 1;
        } else {
            D_80291090.hasRumblePak[0] = 0;
        }
        if (D_80291090.hasRumblePak[0] == 1) {
            osMotorStop(D_80291110);
        }
    }
}
