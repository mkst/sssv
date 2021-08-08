#include <ultra64.h>
#include "common.h"

// minigame?

void func_802CB360_6DCA10(void) {
    D_803D6120.unk0 = 0;
    memset_bytes((u8*)&D_803D6120, 0, sizeof(D_803D6120));
    D_803DA0F4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802CB394_6DCA44.s")

void func_802D5AD8_6E7188(s16 arg0, s16 arg1) {
    s16 i;

    for (i = arg0; i < arg1; i++) {
        if (D_803D6120.unk3FC8[i] == 1) {
            gSPDisplayList(D_801D9E7C++, &D_80204278->unk109A0[i])
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D5B88_6E7238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D5F4C_6E75FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D6738_6E7DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D7434_6E8AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D760C_6E8CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D7AD4_6E9184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D7BE0_6E9290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D9C64_6EB314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D9FC4_6EB674.s")
