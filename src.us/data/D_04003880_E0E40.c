#include <ultra64.h>

Vtx D_04003780_E0D40[4] = {
#include "data/inc/D_04003780_E0D40.inc.c"
};
Vtx D_040037C0_E0D80[4] = {
#include "data/inc/D_040037C0_E0D80.inc.c"
};
Vtx D_04003800_E0DC0[4] = {
#include "data/inc/D_04003800_E0DC0.inc.c"
};
Vtx D_04003840_E0E00[4] = {
#include "data/inc/D_04003840_E0E00.inc.c"
};

extern Gfx D_010034C0_3CD90[];

Gfx D_04003880_E0E40[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04003780_E0D40, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_040037C0_E0D80, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_04003800_E0DC0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_04003840_E0E00, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};
