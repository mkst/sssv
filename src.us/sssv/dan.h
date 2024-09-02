#ifndef DAN_H
#define DAN_H

#include <ultra64.h>

// ========================================================
// definitions
// ========================================================

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
} struct048a; // size 0x18

typedef struct {
    /* 0x00 */ struct048a unk0;
    /* 0x18 */ struct048a unk18;
    /* 0x30 */ struct048a unk30;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ u8  pad52[2];
} struct048; // size 0x54

typedef struct {
    /* 0x0 */ s16 unk0; // marries up with D_803F714C[idx]
    /* 0x2 */ s16 id;
    /* 0x4 */ s16 volume;
    /* 0x8 */ f32 pitch;
} Sfx; // size 0xC

typedef struct {
    /* 0x0 */ s16 unk0; // -> struct048.unk30.unk0[1]
    /* 0x2 */ s16 unk2; // -> struct048.unk30.unk0[2]
    /* 0x4 */ s16 unk4; // -> struct048.unk30.unk0[0]
    /* 0x6 */ s16 unk6; // -> struct048.unk30.unkC[0]
    /* 0x6 */ s16 unk8; // -> struct048.unk30.unkC[1]
    /* 0x6 */ s16 unkA; // -> struct048.unk30.unkC[2]
    /* 0xC */ u16 unkC; // -> struct048.unk4C
} struct110b; // size 0xE

typedef struct {
    s16 unk0;
    struct110b *unk4;
} struct110c; // size 0x8 ?

typedef struct {
    struct110c* unk0;
    Sfx* sfx;
} struct110; // size 0x8

// ========================================================
// .externs
// ========================================================

extern struct110c D_803FDF60[];
extern struct110c D_803FDFF8[];
extern struct110c D_803FE100[];
extern struct110c D_803FE148[];
extern struct110c D_803FE1DC[];
extern struct110c D_803FE244[];
extern struct110c D_803FE264[];
extern struct110c D_803FE27C[];
extern struct110c D_803FE2A4[];
extern struct110c D_803FE2C8[];
extern struct110c D_803FE39C[];
extern struct110c D_803FE3E4[];
extern struct110c D_803FE3FC[];
extern struct110c D_803FE428[];
extern struct110c D_803FE42C[];
extern struct110c D_803FE52C[];
extern struct110c D_803FE5A0[];
extern struct110c D_803FE5B8[];
extern struct110c D_803FE620[];
extern struct110c D_803FE6EC[];
extern struct110c D_803FE71C[];
extern struct110c D_803FF2E8[];
extern struct110c D_803FF3E0[];
extern struct110c D_803FF440[];
extern struct110c D_803FF618[];
extern struct110c D_803FF668[];
extern struct110c D_803FF6F8[];
extern struct110c D_803FF740[];
extern struct110c D_803FF7DC[];
extern struct110c D_803FF870[];
extern struct110c D_803FF974[];
extern struct110c D_803FFB28[];

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

s16 D_803B6B24_7C81D4[3] = {
    0,
    23,
    10,
};

    //  unk   id volume    pitch
Sfx D_803B6B2C_7C81DC[] = {
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6B38_7C81E8[] = {
    {   30,  325, 24576,   1.0f, },
    {   61,  312, 24576,   1.0f, },
    {   67,  321, 24576,   1.0f, },
    {   83,  317, 24576,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6B74_7C8224[] = {
    {    1,  332, 32767,   1.0f, },
    {   56,  263, 32767,  0.71f, },
    {  128,  336, 32767,   1.0f, },
    {  157,  337, 32767,   1.0f, },
    {  185,  306, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6BBC_7C826C[] = {
    {   87,  309, 32767,   1.0f, }, // 12
    {   87,  300, 24575,  0.87f, },
    {  117,  310, 32767,   1.0f, },
    {  117,  300, 24575,  0.87f, },
    {  131,  311, 32767,   1.0f, },
    {  131,  300, 24575,  0.87f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6C10_7C82C0[] = {
    {   25,  334, 32767,   1.0f, }, // 19
    {   60,  333, 32767,   1.0f, },
    {   70,  330, 32767,   1.0f, },
    {  174,  331, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6C4C_7C82FC[] = {
    {    1,  329, 32767,   1.0f, }, // 24
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6C64_7C8314[] = {
    {    9,  263, 25088,  0.81f, }, // 26
    {   19,  263, 26624, 0.803f, },
    {   28,  263, 28672, 0.793f, },
    {   38,  263, 27136,  0.78f, },
    {   48,  263, 28672, 0.793f, },
    {   60,  263, 24576,  0.77f, },
    {   70,  263, 28672,  0.79f, },
    {   94,  302, 32767,   1.0f, },
    {  100,  299, 18432, 0.707f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6CDC_7C838C[] = {
    {    1,  327, 16384,   1.0f, }, // 36
    {   13,  327, 24576,   1.0f, },
    {   25,  327, 24576,   1.0f, },
    {   36,  327, 24576,   1.0f, },
    {   48,  327, 24576,   1.0f, },
    {   66,  327, 24576,   1.0f, },
    {   79,  327, 24576,   1.0f, },
    {   94,  327, 24576,  0.97f, },
    {  110,  327, 14848,  0.94f, },
    {  129,  327, 12288,  0.92f, },
    {  151,  327, 10240,  0.89f, },
    {  187,  318, 32767,   1.0f, },
    {  206,  302, 32767,   1.0f, },
    {  230,  308, 32767,   1.0f, },
    {  255,  301, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6D9C_7C844C[] = {
    {   60,  324, 32767,   1.0f, }, // 52
    {   85,  301, 22528,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6DC0_7C8470[] = {
    {   27,  323, 25856,   1.0f, }, // 55
    {   46,  328, 24576,   1.0f, },
    {   68,  326, 14199,   1.0f, },
    {   74,  326, 14199,   1.0f, },
    {   84,  326, 14199,  1.25f, },
    {   92,  326,  8465,   1.0f, },
    {  105,  305, 32767,   1.0f, },
    {  128,  307, 22391,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6E2C_7C84DC[] = {
    {   13,  319, 32767,   1.0f, }, // 64
    {   36,  320, 32767,   1.0f, },
    {   46,  300, 28671,  0.82f, },
    {   65,  322, 32767,   1.0f, },
    {   94,  308, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6E74_7C8524[] = {
    {   48,  343, 32767,   1.0f, }, // 70
    {   53,  326, 15018,   1.0f, },
    {   58,  326, 15018,   1.0f, },
    {   64,  303, 16384,   1.0f, },
    {   68,  326, 15018,   1.0f, },
    {   80,  326, 15018,   1.0f, },
    {   91,  326, 15018,   1.0f, },
    {  106,  326, 15018,   1.0f, },
    {  117,  326, 15018,   1.0f, },
    {  123,  338, 32767,   1.0f, },
    {  130,  326, 15018,   1.0f, },
    {  142,  313, 28672,   1.0f, },
    {  144,  326, 15018,   1.0f, },
    {  148,  314, 28672,   1.0f, },
    {  153,  315, 28672,   1.0f, },
    {  156,  326, 15018,   1.0f, },
    {  156,  316, 28672,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6F4C_7C85FC[] = {
    {   24,  303, 16384,   1.0f, }, // 88
    {   50,  338, 32767,  0.79f, },
    {   82,  340, 10649,   1.0f, },
    {   96,  341, 10649,   1.0f, },
    {  139,  342, 10649,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6F94_7C8644[] = {
    {   61,  304, 25668,  1.04f, }, // 94
    {   88,  304, 24576,  0.95f, },
    {   96,  304, 24029,   1.2f, },
    {  104,  304, 23483,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
Sfx D_803B6FD0_7C8680[] = {
    {  109,  344, 32767,   1.0f, }, // 99
    {  128,  339, 32767,   1.0f, },
    {  172,  140, 18432,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};


// these are addresses within the data right at the end of the ROM.
struct110 D_803B7000_7C86B0[33] = {
    { D_803FF2E8, D_803B6B2C_7C81DC, },
    { D_803FE27C, D_803B6B38_7C81E8, },
    { D_803FE5B8, D_803B6B74_7C8224, },
    { D_803FE620, D_803B6BBC_7C826C, },
    { D_803FE428, D_803B6C10_7C82C0, },
    { D_803FDFF8, D_803B6C4C_7C82FC, },
    { D_803FE6EC, NULL, },
    { D_803FE244, NULL, },
    { D_803FE1DC, NULL, },
    { D_803FE264, NULL, },
    { D_803FE2C8, NULL, },
    { D_803FE148, NULL, },
    { D_803FE100, NULL, },
    { D_803FE52C, D_803B6C64_7C8314, },
    { D_803FE5A0, D_803B6CDC_7C838C, },
    { D_803FE39C, D_803B6D9C_7C844C, },
    { D_803FE71C, D_803B6DC0_7C8470, },
    { D_803FE3FC, D_803B6E2C_7C84DC, },
    { D_803FE42C, D_803B6E74_7C8524, },
    { D_803FE2A4, D_803B6F4C_7C85FC, },
    { D_803FE3E4, D_803B6F94_7C8644, },
    { D_803FE52C, NULL, },
    { D_803FDF60, NULL, },
    { D_803FF3E0, NULL, },
    { D_803FF668, NULL, },
    { D_803FF7DC, NULL, },
    { D_803FF740, NULL, },
    { D_803FF870, NULL, },
    { D_803FFB28, NULL, },
    { D_803FF974, NULL, },
    { D_803FF618, D_803B6FD0_7C8680, },
    { D_803FF6F8, NULL, },
    { D_803FF440, NULL, },
};

extern Gfx D_0400BBC0_D35F0[];
extern Gfx D_0400BBC0_D35F0[];
extern Gfx D_0400BF20_D3950[];
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
Gfx *D_803B7108_7C87B8[5][10] = {
    {
        D_05000180_7F910, D_050004E0_7FC70, D_05001308_80A98, D_050016D0_80E60, D_05001A30_811C0,
        D_05002828, D_050033C0_82B50, D_05004650_83DE0, D_05004E00_84590, D_05004FD0_84760,
    },
    {
        D_0400BBC0_D35F0, D_0400BF20_D3950, D_0400CD48, D_04010710, D_04010A70,
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


// ========================================================
// .bss (D_803F6720 to D_803F7160)
// ========================================================

static struct048  D_803F6720[3][10]; // 0x54 each
static s16  D_803F70F8[3][10];
static s16  D_803F7134[3];
u16  D_803F713C[3];
static s16  D_803F7144[3];
static s16  D_803F714C[3];

#endif
