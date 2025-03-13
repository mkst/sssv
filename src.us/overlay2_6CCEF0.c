#include <ultra64.h>
#include "common.h"


void func_802BB840_6CCEF0(u16 arg0) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;

    if (1) {};

    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    tmp1 -= arg0;

    D_80203FE0[26].unk0 = tmp0;
    D_80203FE0[26].unk2 = tmp1;
    D_80203FE0[26].unk4 = tmp2;
}

void func_802BB870_6CCF20(u16 arg0) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;
    s16 div;

    if (1) { };

    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    tmp1 -= arg0;

    div = D_80203FE0[0].unk2 - D_80203FE0[2].unk2;
    if (div == 0){
        div = 1;
    }

    tmp2 += (((D_80203FE0[2].unk4 - D_80203FE0[0].unk4) / 2) * arg0) / div;
    D_80203FE0[26].unk0 = tmp0;
    D_80203FE0[26].unk2 = tmp1;
    D_80203FE0[26].unk4 = tmp2;
}

// only used by husky
void func_802BB938_6CCFE8(u16 arg0) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;
    s16 div;

    if (1) {};

    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    tmp1 -= arg0;

    div = D_80203FE0[0].unk2 - D_80203FE0[2].unk2;
    if (div == 0) {
        div = 1;
    }

    tmp2 += ((((D_80203FE0[2].unk4 - D_80203FE0[0].unk4) / 2) * arg0) / div);
    D_80203FE0[26].unk0 = tmp0;
    D_80203FE0[26].unk2 = (tmp2 - D_80203FE0[2].unk4) + tmp1;
    D_80203FE0[26].unk4 = (D_80203FE0[2].unk2 - tmp1) + tmp2;
}

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

    phi_a1_2 = D_803D552C->heading - tmp->unk4;
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

// only used by fox
void func_802BBC90_6CD340(u16 arg0) {
    s16 temp_a1;
    s16 var_a3;
    s32 var_a2;
    s16 idx;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    struct106 *temp_v0;
    u16 tmp;

    temp_v0 = &D_803D5528->unk3C8;

    if ((D_803F2D10.unk0 == 0) && (temp_v0->unk6 != 0)) {
        temp_v0->unk8++;
    }
    if (D_803F2D10.unk0 == 0) {
        temp_v0->unk0 = (temp_v0->unk0 + 3) % 256;
    }
    tmp = temp_v0->unk0;

    temp_a1 = D_80203FE0[1].unk2 - D_80203FE0[2].unk2;
    if (temp_a1 == 0) {
        var_a2 = 0;
    } else {
        var_a2 = ((D_80203FE0[1].unk4 - D_80203FE0[2].unk4) << 0xA) / temp_a1;
    }

    var_a3 = D_803D552C->heading - temp_v0->unk4;
    while (var_a3 < -0x80) {
        var_a3 += 0x100;
    }
    while (var_a3 >= 0x80) {
        var_a3 -= 0x100;
    }

    if (ABS(var_a3) < 32) {
        if (var_a3 < 0) {
            temp_v0->unk4 -= 2;
            if (temp_v0->unk4 < 0) {
                temp_v0->unk4 += 256;
            }
            var_a3 += 2;
        }
        if (var_a3 > 0) {
            temp_v0->unk4 += 2;
            if (temp_v0->unk4 >= 256) {
                temp_v0->unk4 -= 256;
            }
            var_a3 -= 2;
        }
    } else {
        if (var_a3 < 0) {
            temp_v0->unk4 -= 6;
            if (temp_v0->unk4 < 0) {
                temp_v0->unk4 += 256;
            }
            var_a3 += 6;
            if (var_a3 < -63) {
                var_a3 = -63;
            }
        }
        if (var_a3 > 0) {
            temp_v0->unk4 += 6;
            if (temp_v0->unk4 >= 256) {
                temp_v0->unk4 -= 256;
            }
            var_a3 -= 6;
            if (var_a3 > 0x3F) {
                var_a3 = 0x3F;
            }
        }
    }

    var_a3 += SIN(tmp) >> 11;

    var_a2 = var_a2 / 3;

    if (1) {};

    tmp1 = D_80203FE0[2].unk0;
    tmp2 = D_80203FE0[2].unk2;
    tmp3 = D_80203FE0[2].unk4;

    tmp1 += (D_80152350.unk2D0[var_a3] * arg0) / 256;
    tmp3 -= (var_a2 * arg0) / 1024;
    tmp2 -= (arg0 * D_80152350.unk384[var_a3]) / 256;

    D_80203FE0[26].unk0 = tmp1;
    D_80203FE0[26].unk2 = tmp2;
    D_80203FE0[26].unk4 = tmp3;
}

// used by desert_fox
void func_802BBFA0_6CD650(u16 arg0) {
    s16 var_a0;
    s16 temp_a2;
    struct106 *temp_v0;
    u16 tmp;
    s16 tmp0, tmp1, tmp2;

    temp_v0 = &D_803D5528->unk3C8;

    if ((D_803F2D10.unk0 == 0) && (temp_v0->unk6 != 0)) {
        temp_v0->unk8++;
    }
    if (D_803F2D10.unk0 == 0) {
        temp_v0->unk0 = (temp_v0->unk0 + 3) % 256;
    }
    tmp = temp_v0->unk0;

    var_a0 = D_803D552C->heading - temp_v0->unk4;
    while (var_a0 < -128) {
        var_a0 += 256;
    }
    while (var_a0 >= 128) {
        var_a0 -= 256;
    }

    if (ABS(var_a0) < 32) {
        if (var_a0 < 0) {
            temp_v0->unk4 -= 2;
            if (temp_v0->unk4 < 0) {
                temp_v0->unk4 += 256;
            }
            var_a0 += 2;
        }
        if (var_a0 > 0) {
            temp_v0->unk4 += 2;
            if (temp_v0->unk4 >= 256) {
                temp_v0->unk4 -= 256;
            }
            var_a0 -= 2;
        }
    } else {
        if (var_a0 < 0) {
            temp_v0->unk4 -= 6;
            if (temp_v0->unk4 < 0) {
                temp_v0->unk4 += 256;
            }
            var_a0 += 6;
        }
        if (var_a0 > 0) {
            temp_v0->unk4 += 6;
            if (temp_v0->unk4 >= 256) {
                temp_v0->unk4 -= 256;
            }
            var_a0 -= 6;
        }
    }

    var_a0 += SIN(tmp) >> 11;

    if (1) {};

    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    tmp0 += (D_80152350.unk2D0[var_a0] * arg0) / 256;
    tmp1 -= (arg0 * D_80152350.unk384[var_a0]) / 256;

    D_80203FE0[26].unk0 = tmp0;
    D_80203FE0[26].unk2 = tmp1;
    D_80203FE0[26].unk4 = tmp2;
}

// used by vulture, parrot, seagull
void func_802BC1F4_6CD8A4(u16 arg0) {
    s16 var_v1;
    u16 temp_v1;
    struct106 *temp_v0;
    u16 tmp;
    s16 tmp0, tmp1, tmp2;

    temp_v0 = &D_803D5528->unk3C8;
    if ((D_803F2D10.unk0 == 0) && (temp_v0->unk6 != 0)) {
        temp_v0->unk8++;
    }

    switch (temp_v0->unk6) {
    case 9:
        temp_v1 = temp_v0->unk8;
        if (temp_v1 < 5) {
            var_v1 = -((temp_v1 * 40) / 4);
        } else if (temp_v1 < 21) {
            var_v1 = (((temp_v1 * 40) - 160) / 16) - 40;
        } else if (temp_v1 < 37) {
            var_v1 = (((temp_v1 * 20) - 400) / 8);
        } else {
            var_v1 = 20;
            temp_v0->unk6 = 0;
        }
        break;
    default:
        var_v1 = 20;
        temp_v0->unk6 = 0;
        break;
    }

    tmp0 = D_80203FE0[2].unk0;
    tmp1 = D_80203FE0[2].unk2;
    tmp2 = D_80203FE0[2].unk4;

    tmp1 -= (arg0 * D_80152350.unk384[var_v1]) >> 8;
    tmp2 += (arg0 * D_80152350.unk2D0[var_v1]) >> 8;

    D_80203FE0[26].unk0 = tmp0;
    D_80203FE0[26].unk2 = tmp1;
    D_80203FE0[26].unk4 = tmp2;
}

// opposite of func_802BC628_6CDCD8
void func_802BC350_6CDA00(s16 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4) {
    s16 sp3E;
    s16 sp3C;
    s16 pad2;
    s16 sp38;
    s16 sp36;
    s16 sp34;
    s32 pad;

    if (arg4 <= 0) {
        *arg0 = 90;
        *arg1 = -90;
        return;
    }

    sp3E = -(s16)(((arg2 * D_80152350.unk2D0[*arg0]) + (arg3 * D_80152350.unk2D0[*arg1])) / 256);
    sp38 = sqrtf(SQ((f32)sp3E) + SQ((f32)arg4));

    // not abs...
    sp3C = arg2 - arg3;
    if (sp3C < 0) {
        sp3C = -sp3C;
    }

    sp38 = MAX(sp38, sp3C);

    sp36 = func_801283AC((((SQ(arg3) - SQ(arg2) - SQ(sp38))) / ((arg2 * -2 * sp38) / 256)));
    sp34 = func_801283AC((((SQ(arg2) - SQ(arg3) - SQ(sp38))) / ((arg3 * -2 * sp38) / 256)));
    sp38 = -func_8012835C((sp3E * 256) / sp38);

    // fakematch
    *arg0 = sp38 - ((((((sp36 & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF);
    *arg1 = sp38 + sp34;
}

// opposite of func_802BC350_6CDA00
void func_802BC628_6CDCD8(s16 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4) {
  s16 sp3E;
  s16 sp3C;
  s16 pad2;
  s16 sp38;
  s16 sp36;
  s16 sp34;
  s32 pad;

  if (arg4 <= 0) {
      *arg0 = 90;
      *arg1 = -90;
      return;
  }

  sp3E = -(s16)(((arg2 * D_80152350.unk2D0[*arg0]) + (arg3 * D_80152350.unk2D0[*arg1])) / 256);
  sp38 = sqrtf(SQ((f32)sp3E) + SQ((f32)arg4));

  // not abs...
  sp3C = arg2 - arg3;
  if (sp3C < 0) {
      sp3C = -sp3C;
  }

  sp38 = MAX(sp38, sp3C);

  sp36 = func_801283AC((((SQ(arg3) - SQ(arg2) - SQ(sp38))) / ((arg2 * -2 * sp38) / 256)));
  sp34 = func_801283AC((((SQ(arg2) - SQ(arg3) - SQ(sp38))) / ((arg3 * -2 * sp38) / 256)));
  sp38 = -func_8012835C((sp3E * 256) / sp38);

  // fakematch
  *arg0 = sp38 + ((((((sp36 & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF);
  *arg1 = sp38 - sp34;
}

void func_802BC900_6CDFB0(struct077 *arg0, u16 arg1, u16 arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    u16 temp_t8;
    u16 temp_t9;

    if (arg1 < (arg2 / 4)) {
        *arg3 = arg0[0].unk0;
        *arg4 = arg0[0].unk2;
        *arg5 = arg0[0].unk4;
    }
    if (arg1 >= (arg2 / 4)) {
        if (arg1 < (arg2 / 2)) {
            temp_t9 = (arg1 - (arg2 / 4));
            temp_t8 = ((arg2 / 2) - (arg2 / 4));
            *arg3 = ((arg0[0].unk0 * (temp_t8 - temp_t9)) + (arg0[1].unk0 * temp_t9)) / temp_t8;
            *arg4 = ((arg0[0].unk2 * (temp_t8 - temp_t9)) + (arg0[1].unk2 * temp_t9)) / temp_t8;
            *arg5 = ((arg0[0].unk4 * (temp_t8 - temp_t9)) + (arg0[1].unk4 * temp_t9)) / temp_t8;
        }
    }

    if (arg1 >= (arg2 / 2)) {
        if (arg1 < ((arg2 * 3) / 4)) {
            temp_t9 = (arg1 - (arg2 / 2));
            temp_t8 = (((arg2 * 3) / 4) - (arg2 / 2));
            *arg3 = ((arg0[1].unk0 * (temp_t8 - temp_t9)) + (arg0[2].unk0 * temp_t9)) / temp_t8;
            *arg4 = ((arg0[1].unk2 * (temp_t8 - temp_t9)) + (arg0[2].unk2 * temp_t9)) / temp_t8;
            *arg5 = ((arg0[1].unk4 * (temp_t8 - temp_t9)) + (arg0[2].unk4 * temp_t9)) / temp_t8;
        }
    }
    if (arg1 >= ((arg2 * 3) / 4)) {
        *arg3 = arg0[2].unk0;
        *arg4 = arg0[2].unk2;
        *arg5 = arg0[2].unk4;
    }
}

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

void func_802BD40C_6CEABC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 *arg8, s16 *arg9, s16 *argA, s16 argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11, s16 arg12, s16 *arg13, s16 *arg14, s16 *arg15, struct061 *arg16, s16 arg17) {
    u16 sp4E;
    u16 sp4C;
    u16 sp4A;
    u16 sp48;
    u16 sp46;
    s8  sp45;

    sp46 = D_803D552C->unk2F2; // seems to be necessary that this is a temp var
    switch (D_803D5530->state) {
    default:
        sp45 = 0;
        sp48 = sp46;
        sp4A = sp46;
        sp4C = sp46;
        sp4E = sp46;
        break;
    case 0x3:
    case 0xB6:
        sp45 = 1;
        sp4E = (D_803D552C->unk2F6 + arg4) % 256;
        sp4C = (D_803D552C->unk2F6 + arg5) % 256;
        sp4A = (D_803D552C->unk2F6 + argF) % 256;
        sp48 = (D_803D552C->unk2F6 + arg10) % 256;

        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != (u8) 2)) {
            if ((sp4E >= 0xE2) && (((D_803D552C->unk2F8 + arg4) % 256) < 0xE2)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4C >= 0xE2) && (((D_803D552C->unk2F8 + arg5) % 256) < 0xE2)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4A >= 0xE2) && (((D_803D552C->unk2F8 + argF) % 256) < 0xE2)) {
                D_803F2F00 = 3;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp48 >= 0xE2) && (((D_803D552C->unk2F8 + arg10) % 256) < 0xE2)) {
                D_803F2F00 = 4;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x6:
    case 0xB9:
        sp45 = 1;
        sp4E = 0x100 - ((D_803D552C->unk2F6 + arg4) % 256);
        sp4C = 0x100 - ((D_803D552C->unk2F6 + arg5) % 256);
        sp4A = 0x100 - ((D_803D552C->unk2F6 + argF) % 256);
        sp48 = 0x100 - ((D_803D552C->unk2F6 + arg10) % 256);
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((sp4E < 0xE1) && ((0x100 - ((D_803D552C->unk2F8 + arg4) % 256)) >= 0xE1)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4C < 0xE1) && ((0x100 - ((D_803D552C->unk2F8 + arg5) % 256)) >= 0xE1)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4A < 0xE1) && ((0x100 - ((D_803D552C->unk2F8 + argF) % 256)) >= 0xE1)) {
                D_803F2F00 = 3;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp48 < 0xE1) && ((0x100 - ((D_803D552C->unk2F8 + arg10) % 256)) >= 0xE1)) {
                D_803F2F00 = 4;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x4:
    case 0xB7:
        sp45 = 2;
        sp4E = (D_803D552C->unk2F6 + arg6) % 256;
        sp4C = (D_803D552C->unk2F6 + arg7) % 256;
        sp4A = (D_803D552C->unk2F6 + arg11) % 256;
        sp48 = (D_803D552C->unk2F6 + arg12) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((sp4E >= 0xE2) && (((s32) (D_803D552C->unk2F8 + arg6) % 256) < 0xE2)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4C >= 0xE2) && (((D_803D552C->unk2F8 + arg7) % 256) < 0xE2)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4A >= 0xE2) && (((D_803D552C->unk2F8 + arg11) % 256) < 0xE2)) {
                D_803F2F00 = 3;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp48 >= 0xE2) && (((D_803D552C->unk2F8 + arg12) % 256) < 0xE2)) {
                D_803F2F00 = 4;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    }

    if (D_803D5524->waterClass & 0xC00) {
        if ((((D_803D5530->unk162 == 4) || (D_803D5530->unk162 == 5)) || (((u32) D_803D5530->unk162) == 6)) || (D_803D5530->unk162 == 7)) {
            sp45 = 2;
            sp4E = (D_803D552C->unk2F6 * 0x10) & 0xFF;
            sp4C = ((D_803D552C->unk2F6 * 0x10) + 0x80) & 0xFF;
            sp4A = ((D_803D552C->unk2F6 * 0x10) + 0x40) & 0xFF;
            sp48 = ((D_803D552C->unk2F6 * 0x10) + 0xC0) & 0xFF;
            if ((D_803D552C->unk2F6 & 7) == 0) {
                func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
        }
    } else {
        if ((D_803D5530->unk162 == 4) || (D_803D5530->unk162 == 5) || (((u32) D_803D5530->unk162) == 7)) {
            if (0) {};
            sp45 = 2;
            switch (D_803D5530->state) {
            // NOTE: out of order
            case 0x8E:
                sp4E = (D_803D552C->unk2F6 * 16) & 0xFF;
                sp4C = ((D_803D552C->unk2F6 * 16) + 0x80) & 0xFF;
                sp4A = ((D_803D552C->unk2F6 * 16) + 0x40) & 0xFF;
                sp48 = ((D_803D552C->unk2F6 * 16) + 0xC0) & 0xFF;
                if ((D_803D552C->unk2F6 & 7) == 0) {
                    func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
                }
                break;
            case 0x90:
                sp4E = 0x100 - ((D_803D552C->unk2F6 * 8) & 0xFF);
                sp4C = 0x100 - (((D_803D552C->unk2F6 * 8) + 0x80) & 0xFF);
                sp4A = 0x100 - (((D_803D552C->unk2F6 * 8) + 0x40) & 0xFF);
                sp48 = 0x100 - (((D_803D552C->unk2F6 * 8) + 0xC0) & 0xFF);
                if ((D_803D552C->unk2F6 & 0xF) == 0) {
                    func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
                }
                break;
            case 0x8F:
                sp4E = (D_803D552C->unk2F6 * 32) & 0xFF;
                sp4C = ((D_803D552C->unk2F6 * 32) + 0x80) & 0xFF;
                sp4A = ((D_803D552C->unk2F6 * 32) + 0x40) & 0xFF;
                sp48 = ((D_803D552C->unk2F6 * 32) + 0xC0) & 0xFF;
                if ((D_803D552C->unk2F6 & 0x3) == 0) {
                    func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
                }
                break;
            default:
                sp4E = (D_803D552C->unk2F6 * 2) & 0xFF;
                sp4C = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
                sp4A = ((D_803D552C->unk2F6 * 2) + 0x40) & 0xFF;
                sp48 = ((D_803D552C->unk2F6 * 2) + 0xC0) & 0xFF;
                break;
            }
        }
    }
    switch (arg17) {
    case 0:
        func_802BE1A0_6CF850(&D_803D5528->unk370, arg16->unk0, 3, 7, sp4E, arg0, arg1, arg2, arg3, arg8, arg9, argA, sp45);
        func_802BE1A0_6CF850(&D_803D5528->unk384, arg16->unk2, 4, 10, sp4C, arg0, arg1, arg2, arg3, arg8, arg9, argA, sp45);
        break;
    case 1:
        func_802BEAB0_6D0160(&D_803D5528->unk370, arg16->unk0, 3, 7, sp4E, arg0, arg1, arg2, arg3, arg8, arg9, argA, sp45);
        func_802BEAB0_6D0160(&D_803D5528->unk384, arg16->unk2, 4, 10, sp4C, arg0, arg1, arg2, arg3, arg8, arg9, argA, sp45);
        break;
    }
    func_802BEAB0_6D0160(&D_803D5528->unk398, arg16->unk4, 5, 13, sp4A, argB, argC, argD, argE, arg13, arg14, arg15, sp45);
    func_802BEAB0_6D0160(&D_803D5528->unk3AC, arg16->unk6, 6, 16, sp48, argB, argC, argD, argE, arg13, arg14, arg15, sp45);
}

#if 0
void func_802BE1A0_6CF850(struct103 *arg0, s16 arg1, u16 arg2, u8 arg3, u16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, struct077 *arg9, struct077 *argA, struct077 *argB, s8 argC) {

    u16 temp_t7;
    u16 temp_t8;
    s16 sp72;
    s16 sp70;
    s16 sp6E;

    s16 temp_a0;
    s16 tmp1, tmp2, tmp3;

    s16 var_v0;
    u32 temp;

    if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
        arg0->unk12++;
    }

    switch (argC) {
    case 1:
        temp_t7 = arg4 / 32;
        temp_t8 = arg4 - (temp_t7 * 32);

        sp72 = (((32 - temp_t8) * arg9[temp_t7].unk0) + (temp_t8 * arg9[(temp_t7 + 1) % 8].unk0)) / 32;
        sp70 = (((32 - temp_t8) * arg9[temp_t7].unk2) + (temp_t8 * arg9[(temp_t7 + 1) % 8].unk2)) / 32;
        sp6E = (((32 - temp_t8) * arg9[temp_t7].unk4) + (temp_t8 * arg9[(temp_t7 + 1) % 8].unk4)) / 32;
        break;
    case 2:
        temp_t7 = arg4 / 32;
        temp_t8 = arg4 - (temp_t7 * 32);

        sp72 = (((32 - temp_t8) * argA[temp_t7].unk0) + (temp_t8 * argA[(temp_t7 + 1) % 8].unk0)) / 32;
        sp70 = (((32 - temp_t8) * argA[temp_t7].unk2) + (temp_t8 * argA[(temp_t7 + 1) % 8].unk2)) / 32;
        sp6E = (((32 - temp_t8) * argA[temp_t7].unk4) + (temp_t8 * argA[(temp_t7 + 1) % 8].unk4)) / 32;
        break;
    default:
        sp72 = sp70 = sp6E = 0;
        break;
    }

    switch (arg0->unk10) {
    case 2:
    case 3:
    case 4:
        func_802BC900_6CDFB0(argB, arg4, D_803D552C->unk2FC, &sp72, &sp70, &sp6E);
        break;
    case 1:
    case 11:
        if (arg0->unk12 < 25) {
            func_802BCC50_6CE300(arg0->unk12, 25, 0, 0, 0, arg9[4].unk0, arg9[4].unk2, arg9[4].unk4, &sp72, &sp70, &sp6E);
        }
        if ((arg0->unk12 >= 25) && (arg0->unk12 < 50)) {
            func_802BCC50_6CE300(arg0->unk12 - 25, 25, arg9[4].unk0, arg9[4].unk2, arg9[4].unk4, 0, 0, 0, &sp72, &sp70, &sp6E);
        }
        if (arg0->unk12 >= 50) {
            arg0->unk10 = 0;
        }
        break;
    }

    arg0->unk4 = sp72;
    arg0->unk6 = sp70;
    arg0->unk8 = sp6E;

    if (D_803D552C->unk300 != 0) {
        func_802BCDA0_6CE450(arg0, &sp72, &sp70, &sp6E);
    }

    switch (D_803D5530->state) {                        /* switch 2; irregular */
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x6:
    case 0xB6:
    case 0xB7:
    case 0xB9:
        var_v0 = ((256 - D_80152350.unk384[(s16) ((arg4 * 360) / 256)]) * arg8) / 512;
        D_80203FE0[arg2].unk4 = (D_80203FE0[arg2].unk4 + arg8) - var_v0;
        break;
    case 0x5:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0x8D:
    case 0x8E:
    case 0x8F:
    case 0x90:
    case 0xB8:
        var_v0 = 0;
        break;
    case 0x2:
    case 0xB5:
        var_v0 = arg8;
        break;
    default:
        var_v0 = 0;
        break;
    }

    temp = (D_80152350.unk384[sp6E] * arg7) +
           (D_80152350.unk384[sp72] * arg5) +
           (D_80152350.unk384[sp70] * arg6);
    temp_a0 = ((temp / 256) + arg1) - D_80203FE0[arg2].unk4;

    if ((var_v0 * -3) < temp_a0) {
        if (var_v0 >= temp_a0) {
            D_80203FE0[arg2].unk4 += ((temp_a0 + (var_v0 * 3)) / 4);
        } else {
            D_80203FE0[arg2].unk4 += var_v0;
            var_v0 = ((D_80203FE0[arg2].unk4 - arg1) - ((D_80152350.unk384[sp6E] * arg7) / 256));
            func_802BC350_6CDA00(&sp72, &sp70, arg5, arg6, var_v0);
        }
    }
    if (sp70 >= sp6E) {
        sp6E = sp70;
    }

    // all falls apart here...

    tmp1 = D_80203FE0[arg2].unk0;
    tmp2 = D_80203FE0[arg2].unk2;
    tmp3 = D_80203FE0[arg2].unk4;

    tmp2 -= (s16)((arg5 * D_80152350.unk2D0[sp72]) / 256);
    tmp3 -= (s16)((arg5 * D_80152350.unk384[sp72]) / 256);

    D_80203FE0[arg3].unk0 = tmp1;
    D_80203FE0[arg3].unk2 = tmp2;
    D_80203FE0[arg3].unk4 = tmp3;

    tmp2 -= (s16)((arg6 * D_80152350.unk2D0[sp70]) / 256);
    tmp3 -= (s16)((arg6 * D_80152350.unk384[sp70]) / 256);

    D_80203FE0[arg3 + 1].unk0 = tmp1;
    D_80203FE0[arg3 + 1].unk2 = tmp2;
    D_80203FE0[arg3 + 1].unk4 = tmp3;

    tmp2 -= (s16)((arg7 * D_80152350.unk2D0[sp6E]) / 256);
    tmp3 -= (s16)((arg7 * D_80152350.unk384[sp6E]) / 256);

    D_80203FE0[arg3 + 2].unk0 = tmp1;
    D_80203FE0[arg3 + 2].unk2 = tmp2;
    D_80203FE0[arg3 + 2].unk4 = tmp3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BE1A0_6CF850.s")
#endif

#if 0
// dupe of func_802BE1A0_6CF850?
void func_802BEAB0_6D0160(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, struct077 *arg9, struct077 *argA, struct077 *argB, s8 argC) {
    u16 temp_t8;
    u16 temp_t9;

    s16 sp72;
    s16 sp70;
    s16 sp6E;

    s16 var_v0;
    s16 temp_a0;

    s16 tmp1, tmp2, tmp3;


    if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
        arg0->unk12++;
    }

    switch (argC) {
    case 1:
        temp_t8 = arg4 / 32;
        temp_t9 = arg4 - (temp_t8 * 32);
        sp72 = (((32 - temp_t9) * arg9[temp_t8].unk0) + (temp_t9 * arg9[(temp_t8 + 1) % 8].unk0)) / 32;
        sp70 = (((32 - temp_t9) * arg9[temp_t8].unk2) + (temp_t9 * arg9[(temp_t8 + 1) % 8].unk2)) / 32;
        sp6E = (((32 - temp_t9) * arg9[temp_t8].unk4) + (temp_t9 * arg9[(temp_t8 + 1) % 8].unk4)) / 32;
        break;
    case 2:
        temp_t8 = arg4 / 32;
        temp_t9 = arg4 - (temp_t8 * 32);
        sp72 = (((32 - temp_t9) * argA[temp_t8].unk0) + (temp_t9 * argA[(temp_t8 + 1) % 8].unk0)) / 32;
        sp70 = (((32 - temp_t9) * argA[temp_t8].unk2) + (temp_t9 * argA[(temp_t8 + 1) % 8].unk2)) / 32;
        sp6E = (((32 - temp_t9) * argA[temp_t8].unk4) + (temp_t9 * argA[(temp_t8 + 1) % 8].unk4)) / 32;
        break;
    default:
        sp6E = 0;
        sp70 = 0;
        sp72 = 0;
        break;
    }

    switch (arg0->unk10) {
    case 2:
    case 3:
    case 4:
        func_802BC900_6CDFB0(argB, arg4, D_803D552C->unk2FC, &sp72, &sp70, &sp6E);
        break;
    case 1:
    case 11:
        if (arg0->unk12 < 25) {
            func_802BCC50_6CE300(arg0->unk12, 25, 0, 0, 0, arg9[4].unk0, arg9[4].unk2, arg9[4].unk4, &sp72, &sp70, &sp6E);
        }
        if ((arg0->unk12 >= 25) && (arg0->unk12 < 50)) {
            func_802BCC50_6CE300(arg0->unk12 - 25, 25, arg9[4].unk0, arg9[4].unk2, arg9[4].unk4, 0, 0, 0, &sp72, &sp70, &sp6E);
        }
        if (arg0->unk12 >= 50) {
            arg0->unk10 = 0;
        }
        break;
    }

    arg0->unk4 = sp72;
    arg0->unk6 = sp70;
    arg0->unk8 = sp6E;

    if (D_803D552C->unk300 != 0) {
        func_802BCDA0_6CE450(arg0, &sp72, &sp70, &sp6E);
    }

    switch (D_803D5530->state) {
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x6:
    case 0xB6:
    case 0xB7:
    case 0xB9:
        var_v0 = ((0x100 - D_80152350.unk384[(s16) ((arg4 * 360) / 256)]) * arg8) / 512;
        D_80203FE0[arg2].unk4 = (D_80203FE0[arg2].unk4 + arg8) - var_v0;
        break;
    case 0x5:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0x8D:
    case 0x8E:
    case 0x8F:
    case 0x90:
    case 0xB8:
        var_v0 = 0;
        break;
    case 0x2:
    case 0xB5:
        var_v0 = arg8;
        break;
    default:
        var_v0 = 0;
        break;
    }

    temp_a0 = (((u32) ((D_80152350.unk384[sp6E] * arg7) +
                       (D_80152350.unk384[sp72] * arg5) +
                       (D_80152350.unk384[sp70] * arg6)) >> 8) + arg1) - D_80203FE0[arg2].unk4;

    if ((var_v0 * -3) < temp_a0) {
        if (var_v0 >= temp_a0) {
            D_80203FE0[arg2].unk4 += ((temp_a0 + (var_v0 * 3)) / 4);
        } else {
            D_80203FE0[arg2].unk4 += var_v0;
            func_802BC628_6CDCD8(&sp72, &sp70, arg5, arg6, (D_80203FE0[arg2].unk4 - arg1) - ((D_80152350.unk384[sp6E] * arg7) / 256));
        }
    }
    if (sp70 >= sp6E) {
        sp6E = sp70;
    }

    tmp1 = D_80203FE0[arg2].unk0;
    tmp2 = D_80203FE0[arg2].unk2;
    tmp3 = D_80203FE0[arg2].unk4;

    tmp3 -= (s16) ((arg5 * D_80152350.unk384[sp72]) / 256);
    tmp2 -= (s16) ((arg5 * D_80152350.unk2D0[sp72]) / 256);

    D_80203FE0[arg3+0].unk0 = tmp1;
    D_80203FE0[arg3+0].unk2 = tmp2;
    D_80203FE0[arg3+0].unk4 = tmp3;

    tmp3 -= (s16) ((arg6 * D_80152350.unk384[sp70]) / 256);
    tmp2 -= (s16) ((arg6 * D_80152350.unk2D0[sp70]) / 256);

    D_80203FE0[arg3+1].unk0 = tmp1;
    D_80203FE0[arg3+1].unk2 = tmp2;
    D_80203FE0[arg3+1].unk4 = tmp3;

    tmp3 -= (s16) ((arg7 * D_80152350.unk384[sp6E]) / 256);
    tmp2 -= (s16) ((arg7 * D_80152350.unk2D0[sp6E]) / 256);

    D_80203FE0[arg3+2].unk0 = tmp1;
    D_80203FE0[arg3+2].unk2 = tmp2;
    D_80203FE0[arg3+2].unk4 = tmp3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BEAB0_6D0160.s")
#endif

void func_802BF3C0_6D0A70(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, struct077 *arg6, struct077 *arg7, struct077 *arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s16 argD, s16 argE, s32 argF, s32 arg10, s32 arg11, struct061 *arg12) {
    u16 sp4E;
    u16 sp4C;
    u16 sp4A;
    u16 sp48;
    u16 sp46;
    s32 pad;
    s16 var_a0;
    s8  sp3D;
    s16 var_a2;

    sp46 = D_803D552C->unk2F2;
    switch (D_803D5530->state) {
    default:
        sp48 = sp46;
        sp4A = sp46;
        sp4C = sp46;
        sp4E = sp46;
        sp3D = 0;
        break;
    case 0x3:
    case 0xB6:
        sp3D = 1;
        sp4E = (D_803D552C->unk2F6 + arg2) % 256;
        sp4C = (D_803D552C->unk2F6 + arg3) % 256;
        sp4A = (D_803D552C->unk2F6 + argB) % 256;
        sp48 = (D_803D552C->unk2F6 + argC) % 256;

        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != (u8) 2)) {
            if ((sp4E >= 0x81) && (((D_803D552C->unk2F8 + arg2) % 256) < 0x81)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else  if ((sp4C >= 0x81) && (((D_803D552C->unk2F8 + arg3) % 256) < 0x81)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else  if ((sp4A >= 0x81) && (((D_803D552C->unk2F8 + argB) % 256) < 0x81)) {
                D_803F2F00 = 3;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp48 >= 0x81) && (((D_803D552C->unk2F8 + argC) % 256) < 0x81)) {
                D_803F2F00 = 4;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x6:
    case 0xB9:
        sp3D = 1;

        sp4E = 0x100 - ((D_803D552C->unk2F6 + arg2) % 256);
        sp4C = 0x100 - ((D_803D552C->unk2F6 + arg3) % 256);
        sp4A = 0x100 - ((D_803D552C->unk2F6 + argB) % 256);
        sp48 = 0x100 - ((D_803D552C->unk2F6 + argC) % 256);
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((sp4E >= 0x81) && ((0x100 - ((D_803D552C->unk2F8 + arg2) % 256)) < 0x81)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4C >= 0x81) && ((0x100 - ((D_803D552C->unk2F8 + arg3) % 256)) < 0x81)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4A >= 0x81) && ((0x100 - ((D_803D552C->unk2F8 + argB) % 256)) < 0x81)) {
                D_803F2F00 = 3;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp48 >= 0x81) && ((0x100 - ((D_803D552C->unk2F8 + argC) % 256)) < 0x81)) {
                D_803F2F00 = 4;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x4:
    case 0xB7:
        sp3D = 2;
        sp4E = (D_803D552C->unk2F6 + arg4) % 256;
        sp4C = (D_803D552C->unk2F6 + arg5) % 256;
        sp4A = (D_803D552C->unk2F6 + argD) % 256;
        sp48 = (D_803D552C->unk2F6 + argE) % 256;

        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((sp4E >= 0x81) && (((s32) (D_803D552C->unk2F8 + arg4) % 256) < 0x81)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4C >= 0x81) && (((D_803D552C->unk2F8 + arg5) % 256) < 0x81)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp4A >= 0x81) && (((D_803D552C->unk2F8 + argD) % 256) < 0x81)) {
                D_803F2F00 = 3;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp48 >= 0x81) && (((D_803D552C->unk2F8 + argE) % 256) < 0x81)) {
                D_803F2F00 = 4;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    }

    if (D_803D5524->waterClass & 0xC00) {
        u16 animalId; // temp is needed to match

        switch (D_803D5530->unk162) {
        case 4:
        case 5:
        case 6:
        case 7:
            animalId = D_803D5524->unk9C;
            sp3D = 2;
            sp48 = (sp46 * 64) & 0xFF;
            sp4E = (sp46 * 64) & 0xFF;
            sp4C = (sp48 + 0x80) & 0xFF;
            sp4A = (sp48 + 0x80) & 0xFF;
            if ((sp46 & 7) == 0) {
                func_8032CA90_73E140(D_803D5524->mass, animalId, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
            break;
        }
    } else {
        switch (D_803D5530->unk162) {
        case 4:
        case 5:
        case 7:
            var_a0 = 0x40;
            var_a2 = 0xC0;
            if (D_803D5524->unk9C == SKI_HUSKY) {
                var_a0 = 0;
                var_a2 = 0x80;
            }

            if (0) {};
            sp3D = 2;
            switch (D_803D5530->state) {
            case 0x8E:
            case 0x90:
                sp48 = (sp46 * 16) & 0xFF;
                sp4E = (sp46 * 16) & 0xFF;
                sp4C = (sp48 + 0x80) & 0xFF;
                sp4A = (sp48 + 0x80) & 0xFF;
                if ((sp46 & 0xF) == 0) {
                  func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
                }
                break;
            case 0x8F:
                sp48 = (sp46 * 32) & 0xFF;
                sp4E = (sp46 * 32) & 0xFF;
                sp4C = (sp48 + 0x80) & 0xFF;
                sp4A = (sp48 + 0x80) & 0xFF;
                if ((sp46 & 7) == 0) {
                  func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
                }
                break;
            default:
                sp4E = (D_803D552C->unk2F6 * 2) & 0xFF;
                sp4C = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
                sp4A = ((D_803D552C->unk2F6 * 2) + var_a0) & 0xFF;
                sp48 = ((D_803D552C->unk2F6 * 2) + var_a2) & 0xFF;
                break;
            }
        }
    }
    func_802BFF84_6D1634(&D_803D5528->unk370, arg12->unk0, 3, 7,  sp4E, arg0, arg1, arg6, arg7,  arg8,  sp3D);
    func_802BFF84_6D1634(&D_803D5528->unk384, arg12->unk2, 4, 10, sp4C, arg0, arg1, arg6, arg7,  arg8,  sp3D);
    func_802BFF84_6D1634(&D_803D5528->unk398, arg12->unk4, 5, 13, sp4A, arg9, argA, argF, arg10, arg11, sp3D);
    func_802BFF84_6D1634(&D_803D5528->unk3AC, arg12->unk6, 6, 16, sp48, arg9, argA, argF, arg10, arg11, sp3D);
}

void func_802BFF84_6D1634(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, struct077 *arg7, struct077 *arg8, struct077 *arg9, s8 argA) {
    s16 var_v0;
    u16 temp_t1;
    u16 temp_t7;
    s16 tmp;
    s16 tmp1, tmp2, tmp3;

    if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
        arg0->unk12++;
    }

    switch (argA) {
    case 1:
        temp_t1 = (arg4 / 32);
        temp_t7 = (arg4 - (temp_t1 << 5));
        var_v0 = (((32 - temp_t7) * arg7[temp_t1].unk0) + (arg7[(temp_t1 + 1) % 8].unk0 * temp_t7)) / 32;
        break;
    case 2:
        temp_t1 = (arg4 / 32);
        temp_t7 = (arg4 - (temp_t1 << 5));
        var_v0 = (((32 - temp_t7) * arg8[temp_t1].unk0) + (arg8[(temp_t1 + 1) % 8].unk0 * temp_t7)) / 32;
        break;
    default:
        var_v0 = 0;
        break;
    }

    switch (arg0->unk10) {
    case 1:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        break;
    case 2:
    case 3:
    case 4:
        var_v0 = 0;
        break;
    }
    arg0->unk4 = var_v0;

    switch (D_803D5530->state) {                    /* switch 2; irregular */
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x6:
    case 0xB6:
    case 0xB7:
    case 0xB9:
        tmp = ((256 - D_80152350.unk384[(s16) ((arg4 * 360) / 256)]) * arg6) / 512;
        D_80203FE0[arg2].unk4 = (D_80203FE0[arg2].unk4 + arg6) - tmp;
        break;
    case 0x5:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0xB8:
        break;
    case 0x2:
        break;
    default:
        break;
    }

    tmp1 = D_80203FE0[arg2].unk0;
    tmp2 = D_80203FE0[arg2].unk2;
    tmp3 = D_80203FE0[arg2].unk4;

    tmp3 -= (s16)((arg5 * D_80152350.unk384[var_v0]) / 256);
    tmp2 -= (s16)((arg5 * D_80152350.unk2D0[var_v0]) / 256);

    D_80203FE0[arg3].unk0 = tmp1;
    D_80203FE0[arg3].unk2 = tmp2;
    D_80203FE0[arg3].unk4 = tmp3;
}

void func_802C0364_6D1A14(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, s32 arg8, s16 arg9, s16 argA, s16 argB, s16 argC, s16 argD, s16 argE, struct077 *argF, struct077 *arg10, struct077 *arg11, struct061 *arg12) {
    u16 sp4E;
    u16 sp4C;
    u16 sp4A;
    u16 sp48;
    u16 sp46;
    u16 sp44;
    u16 sp42;
    u16 sp40;
    u16 sp3E;
    s8  sp3D;

    sp46 = D_803D552C->unk2F2;
    switch (D_803D5530->state) {
    case 3:
    case 0xB6:
    case 0x8D:
    case 0x8E:
        sp3D = 1;
        sp4E = (D_803D552C->unk2F6 + arg2) % 256;
        sp4C = (D_803D552C->unk2F6 + arg3) % 256;
        sp4A = (D_803D552C->unk2F6 + argB) % 256;
        sp48 = (D_803D552C->unk2F6 + argC) % 256;
        sp44 = ((D_803D552C->unk2F6 + arg2) + ((argB - arg2) / 3)) % 256;
        sp42 = ((D_803D552C->unk2F6 + arg3) + ((argC - arg3) / 3)) % 256;
        sp40 = ((D_803D552C->unk2F6 + argB) + ((arg2 - argB) / 3)) % 256;
        sp3E = ((D_803D552C->unk2F6 + argC) + ((arg3 - argC) / 3)) % 256;

        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != (u8) 2)) {
            if (D_803D5524->unk9C != EVO) {
                if ((sp4E >= 0x81) && (((D_803D552C->unk2F8 + arg2) % 256) < 0x81)) {
                    D_803F2F00 = 1;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if ((sp4C >= 0x81) && (((D_803D552C->unk2F8 + arg3) % 256) < 0x81)) {
                    D_803F2F00 = 2;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if ((sp4A >= 0x81) && (((D_803D552C->unk2F8 + argB) % 256) < 0x81)) {
                    D_803F2F00 = 3;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if ((sp48 >= 0x81) && (((D_803D552C->unk2F8 + argC) % 256) < 0x81)) {
                    D_803F2F00 = 4;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                }
            }
        }
        break;
    case 6:
    case 0x90:
    case 0xB9:
        sp3D = 1;

        sp4E = 0x100 - ((D_803D552C->unk2F6 + arg2) % 256);
        sp4C = 0x100 - ((D_803D552C->unk2F6 + arg3) % 256);
        sp4A = 0x100 - ((D_803D552C->unk2F6 + argB) % 256);
        sp48 = 0x100 - ((D_803D552C->unk2F6 + argC) % 256);
        sp44 = 0x100 - ((D_803D552C->unk2F6 + arg2) + ((argB - arg2) / 3)) % 256;
        sp42 = 0x100 - ((D_803D552C->unk2F6 + arg3) + ((argC - arg3) / 3)) % 256;
        sp40 = 0x100 - ((D_803D552C->unk2F6 + argB) + ((arg2 - argB) / 3)) % 256;
        sp3E = 0x100 - ((D_803D552C->unk2F6 + argC) + ((arg3 - argC) / 3)) % 256;

        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != (u8) 2)) {

            if (D_803D5524->unk9C != 0x3F) {
                if (((s32) sp4E >= 0x81) && ((0x100 - ((s32) (D_803D552C->unk2F8 + arg2) % 256)) < 0x81)) {
                    D_803F2F00 = 1;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if (((s32) sp44 >= 0x81) && ((0x100 - ((s32) (D_803D552C->unk2F8 + arg3) % 256)) < 0x81)) {
                    D_803F2F00 = 2;
                    D_803D553A = 5;
                } else if (((s32) sp4A >= 0x81) && ((0x100 - ((s32) (D_803D552C->unk2F8 + argB) % 256)) < 0x81)) {
                    D_803F2F00 = 3;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if (((s32) sp40 >= 0x81) && ((0x100 - ((s32) (D_803D552C->unk2F8 + argC) % 256)) < 0x81)) {
                    D_803F2F00 = 4;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                }
            }
        }
          break;
    case 4:
    case 0x8F:
    case 0xB7:
        sp3D = 2;
        sp4E = (D_803D552C->unk2F6 + arg4) % 256;
        sp4C = (D_803D552C->unk2F6 + arg5) % 256;
        sp4A = (D_803D552C->unk2F6 + argD) % 256;
        sp48 = (D_803D552C->unk2F6 + argE) % 256;
        sp44 = ((D_803D552C->unk2F6 + arg4) + ((argD - arg4) / 3)) % 256;
        sp42 = ((D_803D552C->unk2F6 + arg5) + ((argE - arg5) / 3)) % 256;
        sp40 = ((D_803D552C->unk2F6 + argD) + ((arg4 - argD) / 3)) % 256;
        sp3E = ((D_803D552C->unk2F6 + argE) + ((arg5 - argE) / 3)) % 256;

        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {

            if (D_803D5524->unk9C != EVO) {
                if ((sp4E >= 0x81) && (((s32) (D_803D552C->unk2F8 + arg4) % 256) < 0x81)) {
                    D_803F2F00 = 1;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if ((sp4C >= 0x81) && (((s32) (D_803D552C->unk2F8 + arg5) % 256) < 0x81)) {
                    D_803F2F00 = 2;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if ((sp4A >= 0x81) && (((s32) (D_803D552C->unk2F8 + argD) % 256) < 0x81)) {
                    D_803F2F00 = 3;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                } else if ((sp48 >= 0x81) && (((s32) (D_803D552C->unk2F8 + argE) % 256) < 0x81)) {
                    D_803F2F00 = 4;
                    D_803D553A = 5;
                    play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
                }
            }
        }
        break;
    default:
        sp48 = sp46;
        sp4A = sp46;
        sp4C = sp46;
        sp4E = sp46;
        sp3D = 0;
        break;
    }

    if (D_803D5524->waterClass & 0xC00) {
        switch (D_803D5530->unk162) {
        case 4:
        case 5:
        case 6:
        case 7:
            sp3D = 2;
            sp4E = (D_803D552C->unk2F6 * 0x10) & 0xFF;
            sp4C = ((D_803D552C->unk2F6 * 0x10) + 0x80) & 0xFF;
            sp4A = ((D_803D552C->unk2F6 * 0x10) + 0x40) & 0xFF;
            sp48 = ((D_803D552C->unk2F6 * 0x10) + 0xC0) & 0xFF;
            if ((D_803D552C->unk2F6 & 7) == 0) {
                func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
            break;
        }
    } else {
        switch (D_803D5530->state) {
        case 0x8E:
            sp3D = 2;
            sp4E = (D_803D552C->unk2F6 * 4) & 0xFF;
            sp4C = ((D_803D552C->unk2F6 * 4) + 0x80) & 0xFF;
            sp4A = ((D_803D552C->unk2F6 * 4) + 0x40) & 0xFF;
            sp48 = ((D_803D552C->unk2F6 * 4) + 0xC0) & 0xFF;
            if ((D_803D552C->unk2F6 & 7) == 0) {
                func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
            break;
        case 0x90:
            sp3D = 2;
            sp4E = 0x100 - ((D_803D552C->unk2F6 * 4) & 0xFF);
            sp4C = 0x100 - (((D_803D552C->unk2F6 * 4) + 0x80) & 0xFF);
            sp4A = 0x100 - (((D_803D552C->unk2F6 * 4) + 0x40) & 0xFF);
            sp48 = 0x100 - (((D_803D552C->unk2F6 * 4) + 0xC0) & 0xFF);
            if ((D_803D552C->unk2F6 & 7) == 0) {
                func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
            break;
        case 0x8F:
            sp3D = 2;
            sp4E = (D_803D552C->unk2F6 * 8) & 0xFF;
            sp4C = ((D_803D552C->unk2F6 * 8) + 0x80) & 0xFF;
            sp4A = ((D_803D552C->unk2F6 * 8) + 0x40) & 0xFF;
            sp48 = ((D_803D552C->unk2F6 * 8) + 0xC0) & 0xFF;
            if ((D_803D552C->unk2F6 & 7) == 0) {
                func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            }
            break;
        case 0x8D:
            sp3D = 2;
            sp4E = (D_803D552C->unk2F6 * 2) & 0xFF;
            sp4C = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
            sp4A = ((D_803D552C->unk2F6 * 2) + 0x40) & 0xFF;
            sp48 = ((D_803D552C->unk2F6 * 2) + 0xC0) & 0xFF;
            break;
        }
    }

    func_802C13E4_6D2A94(&D_803D5528->unk370, arg12->unk0, 3, 7,  sp4E, arg0, arg1, arg6, arg7, arg8, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk370, ((arg12->unk4 - arg12->unk0) / 3) + arg12->unk0, 8, 9, sp44, arg0, arg1, arg6, arg7, arg8, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk384, arg12->unk2, 4, 10, sp4C, arg0, arg1, arg6, arg7, arg8, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk384, ((arg12->unk6 - arg12->unk2) / 3) + arg12->unk2, 0xB, 0xC, sp42, arg0, arg1, arg6, arg7, arg8, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk398, arg12->unk4, 5, 13, sp4A, arg9, argA, argF, arg10, arg11, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk398, ((arg12->unk0 - arg12->unk4) / 3) + arg12->unk4, 0xE, 0xF, sp40, arg9, argA, argF, arg10, arg11, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk3AC, arg12->unk6, 6, 16, sp48, arg9, argA, argF, arg10, arg11, sp3D);
    func_802C13E4_6D2A94(&D_803D5528->unk3AC, ((arg12->unk2 - arg12->unk6) / 3) + arg12->unk6, 0x11, 0x12, sp3E, arg9, argA, argF, arg10, arg11, sp3D);
}

void func_802C13E4_6D2A94(struct103 *arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, struct077 *arg7, struct077 *arg8, struct077 *arg9, s8 argA) {
    s16 temp_a1;
    s16 var_a1;
    u16 temp_t1;
    u16 temp_t8;
    s16 var_a0;
    s16 tmp;
    s16 tmp1, tmp2, tmp3;
    s16 tmp4;

    if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
        arg0->unk12++;
    }

    switch (argA) {
    case 1:
        temp_t1 = arg4 / 32;
        temp_t8 = arg4 - (temp_t1 << 5);
        var_a0 = (((32 - temp_t8) * arg7[temp_t1].unk0) + (arg7[(temp_t1 + 1) % 8].unk0 * temp_t8)) / 32;
        break;
    case 2:
        temp_t1 = arg4 / 32;
        temp_t8 = arg4 - (temp_t1 << 5);
        var_a0 = (((32 - temp_t8) * arg8[temp_t1].unk0) + (arg8[(temp_t1 + 1) % 8].unk0 * temp_t8)) / 32;
        break;
    default:
        var_a0 = 0;
        break;
    }

    switch (arg0->unk10) {
    case 1:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        break;
    case 2:
    case 3:
    case 4:
        var_a0 = 0;
        break;
    }
    arg0->unk4 = var_a0;

    switch (D_803D5530->state) {
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x6:
    case 0xB6:
    case 0xB7:
    case 0xB9:
        tmp = ((256 - D_80152350.unk384[(s16) ((arg4 * 360) / 256)]) * arg6) / 512;
        D_80203FE0[arg2].unk4 = (D_80203FE0[arg2].unk4 + arg6) - tmp;
        break;
    case 0x5:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0xB8:
        break;
    case 0x2:
        break;
    default:
        break;
    }

    tmp1 = D_80203FE0[arg2].unk0;
    tmp2 = D_80203FE0[arg2].unk2;
    tmp3 = D_80203FE0[arg2].unk4;

    tmp3 -= (s16)(arg5 * (D_80152350.unk384[var_a0]) >> 8);
    if (arg2 == 3 || arg2 == 5 || arg2 == 8 || arg2 == 14) {
        tmp1 -= (s16)(arg5 * (D_80152350.unk2D0[var_a0]) >> 8);
    } else {
        tmp1 += (s16)(arg5 * (D_80152350.unk2D0[var_a0]) >> 8);
    }

    D_80203FE0[arg3].unk0 = tmp1;
    D_80203FE0[arg3].unk2 = tmp2;
    D_80203FE0[arg3].unk4 = tmp3;

    D_80203FE0[arg3].unk2 -= (((SIN(arg4) >> 7) >> 4) * arg5) >> 8;
    D_80203FE0[arg2].unk2 -= (((SIN(arg4) >> 7) >> 4) * arg5) >> 8;
}

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

void func_802C1A44_6D30F4(u16 arg0, u16 arg1, s16 *arg2) {
    D_80203FE0[14].unk2 = 0;
    D_80203FE0[14].unk0 = D_80203FE0[14].unk2;
    D_80203FE0[14].unk4 = D_80203FE0[2].unk4 - arg0;

    D_80203FE0[15].unk0 = 0;
    D_80203FE0[15].unk2 = D_80203FE0[14].unk2 + arg1;
    D_80203FE0[15].unk4 = D_80203FE0[14].unk4;
}

// only used by rabbit
void func_802C1A88_6D3138(u16 arg0, struct061 *arg1) {
    struct103 *temp_a1_2;
    s32 var_t0;
    s16 temp_hi;

    D_80203FE0[15].unk0 = D_80203FE0[2].unk0 - ((D_80152350.unk2D0[0x14] * arg0) / 256);
    D_80203FE0[15].unk2 = D_80203FE0[2].unk2 + ((D_80152350.unk384[0x14] * arg0) / 256);

    var_t0 = (((func_802B8C50_6CA300((-(D_80152350.unk2D0[0x14] * arg0) / 256), ((D_80152350.unk384[0x14] * arg0) / 256)) >> 8) << 5) >> 8) - D_80203FE0[2].unk4;
    temp_a1_2 = &D_803D5528->unk398;
    switch (temp_a1_2->unk10) {
    case 1:
        if (D_803F2D10.unk0 == 0) {
            temp_a1_2->unk12 += 1;
        }

        temp_hi = (temp_a1_2->unk12 * 8) % 50;
        if (temp_hi < 0x19) {
            var_t0 += (temp_hi * arg0) / 50;
        }
        if (temp_hi >= 0x19) {
            var_t0 += ((50 - temp_hi) * arg0) / 50;
        }

        if (temp_a1_2->unk12 >= 50) {
            temp_a1_2->unk10 = 0;
        }
        if (D_803D5530->state == 0x2A) {
            temp_a1_2->unk10 = 0;
        }
        if ((temp_hi < (((temp_a1_2->unk12 * 8) - 8) % 50)) && (((D_803D5530->unk162 == 1)) || (D_803D5530->unk162 == 6))) {
            play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
        }
        break;
    case 11:
        if (D_803F2D10.unk0 == 0) {
            temp_a1_2->unk12 += 1;
            if (temp_a1_2->unk12 >= 0x190) {
                temp_a1_2->unk10 = 0;
            }

            var_t0 += ((s32) (func_8038CCA4_79E354() * arg0) >> 7);
            if ((func_8038CCC0_79E370() != 0) && (((D_803D5530->unk162 == 1)) || (D_803D5530->unk162 == 6))) {
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    }

    if (arg0 < var_t0) {
        var_t0 = arg0;
    }
    if (var_t0 < -arg0) {
        var_t0 = -arg0;
    }

    switch (D_803D5530->state) {
    case 0x8E:
    case 0x90:
        D_80203FE0[15].unk2 += (((SIN(D_803D5540 << 5) >> 7) * arg0) >> 9);
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    case 0x8F:
        D_80203FE0[15].unk2 += (((SIN(D_803D5540 << 6) >> 7) * arg0) >> 9);
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    }

    D_80203FE0[15].unk4 = D_80203FE0[2].unk4 + (s16) var_t0;
    D_80203FE0[18].unk0 = D_80203FE0[2].unk0 - ((D_80152350.unk0[340] * arg0) / 256);
    D_80203FE0[18].unk2 = D_80203FE0[2].unk2 + ((D_80152350.unk2D0[70] * arg0) / 256);

    var_t0 = (((func_802B8C50_6CA300(-(D_80152350.unk0[340] * arg0) / 256, ((D_80152350.unk2D0[70] * arg0) / 256)) >> 8) << 5) >> 8) + D_80203FE0[2].unk4;

    temp_a1_2 = &D_803D5528->unk3AC;
    switch (temp_a1_2->unk10) {
    case 1:
        if (D_803F2D10.unk0 == 0) {
            temp_a1_2->unk12 += 1;
        }
        temp_hi = (temp_a1_2->unk12 * 8) % 50;
        if (temp_hi < 25) {
            var_t0 += (temp_hi * arg0) / 50;
        }
        if (temp_hi >= 25) {
            var_t0 += ((50 - temp_hi) * arg0) / 50;
        }
        if (temp_a1_2->unk12 >= 50) {
            temp_a1_2->unk10 = 0;
        }
        if (D_803D5530->state == 0x2A) {
            temp_a1_2->unk10 = 0;
        }
        if ((temp_hi < (((temp_a1_2->unk12 * 8) - 8) % 50)) && (((D_803D5530->unk162 == 1)) || (D_803D5530->unk162 == 6))) {
            play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
        }
        break;
    case 11:
        if (D_803F2D10.unk0 == 0) {
            temp_a1_2->unk12 += 1;
            if (temp_a1_2->unk12 >= 0x190) {
                temp_a1_2->unk10 = 0;
            }
            var_t0 += ((func_8038CCA4_79E354() * arg0) >> 7);
            if ((func_8038CCC0_79E370() != 0) && (((D_803D5530->unk162 == 1)) || (D_803D5530->unk162 == 6))) {
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    }

    if (arg0 < var_t0) {
        var_t0 = arg0;
    }
    if (var_t0 < -arg0) {
        var_t0 = -arg0;
    }
    switch (D_803D5530->state) {
    case 0x8E:
    case 0x90:
        D_80203FE0[18].unk2 += ((SIN((D_803D5540 << 5) + 128) >> 7) * arg0) >> 9;
        break;
    case 0x8F:
        D_80203FE0[18].unk2 += ((SIN((D_803D5540 << 6) + 128) >> 7) * arg0) >> 9;
        break;
    }
    D_80203FE0[18].unk4 = (s16)var_t0 + D_80203FE0[2].unk4;
}

void func_802C23F8_6D3AA8(s16 arg0) {
    u16 sp26;
    u16 sp24;

    u16 tmp1;
    u16 tmp2;

    u16 temp_v1;

    temp_v1 = D_803D552C->unk2F2;
    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0xB6:
    case 0xB9:
        sp26 = D_803D552C->unk2F6 % 256;
        sp24 = (D_803D552C->unk2F6 + 0x80) % 256;
        tmp1 = (D_803D552C->unk2F8 % 256);
        tmp2 = (D_803D552C->unk2F8 + 0x80) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((sp26 > 0x80) && (tmp1 <= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp24 > 0x80) && (tmp2 <= 0x80)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x4:
    case 0xB7:
        sp26 = D_803D552C->unk2F6 % 256;
        sp24 = (D_803D552C->unk2F6 + 0x80) % 256;
        tmp1 = (D_803D552C->unk2F8 % 256);
        tmp2 = (D_803D552C->unk2F8 + 0x80) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((sp26 >= 0x81) && (tmp1 <= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 6;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((sp24 > 0x80) && (tmp2 <= 0x80)) {
                D_803F2F00 = 2;
                D_803D553A = 6;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x8E:
    case 0x90:
        sp26 = (temp_v1 << 5) & 0xFF;
        sp24 = (sp26 + 0x80) & 0xFF;
        if ((D_803D552C->unk2F6 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    case 0x8F:
        sp26 = (temp_v1 << 6) & 0xFF;
        sp24 = (sp26 + 0x80) & 0xFF;
        if ((D_803D552C->unk2F6 & 3) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    case 0x8D:
        if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
            sp26 = (temp_v1 << 5) & 0xFF;
        } else {
            sp26 = (temp_v1 << 1) & 0xFF;
        }
        sp24 = (sp26 + 0x80) & 0xFF;
        break;
    default:
        sp26 = (temp_v1 << 5) & 0xFF;
        sp24 = (sp26 + 0x80) & 0xFF;
        break;
    }
    func_802C287C_6D3F2C(&D_803D5528->unk398, 2, 15, sp26, arg0, 25);
    func_802C287C_6D3F2C(&D_803D5528->unk3AC, 2, 18, sp24, arg0, -25);
}

void func_802C287C_6D3F2C(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5) {
    s32 pad;
    s16 sp38;
    s16 var_t0;
    s16 temp_hi;
    s16 temp_t4;

    D_80203FE0[arg2].unk0 = D_80203FE0[arg1].unk0 - ((D_80152350.unk2D0[arg5] * arg4) / 256);
    D_80203FE0[arg2].unk2 = D_80203FE0[arg1].unk2 + ((D_80152350.unk384[arg5] * arg4) / 256);

    var_t0 = (((func_802B8C50_6CA300(-(D_80152350.unk2D0[arg5] * arg4) / 256, ((D_80152350.unk384[arg5] * arg4) / 256)) >> 8) << 5) >> 8) - D_80203FE0[arg1].unk4;
    sp38 = -arg4;

    switch (D_803D5530->state) {
    case 3:
    case 6:
    case 0x8D:
    case 0x8E:
    case 0x90:
    case 0xB6:
    case 0xB9:
        temp_t4 = ((SIN(arg3) >> 7) * arg4) >> 8;
        if (var_t0 < temp_t4) {
            var_t0 = temp_t4;
        }
        break;
    case 4:
    case 0x8F:
    case 0xB7:
        temp_t4 = ((SIN(arg3) >> 7) * arg4) >> 7;
        if (var_t0 < temp_t4) {
            var_t0 = temp_t4;
        }
        break;
        break;
    }

    switch (arg0->unk10) {
    case 2:
    case 3:
    case 4:
        if (var_t0 < sp38) {
            var_t0 = sp38;
        }
        break;
    case 1:
        if (D_803F2D10.unk0 == 0) {
            arg0->unk12 += 1;
        }

        temp_hi = (arg0->unk12 * 8) % 50;
        if (temp_hi < 25) {
            var_t0 += (temp_hi * arg4) / 50;
        }
        if (temp_hi >= 25) {
            var_t0 += ((50 - temp_hi) * arg4) / 50;
        }
        if (arg0->unk12 >= 50) {
            arg0->unk10 = 0;
        }
        if (temp_hi < (((arg0->unk12 * 8) - 8) % 50)) {
            play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
        }
        break;
    case 11:
        if (D_803F2D10.unk0 == 0) {
            arg0->unk12 += 1;
            if (arg0->unk12 >= 0x190) {
                arg0->unk10 = 0;
            }
            var_t0 += ((func_8038CCA4_79E354() * arg4) >> 7);
            if (func_8038CCC0_79E370() != 0) {
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    default:
        break;
    }

    if (arg4 < var_t0) {
        var_t0 = arg4;
    }
    if (var_t0 < -arg4) {
        var_t0 = sp38;
    }
    D_80203FE0[arg2].unk4 = D_80203FE0[arg1].unk4 + var_t0;
}

void func_802C2D98_6D4448(s16 arg0, s16 arg1) {
    u16 var_t1;
    u16 var_t2;
    u16 tmp1;
    u16 tmp2;

    u16 temp_v1;

    temp_v1 = D_803D552C->unk2F2;

    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0xB6:
    case 0xB9:
        var_t1 = D_803D552C->unk2F6 % 256;
        var_t2 = (D_803D552C->unk2F6 + 0x80) % 256;
        tmp1 = D_803D552C->unk2F8 % 256;
        tmp2 = (D_803D552C->unk2F8 + 0x80) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((var_t1 > 0x80) && (tmp1 <= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((var_t2 > 0x80) && (tmp2 <= 0x80)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x4:
    case 0xB7:
        var_t1 = D_803D552C->unk2F6 % 256;
        var_t2 = (D_803D552C->unk2F6 + 0x80) % 256;
        tmp1 = D_803D552C->unk2F8 % 256;
        tmp2 = (D_803D552C->unk2F8 + 0x80) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((var_t1 > 0x80) && (tmp1 <= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 6;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((var_t2 > 0x80) && (tmp2 <= 0x80)) {
                D_803F2F00 = 2;
                D_803D553A = 6;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x8E:
    case 0x90:
        var_t1 = var_t2 = temp_v1 << 1;
        break;
    case 0x8F:
        var_t1 = var_t2 = temp_v1 << 2;
        break;
    default:
        var_t1 = var_t2 = temp_v1;
        break;
    }

    func_802C3188_6D4838(&D_803D5528->unk398, 5, 13, 14, var_t1, arg0, arg1, -25);
    func_802C3188_6D4838(&D_803D5528->unk3AC, 6, 16, 17, var_t2, arg0, arg1, -25);
}

void func_802C3188_6D4838(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, s16 arg5, s16 arg6, s32 arg7) {
    s32 temp_t7;
    s16 pad;
    s16 var_t1;
    s16 var_t0; // sp38
    s32 temp_t4;

    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0xB6:
    case 0xB9:
        var_t1 = (SIN(arg4) >> 7) >> 4;
        break;
    case 0x4:
    case 0xB7:
        var_t1 = (SIN(arg4) >> 7) >> 3;
        break;
    case 0x8E:
    case 0x8F:
    case 0x90:
        var_t1 = ((SIN(arg4) >> 7) >> 5) - 0x14;
        break;
    default:
        var_t1 = 0;
        break;
    }

    var_t0 = 0;
    switch (arg0->unk10) {
    default:
        arg0->unk10 = 0U;
        break;
    case 2:
    case 3:
    case 4:
        var_t1 = 0;
        break;
    case 11:
        if (D_803F2D10.unk0 == 0) {
            arg0->unk12++;
            if (arg0->unk12 >= 0x190) {
                arg0->unk10 = 0U;
            }
            var_t0 = (func_8038CCA4_79E354() * arg6) >> 6;
            if (func_8038CCC0_79E370() != 0) {
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    }

    D_80203FE0[arg2].unk0 = D_80203FE0[arg1].unk0;
    D_80203FE0[arg2].unk2 = D_80203FE0[arg1].unk2 + (((SIN(var_t1) >> 7) * arg5) >> 8);
    D_80203FE0[arg2].unk4 = D_80203FE0[arg1].unk4 - (((COS(var_t1) >> 7) * arg5) >> 8);

    D_80203FE0[arg3].unk0 = D_80203FE0[arg2].unk0;
    D_80203FE0[arg3].unk2 = D_80203FE0[arg2].unk2 + (((COS(var_t1) >> 7) * arg6) >> 8);
    D_80203FE0[arg3].unk4 = D_80203FE0[arg2].unk4 + (((SIN(var_t1) >> 7) * arg6) >> 8);

    var_t0 += ((((func_802B8C50_6CA300(D_80203FE0[arg1].unk0, D_80203FE0[arg1].unk2) >> 8) << 5) >> 8)) - D_80203FE0[arg2].unk4;
    if (var_t0 < 0) {
        var_t0 = 0;
    }
    if (var_t0 > 0x800) {
        var_t0 = 0x800;
    }

    D_80203FE0[arg2].unk4 += var_t0;
    D_80203FE0[arg1].unk4 += var_t0;
    D_80203FE0[arg3].unk4 += var_t0;

    var_t0 = (((func_802B8C50_6CA300(D_80203FE0[arg1].unk0, D_80203FE0[arg1].unk2) >> 8) << 5) >> 8) - D_80203FE0[arg3].unk4;
    if (var_t0 < 0) {
        var_t0 = 0;
    }
    if (var_t0 > 0x800) {
        var_t0 = 0x800;
    }
    D_80203FE0[arg3].unk4 += var_t0;
}

void func_802C353C_6D4BEC(s16 arg0, s16 arg1, s16 arg2, struct077 *arg3, struct077 *arg4, struct077 *arg5, struct061 *arg6) {
    u16 phi_t2;
    u16 phi_t3;
    u16 temp_v1;
    s8  phi_t1;

    temp_v1 = D_803D552C->unk2F2;

    switch (D_803D5530->state) {                        /* implicit */
    case 0x3:
    case 0x8E:
    case 0xB6:
        phi_t1 = 1;
        phi_t2 = D_803D552C->unk2F6 % 256;
        phi_t3 = (D_803D552C->unk2F6 + 0x80) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((phi_t2 > 0x80) && ((D_803D552C->unk2F8 % 256) <= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else if ((phi_t3 > 0x80) && (((D_803D552C->unk2F8 + 0x80) % 256) <= 0x80)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x6:
    case 0x90:
    case 0xB9:
        phi_t1 = 1;
        phi_t2 = 0x100 - (D_803D552C->unk2F6 % 256);
        phi_t3 = 0x100 - ((D_803D552C->unk2F6 + 0x80) % 256);
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((phi_t2 < 0x80) && ((0x100 - (D_803D552C->unk2F8 % 256)) >= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else
            if ((phi_t3 < 0xE1) && ((0x100 - ((D_803D552C->unk2F8 + 0x80) % 256)) >= 0xE1)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    case 0x4:
    case 0x8F:
    case 0xB7:
        phi_t1 = 2;
        phi_t2 = D_803D552C->unk2F6 % 256;
        phi_t3 = (D_803D552C->unk2F6 + 0x80) % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2)) {
            if ((phi_t2 > 0x80) && ((D_803D552C->unk2F8 % 256) <= 0x80)) {
                D_803F2F00 = 1;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            } else
            if ((phi_t3 > 0x80) && (((D_803D552C->unk2F8 + 0x80) % 256) <= 0x80)) {
                D_803F2F00 = 2;
                D_803D553A = 5;
                play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
            }
        }
        break;
    default:
        phi_t1 = 0;
        phi_t3 = temp_v1;
        phi_t2 = temp_v1;
        break;
    }

    if ((D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2))) {
        switch (D_803D5530->unk162) {
        case 4:
        case 5:
        case 6:
        case 7:
            phi_t1 = 2;
            phi_t2 = (D_803D552C->unk2F6 * 16) & 0xFF;
            phi_t3 = ((D_803D552C->unk2F6 * 16) + 0x80) & 0xFF;
        }
    } else {
        switch (D_803D5530->unk162) {
        case 4:
        case 5:
        case 7:
            phi_t1 = 2;
            switch (D_803D5530->state) {
            default:
                // sameline for regalloc
                phi_t2 = (D_803D552C->unk2F6 * 2) & 0xFF;phi_t3 = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
                break;
            case 0x8E:
                phi_t2 = D_803D552C->unk2F6 & 0xFF;
                phi_t3 = (D_803D552C->unk2F6 + 0x80) & 0xFF;
                break;
            case 0x90:
                phi_t2 = 256 - ((D_803D552C->unk2F6       ) & 0xFF);
                phi_t3 = 256 - ((D_803D552C->unk2F6 + 0x80) & 0xFF);
                break;
            case 0x8F:
                phi_t2 = (D_803D552C->unk2F6 * 2) & 0xFF;
                phi_t3 = ((D_803D552C->unk2F6 * 2) + 0x80) & 0xFF;
                break;
            }
        }
    }

    func_802BE1A0_6CF850(&D_803D5528->unk398, arg6->unk0, 5, 13, phi_t2, arg0, arg1, 0, arg2, arg3, arg4, arg5, phi_t1);
    func_802BE1A0_6CF850(&D_803D5528->unk3AC, arg6->unk2, 6, 16, phi_t3, arg0, arg1, 0, arg2, arg3, arg4, arg5, phi_t1);
}

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
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2) && (tmp1 >= 0xB) && (tmp2 < 0xB) && (D_803D5530->unk4A == 0)) {
            D_803F2F00 = 1;
            D_803D553A = 5;
            play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
        }
        break;
    case 0x4:
    case 0xB7:
        tmp1 = D_803D552C->unk2F6 % 256;
        tmp2 = D_803D552C->unk2F8 % 256;
        if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2) &&
            (tmp1 >= 0xB) &&
            (tmp2 < 0xB) && (D_803D5530->unk4A == 0)) {
            D_803F2F00 = 1;
            D_803D553A = 6;
            play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
        }
        break;
    case 0x8E:
    case 0x90:
        if (!(fixme = D_803D552C->unk2F2 & 7)) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    case 0x8F:
        if (!(fixme = D_803D552C->unk2F2 & 7)) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    }
    func_802C3F58_6D5608(&D_803D5528->unk398, 5, 13, 14,  arg0, arg1, arg2);
    func_802C3F58_6D5608(&D_803D5528->unk3AC, 6, 16, 17, -arg0, arg1, arg2);
}

void func_802C3F58_6D5608(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_a1;
    s16 temp_hi;
    s32 var_a2;

    var_a1 = (((func_802B8C50_6CA300(arg4, arg6) >> 8) << 5) >> 8) - D_80203FE0[2].unk4;
    switch (arg0->unk10) {
    case 1:
        if (D_803F2D10.unk0 == 0) {
            arg0->unk12++;
        }

        temp_hi = (arg0->unk12 << 3) % 50;
        if (temp_hi < 25) {
            var_a1 += (temp_hi * arg6) / 50;
        }
        if (temp_hi >= 25) {
            var_a1 += ((50 - temp_hi) * arg6) / 50;
        }

        if (arg0->unk12 >= 50) {
            arg0->unk10 = 0;
        }
        if (temp_hi < (((arg0->unk12 << 3) - 8) % 50)) {
            // debug stub?
        }
        break;
    case 11:
        if (D_803F2D10.unk0 == 0) {
            arg0->unk12++;
        }
        if (arg0->unk12 < 25) {
            var_a1 += (arg0->unk12 * arg6) / 50;
        }
        if (arg0->unk12 >= 25) {
            var_a1 += ((50 - arg0->unk12) * arg6) / 50;
        }
        if (arg0->unk12 >= 50) {
            arg0->unk10 = 0;
        }
        break;
    }
    if (var_a1 < 0) {
        var_a1 = (var_a1 >> 1);
    }
    // clamp
    if (var_a1 > arg6) {
        var_a1 = arg6;
    }
    if (var_a1 < -arg6) {
        var_a1 = -arg6;
    }

    switch (D_803D5530->state) {
    case 0x8E:
    case 0x90:
        if (arg1 == 5) {
            var_a1 += ((SIN(D_803D5540 << 4) >> 7) * arg6) >> 8;
        } else {
            var_a1 += ((SIN((D_803D5540 << 4) + 128) >> 7) * arg6) >> 8;
        }
        break;
    case 0x8F:
        if (arg1 == 5) {
            var_a1 += ((SIN(D_803D5540 << 5) >> 7) * arg6) >> 8;
        } else {
            var_a1 += ((SIN((D_803D5540 << 5) + 128) >> 7) * arg6) >> 8;
        }
        break;
    }

    D_80203FE0[arg3].unk4 = D_80203FE0[2].unk4 + var_a1;

    D_80203FE0[arg1].unk0 = D_80203FE0[2].unk0 + arg4;
    D_80203FE0[arg1].unk2 = D_80203FE0[2].unk2;
    D_80203FE0[arg1].unk4 = D_80203FE0[2].unk4 + arg5;

    D_80203FE0[arg2].unk0 = D_80203FE0[arg1].unk0;
    D_80203FE0[arg2].unk2 = D_80203FE0[arg1].unk2 - (arg6 >> 2);
    D_80203FE0[arg2].unk4 = D_80203FE0[arg1].unk4 - arg5;

    D_80203FE0[arg3].unk0 = D_80203FE0[arg2].unk0;
    D_80203FE0[arg3].unk2 = D_80203FE0[arg2].unk2 + arg6;
}

void func_802C4448_6D5AF8(s16 arg0) {
    if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
    }
    D_80203FE0[5].unk0 = D_80203FE0[0].unk0;
    D_80203FE0[5].unk2 = D_80203FE0[0].unk2;
    D_80203FE0[5].unk4 = D_80203FE0[0].unk4 - arg0;
}

// ordering of assignments is wrong
#if 0
// CURRENT (7447)
void func_802C44E8_6D5B98(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 sp42;
    s16 sp40;
    s16 sp3E;
    s16 sp3C;

    s16 temp_t9;
    s16 temp_v0;
    s16 temp_t7;
    s32 phi_v1;

    switch (D_803D5530->state) {
    case 142:
    case 144:
        temp_v0 = (D_803D5540 << 4) & 0xFF;
        temp_t9 = ((D_803D5540 << 4) + 0x80) & 0xFF;
        temp_t7 = (((SIN(temp_v0)) >> 7) * arg3) >> 8;
        sp42 = temp_t7;
        sp40 = -temp_t7;
        if ((temp_v0 > 64) && (temp_v0 < 192)) {
            sp3E = ((((COS(temp_v0 << 1) >> 7) + 0x100) * arg3) >> 0xA);
        } else {
            sp3E = 0;
        }
        if ((temp_t9 > 64) && (temp_t9 < 192)) {
            sp3C = ((((COS(temp_t9 << 1) >> 7) + 0x100) * arg3) >> 0xA);
        } else {
            sp3C = 0;
        }
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    case 143:
        temp_v0 = (D_803D5540 << 5) & 0xFF;
        temp_t9 = ((D_803D5540 << 5) + 0x80) & 0xFF;
        temp_t7 = (((SIN(temp_v0)) >> 7) * arg3) >> 8;
        sp42 = temp_t7;
        sp40 = -temp_t7;
        if ((temp_v0 > 64) && (temp_v0 < 192)) {
            sp3E = (((COS(temp_v0 << 1) >> 7) + 256) * arg3) >> 10;
        } else {
            sp3E = 0;
        }
        if ((temp_t9 > 64) && (temp_t9 < 192)) {
            sp3C = (((COS(temp_t9 << 1) >> 7) + 256) * arg3) >> 10;
        } else {
            sp3C = 0;
        }
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
        }
        break;
    default:
        sp3C = 0;
        sp3E = 0;
        sp40 = 0;
        sp42 = 0;
        break;
    }

    // falls apart here
    D_80203FE0[5].unk0 = D_80203FE0[0].unk0;
    D_80203FE0[5].unk2 = D_80203FE0[0].unk2 + sp42;
    D_80203FE0[5].unk4 = D_80203FE0[0].unk4 - arg0;

    D_80203FE0[27].unk0 = D_80203FE0[0].unk0;
    D_80203FE0[27].unk2 = D_80203FE0[0].unk2 + sp40;
    D_80203FE0[27].unk4 = D_80203FE0[0].unk4 - arg0;

    D_80203FE0[3].unk0 = D_80203FE0[5].unk0 - arg1;
    D_80203FE0[3].unk2 = D_80203FE0[5].unk2;
    D_80203FE0[3].unk4 = D_80203FE0[5].unk4;

    D_80203FE0[4].unk0 = D_80203FE0[27].unk0 + arg1;
    D_80203FE0[4].unk2 = D_80203FE0[27].unk2;
    D_80203FE0[4].unk4 = D_80203FE0[27].unk4;

    D_80203FE0[13].unk0 = D_80203FE0[3].unk0;
    D_80203FE0[13].unk2 = D_80203FE0[3].unk2 - arg2;
    D_80203FE0[13].unk4 = D_80203FE0[3].unk4;

    D_80203FE0[11].unk0 = D_80203FE0[4].unk0;
    D_80203FE0[11].unk2 = (D_80203FE0[4].unk2 + arg3) - sp3E;
    D_80203FE0[11].unk4 = D_80203FE0[4].unk4 - sp3C;

    D_80203FE0[14].unk0 = D_80203FE0[4].unk0;
    D_80203FE0[14].unk2 = D_80203FE0[4].unk2 - arg2;
    D_80203FE0[14].unk4 = D_80203FE0[4].unk4;

    D_80203FE0[7].unk0 = (D_80203FE0[3].unk0 - ((arg3 * 0xB) >> 4));
    D_80203FE0[8].unk0 = D_80203FE0[3].unk0;
    D_80203FE0[9].unk0 = (D_80203FE0[3].unk0 + ((arg3 * 0xB) >> 4));

    D_80203FE0[7].unk2 = (D_80203FE0[3].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;
    D_80203FE0[8].unk2 = (D_80203FE0[3].unk2 + arg3) - sp3E;
    D_80203FE0[9].unk2 = (D_80203FE0[3].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;

    D_80203FE0[7].unk4 = D_80203FE0[3].unk4 - sp3E;
    D_80203FE0[8].unk4 = D_80203FE0[3].unk4 - sp3E;
    D_80203FE0[9].unk4 = D_80203FE0[3].unk4 - sp3E;

    D_80203FE0[10].unk0 = D_80203FE0[4].unk0 - ((arg3 * 0xB) >> 4);
    D_80203FE0[12].unk0 = D_80203FE0[4].unk0 + ((arg3 * 0xB) >> 4);

    D_80203FE0[10].unk2 = (D_80203FE0[4].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;
    D_80203FE0[12].unk2 = (D_80203FE0[4].unk2 + ((arg3 * 0xB) >> 4)) - sp3E;

    D_80203FE0[10].unk4 = D_80203FE0[4].unk4 - sp3C;
    D_80203FE0[12].unk4 = D_80203FE0[4].unk4 - sp3C;



    if (D_803D5530->state == 101) {
        if ((D_803D5524->unk9C != SEAGULL2) && (D_803D5524->unk9C != VULTURE)) {
            temp_t9 = D_803D5540 & 0x3F;
            if (temp_t9 < 20) {
                phi_v1 = (temp_t9 - 10) < 0 ? (10 - temp_t9) : (temp_t9 - 10);
                D_80203FE0[7].unk4 += (arg3 * (10 - phi_v1)) >> 4;
            }
            if ((temp_t9 < 30) && (temp_t9 > 10)) {
                phi_v1 = (temp_t9 - 20) < 0 ? (20 - temp_t9) : (temp_t9 - 20);
                D_80203FE0[8].unk4 += (arg3 * (10 - phi_v1)) >> 4;
            }
            if ((temp_t9 < 40) && (temp_t9 > 20)) {
                phi_v1 = (temp_t9 - 30) < 0 ? (30 - temp_t9) : (temp_t9 - 30);
                D_80203FE0[9].unk4 += (arg3 * (10 - phi_v1)) >> 4;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C44E8_6D5B98.s")
#endif
