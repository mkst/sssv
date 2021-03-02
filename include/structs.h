#ifndef STRUCTS_US_H
#define STRUCTS_US_H

typedef struct struct035 struct035;
typedef struct struct044 struct044;

typedef struct {
    u8  pad0[0xC];
    s16 unkC;
    s16 unkE;
    u8  pad10[0xB4];
    u16 unkC4;
    u16 unkC6;
    u8  unkC8[0x6];
    u16 unkCE;
    u8  unkD0[0xA];
    u16 unkDA;
    u16 unkDC; // initialised?
    u8  padDE[0x2];
    f32 unkE0;
} struct000;

typedef struct {
    s32 score;
    s16 unk4;
    u8  pad6[0x2];
    s16 unk8; // level index
    u16 unkA;
    u16 unkC;
} struct001;

/*
states:
  02 - standing
  04 - walking
  05 - in air?
  06 - collecting something?
  8D - in water
  8F - swimming
  DD - ???
*/
typedef struct {
    /* 0x00 */  u16 state; // state? standing, walking, jumping,
    /* 0x02 */  u8  pad2[0x2];
    /* 0x04 */  s16 xPos;
    /* 0x06 */  u8  pad6[0x2];
    /* 0x08 */  s16 zPos;
    /* 0x0A */  u8  padA[0x2];
    /* 0x0C */  s16 yPos;
    /* 0x0E */  u8  padE[0xE];
    /* 0x1C */  s32 xVelocity;
    /* 0x20 */  s32 zVelocity;
    /* 0x24 */  s32 yVelocity;
    /* 0x28 */  u8  pad28[0x4];
    /* 0x2C */  s16 yRotation;
    /* 0x2E */  u8  pad2E[0x2];
    /* 0x30 */  s16 unk30;
    /* 0x32 */  s16 unk32;
    /* 0x34 */  u8  pad34[0xC];
    /* 0x40 */  u16 unk40;
    /* 0x42 */  u16 unk42;
    /* 0x44 */  u8  pad44[0x2];
    /* 0x46 */  u16 unk46;
    /* 0x48 */  u8  unk48[0x2];
    /* 0x4A */  s8  unk4A;
    /* 0x4B */  u8  unk4B;
    /* 0x4C */  s16 unk4C;
    /* 0x4E */  u8  pad4E;
    /* 0x4F */  u8  unk4F;
    /* 0x50 */  u8  pad50[0x80];
    /* 0xD0 */  s32 unkD0;
    /* 0xD4 */  u8  padD4[0x40];
    /* 0x114 */ s16 unk114[4];
    /* 0x11C */ struct044 *unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8  pad128[0x24];
    /* 0x14C */ s16 health;
    /* 0x14E */ u8  pad14E[0x12];
    /* 0x160 */ u8  unk160;
    /* 0x161 */ u8  unk161;
    /* 0x162 */ u8  unk162;
    /* 0x163 */ u8  unk163;
    /* 0x164 */ u8  pad164[0x8];
    /* 0x16C */ struct035* unk16C;
    /* 0x170 */ u8  pad170[0x1C];
    /* 0x18C */ u8  unk18C;
    /* 0x18D */ u8  pad18D[0xB];
    /* 0x198 */ s32 unk198; // pointer?
    /* 0x19C */ u8  pad19C[0xD1];
    /* 0x26D */ u8  unk26D;
    /* 0x26E */ u8  pad26E[0x72];
    /* 0x2E0 */ s16 skillAEnergy[2]; // seems to be an array?
    /* 0x2E4 */ s16 skillBEnergy[2]; // same...
    /* 0x2E8 */ u8  unk2E8;
    /* 0x2E9 */ u8  unk2E9;
    /* 0x2EA */ u8  unk2EA;
    /* 0x2EB */ u8  pad2EB;
    /* 0x2EC */ s16 unk2EC;
    /* 0x2EE */ u8  pad2EE[0x14];
    /* 0x302 */ s16 unk302;
    /* 0x302 */ s16 unk304;
    /* 0x306 */ u8  pad306[0x2];
    /* 0x308 */ s16 unk308;
    /* 0x30A */ u8  unk30A[0x4];
    /* 0x30E */ s16 unk30E;
    /* 0x310 */ u8  pad310[0x10];
    /* 0x320 */ s32 unk320; // pointer to somewhere
    /* 0x324 */ u8  pad324[0x4];
    /* 0x328 */ u16 unk328;
    /* 0x32A */ u8  pad32A[0x1E];
    /* 0x348 */ u16 unk348;
    /* 0x34A */ u16 unk34A;
    /* 0x34C */ s16 unk34C;
    /* 0x34E */ s16 unk34E;
    /* 0x34E */ s16 unk350;
    /* 0x352 */ s16 unk352;
    /* 0x354 */ s16 unk354;
    /* 0x356 */ s16 unk356;
    /* 0x358 */ s16 unk358;
    /* 0x35A */ u8  pad35A[0x6];
    /* 0x360 */ s8  unk360;
    /* 0x361 */ u8  unk361;
    /* 0x362 */ u8  unk362;
    /* 0x363 */ u8  unk363;
    /* 0x364 */ u8  pad364[0x2];
    /* 0x366 */ u8  unk366;
    /* 0x367 */ u8  pad367;
    /* 0x368 */ u8  unk368;
    /* 0x369 */ u8  pad369;
    /* 0x36A */ u8  unk36A;
    /* 0x36B */ u8  unk36B;
    /* 0x36C */ u8  pad36C[0x2];
    /* 0x36E */ u8  unk36E;
} Animal;

typedef struct {
    s8  unk0;
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
    s16 unk0;
} struct010;

typedef struct {
    struct010 *unk0;
    s32 unk4;
} struct006; // OSMesg

typedef struct {
    u8  pad0;
    s32 unk8; // pointer to some audio struct
} struct007;

// merge these two?
typedef struct {
    u8  pad0[0x3BBA8];
    s16 unk3BBA8;
    u8  pad3BBAA[0x1E];
    s16 unk3BBC8;
    u8  pad3BBCA[0x1E];
    s32 unk3BBE8;
    u8  pad3BBEC[0x4];
} struct008; // size 0x3BBF0

typedef struct {
    u8  pad0[0x3F798];
    s16 unk3F798;
    u8  pad3F79A[0x1E];
    s16 unk3F7B8;
    u8  pad3F7BA[0x1E];
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
    s32 unk4; //  is this for anything?
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

typedef struct struct017 struct017;

struct struct017 {
    /* 0x00 */ u16 unk0; // pointer?
    /* 0x02 */ u16 sndID;
    /* 0x04 */ u8  pad4[0x8];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ u16 counter;
    /* 0x10 */ u8  pad10[0xE];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u16 unk20;
    /* 0x22 */ s16 sndSlot;
    /* 0x24 */ u8  sndState;
    /* 0x25 */ u8  pad25[0x3];
    /* 0x28 */ s32 unk28; // ptr?
    /* 0x2C */ struct017 *prev; // maybe
    /* 0x30 */ struct017 *next;
};

typedef struct struct026 struct026;

struct struct026 {
    /* 0x00 */ struct026* unk0;
    /* 0x04 */ u8  pad4[0x1A];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u8  pad20[0xC];
    /* 0x2C */ struct026 *prev; // maybe
    /* 0x30 */ struct026 *next;
};

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
    /* 0x00000 */ u8  pad0[0x4278];
    /* 0x04278 */ struct002* unk4278;
    /* 0x0427C */ u8  pad427C[0x5384];
    /* 0x9600 */  s32 unk9600;
    /* 0x9604 */  u8  pad9604[0x739c];
    /* 0x109A0 */ struct014 unk109A0[8];
    /* 0x267A0 */ s32 unk267A0;
    /* 0x267A4 */ u8  pad267A4[0xc0cc];
    /* 0x32870 */ u8  unk32870[1][0x18]; // probably more than 1
    /* 0x32888 */ u8  pad32888[0xD08];
    /* 0x33590 */ Mtx unk33590[250]; // modelViewMtx (might only be 240?)
    /* 0x37410 */ Mtx unk37410;  // projection matrix 1
    /* 0x37450 */ Mtx unk37450;  // projection matrix 2
    /* 0x37490 */ Mtx unk37490;  // projection matrix 3
    /* 0x374D0 */ Mtx unk374D0;  // modelview matrix 1
    /* 0x37510 */ u8  unk37510[0x1400];
    /* 0x38910 */ s32 unk38910;
    /* 0x38914 */ s32 unk38914;
    /* 0x38918 */ s32 unk38918; // used modelview matrices (unk33590, max 240?)
    /* 0x3891C */ u8  pad3891C[0x9f4];
    /* 0x39310 */ s16 unk39310;
                  u8  pad39311[0x2327];
                  Light unk3B638;
                  Light unk3B640;
                  s8  unk3B648;
                  s8  unk3B649;
                  s8  unk3B64A;
                  u8  pad3B64B[0x5];
                  s8  unk3B650;
                  s8  unk3B651;
                  s8  unk3B652;
                  u8  pad3B653;
                  s8  unk3B654;
                  s8  unk3B655;
                  s8  unk3B656;
                  u8  pad3B657;
                  s8  unk3B658;
                  s8  unk3B659;
                  s8  unk3B65A;
} DisplayList;

typedef struct {
  /* 0x00 */ s32 unk0;
  /* 0x04 */ u8  pad4[0x4];
  /* 0x08 */ s32 unk8;
  /* 0xC; */ s32 unkC;
  /* 0x10 */ s32 unk10;
  /* 0x14 */ s32 unk14;
  /* 0x18 */ s32 unk18;
  /* 0x1C */ s32 unk1C;
  /* 0x20 */ s32 unk20;
  /* 0x24 */ s32 unk24;
  /* 0x28 */ s32 unk28;
  /* 0x2C */ s32 unk2C;
  /* 0x30 */ s32 unk30;
  /* 0x34 */ s32 unk34;
  /* 0x38 */ s32 unk38;
  /* 0x3C */ s32 unk3C;
  /* 0x40 */ s32 unk40;
  /* 0x44 */ s32 unk44;
  /* 0x48 */ s32 unk48;
  /* 0x4C */ s32 unk4C;
  /* 0x50 */ s32 unk50;
  /* 0x54 */ s32 unk54;
  /* 0x58 */ u8 unk58[0x10];
} struct031; // size 0x68

typedef struct {
    /* 0x00000 */ struct031 unk0[2]; // dont think this is quite right?
    /* 0x000D0 */ u8  padD0[0x410];
    /* 0x004E0 */ DisplayList* unk4E0;
    /* 0x004E4 */ u8  pad4E4[0x7cfc];
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
    /* 0x00 */ s32 unk0;        // eeprom checksum?
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8  unkC;
    /* 0x0D */ s8  unkD;
    /* 0x0E */ s8  unkE;
    /* 0x0F */ u8  padF[0x17];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8  unk28;
    /* 0x29 */ u8  pad29[0x17];
} Eeprom; // size 0x40

typedef struct {
    s32 unk0; // vaddr
    s16 unk4; // outLen
    u8  pad6[0x2];
    s32 unk8;
    u8  unkC[0x4];
    s32 unk10;
    u8  unk14[0x4];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8  unk2C[0x4];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8  unk60[0x10];
    s32 unk70;
} struct019; // audio

typedef struct {
    s32 unk0;
    s16 unk4;
} struct020;

typedef struct {
    u8 unk0;
    u8 pad1[0x3];
    s32 unk4;
    s32 unk8;
    u8 unkC;
} struct021;

typedef struct {
    ALSeqFile *seqFile;
    s32 unk4;
} struct022;

typedef struct {
    s32 unk0;
    s32 fontAddress;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  padB;
    u16 glyphBytes;
} struct023;

typedef struct {
    s32 start;
    s32 end;
} struct024; // only RNC?

typedef struct {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ u8  pad4[0x4A];
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ u8  pad50[0x4];
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ u8  pad5A[0x6];
    /* 0x60 */ s16 unk60;
    /* 0x62 */ u8  pad62[0x12];
               f32 unk74;
               f32 unk78;
               f32 unk7C;
               u8  unk80[0x1C];
    /* 0x9C */ u16 unk9C; // maybe not?
    /* 0x9E */ u8  pad9E[0x2C];
    /* 0xCA */ s16 unkCA;
    /* 0xCC */ s16 unkCC;
    /* 0xCE */ s16 unkCE;
    /* 0xD0 */ s16 unkD0;
    /* 0xD2 */ s16 unkD2;
    /* 0xD4 */ u8  unkD4[0x8];
} struct025; // size 0xDC

typedef struct {
    s16 unk0;
    u16 unk2;
    u8  pad4[0x2];
    u16 unk6;
    u16 unk8;
    u8  padA[0x4];
    u16 unkE;
    u8  pad10[0x4];
    u16 unk14;
    u16 unk16;
    u16 unk18;
    s16 unk1A;
    u8  pad1C[0x2];
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  pad28;
    u8  unk29;
    u8  unk2A;
    u8  unk2B;
    u8  unk2C;
    u8  unk2D;
    u8  unk2E;
    u8  pad2F[0x2];
    u8  unk31;
    u8  pad32;
    u8  unk33;
    u8  pad34;
    u8  unk35;
} struct027;

typedef struct {
    s16 unk0;
    s16 unk2;
    u8  pad4[0x4];
    s16 unk8;
    s16 unkA;
} struct028;

typedef struct {
    u8  unk0;
    u8  pad1[0xFF];
} struct029; // size 0x100

typedef struct {
    /* 0x00 */  Animal* animal;
    /* 0x04 */  s16     health;
    /* 0x06 */  s16     unk6; // health related too?
    /* 0x08 */  s16     unk8; // ALSO health?
    /* 0x0A */  s16     unkA; // 0x40?
} struct033;

typedef struct {
    s32 unk0;
    u8  pad4[0x2D00];
    s32 unk2D04;
} struct034;

struct struct035 {
  /* 0x00 */  u16 unk0;
  /* 0x02 */  u8  pad2[0x13];
              u8  unk15; // checked if 4?
              u8  pad16[0x2];
              s32 unk18;
              u8  pad1C[0x60];
  /* 0x7C */  u16 unk7C;
  /* 0x80 */  s32 unk80;
  /* 0x84 */  u8  pad84[0x18];
  /* 0x9C */  u16 unk9C;
  /* 0x9E */  u16 unk9E;
              u8  padA0[0x4];
              u16 unkA4;
              u8  padA6[0x4];
              u16 unkAA;
              u16 unkAC;
              u8  padAE[0x14];
              s16 unkC2;
              s16 unkC4;
              u8  padC6[0x2];
              s16 unkC8;
  /* 0xCA */  s16 unkCA;
  /* 0xCC */  s16 unkCC;
  /* 0xCE */  s16 unkCE;
  /* 0xD0 */  s16 unkD0;
  /* 0xD2 */  s16 unkD2;
  /* 0xD4 */  u8  padD4[0x6];
  /* 0xDA */  s16 unkDA;
  /* 0xDC */  s16 unkDC;
  /* 0xDE */  u8  padDE[0x2];
  /* 0xE0 */  s16 unkE0;
  /* 0xE2 */  s16 unkE2;
  /* 0xE4 */  u8  padE4[0x8];
}; // size 0xEC

typedef struct {
    /* 0x0000 */ u8  pad0[0x3EB0];
    /* 0x3EB0 */ struct035 *unk3EB0;
    /* 0x3EB4 */ Animal *animal;
} struct036;

typedef struct {
    struct035* unk0;
} struct037;

typedef struct {
    s16 unk0;
    u8  pad2[0xab6];
} struct038; // size 0xAB8

typedef struct {
    s32 unk0;
    s32 unk4;
} struct039;

typedef struct {
    s16 min;
    s16 max;
    u8  r;
    u8  g;
    u8  b;
    // u8  pad7;
} Fog; // size 0x8

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} struct004; // sizze 0x18

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 europe;
    s16 ice;
    s16 jungle;
    s16 desert;
    s16 final;
    s16 hidden;
    s16 unk16;
    s16 unk18;
} struct005; // size 0x1A

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
    u16 unk20;
    u8  pad22[0xB];
    s8  unk2D;
    u8  pad2E[0x4];
    u8  unk32;
} struct030;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s32 unk30; // tbd
    s32 unk34; // tbd
    s32 unk38;
    s32 unk3C;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    u8  pad46;
    f32 unk48;
} struct032;

typedef struct {
    union {
        u32  uw;
        u8   ub[4];
    } unk0;
    s32 unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  unkB;
    u8  unkC;
    u8  unkD;
    u8  unkE;
    u8  unkF;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  pad19[0x227];
    u16 unk240;
    u16 unk242;
    s16 unk244;
    u8  unk246[0x2];
    s32 unk248;
    u8  pad24C[0xDC];
    s16 unk328;
    s16 unk32A;
    s32 unk32C;
    Animal *unk330;
    u8  pad334[0x4];
  } struct045; // size 0x338

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} struct040;

typedef struct {
    u8  pad0[0x1E];
    s16 unk1E;
} struct041;

typedef struct {
    struct041 *unk0;
} struct042;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} struct043;

struct struct044 {
    struct044 *unk0;
    s32 unk4;
    s32 unk8;
} ;

#endif
