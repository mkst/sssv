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

extern struct110c D_803FDF60_7D2BDC[];
extern struct110c D_803FDFF8_7D2C74[];
extern struct110c D_803FE100_7D2D7C[];
extern struct110c D_803FE148_7D2DC4[];
extern struct110c D_803FE1DC_7D2E58[];
extern struct110c D_803FE244_7D2EC0[];
extern struct110c D_803FE264_7D2EE0[];
extern struct110c D_803FE27C_7D2EF8[];
extern struct110c D_803FE2A4_7D2F20[];
extern struct110c D_803FE2C8_7D2F44[];
extern struct110c D_803FE39C_7D3018[];
extern struct110c D_803FE3E4_7D3060[];
extern struct110c D_803FE3FC_7D3078[];
extern struct110c D_803FE428_7D30A4[];
extern struct110c D_803FE42C_7D30A8[];
extern struct110c D_803FE52C_7D31A8[];
extern struct110c D_803FE5A0_7D321C[];
extern struct110c D_803FE5B8_7D3234[];
extern struct110c D_803FE620_7D329C[];
extern struct110c D_803FE6EC_7D3368[];
extern struct110c D_803FE71C_7D3398[];
extern struct110c D_803FF2E8_7D2EF8[];
extern struct110c D_803FF3E0_7D405C[];
extern struct110c D_803FF440_7D40BC[];
extern struct110c D_803FF618_7D4294[];
extern struct110c D_803FF668_7D42E4[];
extern struct110c D_803FF6F8_7D4374[];
extern struct110c D_803FF740_7D43BC[];
extern struct110c D_803FF7DC_7D4458[];
extern struct110c D_803FF870_7D44EC[];
extern struct110c D_803FF974_7D45F0[];
extern struct110c D_803FFB28_7D47A4[];

extern u8 D_803FDEC0_7D1AD0[0x1480];
extern u8 D_803FF340_7D2F50[0x410];
extern u8 D_803FF750_7D3360[0x750];
extern u8 D_803FFEA0_7D3AB0[0x7C0];
extern u8 D_80400660_7D4270[0x5C0];
extern u8 D_80400C20_7D4830[0x190];
extern u8 D_80400DB0_7D49C0[0x880];
extern u8 D_80401630_7D5240[0x3E0];
extern u8 D_80401A10_7D5620[0x370];
extern u8 D_80401D80_7D5990[0x400];
extern u8 D_80402180_7D5D90[0x460];
extern u8 D_804025E0_7D61F0[0x2E0];
extern u8 D_804028C0_7D64D0[0x2A0];
extern u8 D_80402B60_7D6770[0x6C0];
extern u8 D_80403220_7D6E30[0x740];
extern u8 D_80403960_7D7570[0x530];
extern u8 D_80403E90_7D7AA0[0x8B0];
extern u8 D_80404740_7D8350[0x590];
extern u8 D_80404CD0_7D88E0[0x5C0];
extern u8 D_80405290_7D8EA0[0x440];
extern u8 D_804056D0_7D92E0[0x580];
extern u8 D_80405C50_7D9860[0x6C0];
extern u8 D_80406310_7D9F20[0x100];
extern u8 D_80406410_7DA020[0x100];
extern u8 D_80406510_7DA120[0x380];
extern u8 D_80406890_7DA4A0[0x4F0];
extern u8 D_80406D80_7DA990[0x460];
extern u8 D_804071E0_7DADF0[0x590];
extern u8 D_80407770_7DB380[0x840];
extern u8 D_80407FB0_7DBBC0[0x690];
extern u8 D_80408640_7DC250[0x330];
extern u8 D_80408970_7DC580[0x410];
extern u8 D_80408D80_7DC990[0x160];

// ========================================================
// .data
// ========================================================

typedef struct {
    u8 *romStart;   // e.g. 007d1ad0
    u8 *romEnd;     // e.g. 007d2f50
    u8 *ramStart;   // e.g. 803fdec0
    u8 *ramEnd;     // e.g. 803ff340
    u8 *ramDest;    // e.g. 803fdec0
} ExtraRomData; // size 0x14

ExtraRomData D_803B6890_7C7F40[33] = {
    /* rom start, rom end, ram start, ram end, destination ram */
    { __7D1AD0SegmentRomStart, __7D1AD0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_803FDEC0_7D1AD0), _overlay2SegmentBssEnd, },
    { __7D2F50SegmentRomStart, __7D2F50SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_803FF340_7D2F50), _overlay2SegmentBssEnd, },
    { __7D3360SegmentRomStart, __7D3360SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_803FF750_7D3360), _overlay2SegmentBssEnd, },
    { __7D3AB0SegmentRomStart, __7D3AB0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_803FFEA0_7D3AB0), _overlay2SegmentBssEnd, },
    { __7D4270SegmentRomStart, __7D4270SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80400660_7D4270), _overlay2SegmentBssEnd, },
    { __7D4830SegmentRomStart, __7D4830SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80400C20_7D4830), _overlay2SegmentBssEnd, },
    { __7D49C0SegmentRomStart, __7D49C0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80400DB0_7D49C0), _overlay2SegmentBssEnd, },
    { __7D5240SegmentRomStart, __7D5240SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80401630_7D5240), _overlay2SegmentBssEnd, },
    { __7D5620SegmentRomStart, __7D5620SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80401A10_7D5620), _overlay2SegmentBssEnd, },
    { __7D5990SegmentRomStart, __7D5990SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80401D80_7D5990), _overlay2SegmentBssEnd, },
    { __7D5D90SegmentRomStart, __7D5D90SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80402180_7D5D90), _overlay2SegmentBssEnd, },
    { __7D61F0SegmentRomStart, __7D61F0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_804025E0_7D61F0), _overlay2SegmentBssEnd, },
    { __7D64D0SegmentRomStart, __7D64D0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_804028C0_7D64D0), _overlay2SegmentBssEnd, },
    { __7D6770SegmentRomStart, __7D6770SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80402B60_7D6770), _overlay2SegmentBssEnd, },
    { __7D6E30SegmentRomStart, __7D6E30SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80403220_7D6E30), _overlay2SegmentBssEnd, },
    { __7D7570SegmentRomStart, __7D7570SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80403960_7D7570), _overlay2SegmentBssEnd, },
    { __7D7AA0SegmentRomStart, __7D7AA0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80403E90_7D7AA0), _overlay2SegmentBssEnd, },
    { __7D8350SegmentRomStart, __7D8350SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80404740_7D8350), _overlay2SegmentBssEnd, },
    { __7D88E0SegmentRomStart, __7D88E0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80404CD0_7D88E0), _overlay2SegmentBssEnd, },
    { __7D8EA0SegmentRomStart, __7D8EA0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80405290_7D8EA0), _overlay2SegmentBssEnd, },
    { __7D92E0SegmentRomStart, __7D92E0SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_804056D0_7D92E0), _overlay2SegmentBssEnd, },
    { __7D9860SegmentRomStart, __7D9860SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80405C50_7D9860), _overlay2SegmentBssEnd, },
    { __7D9F20SegmentRomStart, __7D9F20SegmentRomEnd, _overlay2SegmentBssEnd, _overlay2SegmentBssEnd + sizeof(D_80406310_7D9F20), _overlay2SegmentBssEnd, },

    { __7DA020SegmentRomStart, __7DA020SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80406410_7DA020), D_803FF340_7D2F50, },
    { __7DA120SegmentRomStart, __7DA120SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80406510_7DA120), D_803FF340_7D2F50, },
    { __7DA4A0SegmentRomStart, __7DA4A0SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80406890_7DA4A0), D_803FF340_7D2F50, },
    { __7DA990SegmentRomStart, __7DA990SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80406D80_7DA990), D_803FF340_7D2F50, },
    { __7DADF0SegmentRomStart, __7DADF0SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_804071E0_7DADF0), D_803FF340_7D2F50, },
    { __7DB380SegmentRomStart, __7DB380SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80407770_7DB380), D_803FF340_7D2F50, },
    { __7DBBC0SegmentRomStart, __7DBBC0SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80407FB0_7DBBC0), D_803FF340_7D2F50, },
    { __7DC250SegmentRomStart, __7DC250SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80408640_7DC250), D_803FF340_7D2F50, },
    { __7DC580SegmentRomStart, __7DC580SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80408970_7DC580), D_803FF340_7D2F50, },
    { __7DC990SegmentRomStart, __7DC990SegmentRomEnd, D_803FF340_7D2F50, D_803FF340_7D2F50 + sizeof(D_80408D80_7DC990), D_803FF340_7D2F50, },
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
    { D_803FF2E8_7D2EF8, D_803B6B2C_7C81DC, },
    { D_803FE27C_7D2EF8, D_803B6B38_7C81E8, },
    { D_803FE5B8_7D3234, D_803B6B74_7C8224, },
    { D_803FE620_7D329C, D_803B6BBC_7C826C, },
    { D_803FE428_7D30A4, D_803B6C10_7C82C0, },
    { D_803FDFF8_7D2C74, D_803B6C4C_7C82FC, },
    { D_803FE6EC_7D3368, NULL, },
    { D_803FE244_7D2EC0, NULL, },
    { D_803FE1DC_7D2E58, NULL, },
    { D_803FE264_7D2EE0, NULL, },
    { D_803FE2C8_7D2F44, NULL, },
    { D_803FE148_7D2DC4, NULL, },
    { D_803FE100_7D2D7C, NULL, },
    { D_803FE52C_7D31A8, D_803B6C64_7C8314, },
    { D_803FE5A0_7D321C, D_803B6CDC_7C838C, },
    { D_803FE39C_7D3018, D_803B6D9C_7C844C, },
    { D_803FE71C_7D3398, D_803B6DC0_7C8470, },
    { D_803FE3FC_7D3078, D_803B6E2C_7C84DC, },
    { D_803FE42C_7D30A8, D_803B6E74_7C8524, },
    { D_803FE2A4_7D2F20, D_803B6F4C_7C85FC, },
    { D_803FE3E4_7D3060, D_803B6F94_7C8644, },
    { D_803FE52C_7D31A8, NULL, },
    { D_803FDF60_7D2BDC, NULL, },
    { D_803FF3E0_7D405C, NULL, },
    { D_803FF668_7D42E4, NULL, },
    { D_803FF7DC_7D4458, NULL, },
    { D_803FF740_7D43BC, NULL, },
    { D_803FF870_7D44EC, NULL, },
    { D_803FFB28_7D47A4, NULL, },
    { D_803FF974_7D45F0, NULL, },
    { D_803FF618_7D4294, D_803B6FD0_7C8680, },
    { D_803FF6F8_7D4374, NULL, },
    { D_803FF440_7D40BC, NULL, },
};

extern Gfx D_0400BBC0_D35F0[];
extern Gfx D_0400BBC0_D35F0[];
extern Gfx D_0400BF20_D3950[];
extern Gfx D_0400CD48_D4778[];
extern Gfx D_0400DFA0_D59D0[];
extern Gfx D_0400E750_D6180[];
extern Gfx D_0400E920_D6350[];
extern Gfx D_0400EA20_D6450[];
extern Gfx D_0400EB60_D6590[];
extern Gfx D_0400ED28_D6758[];
extern Gfx D_0400F0A0_D6AD0[];
extern Gfx D_0400F1E0_D6C10[];
extern Gfx D_0400F398_D6DC8[];
extern Gfx D_0400F700_D7130[];
extern Gfx D_0400FE60_D7890[];
extern Gfx D_04010080_D7AB0[];
extern Gfx D_040104C0_D7EF0[];
extern Gfx D_04010710_D8140[];
extern Gfx D_04010A70_D84A0[];
extern Gfx D_04011868_D9298[];
extern Gfx D_04012400_D9E30[];
extern Gfx D_05000180_7F910[];
extern Gfx D_050004E0_7FC70[];
extern Gfx D_05000880_978A0[];
extern Gfx D_05000F90_97FB0[];
extern Gfx D_05001308_80A98[];
extern Gfx D_05001390_983B0[];
extern Gfx D_050016D0_80E60[];
extern Gfx D_05001A30_811C0[];
extern Gfx D_05002828_81FB8[];
extern Gfx D_050033C0_82B50[];
extern Gfx D_05004650_83DE0[];
extern Gfx D_05004E00_84590[];
extern Gfx D_05004FD0_84760[];

// Dan Danger display lists
Gfx *D_803B7108_7C87B8[5][10] = {
    {
        D_05000180_7F910, D_050004E0_7FC70, D_05001308_80A98, D_050016D0_80E60, D_05001A30_811C0,
        D_05002828_81FB8, D_050033C0_82B50, D_05004650_83DE0, D_05004E00_84590, D_05004FD0_84760,
    },
    {
        D_0400BBC0_D35F0, D_0400BF20_D3950, D_0400CD48_D4778, D_04010710_D8140, D_04010A70_D84A0,
        D_04011868_D9298, D_04012400_D9E30, D_0400DFA0_D59D0, D_0400E750_D6180, D_0400E920_D6350,
    },
    {
        D_0400EB60_D6590, D_0400ED28_D6758, D_0400F0A0_D6AD0, D_0400F1E0_D6C10, D_0400F398_D6DC8,
        D_0400F700_D7130, D_0400FE60_D7890, D_040104C0_D7EF0, D_0400EA20_D6450, D_04010080_D7AB0,
    },
    {
        D_0400EB60_D6590, D_0400ED28_D6758, D_0400F0A0_D6AD0, D_0400F1E0_D6C10, D_0400F398_D6DC8,
        D_0400F700_D7130, D_0400FE60_D7890, D_040104C0_D7EF0, D_0400EA20_D6450, D_04010080_D7AB0,
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
