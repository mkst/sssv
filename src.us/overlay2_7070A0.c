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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F657C_707C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F65BC_707C6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6750_707E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F68A0_707F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6A5C_70810C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6DEC_70849C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F7054_708704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F705C_70870C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F7940_708FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F804C_7096FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8160_709810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8658_709D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8918_709FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8994_70A044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8B4C_70A1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8DCC_70A47C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9084_70A734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F908C_70A73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F90A8_70A758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9104_70A7B4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FA6D8_70BD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FA730_70BDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FADBC_70C46C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB270_70C920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB49C_70CB4C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC8F4_70DFA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC970_70E020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC990_70E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FCA08_70E0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD190_70E840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD26C_70E91C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD348_70E9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD3B8_70EA68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD40C_70EABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD468_70EB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD4D0_70EB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD538_70EBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD5DC_70EC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD674_70ED24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD8CC_70EF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD94C_70EFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FD9C4_70F074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FDA44_70F0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FE4C4_70FB74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FE560_70FC10.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF140_7107F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF184_710834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF25C_71090C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF540_710BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF7D4_710E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF828_710ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFA20_7110D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFC34_7112E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFD50_711400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFE94_711544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFED0_711580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFEFC_7115AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFF50_711600.s")

void func_8032CED0_73E580(s16*, s16, s16, f32, s16, s16, s16, s16, s16, s16, s16, s16);
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFF70_711620.s")
// not animal?
// void func_802FFF70_711620(Animal *arg0) {
//     func_8032CED0_73E580(&arg0->yVelocity, 0x9F, 0x3000, 1.0f, 0, 0, arg0->xPos, arg0->zPos, arg0->yPos, 0, 0, 0);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFFD0_711680.s")
