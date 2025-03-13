#include <ultra64.h>
#include "common.h"

// 0x802053E0 to 0x8022e0d0

// TODO: stick this in tv.c ?

VIData D_802053E0;
VIData D_802053F0;
VIData D_80205400;

s16    D_8020540C;

//

Gfx   *D_80205410[4][6];
Gfx    D_80205470[6000];
Vtx    D_80210FF0[5000];
Vtx    D_80224870[216];  // ?

Gfx   *D_802255F0[4][6];
Gfx    D_80225650[2000];
Vtx    D_802294D0[1000];
Vtx    D_8022D350[216]; // ?
