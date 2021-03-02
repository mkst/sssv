#include <ultra64.h>
#include "common.h"


void func_802B6F6C_6C861C(void);
void func_802B6B5C_6C820C(void);
void func_802B6088_6C7738(void);
void func_802B6948_6C7FF8(void);

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B4D20_6C63D0.s")

s32 func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, s32 *arg2, u8 *arg3) {
    struct035 *temp_v0;   // arg0
    struct035 *temp_v0_2; // arg1
    s32 res = 0;

    *arg2 = NULL;
    temp_v0 = arg0->unk16C;
    if (temp_v0->unk15 == 4) {
      temp_v0_2 = arg1->unk16C;
        if (temp_v0_2->unk15 == 4) {
            res = 6;
            *arg2 = &func_802B750C_6C8BBC;
            *arg3 = 0;
        } else if (temp_v0_2->unk18 != 0) {
            if (arg1->unkD0 != NULL) {
                res = 7;
                *arg2 = &func_802B6F6C_6C861C;
                *arg3 = 0;
            } else {
                res = 7;
                *arg2 = &func_802B6F6C_6C861C;
                *arg3 = 0;
            }
        } else {
            if (arg1->unkD0 != NULL) {
                res = 5;
                *arg2 = &func_802B6B5C_6C820C;
                *arg3 = 1;
            }
        }
    } else if (temp_v0->unk18 != 0) {
        temp_v0_2 = arg1->unk16C;
        if (temp_v0_2->unk15 == 4) {
            if (arg1->unkD0 != NULL) {
                res = 7;
                *arg2 = &func_802B6F6C_6C861C;
                *arg3 = 1;
            } else {
                res = 8;
                *arg2 = &func_802B6F6C_6C861C;
                *arg3 = 1;
            }
        } else if (temp_v0_2->unk18 != 0) {
            if ((arg0->unkD0 != NULL) && (arg1->unkD0 != NULL)) {
                res = 1;
                *arg2 = &func_802B6088_6C7738;
                if ((u32) arg0 < (u32) arg1) {
                    *arg3 = 0;
                } else {
                    *arg3 = 1;
                }
            } else {
                if (arg0->unkD0 != NULL) {
                    res = 1;
                    *arg2 = &func_802B6088_6C7738;
                    *arg3 = 0;
                } else {
                    res = 9;
                    *arg2 = &func_802B75B4_6C8C64;
                    *arg3 = 0;
                }

            }
        } else {
            res = 0;
            if (arg1->unkD0 != NULL) {
                res = 2;
                *arg2 = &func_802B6088_6C7738;
                *arg3 = 1;
            }
        }
    } else {
        res = 0;
        if (arg0->unkD0 != NULL) {
            temp_v0_2 = arg1->unk16C;
            if (temp_v0_2->unk15 == 4) {
                res = 4;
                *arg2 = &func_802B6B5C_6C820C;
                *arg3 = 0;
            } else if (temp_v0_2->unk18 != 0) {
                res = 1;
                *arg2 = &func_802B6088_6C7738;
                *arg3 = 0;
            } else {
                res = 0;
                if (arg1->unkD0 != NULL) {
                    res = 3;
                    *arg2 = &func_802B6948_6C7FF8;
                    *arg3 = 0;
                }
            }
        }
    }

    if (res == 0) {
        *arg2 = &func_802B6948_6C7FF8;
        *arg3 = 0;
    }
    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6088_6C7738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6948_6C7FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6B5C_6C820C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6F6C_6C861C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B750C_6C8BBC.s")
// JUSTREG!
// u8 func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
//     u8 check0;
//     u8 check1;
//     s32 velocity0;
//     s32 velocity1;
//
//     velocity0 = arg0->unk30 + arg1->unk30;
//     velocity1 = arg0->unk32 + arg1->unk32;
//
//     check0 = ((arg4 - velocity0) < arg7) && ((arg4 + velocity0) > arg7) &&
//              ((arg5 - velocity1) < arg8) && ((arg5 + velocity1) > arg8);
//
//    check1 = ((arg9 - arg0->unk42) < arg6) && ((arg6 - arg1->unk42) < arg9);
//
//     return check0 && check1;
// }

s32 func_802B75B4_6C8C64(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B75CC_6C8C7C.s")

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
//         if ((arg0->yPos + (arg0->unk42 >> 1)) < (arg1->yPos + (arg1->unk42 >> 1))) {
//             if (phi_v1 >= 2048) {
//                 phi_v1 = 2048;
//             }
//         }
//         arg0->xVelocity -= (D_803D60DC->unk0 * phi_v1) >> 0xB;
//         arg0->zVelocity -= (D_803D60DC->unk4 * phi_v1) >> 0xB;
//         arg0->yVelocity -= (D_803D60DC->unk8 * phi_v1) >> 0xB;
//         return;
//     }
//     temp_f2 = (arg0->xPos - arg1->xPos) / 65536.0;
//     temp_f14 = (arg0->zPos - arg1->zPos) / 65536.0;
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
