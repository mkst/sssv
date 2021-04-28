#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C8440_6D9AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C85EC_6D9C9C.s")

void func_802C87E0_6D9E90(void) {
    D_80204278->usedHilites = 0;
    D_80204278->unk3891C = 0;
    D_803E1B04 = 0;
    D_803F3310 = 0;
    if (D_803F2D10.unk0 == 0) {
        D_803D5540 = (D_803D5540 + 1) & 0xFF;
        D_803D5542 = (D_803D5542 + 1) % 360;
        D_803D5544 += 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C8878_6D9F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C8FC0_6DA670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9340_6DA9F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C93E8_6DAA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C941C_6DAACC.s")

struct071 *func_802C9488_6DAB38(void) {
    struct071 *obj;

    if (D_801F9EB8.unkA114 >= 170) {
        return NULL;
    }
    obj = D_80203D1C[D_801F9EB8.unkA110--];

    if (D_801F9EB8.unkA110 < 0) {
        D_801F9EB8.unkA110 = 169;
    }
    D_801F9EB8.unkA114 += 1; // used?

    obj->unk26C = 0;
    return obj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9500_6DABB0.s")
// void func_802C9500_6DABB0(struct071 *obj) {
//
//     D_80203D1C[D_801F9EB8.unkA112--] = obj;
//     if (D_801F9EB8.unkA112 < 0) {
//         D_801F9EB8.unkA112 = 169;
//     }
//     D_801F9EB8.unkA114--;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9564_6DAC14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9834_6DAEE4.s")

void func_802C985C_6DAF0C(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9884_6DAF34.s")

void func_802C9900_6DAFB0(struct071 *arg0, s32 arg1, u8 arg2) {
    arg0->unk24C[arg2] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9918_6DAFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9BA4_6DB254.s")
