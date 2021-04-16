#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DA7F0_6EBEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DA90C_6EBFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DAD18_6EC3C8.s")
// no idea what is up with these random offsets
// void func_802DAD18_6EC3C8(void *arg0) {
//     void *temp_a1;
//     struct044 *temp_a2;
//     struct044 *temp_a2_2;
//     s16 i;
//
//     for (i = 0; i < 4; i++) {
//         if (arg0->unk114[i] != (u16)0x7FFF) {
//             temp_a1 = arg0 + (i * 0xC);
//             temp_a2 = temp_a1->unk11C;
//             temp_a1->unk120 = temp_a1->unk11C; // is unk120 another pointer?
//             if (temp_a1->unk11C != 0) {
//                 temp_a2->unk0->unk4 = temp_a2->unk4;
//             }
//             temp_a2_2 = temp_a1->unk11C;
//             temp_a2_2->unk4 = NULL;
//             temp_a2_2->unk0 = NULL;
//             temp_a2_2->unk8 = NULL;
//             arg0->unk114[i] = (u16)0x7FFF;
//         }
//     }
// }

// ???
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DADA0_6EC450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DAE5C_6EC50C.s")

void func_802DAF5C_6EC60C(void) {
    s16 i;

    for (i = 0; i < 40; i++) {
        D_803DA110[i].unk0 = 0;
        D_803DA110[i].unk4 = 0;
        D_803DA110[i].unk8 = 0;
    }

    D_803DA2F0 = NULL;
    D_803DA2F4 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DAFAC_6EC65C.s")
// JUSTREG
// void func_802DAFAC_6EC65C(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
//     Animal *ptr;
//     // s64 foo = arg0;
//     s32 a0 = arg0;
//     s32 a1 = arg1;
//     s32 a2 = arg2;
//     s32 a3 = arg3;
//
//
//     for (ptr = D_803DA2F4; ptr != NULL; ptr = ptr->unk198) {
//         if (((ptr->xPos >= ((a0 + a2 + 1) << 22) >> 16)) &&
//              (ptr->xPos >= ((a0             << 22) >> 16)) &&
//             ((ptr->zPos >= ((a1 + a3 + 1) << 22) >> 16)) &&
//              (ptr->zPos >= ((a1             << 22) >> 16))) {
//                 ptr->unk4F |= 0x40;
//         }
//     }
// }
