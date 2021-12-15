#include <ultra64.h>

Vtx D_040085C0_108310[6] = {
#include "data/inc/D_040085C0_108310.inc.c"
};
Vtx D_04008620_108370[15] = {
#include "data/inc/D_04008620_108370.inc.c"
};
Vtx D_04008710_108460[15] = {
#include "data/inc/D_04008710_108460.inc.c"
};
Vtx D_04008800_108550[14] = {
#include "data/inc/D_04008800_108550.inc.c"
};
// FIXME
Vtx D_040089E0_108630[1] = {
#include "data/inc/D_040089E0_108630.inc.c"
};

extern Gfx D_01003708_3CFD8[];
extern Gfx D_010036D0_3CFA0[];

Gfx D_040088F0_108640[] = {
    gsSPDisplayList(D_01003708_3CFD8),
    gsDPSetPrimColor(0, 0, 0x00, 0x96, 0x00, 0xFF),
    gsSPVertex(D_040085C0_108310, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPDisplayList(D_010036D0_3CFA0),
    gsDPSetPrimColor(0, 0, 0x00, 0x64, 0x00, 0xFF),
    gsSPVertex(D_04008620_108370, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPVertex(D_04008710_108460, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPVertex(D_04008800_108550, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSPEndDisplayList(),
};
