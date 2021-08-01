#include <ultra64.h>


Vtx D_04004390_1040E0[16] = {
#include "data/inc/D_04004390_1040E0.inc.c"
};
Vtx D_04004490_1041E0[16] = {
#include "data/inc/D_04004490_1041E0.inc.c"
};

extern Gfx D_01003548_3CE18[];


const Gfx D_04004590_1042E0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x19, 0x19, 0x19, 0xFF),
    gsSPVertex(D_04004390_1040E0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 3, 5, 2, 0),
    gsSP2Triangles(6, 3, 4, 0, 3, 6, 7, 0),
    gsSP2Triangles(5, 3, 7, 0, 8, 6, 4, 0),
    gsSP2Triangles(7, 9, 5, 0, 10, 7, 6, 0),
    gsSP2Triangles(7, 10, 11, 0, 9, 7, 11, 0),
    gsSP2Triangles(12, 10, 6, 0, 6, 8, 12, 0),
    gsSP2Triangles(11, 13, 9, 0, 4, 0, 14, 0),
    gsSP2Triangles(15, 4, 14, 0, 4, 15, 8, 0),
    gsSPVertex(D_04004490_1041E0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 2, 0, 5, 0),
    gsSP2Triangles(6, 2, 5, 0, 5, 7, 6, 0),
    gsSP2Triangles(2, 6, 8, 0, 8, 9, 2, 0),
    gsSP2Triangles(9, 1, 2, 0, 1, 9, 10, 0),
    gsSP2Triangles(4, 1, 10, 0, 10, 11, 4, 0),
    gsSP2Triangles(9, 8, 12, 0, 12, 13, 9, 0),
    gsSP2Triangles(13, 10, 9, 0, 10, 13, 14, 0),
    gsSP2Triangles(11, 10, 14, 0, 13, 12, 15, 0),
    gsSPEndDisplayList(),
};
