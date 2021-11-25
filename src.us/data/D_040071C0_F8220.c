#include <ultra64.h>

Vtx D_04006F20_F7F80[17] = {
#include "data/inc/D_04006F20_F7F80.inc.c"
};
Vtx D_04007030_F8090[10] = {
#include "data/inc/D_04007030_F8090.inc.c"
};
Vtx D_040070D0_F8130[5] = {
#include "data/inc/D_040070D0_F8130.inc.c"
};
Vtx D_04007120_F8180[10] = {
#include "data/inc/D_04007120_F8180.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

const Gfx D_040071C0_F8220[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04007030_F8090, 10, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
    gsSPVertex(D_04007120_F8180, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
    gsSPVertex(D_040070D0_F8130, 5, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(3, 4, 1, 0, 1, 4, 2, 0),
    gsSPVertex(D_04006F20_F7F80, 17, 0),
    gsDPSetPrimColor(0, 0, 0xE7, 0x6F, 0x97, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 4, 0, 5, 0),
    gsSP2Triangles(0, 6, 5, 0, 7, 6, 0, 0),
    gsSP2Triangles(0, 8, 7, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 9, 0, 7, 10, 6, 0),
    gsSP2Triangles(10, 3, 4, 0, 4, 5, 11, 0),
    gsSP2Triangles(11, 5, 6, 0, 6, 10, 11, 0),
    gsSP2Triangles(11, 10, 4, 0, 1, 3, 12, 0),
    gsSP2Triangles(13, 12, 3, 0, 10, 13, 3, 0),
    gsSP2Triangles(2, 1, 14, 0, 13, 15, 14, 0),
    gsSP2Triangles(13, 10, 15, 0, 16, 14, 15, 0),
    gsSP1Triangle(2, 14, 16, 0),
    gsSPEndDisplayList(),
};
