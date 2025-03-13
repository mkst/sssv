#include <ultra64.h>
#include "common.h"


u8 D_800BA760[4000];        // = 0x800BA760; // (32*32*2 ... mipmap images) 0xAB8 each

u8 D_800BB700[1200];        // = 0x800BB700;
u8 D_800BBBB0[1200];        // = 0x800BBBB0;
u8 D_800BC060[1200];        // = 0x800BC060;
u8 D_800BC510[1200];        // = 0x800BC510;
u8 D_800BC9C0[1200];        // = 0x800BC9C0;
u8 D_800BCE70[1200];        // = 0x800BCE70;
u8 D_800BD320[1200];        // = 0x800BD320;
u8 D_800BD7D0[1200];        // = 0x800BD7D0;
u8 D_800BDC80[24000];       // = 0x800BDC80; // SSSV Header image

u8 D_800C3A40[4][32*32*2];  // = 0x800C3A40;

u8 D_800C5A40[9088];        // = 0x800C5A40; //
u8 D_800C7DC0[32928];       // = 0x800C7DC0; // level ia16 textures
u8 D_800CFE60[21952];       // = 0x800CFE60; // ia16 textures
u8 D_800D5420[10240];       // = 0x800D5420; // level textures
u8 D_800D7C20[20480];       // = 0x800D7C20; // biome textures
u8 D_800DCC20[2000];        // = 0x800DCC20; // water textire
u8 D_800DD3F0[4000];        // = 0x800DD3F0; // ZONE_SELECT image
u8 D_800DE390[2704];        // = 0x800DE390; // powercell image
u64  D_800DEE20[128];       // = 0x800DEE20; // dram_stack
Star D_800DF220[1024];      // = 0x800DF220;
