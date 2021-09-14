#include <ultra64.h>

Vtx D_050008C0_B3790[13] = {
#include "data/inc/D_050008C0_B3790.inc.c"
};
Vtx D_05000990_B3860[3] = {
#include "data/inc/D_05000990_B3860.inc.c"
};
Vtx D_050009C0_B3890[3] = {
#include "data/inc/D_050009C0_B3890.inc.c"
};
Vtx D_050009F0_B38C0[9] = {
#include "data/inc/D_050009F0_B38C0.inc.c"
};
Vtx D_05000A80_B3950[4] = {
#include "data/inc/D_05000A80_B3950.inc.c"
};

const Gfx D_05000AC0_B3990[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x16, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050008C0_B3790, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 8, 9, 0, 10, 11, 6, 0),
    gsSP2Triangles(8, 10, 6, 0, 9, 7, 12, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x2A, 0x00, 0xFF, 0xFF),
    gsSPVertex(D_05000990_B3860, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x17, 0x00, 0xFF),
    gsSPVertex(D_050009C0_B3890, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xF5, 0x00, 0xFF),
    gsSPVertex(D_050009F0_B38C0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 2, 3, 0, 4, 5, 6, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 5, 4, 0),
    gsSP2Triangles(4, 7, 8, 0, 6, 5, 8, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_05000A80_B3950, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
