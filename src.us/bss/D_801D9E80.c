#include <ultra64.h>
#include "common.h"

// 0x8015E1D0 to 0x8023F410


u8 D_801D9E80_padding[173404 - (240 + 64)];

// dlabel D_801D9E88
//     /* 801D9E88 */ .space 0x04

// dlabel D_801D9E8C
//     /* 801D9E8C */ .space 0x04

// dlabel D_801D9E90
//     /* 801D9E90 */ .space 0x04

// dlabel D_801D9E94
//     /* 801D9E94 */ .space 0x04

// dlabel D_801D9E98
//     /* 801D9E98 */ .space 0x20

// dlabel D_801D9EB8
//     /* 801D9EB8 */ .space 0x10

// dlabel D_801D9EC8
//     /* 801D9EC8 */ .space 0x01

// dlabel D_801D9EC9
//     /* 801D9EC9 */ .space 0x0B

// dlabel D_801D9ED4
//     /* 801D9ED4 */ .space 0x2A0FC

// dlabel gScreenWidth
//     /* 80203FD0 */ .space 0x02

// dlabel gScreenHeight
//     /* 80203FD2 */ .space 0x0E

// dlabel D_80203FE0
//     /* 80203FE0 */ .space 0x260

// dlabel D_80204240
//     /* 80204240 */ .space 0x20

// dlabel gRegion
//     /* 80204260 */ .space 0x10

// dlabel D_80204270
//     /* 80204270 */ .space 0x04

// dlabel D_80204274
//     /* 80204274 */ .space 0x04

// dlabel D_80204278
//     /* 80204278 */ .space 0x04

// dlabel D_8020427C
//     /* 8020427C */ .space 0x04

// dlabel D_80204280
//     /* 80204280 */ .space 0x02

// dlabel D_80204282
//     /* 80204282 */ .space 0x02

// dlabel D_80204284
//     /* 80204284 */ .space 0x04

// dlabel D_80204288
//     /* 80204288 */ .space 0x04

// dlabel D_8020428C
//     /* 8020428C */ .space 0x04

// dlabel D_80204290
//     /* 80204290 */ .space 0x02

// dlabel D_80204292
//     /* 80204292 */ .space 0x02

// dlabel gRefreshRate
//     /* 80204294 */ .space 0x04

// dlabel D_80204298
//     /* 80204298 */ .space 0x08

// dlabel D_802042A0
//     /* 802042A0 */ .space 0x08

// dlabel D_802042A8
//     /* 802042A8 */ .space 0x44

// dlabel D_802042EC
//     /* 802042EC */ .space 0x04

char D_802042B0[60];
s32  D_802042EC; // OSMesg

s16  D_802042F0[60]; // 0x802042F0
s16  D_80204368[60]; // 0x80204368


u64 D_802043E0[0x1000 / 8]; // 0x802043E0
