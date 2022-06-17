#include <ultra64.h>
#include "common.h"

// .data
s32 D_803A05B0_7B1C60 = FTOFIX32(2.0);
s32 D_803A05B4_7B1C64 = FTOFIX32(4.0);

s32 func_8035E344_76F9F4(struct037 *, s32);
void func_802A467C_6B5D2C(s8 arg0);
void func_802AC158_6BD808(u16 arg0, s32 *arg1, s32 *arg2);

void func_802A3CD0_6B5380(void) {
    s16 xVel, zVel;

    if (D_803D5530->unk160 == 2) {
        func_80311AA8_723158(D_803D5530->xPos.h, D_803D5530->zPos.h, &D_803D5510, &D_803D5512);
    } else {
        func_80311BF8_7232A8(D_803D5530->xPos.h, D_803D5530->zPos.h, &D_803D5510, &D_803D5512);
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
            *arg1 = MIN(*arg1, FTOFIX32(-1.0));
        }
        if (D_803D5510 > 23) {
            *arg1 = MAX(*arg1, FTOFIX32(1.0));
        }
        if (D_803D5512 < -23) {
            *arg2 = MIN(*arg2, FTOFIX32(-1.0));
        }
        if (D_803D5512 > 23) {
            *arg2 = MAX(*arg2, FTOFIX32(1.0));
        }
    }
}

void func_802A3F68_6B5618(s32 *arg0, s32 *arg1) {
    *arg0 += ((((D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk7 & 0xF0) >> 4) & 7   ) * (1 - (((D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk7 >> 4) & 8) >> 2))) << 17;
    *arg1 += ((((D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk7 & 7)        ) & 0xFF) * (1 - (((D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk7     ) & 8) >> 2))) << 17;
}

void func_802A403C_6B56EC(Animal *arg0, s16 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_a2;

    temp_v0 = arg0->xVelocity.w;
    temp_a2 = D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk7;
    temp_v1 = arg0->zVelocity.w;

    temp_v0 = temp_v0 - (((1 - (((temp_a2 >> 4) & 8) >> 2)) * (((temp_a2 & 0xF0) >> 4) & 7)) << 17);
    temp_v1 = temp_v1 - (((1 - ((temp_a2 & 8) >> 2)) * ((u8)temp_a2 & 7)) << 17);

    arg0->xVelocity.w -= (temp_v0 >> arg1);
    arg0->zVelocity.w -= (temp_v1 >> arg1);
}

void func_802A40EC_6B579C(void) {
    s16 tmp;
    if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
        tmp = D_803D5524->unkBA;
    } else {
        tmp = D_803D5524->unkB8;
    }
    D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    D_803D5530->yVelocity.w -= ((D_803D5530->yPos.h + tmp) - func_80298F78_6AA628(D_803D5530->xPos.h, D_803D5530->zPos.h)) << 10;
}

void func_802A4184_6B5834(void) {
    s16 tmp = (D_803D5530->yPos.h + D_803D5524->unkBA) - func_80298F78_6AA628(D_803D5530->xPos.h, D_803D5530->zPos.h);
    if (tmp >= 0) {
        D_803D5530->yVelocity.w -= D_803A05B0;
    } else if (tmp >= -15) {
        D_803D5530->yVelocity.w -= ((tmp + 16) * D_803A05B0) >> 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A4220_6B58D0.s")
// what???
// void func_802A4220_6B58D0(s32 *arg0, s32 *arg1, u16 arg2) {
//     s32 temp_v0;
//     s32 temp_v1;
//
//     temp_v0 = ABS(*arg0);
//     temp_v1 = ABS(*arg1);
//
//     *arg0 = (*arg0 * temp_v0) >> 8;
//     *arg1 = (*arg1 * temp_v1) >> 8;
// }

// miles away: CURRENT (1000)
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A4278_6B5928.s")
// void func_802A4278_6B5928(u16 arg0, u16 arg1, s16 arg2) {
//     s16 pad;
//     s32 zVel;
//     s32 temp_t6_2;
//     s32 temp_t7_2;
//     s32 temp_t7_3;
//     s32 xVel;
//
//     xVel = D_803D5530->xVelocity.w;
//     zVel = D_803D5530->zVelocity.w;
//
//     temp_t7_2 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 5;
//     temp_t6_2 = D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 5;
//     temp_t7_3 = (((xVel >> 0xA) * temp_t7_2) + ((zVel >> 0xA) * temp_t6_2)) >> 0xA;
//     xVel = xVel - (((((xVel - (temp_t7_2 * temp_t7_3)) >> arg0) + (xVel >> arg1)) * arg2) >> 4);
//     zVel = zVel - (((((zVel - (temp_t6_2 * temp_t7_3)) >> arg0) + (zVel >> arg1)) * arg2) >> 4);
//     D_803D5530->xVelocity.w = xVel;
//     D_803D5530->zVelocity.w = zVel;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A467C_6B5D2C.s")
// almost justreg
// void func_802A467C_6B5D2C(s8 arg0) {
//     s16 xVel;
//     s16 zVel;
//     s16 sp60;
//     s16 sp5E;
//     s16 xVel2;
//     s16 zVel2;
//
//     s32 temp_v1_5;
//     Animal *animal;
//     u8 phi_v0;
//     s16 temp_a1;
//     s16 phi_v1;
//     s16 xPos;
//     s16 zPos;
//     s16 phi_t0;
//     s32 phi_t5;
//     s32 phi_a1_2;
//
//     if (D_803D5538 != 0) {
//         xPos = D_803D5564;
//         zPos = D_803D5568;
//         phi_v1 = D_803D556C;
//         animal = D_803D5560;
//     } else {
//         xPos = D_803D5530->xPos.h;
//         zPos = D_803D5530->zPos.h;
//         phi_v1 = D_803D5530->unk160;
//         animal = D_803D5530->unk6C;
//     }
//     D_803D552C->unk367 = 6;
//     D_803D552C->unk36D = 1;
//
//     if (animal != NULL) {
//         zVel = 0;
//         xVel = 0;
//     } else {
//         func_80311A2C_7230DC(xPos, zPos, &xVel, &zVel, phi_v1);
//     }
//     if ((animal == NULL) && ((xVel != 0) || (zVel != 0))) {
//         if (phi_v1 == 2) {
//             phi_v0 = D_803E1D30[D_803C0740[xPos >> 6][zPos >> 6].unk3].unk0;
//         } else {
//             phi_v0 = D_803E1D30[D_803C0740[xPos >> 6][zPos >> 6].unk2].unk0;
//         }
//
//         if (phi_v0 == 0) {
//             return;
//         }
//     }
//
//     D_803D552C->unk2F2 = 0;
//     D_803D552C->unk2F4 = 0;
//     D_803D552C->unk2FC = 22;
//
//     xVel2 = xVel;
//     zVel2 = zVel;
//
//     if (arg0 == 0) {
//         phi_t5 = D_803D5524->unkA6;
//     } else {
//         phi_t5 = D_803D5524->unkA8;
//     }
//
//     if ((ABS(xVel) > 23) || (ABS(zVel) > 23)) {
//         phi_t0 = 0;
//     } else {
//         phi_t0 = 1;
//     }
//
//     if ((phi_t0 == 0) && (D_803D5538 != 0)) {
//         func_80311A2C_7230DC(D_803D5566, D_803D556A, &sp60, &sp5E, D_803D556E);
//
//         if ((ABS(sp60) < 24) && (ABS(sp5E) < 24)) {
//             phi_t0 = 1;
//             xVel2 = sp60;
//             zVel2 = sp5E;
//         }
//     }
//
//     if (xVel2 < -23) {
//         D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -D_803D5524->unkA6 << 15);
//     }
//     if (xVel2 > 23) {
//         D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA6 << 15);
//     }
//     if (zVel2 < -23) {
//         D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -D_803D5524->unkA6 << 15);
//     }
//     if (zVel2 > 23) {
//         D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, D_803D5524->unkA6 << 15);
//     }
//
//     // store original?
//     temp_v1_5 = D_803D5530->yVelocity.w;
//
//     if (phi_t0 != 0) {
//         phi_a1_2 = phi_t5 << 16;
//         if ((D_803D5530->unk162 != 1) && (D_803D5530->unk162 != 6)) {
//             phi_a1_2 += D_803A05B0_7B1C60;
//         }
//         D_803D5530->yVelocity.w += phi_a1_2;
//     } else {
//         phi_a1_2 = phi_t5 << 12;
//         D_803D5530->yVelocity.w += phi_a1_2;
//     }
//
//     if (animal == NULL) {
//         D_803D5530->yVelocity.w = MIN(phi_a1_2, D_803D5530->yVelocity.w);
//         D_803D5530->yVelocity.w = MAX(temp_v1_5, D_803D5530->yVelocity.w);
//     } else {
//         D_803D5530->yVelocity.w = MIN(animal->yVelocity.w + phi_a1_2, D_803D5530->yVelocity.w);
//         D_803D5530->yVelocity.w = MAX(temp_v1_5, D_803D5530->yVelocity.w);
//     }
//     if (D_803D5530->state < 7) {
//         D_803D5530->unk162 = 3U;
//         D_803D5530->state = 5U;
//     } else {
//         if ((D_803D5530->state >= 0x19) &&
//                (D_803D5530->state >= 0x2B) &&
//                (D_803D5530->state >= 0x40) &&
//                (D_803D5530->state >= 0x52) &&
//                (D_803D5530->state >= 0x6B) &&
//                (D_803D5530->state >= 0x7C) &&
//                (D_803D5530->state >= 0x91) &&
//                (D_803D5530->state >= 0xA3) &&
//                (D_803D5530->state < 0xBA)) {
//             D_803D5530->unk162 = 7U;
//             D_803D5530->state = 0xB8U;
//         }
//     }
//
//     play_sound_effect_at_location(
//         D_803A65D0_7B7C80[D_803D5524->unk9C],
//         D_803A6680_7B7D30[D_803D5524->unk9C],
//         0,
//         D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
//
//     func_802B8890_6C9F40();
//
//     if ((animal != NULL) && (animal->unk162 == 5) && (animal->unk4C.unk29)) { //  & 4
//         if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } // regalloc
//         animal->yVelocity.w -= MAX((D_803D5530->unk44 << 0x13) / animal->unk44, FTOFIX32(4.0));
//     }
// }

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
        func_80311A2C_7230DC(D_803D5530->xPos.h, D_803D5530->zPos.h, &xVel, &zVel, D_803D5530->unk160);
    }
    if (xVel < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -D_803D5524->unkA6 << 0xF);
    }
    if (xVel > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA6 << 0xF);
    }
    if (zVel < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -D_803D5524->unkA6 << 0xF);
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
        func_80311A2C_7230DC(D_803D5530->xPos.h, D_803D5530->zPos.h, &xVel, &zVel, D_803D5530->unk160);
    }
    if (xVel < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -D_803D5524->unkA8 << 0xF);
    }
    if (xVel > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA8 << 0xF);
    }
    if (zVel < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -D_803D5524->unkA8 << 0xF);
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

#ifdef NON_MATCHING
// wtf is going on with arg1?
void func_802A5778_6B6E28(s16 arg0, s8 arg1) {
    s32 var_a1; // sp44
    s16 xVel;   // sp42
    s16 zVel;   // sp40

    D_803D552C->unk36D = 1;

    if ((D_803D5530->unk6C != NULL) || (arg1 != 0)) {
        zVel = 0; xVel = 0;
    } else {
        func_80311A2C_7230DC(D_803D5530->xPos.h, D_803D5530->zPos.h, &xVel, &zVel, D_803D5530->unk160);
    }

    if ((arg1 == 0) && (D_803D5530->unk6C == 0) && ((xVel != 0) || (zVel != 0))) {
        u8 var_v1;
        if (D_803D5530->unk160 == 2) {
            var_v1 = D_803E1D30[D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk3].unk0;
        } else {
            var_v1 = D_803E1D30[D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk2].unk0;
        }
        if (var_v1 == 0) {
            return;
        }
    }

    D_803D5530->state = 42;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 0x16;
    if (arg1 != 0) {
        var_a1 = (arg0 + 6) * (D_803D5524->unkA6 << 0xD);
    } else if (arg0 == 0) {
        var_a1 = (D_803D5524->unkA6 & 0xFFFF) << 0x10;
    } else {
        D_803D5530->xVelocity.w += (D_803D5524->unkA4 >> 6) * (D_80152C78[((D_803D5530->yRotation & 0xFF))]) * 2;
        D_803D5530->zVelocity.w += (D_803D5524->unkA4 >> 6) * (D_80152C78[(((D_803D5530->yRotation + 0x40) & 0xFF))]) * 2;
        var_a1 = (arg0 + 1) * (D_803D5524->unkA6 << 0xE);
    }

    if (xVel <= -24) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -var_a1 >> 3);
    }
    if (xVel >= 24) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, var_a1 >> 3);
    }
    if (zVel <= -24) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -var_a1 >> 3);
    }
    if (zVel >= 24) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, var_a1 >> 3);
    }

    if ((ABS(xVel) >= 24) || (ABS(zVel) >= 24)) {
        D_803D5530->yVelocity.w += var_a1 >> 4;
    } else {
        D_803D5530->yVelocity.w += var_a1;
    }

    D_803D5530->unk30C = MAX(6, D_803D5530->unk30C);

    play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);

    if ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk162 == 5) && (D_803D5530->unk6C->unk4C.unk29 != 0)) {
        D_803D5530->unk6C->yVelocity.w -= MIN(FTOFIX32(4.0), (D_803D5530->unk44 << 0x13) / D_803D5530->unk6C->unk44);
    }
    D_803D552C->unk368 = arg0 * 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A5778_6B6E28.s")
#endif

void func_802A5C80_6B7330(void) {
    D_803D5530->state = 41;
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
    D_803D5530->state = 144;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = -arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A6044_6B76F4(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 143;
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
    D_803D5530->state = 105;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 16;
    D_803D5530->unk162 = 2;
}

void func_802A61EC_6B789C(u16 rotation) {
    D_803D5530->state = 106;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A623C_6B78EC(s16 arg0, s16 arg1) {
    D_803D5530->state = 221;
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
    xVel = ((D_80152C78[(tmp + 64) & 0xff] >> 7) * D_801D9ED8.unkFFDC) * 16;
    zVel = ((D_80152C78[tmp & 0xff] >> 7) * -D_801D9ED8.unkFFDC) * 16;
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
//     case 101:
//     case 102:
//     case 103:
//     case 104:
//     case 105:
//     case 106:
//         D_803D5530->state = 103;
//         break;
//     case 0xB5:
//     case 0xB6:
//     case 0xB7:
//     case 0xB8:
//     case 0xB9:
//         D_803D5530->state = 184;
//         break;
//     }
// }

s32 func_802A64B0_6B7B60(void);
// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A64B0_6B7B60.s")

#if 0
// should match, need to decomp functions in between due to rodata
s32 func_802A7648_6B8CF8(Animal *arg0) {
    s16 pad[1];
    s16 temp_lo;
    u8 phi_v1;

    if (arg0->unk161 != 1) {
        arg0->unk54 |= (0x8|0x2);
    }
    if ((arg0->unk16C->objectType != 2) || (D_803F2D50.unk52 != 6) || ((s16)D_803F2D50.segment != 0)) {
        temp_lo = -arg0->yVelocity.h * arg0->unk44;
        if (arg0->unk44 > 120) {
            if (temp_lo > 2000) {
                play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, 1.0f);
            } else if (temp_lo > 500) {
                play_sound_effect_at_location(SFX_UNKNOWN_75, 0x2800, 0, arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, 1.5f);
            }
        }
    }

    switch (arg0->unk162 & 0xF) {
    default:
    case 1:
    case 2:
    case 3:
    case 4:
        arg0->unk162 = 1U;
        break;
    case 5:
    case 6:
    case 7:
        arg0->unk162 = 6U;
        break;
    }
    if (arg0->unk161 == 1) {
        return 0;
    }
    if (arg0->unk160 == 2) {
        phi_v1 = D_803E1D30[D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk3].unk3; // (*(&D_803C0743 + ((((s32) arg0->xPos.h >> 6) * 0x408) + (((s32) arg0->zPos.h;>> 6) * 8))) * 0xC);
    } else {
        phi_v1 = D_803E1D30[D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk2].unk3; // (*(&D_803C0742 + ((((s32) arg0->xPos.h >> 6) * 0x408) + (((s32) arg0->zPos.h;>> 6) * 8))) * 0xC);
    }
    if (phi_v1 < 17) {
        phi_v1 = 0;
    } else {
        phi_v1 -= 16;
    }

    if (func_80311D48_7233F8(arg0) != 0) {
        return 0;
    }
    if (phi_v1 == 0) {
        return 1;
    }

    arg0->yVelocity.w = ((ABS(arg0->yVelocity.w) * phi_v1) >> 4);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A7648_6B8CF8.s")
#endif

// requires jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A78CC_6B8F7C.s")

s32 func_8030AAE0_71C190(Animal*);
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802A935C_6BAA0C.s")
// void func_802A935C_6BAA0C(void) {
//     s32 sp7C;
//     s32 sp78;
//     s32 sp74;
//     s32 sp70;
//     s32 sp6C;
//     s32 sp60;
//     s32 sp5C;
//     s32 sp58;
//     s32 sp54;
//     u8 sp51;
//     Animal *sp3C;
//
//     s32 temp_v0_8;
//     s32 phi_v1;
//     s32 phi_a2;
//     s32 pad;
//     u16 traction;
//
//     if (D_803D5530->unk4A == 0) {
//         D_803D552C->unk2F4 = D_803D552C->unk2F2;
//         D_803D552C->unk2F2++;
//         if (D_803D552C->unk2F2 >= 0x4000) {
//             D_803D552C->unk2F2 -= 0x2000;
//         }
//         sp3C = D_803D5530->unk6C;
//         if (D_803D552C->unk367 > 0) {
//             D_803D552C->unk367--;
//         }
//         sp58 = D_803D552C->yPos.w;
//
//         switch ((D_803D5530->unk162 & 0xF) & 0xFF) {
//         case 1:
//             D_803D552C->yVelocity.w = (D_803D552C->yVelocity.w - D_803A05B4_7B1C64);
//             switch (func_8030AAE0_71C190(D_803D5530)) {                    /* switch 3; irregular */
//             case 1:                                 /* switch 3 */
//                 func_802A6400_6B7AB0();
//                 D_803D5530->unk162 = 3;
//                 D_803D552C->yVelocity.w = ((D_803D552C->yVelocity.w + D_803A05B4_7B1C64) - (D_803A05B0_7B1C60 * 2));
//                 break;
//             case 0:                                     /* switch 3 */
//             case 2:                                     /* switch 3 */
//                 break;
//             }
//
//             if ((D_803D5530->unk6C == sp3C) || (D_803D5530->unk6C == 0)) {
//                 D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//             }
//             func_802B2834_6C3EE4();
//             func_802A3CD0_6B5380();
//             func_802AC5CC_6BDC7C(&sp7C, &sp78);
//             traction  = (*D_803D5520)->traction;
//             if (D_803D5524->unk9C == WALRUS) {
//                 traction  = (traction  * 2);
//                 if (D_803D554C != 0) {
//                     D_803D5530->xVelocity.w += (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) << 8;
//                     D_803D5530->zVelocity.w += (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) << 8;
//                 }
//             } else {
//                 if (D_803D552C->unk36E != 0) {
//                     sp7C += (sp7C * D_803D552C->unk36E) >> 4;
//                     sp78 += (sp78 * D_803D552C->unk36E) >> 4;
//
//                     phi_a2 = ABS(D_803D5530->xVelocity.w);
//                     phi_v1 = ABS(D_803D5530->zVelocity.w);
//
//                     temp_v0_8 = MAX(phi_a2, phi_v1) + (MIN(phi_a2, phi_v1) >> 1);
//                     if ((D_803D5524->unkA4 << 0xB) < temp_v0_8) {
//                         traction  = (traction  / 4);
//                     } else if ((D_803D5524->unkA4 << 0xA) < temp_v0_8) {
//                         traction  = (traction  / 2);
//                     } else if (temp_v0_8 < (D_803D5524->unkA4 << 8)) {
//                         traction  += traction  >> 1;
//                     }
//                 }
//             }
//             func_802ABB10_6BD1C0(traction , &sp7C, &sp78);
//             func_802A3E70_6B5520(D_803D5530, &sp7C, &sp78);
//             D_803D552C->xVelocity.w = sp7C;
//             D_803D552C->zVelocity.w = sp78;
//             D_803D5530->unk10 = (s32) (D_803D5530->xPos.w + D_803D5530->xVelocity.w);
//             D_803D5530->unk14 = (s32) (D_803D5530->zPos.w + D_803D5530->zVelocity.w);
//             D_803D5530->unk18.w = (s32) ((D_803D5530->yPos.w + D_803D5530->yVelocity.w) - D_803A05B4_7B1C64);
//             break;
//         case 2:
//             switch (func_8030AAE0_71C190(D_803D5530)) {                    /* switch 4; irregular */
//             case 0:                                 /* switch 4 */
//                 if (func_802A64B0_6B7B60() != 0) {
//                     D_803D5530->yVelocity.w = (s32) (D_803D5530->yPos.w - sp58);
//                 }
//                 if ((D_803D5544 - D_803D5530->unk48) >= 4) {
//                     func_802DBA58_6ED108(6, D_803D552C);
//                 }
//                 break;
//             case 1:                                 /* switch 4 */
//                 D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//                 break;
//             case 2:                                 /* switch 4 */
//                 D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//                 break;
//             }
//             func_802B2834_6C3EE4();
//             func_802AC5CC_6BDC7C(&sp7C, &sp78);
//             func_802AC484_6BDB34(((u16)(*D_803D5520)->unkB6 * 0x64), &sp7C, &sp78);
//             D_803D5530->xVelocity.w = sp7C;
//             D_803D5530->zVelocity.w = sp78;
//             D_803D5530->unk10 = D_803D5530->xPos.w + D_803D5530->xVelocity.w;
//             D_803D5530->unk14 = D_803D5530->zPos.w + D_803D5530->zVelocity.w;
//             D_803D5530->unk18.w = D_803D5530->yPos.w + D_803D5530->yVelocity.w;
//             break; //goto block_95;
//         case 3:
//             switch (func_8030AAE0_71C190(D_803D5530)) {                   /* switch 5; irregular */
//             case 0:                                 /* switch 5 */
//                 if (func_802A64B0_6B7B60() != 0) {
//                     D_803D5530->yVelocity.w = (s32) (D_803D5530->yPos.w - sp58);
//                 }
//                 if ((D_803D5544 - D_803D5530->unk48) >= 4) {
//                     if (D_803D552C->unk364 == 3) {
//                         D_803D552C->unk364 = 4U;
//                         D_803D552C->unk334 = (u16) D_803D5544;
//                     } else {
//                         func_802DBA58_6ED108(6, D_803D552C);
//                     }
//                 }
//                 break;
//             case 1:                                 /* switch 5 */
//                 D_803D5530->yVelocity.w = (s32) (D_803D5530->yPos.w - sp58);
//                 break;
//             case 2:                                 /* switch 5 */
//                 D_803D5530->yVelocity.w = (s32) (D_803D5530->yPos.w - sp58);
//                 break;
//             }
//             func_802AC5CC_6BDC7C(&sp7C, &sp78);
//             func_802AC484_6BDB34(((*D_803D5520)->traction * 0x10), &sp7C, &sp78);
//             D_803D5530->xVelocity.w = sp7C;
//             D_803D5530->zVelocity.w = sp78;
//             func_802B2834_6C3EE4();
//             D_803D5530->yVelocity.w = (s32) (D_803D5530->yVelocity.w - D_803A05B0_7B1C60);
//             D_803D5530->unk10 = (s32) (D_803D5530->xPos.w + D_803D5530->xVelocity.w);
//             D_803D5530->unk14 = (s32) (D_803D5530->zPos.w + D_803D5530->zVelocity.w);
//             D_803D5530->unk18.w = (s32) (D_803D5530->yPos.w + D_803D5530->yVelocity.w);
//             break; //goto block_95;
//         case 4:
//             sp74 = D_803D5530->xPos.w;
//             sp70 = D_803D5530->zPos.w;
//             sp6C = D_803D5530->yPos.w;
//             switch (func_8030AAE0_71C190(D_803D5530)) {                   /* switch 6; irregular */
//             case 0:                                 /* switch 6 */
//                 if ((D_803D5530->unk6C == 0) && (D_803D5530->unk70 == 0)) {
//                     D_803D5530->xPos.w = sp74;
//                     D_803D5530->zPos.w = sp70;
//                     D_803D5530->yPos.w = sp6C;
//                 }
//                 break;
//             case 1:                             /* switch 6 */
//                 break;
//             case 2:                                 /* switch 6 */
//                 break;
//             }
//             D_803D5530->yVelocity.w = (D_803D5530->yPos.w - sp58);
//             func_802B2964_6C4014();
//             func_802A4220_6B58D0(&D_803D5530->xVelocity.w, &D_803D5530->zVelocity.w, 0xD2, D_803D5530);
//             func_802A403C_6B56EC(D_803D5530, 3);
//             func_802A4184_6B5834();
//             D_803D5530->unk10 = (D_803D5530->xPos.w + D_803D5530->xVelocity.w);
//             D_803D5530->unk14 = (D_803D5530->zPos.w + D_803D5530->zVelocity.w);
//             D_803D5530->unk18.w = (D_803D5530->yPos.w + D_803D5530->yVelocity.w);
//             break; //goto block_95;
//         case 5:
//             sp60 = D_803D5530->xPos.w;
//             sp5C = D_803D5530->zPos.w;
//             sp51 = D_803D5530->unk160;
//             if (func_8030AAE0_71C190(D_803D5530) != 0) {
//
//             }
//             if (func_802B2AF0_6C41A0(D_803D5530->xPos.w - sp60, D_803D5530->zPos.w - sp5C) != 0) {
//                 D_803D5530->unk160 = sp51;
//                 sp54 = D_803D5530->xPos.w;
//                 D_803D5530->xPos.w = sp60;
//                 if (func_802B2AF0_6C41A0(D_803D5530->xPos.w - sp60, D_803D5530->zPos.w - sp5C) != 0) {
//                     D_803D5530->xPos.w = sp54;
//                     D_803D5530->zPos.w = sp5C;
//                     if (func_802B2AF0_6C41A0(D_803D5530->xPos.w - sp60, D_803D5530->zPos.w - sp5C) != 0) {
//                         D_803D5530->xPos.w = sp60;
//                     }
//                 }
//             }
//             D_803D5530->yVelocity.w = (D_803D5530->yPos.w - sp58);
//             func_802B2964_6C4014();
//             func_802A40EC_6B579C();
//             func_802AC5CC_6BDC7C(&sp7C, &sp78);
//             func_802A3F68_6B5618(&sp7C, &sp78);
//             traction = (*D_803D5520)->unkB4; // not traction?
//             if (D_803D5524->unk9C == WALRUS) {
//                 traction = ((traction  * 5) >> 1);
//                 if (D_803D554C != 0) {
//                     D_803D5530->xVelocity.w = (D_803D5530->xVelocity.w + (((D_80152C78[((D_803D552C->unk302 & 0xFF))]) >> 7) << 8));
//                     D_803D5530->zVelocity.w = (D_803D5530->zVelocity.w + (((D_80152C78[(((D_803D552C->unk302 + 0x40) & 0xFF))]) >> 7) << 8));
//                 }
//             }
//             func_802AC158_6BD808(traction , &sp7C, &sp78);
//             D_803D5530->xVelocity.w = sp7C;
//             D_803D5530->zVelocity.w = sp78;
//             D_803D5530->unk10 = (D_803D5530->xPos.w + D_803D5530->xVelocity.w);
//             D_803D5530->unk14 = (D_803D5530->zPos.w + D_803D5530->zVelocity.w);
//             D_803D5530->unk18.w = (D_803D5530->yPos.w + D_803D5530->yVelocity.w);
//             break; //goto block_95;
//         case 6:
//             D_803D5530->yVelocity.w = (s32) (D_803D5530->yVelocity.w - D_803A05B0_7B1C60);
//             switch (func_8030AAE0_71C190(D_803D5530)) {                   /* switch 7; irregular */
//             case 1:                                 /* switch 7 */
//                 func_802A6400_6B7AB0();
//                 D_803D5530->unk162 = 7;
//                 break;
//             case 0:                                     /* switch 7 */
//             case 2:                                     /* switch 7 */
//                 break;
//             }
//             if ((D_803D5530->unk6C == sp3C) || (D_803D5530->unk6C == 0)) {
//                 D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//             }
//             func_802B2964_6C4014();
//             func_802A3CD0_6B5380();
//             func_802A403C_6B56EC(D_803D5530, 3);
//             func_802AC5CC_6BDC7C(&sp7C, &sp78);
//             func_802ABB10_6BD1C0((*D_803D5520)->traction, &sp7C, &sp78);
//             D_803D5530->xVelocity.w = sp7C;
//             D_803D5530->zVelocity.w = sp78;
//             D_803D5530->unk10 = D_803D5530->xPos.w + D_803D5530->xVelocity.w;
//             D_803D5530->unk14 = D_803D5530->zPos.w + D_803D5530->zVelocity.w;
//             D_803D5530->unk18.w = (D_803D5530->yPos.w + D_803D5530->yVelocity.w) - D_803A05B0_7B1C60;
//             break; //goto block_95;
//         case 7:
//             switch (func_8030AAE0_71C190(D_803D5530)) {                   /* switch 8; irregular */
//             case 0:                                 /* switch 8 */
//                 if (func_802A64B0_6B7B60() != 0) {
//                     D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//                 }
//                 break;
//             case 1:                                 /* switch 8 */
//                 D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//                 break;
//             case 2:                                 /* switch 8 */
//                 D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp58;
//                 break;
//             }
//             func_802B2964_6C4014();
//             D_803D5530->yVelocity.w = (s32) (D_803D5530->yVelocity.w - ((s32) D_803A05B0_7B1C60 >> 2));
//             func_802A403C_6B56EC(D_803D5530, 3);
//             D_803D5530->unk10 = (D_803D5530->xPos.w + D_803D5530->xVelocity.w);
//             D_803D5530->unk14 = (D_803D5530->zPos.w + D_803D5530->zVelocity.w);
//             D_803D5530->unk18.w = (D_803D5530->yPos.w + D_803D5530->yVelocity.w);
//             break; //goto block_95;
//         }
//
//         switch (D_803D5530->state) {                /* switch 2 */
//         case 0x2:                                   /* switch 2 */
//         case 0x3:                                   /* switch 2 */
//         case 0x4:                                   /* switch 2 */
//         case 0x5:                                   /* switch 2 */
//         case 0x6:                                   /* switch 2 */
//         case 0x15:                                  /* switch 2 */
//         case 0x16:                                  /* switch 2 */
//         case 0x17:                                  /* switch 2 */
//         case 0x18:                                  /* switch 2 */
//         case 0x29:                                  /* switch 2 */
//         case 0x3D:                                  /* switch 2 */
//         case 0x3E:                                  /* switch 2 */
//         case 0x65:                                  /* switch 2 */
//         case 0x68:                                  /* switch 2 */
//         case 0x69:                                  /* switch 2 */
//         case 0x79:                                  /* switch 2 */
//         case 0x7A:                                  /* switch 2 */
//         case 0x7B:                                  /* switch 2 */
//         case 0x8D:                                  /* switch 2 */
//         case 0x8E:                                  /* switch 2 */
//         case 0x8F:                                  /* switch 2 */
//         case 0x90:                                  /* switch 2 */
//         case 0xA1:                                  /* switch 2 */
//         case 0xA2:                                  /* switch 2 */
//         case 0xB5:                                  /* switch 2 */
//         case 0xB6:                                  /* switch 2 */
//         case 0xB7:                                  /* switch 2 */
//         case 0xB9:                                  /* switch 2 */
//         case 0xC9:                                  /* switch 2 */
//         case 0xCA:                                  /* switch 2 */
//         case 0xCB:                                  /* switch 2 */
//         case 0xCC:                                  /* switch 2 */
//             D_803D552C->unk304 = D_803D552C->unk302;
//             func_802DB940_6ECFF0(&D_803D552C->unk302, D_803D552C->yRotation, D_803D5524->unkB0);//, D_803D5530);
//             break;
//         case 0x51:                                  /* switch 2 */
//             D_803D552C->unk304 = D_803D552C->unk302;
//             D_803D552C->unk302 = D_803D5530->yRotation;
//             break;
//         }
//         func_802B3230_6C48E0();
//
//         // hard level borders
//         if (D_803D5530->xPos.h < 128) {
//             D_803D5530->xPos.h = 128;
//             D_803D5530->xVelocity.w = 0;
//         }
//         if (D_803D5530->zPos.h < 128) {
//             D_803D5530->zPos.h = 128;
//             D_803D5530->zVelocity.w = 0;
//         }
//         if (D_803D5530->xPos.h > (35 * 128) - 1) {
//             D_803D5530->xPos.h = (35 * 128) - 1;
//             D_803D5530->xVelocity.w = 0;
//         }
//         if (D_803D5530->zPos.h > (63 * 128) - 1) {
//             D_803D5530->zPos.h = (63 * 128) - 1;
//             D_803D5530->zVelocity.w = 0;
//         }
//     }
// }

void func_802AA0A0_6BB750(void) {
    if ((D_803D552C->unk366 != 4) &&
        ((D_803D5530->state == 2) || (D_803D5530->state == 0x15) || (D_803D5530->state == 0x29) || (D_803D5530->state == 0x79)) &&
        (SSSV_RAND(32) == 0) && (D_803F6450 != 0)) {
        func_802AA5C0_6BBC70();
    }
    if ((D_803D5530->unk4B > 32) && (D_803D5530->unk4C.unk26 == 0)) {
        D_803D5530->health = MAX(0, D_803D5530->health - 1);
        func_80349280_75A930(D_803D5530, 1);

        if (D_803D5530->unk4B > 48) {
            D_803D5530->health = MAX(0, D_803D5530->health - 1);
            func_80349280_75A930(D_803D5530, 1);
        }

        if (D_803D5530->unk4B > 60) {
            D_803D5530->health = 0;
            func_80349280_75A930(D_803D5530, 40);
        }
    }
}

void func_802AA1EC_6BB89C(void) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    u8 sp37;

    if (D_803D5530->state != 0x1F) {
        switch (D_803D5530->unk162 & 0xF) {
        case 4:
        case 5:
        case 6:
        case 7:
            sp3C = D_803D5530->xPos.w;
            sp38 = D_803D5530->zPos.w;
            sp37 = D_803D5530->unk160;
            func_802AA444_6BBAF4();
            if (func_802B2AF0_6C41A0(D_803D5530->xPos.w - sp3C, D_803D5530->zPos.w - sp38) != 0) {
                D_803D5530->unk160 = sp37;
                D_803D5530->xPos.w = sp3C;
                D_803D5530->zPos.w = sp38;
            }
            func_802B2964_6C4014();
            func_802A40EC_6B579C();
            sp40 = 0;
            sp44 = 0;
            func_802A3F68_6B5618(&sp44, &sp40);
            func_802AC158_6BD808(3, &sp44, &sp40);
            D_803D5530->xVelocity.w = sp44;
            D_803D5530->zVelocity.w = sp40;
            break;
        case 2:
        case 3:
            func_802AA444_6BBAF4();
            if ((D_803D5530->unk162 == 1) && (D_803D5530->yVelocity.h < -0xA)) {
                play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 0.5f);
            }
            func_802B2834_6C3EE4();
            D_803D552C->yVelocity.w -= D_803A05B0_7B1C60;
            break;
        default:
            func_802AA444_6BBAF4();
            func_802B2834_6C3EE4();
            func_802A3CD0_6B5380();
            sp40 = 0;
            sp44 = 0;
            func_802ABB10_6BD1C0(30, &sp44, &sp40);
            func_802A3E70_6B5520(D_803D5530, &sp44, &sp40);
            D_803D552C->xVelocity.w = sp44;
            D_803D552C->zVelocity.w = sp40;
            D_803D552C->yVelocity.w -= D_803A05B0_7B1C60;
            break;
        }
    }
    D_803D552C->unk304 =  D_803D552C->unk302 = D_803D552C->yRotation;
}

void func_802AA424_6BBAD4(void) {
    func_802AA444_6BBAF4();
}

void func_802AA444_6BBAF4(void) {
    s32 sp1C;
    s32 temp_v0;

    sp1C = D_803D552C->yPos.w;
    switch (D_803D5530->unk162 & 0xF) {
    case 1:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        if ((temp_v0 != 0) && (temp_v0 == 1)) {
            D_803D5530->unk162 = 3;
        }
        break;
    case 2:
    case 3:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        switch (temp_v0) {
        case 0:
            D_803D5530->unk162 = 1;
            break;
        case 1:
            D_803D5530->unk162 = 3;
            break;
        }
        break;
    case 4:
    case 5:
    case 7:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        switch (temp_v0) {
        case 0:
            D_803D5530->unk162 = 6;
            break;
        case 1:
            D_803D5530->unk162 = 5;
            break;
        }
        break;
    case 6:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        if ((temp_v0 != 0) && (temp_v0 == 1)) {
            D_803D5530->unk162 = 7;
        }
        break;
    }
    D_803D5530->yVelocity.w = D_803D5530->yPos.w - sp1C;
}

void func_802AA5C0_6BBC70(void) {
    u8 rand = (func_8012826C() >> 8) & 0xF;
    switch (rand) {
    case 0:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 1;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 1:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 1;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 2:
        if ((D_803D5528->unk398.unk10 == 0) && (D_803D5528->unk3AC.unk10 == 0)) {
            D_803D5528->unk398.unk10 = 1;
            D_803D5528->unk398.unk12 = 0;
        }
        break;
    case 3:
        if ((D_803D5528->unk3AC.unk10 == 0) && (D_803D5528->unk398.unk10 == 0)) {
            D_803D5528->unk3AC.unk10 = 1;
            D_803D5528->unk3AC.unk12 = 0;
        }
        break;
    case 4:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 11;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 5:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 11;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 6:
        if ((D_803D5528->unk398.unk10 == 0) && (D_803D5528->unk3AC.unk10 == 0)) {
            D_803D5528->unk398.unk10 = 11;
            D_803D5528->unk398.unk12 = 0;
        }
        break;
    case 7:
        if ((D_803D5528->unk3AC.unk10 == 0) && (D_803D5528->unk398.unk10 == 0)) {
            D_803D5528->unk3AC.unk10 = 11;
            D_803D5528->unk3AC.unk12 = 0;
        }
        break;
    case 8:
    case 9:
        if ((D_803D5528->unk3C0 == 0) && (D_803D5524->unk9C != RACING_DOG) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0 = 1;
            D_803D5528->unk3C2 = 0;
        }
        break;
    case 10:
    case 11:
        if ((D_803D5528->unk3C0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0 = 5;
            D_803D5528->unk3C2 = 0;
        }
        break;
    }
}

void func_802AA85C_6BBF0C(void) {
    u8 rand = (func_8012826C() >> 8) & 0xF;

    switch (rand) {
    case 0:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 1;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 1:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 1;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 2:
        break;
    case 3:
        if ((D_803D5528->unk3C0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0 = 17;
            D_803D5528->unk3C2 = 0;
        }
        break;
    case 4:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 11;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 5:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 11;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 6:
        if ((D_803D5528->unk398.unk10 == 0) && (D_803D5528->unk3AC.unk10 == 0)) {
            D_803D5528->unk398.unk10 = 11;
            D_803D5528->unk398.unk12 = 0;
        }
        break;
    case 7:
        if ((D_803D5528->unk3AC.unk10 == 0) && (D_803D5528->unk398.unk10 == 0)) {
            D_803D5528->unk3AC.unk10 = 11;
            D_803D5528->unk3AC.unk12 = 0;
        }
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        if ((D_803D5528->unk3C0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0 = 5;
            D_803D5528->unk3C2 = 0;
        }
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        if ((D_803D5528->unk3C0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0 = 19;
            D_803D5528->unk3C2 = 0;
        }
        break;
    }
}

void func_802AAAB0_6BC160(void) {
    u16 state;

    if ((D_803D552C->unk360 != 0) && (--D_803D552C->unk360 == 0)) {
        func_802A467C_6B5D2C(D_803D552C->unk361);
    }

    state = D_803D5530->state;
    if (state < 7) {
        func_802AC980_6BE030();
        func_802AD87C_6BEF2C();
    } else if (state < 25) {
        func_802AC980_6BE030();
        func_802AE278_6BF928();
    } else if (state < 0x2B) {
        func_802AC980_6BE030();
        func_802AE9C4_6C0074();
    } else if (state < 0x40) {
        func_802AD63C_6BECEC();
        func_802AEE18_6C04C8();
    } else if (state < 0x52) {
        func_802AD63C_6BECEC();
        func_802AE698_6BFD48();
    } else if (state < 0x6B) {
        func_802AC980_6BE030();
        func_802AF9FC_6C10AC();
    } else if (state < 0x7C) {
        func_802AC980_6BE030();
        func_802AEBB0_6C0260();
    } else if (state < 0x91) {
        func_802AC980_6BE030();
        func_802AF308_6C09B8();
    } else if (state < 0xA3) {
        func_802AC980_6BE030();
        func_802AF7E4_6C0E94();
    } else if (state < 0xBA) {
        func_802AC980_6BE030();
        func_802ADDD0_6BF480();
    } else if (state < 0xCD) {
        func_802AC980_6BE030();
        func_802AE488_6BFB38();
    } else if (state < 0xDE) {
        func_802AD63C_6BECEC();
        func_802B066C_6C1D1C();
    }

    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A == 0) {
        if ((D_801D9ED8.unkFFB2 != 0) &&
            ((D_803D552C->skillAEnergy[1] == 0) || (D_803D552C->skillAEnergy[1] == 0x7FFE)) &&
            (func_8035E344_76F9F4(D_803D5520, 0))) {

            switch (D_803D5524->unk9C) {
            case FLYING_DOG:
                func_802EE89C_6FFF4C();
                break;
            case BEAR:
                func_803277B4_738E64();
                break;
            case MYSTERY_BEAR:
                func_803279BC_73906C();
                break;
            case RACING_DOG:
                func_802EEA7C_70012C();
                break;
            case FIRE_FOX:
                func_802E84E0_6F9B90();
                break;
            case FOX:
            case RACING_FOX:
                func_802E864C_6F9CFC();
                break;
            case RACING_MOUSE:
                func_8031F8BC_730F6C();
                break;
            case RAT:
                func_8035F92C_770FDC();
                break;
            case CANNON_CAMEL:
                func_8036F404_780AB4();
                break;
            case SCORPION:
                func_80379048_78A6F8();
                break;
            case KING_PENGUIN:
                func_80365954_777004();
                break;
            case WALRUS:
                func_803766E8_787D98();
                break;
            case SKI_HUSKY:
                func_8036BBE8_77D298();
                break;
            case POLAR_TANK:
                func_80368B78_77A228();
                break;
            case CHAMELEON:
                func_8035C018_76D6C8();
                break;
            case HYENA_BIKER:
                func_8035A170_76B820();
                break;
            case HIPPO:
                func_802F0374_701A24();
                break;
            case ELEPHANT:
                func_8037D06C_78E71C();
                break;
            case RACING_TORTOISE:
                func_80355F64_767614();
                break;
            case SHEEP:
                func_80362618_773CC8();
                break;
            case TORTOISE_TANK:
                func_80355EDC_76758C();
                break;
            case SPRINGY_THINGY:
                func_80362A00_7740B0();
                break;
            case KING_RAT:
                func_8035FA84_771134();
                break;
            case EVO_SHELLSUIT:
                func_8038B330_79C9E0();
            }
        } else {
            if ((D_801D9ED8.unkFFB2 == 0) && (D_803D552C->skillAEnergy[1] == 0x7FFF)) {
                D_803D552C->skillAEnergy[1] = 0;
            }
            if (D_803D552C->skillAEnergy[1] == 0x7FFE) {
                D_803D552C->skillAEnergy[1] = 0x7FFF;
            }

            switch (D_803D5524->unk9C) {
            case FLYING_DOG:
                func_802EE9EC_70009C();
                break;
            case ELEPHANT:
                func_8037D0EC_78E79C();
                break;
            case KING_RAT:
                func_8035FAEC_77119C();
                break;
            case SHEEP:
                func_80362964_774014();
                break;
            }
        }

        if ((D_801D9ED8.unkFFB6 != 0) &&
            ((D_803D552C->skillBEnergy[1] == 0) || (D_803D552C->skillBEnergy[1] == 0x7FFE)) &&
            func_8035E344_76F9F4(D_803D5520, 1)) {

            switch (D_803D5524->unk9C) {
            case FLYING_DOG:
                func_802EEA18_7000C8();
                break;
            case BEAR:
                func_8032786C_738F1C();
                break;
            case PARROT:
                func_803144F8_725BA8();
                break;
            case COOL_COD:
                func_80383804_794EB4();
                break;
            case PIRANA:
                func_80382C9C_79434C();
                break;
            case DOG:
                func_802EEA54_700104();
                break;
            case RACING_DOG:
                func_802EEC44_7002F4();
                break;
            case FIRE_FOX:
                func_802E8500_6F9BB0();
                break;
            case FOX:
            case RACING_FOX:
                func_802E86C8_6F9D78();
                break;
            case MOUSE:
                func_8031F87C_730F2C();
                break;
            case RACING_MOUSE:
                func_8031FA84_731134();
                break;
            case RAT:
                func_8035FA5C_77110C();
                break;
            case CAMEL:
                func_8036F3AC_780A5C();
                break;
            case CANNON_CAMEL:
                func_8036F4CC_780B7C();
                break;
            case SCORPION:
                func_80379070_78A720();
                break;
            case BOXING_KANGAROO:
                func_80372510_783BC0();
                break;
            case POGO_KANGAROO:
                func_803725A4_783C54();
                break;
            case VULTURE:
            case VULTURE2:
                func_8036D30C_77E9BC();
                break;
            case SEAGULL:
            case SEAGULL2:
                func_80381C60_793310();
                break;
            case DESERT_FOX:
                func_80374470_785B20();
                break;
            case ARMED_DESERT_FOX:
                func_803744C4_785B74();
                break;
            case PENGUIN:
                func_80365C28_7772D8();
                break;
            case KING_PENGUIN:
                func_80365C7C_77732C();
                break;
            case WALRUS:
                func_803769E0_788090();
                break;
            case HUSKY:
                func_8036BBB8_77D268();
                break;
            case SKI_HUSKY:
                func_8036BCF8_77D3A8();
                break;
            case POLAR_BEAR:
                func_80368AC4_77A174();
                break;
            case POLAR_TANK:
                func_80368BA0_77A250();
                break;
            case RABBIT:
                func_80302018_7136C8();
                break;
            case HELI_RABBIT:
                func_80302080_713730();
                break;
            case GORILLA:
                func_8037B590_78CC40();
                break;
            case CHAMELEON:
                func_8035C08C_76D73C();
                break;
            case HYENA:
                func_8035A130_76B7E0();
                break;
            case HYENA_BIKER:
                func_8035A2A8_76B958();
                break;
            case LION:
                func_802F2A2C_7040DC();
                break;
            case HIPPO:
                func_802F03B8_701A68();
                break;
            case ELEPHANT:
                func_8037D138_78E7E8();
                break;
            case TORTOISE_TANK:
                func_80355EFC_7675AC();
                break;
            case RACING_TORTOISE:
                func_80355FFC_7676AC();
                break;
            case RAM:
            case SPRINGY_RAM:
                func_80362A10_7740C0();
                break;
            case SHEEP:
            case SPRINGY_THINGY:
                func_803629B0_774060();
                break;
            case FROG:
                func_80302D5C_71440C();
                break;
            case KING_RAT:
                func_8035FB10_7711C0();
                break;
            case EVO_SHELLSUIT:
                func_8038B730_79CDE0();
                break;
            }
        } else {
            if ((D_801D9ED8.unkFFB6 == 0) && (D_803D552C->skillBEnergy[1] == 0x7FFF)) {
                D_803D552C->skillBEnergy[1] = 0;
            }
            if (D_803D552C->skillBEnergy[1] == 0x7FFE) {
                D_803D552C->skillBEnergy[1] = 0x7FFF;
            }

            switch (D_803D5524->unk9C) {
            case FOX:
            case RACING_FOX:
                func_802E8760_6F9E10();
                break;
            case MOUSE2:
                func_8031F89C_730F4C();
                break;
            case PARROT_ATTACKING:
                func_80314590_725C40();
                break;
            case TORTOISE_TANK_DEFENDING:
                func_80356064_767714();
                break;
            case RACING_TORTOISE_DEFENDING:
                func_803560CC_76777C();
                break;
            case SNEAKY_CHAMELEON:
                func_8035C0CC_76D77C();
                break;
            case CRAZY_BEAR:
                func_803278D4_738F84();
                break;
            case HARD_MOUSE:
                func_8031FAD8_731188();
                break;
            case CRAZY_HUSKY:
                func_8036BE70_77D520();
                break;
            case POLAR_BEAR_DEFENDING:
                func_80368B04_77A1B4();
                break;
            case DESERT_FOX_ATTACKING:
                func_80374518_785BC8();
                break;
            case KING_RAT:
                func_8035FC08_7712B8();
                break;
            case KING_PENGUIN:
                func_80365D74_777424();
                break;
            case PIRANA:
                func_80382CB0_794360();
                break;
            case EVO_SHELLSUIT:
                func_8038B774_79CE24();
                break;
            // why does this matter
            default:
                break;
            }
        }

        switch (D_803D5524->unk9C) {
        case BEAR:
            func_80327908_738FB8();
            break;
        case TORTOISE_TANK:
            func_80355918_766FC8();
            break;
        case GORILLA:
            func_8037B660_78CD10();
            break;
        }
    }

    if ((D_801D9ED8.unkFFDA != 0) ||
        (D_801D9ED8.unkFFB2 != 0) ||
        (D_801D9ED8.unkFFB6 != 0)) {
        D_803D552C->unk35E = D_803D5544;
    }
}

void func_802AB8EC_6BCF9C(u8 rotation, s8 arg1, s16 yOffset) {
    if (D_803D552C->unk360 != 0) {
        if (--D_803D552C->unk360 == 0) {
            func_802A467C_6B5D2C(D_803D552C->unk361);
        }
    }
    if (D_803D552C->unk363 != 0) {
        arg1 = 0;
        yOffset = 0;
    }
    if ((arg1 != 0) && (arg1 != -1)) {
        D_803D552C->unk35E = D_803D5544;
    }

    if (D_803D5530->state < 7) {
        func_802B0B00_6C21B0(rotation, arg1);
    } else if (D_803D5530->state < 0x19) {
        func_802B0F4C_6C25FC(rotation, arg1);
    } else if (D_803D5530->state < 0x2B) {
        func_802B1210_6C28C0(rotation, arg1);
    } else if (D_803D5530->state < 0x40) {
        func_802B1374_6C2A24(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x52) {
        func_802B1654_6C2D04(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x6B) {
        func_802B1E28_6C34D8(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x7C) {
        func_802B1918_6C2FC8(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x91) {
        func_802B1B98_6C3248(rotation, arg1);
    } else if (D_803D5530->state < 0xA3) {
        func_802B1D00_6C33B0(rotation, arg1);
    } else if (D_803D5530->state < 0xBA) {
        func_802B0D4C_6C23FC(rotation, arg1);
    } else if (D_803D5530->state < 0xCD) {
        func_802B10B0_6C2760(rotation, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802ABB10_6BD1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC158_6BD808.s")
#if 0
// miles away
void func_802AC158_6BD808(u16 arg0, s32 *arg1, s32 *arg2) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp30;
    s32 sp24;
    s32 sp20;
    s32 temp_lo;
    s32 temp_t2;
    s32 temp_t3;
    s32 temp_t4;

    s32 temp_v1_3;

    s32 phi_a3;
    s32 phi_a2;
    s32 phi_t0;

    s32 tmpx;
    s32 tmpz;

    temp_t3 = D_803D5530->xVelocity.w;
    temp_t4 = D_803D5530->zVelocity.w;

    if ((D_803D5530->unk161 == 1) && (D_803D5530->unk68 != NULL)) {
        phi_a2 = (*arg1 + D_803D5530->unk68->xVelocity.w) - temp_t3;
        phi_a3 = (*arg2 + D_803D5530->unk68->zVelocity.w) - temp_t4;
    } else {
        phi_a2 = *arg1 - temp_t3;
        phi_a3 = *arg2 - temp_t4;
    }

    phi_t0 = arg0 * 4;
    if ((D_803D5544 - D_803D5530->unk48) < 5) {
        sp40 = temp_t4;
        sp44 = temp_t3;
        sp20 = phi_t0;
        sp24 = arg0;
        sp30 = phi_t0;
        sp38 = phi_a3;
        sp3C = phi_a2;
        phi_t0 = sp30;
        if ((D_803D5530->yPos.h - (func_8031124C_7228FC(D_803D5530->xPos.h, D_803D5530->zPos.h) >> 16)) < 32) {
            temp_lo = D_803E1D30[D_803C0740[D_803D5530->xPos.h >> 6][D_803D5530->zPos.h >> 6].unk2].unk0 * arg0;
            if (temp_lo >= phi_t0) {
                phi_t0 = temp_lo;
            }
        }
    }
    sp3C = phi_a2;
    sp38 = phi_a3;
    sp30 = phi_t0;
    sp44 = D_803D5530->xVelocity.w;
    sp40 = D_803D5530->zVelocity.w;
    temp_v1_3 = func_802AC928_6BDFD8(phi_a2, phi_a3) >> 8;
    if (temp_v1_3 == 0) {
        *arg1 = sp44 + phi_a2;
        *arg2 = sp40 + phi_a3;
    } else if (temp_v1_3 < phi_t0) {
        *arg1 = sp44 + phi_a2;
        *arg2 = sp40 + phi_a3;
    } else if (temp_v1_3 < (phi_t0 * 5)) {
        tmpx = ((phi_a2 >> 8) * phi_t0) / temp_v1_3;
        tmpz = ((phi_a3 >> 8) * phi_t0) / temp_v1_3;
        *arg1 = (tmpx << 8) + sp44;
        *arg2 = (tmpz << 8) + sp40;
    } else {
        tmpx = ((phi_a2 >> 8) * phi_t0) / temp_v1_3;
        tmpz = ((phi_a3 >> 8) * phi_t0) / temp_v1_3;
        *arg1 = (tmpx << 8) + sp44;
        *arg2 = (tmpz << 8) + sp40;
    }
}
#endif

void func_802AC484_6BDB34(u16 arg0, s32 *arg1, s32 *arg2) {
    s32 xVel;
    s32 zVel;
    s32 xVelDiff;
    s32 zVelDiff;
    s32 temp_v1;
    s32 sp28;
    s32 pad2[2];

    xVel = D_803D5530->xVelocity.w;
    zVel = D_803D5530->zVelocity.w;
    sp28 = arg0;
    xVelDiff = *arg1 - xVel;
    zVelDiff = *arg2 - zVel;
    temp_v1 = func_802AC928_6BDFD8(xVelDiff, zVelDiff) >> 8;
    if ((temp_v1 != 0) && (temp_v1 >= arg0)) {
        xVelDiff = ((xVelDiff / 256) * sp28) / temp_v1;
        zVelDiff = ((zVelDiff / 256) * sp28) / temp_v1;
        *arg1 = (xVelDiff << 8) + xVel;
        *arg2 = (zVelDiff << 8) + zVel;
    }
}

void func_802AC5CC_6BDC7C(s32 *arg0, s32 *arg1) {
    if (D_803D5530->yRotation == 256) {
        *arg0 = 0;
        *arg1 = 0;
        return;
    }

    switch (D_803D5530->state) {
    case 0x2:
    case 0x15:
    case 0x29:
    case 0x3D:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x6A:
    case 0x79:
    case 0x7B:
    case 0x8D:
    case 0xA1:
    case 0xB5:
    case 0xB8:
    case 0xC9:
    case 0xDD:
        *arg0 = 0;
        *arg1 = 0;
        break;
    case 0x3:
    case 0x5:
    case 0x16:
    case 0x3E:
    case 0x7A:
    case 0xA2:
    case 0xB6:
    case 0xCA:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkA4 * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x6:
    case 0x18:
    case 0xCC:
        *arg0 = 0;
        *arg1 = -(D_803D5524->unkA4 * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x4:
    case 0x17:
    case 0x2A:
    case 0xB7:
    case 0xCB:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkA4 * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x68:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAC * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x69:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAC * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x51:
        *arg0 = 0;
        *arg1 = D_803D5524->unkAC << 0xA;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x8E:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAA * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x90:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAA * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x8F:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAA * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    default:
        *arg0 = 0;
        *arg1 = 0;
        break;
    }
}

#ifdef NON_MATCHING // JUSTREG
void func_802AC8A0_6BDF50(s32 *arg0, s32 *arg1) {
    *arg0 = 0;

    if (D_801D9ED8.unkFFDA > 2) {
        *arg1 = D_803D5524->unkA4 * 1024;
    } else if (D_801D9ED8.unkFFDA > 0) {
        *arg1 = D_803D5524->unkA4 * 640;
    } else {
        *arg1 = 0;
    }

    // regalloc help?
    if ((D_803D5524->unkA4 && D_803D5524->unkA4) && D_803D5524->unkA4) {};

    func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC8A0_6BDF50.s")
#endif

s32 func_802AC928_6BDFD8(s32 arg0, s32 arg1) {
    arg0 = ABS(arg0);
    arg1 = ABS(arg1);

    if (arg1 >= arg0) {
        return arg1 + (arg0 / 2);
    } else {
        return arg0 + (arg1 / 2);
    }
}

void func_802AC980_6BE030(void) {
    switch (D_803F28E0[D_803F2A98].cameraMode) {
    case 3:
    case 5:
    case 6:
    case 7:
    case 17:
    case 28:
        func_802AD0FC_6BE7AC();
        break;
    default:
        func_802AC9FC_6BE0AC();
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AC9FC_6BE0AC.s")
// void func_802AC9FC_6BE0AC(void) {
//     static s16 D_803D5574; // .bss
//     s16 var_a1;
//     s16 var_a2;
//     s16 var_v1_2;
//     s16 temp_v0;
//
//     if (ABS(D_801D9ED8.unkFFD8) <= 10) {
//         var_a1 = 0;
//     } else if (D_801D9ED8.unkFFD8 > 0) {
//         var_a1 = D_801D9ED8.unkFFD8 - 10;
//     } else {
//         var_a1 = D_801D9ED8.unkFFD8 + 10;
//     }
//
//     if (ABS(D_801D9ED8.unkFFD9) <= 10) {
//         var_a2 = 0;
//     } else if (D_801D9ED8.unkFFD9 > 0) {
//         var_a2 = D_801D9ED8.unkFFD9 - 10;
//     } else {
//         var_a2 = D_801D9ED8.unkFFD9 + 10;
//     }
//
//     temp_v0 = sqrtf(((f32) var_a1 * (f32) var_a1) + ((f32) var_a2 * (f32) var_a2));
//
//     D_801D9ED8.unkFFDA = 0;
//     if (temp_v0 >= 18) {
//         D_801D9ED8.unkFFDA = 1;
//     }
//     if (temp_v0 >= 26) {
//         D_801D9ED8.unkFFDA = 2;
//     }
//     if (temp_v0 >= 38) {
//         D_801D9ED8.unkFFDA = 3;
//     }
//     if (temp_v0 >= 56) {
//         D_801D9ED8.unkFFDA = 4;
//     }
//
//     if (temp_v0 == 0) {
//         D_801D9ED8.unkFFA8 = 0x100;
//     } else {
//         if (ABS(var_a2) >= ABS(var_a1)) {
//             if (var_a2 >= 0) {
//                 var_v1_2 = func_8012840C(((var_a1 << 7) / temp_v0) + 0x80);
//             } else {
//                 var_v1_2 = 0x80 - func_8012840C(((var_a1 << 7) / temp_v0) + 0x80);
//             }
//         } else if (var_a1 >= 0) {
//             var_v1_2 = 0x40 - func_8012840C(((var_a2 << 7) / temp_v0) + 0x80);
//         } else {
//             var_v1_2 = func_8012840C(((var_a2 << 7) / temp_v0) + 0x80) + 0xC0;
//         }
//         D_801D9ED8.unkFFA8 = (s16) (var_v1_2 & 0xFF);
//     }
//     D_803D5570 = (s32) (((D_803F2C3C + 90.0f) * 256.0f) / 360.0f) & 0xFF;
//
//     if (D_801D9ED8.unkFFA8 != 0x100) {
//         if ((D_803D5574 == 0) || (D_803F28E0[D_803F2A98].cameraMode == 0x1A)) {
//             // nothing
//         }
//         if (D_803F28E0[D_803F2A98].cameraMode != 0x1A) {
//             D_801D9ED8.unkFFA8 = (D_801D9ED8.unkFFA8 + D_803D5570) & 0xFF;
//         }
//         if (D_803F28E0[D_803F2A98].cameraMode == 0x1A) {
//             D_801D9ED8.unkFFA8 = (s32) (D_803F28E0[D_803F2A98].unk20 + D_801D9ED8.unkFFA8) & 0xFF;
//         }
//     }
//
//     if (D_803F28E0[D_803F2A98].cameraMode != 0x1A) {
//         // not quite right, whitespace also seems to affect codegen
//         if (D_801D9ED8.unkFFA8 != 0x100) {
//             if (D_801D9ED8.unkFFA8 <= 0x40) { D_801D9ED8.unkFFA8 = (0x20 - ((D_80152C78[((D_801D9ED8.unkFFA8 * 2) + 0x40) & 0xFF] >> 7) >> 3)); }
//             else {
//                 if (D_801D9ED8.unkFFA8 <= 0x80) { D_801D9ED8.unkFFA8 = 0x60 - ((D_80152C78[(((D_801D9ED8.unkFFA8 - 0x40) * 2) + 0x40) & 0xFF] >> 7) >> 3); }
//                 else if (D_801D9ED8.unkFFA8 <= 0xC0) { D_801D9ED8.unkFFA8 = (0xA0 - ((D_80152C78[(((D_801D9ED8.unkFFA8 - 0x80) * 2) + 0x40) & 0xFF] >> 7) >> 3));
//                 } else {
//                     D_801D9ED8.unkFFA8 = (0xE0 - ((D_80152C78[(((D_801D9ED8.unkFFA8 - 0xC0) * 2) + 0x40) & 0xFF] >> 7) >> 3)) & 0xFF;
//                 }
//             }
//         }
//     }
//
//     D_803D5574 = temp_v0;
//     if (D_803F2C28 > 0) {
//         D_803F2C28--;
//         D_803D5574 = 0;
//         D_801D9ED8.unkFFDA = 0;
//         D_801D9ED8.unkFFA8 = 0x100;
//     }
//
//     if (D_801D9ED8.unkFFA8 != 0x100) {
//         if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 != 0) {
//             D_801D9ED8.unkFFA8 = (((((D_80152C78[(D_803D5540 * 4) & 0xFF] >> 7) * (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 >> 2)) >> 0xA) + D_801D9ED8.unkFFA8) & 0xFF);
//         }
//     }
//     if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk363 != 0) {
//         if (D_801D9ED8.unkFFA8 != 0x100) {
//             D_801D9ED8.unkFFA8 = (((D_80152C78[(D_803D5540 * 8) & 0xFF] >> 7) / 6) + D_801D9ED8.unkFFA8) & 0xFF;
//         }
//     }
//     if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A != 0) {
//         D_801D9ED8.unkFFA8 = 0x100;
//         D_801D9ED8.unkFFDA = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD0FC_6BE7AC.s")
// void func_802AD0FC_6BE7AC(void) {
//     static s16 D_803D5576 = 0;
//     s16 temp_a0;
//     s16 temp_a0_2;
//     s16 temp_a3;
//     s16 temp_t0;
//     s16 temp_t0_2;
//     s16 temp_v1_2;
//     s16 temp_v1_3;
//
//     s16 var_a1;
//     s16 var_a2;
//     s16 var_v1;
//
//     if (ABS(D_801D9ED8.unkFFD8) <= 10) {
//         var_a1 = 0;
//         D_803D5576 = MAX(D_803D5576 - 2, 0);
//     } else {
//         D_803D5576 = MIN(D_803D5576 + 1, 14);
//         if (D_801D9ED8.unkFFD8 > 0) {
//             var_a1 = D_801D9ED8.unkFFD8 - 10;
//         } else {
//             var_a1 = D_801D9ED8.unkFFD8 + 10;
//         }
//     }
//
//     if (ABS(D_801D9ED8.unkFFD9) <= 10) {
//         var_v1 = 0;
//     } else {
//         if (D_801D9ED8.unkFFD9 > 0) {
//             var_v1 = D_801D9ED8.unkFFD9 - 10;
//         } else {
//             var_v1 = D_801D9ED8.unkFFD9 + 10;
//         }
//     }
//
//     if (D_803D5524->unk9C == WALRUS) {
//         D_803D5548 += (var_a1 * D_803D5576) / 21;
//     } else {
//         D_803D5548 += (var_a1 * D_803D5576) / 14;
//     }
//     // D_803D5576 = var_a2;
//     temp_a3 =  D_803D5548 >> 4;
//     D_803D5548 %= 0x10;
//     if (D_801D9ED8.unkFFA8 == 0x100) {
//         D_801D9ED8.unkFFA8 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation;
//     }
//     D_801D9ED8.unkFFA8 += temp_a3;
//     // temp_t0 = D_801D9ED8.unkFFA8;
//     // temp_a2 = &D_801D9ED8 + (gCurrentAnimalIndex * 8);
//     if (D_801D9ED8.unkFFA8 < 0) {
//         D_801D9ED8.unkFFA8 += 256;
//     }
//     if (D_801D9ED8.unkFFA8 >= 0x100) {
//         D_801D9ED8.unkFFA8 -= 256;
//     }
//
//     D_801D9ED8.unkFFDA = 0;
//     if (var_v1 >= 0x12) {
//         D_801D9ED8.unkFFDA = 1;
//     }
//     if (var_v1 >= 0x1A) {
//         D_801D9ED8.unkFFDA = 2;
//     }
//     if (var_v1 >= 0x26) {
//         D_801D9ED8.unkFFDA = 3;
//     }
//     if (var_v1 >= 0x38) {
//         D_801D9ED8.unkFFDA = 4;
//     }
//     if (var_v1 < -0x11) {
//         D_801D9ED8.unkFFDA = -1;
//     }
//     if (var_v1 < -0x19) {
//         D_801D9ED8.unkFFDA = -2;
//     }
//     if (var_v1 < -0x25) {
//         D_801D9ED8.unkFFDA = -3;
//     }
//     if (var_v1 < -0x37) {
//         D_801D9ED8.unkFFDA = -4;
//     }
//
//     if (D_803F2C28 > 0) {
//         D_803F2C28--;
//         D_801D9ED8.unkFFDA = 0;
//         D_801D9ED8.unkFFA8 = 0x100;
//     }
//
//     if ((D_801D9ED8.unkFFA8 != 0x100) && (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 != 0)) {
//         D_803D5548 += (((D_80152C78[(((D_803D5540 * 4) & 0xFF))]) >> 7) * D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348) >> 0xD;
//     }
//     if ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk363 != 0) && (D_801D9ED8.unkFFA8 != 0x100)) {
//         D_801D9ED8.unkFFA8 = (s16) ((D_801D9ED8.unkFFA8 + (D_803D5540 * 2)) & 0xFF);
//     }
//     if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A != 0) {
//         D_801D9ED8.unkFFA8 = 0x100;
//         D_801D9ED8.unkFFDA = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AD49C_6BEB4C.s")
// not this...
// void func_802AD49C_6BEB4C(void) {
//     s16 temp_a0_2;
//     s32 temp_t9;
//     s16 phi_v0;
//     s16 phi_a0;
//     s16 phi_v1;
//     s16 phi_v0_2;
//     s16 phi_a1;
//     static s16 D_803D5578;
//
//     phi_v0 = D_801D9ED8.unkFFD8;
//     phi_v1 = D_801D9ED8.unkFFD9;
//     if (D_803F2D30.unk4 != 0) {
//         phi_v1 = 0;
//         phi_v0 = 0;
//     }
//
//     if (ABS(phi_v0) <= 10) {
//         D_803D5578 = MAX(D_803D5578 - 2, 0);
//         phi_v0 = 0;
//     } else {
//         D_803D5578 = MIN(D_803D5578 + 1, 14);
//         if (phi_v0 > 0) {
//             phi_v0 -= 10;
//         } else {
//             phi_v0 += 10;
//         }
//     }
//
//     if (phi_v1 < 0) {
//         s32 new_var, new_var2;
//         new_var = phi_v1;
//         new_var2 = (((!new_var) && (!new_var)) && (!new_var)) && (!new_var);
//         if (new_var2)
//         {
//         }
//         ;
//     } else {
//         // ?
//     }
//
//     D_803D5548 += (phi_v0 * D_803D5578) / 28;
//     temp_t9 = (s16)D_803D5548 >> 4;
//     D_803D5548 = D_803D5548 % 16;
//     D_801D9ED8.unkFFA8 += temp_t9;
//     // D_803D5578 = phi_a1;
//     if (D_801D9ED8.unkFFA8 < 0) {
//         D_801D9ED8.unkFFA8 += 256;
//     }
//     if (D_801D9ED8.unkFFA8 >= 256) {
//         D_801D9ED8.unkFFA8 -= 256;
//     }
//
//     if ((gControllerInput != NULL) && (gControllerInput->button & A_BUTTON)) {
//         D_801D9ED8.unkFFDA = 4;
//     } else {
//         D_801D9ED8.unkFFDA = 0;
//     }
// }

// huh?
u8 overlay2_6B5380_padding[0x14F3A];
void func_802AD63C_6BECEC(void) {
    static u8 overlay2_6B5380_padding[0x14F3A];
    static s16 D_803D557A; // .bss

    D_801D9ED8.unkFFDC = 0;
    if (D_801D9ED8.unkFFD8 < -17) {
        D_801D9ED8.unkFFDC = (D_801D9ED8.unkFFD8 << 6) / 55;
        D_801D9ED8.unkFFDC = (D_801D9ED8.unkFFDC * D_803D557A) / 14;
        if (D_801D9ED8.unkFFDC < -64) {
            D_801D9ED8.unkFFDC = -64;
        }
        D_803D557A = MIN(D_803D557A + 1, 14);
    } else if (D_801D9ED8.unkFFD8 > 17) {
        D_801D9ED8.unkFFDC = (D_801D9ED8.unkFFD8 << 6) / 55;
        D_801D9ED8.unkFFDC = (D_801D9ED8.unkFFDC * D_803D557A) / 14;
        if (D_801D9ED8.unkFFDC > 64) {
            D_801D9ED8.unkFFDC = 64;
        }
        D_803D557A = MIN(D_803D557A + 1, 14);
    } else {
        D_803D557A = MAX(D_803D557A - 2, 0);
    }

    D_801D9ED8.unkFFDE = 0;
    if (D_801D9ED8.unkFFD9 < -17) {
        D_801D9ED8.unkFFDE = (-17 - D_801D9ED8.unkFFD9) >> 1;
    } else if (D_801D9ED8.unkFFD9 > 17) {
        D_801D9ED8.unkFFDE = (17 - D_801D9ED8.unkFFD9) >> 1;
    }
    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->state == 0xDD) {
        D_803D5570 = D_803F28E0[D_803F2A98].unk20;
    }
    D_801D9ED8.unkFFA8 = ((D_801D9ED8.unkFFA8 + D_803D5570) & 0xFF);
}

void func_802AD87C_6BEF2C(void) {
    u16 sp1E;

    sp1E = D_803D5530->yRotation;
    if ((D_803D5524->unk9C == EVO_SHELLSUIT) && (D_803D552C->unk30C > 20)) {
        D_801D9ED8.unkFFDA = 0;
        D_801D9ED8.unkFFA8 = 0x100;
    }
    if (D_801D9ED8.unkFFB8 == 0) {
        D_803D5572 = D_803D5544;
    }
    switch (D_803D5530->unk162 & 0xF) {
    case 1:
        switch (D_803D5530->state) {
        case 1:
        case 2:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 0;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;

            if (D_801D9ED8.unkFFDA > 0) {
                func_802A43E4_6B5A94(D_801D9ED8.unkFFA8, 10); //, &D_803D556C, &D_801D9ED8);
            }
            if (D_801D9ED8.unkFFDA < 0) {
                func_802A44C4_6B5B74(D_801D9ED8.unkFFA8, 10);
            } else {
                if (D_801D9ED8.unkFFA8 != 0x100) {
                    D_803D5530->yRotation = D_801D9ED8.unkFFA8;
                }
            }
            break;
        case 3:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 1;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;

            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4390_6B5A40();
            } else if (D_801D9ED8.unkFFDA > 3) {
                func_802A459C_6B5C4C(D_801D9ED8.unkFFA8, 16);
            } else if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 4:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 2;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4390_6B5A40();
            } else
            if (D_801D9ED8.unkFFDA < 3) {
                func_802A43E4_6B5A94(sp1E, 10);
            }
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 6:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 1;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A4390_6B5A40();
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 3:
        if ((D_801D9ED8.unkFFA8 != sp1E) && (D_801D9ED8.unkFFA8 != 0x100)) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
    if ((D_801D9ED8.unkFFB2 != 0) && ((D_803D5544 - D_803D5572) < 8) && (D_803D5524->canJump & 1) && (D_803D552C->unk367 <= 0) && (D_803D555C != 0) && ((D_803D5544 - D_803D555A) < 4)) {
        D_803D555C = 0;
        switch (D_803D555D) {
        default:
        case 0:
            func_802A6390_6B7A40();
            break;
        case 1:
            func_802A6390_6B7A40();
            break;
        case 2:
            func_802A63C0_6B7A70();
            break;
        }
    }
}

void func_802ADDD0_6BF480(void) {
    u16 rotation = D_803D5530->yRotation;

    switch (D_803D5530->unk162 & 0xF) {
    case 6:
        switch (D_803D5530->state) {
        case 0x1:
        case 0xB5:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 0;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801E9EB2 > 0) {
                func_802A4EC8_6B6578(D_801E9E80, 10);
            } else if (D_801E9EB2 < 0) {
                func_802A4F68_6B6618(D_801E9E80, 10);
            } else if (D_801E9E80 != 256) {
                D_803D5530->yRotation = D_801E9E80;
            }
            break;
        case 0xB6:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 1;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801E9EB2 <= 0) {
                func_802A4E74_6B6524();
            } else {
                if (D_801E9E80 != 256) {
                    D_803D5530->yRotation = D_801E9E80;
                } else
                if (D_801E9EB2 >= 3) {
                    func_802A5008_6B66B8(D_801E9E80, 16);
                }
            }
            break;
        case 0xB7:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 2;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801E9EB2 <= 0) {
                func_802A4E74_6B6524();
            } else if (D_801E9EB2 < 3) {
                func_802A4EC8_6B6578(rotation, 10);
            }
            if (D_801E9E80 != 256) {
                D_803D5530->yRotation = D_801E9E80;
            }
            break;
        case 0xB9:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 0;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->xPos.h;
            D_803D5568 = D_803D5530->zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801E9EB2 >= 0) {
                func_802A4E74_6B6524();
            } else if (D_801E9E80 != 256) {
                D_803D5530->yRotation = D_801E9E80;
            }
            break;
        }
        break;
    case 7:
        if (D_801E9E80 != 256) {
            D_803D5530->yRotation = D_801E9E80;
        }
        break;
    }
    if ((D_801E9E8A != 0) && (D_803D5524->canJump & 1) &&
        (D_803D552C->unk367 <= 0) && (D_803D555C != 0) &&
        ((D_803D5544 - D_803D555A) < 4)) {
        D_803D555C = 0;
        switch (D_803D555D) {
        default:
        case 0:
            func_802A6390_6B7A40();
            break;
        case 1:
            func_802A6390_6B7A40();
            break;
        case 2:
            func_802A6390_6B7A40();
            break;
        }
    }
}

void func_802AE278_6BF928(void) {
    D_803D555A = D_803D5544;

    switch (D_803D5530->unk162 & 0xF) {
    case 1:
        switch (D_803D5530->state) {
        case 21:
            if (D_801D9ED8.unkFFDA > 0) {
                func_802A4D0C_6B63BC(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFDA < 0) {
                func_802A4D80_6B6430(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 22:
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4CB8_6B6368();
            } else if (D_801D9ED8.unkFFDA >= 3) {
                func_802A4DF4_6B64A4(D_801D9ED8.unkFFA8, 0x10);
            }
            break;
        case 23:
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4CB8_6B6368();
            } else if (D_801D9ED8.unkFFDA < 3) {
                func_802A4D0C_6B63BC(D_801D9ED8.unkFFA8, 0xA);
            }
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 24:
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A4CB8_6B6368();
            } else if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 3:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
}

void func_802AE488_6BFB38(void) {
    D_803D555A = D_803D5544;

    switch (D_803D5530->unk162 & 0xF) {
    case 6:
        switch (D_803D5530->state) {
        case 0xC9:
            if (D_801D9ED8.unkFFDA > 0) {
                func_802A55AC_6B6C5C(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFDA < 0) {
                func_802A5620_6B6CD0(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 0xCA:
            if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A5558_6B6C08();
            } else if (D_801D9ED8.unkFFDA >= 3) {
                func_802A5694_6B6D44(D_801D9ED8.unkFFA8, 0x10);
            }
            break;
        case 0xCB:
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A5558_6B6C08();
            } else if (D_801D9ED8.unkFFDA < 3) {
                func_802A55AC_6B6C5C(D_801D9ED8.unkFFA8, 0xA);
            }
            if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 0xCC:
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A5558_6B6C08();
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 7:
        if (D_801D9ED8.unkFFA8 != 256) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AE698_6BFD48.s")
// miles away
// void func_802AE698_6BFD48(void) {
//     s16 temp_a1;
//     s16 temp_v0;
//     s32 temp_v1;
//     s32 var_a3;
//
//     if (D_803D5530->state == 81) {
//         temp_v0 = D_803D557C;
//         temp_v0 += ((D_801D9ED8.unkFFDC * 4) / 3);
//         temp_v1 = temp_v0 / 32;
//         D_803D5530->yRotation += temp_v1;
//         D_803D5530->yRotation &= 0xFF;
//         D_803D552C->unk306 = D_801D9ED8.unkFFDC / 16;
//         D_803D557C = temp_v0 - (temp_v1 * 32);
//
//         if (((!var_a3) && (!var_a3)) && (!var_a3)) {};
//
//         temp_a1 = D_801D9ED8.unkFFDE - D_803D5530->unk28;
//         if (temp_a1 > 0) {
//             D_803D5530->unk28 += MIN(temp_a1, 10);
//         } else {
//             D_803D5530->unk28 += MAX(temp_a1, -10);
//         }
//
//         var_a3 = D_803D5530->unk28 << 0xF;
//         temp_v0 = func_802B2580_6C3C30();
//
//         if ((temp_v0 > 0xA80) && (var_a3 >= FTOFIX32(-1.0))) {
//             var_a3 = FTOFIX32(-1.0);
//         }
//         if ((temp_v0 > 0xA00)) {
//             if (var_a3 >= (0xA00 - temp_v0) << 9) {
//                 var_a3 = (0xA00 - temp_v0) << 9;
//             }
//         } else if ((temp_v0 > 0x980)) {
//             if (var_a3 >= (var_a3 >> 1)) {
//                 var_a3 = var_a3 >> 1;
//             }
//         }
//
//         if (D_803D5530->yVelocity.h > 20) {
//             D_803D5530->yVelocity.h -= 1;
//         }
//         if (D_803D5530->yVelocity.h < -20) {
//             D_803D5530->yVelocity.h += 1;
//         }
//         if (D_803D5530->yVelocity.h > 16) {
//             D_803D5530->yVelocity.h -= 1;
//         }
//         if (D_803D5530->yVelocity.h < -16) {
//             D_803D5530->yVelocity.h += 1;
//         }
//         if (D_803D5530->yVelocity.h > 12) {
//             D_803D5530->yVelocity.h -= 1;
//         }
//         if (D_803D5530->yVelocity.h < -12) {
//             D_803D5530->yVelocity.h += 1;
//         }
//
//         // could this be an ABS somehow?
//         if (var_a3 - D_803D5530->yVelocity.w > 0) {
//             D_803D5530->yVelocity.w += MIN(FTOFIX32(0.75), var_a3 - D_803D5530->yVelocity.w);
//         } else {
//             D_803D5530->yVelocity.w += MAX(-FTOFIX32(0.75), var_a3 - D_803D5530->yVelocity.w);
//         }
//
//         if (D_803D552C->unk365 == 0x2F) {
//             if ((temp_v0 < 0x9E0) || (D_803D5530->yVelocity.h < -8)) {
//                 D_803D552C->unk365 = 0U;
//             }
//             D_803D5530->yVelocity.h -= 2;
//         } else if ((temp_v0 > 0x9F6) && (D_803D5530->yVelocity.w > 0)) {
//             D_803D552C->unk32A = D_803D5544;
//             D_803D552C->unk365 = 47;
//         }
//     }
// }

void func_802AE9C4_6C0074(void) {
    D_803D552C->unk30E = 0;
    if ((D_803D5530->unk162 & 0xF) == 1) {
        if (D_803D552C->unk30C > 0) {
            D_803D552C->unk30C--;
        }
    }

    switch (D_803D5530->state) {
    case 1:
    case 41:
        D_803D555A = D_803D5544;
        D_803D5560 = D_803D5530->unk6C;

        if ((D_801D9ED8.unkFFA8 != 256) && (D_801D9ED8.unkFFB2 != 0) && (D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {
            func_802A5778_6B6E28(MAX(0, D_801D9ED8.unkFFDA), 0);
            D_803D552C->unk30A += 32;
            D_803D5530->unk162 = 3;
        } else if ((D_801D9ED8.unkFFA8 == 256) && (D_801D9ED8.unkFFB2 != 0) && (D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {
            func_802A5778_6B6E28(0, 0);
            D_803D5530->unk162 = 3;
        } else if (D_801D9ED8.unkFFA8 != 256) {
            D_803D552C->unk30E = MAX(0, D_801D9ED8.unkFFDA);
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        } else {
            D_803D552C->unk30E = 0;
        }
        break;
    case 42:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
}

void func_802AEBB0_6C0260(void) {
    s32 temp_v0_3;

    if (D_803D552C->unk30E >= 5) {
        D_803D552C->unk30E--;
    }
    if ((D_803D5530->yVelocity.w > FTOFIX32(6.0)) || (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) {
        D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    }

    switch (D_803D5530->state) {
    case 0x1:
    case 0x79:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        if (D_801D9ED8.unkFFB2 != 0) {
            func_802A5CF4_6B73A4();
        }
        break;
    case 0x7A:
    case 0x7B:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            D_803D5530->state = 0x7A;
            D_803D552C->unk368 = (D_801D9ED8.unkFFDA * 0x10) >> 2;
        } else {
            D_803D5530->state = 0x7BU;
            D_803D552C->unk368 = 0;
        }
        if (D_801D9ED8.unkFFB2 != 0) {
            temp_v0_3 = func_802B2580_6C3C30();
            if (temp_v0_3 < 0x100) {
                D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 3;
            } else if (temp_v0_3 < 0x180) {
                if (D_803D5530->yVelocity.w > FTOFIX32(-1.5)) {
                    D_803D5530->yVelocity.w -= D_803A05B0_7B1C60 >> 5;
                }
            } else {
                D_803D5530->yVelocity.w -= D_803A05B0_7B1C60 >> 3;
            }
            D_803D552C->unk30E = MIN(100, D_803D552C->unk30E + 4);
        } else {
            D_803D5530->yVelocity.w -= D_803A05B0_7B1C60 >> 3;
        }
        break;
    }
    D_803D552C->unk30C = (D_803D552C->unk30C + (D_803D552C->unk30E >> 2)) % 255;
}

#ifdef NON_MATCHING
void func_802AEE18_6C04C8(void) {
    switch (D_803D5530->state) {
    case 0x3E:
        D_803D5530->yRotation += (D_801D9ED8.unkFFDC >> 3);
        D_803D5530->yRotation &= 0xFF;
        D_803D5530->unk28 = D_801D9ED8.unkFFDE;
        D_803D5530->yVelocity.w = ((D_803D5530->yVelocity.w * 7) >> 3) + (D_803D5530->unk28 * 0x500);
        D_803D5530->yVelocity.w += (D_80152C78[(D_803D5540 * 4) & 0xFF] >> 7) << 6;

        if ((D_801D9ED8.unkFFDC != 0) || ((D_803D552C->unk30C != 0))) {
            D_803D552C->unk30E = MIN(16, D_803D552C->unk30E + 1);
        } else {
            D_803D552C->unk30E = MAX(0, D_803D552C->unk30E - 2);
        }

        if (D_801D9ED8.unkFFDC != 0) {
            if (D_803D552C->unk30C == 0) {
                if (D_801D9ED8.unkFFDC < 0) {
                    if ((D_803D552C->unk310 <= 0x300) && (D_803D552C->unk310 >= 0x2EA)) {
                        D_803D552C->unk310 = 0x300;
                    } else {
                        D_803D552C->unk310 = (D_803D552C->unk310 + 20) & 0x3FF;
                    }
                } else {
                    if ((D_803D552C->unk310 <= 0x100) && (D_803D552C->unk310 >= 0xEB)) {
                        D_803D552C->unk310 = 0x100;
                    } else {
                        D_803D552C->unk310 = (D_803D552C->unk310 + 20) & 0x3FF;
                    }
                }
            }
        }

        if (D_801D9ED8.unkFFB2 != 0) {
            if (D_801D9ED8.unkFFB8 == 0) {
                D_803D552C->unk30C += 64;
            } else {
                D_803D552C->unk30C = MAX(64, D_803D552C->unk30C);
            }
        }
        if (D_803D552C->unk30C < 50) {
            D_803D552C->unk30C = MAX(0, D_803D552C->unk30C - 6);
        } else {
            D_803D552C->unk30C = (D_803D552C->unk30C * 7) >> 3;
        }

        D_803D5530->xVelocity.w += (D_803D552C->unk30C * D_80152C78[D_803D552C->unk302 & 0xFF]) / 110;
        D_803D5530->zVelocity.w += (D_803D552C->unk30C * D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF]) / 110;
        if ((D_803D552C->unk365 == 0) && (D_801D9ED8.unkFFB6 != 0) && (D_801D9ED8.unkFFBC == 0)) {
            if ((D_803D5530->yPos.h - func_80298F78_6AA628(D_803D5530->xPos.h, D_803D5530->zPos.h)) >= -0x3F) {
                D_803D552C->unk369 = 0;
                D_803D5530->yPos.h += 23;
                D_803D5530->yVelocity.h += 23;
                D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 6;
                D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * 6;
                D_803D552C->unk308 = 0;
                D_803D5530->state = 0x3FU;
                D_803D5530->unk162 = 3;
                play_sound_effect_at_location(SFX_UNKNOWN_42, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            } else if (D_803D5524->unk9C != PIRANA) {
                func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
            }
        }
        break;
    case 0x1:
    case 0x3D:
    case 0x3F:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AEE18_6C04C8.s")
#endif

#ifdef NON_MATCHING
void func_802AF308_6C09B8(void) {
    u16 rotation = D_803D5530->yRotation;

    switch (D_803D5530->state) {
    default:
        break;
    case 0x1:
    case 0x8D:
        if (D_801D9ED8.unkFFDA > 0) {
            if ((D_803D5524->unk9C != VULTURE) && (D_803D5524->unk9C != SEAGULL2)) {
                func_802A5EF8_6B75A8(D_801D9ED8.unkFFA8, 0xA);
            }
        } else if (D_801D9ED8.unkFFDA < 0) {
            if ((D_803D5524->unk9C != VULTURE) && (D_803D5524->unk9C != SEAGULL2)) {
                func_802A5F9C_6B764C(D_801D9ED8.unkFFA8, 0xA);
            }
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 0x8E:
        if (D_801D9ED8.unkFFDA <= 0) {
            func_802A5EA4_6B7554();
        } else if (D_801D9ED8.unkFFDA >= 3) {
            func_802A6044_6B76F4(D_801D9ED8.unkFFA8, 0x10);
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 0x8F:
        if (D_801D9ED8.unkFFA8 == rotation) {
            if (D_801D9ED8.unkFFDA < 3) {
                func_802A5EF8_6B75A8(rotation, 0xA);
            }
        } else if (D_801D9ED8.unkFFA8 == 0x100) {
            func_802A5EA4_6B7554();
        } else {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    case 0x90:
        if (D_801D9ED8.unkFFDA >= 0) {
            func_802A5EA4_6B7554();
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    }
    if ((D_803D5524->unk9C == FROG) && (D_801D9ED8.unkFFB2 != 0)) {
        if ((D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {

            if ((D_803D5530->yPos.h - (MAX(MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 0].unk6, D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 0].unk6), MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 1].unk6, D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 1].unk6)) * 4)) > -40) {
                func_802A5778_6B6E28(MAX(0, D_801D9ED8.unkFFDA), 1);
                D_803D552C->unk30A += 32;
                D_803D5530->unk162 = 3;
                // FUUUUUU
                D_803D5530->yPos.h = MAX(D_803D5530->yPos.h, ((4 * MAX(MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 0].unk6, D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 0].unk6), MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 1].unk6, D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 1].unk6))) - D_803D5524->unkB8 + 12));
            }
        }
    }

    if (D_803D552C->unk30C > 0) {
        D_803D552C->unk30C--;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802AF308_6C09B8.s")
#endif

void func_802AF7E4_6C0E94(void) {
    if ((D_803D5540 & 1) == 0) {
        if ((D_803D5530->unk4A == 0) && (D_803D5530->unk4C.unk26 == 0)) {
            D_803D5530->health--;
            D_803D5530->health = D_803D5530->health;
            D_803D552C->unk36B++;
        }
    }
    switch (D_803D5530->state) {
    case 0x1:
    case 0xA1:
        if (D_803D552C->unk308 > 0) {
            D_803D552C->unk308--;
        } else {
            // huh?
            if ((D_801D9ED8.unkFFA8 != 0x100) && (D_801D9ED8.unkFFA8 != 0x100)) {
                func_802A5E1C_6B74CC(D_801D9ED8.unkFFA8);
            }
        }
        break;
    case 0xA2:
        if (D_801D9ED8.unkFFA8 == 0x100) {
            func_802A5E64_6B7514();
        } else if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
    D_803D552C->unk30E = (func_8012826C() & 0x1F) - 0xF;
    if ((D_801E9E8A != 0) && (D_801E9E90 == 0)) {
        if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) < 12) {
            D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 3;
            D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * 3;
        }
    }
}

void func_802AF9FC_6C10AC(void) {
    s32 pad1;
    s32 pad2;
    u16 sp4E;
    s16 sp4C;
    s16 pad;
    s16 tmp;
    s16 yVel;
    s16 xVel;
    s16 zVel;

    D_803D552C->unk30E++;

    if (D_801D9ED8.unkFFB8 == 0) {
        D_803D5572 = D_803D5544;
    }

    sp4E = D_803D5530->yRotation;   // angle?
    sp4C = D_803D5524->unkC2;       // lift?

    if ((D_803D5540 % 3) != 2) {
        D_803D5558 += -1;
    }

    D_803D5558 = MAX(D_803D5530->yPos.h - 64, D_803D5558);

    switch (D_803D5524->unk9C) {
    case SEAGULL:
    case VULTURE2:
        yVel = 384;
        break;
    case VULTURE:
    case SEAGULL2:
        yVel = 288;
        break;
    case PARROT:
        yVel = 640;
        break;
    default:
        yVel = 0;
        break;
    }

    func_80311A2C_7230DC(D_803D5530->xPos.h, D_803D5530->zPos.h, &xVel, &zVel, D_803D5530->unk160);

    if ((D_803D5530->unk68 != 0) || ((ABS(xVel) < 0x22) && (ABS(zVel) < 0x22))) {
        if (D_803D5530->unk162 == 1) {
            D_803D552C->unk30E = 0;
            D_803D5558 = MAX(D_803D5558, D_803D5530->yPos.h + yVel);
        } else {
            D_803D5558 = MAX(D_803D5558, func_802B25B4_6C3C64(1) + yVel);
        }
    }

    switch (D_803D5530->state) {
    case 101:
        if ((D_801D9ED8.unkFFB2 != 0) && (((D_803D5544 - D_803D5572) < 8) || (D_803D5530->unk162 != 1))) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }

            if ((D_801D9ED8.unkFFA8 != 0x100) && (D_803D5530->unk162 == 1) && (D_801D9ED8.unkFFDA > 0)) {
                if ((D_803D5530->xVelocity.w == 0) && (D_803D5530->zVelocity.w == 0)) {
                    D_803D5530->xVelocity.w += D_80152C78[D_801D9ED8.unkFFA8 & 0xFF] * 8;
                    D_803D5530->zVelocity.w += D_80152C78[(D_801D9ED8.unkFFA8 + 64) & 0xFF] * 8;
                    D_803D5530->yVelocity.w = FTOFIX32(10.0);
                    play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    D_803D5530->unk162 = 3;
                    D_803D552C->unk367 = 27;
                }
            }
        }

        if ((D_803D5530->unk162 == 3) && (D_803D552C->unk367 == 0) && (D_803D5530->yVelocity.h < -0xA)) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
            D_803D553A = 4;
            D_803D552C->unk30C = sp4C;
            D_803D5530->unk162 = 2;
            func_802B8AD8_6CA188();
            if ((D_803D5524->unk9C == VULTURE2) || (D_803D5524->unk9C == SEAGULL)) {
                D_803D5528->unk3C4 = 13;
            } else if ((D_803D5524->unk9C == VULTURE) || (D_803D5524->unk9C == SEAGULL2)) {
                D_803D5528->unk3C4 = 14;
            }
        }
        break;
    case 102:                                      /* switch 2 */
        if (D_803D552C->unk365 == 0) {
            func_802A60C4_6B7774();
        }
        break;
    case 103:
        if (D_801D9ED8.unkFFA8 != 256) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        if (D_801D9ED8.unkFFDA > 0) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
        }
        break;
    case 104:
        if (D_801D9ED8.unkFFDA == 0) {
            func_802A6100_6B77B0();
        } else if (D_801D9ED8.unkFFA8 != sp4E) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        } else if (D_801D9ED8.unkFFDA >= 3) {
            func_802A6198_6B7848(D_801D9ED8.unkFFA8);
        }
        break;
    case 105:
        if (D_801D9ED8.unkFFA8 != sp4E) {
            if (D_801D9ED8.unkFFA8 == 0x100) {
                func_802A6100_6B77B0();
            } else {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        } else if (D_801D9ED8.unkFFDA < 3) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
        }
        break;
    case 106:
        if ((D_803A05B0_7B1C60 * -16) < D_803D5530->yVelocity.w) {
            D_803D5530->yVelocity.w -= D_803A05B0_7B1C60 + (D_803A05B0_7B1C60 >> 1);
        }
        break;
    default:
        break; // required
    }

    if (((D_803D5530->yVelocity.w > FTOFIX32(6.0)) || (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) && (D_803D5530->state != 0x6A)) {
        D_803D5530->yVelocity.w = ((D_803D5530->yVelocity.w * 7) >> 3);
    }

    D_803D5530->yVelocity.w -= (D_803A05B0_7B1C60 >> 2);

    if ((D_803D5524->unk9C == VULTURE2) ||
        (D_803D5524->unk9C == VULTURE) ||
        (D_803D5524->unk9C == SEAGULL) ||
        (D_803D5524->unk9C == SEAGULL2)) {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
        }
    } else {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-5.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-7.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-8.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 3;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-10.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 1;
        }
    }
    if (D_803D552C->unk30C > 0) {
        if ((((sp4C * 0xA) >> 4) < D_803D552C->unk30C) && (sp4C >= D_803D552C->unk30C)) {
            D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 3;
            D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] * 3;

            if ((D_803D5524->unk9C == VULTURE2) ||
                (D_803D5524->unk9C == VULTURE) ||
                (D_803D5524->unk9C == SEAGULL) ||
                (D_803D5524->unk9C == SEAGULL2)) {
                if ((D_803D5530->yVelocity.w < FTOFIX32(-2.0)) && (D_803D5530->yPos.h < (D_803D5558 - 192))) {
                    D_803D5530->yVelocity.w += FTOFIX32(2.0);
                } else if ((D_803D5530->yVelocity.w < FTOFIX32(4.0)) && (D_803D5530->yPos.h < (D_803D5558 - 192))) {
                    D_803D5530->yVelocity.w += FTOFIX32(1.5625);
                } else if (D_803D5530->yVelocity.w < FTOFIX32(2.0)) {
                    // distance to ground?
                    if (D_803D5558 < D_803D5530->yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.75);
                    } else if ((D_803D5558 - 64) < D_803D5530->yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(1.0625);
                    } else if ((D_803D5558 - 128) < D_803D5530->yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(1.375);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(1.5625);
                    }
                }
            } else {
                if (D_803D5530->yVelocity.w < FTOFIX32(10.0)) {
                    if (D_803D5558 < D_803D5530->yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.5);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(1.75);
                    }
                }
            }
        }
        D_803D552C->unk30C--;
        if ((D_803D552C->unk30C == (sp4C >> 1)) && ((D_803D5524->unk9C == VULTURE) || (D_803D5524->unk9C == SEAGULL2))) {
            D_803D553A = 4;
        }
    } else {
        tmp = 0;
        if (D_803D5524->unk9C == PARROT) {
            if ((D_801D9ED8.unkFFB2 != 0) && (D_803D5530->state != 0x6A) && ((D_803D5544 - D_803D5572) < 8)) {
                tmp = 1;
            }
        } else if (D_801D9ED8.unkFFB2 != 0) {
            tmp = 1;
        }
        if (tmp) {
            D_803D553A = 4;
            D_803D5530->yVelocity.w += (4 << (20 / sp4C));
            D_803D552C->unk30C = sp4C;
            D_803D5530->unk162 = 2;
            func_802B8AD8_6CA188();
            if ((D_803D5524->unk9C == VULTURE2) ||
                (D_803D5524->unk9C == SEAGULL)) {
                D_803D5528->unk3C4 = 13;
            } else if ((D_803D5524->unk9C == VULTURE) ||
                       (D_803D5524->unk9C == SEAGULL2)) {
                D_803D5528->unk3C4 = 14;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B066C_6C1D1C.s")
// miles away
// void func_802B066C_6C1D1C(void) {
//     s16 sp36;
//     s16 sp34;
//     s16 sp32;
//     s32 sp24;
//     s16 temp_t2;
//     s16 temp_t7;
//     s16 temp_v0;
//     s16 var_a0;
//     s16 var_v0;
//     s16 var_v1;
//     s32 temp_a0_2;
//     f32 temp_f18;
//     s32 var_v1_2;
//     s8 temp_a0;
//
//     sp36 = D_803D552C->unk308;
//
//     if (D_801D9ED8.unkFFDE < 0) {
//         var_a0 = -(-D_801D9ED8.unkFFDE >> 3);
//     } else {
//         var_a0 = (D_801D9ED8.unkFFDE >> 3);
//     }
//
//     if (D_803E00C0[sp36].unk35 == 0) {
//         D_803D552C->unk30A += var_a0;
//     }
//     if (D_803D552C->unk30A < 0x38) {
//         D_803D552C->unk30A = 0x3A;
//     }
//
//     temp_t7 = (D_803E00C0[sp36].unk14 - 1) * 0x10;
//     if (temp_t7 < D_803D552C->unk30A) {
//         D_803D552C->unk30A = temp_t7;
//     }
//
//     sp34 = (D_803D552C->unk30A >> 4);
//     temp_t2 = D_803D552C->unk30A & 0xF;
//     D_803E00C0[sp36].unk30 = sp34;
//
//     if (D_801D9ED8.unkFFDC > 0) {
//         D_803D5530->yRotation = (s32) (D_803F28E0[D_803F2A98].unk20 + 0x40) & 0xFF;
//     }
//     if (D_801D9ED8.unkFFDC < 0) {
//         D_803D5530->yRotation = (s32) (D_803F28E0[D_803F2A98].unk20 + 0xC0) & 0xFF;
//     }
//
//     temp_f18 = D_803F28E0[D_803F2A98].unk20;
//     if (D_803E00C0[sp36].unk35 == 0) {
//         s32 tmp1 = (D_80152C78[((s32)temp_f18 + 0x40) & 0xFF] >> 7);
//         s32 tmp2 = (D_80152C78[(s32)temp_f18 & 0xFF] >> 7);
//         func_802DE770_6EFE20(
//             sp36,
//             sp34,
//             tmp1 * D_801D9ED8.unkFFDC,
//             tmp2 * -D_801D9ED8.unkFFDC,
//             0xFFFF0000);
//     } else {
//         D_803E00C0[sp36].unk35--;
//     }
//     if (temp_t2 == 0) {
//         D_803D5530->xPos.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk0;
//         D_803D5530->zPos.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk4;
//         D_803D5530->yPos.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk8;
//     } else {
//         D_803D5530->xPos.w = ((16 - temp_t2) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk0 >> 4)) + ((D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 1].unk0 >> 4) * temp_t2);
//         D_803D5530->zPos.w = ((16 - temp_t2) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk4 >> 4)) + ((D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 1].unk4 >> 4) * temp_t2);
//         D_803D5530->yPos.w = ((16 - temp_t2) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk8 >> 4)) + ((D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 1].unk8 >> 4) * temp_t2);
//     }
//
//     func_803136B0_724D60(D_803D5530);
//     D_803D5530->xVelocity.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unkC;
//     D_803D5530->zVelocity.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk10;
//     D_803D5530->yVelocity.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk14;
// }

void func_802B0B00_6C21B0(s16 arg0, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 2: // STATE_STANDING ?
        if ((s32) arg1 > 0) {
            if (arg1 < 0xE) {
                func_802A43E4_6B5A94(arg0, (s8) arg1);
            } else if (arg1 >= 0xE) {
                func_802A459C_6B5C4C(arg0, (s8) arg1);
            }
        }
        break;
    case 3: // STATE_WALKING
        if (arg1 < 0) {
            func_802A4390_6B5A40();
        } else if (arg1 == 0) {
            func_802A4390_6B5A40();
        } else if (arg1 >= 0xE) {
            func_802A459C_6B5C4C(arg0, (s8) arg1);
        } else {
            D_803D5530->yRotation = (s16) arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = (s8) arg1;
                D_803D552C->unk31A = (s16) ((arg1 * D_803D5524->unkA4) / 0x10);
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    case 4: // STATE_RUNNING
        if (arg1 < 0) {
            D_803D552C->unk368 = 0;
            D_803D552C->unk31A = 0;
            D_803D552C->unk2FA = 1000;
            func_802A4390_6B5A40();
        } else if (arg1 == 0) {
            func_802A4390_6B5A40();
        } else if (arg1 < 0xE) {
            func_802A43E4_6B5A94(arg0, (s8) arg1);
        } else {
            D_803D5530->yRotation = (s16) arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = (s8) arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 0x10;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    case 5:
        break;
    }
    if (arg1 < 0) {
        D_803D5530->yRotation = (s16) arg0;
    }
}

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

void func_802B0F4C_6C25FC(s16 arg0, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 21:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A4D0C_6B63BC(arg0, arg1);
            } else {
                func_802A4DF4_6B64A4(arg0, arg1);
            }
        }
        break;
    case 22:
        if (arg1 <= 0) {
            func_802A4CB8_6B6368();
        } else if (arg1 > 13) {
            func_802A4DF4_6B64A4(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 23:
        if (arg1 <= 0) {
            func_802A4CB8_6B6368();
        } else if (arg1 < 14) {
            func_802A4D0C_6B63BC(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            D_803D552C->unk368 = arg1;
        }
        break;
    }

    if (arg1 == -1) {
        D_803D5530->yRotation = arg0;
    }
}

void func_802B10B0_6C2760(s16 rotation, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 201:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A55AC_6B6C5C(rotation, arg1);
            } else {
                func_802A5694_6B6D44(rotation, arg1);
            }
        }
        break;
    case 202:
        if (arg1 <= 0) {
            func_802A5558_6B6C08();
        } else if (arg1 > 13) {
            func_802A5694_6B6D44(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 203:
        if (arg1 <= 0) {
            func_802A5558_6B6C08();
        } else if (arg1 < 13) {
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

void func_802B1210_6C28C0(s16 rotation, s16 arg1) {
    if ((D_803D5530->unk162 & 0xF) == 1) {
        if (D_803D552C->unk30C > 0) {
            D_803D552C->unk30C -= 1;
        }
    } else {
        D_803D552C->unk30C = MAX(D_803D552C->unk30C, 25);
    }

    switch (D_803D5530->state) {
    case 1:
    case 0x29:
        D_803D5530->yRotation = rotation;
        D_803D552C->unk302 = rotation;

        if ((D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {
            if (arg1 > 0) {
                func_802A5778_6B6E28(MIN(arg1 >> 2, 3), 0);
                D_803D5530->unk162 = 3;
            }
        }
        break;
    case 0x2A:
        D_803D5530->yRotation = rotation;
        D_803D552C->unk302 = rotation;
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1374_6C2A24(s16 rotation, s16 arg1, s16 yOffset) {
    s16 pad[3];
    s16 pad2;
    s16 var_a3;

    D_803D552C->unk30C = (D_803D552C->unk30C + 1) & 0xFF;

    if ((D_803D5530->state != 1) && (D_803D5530->state != 0x3D) && (D_803D5530->state == 0x3E)) {
        if (arg1 <= 0) {
            D_803D552C->unk30C = 0;
            D_803D552C->unk30E = MAX(D_803D552C->unk30E - 1, 0);
        } else if (arg1 < 0xE) {
            D_803D552C->unk30C = arg1 * 6;
            D_803D552C->unk30E = MIN(D_803D552C->unk30E + 1, 10);
        } else {
            D_803D552C->unk30C = arg1 * 6;
            D_803D552C->unk30E = MIN(D_803D552C->unk30E + 1, 16);
        }

        D_803D5530->yRotation = rotation;
        if (arg1 > 0) {
            D_803D5530->xVelocity.w += (((arg1 * 0x10) * (D_80152C78[D_803D5530->yRotation & 0xFF] >> 7)));
            D_803D5530->zVelocity.w += (((arg1 * 0x10) * (D_80152C78[(D_803D5530->yRotation + 0x40) & 0xFF] >> 7)));
        }

        if (yOffset < 0) {
            if (yOffset == -1) {
                var_a3 = 60;
            } else {
                var_a3 = -yOffset;
            }
            var_a3 = var_a3 + ((func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 0x10) - D_803D5530->yPos.h);
        } else {
            var_a3 = yOffset - D_803D5530->yPos.h;
        }

        if (var_a3 > 80) {
            var_a3 = 80;
        }
        if (var_a3 < -80) {
            var_a3 = -80;
        }
        D_803D5530->unk28 = var_a3;
        D_803D5530->yVelocity.w = ((D_803D5530->yVelocity.w * 7) >> 3) + (D_803D5530->unk28 << 9);
        D_803D5530->yVelocity.w += ((D_80152C78[(s16)(D_803D552C->unk31C + (D_803D5540 * 4)) & 0xFF] >> 7) << 6);
    }
    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1654_6C2D04(s16 rotation, s16 arg1, s16 yOffset) {
    s16 pad[2];
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;
    s32 temp_v0_2;


    if (D_803D5530->state == 0x51) {
        var_v0 = (rotation - D_803D5530->yRotation) & 0xFF;
        if (var_v0 > 128) {
            var_v0 -= 256;
        }
        if (var_v0 > 4) {
            var_v0 = 4;
        }
        if (var_v0 < -4) {
            var_v0 = -4;
        }
        D_803D5530->yRotation = (D_803D5530->yRotation + var_v0) & 0xFF;
        D_803D552C->unk306 = var_v0;
        if (yOffset < 0) {
            if (yOffset == -1) {
                var_a3 = 60;
            } else {
                var_a3 = -yOffset;
            }
            var_a3 = var_a3 + ((func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 0x10) - D_803D5530->yPos.h);
        } else {
            var_a3 = yOffset - D_803D5530->yPos.h;
        }
        var_a3 = var_a3 >> 2;
        if ((func_802B2580_6C3C30() >= 2369) && (var_a3 > 0)) {
            var_a3 = 0;
        }
        if (var_a3 > 40) {
            var_a3 = 40;
        }
        if (var_a3 < -40) {
            var_a3 = -40;
        }

        temp_v0 = var_a3 - D_803D5530->unk28;
        if (temp_v0 > 0) {
            D_803D5530->unk28 += MIN(temp_v0, 12);
        } else {
            D_803D5530->unk28 += MAX(temp_v0, -12);
        }

        if (D_803D5530->yVelocity.h > 20) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -20) {
            D_803D5530->yVelocity.h += 1;
        }
        if (D_803D5530->yVelocity.h > 16) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -16) {
            D_803D5530->yVelocity.h += 1;
        }
        if (D_803D5530->yVelocity.h > 12) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -12) {
            D_803D5530->yVelocity.h += 1;
        }

        temp_v0_2 = (D_803D5530->unk28 << 0xE) - D_803D5530->yVelocity.w;
        if (temp_v0_2 > 0) {
            D_803D5530->yVelocity.w += MIN(0x4000, temp_v0_2);
        } else {
            D_803D5530->yVelocity.w += MAX(-0x4000, temp_v0_2);
        }
    }
}

void func_802B1918_6C2FC8(s16 arg0, s16 arg1, s16 arg2) {
    s16 pad[2];
    s16 var_a3;

    if ((D_803D5530->yVelocity.w > FTOFIX32(6.0)) || (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) {
        D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    }
    if (D_803D552C->unk30E > 8) {
        D_803D552C->unk30E--;
    }
    if (arg2 < 0) {
        if (arg2 == -1) {
            var_a3 = 60;
        } else {
            var_a3 = -arg2;
        }
        var_a3 = var_a3 + ((func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 0x10) - D_803D5530->yPos.h);
    } else {
        var_a3 = arg2 - D_803D5530->yPos.h;
    }

    switch (D_803D5530->state) {
    case 0x1:
    case 0x79:
        if ((arg1 > 0) || (var_a3 > 0)) {
            func_802A5CF4_6B73A4();
            D_803D5530->unk162 = 2;
        }
        break;
    case 0x7A:
    case 0x7B:
        if (arg1 == 0) {
            D_803D5530->state = 123;
            D_803D552C->unk368 = 0;
        } else if (arg1 == -1) {
            D_803D5530->state = 123;
            D_803D5530->yRotation = arg0;
            D_803D552C->unk368 = 0;
        } else {
            D_803D5530->yRotation = arg0;
            D_803D5530->state = 122;
            D_803D552C->unk368 = arg1;
        }
        if ((var_a3 > 0) || (D_803D5530->yVelocity.w < (D_803A05B0_7B1C60 * -2))) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 3;
            D_803D552C->unk30E = 50;
        } else {
            D_803D5530->yVelocity.w -= (D_803A05B0_7B1C60 >> 3);
        }
        break;
    }
    D_803D552C->unk30C = (D_803D552C->unk30C + (D_803D552C->unk30E >> 1)) % 360;
    if (arg1 < 0) {
        D_803D5530->yRotation = arg0;
    }
}

void func_802B1B98_6C3248(s16 rotation, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 141:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A5EF8_6B75A8(rotation, arg1);
            } else if (arg1 > 13) {
                func_802A6044_6B76F4(rotation, arg1);
            }
        }
        break;

    case 142:
        if (arg1 <= 0) {
            func_802A5EA4_6B7554();
        } else if (arg1 > 13) {
            func_802A6044_6B76F4(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 143:
        if (arg1 <= 0) {
            func_802A5EA4_6B7554();
        } else if (arg1 < 14) {
            func_802A5EF8_6B75A8(rotation, arg1);
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

void func_802B1D00_6C33B0(s16 rotation, s16 arg1) {
    if ((D_803D5540 & 3) == 0) {
        if ((D_803D5530->unk4A == 0) && (D_803D5530->unk4C.unk26 == 0)) {
            D_803D5530->health--;
            D_803D5530->health = D_803D5530->health;
            D_803D552C->unk36B++;
        }
    }

    switch (D_803D5530->state) {
    case 1:
    case 161:
        if ((arg1 == 1) || (arg1 == 2)) {
            func_802A5E1C_6B74CC(rotation);
        }
        break;
    case 162:
        if ((arg1 == 0) || (arg1 == -1)) {
            func_802A5E64_6B7514();
        }
        D_803D5530->yRotation = rotation;
        break;
    }

    if (arg1 == -1) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1E28_6C34D8(s16 rotation, s16 arg1, s16 yOffset) {
    s16 pad[3];
    s16 airHeight;
    s16 phi_v1_6;
    s16 temp_v0_3;
    s16 sp18;

    if ((D_803D5530->yVelocity.w > FTOFIX32(6.0)) ||
        (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) {
        D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    }
    sp18 = D_803D5524->unkC2;

    switch (D_803D5530->state) {
    case 101:
        if (arg1 > 0) {
            func_802A613C_6B77EC(rotation);
            D_803D5530->yVelocity.h += 2;
            D_803D5530->unk162 = 2;
        }
        D_803D5530->yRotation = rotation;
        break;
    case 103:
        if (arg1 > 0) {
            func_802A613C_6B77EC(rotation);
        }
        D_803D5530->yRotation = rotation;
        break;
    case 104:
        if ((arg1 == 0) || (arg1 == -1)) {
            func_802A60C4_6B7774();
        } else if (arg1 >= 10) {
            func_802A6198_6B7848(rotation);
        }
        D_803D5530->yRotation = rotation;
        break;
    case 105:
        if (arg1 < 10) {
            func_802A613C_6B77EC(rotation);
        }
        D_803D5530->yRotation = rotation;
        break;
    case 106:
        if ((D_803A05B0_7B1C60 * -32) < D_803D5530->yVelocity.w) {
            D_803D5530->yVelocity.w -= D_803A05B0_7B1C60 + (D_803A05B0_7B1C60 >> 1);
        }
        break;
    default:
        break; // required
    }

    D_803D5530->yVelocity.w -= D_803A05B0_7B1C60 >> 3;

    if ((D_803D5524->unk9C == VULTURE2) ||
        (D_803D5524->unk9C == VULTURE) ||
        (D_803D5524->unk9C == SEAGULL) ||
        (D_803D5524->unk9C == SEAGULL2)) {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
        }
    } else {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-5.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-7.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-8.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 3;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 2;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-10.0)) {
            D_803D5530->yVelocity.w += D_803A05B0_7B1C60 >> 1;
        }
    }
    if (D_803D552C->unk30C > 0) {
        if ((((sp18 * 0xA) >> 4) < D_803D552C->unk30C) && (sp18 >= D_803D552C->unk30C)) {
            D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 3;
            D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * 3;
            if ((D_803D5524->unk9C == VULTURE2) ||
                (D_803D5524->unk9C == VULTURE) ||
                (D_803D5524->unk9C == SEAGULL) ||
                (D_803D5524->unk9C == SEAGULL2)) {
                airHeight = func_802B2580_6C3C30();
                if ((D_803D5524->unk9C == VULTURE) ||
                    (D_803D5524->unk9C == SEAGULL2)) {
                    airHeight += airHeight >> 1;
                }
                if (D_803D5530->yVelocity.w < FTOFIX32(10.0)) {
                    if (airHeight > 448) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.5625);
                    } else if (airHeight > 320) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.6875);
                    } else if (airHeight > 192) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.75);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(0.875);
                    }
                }
            } else {
                airHeight = func_802B2580_6C3C30();
                if (D_803D5530->yVelocity.w < FTOFIX32(10.0)) {
                    if (airHeight > 640) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.25);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(0.875);
                    }
                }
            }
        }
        D_803D552C->unk30C += -1;
    } else {
        if (yOffset < 0) {
            phi_v1_6 = ((func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 0x10) - yOffset) - D_803D5530->yPos.h;
        } else {
            phi_v1_6 = yOffset - D_803D5530->yPos.h;
        }
        if (D_803D5530->state != 0x6A) {
            temp_v0_3 = 0;
            if (phi_v1_6 >= -256) {
                if (phi_v1_6 < -128) {
                    if (D_803D5530->yVelocity.h < -10) {
                        temp_v0_3 = 1;
                    }
                } else if (phi_v1_6 < 0) {
                    if (D_803D5530->yVelocity.h < -5) {
                        temp_v0_3 = 1;
                    }
                } else if (phi_v1_6 < 64) {
                    if (D_803D5530->yVelocity.h < 2) {
                        temp_v0_3 = 1;
                    }
                } else if (D_803D5530->yVelocity.h < 10) {
                    temp_v0_3 = 1;
                }
            }
            if (temp_v0_3 != 0) {
                D_803D553A = 4;
                D_803D5530->yVelocity.w += 2 << (20 / sp18);
                D_803D552C->unk30C = sp18;
                D_803D5530->unk162 = 2;
                func_802B8AD8_6CA188();
                if ((D_803D5524->unk9C == VULTURE2) ||
                    (D_803D5524->unk9C == VULTURE) ||
                    (D_803D5524->unk9C == SEAGULL) ||
                    (D_803D5524->unk9C == SEAGULL2)) {
                    D_803D5528->unk3C4 = 13;
                }
            }
        }
    }
    if (arg1 == -1) {
        D_803D5530->yRotation = rotation;
    }
}

// get_distance_from_ground
s16 func_802B2580_6C3C30(void) {
    return D_803D5530->yPos.h - func_802B25B4_6C3C64(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6B5380/func_802B25B4_6C3C64.s")
// still need to understand collision
// s16 func_802B25B4_6C3C64(u8 getWaterHeight) {
//     s16 temp_t0;
//     s16 temp_t1;
//
//     s16 temp_a2;
//     s16 temp_v1;
//
//     s32 phi_t2;
//     s32 phi_t4;
//     s32 phi_t3;
//     s32 phi_t5;
//
//     s16 phi_a1;
//
//     temp_v1 = D_803D5530->xPos.h >> 6;
//     temp_a2 = D_803D5530->zPos.h >> 6;
//     if (D_803D5530->unk160 == 2) {
//         phi_a1 = MIN(MIN(D_803C0740[temp_v1 + 0][temp_a2 + 0].unk1,
//                          D_803C0740[temp_v1 + 1][temp_a2 + 0].unk1),
//                      MIN(D_803C0740[temp_v1 + 0][temp_a2 + 1].unk1,
//                          D_803C0740[temp_v1 + 1][temp_a2 + 1].unk1));
//     } else {
//         temp_t0 = D_803D5530->xPos.h & 0x3F;
//         temp_t1 = D_803D5530->zPos.h & 0x3F;
//
//         if (1) {}; // regalloc helper.. ish
//
//         phi_t2 = D_803C0740[temp_v1 + 0][temp_a2 + 0].unk0;
//         phi_t4 = D_803C0740[temp_v1 + 1][temp_a2 + 0].unk0;
//         phi_t3 = D_803C0740[temp_v1 + 0][temp_a2 + 1].unk0;
//         phi_t5 = D_803C0740[temp_v1 + 1][temp_a2 + 1].unk0;
//
//         if (D_803C0740[temp_v1 + 0][temp_a2 + 0].unk4 & 1) {
//             if (temp_t0 < temp_t1) {
//                 phi_t4 = (s16) D_803C0740[temp_v1 + 0][temp_a2 + 0].unk0;
//             } else {
//                 phi_t3 = (s16) D_803C0740[temp_v1 + 0][temp_a2 + 0].unk0;
//             }
//         } else if ((temp_t0 + temp_t1) < 64) {
//             phi_t5 = (s16) D_803C0740[temp_v1 + 0][temp_a2 + 0].unk0;
//         } else {
//             phi_t2 = (s16) D_803C0740[temp_v1 + 1][temp_a2 + 1].unk0;
//         }
//
//         phi_a1 = MIN(MIN(phi_t2, phi_t4),
//                      MIN(phi_t3, phi_t5));
//     }
//
//     if (getWaterHeight) {
//         return MAX(phi_a1 * 8, D_803C0740[temp_v1 + 0][temp_a2 + 0].unk6 * 4);
//     } // else return lowest point in terrain?
//     return (phi_a1 * 8);
// }

void func_802B2834_6C3EE4(void) {
    s16 phi_a2;
    s16 temp_v0_3;
    s16 a;
    s16 b;

    a = D_803D5530->xPos.h >> 6;
    b = D_803D5530->zPos.h >> 6;

    if ((D_803C0740[a + 0][b + 0].unk6) ||
        (D_803C0740[a + 1][b + 0].unk6) ||
        (D_803C0740[a + 0][b + 1].unk6) ||
        (D_803C0740[a + 1][b + 1].unk6)) {

        if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
            phi_a2 = D_803D5524->unkBA;
        } else {
            phi_a2 = D_803D5524->unkB8;
        }
        temp_v0_3 = func_80298F78_6AA628(D_803D5530->xPos.h, D_803D5530->zPos.h);
        if (temp_v0_3 != 0) {
            if ((D_803D5530->yPos.h + phi_a2) < temp_v0_3) {
                if (D_803D5530->state != 0xDD) {
                    func_802B315C_6C480C();
                }
                func_802B8B1C_6CA1CC();
                func_802D760C_6E8CBC(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk30, D_803D5530->yVelocity.h);
            }
        }
    }
}

void func_802B2964_6C4014(void) {
    s16 phi_a3;
    s16 temp_v0_2;

    temp_v0_2 = func_80298F78_6AA628(D_803D5530->xPos.h, D_803D5530->zPos.h);
    if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
        phi_a3 = D_803D5524->unkBA;
    } else {
        phi_a3 = D_803D5524->unkB8;
    }
    if ((temp_v0_2 == 0) || (temp_v0_2 < ((func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 16) + phi_a3))) {
        func_802B2EA8_6C4558();
        return;
    }
    if ((D_803D5538 != 0) &&
        (((D_803D5524->class == CLASS_BIRD) && (D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0)) ||
         ((D_803D5524->class == CLASS_HELI) && (D_801D9ED8.unkFFB2 != 0)))) {

        if (((D_803D5530->yPos.h + phi_a3) - temp_v0_2) > -7) {
            D_803D5530->yPos.h = MAX(D_803D5530->yPos.h, temp_v0_2 - phi_a3);
            D_803D5530->yVelocity.w = FTOFIX32(4.0);
            func_802B2EA8_6C4558();
        }
    }
    if ((temp_v0_2 + 16) < D_803D5530->yPos.h) {
        func_802B2FF4_6C46A4();
    }
}

s32 func_802B2AF0_6C41A0(s32 arg0, s32 arg1) {
    if ((arg0 <= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos.h - D_803D5524->unkBE, D_803D5530->zPos.h))) {
        return 1;
    }
    if ((arg0 >= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos.h + D_803D5524->unkBE, D_803D5530->zPos.h))) {
        return 1;
    }
    if ((arg1 <= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos.h, D_803D5530->zPos.h - D_803D5524->unkBE))) {
        return 1;
    }
    if ((arg1 >= 0) && (func_802B2C20_6C42D0(D_803D5530->xPos.h, D_803D5530->zPos.h + D_803D5524->unkBE))) {
        return 1;
    }
    // implicit return? UB?
}

s32 func_802B2C20_6C42D0(s16 arg0, s16 arg1) {
    s32 phi_v0_2;
    s16 phi_v1;
    s16 temp_a3;
    s16 xVel;
    s16 zVel;
    s32 pad;

    phi_v0_2 = MAX(MAX(D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6,
                       D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6),
                   MAX(D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6,
                       D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6)) & 0xFFFFFFFF;

    temp_a3 = D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63] + (4 * phi_v0_2);

    if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
        phi_v1 = D_803D5524->unkBA;
    } else {
        // regalloc helper
        if ((phi_v1 && phi_v1) && phi_v1) {}
        phi_v1 = D_803D5524->unkB8;
    }

    phi_v0_2 = func_80310EE4_722594(arg0, arg1, D_803D5530->unk160);
    if (phi_v0_2 == 0x40000000) {
        if (temp_a3 < ((func_8031124C_7228FC(arg0, arg1) >> 0x10) + phi_v1)) {
            func_80311BF8_7232A8(arg0, arg1, &xVel, &zVel);
            if (ABS(xVel) > 23) {
                return 1;
            }
            if (ABS(zVel) > 23) {
                return 1;
            }
        }
        return 0;
    }

    if (temp_a3 < ((phi_v0_2 >> 0x10) + phi_v1)) {
        func_80311A2C_7230DC(arg0, arg1, &xVel, &zVel, D_803D5530->unk160);
        if (ABS(xVel) > 23) {
            return 1;
        }
        if (ABS(zVel) > 23) {
            return 1;
        }
    }
    return 0;
}

void func_802B2EA8_6C4558(void) {
    switch (D_803D5524->class) {
    case CLASS_WALK:
        func_802A4390_6B5A40();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_WHEELS:
        func_802A4CB8_6B6368();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_POGO:
        func_802A5C80_6B7330();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_FLYING:
        func_802A5708_6B6DB8(D_803D5530->yRotation, 0, 1);
        D_803D5530->unk162 = 2;
        break;
    case CLASS_BIRD:
        func_802A60C4_6B7774();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_HELI:
        func_802A5D64_6B7414();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_SWIM:
        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        func_802A5E64_6B7514();
        D_803D5530->unk162 = 1;
        break;
    }
}

void func_802B2FF4_6C46A4(void) {
    switch (D_803D5524->class) {
    case CLASS_WALK:
        D_803D5530->state = 5;
        D_803D5530->unk162 = 3;
        break;
    case CLASS_WHEELS:
        func_802A4CB8_6B6368();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_POGO:
        func_802A5C80_6B7330();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_FLYING:
        func_802A5708_6B6DB8(D_803D5530->yRotation, 0, 1);
        D_803D5530->unk162 = 2;
        break;
    case CLASS_BIRD:
        func_802A60C4_6B7774();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_HELI:
        func_802A5CF4_6B73A4();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_SWIM:
        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        func_802A5E1C_6B74CC(0);
        D_803D5530->unk162 = 3;
        break;
    }
}

void func_802B315C_6C480C(void) {
    switch (D_803D5524->waterClass & (WATER_DAMAGE - 1)) {
    case WATER_FLOAT:
        func_802A5EA4_6B7554();
        D_803D5530->unk162 = 5;
        break;
    case WATER_SWIM:
        func_802A5DD0_6B7480();
        D_803D5530->unk162 = 4;
        break;
    case WATER_SINK_WALK:
        func_802A4E74_6B6524();
        D_803D5530->unk162 = 6;
        break;
    case WATER_SINK_WHEELS:
        func_802A5558_6B6C08();
        D_803D5530->unk162 = 6;
        break;
    case WATER_TBD:
        D_803D5530->yVelocity.w += FTOFIX32(5.0);
        break;
    }
}

void func_802B3230_6C48E0(void) {
    s16 tmp;

    if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
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
            if (D_803D5524->unkBA < (func_80298F78_6AA628(D_803D5530->xPos.h, D_803D5530->zPos.h) - (func_8031124C_7228FC(D_803D5530->xPos.h, D_803D5530->zPos.h) >> 0x10))) {
                if ((D_803D5530->unk4C.unk26 == 0) && ((D_803D5540 & 3) == 0)) {
                    tmp = 0;
                    if (D_803D5524->waterClass & WATER_DAMAGE) {
                        tmp += 1;
                    }
                    if (D_803D5524->waterClass & WATER_DAMAGE_X2) {
                        tmp += 2;
                    }
                    func_802B38FC_6C4FAC(D_803D5530, tmp, -1, 0);
                }
                if (SSSV_RAND(16) == 0xC) {
                    func_802D9C64_6EB314(
                        D_803D5530->xPos.h,
                        D_803D5530->zPos.h,
                        D_803D5530->yPos.h,
                        33,
                        GPACK_RGBA5551(224, 224, 128, 1));
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
  D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A += 1;
  D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk304 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302;
}

void func_802B3474_6C4B24(void) {
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk304 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302;
}

void func_802B34B8_6C4B68(Animal *a) {
    a->unk4A = MAX(0, a->unk4A - 1);
}

void func_802B34DC_6C4B8C(void) {
    Animal *a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    a->unk4A = MAX(0, a->unk4A - 1);
}

// increment
void func_802B3518_6C4BC8(void) {
    D_803D554A += 1;
}
// reset
void func_802B3530_6C4BE0(void) {
    D_803D554A = 1;
}
// decrement
void func_802B3540_6C4BF0(void) {
    D_803D554A = MAX(0, D_803D554A - 1);
}

void func_802B356C_6C4C1C(Animal *arg0, s16 damage, s16 arg2, u8 arg3) {
    s16 hpDrop;
    s16 temp_v1_2;
    s16 pad;

    damage <<= 4;

    if ((arg0->unk4C.unk26 != 0) || (arg0->unk4A != 0) || (arg0->unk16C->armour == 0xFF)) {
        damage = 0;
    }

    if (arg0->unk16C->unk80.bit == 0) {
        arg0->health = MAX(0, arg0->health - (damage >> 4));
    }

    switch (arg0->unk16C->unkE6) {
    case 0:
        hpDrop = (damage * 36) >> 4;
        break;
    case 1:
        hpDrop = (damage * 24) >> 4;
        break;
    case 2:
        hpDrop = (damage * 16) >> 4;
        break;
    case 3:
        hpDrop = (damage * 8) >> 4;
        break;
    case 4:
        hpDrop = (damage * 5) >> 4;
        break;
    default:
        hpDrop = (damage * 16) >> 4;
        break;
    }

    if ((arg2 >= 0) && (arg0->unk16C->unk80.bit) && (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        temp_v1_2 = arg0->unk16C->unkE6 - arg2;
        switch (temp_v1_2) {
        case 2:
            hpDrop = ((hpDrop * 3) >> 2);
            break;
        case 3:
            hpDrop = (hpDrop >> 1);
            break;
        case 4:
            hpDrop = (hpDrop >> 2);
            break;
        case 5:
            hpDrop = (hpDrop >> 3);
            break;
        case 6:
        case 7:
            hpDrop = 0;
            break;
        }
    }

    if ((arg0->unk16C->unk80.bit) && (arg3 != 0) && ((arg0->health - hpDrop) > 0)) {
        if (hpDrop > 480) {
            func_802DBA58_6ED108(14, arg0);
            func_802D9C64_6EB314(arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, 33, GPACK_RGBA5551(224, 224, 0, 1));
        } else if (hpDrop > 192) {
            func_802DBA58_6ED108(14, arg0);
            func_802D9C64_6EB314(arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, 17, GPACK_RGBA5551(224, 224, 0, 1));
        } else if (hpDrop >= 64) {
            func_802DBA58_6ED108(13, arg0);
            func_802D9C64_6EB314(arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, 8, GPACK_RGBA5551(224, 224, 0, 1));
        }
    }
    hpDrop = MIN(hpDrop, 560);

    if ((damage != 0) && (hpDrop <= 0)) {
        hpDrop = 1;
    }

    func_80349280_75A930(arg0, hpDrop >> 4);

    if (hpDrop > 0) {
        arg0->health = MAX(0, (arg0->health - MAX(1, hpDrop >> 4)));
    }
}

void func_802B38FC_6C4FAC(Animal *arg0, s16 damage, s16 arg2, u8 stars) {
    s16 hpDrop;
    s16 temp_v0;

    if ((arg0->unk4C.unk26 != 0) || (arg0->unk4A != 0)) {
        damage = 0;
    }
    // e.g. POLAR_BEAR_DEFENDING
    if (arg0->unk16C->armour == 0xFF) {
        damage = 0;
    }
    hpDrop = damage;
    if ((arg2 >= 0) && (arg0->unk16C->unk80.bit) && (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        temp_v0 = arg0->unk16C->unkE6 - arg2;
        switch (temp_v0) {
        case 2:
            hpDrop = (damage * 12) >> 4;
            break;
        case 3:
            hpDrop = (damage * 9) >> 4;
            break;
        case 4:
            hpDrop = (damage * 6) >> 4;
            break;
        case 5:
        case 6:
        case 7:
            hpDrop = (damage * 4) >> 4;
            break;
        }
    }

    if ((arg0->unk16C->unk80.bit) && (stars != 0) && ((arg0->health - hpDrop) > 0)) {
        if (hpDrop > 480) {
            func_802DBA58_6ED108(14, arg0);
            func_8034A684_75BD34(); // lots of stars
        } else if (hpDrop > 192) {
            func_802DBA58_6ED108(14, arg0);
            func_8034A914_75BFC4(); // medium amount of stars
        } else if (hpDrop >= 64) {
            func_802DBA58_6ED108(13, arg0);
            func_8034ABA4_75C254(); // small amount of stars
        }
    }

    // clamp min/max hp drop
    if ((damage != 0) && (hpDrop <= 0)) {
        hpDrop = 1;
    }
    if (hpDrop >= 35) {
        hpDrop = 35;
    }
    func_80349280_75A930(arg0, hpDrop);
    arg0->health = MAX(0, arg0->health - hpDrop);
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

    if (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
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
        // arg0 = (arg0 * 16) >> 4;
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

    tmpf = ABS(D_803D5530->xPos.h - D_803F2C44);
    x = (s16)tmpf >> 1;

    tmpf = ABS(D_803D5530->zPos.h - D_803F2C48);
    z = (s16)tmpf >> 1;

    tmpf = ABS(D_803D5530->yPos.h - D_803F2C4C);
    y = (s16)tmpf >> 1;

    return MAX(MAX(x, z), y) + x + z + y;
}
