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
    /* 0x00 */  u8  pad0[0x4];
    /* 0x04 */  s16 xPos;
    /* 0x06 */  u8  pad6[0x2];
    /* 0x08 */  s16 zPos;
    /* 0x0A */  u8  padA[0x2];
    /* 0x0C */  s16 yPos;
    /* 0x0E */  u8  padE[0xE];
    /* 0x1C */  s16 xVelocity;
    /* 0x1E */  u8  pad1E[0x2];
    /* 0x20 */  s16 zVelocity;
    /* 0x22 */  u8  pad22[0x2];
    /* 0x24 */  s16 yVelocity;
    /* 0x26 */  u8  pad26[0x6];
    /* 0x2C */  s16 yRotation;
    /* 0x2E */  u8  pad2E[0x11E];
    /* 0x14C */ u16 health;
    /* 0x2E0 */ s16 skillAEnergy;
    /* 0x2E2 */ u8  pad2E2[0x2];
    /* 0x2E4 */ s16 skillBEnergy;
} Animal;

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
    u8 pad0[0x38918];
    s32 unk38918;
} struct004;

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
    Animal *unk0;
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

typedef struct {
    u8  pad0[0x22];
    s16 unk22; // sound id?
} struct017;

typedef struct {
    u8 pad0[0x2BC0];
} struct014; // size 0x2BC0

typedef struct {
    u8 pad[0x18];
} struct011; // size 0x18

typedef struct {
    struct011 unk32870[1];
} struct002; //

typedef struct {
    /* 0x00000 */ u8 pad0[0x4278];
    /* 0x04278 */ struct002* unk4278;
    /* 0x0427C */ u8 pad427C[0xc724];
    /* 0x109A0 */ struct014 unk109A0[8];
    /* 0x267A0 */ u8  pad267A0[0xcdf0];
    /* 0x33590 */ Mtx unk33590[1]; // probably more than 1
    /* 0x335D0 */ u8  unk335D0[0x3e40];
    /* 0x37410 */ Mtx unk37410;  // projection matrix 1
    /* 0x37450 */ Mtx unk37450;  // projection matrix 2
    /* 0x37490 */ Mtx unk37490;  // projection matrix 3
    /* 0x374D0 */ Mtx unk374D0;  // modelview matrix 1
    /* 0x37510 */ u8  unk37510[0x3408];
    /* 0x38918 */ s32 unk38918;
} DisplayList;

typedef struct {
    /* 0x00000 */ u8  pad0[0x4E0];
    /* 0x00000 */ DisplayList* unk4E0;
    /* 0x00000 */ u8  pad4E4[0x7cfc];
    /* 0x081E0 */ s32 unk81E0;
    /* 0x081E4 */ u8  unk81E4[0x18fc];
    /* 0x09AE0 */ s32 unk9AE0;
    /* 0x09AE4 */ u8  unk9AE4[0x257c];
    /* 0x0C060 */ s32 unkC060;
    /* 0x0C064 */ u8  unkC064[0x1f3c];
    /* 0x0DFA0 */ s32 unkDFA0;
    /* 0x0DFA4 */ u8  padDFA4[0x18cdc];
    /* 0x26C80 */ s32 unk26C80;
    /* 0x26C84 */ u8  unk26C84[0x14f64];
    /* 0x3BBE8 */ s32 unk3BBE8;
} struct018;

typedef struct {
    /* 0x00 */ s32 unk0;        // checksum?
    /* 0x04 */ u8  unk4[0x8];
    /* 0x0C */ s8  unkC;
    /* 0x0D */ s8  unkD;
    /* 0x0E */ s8  unkE;
    /* 0x0F */ u8  padF[0x17];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8  pad28[0x18];
} Eeprom; // size 0x40

#endif
