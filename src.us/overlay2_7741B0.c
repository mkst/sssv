#include <ultra64.h>
#include "common.h"


s32 func_80362B00_7741B0(Animal *a) {
    if ((a->unk4A != 0) || (a->unk366 == 5) || (a->unk366 == 2)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362B38_7741E8(Animal *a) {
    if (a->unk16C->unkA0 & 4) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362B60_774210(Animal *a) {
    s32 tmp = a->unk162 & 0xF;
    if ((tmp == 4) || (tmp == 5) || (tmp == 6) || (tmp == 7)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362B9C_77424C(Animal *a) {
    if ((a->unk16C->unkA0 & 0xC00) != 0) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362BC4_774274(Animal *a) {
    if ((a->unk16C->unk9E & 0xE0) != 0) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362BEC_77429C(Animal *a) {
    if (a->unk162 == 2) {
        return 1;
    } else {
        return 0;
    }
}

void func_80362C10_7742C0(Animal *arg0) {
    if (func_80305084_716734(arg0->xPos - arg0->unk2A4, arg0->zPos - arg0->unk2A6, arg0->unk2D4, arg0->unk2D8) > 100) {
        if (arg0->unk2DC == 0) {
            arg0->unk275 = 10;
            arg0->unk2D4 = arg0->xPos - arg0->unk2A4;
            arg0->unk2D8 = arg0->zPos - arg0->unk2A6;
            arg0->unk2DC = 1;
        } else {
            arg0->unk2A0 = 6;
            arg0->unk275 = -1;
            arg0->unk2DC = 0;
        }
    }
}

// contains jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80362CC4_774374.s")
// contains jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_803633C4_774A74.s")

void func_80363738_774DE8(Animal *arg0, Animal *arg1, u16 arg2) {
    if (arg0->unk320 == 0) {
        arg0->unk28E = 0;
        arg0->unk28C = 9;
        arg0->unk298 = arg2;
        arg0->unk294.w = arg1;
        func_80363DB4_775464(arg0, arg1, -1, arg2);
    } else {
        func_803638E8_774F98(arg0);
    }
}

void func_8036379C_774E4C(Animal *arg0) {
    arg0->unk28C = 10;
    arg0->unk290 = 0;
    func_8037B784_78CE34(arg0);
    arg0->unk2AC = arg0->unk320;
}

void func_803637D4_774E84(Animal *arg0, Animal *arg1, u16 arg2) {
    arg0->unk28C = 8;
    arg0->unk298 = arg2;
    arg0->unk294.w = arg1;
    arg0->unk29A.b = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    func_80363CC8_775378(arg0);
    func_80309E4C_71B4FC(arg1);
    arg0->unk270 = 1;
}

void func_80363844_774EF4(Animal *arg0, s16 arg1) {
    arg0->unk28C = 6;
    arg0->unk294.h[0] = arg1;
    func_80363FB8_775668(arg0, arg1, -0x80, -1);
}

void func_80363880_774F30(Animal *arg0, Animal *arg1) {
    arg0->unk28C = 7;
    arg0->unk294.w = arg1;
    func_80363E88_775538(arg0, arg1);
}

void func_803638A8_774F58(Animal *arg0, Animal *arg1, s16 arg2) {
    arg0->unk28C = 5;
    arg0->unk294.w = arg1;
    arg0->unk298 = arg2;
    func_80363DB4_775464(arg0, arg1, -1, arg2);
}

void func_803638E8_774F98(Animal *arg0) {
    arg0->unk28C = 0;
    arg0->unk2CC = 0;
    func_80363CC8_775378(arg0);
}

// these two have weird offsets on unk294
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_8036390C_774FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80363A0C_7750BC.s")

void func_80363B34_7751E4(Animal *arg0, u16 arg1) {
    arg0->unk28C = 3;
    arg0->unk294.b[0] = arg1;
    func_80363C48_7752F8(arg0, arg0->xPos, arg0->zPos, -1, 10, 32);
    arg0->unk290 = func_8012826C() & 3;
}

void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5) {
    arg0->unk28C = 2;
    arg0->unk294.h[1] = xPos;
    arg0->unk298 = zPos;
    arg0->unk29A.h = arg3;
    arg0->unk294.b[0] = arg4;
    arg0->unk294.b[1] = arg5;
    func_80363C48_7752F8(arg0, xPos, zPos, arg3, arg4, arg5);
}

void func_80363C0C_7752BC(Animal *arg0, u8 arg1) {
    arg0->unk28C = 4;
    arg0->unk28E = 1;
    arg0->unk290 = 30;
    arg0->unk294.b[0] = arg1;
    func_80363CC8_775378(arg0);
}

void func_80363C48_7752F8(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5) {
    arg0->unk2A0 = 1;
    arg0->unk2A4 = xPos;
    arg0->unk2A6 = zPos;
    arg0->unk2A8 = arg3;
    arg0->unk2A1 = arg4;
    arg0->unk2A2 = arg5;
    arg0->unk2AC = 0;
    arg0->unk274 = 2;
    arg0->unk275 = arg4;
    arg0->unk278 = xPos;
    arg0->unk27A = zPos;
    arg0->unk27C = arg3;
    arg0->unk2D4 = arg0->xPos - xPos;
    arg0->unk2D8 = arg0->zPos - zPos;
    arg0->unk2DC = 0;
}

void func_80363CC8_775378(Animal *arg0) {
    arg0->unk2A0 = 0;
    arg0->unk2A1 = 0;
    arg0->unk2AC = 0;
    arg0->unk274 = 0;
    arg0->unk275 = 0;
}

void func_80363CE0_775390(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3) {
    arg0->unk2A8 = arg2;
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 2;
    arg0->unk2B0 = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg1->xPos;
    arg0->unk27A = arg1->zPos;
    if (func_80362BC4_774274(arg1) || func_80362B60_774210(arg1)) {
        arg0->unk27C = arg1->yPos + (arg1->unk42 >> 1) + arg2;
    } else {
        arg0->unk27C = arg2;
    }
    arg0->unk274 = 2;
    arg0->unk275 = arg3;
}

void func_80363DB4_775464(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3) {
    arg0->unk2A8 = arg2;
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 8;
    arg0->unk2B0 = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg1->xPos;
    arg0->unk27A = arg1->zPos;
    if (func_80362BC4_774274(arg1) || func_80362B60_774210(arg0->unk2AC)) {
        arg0->unk27C = arg1->yPos + (arg1->unk42 >> 1) + arg2;
    } else {
        arg0->unk27C = arg2;
    }
    arg0->unk274 = 2;
    arg0->unk275 = arg3;
}

void func_80363E88_775538(Animal *arg0, Animal *arg1) {
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 3;
    arg0->unk2B0 = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg1->xPos;
    arg0->unk27A = arg1->zPos;
    arg0->unk274 = 2;
    arg0->unk275 = -1;
}

void func_80363EDC_77558C(Animal *arg0, s16 arg1, Animal *arg2) {
    arg0->unk2A8 = arg1;
    arg0->unk2AC = arg2;
    arg0->unk2A0 = 4;
    arg0->unk2A1 = 16;
    arg0->unk2B0 = arg2 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg2->xPos;
    arg0->unk27A = arg2->zPos;
    arg0->unk274 = 3;
    arg0->unk275 = 16;
    if (func_80362BC4_774274(arg2) || func_80362B60_774210(arg2)) {
        arg0->unk27C = arg2->yPos + (arg2->unk42 >> 1) + arg1;
    } else {
        arg0->unk27C = arg1;
    }
}

void func_80363FB8_775668(Animal *arg0, u16 arg1, s16 arg2, s16 arg3) {
    arg0->unk2A8 = arg2;
    arg0->unk2A1 = arg3;
    arg0->unk2A0 = 5;
    arg0->unk2AC = 0;
    arg0->unk276 = arg1;
    arg0->unk27C = arg2;
    arg0->unk275 = arg3;
    arg0->unk274 = 1;
}

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80363FF0_7756A0.s")
// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80364120_7757D0.s")
