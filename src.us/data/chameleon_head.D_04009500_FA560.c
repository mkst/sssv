#include <ultra64.h>

Vtx D_04009030_FA090[8] = {
#include "data/inc/D_04009030_FA090.inc.c"
};
Vtx D_040090B0_FA110[8] = {
#include "data/inc/D_040090B0_FA110.inc.c"
};
Vtx D_04009130_FA190[3] = {
#include "data/inc/D_04009130_FA190.inc.c"
};
Vtx D_04009160_FA1C0[4] = {
#include "data/inc/D_04009160_FA1C0.inc.c"
};
Vtx D_040091A0_FA200[10] = {
#include "data/inc/D_040091A0_FA200.inc.c"
};
Vtx D_04009240_FA2A0[7] = {
#include "data/inc/D_04009240_FA2A0.inc.c"
};
Vtx D_040092B0_FA310[7] = {
#include "data/inc/D_040092B0_FA310.inc.c"
};
Vtx D_04009320_FA380[3] = {
#include "data/inc/D_04009320_FA380.inc.c"
};
Vtx D_04009350_FA3B0[15] = {
#include "data/inc/D_04009350_FA3B0.inc.c"
};
Vtx D_04009440_FA4A0[3] = {
#include "data/inc/D_04009440_FA4A0.inc.c"
};
Vtx D_04009470_FA4D0[3] = {
#include "data/inc/D_04009470_FA4D0.inc.c"
};
Vtx D_040094A0_FA500[3] = {
#include "data/inc/D_040094A0_FA500.inc.c"
};
Vtx D_040094D0_FA530[3] = {
#include "data/inc/D_040094D0_FA530.inc.c"
};


extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003548_3CE18[];

const Gfx D_04009500_FA560[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04009030_FA090, 8, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSP1Quadrangle(2, 1, 4, 5, 0),
    gsSP2Triangles(0, 2, 5, 0, 1, 6, 4, 0),
    gsSP2Triangles(1, 3, 6, 0, 3, 7, 6, 0),
    gsSP2Triangles(3, 0, 7, 0, 0, 5, 7, 0),
    gsSPVertex(D_040090B0_FA110, 8, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(5, 1, 3, 0, 5, 6, 1, 0),
    gsSP2Triangles(6, 2, 1, 0, 6, 7, 2, 0),
    gsSP2Triangles(7, 0, 2, 0, 7, 4, 0, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xD6, 0xFF, 0xD6, 0xFF),
    gsSPVertex(D_04009160_FA1C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPVertex(D_04009240_FA2A0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP1Triangle(4, 5, 6, 0),
    gsSPVertex(D_04009320_FA380, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_04009440_FA4A0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_040094A0_FA500, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x7B, 0x00, 0xFF),
    gsSPVertex(D_04009130_FA190, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_040091A0_FA200, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 5, 0, 6, 7, 5, 0),
    gsSP1Triangle(7, 8, 9, 0),
    gsSPVertex(D_040092B0_FA310, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 3, 5, 0),
    gsSPVertex(D_04009350_FA3B0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 6, 4, 0),
    gsSP2Triangles(5, 7, 6, 0, 8, 6, 7, 0),
    gsSP2Triangles(4, 6, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 7, 5, 11, 0),
    gsSP2Triangles(11, 5, 3, 0, 0, 11, 3, 0),
    gsSP2Triangles(11, 10, 9, 0, 9, 7, 11, 0),
    gsSP2Triangles(12, 11, 0, 0, 12, 10, 11, 0),
    gsSP1Triangle(8, 13, 14, 0),
    gsSPVertex(D_04009470_FA4D0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_040094D0_FA530, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
