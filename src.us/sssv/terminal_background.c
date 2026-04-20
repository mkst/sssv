#include <ultra64.h>
#include "common.h"

#include "camera.h"

// ========================================================
// definitions
// ========================================================

extern s8  D_803F2C6D; // mismatch camera.c
extern u8  gTerminalTransitionCounter; // tbd

// ========================================================
// .data
// ========================================================

u8 dna[8] = "AGCT.-01";

char* terminal_asm[] = {
    "mov si,animaltype",
    "add si,128",
    "mov blocksi,si",
    "mov ax,0",
    "mov ax,xpos",
    "mov bx,ax",
    "shl al,4",
    "shr al,4",
    "mov ah,0",
    "cmp animalinview,0",
    "je  scared",
    "mov ax,0",
    "scared:",
    "mov energy,ax",
    "mov ax,bx",
    "shr ax,4",
    "mov animalpositionx,0",
    "mov animalpositiony,0",
    "mov si,animalpositionz",
    "mov world,ax",
    "mov ax,ypos",
    "and ah,ah",
    "mov bx,ax",
    "shl al,4",
    "shr al,4",
    "cmp animalinview,0",
    "je  fearless",
    "mov ax,0",
    "fearless:",
    "mov intelligence,ax",
    "mov ax,bx",
    "shr ax,4",
    "mul strength",
    "add world,ax",
    "push bp",
    "push ds",
    "leslies code sucks:",
    "cmp movedcounter,1",
    "jne again",
    "mov movedcounter,800",
    "again:",
    "mov si,animalpositionz",
    "mov ds,worldfeatureseg",
    "mov bx,world",
    "mov al,(ds:si+bx)",
    "mov curblock,al",
    "push bp",
    "push ds",
    "mov byte (ds:si+bx),0",
    "jmp havetomove",
    "nothuhumantemp:",
    "mov si,worldfeatureanimofs",
    "mov ds,worldfeatureanimseg",
    "mov bx,world",
    "mov cx,0",
    "mov cl,(ds:si+bx)",
    "cmp cl,254",
    "jne continue",
    "mov byte (ds:si+bx),0",
    "jmp havetomove",
    "continue:",
    "animalnotoverlay:",
    "cmp al,enemy1right",
    "jb  gnotbaddie",
    "cmp al,enemy2right",
    "jae gbaddie2",
    "mov al,enemy1right",
    "jmp gnotbaddie",
    "gbaddie2:",
    "mov al,enemy2right",
    "gnotbaddie:",
};

// where is this used?
s16 *D_803B6450_7C7B00[68] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, // padding or?
};

// FIXME
s32 foo[3] = {0, 0, 0};

s16 *gTerminalStatText[18] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0,
};

Lights1 D_803B65A8_7C7C58 = gdSPDefLights1(0x00, 0x0A, 0x00, 0x00, 0x64, 0x00, 0x04, 0x00, 0x08);
Lights1 D_803B65C0_7C7C70 = gdSPDefLights1(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0x08);
Lights1 D_803B65D8_7C7C88 = gdSPDefLights1(0x19, 0x32, 0x00, 0x64, 0xC8, 0x00, 0x04, 0x00, 0x08);
Lights1 D_803B65F0_7C7CA0 = gdSPDefLights1(0x00, 0x19, 0x00, 0x32, 0xC8, 0x00, 0x04, 0x00, 0x08);

Gfx gTerminalDnaOpaqueRenderSetupDl[] = {
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetColorDither(G_CD_BAYER),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPClipRatio(FRUSTRATIO_4),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx gTerminalDnaInterlaceRenderSetupDl[] = {
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_AA_ZB_OPA_INTER2),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

// u8 D_803B66E4_7C7D94 = 0;

void func_8038CF90_79E640(void) {
    gSPDisplayList(gMainDL++, D_01004270_3DB40);
    gDPSetCombineMode(gMainDL++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMainDL++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
}

// ========================================================
// .bss (D_803F6460 to D_803F6680)
// ========================================================

u8   D_803F6460;
Animal *D_803F6464;
s16  D_803F6468;
f32  D_803F646C;
s16  D_803F6470;
u8   D_803F6472;
s16  D_803F6474;
struct109 gTerminalTextScrollState;
s16 *gTerminalStatLabels[18];
s16  gTerminalStatTextX[20];
f32  gTerminalDnaSimulation[16][2][2]; // tbd
// f32  D_803F6670;


// ========================================================
// definitions
// ========================================================

void spin_dna_helixes(u16 arg0);
u8 step_terminal_dna_simulation(void);

// ========================================================
// .text
// ========================================================

void render_terminal_background_glyphs(Gfx **dl, u16 intensity) {
    s16 xPos;
    s16 yPos;
    s16 idx;
    u16 vertical_offset;
    s16 j;
    u8 i;
    s32 pad;
    s32 g;
    s8 ascii[64];
    s16 wide[64];

    vertical_offset = 10;

    load_default_display_list(dl);
    select_font(0, FONT_COMIC_SANS, 0, 0);

    // needed for stack
    g = MIN(intensity << 2, 80);

    set_menu_text_color(0, g, 0, 0xFF);

    for (i = 0; i < 4; i++) {
        sprintf((char*)ascii, "%s\n", terminal_asm[(rand() / 924) & 0xFF]);
        prepare_text((u8*)ascii, wide);
        func_8012D374(dl, wide, 6, vertical_offset, 13.0f, 9.0f, -1);
        vertical_offset += 10;
    }

    for (j = 0; j < 15; j++) {
        idx = advance_random_seed();   // random number

        xPos = (idx >> 3) & 0xF; // bottom 7 bits (max=15)
        yPos = (idx >> 8) & 3;   // bottom 2 bits (max=3)
        idx = idx & 7;           // bottom 3 bits (max=7)

        ascii[0] = dna[idx];
        ascii[1] = '\0'; // NUL terminate string

        prepare_text((u8*)ascii, wide);
        draw_glyph(dl, wide, (xPos * 13) + 175, (yPos * 8) + 10, 13.0f, 9.0f);
    }

    gSPEndDisplayList((*dl)++);
}

// ESA: func_8001F200
void setup_terminal_stat_text(void) {
    Animal *a;
    s16 i;
    s16 wide[62];
    u8 ascii[62];

    // pre-fill with empty messages
    for (i = 0; i < 17; i++) {
        if (gTerminalStatText[i] == 0) {
            get_message_address_by_id(0xD5); // ""
        }
    }

    D_803D5520 = &gAnimalState.animals[gCurrentAnimalIndex];
    D_803D5524 = gAnimalState.animals[gCurrentAnimalIndex].unk0;

    D_803D5528 = gAnimalState.animals[gCurrentAnimalIndex].animal;
    a = D_803D5528;
    if (a == NULL) {};
    D_803D552C = a;
    D_803D5530 = a;

    D_803D5538 = 1;
    D_803D553C = gCurrentAnimalIndex;
    D_803D553A = 0;

    gTerminalStatLabels[0] = get_message_address_by_id(0x1F);  // type
    gTerminalStatLabels[1] = get_message_address_by_id(0x2E);  // environment
    gTerminalStatLabels[2] = get_message_address_by_id(0x29);  // skill A
    gTerminalStatLabels[3] = get_message_address_by_id(0x2A);  // skill B
    gTerminalStatLabels[4] = get_message_address_by_id(0x21);  // water resistance
    gTerminalStatLabels[5] = get_message_address_by_id(0x24);  // mass
    gTerminalStatLabels[6] = get_message_address_by_id(0x26);  // armour
    gTerminalStatLabels[7] = get_message_address_by_id(0x25);  // strength
    gTerminalStatLabels[8] = get_message_address_by_id(0x23);  // traction
    gTerminalStatLabels[9] = get_message_address_by_id(0x28);  // fall distance
    gTerminalStatLabels[10] = get_message_address_by_id(0x2C); // production
    gTerminalStatLabels[11] = get_message_address_by_id(0x20); // engine
    gTerminalStatLabels[12] = get_message_address_by_id(0x2D); // intelligence
    gTerminalStatLabels[13] = get_message_address_by_id(0xD5); // ""
    gTerminalStatLabels[14] = get_message_address_by_id(0xD5); // ""
    gTerminalStatLabels[15] = get_message_address_by_id(0xD5); // ""
    gTerminalStatLabels[16] = get_message_address_by_id(0xD5); // ""

    gTerminalStatText[0] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk0);
    gTerminalStatText[11] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk8);
    gTerminalStatText[4] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unkA);
    gTerminalStatText[7] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unkC);
    gTerminalStatText[12] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk2);
    gTerminalStatText[2] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk4);
    gTerminalStatText[3] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk6);

    switch (D_803D5524->biome) {
    case EUROPE_BIOME:
        gTerminalStatText[1] = get_message_address_by_id(0x46); // europe
        break;
    case ICE_BIOME:
        gTerminalStatText[1] = get_message_address_by_id(0x49); // ice
        break;
    case DESERT_BIOME:
        gTerminalStatText[1] = get_message_address_by_id(0x48); // desert
        break;
    case JUNGLE_BIOME:
        gTerminalStatText[1] = get_message_address_by_id(0x47); // jungle
        break;
    }

    switch (D_803D5524->mass) {
    case 0x14:
        gTerminalStatText[5] = get_message_address_by_id(0x34);     // tiny
        gTerminalStatText[10] = get_message_address_by_id(0x33);    // very short
        break;
    case 0x28:
        gTerminalStatText[5] = get_message_address_by_id(0x37);     // light
        gTerminalStatText[10] = get_message_address_by_id(0x36);    // short
        break;
    case 0x3C:
        gTerminalStatText[5] = get_message_address_by_id(0x38);     // medium
        gTerminalStatText[10] = get_message_address_by_id(0x38);    // medium
        break;
    case 0x50:
        gTerminalStatText[5] = get_message_address_by_id(0x3B);     // heavy
        gTerminalStatText[10] = get_message_address_by_id(0x3A);    // long
        break;
    case 0x64:
        gTerminalStatText[5] = get_message_address_by_id(0x3E);     // huge
        gTerminalStatText[10] = get_message_address_by_id(0x3D);    // very long
        break;
    }

    if (D_803D5524->fallDistance < 0x14) {
        gTerminalStatText[9] = get_message_address_by_id(0x32);   // very low
    } else if (D_803D5524->fallDistance < 0x32) {
        gTerminalStatText[9] = get_message_address_by_id(0x35);   // low
    } else if (D_803D5524->fallDistance < 0xA0) {
        gTerminalStatText[9] = get_message_address_by_id(0x38);   // medium
    } else if (D_803D5524->fallDistance < 0x1F4) {
        gTerminalStatText[9] = get_message_address_by_id(0x39);   // high
    } else {
        gTerminalStatText[9] = get_message_address_by_id(0x3C);   // very high
    }

    switch (D_803D5524->armour) {
    case 4:
        gTerminalStatText[6] = get_message_address_by_id(0x37); // light
        break;
    case 8:
        gTerminalStatText[6] = get_message_address_by_id(0x38); // medium
        break;
    case 16:
        gTerminalStatText[6] = get_message_address_by_id(0x3F); // tough
        break;
    case 255:
        gTerminalStatText[6] = get_message_address_by_id(0x40); // invincible
        break;
    }

    if (D_803D5524->traction < 0xA) {
        gTerminalStatText[8] = get_message_address_by_id(0x41); // very poor
    } else if (D_803D5524->traction < 0x13) {
        gTerminalStatText[8] = get_message_address_by_id(0x42); // poor
    } else if (D_803D5524->traction < 0x28) {
        gTerminalStatText[8] = get_message_address_by_id(0x43); // average
    } else if (D_803D5524->traction < 0x46) {
        gTerminalStatText[8] = get_message_address_by_id(0x44); // good
    } else {
        gTerminalStatText[8] = get_message_address_by_id(0x45); // very good
    }

    select_font(0, FONT_COMIC_SANS, 1, 0);
    sprintf((char*)ascii, "%s", " ");
    prepare_text(ascii, wide);
    func_8012D374(&gMainDL, wide, 25, 0, 14.0f, 16.0f, 0);

    for (i = 0; i < 13; i++) {
        gTerminalStatTextX[i] = (gScreenWidth - get_message_width(gTerminalStatText[i])) - 14;
    }

    for (i = 0; i < 13; i++) {
        gTerminalTextScrollState.unk0[i] = 0;
        gTerminalTextScrollState.unk34[i] = 0;
        gTerminalTextScrollState.unk68[i] = 0;
        // huh?
        gTerminalTextScrollState.unk82 = 0;
        gTerminalTextScrollState.unk84 = 0;
        gTerminalTextScrollState.unk86 = 0;
    }
}

void update_terminal_scene_lighting(u8 arg0) {
    func_8032F950_741000();
    func_802C87E0_6D9E90();
    func_802C8878_6D9F28();
    func_802E072C_6F1DDC(1);
    if (gCameraUiState != 0) {
        add_light_at_location(gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h + 64, gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h,      gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h + 64, arg0,    0, arg0, 0);
        add_light_at_location(gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h,      gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h - 64, gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h - 64, arg0, arg0,    0, 0);
        if ((gCameraUiState == 1) && (gTerminalPhase != 2)) {
            func_802F2EEC_70459C(70, 70, 70, 50, 30, 30, 30);
            gCameraUiState += 1;
        }
    }
}

void render_terminal_background_scene(void) {
    switch_to_current_segment(&gMainDL, gDisplayListContext);
    setup_world_perspective_6AB090(gDisplayListContext);
    setup_frame_render_state(gDisplayListContext, &gMainDL);

    gSPViewport(gMainDL++, &gMainViewport);
    gDPSetColorImage(gMainDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(gFrameContextPtr->framebuffer));
    gDPSetScissor(gMainDL++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

    gSPDisplayList(gMainDL++, D_01004270_3DB40);
    gSPDisplayList(gMainDL++, &gDisplayListContext->gOpaqueDL);
}

void render_terminal_stat_text(s32 arg0, s32 arg1) {
    s16 phi_s1;
    s16 var_v1;
    s16 i;
    s16 vertical_offset;

    if (gTerminalTextScrollState.unk82 == 0) {
        if (gTerminalTextScrollState.unk0[0] == 0) {
            phi_s1 = 0;
        } else {
            phi_s1 = get_raw_message_length(gTerminalTextScrollState.unk0[0]);
        }
        if (gTerminalTextScrollState.unk34[0] == 0) {
            var_v1 = 0;
        } else {
            var_v1 = get_raw_message_length(gTerminalTextScrollState.unk34[0]);
        }

        if (gTerminalTextScrollState.unk84 >= (phi_s1 + var_v1 + 3)) {
            gTerminalTextScrollState.unk82 = 1;
            gTerminalTextScrollState.unk84 = 0;
            func_8032C2D0_73D980(SFX_UNKNOWN_21, 0x3800, 1.0f);
        } else {
            if (gTerminalTextScrollState.unk0[0] != 0) {
                func_8012D374(&gMainDL, gTerminalTextScrollState.unk0[0], 25, 210, 14.0f, 16.0f, gTerminalTextScrollState.unk84);
            }
            if ((gTerminalTextScrollState.unk34[0] != 0) && ((phi_s1 + 3) < gTerminalTextScrollState.unk84)) {
                func_8012D374(&gMainDL, gTerminalTextScrollState.unk34[0], gTerminalTextScrollState.unk68[0], 210, 14.0f, 16.0f, (gTerminalTextScrollState.unk84 - phi_s1) - 3);
            }
            if ((gTerminalTextScrollState.unk84 < phi_s1) || ((phi_s1 + 3) < gTerminalTextScrollState.unk84)) {
                func_8032CD20_73E3D0((void*)0x17, 0x36, 0x1AAA, 0, 0.5f);
            }
            gTerminalTextScrollState.unk84++;
        }
    } else {
        gTerminalTextScrollState.unk82 += 2;
        if (gTerminalTextScrollState.unk82 >= 16) {
            gTerminalTextScrollState.unk82 = 0;

            for (i = 11; i >= 0; i--) {
                gTerminalTextScrollState.unk0[i+1] = gTerminalTextScrollState.unk0[i];
                gTerminalTextScrollState.unk34[i+1] = gTerminalTextScrollState.unk34[i];
                gTerminalTextScrollState.unk68[i+1] = gTerminalTextScrollState.unk68[i];
            }

            gTerminalTextScrollState.unk0[0] = gTerminalStatLabels[gTerminalTextScrollState.unk86];
            gTerminalTextScrollState.unk34[0] = gTerminalStatText[gTerminalTextScrollState.unk86];
            gTerminalTextScrollState.unk68[0] = gTerminalStatTextX[gTerminalTextScrollState.unk86];

            gTerminalTextScrollState.unk86 = (gTerminalTextScrollState.unk86 + 1) % 17;
        }
    }

    vertical_offset =  210 - gTerminalTextScrollState.unk82;

    for (i = 0; i < 13; i++) {
        if ((i != 0) || (gTerminalTextScrollState.unk82 != 0)) {
            if (gTerminalTextScrollState.unk0[i] != 0) {
                func_8012D374(&gMainDL, gTerminalTextScrollState.unk0[i], 25, vertical_offset, 14.0f, 16.0f, -1);
            }
            if (gTerminalTextScrollState.unk34[i] != 0) {
                func_8012D374(&gMainDL, gTerminalTextScrollState.unk34[i], gTerminalTextScrollState.unk68[i], vertical_offset, 14.0f, 16.0f, -1);
            }
        }
        vertical_offset -= 15;
    }
}

void spin_dna_helixes(u16 arg0) {
    s32 idx;

    f32 temp_f0;

    s16 i;
    s16 var_v1;

    static f32 D_803F6670;

    idx = step_terminal_dna_simulation() & 0xFF;

    D_803F6670 += 10.0;
    if (D_803F6670 > 5600.0) {
        D_803F6670 -= 5600.0;
    }

    for (i = 0; i < 16; i++) {
        temp_f0 = (((i - 8) * 350.0) - D_803F6670);
        while (temp_f0 < -2800.0) {
            temp_f0 += 5600.0;
        }

        // translate around Z
        guTranslate(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], 0, 0, temp_f0);
        gSPMatrix(gOpaqueDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        guRotate(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], gTerminalDnaSimulation[i][idx][0], 0, 0, 1.0f);
        gSPMatrix(gOpaqueDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        gSPSetLights0(gOpaqueDL++, D_803B65D8_7C7C88);
        gSPDisplayList(gOpaqueDL++, D_0103B880_75150);

        gSPSetLights0(gOpaqueDL++, D_803B65F0_7C7CA0);
        gSPDisplayList(gOpaqueDL++, D_0103BA70_75340);

        gSPSetLights0(gOpaqueDL++, D_803B65A8_7C7C58);
        gSPDisplayList(gOpaqueDL++, D_0103EC20_784F0);

        var_v1 = MIN(0xFF, arg0 * 4);

        D_803B65D8_7C7C88.a.l.col[0] = D_803B65D8_7C7C88.a.l.colc[0] = (var_v1 * 25) >> 8;
        D_803B65D8_7C7C88.a.l.col[1] = D_803B65D8_7C7C88.a.l.colc[1] = (var_v1 * 50) >> 8;
        D_803B65D8_7C7C88.a.l.col[2] = D_803B65D8_7C7C88.a.l.colc[2] = (var_v1 * 0) >> 8;
        D_803B65D8_7C7C88.l[0].l.col[0] = D_803B65D8_7C7C88.l[0].l.colc[0] = (var_v1 * 100) >> 8;
        D_803B65D8_7C7C88.l[0].l.col[1] = D_803B65D8_7C7C88.l[0].l.colc[1] = (var_v1 * 150) >> 8;
        D_803B65D8_7C7C88.l[0].l.col[2] = D_803B65D8_7C7C88.l[0].l.colc[2] = (var_v1 * 0) >> 8;

        D_803B65F0_7C7CA0.a.l.col[0] = D_803B65F0_7C7CA0.a.l.colc[0] = (var_v1 * 20) >> 8;
        D_803B65F0_7C7CA0.a.l.col[1] = D_803B65F0_7C7CA0.a.l.colc[1] = (var_v1 * 50) >> 8;
        D_803B65F0_7C7CA0.a.l.col[2] = D_803B65F0_7C7CA0.a.l.colc[2] = (var_v1 * 0) >> 8;
        D_803B65F0_7C7CA0.l[0].l.col[0] = D_803B65F0_7C7CA0.l[0].l.colc[0] = (var_v1 * 75) >> 8;
        D_803B65F0_7C7CA0.l[0].l.col[1] = D_803B65F0_7C7CA0.l[0].l.colc[1] = (var_v1 * 150) >> 8;
        D_803B65F0_7C7CA0.l[0].l.col[2] = D_803B65F0_7C7CA0.l[0].l.colc[2] = (var_v1 * 0) >> 8;

        D_803B65A8_7C7C58.a.l.col[0] = D_803B65A8_7C7C58.a.l.colc[0] = (var_v1 * 0) >> 8;
        D_803B65A8_7C7C58.a.l.col[1] = D_803B65A8_7C7C58.a.l.colc[1] = (var_v1 * 10) >> 8;
        D_803B65A8_7C7C58.a.l.col[2] = D_803B65A8_7C7C58.a.l.colc[2] = (var_v1 * 0) >> 8;
        D_803B65A8_7C7C58.l[0].l.col[0] = D_803B65A8_7C7C58.l[0].l.colc[0] = (var_v1 * 0) >> 8;
        D_803B65A8_7C7C58.l[0].l.col[1] = D_803B65A8_7C7C58.l[0].l.colc[1] = (var_v1 * 100) >> 8;
        D_803B65A8_7C7C58.l[0].l.col[2] = D_803B65A8_7C7C58.l[0].l.colc[2] = (var_v1 * 0) >> 8;

        gSPPopMatrix(gOpaqueDL++, G_MTX_MODELVIEW);
    }
}

void render_terminal_background_dna_79FBB4(u16 arg0) {
    u16 norm;
    static s16 D_803B66E0_7C7D90 = 0; // .data

    guPerspective(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], &norm, 33.0f, 1.33333333f, 100.0f, 25000.0, 1.0f);
    gSPMatrix(gOpaqueDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(gOpaqueDL++, norm);
    guLookAt(
        &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs],
        7000.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        (SIN(D_803B66E0_7C7D90) >> 7) / 3000.0,
        (COS(D_803B66E0_7C7D90) >> 7) / 3000.0,
        1.0f);
    gSPMatrix(gOpaqueDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    guScale(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], 1.0f, 1.0f, 1.0f);

    gSPMatrix(gOpaqueDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(gOpaqueDL++, gTerminalDnaOpaqueRenderSetupDl);
    D_803B66E0_7C7D90 = (D_803B66E0_7C7D90 + 1) & 0xFF;
    gSPDisplayList(gOpaqueDL++, gTerminalDnaInterlaceRenderSetupDl);
    spin_dna_helixes(arg0);
}

u8 step_terminal_dna_simulation(void) {
    f32 temp_f16;
    s16 i;
    u16 rand;
    u8 idx;
    u8 var_v0;

    static s16 D_803F6674;
    static u8 D_803B66E4_7C7D94 = 0;

    D_803F6674 = (D_803F6674 + 1) & 0x1FF;

    if (D_803B66E4_7C7D94) {
        D_803B66E4_7C7D94 = 0;
        idx = 1;
    } else {
        D_803B66E4_7C7D94 = 1;
        idx = 0;
    }

    for (i = 0; i < 16; i++) {
        temp_f16 = (gTerminalDnaSimulation[(i - 1) & 0xF][D_803B66E4_7C7D94][0] + gTerminalDnaSimulation[(i + 1) & 0xF][D_803B66E4_7C7D94][0]) / 2.0;
        gTerminalDnaSimulation[i][idx][1] = (gTerminalDnaSimulation[i][D_803B66E4_7C7D94][1] * 0.995) + ((temp_f16 - gTerminalDnaSimulation[i][D_803B66E4_7C7D94][0]) * 0.1);
        gTerminalDnaSimulation[i][idx][0] = gTerminalDnaSimulation[i][D_803B66E4_7C7D94][0] + gTerminalDnaSimulation[i][idx][1];
    }

    rand = advance_random_seed();
    if ((rand & 0xFF00) == 0x3400) {
        gTerminalDnaSimulation[(rand & 0xF)][idx][1] += (((rand >> 4) & 0xF) - 7) * 10.0;
    }
    gTerminalDnaSimulation[8][idx][1] += (SIN(D_803F6674 >> 1) >> 7) / 200.0;

    return idx;
}

void render_terminal_background_frame(void) {
    s32 test;
    s16 i; // sp6A
    s16 sp68;
    s16 sp66;

    load_segments(&gMainDL, gDisplayListContext);
    switch_to_current_segment(&gMainDL, gDisplayListContext);

    gSPViewport(gMainDL++, &gMainViewport);
    clear_depth_buffer(&gMainDL);

    gDPSetColorImage(gMainDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(gFrameContextPtr->framebuffer));
    gDPSetScissor(gMainDL++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gSPFogFactor(gMainDL++, -3072, -22016);
    gDPSetFogColor(gMainDL++, 0x00, 0x00, 0x00, 0x00);

    if (gTerminalFadeStep == 0) {
        start_sfx_volume_fade(1.0f, 0.0f, 20.0f);
        D_803F6470 = 0;
        D_803F646C = 0.0f;
        if (D_80291090.hasRumblePak[0] != 0) { // Controller array
            func_80137168();
            func_8013724C(0);
        }
    }
    if (D_803F6470 < 100) {
        D_803F6470 += 1;
    }
    if ((D_803F6470 == 5) && (gCameraUiState == 3)) {
        play_sound_effect(SFX_UNKNOWN_135, 0, 0x5000, 1.0f, 0x40);
    }
    if (gTerminalFadeStep < 2) {
        draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, 0xFF);
        gTerminalFadeStep++;
    }
    func_8032CD20_73E3D0((void*)0x45, SFX_UNKNOWN_132, 6144.0f * D_803F646C, 0, 1.0f);
    func_8032CD20_73E3D0((void*)0xA9, SFX_UNKNOWN_133, 4352.0f * D_803F646C, 0, 0.7f);
    func_8032CD20_73E3D0((void*)0x171, SFX_UNKNOWN_133, 4352.0f * D_803F646C, 0, 1.0f);
    func_8032CD20_73E3D0((void*)0x10D, SFX_UNKNOWN_134, 21760.0f * D_803F646C, 0, 1.0f);

    if (D_803F646C < 1.0) {
        D_803F646C += 0.016;
    }

    gScreenHeight = 240;
    D_803A6CC4_7B8374 = ((SIN(D_803F6472 * 2) >> 7) / 3200.0) + 0.7; // D_803C0170_7D1820
    D_803A6CC8_7B8378 = ((SIN(D_803F6472) >> 7) / 15.0) + 45.0; // D_803C0178_7D1828
    D_803F6472++;

    gMainViewport.vp.vscale[0] = gScreenWidth  << 1;
    gMainViewport.vp.vscale[1] = gScreenHeight << 1;
    gMainViewport.vp.vtrans[0] = gScreenWidth  << 1;
    gMainViewport.vp.vtrans[1] = gScreenHeight << 1;

    func_8038CF90_79E640();
    if (gTerminalPhase == 0) {
        draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, 75);
    } else {
        draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, 100);
    }

    switch (gTerminalPhase) {
    case 0:
        if (gScreenWidth < 320) {
            gScreenWidth = gScreenWidth + 2;
        }
        update_terminal_scene_lighting(0xFF);
        render_terminal_background_scene();

        if (D_803B6310_7C79C0++ > 40) {
            gTerminalTransitionCounter = 1;
            D_803B6310_7C79C0 = 0;
            gTerminalPhase = 1;
        }
        break;
    case 1:
        gScreenWidth = 320;
        load_default_display_list(&gMainDL);
        set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
        select_font(0, FONT_COMIC_SANS, 1, 0);
        update_terminal_scene_lighting(0xFF);

        sp68 = SSSV_RAND(8);
        for (i = 0; i < 6; i++) {
            sp66 = i*40 + sp68;

            gDPSetColorImage(gMainDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(gFrameContextPtr->framebuffer + ((sp66 * 10) << 6)));
            gDPSetScissor(gMainDL++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, (gScreenHeight - sp66 - 1) - 8);
            gSPDisplayList(gMainDL++, gLayer0DL);
        }

        gDPSetColorImage(gMainDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(gFrameContextPtr->framebuffer));
        gDPSetScissor(gMainDL++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

        render_terminal_background_glyphs(&gLayer0DL, D_803B6310_7C79C0);
        render_terminal_background_scene();
        render_terminal_background_dna_79FBB4(D_803B6310_7C79C0);
        load_default_display_list(&gMainDL);
        set_menu_text_color(0x80, 0xFF, 0, 0xFF);
        select_font(0, FONT_COMIC_SANS, 1, 0);
        render_terminal_stat_text(0xE, 0x10);
        if (D_803B6310_7C79C0++ > 65000) {
            D_803B6310_7C79C0 = 200;
        }
        if ((gControllerInput->button & A_BUTTON) || (gControllerInput->button & B_BUTTON)) {
            // exit screen?
            if (gTerminalTransitionCounter == 0) {
                start_sequence_volume_fade(0, 25.0f, 0, 20.0f);
                gTerminalFadeStep = 0;
                gTerminalTransitionCounter = 1;
                D_803B6310_7C79C0 = 0;
                gUiFlowState.unk0 = 0;
                D_803F2C6C = D_803F2C6D = 0;
                gTerminalPhase = 0;
                D_803F6460 = 100;
                gControllerDebounce = 18;
                draw_rectangle(&gMainDL, 0, 0, 320, 240, 0, 0, 0, 0xFF);
                if (gCameraUiState == 4) {
                    gCameraUiState = 2;
                    D_803F6468 = 0;
                    D_803F2AA3 = 60;
                } else {
                    gCameraUiState = 0;
                }
            }
        }
        break;
    case 2:
        update_terminal_scene_lighting(0xFF);
        if (D_803B6310_7C79C0 && D_803B6310_7C79C0) {} // permuter
        render_terminal_background_scene();
        if (D_803B6310_7C79C0 == 1) {
            func_802F2EEC_70459C(80, 80, 80, 200, 200, 200, 10);
        }
        D_803B6310_7C79C0 += 1;
        if ((D_803B6310_7C79C0) == 40) {
            D_803B6310_7C79C0 = 0;
            gCameraUiState = 0;
            gUiFlowState.unk0 = 0;
            D_803F2C6C = D_803F2C6D = 0;
            gTerminalPhase = 0;
        }
        break;
    }

    if (gTerminalTransitionCounter != 0) {
        test = gTerminalTransitionCounter ^ 7;
        gTerminalTransitionCounter = gTerminalTransitionCounter + 1;
        if (test == 0) {
            gTerminalTransitionCounter = 0;
        }
    }
}

void func_8038F414_7A0AC4(void) {
    switch (gCameraUiState) {
    case 0:
        if (D_803F6460 > 0) {
            D_803F6460 -= 1;
        }
        if ((D_803F2AA3 > 0) && (--D_803F2AA3  == 0)) {
            gCameraUiState = 3;
            gTerminalPhase = 0;
            setup_terminal_stat_text();
            D_803B6310_7C79C0 = 0;
            D_803A6CC4_7B8374 = 0.7f;
            D_803A6CC8_7B8378 = 45.0f;
            D_803F6472 = 0;
            gUiFlowState.unk0 = 3;
            D_803F6474 = D_803F2D50.unkDA;
        }
        break;
    case 1:
        if (D_803F2AA3 > 0) {
            D_803F2AA3--;
        }
        if ((D_803F2AA3 <= 0) && (D_803F6468 >= 100)) {
            func_802B342C_6C4ADC();
            start_sequence_volume_fade(0, 25.0f, 20.0f, 0.0f);
            gCameraUiState = 4;
            gTerminalPhase = 1;
            setup_terminal_stat_text();
            D_803B6310_7C79C0 = 0;
            D_803A6CC4_7B8374 = 0.7f;
            D_803A6CC8_7B8378 = 45.0f;
            D_803F6472 = 0;
            gUiFlowState.unk0 = 3;
            D_803F6474 = D_803F2D50.unkDA;
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
        }
        break;
    case 2:
        if ((D_803F2AA3 > 0) && (--D_803F2AA3 == 0)) {
            gCameraUiState = 0;
            func_802B34DC_6C4B8C();
        }
    }
}

void func_8038F5F8_7A0CA8(Animal *arg0) {
    if ((gAnimalState.animals[gCurrentAnimalIndex].animal->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO) &&
        (gAnimalState.animals[gCurrentAnimalIndex].animal->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        if (D_803F6460 == 0) {
            gControllerDebounce = 100;
            gCameraUiState = 1;
            D_803F6464 = arg0;
            D_803F6468 = 0;
            D_803F2AA3 = 100;
            D_803F6460 = 100;
            set_species_as_encountered(gAnimalState.animals[gCurrentAnimalIndex].animal->unk16C->unk9C);
        }
    }
}

// NOTE: there is a bug if paused is pressed during transition to NAC
void trigger_new_animal_cutscene(void) {
    gCameraUiState = 0;
    D_803F2AA3 = 25;
    start_sequence_volume_fade(0, 135.0f, 20.0f, 0);
    start_sfx_volume_fade(135.0f, 20.0f, 0);
}
