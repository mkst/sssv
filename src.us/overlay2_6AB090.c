#include <ultra64.h>

#include "common.h"


void func_802999E0_6AB090(DisplayList *arg0) {
    guPerspective(&arg0->unk37410, &D_803C0658, D_803F2D50.unkE0, 1.0f, D_803F2D50.unkC, D_803F2D50.unkE, 1.0f);
    guRotateRPY(&arg0->unk37450, 0.5f, 0.5f, 0.5f);
    guRotateRPY(&arg0->unk374D0, 1.0f, 1.0f, 1.0f);
    func_8033F380_750A30();
}

void func_80299AA8_6AB158(DisplayList *arg0, Gfx **arg1) {
    gSPMatrix((*arg1)++, &arg0->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk37450, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk37490, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk374D0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPPerspNormalize((*arg1)++, D_803C0658);
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_80299B68_6AB218.s")
// void func_80299B68_6AB218(s32 arg0) {
//
//     struct025 *temp_v1;
//     struct039 *temp_v1_2;
//
//     gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 16, &D_800DCC20 + (((s32) D_803C063C >> 1) << 9));
//     gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0180, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync(D_801D9E7C++);
//     gDPLoadTile(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 4*(15.5), 4*(31));
//     gDPPipeSync(D_801D9E7C++);
//     gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0180, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize(D_801D9E7C++, 6, 0, 0, 4*(31), 4*(31));
//
//     gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 8, D_01021BB0);
//     gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x01C0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
//     gDPLoadSync(D_801D9E7C++);
//     gDPLoadTile(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 4*(7.5), 4*(15));
//     gDPPipeSync(D_801D9E7C++);
//     gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01C0, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
//     gDPSetTileSize(D_801D9E7C++, 5, 0, 0, 4*(15), 4*(15));
//
//     gSPDisplayList(D_801D9E7C++, D_010043A0);
//
//     temp_v1 = &D_803F28E0[D_803F2A98]; // * 0xDC) + &D_803F28E0;
//     func_8029A3B0_6ABA60(temp_v1->unk74, temp_v1->unk78, temp_v1->unk7C);
//
//     D_803A0500 = 0;
//     while (D_803C0660[D_803A0500].unk0 != 0x63) {
//         temp_v1_2 = &D_803C0660[D_803A0500];
//         gSPDisplayList(D_801D9E7C++, &D_80205410[(temp_v1_2->unk0 * 0x18) + (temp_v1_2->unk2 * 4)]);
//         D_803A0500 += 1;
//     }
//
//     gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_80299E84_6AB534.s")

void func_8029A32C_6AB9DC(s32 arg0) {
}

s32 func_8029A334_6AB9E4(s32 arg0, s32 arg1, s32 arg2) {
    arg0 >>= 6;
    arg1 >>= 6;
    arg0 = (arg0 - 4) >> 4;
    arg1 = (arg1 - 8) >> 4;
    if ((arg0 < 0) || (arg0 >= 4) || (arg1 < 0) || (arg1 >= 6)) {
        return 1;
    }
    if ((*(&D_803F28D0 + arg1) & (1 << arg0))) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A3B0_6ABA60.s")

u16 func_8029A52C_6ABBDC(u8 arg0) {
    struct038 *s;
    u16 tmp = arg0 & 0x3F;

    s = &D_800BB210[tmp];
    tmp = s->unk0;
    return tmp;
}

u16 func_8029A568_6ABC18(s16 arg0) {
    s16 temp_v0;
    u16 temp_v1;
    u16 temp_v2;
    u16 temp_v3;
    u16 res;

    temp_v0 = arg0;
    temp_v1 =  ((temp_v0 & 0x003E) >> 2) & 0x3E;
    temp_v2 = (((temp_v0 & 0x07C0) >> 7) << 5) & 0x7C0;
    temp_v3 = (((temp_v0 & 0xF800) >> 12) << 10) & 0xF800;

    res = temp_v1 | temp_v2 | temp_v3;
    return res;
}

// set_fog_factor
void func_8029A5B4_6ABC64(Gfx **dl, u8 r, u8 g, u8 b) {
    // gSPFogPosition((*arg0)++, 1033, 992); // this is not quite right
    gSPFogFactor((*dl)++, 0xBC00F400, 0xF4000D00);
    gDPSetFogColor((*dl)++, r, g, b, 0x00);
}

// set_fog_position_and_color
void func_8029A624_6ABCD4(Gfx **dl) {
    gSPFogPosition((*dl)++, D_803E1CF8.min, D_803E1CF8.max);
    gDPSetFogColor((*dl)++, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 0x00);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A720_6ABDD0.s")

void func_8029ABCC_6AC27C(void) {
    func_80125980(&D_80204278->unk33590[D_80204278->unk38918], 0x1000000, 0x2000000, 0x5780000, 0, 0, 0, 0x20000, 0x20000, 0x20000);
    gSPMatrix(D_801D9E7C++, &D_80204278->unk33590[D_80204278->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->unk38918 += 1;
}
