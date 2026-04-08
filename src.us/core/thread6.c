#include <ultra64.h>

#include "common.h"

// ========================================================
// .data
// ========================================================

u8 D_80152E90 = 1; // current overlay
u8 D_80152E94 = 1; // unused?
u8 D_80152E98 = 1;

s16 D_80152E9C = 0;
s16 D_80152EA0 = 0; // some flag
s16 D_80152EA4 = 3; // only used once?

Vp gMainViewport = {{
    {
        640,
        480,
        511,
        0,
    },
    {
        640,
        480,
        511,
        0,
    }
}};

u16 D_80152EB8 = 0; // framebuffer id
u16 D_80152EBC = 0; // some kind of delay timer?

// ========================================================
// .bss (0x8015E1D0 to 0x801D9E80)
// ========================================================

u8 D_8015E1D0[0x2200];  // tbd

OSSched sc;             // 0x801603D0

u8 D_80160658[0x2000];  // padding

FrameContext D_80162658[2];

u16  D_801D9E38;

u8  D_801D9E40[0x18];   // padding

u8  *D_801D9E58;
u8  *D_801D9E5C;
u8  *D_801D9E60;
u8  *D_801D9E64;
u8  *D_801D9E68;
u8  *gMenuSegmentBase;

s16 *gFontSegmentBase;
u8  *gSegment1Base;
u8  *gSegment5Base;
Gfx *gMainDL;

// ========================================================
// .text
// ========================================================

// thread 6
void thread6(s32 arg0) {
    unsigned long long i;

    gFrameStepDivisor = 1;
    D_80204292 = 2;

    osCreateMesgQueue(&D_8028D048, D_802902C0, 32);
    osCreateMesgQueue(&D_8028D078, D_80290FC8, 1);
    osCreateMesgQueue(&D_80291060, D_80291058, 1);
    osCreateMesgQueue(&D_80291078, D_8029105C, 1);

    osStartThread(&gThread7);

    read_rom_header();
    set_region();

    initialise_tv_mode();

    osCreateScheduler(&sc, (void*)D_80162658, 20, gVIData.VIModeType, 1);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_OFF | OS_VI_GAMMA_OFF);

    gScreenWidth = 320;
    gScreenHeight = 240;

    gControllerInput = NULL;

    initialise_audio((s32 *)&D_80286328);

    i = 0; // fakematch

    // stack (1)
    D_80162658[i].unk3BBA8 = 6;
    D_80162658[i].unk3BBC8 = 2;
    D_80162658[i].framebuffer = gFramebuffer[0];
    // stack (2)
    D_80162658[1].unk3BBA8 = 6;
    D_80162658[1].unk3BBC8 = 2;
    D_80162658[1].framebuffer = gFramebuffer[1];

    clear_framebuffer();
    D_801D9E38 = 5;
    osCreateMesgQueue(&D_8028D060, D_80290F40, 32);
    osScAddClient(&sc, &D_802042A0, &D_8028D060);

    if (init_controllers() <= 0) {
        // if no controllers connected
        D_802912D0 = 0;
        gControllerConnected = 0;
        D_80204270 = 1;
    } else {
        D_802912D0 = 1;
        gControllerConnected = 1;
        D_80204270 = 0;
    }
    if (D_802912D0 == 0) {
        gOverlayState = 0;
    }
    // eeprom stuff
    clear_player_eeprom_state();
    func_80130E44(); // read_eeprom

    gAttractModeState = 0;

    load_overlay(1); // load menu overlay

    gOverlayState = 1;
    gFrameStepDivisor = 1;
    D_8020427C = 1;
    D_80204280 = 199;
    D_80204282 = 99;

    while (TRUE) {
        // this has a while loop anyway.. *shrug*
        thread6_loop();
    }
}

void thread6_loop(void) {
    s8 phi_s1;

    D_801D9EC8 = 0;
    D_801D9EC9 = 0;
    D_80152EB8 = 0;
    D_80152EBC = 0;
    D_802042A8 = 0;

    phi_s1 = 0;

    while (TRUE) {
        if ((gOverlayState != 2) && (gOverlayState != 1) && (gOverlayState != 5) && (gOverlayState != 8)) {
            stop_all_sounds();
            func_801328F8();
            gFrameStepDivisor = 1;
            gCurrentMusicTrack = NO_MUSIC;

            phi_s1 = 1;
            switch (gOverlayState) {
            case 3:
                set_tv_mode_normal();
                gOverlayState = 5;
                break;
            case 4:
                gOverlayState = 2;
                break;
            case 7:
                gOverlayState = 8;
                break;
            }
        }

        if (phi_s1 == 3) {
            phi_s1 = 0;
            D_8020427C = 1;
            D_80152E98 = 1;
            func_801328F8();
            func_801328F8();
            func_801328F8();
            func_801328F8();
            load_overlay(D_80152E90);
            func_801328F8();
            func_801328F8();
            func_801328F8();
            func_801328F8();
        }
        osRecvMesg(&D_8028D060, (OSMesg *)&D_80204298, OS_MESG_BLOCK);

        switch (D_80204298->type) {
        case 1:
            D_80204292 += 1;
            if (phi_s1 != 0) {
                phi_s1 += 1;
            }
            if (D_801D9ED4 != 0) {
                D_801D9ED4 -= 1;
            }
            if ((D_80152EBC < 2) && (phi_s1 == 0) && (D_80204292 >= gFrameStepDivisor)) {
                func_80136F64(); // read input
                if (gControllerConnected != 0) {
                    func_801370F4();
                    osContStartReadData(&D_8028D0A8);
                    osRecvMesg(&D_8028D0A8, &D_802042EC, OS_MESG_BLOCK);
                    func_8013713C();
                    osContGetReadData(D_802910E8);
                    D_802912D0 = 1;
#ifdef VERSION_US
                    gControllerInput = &D_802910E8;
#else
                    gControllerInput = &D_802910E8[D_801D9ED0];
#endif
                }
                D_80204292 = 0;
                D_8020428C = &D_80162658[D_80152EB8];
                osSendMesg(&D_80291060, D_80291054, OS_MESG_BLOCK);
                osRecvMesg(&D_80291078, D_80291054, OS_MESG_BLOCK);
                D_80152EA0 = (1 - D_80152EA0);
                no_controller_message();
                end_display_lists();
                D_801D9EC8 = 0;
                reset_task_list();

                func_8013107C(
                    &D_80162658[D_80152EB8],
                    &D_80162658[D_80152EB8].dl,
                    (gMainDL - D_80162658[D_80152EB8].dl.mainDL) * sizeof(Gfx),
                    3, /* type */
                    &D_80162658[D_80152EB8].unk3BBC8, // always 2
                    0x63); // OS_SC_SWAPBUFFER | OS_SC_LAST_TASK | OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP

                D_80152EBC += 1;
                D_80152EB8 ^= 1;
            }

            if (++D_802042A8 >= 16) {
                D_802042A8 = 0;
            }
            if (D_80152E9C < 16) {
                func_801328F8();
            }
            break;
        case 2:
            if (gFrameStepDivisor == 1) {
                set_screen_scaling();
            } else if (D_80204292 >= (gFrameStepDivisor - 1)) {
                set_screen_scaling();
            }
            D_80152EA4 = 0;
            D_802042A8 = 0;
            D_801D9EC9 = 0;
            D_80152EBC -= 1;
            break;
        case 4:
            if (D_80152E9C == 0) {
                D_80152E9C = 1;
            }
            break;
        case 6:
            break;
        }
    }
}

// thread 7
void thread7(void) {
    FrameContext *temp_a0;
    s16 i;

    while (TRUE) {
        osRecvMesg(&D_80291060, D_80291054, OS_MESG_BLOCK);
        temp_a0 = D_8020428C;
        gDisplayListContext = &temp_a0->dl;

        gMainDL = temp_a0->dl.mainDL;
        gLayer0DL = temp_a0->dl.gLayer0DL;
        gLayer1DL = temp_a0->dl.gLayer1DL;
        gOpaqueDL = temp_a0->dl.gOpaqueDL;
        gXluDL = temp_a0->dl.gXluDL;
        gAuxDL = temp_a0->dl.gAuxDL;

        for (i = 0; i < 8; i++) {
            D_801D9E98[i] = &gDisplayListContext->unk109A0[i];
        }

        gFrameContext = temp_a0;
        if (D_80152E9C == 0) {
            func_80294E50_6384F0(); // call overlay1 entrypoint
        } else {
            func_8012A588();
        }
        osWritebackDCacheAll();
        osSendMesg(&D_80291078, D_80291054, OS_MESG_BLOCK);
    }
}

void func_8012A400(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        osRecvMesg(&D_8028D060, (OSMesg *)&D_80204298, OS_MESG_BLOCK);
        if (D_80204298->type == 2) {
            i = 100; // thats more than 4!
        }
    }

    D_80152EBC = 0;
}

void end_display_lists(void) {
    gSPTexture(gMainDL++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

    gSPEndDisplayList(gLayer0DL++);
    gSPEndDisplayList(gLayer1DL++);
    gSPEndDisplayList(gOpaqueDL++);
    gSPEndDisplayList(gXluDL++);
    gSPEndDisplayList(gAuxDL++);

    gDPFullSync(gMainDL++);

    gSPEndDisplayList(gMainDL++);
}

void func_8012A588(void) {
    s16 tmp;

    if (D_80152E9C != 0) {
        gFrameStepDivisor = 1;
        if (D_80152E9C == 1) {
            init_rumble_pak();
            func_8012A400();
            memcpy_sssv(D_80162658[D_80152EB8].framebuffer, D_80162658[D_80152EB8 ^ 1].framebuffer, sizeof(gFramebuffer[0]));
        }
        if (D_80152E9C == 2) {
            set_tv_mode_normal();
            start_sequence_volume_fade(0, 10.0f, 20.0f, 0.0f);
            start_sfx_volume_fade(   10.0f, 20.0f, 0.0f);
        }
        // fakematch
        if (tmp = D_80152E9C != 0) {}

        gDPSetColorImage(gMainDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(gFrameContext->framebuffer));
        draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, 120);

        D_80152E9C = D_80152E9C + gFrameStepDivisor;

        if (D_80152E9C >= 16) {
            D_80152EBC += 100;
            func_8012AC8C();
        }
    }
}

void no_controller_message(void) {
    if (gControllerConnected == 0) {
        load_segments(&gMainDL, gDisplayListContext);
        draw_rectangle(&gMainDL, 0, 16, 320, 36, 40, 40, 40, 128);
        gDPPipeSync(gMainDL++);

        load_default_display_list(&gMainDL);
        select_font(0, FONT_DEFAULT, 0, 0);
        set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
        // "CONTROLLER NOT CONNECTED" text
        display_text_centered(&gMainDL, gNoControllerMessageText, gScreenWidth/2, 20, 16.0f, 16.0f);
        gDPPipeSync(gMainDL++);
    }
}
