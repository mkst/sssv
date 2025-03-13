#include <ultra64.h>

Vtx D_0400A050_FB0B0[3] = {
#include "data/inc/D_0400A050_FB0B0.inc.c"
};
Vtx D_0400A080_FB0E0[3] = {
#include "data/inc/D_0400A080_FB0E0.inc.c"
};
Vtx D_0400A0B0_FB110[10] = {
#include "data/inc/D_0400A0B0_FB110.inc.c"
};
Vtx D_0400A150_FB1B0[4] = {
#include "data/inc/D_0400A150_FB1B0.inc.c"
};
Vtx D_0400A190_FB1F0[14] = {
#include "data/inc/D_0400A190_FB1F0.inc.c"
};
Vtx D_0400A270_FB2D0[4] = {
#include "data/inc/D_0400A270_FB2D0.inc.c"
};
Vtx D_0400A2B0_FB310[8] = {
#include "data/inc/D_0400A2B0_FB310.inc.c"
};
Vtx D_0400A330_FB390[4] = {
#include "data/inc/D_0400A330_FB390.inc.c"
};
Vtx D_0400A370_FB3D0[3] = {
#include "data/inc/D_0400A370_FB3D0.inc.c"
};
Vtx D_0400A3A0_FB400[12] = {
#include "data/inc/D_0400A3A0_FB400.inc.c"
};
Vtx D_0400A460_FB4C0[8] = {
#include "data/inc/D_0400A460_FB4C0.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_0400A4E0_FB540[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_0400A080_FB0E0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_0400A370_FB3D0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x71, 0x7B, 0xFF),
    gsSPVertex(D_0400A050_FB0B0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPVertex(D_0400A0B0_FB110, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 4, 3, 0),
    gsSP2Triangles(5, 4, 2, 0, 5, 6, 4, 0),
    gsSP1Triangle(7, 9, 8, 0),
    gsSPVertex(D_0400A150_FB1B0, 4, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSPVertex(D_0400A190_FB1F0, 14, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 2, 0, 5, 4, 6, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 2, 5, 0),
    gsSP2Triangles(5, 9, 8, 0, 5, 10, 9, 0),
    gsSP2Triangles(11, 10, 12, 0, 10, 11, 13, 0),
    gsSPVertex(D_0400A270_FB2D0, 4, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSPVertex(D_0400A2B0_FB310, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSPVertex(D_0400A330_FB390, 4, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSPVertex(D_0400A3A0_FB400, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(7, 4, 8, 0, 9, 11, 10, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x71, 0x7B, 0xFF),
    gsSPVertex(D_0400A460_FB4C0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSPEndDisplayList(),
};
