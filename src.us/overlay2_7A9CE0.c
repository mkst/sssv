#include <ultra64.h>
#include "common.h"

#include "pp.h"

void func_80398630_7A9CE0(void) {
    func_803800F0_7917A0(6);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04006EC0 & 0xFFFFFF)), &D_800BA760); // rnc_42DCA0, textures
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04007FA0 & 0xFFFFFF)), &D_800BDC80);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04000000 & 0xFFFFFF)), &D_800DE390);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04013060 & 0xFFFFFF)), &D_800C3A40);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_040133C0 & 0xFFFFFF)), &D_800C5240);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_040131B0 & 0xFFFFFF)), &D_800C4240);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04013580 & 0xFFFFFF)), &D_800C4A40);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04007700 & 0xFFFFFF)), &D_800BB700);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_040077A0 & 0xFFFFFF)), &D_800BBBB0);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_040078C0 & 0xFFFFFF)), &D_800BC060);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_040079F0 & 0xFFFFFF)), &D_800BC510);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04007B40 & 0xFFFFFF)), &D_800BC9C0);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04007C60 & 0xFFFFFF)), &D_800BCE70);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04007D90 & 0xFFFFFF)), &D_800BD320);
    UnpackRNC((RNC_fileptr)(D_801D9E6C + ((s32)D_04007EC0 & 0xFFFFFF)), &D_800BD7D0);
}

void func_8039884C_7A9EFC(void) {
    u8 sp18[0x58]; // 88?

    func_8039D6A4_7AED54();
    // debug here?
    if (0);
    D_803F7DA8.unk32 = 99;
    D_803F7D78.unk18 = 0;
    D_803F7D78.unk1C = 0;
    D_803F7D78.unk20 = 0;
    D_803F7D78.unk0 = 0.0f;
    D_803F7D78.unk4 = 0.0f;
    D_803F7D78.unk8 = 0.0f;
    D_803F7D78.unkC = 0.0f;
    D_803F7D78.unk10 = 0.0f;
    D_803F7D78.unk14 = 0.0f;
    D_803F7D70 = D_803C03F4;
    prepare_text(sp18, D_803F2E34);
    D_803F7DA8.unk8 = 1.0f;
    D_803B7468 = D_803F7DA8.unk2D * 12;
    D_803F7D68 = D_803F7DA8.unk2D * 12;
    D_803F7DA8.unk0 = 40.0f;
    D_803F7DA8.unk4 = 30.0f;
    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DA0 = 6;
    D_803F7DA1 = 6;
    D_803F7DA2 = 0;
    D_803F7DA3 = 0;
    D_803F2E1E = get_evo_suit_color();
}

void func_8039895C_7AA00C(void) {
    s16 i;

    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DD7 = 0;
    generate_stars();

    for (i = 0; i < 4; i++) {
        read_eeprom(i);
        memcpy_sssv((u8*)&D_8023F260, (u8*) &D_8023F2E0[i], 64);
    }
    read_eeprom(D_803F7DD6);
}

void func_80398A00_7AA0B0(void) {
    D_803F7DD8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_80398A0C_7AA0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039A2DC_7AB98C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039BBB8_7AD268.s")
// void func_8039BBB8_7AD268(void) {
//     s16 temp_a0_2;
//     s16 level;
//     s16 temp_t9;
//     s32 temp_a0;
//     s32 temp_v1;
//     u32 temp_v1_2;
//     u8 temp_t3;
//     struct003 *temp_v0;
//
//
//     if (D_803F2D50.unkC6 != 0) {
//         temp_a0 = D_803E4D28 & 2;
//         if ((D_803E4D28 & 1) != 0) {
//             temp_t9 = D_803F7DA8.unk2D + 1;
//             if ((temp_t9 != GIVE_A_DOG_A_BONUS) &&
//                 (temp_t9 != WALRACE_64) &&
//                 (temp_t9 != EVOS_ESCAPE) &&
//                 (temp_t9 != PUNCHUP_PYRAMID) &&
//                 (temp_t9 != BIG_CELEBRATION_PARADE)) {
//                 temp_v0 = &D_8023F260 + D_803F2D30.unk8;
//                 temp_v0->unk3 |= 1;
//             }
//         }
//         level = D_803F7DA8.unk2D + 1;
//         if (temp_a0 != 0) {
//             if (level == GIVE_A_DOG_A_BONUS) {
//                 D_8023F260.unk3B |= 1;
//             }
//             if (level == WALRACE_64) {
//                 D_8023F260.unk3B |= 2;
//             }
//             if (level == EVOS_ESCAPE) {
//                 D_8023F260.unk3B |= 4;
//             }
//             if (level == PUNCHUP_PYRAMID) {
//                 D_8023F260.unk3B |= 8;
//             }
//         }
//         if ((level == GIVE_A_DOG_A_BONUS) ||
//             (level == WALRACE_64) ||
//             (level == EVOS_ESCAPE) ||
//             (level == PUNCHUP_PYRAMID)) {
//             if (temp_a0 != 0) {
//                 temp_v0 = &D_8023F260 + D_803F2D30.unk8;
//                 temp_v0->unk3 |= 2;
//             }
//         } else {
//             temp_a0_2 = D_803F2D30.unkC;
//             temp_v0 = &D_8023F260 + D_803F2D30.unk8;
//             temp_t3 = temp_v0->unk3 | 2;
//             temp_v1_2 = temp_t3 & 0xFF;
//             temp_v0->unk3 = temp_t3;
//             if ((s32) (temp_v1_2 >> 4) < (s32) temp_a0_2) {
//                 temp_v0->unk3 = (u8) ((temp_a0_2 * 0x10) | (temp_v1_2 & 0xFF0F));
//             }
//         }
//         D_803F2D50.unkC6 = 0;
//         memcpy_sssv(&D_8023F260, &D_8023F2E0[D_803F7DA8.unk2E], 0x40);
//         write_eeprom(D_803F7DA8.unk2E);
//         level = D_803F7DA8.unk2D + 1;
//         if ((level == GIVE_A_DOG_A_BONUS) ||
//             (level == WALRACE_64) ||
//             (level == EVOS_ESCAPE) ||
//             (level == PUNCHUP_PYRAMID)) {
//             if ((D_803E4D28 & 2) != 0) {
//                 if (level == PUNCHUP_PYRAMID) {
//                     if (D_8023F260.unk3B == 15) {
//                         D_803F7DA8.unk2D += 1;
//                     }
//                 } else {
//                     D_803F7DA8.unk2D += 1;
//                 }
//             }
//         } else {
//             D_803F7DA8.unk2D += 1;
//         }
//         if (D_803F7DA8.unk2D == 0x1F) {
//             D_803F7DA8.unk2D = 0x22;
//         }
//     } else {
//         if (D_8023F260.score < D_803F2D30.score) {
//             D_8023F260.score = D_803F2D30.score;
//         }
//         memcpy_sssv(&D_8023F260, &D_8023F2E0[D_803F7DA8.unk2E], 64);
//         write_eeprom(D_803F7DA8.unk2E);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039BE98_7AD548.s")
// NON-MATCHING: long way to go here...
// void func_8039BE98_7AD548(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, struct052 *arg6, s16 arg7, s16 arg8, f32 arg9, u8 argA) {
//
//     f32 temp_f22;
//     s32 phi_t4;
//     s32 phi_t5;
//     s16 i;
//     s8 *temp_t0;
//
//     D_803F7D60 = (D_803F7D60 + 1) % 100;
//
//     if (arg4 == 0x1E) {
//         if (argA == 0x1E) {
//             if (((u32)(arg6->unk22 << 0x1E) >> 0x1F) == 1) {
//                 if (D_803F7D60 < 0x32) {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xF0);
//                 } else {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0x80, 0, 0xF0);
//                 }
//             } else if (D_803F7D60 < 0x32) {
//                 gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xF0);
//             } else {
//                 gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0x80, 0, 0xF0);
//             }
//         } else if ((D_803F7DFE == 0) && (argA != 0xFF)) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0x14);
//         } else if (argA == 0xFF) {
//             if (((u32)(arg6->unk22 << 0x1E) >> 0x1F) == 1) {
//                 gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0 - 0xF, 0x28, 0x28, 0xFF);
//             } else {
//                 gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xFF);
//             }
//         } else if (((u32)(arg6->unk22 << 0x1E) >> 0x1F) == 1) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xF0);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0x46);
//         }
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800BA760, 0x2B, 0x2B, arg9, arg9, 0, 0, arg7, arg8);
//     } else {
//
//         temp_f22 = arg9 / 2.0f;
//
//         for (i = arg4; i < arg5; i++) {
//
//             temp_t0 = &D_803B71D0[i];
//             if (temp_t0[0] < 0) {
//                 phi_t4 = 1;
//             } else {
//                 phi_t4 = 0;
//             }
//             if (temp_t0[1] < -1) {
//                 phi_t5 = 1;
//             } else {
//                 phi_t5 = 0;
//             }
//             if (i == argA) {
//                 if (((u32) (arg6->unk4[i] << 0x1E) >> 0x1F) == 1) {
//                     if (D_803F7D60 < 0x32) {
//                         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xF0);
//                     } else {
//                         gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0x80, 0, 0xF0);
//                     }
//                 } else if (D_803F7D60 < 0x32) {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xF0);
//                 } else {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0x80, 0, 0xF0);
//                 }
//             } else if ((D_803F7DE0[i] == 0) && (argA != 0xFF)) {
//                 gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0x14);
//             } else if (argA == 0xFF) {
//                 if (((u32) (arg6->unk4[i] << 0x1E) >> 0x1F) == 1) {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0 + 0xF, 0, 0, 0xFF);
//                 } else {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xFF);
//                 }
//             } else {
//                 if (((u32) (arg6->unk4[i] << 0x1E) >> 0x1F) == 1) {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0xF0);
//                 } else {
//                     gDPSetPrimColor(D_801D9E7C++, 0, 0, arg0, arg1, arg2, 0x46);
//                 }
//             }
//             func_8039C834_7ADEE4(&D_801D9E7C, ((temp_t0[4] * 0x4B0) ) + 0xFA0 + &D_800BA760, (temp_t0[2] * 2) & 0xFFFF, (temp_t0[3] * 2) & 0xFFFF, temp_f22, temp_f22, phi_t4, phi_t5, (s16) (s32) (arg7 + ((f32) temp_t0[0] * arg9)), (s16) (s32) (arg8 + ((f32) temp_t0[1] * arg9)));
//         }
//     }
// }

void func_8039C5F8_7ADCA8(s16 arg0, s16 arg1, f32 arg2, void *arg3, s16 arg4) {
    s32 tmp0, tmp1;
    u8 red, green, blue, col;

    if (arg4 == 1) {
        red = 200;
        green = 200;
        blue = 255;
        col = 255;
    } else {
        red = 60;
        green = 60;
        blue = 100;
        col = 128;
    }
    gDPSetPrimColor(D_801D9E7C++, 0, 0, col, col, col, 255);

    tmp0 = arg0 - (21.5f * arg2);
    tmp1 = arg1 - (21.5f * arg2);
    func_8039BE98_7AD548(red, green, blue, 128, 30, 30, arg3, tmp0, tmp1, arg2, 0xFF);
    func_8039BE98_7AD548(red, green, blue, 128,  0,  9, arg3, arg0, arg1, arg2, 0xFF);
    func_8039BE98_7AD548(red, green, blue, 128, 10, 16, arg3, arg0, arg1, arg2, 0xFF);
    func_8039BE98_7AD548(red, green, blue, 128, 17, 22, arg3, arg0, arg1, arg2, 0xFF);
    func_8039BE98_7AD548(red, green, blue, 128, 23, 29, arg3, arg0, arg1, arg2, 0xFF);
}

// calls guSprite2DInit
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039C834_7ADEE4.s")

void func_8039CAB8_7AE168(s16 arg0) {
    if (arg0 == 1) {
        draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 40);
    }

    gSPDisplayList(D_801D9E7C++, &D_801584A0);
    gDPPipeSync(D_801D9E7C++);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);

    gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
    gDPSetRenderMode(D_801D9E7C++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, 255, 80);

    gDPSetColorDither(D_801D9E7C++, G_CD_NOISE);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_DISABLE);

    func_8039C834_7ADEE4(&D_801D9E7C, D_800BDC80, 0x140, 0x24, 1.0f, 1.0f, 0, 0, 0, 0xC);

    gDPPipeSync(D_801D9E7C++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039CCBC_7AE36C.s")

// min/max with tolerance?
f32 func_8039CDE8_7AE498(f32 arg0, f32 arg1) {
    if (((arg1 - 0.25) < arg0) && (arg0 < (arg1 + 0.25))) {
        return arg1;
    } else {
        return arg0;
    }
}

void func_8039CE38_7AE4E8(Gfx **arg0) {

    D_803B66F0.unk0 = 640;
    D_803B66F0.unk2 = 480;
    D_803B66F0.unk8 = 640;
    D_803B66F0.unkA = 480;

    gDPPipeSync((*arg0)++);
    gSPLoadUcode((*arg0)++, &D_8014E300, &D_8015C750);
    gDPPipeSync((*arg0)++);

    func_80129300(arg0, D_80204278);

    gSPViewport((*arg0)++, &D_803B66F0);
    gDPSetDepthImage((*arg0)++, osVirtualToPhysical(&D_80100000));
    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gSPDisplayList((*arg0)++, D_01004270);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPPipeSync((*arg0)++);
}

void func_8039D034_7AE6E4(Gfx **arg0, s16 arg1) {
    if (D_803F66A4 == 0) {
        if (D_803F7D9E == 0) {
            if ((guRandom() % 1000) < 10) {
                D_803F7D9E = 1;
            }
        } else {
            D_803F7D9E += 1;
        }

        if (((guRandom() % 2) + 1) < D_803F7D9E) {
            D_803F7D9E = 0;
        }
        if (D_803F7D9C == 0) {
            if ((guRandom() % 2000) < 10) {
                D_803F7D9C = 1;
                func_8032CD20_73E3D0(0x283B, 0x74, 0x4000, 0, 1.0f);
            }
        } else {
            D_803F7D9C += 1;
        }
        if (((guRandom() % 5) + 9) < D_803F7D9C) {
            D_803F7D9C = 0;
        }

        if ((D_803F7D9C != 0) || (arg1 != 0)) {
            gDPPipeSync((*arg0)++);
            gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
            gDPSetBlendColor((*arg0)++, 0, 0, 0, 128);
            gDPSetRenderMode((*arg0)++, G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_NOOP2);
            gSPClearGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
            gDPSetTexturePersp((*arg0)++, G_TP_NONE);
            gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

            if (arg1 != 0) {
                gDPSetPrimColor((*arg0)++, 0, 0, 120, 120, 120, arg1);

            } else {
                gDPSetPrimColor((*arg0)++, 0, 0, 120, 120, 120, 0x05);

            }
            gDPPipeSync((*arg0)++);
            gDPFillRectangle((*arg0)++, 0, 0, 320, 239);
            gDPPipeSync(D_801D9E7C++);
        }
    }
}

void render_stars(Gfx **arg0) {
    s16 _i;

    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
    gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode((*arg0)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (_i = 0; _i < 180; _i++) {
        s16 x, y, i;

        // FIXME: fakematch
        i = _i;
        if (0) {};

        gDPSetPrimColor((*arg0)++, 0, 0, D_800DF220[i].brightness, D_800DF220[i].brightness, D_800DF220[i].brightness, 0);

        D_800DF220[i].x -= D_800DF220[i].speed * D_80204290;
        if (D_800DF220[i].x < 40) {
            // wrap around if moving off left side of screen
            D_800DF220[i].x += 1280;
        }

        x = D_800DF220[i].x;
        y = D_800DF220[i].y * 4;
        gSPTextureRectangle((*arg0)++, x, y, x + 4, y + 4, G_TX_RENDERTILE, 0, 0, 0, 0);
    }

    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPPipeSync((*arg0)++);
}

void generate_stars(void) {
    s16 i;
    for (i = 0; i < 180; i++) {
        D_800DF220[i].x = (guRandom() % 320) * 4;
        D_800DF220[i].y = (guRandom() % 240) * 4;
        D_800DF220[i].speed = (guRandom() % 4) + 1;
        D_800DF220[i].brightness = (D_800DF220[i].speed * 15) + 70;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039D6A4_7AED54.s")
// yuck
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039DAAC_7AF15C.s")

void seconds_to_mins_secs(const s16 seconds, s16 *mins, s16 *secs) {
    s16 _div = seconds / 60;
    *mins = _div;
    *secs = seconds - (s16) (_div * 60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039DBC8_7AF278.s")
// JUSTREG: using v1 not v0..
// void func_8039DBC8_7AF278(void) {
//     s16 end;
//     s16 i;
//
//     end = 0;
//     for (i = 0; i < D_803F63C0; i++) {
//         s16 *tmp = &D_803F34C0[D_803F3330[i]];
//         if ((tmp[0] == 336) && (tmp[1] == 350)) {
//             memcpy_sssv(&tmp[2], D_803F2E34, 84);
//             end = 1;
//         }
//     }
//
//     if (end == 0) {
//         D_803F2D50.unkE4 = 304;
//         D_803F2D50.unkE6 = 30000; // end marker
//     }
// }

// note that levels are off by 1
// SMASHING_START would be 0 in this function
s32 get_biome_for_level(s16 arg0) {
    if ((arg0 >= 0) && (arg0 < 10)) {
        return EUROPE_BIOME;
    }
    if ((arg0 >= 10) && (arg0 < 17)) {
        return ICE_BIOME;
    }
    if ((arg0 >= 17) && (arg0 < 23)) {
        return JUNGLE_BIOME;
    }
    if ((arg0 >= 23) && (arg0 < 30)) {
        return DESERT_BIOME;
    }
    if ((arg0 == 30) || (arg0 == 31)) {
        return CITY_BIOME;
    }
}
