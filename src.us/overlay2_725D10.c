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
    bzero_sssv((u8*)D_803E4CA8, sizeof(D_803E4CA8));
    bzero_sssv((u8*)D_803E4D40, sizeof(D_803E4D40));
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

// set_game_state()
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80314874_725F24.s")
// extern s32 D_FFFE0404[];
// extern s32 D_803C4DAC[];
// void func_80314874_725F24(Animal *arg0, s16 arg1, s32 arg2) {
//     s16 temp_v1;
//     s32 temp_hi;
//     s32 temp_t6;
//     struct035 *temp_v0_3;
//     s32 phi_v0;
//     s16 phi_v1;
//     struct035 *phi_t1;
//     s16 phi_v1_2;
//     Animal *tmp;
//             s16 i;
//
//     switch (arg1) {
//     case 0x7F7F:
//     case 0x7F80:
//     case 0x7F81:
//         // wtf is this
//         D_FFFE0404[(s32)arg0 + (arg1)] = arg2; // -130044 , -0x1fbfc?
//         break;
//     case 0x7F82:
//         arg0->unk158 = arg2;
//         arg0->unk15E = arg2;
//         break;
//     case 0x7F83:
//         if (!(arg0->unk4C.pad30 /* & 0x20 */) || (arg0->health < arg2)) {
//             if (arg0->unk16C->unk0 >= 256) {
//                 if (arg2 < arg0->health) {
//                     func_80349280_75A930(arg0, arg0->health - arg2);
//                 }
//             }
//             if (arg2 < 0) {
//                 phi_v0 = 0;
//             } else {
//                 phi_v0 = arg2;
//             }
//             if (phi_v0 > 0x7F) {
//                 arg0->health = 0x7F;
//             } else {
//                 if (arg2 < 0) {
//                     phi_v0 = 0;
//                 } else {
//                     phi_v0 = arg2;
//                 }
//                 arg0->health = phi_v0;
//             }
//         }
//         break;
//     case 0x7F97:
//     case 0x7F98:
//     case 0x7F99:
//     case 0x7F9A:
//         break;
//     case 0x7F84:
//         func_8012822C(arg2);
//         break;
//     case 0x7F85:
//         arg0->xPos = arg2 << 16;
//         func_803136B0_724D60(arg0);
//         break;
//     case 0x7F86:
//         arg0->zPos = arg2 << 16;
//         func_803136B0_724D60(arg0);
//         break;
//     case 0x7F87:
//         arg0->yPos = arg2 << 16;
//         func_803136B0_724D60(arg0);
//         break;
//     case 0x7F88:
//         arg0->unk40 = arg2;
//         func_802C9BA4_6DB254(arg0);
//         break;
//     case 0x7F89:
//         func_80349AA0_75B150(arg2);
//         break;
//     case 0x7F8A:
//         arg0->xVelocity.w = arg2 << 5;
//         break;
//     case 0x7F8B:
//         arg0->zVelocity.w = arg2 << 5;
//         break;
//     case 0x7F8C:
//         arg0->yVelocity.w = arg2 << 5;
//         break;
//     case 0x7F8D:
//         if (arg0->unk16C->unk0 >= 256) {
//             arg0->unk2E = (s16) (((s32) (arg2 << 8) / 360) & 0xFF);
//         } else {
//             // is 1800 a typo?
//             func_802C9918_6DAFC8(arg0, (s16) ((s32) (arg2 + 1800) % 360), arg0->yRotation);
//         }
//     case 0x7F8E:
//         if (arg0->unk16C->unk0 >= 256) {
//             arg0->yRotation = (s16) (((s32) (arg2 * 256) / 360) & 0xFF);
//             arg0->unk302 = (s16) arg0->yRotation;
//         } else {
//             func_802C9918_6DAFC8(arg0, arg0->unk2E, (s16) ((s32) (arg2 + 1800) % 360));
//         }
//     case 0x7F8F:
//         temp_hi = arg2 % 100;
//         arg0->unk248[0] = func_803146A8_725D58(arg0, (s16) temp_hi, (arg2 / 100) & 0xFFFF);
//         arg0->unk1CC = (s8) temp_hi;
//         break;
//     case 0x7F90:
//         if (arg2 & 1) {
//             arg0->unk163 &= ~0x8;
//         } else {
//             arg0->unk163 |= 0x8;
//         }
//         if (arg2 & 2) {
//             arg0->unk163 |= 0x10;
//         } else {
//             arg0->unk163 &= ~0x10;
//         }
//         if (arg2 & 4) {
//             arg0->unk163 |= 0x40;
//         } else {
//             arg0->unk163 &= ~0x40;
//         }
//         if (arg2 & 8) {
//             arg0->unk163 |= 0x80;
//         } else {
//             arg0->unk163 &= ~0x80;
//         }
//         break;
//     case 0x7F91:
//         arg0->unk46 = arg2;
//         arg0->unk44 = (s16) ((s32) ((arg2) * arg0->unk40) >> 0xB);
//         break;
//     case 0x7F92:
//         D_803F2D30.score = arg2;
//         break;
//     case 0x7F93:
//         arg0->unk3E = arg2;
//         break;
//     case 0x7F94:
//         arg0->state = arg2;
//         break;
//     case 0x7F95:
//         D_803F2CD8 = ABS(arg2);
//         D_803F2CD6 = ABS(arg2);
//         break;
//     case 0x7F96:
//         temp_t6 = arg2 << 6;
//         D_803A05B0_7B1C60 = temp_t6;
//         D_803A05B4_7B1C64 = temp_t6 * 2;
//         break;
//     case 0x7F9B:
//         D_803E4D2C = arg2;
//         break;
//     case 0x7F9C:
//         D_803F2E30 = (f32) arg2 / 100.0f;
//         break;
//     case 0x7F9D:
//         D_803E4D30 = arg2;
//         break;
//     case 0x7F9E:
//         D_803E4D38[0] = arg2;
//         D_8023F260.unk30 = arg2;
//         write_eeprom(D_803F7DD6);
//         break;
//     case 0x7F9F:
//         if (arg2 < 256) {
//             arg0->unk16C = &D_801E9EB8[arg2];
//             func_802C9BA4_6DB254(arg0);
//         } else {
//             phi_t1 = NULL;
//             for (i = 0; i < D_803D553E; i++) {
//                 tmp = D_801D9ED8.animal[i].unk0;
//                 if ((arg0 == tmp) && (tmp->unk366 != 6)) {
//                     phi_t1 = D_801D9ED8.unk3EB0;
//                     break;
//                 }
//             }
//             if (phi_t1 != NULL) {
//                 temp_v0_3 = &D_801D9ED8.unk0[arg2]; // + (arg2 * 0xEC) + 0xFFFF1400;
//                 phi_t1->unk0 = temp_v0_3;
//                 arg0->unk16C = temp_v0_3;
//                 // help
//                 D_803D5520 = &D_801D9ED8.unk0[arg2];
//                 D_803D5524 = &D_801D9ED8.unk3EB0; //phi_t1->unk0;
//                 D_803D5528 = &D_801D9ED8.animal;  //phi_t1->unk4;
//                 D_803D552C = &D_801D9ED8.animal;  //phi_t1->unk4;
//                 D_803D5530 = &D_801D9ED8.animal;  //phi_t1->unk4;
//                 if (i == gCurrentAnimalIndex) {
//                     D_803D5538 = 1;
//                 } else {
//                     D_803D5538 = 0;
//                 }
//                 D_803D553C = i;
//                 D_803D553A = 0;
//                 // arg0 = arg0;
//                 func_802B2EA8_6C4558();
//                 if (arg0 == D_801D9ED8.animal[gCurrentAnimalIndex].unk0) { // + (gCurrentAnimalIndex * 8))->
//                     D_803E9824 = arg2 - 256;
//                     // temp_v0_4 = (D_803E9824 * 2) + &D_803A63B0_7B7A60;
//                     // arg0 = arg0;
//                     D_803E9820 = (s16) D_803A63B0_7B7A60[D_803E9824].unk0;
//                     D_803E9822 = (s16) D_803A63B0_7B7A60[D_803E9824].unk1;
//                     func_80327DA8_739458();
//                 }
//                 func_802C9BA4_6DB254(arg0);
//             }
//         }
//         break;
//     case 0x7FA0:
//         D_801546E0 = (s16) arg2;
//         break;
//     case 0x7FA1:
//         D_801546D8 = MAX(arg2, 0);
//         break;
//     case 0x7FA2:
//         D_803E4D38[1] = arg2;
//         D_8023F260.unk34 = arg2;
//         write_eeprom(D_803F7DD6); //, arg1, arg0);
//         break;
//     case 0x7FA3:
//         D_803E4D28 = arg2;
//         break;
//     default:
//         D_803C4DAC[arg1] = arg2; // + (arg1 * 4)) = arg2;
//         break;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_725D10/func_80314F0C_7265BC.s")
// something to do with in-game scripting
extern u8 D_FFFE0400[];

extern s32 D_803E4D3C;
extern s32 D_803C4DAC_7D645C[];
// need to check rodata
// get_game_state()
// s32 func_80314F0C_7265BC(Animal *arg0, s32 arg1) {
//     s32 res;
//
//     if (arg1 < 0x7F7F) {
//         res = arg1;
//     } else {
//         switch (arg1) { // arg1 - 0x7F7F
//         case 32639:
//         case 32640:
//         case 32641:
//             res = *(s32*)&D_FFFE0400[(s32)(((s32*)&arg0->xPos) + arg1)];
//             break;
//         case 32642:
//             res = arg0->unk158;
//             break;
//         case 32643:
//             res = arg0->health;
//             break;
//         case 32644:
//             res = (s32) (func_80128200() & 0x7FFF) % 0x7F7E;
//             break;
//         case 32645:
//             res = arg0->xPos;
//             break;
//         case 32646:
//             res = arg0->zPos;
//             break;
//         case 32647:
//             res = arg0->yPos;
//             break;
//         case 32648:
//             res = arg0->unk40;
//             break;
//         case 32649:
//             if (D_803F2CD6 < 0) {
//                 res = D_803F2CD2;
//             } else {
//                 res = D_803F2CD2 - 1;
//                 if ((D_803F2CD8 >> 1) < D_803F2CD4) {
//                     res += 1;
//                 }
//             }
//             break;
//         case 32650:
//             res = arg0->xVelocity.w >> 5;
//             break;
//         case 32651:
//             res = arg0->zVelocity.w >> 5;
//             break;
//         case 32652:
//             res = arg0->yVelocity.w >> 5;
//             break;
//         case 32653:
//             if (arg0->unk16C->unk0 >= 256) {
//                 res = (arg0->unk2E * 360) / 256;
//             } else {
//                 res = arg0->unk2E;
//             }
//             break;
//         case 32654:
//             if (arg0->unk16C->unk0 >= 256) {
//                 res = (arg0->yRotation * 360) / 256;
//             } else {
//                 res = arg0->yRotation;
//             }
//             break;
//         case 32655:
//             res = arg0->unk1CC;
//             break;
//         case 32656:
//             res = (arg0->unk163 & 0x18) >> 3;
//             break;
//         case 32657:
//             res = arg0->unk46;
//             break;
//         case 32658:
//             res = D_803F2D30.score;
//             break;
//         case 32659:
//             res = arg0->unk3E;
//             break;
//         case 32660:
//             res = arg0->state;
//             break;
//         case 32661:
//             res = D_803F2CD8 * D_803F2CD6;
//             break;
//         case 32662:
//             res = D_803A05B0_7B1C60 >> 6;
//             break;
//         case 32663:
//             if ((gControllerInput->stick_x < -8) || (gControllerInput->stick_x > 8)) {
//                 res = gControllerInput->stick_x;
//             } else {
//                 res = 0;
//             }
//             break;
//         case 32664:
//             if ((gControllerInput->stick_y < -8) || (gControllerInput->stick_y > 8)) {
//                 res = gControllerInput->stick_y;
//             } else {
//                 res = 0;
//             }
//             break;
//         case 32665:
//             if ((gControllerInput->button & A_BUTTON)) {
//                 res = 1;
//             } else {
//                 res = 0;
//             }
//             break;
//         case 32666:
//             if ((gControllerInput->button & B_BUTTON)) {
//                 res = 1;
//             } else {
//                 res = 0;
//             }
//             break;
//         case 32667:
//             res = D_803E4D2C;
//             break;
//         case 32668:
//             res = D_803F2E30 * 100.0f;
//             break;
//         case 32669:
//             res = D_803E4D30;
//             break;
//         case 32670:
//             res = D_803E4D38[0];
//             break;
//         case 32671:
//             res = arg0->unk16C->unk0;
//             break;
//         case 32672:
//             res = D_801546E0;
//             break;
//         case 32673:
//             res = D_801546D8;
//             break;
//         case 32674:
//             res = D_803E4D38[1];
//             break;
//         case 32675:
//             res = D_803E4D28;
//             break;
//         default:
//             res = D_803C4DAC_7D645C[arg1];
//         }
//     }
//     return res;
// }

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

// delay slot + loopy
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
// absolutely huge function
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
