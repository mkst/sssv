#include <ultra64.h>

Vtx D_050016F0_C5EA0[8] = {
#include "data/inc/D_050016F0_C5EA0.inc.c"
};
Vtx D_05001770_C5F20[32] = {
#include "data/inc/D_05001770_C5F20.inc.c"
};
Vtx D_05001970_C6120[32] = {
#include "data/inc/D_05001970_C6120.inc.c"
};
Vtx D_05001B70_C6320[30] = {
#include "data/inc/D_05001B70_C6320.inc.c"
};
Vtx D_05001D50_C6500[31] = {
#include "data/inc/D_05001D50_C6500.inc.c"
};
Vtx D_05001F40_C66F0[32] = {
#include "data/inc/D_05001F40_C66F0.inc.c"
};
Vtx D_05002140_C68F0[32] = {
#include "data/inc/D_05002140_C68F0.inc.c"
};
Vtx D_05002340_C6AF0[31] = {
#include "data/inc/D_05002340_C6AF0.inc.c"
};
Vtx D_05002530_C6CE0[24] = {
#include "data/inc/D_05002530_C6CE0.inc.c"
};

Gfx D_050026B0_C6E60[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_050016F0_C5EA0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05001770_C5F20, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
    gsSP2Triangles(0, 5, 6, 0, 1, 6, 7, 0),
    gsSP2Triangles(3, 7, 8, 0, 4, 8, 5, 0),
    gsSP2Triangles(9, 6, 5, 0, 9, 7, 6, 0),
    gsSP2Triangles(9, 8, 7, 0, 9, 5, 8, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 10, 12, 0),
    gsSP2Triangles(14, 13, 15, 0, 16, 15, 17, 0),
    gsSP2Triangles(18, 17, 13, 0, 15, 12, 11, 0),
    gsSP2Triangles(17, 11, 10, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 24, 26, 0),
    gsSP2Triangles(27, 26, 23, 0, 20, 22, 25, 0),
    gsSP2Triangles(28, 25, 27, 0, 19, 27, 22, 0),
    gsSP2Triangles(20, 28, 21, 0, 28, 19, 21, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05001970_C6120, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 6, 5, 0),
    gsSP2Triangles(0, 9, 8, 0, 10, 11, 9, 0),
    gsSP2Triangles(3, 8, 11, 0, 9, 7, 6, 0),
    gsSP2Triangles(11, 5, 7, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(15, 20, 21, 0, 22, 21, 19, 0),
    gsSP2Triangles(20, 14, 13, 0, 21, 13, 12, 0),
    gsSP2Triangles(19, 12, 14, 0, 18, 17, 23, 0),
    gsSP2Triangles(22, 23, 16, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 29, 31, 0),
    gsSPVertex(D_05001B70_C6320, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 0, 0, 7, 0, 4, 0),
    gsSP2Triangles(3, 6, 8, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 14, 16, 0, 17, 16, 13, 0),
    gsSP2Triangles(10, 12, 15, 0, 18, 15, 17, 0),
    gsSP2Triangles(9, 17, 12, 0, 10, 18, 11, 0),
    gsSP2Triangles(18, 9, 11, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 27, 19, 0, 29, 19, 26, 0),
    gsSPVertex(D_05001D50_C6500, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 9, 1, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(11, 15, 16, 0, 12, 16, 14, 0),
    gsSP2Triangles(17, 12, 13, 0, 18, 19, 20, 0),
    gsSP2Triangles(17, 20, 21, 0, 18, 13, 11, 0),
    gsSP2Triangles(10, 21, 19, 0, 16, 15, 14, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 27, 29, 0, 30, 29, 26, 0),
    gsSP1Triangle(23, 25, 28, 0),
    gsSPVertex(D_05001F40_C66F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 0, 6, 0, 0, 3, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 11, 0, 14, 9, 13, 0),
    gsSP2Triangles(15, 16, 17, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 18, 0, 17, 19, 21, 0),
    gsSP2Triangles(22, 20, 16, 0, 23, 17, 20, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 25, 0),
    gsSP2Triangles(29, 26, 28, 0, 25, 30, 31, 0),
    gsSPVertex(D_05002140_C68F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 7, 9, 0),
    gsSP2Triangles(10, 9, 6, 0, 11, 12, 13, 0),
    gsSP2Triangles(13, 6, 9, 0, 14, 9, 7, 0),
    gsSP2Triangles(12, 7, 6, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 14, 12, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 19, 18, 0, 21, 22, 19, 0),
    gsSP2Triangles(23, 18, 22, 0, 24, 21, 20, 0),
    gsSP2Triangles(25, 23, 21, 0, 26, 20, 23, 0),
    gsSP2Triangles(27, 22, 18, 0, 28, 19, 22, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05002340_C6AF0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(2, 5, 6, 0, 1, 7, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 10, 12, 0),
    gsSP2Triangles(9, 14, 15, 0, 12, 16, 14, 0),
    gsSP2Triangles(10, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(19, 26, 24, 0, 18, 25, 26, 0),
    gsSP2Triangles(27, 22, 28, 0, 29, 19, 23, 0),
    gsSP1Triangle(30, 23, 18, 0),
    gsSPVertex(D_05002530_C6CE0, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 3, 7, 0),
    gsSP2Triangles(10, 8, 3, 0, 8, 11, 4, 0),
    gsSP2Triangles(12, 4, 11, 0, 13, 5, 4, 0),
    gsSP2Triangles(7, 5, 11, 0, 14, 11, 5, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 16, 0),
    gsSP2Triangles(20, 17, 19, 0, 16, 21, 22, 0),
    gsSP2Triangles(19, 23, 21, 0, 17, 22, 23, 0),
    gsSPEndDisplayList(),
};
