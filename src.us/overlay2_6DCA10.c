#include <ultra64.h>
#include "common.h"


// zero out particle data?
void func_802CB360_6DCA10(void) {
    D_803D6120.unk0[0].unk0 = 0;
    memset_bytes((u8*)&D_803D6120, 0, sizeof(D_803D6120));
    D_803D6120.unk3FD4 = 0; // ?
}

// this is a big one...
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802CB394_6DCA44.s")

// only called with these values:
// func_802D5AD8_6E7188(0, 1) (enable dl 0)
// func_802D5AD8_6E7188(1, 8) (enable dl 1 thu 7)
void func_802D5AD8_6E7188(s16 start, s16 end) {
    s16 i;

    for (i = start; i < end; i++) {
        if (D_803D6120.unk3FC8[i] == 1) {
            gSPDisplayList(D_801D9E7C++, &D_80204278->unk109A0[i]);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D5B88_6E7238.s")
// long way still to go
// s32 func_802D5B88_6E7238(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s8 arg4, u16 arg5, u16 arg6, u16 arg7) {
//     u8 sp3F;
//     u16 sp3C;
//     u16 *sp2C;
//     s32 sp1C;
//     void *sp18;
//     s32 temp_t5;
//     s32 temp_t6;
//     s32 temp_v0_4;
//     s32 temp_v0_5;
//     s32 temp_v1;
//     s32 temp_v1_2;
//     struct099 *temp_v0_3;
//     u8 temp_t7;
//     u8 temp_t7_2;
//     struct101 *temp_a2;
//     struct101 *temp_v0;
//     struct101 *temp_v0_2;
//     struct101 *temp_v1_3;
//     struct101 *temp_v1_4;
//     struct101 *temp_v1_5;
//     s32 phi_v1;
//     s32 phi_v1_2;
//     s32 phi_v1_3;
//     struct099 *phi_t2;
//     u8 *phi_t0;
//
//     D_803D6120.unk0[0].unk0++;
//     phi_v1 = D_803D6120.unk0[0].unk0;
//
//     // wraparound
//     if (D_803D6120.unk0[0].unk0 > 254) {
//         phi_v1 = 0;
//         D_803D6120.unk0[0].unk0 = 0;
//     }
//     // find unused?
//     for (temp_v0 = &D_803D6120.unk0[D_803D6120.unk0[0].unk0]; ((temp_v0->unk22 == 1) || (((temp_v0 + 1)->unk0 & 2) && (temp_v0->unk20 != 0))); temp_v0 = &D_803D6120.unk0[D_803D6120.unk0[phi_v1].unk0]) {
//         phi_v1++;
//         D_803D6120.unk0[0].unk0 = phi_v1;
//         // wraparound
//         if (phi_v1 > 254) {
//             D_803D6120.unk0[0].unk0 = 0;
//             phi_v1 = 0;
//         }
//     }
//
//     temp_v0_3 = &D_803A20C0_7B3770[arg3]; // (arg3 * 0x18) +
//     phi_t2 = temp_v0_3;
//     if ((temp_v0_3->unk0 & 0x400) == 0) {
//         temp_v0_4 = func_802EA004_6FB6B4(arg0 << 0x10, arg1 << 0x10, arg2 << 0x10, arg4);
//         if ((temp_v0_4 == 2) || (temp_v0_4 == 1)) {
//             return 0;
//         }
//     }
//     sp1C = arg2 << 0x10;
//     sp3C = func_8012826C();
//     sp3F = D_803D6120.unk0[0].unk0;
//     if (arg3 == 0x78) {
//         arg3 = SSSV_RAND(2) + 0x19;
//         arg7 = (guRandom() % arg4) + arg4;
//         arg5 = GPACK_RGBA5551(248, 200, 0, 0); // 0xFE40U; // yellow
//         arg6 = GPACK_RGBA5551(248, 0, 0, 0); // 0xF800U; // red
//     }
//     temp_a2 = &D_803D6120.unk0[D_803D6120.unk0[0].unk0];
//     // FIXME:
//     //temp_a2->unk40 = 0; // more likely next item?
//     D_803D6120.unk0[D_803D6120.unk0[0].unk0].unk0 = 0;
//     // sp18 = temp_a2;
//     temp_a2->unk34 = (s8) arg3;
//
//     temp_v0_5 = func_80310F58_722608(arg0, arg1);
//
//     temp_v1_5 = temp_a2->unk8; // temp_a2 + 8
//     if (temp_v0_5 < sp1C) {
//         temp_v1_5->unk38 |= 1;
//     }
//     if (phi_t2->unk0 & 0x1000) {
//         temp_v1_5->unk38 |= 2;
//     }
//     if ((phi_t2->unk0 & 0x800) &&
//         (temp_v0_5 != 0x40000000) &&
//         (sp1C < temp_v0_5)) {
//         return 0;
//     }
//     temp_v1_5->unk34 = arg7;
//     temp_v1_5->unk20 = 0;
//     temp_v1_5->unk24 = 0;
//     temp_v1_5->unk28 = 0;
//     temp_t6 = arg1 << 0x10;
//     temp_t5 = arg0 << 0x10;
//     if ((phi_t2->unk0 & 0x100) != 0) {
//         temp_v1_5->unk1A = 1;
//     } else {
//         temp_v1_5->unk1A = 0;
//     }
//     temp_v1_5->unk0 = (s32) (temp_t5 >> 0x1F);
//     temp_v1_5->unk4 = temp_t5;
//     temp_v1_5->unk8 = (s32) (temp_t6 >> 0x1F);
//     temp_v1_5->unkC = temp_t6;
//     temp_v1_5->unk10 = (s32) (sp1C >> 0x1F);
//     temp_v1_5->unk14 = sp1C;
//     temp_v1_5->unk2E = phi_t2->unk2;
//     temp_v1_5->unk18 = phi_t2->unk4;
//     if (arg4 == 0) {
//         temp_v1_5->unk1C = phi_t2->unk2;
//     } else {
//         temp_v1_5->unk1C = arg4;
//     }
//     if (arg5 == 0) {
//         temp_v1_5->unk30 = phi_t2->unkE;
//     } else {
//         temp_v1_5->unk30 = arg5;
//     }
//     if (arg6 == 0) {
//         temp_v1_5->unk32 = phi_t2->unk10;
//     } else {
//         temp_v1_5->unk32 = arg6;
//     }
//     temp_v1_5->unk2D = 0;
//     temp_v1_5->unk36 = 0U;
//
//     switch (arg3) {
//     case 38:
//         temp_v1_5->unk18 = (s16) (temp_v1_5->unk18 - (sp3C & 7));
//         break;
//     case 0:
//     case 1:
//     case 2:
//     case 3:
//     case 4:
//     case 5:
//     case 6:
//     case 7:
//     case 8:
//     case 25:
//     case 48:
//         temp_v1_5->unk36 = arg7;
//         break;
//     }
//     temp_v1_5->unk18 = (s16) phi_t2->unk4;
//     D_803D6120.unk0[0].unk0 += 1;
//     return 1;
// }

// arg3 = particle 38 --> Zzzzz...
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/create_particle_effect.s")

void func_802D6738_6E7DE8(void) {
    s16 pad1[10];
    s16 sp7A;
    s16 sp78;
    s16 sp76;

    s16 pad2[12];

    s16 i;

    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();

    D_803D6120.unk3FD0 += 1;
    if (D_803F2D50.unk1C != 0) {
        for (i = 0; i < D_803F2D50.unk1C; i++) {
            // get some location?
            func_80343720_754DD0(&sp7A, &sp78, &sp76);
            create_particle_effect(
                sp7A,
                sp78,
                sp76,
                55,
                0,
                0,
                0,
                0,
                GPACK_RGBA5551(0, 0, 0, 0),
                GPACK_RGBA5551(0, 0, 0, 0),
                0);
        }
    }

    if (D_803F2D50.unk1E != 0) {
        for (i = 0; i < D_803F2D50.unk1E; i++) {
            func_80343720_754DD0(&sp7A, &sp78, &sp76);
            create_particle_effect(
                sp7A,
                sp78,
                sp76,
                57,
                0,
                0,
                0,
                0,
                GPACK_RGBA5551(D_803E1BBA, D_803E1BBB, D_803E1BBC, 1),
                GPACK_RGBA5551(D_803E1BBA, D_803E1BBB, D_803E1BBC, 1),
                0);
        }
    }
    if (D_803F2D50.unk1E != 0) {
        D_803D6120.unk3FD2 = 0x3FF;
    } else {
        D_803D6120.unk3FD2 = 0;
    }

    if (D_803D6120.unk3FD2 != 0) {
        if ((func_8012826C() & D_803D6120.unk3FD2) == 1) {
            D_803D6120.unk3FD4 = 1;
        }
    }

    if (D_803D6120.unk3FD4 != 0) {
        D_803D6120.unk3FD4 = D_803D6120.unk3FD4 + 1;
        D_803D6120.unk3FD4 = D_803D6120.unk3FD4 & 7;
        if (SSSV_RAND(2)) {
            D_80204278->unk3B638.l.colc[0] = 0xFF;
            D_80204278->unk3B638.l.col[0] = D_80204278->unk3B638.l.colc[0];
            D_80204278->unk3B638.l.colc[1] = 0xFF;
            D_80204278->unk3B638.l.col[1] = D_80204278->unk3B638.l.colc[1];
            D_80204278->unk3B638.l.colc[2] = 0xFF;
            D_80204278->unk3B638.l.col[2] = D_80204278->unk3B638.l.colc[2];
            D_80204278->unk3B640[0].l.colc[0] = 0xFF;
            D_80204278->unk3B640[0].l.col[0] = D_80204278->unk3B640[0].l.colc[0];
            D_80204278->unk3B640[0].l.colc[1] = 0xFF;
            D_80204278->unk3B640[0].l.col[1] = D_80204278->unk3B640[0].l.colc[1];
            D_80204278->unk3B640[0].l.colc[2] = 0xFF;
            D_80204278->unk3B640[0].l.col[2] = D_80204278->unk3B640[0].l.colc[2];
        } else if (D_803D6120.unk3FD2 != 0) {
            D_80204278->unk3B638.l.colc[0] = 0x50;
            D_80204278->unk3B638.l.col[0] = D_80204278->unk3B638.l.colc[0];
            D_80204278->unk3B638.l.colc[1] = 0x50;
            D_80204278->unk3B638.l.col[1] = D_80204278->unk3B638.l.colc[1];
            D_80204278->unk3B638.l.colc[2] = 0x50;
            D_80204278->unk3B638.l.col[2] = D_80204278->unk3B638.l.colc[2];
            D_80204278->unk3B640[0].l.colc[0] = 0x50;
            D_80204278->unk3B640[0].l.col[0] = D_80204278->unk3B640[0].l.colc[0];
            D_80204278->unk3B640[0].l.colc[1] = 0x50;
            D_80204278->unk3B640[0].l.col[1] = D_80204278->unk3B640[0].l.colc[1];
            D_80204278->unk3B640[0].l.colc[2] = 0x50;
            D_80204278->unk3B640[0].l.col[2] = D_80204278->unk3B640[0].l.colc[2];
        }
    } else if (D_803D6120.unk3FD2 != 0) {
        D_80204278->unk3B638.l.colc[0] = 0x50;
        D_80204278->unk3B638.l.col[0] = D_80204278->unk3B638.l.colc[0];
        D_80204278->unk3B638.l.colc[1] = 0x50;
        D_80204278->unk3B638.l.col[1] = D_80204278->unk3B638.l.colc[1];
        D_80204278->unk3B638.l.colc[2] = 0x50;
        D_80204278->unk3B638.l.col[2] = D_80204278->unk3B638.l.colc[2];
        D_80204278->unk3B640[0].l.colc[0] = 0x50;
        D_80204278->unk3B640[0].l.col[0] = D_80204278->unk3B640[0].l.colc[0];
        D_80204278->unk3B640[0].l.colc[1] = 0x50;
        D_80204278->unk3B640[0].l.col[1] = D_80204278->unk3B640[0].l.colc[1];
        D_80204278->unk3B640[0].l.colc[2] = 0x50;
        D_80204278->unk3B640[0].l.col[2] = D_80204278->unk3B640[0].l.colc[2];
    }
    if (D_803F2D50.segment == 1) {
        sp7A = RAND(63) + 4;
        sp78 = RAND(127) + 8;
        if (((D_803C0740[sp7A][sp78].unk0 != D_803C0740[sp7A + 1][sp78 + 1].unk0) || (D_803C0740[sp7A][sp78].unk0 != D_803C0740[sp7A - 1][sp78 - 1].unk0)) && (D_803C0740[sp7A][sp78].unk6 == 0)) {
            func_802D5B88_6E7238(sp7A << 6, sp78 << 6, D_803C0740[sp7A][sp78].unk0 << 3, 53, 0, 0, 0, 5);
        } else {
            sp7A = RAND(63) + 4;
            sp78 = RAND(127) + 8;
            if (((D_803C0740[sp7A][sp78].unk0 != D_803C0740[sp7A + 1][sp78 + 1].unk0) || (D_803C0740[sp7A][sp78].unk0 != D_803C0740[sp7A - 1][sp78 - 1].unk0)) && (D_803C0740[sp7A][sp78].unk6 == 0)) {
                func_802D5B88_6E7238(sp7A << 6, sp78 << 6, D_803C0740[sp7A][sp78].unk0 << 3, 53, 0, 0, 0, 5);
            }
        }
    }
    if ((D_803F2D50.unk4C == 0) || (D_803F2D50.unk4C == 3)) {
        for (i = 0; i < 5; i++) {
            sp7A = D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h - 960;
            sp78 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h - 960;
            if (sp7A < 0) {
                sp7A = 0;
            }
            if (sp78 < 0) {
                sp78 = 0;
            }
            sp7A += RAND(960) * 2;
            sp78 += RAND(960) * 2;
            sp76 = func_80298818_6A9EC8(sp7A, sp78);
            if ((sp76 != 0) && ((func_802D7434_6E8AE4(sp7A, sp78) + 64) < sp76)) {
                func_802D5B88_6E7238(
                    sp7A,
                    sp78,
                    sp76,
                    53,
                    0,
                    GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
                    GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
                    2);
            }
        }

        if ((D_803F28E0[D_803F2A98].unk7C - 12.0f) < func_80298818_6A9EC8((u16) D_803F28E0[D_803F2A98].unk74, (u16) D_803F28E0[D_803F2A98].unk78)) {
            sp7A = D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h - 512;
            sp78 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h - 512;
            if (sp7A < 0) {
                sp7A = 0;
            }
            if (sp78 < 0) {
                sp78 = 0;
            }
            sp7A += RAND(512) * 2;
            sp78 += RAND(512) * 2;
            if (func_80298818_6A9EC8(sp7A, sp78) != 0) {
                sp76 = func_802D7434_6E8AE4(sp7A, sp78);
                func_802D7AD4_6E9184(sp7A, sp78, sp76, RAND(3));
            }
        }
    } else if (D_803F2D50.unk4C != 2) {
        for (i = 0; i < 4; i++) {
            sp7A = D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h - 960;
            sp78 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h - 960;
            if (sp7A < 0) {
                sp7A = 0;
            }
            if (sp78 < 0) {
                sp78 = 0;
            }
            sp7A += RAND(960) * 2;
            sp78 += RAND(960) * 2;
            sp76 = func_80298818_6A9EC8(sp7A, sp78);
            if ((sp76 != 0) && ((func_802D7434_6E8AE4(sp7A, sp78) + 64) < sp76)) {
                func_802D5B88_6E7238(sp7A, sp78, sp76, 106, RAND(15) + 10, 0, 0, 0);
            }
        }
    }
}

s16 func_802D7434_6E8AE4(s16 arg0, s16 arg1) {
    s16 temp_t2;
    s16 temp_t4;

    s32 temp_t6;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_t9;

    s16 ret;

    temp_t6 = D_803C0740[(s16)(arg0 >> 6) + 0][(s16)(arg1 >> 6) + 0].unk0 << 3;
    temp_t8 = D_803C0740[(s16)(arg0 >> 6) + 0][(s16)(arg1 >> 6) + 1].unk0 << 3;
    temp_t7 = D_803C0740[(s16)(arg0 >> 6) + 1][(s16)(arg1 >> 6) + 1].unk0 << 3;
    temp_t9 = D_803C0740[(s16)(arg0 >> 6) + 1][(s16)(arg1 >> 6) + 0].unk0 << 3;

    temp_t2 = arg0 & 0x3F;
    temp_t4 = arg1 & 0x3F;

    if ((D_803C0740[(s16)(arg0 >> 6) + 0][(s16)(arg1 >> 6) + 0].unk4 & 1)) {
        if (temp_t2 < temp_t4) {
            ret = (((((temp_t7 - temp_t8) * temp_t2) + ((temp_t8 - temp_t6) * temp_t4)) >> 6) + temp_t6);
        } else {
            ret = (((((temp_t9 - temp_t6) * temp_t2) + ((temp_t7 - temp_t9) * temp_t4)) >> 6) + temp_t6);
        }
    } else if ((temp_t2 + temp_t4) < 64) {
        ret = (((((temp_t9 - temp_t6) * temp_t2) + ((temp_t8 - temp_t6) * temp_t4)) >> 6) + temp_t6);
    } else {
        ret = (((((temp_t8 - temp_t7) * (64 - temp_t2)) + ((temp_t9 - temp_t7) * (64 - temp_t4))) >> 6) + temp_t7);
    }

    return ret;
}

#ifdef NON_MATCHING
void func_802D760C_6E8CBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    s16 temp_s0;
    s16 temp_s2;
    s16 phi_v1;
    s16 i;
    s32 phi_v1_4;
    u16 random;

    if (arg3 < 2) {
        arg3 = 2;
    }

    phi_v1 = ABS(arg4);
    if (phi_v1 > 6) {
        phi_v1 = 6;
    }
    if (phi_v1 < 2) {
        phi_v1 = 2;
    }

    if (arg3 < 17) {
        tmp1 = 0;
    } else if ((arg3 > 16) && (arg3 < 27)) {
        tmp1 = 1;
    } else if (arg3 > 26) {
        tmp1 = 2;
    }

    tmp0 = (tmp1 + 1) << 4;
    if (tmp0 > 25) {
        tmp0 = 25;
    }

    tmp2 = arg3 / 4;
    if (tmp2 < 4) {
        tmp2 = 4;
    }
    if (tmp2 > 24) {
        tmp2 = 24;
    }

    for (i = 0; i < tmp0; i++) {
        temp_s0 = arg0 + ((D_80152350.unk2D0[(s16)(SSSV_RAND(8) + (360 / tmp0 * i))] * arg3) >> 9);
        temp_s2 = arg1 + ((D_80152350.unk384[(s16)(SSSV_RAND(8) + (360 / tmp0 * i))] * arg3) >> 9);
        phi_v1_4 = MAX(arg2, func_80298E98_6AA548(temp_s0, temp_s2));
        phi_v1_4 = (s16)(phi_v1_4 + 20);
        random = func_8012826C();
        guRandom();
        create_particle_effect(
            temp_s0,
            temp_s2,
            phi_v1_4,
            24,
            D_80152350.unk2D0[(s16)(360 / tmp0 * i)] * tmp2 << 4,
            D_80152350.unk384[(s16)(360 / tmp0 * i)] * tmp2 << 4,
            ((random & 0x7FFF) << 2) + (phi_v1 << 16),
            2,
            GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
            GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
            0);
    }
    if (tmp1 == 0) {
        tmp3 = 0x5000;
    }
    if (tmp1 == 1) {
        tmp3 = 0x7FFF;
    }
    if (tmp1 == 2) {
        tmp3 = 0x5000;
    }
    // this seems weird
    if (tmp1 < 2) {
        play_sound_effect_at_location(SFX_UNKNOWN_165, 0x7FFF, 0x80, arg0, arg1, arg2, 1.0f);
    } else {
        play_sound_effect_at_location(SFX_UNKNOWN_76, tmp3, 0x80, arg0, arg1, arg2, 1.0f);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D760C_6E8CBC.s")
#endif

void func_802D7AD4_6E9184(s16 x, s16 z, s16 y, s16 arg3) {
    s16 i;
    s16 tmp = (arg3 * 3) + 1;

    for (i = 0; i < tmp; i++) {
            func_802D5B88_6E7238(
                SSSV_RAND(8) + x,
                SSSV_RAND(8) + z,
                y,
                28,
                SSSV_RAND(8) + 1,
                0,
                0,
                0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D7BE0_6E9290.s")

void func_802D9C64_6EB314(s16 x, s16 z, s16 y, s16 arg3, u16 color) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    s32 pad[3];
    s16 i;

    if (arg3 < 2) {
        arg3 = 2;
    }

    if (arg3 < 17) {
        tmp1 = 0;
    } else if ((arg3 > 16) && (arg3 < 33)) {
        tmp1 = 1;
    } else if (arg3 > 31) {
        tmp1 = 2;
    }

    tmp0 = ((SSSV_RAND(2) + tmp1) * 3) + 6;
    if (tmp0 > 12) {
        tmp0 = 12;
    }

    tmp2 = arg3 / 4;
    if (tmp2 < 4) {
        tmp2 = 4;
    }
    if (tmp2 > 24) {
        tmp2 = 24;
    }
    guRandom();
    guRandom();
    guRandom();
    for (i = 0; i < tmp0; i++) {
        create_particle_effect(
            x,
            z,
            y,
            35,
            D_80152350.unk2D0[(s16)(RAND(90) + (360 / tmp0) * i)] * tmp2 * 84,
            D_80152350.unk384[(s16)(RAND(90) + (360 / tmp0) * i)] * tmp2 * 84,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) + FTOFIX32(6.0),
            SSSV_RAND(2) + 3,
            color,
            color,
            0);
    }
    func_8012826C();
    if (tmp1 == 0) {
        tmp3 = 0x2000;
    }
    if (tmp1 == 1) {
        tmp3 = 0x2500;
    }
    if (tmp1 == 2) {
        tmp3 = 0x3000;
    }
    play_sound_effect_at_location(SFX_UNKNOWN_77, tmp3, 0x80, x, z, y, 1.0f);
}

void func_802D9FC4_6EB674(s16 x, s16 z, s16 y, s16 arg3) {
    s16 phi_s0;
    u16 temp_v1;
    s16 i;

    phi_s0 = RAND(4);

    switch (arg3) {
    case 1: // energy ball
        play_sound_effect_at_location(SFX_PICKUP_ENERGY_BALL, 0x6000, 0, x, z, y, 1.0f);
        for (i = 0; i < 8; i++) {
            phi_s0 = (s16)(phi_s0 + 1) % 4;
            create_particle_effect(
                x,
                z,
                y,
                60,
                RAND(128),
                0,
                0,
                16,
                D_803A20B0_7B3760[phi_s0],
                D_803A20B0_7B3760[phi_s0],
                i << 2);
        }
        break;
    case 2: // powercell?
        play_sound_effect_at_location(D_803A1BB0_7B3260[D_803F2D30.powercells].id, 0x6000, 0, x, z, y, D_803A1BB0_7B3260[D_803F2D30.powercells].unk0);
        for (i = 0; i < 8; i++) {
            phi_s0 = (s16)(phi_s0 + 1) % 4;
            create_particle_effect(
                x,
                z,
                y,
                61,
                RAND(128),
                0,
                0,
                16,
                D_803A20B0_7B3760[phi_s0 + 4],
                D_803A20B0_7B3760[phi_s0 + 4],
                i << 2);
        }
        break;
    case 3: // trophy?
        play_sound_effect_at_location(SFX_UNKNOWN_112, 0x6000, 0, x, z, y, 1.0f);
        for (i = 0; i < 16; i++) {
            create_particle_effect(
                (RAND(20) + x) - 12,
                (RAND(20) + z) - 12,
                (RAND(20) + y) - 12,
                89,
                RAND(128),
                0,
                0,
                1,
                GPACK_RGBA5551(RAND(64) + 192, RAND(64) + 192, 0, 1),
                GPACK_RGBA5551(RAND(64) + 192, RAND(64) + 192, 0, 1),
                32);
        }
        break;
    case 4: // key?
        play_sound_effect_at_location(SFX_UNKNOWN_163, 0x5000, 0, x, z, y, 1.0f);
        for (i = 0; i < 16; i++) {
            create_particle_effect(
                (RAND(20) + x) - 12,
                (RAND(20) + z) - 12,
                (RAND(20) + y) - 12,
                89,
                RAND(128),
                0,
                0,
                16,
                GPACK_RGBA5551(RAND(64) + 192, RAND(64) + 192, 0, 1),
                GPACK_RGBA5551(RAND(64) + 192, RAND(64) + 192, 0, 1),
                32);
        }
        break;
    case 5: // objective (e.g. keycard)
    case 6: // objective but no sound?
        if (arg3 == 5) {
            play_sound_effect_at_location(SFX_UNKNOWN_78, 0x6000, 0, x, z, y, 1.0f);
        }
        for (i = 0; i < 16; i++) {
            create_particle_effect(
                (RAND(60) + x) - 36,
                (RAND(60) + z) - 36,
                (RAND(60) + y) - 36,
                65,
                RAND(128),
                0,
                0,
                16,
                GPACK_RGBA5551(248, 0, 248, 1),
                GPACK_RGBA5551(248, 0, 248, 1),
                0);
        }
        break;
    default:
        break;
    }
}
