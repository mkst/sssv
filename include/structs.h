#ifndef STRUCTS_US_H
#define STRUCTS_US_H

typedef struct struct035 struct035;
typedef struct struct044 struct044;
typedef struct struct049 struct049;
typedef struct struct055 struct055;
typedef struct struct065 struct065;
typedef struct struct069 struct069;
typedef struct struct070 struct070;
typedef struct struct071 struct071;
typedef struct struct101 struct101;
typedef struct struct103 struct103;

typedef struct Animal Animal;


typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    s16 unkC;   // used for perspective?
    s16 unkE;   // used for perspective?
    u16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    u8  pad18[0x2];
    u16 animalId; // starting animal id
    u16 unk1C;
    u16 unk1E;
    u16 biome;  // current biome
    u8  pad22[0x1E];
    s16 unk40;
    u8  pad42[0xA];
    s16 unk4C;
    s16 unk4E;
    u8  pad50[0x2];
    s16 unk52;  // texture bank?
    /* 0x54 */ u8  unk54;
    /* 0x54 */ u8  unk55;
    /* 0x54 */ u8  unk56;
    /* 0x54 */ u8  unk57;  // water primary alpha
    /* 0x54 */ u8  unk58;
    /* 0x54 */ u8  unk59;
    /* 0x54 */ u8  unk5A;
    /* 0x54 */ u8  unk5B;  // water env alpha
    /* 0x5C */ u8  pad5C[0x60];
    /* 0xBC */ Animal *unkBC;
    u8  padC0[0x4];
    u16 unkC4;
    s16 unkC6;
    u8  unkC8[0x6];
    u16 unkCE;  // evo suit colour
    u8  unkD0[0xA];
    u16 unkDA;  // scissor? width?
    u16 unkDC;  // initialised?
    u8  padDE[0x2];
    f32 unkE0;  // used for perspective
    u16 titleText[42];
    // u16 unkE6;
} struct000;

typedef struct {
    /* 0x0 */ s32 score;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ u8  pad6[0x2];
    /* 0x8 */ s16 unk8; // level index
    /* 0xA */ u16 unkA;
    /* 0xC */ s16 powercells; // powercells collected
} struct001;

struct struct069 {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
}; // size 0xA

struct struct070 {
    u8  unk0;
    u8  unk1;
    union {
        u8  b[2];
        s16 h;
    } unk2;
    union {
        u8  b[2];
        s16 h;
    } unk4;
    s16 unk6;
}; // size 0x8

struct struct103 {
 /* 0x0 */ u16 unk0;
 /* 0x2 */ s16 unk2;
 /* 0x4 */ s16 unk4; // used
 /* 0x6 */ s16 unk6; // used
 /* 0x8 */ s16 unk8; // used
 /* 0xA */ s16 unkA; // used
 /* 0xC */ s16 unkC; // used
 /* 0xE */ u16 unkE; // used    (also used as s16)
 /* 0x10 */ u16 unk10; // used
 /* 0x12 */ s16 unk12; // used
}; // size 0x14

typedef struct  {
    /* 0x3C8 */ s16 unk0; //unk3C8;
    /* 0x3CA */ s16 unk2; //unk3CA;
    /* 0x3CC */ s16 unk4; //unk3CC;
    /* 0x3CE */ u16 unk6; //unk3CE;
    /* 0x3D0 */ s16 unk8; //unk3D0;

} struct106;

/*
states:
  02 - standing
  03 - walking
  04 - running
  05 - in air?
  06 - collecting something?
  8D - in water
  8E - swimming slowly
  8F - swimming fast
  DD - ???
*/
struct Animal {
    /* 0x00 */  u16 state; // state? standing, walking, jumping,
    /* 0x02 */  u16 unk2;
    /* 0x04 */  s16 xPos;
    /* 0x06 */  u8  pad6[0x2];
    /* 0x08 */  s16 zPos;
    /* 0x0A */  u8  padA[0x2];
    /* 0x0C */  s16 yPos;
    /* 0x0E */  u8  padE[0xA];
    /* 0x18 */  s16 unk18;
    /* 0x1A */  u8  pad1A[0x2];
    /* 0x1C */  union {
                    s32 w;
                    s16 h;
                } xVelocity; // are these really unions or?
    /* 0x20 */  union {
                    s32 w;
                    s16 h;
                } zVelocity;
    /* 0x24 */  union {
                    s32 w;
                    s16 h;
                } yVelocity;
    /* 0x28 */  s16 unk28;
    /* 0x2A */  u8  pad2A[0x2];
    /* 0x2C */  s16 yRotation;
    /* 0x2E */  s16 unk2E;
    /* 0x30 */  s16 unk30;
    /* 0x32 */  s16 unk32;
    /* 0x34 */  s16 unk34;
    /* 0x36 */  s16 unk36;
    /* 0x38 */  u8  pad38[0x6];
    /* 0x3E */  u16 unk3E;
    /* 0x40 */  u16 unk40;
    /* 0x42 */  u16 unk42; // distance from camera (height?) cameraOffsetY?
    /* 0x44 */  u16 unk44;
    /* 0x46 */  u16 unk46;
    /* 0x48 */  u8  pad8[0x2];
    /* 0x4A */  s8  unk4A;
    /* 0x4B */  u8  unk4B;
    /* 0x4C */  struct {
                    s8  pad0  : 8;  // 0x4C
                    s8  pad8  : 8;  // 0x4D
                    s8  unk16 : 8;  // 0x4E
                    u8  unk24 : 1;  // 0x4F
                    u8  unk25 : 1;
                    u8  unk26 : 1;
                    u8  pad27 : 2;
                    u8  unk29 : 1;
                    u8  pad30 : 2;
                } unk4C;
    /* 0x50 */  u16 unk50;
    /* 0x52 */  u8  pad52[0x2];
    /* 0x54 */  u8  unk54;
    /* 0x55 */  u8  pad55[0x7];
    /* 0x5C */  u8  unk5C;
    /* 0x5D */  u8  unk5D;
    /* 0x5E */  u8  pad5E;
    /* 0x5E */  u8  unk5F;
    /* 0x60 */  Animal* unk60;
    /* 0x64 */  u8  pad64;
    /* 0x65 */  u8  unk65;
    /* 0x66 */  u8  pad66[0x2];
    /* 0x68 */  Animal *unk68;
    /* 0x6C */  Animal *unk6C;
    /* 0x70 */  Animal *unk70;
    /* 0x74 */  u8  pad74[0x8];
    /* 0x7C */  s16 unk7C;
    /* 0x80 */  s32 unk80;
    /* 0x84 */  u8  pad84[0x3C];
    /* 0xC0 */  s16 unkC0[1][8];
    /* 0xD0 */  Mtx unkD0; // this might be nonsense
    /* 0x110 */ u8  pad110[0x4];
    /* 0x114 */ s16 unk114[4];
    /* 0x11C */ struct044 *unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8  pad128[0x24];
    /* 0x14C */ s16 health;
    /* 0x14E */ s16 unk14E;
    /* 0x150 */ s16 unk150;
    /* 0x152 */ s16 unk152;
    /* 0x154 */ u8  unk154;
    /* 0x156 */ u8  pad155[0x3];
    /* 0x158 */ s32 unk158;
    /* 0x15C */ u8  unk15C;
    /* 0x15D */ u8  pad15D;
    /* 0x15E */ s16 unk15E;
    /* 0x160 */ u8  unk160;
    /* 0x161 */ u8  unk161;
    /* 0x162 */ u8  unk162;
    /* 0x163 */ u8  unk163;
    /* 0x164 */ u8  unk164;
    /* 0x165 */ u8  unk165[0x3];
    /* 0x168 */ Animal *unk168;
    /* 0x16C */ struct035* unk16C;
    /* 0x170 */ s8  unk170;
    /* 0x171 */ u8  pad171;
    /* 0x172 */ s16 unk172;
    /* 0x174 */ u8  pad174[0x4];
    /* 0x178 */ s16 unk178;
    /* 0x17A */ s16 unk17A;
    /* 0x17C */ s16 unk17C;
    /* 0x17E */ s16 unk17E;
    /* 0x180 */ s16 unk180;
    /* 0x182 */ s16 unk182;
    /* 0x184 */ s16 unk184;
    /* 0x186 */ u8  pad186[0x6];
    /* 0x18C */ u8  unk18C;
    /* 0x18D */ u8  unk18D[5];
    /* 0x192 */ u8  unk192;
    /* 0x193 */ u8  unk193[5];
    /* 0x198 */ Animal *unk198; // pointer?
    /* 0x19C */ u8  unk19C;
    /* 0x19E */ struct069 unk19E;
    /* 0x1A8 */ struct069 *unk1A8; // array of struct069s?
    /* 0x1AC */ struct070 unk1AC[4];
    /* 0x1CC */ u8  unk1CC;
    /* 0x1CD */ u8  unk1CD;
    /* 0x1CE */ u8  pad1CE[0x6];
    /* 0x1D4 */ u8  unk1D4;
    /* 0x1D5 */ u8  pad1D5[0x57];
    /* 0x22C */ u8  unk22C;
    /* 0x22D */ u8  pad22D[0xF];
    /* 0x23C */ u8  unk23C;
    /* 0x23D */ u8  unk23D;
    /* 0x23E */ u8  unk23E;
    /* 0x23F */ u8  unk23F;
    /* 0x240 */ u8  unk240;
    /* 0x241 */ u8  unk241;
    /* 0x242 */ s16 unk242;
    /* 0x244 */ s16 unk244;
    /* 0x246 */ u16 unk246;
    /* 0x248 */ Animal *unk248[9]; // tbd, at least 8
    /* 0x26C */ u8  unk26C;
    /* 0x26D */ u8  unk26D;
    /* 0x26E */ u8  pad26E[0x2];
    /* 0x270 */ u8  unk270;
    /* 0x271 */ u8  pad271;
    /* 0x272 */ u16 unk272; // flagged state, 1, 4, 8...
    /* 0x274 */ u8  unk274;
    /* 0x275 */ s8  unk275;
    /* 0x276 */ s16 unk276;
    /* 0x278 */ s16 unk278;
    /* 0x27A */ s16 unk27A;
    /* 0x27C */ s16 unk27C;
    /* 0x27E */ u8  pad27E[0x2];
    /* 0x280 */ Animal *unk280; // another one? is this a repeating array?
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8  pad286;
    /* 0x287 */ u8  unk287;
    /* 0x287 */ u16 unk288;
    /* 0x287 */ u8  unk28A;
    /* 0x287 */ u8  unk28B;
    /* 0x28C */ u16 unk28C;
    /* 0x28E */ u8  unk28E;
    /* 0x28F */ u8  pad28F;
    /* 0x290 */ s16 unk290;
    /* 0x292 */ u8  pad292[0x2];
    /* 0x294 */ union {
                    Animal *w;
                    s16 h[2];
                    s8  b[4];
                    u8  ub[4];
                } unk294;
    /* 0x298 */ union {
                    s16 h;
                    u8  ub[2];
                } unk298;
    /* 0x29A */ union {
                    s16 h;
                    s8  b;
                } unk29A;
    /* 0x29C */ u8 *unk29C;
    /* 0x2A0 */ s8  unk2A0;
    /* 0x2A1 */ s8  unk2A1;
    /* 0x2A2 */ u8  unk2A2;
    /* 0x2A3 */ u8  pad2A3;
    /* 0x2A4 */ s16 xPosTarget;
    /* 0x2A6 */ s16 zPosTarget;
    /* 0x2A8 */ s16 yPosTarget;
    /* 0x2AA */ u8  pad2AA[0x2];
    /* 0x2AC */ Animal* unk2AC;
    /* 0x2B0 */ u8  unk2B0;
    /* 0x2B1 */ u8  pad2B1[0x3];
    /* 0x2B4 */ struct {
                    u8  state : 4;
                    u8  unk4  : 3;
                    u8  unk7  : 1;
                    s8  unk8  : 8;
                    u32 pad10 : 16;
                } unk2B4;
    /* 0x2B8 */ s32 unk2B8;
    /* 0x2BC */ s32 unk2BC;
    /* 0x2C0 */ s32 unk2C0;
    /* 0x2C4 */ s32 unk2C4; // "FC" ?
    /* 0x2C8 */ u16 unk2C8;
    /* 0x2CA */ u8  pad2CA;
    /* 0x2CC */ Animal* unk2CC; // target for missiles?
    /* 0x2D0 */ s16 unk2D0;
    /* 0x2D2 */ u8  pad2D2[0x2];
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ s16 unk2DC;
    /* 0x2DE */ u8  unk2DE[0x2];
    /* 0x2E0 */ s16 skillAEnergy[2]; // seems to be an array?
    /* 0x2E4 */ s16 skillBEnergy[2]; // same...
    /* 0x2E8 */ u8  missileScaleLeft;  // scale factor for 'left' side missile
    /* 0x2E9 */ u8  missileScaleRight; // scale factor for 'right' side missile
    /* 0x2EA */ u8  missileSide; // selector for missile 1 or 2
    /* 0x2EB */ s8  unk2EB;
    /* 0x2EC */ s16 unk2EC; // (husky) bite energy?
    /* 0x2EE */ u16 unk2EE;
    // /* 0x2EE */ struct {
    //                 s16  unk0  : 10;
    //                 u16  unk10 : 6;
    //             } unk2EE;
    /* 0x2F0 */ u8  pad2F0[0x2];
    /* 0x2F2 */ u16 unk2F2;
    /* 0x2F4 */ u16 unk2F4;
    /* 0x2F6 */ u16 unk2F6; // tbd
    /* 0x2F8 */ u16 unk2F8;
    /* 0x2FA */ u16 unk2FA;
    /* 0x2FC */ u16 unk2FC;
    /* 0x2FE */ u16 unk2FE;
    /* 0x300 */ u16 unk300;
    /* 0x302 */ s16 unk302; // heading? facing?
    /* 0x304 */ s16 unk304;
    /* 0x306 */ s16 unk306;
    /* 0x308 */ s16 unk308;
    /* 0x30A */ s16 unk30A;
    /* 0x30C */ s16 unk30C;
    /* 0x30E */ s16 unk30E;
    /* 0x310 */ s16 unk310;
    /* 0x312 */ s16 unk312;
    /* 0x314 */ s16 unk314;
    /* 0x316 */ s16 unk316;
    /* 0x318 */ s16 unk318;
    /* 0x31A */ s16 unk31A;
    /* 0x31C */ s16 unk31C;
    /* 0x31E */ u8  pad31E[0x2];
    /* 0x320 */ Animal *unk320;
    /* 0x324 */ u16 unk324;
    /* 0x326 */ u16 unk326;
    /* 0x328 */ u16 unk328;
    /* 0x32A */ u16 unk32A;
    /* 0x32C */ s16 unk32C;
    /* 0x32E */ u8  pad32E[0x2];
    /* 0x330 */ Animal *unk330;
    /* 0x334 */ u16 unk334;
    /* 0x336 */ u8  pad336[0x2];
    /* 0x338 */ s32 unk338;
    /* 0x33C */ u8  pad33C[0xC];
    /* 0x348 */ s16 unk348; // (desert fox) dizziness duration and size
    /* 0x34A */ s16 unk34A; // (desert fox) dizziness recovery delay?
    /* 0x34C */ s16 unk34C;
    /* 0x34E */ s16 unk34E;
    /* 0x34E */ s16 unk350;
    /* 0x352 */ s16 unk352;
    /* 0x354 */ s16 unk354;
    /* 0x356 */ s16 unk356;
    /* 0x358 */ s16 unk358;
    /* 0x35A */ s16 unk35A;
    /* 0x35C */ s16 unk35C;
    /* 0x35E */ u16 unk35E;
    /* 0x360 */ s8  unk360;
    /* 0x361 */ s8  unk361;
    /* 0x362 */ u8  unk362;
    /* 0x363 */ u8  unk363;
    /* 0x364 */ u8  unk364;
    /* 0x365 */ u8  unk365; // current attack
    /* 0x366 */ u8  unk366;
    /* 0x367 */ u8  unk367;
    /* 0x368 */ s8  unk368;
    /* 0x369 */ u8  unk369;
    /* 0x36A */ u8  unk36A;
    /* 0x36B */ s8  unk36B;
    /* 0x36C */ u8  unk36C;
    /* 0x36D */ u8  unk36D; // sheep only?
    /* 0x36E */ s8  unk36E;
    /* 0x36F */ s8  unk36F;
    /* 0x370 */ struct103 unk370;
    /* 0x384 */ struct103 unk384; // s16 x 7
    /* 0x398 */ struct103 unk398;
    /* 0x3AC */ struct103 unk3AC;
    /* 0x3C0 */ u16 unk3C0; // this is another struct
    /* 0x3C2 */ s16 unk3C2;
    /* 0x3C4 */ u16 unk3C4;
    /* 0x3C6 */ s16 unk3C6;
    /* 0x3C8 */ struct106 unk3C8;
    /* 0x3D0 */ s16 unk3D2;
};

// WIP experiment to see if D_803D5530 is a different struct
typedef struct {
    /* 0x00 */  u16 state;
    /* 0x04 */  s32 xPos; // unions?
    /* 0x08 */  s32 zPos;
    /* 0x0C */  s32 yPos;
    /* 0x10 */  u8  pad10[0xC];
    /* 0x1C */  s32 xVelocity;
    /* 0x20 */  s32 zVelocity;
    /* 0x24 */  s32 yVelocity;
    /* 0x28 */  s16 unk28;
    /* 0x2A */  u8  pad2A[0x2];
    /* 0x2C */  s16 yRotation;
    /* 0x2E */  u8  pad2E[0x14];
    /* 0x42 */  u16 unk42;
    /* 0x44 */  u8  pad44[0x6];
    /* 0x4A */  s8  unk4A;
    /* 0x4B */  u8  pad4B[0x11];
    /* 0x5C */  u8  unk5C;
    /* 0x5D */  u8  pad5D[0x3];
    /* 0x60 */  Animal* unk60;
    /* 0x64 */  u8  pad64[0xFE];
    /* 0x162 */ u8  unk162;
} Camera;

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
    /* 0x20 */  s16 region;
} RomHeader;

typedef struct {
    s16 unk0;
} struct010;

typedef struct {
    struct010 *unk0;
    s32 unk4;
} struct006; // OSMesg

typedef struct {
    Acmd *unk0;
    u8  unk4[0x8];
    s32 unk8; // pointer to some audio struct
} struct007;

typedef struct {
    /* 0x0 */     u8  pad0[0x3F798];
    /* 0x3F798 */ u16 unk3F798;
    /* 0x3F79A */ u8  pad3F79A[0x1E];
    /* 0x3F7B8 */ u16 unk3F7B8;
    /* 0x3F7BA */ u8  pad3F7BA[0x1E];
    /* 0x3F7D8 */ u8 *unk3F7D8;
} struct009;

typedef struct {
    /* 0x0 */ s32 vStart;
    /* 0x4 */ s32 yScale;
    /* 0x8 */ s16 VIModeType;
    /* 0xA */ s16 unkA;
    /* 0xC */ u8  padC[0x4]; // padding/alignment?
} struct012; // size 0x10

typedef struct {
    u8  pad0[0x2D0];
    s16 unk2D0[90];
    s16 unk384[90]; // ?
} struct013;

typedef struct {
    Animal *unk0;
    s32 unk4; //  tbd what this points to
} struct015;

// is this even a struct
typedef struct {
    s16  unk0;
    s16  unk2;
    s16  unk4;
    u8   pad6[0x2];
} struct016; // size 0x8

// only used in main_123E0.c
typedef struct {
    s32 status;
    s32 controller;
} ControllerMesg;

typedef struct {
    /* 0x00 */ s16 unk0[4];
    /* 0x08 */ s16 unk8[4];
    /* 0x10 */ s16 unk10[4];
    /* 0x18 */ s16 unk18[4];
    /* 0x20 */ s16 unk20[4];
    /* 0x28 */ s16 unk28[4];
    /* 0x30 */ s16 unk30[4];
} ControllerState;

typedef struct {
    /* 0x00 */ s8  hasRumblePak[4]; // or isInitialised ?
    /* 0x04 */ ControllerState state;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u8  pad3E[0x2A];
} Controller; // size 0x68;

typedef struct struct017 struct017;

struct struct017 {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 sndID;
    /* 0x04 */ u8  pad4[0x8];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ u16 counter;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8  pad12[0xC];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u16 unk20;
    /* 0x22 */ s16 sndSlot;
    /* 0x24 */ u8  sndState;
    /* 0x25 */ u8  pad25[0x3];
    /* 0x28 */ s32 unk28; // ptr?
    /* 0x2C */ struct017 *prev; // maybe
    /* 0x30 */ struct017 *next;
}; // size 0x34


typedef struct {
    /* 0x00000 */ u8  pad0[0x7D00];
    /* 0x7D00 */  Gfx *unk7D00;
    /* 0x7D04 */  u8  pad7D04[0x18fc];
    /* 0x9600 */  Gfx *unk9600;
    /* 0x9604 */  u8  pad9604[0x257c];
    /* 0xBB80 */  Gfx *unkBB80;
    /* 0xBB84 */  u8  padBB84[0x1f3c];
    /* 0xDAC0 */  Gfx *unkDAC0;
    /* 0xDAC4 */  u8  padDAC4[0x2edc];
    /* 0x109A0 */ Gfx unk109A0[8][1400];
    /* 0x267A0 */ s32 unk267A0;
    /* 0x267A4 */ u8  pad267A4[0x241C];
    /* 0x28BC0 */ s16 unk28BC0;
    /* 0x28BC2 */ s16 unk28BC2;
    /* 0x28BC4 */ u8  pad28BC4[0x4];
    /* 0x28BC8 */ s16 unk28BC8;
    /* 0x28BCA */ s16 unk28BCA;
    /* 0x28BCC */ u8  unk28BCC;
    /* 0x28BCD */ u8  unk28BCD;
    /* 0x28BCE */ u8  unk28BCE;
    /* 0x28BCF */ u8  unk28BCF;
    /* 0x28BD0 */ u8  pad28BD0[0x9CA0];
    /* 0x32870 */ uSprite sprites[140]; // maybe more/less
    /* 0x33590 */ Mtx modelViewMtx[250]; // (might only be 240?)
    /* 0x37410 */ Mtx unk37410;  // projection matrix 1
    /* 0x37450 */ Mtx unk37450;  // projection matrix 2
    /* 0x37490 */ Mtx unk37490;  // projection matrix 3
    /* 0x374D0 */ Mtx unk374D0;  // modelview matrix 1
    /* 0x37510 */ Mtx unk37510;
    /* 0x37550 */ Mtx unk37550;
    /* 0x37590 */ Mtx unk37590;
    /* 0x375D0 */ Mtx unk375D0;
    /* 0x37610 */ Mtx unk37610;
    /* 0x37650 */ Hilite hilites[100]; // 0x10 each
    /* 0x37C90 */ LookAt lookAts[100]; // 0x20 each
    /* 0x38910 */ s32 usedHilites;
    /* 0x38914 */ s32 usedSprites;
    /* 0x38918 */ s32 usedModelViewMtxs;
    /* 0x3891C */ s32 unk3891C;
    /* 0x38920 */ u8  pad38920[0xF0];
    /* 0x38A10 */ f32 unk38A10[3][4];
    /* 0x38A40 */ f32 unk38A40[4];
    /* 0x38A50 */ u8  pad38A50[0x8C0];
    /* 0x39310 */ s16 unk39310; // used xxx ?
    /* 0x39312 */ u8  pad39312[0x1ff6];
    /* 0x3B308 */ u16 unk3B308;
    /* 0x3B30A */ u8  pad3B30A[0x32e];
    /* 0x3B638 */ Ambient unk3B638; // either this or a pointer to a Light struct
    /* 0x3B640 */ Light unk3B640;
    /* 0x3B650 */ s8  unk3B650;
    /* 0x3B651 */ s8  unk3B651;
    /* 0x3B652 */ s8  unk3B652;
    /* 0x3B653 */ u8  pad3B653;
    /* 0x3B654 */ s8  unk3B654;
    /* 0x3B655 */ s8  unk3B655;
    /* 0x3B656 */ s8  unk3B656;
    /* 0x3B657 */ u8  pad3B657;
    /* 0x3B658 */ s8  unk3B658;
    /* 0x3B659 */ s8  unk3B659;
    /* 0x3B65A */ s8  unk3B65A;
    /* 0x3B65B */ u8  pad3B65B[0x55];
    /* 0x3B6B0 */ Ambient unk3B6B0;
    /* 0x3B6B8 */ Light unk3B6B8;
    // /* 0x3B6C0 */ Ambient unk3B6C0;

} DisplayList;

typedef struct {
  /* 0x00 */ s32 unk0;
  /* 0x04 */ u8  pad4[0x4];
  /* 0x08 */ u8 *unk8;
  /* 0xC; */ s32 unkC;
  /* 0x10 */ s32 unk10;
  /* 0x14 */ s32 unk14;
  /* 0x18 */ s32 unk18;
  /* 0x1C */ s32 unk1C;
  /* 0x20 */ u8 *unk20; // pointer to ucode
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
    /* 0x004E0 */ Gfx unk4E0[4000];
    /* 0x081E0 */ Gfx unk81E0[800];
    /* 0x09AE0 */ Gfx unk9AE0[1200];
    /* 0x0C060 */ Gfx unkC060[1000];
    /* 0x0DFA0 */ Gfx unkDFA0[12700];
    /* 0x26C80 */ Gfx unk26C80[10725];
    /* 0x3BBA8 */ u16 unk3BBA8;
    /* 0x3BBAA */ u8  pad3BBAA[0x1E];
    /* 0x3BBC8 */ u16 unk3BBC8;
    /* 0x3BBCA */ u8  pad3BBCA[0x1E];
    /* 0x3BBE8 */ u8 *unk3BBE8; // pointer to framebuffer
    /* 0x3BBEC */ u8  pad3BBEC[0x4];
} struct018; // size 0x3BBF0

typedef struct {
    /* 0x00 */ s32 checksum;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8  musicVol;
    /* 0x0D */ s8  sfxVol;
    /* 0x0E */ s8  language;  // chosen language, e.g. LANG_ENGLISH
    /* 0x0F */ u8  padF[0x17];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8  pad28[0x18];
} Eeprom; // size 0x40 - Game settings?

typedef struct {
    u8 powercells : 4;  // used as 'time' for boss levels
    u8 pad : 2;
    u8 completed : 1;   // level complete
    u8 trophy : 1;      // got trophy
} Progress;

typedef struct {
    /* 0x00 */ s32 checksum;
    /* 0x04 */ Progress level[32];
    /* 0x24 */ u8  pad24[0x4];
    /* 0x28 */ u8  speciesSeen[0x8];
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u8  pad38[0x3];
    /* 0x3B */ s8  evoPartsCollected;
    /* 0x3C */ s32 score;
} PlayerEeprom; // size 0x40 (64 bytes)

typedef struct {
    void *vAddr; // vAddr
    s16 outLen; // outLen
    u8  pad6[0x2];
    s32 unk8;
    u8  unkC[0x4];
    s32 unk10;
    u8  unk14[0x4];
    s32 unk18;
    s32 unk1C;
    u8 *unk20;
    s32 unk24;
    u8 *unk28;
    u8  pad2C[0x4];
    u8 *unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    Acmd *unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    OSMesgQueue *unk58;
    s32 unk5C;
    u8  unk60[0x10];
    s32 unk70;
} struct019; // audio


typedef struct {
    s32 vAddr;
    s16 nbytes;
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
    /* 0x0 */ u8 *unk0;
    /* 0x4 */ u8 *fontAddress;
    /* 0x8 */ u8  width;
    /* 0x9 */ u8  height;
    /* 0xA */ u8  bits;
    /* 0xC */ u16 glyphBytes;
} struct023;

typedef struct {
    s32 start;
    s32 end;
} struct024; // only RNC?

typedef struct {
    /* 0x00 */ s16 unk0; // camera mode?
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8  pad4[0x2];
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ u8  pad14[0xC];
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8  pad28[0x26];
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ u8  pad50[0x4];
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ u8  pad62[0x2];
    /* 0x64 */ s8  unk64;
    /* 0x65 */ s8  unk65;
    /* 0x66 */ s8  unk66;
    /* 0x67 */ u8  unk67;
    /* 0x68 */ u8  pad68[0x4];
    /* 0x6C */ u8 *unk6C;
    /* 0x70 */ u8  pad70[0x4];
    /* 0x74 */ f32 unk74;
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ u8  unk80[0xC];
    /* 0x8C */ f32 unk8C;
    /* 0x90 */ f32 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 unk98;
    /* 0x9C */ f32 unk9C;
    /* 0xA0 */ f32 unkA0;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ u8  padAC[0xA];
    /* 0xB6 */ s8  unkB6;
    /* 0xB7 */ u8  padB7[0x11];
    /* 0xC8 */ u8  unkC8;
    /* 0xC9 */ u8  unkC9;
    /* 0xCA */ s16 unkCA;
    /* 0xCC */ s32 unkCC;
    /* 0xD0 */ s16 unkD0;
    /* 0xD2 */ s16 unkD2;
    /* 0xD4 */ s16 unkD4;
    /* 0xD6 */ s8  unkD6;
    /* 0xD7 */ u8  padD7[0x5];
} struct025; // size 0xDC

typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    u8  padA[0x4];
    u16 unkE;
    u8  pad10[0x4];
    s16 unk14;  // selected option?
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8  unk26;
    u8  unk27;
    u8  pad28;
    u8  unk29;
    u8  unk2A;
    u8  unk2B;
    u8  unk2C;
    u8  unk2D;
    u8  unk2E;
    u8  unk2F;
    u8  unk30;
    u8  unk31; // exit zone
    u8  unk32; // exit zone
    u8  unk33; // leave sv
    u8  unk34; // leave sv
    u8  unk35; // replay zone, cancel/confirm not active
    u8  unk36; // replay zone, 0 cancel active, 1 confirm active
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
  /* 0x00 */  u16 unk0; // animal type?
  /* 0x02 */  s16 unk2;
              u8  pad4[0x11];
              u8  unk15; // checked if 4?
              u8  pad16[0x2];
              s32 unk18;
              u8  pad1C[0x56];
              s16 unk72;
              s16 unk74;
              s16 unk76;
              s16 unk78;
              s16 unk7A;
  /* 0x7C */  u16 mass;
              s16 unk7E;
  /* 0x80 */  struct {
                s32 pad  : 17;
                u8  bit2 : 1;
                u8  bit  : 1;
              } unk80;
  /* 0x84 */  void (*unk84)(void *);
              u8  pad88[0x2];
              u8  unk8A;
  /* 0x8B */  u8  armour;
  /* 0x8C */  u8  unk8C;
  /* 0x8D */  u8  unk8D;
  /* 0x8E */  u8  pad8E[0xE];
  /* 0x9C */  u16 unk9C; // ANIMAL_TYPE
  /* 0x9E */  u16 unk9E;
              u16 unkA0; // bitfield? 0xC00 0x800 0x400
              u16 unkA2;
              u16 unkA4; // scaling?
              u16 unkA6;
              u16 unkA8;
              u16 unkAA; // scaling?
              u16 unkAC; // scaling?
              s16 fallDistance; // fall distance
              s16 unkB0;
              u16 traction; // traction
              s16 unkB4;
              s16 unkB6;
              u16 unkB8;
              u16 unkBA;
              s16 unkBC;
              u16 unkBE;
              s16 unkC0;
              s16 unkC2; // scaling?
              s16 unkC4; // scaling?
              s16 unkC6;
              s16 unkC8; // scaling?
  /* 0xCA */  s16 unkCA;
  /* 0xCC */  s16 unkCC;
  /* 0xCE */  s16 unkCE;
  /* 0xD0 */  s16 unkD0; // scaling?
  /* 0xD2 */  s16 unkD2; // scaling?
  /* 0xD4 */  s16 unkD4;
  /* 0xD6 */  s16 biome;
  /* 0xD8 */  u8  unkD8;
  /* 0xD9 */  u8  padD9;
  /* 0xDA */  s16 unkDA[3]; // skill A (drainRate;unknown;unknown)
  /* 0xE0 */  s16 unkE0[3]; // skill B (drainRate;unknown;unknown)
  /* 0xE6 */  s8  unkE6; // animal class / value?
  /* 0xE7 */  u8  unkE7;
  /* 0xE8 */  u8  unkE8;
  /* 0xE8 */  u8  unkE9;
  /* 0xE8 */  u8  unkEA;
  /* 0xEB */  s8  unkEB;
}; // size 0xEC

typedef struct {
    /* 0x0000 */ u8  pad0[0x3EB0];
    /* 0x3EB0 */ struct035 *unk3EB0;
    /* 0x3EB4 */ Animal *animal;
} struct036;

typedef struct {
    struct035* unk0;
    s32 unk4;
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
    /* 0x0 */ s16 min;
    /* 0x2 */ s16 max;
    /* 0x4 */ u8  r;
    /* 0x5 */ u8  g;
    /* 0x6 */ u8  b;
    /* 0x7 */ u8  padding;
} Fog; // size 0x8

typedef struct {
    s16 min;
    s16 max;
    s32 position;
} Fog2;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} struct004; // sizze 0x18

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 debugMode;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 europe;
    /* 0xC */ s16 ice;
    /* 0xE */ s16 jungle;
    /* 0x10 */ s16 desert;
    /* 0x12 */ s16 final;
    /* 0x14 */ s16 hidden;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
} struct005; // size 0x1A

typedef struct {
    /* 0x0 */ f32 unk0;     // x offset
    /* 0x4 */ f32 unk4;     // y offset
    /* 0x8 */ f32 unk8;     // scale?
    /* 0xC */ f32 unkC;     // europe ring section X
    /* 0x10 */ f32 unk10;   // europe ring section Y
    /* 0x14 */ f32 unk14;   // desert ring section X
    /* 0x18 */ f32 unk18;   // desert ring section Y
    /* 0x1C */ f32 unk1C;   // jungle ring section X
    /* 0x20 */ f32 unk20;   // jungle ring section Y
    /* 0x24 */ f32 unk24;   // ice ring section X
    /* 0x28 */ f32 unk28;   // ice ring section Y
    /* 0x2C */ s8  biome;   // currently selected biome
    /* 0x2D */ s8  currentLevel; // currently selected level
    /* 0x2E */ s8  bank;    // current save bank
    /* 0x2F */ s8  unk2F;
    /* 0x30 */ s8  unk30;
    /* 0x31 */ s8  unk31;
    /* 0x32 */ s8  lastLevel; // previously selected level
} struct030;

typedef struct {
    /* 0x0 */ f32 unk0;
    /* 0x4 */ f32 unk4;
    /* 0x8 */ f32 unk8;
    /* 0xC */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s16 unk20;
} struct008;

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
    s32 unk0;
    s32 unk4;
    s32 unk8;
} struct043;

struct struct044 {
    struct044 *unk0;
    s32 unk4;
    s32 unk8;
};

typedef struct {
    u8 *romStart;   // e.g. 007d1ad0
    u8 *romEnd;     // e.g. 007d2f50
    u8 *ramStart;   // e.g. 803fdec0
    u8 *ramEnd;     // e.g. 803ff340
    u8 *ramStart2;  // e.g. 803fdec0
} struct046; // size 0x14

typedef struct {
    u8  pad0[0x48];
    f32 unk48;
    f32 unk4C;
} struct047;

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

struct struct049 {
    u8  pad0[0x4];
    s16 unk4;
    u8  pad6[0x2];
    s16 unk8;
};


typedef struct {
    /* 0x0000 */ struct035 unk0[68]; // each 0xEC so 0x3EB0 total
    /* 0x3EB0 */ struct035 *unk3EB0;    // what is this D_801DDD88
    /* 0x3EB4 */ struct015 animal[68];  // D_801DDD8C
    /* 0x40D4 */ u8        pad3FC4[0x3f07];
    /* 0x7FDB */ u8        unk7FDB;
    /* 0x7FDC */ u8        pad7FDC[0x7fcc];
    /* 0xFFA8 */ s16       unkFFA8;
    /* 0xFFAA */ u8        padFFAA[0x8];
    /* 0xFFB2 */ u16       unkFFB2;
    /* 0xFFB4 */ u16       unkFFB4;
    /* 0xFFB6 */ u16       unkFFB6;
    /* 0xFFB8 */ u16       unkFFB8;
    /* 0xFFBA */ u16       unkFFBA;
    /* 0xFFBC */ u16       unkFFBC;
    /* 0xFFBE */ u16       unkFFBE;
    /* 0xFFC0 */ u16       unkFFC0;
    /* 0xFFC2 */ u16       unkFFC2;
    /* 0xFFC4 */ u16       unkFFC4;
    /* 0xFFC6 */ u16       unkFFC6;
    /* 0xFFC8 */ u16       unkFFC8;
    /* 0xFFCA */ u8        padFFCA[0x4];
    /* 0xFFCE */ u16       unkFFCE;
    /* 0xFFD0 */ u8        padFFD0[0x6];
    /* 0xFFD6 */ u16       unkFFD6;
    /* 0xFFD8 */ u8        padFFD8[0x2];
    /* 0xFFDA */ s16       unkFFDA;
} struct050;

typedef struct {
    /* 0x0 */  s32 unk0;
    /* 0x4 */  s32 unk4;
    /* 0x8 */  s16 unk8;
    /* 0xA */  s16 unkA;
    /* 0xC */  s16 unkC;
    /* 0xE */  s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ u8  pad1E[2];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s8  unk2E;
    /* 0x2F */ s8  unk2F;
    /* 0x30 */ u8  pad30[0x2];
    /* 0x32 */ s8  unk32;
    /* 0x33 */ s8  unk33;
    /* 0x34 */ s8  unk34;
    /* 0x35 */ u8  pad35[0x3];
} struct051; // size 0x38

// might just be an s16 array but this is a little nicer
typedef struct {
    s16 x;
    s16 y;
    s16 brightness;
    s16 speed;
} Star; // size 0x8

typedef struct {
    u8  pad0[0x4];
    u8  unk4[0xC];
    u8  pad10[0x12];
    u8  unk22;
} struct052;

typedef struct {
    s8  unk0[8][64];
    s16 unk200; // lod?
    u16 unk202;
    u16 unk204;
    u16 unk206;
    s16 unk208;
    s16 unk20A;
    u8  unk20C;
    u8  pad20D[0x2];
    u8  unk20F;
} struct053;

typedef struct {
    s16 unk0;
    s16 unk2;
    u8  pad4[0x42];
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    Animal *unk58;
    Animal *unk5C;
    Animal *unk60;
    s16 unk64;
} struct054;

struct struct055 {
    /* 0x000 */ Animal *unk0;
    /* 0x004 */ s32 xPos;
    /* 0x008 */ s32 zPos;
    /* 0x00C */ s32 yPos;
    /* 0x010 */ u8  pad10[0x150];
    /* 0x160 */ u8  unk160;
}; // is this just Animal?

typedef struct {
    /* 0x00000 */ u8  pad0[0x1ACC0];
    /* 0x1ACC0 */ u8  unk1ACC0[0x2800];
    /* 0x1D4C0 */ u8  unk1D4C0[0x2800];
} struct056;

typedef struct {
    s16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    u8 unk18;
} struct057;

typedef struct {
    u8  pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8  unk10[0x1C];
    s16 unk2C;
    s16 unk2E;
    u8  unk30[0x10];
    u16 unk40;
    u16 unk42;
    u8  unk44[0x20];
    u8  unk64;
} struct058;

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2[64]; // 48?
} struct059;

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vertex;

typedef struct {
     s32 unk0;
     s32 unk4;
     s32 unk8;
     s16 unkC;
     s16 unkE;
} struct060;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} struct061; // size 0x8

typedef struct {
    struct071 *unk0;
    u8  pad4[0x4];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s8  unk14;
    s8  unk15;
    s8  unk16;
    s8  unk17;
    s8  unk18;
    s8  unk19;
    s8  unk1A;
    s8  unk1B;
    u8  pad1C[0x4];
} struct062; // size 0x20

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} struct063; // size 0x8

typedef struct {
    s8 unk0;
    u8 pad1[0xB];
} struct064; // size 0xC

struct struct065 {
    struct065 *unk0;
    s32 unk4;
    Animal *unk8;
}; // size 0xC

typedef struct {
    u8 *start;
    u8 *end;
} struct066;

typedef struct {
    u8 pad0[0x100C];
} struct067;

typedef struct {
    /* 0x00 */ u16 id;
    /* 0x02 */ u16 type;            // flags OR'd together
    /* 0x04 */ u8* displayList1;
    /* 0x08 */ u8* displayList2;
    /* 0x0C */ u8* displayList3;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8  unk14;
    /* 0x15 */ u8  unk15;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ struct067* unk18;
    /* 0x1C */ u16 unk1C;
    /* 0x18 */ u8 pad1E[0x7E];
} struct068; // size 0x9C

typedef struct {
    u8  unk0;
    u8  unk1;
    u8  unk2;
    u8  unk3;
    u32 unk4;
} struct071_inner;

struct struct071 {
    /* 0x0 */   u16 unk0;
    /* 0x2 */   u8  pad2[0x2];
    /* 0x4 */   union {
                    s16 h;
                    s32 w;
                } unk4;
    /* 0x8 */   union {
                    s16 h;
                    s32 w;
                } unk8;
    /* 0xC */   union {
                    s16 h;
                    s32 w;
                } unkC;
    /* 0x10 */  u8  pad10[0x5];
    /* 0x15 */  u8  unk15;
    /* 0x16 */  u8  pad16[2];
    /* 0x18 */  s32 unk18;  // xVelocity
    /* 0x1C */  union {
                    s16 h[2];
                    s32 w;
                }  unk1C;  // zVelocity
    /* 0x20 */  union {
                    s16 h[2];
                    s32 w;
                } unk20;    // yVelocity
    /* 0x24 */  s32 unk24;
    /* 0x28 */  u8  pad28[0x4];
    /* 0x2C */  s16 unk2C;
    /* 0x2E */  s16 unk2E;
    /* 0x30 */  u8  pad30[0x10];
    /* 0x40 */  u16 unk40;
    /* 0x42 */  u16 unk42;
    /* 0x44 */  u8  pad44[0x7];
    /* 0x4B */  u8  unk4B;
    /* 0x4C */  struct {
                    s32  unk0  : 0x1C;
                    s32  unk1C : 1;
                    s32  unk1D : 1;
                } unk4C;
    /* 0x50 */  u8  pad50[0x4];
    /* 0x54 */  struct071_inner unk54;
    /* 0x5C */  struct071_inner unk5C;
    /* 0x64 */  u8  unk64;
    /* 0x65 */  u8  pad65[0x3];
    /* 0x68 */  Animal *unk68; // or struct071?
    /* 0x6C */  Animal *unk6C; // or struct071?
    /* 0x70 */  Animal *unk70; // or struct071?
    /* 0x74 */  u8  pad74[0xda];
    /* 0x14E */ s16 unk14E;
    /* 0x150 */ s16 unk150;
    /* 0x152 */ s16 unk152;
    /* 0x154 */ u8  unk154;
    /* 0x155 */ u8  pad155[0x3];
    /* 0x158 */ s32 unk158;
    /* 0x15C */ s8  unk15C;
    /* 0x15D */ u8  pad15D;
    /* 0x15E */ s16 unk15E;
    /* 0x160 */ u8  unk160;
    /* 0x161 */ u8  unk161;
    /* 0x162 */ u8  unk162;
    /* 0x163 */ u8  unk163;
    /* 0x164 */ u8  unk164;
    /* 0x165 */ u8  unk165[0x3];
    /* 0x168 */ Animal *unk168;
    /* 0x16C */ u8  pad16C[0x4];
    /* 0x170 */ struct068 *unk170;
    /* 0x174 */ u8  pad174[0x4];
    /* 0x178 */ s16 unk178;
    /* 0x17A */ s16 unk17A;
    /* 0x17C */ s16 unk17C;
    /* 0x17E */ s16 unk17E;
    /* 0x180 */ s16 unk180;
    /* 0x182 */ s16 unk182;
    /* 0x184 */ s16 unk184;
    /* 0x186 */ u8  pad186[0x26];
    /* 0x1AC */ s32 unk1AC;
    /* 0x1B0 */ u8  pad1B0[0x50];
    /* 0x200 */ s32 unk200;
    /* 0x204 */ s32 unk204;
    /* 0x208 */ s32 unk208;
    /* 0x201 */ u8  pad20C[0x40];
    /* 0x26C */ s32 unk24C[8]; // tbd how many
    /* 0x26C */ u8  unk26C;
    /* 0x26D */ u8  pad26D[0x3]; // just alignment?
}; // game object, size 0x270

typedef struct {
    /* 0x0 */    u8 pad[0xA110];
    /* 0xA110 */ s16 unkA110;
    /* 0xA112 */ s16 unkA112;
    /* 0xA114 */ s16 unkA114;
} struct072;

typedef struct {
    s8 unk0;
    s8 unk1;
    s16 unk2;
    s32 unk4;   // 10.2 format
    s32 unk8;   // 10.2 format
    s32 unkC;
    s32 unk10;
    s32 unk14;  // displaylist?
} struct073; // size 0x18

typedef struct {
    u8  unk0;
    u8  unk1;
    u8  unk2;
    u8  pad3;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
} struct074; // size 0x14

typedef struct {
    u8 pad0[0x7];
    s8 unk7;
} struct075; // size 0x8

typedef struct {
    s16 unk0;
    s16 unk2;
} struct076; // size 0x4

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} struct077; // size 0x6

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ u8  pad6[0x6];
    /* 0xC */ s8  unkC;
    /* 0xD */ s8  unkD;
    /* 0xE */ s8  unkE;
    /* 0xF */ u8  padF;
} struct078; // size 0x10

typedef struct {
    u8  pad0[0x54];
    s32 unk54;
    Animal *unk58; // Animal? or Object?
    s32 unk5C;
    Animal *unk60;
    u8  unk64;
} struct079; // TODO: likely merge with an existing struct

typedef struct {
    u8  pad0[0x7FA8];
    s16 unk7FA8;
    u8  pad7FAA[0x9];
    u16 unk7FB3;
    u8  pad7FB5[0x4];
    u16 unk7FB9;
    u8  pad7FBB[0x12];
    u16 unk7FC7;
    u16 unk7FC9;
    u8  pad7FCB[0xF];
    s16 unk7FDA;
    s16 unkFFA8;
    s16 unkFFDA;
} struct080; // nonsense
// 0x8000 big?

typedef struct {
    s32 unk0;
    s32 unk4;
} struct081;

typedef struct {
    s8 unk0;
    s8 unk1;
} struct082;

typedef struct {
    s32 unk0;
    ALBank *unk4;
} struct083;

struct struct101 {
    u8  unk0;
    u8  pad1[0x3];
    s32 unk4;
    s32 *unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s16 unk20;
    u8  unk22;
    u8  pad23; //
    s32 unk24;
    s32 unk28;
    u8  unk2C;
    u8  unk2D;
    s8  unk2E;
    u8  pad2F;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s8  unk38;
    u8  pad39[0x3];
    s32 unk3C;
}; // size 0x40

typedef struct {
    /* 0x00 */   struct101 unk0[255];
    /* 0x3FC0 */ u8  pad3FC0[8];
    /* 0x3FC8 */ s8  unk3FC8[8]; // is displaylist enabled?
    /* 0x3FD0 */ u16 unk3FD0;
    /* 0x3FD2 */ s16 unk3FD2;
    /* 0x3FD4 */ s16 unk3FD4;
    /* 0x3FD6 */ s16 unk3FD6;
} struct084; // size 0x3FD8

typedef struct {
    u8  unk0;
    s8  unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u8  pad12[0x2];
    s32 unk14;
} struct085; // size 0x18

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} struct086; // size 0x8

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} struct088; // size 0x18

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8  unkA;
    u8  unkB;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2D;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4F;
    s16 unk50;
    u8  unk51;
} struct089; // size 0x52

// level data

// case 0: // object
typedef struct {
    /* 0x0 */ s16 id;
    /* 0x2 */ s16 x;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 y;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 angle;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 scale;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
} struct090; // size 0x16

// case 1:
typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 unkE;
} struct091; // size 0x10

// case 2:
typedef struct {
    s16 unk0;
    s16 unk2;
    u8  pad4;
    u8  unk5;
} struct092;

// case 7:
typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8  unk18;
    /* 0x19 */ u8 unk19;
} struct097; // size 0x1A

typedef struct {
    f32 unk0;
    s16 id;
} struct098; // size 0x8

typedef struct {
    u16 unk0; // particle type?
    u8  unk2;
    u8  pad3;
    s16 unk4;
    u8  pad6[0x8];
    u16 unkE;
    u16 unk10;
    u8  unk12[0x6];
} struct099; // particle, size 0x18?

typedef struct {
    s32 unk0;
    s32 unk4;
} struct100;

typedef struct {
    s16 unk0;
    s8  unk2;
    s8  unk3;
} struct102;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 transitionId;
    s16 unk6;
    s16 overlayTV;
} ScreenTransition;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} struct104;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} struct105;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
} struct107; // size 0xE

typedef struct {
    s16* unk0;
    s16* unk4;
    s16* unk8;
    s16* unkC;
    s16* unk10;
    s16* unk14;
    s16* unk18;
    s16* unk1C;
    s16* unk20;
    s16* unk24;
    s16* unk28;
    s16* unk2C;
    s16* unk30;
    s16* unk34;
    s16* unk38;
    s16* unk3C;
    s16* unk40;
} struct108;

typedef struct {
    /* 0x0  */ s16* unk0[13];   // description?
    /* 0x34 */ s16* unk34[13];  // value?
    /* 0x68 */ s16  unk68[13];  // offsets?
    /* 0x82 */ s16  unk82;
    /* 0x84 */ s16  unk84;
    /* 0x86 */ s16  unk86;
} struct109; // size 0x88

typedef struct {
    u8  pad0[0x2];
    s16 unk2;   // sfx id
    s32 unk4;   // freq?
    f32 unk8;   // duration?
} struct111; // size 0xC

typedef struct {
    u8    pad0[0x4];
    void* unk4;
} struct110;

typedef struct {
    s16 unk0; // type?
    u8  unk2; // particle id?
    u8  unk3;
    u8  unk4;
    u8  unk5;
    s16 unk6;
    s16 unk8;
} struct112;

typedef struct {
    u8 x;
    u8 z;
    u8 y;
} Waypoint;

typedef struct {
    u8 length;
    Waypoint waypoint[1];
} WaypointData;

#endif
