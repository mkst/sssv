#include <ultra64.h>
#include "common.h"

void func_8032FD0C_7413BC(u8 cameraID, u8 arg1);
void func_8032FF94_741644(u8);
void func_80332444_743AF4(u8);
void func_80334470_745B20(u8, u8);
void func_8033641C_747ACC(u8, u8, u8);
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
void func_80342550_753C00(Camera *camera);

// .data
extern f32 D_803A6CC4_7B8374; // 1.0f
extern f32 D_803A6CC8_7B8378; // 45.0f
extern f32 D_803A6CCC_7B837C; // 1.0f
// .rodata
extern f64 D_803BE550_7CFC00; // 6.2832
extern f64 D_803BE558_7CFC08; // 360.0
extern f64 D_803BE560_7CFC10; // 360.0
extern f64 D_803BE568_7CFC18; // 360.0

// BSS starts at 0x803C0420
//  0x803F2C18 - 0x803C0420 => 0x327f8

s16  D_803F2C18[3]; // BSS
// static u16 D_803F2C72;

void func_8032F950_741000(void) {
    s16 i;
    s16 phi_v0_2;

    D_803F2AC5 = 0;

    if (D_803F28E0[D_803F2A98].unkD6 != 1) {
        D_803F2ACC = 20;
    } else if (((D_801D9ED8.animals[gCurrentAnimalIndex].animal->xVelocity.w != 0) ||
                (D_801D9ED8.animals[gCurrentAnimalIndex].animal->zVelocity.w != 0)) ||
            (ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->yVelocity.h) > 1)) {
        D_803F2ACC = 20;
    } else if (D_803F2ACC > 0) {
        D_803F2ACC--;
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
        if ((func_80344158_755808(D_803F28E0[D_803F2A98].cameraMode) == 0) &&
            (func_80344158_755808(D_803F28E0[D_803F2AC8].cameraMode) != 0)) {
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
                    if (D_803F28E0[D_803F2A98].cameraMode != 23) {
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

#if 0
// TODO: doublecheck rodata
void func_8032FD0C_7413BC(u8 cameraID, u8 arg1) {

    func_80342550_753C00(&D_803F28E0[cameraID]);

    switch (D_803F28E0[cameraID].cameraMode) {
    case 1:
        func_80332444_743AF4(cameraID);
        break;
    case 26:
        func_8032FF94_741644(cameraID);
        break;
    case 2:
    case 12:
        func_803378BC_748F6C(cameraID);
        break;
    case 3:     // behind animal (Z mode?)
    case 17:
        func_80337ECC_74957C(cameraID);
        break;
    case 4:     // overhead, GTA style 1
        func_80338E1C_74A4CC(cameraID);
        break;
    case 19:    // overhead, GTA style 3
        func_803391D0_74A880(cameraID);
        break;
    case 20:    // overhead, GTA style 4
        func_80339238_74A8E8(cameraID);
        break;
    case 21:    // overhead, GTA style 5
        func_803392A0_74A950(cameraID);
        break;
    case 5:     // overheda GTA style 2
        func_803394E4_74AB94(cameraID, arg1);
        break;
    case 6:
        func_80334470_745B20(cameraID, arg1);
        break;
    case 7:     // like 6 but a little higher
        func_8033641C_747ACC(cameraID, 0, arg1);
        break;
    case 13:
        func_80339B84_74B234(cameraID, 0.0f);
        break;
    case 14:
        func_80339B84_74B234(cameraID, 128.0f);
        break;
    case 15:
        func_80339B84_74B234(cameraID, 64.0f);
        break;
    case 16:
        func_80339B84_74B234(cameraID, 192.0f);
        break;
    case 8:     // looking behind player, SE-ish
        func_80339B84_74B234(cameraID, 32.0f);
        break;
    case 9:     // fixed, looking left
        func_80339B84_74B234(cameraID, 96.0f);
        break;
    case 10:
        func_80339B84_74B234(cameraID, 160.0f);
        break;
    case 11:    // fixed, looking right
        func_80339B84_74B234(cameraID, 224.0f);
        break;
    case 22:
        func_80339308_74A9B8(cameraID);
        break;
    case 23:    // seem to crash game?
    case 24:
        func_8033AAC8_74C178(cameraID);
        break;
    case 25:    // zoomed in, spin around player
        func_8033B118_74C7C8(cameraID);
        break;
    case 30:    // seems to crash game?
        func_8033B440_74CAF0(cameraID);
        break;
    case 27:
        func_8033C320_74D9D0(cameraID);
        break;
    case 28:
        func_8033641C_747ACC(cameraID, 1, arg1);
        break;
    case 29:    // seems to crash game?
        func_8033B594_74CC44(cameraID);
        break;
    case 18:    // spinning around player
    case 31:
        func_8033B9B8_74D068(cameraID);
        break;
    case 228:
        func_8033C054_74D704(cameraID);
        break;
    case 0:
    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032FD0C_7413BC.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032FF94_741644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80332444_743AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80334470_745B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033641C_747ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803378BC_748F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80337ECC_74957C.s")

#if 0
// needs rodata to match
void func_80338E1C_74A4CC(u8 cameraID) {
    s32 one = 1; // ehhhh....
    s32 phi_a0;
    s32 phi_v1;
    f32 phi_f0;
    f32 temp;

    gCamera = &D_803F28E0[cameraID];

    if (gCamera->unkD6 == 1) {
        gCamera->unk50 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkC8;
        gCamera->unk4E = D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkCA;
    } else {
        // defaults
        gCamera->unk50 = 400;
        gCamera->unk4E = 32;
    }
    if (gCamera->unk64 < 0) {
        gCamera->unk34 = gCamera->unk50 + ((gCamera->unk64 * gCamera->unk50) / 4);
    } else {
        gCamera->unk34 = gCamera->unk50 + ((gCamera->unk64 * gCamera->unk50) / 2);
    }

    phi_f0 = (gCamera->unk34 - gCamera->unk30) * 0.18; // D_803BE4D0_7CFB80

    if (!(ABSF(phi_f0) > ABSF(gCamera->unk38))) {
        if (phi_f0 < 0.0f) {
            phi_v1 = -1;
        } else {
            phi_v1 = 1;
        }

        if (gCamera->unk38 < 0.0f) {
            phi_a0 = -1;
        } else {
            phi_a0 = 1;
        }

        if (phi_a0 != phi_v1) {
            goto block_18;
        }
    } else {
block_18:
        if (phi_f0 > 0.0f) {
            phi_f0 = MIN(phi_f0, gCamera->unk38 + 4.0);
        } else {
            phi_f0 = MAX(phi_f0, gCamera->unk38 - 4.0);
        }
    }

    gCamera->unk38 = phi_f0;
    temp = gCamera->unk30;
    gCamera->unk30 += phi_f0;

    gCamera->unkA4 = gCamera->unkA4 * (gCamera->unk30 / temp);
    gCamera->unkA8 = gCamera->unkA8 * (gCamera->unk30 / temp);

    gCamera->unkBC = gCamera->unkBC * (gCamera->unk30 / temp);
    gCamera->unkC0 = gCamera->unkC0 * (gCamera->unk30 / temp);

    gCamera->unk20 = 0.0f;
    gCamera->unk24 = 0.0f;

    if (gCamera->unk30 < 1.0) {
        gCamera->unk30 = 1.0f;
    }

    gCamera->unk8 = gCamera->unk98;
    gCamera->unkC = gCamera->unk9C;
    gCamera->unk10 = gCamera->unkA0 + 4.0;

    gCamera->unk74 = gCamera->unk8;
    gCamera->unk78 = gCamera->unkC;
    gCamera->unk7C = gCamera->unk10 + gCamera->unk30;

    gCamera->unk8C = 0.0f;
    gCamera->unk90 = 1.0f;
    gCamera->unk94 = 0.0f;

    if (D_803F2AA6 != 0) {
        gCamera->unk30 = gCamera->unk34;
        gCamera->unk38 = 0.0f;
    }
    D_803F2AC5 = one;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80338E1C_74A4CC.s")
#endif

void func_803391D0_74A880(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    gCamera->unk8C = 0.0f;
    gCamera->unk90 = -1.0f;
    gCamera->unk20 = gCamera->unk24 = 128.0f;
}

void func_80339238_74A8E8(u8 cameraID) {
    func_80338E1C_74A4CC(cameraID);
    gCamera->unk8C = 1.0f;
    gCamera->unk90 = 0.0f;
    gCamera->unk20 = gCamera->unk24 = 64.0f;
}

void func_803392A0_74A950(u8 cameraID) {
    func_80338E1C_74A4CC(cameraID);
    gCamera->unk8C = -1.0f;
    gCamera->unk90 = 0.0f;
    gCamera->unk20 = gCamera->unk24 = 192.0f;
}

void func_80339308_74A9B8(u8 cameraID) {
    f32 tmp;

    gCamera = &D_803F28E0[cameraID];
    tmp = gCamera->unk20;
    func_80338E1C_74A4CC(cameraID);
    if ((tmp > 32.0) && (tmp <= 96.0)) {
        gCamera->unk20 = 64.0f;
        gCamera->unk8C = 1.0f;
        gCamera->unk90 = 0.0f;
    } else if ((tmp > 96.0) && (tmp <= 160.0)) {
        gCamera->unk20 = 128.0f;
        gCamera->unk8C = 0.0f;
        gCamera->unk90 = -1.0f;
    } else if ((tmp > 160.0) && (tmp <= 224.0)) {
        gCamera->unk20 = 192.0f;
        gCamera->unk8C = -1.0f;
        gCamera->unk90 = 0.0f;
    } else {
        gCamera->unk20 = 0.0f;
        gCamera->unk8C = 0.0f;
        gCamera->unk90 = 1.0f;
    }
    gCamera->unk24 = gCamera->unk20;
    D_803F2AC5 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803394E4_74AB94.s")

// fix camera to angle offset
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80339B84_74B234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033AAC8_74C178.s")
// 80% of the way there...
// void func_8033AAC8_74C178(u8 cameraID) {
//     u8 **new_var;
//     f32 temp_f0;
//     f32 temp_f14;
//     f32 phi_f2;
//     s32 temp_a2;
//     u8 temp_a3;
//
//     gCamera = &D_803F28E0[cameraID];
//     temp_a3 = *gCamera->unk6C;
//     temp_a2 = temp_a3 << 5;
//     if (gCamera->unk6 < (temp_a2 - 65)) {
//         gCamera->unk6 += 1;
//     } else {
//         D_803F2AC5 = 1;
//     }
//     new_var = &gCamera->unk6C;
//     if (temp_a2 == (gCamera->unk6 + 104)) {
//         D_803F2C6C = 0;
//         D_803F2C6D = 0;
//         gCamera->cameraMode = 24;
//     }
//     func_8033AC68_74C318(&gCamera->unk74, &gCamera->unk78, &gCamera->unk7C, new_var, gCamera->unk6);
//     func_8033AC68_74C318(&gCamera->unk8, &gCamera->unkC, &gCamera->unk10, new_var, gCamera->unk6 + 31);
//
//     gCamera->unk8C = 0.0f;
//     gCamera->unk90 = 0.0f;
//     gCamera->unk94 = 1.0f;
//
//     temp_f14 = gCamera->unk8 - gCamera->unk74;
//     temp_f0 = gCamera->unkC - gCamera->unk78;
//     if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
//         phi_f2 = 0.0f;
//     } else {
//         phi_f2 = func_801286B8(-temp_f0, temp_f14);
//     }
//     gCamera->unk24 = phi_f2;
//     gCamera->unk20 = phi_f2;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033AC68_74C318.s")
// pure nonsense
// void func_8033AC68_74C318(f32 *arg0, f32 *arg1, f32 *arg2, u8 *arg3, s16 arg4) {
//     s16 sp4E;
//     s16 sp4C;
//     s16 sp4A;
//     s16 sp48;
//     f32 sp20;
//     f32 sp1C;
//     f32 sp18;
//     f32 spC;
//     f32 sp4;
//     f32 sp0;
//     f32 temp_f10;
//     f32 temp_f10_2;
//     f32 temp_f10_3;
//     f32 temp_f10_4;
//     f32 temp_f18;
//     f32 temp_f4;
//     f32 temp_f4_2;
//     f32 temp_f4_3;
//     f32 temp_f4_4;
//     f32 temp_f4_5;
//     f32 temp_f6;
//     f32 temp_f6_2;
//     f32 temp_f8;
//     f32 temp_f8_2;
//     f32 temp_f8_3;
//     f32 temp_f8_4;
//     f32 temp_f8_5;
//     f64 temp_f0;
//     f64 temp_f12;
//     f64 temp_f14;
//     f64 temp_f16;
//     s32 temp_t0;
//     s32 temp_t0_2;
//     s32 temp_t7;
//     s32 temp_v1;
//     s32 temp_v1_2;
//     s32 temp_v1_3;
//     u8 temp_t1;
//     u8 temp_t2;
//     u8 temp_t3;
//     u8 temp_t4;
//     u8 temp_t5;
//     u8 temp_t6;
//     u8 temp_t7_2;
//     u8 temp_t7_3;
//     u8 temp_t8;
//     u8 temp_t9;
//     f32 phi_f4;
//     f32 phi_f8;
//     f32 phi_f6;
//     f32 phi_f8_2;
//     f32 phi_f8_3;
//     f32 phi_f10;
//     f32 phi_f4_2;
//     f32 phi_f10_2;
//     f32 phi_f10_3;
//     f32 phi_f8_4;
//
//     temp_t7 = (s32) arg4 / 32;
//
//     sp48 = MAX(0, temp_t7 - 1);
//     sp4A = (s16) temp_t7;
//     sp4C = MIN(*arg3 - 1, temp_t7 + 1);
//     sp4E = MIN(*arg3 - 1, temp_t7 + 2);
//
//     temp_f18 = (f32) (s16) (arg4 - ((s16) temp_t7 << 5)) / 32.0f;
//     sp1C = temp_f18 * temp_f18;
//     temp_f12 = (f64) sp1C;
//     sp18 = temp_f18 * sp1C;
//     temp_f0 = (f64) sp18;
//     temp_f10 = (f32) (temp_f0 / 6.0);
//     spC = temp_f10;
//     temp_f14 = 3.0 * temp_f12;
//     temp_f16 = 3.0 * (f64) temp_f18;
//     temp_f4 = (f32) (((((f64) -sp18 + temp_f14) - temp_f16) + 1.0) / 6.0);
//     sp20 = temp_f4;
//     temp_f6 = (f32) ((((temp_f0 * 3.0) - (6.0 * temp_f12)) + 4.0) / 6.0);
//     sp1C = temp_f6;
//     temp_f8 = (f32) (((temp_f0 * -3.0) + temp_f14 + temp_f16 + 1.0) / 6.0);
//     temp_f4_2 = temp_f4;
//     sp18 = temp_f8;
//     sp0 = temp_f10;
//     sp4 = temp_f6;
//     // temp_f4_3 = sp4;
//     sp4 = temp_f8;
//
//     *arg0 = ((sp0 * arg3[sp4E*3 + 1]) +
//              (sp20 * arg3[sp48*3 + 1]) +
//              (sp1C * arg3[sp4A*3 + 1]) +
//              (sp4 * arg3[sp4C*3 + 1])
//             ) * 64.0f;
//
//     *arg1 = ((spC * arg3[sp4E*3 + 2]) +
//              (sp20 * arg3[sp48*3 + 2]) + // +1 ?
//              (sp1C * arg3[sp4A*3 + 2]) +
//              (sp18 * arg3[sp4C*3 + 2])
//             ) * 64.0f;
//
//     *arg2 = ((spC * arg3[sp4E*3 + 3]) +
//              (sp20 * arg3[sp48*3 + 3]) +
//              (sp1C * arg3[sp4A*3 + 3]) +
//              (sp18 * arg3[sp4C*3 + 3])
//             ) * 64.0f;
// }

#if 0
// needs rodata
void func_8033B118_74C7C8(u8 cameraID) {
    f32 phi_f2;
    f32 sp30;
    f32 temp_f22;

    gCamera = &D_803F28E0[cameraID];
    gCamera->unk20 += D_803A6CCC_7B837C;

    if (gCamera->unk20 > 256.0) {
        gCamera->unk20 -= 256.0;
    }
    gCamera->unk24 = gCamera->unk20;

    gCamera->unk8 = (f64) (f32) *(s32*)&D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h / 65536.0;
    gCamera->unkC = (f64) (f32) *(s32*)&D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h / 65536.0;
    gCamera->unk10 = ((f64) (f32) *(s32*)&D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h / 65536.0) + ((f64) (f32)D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 0.5);

    // temp_f20 = 6.2832; // D_803BE550_7CFC00
    temp_f22 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkD4;
    temp_f22 = temp_f22 * D_803A6CC4_7B8374;
    temp_f22 = (temp_f22 * 75.0f) / D_803F2D50.unkE0;
    sp30 = cosf((D_803A6CC8_7B8378 * 6.2832) / 360.0); // D_803BE558_7CFC08
    gCamera->unk74 = (gCamera->unk8 - (sinf((gCamera->unk20 * 6.2832 * 0.00390625)) * (temp_f22 * sp30)));
    sp30 = cosf((D_803A6CC8_7B8378 * 6.2832) / 360.0); // D_803BE560_7CFC10
    gCamera->unk78 = (gCamera->unkC - (cosf((gCamera->unk20 * 6.2832 * 0.00390625)) * (temp_f22 * sp30)));
    gCamera->unk7C = ((sinf(((D_803A6CC8_7B8378 * 6.2832) / 360.0)) * temp_f22) + gCamera->unk10); // D_803BE568_7CFC18

    gCamera->unk8C = 0.0f;
    gCamera->unk90 = 0.0f;
    gCamera->unk94 = 1.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B118_74C7C8.s")
#endif

void func_8033B440_74CAF0(u8 cameraID) {
    f32 temp_f0;
    f32 temp_f14;
    f32 phi_f2;

    gCamera = &D_803F28E0[cameraID];
    gCamera->unk8 = D_803F2AB4;
    gCamera->unkC = D_803F2AB8;
    gCamera->unk10 = D_803F2ABC;

    gCamera->unk74 = D_803F2AA8;
    gCamera->unk78 = D_803F2AAC;
    gCamera->unk7C = D_803F2AB0;

    gCamera->unk8C = D_803A6CD0;
    gCamera->unk90 = D_803A6CD4;
    gCamera->unk94 = D_803A6CD8;
    temp_f14 = gCamera->unk8 - gCamera->unk74;
    temp_f0 = gCamera->unkC - gCamera->unk78;
    if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
        phi_f2 = 0.0f;
    } else {
        phi_f2 = func_801286B8(-temp_f0, temp_f14);
    }
    gCamera->unk24 = phi_f2;
    gCamera->unk20 = phi_f2;
}

#if 0
// rodata
void func_8033B594_74CC44(u8 arg0) {
    f32 phi_f14;
    f32 phi_f20;
    f32 sp2C;

    rmonPrintf("ca_UpdateCamera_Watch_TV.\n"); //&D_803BE1B0_7CF860);
    gCamera = &D_803F28E0[arg0];
    D_803F6468 += 1;

    if ((D_803F2AA2 == 1) || (D_803F2AA2 == 4)) {
        phi_f20 = MAX(22.0f, 200.0 - (D_803F6468 * 1.95));

        if ((D_803F6468 * 0.5) > 30.0) {
            // wtf is this?
            phi_f14 = ((D_803F6468 * 0.5) > 30.0) * 0.0;
            // phi_f14 = 0;
        } else {
            phi_f14 = 30.0 - (D_803F6468 * 0.5);
        }

        phi_f20 = ((f32)D_803F6464->unk40 * phi_f20) / 4915.2; // D_803BE578_7CFC28
    } else {
        // temp_f0 = D_803F6468;
        phi_f20 = (f32) ((2.0 * D_803F6468) + 22.0f);
        phi_f20 = ((f32)D_803F6464->unk40 * phi_f20) / 4915.2; // D_803BE580_7CFC30
        phi_f14 = (D_803F6468 * 0.7); // D_803BE588_7CFC38
    }
    gCamera->unk30 = phi_f20;
    gCamera->unk34 = phi_f20;
    gCamera->unk14 = phi_f14;
    gCamera->unk18 = phi_f14;
    gCamera->unk20 = ((((s32) (D_803F6464->yRotation * 256) / 360) + 128) & 0xFF);
    gCamera->unk24 = gCamera->unk20;

    gCamera->unk8 = (f64) (f32) *(s32*)&D_803F6464->xPos.h / 65536.0;
    gCamera->unkC = (f64) (f32) *(s32*)&D_803F6464->zPos.h / 65536.0;
    gCamera->unk10 = ((f64) (f32) *(s32*)&D_803F6464->yPos.h / 65536.0) + ((f32)D_803F6464->unk42 * 0.73); // D_803BE590_7CFC40
    // temp_f12 = ((phi_f14 * 6.2832) / 360.0); //D_803BE598_7CFC48,  D_803BE5A0_7CFC50
    sp2C = cosf(((phi_f14 * 6.2832) / 360.0));
    gCamera->unk74 = (gCamera->unk8 - (sinf((gCamera->unk20 * 6.2832 * 0.00390625)) * (phi_f20 * sp2C))); // D_803BE5A8_7CFC58
    sp2C = cosf(((phi_f14 * 6.2832) / 360.0));
    gCamera->unk78 = (gCamera->unkC - (cosf((gCamera->unk20 * 6.2832 * 0.00390625)) * (phi_f20 * sp2C))); // D_803BE5B0_7CFC60
    gCamera->unk7C = ((sinf(((phi_f14 * 6.2832) / 360.0)) * phi_f20) + gCamera->unk10);
    gCamera->unk8C = 0.0f;
    gCamera->unk90 = 0.0f;
    gCamera->unk94 = 1.0f;
    gCamera->unkA8 = 0.0f;
    gCamera->unkA4 = gCamera->unkA8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B594_74CC44.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B9B8_74D068.s")
// void func_8033B9B8_74D068(u8 arg0) {
//     f32 sp6C;
//     f32 sp68;
//     f32 sp64;
//     f32 sp60;
//     f32 sp5C;
//     f32 sp58;
//     f32 sp2C;
//     f32 sp28;
//     f32 sp24;
//     f32 temp_f0_5;
//     f32 tmp;
//
//     f32 phi_f14_2;
//     f32 phi_f16_2;
//
//     gCamera = &D_803F28E0[arg0]; //temp_t9;
//
//     gCamera->unk6 += 1; //(s16) (gCamera->unk6 + 1);
//     gCamera->unk24 += MIN(1.7, (gCamera->unk6 / 100.0) + 0.5);
//     gCamera->unk20 = gCamera->unk24;
//
//     if (gCamera->unk18 < 42.0) {
//         gCamera->unk18 += 0.1; // D_803BE5C0_7CFC70
//         gCamera->unk14 = gCamera->unk18;
//     }
//     if (gCamera->cameraMode == 31) {
//         if (gCamera->unk34 < 1000.0) { // D_803BE5D0_7CFC80
//             gCamera->unk34 += 2.0;
//             gCamera->unk30 = gCamera->unk34;
//         }
//     }
//
//     sp6C = gCamera->unk98;
//     sp68 = gCamera->unk9C;
//     sp64 = gCamera->unkA0 + 4.0;
//
//     // wtf is this junk?
//     if ((ABSF(sp6C - gCamera->unk98) <= 10.0f) &&
//         (ABSF(sp68 - gCamera->unk9C) <= 10.0f) &&
//         (ABSF(sp64 - gCamera->unkA0) <= 10.0f)) {
//         D_803F2AC5 = 1;
//     }
//     // temp_f0_4 = 0.95f; //D_803BE5D8_7CFC88;
//     // temp_f12_2 = 0.1; //D_803BE5E0_7CFC90;
//     sp60 = (0.95f * sp6C) - (0.95f * gCamera->unk8);
//     sp5C = (0.95f * sp68) - (0.95f * gCamera->unkC);
//     sp58 = (0.95f * sp64) - (0.95f * gCamera->unk10);
//
//     if (ABSF(sp60) < 0.1) {
//         sp60 = 0.0f;
//     }
//     if (ABSF(sp5C) < 0.1) {
//         sp5C = 0.0f;
//     }
//     if (ABSF(sp58) < 0.1) {
//         sp58 = 0.0f;
//     }
//
//     if (ABSF(sp60) < ABSF(gCamera->unk80)) {
//         sp2C = 0.0f;
//     } else {
//         sp2C = sp60 - gCamera->unk80;
//     }
//
//     if (ABSF(sp5C) < ABSF(gCamera->unk84)) {
//         phi_f16_2 = 0.0f;
//     } else {
//         phi_f16_2 = sp5C - gCamera->unk84;
//     }
//
//     if (ABSF(sp58) < ABSF(gCamera->unk88)) {
//         phi_f14_2 = 0.0f;
//     } else {
//         phi_f14_2 = sp58 - gCamera->unk88;
//     }
//
//     temp_f0_5 = sqrtf((sp2C * sp2C) + (phi_f16_2 * phi_f16_2) + (phi_f14_2 * phi_f14_2)); //, phi_f14_2, &gCamera);
//     if ((temp_f0_5 > 0.0) && ((6.0f / temp_f0_5) < 1.0)) {
//         if (sp2C != 0.0) {
//             sp60 = gCamera->unk80 + ((sp2C * 6.0f) / temp_f0_5);
//         }
//         if (phi_f16_2 != 0.0) {
//             sp5C = gCamera->unk84 + ((phi_f16_2 * 6.0f) / temp_f0_5);
//         }
//         if (phi_f14_2 != 0.0) {
//             sp58 = gCamera->unk88 + ((phi_f14_2 * 6.0f) / temp_f0_5);
//         }
//         if (1) { }
//     }
//     gCamera->unk80 = sp60;
//     gCamera->unk84 = sp5C;
//     gCamera->unk88 = sp58;
//
//     gCamera->unk8 += sp60;
//     gCamera->unkC += sp5C;
//     gCamera->unk10 += sp58;
//
//     if (D_803F2AA6 != 0) {
//         gCamera->unk8 = sp6C;
//         gCamera->unkC = sp68;
//         gCamera->unk10 = sp64;
//         gCamera->unk80 = gCamera->unk84 = gCamera->unk88 = 0.0f;
//     }
//
//     func_8033E6B8_74FD68(gCamera->unk14, gCamera->unk20, gCamera->unk30,
//                          &gCamera->unk74, &gCamera->unk78, &gCamera->unk7C);
//
//     if (gCamera->unk52 != gCamera->unk58) {
//         if (gCamera->unk52 < gCamera->unk58) {
//             gCamera->unk52 += 1;
//         } else {
//             gCamera->unk52 -= 1;
//         }
//     }
//     gCamera->unk8C = 0.0f;
//     gCamera->unk90 = 0.0f;
//     gCamera->unk94 = 1.0f;
// }

#if 0
// needs rodata to OK
void func_8033C054_74D704(u8 arg0) {
    f32 temp_f20;

    f64 temp_f22;
    f64 temp_f2;

    temp_f2 = 0.7111111111111111;   // D_803BE5E8_7CFC98
    temp_f22 = 6.2832;              // D_803BE5F0_7CFCA0

    gCamera = &D_803F28E0[arg0];

    gCamera->unk74 = gCamera->unkCC->xPos.w / 65536.0;
    gCamera->unk78 = gCamera->unkCC->zPos.w / 65536.0;
    gCamera->unk7C = gCamera->unkCC->yPos.w / 65536.0;

    temp_f20 = gCamera->unkCC->unk2C * temp_f2;
    gCamera->unk20 = temp_f20;
    gCamera->unk24 = temp_f20;

    temp_f20 = gCamera->unkCC->unk2E * temp_f2;
    gCamera->unk14 = temp_f20;
    gCamera->unk18 = temp_f20;

    temp_f20 = sinf((gCamera->unk24 * temp_f22 * 0.00390625));
    gCamera->unk8 = ((cosf((gCamera->unk18 * temp_f22 * 0.00390625)) * temp_f20) * 256.0) + gCamera->unk74;
    temp_f20 = cosf((gCamera->unk24 * temp_f22 * 0.00390625));
    gCamera->unkC = ((cosf((gCamera->unk18 * temp_f22 * 0.00390625)) * temp_f20) * 256.0) + gCamera->unk78;
    gCamera->unk10 = (sinf((gCamera->unk18 * temp_f22 * 0.00390625)) * 256.0) + gCamera->unk7C;

    gCamera->unk8C = 0.0f;
    gCamera->unk90 = 0.0f;
    gCamera->unk94 = 1.0f;

    gCamera->unk98 = gCamera->unk8;
    gCamera->unk9C = gCamera->unkC;
    gCamera->unkA0 = gCamera->unk10;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C054_74D704.s")
#endif

void func_8033C320_74D9D0(u8 arg0) {
    D_803F2AC5 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C334_74D9E4.s")
#if 0
void func_8033C334_74D9E4(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    s16 temp_a0;
    s16 temp_s0;
    s32 temp_t8;
    s8 temp_v1_2;
    s8 temp_v1_3;
    u16 temp_t0;
    u8 temp_t2;

    s16 phi_s0;
    s16 i;

    memset_bytes((u8*)&D_803F28E0, 0, sizeof(D_803F28E0)); // zero out both camera structs
    memset_bytes((u8*)&D_803F2AD8, 0, sizeof(D_803F2AD8));
    memset_bytes((u8*)&D_803F2AF8, 0, sizeof(D_803F2AF8));
    memset_bytes((u8*)&D_803F2C18, 0, sizeof(D_803F2C18));

    D_803F2AF8[0].unkA = -1;
    D_803F2A98 = 0;
    D_803F2AC8 = 1;
    D_803F2ACA = 0;
    D_803F2A9A = 0xFF;
    D_803F2AA6 = 0;
    D_803A6CC4_7B8374 = 1.0f;
    D_803A6CC8_7B8378 = 45.0f;
    D_803A6CCC_7B837C = 1.0f;
    D_803F2AA2 = 0;
    D_803A6CE0_7B8390 = 0;
    D_803A6CE4_7B8394 = 0;
    D_803A6CE8_7B8398 = 0;
    gCamera = &D_803F28E0;
    D_803F2C20 = 0;
    D_803F2C22 = 1;
    D_803F2AF8[0].unk12 = 0;
    D_803F2AF8[0].unk17 = 1;
    D_803F2AF8[0].unk8 = 0;

    D_803F28E0[0].unkD6 = 1;
    D_803F28E0[1].unkD6 = 1;

    // temp_v0 = *(&D_801DDD8C + (gCurrentAnimalIndex * 8));
    func_80319F58_72B608(
        &D_803A6D14_7B83C4,
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6),
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6),
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h >> 6),
        D_803F2C38,
        &D_803F2C6C,
        &D_803F2C6D);
    // temp_v1 = ( * 0x14) + &D_803A7114_7B87C4[D_803F2C6D];
    D_803F28D0[0] = (u16) D_803A7114_7B87C4[D_803F2C6D].unk4;
    D_803F28D0[1] = (u16) D_803A7114_7B87C4[D_803F2C6D].unk6;
    D_803F28D0[4] = (u16) D_803A7114_7B87C4[D_803F2C6D].unkC;
    D_803F28D0[2] = (u16) D_803A7114_7B87C4[D_803F2C6D].unk8;
    D_803F28D0[5] = (u16) D_803A7114_7B87C4[D_803F2C6D].unkE;
    D_803F28D0[6] = (u16) D_803A7114_7B87C4[D_803F2C6D].unk10;
    D_803F28E0[0].unk65 = D_803A7114_7B87C4[D_803F2C6D].unk12.x.unk8; //(s8) ((s8) temp_t0 >> 4);
    D_803F28E0[0].unk66 = D_803A7114_7B87C4[D_803F2C6D].unk12.x.unk12; //(s8) ((s8) (temp_t0 << 4) >> 4);
    D_803F28D0[3] = (u16) D_803A7114_7B87C4[D_803F2C6D].unkA;
    temp_t8 = (s32) ((D_803F28E0[0].unk66 + D_803F28E0[0].unk65) - 1) >> 1;
    D_803F28E0[0].unk67 = D_803A7114_7B87C4[D_803F2C6D].unk12.x.unk7; // //(s8) (((s32) temp_t0 >> 8) & 1);
    D_803F28E0[0].unk64 = D_803F28E0[1].unk64 = (s8) temp_t8;
    // D_803F28E0[0].unk64 = (s8) temp_t8;
    temp_t0 = D_803A7114_7B87C4[D_803F2C6D].unk12.u;
    D_803F28D0[7] = temp_t0;
    // temp_t2 = D_803F2C6C;
    D_803F28E0[0].unk2 = (s16) D_803F2C6C;
    func_80343C44_7552F4((s16) D_803F2C6C, &D_803F28E0, &D_803F28E0[0].unk4);
    D_803F28E0[0].unk50 = 0xC8;
    D_803F28E0[0].unk62 = 0xA;
    D_803F28E0[0].unk30 = D_803F28E0[0].unk34 = D_803F28E0[0].unk50;

    D_803F2C1E = 0;
    // temp_v1_2 = D_803F28E0[0].unk65;
    // temp_v0_2 = D_801D9ED8.animals[gCurrentAnimalIndex].animal ; //(&D_801D9ED8 + (gCurrentAnimalIndex * 8))->unk3EB4;
    D_803F28E0[0].unk8 = (f32) D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.w;
    D_803F28E0[0].unkC = (f32) D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.w;
    D_803F28E0[0].unk50 = 0xFA;
    D_803F28E0[0].unk14 = 25.0f;
    D_803F28E0[0].unk54 = -0x20;
    D_803F28E0[0].unk56 = 0x10;
    D_803F28E0[0].unk58 = 0x14;
    D_803F28E0[0].unk60 = 0x10;
    // temp_f0_2 = (f32) D_803F28E0[0].unk50;
    D_803F28E0[0].unk10 = (f32) D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.w; //temp_v0_2->unkC;
    D_803F28E0[0].unk30 = D_803F28E0[0].unk34 = (f32)D_803F28E0[0].unk50;
    // D_803F28E0[0].unk30 = temp_f0_2;
    // temp_f0_3 = D_803F28E0[0].unk14;
    D_803F28E0[0].unk4E = D_803F28E0[0].unk18 = D_803F28E0[0].unk14;
    // D_803F28E0[0].unk4E = (s16) (s32) temp_f0_3;

    D_803F2C6E = MAX(0, D_803F28E0[0].unk65);
    D_803F2C6E = MIN(D_803F28E0[0].unk66, D_803F2C6E);

    D_803F28E0[0].unkC9 = 1;
    D_803F28E0[0].unk64 = (s8) D_803F2C6E;
    temp_f0_4 = (f32) ((s32) (D_803F2D50.unk50 << 8) / 360);
    D_803F28E0[0].unk24 = temp_f0_4;
    D_803F28E0[0].unk20 = temp_f0_4;
    // temp_v1_4 = (D_803F2C6D * 0x14) + &D_803A7114_7B87C4[D_803F2C6D];
    D_803F28E0[0].unk5A = (s16) D_803A7114_7B87C4[D_803F2C6D].unk0;
    D_803F28E0[0].unk5C = (s16) D_803A7114_7B87C4[D_803F2C6D].unk1;
    D_803F28E0[0].unk5E = (s16) D_803A7114_7B87C4[D_803F2C6D].unk2;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302 = (s16) ((s32) (D_803F2D50.unk4E << 8) / 360);
    // (&D_801D9ED8 + (gCurrentAnimalIndex * 8))->unk3EB4->unk2C = (s16) ((s32) (D_803F2D50.unk4E << 8) / 360);
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation = (s16) ((s32) (D_803F2D50.unk4E << 8) / 360);
    D_803F28E0[0].unk4C = (s16) (D_803F28E0[0].unk64 * 8);

    for (i = 0; i < 50; i++) {
        func_8032FD0C_7413BC(0, 0);
    }
    D_803A6CEC_7B839C = -1;
}
#endif

void func_8033C814_74DEC4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C += arg6;
    sp38 += arg7;
    func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, sp34, 127, 1, arg8);
}

void func_8033C8EC_74DF9C(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C += arg6;
    sp38 += arg7;
    func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, (s16)sp34 + 34, 127, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C9CC_74E07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033D604_74ECB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033DF88_74F638.s")

void func_8033E430_74FAE0(void) {
    Animal *animal;
    s16 xPos;
    s16 yPos;
    s16 temp_f16;
    s16 temp_a0_2;
    s16 sp32;
    s16 phi_v0_2;

    if (D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkC6 & 8) {
        D_803F2A9E = 0;
        return;
    }

    animal = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    if ((animal->unk162 & 0xF) == 1) {
        temp_f16 = animal->yRotation + gCamera->unk24;
        xPos = animal->xPos.h + (((D_80152C78[temp_f16 & 0xFF] >> 7) << 7) >> 8);
        yPos = animal->zPos.h + (((D_80152C78[(temp_f16 + 0x40) & 0xFF] >> 7) << 7) >> 8);

        sp32 = (func_80310F58_722608(xPos, yPos) >> 0x10);
        temp_a0_2 = func_8031124C_7228FC(xPos, yPos) >> 0x10;
        if (sp32 == 0x4000) {
            phi_v0_2 = temp_a0_2 - animal->yPos.h;
        } else {
            if (animal->unk160 == 2) {
                phi_v0_2 = sp32 - animal->yPos.h;
            } else if (func_8033C9CC_74E07C(
                    animal->xPos.h,
                    animal->zPos.h,
                    D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unkBA + animal->yPos.h,
                    animal->unk160,
                    xPos,
                    yPos,
                    (sp32 + temp_a0_2) >> 1,
                    0x7F,
                    1,
                    0) == 0) {
                phi_v0_2 = temp_a0_2 - animal->yPos.h;
            } else {
                phi_v0_2 = sp32 - animal->yPos.h;
            }
        }
        // clamp
        if (phi_v0_2 < -240) {
            phi_v0_2 = -240;
        }
        if (phi_v0_2 > 240) {
            phi_v0_2 = 240;
        }

        if (D_803F2A9E < phi_v0_2) {
            D_803F2A9E = MIN(phi_v0_2, D_803F2A9E + 6);
        } else if (phi_v0_2 < D_803F2A9E) {
            D_803F2A9E = MAX(phi_v0_2, D_803F2A9E - 6);
        }
    }
}

void func_8033E6B8_74FD68(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 tmp0;
    f32 tmp1;
    f32 tmp2;
    // 6.2832 (2*PI)
    tmp1 = arg1 * D_803BE5F8 * (256 / 65536.0);
    tmp0 = sinf(tmp1);
    // 6.2832
    tmp2 = arg0 * D_803BE600 * (256 / 65536.0);
    *arg3 = gCamera->unk8 - cosf(tmp2) * (arg2 * tmp0);
    tmp0 = cosf(tmp1);
    *arg4 = gCamera->unkC - cosf(tmp2) * (arg2 * tmp0);
    *arg5 = gCamera->unk10 + sinf(tmp2) * arg2;
}

#if 0
void func_8033E7C8_74FE78(OSContPad *cont) {
    static u16 D_803F2C72; // I guess it is static
    s16 phi_v0;
    u16 button = cont->button;

    if (((button & D_CBUTTONS)) && (!(D_803F2C72 & D_CBUTTONS)) &&
        (button & U_CBUTTONS)) {
            D_803F2AA2 = 0;
            D_803F2C6C = D_803F2C6D = 0;
    }

    phi_v0 = MIN(D_803F28E0[D_803F2A98].unk66, D_803F2C6E);
    D_803F28E0[D_803F2A98].unk64 = MAX(D_803F28E0[D_803F2A98].unk65, phi_v0);

    switch (D_803F28E0[D_803F2A98].cameraMode) {
    case 1:
    case 26:
        if (D_803F28E0[D_803F2A98].unkD6 == 1) {
            if ((cont->button & R_CBUTTONS) && (!(D_803F2C72 & R_CBUTTONS))) {
                if (D_803F28E0[D_803F2A98].unkD8 == 0) {
                    func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
                } else {
                    func_8032C508_73DBB8(15, 0x2A00, 0, 1.0f);
                    if ((D_803F28E0[D_803F2A98].unk24 > 0.0) &&
                        (D_803F28E0[D_803F2A98].unk24 < 32.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 0.0f;
                    } else if ((D_803F28E0[D_803F2A98].unk24 > 64.0) &&
                               (D_803F28E0[D_803F2A98].unk24 < 96.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 64.0f;
                    } else if ((D_803F28E0[D_803F2A98].unk24 > 128.0) &&
                               (D_803F28E0[D_803F2A98].unk24 < 160.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 128.0f;
                    } else if ((D_803F28E0[D_803F2A98].unk24 > 192.0) &&
                               (D_803F28E0[D_803F2A98].unk24 < 224.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 192.0f;
                    } else {
                        D_803F28E0[D_803F2A98].unk24 -= 32.0;
                    }
                    if (D_803F28E0[D_803F2A98].unk24 < 0.0) {
                        D_803F28E0[D_803F2A98].unk24 += 256.0;
                    }

                    if (D_803F28E0[D_803F2A98].cameraMode == 26) {
                        D_803F28E0[D_803F2A98].unk70 = 60;
                    } else {
                        D_803F28E0[D_803F2A98].unk70 = 200;
                    }
                }
            }
            if ((cont->button & L_CBUTTONS) && (!(D_803F2C72 & L_CBUTTONS))) {
                if (D_803F28E0[D_803F2A98].unkD7 == 0) {
                    func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
                } else {
                    func_8032C508_73DBB8(15, 0x2A00, 0, 1.0f);
                    if ((D_803F28E0[D_803F2A98].unk24 > 32.0) && (D_803F28E0[D_803F2A98].unk24 < 64.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 64.0f;
                    } else if ((D_803F28E0[D_803F2A98].unk24 > 96.0) && (D_803F28E0[D_803F2A98].unk24 < 128.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 128.0f;
                    } else if ((D_803F28E0[D_803F2A98].unk24 > 160.0) && (D_803F28E0[D_803F2A98].unk24 < 192.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 192.0f;
                    } else if ((D_803F28E0[D_803F2A98].unk24 > 224.0) && (D_803F28E0[D_803F2A98].unk24 < 256.0)) {
                        D_803F28E0[D_803F2A98].unk24 = 256.0f;
                    } else {
                        D_803F28E0[D_803F2A98].unk24 += 32.0;
                    }
                    if (D_803F28E0[D_803F2A98].unk24 > 256.0) {
                        D_803F28E0[D_803F2A98].unk24 -= 256.0;
                    }

                    if (D_803F28E0[D_803F2A98].cameraMode == 26) {
                        D_803F28E0[D_803F2A98].unk70 = 60;
                    } else {
                        D_803F28E0[D_803F2A98].unk70 = 200;
                    }
                }
            }

            func_8033EF94_750644(cont, D_803F2C72);
            if ((D_803F2D30.unk4 > 0) && (D_803F28E0[D_803F2A98].unkD6 == 1)) {
                D_803F2C6E -= 2;
            }
        }
        break;
    case 2:
    case 12:
        func_8033EF94_750644(cont, D_803F2C72);
        if ((D_803F2D30.unk4 > 0) && (D_803F28E0[D_803F2A98].unkD6 == 1)) {
            D_803F2C6E -= 2;
        }
        break;
    case 3:
    case 17:
        if (D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C != TORTOISE_TANK) {
            func_8033EF94_750644(cont, D_803F2C72);
        } else {
            D_803F28E0[D_803F2A98].unk18 = 0.0f;
        }
        D_803F28E0[D_803F2A98].unk68 = 0;
        D_803F28E0[D_803F2A98].unk24 = 0.0f;
        break;
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 19:
    case 20:
    case 21:
    case 22:
        if ((D_803F28E0[D_803F2A98].unkD6 == 1) &&
            ((((cont->button & R_CBUTTONS)) && (!(D_803F2C72 & R_CBUTTONS))) ||
            ((cont->button & L_CBUTTONS) && (!(D_803F2C72 & L_CBUTTONS))))) {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
        }

        func_8033EF94_750644(cont, D_803F2C72);
        break;
    case 6:
    case 7:
    case 28:
        if (D_803F28E0[D_803F2A98].unkD6 == 1) {
            func_8033EF94_750644(cont, D_803F2C72);
        }
        if (D_803F2D30.unk4 > 0) {
            if (D_803F28E0[D_803F2A98].unkD6 == 1) {
                D_803F28E0[D_803F2A98].unk64 = MIN(D_803F28E0[D_803F2A98].unk64, -2);
            }
        }
        break;
    case 0:
    // case 18:
    // case 23:
    // case 24:
    // case 25:
    // case 27:
    // case 29:
    // case 30:
    case 31:
    case 228:
        break;
    }
    D_803F2C72 = cont->button;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033E7C8_74FE78.s")
#endif

void func_8033EF94_750644(OSContPad *cont, u16 prevButtonState) {
    u8 res = 0;

    if ((cont->button & U_CBUTTONS) && (!(prevButtonState & U_CBUTTONS))) {
        if (D_803F2C6E < MIN(D_803F28E0[D_803F2A98].unk66, 0)) {
            D_803F2C6E = MIN(MIN(MAX(D_803F2C6E + 1, D_803F28E0[D_803F2A98].unk64 + 1), D_803F28E0[D_803F2A98].unk66), 0);
            D_803F28E0[D_803F2A98].unk64 = D_803F2C6E;
            res = 1;
        } else {
            res = 2;
        }
    }
    if ((cont->button & D_CBUTTONS) && (!(prevButtonState & D_CBUTTONS))) {
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

// decrease player <-> camera distance
void func_8033F23C_7508EC(s16 dist) {
    if (D_803F28E0[D_803F2A98].unkD6 == 1) {
        D_803F2C6E -= dist;
    }
}

// increase player <-> camera distance
void func_8033F294_750944(s16 dist) {
    if (D_803F28E0[D_803F2A98].unkD6 == 1) {
        D_803F2C6E += dist;
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

#if 0
// .rodata for function
// const f64 D_803BE688_7CFD38 = 3.1415;
// const f64 D_803BE690_7CFD40 = 3.141593;
// const f64 D_803BE698_7CFD48 = 180.0;
// const f64 D_803BE6A0_7CFD50 = 360.0;
// const f64 D_803BE6A8_7CFD58 = 180.0;
// const f64 D_803BE6B0_7CFD60 = 360.0;
// const f64 D_803BE6B8_7CFD68 = 180.0;
// const f64 D_803BE6C0_7CFD70 = 360.0;
// const f64 D_803BE6C8_7CFD78 = -180.0;
// const f64 D_803BE6D0_7CFD80 = 360.0;
const f64 D_803BE6D8_7CFD88 = 180.0;
const f64 D_803BE6E0_7CFD90 = 360.0;
// const f64 D_803BE6E8_7CFD98 = 0.017453277777777776;
// const f64 D_803BE6F0_7CFDA0 = 0.017453277777777776;
// const f64 D_803BE6F8_7CFDA8 = 0.017453277777777776;
// const f64 D_803BE700_7CFDB0 = 0.017453277777777776;
// const f64 D_803BE708_7CFDB8 = 0.0012321;
// const f32 D_803BE710_7CFDC0 = 0.6f;
// const f64 D_803BE714_7CFDC4 = 0.0f;
// const f64 D_803BE718_7CFDC8 = 310.0;
// const f64 D_803BE720_7CFDD0 = 0.0015625;
// const f64 D_803BE728_7CFDD8 = 310.0;
// const f64 D_803BE730_7CFDE0 = 0.0015625;
// const f64 D_803BE738_7CFDE8 = 0.00021;
// const f64 D_803BE740_7CFDF0 = 0.000013;
// const f64 D_803BE748_7CFDF8 = 0.00021;
// const f64 D_803BE750_7CFE00 = 0.000013;
// const f64 D_803BE758_7CFE08 = 0.00021;
// const f64 D_803BE760_7CFE10 = 0.000013;
// const f64 D_803BE768_7CFE18 = 0.00021;
// const f64 D_803BE770_7CFE20 = 0.000013;
// const f32 D_803BE778_7CFE28 = 0.7f;
const f32 D_803BE77C_7CFE2C = 0.0f;
// const f64 D_803BE780_7CFE30 = 180.0;
// const f64 D_803BE788_7CFE38 = 360.0;
const f64 D_803BE790_7CFE40 = 360.0;
#endif

#if 0
void func_8033F380_750A30(void) {
    f32 spCC;
    f32 spC8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp8C;
    f32 sp84;
    f32 sp80;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f14;

    Camera *camera1; // sp64
    Camera *camera2; // sp60

    f32 tmp;

    camera2 = &D_803F28E0[D_803F2AC8];
    camera1 = &D_803F28E0[D_803F2A98];

    switch (D_803F2C18[0]) {
    case 0:
        D_803F2C44 = camera1->unk74 + camera1->unkA4;
        D_803F2C48 = camera1->unk78 + camera1->unkA8;
        D_803F2C4C = camera1->unk7C;

        D_803F2C50 = camera1->unk8 + camera1->unkA4;
        D_803F2C54 = camera1->unkC + camera1->unkA8;
        D_803F2C58 = camera1->unk10;

        D_80204200 = camera1->unk8C;
        D_80204204 = camera1->unk90;
        D_80204208 = camera1->unk94;
        D_803F2A9A = 0x100;
        break;
    case 1:
        tmp = cosf((((f32) D_803F2C18[1] / D_803F2C18[2]) * 3.1415));
        spCC = 0.5 - 0.5 * tmp;
        spC8 = 1.0 - spCC;
        D_803F2C44 = (spC8 * (camera2->unk74 + camera2->unkA4)) + (spCC * (camera1->unk74 + camera1->unkA4));
        D_803F2C48 = (spC8 * (camera2->unk78 + camera2->unkA8)) + (spCC * (camera1->unk78 + camera1->unkA8));
        D_803F2C4C = (spC8 * camera2->unk7C) + (spCC * camera1->unk7C);

        D_80204200 = (spC8 * camera2->unk8C) + (spCC * camera1->unk8C);
        D_80204204 = (spC8 * camera2->unk90) + (spCC * camera1->unk90);
        D_80204208 = (spC8 * camera2->unk94) + (spCC * camera1->unk94);

        if (((camera2->cameraMode == 4) ||
             (camera2->cameraMode == 19) ||
             (camera2->cameraMode == 20) ||
             (camera2->cameraMode == 21) ||
             (camera2->cameraMode == 5) ||
             (camera2->cameraMode == 22)) &&
             ((camera1->cameraMode == 4) ||
              (camera1->cameraMode == 19) ||
              (camera1->cameraMode == 20) ||
              (camera1->cameraMode == 21) ||
              (camera1->cameraMode == 5) ||
              (camera1->cameraMode == 22))) {

            if (ABS(camera2->unk24 - camera1->unk24) == 128.0) {
                // sp54 = spCC * 3.141593;
                D_80204200 = (cosf(spCC * 3.141593) * camera2->unk8C) + (sinf(spCC * 3.141593) * camera2->unk90);
                D_80204204 = (cosf(spCC * 3.141593) * camera2->unk90) - (sinf(spCC * 3.141593) * camera2->unk8C);
            }
        }
        spB4 = camera2->unk8 - camera2->unk74;
        spB0 = camera2->unkC - camera2->unk78;
        spAC = camera2->unk10 - camera2->unk7C;
        sp84 = func_801286B8(spAC, sqrtf((spB4 * spB4) + (spB0 * spB0)));

        if (sp84 > 180.0) {
            sp84 -= 180.0;
        }
        if ((spB0 == 0.0) && (spB4 == 0.0)) {
            sp80 = 0.0f;
        } else {
            sp80 = func_801286B8(-spB0, spB4);
        }
        spA0 = camera1->unk8 - camera1->unk74;
        sp9C = camera1->unkC - camera1->unk78;
        sp98 = camera1->unk10 - camera1->unk7C;

        sp8C = func_801286B8(sp98, sqrtf((spA0 * spA0) + (sp9C * sp9C)));
        if (sp8C > 360.0) {
            sp8C -= 360.0; //(sp8C - 360.0);
        }
        if ((sp9C == 0.0) && (spA0 == 0.0)) {
            temp_f14 = 0.0f;
        } else {
            temp_f14 = func_801286B8(-sp9C, spA0);
        }
        D_803F2C74 = (spCC * sp8C) + (spC8 * sp84);

        if ((camera2->cameraMode == 4) ||
            (camera2->cameraMode == 19) ||
            (camera2->cameraMode == 20) ||
            (camera2->cameraMode == 21) ||
            (camera2->cameraMode == 5) ||
            (camera2->cameraMode == 22)) {
            D_803F2C78 = temp_f14;
        } else {
            if ((camera1->cameraMode == 4) ||
                (camera1->cameraMode == 19) ||
                (camera1->cameraMode == 20) ||
                (camera1->cameraMode == 21) ||
                (camera1->cameraMode == 5) ||
                (camera1->cameraMode == 22)) {
                D_803F2C78 = sp80;
            } else {
                temp_f2 = temp_f14 - sp80;

                if (D_803F2C18[1] == 1) {

                    while (temp_f2 > 180.0) {
                        temp_f2 -= 360.0;
                    };

                    while (temp_f2 < -180.0) {
                        temp_f2 += 360.0;
                    };

                    D_803F2C78 = (temp_f2 * spCC) + sp80;
                } else {
                    if (temp_f2 < D_803F2C7C) {
                        temp_f2 = ABS(temp_f2 - D_803F2C7C);
                        while (temp_f2 > 180.0f) {
                            temp_f2 += 360.0f;
                            temp_f2 = ABS(temp_f2 - D_803F2C7C);
                        }
                    } else {
                        temp_f2 = ABS(temp_f2 - D_803F2C7C);

                        while (temp_f2 > 180.0f) {
                            temp_f2 -= 360.0f;
                            temp_f2 = ABS(temp_f2 - D_803F2C7C);
                        }
                    }
                    D_803F2C78 = (temp_f2 * spCC) + sp80;
                }
                D_803F2C7C = temp_f2;
            }
        }
        sp74 = cosf(D_803F2C74 * (3.14159 / 180));
        sp6C = sinf(D_803F2C74 * (3.14159 / 180));
        sp70 = sinf(D_803F2C78 * (3.14159 / 180)) * -sp74;
        tmp = (cosf(D_803F2C78 * (3.14159 / 180)) * sp74);

        D_803F2C50 = D_803F2C44 + tmp;
        D_803F2C54 = D_803F2C48 + sp70;
        D_803F2C58 = D_803F2C4C + sp6C;

        D_803F2A9A = 256;
        break;
    case 2:
        if (D_803F2C18[1] == 1) {
            trigger_screen_transition(5);
        } else if (((D_803F2C18[2] / 2) + 1) == D_803F2C18[1]) {
            trigger_screen_transition(4);
        }
        if ((D_803F2C18[2] / 2) >= D_803F2C18[1]) {
            D_803F2C44 = camera2->unk74 + camera1->unkA4;
            D_803F2C48 = camera2->unk78 + camera1->unkA8;
            D_803F2C4C = camera2->unk7C;

            D_803F2C50 = camera2->unk8 + camera1->unkA4;
            D_803F2C54 = camera2->unkC + camera1->unkA8;
            D_803F2C58 = camera2->unk10;

            D_80204200 = camera2->unk8C;
            D_80204204 = camera2->unk90;
            D_80204208 = camera2->unk94;
        } else {
            D_803F2C44 = camera1->unk74 + camera1->unkA4;
            D_803F2C48 = camera1->unk78 + camera1->unkA8;
            D_803F2C4C = camera1->unk7C;

            D_803F2C50 = camera1->unk8 + camera1->unkA4;
            D_803F2C54 = camera1->unkC + camera1->unkA8;
            D_803F2C58 = camera1->unk10;

            D_80204200 = camera1->unk8C;
            D_80204204 = camera1->unk90;
            D_80204208 = camera1->unk94;
        }
        break;
    }

    if (D_803F2ACA > 0) {
        D_803F2ACA -= D_803F2ACA >> 3;
        D_803F2ACA -= 1;

        if ((camera1->cameraMode == 3) || (camera1->cameraMode == 17)) {
            temp_f0 = ((f32) (func_8012826C() - 32768.0) * D_803F2ACA) / (6 * 65536.0f);
            D_803F2C44 += temp_f0;
            D_803F2C50 += temp_f0;

            temp_f0 = ((f32) (func_8012826C() - 32768.0) * D_803F2ACA) / (6 * 65536.0f);
            D_803F2C48 += temp_f0;
            D_803F2C54 += temp_f0;

            temp_f0 = ((f32) (func_8012826C() - 32768.0) * D_803F2ACA) / (3 * 65536.0f);
            D_803F2C4C += temp_f0;
            D_803F2C58 += temp_f0;
        } else {
            temp_f0 = ((f32) (func_8012826C() - 32768.0) * D_803F2ACA) / (2 * 65536.0f);
            D_803F2C44 += temp_f0;
            D_803F2C50 += temp_f0;

            temp_f0 = ((f32) (func_8012826C() - 32768.0) * D_803F2ACA) / (2 * 65536.0f);
            D_803F2C48 += temp_f0;
            D_803F2C54 += temp_f0;

            temp_f0 = ((f32) (func_8012826C() - 32768.0) * D_803F2ACA) / (1 * 65536.0f);
            D_803F2C4C += temp_f0;
            D_803F2C58 += temp_f0;
        }
    }
    if ((D_803F2C44 == D_803F2C50) && (D_803F2C48 == D_803F2C54) && (D_803F2C4C == D_803F2C58)) {
        D_803F2C50 += 10.0;
    }
    if ((D_80204200 == 0.0) && (D_80204204 == 0.0) && (D_80204208 == 0.0)) {
        D_80204204 = 10.0f;
    }
    if ((D_803F2C44 == D_803F2C50) && (D_803F2C48 == D_803F2C54)) {
        D_80204200 += 0.0012321;
    }
    temp_f0 = sqrtf((D_80204200 * D_80204200) + (D_80204204 * D_80204204) + (D_80204208 * D_80204208));
    D_80204200 /= temp_f0;
    D_80204204 /= temp_f0;
    D_80204208 /= temp_f0;

    D_80204218 = D_803F2C50 - D_803F2C44;
    D_8020421C = D_803F2C54 - D_803F2C48;
    D_80204220 = D_803F2C58 - D_803F2C4C;

    temp_f0 = sqrtf((D_80204218 * D_80204218) + (D_8020421C * D_8020421C) + (D_80204220 * D_80204220));
    D_80204218 /= temp_f0;
    D_8020421C /= temp_f0;
    D_80204220 /= temp_f0;

    D_80204224 = (s16) (s32) (D_80204218 * 1024.0);
    D_80204226 = (s16) (s32) (D_8020421C * 1024.0);
    D_80204228 = (s16) (s32) (D_80204220 * 1024.0);

    // Compute the negative cross product of these two vectors:
    // x0 = D_80204200
    // y0 = D_80204204
    // z0 = D_80204208

    // x1 = D_80204218
    // y1 = D_8020421C
    // z1 = D_80204220

    // Cross product:
    // y0 * z1 - z0 * y1
    // z0 * x1 - x0 * z1
    // x0 * y1 - y0 * x1

    // Negative cross product:
    // z0 * y1 - y0 * z1
    // x0 * z1 - z0 * x1
    // y0 * x1 - x0 * y1

    D_8020422C = (D_80204208 * D_8020421C) - (D_80204204 * D_80204220);
    D_80204230 = (D_80204200 * D_80204220) - (D_80204208 * D_80204218);
    D_80204234 = (D_80204204 * D_80204218) - (D_80204200 * D_8020421C);

    temp_f0 = sqrtf((D_8020422C * D_8020422C) + (D_80204230 * D_80204230) + (D_80204234 * D_80204234));
    if (temp_f0 == 0.0f) {
        D_8020422C = 0.6f;
        D_80204230 = 0.6f;
        D_80204234 = 0.6f;
    } else {
        D_8020422C /= temp_f0;
        D_80204230 /= temp_f0;
        D_80204234 /= temp_f0;
    }

    if (D_803A6CE4_7B8394 & 4) {
        D_80204200 = D_80152620[(s16)D_803F2C3C] * (0.0015625 * cosf(D_803D5544 / 310.0));
        D_80204204 = D_801526D4[(s16)D_803F2C3C] * (0.0015625 * cosf(D_803D5544 / 310.0));
        guLookAt(
            &D_80204278->unk37490,
            D_803F2C44,
            D_803F2C48,
            D_803F2C4C,
            (D_803F2C44 + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (D_803F2C48 - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (D_803F2C4C           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204204,
            D_80204208);
    } else if (D_803A6CE4_7B8394 & 1) {
        guLookAt(
            &D_80204278->unk37490,
            D_803F2C44,
            D_803F2C48,
            D_803F2C4C,
            (D_803F2C44 + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (D_803F2C48 - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (D_803F2C4C           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204204,
            -D_80204208);
    } else if (D_803A6CE4_7B8394 & 2) {
        guLookAt(
            &D_80204278->unk37490,
            D_803F2C44,
            D_803F2C48,
            D_803F2C4C,
            (D_803F2C44 + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (D_803F2C48 - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (D_803F2C4C           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204208,
            D_80204204);
    } else {
        guLookAt(
            &D_80204278->unk37490,
            D_803F2C44,
            D_803F2C48,
            D_803F2C4C,
            (D_803F2C44 + 0.00021 ) + (D_80204218 * 64.0 * 10.0),
            (D_803F2C48 - 0.000013) + (D_8020421C * 64.0 * 10.0),
            (D_803F2C4C           ) + (D_80204220 * 64.0 * 10.0),
            D_80204200,
            D_80204204,
            D_80204208);
    }
    D_803F2C5C = D_803F2C50 - D_803F2C44;
    D_803F2C60 = D_803F2C54 - D_803F2C48;

    temp_f0 = sqrtf((D_803F2C5C * D_803F2C5C) + (D_803F2C60 * D_803F2C60));
    if (temp_f0 == 0.0) {
        D_803F2C5C = 0.7f;
        D_803F2C60 = 0.7f;
    } else {
        D_803F2C5C /= temp_f0;
        D_803F2C60 /= temp_f0;
    }
    D_803F2C64 = -D_803F2C60;
    D_803F2C68 = D_803F2C5C;
    D_8020420C = (D_80204234 * D_8020421C) - (D_80204230 * D_80204220);
    D_80204210 = (D_8020422C * D_80204220) - (D_80204234 * D_80204218);
    D_80204214 = (D_80204230 * D_80204218) - (D_8020422C * D_8020421C);
    func_803415BC_752C6C();
    func_8032D680_73ED30();

    D_803F2C40 = func_801286B8(D_80204220, sqrtf((D_80204218 * D_80204218) + (D_8020421C * D_8020421C)));
    if (360.0 < D_803F2C40) {
        D_803F2C40 -= 180.0;
    }

    if ((D_8020421C == 0.0) && (D_80204218 == 0.0)) {
        D_803F2C3C = 0.0f;
    } else {
        D_803F2C3C = func_801286B8(-D_8020421C, D_80204218);
    }
    temp_f0 = D_803F2C44 - D_803F2C50;
    temp_f2 = D_803F2C48 - D_803F2C54;
    temp_f14 = D_803F2C4C - D_803F2C58;
    D_803A6CC0_7B8370 = (s32)((256.0 * (f64) (D_803F2C4C - D_803F2C58)) / (f64) sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14)));
    D_803F2A9C = sqrtf((65536.0 - ((f32)D_803A6CC0_7B8370 * D_803A6CC0_7B8370)));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033F380_750A30.s")
#endif

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

void func_80340EA4_752554(struct062 *arg0, s16 arg1) {
    s16 cameraMode;
    s16 i;
    s16 sp32;
    s16 sp30;
    s8  sp2F;
    s16 temp_v0_5;

    if (D_803F2C18[0] == 0) {
        func_80343C44_7552F4(arg0->unk12, &sp32, &sp30);
        cameraMode = D_803F28E0[D_803F2A98].cameraMode;
        D_803F2AC8 = D_803F2A98;
        D_803F2A98 = (D_803F2A98 + 1) % 2;

        if (((cameraMode == 2) || (sp32 == 2)) &&
            ((cameraMode != 12) && (sp32 != 12))) {
            D_803F2C18[0] = 2;
        } else {
            D_803F2C18[0] = 1;
        }
        if (arg1 < 0) {
            D_803F2C18[2] = arg0->unkA;
        } else {
            D_803F2C18[2] = arg1;
        }
        D_803F2C18[1] = 0;
        if (D_803A6CEC_7B839C >= 0) {
            D_803F2C18[2] = D_803A6CEC_7B839C;
            D_803A6CEC_7B839C = -1;
        }

        if (arg0->unk12 == 0) {
            D_803F28E0[D_803F2A98].unk2 = D_803F28E0[D_803F2AC8].unk2;
            D_803F28E0[D_803F2A98].cameraMode = D_803F28E0[D_803F2AC8].cameraMode;
        } else {
            D_803F28E0[D_803F2A98].unk2 = arg0->unk12;
            D_803F28E0[D_803F2A98].cameraMode = sp32;
        }
        D_803F28E0[D_803F2A98].unk6 = 0;
        D_803F28E0[D_803F2A98].unk4 = sp30;
        D_803F28E0[D_803F2A98].unkC9 = arg0->unk17;
        D_803F28E0[D_803F2A98].unkD6 = arg0->unk18;
        D_803F28E0[D_803F2A98].unkD0 = arg0->unkC;
        D_803F28E0[D_803F2A98].unkD2 = arg0->unkE;
        D_803F28E0[D_803F2A98].unkD4 = arg0->unk10;
        D_803F28E0[D_803F2A98].unkCC = arg0->unk0;
        D_803F28E0[D_803F2A98].unk6C = arg0->unk0;

        D_803F28E0[D_803F2A98].unk4E = D_803F28E0[D_803F2AC8].unk4E;
        D_803F28E0[D_803F2A98].unk50 = D_803F28E0[D_803F2AC8].unk50;
        D_803F28E0[D_803F2A98].unk52 = D_803F28E0[D_803F2AC8].unk52;
        D_803F28E0[D_803F2A98].unk54 = D_803F28E0[D_803F2AC8].unk54;
        D_803F28E0[D_803F2A98].unk56 = D_803F28E0[D_803F2AC8].unk56;
        D_803F28E0[D_803F2A98].unk58 = D_803F28E0[D_803F2AC8].unk58;
        D_803F28E0[D_803F2A98].unk67 = D_803F28E0[D_803F2AC8].unk67;
        D_803F28E0[D_803F2A98].unk60 = D_803F28E0[D_803F2AC8].unk60;

        D_803F28E0[D_803F2A98].unk5A = arg0->unk14;
        D_803F28E0[D_803F2A98].unk5C = arg0->unk15;
        D_803F28E0[D_803F2A98].unk5E = arg0->unk16;

        D_803F28E0[D_803F2A98].unk18 = D_803F28E0[D_803F2A98].unk4E;
        D_803F28E0[D_803F2A98].unk14 = D_803F28E0[D_803F2A98].unk4E;
        D_803F28E0[D_803F2A98].unk1C = 0.0f;

        if ((D_803F28E0[D_803F2AC8].cameraMode == 3) || (D_803F28E0[D_803F2AC8].cameraMode == 17)) {
            D_803F28E0[D_803F2A98].unk24 = (D_803F28E0[D_803F2AC8].unk24 * 256.0) / 360.0;
        } else {
            D_803F28E0[D_803F2A98].unk24 = D_803F28E0[D_803F2AC8].unk24;
        }

        D_803F28E0[D_803F2A98].unk28 = 0.0f;
        D_803F28E0[D_803F2A98].unk20 = D_803F28E0[D_803F2A98].unk24;
        D_803F28E0[D_803F2A98].unk34 = D_803F28E0[D_803F2AC8].unk34;
        D_803F28E0[D_803F2A98].unk30 = D_803F28E0[D_803F2A98].unk34;
        D_803F28E0[D_803F2A98].unk38 = 0.0f;
        D_803F28E0[D_803F2A98].unk3C = D_803F28E0[D_803F2A98].unk54;
        D_803F28E0[D_803F2A98].unk40 = 0.0f;
        D_803F28E0[D_803F2A98].unk44 = D_803F28E0[D_803F2A98].unk56;
        D_803F28E0[D_803F2A98].unk48 = 0.0f;

        D_803F28E0[D_803F2A98].unk8 = D_803F28E0[D_803F2AC8].unk8;
        D_803F28E0[D_803F2A98].unkC = D_803F28E0[D_803F2AC8].unkC;
        D_803F28E0[D_803F2A98].unk10 = D_803F28E0[D_803F2AC8].unk10;
        D_803F28E0[D_803F2A98].unk74 = D_803F28E0[D_803F2AC8].unk74;
        D_803F28E0[D_803F2A98].unk78 = D_803F28E0[D_803F2AC8].unk78;
        D_803F28E0[D_803F2A98].unk7C = D_803F28E0[D_803F2AC8].unk7C;
        D_803F28E0[D_803F2A98].unk80 = D_803F28E0[D_803F2AC8].unk80;
        D_803F28E0[D_803F2A98].unk84 = D_803F28E0[D_803F2AC8].unk84;
        D_803F28E0[D_803F2A98].unk88 = D_803F28E0[D_803F2AC8].unk88;
        D_803F28E0[D_803F2A98].unkA4 = D_803F28E0[D_803F2AC8].unkA4;
        D_803F28E0[D_803F2A98].unkA8 = D_803F28E0[D_803F2AC8].unkA8;
        D_803F28E0[D_803F2A98].unkAC = D_803F28E0[D_803F2AC8].unkAC;
        D_803F28E0[D_803F2A98].unkB0 = D_803F28E0[D_803F2AC8].unkB0;
        D_803F28E0[D_803F2A98].unkB4 = D_803F28E0[D_803F2AC8].unkB4;
        D_803F28E0[D_803F2A98].unkB8 = D_803F28E0[D_803F2AC8].unkB8;
        D_803F28E0[D_803F2A98].unk8C = D_803F28E0[D_803F2AC8].unk8C;
        D_803F28E0[D_803F2A98].unk90 = D_803F28E0[D_803F2AC8].unk90;
        D_803F28E0[D_803F2A98].unk94 = D_803F28E0[D_803F2AC8].unk94;

        D_803F28E0[D_803F2A98].unk66 = arg0->unk1A;
        D_803F28E0[D_803F2A98].unk65 = arg0->unk19;
        D_803F28E0[D_803F2A98].unk67 = arg0->unk1B;

        D_803F28E0[D_803F2A98].unk64 = D_803F28E0[D_803F2AC8].unk64;
        D_803F28E0[D_803F2A98].unk64 = MIN(D_803F28E0[D_803F2A98].unk66, D_803F28E0[D_803F2A98].unk64);
        D_803F28E0[D_803F2A98].unk64 = MAX(D_803F28E0[D_803F2A98].unk65, D_803F28E0[D_803F2A98].unk64);

        D_803F28E0[D_803F2A98].unk4C = (D_803F28E0[D_803F2A98].unk64 * 8);

        switch (D_803F28E0[D_803F2A98].unkD6) {
        case 1:
            if ((D_803A6CE4_7B8394 & 8)) {
                D_803F28E0[D_803F2A98].unk62 = (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 3;
            } else {
                D_803F28E0[D_803F2A98].unk62 = (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2;
            }
            break;
        case 2:
            D_803F28E0[D_803F2A98].unk62 = (D_803F28E0[D_803F2A98].unkCC->unk42 * 3) >> 2;
            break;
        case 3:
            D_803F28E0[D_803F2A98].unk62 = (D_803F28E0[D_803F2A98].unkCC->unk42 * 3) >> 2;
            break;
        }

        if ((D_803F28E0[D_803F2A98].unkD6 == 1) && (D_803F28E0[D_803F2AC8].unkD6 != 1)) {
            D_803F28E0[D_803F2A98].unk64 = D_803F2C6E;
            D_803F28E0[D_803F2A98].unk64 = MIN(D_803F28E0[D_803F2A98].unk66, D_803F28E0[D_803F2A98].unk64);
            D_803F28E0[D_803F2A98].unk64 = MAX(D_803F28E0[D_803F2A98].unk65, D_803F28E0[D_803F2A98].unk64);
        }

        D_803F28E0[D_803F2A98].unkC4 = 0.0f;
        if ((sp32 == 3) || (sp32 == 0x11)) {
            D_803F28E0[D_803F2A98].unk24 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation;
            D_803F28E0[D_803F2A98].unk20 = D_803F28E0[D_803F2A98].unk24;
            D_803F28E0[D_803F2A98].unk18 = 0.0f;
            D_803F28E0[D_803F2A98].unk14 = 0.0f;
        }
        sp2F = func_80344158_755808(D_803F28E0[D_803F2A98].cameraMode);
        temp_v0_5 = func_80344158_755808(D_803F28E0[D_803F2AC8].cameraMode);
        if ((((sp2F == 1) && (temp_v0_5 == 0)) || ((temp_v0_5 == 1) && (sp2F == 0))) &&
             (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A == 0)) {
            D_803F2C28 = 8;
        }
        if ((sp32 == 3) || (sp32 == 5) || (sp32 == 6) || (sp32 == 7) || (sp32 == 28) || (sp32 == 17)) {
            D_801D9ED8.unkFFA8 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation;
        }

        if ((D_803F28E0[D_803F2AC8].cameraMode == 23) || (D_803F28E0[D_803F2AC8].cameraMode == 24)) {
            func_802B34DC_6C4B8C();
        }
        D_803F2AA6 = 1;

        for (i = 0; i < 5; i++) {
            if (D_803F28E0[D_803F2A98].cameraMode != 23) {
                func_8032FD0C_7413BC(D_803F2A98, 0);
            }
        }
        D_803F2AA6 = 0;
    }
}

void func_803415BC_752C6C(void) {
    u8 sp57;
    u8 sp56;

    u8 sp55; // not actually used?
    u8 sp54;

    s16 phi_v0;
    s16 phi_t0;

    D_803F2AA4 = 0;
    D_803F2AA5 = 0;
    D_803F2AC6 = 0;
    func_80343A50_755100();
    sp57 = sp56 = 0xFF;

    if (D_803F2C18[0] == 0) {
        if (D_803F2AA7 != 0) {
            if (D_803F28E0[D_803F2A98].cameraMode != 30) {
                func_80340E08_7524B8(30, 0, 0, 0, 0, 0, 0, 1, D_803A6CDC_7B838C);
                D_803A6CEC_7B839C = D_803A6CDC_7B838C;
            }
            D_803F2C6C = D_803F2C6D = 0;
        } else {
            if ((D_803F2AA2 == 3) || (D_803F2AA2 == 4)) {
                if (D_803F28E0[D_803F2A98].cameraMode != 25) {
                    if (D_803F2AA2 == 3) {
                        phi_v0 = 30;
                    } else {
                        phi_v0 = 0;
                    }
                    func_80340E08_7524B8(45, 0, 0, 0, 1, -2, 0, 1, phi_v0);
                }
            } else if ((D_803F2AA2 == 1) || (D_803F2AA2 == 2)) {
                if (D_803F28E0[D_803F2A98].cameraMode != 29) {
                    if (D_803F2AA2 == 1) {
                        phi_v0 = 30;
                    } else {
                        phi_v0 = 0;
                    }
                    func_80340E08_7524B8(29, 0, 0, 0, 1, -2, 0, 1, phi_v0);
                }
            } else {
                if ((D_803F2AF8[D_803F2C20].unk18 != 1) && (D_803F2AF8[D_803F2C20].unk18 != 0)) {
                    if (((D_803F28E0[D_803F2A98].unk2  != D_803F2AF8[D_803F2C20].unk12) && (D_803F2AF8[D_803F2C20].unk12 != 0)) ||
                         (D_803F28E0[D_803F2A98].unkC9 != D_803F2AF8[D_803F2C20].unk17) ||
                         (D_803F28E0[D_803F2A98].unkD6 != D_803F2AF8[D_803F2C20].unk18) ||
                         (D_803F28E0[D_803F2A98].unkCC != D_803F2AF8[D_803F2C20].unk0 ) ||
                         (D_803F28E0[D_803F2A98].unkD0 != D_803F2AF8[D_803F2C20].unkC ) ||
                         (D_803F28E0[D_803F2A98].unkD2 != D_803F2AF8[D_803F2C20].unkE ) ||
                         (D_803F28E0[D_803F2A98].unkD4 != D_803F2AF8[D_803F2C20].unk10) ||
                         (D_803F28E0[D_803F2A98].unk5A != D_803F2AF8[D_803F2C20].unk14) ||
                         (D_803F28E0[D_803F2A98].unk5C != D_803F2AF8[D_803F2C20].unk15) ||
                         (D_803F28E0[D_803F2A98].unk5E != D_803F2AF8[D_803F2C20].unk16) ||
                         (D_803F28E0[D_803F2A98].unk65 != D_803F2AF8[D_803F2C20].unk19) ||
                         (D_803F28E0[D_803F2A98].unk66 != D_803F2AF8[D_803F2C20].unk1A) ||
                         (D_803F28E0[D_803F2A98].unk67 != D_803F2AF8[D_803F2C20].unk1B)) {
                        if (D_803F2AF8[D_803F2C20].unk12 == 0) {
                            D_803F2AF8[D_803F2C20].unk12 = D_803F28E0[D_803F2A98].unk2;
                        }
                        func_80340EA4_752554(&D_803F2AF8[D_803F2C20], -1);
                    }
                    D_803F2C6C = D_803F2C6D = 0;
                } else {
                    if (D_803F2AD8[0].unk12 != 0) {
                        if ((D_803F28E0[D_803F2A98].unk2  != D_803F2AD8[0].unk12) ||
                            (D_803F28E0[D_803F2A98].unkC9 != D_803F2AD8[0].unk17) ||
                            (D_803F28E0[D_803F2A98].unkD6 != D_803F2AD8[0].unk18) ||
                            (D_803F28E0[D_803F2A98].unkCC != D_803F2AD8[0].unk0 ) ||
                            (D_803F28E0[D_803F2A98].unkD0 != D_803F2AD8[0].unkC ) ||
                            (D_803F28E0[D_803F2A98].unkD2 != D_803F2AD8[0].unkE ) ||
                            (D_803F28E0[D_803F2A98].unkD4 != D_803F2AD8[0].unk10) ||
                            (D_803F28E0[D_803F2A98].unk5A != D_803F2AD8[0].unk14) ||
                            (D_803F28E0[D_803F2A98].unk5C != D_803F2AD8[0].unk15) ||
                            (D_803F28E0[D_803F2A98].unk5E != D_803F2AD8[0].unk16) ||
                            (D_803F28E0[D_803F2A98].unk65 != D_803F2AD8[0].unk19) ||
                            (D_803F28E0[D_803F2A98].unk66 != D_803F2AD8[0].unk1A) ||
                            (D_803F28E0[D_803F2A98].unk67 != D_803F2AD8[0].unk1B)) {
                            if (D_803F2AF8[D_803F2C20].unkA >= 0) {
                                func_80340EA4_752554(&D_803F2AD8, D_803F2AF8[D_803F2C20].unkA);
                                D_803F2AF8[D_803F2C20].unkA = -1;
                            } else {
                                func_80340EA4_752554(&D_803F2AD8, -1);
                            }
                            D_803F2C6C = D_803F2C6D = 0;
                        } else {
                            D_803F2AA4 = 1;
                        }
                    } else {
                        if ((D_803F2AF8[D_803F2C20].unk18 == 1) || (D_803F2AF8[D_803F2C20].unk18 == 0)) {
                            if ((gControllerInput->button & Z_TRIG) &&
                                (D_801D9ED8.animals[gCurrentAnimalIndex].animal->state != 0xDD) &&
                                (D_803A6CE0_7B8390 == 0) &&
                                (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk366 != 2)) {
                                sp57 = 3;
                                sp56 = 254;
                                D_803A6CE8_7B8398 = 25;
                                func_80319F58_72B608(
                                    D_803A6D14_7B83C4,
                                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
                                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
                                    (D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h + ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2)) >> 6,
                                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160,
                                    &sp55,
                                    &sp54);
                            } else {
                                func_80319F58_72B608(
                                    D_803A6D14_7B83C4,
                                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
                                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
                                    (D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h + ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2)) >> 6,
                                    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160,
                                    &sp57,
                                    &sp56);
                            }
                        } else {
                            func_80319F58_72B608(
                                D_803A6D14_7B83C4,
                                (s16)D_803F2C2C >> 6,
                                (s16)D_803F2C30 >> 6,
                                (s16)D_803F2C34 >> 6,
                                D_803F2C38,
                                &sp57,
                                &sp56);
                        }

                        if ((sp57 != D_803F2C6C) || (sp56 != D_803F2C6D)) {
                            if ((sp57 == 2) || (sp57 == 12) ||
                                (sp57 == 33) || (sp57 == 40)) {
                                phi_t0 = 30;
                                if (D_803F2AF8[D_803F2C20].unkA >= 0) {
                                    phi_t0 = D_803F2AF8[D_803F2C20].unkA;
                                    D_803F2AF8[D_803F2C20].unkA = -1;
                                    if (phi_t0 == 0) {
                                        func_80319F58_72B608(
                                            D_803A6D14_7B83C4,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h >> 6,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160,
                                            &D_803F2C6C,
                                            &D_803F2C6D);
                                    }
                                }
                                if (sp56 == 254) {
                                    func_80340E08_7524B8(sp57, 0, 0, 0, 0, 0, 0, 0, 20);
                                } else {
                                    func_80340E08_7524B8(
                                        sp57,
                                        D_803A7114_7B87C4[sp56].unk0,
                                        D_803A7114_7B87C4[sp56].unk1,
                                        D_803A7114_7B87C4[sp56].unk2,
                                        1,
                                        (s8) D_803A7114_7B87C4[sp56].unk12.u >> 4,
                                        (s8) (D_803A7114_7B87C4[sp56].unk12.u << 4) >> 4,
                                        (D_803A7114_7B87C4[sp56].unk12.u >> 8) & 1,
                                        phi_t0);
                                }
                            } else {
                                phi_t0 = 40;
                                if ((D_803F2C6C == 2) || (D_803F2C6C == 12) ||
                                    (D_803F2C6C == 33) || (D_803F2C6C == 40)) {
                                    phi_t0 = 30;
                                }
                                if (D_803F2AF8[D_803F2C20].unkA >= 0) {
                                    phi_t0 = D_803F2AF8[D_803F2C20].unkA;
                                    D_803F2AF8[D_803F2C20].unkA = -1;
                                    if (phi_t0 == 0) {
                                        func_80319F58_72B608(
                                            D_803A6D14_7B83C4,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h >> 6,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h >> 6,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h >> 6,
                                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160,
                                            &D_803F2C6C,
                                            &D_803F2C6D);
                                    }
                                }
                                if (sp56 == 254) {
                                    func_80340E08_7524B8(
                                        sp57,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        0,
                                        20);
                                } else {
                                    func_80340E08_7524B8(
                                        sp57,
                                        0,
                                        0,
                                        0,
                                        1,
                                        (s8) D_803A7114_7B87C4[sp56].unk12.u >> 4,
                                        (s8) (D_803A7114_7B87C4[sp56].unk12.u << 4) >> 4,
                                        (D_803A7114_7B87C4[sp56].unk12.u >> 8) & 1,
                                        phi_t0);
                                }
                            }
                            D_803F2C6C = sp57; D_803F2C6D = sp56;
                        } else {
                            D_803F2AC6 = 1;
                        }
                    }
                }
            }
        }
    }

    if ((sp57 == 0xFF) && (sp56 == 0xFF)) {
        func_80319F58_72B608(
            D_803A6D14_7B83C4,
            (s16)D_803F2C2C >> 6,
            (s16)D_803F2C30 >> 6,
            (s16)D_803F2C34 >> 6,
            D_803F2C38,
            &sp57,
            &sp56);
    }
    if (D_803F28E0[D_803F2A98].unkC9 != 0) {
        D_803F28D0[0] = D_803A7114_7B87C4[sp56].unk4;
        D_803F28D0[1] = D_803A7114_7B87C4[sp56].unk6;
        D_803F28D0[2] = D_803A7114_7B87C4[sp56].unk8;
        D_803F28D0[3] = D_803A7114_7B87C4[sp56].unkA;
        D_803F28D0[4] = D_803A7114_7B87C4[sp56].unkC;
        D_803F28D0[5] = D_803A7114_7B87C4[sp56].unkE;
        D_803F28D0[6] = D_803A7114_7B87C4[sp56].unk10;
        D_803F28D0[7] = D_803A7114_7B87C4[sp56].unk12.u;
    } else {
        D_803F28D0[0] = (D_803F28D0[0] & 0xC0) | 0x413F; // GPACK_RGBA5551(64, 32, 248, 1) ?
        D_803F28D0[1] = D_803F28D0[2] = D_803F28D0[3] = D_803F28D0[4] = D_803F28D0[5] = 0x413FU;
        D_803F28D0[6] = D_803A7114_7B87C4[sp56].unk10;
        D_803F28D0[7] = D_803A7114_7B87C4[sp56].unk12.u;
    }
    if (D_803A6CE8_7B8398 > 0) {
        D_803A6CE8_7B8398 -= 1;
        D_803F28D0[0] = (D_803F28D0[0] & 0xC0) | 0x413F;
        D_803F28D0[1] = D_803F28D0[2] = D_803F28D0[3] = D_803F28D0[4] = D_803F28D0[5] = 0x413F;
        D_803F28D0[6] = D_803A7114_7B87C4[sp54].unk10;
        D_803F28D0[7] = D_803A7114_7B87C4[sp54].unk12.u;
    }
    if ((D_803F2AC6 != 0) && (D_803F2AC5 != 0)) {
        D_803F2AA4 = 1;
    }
}

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

void func_803423C4_753A74(s16 cameraID, f32 x, f32 y, f32 z) {
    D_803F28E0[cameraID].unk8 += x;
    D_803F28E0[cameraID].unkC += y;
    D_803F28E0[cameraID].unk10 += z;

    D_803F28E0[cameraID].unk74 += x;
    D_803F28E0[cameraID].unk78 += y;
    D_803F28E0[cameraID].unk7C += z;

    D_803F28E0[cameraID].unk5A += x * (1.0 / 64);
    D_803F28E0[cameraID].unk5C += y * (1.0 / 64);
    D_803F28E0[cameraID].unk5E += z * (1.0 / 64);

    D_803F28E0[cameraID].unk98 += x;
    D_803F28E0[cameraID].unk9C += y;
    D_803F28E0[cameraID].unkA0 += z;

    D_803F28E0[cameraID].unkD0 += x;
    D_803F28E0[cameraID].unkD2 += y;
    D_803F28E0[cameraID].unkD4 += z;
}

void func_80342550_753C00(Camera *arg0) {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    f32 temp_f0;
    f32 temp_f2;    // sp2C
    f32 temp_f12;

    s16 temp_v0_3;
    s16 phi_v1;

    f32 phi_f16;
    f32 phi_f14;
    f32 phi_f12;
    f32 phi_f2;
    f32 phi_f0;

    phi_v1 = -1;

    switch (D_803F28E0[D_803F2A98].unkD6) {
    case 1:
        if ((D_803A6CE4_7B8394 & 8) != 0) {
            phi_v1 = (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 3;
        } else {
            phi_v1 = (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk42 * 3) >> 2;
        }
        break;
    case 2:
        phi_v1 = (D_803F28E0[D_803F2A98].unkCC->unk42 * 3) >> 2;
        break;
    case 3:
        phi_v1 = (D_803F28E0[D_803F2A98].unkCC->unk42 * 3) >> 2;
        break;
    }

    if (phi_v1 != -1) {
        if (arg0->unk62 < phi_v1) {
            arg0->unk62 += 1;
        } else if (phi_v1 < arg0->unk62) {
            arg0->unk62 -= 1;
        }
    }

    switch (arg0->unkD6) {
    case 1:
        arg0->unk98 = ((f64) (f32) *(s32*)&D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h) / 65536;
        arg0->unk9C = ((f64) (f32) *(s32*)&D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h) / 65536;
        arg0->unkA0 = ((f64) (f32) *(s32*)&D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h) / 65536;
        if (arg0->unk67 != 0) {
            phi_f0 = (arg0->unk60 * arg0->unk30 * D_803F2D50.unkE0) / 1200.0;
        } else {
            phi_f0 = 0.0f;
        }
        temp_v0_3 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302;
        phi_f14 = ((D_80152C78[temp_v0_3 & 0xFF] >> 7) * phi_f0) / 600.0;
        phi_f16 = ((D_80152C78[(temp_v0_3 + 0x40) & 0xFF] >> 7) * phi_f0) / 600.0;

        arg0->unkA0 += arg0->unk62;
        arg0->unkC8 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk160;

        if ((D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == VULTURE) ||
            (D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == SEAGULL2)) {
            arg0->unkA0 += D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk308;
        }
        break;
    case 2:
        arg0->unk98 = (f64) (f32) arg0->unkCC->xPos.w / 65536;
        arg0->unk9C = (f64) (f32) arg0->unkCC->zPos.w / 65536;
        arg0->unkA0 = (f64) (f32) arg0->unkCC->yPos.w / 65536;
        arg0->unkA0 += arg0->unk62;
        arg0->unkC8 = (u8) arg0->unkCC->unk160;

        phi_f14 = phi_f16 = 0.0f;

        if (arg0->unkCC == (struct071*)D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            if (arg0->unk67 != 0) {
                phi_f0 = (arg0->unk60 * arg0->unk30 * D_803F2D50.unkE0) / 1200.0;
            } else {
                phi_f0 = 0.0f;

            }
            temp_v0_3 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302;
            phi_f14 = ((D_80152C78[temp_v0_3 & 0xFF] >> 7) * phi_f0) / 600.0;
            phi_f16 = ((D_80152C78[(temp_v0_3 + 0x40) & 0xFF] >> 7) * phi_f0) / 600.0;

            if ((D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == VULTURE) ||
                (D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == SEAGULL2)) {
                arg0->unkA0 += D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk308;
            }
        }
        break;
    case 3:
        arg0->unk98 = ((f64) (f32) arg0->unkCC->xPos.w / 65536.0);
        arg0->unk9C = ((f64) (f32) arg0->unkCC->zPos.w / 65536.0);
        arg0->unkA0 = ((f64) (f32) arg0->unkCC->yPos.w / 65536.0);
        arg0->unkA0 += arg0->unk62;
        arg0->unkC8 = arg0->unkCC->unk160;

        phi_f14 = phi_f16 = 0.0f;
        break;
    case 4:
        arg0->unk98 = arg0->unkD0;
        arg0->unk9C = arg0->unkD2;
        arg0->unkA0 = arg0->unkD4;
        arg0->unkC8 = func_803136FC_724DAC(arg0->unk98, arg0->unk9C, arg0->unkA0);

        phi_f14 = phi_f16 = 0.0f;
        break;
    case 0:
    case 5:
        arg0->unk98 = arg0->unk8;
        arg0->unk9C = arg0->unkC;
        arg0->unkA0 = arg0->unk10;
        arg0->unkC8 = func_803136FC_724DAC(arg0->unk98, arg0->unk9C, arg0->unkA0);

        phi_f14 = phi_f16 = 0.0f;
        break;
    default:
        if (1) {};
#ifdef AVOID_UB
        phi_f16 = 0.0f;
        phi_f14 = 0.0f;
#else
        phi_f16 = sp68; // uninitialised
        phi_f14 = sp6C; // uninitialised
#endif
        break;
    }

    switch (arg0->cameraMode) {
    case 4:
    case 5:
    case 19:
    case 20:
    case 21:
    case 22:
        sp48 = D_803A6CF3_7B83A3[arg0->unk64] * 0.05;
        if ((D_803D2D90.unk0 != 0) || (D_803F2E16 != 0) || (arg0->unk67 == 0)) {
            phi_f14 = phi_f16 = 0.0f;
        }
        phi_f14 = MAX(256.0 - D_803F28E0[D_803F2A98].unk98, phi_f14);
        phi_f14 = MIN(4352.0 - D_803F28E0[D_803F2A98].unk98, phi_f14);

        phi_f2 = phi_f14 - arg0->unkA4;
        sp60 = phi_f16 - arg0->unkA8;

        temp_f12 = ABSF(phi_f2);
        if (temp_f12 <= 2.0) {
            phi_f2 = 0.0f;
        }
        temp_f12 = ABSF(sp60);
        if (temp_f12 <= 2.0) {
            sp60 = 0.0f;
        }

        temp_f12 = phi_f2 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->unkBC)) {
            arg0->unkBC = temp_f12;
            phi_f16 = 0.0f;
        } else {
            phi_f16 = temp_f12 - arg0->unkBC;
        }

        temp_f12 = sp60 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->unkC0)) {
            arg0->unkC0 = temp_f12;
            phi_f14 = 0.0f;
        } else {
            phi_f14 = temp_f12 - arg0->unkC0;
        }

        temp_f0 = sqrtf((phi_f16 * phi_f16) + (phi_f14 * phi_f14));
        if (temp_f0 != 0.0) {
            if (sp48 < temp_f0) {
                arg0->unkBC += (sp48 * phi_f16) / temp_f0;
                arg0->unkC0 += (sp48 * phi_f14) / temp_f0;
            } else {
                arg0->unkBC += phi_f16;
                arg0->unkC0 += phi_f14;
            }
        }
        arg0->unkA4 += arg0->unkBC;
        arg0->unkA8 += arg0->unkC0;
        break;
    case 7:
    case 28:
        phi_f14 *= 0.5;
        phi_f16 *= 0.5;
        /* fallthrough */
    default:
        phi_f14 = MAX(256.0 - D_803F28E0[D_803F2A98].unk98, phi_f14);
        phi_f14 = MIN(4352.0 - D_803F28E0[D_803F2A98].unk98, phi_f14);

        if ((arg0->cameraMode == 25) || (arg0->cameraMode == 30) ||
            (arg0->cameraMode == 228) || (arg0->cameraMode == 29)) {
            phi_f16 = 0.0f;
            phi_f14 = 0.0f;
        }
        sp48 = D_803A6CF3_7B83A3[arg0->unk64] * 0.05;
        phi_f0 = ((phi_f14 * D_803F2C64) + (phi_f16 * D_803F2C68)) / 1.4;
        phi_f12 = (phi_f14 * D_803F2C5C) + (phi_f16 * D_803F2C60);
        if ((D_803D2D90.unk0 != 0) || (D_803F2E16 != 0) ||
            (arg0->cameraMode == 3) || (arg0->cameraMode == 0x11)) {
            phi_f12 = 0.0f;
            phi_f0 = 0.0f;
        }
        sp44 = phi_f0 - arg0->unkAC;
        sp40 = phi_f12 - arg0->unkB0;

        if (ABSF(sp44) <= 2.0) {
            sp44 = 0.0f;
        }
        if (ABSF(sp40) <= 2.0) {
            sp40 = 0.0f;
        }

        temp_f12 = sp44 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->unkB4)) {
            arg0->unkB4 = temp_f12;
            temp_f0 = 0.0f;
        } else {
            temp_f0 = temp_f12 - arg0->unkB4;
        }

        temp_f12 = sp40 / 20.0;
        if (ABSF(temp_f12) <= ABSF(arg0->unkB8)) {
            arg0->unkB8 = temp_f12;
            temp_f2 = 0.0f;
        } else {
            temp_f2 = temp_f12 - arg0->unkB8;
        }

        phi_f0 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
        if (phi_f0 != 0.0) {
            if (sp48 < phi_f0) {
                arg0->unkB4 += (sp48 * temp_f0) / phi_f0;
                arg0->unkB8 += (sp48 * temp_f2) / phi_f0;
            } else {
                arg0->unkB4 += temp_f0;
                arg0->unkB8 += temp_f2;
            }
        }
        arg0->unkAC += arg0->unkB4;
        arg0->unkB0 += arg0->unkB8;
        arg0->unkA4 = (arg0->unkAC * D_803F2C64) + (arg0->unkB0 * D_803F2C5C);
        arg0->unkA8 = (arg0->unkAC * D_803F2C68) + (arg0->unkB0 * D_803F2C60);
        break;
    }
}

void func_80343438_754AE8(void) {
    f32 phi_f2;
    Camera *nextCamera;
    s16 id;

    switch (D_803F2C18[0]) {
    case 0:
        D_803F2C2C = D_803F28E0[D_803F2A98].unk98;
        D_803F2C30 = D_803F28E0[D_803F2A98].unk9C;
        D_803F2C34 = D_803F28E0[D_803F2A98].unkA0;
        D_803F2C38 = D_803F28E0[D_803F2A98].unkC8;
        break;
    case 1:
    case 2:
        phi_f2 = (f32) D_803F2C18[1] / (f32) D_803F2C18[2];
        if (D_803F2C18[0] == 2) {
            if (phi_f2 < 0.5) {
                phi_f2 = 0.0f;
            } else {
                phi_f2 = 1.0f;
            }
        }

        id = D_803F2A98;
        nextCamera = &D_803F28E0[(id + 1) % 2];

        D_803F2C2C = (phi_f2 * D_803F28E0[id].unk98) + ((1.0 - phi_f2) * nextCamera->unk98);
        D_803F2C30 = (phi_f2 * D_803F28E0[id].unk9C) + ((1.0 - phi_f2) * nextCamera->unk9C);
        D_803F2C34 = (phi_f2 * D_803F28E0[id].unkA0) + ((1.0 - phi_f2) * nextCamera->unkA0);
        D_803F2C38 = func_803136FC_724DAC(D_803F2C2C, D_803F2C30, D_803F2C34);
        break;
    }

    if ((D_803F28E0[D_803F2A98].cameraMode == 23) && (D_803F2C18[0] != 1)) {
        D_803F2C2C = D_803F28E0[D_803F2A98].unk8;
        D_803F2C30 = D_803F28E0[D_803F2A98].unkC;
        D_803F2C34 = D_803F28E0[D_803F2A98].unk10;
        D_803F2C38 = func_803136FC_724DAC(D_803F2C2C, D_803F2C30, D_803F2C34);
    }
}

void func_80343720_754DD0(s16 *arg0, s16 *arg1, s16 *arg2) {
    s32 pad;
    s16 sp1A;
    s16 x;
    f32 temp_f0;

    switch (D_803F28E0[D_803F2A98].cameraMode) {
    case 4:
    case 5:
    case 19:
    case 20:
    case 21:
    case 22:
        *arg0 = (D_803F28E0[D_803F2A98].unk74 + SSSV_RAND(256)) - 128.0f;
        *arg1 = (D_803F28E0[D_803F2A98].unk78 + SSSV_RAND(256)) - 128.0f;
        *arg2 = (D_803F28E0[D_803F2A98].unk7C                 ) - 100.0f;
        break;
    default:
        temp_f0 = (s16) SSSV_RAND(1024);
        *arg0 = D_803F28E0[D_803F2A98].unk74 + (D_80204218 * temp_f0);
        *arg1 = D_803F28E0[D_803F2A98].unk78 + (D_8020421C * temp_f0);
        *arg2 = D_803F28E0[D_803F2A98].unk7C + (D_80204220 * temp_f0);
        sp1A = ((temp_f0 * D_803F2D50.unkE0) / 128);

        x = ((SSSV_RAND(512) - 256) * sp1A) >> 9;

        temp_f0 = (s16) ((x << 2) >> 1);
        *arg0 = *arg0 + (temp_f0 * D_8020422C);
        *arg1 = *arg1 + (temp_f0 * D_80204230);
        *arg2 = *arg2 + (temp_f0 * D_80204234) + sp1A;
        break;
    }
}

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
            memset_bytes((u8*)&D_803F2AF8[D_803F2C22], 0, 32);
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

#ifdef NON_MATCHING
void func_80343C44_7552F4(s16 arg0, s16 *arg1, s16 *arg2) {
    *arg1 = D_803A7B3C_7B91EC[arg0][0];
    *arg2 = D_803A7B3C_7B91EC[arg0][1];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343C44_7552F4.s")
#endif

void func_80343C74_755324(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4) {
    memset_bytes((u8*)D_803F2AD8, 0, sizeof(D_803F2AD8));
    D_803F2AD8[0].unk18 = 1;
    D_803F2AD8[0].unkA = 40;
    D_803F2AD8[0].unk12 = arg0;
    D_803F2AD8[0].unk17 = arg1;
    D_803F2AD8[0].unk19 = arg2;
    D_803F2AD8[0].unk1A = arg3;
    D_803F2AD8[0].unk1B = arg4;
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

    D_803F28E0[D_803F2A98].cameraMode = 27;
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
        if ((D_803F2C18[0] != 0) && (D_803F28E0[D_803F2A98].cameraMode == 30)) {
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
                (D_803A7114_7B87C4[i].unk12.u == D_803A7114_7B87C4[j].unk12.u)) {

                D_803A6D14_7B83C4[i].unk7 = D_803A6D14_7B83C4[j].unk7;
                // break loop
                j = 128;
            }
        }
    }
}

s16 func_80344158_755808(s16 arg0) {
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
