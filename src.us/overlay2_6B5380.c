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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A3F68_6B5618.s")
// JUSTREG
// void func_802A3F68_6B5618(s32 *arg0, s32 *arg1) {
//     s32 temp_t6;
//     s32 temp_v1;
//
//     temp_v1 = D_803C0740_7D1DF0[D_803D5530->xPos >> 6][D_803D5530->zPos >> 6].unk7;
//     *arg0 += ((1 - (((temp_v1 >> 4) & 8) >> 2)) * (((temp_v1 & 0xF0) >> 4) & 7)) << 17;
//     if (0) { };
//     temp_t6 = D_803C0740_7D1DF0[D_803D5530->xPos >> 6][D_803D5530->zPos >> 6].unk7;
//     *arg1 += ((1 - ((temp_t6 & 8) >> 2)) * (temp_t6 & 7)) << 17;
// }

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
// void func_802A4220_6B58D0(s32 *arg0, s32 *arg1, s32 arg2) {
//     s32 temp_v0;
//     s32 temp_v1;
//
//     temp_v0 = ABS(*arg0);
//     temp_v1 = ABS(*arg1);
//
//     *arg0 = (*arg0 * temp_v0) >> 8;
//     *arg1 = (*arg1 * temp_v1) >> 8;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A4278_6B5928.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A50A8_6B6758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A5300_6B69B0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A628C_6B793C.s")
// NON-MATCHING: (almost) JUSTREG
// void func_802A628C_6B793C(void) {
//     s32 xVel;
//     s32 zVel;
//     s8 tmp;
//
//     func_802E4A78_6F6128(D_803D552C->unk308);
//     tmp = D_803F28E0[D_803F2A98].unk20;
//     xVel = (D_80152C78[(tmp + 64) & 0xff] >> 7) * D_801E9EB4;
//     zVel = (D_80152C78[tmp & 0xff] >> 7) * -D_801E9EB4;
//     D_803D5530->xVelocity.w += xVel * 16;
//     D_803D5530->zVelocity.w += zVel * 16;
//     D_803D552C->unk368 = 0;
//     D_803D5546 = 50;
//     func_802B2EA8_6C4558();
//     D_803D5530->unk162 = 3;
// }

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
// well this looks grim
// u16 func_802A6400_6B7AB0(void) {
//     u16 temp_v0;
//     u32 temp_t6;
//     u32 temp_t7;
//     u32 temp_t8;
//
//     temp_v0 = D_803D5530->state;
//     temp_t6 = temp_v0 - 0xB5;
//     if (temp_v0 >= 0x6B) {
//         if (temp_t6 < 5U) {
//             goto **(&jtbl803BADC0 + (temp_t6 * 4)); // switch 1
// block_3:
//             temp_t8 = temp_v0 - 2;
//             if (temp_v0 >= 7) {
//                 temp_t7 = temp_v0 - 0x65;
//                 if (temp_t7 < 6U) {
//                     goto **(&jtbl803BADD4 + (temp_t7 * 4)); // switch 2
// block_6:
//                     if (temp_t8 < 5U) {
//                         goto **(&jtbl803BADEC + (temp_t8 * 4)); // switch 3
//                     default: // switch 3
//                     case 0: // switch 3
//                         *temp_v1 = (u16)5U;
//                         return temp_v0;
//                     default: // switch 2
//                     case 0: // switch 2
//                         *temp_v1 = (u16)0x67U;
//                         return temp_v0;
//                     default: // switch 1
//                     case 0: // switch 1
//                         *temp_v1 = (u16)0xB8U;
//                     }
//                 }
//             } else {
//                 goto block_6;
//             }
//         }
//     } else {
//         goto block_3;
//     }
//     return temp_v0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A64B0_6B7B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A7648_6B8CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A78CC_6B8F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A935C_6BAA0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA0A0_6BB750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA1EC_6BB89C.s")

void func_802AA424_6BBAD4(void) {
    func_802AA444_6BBAF4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA444_6BBAF4.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA5C0_6BBC70.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AA85C_6BBF0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AAAB0_6BC160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AB8EC_6BCF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802ABB10_6BD1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC158_6BD808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC484_6BDB34.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC5CC_6BDC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC8A0_6BDF50.s")
//nonmatch: JUSTREG
// void func_802AC8A0_6BDF50(s32 *arg0, s32 *arg1) {
//     *arg0 = 0;
//     if (D_801E9EB2 > 2) {
//         *arg1 = D_803D5524->unkA4 * 1024;
//     } else if (D_801E9EB2 > 0) {
//         *arg1 = D_803D5524->unkA4 * 640;
//     } else {
//         *arg1 = 0;
//     }
//     func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
// }

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

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC980_6BE030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC9FC_6BE0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD0FC_6BE7AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD49C_6BEB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD63C_6BECEC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AF9FC_6C10AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B066C_6C1D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B0B00_6C21B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B0D4C_6C23FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B0F4C_6C25FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B10B0_6C2760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1210_6C28C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1374_6C2A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1654_6C2D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1918_6C2FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1B98_6C3248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1D00_6C33B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B1E28_6C34D8.s")

s16 func_802B2580_6C3C30(void) {
    return D_803D5530->yPos - func_802B25B4_6C3C64(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B25B4_6C3C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B2834_6C3EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B2964_6C4014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B2AF0_6C41A0.s")

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

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B315C_6C480C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B3230_6C48E0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B342C_6C4ADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B3474_6C4B24.s")
// void func_802B3474_6C4B24(void) {
//     D_801D9ED8->unk3EB4[gCurrentAnimalIndex].unk0->unk4A = 1;
//     D_801D9ED8->unk3EB4[gCurrentAnimalIndex].unk0->unk304 = D_801D9ED8->unk3EB4[gCurrentAnimalIndex].unk0->unk302;
// }

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

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B356C_6C4C1C.s")

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B38FC_6C4FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B3B48_6C51F8.s")
// JUSTREG - also need to confirm rodata
// void func_802B3B48_6C51F8(Animal *arg0, Animal *arg1, s16 *arg2) {
//     s16 temp_v1 = *arg2;
//
//     switch (arg0->unk16C->unkE6) {
//     case 0:
//         *arg2 = (*arg2 * 36) >> 4;
//         break;
//     case 1:
//         *arg2 = (*arg2 * 24) >> 4;
//         break;
//     case 2:
//         *arg2 = *arg2;
//         break;
//     case 3:
//         // ???
//         *arg2 = ((((*arg2) * 8) >> 4) & 0xFFFF) & 0xFFFF;
//         break;
//     case 4:
//         *arg2 = (*arg2 * 5) >> 4;
//     }
//
//     if (arg0 != D_801DDD8C[gCurrentAnimalIndex].unk0) {
//         s16 tmp = (s8)arg0->unk16C->unkE6 - (s8)arg1->unk16C->unkE6;
//         switch (tmp - 2) {
//         case 0:
//             *arg2 = *arg2 >> 1;
//             break;
//         case 1:
//             *arg2 = *arg2 >> 2;
//             break;
//         case 2:
//             *arg2 = *arg2 >> 3;
//             break;
//         case 3:
//         case 4:
//         case 5:
//             *arg2 = 0;
//         }
//     }
//
//     if (temp_v1 != 0) {
//         *arg2 = MAX(*arg2, 1);
//     }
// }

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
