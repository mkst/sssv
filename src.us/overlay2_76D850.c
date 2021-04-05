#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035C1A0_76D850.s")
// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035D120_76E7D0.s")

void func_8035D6A0_76ED50(void) {
    if (D_803F2EDC != 0) {
        func_8029A624_6ABCD4(&D_801D9E88);
    }
}

void func_8035D6D0_76ED80(void) {
    if (D_803D552C->unk348 != 0) {
        if (D_803D552C->unk34A != 0) {
            D_803D552C->unk34A -= 1;
        } else {
            D_803D552C->unk348 -= 1;
        }
    }
    if ((D_803D552C->unk36B - 1) < 0) {
        D_803D552C->unk36B = 0;
    } else {
        D_803D552C->unk36B -= 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035D734_76EDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035DA60_76F110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76D850/func_8035DEC4_76F574.s")
// void func_8035DEC4_76F574(void) {
//     s32 tmp;
//
//     if (D_803D552C->unk366 != 5) {
//         if (D_803D552C->unk2EE < 385) {
//             D_803F2EBC += D_80152C78[(u8)(D_803D552C->unk2EE * 16)] >> 2;
//             D_803F2EC0 += D_80152C78[(u8)(D_803D552C->unk2EE * 16)] >> 2;
//             D_803F2EC4 += D_80152C78[(u8)(D_803D552C->unk2EE * 16)] >> 2;
//         } else {
//             D_803F2EBC += D_80152C78[(u8)(D_803D552C->unk2EE * 8)] >> 2;
//             D_803F2EC0 += D_80152C78[(u8)(D_803D552C->unk2EE * 8)] >> 2;
//             D_803F2EC4 += D_80152C78[(u8)(D_803D552C->unk2EE * 8)] >> 2;
//         }
//         if (D_803F2D10.unk0 == 0) {
//             D_803D552C->unk2EE += 1;
//         }
//         // what is going on here?
//         if (D_803D5530->state == 23) {
//             if (D_803D552C->unk2EE == 0) {
//                 D_803D552C->unk2EE = -63;
//             }
//         }
//         if (D_803D5530->state == 4) {
//             if (D_803D552C->unk2EE == 0) {
//                 D_803D552C->unk2EE -= 1;
//             }
//         }
//         if (D_803D5530->state == 42) {
//             if (D_803D552C->unk2EE == 0) {
//                 D_803D552C->unk2EE = -1;
//             }
//         }
//         if (D_803D5530->state == 0x69) {
//             if (D_803D552C->unk2EE == 0) {
//                 D_803D552C->unk2EE = -1;
//             }
//         }
//     }
// }
