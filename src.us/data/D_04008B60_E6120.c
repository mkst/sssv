#include <ultra64.h>

Vtx D_04007EB0_E5470[25] = {
#include "data/inc/D_04007EB0_E5470.inc.c"
};
Vtx D_04008040_E5600[31] = {
#include "data/inc/D_04008040_E5600.inc.c"
};
Vtx D_04008230_E57F0[32] = {
#include "data/inc/D_04008230_E57F0.inc.c"
};
Vtx D_04008430_E59F0[32] = {
#include "data/inc/D_04008430_E59F0.inc.c"
};
Vtx D_04008630_E5BF0[31] = {
#include "data/inc/D_04008630_E5BF0.inc.c"
};
Vtx D_04008820_E5DE0[31] = {
#include "data/inc/D_04008820_E5DE0.inc.c"
};
Vtx D_04008A10_E5FD0[21] = {
#include "data/inc/D_04008A10_E5FD0.inc.c"
};

Gfx D_04008B60_E6120[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04007EB0_E5470, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 1, 4, 0, 2, 1, 24, 0),
    gsSP2Triangles(24, 19, 2, 0, 16, 19, 24, 0),
    gsSP2Triangles(24, 13, 16, 0, 10, 13, 24, 0),
    gsSP2Triangles(24, 7, 10, 0, 4, 7, 24, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04008040_E5600, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 1, 3, 0, 4, 5, 6, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 6, 0),
    gsSP2Triangles(6, 5, 8, 0, 9, 8, 10, 0),
    gsSP2Triangles(10, 11, 9, 0, 11, 7, 6, 0),
    gsSP2Triangles(6, 9, 11, 0, 12, 7, 11, 0),
    gsSP2Triangles(12, 4, 7, 0, 12, 10, 4, 0),
    gsSP2Triangles(12, 11, 10, 0, 13, 14, 15, 0),
    gsSP2Triangles(15, 16, 13, 0, 17, 18, 13, 0),
    gsSP2Triangles(13, 14, 17, 0, 19, 17, 18, 0),
    gsSP2Triangles(18, 20, 19, 0, 13, 16, 20, 0),
    gsSP2Triangles(20, 18, 13, 0, 20, 16, 21, 0),
    gsSP2Triangles(16, 15, 21, 0, 15, 19, 21, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 24, 0, 27, 28, 29, 0),
    gsSP2Triangles(24, 29, 22, 0, 29, 24, 27, 0),
    gsSP2Triangles(26, 30, 27, 0, 24, 23, 25, 0),
    gsSP1Triangle(27, 24, 26, 0),
    gsSPVertex(D_04008230_E57F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 0, 4, 0, 5, 4, 6, 0),
    gsSP2Triangles(4, 5, 1, 0, 7, 8, 9, 0),
    gsSP2Triangles(6, 10, 5, 0, 9, 11, 7, 0),
    gsSP2Triangles(5, 10, 12, 0, 1, 5, 13, 0),
    gsSP2Triangles(2, 1, 14, 0, 12, 13, 5, 0),
    gsSP2Triangles(13, 14, 1, 0, 14, 15, 2, 0),
    gsSP2Triangles(14, 8, 7, 0, 7, 15, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 17, 0),
    gsSP2Triangles(21, 22, 23, 0, 21, 24, 25, 0),
    gsSP2Triangles(26, 21, 27, 0, 28, 26, 20, 0),
    gsSP2Triangles(22, 21, 26, 0, 29, 30, 31, 0),
    gsSPVertex(D_04008430_E59F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 3, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 12, 14, 0),
    gsSP2Triangles(13, 15, 16, 0, 10, 13, 17, 0),
    gsSP2Triangles(18, 8, 19, 0, 6, 20, 7, 0),
    gsSP2Triangles(21, 18, 22, 0, 0, 23, 24, 0),
    gsSP2Triangles(25, 0, 26, 0, 27, 28, 26, 0),
    gsSP2Triangles(29, 26, 24, 0, 30, 21, 31, 0),
    gsSPVertex(D_04008630_E5BF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 8, 10, 0),
    gsSP2Triangles(9, 11, 12, 0, 6, 9, 13, 0),
    gsSP2Triangles(4, 14, 5, 0, 14, 15, 5, 0),
    gsSP2Triangles(15, 0, 2, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 16, 20, 0, 21, 22, 20, 0),
    gsSP2Triangles(23, 20, 18, 0, 24, 18, 25, 0),
    gsSP2Triangles(26, 25, 27, 0, 28, 27, 29, 0),
    gsSP1Triangle(30, 29, 13, 0),
    gsSPVertex(D_04008820_E5DE0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 8, 0, 5, 12, 13, 0),
    gsSP2Triangles(12, 14, 15, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 17, 0, 21, 22, 17, 0),
    gsSP2Triangles(22, 23, 18, 0, 14, 24, 25, 0),
    gsSP2Triangles(24, 26, 27, 0, 28, 29, 8, 0),
    gsSP1Triangle(29, 30, 9, 0),
    gsSPVertex(D_04008A10_E5FD0, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 14, 9, 0),
    gsSP2Triangles(14, 15, 10, 0, 16, 17, 1, 0),
    gsSP2Triangles(17, 18, 2, 0, 17, 19, 7, 0),
    gsSP1Triangle(16, 20, 19, 0),
    gsSPEndDisplayList(),
};
