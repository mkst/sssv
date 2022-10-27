#include <ultra64.h>

#include "common.h"


// initialise/reset
void func_8039DD60_7AF410(void) {
    D_803FDEA0 = 0; // structs used = 0
    bzero_sssv((u8*)D_803F7E10, sizeof(D_803F7E10)); // 24720
}

void func_8039DD90_7AF440(u8 *arg0) {
    *arg0 = (*arg0 & 0xFFF0) | 2;
}

// creates a trail (wake?) behind animal?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039DDA4_7AF454.s")
// miles away
// struct045 *func_8039DDA4_7AF454(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, u8 argF, u8 arg10, u8 arg11, s32 arg12) {
//     s32 temp_t9;
//     s8 temp_t5;
//     u8 temp_t8;
//     struct045 *temp_v1;
//     s16 i;
//
//     if (arg12 != 0) {
//         for (i = 0; i < 30; i++) {
//             temp_v1 = &D_803F7E10[i];
//             if ((arg12 == temp_v1->unk4) && ((temp_v1->unk0.uw >> 28) != 0) && ((temp_v1->unk0.ub[0] & 0xF) != 2)) {
//                 temp_v1->unk0.ub[1] = (temp_v1->unk0.ub[1] & 0xFFF0) | 1;
//                 return temp_v1;
//             }
//         }
//     }
//
//     for (i = 0; i < 30; i++) {
//         temp_v1 = &D_803F7E10[i];
//         if ((temp_v1->unk0.uw >> 28) == 0) {
//             temp_v1->unk248 = arg0;
//             temp_t5 = (temp_v1->unk0.ub[0] & 0xFF0F) | 0x10;
//             temp_v1->unk0.ub[0] = temp_t5;
//             temp_v1->unk0.ub[0] =  ((temp_t5 & 0xF0) | 1);
//             temp_t8 = (arg11 * 0x10) | (temp_v1->unk0.ub[1] & 0xFF0F);
//             temp_t9 = temp_t8 & 0xF0;
//             temp_v1->unk0.ub[1] = temp_t8;
//             temp_v1->unk8 = (((arg1 &0xff) * 0x10) | (temp_v1->unk8 & 0xFF0F));
//             temp_v1->unk10 = arg9; // blue
//             temp_v1->unk11 = argA;
//             temp_v1->unk0.ub[1] = temp_t9 | 1;
//             temp_v1->unk242 = arg5;
//             temp_v1->unk240 = arg4;
//             temp_v1->unk244 = arg6;
//             temp_v1->unk13 = argC;
//             temp_v1->unkE = arg7; // red
//             temp_v1->unkF = arg8; // green
//             temp_v1->unk12 = argB;
//             temp_v1->unk14 = argD;
//             temp_v1->unk4 = arg12;
//             temp_v1->unkB = 0;
//             temp_v1->unkC = 0;
//             temp_v1->unkD = arg2;
//             temp_v1->unk17 = 0x80 / (arg3 * arg10);
//             temp_v1->unk18 = arg10;
//             temp_v1->unk15 = argE;
//             temp_v1->unk16 = argF;
//             D_803FDEA0 += 1;
//             return temp_v1;
//         }
//     }
//     return i;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039DFD4_7AF684.s")
// struct045 *func_8039DFD4_7AF684(Animal *arg0 /* a guess */, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, s32 argF) {
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s8 temp_t8;
//     u8 temp_t4;
//     struct045 *temp_v1;
//     s16 i;
//
//     if (argF != 0) {
//         for (i = 0; i < 30; i++) {
//             temp_v1 = &D_803F7E10[i];
//             if ((argF == temp_v1->unk4) && ((temp_v1->unk0.uw >> 0x1C) != 0) && ((temp_v1->unk0.ub[0] & 0xF) != 2)) {
//                 temp_v1->unk0.ub[1] = ((temp_v1->unk0.ub[1] & 0xFFF0) | 1);
//                 return temp_v1;
//             }
//         }
//         if ((arg0->xVelocity | arg0->zVelocity) == 0) {
//             return NULL;
//         }
//     }
//
//     for (i = 0; i < 30; i++) {
//         temp_v1 = &D_803F7E10[i];
//         if (((u32) temp_v1->unk0.uw >> 0x1C) == 0) {
//             temp_v1->unk330 = arg0;
//             temp_t8 = ((u8) temp_v1->unk0.ub[0] & 0xFF0F) | 0x30;
//             temp_v1->unk0.uw = temp_t8;
//             temp_t4 = (argE * 0x10) | (temp_v1->unk0.ub[1] & 0xFF0F);
//             temp_v1->unk0.ub[0] = (s8) ((temp_t8 & 0xF0) | 1);
//             temp_v1->unk32C = arg6;
//             temp_v1->unk0.ub[1] = temp_t4;
//             temp_v1->unkE = arg7;
//             temp_v1->unkF = arg8;
//             temp_v1->unk0.ub[1] = (u8) ((temp_t4 & 0xF0) | 1);
//             temp_v1->unk8 = (u8) (((arg1 & 0xFF) * 0x10) | (temp_v1->unk8 & 0xFF0F));
//             temp_v1->unk328 = arg4;
//             temp_v1->unk11 = argA;
//             temp_v1->unk32A = arg5;
//             temp_v1->unk10 = arg9;
//             temp_v1->unk12 = argB;
//             temp_v1->unk4 = argF;
//             temp_v1->unkB = (u8)0;
//             temp_v1->unkC = (u8)0;
//             temp_v1->unkD = (s8) (arg2 & 0xFF);
//             temp_v1->unk14 = (s8) (0x80 / (s32) (((arg3 & 0xFF) - 2) * argD));
//             D_803FDEA0 = (s16) (D_803FDEA0 + 1);
//             temp_v1->unk15 = argD;
//             temp_v1->unk13 = argC;
//             return temp_v1;
//         }
//     }
//     return (void *) temp_v0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E20C_7AF8BC.s")
// similar to previous
// void *func_8039E20C_7AF8BC(s32 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD) {
//     s32 temp_t8;
//     s8 temp_t7;
//     struct045 *temp_v1;
//     s16 i;
//
//     for (i = 0 ; i < 30; i++) {
//         temp_v1 = &D_803F7E10[i];
//         if ((temp_v1->unk0.uw >> 0x1C) == 0) {
//             temp_t7 = (temp_v1->unk0.ub[0] & 0xFF0F) | 64;
//             temp_t8 = temp_t7 & 0xF0;
//             temp_v1->unk0.ub[0] = temp_t7;
//             temp_v1->unk0.ub[1] = (argD * 0x10) | (temp_v1->unk0.ub[1] & 0xFF0F);
//             temp_v1->unk248 = arg0;
//             temp_v1->unk0.ub[0] = temp_t8 | 1;
//             temp_v1->unk242 = arg5;
//             temp_v1->unk8 = (((arg1 & 0xFF) * 0x10) | (temp_v1->unk8 & 0xFF0F));
//             temp_v1->unk240 = arg4;
//             temp_v1->unk244 = arg6;
//             temp_v1->unk9 = 0;
//             temp_v1->unkA = 0;
//             temp_v1->unkB = arg2;
//             temp_v1->unk12 = arg3;
//             D_803FDEA0 += 1;
//             temp_v1->unkC = arg7;
//             temp_v1->unkD = arg8;
//             temp_v1->unkE = arg9;
//             temp_v1->unkF = argA;
//             temp_v1->unk10 = argB;
//             temp_v1->unk11 = argC;
//             return temp_v1;
//         }
//     }
// }

// grim structs
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E33C_7AF9EC.s")

#ifdef NON_MATCHING
// just the stack
void func_8039E6D4_7AFD84(struct114 *arg0) {
    s16 sp5E;
    s16 sp5C;
    s16 sp5A;
    s16 sp58;
    s16 temp_v0;
    Animal *animal;
    struct077 sp48; // 0x6 big
    s16 pad;
    s16 sp44;
    s16 sp42;
    s16 sp40;
    s32 sp38;
    s32 sp34;

    animal = arg0->unk240;
    sp40 = animal->zRotation;
    sp42 = animal->yRotation;
    sp38 = animal->xVelocity.w >> 8;
    sp34 = animal->zVelocity.w >> 8;

    if (sp38 | sp34) {
        sp44 = func_801284B8(
            -animal->yVelocity.w >> 8,
            sqrtf((sp38 * sp38) + (sp34 * sp34)));
        temp_v0 = func_801284B8(sp38, sp34);

        if (animal->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
            // it's an animal
            sp42 = (sp42 * 360) / 256;
            sp40 = (sp40 * 360) / 256;
        }

        switch (arg0->unk0.state) {
        case 0:
            sp5E = (D_80152350.unk384[temp_v0] * arg0->unk5) >> 8;
            sp5C = (-D_80152350.unk2D0[temp_v0] * arg0->unk5) >> 8;
            sp5A = 0;
            break;
        case 1:
            func_802F5F44_7075F4(0, 0, arg0->unk5, 360 - sp44, temp_v0, &sp48);

            sp5E = sp48.unk0;
            sp5C = sp48.unk2;
            sp5A = sp48.unk4;
            break;
        case 2:
            sp58 = (D_80152C78[(arg0->unk4 + 0x40) & 0xFF] * arg0->unk5) >> 0xF;

            sp5A = (-D_80152C78[arg0->unk4 & 0xFF] * arg0->unk5) >> 0xF;
            sp5E = (D_80152350.unk384[temp_v0] * sp58) >> 8;
            sp5C = (D_80152350.unk2D0[temp_v0] * -sp58) >> 8;
            break;
        case 3:
            sp58 = ((D_80152C78[(arg0->unk4 + 0x40) & 0xFF] * arg0->unk5) >> 0xF);

            sp5A = (-D_80152C78[arg0->unk4 & 0xFF] * arg0->unk5) >> 0xF;
            sp5E = (D_801526D4[(s16) ((s32)func_80128200() % 360)] * sp58) >> 8;
            sp5C = (D_80152620[(s16) ((s32)func_80128200() % 360)] * -sp58) >> 8;
            break;
        default:
            break;
        }
    } else {
        sp5A = sp5C = sp5E = 0;
    }

    func_802F5F44_7075F4(arg0->unk238, arg0->unk23A, arg0->unk23C + (animal->unk42 >> 1), sp40, sp42, &sp48);

    arg0->unk38[arg0->unk0.used].unk0 = (animal->xPos.h - sp5E) + sp48.unk0;
    arg0->unk38[arg0->unk0.used].unk2 = (animal->zPos.h - sp5C) + sp48.unk2;
    arg0->unk38[arg0->unk0.used].unk4 = (animal->yPos.h - sp5A) + sp48.unk4;

    arg0->unk38[arg0->unk0.used+1].unk0 = animal->xPos.h + sp5E + sp48.unk0;
    arg0->unk38[arg0->unk0.used+1].unk2 = animal->zPos.h + sp5C + sp48.unk2;
    arg0->unk38[arg0->unk0.used+1].unk4 = animal->yPos.h + sp5A + sp48.unk4;

    if ((arg0->unk0.used >> 1) & 1) {
        // odd
        arg0->unk38[arg0->unk0.used].unk8 = 0x7FF;
        arg0->unk38[arg0->unk0.used].unkA = 0;

        arg0->unk38[arg0->unk0.used+1].unk8 = 0x7FF;
        arg0->unk38[arg0->unk0.used+1].unkA = 0x7FF;
    } else {
        // even
        arg0->unk38[arg0->unk0.used].unk8 = 0;
        arg0->unk38[arg0->unk0.used].unkA = 0;

        arg0->unk38[arg0->unk0.used+1].unk8 = 0;
        arg0->unk38[arg0->unk0.used+1].unkA = 0x7FF;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E6D4_7AFD84.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039EBFC_7B02AC.s")
