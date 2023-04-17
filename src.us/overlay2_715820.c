#include <ultra64.h>
#include "common.h"


// ========================================================
// externs
// ========================================================

extern u8  D_803F2DA7; // FIXME: D_803F2D50.unkA7

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

struct116 D_803E2930[256]; // 0x8 each
struct073 D_803E3130[256]; // 0x18 each

u8   D_803E4930[104];
u8   D_803E4998[104];
u16  D_803E4A00[100];
s16  D_803E4AC8;
s32  D_803E4ACC; // unused
s8   D_803E4AD0[256];

s8   D_803E4BD0;
s8   D_803E4BD1;
s8   D_803E4BD2;
s16  D_803E4BD4;

// ========================================================
// .text
// ========================================================

void func_80304170_715820(void) {
    s16 i;
    for (i = 0; i < 256; i++) {
        // was there debug stuff here?
    }
}

void func_80304194_715844(void) {
    s16 i;
    for (i = 0; i < 256; i++) {
        D_803E3130[i].unk0 = 0;
        D_803E3130[i].unk4 = 0;
        D_803E3130[i].unk8 = 0;
        D_803E3130[i].unkC = 0;
        D_803E3130[i].unk10 = 0;
        D_803E3130[i].unk2 = 0;
        D_803E3130[i].unk14 = NULL;
        D_803E4AD0[i] = 1; // free?
    }
}

void func_803041FC_7158AC(void) {
    s16 i;
    Gfx *dl;

    s32 var_a2;
    s32 var_a3;
    s32 var_t4;
    s32 var_t5;

    u8 *imgBase;

    s16 foo;

    s16 temp_a0;
    s16 tmp;

    static s16 D_803E4BD6;
    static s16 D_803E4BD8;
    static s16 D_803E4BDA;

    if (foo = D_80152350.unk2D0[D_803E4BD4] / 2) {}

    D_803E4BD4 = D_803E4BD4 + 10;
    D_803E4BD4 = D_803E4BD4 % 360;

    // is this some hack added "later" to match geo to terrain map?
    for (i = 0; i < D_803E4AC8; i++) {
        temp_a0 = D_803C0740[D_803E4930[i]][D_803E4998[i]].unk6 << 2;
        if (D_802294D0[D_803E4A00[i]].v.ob[2] < temp_a0) {
            D_802294D0[D_803E4A00[i]].v.ob[2]++;
        } else if (temp_a0 < D_802294D0[D_803E4A00[i]].v.ob[2]) {
            D_802294D0[D_803E4A00[i]].v.ob[2]--;
        }
    }

    D_803E4BD6 = D_803E4BD6 + 2;
    D_803E4BD6 = D_803E4BD6 % 360;

    D_803E4BD8 = D_803E4BD8 + 3;
    D_803E4BD8 = D_803E4BD8 % 360;

    D_803E4BDA = D_803E4BDA + 10;
    D_803E4BDA = D_803E4BDA % 360;

    D_803E4BD0 = D_803E4BD0 + 1;
    D_803E4BD0 = D_803E4BD0 % 4;

    D_803E4BD2 = D_803E4BD2 + 1;
    D_803E4BD2 = D_803E4BD2 % 9;

    if (D_803E4BD0 & 1) {
        D_803E4BD1 = guRandom() % 3;
    }

    imgBase = D_0102C810;

    for (i = 0; i < D_803F2CA6; i++) {
        // if free?
        if ((D_803E4AD0[D_803E3130[i].unk2]) == 1) {

            dl = D_803E3130[i].unk14;

            tmp = D_803E3130[i].unk2;
            if (tmp >= 300) {
                if (tmp == 300) {
                    var_t4 = 0;
                    var_t5 = FTOFIX32(1.0);
                }
                var_a2 = var_t4 >> 1;
                var_a3 = var_t5 >> 1;
            } else {
                var_t4 = D_803E2930[tmp].unk0 << 4;
                var_t5 = D_803E2930[tmp].unk4 << 4;

                var_a2 = var_t4 >> 1;
                var_a3 = var_t5 >> 1;
            }

            D_803E3130[i].unk4 += var_t4;
            D_803E3130[i].unk8 += var_t5;

            D_803E3130[i].unkC += var_a2;
            D_803E3130[i].unk10 += var_a3;

            if (D_803E3130[i].unk4 > FTOFIX32(128.0)) {
                D_803E3130[i].unk4 -= FTOFIX32(128.0);
            }
            if (D_803E3130[i].unk8 > FTOFIX32(128.0)) {
                D_803E3130[i].unk8 -= FTOFIX32(128.0);
            }
            if (D_803E3130[i].unkC > FTOFIX32(128.0)) {
                D_803E3130[i].unkC -= FTOFIX32(128.0);
            }
            if (D_803E3130[i].unk10 > FTOFIX32(128.0)) {
                D_803E3130[i].unk10 -= FTOFIX32(128.0);
            }

            switch (D_803E3130[i].unk1) {
            case 7:
                gDPSetPrimColor(dl++, 128, 128, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2DA7);
                break;
            case 0:
                gDPSetTileSize(
                    dl++,
                    5,
                    D_803E3130[i].unk4 >> 16,
                    D_803E3130[i].unk8 >> 16,
                    124,
                    124);
                gDPSetTileSize(
                    dl++,
                    6,
                    D_803E3130[i].unkC >> 16,
                    D_803E3130[i].unk10 >> 16,
                    124,
                    124);
                gDPSetPrimColor(dl++, 128, 128, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2DA7);
                break;
            case 1:
            case 11:
                gDPSetTileSize(
                    dl++,
                    G_TX_RENDERTILE,
                    D_803E3130[i].unk4 >> 16,
                    D_803E3130[i].unk8 >> 16,
                    124,
                    124);
                gDPSetTileSize(
                    dl++,
                    1,
                    (D_803E3130[i].unk4 >> 16) >> 1,
                    (D_803E3130[i].unk8 >> 16) >> 1,
                    60,
                    60);
                gDPSetTileSize(
                    dl++,
                    2,
                    (D_803E3130[i].unk4 >> 16) >> 2,
                    (D_803E3130[i].unk8 >> 16) >> 2,
                    28,
                    28);
                break;
            case 2:
                gDPSetTileSize(
                    dl++,
                    1,
                    D_80152350.unk2D0[D_803E4BD6] >> 2,
                    D_80152350.unk384[D_803E4BD6] >> 2,
                    124,
                    124);
                gDPSetTileSize(
                    dl++,
                    2,
                    D_80152350.unk2D0[(s16) (290 - D_803E4BD8)] >> 2,
                    D_80152350.unk384[(s16) (290 - D_803E4BD8)] >> 2,
                    124,
                    124);
                gDPSetPrimColor(dl++, 128, 128, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2DA7);
                break;
            case 3:
                gDPSetTileSize(
                    dl++,
                    5,
                    D_803E3130[i].unk4 >> 16,
                    D_803E3130[i].unk8 >> 16,
                    124,
                    124);
                gDPSetTileSize(
                    dl++,
                    6,
                    D_803E3130[i].unkC >> 16,
                    D_803E3130[i].unk10 >> 16,
                    124,
                    124);
                gDPSetPrimColor(dl++, 128, 128, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2DA7);
                break;
            case 4:
                gDPSetTileSize(
                    dl++,
                    G_TX_RENDERTILE,
                    D_803E3130[i].unk4 >> 16,
                    D_803E3130[i].unk8 >> 16,
                    124,
                    124);
                gDPSetTileSize(
                    dl++,
                    1,
                    (D_803E3130[i].unk4 >> 16) >> 1,
                    (D_803E3130[i].unk8 >> 16) >> 1,
                    60,
                    60);
                gDPSetTileSize(
                    dl++,
                    2,
                    (D_803E3130[i].unk4 >> 16) >> 2,
                    (D_803E3130[i].unk8 >> 16) >> 2,
                    28,
                    28);
                break;
            case 5:
                gDPSetTileSize(
                    dl++,
                    6,
                    D_80152350.unk2D0[D_803E4BDA] >> 7,
                    D_803E3130[i].unk8 >> 16,
                    60,
                    60);
                break;
            case 6:
                gDPSetTileSize(
                    dl++,
                    1,
                    D_803E3130[i].unk4 >> 16,
                    D_803E3130[i].unk8 >> 16,
                    60,
                    60);
                break;
            case 8:
                if ((var_t4 == 0) && (var_t5 == 0)) {
                    gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(imgBase));
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(dl++);
                    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(dl++);
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(dl++, 6, 0, 0, 124, 124);
                } else {
                    gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(imgBase + (D_803E4BD0 << 0xA)));
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(dl++);
                    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(dl++);
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(dl++, 6, 0, 0, 124, 124);
                }
                break;
            case 10:
                if ((var_t4 != 0) || (var_t5 != 0)) {
                    gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(imgBase + 0x1C00 + (D_803E4BD1 << 0xA))); // 0x80001C00 + D_0102C810
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(dl++);
                    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(dl++);
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(dl++, 6, 0, 0, 124, 124);
                } else {
                    gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(imgBase + 0x1C00));
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(dl++);
                    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(dl++);
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(dl++, 6, 0, 0, 124, 124);
                }
                break;
            case 9:
                if ((var_t4 != 0) || (var_t5 != 0)) {
                    gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(imgBase + 0x1000 + ((D_803E4BD2 / 3) << 0xA))); // 0x80001000 + D_0102C810)); // OS_PHYSICAL_TO_K0
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(dl++);
                    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(dl++);
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(dl++, 6, 0, 0, 124, 124);
                } else {
                    gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(imgBase + 0x1000));
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(dl++);
                    gDPLoadBlock(dl++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(dl++);
                    gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(dl++, 6, 0, 0, 124, 124);
                }
                break;
            }
        }
    }
}
