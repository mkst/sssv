#ifndef VARIABLES_US_H
#define VARIABLES_US_H

#include "PR/sched.h"

// Overlay 1
// .text : 0x80294E50 -> 0x80299730
// .data : 0x80299730 -> 0x80302E60
// .bss  : 0x80302E60 -> 0x803B05A0

// Overlay 2
// .text : 0x80294E50 -> 0x803A04E0
// .data : 0x803A04E0 -> 0x803C0420
// .bss  : 0x803C0420 -> 0x803FDEC0

// 0x2CB38 in ROM maps to sAtanDegreesQ6Table

// display lists
extern Gfx  D_01003460_3CD30[];
extern Gfx  D_01003498_3CD68[];
extern Gfx  D_010034C0_3CD90[];
extern Gfx  D_01003548_3CE18[];
extern Gfx  D_01003618_3CEE8[];
extern Gfx  D_010037F0_3D0C0[];
extern Gfx  D_01003998_3D268[];
extern Gfx  D_01003A58_3D328[];
extern Gfx  D_01003B70_3D440[];
extern Gfx  D_01004270_3DB40[];
extern Gfx  D_01004308_3DBD8[];
extern Gfx  D_01004360_3DC30[];
extern Gfx  D_010043A0_3DC70[];
extern Gfx  D_01004458_3DD28[];
extern Gfx  D_01004510_3DDE0[];
extern Gfx  D_01004600_3DED0[];
extern Gfx  D_01004680_3DF50[];
extern Gfx  D_010047D0_3E0A0[];
extern Gfx  D_01004970_3E240[];
extern Gfx  D_010049A0_3E270[];
extern Gfx  D_01004AF8_3E3C8[];
extern Gfx  D_01004B98_3E468[];
extern Gfx  D_0100C120_459F0[];
extern Gfx  D_01011AB0_4B380[];
extern Gfx  D_01013370_4CC40[];
extern Gfx  D_01017AA0_51370[];
extern Gfx  D_0101B000_548D0[];

extern Gfx  D_01037700_70FD0[];
extern Gfx  D_01037950_71220[];
extern Gfx  D_01037998_71268[];
extern Gfx  D_010379D8_712A8[];
extern Gfx  D_01037A00_712D0[];
extern Gfx  D_0103B6F0_74FC0[];
extern Gfx  D_0103B880_75150[];
extern Gfx  D_04000840_DDE00[];
extern Gfx  D_04000900_DDEC0[];
extern Gfx  D_04000AE0_DE0A0[];
extern Gfx  D_04000B40_DE100[];
extern Gfx  D_040005A0_DDB60[];
extern Gfx  D_04002630_DFBF0[]; // polar bear
extern Gfx  D_04002930_DFEF0[]; // polar bear
extern Gfx  D_040000E0_DD6A0[];
extern Gfx  D_040002D0_DD890[];
extern Gfx  D_04007500_E4AC0[];
extern Gfx  D_04000230_E77E0[];
extern Gfx  D_04000370_E7920[];
extern Gfx  D_040004B0_E7A60[];
extern Gfx  D_04000600_E7BB0[];
extern Gfx  D_040009D0_E7F80[];
extern Gfx  D_04000DB0_E8360[];
extern Gfx  D_04000DD0_E8380[];
extern Gfx  D_04000600_F1660[];
extern Gfx  D_04000230_F1290[];

extern Gfx  D_04005B60_11C730[]; // spaceship interior
extern Gfx  D_04006D00_11D8D0[]; // tv body

extern Gfx D_04003580_EAB30[];
extern Gfx D_04003640_EABF0[];
extern Gfx D_040036D0_EAC80[];
extern Gfx D_04003930_E0EF0[];
extern Gfx D_040039C0_E0F80[];
extern Gfx D_04005F70_ED520[];
extern Gfx D_04006050_ED600[];
extern Gfx D_04006C00_CE630[];
extern Gfx D_04006200_F7260[];
extern Gfx D_040062C0_F7320[];
extern Gfx D_04000E70_F1ED0[]; // to double-check
extern Gfx D_04000EF0_F1F50[]; // to double-check

extern Gfx  D_01003840_3D110[];

extern Gfx  D_040077E0_E4DA0[];
extern Gfx  D_04007AE0_E50A0[];
extern Gfx  D_04007E70_E5430[];
extern Gfx  D_04007E90_E5450[];
extern Gfx  D_040088F0_F9950[];
extern Gfx  D_0400A9E0_1215B0[];
extern Gfx  D_0400BD00_FCD60[];
extern Gfx  D_0400C260_FD2C0[];
extern Gfx  D_0400C010_FD070[];
extern Gfx  D_0400C170_FD1D0[];
extern Gfx  D_0400C240_FD2A0[];

extern Gfx  D_05006170_9D190[];

// 0x8000xxxx

extern u8   gFramebuffer[2][320 * 240 * 2]; // 0x25C00

// 0x800Bxxxx

extern u8   gfxspecific[];

extern u8   D_800B49A0[8000]; // level thumbnail img
extern u8   D_800B68E0[16000]; // trophy img
extern u8   D_800BA760[];

#define D_800BDC80 (D_800BA760 + 4000 + (8 * 1200))

extern u8   gWaterTextureBuffer[2000];
extern u8   D_800DD3F0[4000];
extern u8   D_800DE390[2704];
extern u64  D_800DEE20[0x80]; // dram stack
extern Star D_800DF220[1024]; // could just be [x][4] s16 array

// 0x800Exxxx

#define GFX_RDP_OUTPUT_SIZE 0x2000
extern u64 D_800EF0D0[GFX_RDP_OUTPUT_SIZE];

// 0x800Fxxxx

// 0x8010xxxx

extern u32  D_80100000[];

// 0x8012xxxx

// 0x8013xxxx

// 0x8014xxxx

// 0x8015xxxx

// controller.h
extern u16  gSeed;
extern s16  gAsinDegreesQ8Table[];

// mtx.h
extern s16  gSineTable[1170];
extern s16  gSineTable256[256];

// thread6
extern s8   D_80152E90; // 0x2E590
extern u8   D_80152E98;
extern Vp   gMainViewport;
extern u16  D_80152EB8; // frame buffer id?

// overlay1_6384F0
extern Gfx  D_801542D0[]; // 0x2F9D0

// audiomgr.c
// core/audio.c .data
extern s16  gMusicVolumeScale; // used in lots of places
extern s16  D_801546E0;
extern s32  D_80155160;
extern s8   D_80155164[];
extern s8   D_80155168[]; // is this u8?
extern s8   D_80155170;
extern s8   D_80155174;
extern f32  gMusicSpeakerVolumeScale;
extern u8   gMusicChannel1NoteOn;
extern u8   gMusicChannels3PlusNoteOn;

// overlay1_6384F0
extern Gfx  D_801582C0[];
extern Gfx  gOpaqueLit3DRenderSetupDl[];
extern Gfx  D_801584A0[];

// 0x8016xxxx

extern OSSched sc; // D_801603D0;
extern FrameContext gFrameContext[2];

// 0x801Dxxxx
extern u8  *gEuropeSegmentBase;
extern u8  *gCitySegmentBase;
extern u8  *gIceSegmentBase;
extern u8  *gDesertSegmentBase;
extern u8  *gJungleSegmentBase;
extern u8  *gMenuSegmentBase;

extern s16 *gFontSegmentBase;
extern u8  *gSegment1Base;
extern u8  *gSegment5Base;
extern Gfx *gMainDL;

extern Gfx *gOpaqueDL;
extern Gfx *gXluDL;
extern Gfx *gLayer0DL;
extern Gfx *gLayer1DL;
extern Gfx *D_801D9E98[8];
extern Gfx *gAuxDL;
extern u8  *D_801D9EC4; // currently loaded segment
extern s32  D_801D9ED0;
extern s16  D_801D9ED4; // either 10 or 6 - input debounce?
extern struct050 gAnimalState;

extern s16  gScreenWidth;
extern s16  gScreenHeight;

extern Objects D_801E9EB8;  // gObjects

extern LimbConfig D_80203FE0[34];
extern LimbConfig D_802040F0[34];

// is this a Mtx?
extern f32  D_80204200;
extern f32  D_80204204;
extern f32  D_80204208;
extern f32  D_8020420C;
extern f32  D_80204210;
extern f32  D_80204214;
extern f32  D_80204218;
extern f32  D_8020421C;
extern f32  D_80204220;
extern s16  D_80204224;
extern s16  D_80204226;
extern s16  D_80204228;
extern f32  D_8020422C;
extern f32  D_80204230;
extern f32  D_80204234;

extern RomHeader D_80204240;
extern s16  D_80204270;
extern FrameContext *gFrameContextPtr;
extern DisplayList *gDisplayListContext;
extern s16  D_8020427C;
extern s16  D_80204280;
extern s16  gOverlayState;
extern s8   gAttractModeState;
extern FrameContext *D_8020428C;
extern s16  gFrameStepDivisor;
extern s16  gRefreshRate;
extern char gDebugTextBuffer[60];
extern s16  gNoControllerMessageText[];
extern s16  D_80204368[];
extern u64  D_802043E0[]; // yield_data_ptr

extern VIData gVIData;
extern VIData D_802053F0;
extern VIData D_80205400;
extern s16  gIsWidescreen;

extern Gfx  *gWorldCellOpaqueDisplayLists[4][6];
extern Gfx   D_80205470[6000];

extern Vtx   gOpaqueVtxPool[5000];

extern Vtx   D_80224870[216];
extern Gfx  *gWorldCellTranslucentDisplayLists[4][6];
extern Gfx   D_80225650[2000];
extern Vtx   gTranslucentVtxPool[1000];
extern Vtx   D_8022D350[216];

// src.us/main_78F0.c

// 0x8023xxxx

extern LanguageData D_8022E3F0;

// extern LevelText D_80231D50;

extern s16  D_8023F208[32];

extern PlayerEeprom gPlayerEeprom;
extern Eeprom gEepromGlobal;
extern PlayerEeprom gPlayerEepromSlots[4];

// audiomgr
extern ALHeap D_80286328;
extern ALSeqPlayer *D_802863C8[1];
extern ALCSeq *D_802863CC[1];
extern u8   D_80286458;
extern s16  gSpeakerUpdatesThisFrame;
extern s16  gCurrentMusicTrack;

// csplayer
extern s16  gMusicBeatPhase;
extern s16  gPreviousMusicBeatPhase;

// thread1
extern OSThread    gThread7; // 0x80286720
extern OSThread    gThread9; // 0x80286A80
extern u64         thread9_stack[512];

extern OSMesgQueue D_8028D048;
extern OSMesgQueue D_8028D060;
extern OSMesgQueue D_8028D078;
extern OSMesgQueue gSiLockQueue;
extern OSMesgQueue gSiEventQueue;
extern OSIoMesg    D_8028D0C0;

// 0x8029xxxx

extern OSMesg D_802902C0[800];
extern OSMesg D_80290F40[34]; // 32 + spare padding?
extern OSMesg D_80290FC8[32];
extern OSMesg gSiLockQueueBuffer[1];
extern OSMesg gSiEventQueueBuffer[1];
extern OSMesg *D_80291054;
extern OSMesg D_80291058[1];
extern OSMesg D_8029105C[1];
extern OSMesgQueue D_80291060;
extern OSMesgQueue D_80291078;

// TODO: thread9 bss

extern Controller gRumbleState;
extern OSContPad *gControllerInput;
extern OSContPad gControllerPads[MAXCONTROLLERS]; // 4?

// thread9 bss

extern s32  D_802912D0;
extern s32  gEepromType;
extern s16  gControllerConnected;
extern u8   gPrevStartButtonUp; // 1 when up in the previous sample
extern u8   gPrevAButtonUp; // 1 when up in the previous sample
extern u8   gPrevBButtonUp; // 1 when up in the previous sample
extern u8   gPrevDpadUpButtonUp; // 1 when up in the previous sample
extern u8   gPrevDpadDownButtonUp; // 1 when up in the previous sample
extern u8   gPrevDpadLeftButtonUp; // 1 when up in the previous sample
extern u8   gPrevDpadRightButtonUp; // 1 when up in the previous sample

// BSS (overlay1)

extern s32  gGravity;
extern s32  D_803A05B4_7B1C64;
extern struct089 D_803A05D0_7B1C80[68];

extern struct118 D_803A3990_7B5040[];
extern struct118 D_803A39C0_7B5070[];
extern struct118 D_803A39FC_7B50AC[];
extern struct118 D_803A3A38_7B50E8[];
extern struct118 D_803A3A74_7B5124[];
extern struct118 D_803A3AC8_7B5178[];
extern struct118 D_803A3B1C_7B51CC[];
extern struct118 D_803A3B4C_7B51FC[];
extern struct118 D_803A3BAC_7B525C[];
extern struct118 D_803A3C0C_7B52BC[];
extern struct118 D_803A3C3C_7B52EC[];
extern struct118 D_803A3C9C_7B534C[16];
extern struct118 D_803A3D5C_7B540C[16];
extern struct118 D_803A3E1C_7B54CC[16];
extern struct118 D_803A3EDC_7B558C[16];
extern struct118 D_803A3F9C_7B564C[16];
extern struct118 D_803A411C_7B57CC[];
extern struct118 D_803A41DC_7B588C[];
extern struct118 D_803A429C_7B594C[];
extern struct118 D_803A435C_7B5A0C[];
extern struct118 D_803A4398_7B5A48[];
extern struct118 D_803A43D4_7B5A84[];
extern struct118 D_803A4410_7B5AC0[];
extern struct118 D_803A444C_7B5AFC[];
extern struct118 D_803A4488_7B5B38[];

extern u16  gWaypointPathCount; // number of waypoints?
extern u16  D_803A5760_7B6E10;

extern u8   gLevelLightTransitionComplete; // lights.c

extern struct082 D_803A63B0_7B7A60[]; // animals?
extern s16  D_803A65D0_7B7C80[];
extern s16  D_803A6680_7B7D30[];

extern s16  D_803A8340_7B99F0;
extern u8  *D_803A8370_7B9A20[];

extern ObjectData D_803A8528_7B9BD8[247]; // 0x9C each
extern u16  D_803A4638_7B5CE8[];

// 0x803Bxxxx
extern u16 D_803B1BAC_7C325C[];
extern u8  D_803B1D20_7C33D0[];

extern DemoInput D_803B1F20_7C35D0[];
extern DemoInput D_803B2580_7C3C30[];
extern DemoInput D_803B29D8_7C4088[];
extern DemoInput D_803B30D0_7C4780[];
extern DemoInput D_803B3388_7C4A38[];
extern DemoInput D_803B384C_7C4EFC[];

extern u8   D_803B5498_7C6B48[];
extern u8   D_803B54A0_7C6B50[];
extern s16  D_803B54A8_7C6B58[];
extern s32  D_803B5764_7C6E14[];

extern struct107 D_803B58E0_7C6F90[];

extern Lights1 D_803B65A8_7C7C58;
extern Lights1 D_803B65D8_7C7C88;
extern Lights1 D_803B65F0_7C7CA0;

extern Gfx D_0103BA70_75340[];
extern Gfx D_0103EC20_784F0[];

// overlay2_7A0DA0
extern Vp  D_803B66F0_7C7DA0;

// rodata starts at 0x803BACD0

extern const LeftEyes  D_803BD530_7CEBE0;
extern const RightEyes D_803BD600_7CECB0;

// overlay2_6A6500
extern s16  D_803C0420; // first var in BSS
extern u8   gInitialisationState;
extern s16  D_803C0424;
extern s16  D_803C0426;
extern s16  D_803C0428;
extern struct053 gWaterAnimState;

extern s64  gRenderMode1;
extern s64  gRenderMode2;
extern s64  gGeometryMode;
extern u16  gWorldPerspNorm; // matrix normalise

// sssv/terrain_map.c
extern struct063 D_803C0740[72+1][128+1]; // 129 but data is [65][97]

// sssv/teleporters.c
extern struct054 D_803D2D90;

// overlay2_6AE5A0
extern DynamicTextures gDynamicTextureBillboardQueue;
extern DisplayList* D_803D3434;

// overlay2_6B5380
extern s16  D_803D5510;
extern s16  D_803D5512;
extern Animal2 *D_803D5520;
extern struct035 *D_803D5524;
extern Animal *D_803D5528; // Animal
extern Animal *D_803D552C; // Animal
extern Entity *D_803D5530; // Entity
extern s16  gCurrentAnimalIndex;
extern s16  D_803D5536; // tmp animal idx?
extern u8   D_803D5538;
extern s16  D_803D553A;
extern s16  D_803D553C;
extern s16  gNumAnimalsInLevel;
extern s16  D_803D5540; // timer
extern s16  D_803D5542; // timer
extern u16  gGameplayTick; // timer (for attacks? everything?) gCurrentTick
extern s16  D_803D5546;
extern s16  D_803D5548;
extern s8   D_803D554A;
extern s8   D_803D554B;
extern s8   D_803D554C;
extern s16  D_803D5558;

// sssv/player_input.c
extern s16  gControllerDebounce;

// collist2
extern CollisionNode gCollisionGridHeads[40];

// dynamic_tail
extern struct088 D_803DA300[1000];
extern DynamicTail D_803E00C0[120];
extern s16  D_803E1B02; // another counter, max 120
extern s16  D_803E1B04; // used vtx for dynamic tails?

// screen_transition
extern ScreenTransition gScreenTransition;

// lights
extern u8   gWaterPrimRed; // water prim r
extern u8   gWaterPrimGreen; // water prim g
extern u8   gWaterPrimBlue; // water prim b
extern u8   gWaterEnvRed; // water env r
extern u8   gWaterEnvGreen; // water env g
extern u8   gWaterEnvBlue; // water env b

// input
extern s16  gInputMode;

// overlay2_707310
extern Fog  gFogState;
extern struct064 D_803E1D30[]; // additional layer for level data

extern struct116 D_803E2930[];

// overlay2_715820
extern struct073 D_803E3130[];
extern u8   D_803E4930[];
extern u8   D_803E4998[];
extern u16  D_803E4A00[];
extern s16  D_803E4AC8;
extern s8   D_803E4AD0[];

// overlay2_716900
extern struct079 D_803E4BE0;

// overlay2_725D10
extern s32  gLevelProgress;
extern s32  gTasksCompleted;
extern s32  D_803E4D30;
extern CmdWrapper D_803E4D40[1666]; // BIG_DAY_PARADE is 1666 commands long
extern u16  D_803E8E54;
extern u8   gSpeakerDistanceAttenuationEnabled;

// overlay2_72B100
extern WaypointData *gWaypointPaths[64];
extern u8   gWaypointPathBuffer[1100];
extern LevelRegion gLevelRegions[65];
extern s64  gLevelRegionCollisionMasks[65];

// overlay2_72BA20
extern s16  D_803E97C0;

// overlay2_739290
extern s16  D_803E9820;
extern s16  D_803E9822;
extern s16  gCurrentAnimalId;
extern Collision D_803E9840[];

// 0x803Fxxxx

// TODO:
extern s16  D_803F28C2;

// camera
extern u16  gCameraVisibilityMask[8];

extern Camera gCameras[2];
extern s16  gCameraId;
extern s16  D_803F2A9A;
extern s16  D_803F2A9C;
extern s16  D_803F2A9E;
extern u8   gCameraUiState;
extern u8   D_803F2AA3;
extern u8   D_803F2AA4; // toggle/boolean, cutscene? who knows

extern s16  D_803F2C18[3];
extern s16  D_803F2C28;
extern f32  D_803F2C3C;

extern f32  D_803F2C40;

extern f32  gCameraEyeWorldX;
extern f32  gCameraEyeWorldZ;
extern f32  gCameraEyeWorldY;

extern f32  D_803F2C5C;
extern f32  D_803F2C60;
extern u8   D_803F2C6C;

// osd
extern s16  D_803F2CD0;
extern s16  gHudTimerSeconds; // (race?) timer
extern s16  gHudTimerTickCounter;
extern s16  gHudTimerStepSeconds;
extern s16  gHudTimerTicksPerStep;
extern s8   D_803F2CDC;

extern s16 *gHudCenterText; // pointer to some text
extern s16  D_803F2CE4; // vertical offset for osd text?
extern u8   D_803F2CE6; // has (death?) sfx been played?
extern s16  gHudDisplayedPlayerHealth; // health slider 'animation'

// init.c
extern UiFlowState gUiFlowState;
extern s16  D_803F2D18;

// overlay2_7558F0
extern s16  D_803F2CA6;
extern s8   gWorldCellTranslucentEnabled[4][6];

// sssv/music_control.c
extern s16  D_803F2D24;

// sssv/level_results.c
extern GameState gGameState;
extern LevelConfig D_803F2D50;

// overlay2_76E7D0
extern s32  D_803F2EB0; // breathing related?
extern s32  D_803F2EB4; // breathing related?
extern s32  D_803F2EB8; // breathing related?
extern s32  D_803F2EBC;
extern s32  D_803F2EC0;
extern s32  D_803F2EC4;
extern s32  D_803F2EC8;
extern u16  D_803F2ECC;
extern u16  gAnimBlendMode;
extern s16  D_803F2ED0;
extern s16  D_803F2ED2;
extern s32  D_803F2ED4;
extern s16  D_803F2ED8;
extern u8   D_803F2EDA;
extern u8   D_803F2EDB;
extern u8   gLodDetailState;
extern u8   D_803F2EDE;

// overlay2_785D10
extern s16  D_803F2F00; // only used by husky/polar bear? snow footprints?

// scorpion
extern s16  gScorpionVtxIdx;

extern u16  D_803F3330[]; // message lookup?
extern s16  D_803F34C0[]; // message lookup 2?
extern s16  gLoadedMessageCount;
extern u8   D_803F63C2;

// overlay2_791CD0
extern s16  D_803F63E0;

// cheats
extern Cheats  gCheats;

// overlay2_79DE10
extern s16  gAnimalBehaviourEnabled;

// terminal_background
extern Animal *D_803F6464;
extern s16  D_803F6468;

// overlay2_7A0DA0
extern OverlayMenuState gOverlayMenuState;
extern s16  D_803F6704;
extern u16  D_803F6714;
extern s16  D_803F6716; // current sfx volume
extern s16  D_803F6718; // current music volume
extern s16  D_803F671A; // current language
extern s16  D_803F671C;

// overlay2_7A8A50
extern u16  D_803F713C[];

// ui_main_menu
extern struct030 D_803F7DA8;

#endif
