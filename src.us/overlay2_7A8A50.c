#include <ultra64.h>
#include "common.h"


// ========================================================
// .externs
// ========================================================

extern u8 D_803FDFC0[];
extern u8 D_803FE050[];
extern u8 D_803FE160[];
extern u8 D_803FE1A0[];
extern u8 D_803FE230[];
extern u8 D_803FE2A0[];
extern u8 D_803FE2C0[];
extern u8 D_803FE2D0[];
extern u8 D_803FE300[];
extern u8 D_803FE320[];
extern u8 D_803FE3F0[];
extern u8 D_803FE440[];
extern u8 D_803FE450[];
extern u8 D_803FE480[];
extern u8 D_803FE580[]; // two sections have the same length, therefore same end
extern u8 D_803FE600[];
extern u8 D_803FE610[];
extern u8 D_803FE680[];
extern u8 D_803FE740[];
extern u8 D_803FE770[];
extern u8 D_803FF340[]; // ??
extern u8 D_803FF440[];
extern u8 D_803FF4A0[];
extern u8 D_803FF670[];
extern u8 D_803FF6C0[];
extern u8 D_803FF750[];
extern u8 D_803FF7A0[];
extern u8 D_803FF830[];
extern u8 D_803FF8D0[];
extern u8 D_803FF9D0[];
extern u8 D_803FFB80[];

// ========================================================
// .data
// ========================================================

struct046 D_803B6890_7C7F40[33] = {
    { _7D1AD0_ROM_START, _7D1AD0_ROM_END, overlay2_BSS_END, D_803FF340, overlay2_BSS_END, },
    { _7D2F50_ROM_START, _7D2F50_ROM_END, overlay2_BSS_END, D_803FE2D0, overlay2_BSS_END, },
    { _7D3360_ROM_START, _7D3360_ROM_END, overlay2_BSS_END, D_803FE610, overlay2_BSS_END, },
    { _7D3AB0_ROM_START, _7D3AB0_ROM_END, overlay2_BSS_END, D_803FE680, overlay2_BSS_END, },
    { _7D4270_ROM_START, _7D4270_ROM_END, overlay2_BSS_END, D_803FE480, overlay2_BSS_END, },
    { _7D4830_ROM_START, _7D4830_ROM_END, overlay2_BSS_END, D_803FE050, overlay2_BSS_END, },
    { _7D49C0_ROM_START, _7D49C0_ROM_END, overlay2_BSS_END, D_803FE740, overlay2_BSS_END, },
    { _7D5240_ROM_START, _7D5240_ROM_END, overlay2_BSS_END, D_803FE2A0, overlay2_BSS_END, },
    { _7D5620_ROM_START, _7D5620_ROM_END, overlay2_BSS_END, D_803FE230, overlay2_BSS_END, },
    { _7D5990_ROM_START, _7D5990_ROM_END, overlay2_BSS_END, D_803FE2C0, overlay2_BSS_END, },
    { _7D5D90_ROM_START, _7D5D90_ROM_END, overlay2_BSS_END, D_803FE320, overlay2_BSS_END, },
    { _7D61F0_ROM_START, _7D61F0_ROM_END, overlay2_BSS_END, D_803FE1A0, overlay2_BSS_END, },
    { _7D64D0_ROM_START, _7D64D0_ROM_END, overlay2_BSS_END, D_803FE160, overlay2_BSS_END, },
    { _7D6770_ROM_START, _7D6770_ROM_END, overlay2_BSS_END, D_803FE580, overlay2_BSS_END, },
    { _7D6E30_ROM_START, _7D6E30_ROM_END, overlay2_BSS_END, D_803FE600, overlay2_BSS_END, },
    { _7D7570_ROM_START, _7D7570_ROM_END, overlay2_BSS_END, D_803FE3F0, overlay2_BSS_END, },
    { _7D7AA0_ROM_START, _7D7AA0_ROM_END, overlay2_BSS_END, D_803FE770, overlay2_BSS_END, },
    { _7D8350_ROM_START, _7D8350_ROM_END, overlay2_BSS_END, D_803FE450, overlay2_BSS_END, },
    { _7D88E0_ROM_START, _7D88E0_ROM_END, overlay2_BSS_END, D_803FE480, overlay2_BSS_END, },
    { _7D8EA0_ROM_START, _7D8EA0_ROM_END, overlay2_BSS_END, D_803FE300, overlay2_BSS_END, },
    { _7D92E0_ROM_START, _7D92E0_ROM_END, overlay2_BSS_END, D_803FE440, overlay2_BSS_END, },
    { _7D9860_ROM_START, _7D9860_ROM_END, overlay2_BSS_END, D_803FE580, overlay2_BSS_END, },
    { _7D9F20_ROM_START, _7D9F20_ROM_END, overlay2_BSS_END, D_803FDFC0, overlay2_BSS_END, },

    { _7DA020_ROM_START, _7DA020_ROM_END, D_803FF340, D_803FF440, D_803FF340, },
    { _7DA120_ROM_START, _7DA120_ROM_END, D_803FF340, D_803FF6C0, D_803FF340, },
    { _7DA4A0_ROM_START, _7DA4A0_ROM_END, D_803FF340, D_803FF830, D_803FF340, },
    { _7DA990_ROM_START, _7DA990_ROM_END, D_803FF340, D_803FF7A0, D_803FF340, },
    { _7DADF0_ROM_START, _7DADF0_ROM_END, D_803FF340, D_803FF8D0, D_803FF340, },
    { _7DB380_ROM_START, _7DB380_ROM_END, D_803FF340, D_803FFB80, D_803FF340, },
    { _7DBBC0_ROM_START, _7DBBC0_ROM_END, D_803FF340, D_803FF9D0, D_803FF340, },
    { _7DC250_ROM_START, _7DC250_ROM_END, D_803FF340, D_803FF670, D_803FF340, },
    { _7DC580_ROM_START, _7DC580_ROM_END, D_803FF340, D_803FF750, D_803FF340, },
    { _7DC990_ROM_START, _7DC990_ROM_END, D_803FF340, D_803FF4A0, D_803FF340, },
};

s16 D_803B6B24_7C81D4[3] = {0, 23, 10};

// where is this used?
s16 D_803B6B2C_7C81DC = -1;

// FIXME
s16 D_803B6B30_7C81E0[8] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x001e, 0x0145, 0x6000, 0x0000,
};

typedef struct {
    f32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} tbd;  // size 0xC

tbd D_803B6B40_7C81F0[] = {
    { 1.0f,    61,   312, 24576,     0 },
    { 1.0f,    67,   321, 24576,     0 },
    { 1.0f,    83,   317, 24576,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,     1,   332, 32767,     0 },
    { 1.0f,    56,   263, 32767,     0 },
    { 0.71f,  128,   336, 32767,     0 },
    { 1.0f,   157,   337, 32767,     0 },
    { 1.0f,   185,   306, 32767,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    87,   309, 32767,     0 },
    { 1.0f,    87,   300, 24575,     0 },
    { 0.87f,  117,   310, 32767,     0 },
    { 1.0f,   117,   300, 24575,     0 },
    { 0.87f,  131,   311, 32767,     0 },
    { 1.0f,   131,   300, 24575,     0 },
    { 0.87f,   -1,     0,     0,     0 },
    { 0.0f,    25,   334, 32767,     0 },
    { 1.0f,    60,   333, 32767,     0 },
    { 1.0f,    70,   330, 32767,     0 },
    { 1.0f,   174,   331, 32767,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,     1,   329, 32767,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,     9,   263, 25088,     0 },
    { 0.81f,   19,   263, 26624,     0 },
    { 0.803f,  28,   263, 28672,     0 },
    { 0.793f,  38,   263, 27136,     0 },
    { 0.78f,   48,   263, 28672,     0 },
    { 0.793f,  60,   263, 24576,     0 },
    { 0.77f,   70,   263, 28672,     0 },
    { 0.79f,   94,   302, 32767,     0 },
    { 1.0f,   100,   299, 18432,     0 },
    { 0.707f,  -1,     0,     0,     0 },
    { 0.0f,     1,   327, 16384,     0 },
    { 1.0f,    13,   327, 24576,     0 },
    { 1.0f,    25,   327, 24576,     0 },
    { 1.0f,    36,   327, 24576,     0 },
    { 1.0f,    48,   327, 24576,     0 },
    { 1.0f,    66,   327, 24576,     0 },
    { 1.0f,    79,   327, 24576,     0 },
    { 1.0f,    94,   327, 24576,     0 },
    { 0.97f,  110,   327, 14848,     0 },
    { 0.94f,  129,   327, 12288,     0 },
    { 0.92f,  151,   327, 10240,     0 },
    { 0.89f,  187,   318, 32767,     0 },
    { 1.0f,   206,   302, 32767,     0 },
    { 1.0f,   230,   308, 32767,     0 },
    { 1.0f,   255,   301, 32767,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    60,   324, 32767,     0 },
    { 1.0f,    85,   301, 22528,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    27,   323, 25856,     0 },
    { 1.0f,    46,   328, 24576,     0 },
    { 1.0f,    68,   326, 14199,     0 },
    { 1.0f,    74,   326, 14199,     0 },
    { 1.0f,    84,   326, 14199,     0 },
    { 1.25f,   92,   326,  8465,     0 },
    { 1.0f,   105,   305, 32767,     0 },
    { 1.0f,   128,   307, 22391,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    13,   319, 32767,     0 },
    { 1.0f,    36,   320, 32767,     0 },
    { 1.0f,    46,   300, 28671,     0 },
    { 0.82f,   65,   322, 32767,     0 },
    { 1.0f,    94,   308, 32767,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    48,   343, 32767,     0 },
    { 1.0f,    53,   326, 15018,     0 },
    { 1.0f,    58,   326, 15018,     0 },
    { 1.0f,    64,   303, 16384,     0 },
    { 1.0f,    68,   326, 15018,     0 },
    { 1.0f,    80,   326, 15018,     0 },
    { 1.0f,    91,   326, 15018,     0 },
    { 1.0f,   106,   326, 15018,     0 },
    { 1.0f,   117,   326, 15018,     0 },
    { 1.0f,   123,   338, 32767,     0 },
    { 1.0f,   130,   326, 15018,     0 },
    { 1.0f,   142,   313, 28672,     0 },
    { 1.0f,   144,   326, 15018,     0 },
    { 1.0f,   148,   314, 28672,     0 },
    { 1.0f,   153,   315, 28672,     0 },
    { 1.0f,   156,   326, 15018,     0 },
    { 1.0f,   156,   316, 28672,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    24,   303, 16384,     0 },
    { 1.0f,    50,   338, 32767,     0 },
    { 0.79f,   82,   340, 10649,     0 },
    { 1.0f,    96,   341, 10649,     0 },
    { 1.0f,   139,   342, 10649,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,    61,   304, 25668,     0 },
    { 1.04f,   88,   304, 24576,     0 },
    { 0.95f,   96,   304, 24029,     0 },
    { 1.2f,   104,   304, 23483,     0 },
    { 1.0f,    -1,     0,     0,     0 },
    { 0.0f,   109,   344, 32767,     0 },
    { 1.0f,   128,   339, 32767,     0 },
    { 1.0f,   172,   140, 18432,     0 },
    { 1.0f,    -1,     0,     0,     0 },
};

#if 0
// do we need padding here
s32 junk_padding = 0; //0000 0000

extern u8 D_803B6B2C[];
extern u8 D_803B6B38[];
extern u8 D_803B6B74[];
extern u8 D_803B6BBC[];
extern u8 D_803B6C10[];
extern u8 D_803B6C4C[];
extern u8 D_803B6C64[];
extern u8 D_803B6CDC[];
extern u8 D_803B6D9C[];
extern u8 D_803B6DC0[];
extern u8 D_803B6E2C[];
extern u8 D_803B6E74[];
extern u8 D_803B6F4C[];
extern u8 D_803B6F94[];
extern u8 D_803B6FD0[];
extern u8 D_803FDF60[];
extern u8 D_803FDFF8[];
extern u8 D_803FE100[];
extern u8 D_803FE148[];
extern u8 D_803FE1DC[];
extern u8 D_803FE244[];
extern u8 D_803FE264[];
extern u8 D_803FE27C[];
extern u8 D_803FE2A4[];
extern u8 D_803FE2C8[];
extern u8 D_803FE39C[];
extern u8 D_803FE3E4[];
extern u8 D_803FE3FC[];
extern u8 D_803FE428[];
extern u8 D_803FE42C[];
extern u8 D_803FE52C[];
extern u8 D_803FE5A0[];
extern u8 D_803FE5B8[];
extern u8 D_803FE620[];
extern u8 D_803FE6EC[];
extern u8 D_803FE71C[];
extern u8 D_803FF2E8[];
extern u8 D_803FF3E0[];
extern u8 D_803FF440[];
extern u8 D_803FF618[];
extern u8 D_803FF668[];
extern u8 D_803FF6F8[];
extern u8 D_803FF740[];
extern u8 D_803FF7DC[];
extern u8 D_803FF870[];
extern u8 D_803FF974[];
extern u8 D_803FFB28[];

// these are addresses within the data right at the end of the ROM.
struct110 D_803B7000_7C86B0[33] = {
    { D_803FF2E8, D_803B6B2C, },
    { D_803FE27C, D_803B6B38, },
    { D_803FE5B8, D_803B6B74, },
    { D_803FE620, D_803B6BBC, },
    { D_803FE428, D_803B6C10, },
    { D_803FDFF8, D_803B6C4C, },
    { D_803FE6EC, NULL, },
    { D_803FE244, NULL, },
    { D_803FE1DC, NULL, },
    { D_803FE264, NULL, },
    { D_803FE2C8, NULL, },
    { D_803FE148, NULL, },
    { D_803FE100, NULL, },
    { D_803FE52C, D_803B6C64, },
    { D_803FE5A0, D_803B6CDC, },
    { D_803FE39C, D_803B6D9C, },
    { D_803FE71C, D_803B6DC0, },
    { D_803FE3FC, D_803B6E2C, },
    { D_803FE42C, D_803B6E74, },
    { D_803FE2A4, D_803B6F4C, },
    { D_803FE3E4, D_803B6F94, },
    { D_803FE52C, NULL, },
    { D_803FDF60, NULL, },
    { D_803FF3E0, NULL, },
    { D_803FF668, NULL, },
    { D_803FF7DC, NULL, },
    { D_803FF740, NULL, },
    { D_803FF870, NULL, },
    { D_803FFB28, NULL, },
    { D_803FF974, NULL, },
    { D_803FF618, D_803B6FD0, },
    { D_803FF6F8, NULL, },
    { D_803FF440, NULL, },
};

extern Gfx D_0400BBC0_D35F0[];
extern Gfx D_0400BBC0_D35F0D_0400BF20_D3950[];
extern Gfx D_0400CD48[];
extern Gfx D_0400DFA0_D59D0[];
extern Gfx D_0400E750_D6180[];
extern Gfx D_0400E920[];
extern Gfx D_0400EA20[];
extern Gfx D_0400EA20[];
extern Gfx D_0400EB60[];
extern Gfx D_0400EB60[];
extern Gfx D_0400ED28[];
extern Gfx D_0400ED28[];
extern Gfx D_0400F0A0[];
extern Gfx D_0400F0A0[];
extern Gfx D_0400F1E0[];
extern Gfx D_0400F1E0[];
extern Gfx D_0400F398[];
extern Gfx D_0400F398[];
extern Gfx D_0400F700[];
extern Gfx D_0400F700[];
extern Gfx D_0400FE60[];
extern Gfx D_0400FE60[];
extern Gfx D_04010080[];
extern Gfx D_04010080[];
extern Gfx D_040104C0[];
extern Gfx D_040104C0[];
extern Gfx D_04010710[];
extern Gfx D_04010A70[];
extern Gfx D_04011868[];
extern Gfx D_04012400[];
extern Gfx D_05000180_7F910[];
extern Gfx D_050004E0_7FC70[];
extern Gfx D_05000880_978A0[];
extern Gfx D_05000F90_97FB0[];
extern Gfx D_05001308_80A98[];
extern Gfx D_05001390_983B0[];
extern Gfx D_050016D0_80E60[];
extern Gfx D_05001A30_811C0[];
extern Gfx D_05002828[];
extern Gfx D_050033C0_82B50[];
extern Gfx D_05004650_83DE0[];
extern Gfx D_05004E00_84590[];
extern Gfx D_05004FD0_84760[];

// Dan Danger display lists
Gfx **D_803B7108_7C87B8[5][10] = {
    {
        D_05000180_7F910, D_050004E0_7FC70, D_05001308_80A98, D_050016D0_80E60, D_05001A30_811C0,
        D_05002828, D_050033C0_82B50, D_05004650_83DE0, D_05004E00_84590, D_05004FD0_84760,
    },
    {
        D_0400BBC0_D35F0, D_0400BBC0_D35F0D_0400BF20_D3950, D_0400CD48, D_04010710, D_04010A70,
        D_04011868, D_04012400, D_0400DFA0_D59D0, D_0400E750_D6180, D_0400E920,
    },
    {
        D_0400EB60, D_0400ED28, D_0400F0A0, D_0400F1E0, D_0400F398,
        D_0400F700, D_0400FE60, D_040104C0, D_0400EA20, D_04010080,
    },
    {
        D_0400EB60, D_0400ED28, D_0400F0A0, D_0400F1E0, D_0400F398,
        D_0400F700, D_0400FE60, D_040104C0, D_0400EA20, D_04010080,
    },
    // this is the DMA dude (A, M, D)
    {
                 0,          0,          0,          0,          0,
                 0, D_05001390_983B0, D_05000F90_97FB0,          0, D_05000880_978A0,
    },
};
#endif

// ========================================================
// .bss (D_803F6720 to D_803F7160)
// ========================================================

struct048  D_803F6720[3][10]; // 0x54 each
s16  D_803F70F8[3][10];
s16  D_803F7134[3];
u16  D_803F713C[3];
s16  D_803F7144[3];
s16  D_803F714C[3];

// ========================================================
// .text
// ========================================================

void func_803973A0_7A8A50(s16 arg0) {
    s32 len = D_803B6890_7C7F40[arg0].romEnd - D_803B6890_7C7F40[arg0].romStart;

    osInvalDCache(D_803B6890_7C7F40[arg0].ramStart, D_803B6890_7C7F40[arg0].ramEnd - D_803B6890_7C7F40[arg0].ramStart);
    dma_read(D_803B6890_7C7F40[arg0].romStart, D_803B6890_7C7F40[arg0].ramStart2, len);
}

void func_80397414_7A8AC4(u8 push, f32 x_amt, f32 y_amt, f32 z_amt, f32 x_angle, f32 y_angle, f32 z_angle) {
    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], x_amt, y_amt, z_amt);
    if (push) {
        gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    } else {
        gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    }

    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], y_angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], z_angle, 0.0f, 0.0f, 1.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], x_angle, 1.0f, 0.0f, 0.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

// init/reset something
void func_803976E0_7A8D90(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        D_803F713C[i] = 0;
        D_803F7144[i] = 0;
        D_803F714C[i] = 0;
    }
}

// arg1 is 0 to 2
void func_80397734_7A8DE4(s16 arg0, u8 arg1) {
    s16 i;

    arg0 += D_803B6B24_7C81D4[arg1];
    func_803973A0_7A8A50(arg0);
    for (i = 0; i < 10; i++) {
        D_803F70F8[arg1][i] = 0;
        D_803F6720[arg1][i].unk48 = 0.0f;
        D_803F6720[arg1][i].unk4C = 0.0f;
    }
    D_803F713C[arg1] = 0x3FF;
    D_803F714C[arg1] = 0;
    D_803F7144[arg1] = 0;
    D_803F7134[arg1] = arg0;
}

#if 0
// still junk
void func_80397840_7A8EF0(void) {
    f32 var_f10;
    s16 *temp_s0;
    s16 *temp_s1;
    s16 *temp_s3;
    s16 *temp_s6;
    s16 *temp_s6_2;
    struct110a *var_v0;
    s16 temp_a1;
    s16 i;
    s32 temp_a0;
    s32 temp_s7;
    s16 j;
    u16 *temp_s2;
    u16 temp_t8;
    u16 temp_v1_3;
    struct110c *temp_t0;
    struct048 *temp_v0;
    struct110b *temp_v0_2;
    struct110b *temp_v1;
    struct110b *temp_v1_2;


    for (i = 0; i < 3; i++) {
        // temp_s2 = &D_803F713C[i];
        // temp_s3 = &D_803F7134[i];
        if (D_803F713C[i] != 0) {
            // temp_v1 = D_803B7000_7C86B0[D_803F7134[i]].unk4;
            // temp_s0 = &D_803F7144[i];
            while ((D_803B7000_7C86B0[D_803F7134[i]].unk4 != NULL) && (D_803B7000_7C86B0[D_803F7134[i]].unk4[D_803F7144[i]].unk0 == D_803F714C[i])) {
                // temp_s6 = &D_803F714C[i];
                // while (var_v0->unk0 == D_803F714C[i]) {
                  // var_v0 = &D_803B7000_7C86B0[D_803F7134[i]].unk4[D_803F7144[i]]; //  * 0xC
                  // D_803B7000_7C86B0[D_803F7134[i]].unk4[D_803F7144[i]]
// loop_4:
                    func_8032C508_73DBB8(var_v0->unk2, var_v0->unk4, 0, var_v0->unk8);
                    // temp_v1_2 = D_803B7000_7C86B0[D_803F7134[i]].unk4;
                    D_803F7144[i] += 1;
                    // if (temp_v1_2 != NULL) {
                        // var_v0 = temp_v1_2 + (D_803F7144[i] * 0xC);
                        // if (var_v0->unk0 == D_803F714C[i]) {
                            // goto loop_4;
                        // }
                    // }
                // }
            };

#if 1
            // temp_s6_2 = &D_803F714C[i];
            // j = 0;
            // temp_s7 = i & 0xFF;
            // do {
            for (j = 0; j < 10; j++) {
                // temp_v1_3 = *temp_s2;
                temp_a0 = 1 << j;
                if (D_803F713C[i] & temp_a0) {
                    // temp_v0 = &D_803F6720[i][j]; //(i * 0x348) + (j * 0x54) + ;
                    if (D_803F6720[i][j].unk4C <= D_803F6720[i][j].unk48) {
                        // temp_s1 = (i * 0x14) + (j * 2) + D_803F70F8;
                        // temp_s1 = D_803F70F8[i][j];
                        temp_a1 = D_803F70F8[i][j]; //*temp_s1;
                        temp_t0 = D_803B7000_7C86B0[D_803F7134[i] + j].unk0; // + (j * 8);
                        if (D_803F70F8[i][j] >= temp_t0->unk8) {
                            D_803F713C[i] = D_803F713C[i] & ~temp_a0;
                        } else {
                            // temp_v0_2 = &temp_t0->unk4[temp_a1]; // + (temp_a1 * 0xE);
                            // temp_t8 = temp_v0_2->unkC;
                            // var_f10 = (f32) temp_t8;
                            // if ((s32) temp_t8 < 0) {
                            //     var_f10 += 4294967296.0f;
                            // }
                            func_80397C58_7A9308(
                                 ((temp_t0->unk4[temp_a1].unk4 * 180.0f) / 32768.0f),
                                -((temp_t0->unk4[temp_a1].unk0 * 180.0f) / 32768.0f),
                                -((temp_t0->unk4[temp_a1].unk2 * 180.0f) / 32768.0f),
                                temp_t0->unk4[temp_a1].unk6,
                                temp_t0->unk4[temp_a1].unk8, // M2C_ERROR(/* Unable to find stack arg 0x10 in block */),
                                temp_t0->unk4[temp_a1].unkA, // M2C_ERROR(/* Unable to find stack arg 0x14 in block */),
                                temp_t0->unk4[temp_a1].unkC, // var_f10
                                j,
                                i);
                            // *temp_s1 += 1;
                            D_803F70F8[i][j]++;
                        }
                    }
                }
                // j++; //= (s32) (s16) (j + 1);
            } //while (j < 0xA);
            func_80397D1C_7A93CC(i);
            D_803F714C[i] += 1;
#endif
        }
        //i += 1;
    } //while (i < 3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397840_7A8EF0.s")
#endif

void func_80397B84_7A9234(void) {
    s16 i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 3; k++) {
                D_803F6720[i][j].unk18.unk0[k] = 0.0f;
                D_803F6720[i][j].unk18.unkC[k] = 0.0f;

                D_803F6720[i][j].unk0.unk0[k] = 0.0f;
                D_803F6720[i][j].unk0.unkC[k] = 0.0f;

                D_803F6720[i][j].unk30.unk0[k] = 0.0f;
                D_803F6720[i][j].unk30.unkC[k] = 0.0f;
            }
            D_803F6720[i][j].unk48 = 0.0f;
            D_803F6720[i][j].unk4C = 0.0f;
            D_803F6720[i][j].unk50 = 0;
        }
    }
}

void func_80397C58_7A9308(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7, u8 arg8) {
    struct048 *temp_v0 = &D_803F6720[arg8][arg7];

    temp_v0->unk18.unk0[0] = temp_v0->unk0.unk0[0];
    temp_v0->unk18.unk0[1] = temp_v0->unk0.unk0[1];
    temp_v0->unk18.unk0[2] = temp_v0->unk0.unk0[2];

    temp_v0->unk18.unkC[0] = temp_v0->unk0.unkC[0];
    temp_v0->unk18.unkC[1] = temp_v0->unk0.unkC[1];
    temp_v0->unk18.unkC[2] = temp_v0->unk0.unkC[2];

    temp_v0->unk30.unk0[0] = arg0;
    temp_v0->unk30.unk0[1] = arg1;
    temp_v0->unk30.unk0[2] = arg2;
    temp_v0->unk30.unkC[0] = arg3;
    temp_v0->unk30.unkC[1] = arg4;
    temp_v0->unk30.unkC[2] = arg5;

    temp_v0->unk48 = 0.0f;
    temp_v0->unk4C = arg6;
    temp_v0->unk50 = (u16)1;
}

void func_80397D1C_7A93CC(u8 arg0) {
    f32 pad[4];
    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f16;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f30;
    f32 tmp;
    f32 factor;
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_803F6720[arg0][i].unk50 != 0) {
            factor = 2.0f;
            D_803F6720[arg0][i].unk48 += 1.0f;
            if (D_803F6720[arg0][i].unk4C <= D_803F6720[arg0][i].unk48) {
                D_803F6720[arg0][i].unk0.unk0[0] = D_803F6720[arg0][i].unk30.unk0[0];
                D_803F6720[arg0][i].unk0.unk0[1] = D_803F6720[arg0][i].unk30.unk0[1];
                D_803F6720[arg0][i].unk0.unk0[2] = D_803F6720[arg0][i].unk30.unk0[2];
                D_803F6720[arg0][i].unk0.unkC[0] = D_803F6720[arg0][i].unk30.unkC[0];
                D_803F6720[arg0][i].unk0.unkC[1] = D_803F6720[arg0][i].unk30.unkC[1];
                D_803F6720[arg0][i].unk0.unkC[2] = D_803F6720[arg0][i].unk30.unkC[2];
                D_803F6720[arg0][i].unk50 = 0;
            } else {
                temp_f22 = (D_803F6720[arg0][i].unk30.unk0[0] - D_803F6720[arg0][i].unk18.unk0[0]) / factor;
                temp_f24 = (D_803F6720[arg0][i].unk30.unk0[1] - D_803F6720[arg0][i].unk18.unk0[1]) / factor;
                temp_f26 = (D_803F6720[arg0][i].unk30.unk0[2] - D_803F6720[arg0][i].unk18.unk0[2]) / factor;
                temp_f28 = (D_803F6720[arg0][i].unk30.unkC[0] - D_803F6720[arg0][i].unk18.unkC[0]) / factor;
                temp_f30 = (D_803F6720[arg0][i].unk30.unkC[1] - D_803F6720[arg0][i].unk18.unkC[1]) / factor;
                temp_f16 = (D_803F6720[arg0][i].unk30.unkC[2] - D_803F6720[arg0][i].unk18.unkC[2]) / factor;
                tmp = ((D_803F6720[arg0][i].unk48 / D_803F6720[arg0][i].unk4C) * 180.0f);
                // this is not quite PI (3.14159265359)
                temp_f0 = cosf((SSSV_PI / 180) * tmp);
                D_803F6720[arg0][i].unk0.unk0[0] = (D_803F6720[arg0][i].unk18.unk0[0] + temp_f22) - (temp_f22 * temp_f0);
                D_803F6720[arg0][i].unk0.unk0[1] = (D_803F6720[arg0][i].unk18.unk0[1] + temp_f24) - (temp_f24 * temp_f0);
                D_803F6720[arg0][i].unk0.unk0[2] = (D_803F6720[arg0][i].unk18.unk0[2] + temp_f26) - (temp_f26 * temp_f0);
                D_803F6720[arg0][i].unk0.unkC[0] = (D_803F6720[arg0][i].unk18.unkC[0] + temp_f28) - (temp_f28 * temp_f0);
                D_803F6720[arg0][i].unk0.unkC[1] = (D_803F6720[arg0][i].unk18.unkC[1] + temp_f30) - (temp_f30 * temp_f0);
                D_803F6720[arg0][i].unk0.unkC[2] = (D_803F6720[arg0][i].unk18.unkC[2] + temp_f16) - (temp_f16 * temp_f0);
            }
        }
    }
}

#if 0
void func_80397F5C_7A960C(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5, u8 arg6, u8 arg7) {
    s16 phi_s2;
    s16 i;
    s32 tmp;


    if (arg7 == 2) {
        // if (1) {};
        func_8034C8F8_75DFA8(
            (arg0 >> 16) + D_803F6720[arg7][0].unk0.unkC[0],
            (arg1 >> 16) + D_803F6720[arg7][0].unk0.unkC[1],
            (arg2 >> 16) + D_803F6720[arg7][0].unk0.unkC[2],
            ((arg4 - D_803F6720[arg7][0].unk0.unk0[2]) * 256.0f) / 360.0f,
            D_803A8374_7B9A24, // 0x1034190
            (arg5 << 3) >> 0x10,
            (arg5 << 4) >> 0x10,
            0x9B,
            0,
            0,
            0,
            8,
            1);
    }
    // tmp = (arg5 >> 2) - arg5; // whaat
    tmp = arg5 / 5;
    func_80125FE0(
        &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
        arg0,
        arg1,
        arg2,
        arg3,
        arg4,
        tmp,
        tmp,
        tmp);

    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    func_80397414_7A8AC4(
        0,
        D_803F6720[arg7][0].unk0.unkC[0],
        D_803F6720[arg7][0].unk0.unkC[1],
        D_803F6720[arg7][0].unk0.unkC[2],
        D_803F6720[arg7][0].unk0.unk0[0],
        D_803F6720[arg7][0].unk0.unk0[1],
        D_803F6720[arg7][0].unk0.unk0[2]
    );
    gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][6]); // ->unk18

    if (arg7 != 2) {
        phi_s2 = 4;
        i = 0;
        // is this a for loop?
        do {
            // push
            func_80397414_7A8AC4(
                1,
                D_803F6720[arg7][phi_s2].unk0.unkC[0],
                D_803F6720[arg7][phi_s2].unk0.unkC[1],
                D_803F6720[arg7][phi_s2].unk0.unkC[2],
                D_803F6720[arg7][phi_s2].unk0.unk0[0],
                D_803F6720[arg7][phi_s2].unk0.unk0[1],
                D_803F6720[arg7][phi_s2].unk0.unk0[2]
            );
            gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][i]); // phi_s3

            // no push
            func_80397414_7A8AC4(
                0,
                D_803F6720[arg7][i].unk0.unkC[0],
                D_803F6720[arg7][i].unk0.unkC[1],
                D_803F6720[arg7][i].unk0.unkC[2],
                D_803F6720[arg7][i].unk0.unk0[0],
                D_803F6720[arg7][i].unk0.unk0[1],
                D_803F6720[arg7][i].unk0.unk0[2]
            );
            gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][i]);

            // no push
            func_80397414_7A8AC4(
                0,
                D_803F6720[arg7][i].unk0.unkC[0],
                D_803F6720[arg7][i].unk0.unkC[1],
                D_803F6720[arg7][i].unk0.unkC[2],
                D_803F6720[arg7][i].unk0.unk0[0],
                D_803F6720[arg7][i].unk0.unk0[1],
                D_803F6720[arg7][i].unk0.unk0[2]
            );
            gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][i]);

            gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
            phi_s2++;
        } while (i++ < 2); //?
    }

    func_80397414_7A8AC4(
        1,
        D_803F6720[arg7][1].unk0.unkC[0],
        D_803F6720[arg7][1].unk0.unkC[1],
        D_803F6720[arg7][1].unk0.unkC[2],
        D_803F6720[arg7][1].unk0.unk0[0],
        D_803F6720[arg7][1].unk0.unk0[1],
        D_803F6720[arg7][1].unk0.unk0[2]
    );
    gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][7]);

    if (arg7 != 2) {
        func_80397414_7A8AC4(
            1,
            D_803F6720[arg7][2].unk0.unkC[0],
            D_803F6720[arg7][2].unk0.unkC[1],
            D_803F6720[arg7][2].unk0.unkC[2],
            D_803F6720[arg7][2].unk0.unk0[0],
            D_803F6720[arg7][2].unk0.unk0[1],
            D_803F6720[arg7][2].unk0.unk0[2]
        );
        gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][8]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
    func_80397414_7A8AC4(
        1,
        D_803F6720[arg7][1].unk0.unkC[0],
        D_803F6720[arg7][1].unk0.unkC[1],
        D_803F6720[arg7][1].unk0.unkC[2],
        D_803F6720[arg7][1].unk0.unk0[0],
        D_803F6720[arg7][1].unk0.unk0[1],
        D_803F6720[arg7][1].unk0.unk0[2]
    );

    if (arg7 == 1) {
        gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xEA, 0xE6, 0xFF, 0xFF); // very light lilac
        gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
    }

    func_80397414_7A8AC4(
        1,
        D_803F6720[arg7][3].unk0.unkC[0],
        D_803F6720[arg7][3].unk0.unkC[1],
        D_803F6720[arg7][3].unk0.unkC[2],
        D_803F6720[arg7][3].unk0.unk0[0],
        D_803F6720[arg7][3].unk0.unk0[1],
        D_803F6720[arg7][3].unk0.unk0[2]
    );
    gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][9]);
    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397F5C_7A960C.s")
#endif
