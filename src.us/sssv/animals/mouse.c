#include <ultra64.h>
#include "common.h"

#include "structs.h"
#include "variables.us.h"

void func_80320828_731ED8(void *arg0, u16 arg1, s16 arg2, s16 arg3, s16 arg4);


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031C7A0_72DE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031D624_72ECD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031E6A0_72FD50.s")

void func_8031F858_730F08(void) {
    rmonPrintf(D_803BD9A0_7CF050); // "Helimouse is gone\n"
}

void func_8031F87C_730F2C(void) {
    func_8032AAF0_73C1A0(MOUSE2);
}

void func_8031F89C_730F4C(void) {
    func_8032AAF0_73C1A0(MOUSE);
}

void func_8031F8BC_730F6C(void) {
    u16 tmp[7]; // is this a struct?

    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        tmp[3] = func_8012826C();
        tmp[4] = func_8012826C();
        tmp[5] = func_8012826C();
        tmp[6] = func_8012826C();
        func_802D5F4C_6E75FC(
            D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            (tmp[3] & 1) + 25,
            ((tmp[4] & 0x7FFF) * 2) - 40000,
            ((tmp[5] & 0x7FFF) * 2) - 40000,
            0,
            (tmp[6] & 0xF) + 10,
            1, 1, (func_8012826C() & 0xF) + 0xF);
    } else {
        func_8037D994_78F044(16); // not animal id
        tmp[3] = func_8012826C();
        tmp[4] = func_8012826C();
        tmp[5] = func_8012826C();
        tmp[6] = func_8012826C();
        func_802D5F4C_6E75FC(
            D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            (tmp[3] & 1) + 25,
            ((tmp[4] & 0x7FFF) * 2) - 40000,
            ((tmp[5] & 0x7FFF) * 2) - 40000,
            0,
            (tmp[6] & 0xF) + 10,
            1, 1, (func_8012826C() & 0xF) + 0xF);
    }
}

void func_8031FA84_731134(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    func_8032AAF0_73C1A0(RACING_MOUSE_ATTACKING);
    D_803D552C->unk365 = 40;
    D_803D552C->unk32A = D_803D5544;
}

void func_8031FAD8_731188(void) {
    if (D_803D552C->unk365 != 41) {
        if ((D_803D5544 - (u16)D_803D552C->unk32A) >= 8) {
            if (D_803D552C->unk365 != 40) {
                D_803D552C->unk32A = D_803D5544;
            }
            D_803D552C->unk365 = 41;
        }
    }
}

void func_8031FB30_7311E0(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == MOUSE) {
        func_8032AAF0_73C1A0(MOUSE2);
    }
}

void func_8031FB78_731228(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_MOUSE) {
        func_8032AAF0_73C1A0(RACING_MOUSE_ATTACKING);
        D_803D552C->unk365 = 40;
        D_803D552C->unk32A = D_803D5544;
    }
}

void func_8031FBE8_731298(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 16;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031FC30_7312E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031FE40_7314F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8032018C_73183C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8032066C_731D1C.s")
// void func_8032066C_731D1C(s16 arg0, s16 arg1) {
//     u16 sp24;
//     u16 temp_v1;
//     u16 phi_a2;
//
//     temp_v1 = D_803D552C->unk2F2;
//
//     switch (D_803D5530->state) {
//     case 0x90:
//     case 0xB6:
//     case 0xB7:
//     case 0xB9:
//     case 3:
//     case 4:
//     case 6:
//     case 0x8E:
//     case 0x8F:
//         sp24 = ((u16)D_803D552C->unk2F6 + 128) % 256;
//         phi_a2 = ((u16)D_803D552C->unk2F6 % 0x100) & 0xFFFF;
//         break;
//     default:
//         sp24 = temp_v1;
//         phi_a2 = temp_v1 & 0xFFFF;
//     }
//
//     if (D_803D5528->unk394 == 1) {
//         D_803D5528->unk394 = 0;
//     }
//     if (D_803D5528->unk380 == 1) {
//         D_803D5528->unk394 = 1;
//         D_803D5528->unk396 = D_803D5528->unk382;
//     }
//
//     func_80320828_731ED8(&D_803D5528->unk370, 7, phi_a2, arg0, arg1);
//     func_80320828_731ED8(&D_803D5528->unk384, 10, sp24, -arg0, arg1);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_80320828_731ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_80320B04_7321B4.s")
// void func_80320B04_7321B4(s16 arg0, s16 arg1) {
//     s16 temp_a0;
//     s16 temp_a1;
//     s16 temp_a2;
//     s16 temp_t6;
//     s16 temp_v1;
//     s16 temp_v1_2;
//     s32 temp_a3;
//     s32 temp_t0;
//     u8 temp_t1;
//     s32 temp_t4;
//     s16 phi_v0;
//
//     if (D_803D5530->unk4A != 0) {
//         phi_v0 = (u16)0;
//     } else {
//         temp_v1 = D_803D5540;
//         temp_t4 = (temp_v1 * 0x10) & 0xFF;
//         if ((temp_t4 == 0) || (temp_t4 == 0x80)) {
//             D_803D553A = (u16)3;
//         }
//         phi_v0 = temp_v1;
//     }
//
//     temp_a3 = phi_v0 * 0x10;
//     temp_t0 = temp_a3 + 1;
//
//     D_80203FE0[7].unk0 = (D_80203FE0[1].unk0 + arg0);
//     D_80203FE0[10].unk0 = (D_80203FE0[1].unk0 - arg0);
//
//     D_80203FE0[7].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[7].unk4 = D_80203FE0[1].unk4;
//
//     D_80203FE0[8].unk0 = D_80203FE0[7].unk0;
//     D_80203FE0[8].unk2 = D_80203FE0[7].unk2 + (((((D_80152C78[((temp_t0 & 0xFF))]) >> 7) * arg1) >> 8));
//
//     temp_t6 = D_80152C78[(temp_t0 + 64) & 0xFF];
//     D_80203FE0[8].unk4 = D_80203FE0[7].unk4 + (((temp_t6 >> 7) * arg1) >> 8);
//
//     D_80203FE0[10].unk2 = D_80203FE0[1].unk2;
//     D_80203FE0[10].unk4 = D_80203FE0[1].unk4;
//
//
//     temp_t1 = temp_a3 + 0x80;
//     D_80203FE0[11].unk0 = D_80203FE0[10].unk0;
//     D_80203FE0[11].unk2 = D_80203FE0[10].unk2 + ((((D_80152C78[temp_t1 & 0xFF] >> 7) * arg1) >> 8));
//     D_80203FE0[11].unk4 = D_80203FE0[10].unk4 + ((((D_80152C78[(temp_t1 + 64) & 0xFF] >> 7) * arg1) >> 8));
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_80320C84_732334.s")
// void func_80320C84_732334(s32 arg0, s16 arg1) {
//     s16 temp_a2;
//     s16 temp_v0;
//
//     temp_v0 = ((D_80152C78[(((D_803D5540 * 12) + 0x69) & 0xFF)] >> 7) >> 4) + 80;
//     temp_a2 = ((D_80152C78[((D_803D5540 * 12) + 0xBE) & 0xFF] >> 7) >> 4) + 80;
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

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_80320E70_732520.s")

void func_80321224_7328D4(s32 arg0, u16 arg1, u16 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6) {
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
