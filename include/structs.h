#ifndef STRUCTS_US_H
#define STRUCTS_US_H

typedef struct {
    u8  pad0[0xC4];
    u16 unkC4;
    u16 unkC6;
    u8  unkC8[0x6];
    u16 unkCE;
    u8  unkD0[0xA];
    u16 unkDA;
    u16 unkDC; // initialised?
} struct000;

typedef struct {
    u8 pad0[0x4];
    s16 unk4;
    u8  pad6[0x2];
    s16 unk8;
    u16 unkA;
    u16 unkC;
} struct001;

typedef struct {
    u8  pad0[0x4];
    s16 unk4;
    u8  pad6[0x2];
    s16 unk8;
    u8  padA[0x2];
    s16 unkC;
    u8  padE[0x2];
    u8  pad10[0x13C];
    u16 unk14C;
    s32 unk150[0x10];
} struct002;

typedef struct {
    u8  unk0;
    u8  unk1;
    u8  unk2;
    u8  unk3;
} struct003;

typedef struct {
                u8  pad0[0x1E];
    /* 0x1E */  u8  countryCode;
                u8  pad1F;
    /* 0x20 */  u16 mode;
} RomHeader;

typedef struct {
    s32 unk0;
    u8  pad4[0x1C];
    s32 unk20;
} struct005;

typedef struct {
    s16 unk0;
} struct010;

typedef struct {
    struct010 *unk0;
    s32 unk4;
} struct006; // OSMesg

typedef struct {
    u8  pad0;
    s32 unk8;
} struct007;

// merge these two?
typedef struct {
    u8  pad0[0x3BBA8];
    s16 unk3BBA8;
    u8  pad3BBAA[0x1E];
    s16 unk3BBC8;
    u8  pad3BBCA[0x1E];
    s32 unk3BBE8;
} struct008; // size 0x3BBF0

typedef struct {
    u8  pad0[0x3F798];
    s16 unk3F798;
    u8  padunk3F79A[0x1E];
    s16 unk3F7B8;
    u8  padunk3F7BA[0x1E];
    s32 unk3F7D8;
} struct009;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8; // union?
    s16 unkA;
    u8  padA[0x4]; // padding?
} struct012; // size 0x10

typedef struct {
    u8  pad0[0x2D0];
    s16 unk2D0;
    u8  unk2D2[0xB2];
    s16 unk384;
} struct013;

typedef struct {
    struct002 *unk0;
    s32 unk8;
} struct015;

// is this even a struct
typedef struct {
    s8  unk0;
    u8  unk1[0x3];
    s16 unk4;
    u8  pad6[0x6];
    s16 unkC;
    u8  unkE[0x6];
    s16 unk14;
    u8  unk16[0x6];
    s16 unk1C;
    u8  unk1E[0x6];
    s16 unk24;
    u8  unk26[0x6];
    s16 unk2C;
    u8  unk2E[0x6];
    s16 unk34;
    u8  unk36[0x6];
    s16 unk3C;
} struct016;

// only used in main_123E0.c
typedef struct {
    s32 status;
    s32 controller;
} ControllerMesg;

typedef struct {
    s8  hasRumblePak; // or initialised ?
    u8  pad1;
    u16 unk2;
    u16 unk4;
    u8  pad6[0x6];
    u16 unkC;
    u8  padE[0x6];
    u16 unk14;
    u8  pad16[0x6];
    u16 unk1C;
    u8  pad1E[0x6];
    u16 unk24;
    u8  pad26[0x6];
    u16 unk2C;
    u8  pad2E[0x6];
    u16 unk34;
    u8  pad36[0x6];
    u16 unk3C;
    u8  pad3E[0x2A];
} Controller; // size 0x68

#endif
