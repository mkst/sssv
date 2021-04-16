#include <ultra64.h>
#include "common.h"


void func_80314660_725D10(void) {
    s16 i;
    for (i = 0; i < 32; i++) {
        D_8023F208[i] = D_803E4CA8[i];
    }
}

Animal *func_803146A8_725D58(Animal *arg0, s16 arg1, u16 arg2) {
    Animal *ret;

    switch (arg1) {
    case 0:
        ret = arg0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        ret = arg0->unk248[arg1];
        break;
    case 8:
        ret = arg0->unk60;
        break;
    case 9:
        ret = D_801DDD8C[gCurrentAnimalIndex].unk0;
        break;
    case 10:
        ret = func_8031540C_726ABC(arg2, 1);
        break;
    case 11:
        ret = func_8031540C_726ABC(arg2, 0);
        break;
    case 12:
        ret = arg0->unk248[0];
        break;
    }
    return ret;
}

void func_80314788_725E38(void) {
    fancy_bzero((u8*)D_803E4CA8, sizeof(D_803E4CA8));
    fancy_bzero((u8*)D_803E4D40, sizeof(D_803E4D40));
    D_803E8E54 = 0;
    D_803E4CA4 = 0;
    D_803E4CA5 = 0;
    D_803E4CA6 = 0;
    D_803E8E56 = 0;
    func_803497DC_75AE8C(); // initialise ...something osd related
    D_803A05B0_7B1C60 = 0x20000;
    D_803A05B4_7B1C64 = D_803A05B0_7B1C60 * 2;
    D_803E4D2C = 0;
    D_803E4D30 = 16;
    D_803E4D38[0] = D_8023F260.unk30;
    D_803E4D38[1] = D_8023F260.unk34;
    D_803E4D28 = 0;
    D_803E4CA0 = 0;
    D_801546E0 = 0x800;
    D_801546D8 = 0x800;
    func_803976E0_7A8D90(); // initialise something...
    D_803E8E57 = 1;
    D_803E8E58 = 1;
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80314874_725F24.s")
// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80314F0C_7265BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_803152A4_726954.s")
// rodata should be correct
// s32 func_803152A4_726954(s32 arg0, u8 arg1, s32 arg2) {
//     switch (arg1) {
//     case 1:
//         arg0 = arg0 + arg2;
//         break;
//     case 2:
//         arg0 = arg0 - arg2;
//         break;
//     case 3:
//         arg0 = arg0 * arg2;
//         break;
//     case 4:
//         arg0 = arg0 / arg2;
//         break;
//     case 5:
//         arg0 = arg0 & arg2;
//         break;
//     case 6:
//         arg0 = arg0 | arg2;
//         break;
//     case 7:
//         arg0 = arg0 % arg2;
//         break;
//     case 8:
//         arg0 = arg0 >> arg2;
//         break;
//     case 9:
//         arg0 = arg0 << arg2;
//         break;
//     case 0:
//         // arg0 = arg0;
//         break;
//     }
//     return arg0;
// }

void func_80315384_726A34(struct069 *arg0, struct069 *arg1) {
    arg1->unk2 = arg0->unk2;
    arg1->unk4 = arg0->unk4;
    arg1->unk6 = arg0->unk6;
    arg1->unk8 = arg0->unk8;
    arg1->unk0 = arg0->unk0;
}

void func_803153B0_726A60(Animal *arg0, struct069 arg1[], u8 arg2) {
    arg0->unk1A8 = arg1;
    arg0->unk19C = arg2;
    arg0->unk1CD = 0;
    arg0->unk1CC = 0;
    arg0->unk248[0] = arg0;
    if (arg1 != 0) {
        func_80315384_726A34(&arg1[arg2], &arg0->unk19E);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_8031540C_726ABC.s")

// delay slot
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80315658_726D08.s")

s32 func_80315870_726F20(s32 arg0, s32 arg1) {
    return 1;
}

void func_80315880_726F30(s16 arg0) {
    func_80315658_726D08(arg0, &func_80315870_726F20, 0);
}

s32 func_803158B4_726F64(Animal *arg0, s16 arg1) {
    if (arg1 == arg0->unk16C->unk0) {
        return 1;
    } else {
        return 0;
    }
}

void func_803158E4_726F94(s16 arg0, s16 arg1) {
    func_80315658_726D08(arg0, &func_803158B4_726F64, arg1);
}

s32 func_80315924_726FD4(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->unk0 >= 256) {
        return 1;
    } else {
        return 0;
    }
}

void func_80315950_727000(s16 arg0) {
    func_80315658_726D08(arg0, &func_80315924_726FD4, 0);
}

s32 func_80315984_727034(Animal *arg0, s16 arg1) {
    if (arg0->unk16C->unk0 < 256) {
        return 1;
    } else {
        return 0;
    }
}

void func_803159B0_727060(s16 arg0) {
    func_80315658_726D08(arg0, &func_80315984_727034, 0);
}

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_803159E4_727094.s")
// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80316408_727AB8.s")

// unsure how correct this is?
void func_803190FC_72A7AC(Animal *arg0) {
    struct070 *phi_s0;
    s8 i;

    phi_s0 = &arg0->unk1AC[0];
    for (i = 0; i < arg0->unk1CD; i++) {
        if (func_803159E4_727094(func_803146A8_725D58(arg0, phi_s0->unk1, 0), phi_s0) != 0) {
            arg0->unk19C = phi_s0->unk6 + 1;
            func_80315384_726A34(arg0->unk1A8 + arg0->unk19C, &arg0->unk19E);
            arg0->unk1CD = 0;
            arg0->unk1D4 = 0;
            return;
        }
        phi_s0 = phi_s0 + 1;
    }
}

void func_803191B0_72A860(Animal *arg0) {
    s8 temp_v0;

    if (arg0->unk1CC == 9) {
        arg0->unk248[0] = D_801DDD8C[gCurrentAnimalIndex].unk0;
    }
    if (arg0->unk1CD != 0) {
        func_803190FC_72A7AC(arg0);
    }

    do {
        temp_v0 = func_80316408_727AB8(arg0);
        if (temp_v0 != 0) {
            arg0->unk19C += 1;
            func_80315384_726A34(arg0->unk1A8 + arg0->unk19C, &arg0->unk19E);
        }
    } while (temp_v0 == 69);
}
