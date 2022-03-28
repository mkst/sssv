#include <ultra64.h>

Vtx D_04009E30_FAE90[4] = {
#include "data/inc/D_04009E30_FAE90.inc.c"
};
Vtx D_04009E70_FAED0[3] = {
#include "data/inc/D_04009E70_FAED0.inc.c"
};
Vtx D_04009EA0_FAF00[7] = {
#include "data/inc/D_04009EA0_FAF00.inc.c"
};
Vtx D_04009F10_FAF70[3] = {
#include "data/inc/D_04009F10_FAF70.inc.c"
};
Vtx D_04009F40_FAFA0[8] = {
#include "data/inc/D_04009F40_FAFA0.inc.c"
};

extern Gfx D_01003508_3CDD8[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04009FC0_FB020[] = {
    gsSPDisplayList(D_01003508_3CDD8),
    gsSPVertex(D_04009E70_FAED0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_04009F10_FAF70, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x6B, 0x7B, 0xFF),
    gsSPVertex(D_04009EA0_FAF00, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 4, 2, 0),
    gsSP1Triangle(4, 6, 5, 0),
    gsSPVertex(D_04009E30_FAE90, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSPVertex(D_04009F40_FAFA0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(3, 2, 4, 0, 5, 6, 0, 0),
    gsSP1Triangle(6, 5, 7, 0),
    gsSPEndDisplayList(),
};
