#ifndef VARIABLES_US_H
#define VARIABLES_US_H

#include "PR/sched.h"

// Overlay 1
// instructions 0x80294E50 to 0x803A04E0
// bss 0x803A04E0 to 0x803C0420
// Overlay 2
// instructions 0x80294E50 to 0x80299730
// bss 0x80299730 to 0x80302E60

// 0x2CB38 in ROM maps to D_80151438

extern s32 *D_801DDD88; // base of animal pointers

extern s32 D_803F2C20; // struct?
/*
  00 // something with camera
  04
  08
  0C x or z position
  10 x or z position
  14 y position
*/

// 0x8000xxxx

extern s16  D_80000302;
extern s32  D_80000400;

// 0x8002xxxx

extern s32  D_80025C00;

// 0x800Bxxxx

extern struct038 D_800BB210[];

// 0x8010xxxx

extern s32  D_80100000;

// 0x8012xxxx

extern u8  D_0012A390[];
extern u8  D_0012EDC0[];

// 0x8014xxxx

extern s32  D_8014D390;
extern s32  D_8014D460; // ucode text start
extern s32  D_8014E300;
extern s32  D_8014F1D0; // ucode text start

// 0x8015xxxx

extern s32  D_80150600;
extern u32  D_80151430;
extern u16  D_80151434;
extern u8   D_80151438[]; // maps to ROM 0x2CB38 ?
extern f32  D_80151C38[];
extern s16  D_80152C78[];
extern s16  D_80152040[];
extern s8   D_80152248[];
extern struct013  D_80152350[];
extern u32  D_80152E80;
extern u8   D_80152E90;
extern u8   D_80152E98;
extern s16  D_80152E9C;
extern struct028  D_80152EA8;
extern u16  D_80152EB8;
extern u16  D_80152EBC;
extern s32  D_801542D0;
extern s32  D_80154370;
extern s32  D_80154500[]; // bunch of offsets to RNC files
extern s32  D_80154628; // display list?
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
extern f32  D_801546D0;
extern f32  D_801546D4;
extern s16  D_801546D8;
extern u16  D_801546E0;
extern s32  D_80154C4C[]; // sound effect pointers?

extern s16  D_801550F8[];
extern s32  D_80155154; // sound initialised?
extern s32  D_8015515C;
extern s8   D_80155164[];
extern s8   D_80155168[];
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

extern s32  D_8015B790; // ucode data start
extern s32  D_801582C0; // display list?
extern s32  D_80158368;
extern s32  D_801584A0;
extern s16  D_80158540;
extern s32  D_80158544;
extern s32  D_80158550;
// extern OSViMode D_80159980[];
extern f64  D_8015AC60;
extern f64  D_8015AC68;
extern f64  D_8015AC70;
extern f64  D_8015AC78;
extern f64  D_8015AC80;
extern f64  D_8015AC88;
extern f64  D_8015AC90;
extern u8   D_8015AD70[]; // "reset all data - %d\n"
extern u8   D_8015AD90[]; // "----------------- Active sounds"
extern u8   D_8015ADB4[]; // "sndState:%d sndSlot:%d sndID:%d object:%p counter:%d sndSlotState[sndSlot]:%d"

extern s32  D_8015C750;
extern s32  D_8015D710; // ucode data start
extern s32  D_8015DF10;

// 0x8016xxxx

extern OSSched D_801603D0;
extern struct008 D_80162658[];

// 0x8019xxxx

extern struct009 D_8019A658[];

// 0x801Dxxxx

extern s32  D_801D9D70; // camera position? distance? angle?
extern u16  D_801D9E38;
extern s16 *D_801D9E6C;
extern s16 *D_801D9E70;
extern s16 *D_801D9E74;
extern s32  D_801D9E78;
extern Gfx *D_801D9E7C;
extern Gfx *D_801D9E88;
extern Gfx *D_801D9E8C;
extern Gfx *D_801D9E90;
extern Gfx *D_801D9E94;
extern struct014 *D_801D9E98[];
extern Gfx *D_801D9EB8;
extern u16  D_801D9ED4;
extern struct035 D_801D9ED8[]; // size 0xEC

// 0x8020xxxx

extern struct002 *D_80200000;
extern s16  D_80200008;
extern s16  D_80203FD0;
extern s32  D_80203FD2;
extern RomHeader D_80204240;
extern s16  D_80204260;
extern u16  D_80204270;
extern s32  D_802042B0;
extern struct008 *D_80204274;
extern DisplayList *D_80204278;
extern s32  D_802042A0;
extern s16 *D_802042F0;
extern s16 *D_80204368;
extern s32  D_802043E0;
extern s16  gScreenWidth;
extern s16  gScreenHeight;

extern s32  D_8022E0D4;
extern s32  D_8022E0DC;
extern s32  D_8022E3E0;
extern u8   D_8022E3E4;
extern s16  D_8022E3F0[]; // maps to ROM 0x12A390

extern ALSeqFile *D_8028630C;
extern ALSndPlayer *D_80286310;
extern s32 D_80286314[];
extern struct017 *D_8028631C;
extern struct017 *D_80286320;
extern struct042 D_80286338[];

extern s32  D_80286328;
extern s16  D_80286388[];
extern ALCSeq *D_802863CC;
extern ALSeqPlayer *D_802863C8[];
extern u8   D_802863B0[];


extern OSThread gThread1; // thread ID 1 (idle after init)
extern OSThread gThread9; // thread ID 9
extern s32  D_8028D230;

extern s16  D_8028654C;
extern OSThread gThread6; // thread ID 6
extern OSThread gThread7; // thread ID 7
extern s32  D_80288E30;
extern s32  D_8028B030;

extern OSMesgQueue D_80291060;
extern OSMesgQueue D_80291078;
extern OSMesgQueue D_8028D030;
extern OSMesgQueue D_8028D048;
extern OSMesgQueue D_8028D060;
extern OSMesgQueue D_8028D078;
extern OSMesgQueue D_8028D090;
extern OSMesgQueue D_8028D0A8;
extern OSIoMesg    D_8028D0C0;
extern s32  D_8028E230;
extern OSMesg      D_8028F640;

extern s32  D_80299CD0;
extern Light *D_80299D50;
extern Light *D_80299D58;
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
extern s8   D_80299E24;
extern u8   D_80299FCC;
extern s16  D_80299FD0;

extern s32  D_802AFBD0;
extern s32  D_802B12D0;
extern s32  D_802B2930;
extern s32  D_802B3F90;
extern s32  D_802B64A0; // ROM 0x659b40
extern s32  D_802BC430;
extern s32  D_802C11C0;
extern s32  D_802EEB20;
extern s32  D_802F4CA0;



extern u16  D_8020427C;
extern s16  D_80204280;
extern u16  D_80204282;
extern u16  D_80204284;
extern s8   D_80204288;
extern struct018 *D_8020428C;
extern s16  D_80204290;
extern u16  D_80204292;
extern s16  D_80204294;
extern struct006 D_80204298; // OSMesg

extern struct012 D_802053E0;
extern s16 D_802053EA;
extern struct012 D_802053F0; // pointer?
extern struct012 D_80205400;
extern s32 D_80205410[];
extern s16  D_8020540C;
extern u8   D_80286458;
extern u16  D_8028645A;
extern s16  D_8028645C;
extern ALCSeqMarker D_80286460;
extern OSMesg D_80290F40;
extern OSMesg D_802902C0;
extern OSMesg D_80290FC8;
extern struct006 *D_80291054;
extern OSMesg D_80291058;
extern OSMesg D_8029105C;
extern Controller D_80291090[];
extern OSMesg D_80291048;
extern OSMesg D_8029104C;
extern u16   *D_802910D0;
extern OSContStatus *D_802910D8[];
extern ControllerMesg D_80291100;
extern OSPfs        *D_80291110[]; // ?
extern OSMesgQueue D_802912B0;
extern OSMesg      D_802912C8;
extern OSMesg      D_802912CC;
extern s32  D_802912D0;
extern s32  D_802912D4;
extern s16  D_802912D8;
extern u16  D_802912DA;
extern u16  D_802912DC;
extern u8   D_802912DE;
extern u8   D_802912DF;
extern u8   D_802912E0;
extern u8   D_802912E1;
extern u8   D_802912E2;
extern u8   D_802912E3;
extern u8   D_802912E4;
extern u8   D_802912E5;

extern f32  D_80302D20; // 15000.0f
extern f64  D_80302D28;
extern u16  D_80302E60;
extern s32  D_80302E88;
extern s32  D_8032AE88;
extern s32  D_80338688;
extern s32  D_8033CE88;
extern s32  D_80364E88;
extern s32  D_80376ED8;
extern s32  D_8039E2E8;
extern s16  D_803A0500;
extern s32  D_803A05B0;
extern s32  D_803A38D8;
extern s8   D_803A63B0[];
extern s16  D_803A6730[];
extern s16  D_803A69F0[];
extern s16  D_803A6CE4;
extern s16  D_803A8340;
extern u8  *D_803A8344; // timer string written here
extern s32  D_803A8EC8;
extern struct029 D_803A4B78[];
extern u8   D_803A48C0[]; // europe
extern u8   D_803A4ABC[]; // ice
extern u8   D_803A4A2C[]; // jungle
extern u8   D_803A4B38[]; // desert

extern s16  D_803B62B0;
extern s16  D_803B62B4;
extern u16  D_803B62B8;
extern s16  D_803B62BC;
extern u8   D_803B62C0;
extern u8   D_803B6318;
extern s32  D_803B6320[];
extern s32  D_803B6328[];
extern struct028 D_803B66F0;
extern struct004 D_803B6700[];
extern struct004 D_803B6730;
extern struct004 D_803B683C;
extern struct004 D_803B6790;
extern u16  D_803B6870[];
extern f32  D_803B7468;
extern u8   D_803BBF00[]; // "\nASSERT: TotalMass != 0, %s, %u\n" (in /src/collision.c)
extern f64  D_803BBF48; // 0.7
extern f64  D_803BBF50; // 0.7
extern f32  D_803BBF58; // 0.699999988079071f (0.7f)
extern f32  D_803BBF5C; // -0.699999988079071f (-0.7f)
extern u8   D_803BE940[]; // "%8d"
extern u8   D_803BE944[]; // "%d"
extern u8   D_803BE948[]; // "%d:%02d"
extern f64  D_803BE950;
extern f32  D_803BEB0C; // 1.7999999523162842
extern f32  D_803BEB10;
extern f32  D_803BEB14;
extern f32  D_803BEB18;
extern f32  D_803BEB1C;
extern f32  D_803BEB20;

extern u8   D_803BFAA0[]; // "%9d"
extern u8   D_803BFAA4[]; // (%3d  %3d  %4d)
extern u8   D_803BFAB4[]; // Ver - 1.37
extern u8   D_803BFAC0[]; // WIZDIZWE (energy top up)
extern u8   D_803BFACC[]; // UDIZDUZD (unlock Europe)
extern u8   D_803BFAD8[]; // UDZIDEZD (unlock Ice)
extern u8   D_803BFAE4[]; // UDIZDWZD (unlock Jungle)
extern u8   D_803BFAF0[]; // UDIZDLZD (unlock Desert)
extern u8   D_803BFAFC[]; // UDIZDRZD (unlock Final level)
extern u8   D_803BFB08[]; // DUZIDLZD (unlock Hidden level)
extern u8   D_803BFB14[]; // UIZDLZDU ("Funny effect 1")
extern u8   D_803BFB20[]; // IDZIDUIL ("Funny effect 2")
extern u8   D_803BFB2C[]; // ZDUIRILR ("Funny effect 3")
extern u8   D_803BFB38[]; // LRZILZRL ("Funny effect 4")
extern u8   D_803BFB44[]; // DANISIL (stop camera in Wallrace64 (?))
extern u8   D_803BFB50[]; // "%9d"
extern u8   D_803BFFD4[]; // "%s\n"

extern DisplayList* D_803D3434;
// more position vars
extern struct037 *D_803D5520;
extern struct035 *D_803D5524;
extern s32 D_803D5528;
extern Animal *D_803D552C;
extern s16 D_803D5540;
extern u16 D_803D5544;
extern u16 D_803D5546;
extern s8  D_803D554A;
extern s8  D_803D554B;
extern s8  D_803D554C;
extern s32 D_803D5564;
extern s32 D_803D5568;
extern u8  D_803D5575; // controller maginitude?
extern struct043 *D_803D60DC;

extern u16  D_803F2D20;
extern s8   D_803F2D22;
extern s8   D_803F2D23;
extern s16  D_803F3330[]; // tbd
extern s16  D_803F34C0[]; // tbd
extern s16  D_803F63C0;
extern s16  D_803F63E0;
extern u8   D_803F6410[20];
extern struct005  D_803F6428;
extern s16  D_803F642C;
extern s16  D_803F642E;
extern s16  D_803F6432;
extern s16  D_803F6434;
extern s16  D_803F6436;
extern s16  D_803F6438;
extern s16  D_803F643A;
extern s16  D_803F643C;
extern struct027 D_803F6680;
extern u16  D_803F6684;
extern u8   D_803F66A6;
extern u16  D_803F66A4;
extern u8   D_803F66AD;
extern u8   D_803F66AE;
extern u8   D_803F66AF;
extern struct032 D_803F66B8;
extern f32  D_803F6700;
extern u16  D_803F6704;
extern u16  D_803F6706;
extern u16  D_803F6708;
extern u16  D_803F670A;
extern u16  D_803F670C;
extern u16  D_803F670E;
extern u16  D_803F6714;
extern s16  D_803F6716; // these 3 store eeprom data
extern s16  D_803F6718;
extern s16  D_803F671A;
extern s16  D_803F671C;
extern f32  D_803F7D68;
extern u16  D_803F7D9C;
extern u16  D_803F7D9E;
extern struct045  D_803F7E10[30];
extern u16  D_803FDEA0;
extern s16  D_803C0420[];

extern f32  D_803C0388;
extern f32  D_803C03F4;
extern u8   D_803C0422;
extern s16  D_803C0424;
extern s16  D_803C0426;
extern s32  D_803C0428;
extern s16  D_803C042A;
extern Fog  D_803C0660[]; // fogPositions? or just a coincidence
extern u8   D_803C063C;
extern s64  D_803C0640;
extern s32  D_803C0644;
extern s64  D_803C0648;
extern s64  D_803C064C;
extern s64  D_803C0650;
extern u16  D_803C0658; // matrix normalise
extern struct025 D_803F2900[];
extern u16  D_803F2CD0;
extern s16  D_803F2CD2; // (race?) timer
extern s16  D_803F2CD4;
extern s16  D_803F2CD6;
extern s16  D_803F2CD8;
extern s16  D_803F2CDA;
extern s8   D_803F2CDC;
extern s8   D_803F2CDD;
extern u8   D_803F2CDE;
extern u8   D_803F2CDF;
extern s32  D_803F2CE0;
extern s16  D_803F2CE4;
extern s16  D_803F2CE6;
extern s32  D_803F2CEC;
extern u8   D_803F2CF2;

extern u16  D_803F2CE8; // health slider 'animation'
extern s16  D_803F2CF0;
extern struct033 D_803F2CF8; // pointer to an animal+health
extern s32  D_803F2C3C;
extern s32  D_803F2C40;
extern f32  D_803F2C44;
extern f32  D_803F2C48;
extern f32  D_803F2C4C;
extern struct034 D_803F2D04;
extern struct001 D_803F2D30;
extern s16  D_803F2D34;
extern s16  D_803F2D38; // map index
extern u8   D_803F2D3E; // score as a string, e.g. "       0"
extern struct000 D_803F2D50;
extern u16  D_803F2D68;
extern s16  D_803F2D70; // biome (0 Europe, 1 Ice, 2 Desert, 3 Jungle)


extern s16  D_803D5510;
extern s16  D_803D5512;
extern Animal *D_803D5530;
extern s16  gCurrentAnimalIndex; // current animal (id within level)
extern u8   D_803D5538;
extern u16  D_803D553A;
extern s16  D_803D553C;
extern s16  D_803D553E;
extern Animal *D_803DA2F0;
extern Animal *D_803DA2F4;
extern s32  D_803E4D28;
extern s32  D_803E4D2C;
extern s16  D_803E1BC0;
extern u16  D_803E1BC4; // buttons pressed
extern Fog  D_803E1CF8;
extern s16  D_803E9820;
extern s16  D_803E9822;
extern s16  D_803E9824;
extern u16  D_803E9828[];
extern s16  D_803F2E16;
extern s16  D_803F2E1E;
extern s16  D_803F2E2A;
extern u16 *D_803F2E34;
extern s32  D_803F2EB0;
extern s32  D_803F2EB4;
extern s32  D_803F2EB8;
extern f32  D_803F7D70;
extern struct030 D_803F7D78; // ?
extern u8   D_803F7DA0;
extern u8   D_803F7DA1;
extern u8   D_803F7DA2;
extern u8   D_803F7DA3;
extern struct030 D_803F7DA8;
extern s8   D_803F7DD4;
extern s8   D_803F7DD5;
extern s8   D_803F7DD6;
extern s8   D_803F7DD7;
extern s8   D_803F7DD8;

extern s32  D_801DD800;
extern struct015 D_801DDD8C[]; // animals struct array
extern s16  D_801E9EB4;

extern s32  D_80231AA0;
extern s32  D_80231D5C;
extern s32  D_80235410[];
extern struct023 D_8023F1E0;
extern u8   D_8023F1E8;
extern s8   D_8023F1F0;
extern s8   D_8023F1F1;
extern s8   D_8023F1F2;
extern s8   D_8023F1F3;
extern s8   D_8023F1F4;
extern s8   D_8023F1F5;
extern f32  D_8023F1F8;
extern f32  D_8023F1FC;
extern s32  D_8023F260[]; // likely Eeprom too
extern Eeprom D_8023F2A0;
extern s32  D_8023F2A8; // TODO: is this D_8023F2A0.unk8?
extern s8   D_8023F2AC;
extern s8   D_8023F2AD;
extern s8   D_8023F2AE;
extern Eeprom  D_8023F2E0[];

// display
extern u16  D_8023F3E0;

// audio
extern struct007   *D_8023F410[3];
extern OSThread    gAudioThread;
extern OSMesg      D_8023F5F0;
extern OSMesg      D_8023F688;
extern OSMesgQueue D_8023F670;
extern OSMesgQueue D_8023F5D8;
extern OSMesg      D_802423E8;
extern struct021   D_80241758;
extern ALHeap D_80241768[];
extern ALHeap D_8024177C[];
extern s16  D_80241D08;
extern s16  D_80241D0A;
extern s16  D_80241D0C;
extern u16  D_80241D0E;
extern OSMesgQueue D_802423D0;
extern s16  D_803F2A98;
extern u8   D_803F2AA2;
extern u8   D_803F2AA3;
extern u16  D_803F28D0;
extern struct025   D_803F28E0[];
extern ALGlobals   D_8023F708;
extern struct003 D_803F2D10;
extern s8   D_803F2D23;

extern s32  D_80032870;
extern u8   D_80099600[]; // _gfxdlistSegmentStart
extern u8   D_8004B400[]; // _gfxdlistSegmentEnd
extern s32  D_800C3A40;
extern s32  D_800C4240;
extern s32  D_800C4A40;
extern s32  D_800C5240;
extern s32  D_800C5A40;
extern s32  D_800DCC20; // water texture location?
extern u8   D_800DEE20[]; // tbd
extern u8   D_800DF220[];
extern u8   D_800E1220[]; // _fontbufferSegmentStart
extern u8   D_800EF0D0[]; // _fontbufferSegmentEnd
extern u8   D_800FF0D0[];

// display lists
extern u8   D_01003498[];
extern u8   D_01003998[];
extern u8   D_01003B70[];
extern u8   D_01004270[];
extern u8   D_01004360[];
extern u8   D_010043A0[];
extern u8   D_01004AF8[];
extern u8   D_01021BB0[];
extern u8   D_01030810[];
extern u8   D_0103B6F0[];
extern u8   D_04005B60[];
extern u8   D_04006D00[];
extern u8   D_0400A9E0[];
#endif
