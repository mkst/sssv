#include <ultra64.h>
#include "common.h"


void func_802A3CD0_6B5380(void) {
    s16 xVel, zVel;

    if (D_803D5530->unk160 == 2) {
        func_80311AA8_723158(D_803D5530->xPos, D_803D5530->zPos, &D_803D5510, &D_803D5512);
    } else {
        func_80311BF8_7232A8(D_803D5530->xPos, D_803D5530->zPos, &D_803D5510, &D_803D5512);
    }

    if (D_803D5530->unk161 == 0) {
        xVel = D_803D5510;
        zVel = D_803D5512;

        if (xVel > 24) {
            xVel += xVel - 24;
        }
        if (xVel < -24) {
            xVel += xVel + 24;
        }

        if (zVel > 24) {
            zVel += zVel - 24;
        }
        if (zVel < -24) {
            zVel += zVel + 24;
        }

        D_803D5530->xVelocity.w += MAX(MIN(xVel, 128), -128) << 12;
        D_803D5530->zVelocity.w += MAX(MIN(zVel, 128), -128) << 12;
    }
}

void func_802A3E70_6B5520(Animal *arg0, s32 *arg1, s32 *arg2) {
    if (arg0->unk161 == 0) {
        if (D_803D5510 < -23) {
            *arg1 = MIN(*arg1, -65536);
        }
        if (D_803D5510 >= 24) {
            *arg1 = MAX(*arg1, 65536);
        }
        if (D_803D5512 < -23) {
            *arg2 = MIN(*arg2, -65536);
        }
        if (D_803D5512 >= 24) {
            *arg2 = MAX(*arg2, 65536);
        }
    }
}

#ifdef NON_MATCHING // JUSTREG
void func_802A3F68_6B5618(s32 *arg0, s32 *arg1) {
    s32 temp_t6;
    s32 temp_v1;

    temp_v1 = D_803C0740_7D1DF0[D_803D5530->xPos >> 6][D_803D5530->zPos >> 6].unk7;
    *arg0 += ((1 - (((temp_v1 >> 4) & 8) >> 2)) * (((temp_v1 & 0xF0) >> 4) & 7)) << 17;
    if (0) { };
    temp_t6 = D_803C0740_7D1DF0[D_803D5530->xPos >> 6][D_803D5530->zPos >> 6].unk7;
    *arg1 += ((1 - ((temp_t6 & 8) >> 2)) * (temp_t6 & 7)) << 17;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A3F68_6B5618.s")
#endif

void func_802A403C_6B56EC(Animal *arg0, s16 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_a2;

    temp_v0 = arg0->xVelocity.w;
    temp_a2 = D_803C0740_7D1DF0[arg0->xPos >> 6][arg0->zPos >> 6].unk7;
    temp_v1 = arg0->zVelocity.w;

    temp_v0 = temp_v0 - (((1 - (((temp_a2 >> 4) & 8) >> 2)) * (((temp_a2 & 0xF0) >> 4) & 7)) << 17);
    temp_v1 = temp_v1 - (((1 - ((temp_a2 & 8) >> 2)) * ((u8)temp_a2 & 7)) << 17);

    arg0->xVelocity.w -= (temp_v0 >> arg1);
    arg0->zVelocity.w -= (temp_v1 >> arg1);
}

void func_802A40EC_6B579C(void) {
    s16 tmp;
    if ((D_803D5524->unkA0 & 0xC00) != 0) {
        tmp = D_803D5524->unkBA;
    } else {
        tmp = D_803D5524->unkB8;
    }
    D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    D_803D5530->yVelocity.w -= ((D_803D5530->yPos + tmp) - func_80298F78_6AA628(D_803D5530->xPos, D_803D5530->zPos)) << 10;
}

void func_802A4184_6B5834(void) {
    s16 tmp = (D_803D5530->yPos + D_803D5524->unkBA) - func_80298F78_6AA628(D_803D5530->xPos, D_803D5530->zPos);
    if (tmp >= 0) {
        D_803D5530->yVelocity.w -= D_803A05B0;
    } else if (tmp >= -15) {
        D_803D5530->yVelocity.w -= ((tmp + 16) * D_803A05B0) >> 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A4220_6B58D0.s")
// what???
// void func_802A4220_6B58D0(s32 arg0, s32 arg1, s32 arg2) {
//     s32 temp_v0;
//     s32 temp_v1;
//
//     temp_v0 = ABS(arg0);
//     temp_v1 = ABS(arg1);
//
//     *arg0 = (arg0 * temp_v0) >> 8;
//     *arg1 = (arg1 * temp_v1) >> 8;
// }

// miles away
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A4278_6B5928.s")
// void func_802A4278_6B5928(u16 arg0, u16 arg1, s16 arg2) {
//     s32 temp_t7_2;
//     s32 temp_t6_2;
//     s32 temp_t7_3;
//
//     s32 xVel;
//     s32 zVel;
//
//     xVel = D_803D5530->xVelocity.w;
//     zVel = D_803D5530->zVelocity.w;
//
//     temp_t7_2 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 5;
//     temp_t6_2 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 5;
//
//     temp_t7_3 = (((xVel >> 10) * temp_t7_2) + ((zVel >> 10) * temp_t6_2)) >> 10;
//
//     D_803D5530->xVelocity.w = xVel - (((((xVel - (temp_t7_2 * temp_t7_3)) >> arg0) + (xVel >> arg1)) * arg2) >> 4);
//     D_803D5530->zVelocity.w = zVel - (((((zVel - (temp_t6_2 * temp_t7_3)) >> arg0) + (zVel >> arg1)) * arg2) >> 4);
// }

void func_802A4390_6B5A40(void) {
    D_803D5530->state = 2;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A43E4_6B5A94(u16 rotation, s8 arg1) {
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;

    D_803D5530->state = 3;
    D_803D5530->yRotation = rotation;

    if ((D_803D5524->unk9C == GORILLA) || (D_803D5524->unk9C == BEAR)) {
        if (D_803D552C->unk320 != 0) {
            arg1 = (arg1 * 5) / 6;
        }
    }
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
    func_802B8790_6C9E40();
}

void func_802A44C4_6B5B74(u16 rotation, s8 arg1) {
    D_803D5530->state = 6;
    D_803D5530->yRotation = rotation;

    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;

    if ((D_803D5524->unk9C == GORILLA) || ( (D_803D5524->unk9C == BEAR))) {
        if (D_803D552C->unk320 != 0) {
            arg1 = (arg1 * 5) / 6;
        }
    }
    D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
    func_802B8790_6C9E40();
}

void func_802A459C_6B5C4C(u16 rotation, s8 arg1) {
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;

    D_803D5530->state = 4;
    D_803D5530->yRotation = rotation;

    if ((D_803D5524->unk9C == GORILLA) || (D_803D5524->unk9C == BEAR)) {
        if (D_803D552C->unk320 != 0) {
            arg1 = (arg1 * 5) / 6;
        }
    }
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
    func_802B8810_6C9EC0();
}

// might not be too bad
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A467C_6B5D2C.s")

void func_802A4CB8_6B6368(void) {
    D_803D5530->state = 21;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A4D0C_6B63BC(u16 rotation, s8 arg1) {
    D_803D5530->state = 22;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A4D80_6B6430(u16 rotation, s8 arg1) {
    D_803D5530->state = 24;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A4DF4_6B64A4(u16 rotation, s8 arg1) {
    D_803D5530->state = 23;
    D_803D552C->unk31A = D_803D5524->unkA4 * 65536;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8978_6CA028();
}

void func_802A4E74_6B6524(void) {
    D_803D5530->state = 181;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A4EC8_6B6578(u16 rotation, s8 arg1) {
    D_803D5530->state = 182;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A4F68_6B6618(u16 rotation, s8 arg1) {
    D_803D5530->state = 185;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    D_803D552C->unk368 = arg1;
    func_802B8790_6C9E40();
}

void func_802A5008_6B66B8(u16 rotation, s8 arg1) {
    D_803D5530->state = 183;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8810_6C9EC0();
}

void func_802A50A8_6B6758(void) {
    s16 xVel, zVel;

    D_803D5530->state = 184;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;

    if (D_803D5530->unk162 != 1) {
        zVel = 0;
        xVel = 0;
    } else {
        func_80311A2C_7230DC(D_803D5530->xPos, D_803D5530->zPos, &xVel, &zVel, D_803D5530->unk160);
    }
    if (xVel < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -(s32) D_803D5524->unkA6 << 0xF);
    }
    if (xVel > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA6 << 0xF);
    }
    if (zVel < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -(s32) D_803D5524->unkA6 << 0xF);
    }
    if (zVel > 23) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, D_803D5524->unkA6 << 0xF);
    }

    if ((ABS(xVel) > 23) || (ABS(zVel) > 23)) {
        D_803D5530->yVelocity.w += (D_803D5524->unkA6 << 12);
    } else {
        D_803D5530->yVelocity.w += (D_803D5524->unkA6 << 16);
        if (D_803D5530->unk162 != 1) {
            D_803D5530->yVelocity.w += D_803A05B0;
        }
    }
    func_802B8890_6C9F40();
}

void func_802A5300_6B69B0(void) {
    s16 xVel, zVel;

    D_803D5530->state = 184;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 32;

    if (D_803D5530->unk162 != 1) {
        zVel = 0;
        xVel = 0;
    } else {
        func_80311A2C_7230DC(D_803D5530->xPos, D_803D5530->zPos, &xVel, &zVel, D_803D5530->unk160);
    }
    if (xVel < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -(s32) D_803D5524->unkA8 << 0xF);
    }
    if (xVel > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA8 << 0xF);
    }
    if (zVel < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -(s32) D_803D5524->unkA8 << 0xF);
    }
    if (zVel > 23) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, D_803D5524->unkA8 << 0xF);
    }

    if ((ABS(xVel) > 23) || (ABS(zVel) > 23)) {
        D_803D5530->yVelocity.w += (D_803D5524->unkA8 << 12);
    } else {
        D_803D5530->yVelocity.w += (D_803D5524->unkA8 << 16);
        if (D_803D5530->unk162 != 1) {
            D_803D5530->yVelocity.w += D_803A05B0;
        }
    }
    func_802B8890_6C9F40();
}

void func_802A5558_6B6C08(void) {
    D_803D5530->state = 201;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A55AC_6B6C5C(u16 rotation, s8 arg1) {
    D_803D5530->state = 202;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A5620_6B6CD0(u16 rotation, s8 arg1) {
    D_803D5530->state = 0xCC;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A5694_6B6D44(u16 rotation, s8 arg1) {
    D_803D5530->state = 0xCB;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8978_6CA028();
}

void func_802A5708_6B6DB8(s16 arg0, s16 arg1, s8 arg2) {
    D_803D5530->yRotation = arg0 & 0xFF;
    D_803D5530->unk28 = arg1;
    D_803D5530->state = 81;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg2;
    func_802B8A48_6CA0F8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A5778_6B6E28.s")

void func_802A5C80_6B7330(void) {
    D_803D5530->state = 0x29;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk30C = MAX(6, D_803D552C->unk30C);
     func_802B8720_6C9DD0();
}

void func_802A5CF4_6B73A4(void) {
    D_803D552C->unk30E = 50;
    D_803D5530->state = 123;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;
    D_803D552C->unk368 = 0;
    D_803D5530->yVelocity.w = 2 * D_803A05B0;
    D_803D5530->unk162 = 2;
}

void func_802A5D64_6B7414(void) {
    D_803D5530->state = 121;
    D_803D552C->unk31A = 0;
    D_803D5530->yVelocity.w = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 1;
    func_802B8720_6C9DD0();
}

void func_802A5DD0_6B7480(void) {
    D_803D5530->state = 62;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;
    D_803D552C->unk368 = 0;
    D_803D5530->yVelocity.w = 0;
}

void func_802A5E1C_6B74CC(u16 rotation) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 162;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 16;
}

void func_802A5E64_6B7514(void) {
    D_803D5530->state = 161;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D552C->unk308 = 10;
}

void func_802A5EA4_6B7554(void) {
    D_803D5530->state = 141;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = (u8)0;
    func_802B8720_6C9DD0();
}

void func_802A5EF8_6B75A8(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 142;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A5F9C_6B764C(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 0x90;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = -arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A6044_6B76F4(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 0x8F;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = D_803D5524->unkA4 >> 1;
    func_802B8810_6C9EC0();
}

void func_802A60C4_6B7774(void) {
    D_803D5530->state = 101;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
}

void func_802A6100_6B77B0(void) {
    D_803D5530->state = 103;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
}

void func_802A613C_6B77EC(u16 rotation) {
    D_803D5530->state = 104;
    if (rotation != 256) {
        D_803D5530->yRotation = rotation;
    }
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A6198_6B7848(u16 rotation) {
    D_803D5530->state = 0x69;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 16;
    D_803D5530->unk162 = 2;
}

void func_802A61EC_6B789C(u16 rotation) {
    D_803D5530->state = 0x6A;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A623C_6B78EC(s16 arg0, s16 arg1) {
    D_803D5530->state = 0xDD;
    D_803D552C->unk308 = arg0;
    D_803D552C->unk30A = arg1 * 16;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A628C_6B793C(void) {
    s32 xVel;
    s32 zVel;
    s16 tmp;

    func_802E4A78_6F6128(D_803D552C->unk308);
    tmp = D_803F28E0[D_803F2A98].unk20;
    xVel = ((D_80152C78[(tmp + 64) & 0xff] >> 7) * D_801E9EB4) * 16;
    zVel = ((D_80152C78[tmp & 0xff] >> 7) * -D_801E9EB4) * 16;
    D_803D5530->xVelocity.w += xVel;
    D_803D5530->zVelocity.w += zVel;
    D_803D552C->unk368 = 0;
    D_803D5546 = 50;
    func_802B2EA8_6C4558();
    D_803D5530->unk162 = 3;
}

void func_802A6390_6B7A40(void) {
    if (D_803D552C->unk360 == 0) {
        D_803D552C->unk360 = 3;
        D_803D552C->unk361 = 0;
    }
}

void func_802A63C0_6B7A70(void) {
    if (D_803D552C->unk360 == 0) {
        D_803D552C->unk360 = 3;
        D_803D552C->unk361 = 1;
    } else {
        D_803D552C->unk361 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A6400_6B7AB0.s")
// should match, need to decomp functions in between due to rodata
// void func_802A6400_6B7AB0(void) {
//     switch (D_803D5530->state) {
//     case 2:
//     case 3:
//     case 4:
//     case 5:
//     case 6:
//         D_803D5530->state = 5;
//         break;
//     case 0x65:
//     case 0x66:
//     case 0x67:
//     case 0x68:
//     case 0x69:
//     case 0x6A:
//         D_803D5530->state = 0x67;
//         break;
//     case 0xB5:
//     case 0xB6:
//     case 0xB7:
//     case 0xB8:
//     case 0xB9:
//         D_803D5530->state = 0xB8;
//         break;
//     }
// }

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A64B0_6B7B60.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A7648_6B8CF8.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A78CC_6B8F7C.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A935C_6BAA0C.s")

void func_802AA0A0_6BB750(void) {
    if ((D_803D552C->unk366 != 4) &&
        ((D_803D5530->state == 2) || (D_803D5530->state == 0x15) || (D_803D5530->state == 0x29) || (D_803D5530->state == 0x79)) &&
        ((func_8012826C() & 0x1F) == 0) && (D_803F6450 != 0)) {
        func_802AA5C0_6BBC70();
    }
    if ((D_803D5530->unk4B >= 0x21) && (D_803D5530->unk4C.unk26 == 0)) {
        D_803D5530->health = MAX(0, D_803D5530->health - 1);

        func_80349280_75A930(D_803D5530, 1);
        if (D_803D5530->unk4B >= 0x31) {
            D_803D5530->health = MAX(0, D_803D5530->health - 1);
            func_80349280_75A930(D_803D5530, 1);
        }
        if (D_803D5530->unk4B >= 0x3D) {
            D_803D5530->health = 0;
            func_80349280_75A930(D_803D5530, 40);
        }
    }
}

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA1EC_6BB89C.s")

void func_802AA424_6BBAD4(void) {
    func_802AA444_6BBAF4();
}

// jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA444_6BBAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA5C0_6BBC70.s")
// should match, just rodata...
// void func_802AA5C0_6BBC70(void) {
//     u8 tmp;
//
//     tmp = (func_8012826C() >> 8) & 0xF;
//     switch (tmp) {
//     case 0:
//         if ((D_803D5528->unk380 == 0) && (D_803D5528->unk394 == 0)) {
//             D_803D5528->unk380 = 1;
//             D_803D5528->unk382 = 0;
//         }
//         break;
//     case 1:
//         if ((D_803D5528->unk394 == 0) && (D_803D5528->unk380 == 0)) {
//             D_803D5528->unk394 = 1;
//             D_803D5528->unk396 = 0;
//         }
//         break;
//     case 2:
//         if ((D_803D5528->unk3A8 == 0) && (D_803D5528->unk3BC == 0)) {
//             D_803D5528->unk3A8 = 1;
//             D_803D5528->unk3AA = 0;
//         }
//         break;
//     case 3:
//         if ((D_803D5528->unk3BC == 0) && (D_803D5528->unk3A8 == 0)) {
//             D_803D5528->unk3BC = 1;
//             D_803D5528->unk3BE = 0;
//         }
//         break;
//     case 4:
//         if ((D_803D5528->unk380 == 0) && (D_803D5528->unk394 == 0)) {
//             D_803D5528->unk380 = 11;
//             D_803D5528->unk382 = 0;
//         }
//         break;
//     case 5:
//         if ((D_803D5528->unk394 == 0) && (D_803D5528->unk380 == 0)) {
//             D_803D5528->unk394 = 11;
//             D_803D5528->unk396 = 0;
//         }
//         break;
//     case 6:
//         if ((D_803D5528->unk3A8 == 0) && (D_803D5528->unk3BC == 0)) {
//             D_803D5528->unk3A8 = 11;
//             D_803D5528->unk3AA = 0;
//         }
//         break;
//     case 7:
//         if ((D_803D5528->unk3BC == 0) && (D_803D5528->unk3A8 == 0)) {
//             D_803D5528->unk3BC = 11;
//             D_803D5528->unk3BE = 0;
//         }
//         break;
//     case 8:
//     case 9:
//         if ((D_803D5528->unk3C0 == 0) && (D_803D5524->unk9C != RACING_DOG) && (D_803D552C->unk318 == 0)) {
//             D_803D5528->unk3C0 = 1;
//             D_803D5528->unk3C2 = 0;
//         }
//         break;
//     case 10:
//     case 11:
//         if ((D_803D5528->unk3C0 == 0) && (D_803D552C->unk318 == 0)) {
//             D_803D5528->unk3C0 = 5;
//             D_803D5528->unk3C2 = 0;
//         }
//         break;
//     }
// }

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA85C_6BBF0C.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AAAB0_6BC160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AB8EC_6BCF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802ABB10_6BD1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC158_6BD808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC484_6BDB34.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC5CC_6BDC7C.s")

#ifdef NON_MATCHING // JUSTREG
void func_802AC8A0_6BDF50(s32 *arg0, s32 *arg1) {
    *arg0 = 0;

    if (D_801E9EB2 > 2) {
        *arg1 = D_803D5524->unkA4 * 1024;
    } else if (D_801E9EB2 > 0) {
        *arg1 = D_803D5524->unkA4 * 640;
    } else {
        *arg1 = 0;
    }
    func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC8A0_6BDF50.s")
#endif

s32 func_802AC928_6BDFD8(s32 arg0, s32 arg1) {
    if (arg0 < 0) {
        arg0 = -arg0;
    }
    if (arg1 < 0) {
        arg1 = -arg1;
    }
    if (arg1 >= arg0) {
        return (arg0 / 2) + arg1;
    }
    return (arg1 / 2) + arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC980_6BE030.s")
// should match, just rodata
// void func_802AC980_6BE030(void) {
//     switch (D_803F28E0[D_803F2A98].unk0) {
//     case 3:
//     case 5:
//     case 6:
//     case 7:
//     case 17:
//     case 28:
//         func_802AD0FC_6BE7AC();
//         break;
//     default:
//         func_802AC9FC_6BE0AC();
//         break;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC9FC_6BE0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD0FC_6BE7AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD49C_6BEB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD63C_6BECEC.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD87C_6BEF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802ADDD0_6BF480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AE278_6BF928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AE488_6BFB38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AE698_6BFD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AE9C4_6C0074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AEBB0_6C0260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AEE18_6C04C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AF308_6C09B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AF7E4_6C0E94.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AF9FC_6C10AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B066C_6C1D1C.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B0B00_6C21B0.s")

void func_802B0D4C_6C23FC(s16 arg0, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 181:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A4EC8_6B6578(arg0, arg1);
            } else if (arg1 >= 14) {
                func_802A5008_6B66B8(arg0, arg1);
            }
        }
        break;
    case 182:
        if (arg1 <= 0) {
            func_802A4E74_6B6524();
        } else if (arg1 >= 14) {
            func_802A5008_6B66B8(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    case 183:
        if (arg1 <= 0) {
            func_802A4E74_6B6524();
        } else if (arg1 < 14) {
            func_802A4EC8_6B6578(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B0F4C_6C25FC.s")

void func_802B10B0_6C2760(s16 rotation, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 201:
        if (arg1 > 0) {
            if (arg1 < 0xE) {
                func_802A55AC_6B6C5C(rotation, arg1);
            } else {
                func_802A5694_6B6D44(rotation, arg1);
            }
        }
        break;
    case 202:
        if (arg1 <= 0) {
            func_802A5558_6B6C08();
        } else if (arg1 >= 0xE) {
            func_802A5694_6B6D44(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 203:
        if (arg1 <= 0) {
            func_802A5558_6B6C08();
        } else if (arg1 < 0xD) {
            func_802A5694_6B6D44(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1210_6C28C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1374_6C2A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1654_6C2D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1918_6C2FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1B98_6C3248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1D00_6C33B0.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1E28_6C34D8.s")

s16 func_802B2580_6C3C30(void) {
    return D_803D5530->yPos - func_802B25B4_6C3C64(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B25B4_6C3C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B2834_6C3EE4.s")

void func_802B2964_6C4014(void) {
    s16 phi_a3;
    s16 temp_v0_2;

    temp_v0_2 = func_80298F78_6AA628(D_803D5530->xPos, D_803D5530->zPos);
    if ((D_803D5524->unkA0 & 0xC00) != 0) {
        phi_a3 = D_803D5524->unkBA;
    } else {
        phi_a3 = D_803D5524->unkB8;
    }
    if ((temp_v0_2 == 0) || (temp_v0_2 < ((func_80310EE4_722594(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->unk160) >> 16) + phi_a3))) {
        func_802B2EA8_6C4558();
        return;
    }
    if ((D_803D5538 != 0) &&
        (((D_803D5524->unk9E == 0x20) && (D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0)) ||
         ((D_803D5524->unk9E == 0x80) && (D_801D9ED8.unkFFB2 != 0)))) {

        if (((D_803D5530->yPos + phi_a3) - temp_v0_2) > -7) {
            D_803D5530->yPos = MAX(D_803D5530->yPos, temp_v0_2 - phi_a3);
            D_803D5530->yVelocity.w = 0x40000;
            func_802B2EA8_6C4558();
        }
    }
    if ((temp_v0_2 + 16) < D_803D5530->yPos) {
        func_802B2FF4_6C46A4();
    }
}

s32 func_802B2AF0_6C41A0(s32 arg0, s32 arg1) {
    if ((arg0 <= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos - D_803D5524->unkBE, D_803D5530->zPos))) {
        return 1;
    }
    if ((arg0 >= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos + D_803D5524->unkBE, D_803D5530->zPos))) {
        return 1;
    }
    if ((arg1 <= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos, D_803D5530->zPos - D_803D5524->unkBE))) {
        return 1;
    }
    if ((arg1 >= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos, D_803D5530->zPos + D_803D5524->unkBE))) {
        return 1;
    }
    // implicit return?
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B2C20_6C42D0.s")

void func_802B2EA8_6C4558(void) {
    switch (D_803D5524->unk9E) {
    case 2:
        func_802A4390_6B5A40();
        D_803D5530->unk162 = 1;
        break;
    case 4:
        func_802A4CB8_6B6368();
        D_803D5530->unk162 = 1;
        break;
    case 8:
        func_802A5C80_6B7330();
        D_803D5530->unk162 = 1;
        break;
    case 64:
        func_802A5708_6B6DB8(D_803D5530->yRotation, 0, 1);
        D_803D5530->unk162 = 2;
        break;
    case 32:
        func_802A60C4_6B7774();
        D_803D5530->unk162 = 1;
        break;
    case 128:
        func_802A5D64_6B7414();
        D_803D5530->unk162 = 1;
        break;
    case 256:
        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        func_802A5E64_6B7514();
        D_803D5530->unk162 = 1;
        break;
    }
}

void func_802B2FF4_6C46A4(void) {
    switch (D_803D5524->unk9E) {
    case 2:
        D_803D5530->state = 5;
        D_803D5530->unk162 = 3;
        break;
    case 4:
        func_802A4CB8_6B6368();
        D_803D5530->unk162 = 3;
        break;
    case 8:
        func_802A5C80_6B7330();
        D_803D5530->unk162 = 3;
        break;
    case 64:
        func_802A5708_6B6DB8(D_803D5530->yRotation, 0, 1);
        D_803D5530->unk162 = 2;
        break;
    case 32:
        func_802A60C4_6B7774();
        D_803D5530->unk162 = 3;
        break;
    case 128:
        func_802A5CF4_6B73A4();
        D_803D5530->unk162 = 3;
        break;
    case 256:
        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        func_802A5E1C_6B74CC(0);
        D_803D5530->unk162 = 3;
        break;
    }
}

void func_802B315C_6C480C(void) {
    switch (D_803D5524->unkA0 & 0x3FF) {
    case 2:
        func_802A5EA4_6B7554();
        D_803D5530->unk162 = 5;
        break;
    case 4:
        func_802A5DD0_6B7480();
        D_803D5530->unk162 = 4;
        break;
    case 8:
        func_802A4E74_6B6524();
        D_803D5530->unk162 = 6;
        break;
    case 16:
        func_802A5558_6B6C08();
        D_803D5530->unk162 = 6;
        break;
    case 1:
        D_803D5530->yVelocity.w += 0x50000;
        break;
    }
}

void func_802B3230_6C48E0(void) {
    s16 tmp;

    if ((D_803D5524->unkA0 & 0xC00)) {
        switch (D_803D5530->state) {
        case 61:
        case 62:
        case 141:
        case 142:
        case 143:
        case 144:
        case 181:
        case 182:
        case 183:
        case 184:
        case 185:
        case 201:
        case 202:
        case 203:
        case 204:
            if (D_803D5524->unkBA < (func_80298F78_6AA628(D_803D5530->xPos, D_803D5530->zPos) - (func_8031124C_7228FC(D_803D5530->xPos, D_803D5530->zPos) >> 0x10))) {
                if ((D_803D5530->unk4C.unk26 == 0) && ((D_803D5540 & 3) == 0)) {
                    tmp = 0;
                    if (D_803D5524->unkA0 & 0x400) {
                        tmp += 1;
                    }
                    if (D_803D5524->unkA0 & 0x800) {
                        tmp += 2;
                    }
                    func_802B38FC_6C4FAC(D_803D5530, tmp, -1, 0);
                }
                if ((func_8012826C() & 0xF) == 0xC) {
                    func_802D9C64_6EB314(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 33, 0xE721);

                }
            }
        }
    }
}

void func_802B33D0_6C4A80(Animal *a) {
    a->unk4A += 1;
    if (a->unk16C->unk80.bit) {
        a->unk304 = a->unk302;
    }
}

void func_802B3400_6C4AB0(Animal *a) {
    a->unk4A = 1;
    if (a->unk16C->unk80.bit) {
        a->unk304 = a->unk302;
    }
}

void func_802B342C_6C4ADC(void) {
  D_801D9ED8.animal[gCurrentAnimalIndex].unk0->unk4A += 1;
  D_801D9ED8.animal[gCurrentAnimalIndex].unk0->unk304 = D_801D9ED8.animal[gCurrentAnimalIndex].unk0->unk302;
}

void func_802B3474_6C4B24(void) {
    D_801D9ED8.animal[gCurrentAnimalIndex].unk0->unk4A = 1;
    D_801D9ED8.animal[gCurrentAnimalIndex].unk0->unk304 = D_801D9ED8.animal[gCurrentAnimalIndex].unk0->unk302;
}

void func_802B34B8_6C4B68(Animal *a) {
    if ((a->unk4A - 1) < 0) {
        a->unk4A = 0;
    } else {
        a->unk4A -= 1;
    }
}

void func_802B34DC_6C4B8C(void) {
    Animal *a = D_801DDD8C[gCurrentAnimalIndex].unk0;
    if ((a->unk4A - 1) < 0) {
        a->unk4A = 0;
    } else {
        a->unk4A -= 1;
    }
}

void func_802B3518_6C4BC8(void) {
    D_803D554A += 1;
}

void func_802B3530_6C4BE0(void) {
    D_803D554A = 1;
}

void func_802B3540_6C4BF0(void) {
    if ((D_803D554A - 1) < 0) {
        D_803D554A = 0;
    } else {
        D_803D554A -= 1;
    }
}

void func_802B356C_6C4C1C(Animal *arg0, s16 arg1, s16 arg2, u8 arg3) {
    s16 tmp;
    s16 temp_v1_2;
    s16 pad;

    arg1 <<= 4;

    if ((arg0->unk4C.unk26 != 0) || (arg0->unk4A != 0) || (arg0->unk16C->unk8B == 0xFF)) {
        arg1 = 0;
    }

    if (arg0->unk16C->unk80.bit == 0) {
        arg0->health = MAX(0, arg0->health - (arg1 >> 4));
    }

    switch (arg0->unk16C->unkE6) {
    case 0:
        tmp = (arg1 * 36) >> 4;
        break;
    case 1:
        tmp = (arg1 * 24) >> 4;
        break;
    case 2:
        tmp = (arg1 * 16) >> 4;
        break;
    case 3:
        tmp = (arg1 * 8) >> 4;
        break;
    case 4:
        tmp = (arg1 * 5) >> 4;
        break;
    default:
        tmp = (arg1 * 16) >> 4;
        break;
    }

    if ((arg2 >= 0) && (arg0->unk16C->unk80.bit) && (arg0 != D_801DDD8C[gCurrentAnimalIndex].unk0)) {
        temp_v1_2 = arg0->unk16C->unkE6 - arg2;
        switch (temp_v1_2) {
        case 2:
            tmp = ((tmp * 3) >> 2);
            break;
        case 3:
            tmp = (tmp >> 1);
            break;
        case 4:
            tmp = (tmp >> 2);
            break;
        case 5:
            tmp = (tmp >> 3);
            break;
        case 6:
        case 7:
            tmp = 0;
            break;
        }
    }

    if ((arg0->unk16C->unk80.bit) && (arg3 != 0) && ((arg0->health - tmp) > 0)) {
        if (tmp > 480) {
            func_802DBA58_6ED108(14, arg0);
            func_802D9C64_6EB314(arg0->xPos, arg0->zPos, arg0->yPos, 33, 0xE701);
        } else if (tmp > 192) {
            func_802DBA58_6ED108(14, arg0);
            func_802D9C64_6EB314(arg0->xPos, arg0->zPos, arg0->yPos, 17, 0xE701);
        } else if (tmp >= 64) {
            func_802DBA58_6ED108(13, arg0);
            func_802D9C64_6EB314(arg0->xPos, arg0->zPos, arg0->yPos, 8, 0xE701);
        }
    }
    tmp = MIN(tmp, 0x230);

    if ((arg1 != 0) && (tmp <= 0)) {
        tmp = 1;
    }

    func_80349280_75A930(arg0, tmp >> 4);

    if (tmp > 0) {
        arg0->health = MAX(0, (arg0->health - MAX(1, tmp >> 4)));
    }
}

void func_802B38FC_6C4FAC(Animal *arg0, s16 arg1, s16 arg2, u8 arg3) {
    s16 phi_a2;
    s16 temp_v0;

    if ((arg0->unk4C.unk26 != 0) || (arg0->unk4A != 0)) {
        arg1 = 0;
    }
    if (arg0->unk16C->unk8B == 0xFF) {
        arg1 = 0;
    }
    phi_a2 = arg1;
    if ((arg2 >= 0) && (arg0->unk16C->unk80.bit) && (arg0 != D_801DDD8C[gCurrentAnimalIndex].unk0)) {
        temp_v0 = arg0->unk16C->unkE6 - arg2;
        switch (temp_v0) {
        case 2:
            phi_a2 = (arg1 * 12) >> 4;
            break;
        case 3:
            phi_a2 = (arg1 * 9) >> 4;
            break;
        case 4:
            phi_a2 = (arg1 * 6) >> 4;
            break;
        case 5:
        case 6:
        case 7:
            phi_a2 = (arg1 * 4) >> 4;
            break;
        }
    }

    if ((arg0->unk16C->unk80.bit) && (arg3 != 0) && ((arg0->health - phi_a2) > 0)) {
        if (phi_a2 > 0x1E0) {
            func_802DBA58_6ED108(0xE, arg0);
            func_8034A684_75BD34();
        } else if (phi_a2 > 0xC0) {
            func_802DBA58_6ED108(0xE, arg0);
            func_8034A914_75BFC4();
        } else if (phi_a2 >= 0x40) {
            func_802DBA58_6ED108(0xD, arg0);
            func_8034ABA4_75C254();
        }
    }

    if ((arg1 != 0) && (phi_a2 <= 0)) {
        phi_a2 = 1;
    }

    if (phi_a2 >= 0x23) {
        phi_a2 = 0x23;
    }
    func_80349280_75A930(arg0, phi_a2);
    arg0->health = MAX(0, arg0->health - phi_a2);
}

void func_802B3B48_6C51F8(Animal *arg0, Animal *arg1, s16 *arg2) {
    s16 orig = *arg2;
    s16 tmp;

    switch (arg0->unk16C->unkE6) {
    case 0:
        *arg2 = *arg2 * 36 >> 4;
        break;
    case 1:
        *arg2 = *arg2 * 24 >> 4;
        break;
    case 2:
        *arg2 = *arg2 * 16 >> 4;
        break;
    case 3:
        *arg2 = *arg2 * 8 >> 4;
        break;
    case 4:
        *arg2 = *arg2 * 5 >> 4;
        break;
    }

    if (arg0 != D_801DDD8C[gCurrentAnimalIndex].unk0) {
        tmp = arg0->unk16C->unkE6 - arg1->unk16C->unkE6;
        switch (tmp) {
        case 2:
            *arg2 = *arg2 >> 1;
            break;
        case 3:
            *arg2 = *arg2 >> 2;
            break;
        case 4:
            *arg2 = *arg2 >> 3;
            break;
        case 5:
        case 6:
        case 7:
            *arg2 = 0;
        }
    }

    if (orig != 0) {
        *arg2 = MAX(*arg2, 1);
    }
}

s16 func_802B3C9C_6C534C(s16 arg0, Animal *arg1) {
    if (arg0 == 0) {
        return 0;
    }

    switch (arg1->unk16C->unkE6) {
    case 0:
        arg0 = (arg0 * 32) >> 4;
        break;
    case 1:
        arg0 = (arg0 * 24) >> 4;
        break;
    case 2:
        break;
    case 3:
        arg0 = (arg0 * 10) >> 4;
        break;
    case 4:
        arg0 = (arg0 * 6) >> 4;
        break;
    }
    return  MAX(1, arg0);
}

s16 func_802B3D68_6C5418(void) {
    s16 x;
    s16 y;
    s16 z;

    f32 tmpf;

    if (D_803D5530->xPos < D_803F2C44) {
        tmpf = -(D_803D5530->xPos - D_803F2C44);
    } else {
        tmpf = D_803D5530->xPos - D_803F2C44;
    }
    x = (s16)tmpf >> 1;

    if (D_803D5530->zPos < D_803F2C48) {
        tmpf = -(D_803D5530->zPos - D_803F2C48);
    } else {
        tmpf = D_803D5530->zPos - D_803F2C48;
    }
    z = (s16)tmpf >> 1;

    if (D_803D5530->yPos < D_803F2C4C) {
        tmpf = -(D_803D5530->yPos - D_803F2C4C);
    } else {
        tmpf = D_803D5530->yPos - D_803F2C4C;
    }
    y = (s16)tmpf >> 1;

    return MAX(MAX(x, z), y) + x + z + y;
}
