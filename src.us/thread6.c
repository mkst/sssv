#include <ultra64.h>

#include "common.h"

// thread 6
void thread6(s32 arg0) {
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

    osCreateScheduler(&sc, &D_80162658, 20, D_802053E0.VIModeType, 1);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_OFF | OS_VI_GAMMA_OFF);

    gScreenWidth = 320;
    gScreenHeight = 240;

    gControllerInput = NULL;

    initialise_audio(&D_80286328);

    i = 0; // fakematch
    // stack (1)?
    D_80162658[i].unk3BBA8 = 6;
    D_80162658[i].unk3BBC8 = 2;
    D_80162658[i].unk3BBE8 = gFramebuffer[0];
    // stack (2)?
    D_8019A658[0].unk3F798 = 6;
    D_8019A658[0].unk3F7B8 = 2;
    D_8019A658[0].unk3F7D8 = gFramebuffer[1];

    clear_framebuffer();
    D_801D9E38 = 5;
    osCreateMesgQueue(&D_8028D060, &D_80290F40, 32);
    osScAddClient(&sc, &D_802042A0, &D_8028D060);

    if (init_controllers() <= 0) {
        // if no controllers connected
        D_802912D0 = 0;
        gControllerConnected = 0; // gControllerConnected
        D_80204270 = 1;
    } else {
        D_802912D0 = 1;
        gControllerConnected = 1;
        D_80204270 = 0;
    }
    if (D_802912D0 == 0) {
        D_80204284 = 0;
    }
    // eeprom stuff
    func_80130C04();
    func_80130E44();

    D_80204288 = 0;

    load_overlay(1); // load menu overlay

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

void func_80129DC0(void) {
    s8 phi_s1;

    D_801D9EC8 = 0;
    D_801D9EC9 = 0;
    D_80152EB8 = 0U;
    D_80152EBC = 0U;
    D_802042A8 = 0;

    phi_s1 = 0;

    while (TRUE) {
        if ((D_80204284 != 2) && (D_80204284 != 1) && (D_80204284 != 5) && (D_80204284 != 8)) {
            stop_all_sounds();
            func_801328F8();
            D_80204290 = 1;
            D_8028645C = 0;

            phi_s1 = 1;
            switch (D_80204284) {
            case 3:
                func_8012AC40();
                D_80204284 = 5;
                break;
            case 4:
                D_80204284 = 2;
                break;
            case 7:
                D_80204284 = 8;
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
        osRecvMesg(&D_8028D060, &D_80204298, OS_MESG_BLOCK);

        switch (D_80204298.unk0->unk0) {
        case 1:
            D_80204292 += 1;
            if (phi_s1 != 0) {
                phi_s1 += 1;
            }
            if (D_801D9ED4 != 0) {
                D_801D9ED4 -= 1;
            }
            if ((D_80152EBC < 2) && (phi_s1 == 0) && (D_80204292 >= D_80204290)) {
                func_80136F64(); // debounce input?
                if (gControllerConnected != 0) {
                    func_801370F4();
                    osContStartReadData(&D_8028D0A8);
                    osRecvMesg(&D_8028D0A8, &D_802042EC, OS_MESG_BLOCK);
                    func_8013713C();
                    osContGetReadData(&D_802910E8);
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
                func_80131070();

                func_8013107C(
                    &D_80162658[D_80152EB8],
                    D_80162658[D_80152EB8].unk4E0,
                    (D_801D9E7C - D_80162658[D_80152EB8].unk4E0) * sizeof(Gfx),
                    3,
                    &D_80162658[D_80152EB8].unk3BBC8,
                    99);

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
            if (D_80204290 == 1) {
                func_8012AB94();
            } else if (D_80204292 >= (D_80204290 - 1)) {
                func_8012AB94();
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
    struct018 *temp_a0;
    s16 i;

    while (TRUE) {
        osRecvMesg(&D_80291060, D_80291054, OS_MESG_BLOCK);
        temp_a0 = D_8020428C;
        D_80204278 = &temp_a0->unk4E0;
        D_801D9E7C = &temp_a0->unk4E0;
        D_801D9E90 = &temp_a0->unkDFA0;
        D_801D9E94 = &temp_a0->unk81E0;
        D_801D9E88 = &temp_a0->unk9AE0;
        D_801D9E8C = &temp_a0->unkC060;
        D_801D9EB8 = &temp_a0->unk26C80;

        for (i = 0; i < 8; i++) {
            D_801D9E98[i] = &D_80204278->unk109A0[i];
        }

        D_80204274 = temp_a0;
        if (D_80152E9C == 0) {
            func_80294E50(); // call overlay func
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
        if (D_80204298.unk0->unk0 == 2) {
            i = 100; // thats more than 4!
        }
    }

    D_80152EBC = 0;
}

void end_display_lists(void) {
    gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

    gSPEndDisplayList(D_801D9E90++);
    gSPEndDisplayList(D_801D9E94++);
    gSPEndDisplayList(D_801D9E88++);
    gSPEndDisplayList(D_801D9E8C++);
    gSPEndDisplayList(D_801D9EB8++);

    gDPFullSync(D_801D9E7C++);

    gSPEndDisplayList(D_801D9E7C++);
}

void func_8012A588(void) {
    s16 tmp;

    if (D_80152E9C != 0) {
        D_80204290 = 1;
        if (D_80152E9C == 1) {
            func_80137840();
            func_8012A400();
            memcpy_sssv(D_80162658[D_80152EB8].unk3BBE8, D_80162658[D_80152EB8 ^ 1].unk3BBE8, sizeof(gFramebuffer[0]));
        }
        if (D_80152E9C == 2) {
            func_8012AC40();
            func_801337DC(0, 10.0f, 20.0f, 0.0f);
            func_8013385C(   10.0f, 20.0f, 0.0f);
        }
        // fakematch
        if (tmp = D_80152E9C != 0) {}

        gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
        draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 120);

        D_80152E9C = D_80152E9C + D_80204290;

        if (D_80152E9C >= 16) {
            D_80152EBC += 100;
            func_8012AC8C();
        }
    }
}

void no_controller_message(void) {
    if (gControllerConnected == 0) {
        load_segments(&D_801D9E7C, D_80204278);
        draw_rectangle(&D_801D9E7C, 0, 16, 320, 36, 40, 40, 40, 128);
        gDPPipeSync(D_801D9E7C++);

        load_default_display_list(&D_801D9E7C);
        select_font(0, FONT_DEFAULT, 0, 0);
        set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
        // "CONTROLLER NOT CONNECTED" text
        display_text(&D_801D9E7C, D_802042F0, gScreenWidth/2, 20, 16.0f, 16.0f);
        gDPPipeSync(D_801D9E7C++);
    }
}
