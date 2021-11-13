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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80362CC4_774374.s")
#if 0
void func_80362CC4_774374(Animal *arg0) {
    s16 sp54;
    s16 sp52;
    s16 sp4C;
    s16 sp48;
    s16 sp46;
    Animal *sp28;
    Animal *temp_t7_2;
    Animal *temp_v0_5;
    s16 temp_v0_3;
    s16 temp_v1;
    s32 temp_t0_2;
    s32 temp_t3;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_v1_3;
    u16 temp_t6;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_t0;
    u8 temp_t1;
    u8 temp_v1_2;
    u8 temp_v1_4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_4;
    u8 phi_v0;
    s16 phi_v1;
    s16 phi_t0;

    // temp_t6 = arg0->unk28C;
    switch (arg0->unk28C) {
    case 1:
        if (arg0->unk2A0 == 0) {
            temp_t8 = (s32) arg0->unk294.h[1] >> 0xC;
            if (temp_t8 > 0) {
                phi_v0 = (((s32) arg0->unk295 < (s32) *arg0->unk29C) ^ 1); // & 0xFF;
            } else {
                phi_v0 = ((s32) arg0->unk295 < 0) & 0xFF;
            }
            if (phi_v0 != 0) {
                if (((u8) arg0->unk294.h[1] & 0xF) == 1) {
                    func_80363CC8_775378(arg0);
                    arg0->unk28C = 0;
                } else if (temp_t8 > 0) {
                    arg0->unk295 = 0;
                } else {
                    arg0->unk295 = (s8) (*arg0->unk29C - 1);
                }
            } else {
                temp_v0 = arg0->unk29C + (arg0->unk295 * 3);
                func_80363C48_7752F8(
                    arg0,
                    (s16) ((temp_v0->unk1 << 6) + 0x20),
                    (s16) ((temp_v0->unk2 << 6) + 0x20),
                    (s16) ((temp_v0->unk3 << 6) + 0x20),
                    (s8) (s32) (s8) arg0->unk298.h,
                    (u8) (s32) arg0->unk297
                    );
                arg0->unk295 = (s8) (arg0->unk295 + ((s32) arg0->unk294.h[1] >> 0xC));
            }
        }
        break;
    // default:
        // return;
    case 2:
        if ((u8) arg0->unk2A0 == 0) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 3:
        if ((u8) arg0->unk2A0 == 0) {
            temp_v1 = arg0->unk290;
            temp_v0_2 = ((u8) arg0->unk294.w * 8) + D_803E93B0;
            temp_a0 = temp_v0_2->unk3;
            temp_t0 = temp_v0_2->unk0;
            temp_t1 = temp_v0_2->unk4;
            temp_a1 = temp_v0_2->unk1;
            temp_t7 = (s32) (temp_a0 - temp_t0) >> 2;
            temp_t3 = (s32) (temp_t1 - temp_a1) >> 2;
            switch (temp_v1) {
            case 0:
                sp54 = temp_t0 + (s16) temp_t7;
                sp52 = temp_a1 + (s16) temp_t3;
                break;
            case 1:
                sp54 = temp_a0 - (s16) temp_t7;
                sp52 = temp_a1 + (s16) temp_t3;
                break;
            case 2:
                sp54 = temp_a0 - (s16) temp_t7;
                sp52 = temp_t1 - (s16) temp_t3;
                break;
            case 3:
                sp54 = temp_t0 + (s16) temp_t7;
                sp52 = temp_t1 - (s16) temp_t3;
                break;
            }

            func_80363C48_7752F8(arg0, (s16) ((sp54 << 6) + 0x20), (s16) ((sp52 << 6) + 0x20), -1, (s8) 0xA, (u8) 0x20);
            arg0->unk290 += 1;
            arg0->unk290 &= 3;
        }
        // Duplicate return node #63. Try simplifying control flow for better match
        break;
    case 4:
        temp_v1_2 = arg0->unk28E;
        if (temp_v1_2 != 0) {
            if (temp_v1_2 == 1) {
                if (arg0->unk290 == 0) {
                    temp_v0_4 = ((u8) arg0->unk294.w * 8) + D_803E93B0;
                    temp_v1_3 = (s32) (((temp_v0_4->unk3 - temp_v0_4->unk0) - 1) << 0x16) >> 0x10;
                    temp_t0_2 = (s32) (((temp_v0_4->unk4 - temp_v0_4->unk1) - 1) << 0x16) >> 0x10;
                    phi_v1 = (s16) temp_v1_3;
                    phi_t0 = (s16) temp_t0_2;
                    if (temp_v1_3 <= 0) {
                        phi_v1 = 1;
                    }
                    if (temp_t0_2 <= 0) {
                        phi_t0 = 1;
                    }
                    sp48 = phi_v1;
                    sp46 = phi_t0;
                    sp4C = (func_8012826C() % (s32) phi_v1) + ((*(D_803E93B0 + ((u8) arg0->unk294.w * 8)) + 1) << 6);
                    func_80363C48_7752F8(arg0, sp4C, (s16) ((func_8012826C() % (s32) phi_t0) + ((*(&D_803E93B1 + ((u8) arg0->unk294.w * 8)) + 1) << 6)), -1, (s8) 0xA, (u8) 0x20);
                    arg0->unk28E = 0;
                } else {
                    arg0->unk290 = arg0->unk290 - 1;
                }
                break;
            }
            // Duplicate return node #63. Try simplifying control flow for better match
            return;
        }
        if ((u8) arg0->unk2A0 == 0) {
            arg0->unk290 = (func_8012826C() & 0x3F) + 0x3C;
            arg0->unk28E = 1;
            func_80363CC8_775378(arg0);
        }
        break;
    case 5:
        if ((u8) arg0->unk2A0 == 0) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 6:
        if (arg0->yRotation == ((s32) (arg0->unk294.h[0] << 8) / 0x168)) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 7:
        temp_v0_5 = arg0->unk294.w;
        if (func_803051F0_7168A0((s16) ((s32) (func_801284B8((s16) (temp_v0_5->xPos - arg0->xPos), (s16) (temp_v0_5->zPos - arg0->zPos)) << 8) / 0x168), arg0->yRotation) < 6) {
            func_803638E8_774F98(arg0);
        }
        break;
    case 8:
        if ((u8) arg0->unk29A.b != 0) {
            arg0->unk294.w = D_801D9ED8.animal[gCurrentAnimalIndex].unk0;
            arg0->unk2AC = D_801D9ED8.animal[gCurrentAnimalIndex].unk0;
            arg0->unk2CC = D_801D9ED8.animal[gCurrentAnimalIndex].unk0;
        }
        if (func_803099BC_71B06C() == 0) {
            func_803638E8_774F98(arg0);
        }
        // Duplicate return node #63. Try simplifying control flow for better match
        break;
    case 9:
        temp_t7_2 = arg0->unk294.w;
        sp28 = temp_t7_2;
        if (temp_t7_2->unk26C != 0) {
            func_803153B0_726A60(arg0, NULL, 0U);
            func_803638E8_774F98(arg0);
        } else {
            // temp_v1_4 = arg0->unk28E;
            switch (arg0->unk28E) {
            case 0:
                if ((u8) arg0->unk2A0 == 0) {
                    if ((sp28->xVelocity.h | sp28->zVelocity.h | sp28->yVelocity.h) == 0) {
                        func_80363E88_775538(arg0, sp28);
                        arg0->unk28E = 1;
                    } else {
                        func_80363DB4_775464(arg0, sp28, -1, arg0->unk298.h);
                    }
                }
                break;
            case 1:
                if (func_803051F0_7168A0((s16) ((s32) (func_801284B8((s16) (sp28->xPos - arg0->xPos), (s16) (sp28->zPos - arg0->zPos)) << 8) / 0x168), arg0->yRotation) < 4) {
                    func_8037B754_78CE04(arg0, arg0->unk294.w);
                    arg0->unk290 = 0;
                    arg0->unk28E = 2;
                }
                break;
            case 2:
                arg0->unk290 += 1;
                if ((s32) arg0->unk290 >= 0x15) {
                    func_803638E8_774F98(arg0);
                }
                break;
            }
        }
        break;
    case 10:
        arg0->unk290 += 1;
        if ((s32) arg0->unk290 >= 0x3D) {
            func_803638E8_774F98(arg0);
        }
        // Duplicate return node #63. Try simplifying control flow for better match
        break;
    }
}
#endif

void func_803633C4_774A74(Animal *arg0) {
    s32 tmp0, tmp1;

    switch (arg0->unk2A0) {
    case 0:
        break;
    case 1:
        if ((ABS(arg0->unk2A4 - arg0->xPos) < arg0->unk2A2) && (ABS(arg0->unk2A6 - arg0->zPos) < arg0->unk2A2)) {
            func_80363CC8_775378(arg0);
        } else {
            func_80362C10_7742C0(arg0);
        }
        break;
    case 2:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801DDD8C[gCurrentAnimalIndex].unk0;
        }
        if (arg0->unk2AC->unk26C != 0) {
            func_80363CC8_775378(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->xPos;
            arg0->unk27A = arg0->unk2AC->zPos;
            if ((func_80362BC4_774274(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = (arg0->unk2AC->yPos + (arg0->unk2AC->unk42 >> 1)) - arg0->unk2A8;
            }
        }
        break;
    case 3:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801DDD8C[gCurrentAnimalIndex].unk0;
        }
        arg0->unk278 = arg0->unk2AC->xPos;
        arg0->unk27A = arg0->unk2AC->zPos;
        break;
    case 4:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801DDD8C[gCurrentAnimalIndex].unk0;
        }
        if (arg0->unk2AC->unk26C != 0) {
            func_80363CC8_775378(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->xPos;
            arg0->unk27A = arg0->unk2AC->zPos;
            if ((func_80362BC4_774274(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = (arg0->unk2AC->yPos + (arg0->unk2AC->unk42 >> 1)) - arg0->unk2A8;
            }
        }
        break;
    case 5:
        break;
    case 6:
        tmp0 = arg0->unk2A4 - arg0->xPos;
        tmp1 = arg0->unk2A6 - arg0->zPos;

        if (func_803051F0_7168A0((func_801284B8(tmp0, tmp1) << 8) / 360, arg0->yRotation) < 6) {
            arg0->unk2A0 = 1;
            arg0->unk275 = arg0->unk2A1;
        }
        break;
    case 7:
        break;
    case 8:
        if (arg0->unk2B0 != 0) {
            arg0->unk2AC = D_801DDD8C[gCurrentAnimalIndex].unk0;
        }
        if (arg0->unk2AC->unk26C != 0) {
            func_80363CC8_775378(arg0);
        } else {
            arg0->unk278 = arg0->unk2AC->xPos;
            arg0->unk27A = arg0->unk2AC->zPos;
            if ((func_80362BC4_774274(arg0->unk2AC) != 0) || ((func_80362B60_774210(arg0->unk2AC) != 0))) {
                arg0->unk27C = ((arg0->unk2AC->yPos + (arg0->unk2AC->unk42 >> 1)) - arg0->unk2A8);
            }
            if (((arg0->unk5C & 5) != 0) && (arg0->unk60 == arg0->unk2AC)) {
                func_80363CC8_775378(arg0);
            }
        }
        break;
    }
}

void func_80363738_774DE8(Animal *arg0, Animal *arg1, u16 arg2) {
    if (arg0->unk320 == 0) {
        arg0->unk28E = 0;
        arg0->unk28C = 9;
        arg0->unk298.h = arg2;
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
    arg0->unk298.h = arg2;
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
    arg0->unk298.h = arg2;
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
// void func_80363A0C_7750BC(Animal *arg0, u8 arg1, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
//     s32 sp2C;
//     s16 temp_t4;
//     s16 temp_v0;
//     s32 temp_a0;
//     s8 temp_t6;
//     void *temp_v1;
//
//     temp_a0 = D_803E8E60[arg1];
//     sp2C = temp_a0;
//     temp_v0 = func_80319B4C_72B1FC(temp_a0, arg0->xPos, arg0->zPos, arg0->yPos);
//     arg0->unk28C = (u16)1;
//     temp_t4 = temp_v0;
//     arg0->unk294.b[0] = (s8) temp_t4;
//     arg0->unk294 = arg1;
//     temp_t6 = (arg3 * 0x10) | (arg0->unk296 & 0xFF0F);
//     arg0->unk294.b[2] = temp_t6;
//     arg0->unk298 = arg2;
//     arg0->unk294.b[2] = (s8) ((arg4 & 0xF) | (temp_t6 & 0xF0));
//     arg0->unk294.b[3] = arg5;
//     arg0->unk29C = sp2C;
//     temp_v1 = sp2C + (temp_t4 * 3);
//     func_80363C48_7752F8(arg0, (s16) ((temp_v1->unk1 << 6) + 0x20), (s16) ((temp_v1->unk2 << 6) + 0x20), (s16) ((temp_v1->unk3 << 6) + 0x20), (?32) arg2, (?32) arg5);
//     arg0->unk294.b[1] += arg3; //(s8) (arg0->unk295 + arg3);
// }

void func_80363B34_7751E4(Animal *arg0, u16 arg1) {
    arg0->unk28C = 3;
    arg0->unk294.b[0] = arg1;
    func_80363C48_7752F8(arg0, arg0->xPos, arg0->zPos, -1, 10, 32);
    arg0->unk290 = func_8012826C() & 3;
}

void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5) {
    arg0->unk28C = 2;
    arg0->unk294.h[1] = xPos;
    arg0->unk298.h = zPos;
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

void func_80363FF0_7756A0(Animal *arg0) {
    switch (arg0->unk28C) {
    case 0:
        func_803638E8_774F98(arg0);
        break;
    case 1:
        func_80363A0C_7750BC(arg0, arg0->unk294.ub[0], arg0->unk298.ub[0], (s8)(arg0->unk294.h[1] >> 12), arg0->unk294.ub[2] & 0xF, arg0->unk294.ub[3]);
        break;
    case 2:
        func_80363B98_775248(arg0, arg0->unk294.h[1], arg0->unk298.h, arg0->unk29A.h, arg0->unk294.b[0], arg0->unk294.ub[1]);
        break;
    case 3:
        func_80363B34_7751E4(arg0, arg0->unk294.ub[0]);
        break;
    case 4:
        func_80363C0C_7752BC(arg0, arg0->unk294.ub[0]);
        break;
    case 5:
        func_803638A8_774F58(arg0, arg0->unk294.w, arg0->unk298.h);
        break;
    case 6:
        func_80363844_774EF4(arg0, arg0->unk294.h[0]);
        break;
    case 7:
        func_80363880_774F30(arg0, arg0->unk294.w);
        break;
    case 8:
        func_803637D4_774E84(arg0, arg0->unk294.w, arg0->unk298.h);
        break;
    case 9:
        func_80363738_774DE8(arg0, arg0->unk294.w, arg0->unk298.h);
        break;
    case 10:
        func_803638E8_774F98(arg0);
        break;
    }
}

void func_80364120_7757D0(u8 arg0, s16 arg1, s16 arg2, Animal *arg3) {
    // skill A
    if (arg0 == 0) {
        switch (D_803D5524->unk9C) {
        case SEAGULL:
            break;
        case LION:
            animal_jump();
            break;
        case HIPPO:
            hippo_spit(0, 0, 0);
            break;
        case RACING_DOG:
            racing_dog_turbo(arg1);
            break;
        case FLYING_DOG:
            flying_dog_fire_gun(0, 0, 0);
            break;
        case FOX:
            fox_warp();
            break;
        case FROG:
            animal_jump();
            break;
        case RABBIT:
            animal_jump();
            break;
        case KING_RAT:
            king_rat_fart(60);
            break;
        case PARROT:
            parrot_fly();
            break;
        case MOUSE:
            animal_jump();
            break;
        case RACING_MOUSE:
            racing_mouse_turbo(arg1);
            break;
        case MOUSE2:
            animal_jump();
            break;
        case RACING_FOX:
            fox_warp();
            break;
        case RACING_TORTOISE:
            racing_tortoise_turbo(arg1);
            break;
        case PIRANA:
            animal_jump();
            break;
        case DOG:
            animal_jump();
            break;
        case RAT:
            rat_drop_mine();
            break;
        case SHEEP:
            animal_jump();
            break;
        case RAM:
            animal_jump();
            break;
        case SPRINGY_THINGY:
            animal_jump();
            break;
        case SPRINGY_RAM:
            animal_jump();
            break;
        case PENGUIN:
            animal_jump();
            break;
        case POLAR_BEAR:
            polar_bear_jump_thump();
            break;
        case POLAR_TANK:
            polar_tank_fire_cannon();
            break;
        case HUSKY:
            animal_jump();
            break;
        case SKI_HUSKY:
            ski_husky_turbo(arg1);
            break;
        case WALRUS:
            walrus_turbo(arg1);
            break;
        case CAMEL:
            animal_jump();
            break;
        case CANNON_CAMEL:
            func_8036F740_780DF0(D_803D5530->yRotation);
            break;
        case POGO_KANGAROO:
            animal_jump();
            break;
        case BOXING_KANGAROO:
            animal_jump();
            break;
        case DESERT_FOX:
            animal_jump();
            break;
        case ARMED_DESERT_FOX:
            animal_jump();
            break;
        case SCORPION:
            func_803791AC_78A85C();
            break;
        case GORILLA:
            animal_jump();
            break;
        case ELEPHANT:
            func_8037D268_78E918(arg1);
            break;
        case HYENA:
            animal_jump();
            break;
        case HYENA_BIKER:
            func_8035A5A4_76BC54(arg1);
            break;
        case CHAMELEON:
            func_8035C10C_76D7BC();
            break;
        case COOL_COD:
            break;
        }
    } else {
        // skill B
        switch (D_803D5524->unk9C) {
        case SEAGULL:
        case LION:
            lion_roar();
            break;
        case HIPPO:
            drop_sticky_mine();
            break;
        case RACING_DOG:
            racing_dog_fire_missile(arg3);
            break;
        case FLYING_DOG:
            flying_dog_drop_bomb(0, 0, 0);
            break;
        case FOX:
            func_802E88C0_6F9F70(arg1);
            break;
        case FIRE_FOX:
            fire_fox_fire_missile(arg3);
            break;
        case FROG:
            frog_croak();
            break;
        case POLAR_BEAR_DEFENDING:
            func_80368D60_77A410(arg1);
            break;
        case RABBIT:
            func_803021A8_713858();
            break;
        case HELI_RABBIT:
            heli_rabbit_drop_bomb(0, 0, 0);
            break;
        case MOUSE:
            func_8031FB30_7311E0(arg1);
            break;
        case RACING_MOUSE:
            func_8031FB78_731228(arg1);
            break;
        case MOUSE2:
            func_8031FB30_7311E0(arg1);
            break;
        case BEAR:
            func_80327B94_739244(arg1);
            break;
        case RACING_FOX:
            func_802E88C0_6F9F70(arg1);
            break;
        case TORTOISE_TANK:
            func_803562C8_767978(arg1);
            break;
        case RACING_TORTOISE:
            func_80356348_7679F8(arg1);
            break;
        case PIRANA:
            func_80382CC0_794370(arg1);
            break;
        case DOG:
            dog_bite();
            break;
        case RAT:
            rat_bite();
            break;
        case SHEEP:
            func_8037FEDC_79158C();
            break;
        case RAM:
            ram_headbutt();
            break;
        case SPRINGY_RAM:
            ram_headbutt();
            break;
        case PENGUIN:
            penguin_throw_snowball(arg3);
            break;
        case POLAR_BEAR:
            func_80368D60_77A410(arg1);
            break;
        case POLAR_TANK:
            polar_tank_drop_mine();
            break;
        case HUSKY:
            func_8036C014_77D6C4(arg1);
            break;
        case SKI_HUSKY:
            ski_husky_fire_missile(arg3);
            break;
        case WALRUS:
            walrus_fire_missile(arg3);
            break;
        case CAMEL:
            func_8036F50C_780BBC(arg3);
            break;
        case CANNON_CAMEL:
            camel_cannon_fire_cannon(arg3);
            break;
        case POGO_KANGAROO:
            func_80372698_783D48();
            break;
        case BOXING_KANGAROO:
            func_80372604_783CB4();
            break;
        case DESERT_FOX:
            func_803745C4_785C74(arg1);
            break;
        case ARMED_DESERT_FOX:
            func_8037460C_785CBC();
            break;
        case SCORPION:
            func_80379148_78A7F8(arg3);
            break;
        case HYENA:
            func_8035A590_76BC40(arg1);
            break;
        case HYENA_BIKER:
            biker_hyena_fire_missile(arg3);
            break;
        case CHAMELEON:
            func_8035C180_76D830(arg1);
            break;
        case CHAMELEON_DEFENDING:
            func_8035C180_76D830(arg1);
            break;
        case COOL_COD:
            break;
        }
    }
}
