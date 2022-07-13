#include <ultra64.h>
#include "common.h"


// tbd
void func_802BE1A0_6CF850(struct103*, s16, u8, u8, u8, s16, s16, s16, s32, s32, s32, s32, s16);
void func_802C3F58_6D5608(struct103*, u8, u8, u8, s16, s16, s16);

void func_802BB840_6CCEF0(u16 arg0) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;

    if (1) {};
    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    D_80203FE0[26].unk0 = tmp0;
    D_80203FE0[26].unk2 = (tmp1 - arg0) & 0xFFFF; // fakematch shenanigans
    D_80203FE0[26].unk4 = tmp2;
}

// unused? more nonsense
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB870_6CCF20.s")
// void func_802BB870_6CCF20(u16 arg0) {
//     s16 phi_t1;
//
//     s16 tmp0;
//     s16 tmp1;
//     s16 tmp2;
//     s16 tmp3;
//
//     tmp2 = D_80203FE0[2].unk4;
//     tmp1 = D_80203FE0[2].unk2;
//     tmp0 = D_80203FE0[2].unk0;
//
//     if (1) {};
//
//     tmp3 = D_80203FE0[0].unk2;
//
//     phi_t1 = tmp3 - tmp1;
//     tmp1 = tmp1 - arg0;
//
//     if (phi_t1 == 0) {
//         phi_t1 = 1;
//     }
//
//     tmp2 += ((((tmp2 - D_80203FE0[0].unk4) / 2) * arg0) / phi_t1);
//
//     D_80203FE0[26].unk0 = tmp0;
//     D_80203FE0[26].unk2 = tmp1;
//     D_80203FE0[26].unk4 = tmp2;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB938_6CCFE8.s")
//more nonsense
// void func_802BB938_6CCFE8(u16 arg0) {
//     s16 temp_a0;
//     s16 temp_a1;
//     s16 temp_a2;
//     s16 temp_t1;
//     s16 temp_v1;
//     u16 temp_a3;
//     s16 phi_t1;
//     s16 new_var;
//
//     temp_a3 = arg0; // & 0xFFFF;
//
//     temp_a0 = D_80203FE0[2].unk2;
//     new_var = D_80203FE0[0].unk2;
//     temp_a2 = D_80203FE0[2].unk4;
//
//     temp_t1 = new_var - temp_a0;
//     temp_v1 = temp_a0 - temp_a3;
//
//     phi_t1 = (s32) temp_t1;
//
//     if (phi_t1 == 0) {
//         temp_v1 = temp_a0 - temp_a3;
//         phi_t1 = 1;
//     }
//
//     D_80203FE0[26].unk0 = D_80203FE0[2].unk0;
//
//     if ((D_80203FE0 && D_80203FE0) && D_80203FE0) {};
//
//     temp_a1 = temp_a2 + ((((temp_a2 - D_80203FE0[0].unk4) / 2) * temp_a3) / phi_t1);
//     D_80203FE0[26].unk2 = ((temp_a1 - temp_a2) + temp_v1);
//     D_80203FE0[26].unk4 = ((temp_a0 - temp_v1) + temp_a1);
// }

// used by fox, called with func_802BBA10_6CD0C0(870)
void func_802BBA10_6CD0C0(u16 arg0) {
    struct106 *tmp;
    s16 temp_v1;
    s16 phi_a1_2;
    s32 phi_a0;
    s16 tmp0, tmp1, tmp2;

    tmp = &D_803D5528->unk3C8;

    if (tmp->unk6 != 0) {
        tmp->unk8 += 1;
    }
    temp_v1 = D_80203FE0[1].unk2 - D_80203FE0[2].unk2;
    if (temp_v1 == 0) {
        phi_a0 = 0;
    } else {
        phi_a0 = ((D_80203FE0[1].unk4 - D_80203FE0[2].unk4) << 0xA) / (s32) temp_v1;
    }

    phi_a1_2 = D_803D552C->unk302 - tmp->unk4;
    while (phi_a1_2 < -128) {
        phi_a1_2 += 256;
    };
    while (phi_a1_2 >= 128) {
        phi_a1_2 -= 256;
    };

    if (ABS(phi_a1_2) < 48) {
        if (phi_a1_2 < 0) {
            tmp->unk4 -= 2;
            if (tmp->unk4 < 0) {
                tmp->unk4 += 256;
            }
            phi_a1_2 += 1;
        }
        if (phi_a1_2 > 0) {
            tmp->unk4 += 2;
            if (tmp->unk4 >= 256) {
                tmp->unk4 -= 256;
            }
            phi_a1_2 -= 1;
        }
    } else {
        if (phi_a1_2 < 0) {
            tmp->unk4 -= 4;
            if (tmp->unk4 < 0) {
                tmp->unk4 += 256;
            }
            phi_a1_2 += 2;
        }
        if (phi_a1_2 > 0) {
            tmp->unk4 += 4;
            if (tmp->unk4 >= 256) {
                tmp->unk4 -= 256;
            }
            phi_a1_2 -= 2;
        }
    }

    if (1) {};

    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    tmp0 += (D_80152350.unk2D0[phi_a1_2] * arg0) / 256;
    tmp2 -= (phi_a0 * arg0) / 1024;
    tmp1 -= (arg0 * D_80152350.unk384[phi_a1_2]) / 256;

    D_80203FE0[26].unk0 =  tmp0;
    D_80203FE0[26].unk2 =  tmp1;
    D_80203FE0[26].unk4 =  tmp2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBC90_6CD340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBFA0_6CD650.s")
// used by desert_fox
// void func_802BBFA0_6CD650(u16 arg0) {
//     s16 var_a0;
//     s16 temp_a2;
//     struct106 *temp_v0;
//     u16 tmp;
//     s16 tmp0, tmp1, tmp2;
//
//     temp_v0 = &D_803D5528->unk3C8;
//
//     if ((D_803F2D10.unk0 == 0) && (temp_v0->unk6 != 0)) {
//         temp_v0->unk8++;
//     }
//     if (D_803F2D10.unk0 == 0) {
//         temp_v0->unk0 = (temp_v0->unk0 + 3) % 256;
//     }
//     tmp = temp_v0->unk0;
//
//     var_a0 = D_803D552C->unk302 - temp_v0->unk4;
//     while (var_a0 < -128) {
//         var_a0 += 256;
//     }
//     while (var_a0 >= 128) {
//         var_a0 -= 256;
//     }
//
//     if (ABS(var_a0) < 32) {
//         if (var_a0 < 0) {
//             temp_v0->unk4 -= 2;
//             if (temp_v0->unk4 < 0) {
//                 temp_v0->unk4 += 256;
//             }
//             var_a0 += 2;
//         }
//         if (var_a0 > 0) {
//             temp_v0->unk4 += 2;
//             if (temp_v0->unk4 >= 256) {
//                 temp_v0->unk4 -= 256;
//             }
//             var_a0 -= 2;
//         }
//     } else {
//         if (var_a0 < 0) {
//             temp_v0->unk4 -= 6;
//             if (temp_v0->unk4 < 0) {
//                 temp_v0->unk4 += 256;
//             }
//             var_a0 += 6;
//         }
//         if (var_a0 > 0) {
//             temp_v0->unk4 += 6;
//             if (temp_v0->unk4 >= 256) {
//                 temp_v0->unk4 -= 256;
//             }
//             var_a0 -= 6;
//         }
//     }
//
//     tmp0 = D_80203FE0[2].unk0;
//     tmp1 = D_80203FE0[2].unk4;
//     tmp2 = D_80203FE0[2].unk2;
//
//     // temp_a2 = &D_80152350 + ((s16) (var_a0 + ((s16) *(&D_80152C78 + (((u16) temp_v0->unk0 & 0xFF) * 2)) >> 0xB)) * 2);
//
//     tmp0 += (arg0 * D_80152350.unk2D0[(s16)(var_a0 + (D_80152C78[tmp & 0xFF] >> 11))]) / 256;
//     tmp2 -= (arg0 * D_80152350.unk384[(s16)(var_a0 + (D_80152C78[tmp & 0xFF] >> 11))]) / 256;
//     D_80203FE0[26].unk4 = tmp1;
//
//     D_80203FE0[26].unk0 = tmp0;
//     D_80203FE0[26].unk2 = tmp2;
// }

// used by vulture, parrot, seagull
// just regalloc...
#ifdef NON_MATCHING
void func_802BC1F4_6CD8A4(u16 arg0) {
    s16 var_v1;
    u16 temp_v1;
    struct106 *temp_v0;
    u16 tmp;

    temp_v0 = &D_803D5528->unk3C8;
    if ((D_803F2D10.unk0 == 0) && (temp_v0->unk6 != 0)) {
        temp_v0->unk8++;
    }
    if (temp_v0->unk6 == 9) {
        temp_v1 = temp_v0->unk8;
        if (temp_v1 < 5) {
            var_v1 = ((temp_v1 * 40) / 4);
            var_v1 = -var_v1;
        } else if (temp_v1 < 21) {
            var_v1 = (((temp_v1 * 40) - 160) / 16) - 40;
        } else if (temp_v1 < 37) {
            var_v1 = (((temp_v1 * 20) - 400) / 8);
        } else {
            var_v1 = 20;
            temp_v0->unk6 = 0;
        }
    } else {
        var_v1 = 20;
        temp_v0->unk6 = 0;
    }
    D_80203FE0[26].unk2 = -((arg0 * D_80152350.unk384[var_v1]) >> 8) + D_80203FE0[2].unk2;
    D_80203FE0[26].unk0 = D_80203FE0[2].unk0;
    D_80203FE0[26].unk4 = ((arg0 * D_80152350.unk2D0[var_v1]) >> 8) + D_80203FE0[2].unk4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC1F4_6CD8A4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC350_6CDA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC628_6CDCD8.s")

#ifdef NON_MATCHING
// 180 away
void func_802BC900_6CDFB0(struct087 *arg0, u16 arg1, u16 arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    s32 temp_t0;
    s32 temp_t1;
    u16 temp_t6_2;
    s32 temp_t7;
    u16 temp_t7_2;
    u16 temp_t8;
    u16 temp_t9;

    temp_t0 = arg2 / 4;
    if (arg1 < temp_t0) {
        *arg3 = arg0->unk0;
        *arg4 = arg0->unk2;
        *arg5 = arg0->unk4;
    }
    if (arg1 >= temp_t0) {
        temp_t1 = arg2 / 2;
        if (arg1 < temp_t1) {
            temp_t6_2 = (arg1 - temp_t0);
            temp_t7_2 = (temp_t1 - temp_t0);
            *arg3 = ((arg0->unk6 * temp_t6_2) + (arg0->unk0 * (temp_t7_2 - temp_t6_2))) / temp_t7_2;
            *arg4 = ((arg0->unk8 * temp_t6_2) + (arg0->unk2 * (temp_t7_2 - temp_t6_2))) / temp_t7_2;
            *arg5 = ((arg0->unkA * temp_t6_2) + (arg0->unk4 * (temp_t7_2 - temp_t6_2))) / temp_t7_2;
        }
    }
    temp_t1 = arg2 / 2;
    if (arg1 >= temp_t1) {
        temp_t7 = (arg2 * 3) / 4;
        if (arg1 < temp_t7) {
            temp_t9 = (arg1 - temp_t1);
            temp_t8 = (temp_t7 - temp_t1);
            *arg3 = ((arg0->unkC * temp_t9) + (arg0->unk6 * (temp_t8 - temp_t9))) / temp_t8;
            *arg4 = ((arg0->unkE * temp_t9) + (arg0->unk8 * (temp_t8 - temp_t9))) / temp_t8;
            *arg5 = ((arg0->unk10 * temp_t9) + (arg0->unkA * (temp_t8 - temp_t9))) / temp_t8;
        }
    }
    if (arg1 >= ((arg2 * 3) / 4)) {
        *arg3 = arg0->unkC;
        *arg4 = arg0->unkE;
        *arg5 = arg0->unk10;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC900_6CDFB0.s")
#endif

void func_802BCC50_6CE300(s16 arg0, u16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 *arg8, s16 *arg9, s16 *argA) {
    *arg8 = ((arg5 * arg0) + (arg2 * (arg1 - arg0))) / arg1;
    *arg9 = ((arg6 * arg0) + (arg3 * (arg1 - arg0))) / arg1;
    *argA = ((arg7 * arg0) + (arg4 * (arg1 - arg0))) / arg1;
}

void func_802BCDA0_6CE450(struct103 *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    s16 tmp;

    if (D_803D552C->unk300 != 0) {
        tmp = D_803D552C->unk2F2 - D_803D552C->unk2FE;
        if (tmp < 0) {
            tmp += 256;
        }
        if (tmp < D_803D552C->unk300) {
            *arg1 = (((*arg1 * tmp) + (arg0->unkA * (D_803D552C->unk300 - tmp))) / D_803D552C->unk300);
            *arg2 = (((*arg2 * tmp) + (arg0->unkC * (D_803D552C->unk300 - tmp))) / D_803D552C->unk300);
            *arg3 = (((*arg3 * tmp) + ((s16)arg0->unkE * (D_803D552C->unk300 - tmp))) / D_803D552C->unk300);
        } else {
            D_803D552C->unk300 = 0U;
        }
    }
}

void func_802BCF38_6CE5E8(u16 arg0, u16 arg1, struct061 *arg2) {
    s16 temp_v1;

    switch (D_803D5530->unk162 & 0xF) {
    case 1:
    case 6:
        arg2->unk0 = ((func_802B8C50_6CA300(-arg1, arg0) >> 8) << 5) >> 8;
        arg2->unk2 = ((func_802B8C50_6CA300(arg1, arg0) >> 8) << 5) >> 8;
        arg2->unk4 = ((func_802B8C50_6CA300(-arg1, -arg0) >> 8) << 5) >> 8;
        arg2->unk6 = ((func_802B8C50_6CA300(arg1, -arg0) >> 8) << 5) >> 8;

        if (arg0 * 3 < arg2->unk0) {
            arg2->unk0 = arg0 * 3;
        }
        if (arg2->unk0 < arg0 * -3) {
            arg2->unk0 = arg0 * -3;
        }
        if (arg0 * 3 < arg2->unk2) {
            arg2->unk2 = arg0 * 3;
        }
        if (arg2->unk2 < arg0 * -3) {
            arg2->unk2 = arg0 * -3;
        }
        if (arg0 * 3 < arg2->unk4) {
            arg2->unk4 = arg0 * 3;
        }
        if (arg2->unk4 < arg0 * -3) {
            arg2->unk4 = arg0 * -3;
        }
        if (arg0 * 3 < arg2->unk6) {
            arg2->unk6 = arg0 * 3;
        }
        if (arg2->unk6 < arg0 * -3) {
            arg2->unk6 = arg0 * -3;
        }
        break;
    default:
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        arg2->unk0 = 0;
        arg2->unk2 = 0;
        arg2->unk4 = 0;
        arg2->unk6 = 0;

        temp_v1 = func_802B8C50_6CA300(-arg1, arg0) >> 16;
        if (arg2->unk0 < temp_v1) {
            arg2->unk0 = temp_v1 << 5;
        }
        temp_v1 = func_802B8C50_6CA300(arg1, arg0) >> 16;
        if (arg2->unk2 < temp_v1) {
            arg2->unk2 = temp_v1 << 5;
        }
        temp_v1 = func_802B8C50_6CA300(-arg1, -arg0) >> 16;
        if (arg2->unk4 < temp_v1) {
            arg2->unk4 = temp_v1 << 5;
        }
        temp_v1 = func_802B8C50_6CA300(arg1, -arg0) >> 16;
        if (arg2->unk6 < temp_v1) {
            arg2->unk6 = temp_v1 << 5;
        }
        break;
    }
}

void func_802BD21C_6CE8CC(u16 arg0, struct061 *arg1) {
    s16 tmp;

    switch (D_803D5530->unk162 & 0xF) {
    case 1:
    case 6:
        arg1->unk0 = ((func_802B8C50_6CA300(-arg0, 0) >> 8) << 5) >> 8;
        arg1->unk2 = ((func_802B8C50_6CA300(arg0, 0) >> 8) << 5) >> 8;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        arg1->unk0 = 0;
        arg1->unk2 = 0;
        arg1->unk4 = 0;
        arg1->unk6 = 0;

        tmp = func_802B8C50_6CA300(-arg0, 0) >> 16;
        if (arg1->unk0 < tmp) {
            arg1->unk0 = tmp << 5;
        }
        tmp = func_802B8C50_6CA300(arg0, 0) >> 16;
        if (arg1->unk2 < tmp) {
            arg1->unk2 = tmp << 5;
        }
        break;
    default:
        break;
    }
}

void func_802BD358_6CEA08(s16 *arg0) {
    s16 tmp;

    switch (D_803D5530->unk162 & 0xF) {
    case 1:
    case 6:
        *arg0 = ((func_802B8C50_6CA300(0, 0) >> 8) << 5) >> 8;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        *arg0 = 0;
        tmp = func_802B8C50_6CA300(0, 0) >> 16;
        if (*arg0 < tmp) {
            *arg0 = tmp << 5;
        }
        break;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BD40C_6CEABC.s")
// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BE1A0_6CF850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BEAB0_6D0160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BF3C0_6D0A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BFF84_6D1634.s")
// void func_802BFF84_6D1634(struct103 *arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, s16 arg7[8][3], s16 arg8[8][3], s8 argA) {
//     s16 var_v0;
//     u16 temp_t1;
//     u16 temp_t7;
//     s16 tmp;
//     s16 tmp1, tmp2, tmp3;
//
//     if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
//         arg0->unk12++;
//     }
//
//     switch (argA) {
//     case 1:
//         temp_t1 = (arg4 / 32);
//         temp_t7 = (arg4 - (temp_t1 << 5));
//         var_v0 = (((32 - temp_t7) * arg7[temp_t1][0]) + (arg7[(temp_t1 + 1) % 8][0] * temp_t7)) / 32;
//         break;
//     case 2:
//         temp_t1 = (arg4 / 32);
//         temp_t7 = (arg4 - (temp_t1 << 5));
//         var_v0 = (((32 - temp_t7) * arg8[temp_t1][0]) + (arg8[(temp_t1 + 1) % 8][0] * temp_t7)) / 32;
//         break;
//     default:
//         var_v0 = 0;
//         break;
//     }
//
//     switch (arg0->unk10) {                          /* switch 1 */
//     case 1:                                         /* switch 1 */
//     case 5:                                         /* switch 1 */
//     case 6:                                         /* switch 1 */
//     case 7:                                         /* switch 1 */
//     case 8:                                         /* switch 1 */
//     case 9:                                         /* switch 1 */
//     case 10:                                        /* switch 1 */
//     case 11:                                        /* switch 1 */
//         break;
//     case 2:                                         /* switch 1 */
//     case 3:                                         /* switch 1 */
//     case 4:                                         /* switch 1 */
//         var_v0 = 0;
//         break;
//     }
//     arg0->unk4 = var_v0;
//
//     switch (D_803D5530->state) {                    /* switch 2; irregular */
//     case 0x1:                                       /* switch 2 */
//     case 0x3:                                       /* switch 2 */
//     case 0x4:                                       /* switch 2 */
//     case 0x6:                                       /* switch 2 */
//     case 0xB6:                                      /* switch 2 */
//     case 0xB7:                                      /* switch 2 */
//     case 0xB9:                                      /* switch 2 */
//         tmp = ((256 - D_80152350.unk384[(s16) ((arg4 * 360) / 256)]) * arg6) / 512;
//         D_80203FE0[arg2].unk4 = (D_80203FE0[arg2].unk4 + arg6) - tmp;
//         break;
//     case 0x5:                                       /* switch 2 */
//     case 0x65:                                      /* switch 2 */
//     case 0x68:                                      /* switch 2 */
//     case 0x69:                                      /* switch 2 */
//     case 0xB8:                                      /* switch 2 */
//         break;
//     case 0x2:                                       /* switch 2 */
//         break;
//     default:                                        /* switch 2 */
//         break;
//     }
//
//     // close but no cigar...
//
//     tmp1 = D_80203FE0[arg2].unk0;
//     tmp2 = D_80203FE0[arg2].unk2 - (arg5 * D_80152350.unk2D0[var_v0]) / 256;
//     tmp3 = D_80203FE0[arg2].unk4 - (arg5 * D_80152350.unk384[var_v0]) / 256;
//
//     D_80203FE0[arg3].unk0 = tmp1;
//     D_80203FE0[arg3].unk2 = tmp2;
//     D_80203FE0[arg3].unk4 = tmp3;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C0364_6D1A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C13E4_6D2A94.s")
// similar issues to func_802BFF84_6D1634
// void func_802C13E4_6D2A94(struct103 *arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, s16 arg7[8][3], s16 arg8[8][3], s8 argA) {
//     s16 temp_a1;
//     s16 var_a1;
//     u16 temp_t1;
//     u16 temp_t8;
//     s16 var_a0;
//     s16 tmp;
//     s16 tmp1;
//
//     if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
//         arg0->unk12++;
//     }
//
//     switch (argA) {
//     case 1:
//         temp_t1 = arg4 / 32;
//         temp_t8 = arg4 - (temp_t1 << 5);
//         var_a0 = (((32 - temp_t8) * arg7[temp_t1][0]) + (arg7[(temp_t1 + 1) % 8][0] * temp_t8)) / 32;
//         break;
//     case 2:
//         temp_t1 = arg4 / 32;
//         temp_t8 = arg4 - (temp_t1 << 5);
//         var_a0 = (((32 - temp_t8) * arg8[temp_t1][0]) + (arg8[(temp_t1 + 1) % 8][0] * temp_t8)) / 32;
//         break;
//     default:
//         var_a0 = 0;
//         break;
//     }
//
//     switch (arg0->unk10) {                          /* switch 1 */
//     case 1:                                         /* switch 1 */
//     case 5:                                         /* switch 1 */
//     case 6:                                         /* switch 1 */
//     case 7:                                         /* switch 1 */
//     case 8:                                         /* switch 1 */
//     case 9:                                         /* switch 1 */
//     case 10:                                        /* switch 1 */
//     case 11:                                        /* switch 1 */
//         var_a0 = var_a0;
//         break;
//     case 2:                                         /* switch 1 */
//     case 3:                                         /* switch 1 */
//     case 4:                                         /* switch 1 */
//         var_a0 = 0;
//         break;
//     }
//     arg0->unk4 = var_a0;
//
//     switch (D_803D5530->state) {                        /* switch 2; irregular */
//     case 0x1:                                       /* switch 2 */
//     case 0x3:                                       /* switch 2 */
//     case 0x4:                                       /* switch 2 */
//     case 0x6:                                       /* switch 2 */
//     case 0xB6:                                      /* switch 2 */
//     case 0xB7:                                      /* switch 2 */
//     case 0xB9:                                      /* switch 2 */
//         tmp = ((256 - D_80152350.unk384[(s16) ((arg4 * 360) / 256)]) * arg6) / 512;
//         D_80203FE0[arg2].unk4 = (D_80203FE0[arg2].unk4 + arg6) - tmp;
//         break;
//     case 0x5:                                       /* switch 2 */
//     case 0x65:                                      /* switch 2 */
//     case 0x68:                                      /* switch 2 */
//     case 0x69:                                      /* switch 2 */
//     case 0xB8:                                      /* switch 2 */
//         break;
//     case 0x2:                                       /* switch 2 */
//         break;
//     default:                                        /* switch 2 */
//         break;
//     }
//
//     // all goes wrong from here ...
//
//     var_a1 = D_80203FE0[arg2].unk0 - ((arg5 * D_80152350.unk2D0[var_a0]) >> 8);
//     if ((arg2 == 3) || (arg2 == 5) || (arg2 == 8) || (arg2 == 14)) {
//
//     } else {
//         var_a1 = D_80203FE0[arg2].unk0 + ((arg5 * D_80152350.unk2D0[var_a0]) >> 8);
//     }
//
//     D_80203FE0[arg3].unk0 = var_a1;
//     D_80203FE0[arg3].unk2 = D_80203FE0[arg2].unk2;
//     D_80203FE0[arg3].unk4 = D_80203FE0[arg2].unk4 - ((arg5 * D_80152350.unk384[var_a0]) >> 8);
//
//     D_80203FE0[arg3].unk2 -= (((D_80152C78[arg4 & 0xFF] >> 7) >> 4) * arg5) >> 8;
//     D_80203FE0[arg2].unk2 -= (((D_80152C78[arg4 & 0xFF] >> 7) >> 4) * arg5) >> 8;
// }

void func_802C1830_6D2EE0(u16 arg0, struct061 *arg1) {
    func_802C19CC_6D307C(&D_803D5528->unk370, arg1->unk0, 3, 7, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk384, arg1->unk2, 4, 10, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk398, arg1->unk4, 5, 13, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk3AC, arg1->unk6, 6, 16, 0, arg0);
}

void func_802C18FC_6D2FAC(u16 arg0, u16 arg1, struct061 *arg2) {
    func_802C19CC_6D307C(&D_803D5528->unk370, arg2->unk0, 3, 7, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk384, arg2->unk2, 4, 10, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk398, arg2->unk4, 5, 13, 0, arg1);
    func_802C19CC_6D307C(&D_803D5528->unk3AC, arg2->unk6, 6, 16, 0, arg1);
}

void func_802C19CC_6D307C(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, s32 arg4, u16 arg5) {
    s16 tmp0 = D_80203FE0[arg2].unk0;
    s16 tmp2 = D_80203FE0[arg2].unk2;

    D_80203FE0[arg3].unk0 = tmp0;
    D_80203FE0[arg3].unk2 = tmp2;
    D_80203FE0[arg3].unk4 = arg1 + arg5;

    D_80203FE0[arg3+1].unk0 = tmp0;
    D_80203FE0[arg3+1].unk2 = tmp2;
    D_80203FE0[arg3+1].unk4 = arg1;

    D_80203FE0[arg3+2].unk0 = tmp0;
    D_80203FE0[arg3+2].unk2 = tmp2;
    D_80203FE0[arg3+2].unk4 = arg1;
}

void func_802C1A44_6D30F4(u16 arg0, u16 arg1, s32 arg2) {
    D_80203FE0[14].unk2 = 0;
    D_80203FE0[14].unk0 = D_80203FE0[14].unk2;
    D_80203FE0[14].unk4 = D_80203FE0[2].unk4 - arg0;

    D_80203FE0[15].unk0 = 0;
    D_80203FE0[15].unk2 = D_80203FE0[14].unk2 + arg1;
    D_80203FE0[15].unk4 = D_80203FE0[14].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C1A88_6D3138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C23F8_6D3AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C287C_6D3F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C2D98_6D4448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3188_6D4838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C353C_6D4BEC.s")
// void func_802C353C_6D4BEC(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5, struct061 *arg6) {
//     u16 phi_t2;
//     u16 phi_t3;
//     u16 temp_v1;
//     s8  phi_t1;
//
//     temp_v1 = D_803D552C->unk2F2;
//
//     switch (D_803D5530->state) {                        /* implicit */
//     case 0x3:
//     case 0x8E:
//     case 0xB6:
//         phi_t1 = 1;
//         phi_t2 = D_803D552C->unk2F6 % 256;
//         phi_t3 = (D_803D552C->unk2F6 + 0x80) % 256;
//         if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
//             if ((phi_t2 > 0x80) && ((D_803D552C->unk2F8 % 256) <= 0x80)) {
//                 D_803F2F00 = 1;
//                 D_803D553A = 5;
//                 func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
//             } else if ((phi_t3 > 0x80) && (((D_803D552C->unk2F8 + 0x80) % 256) <= 0x80)) {
//                 D_803F2F00 = 2;
//                 D_803D553A = 5;
//                 func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
//             }
//         }
//         break;
//     case 0x6:
//     case 0x90:
//     case 0xB9:
//         phi_t1 = 1;
//         phi_t2 = 0x100 - (D_803D552C->unk2F6 % 256);
//         phi_t3 = 0x100 - ((D_803D552C->unk2F6 + 0x80) % 256);
//         if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
//             if ((phi_t2 < 0x80) && ((0x100 - (D_803D552C->unk2F8 % 256)) >= 0x80)) {
//                 D_803F2F00 = 1;
//                 D_803D553A = 5;
//                 func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
//             } else
//             if ((phi_t3 < 0xE1) && ((0x100 - ((D_803D552C->unk2F8 + 0x80) % 256)) >= 0xE1)) {
//                 D_803F2F00 = 2;
//                 D_803D553A = 5;
//                 func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
//             }
//         }
//         break;
//     case 0x4:
//     case 0x8F:
//     case 0xB7:
//         phi_t1 = 2;
//         phi_t2 = D_803D552C->unk2F6 % 256;
//         phi_t3 = (D_803D552C->unk2F6 + 0x80) % 256;
//         if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
//             if ((phi_t2 > 0x80) && ((D_803D552C->unk2F8 % 256) <= 0x80)) {
//                 D_803F2F00 = 1;
//                 D_803D553A = 5;
//                 func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
//             } else // ?
//             if ((phi_t3 > 0x80) && (((D_803D552C->unk2F8 + 0x80) % 256) <= 0x80)) {
//                 D_803F2F00 = 2;
//                 D_803D553A = 5;
//                 func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
//             }
//         }
//         break;
//     default:
//         phi_t1 = 0;
//         phi_t3 = temp_v1;
//         phi_t2 = temp_v1;
//         break;
//     }
//
//     if ((D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2))) {
//         if ((D_803D5530->unk162 == 4) || (D_803D5530->unk162 == 5) ||
//             (D_803D5530->unk162 == 6) || (D_803D5530->unk162 == 7)) {
//             phi_t1 = 2;
//             phi_t2 = (D_803D552C->unk2F6 * 16) & 0xFF;
//             phi_t3 = ((D_803D552C->unk2F6 * 16) + 0x80) & 0xFF;
//         }
//     } else {
//         if ((D_803D5530->unk162 == 4) || (D_803D5530->unk162 == 5) ||
//             (D_803D5530->unk162 == 7)) {
//             phi_t1 = 2;
//             switch (D_803D5530->state) {
//             default:
//                 phi_t2 = (D_803D552C->unk2F6 * 2) & 0xFF;
//                 phi_t3 = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
//                 break;
//             case 0x8E:
//                 phi_t2 = D_803D552C->unk2F6 & 0xFF;
//                 phi_t3 = (D_803D552C->unk2F6 + 0x80) & 0xFF;
//                 break;
//             case 0x90:
//                 // help
//                 phi_t2 -= (256 - (D_803D552C->unk2F6       )) & 0xFFFF;
//                 phi_t3 -= (256 - (D_803D552C->unk2F6 + 0x80)) & 0xFFFF;
//                 break;
//             case 0x8F:
//                 phi_t2 = (D_803D552C->unk2F6 * 2) & 0xFF;
//                 phi_t3 = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
//                 break;
//             }
//         }
//     }
//
//     func_802BE1A0_6CF850(&D_803D5528->unk398, arg6->unk0, 5, 13, phi_t2, arg0, arg1, 0, arg2, arg3, arg4, arg5, phi_t1);
//     func_802BE1A0_6CF850(&D_803D5528->unk3AC, arg6->unk2, 6, 16, phi_t3, arg0, arg1, 0, arg2, arg3, arg4, arg5, phi_t1);
// }

void func_802C3C64_6D5314(s16 arg0, s16 arg1, s16 arg2) {
    u16 tmp1;
    u16 tmp2;

    s32 fixme;

    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0xB6:
    case 0xB9:
        tmp1 = D_803D552C->unk2F6 % 256;
        tmp2 = D_803D552C->unk2F8 % 256;
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2) && (tmp1 >= 0xB) && (tmp2 < 0xB) && (D_803D5530->unk4A == 0)) {
            D_803F2F00 = 1;
            D_803D553A = 5;
            func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
        }
        break;
    case 0x4:
    case 0xB7:
        tmp1 = D_803D552C->unk2F6 % 256;
        tmp2 = D_803D552C->unk2F8 % 256;
        if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2) &&
            (tmp1 >= 0xB) &&
            (tmp2 < 0xB) && (D_803D5530->unk4A == 0)) {
            D_803F2F00 = 1;
            D_803D553A = 6;
            func_8032C5A8_73DC58(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, D_803D5530->unk160);
        }
        break;
    case 0x8E:
    case 0x90:
        if (!(fixme = D_803D552C->unk2F2 & 7)) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
        }
        break;
    case 0x8F:
        if (!(fixme = D_803D552C->unk2F2 & 7)) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
        }
        break;
    }
    func_802C3F58_6D5608(&D_803D5528->unk398, 5, 13, 14,  arg0, arg1, arg2);
    func_802C3F58_6D5608(&D_803D5528->unk3AC, 6, 16, 17, -arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3F58_6D5608.s")

void func_802C4448_6D5AF8(s16 arg0) {
    if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
        }
    }
    D_80203FE0[5].unk0 = D_80203FE0[0].unk0;
    D_80203FE0[5].unk2 = D_80203FE0[0].unk2;
    D_80203FE0[5].unk4 = D_80203FE0[0].unk4 - arg0;
}

// ordering of assignments is wrong
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C44E8_6D5B98.s")
// void func_802C44E8_6D5B98(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
//     s16 sp42;
//     s16 sp40;
//     s16 sp3E;
//     s16 sp3C;
//
//     s16 temp_t9;
//     s16 temp_v0;
//     s16 temp_t7;
//     s32 phi_v1;
//
//     switch (D_803D5530->state) {
//     case 142:
//     case 144:
//         temp_v0 = (D_803D5540 << 4) & 0xFF;
//         temp_t9 = ((D_803D5540 << 4) + 0x80) & 0xFF;
//         temp_t7 = (((D_80152C78[temp_v0 & 0xFF]) >> 7) * arg3) >> 8;
//         sp42 = temp_t7;
//         sp40 = -temp_t7;
//         if ((temp_v0 > 64) && (temp_v0 < 192)) {
//             sp3E = ((((D_80152C78[((temp_v0 * 2) + 64) & 0xFF] >> 7) + 0x100) * arg3) >> 0xA);
//         } else {
//             sp3E = 0;
//         }
//         if ((temp_t9 > 64) && (temp_t9 < 192)) {
//             sp3C = ((((D_80152C78[((temp_t9 * 2) + 64) & 0xFF] >> 7) + 0x100) * arg3) >> 0xA);
//         } else {
//             sp3C = 0;
//         }
//         if ((D_803D5540 & 7) == 0) {
//             func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
//         }
//         break;
//     case 143:
//         temp_v0 = (D_803D5540 << 5) & 0xFF;
//         temp_t9 = ((D_803D5540 << 5) + 0x80) & 0xFF;
//         temp_t7 = (((D_80152C78[temp_v0 & 0xFF]) >> 7) * arg3) >> 8;
//         sp42 = temp_t7;
//         sp40 = -temp_t7;
//         if ((temp_v0 > 64) && (temp_v0 < 192)) {
//             sp3E = (((D_80152C78[((temp_v0 * 2) + 64) & 0xFF] >> 7) + 256) * arg3) >> 10;
//         } else {
//             sp3E = 0;
//         }
//         if ((temp_t9 > 64) && (temp_t9 < 192)) {
//             sp3C = (((D_80152C78[((temp_t9 * 2) + 64) & 0xFF] >> 7) + 256) * arg3) >> 10;
//         } else {
//             sp3C = 0;
//         }
//         if ((D_803D5540 & 7) == 0) {
//             func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
//         }
//         break;
//     default:
//         sp3C = 0;
//         sp3E = 0;
//         sp40 = 0;
//         sp42 = 0;
//         break;
//     }
//
//     D_80203FE0[5].unk0 = D_80203FE0[0].unk0;
//     D_80203FE0[5].unk2 = D_80203FE0[0].unk2 + sp42;
//     D_80203FE0[5].unk4 = D_80203FE0[0].unk4 - arg0;
//
//     D_80203FE0[27].unk0 = D_80203FE0[0].unk0;
//     D_80203FE0[27].unk2 = D_80203FE0[0].unk2 + sp40;
//     D_80203FE0[27].unk4 = D_80203FE0[0].unk4 - arg0;
//
//     D_80203FE0[3].unk0 = D_80203FE0[5].unk0 - arg1;
//     D_80203FE0[3].unk2 = D_80203FE0[5].unk2;
//     D_80203FE0[3].unk4 = D_80203FE0[5].unk4;
//
//     D_80203FE0[4].unk0 = D_80203FE0[27].unk0 + arg1;
//     D_80203FE0[4].unk2 = D_80203FE0[27].unk2;
//     D_80203FE0[4].unk4 = D_80203FE0[27].unk4;
//
//     D_80203FE0[13].unk0 = D_80203FE0[3].unk0;
//     D_80203FE0[13].unk2 = D_80203FE0[3].unk2 - arg2;
//     D_80203FE0[13].unk4 = D_80203FE0[3].unk4;
//
//     D_80203FE0[14].unk4 = D_80203FE0[4].unk4;
//     D_80203FE0[14].unk2 = D_80203FE0[4].unk2 - arg2;
//     D_80203FE0[14].unk0 = D_80203FE0[4].unk0;
//
//     D_80203FE0[8].unk2 = (D_80203FE0[3].unk2 + arg3) - sp3E;
//     D_80203FE0[7].unk0 = (D_80203FE0[3].unk0 - ((arg3 * 0xB) >> 4));
//     D_80203FE0[9].unk0 = D_80203FE0[3].unk0 + ((arg3 * 0xB) >> 4);
//
//     D_80203FE0[11].unk4 = D_80203FE0[4].unk4 - sp3C;
//
//     D_80203FE0[8].unk0 = D_80203FE0[3].unk0;
//     D_80203FE0[10].unk0 = D_80203FE0[4].unk0 - ((arg3 * 0xB) >> 4);
//     D_80203FE0[11].unk2 = (D_80203FE0[4].unk2 + arg3) - sp3E;
//
//     D_80203FE0[7].unk2 = (D_80203FE0[3].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;
//     D_80203FE0[7].unk4 = D_80203FE0[3].unk4 - sp3E;
//     D_80203FE0[8].unk4 = D_80203FE0[3].unk4 - sp3E;
//
//     D_80203FE0[9].unk2 = (D_80203FE0[3].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;
//     D_80203FE0[9].unk4 = D_80203FE0[3].unk4 - sp3E;
//
//     D_80203FE0[10].unk2 = (D_80203FE0[4].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;
//     D_80203FE0[11].unk0 = D_80203FE0[4].unk0;
//     D_80203FE0[10].unk4 = D_80203FE0[4].unk4 - sp3C;
//
//     D_80203FE0[12].unk0 = D_80203FE0[4].unk0 + ((arg3 * 0xB) >> 4);
//     D_80203FE0[12].unk2 = (D_80203FE0[4].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;
//     D_80203FE0[12].unk4 = D_80203FE0[4].unk4 - sp3C;
//
//     if (D_803D5530->state == 101) {
//         if ((D_803D5524->unk9C != SEAGULL2) && (D_803D5524->unk9C != VULTURE)) {
//             temp_t9 = D_803D5540 & 0x3F;
//             if (temp_t9 < 20) {
//                 phi_v1 = (temp_t9 - 10) < 0 ? (10 - temp_t9) : (temp_t9 - 10);
//                 D_80203FE0[7].unk4 += (arg3 * (10 - phi_v1)) >> 4;
//             }
//             if ((temp_t9 < 30) && (temp_t9 > 10)) {
//                 phi_v1 = (temp_t9 - 20) < 0 ? (20 - temp_t9) : (temp_t9 - 20);
//                 D_80203FE0[8].unk4 += (arg3 * (10 - phi_v1)) >> 4;
//             }
//             if ((temp_t9 < 40) && (temp_t9 > 20)) {
//                 phi_v1 = (temp_t9 - 30) < 0 ? (30 - temp_t9) : (temp_t9 - 30);
//                 D_80203FE0[9].unk4 += (arg3 * (10 - phi_v1)) >> 4;
//             }
//         }
//     }
// }
