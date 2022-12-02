#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032D680_73ED30.s")
// is this a loop? bunch of macros? what?
// void func_8032D680_73ED30(void) {
//     Mtx *temp_v0;
//     Mtx *temp_v0_2;
//
//     temp_v0_2 = &D_80204278->unk37490;
//
//     D_80204278->unk38A10[0][0] = (f32) ((temp_v0_2->m[0][0] & 0xFFFF0000      ) | ((temp_v0_2->m[2][0] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][0] = (f32) ((temp_v0_2->m[0][0]              << 16) |  (temp_v0_2->m[2][0] & 0xFFFF)           ) / 65536.0;
//     D_80204278->unk38A10[0][1] = (f32) ((temp_v0_2->m[0][2] & 0xFFFF0000      ) | ((temp_v0_2->m[2][2] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][1] = (f32) ((temp_v0_2->m[0][2]              << 16) |  (temp_v0_2->m[2][2] & 0xFFFF)           ) / 65536.0;
//
//     D_80204278->unk38A10[0][2] = (f32) ((temp_v0_2->m[1][0] & 0xFFFF0000      ) | ((temp_v0_2->m[3][0] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][2] = (f32) ((temp_v0_2->m[1][0]              << 16) |  (temp_v0_2->m[3][0] & 0xFFFF)           ) / 65536.0;
//     D_80204278->unk38A10[0][3] = (f32) ((temp_v0_2->m[1][2] & 0xFFFF0000      ) | ((temp_v0_2->m[3][2] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][3] = (f32) ((temp_v0_2->m[1][2]              << 16) |  (temp_v0_2->m[3][2] & 0xFFFF)           ) / 65536.0;
//
//     D_80204278->unk38A10[2][0] = (f32) ((temp_v0_2->m[0][1] & 0xFFFF0000      ) | ((temp_v0_2->m[2][1] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[2][1] = (f32) ((temp_v0_2->m[0][3] & 0xFFFF0000      ) | ((temp_v0_2->m[2][3] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[2][2] = (f32) ((temp_v0_2->m[1][1] & 0xFFFF0000      ) | ((temp_v0_2->m[3][1] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[2][3] = (f32) ((temp_v0_2->m[1][3] & 0xFFFF0000      ) | ((temp_v0_2->m[3][3] & 0xFFFF0000) >> 16)) / 65536.0;
//
//     temp_v0 = &D_80204278->unk37410;
//     D_80204278->unk38A10[3][0] = (f32) ((temp_v0->m[0][0] & 0xFFFF0000      ) | ((temp_v0->m[2][0] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[3][1] = (f32) ((temp_v0->m[0][2]              << 16) |  (temp_v0->m[2][2] & 0xFFFF)           ) / 65536.0;
//     D_80204278->unk38A10[3][2] = (f32) ((temp_v0->m[1][1] & 0xFFFF0000      ) | ((temp_v0->m[3][1] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[3][3] = (f32) ((temp_v0->m[1][3] & 0xFFFF0000      ) | ((temp_v0->m[3][3] & 0xFFFF0000) >> 16)) / 65536.0;
//
//     D_80204278->unk38A10[3][0] *= -(gScreenWidth * 2);
//     D_80204278->unk38A10[3][1] *= gScreenHeight * 2;
// }

#if 0
// million miles away
void func_8032DACC_73F17C(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp4C;
    f32 sp48;
    f32 sp10;
    f32 sp8;
    f32 sp4;

    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    // f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f18;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    // f32 temp_f6;
    f32 var_f12;
    // s16 var_t1;
    // s16 var_t1_2;
    // s16 var_t2;
    // s16 var_t2_2;
    s16 var_t3;
    s16 temp_f10;
    s16 temp_f4_2;
    s16 temp_f6_2;
    // s16 temp_f6_3;
    // s32 temp_f8;
    s32 temp_f8_2;
    // s32 temp_t7;
    // s32 temp_t7_2;
    // s32 temp_t8;
    // s32 temp_t9;
    s32 var_t2_3;
    s32 var_t4;
    // s32 var_v0;
    // s32 var_v0_2;

    temp_f18 = arg1 / 65536.0;
    temp_f12 = arg2 / 65536.0;
    temp_f14 = arg3 / 65536.0;

    temp_f0 = (D_80204278->unk38A10[2][0] * temp_f18) + (D_80204278->unk38A10[2][1] * temp_f12) + (D_80204278->unk38A10[2][2] * temp_f14) + D_80204278->unk38A10[2][3];
    if (temp_f0 <= -3.0) {
        temp_f2 = ((D_80204278->unk38A10[3][2] * temp_f0) + D_80204278->unk38A10[3][3]) / -temp_f0;
        // sp78 = temp_f2;
        if (temp_f2 > 0.0) {
            sp80 = (gScreenWidth * 2)  + ((D_80204278->unk38A10[3][0] * ((D_80204278->unk38A10[0][0] * temp_f18) + (D_80204278->unk38A10[0][1] * temp_f12) + (D_80204278->unk38A10[0][2] * temp_f14) + D_80204278->unk38A10[0][3])) / temp_f0);
            sp7C = (gScreenHeight * 2) + ((D_80204278->unk38A10[3][1] * ((D_80204278->unk38A10[1][0] * temp_f18) + (D_80204278->unk38A10[1][1] * temp_f12) + (D_80204278->unk38A10[1][2] * temp_f14) + D_80204278->unk38A10[1][3])) / temp_f0);

            var_f12 = ((s32) ((arg6 * 33) / D_803F2D50.unkE0) * 32) / -temp_f0;
            var_f12 = MIN(16383.0f, var_f12);

            if (var_f12 > 0.0f) {
                // temp_v1 = *arg0;
                // *arg0 = temp_v1 + 8;
                // temp_v1->unk0 = 0xEE000000;
                // temp_v1->unk4 = (s32) (((u32) ((sp78 * 1023.0f * 32.0f) + 32736.0f) - D_803F2D50.unk42) << 0x10);
                gDPSetPrimDepth((*arg0)++, ((u32) ((temp_f2 * 1023.0f * 32.0f) + 32736.0f) - D_803F2D50.unk42), 0);

                temp_f4 = ((arg4 * var_f12) / 128.0); //* 0.0078125);
                temp_f2_2 = sp80 - temp_f4;
                temp_f0 = sp80 + temp_f4;

                if (temp_f2_2 < temp_f0) {
                    sp4 = ((arg5 * var_f12) / 128.0); //* 0.0078125);
                    sp10 = sp7C - sp4;
                    sp8 = sp7C + sp4;

                    if (sp10 < sp8) {
                        temp_f6_2 = ((f32) (arg5 * 4096) / (temp_f0 - temp_f2_2));
                        temp_f10 = ((f32) (arg4 * 4096) / (sp8 - sp10));

                        if (sp10 < 0.0f) {
                            var_t3 = 0;
                        } else {
                            var_t3 = (s16) ((s32) -(temp_f10 * ((s32) sp10 & 3)) >> 7);
                        }
                        if ((temp_f2_2 < (f32) (gScreenWidth * 4)) && (sp10 < 960.0f) && (temp_f0 > 0.0f) && (sp8 > 0.0f)) {
                            // temp_t4 = *arg0;
                            // var_t1 = 0;
                            // var_t2 = 0;
                            // temp_f8 = (s32) temp_f0_2;
                            // *arg0 = temp_t4 + 8;
                            // temp_f6_3 = (s32) sp10;
                            temp_f8_2 = (s32) sp8;
                            // if ((s16) temp_f8 > 0) {
                            //     var_t1 = (s16) temp_f8;
                            // }
                            // var_t1 = MAX(0, temp_f8);
                            // if ((s16) temp_f8_2 > 0) {
                            //     var_t2 = (s16) temp_f8_2;
                            // }
                            // var_t2 = MAX(0, temp_f8_2);
                            // temp_f4_2 = (s32) temp_f2_2;
                            // temp_t4->unk0 = (s32) ((var_t2 & 0xFFF) | 0xE4000000 | ((var_t1 & 0xFFF) << 0xC));
                            // if (temp_f4_2 > 0) {
                            //     var_t1_2 = (s16) temp_f4_2;
                            // } else {
                            //     var_t1_2 = 0;
                            // }
                            // var_t1_2 = MAX(0, temp_f2_2);
                            // if (temp_f6_3 > 0) {
                            //     var_t2_2 = temp_f6_3;
                            // } else {
                            //     var_t2_2 = 0;
                            // }
                            // var_t2_2 = MAX(0, temp_f6_3);
                            // temp_t4->unk4 = (s32) ((var_t2_2 & 0xFFF) | ((var_t1_2 & 0xFFF) << 0xC));

                            // temp_a1 = *arg0;
                            var_t4 = 0;
                            var_t2_3 = 0;
                            // *arg0 = temp_a1 + 8;
                            // temp_a1->unk0 = 0xB4000000;
                            if ((s32)temp_f4_2 < 0) {
                                if (temp_f6_2 < 0) {
                                    var_t4 = MAX((temp_f4_2 * temp_f6_2) >> 7, 0);
                                } else {
                                    var_t4 = MAX((temp_f4_2 * temp_f6_2) >> 7, 0);
                                }
                            }
                            if ((s32) sp10 < 0) {
                                if (temp_f10 < 0) {
                                    var_t2_3 = MAX(((s32) sp10 * temp_f10) >> 7, 0);
                                } else {
                                    var_t2_3 = MAX(((s32) sp10 * temp_f10) >> 7, 0);
                                }
                            }
                            // temp_a1->unk4 = (s32) (((var_t3 - var_t2_3) & 0xFFFF) | ((((s32) (temp_f6_2 * (temp_f4_2 & 3)) >> 9) - var_t4) << 0x10));
                            // temp_v0_2 = *arg0;
                            // *arg0 = temp_v0_2 + 8;
                            // temp_v0_2->unk0 = 0xB3000000;
                            // temp_v0_2->unk4 = (s32) ((temp_f6_2 << 0x10) | ((s16) temp_f10 & 0xFFFF));

                            gSPTextureRectangle(
                            /* gdl  */ (*arg0)++,
                            /* ulx  */ MAX(0, (s32) temp_f0),
                            /* uly  */ MAX(0, (s32) sp8),
                            /* lrx  */ MAX(0, (s32) temp_f2_2),
                            /* lry  */ MAX(0, (s32) sp10),
                            /* tile */ G_TX_RENDERTILE,
                            /* t    */ ((((s32)temp_f6_2 * (temp_f4_2 & 3)) >> 9) - var_t4),
                            /* s    */ (((s32) -(temp_f10 * ((s32) sp10 & 3)) >> 7) - var_t2_3),
                            /* dsdx */ temp_f6_2,
                            /* dtdy */ temp_f10);
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032DACC_73F17C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032E150_73F800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032E9E4_740094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032F170_740820.s")

void func_8032F8C8_740F78(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8029CEF0_6AE5A0(arg0 << 16, arg1 << 16, arg2 << 16, 512, arg3 + 3, &D_803D2E08, arg3 + 3, 0, 0, 0);
}
