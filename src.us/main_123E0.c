#include <ultra64.h>
#include "PR/os.h"

#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/main_123E0/func_80136CE0.s")
// NON-MATCHING: 80% of the way there...
// s32 func_80136CE0(void) {
//     s16 i;
//     OSPfs *pfs;
//     s32 res;
//     u8 bitpattern;
//     OSContStatus *contStatus;
//
//     D_802912DA = 0;
//     D_802912DC = 0;
//     D_802912DE = 1;
//     D_802912DF = 1;
//     D_802912E0 = 1;
//     D_802912E1 = 1;
//     D_802912E2 = 1;
//     D_802912E3 = 1;
//     D_802912E4 = 1;
//     D_802912E5 = 1;
//
//     osCreateMesgQueue(&D_8028D0A8, &D_8029104C, 1);
//     osSetEventMesg(5, &D_8028D0A8, 1);
//     osContInit(&D_8028D0A8, &bitpattern, &D_802910D8);
//     D_80158544 = 0;
//
//     for (i = 0; i < 4; i++) {
//         if ((bitpattern & (1 << i)) && ((((D_802910D8[i])->errno) & 8) == 0)) {
//             D_80158544++;
//         }
//     }
//
//     osContSetCh(1);
//     osCreateMesgQueue(&D_802912B0, &D_802912C8, 1);
//     osCreateThread(&gThread9, 9, (void *)func_80137294, 0, &D_8028E230, 9);
//     osStartThread(&gThread9);
//
//     for (i = 0; i < 4; i++) {
//         D_80291090[i].hasRumblePak = 0;
//         if ((bitpattern >> i) & 1) {
//             contStatus = &D_802910D8[i];
//             if ((contStatus->type & CONT_JOYPORT) && (contStatus->status & CONT_CARD_ON)) {
//                 pfs = D_80291110[i];
//                 res = osPfsInit(&D_8028D0A8, pfs, i);
//                 if ((res == PFS_ERR_ID_FATAL) || (res == PFS_ERR_DEVICE)) {
//                     if (osMotorInit(&D_8028D0A8, pfs, i) == 0) {
//                         D_80291090[i].hasRumblePak = (u8)1;
//                     }
//                 }
//             }
//         }
//     }
//
//     D_802912D4 = osEepromProbe(&D_8028D0A8);
//     func_80137168();
//     return D_80158544;
// }

void func_80136F64(void) {
    u16 *temp_v0 = D_802910D0; // pointer to controller input bitmask

    if (temp_v0 != 0) {
        if (*temp_v0 & CONT_START) {
            D_802912DE = 0;
        } else {
            D_802912DE = 1;
        }
        if (*temp_v0 & CONT_A) {
            D_802912DF = 0;
        } else {
            D_802912DF = 1;
        }
        if (*temp_v0 & CONT_B) {
            D_802912E0 = 0;
        } else {
            D_802912E0 = 1;
        }
        if (*temp_v0 & CONT_UP) {
            D_802912E1 = 0;
        } else {
            D_802912E1 = 1;
        }
        if (*temp_v0 & CONT_DOWN) {
            D_802912E2 = 0;
        } else {
            D_802912E2 = 1;
        }
        if (*temp_v0 & CONT_LEFT) {
            D_802912E3 = 0;
        } else {
            D_802912E3 = 1;
        }
        if (*temp_v0 & CONT_RIGHT) {
            D_802912E4 = 0;
        } else {
            D_802912E4 = 1;
        }
        if (*temp_v0 & Z_TRIG) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/main_123E0/func_80137168.s")
// I dont understand this function... this isnt right
// void func_80137168(void) {
//     s16 i;
//     Controller *cont;
//
//     for (i = 0; i < 4; i++) {
//
//         cont = &D_80291090[i];
//         cont->unk2 = 0;
//         cont->unk4 = 0;
//         cont->unkC = 0;
//         cont->unk14 = 0;
//         cont->unk1C = 0;
//         cont->unk24 = 0;
//         cont->unk2C = 0;
//         cont->unk34 = 0;
//         cont->unk3C = 0;
//
//         if (cont->hasRumblePak == 1) {
//             func_8013724C(i);
//         }
//     }
// }

void func_80137204(s16 arg0) {
    D_80291100.status = 2;
    D_80291100.controller = arg0;
    osSendMesg(&D_802912B0, (OSMesg)&D_80291100, OS_MESG_BLOCK);
}

void func_8013724C(s16 arg0) {
    D_80291100.status = 1;
    D_80291100.controller = arg0;
    osSendMesg(&D_802912B0, (OSMesg)&D_80291100, OS_MESG_BLOCK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_123E0/func_80137294.s")
// miles away
// void func_80137294(void) {
//     ControllerMesg *msg;
//     s16 controller;
//     s16 status;
//
//     do {
//         osRecvMesg(&D_802912B0, &msg, OS_MESG_BLOCK);
//         func_801370F4();
//         status = msg->status;
//         controller = msg->controller;
//         // is this a switch?
//         if (status != 1) {
//             if (status == 2) {
//                 if (osMotorStart(&D_80291110[controller]) == 0) {
//                     D_80291090[controller].unk2 = 1;
//                 } else {
//                     D_80291090[controller].hasRumblePak = 0;
//                 }
//             }
//         } else if (osMotorStop(&D_80291110[controller]) == 0) {
//             D_80291090[controller].unk2 = 1;
//         } else {
//             D_80291090[controller].hasRumblePak = 0;
//         }
//         func_8013713C();
//     } while (TRUE);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_123E0/func_801373CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_123E0/func_801375E8.s")

// initialise rumble pack
void func_80137840(void) {
    if (D_80291090[0].hasRumblePak != 0) {
        if (osMotorInit(&D_8028D0A8, &D_80291110, 0) == 0) {
            D_80291090[0].hasRumblePak = 1;
        } else {
            D_80291090[0].hasRumblePak = 0;
        }
        if (D_80291090[0].hasRumblePak == 1) {
            osMotorStop(&D_80291110);
        }
    }
}
