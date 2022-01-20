#include <ultra64.h>
#include "common.h"

void func_8032FF94_741644(u8);
void func_80332444_743AF4(u8);
void func_80334470_745B20(u8, u8);
void func_8033641C_747ACC(u8, u8);
void func_803378BC_748F6C(u8);
void func_80337ECC_74957C(u8);
void func_80338E1C_74A4CC(u8);
void func_803391D0_74A880(u8);
void func_80339238_74A8E8(u8);
void func_803392A0_74A950(u8);
void func_803394E4_74AB94(u8, u8);
void func_80339B84_74B234(u8, f32);
void func_8033AAC8_74C178(u8);
void func_8033B118_74C7C8(u8);
void func_8033B594_74CC44(u8);
void func_8033B9B8_74D068(u8);
void func_8033C054_74D704(u8);
void func_8033C320_74D9D0(u8);

// BSS starts at 0x803C0420
//  0x803F2C18 - 0x803C0420 => 0x327f8

s16  D_803F2C18[3]; // BSS

void func_8032F950_741000(void) {
    s16 i;
    s16 phi_v0_2;

    D_803F2AC5 = 0;

    if (D_803F28E0[D_803F2A98].unkD6 != 1) {
        D_803F2ACC = 20;
    } else if (((D_801DDD8C[gCurrentAnimalIndex].unk0->xVelocity.w != 0) ||
                (D_801DDD8C[gCurrentAnimalIndex].unk0->zVelocity.w != 0)) ||
            (ABS(D_801DDD8C[gCurrentAnimalIndex].unk0->yVelocity.h) > 1)) {
        D_803F2ACC = 20;
    } else if (D_803F2ACC > 0) {
        D_803F2ACC = D_803F2ACC - 1;
    }

    phi_v0_2 = D_803F2C18[0];
    if ((phi_v0_2 != 0) && ((phi_v0_2 == 1) || (phi_v0_2 == 2))) {
        D_803F2C18[1] += 1;
        if (D_803F2C18[1] >= D_803F2C18[2]) {
            D_803F2C18[0] = 0;
            D_803F2C18[1] = 0;
            phi_v0_2 = 0;
        }
    }
    switch (phi_v0_2) {
    case 0:
        func_8032FD0C_7413BC(D_803F2A98, 0);
        break;
    case 1:
        func_8032FD0C_7413BC(D_803F2A98, 0);
        if ((func_80344158_755808(D_803F28E0[D_803F2A98].unk0) == 0) &&
            (func_80344158_755808(D_803F28E0[D_803F2AC8].unk0) != 0)) {
            func_8032FD0C_7413BC(D_803F2AC8, 1);
        } else {
            func_8032FD0C_7413BC(D_803F2AC8, 0);
        }
        D_803F2AC5 = 0;
        break;
    case 2:
        if ((D_803F2C18[2] / 2) >= D_803F2C18[1]) {
            func_8032FD0C_7413BC(D_803F2AC8, 0);
        } else {
            if (((D_803F2C18[2] / 2) + 1) == D_803F2C18[1]) {
                D_803F2AA6 = 1;
                for (i = 0; i < 5; i++) {
                    if (D_803F28E0[D_803F2A98].unk0 != 23) {
                        func_8032FD0C_7413BC(D_803F2A98, 0);
                    }
                }
                D_803F2AA6 = 0;
            }
            func_8032FD0C_7413BC(D_803F2A98, 0);
        }
        D_803F2AC5 = 0;
    }

    func_80343438_754AE8();

    if (1) {};

    switch (D_803F2C18[0]) {
    default:
        D_803F2AA0 = 0;
        break;
    case 0:
        if (D_803F28E0[D_803F2A98].unkD6 == 1) {
            D_803F2AA0 = 0;
        } else {
            D_803F2AA0 = 1;
        }
        break;
    case 1:
    case 2:
        D_803F2AA0 = 0;
        if (D_803F28E0[0].unkD6 != 1) {
            D_803F2AA0 = 1;
        }
        if (D_803F28E0[1].unkD6 != 1) {
            D_803F2AA0 = 1;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032FD0C_7413BC.s")
// very close, a2/a3 mixup
// void func_8032FD0C_7413BC(u8 arg0, u8 arg1) {
//
//     func_80342550_753C00(&D_803F28E0[arg0]); // arg0?
//
//     switch (D_803F28E0[arg0].unk0) {
//     case 0:
//         func_80332444_743AF4(arg0);
//         break;
//     case 26:
//         func_8032FF94_741644(arg0);
//         break;
//     case 2:
//     case 12:
//         func_803378BC_748F6C(arg0);
//         break;
//     case 3:
//     case 17:
//         func_80337ECC_74957C(arg0);
//         break;
//     case 4:
//         func_80338E1C_74A4CC(arg0);
//         break;
//     case 19:
//         func_803391D0_74A880(arg0);
//         break;
//     case 20:
//         func_80339238_74A8E8(arg0);
//         break;
//     case 21:
//         func_803392A0_74A950(arg0);
//         break;
//     case 5:
//         func_803394E4_74AB94(arg0, arg1);
//         break;
//     case 6:
//         func_80334470_745B20(arg0, arg1);
//         break;
//     case 7:
//         func_8033641C_747ACC(arg0, 0);
//         break;
//     case 13:
//         func_80339B84_74B234(arg1, 0.0f);
//         break;
//     case 14:
//         func_80339B84_74B234(arg1, 128.0f);
//         break;
//     case 15:
//         func_80339B84_74B234(arg1, 64.0f);
//         break;
//     case 16:
//         func_80339B84_74B234(arg1, 192.0f);
//         break;
//     case 8:
//         func_80339B84_74B234(arg1, 32.0f);
//         break;
//     case 9:
//         func_80339B84_74B234(arg1, 96.0f);
//         break;
//     case 10:
//         func_80339B84_74B234(arg1, 160.0f);
//         break;
//     case 11:
//         func_80339B84_74B234(arg1, 224.0f);
//         break;
//     case 22:
//         func_80339308_74A9B8(arg0);
//         break;
//     case 23:
//     case 24:
//         func_8033AAC8_74C178(arg0);
//         break;
//     case 25:
//         func_8033B118_74C7C8(arg0);
//         break;
//     case 30:
//         func_8033B440_74CAF0(arg1);
//         break;
//     case 27:
//         func_8033C320_74D9D0(arg1);
//         break;
//     case 28:
//         func_8033641C_747ACC(arg0, 1);
//         break;
//     case 29:
//         func_8033B594_74CC44(arg0);
//         break;
//     case 18:
//     case 31:
//         func_8033B9B8_74D068(arg0);
//         break;
//     case 228:
//         func_8033C054_74D704(arg0);
//         break;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032FF94_741644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80332444_743AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80334470_745B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033641C_747ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803378BC_748F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80337ECC_74957C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80338E1C_74A4CC.s")
#if 0
// f64  D_803BE4D0_7CFB80 = 0.8;
void func_80338E1C_74A4CC(u8 arg0) {
    s32 phi_a0;
    s32 phi_v1;
    f32 phi_f0;
    f32 temp;

    D_803F2AD0 = &D_803F28E0[arg0];

    if (D_803F2AD0->unkD6 == 1) {
        D_803F2AD0->unk50 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkC8;
        D_803F2AD0->unk4E = D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        // defaults
        D_803F2AD0->unk50 = 400;
        D_803F2AD0->unk4E = 32;
    }
    if (D_803F2AD0->unk64 < 0) {
        D_803F2AD0->unk34 = D_803F2AD0->unk50 + ((D_803F2AD0->unk64 * D_803F2AD0->unk50) / 4);
    } else {
        D_803F2AD0->unk34 = D_803F2AD0->unk50 + ((D_803F2AD0->unk64 * D_803F2AD0->unk50) / 2);
    }

    phi_f0 = (D_803F2AD0->unk34 - D_803F2AD0->unk30) * 0.18; // D_803BE4D0_7CFB80

    if (!(ABSF(phi_f0) > ABSF(D_803F2AD0->unk38))) {
        phi_a0 = phi_v1 = 1U;
        if (phi_f0 < 0.0f) {
            phi_v1 = -1;
        }
        if (D_803F2AD0->unk38 < 0.0f) {
            phi_a0 = -1;
        }

        if (phi_v1 != phi_a0) {
            goto block_18;
        }
    } else {
block_18:
        if (phi_f0 > 0.0f) {
            phi_f0 = MIN(phi_f0, D_803F2AD0->unk38 + 4.0);
        } else {
            phi_f0 = MAX(phi_f0, D_803F2AD0->unk38 - 4.0);
        }
    }

    D_803F2AD0->unk38 = phi_f0;
    temp = D_803F2AD0->unk30;
    D_803F2AD0->unk30 += phi_f0;

    D_803F2AD0->unkA4 = D_803F2AD0->unkA4 * (D_803F2AD0->unk30 / temp);
    D_803F2AD0->unkA8 = D_803F2AD0->unkA8 * (D_803F2AD0->unk30 / temp);

    D_803F2AD0->unkBC = D_803F2AD0->unkBC * (D_803F2AD0->unk30 / temp);
    D_803F2AD0->unkC0 = D_803F2AD0->unkC0 * (D_803F2AD0->unk30 / temp);

    D_803F2AD0->unk20 = 0.0f;
    D_803F2AD0->unk24 = 0.0f;

    if (D_803F2AD0->unk30 < 1.0) {
        D_803F2AD0->unk30 = 1.0f;
    }

    D_803F2AD0->unk8 = D_803F2AD0->unk98;
    D_803F2AD0->unkC = D_803F2AD0->unk9C;
    D_803F2AD0->unk10 = D_803F2AD0->unkA0 + 4.0;

    D_803F2AD0->unk74 = D_803F2AD0->unk8;
    D_803F2AD0->unk78 = D_803F2AD0->unkC;
    D_803F2AD0->unk7C = D_803F2AD0->unk10 + D_803F2AD0->unk30;

    D_803F2AD0->unk8C = 0.0f;
    D_803F2AD0->unk90 = 1.0f;
    D_803F2AD0->unk94 = 0.0f;

    if (D_803F2AA6 != 0) {
        D_803F2AD0->unk30 = D_803F2AD0->unk34;
        D_803F2AD0->unk38 = 0.0f;
    }
    D_803F2AC5 = 1;
}
#endif

void func_803391D0_74A880(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    D_803F2AD0->unk8C = 0.0f;
    D_803F2AD0->unk90 = -1.0f;
    D_803F2AD0->unk20 = D_803F2AD0->unk24 = 128.0f;
}

void func_80339238_74A8E8(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    D_803F2AD0->unk8C = 1.0f;
    D_803F2AD0->unk90 = 0.0f;
    D_803F2AD0->unk20 = D_803F2AD0->unk24 = 64.0f;
}

void func_803392A0_74A950(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    D_803F2AD0->unk8C = -1.0f;
    D_803F2AD0->unk90 = 0.0f;
    D_803F2AD0->unk20 = D_803F2AD0->unk24 = 192.0f;
}

void func_80339308_74A9B8(u8 arg0) {
    f32 tmp;

    D_803F2AD0 = &D_803F28E0[arg0];
    tmp = D_803F2AD0->unk20;
    func_80338E1C_74A4CC(arg0);
    if ((tmp > 32.0) && (tmp <= 96.0)) {
        D_803F2AD0->unk20 = 64.0f;
        D_803F2AD0->unk8C = 1.0f;
        D_803F2AD0->unk90 = 0.0f;
    } else if ((tmp > 96.0) && (tmp <= 160.0)) {
        D_803F2AD0->unk20 = 128.0f;
        D_803F2AD0->unk8C = 0.0f;
        D_803F2AD0->unk90 = -1.0f;
    } else if ((tmp > 160.0) && (tmp <= 224.0)) {
        D_803F2AD0->unk20 = 192.0f;
        D_803F2AD0->unk8C = -1.0f;
        D_803F2AD0->unk90 = 0.0f;
    } else {
        D_803F2AD0->unk20 = 0.0f;
        D_803F2AD0->unk8C = 0.0f;
        D_803F2AD0->unk90 = 1.0f;
    }
    D_803F2AD0->unk24 = D_803F2AD0->unk20;
    D_803F2AC5 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803394E4_74AB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80339B84_74B234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033AAC8_74C178.s")
// 80% of the way there...
// void func_8033AAC8_74C178(u8 arg0) {
//     f32 temp_f0;
//     f32 temp_f14;
//     f32 phi_f2;
//     s32 temp_a2;
//     u8 temp_a3;
//
//     D_803F2AD0 = &D_803F28E0[arg0];
//     temp_a3 = *D_803F2AD0->unk6C;
//     temp_a2 = temp_a3 << 5;
//     if (D_803F2AD0->unk6 < (temp_a2 - 65)) {
//         D_803F2AD0->unk6 += 1;
//     } else {
//         D_803F2AC5 = 1;
//     }
//     if (temp_a2 == (D_803F2AD0->unk6 + 104)) {
//         D_803F2C6D = 0;
//         D_803F2C6C = 0;
//         D_803F2AD0->unk0 = 24;
//     }
//     func_8033AC68_74C318(&D_803F2AD0->unk74, &D_803F2AD0->unk78, &D_803F2AD0->unk7C, &D_803F2AD0->unk6C, D_803F2AD0->unk6);
//     func_8033AC68_74C318(&D_803F2AD0->unk8, &D_803F2AD0->unkC, &D_803F2AD0->unk10, &D_803F2AD0->unk6C, D_803F2AD0->unk6 + 31);
//     D_803F2AD0->unk8C = 0.0f;
//     D_803F2AD0->unk90 = 0.0f;
//     D_803F2AD0->unk94 = 1.0f;
//     temp_f14 = D_803F2AD0->unk8 - D_803F2AD0->unk74;
//     temp_f0 = D_803F2AD0->unkC - D_803F2AD0->unk78;
//     if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
//         phi_f2 = 0.0f;
//     } else {
//         phi_f2 = func_801286B8(-temp_f0, temp_f14);
//     }
//     D_803F2AD0->unk24 = phi_f2;
//     D_803F2AD0->unk20 = phi_f2;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033AC68_74C318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B118_74C7C8.s")
// void func_8033B118_74C7C8(u8 arg0) {
//     f32 sp30;
//     f32 temp_f16;
//     f32 temp_f22;
//     f32 temp_f2;
//     f64 temp_f0;
//     f64 temp_f20;
//     u16 temp_t5;
//     void *temp_t9;
//     void *temp_v0;
//     void *temp_v0_2;
//     void *temp_v0_3;
//     void *temp_v0_4;
//     void *temp_v1;
//     f32 phi_f2;
//     f32 phi_f16;
//
//     // temp_t9 = ((arg0 & 0xFF) * 0xDC) + &D_803F28E0;
//     D_803F2AD0 = &D_803F28E0[arg0];
//     D_803F2AD0->unk20 = (f32) (D_803F2AD0->unk20 + D_803A6CCC_7B837C);
//     // temp_v0 = D_803F2AD0;
//     temp_f2 = D_803F2AD0->unk20;
//     temp_f0 = (f64) temp_f2;
//     phi_f2 = temp_f2;
//     if (temp_f0 > 256.0) {
//         D_803F2AD0->unk20 = (f32) (temp_f0 - 256.0);
//         phi_f2 = D_803F2AD0->unk20;
//     }
//     temp_f20 = D_803BE550_7CFC00;
//     D_803F2AD0->unk24 = phi_f2;
//     D_803F2AD0->unk8 = (f32) ((f64) (f32) (D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos / 65536.0);
//     D_803F2AD0->unkC = (f32) ((f64) (f32) (D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos / 65536.0);
//     temp_v1 = (&D_801D9ED8 + (gCurrentAnimalIndex * 8))->unk3EB4;
//     temp_t5 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42; //temp_v1->unk42;
//     temp_f16 = (f32) temp_t5;
//     phi_f16 = temp_f16;
//     if ((s32) temp_t5 < 0) {
//         phi_f16 = temp_f16 + 4294967296.0f;
//     }
//     D_803F2AD0->unk10 = (f32) (((f64) phi_f16 * 0.5) + ((f64) (f32) temp_v1->unkC / 65536.0));
//     temp_f22 = ((f32) (&D_801D9ED8 + (gCurrentAnimalIndex * 8))->unk3EB0->unkD4 * D_803A6CC4_7B8374 * 75.0f) / D_803F2E30;
//     sp30 = cosf((f32) (((f64) D_803A6CC8_7B8378 * temp_f20) / D_803BE558_7CFC08), &D_801D9ED8, &gCurrentAnimalIndex);
//     // temp_v0_2 = D_803F2AD0;
//     D_803F2AD0->unk74 = (f32) (D_803F2AD0->unk8 - (sinf((f32) ((f64) D_803F2AD0->unk20 * temp_f20 * 0.00390625)) * (temp_f22 * sp30)));
//     sp30 = cosf((f32) (((f64) D_803A6CC8_7B8378 * temp_f20) / D_803BE560_7CFC10));
//     // temp_v0_3 = D_803F2AD0;
//     D_803F2AD0->unk78 = (f32) (D_803F2AD0->unkC - (cosf((f32) ((f64) D_803F2AD0->unk20 * temp_f20 * 0.00390625)) * (temp_f22 * sp30)));
//     // temp_v0_4 = D_803F2AD0;
//     D_803F2AD0->unk7C = (f32) ((sinf((f32) (((f64) D_803A6CC8_7B8378 * temp_f20) / D_803BE568_7CFC18)) * temp_f22) + D_803F2AD0->unk10);
//     D_803F2AD0->unk8C = 0.0f;
//     D_803F2AD0->unk90 = 0.0f;
//     D_803F2AD0->unk94 = 1.0f;
// }

void func_8033B440_74CAF0(u8 arg0) {
    f32 temp_f0;
    f32 temp_f14;
    f32 phi_f2;

    D_803F2AD0 = &D_803F28E0[arg0];
    D_803F2AD0->unk8 = D_803F2AB4;
    D_803F2AD0->unkC = D_803F2AB8;
    D_803F2AD0->unk10 = D_803F2ABC;
    D_803F2AD0->unk74 = D_803F2AA8;
    D_803F2AD0->unk78 = D_803F2AAC;
    D_803F2AD0->unk7C = D_803F2AB0;
    D_803F2AD0->unk8C = D_803A6CD0;
    D_803F2AD0->unk90 = D_803A6CD4;
    D_803F2AD0->unk94 = D_803A6CD8;
    temp_f14 = D_803F2AD0->unk8 - D_803F2AD0->unk74;
    temp_f0 = D_803F2AD0->unkC - D_803F2AD0->unk78;
    if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
        phi_f2 = 0.0f;
    } else {
        phi_f2 = func_801286B8(-temp_f0, temp_f14);
    }
    D_803F2AD0->unk24 = phi_f2;
    D_803F2AD0->unk20 = phi_f2;
}

// "ca_UpdateCamera_Watch_TV.\n"
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B594_74CC44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B9B8_74D068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C054_74D704.s")

void func_8033C320_74D9D0(u8 arg0) {
    D_803F2AC5 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C334_74D9E4.s")

void func_8033C814_74DEC4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C = sp3C + arg6;
    sp38 = sp38 + arg7;
    func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, sp34, 127, 1, arg8);
}

void func_8033C8EC_74DF9C(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C = sp3C + arg6;
    sp38 = sp38 + arg7;
    func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, (s16)sp34 + 34, 127, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C9CC_74E07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033D604_74ECB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033DF88_74F638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033E430_74FAE0.s")

void func_8033E6B8_74FD68(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 tmp0;
    f32 tmp1;
    f32 tmp2;

    tmp1 = arg1 * D_803BE5F8 * (256 / 65536.0);
    tmp0 = sinf(tmp1);
    tmp2 = arg0 * D_803BE600 * (256 / 65536.0);
    *arg3 = D_803F2AD0->unk8 - cosf(tmp2) * (arg2 * tmp0);
    tmp0 = cosf(tmp1);
    *arg4 = D_803F2AD0->unkC - cosf(tmp2) * (arg2 * tmp0);
    *arg5 = D_803F2AD0->unk10 + sinf(tmp2) * arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033E7C8_74FE78.s")

void func_8033EF94_750644(u16 *arg0, u16 arg1) {
    u8 res = 0;

    if (((*arg0 & 8) != 0) && ((arg1 & 8) == 0)) {
        if (D_803F2C6E < MIN(D_803F28E0[D_803F2A98].unk66, 0)) {
            D_803F2C6E = MIN(MIN(MAX(D_803F2C6E + 1, D_803F28E0[D_803F2A98].unk64 + 1), D_803F28E0[D_803F2A98].unk66), 0);
            D_803F28E0[D_803F2A98].unk64 = D_803F2C6E;
            res = 1;
        } else {
            res = 2;
        }
    }
    if (((*arg0 & 4) != 0) && ((arg1 & 4) == 0)) {
        if (D_803F2C6E > MAX(D_803F28E0[D_803F2A98].unk65, -2)) {
            D_803F2C6E = MAX(MAX(MIN(D_803F2C6E - 1, D_803F28E0[D_803F2A98].unk64 - 1), D_803F28E0[D_803F2A98].unk65), -2);
            D_803F28E0[D_803F2A98].unk64 = D_803F2C6E;
            res = 1;
        } else {
            res = 2;
        }
    }

    if (res == 2) {
        func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
    } else if (res == 1) {
        func_8032C508_73DBB8(SFX_CAMERA_PAN, 0x2A00, 0, 1.0f);
    }
}

void func_8033F23C_7508EC(s16 arg0) {
    if (D_803F28E0[D_803F2A98].unkD6 == 1) {
        D_803F2C6E -= arg0;
    }
}

void func_8033F294_750944(s16 arg0) {
    if (D_803F28E0[D_803F2A98].unkD6 == 1) {
        D_803F2C6E += arg0;
    }
}

void func_8033F2EC_75099C(void) {
    D_803F2C70 = D_803F2C6E;
}

void func_8033F300_7509B0(void) {
    D_803F2C70 = MIN(D_803F2C70, D_803F28E0[D_803F2A98].unk66);
    D_803F2C70 = MAX(D_803F2C70, D_803F28E0[D_803F2A98].unk65);
    D_803F2C6E = D_803F2C70;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033F380_750A30.s")

void func_80340E08_7524B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s8 arg5, s8 arg6, u8 arg7, s16 arg8) {
    memset_bytes((u8*)&D_803F2BF8, 0, 32);
    D_803F2BF8.unk12 = arg0;
    D_803F2BF8.unk14 = arg1;
    D_803F2BF8.unk15 = arg2;
    D_803F2BF8.unk16 = arg3;
    D_803F2BF8.unk17 = arg4;
    D_803F2BF8.unkA = arg8;
    D_803F2BF8.unk1A = arg6;
    D_803F2BF8.unk19 = arg5;
    D_803F2BF8.unk1B = arg7;
    D_803F2BF8.unk18 = 1;
    func_80340EA4_752554(&D_803F2BF8, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80340EA4_752554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803415BC_752C6C.s")

void func_803421E0_753890(s16 arg0) {
    if (D_803F2ACA < arg0) {
        D_803F2ACA = arg0;
    }
}

void func_8034220C_7538BC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 tmp = ((ABS(arg1 - (s16)D_803F2C44) +
                ABS(arg2 - (s16)D_803F2C48) +
                ABS(arg3 - (s16)D_803F2C4C)) >> 6);
    tmp -= 5;

    if (tmp > 0) {
        arg0 -= tmp >> 1;
    }
    if (arg0 > 0) {
        func_803421E0_753890(arg0);
    }
}

void func_80342318_7539C8(s32 arg0, s32 arg1, s32 arg2) {
    func_803423C4_753A74(0, arg0 / 65536.0, arg1 / 65536.0, arg2 / 65536.0);
    func_803423C4_753A74(1, arg0 / 65536.0, arg1 / 65536.0, arg2 / 65536.0);
}

void func_803423C4_753A74(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_803F28E0[arg0].unk8 = D_803F28E0[arg0].unk8 + arg1;
    D_803F28E0[arg0].unkC = D_803F28E0[arg0].unkC + arg2;
    D_803F28E0[arg0].unk10 = D_803F28E0[arg0].unk10 + arg3;
    D_803F28E0[arg0].unk74 = D_803F28E0[arg0].unk74 + arg1;
    D_803F28E0[arg0].unk78 = D_803F28E0[arg0].unk78 + arg2;
    D_803F28E0[arg0].unk7C = D_803F28E0[arg0].unk7C + arg3;
    D_803F28E0[arg0].unk5A = D_803F28E0[arg0].unk5A + arg1 * (1.0 / 64.0);
    D_803F28E0[arg0].unk5C = D_803F28E0[arg0].unk5C + arg2 * (1.0 / 64.0);
    D_803F28E0[arg0].unk5E = D_803F28E0[arg0].unk5E + arg3 * (1.0 / 64.0);
    D_803F28E0[arg0].unk98 = D_803F28E0[arg0].unk98 + arg1;
    D_803F28E0[arg0].unk9C = D_803F28E0[arg0].unk9C + arg2;
    D_803F28E0[arg0].unkA0 = D_803F28E0[arg0].unkA0 + arg3;
    D_803F28E0[arg0].unkD0 = D_803F28E0[arg0].unkD0 + arg1;
    D_803F28E0[arg0].unkD2 = D_803F28E0[arg0].unkD2 + arg2;
    D_803F28E0[arg0].unkD4 = D_803F28E0[arg0].unkD4 + arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80342550_753C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343438_754AE8.s")

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343720_754DD0.s")

void func_80343A50_755100(void) {
    if (D_803F2C1E > 0) {
        D_803F2C1E -= 1;
    } else if (((D_803F2C20 + 1) % 8) != D_803F2C22) {
        D_803F2C20 = (D_803F2C20 + 1) % 8;
        D_803F2C1E = D_803F2AF8[D_803F2C20].unkA + D_803F2AF8[D_803F2C20].unk8;
    } else {
        D_803F2AC6 = 1;
    }
}

void func_80343AE0_755190(u8 arg0, s16 arg1, s16 arg2, struct071 *arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, s16 argA, u8 argB, s8 argC, s8 argD, u8 argE) {
    s32 pad;
    D_803F2AA4 = D_803F2AA5 = 0;

    if (arg1 == 0x7FFF) {
        arg1 = 0;
    }
    if (D_803F2C22 != D_803F2C20) {
        switch (arg0) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            memset_bytes(&D_803F2AF8[D_803F2C22], 0, 32);
            D_803F2AF8[D_803F2C22].unk18 = arg0;
            D_803F2AF8[D_803F2C22].unk8 = arg1;
            D_803F2AF8[D_803F2C22].unkA = arg2;
            D_803F2AF8[D_803F2C22].unk0 = arg3;
            D_803F2AF8[D_803F2C22].unkC = arg4;
            D_803F2AF8[D_803F2C22].unkE = arg5;
            D_803F2AF8[D_803F2C22].unk10 = arg6;
            D_803F2AF8[D_803F2C22].unk14 = arg7;
            D_803F2AF8[D_803F2C22].unk15 = arg8;
            D_803F2AF8[D_803F2C22].unk16 = arg9;
            D_803F2AF8[D_803F2C22].unk12 = argA;
            D_803F2AF8[D_803F2C22].unk17 = argB;
            D_803F2AF8[D_803F2C22].unk19 = argC;
            D_803F2AF8[D_803F2C22].unk1A = argD;
            D_803F2AF8[D_803F2C22].unk1B = argE;
            D_803F2C22 = (D_803F2C22 + 1) % 8;
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343C44_7552F4.s")
// JUSTREG: perhaps not quite this?
// void func_80343C44_7552F4(s16 arg0, s16 *arg1, s16 *arg2) {
//     *arg1 = D_803A7B3C[arg0][0];
//     *arg2 = D_803A7B3C[arg0][1];
// }

void func_80343C74_755324(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4) {
    memset_bytes((u8*)&D_803F2AD8, 0, sizeof(D_803F2AD8));
    D_803F2AD8.unk18 = 1;
    D_803F2AD8.unkA = 40;
    D_803F2AD8.unk12 = arg0;
    D_803F2AD8.unk17 = arg1;
    D_803F2AD8.unk19 = arg2;
    D_803F2AD8.unk1A = arg3;
    D_803F2AD8.unk1B = arg4;
    if (((D_803F2C20 + 1) % 8) == D_803F2C22) {
        if ((D_803F2AF8[D_803F2C20].unk18 != 1) && (D_803F2AF8[D_803F2C20].unk18 != 0)) {
            D_803F2AF8[D_803F2C20].unkA = 40;
        }
    }
}

void func_80343D44_7553F4(struct071 *arg0, s8 arg1) {
    // FIXME: arg0->unk0 ?
    func_80343AE0_755190(5, ((*(u8*)arg0) * 32) - 136, 40, arg0, 0, 0, 0, 0, 0, 0, 44, arg1, -2, 0, 1);
}

void func_80343DC0_755470(void) {
    D_803F2C20 = 0;
    D_803F2C22 = 1;
    memset_bytes((u8*)&D_803F2AF8, 0, 32);
    D_803F2C1E = 0;
    D_803F2C18[0] = 0;
    D_803F2C18[1] = 0;
    D_803F2C18[2] = 0;

    D_803F28E0[D_803F2A98].unk0 = 27;
    D_803F28E0[D_803F2A98].unk2 = 0;
    D_803F28E0[D_803F2A98].unkD6 = 4;
    D_803F28E0[D_803F2A98].unk74 = D_803F2C44 - D_803F28E0[D_803F2A98].unkA4;
    D_803F28E0[D_803F2A98].unk78 = D_803F2C48 - D_803F28E0[D_803F2A98].unkA8;
    D_803F28E0[D_803F2A98].unk7C = D_803F2C4C;
    D_803F28E0[D_803F2A98].unk8 = D_803F2C50 - D_803F28E0[D_803F2A98].unkA4;
    D_803F28E0[D_803F2A98].unkC = D_803F2C54 - D_803F28E0[D_803F2A98].unkA8;
    D_803F28E0[D_803F2A98].unk10 = D_803F2C58;
    D_803F28E0[D_803F2A98].unk8C = D_80204200;
    D_803F28E0[D_803F2A98].unk90 = D_80204204;
    D_803F28E0[D_803F2A98].unk94 = D_80204208;

    D_803F2AF8[D_803F2C20].unk12 = D_803F28E0[D_803F2A98].unk2;
    D_803F2AF8[D_803F2C20].unk17 = D_803F28E0[D_803F2A98].unkC9;
    D_803F2AF8[D_803F2C20].unk18 = D_803F28E0[D_803F2A98].unkD6;
    D_803F2AF8[D_803F2C20].unk0 = D_803F28E0[D_803F2A98].unkCC;
    D_803F2AF8[D_803F2C20].unkC = D_803F28E0[D_803F2A98].unkD0;
    D_803F2AF8[D_803F2C20].unkE = D_803F28E0[D_803F2A98].unkD2;
    D_803F2AF8[D_803F2C20].unk10 = D_803F28E0[D_803F2A98].unkD4;
    D_803F2AF8[D_803F2C20].unk14 = D_803F28E0[D_803F2A98].unk5A;
    D_803F2AF8[D_803F2C20].unk15 = D_803F28E0[D_803F2A98].unk5C;
    D_803F2AF8[D_803F2C20].unk16 = D_803F28E0[D_803F2A98].unk5E;
    D_803F2AF8[D_803F2C20].unk19 = D_803F28E0[D_803F2A98].unk65;
    D_803F2AF8[D_803F2C20].unk1A = D_803F28E0[D_803F2A98].unk66;
    D_803F2AF8[D_803F2C20].unk1B = D_803F28E0[D_803F2A98].unk67;
}

void func_80343F58_755608(s16 arg0) {
    D_803F2C6E = arg0;
}

void func_80343F68_755618(void) {
    D_803F2AA7 = 1;
}

void func_80343F78_755628(void) {
    if (D_803F2AA7 != 0) {
        D_803F2AA7 = 0;
        if ((D_803F2C18[0] != 0) && (D_803F28E0[D_803F2A98].unk0 == 30)) {
            D_803F2C18[1] = D_803F2C18[2] - D_803F2C18[1];
            D_803F2A98 = (D_803F2A98 + 1) & 1;
            D_803F2AC8 = (D_803F2AC8 + 1) & 1;
            D_803A6CEC = -1;
        }
    }
}

void func_8034401C_7556CC(void) {
    s16 i, j;

    for (i = 1; i < 128; i++) {
        for (j = 0; j < i; j++) {
            if ((D_803A7114_7B87C4[i].unk0 == D_803A7114_7B87C4[j].unk0) &&
                (D_803A7114_7B87C4[i].unk1 == D_803A7114_7B87C4[j].unk1) &&
                (D_803A7114_7B87C4[i].unk2 == D_803A7114_7B87C4[j].unk2) &&
                (D_803A7114_7B87C4[i].unk4 == D_803A7114_7B87C4[j].unk4) &&
                (D_803A7114_7B87C4[i].unk6 == D_803A7114_7B87C4[j].unk6) &&
                (D_803A7114_7B87C4[i].unk8 == D_803A7114_7B87C4[j].unk8) &&
                (D_803A7114_7B87C4[i].unkA == D_803A7114_7B87C4[j].unkA) &&
                (D_803A7114_7B87C4[i].unkC == D_803A7114_7B87C4[j].unkC) &&
                (D_803A7114_7B87C4[i].unkE == D_803A7114_7B87C4[j].unkE) &&
                (D_803A7114_7B87C4[i].unk10 == D_803A7114_7B87C4[j].unk10) &&
                (D_803A7114_7B87C4[i].unk12 == D_803A7114_7B87C4[j].unk12)) {
                // break loop
                D_803A6D14_7B83C4[i].unk7 = D_803A6D14_7B83C4[j].unk7;
                j = (u16)0x80;
            }
        }
    }
}

s32 func_80344158_755808(s16 arg0) {
    switch (arg0) {
    case 3:
    case 5:
    case 6:
    case 7:
    case 17:
    case 28:
        return 1;
    default:
        return 0;
    }
}

void func_8034419C_75584C(struct071 *arg0) {
    func_80343AE0_755190(4, 0, 30, arg0, 0, 0, 0, 0, 0, 0, 228, 1, 0, 0, 0);
}

void func_803441FC_7558AC(void) {
    if (D_803F2C18[0] != 0) {
        if ((D_803F2C18[0] == 1) || (D_803F2C18[0] == 2)) {
            D_803F2C18[0] = 0;
            D_803F2C18[1] = 0;
        }
    }
}
