#include <ultra64.h>
#include "common.h"

s32 func_802B6088_6C7738(Animal *arg0, Animal *arg1, void*, void*, s16 x1, s16 y1, s16 z1, s16 x2, s16 y2, s16 z2);
s32 func_802B6948_6C7FF8(void *arg0, void *arg1, void **arg2, void **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);
s32 func_802B6B5C_6C820C(void);
s32 func_80313448_724AF8(Animal *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_802B75B4_6C8C64(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
s32 func_802B6F6C_6C861C(Animal *arg0, Animal *arg1, s32 **arg2, s32 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9);

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B4D20_6C63D0.s")

s32 func_802B5E48_6C74F8(Animal *arg0, Animal *arg1, s32 (**arg2)(Animal *arg0, Animal *arg1, void*, void*, s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z3), u8 *arg3) {
    struct035 *a0; // arg0
    struct035 *a1; // arg1
    s32 res = 0;

    *arg2 = NULL;
    a0 = arg0->unk16C;
    if (a0->unk15 == 4) {
      a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            res = 6;
            *arg2 = func_802B750C_6C8BBC;
            *arg3 = 0;
        } else if (a1->unk18 != 0) {
            if (arg1->unkC0.a.unkD0.m[0][0] != 0) {
                res = 7;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 0;
            } else {
                res = 7;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 0;
            }
        } else {
            if (arg1->unkC0.a.unkD0.m[0][0] != 0) {
                res = 5;
                *arg2 = func_802B6B5C_6C820C;
                *arg3 = 1;
            }
        }
    } else if (a0->unk18 != 0) {
        a1 = arg1->unk16C;
        if (a1->unk15 == 4) {
            if (arg1->unkC0.a.unkD0.m[0][0] != 0) {
                res = 7;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 1;
            } else {
                res = 8;
                *arg2 = func_802B6F6C_6C861C;
                *arg3 = 1;
            }
        } else if (a1->unk18 != 0) {
            if ((arg0->unkC0.a.unkD0.m[0][0] != 0) && (arg1->unkC0.a.unkD0.m[0][0] != 0)) {
                res = 1;
                *arg2 = func_802B6088_6C7738;
                if ((u32) arg0 < (u32) arg1) {
                    *arg3 = 0;
                } else {
                    *arg3 = 1;
                }
            } else {
                if (arg0->unkC0.a.unkD0.m[0][0] != 0) {
                    res = 1;
                    *arg2 = func_802B6088_6C7738;
                    *arg3 = 0;
                } else {
                    res = 9;
                    *arg2 = func_802B75B4_6C8C64;
                    *arg3 = 0;
                }

            }
        } else {
            res = 0;
            if (arg1->unkC0.a.unkD0.m[0][0] != NULL) {
                res = 2;
                *arg2 = func_802B6088_6C7738;
                *arg3 = 1;
            }
        }
    } else {
        res = 0;
        if (arg0->unkC0.a.unkD0.m[0][0] != NULL) {
            a1 = arg1->unk16C;
            if (a1->unk15 == 4) {
                res = 4;
                *arg2 = func_802B6B5C_6C820C;
                *arg3 = 0;
            } else if (a1->unk18 != 0) {
                res = 1;
                *arg2 = func_802B6088_6C7738;
                *arg3 = 0;
            } else {
                res = 0;
                if (arg1->unkC0.a.unkD0.m[0][0] != NULL) {
                    res = 3;
                    *arg2 = func_802B6948_6C7FF8;
                    *arg3 = 0;
                }
            }
        }
    }

    if (res == 0) {
        *arg2 = func_802B6948_6C7FF8;
        *arg3 = 0;
    }
    return res;
}

// yuck
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6088_6C7738.s")

// shit about unkD0
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6948_6C7FF8.s")

// more shit about unkD0
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6B5C_6C820C.s")

#if 0
// complete junk so far
s32 func_802B6F6C_6C861C(Animal *arg0, Animal *arg1, s32 **arg2, s32 **arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s16 sp16;
    s32 sp10;
    s32 sp4;
    s16 temp_t8;
    s16 temp_t8_2;
    s16 temp_t9;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v0_8;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 var_a0;
    s16 var_t0;
    s16 var_t1;
    struct035_ptr *temp_t4;
    s32 temp_lo;
    s32 temp_t2;
    s32 temp_t5;
    s32 ret;

    static s16 D_803D60F8;
    static s16 D_803D60FC;
    static s32 D_803D6100;

    ret = 0;

    temp_t4 = arg1->unk16C->unk18;
    D_803D60F8 = 0;
    D_803D60F8 = 0;
    D_803D6100 = 0;

    temp_t2 = (s32) (arg1->unk40 << 6) >> 0xB;
    temp_t5 = (((arg0->unk42 << 0xF) + arg6) - arg9) - (arg1->unk42 << 0xF);
    temp_v0 = ((s32) ((s32) (arg4 - arg7) >> 0xB) / temp_t2) + 0x10;
    var_t0 = temp_v0;
    temp_v1 = ((s32) ((s32) (arg5 - arg8) >> 0xB) / temp_t2) + 0x10;
    var_t1 = temp_v1;
    temp_lo = (s32) ((arg0->unk30 + arg0->unk32) * 0x10) / temp_t2;
    var_a0 = temp_lo;
    // var_a0 = sp4;
    if (temp_lo <= 0) {
        var_a0 = 1;
    }
    // temp_t8 = arg1->yRotation;
    // sp10 = (s32) temp_t8;
    switch (arg1->yRotation) {                              /* irregular */
    case 90:
        var_t0 = 0x20 - temp_v1;
        var_t1 = temp_v0;
        break;
    case 180:
        var_t0 = 0x20 - temp_v0;
        var_t1 = 0x20 - temp_v1;
        break;
    case 270:
        var_t0 = temp_v1;
        var_t1 = 0x20 - temp_v0;
        break;
    }
    if ((var_t0 >= 0) && (var_t0 < 0x20) && (var_t1 >= 0) && (var_t1 < 0x20)) {
        temp_v1_2 = ((s32) (temp_t5 >> 0xB) / temp_t2) + 0x10;
        temp_v0_2 = temp_v1_2 + var_a0;
        if ((temp_v0_2 >= 0) && (temp_v0_2 < 0x20) && (temp_t4[var_t0].unk8[(var_t1 << 5)] & (1 << temp_v0_2))) {
            ret = 1;
            D_803D6100 += 2;
        }
        temp_v0_3 = temp_v1_2 - var_a0;
        if ((temp_v0_3 >= 0) && (temp_v0_3 < 0x20) && (temp_t4[var_t0].unk8[(var_t1 << 5)] & (1 << temp_v0_3))) {
            ret = 1;
            D_803D6100 -= 2;
        }
    }

    temp_v1_3 = ((s32) (temp_t5 >> 0xB) / temp_t2) + 0x10;
    if ((temp_v1_3 >= 0) && (temp_v1_3 < 0x20)) {
        if (var_t0 >= 0) {
            temp_v0_4 = var_t1 + var_a0;
            if (var_t0 < 0x20) {
                temp_v0_5 = var_t1 - var_a0;
                if ((temp_v0_4 >= 0) && (temp_v0_4 < 0x20) && (temp_t4[var_t0].unk8[(temp_v0_4 << 5)] & (1 << temp_v1_3))) {
                    ret = 1;
                    D_803D60FC += 2;
                }
                if ((temp_v0_5 >= 0) && (temp_v0_5 < 0x20) && (temp_t4[var_t0].unk8[(temp_v0_5 << 5)] & (1 << temp_v1_3))) {
                    ret = 1;
                    D_803D60FC -= 2;
                }
            }
        }
        if (var_t1 >= 0) {
            temp_v0_6 = var_t0 + var_a0;
            if (var_t1 < 0x20) {
                temp_v0_7 = var_t0 - var_a0;
                if ((temp_v0_6 >= 0) && (temp_v0_6 < 0x20) && (temp_t4[temp_v0_6].unk8[(var_t1 << 5)] & (1 << temp_v1_3))) {
                    ret = 1;
                    D_803D60F8 += 2;
                }
                if ((temp_v0_7 >= 0) && (temp_v0_7 < 0x20) && (temp_t4[temp_v0_7].unk8[(var_t1 << 5)] & (1 << temp_v1_3))) {
                    ret = 1;
                    D_803D60F8 -= 2;
                }
            }
        }
    }

    if (ret != 0) {
        switch (arg1->yRotation) {
        case 90:
            temp_t9 = D_803D60FC;
            D_803D60FC = -D_803D60F8;
            D_803D60FC = temp_t9;
            break;
        case 180:
            D_803D60F8 = -D_803D60F8;
            D_803D60F8 = -D_803D60FC;
            break;
        case 270:
            temp_t9 = D_803D60F8;
            D_803D60F8 = -D_803D60FC;
            D_803D60F8 = temp_t9;
            break;
        }
        *arg2 = &D_803D60F8;
        *arg3 = &D_803D60F8;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B6F6C_6C861C.s")
#endif

#ifdef NON_MATCHING
// is the function definition wrong??
u8 func_802B750C_6C8BBC(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    u8 check0;
    u8 check1;
    s32 velocity0;
    s32 velocity1;

    velocity0 = arg0->unk30 + arg1->unk30;
    velocity1 = arg0->unk32 + arg1->unk32;

    check0 = (((arg4 - velocity0) < arg7) && ((arg4 + velocity0) > arg7) && ((arg5 - velocity1) < arg8) && ((arg5 + velocity1) > arg8));

    check1 = (((arg9 - arg0->unk42) < arg6) && ((arg6 - arg1->unk42) < arg9));

    return check0 && check1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B750C_6C8BBC.s")
#endif

s32 func_802B75B4_6C8C64(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    return 0;
}

// broken expansion pak function
#if 0
s32 func_802B75CC_6C8C7C(Animal *arg0, Animal *arg1, s32 x, s32 y, s32 z, u8 *arg5, u16 arg6) {
    Animal *temp_v1;
    struct065 *var_s5;

    for (var_s5 = D_803DA110[arg0->unk114[0]].next; var_s5 != NULL; var_s5 = var_s5->next) {
        temp_v1 = var_s5->animal;

        if ((arg0 != temp_v1) && (arg0 != arg1) && ((D_803B1BAC_7C325C[temp_v1->unk16C->unk2]) & (1 << (0xF - arg0->unk16C->unk2)))) {

            if ((ABS(temp_v1->xPos.h - x) < (temp_v1->unk34 + arg0->unk34)) &&
                (ABS(temp_v1->zPos.h - y) < (temp_v1->unk34 + arg0->unk34)) &&
                ((ABS((temp_v1->yPos.h + (temp_v1->unk42 >> 1)) - (z + arg0->unk42 >> 1)) < (temp_v1->unk36 + arg0->unk36)))) {

                if ((arg0 != temp_v1->unk68) && (temp_v1 != arg0->unk68) && ((arg0 != temp_v1->unk70) || (arg0->unk16C->unk15 != 4)) && ((temp_v1 != arg0->unk70) || (temp_v1->unk16C->unk15 != 4)) && (temp_v1->state != 0x1E) && (arg0->state != 0x1E) && (temp_v1->state != 0x1F) && (arg0->state != 0x1F) && ((temp_v1->unk15C == 0) || (arg0 != temp_v1->unk168)) && ((arg0->unk15C == 0) || (temp_v1 != arg0->unk168)) && ((arg6 == 0) || (temp_v1->unk16C->objectType < 0x100))) {
                    func_802B5E48_6C74F8(temp_v1, arg0, D_803D60D0, D_803D60D4);

                    if (((*D_803D60D4 != 0) && (D_803D60D0(arg0, temp_v1, &D_803D60D8, &D_803D60DC, x, y, z, temp_v1->xPos.w, temp_v1->zPos.w, temp_v1->yPos.w) != 0)) ||
                        ((*D_803D60D4 == 0) && (D_803D60D0(temp_v1, arg0, &D_803D60D8, &D_803D60DC, temp_v1->xPos.w, temp_v1->zPos.w, temp_v1->yPos.w, x, y, z) != 0)))  {

                        if ((arg0->unk16C->unk2 == 9) || (temp_v1->unk16C->unk2 == 9) || (arg0->unk16C->unk2 == 8) || (temp_v1->unk16C->unk2 == 8)) {
                            return 0;
                        }

                        z += D_803A05B4_7B1C64;

                        if ((((*D_803D60D4 != 0) && (D_803D60D0(arg0, temp_v1, &D_803D60D8, &D_803D60DC, x, y, z, temp_v1->xPos.w, temp_v1->zPos.w, temp_v1->yPos.w) != 0))) ||
                             ((*D_803D60D4 == 0) && (D_803D60D0(temp_v1, arg0, &D_803D60D8, &D_803D60DC, temp_v1->xPos.w, temp_v1->zPos.w, temp_v1->yPos.w, x, y, z) != 0))) {
                            *arg5 = 1;
                            if ((arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (temp_v1->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(temp_v1);
                            }
                            if ((temp_v1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (arg0->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(arg0);
                            }
                            func_802FD674_70ED24(arg0, temp_v1);
                            return 1;
                        } else {
                            *arg5 = 0;
                            if ((arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (temp_v1->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(temp_v1);
                            }
                            if ((temp_v1 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) && (arg0->unk16C->objectType == OBJECT_TV_SCREEN)) {
                                func_8038F5F8_7A0CA8(arg0);
                            }
                            func_802FD674_70ED24(arg0, temp_v1);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B75CC_6C8C7C.s")
#endif

#if 0
// so so far away it hurts
u8 func_802B7BC8_6C9278(Animal *arg0, Animal *arg1) {
    Vertex spC4;
    Vertex spB4;
    Vertex spA8;
    Vertex sp9C;

    s32 x1;
    s32 y1;
    s32 z1;
    s32 x2;
    s32 y2;
    s32 z2; // sp84?

    u8 sp82;
    u8 sp80;

    s16 i;

    s32 var_s3;
    u8 var_v0;

    u16 temp_v0_2;
    u16 temp_v1_4;
    u8 var_a1;

    s32 *xPos1, *zPos1, *yPos1, *xPos2, *zPos2, *yPos2;

    if (D_803D60D0 == func_802B6088_6C7738) {
        if (*D_803D60D4 != 0) {
            x1 = D_803D60DC->unk0;
            y1 = D_803D60DC->unk4;
            z1 = D_803D60DC->unk8;
            x2 = -x1;
            y2 = -y1;
            z2 = -z1;
        } else {
            x2 = D_803D60DC->unk0;
            y2 = D_803D60DC->unk4;
            z1 = D_803D60DC->unk8; // is this correct?
            x1 = -x2;
            y1 = -y2;
            z2 = -z1;
        }
    } else {
        spB4.x = arg0->xPos.w / 65536.0;
        spB4.y = arg0->zPos.w / 65536.0;
        spB4.z = (arg0->yPos.w + (arg0->unk42 << 0xF)) / 65536.0;

        spA8.x = arg1->xPos.w / 65536.0;
        spA8.y = arg1->zPos.w / 65536.0;
        spA8.z = (arg1->yPos.w + (arg1->unk42 << 0xF)) / 65536.0;

        vector_subtract(&spA8, &spB4, &sp9C);
        normalize_vector(&sp9C, &spC4);
        vector_multiply_by(&spC4, 2.0f, &sp9C);

        spC4.x = sp9C.x;
        spC4.y = sp9C.y;
        spC4.z = sp9C.z;

        x1 = -spC4.x * 65536.0;
        y1 = -spC4.y * 65536.0;
        z1 = -spC4.z * 65536.0;

        x2 = spC4.x * 65536.0;
        y2 = spC4.y * 65536.0;
        z2 = spC4.z * 65536.0;
    }

    if ((arg0->unk16C->unk80.bit2 != 0) || (arg0->unk4C.unk27 == 0) || (arg0->unk4A != 0) || ((x1 == 0) && (y1 == 0) && (z1 == 0))) {
        var_a1 = 0;
    } else {
        var_a1 = 1;
    }

    var_s3 = 1;

    if ((arg1->unk16C->unk80.bit2 != 0) || (arg1->unk4C.unk27 == 0) || (arg1->unk4A != 0) || ((x2 == 0) && (y2 == 0) && (z2 == 0))) {
        var_s3 = 0;
    }
    if (arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        var_s3 = 0;
    }
    if (arg1->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        var_a1 = 0;
    }

    temp_v0_2 = arg0->unk44;
    temp_v1_4 = arg1->unk44;
    if ((temp_v0_2 * 3) < temp_v1_4) {
        if (var_a1 == 1) {
            var_s3 = 0;
        }
    } else if ((temp_v1_4 * 3) < temp_v0_2) {
        if (var_s3 == 1) {
            var_a1 = 0;
        }
    } else if ((temp_v0_2 * 2) < temp_v1_4) {
        x2 >>= 1;
        y2 >>= 1;
        z2 >>= 1;
    } else if ((temp_v1_4 * 2) < temp_v0_2) {
        x1 >>= 1;
        y1 >>= 1;
        z1 >>= 1;
    }


    i = 0;
    var_v0 = 1;

    while (((var_a1 != 0) || (var_s3 != 0)) && (var_v0 != 0) && (i < 16)) {
        xPos1 = &arg0->xPos.w;
        zPos1 = &arg0->zPos.w;
        yPos1 = &arg0->yPos.w;

        xPos2 = &arg1->xPos.w;
        zPos2 = &arg1->zPos.w;
        yPos2 = &arg1->yPos.w;

        if (var_a1 != 0) {
            if ((func_802B75CC_6C8C7C(arg0, arg1, x1, y1, z1, &sp80, 0) == 0) && (func_80313448_724AF8(arg0, x1, y1, z1) != 0)) {
                arg0->yPos.w = MAX(arg0->yPos.w, func_80310EE4_722594(arg0->xPos.h, arg0->zPos.h, arg0->unk160));
            } else {
                var_a1 = 0; // break
            }
        }
        if (var_s3 != 0) {
            if ((func_802B75CC_6C8C7C(arg1, arg0, x2, y2, z2, &sp80, 0) == 0) && (func_80313448_724AF8(arg1, x2, y2, z2) != 0)) {
                arg1->yPos.w = MAX(arg1->yPos.w, func_80310EE4_722594(arg1->xPos.h, arg1->zPos.h, arg1->unk160));
            } else {
                var_s3 = 0; // break
            }
        }

        if (*D_803D60D4 != 0) {
           var_v0 = D_803D60D0(arg1, arg0, &D_803D60D8, &D_803D60DC, *xPos2, *zPos2, *yPos2, *xPos1, *zPos1, *yPos1);
        } else {
           var_v0 = D_803D60D0(arg0, arg1, &D_803D60D8, &D_803D60DC, *xPos1, *zPos1, *yPos1, *xPos2, *zPos2, *yPos2);
        }

        if ((D_803D60D0 == func_802B6088_6C7738) && (var_v0 != 0)) {
            if (*D_803D60D4 != 0) {
                x1 = D_803D60DC->unk0;
                y1 = D_803D60DC->unk4;
                z1 = D_803D60DC->unk8;
                x2 = -x1;
                y2 = -y1;
                z2 = -z1;
            } else {
                x2 = D_803D60DC->unk0;
                y2 = D_803D60DC->unk4;
                z1 = D_803D60DC->unk8;
                x1 = -x2;
                y1 = -y2;
                z2 = -z1;
            }
        }
        i++;
    }

    arg0->unk10 = arg0->xPos.w + arg0->xVelocity.w;
    arg0->unk14 = arg0->zPos.w + arg0->zVelocity.w;
    arg0->unk18.w = arg0->yPos.w + arg0->yVelocity.w;
    arg1->unk10 = arg1->xPos.w + arg1->xVelocity.w;
    arg1->unk14 = arg1->zPos.w + arg1->zVelocity.w;
    arg1->unk18.w = arg1->yPos.w + arg1->yVelocity.w;

    return (var_v0 == 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/collision/func_802B7BC8_6C9278.s")
#endif

void func_802B8304_6C99B4(Animal *arg0, Animal *arg1) {
    f32 var_f2;
    f32 var_f14;

    f32 sp24;
    f32 sp20;
    f32 sp1C;

    f32 var_f16;
    f32 var_f12;
    s16 var_v1;

    if (arg1->unk16C->unk18 != NULL) {
        var_v1 = MAX(0x800, arg1->unk40);
        if (((arg0->yPos.h + (arg0->unk42 >> 1)) < (arg1->yPos.h + (arg1->unk42 >> 1)))) {
            var_v1 = MIN(var_v1, 0x800);
        }

        arg0->xVelocity.w -= (D_803D60DC->unk0 * var_v1) >> 0xB;
        arg0->zVelocity.w -= (D_803D60DC->unk4 * var_v1) >> 0xB;
        arg0->yVelocity.w -= (D_803D60DC->unk8 * var_v1) >> 0xB;
        return;
    }

    var_f2 = (arg0->xPos.w - arg1->xPos.w) / 65536.0;
    var_f14 = (arg0->zPos.w - arg1->zPos.w) / 65536.0;

    if (arg1->unk16C->unk15 == 4) {
        if (var_f2 < 0.0f) {
            var_f2 = MIN(0.0f, var_f2 + (arg1->unk30 - 2));
        } else {
            var_f2 = MAX(0.0f, var_f2 - (arg1->unk30 - 2));
        }

        if (var_f14 < 0.0f) {
            var_f14 = MIN(0.0f, var_f14 + (arg1->unk32 - 2));
        } else {
            var_f14 = MAX(0.0f, var_f14 - (arg1->unk32 - 2));
        }
    }

    sp24 = sqrtf((var_f2 * var_f2) + (var_f14 * var_f14));
    sp20 = ((arg0->xVelocity.w - arg1->xVelocity.w) / 65536.0);
    sp1C = ((arg0->zVelocity.w - arg1->zVelocity.w) / 65536.0);
    if (sqrtf(SQ(sp20) + SQ(sp1C)) < 4.0) {
        if (sp24 != 0.0) {
            var_f16 = ((MAX(0x800, arg1->unk40) * (var_f2 * 0.7)) / (sp24 * 2048.0f));
            var_f12 = ((MAX(0x800, arg1->unk40) * (var_f14 * 0.7)) / (sp24 * 2048.0f));
            if (((sp20 * var_f16) + (sp1C * var_f12)) < 0.0f) {
                arg0->xVelocity.w = arg1->xVelocity.w;
                arg0->zVelocity.w = arg1->zVelocity.w;
            }
        } else {
            var_f16 = 0.7f;
            var_f12 = -0.7f;
        }
        arg0->xVelocity.w += (s32) (var_f16 * 65536.0);
        arg0->zVelocity.w += (s32) (var_f12 * 65536.0);
    }
}
