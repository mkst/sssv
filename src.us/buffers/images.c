#include <ultra64.h>
#include "common.h"

// each biome has 20 RGBA16 mipmap textures + 8 IA16 mipmap textures
// each level has 12 RGBA16 mipmap textures
// each biome has 10 RGBA16 textures
// each level has 5 RGBA16 textures
u8 D_800BA760[(40 * 0xab8) + (15*0x800)];

u8 gWaterTextureBuffer[2000]; // = 0x800DCC20; // water texture
u8 D_800DD3F0[4000];        // = 0x800DD3F0; // ZONE_SELECT image
u8 D_800DE390[2704];        // = 0x800DE390; // powercell image
u64  D_800DEE20[128];       // = 0x800DEE20; // dram_stack
Star D_800DF220[1024];      // = 0x800DF220;
