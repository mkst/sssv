#include <ultra64.h>

#include "common.h"

#include "pp.h"


// ========================================================
// definitions
// ========================================================

typedef struct {
    u16 startTime;
    s16 pad;
    s16 sfx;
} SubtitleText; // size 0x6

typedef struct {
    SubtitleText *msg;
    s16 id;
    s16 pad;
} Subtitle; // size 0x8

typedef struct {
    s16 time;
    s16 tile;
    s16 unk6;
} Newscaster; // size 0x6

// ========================================================
// externs
// ========================================================

// these assets are split & included separately

extern const Gfx  D_802EEB20_6921C0[];    // spaceship model
extern const Gfx  D_802F3C20_6972C0[527]; // N64 controller model

// ========================================================
// .data
// ========================================================

    /* start, unused, sfx */
SubtitleText D_80299730_63CDD0[4] = {
    { 0x0008, 0x0300, 0x0121, },
    { 0x004A, 0x0300, 0x0125, },
    { 0x0078, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299748_63CDE8[5] = {
    { 0x0001, 0x0300, 0x0120, },
    { 0x002E, 0x0300, 0x0123, },
    { 0x005E, 0x0300, 0x0127, },
    { 0x0086, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299768_63CE08[5] = {
    { 0x0002, 0x0300, 0x0126},
    { 0x0024, 0x0300, 0x0122},
    { 0x0044, 0x0300, 0x0128},
    { 0x0070, 0x0000, 0x00FF},
    { 0x0000, 0x0000, 0x00FF},
};

SubtitleText D_80299788_63CE28[6] = {
    { 0x0002, 0x0300, 0x0126, },
    { 0x0022, 0x0300, 0x0127, },
    { 0x0045, 0x0300, 0x0120, },
    { 0x0070, 0x0300, 0x0122, },
    { 0x008C, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_802997AC_63CE4C[5] = {
    { 0x0002, 0x0300, 0x0124, },
    { 0x0038, 0x0300, 0x0129, },
    { 0x0067, 0x0300, 0x0127, },
    { 0x008B, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_802997CC_63CE6C[5] = {
    { 0x0002, 0x0300, 0x0126, },
    { 0x0024, 0x0300, 0x012A, },
    { 0x0058, 0x0300, 0x0120, },
    { 0x0082, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_802997EC_63CE8C[3] = {
    { 0x0003, 0x0300, 0x0128, },
    { 0x0050, 0x0300, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299800_63CEA0[4] = {
    { 0x0001, 0x0000, 0x0129, },
    { 0x0042, 0x0000, 0x0123, },
    { 0x0070, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299818_63CEB8[5] = {
    { 0x0001, 0x0000, 0x0122, },
    { 0x0020, 0x0000, 0x0127, },
    { 0x0048, 0x0000, 0x0120, },
    { 0x0074, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299838_63CED8[4] = {
    { 0x0001, 0x0000, 0x012A, },
    { 0x003C, 0x0000, 0x0128, },
    { 0x0064, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299850_63CEF0[5] = {
    { 0x0002, 0x0000, 0x0126, },
    { 0x0022, 0x0000, 0x0127, },
    { 0x0045, 0x0000, 0x0120, },
    { 0x0070, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299870_63CF10[4] = {
    { 0x0001, 0x0000, 0x012A, },
    { 0x0038, 0x0000, 0x0124, },
    { 0x0078, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299888_63CF28[4] = {
    { 0x0001, 0x0000, 0x0121, },
    { 0x003E, 0x0000, 0x012A, },
    { 0x0072, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_802998A0_63CF40[4] = {
    { 0x0001, 0x0000, 0x0122, },
    { 0x002C, 0x0000, 0x0125, },
    { 0x005A, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_802998B8_63CF58[9] = {
    { 0x0002, 0x0301, 0x00FF, },
    { 0x0007, 0x0300, 0x00FF, },
    { 0x000A, 0x0301, 0x0057, },
    { 0x0012, 0x0300, 0x00FF, },
    { 0x0019, 0x0301, 0x0057, },
    { 0x0020, 0x0300, 0x00FF, },
    { 0x0028, 0x0301, 0x0057, },
    { 0x0031, 0x0000, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_802998F0_63CF90[4] = {
    { 0x0005, 0x0300, 0x0057, },
    { 0x000D, 0x0301, 0x0057, },
    { 0x001B, 0x0300, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299908_63CFA8[5] = {
    { 0x0005, 0x0300, 0x00FF, },
    { 0x000F, 0x0000, 0x00FF, },
    { 0x001A, 0x0101, 0x00FF, },
    { 0x0028, 0x0100, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299928_63CFC8[5] = {
    { 0x0005, 0x0300, 0x00FF, },
    { 0x000F, 0x0000, 0x00FF, },
    { 0x001A, 0x0101, 0x00FF, },
    { 0x0028, 0x0100, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

SubtitleText D_80299948_63CFE8[4] = {
    { 0x0001, 0x0300, 0x00FF, },
    { 0x001E, 0x0300, 0x0128, },
    { 0x0064, 0x0300, 0x00FF, },
    { 0x0000, 0x0000, 0x00FF, },
};

Subtitle D_80299960_63D000[28] = {
    { D_802998B8_63CF58, 0x000D, 0x0000},
    { D_80299730_63CDD0, 0x0000, 0x0000},
    { D_80299748_63CDE8, 0x0001, 0x0000},
    { D_802997EC_63CE8C, 0x0002, 0x0000},
    { D_802998F0_63CF90, 0x0002, 0x0000},
    { D_80299788_63CE28, 0x0003, 0x0000},
    { D_802997AC_63CE4C, 0x0004, 0x0000},
    { D_802997CC_63CE6C, 0x0005, 0x0000},
    { D_802997EC_63CE8C, 0x0006, 0x0000},
    { D_80299908_63CFA8, 0x000D, 0x0000},
    { D_80299800_63CEA0, 0x0011, 0x0000},
    { D_80299818_63CEB8, 0x0012, 0x0000},
    { D_80299838_63CED8, 0x0013, 0x0000},
    { D_80299908_63CFA8, 0x000D, 0x0000},
    { D_80299850_63CEF0, 0x0007, 0x0000},
    { D_802997AC_63CE4C, 0x0008, 0x0000},
    { D_80299870_63CF10, 0x0009, 0x0000},
    { D_802998F0_63CF90, 0x000D, 0x0000},
    { D_802998F0_63CF90, 0x000D, 0x0000},
    { D_802998F0_63CF90, 0x000D, 0x0000},
    { D_802998F0_63CF90, 0x000D, 0x0000},
    { D_802998F0_63CF90, 0x000D, 0x0000},
    { D_80299888_63CF28, 0x000A, 0x0000},
    { D_802998A0_63CF40, 0x000B, 0x0000},
    { D_802998B8_63CF58, 0x000D, 0x0000},
    { D_80299948_63CFE8, 0x000C, 0x0000},
    { D_802998F0_63CF90, 0x000D, 0x0000},
    { D_80299928_63CFC8, 0x000D, 0x0000},
};

Newscaster D_80299A40_63D0E0[4] = {
   /* time,   tile,   shuffle papers */
    { 0x0001, 0x0003, 0x0001, },
    { 0x0009, 0x0003, 0x0000, },
    { 0x000E, 0x0001, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299A58_63D0F8[8] = {
    { 0x0001, 0x0002, 0x0000, },
    { 0x0009, 0x0001, 0x0000, },
    { 0x000F, 0x0003, 0x0000, },
    { 0x0011, 0x0002, 0x0000, },
    { 0x0019, 0x0000, 0x0000, },
    { 0x001F, 0x0001, 0x0000, },
    { 0x002F, 0x0003, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299A88_63D128[11] = {
    { 0x0001, 0x0121, 0x0000, }, // typo?
    { 0x0003, 0x0001, 0x0000, },
    { 0x001D, 0x0003, 0x0000, },
    { 0x0021, 0x0002, 0x0000, },
    { 0x0027, 0x0000, 0x0000, },
    { 0x002F, 0x0003, 0x0000, },
    { 0x0033, 0x0001, 0x0000, },
    { 0x003B, 0x0003, 0x0000, },
    { 0x003F, 0x0001, 0x0000, },
    { 0x0047, 0x0003, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299ACC_63D16C[7] = {
    { 0x0001, 0x0001, 0x0000, },
    { 0x0003, 0x0002, 0x0000, },
    { 0x000B, 0x0003, 0x0000, },
    { 0x0013, 0x0001, 0x0000, },
    { 0x0017, 0x0002, 0x0000, },
    { 0x0021, 0x0000, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299AF8_63D198[9] = {
    { 0x0001, 0x0001, 0x0000, },
    { 0x0007, 0x0000, 0x0000, },
    { 0x000D, 0x0003, 0x0000, },
    { 0x0011, 0x0002, 0x0000, },
    { 0x0015, 0x0000, 0x0000, },
    { 0x001B, 0x0003, 0x0000, },
    { 0x001F, 0x0000, 0x0000, },
    { 0x002F, 0x0003, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299B30_63D1D0[11] = {
    { 0x0001, 0x0003, 0x0000, },
    { 0x0003, 0x0002, 0x0000, },
    { 0x0007, 0x0003, 0x0000, },
    { 0x0009, 0x0002, 0x0000, },
    { 0x0011, 0x0000, 0x0000, },
    { 0x0015, 0x0002, 0x0000, },
    { 0x0021, 0x0003, 0x0000, },
    { 0x0025, 0x0002, 0x0000, },
    { 0x002B, 0x0003, 0x0000, },
    { 0x0031, 0x0000, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299B74_63D214[5] = {
    { 0x0001, 0x0003, 0x0000, },
    { 0x0002, 0x0001, 0x0000, },
    { 0x000F, 0x0002, 0x0000, },
    { 0x001D, 0x0001, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299B94_63D234[8] = {
    { 0x0001, 0x0003, 0x0000, },
    { 0x0003, 0x0001, 0x0000, },
    { 0x000F, 0x0003, 0x0000, },
    { 0x0015, 0x0002, 0x0000, },
    { 0x001D, 0x0003, 0x0000, },
    { 0x0023, 0x0001, 0x0000, },
    { 0x002F, 0x0000, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299BC4_63D264[7] = {
    { 0x0001, 0x0000, 0x0000, },
    { 0x0007, 0x0001, 0x0000, },
    { 0x0013, 0x0002, 0x0000, },
    { 0x0017, 0x0000, 0x0000, },
    { 0x001B, 0x0002, 0x0000, },
    { 0x0027, 0x0000, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299BF0_63D290[8] = {
    { 0x0001, 0x0003, 0x0000, },
    { 0x0003, 0x0002, 0x0000, },
    { 0x000B, 0x0003, 0x0000, },
    { 0x000F, 0x0000, 0x0000, },
    { 0x0019, 0x0003, 0x0000, },
    { 0x001D, 0x0001, 0x0000, },
    { 0x0029, 0x0003, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299C20_63D2C0[8] = {
    { 0x0001, 0x0003, 0x0000, },
    { 0x0003, 0x0001, 0x0000, },
    { 0x000F, 0x0003, 0x0000, },
    { 0x0015, 0x0002, 0x0000, },
    { 0x001D, 0x0003, 0x0000, },
    { 0x0023, 0x0001, 0x0000, },
    { 0x002F, 0x0000, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299C50_63D2F0[5] = {
    { 0x0001, 0x0001, 0x0000, },
    { 0x000B, 0x0003, 0x0000, },
    { 0x0013, 0x0001, 0x0000, },
    { 0x002F, 0x0000, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

Newscaster D_80299C70_63D310[3] = {
    { 0x0000, 0x0003, 0x0000, },
    { 0x0001, 0x0003, 0x0000, },
    { 0x03E8, 0x0003, 0x0000, },
};

// is this a struct?
u16 D_80299C84_63D324[3] = {
    154, // x
    75,  // y
    1,   // start
};

Vtx D_80299C90_63D330[4] = {
    {{{-800, -800, 0}, 0, {0, 0}, {100, 100, 100, 100}}},
    {{{ 800, -800, 0}, 0, {0, 0}, {100, 100, 100, 100}}},
    {{{-800,  800, 0}, 0, {0, 0}, {100, 100, 100, 100}}},
    {{{ 800,  800, 0}, 0, {0, 0}, {100, 100, 100, 100}}},
};

Gfx D_80299CD0_63D370[3] = {
    gsSPVertex(D_80299C90_63D330, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 1, 0),
    gsSPEndDisplayList(),
};

Lights1 D_80299CE8_63D388 = gdSPDefLights1(0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x08);

Lights1 D_80299D00_63D3A0 = gdSPDefLights1(0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08);

Lights3 D_80299D18_63D3B8 = gdSPDefLights3(0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

Lights1 D_80299D50_63D3F0 = gdSPDefLights1(0xC8, 0xC8, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08);

Lights2 D_80299D68_63D408 = gdSPDefLights2(0x32, 0x32, 0x32, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x08,
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x08);

Lights2 D_80299D90_63D430 = gdSPDefLights2(0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0x7F, 0x00, 0x00,
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

f32 D_80299DB8_63D458 = 200.0f;
f32 D_80299DBC_63D45C = 0.0f;
f32 D_80299DC0_63D460 = 2000.0f;
f32 D_80299DC4_63D464 = -261.0f;
f32 D_80299DC8_63D468 = 237.0f;
f32 D_80299DCC_63D46C = 132.0f;
f32 D_80299DD0_63D470 = 320.0f;
f32 D_80299DD4_63D474 = 230.0f;
f32 D_80299DD8_63D478 = 320.0f;
f32 D_80299DDC_63D47C = 1.0f;
f32 D_80299DE0_63D480 = 1.0f;
f32 D_80299DE4_63D484 = 1.0f;
f32 D_80299DE8_63D488 = 0.0f;
f32 D_80299DEC_63D48C = 1.0f;
f32 D_80299DF0_63D490 = 0.0f;
f32 D_80299DF4_63D494 = 0.0f;
u8  D_80299DF8_63D498 = 9;

/*
  1 - NEWSFLASH
  2 - Newscaster
  3 - Main splash (rotating spaceship)
  4 - black screen
  5 - blue screen (scrolling)
  6 - black screen
  7 - black screen
  8 - static spaceship
  9 - NEWSFLASH + 200 credz
  A - black screen
*/
u8  D_80299DFC_63D49C = 0; // intro state
u8  D_80299E00_63D4A0 = 3; // unused
u8  D_80299E04_63D4A4 = 0;
u16 D_80299E08_63D4A8 = 0;
u16 D_80299E0C_63D4AC = 0;

u16 D_80299E10_63D4B0 = 0xFF;
u8  D_80299E14_63D4B4 = 0; // tooth star counter
u8  D_80299E18_63D4B8 = 0;
u16 D_80299E1C_63D4BC = 0;
s8  D_80299E20_63D4C0 = 0;
s8  D_80299E24_63D4C4 = 0;
s8  D_80299E28_63D4C8 = 0; // always 0

s16 D_80299E2C_63D4CC = 0xFF;
s16 D_80299E30_63D4D0 = 1000; // unused
s16 D_80299E34_63D4D4 = 0;
s16 D_80299E34_63D4D8 = 0;  // unused
s16 D_80299E3C_63D4DC = 0;  // newscaster tile index
s16 D_80299E40_63D4E0 = 0;

// Copyright "(C)"
u8 D_80299E44_63D4E4[] = {
    0x40, 0x59, 0x40, 0x59, 0x48, 0x59, 0x48, 0x99, 0x48, 0x99, 0x48, 0x99, 0x48, 0x5B, 0x40, 0x5B,
    0x40, 0x5B, 0x40, 0x1B, 0x38, 0x59, 0x40, 0x59, 0x69, 0x53, 0xAB, 0x0D, 0xAB, 0x0D, 0xAB, 0x0D,
    0x82, 0x13, 0x40, 0x5B, 0x40, 0x5B, 0x40, 0x5B, 0x38, 0x19, 0xC4, 0x09, 0xFE, 0x01, 0xFE, 0x01,
    0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0xED, 0x05, 0x48, 0x99, 0x38, 0x1B, 0xAB, 0x4B, 0xFE, 0x01,
    0xFE, 0x01, 0xFD, 0xC1, 0xCC, 0x0B, 0xFD, 0x81, 0xFE, 0x01, 0xFE, 0x01, 0xE4, 0xC7, 0x38, 0x1B,
    0xFD, 0x81, 0xFE, 0x01, 0xFE, 0x01, 0xB3, 0xC9, 0x08, 0x01, 0x40, 0xC1, 0x9A, 0xC1, 0x72, 0x01,
    0x51, 0x41, 0x31, 0x09, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0x51, 0x41, 0x08, 0x01, 0x18, 0x43,
    0x5A, 0x15, 0x28, 0xC7, 0x08, 0x01, 0x08, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0x61, 0xC1,
    0x08, 0x01, 0x6A, 0x97, 0xAB, 0x4D, 0xB3, 0x8F, 0x93, 0x51, 0x6A, 0x59, 0xD4, 0x43, 0xFE, 0x01,
    0xFE, 0x01, 0xED, 0x01, 0x61, 0xC1, 0xDC, 0x89, 0xFE, 0x01, 0xFE, 0x01, 0xFD, 0xC1, 0x48, 0x97,
    0x51, 0xCD, 0xED, 0x05, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01,
    0xAB, 0xCD, 0x62, 0x59, 0x41, 0x8D, 0x40, 0x93, 0xAB, 0xC9, 0xCC, 0x01, 0xDC, 0x81, 0xEC, 0xC1,
    0xCC, 0x49, 0x6A, 0x91, 0x08, 0x01, 0x08, 0x01, 0x41, 0x8D, 0x30, 0x13, 0x40, 0x97, 0x31, 0x09,
    0x08, 0x01, 0x08, 0x01, 0x08, 0x01, 0x08, 0x01, 0x08, 0x01, 0x08, 0x01, 0x5A, 0x17, 0x28, 0x13,
    0x30, 0x13, 0x40, 0x95, 0x5A, 0x57, 0x49, 0xCF, 0x41, 0x8D, 0x41, 0x8D, 0x5A, 0x15, 0x49, 0x19,
};

Gfx D_80299F38_63D5D8[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0xFF60CDF8),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH | G_CLIPPING),
    gsDPSetColorDither(G_CD_BAYER),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPClipRatio(FRUSTRATIO_4),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s16 D_80299FC0_63D660 = 0;
s16 D_80299FC4_63D664 = 360;
s16 D_80299FC8_63D668 = 0;

// ========================================================
// .bss
// ========================================================

u16  D_80302E60[2];
u8*  D_80302E64;

u8   D_80302E68[0x8]; // pad

// might be static in func_80295FAC_63964C but do not appear to make much difference
u8   D_80302E70;
u8   D_80302E71;
Newscaster *D_80302E74;

u8   D_80302E78[0x10]; // pad

u8   D_80302E88[0xad578]; // 710008 ?


// ========================================================
// .text
// ========================================================

void func_80294E50_6384F0(void) {
    func_802988E8_63BF88();
}

void func_80294E70_638510(Gfx **dl, u8 alpha) {
    draw_rectangle(dl++, 0, 0, 320, 240, 0, 0, 0, alpha);
}

void func_80294EB8_638558(Gfx **dl) {
    guPerspective(&D_80204278->unk37410, D_80302E60, 33.0f, 1.33333333f, 100.0f, 15000.0f, 1.0f);

    gSPPerspNormalize((*dl)++, D_80302E60[0]); // different to debug?

    guScale(&D_80204278->unk37450, D_80299DDC_63D47C, D_80299DE0_63D480, D_80299DE4_63D484);
    guScale(&D_80204278->unk374D0, D_80299DDC_63D47C, D_80299DE0_63D480, D_80299DE4_63D484);
    guLookAt(&D_80204278->unk37490, D_80299DB8_63D458, D_80299DBC_63D45C, D_80299DC0_63D460, 0.0f, 0.0f, 0.0f, D_80299DE8_63D488, D_80299DEC_63D48C, D_80299DF0_63D490);

    gSPMatrix((*dl)++, &D_80204278->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204278->unk37450, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204278->unk37490, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*dl)++, &D_80204278->unk374D0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_802950B8_638758(void) {
    s16 *src;
    s16 *dst;

    font_init();
    if (gRegion == REGION_EU) {
        language_select_menu(0);
    }
    UnpackRNC((RNC_fileptr)img_intro_newscaster_5_rgba16_rnc_rgba16__rnc, D_80302E88);
    UnpackRNC((RNC_fileptr)img_intro_newscaster_1_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x9B460);
    UnpackRNC((RNC_fileptr)img_intro_newscaster_2_rgba16_rnc_rgba16__rnc, D_80302E88 + 0xA0A50);
    UnpackRNC((RNC_fileptr)img_intro_newscaster_3_rgba16_rnc_rgba16__rnc, D_80302E88 + 0xA6040);
    UnpackRNC((RNC_fileptr)img_intro_newscaster_4_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x35800);
    UnpackRNC((RNC_fileptr)img_intro_newsflash_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x3A000);
    UnpackRNC((RNC_fileptr)img_space_background_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x28000);
    UnpackRNC((RNC_fileptr)img_menu_trademark_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x74050);

    // load "lang34.dat"
    load_level_text_data(gEepromGlobal.language, 33, D_80231AA0, D_80231D50.data);

    src = get_message_address_by_id(MSG_CONTROLLER_NOT_CONNECTED);
    dst = D_802042F0;
    COPY_MESSAGE(src, dst);

    src = get_message_address_by_id(MSG_PRESS_START);
    dst = D_80204368;
    COPY_MESSAGE(src, dst);
}

void func_80295234_6388D4(void) {
    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, 312, 232);
    gSPDisplayList(D_801D9E7C++, D_80158368);

    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_80299DC4_63D464, D_80299DC8_63D468, D_80299DCC_63D46C);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, D_80299DD0_63D470, D_80299DD4_63D474, D_80299DD8_63D478, 0x10000, 0x10000, 0x10000);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(D_801D9E7C++, D_801542D0);        // load spaceship texture
    gSPDisplayList(D_801D9E7C++, D_802EEB20_6921C0); // load spaceship model
    gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);
}

void func_8029548C_638B2C(void) {
}

void func_80295494_638B34(Gfx **arg0, u16 arg1) {
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    u16 sp66;
    u16 sp64;

    sp66 = 160;
    sp64 = 120;

    D_80299DC4_63D464 = D_80299DB8_63D458;
    D_80299DC8_63D468 = D_80299DBC_63D45C;

    func_80294EB8_638558(&D_801D9E7C);
    gSPDisplayList((*arg0)++, &D_80158368);
    gSPNumLights((*arg0)++, 1);
    gSPLight((*arg0)++, &D_80299D50_63D3F0.l, 1);
    gSPLight((*arg0)++, &D_80299D50_63D3F0.a, 2);

    if (arg1 < 20) {
        sp74 = (sp66 - (arg1 << 3)) - 1;
        sp6C = sp66 + (arg1 << 3) + 1;
        if (sp74 < 8) {
            sp74 = 8;
        }
        if (sp6C > 312) {
            sp6C = 312;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, sp74, 120, sp6C, 121);

    } else if (arg1 < 0x28) {
        sp70 = (sp64 - ((arg1 / 2) * 0xC)) + 119;
        sp68 = (sp64 + ((arg1 / 2) * 0xC)) - 120;
        if (sp70 < 8) {
            sp74 = 8; // unused but important for eu
        }
        if (sp68 > 232) {
            sp68 = 232;
        }
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, sp70, 312, sp68);
    } else {
        gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    }

    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, 0, 0, 0, FTOFIX32(8.0), FTOFIX32(8.0), FTOFIX32(8.0));

    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gDPSetRenderMode((*arg0)++, G_RM_ZB_PCL_SURF, G_RM_ZB_PCL_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
    gSPDisplayList((*arg0)++, D_80299CD0_63D370);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void black_out_screen(Gfx **dl) {
    gSPDisplayList((*dl)++, &D_801582C0);
    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, 320, 240);
    gDPSetPrimColor((*dl)++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
    gDPSetCombineMode((*dl)++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetRenderMode((*dl)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPFillRectangle((*dl)++, 0, 0, 321, 241);
}

void func_8029597C_63901C(uSprite *sprite, u8 mode) {
    static u8   scaleY = 0;  // .data (D_80299FCC_63D66C)
    static s16  scaleX = 60; // .data (D_80299FD0_63D670)
    s16 temp_t2;
    u8 flip_x = 0;

    if (mode != 0) { // 0 for spin in, 1 for thumbnail
        scaleX = 60;
        scaleY = 0;
    }

    temp_t2 = ((scaleY * 260.0f) / 48.0) + 60.0;

    if (scaleY < 24) {
        flip_x = 1;
    }

    func_801366BC(&D_801D9E7C, 0xFF, 0xFF, 0xFF, 0xFF);
    draw_sprite(
        &D_801D9E7C,
        sprite,
        320,
        240,
        ABS(scaleX), // scale_x
        (scaleY * 195.0f / 48.0) + 45.0,
        flip_x,
        0,
        (48 - scaleY) + ((temp_t2 - ABS(scaleX)) / 2),
        (48 - scaleY),
        16);

    if (scaleY < 49) {
        if (scaleY < 24) {
            scaleX -= temp_t2 / 48;
        } else {
            scaleX += temp_t2 / 19;
        }
        scaleY++;
    }
}

void func_80295C38_6392D8(u8 arg0, u8 arg1) {
    gSPDisplayList(D_801D9E7C++, &D_801582C0);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, D_80299E10_63D4B0, D_80299E10_63D4B0, D_80299E10_63D4B0, 0xFF);

    draw_chunked_image(0, 0, 320, 256, &D_801D9E7C, D_80302E88);

    switch (arg0) {
    case 1:
        D_80302E64 = D_80302E88 + 0x9B460; // newscaster image 1
        break;
    case 2:
        D_80302E64 = D_80302E88 + 0xA0A50; // newscaster image 2
        break;
    case 3:
        D_80302E64 = D_80302E88 + 0xA6040; // newscaster image 3
        break;
    }

    if (arg0) {
        draw_chunked_image(112, 20, 96, 96, &D_801D9E7C, D_80302E64);
    }
    if (arg1) {
        draw_chunked_image(112, 131, 96, 96, &D_801D9E7C, D_80302E88 + 0x35800); // newscaster image 4 (body/hands?)
    }

    if ((D_80299E14_63D4B4 >= D_80299C84_63D324[2]) && ((D_80299C84_63D324[2] + 7) >= D_80299E14_63D4B4)) {
        // sparkling smile
        switch ((D_80299E14_63D4B4 - D_80299C84_63D324[2]) / 2) {
        case 0:
            D_80302E64 = img_intro_sparkling_smile_1_i8__png;
            break;
        case 1:
        case 3:
            D_80302E64 = img_intro_sparkling_smile_3_i8__png;
            break;
        case 2:
            D_80302E64 = img_intro_sparkling_smile_2_i8__png;
            break;
        }
        func_801356C0(D_80299C84_63D324[0], D_80299C84_63D324[1], 32, 32, &D_801D9E7C, D_80302E64, 32.0f, 32.0f, 8);
        D_80299E14_63D4B4++;
    } else {
        D_80299E14_63D4B4 = 0;
    }
}

// could there be a file split here?

// draw_space_background_image_at_x
void func_80295EB0_639550(s32 x) {
    func_801366BC(&D_801D9E7C, 0xFF, 0xFF, 0xFF, 0xFF);
    draw_sprite(&D_801D9E7C, (uSprite *)(D_80302E88 + 0x28000), 160, 128, 320, 241, 0, 0, x, 0, 16);
    func_80129594(&D_801D9E7C, D_80204278);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
}

#if 0

// #define SHADE 0
// #define PRIMITIVE 0

// s16 D_80299FD4_63D674 = 0;
// s16 D_80299FD8_63D678 = 0;
// s32 D_80299FDC_63D67C = 0;

// s32 D_80299FE0_63D680 = 0;
// s32 D_80299FE4_63D684 = 0;
// s32 D_80299FE8_63D688 = 0;
// u8  D_80299FEC_63D68C = 0;

// u8  D_80299FF0_63D690 = 0;
// s16 D_80299FF4_63D694 = 1;
// s8  D_80299FF8_63D698 = 0;
// s16 D_80299FFC_63D69C = 320;

// s16 D_8029A000_63D6A0 = 0;
// f32 D_8029A004_63D6A4 = 1.0f;
// f32 D_8029A008_63D6A8 = 1.0f;
// u8  D_8029A00C_63D6AC = 0;

// s8  D_8029A010_63D6B0 = 251;
// u8  D_8029A014_63D6B4 = 46;
// u16 D_8029A018_63D6B8 = 0;
// u8  D_8029A01C_63D6BC = 1;

u8  D_8029A020_63D6C0 = 0;
u16 D_8029A024_63D6C4 = 0;
u16 D_8029A028_63D6C8 = 0;
f32 D_8029A02C_63D6CC = 0;

u8  D_8029A030_63D6D0 = 0;
u16 D_8029A034_63D6D4 = 0;
u16 D_8029A038_63D6D8 = 0;
s16 D_8029A03C_63D6DC = 0;


void func_80295FAC_63964C(struct018 *arg0) {
    static s16 D_80299FD4_63D674 = 0;
    static s16 D_80299FD8_63D678 = 0;
    static s32 D_80299FDC_63D67C = 0;

    static s32 D_80299FE0_63D680 = 0;
    static s32 D_80299FE4_63D684 = 0;
    static s32 D_80299FE8_63D688 = 0;
    static u8  D_80299FEC_63D68C = 0;

    static u8  D_80299FF0_63D690 = 0;
    static s16 D_80299FF4_63D694 = 1;
    static s8  D_80299FF8_63D698 = 0;
    static s16 D_80299FFC_63D69C = 320;

    static s16 D_8029A000_63D6A0 = 0;
    static f32 D_8029A004_63D6A4 = 1.0f;
    static f32 D_8029A008_63D6A8 = 1.0f;
    static u8  D_8029A00C_63D6AC = 0;

    static s8  D_8029A010_63D6B0 = 251;
    static u8  D_8029A014_63D6B4 = 46;
    static u16 D_8029A018_63D6B8 = 0;
    static u8  D_8029A01C_63D6BC = 1;

    // static u8  D_8029A020_63D6C0 = 0;
    // static u16 D_8029A024_63D6C4 = 0;
    // static u16 D_8029A028_63D6C8 = 0;
    // static f32 D_8029A02C_63D6CC = 0;

    // static u8  D_8029A030_63D6D0 = 0;
    // static u16 D_8029A034_63D6D4 = 0;
    // static u16 D_8029A038_63D6D8 = 0;
    // static s16 D_8029A03C_63D6DC = 0;

    u8  spC7;
    s16 spC4;
    s16 spC0;
    s16 spB8[4]; // pad
    s16 spB6;
    s16 spB4;    // pad
    s16 spB2;
    s16 spA8[5]; // pad

    if (D_80204284 == 5) {
        D_80299DFC_63D49C = 6;
        D_80204284 = 1;
        D_80299E1C_63D4BC = 0;
        D_8029A038_63D6D8 = 0;
        D_80299E08_63D4A8 = 0;
        D_80299E0C_63D4AC = 0xFF;

        D_80299DD0_63D470 = 270.0f;
        D_80299DD4_63D474 = 180.0f;
        D_80299DD8_63D478 = 180.0f;

        D_80299DB8_63D458 = 0.0f;
        D_80299DBC_63D45C = 0.0f;
        D_80299DC0_63D460 = 3800.0f;

        D_80299DE8_63D488 = -1.0f;
        D_80299DF4_63D494 = 0.0f;

        D_8029A024_63D6C4 = 0;
        D_8029A028_63D6C8 = 0;
        D_80299FFC_63D69C = 8;
        D_8029A000_63D6A0 = 2;
    }
    if (D_80299FEC_63D68C == 0) {
        func_802950B8_638758(); // decompress newscaster video
        D_80299FEC_63D68C = 1;
        D_80299E10_63D4B0 = 254; // red level
    }

    gControllerInput = &D_802910E8[D_801D9ED0];

    switch (D_80299DFC_63D49C) {
    case 0:
        black_out_screen(&D_801D9E7C);
        if (gEepromGlobal.language == LANG_DEFAULT) {
            if (gRegion == REGION_EU) {
                if ((gControllerConnected == 0) && (D_80204270 != 0)) {
                    gEepromGlobal.language = LANG_ENGLISH;
                    spB6 = write_eeprom(4);
                } else {
                    if ((spC4 = language_select_menu(1)) != 0xFF) {
                        gEepromGlobal.language = spC4;
                        spB6 = write_eeprom(4);
                    }
                }
            }
        } else if ((gControllerConnected == 0) && (D_80204270 != 0)) {
            // show CONTROLLER_NOT_CONNECTED text + N64 controller model
            spB2 = D_80152350.unk0[D_80204270];
            if (spB2 >= 256) {
                spB2 = 0xFF;
            }

            D_80204270++;
            if (D_80204270 >= 180) {
                D_80204270 = 0;
            }

            func_80294EB8_638558(&D_801D9E7C);

            D_80299FD4_63D674++;
            D_80299FD4_63D674 = D_80299FD4_63D674 % 360;
            D_80299FD8_63D678++;
            D_80299FD8_63D678 = D_80299FD8_63D678 % 360;

            D_80299DB8_63D458 = 0.0f;
            D_80299DBC_63D45C = 0.0f;
            D_80299DC0_63D460 = 12000.0f;

            func_80298AC0_63C160();

            gDPPipeSync(D_801D9E7C++);
            gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
            gSPNumLights(D_801D9E7C++, 1);
            gSPLight(D_801D9E7C++, &D_80299D90_63D430.l, 1);
            gSPLight(D_801D9E7C++, &D_80299D90_63D430.a, 2);

            D_80299D90_63D430.l[0].l.col[0] = D_80299D90_63D430.l[0].l.colc[0] = (spB2 * 170) / 255;
            D_80299D90_63D430.l[0].l.col[1] = D_80299D90_63D430.l[0].l.colc[1] = (spB2 * 170) / 255;
            D_80299D90_63D430.l[0].l.col[2] = D_80299D90_63D430.l[0].l.colc[2] = (spB2 * 170) / 255;

            gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCombineLERP(D_801D9E7C++,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0);
            gDPSetRenderMode(D_801D9E7C++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gSPSetGeometryMode(D_801D9E7C++, G_CULL_BACK | G_LIGHTING);

            // FTOFIX32(10000.0 / 65536.0)
            func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0, 0, 0, 0, 0, 0x2710, 0x2710, 0x2710);
            gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_80299FD4_63D674, 0.0f, 1.0f, 0.0f);
            gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            gSPDisplayList(D_801D9E7C++, D_802F3C20_6972C0);
            gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);
        } else {
            if (D_8029A020_63D6C0 == 0) {
                D_80299E08_63D4A8++;
                if ((D_80299E08_63D4A8 > 10) && (D_80299E08_63D4A8 < 249)) {
                    spC7 = 0xFF;
                    if (D_80299E08_63D4A8 > 160) {
                        spC7 = 0xFF - D_80152040[D_80299E08_63D4A8 + 233];
                    }
                    if (spC7 == 0) {
                        D_80299E08_63D4A8 = 260;
                    }
                    func_801366BC(&D_801D9E7C, spC7, spC7, spC7, 0xFF);
                    draw_sprite(&D_801D9E7C, (uSprite *)(D_80302E88 + 0x74050), 0x140, 0xF0, 0x140, 0xF0, 0, 0, 0, 0, 0x10);
                    if (gRegion == REGION_EU) {
                        // add Copyright C
                        draw_sprite(&D_801D9E7C, (uSprite*)D_80299E44_63D4E4, 0xA, 0xC, 0xA, 0xC, 0, 0, 0x71, 0x90, 0x10);
                    }
                    D_80299DB8_63D458 = 1.0f;
                    D_80299DBC_63D45C = 501.0f;
                    D_80299DC0_63D460 = 6000.0f;
                }
                if ((D_80299E08_63D4A8 > 260) && (D_80299E08_63D4A8 < 750)) {
                    D_80299E08_63D4A8 = 761;
                    if (D_80299E08_63D4A8 == 500) {
                        D_80299E08_63D4A8 = 760;
                    }
                }
                if ((D_80299E08_63D4A8 >= 0x2F9) && (D_80299E08_63D4A8 < 0x3E8)) {
                    D_80152E90 = 0;
                    D_80204284 = 4;
                    D_80204288 = 10;
                }
                if (D_80299E08_63D4A8 >= 1000) {
                    if ((gEepromGlobal.unk8 & 1) == 0) {
                        D_8029A020_63D6C0 = 1;
                        D_8029A038_63D6D8 = 0;
                        D_80299E08_63D4A8 = 0;
                        D_80299E0C_63D4AC = 0xFF;
                        D_80299DD0_63D470 = 270.0f;
                        D_80299DD4_63D474 = 180.0f;
                        D_80299DD8_63D478 = 180.0f;
                        D_80299DB8_63D458 = 0.0f;
                        D_80299DBC_63D45C = 0.0f;
                        D_80299DC0_63D460 = 3800.0f;
                        D_80299DE8_63D488 = -1.0f;
                        D_80299DF4_63D494 = 0.0f;
                    } else {
                        D_80299E08_63D4A8 = 0;
                        D_80299E10_63D4B0 = 55;
                        D_80299DFC_63D49C = 1;
                        D_80299DC0_63D460 = 6000.0f;
                        D_8029A014_63D6B4 = 0x2E;
                    }
                }
            }
            gDPPipeSync(D_801D9E7C++);
        }
        break;
    case 1:                                         /* switch 1 */
        if (D_80299E08_63D4A8 == 20) {
            gCurrentMusicTrack = NO_MUSIC;
            func_801337DC(0, 2.0f, 1.0f, 20.0f);
            func_8013385C(2.0f, 1.0f, 20.0f);
        }
        D_80299E08_63D4A8++;
        if (D_80299E08_63D4A8 == 0xC8) {
            // empty stub
        }
        if (D_80299E08_63D4A8 < 200) {
            black_out_screen(&D_801D9E7C);
            func_80295494_638B34(&D_801D9E7C, D_80299E08_63D4A8);
            if (D_80299E08_63D4A8 < 0x5F) {

            }
            if (D_80299E08_63D4A8 > 40) {
                func_8013328C(0x2C23, 0x9F, 0x40, 1.0f, (D_8029A014_63D6B4 * 100) + 0x1000, 0);
            }
            if (D_80299E08_63D4A8 > 50) {
                gSPDisplayList(D_801D9E7C++, &D_801582C0);

                for (D_8029A004_63D6A4 = 30.0f; D_8029A004_63D6A4 <= 260.0f; D_8029A004_63D6A4 += 8.0f) {
                    // simulate turning volume up
                    if (D_8029A004_63D6A4 <= D_8029A014_63D6B4) {
                        func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, D_80156AC0, 22.0f, 22.0f, 16); // |
                    } else {
                        func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, D_801562C0, 22.0f, 22.0f, 16); // .
                    }
                }
                // draw "CH 0" on screen
                func_801356C0(200, 0x28, 0x20, 0x20, &D_801D9E7C, D_801552C0, 22.0f, 22.0f, 0x10); // C
                func_801356C0(220, 0x28, 0x20, 0x20, &D_801D9E7C, D_80155AC0, 22.0f, 22.0f, 0x10); // H
                func_801356C0(250, 0x28, 0x20, 0x20, &D_801D9E7C, D_80157AC0, 22.0f, 22.0f, 0x10); // 0
            }
            if (D_80299E08_63D4A8 > 130) {
                D_8029A014_63D6B4 = 96;
            } else if (D_80299E08_63D4A8 > 80) {
                D_8029A014_63D6B4 = 88;
            } else if (D_80299E08_63D4A8 > 70) {
                D_8029A014_63D6B4 = 80;
            } else if (D_80299E08_63D4A8 > 60) {
                D_8029A014_63D6B4 = 72;
            } else if (D_80299E08_63D4A8 > 50) {
                D_8029A014_63D6B4 = 64;
            } else if (D_80299E08_63D4A8 > 35) {
                D_8029A014_63D6B4 = 56;
            }
        } else {
            D_8015517C = 1.0f;
            D_801546E0 = 2048;
            D_801546D8 = 1936; // volume related
            gCurrentMusicTrack = MUSIC_TRACK_NEWSCASTER;
            // dupe?
            D_8015517C = 1.0f;
            D_801546D8 = 1936;

            if (gRefreshRate == 50) {
                D_801546E0 = 1706; // (50 / 60) * 2048
            }
            gSPDisplayList(D_801D9E7C++, D_801582C0);
            if (D_80299E10_63D4B0 < 56) {
                D_80299E10_63D4B0 = 255; // pulse back to 255
            }
            D_80299E10_63D4B0 -= 5;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, D_80299E10_63D4B0, 125, 125, 255);
            draw_chunked_image(0, 0, 0x140, 0x100, &D_801D9E7C, D_80302E88 + 0x3A000);
            if (D_80299E08_63D4A8 < 320) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                for (D_8029A004_63D6A4 = 30.0f; D_8029A004_63D6A4 <= 260.0f; D_8029A004_63D6A4 += 8.0f) {
                    // simulate volume turning up...
                    if (D_8029A004_63D6A4 <= D_8029A014_63D6B4) {
                        func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, D_80156AC0, 22.0f, 22.0f, 16); // |
                    } else {
                        func_801356C0(D_8029A004_63D6A4, 170, 32, 32, &D_801D9E7C, D_801562C0, 22.0f, 22.0f, 16); // .
                    }
                }
                if (D_80299E08_63D4A8 > 240) {
                    D_8029A014_63D6B4 = 88;
                } else if (D_80299E08_63D4A8 > 260) {
                    D_8029A014_63D6B4 = 96;
                }
                // draw "CH 1" on screen
                func_801356C0(200, 0x28, 0x20, 0x20, &D_801D9E7C, D_801552C0, 22.0f, 22.0f, 16); // C
                func_801356C0(220, 0x28, 0x20, 0x20, &D_801D9E7C, D_80155AC0, 22.0f, 22.0f, 16); // H
                func_801356C0(250, 0x28, 0x20, 0x20, &D_801D9E7C, D_801572C0, 22.0f, 22.0f, 16); // 1
            }
        }
        if (D_80299E08_63D4A8 == 436) { // ? end? length of what?
            D_80299E08_63D4A8 = 0;
            D_80299DFC_63D49C = 2;
            D_80302E70 = 0;
            D_80302E71 = 0;
            D_80299E10_63D4B0 = 255;
            D_80299E18_63D4B8 = 0;
            D_80299FF0_63D690 = 0;
            D_8029A01C_63D6BC = 1;
            D_80299FF8_63D698 = 0;
        }
        gDPPipeSync(D_801D9E7C++);
        break;
    case 2:  // tv announcer                                       /* switch 1 */
        D_80299E08_63D4A8++;
        D_8029A038_63D6D8++;
        if (D_80299FF0_63D690 != 0xFF) {

            if (D_80299E08_63D4A8 == D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].startTime) {
                D_80299E2C_63D4CC = D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].sfx;
                D_80299E34_63D4D4 = 0;
                D_80299E3C_63D4DC = 0;
                D_80299E40_63D4E0 = 1;

                switch (D_80299E2C_63D4CC) {
                case 0x57:
                    D_80302E74 = D_80299A40_63D0E0;
                    break;
                case 0x120:
                    D_80302E74 = D_80299A58_63D0F8;
                    break;
                case 0x121:
                    D_80302E74 = D_80299A88_63D128;
                    break;
                case 0x122:
                    D_80302E74 = D_80299ACC_63D16C;
                    break;
                case 0x123:
                    D_80302E74 = D_80299AF8_63D198;
                    break;
                case 0x124:
                    D_80302E74 = D_80299B30_63D1D0;
                    break;
                case 0x125:
                    D_80302E74 = D_80299B74_63D214;
                    break;
                case 0x126:
                    D_80302E74 = D_80299B94_63D234;
                    break;
                case 0x127:
                    D_80302E74 = D_80299BC4_63D264;
                    break;
                case 0x128:
                    D_80302E74 = D_80299BF0_63D290;
                    break;
                case 0x129:
                    D_80302E74 = D_80299C20_63D2C0;
                    break;
                case 0x12A:
                    D_80302E74 = D_80299C50_63D2F0;
                    break;
                case 0xFF:
                    D_80302E74 = D_80299C70_63D310;
                    break;
                }

                if (D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].sfx != 0xFF) {
                    if (D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].sfx == 0x57) {
                        spC0 = 0x2500;
                    } else {
                        spC0 = 0x5500;
                    }
                    if (D_8029A020_63D6C0 == 0) {
                        if (gRefreshRate == 60) {
                            play_sound_effect(D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].sfx, 0, spC0, 1.2f, 0); // 0x3F99999A
                        } else {
                            play_sound_effect(D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].sfx, 0, spC0, 1.0f, 0);
                        }
                    }
                }
                D_80299E18_63D4B8++;
            } else {
                if ((D_80299960_63D000[D_80299FF0_63D690].msg[D_80299E18_63D4B8].startTime == 0) && (D_80299FF0_63D690 < 28)) {
                    D_80299E18_63D4B8 = 0;
                    D_80299E08_63D4A8 = 0;
                    D_80299FF0_63D690++;
                }
            }
            if (D_80299E40_63D4E0 != 0) {
                if (D_80302E74[D_80299E3C_63D4DC].time == D_80299E34_63D4D4) { // unk0
                    D_80302E70 = D_80302E74[D_80299E3C_63D4DC].tile; // unk2
                    D_80302E71 = D_80302E74[D_80299E3C_63D4DC].unk6; // unk4
                    D_80299E3C_63D4DC++;
                }
                D_80299E34_63D4D4++;
            }
        }
        if (D_80299FF0_63D690 == 17) {
            D_80299FF0_63D690++;
            D_80299DFC_63D49C = 9;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0xFF);
            D_8029A018_63D6B8 = 0;
            D_80299E10_63D4B0 = 105;
            D_80299E0C_63D4AC = 0;
            D_8029A010_63D6B0 = -2;
            UnpackRNC(&img_intro_heroes_for_hire_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x3A000); // heroes_for_hire image
        }

        if (D_80299FF0_63D690 == 0x1C) {
            D_80299FF0_63D690 = 0xFF;
            D_80299E14_63D4B4 = 1;
            func_80132F70(SFX_CHEAT_ENABLED, /* volume */ 0x5000);
            D_80302E70 = 1;
        }
        func_80295C38_6392D8(D_80302E70, D_80302E71);

        if ((D_80299FF0_63D690 > 0) && (D_80299FF0_63D690 < 4)) {
            if (D_8029A01C_63D6BC != 0) {
                UnpackRNC(&img_intro_space_station_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x3A000); // space_station img
                func_8029597C_63901C(D_80302E88 + 0x3A000, 1); // thumbnail
            } else if (D_80299FF0_63D690 == 1) {
                func_8029597C_63901C(D_80302E88 + 0x3A000, 1); // thumbnail
            } else {
                func_8029597C_63901C(D_80302E88 + 0x3A000, 0); // spin into full screen
            }
            D_8029A01C_63D6BC = 0;
        }
        if ((D_80299FF0_63D690 > 4) && (D_80299FF0_63D690 < 8)) {
            if (D_8029A01C_63D6BC != 0) {
                UnpackRNC(&img_intro_professor_cheese_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x3A000); // professor_cheese
                func_8029597C_63901C(D_80302E88 + 0x3A000, 1);
            } else if (D_80299FF0_63D690 == 5) {
                func_8029597C_63901C(D_80302E88 + 0x3A000, 1);
            } else {
                func_8029597C_63901C(D_80302E88 + 0x3A000, 0);
            }
            D_8029A01C_63D6BC = 0;
        }
        if ((D_80299FF0_63D690 > 13) && (D_80299FF0_63D690 < 17)) {
            if (D_8029A01C_63D6BC != 0) {
                UnpackRNC(&img_intro_president_frank_bloke_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x3A000); // president_frank_bloke
                func_8029597C_63901C(D_80302E88 + 0x3A000, 1);
            } else if (D_80299FF0_63D690 == 14) {
                func_8029597C_63901C(D_80302E88 + 0x3A000, 1);
            } else {
                func_8029597C_63901C(D_80302E88 + 0x3A000, 0);
            }
            D_8029A01C_63D6BC = 0;
        }
        if ((D_80299FF0_63D690 == 4) || (D_80299FF0_63D690 == 8)) {
            D_8029A01C_63D6BC = 1; // need to decompress next image
        }
        if (D_80299FF0_63D690 != 0xFF) {
            if (D_80299960_63D000[D_80299FF0_63D690].id != MSG_DUMMY) {
                load_default_display_list(&D_801D9E7C);
                set_menu_text_color(255, 255, 255, 255);
                select_font(0, 1, 1, 0);
                // update subtitle text
                func_8012EB4C(&D_801D9E7C, get_message_address_by_id(D_80299960_63D000[D_80299FF0_63D690].id), 160, 202, 16.0f, 16.0f, 16);
            }
        } else if (D_80299E08_63D4A8 > 45) {
            D_8029A020_63D6C0 = 1;
            D_8029A038_63D6D8 = 0;
            D_80299E08_63D4A8 = 0;
            D_80299E0C_63D4AC = 0xFF;
            D_80299DD0_63D470 = 270.0f;
            D_80299DD4_63D474 = 180.0f;
            D_80299DD8_63D478 = 180.0f;
            D_80299DB8_63D458 = 0.0f;
            D_80299DBC_63D45C = 0.0f;
            D_80299DC0_63D460 = 3800.0f;
            D_80299DE8_63D488 = -1.0f;
            D_80299DF4_63D494 = 0.0f;
            if ((gEepromGlobal.unk8 & 1) != 0) {
                gEepromGlobal.unk8 = 0;
                spB6 = write_eeprom(4);
            }
        }
        break;
    case 9: // heroes for hire?
        gSPDisplayList(D_801D9E7C++, D_801582C0);

        if ((D_80299E10_63D4B0 == 255) || (D_80299E10_63D4B0 == 105)) {
            D_8029A010_63D6B0 = -D_8029A010_63D6B0;
        }
        // is this really blue, or is it red?
        gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, D_80299E10_63D4B0, 255);

        D_80299E10_63D4B0 += D_8029A010_63D6B0;
        // newsflash
        draw_chunked_image(0, 0, 0x140, 0x100, &D_801D9E7C, D_80302E88 + 0x3A000);
        if (D_80299E0C_63D4AC++ > 20) {
            // show 200 credz popup
            draw_chunked_image(0xDC, 0x8C, 0x40, 0x40, &D_801D9E7C, img_intro_200_credz_rgba16__png);
            if (D_80299E0C_63D4AC == 40) {
                D_80299E0C_63D4AC = 0;
            }
        }

        if (D_8029A018_63D6B8++ == 300) {
            D_80299DFC_63D49C = 2;
            D_80299E10_63D4B0 = 0xFF;
        }
        break;
    case 3:  // title screen
        if (D_80299E1C_63D4BC == 1) {
            D_8015517C = 1.0f;
            D_801546E0 = 2048;
            D_801546D8 = 2048;
            gCurrentMusicTrack = MUSIC_TRACK_TITLE_SCREEN;
            // dupe
            D_8015517C = 1.0f;
            D_801546E0 = 2048;
            D_801546D8 = 2048;
        }

        D_80299DD4_63D474++;// += 1.0f;
        if (D_80299DD4_63D474 > 359.0) {
            D_80299DD4_63D474 = 0.0f;
        }
        D_80299DF4_63D494 += 1.0f;
        if (D_80299DF4_63D494 > 359.0f) {
            D_80299DF4_63D494 = 0.0f;
        }
        if (D_80299E1C_63D4BC < 1800) {
            D_80299DD8_63D478 += 1.0f;
            if (D_80299DD8_63D478 > 359.0) {
                D_80299DD8_63D478 = 0.0f;
            }
            D_80299DC4_63D464 = D_80152350.unk2D0[(s16)D_80299DF4_63D494] * D_80299DF8_63D498;
            D_80299DC8_63D468 = 0.0f;
            D_80299DCC_63D46C = (D_80152350.unk384[(s16)D_80299DF4_63D494] * D_80299DF8_63D498) - 2500;
        }
        if (D_80299E1C_63D4BC >= 1800) {
            if (D_80299E1C_63D4BC == 1800) {
                func_801337DC(0, 4.0f, 20.0f, 0);
            }
            D_80299DC4_63D464 += 42.0f;
            D_80299E10_63D4B0 = 0x1617 - (D_80299E1C_63D4BC * 3);
        }
        func_80294EB8_638558(&D_801D9E7C);
        func_80295234_6388D4();

        func_80136418(&D_801D9E7C, D_80299E10_63D4B0);
        func_801360C8(&D_801D9E7C, (uSprite *)(D_80302E88 + 0x50000), 0x100, 0x80, 0x100, 0x7E, 0, 0, 0x20, 0x20, 0xFDE8);
        func_80136418(&D_801D9E7C, D_80299E10_63D4B0);
        func_801360C8(&D_801D9E7C, (uSprite *)(D_80302E88 + 0x28000), 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);

        load_segments(&D_801D9E7C, D_80204278);
        load_default_display_list(&D_801D9E7C);

        set_menu_text_color(D_80299E10_63D4B0, D_80299E10_63D4B0, 0, 0xFF);
        select_font(0, 0, 0, 0);
        if ((D_80299E1C_63D4BC < 1800) && (gControllerConnected != 0)) {
            // PRESS START
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_PRESS_START), 0xA0, 0xC8, 16.0f, 16.0f);
        }
        D_80299E1C_63D4BC++;
        if (D_80299E1C_63D4BC >= 1885) {
            if (D_80204288 >= 6) {
                D_80204288 = 0;
            }
            D_80204288++;
            if (D_80204288 == 1) {
                D_80299E08_63D4A8 = 0;
                D_80299E10_63D4B0 = 55;
                D_80299DFC_63D49C = 1;
                D_80299DC0_63D460 = 6000.0f;
                D_8029A014_63D6B4 = 46;
                D_80299FEC_63D68C = 0;
            } else {
                func_801337DC(0, 10.0f, 20.0f, 0);
                func_80298F1C_63C5BC(arg0->framebuffer, D_80302E88 + 0x62000);
                D_80299DFC_63D49C = 10;
                D_80299FF8_63D698 = 0;
                D_80299E04_63D4A4 = 1;
                D_8029A00C_63D6AC = 32;
                gCurrentMusicTrack = NO_MUSIC;
            }
        }
        break;
        break;
    case 5:  // title screen logo pop-in
        D_8015517C = 1.0f;
        D_801546E0 = 2048;
        D_801546D8 = 1;
        gCurrentMusicTrack = MUSIC_TRACK_NEWSCASTER;
        D_80299E10_63D4B0 = 0xFF;
        if (D_80299DC4_63D464 == -2616.0f) {
            UnpackRNC(&img_sssv_logo_rgba16_rnc_rgba16__rnc, D_80302E88 + 0x50000); // sssv_logo
        }
        gSPDisplayList(D_801D9E7C++, D_801582C0);

        D_80299DC4_63D464 += 42.0f;

        D_80299DD4_63D474++; // += 1.0f;
        if (D_80299DD4_63D474 >= 359.0) {
            D_80299DD4_63D474 = 0.0f;
        }

        D_80299E08_63D4A8++;
        func_80294EB8_638558(&D_801D9E7C);
        func_80295234_6388D4();
        D_80302E64 = D_80302E88 + 0x28000;
        func_80136418(&D_801D9E7C, D_80299E10_63D4B0);
        func_801360C8(&D_801D9E7C, D_80302E88 + 0x28000, 0xA0, 0x80, 0x140, 0xF1, 0, 0, 0, 0, 0xFFFF);

        func_801360C8(
            &D_801D9E7C,
            D_80302E88 + 0x50000,
            0x100,
            0x80,
            D_80299FFC_63D69C + D_80299E08_63D4A8 * 4,
            D_8029A000_63D6A0 + D_80299E08_63D4A8 * 2,
            0,
            0,
            0x9C - D_80299E08_63D4A8 * 2,
            0x5E - D_80299E08_63D4A8,
            0xFDE8);
        if (D_8029A00C_63D6AC != 0) {
            func_80298C70_63C310(D_8029A00C_63D6AC);
            D_8029A00C_63D6AC--;
        }
        if (D_80299DC4_63D464 == -12.0f) {
            D_80299DFC_63D49C = 3;
            D_8029A004_63D6A4 = 1.0f;
            D_80299E10_63D4B0 = 0xFF;
            D_80299E1C_63D4BC = 0;
            D_80299E08_63D4A8 = 0;
        }
        break;
    case 6:  // loading something? immediately before 5
        if (D_80299E1C_63D4BC == 0) {
            D_80299E10_63D4B0 = 0;
        }
        gCurrentMusicTrack = NO_MUSIC;
        D_80204290 = 1;
        D_80299E28_63D4C8 = 0;
        D_80299E1C_63D4BC = 0;
        D_80299E0C_63D4AC = 0; // ?
        D_80299FEC_63D68C = 0;
        D_80299E10_63D4B0 = 0xFF;
        D_80299FF4_63D694 = 1;
        D_8029A004_63D6A4 = 1.0f;
        D_8029A008_63D6A8 = 1.0f;
        D_80299DFC_63D49C = 5;  // title screen
        D_80299FF8_63D698 = 1;
        D_80299E04_63D4A4 = 1;
        D_80299E08_63D4A8 = 0;
        D_80299E0C_63D4AC = 0xFF;
        D_80299DD0_63D470 = 270.0f;
        D_80299DD4_63D474 = 110.0f;
        D_80299DD8_63D478 = 180.0f;

        D_80299DB8_63D458 = 0.0f;
        D_80299DBC_63D45C = 0.0f;
        D_80299DC0_63D460 = 3800.0f;

        D_80299DE8_63D488 = -1.0f;
        D_80299DF4_63D494 = 0.0f;

        D_80299DC4_63D464 = -2616.0f;
        D_80299DC8_63D468 = 0.0f;
        D_80299DCC_63D46C = -196.0f;

        D_8029A00C_63D6AC = 0;

        if ((D_80204288 == 10) && ((gEepromGlobal.unk8 & 1) == 1)) {
            D_80204288 = 0;
            D_80299E10_63D4B0 = 55;
            D_80299DFC_63D49C = 1;
            D_80299DC0_63D460 = 6000.0f;
            D_8029A014_63D6B4 = 46;
        }
        break;
    case 10:
        black_out_screen(&D_801D9E7C);
        if (D_8029A00C_63D6AC != 0) {
            func_80298C70_63C310(D_8029A00C_63D6AC);
            D_8029A00C_63D6AC--;
            if (D_8029A00C_63D6AC == 0) {
                stop_all_sounds();
                D_80299E24_63D4C4 = 1;
            }
        }
        break;
    case 8:
        black_out_screen(&D_801D9E7C);
        func_80294EB8_638558(&D_801D9E7C);
        func_80295234_6388D4();
        func_80136418(&D_801D9E7C, D_80299E10_63D4B0);
        func_801360C8(&D_801D9E7C, D_80302E88 + 0x28000, 160, 128, 320, 241, 0, 0,  0,  0, 0xFFFF);
        func_801360C8(&D_801D9E7C, D_80302E88 + 0x50000, 256, 128, 256, 126, 0, 0, 32, 32, 0xFDE8);
        D_80299DC4_63D464 = D_80299DC8_63D468 = D_80299DCC_63D46C = 0.0f;
        D_80299DB8_63D458 = D_80299DBC_63D45C = 0.0f;
        D_80299DC0_63D460 = 4000.0f;

        if (D_80299DD8_63D478++ >= 359.0f) {
            D_80299DD8_63D478 = 0.0f;
        }
        if (D_80299DD4_63D474++ >= 359.0f) {
            D_80299DD4_63D474 = 0.0f;
        }
        if (D_80299DD0_63D470++ >= 359.0f) {
            D_80299DD0_63D470 = 0.0f;
        }
        break;
    default:
        break;
    }

    if (D_8029A020_63D6C0 != 0) {
        D_8029A030_63D6D0 = 0xFF;
        if (D_80299FF8_63D698 == 0) {
            D_80299FF8_63D698 = 1;
            D_8029A034_63D6D4 = 0;

            D_8029A02C_63D6CC = 180.0f;
            D_8029A024_63D6C4 = 320;
            D_8029A028_63D6C8 = 0;
        }

        if (D_8029A034_63D6D4 == 0) {
            if (D_8029A024_63D6C4 <= 0) {
                D_8029A034_63D6D4 = 1;
            } else {
                D_8029A024_63D6C4 -= 20;
            }
        } else {
            if (D_8029A02C_63D6CC >= 359.0f) {
                D_8029A02C_63D6CC = 0.0f;
            }
            if (((s32) D_8029A02C_63D6CC % 180) == 0) {
                D_8029A028_63D6C8 += 4;
            }

            D_8029A024_63D6C4 = ABS(D_80152350.unk2D0[(s16)D_8029A02C_63D6CC] / D_8029A028_63D6C8);
            if (D_8029A028_63D6C8 < 5) {
                D_8029A02C_63D6CC += 6.0f;
            }
        }
        black_out_screen(&D_801D9E7C);
        D_80302E64 = D_80302E88 + 0x28000;
        func_80295EB0_639550(D_8029A024_63D6C4);
        if (D_8029A028_63D6C8 > 4) {
            D_80299DFC_63D49C = 5;
            D_8029A020_63D6C0 = 0;
            D_80299E08_63D4A8 = 0;
            D_80299E0C_63D4AC = 0xFF;
            D_80299DD0_63D470 = 270.0f;
            D_80299DD4_63D474 = 110.0f;
            D_80299DD8_63D478 = 180.0f;
            D_80299DB8_63D458 = 0.0f;
            D_80299DBC_63D45C = 0.0f;
            D_80299DC0_63D460 = 3800.0f;
            D_80299DE8_63D488 = -1.0f;
            D_80299DF4_63D494 = 0.0f;
            D_80299DC4_63D464 = -2616.0f;
            D_80299DC8_63D468 = 0.0f;
            D_80299DCC_63D46C = -196.0f;
            D_80299FFC_63D69C = 8;
            D_8029A000_63D6A0 = 2;
        }
    }

    if ((gControllerInput->button & START_BUTTON) &&
        (D_80299DFC_63D49C == 3) &&
        (D_8029A00C_63D6AC == 0) &&
        (D_8029A020_63D6C0 == 0)) {
        play_sound_effect(0x8F, 0, 0x5000, 1.0f, 0);
        func_801337DC(0, 30.0f, 20.0f, 0);
        func_8012A400();
        func_80298F1C_63C5BC(D_80162658[D_80152EB8 ^ 1].framebuffer, D_80302E88 + 0x62000);
        D_80299DFC_63D49C = 10;
        D_80299FF8_63D698 = 0;
        D_80299E04_63D4A4 = 1;
        D_8029A00C_63D6AC = 32;
        gCurrentMusicTrack = NO_MUSIC;
        D_80204288 = 0;
    }
    if ((D_80299E04_63D4A4 > 0) && (D_80299E04_63D4A4 < 5)) {
        D_80299E04_63D4A4++;
    } else {
        if (((gControllerInput->button & START_BUTTON) == 0) &&
            ((gControllerInput->button & A_BUTTON) == 0)) {
            D_80299E04_63D4A4 = 0;
        }
    }
    if (gControllerInput->button & START_BUTTON) {
        if ((D_80299DFC_63D49C != 7) && (D_80299DFC_63D49C != 10) && (D_80299E04_63D4A4 == 0) && (D_80299E20_63D4C0 == 0)) {
            D_80204288 = 0;
            if ((D_80299DFC_63D49C == 0) && (D_80299E08_63D4A8 < 260)) {

            } else {
                if ((D_80299DFC_63D49C != 3) && (D_8029A020_63D6C0 == 0) && (D_80299DFC_63D49C != 5)) {
                    if (((D_80299DFC_63D49C == 0) || (D_80299DFC_63D49C == 1) || (D_80299DFC_63D49C == 2) || (D_80299DFC_63D49C == 9)) && ((gEepromGlobal.unk8 & 1) == 1)) {

                    } else {
                        play_sound_effect(0x8F, 0, 0x5000, 1.0f, 0);
                        func_8013385C(2.0f, 20.0f, 0);
                        func_801337DC(0, 2.0f, 20.0f, 0);
                        D_8029A020_63D6C0 = 1;
                        D_80299FF8_63D698 = 0;
                        D_80299E04_63D4A4 = 1;
                    }
                }
            }
        }
    }
}
#else

s16 D_80299FD4_63D674 = 0;
s16 D_80299FD8_63D678 = 0;
s32 D_80299FDC_63D67C = 0;

s32 D_80299FE0_63D680 = 0;
s32 D_80299FE4_63D684 = 0;
s32 D_80299FE8_63D688 = 0;
u8  D_80299FEC_63D68C = 0;

u8  D_80299FF0_63D690 = 0;
s16 D_80299FF4_63D694 = 1;
s8  D_80299FF8_63D698 = 0;
s16 D_80299FFC_63D69C = 320;

s16 D_8029A000_63D6A0 = 0;
f32 D_8029A004_63D6A4 = 1.0f;
f32 D_8029A008_63D6A8 = 1.0f;
u8  D_8029A00C_63D6AC = 0;

s8  D_8029A010_63D6B0 = 251;
u8  D_8029A014_63D6B4 = 46;
u16 D_8029A018_63D6B8 = 0;
u8  D_8029A01C_63D6BC = 1;

u8  D_8029A020_63D6C0 = 0;
u16 D_8029A024_63D6C4 = 0;
u16 D_8029A028_63D6C8 = 0;
f32 D_8029A02C_63D6CC = 0;

u8  D_8029A030_63D6D0 = 0;
u16 D_8029A034_63D6D4 = 0;
u16 D_8029A038_63D6D8 = 0;
s16 D_8029A03C_63D6DC = 0;

s16 D_8029A040_63D6E0 = 100;
s16 D_8029A044_63D6E4 = 100;
s16 D_8029A048_63D6E8 = 4000;

s16 D_8029A04C_63D6EC = 0;
s16 D_8029A050_63D6F0 = 0;

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_6384F0/func_80295FAC_63964C.s")
#endif

void func_802988E8_63BF88(void) {
    gScreenWidth = 320;
    gScreenHeight = 240;
    load_segments(&D_801D9E7C, D_80204278);
    func_80129430(&D_801D9E7C);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
    gDPPipeSync(D_801D9E7C++);

    D_80152EA8.vp.vscale[0] = gScreenWidth * 2;
    D_80152EA8.vp.vscale[1] = gScreenHeight * 2;
    D_80152EA8.vp.vtrans[0] = gScreenWidth * 2;
    D_80152EA8.vp.vtrans[1] = gScreenHeight * 2;

    gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    // reset used counters
    D_80204278->usedSprites = 0;
    D_80204278->usedModelViewMtxs = 0;
    D_80204278->usedSprites = 0; // set twice?
    D_80204278->unk39310 = 0;
    D_80204278->usedHilites = 0;

    func_80295FAC_63964C(&D_80162658[D_80152EB8]);
    if (D_80299E24_63D4C4 != 0) {
        D_80152E90 = 0;  // select game overlay
        D_80204284 = 4;
    }
}

void func_80298AC0_63C160(void) {
    gSPClearGeometryMode(D_801D9E7C++, -1);
    gSPSetGeometryMode(D_801D9E7C++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH | G_CLIPPING);

    gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);

    gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
    gDPSetTextureDetail(D_801D9E7C++, G_TD_CLAMP);
    gDPSetTextureLUT(D_801D9E7C++, G_TT_NONE);
    gDPSetTexturePersp(D_801D9E7C++, G_TP_PERSP);
    gDPSetTextureConvert(D_801D9E7C++, G_TC_FILT);

    gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_4);
    gDPSetDepthSource(D_801D9E7C++, G_ZS_PIXEL);
}
