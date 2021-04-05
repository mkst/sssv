#include <ultra64.h>
#include "common.h"


void func_8038F6F0_7A0DA0(void) {
    D_803F6680.unk8 = 5;
    D_803F6680.unkE = 0;
}

void func_8038F708_7A0DB8(void) {
    if ((D_803F6716 != D_8023F2A0.unkD) || (D_803F6718 != D_8023F2A0.unkC) || (D_803F671A != D_8023F2A0.unkE)) {
        write_eeprom(4);
        func_80133BA0(D_8023F2A0.unkC);
    }
    D_803F66A4 = 1;
    func_802F07D0_701E80();
    func_802F07E8_701E98(3);
    D_8028645C = 0;
}

void func_8038F794_7A0E44(void) {
    generate_stars();
    func_801337DC(0, 60.0f, 20.0f, 6.0f);

    D_803F6680.unk14 = 0;
    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6730;
    D_803F6680.unk31 = 0;
    D_803F6680.unk33 = 0;
    D_803F6680.unk35 = 0;
    D_803F6680.unk29 = 1;
    D_803F6680.unk16 = 0x1E;
    D_803F6680.unk2 = 0;
    D_803F6680.unk18 = 0;
    D_803F6680.unk2A = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2B = 0;
    D_803F6680.unk1A = 0;
    D_803F6680.unk1E = 0xFF;
    D_803F6680.unk20 = 1;
    D_803F6680.unk22 = 0;
    D_803F6680.unk24 = 0;
    D_803F6706 = 0;
    D_803F6708 = 0;
    D_803F670A = 0x500;
    D_803F670C = 0x3C0;
    D_803C0422 = 1;
    D_801D9ED4 = 6;
    D_803F6716 = D_8023F2A0.unkD;
    D_803F6718 = D_8023F2A0.unkC;
    D_803F671A = D_8023F2A0.unkE;
}

void func_8038F8C8_7A0F78(void) {
    generate_stars();
    func_801337DC(0, 15.0f, 20.0f, 6.0f);

    D_803F6680.unk2D = 0;
    D_803F6680.unk31 = 0;
    D_803F6680.unk33 = 0;
    D_803F6680.unk35 = 0;
    D_803F6680.unk29 = 0;
    D_803F6680.unk18 = 40;
    D_803F6680.unk16 = 30;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2B = 0;
    D_803F6680.unk1A = 0;
    D_803F6680.unk1E = 0xFF;
    D_803F6680.unk20 = 1;
    D_803F6680.unk22 = 0;
    D_803F6680.unk24 = 0;
    D_803F6680.unk0 = 1;
    gScreenWidth = 320;
    func_8012A400();
}

void func_8038F968_7A1018(void) {
    D_803F2CE0 = &D_803F34C0[D_803F3330[D_803A8340]];
    D_803F2CE4 = func_8012E78C(D_803F2CE0, 10.0f, 10.0f, 0xC) - 0xC;
    D_803F6680.unk0 = 0;
    D_803F6680.unk27 = 1;
    func_80133BA0(D_8023F2A0.unkC);
    D_803F671C = 1;
}

void func_8038FA00_7A10B0(void) {
    generate_stars();

    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6730;
    D_803F6680.unk8 = 6;
    D_803F6680.unk6 = 2;
    D_803F6680.unk29 = 1;
    D_803F6680.unk18 = 0x14;
    D_803F6680.unk16 = 0x1E;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 1;
    D_803F6680.unk2C = 1;
    D_803F6680.unk1A = 0;
    D_801D9ED4 = 6;
    D_803F6680.unk24 = 0;
    D_803C0422 = 1;
}

void func_8038FAB4_7A1164(void) {
    generate_stars();

    D_803F6680.unk24 = 0;
    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6730;
    D_803F6680.unk8 = 0xC;
    D_803F6680.unk6 = 2;
    D_803F6680.unk29 = 1;
    D_803F6680.unk18 = 0x1E;
    D_803F6680.unk16 = 0x1E;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 1;
    D_803F6680.unk2C = 1;
    D_803F6680.unk1A = 0;
    D_801D9ED4 = 6;
    D_803C0422 = 1;
}

void func_8038FB68_7A1218(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2A = 0;
    D_803C0422 = 0;
}

// load_level
void func_8038FB94_7A1244(s16 arg0) {
    D_803F671C = 0;
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803C0422 = 0;
    gLevelIndex = arg0;
    func_802961D4_6A7884();
    func_8029614C_6A77FC();
    func_802F07E8_701E98(2);
    D_80152E98 = 0;
    D_803E1BC0 = 1;
}

// load_intro
void func_8038FC04_7A12B4(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803C0422 = 0;
    gLevelIndex = DMA_INTRO;
    func_802961D4_6A7884();
    func_8029614C_6A77FC();
    D_80152E98 = 0;
}

void func_8038FC58_7A1308(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803C0422 = 0;
    func_802961D4_6A7884();
    func_8029614C_6A77FC();
    if (D_803F7DD5 != 0) {
        func_802F07E8_701E98(2);
    }
    D_80152E98 = 0;
    D_8028645C = 0;
    D_80204290 = 2;
    func_801337DC(0, 60.0f, 0, 20.0f);
    func_8013385C(60.0f, 0, 20.0f);
}

void func_8038FCF8_7A13A8(void) {
    D_80204290 = 2;
    func_801337DC(0, 5.0f, 20.0f, 0);
    gLevelIndex = SMASHING_START;
    D_803F7DA8.unk2D = 0;
    D_803F63C0 = func_801308E8(D_8023F2A0.unkE, D_803F7DA8.unk2D, &D_803F3330, &D_803F34C0);
    func_8038FC58_7A1308();
}

// initialise game (?)
void func_8038FD74_7A1424(void) {
    reset_cheats();
    D_803F671C = 0;
    func_80133B74(D_8023F2A0.unkD);
    func_80133BA0(D_8023F2A0.unkC);
    D_803E1BC0 = 0;
    D_803C0424 = 0;
    D_803C0426 = 0;

    reset_credits_counters();
    func_801308E8(D_8023F2A0.unkE, 32, &D_80231AA0, &D_80231D5C);
    generate_stars();

    D_803F6704 = 0;
    D_803F7DD4 = 0;
    D_803F6680.unk2E = 0;

    func_80352280_763930();
    func_80352310_7639C0();
    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6790;
    D_803F6680.unk8 = 6;
    D_803F6680.unk24 = 0;
    D_803F6680.unk6 = 6;
    D_803F6680.unk29 = 0;
    D_803F6680.unk16 = 30;
    D_803F6680.unk0 = 1;
    D_803F6680.unk2 = 0;
    D_803F6680.unk18 = 2;
    D_803F6680.unk1A = 0;
    D_803F6680.unk2A = 0;
    D_803F6680.unk2B = 0;
    D_803F6680.unk2C = 0;
    D_803F7DD6 = 0;
    D_803C0422 = 0;
    D_803F2D30.score = 0;
    D_801D9ED4 = 6;
    D_8028645C = 25;
    D_801546D8 = 1600;
    D_801546E0 = 2048;
    D_8015517C = 1.0f;

    func_802F07D0_701E80();
    func_802F07E8_701E98(2);

    if (D_80204288 == 0xA) {
        // load intro
        func_8038FC04_7A12B4();
    } else if (D_80204288 != 0) {
        // load level
        func_8038FB94_7A1244(D_803B6870[D_80204288]);
    }
}

void func_8038FF48_7A15F8(void) {
    D_803F6680.unk26 = 1;
    D_803F6680.unk2 = 0;
    D_803F6714 = 0;
}

// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_8038FF68_7A1618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80391A38_7A30E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80391C90_7A3340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803925D0_7A3C80.s")

void func_8039264C_7A3CFC(void) {
    D_803F66B8.unk40 = 0;
    D_803F66B8.unk42 = 0;
    D_803F66B8.unk48 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80392668_7A3D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803929FC_7A40AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80393024_7A46D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80393238_7A48E8.s")

void func_80395074_7A6724(s32 arg0) {
    D_801D9ED4 = 10;
}

void func_80395088_7A6738(Gfx **arg0, s16 ulx, s16 uly, s16 lrx, s16 lry, u8 color) {
    gDPPipeSync((*arg0)++);
    gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP((*arg0)++, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0);
    gDPSetPrimColor((*arg0)++, 0, 0, color, color, color, 0x80);
    gDPPipeSync((*arg0)++);
    gDPFillRectangle((*arg0)++, ulx, uly, lrx, lry);
}

void func_803951BC_7A686C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_80125FE0(&D_80204278->unk33590[D_80204278->unk38918], arg1 << 16, arg2 << 16, arg3 << 16, 0, 0, 0x8000, 0x8000, 0x9000);
    gSPMatrix((*arg0)++, &D_80204278->unk33590[D_80204278->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->unk38918 += 1;

    gSPDisplayList((*arg0)++, D_04006D00);
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);
    gDPPipeSync((*arg0)++);
}

void func_80395314_7A69C4(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_80125FE0(&D_80204278->unk33590[D_80204278->unk38918], arg1 << 16, arg2 << 16, arg3 << 16, 0, 0, 0x8000, 0x8000, 0x9000);
    gSPMatrix((*arg0)++, &D_80204278->unk33590[D_80204278->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->unk38918 += 1;

    gSPDisplayList((*arg0)++, D_0400A9E0);
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);
    gDPPipeSync((*arg0)++);
}

void func_8039546C_7A6B1C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3) {
}

void func_80395480_7A6B30(void) {
    D_803B66F0.unk0 = gScreenWidth  * 2;
    D_803B66F0.unk2 = gScreenHeight * 2;
    D_803B66F0.unk8 = gScreenWidth  * 2;
    D_803B66F0.unkA = gScreenHeight * 2;

    gDPPipeSync(D_801D9E7C++);
    func_80129594(&D_801D9E7C, D_80204278);
    gDPPipeSync(D_801D9E7C++);

    func_80129300(&D_801D9E7C, D_80204278);

    gSPSegment(D_801D9E7C++, 0x04, osVirtualToPhysical(D_801D9E6C));
    gSPViewport(D_801D9E7C++, &D_803B66F0);
    func_80129430(&D_801D9E7C);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));

    guPerspective(&D_80204278->unk37410, &D_803C0658, 45.0f, 1.0f, 2.0f, 2000.0f, 1.0f);
    guRotateRPY(&D_80204278->unk37450, 0.5f, 0.5f, 0.5f);
    guRotateRPY(&D_80204278->unk374D0, 1.0f, 1.0f, 1.0f);

    guLookAt(&D_80204278->unk37490, D_803B683C.unk0, (D_803F6700 / 700.0f) + D_803B683C.unk4, D_803B683C.unk8, D_803B683C.unkC, D_803B683C.unk10, D_803B683C.unk14, 0.0f, 0.0f, 1.0f);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPFogPosition(D_801D9E7C++, 995, 999);
    gDPSetFogColor(D_801D9E7C++, 0xFF, 0xFF, 0xFF, 0x00);

    gSPDisplayList(D_801D9E7C++, D_01004270);
    gSPClearGeometryMode(D_801D9E7C++, G_FOG);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void func_80395854_7A6F04(void) {
    gDPPipeSync(D_801D9E7C++);
    func_80129594(&D_801D9E7C, D_80204278);
    gDPPipeSync(D_801D9E7C++);

    func_80129300(&D_801D9E7C, D_80204278);

    gSPSegment(D_801D9E7C++, 0x04, osVirtualToPhysical(D_801D9E6C));
    gSPViewport(D_801D9E7C++, &D_803B66F0);

    guPerspective(&D_80204278->unk37410, &D_803C0658, 45.0f, 0.92f, 2.0f, D_803C0388, 1.0f);
    guRotateRPY(&D_80204278->unk37450, 0.5f, 0.5f, 0.5f);
    guRotateRPY(&D_80204278->unk374D0, 1.0f, 1.0f, 1.0f);
    guLookAt(&D_80204278->unk37490, D_803B683C.unk0, D_803B683C.unk4, D_803B683C.unk8, D_803B683C.unkC, D_803B683C.unk10, D_803B683C.unk14, 0.0f, 0.0f, 1.0f);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPDisplayList(D_801D9E7C++, D_01004270);
    gSPClearGeometryMode(D_801D9E7C++, G_FOG);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80395B58_7A7208.s")
// Needs significantly more understanding of C
// void func_80395B58_7A7208(void) {
//     s16 temp_t0;
//     s32 temp_lo;
//     f32 temp_a1;
//     u32 temp_a2;
//
//     temp_a1 = (u32) (40.0f * 1.0f);
//     D_80204278->unk3B638.l.col[0] = temp_a1;
//     D_80204278->unk3B638.l.colc[0] = temp_a1;
//     D_80204278->unk3B638.l.dir[0] = temp_a1;
//     temp_a2 = (u32) (200.0f * 1.0f);
//     D_80204278->unk3B640.l.col[0] = temp_a2;
//     D_80204278->unk3B640.l.colc[0] = temp_a2;
//     D_80204278->unk3B640.l.dir[0] = temp_a2;
//
//     D_80204278->unk3B648 = -0x6D;
//     D_80204278->unk3B649 = 0x5C;
//     D_80204278->unk3B64A = 0x70;
//     // huh
//     temp_t0 = (s16) ((s32) (s16) (D_803F670E + 2) % 0x168);
//     temp_lo = (s32) &D_80152350[(temp_t0 + 0xFF) / 6];
//     D_80204278->unk3B650 = temp_lo;
//     D_80204278->unk3B651 = 8;
//     D_80204278->unk3B652 = 0;
//     D_80204278->unk3B654 = temp_lo;
//     D_80204278->unk3B655 = 0;
//     D_80204278->unk3B656 = 0;
//     D_80204278->unk3B658 = 0x57;
//     D_80204278->unk3B659 = 0x64;
//     D_80204278->unk3B65A = 0;
//
//     gSPNumLights(D_801D9E7C++, 1);
//     gSPLight(D_801D9E7C++, &D_80204278->unk3B640, 1);
//     gSPLight(D_801D9E7C++, &D_80204278->unk3B638, 2);
// }

void func_80395E98_7A7548(Gfx **arg0) {
    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_2CYCLE);
    gDPPipeSync((*arg0)++);
    gSPDisplayList((*arg0)++, D_01004AF8);

    gDPSetRenderMode((*arg0)++, D_803C0640, G_RM_AA_ZB_OPA_SURF2);

    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_01030810);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);

    func_80125FE0(&D_80204278->unk33590[D_80204278->unk38918], 0x3E80000, 0x3E80000, 0x3E80000, 0, 0, 0xC0000, 0xC0000, 0xC0000);
    gSPMatrix((*arg0)++, &D_80204278->unk33590[D_80204278->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->unk38918 += 1;
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);
}

void func_803960F4_7A77A4(Gfx **arg0) {
    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_2CYCLE);
    gDPPipeSync((*arg0)++);
    gSPTexture((*arg0)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP((*arg0)++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
    gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPSetGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING);

    func_80125FE0(&D_80204278->unk33590[D_80204278->unk38918], 0x3E80000, 0x3E80000, 0x3E80000, 0, 0, 0x30000, 0x30000, 0x30000);

    gSPMatrix((*arg0)++, &D_80204278->unk33590[D_80204278->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->unk38918 += 1;
    gSPDisplayList((*arg0)++, D_04005B60);
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);

    gDPPipeSync((*arg0)++);
}

// calls sprite macros
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803962EC_7A799C.s")

void func_8039661C_7A7CCC(s16 arg0, s16 arg1, s16 arg2) {
    struct004 *temp_v0;

    if (arg2 != 0) {
        D_803F66B8.unk44 = 1;
    } else {
        D_803F66B8.unk44 = 0;
    }
    temp_v0 = &D_803B6700[arg0];
    D_803F66B8.unk0 = D_803B683C.unk0;
    D_803F66B8.unk4 = D_803B683C.unk4;
    D_803F66B8.unk8 = D_803B683C.unk8;
    D_803F66B8.unkC = D_803B683C.unkC;
    D_803F66B8.unk10 = D_803B683C.unk10;
    D_803F66B8.unk14 = D_803B683C.unk14;
    D_803F66B8.unk30 = 0;
    D_803F66B8.unk34 = 0;
    D_803F66B8.unk38 = arg1;
    D_803F66B8.unk3C = arg1;
    D_803F66B8.unk40 = 1;
    D_803F66B8.unk42 = 1;
    D_803F66B8.unk18 = temp_v0->unk0;
    D_803F66B8.unk1C = temp_v0->unk4;
    D_803F66B8.unk20 = temp_v0->unk8;
    D_803F66B8.unk24 = temp_v0->unkC;
    D_803F66B8.unk28 = temp_v0->unk10;
    D_803F66B8.unk2C = temp_v0->unk14;
    D_803F6680.unk6 = (*(s16*)&D_803F6680.unk8); // FIXME?
}

s32 func_80396714_7A7DC4(void) {
    if ((D_803F66B8.unk40 == 0) && (D_803F66B8.unk42 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80396748_7A7DF8(void) {
    if (((*D_802910D0 & CONT_START) && (D_802912DE == 1)) ||
        ((*D_802910D0 & CONT_A) && (D_802912DF == 1))) {
          play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
          D_803F66AF = (u8)1;
          return 1;
    } else {
        return 0;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803967D4_7A7E84.s")
// void func_803967D4_7A7E84(u16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
//     s32 sp4C;
//     s32 sp40;
//     f32 temp_f10_2;
//     f32 temp_f12;
//     f32 temp_f16;
//     f32 temp_f2;
//     f32 temp_f2_2;
//     f32 temp_f2_3;
//     s32 temp_f10;
//     s32 temp_f16_2;
//     s32 temp_s1;
//     s32 temp_s2;
//     s32 temp_t3;
//     s32 temp_t5;
//     s32 temp_t6;
//     s32 temp_t9;
//
//     s32 phi_t4;
//     s32 phi_t4_2;
//
//     gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
//     gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
//
//     if (arg9 == 1) {
//         if (arg5 != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C3A40, 32, 32, 1.0f, 1.0f, 0, 0, arg0, arg1 + 1);
//
//         if (arg6 != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4A40, 32, 32, 1.0f, 1.0f, 0, 0, arg0, arg1 + 32);
//
//         if (arg8 != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, 1.0f, 1.0f, 0, 0, arg0 + 0xC, arg1 + 0x3A);
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, 1.0f, 1.0f, 1, 0, arg0 - 0xC, arg1 + 0x3A);
//
//         if (arg7 != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, 1.0f, 1.0f, 0, 0, arg0 + 0x1A, arg1 + 0x1C);
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, 1.0f, 1.0f, 1, 0, arg0 - 0x1A, arg1 + 0x1C);
//         return;
//     }
//
//     if (arg5 != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//     }
//
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C3A40, 0x20, 0x20, 0.5f, 0.5f, 0, 0, arg0, arg1);
//
//     if (arg6 != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//     }
//
//     temp_f2 = (f32) arg1;
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4A40, 0x20, 0x20, 0.5f, 0.5f, 0, 0, arg0, (u32) (temp_f2 + (32.0f * 0.5f)));
//
//     if (arg8 != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//     }
//
//     temp_f2_2 = 12.0f * 0.5f;
//     temp_f12 = (f32) (s16) arg0;
//     temp_t9 = (u32) (temp_f2 + (58.0f * 0.5f)) & 0xFFFF;
//     sp40 = temp_t9;
//     sp4C = temp_f12;
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, 0.5f, 0.5f, 0, 0, (u32) (temp_f12 + temp_f2_2), temp_t9);
//     temp_f16 = ( f32) sp4C - temp_f2_2; // bitwise
//     temp_f10 = (s32) temp_f16;
//
// //     if ((ERROR(cfc1) & 0x78) != 0) {
// //         if ((ERROR(cfc1) & 0x78) == 0) {
// //             phi_t4 = (s32) (temp_f16 - 2.1474836e9f) | 0x80000000;
// //         } else {
// // loop_26:
// //             phi_t4 = -1;
// //         }
// //     } else {
// //         phi_t4 = temp_f10;
// //         if (temp_f10 < 0) {
// //             goto loop_26;
// //         }
// //     }
//
//     // func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, phi_t4, sp40);
//
//     if (arg7 != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, arg2, arg3, arg4, 0x14);
//     }
//
//     temp_f2_3 = 26.0f * 0.5f;
//     temp_t5 = (u32) (temp_f2 + (28.0f * 0.5f)) & 0xFFFF;
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, 0.5f, 0.5f, 0, 0, (u32) ((f32) sp4C + temp_f2_3), temp_t5);
//     temp_f10_2 = (f32) sp4C - temp_f2_3; // bitwise
//     temp_f16_2 = (s32) temp_f10_2;
// //     if ((ERROR(cfc1) & 0x78) != 0) {
// //         if ((ERROR(cfc1) & 0x78) == 0) {
// //             phi_t4_2 = (s32) (temp_f10_2 - 2.1474836e9f) | 0x80000000;
// //         } else {
// // loop_34:
// //             phi_t4_2 = -1;
// //         }
// //     } else {
// //         phi_t4_2 = temp_f16_2;
// //         if (temp_f16_2 < 0) {
// //             goto loop_34;
// //         }
// //     }
//
//     // func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, phi_t4_2, temp_t5);
// }
