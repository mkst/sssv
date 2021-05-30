#include <ultra64.h>

#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A6500/func_80294E50_6A6500.s")
// void func_80294E50_6A6500(void) {
//     void *spAC;
//     s32 sp38;
//     s16 temp_a3;
//
//     s16 temp_t8_2;
//     s16 temp_t9;
//     s16 temp_v0_12;
//     s32 temp_a0_3;
//     u16 temp_v0_4;
//     u8 temp_t6;
//     u8 temp_t8;
//     u8 temp_v0;
//     u8 temp_v1;
//     void *temp_a0_2;
//     Animal * temp_v0_9;
//
//     u8 phi_v0;
//     s32 phi_v0_2;
//     s16 phi_t0;
//     s16 phi_a0;
//     void *phi_a1;
//     s16 phi_v0_3;
//     s16 phi_v0_4;
//     s16 *phi_a1_2;
//     void *phi_a1_3;
//
//     D_80204278->usedModelViewMtxs = 0;
//     D_80204278->unk39310 = (u16)0;
//     D_80204278->unk38914 = 0;
//     D_8028645A = (u16)0;
//     func_8029F3CC_6B0A7C();
//
//     D_803C0648 = 0;
//     D_803C064C = 0x112038;
//     if (D_803C0422 != 0) {
//         D_803C0422++;
//         if (D_803C0422 == 2) {
//             draw_rectangle(&D_801D9E7C, 0, 0, 8, 0xF0, 0, 0, 0, 0xFF);
//             draw_rectangle(&D_801D9E7C, (gScreenWidth - 8), 0, gScreenWidth, 0xF0, 0, 0, 0, 0xFF);
//             draw_rectangle(&D_801D9E7C, 0, 0, gScreenWidth, 8, 0, 0, 0, 0xFF);
//             draw_rectangle(&D_801D9E7C, 0, (gScreenHeight - 8), gScreenWidth, 0xF0, 0, 0, 0, 0xFF);
//         }
//         if (D_803C0422 == 3) {
//             func_80137840();
//             func_8012A400();
//             func_803925D0_7A3C80(D_8020428C->unk3BBE8, &D_800C5A40);
//             D_803F6680.unk0 = (u16)1;
//             D_803F6714 = (u16)0;
//             D_803C0422 = (u8)0;
//             D_803F6680.unk26 = (u8)0;
//             D_803F6680.unk2D = (u8)0;
//             D_803F6704 = (s16) D_8020540C;
//             func_8012AC40();
//         }
//     }
//     if (D_80152E98 == (u16)1) {
//         func_8038FD74_7A1424();
//         D_80152E98 = (u8)0;
//     }
//     if ((D_803F2AA2 == 3) || (D_803F2AA2 == 4)){
//         func_8038E9F8_7A00A8();
//         return;
//     }
//
//     if ((((gControllerInput->button & START_BUTTON) != 0) && (D_802912DE == (u16)1) && (D_803F6680.unk0 == 0)) || (D_803F66A6 == 3)) {
//         if ((D_803E1BC0 == 0) && (D_803C0426 == 0) && (D_8020540C != 1) && (D_803C0422 == 0)) {
//             if ((D_803F2D34 == 0) && (D_803F2E16 == 0) && (gLevelIndex != END_CREDITS) && ((D_803E4D28 & 0x10) == 0)) {
//                 if ((D_803C0420 == 0) || ((((s32) D_803C0420 < 0xB) == 0))) {
//                     play_sound_effect(0x7F, 0, 0x5000, 1.0f, 0x40);
//                     D_801D9ED4 = (u16)0xA;
//                     func_8038F794_7A0E44();
//                 }
//             }
//         }
//     }
//
//     if ((D_803E4D28 & 0x40) != 0) {
//         func_80137840(); // initialise rumble packs?
//         func_8012A400(); // receive some messages?
//         // swap frame buffer?
//         memcpy_sssv(&D_80162658[D_80152EB8].unk3BBE8, &D_80162658[D_80152EB8 ^ 1].unk3BBE8, sizeof(gFramebuffer[0]));
//         func_8038F8C8_7A0F78();
//         D_803E4D28 = D_803E4D28 & ~0x40;
//     }
//     if (((D_803E4D28 & 0x80) != 0) && (D_803C0426 == 0) && (D_80204288 == 0xA)) {
//         D_803C0426 = 1;
//         D_803C042A = 0;
//     }
//     if (((gControllerInput->button & START_BUTTON) != 0) && (1 == D_802912DE) && (D_803C0426 == 0) && (D_80204288 == 10) && ((D_8023F2A0.unk8 & 1) == 0)) {
//         D_803C0426 = 1;
//         D_803C042A = 1;
//     }
//     if (D_803F6680.unk0 != 0) {
//         if (D_803F66AD == 0) {
//             // decompress a bunch of textures
//             func_80398630_7A9CE0();
//             D_803F66AD = (u8)1;
//         }
//         func_8038FF68_7A1618();
//     } else {
//         func_8038F414_7A0AC4();
//         D_80204290 = (u16)2;
//         if (D_803F642C == 0) {
//             D_803F2E2A = (s16) D_802053EA;
//         } else {
//             D_803F2E2A = 320;
//         }
//         gScreenWidth = D_803F2E2A;
//         gScreenHeight = 240;
//         func_802F59F0_7070A0();
//         if (gControllerInput != NULL) {
//             func_802C8FC0_6DA670(gControllerInput);
//         }
//         func_802FDA44_70F0F4();
//         func_802FE5E8_70FC98();
//         func_802F30A4_704754();
//
//         gSPDisplayList(D_801D9E88++, D_01003498);
//         gSPDisplayList(D_801D9E88++, D_01004360);
//         gSPDisplayList(D_801D9E88++, D_01003B70);
//         gSPDisplayList(D_801D9E88++, D_01003998);
//
//         gSPDisplayList(D_801D9E90++, D_01003998);
//         gDPSetColorDither(D_801D9E90++, G_CD_NOISE);
//         gDPSetAlphaDither(D_801D9E90++, G_AD_DISABLE);
//
//         func_803041FC_7158AC(&D_801D9E90);
//         func_80129300(&D_801D9E7C, D_80204278);
//         func_80380490_791B40(&D_801D9E7C, D_80204278);
//
//         gSPViewport(D_801D9E7C++, &D_80152EA8);
//
//         func_80129430(&D_801D9E7C);
//
//         gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
//         gSPDisplayList(D_801D9E7C++, D_01004270);
//
//         gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);
//
//         func_8032F950_741000();
//         func_802999E0_6AB090(D_80204278);
//         func_80299AA8_6AB158(D_80204278, &D_801D9E7C);
//         func_8029A624_6ABCD4(&D_801D9E7C);
//         func_802C87E0_6D9E90();
//         if (func_8038CCC0_79E370() != 0) {
//             D_803E4D28 = (s32) (D_803E4D28 | 0x20);
//         } else {
//             D_803E4D28 = (s32) (D_803E4D28 & ~0x20);
//         }
//         if (D_803F671C != 0) {
//             draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 2);
//             draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 2);
//             draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 2);
//             D_803F671C = (s16) (D_803F671C + 1);
//             if ((s32) D_803F671C >= 3) {
//                 D_803F671C = (u16)0;
//             }
//         }
//         func_802B3EC0_6C5570(&D_801D9E7C, ((D_803F28D0 & 0xC0) >> 6), D_803F2C3C, D_803F2C40, D_801DDD8C[gCurrentAnimalIndex].unk0->xPos, D_801DDD8C[gCurrentAnimalIndex].unk0->zPos);
//         if ((D_803C0422 == 0) && (D_803E1BC0 == 0) && (gLevelIndex != DMA_INTRO)) {
//             func_80349DCC_75B47C(1);
//         }
//
//         gSPDisplayList(D_801D9E7C++, D_80204278->unk267A0);
//         func_8029877C_6A9E2C();
//         D_803F2D68 = (u16)1;
//         temp_t8 = D_803C0430.unk20F + 1;
//         temp_t6 = temp_t8 & 7;
//         D_803C0430.unk20F = temp_t8;
//         D_803C0430.unk20F = temp_t6;
//         if ((temp_t6 & 0xFF) == 0) {
//             func_8029726C_6A891C(&D_803C0740_7D1DF0);
//             func_80296C8C_6A833C(&D_803C0740_7D1DF0);
//         }
//         func_802B4D20_6C63D0();
//         func_802FA6D8_70BD88();
//         func_80397840_7A8EF0();
//         func_802DA7F0_6EBEA0();
//         func_802D6738_6E7DE8();
//         func_802CB394_6DCA44(D_80204278);
//         // temp_t9 = gScreenWidth * 2;
//         D_80152EA8.unk0 = gScreenWidth * 2;
//         D_80152EA8.unk8 = gScreenWidth * 2;
//         // temp_t8_2 = gScreenHeight * 2;
//         D_80152EA8.unk2 = gScreenHeight * 2;
//         D_80152EA8.unkA = gScreenHeight * 2;
//         func_802DE950_6F0000(&D_80152EA8);
//         func_802C8878_6D9F28();
//         func_802E072C_6F1DDC(0);
//
//         gSPDisplayList(D_801D9E7C++, D_80204278->unk9600);
//
//         D_803C0648 = 0;
//         D_803C064C = 0x110038;
//         func_8029F7D4_6B0E84(D_80204278, &D_801E9EB8, &D_80204278);
//         func_8029A720_6ABDD0();
//         func_8029A624_6ABCD4(&D_801D9E7C);
//
//         gSPDisplayList(D_801D9E7C++, D_80204278->unkBB80);
//
//         if ((gControllerInput != NULL) && (D_801D9ED4 == 0) && (gControllerInput->button & L_TRIG)) {
//             D_801D9ED4 = 10;
//         }
//         func_8029A624_6ABCD4(&D_801D9E7C);
//         if ((D_803F2AA2 != 2) || ((s32) D_803F6468 >= 7)) {
//             func_80299B68_6AB218(D_80204278);
//         }
//         func_80297628_6A8CD8(&D_803C0740_7D1DF0, D_80204278);
//
//         gSPDisplayList(D_801D9E7C++, D_01003A58);
//         gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
//         gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
//
//         if (D_803F2D10.unk0 < 2) {
//             func_802D5AD8_6E7188(0, 1);
//         }
//         func_80299E84_6AB534(D_80204278);
//
//         gSPDisplayList(D_801D9E7C++, D_80204278->unkDAC0);
//         gSPDisplayList(D_801D9E7C++, D_80204278->unk7D00);
//         gSPDisplayList(D_801D9E7C++, D_80204278 + 0x1234); //sp38); // ?!
//
//         gDPSetColorDither(D_801D9E7C++, G_CD_NOISE);
//         gDPSetAlphaDither(D_801D9E7C++, G_AD_DISABLE);
//         gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
//         gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
//
//         if ((s32) D_803F2D10.unk0 < 2) {
//             func_802D5AD8_6E7188(1, 8);
//         }
//         gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
//         gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
//
//         func_8029BB94_6AD244();
//         func_803572F0_7689A0();
//         func_80357480_768B30();
//         func_80357438_768AE8();
//         func_8039EBFC_7B02AC();
//         func_802FF25C_71090C();
//
//         if (D_803F63C2 != 0) {
//             func_8037D32C_78E9DC(&D_803B5764, (D_803F63C2 + 1) & 0xFF, 25, (gScreenWidth - 0x19) & 0xFFFF, gScreenHeight - 0x64);
//         }
//         if (D_803C0422 == 0) {
//             if (D_803E1BC0 == 0) {
//                 if (gLevelIndex != DMA_INTRO) {
//                     func_80349DCC_75B47C(0);
//                 }
//             } else if (D_802912D8 != 0) {
//                 load_default_display_list(&D_801D9E7C);
//                 set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // yellow
//                 select_font(0, 2, 1, 0);
//                 func_8012EB4C(&D_801D9E7C, &D_80204368, ((s32) gScreenWidth / 2) & 0xFFFF, 0xC8, 16.0f, 16.0f, 0x10);
//             }
//         }
//
//         gDPPipeSync(D_801D9E7C++);
//         gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0x00);
//         gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//         gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
//         gDPFillRectangle(D_801D9E7C++, 23, 186, 117, 221);
//
//         func_80299140_6AA7F0();
//
//         gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
//
//         if (D_803C0420[0] != 0) {
//             if (D_803C0420[0] == 1) {
//                 func_803497DC_75AE8C();
//                 func_80349720_75ADD0();
//             }
//             D_803C0420[0] = D_803C0420[0] + 1;
//             D_803C0420[0] = D_803C0420[0] & 0x7F;
//         }
//         if (D_803F66A7 != 0) {
//             func_803800F0_7917A0((u8)D_803F2D70, &D_803C0420);
//             func_8031B174_72C824((u8)D_803F2D70, D_803F2DA3);
//             func_80352310_7639C0();
//             D_803F66A7 = (u8)0;
//             D_803F66AD = (u8)0;
//             if (D_803F6704 != 0) {
//                 func_8012ABF0();
//             }
//         }
//         if (D_8028645A == 0) {
//             D_8015517C = 0.0f;
//         }
//         if ((D_8028645C == 9) || (D_8028645C == 5) || (D_8028645C == 24)) {
//             D_8015517C = 1.0f;
//             D_801546D8 = (u16)0x800;
//         }
//         temp_v0_12 = D_803C0426;
//         phi_a1_3 = &D_803C0426;
//         if (temp_v0_12 != 0) {
//             phi_v0_3 = temp_v0_12;
//             if (temp_v0_12 == 2) {
//                 func_80133738();
//                 phi_v0_3 = D_803C0426;
//             }
//             if (phi_v0_3 == 1) {
//                 phi_a1_2 = &D_803C0426;
//                 if (D_803C042A == 0) {
//                     func_802F07D0_701E80();
//                     func_802F07E8_701E98(3);
//                     phi_v0_4 = D_803C042A;
//                     phi_a1_2 = &D_803C0426;
//                 }
//                 if (D_803C042A == 1) {
//                     *phi_a1_2 = (u16)0xD;
//                 }
//                 D_8028645C = (u16)0;
//                 *phi_a1_2 = (s16) (*phi_a1_2 + 1);
//                 phi_a1_3 = phi_a1_2;
//             } else {
//                 D_803C0426 = (s16) (phi_v0_3 + 1);
//                 phi_a1_3 = &D_803C0426;
//                 if ((s32) D_803C0426 >= 0x11) {
//                     D_80204284 = (u16)3;
//                     D_80152E90 = (u8)1;
//                     phi_a1_3 = &D_803C0426;
//                 }
//             }
//         }
//         if (D_803E1BC0 == 2) {
//             if (D_803C0424 == 0) {
//                 func_8013385C(8.0f, 20.0f, 0);
//                 func_801337DC(0, 8.0f, 20.0f, 0);
//                 func_802F07E8_701E98(3);
//                 D_803C0424 = (u16)1;
//             } else {
//                 D_803C0424 = (s16) (D_803C0424 + 1);
//                 if ((s32) D_803C0424 >= 0xE) {
//                     D_80204284 = (u16)3;
//                     D_80152E90 = (u8)1;
//                     D_8028645C = (u16)0;
//                 }
//             }
//         }
//         func_801375E8(0);
//     }
//
//     check_cheats(gControllerInput);
//     func_802F0918_701FC8();
//     if (D_803C0426 != 0) {
//         if (D_803C042A == 1) {
//             draw_rectangle(&D_801D9E7C, 0, 0, 0x140, 0xF0, 0, 0, 0, 0xFF);
//         }
//     }
//     if ((gLevelIndex == END_CREDITS) && (D_803F6680.unk0 == 0)) {
//         if (D_803C0428 != 0) {
//             D_803C0428 = (s16) (D_803C0428 + 1);
//             if ((s32) D_803C0428 >= 20) {
//                 D_8028645C = (u16)0;
//                 D_80204284 = (u16)3;
//                 D_80152E90 = (u8)1;
//             }
//         } else {
//             if (display_credits() == 1) {
//                 D_803C0428 = (u16)1;
//                 func_8013385C(6.0f, 20.0f, 0);
//                 func_801337DC(0, 6.0f, 20.0f, 0);
//                 func_802F07E8_701E98(3);
//             }
//         }
//     }
//     D_801552B4 = (u8)0;
//     D_801552B0 = (u8)0;
// }

void func_8029614C_6A77FC(void) {
    D_803F2D30.unkA = 3;
    D_803F2D30.unk4 = 0;

    D_803F2D10.unk0 = 0;
    D_803F2D10.unk1 = 0;
    D_803F2D10.unk2 = 0;
    D_803F2D10.unk3 = 0;

    D_803F2D50.unkC6 = 0;
    D_803F2D50.unkC4 = 1;

    D_8020427C = 0;

    D_803F2D30.unkC = 0;
}

void func_8029619C_6A784C(void) {
    D_801DDD8C[gCurrentAnimalIndex].unk0->health = 0x7F;
    D_803F2CE8 = 0;
    D_8020427C = 1;
}

void func_802961D4_6A7884(void) {
    func_8012A400();
    func_80352280_763930();
    func_80352310_7639C0();
    D_803C0422 = 0;
    D_803F6684 = 0;
    D_8028645A = 0;
    D_8015517C = 0.0f;
    D_8028645C = 0;
    D_803F2D50.unkDA = 320;
    D_803F2D50.unkDC = 0;
    // these 3 are 64bit
    D_803C0640 = 0xFFFFFFFFC8000000; // rendermode mask?
    D_803C0648 = 0x0000000000112038;
    D_803C0650 = 0x0000000000010000;
    func_802C9340_6DA9F0();
    func_802C9834_6DAEE4();
    func_80296544_6A7BF4();
    func_802CB360_6DCA10();
    func_80304170_715820();
    func_80304194_715844(); // zero out something
    load_level(gLevelIndex);
    D_80204280 = D_803F2D30.unk8;
    D_803F2D30.unk4 = 0;
    func_80296310_6A79C0();
    func_802B3FAC_6C565C();
    D_803F2D50.unkCE = get_evo_suit_color();
    D_803F2D50.unkDC = 1;
    func_8012AC40();
    D_803E4D2C = 0;
}

void func_80296310_6A79C0(void) {
    D_803C0420[0] = 1;
}

s32 get_evo_suit_color(void) {
    s16 powercells;
    s16 i;
    s32 color;
    u8* e = (u8*)&D_8023F260;
    powercells = 0;

    for (i = 1; i < 32; i++) {
        if ((i != GIVE_A_DOG_A_BONUS) &&
            (i != WALRACE_64) &&
            (i != EVOS_ESCAPE) &&
            (i != PUNCHUP_PYRAMID) &&
            (i != BIG_CELEBRATION_PARADE)) {
                powercells += (u32)e[i + 3] >> 4;
            }
    }
    if (powercells < 200) {
        color = EVO_BRONZE_SHELLSUIT;
    } else if (powercells < 390) {
        color = EVO_SILVER_SHELLSUIT;
    } else {
        color = EVO_GOLD_SHELLSUIT;
    }

    return color;
}
