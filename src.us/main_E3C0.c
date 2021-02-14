#include <ultra64.h>
#include "common.h"


// more audio

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80132CC0.s")
// void func_80132CC0(s32 arg0) {
//     s16 temp_a2;
//     void *temp_s0;
//     void *temp_s0_2;
//     void *phi_s0;
//
//     temp_s0 = D_8028631C;
//     rmonPrintf(&D_8015AD90); // ----------------- Active sounds
//     if (temp_s0 != 0) {
//         phi_s0 = temp_s0;
// loop_2:
//         temp_a2 = phi_s0->unk22;
//         // sndState:%d sndSlot:%d sndID:%d object:%p counter:%d sndSlotState[sndSlot]:%d
//         rmonPrintf(&D_8015ADB4, phi_s0->unk24, temp_a2, phi_s0->unk2, phi_s0->unk28, phi_s0->unkE, *(&D_802863B0 + temp_a2));
//         temp_s0_2 = phi_s0->unk30; // pointer to next sound?
//         phi_s0 = temp_s0_2;
//         if (temp_s0_2 != 0) {
//             goto loop_2;
//         }
//     }
// }

// count used sounds?
#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80132D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80132D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80132F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_8013307C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80133188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_8013328C.s")

void func_80133528(u8 arg0, s16 vol) {
    struct017 *temp_v0 = func_80132414(arg0);

    if (temp_v0 != NULL) {
        if ((temp_v0->unk22 >= 0) && (D_802863B0[temp_v0->unk22] != 1)) {
            alSndpSetSound(D_80286310, temp_v0->unk22);
            alSndpSetVol(D_80286310, vol);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_8013359C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80133608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_8013364C.s")

void func_80133738(void) {
    s8 i;

    if (D_80155154) {
        for (i = 0; i < 20; i++) {
            if (func_801323B8(i)) {
                alSndpStop(D_80286310);
            }
        }
        func_8013364C();
        D_8028645C = (u16)0;
    }
}

void func_801337BC(s8 arg0, s32 arg1) {
    D_801552A8 = 1;
    D_80155164 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_801337DC.s")

void func_8013385C(f32 arg0, f32 arg1, f32 arg2)
{
    D_801546C0 = arg0;
    D_801546C4 = arg0;
    D_801546C8 = arg2 / 20.0f;
    D_801546CC = (arg1 - arg2) / 20.0f;
    D_801546BC = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_801338A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_801339F8.s")

void func_80133B74(s16 arg0) {
    D_801546D4 = arg0 / 20.0f;
}

void func_80133BA0(s16 arg0) {
    D_801546D0 = arg0 / 20.0f;
    func_80133C50(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80133BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80133C50.s")

void func_80133E44(void) {
    alCSeqGetLoc(D_802863CC, &D_80286460);
    D_80155180 = D_8028645C;
    D_80155184 = 0;
}

void func_80133E84(void) {
    if ((D_80155180 == D_8028645C) && (D_8028645C != 0)) {
        D_80155184 += 1;
        if (D_80155184 >= 3) {
            alCSeqSetLoc(D_802863CC, &D_80286460);
            D_80155180 = 0;
        }
    }
}
