#include <ultra64.h>
#include "common.h"

void func_803458B8_756F68(Gfx **arg0, Vtx *vtx, s16 num);
void func_803458FC_756FAC(Gfx **dl, struct117 *arg1, s16 numTris);
void func_80346BB4_758264(Gfx **arg0, struct115* arg1, s16 numTris);

typedef struct {
  u8 unk148[1][0xc]; // (sp + (spF8C * 0x24))->unk148 = spFC6;
  u8 unkF58[4];
  u8 unkF60[4];
  s8 unkF64[4];
} foobar;

typedef struct {
    s32 unk4;
    s32 unkC;
    s32 unk1C;
} foobar2;

#if 0
void func_80344240_7558F0(void) {
    s16 spFC6;
    s16 spFC2;
    s16 spFC0;
    s16 spFB4;
    s16 spFB2;
    s16 spFB0;
    s16 spFAE;
    s16 spFAC;
    s16 spFAA;
    s16 spFA8;
    s16 spFA6;
    s16 spFA4;
    s16 spFA2;
    s16 spFA0;
    s16 spF9E;
    s16 spF9C;
    s16 spF98;
    s16 spF94;
    s16 spF92;
    s16 spF90;
    s16 spF8E;
    s16 spF8C;
    s16 spF88;
    s16 spF7A;
    s16 spF72;
    s16 spF70;
    s16 spF6E;
    s16 spF6C;

    u8  spF67;
    u8  spF66;
    u8  spF65;
    u8  spF64;
    u8  spF62;
    u8  spF63;
    u8  spF61;
    u8  spF60;

    u16 spF58[4];

    struct102_payload sp850[50][3]; // (0xF58 - 0x850) / 0x24 ==> 50

    u8  pad[0x660];

    s32 sp148;
    s8 sp147;
    s8 sp146;
    s8 sp145;
    Gfx *sp13C;
    Gfx *sp138;
    // s32 sp60;
    s32 sp58;
    struct102 *sp54;
    s32 sp48;
    struct102_payload *sp44;
    s32 sp40;

    foobar sp;

    Gfx *temp_t9;

    Vtx *temp_a1_4;
    Vtx *temp_a1_7;
    Vtx *temp_v0_3;
    s16 temp_a0_5;
    s16 temp_a0_6;
    s16 temp_a1_3;
    s16 temp_a1_6;
    s16 temp_a2;
    s16 temp_a2_3;
    s16 temp_a2_4;
    s16 temp_a2_5;
    s16 temp_a2_6;
    s16 temp_a3_2;
    s16 temp_t0_2;
    s16 temp_t0_3;
    s16 temp_t1;
    s16 temp_t1_2;
    // s16 temp_t5;
    s16 temp_t6_10;
    s16 temp_t8_15;
    s16 temp_v0_5;
    s16 var_a3;
    s16 i;
    s16 var_s0;
    s16 var_s3;
    s16 var_v1_10;
    struct102 *temp_a0_3;
    struct102 *temp_a1_2;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s8 temp_t2;
    s8 temp_t3;
    s8 temp_t4;
    u16 temp_v1;
    u8 temp_t5_2;
    u8 var_v1;

    struct102 *temp_v0_2;
    struct102 *temp_v0_6;
    Vtx *temp_v0_7;
    foobar2 *temp_v1_3;
    foobar2 *temp_v1_4;
    struct102 *var_v0;

    D_803F2C80 = (struct102*)&D_80100000;
    D_803C0648_7D1CF8 = 0x110038;
    // D_803C064C = 0x110038;
    // D_803F2CC0 = 0;
    D_803F2CC0 = 0x1049D8;

    D_803F2CA6 = 0;
    D_803F2C99 = 0;
    D_803F2C9A = 0;
    D_803F2C9B = 0;
    D_803E4AC8 = 0;

    spFC6 = 0;
    var_s3 = 0;
    spF98 = 0;
    spF94 = 0;
    spF92 = 0;
    spF8E = 0;
    spF90 = 0;
    spF8C = 0;
    // D_80225650.unk4 = 0xFFFE793C;
    // D_80225650.unk0 = 0xFCFFFFFF;
    // D_80225650 = 0xFCFFFFFFFFFE793C
    sp13C = &D_80205470;
    sp138 = &D_80225658;

    gDPSetCombineMode(D_80225650, G_CC_SHADE, G_CC_SHADE);

    for (D_803F2CA4 = 0; D_803F2CA4 < 6; D_803F2CA4++) {
        for (D_803F2CA2 = 0; D_803F2CA2 < 4; D_803F2CA2++) {
            D_803F2C8C = 0;
            D_803F2C8E = 0;
            D_803F2C90 = 0;

            // temp_t5 = D_803F2CA4;
            // (*D_803F2CA8)[(D_803F2CA2 * 6) + temp_t5] = 0;
            D_803F2CA8[D_803F2CA2][D_803F2CA4] = 0;

            D_803F2C86 = 1;
            D_803F2C88 = 1;
            D_803F2C8A = 1;

            spFB2 = -30000;
            D_803F2C84 = 1000;
            spFAE = -30000;
            spFAA = 30000;
            spF9C = 30000;
            D_803F2C96 = 0xFF;
            spFB0 = -30000;
            spFAC = 30000;
            spFA2 = -30000;
            D_803F2C98 = 0xFF;
            spFA8 = 30000;
            spFA4 = -30000;
            spFA0 = 30000;
            D_803F2C97 = 0xFF;
            spFA6 = -30000;
            spF9E = 30000;

            // temp_v0 = temp_t5 * 4;
            // *(D_80205410 + ((D_803F2CA2 * 0x18) + temp_v0)) = sp13C;
            D_80205410[D_803F2CA2][D_803F2CA4] = sp13C;
            // temp_t9 = sp13C;
            // *(D_802255F0 + ((D_803F2CA2 * 0x18) + temp_v0)) = sp138;
            D_802255F0[D_803F2CA2][D_803F2CA4] = sp138;

            // sp13C = temp_t9 + 8;
            // temp_t9->words.w1 = -1U;
            // temp_t9->words.w0 = 0xB6000000;
            gSPClearGeometryMode(sp13C++, -1U); // help

            // temp_a0 = sp13C;
            // sp13C = temp_a0 + 8;
            // temp_a0->words.w0 = 0x0400207F;
            // temp_a0->words.w1 = (s32) (((s16) ((D_803F2CA2 * 8) + (D_803F2CA4 << 5)) * 0x10) + &D_80224870) & 0x1FFFFFFF;

            gSPVertex(sp13C++, (s32) ((s32)&D_80224870[(s16) ((D_803F2CA2 << 3) + (D_803F2CA4 << 5))] & 0x1FFFFFFF), 8, 0);

            // temp_t6 = sp13C;
            // temp_t8 = temp_t6 + 8;
            // sp13C = temp_t8;
            // temp_t6->words.w1 = 0xE;
            // temp_t6->words.w0 = 0xBE000000;
            gSPCullDisplayList(sp13C++, 0, 7);
            // var_t8 = temp_t8;
            if (D_803F2DAC[D_803F2CA2][D_803F2CA4] == 0) {
                gSPSetGeometryMode(sp13C++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_CLIPPING);
            } else {
                gSPSetGeometryMode(sp13C++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG |              G_SHADING_SMOOTH | G_CLIPPING);
            }
            // var_t8->words.w1 = var_t6;

            // temp_t8_2 = sp13C;
            // sp13C = temp_t8_2 + 8;
            // temp_t8_2->words.w0 = 0xBB002801;
            // temp_t8_2->words.w1 = 0x80008000;
            gSPTexture(sp13C++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
            // temp_t8_3 = sp138;
            // sp138 = temp_t8_3 + 8;
            // temp_t8_3->unk0 = (Gfx *)0xB6000000;
            // temp_t8_3->unk4 = 0x20000;
            gSPClearGeometryMode(sp138++, G_LIGHTING);
            // temp_a0_2 = sp138;
            temp_a2 = (D_803F2CA2 * 8) + (D_803F2CA4 << 5);
            // sp138 = temp_a0_2 + 8;
            // temp_a0_2->unk0 = (Gfx *)0x0400207F;
            // temp_a0_2->unk4 = (s32) ((s32) ((temp_a2 * 0x10) + &D_8022D350) & 0x1FFFFFFF);
            gSPVertex(sp138++, (s32)&D_8022D350[temp_a2] & 0x1FFFFFFF, 8, 0);
            // temp_t9_2 = sp138;
            // sp138 = temp_t9_2 + 8;
            // temp_t9_2->unk4 = 0xE;
            // temp_t9_2->unk0 = (Gfx *)0xBE000000;
            gSPCullDisplayList(sp138++, 0, 7);
            // temp_t9_3 = sp138;
            // sp138 = temp_t9_3 + 8;
            // temp_t9_3->unk0 = (Gfx *)0xBA001701;
            spF88 = temp_a2;
            // temp_t9_3->unk4 = 0;
            gDPPipelineMode(sp138++, G_PM_NPRIMITIVE);
            // temp_t8_4 = sp138;
            // sp138 = temp_t8_4 + 8;
            // temp_t8_4->unk4 = 0x80008000;
            // temp_t8_4->unk0 = (Gfx *)0xBB002801;
            gSPTexture(sp138++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
            // temp_t8_5 = sp138;
            // sp138 = temp_t8_5 + 8;
            // temp_t8_5->unk4 = 0x7C07CU;
            // temp_t8_5->unk0 = (Gfx *)0xF2000000;
            gDPSetTileSize(sp138++, G_TX_RENDERTILE, 0, 0, 124, 124);
            // temp_t7 = sp138;
            // sp138 = temp_t7 + 8;
            // temp_t7->unk4 = 0;
            // temp_t7->unk0 = (Gfx *)0xB9000002;
            gDPSetAlphaCompare(sp138++, G_AC_NONE);
            // temp_t9_4 = sp138;
            // sp138 = temp_t9_4 + 8;
            // temp_t9_4->unk4 = 0x7C07CU;
            // temp_t9_4->unk0 = (Gfx *)0xF2000000;
            gDPSetTileSize(sp138++, G_TX_RENDERTILE, 0, 0, 124, 124);
            // temp_t6_2 = sp138;
            // sp138 = temp_t6_2 + 8;
            // temp_t6_2->unk4 = 0x0103C03C;
            // temp_t6_2->unk0 = (Gfx *)0xF2000000;
            gDPSetTileSize(sp138++, 1, 0, 0, 60, 60);
            // temp_t7_2 = sp138;
            // sp138 = temp_t7_2 + 8;
            // temp_t7_2->unk4 = 0x0201C01C;
            // temp_t7_2->unk0 = (Gfx *)0xF2000000;
            gDPSetTileSize(sp138++, 2, 0, 0, 28, 28);
            // temp_t9_5 = sp138;
            // sp138 = temp_t9_5 + 8;
            // temp_t9_5->unk4 = 0x0507C07C;
            // temp_t9_5->unk0 = (Gfx *)0xF2000000;
            gDPSetTileSize(sp138++, 5, 0, 0, 124, 124);
            // temp_t8_6 = sp138;
            // sp138 = temp_t8_6 + 8;
            // temp_t8_6->unk4 = 0x0607C07C;
            // temp_t8_6->unk0 = (Gfx *)0xF2000000;
            gDPSetTileSize(sp138++, 6, 0, 0, 124, 124);
            // temp_t6_3 = sp138;
            // sp138 = temp_t6_3 + 8;
            // temp_t6_3->unk4 = 0x14050;
            // temp_t6_3->unk0 = (Gfx *)0xF5101000;
            gDPSetTile(sp138++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            // temp_t6_4 = sp138;
            // sp138 = temp_t6_4 + 8;
            // temp_t6_4->unk0 = (Gfx *)0xF5100900;
            // temp_t6_4->unk4 = 0x01010441;
            gDPSetTile(sp138++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
            // temp_t6_5 = sp138;
            // sp138 = temp_t6_5 + 8;
            // temp_t6_5->unk4 = 0x0200C832;
            // temp_t6_5->unk0 = (Gfx *)0xF5100540;
            gDPSetTile(sp138++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
            // temp_t6_6 = sp13C;
            // sp13C = temp_t6_6 + 8;
            // temp_t6_6->words.w1 = 0;
            // temp_t6_6->words.w0 = 0xE7000000;
            gDPPipeSync(sp13C++);
            // temp_t7_3 = sp13C;
            // sp13C = temp_t7_3 + 8;
            // temp_t7_3->words.w1 = 0;
            // temp_t7_3->words.w0 = 0xB9000002;
            gDPSetAlphaCompare(sp13C++, G_AC_NONE);
            // temp_a1 = sp13C;
            // temp_t7_4 = temp_a1 + 8;
            // sp13C = temp_t7_4;
            // temp_a1->words.w0 = 0xB900031D;
            // temp_a1->words.w1 = D_803C0644 | D_803C064C;
            gDPSetRenderMode(sp13C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
            // sp13C = temp_t7_4 + 8;
            // temp_t7_4->words.w1 = 0x1FFC93FC;
            // temp_t7_4->words.w0 = 0xFC26A004;
            gDPSetCombineMode(sp13C++, G_CC_TRILERP, G_CC_MODULATEI2);
            // temp_t7_5 = sp13C;
            // sp13C = temp_t7_5 + 8;
            // temp_t7_5->words.w1 = 0x00100000;
            // temp_t7_5->words.w0 = 0xBA001402;
            gDPSetCycleType(sp13C++, G_CYC_2CYCLE);
            // temp_t7_6 = sp13C;
            // sp13C = temp_t7_6 + 8;
            // temp_t7_6->words.w1 = 0x00010000;
            // temp_t7_6->words.w0 = 0xBA001001;
            gDPSetTextureLOD(sp13C++, G_TL_LOD);
            // temp_t7_7 = sp13C;
            // sp13C = temp_t7_7 + 8;
            // temp_t7_7->words.w1 = 0;
            // temp_t7_7->words.w0 = 0xFA008080;
            gDPSetPrimColor(sp13C++, 128, 128, 0x00, 0x00, 0x00, 0x00);
            // temp_t6_7 = sp13C;
            // sp13C = temp_t6_7 + 8;
            // temp_t6_7->words.w1 = 0x0007C07C;
            // temp_t6_7->words.w0 = 0xF2000000;
            gDPSetTileSize(sp13C++, G_TX_RENDERTILE, 0, 0, 124, 124);
            // temp_t9_6 = sp13C;
            // sp13C = temp_t9_6 + 8;
            // temp_t9_6->words.w1 = 0x0103C03C;
            // temp_t9_6->words.w0 = 0xF2000000;
            gDPSetTileSize(sp13C++, 1, 0, 0, 60, 60);
            // temp_t8_7 = sp13C;
            // sp13C = temp_t8_7 + 8;
            // temp_t8_7->words.w1 = 0x0201C01C;
            // temp_t8_7->words.w0 = 0xF2000000;
            gDPSetTileSize(sp13C++, 2, 0, 0, 28, 28);
            // temp_t7_8 = sp13C;
            // sp13C = temp_t7_8 + 8;
            // temp_t7_8->words.w1 = 0x0300C00C;
            // temp_t7_8->words.w0 = 0xF2000000;
            gDPSetTileSize(sp13C++, 3, 0, 0, 12, 12);
            // temp_t6_8 = sp13C;
            // sp13C = temp_t6_8 + 8;
            // temp_t6_8->words.w1 = 0x04004004;
            // temp_t6_8->words.w0 = 0xF2000000;
            gDPSetTileSize(sp13C++, 4, 0, 0, 4, 4);
            // temp_t9_7 = sp13C;
            // sp13C = temp_t9_7 + 8;
            // temp_t9_7->words.w1 = 0x05000000;
            // temp_t9_7->words.w0 = 0xF2000000;
            gDPSetTileSize(sp13C++, 5, 0, 0, 0, 0);
            // temp_t0 = sp13C;
            // sp13C = temp_t0 + 8;
            // temp_t0->words.w0 = 0xF5101000;
            // temp_t0->words.w1 = 0x00014050;
            gDPSetTile(sp13C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            // temp_t8_8 = sp13C;
            // sp13C = temp_t8_8 + 8;
            // temp_t8_8->words.w1 = 0x01010441;
            // temp_t8_8->words.w0 = 0xF5100900;
            gDPSetTile(sp13C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
            // temp_t8_9 = sp13C;
            // sp13C = temp_t8_9 + 8;
            // temp_t8_9->words.w0 = 0xF5100540;
            // temp_t8_9->words.w1 = 0x0200C832;
            gDPSetTile(sp13C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
            // temp_t8_10 = sp13C;
            // sp13C = temp_t8_10 + 8;
            // temp_t8_10->words.w1 = 0x03008C23;
            // temp_t8_10->words.w0 = 0xF5100350;
            gDPSetTile(sp13C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
            // temp_t8_11 = sp13C;
            // sp13C = temp_t8_11 + 8;
            // temp_t8_11->words.w0 = 0xF5100354;
            // temp_t8_11->words.w1 = 0x04005014;
            gDPSetTile(sp13C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
            // temp_t8_12 = sp13C;
            // sp13C = temp_t8_12 + 8;
            // temp_t8_12->words.w1 = 0x05001405;
            // temp_t8_12->words.w0 = 0xF5100356;
            gDPSetTile(sp13C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5);
            D_803F2C92 = 0;
            D_803F2C94 = 0;
            // temp_t8_13 = sp13C;
            D_803F2C99 = 0;
            D_803F2C9A = 0;
            D_803F2C9B = 0;
            // sp13C = temp_t8_13 + 8;
            // temp_t8_13->words.w0 = 0xE7000000;
            // temp_t8_13->words.w1 = 0;
            gDPPipeSync(sp13C++);

            spFC2 = D_803F2CA2 << 0xA;
            spFC0 = D_803F2CA4 << 0xA;

            do {
                // temp_a0_3 = D_803F2C80; //->unk0[0];
                temp_v0_2 = &D_803F2C80[spFC6]; //->unk0; // + (spFC6 * 0x34);

                temp_v1 = D_803F2C80[spFC6].unk0.unk0; // flags
                temp_t5_2 = D_803F2C80[spFC6].unk0.unk3;


                sp58 = (s32) temp_v1;

                if (sp58 & 1) {
                    spFB4 = 3; // three tris
                } else {
                    spFB4 = 4; // four tris
                }

                if ((sp58 & 0x20) || (sp58 & 0x10) || (sp58 & 0x200) || (sp58 & 0x8000)) {
                    // (*D_803F2CA8)[(D_803F2CA2 * 6) + D_803F2CA4] = 1;
                    D_803F2CA8[D_803F2CA2][D_803F2CA4] = 1;
                    for (i = 0; i < spFB4; i++) {
                    // if (i < spFB4) {
                        sp48 = sp58 & 0x4000;
                        sp54 = &D_803F2C80[spFC6]; // + (spFC6 * 0x34);
                        // do {
                        temp_v1_2 = i * 0xC;
                        var_v0 = &sp54; // + temp_v1_2;
                        D_803F2C9C = (var_v0->unk4[i].unk7 << 6) + spFC2 + 0x100;   // unkB
                        D_803F2C9E = (var_v0->unk4[i].unkA << 6) + spFC0 + 0x200;   // unkE
                        D_803F2CA0 = var_v0->unk4[i].unk8 * 8;                      // unkC
                        sp.unkF64[i] = (s8) ((s16) D_803F2C9C >> 6);
                        sp.unkF60[i] = (s8) ((s16) D_803F2C9E >> 6);
                        sp.unkF58[i] = spF92;

                        if (sp48 != 0) {
                            D_803F2CA0 = D_803F2CA0;
                        }
                        temp_t0_2 = var_v0->unk4[i].unk0 << 6; // unk4
                        temp_t1 = var_v0->unk4[i].unk2 << 6; // unk6

                        if ((s32) var_v0->unk4[i].unkB >= 0xFB) { // unkF
                            var_v0->unk4[i].unkB = 0xFFU; // unkF
                            temp_a1_2 = &D_803F2C80[spFC6].unk4; // * 0x34);
                            var_v0 = temp_a1_2 + temp_v1_2;
                            sp54 = temp_a1_2;
                        }
                        if (D_803F2C80[spFC6].unk0.unk2 >= 32) {
                            var_v1 = 0;
                        } else {
                            var_v1 = var_v0->unk4[i].unkB; // unkF
                        }

                        temp_v0_3 = &D_802294D0[spF92];
                        // temp_a1_3 = D_803F2CA0;
                        temp_v0_3->v.ob[0] = D_803F2C9C;
                        temp_v0_3->v.ob[1] = D_803F2C9E;
                        temp_v0_3->v.ob[2] = D_803F2CA0;

                        temp_v0_3->v.cn[0] = var_v0->unk4[i].unk4; // unk8
                        temp_v0_3->v.cn[1] = var_v0->unk4[i].unk5; // unk9
                        temp_v0_3->v.cn[2] = var_v0->unk4[i].unk6; // unkA
                        temp_v0_3->v.cn[3] = var_v1;

                        temp_v0_3->v.tc[0] = temp_t0_2;
                        temp_v0_3->v.tc[1] = temp_t1;

                        if (spF9C >= D_803F2C9C) {
                            spF9C = D_803F2C9C;
                        }
                        if (spFA0 >= D_803F2CA0) {
                            spFA0 = D_803F2CA0;
                        }
                        if (spF9E >= D_803F2C9E) {
                            spF9E = D_803F2C9E;
                        }
                        if (D_803F2C9C >= spFA2) {
                            spFA2 = D_803F2C9C;
                        }
                        if (D_803F2CA0 >= spFA6) {
                            spFA6 = D_803F2CA0;
                        }
                        if (D_803F2C9E >= spFA4) {
                            spFA4 = D_803F2C9E;
                        }
                        spF92 += 1;
                    }

                    if ((temp_t5_2 >= 32) && (temp_t5_2 < 48)) {
                        if (spFB4 == 4) {
                            spF72 = MAX(MAX(MAX(spF64, spF65), spF66), spF67);
                            spF70 = MAX(MAX(MAX(spF60, spF61), spF62), spF63);
                            spF6E = MIN(MIN(MIN(spF64, spF65), spF66), spF67);
                            spF6C = MIN(MIN(MIN(spF60, spF61), spF62), spF63);
                        }
                        for (i = 0; i < spFB4; i++) {
                            D_803E4930[D_803E4AC8 + i] = (spF72 + spF6E) >> 1;
                            D_803E4998[D_803E4AC8 + i] = (spF70 + spF6C) >> 1;
                            D_803E4A00[D_803E4AC8 + i] = spF58[i];
                        }
                        D_803E4AC8 += spFB4;
                    }

                    // (sp + (spF8C * 0x24))->unk148 = spFC6;
                    sp.unk148[spF8C][0] = spFC6; // fixme

                    temp_v0_5 = spF8C + 1;
                    if (temp_v1 & 1) {
                        spF8E += 3;
                    } else {
                        spF8E += 4;
                    }
                    spFC6 += 1;
                    spF8C = temp_v0_5;
                    if (temp_v0_5 >= 8) {
                        spF90 = spF92;
                        func_803458B8_756F68(&sp138, &D_802294D0[spF90], spF8E);
                        func_80346BB4_758264(&sp138, &sp148, 8);
                        spF8E = 0; // reset numTris
                        spF8C = 0; // reset index?
                    }
                } else {
                    sp40 = var_s3 - spF98;
                    sp54 = &D_803F2C80[spFC6]; // + (spFC6 * 0x34);
                    sp48 = sp58 & 0x4000;
                    sp44 = &sp850[spF94][0]; // (spF94 * 0x24) + &sp850;
                    // i = 0;
                    for (i = 0; i < spFB4; i++) {
                    // do {
                        // temp_v0_6 = &sp54; // + (i * 0xC);
                        D_803F2C9C = (sp54->unk4[i].unk7 << 6) + spFC2 + 0x100;    // unkB
                        D_803F2C9E = (sp54->unk4[i].unkA << 6) + spFC0 + 0x200;    // unkE

                        var_a3 = -0x64;
                        var_v1_10 = spF98;
                        D_803F2CA0 = sp54->unk4[i].unk8 * 8;   // unkC
                        if (sp48 != 0) {
                            D_803F2CA0 = D_803F2CA0;
                        }

                        sp147 = sp54->unk4[i].unk4;    // unk8
                        sp146 = sp54->unk4[i].unk5;    // unk9
                        sp145 = sp54->unk4[i].unk6;    // unkA

                        temp_t0_3 = sp54->unk4[i].unk0 << 6;   // unk4
                        temp_t1_2 = sp54->unk4[i].unk2 << 6;   // unk6

                        temp_t2 = sp147 & 0xFF;
                        temp_t3 = sp146 & 0xFF;
                        temp_t4 = sp145 & 0xFF;

                        if (var_v1_10 < var_s3) {
                            do {
                                var_s0 = 0;
                                if (D_803F2DAC[D_803F2CA2][D_803F2CA4] == 0) {
                                    temp_v0_7 = &D_80210FF0[var_v1_10];
                                    if ((D_803F2C9C == temp_v0_7->v.ob[0]) && (D_803F2C9E == temp_v0_7->v.ob[1]) && (D_803F2CA0 == temp_v0_7->v.ob[2]) && (var_a3 == -0x64)) {
                                        if ((temp_t0_3 != temp_v0_7->v.tc[0]) || (temp_t1_2 != temp_v0_7->v.tc[1])) {
                                            var_s0 = 1;
                                        }
                                        if (temp_v0_7->v.flag != 0) {
                                            var_s0 |= 1;
                                        }
                                        temp_v0_7->v.flag = 1;
                                        if (var_s0 == 0) {
                                            // goto block_140;
                                            var_s0 = 4;
                                        }
                                    }
                                } else {
                                    temp_v0_7 = &D_80210FF0[var_v1_10];
                                    if ((D_803F2C9C == temp_v0_7->v.ob[0]) && (D_803F2C9E == temp_v0_7->v.ob[1]) && (D_803F2CA0 == temp_v0_7->v.ob[2]) &&
                                       ((temp_t2 & 0xF0) == (temp_v0_7->v.cn[0] & 0xF0)) && ((temp_t3 & 0xF0) == (temp_v0_7->v.cn[1] & 0xF0)) && ((temp_t4 & 0xF0) == (temp_v0_7->v.cn[2] & 0xF0)) &&
                                       (var_a3 == -0x64)) {

                                        if (((temp_t0_3 & 0xFFFF00) != (temp_v0_7->v.tc[0] & 0xFFFF00)) || ((temp_t1_2 & 0xFFFF00) != (temp_v0_7->v.tc[1] & 0xFFFF00))) {
                                            var_s0 = 1;
                                        }
                                        if (temp_v0_7->v.flag != 0) {
                                            var_s0 |= 1;
                                        }
                                        temp_v0_7->v.flag = 1U;
                                        if (var_s0 == 0) {
                                            var_s0 = 4;
                                        }
                                    }
                                }
                                if (var_s0 != 0) {
                                    var_a3 = var_v1_10;
                                    var_v1_10 = var_s3;
                                } else {
                                    var_v1_10 += 1;
                                }
                            } while (var_v1_10 < var_s3);
                        }

                        temp_a0_6 = D_803F2C9C;
                        temp_a2_3 = D_803F2C9E;
                        temp_a1_6 = D_803F2CA0;

                        if (var_a3 != -0x64) {
                            temp_v1_3 = sp44 + (i * 2);
                            temp_v1_3->unk4 = (s16) (var_a3 - spF98);
                            temp_v1_3->unkC = var_s0;
                        } else {
                            // temp_v0_9 = &D_80210FF0[var_s3];
                            D_80210FF0[var_s3].v.flag = 0;
                            D_80210FF0[var_s3].v.ob[0] = temp_a0_6;
                            D_80210FF0[var_s3].v.ob[1] = temp_a2_3;
                            D_80210FF0[var_s3].v.ob[2] = temp_a1_6;

                            if (D_803F2DAC[D_803F2CA2][D_803F2CA4] == 0) {
                                D_80210FF0[var_s3].v.cn[0] = sp147;
                                D_80210FF0[var_s3].v.cn[1] = sp146;
                                D_80210FF0[var_s3].v.cn[2] = sp145;
                            } else {
                                D_80210FF0[var_s3].v.cn[0] = temp_t2;
                                D_80210FF0[var_s3].v.cn[1] = temp_t3;
                                D_80210FF0[var_s3].v.cn[2] = temp_t4;
                            }

                            temp_v1_4 = sp44 + (i * 2);
                            temp_v1_4->unk4 = (s16) sp40;
                            temp_v1_4->unkC = 0;
                            temp_v1_4->unk1C = var_s3;
                            D_80210FF0[var_s3].v.cn[3] = 0xFF;
                            D_80210FF0[var_s3].v.tc[0] = temp_t0_3;
                            D_80210FF0[var_s3].v.tc[1] = temp_t1_2;
                            var_s3 += 1;
                            sp40 = var_s3 - spF98;
                        }

                        if (spFA8 >= temp_a0_6) {
                            spFA8 = temp_a0_6;
                        }
                        if (spFAC >= temp_a1_6) {
                            spFAC = temp_a1_6;
                        }
                        if (spFAA >= temp_a2_3) {
                            spFAA = temp_a2_3;
                        }
                        if (temp_a0_6 >= spFAE) {
                            spFAE = temp_a0_6;
                        }
                        if (temp_a1_6 >= spFB2) {
                            spFB2 = temp_a1_6;
                        }
                        if (temp_a2_3 >= spFB0) {
                            spFB0 = temp_a2_3;
                        }
                    }
                    // (sp + (spF94 * 0x24))->
                    sp850[spF94][0].unk0 = spFC6;

                    spF94 += 1;
                    // spF94 = temp_a3_2;
                    spFC6 += 1;

                    if (sp40 >= 29) {
                        temp_t6_10 = spF98;
                        spF98 = var_s3;
                        // spF94 = temp_a3_2;
                        func_803458B8_756F68(&sp13C, &D_80210FF0[temp_t6_10], sp40);
                        func_803458FC_756FAC(&sp13C, &sp850, spF94);
                        spF94 = 0;
                    }
                }
            } while ((sp58 & 2) != 0);

            // temp_t8_14 = spF88 * 0x10;
            // temp_v0_10 = temp_t8_14 + &D_80224870;

            // D_80224870 is 5000 Vtx higher than D_80210FF0
            D_80224870[spF88 + 0].v.ob[0] = spFA8;
            D_80224870[spF88 + 1].v.ob[0] = spFAE;
            D_80224870[spF88 + 0].v.ob[2] = spFAC;
            D_80224870[spF88 + 1].v.ob[2] = spFAC;

            D_80224870[spF88 + 0].v.ob[1] = spFAA;
            D_80224870[spF88 + 1].v.ob[1] = spFAA;

            D_80224870[spF88 + 4].v.ob[2] = spFB2;
            D_80224870[spF88 + 5].v.ob[2] = spFB2;
            D_80224870[spF88 + 6].v.ob[2] = spFB2;
            D_80224870[spF88 + 7].v.ob[2] = spFB2;
            D_80224870[spF88 + 2].v.ob[1] = spFB0;
            D_80224870[spF88 + 3].v.ob[1] = spFB0;
            D_80224870[spF88 + 6].v.ob[1] = spFB0;
            D_80224870[spF88 + 7].v.ob[1] = spFB0;
            D_80224870[spF88 + 2].v.ob[0] = spFA8;
            D_80224870[spF88 + 4].v.ob[0] = spFA8;
            D_80224870[spF88 + 6].v.ob[0] = spFA8;
            D_80224870[spF88 + 3].v.ob[0] = spFAE;
            D_80224870[spF88 + 5].v.ob[0] = spFAE;
            D_80224870[spF88 + 7].v.ob[0] = spFAE;
            D_80224870[spF88 + 2].v.ob[2] = spFAC;
            D_80224870[spF88 + 3].v.ob[2] = spFAC;
            D_80224870[spF88 + 4].v.ob[1] = spFAA;
            D_80224870[spF88 + 5].v.ob[1] = spFAA;

            // D_8022D350 is 2222 Vtx higher than D_80224870
            // temp_v1_5 = temp_t8_14 + &D_8022D350;

            D_8022D350[spF88 + 0].v.ob[2] = spFA0;
            D_8022D350[spF88 + 1].v.ob[2] = spFA0;
            D_8022D350[spF88 + 0].v.ob[1] = spF9E;
            D_8022D350[spF88 + 1].v.ob[1] = spF9E;

            D_8022D350[spF88 + 4].v.ob[2] = spFA6;
            D_8022D350[spF88 + 5].v.ob[2] = spFA6;
            D_8022D350[spF88 + 6].v.ob[2] = spFA6;
            D_8022D350[spF88 + 7].v.ob[2] = spFA6;

            D_8022D350[spF88 + 2].v.ob[1] = spFA4;
            D_8022D350[spF88 + 3].v.ob[1] = spFA4;
            D_8022D350[spF88 + 6].v.ob[1] = spFA4;
            D_8022D350[spF88 + 7].v.ob[1] = spFA4;

            D_8022D350[spF88 + 2].v.ob[0] = spF9C;
            D_8022D350[spF88 + 4].v.ob[0] = spF9C;
            D_8022D350[spF88 + 6].v.ob[0] = spF9C;
            D_8022D350[spF88 + 3].v.ob[0] = spFA2;

            D_8022D350[spF88 + 5].v.ob[0] = spFA2;
            D_8022D350[spF88 + 7].v.ob[0] = spFA2;
            D_8022D350[spF88 + 2].v.ob[2] = spFA0;
            D_8022D350[spF88 + 3].v.ob[2] = spFA0;

            D_8022D350[spF88 + 4].v.ob[1] = spF9E;
            D_8022D350[spF88 + 5].v.ob[1] = spF9E;
            D_8022D350[spF88 + 0].v.ob[0] = spF9C;
            D_8022D350[spF88 + 1].v.ob[0] = spFA2;


            if (spF94 != 0) {
                temp_t8_15 = spF98;
                spF98 = var_s3;
                func_803458B8_756F68(&sp13C, &D_80210FF0[temp_t8_15], var_s3 - temp_t8_15);
                temp_a2_4 = spF94;
                spF94 = 0;
                func_803458FC_756FAC(&sp13C, &sp850, temp_a2_4);
            }
            if (spF8C != 0) {
                temp_a2_5 = spF8E; // num
                spF8E = 0;
                temp_a1_7 = &D_802294D0[spF90];
                spF90 = spF92;
                func_803458B8_756F68(&sp138, temp_a1_7, temp_a2_5);
                temp_a2_6 = spF8C;
                spF8C = 0;
                func_80346BB4_758264(&sp138, &sp148, temp_a2_6);
            }
            gSPEndDisplayList(sp13C++);
            gSPEndDisplayList(sp138++);
        }
    }
    gSPEndDisplayList(sp13C++);
    gSPEndDisplayList(sp138++);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_80344240_7558F0.s")
#endif

void func_803458B8_756F68(Gfx **arg0, Vtx *vtx, s16 num) {
    gSPVertex((*arg0)++, K0_TO_PHYS(vtx), num, 0);
}

// a long way to go here, probably need to start again
#if 0
void func_803458FC_756FAC(Gfx **dl, struct117 *arg1, s16 numTris) {
    s16 sp17A;
    s16 sp178;
    u8 sp175;
    s16 *sp4C;
    struct117 *temp_t2;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_v0_6;
    s32 temp_a0;
    s32 temp_t9;
    u16 temp_v1;
    u8 temp_s6;
    struct102_inner *temp_v0;
    struct073 *temp_v0_4;
    s16 phi_t3;
    struct117 *phi_t2;
    s16 phi_t3_2;

    s16 i;

    sp178 = 0;
    sp17A = 0;
    // phi_a2 = numTris;

    for (i = 0; i < numTris; i++) {
        // phi_t3 = 0xC;
        // phi_t3_2 = 0xC;
        // temp_t9 = i * 0x24; // sp17A
        temp_t2 = &arg1[i]; // + (i * 0x24); //temp_t9;
        temp_v0 = &D_803F2C80[temp_t2->unk0.unk0]; // *phi_t4 + (*temp_t2 * 0x34);
        temp_v1 = temp_v0->unk0;
        temp_s6 = temp_v0->unk2;
        // temp_a0 = temp_v1 & 8;
        sp175 = temp_v0->unk3;
        phi_t2 = temp_t2; //->unk0;
        // phi_t4_2 = phi_t4;
        // phi_t3_2 = phi_t3;
        if ((temp_v1 & 8) ||
            (temp_v1 & 0x40) ||
            (temp_v1 & 0x2000) ||
            (temp_v1 & 0x100)) {
            // sp40 = temp_v1 & 0x40;
            if ((temp_v1 & 8) && (D_803F2C86 != 4)) {
                gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE);
                gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0180, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                gDPSetTextureLOD((*dl)++, G_TL_TILE);
                gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
                gDPTileSync((*dl)++);

                D_803F2C86 = 4;
            }
            if ((temp_v1 & 0x100) != 0) {
                if (12 != D_803F2C86) {
                    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01C0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);

                    D_803F2C86 = 12;
                }
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) (temp_v0_4->unk0 | 1);
                D_803E3130[D_803F2CA6].unk1 = 6;
                D_803E3130[D_803F2CA6].unk2 = (s16) sp175;
                D_803E3130[D_803F2CA6].unk14 = (s32 *) *dl;
                gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);

                D_803F2CA6 += 1;
                D_803F2C92 = 1;
            }
        } else {
            if (temp_s6 > 40) {
                if (D_803F2C86 != 14) {
                    D_803F2C8E = 0;
                    gDPPipeSync((*dl)++);
                    gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                    gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                    gDPSetCombineMode((*dl)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                    gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_TEX_EDGE2);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 32768, 32768, 0, 6, G_ON);

                    if (D_803F2C96 != temp_s6) {
                        D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) (temp_v0_4->unk0 | 1);
                        D_803E3130[D_803F2CA6].unk1 = (s8) (temp_s6 - 33);
                        D_803E3130[D_803F2CA6].unk2 = (s16) sp175;
                        D_803E3130[D_803F2CA6].unk14 = (s32 *) *dl;
                        D_803F2CA6 += 1; //D_803F2CA6 + 1;
                        gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_0102C810));
                        gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPLoadSync((*dl)++);
                        gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 512);
                        gDPPipeSync((*dl)++);
                        gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);

                        D_803F2C96 = temp_s6;
                        D_803F2C97 = 0xFF;
                    }
                    D_803F2C86 = 14;
                }
            } else if (((temp_v1 & 8) == 0) && (D_803F2C86 != 1)) {
                gDPPipeSync((*dl)++);
                gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
                gDPSetTextureLOD((*dl)++, G_TL_LOD);
                gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                gSPTexture((*dl)++, 32768, 32768, 5, G_TX_RENDERTILE, G_ON);
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);

                D_803F2C86 = 1;
            }
            if (sp175 != 0) {
                D_803F2C86 = 1;
                if (D_803F2C86 != 0) {
                    D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) (temp_v0_4->unk0 | 1);
                    D_803E3130[D_803F2CA6].unk1 = 1;
                    D_803E3130[D_803F2CA6].unk2 = (s16) sp175;
                    D_803E3130[D_803F2CA6].unk14 = *dl;
                    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
                    gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
                    gDPTileSync((*dl)++);
                    gDPPipeSync((*dl)++);

                    D_803F2CA6 += 1; //(s16) (D_803F2CA6 + 1);
                    D_803F2C92 = 1;
                }
            }
        }
        if (temp_v1 & 0x40) {
            if (D_803F2C99 == 0) {
                gDPPipeSync((*dl)++);
                gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEIDECALA);
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_TEX_EDGE2);
                D_803F2C99 = 1;
            }
        } else if (D_803F2C99 == 1) {
            gDPPipeSync((*dl)++);
            gSPTexture((*dl)++, 32768, 32768, 5, G_TX_RENDERTILE, G_ON);
            gDPSetAlphaCompare((*dl)++, G_AC_NONE);
            gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
            gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);

            D_803F2C99 = 0U;
        }
        if (temp_v1 & 0x4000) {
            if (D_803F2C8E != 1) {
                D_803F2C8E = 1;
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_ZB_OPA_DECAL2);
                // goto block_37;
            }
        } else if (D_803F2C8E != 0) {
            D_803F2C8E = 0;
            if (temp_v0->unk2 > 40) {
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_TEX_EDGE2);

            } else {
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
            }
        }
        if (temp_v1 & 0x800) {
            if (D_803F2C88 != 2) {
                D_803F2C88 = 2;
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_OPA_INTER2);

            }
        } else if (D_803F2C88 != 1) {
            gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
        }
        if (D_803F2C96 != temp_v0->unk2) {
            if (temp_v0->unk2 < 32) {
                sp4C = temp_t2;
                func_80346878_757F28(dl, temp_s6); //, numTris);
                // phi_t4_2 = &D_803F2C80;
            }
            D_803F2C96 = temp_s6;
            D_803F2C97 = 0xFF;
            phi_t2 = &arg1[i]; // + (i * 0x24) ; // temp_t9;
        }
        // phi_t4 = phi_t4_2;
        // phi_t3 = phi_t3_2;
        if ((temp_v1 & 4) && (D_803F2C9A == 0)) {
            gSPClearGeometryMode((*dl)++, G_CULL_BACK);

            D_803F2C9A = 1;
        }
        if (((temp_v1 & 4) == 0) && (D_803F2C9A == 1)) {
            gSPSetGeometryMode((*dl)++, G_CULL_BACK);
            D_803F2C9A = 0;
        }
        if (temp_v1 & 0x80) {
            if (D_803F2C8A != 0) {
                D_803F2C8A = 0;
            }
        } else if (D_803F2C8A != 1) {
            D_803F2C8A = 1;
        }
        if (temp_v1 & 0x400) {
            if (D_803F2C8C != 1) {
                gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, PRIMITIVE, SHADE, 0, 0, 0, 0, SHADE);
                gDPSetPrimColor((*dl)++, 128, 128, 45, 45, 45, 0x00);
                D_803F2C8C = 1;
            }
        } else if (D_803F2C8C == 1) {
            gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
            D_803F2C8C = 0;
        }
        if ((sp175 == 0) && (D_803F2C92 != 0)) {
            if ((temp_v1 & 0x40) == 0) {
                gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 124);

            }
            gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
            gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
            gDPSetTileSize((*dl)++, 3, 0, 0, 12, 12);
            gDPSetTileSize((*dl)++, 4, 0, 0, 4, 4);
            gDPSetTileSize((*dl)++, 5, 0, 0, 0, 0);

            D_803F2C92 = 0;
        }
        if ((temp_v1 & 1) == 0) {
            for (i = 0; i < 4; i++) {
#if 0
                temp_a2 = i * 2;
                temp_v0_6 = (arg1 + (i * 0x24) + temp_a2)->unkC;
                if ((temp_v0_6 != 0) && ((temp_v0_6 & 1) != 0)) {
                    temp_v0_7 = D_803F2C80[phi_t2->unk0].unk4[i]; // + (phi_t2->unk0.->unk0 * 0x34) + (i * 12);
                    // temp_a0_67 = *arg0;
                    // *arg0 = temp_a0_67 + 8;
                    // temp_a0_67->unk0 = (((phi_t2 + temp_a2)->unk4 * 2) & 0xFFFF) | 0xB2140000;
                    // temp_a0_67->unk4 = (s32) ((((temp_v0_7->unk4 << 5) << 0x10) & 0xFFFF0000) | ((temp_v0_7->unk6 << 5) & 0xFFFF));
                    gSPModifyVertex((*dl)++,
                        ((phi_t2 + temp_a2)->unk4 * 2),
                        G_MWO_POINT_ST,
                        (temp_v0_7->unk4 << 5) |
                        (temp_v0_7->unk6 << 5)));
                }
#endif
            }
            gSP1Quadrangle((*dl)++,
                phi_t2->unk4[0].unk0, //->unk4 << 1,
                phi_t2->unk4[0].unk2, //->unk6 << 1,
                phi_t2->unk4[0].unk4, //->unk8 << 1,
                phi_t2->unk4[0].unk6, //->unkA << 1,
                0); // flag

            sp178 += 1;
        } else {
            for (i = 0; i < 3; i++) {
#if 0
                temp_a2_2 = i * 2;
                temp_v0_6 = (arg1 + (i * 0x24) + temp_a2_2)->unkC;
                // phi_a2 = temp_a2_2;
                if ((temp_v0_6 != 0) && ((temp_v0_6 & 1) != 0)) {
                    temp_v0_9 = D_803F2C80 + (phi_t2[0] * 0x34) + (i * 12);
                    // temp_a0_69 = *arg0;
                    // *arg0 = temp_a0_69 + 8;
                    temp_a0_69->unk0 = (((phi_t2 + temp_a2_2)->unk4 * 2) & 0xFFFF) | 0xB2140000;
                    temp_a0_69->unk4 = (s32) ((((temp_v0_9->unk4 << 5) << 0x10) & 0xFFFF0000) | ((temp_v0_9->unk6 << 5) & 0xFFFF));
                }
#endif
                // gSPModifyVertex((*dl)++,
                //     D_803F2C80[phi_t2[2]][i], //phi_t2[i][2],
                //     G_MWO_POINT_ST,
                //     D_803F2C80[phi_t2[0]][i]
                // );

            }
            gSP1Triangle((*dl)++,
                phi_t2->unk4[0].unk0, //->unk4 << 1,
                phi_t2->unk4[0].unk2, //->unk6 << 1,
                phi_t2->unk4[0].unk4, //->unk8 << 1,
                0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_803458FC_756FAC.s")
#endif

void func_80346878_757F28(Gfx **arg0, u8 arg1) {
    if (arg1 < 32) {
        gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[(s32)arg1]);
        gDPTileSync((*arg0)++);
        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTextureImage((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_800BA760[(s32)arg1]);
        gDPTileSync((*arg0)++);
        gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    }
    gDPTileSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 1372, 0);
    gDPTileSync((*arg0)++);
}

// load EVO texture?
void func_803469D4_758084(Gfx **arg0, u16 arg1) {
    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_0102F010 + ((u8)arg1 << 7));
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 31, 256);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 0);
}

// load_xlui_texture
void func_80346AB0_758160(Gfx **arg0, u8 arg1) {
    rmonPrintf("load xlui texture - %d\n", arg1);
    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[(s32)arg1]);
    gDPTileSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 1024, 0);
    gDPTileSync((*arg0)++);
}

// uses delay slot
#if 0
void func_80346BB4_758264(Gfx **arg0, struct115* arg1, s16 numTris) {
    s16 i;    // sp29A
    s16 tris; // sp298
    u8  padx[3];
    u8  sp294; // usedTris? neededTris?
    u8  pad2[0x14];
    s16 sp28E;
    // s32 sp5C;
    // s16 *sp58;
    // s32 sp50;
    // s32 sp48;
    // s32 sp44;

    s32 temp_t0_3;
    // s32 temp_v1_9;
    s16 var_v0_5;
    s16 var_v0_4;
    s8 temp_t0_2;

    u16 vtxFlags;
    u8 temp_s1;

    tris = 0;

    for (i = 0; i < numTris; i++) {
        sp28E = 1;

        // helpppp...
        vtxFlags = D_803F2C80[arg1[i].unk0].unk0.unk0;
        temp_s1 = D_803F2C80[arg1[i].unk0].unk0.unk3;
        sp294   = D_803F2C80[arg1[i].unk0].unk0.unk2;

        if (((vtxFlags & 0x20)) || (vtxFlags & 0x10) || (vtxFlags & 0x200) || (vtxFlags & 0x8000) || (vtxFlags & 0x100) || (vtxFlags & 0x1000)) {
            if ((vtxFlags & 0x8000) && (D_803F2C84 != 7)) {
                gDPSetCombineMode((*arg0)++, G_CC_MODULATEI, G_CC_PASS2);
                gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803C0648_7D1CF8);
                D_803F2C84 = 7;
            }
            if ((vtxFlags & 0x10)) {
                sp28E = 0;
                if (D_803F2C84 != 3) {
                    gDPPipeSync((*arg0)++);
                    gDPSetCombineLERP((*arg0)++, TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, PRIMITIVE);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 5, G_ON); // 0x10000*(0.5)

                    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, D_0102B610);

                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x019E, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync((*arg0)++);
                    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 124);
                    gDPPipeSync((*arg0)++);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x019E, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPPipeSync((*arg0)++);
                    D_803F2C84 = 3;
                }

                D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) temp_v1_2->unk0 | 1;

                if (temp_s1 != 0) {
                    D_803E3130[D_803F2CA6].unk1 = 0;
                    D_803E3130[D_803F2CA6].unk14 = *arg0;
                    gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*arg0)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // 0x100*

                } else {
                    D_803E3130[D_803F2CA6].unk1 = 7;
                    D_803E3130[D_803F2CA6].unk14 = *arg0;
                    gDPSetPrimColor((*arg0)++, 128, 128, 0x00, 0x00, 0x00, 0xDC);

                }
                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if ((vtxFlags & 0x200)) {
                sp28E = 0;
                if (D_803F2C84 != 6) {
                    gDPSetCombineLERP((*arg0)++, TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0, TEXEL1, PRIMITIVE, SHADE, PRIMITIVE, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, COMBINED);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 5, G_ON);
                    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, D_0102B810);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x01A0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync((*arg0)++);
                    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 124);
                    gDPPipeSync((*arg0)++);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x01A0, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPPipeSync((*arg0)++);
                    D_803F2C84 = 6;
                }
                D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;

                if (temp_s1 != 0) {
                    D_803E3130[D_803F2CA6].unk1 = 3;
                    D_803E3130[D_803F2CA6].unk14 = *arg0;
                    gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*arg0)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // 0x100*
                } else {
                    D_803E3130[D_803F2CA6].unk1 = 7;
                    D_803E3130[D_803F2CA6].unk14 = *arg0;
                    gDPSetPrimColor((*arg0)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // 0x100*
                    gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                }
                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if ((vtxFlags & 0x100)) {
                sp28E = 0;
                if (D_803F2C84 != 11) {
                    gSPClearGeometryMode((*arg0)++, G_FOG);
                    gDPSetCombineLERP((*arg0)++,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 6, G_ON);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 6, 0x01DE, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);

                    D_803F2C84 = 11;
                }
                D_803E3130[D_803F2CA6].unk2 = temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;
                D_803E3130[D_803F2CA6].unk1 = 5;
                D_803E3130[D_803F2CA6].unk14 = *arg0;
                gDPSetTileSize((*arg0)++, 6, 0, 0, 60, 60);

                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if ((vtxFlags & 0x1000)) {
                sp28E = 0;
                if (D_803F2C84 != 13) {
                    gSPClearGeometryMode((*arg0)++, G_FOG);
                    gDPSetCombineLERP((*arg0)++,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 5, G_ON);

                    D_803F2C84 = 13;
                }
                D_803E3130[D_803F2CA6].unk2 = temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_8022D350[temp_t8_14].unk0 | 1;
                D_803E3130[D_803F2CA6].unk1 = 5;
                D_803E3130[D_803F2CA6].unk14 = *arg0;
                gDPSetTileSize((*arg0)++, 5, 0, 0, 60, 60);

                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }

            if (((vtxFlags & 0x20) != 0) && ((vtxFlags & 0x10) == 0) && ((vtxFlags & 0x200) == 0) && ((vtxFlags & 0x100) == 0)) {
                vtxFlags = D_803F2C80[arg1[i].unk0].unk0.unk2;
                if (sp294 >= 32) {
                    if (D_803F2C84 != 0xE) {
                        gDPPipeSync((*arg0)++);
                        if (sp294 > 40) {
                            gDPSetCombineMode((*arg0)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                            gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
                            gDPSetBlendColor((*arg0)++, 0x00, 0x00, 0x00, 0x01);

                            if (vtxFlags & 0x4000) {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, G_RM_ZB_XLU_DECAL2);
                            } else {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, D_803F2CC0);

                            }
                            gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                            gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 6, G_ON);

                            temp_t0_2 = sp294 - 33;
                            D_803E3130[D_803F2CA6].unk2 = temp_s1;
                            D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;
                            D_803E3130[D_803F2CA6].unk1 = temp_t0_2;
                            D_803F2CA6++; // = temp_a1_2 + 1;
                            D_803E3130[D_803F2CA6].unk14 = *arg0;
                            if (temp_t0_2 == 9) {
                                gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_0102C810 + 0x1000));
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync((*arg0)++);
                                gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 511, 512);
                                gDPPipeSync((*arg0)++);
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);

                            } else {
                                gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_0102C810));
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync((*arg0)++);
                                gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 511, 512);
                                gDPPipeSync((*arg0)++);
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                            }
                            gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        } else {
                            gDPSetCombineLERP((*arg0)++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, SHADE, 0, COMBINED);
                            if (vtxFlags & 0x4000) {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, G_RM_ZB_XLU_DECAL2);

                            } else {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, D_803F2CC0);
                            }
                            gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                            gSPTexture((*arg0)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                            gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
                            gDPSetBlendColor((*arg0)++, 0x00, 0x00, 0x00, 0x01);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5);
                            gDPSetTileSize((*arg0)++, 5, 0, 0, 0, 0);

                            D_803F2C84 = 0xE;
                        }
                        if (temp_s1 != 0) {
                            D_803E3130[D_803F2CA6].unk2 = temp_s1;
                            D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;
                            D_803E3130[D_803F2CA6].unk1 = 0xB;
                            D_803F2CA6++; // = temp_a1_3 + 1;
                            D_803F2C94 = 1;
                            D_803E3130[D_803F2CA6].unk14 = *arg0;

                            gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                            gDPSetTileSize((*arg0)++, 1, 0, 0, 60, 60);
                            gDPSetTileSize((*arg0)++, 2, 0, 0, 28, 28);

                        }
                    }
                } else {
                    if (vtxFlags & 1) {
                        var_v0_4 = 3;
                    } else {
                        var_v0_4 = 4;
                    }

                    // delayslot around here ish
                    var_v0_5 = var_v0_4 + 1;
                    if (var_v0_4 > 0) {
                    loop_59:
                        if (var_v0_5 > 0) {
                            var_v0_5 = var_v0_5 + 1;
                            goto loop_59;
                        }
                    }

                    if ((D_803F2C84 != 9) && (sp294 != 0)) {
                        gDPPipeSync((*arg0)++);
                        gSPClearGeometryMode((*arg0)++, G_FOG);
                        gDPSetEnvColor((*arg0)++, 0x00, 0x00, 0x80, 0x80);

                        if (vtxFlags & 0x4000) {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_ZB_XLU_DECAL2);
                        } else {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC0);

                        }
                        if (vtxFlags & 0x40) {
                            gDPSetAlphaCompare((*arg0)++, G_AC_DITHER);
                        } else {
                            gDPSetAlphaCompare((*arg0)++, G_AC_NONE);

                        }
                        gDPSetCombineMode((*arg0)++, G_CC_TRILERP, G_CC_MODULATEI2);
                        gSPTexture((*arg0)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                        gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                                                                      /* line, tmem, tile, palette ... */
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5);
                        gDPSetTileSize((*arg0)++, 5, 0, 0, 0, 0);

                        D_803F2C84 = 9;
                    }

                    if ((temp_s1 != 0) && !(vtxFlags & 0x100) && !(vtxFlags & 0x10) && !(vtxFlags & 0x200)) {
                        D_803E3130[D_803F2CA6].unk2 = temp_s1;
                        D_803E3130[D_803F2CA6].unk0 |= 1;
                        D_803E3130[D_803F2CA6].unk1 = 4;
                        D_803E3130[D_803F2CA6].unk14 = *arg0;
                        gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                        gDPSetTileSize((*arg0)++, 1, 0, 0, 60, 60);
                        gDPSetTileSize((*arg0)++, 2, 0, 0, 28, 28);
                        gDPTileSync((*arg0)++);
                        gDPPipeSync((*arg0)++);
                        D_803F2C94 = 1;
                        D_803F2CA6 += 1;
                    }
                    if ((sp294 == 0) && (D_803F2C84 != 0xA)) {
                        gDPPipeSync((*arg0)++);
                        gSPClearGeometryMode((*arg0)++, G_FOG);
                        gDPSetEnvColor((*arg0)++, 0x00, 0x00, 0x80, 0x80);

                        if (vtxFlags & 0x4000) { // DECAL_MODE?
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_ZB_XLU_DECAL2);

                        } else {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC0);

                        }
                        if (vtxFlags & 0x40) { // DITHER ?
                            gDPSetAlphaCompare((*arg0)++, G_AC_DITHER);
                        } else {
                            gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
                        }
                        gDPSetCombineMode((*arg0)++, G_CC_SHADE, G_CC_PASS2);

                        D_803F2C84 = 0xA;
                    }
                }
            }
        }

        if ((D_803F2C98 != sp294) && (sp28E == 1)) {
            if (sp294 <= 40) {
                func_80346878_757F28(arg0, sp294);
                D_803F2C98 = sp294;
            } else {
                D_803F2C98 = 100;
            }
        }
        if (vtxFlags & 4) {
            if (D_803F2C9B == 0) {
                gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
                D_803F2C9B = 1;
            }
        } else if (D_803F2C9B == 1) {
            gSPSetGeometryMode((*arg0)++, G_CULL_BACK);
            D_803F2C9B = 0;
        }
        if ((temp_s1 == 0) && (D_803F2C94 != 0)) {
            gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
            gDPSetTileSize((*arg0)++, 1, 0, 0, 60, 60);
            gDPSetTileSize((*arg0)++, 2, 0, 0, 28, 28);
            gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
            gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
            D_803F2C94 = 0;
        }

        if ((vtxFlags & 1) == 0) {
            gSP1Quadrangle((*arg0)++,
            /* v0   */ tris + 0,
            /* v1   */ tris + 1,
            /* v2   */ tris + 2,
            /* v3   */ tris + 3,
            /* flag */ 0);
            tris += 1; // 4 triangles
        } else {
            gSP1Triangle((*arg0)++,
            /* v0   */ tris + 0,
            /* v1   */ tris + 1,
            /* v2   */ tris + 2,
            /* flag */ 0);
        }
        tris += 3;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_80346BB4_758264.s")
#endif
