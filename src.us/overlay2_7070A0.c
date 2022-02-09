#include <ultra64.h>
#include "common.h"

#pragma intrinsic sqrtf

u8 func_802F8658_709D08(Animal *arg0, struct071 *arg1, f32 arg2, f32 arg3, struct077 *arg4);
struct071 *func_802F8994_70A044(struct071*);


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
//     case 2: // go to main menu
//         if (D_803A52C0 == 0) {
//             D_80151434 = (u16)0xB57; // 2903?
//             func_8012822C(1); // set time to 1
//             switch (D_803F2D50.biome) {
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
//         if (--D_803A52C4 < 0) {
//             if (D_803E1BD4->button != 0xFFFF) {
//                 D_803E1BC4.button = D_803E1BD4->button;
//                 D_803E1BC4.stick_x = D_803E1BD4->stick_x;
//                 D_803E1BC4.stick_y = D_803E1BD4->stick_y;
//                 D_803E1BD4++; // next?!
//                 D_803A52C4 = D_803E1BD4->errno;
//             } else {
//                 D_803E1BC4.button = 0U;
//                 D_803E1BC4.stick_y = 0;
//                 D_803E1BC4.stick_x = D_803E1BC4.stick_y;
//                 D_803E1BC0 = 2;
//             }
//         }
//         // press start?
//         if ((D_802910E8[D_801D9ED0].button & CONT_START)) {
//             D_803E1BC0 = 2;
//         }
//         break;
//     }
//
//     D_803A52C0_7B6970 = tmp + 1; //(D_803A52C0_7B6970 + 1);
// }

// contains a bunch of __ll_mul
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F5C60_707310.s")

void func_802F5F44_7075F4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, struct077 *arg5) {
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t3;
    s16 temp_v0;
    s32 temp_t7;

    temp_v0 = D_80152350.unk2D0[arg3];
    temp_t0 = D_80152350.unk384[arg3];

    temp_t1 = D_80152350.unk2D0[arg4];
    temp_t3 = D_80152350.unk384[arg4];

    temp_t7 = ((arg1 * temp_t0) - (arg2 * temp_v0)) >> 8;

    arg5->unk0 = ((arg0 * temp_t3) + (temp_t7 * temp_t1)) >> 8;
    arg5->unk2 = ((-arg0 * temp_t1) + (temp_t7 * temp_t3)) >> 8;
    arg5->unk4 = ((arg1 * temp_v0) + (arg2 * temp_t0)) >> 8;
}

// more __ll_mul
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F603C_7076EC.s")

struct071 *func_802F62E4_707994(s16 x, s16 z, s16 y, u8 id, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s32 scale) {
    struct071 *obj;
    struct077 sp3C;
    struct077 sp34;

    func_802F5F44_7075F4(arg4,      arg5, arg6, arg7, arg8, &sp3C);
    func_802F5F44_7075F4(0,    arg9 << 8,    0, arg7, arg8, &sp34);
    obj = func_802C9564_6DAC14(
        id,
        x + sp3C.unk0,
        z + sp3C.unk2,
        y + sp3C.unk4,
        sp34.unk0 << 8,
        sp34.unk2 << 8,
        sp34.unk4 << 8,
        arg7,
        arg8,
        scale);

    if (obj == 0) {
        return NULL;
    }
    obj->unk2E = arg7;
    return obj;
}

s16 func_802F63F8_707AA8(s16 arg0, s16 arg1, s16 arg2) {
    s16 diff;

    diff = arg1 - arg0;
    if (diff < 0) {
        diff += 360;
    }
    if (diff == 0) {
        return 0;
    }
    if (diff >= 180) {
        if ((diff + arg2) >= 360) {
            return 360 - diff;
        }
        return arg2;
    }
    if ((diff - arg2) < 0) {
        return -diff;
    }
    return -arg2;
}

s16 func_802F649C_707B4C(s16 arg0, s16 arg1, s16 arg2) {
    s16 diff;

    diff = arg1 - arg0;
    if (diff < 0) {
        diff += 360;
    }

    if (diff != 0) {
        if (diff >= 180) {
            if ((diff + arg2) >= 360) {
                arg1 = ((arg1 - diff) + 360);
            } else {
                arg1 = (arg1 + arg2);
            }
            if (arg1 >= 360) {
                arg1 = (arg1 - 360);
            }
        } else {
            if ((diff - arg2) < 0) {
                arg1 = (arg1 - diff);
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
    arg0->unk17E = arg0->xPos;
    arg0->unk180 = arg0->zPos;
    arg0->unk182 = arg0->yPos;
    arg0->unk184 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F65BC_707C6C.s")
// CURRENT (190)
// void func_802F65BC_707C6C(Animal *arg0) {
//     s32 new_var;
//     s32 temp_t5;
//     s32 temp_t6;
//     s32 temp_t8;
//
//     s32 phi_t2;
//
//     u16 new_var2;
//
//     if (arg0->unk184 >= 256) {
//         arg0->unk170 = 0;
//         arg0->xVelocity.w = 0;
//         arg0->zVelocity.w = 0;
//         if ((arg0->unk4C.unk29 == 0)) {
//             arg0->yVelocity.w = 0;
//         }
//     } else if (arg0->state == 0) {
//         arg0->xVelocity.w = 0;
//         arg0->zVelocity.w = 0;
//         if ((arg0->unk4C.unk29 == 0)) {
//             arg0->yVelocity.w = 0;
//         }
//     } else {
//         arg0->unk184 += arg0->unk172;
//
//         temp_t6 = (arg0->unk178 - arg0->unk17E) >> 1;
//         temp_t8 = (arg0->unk17A - arg0->unk180) >> 1;
//         temp_t5 = (arg0->unk17C - arg0->unk182) >> 1;
//
//         if (arg0->unk184 >= 256) {
//             phi_t2 = -FTOFIX32(0.5);
//         } else if (arg0->unk184 == 0) {
//             phi_t2 = FTOFIX32(0.5);
//         } else {
//             phi_t2 = D_80152C78[((arg0->unk184 >> 1) + 64) & 0xFF];
//         }
//
//         // this is wrong ...
//         new_var2 = arg0->unk184;
//         if (new_var2 & 1) { // odd?
//             phi_t2 = (D_80152C78[(((new_var2 >> 1) + 64) + 1) & 0xFF] + phi_t2) >> 1;
//         }
//
//         temp_t6 = ((arg0->unk17E + temp_t6) << 16) - (temp_t6 * 2 * phi_t2);
//         temp_t8 = ((arg0->unk180 + temp_t8) << 16) - (temp_t8 * 2 * phi_t2);
//         temp_t5 = ((arg0->unk182 + temp_t5) << 16) - (temp_t5 * 2 * phi_t2);
//
//         arg0->xVelocity.w = temp_t6 - *(s32*)&arg0->xPos;
//         arg0->zVelocity.w = temp_t8 - *(s32*)&arg0->zPos;
//         if (arg0->unk4C.unk29 == 0) {
//             arg0->yVelocity.w = temp_t5 - *(s32*)&arg0->yPos;
//         }
//     }
// }

void func_802F6750_707E00(Animal *arg0) {
    s32 temp_a2;
    s32 temp_t1;
    s32 temp_v0_2;

    s32 xVel;
    s32 zVel;
    s32 yVel;

    if (arg0->unk184 >= 256) {
        arg0->unk170 = 0;
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk29 == 0) {
            arg0->yVelocity.w = 0;
        }
    } else if (arg0->state == 0) {
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk29 == 0) {
            arg0->yVelocity.w = 0;
        }
    } else {
        arg0->unk184 += arg0->unk172;
        if (arg0->unk184 > 256) {
            arg0->unk184 = 256;
        }

        temp_v0_2 = arg0->unk178 - arg0->unk17E;
        temp_a2 = arg0->unk17A - arg0->unk180;
        temp_t1 = arg0->unk17C - arg0->unk182;

        if (temp_v0_2 == 0) {
            xVel = arg0->unk178 << 16;
        } else {
            xVel = (arg0->unk17E << 16) + ((temp_v0_2 * arg0->unk184) << 8);
        }
        if (temp_a2 == 0) {
            zVel = arg0->unk17A << 16;
        } else {
            zVel = (arg0->unk180 << 16) + ((temp_a2 * arg0->unk184) << 8);
        }
        if (temp_t1 == 0) {
            yVel = arg0->unk17C << 16;
        } else {
            yVel = (arg0->unk182 << 16) + ((temp_t1 * arg0->unk184) << 8);
        }
        arg0->xVelocity.w = xVel - *(s32*)&arg0->xPos;
        arg0->zVelocity.w = zVel - *(s32*)&arg0->zPos;
        if (arg0->unk4C.unk29 == 0) {
            arg0->yVelocity.w = yVel - *(s32*)&arg0->yPos;
        }
    }
}

void func_802F68A0_707F50(Animal *arg0) {
    s32 x, z, y;

    if ((arg0->xPos == arg0->unk178) &&
        (arg0->zPos == arg0->unk17A) &&
        ((arg0->unk4C.unk29 != 0) || (arg0->yPos == arg0->unk17C))) {
        arg0->unk170 = 0;
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk29 == 0) {
            arg0->yVelocity.w = 0;
        }
    } else if (arg0->state == 0) {
        arg0->xVelocity.w = 0;
        arg0->zVelocity.w = 0;
        if (arg0->unk4C.unk29 == 0) {
            arg0->yVelocity.w = 0;
        }
    } else {
        if (arg0->xPos < arg0->unk178) {
            x = arg0->xPos + arg0->unk172;
            if (arg0->unk178 < x) {
                x = arg0->unk178;
            }
        } else {
            if (arg0->unk178 < arg0->xPos) {
                x = arg0->xPos - arg0->unk172;
                if (x < arg0->unk178) {
                    x = arg0->unk178;
                }
            } else {
                x = arg0->xPos;
            }
        }

        if (arg0->zPos < arg0->unk17A) {
            z = arg0->zPos + arg0->unk172;
            if (arg0->unk17A < z) {
                z = arg0->unk17A;
            }
        } else {
            if (arg0->unk17A < arg0->zPos) {
                z = arg0->zPos - arg0->unk172;
                if (z < arg0->unk17A) {
                    z = arg0->unk17A;
                }
            } else {
                z = arg0->zPos;
            }
        }

        if (arg0->yPos < arg0->unk17C) {
            y = arg0->yPos + arg0->unk172;
            if (arg0->unk17C < y) {
                y = arg0->unk17C;
            }
        } else {
            if (arg0->unk17C < arg0->yPos) {
                y = arg0->yPos - arg0->unk172;
                if (y < arg0->unk17C) {
                    y = arg0->unk17C;
                }
            } else {
                y = arg0->yPos;
            }
        }

        arg0->xVelocity.w = (x << 16) - *(s32*)&arg0->xPos;
        arg0->zVelocity.w = (z << 16) - *(s32*)&arg0->zPos;
        if (arg0->unk4C.unk29 == 0) {
            arg0->yVelocity.w = (y << 16) - *(s32*)&arg0->yPos;
        }
    }
}

#if 0
// OK but has .rodata
void func_802F6A5C_70810C(Animal *arg0) {
    s16 phi_a2;
    s16 phi_v0_4;

    f32 sqrt;
    f64 temp_f2;
    f32 phi_f14;
    f32 phi_f2;
    f32 phi_f16;
    f64 temp_f14;

    if ((arg0->state != 30) && (arg0->state != 31)) {
        if ((arg0->unk161 == 1) && ((arg0->unk6C != NULL))) {
            phi_f14 = (f32) (arg0->xVelocity.w - arg0->unk6C->xVelocity.w) / arg0->unk30;
            phi_f2 = (f32) (arg0->zVelocity.w - arg0->unk6C->zVelocity.w) / arg0->unk30;
        } else {
            phi_f14 = (f32) arg0->xVelocity.w / arg0->unk30;
            phi_f2 = (f32) arg0->zVelocity.w / arg0->unk30;
        }

        // huh?
        sqrt = sqrtf((phi_f14 * phi_f14) + (phi_f2 * phi_f2));

        if (sqrtf((phi_f14 * phi_f14) + (phi_f2 * phi_f2)) == 0.0) {
            phi_f16 = 0.0f;
        } else {
            temp_f14 = 360.0; // D_803BCED0_7CE580;
            phi_f16 = func_801286B8(-phi_f2, phi_f14) + 90.0; //D_803BCED8_7CE588);
            if (temp_f14 < phi_f16) {
                phi_f16 -= temp_f14;
            }
        }
        temp_f14 = 500.0; //D_803BCEE0_7CE590;
        temp_f2 = sqrt;
        if (temp_f14 < temp_f2) {
            phi_v0_4 = phi_f16;
            phi_v0_4 = phi_v0_4 - arg0->yRotation;
            while (phi_v0_4 < -90) {
                phi_v0_4 += 180;
            }
            while (phi_v0_4 > 90) {
                phi_v0_4 -= 180;
            }

            phi_a2 = MIN(10.0, temp_f2 / temp_f14);
            if (phi_a2 >= ABS(phi_v0_4)) {
                arg0->yRotation += phi_v0_4;
            } else if (phi_v0_4 < 0) {
                arg0->yRotation -= phi_a2;
            } else {
                arg0->yRotation += phi_a2;
            }
        }
        phi_v0_4 = arg0->yRotation - (s16) phi_f16;
        while (phi_v0_4 < -180) {
            phi_v0_4 += 360;
        }
        while (phi_v0_4 > 180) {
            phi_v0_4 -= 360;
        }

        if (ABS(phi_v0_4) < 90) {
            arg0->unk2E -= (s16) (temp_f2 * 0.0008742899988063026); // SSSV_PI / (10 * 360) ? ish D_803BCEE8_7CE598
        } else {
            arg0->unk2E += (s16) (temp_f2 * 0.0008742899988063026); // D_803BCEF0_7CE5A0
        }

        while (arg0->unk2E >= 360) {
            arg0->unk2E -= 360;
        }
        while (arg0->unk2E < 0) {
            arg0->unk2E += 360;
        }

        while (arg0->yRotation >= 360) {
            arg0->yRotation -= 360;
        }
        while (arg0->yRotation < 0) {
            arg0->yRotation += 360;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6A5C_70810C.s")
#endif

// more __ll_mul
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F6DEC_70849C.s")

void func_802F7054_708704(s32 arg0) {
}

// 3-deep loops
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F705C_70870C.s")
// more loops
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F7940_708FF0.s")

s32 func_802F804C_7096FC(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_f18;
    f32 phi_f18;

    if (arg1 == 0.0f) {
        return 90;
    }
    temp_f18 = 1.0 - (((2.0f * arg4) / (arg2 * arg2)) * (((arg4 * (arg1 * arg1)) / (2.0f * (arg2 * arg2))) + arg3));
    if (temp_f18 < 0.0f) {
        return 9999;
    }
    temp_f18 = sqrtf(temp_f18);
    if (arg0 != 0) {
        phi_f18 = ((arg2 * arg2) / (arg4 * arg1)) * (1.0 + temp_f18);
    } else {
        phi_f18 = ((arg2 * arg2) / (arg4 * arg1)) * (1.0 - temp_f18);
    }
    return func_8012844C(phi_f18 * 64.0f);
}

// gotos
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8160_709810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8658_709D08.s")
// so far away.
// s32 func_802F8658_709D08(Animal *arg0, struct071 *arg1, f32 arg2, f32 arg3, struct077 *arg4) {
//     f32 sp60;
//     f32 sp5C;
//     f32 sp50;
//     f32 temp_f0_2;
//     Vertex sp44;
//     Vertex sp38;
//     f32 temp_f0_3;
//     s16 temp_v0;
//     s16 phi_v1;
//     f32 phi_f12;
//     f32 phi_f2;
//
//     sp44.x = arg0->xPos - arg1->xPos;
//     sp44.y = arg0->zPos - arg1->zPos;
//     sp44.z = (arg0->yPos + arg0->unk42) - (arg1->yPos + arg1->unk42);
//     sp50 = sqrtf((sp44.x * sp44.x) + (sp44.y * sp44.y) + (sp44.z * sp44.z));
//
//     if (arg3 < sp50) {
//         return 0;
//     }
//     sp38.x = arg1->xVelocity.h;
//     sp38.y = arg1->zVelocity.h;
//     sp38.z = arg1->yVelocity.h;
//     sp60 = sqrtf((sp38.x * sp38.x) + (sp38.y * sp38.y) + (sp38.z * sp38.z)) / arg2;
//
//     temp_v0 = func_8032D5A4_73EC54(&sp44, &sp38); // arg3, arg2,
//     phi_v1 = func_8012835C((sinf((f32)temp_v0 * 0.017453292519943295) * sp50 * 256.0f)); // D_803BCEF8_7CE5A8
//     // help
//     if (phi_v1 <= 0.0f) {
//         phi_v1 = -phi_v1;
//     }
//     temp_f0_2 = ((s16) (s32) (D_80152350.unk384[temp_v0] * sp60) + D_80152350.unk384[phi_v1]) * 256.0f;
//     if (temp_f0_2 == 0.0f) {
//         return 0;
//     }
//
//     temp_f0_3 = get_magnitude(&sp38);
//     if (temp_f0_3 == 0.0f) {
//         phi_f12 = 0.0f;
//         phi_f2 = 0.0f;
//     } else {
//         phi_f12 = sp38.x / temp_f0_3;
//         phi_f2 = sp38.y / temp_f0_3;
//     }
//     sp5C = sp50 / temp_f0_2;
//     arg4.unk0 = arg1->xPos + (s16) (sp60 * sp5C * phi_f12);
//     arg4.unk2 = arg1->zPos + (s16) (sp60 * sp5C * phi_f2);
//     arg4.unk4 = arg1->yPos + (arg1->unk42 >> 1);
//     return 1;
// }

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
// regalloc is wrong,
// struct071 *func_802F8994_70A044(struct071 *arg0) {
//     s16 i;
//     s16 phi_v1;
//     s16 phi_a0;
//
//     s16 distance;
//     s16 temp_s0;
//
//     Animal *animal;
//     struct071 *ret;
//
//     distance = 0x7FFF; // MAX_SHORT ?
//     ret = NULL;
//
//     for (i = 0; i < D_803D553E; i++) {
//         animal = D_801D9ED8.animals[i].animal;
//         if (animal != NULL) {
//             if ((animal->unk366 != 6) && (animal->unk366 != 2) && (animal->unk366 != 5)) {
//                 if ((D_801D9ED8.animals[i].unk0->unk9C != EVO_GLITCHY) &&
//                     (D_801D9ED8.animals[i].unk0->unk9C != EVO)) {
//
//                     ret = arg0; // not this but similar?
//                     phi_a0 = ABS(arg0->unk4.h - animal->xPos);
//                     phi_v1 = ABS(arg0->unk8.h - animal->zPos);
//                     temp_s0 = MAX(phi_a0, phi_v1) + (MIN(phi_a0, phi_v1) >> 1);
//
//                     if ((temp_s0 < distance) && func_802F8918_709FC8(arg0, animal)) {
//                         // found a new closer animal?
//                         distance = temp_s0;
//                         ret = animal;
//                     }
//                 }
//             }
//         }
//     }
//     return ret;
// }

// gun turret
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F8B4C_70A1FC.s")
// void func_802F8B4C_70A1FC(struct071 *arg0) {
//     s16 pad2[8];
//     s16 angle;
//     struct071 *obj;
//     s16 temp_t0;
//     s16 pad[3];
//     // s16 sp5C;
//     // s32 sp58;
//     // s16 sp4A;
//     s16 sp4C[1];
//     struct077 sp48; // probably a bigger struct?
//
//     if (arg0->unk150 > 0) {
//         arg0->unk150 -= 2;
//     }
//     if ((arg0->unk0 == 1)) {
//         obj = func_802F8994_70A044(arg0);
//         if ((obj != NULL) && func_802F8658_709D08(arg0, obj, 16.0f, 512.0f, &sp48)) {
//             // something missing here...
//             angle = func_801284B8(sp48.unk0 - arg0->unk4.h, sp48.unk2 - arg0->unk8.h);
//             temp_t0 = func_802F8160_709810(arg0, obj, 0, 0, 16, 89, -4, 4, (f64) (f32) D_803A05B0_7B1C60 / (512 * 1024));
//             arg0->unk2C = ((angle + 180) % 360) & 0xffff;
//             if (temp_t0 != -1) {
//                 if (temp_t0 <= 90) {
//                     arg0->unk2E = 90 - temp_t0;
//                 } else {
//                     arg0->unk2E = 90;
//                 }
//             }
//             if (arg0->unk14E <= 0) {
//                 if (arg0->unk152 > 0) {
//                     arg0->unk152 -= 1;
//                     arg0->unk150 = 256;
//                     if (((arg0->unk152 & 1) == 1)) {
//                         play_sound_effect_at_location(SFX_UNKNOWN_74, 0x5000, 0, arg0->unk4.h, arg0->unk8.h, arg0->unkC.h, 1.0f);
//                         obj = func_802F62E4_707994(arg0->unk4.h, arg0->unk8.h, (s16) (arg0->unkC.h + ((s32) (arg0->unk40 * 6) >> 0xB)), 0x26, 0, (arg0->unk40 * 40) >> 11, 0, temp_t0, angle, 0x10, (s32) (arg0->unk40 << 0xB) >> 0xB);
//                         if (obj != NULL) {
//                             obj->unk154 = 200;
//                         }
//                     }
//                 } else {
//                     arg0->unk14E = (s16) ((func_80128200() & 0x1F) + arg0->unk158 + 0x18);
//                     arg0->unk152 = 6;
//                 }
//             } else {
//                 arg0->unk14E -= 1;
//             }
//         }
//     }
// }

// homing missile turret
void func_802F8DCC_70A47C(struct071 *arg0) {
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t2;
    s16 sp56;
    s16 phi_t0;
    s16 pad[2];
    struct071 *obj; // target, animal?

    if (arg0->unk150 > 0) {
        arg0->unk150 -= 2;
    }
    if (arg0->unk0 == 1) {
        obj = func_802F8994_70A044(arg0);
        if (obj != NULL) {
            if (arg0->unk14E > 0) {
                arg0->unk14E -= 1;
            }
            temp_a2 = obj->unk4.h - arg0->unk4.h;
            temp_a3 = obj->unk8.h - arg0->unk8.h;
            temp_t0 = ((obj->unkC.h - arg0->unkC.h) - arg0->unk42) + (obj->unk42 >> 1);
            temp_t2 = (s16)sqrtf((temp_a2 * temp_a2) + (temp_a3 * temp_a3));
            if (temp_t2 < 640) {
                sp56 = func_801284B8(temp_a2, temp_a3);
                phi_t0 = func_801284B8(temp_t0, temp_t2);
                if (phi_t0 > 180) {
                    phi_t0 = 0;
                } else if (phi_t0 > 90) {
                    phi_t0 = 90;
                }
                arg0->unk2C = func_802F649C_707B4C(((sp56 + 180) % 360), arg0->unk2C, 6);
                arg0->unk2E = func_802F649C_707B4C((90 - phi_t0), arg0->unk2E, 6);
                if (arg0->unk14E <= 0) {
                    arg0->unk14E = arg0->unk158 + 250;
                    arg0->unk150 = 256;
                    play_sound_effect_at_location(SFX_UNKNOWN_74, 0x5000, 0, arg0->unk4.h, arg0->unk8.h, arg0->unkC.h, 1.0f);
                    func_802FED68_710418(arg0, obj, arg0->unk4.h, arg0->unk8.h, arg0->unkC.h + ((arg0->unk40 * 6) >> 11), 0, (arg0->unk40 * 40) >> 11, 0, phi_t0, sp56, 0, (f32)arg0->unk40 / 2048 * D_803BCF00_7CE5B0, 10); // 0.3
                }
            }
        }
    }
}

void func_802F9084_70A734(s32 arg0) {
}

void func_802F908C_70A73C(struct071 *arg0) {
    if (arg0->unk154 == 0) {
        arg0->unk154 = 100;
    }
}

void func_802F90A8_70A758(struct071 *arg0) {
    arg0->unk4.w += arg0->unk1C.w;
    arg0->unk8.w += arg0->unk20.w;
    if (!arg0->unk4C.unk30) {
        arg0->unkC.w += arg0->unk24;
    }
    func_803136B0_724D60(arg0);
}

void func_802F9104_70A7B4(struct071 *arg0) {
    arg0->unk150 = (arg0->unk150 + 4) & 0xFF;
    arg0->unk40 = (((D_80152C78[(arg0->unk150 + 64) & 0xFF] >> 7) * 0x66) >> 8) + 0x533;
    func_802C9BA4_6DB254(arg0);
}

// mouse radar?
s32 func_802F9178_70A828(Animal *arg0) {
    Animal *target;
    s16 zDist;
    s16 xDist;
    s32 phi_t0;
    s32 phi_a3;
    s16 i;

    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != 0) &&
            (D_801D9ED8.animals[i].unk0->unk9C == MOUSE2)) {
            if ((D_801D9ED8.animals[i].animal->unk366 != 6) &&
                (D_801D9ED8.animals[i].animal->unk366 != 2) &&
                (D_801D9ED8.animals[i].animal->unk366 != 5)) {

                target = D_801D9ED8.animals[i].animal;

                xDist = ABS(arg0->xPos - target->xPos);
                zDist = ABS(arg0->zPos - target->zPos);
                phi_a3 = MAX(xDist, zDist);
                phi_t0 = MIN(xDist, zDist);

                // found a close animal
                if ((s16) ((phi_t0 >> 1) + phi_a3) < 0x280) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

#ifdef NON_MATCHING
// justreg
void func_802F92B0_70A960(Animal *arg0) {
    s16 phi_a2;
    s16 temp_a3_2;
    s32 temp_v1;
    s32 temp_a2;
    s16 phi_a1;
    Animal *temp_a3;
    s32 pad;

    s32 sp54;
    s32 sp50;
    s16 sp4E;
    s16 sp4C;
    s16 pad4A;
    s16 sp48;
    u8  sp47;

    sp47 = func_802F9178_70A828(arg0);
    temp_a3 = arg0->unk188;
    if (temp_a3 != NULL) {
        temp_v1 = temp_a3->xPos - arg0->xPos;
        temp_a2 = temp_a3->zPos - arg0->zPos;
        sp54 = (temp_a3->yPos - arg0->yPos) + (temp_a3->unk42 >> 1);
        sp50 = (s16) sqrtf(((temp_v1 * temp_v1) + (temp_a2 * temp_a2)));
        sp4E = func_801284B8(temp_v1, temp_a2);
        temp_a3_2 = func_801284B8(sp54, sp50);
        if (arg0->unk150 != 0) {
            phi_a2 = arg0->unk150;
        } else {
            phi_a2 = 7;
        }
        sp4C = temp_a3_2;
        arg0->yRotation = func_802F649C_707B4C(sp4E, arg0->yRotation, phi_a2);
        arg0->unk2E = func_802F649C_707B4C(sp4C, arg0->unk2E, MAX((phi_a2 * 3) / 4, 1));
    }

    if (arg0->unk152 != 0) {
        phi_a1 = arg0->unk152;
    } else {
        phi_a1 = 18;
    }

    if (sp47 != 0) {
        arg0->yRotation += (D_80152620[(s16) ((arg0->unk14E * 16) % 360)]) >> 5;
    }
    if (arg0->yRotation >= 360) {
        arg0->yRotation -= 360;
    } else if (arg0->yRotation < 0) {
        arg0->yRotation += 360;
    }
    func_802F6DEC_70849C(arg0, phi_a1);
    arg0->unk14E += 1;
    if (arg0->unk154 == 0) {
        arg0->unk154 = 160;
    }
    func_8032CED0_73E580(arg0, 0x67, 0x4000, 0.4f, 0, 0, arg0->xPos, arg0->zPos, arg0->yPos, arg0->xVelocity.w, arg0->zVelocity.w, arg0->yVelocity.w);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F92B0_70A960.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F951C_70ABCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9624_70ACD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F96E0_70AD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802F9880_70AF30.s")

void func_802F9A08_70B0B8(Animal *arg0) {
    if (arg0->state == 1) {
        if (arg0->unk14E == 0) {
            arg0->unk23C = 13;
            arg0->unk23D = 128;
            arg0->unk23E = 128;
            arg0->unk23F = 96;
            arg0->unk240 = 128;
            arg0->unk241 = 5;
            arg0->unk242 = 64;
            arg0->unk244 = 0;
        }
        if (arg0->unk14E < 0xFF) {
            arg0->unk14E += 4;
            if (arg0->unk14E >= 256) {
                arg0->unk14E = 0xFF;
            }
        }
    } else {
        if (arg0->unk14E >= 0xFF) {
            arg0->unk23C = 13;
            arg0->unk23D = 128;
            arg0->unk23E = 128;
            arg0->unk23F = 128;
            arg0->unk240 = 96;
            arg0->unk241 = 5;
            arg0->unk242 = 64;
            arg0->unk244 = 0;
        }
        if (arg0->unk14E > 0) {
            arg0->unk14E -= 4;
            if (arg0->unk14E < 0) {
                arg0->unk14E = 0;
            }
        }
    }
    arg0->yRotation = ((arg0->unk14E * 360) / 128) % 360;
}

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

void func_802FB49C_70CB4C(struct071 *arg0) {
    arg0->unk5C = arg0->unk54;

    arg0->unk54.unk0 = 0;
    arg0->unk54.unk1 = 0;
    arg0->unk54.unk2 = 0;
    arg0->unk54.unk3 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB4C0_70CB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB680_70CD30.s")

#ifdef NON_MATCHING
void func_802FB85C_70CF0C(Animal *arg0) {
    s16 phi_v0;
    s16 phi_v1;
    s32 phi_v1_2;
    u16 phi_a1;

    if (arg0->unk15E == 0) {
        phi_v0 = (arg0->unk40 << 5) >> 11;
        if (arg0->unk158 != 0) {
            phi_v0 *= arg0->unk158;
        }
    } else {
        phi_v0 = arg0->unk15E;
    }

    if ((arg0->unk168 != 0) && (arg0->unk168->unk16C->unk80.bit)) {
        phi_v1 = arg0->unk168->unk16C->unkE6;
    } else {
        phi_v1 = -1;
    }

    func_802FF184_710834(
        arg0,
        1,
        arg0->xPos,
        arg0->zPos,
        arg0->yPos + (arg0->unk42 >> 1),
        0,
        0,
        100,
        phi_v0,
        phi_v1);

    phi_v1_2 = MAX(
        MAX(D_803C0740[(arg0->xPos >> 6) + 0][(arg0->zPos >> 6) + 0].unk6, D_803C0740[(arg0->xPos >> 6) + 1][(arg0->zPos >> 6) + 0].unk6),
        MAX(D_803C0740[(arg0->xPos >> 6) + 0][(arg0->zPos >> 6) + 1].unk6, D_803C0740[(arg0->xPos >> 6) + 1][(arg0->zPos >> 6) + 1].unk6)
    );

    if (arg0->yPos < (phi_v1_2 << 2)) {
        phi_a1 = 32;
    } else {
        phi_a1 = 4 | 2 | 1;
    }

    func_802D7BE0_6E9290(
        0,
        (phi_a1 | 0x40) & 0xFFFF,
        arg0->xPos,
        arg0->zPos,
        arg0->yPos + (arg0->unk42 >> 1),
        arg0->unk30 >> 2,
        0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FB85C_70CF0C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBA40_70D0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBBF8_70D2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBDA8_70D458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FBF58_70D608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC108_70D7B8.s")

// huh?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC2B8_70D968.s")

// complete mess
// #pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC438_70DAE8.s")
void func_802FC438_70DAE8(s16 x, s16 z, s16 y) {
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s16 i;

    for (i = 0; i < 3; i++) {
        temp_s1 = ((s32)func_80128200() % FTOFIX32(6.0)) - FTOFIX32(3.0);
        temp_s2 = ((s32)func_80128200() % FTOFIX32(6.0)) - FTOFIX32(3.0);
        temp_s3 = ((s32)func_80128200() % FTOFIX32(2.0)) + FTOFIX32(3.0);
        create_particle_effect(
            x,
            z,
            y,
            35,
            temp_s1, // ?
            temp_s2, // ?
            temp_s3, // ?
            8,       // particle size
            GPACK_RGBA5551(0, 248, 0, 1),
            GPACK_RGBA5551(8,  56, 0, 1),
            0);
    }
}


void func_802FC5C0_70DC70(Animal *arg0) {
    s16 phi_a1;
    s32 phi_v1;

    phi_v1 = MAX(MAX(D_803C0740[(arg0->xPos >> 6) + 0][(arg0->zPos >> 6) + 0].unk6,
                     D_803C0740[(arg0->xPos >> 6) + 1][(arg0->zPos >> 6) + 0].unk6),
                 MAX(D_803C0740[(arg0->xPos >> 6) + 0][(arg0->zPos >> 6) + 1].unk6,
                     D_803C0740[(arg0->xPos >> 6) + 1][(arg0->zPos >> 6) + 1].unk6));

    if (arg0->yPos < (phi_v1 * 4)) {
        phi_a1 = 40;
    } else {
        phi_a1 = 9;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->xPos, arg0->zPos, arg0->yPos, arg0->unk30, func_8029A52C_6ABBDC(arg0->unk3E));
}

void func_802FC6E4_70DD94(Animal *arg0) {
    s16 phi_a1;
    s32 phi_v1;

    phi_v1 = MAX(MAX(D_803C0740[(arg0->xPos >> 6) + 0][(arg0->zPos >> 6) + 0].unk6,
                     D_803C0740[(arg0->xPos >> 6) + 1][(arg0->zPos >> 6) + 0].unk6),
                 MAX(D_803C0740[(arg0->xPos >> 6) + 0][(arg0->zPos >> 6) + 1].unk6,
                     D_803C0740[(arg0->xPos >> 6) + 1][(arg0->zPos >> 6) + 1].unk6));

    if (arg0->yPos < (phi_v1 * 4)) {
        phi_a1 = 104;
    } else {
        phi_a1 = 72;
    }
    func_802D7BE0_6E9290(0, phi_a1, arg0->xPos, arg0->zPos, arg0->yPos, arg0->unk30, func_8029A52C_6ABBDC(arg0->unk3E));
}

#ifdef NON_MATCHING
// regalloc
void func_802FC808_70DEB8(Animal *arg0) {
    s32 tmp = (arg0->unk40 * 18) >> 11;
    s16 i;

    for (i = 0; i < 10; i++) {
        create_particle_effect(
            arg0->xPos,
            arg0->zPos,
            arg0->yPos + (arg0->unk42 >> 1),
            23,
            ((arg0->unk40 & 0xffff) * D_803A52E8_7B6998[i].unk0) >> 11,
            ((arg0->unk40 & 0xffff) * D_803A52E8_7B6998[i].unk4) >> 11,
            0,
            tmp,
            GPACK_RGBA5551(176, 176, 176, 0),
            GPACK_RGBA5551(176, 176, 176, 0),
            0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FC808_70DEB8.s")
#endif


void func_802FC8F4_70DFA4(Animal *arg0) {
    s32 tmp = (arg0->unk40 * 18) >> 11;
    create_particle_effect(
        arg0->xPos,
        arg0->zPos,
        arg0->yPos + (arg0->unk42 >> 1),
        23,
        0,
        0,
        0,
        tmp,
        GPACK_RGBA5551(176, 176, 176, 0),
        GPACK_RGBA5551(176, 176, 176, 0),
        0);
}

void func_802FC970_70E020(Animal *arg0) {
    func_802FCA08_70E0B8(arg0, arg0->unk164);
}

void func_802FC990_70E040(Animal *arg0) {
    if (arg0->unk26C != 1) {
        func_802FCA08_70E0B8(arg0, arg0->unk164);
        arg0->unk26C = 1;
        if (arg0->unk246 != 0) {
            struct069 *tmp = &D_803E4D40[arg0->unk246 - 1];
            func_803153B0_726A60(arg0, tmp, 0);
            func_803191B0_72A860(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FCA08_70E0B8.s")
// void func_802FCA08_70E0B8(Animal *arg0, s16 arg1) {
//     s32 temp_t5;
//     s16 phi_v0;
//     s16 phi_v1;
//     // surely not...
//     volatile u8 tmp  = ((arg1 & 0x4000) == 0) & 0xFF;
//
//     switch ((s16)(arg1 & 0xBFFF)) {
//     case 0:
//         break;
//     case 1: // dust cloud
//         func_802FC808_70DEB8(arg0);
//         break;
//     case 2: // bomb/explosion air
//         func_802FB4C0_70CB70(arg0);
//         break;
//     case 3: // bomb/explosion ground
//         func_802FBBF8_70D2A8(arg0);
//         break;
//     case 4: // powerup?
//         switch (arg0->unk16C->unk0) {
//         case 0x22: // powercell
//             if (((arg1 & 0x4000) == 0)) {
//                 D_803F2D30.powercells += 1;
//                 D_803F2D30.unk6 += 1;
//                 D_803F2D30.score += 1000;
//             }
//             func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, (arg0->yPos + ((arg0->unk40) >> 7) * 2), 2);
//             break;
//         case 0x3A: // energy ball + 16 hp
//             if (((arg1 & 0x4000) == 0)) {
//                 if (D_803F2D30.unk4 == 0) {
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = MIN(D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 0x10, 0x7F);
//                 }
//                 D_803D552C->unk348 = 0;
//                 D_803D552C->unk34A = 0;
//                 D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk358 = 0;
//                 D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk363 = 0;
//             }
//             // func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, (arg0->yPos + (((s32) arg0->unk40 >> 7) * 2)), 1);
//             func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos + ((arg0->unk40) >> 7) * 2, 1);
//             break;
//         case 0x3B:  // energy ball + 32 hp
//             if (((arg1 & 0x4000) == 0)) {
//                 if (D_803F2D30.unk4 == 0) {
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = MIN(D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 0x20, 0x7F);
//                 }
//                 D_803D552C->unk348 = 0;
//                 D_803D552C->unk34A = 0;
//                 D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk358 = 0; //(&D_801D9ED8 + (gCurrentAnimalIndex * 8))->unk3EB4->unk358 = 0;
//                 D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk363 = 0; //(&D_801D9ED8 + (gCurrentAnimalIndex * 8))->unk3EB4->unk363 = 0;
//             }
//             func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, (arg0->yPos + ((arg0->unk40) >> 7) * 2), 1);
//             break;
//         case 0x3C: // energy ball + 64hp
//             if (((arg1 & 0x4000) == 0)) {
//                 if (D_803F2D30.unk4 == 0) {
//                     D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = MIN(D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 0x40, 0x7F);
//                 }
//                 D_803D552C->unk348 = 0;
//                 D_803D552C->unk34A = 0;
//                 D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk358 = 0;
//                 D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk363 = 0;
//             }
//             func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos + ((arg0->unk40) >> 7) * 2, 1);
//             break;
//         default:                                    /* switch 1 */
//             func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos + ((arg0->unk40) >> 7) * 2, 2);
//             break;
//         }
//         break;
//     // no case 5
//     case 6: // white sparks?
//         func_802FC2B8_70D968(arg0->xPos, arg0->zPos, (arg0->yPos + (arg0->unk42 >> 1)));
//         break;
//     case 7: // explosion with red debris
//         func_802FBF58_70D608(arg0);
//         break;
//     case 8: // ground explosion
//         func_802FBDA8_70D458(arg0);
//         break;
//     case 9: // explosion
//         func_802FC108_70D7B8(arg0);
//         break;
//     case 10: // big explosion, brown debris
//         func_802FC5C0_70DC70(arg0);
//         break;
//     case 11: // water splash
//         func_802D760C_6E8CBC(arg0->xPos, arg0->zPos, (arg0->yPos + ((s32) arg0->unk42 >> 1)), arg0->unk30, 8);
//         break;
//     case 12: // small explosion
//         func_802D5B88_6E7238(arg0->xPos, arg0->zPos, arg0->yPos + ((s32) arg0->unk42 >> 1), 0, 0, 0, 0, 0);
//         break;
//     case 13: // explosion
//         func_802FB680_70CD30(arg0);
//         break;
//     case 14: // explosion vertical (wall hit?)
//         func_802FBA40_70D0F0(arg0);
//         break;
//     case 15: // radioactive
//         func_802FC438_70DAE8(arg0->xPos, arg0->zPos, (s16) (arg0->yPos + ((s32) arg0->unk42 >> 1)));
//         break;
//     case 16: // cardboard/earthquake debris?
//         func_802FC6E4_70DD94(arg0);
//         play_sound_effect_at_location(0x79, 0x6000, 0, arg0->xPos, (s32) arg0->zPos, (s32) arg0->yPos, 1.0f);
//         break;
//     case 17: // trophy?
//         func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos, 3);
//         break;
//     case 18: //
//         func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos, 4);
//         break;
//     case 19: // shockwave
//         if (arg0->unk15E == 0) {
//             phi_v0 = ((arg0->unk40 << 5) >> 11);
//             if (arg0->unk158 != 0) {
//                 phi_v0 *= arg0->unk158;
//             }
//         } else {
//             phi_v0 = arg0->unk15E;
//         }
//         if ((arg0->unk168 != NULL) && (arg0->unk168->unk16C->unk80.bit)) {
//             phi_v1 = arg0->unk168->unk16C->unkE6;
//         } else {
//             phi_v1 = -1;
//         }
//         func_802FF184_710834(arg0, 1, arg0->xPos, arg0->zPos, arg0->yPos + (arg0->unk42 >> 1), 0, 0, 100, phi_v0, phi_v1);
//         func_802D7BE0_6E9290(0, 32, arg0->xPos, arg0->zPos, arg0->yPos + (arg0->unk42 >> 1), arg0->unk30 >> 1, 0);
//         break;
//     case 20: // objective with sound?
//         func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos, 5);
//         break;
//     case 21: // big splash?
//         func_802D5B88_6E7238(arg0->xPos, arg0->zPos, arg0->yPos + (arg0->unk42 >> 1), 0x3A, arg0->unk30 << 2, 0, 0, 0);
//         break;
//     case 22: // objective no sound?
//         func_802D9FC4_6EB674(arg0->xPos, arg0->zPos, arg0->yPos, 6);
//         break;
//     case 23: // nuts & bolts (evo exploding?)
//         func_802D7BE0_6E9290(0, 16, arg0->xPos, arg0->zPos, arg0->yPos + (arg0->unk42 >> 1), arg0->unk30 >> 2, 0);
//         break;
//     case 24: // brown debris
//         func_802FC6E4_70DD94(arg0);
//         play_sound_effect_at_location(0x4B, 0x6000, 0, arg0->xPos, arg0->zPos, arg0->yPos, 1.0f);
//         break;
//     case 25: // ground explosion
//         func_802FB85C_70CF0C(arg0);
//         break;
//     default:
//         break;
//     }
// }

void func_802FD190_70E840(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4) {
    s16 i, j;

    for (i = 0; i <= arg2; i++) {
        for (j = 0; j <= arg3; j++) {
            D_803C0740[arg0 + i][arg1 + j].unk0 = arg4;
        }
    }

    func_802DAFAC_6EC65C(arg0, arg1, arg2, arg3);
}

void func_802FD26C_70E91C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4) {
    s16 i, j;

    for (i = 0; i <= arg2; i++) {
        for (j = 0; j <= arg3; j++) {
            D_803C0740[arg0 + i][arg1 + j].unk6 = arg4;
        }
    }

    func_802DAFAC_6EC65C(arg0, arg1, arg2, arg3);
}

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

s32 func_802FD538_70EBE8(Animal *arg0) {
    s16 i;

    if ((D_803E1B02 > 0) && (D_801D9ED8.animals[gCurrentAnimalIndex].animal->state == 0xDD)) {
        for (i = 0; i < 120; i++) {
            if ((D_803E00C0[i].unk2F == 2) &&
                ((arg0 == D_803E00C0[i].unk4) || (arg0 == D_803E00C0[i].unk0))) {
                return 1;
            }
        }
    }
    return 0;
}

s16 func_802FD5DC_70EC8C(Animal *arg0) {
    struct065 *tmp;
    s16 res;

    res = 0;

    for (tmp = D_803DA110[arg0->unk114[0]].unk0; tmp != NULL; tmp = tmp->unk0) {
        if (arg0 == tmp->unk8->unk6C) {
            res += tmp->unk8->unk44 + func_802FD5DC_70EC8C(tmp->unk8);
        }
    }

    return res;
}

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

void func_802FE4C4_70FB74(void) {
    D_803E1D20.unk0 = D_803E1D18.unk0 = D_803F2D50.unk54;
    D_803E1D20.unk1 = D_803E1D18.unk1 = D_803F2D50.unk55;
    D_803E1D20.unk2 = D_803E1D18.unk2 = D_803F2D50.unk56;
    D_803E1D20.unk3 = D_803E1D18.unk3 = D_803F2D50.unk57;
    D_803E1D20.unk4 = D_803E1D18.unk4 = D_803F2D50.unk58;
    D_803E1D20.unk5 = D_803E1D18.unk5 = D_803F2D50.unk59;
    D_803E1D20.unk6 = D_803E1D18.unk6 = D_803F2D50.unk5A;
    D_803E1D20.unk7 = D_803E1D18.unk7 = D_803F2D50.unk5B;

    D_803E1D28 = D_803E1D2A = 0;
    D_803E1D2C = 1;
}

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

void func_802FED68_710418(struct071 *arg0, struct071 *arg1, s16 x, s16 z, s16 y, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, f32 argB, u8 argC) {
    struct077 sp50;
    struct077 sp48;

    func_802F5F44_7075F4(arg5, arg6, arg7, arg8, arg9, &sp50);
    func_802F5F44_7075F4(0, argA << 8, 0, arg8, arg9, &sp48);
    func_802FEE98_710548(
        x + sp50.unk0,
        z + sp50.unk2,
        y + sp50.unk4,
        arg8,
        arg9,
        arg1, // target
        3,
        10,
        argB,
        250,
        (arg0->unk40 * 0xA) >> 0xB,
        sp48.unk0 << 8,
        sp48.unk2 << 8,
        sp48.unk4 << 8,
        arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FEE98_710548.s")

void spawn_temporary_object(s16 x, s16 z, s16 y, s16 scale, u8 lifetime, Animal *owner, s16 arg6, u8 id) {
    struct071 *obj = func_802C9564_6DAC14(id, x, z, func_80310EE4_722594(x, z, owner->unk160) >> 16, 0, 0, 0, 0, 0, scale);
    if (obj != NULL) {
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
        D_803E1BE8[i].unk0 = 0;
    }
}

void func_802FF184_710834(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    s16 i;

    if (D_803A5330_7B69E0 < 10) {
        for (i = 0; i < 10; i++) {
            if (D_803E1BE8[i].unk0 == 0) {
                D_803E1BE8[i].unk2 = arg2;
                D_803E1BE8[i].unk4 = arg3;
                D_803E1BE8[i].unk0 = arg1;
                D_803E1BE8[i].unk1 = 0;
                D_803E1BE8[i].unk6 = arg4;
                D_803E1BE8[i].unkC = arg7;
                D_803E1BE8[i].unkE = arg8;
                D_803E1BE8[i].unk10 = arg9;
                D_803E1BE8[i].unk14 = arg0;
                D_803E1BE8[i].unkA = arg5;
                D_803E1BE8[i].unk8 = arg6;
                D_803A5330_7B69E0 += 1;
                break;
            }
        }
    }
}

// displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF25C_71090C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF540_710BF0.s")

void func_802FF7D4_710E84(Animal *arg0) {
    create_particle_effect(
        arg0->xPos,
        arg0->zPos,
        arg0->yPos,
        124,
        0,
        0,
        0,
        20,
        GPACK_RGBA5551(0, 0, 0, 0),
        GPACK_RGBA5551(0, 0, 0, 0),
        0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FF828_710ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFA20_7110D0.s")

void func_802FFC34_7112E4(struct071 *arg0) {
    s32 pad;
    s32 phi_v1;
    s32 temp_t4;

    if (arg0->unk0 == 1) {
        phi_v1 = MIN(arg0->unk158, 0xFF);
        func_802F2B54_704204(
            arg0->unk4.h,
            arg0->unk8.h,
            arg0->unkC.h,
            (s16) phi_v1,
            arg0->unk200,
            arg0->unk204,
            arg0->unk208);

        if ((arg0->unk163 & 8) == 0) { // probably a bitfield
            temp_t4 = (arg0->unk40 << 6) >> 0xB;
            func_8034BD20_75D3D0(
                arg0->unk4.h,
                arg0->unk8.h,
                arg0->unkC.h,
                (s16) ((arg0->unk2C << 8) / 360),
                D_803A8374_7B9A24,
                (s16) temp_t4,
                (s16) temp_t4,
                (s16) phi_v1,
                arg0->unk200,
                arg0->unk204,
                arg0->unk208,
                2,
                0);
        }
    }
}

void func_802FFD50_711400(struct071 *arg0) {
    f32 sp34;
    f32 sp1C; // pad
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;

    temp_f16 = arg0->unk1C.w / 65536.0f;
    temp_f12 = arg0->unk20.w / 65536.0f;
    temp_f18 = arg0->unk24 / 65536.0f;
    sp34 = sqrtf((temp_f16 * temp_f16) + (temp_f12 * temp_f12) + (temp_f18 * temp_f18));

    if (ABSF(sp34) > 0.0f) {
        temp_f14 = temp_f12 / sp34;
        if (temp_f14 == 0.0f) {
            temp_f14 = 0.001f;
        }

        arg0->unk2C = func_801286B8(temp_f16 / sp34, temp_f14);
        arg0->unk2E = func_8012835C((temp_f18 / sp34) * 256.0f);

        if ((arg0->unk2E < 0) || (arg0->unk2E > 360)) {
            arg0->unk2E = (arg0->unk2E + 1440) % 360;
        }
    }
}

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

// used by object 151
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

void func_802FFF70_711620(struct071 *arg0) {
    func_8032CED0_73E580(&arg0->unk20.h[1], SFX_UNKNOWN_159, 0x3000, 1.0f, 0, 0, arg0->unk4.h, arg0->unk8.h, arg0->unkC.h, 0, 0, 0);
}

// #pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7070A0/func_802FFFD0_711680.s")
void func_802FFFD0_711680(struct071 *arg0) {
    u8 red, green, blue;

    // same line required for regalloc
    if (arg0->unk16C->unk0 == 60) {
        red = 0xFF; green = 0xFF; blue = 0xFF;
    } else if (arg0->unk16C->unk0 == 59) {
        red = 0xFF; green = 0xA0; blue = 0xFF;
    } else if (arg0->unk16C->unk0 == 58) {
        red = 0xFF; green = 0; blue = 0xFF;
    }

    func_802F2B54_704204(
        arg0->unk4.h,
        arg0->unk8.h,
        arg0->unkC.h,
        128,
        red,
        green,
        blue);
    if ((arg0->unk163 & 8) == 0) {
        s32 tmp = (arg0->unk40 << 5) >> 11;
        func_8034BD20_75D3D0(
            arg0->unk4.h,
            arg0->unk8.h,
            arg0->unkC.h,
            ((arg0->unk2C << 8) / 360),
            D_803A8374_7B9A24,
            tmp,
            tmp,
            64,
            red,
            green,
            blue,
            2,
            0);
    }
}
