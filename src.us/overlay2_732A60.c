#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803213B0_732A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803215DC_732C8C.s")

Animal *func_803218D8_732F88(Animal *arg0) {
    if (arg0 != 0) {
        D_803D552C->unk324 = arg0->state;
        D_803D552C->unk320 = arg0;
        arg0->state = 30;
        arg0->unk4C.unk25 = 1;
        return arg0;
    }
    return NULL;
}

void func_80321920_732FD0(Animal *arg0, s16 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg0->xVelocity.h = D_803D5530->xVelocity.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8);
        arg0->zVelocity.h = D_803D5530->zVelocity.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8);
        arg0->yVelocity.h = (D_803D5530->yVelocity.h + arg2) - 1;
        arg0->unk4C.unk25 = 1;
        arg0->unk160 = D_803D5530->unk160;
        if (arg0->unk160 != 0) {
            if (((arg0->unk160 == 1) || (arg0->unk160 == 2)) && (D_803C0740[arg0->xPos >> 6][arg0->zPos >> 6].unk3 == 0)) {
                arg0->unk160 = 0U;
            }
        } else {
            if (D_803C0740[arg0->xPos >> 6][arg0->zPos >> 6].unk3 != 0) {
                if ((func_80310F58_722608(arg0->xPos, arg0->zPos) >> 0x10) < arg0->yPos) {
                    arg0->unk160 = 2U;
                } else {
                    arg0->unk160 = 1U;
                }
            }
        }

        arg0->state = D_803D552C->unk324;
        D_803D552C->unk320 = 0;

        if (arg0->yRotation < 45) {
            arg0->yRotation = 0;
        } else if (arg0->yRotation < 135) {
            arg0->yRotation = 90;
        } else if (arg0->yRotation < 225) {
            arg0->yRotation = 180;
        } else if (arg0->yRotation < 315) {
            arg0->yRotation = 270;
        } else {
            arg0->yRotation = 0;
        }
        if (arg0->unk16C->unk80.bit == 0) {
            if ((arg0->unk163 & 0x20) == 0) {
                arg0->unk163 &= 0xFFF7;
            }
        }
    }
}

void func_80321B70_733220(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_t0;

    Animal *a = D_803D552C->unk320;
    if (a != 0) {
        a->xPos = (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8) + (D_803D5530->xPos + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8));
        a->zPos = D_803D5530->zPos + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8) - (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->yPos = D_803D5530->yPos + arg2;
        a->unk160 = D_803D5530->unk160;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;

        temp_t0 = D_803D552C->unk302 - D_803D552C->unk304;
        if (a->unk16C->unk80.bit != 0) {
            a->yRotation = ((a->yRotation + temp_t0) & 0xFF);
            a->unk302 = a->yRotation;
        } else {
            temp_t0 = (temp_t0 * 360) / 256;
            a->yRotation += temp_t0;
            while (a->yRotation < 0) {
                a->yRotation += 360;
            }
            while (a->yRotation >= 360) {
                a->yRotation -= 360;
            }
        }
    }
}

void func_80321D74_733424(s16 arg0, s16 arg1) {
    Animal *a = D_803D552C->unk320;
    if (a != NULL) {
        a->xPos = D_803D5530->xPos + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->zPos = D_803D5530->zPos + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8);
        a->yPos = D_803D5530->yPos + arg1;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80321E60_733510.s")
// long way to go here
// void func_80321E60_733510(u8 id, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
//     s32 sp38;
//     s32 sp34;
//     s32 sp30;
//
//     s32 zpos;
//     s32 xpos;
//
//     s32 temp_t7;
//     s32 temp_t7_2;
//     struct071 *obj;
//
//     temp_t7 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7;
//     temp_t7_2 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 7;
//     xpos = D_803D5530->xPos + (((temp_t7 * arg2) + (arg1 * temp_t7_2)) >> 8);
//     zpos = D_803D5530->zPos + (((arg1 * temp_t7) - (temp_t7_2 * arg2)) >> 8);
//     sp38 = temp_t7_2 * (D_80152C78[(arg5 + 64) & 0xFF] >> 7) * arg4;
//     sp34 = temp_t7 * (D_80152C78[(arg5 + 64) & 0xFF] >> 7) * arg4;
//     sp30 = ((D_80152C78[arg5 & 0xFF] >> 7) * arg4) << 8;
//     obj = func_802C9564_6DAC14(
//         arg0 & 0xffff,
//         xpos,
//         zpos,
//         D_803D5530->yPos + arg3,
//         D_803D5530->xVelocity.w + sp38,
//         D_803D5530->zVelocity.w + sp34,
//         D_803D5530->yVelocity.w + sp30,
//         0,
//         0,
//         0);
//     if (obj != 0) {
//         D_803D5530->xVelocity.w -= sp38 >> arg6;
//         D_803D5530->zVelocity.w -= sp34 >> arg6;
//         obj->unk15C = 15;
//         obj->unk168 = D_803D5530;
//         if (arg7 != 0) {
//             obj->unk15E = arg7;
//         }
//     }
// }

// how to match these functions??
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322064_733714.s")
// void func_80322064_733714(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8) {
//     s32 sp38;
//     s32 sp34;
//     s32 temp_lo;
//     s32 temp_t6;
//     s32 temp_t8;
//     struct071 *obj;
//
//     temp_t8 = D_80152C78[(arg5 + 64) & 0xFF] >> 7;
//     temp_t6 = D_80152C78[arg5 & 0xFF] >> 7;
//     sp38 = temp_t6 * (D_80152C78[(arg6 + 0x40) & 0xFF] >> 7) * arg4;
//     sp34 = temp_t8 * (D_80152C78[(arg6 + 0x40) & 0xFF] >> 7) * arg4;
//     obj = func_802C9564_6DAC14(
//         arg0,
//         D_803D5530->xPos + (((temp_t8 * arg2) + (arg1 * temp_t6)) >> 8),
//         D_803D5530->zPos + (((arg1 * temp_t8) - (temp_t6 * arg2)) >> 8),
//         D_803D5530->yPos + arg3,
//         D_803D5530->xVelocity.w + sp38,
//         D_803D5530->zVelocity.w + sp34,
//         D_803D5530->yVelocity.w + (((D_80152C78[arg6 & 0xFF] >> 7) * arg4) << 8),
//         0,
//         0,
//         0);
//     if (obj != NULL) {
//         D_803D5530->xVelocity.w -= (sp38 >> arg7);
//         D_803D5530->zVelocity.w -= (sp34 >> arg7);
//         obj->unk15C = 15;
//         obj->unk168 = (void *) D_803D5530;
//         if (arg8 != 0) {
//             obj->unk15E = arg8;
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_8032225C_73390C.s")
// another junk function
// void func_8032225C_73390C(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, s16 arg8) {
//     s32 temp_t7;
//     s32 temp_t7_2;
//     s32 xpos;
//     s32 zpos;
//     s16 idx;
//
//     struct071 *obj;
//
//     idx = D_803D552C->unk302;
//     temp_t7 = D_80152C78[(idx + 64) & 0xFF] >> 7;
//     temp_t7_2 = D_80152C78[idx & 0xFF] >> 7;
//
//     xpos = D_803D5530->xPos + (((temp_t7 * arg2) + (arg1 * temp_t7_2)) >> 8);
//     zpos = D_803D5530->zPos + (((arg1 * temp_t7) - (temp_t7_2 * arg2)) >> 8);
//
//     obj = func_802C9564_6DAC14(
//         arg0 & 0xffff,
//         xpos & 0xFFFFFFFFFFFFFFFFu,
//         zpos & 0xFFFFFFFFFFFFFFFFu,
//         D_803D5530->yPos + arg3,
//         D_803D5530->xVelocity.w + arg4,
//         D_803D5530->zVelocity.w + arg5,
//         D_803D5530->yVelocity.w + arg6,
//         0,
//         0,
//         0);
//
//     if (obj != NULL) {
//         D_803D5530->xVelocity.w -= arg4 >> arg7;
//         D_803D5530->zVelocity.w -= arg5 >> arg7;
//         obj->unk168 = D_803D5530;
//         if (arg8 != 0) {
//             obj->unk15E = arg8;
//         }
//     }
// }

void recoil(s16 arg0) {
    s32 temp_t2 = D_80152C78[(u8)D_803D552C->unk302] >> 7;
    s32 temp_t7 = D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7;

    if (arg0 < 0) {
        D_803D5530->xVelocity.w += temp_t2 << (8 - arg0);
        D_803D5530->zVelocity.w += temp_t7 << (8 - arg0);
    } else {
        D_803D5530->xVelocity.w -= temp_t2 << (arg0 + 8);
        D_803D5530->zVelocity.w -= temp_t7 << (arg0 + 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803224C4_733B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322A58_734108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322D68_734418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80323040_7346F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803233A0_734A50.s")
