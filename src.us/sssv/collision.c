#include <ultra64.h>
#include "common.h"

s32 func_802B6F6C_6C861C(void);
s32 func_802B6B5C_6C820C(void);
s32 func_802B6088_6C7738(void);
s32 func_802B6948_6C7FF8(void);

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B4D20_6C63D0.s")

s32 func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, s32 (**arg2)(), u8 *arg3) {
    struct035 *a0; // arg0
    struct035 *a1; // arg1
    s32 res = 0;

    *arg2 = NULL;
    a0 = arg0->unk16C;
    if (a0->unk15 == 4) {
      a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            res = 6;
            *arg2 = func_802B750C_6C8BBC;
            *arg3 = 0;
        } else if (a1->unk18 != 0) {
            if (arg1->unkD0.m[0][0] != 0) {
                res = 7;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 0;
            } else {
                res = 7;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 0;
            }
        } else {
            if (arg1->unkD0.m[0][0] != 0) {
                res = 5;
                *arg2 = func_802B6B5C_6C820C;
                *arg3 = 1;
            }
        }
    } else if (a0->unk18 != 0) {
        a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            if (arg1->unkD0.m[0][0] != 0) {
                res = 7;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 1;
            } else {
                res = 8;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 1;
            }
        } else if (a1->unk18 != 0) {
            if ((arg0->unkD0.m[0][0] != 0) && (arg1->unkD0.m[0][0] != 0)) {
                res = 1;
                *arg2 = func_802B6088_6C7738;
                if ((u32) arg0 < (u32) arg1) {
                    *arg3 = 0;
                } else {
                    *arg3 = 1;
                }
            } else {
                if (arg0->unkD0.m[0][0] != 0) {
                    res = 1;
                    *arg2 = func_802B6088_6C7738;
                    *arg3 = 0;
                } else {
                    res = 9;
                    *arg2 = func_802B75B4_6C8C64;
                    *arg3 = 0;
                }

            }
        } else {
            res = 0;
            if (arg1->unkD0.m[0][0] != NULL) {
                res = 2;
                *arg2 = func_802B6088_6C7738;
                *arg3 = 1;
            }
        }
    } else {
        res = 0;
        if (arg0->unkD0.m[0][0] != NULL) {
            a1 = arg1->unk16C;
            if (a1->unk15 == 4) {
                res = 4;
                *arg2 = func_802B6B5C_6C820C;
                *arg3 = 0;
            } else if (a1->unk18 != 0) {
                res = 1;
                *arg2 = func_802B6088_6C7738;
                *arg3 = 0;
            } else {
                res = 0;
                if (arg1->unkD0.m[0][0] != NULL) {
                    res = 3;
                    *arg2 = func_802B6948_6C7FF8;
                    *arg3 = 0;
                }
            }
        }
    }

    if (res == 0) {
        *arg2 = func_802B6948_6C7FF8;
        *arg3 = 0;
    }
    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6088_6C7738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6948_6C7FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6B5C_6C820C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6F6C_6C861C.s")

#ifdef NON_MATCHING // JUSTREG
s32 func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    u8 check0;
    u8 check1;
    s32 velocity0;
    s32 velocity1;

    velocity0 = arg0->unk30 + arg1->unk30;
    velocity1 = arg0->unk32 + arg1->unk32;

    check0 = ((arg4 - velocity0) < arg7) && ((arg4 + velocity0) > arg7) &&
             ((arg5 - velocity1) < arg8) && ((arg5 + velocity1) > arg8);

    check1 = ((arg9 - arg0->unk42) < arg6) && ((arg6 - arg1->unk42) < arg9);

    return (u8) (check0 && check1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B750C_6C8BBC.s")
#endif

s32 func_802B75B4_6C8C64(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 0;
}

// broken expansion pak function
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B75CC_6C8C7C.s")
// s32 func_802B75CC_6C8C7C(Animal *arg0, Animal *arg1, s32 (**arg2)(), s32 arg3, s32 arg4, s8 *arg5, u16 arg6) {
//
//     s32 sp74;
//     s32 *temp_s2;
//     s32 *temp_s2_2;
//     s32 *temp_s3;
//     s32 *temp_s3_2;
//     s32 *temp_s4;
//     s32 *temp_s4_2;
//     Animal *temp_v0_3;
//     u16 temp_v0;
//     u8 temp_v0_2;
//
//     struct065 *phi_s5;
//
//     Animal *temp_v1;
//
//     s32 phi_v0;
//     u8 phi_v1;
//     s32 *phi_s2;
//     s32 *phi_s3;
//     s32 *phi_s4;
//     u8 phi_v1_2;
//     Animal *phi_v0_4;
//     Animal *phi_v0_5;
//
//     for (phi_s5 = &D_803DA110[(s32)arg0->unk114]; phi_s5 != NULL; phi_s5 = phi_s5->next) {
//
//         temp_v1 = phi_s5->unk8;
//         if ((arg0 != temp_v1) && (arg0 != arg1) && (((D_803B1BAC[temp_v1->unk16C->unk2]) & (1 << (0xF - arg0->unk16C->unk2))) != 0)) {
//
//             if ((ABS(temp_v1->xPos.h - (s16) arg2) < (temp_v1->unk34 + arg0->unk34)) &&
//                 (ABS(temp_v1->zPos.h - (s16) arg3) < (temp_v1->unk34 + arg0->unk34)) &&
//                 (ABS((temp_v1->yPos.h + (temp_v1->unk42 >> 1)) - arg0->unk42 >> 1) < (temp_v1->unk36 + arg0->unk36)) &&
//                 (arg0 != temp_v1->unk68) && (temp_v1 != arg0->unk68) &&
//                 ((arg0 != temp_v1->unk70) || (arg0->unk16C->unk15 != 4)) &&
//                 ((temp_v1 != arg0->unk70) || (temp_v1->unk16C->unk15 != 4)) &&
//                 (temp_v1->state != 0x1E) && (arg0->state != 0x1E) &&
//                 (temp_v1->state != 0x1F) && (arg0->state != 0x1F) &&
//                 ((temp_v1->unk15C == 0) || (arg0 != temp_v1->unk168)) && ((arg0->unk15C == 0) || (temp_v1 != arg0->unk168)) &&
//                 ((arg6 == 0) || ((s32) temp_v1->unk16C->unk0 < OB_TYPE_ANIMAL_OFFSET))) {
//
//                 func_802B5E48_6C74F8(temp_v1, arg0, &D_803D60D0, D_803D60D4);
//
//                 if (D_803D60D4 != 0) {
//                     temp_s2 = temp_v1->xPos.h;
//                     temp_s3 = temp_v1->zPos.h;
//                     temp_s4 = temp_v1->yPos.h;
//                     phi_s2 = temp_s2;
//                     phi_s3 = temp_s3;
//                     phi_s4 = temp_s4;
//                     if (func_803D60D0(arg0, temp_v1, &D_803D60D8, &D_803D60DC, arg2, arg3, arg4, *temp_s2, *temp_s3, *temp_s4) == 0) {
//                         // phi_v1 = D_803D60D4;
//                         goto block_34;
//                     }
//                     goto block_36;
//                 }
// block_34:
//                 if ((D_803D60D4 == 0) && (temp_s2_2 = temp_v1->xPos.h, temp_s3_2 = temp_v1->zPos.h, temp_s4_2 = temp_v1->yPos.h, phi_s2 = temp_s2_2, phi_s3 = temp_s3_2, phi_s4 = temp_s4_2, (func_803D60D0(temp_v1, arg0, &D_803D60D8, &D_803D60DC, *temp_s2_2, *temp_s3_2, *temp_s4_2, arg2, arg3, arg4) != 0))) {
// block_36:
//                     if ((arg0->unk16C->unk2 == 9) || (temp_v1->unk16C->unk2 == 9) ||
//                         (arg0->unk16C->unk2 == 8) || (temp_v1->unk16C->unk2 == 8)) {
//                         break;
//                     }
//
//                     sp74 = arg4 + D_803A05B4_7B1C64;
//                     if (D_803D60D4 != 0) {
//                         if (func_803D60D0(arg0, temp_v1, D_803D60D8, &D_803D60DC, arg2, arg3, arg4, *phi_s2, *phi_s3, *phi_s4) == 0) {
//                             goto block_44;
//                         }
//                         goto block_46;
//                     }
// block_44:
//                     if ((D_803D60D4 == 0) && (func_803D60D0(temp_v1, arg0, &D_803D60D8, &D_803D60DC, *phi_s2, *phi_s3, *phi_s4, arg2, arg3, sp74) != 0)) {
// block_46:
//                         *arg5 = 1;
//                         phi_v0_5 = &D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//                         // if its a TV Screen
//                         if ((arg0 == phi_v0_5) && (temp_v1->unk16C->unk0 == 242)) {
//                             func_8038F5F8_7A0CA8(temp_v1);
//                             // phi_v0_5 = &D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//                         }
//                         // if its a TV Screen
//                         if ((temp_v1 == phi_v0_5) && (arg0->unk16C->unk0 == 242)) {
//                             func_8038F5F8_7A0CA8(arg0);
//                         }
//                         func_802FD674_70ED24(arg0, temp_v1);
//                         return 1;
//                     } else {
//                         *arg5 = 0;
//                         phi_v0_4 = &D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//                         // phi_v0_4 = temp_v0_3;
//                         // if its a TV Screen
//                         if ((arg0 == phi_v0_4) && (temp_v1->unk16C->unk0 == 242)) {
//                             func_8038F5F8_7A0CA8(temp_v1);
//                             // phi_v0_4 = &D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//                         }
//                         // if its a TV Screen
//                         if ((temp_v1 == phi_v0_4) && (arg0->unk16C->unk0 == 242)) {
//                             func_8038F5F8_7A0CA8(arg0);
//                         }
//                         func_802FD674_70ED24(arg0, temp_v1);
//                         return 1;
//                     }
//                 }
//             }
//         }
//     }
//
//     return 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B7BC8_6C9278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B8304_6C99B4.s")
// plenty more to work through
// void func_802B8304_6C99B4(Animal *arg0, Animal *arg1) {
//     f32 sp2C;
//     f32 sp28;
//     f32 sp24;
//     f32 sp20;
//     f32 sp1C;
//     f32 temp_f0;
//     f32 temp_f0_2;
//     f32 temp_f0_3;
//     f32 temp_f0_4;
//     f32 temp_f12;
//     f32 temp_f14;
//     f32 temp_f16;
//     f32 temp_f16_2;
//     f32 temp_f2;
//     f32 temp_f4;
//     f32 temp_ret;
//     f64 temp_f0_5;
//     u16 temp_v0_2;
//     u16 temp_v0_3;
//     struct035 *temp_v0;
//     s32 phi_v1;
//     s32 phi_v1_2;
//     f32 phi_f2;
//     f32 phi_f14;
//     u16 phi_v1_3;
//     u16 phi_v1_4;
//     f32 phi_f16;
//     f32 phi_f12;
//
//     temp_v0 = arg1->unk16C;
//     if (temp_v0->unk18 != 0) {
//         if (arg1->unk40 < 2048) {
//             phi_v1 = 2048;
//         } else {
//             phi_v1 = (s16) arg1->unk40;
//         }
//         if ((arg0->yPos.h + (arg0->unk42 >> 1)) < (arg1->yPos.h + (arg1->unk42 >> 1))) {
//             if (phi_v1 >= 2048) {
//                 phi_v1 = 2048;
//             }
//         }
//         arg0->xVelocity -= (D_803D60DC->unk0 * phi_v1) >> 0xB;
//         arg0->zVelocity -= (D_803D60DC->unk4 * phi_v1) >> 0xB;
//         arg0->yVelocity -= (D_803D60DC->unk8 * phi_v1) >> 0xB;
//         return;
//     }
//     temp_f2 = (arg0->xPos.h - arg1->xPos.h) / 65536.0;
//     temp_f14 = (arg0->zPos.h - arg1->zPos.h) / 65536.0;
//     phi_f2 = temp_f2;
//     phi_f14 = temp_f14;
//     if (temp_v0->unk15 == 4) {
//         if (temp_f2 < 0.0f) {
//             temp_f0 = (arg1->unk30 - 2) + temp_f2;
//             if (temp_f0 > 0.0f) {
//                 phi_f2 = 0.0f;
//             } else {
//                 phi_f2 = temp_f0;
//             }
//         } else {
//             temp_f0_2 = (f32) (arg1->unk30 - 2);
//             if (temp_f2 < temp_f0_2) {
//                 phi_f2 = 0.0f;
//             } else {
//                 phi_f2 = temp_f2 - temp_f0_2;
//             }
//         }
//         if (temp_f14 < 0.0f) {
//             temp_f0_3 = (f32) (arg1->unk32 - 2) + temp_f14;
//             if (temp_f0_3 > 0.0f) {
//                 phi_f14 = 0.0f;
//             } else {
//                 phi_f14 = temp_f0_3;
//             }
//         } else {
//             temp_f0_4 = (f32) (arg1->unk32 - 2);
//             if (temp_f14 < temp_f0_4) {
//                 phi_f14 = 0.0f;
//             } else {
//                 phi_f14 = temp_f14 - temp_f0_4;
//             }
//         }
//     }
//
//     sp24 = sqrtf((phi_f2 * phi_f2) + (phi_f14 * phi_f14));
//     temp_f16 = (arg0->xVelocity - arg1->xVelocity) / 65536.0;
//     temp_f4 = (arg0->zVelocity - arg1->zVelocity) / 65536.0;
//     temp_ret = sqrtf((temp_f16 * temp_f16) + (temp_f4 * temp_f4));
//     if (temp_ret < 4.0) {
//         if (sp24 != 0.0) {
//             if (arg1->unk40 < 0x800) {
//                 phi_v1_3 = 0x800U;
//             } else {
//                 phi_v1_3 = arg1->unk40;
//             }
//             temp_f0_5 = sp24 * 2048.0f;
//             temp_f16_2 = (f32) (((f64) phi_v1_3 * ((f64) phi_f2 * D_803BBF48)) / temp_f0_5);
//
//             if (arg1->unk40 < 0x800) {
//                 phi_v1_4 = 0x800U;
//             } else {
//                 phi_v1_4 = arg1->unk40;
//             }
//             temp_f12 = (f32) (((f64) phi_v1_4 * ((f64) phi_f14 * D_803BBF50)) / temp_f0_5);
//             phi_f16 = temp_f16_2;
//             phi_f12 = temp_f12;
//             if (((temp_f16 * temp_f16_2) + (temp_f4 * temp_f12)) < 0.0f) {
//                 arg0->xVelocity = arg1->xVelocity;
//                 arg0->zVelocity = arg1->zVelocity;
//             }
//         } else {
//             phi_f16 = D_803BBF58;
//             phi_f12 = D_803BBF5C;
//         }
//         arg0->xVelocity += (s32) ((s32) ((f64) phi_f16 * 65536.0));
//         arg0->zVelocity += (s32) ((s32) ((f64) phi_f12 * 65536.0));
//     }
// }
