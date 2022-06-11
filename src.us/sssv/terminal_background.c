#include <ultra64.h>

#include "common.h"

// tbd
u8 func_8038E80C_79FEBC(void);

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

#if 0
// animal stats (message ids)
struct107 D_803B58E0_7C6F90[68] = {
    { 125,  53,  88, 118, 198, 205, 211 }, // seagull, low, flight, claw attack, kerosene, excellent, little lift
    { 126,  57,  76,  77, 195, 206, 210 },
    { 127,  53,  78,  79, 196, 206, 210 },
    { 128,  53,  98,  98, 201, 206, 210 },
    { 129,  53,  80,  81, 193, 206,  56 },
    { 130,  88,  88,  83, 198,  66,  56 },
    { 131,  60,  99,  94, 202, 206,  56 },
    { 132,  60,  80,  81, 200, 206,  56 },
    { 133,  56,  76,  86, 203, 205,  56 },
    { 134,  56, 109, 101,  98, 206, 210 },
    { 135,  56,  76,  87, 203, 206,  56 },
    { 136,  56,  88,  82, 198, 206,  56 },
    { 137,  53,  80,  76, 196, 205, 209 },
    { 138,  60,  90,  91, 201, 206,  56 },
    { 139,  56,  88,  92, 204, 205, 209 },
    { 140,  56,  88,  92, 204, 205, 209 },
    { 141,  57,  76,  93, 202,  66, 209 },
    { 142,  57,  80,  94, 194,  66, 209 },
    { 143,  57,  80,  94, 194,  66, 209 },
    { 144,  56,  88,  95, 198, 205, 211 },
    { 145,  57,  76,  93, 202,  66, 209 },
    { 146,  57,  98,  98, 198,  66, 209 },
    { 147,  53,  95,  96, 196,  66, 212 },
    { 148,  53,  95,  96, 196,  66, 210 },
    { 149,  53,  98,  98, 197,  66, 210 },
    { 150,  53,  88, 118, 198, 205, 211 },
    { 151,  60,  99,  94, 193, 206,  56 },
    { 152,  57, 100, 101, 201, 206, 210 },
    { 153,  57,  80, 102, 193, 206,  56 },
    { 154,  57, 100, 101,  98, 206, 210 },
    { 155,  53,  76,  84, 197, 205,  56 },
    { 156,  53,  76,  84, 202, 205,  56 },
    { 157,  57, 103,  84, 201, 205, 209 },
    { 158,  50, 104, 105, 204, 206, 209 },
    { 159,  53,  76, 106, 202, 206,  56 },
    { 160,  50,  76, 105, 203, 206, 209 },
    { 161,  53,  76, 106, 203, 206,  56 },
    { 162,  56,  76, 108, 202, 205, 209 },
    { 163,  50, 109, 101, 197, 205, 210 },
    { 164,  50, 100, 112, 197, 205, 210 },
    { 165,  56,  76, 113, 202, 206,  56 },
    { 166,  53,  76, 113, 202, 206,  56 },
    { 167,  56,  80,  81, 202,  66,  56 },
    { 168,  57,  88,  82, 198, 206, 209 },
    { 169,  57,  80, 114, 196, 205, 210 },
    { 170,  56,  88,  95, 198, 205, 211 },
    { 171,  57,  76,  89, 204, 206, 210 },
    { 172,  57, 100, 115, 197, 206, 210 },
    { 173,  57,  98,  98, 204, 206, 209 },
    { 174,  56,  76, 116, 203, 206,  56 },
    { 175,  56,  76, 117, 195, 206,  56 },
    { 176,  57,  76, 124, 202,  66, 209 },
    { 177,  57,  76, 100, 202,  66, 209 },
    { 178,  60, 118, 119, 195, 208,  56 },
    { 179,  50, 109,  95, 196, 206, 212 },
    { 180,  57,  76, 124, 195,  66,  56 },
    { 181,  57, 120,  95, 201, 206, 210 },
    { 182,  57,  76, 121, 202, 206,  56 },
    { 183,  57,  80,  81, 194, 206,  56 },
    { 184,  56,  86, 122, 197,  66, 209 },
    { 185,  56,  86, 122, 197,  66, 209 },
    { 186,  60,  98,  98, 202, 206, 209 },
    { 187,  60,  98,  98, 202, 206, 209 },
    { 188,  60,  98,  98, 202, 206, 209 },
    { 189,  57, 107, 123, 199, 205,  56 },
    { 190,  57,  80, 102, 197, 206,  56 },
    { 191,  56,  76,  80, 199, 205, 209 },
    { 192,  56,  88,  98, 202, 206, 210 },
};
#endif

void func_8038CF90_79E640(void) {
    gSPDisplayList(D_801D9E7C++, D_01004270);
    gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
}

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

extern s16 *D_803B6560_7C7C10[11];
extern char D_803BFFD8_7D1688[];
extern char D_803BFFDC_7D168C[];

// load animal stats
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038D258_79E908.s")
// void func_8038D258_79E908(void) {
//     s32 pad;
//     s16 i;
//     s16 wide[64];
//     u8 ascii[54];
//
//     // pre-fill with empty messages
//     for (i = 0; i < 17; i++) {
//         if (D_803B6560_7C7C10[i] == 0) {
//             get_message_address_by_id(0xD5); // ""
//         }
//     }
//
//     D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
//     D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
//
//     D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//     D_803D552C = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//     D_803D5530 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
//
//     goto dummy_label_714037;dummy_label_714037: ;
//     if (pad = D_803D5528 == NULL) {};
//
//     D_803D5538 = 1;
//     D_803D553C = gCurrentAnimalIndex;
//     D_803D553A = 0;
//
//     D_803F6500[0] = get_message_address_by_id(0x1F);  // type
//     D_803F6500[1] = get_message_address_by_id(0x2E);  // environment
//     D_803F6500[2] = get_message_address_by_id(0x29);  // skill A
//     D_803F6500[3] = get_message_address_by_id(0x2A);  // skill B
//     D_803F6500[4] = get_message_address_by_id(0x21);  // water resistance
//     D_803F6500[5] = get_message_address_by_id(0x24);  // mass
//     D_803F6500[6] = get_message_address_by_id(0x26);  // armour
//     D_803F6500[7] = get_message_address_by_id(0x25);  // strength
//     D_803F6500[8] = get_message_address_by_id(0x23);  // traction
//     D_803F6500[9] = get_message_address_by_id(0x28);  // fall distance
//     D_803F6500[10] = get_message_address_by_id(0x2C); // production
//     D_803F6500[11] = get_message_address_by_id(0x20); // engine
//     D_803F6500[12] = get_message_address_by_id(0x2D); // intelligence
//     D_803F6500[13] = get_message_address_by_id(0xD5); // ""
//     D_803F6500[14] = get_message_address_by_id(0xD5); // ""
//     D_803F6500[15] = get_message_address_by_id(0xD5); // ""
//     D_803F6500[16] = get_message_address_by_id(0xD5); // ""
//
//     D_803B6560_7C7C10[0] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk0);
//     D_803B6560_7C7C10[11] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk8);
//     D_803B6560_7C7C10[4] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unkA);
//     D_803B6560_7C7C10[7] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unkC);
//     D_803B6560_7C7C10[12] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk2);
//     D_803B6560_7C7C10[2] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk4);
//     D_803B6560_7C7C10[3] = get_message_address_by_id(D_803B58E0_7C6F90[D_803D5524->unk9C].unk6);
//
//     switch (D_803D5524->biome) {
//     case EUROPE_BIOME:
//         D_803B6560_7C7C10[1] = get_message_address_by_id(0x46); // europe
//         break;
//     case ICE_BIOME:
//         D_803B6560_7C7C10[1] = get_message_address_by_id(0x49); // ice
//         break;
//     case DESERT_BIOME:
//         D_803B6560_7C7C10[1] = get_message_address_by_id(0x48); // desert
//         break;
//     case JUNGLE_BIOME:
//         D_803B6560_7C7C10[1] = get_message_address_by_id(0x47); // jungle
//         break;
//     }
//
//     switch (D_803D5524->mass) {
//     case 0x14:
//         D_803B6560_7C7C10[5] = get_message_address_by_id(0x34);     // tiny
//         D_803B6560_7C7C10[10] = get_message_address_by_id(0x33);    // very short
//         break;
//     case 0x28:
//         D_803B6560_7C7C10[5] = get_message_address_by_id(0x37);     // light
//         D_803B6560_7C7C10[10] = get_message_address_by_id(0x36);    // short
//         break;
//     case 0x3C:
//         D_803B6560_7C7C10[5] = get_message_address_by_id(0x38);     // medium
//         D_803B6560_7C7C10[10] = get_message_address_by_id(0x38);    // medium
//         break;
//     case 0x50:
//         D_803B6560_7C7C10[5] = get_message_address_by_id(0x3B);     // heavy
//         D_803B6560_7C7C10[10] = get_message_address_by_id(0x3A);    // long
//         break;
//     case 0x64:
//         D_803B6560_7C7C10[5] = get_message_address_by_id(0x3E);     // huge
//         D_803B6560_7C7C10[10] = get_message_address_by_id(0x3D);    // very long
//         break;
//     }
//
//     if (D_803D5524->fallDistance < 0x14) {
//         D_803B6560_7C7C10[9] = get_message_address_by_id(0x32);   // very low
//     } else if (D_803D5524->fallDistance < 0x32) {
//         D_803B6560_7C7C10[9] = get_message_address_by_id(0x35);   // low
//     } else if (D_803D5524->fallDistance < 0xA0) {
//         D_803B6560_7C7C10[9] = get_message_address_by_id(0x38);   // medium
//     } else if (D_803D5524->fallDistance < 0x1F4) {
//         D_803B6560_7C7C10[9] = get_message_address_by_id(0x39);   // high
//     } else {
//         D_803B6560_7C7C10[9] = get_message_address_by_id(0x3C);   // very high
//     }
//
//     switch (D_803D5524->armour) {
//     case 4:
//         D_803B6560_7C7C10[6] = get_message_address_by_id(0x37); // light
//         break;
//     case 8:
//         D_803B6560_7C7C10[6] = get_message_address_by_id(0x38); // medium
//         break;
//     case 16:
//         D_803B6560_7C7C10[6] = get_message_address_by_id(0x3F); // tough
//         break;
//     case 255:
//         D_803B6560_7C7C10[6] = get_message_address_by_id(0x40); // invincible
//         break;
//     }
//
//     if (D_803D5524->traction < 0xA) {
//         D_803B6560_7C7C10[8] = get_message_address_by_id(0x41); // very poor
//     } else if (D_803D5524->traction < 0x13) {
//         D_803B6560_7C7C10[8] = get_message_address_by_id(0x42); // poor
//     } else if (D_803D5524->traction < 0x28) {
//         D_803B6560_7C7C10[8] = get_message_address_by_id(0x43); // average
//     } else if (D_803D5524->traction < 0x46) {
//         D_803B6560_7C7C10[8] = get_message_address_by_id(0x44); // good
//     } else {
//         D_803B6560_7C7C10[8] = get_message_address_by_id(0x45); // very good
//     }
//
//     select_font(0, FONT_COMIC_SANS, 1, 0);
//     // "%s", " "
//     sprintf((char*)ascii, D_803BFFD8_7D1688, D_803BFFDC_7D168C);
//     prepare_text(ascii, wide);
//     func_8012D374(&D_801D9E7C, wide, 25, 0, 14.0f, 16.0f, 0);
//
//     for (i = 0; i < 13; i++) {
//         D_803F6548[i] = (gScreenWidth - func_8012C3D8(D_803B6560_7C7C10[i])) - 14;
//     }
//
//     for (i = 0; i < 13; i++) {
//         D_803F6478.unk0[i] = 0;
//         D_803F6478.unk34[i] = 0;
//         D_803F6478.unk68[i] = 0;
//         // huh?
//         D_803F6478.unk82 = 0;
//         D_803F6478.unk84 = 0;
//         D_803F6478.unk86 = 0;
//     }
// }

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
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

    gSPDisplayList(D_801D9E7C++, D_01004270);
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

// spin_dna_helixes
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038DF18_79F5C8.s")
// void func_8038DF18_79F5C8(u16 arg0) {
//     s32 sp9C;
//     Light *sp98;
//     Light *sp94;
//     s32 sp90;
//     Light *sp8C;
//     Light *sp88;
//     s32 sp84;
//     Light *sp80;
//     Light *sp7C;
//     s32 sp78;
//     s32 sp74;
//
//     f32 temp_f0_2;
//     f64 temp_f22;
//
//     // static f32 D_803F6670;
//
//     f32 phi_f12;
//     s16 i;
//     f32 phi_f2;
//     s16 phi_v1;
//
//     // temp_f22 = 5600.0; //D_803C0128_7D17D8;
//     phi_f12 = D_803F6670 + 10.0;
//     // phi_f12 = temp_f12;
//
//     if (5600.0 < phi_f12) {
//         phi_f12 = phi_f12 - 5600.0;
//     }
//     D_803F6670 = phi_f12;
//
//     sp9C = func_8038E80C_79FEBC() * 8;
//     sp98 = &D_803B65E0_7C7C90;
//     sp94 = &D_803B65D8_7C7C88;
//     sp88 = &D_803B65F0_7C7CA0;
//     sp8C = &D_803B65F8_7C7CA8;
//     sp90 = D_0103B880;
//     sp84 = D_0103BA70;
//     sp80 = &D_803B65B0_7C7C60;
//     sp74 = arg0 * 4;
//     sp7C = &D_803B65A8_7C7C58;
//     sp78 = D_0103EC20;
//     // temp_f20 = D_803C0138_7D17E8;
//
//     for (i = 0; i < 16; i++) {
//         // D_803C0130_7D17E0
//         temp_f0_2 = (((i - 8) * 350.0) - D_803F6670);
//         while (temp_f0_2 < -2800.0) {
//             temp_f0_2 += 5600.0;
//         }
//
//         // translate around Z
//         guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, temp_f0_2);
//         gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//         guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803F6570[(i * 16) + sp9C], 0, 0, 1.0f);
//         gSPMatrix(D_801D9E88++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//
//         gSPNumLights(D_801D9E88++, 1);
//         gSPLight(D_801D9E88++, sp98, 1);
//         gSPLight(D_801D9E88++, sp94, 2);
//         gSPDisplayList(D_801D9E88++, sp90);
//
//         gSPNumLights(D_801D9E88++, 1);
//         gSPLight(D_801D9E88++, sp8C, 1);
//         gSPLight(D_801D9E88++, sp88, 2);
//         gSPDisplayList(D_801D9E88++, sp84);
//
//         gSPNumLights(D_801D9E88++, 1);
//         gSPLight(D_801D9E88++, sp80, 1);
//         gSPLight(D_801D9E88++, sp7C, 2);
//         gSPDisplayList(D_801D9E88++, sp78);
//
//         if (sp74 >= 0x100) {
//             phi_v1 = 0xFF;
//         } else {
//             phi_v1 = sp74; // sp78?
//         }
//
//         // temp_t9 = (phi_v1 * 0x32) >> 8;
//         D_803B65D8_7C7C88.unk1 = D_803B65D8_7C7C88.unk5 = (phi_v1 * 0x32) >> 8;;
//         D_803B65F0_7C7CA0.unk1 = D_803B65F0_7C7CA0.unk5 = (phi_v1 * 0x32) >> 8;;
//         // temp_t8 = (phi_v1 * 0x19) >> 8;
//         D_803B65D8_7C7C88.unk0 = D_803B65D8_7C7C88.unk4 = (phi_v1 * 0x19) >> 8;;
//         // temp_t6 = (phi_v1 * 0x64) >> 8;
//         D_803B65D8_7C7C88.unk8 = D_803B65D8_7C7C88.unkC = (phi_v1 * 0x64) >> 8;;
//         D_803B65F0_7C7CA0.unk8 = D_803B65F0_7C7CA0.unkC = (phi_v1 * 0x4B) >> 8;
//         // temp_t7 = (phi_v1 * 0x96) >> 8;
//         D_803B65D8_7C7C88.unk9 = D_803B65D8_7C7C88.unkD = (phi_v1 * 0x96) >> 8;
//         D_803B65F0_7C7CA0.unk9 = D_803B65F0_7C7CA0.unkD = (phi_v1 * 0x96) >> 8;
//         D_803B65F0_7C7CA0.unk0 = D_803B65F0_7C7CA0.unk4 = (phi_v1 * 0x14) >> 8;
//         D_803B65D8_7C7C88.unk2 = D_803B65D8_7C7C88.unk6 = 0;
//         D_803B65D8_7C7C88.unkA = D_803B65D8_7C7C88.unkE = 0;
//         D_803B65F0_7C7CA0.unk2 = D_803B65F0_7C7CA0.unk6 = 0;
//         D_803B65F0_7C7CA0.unkA = D_803B65F0_7C7CA0.unkE = 0;
//         D_803B65A8_7C7C58.unk0 = D_803B65A8_7C7C58.unk4 = 0;
//         D_803B65A8_7C7C58.unk1 = D_803B65A8_7C7C58.unk5 = (phi_v1 * 0xA) >> 8;
//         D_803B65A8_7C7C58.unk2 = D_803B65A8_7C7C58.unk6 = 0;
//         D_803B65A8_7C7C58.unk8 = D_803B65A8_7C7C58.unkC = 0;
//         D_803B65A8_7C7C58.unk9 = D_803B65A8_7C7C58.unkD = (phi_v1 * 0x64) >> 8;;
//         D_803B65A8_7C7C58.unkA = D_803B65A8_7C7C58.unkE = 0;
//
//         gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E504_79FBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E80C_79FEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E9F8_7A00A8.s")
// NON-MATCHING: a fair bit to do
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
//     gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
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
//     func_8032CD20_73E3D0(0xA9, SFX_UNKNOWN_133, 4352.0f * D_803F646C, 0, D_803C0160);
//     func_8032CD20_73E3D0(0x171, SFX_UNKNOWN_133, 4352.0f * D_803F646C, 0, 1.0f);
//     func_8032CD20_73E3D0(0x10D, SFX_UNKNOWN_134, 21760.0f * D_803F646C, 0, 1.0f);
//     if (D_803F646C < 1.0) {
//         D_803F646C += D_803C0168;
//     }
//     gScreenHeight = 240;
//     D_803A6CC4 = (((f64) ((s32) D_80152C78[D_803F6472] >> 7) / 3200.0) + D_803C0170_7D1820);
//     D_803A6CC8 = (((f64) ((s32) D_80152C78[D_803F6472] >> 7) / 15.0) + D_803C0178);
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
//             gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8 + (temp_v0_5 * 0x280)));
//             gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, (gScreenHeight - temp_v0_5) - 9);
//             gSPDisplayList(D_801D9E7C++, D_801D9E90);
//         }
//
//         gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
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
            D_803A6CC4 = D_803C0180; // 0.7f
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
            D_803A6CC4 = D_803C0184; // 0.7f
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
    if ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->unk0 != OB_TYPE_ANIMAL_OFFSET+EVO) &&
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->unk0 != OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
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
