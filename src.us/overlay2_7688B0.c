#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7688B0/func_80357200_7688B0.s")
//WORKED ON BUT STILL NOT QUITE MATCHING
// void func_80357200_7688B0(void) {
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s32 temp_t1;
//     struct036 *temp_v1;
//
//     temp_v0 = D_8028645C;
//     if (temp_v0 < 0x65) {
//         if ((temp_v0 != 9) && (temp_v0 != 5) && (temp_v0 != 0x18)) {
//             D_8028645C = D_803F2D23;
//             return;
//         }
//         temp_v0_2 = gCurrentAnimalIndex;
//         temp_v1 = &D_801D9ED8[temp_v0_2].unk0;
//         D_803D5520 = &temp_v1->unk3EB0;
//         D_803D5524 = temp_v1->unk3EB0;
//         temp_t1 = temp_v1->animal;
//         D_803D5528 = temp_t1;
//         D_803D552C = temp_t1;
//         D_803D5530 = temp_t1;
//         D_803D5538 = 1;
//         D_803D553C = temp_v0_2;
//         D_803D553A = 0;
//     }
// }

void func_803572B0_768960(s8 arg0) {
    D_803F2D23 = arg0;
}

s32 func_803572C0_768970(void) {
    D_803F2D20 = 0;
    D_803F2D22 = 1;
    D_803F2D23 = 1;
    D_8028645C = 1;
    return 1;
}
