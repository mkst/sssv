#include <ultra64.h>
#include "common.h"


void func_802DA7F0_6EBEA0(void) {
    void (*func)(void *);
    Animal *a;
    Animal *tmp;

    a = D_803DA2F0;
    while (a != NULL) {
        func = a->unk16C->unk84;
        if (func != NULL) {
            func(a);
        }
        func_802FB270_70C920(a);
        tmp = a;
        if (tmp->unk26C != 0) {
            a = a->unk198;
            func_802DAE5C_6EC50C(tmp);
            func_802C9500_6DABB0(tmp);
        } else {
            func_802DA90C_6EBFBC(tmp);
            a = a->unk198;
        }
    }

    a = D_803DA2F4;
    while (a != NULL) {
        func = a->unk16C->unk84;
        if (func != NULL) {
            func(a);
        }
        if (a->unk4C.unk25) {
            func_802FB270_70C920(a);
            tmp = a;
            if (tmp->unk26C != 0) {
                a = a->unk198;
                func_802DAE5C_6EC50C(tmp);
                func_802C9500_6DABB0(tmp);
            } else {
                func_802DA90C_6EBFBC(tmp);
                a = a->unk198;
            }
        } else {
            a = a->unk198;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DA90C_6EBFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DAD18_6EC3C8.s")
// no idea what is up with these random offsets
// void func_802DAD18_6EC3C8(Animal *arg0) {
//     Animal *temp_a1;
//     struct044 *temp_a2;
//     struct044 *temp_a2_2;
//     s16 i;
//
//     for (i = 0; i < 4; i++) {
//         if (arg0->unk114[i] != 0x7FFF) {
//             temp_a1 = arg0 + (i * 0xC);
//             temp_a2 = temp_a1->unk11C;
//             temp_a1->unk120 = temp_a1->unk11C; // is unk120 another pointer?
//             if (temp_a1->unk11C != 0) {
//                 temp_a2->unk0->unk4 = temp_a2->unk4;
//             }
//             temp_a2_2 = &temp_a1->unk11C[i];
//             temp_a2_2->unk4 = NULL;
//             temp_a2_2->unk0 = NULL;
//             temp_a2_2->unk8 = NULL;
//             arg0->unk114[i] = 0x7FFF;
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collist2/func_802DADA0_6EC450.s")
// void func_802DADA0_6EC450(Animal *arg0) {
//     Animal *temp_v0;
//     Animal **phi_v0;
//     s16 i;
//
//     if (arg0->unk16C->unk80.bit2) {
//         phi_v0 = &D_803DA2F0;
//         arg0->unk26D = 1;
//     } else {
//         phi_v0 = &D_803DA2F4;
//         arg0->unk26D = 2;
//     }
//
//     if (arg0->unk16C->unk0 < 256) {
//         arg0->unk198 = *phi_v0;
//         *phi_v0 = arg0;
//     }
//
//     for (i = 0; i < 4; i++) {
//         arg0->unk114[i] = 0x7FFF;
//         temp_v0 = arg0 + (i * 12); // what is this
//         temp_v0->unk11C = 0;
//         temp_v0->unk120 = 0;
//         temp_v0->unk124 = 0;
//     }
//
//     func_802DA90C_6EBFBC(arg0);
// }

void func_802DAE5C_6EC50C(Animal *arg0) {
    Animal **a;

    func_802DAD18_6EC3C8(arg0);
    switch (arg0->unk26D) {
    case 1:
        a = &D_803DA2F0;
        break;
    case 2:
        a = &D_803DA2F4;
        break;
    default:
        a = NULL;
        break;
    }

    if (a != NULL) {

        while ((*a != NULL) && (*a != arg0)) {
            a = &(*a)->unk198;
        }

        if (*a == NULL) {
            rmonPrintf("collist2. Object has been deleted but was not in list. %d.\n", arg0->unk26D);
            rmonPrintf("psMoveObj %p ID %d XYZ %d %d %d\n", arg0, arg0->unk16C->unk0, arg0->xPos, arg0->zPos, arg0->yPos);
            SSSV_ASSERT(FALSE, "../src/collist2.c", 436);
        } else {
            *a = arg0->unk198;
        }
    }
    arg0->unk198 = NULL;
    arg0->unk26D = 0U;
}

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

void func_802DAFAC_6EC65C(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    Animal *ptr;
    s32 a0 = arg0;
    s32 a1 = arg1;
    s32 a2 = arg2;
    s32 a3 = arg3;

    for (ptr = D_803DA2F4; ptr != NULL; ptr = ptr->unk198) {
        if (((s16)(a0 + a2 + 1 << 6) >= ptr->xPos) &&
            ((s16)(a0          << 6) <= ptr->xPos) &&
            ((s16)(a1 + a3 + 1 << 6) >= ptr->zPos) &&
            ((s16)(a1          << 6) <= ptr->zPos)) {
              ptr->unk4C.unk25 = 1;
        }
    }
}
