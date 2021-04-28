#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305250_716900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305368_716A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305A70_717120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80305DA4_717454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803064BC_717B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803065F0_717CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803071BC_71886C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309798_71AE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309868_71AF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803098F0_71AFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803099BC_71B06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309ACC_71B17C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309B40_71B1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309BA0_71B250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309C8C_71B33C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309DC4_71B474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309E4C_71B4FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309EDC_71B58C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80309F38_71B5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030A8EC_71BF9C.s")

// jump
void animal_jump(void) {
    if (D_803D5524->unkA2 & 1) {
        if (D_803D5524->unk9E == 2) {
            if ((D_803D5530->unk162 == 1) || (D_803D5530->unk162 == 6)) {
                switch (D_803D5530->state) {
                case 2:
                    func_802A6390_6B7A40();
                    break;
                case 3:
                    func_802A6390_6B7A40();
                    break;
                case 4:
                    func_802A63C0_6B7A70();
                    break;
                default:
                    break;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030AA08_71C0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030AA90_71C140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030AAE0_71C190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030B494_71CB44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030BC50_71D300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030BD50_71D400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030BE20_71D4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030DD34_71F3E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030E208_71F8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030E69C_71FD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030E8AC_71FF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030EA98_720148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030EB88_720238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8030EBF0_7202A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80310030_7216E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803102BC_72196C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80310E10_7224C0.s")

s32 func_80310EE4_722594(s16 x, s16 z, u8 arg2) {
    switch (arg2) {
        case 0:
        case 1:
            return func_8031124C_7228FC(x, z);
        case 2:
            return func_80310F58_722608(x, z);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80310F58_722608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_8031124C_7228FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80311554_722C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80311A2C_7230DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80311AA8_723158.s")
// JUSTREG
// void func_80311AA8_723158(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3) {
//     s16 temp_t7_2;
//     s16 temp_t9_2;
//
//     u8 temp_t0;
//     u8 temp_t1;
//     u8 temp_t2;
//     u8 temp_v1;
//
//     *arg3 = 0;
//     *arg2 = *arg3;
//
//     temp_t7_2 = arg0 >> 6;
//     temp_t9_2 = arg1 >> 6;
//
//     if ((temp_t7_2 >= 0) && (temp_t7_2 < 72)) {
//         if ((temp_t9_2 >= 0) && (temp_t9_2 < 128)) {
//             temp_v1 = D_803C0740_7D1DF0[arg0 >> 6][arg1 >> 6].unk1;
//             temp_t0 = D_803C0740_7D1DF0[arg0 >> 6][(arg1 >> 6)+1].unk1;
//             temp_t1 = D_803C0740_7D1DF0[(arg0 >> 6)+1][(arg1 >> 6)+1].unk1;
//             temp_t2 = D_803C0740_7D1DF0[(arg0 >> 6)+1][arg1 >> 6].unk1;
//
//             if ((D_803C0740_7D1DF0[arg0 >> 6][arg1 >> 6].unk4 & 2) != 0) {
//                 if ((s16)(arg0 & 0x3F) < (s16)(arg1 & 0x3F)) {
//                     *arg2 = (temp_t0 - temp_t1) * 2;
//                     *arg3 = (temp_v1 - temp_t0) * 2;
//                 } else {
//                     *arg2 = (temp_v1 - temp_t2) * 2;
//                     *arg3 = (temp_t2 - temp_t1) * 2;
//                 }
//             } else if (((s16)(arg0 & 0x3F) + (s16)(arg1 & 0x3F)) < 64) {
//                 *arg2 = (temp_v1 - temp_t2) * 2;
//                 *arg3 = (temp_v1 - temp_t0) * 2;
//             } else {
//                 *arg2 = (temp_t0 - temp_t1) * 2;
//                 *arg3 = (temp_t2 - temp_t1) * 2;
//             }
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80311BF8_7232A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80311D48_7233F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80312054_723704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803123A4_723A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803126F4_723DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80312A44_7240F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80312D94_724444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80313064_724714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80313334_7249E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_80313448_724AF8.s")
// s32 func_80313448_724AF8(struct055 *arg0, s32 arg1, s32 arg2, s32 arg3) {
//     D_803E4C94 = arg0;
//
//     D_803E4C52 = *(s16*)&arg0->xPos; // er?
//     D_803E4C54 = *(s16*)&arg0->zPos;
//     D_803E4C5C = arg0->xPos + arg1;
//     D_803E4C60 = arg0->zPos + arg2;
//     D_803E4C64 = arg0->yPos + arg3;
//
//     D_803E4C56 = D_803E4C5C >> 16;
//     D_803E4C58 = D_803E4C60 >> 16;
//     D_803E4C68 = D_803E4C52 >> 6;
//     D_803E4C6A = D_803E4C54 >> 6;
//     D_803E4C6C = D_803E4C6A >> 6;
//     D_803E4C6E = (D_803E4C5C >> 16) >> 6;
//
//     D_803E4C70 = D_803E4C52 & 0x3F;
//     D_803E4C72 = D_803E4C54 & 0x3F;
//     D_803E4C74 = D_803E4C6A & 0x3F;
//     D_803E4C76 = D_803E4C58 & 0x3F;
//
//     D_803E4C7C = D_803D5530->xVelocity.w;
//     D_803E4C80 = D_803D5530->zVelocity.w;
//     D_803E4C78 = arg0->unk160;
//
//     if ((func_8030B494_71CB44() == 0) && (func_8030EA98_720148() == 0)) {
//         D_803E4C94->xPos = D_803E4C5C;
//         D_803E4C94->zPos = D_803E4C60;
//         D_803E4C94->yPos = D_803E4C64;
//         D_803E4C94->unk160 = D_803E4C78;
//         return 1;
//     } else {
//         return 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716900/func_803135FC_724CAC.s")
// JUSTREG
// void func_803135FC_724CAC(Animal *arg0) {
//     s32 temp_t1;
//     s32 temp_t2;
//     s32 temp_v0;
//     s32 phi_a2;
//     s32 phi_a3;
//
//     temp_v0 = arg0->xPos >> 6;
//     if (temp_v0 < 36) {
//         phi_a2 = D_803A5590_7B6C40[temp_v0 - 1];
//         phi_a3 = D_803A5590_7B6C40[temp_v0];
//     } else {
//         phi_a2 = D_803A5590_7B6C40[temp_v0];
//         phi_a3 = D_803A5590_7B6C40[temp_v0 + 1];
//     }
//     temp_t1 = arg0->yPos + arg0->unk42;
//     if ((phi_a2 < temp_t1) || (phi_a3 < temp_t1)) {
//         temp_t2 = (((phi_a3 - phi_a2) * (arg0->xPos - (temp_v0 << 6))) >> 6) + phi_a2;
//         if (temp_t2 < temp_t1) {
//             arg0->yPos = temp_t2 - arg0->unk42;
//             arg0->yVelocity.w = MIN(arg0->yVelocity.w, 0);
//         }
//     }
// }

void func_803136B0_724D60(Animal *arg0) {
    arg0->unk160 = func_803136FC_724DAC(arg0->xPos, arg0->zPos, (arg0->yPos + (arg0->unk42 >> 1)));
}

s32 func_803136FC_724DAC(s16 x, s16 z, s16 y) {
    if (D_803C0740_7D1DF0[x >> 6][z >> 6].unk3 == 0) {
        return 0;
    }
    if ((func_80310F58_722608(x, z) >> 16) < y) {
        return 2;
    } else {
        return 1;
    }
}
