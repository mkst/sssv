#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct struct017 struct017;
typedef struct struct025 struct025;
typedef struct struct035 struct035;
typedef struct struct072 struct072;
typedef struct CollisionNode CollisionNode;
typedef struct Entity Entity;
typedef struct Animal Animal;


typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f;

typedef union {
    s16 h;
    s32 w;
} Pos;

typedef struct {
  /* 0x0 */   Pos xPos;
  /* 0x4 */   Pos zPos;
  /* 0x8 */   Pos yPos;
} Position; // size 0xC

typedef struct {
    union {
        struct {
            s32 unk0;
            s32 unk4;
        } w;
        struct {
            u16 unk0;
            u16 unk2;
            u16 unk4;
            u16 unk6;
        } h;
    }; // unnamed
} FracIntHelper;

typedef struct {
  s16 unk0; // tbd
  s16 unk2; // tbd
  s16 unk4; // tbd
  s16 unk6; // tbd
  s32 data[32*32];
  s32 unk1008; // tbd
} Collision; // size 0x100C

typedef struct {
    /* 0x0  */ u16 unk0;
    /* 0x2  */ u16 unk2;
    /* 0x4  */ u16 unk4;
    /* 0x6  */ u16 unk6;
    /* 0x8  */ u16 unk8;
    /* 0xA  */ u16 unkA;
    /* 0xC  */ s16 unkC;   // used for perspective?
    /* 0xE  */ s16 unkE;   // used for perspective?
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;  // xy start/end for level collision
    /* 0x14 */ u16 unk14;  // xy start/end for level collision
    /* 0x16 */ u16 unk16;  // xy start/end for level collision
    /* 0x18 */ u16 unk18;  // xy start/end for level collision
    /* 0x1A */ u16 animalId; // starting animal id
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
    /* 0x20 */ s16 segment; // not quite equal to biome
    /* 0x22 */ s16 unk22;  // water amplitude, only HOT_CROSS_BUNS, SMASHING_START, SNOW_JOKE & THE_ENGINE_ROOM. use 0, otherwise 1
    /* 0x24 */ u8  pad24[0x1C];
    /* 0x40 */ s16 unk40;   // sourceFovY ?
    /* 0x42 */ s16 unk42;
    /* 0x44 */ u8  pad44[0x8];
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;  // texture bank? level id?
    /* 0x54 */ u8  unk54;
    /* 0x55 */ u8  unk55;
    /* 0x56 */ u8  unk56;
    /* 0x57 */ u8  unk57;  // water primary alpha
    /* 0x58 */ u8  unk58;
    /* 0x59 */ u8  unk59;
    /* 0x5A */ u8  unk5A;
    /* 0x5B */ u8  unk5B;  // water env alpha
    /* 0x5C */ u8  unk5C[4][6];
    /* 0x74 */ u8  pad74;
    /* 0x75 */ u8  unk75;
    /* 0x76 */ s8  unk76; // r
    /* 0x77 */ s8  unk77; // g
    /* 0x78 */ s8  unk78; // b
    /* 0x79 */ u8  pad79[0x27];

    // NOTE: level .dat ends at 0xA0

    /* 0xA0 */ u8  padA0[0x1C];

    /* 0xBC */ Entity *entranceTeleporter;
    /* 0xC0 */ Entity *exitTeleporter;
    /* 0xC4 */ u16 unkC4;
    /* 0xC6 */ s16 unkC6;
    /* 0xC8 */ u8  unkC8[0x6];
    /* 0xCE */ s16 evoSuitColor;
    /* 0xD0 */ u8  padD0[0xA];
    /* 0xDA */ s16 unkDA;  // scissor? width?
    /* 0xDC */ u16 unkDC;  // initialised?
    /* 0xE0 */ f32 fovY;  // used for perspective (copied from unk40)
    /* 0xE4 */ u16 titleText[42];
} LevelConfig;

typedef struct {
    /* 0x0 */ s32 score;
    /* 0x4 */ s16 unk4;         // if 0 can increase health? paused?
    /* 0x6 */ s16 powercells2;  // also incremented when a powercell is collected
    /* 0x8 */ s16 level;        // level index
    /* 0xA */ u16 unkA;         // only ever set to 3
    /* 0xC */ s16 powercells;   // number of powercells collected
    /* 0xE */ char scoreText[18];
} GameState; // size 0x20

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 data[7000];
} LevelText; // only used to force alignment

struct CollisionNode {
    /* 0x0 */ CollisionNode *next;
    /* 0x4 */ CollisionNode *prev;
    /* 0x8 */ Animal *animal;
}; // size 0xC

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} CmdRegular;

typedef struct {
    /* 0x0 */ union {
                u8 ub[2];
                s16 h;
              } unk0;
    /* 0x4 */ s16 unk2;
    /* 0x6 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} CmdUnknown;

typedef struct {
    /* 0x0 */ u8 unk0;  // lbu a0,4(s0)
    /* 0x1 */ u8 unk1;  // lbu a1,5(s0)
    /* 0x2 */ u8 unk2;  // lbu a2,6(s0)
    /* 0x3 */ u8 unk3;  // lbu a3,7(s0)
    /* 0x4 */ u8 unk4;  // 8
    /* 0x5 */ u8 unk5;  // 9
    /* 0x6 */ u8 unk6;  // A
    /* 0x7 */ u8 unk7;  // B
} CmdDummy;

typedef struct {
    /* 0x0 */ s16 unk0;
} CmdSimple;

typedef struct {
    /* 0x0 */ u8  unk0;  // lbu a0,4(s0)
    /* 0x1 */ u8  unk1;  // lbu a1,5(s0)
    /* 0x2 */ u8  unk2;  // lbu a2,6(s0)
    /* 0x3 */ u8  unk3;  // lbu a3,7(s0)
    /* 0x4 */ u8  unk4;  // 8
    /* 0x5 */ u8  unk5;  // 9
    /* 0x6 */ s16 unk6;  // A
} CmdUnknown2;

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1[0x5];
    /* 0x6 */ s16 unk6;
} CmdType1;

typedef struct {
    /* 0x0 */ u8 xStart;
    /* 0x1 */ u8 yStart;
    /* 0x2 */ u8 xEnd;
    /* 0x3 */ u8 yEnd;
    /* 0x4 */ s16 action;
} CmdType12; // CmdSetFloorLevel

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x0 */ u16 unk2;
    /* 0x0 */ s16 unk4;
} CmdType13;

typedef struct {
    /* 0x0 */ u16 unk0;
} CmdType14;

typedef struct {
    /* 0x0 */ u8 id;
    /* 0x1 */ s8 unk1;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ s8 unk3;
    /* 0x4 */ s8 unk4;
    /* 0x5 */ s8 unk5;
    /* 0x6 */ u8 unk6;
    // /* 0x7 */ s8 unk7;
} CmdType16;

typedef struct {
    /* 0x0 */ u8 id;
    /* 0x2 */ s16 x;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 y;
} CmdType17;

typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
} CmdType20;

typedef struct {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ s8 unk1;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} CmdType21;

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} CmdType22;

typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8  unk2;
    /* 0x3 */ s8  unk3;
    /* 0x4 */ u8  unk4;
    /* 0x5 */ u8  unk5;
    /* 0x6 */ u16 unk6;
} CmdType23;

typedef struct {
    /* 0x0 */ u16 F; // Flags
    /* 0x2 */ u8  State; // Particle ID
    /* 0x3 */ s8  Fq; // Frequency
    /* 0x4 */ u8  S; // Size
    /* 0x5 */ u8  unk5;
    /* 0x6 */ u16 Time;
} CmdType24;

typedef struct {
    /* 0x0 */ u16 unk0;  // lbu a0,4(s0)
    /* 0x2 */ u16 unk2;  // lbu a2,6(s0)
    /* 0x4 */ u8  unk4;  // 8
    /* 0x5 */ u8  unk5;  // 9
    /* 0x6 */ u8  unk6;  // A
    /* 0x7 */ u8  unk7;  // B
} CmdType29;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ u8  unk6;
    /* 0x7 */ s8  unk7;
} CmdType30;

typedef struct {
    /* 0x0 */ u16 unk0;
} CmdType35;

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u16 unk6;
} CmdType37;

typedef struct {
    /* 0x0 */ s16 id;
    /* 0x2 */ s16 volume;
    /* 0x0 */ u16 pitch;
    /* 0x6 */ u8  atLocation;
} CmdType38; // CmdPlaySfx

typedef struct {
    /* 0x0 */ u8 id;
} CmdType39; // CmdSetMusicTrack

typedef struct {
    /* 0x0 */ u16 unk0;
} CmdType41; // sets D_803F2D50.unk1E / D_803F2D50.unk1C

typedef struct {
    /* 0x0 */ u8  unk0;
    /* 0x1 */ u8  unk1;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} CmdType50;

typedef struct {
    /* 0x0 */ u16  unk0;
} CmdType51;

typedef struct {
    /* 0x0 */ u8 unk0;  // lbu a0,4(s0)
    /* 0x1 */ u8 unk1;  // lbu a1,5(s0)
    /* 0x2 */ u8 unk2;  // lbu a2,6(s0)
    /* 0x3 */ u8 unk3;  // lbu a3,7(s0)
    /* 0x4 */ u8 unk4;  // 8
    /* 0x5 */ u8 unk5;  // 9
    /* 0x6 */ u8 unk6;  // A
    /* 0x7 */ u8 unk7;  // B
} CmdType52;

typedef struct {
    /* 0x0 */ u8 xStart;
    /* 0x1 */ u8 yStart;
    /* 0x2 */ u8 xEnd;
    /* 0x3 */ u8 yEnd;
    /* 0x4 */ s16 action;
} CmdType53; // CmdSetWaterLevel

typedef struct {
    /* 0x0 */ u16  unk0;
} CmdType54;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ struct {
                u8 unk0 : 4;
                u8 unk4 : 4;
              } unk7;
} CmdType61;

typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
} CmdType68;

typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8  unk2;
    /* 0x3 */ u8  unk3;
    /* 0x4 */ u8  unk4;
} CmdType71;

typedef struct {
    /* 0x0 */ u16 unk0;
} CmdType72;

typedef struct {
    /* 0x0 */ u16  unk0;
} CmdType74;

typedef struct {
  /* 0x0 */ u8 unk0;  // lbu a0,4(s0)
  /* 0x1 */ u8 unk1;  // lbu a1,5(s0)
  /* 0x2 */ u8 unk2;  // lbu a2,6(s0)
  /* 0x3 */ u8 unk3;  // lbu a3,7(s0)
  /* 0x4 */ u8 unk4;  // 8, 9
  /* 0x5 */ u8 unk5;
  /* 0x6 */ struct {
                s8  unk0 : 5;
                u8  unk5 : 1;
                u8  unk6 : 1;
                u8  pad7 : 1;
            } unk6;
  /* 0x7 */ struct {
                u8  unk0 : 5;
                u8  unk5 : 3;
            } unk7;
} CmdType77;

typedef struct {
    /* 0x0 */ s16 unk0;  // lbu a0,4(s0)
    /* 0x2 */ s16 unk2;   // lbu a2,6(s0)
    /* 0x4 */ u8 unk4;   // 8
    /* 0x5 */ u8 unk5;   // 9
    /* 0x6 */ u8 unk6;  // A
} CmdType82;

typedef struct {
    /* 0x0 */ u16 unk0;
} CmdType83;

typedef struct {
    /* 0x0 */ struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7;
              } unk0;
    /* 0x1 */ struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7;
              } unk1;
    /* 0x2 */ struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7;
              } unk2;
    /* 0x3 */ struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7;
              } unk3;
              struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7; // & 0x7F ?
              } unk4;
              struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7; // & 0x7F ?
              } unk5;
              struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7; // & 0x7F ?
              } unk6;
              struct {
                  u8 unk0 : 1;
                  u8 unk1 : 7; // & 0x7F ?
              } unk7;
} CmdType89;

typedef struct {
    /* 0x0 */ u8 unk0;  // lbu a0,4(s0)
    /* 0x1 */ s8 unk1;  // lbu a1,5(s0)
    /* 0x2 */ s8 unk2;  // lbu a2,6(s0)
    /* 0x3 */ s8 unk3;  // lbu a3,7(s0)
    /* 0x4 */ s8 unk4;  // 8
    /* 0x5 */ s8 unk5;  // 9
    /* 0x6 */ u8 unk6;  // A
    /* 0x7 */ u8 unk7;  // B
} CmdType95;

typedef struct {
  /* 0x0 */ u8 id;
  /* 0x2 */ s16 x;
  /* 0x4 */ s16 z;
  /* 0x6 */ s16 y;
} CmdType96; // CmdSpawnAnimal

typedef struct {
    /* 0x0 */ u8 action;
    /* 0x1 */ u8 op;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
} CmdType101;

typedef struct {
    union {
        CmdRegular regular;
        CmdDummy   dummy;
        CmdUnknown unknown;
        CmdUnknown2 unknown2;
        CmdSimple  simple; // just s16 unk0
        CmdType1   type1;
        CmdType12  type12;
        CmdType13  type13;
        CmdType14  type14;
        CmdType16  type16;
        CmdType17  type17;
        CmdType20  type20;
        CmdType21  type21;
        CmdType22  type22;
        CmdType23  type23;
        CmdType24  type24;
        CmdType29  type29;
        CmdType30  type30;
        CmdType35  type35;
        CmdType37  type37;
        CmdType38  type38;
        CmdType39  type39;
        CmdType41  type41;
        CmdType50  type50;
        CmdType51  type51;
        CmdType52  type52;
        CmdType53  type53;
        CmdType54  type54;
        CmdType61  type61;
        CmdType68  type68;
        CmdType71  type71;
        CmdType72  type72;
        CmdType77  type77;
        CmdType74  type74;
        CmdType82  type82;
        CmdType83  type83;
        CmdType89  type89;
        CmdType95  type95;
        CmdType96  type96;
        CmdType101 type101;
    };
} Cmd; // size 0x8

typedef struct {
    /* 0x0 */ u16 type;
    /* 0x2 */ Cmd cmd;
} CmdWrapper; // size 0xA

typedef struct {
  /* 0x0 */ u8 count;
  /* 0x4 */ CmdWrapper payload;
} CmdsWrapper;

typedef struct {
    /* 0x0   AKA 0x19C */ CmdsWrapper unk19C;
    /* 0xC   AKA 0x1A8 */ CmdWrapper *unk1A8; // ptr to list of commands
    /* 0x10  AKA 0x1AC */ Cmd unk1AC[4];
    /* 0x30  AKA 0x1CC */ u8  unk1CC;
    /* 0x31  AKA 0x1CD */ u8  numCommandsToCopy;
    /* 0x32  AKA 0x1CE */ s16 unk1CE;
    /* 0x34  AKA 0x1D0 */ u8  unk1D0;
    /* 0x36  AKA 0x1D2 */ s16 unk1D2;
    /* 0x38  AKA 0x1D4 */ u8  unk1D4;
    /* 0x39  AKA 0x1D5 */ u8  unk1D5; // numCommandsToCopy2?
    /* 0x3A  AKA 0x1D6 */ s16 unk1D6;
    /* 0x3C  AKA 0x1D8 */ u8  unk1D8;
    /* 0x3D  AKA 0x1D9 */ u8  unk1D9;
    /* 0x3E  AKA 0x1DA */ Cmd unk1DA[4]; // tbd
    /* 0x60  AKA 0x1FC */ CmdWrapper * unk1FC;
} Commands;

typedef struct  {
 /* 0x0 */ s16 unk0;
 /* 0x2 */ s16 unk2;
 /* 0x4 */ s16 unk4; // jointAngleA
 /* 0x6 */ s16 unk6; // jointAngleB
 /* 0x8 */ s16 unk8; // jointAngleC
 /* 0xA */ s16 unkA; // blendTargetA
 /* 0xC */ s16 unkC; // blendTargetB
 /* 0xE */ u16 unkE; // blendTargetC (also used as s16)
 /* 0x10 */ u16 unk10; // ikMode
 /* 0x12 */ s16 unk12; // ikTimer
} LimbIKState; // size 0x14

typedef struct {
    /* 0x3C0 */ u16 unk0; // this is another struct
    /* 0x3C2 */ s16 unk2;
} struct113;

typedef struct  {
    /* 0x3C8 */ s16 unk0; //unk3C8; dynamicTailIndex
    /* 0x3CA */ s16 unk2; //unk3CA;
    /* 0x3CC */ s16 unk4; //unk3CC;
    /* 0x3CE */ u16 unk6; //unk3CE;
    /* 0x3D0 */ s16 unk8; //unk3D0;
} struct106; // size 0xA

typedef struct {
    s16 unk0;
    s16 unk2;
} Energy; // size 0x4

typedef struct {
  /* 0x0 */ struct {
              u8  state  : 4;
            } unk0;
  /* 0x1 */ u8  numVtxs; // max 32
  /* 0x2 */ u8  unk2;
  /* 0x3 */ u8  unk3;
  /* 0x4 */ u8  unk4;
  /* 0x5 */ u8  unk5;
  /* 0x6 */ u8  color[3];
  /* 0x9 */ u8  env[3];
  /* 0xC */ u8  unkC;
  /* 0xC */ u8  unkD;
  /* 0xE */ s16 unkE[16];
  /* 0x2E */ u8  unk2E[16];
  /* 0x3E */ s16 unk3E[16];
  /* 0x5E */ s16 unk5E[16][3]; // x, y, z
  /* 0xBE */ s16 unkBE[16];
  /* 0xDE */ s16 unkDE[16][2];
  /* 0x120 */ Vtx vtxs[32];
  /* 0x320 */ s16 unk320;
  /* 0x322 */ s16 unk322;
  /* 0x324 */ s16 unk324;
  /* 0x328 */ Animal *unk328;
} WalrusWake; // type 3 (TRAIL_TYPE_WALRUS)

typedef struct {
    /* 0x0   */ struct {
                u8  state  : 4;
              } unk0;
    /* 0x1   */ u8 unk1;
    /* 0x2   */ u8 unk2;
    /* 0x3   */ u8 unk3;
    /* 0x4   */ u8 color[3];
    /* 0x7   */ u8 env[3];
    /* 0xA   */ u8 unkA; // tris count?
    /* 0xB   */ u8 paddB[0x21];
    /* 0x2C  */ s16 unk2C; // x
    /* 0x2E  */ s16 unk2E; // z
    /* 0x30  */ s16 unk30; // y
    /* 0x32  */ u8  pad32[0x6];
    /* 0x38  */ Vtx unk38[32];
    /* 0x238 */ s16 unk238;
    /* 0x23A */ s16 unk23A;
    /* 0x23C */ s16 unk23C;
    /* 0x240 */ Animal *animal;
} SimpleTrail; // type 4 (TRAIL_TYPE_SIMPLE)

typedef struct {
    /* 0x0 */ struct {
                u8  state  : 4;
              } unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4; // red
    /* 0x5 */ u8 unk5; // green
    /* 0x6 */ u8 unk6; // blue
    /* 0x7 */ u8 unk7; // envRed
    /* 0x8 */ u8 unk8; // envGreen
    /* 0x9 */ u8 unk9; // envBlue
    /* 0xA */ u8 unkA; // tris count?
    /* 0xB */ u8 unkB;
    /* 0xC */ u8 unkC;
    /* 0xD */ u8 unkD;
    /* 0xE */ u8 unkE;
    /* 0xF */ u8 unkF;
    /* 0x10 */ u8 unk10;
    /* 0x12 */ s16 unk12[13]; // guess
    /* 0x2C */ s16 unk2C; // x
    /* 0x2E */ s16 unk2E; // z
    /* 0x30 */ s16 unk30; // y
    /* 0x32 */ u8  pad32[0x6];
    /* 0x38 */ Vtx unk38[32];
    /* 0x238 */ s16 unk238;
    /* 0x23A */ s16 unk23A;
    /* 0x23C */ s16 unk23C;
    /* 0x240 */ Animal *unk240;
    /* 0x24C */ u8 pad244[0xdc];
    /* 0x320 */ s16 unk320;
    /* 0x322 */ s16 unk322;
    /* 0x324 */ s16 unk324;
    /* 0x328 */ Animal *unk328;
} RegularTrail; // type 1 (TRAIL_TYPE_REGULAR)

typedef struct {
    /* 0x00 */ struct {
                   u8  trailType  : 4; // ((u8) temp_v1->unk0 & 0xFF0F) | 0x10;
                   u8  unk4  : 4; // (s8) ((temp_t5 & 0xF0) | 1);
               } unk0;
    /* 0x01 */ struct {
                   u8  unk0  : 4; // (arg11 * 0x10) | (temp_v1->unk1 & 0xFF0F);
                   u8  unk4  : 4; //  (temp_v1_2->unk1 & 0xFFF0) | 1; OR (temp_t8 & 0xF0) | 1;
               } unk1;
    /* 0x04 */ s32 unk4; // id?
    /* 0x08 */ union {
                  RegularTrail regular;
                  WalrusWake   walrus;
                  SimpleTrail  simple;
              } trail;
  } Trail; // size 0x338

typedef struct {
    u8 x;
    u8 z;
    u8 y;
} Waypoint;

typedef struct {
    u8 length;
    Waypoint waypoint[1];
} WaypointData;

typedef struct {
    s16 eyes[8][13];
} LeftEyes;

typedef struct {
    s16 nine;
    s16 eyes[6][13];
} RightEyes;


typedef struct {
    Position pos;
    s32 unkC; // unkD0, scale factor
} struct043; // size 0x10

typedef struct {
    u8  unk0;
    u8  unk1; // objectType
    u8  unk2;
    u8  unk3;
    Entity *unk4;
} EntityInner;

typedef struct {
    u8 length;
    u8 unk1[5];
} struct002; // size 0x6

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
    /* 0x04 */  Position position;
    /* 0x10 */  Position newPosition;
    /* 0x1C */  Pos xVelocity;
    /* 0x20 */  Pos zVelocity;
    /* 0x24 */  Pos yVelocity;
    /* 0x28 */  s16 unk28; // 0..360
    /* 0x2A */  s16 unk2A; // 0..360
    /* 0x2C */  s16 yRotation;
    /* 0x2E */  s16 zRotation;
    /* 0x30 */  s16 unk30; // width?
    /* 0x32 */  s16 unk32; // depth?
    /* 0x34 */  s16 unk34; // used in collision
    /* 0x36 */  s16 unk36;
    /* 0x38 */  s8  unk38; // xRotationSpeed
    /* 0x39 */  u8  pad39;
    /* 0x3A */  s8  unk3A; // zRotationSpeed
    /* 0x3B */  u8  pad3B;
    /* 0x3C */  s8  unk3C; // yRotationSpeed
    /* 0x3E */  u16 unk3E;
    /* 0x40 */  u16 unk40; // scale
    /* 0x42 */  u16 unk42; // height?
    /* 0x44 */  u16 unk44; // mass?
    /* 0x46 */  u16 unk46; // another mass?
    /* 0x48 */  u16 unk48;
    /* 0x4A */  s8  unk4A; // 0 => player can move animal, 1 => player cannot move animal, 2 => unknown
    /* 0x4B */  u8  unk4B;
    /* 0x4C */  struct {
                    s8  pad0  : 8;  // 0x4C
                    s8  pad8  : 8;  // 0x4D
                    s8  unk10 : 8;  // unk16 //  // 0x4E
                    u8  unk18 : 1;  // unk24 //  // 0x4F OR unk24 & 0xFF7F
                    u8  unk19 : 1;  // unk25 //  // foo->unk4F | 0x40 OR unk24 & 0xFFBF
                    u8  unk1A : 1;  // unk26 //  // unk4C << 0x1A
                    u8  unk1B : 1;  // unk27 //  // (unk4C << 0x1B) >> 0x1F OR unk4C & 0x10
                    u8  unk1C : 1;  // unk28 //  // (unk4C << 0x1C) >> 0x1F OR & 8
                    u8  unk1D : 1;  // unk29 //  // (unk4C << 0x1D) >> 0x1F OR & 4
                    u8  pad1E : 2;  // pad30 //
                } unk4C;
    /* 0x50 */  u8  pad50[0x4];
    /* 0x54 */  EntityInner unk54;
    /* 0x54 */  EntityInner unk5C;
    /* 0x64 */  u8  unk64;
    /* 0x65 */  u8  unk65;  // never really used? lastDamage?
    /* 0x68 */  Animal *unk68; // carry-ee (e.g. what seagull is carrying)
    /* 0x6C */  Animal *unk6C; // baseEntity (i.e. moving platform)
    /* 0x70 */  Animal *unk70; // carry-er (e.g. seagull)
    /* 0x74 */  struct043 unk74[5];
    /* 0xC4 */  struct043 unkC4[5];  // hitboxes?
    /* 0x114 */ s16 unk114[4];       // occupied cells
    /* 0x11C */ CollisionNode unk11C[4]; // collisionNode
                struct {
                    /* 0x14C */ s16 health;
                    /* 0x14E */ s16 unk14E;
                    /* 0x150 */ s16 unk150; // Info.Counter2 ?
                    /* 0x152 */ s16 unk152;
                    /* 0x154 */ u8  lifetime;
                } Info;
    /* 0x158 */ s32 unk158; // some kind of scale?
    /* 0x15C */ u8  unk15C;
    /* 0x15E */ s16 unk15E;
    /* 0x160 */ u8  unk160; // 0, 1 or 2 (mapStatus12)
    /* 0x161 */ u8  unk161; // inheritsBaseVelocity
    /* 0x162 */ u8  movementState;
    /* 0x163 */ u8  unk163;
    /* 0x164 */ u8  unk164;
    /* 0x168 */ Animal *owner; // owner
    /* 0x16C */ struct035* unk16C;

    /* 0x170 */ u8  unk170; // current waypoint mode?
    /* 0x172 */ s16 waypointFudgeFactor;
    /* 0x174 */ struct {
                    s8 unk0 : 4;
                    s8 unk4 : 4;
                    s8 unk8 : 8;
                } unk174;
    /* 0x174 */ s16 unk176; // waypoint related
    /* 0x178 */ s16 waypointTargetXPos;
    /* 0x17A */ s16 waypointTargetZPos;
    /* 0x17C */ s16 waypointTargetYPos;
    /* 0x17E */ s16 waypointStartXPos;
    /* 0x180 */ s16 waypointStartZPos;
    /* 0x182 */ s16 waypointStartYPos;
    /* 0x184 */ s16 waypointVelocity;

    /* 0x188 */ Animal *target;
    /* 0x18C */ struct002 unk18C;
    /* 0x192 */ struct002 unk192;
    /* 0x198 */ Animal *unk198; // pointer?
    /* 0x19C */ Commands commands;
    /* 0x200 */ s32 unk200[3];
    /* 0x20C */ s16 unk20C;
    /* 0x20E */ u16 unk20E;
    /* 0x210 */ s16 unk210;
    /* 0x212 */ s8  unk212;
    /* 0x213 */ s8  unk213;
    /* 0x214 */ s8  unk214;
    /* 0x215 */ u8  unk215;
    /* 0x216 */ u8  unk216;
    /* 0x217 */ u8  unk217;
    /* 0x218 */ u8  unk218;
    /* 0x219 */ u8  unk219;
    /* 0x21A */ u8  unk21A;
    /* 0x21B */ u8  unk21B;
    /* 0x21C */ u8  unk21C;
    /* 0x21D */ u8  unk21D;
    /* 0x21E */ Cmd unk21E;
    /* 0x226 */ u16 unk226; // particle color1
    /* 0x228 */ u16 unk228; // particle color2
    /* 0x22A */ s8  unk22A;
    /* 0x22B */ u8  pad22B;
    /* 0x22C */ u8  unk22C;
    /* 0x22D */ u8  unk22D;
    /* 0x22E */ s16 unk22E;
    /* 0x230 */ s16 unk230;
    /* 0x232 */ s16 unk232;
    /* 0x234 */ u8  unk234[0x2];
    /* 0x236 */ s16 unk236;
    /* 0x238 */ u8  pad238[0x2];
    /* 0x23A */ s16 unk23A;
    /* 0x23C */ Cmd unk23C;
    /* 0x244 */ u16 unk244;
    /* 0x246 */ u16 cmdIndex; // commands index (if applicable)
    /* 0x248 */ Entity *unk248[9];
    /* 0x26C */ u8  unk26C;
    /* 0x26D */ u8  unk26D;
    /* 0x26E */ u8  pad26E[0x2];

    // --- end of Entity/Animal shared fields ---

    /* 0x270 */ u8  unk270;
    /* 0x271 */ u8  unk271;
    /* 0x272 */ u16 unk272; // flagged state, 1, 4, 8...
    /* 0x274 */ u8  navMode;
    /* 0x275 */ s8  navTimer;
    /* 0x276 */ s16 unk276;
    /* 0x278 */ s16 unk278;
    /* 0x27A */ s16 unk27A;
    /* 0x27C */ s16 unk27C; // target y pos
    /* 0x280 */ Animal *unk280; // another one? is this a repeating array?
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8  pad286;
    /* 0x287 */ u8  unk287;
    /* 0x287 */ u16 unk288;
    /* 0x287 */ u8  unk28A;
    /* 0x287 */ u8  unk28B;
    /* 0x28C */ u16 waypointMode;
    /* 0x28E */ u8  unk28E;
    /* 0x290 */ s16 unk290;
    /* 0x294 */ union {
                    struct {
                      s8 pathId;
                      s8 unk1;
                      struct {
                        s8 unk0 : 4;
                        u8 unk4 : 4;
                      } unk2;
                      u8 unk3;
                      s8 unk4;
                    } type1;
                    struct {
                      s8 unk0;
                      u8 unk1;
                      s16 xPos;
                      s16 zPos;
                      s16 yPos;
                    } type2;
                    struct {
                      u8 unk0;
                    } type3;
                    struct {
                      u8 unk0;
                    } type4;
                    struct {
                      Animal *unk0;
                      s16 unk4;
                    } type5;
                    struct {
                      s16 unk0;
                    } type6;
                    struct {
                      Animal *unk0;
                    } type7;
                    struct {
                      Animal *target;
                      s16 unk4;
                      u8  unk6;
                    } type8;
                    struct {
                      Animal *target;
                      s16 unk4;
                    } type9;
                } unk294;
    /* 0x29C */ WaypointData *waypointData;
    /* 0x2A0 */ u8  navState;
    /* 0x2A1 */ s8  unk2A1;
    /* 0x2A2 */ u8  unk2A2;
    /* 0x2A4 */ s16 xPosTarget;
    /* 0x2A6 */ s16 zPosTarget;
    /* 0x2A8 */ s16 yPosTarget;
    /* 0x2AC */ Animal* unk2AC;
    /* 0x2B0 */ u8  targetIsPlayer;
    /* 0x2B4 */ struct {
                    u8  state : 4; // 0xFF0F => 0
                    u8  unk4  : 3; // 0xFFF1 => 0
                    u8  unk7  : 1;
                    s8  unk8  : 8;
                    u32 pad10 : 16;
                } unk2B4;
    /* 0x2B8 */ s32 unk2B8;
    /* 0x2BC */ s32 unk2BC;
    /* 0x2C0 */ s32 unk2C0;
    /* 0x2C4 */ s32 unk2C4; // "FC" ?
    /* 0x2C8 */ u16 unk2C8;
    /* 0x2CC */ Animal* unk2CC; // target for missiles?
    /* 0x2D0 */ s16 targetDistance;
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ s16 unk2DC;
    /* 0x2DE */ u8  unk2DE[0x2];
    /* 0x2E0 */ Energy energy[2];       // seems to be an array?
    /* 0x2E8 */ u8  missileScaleLeft;   // scale factor for 'left' side missile
    /* 0x2E9 */ u8  missileScaleRight;  // scale factor for 'right' side missile
    /* 0x2EA */ u8  missileSide;        // selector for missile 1 or 2
    /* 0x2EB */ s8  unk2EB;
    /* 0x2EC */ s16 unk2EC;             // (husky) bite energy? stamina? another attackTimer?
    /* 0x2EE */ u16 unk2EE;
    // /* 0x2EE */ struct {
    //                 s16  unk0 : 10;
    //                 u16  unkA : 6;
    //             } unk2EE;
    /* 0x2F0 */ u8  pad2F0[0x2];
    /* 0x2F2 */ u16 gaitPhase;
    /* 0x2F4 */ u16 unk2F4;
    /* 0x2F6 */ u16 gaitPhaseOffset; // tbd
    /* 0x2F8 */ u16 prevGaitPhaseOffset;
    /* 0x2FA */ u16 unk2FA;
    /* 0x2FC */ u16 gaitCycleLength;
    /* 0x2FE */ u16 unk2FE;
    /* 0x300 */ u16 unk300;
    /* 0x302 */ s16 heading;
    /* 0x304 */ s16 previousHeading;
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
    /* 0x31C */ u16 unk31C;
    /* 0x320 */ Animal *unk320;
    /* 0x324 */ u16 unk324; // temporary state? next state?
    /* 0x326 */ s16 unk326; // eye timer (e.g. blinking)
    /* 0x328 */ u16 unk328;
    /* 0x32A */ u16 unk32A;
    /* 0x32C */ s16 unk32C;
    /* 0x330 */ Animal *unk330;
    /* 0x334 */ u16 attackTimer;
    /* 0x338 */ s32 unk338;
    /* 0x33C */ s32 pad33C[3];
    /* 0x348 */ s16 unk348; // (desert fox) dizziness duration and size
    /* 0x34A */ s16 unk34A; // (desert fox) dizziness recovery delay?
    /* 0x34C */ s16 laughterDuration;
    /* 0x34E */ s16 unk34E;
    /* 0x34E */ s16 unk350;
    /* 0x352 */ s16 unk352; // some scaling factors?
    /* 0x354 */ s16 unk354;
    /* 0x356 */ s16 unk356; // some scaling factors?
    /* 0x358 */ s16 laughterThreshold; // what is a better name, if this is above 80, animal will start laughing
    /* 0x35A */ s16 unk35A; // current bounce velocity?
    /* 0x35C */ s16 unk35C; // bounce acceleration
    /* 0x35E */ u16 unk35E;
    /* 0x360 */ s8  unk360;
    /* 0x361 */ s8  unk361;
    /* 0x362 */ u8  laughterFactor;
    /* 0x363 */ u8  isLaughing;
    /* 0x364 */ u8  unk364;
    /* 0x365 */ u8  unk365; // current attack
    /* 0x366 */ u8  movementMode;
    /* 0x367 */ u8  unk367;
    /* 0x368 */ s8  unk368;
    /* 0x369 */ u8  unk369;
    /* 0x36A */ s8  unk36A;
    /* 0x36B */ s8  lastHpLost;
    /* 0x36C */ u8  unk36C;
    /* 0x36D */ u8  unk36D;
    /* 0x36E */ s8  unk36E; // boost speed?
    /* 0x36F */ s8  unk36F;
    /* 0x370 */ LimbIKState unk370;
    /* 0x384 */ LimbIKState unk384; // s16 x 7
    /* 0x398 */ LimbIKState unk398;
    /* 0x3AC */ LimbIKState unk3AC;
    /* 0x3C0 */ struct113 unk3C0;
    /* 0x3C4 */ struct113 unk3C4;
    /* 0x3C8 */ struct106 unk3C8;
    /* 0x3D2 */ s16 unk3D2;
}; // size 0x3D4

typedef struct {
    s8  unk0;
    u8  unk1;
    u8  unk2;
    u8  unk3;
} struct003;

typedef struct {
    u32 End1;
    u32 End2;
    u32 Start1;
    u32 Start2;
} struct005;

typedef struct {
                u8  pad0[0x1E];
    /* 0x1E */  u8  countryCode;
    /* 0x20 */  s16 region;
} RomHeader;

typedef struct {
    /* 0x0 */ s32 vStart;
    /* 0x4 */ s32 yScale;
    /* 0x8 */ s16 VIModeType;
    /* 0xA */ s16 screenWidth;
} VIData; // size 0xC

typedef struct {
    s16 unk0[360];
    s16 unk2D0[90];
    s16 unk384[90]; // ?
} struct013;

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
} Controller; // size 0x40;

struct struct017 {
    /* 0x00 */ u16 unk0; // priority?
    /* 0x02 */ u16 sndID;
    /* 0x04 */ u8  sndPan;
    /* 0x08 */ f32 sndPitch;
    /* 0x0C */ s16 sndVolume;
    /* 0x0E */ u16 counter;
    /* 0x10 */ u16 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s16 sndArrayIndex;
    /* 0x1E */ s16 unk1E; // index?
    /* 0x20 */ u16 unk20;
    /* 0x22 */ s16 sndSlot;
    /* 0x24 */ u8  sndState;
    /* 0x25 */ u8  pad25[0x3];
    /* 0x28 */ s32 object; // ptr?
    /* 0x2C */ struct017 *prev; // maybe
    /* 0x30 */ struct017 *next;
}; // size 0x34

typedef struct {
    s32 params[66];
} struct121; // size 0x108

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
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
} FlatMatrix;

typedef struct {
    /* 0x0000 */  Gfx mainDL[4000];
    /* 0x7D00 */  Gfx gLayer1DL[800];
    /* 0x9600 */  Gfx gOpaqueDL[1200];
    /* 0xBB80 */  Gfx gXluDL[1000];
    /* 0xDAC0 */  Gfx gLayer0DL[1500];
    /* 0x109A0 */ Gfx unk109A0[8][1400];
    /* 0x267A0 */ Gfx gAuxDL[1000];

    /* 0x286E0 */ Vtx unk286E0[961]; // ???
    /* 0x2C2F0 */ Vtx unk2C2F0[40];
    /* 0x2C570 */ Vtx unk2C570[1000];
    /* 0x303F0 */ Vtx unk303F0[200];
    /* 0x31070 */ Vtx unk31070[30]; // might be bigger, treated as pairs
    /* 0x31250 */ Vtx unk31250[350]; // might only be 8?
    /* 0x32830 */ Mtx unk32830; // unused?
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
    /* 0x3891C */ s32 usedVtxs;
    /* 0x38920 */ u8  pad38920[0xF0];
    /* 0x38A10 */ union {
                    f32 m[4][4];
                    FlatMatrix flat;
                } unk38A10;
    /* 0x38A50 */ LookAt unk38A50[20];
    /* 0x38CD0 */ Mtx unk38CD0[25];
    /* 0x39310 */ u16 unk39310; // used lookAts
    /* 0x39312 */ u8  pad39312[0x976];
    /* 0x39C88 */ Vtx unk39C88[360]; // tbd
    /* 0x3B308 */ s16 unk3B308;     // used to index into unk39C88
    /* 0x3B30A */ u8  unk3B30A[14]; // vtx count
    /* 0x3B318 */ Gfx unk3B318[100]; // maybe?
    /* 0x3B638 */ Lights7 lights;
    /* 0x3B6B0 */ Ambient unk3B6B0;
    /* 0x3B6B8 */ Light unk3B6B8;
} DisplayList; // 0x3B6D0 big?

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
} struct031; // size 0x68 (actually OSScTask_s)

typedef struct {
    /* 0x00000 */ struct031 tasks[12]; // OSScTask_s
    /* 0x004E0 */ DisplayList dl;
    /* 0x3BBA8 */ u16 unk3BBA8; // set but unused
    /* 0x3BBAA */ u8  pad3BBAA[0x1E];
    /* 0x3BBC8 */ u16 unk3BBC8; // message
    /* 0x3BBCA */ u8  pad3BBCA[0x1E];
    /* 0x3BBE8 */ u8 *framebuffer; // pointer to framebuffer
} FrameContext; // size 0x3BBF0

typedef struct {
    /* 0x00 */ s32 checksum;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8; // 1 = state has been reset
    /* 0x0C */ s8  musicVol;
    /* 0x0D */ s8  sfxVol;
    /* 0x0E */ s8  language;  // chosen language, e.g. LANG_ENGLISH
    /* 0x10 */ s32 pad10[0xC];
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
#if 0
    /* 0x30 */ struct {
                  u16 evosEscapeScore : 8; // 11111111 00000000 00000000 00000000 | (x >> 24)
                  u16 unused          : 2; // 00000000 11000000 00000000 00000000
                  u16 gadabTime       : 9; // 00000000 00111111 11100000 00000000 | (x >> 13) & 0x1FF
                  u16 punchupTime     : 5; // 00000000 00000000 00011111 00000000 | (x >>  8) & 0x1F)
                  u16 walraceTime     : 8; // 00000000 00000000 00000000 11111111 | (x      ) & 0xFF)
               } unk30;
#else
    /* 0x30 */ u32 unk30;
#endif
    /* 0x34 */ u32 unk34; // tbd if this is a bitfield
    /* 0x38 */ u8  pad38[0x3];
    /* 0x3B */ s8  evoPartsCollected;
    /* 0x3C */ s32 score;
} PlayerEeprom; // size 0x40 (64 bytes)

typedef struct {
    /* 0x00 */ s16 cameraMode; // camera mode?
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4; // nextCameraMode?
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C; // used in Z-mode
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;  // distance?
    /* 0x50 */ s16 unk50;  // distance?
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ s16 unk62;
    /* 0x64 */ s8  unk64;
    /* 0x65 */ s8  unk65;
    /* 0x66 */ s8  unk66;
    /* 0x67 */ u8  unk67;
    /* 0x68 */ u8  unk68; //[0x4];
    /* 0x69 */ u8  pad69[3];
    /* 0x6C */ WaypointData *unk6C;
    /* 0x70 */ s16 unk70;
    /* 0x71 */ u8  pad72[0x2];
    /* 0x74 */ f32 unk74;
    /* 0x78 */ f32 unk78;
    /* 0x7C */ f32 unk7C;
    /* 0x80 */ f32 unk80;
    /* 0x84 */ f32 unk84;
    /* 0x88 */ f32 unk88;
    /* 0x8C */ f32 unk8C;
    /* 0x90 */ f32 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 unk98;
    /* 0x9C */ f32 unk9C;
    /* 0xA0 */ f32 unkA0;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ f32 unkB0;
    /* 0xB4 */ f32 unkB4;
    /* 0xB8 */ f32 unkB8;
    /* 0xBC */ f32 unkBC;
    /* 0xC0 */ f32 unkC0;
    /* 0xC4 */ f32 unkC4;
    /* 0xC8 */ u8  unkC8;
    /* 0xC9 */ u8  unkC9;
    /* 0xCA */ s16 unkCA;
    /* 0xCC */ Entity *unkCC; // animal ?
    /* 0xD0 */ s16 unkD0;
    /* 0xD2 */ s16 unkD2;
    /* 0xD4 */ s16 unkD4;
    /* 0xD6 */ s8  unkD6;
    /* 0xD7 */ u8  unkD7;
    /* 0xD8 */ u8  unkD8;
    /* 0xD9 */ u8  padD9[0x3];
} Camera; // size 0xDC

typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    u8  padA[0x2];
    s16 unkC;
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
} struct027; // size 0x37

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} struct028;

typedef struct {
    /* 0x00 */  Animal* animal;
    /* 0x04 */  s16     health;
    /* 0x06 */  s16     unk6; // health related too?
    /* 0x08 */  s16     unk8; // ALSO health?
    /* 0x0A */  s16     unkA; // 0x40?
} struct033; // size 0xC

struct struct035 { // TODO: merge with ObjectData?
  /* 0x00 */  u16 objectType;
  /* 0x02 */  u8  unk2;
  /* 0x03 */  u8  unk3;
  /* 0x04 */  Gfx *displayList1;
  /* 0x08 */  Gfx *displayList2;
  /* 0x0C */  Gfx *displayList3;
  /* 0x10 */  s32 unk10;
  /* 0x014 */ u8  unk14;
  /* 0x15 */  u8  unk15; // checked if 2 or 4?
  /* 0x16 */  u16 unk16;
  /* 0x18 */  Collision *collision;
  /* 0x1C */  u16 collisionIdx;
  /* 0x1E */  s16 pad1E;
  /* 0x20 */  s32 unk20[5][4]; // wrong
  /* 0x70 */  u16 unk70;
  /* 0x72 */  u16 unk72; // depth
              s16 unk74; // width
              s16 unk76; // height
              s16 unk78;
              u16 unk7A;
  /* 0x7C */  u16 mass;
  /* 0x7E */  s16 unk7E;
  /* 0x80 */  s16 unk80;
  /* 0x82 */  struct {
                  u8  unk0  : 1; // 0x80
                  u8  unk1  : 1; // 0x40
                  u8  unk2  : 1; // 0x20
                  u8  unk3  : 1; // 0x10
                  u8  unk4  : 1; // 0x8
                  u8  unk5  : 1; // 0x4
                  u8  unk6  : 1; // 0x2
                  u8  unk7  : 1; // 0x1
              } unk82;
  /* 0x83 */  u8 unk83;
  /* 0x84 */  void (*unk84)(void *);
  /* 0x88 */  u8  unk88;
  /* 0x89 */  u8  unk89;
  /* 0x8A */  u8  unk8A; // health?
  /* 0x8B */  u8  armour;
  /* 0x8C */  u8  unk8C; // (collisionDamageFactor) hard mouse has this value / 5
  /* 0x8D */  u8  unk8D; // contactDamage
  /* 0x8E */  u16 unk8E;
  /* 0x90 */  u8  unk90;
  /* 0x91 */  u8  unk91; // red
  /* 0x92 */  u8  unk92; // green
  /* 0x93 */  u8  unk93; // blue
  /* 0x94 */  s8  unk94; // alpha?
  /* 0x95 */  u8  pad95;
  // very much TBD:
  /* 0x96 */  struct {
                  u8 a : 4;
                  u8 b : 4;
              } unk96;
  /* 0x97 */  u8  unk97;
  /* 0x98 */  u8  unk98;
  /* 0x99 */  s8  unk99;
  /* 0x98 */  u8  pad9A[0x2];

  /* 0x9C */  u16 unk9C; // ANIMAL_TYPE
  /* 0x9E */  u16 class;
  /* 0xA0 */  u16 waterClass;
  /* 0xA2 */  u16 canJump;
              u16 unkA4; // scaling?
              u16 unkA6;
              u16 unkA8;
              u16 unkAA; // scaling?
              u16 unkAC; // scaling?
  /* 0xAE */  s16 fallDistance;
              s16 unkB0;
  /* 0xB2 */  u16 traction;
              s16 unkB4;
              s16 unkB6;
              u16 unkB8;
              u16 unkBA;
              u16 unkBC; // height
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
  /* 0xDA */  s16 unkDA[2][3]; // skill A/B (drainRate;unknown;unknown)
  /* 0xE6 */  s8  unkE6; // animal class / value?
  /* 0xE7 */  s8  unkE7;
  /* 0xE8 */  s8  unkE8;
  /* 0xE8 */  s8  unkE9;
  /* 0xE8 */  s8  unkEA;
  /* 0xEB */  s8  unkEB;
}; // size 0xEC

typedef struct {
  /* 0x0  */ s64 unk0;  // x
  /* 0x8  */ s64 unk8;  // z
  /* 0x10 */ s64 unk10; // y

  /* 0x18 */ s16 unk18; // argA
  /* 0x1A */ u8  unk1A;
  /* 0x1C */ s16 size;
  /* 0x20 */ s32 unk20; // arg4
  /* 0x24 */ s32 unk24; // arg5
  /* 0x28 */ s32 unk28; // arg6
  /* 0x2C */ u8  id;
  /* 0x2D */ u8  unk2D;
  /* 0x2E */ s8  unk2E;
  /* 0x30 */ u16 primaryColor;
  /* 0x32 */ u16 envColor;
  /* 0x34 */ u16 unk34; // also argA
  /* 0x36 */ s16 unk36;
  /* 0x38 */ s8  unk38; // flags
  /* 0x38 */ u8  pad39[0x7];
} struct036; // size 0x40

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
    s16 start;
    s16 end;
    s32 position;
} GfxHelper; // size 0x8

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
    /* 0x12 */ s16 bcp;
    /* 0x14 */ s16 hidden;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
} Cheats; // size 0x1A

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
    /* 0x32 */ s8  previousLevel; // previously selected level
} struct030; // size 0x33 ?

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
} struct032; // size 0x4C TBD

typedef struct {
    u8 *romStart;   // e.g. 007d1ad0
    u8 *romEnd;     // e.g. 007d2f50
    u8 *ramStart;   // e.g. 803fdec0
    u8 *ramEnd;     // e.g. 803ff340
    u8 *ramStart2;  // e.g. 803fdec0
} struct046; // size 0x14

typedef struct {
    struct035 *unk0;
    Animal    *animal;
} Animal2; // size 0x8

typedef struct {
    /* 0x0000 */ struct035 unk0[68];        // each 0xEC so 0x3EB0 total
    /* 0x3EB0 */ Animal2   animals[50];
    /* 0x4040 */ Animal    unk4040[50];     // D_801DDF18
    /* 0xFFA8 */ s16       unkFFA8;         // D_801E9E80
    /* 0xFFAA */ u8        padFFAA[0x8];
    /* 0xFFB2 */ u16       curAButton;      // A pressed
    /* 0xFFB4 */ u16       curLRTrigger;    // L/R Trigger (1 or 2)
    /* 0xFFB6 */ u16       curBButton;      // B pressed
    /* 0xFFB8 */ u16       prevAButton;     // D_801E9E90, prev a pressed?
    /* 0xFFBA */ u16       prevLRTrigger;
    /* 0xFFBC */ u16       prevBButton;
    /* 0xFFBE */ u16       curDPadUp;       // D-PAD Up pressed
    /* 0xFFC0 */ u16       curDPadDown;     // D-PAD Down pressed
    /* 0xFFC2 */ u16       curDPadLeft;     // D-PAD Left pressed
    /* 0xFFC4 */ u16       curDPadRight;    // D-PAD Right pressed
    /* 0xFFC6 */ u16       curCButtonUp;    // C-button Up
    /* 0xFFC8 */ u16       curCButtonDown;  // C-button Down
    /* 0xFFCA */ u16       curCButtonLeft;  // C-button Left
    /* 0xFFCA */ u16       curCButtonRight; // C-button Right
    /* 0xFFCE */ u16       unkFFCE;
    /* 0xFFD0 */ u16       prevDPadLeft; // Previous D-PAD Left pressed
    /* 0xFFD2 */ u16       prevDPadRight; // Previous D-PAD Right pressed
    /* 0xFFD4 */ u16       prevDPadUp; // Previous D-PAD Up pressed
    /* 0xFFD6 */ u16       prevDPadDown; // Previous D-PAD Down pressed
    /* 0xFFD8 */ s8        stickX; // stick x
    /* 0xFFD8 */ s8        stickY; // stick y
    /* 0xFFDA */ s16       unkFFDA; // D_801E9EB2
    /* 0xFFDC */ s16       unkFFDC; // D_801E9EB4
    /* 0xFFDE */ s16       unkFFDE; // D_801E9EB6
} struct050;

typedef struct {
    /* 0x0 */  Animal *unk0;
    /* 0x4 */  Animal *unk4;
    /* 0x8 */  s16 unk8;
    /* 0xA */  s16 unkA;
    /* 0xC */  s16 unkC;
    /* 0xE */  s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 numSegments;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s32 unk18; // length
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ u8  pad1E[2];
    /* 0x20 */ s32 unk20; // xPos
    /* 0x24 */ s32 unk24; // zPos
    /* 0x28 */ s32 unk28; // yPos
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s8  tailType;
    /* 0x2F */ s8  unk2F;
    /* 0x30 */ s8  unk30; // lastSegmentNum?
    /* 0x31 */ s8  unk31;
    /* 0x32 */ u8  unk32;
    /* 0x33 */ u8  unk33;
    /* 0x34 */ s8  unk34;
    /* 0x35 */ s8  unk35;
    /* 0x36 */ u8  pad36[0x2];
} struct051; // size 0x38

// might just be an s16 array but this is a little nicer
typedef struct {
    s16 x;
    s16 y;
    s16 brightness;
    s16 speed;
} Star; // size 0x8

typedef struct {
    s8  unk0[8][64];
    s16 unk200; // lod? (0..255)
    u16 unk202; // current water tile index (0..15)
    u16 unk204; // (0..63)
    u16 unk206;
    s16 unk208;
    s16 unk20A;
    u8  unk20C; // another water tile index (0..31)
    u8  unk20D;
    u8  unk20E;
    u8  unk20F;
} struct053; // size 0x210

typedef struct {
    /* 0x0  */ s16 unk0;
    /* 0x2  */ s16 unk2; // teleporter type
    /* 0x4  */ s16 unk4;
    /* 0x6  */ s16 unk6[12]; // green?
    /* 0x1E */ s16 unk1E[12]; // size?
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46; // 2nd xPos
    /* 0x48 */ s16 unk48; // 2nd zPos
    /* 0x4A */ s16 unk4A; // 2nd yPos
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52; // xPos
    /* 0x54 */ s16 unk54; // zPos
    /* 0x56 */ s16 unk56; // yPos
    /* 0x58 */ Animal *unk58;
    /* 0x5C */ Entity *unk5C;
    /* 0x60 */ Entity *unk60;
    /* 0x64 */ s16 unk64;
} struct054; // size 0x66

typedef struct {
    s16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    Gfx *unk14;
    u8 unk18;
} struct057; // size 0x1C

typedef struct {
    /* 0x0 */ s32 xPos;  // x
    /* 0x4 */ s32 zPos;  // y
    /* 0x8 */ s32 yPos;  // z
    /* 0xC */ u16 size;
    /* 0xE */ u8  category;
    /* 0xF */ s8  next;
    /* 0x10 */ s8 unk10; // id?
    /* 0x11 */ u8 red;
    /* 0x12 */ u8 green;
    /* 0x13 */ u8 blue;
} DynamicTexture; // size 0x14

typedef struct {
    /* 0x0 */  s8 unk0;
    /* 0x1 */  s8 unk1;
    /* 0x2 */  s8 textureGroups[64]; // tbd
    /* 0x44 */ DynamicTexture textures[75]; // ?
} DynamicTextures; // DynamicTextureManager ?

typedef struct {
     s32 unk0;
     s32 unk4;
     s32 unk8;
     s16 unkC;
     u16 unkE;
} struct060; // size 0x10?

typedef struct {
    s16 unk0;  // vtx x
    s16 unk2;  // vtx y
    s16 unk4;  // tc0
    s16 unk6;  // tc1
} Vertex; // size 0x8

typedef struct {
    s16 unk0;  // x
    s16 unk2;  // z
    s16 unk4;  // y
    s16 unk6;  // alignment?
} LimbConfig;  // size 0x8

typedef struct {
    WaypointData *unk0; // union with Entity ?!
    u8  pad4[0x4];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12; // cameraModeIndex
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    s8  unk18;
    s8  unk19;
    s8  unk1A;
    u8  unk1B;
    u8  pad1C[0x4];
} struct062; // size 0x20

typedef struct {
    u8 unk0; // terrain height?
    u8 unk1; // terrain height?
    u8 unk2; // terrain type?
    u8 unk3; // e.g. bridges? fences?
    u8 unk4; // flags
    u8 unk5; // also flags
    u8 unk6; // water?
#if 0
    union {
        struct {
          u8 unk0 : 1; // ((x >> 4) & 8) >> 2
          u8 unk1 : 3; // ((x & 0xF0) >> 4) & 7
          u8 unk4 : 1; // (x & 8) >> 2
          u8 unk5 : 3; // (x & 7)
        } bits; // bitfield?
        u8 ub;
    } unk7;
#else
    u8 unk7;
#endif
} struct063; // size 0x8

typedef struct {
    u8 unk0; // friction?
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    s8 unkB;
} struct064; // size 0xC

typedef struct {
    u8 *start;
    u8 *end;
} struct066;

typedef struct {
  u8  unk0; // start1
  u8  unk1; // start2
  u8  unk2; // used?
  u8  unk3; // end 1
  u8  unk4; // send 2
  u8  unk5; // used2?
  u16 alignment;
} struct067; // size 0x8

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
    /* 0x18 */ Collision* collision;
    /* 0x1C */ u16 collisionIndex;
    /* 0x1E */ u8 pad1E[0x52];
    /* 0x70 */ s32 unk70;
    /* 0x74 */ u8  pad74[0xC];
    /* 0x80 */ s16 unk80;
  /* 0x82 */  struct {
                  u8  unk0  : 1; // 0x80
                  u8  unk1  : 1; // 0x40
                  u8  unk2  : 1; // 0x20
                  u8  unk3  : 1; // 0x10
                  u8  unk4  : 1; // 0x8
                  u8  unk5  : 1; // 0x4
                  u8  unk6  : 1; // 0x2
                  u8  unk7  : 1; // 0x1
              } unk82;
              u8 pad83;
    /* 0x84 */ u8  pad84[0x5];
    /* 0x89 */ u8  unk89;
    /* 0x8A */ u8  unk8A;
    /* 0x8B */ u8  pad8B[0x11];
} ObjectData; // size 0x9C, ObjectData ?

struct Entity {
    /* 0x0 */   u16 state; // enabled/disabled
    /* 0x4 */   Position position;
    /* 0x10 */  Position newPosition;
    /* 0x1C */  Pos xVelocity;
    /* 0x20 */  Pos zVelocity;
    /* 0x24 */  Pos yVelocity;
    /* 0x28 */  s16 unk28; // 0..360
    /* 0x2A */  s16 unk2A; // 0..360
    /* 0x2C */  s16 yRotation; // rotation
    /* 0x2E */  s16 zRotation; // vertical rotation
    /* 0x30 */  s16 unk30; // width
    /* 0x32 */  s16 unk32; // depth
    /* 0x34 */  s16 unk34;
    /* 0x36 */  s16 unk36;
    /* 0x38 */  s8  unk38;
    /* 0x39 */  u8  pad39;
    /* 0x3A */  s8  unk3A;
    /* 0x3B */  u8  pad3B;
    /* 0x3C */  s8  unk3C;
    /* 0x3E */  u16 unk3E;
    /* 0x40 */  u16 unk40;
    /* 0x42 */  u16 unk42; // height
    /* 0x44 */  u16 unk44;
    /* 0x46 */  u16 unk46;
    /* 0x48 */  u16 unk48;
    /* 0x4A */  s8  unk4A; // 0 => player can move animal, 1 => player cannot move animal, 2 => unknown
    /* 0x4B */  u8  unk4B;
    /* 0x4F */  struct {
                    s8  pad0  : 8; // 0x4C (tilePressureScale)
                    s8  pad8  : 8; // 0x4D (tilePressureCounter)
                    s8  unk10 : 8; // 0x4E
                    u8  unk18 : 1; // x111 1111 (movedThisFrame)
                    u8  unk19 : 1; // 1x11 1111 (keepAwake)
                    u8  unk1A : 1; // 11x1 1111
                    u8  unk1B : 1; // 111x 1111
                    u8  unk1C : 1; // 1111 x111 (canMoveHorizontally)
                    u8  unk1D : 1; // 1111 1x11 (canMoveVertically)
                    u8  pad1E : 2; // 1111 11x1
                } unk4C;
    /* 0x50 */  u8  pad50[0x4];
    /* 0x54 */  EntityInner unk54;
    /* 0x5C */  EntityInner unk5C;
    /* 0x64 */  u8  unk64;
    /* 0x65 */  u8  unk65;
    /* 0x68 */  Entity *unk68;
    /* 0x6C */  Entity *unk6C; // baseEntity
    /* 0x70 */  Entity *unk70;
    /* 0x74 */  struct043 unk74[5];
    /* 0xC4 */  struct043 unkC4[5];  // hitboxes?
    /* 0x114 */ s16 unk114[4];
    /* 0x11C */ CollisionNode unk11C[4]; // collisionNode
                struct {
    /* 0x14C */     s16 health;
    /* 0x14E */     s16 unk14E;
    /* 0x150 */     s16 Counter2; // inferred from ESA decomp
    /* 0x152 */     s16 unk152;
    /* 0x154 */     u8  lifetime;
                } Info; // TBD how large this is
    /* 0x158 */ s32 unk158;
    /* 0x15C */ u8  unk15C;
    /* 0x15E */ s16 unk15E;
    /* 0x160 */ u8  unk160; // 0, 1 or 2 (mapStatus12)
    /* 0x161 */ u8  unk161; // inheritsBaseVelocity
    /* 0x162 */ u8  movementState;
    /* 0x163 */ u8  unk163;
    /* 0x164 */ u8  unk164;
    /* 0x168 */ Animal *owner;
    /* 0x16C */ struct035 *unk16C;

    /* 0x170 */ u8  unk170; // current waypoint mode?
    /* 0x172 */ s16 waypointFudgeFactor;
    /* 0x174 */ struct {
                    s8 unk0 : 4;
                    s8 unk4 : 4;
                    s8 unk8 : 8;
                } unk174;
    /* 0x174 */ s16 unk176; // waypoint related
    /* 0x178 */ s16 waypointTargetXPos;
    /* 0x17A */ s16 waypointTargetZPos;
    /* 0x17C */ s16 waypointTargetYPos;
    /* 0x17E */ s16 waypointStartXPos;
    /* 0x180 */ s16 waypointStartZPos;
    /* 0x182 */ s16 waypointStartYPos;
    /* 0x184 */ s16 waypointVelocity;

    /* 0x188 */ Animal *target;
    /* 0x18C */ struct002 unk18C;
    /* 0x192 */ struct002 unk192;
    /* 0x198 */ void *unk198;

    /* 0x19C */ Commands commands;

    /* 0x200 */ s32 unk200; // r
    /* 0x204 */ s32 unk204; // g
    /* 0x208 */ s32 unk208; // b

    /* 0x20C */ s16 unk20C;
    /* 0x20E */ u16 unk20E;
    /* 0x210 */ s16 unk210;
    /* 0x212 */ s8  unk212;
    /* 0x213 */ s8  unk213;
    /* 0x214 */ s8  unk214;
    /* 0x215 */ u8  unk215;
    /* 0x216 */ u8  unk216;
    /* 0x217 */ u8  unk217;
    /* 0x218 */ u8  unk218;
    /* 0x219 */ u8  unk219;
    /* 0x21A */ u8  unk21A;
    /* 0x21B */ u8  unk21B;
    /* 0x21C */ u8  unk21C;
    /* 0x21D */ u8  unk21D;
    /* 0x21E */ Cmd unk21E;
    /* 0x226 */ u16 unk226; // particle color1
    /* 0x228 */ u16 unk228; // particle color2
    /* 0x22A */ s8  unk22A;
    /* 0x22B */ u8  pad22B;
    /* 0x22C */ u8  unk22C;
    /* 0x22D */ u8  unk22D;
    /* 0x22E */ s16 unk22E;
    /* 0x230 */ s16 unk230;
    /* 0x232 */ s16 unk232;
    /* 0x234 */ u8  unk234[0x2];
    /* 0x236 */ s16 unk236;
    /* 0x238 */ u8  pad238[0x2];
    /* 0x23A */ s16 unk23A;
    /* 0x23C */ Cmd unk23C;
    /* 0x244 */ u16 unk244;

    /* 0x246 */ s16 cmdIndex; // (if applicable)
    /* 0x248 */ Entity *unk248[9];
    /* 0x26C */ u8  unk26C;
    /* 0x26D */ u8  unk26D;
    /* 0x26E */ u8  pad26E[0x2]; // just alignment?
}; // game object, size 0x270

typedef struct {
    /* 0x0  */ u8  unk0;
    /* 0x1  */ s8  type;
    /* 0x2  */ s16 unk2;   // index? used to index into D_803E2930 (uls/ult)
    /* 0x4  */ s32 uls;    // Texture tile's upper-left s coordinate (10.2, 0.0~1023.75).
    /* 0x8  */ s32 ult;    // Texture tile's upper-left t coordinate (10.2, 0.0~1023.75).
    /* 0xC  */ s32 uls2;   // 10.2 format
    /* 0x10 */ s32 ult2;   // 10.2 format
    /* 0x14 */ Gfx *displayList;
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
    s16 unk0;
    s16 unk2;
} struct076; // size 0x4

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} struct077; // size 0x6

struct struct078 {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ u8  pad6[0x6];
    /* 0xC */ s8  unkC;
    /* 0xD */ s8  unkD;
    /* 0xE */ s8  unkE;
    /* 0xF */ u8  padF;
} ; // size 0x10

typedef struct {
    /* 0x0 */  u16 used;
    /* 0x2 */  // padding not required
    /* 0x4 */  s32 distance[3];
    /* 0x10 */ Animal *animal[3];
} struct079_inner; // size 0x1C

typedef struct {
    /* 0x0 */  struct079_inner unk0;
    /* 0x1C */ struct079_inner unk1C;
    /* 0x38 */ struct079_inner unk38;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ Animal *unk58; // Animal? or Object?
    /* 0x5C */ s32 distance;
    /* 0x60 */ Animal *unk60;
    /* 0x64 */ u8  unk64;
} struct079; // size 0x65 ?

typedef struct {
    s8 unk0;
    s8 unk1;
} struct082;

typedef struct {
    u8           used;
    u8           pad[0x7];
    /* 0x00 */   struct036 particles[255];
    /* 0x3FC8 */ s8  unk3FC8[8]; // is displaylist enabled?
    /* 0x3FD0 */ u16 unk3FD0;
    /* 0x3FD2 */ s16 unk3FD2;
    /* 0x3FD4 */ s16 unk3FD4;
    /* 0x3FD6 */ s16 unk3FD6;
} struct084; // size 0x3FD8

typedef struct {
    u8  used;   // used flag
    u8  unk1;   // not quite a counter, what?
    s16 x;      // x
    s16 y;      // y
    s16 z;      // z
    s16 unk8;
    s16 unkA;
    s16 unkC;   // size?
    s16 unkE;
    s16 unk10;  // animal class maybe? relates to damage done on collision
    u8  pad12[0x2];
    s32 unk14;
} struct085; // size 0x18

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} struct088; // size 0x18

typedef struct {
    /* 0x0 */ u16 class;    // unk9E
    /* 0x2 */ u16 waterClass;     // unkA0
    /* 0x4 */ u16 canJump;     // unkA2
    /* 0x6 */ u16 unk6;     // unkBE, unk72, unk74
    /* 0x8 */ u16 unk8;     // mass
    /* 0xA */ u8  unkA;     // armour
    /* 0xB */ u8  unkB;     // unk8C
    /* 0xC */ u16 unkC;     // unkA4
    /* 0xE */ u16 unkE;     // unkA6
    /* 0x10 */ u16 unk10;   // unkA8
    /* 0x12 */ u16 unk12;   // unkAA
    /* 0x14 */ u16 unk14;   // unkAC
    /* 0x16 */ s16 unk16;   // fallDistance
    /* 0x18 */ s16 unk18;   // unkB0
    /* 0x1A */ u16 unk1A;   // traction
    /* 0x1C */ u16 unk1C;   // unkB4
    /* 0x1E */ u16 unk1E;   // unkB6
    /* 0x20 */ u16 unk20;   // unkB8
    /* 0x22 */ u16 unk22;   // unkBA, unk7A
    /* 0x24 */ u16 unk24;   // unkBC
    /* 0x26 */ s16 unk26;   // unkC0
    /* 0x28 */ s16 unk28;   // unkC2
    /* 0x2A */ s16 unk2A;   // unkC4
    /* 0x2C */ s8  unk2C;   // unkE6
    /* 0x2D */ s8  unk2D;   // unkE7
    /* 0x2E */ s16 unk2E;   // unkC6
    /* 0x30 */ s16 unk30;   // unkC8
    /* 0x32 */ s16 unk32;   // unkCA
    /* 0x34 */ s16 unk34;   // unkCC
    /* 0x36 */ s16 unk36;   // unkCE
    /* 0x38 */ s16 unk38;   // unkD0
    /* 0x3A */ s16 unk3A;   // unkD2
    /* 0x3C */ s16 unk3C;   // unkE8
    /* 0x3E */ s16 unk3E;   // unkD4
    /* 0x40 */ s16 unk40;   // biome
    /* 0x42 */ s16 unk42[2][3];
    /* 0x4E */ s8  unk4E;   //
    /* 0x4F */ s8  unk4F;   // unkE9
    /* 0x50 */ s8  unk50;   // unkEA
    /* 0x51 */ s8  unk51;   // unkEB
} struct089; // size 0x52

// level data

// case 0: // object
typedef struct {
    /* 0x0 */ u16 id;
    /* 0x2 */ s16 x;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 y;
    /* 0x8 */ s16 zRotation;
    /* 0xA */ s16 angle;
    /* 0xC */ u16 unkC;
    /* 0xE */ u16 scale;
    /* 0x10 */ u16 commandReferenceIdx;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u8  commandsLength;
    /* 0x15 */ u8  unk15;
} struct090; // size 0x16

// case 1:
typedef struct {
    /* 0x0 */ u16 id;
    /* 0x2 */ s16 x;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 y;
    /* 0x8 */ s16 rotation;
    /* 0xA */ s16 health;
    /* 0xC */ u16 unkC;
    /* 0xE */ u16 unkE;
} struct091; // size 0x10

// case 2:
typedef struct {
    u16 parent;
    u16 child;
    u16 referenceIdx; // referenceIdx
} struct092; // size 0x6

// case 7:
typedef struct {
    /* 0x0 */ u16 unk0;
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
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
} struct097; // size 0x1A

typedef struct {
    f32 unk0;
    s16 id;
} struct098; // size 0x8

typedef struct {
    /* 0x0  */ u16 unk0; // particle type (flags)
    /* 0x2  */ u8  unk2; // defaultSize
    /* 0x3  */ u8  pad3;
    /* 0x4  */ s16 unk4;
    /* 0x6  */ u8  unk6;
    /* 0x7  */ u8  pad7[0x4];
    /* 0xB  */ u8  unkB;
    /* 0xC  */ u8  unkC;
    /* 0xD  */ u8  unkD;
    /* 0xE  */ u16 unkE;  // defaultPrimaryColor
    /* 0x10 */ u16 unk10; // defaultEnvColor
    /* 0x12 */ u8  unk12[0x6];
} struct099; // particle, size 0x18?

typedef struct {
  u16  flags;  // flags
  u8   unk2;  // texture index?
  u8   unk3;  // probably not tris..
} struct102_inner; // size 0x4

typedef struct {
    s16 tc0; // tc0
    s16 tc1; // tc1
    u8  unk4; // cn[0] / r
    u8  unk5; // cn[1] / g
    u8  unk6; // cn[2] / b
    s8  unk7; // x
    s16 unk8; // y
    s8  unkA; // z
    u8  unkB; // cn[3] / a
} struct102_payload; // size 0xC

typedef struct {
  /* 0x00 */ struct102_inner unk0;
  /* 0x04 */ struct102_payload unk4[4];
} struct102; // size 0x34?

typedef struct {
    /* 0x0  */ s16 idx;
    /* 0x2  */ s16 unused; // doesnt really force alignment..
    /* 0x4  */ s16 v[4];
    /* 0xC  */ s16 flags[4]; // has texture?
    /* 0x14 */ u8  pad14[0x10];
} struct115; // size 0x24 ?

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 transitionId;
    s16 unk6;
    s16 overlayTV;
} ScreenTransition; // size 0xA

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    s8 unk7;
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
    /* 0x0     */ ObjectData *unk0;
    /* 0x4     */ Entity  objects[170]; // 0x270 each
    /* 0x19E64 */ Entity *objectsPtr[170];
    /* 0x1A10C */ s16 total; // total objects
    /* 0x1A10E */ s16 pad1A10E;
    /* 0x1A110 */ s16 unk1A110; // current object?
    /* 0x1A112 */ s16 unk1A112; // current object2?
    /* 0x1A114 */ s16 used;
} Objects; // 0x1A118 big

typedef struct {
    u16 button;
    s8  stick_x;
    s8  stick_y;
    s16 count;
} DemoInput;

typedef struct {
    s32 unk0;
    s32 unk4;
} struct116; // size 0x8

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} struct118; // size 0xC

typedef struct {
    /* 0x0 */ s16 rotZ;
    /* 0x2 */ s16 rotY;
    /* 0x4 */ s16 rotX;
    /* 0x6 */ s16 posX;
    /* 0x8 */ s16 posZ;
    /* 0xA */ s16 posY;
    /* 0xC */ u16 duration;
} RigKeyframe; // size 0xE

typedef struct {
    RigKeyframe *keyframes;
    s16 keyframeCount;
} BoneTrack; // size 0x6 ?

typedef struct {
    s16 trackCount;
    BoneTrack boneTrack[];
} RigAnimation;

#endif
