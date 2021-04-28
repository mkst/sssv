#include <ultra64.h>

#include "common.h"


// first function called after osInitialize
void init(void) {
    fancy_bzero(gFramebuffer[0], sizeof(gFramebuffer[0]));
    fancy_bzero(gFramebuffer[1], sizeof(gFramebuffer[1]));
}

// thread 6
void func_80129B10(s32 arg0) {
    unsigned long long  i;

    D_80204290 = 1;
    D_80204292 = 2;

    osCreateMesgQueue(&D_8028D048, &D_802902C0, 32);
    osCreateMesgQueue(&D_8028D078, &D_80290FC8, 1);
    osCreateMesgQueue(&D_80291060, &D_80291058, 1);
    osCreateMesgQueue(&D_80291078, &D_8029105C, 1);
    // start thread 7
    osStartThread(&gThread7);

    read_rom_header();
    set_region();
    // initialise various tv settings
    func_8012A870();

    osCreateScheduler(&D_801603D0, &D_80162658, 20, D_802053E0.unk8, 1);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_OFF | OS_VI_GAMMA_OFF);

    gScreenWidth = 320;
    gScreenHeight = 240;

    gControllerInput = NULL;

    initialise_audio(D_80286328);

    i = 0; // fakematch
    // stack (1)?
    D_80162658[i].unk3BBA8 = 6;
    D_80162658[i].unk3BBC8 = 2;
    D_80162658[i].unk3BBE8 = gFramebuffer[0];
    // stack (2)?
    D_8019A658[0].unk3F798 = 6;
    D_8019A658[0].unk3F7B8 = 2;
    D_8019A658[0].unk3F7D8 = gFramebuffer[1];

    init();
    D_801D9E38 = 5;
    osCreateMesgQueue(&D_8028D060, &D_80290F40, 32);
    osScAddClient(&D_801603D0, &D_802042A0, &D_8028D060);

    if (func_80136CE0() <= 0) {
        D_802912D0 = 0;
        D_802912D8 = 0;
        D_80204270 = 1;
    } else {
        D_802912D0 = 1;
        D_802912D8 = 1;
        D_80204270 = 0;
    }
    if (D_802912D0 == 0) {
        D_80204284 = 0;
    }
    // eeprom stuff
    func_80130C04();
    func_80130E44();

    D_80204288 = 0;
    // load_overlay
    func_8012C070(1);

    D_80204284 = 1;
    D_80204290 = 1;
    D_8020427C = 1;
    D_80204280 = 199;
    D_80204282 = 99;

    while (TRUE) {
        // this has a while loop anyway.. *shrug*
        func_80129DC0();
    }
}

// read controller data
#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_80129DC0.s")

// thread 7
#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A260.s")
// NON-MATCHING: matches but won't OK
// void func_8012A260(void) {
//     struct018 *temp_a0;
//     s32 temp_a1;
//     s16 i;
//
//     while (TRUE) {
//         osRecvMesg(&D_80291060, D_80291054, OS_MESG_BLOCK);
//         temp_a0 = D_8020428C;
//         temp_a1 = &temp_a0->unk4E0;
//         D_80204278 = temp_a1;
//         D_801D9E7C = temp_a1;
//         D_801D9E90 = &temp_a0->unkDFA0;
//         D_801D9E94 = &temp_a0->unk81E0;
//         D_801D9E88 = &temp_a0->unk9AE0;
//         D_801D9E8C = &temp_a0->unkC060;
//         D_801D9EB8 = &temp_a0->unk26C80;
//
//         for (i = 0; i < 8; i++) {
//             D_801D9E98[i] = &D_80204278->unk109A0[i];
//         }
//
//         D_80204274 = temp_a0;
//         if (D_80152E9C == 0) {
//             func_80294E50(); // call overlay func
//         } else {
//             func_8012A588();
//         }
//         osWritebackDCacheAll();
//         osSendMesg(&D_80291078, D_80291054, OS_MESG_BLOCK);
//     }
// }

void func_8012A400(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        osRecvMesg(&D_8028D060, (OSMesg *)&D_80204298, OS_MESG_BLOCK);
        if (D_80204298.unk0->unk0 == 2) {
            i = 100; // thats more than 4!
        }
    }

    D_80152EBC = 0;
}

// end_display_lists
void func_8012A490(void) {
    gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

    gSPEndDisplayList(D_801D9E90++);
    gSPEndDisplayList(D_801D9E94++);
    gSPEndDisplayList(D_801D9E88++);
    gSPEndDisplayList(D_801D9E8C++);
    gSPEndDisplayList(D_801D9EB8++);

    gDPFullSync(D_801D9E7C++);

    gSPEndDisplayList(D_801D9E7C++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A588.s")
// void func_8012A588(void) {
//     s16 pad;
//
//     if (D_80152E9C != 0) {
//         D_80204290 = 1;
//         if (D_80152E9C == 1) {
//             func_80137840();
//             func_8012A400();
//             strncpy(D_80162658[D_80152EB8].unk3BBE8, D_80162658[D_80152EB8 ^ 1].unk3BBE8, sizeof(gFramebuffer[0]));
//         }
//         if (D_80152E9C == 2) {
//             func_8012AC40();
//             func_801337DC(0.0f, 10.0f, 20.0f, 0.0f);
//             func_8013385C(10.0f, 20.0f, 0.0f);
//             // ???
//         }
//
//         gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
//         draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 120);
//
//         D_80152E9C += D_80204290;
//
//         if (D_80152E9C >= 16) {
//             D_80152EBC += 100;
//             func_8012AC8C();
//         }
//     }
// }

void func_8012A750(void) {
    if (D_802912D8 == 0) {
        func_80129300(&D_801D9E7C, D_80204278);
        draw_rectangle(&D_801D9E7C, 0, 16, 320, 36, 40, 40, 40, 128);
        gDPPipeSync(D_801D9E7C++);

        load_default_display_list(&D_801D9E7C);
        select_font(0, 0, 0, 0);
        set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
        display_text(&D_801D9E7C, D_802042F0, gScreenWidth/2, 20, 16.0f, 16.0f);
        gDPPipeSync(D_801D9E7C++);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_51D0/func_8012A870.s")
// plenty more work to do here..
// void func_8012A870(void) {
//     s16 temp_a2_7;
//     s32 temp_a1;
//     s32 temp_v0;
//     OSViMode *temp_a2;
//     struct001 *temp_v1;
//     s32 phi_a3;
//     struct012 *phi_v1;
//     s32 phi_t0;
//     struct012 *phi_a0;
//     OSViMode *phi_a2;
//
//     switch (D_80000302) { // part of tv type?
//         case 0:
//             D_802053E0.unk0 = 14;
//             D_802053E0.unkA = 304;
//             D_80204294 = 50; // 50 hz
//             D_802053F0.unk0 = 0x7A0210;
//             D_802053F0.unk4 = 1200;
//             D_80205400.unk0 = 0x34025A;
//             D_80205400.unk4 = 878;
//             temp_a2_7 = D_80204240.mode;
//             if (((temp_a2_7 == 2) || (temp_a2_7 == 0)) && (D_80204240.countryCode != 0)) {
//                 *(volatile s16*)0 = 0; // shit our pants?
//             }
//             phi_a2 = &osViModeTable[D_802053E0.unk8];
//             phi_a3 = phi_a2->unk30;
//             phi_t0 = phi_a2->unk2C;
//             phi_v1 = &D_802053E0;
//             phi_a0 = &D_80205400;
//             break;
//         case 1:
//             D_802053E0.unk0 = 0;
//             D_802053E0.unkA = 304;
//             D_80204294 = 60; // 60 hz
//             phi_a2 = &osViModeTable[D_802053E0.unk8];
//             phi_a3 = phi_a2->unk30;
//             phi_t0 = phi_a2->unk2C;
//             D_802053F0.unk0 = 0x6501BF;
//             D_802053F0.unk4 = 0x587;
//             D_80205400.unk0 = phi_a3;
//             D_80205400.unk4 = phi_t0;
//             phi_v1 = &D_802053E0;
//             phi_a0 = &D_80205400;
//             if (D_80204240.mode == 1) {
//                 if (D_80204240.countryCode != 0) {
//                     *(volatile s16*)0 = 0;
//                 }
//             }
//             break;
//         case 2:
//             D_802053E0.unk8 = 28;
//             D_802053E0.unkA = 304;
//             D_80204294 = 60;
//             phi_a2 = &osViModeTable[D_802053E0.unk8];
//             phi_a3 = phi_a2->unk30;
//             phi_t0 = phi_a2->unk2C;
//             D_802053F0.unk0 = 0x6501BF;
//             D_802053F0.unk4 = 0x587; // 1415
//             D_80205400.unk0 = phi_a3;
//             D_80205400.unk4 = phi_t0;
//             phi_v1 = &D_802053E0;
//             phi_a0 = &D_80205400;
//             if ((D_80204240.mode == 1) && (D_80204240.countryCode != 0) ){
//                 *(volatile s16*)0 = 0;
//                 // phi_a2 = &osViModeTable[D_802053E0.unk8];
//                 // phi_a3 = phi_a2->unk30;
//                 // phi_v1 = &D_802053E0;
//                 // phi_a0 = &D_80205400;
//                 // phi_t0 = phi_a2->unk2C;
//             }
//             break;
//         default:
//             D_802053E0.unk8 = 0;
//             D_802053E0.unkA = 304;
//             D_80204294 = 60;
//             phi_a2 = &osViModeTable[D_802053E0.unk8];
//             phi_a3 = phi_a2->unk30;
//             phi_t0 = phi_a2->unk2C;
//             D_802053F0.unk0 = 0x6501BF;
//             D_802053F0.unk4 = 1415;
//             D_80205400.unk0 = phi_a3;
//             D_80205400.unk4 = phi_t0;
//             phi_v1 = &D_802053E0;
//             phi_a0 = &D_80205400;
//             if ((D_80204240.mode == 1) && (D_80204240.countryCode != 0)) {
//                 *(volatile s16*)0 = 0;
//                 // phi_a2 = &osViModeTable[D_802053E0.unk8];
//                 // phi_a3 = phi_a2->unk30;
//                 // phi_v1 = &D_802053E0;
//                 // phi_a0 = &D_80205400;
//                 // phi_t0 = phi_a2->unk2C;
//             }
//             break;
//     }
//
//     temp_v0 = phi_a0->unk0;
//     temp_a1 = phi_a0->unk4;
//
//     phi_v1->unk0 = phi_a3;
//     phi_v1->unk4 = phi_t0;
//     phi_a2->unk30 = temp_v0;
//     phi_a2->unk44 = temp_v0;
//     phi_a2->unk2C = temp_a1;
//     phi_a2->unk40 = temp_a1;
//     D_8020540C = (u16)0;
// }

void func_8012AB94(void) {
    osViSetXScale(gScreenWidth / 320.0f);
    osViSetYScale(gScreenHeight / 240.0f);
}

void func_8012ABF0(void) {
    OSViMode *mode;
    s32 vStart;
    s32 yScale;

    mode = &osViModeTable[D_802053E0.unk8];
    vStart = D_802053F0.unk0;
    yScale = D_802053F0.unk4;
    mode->fldRegs[0].vStart = vStart;
    mode->fldRegs[1].vStart = vStart;
    mode->fldRegs[0].yScale = yScale;
    mode->fldRegs[1].yScale = yScale;

    D_8020540C = 1;
}

void func_8012AC40(void) {
    OSViMode *mode;
    s32 vStart;
    s32 yScale;

    mode = &osViModeTable[D_802053E0.unk8];
    vStart = D_80205400.unk0;
    yScale = D_80205400.unk4;
    mode->fldRegs[0].vStart = vStart;
    mode->fldRegs[1].vStart = vStart;
    mode->fldRegs[0].yScale = yScale;
    mode->fldRegs[1].yScale = yScale;

    D_8020540C = 0;
}

void func_8012AC8C(void) {
    OSViMode *mode;
    s32 vStart;
    s32 yScale;

    osViSetXScale(1.0f);
    osViSetYScale(1.0f);

    mode = &osViModeTable[D_802053E0.unk8];
    vStart = D_802053E0.unk0;
    yScale = D_802053E0.unk4;
    mode->fldRegs[0].vStart = vStart;
    mode->fldRegs[1].vStart = vStart;
    mode->fldRegs[0].yScale = yScale;
    mode->fldRegs[1].yScale = yScale;

    osViBlack(1);
}

void func_8012AD08(void) {
    osViBlack(0);
    func_8012AC40();
}

void draw_rectangle(Gfx **arg0, s16 x0, s16 y0, s16 x1, s16 y1, u8 r, u8 g, u8 b, u8 alpha) {
    s32 color;

    if (alpha != 0) {
        gDPPipeSync((*arg0)++);
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 0, 0, 320, 241);

        gDPPipeSync((*arg0)++);
        gDPSetAlphaCompare((*arg0)++, G_AC_NONE);

        if (alpha == 0xFF) {
            // rgba5551
            gDPPipeSync((*arg0)++);
            gDPSetCycleType((*arg0)++, G_CYC_FILL);
            gDPPipeSync((*arg0)++);

            gDPSetRenderMode((*arg0)++, G_RM_NOOP, G_RM_NOOP2);

            gDPSetFillColor((*arg0)++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
            gDPFillRectangle((*arg0)++, x0, y0, x1 - 1, y1 - 1);
        } else {
            // rgba32
            gDPPipeSync((*arg0)++);
            gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
            gDPSetColorDither((*arg0)++, G_CD_NOISE);
            gDPSetAlphaDither((*arg0)++, G_AD_DISABLE);

            gDPSetPrimColor((*arg0)++, 0, 0, r, g, b, alpha);

            if (D_80204288 == 10) {
                gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
            } else {
                gDPSetRenderMode((*arg0)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            }

            gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPFillRectangle((*arg0)++, x0, y0, x1, y1);
        }

        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
        gDPPipeSync((*arg0)++);
    }
}
