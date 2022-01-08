#include <ultra64.h>
#include "common.h"

// weird offsets
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802963D0_6A7A80.s")

void func_80296544_6A7BF4(void) {
    f64 temp_f20;
    f64 temp_f22;
    f64 temp_f24;

    u8 i;

    D_803C0430.unk202 = 0;
    D_803C0430.unk204 = 0;

    if (D_803F2D72 == 0) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 1;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 3;
        }
    }
    if ((D_803F2D72 == 1) || (D_803F2D72 == 2)) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 7;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            D_803C0430.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80296C8C_6A833C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_8029726C_6A891C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80297628_6A8CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802983D0_6A9A80.s")
// returns are wrong
// s32 func_802983D0_6A9A80(void) {
//     s32 tmp0 = MIN(D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6, D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6);
//     s32 tmp1 = MIN(D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6, D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6);
//
//     if (tmp0 < tmp1) {
//         if (D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6 <
//             D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 0].unk6) {
//             return 0;
//         } else {
//             return 0;
//         }
//     } else {
//         if (D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 1][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6 <
//             D_803C0740[((u16)D_803F28E0[D_803F2A98].unk74 >> 6) + 0][((u16)D_803F28E0[D_803F2A98].unk78 >> 6) + 1].unk6) {
//             return 0;
//         } else {
//             return 0;
//         }
//     }
// }

// draw_water
void func_802985AC_6A9C5C(Gfx **dl) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_800DCC20[D_803C0430.unk202]);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 1024);
    gDPPipeSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(63));
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

    gDPSetEnvColor((*dl)++, D_803E1BBD, D_803E1BBE, D_803E1BBF, D_803F2D50.unk5B);

    gDPSetPrimColor((*dl)++, 128, D_803C0430.unk200, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2D50.unk57);
}

void func_8029877C_6A9E2C(void) {
    // maximum 64
    D_803C0430.unk204 += 1;
    D_803C0430.unk204 &= 0x3F;

    // maximum 255
    D_803C0430.unk200 += 64;
    if (D_803C0430.unk200 >= 256) {
        D_803C0430.unk200 &= 0xFF;
        D_803C0430.unk202 += 1;
        D_803C0430.unk202 &= 0xF;
    }

    D_803C0430.unk208 = 0;

    D_803C0430.unk206 += D_803C0430.unk20A;

    if (D_803C0430.unk206 == 240) {
        D_803C0430.unk20A = -8;
    }
    if (D_803C0430.unk206 == 0) {
        D_803C0430.unk20A = 8;
    }
    // maximum 31
    D_803C0430.unk20C += 1;
    D_803C0430.unk20C &= 0x1F;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298818_6A9EC8.s")
// miles away
// s16 func_80298818_6A9EC8(s16 arg0, s16 arg1) {
//     s32 temp_lo;
//     s32 temp_t5;
//
//     s32 temp_t1_2;
//     s32 temp_t9;
//
//     s16 phi_v1;
//     s16 phi_t3;
//     s16 phi_t4;
//     s16 phi_a2;
//
//     s16 tmp0, tmp1, tmp2, tmp3;
//
//     temp_lo = (arg0 >> 6) * (arg1 >> 6);
//     temp_t5 = (arg0 >> 6) + (arg1 >> 6);
//
//     temp_t1_2 = D_803C0634 + ((temp_lo + ((arg0 >> 6) * (arg0 >> 6))) * 8);
//     phi_v1 = D_803C0430.unk0[(temp_lo + 0) & 7][(temp_t1_2 + 0) & 0x3F] + (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2); //+ ((<< 6) + (temp_t1_2 & 0x3F))) + (temp_t2->unk6 * 4);
//     phi_t3 = D_803C0430.unk0[(temp_lo + 1) & 7][(temp_t1_2 + 8) & 0x3F] + (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2); //+ ((() << 6) + ((temp_t1_2 + 8) & 0x3F))) + (temp_t2->unkE * 4);
//
//     temp_t9 = D_803C0634 + ((temp_t5 + (arg0 >> 6) + (arg0 >> 6)) * 8);
//     phi_t4 = D_803C0430.unk0[(temp_t5 + 1) & 7][(temp_t9 + 16) & 0x3F] + (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2);
//     phi_a2 = D_803C0430.unk0[(temp_t5 + 0) & 7][(temp_t9 +  8) & 0x3F] + (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2);
//
//     // is this necessary?
//     tmp0 = phi_v1;
//     tmp1 = phi_t3;
//     tmp2 = phi_t4;
//     tmp3 = phi_a2;
//
//     if (tmp0 < 16) {
//         phi_v1 = MAX(tmp3, MAX(tmp2, tmp1));
//     }
//     if (tmp1 < 16) {
//         phi_t3 = MAX(tmp0, MAX(tmp3, tmp2));
//     }
//     if (tmp2 < 16) {
//         phi_t4 = MAX(tmp0, MAX(tmp3, tmp1));
//     }
//     if (tmp3 < 16) {
//         phi_a2 = MAX(tmp0, MAX(phi_t4, tmp1));
//     }
//
//     if ((s16)(arg0 & 0x3F) < (s16)(arg1 & 0x3F)) {
//         return (phi_v1 + ((((phi_t4 - phi_t3) * (arg0 & 0x3F)) + ((phi_t3 - phi_v1) * (arg1 & 0x3F))) >> 6));
//     } else {
//         return (phi_v1 + ((((phi_a2 - phi_v1) * (arg0 & 0x3F)) + ((phi_t4 - phi_a2) * (arg1 & 0x3F))) >> 6));
//     }
// }

s16 func_80298B70_6AA220(s16 arg0, s16 arg1) {
    s16 temp_t3;
    s16 temp_v0;

    s16 temp_a2;
    s16 temp_a3;
    s16 temp_t0;
    s16 temp_v1;

    temp_v1 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2;
    temp_a2 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2;
    temp_a3 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2;
    temp_t0 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2;

    if ((temp_v1 + temp_a2 + temp_a3 + temp_t0) == 0) {
        return 0;
    }

    temp_v0 = arg0 & 0x3F;
    temp_t3 = arg1 & 0x3F;
    if (temp_v0 < temp_t3) {
        return (D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_a3 - temp_a2) * temp_v0) + ((temp_a2 - temp_v1) * temp_t3)) >> 6);
    } else {
        return (D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_t0 - temp_v1) * temp_v0) + ((temp_a3 - temp_t0) * temp_t3)) >> 6);
    }
}

#ifdef NON_MATCHING
// regalloc
void func_80298D44_6AA3F4(Animal *arg0) {
    s16 x;
    s16 z;
    s32 tmp;

    x = (((D_803C0740[arg0->xPos >> 6][arg0->zPos >> 6].unk7 & 0xF0) >> 4) & 7) * (1 - (((D_803C0740[arg0->xPos >> 6][arg0->zPos >> 6].unk7 >> 4) & 8) >> 2));
    z = (((D_803C0740[arg0->xPos >> 6][arg0->zPos >> 6].unk7       )     ) & 7) * (1 - (((D_803C0740[arg0->xPos >> 6][arg0->zPos >> 6].unk7     ) & 8) >> 2));

    if (x != 0) {
        arg0->xVelocity.w -= (arg0->xVelocity.w - (x << 17)) >> 1;
    }
    if (z != 0) {
        arg0->zVelocity.w -= (arg0->zVelocity.w - (z << 17)) >> 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298D44_6AA3F4.s")
#endif

s32 func_80298E08_6AA4B8(s16 arg0, s16 arg1) {
    // equivalent to dividing by 64
    arg0 >>= 6;
    arg1 >>= 6;

    if ((arg0 < D_803F2D50.unk10) ||
        (arg1 < D_803F2D50.unk12) ||
        ((D_803F2D50.unk10 + (u16)D_803F2D50.unk14) < arg0) ||
        ((D_803F2D50.unk12 + (u16)D_803F2D50.unk16) < arg1)) {
        return 0;
    }

    return 1;
}

s16 func_80298E98_6AA548(s16 arg0, s16 arg1) {
    s16 tmp;
    s16 res;

    res = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;

    if (func_80298E08_6AA4B8(arg0, arg1)) {
        tmp = D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63];
        return res + tmp;
    } else {
        return res;
    }
}

s16 func_80298F78_6AA628(s16 arg0, s16 arg1) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 temp_t4;
    s16 temp_t6;

    func_80299640_6AACF0(arg0 >> 6, arg1 >> 6, &sp36, &sp34, &sp32, &sp30);
    temp_t4 = arg0 & 0x3F;
    temp_t6 = arg1 & 0x3F;
    if ((temp_t4 + temp_t6) < 64) {
        return sp36 + ((((sp32 - sp36) * temp_t4) + ((sp34 - sp36) * temp_t6)) >> 6);
    } else {
        return sp30 + ((((sp34 - sp30) * (64 - temp_t4)) + ((sp32 - sp30) * (64 - temp_t6))) >> 6);
    }
}

s16 func_802990A4_6AA754(s16 arg0, s16 arg1) {
    s16 tmp0;
    s16 tmp1;

    tmp0 = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;
    tmp1 = D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63] >> 1;

    return tmp0 + tmp1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80299140_6AA7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80299640_6AACF0.s")
