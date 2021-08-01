#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F59F0_7070A0.s")
// still a long way to go ..
// void func_802F59F0_7070A0(void) {
//     s32 tmp = D_803A52C0_7B6970;
//
//     gControllerInput = &D_803E1BC4;
//
//     switch (D_803E1BC0) {
//     case 0:
//         // temp_v0_3 = &D_802910E8[D_801D9ED0];
//         D_803E1BC4.button =  D_802910E8[D_801D9ED0].button;
//         D_803E1BC4.stick_x = D_802910E8[D_801D9ED0].stick_x;
//         D_803E1BC4.stick_y = D_802910E8[D_801D9ED0].stick_y;
//         break;
//     case 1:
//         D_803E1BC4.button =  0U;
//         D_803E1BC4.stick_x = 0;
//         D_803E1BC4.stick_y = 0;
//         break;
//     case 2:
//         if (D_803A52C0 == 0) {
//             D_80151434 = (u16)0xB57; // 2903?
//             func_8012822C(1);
//             switch (D_803F2D50.unk20) {
//             case 0:
//                 D_803E1BD4 = &D_803B1F20_7C35D0;
//                 break;
//             case 1:
//                 if (D_803F2D50.unk52 == 1) {
//                     D_803E1BD4 = &D_803B2580_7C3C30;
//                 } else {
//                     D_803E1BD4 = &D_803B29D8_7C4088;
//                 }
//                 break;
//             case 2:
//                 D_803E1BD4 = &D_803B30D0_7C4780;
//                 break;
//             case 3:
//                 D_803E1BD4 = &D_803B384C_7C4EFC;
//                 break;
//             case 4:
//                 D_803E1BD4 = &D_803B3388_7C4A38;
//                 break;
//             case 5:
//                 break;
//             }
//             // tmp = D_803A52C4;
//             D_803A52C4 = 0;
//         }
//         D_803A52C4 -= 1;
//         if (D_803A52C4 < 0) {
//             if (D_803E1BD4->button != 0xFFFF) {
//                 D_803E1BC4.button = D_803E1BD4->button;
//                 D_803E1BC4.stick_x = D_803E1BD4->stick_x;
//                 D_803E1BC4.stick_y = D_803E1BD4->stick_y;
//                 D_803E1BD4 = (OSContPad *) (D_803E1BD4 + 6); // next?!
//                 D_803A52C4 = D_803E1BD4->errno;
//             } else {
//                 D_803E1BC4.button = 0U;
//                 D_803E1BC4.stick_y = 0;
//                 D_803E1BC4.stick_x = D_803E1BC4.stick_y;
//                 D_803E1BC0 = 2;
//             }
//         }
//         // press start?
//         if ((D_802910E8[D_801D9ED0].button & CONT_START) != 0) {
//             D_803E1BC0 = 2;
//         }
//         break;
//     }
//
//     D_803A52C0_7B6970 = tmp + 1; //(D_803A52C0_7B6970 + 1);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F5C60_707310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F5F44_7075F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F603C_7076EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F62E4_707994.s")

s16 func_802F63F8_707AA8(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;

    temp_v0 = arg1 - arg0;
    if (temp_v0 < 0) {
        temp_v0 += 360;
    }
    if (temp_v0 == 0) {
        return 0;
    }
    if (temp_v0 >= 180) {
        if ((temp_v0 + arg2) >= 360) {
            return 360 - temp_v0;
        }
        return arg2;
    }
    if ((temp_v0 - arg2) < 0) {
        return -temp_v0;
    }
    return -arg2;
}

s16 func_802F649C_707B4C(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v1;

    temp_v1 = arg1 - arg0;
    if (temp_v1 < 0) {
        temp_v1 += 360;
    }

    if (temp_v1 != 0) {
        if (temp_v1 >= 180) {
            if ((temp_v1 + arg2) >= 360) {
                arg1 = ((arg1 - temp_v1) + 360);
            } else {
                arg1 = (arg1 + arg2);
            }
            if (arg1 >= 360) {
                arg1 = (arg1 - 360);
            }
        } else {
            if ((temp_v1 - arg2) < 0) {
                arg1 = (arg1 - temp_v1);
            } else {
                arg1 = (arg1 - arg2);
            }
            if (arg1 < 0) {
                arg1 = (arg1 + 360);
            }
        }
    }
    return arg1;
}

void func_802F657C_707C2C(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk178 = arg1;
    arg0->unk17A = arg2;
    arg0->unk17C = arg3;
    arg0->unk172 = arg4;
    arg0->unk184 = 0;
    arg0->unk17E = arg0->xPos;
    arg0->unk180 = arg0->zPos;
    arg0->unk182 = arg0->yPos;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F65BC_707C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6750_707E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F68A0_707F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6A5C_70810C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6DEC_70849C.s")

void func_802F7054_708704(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F705C_70870C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F7940_708FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F804C_7096FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8160_709810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8658_709D08.s")

s32 func_802F8918_709FC8(Animal *arg0, Animal *arg1) {
    u8 i, j;

    if (arg0->unk18C == 0) {
        return 1;
    }
    for (i = 0; i < arg0->unk18C; i++) {
        for (j = 0; j < arg1->unk192; j++) {
            if (arg0->unk18D[i] == arg1->unk193[j]) {
                return 1;
            }
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8994_70A044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8B4C_70A1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8DCC_70A47C.s")

void func_802F9084_70A734(s32 arg0) {
}

void func_802F908C_70A73C(struct071 *arg0) {
    if (arg0->unk154 == 0) {
        arg0->unk154 = 100;
    }
}

void func_802F90A8_70A758(struct071 *arg0) {
    arg0->unk4.w += arg0->unk1C;
    arg0->unk8.w += arg0->unk20.w;
    if (!arg0->unk4C.unk1D) {
        arg0->unkC.w += arg0->unk24;
    }
    func_803136B0_724D60(arg0);
}

void func_802F9104_70A7B4(Animal *arg0) {
    arg0->unk150 = (arg0->unk150 + 4) & 0xFF;
    arg0->unk40 = (((D_80152C78[(arg0->unk150 + 64) & 0xFF] >> 7) * 0x66) >> 8) + 0x533;
    func_802C9BA4_6DB254();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9178_70A828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F92B0_70A960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F951C_70ABCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9624_70ACD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F96E0_70AD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9880_70AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9A08_70B0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9B4C_70B1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9C50_70B300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9E10_70B4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9EB8_70B568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FA4F8_70BBA8.s")

void func_802FA6D8_70BD88(void) {
    D_80204278->unk3B308 = 0;
    D_803E97C0 = 0;
    D_803A5760_7B6E10 = D_803A5760_7B6E10 + 4;
    D_803A5760_7B6E10 = D_803A5760_7B6E10 & 0xFF;
    D_803A52D0_7B6980 += 1;
    D_803E1BE0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FA730_70BDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FADBC_70C46C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB270_70C920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB49C_70CB4C.s")
// huh?
// void func_802FB49C_70CB4C(struct071 *arg0) {
//     arg0->unk54 = 0;
//     arg0->unk55 = 0;
//     arg0->unk56 = 0;
//     arg0->unk57 = 0;
//     arg0->unk5C = arg0->unk54;
//     arg0->unk60 = arg0->unk58;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB4C0_70CB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB680_70CD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB85C_70CF0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBA40_70D0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBBF8_70D2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBDA8_70D458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBF58_70D608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC108_70D7B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC2B8_70D968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC438_70DAE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC5C0_70DC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC6E4_70DD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC808_70DEB8.s")

void func_802FC8F4_70DFA4(Animal *arg0) {
    s32 tmp = (arg0->unk40 * 18) >> 11;
    func_802D5F4C_6E75FC(arg0->xPos, arg0->zPos, arg0->yPos + (arg0->unk42 >> 1), 23, 0, 0, 0, tmp, 0xB5AC, 0xB5AC, 0);
}

void func_802FC970_70E020(Animal *arg0) {
    func_802FCA08_70E0B8(arg0, arg0->unk164);
}

void func_802FC990_70E040(Animal *arg0) {
    if (arg0->unk26C != 1) {
        func_802FCA08_70E0B8(arg0, arg0->unk164);
        arg0->unk26C = 1;
        if (arg0->unk246 != 0) {
            struct069 *tmp = &D_803E4D40[(arg0->unk246 * 10) - 10];
            func_803153B0_726A60(arg0, tmp, 0);
            func_803191B0_72A860(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FCA08_70E0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD190_70E840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD26C_70E91C.s")

s32 func_802FD348_70E9F8(Animal *arg0, u16 arg1) {
    struct065 *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].unk0; tmp != NULL; tmp = tmp->unk0) {
        if ((arg0 == tmp->unk8->unk6C) && (tmp->unk8->unk16C->unk0 == arg1)) {
            return 1;
        }
    }
    return 0;
}

s32 func_802FD3B8_70EA68(Animal *arg0) {
    struct065 *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].unk0; tmp != NULL; tmp = tmp->unk0) {
        if (arg0 == tmp->unk8->unk6C) {
            return 1;
        }
    }
    return 0;
}

// is this animal or object?
s32 func_802FD40C_70EABC(Animal *arg0, Animal *arg1) {
    struct065 *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].unk0; tmp != NULL; tmp = tmp->unk0) {
        if ((arg0 == tmp->unk8->unk6C) && (arg1 == tmp->unk8)) {
            return 1;
        }
    }
    return 0;
}

s32 func_802FD468_70EB18(Animal *arg0) {
    struct065 *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].unk0; tmp != NULL; tmp = tmp->unk0) {
        if ((arg0 == tmp->unk8->unk6C) && (tmp->unk8->unk16C->unk0 >= 256)) {
            return 1;
        }
    }
    return 0;
}

s32 func_802FD4D0_70EB80(Animal *arg0) {
    struct065 *tmp;
    for (tmp = D_803DA110[arg0->unk114[0]].unk0; tmp != NULL; tmp = tmp->unk0) {
        if ((arg0 == tmp->unk8->unk6C) && (tmp->unk8->unk16C->unk0 < 256)) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD538_70EBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD5DC_70EC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD674_70ED24.s")

void func_802FD8CC_70EF7C(void) {
    D_803E1CF8.min = D_803E1CE8.min = D_803F2D50.unk2;
    D_803E1CF8.max = D_803E1CE8.max = D_803F2D50.unk4;

    D_803E1CF8.r = D_803E1CE8.r = D_803F2D50.unk6;
    D_803E1CF8.g = D_803E1CE8.g = D_803F2D50.unk8;
    D_803E1CF8.b = D_803E1CE8.b = D_803F2D50.unkA;

    D_803E1D00 = D_803E1D02 = 0;
    D_803E1D04 = 1;
}

void func_802FD94C_70EFFC(s16 min, s16 max, u8 r, u8 g, u8 b, s16 arg5) {
    D_803E1CE0 = D_803E1CF8;

    D_803E1CE8.min = min;
    D_803E1CE8.max = max;
    D_803E1CE8.r = r;
    D_803E1CE8.g = g;
    D_803E1CE8.b = b;
    D_803E1D00 = arg5;
    D_803E1D02 = 0;
    D_803E1D04 = 0;
    D_803E1D0C = 0;
}

void func_802FD9C4_70F074(s16 min, s16 max, u8 r, u8 g, u8 b, s16 arg5, s16 arg6) {
    // struct copy
    D_803E1CE0 = D_803E1CF8;

    D_803E1CF0.min = min;
    D_803E1CF0.max = max;
    D_803E1CF0.r = r;
    D_803E1CF0.g = g;
    D_803E1CF0.b = b;
    D_803E1D06 = arg5;
    D_803E1D08 = arg6;
    D_803E1D0A = 0;
    D_803E1D0C = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FDA44_70F0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FE4C4_70FB74.s")

void func_802FE560_70FC10(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, u8 arg7, s16 arg8) {
    D_803E1D10 = D_803E1D20;

    D_803E1D18.unk0 = arg0;
    D_803E1D18.unk1 = arg1;
    D_803E1D18.unk2 = arg2;
    D_803E1D18.unk3 = arg3;
    D_803E1D18.unk4 = arg4;
    D_803E1D18.unk5 = arg5;
    D_803E1D18.unk6 = arg6;
    D_803E1D18.unk7 = arg7;
    D_803E1D28 = arg8;
    D_803E1D2A = 0;
    D_803E1D2C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FE5E8_70FC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FED68_710418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FEE98_710548.s")

void spawn_temporary_object(s16 x, s16 z, s16 y, s16 scale, u8 lifetime, Animal *owner, s16 arg6, u8 id) {
    struct071 *obj = func_802C9564_6DAC14(id, x, z, func_80310EE4_722594(x, z, owner->unk160) >> 16, 0, 0, 0, 0, 0, scale);
    if (obj != 0) {
        obj->unk15C = 50;
        obj->unk168 = owner;
        obj->unk154 = lifetime;
        obj->unk15E = arg6 * 8;
    }
}

void func_802FF140_7107F0(void) {
    s16 i;

    D_803A5330_7B69E0 = 0;
    for (i = 0; i < 10; i++) {
        D_803E1BE8[i][0] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF184_710834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF25C_71090C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF540_710BF0.s")

void func_802FF7D4_710E84(Animal *arg0) {
    func_802D5F4C_6E75FC(arg0->xPos, arg0->zPos, arg0->yPos, 0x7C, 0, 0, 0, 0x14, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF828_710ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFA20_7110D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFC34_7112E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFD50_711400.s")

void func_802FFE94_711544(struct071 *arg0) {
    arg0->unk14E = (arg0->unk14E + 1) & 0x1F;
    if ((arg0->unk200 & 1) != 0) {
        func_802FFD50_711400(arg0);
    }
}

void func_802FFED0_711580(struct071 *arg0) {
    if (arg0->unk158 != 0) {
        func_802FFD50_711400(arg0);
    }
}
void func_802FFEFC_7115AC(struct071 *arg0) {
    if (arg0->unk0 == 1) {
        if (arg0->unk14E == 0) {
            arg0->unk14E = 1;
            func_8034419C_75584C(arg0);
        }
    } else if (arg0->unk14E == 1) {
        arg0->unk14E = 0;
    }
}

void func_802FFF50_711600(struct071 *arg0) {
    func_802FFED0_711580(arg0);
}

void func_8032CED0_73E580(s16*, s16, s16, f32, s16, s16, s16, s16, s16, s16, s16, s16);

void func_802FFF70_711620(struct071 *arg0) {
    func_8032CED0_73E580(&arg0->unk20.h[1], 0x9F, 0x3000, 1.0f, 0, 0, arg0->unk4.h, arg0->unk8.h, arg0->unkC.h, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFFD0_711680.s")
