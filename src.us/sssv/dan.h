#ifndef DAN_H
#define DAN_H

#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

typedef struct {
    f32 rot[3];
    f32 pos[3];
} RigTransform; // size 0x18

typedef struct {
    /* 0x00 */ RigTransform current;
    /* 0x18 */ RigTransform previous;
    /* 0x30 */ RigTransform target;
    /* 0x48 */ f32 elapsed;
    /* 0x4C */ f32 duration;
    /* 0x50 */ s16 active;
    /* 0x52 */ s16 unused;
} RigPoseState; // size 0x54

typedef struct {
    /* 0x0 */ s16 frame; // marries up with D_803F714C[idx]
    /* 0x2 */ s16 id;
    /* 0x4 */ s16 volume;
    /* 0x8 */ f32 pitch;
} RigSfxEvent; // size 0xC

typedef struct {
    RigAnimation* anim;
    RigSfxEvent*  sfx;
} ClipData; // size 0x8

// ========================================================
// .externs
// ========================================================

extern RigAnimation D_803FF2E8_7D2EF8[];
extern RigAnimation D_803FE27C_7D330C[];
extern RigAnimation D_803FE5B8_7D3A58[];
extern RigAnimation D_803FE620_7D4210[];
extern RigAnimation D_803FE428_7D47D8[];
extern RigAnimation D_803FDFF8_7D4968[];
extern RigAnimation D_803FE6EC_7D51EC[];
extern RigAnimation D_803FE244_7D55C4[];
extern RigAnimation D_803FE1DC_7D593C[];
extern RigAnimation D_803FE264_7D5D34[];
extern RigAnimation D_803FE2C8_7D6198[];
extern RigAnimation D_803FE148_7D6478[];
extern RigAnimation D_803FE100_7D6710[];
extern RigAnimation D_803FE52C_7D6DDC[];
extern RigAnimation D_803FE5A0_7D7510[];
extern RigAnimation D_803FE39C_7D7A4C[];
extern RigAnimation D_803FE71C_7D82FC[];
extern RigAnimation D_803FE3FC_7D888C[];
extern RigAnimation D_803FE42C_7D8E4C[];
extern RigAnimation D_803FE2A4_7D9284[];
extern RigAnimation D_803FE3E4_7D9804[];
extern RigAnimation D_803FE52C_7D9ECC[];
extern RigAnimation D_803FDF60_7D9FC0[];


extern RigAnimation D_803FF3E0_7DA0C0[];
extern RigAnimation D_803FF668_7DA448[];
extern RigAnimation D_803FF7DC_7DA93C[];
extern RigAnimation D_803FF740_7DAD90[];
extern RigAnimation D_803FF870_7DB320[];
extern RigAnimation D_803FFB28_7DBB68[];
extern RigAnimation D_803FF974_7DC1F4[];
extern RigAnimation D_803FF618_7DC528[];
extern RigAnimation D_803FF6F8_7DC938[];
extern RigAnimation D_803FF440_7DCA90[];


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
    /*  rom start,               rom end,               ram start,            ram end,                destination ram */
    { __7D1AD0SegmentRomStart, __7D1AD0SegmentRomEnd, __7D1AD0SegmentStart, __7D1AD0SegmentDataEnd, __7D1AD0SegmentStart, },
    { __7D2F50SegmentRomStart, __7D2F50SegmentRomEnd, __7D2F50SegmentStart, __7D2F50SegmentDataEnd, __7D2F50SegmentStart, },
    { __7D3360SegmentRomStart, __7D3360SegmentRomEnd, __7D3360SegmentStart, __7D3360SegmentDataEnd, __7D3360SegmentStart, },
    { __7D3AB0SegmentRomStart, __7D3AB0SegmentRomEnd, __7D3AB0SegmentStart, __7D3AB0SegmentDataEnd, __7D3AB0SegmentStart, },
    { __7D4270SegmentRomStart, __7D4270SegmentRomEnd, __7D4270SegmentStart, __7D4270SegmentDataEnd, __7D4270SegmentStart, },
    { __7D4830SegmentRomStart, __7D4830SegmentRomEnd, __7D4830SegmentStart, __7D4830SegmentDataEnd, __7D4830SegmentStart, },
    { __7D49C0SegmentRomStart, __7D49C0SegmentRomEnd, __7D49C0SegmentStart, __7D49C0SegmentDataEnd, __7D49C0SegmentStart, },
    { __7D5240SegmentRomStart, __7D5240SegmentRomEnd, __7D5240SegmentStart, __7D5240SegmentDataEnd, __7D5240SegmentStart, },
    { __7D5620SegmentRomStart, __7D5620SegmentRomEnd, __7D5620SegmentStart, __7D5620SegmentDataEnd, __7D5620SegmentStart, },
    { __7D5990SegmentRomStart, __7D5990SegmentRomEnd, __7D5990SegmentStart, __7D5990SegmentDataEnd, __7D5990SegmentStart, },
    /*  rom start,               rom end,               ram start,            ram end,                destination ram */
    { __7D5D90SegmentRomStart, __7D5D90SegmentRomEnd, __7D5D90SegmentStart, __7D5D90SegmentDataEnd, __7D5D90SegmentStart, },
    { __7D61F0SegmentRomStart, __7D61F0SegmentRomEnd, __7D61F0SegmentStart, __7D61F0SegmentDataEnd, __7D61F0SegmentStart, },
    { __7D64D0SegmentRomStart, __7D64D0SegmentRomEnd, __7D64D0SegmentStart, __7D64D0SegmentDataEnd, __7D64D0SegmentStart, },
    { __7D6770SegmentRomStart, __7D6770SegmentRomEnd, __7D6770SegmentStart, __7D6770SegmentDataEnd, __7D6770SegmentStart, },
    { __7D6E30SegmentRomStart, __7D6E30SegmentRomEnd, __7D6E30SegmentStart, __7D6E30SegmentDataEnd, __7D6E30SegmentStart, },
    { __7D7570SegmentRomStart, __7D7570SegmentRomEnd, __7D7570SegmentStart, __7D7570SegmentDataEnd, __7D7570SegmentStart, },
    { __7D7AA0SegmentRomStart, __7D7AA0SegmentRomEnd, __7D7AA0SegmentStart, __7D7AA0SegmentDataEnd, __7D7AA0SegmentStart, },
    { __7D8350SegmentRomStart, __7D8350SegmentRomEnd, __7D8350SegmentStart, __7D8350SegmentDataEnd, __7D8350SegmentStart, },
    { __7D88E0SegmentRomStart, __7D88E0SegmentRomEnd, __7D88E0SegmentStart, __7D88E0SegmentDataEnd, __7D88E0SegmentStart, },
    { __7D8EA0SegmentRomStart, __7D8EA0SegmentRomEnd, __7D8EA0SegmentStart, __7D8EA0SegmentDataEnd, __7D8EA0SegmentStart, },
    { __7D92E0SegmentRomStart, __7D92E0SegmentRomEnd, __7D92E0SegmentStart, __7D92E0SegmentDataEnd, __7D92E0SegmentStart, },
    { __7D9860SegmentRomStart, __7D9860SegmentRomEnd, __7D9860SegmentStart, __7D9860SegmentDataEnd, __7D9860SegmentStart, },
    { __7D9F20SegmentRomStart, __7D9F20SegmentRomEnd, __7D9F20SegmentStart, __7D9F20SegmentDataEnd, __7D9F20SegmentStart, },
    /*  rom start,               rom end,               ram start,            ram end,                destination ram */
    { __7DA020SegmentRomStart, __7DA020SegmentRomEnd, __7DA020SegmentStart, __7DA020SegmentDataEnd, __7DA020SegmentStart, },
    { __7DA120SegmentRomStart, __7DA120SegmentRomEnd, __7DA120SegmentStart, __7DA120SegmentDataEnd, __7DA120SegmentStart, },
    { __7DA4A0SegmentRomStart, __7DA4A0SegmentRomEnd, __7DA4A0SegmentStart, __7DA4A0SegmentDataEnd, __7DA4A0SegmentStart, },
    { __7DA990SegmentRomStart, __7DA990SegmentRomEnd, __7DA990SegmentStart, __7DA990SegmentDataEnd, __7DA990SegmentStart, },
    { __7DADF0SegmentRomStart, __7DADF0SegmentRomEnd, __7DADF0SegmentStart, __7DADF0SegmentDataEnd, __7DADF0SegmentStart, },
    { __7DB380SegmentRomStart, __7DB380SegmentRomEnd, __7DB380SegmentStart, __7DB380SegmentDataEnd, __7DB380SegmentStart, },
    { __7DBBC0SegmentRomStart, __7DBBC0SegmentRomEnd, __7DBBC0SegmentStart, __7DBBC0SegmentDataEnd, __7DBBC0SegmentStart, },
    { __7DC250SegmentRomStart, __7DC250SegmentRomEnd, __7DC250SegmentStart, __7DC250SegmentDataEnd, __7DC250SegmentStart, },
    { __7DC580SegmentRomStart, __7DC580SegmentRomEnd, __7DC580SegmentStart, __7DC580SegmentDataEnd, __7DC580SegmentStart, },
    { __7DC990SegmentRomStart, __7DC990SegmentRomEnd, __7DC990SegmentStart, __7DC990SegmentDataEnd, __7DC990SegmentStart, },
};

s16 D_803B6B24_7C81D4[3] = {
    0,
    23,
    10,
};

    // frame  id volume    pitch
RigSfxEvent D_803B6B2C_7C81DC[] = {
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6B38_7C81E8[] = {
    {   30,  325, 24576,   1.0f, },
    {   61,  312, 24576,   1.0f, },
    {   67,  321, 24576,   1.0f, },
    {   83,  317, 24576,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6B74_7C8224[] = {
    {    1,  332, 32767,   1.0f, },
    {   56,  263, 32767,  0.71f, },
    {  128,  336, 32767,   1.0f, },
    {  157,  337, 32767,   1.0f, },
    {  185,  306, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6BBC_7C826C[] = {
    {   87,  309, 32767,   1.0f, }, // 12
    {   87,  300, 24575,  0.87f, },
    {  117,  310, 32767,   1.0f, },
    {  117,  300, 24575,  0.87f, },
    {  131,  311, 32767,   1.0f, },
    {  131,  300, 24575,  0.87f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6C10_7C82C0[] = {
    {   25,  334, 32767,   1.0f, }, // 19
    {   60,  333, 32767,   1.0f, },
    {   70,  330, 32767,   1.0f, },
    {  174,  331, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6C4C_7C82FC[] = {
    {    1,  329, 32767,   1.0f, }, // 24
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6C64_7C8314[] = {
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
RigSfxEvent D_803B6CDC_7C838C[] = {
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
RigSfxEvent D_803B6D9C_7C844C[] = {
    {   60,  324, 32767,   1.0f, }, // 52
    {   85,  301, 22528,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6DC0_7C8470[] = {
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
RigSfxEvent D_803B6E2C_7C84DC[] = {
    {   13,  319, 32767,   1.0f, }, // 64
    {   36,  320, 32767,   1.0f, },
    {   46,  300, 28671,  0.82f, },
    {   65,  322, 32767,   1.0f, },
    {   94,  308, 32767,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6E74_7C8524[] = {
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
RigSfxEvent D_803B6F4C_7C85FC[] = {
    {   24,  303, 16384,   1.0f, }, // 88
    {   50,  338, 32767,  0.79f, },
    {   82,  340, 10649,   1.0f, },
    {   96,  341, 10649,   1.0f, },
    {  139,  342, 10649,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6F94_7C8644[] = {
    {   61,  304, 25668,  1.04f, }, // 94
    {   88,  304, 24576,  0.95f, },
    {   96,  304, 24029,   1.2f, },
    {  104,  304, 23483,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};
RigSfxEvent D_803B6FD0_7C8680[] = {
    {  109,  344, 32767,   1.0f, }, // 99
    {  128,  339, 32767,   1.0f, },
    {  172,  140, 18432,   1.0f, },
    {   -1,    0,     0,   0.0f, },
};


// these are addresses within the data right at the end of the ROM.
ClipData D_803B7000_7C86B0[33] = {
    { D_803FF2E8_7D2EF8, D_803B6B2C_7C81DC, },
    { D_803FE27C_7D330C, D_803B6B38_7C81E8, },
    { D_803FE5B8_7D3A58, D_803B6B74_7C8224, },
    { D_803FE620_7D4210, D_803B6BBC_7C826C, },
    { D_803FE428_7D47D8, D_803B6C10_7C82C0, },
    { D_803FDFF8_7D4968, D_803B6C4C_7C82FC, },
    { D_803FE6EC_7D51EC, NULL, },
    { D_803FE244_7D55C4, NULL, },
    { D_803FE1DC_7D593C, NULL, },
    { D_803FE264_7D5D34, NULL, },
    { D_803FE2C8_7D6198, NULL, },
    { D_803FE148_7D6478, NULL, },
    { D_803FE100_7D6710, NULL, },
    { D_803FE52C_7D6DDC, D_803B6C64_7C8314, },
    { D_803FE5A0_7D7510, D_803B6CDC_7C838C, },
    { D_803FE39C_7D7A4C, D_803B6D9C_7C844C, },
    { D_803FE71C_7D82FC, D_803B6DC0_7C8470, },
    { D_803FE3FC_7D888C, D_803B6E2C_7C84DC, },
    { D_803FE42C_7D8E4C, D_803B6E74_7C8524, },
    { D_803FE2A4_7D9284, D_803B6F4C_7C85FC, },
    { D_803FE3E4_7D9804, D_803B6F94_7C8644, },
    { D_803FE52C_7D9ECC, NULL, },
    { D_803FDF60_7D9FC0, NULL, },

    { D_803FF3E0_7DA0C0, NULL, },
    { D_803FF668_7DA448, NULL, },
    { D_803FF7DC_7DA93C, NULL, },
    { D_803FF740_7DAD90, NULL, },
    { D_803FF870_7DB320, NULL, },
    { D_803FFB28_7DBB68, NULL, },
    { D_803FF974_7DC1F4, NULL, },
    { D_803FF618_7DC528, D_803B6FD0_7C8680, },
    { D_803FF6F8_7DC938, NULL, },
    { D_803FF440_7DCA90, NULL, },
};

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
Gfx *gRigPartDisplayLists[5][10] = {
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

static RigPoseState  gRigPoseStates[3][10]; // 0x54 each
static s16  D_803F70F8[3][10]; // current keyframe index for bone j
static s16  D_803F7134[3];
u16  D_803F713C[3]; // active bone mask
static s16  D_803F7144[3]; // next sound cue index
static s16  D_803F714C[3]; // current frame number / tick

#endif
