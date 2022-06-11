#include <ultra64.h>
#include "common.h"

#include "structs.h"
#include "variables.us.h"


void func_80320828_731ED8(struct103 *arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4);

// needs some help...
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_8031FC30_7312E0.s")
// void func_8031FC30_7312E0(struct103 *arg0, u16 arg1, u16 arg2, s16 arg3, s16 arg4, s16 arg5) {
//     s32 pad;
//     s16 sp24;
//
//     switch (D_803D5530->state)
//     {
//     case 0x3:
//     case 0x6:
//     case 0x8E:
//     case 0x90:
//     case 0xB6:
//     case 0xB9:
//         sp24 = (D_80152C78[arg2 & (0xFF)] >> 7) / 10;
//         break;
//     case 0x4:
//     case 0x8F:
//     case 0xB7:
//         sp24 = (D_80152C78[arg2 & 0xFF] >> 7) / 6;
//         break;
//     default:
//         sp24 = 0;
//         break;
//     }
//
//     switch (arg0->unk10)
//     {
//     case 1:
//     case 2:
//     case 3:
//     case 4:
//     case 5:
//     case 6:
//     case 7:
//     case 8:
//     case 9:
//     case 10:
//     case 11:
//         break;
//     }
//
//
//     if ((s16)arg1 == 7) {
//         sp24 = -sp24;
//     }
//
//     D_80203FE0[arg1].unk0 = D_80203FE0[1].unk0 + arg3;
//     D_80203FE0[arg1].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[arg1].unk4 = D_80203FE0[1].unk4;
//
//     func_802C7B18_6D91C8(&D_80203FE0[arg1], arg1); // wrong? should be sp24 ?
//
//     D_80203FE0[arg1 + 1].unk0 = D_80203FE0[arg1].unk0;
//     D_80203FE0[arg1 + 1].unk2 = D_80203FE0[arg1].unk2;
//     D_80203FE0[arg1 + 1].unk4 = D_80203FE0[arg1].unk4 - arg4;
//
//     D_80203FE0[arg1 + 2].unk0 = D_80203FE0[arg1 + 1].unk0;
//     if (sp24 < 0) {
//         sp24 = 0;
//     }
//     D_80203FE0[arg1 + 2].unk2 = D_80203FE0[arg1 + 1].unk2 + ((arg5 * sp24) / 64);
//     D_80203FE0[arg1 + 2].unk4 = D_80203FE0[arg1 + 1].unk4 - arg5;
// }

void func_8032018C_73183C(struct103 *arg0, u16 arg1, u16 arg2, u16 arg3, s32 arg4, s32 arg5, s32, s32, s32, s8);

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_8031FE40_7314F0.s")
// more of the same
// void func_8031FE40_7314F0(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
//     u16 sp34;
//     u16 sp30; // pad
//     u16 temp_v1;
//     s8 phi_t0;
//     u16 phi_a3;
//
//     temp_v1 = D_803D552C->unk2F2;
//
//     switch (D_803D5530->state) {                        /* implicit */
//     case 0x3:
//     case 0x8E:
//     case 0xB6:
//         phi_a3 = D_803D552C->unk2F6 % 256;
//         sp34 = ((D_803D552C->unk2F6 + 128) % 256);
//         phi_t0 = 1;
//         break;
//     case 0x6:
//     case 0x90:
//     case 0xB9:
//         phi_a3 = 256 - (D_803D552C->unk2F6 % 256);
//         sp34 = 256 - ((D_803D552C->unk2F6 + 128) % 256);
//         phi_t0 = 1;
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
//         sp34 = temp_v1;
//         phi_a3 = temp_v1;
//         break;
//     }
//     if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
//         if ((D_803D5530->unk162 == 4) ||
//             (D_803D5530->unk162 == 5) ||
//             (D_803D5530->unk162 == 6) ||
//             (D_803D5530->unk162 == 7)) {
//             phi_a3 = (D_803D552C->unk2F6 << 4) & 0xFF;
//             sp34 = ((D_803D552C->unk2F6 << 4) + 128) & 0xFF;
//             phi_t0 = 2;
//         }
//     } else {
//         if ((D_803D5530->unk162 == 4) ||
//             (D_803D5530->unk162 == 5) ||
//             (D_803D5530->unk162 == 7)) {
//             switch (D_803D5530->state) {
//             case 0x8E:
//                 sp34 = (D_803D552C->unk2F6 + 128) & 0xFF;
//                 phi_a3 = D_803D552C->unk2F6 & 0xFF;
//                 phi_t0 = 2;
//                 break;
//             case 0x8F:
//                 sp34 = ((D_803D552C->unk2F6 << 1) + 128) & 0xFF;
//                 phi_a3 = (D_803D552C->unk2F6 << 1) & 0xFF;
//                 phi_t0 = 2;
//                 break;
//             case 0x90:
//                 sp34 = 256 - ((D_803D552C->unk2F6 + 128) & 0xFF);
//                 phi_a3 = (256 - (D_803D552C->unk2F6 & 0xFF));
//                 phi_t0 = 2;
//                 break;
//             default:
//                 sp34 = (D_803D552C->unk2F6 + 128) & 0xFF;
//                 phi_a3 = D_803D552C->unk2F6 & 0xFF;
//                 phi_t0 = 2;
//                 break;
//             }
//         }
//     }
//     func_8032018C_73183C(&D_803D5528->unk370, 3, 7, phi_a3, arg0, arg1, arg2, arg3, arg4, phi_t0);
//     func_8032018C_73183C(&D_803D5528->unk384, 4, 10,  sp34, arg0, arg1, arg2, arg3, arg4, phi_t0);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_8032018C_73183C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320828_731ED8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320C84_732334.s")
// void func_80320C84_732334(s16 arg0, s16 arg1) {
//     s16 temp_a2;
//     s16 temp_v0;
//
//     temp_v0 = ((D_80152C78[((D_803D5540 * 12)+105) & 0xFF] >> 7) >> 4) + 80;
//     temp_a2 = ((D_80152C78[((D_803D5540 * 12)+85) & 0xFF] >> 7) >> 4) + 80;
//
//     D_80203FE0[7].unk0 = D_80203FE0[1].unk0 + arg0;
//     D_80203FE0[10].unk0 = D_80203FE0[1].unk0 - arg0;
//
//     D_80203FE0[7].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[7].unk4 = D_80203FE0[1].unk4;
//
//     D_80203FE0[10].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[10].unk4 = D_80203FE0[1].unk4;
//     D_80203FE0[8].unk0 = D_80203FE0[7].unk0;
//     D_80203FE0[8].unk2 = D_80203FE0[7].unk2 + (((D_80152C78[temp_v0 & 0xFF] >> 7) * arg1) >> 8);
//     D_80203FE0[8].unk4 = D_80203FE0[7].unk4 + (((D_80152C78[(temp_v0 + 64) & 0xFF] >> 7) * arg1) >> 8);
//
//     D_80203FE0[11].unk0 = D_80203FE0[10].unk0;
//     D_80203FE0[11].unk2 = D_80203FE0[10].unk2 + (((D_80152C78[temp_a2 & 0xFF] >> 7) * arg1) >> 8);
//     D_80203FE0[11].unk4 = D_80203FE0[10].unk4 + (((D_80152C78[(temp_a2 + 64) & 0xFF] >> 7) * arg1) >> 8);
// }

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7312E0/func_80320E70_732520.s")
// void func_80320E70_732520(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
//     u16 temp_t1;
//     u16 sp36;
//     u16 sp34;
//     s16 sp30;
//
//     temp_t1 = D_803D552C->unk2F2;
//
//     switch (D_803D5530->state) {
//     case 0x3:
//     case 0x6:
//     case 0xB6:
//     case 0xB9:
//         sp34 = (D_803D552C->unk2F6 + 0x80) & 0xFF;
//         sp36 = D_803D552C->unk2F6 & 0xFF;
//         break;
//     case 0x4:
//     case 0xB7:
//         sp34 = (D_803D552C->unk2F6 + 0x80) & 0xFF;
//         sp36 = D_803D552C->unk2F6 & 0xFF;
//         break;
//     case 0x8D:
//         D_803D552C->unk30E = (D_803D552C->unk30E + 1) & 0xFF;
//         sp34 = sp36 = D_803D552C->unk30E;
//         break;
//     case 0x8F:
//         D_803D552C->unk30E = (D_803D552C->unk30E + 9) & 0xFF;
//         sp34 = sp36 = D_803D552C->unk30E;
//         break;
//     case 0x90:
//         D_803D552C->unk30E = (D_803D552C->unk30E - 5) & 0xFF;
//         sp34 = sp36 = D_803D552C->unk30E;
//         break;
//     case 0x8E:
//         D_803D552C->unk30E = (D_803D552C->unk30E + 5) & 0xFF;
//         sp34 = sp36 = D_803D552C->unk30E;
//         break;
//     default:
//         sp34 = temp_t1;
//         sp36 = temp_t1;
//         break;
//     }
//     func_80321224_7328D4(D_803D5528->unk370, 3, 7,  sp36, arg0, arg1, arg2);
//     func_80321224_7328D4(D_803D5528->unk384, 4, 10, sp34, arg0, arg1, arg3);
//
//     if ((D_803D5530->state == 0x8D) ||
//         (D_803D5530->state == 0x8E) ||
//         (D_803D5530->state == 0x8F) ||
//         (D_803D5530->state == 0x90)) {
//
//         // take copy of D_803F2ECC
//         sp30 = D_803F2ECC;
//         func_802DB8DC_6ECF8C();
//         D_803F2ECC = 32;
//         if (sp36 < 85) {
//             func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B555C_7C6C0C);
//             D_803F2ECC = (sp36 << 5) / 85;
//             func_802DB8DC_6ECF8C();
//             func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B5574_7C6C24);
//         } else if (sp36 < 0xAA) {
//             func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B5574_7C6C24);
//             D_803F2ECC = ((sp36 << 5) - (85 << 5)) / 85;
//             func_802DB8DC_6ECF8C();
//             func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B558C_7C6C3C);
//         } else {
//             func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B558C_7C6C3C);
//             D_803F2ECC = ((sp36 << 5) - (85 << 6)) / 85;
//             func_802DB8DC_6ECF8C();
//             func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B555C_7C6C0C);
//         }
//         // restore D_803F2ECC
//         D_803F2ECC = sp30;
//     }
// }

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
