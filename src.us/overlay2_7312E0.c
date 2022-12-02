#include <ultra64.h>
#include "common.h"

#include "structs.h"
#include "variables.us.h"


void func_8032018C_73183C(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, struct077 arg6[8], struct077 arg7[8], struct087 *arg8, s8 arg9);
void func_80320828_731ED8(struct103 *arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4);

#if 0
// needs some help... maybe just regalloc?
void func_8031FC30_7312E0(struct103 *arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    u16 new_var;
    s16 pad[2];
    s16 tmp1;
    s16 sp24;

    sp24 = arg2;

    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0x8E:
    case 0x90:
    case 0xB6:
    case 0xB9:
        tmp1 = (D_80152C78[sp24 & 0xFF] >> 7) / 10;
        break;
    case 0x4:
    case 0x8F:
    case 0xB7:
        tmp1 = (D_80152C78[sp24 & 0xFF] >> 7) / 6;
        break;
    default:
        tmp1 = 0;
        break;
    }

    switch (arg0->unk10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        break;
    }

    sp24 = tmp1;
    if (arg1 == 7) {
        sp24 = -sp24;
    }

    D_80203FE0[arg1].unk0 = D_80203FE0[1].unk0 + arg3;
    D_80203FE0[arg1].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[arg1].unk4 = D_80203FE0[1].unk4;

    func_802C7B18_6D91C8(&D_80203FE0[arg1], sp24);

    D_80203FE0[arg1 + 1].unk0 = D_80203FE0[arg1].unk0;
    D_80203FE0[arg1 + 1].unk2 = D_80203FE0[arg1].unk2;
    // urgh
    D_80203FE0[arg1 + 1].unk4 = new_var = D_80203FE0[arg1].unk4 - arg4;;

    D_80203FE0[arg1 + 2].unk0 = D_80203FE0[arg1 + 1].unk0;
    // urgh x2
    if (sp24 < (arg1 * 0)) {
        sp24 = 0;
    }
    D_80203FE0[arg1 + 2].unk2 = D_80203FE0[arg1 + 1].unk2 + ((arg5 * sp24) / 64);
    D_80203FE0[arg1 + 2].unk4 = D_80203FE0[arg1 + 1].unk4 - arg5;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_8031FC30_7312E0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_8031FE40_7314F0.s")
// more of the same
// void func_8031FE40_7314F0(s16 arg0, s16 arg1, struct077 arg2[8], struct077 arg3[8], struct087 *arg4) {
//     u16 temp_v1;
//     u16 sp34;
//     u16 sp30; // pad
//     s8 phi_t0;
//     u16 phi_a3;
//
//     temp_v1 = D_803D552C->unk2F2;
//
//     switch (D_803D5530->state) {                        /* implicit */
//     case 0x3:
//     case 0x8E:
//     case 0xB6:
//         phi_t0 = 1;
//         phi_a3 = D_803D552C->unk2F6 % 256;
//         sp34 = ((D_803D552C->unk2F6 + 128) % 256);
//         break;
//     case 0x6:
//     case 0x90:
//     case 0xB9:
//         phi_t0 = 1;
//         phi_a3 = 256 - (D_803D552C->unk2F6 % 256);
//         sp34 = 256 - ((D_803D552C->unk2F6 + 128) % 256);
//         break;
//     case 0x4:
//     case 0x8F:
//     case 0xB7:
//         phi_t0 = 2;
//         phi_a3 = D_803D552C->unk2F6 % 256;
//         sp34 = (D_803D552C->unk2F6 + 128) % 256;
//         break;
//     default:
//         phi_t0 = 0;
//         phi_a3 = sp34 = temp_v1;
//         break;
//     }
//
//     if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
//         switch (D_803D5530->unk162) {
//           case 4:
//           case 5:
//           case 6:
//           case 7:
//               phi_t0 = 2;
//               phi_a3 = (D_803D552C->unk2F6 << 4) & 0xFF;
//               sp34 = ((D_803D552C->unk2F6 << 4) + 128) & 0xFF;
//               break;
//         }
//     } else {
//       switch (D_803D5530->unk162) {
//         case 4:
//         case 5:
//         case 7:
//             switch (D_803D5530->state) {
//             case 0x8E:
//                 phi_a3 = D_803D552C->unk2F6 & 0xFF;
//                 sp34 = (D_803D552C->unk2F6 + 128) & 0xFF;
//                 phi_t0 = 2;
//                 break;
//             case 0x8F:
//                 phi_a3 = (D_803D552C->unk2F6 << 1) & 0xFF;
//                 sp34 = ((D_803D552C->unk2F6 << 1) + 128) & 0xFF;
//                 phi_t0 = 2;
//                 break;
//             case 0x90:
//                 phi_a3 = (256 - (D_803D552C->unk2F6 & 0xFF));
//                 sp34 = 256 - ((D_803D552C->unk2F6 + 128) & 0xFF);
//                 phi_t0 = 2;
//                 break;
//             default:
//                 phi_a3 = D_803D552C->unk2F6 & 0xFF;
//                 sp34 = (D_803D552C->unk2F6 + 128) & 0xFF;
//                 phi_t0 = 2;
//                 break;
//             }
//             break;
//         }
//     }
//     func_8032018C_73183C(&D_803D5528->unk370, 3, 7, phi_a3, arg0, arg1, arg2, arg3, arg4, phi_t0);
//     func_8032018C_73183C(&D_803D5528->unk384, 4, 10,  sp34, arg0, arg1, arg2, arg3, arg4, phi_t0);
// }

#if 0
//10000+ away
void func_8032018C_73183C(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, struct077 arg6[8], struct077 arg7[8], struct087 *arg8, s8 arg9) {
    u16 temp_t5;
    u16 temp_t5_2;

    s16 sp62;
    s16 sp60;
    s16 sp5E;

    s16 temp_a3;
    s16 temp_a1;
    s16 temp_t0_3;
    s16 temp_t6_3;

    s16 idx;

    if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
        arg0->unk12++;
    }

    switch (arg9) {
    case 1:
        temp_t5 = (arg3 / 32);
        temp_t5_2 = (arg3 - (temp_t5 * 32));
        temp_a3 = 32 - temp_t5_2;
        idx = ((temp_t5 + 1) % 8);
        sp62 = ((arg6[idx].unk0 * temp_t5_2) + (temp_a3 * arg6[temp_t5].unk0)) / 32;
        sp60 = ((arg6[idx].unk2 * temp_t5_2) + (temp_a3 * arg6[temp_t5].unk2)) / 32;
        break;
    case 2:
        temp_t5 = (arg3 / 32);
        temp_t5_2 = (arg3 - (temp_t5 * 32));
        temp_a3 = 32 - temp_t5_2;
        idx = ((temp_t5 + 1) % 8);
        sp62 = ((arg7[idx].unk0 * temp_t5_2) + (temp_a3 * arg7[temp_t5].unk0)) / 32;
        sp60 = ((arg7[idx].unk2 * temp_t5_2) + (temp_a3 * arg7[temp_t5].unk2)) / 32;
        break;
    default:
        sp62 = sp60 = 0;
        break;
    }

    switch (arg0->unk10) {
    case 2:
    case 3:
    case 4:
        func_802BC900_6CDFB0(arg8, arg3, D_803D552C->unk2FC, &sp62, &sp60, &sp5E);
        break;
    case 1:
    case 11:
        if (arg0->unk12 < 25) {
            func_802BCC50_6CE300(arg0->unk12, 25, 0, 0, 0, arg6[4].unk0, arg6[4].unk2, arg6[4].unk4, &sp62, &sp60, &sp5E);
        }
        if ((arg0->unk12 >= 25) && (arg0->unk12 < 50)) {
            func_802BCC50_6CE300(arg0->unk12 - 25, 25, arg6[4].unk0, arg6[4].unk2, arg6[4].unk4, 0, 0, 0, &sp62, &sp60, &sp5E);
        }
        if (arg0->unk12 >= 50) {
            arg0->unk10 = 0;
        }
        break;
    }

    arg0->unk4 = sp62;
    arg0->unk6 = sp60;
    arg0->unk8 = sp5E;

    if (D_803D552C->unk300 != 0) {
        func_802BCDA0_6CE450(arg0, &sp62, &sp60, &sp5E);
    }
    temp_t0_3 = D_80203FE0[arg1].unk0;
    temp_t6_3 = D_80203FE0[arg1].unk2 - ((arg4 * D_80152350.unk2D0[sp62]) / 256);
    temp_a1 = D_80203FE0[arg1].unk4 - ((arg4 * D_80152350.unk384[sp62]) / 256);

    D_80203FE0[arg2].unk0 = temp_t0_3;
    D_80203FE0[arg2].unk2 = temp_t6_3;
    D_80203FE0[arg2].unk4 = temp_a1;

    D_80203FE0[arg2+1].unk0 = temp_t0_3;
    D_80203FE0[arg2+1].unk2 = temp_t6_3 - ((arg5 * D_80152350.unk2D0[sp60]) / 256);
    D_80203FE0[arg2+1].unk4 = temp_a1 - ((arg5 * D_80152350.unk384[sp60]) / 256);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_8032018C_73183C.s")
#endif

void func_8032066C_731D1C(s16 arg0, s16 arg1) {
    u16 temp_v1;
    u16 sp24;
    u16 phi_a2;

    temp_v1 = D_803D552C->unk2F2;

    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0x8E:
    case 0x90:
    case 0xB6:
    case 0xB9:
        phi_a2 = (D_803D552C->unk2F6 % 256);
        sp24 = ((D_803D552C->unk2F6 + 128) % 256);
        break;
    case 0x4:
    case 0x8F:
    case 0xB7:
        phi_a2 = (D_803D552C->unk2F6 % 256);
        sp24 = ((D_803D552C->unk2F6 + 128) % 256);
        break;
    default:
        sp24 = temp_v1;
        phi_a2 = temp_v1;
    }

    if (D_803D5528->unk384.unk10 == 1) {
        D_803D5528->unk384.unk10 = 0;
    }
    if (D_803D5528->unk370.unk10 == 1) {
        D_803D5528->unk384.unk10 = 1;
        D_803D5528->unk384.unk12 = D_803D5528->unk370.unk12;
    }

    func_80320828_731ED8(&D_803D5528->unk370, 7, phi_a2, arg0, arg1);
    func_80320828_731ED8(&D_803D5528->unk384, 10, sp24, -arg0, arg1);
}

#if 0
void func_80320828_731ED8(struct103 *arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4) {
    s16 sp2C;
    s16 sp2A;
    s32 sp20;
    // struct061 *sp1C;
    s16 temp_a3;
    s16 var_a1;
    s16 var_t0;

    var_t0 = 0;
    if ((arg0->unk10 != 0) && (D_803F2D10.unk0 == 0)) {
        arg0->unk12++;
    }

    switch (D_803D5530->state) {                        /* switch 1; irregular */
    case 0x3:                                       /* switch 1 */
    case 0x6:                                       /* switch 1 */
    case 0x8E:                                      /* switch 1 */
    case 0x90:                                      /* switch 1 */
    case 0xB6:                                      /* switch 1 */
    case 0xB9:                                      /* switch 1 */
        var_a1 = ((D_80152C78[(s16)arg2 & 0xFF] >> 7) / 20);
        break;
    case 0x4:                                       /* switch 1 */
    case 0x8F:                                      /* switch 1 */
    case 0xB7:                                      /* switch 1 */
        var_a1 = ((D_80152C78[(s16)arg2 & 0xFF] >> 7) / 12);
        break;
    default:                                        /* switch 1 */
        var_a1 = 0;
        break;
    }
    switch (arg0->unk10) {
    case 1:
        sp20 = (D_80152C78[((arg0->unk12 << 7) / 100) & 0xFF] >> 7);
        var_t0 = ((sp20 * arg4) >> 0xC);
        if (arg0->unk12 >= 100) {
          arg0->unk10 = 0;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    case 11:
        sp20 = -(D_80152C78[(((arg0->unk12 << 8) / 100) + 0x40) & 0xFF] >> 7);
        var_a1 = (-(sp20 + 256) / 32);
        if (arg0->unk12 >= 100) {
            arg0->unk10 = 0;
        }
        break;
    }

    temp_a3 = var_a1;
    if (arg1 == 7) {
        var_a1 = -var_a1;
    }
    D_80203FE0[arg1].unk0 = D_80203FE0[1].unk0 + arg3;
    D_80203FE0[arg1].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[arg1].unk4 = D_80203FE0[1].unk4 + var_t0;

    func_802C7B18_6D91C8(&D_80203FE0[arg1], var_a1);

    D_80203FE0[arg1+1].unk0 = D_80203FE0[arg1].unk0;
    D_80203FE0[arg1+1].unk2 = D_80203FE0[arg1].unk2 + ((s32) (arg4 * temp_a3) / 32);
    D_80203FE0[arg1+1].unk4 = (D_80203FE0[arg1].unk4 - arg4) + var_t0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320828_731ED8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320B04_7321B4.s")
// void func_80320B04_7321B4(s16 arg0, s16 arg1) {
//     s16 temp_t6;
//     s32 temp_a3;
//     s32 temp_t0;
//     u8 temp_t1;
//     u8 temp_t4;
//     s16 phi_v0;
//
//     if (D_803D5530->unk4A != 0) {
//         phi_v0 = 0;
//     } else {
//         temp_t4 = (D_803D5540 << 4);
//         if ((temp_t4 == 0) || (temp_t4 == 0x80)) {
//             D_803D553A = 3;
//         }
//         phi_v0 = D_803D5540;
//     }
//
//     temp_a3 = phi_v0 << 4;
//     temp_t0 = temp_a3 + 1;
//
//     D_80203FE0[7].unk0 = D_80203FE0[1].unk0 + arg0;
//     D_80203FE0[10].unk0 = D_80203FE0[1].unk0 - arg0;
//
//     D_80203FE0[7].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[7].unk4 = D_80203FE0[1].unk4;
//
//     D_80203FE0[8].unk0 = D_80203FE0[7].unk0;
//     D_80203FE0[8].unk2 = D_80203FE0[7].unk2 + (((D_80152C78[temp_t0 & 0xFF] >> 7) * arg1) >> 8);
//
//     temp_t6 = D_80152C78[(temp_t0 + 64) & 0xFF];
//     D_80203FE0[8].unk4 = D_80203FE0[7].unk4 + (((temp_t6 >> 7) * arg1) >> 8);
//
//     D_80203FE0[10].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[10].unk4 = D_80203FE0[1].unk4;
//
//     temp_t1 = temp_a3 + 128;
//     D_80203FE0[11].unk0 = D_80203FE0[10].unk0;
//     D_80203FE0[11].unk2 = D_80203FE0[10].unk2 + (((D_80152C78[temp_t1 & 0xFF] >> 7) * arg1) >> 8);
//     D_80203FE0[11].unk4 = D_80203FE0[10].unk4 + (((D_80152C78[(temp_t1 + 64) & 0xFF] >> 7) * arg1) >> 8);
// }

#ifdef NON_MATCHING
void func_80320C84_732334(s16 arg0, s16 arg1) {
    s16 temp_v0;
    s16 temp_a2;

    // regalloc nonsense
    temp_v0 = ((D_80152C78[((s16)(((D_803D5540 * 12) + 105) & 0xFFFFFFFFFFFFFFFF)) & 0xFF] >> 7) >> 4) + 80;
    temp_a2 = ((D_80152C78[((s16)((D_803D5540 * 12) + 190)) & 0xFF] >> 7) >> 4) + 80;

    D_80203FE0[7].unk0 = D_80203FE0[1].unk0 + arg0;
    D_80203FE0[7].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[7].unk4 = D_80203FE0[1].unk4;

    D_80203FE0[10].unk0 = D_80203FE0[1].unk0 - arg0;
    D_80203FE0[10].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[10].unk4 = D_80203FE0[1].unk4;

    D_80203FE0[8].unk0 = D_80203FE0[7].unk0;
    D_80203FE0[8].unk2 = D_80203FE0[7].unk2 + (((D_80152C78[temp_v0 & 0xFF] >> 7) * arg1) >> 8);
    D_80203FE0[8].unk4 = D_80203FE0[7].unk4 + (((D_80152C78[(temp_v0 + 64) & 0xFF] >> 7) * arg1) >> 8);

    D_80203FE0[11].unk0 = D_80203FE0[10].unk0;
    D_80203FE0[11].unk2 = D_80203FE0[10].unk2 + (((D_80152C78[temp_a2 & 0xFF] >> 7) * arg1) >> 8);
    D_80203FE0[11].unk4 = D_80203FE0[10].unk4 + (((D_80152C78[(temp_a2 + 64) & 0xFF] >> 7) * arg1) >> 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320C84_732334.s")
#endif

void func_80320DF8_7324A8(s16 arg0, s16 arg1) {
    D_80203FE0[3].unk0 = D_80203FE0[1].unk0 - arg0;
    D_80203FE0[3].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[3].unk4 = D_80203FE0[1].unk4;
    D_80203FE0[4].unk0 = D_80203FE0[1].unk0 + arg0;
    D_80203FE0[4].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[4].unk4 = D_80203FE0[1].unk4;
    D_80203FE0[7].unk0 = D_80203FE0[3].unk0;
    D_80203FE0[7].unk2 = D_80203FE0[3].unk2 + arg1;
    D_80203FE0[7].unk4 = D_80203FE0[3].unk4;
    D_80203FE0[10].unk0 = D_80203FE0[4].unk0;
    D_80203FE0[10].unk2 = D_80203FE0[4].unk2 + arg1;
    D_80203FE0[10].unk4 = D_80203FE0[4].unk4;
}

#if 0
void func_80320E70_732520(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    u16 temp_t1;
    u16 sp36;
    s16 sp34;
    s16 sp30;

    temp_t1 = D_803D552C->unk2F2;

    switch (D_803D5530->state) {
    case 0x3:
    case 0x6:
    case 0xB6:
    case 0xB9:
        sp34 = (D_803D552C->unk2F6 + 0x80) & 0xFF;
        sp36 = D_803D552C->unk2F6 & 0xFF;
        break;
    case 0x4:
    case 0xB7:
        sp34 = (D_803D552C->unk2F6 + 0x80) & 0xFF;
        sp36 = D_803D552C->unk2F6 & 0xFF;
        break;
    case 0x8D:
        D_803D552C->unk30E = (D_803D552C->unk30E + 1) & 0xFF;
        sp34 = sp36 = D_803D552C->unk30E;
        break;
    case 0x8F:
        D_803D552C->unk30E = (D_803D552C->unk30E + 9) & 0xFF;
        sp34 = sp36 = D_803D552C->unk30E;
        break;
    case 0x90:
        D_803D552C->unk30E = (D_803D552C->unk30E - 5) & 0xFF;
        sp34 = sp36 = D_803D552C->unk30E;
        break;
    case 0x8E:
        D_803D552C->unk30E = (D_803D552C->unk30E + 5) & 0xFF;
        sp34 = sp36 = D_803D552C->unk30E;
        break;
    default:
        sp34 = temp_t1;
        sp36 = temp_t1;
        break;
    }
    func_80321224_7328D4(&D_803D5528->unk370, 3, 7,  sp36, arg0, arg1, arg2);
    func_80321224_7328D4(&D_803D5528->unk384, 4, 10, sp34, arg0, arg1, arg3);

    switch (D_803D5530->state) {
    case 0x8D:
    case 0x8E:
    case 0x8F:
    case 0x90:
        // take copy of D_803F2ECC
        sp30 = D_803F2ECC;
        func_802DB8DC_6ECF8C();
        D_803F2ECC = 32;
        if (sp36 < 85) {
            func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B555C_7C6C0C);
            D_803F2ECC = (sp36 << 5) / 85;
            func_802DB8DC_6ECF8C();
            func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B5574_7C6C24);
        } else if (sp36 < 0xAA) {
            func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B5574_7C6C24);
            D_803F2ECC = ((sp36 << 5) - (85 << 5)) / 85;
            func_802DB8DC_6ECF8C();
            func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B558C_7C6C3C);
        } else {
            func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B558C_7C6C3C);
            D_803F2ECC = ((sp36 << 5) - (85 << 6)) / 85;
            func_802DB8DC_6ECF8C();
            func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B555C_7C6C0C);
        }
        // restore D_803F2ECC
        D_803F2ECC = sp30;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320E70_732520.s")
#endif

void func_80321224_7328D4(void *arg0, u16 arg1, u16 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s16 tmp[6]; // ??
    s16 phi_v1;

    D_80203FE0[arg2].unk0 = D_80203FE0[arg1].unk0;
    D_80203FE0[arg2].unk2 = D_80203FE0[arg1].unk2 + (((D_80152C78[arg6 & 0xFF] >> 7) * arg4) >> 8);
    D_80203FE0[arg2].unk4 = D_80203FE0[arg1].unk4 - (((D_80152C78[(arg6 + 64) & 0xFF] >> 7) * arg4) >> 8);

    D_80203FE0[arg2 + 1].unk0 = D_80203FE0[arg2].unk0;
    D_80203FE0[arg2 + 1].unk2 = D_80203FE0[arg2].unk2 + (((D_80152C78[arg6 & 0xFF] >> 7) * arg5) >> 8);
    D_80203FE0[arg2 + 1].unk4 = D_80203FE0[arg2].unk4 - (((D_80152C78[(arg6 + 64) & 0xFF] >> 7) * arg5) >> 8);

    phi_v1 = ((func_802B8C50_6CA300(D_80203FE0[arg2 + 1].unk0, D_80203FE0[arg2 + 1].unk2) >> 16) << 5) - D_80203FE0[arg2 + 1].unk4;
    phi_v1 = MAX(0, phi_v1);
    phi_v1 = MIN(arg5, phi_v1);

    D_80203FE0[arg2 + 1].unk4 += phi_v1;
    D_80203FE0[arg2 + 1].unk2 -= phi_v1 >> 1;
}
