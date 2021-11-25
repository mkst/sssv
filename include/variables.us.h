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

extern u8   D_01000620[];
extern u8   D_01000CC0[];
extern u8   D_01000D00[];
extern u8   D_01000D20[];
extern Gfx  D_01003460[];
extern Gfx  D_01003498_3CD68[];
extern Gfx  D_010034C0_3CD90[];
extern Gfx  D_01003548_3CE18[];
extern Gfx  D_01003618_3CEE8[];
extern Gfx  D_01003998_3D268[];
extern Gfx  D_01003A58[];
extern Gfx  D_01003B70_3D440[];
extern Gfx  D_01004270[];
extern Gfx  D_01004360_3DC30[];
extern u8   D_010043A0[];
extern Gfx  D_01004510[];
extern Gfx  D_010049A0_3E270[];
extern u8   D_01004AF8[];
extern Gfx  D_01013370_4CC40[];
extern u8   D_01021BB0[];
extern u8   D_0102A210[];
extern u8   D_0102C810[];
extern u8   D_0102F010[];
extern u8   D_01030810[];
extern u8   D_01033190[];
extern Gfx  D_01037700[];
extern u8   D_0103B6F0[];
extern u8   D_04000000[];
extern u8   D_040000A0[];
extern Gfx  D_040000E0_DD6A0[];
extern u8   D_04000230[];
extern Gfx  D_040002D0_DD890[];
extern u8   D_04000370[];
extern u8   D_040004B0[];
extern u8   D_04000600[];
extern u8   D_040006F0[];
extern Gfx  D_04000840_DDE00[];
extern Gfx  D_04000900_DDEC0[];
extern u8   D_040009D0[];
extern Gfx  D_04000AE0_DE0A0[];
extern u8   D_04000B10[];
extern Gfx  D_04000B40_DE100[];
extern u8   D_04000D10[];
extern u8   D_04000DB0[]; // tortoise?
extern u8   D_04000DD0[];
extern Gfx  D_040005A0_DDB60[];
extern u8   D_04002D70[];
extern Gfx  D_04002630_DFBF0[]; // polar bear
extern Gfx  D_04002930_DFEF0[]; // polar bear
extern u8   D_040029D0[];
extern u8   D_04002F28[];
extern u8   D_04003850[];
extern u8   D_04003A50[];
extern u8   D_04005B60_11C730[]; // spaceship interior
extern u8   D_04006D00_11D8D0[]; // tv body
extern u8   D_04006EC0[];
extern Gfx  D_04007500_E4AC0[];
extern Gfx  D_040077E0_E4DA0[];
extern Gfx  D_04007BD0[];
extern u8   D_04007700[];
extern u8   D_040077A0[];
extern u8   D_040078C0[];
extern u8   D_040079F0[];
extern Gfx  D_04007AE0_E50A0[];
extern u8   D_04007B40[];
extern u8   D_04007C60[];
extern u8   D_04007D90[];
extern u8   D_04007DD0[];
extern u8   D_04007E70[];
extern u8   D_04007E90[];
extern u8   D_04007EC0[];
extern u8   D_04007FA0[];
extern u8   D_04008290[];
extern u8   D_04008420[];
extern u8   D_040088F0[];
extern u8   D_040089E0[];
extern u8   D_04008A10[];
extern u8   D_04008C10[];
extern u8   D_0400A9E0_1215B0[];
extern u8   D_04012B20_1296F0[];
extern u8   D_04013060[];
extern u8   D_040131B0[];
extern u8   D_040133C0[];
extern u8   D_04013580[];
extern Gfx  D_04003140[];
extern Gfx  D_040033C0[];
extern Gfx  D_04003530[];
extern Gfx  D_04003650[];
extern Gfx  D_04003E70[];
extern Gfx  D_04004070[];
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

// 0x800Dxxxx

extern s32  D_800DCC20; // water texture location?
extern u8   D_800DEE20[]; // tbd
extern Star D_800DF220[1024]; // could just be [x][4] s16 array

// 0x800Exxxx

extern u8   D_800E1220[]; // _fontbufferSegmentStart
extern u8   D_800EF0D0[]; // _fontbufferSegmentEnd

// 0x800Fxxxx

extern u8   D_800FF0D0[];

// 0x8010xxxx

extern s32  D_80100000;

// 0x8012xxxx

extern u8  D_0012A390[];
extern u8  D_0012EDC0[];

// 0x8014xxxx

// extern u8   D_8014D390[];
// extern u8   D_8014D460[]; // ucode text start
extern s32  D_8014E300;
extern s32  D_8014F1D0; // ucode text start

// 0x8015xxxx

extern u8   D_80150600[];
extern u32  D_80151430;
extern u16  D_80151434; // kinda random number?
extern u8   D_80151438[]; // maps to ROM 0x2CB38 ?

extern f32  D_80151C38[];
extern s16  D_80152620[];
extern s16  D_80152C78[];
extern s16  D_80152040[];
extern s8   D_80152248[];
extern struct013 D_80152350;
extern u32  D_80152E80; // gRandomSeed
extern u8   D_80152E90;
extern u8   D_80152E98;
extern s16  D_80152E9C;
extern s16  D_80152EA0;
extern s16  D_80152EA4;
extern Vp   D_80152EA8;
extern u16  D_80152EB8; // frame buffer id?
extern u16  D_80152EBC;
extern s32  D_801542D0;
extern u8   D_80154370[];

// extern u8*  D_80154500[37][2]; // bunch of offsets to RNC language files
extern s32  D_80154680; // some kind of counter?
extern s16  D_80154684;
extern s16  D_80154688;
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
extern f32  gMusicVolume;
extern f32  gSfxVolume;
extern s16  D_801546D8;
extern s16  D_801546E0;
extern s32  D_801546E4;
extern f32  D_801546E8[];

extern s16  D_801550F8[];
extern s32  gAudioInitialized;
extern s32  D_8015515C;
extern s8   D_80155164[];
extern s8   D_80155168[]; // is this u8?
extern s16  D_8015516C[];
extern s8   D_80155170;
extern f32  D_8015517C;
extern s16  D_80155180;
extern s16  D_80155184;
extern s16  D_80155188;
extern s32  D_8015518C;
extern u16  D_801552A8;
extern u8   D_801552B0;
extern u8   D_801552B4;

extern Gfx  D_801582C0[];
extern Gfx  D_80158368[];
extern Gfx  D_80158420[];
extern Gfx  D_801584A0[];
extern s16  D_80158540;
extern s32  numControllers;
extern u8   D_80158550[];
// extern OSViMode D_80159980[];
extern f64  D_8015AC60;
extern f64  D_8015AC68;
extern f64  D_8015AC70;
extern f64  D_8015AC78;
extern f64  D_8015AC80;
extern f64  D_8015AC88;
extern f64  D_8015AC90;
extern char D_8015ACA0[]; // "%d"
extern char D_8015ACA4[]; // "%d"
extern char D_8015AD70[]; // "reset all data - %d\n"
extern char D_8015AD90[]; // "----------------- Active sounds\n"
extern char D_8015ADB4[]; // "sndState:%d sndSlot:%d sndID:%d object:%p counter:%d sndSlotState[sndSlot]:%d"

extern s32  D_8015B790; // ucode data start
extern s32  D_8015C750;
extern s32  D_8015D710; // ucode data start
extern u8   D_8015DF10[];

// 0x8016xxxx

extern OSSched sc; // D_801603D0;
extern struct018 D_80162658[];

// 0x8019xxxx

extern struct009 D_8019A658[];

// 0x801Dxxxx

extern s32  D_801D9D70; // camera position? distance? angle?
extern u16  D_801D9E38;
extern u8  *D_801D9E6C;
extern s16 *D_801D9E70;
extern s16 *D_801D9E74;
extern u8  *D_801D9E78;
extern Gfx *D_801D9E7C;
extern Gfx *D_801D9E88;
extern Gfx *D_801D9E8C;
extern Gfx *D_801D9E90;
extern Gfx *D_801D9E94;
extern Gfx *D_801D9E98[8];
extern Gfx *D_801D9EB8;
extern u8  *D_801D9EC4;
extern u8   D_801D9EC8;
extern u8   D_801D9EC9;
extern s32  D_801D9ED0;
extern s16  D_801D9ED4; // either 10 or 6 - input debounce?
extern struct050 D_801D9ED8; // what is this variable!?

extern s32  D_801DD800;
extern struct035 *D_801DDD88; // base of animal pointers
extern struct015 D_801DDD8C[]; // animals struct array

// 0x801Exxxx

extern struct080 D_801E1ED8;
extern u16  D_801E9E8E;
extern s16  D_801E9EB2;
extern s16  D_801E9EB4;
extern struct071 D_801E9EB8[]; // 170

// 0x801Fxxxx

extern struct072 D_801F9EB8;

// 0x8020xxxx

extern s16  D_80200008;
extern struct071 D_80203AA8[];
extern struct071 *D_80203D1C[]; // table of pointers to each interactive object
extern s16  D_80203FC4;
extern s16  D_80203FD0;
extern s16  D_80203FD2;
extern struct016 D_80203FE0[34];
extern struct016 D_802040F0[34];
extern s16  D_80203FE8;  // D_80203FE0[1].unk0?
extern s16  D_80203FF0;
extern s16  D_80203FF2;
extern struct061 D_80204090;
extern struct061 D_80204098;
extern struct061 D_802040A0;
extern struct061 D_802040A8;
extern f32  D_80204200;
extern f32  D_80204204;
extern f32  D_80204208;
extern RomHeader D_80204240;
extern s16  gRegion;
extern u16  D_80204270;
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
extern struct006 D_80204298; // OSMesg
extern OSScClient D_802042A0;
extern s16  D_802042A8;
extern char D_802042B0[];
extern s32  D_802042EC;
extern s16  D_802042F0[];
extern s16  D_80204368[];
extern s32  D_802043E0;
extern s16  gScreenWidth;
extern s16  gScreenHeight;

extern struct012 D_802053E0;
extern s16  D_802053EA;
extern struct012 D_802053F0; // pointer?
extern struct012 D_80205400;
extern s16  D_8020540C;
extern u8   D_80205410[][0x18];

// 0x8021xxxx
extern Vtx  D_8021A5A0[]; // level vtx?

// 0x8022xxxx

extern Vtx  D_802294D0[]; // unknown size

extern s16  D_8022E3F0[]; // scratch area for RNC decompression
extern s16  D_8022E3F2;

// 0x8023xxxx

extern u16  D_80231AA0[];
extern s16  D_80231D5C[];
extern s32  D_80235410[];
extern struct023 D_8023F1E0;
extern u8   D_8023F1F0; // r
extern u8   D_8023F1F1; // g
extern u8   D_8023F1F2; // b
extern u8   D_8023F1F3; // a
extern u8   D_8023F1F4;
extern u8   D_8023F1F5;
extern f32  D_8023F1F8; // current font width / scale
extern f32  D_8023F1FC; // current font height / scale
extern s16  D_8023F206[];
extern s16  D_8023F208[32];
extern s16  D_8023F248[];
extern PlayerEeprom D_8023F260; // 0x40 // default user state?
extern Eeprom D_8023F2A0; // global game save state, different struct to user data?
extern Eeprom D_8023F2E0[4]; // 0x100

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
extern s32  D_80242508; // base of heap
// 0x8028xxxx

extern ALBankFile *D_802862F8;
extern ALSeqFile *D_8028630C;
extern ALSndPlayer *D_80286310;
extern u8 *D_80286314[];
extern struct017 *D_8028631C;
extern struct017 *D_80286320;
extern ALHeap D_80286328; // more likely some audio struct.. but whatever
extern struct017 *D_80286338[];
extern s16  D_80286388[];
extern u8   D_802863B0[];
extern ALSeqPlayer *D_802863C8[];
extern ALCSeq *D_802863CC[];

extern u8   D_80286458;
extern s16  D_8028645A;
extern s16  D_8028645C;
extern ALCSeqMarker D_80286460;

extern s16  D_8028654C;
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

extern OSMesg D_80290F40;
extern OSMesg D_802902C0;
extern OSMesg D_80290FC8;

extern OSMesg D_80291048;
extern OSMesg D_8029104C;
extern struct006 *D_80291054;
extern OSMesg D_80291058;
extern OSMesg D_8029105C;
extern OSMesgQueue D_80291060;
extern OSMesgQueue D_80291078;
extern Controller D_80291090;
extern OSContPad *gControllerInput;
extern OSContStatus gControllerStatus[];
extern OSContPad D_802910E8[4]; // 4?
extern ControllerMesg D_80291100;
extern OSPfs       D_80291110[]; // ?
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

extern u16  D_80299C84[3];
extern s32  D_80299CD0_63D370;
extern Light *D_80299D50_63D3F0;
extern Light *D_80299D58_63D3F8;
extern f32  D_80299DB8;
extern f32  D_80299DBC;
extern f32  D_80299DC0;
extern f32  D_80299DC4;
extern f32  D_80299DC8;
extern f32  D_80299DCC;
extern f32  D_80299DD0;
extern f32  D_80299DD4;
extern f32  D_80299DD8;
extern f32  D_80299DDC;
extern f32  D_80299DE0;
extern f32  D_80299DE4;
extern f32  D_80299DE8;
extern f32  D_80299DEC;
extern f32  D_80299DF0;
extern u8   D_80299DFC_63D49C; // intro state
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
extern u16  D_80299E10;
extern u8   D_80299E14;
extern u16  D_80299E1C_63D4BC;
extern s8   D_80299E24;
extern u8   D_80299FCC_63D66C;
extern s16  D_80299FD0_63D670;

// 0x802Axxxx
extern u8   D_802AFBD0[];

// 0x802Bxxxx
extern u8   D_802B12D0[];
extern u8   D_802B2930[];
extern u8   D_802B3F90[];
extern u8   D_802B58A0[];
extern u8   D_802B5CA0[];
extern u8   D_802B60A0[];
extern u8   D_802B64A0[]; // ROM 0x659b40
extern u8   D_802BC430[];

// 0x802Cxxxx

extern u8   D_802C11C0[];

// 0x802Exxxx

extern const Gfx  D_802EEB20_6921C0[]; // spaceship model
extern const Gfx  D_802F3C20_6972C0[]; // N64 controller model

// 0x802Fxxxx

extern u8   D_802F4CA0[];
extern u8   D_802FD920_6A0FC0[]; // English language flag
extern u8   D_802FE520_6A1BC0[]; // French language flag
extern u8   D_802FF120_6A27C0[]; // German language flag
extern u8   D_802FFD20_6A33C0[]; // Italian language flag

// 0x8030xxxx
extern u8   D_80300920_6A3FC0[]; // Portugese language flag
extern u8   D_80301520_6A4BC0[]; // Dutch language flag
extern u8   D_80302120_6A57C0[]; // Spanish language flag
extern f32  D_80302D20; // 15000.0f
extern f64  D_80302D28;

// BSS (overlay1)

extern u8   D_80302E88[];

// 0x8032xxxx

extern u8   D_8032AE88[];

// 0x8033xxxx

extern u8   D_80338688[];
extern u8   D_8033CE88[];

// 0x8036xxxx

extern s32  D_80364E88;

// 0x8037xxxx

extern u8   D_80376ED8[];

// 0x8039xxxx

extern u8   D_8039E2E8[];

// 0x803Axxxx

extern s16  D_803A0500;
extern s16  D_803A05C0_7B1C70;
extern s16  D_803A05C8_7B1C78;
extern s32  D_803A05B0;
extern s32  D_803A05B0_7B1C60;
extern s32  D_803A05B4_7B1C64;
extern struct089 D_803A05D0_7B1C80[];
extern struct098 D_803A1BB0_7B3260[];
extern u16  D_803A20B0_7B3760[]; // colors
extern struct099 D_803A20C0_7B3770[];
extern struct076 D_803A2D90_7B4440[];
extern u8   D_803A38D8[];
extern struct028 D_803A50C0_7B6770;
extern s32  D_803A5520_7B6BD0;
extern s32  D_803A5524_7B6BD4;
extern s32  D_803A5528_7B6BD8;
extern s32  D_803A5530_7B6BE0;
extern s32  D_803A5544_7B6BF4;
extern s8   D_803A5580_7B6C30;
extern s32  D_803A5590_7B6C40[];
extern u16  D_803A5750_7B6E00;
extern u16  D_803A5760_7B6E10;
extern s16  D_803A5764_7B6E14;
extern u8*  D_803A5BF8_7B72A8[36][2];
extern u8   D_803A52A0_7B6950;
extern u8   D_803A52A4_7B6954;
extern u8   D_803A52A8_7B6958;
extern u8   D_803A52AC_7B695C;
extern u8   D_803A52B0_7B6960;
extern u8   D_803A52B4_7B6964;
extern u8   D_803A52B8_7B6968;
extern s32  D_803A52C0;
extern s32  D_803A52C0_7B6970;
extern s16  D_803A52C4;
extern s16  D_803A52C4_7B6974;
extern u8   D_803A52D0_7B6980;
extern struct100 D_803A52E8_7B6998[];
extern s16  D_803A5330_7B69E0;
extern s16  D_803A53C4_7B6A74;
extern s16  D_803A53CC_7B6A7C;
extern s16  D_803A53D4_7B6A84;
extern s16  D_803A53E0_7B6A90;
extern s16  D_803A53FC_7B6AAC;
extern struct082 D_803A63B0_7B7A60[];
extern s16  D_803A6470_7B7B20[];
extern s16  D_803A6520_7B7BD0[];
extern s16  D_803A65D0[];
extern s16  D_803A6680[];
extern s16  D_803A6730[];
extern s16  D_803A69F0[];
extern f32  D_803A6CC4;
extern f32  D_803A6CC8;
extern f32  D_803A6CD0;
extern f32  D_803A6CD4;
extern f32  D_803A6CD8;
extern s16  D_803A6CE4;
extern s16  D_803A6CE4_7B8394;
extern s16  D_803A6CEC;
extern struct075 D_803A6D14_7B83C4[128];
extern struct074 D_803A7114_7B87C4[128];
extern s16  D_803A7B3C[][2];
extern s16  D_803A8340;
extern u8   D_803A8344[]; // timer string written here
extern s8   D_803A8350_7B9A00[];
extern s8   D_803A8358_7B9A08[];
extern s8   D_803A8360_7B9A10[];
extern s32  D_803A8374;
extern s32  D_803A843C;
extern s32  D_803A8450;
extern s32  D_803A8464;
extern s32  D_803A8464_7B9B14;
extern s32  D_803A8484;
extern s32  D_803A8484_7B9B34;
extern s32  D_803A84CC;
extern s32  D_803A84CC_7B9B7C;
extern s32  D_803A8514;
extern s32  D_803A8514_7B9BC4;
extern s32  D_803A8518_7B9BC8;
extern struct068 D_803A8528_7B9BD8[247]; // 0x9C each
extern u8   D_803A8EC8[];
extern u16  D_803A4638[];
extern u8   D_803A48C0[]; // europe
extern u8   D_803A4ABC[]; // ice
extern u8   D_803A4A2C[]; // jungle
extern u8   D_803A4B38[]; // desert
extern u8   D_803A4B78[][0x100];

// 0x803Bxxxx

extern s16  D_803B0400[][20];
extern s16  D_803B0590;
extern s16  D_803B0592;
extern s16  D_803B0594;
extern u8   D_803B0595;
extern s16  D_803B0596;

extern s16 D_803B1BAC[];
extern OSContPad D_803B1F20_7C35D0;
extern OSContPad D_803B2580_7C3C30;
extern OSContPad D_803B29D8_7C4088;
extern OSContPad D_803B30D0_7C4780;
extern OSContPad D_803B384C_7C4EFC;
extern OSContPad D_803B3388_7C4A38;

extern s16  D_803B4F30;
extern s16  D_803B4F34;
extern s32  D_803B4944_7C5FF4;
extern s32  D_803B4958_7C6008;
extern s32  D_803B49CC_7C607C;
extern s32  D_803B4930_7C5FE0;
extern s32  D_803B497C_7C602C;

extern s16  D_803B52FC[];
extern Gfx  D_803B5764[];
extern u8   D_803B58A0_7C6F50[];
extern u8   D_803B58A4_7C6F54[];
extern s16  D_803B58A8_7C6F58[];
extern s32  D_803B58B0_7C6F60;
extern s32  D_803B58C4_7C6F74;
extern void (*D_803B5D20[])(void);
extern s16  D_803B62B0;
extern s16  D_803B62B4;
extern u16  D_803B62B8;
extern s16  D_803B62BC;
extern u8   D_803B62C0;
extern s16  D_803B62D0[];
extern u16  D_803B6310;
extern s16  D_803B6314;
extern u8   D_803B6318;
extern u8   D_803B631C;
extern u8   D_803B6320_7C79D0[]; // "AGCT.-01"
extern s32  D_803B6328_7C79D8[]; // array of pointers to TV screen assembly background text
extern struct028 D_803B66F0;
extern struct004 D_803B6700[];
extern struct004 D_803B6700_7C7DB0;
extern struct004 D_803B6730;
extern struct004 D_803B6730_7C7DE0;
extern struct004 D_803B683C;
extern struct004 D_803B683C_7C7EEC;
extern struct004 D_803B6718_7C7DC8;
extern s32  D_803B6880_7C7F30;
extern struct004 D_803B6790;
extern f32  D_803B6868_7C7F18;
extern f32  D_803B686C_7C7F1C;
extern u16  D_803B6870[];
extern s16  D_803B6870_7C7F20;
extern s8   D_803B71D0[][5];
extern struct066 D_803B7268_7C8918[32];
extern struct066 D_803B7368_7C8A18[32];
extern f32  D_803B7468;
extern f32  D_803B74AC_7C8B5C;
extern f32  D_803B74B0_7C8B60;
extern f32  D_803B74B4_7C8B64;
extern f32  D_803B74B8_7C8B68;
extern f32  D_803B74BC_7C8B6C;
extern f32  D_803B74C0_7C8B70;
extern f32  D_803B74C4_7C8B74;

// rodata starts at 0x803BACD0 (maybe)

extern u8   D_803BBF00[]; // "\nASSERT: TotalMass != 0, %s, %u\n" (in /src/collision.c)
extern f64  D_803BBF48; // 0.7
extern f64  D_803BBF50; // 0.7
extern f32  D_803BBF58; // 0.699999988079071f (0.7f)
extern f32  D_803BBF5C; // -0.699999988079071f (-0.7f)

extern char D_803BC6C0_7CDD70[];
extern char D_803BC6FC_7CDDAC[];
extern char D_803BC720_7CDDD0[];
extern char D_803BC738_7CDDE8[];
extern f32  D_803BCDD8_7CE488;
extern f32  D_803BCDDC_7CE48C;
extern f32  D_803BCF94_7CE644;
// rabbit
extern f32  D_803BCFA0_7CE650; // -0.35f
extern f64  D_803BCFA8_7CE658; // 0.6
extern f64  D_803BCFB0_7CE660; // 1.666
extern f64  D_803BCFB8_7CE668; // 1.2
extern f32  D_803BCFC0_7CE670; // -0.35
// frog
extern f32  D_803BCFD0_7CE680; // -0.38
extern f32  D_803BD114_7CE7C4; // 1.1892
extern s16  D_803BD54A[];
extern s16  D_803BD564_7CEC14[];
extern s16  D_803BD602[];
extern char D_803BD8B0_7CEF60[]; // "Fq %d Time %d S %d\n"
extern char D_803BD9A0_7CF050[]; // "Helimouse is gone\n"
extern f32  D_803BE13C_7CF7EC;
extern f32  D_803BE140_7CF7F0;
extern f32  D_803BE144_7CF7F4;
extern f32  D_803BE148_7CF7F8;
extern f64  D_803BE5F8;
extern f64  D_803BE600;
extern char D_803BE920[]; // "load xlui texture - %d\n"
extern char D_803BE940[]; // "%8d"
extern char D_803BE944[]; // "%d"
extern char D_803BE948[]; // "%d:%02d"
extern f64  D_803BE950;   // 0x3FE3333333333333
extern char D_803BE9A0[]; // "Sorry, no more space for extra hilites\n"
extern char D_803BE9F0[];
extern char D_803BEA38[];
extern char D_803BEA48[];
extern char D_803BEA78[];
extern f64  D_803BEAE8;
extern f64  D_803BEAF0;
extern f64  D_803BEAF8_7D01A8;
extern f32  D_803BEB00_7D01B0;
extern f32  D_803BEB04_7D01B4;
extern f32  D_803BEB08_7D01B8;
extern f32  D_803BEB0C; // 1.7999999523162842
extern f32  D_803BEB10; // 0x3FE66666
extern f32  D_803BEB14;
extern f32  D_803BEB18;
extern f32  D_803BEB1C;
extern f32  D_803BEB20;
extern s16  D_803BEB70_7D0220[16];
extern s16  D_803BEB90_7D0240[16];
extern f32  D_803BEC10;
extern f32  D_803BEC14;
extern f32  D_803BEC18;
extern f32  D_803BEF14;
extern f32  D_803BEF18;
extern f32  D_803BEF68;
extern f32  D_803BEF6C;
extern f32  D_803BEF90;

extern f32  D_803BF028; // 0x3F333333
extern f32  D_803BF02C; // 0x3F333333
extern char D_803BF030[]; // "mapStatus12:%d %d\n"
extern char D_803BF044[]; // "ATTACK ABANDONED\n"
extern f32  D_803BF3E0;
extern char D_803BFFD4[]; // "%s\n"

// 0x803Cxxxx

extern f32  D_803C0160;
extern f64  D_803C0168;
extern f32  D_803C0170_7D1820;
extern f64  D_803C0178;
extern f32  D_803C0180;
extern f32  D_803C0184;
extern char D_803C0190_7D1840[];
extern char D_803C0194_7D1844[];
extern char D_803C0198_7D1848[];
extern char D_803C01B0_7D1860[];
extern char D_803C01C8_7D1878[];

extern f32  D_803C032C_7D19DC;
extern f32  D_803C0348_7D19F8;
extern f32  D_803C034C_7D19FC;
extern f32  D_803C0388;
extern f64  D_803C0390;
extern char D_803C03A0_7D1A50[];
extern char D_803C03A8_7D1A58[];
extern char D_803C03B0_7D1A60[];
extern char D_803C03B8_7D1A68[];
extern char D_803C03C0_7D1A70[];
extern char D_803C03C4_7D1A74[];
extern char D_803C03C8_7D1A78[];
extern char D_803C03D0_7D1A80[];
extern char D_803C03D8_7D1A88[];
extern char D_803C03DC_7D1A8C[];
extern char D_803C03E0_7D1A90[];
extern char D_803C03E4_7D1A94[];
extern char D_803C03E8_7D1A98[];
extern char D_803C03EC_7D1A9C[];
extern char D_803C03F0_7D1AA0[];

extern f32 D_803C03F4_7D1AA4; // 0.1f
extern f32 D_803C03F8_7D1AA8; // 9.7f;
extern f64 D_803C0400_7D1AB0; // 1.95;
extern f64 D_803C0408_7D1AB8; // 2.05;

extern f32  D_803C0410_7D1AC0;
extern s16  D_803C0420; // first var in BSS
extern u8   D_803C0422;
extern s16  D_803C0424;
extern s16  D_803C0426;
extern s16  D_803C0428;
extern s16  D_803C042A;
extern struct053 D_803C0430;
extern Fog  D_803C0660[]; // fogPositions? or just a coincidence
extern u16  D_803C063A;
extern u8   D_803C063C;
extern u64  D_803C0640_7D1CF0;
extern u64  D_803C0648_7D1CF8;
extern u64  D_803C0650_7D1D00;
extern u32  D_803C0654; // geometry mode
extern u16  D_803C0658; // matrix normalise
extern struct063 D_803C0740_7D1DF0[][0x81];
extern s16  D_803C29E4_7D4094[];
extern s16  D_803C29FE[];
// 0x803Dxxxx

extern struct054 D_803D2D90;
extern struct059 D_803D2E08;

extern DisplayList* D_803D3434;
extern struct059 D_803D3448;
extern s32    *D_803D3438;
extern struct058 *D_803D343C;
extern struct059 D_803D3A20;
extern struct059 D_803D3FF8;
extern s8   D_803D45D0;
extern s8   D_803D4BB1;
extern s32  D_803D5188;

extern s16  D_803D5508;
extern s16  D_803D5510;
extern s16  D_803D5512;
extern Animal *D_803D5530;
extern s16  gCurrentAnimalIndex; // current animal (id within level)
extern u8   D_803D5538;
extern s16  D_803D553A;
extern s16  D_803D553C;
extern s16  D_803D553E; // number of animals in level?
extern struct037 *D_803D5520;
extern struct035 *D_803D5524;
extern Animal *D_803D5528;
extern Animal *D_803D552C; // is this *really* Animal? is it World?
extern s16  D_803D5540;
extern s16  D_803D5542;
extern u16  D_803D5544; // timer (for attacks? everything?)
extern u16  D_803D5546;
extern s8   D_803D554A;
extern s8   D_803D554B;
extern s8   D_803D554C;
extern s16  D_803D555A;
extern Animal *D_803D5560;
extern s16  D_803D5564;
extern s16  D_803D5566;
extern s16  D_803D5568;
extern s16  D_803D556A;
extern s16  D_803D556C;
extern s16  D_803D556E;
extern u8   D_803D5575; // controller maginitude?
extern s16  D_803D5590[360];
extern s16  D_803D5860[360];
extern s16  D_803D5B30[360];
extern s16  D_803D5E00[360];

extern s32  (D_803D60D0)();
extern u8   D_803D60D4[];
extern s32  D_803D60D8;
extern struct043 *D_803D60DC;
extern s16  D_803D6110;
extern struct084 D_803D6120; // size 0x3FD8

extern struct065 D_803DA110[40];
extern Animal *D_803DA2F0;
extern Animal *D_803DA2F4;
extern struct088 D_803DA300[1000];

// 0x803Exxxx

extern struct051 D_803E00C0[120];
extern s16  D_803E1B00; // counter, max 1000
extern s16  D_803E1B02; // another counter, max 120
extern u16  D_803E1B04;
extern u16  D_803E1B06;
extern s16  D_803E1B08;
extern ScreenTransition D_803E1B10;
extern u8   D_803E1B1A;
extern u8   D_803E1B1B;
extern u8   D_803E1B1C;
extern u16  D_803E1B1E;
extern s16  D_803E1B20[5];
extern s16  D_803E1B8A;
extern u16  D_803E1B8C;
extern u16  D_803E1B8E;
extern u16  D_803E1B90;
extern u16  D_803E1B92;
extern u16  D_803E1B94;
extern u8   D_803E1B96;
extern u8   D_803E1B97;
extern u8   D_803E1B98;
extern u8   D_803E1B99;
extern u8   D_803E1B9A;
extern u8   D_803E1B9B;
extern u16  D_803E1BA2;
extern u16  D_803E1BA4;
extern u8   D_803E1BA6;
extern u16  D_803E1BA8;
extern u16  D_803E1BAA;
extern u16  D_803E1BAC;
extern u16  D_803E1BAE;
extern u16  D_803E1BB0;
extern u16  D_803E1BB0;
extern u16  D_803E1BB2;
extern u16  D_803E1BB4;
extern u16  D_803E1BB6;
extern u16  D_803E1BB8;
extern u8   D_803E1BBA;
extern u8   D_803E1BBB;
extern u8   D_803E1BBC;
extern s16  D_803E1BC0;
extern OSContPad D_803E1BC4;
extern OSContPad *D_803E1BD4;
extern s32  D_803E1BE0;
extern struct085  D_803E1BE8[10];
extern Fog  D_803E1CE0;
extern Fog  D_803E1CE8;
extern Fog  D_803E1CF0;
extern Fog  D_803E1CF8;
extern u16  D_803E1D00;
extern u16  D_803E1D02;
extern s8   D_803E1D04;
extern u16  D_803E1D06;
extern u16  D_803E1D08;
extern u16  D_803E1D0A;
extern u16  D_803E1D0C;
extern struct063 D_803E1D10;
extern struct063 D_803E1D18;
extern struct063 D_803E1D20;
extern s16  D_803E1D28;
extern u16  D_803E1D2A;
extern u8   D_803E1D2C;
extern u8   D_803E1D30[];
extern u8   *D_803E1D32; // ?
extern struct064 D_803E1D3B[];
extern struct073 D_803E3130[];
extern s16  D_803E4AC8;
extern u8   D_803E4AD0[];
extern s16  D_803E4BD4;
extern struct079 D_803E4BE0;
extern s32  D_803E4C3C;
extern s16  D_803E4C52;
extern s16  D_803E4C54;
extern s16  D_803E4C56;
extern s16  D_803E4C58;
extern s32  D_803E4C5C;
extern s32  D_803E4C60;
extern s32  D_803E4C64;
extern s16  D_803E4C68;
extern s16  D_803E4C6A;
extern s16  D_803E4C6C;
extern s16  D_803E4C6E;
extern s16  D_803E4C70;
extern s16  D_803E4C72;
extern s16  D_803E4C74;
extern s16  D_803E4C76;
extern u8   D_803E4C78;
extern u8   D_803E4C7A;
extern s32  D_803E4C7C;
extern s32  D_803E4C80;
extern s16  D_803E4C84;
extern s16  D_803E4C86;
extern s32  D_803E4C88;
extern s32  D_803E4C8C;
extern void *D_803E4C90;
extern struct071 *D_803E4C94; // Animal*?
extern s32  D_803E4CA0;
extern u8   D_803E4CA4;
extern u8   D_803E4CA5;
extern u8   D_803E4CA6;
extern s32  D_803E4CA8[32];
extern s32  D_803E4D28;
extern s32  D_803E4D2C; // completed tasks?
extern s32  D_803E4D30;
extern s32  D_803E4D38[2];
extern s32  D_803E4D3C;
extern u8   D_803E4D40[1666][10]; // tbd what this is 0x4114
extern u16  D_803E8E54;
extern u8   D_803E8E56;
extern u8   D_803E8E57;
extern u8   D_803E8E58;
extern u8   D_803E8E60[256];
extern u8   D_803E8F60[1100];
extern struct063 D_803E93B0[]; // ??
extern s16  D_803E97C0;
extern s16  D_803E9820;
extern s16  D_803E9822;
extern s16  D_803E9824;
extern u8  *D_803E9828;
extern u8  *D_803E982C;
extern struct067 D_803E9840[];
// 0x803Fxxxx

extern s16  D_803F28C2;
extern u16  D_803F28D0[];
extern u16  D_803F28DC;
extern struct025 D_803F28E0[]; // 2 values?

extern s8   D_803F2A92;
extern s16  D_803F2A98;
extern s16  D_803F2A9E;
extern u8   D_803F2AA0;
extern u8   D_803F2AA2;
extern u8   D_803F2AA3;
extern u8   D_803F2AA4;
extern u8   D_803F2AA5;
extern u8   D_803F2AA6;
extern u8   D_803F2AA7;
extern f32  D_803F2AA8;
extern f32  D_803F2AAC;
extern f32  D_803F2AB0;
extern f32  D_803F2AB4;
extern f32  D_803F2AB8;
extern f32  D_803F2ABC;
extern s8   D_803F2AC5;
extern s8   D_803F2AC6;
extern s16  D_803F2AC8;
extern s16  D_803F2ACA;
extern s16  D_803F2ACC;
extern struct025 *D_803F2AD0;
extern struct062 D_803F2AD8;
extern struct062 D_803F2AF8[8]; // indexed in with % 8
extern struct062 D_803F2BF8;

extern s16  D_803F2C18[3]; // struct?
extern s16  D_803F2C1E;
extern s16  D_803F2C20; // struct?
extern s16  D_803F2C22;
extern f32  D_803F2C2C;
extern f32  D_803F2C30;
extern f32  D_803F2C34;
extern s8   D_803F2C38;
extern f32  D_803F2C3C;
extern f32  D_803F2C40;
extern f32  D_803F2C44;
extern f32  D_803F2C48;
extern f32  D_803F2C4C;
extern f32  D_803F2C50;
extern f32  D_803F2C54;
extern f32  D_803F2C58;
extern s8   D_803F2C6C;
extern s8   D_803F2C6D;
extern s16  D_803F2C6E;
extern s16  D_803F2C70;
extern struct102 D_803F2C80[]; // [0x34] big?
extern s16  D_803F2C86;
extern s16  D_803F2C88;
extern s16  D_803F2C8A;
extern s16  D_803F2C8C;
extern s16  D_803F2C8E;
extern s16  D_803F2C92;
extern u8   D_803F2C96;
extern u8   D_803F2C97;
extern u8   D_803F2C99;
extern u8   D_803F2C9A;
extern u8   D_803F2C9B;
extern s16  D_803F2CA4;
extern s16  D_803F2CA6;
extern s16  D_803F2CD0;
extern s16  D_803F2CD2; // (race?) timer
extern s16  D_803F2CD4;
extern s16  D_803F2CD6;
extern s16  D_803F2CD8;
extern s16  D_803F2CDA;
extern s8   D_803F2CDC;
extern s8   D_803F2CDD;
extern u8   D_803F2CDE;
extern u8   D_803F2CDF;
extern s16 *D_803F2CE0;
extern s16  D_803F2CE4;
extern s16  D_803F2CE6;
extern u16  D_803F2CE8; // health slider 'animation'
extern s32  D_803F2CEC;
extern s16  D_803F2CF0;
extern u8   D_803F2CF2;
extern struct033 D_803F2CF8; // pointer to an animal+health

extern struct034 D_803F2D04;
extern struct003 D_803F2D10;
extern u16  D_803F2D20;
extern s8   D_803F2D22;
extern s8   D_803F2D23;
extern struct001 D_803F2D30;
extern s16  D_803F2D34;
extern s16  gLevelIndex;
extern s16  D_803F2D3C;
extern char D_803F2D3E[]; // score as a string, e.g. "       0"
extern struct000 D_803F2D50;
extern u16  D_803F2D68;
extern s16  D_803F2D70; // biome (0 Europe, 1 Ice, 2 Desert, 3 Jungle)
extern u8   D_803F2DA3;
extern s32  D_803F2E0C;
extern s32  D_803F2E10;
extern s16  D_803F2EE0[];
extern u16  D_803F2EF0;
extern s16  D_803F2E16;
extern s16  D_803F2E1E; // evo suit color
extern s16  D_803F2E2A;
extern f32  D_803F2E30;
extern s16  D_803F2E34[];
extern s32  D_803F2EB0;
extern s32  D_803F2EB4;
extern s32  D_803F2EB8;
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
extern s8   D_803F2EDB;
extern u8   D_803F2EDC;
extern u8   D_803F2EDD;
extern u8   D_803F2EDE;
extern struct060 D_803F2F08[];

extern s16  D_803F3308;
extern s16  D_803F330A;
extern s16  D_803F330C;
extern s16  D_803F330E;
extern s16  D_803F3310;
extern s16  D_803F3330[]; // tbd
extern s16  D_803F34C0[]; // tbd
extern s16  D_803F63C0;
extern u8   D_803F63C2;
extern s16  D_803F63E0;
extern s16  D_803F63F0;
extern s16  D_803F6400; // credit entry offset
extern s16  D_803F6402; // credit vertical position
extern u8   D_803F6410[20];
extern struct005  D_803F6428;
extern s16  D_803F6450;
extern u8   D_803F6460;
extern s32  D_803F6464;
extern s16  D_803F6468;
extern f32  D_803F646C;
extern s16  D_803F642C;
extern s16  D_803F642E;
extern s16  D_803F6432;
extern s16  D_803F6434;
extern s16  D_803F6436;
extern s16  D_803F6438;
extern s16  D_803F643A;
extern s16  D_803F643C;
extern s16  D_803F6470;
extern s8   D_803F6472;
extern s16  D_803F6474;
extern struct027 D_803F6680;
extern u8   D_803F66A6;
extern u8   D_803F66A7;
extern s16  D_803F66A4;
extern u8   D_803F66AA;
extern u8   D_803F66AD;
extern u8   D_803F66AE;
extern u8   D_803F66AF;
extern struct032 D_803F66B8;
extern f32  D_803F6700;
extern s16  D_803F6704;
extern s16  D_803F6706;
extern s16  D_803F6708;
extern s16  D_803F670A;
extern s16  D_803F670C;
extern u16  D_803F670E;
extern u16  D_803F6714;
extern s16  D_803F6716; // current sfx volume
extern s16  D_803F6718; // current music volume
extern s16  D_803F671A; // current language
extern s16  D_803F671C;
extern struct048  D_803F6720[][10];
extern s16  D_803F70F8[][10];
extern s16  D_803F7134[];
extern u16  D_803F713C[];
extern s16  D_803F7144[];
extern s16  D_803F714C[];
extern s16  D_803F71A0[];
extern s32  D_803F7D60;
extern f32  D_803F7D68;
extern f32  D_803F7D70;
extern struct008 D_803F7D78;
extern s16  D_803F7D9C;
extern s16  D_803F7D9E;
extern s8   D_803F7DA0;
extern s8   D_803F7DA1;
extern s8   D_803F7DA2;
extern s8   D_803F7DA3;
extern struct030 D_803F7DA8;
extern s8   D_803F7DD4;
extern s8   D_803F7DD5; // current level idx?
extern s8   D_803F7DD6;
extern s8   D_803F7DD7;
extern s8   D_803F7DD8;
extern s8   D_803F7DE0[]; // levels available
extern s8   D_803F7DFE;

extern s16  D_803F7E00; // europe levels completed
extern s16  D_803F7E02; // levels
extern s16  D_803F7E04; // levels
extern s16  D_803F7E06; // levels
extern struct045  D_803F7E10[30];
extern u16  D_803FDEA0;

#endif
