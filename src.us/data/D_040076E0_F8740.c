#include <ultra64.h>

Vtx D_040074E0_F8540[8] = {
#include "data/inc/D_040074E0_F8540.inc.c"
};
Vtx D_04007560_F85C0[8] = {
#include "data/inc/D_04007560_F85C0.inc.c"
};
Vtx D_040075E0_F8640[8] = {
#include "data/inc/D_040075E0_F8640.inc.c"
};
Vtx D_04007660_F86C0[8] = {
#include "data/inc/D_04007660_F86C0.inc.c"
};

Gfx D_040076E0_F8740[] = {
    gsSPVertex(D_040074E0_F8540, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSPVertex(D_04007660_F86C0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040075E0_F8640, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
    gsSPVertex(D_04007560_F85C0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsDPSetPrimColor(0, 0, 0xE7, 0x6F, 0x97, 0xFF),
    gsSPEndDisplayList(),
};
