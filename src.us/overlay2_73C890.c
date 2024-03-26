#include <ultra64.h>
#include "common.h"

#ifdef NON_MATCHING
// ESA: func_8007E6A0
// CURRENT (16), just the stack
s32 func_8032B1E0_73C890(Animal *arg0, s16 arg1, s16 arg2, s32 *arg3, s32 *arg4) {
    s32 pad[3];

    s16 temp_t1; // sp92?

    s16 var_a0;
    s16 index;

    Collision *collision; // sp88
    s32 temp_v0; // sp84
    s32 temp_v1; // sp80

    s32 var_t5;

    s32 sp78;
    s32 var_t0; // sp74?
    s32 var_t3; // sp70 ?
    s32 sp6C;
    s32 sp68;
    s16 i;
    s16 j;

    s16 var_a2;
    s16 temp_lo;
    s16 temp_lo_2;
    s16 temp_t6;

    s32 sp58;
    s32 sp54;
    s32 sp50;

    s32 var_t1;

    collision = arg0->unk16C->collision;
    if (collision == NULL) {
        *arg3 = arg0->position.yPos.w + (arg0->unk42 << 0x10);
        *arg4 = arg0->position.yPos.w;
        return 1;
    }

    temp_t6 = (arg0->unk40 << 6) >> 0xC;

    if ((arg1 >= (arg0->position.xPos.h - temp_t6)) && (arg1 < (arg0->position.xPos.h + temp_t6)) &&
        (arg2 >= (arg0->position.zPos.h - temp_t6)) && (arg2 < (arg0->position.zPos.h + temp_t6))) {

        temp_t1 = temp_t6 * 2;

        switch (arg0->yRotation) {              /* irregular */
        case 90:
            var_a0 = (arg0->position.zPos.h + temp_t6) - arg2;
            var_a2 = (arg1 - arg0->position.xPos.h) + temp_t6;
            break;
        case 180:
            var_a0 = (arg0->position.xPos.h + temp_t6) - arg1;
            var_a2 = (arg0->position.zPos.h + temp_t6) - arg2;
            break;
        case 270:
            var_a0 = (arg2 - arg0->position.zPos.h) + temp_t6;
            var_a2 = (arg0->position.xPos.h + temp_t6) - arg1;
            break;
        default:
            var_a0 = (arg1 - arg0->position.xPos.h) + temp_t6;
            var_a2 = (arg2 - arg0->position.zPos.h) + temp_t6;
            break;
        }

        temp_lo = (var_a0 << 5) / temp_t1;
        temp_lo_2 = (var_a2 << 5) / temp_t1;

        if (temp_t1 >= 0x40) {
            temp_v0 = var_a0 - ((temp_lo * temp_t1) >> 5);
            temp_v1 = var_a2 - ((temp_lo_2 * temp_t1) >> 5);

            if (temp_v0 < temp_v1) {

                index = temp_lo + (temp_lo_2 << 5);
                sp58 = collision->data[index];

                if (collision->data[index] != 0) {
                    for (i = 31; (collision->data[index] & (1 << i)) == 0; i--);

                    sp68 = i;
                    sp78 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((i - 15) * temp_t1) << 0xB);
                } else {
                    sp78 = arg0->position.yPos.w;
                    sp68 = 0;
                }

                if ((temp_lo_2 + 1) >= 0x20) {
                    var_t0 = arg0->position.yPos.w;
                    var_t5 = 0;
                    sp54 = 0;
                } else {
                    index = temp_lo + ((temp_lo_2 + 1) << 5);
                    sp54 = collision->data[index];

                    if (collision->data[index] != 0) {
                        for (i = 31; (collision->data[index] & (1 << i)) == 0; i--);
                        var_t0 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((i - 15) * temp_t1) << 0xB);
                        var_t5 = i;
                    } else {
                        var_t0 = arg0->position.yPos.w;
                        var_t5 = 0;
                    }
                }

                if (((temp_lo + 1) >= 0x20) || ((temp_lo_2 + 1) >= 0x20)) {
                    var_t1 = 0;
                    var_t3 = arg0->position.yPos.w;
                    sp50 = 0;
                } else {
                    index = temp_lo + ((temp_lo_2 + 1) << 5) + 1;
                    sp50 = collision->data[index];

                    if (collision->data[index] != 0) {
                        for (i = 31; (collision->data[index] & (1 << i)) == 0; i--);

                        var_t1 = i;
                        var_t3 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((i - 15) * temp_t1) << 0xB);
                    } else {
                        var_t3 = arg0->position.yPos.w;
                        var_t1 = 0;
                    }
                }

                if (func_8032BD5C_73D40C(sp58, sp54, sp50, sp68, var_t5, var_t1) == 0) {
                    if (sp68 != 0) {
                        *arg3 = sp78;
                    } else {
                        return 0;
                    }
                } else {
                    *arg3 = ((((var_t3 - var_t0) * temp_v0) + ((var_t0 - sp78) * temp_v1)) / (temp_t1 >> 5)) + sp78;
                }

                index = temp_lo + (temp_lo_2 << 5);
                if (collision->data[index] != 0) {
                    for (j = 0; (collision->data[index] & (1 << j)) == 0; j++);

                    *arg4 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((j - 16) * temp_t1) << 0xB);
                } else {
                    return 0;
                }
            } else {
                index = temp_lo + (temp_lo_2 << 5);
                sp58 = collision->data[index];

                if (collision->data[index] != 0) {
                    for (i = 31; (collision->data[index] & (1 << i)) == 0; i--);

                    sp68 = i;
                    sp78 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((i - 15) * temp_t1) << 0xB);
                } else {
                    sp78 = arg0->position.yPos.w;
                    sp68 = 0;
                }

                if (((temp_lo + 1) >= 0x20) || ((temp_lo_2 + 1) >= 0x20)) {
                    var_t1 = 0;
                    var_t3 = arg0->position.yPos.w;
                    sp50 = 0;
                } else {
                    index = (temp_lo + 1) + ((temp_lo_2 + 1) << 5) ;
                    sp50 = collision->data[index];

                    if (collision->data[index] != 0) {
                        for (i = 31; (collision->data[index] & (1 << i)) == 0; i--);

                        var_t3 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((i - 15) * temp_t1) << 0xB);
                        var_t1 = i;
                    } else {
                        var_t3 = arg0->position.yPos.w;
                        var_t1 = 0;
                    }
                }

                if ((temp_lo + 1) >= 0x20) {
                    var_t0 = arg0->position.yPos.w;
                    sp6C = 0;
                } else {
                    index = (temp_lo + 1) + (temp_lo_2 << 5);
                    sp6C = collision->data[index];

                    if (collision->data[index] != 0) {
                        for (i = 0x1F; (collision->data[index] & (1 << i)) == 0; i--);
                        var_t0 = arg0->position.yPos.w + (arg0->unk42 << 0xF);
                        var_t0 += (((i - 0xF) * temp_t1) << 0xB);
                    } else {
                        var_t0 = arg0->position.yPos.w;
                    }
                }

                if (func_8032BD5C_73D40C(sp58, sp50, sp6C, sp68, 0, var_t1) == 0) {
                    if (sp68 != 0) {
                        *arg3 = sp78;
                    } else {
                        return 0;
                    }
                } else {
                    *arg3 = ((((var_t0 - sp78) * temp_v0) + ((var_t3 - var_t0) * temp_v1)) / (temp_t1 >> 5)) + sp78;
                }

                index = temp_lo + (temp_lo_2 << 5);
                if (collision->data[index] != 0) {
                    for (j = 0; (collision->data[index] & (1 << j)) == 0; j++);

                    *arg4 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((j - 16) * temp_t1) << 0xB);
                } else {
                    return 0;
                }
            }

            return 1;
        }

        index = temp_lo + (temp_lo_2 << 5);
        if (collision->data[index] != 0) {

            for (i = 31; (collision->data[index] & (1 << i)) == 0; i--);
            for (j = 0;  (collision->data[index] & (1 << j)) == 0; j++);

            *arg3 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((i - 15) * temp_t1) << 0xB);
            *arg4 = arg0->position.yPos.w + (arg0->unk42 << 0xF) + (((j - 16) * temp_t1) << 0xB);
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73C890/func_8032B1E0_73C890.s")
#endif

// check some flag?
// ESA: func_8007EFB0
u8 func_8032BCF8_73D3A8(s32 arg0, s16 arg1) {
    if (arg1 >= 0) {
        while ((2 << arg1) & arg0) {
            if (--arg1 < 0) {
                break;
            }
        }
    }
    return (arg1 + 1) == 0;
}

// ESA: func_8007F010
s32 func_8032BD5C_73D40C(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    if (arg0 == 0) {
        if ((func_8032BCF8_73D3A8(arg1, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg1 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg2 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg1, arg4) == 0)) {
            return 0;
        }
    }
    return 1;
}

void func_8032BE28_73D4D8(Animal *arg0) {
    s16 index;
    Collision *collision;
    s16 x;
    s16 y1;
    s16 y2;
    s16 i;
    s16 j;

    if (arg0->unk16C->collision == NULL) {
        return;
    }

    collision = arg0->unk16C->collision;
    gSPDisplayList(D_801D9E8C++, D_01003548_3CE18);

    if (collision != NULL) {
        x = (D_803D5540 >> 3) % 32;
        for (i = 0; i < 32; i++) {
            index = x + (i << 5);
            if (collision->data[index] != 0) {
                for (y1 = 0;  (collision->data[index] & (1 << y1)) == 0; y1++);
                for (y2 = 31; (collision->data[index] & (1 << y2)) == 0; y2--);

                if (y1 == y2) {
                    // arg0, x, y, z, r, g, b
                    func_8032C0EC_73D79C(arg0, x, i, y1, 0, 200, 200);  // turquoise
                } else {
                    func_8032C0EC_73D79C(arg0, x, i, y1, 0, 200, 0);    // green
                    func_8032C0EC_73D79C(arg0, x, i, y2, 0, 0,   200);  // blue

                    for (j = y1; j < y2; j++) {
                        if ((collision->data[index] & (1 << j)) == 0) {
                            // red
                            func_8032C0EC_73D79C(arg0, x, i, j, 255, 0, 0);
                        }
                    }
                }
            }
        }
    }
}

void func_8032C0EC_73D79C(Animal *arg0, s16 x, s16 y, s16 z, s16 r, s16 g, s16 b) {

    if (D_803D3434->usedModelViewMtxs < 240) {
        gDPSetPrimColor(D_801D9E8C++, 0, 0, r, g, b, 0xFF);
        guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], (2.0 * (f32) x) - 30.0, (2.0 * (f32) y) - 30.0, (2.0 * (f32)z) - 32.0);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        gSPDisplayList(D_801D9E8C++, D_0103B6F0_74FC0);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}
