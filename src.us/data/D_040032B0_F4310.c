#include <ultra64.h>

Vtx D_040031B0_F4210[4] = {
#include "data/inc/D_040031B0_F4210.inc.c"
};
Vtx D_040031F0_F4250[4] = {
#include "data/inc/D_040031F0_F4250.inc.c"
};
Vtx D_04003230_F4290[4] = {
#include "data/inc/D_04003230_F4290.inc.c"
};
Vtx D_04003270_F42D0[4] = {
#include "data/inc/D_04003270_F42D0.inc.c"
};

extern Gfx D_010034C0_3CD90[];

Gfx D_040032B0_F4310[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_040031B0_F4210, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_040031F0_F4250, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_04003230_F4290, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_04003270_F42D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};
