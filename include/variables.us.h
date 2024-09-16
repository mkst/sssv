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

// 0x2CB38 in ROM maps to D_80151438

// display lists
extern u8   D_000398D0[];
extern u8   D_0007F790[];

extern u8   D_005449C0[];
extern u8   D_00546BC0[];

extern u8   D_01000620_39EF0[];
extern u8   D_01000CA0_3A570[];
extern u8   D_01000CC0_3A590[];
extern u8   D_01000D00_3A5D0[];
extern u8   D_01000D20_3A5F0[];
extern u8   D_01002100_3B9D0[];
extern u8   D_010025A0_3BE70[];
extern u8   D_01002C20_3C4F0[];
extern u8   D_01002C40_3C510[];

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

extern u8   D_01021BB0_5B480[];
extern u8   D_01029E10_636E0[];
extern u8   D_0102A210_63AE0[];
extern u8   D_0102C810_660E0[];
extern u8   D_0102D810[];
extern u8   D_0102F010_688E0[]; // [64][2048]; ?
extern u8   D_0102B610[];
extern u8   D_0102B810[];
extern u8   D_0102BA10_652E0[];
extern u8   D_01030810_6A0E0[];
extern u8   D_01033190_6CA60[]; // D_01033190_6CA60?
extern u8   D_01035190_6EA60[];
extern u8   D_01035990_6F260[];
extern u8   D_01036190_6FA60[];
extern Gfx  D_01037700_70FD0[];
extern u8   D_01037750_71020[];
extern Gfx  D_01037950_71220[];
extern Gfx  D_01037998_71268[];
extern Gfx  D_010379D8_712A8[];
extern Gfx  D_01037A00_712D0[];
extern Gfx  D_01037A20_712F0[];
extern u8   D_0103AC40_74510[];
extern u8   D_0103B440_74D10[];
extern Gfx  D_0103B6F0_74FC0[];
extern Gfx  D_0103B880_75150[];
extern Gfx  D_0103BA70[];
extern Gfx  D_0103EC20[];
extern u8   D_0103ECB0_78580[];
extern u8   D_01040CB0_7A580[];
extern u8   D_04000000_116BD0[]; // powercell
extern u8   D_040000A0[];
extern Gfx  D_040000E0_DD6A0[];
extern Gfx  D_04000230_E77E0[];
extern Gfx  D_040002D0_DD890[];
extern u8   D_04000370_E7920[];
extern u8   D_040004B0_E7A60[];
extern Gfx  D_04000600_E7BB0[];
extern Gfx  D_04000600_F1660[];
extern Gfx  D_04000230_F1290[];
extern u8   D_040006F0[];
extern Gfx  D_04000840_DDE00[];
extern Gfx  D_04000900_DDEC0[];
extern Gfx  D_040009D0_E7F80[];
extern Gfx  D_04000AE0_DE0A0[];
extern u8   D_04000B10_E80C0[];
extern Gfx  D_04000B40_DE100[];
extern u8   D_04000D10_E82C0[];
extern Gfx  D_04000DB0_E8360[];
extern u8   D_04000DD0_E8380[];
extern Gfx  D_040005A0_DDB60[];
extern Gfx  D_04002630_DFBF0[]; // polar bear
extern Gfx  D_04002930_DFEF0[]; // polar bear
extern u8   D_040029D0[];
extern u8   D_04002F28[];

extern u8   D_04005B60_11C730[]; // spaceship interior
extern u8   D_04006D00_11D8D0[]; // tv body
extern u8   D_04006EC0_11DA90[]; // sssv 43x43
extern Gfx  D_04007500_E4AC0[];

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

// mouse
extern Gfx  D_04005480_1051D0[];
extern Gfx  D_040053D0_105120[];
extern Gfx  D_04005A50_1057A0[];
extern Gfx  D_04005CA0_1059F0[];
extern Gfx  D_04006040_105D90[];
extern Gfx  D_04006B00_106850[];
extern Gfx  D_04006B60_1068B0[];

extern Gfx  D_01003840_3D110[];

extern Gfx  D_040077E0_E4DA0[];
extern u8   D_04007BD0_E5190[];
extern u8   D_04007700_11E2D0[];
extern u8   D_040077A0_11E370[];
extern u8   D_040078C0[];
extern u8   D_040079F0[];
extern Gfx  D_04007AE0_E50A0[];
extern u8   D_04007B40[];
extern u8   D_04007C60[];
extern u8   D_04007D90[];
extern u8   D_04007DD0_E5390[];
extern u8   D_04007E70_E5430[];
extern u8   D_04007E90_E5450[];
extern u8   D_04007EC0[];
extern u8   D_04007FA0_11EB70[];
extern u8   D_04008290_107FE0[];
extern u8   D_04008420_108170[];
extern u8   D_040088F0_F9950[];
extern u8   D_040089E0_108730[];
extern u8   D_04008A10_108760[];
extern u8   D_04008C10_108960[];
extern u8   D_0400A9E0_1215B0[];
extern Gfx  D_0400BD00_FCD60[];
extern Gfx  D_0400C260_FD2C0[];
extern u8   D_0400C280_FD2E0[];
extern u8   D_0400C480[];
extern u8   D_0400C6A0_FD700[];
extern u8   D_0400C6C0_FD720[];
extern u8   D_0400C8C0_FD920[];
extern Gfx  D_0400C010_FD070[];
extern Gfx  D_0400C170_FD1D0[];
extern Gfx  D_0400C240_FD2A0[];

extern u8   D_04012B20_1296F0[];
extern u8   D_04013060_129C30[];
extern u8   D_040131B0_129D80[];
extern u8   D_040133C0_129F90[];
extern u8   D_04013580_12A150[];
extern u8   D_04003E70_F4ED0[];
extern u8   D_04004070_F50D0[];

extern Gfx  D_05006170[];

// 0x8000xxxx

extern s32  D_80000300;
extern s16  D_80000302;
extern u8   gFramebuffer[][320 * 240 * 2]; // 0x25C00

// 0x8003xxxx

extern s32  D_80032870;

// 0x8004xxxx

extern u8   D_8004B400[]; // _gfxdlistSegmentStart

// 0x8009xxxx

extern u8   D_80099600[]; // _gfxdlistSegmentEnd

// 0x800Bxxxx

extern u8 D_800B0B20[];
extern u8 D_800B49A0[]; // level thumbnail img
extern u8 D_800B68E0[]; // trophy img
extern struct038 D_800BB210[];
extern u8 D_800BB700[];
extern u8 D_800BBBB0[];
extern u8 D_800BC060[];
extern u8 D_800BC510[];
extern u8 D_800BC9C0[];
extern u8 D_800BCE70[];
extern u8 D_800BD320[];
extern u8 D_800BD7D0[];
extern u8 D_800BDC80[];
extern u8 D_800DD3F0[];
extern u8 D_800DE390[];
// are different values loaded into this area?
extern u8 D_800BA760[20][0xAB8]; // 2744 bytes per texture, initially contains rnc_42DCA0 compressed texture

// 0x800Cxxxx

extern u8   D_800C3A40[];
extern u8   D_800C4240[];
extern u8   D_800C4A40[];
extern u8   D_800C5240[];
extern u8   D_800C5A40[]; // current frame?
extern u8   D_800C7DC0[]; // level ia16 textures
extern u8   D_800CFE60[]; // biome ia16 textures
extern u8   D_800D5420[]; // level textures
extern u8   D_800D7C20[]; // biome textures

// 0x800Dxxxx

extern u8   D_800DCC20[][512]; // water texture location?
extern u64  D_800DEE20[0x80]; // dram stack
extern Star D_800DF220[1024]; // could just be [x][4] s16 array

// 0x800Exxxx

extern u8  _fontbufferSegmentStart[]; // D_800E1220
extern u8  _fontbufferSegmentEnd[];   // D_800EF0D0

#define GFX_RDP_OUTPUT_SIZE 0x2000
extern u64 D_800EF0D0[GFX_RDP_OUTPUT_SIZE];

// 0x800Fxxxx

// 0x8010xxxx

extern u32  D_80100000[];

// 0x8012xxxx

// 0x8013xxxx

// 0x8014xxxx

// 0x8015xxxx

extern u16  D_80151424; // 0x2cb24 ??? in aspMainText?

extern u16  gSeed; // kinda random number?
// extern u8   D_80151438[]; // maps to ROM 0x2CB38 ?

extern f32  D_80151C38[];
extern s16  D_80152040[];
extern s16  D_80152212[];
extern s8   D_80152248[];
extern struct013 D_80152350; // likely just an s16 array
// extern s16  D_80152620[]; // these are D_80152350.unk2D0
// extern s16  D_801526D4[]; // these are D_80152350.unk384
extern s16  D_80152C78[256];

// thread6
extern u8   D_80152E90; // 0x2E590
extern u8   D_80152E98;
extern Vp   D_80152EA8;
extern u16  D_80152EB8; // frame buffer id?

// overlay1_6384F0
extern Gfx  D_801542D0[]; // 0x2F9D0

// main_78F0
extern u8   D_80154370[]; // 0x2FA70

// extern u8*  D_80154500[37][2]; // bunch of offsets to RNC language files

// audiomgr.c
extern s16  D_8015468C; // max of 21
extern u8   D_80154690[];
extern s8   D_801546A8[];
extern f32  D_801546AC[];
extern f32  D_801546B0[];
extern f32  D_801546B4[];
extern f32  D_801546B8[];
extern s8   D_801546BC;
extern f32  D_801546C0;
extern f32  D_801546C4;
extern f32  D_801546C8;
extern f32  D_801546CC;
// core/audio.c .data
extern f32  gMusicVolume;
extern f32  gSfxVolume;
extern s16  D_801546D8; // used in lots of places
extern s16  D_801546DC;
extern s16  D_801546E0;
extern s32  D_801546E4;
extern f32  D_801546E8[];
extern s32  D_80154C4C[];

extern s16  D_801550F8[];
extern s32  gAudioInitialized;
extern s32  D_8015515C;
extern s32  D_80155160;
extern s8   D_80155164[];
extern s8   D_80155168[]; // is this u8?
extern s16  D_8015516C[];
extern s8   D_80155170;
extern s8   D_80155174;
extern u8   D_80155178; // Wet/dry mix
extern f32  D_8015517C;
extern s16  D_80155180;
extern s16  D_80155184;
extern s16  D_80155188;
extern s32  D_8015518C;
extern f32  D_8015529C;
extern u16  D_801552A8;
extern u8   D_801552B0;
extern u8   D_801552B4;

// overlay1_6384F0
extern u8   D_801552C0[]; // C
extern u8   D_80155AC0[]; // H
extern u8   D_801562C0[]; // .
extern u8   D_80156AC0[]; // |
extern u8   D_801572C0[]; // 1
extern u8   D_80157AC0[]; // 0

extern Gfx  D_801582C0[];
extern Gfx  D_80158368[];
extern Gfx  D_80158420[];
extern Gfx  D_801584A0[];

// thread9
extern s16  D_80158540;
extern s32  numControllers;
extern u8   D_80158550[];
// extern OSViMode D_80159980[];

extern s32  D_8015B790; // ucode data start
extern s32  D_8015C750;
extern s32  D_8015D710; // ucode data start
extern u8   D_8015DF10[];

// 0x8016xxxx

extern OSSched sc; // D_801603D0;
extern struct018 D_80162658[2];

// 0x8019xxxx

extern struct009 D_8019A658[];
// 0d80162658 + 0x3BBF0 => 0x8019E248
extern u8 D_8019E240[2][0x3BBF0];
// 0x801Dxxxx

extern s32  D_801D9D70; // camera position? distance? angle?
extern u16  D_801D9E38;
extern u8  *D_801D9E58;
extern u8  *D_801D9E5C;
extern u8  *D_801D9E60;
extern u8  *D_801D9E64;
extern u8  *D_801D9E68;
extern u8  *D_801D9E6C;
extern s16 *D_801D9E70;
extern u8  *D_801D9E74;
extern u8  *D_801D9E78;
extern Gfx *D_801D9E7C;
extern Gfx *D_801D9E88;
extern Gfx *D_801D9E8C;
extern Gfx *D_801D9E90;
extern Gfx *D_801D9E94;
extern Gfx *D_801D9E98[8];
extern Gfx *D_801D9EB8;
extern u8  *D_801D9EC4; // currently loaded segment
extern u8   D_801D9EC8;
extern u8   D_801D9EC9;
extern s32  D_801D9ED0;
extern s16  D_801D9ED4; // either 10 or 6 - input debounce?
extern struct050 D_801D9ED8;

extern s32  D_801DD800;
extern s32  D_801DD8EC;

// D_801DDD88 is D_801D9ED8.animals
// D_801DDD8C[gCurrentAnimalIndex] is D_801D9ED8.animals[gCurrentAnimalIndex].animal

// 0x801Exxxx

// D_801E1ED7->unk7FA9 =>D_801D9ED8.unkFFA8
extern struct080 D_801E1ED8;

// all of these might be part of D_801D9ED8
extern s16  D_801E9E80; // D_801D9ED8.unkFFA8
extern u16  D_801E9E8A; // D_801D9ED8.curAButton
extern u16  D_801E9E8E; // D_801D9ED8.curBButton
extern u16  D_801E9E90; // D_801D9ED8.prevAButton
extern s16  D_801E9EA6; // D_801D9ED8.unkFFCE
extern s8   D_801E9EB0; // D_801D9ED8.stickX // controller x
extern s8   D_801E9EB1; // D_801D9ED8.stickY // controller y
extern s16  D_801E9EB2; // D_801D9ED8.unkFFDA // force? duration of controller input?
extern s16  D_801E9EB4; // D_801D9ED8.unkFFDC
extern s16  D_801E9EB6; // D_801D9ED8.unkFFDE // bear/gorilla use this

extern Objects D_801E9EB8;  // gObjects
// extern struct071 D_80203AA8[];   // D_801E9EB8.objects
// extern struct071 *D_80203D1C[];  // D_801E9EB8.objectsPtr
// extern s16  D_80203FC4;          // D_801E9EB8.total

extern s16  D_80203FD0; // gScreenWidth
extern s16  D_80203FD2; // gScreenHeight

extern struct061 D_80203FE0[34];
extern struct061 D_802040F0[34];

// extern s16 D_80203FF0;
// extern s16 D_80203FF2;
// extern s16 D_80203FF4;
// extern s16 D_80203FFA; // is D_80203FE0[3].unk2
// extern s16 D_80204002; // is D_80203FE0[4].unk2

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
extern s16  gRegion;
extern s16  D_80204270;
extern struct018 *D_80204274;
extern DisplayList *D_80204278;
extern s16  D_8020427C;
extern s16  D_80204280;
extern u16  D_80204282;
extern s16  D_80204284;
extern s8   D_80204288;
extern struct018 *D_8020428C;
extern s16  D_80204290;
extern s16  D_80204292;
extern s16  gRefreshRate;
extern OSScMsg *D_80204298; // OSMesg
extern OSScClient D_802042A0;
extern s16  D_802042A8;
extern char D_802042B0[];
extern s32  D_802042EC;
extern s16  D_802042F0[];
extern s16  D_80204368[];
extern s32  D_802043E0;
extern s16  gScreenWidth;
extern s16  gScreenHeight;

extern VIData D_802053E0;
extern VIData D_802053F0;
extern VIData D_80205400;
extern s16  D_8020540C;
extern Gfx *D_80205410[][6];

extern s32  D_80205470;

extern Vtx  D_80210FF0[];

// 0x8021xxxx
extern Vtx  D_8021A5A0[]; // level vtx?

// 0x8022xxxx

extern Vtx  D_802294D0[]; // unknown size

extern Gfx  *D_802255F0[][6]; // 2 triangles?

extern Gfx  *D_80225650;
extern Gfx  *D_80225658;

extern Vtx  D_80224870[2222]; // tbd
extern Vtx  D_8022D350[];

extern s16  D_8022E3F0[]; // scratch area for RNC decompression
extern s16  D_8022E3F2;

// 0x8023xxxx

extern u16  D_80231AA0[];
extern s16  D_80231D5C[];
extern u8   D_80235410[];
extern struct023 D_8023F1E0;
extern u8   D_8023F1F0; // r
extern u8   D_8023F1F1; // g
extern u8   D_8023F1F2; // b
extern u8   D_8023F1F3; // a
extern u8   D_8023F1F4; // 0 or 1
extern u8   D_8023F1F5; // use shadow?
extern f32  D_8023F1F8; // current font width / scale
extern f32  D_8023F1FC; // current font height / scale
extern s16  D_8023F206[];
extern s16  D_8023F208[32];
extern s16  D_8023F248[];
extern PlayerEeprom D_8023F260; // 0x40 // default user state?
extern Eeprom gEepromGlobal; // global game save state, different struct to user data?
extern PlayerEeprom D_8023F2E0[4]; // 0x100

// display
extern u16  D_8023F3E0;
// audio
extern OSThread    gAudioThread;
extern OSMesgQueue D_8023F5D8;
extern OSMesg      D_8023F5F0;
extern OSMesg      D_8023F688;
extern OSMesgQueue D_8023F670;
extern ALGlobals   D_8023F708;

extern Acmd *D_8023F410[3];
// 0x8024xxxx

extern struct021   D_80241758;
extern ALEventQueue D_80241768[];
extern ALEventQueue D_8024177C[];
extern s16  D_80241D08;
extern s16  D_80241D0A;
extern s16  D_80241D0C;
extern u16  D_80241D0E;
extern OSMesgQueue D_802423D0;
extern OSMesg      D_802423E8;
extern u8  D_80242508[278000]; // base of heap

// 0x8028xxxx

extern ALBankFile *D_802862F8;
extern ALBank *D_80286300; // --> 80257D98
extern ALBank *D_80286304;
extern ALSeqFile *D_80286308;
extern ALSeqFile *D_8028630C;
extern ALSndPlayer *D_80286310;
extern u8 *D_80286314[1];
extern s32 D_80286318;
extern struct121 D_80155190; // params data
extern ALBankFile *D_802862FC;
extern s32 D_802863D0;

extern struct017 *D_8028631C;
extern struct017 *D_80286320;
extern ALHeap D_80286328;
extern struct017 *D_80286338[20];
extern s16  D_80286388[];
extern u8   D_802863B0[]; // sndSlotState
extern ALSeqPlayer *D_802863C8[1];
extern ALCSeq *D_802863CC[1];

extern u8   D_80286458;
extern s16  D_8028645A;
extern s16  gCurrentMusicTrack; // current music track?
extern ALCSeqMarker D_80286460;

extern s16  D_8028654C;
extern f32  D_80286554;
extern s16  D_80286560;
extern s16  D_80286562;
extern f32  D_80286564;
extern f32  D_80286568;
extern OSThread gThread6; // thread ID 6
extern OSThread gThread7; // thread ID 7
extern s32  D_80288E30;
extern s32  D_8028B030;

extern OSMesgQueue D_8028D030;
extern OSMesgQueue D_8028D048;
extern OSMesgQueue D_8028D060;
extern OSMesgQueue D_8028D078;
extern OSMesgQueue D_8028D090;
extern OSMesgQueue D_8028D0A8;
extern OSIoMesg    D_8028D0C0;
extern OSThread gThread1; // thread ID 1 (idle after init)
extern OSThread gThread9; // thread ID 9
extern s32  D_8028D230;
extern s32  D_8028E230;
extern OSMesg      D_8028F640;

// 0x8029xxxx

extern OSMesg D_802902C0;
extern OSMesg D_80290F40;
extern OSMesg D_80290FC8;

extern OSMesg D_80291048;
extern OSMesg D_8029104C;
extern OSMesg *D_80291054;
extern OSMesg D_80291058;
extern OSMesg D_8029105C;
extern OSMesgQueue D_80291060;
extern OSMesgQueue D_80291078;

extern Controller D_80291090;
extern OSContPad *gControllerInput;
extern OSContStatus gControllerStatus[MAXCONTROLLERS];
extern OSContPad D_802910E8[MAXCONTROLLERS]; // 4?
extern ControllerMesg D_80291100;
extern OSPfs       D_80291110[MAXCONTROLLERS];
extern OSMesgQueue D_802912B0;
extern OSMesg      D_802912C8;
extern OSMesg      D_802912CC;
extern s32  D_802912D0;
extern s32  D_802912D4;
extern s16  gControllerConnected;
extern u16  D_802912DA;
extern s16  D_802912DC;
extern u8   D_802912DE; // start pressed
extern u8   D_802912DF; // a pressed
extern u8   D_802912E0; // b pressed
extern u8   D_802912E1; // d-up pressed
extern u8   D_802912E2; // d-down pressed
extern u8   D_802912E3; // d-left pressed
extern u8   D_802912E4; // d-right pressed
extern u8   D_802912E5; // z pressed

// BSS (overlay1)

// extern s16  D_803A05C0_7B1C70;
// extern s16  D_803A05C8_7B1C78;
extern s32  gGravity; // gravity constant?
extern s32  D_803A05B4_7B1C64;
extern struct089 D_803A05D0_7B1C80[68];
extern struct098 D_803A1BB0_7B3260[];
extern u16  D_803A20B0_7B3760[]; // colors
extern struct099 D_803A20C0_7B3770[];

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

extern struct028 D_803A50C0_7B6770;

extern s16  D_803A5560_7B6C10[4];
extern s16  D_803A5568_7B6C18[];
extern s16  D_803A5570_7B6C20[];
extern s16  D_803A5578_7B6C28[];
extern s32  D_803A5590_7B6C40[];
extern u16  D_803A5750_7B6E00; // number of waypoints?
extern u16  D_803A5760_7B6E10;
extern s16  D_803A5764_7B6E14;
// extern u8  *D_803A5BF8_7B72A8[36][2];

extern u8   D_803A52B8_7B6968; // lights.c


// extern s32  D_803A52C0_7B6970;
// extern s16  D_803A52C4_7B6974;
extern u8   D_803A52D0_7B6980;
extern s16  D_803A52D4_7B6984; // a struct in ESA?
extern s32  D_803A52E8_7B6998[];
extern s16  D_803A5330_7B69E0;
extern u8   D_803A53C4_7B6A74[];
extern u8   D_803A53CC_7B6A7C[];
extern s16  D_803A53D4_7B6A84[];
extern struct077 D_803A53E0_7B6A90;
extern struct077 D_803A53FC_7B6AAC;

extern s16  D_803A5D98_7B7448[];
extern s16  D_803A5DAC_7B745C[];
extern s16  D_803A5DC0_7B7470[];
extern s16  D_803A5DE4_7B7494[];
extern s16  D_803A5E34_7B74E4[];

extern struct082 D_803A63B0_7B7A60[]; // animals?
extern s16  D_803A6470_7B7B20[];
extern s16  D_803A6520_7B7BD0[];
extern s16  D_803A65D0_7B7C80[];
extern s16  D_803A6680_7B7D30[];
extern s16  D_803A6730_7B7DE0[];
extern s16  D_803A69F0_7B80A0[];

extern s16  D_803A8340_7B99F0;
extern u8   D_803A8344_7B99F4[]; // timer string written here
// extern s8   D_803A8350_7B9A00[];
// extern s8   D_803A8358_7B9A08[];
// extern s8   D_803A8360_7B9A10[];
extern s32  D_803A8374_7B9A24; // pointer to an image

extern ObjectData D_803A8528_7B9BD8[247]; // 0x9C each
extern u16  D_803A4638_7B5CE8[];
extern u8   D_803A47F4_7B5EA4[]; // 68 big?
extern u8   D_803A48C0_7B5F70[MAX_EUROPE_ANIMALS][MAX_EUROPE_ANIMALS]; // europe
extern u8   D_803A4ABC_7B616C[MAX_ICE_ANIMALS][MAX_ICE_ANIMALS]; // ice
extern u8   D_803A4A2C_7B60DC[MAX_JUNGLE_ANIMALS][MAX_JUNGLE_ANIMALS]; // jungle
extern u8   D_803A4B38_7B61E8[MAX_DESERT_ANIMALS][MAX_DESERT_ANIMALS]; // desert
// extern u8   D_803A4B78_7B6228[];

// 0x803Bxxxx
extern u16 D_803B1BAC_7C325C[];
extern u8  D_803B1D20_7C33D0[];

extern DemoInput D_803B1F20_7C35D0[];
extern DemoInput D_803B2580_7C3C30[];
extern DemoInput D_803B29D8_7C4088[];
extern DemoInput D_803B30D0_7C4780[];
extern DemoInput D_803B3388_7C4A38[];
extern DemoInput D_803B384C_7C4EFC[];

extern s16  D_803B4958_7C6008[];
extern s16  D_803B497C_7C602C[];
extern s16  D_803B49CC_7C607C[];
extern s16  D_803B4F30_7C65E0;
extern s16  D_803B4F34_7C65E4;
extern u8   D_803B4930_7C5FE0[];
extern u8   D_803B4944_7C5FF4[];

extern s16  D_803B52FC[];
extern u8   D_803B5498_7C6B48[];
extern u8   D_803B54A0_7C6B50[];
extern s16  D_803B54A8_7C6B58[];
extern struct076 D_803B555C_7C6C0C[];
extern struct076 D_803B5574_7C6C24[];
extern struct076 D_803B558C_7C6C3C[];
extern Gfx  D_803B5764[];
extern u8   D_803B5860_7C6F10[];
extern u8   D_803B5864_7C6F14[];
extern u8   D_803B5868_7C6F18[];
extern u8   D_803B5870_7C6F20[];
extern u8   D_803B5884_7C6F34[];

extern struct107 D_803B58E0_7C6F90[];
extern void (*D_803B5D20[])(void);
extern s16  D_803B62B0_7C7960;
extern s16  D_803B62B4_7C7964;
extern u16  D_803B62B8_7C7968;
extern s16  D_803B62BC_7C796C;
extern u8   D_803B62C0_7C7970;
extern s16  D_803B62D0_7C7980[];
extern u16  D_803B6310_7C79C0;
extern s16  D_803B6314_7C79C4;
extern u8   D_803B6318_7C79C8;
// extern u8   D_803B631C_7C79CC;

extern Lights1 D_803B65A8_7C7C58;
extern Lights1 D_803B65C0_7C7C70;
extern Lights1 D_803B65D8_7C7C88;
extern Lights1 D_803B65F0_7C7CA0;

extern Gfx D_0103BA70_75340[];
extern Gfx D_0103EC20_784F0[];

extern Vp  D_803B66F0_7C7DA0;
extern struct004 D_803B6700_7C7DB0[13]; // needs to be 13 big at least
extern struct004 D_803B683C_7C7EEC;
extern f32       D_803B6868_7C7F18;
extern f32       D_803B686C_7C7F1C;
extern s32       D_803B6880_7C7F30;

extern s16  D_803B6870_7C7F20[];

// extern s8   D_803B71D0_7C8880[][5];
extern u8  *D_803B7268_7C8918[64];
extern u8  *D_803B7368_7C8A18[64];
extern f32  D_803B7468_7C8B18;
extern f32  D_803B74AC_7C8B5C;
extern f32  D_803B74B0_7C8B60;
extern f32  D_803B74B4_7C8B64;
extern f32  D_803B74B8_7C8B68;
extern f32  D_803B74BC_7C8B6C;
extern f32  D_803B74C0_7C8B70;
extern f32  D_803B74C4_7C8B74;

// rodata starts at 0x803BACD0

extern const s16  D_803BD530_7CEBE0[];
extern const s16  D_803BD54A_7CEBFA[];
extern const s16  D_803BD564_7CEC14[];
extern const s16  D_803BD602_7CECB2[];

// extern s16  D_803BD602[];
extern s16  D_803BD61C_7CECCC[];
extern s16  D_803BD5B2_7CEC62[];
extern s16  D_803BD5B6_7CEC66[];
extern s16  D_803BD5CC_7CEC7C[];
extern s16  D_803BD66A_7CED1A[];
extern s16  D_803BD66E_7CED1E[];
extern s16  D_803BD684_7CED34[];

// overlay2_6A6500
extern s16  D_803C0420; // first var in BSS
extern u8   gInitialisationState;
extern s16  D_803C0424;
extern s16  D_803C0426;
extern s16  D_803C0428;
extern s16  D_803C042A;
extern struct053 D_803C0430;

extern u64  gRenderMode1;
extern u64  gRenderMode2;
extern u64  gGeometryMode;
extern u16  D_803C0658; // matrix normalise

extern Fog2 D_803C0660[28]; // fogPositions? or just a coincidence

// overlay2_6AC360
extern struct063 D_803C0740[72+1][128+1]; // 129 but data is [65][97]

// overlay2_6ACF20
extern struct054 D_803D2D90;
// extern f32       D_803D2DF8;
// extern s16       D_803D2DFC;
// extern s16       D_803D2DFE;
// extern s16       D_803D2E00;
extern struct059 D_803D2E08;
// extern s32        D_803D3428;
// extern s32        D_803D342C;
// extern s16        D_803D3430;
// extern s16        D_803D3432;
extern DisplayList* D_803D3434;
// extern s32       *D_803D3438;
// extern Animal    *D_803D343C;
// extern struct035 *D_803D3440;
// extern struct025  D_803D3448;
// extern struct025  D_803D3A20;
// extern struct025  D_803D3FF8;
// extern struct072  D_803D45D0;
// extern struct025  D_803D4BB0;
// extern struct057  D_803D5188[];
// extern s16  D_803D5508;

// overlay2_6B5380
extern s16  D_803D5510;
extern s16  D_803D5512;
extern Animal2 *D_803D5520;
extern struct035 *D_803D5524;
extern Animal *D_803D5528;
extern Animal *D_803D552C; // is this *really* Animal? is it World?
extern Animal *D_803D5530; // pointer to first animal?
extern s16  gCurrentAnimalIndex; // current animal (id within level)
extern s16  D_803D5536; // tmp animal idx?
extern u8   D_803D5538;
extern s16  D_803D553A;
extern s16  D_803D553C;
extern s16  D_803D553E; // number of animals in level? gNumAnimals
extern s16  D_803D5540; // timer
extern s16  D_803D5542; // timer
extern u16  D_803D5544; // timer (for attacks? everything?) gCurrentTick
extern s16  D_803D5546;
extern s16  D_803D5548;
extern s8   D_803D554A;
extern s8   D_803D554B;
extern s8   D_803D554C;
extern s16  D_803D5558;
extern u16  D_803D555A; // timer
extern u8   D_803D555C;
extern u8   D_803D555D;
extern Animal *D_803D5560;
extern s16  D_803D5564;
extern s16  D_803D5566;
extern s16  D_803D5568;
extern s16  D_803D556A;
extern s16  D_803D556C;
extern s16  D_803D556E;
extern s16  D_803D5570;
extern u16  D_803D5572;
extern s16  D_803D5574;
extern u8   D_803D5575; // controller maginitude?
// extern s16  D_803D5578;
// extern s16  D_803D557A;
// extern s16  D_803D557C;
extern f32  D_803D5580;

// overlay2_6C5570
extern s16  D_803D5590[360];
extern s16  D_803D5860[360];
extern s16  D_803D5B30[360];
extern s16  D_803D5E00[360];

// collision
// extern s32  (*D_803D60D0)(Animal *arg0, Animal *arg1, void*, void*, s16 x1, s16 y1, s16 z1, s16 x2, s16 y2, s16 z2);
extern u8   D_803D60D4;
extern Position *D_803D60D8;
extern Position *D_803D60DC;

// overlay2_6D9AF0
extern s16  gControllerDebounce;

// overlay2_6DCA10
extern struct084 D_803D6120; // size 0x3FD8
extern struct036 D_803D6128[]; // eh

// collist2
extern struct065 D_803DA110[40];
extern Animal *D_803DA2F0;

// dynamic_tail
extern struct088 D_803DA300[1000];
extern struct051 D_803E00C0[120];
extern s16  D_803E1B02; // another counter, max 120
extern s16  D_803E1B04; // used vtx for dynamic tails?

// screen_transition
extern ScreenTransition D_803E1B10;

// lights
extern u8   D_803E1BBA; // env r
extern u8   D_803E1BBB; // env g
extern u8   D_803E1BBC; // env b
extern u8   D_803E1BBD; // water r
extern u8   D_803E1BBE; // water g
extern u8   D_803E1BBF; // water b

// input
extern s16  gInputMode;

// overlay2_707310
extern Fog  D_803E1CF8;
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
extern s32  D_803E4D28;
extern s32  gTasksCompleted;
extern s32  D_803E4D30;
extern CmdWrapper D_803E4D40[1666]; // BIG_DAY_PARADE is 1666 commands long
extern u16  D_803E8E54;
extern u8   D_803E8E57;

// overlay2_72B100
extern WaypointData *D_803E8E60[64];
extern u8   D_803E8F60[1100];
extern struct067 D_803E93B0[65];
extern s64  D_803E95B8[65];

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
extern u16  D_803F28D0[8];

extern Camera gCameras[2];
extern s16  gCameraId;
extern s16  D_803F2A9A;
extern s16  D_803F2A9C;
extern s16  D_803F2A9E;
extern u8   D_803F2AA2;
extern u8   D_803F2AA3;
extern u8   D_803F2AA4; // toggle/boolean, cutscene? who knows

extern s16  D_803F2C18[3];
extern s16  D_803F2C28;
extern f32  D_803F2C3C;

extern f32  D_803F2C40;

extern f32  D_803F2C44;
extern f32  D_803F2C48;
extern f32  D_803F2C4C;

extern f32  D_803F2C5C;
extern f32  D_803F2C60;
extern u8   D_803F2C6C;
// extern u8   D_803F2C6D; // deliberately commented out, terminal_background needs it to be an s8

// osd
extern s16  D_803F2CD0;
extern s16  D_803F2CD2; // (race?) timer
extern s16  D_803F2CD4;
extern s16  D_803F2CD6;
extern s16  D_803F2CD8;
extern s8   D_803F2CDC;

extern s16 *D_803F2CE0; // pointer to some text
extern s16  D_803F2CE4; // vertical offset for osd text?
extern u8   D_803F2CE6; // has (death?) sfx been played?
extern s16  D_803F2CE8; // health slider 'animation'

// init.c
extern struct003 D_803F2D10;
extern s16  D_803F2D18;

// overlay2_7688B0
extern s16  D_803F2D24;
extern LevelProgress D_803F2D30;

// TODO:
extern LevelConfig D_803F2D50;

// overlay2_7558F0
extern s16  D_803F2CA6;
extern s8   D_803F2CA8[4][6];

// overlay2_76E7D0
extern s32  D_803F2EB0; // breathing related?
extern s32  D_803F2EB4; // breathing related?
extern s32  D_803F2EB8; // breathing related?
extern s32  D_803F2EBC;
extern s32  D_803F2EC0;
extern s32  D_803F2EC4;
extern s32  D_803F2EC8;
extern u16  D_803F2ECC;
extern u16  D_803F2ECE;
extern s16  D_803F2ED0;
extern s16  D_803F2ED2;
extern s32  D_803F2ED4;
extern s16  D_803F2ED8;
extern u8   D_803F2EDA;
extern u8   D_803F2EDB;
// extern u8   D_803F2EDC;
extern u8   D_803F2EDD;
extern u8   D_803F2EDE;

// overlay2_785D10
extern s16  D_803F2F00; // only used by husky/polar bear? snow footprints?
extern struct060 D_803F2F08[64]; // 0x400 big

// scorpion
extern s16  gScorpionVtxIdx;

extern s16  D_803F3330[]; // message lookup?
extern s16  D_803F34C0[]; // message lookup 2?
extern s16  gLoadedMessageCount;
extern u8   D_803F63C2;

// overlay2_791CD0
extern s16  D_803F63E0;

// cheats
extern Cheats  gCheats;

// overlay2_79DE10
extern s16  D_803F6450;

// terminal_background
extern u8   D_803F6460;
extern Animal *D_803F6464;
extern s16  D_803F6468;
extern f32  D_803F646C;
extern s16  D_803F6470;
extern u8   D_803F6472;
extern s16  D_803F6474;
extern struct109 D_803F6478;
extern s16 *D_803F6500[18];
extern s16  D_803F6548[20];
// extern f32  D_803F6570[64];
extern f32  D_803F6670;

// overlay2_7A0DA0
extern struct027 D_803F6680;
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
