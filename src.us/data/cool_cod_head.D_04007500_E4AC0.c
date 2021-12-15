#include <ultra64.h>

Vtx D_04007190_E4750[7] = {
#include "data/inc/D_04007190_E4750.inc.c"
};
Vtx D_04007200_E47C0[6] = {
#include "data/inc/D_04007200_E47C0.inc.c"
};
Vtx D_04007260_E4820[6] = {
#include "data/inc/D_04007260_E4820.inc.c"
};
Vtx D_040072C0_E4880[18] = {
#include "data/inc/D_040072C0_E4880.inc.c"
};
Vtx D_040073E0_E49A0[3] = {
#include "data/inc/D_040073E0_E49A0.inc.c"
};
Vtx D_04007410_E49D0[3] = {
#include "data/inc/D_04007410_E49D0.inc.c"
};
Vtx D_04007440_E4A00[3] = {
#include "data/inc/D_04007440_E4A00.inc.c"
};
Vtx D_04007470_E4A30[3] = {
#include "data/inc/D_04007470_E4A30.inc.c"
};
Vtx D_040074A0_E4A60[3] = {
#include "data/inc/D_040074A0_E4A60.inc.c"
};
Vtx D_040074D0_E4A90[3] = {
#include "data/inc/D_040074D0_E4A90.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_010034C0_3CD90[];

Gfx D_04007500_E4AC0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xDE, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04007190_E4750, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(0, 3, 4, 0, 4, 2, 0, 0),
    gsSP2Triangles(3, 5, 4, 0, 3, 6, 5, 0),
    gsSP1Triangle(3, 1, 6, 0),
    gsDPSetPrimColor(0, 0, 0xDE, 0xDE, 0xFF, 0xFF),
    gsSPVertex(D_04007200_E47C0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(4, 1, 3, 0, 3, 5, 4, 0),
    gsSPVertex(D_04007260_E4820, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_040072C0_E4880, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 0, 0, 6, 3, 4, 0),
    gsSP2Triangles(3, 6, 7, 0, 7, 1, 3, 0),
    gsSP2Triangles(1, 7, 8, 0, 8, 0, 1, 0),
    gsSP2Triangles(0, 8, 9, 0, 9, 5, 0, 0),
    gsSP2Triangles(4, 10, 6, 0, 5, 9, 10, 0),
    gsSP2Triangles(10, 4, 5, 0, 11, 6, 10, 0),
    gsSP2Triangles(10, 12, 11, 0, 12, 10, 9, 0),
    gsSP2Triangles(9, 13, 12, 0, 13, 8, 7, 0),
    gsSP2Triangles(13, 9, 8, 0, 13, 7, 14, 0),
    gsSP2Triangles(7, 15, 14, 0, 15, 6, 11, 0),
    gsSP2Triangles(15, 7, 6, 0, 16, 11, 12, 0),
    gsSP1Quadrangle(16, 12, 13, 17, 0),
    gsSP1Triangle(17, 11, 16, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_040073E0_E49A0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_04007410_E49D0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_04007440_E4A00, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_04007470_E4A30, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_040074A0_E4A60, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_040074D0_E4A90, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};
