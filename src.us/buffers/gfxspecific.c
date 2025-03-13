#include <ultra64.h>
#include "common.h"

u8  gfxspecific[16000];     // 0x800B0B20 -> 0x800B49A0

// TODO: why are these included in the gfxspecific segment?

u8 D_800B49A0[8000];        // = 0x800B49A0; // level thumbnail
u8 D_800B68E0[16000];       // = 0x800B68E0; // level trophy
