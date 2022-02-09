#include <ultra64.h>

Vtx D_0400C0C0_FD120[6] = {
#include "data/inc/D_0400C0C0_FD120.inc.c"
};
Vtx D_0400C120_FD180[5] = {
#include "data/inc/D_0400C120_FD180.inc.c"
};

extern Gfx D_01003508_3CDD8[];

Gfx D_0400C170_FD1D0[] = {
    gsSPDisplayList(D_01003508_3CDD8),
    gsSPVertex(D_0400C0C0_FD120, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 2, 4, 0, 0),
    gsSP2Triangles(5, 3, 4, 0, 5, 1, 3, 0),
    gsSP2Triangles(2, 4, 5, 0, 5, 1, 2, 0),
    gsSPVertex(D_0400C120_FD180, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSPEndDisplayList(),
};
