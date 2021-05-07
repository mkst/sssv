#include <ultra64.h>
#include "common.h"


void func_80304170_715820(void) {
    s16 i;
    for (i = 0; i < 256; i++) {
        // was there debug stuff here?
    }
}

void func_80304194_715844(void) {
    s16 i;
    for (i = 0; i < 256; i++) {
        D_803E3130[i].unk0 = 0;
        D_803E3130[i].unk4 = 0;
        D_803E3130[i].unk8 = 0;
        D_803E3130[i].unkC = 0;
        D_803E3130[i].unk10 = 0;
        D_803E3130[i].unk2 = 0;
        D_803E3130[i].unk14 = 0;
        D_803E4AD0[i] = 1;
    }
}

// fat switch statement with display lists
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_715820/func_803041FC_7158AC.s")
