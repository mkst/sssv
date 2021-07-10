#include <ultra64.h>

Vtx D_05000000_B2ED0[31] = {
#include "data/inc/D_05000000_B2ED0.inc.c"
};
Vtx D_050001F0_B30C0[31] = {
#include "data/inc/D_050001F0_B30C0.inc.c"
};
Vtx D_050003E0_B32B0[31] = {
#include "data/inc/D_050003E0_B32B0.inc.c"
};
Vtx D_050005D0_B34A0[3] = {
#include "data/inc/D_050005D0_B34A0.inc.c"
};
Vtx D_05000600_B34D0[16] = {
#include "data/inc/D_05000600_B34D0.inc.c"
};

const Gfx D_05000700_B35D0[] = {
    gsSPVertex(D_05000000_B2ED0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 7, 0),
    gsSP2Triangles(3, 10, 8, 0, 7, 9, 5, 0),
    gsSP2Triangles(4, 3, 6, 0, 8, 6, 3, 0),
    gsSP2Triangles(5, 4, 7, 0, 7, 6, 8, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 13, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 19, 20, 0),
    gsSP2Triangles(19, 16, 21, 0, 18, 21, 16, 0),
    gsSP2Triangles(20, 18, 17, 0, 21, 20, 19, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 24, 0),
    gsSP2Triangles(23, 27, 28, 0, 25, 28, 29, 0),
    gsSP2Triangles(27, 30, 29, 0, 25, 24, 28, 0),
    gsSP2Triangles(24, 26, 22, 0, 28, 24, 23, 0),
    gsSPVertex(D_050001F0_B30C0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 5, 1, 0, 6, 7, 8, 0),
    gsSP2Triangles(4, 0, 8, 0, 1, 5, 3, 0),
    gsSP2Triangles(5, 9, 10, 0, 8, 0, 6, 0),
    gsSP2Triangles(4, 1, 0, 0, 2, 6, 0, 0),
    gsSP2Triangles(3, 7, 6, 0, 7, 3, 10, 0),
    gsSP2Triangles(6, 2, 3, 0, 10, 11, 7, 0),
    gsSP2Triangles(12, 13, 14, 0, 13, 15, 14, 0),
    gsSP2Triangles(15, 12, 14, 0, 16, 17, 18, 0),
    gsSP2Triangles(17, 19, 20, 0, 19, 16, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 23, 25, 26, 0),
    gsSP2Triangles(25, 22, 27, 0, 27, 28, 29, 0),
    gsSP2Triangles(28, 30, 29, 0, 30, 27, 29, 0),
    gsSPVertex(D_050003E0_B32B0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 4, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 8, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 6, 10, 0, 9, 8, 4, 0),
    gsSP2Triangles(7, 5, 4, 0, 9, 0, 11, 0),
    gsSP2Triangles(3, 12, 11, 0, 11, 0, 3, 0),
    gsSP2Triangles(8, 10, 6, 0, 9, 1, 0, 0),
    gsSP2Triangles(10, 11, 12, 0, 4, 8, 7, 0),
    gsSP2Triangles(5, 2, 1, 0, 9, 4, 1, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 13, 17, 0),
    gsSP2Triangles(14, 16, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 19, 23, 0, 20, 22, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 25, 28, 29, 0),
    gsSP1Triangle(30, 29, 28, 0),
    gsSPVertex(D_050005D0_B34A0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000600_B34D0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(8, 10, 11, 0, 10, 12, 13, 0),
    gsSP2Triangles(2, 14, 0, 0, 4, 1, 0, 0),
    gsSP2Triangles(6, 4, 3, 0, 9, 15, 7, 0),
    gsSP2Triangles(11, 9, 8, 0, 13, 11, 10, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
