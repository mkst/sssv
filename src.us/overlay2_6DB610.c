#include <ultra64.h>
#include "common.h"

void func_802CB180_6DC830(Animal *arg0);

void func_802C9F60_6DB610(Animal *arg0) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s16 sp2A;
    s32 tmp;

    if (arg0->unk4A == 0) {
        if ((arg0->state == 0x1E) || (arg0->state == 0x1F)) {
            arg0->unk6C = 0;
            arg0->unk70 = 0;
            arg0->unk68 = 0;
            return;
        }

        sp34 = arg0->xPos.w;
        sp30 = arg0->zPos.w;
        sp2C = arg0->yPos.w;

        if (arg0->unk4C.unk29) {
            switch (arg0->unk162) {
            case 1:
                arg0->yVelocity.w -= D_803A05B0_7B1C60;
                switch (func_8030AA90_71C140(arg0)) {
                case 0:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 1:
                    arg0->unk162 = 3U;
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 2:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                }
                break;
            case 3:
                switch (func_8030AA90_71C140(arg0)) {
                case 0:
                    if (func_802A7648_6B8CF8(arg0) != 0) {
                        arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    }
                    break;
                case 1:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 2:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                }
                break;
            case 5:
                arg0->yVelocity.w -= (s32) D_803A05B0_7B1C60 >> 4;
                switch (func_8030AA90_71C140(arg0)) {
                case 0:
                    if (func_802A7648_6B8CF8(arg0) != 0) {
                        arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    }
                    break;
                case 1:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 2:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                }
                break;
            case 6:
                switch (func_8030AA90_71C140(arg0)) {
                case 0:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 1:
                    if (arg0->unk16C->unk82.unk0) {
                        arg0->unk162 = 5;
                    } else {
                        arg0->unk162 = 7;
                    }
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 2:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                }
                break;
            case 7:
                switch (func_8030AA90_71C140(arg0)) {                /* switch 7; irregular */
                case 0:
                    if (func_802A7648_6B8CF8(arg0) != 0) {
                        arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    }
                    break;
                case 1:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                case 2:
                    arg0->yVelocity.w = arg0->yPos.w - sp2C;
                    break;
                }
                break;
            }
        }

        // sh
        sp2A = tmp = func_80298F78_6AA628(arg0->xPos.h, arg0->zPos.h);

        switch (arg0->unk162) {
        case 1:
            if (arg0->unk4C.unk28 != 0) {
                if (arg0->unk161 != 1) {
                    func_80311A2C_7230DC(arg0->xPos.h, arg0->zPos.h, &D_803D5510, &D_803D5512, arg0->unk160);
                    if (D_803D5510 > 0x18) {
                        D_803D5510 = 0x18;
                    } else if (D_803D5510 < -0x18) {
                        D_803D5510 = -0x18;
                    }
                    if (D_803D5512 > 0x18) {
                        D_803D5512 = 0x18;
                    } else if (D_803D5512 < -0x18) {
                        D_803D5512 = -0x18;
                    }
                    arg0->xVelocity.w += D_803D5510 << 0xC;
                    arg0->zVelocity.w += D_803D5512 << 0xC;
                }
                func_802CA8D4_6DBF84(arg0);
                func_802A3E70_6B5520(arg0, &arg0->xVelocity, &arg0->zVelocity);
            }
            if ((arg0->unk4C.unk28) && ((arg0->yPos.h + (arg0->unk42 >> 1)) < sp2A)) {
                if (arg0->unk16C->unk82.unk0) {
                    arg0->unk162 = 5;
                } else {
                    arg0->unk162 = 7;
                }
                func_802D760C_6E8CBC(arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, arg0->unk30, arg0->yVelocity.h);
            }
            break;
        case 3:
            if (arg0->unk4C.unk29) {
                if ((arg0->unk16C->objectType == 38) || (arg0->unk16C->objectType == 177)) {
                    arg0->yVelocity.w -= ((s32) D_803A05B0_7B1C60 >> 3);
                } else {
                    arg0->yVelocity.w -= D_803A05B0_7B1C60;
                }
                if ((arg0->yPos.h + (arg0->unk42 >> 1)) < tmp) {
                    if (arg0->unk16C->unk82.unk0) {
                        arg0->unk162 = 5;
                    } else {
                        arg0->unk162 = 7;
                    }
                    func_802D760C_6E8CBC(arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, arg0->unk30, arg0->yVelocity.h);
                }
            }
            break;
        case 5:
            if (arg0->unk4C.unk28) {
                func_802A403C_6B56EC(arg0, 4);
            }
            if (arg0->unk4C.unk29) {
                func_802CAACC_6DC17C(arg0, sp2A);
            }
            break;
        case 6:
            if (arg0->unk4C.unk28) {
                func_802A403C_6B56EC(arg0, 3);
                if (arg0->unk161 != 1) {
                    func_80311A2C_7230DC(arg0->xPos.h, arg0->zPos.h, &D_803D5510, &D_803D5512, (s32) arg0->unk160);
                    if (D_803D5510 > 0x18) {
                        D_803D5510 = 0x18;
                    } else if (D_803D5510 < -0x18) {
                        D_803D5510 = -0x18;
                    }
                    if (D_803D5512 > 0x18) {
                        D_803D5512 = 0x18;
                    } else if (D_803D5512 < -0x18) {
                        D_803D5512 = -0x18;
                    }
                    arg0->xVelocity.w += D_803D5510 << 0xC;
                    arg0->zVelocity.w += D_803D5512 << 0xC;
                }
                func_802CA8D4_6DBF84(arg0);
                func_802A3E70_6B5520(arg0, &arg0->xVelocity.h, &arg0->zVelocity.h);
            }
            if (sp2A < (arg0->yPos.h + (arg0->unk42 >> 1))) {
                arg0->unk162 = 1;
            }
            func_802CB180_6DC830(arg0);
            break;
        case 7:
            if (arg0->unk4C.unk28) {
                func_802A403C_6B56EC(arg0, 3);
            }
            if (arg0->unk4C.unk29) {
                arg0->yVelocity.w -= (s32) D_803A05B0_7B1C60 >> 2;
                if (sp2A < (arg0->yPos.h + (arg0->unk42 >> 1))) {
                    arg0->unk162 = 3;
                }
            }
            func_802CB180_6DC830(arg0);
            break;
        }
        // hard borders
        if (arg0->xPos.h < 64) {
            arg0->xPos.h = 64;
            arg0->xVelocity.w = 0;
            arg0->unk54 |= 0xA;
        }
        if (arg0->zPos.h < 64) {
            arg0->zPos.h = 64;
            arg0->zVelocity.w = 0;
            arg0->unk54 |= 0xA;
        }
        if (arg0->xPos.h > 0x11BF) {
            arg0->xPos.h = 0x11BF; // 4543
            arg0->xVelocity.w = 0;
            arg0->unk54 |= 0xA;
        }
        if (arg0->zPos.h > 0x1FBF) {
            arg0->zPos.h = 0x1FBF; // 8127
            arg0->zVelocity.w = 0;
            arg0->unk54 |= 0xA;
        }
        if ((sp34 != arg0->xPos.w) || (sp30 != arg0->zPos.w) || (sp2C != arg0->yPos.w)) {
            arg0->unk4C.unk24 = 1;
        } else {
            arg0->unk4C.unk24 = 0;
        }

        if (arg0->unk4C.unk24 != 0) {
            arg0->unk28 += arg0->unk38;
            arg0->unk2A += arg0->unk3A;
            arg0->yRotation += arg0->unk3C;
            if (arg0->unk28 < 0) {
                arg0->unk28 += 360;
            } else if (arg0->unk28 >= 360) {
                arg0->unk28 -= 360;
            }
            if (arg0->unk2A < 0) {
                arg0->unk2A += 360;
            } else if (arg0->unk2A >= 360) {
                arg0->unk2A -= 360;
            }
            if (arg0->yRotation < 0) {
                arg0->yRotation += 360;
            } else if (arg0->yRotation >= 360) {
                arg0->yRotation -= 360;
            }
            // regalloc help
            if (1) {};
        }

        if ((arg0->unk4C.unk24 == 0) && (arg0->xVelocity.w == 0) && (arg0->zVelocity.w == 0) && (((arg0->unk162 == 1)) || ((arg0->unk162 == 6) && (arg0->unk16C->unk82.unk0 == 0))) && (arg0->unk68 == 0) && (arg0->unk70 == 0) && (arg0->unk1A8 == 0)) {
            if ((arg0->state != 0x1E) && (arg0->state != 0x1F) && (arg0->unk16C->unk2 != 1) && (arg0->unk154 == 0)) {
                arg0->unk4C.unk25  = 0;
            }
        }
    }
}

void func_802CA8D4_6DBF84(Animal *arg0) {
    s32 xVel;
    s32 zVel;
    s32 multi;
    s32 var_v1;

    if ((arg0->unk161 == 1) && (arg0->unk6C != NULL)) {
        var_v1 = 120;
        if (arg0->unk6C->unk16C->objectType == OBJECT_BOULDER) {
            xVel = arg0->unk6C->xVelocity.w * 2;
            zVel = arg0->unk6C->zVelocity.w * 2;
        } else {
            xVel = arg0->unk6C->xVelocity.w;
            zVel = arg0->unk6C->zVelocity.w;
        }
    } else {
        xVel = zVel = 0;
        if (arg0->unk160 == 2) {
            var_v1 = D_803E1D30[D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk3].unk0;
        } else {
            var_v1 = D_803E1D30[D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk2].unk0;
        }
    }
    if (arg0->unk16C->objectType == OBJECT_BOULDER) {
        var_v1 /= 4;
    }
    multi = arg0->unk16C->unk7E + (((256 - arg0->unk16C->unk7E) * (16 - var_v1)) >> 4);
    if (multi < 0) {
        multi = 0;
    }
    if (arg0->unk162 == 6) {
        multi = 256 - ((256 - multi) >> 1);
    }

    arg0->xVelocity.w = (((arg0->xVelocity.w - xVel) * multi) >> 8) + xVel;
    arg0->zVelocity.w = (((arg0->zVelocity.w - zVel) * multi) >> 8) + zVel;
    if ((ABS(arg0->xVelocity.w) < 0x800) && (ABS(arg0->zVelocity.w) < 0x800)) {
        arg0->zVelocity.w = arg0->xVelocity.w = 0;
    }
}

void func_802CAACC_6DC17C(Animal *arg0, s16 arg1) {
    arg0->yVelocity.w = (arg0->yVelocity.w * 7) / 8;
    arg0->yVelocity.w -= ((arg0->yPos.h + (arg0->unk42 >> 1)) - arg1) << 10;
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

    if ((arg0->unk16C->unk82.unk2) && (!arg1->unk16C->unk82.unk2)) {
        if ((ABS(arg5) < 9) && (ABS(arg6) < 9) && (ABS(arg7) < 9)) {
            phi_t1 = 1;
        }
    }

    if ((arg1->unk16C->unk82.unk2) && (!arg0->unk16C->unk82.unk2)) {
        if ((ABS(arg2) < 9) && (ABS(arg3) < 9) && (ABS(arg4) < 9)) {
            phi_t1 = 1;
        }
    }

    if (((arg0->unk16C->unk82.unk2) && (!arg1->unk16C->unk82.unk2)) || ((arg1->unk16C->unk82.unk2) && (!arg0->unk16C->unk82.unk2))) {
        if ((ABS(arg2 - arg5) < 9) && (ABS(arg3 - arg6) < 9) && (ABS(arg4 - arg7) < 9)) {
            phi_t1 = 1;
        }
    }

    if (((arg0->unk16C->unk82.unk2) && (arg1->unk16C->unk82.unk2)) &&
        (((arg0->unk366 == 5)) || (arg0->unk366 == 2) || ((arg1->unk366 == 5)) || (arg1->unk366 == 2))) {
        phi_t1 = 1;
    }

    phi_a2 = ABS(arg0->xVelocity.h - arg2);
    phi_a1 = ABS(arg0->zVelocity.h - arg3);
    phi_a0 = ABS(arg0->yVelocity.h - arg4);
    if (phi_t1 == 0) {
        sp38 = (phi_a2 + phi_a1 + phi_a0) << 8;
        temp_v1_4 = arg1->unk16C->unk8C;
        if ((arg1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) && (arg1 != D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
            temp_v1_4 /= 5;
        }
        sp38 = ((sp38 * temp_v1_4) >> 4) / 1024;
    } else {
        sp38 = 0;
    }

    if ((arg1->unk16C->unk82.unk2) &&
        ((arg1->unk16C->unk9C == DESERT_FOX_ATTACKING) ||
         (arg1->unk16C->unk9C == RACING_TORTOISE_DEFENDING) ||
         (arg1->unk16C->unk9C == POLAR_BEAR_DEFENDING) ||
         (arg1->unk16C->unk9C == HARD_MOUSE))) {
        func_802B3B48_6C51F8(arg0, arg1, &sp38);
        if ((arg0->unk16C->unk82.unk2) && (arg1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
            arg0->unk2EB += 1;
        }
    }
    if (arg0->unk16C->unk82.unk2) {
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
        if ((arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) && (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
            temp_v1_4 = temp_v1_4 / 5;
        }
        sp38 = ((sp38 * temp_v1_4) >> 4) / 1024;
    } else {
        sp38 = 0;
    }

    if ((arg0->unk16C->unk82.unk2) &&
        ((arg0->unk16C->unk9C == DESERT_FOX_ATTACKING) ||
         (arg0->unk16C->unk9C == RACING_TORTOISE_DEFENDING) ||
         (arg0->unk16C->unk9C == POLAR_BEAR_DEFENDING) ||
         (arg0->unk16C->unk9C == HARD_MOUSE))) {
        func_802B3B48_6C51F8(arg1, arg0, &sp38);
        if ((arg1->unk16C->unk82.unk2) && (arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
            arg1->unk2EB += 1;
        }
    }
    if (arg1->unk16C->unk82.unk2) {
        sp38 += func_802B3C9C_6C534C(arg0->unk16C->unk8D, arg1);
    } else {
        sp38 += arg0->unk16C->unk8D;
    }
    func_802B38FC_6C4FAC(arg1, sp38, -1, 1);
    arg1->unk65 += sp38;
}

void func_802CB180_6DC830(Animal *arg0) {
    if (func_80298E08_6AA4B8(arg0->xPos.h, arg0->zPos.h)) {
        s8 tmp;
        s16 phi_a1;
        s16 pad;
        s16 temp_t7;
        s16 xPos = arg0->xPos.h >> 6;
        s16 zPos = arg0->zPos.h >> 6;
        temp_t7 = D_803C0740[xPos][zPos].unk6 << 2;

        if (temp_t7 < arg0->yPos.h) {
            phi_a1 = 0;
        } else {
            if ((arg0->yPos.h + arg0->unk42) < temp_t7) {
                phi_a1 = 64;
            } else {
                phi_a1 = ((temp_t7 - arg0->yPos.h) << 6) / arg0->unk42;
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
