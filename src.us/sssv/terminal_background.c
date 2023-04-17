#include <ultra64.h>
#include "common.h"


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

s16 *D_803B6560_7C7C10[18] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0,
};

Lights1 D_803B65A8_7C7C58 = gdSPDefLights1(0x00, 0x0A, 0x00, 0x00, 0x64, 0x00, 0x04, 0x00, 0x08);
Lights1 D_803B65C0_7C7C70 = gdSPDefLights1(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0x08);
Lights1 D_803B65D8_7C7C88 = gdSPDefLights1(0x19, 0x32, 0x00, 0x64, 0xC8, 0x00, 0x04, 0x00, 0x08);
Lights1 D_803B65E8_7C7CA0 = gdSPDefLights1(0x00, 0x19, 0x00, 0x32, 0xC8, 0x00, 0x04, 0x00, 0x08);

Gfx D_803B6608_7C7CB8[] = {
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

Gfx D_803B66B8_7C7D68[] = {
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_INTER, G_RM_AA_ZB_OPA_INTER2),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};


void func_8038CF90_79E640(void) {
    gSPDisplayList(D_801D9E7C++, D_01004270_3DB40);
    gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
}

// ========================================================
// .bss (D_803F6460 to D_803F6680)
// ========================================================

u8   D_803F6460;
Animal *D_803F6464;
s16  D_803F6468;
f32  D_803F646C;
s16  D_803F6470;
s8   D_803F6472;
s16  D_803F6474;
struct109 D_803F6478;
s16 *D_803F6500[18];
s16  D_803F6548[20];
f32  D_803F6570[32][2]; // tbd
f32  D_803F6670;
s16  D_803F6674;

// ========================================================
// definitions
// ========================================================

void func_8038DF18_79F5C8(u16 arg0);
u8 func_8038E80C_79FEBC(void);

// ========================================================
// .text
// ========================================================

void func_8038D004_79E6B4(Gfx **dl, u16 intensity) {
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
        idx = func_8012826C();   // random number

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

void func_8038D258_79E908(void) {
    Animal *a;
    s16 i;
    s16 wide[62];
    u8 ascii[62];

    // pre-fill with empty messages
    for (i = 0; i < 17; i++) {
        if (D_803B6560_7C7C10[i] == 0) {
            get_message_address_by_id(0xD5); // ""
        }
    }

    D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
    D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

    D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    a = D_803D5528;
    if (a == NULL) {};
    D_803D552C = a;
    D_803D5530 = a;

    D_803D5538 = 1;
    D_803D553C = gCurrentAnimalIndex;
    D_803D553A = 0;

    D_803F6500[0] = get_message_address_by_id(0x1F);  // type
    D_803F6500[1] = get_message_address_by_id(0x2E);  // environment
    D_803F6500[2] = get_message_address_by_id(0x29);  // skill A
    D_803F6500[3] = get_message_address_by_id(0x2A);  // skill B
    D_803F6500[4] = get_message_address_by_id(0x21);  // water resistance
    D_803F6500[5] = get_message_address_by_id(0x24);  // mass
    D_803F6500[6] = get_message_address_by_id(0x26);  // armour
    D_803F6500[7] = get_message_address_by_id(0x25);  // strength
    D_803F6500[8] = get_message_address_by_id(0x23);  // traction
    D_803F6500[9] = get_message_address_by_id(0x28);  // fall distance
    D_803F6500[10] = get_message_address_by_id(0x2C); // production
    D_803F6500[11] = get_message_address_by_id(0x20); // engine
    D_803F6500[12] = get_message_address_by_id(0x2D); // intelligence
    D_803F6500[13] = get_message_address_by_id(0xD5); // ""
    D_803F6500[14] = get_message_address_by_id(0xD5); // ""
    D_803F6500[15] = get_message_address_by_id(0xD5); // ""
    D_803F6500[16] = get_message_address_by_id(0xD5); // ""

    D_803B6560_7C7C10[0] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk0);
    D_803B6560_7C7C10[11] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk8);
    D_803B6560_7C7C10[4] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unkA);
    D_803B6560_7C7C10[7] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unkC);
    D_803B6560_7C7C10[12] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk2);
    D_803B6560_7C7C10[2] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk4);
    D_803B6560_7C7C10[3] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk6);

    switch (D_803D5524->biome) {
    case EUROPE_BIOME:
        D_803B6560_7C7C10[1] = get_message_address_by_id(0x46); // europe
        break;
    case ICE_BIOME:
        D_803B6560_7C7C10[1] = get_message_address_by_id(0x49); // ice
        break;
    case DESERT_BIOME:
        D_803B6560_7C7C10[1] = get_message_address_by_id(0x48); // desert
        break;
    case JUNGLE_BIOME:
        D_803B6560_7C7C10[1] = get_message_address_by_id(0x47); // jungle
        break;
    }

    switch (D_803D5524->mass) {
    case 0x14:
        D_803B6560_7C7C10[5] = get_message_address_by_id(0x34);     // tiny
        D_803B6560_7C7C10[10] = get_message_address_by_id(0x33);    // very short
        break;
    case 0x28:
        D_803B6560_7C7C10[5] = get_message_address_by_id(0x37);     // light
        D_803B6560_7C7C10[10] = get_message_address_by_id(0x36);    // short
        break;
    case 0x3C:
        D_803B6560_7C7C10[5] = get_message_address_by_id(0x38);     // medium
        D_803B6560_7C7C10[10] = get_message_address_by_id(0x38);    // medium
        break;
    case 0x50:
        D_803B6560_7C7C10[5] = get_message_address_by_id(0x3B);     // heavy
        D_803B6560_7C7C10[10] = get_message_address_by_id(0x3A);    // long
        break;
    case 0x64:
        D_803B6560_7C7C10[5] = get_message_address_by_id(0x3E);     // huge
        D_803B6560_7C7C10[10] = get_message_address_by_id(0x3D);    // very long
        break;
    }

    if (D_803D5524->fallDistance < 0x14) {
        D_803B6560_7C7C10[9] = get_message_address_by_id(0x32);   // very low
    } else if (D_803D5524->fallDistance < 0x32) {
        D_803B6560_7C7C10[9] = get_message_address_by_id(0x35);   // low
    } else if (D_803D5524->fallDistance < 0xA0) {
        D_803B6560_7C7C10[9] = get_message_address_by_id(0x38);   // medium
    } else if (D_803D5524->fallDistance < 0x1F4) {
        D_803B6560_7C7C10[9] = get_message_address_by_id(0x39);   // high
    } else {
        D_803B6560_7C7C10[9] = get_message_address_by_id(0x3C);   // very high
    }

    switch (D_803D5524->armour) {
    case 4:
        D_803B6560_7C7C10[6] = get_message_address_by_id(0x37); // light
        break;
    case 8:
        D_803B6560_7C7C10[6] = get_message_address_by_id(0x38); // medium
        break;
    case 16:
        D_803B6560_7C7C10[6] = get_message_address_by_id(0x3F); // tough
        break;
    case 255:
        D_803B6560_7C7C10[6] = get_message_address_by_id(0x40); // invincible
        break;
    }

    if (D_803D5524->traction < 0xA) {
        D_803B6560_7C7C10[8] = get_message_address_by_id(0x41); // very poor
    } else if (D_803D5524->traction < 0x13) {
        D_803B6560_7C7C10[8] = get_message_address_by_id(0x42); // poor
    } else if (D_803D5524->traction < 0x28) {
        D_803B6560_7C7C10[8] = get_message_address_by_id(0x43); // average
    } else if (D_803D5524->traction < 0x46) {
        D_803B6560_7C7C10[8] = get_message_address_by_id(0x44); // good
    } else {
        D_803B6560_7C7C10[8] = get_message_address_by_id(0x45); // very good
    }

    select_font(0, FONT_COMIC_SANS, 1, 0);
    sprintf((char*)ascii, "%s", " ");
    prepare_text(ascii, wide);
    func_8012D374(&D_801D9E7C, wide, 25, 0, 14.0f, 16.0f, 0);

    for (i = 0; i < 13; i++) {
        D_803F6548[i] = (gScreenWidth - func_8012C3D8(D_803B6560_7C7C10[i])) - 14;
    }

    for (i = 0; i < 13; i++) {
        D_803F6478.unk0[i] = 0;
        D_803F6478.unk34[i] = 0;
        D_803F6478.unk68[i] = 0;
        // huh?
        D_803F6478.unk82 = 0;
        D_803F6478.unk84 = 0;
        D_803F6478.unk86 = 0;
    }
}

void func_8038D920_79EFD0(u8 arg0) {
    func_8032F950_741000();
    func_802C87E0_6D9E90();
    func_802C8878_6D9F28();
    func_802E072C_6F1DDC(1);
    if (D_803F2AA2 != 0) {
        add_light_at_location(D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h + 64, D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h,      D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h + 64, arg0,    0, arg0, 0);
        add_light_at_location(D_801D9ED8.animals[gCurrentAnimalIndex].animal->xPos.h,      D_801D9ED8.animals[gCurrentAnimalIndex].animal->zPos.h - 64, D_801D9ED8.animals[gCurrentAnimalIndex].animal->yPos.h - 64, arg0, arg0,    0, 0);
        if ((D_803F2AA2 == 1) && (D_803B6318 != 2)) {
            func_802F2EEC_70459C(70, 70, 70, 50, 30, 30, 30);
            D_803F2AA2 += 1;
        }
    }
}

void func_8038DA70_79F120(void) {
    func_80380490_791B40(&D_801D9E7C, D_80204278);
    func_802999E0_6AB090(D_80204278);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

    gSPDisplayList(D_801D9E7C++, D_01004270_3DB40);
    gSPDisplayList(D_801D9E7C++, &D_80204278->unk9600);
}

void func_8038DBE0_79F290(s32 arg0, s32 arg1) {
    s16 phi_s1;
    s16 phi_v1;
    s16 i;
    s16 vertical_offset;

    if (D_803F6478.unk82 == 0) {
        if (D_803F6478.unk0[0] == 0) {
            phi_s1 = 0;
        } else {
            phi_s1 = get_raw_message_length(D_803F6478.unk0[0]);
        }
        if (D_803F6478.unk34[0] == 0) {
            phi_v1 = 0;
        } else {
            phi_v1 = get_raw_message_length(D_803F6478.unk34[0]);
        }

        if (D_803F6478.unk84 >= (phi_s1 + phi_v1 + 3)) {
            D_803F6478.unk82 = 1;
            D_803F6478.unk84 = 0;
            func_8032C2D0_73D980(SFX_UNKNOWN_21, 0x3800, 1.0f);
        } else {
            if (D_803F6478.unk0[0] != 0) {
                func_8012D374(&D_801D9E7C, D_803F6478.unk0[0], 25, 210, 14.0f, 16.0f, D_803F6478.unk84);
            }
            if ((D_803F6478.unk34[0] != 0) && ((phi_s1 + 3) < D_803F6478.unk84)) {
                func_8012D374(&D_801D9E7C, D_803F6478.unk34[0], D_803F6478.unk68[0], 210, 14.0f, 16.0f, (D_803F6478.unk84 - phi_s1) - 3);
            }
            if ((D_803F6478.unk84 < phi_s1) || ((phi_s1 + 3) < D_803F6478.unk84)) {
                func_8032CD20_73E3D0(0x17, 0x36, 0x1AAA, 0, 0.5f);
            }
            D_803F6478.unk84++;
        }
    } else {
        D_803F6478.unk82 += 2;
        if (D_803F6478.unk82 >= 16) {
            D_803F6478.unk82 = 0;

            for (i = 11; i >= 0; i--) {
                D_803F6478.unk0[i+1] = D_803F6478.unk0[i];
                D_803F6478.unk34[i+1] = D_803F6478.unk34[i];
                D_803F6478.unk68[i+1] = D_803F6478.unk68[i];
            }

            D_803F6478.unk0[0] = D_803F6500[D_803F6478.unk86];
            D_803F6478.unk34[0] = D_803B6560_7C7C10[D_803F6478.unk86];
            D_803F6478.unk68[0] = D_803F6548[D_803F6478.unk86];

            D_803F6478.unk86 = (D_803F6478.unk86 + 1) % 17;
        }
    }

    vertical_offset =  210 - D_803F6478.unk82;

    for (i = 0; i < 13; i++) {
        if ((i != 0) || (D_803F6478.unk82 != 0)) {
            if (D_803F6478.unk0[i] != 0) {
                func_8012D374(&D_801D9E7C, D_803F6478.unk0[i], 25, vertical_offset, 14.0f, 16.0f, -1);
            }
            if (D_803F6478.unk34[i] != 0) {
                func_8012D374(&D_801D9E7C, D_803F6478.unk34[i], D_803F6478.unk68[i], vertical_offset, 14.0f, 16.0f, -1);
            }
        }
        vertical_offset -= 15;
    }
}

#if 0
// spin_dna_helixes
// TOOD: re-m2c this
void func_8038DF18_79F5C8(u16 arg0) {
    s32 sp9C;
    Lights1 *sp98;
    Lights1 *sp94;
    s32 sp90;
    Lights1 *sp8C;
    Lights1 *sp88;
    s32 sp84;
    Lights1 *sp80;
    Lights1 *sp7C;
    s32 sp78;
    s32 sp74;

    f32 temp_f0_2;
    f64 temp_f22;

    // static f32 D_803F6670;

    f32 phi_f12;
    s16 i;
    f32 phi_f2;
    s16 phi_v1;

    // temp_f22 = 5600.0; //D_803C0128_7D17D8;
    phi_f12 = D_803F6670 + 10.0;
    // phi_f12 = temp_f12;

    if (5600.0 < phi_f12) {
        phi_f12 = phi_f12 - 5600.0;
    }
    D_803F6670 = phi_f12;

    sp9C = (func_8038E80C_79FEBC() & 0xFF) * 8;
    sp98 = &D_803B65E0_7C7C90;
    D_803F6670 = var_f12;
    sp94 = &D_803B65D8_7C7C88;
    sp88 = &D_803B65F0_7C7CA0;
    sp8C = &D_803B65F8_7C7CA8;
    sp90 = &D_0103B880_75150;
    sp84 = &D_0103BA70_75340;
    sp80 = &D_803B65B0_7C7C60;

    sp74 = arg0 * 4;
    sp7C = &D_803B65A8_7C7C58;
    sp78 = &D_0103EC20_784F0;
    // temp_f20 = D_803C0138_7D17E8;

    for (i = 0; i < 16; i++) {
        // D_803C0130_7D17E0
        temp_f0_2 = (((i - 8) * 350.0) - D_803F6670);
        while (temp_f0_2 < -2800.0) {
            temp_f0_2 += 5600.0;
        }

        // translate around Z
        guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, temp_f0_2);
        gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803F6570[(i * 16) + sp9C], 0, 0, 1.0f);
        gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        gSPNumLights(D_801D9E88++, 1);
        gSPLight(D_801D9E88++, sp98, 1);
        gSPLight(D_801D9E88++, sp94, 2);
        gSPDisplayList(D_801D9E88++, sp90);

        gSPNumLights(D_801D9E88++, 1);
        gSPLight(D_801D9E88++, sp8C, 1);
        gSPLight(D_801D9E88++, sp88, 2);
        gSPDisplayList(D_801D9E88++, sp84);

        gSPNumLights(D_801D9E88++, 1);
        gSPLight(D_801D9E88++, sp80, 1);
        gSPLight(D_801D9E88++, sp7C, 2);
        gSPDisplayList(D_801D9E88++, sp78);

        if (sp74 >= 0x100) {
            phi_v1 = 0xFF;
        } else {
            phi_v1 = sp74; // sp78?
        }

        // temp_t9 = (phi_v1 * 0x32) >> 8;
        D_803B65D8_7C7C88.a.l.col[1] = D_803B65D8_7C7C88.a.l.colc[1] = (phi_v1 * 0x32) >> 8;;
        D_803B65F0_7C7CA0.a.l.col[1] = D_803B65F0_7C7CA0.a.l.colc[1] = (phi_v1 * 0x32) >> 8;;
        // temp_t8 = (phi_v1 * 0x19) >> 8;
        D_803B65D8_7C7C88.a.l.col[0] = D_803B65D8_7C7C88.a.l.colc[0] = (phi_v1 * 0x19) >> 8;;
        // temp_t6 = (phi_v1 * 0x64) >> 8;
        D_803B65D8_7C7C88.l[0].unk8 = D_803B65D8_7C7C88.l[0].unkC = (phi_v1 * 0x64) >> 8;;
        D_803B65F0_7C7CA0.unk8 = D_803B65F0_7C7CA0.unkC = (phi_v1 * 0x4B) >> 8;
        // temp_t7 = (phi_v1 * 0x96) >> 8;
        D_803B65D8_7C7C88.l[0].unk9 = D_803B65D8_7C7C88.l[0].unkD = (phi_v1 * 0x96) >> 8;
        D_803B65F0_7C7CA0.unk9 = D_803B65F0_7C7CA0.unkD = (phi_v1 * 0x96) >> 8;
        D_803B65F0_7C7CA0.a.l.col[0] = D_803B65F0_7C7CA0.a.l.colc[0] = (phi_v1 * 0x14) >> 8;
        D_803B65D8_7C7C88.a.l.unk2 = D_803B65D8_7C7C88.a.l.unk6 = 0;
        D_803B65D8_7C7C88.l[0].unkA = D_803B65D8_7C7C88.l[0].unkE = 0;
        D_803B65F0_7C7CA0.unk2 = D_803B65F0_7C7CA0.unk6 = 0;
        D_803B65F0_7C7CA0.unkA = D_803B65F0_7C7CA0.unkE = 0;
        D_803B65A8_7C7C58.a.l.col[0] = D_803B65A8_7C7C58.a.l.colc[0] = 0;
        D_803B65A8_7C7C58.a.l.col[1] = D_803B65A8_7C7C58.a.l.colc[1] = (phi_v1 * 0xA) >> 8;
        D_803B65A8_7C7C58.unk2 = D_803B65A8_7C7C58.unk6 = 0;
        D_803B65A8_7C7C58.unk8 = D_803B65A8_7C7C58.unkC = 0;
        D_803B65A8_7C7C58.unk9 = D_803B65A8_7C7C58.unkD = (phi_v1 * 0x64) >> 8;;
        D_803B65A8_7C7C58.unkA = D_803B65A8_7C7C58.unkE = 0;

        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038DF18_79F5C8.s")
#endif

extern Gfx D_803B6608_7C7CB8[];
extern Gfx D_803B66B8_7C7D68[];

void func_8038E504_79FBB4(u16 arg0) {
    u16 norm;
    static s16 D_803B66E0_7C7D90 = 0; // .data

    guPerspective(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], &norm, 33.0f, 1.33333333f, 100.0f, 25000.0, 1.0f);
    gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(D_801D9E88++, norm);
    guLookAt(
        &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
        7000.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        (D_80152C78[D_803B66E0_7C7D90 & 0xFF] >> 7) / 3000.0,
        (D_80152C78[(D_803B66E0_7C7D90 + 0x40) & 0xFF] >> 7) / 3000.0,
        1.0f);
    gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 1.0f, 1.0f, 1.0f);

    gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(D_801D9E88++, D_803B6608_7C7CB8);
    D_803B66E0_7C7D90 = (D_803B66E0_7C7D90 + 1) & 0xFF;
    gSPDisplayList(D_801D9E88++, D_803B66B8_7C7D68);
    func_8038DF18_79F5C8(arg0);
}

#if 0
u8 func_8038E80C_79FEBC(void) {
    static u8 D_803B66E4_7C7D94 = 0;
    s16 temp_a0;
    s16 i;

    u16 temp_v0_2;
    u8 var_t2;
    // u8 var_v0;

    D_803F6674 = (D_803F6674 + 1) & 0x1FF;
    if (D_803B66E4_7C7D94 != 0) {
        D_803B66E4_7C7D94 = 0;
        var_t2 = 1;
    } else {
        D_803B66E4_7C7D94 = 1;
        var_t2 = 0;
    }

    for (i = 0; i < 16; i++) {
        D_803F6570[i][D_803B66E4_7C7D94+1] = ((((f32) ((D_803F6570[temp_a0 & 0xF][D_803B66E4_7C7D94] + (D_803F6570[(i - 1) & 0xF][D_803B66E4_7C7D94])) * 0.5) - D_803F6570[i][D_803B66E4_7C7D94+0]) * 0.1) + (D_803F6570[i][D_803B66E4_7C7D94+1] * 0.995));
        D_803F6570[i][D_803B66E4_7C7D94+0] += D_803F6570[i][D_803B66E4_7C7D94+1];
    }

    temp_v0_2 = func_8012826C();
    if ((temp_v0_2 & 0xFF00) == 0x3400) {
        D_803F6570[temp_v0_2 & 0xF][var_t2+1] += (f32) ((f64) D_803F6570[temp_v0_2 & 0xF][var_t2+1] + ((f64) (((temp_v0_2 >> 4) & 0xF) - 7) * 10.0));
    }

    D_803F6570[16][var_t2+1] = D_803F6570[16][var_t2+1] + ( ((s16) D_80152C78[((s16) D_803F6674 >> 1) & 0xFF] >> 7) / 200.0); // unk84

    return var_t2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E80C_79FEBC.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E9F8_7A00A8.s")
// lots to do here
// void func_8038E9F8_7A00A8(void) {
//     s16 sp68;
//     s16 temp_a0;
//     s16 temp_v0_2;
//     s16 temp_v0_5;
//     s16 i;
//
//     load_segments(&D_801D9E7C, D_80204278);
//     func_80380490_791B40(&D_801D9E7C, D_80204278);
//
//     gSPViewport(D_801D9E7C++, &D_80152EA8);
//     func_80129430(&D_801D9E7C);
//
//     gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
//     gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
//     gSPFogPosition(D_801D9E7C++, -3026, -3067); // use gSPFogFactor
//     gDPSetFogColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
//
//     if (D_803B6314 == 0) {
//         func_8013385C(1.0f, 0.0f, 20.0f);
//         D_803F6470 = 0;
//         D_803F646C = 0.0f;
//         if (D_80291090.hasRumblePak[0] != 0) { // Controller array
//             func_80137168();
//             func_8013724C(0);
//         }
//     }
//     if (D_803F6470 < 100) {
//         D_803F6470 += 1;
//     }
//     if ((D_803F6470 == 5) && (D_803F2AA2 == 3)) {
//         play_sound_effect(SFX_UNKNOWN_135, 0, 0x5000, 1.0f, 0x40);
//     }
//     if (D_803B6314 < 2) {
//         draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 0xFF);
//         D_803B6314 += 1;
//     }
//     func_8032CD20_73E3D0(0x45, SFX_UNKNOWN_132, 6144.0f * D_803F646C, 0, 1.0f);
//     func_8032CD20_73E3D0(0xA9, SFX_UNKNOWN_133, 4352.0f * D_803F646C, 0, 0.7f); // 0.6999999881, D_803C0160_7D1810
//     func_8032CD20_73E3D0(0x171, SFX_UNKNOWN_133, 4352.0f * D_803F646C, 0, 1.0f);
//     func_8032CD20_73E3D0(0x10D, SFX_UNKNOWN_134, 21760.0f * D_803F646C, 0, 1.0f);
//     if (D_803F646C < 1.0) {
//         D_803F646C += 0.0160000000000000003; //D_803C0168_7D1818; -> 1 / 62.5
//     }
//     gScreenHeight = 240;
//     D_803A6CC4 = ((((s32) D_80152C78[D_803F6472] >> 7) / 3200.0) + 0.7); // D_803C0170_7D1820
//     D_803A6CC8 = ((((s32) D_80152C78[D_803F6472] >> 7) / 15.0) + 45.0); // D_803C0178_7D1828
//     D_803F6472 += 1;
//
//     D_80152EA8.vp.vscale[0] = gScreenWidth * 2;
//     D_80152EA8.vp.vscale[1] = gScreenHeight * 2;
//     D_80152EA8.vp.vtrans[0] = gScreenWidth * 2;
//     D_80152EA8.vp.vtrans[1] = gScreenHeight * 2;
//
//     func_8038CF90_79E640();
//     if (D_803B6318 == 0) {
//         draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 75);
//     } else {
//         draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 100);
//     }
//
//     switch (D_803B6318) {
//     case 0:
//         if (gScreenWidth < 320) {
//             gScreenWidth = gScreenWidth + 2;
//         }
//         func_8038D920_79EFD0(0xFF);
//         func_8038DA70_79F120();
//         D_803B6310 += 1;
//         if (D_803B6310 > 40) {
//             D_803B631C = 1;
//             D_803B6310 = 0;
//             D_803B6318 = 1;
//         }
//         break;
//     case 1:
//         gScreenWidth = 320;
//         load_default_display_list(&D_801D9E7C);
//         set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
//         select_font(0, FONT_COMIC_SANS, 1, 0);
//         func_8038D920_79EFD0(0xFF);
//         sp68 = SSSV_RAND(8);
//         for (i = 0; i < 6; i++) {
//             temp_v0_5 = (((i * 4) + i) * 8) + sp68;
//
//             gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer + (temp_v0_5 * 0x280)));
//             gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, (gScreenHeight - temp_v0_5) - 9);
//             gSPDisplayList(D_801D9E7C++, D_801D9E90);
//         }
//
//         gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
//         gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
//
//         func_8038D004_79E6B4(&D_801D9E90, D_803B6310);
//         func_8038DA70_79F120();
//         func_8038E504_79FBB4(D_803B6310);
//         load_default_display_list(&D_801D9E7C);
//         set_menu_text_color(0x80, 0xFF, 0, 0xFF);
//         select_font(0, FONT_COMIC_SANS, 1, 0);
//         func_8038DBE0_79F290(0xE, 0x10);
//         if (++D_803B6310 > 65000) {
//             D_803B6310 = 200U;
//         }
//         if ((gControllerInput->button & A_BUTTON) || (gControllerInput->button & B_BUTTON)) {
//             if (D_803B631C == 0) {
//                 func_801337DC(0, 25.0f, 0, 20.0f);
//                 D_803B6314 = 0;
//                 D_803B631C = 1;
//                 D_803B6310 = 0U;
//                 D_803F2D10.unk0 = 0;
//                 D_803F2C6C = D_803F2C6D = 0;
//                 D_803B6318 = 0;
//                 D_803F6460 = 100;
//                 D_803D6110 = 18;
//                 draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 0xFF);
//                 if (D_803F2AA2 == 4) {
//                     D_803F2AA2 = 2;
//                     D_803F6468 = 0;
//                     D_803F2AA3 = 60;
//                 } else {
//                     D_803F2AA2 = 0;
//                 }
//             }
//         }
//         break;
//     case 2:
//         func_8038D920_79EFD0(0xFF);
//         func_8038DA70_79F120();
//         if (D_803B6310 == 1) {
//             func_802F2EEC_70459C(80, 80, 80, 200, 200, 200, 10);
//         }
//         D_803B6310 += 1;
//         if ((D_803B6310) == 40) {
//             D_803B6310 = 0;
//             D_803F2AA2 = 0;
//             D_803F2D10.unk0 = 0;
//             D_803F2C6C = D_803F2C6D = 0;
//             D_803B6318 = 0;
//         }
//         break;
//     }
//
//     if (D_803B631C != 0) {
//         D_803B631C += 1;
//         if ((D_803B631C ^ 7) == 0) {
//             D_803B631C = (u8)0;
//         }
//     }
// }

void func_8038F414_7A0AC4(void) {
    switch (D_803F2AA2) {
    case 0:
        if (D_803F6460 > 0) {
            D_803F6460 -= 1;
        }
        if ((D_803F2AA3 > 0) && (--D_803F2AA3  == 0)) {
            D_803F2AA2 = 3;
            D_803B6318 = 0;
            func_8038D258_79E908();
            D_803B6310 = 0;
            D_803A6CC4 = 0.7f;
            D_803A6CC8 = 45.0f;
            D_803F6472 = 0;
            D_803F2D10.unk0 = 3;
            D_803F6474 = D_803F2D50.unkDA;
        }
        break;
    case 1:
        if (D_803F2AA3 > 0) {
            D_803F2AA3--;
        }
        if ((D_803F2AA3 <= 0) && (D_803F6468 >= 100)) {
            func_802B342C_6C4ADC();
            func_801337DC(0, 25.0f, 20.0f, 0.0f);
            D_803F2AA2 = 4;
            D_803B6318 = 1;
            func_8038D258_79E908();
            D_803B6310 = 0;
            D_803A6CC4 = 0.7f;
            D_803A6CC8 = 45.0f;
            D_803F6472 = 0;
            D_803F2D10.unk0 = 3;
            D_803F6474 = D_803F2D50.unkDA;
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
        }
        break;
    case 2:
        if ((D_803F2AA3 > 0) && (--D_803F2AA3 == 0)) {
            D_803F2AA2 = 0;
            func_802B34DC_6C4B8C();
        }
    }
}

void func_8038F5F8_7A0CA8(Animal *arg0) {
    if ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO) &&
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        if (D_803F6460 == 0) {
            D_803D6110 = 100;
            D_803F2AA2 = 1;
            D_803F6464 = arg0;
            D_803F6468 = 0;
            D_803F2AA3 = 100;
            D_803F6460 = 100;
            set_species_as_encountered(D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->unk9C);
        }
    }
}

void func_8038F694_7A0D44(void) {
    D_803F2AA2 = 0;
    D_803F2AA3 = 25;
    func_801337DC(0, 135.0f, 20.0f, 0);
    func_8013385C(135.0f, 20.0f, 0);
}
