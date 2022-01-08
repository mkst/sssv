#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DB610/func_802C9F60_6DB610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DB610/func_802CA8D4_6DBF84.s")

void func_802CAACC_6DC17C(Animal *arg0, s16 arg1) {
    arg0->yVelocity.w = (arg0->yVelocity.w * 7) / 8;
    arg0->yVelocity.w -= ((arg0->yPos + (arg0->unk42 >> 1)) - arg1) << 10;
}

void func_802CAB20_6DC1D0(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    s16 phi_a0;
    s16 phi_a1;
    s16 phi_a2;
    s16 sp38;

    s16 temp_v1_4;
    s8 phi_t1;

    phi_t1 = 0;

    arg0->unk65 = arg1->unk65 = 0U;

    if ((arg0->unk16C->unk80.bit) && (!arg1->unk16C->unk80.bit)) {
        if ((ABS(arg5) < 9) && (ABS(arg6) < 9) && (ABS(arg7) < 9)) {
            phi_t1 = 1;
        }
    }

    if ((arg1->unk16C->unk80.bit) && (!arg0->unk16C->unk80.bit)) {
        if ((ABS(arg2) < 9) && (ABS(arg3) < 9) && (ABS(arg4) < 9)) {
            phi_t1 = 1;
        }
    }

    if (((arg0->unk16C->unk80.bit) && (!arg1->unk16C->unk80.bit)) || ((arg1->unk16C->unk80.bit) && (!arg0->unk16C->unk80.bit))) {
        if ((ABS(arg2 - arg5) < 9) && (ABS(arg3 - arg6) < 9) && (ABS(arg4 - arg7) < 9)) {
            phi_t1 = 1;
        }
    }

    if (((arg0->unk16C->unk80.bit) && (arg1->unk16C->unk80.bit)) &&
        (((arg0->unk366 == 5)) || (arg0->unk366 == 2) || ((arg1->unk366 == 5)) || (arg1->unk366 == 2))) {
        phi_t1 = 1;
    }

    phi_a2 = ABS(arg0->xVelocity.h - arg2);
    phi_a1 = ABS(arg0->zVelocity.h - arg3);
    phi_a0 = ABS(arg0->yVelocity.h - arg4);
    if (phi_t1 == 0) {
        sp38 = (phi_a2 + phi_a1 + phi_a0) << 8;
        temp_v1_4 = arg1->unk16C->unk8C;
        if ((arg1->unk16C->unk0 == 273) && (arg1 != D_801DDD8C[gCurrentAnimalIndex].unk0)) {
            temp_v1_4 /= 5;
        }
        sp38 = ((sp38 * temp_v1_4) >> 4) / 1024;
    } else {
        sp38 = 0;
    }

    if ((arg1->unk16C->unk80.bit) &&
        ((arg1->unk16C->unk9C == DESERT_FOX_ATTACKING) ||
         (arg1->unk16C->unk9C == RACING_TORTOISE_ATTACKING) ||
         (arg1->unk16C->unk9C == POLAR_BEAR_DEFENDING) ||
         (arg1->unk16C->unk9C == HARD_MOUSE))) {
        func_802B3B48_6C51F8(arg0, arg1, &sp38);
        if ((arg0->unk16C->unk80.bit) && (arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0)) {
            arg0->unk2EB += 1;
        }
    }
    if (arg0->unk16C->unk80.bit) {
        sp38 += func_802B3C9C_6C534C(arg1->unk16C->unk8D, arg0);
    } else {
        sp38 += arg1->unk16C->unk8D;
    }

    func_802B38FC_6C4FAC(arg0, sp38, -1, 1);
    arg0->unk65 += sp38;

    if (0) { } // debug?

    phi_a2 = ABS(arg1->xVelocity.h - arg5);
    phi_a1 = ABS(arg1->zVelocity.h - arg6);
    phi_a0 = ABS(arg1->yVelocity.h - arg7);
    if (phi_t1 == 0) {
        sp38 = (phi_a2 + phi_a1 + phi_a0) << 8;
        temp_v1_4 = arg0->unk16C->unk8C;
        if ((arg0->unk16C->unk0 == 273) && (arg0 != D_801DDD8C[gCurrentAnimalIndex].unk0)) {
            temp_v1_4 = temp_v1_4 / 5;
        }
        sp38 = ((sp38 * temp_v1_4) >> 4) / 1024;
    } else {
        sp38 = 0;
    }

    if ((arg0->unk16C->unk80.bit) &&
        ((arg0->unk16C->unk9C == DESERT_FOX_ATTACKING) ||
         (arg0->unk16C->unk9C == RACING_TORTOISE_ATTACKING) ||
         (arg0->unk16C->unk9C == POLAR_BEAR_DEFENDING) ||
         (arg0->unk16C->unk9C == HARD_MOUSE))) {
        func_802B3B48_6C51F8(arg1, arg0, &sp38);
        if ((arg1->unk16C->unk80.bit) && (arg0 == D_801DDD8C[gCurrentAnimalIndex].unk0)) {
            arg1->unk2EB += 1;
        }
    }
    if (arg1->unk16C->unk80.bit) {
        sp38 += func_802B3C9C_6C534C(arg0->unk16C->unk8D, arg1);
    } else {
        sp38 += arg0->unk16C->unk8D;
    }
    func_802B38FC_6C4FAC(arg1, sp38, -1, 1);
    arg1->unk65 += sp38;
}

void func_802CB180_6DC830(Animal *arg0) {
    if (func_80298E08_6AA4B8(arg0->xPos, arg0->zPos)) {
        s8 tmp;
        s16 phi_a1;
        s16 pad;
        s16 temp_t7;
        s16 xPos = arg0->xPos >> 6;
        s16 zPos = arg0->zPos >> 6;
        temp_t7 = D_803C0740[xPos][zPos].unk6 << 2;

        if (temp_t7 < arg0->yPos) {
            phi_a1 = 0;
        } else {
            if ((arg0->yPos + arg0->unk42) < temp_t7) {
                phi_a1 = 64;
            } else {
                phi_a1 = ((temp_t7 - arg0->yPos) << 6) / arg0->unk42;
            }
        }

        tmp = (s8)((arg0->unk4C.pad0 * phi_a1) >> 6);
        if (tmp >= (arg0->unk4C.pad8 + 3)) {
            arg0->unk4C.pad8++;
            if (D_803C0740[xPos][zPos].unk6) {
                D_803C0740[xPos][zPos].unk6++;
            } else {
                D_803C0740[xPos][zPos].unk6 = (D_803C0740[xPos][zPos].unk0 << 1) + 1;
            }
            if (func_80298E08_6AA4B8(xPos + 1, zPos)) {
                arg0->unk4C.pad8++;
                if (D_803C0740[xPos + 1][zPos].unk6) {
                    D_803C0740[xPos + 1][zPos].unk6++;
                }
            }
            if (func_80298E08_6AA4B8(xPos, zPos + 1)) {
                arg0->unk4C.pad8++;
                if (D_803C0740[xPos][zPos + 1].unk6) {
                    D_803C0740[xPos][zPos + 1].unk6++;
                }
            }
        }
    }
}
