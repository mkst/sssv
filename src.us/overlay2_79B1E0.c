#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79B1E0/func_80389B30_79B1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79B1E0/func_8038B330_79C9E0.s")

void func_8038B730_79CDE0(void) {
    D_803D5528->unk3C0 = 0;
    D_803D552C->unk30C = 1;
    if (D_803D5530->unk4A != 0) {
        D_803D552C->unk30C = 0;
    }
}

void func_8038B774_79CE24(void) {
    D_803D552C->unk30C = 0;
    D_803D552C->unk30E = 0;
    D_803D552C->unk310 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79B1E0/func_8038B798_79CE48.s")
// void func_8038B798_79CE48(void) {
//     s16 temp_a0;
//     Animal *temp_t0;
//     struct036 *temp_v0;
//
//     temp_a0 = gCurrentAnimalIndex;
//     temp_v0 = &D_801D9ED8[temp_a0];
//     D_803D5520 = &temp_v0->unk3EB0;
//     D_803D5524 = temp_v0->unk3EB0;
//     D_803D5528 = temp_v0->animal;
//     D_803D552C = temp_v0->animal;
//     D_803D5530 = temp_v0->animal;
//     D_803D5538 = 1;
//     D_803D553C = temp_a0;
//     D_803D553A = 0;
//     if (D_803D5530->unk162 == 1) {
//         // this doesnt make sense?
//         func_802A6390_6B7A40(temp_a0, &D_803D5528, &D_803D5530);
//     }
// }
