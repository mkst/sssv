#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB840_6CCEF0.s")
// nonsense
// void func_802BB840_6CCEF0(s16 arg0) {
//     s16 tmp = arg0;
//
//     D_80203FE0[26].unk0 = D_80203FE0[2].unk0;
//     D_80203FE0[26].unk2 = D_80203FE0[2].unk2 - tmp;
//     D_80203FE0[26].unk4 = D_80203FE0[2].unk4;
// }

// unused? similar issue to func_802BB840_6CCEF0
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB870_6CCF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB938_6CCFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBA10_6CD0C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBC90_6CD340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBFA0_6CD650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC1F4_6CD8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC350_6CDA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC628_6CDCD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC900_6CDFB0.s")

void func_802BCC50_6CE300(s16 arg0, u16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 *arg8, s16 *arg9, s16 *argA) {
    *arg8 = ((arg5 * arg0) + (arg2 * (arg1 - arg0))) / arg1;
    *arg9 = ((arg6 * arg0) + (arg3 * (arg1 - arg0))) / arg1;
    *argA = ((arg7 * arg0) + (arg4 * (arg1 - arg0))) / arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BCDA0_6CE450.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C0364_6D1A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C13E4_6D2A94.s")

void func_802C1830_6D2EE0(u16 arg0, struct061 *arg1) {
    func_802C19CC_6D307C(D_803D5528->unk370, arg1->unk0, 3, 7, 0, arg0);
    func_802C19CC_6D307C(D_803D5528->unk384, arg1->unk2, 4, 10, 0, arg0);
    func_802C19CC_6D307C(D_803D5528->unk398, arg1->unk4, 5, 13, 0, arg0);
    func_802C19CC_6D307C(D_803D5528->unk3AC, arg1->unk6, 6, 16, 0, arg0);
}

void func_802C18FC_6D2FAC(u16 arg0, u16 arg1, struct061 *arg2) {
    func_802C19CC_6D307C(D_803D5528->unk370, arg2->unk0, 3, 7, 0, arg0);
    func_802C19CC_6D307C(D_803D5528->unk384, arg2->unk2, 4, 10, 0, arg0);
    func_802C19CC_6D307C(D_803D5528->unk398, arg2->unk4, 5, 13, 0, arg1);
    func_802C19CC_6D307C(D_803D5528->unk3AC, arg2->unk6, 6, 16, 0, arg1);
}

void func_802C19CC_6D307C(s16 **arg0, s16 arg1, u16 arg2, u16 arg3, s32 arg4, u16 arg5) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3C64_6D5314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3F58_6D5608.s")

void func_802C4448_6D5AF8(s16 arg0) {
    if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->unk7C, D_803D5524->unk9C, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
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
//             func_8032CA90_73E140(D_803D5524->unk7C, D_803D5524->unk9C, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
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
//             func_8032CA90_73E140(D_803D5524->unk7C, D_803D5524->unk9C, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
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
