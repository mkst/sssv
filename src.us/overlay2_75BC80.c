#include <ultra64.h>
#include "common.h"


void func_8034A5D0_75BC80(void) {
    func_802D760C_6E8CBC(
        D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void func_8034A60C_75BCBC(void) {
    func_802D760C_6E8CBC(
        D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

void func_8034A648_75BCF8(void) {
    func_802D760C_6E8CBC(
        D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos,
        D_803D5530->unk30, D_803D5530->yVelocity.h);
}

// not even remotely close
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034A684_75BD34.s")
// void func_8034A684_75BD34(void) {
//     u8  sp64;
//     s16 temp_t0;
//     u16 temp_s4;
//     u16 temp_s5;
//     u16 temp_t5;
//     u16 temp_t5_2;
//     s32 temp_t6;
//     s32 temp_t6_2;
//     u16 temp_t3;
//     s32 temp_s1;
//     s32 temp_s2;
//     s32 temp_s3;
//     s16 i;
//
//
//     sp64 = func_8012826C(); // & 0xFF;
//     for (i = 0; i < 8; i++) {
//         temp_t0 = sp64 + (i * 32);
//         temp_t3 = D_803D5524->unkBE;
//         temp_t6 = (D_80152C78[(((sp64 + (i << 5)) & 0xFF))]) >> 7;
//         temp_t6_2 = (D_80152C78[((((sp64 + (i << 5)) + 64) & 0xFF))]) >> 7;
//         temp_s1 = D_803A8360[i];
//         temp_s3 = D_803A8358[i];
//         temp_s2 = D_803A8350[i];
//         temp_t5 = ((((s32) temp_s1 >> 2) & 0x3E) | ((temp_s2 << 8) & 0xF800) | ((temp_s3 * 8) & 0x7C0) | 1); // & 0xFFFF;
//         create_particle_effect(
//             ((s32) (temp_t6 * temp_t3) >> 9) + D_803D5530->xPos,
//             ((s32) (temp_t6_2 * temp_t3) >> 9) + D_803D5530->zPos,
//             D_803D5530->yPos + D_803D5524->unkBA,
//             0x24,
//             (temp_t6 << 9) + ((s32) D_803D5530->xVelocity.h >> 1),
//             (temp_t6_2 << 9) + ((s32) D_803D5530->zVelocity.h >> 1),
//             ((func_8012826C() & 0x7FFF) * 4) + 0x30000,
//             8, temp_t5, temp_t5, 0);
//         // ===
//         temp_t5_2 = ((((s32) temp_s1 >> 2) & 0x3E) | ((temp_s2 << 8) & 0xF800) | ((temp_s3 * 8) & 0x7C0) | 1); // & 0xFFFF;
//         create_particle_effect(
//             ((func_8012826C() & 0x1F) + D_803D5530->xPos) - 0x10,
//             ((func_8012826C() & 0x1F) + D_803D5530->zPos) - 0x10,
//             (func_8012826C() & 0x1F) + D_803D5530->yPos + (D_803D5524->unkBA >> 1),
//             0x23,
//             0,
//             0,
//             0,
//             6, temp_t5_2, temp_t5_2, 0);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034A914_75BFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034ABA4_75C254.s")

void func_8034AE34_75C4E4(s32 arg0, Animal *arg1) {
    s16 temp_v0;
    s16 i;

    for (i = 0; i < 2; i++) {
        temp_v0 = func_8012826C();
        if ((temp_v0 & 1) != 0) {
            create_particle_effect(
                (D_803D5530->xPos + (temp_v0 & 0xF)) - 8,
                (D_803D5530->zPos + ((temp_v0 >> 8) & 0xF)) - 8,
                D_803D5530->yPos,
                20, arg0, arg1, 0x8000, 10, 0x7BD9, 0x8C63, 0);
        }
    }
}

void func_8034AF0C_75C5BC(s32 arg0, Animal *arg1) {
    u16 temp_v0;
    u16 i;

    for (i = 0; i < 4; i++) {
        temp_v0 = func_8012826C();
        if ((temp_v0 & 1) != 0) {
            create_particle_effect(
                (D_803D5530->xPos + (temp_v0 & 0xF)) - 8,
                (D_803D5530->zPos + ((temp_v0 & 0xF0) >> 4)) - 8,
                D_803D5530->yPos,
                20, arg0, arg1, 0x8000, 7, 0x7BD9, 0x8C63, 0);
        }
    }
}

void func_8034AFE0_75C690(void) {
}

void func_8034AFE8_75C698(s32 arg0, Animal *arg1) {
}

void func_8034AFF4_75C6A4(s32 arg0, Animal *arg1) {
}

void func_8034B000_75C6B0(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034B008_75C6B8.s")

void func_8034B298_75C948(s16 arg0) {
    s16 sp2E;
    s16 sp2C;

    if ((arg0 == 0) || ((D_803D5540 & 2) == 0)) {
        if ((D_803D5530->state == 143) || (((D_803D5530->state == 142) || (D_803D5530->state == 144)) && ((D_803D5540 & 1) != 0))) {
            sp2E = (((func_8012826C() & 0xF) - 7) * (u16)D_803D5524->unkBE) >> 3;
            sp2C = (((func_8012826C() & 0xF) - 7) * (u16)D_803D5524->unkBE) >> 3;
            func_802D5B88_6E7238(D_803D5530->xPos + sp2E, D_803D5530->zPos + sp2C, D_803D5530->yPos, 28, (func_8012826C() & 3) + 4, 0, 0, 0);
        }
    }
}

void func_8034B3A8_75CA58(s16 arg0) {
    if ((arg0 == 0) || ((D_803D5540 & 2) == 0)) {
        if ((D_803D552C->unk366 == 3) ||
            (D_803D552C->unk366 == 4) ||
            (D_803D552C->unk366 == 1)) {
            if ((D_803D5530->state == 0x8F) ||
                (((D_803D5530->state == 0x8E) ||
                  (D_803D5530->state == 0x90) ||
                  (D_803D5530->state == 0x8D)) && (D_803D5540 & 1))) {
                func_8012826C();
                func_8012826C();
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034B45C_75CB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034B64C_75CCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034B848_75CEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75BC80/func_8034BB38_75D1E8.s")
