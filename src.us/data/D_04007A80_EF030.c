#include <ultra64.h>

Vtx D_04007160_EE710[8] = {
#include "data/inc/D_04007160_EE710.inc.c"
};
Vtx D_040071E0_EE790[31] = {
#include "data/inc/D_040071E0_EE790.inc.c"
};
Vtx D_040073D0_EE980[30] = {
#include "data/inc/D_040073D0_EE980.inc.c"
};
Vtx D_040075B0_EEB60[31] = {
#include "data/inc/D_040075B0_EEB60.inc.c"
};
Vtx D_040077A0_EED50[32] = {
#include "data/inc/D_040077A0_EED50.inc.c"
};
Vtx D_040079A0_EEF50[14] = {
#include "data/inc/D_040079A0_EEF50.inc.c"
};

Gfx D_04007A80_EF030[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04007160_EE710, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_040071E0_EE790, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 10, 12, 0, 1, 8, 11, 0),
    gsSP2Triangles(2, 11, 13, 0, 14, 13, 15, 0),
    gsSP2Triangles(4, 16, 17, 0, 10, 18, 19, 0),
    gsSP2Triangles(20, 21, 12, 0, 4, 3, 22, 0),
    gsSP2Triangles(13, 12, 21, 0, 21, 20, 23, 0),
    gsSP2Triangles(24, 23, 25, 0, 9, 25, 18, 0),
    gsSP2Triangles(1, 0, 26, 0, 27, 16, 21, 0),
    gsSP2Triangles(11, 2, 1, 0, 13, 14, 2, 0),
    gsSP2Triangles(2, 28, 0, 0, 14, 29, 28, 0),
    gsSP2Triangles(22, 7, 29, 0, 5, 30, 3, 0),
    gsSP2Triangles(12, 13, 11, 0, 21, 15, 13, 0),
    gsSP2Triangles(15, 21, 16, 0, 15, 22, 14, 0),
    gsSP2Triangles(16, 4, 15, 0, 17, 5, 4, 0),
    gsSP2Triangles(10, 11, 8, 0, 25, 9, 24, 0),
    gsSP2Triangles(28, 2, 14, 0, 29, 14, 22, 0),
    gsSP2Triangles(22, 15, 4, 0, 18, 10, 9, 0),
    gsSP2Triangles(19, 12, 10, 0, 12, 19, 20, 0),
    gsSP2Triangles(7, 22, 3, 0, 6, 3, 30, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_040073D0_EE980, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(5, 4, 3, 0, 6, 7, 3, 0),
    gsSP2Triangles(0, 2, 8, 0, 7, 5, 3, 0),
    gsSP2Triangles(6, 3, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 10, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 17, 13, 0, 10, 12, 18, 0),
    gsSP2Triangles(17, 15, 13, 0, 16, 13, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 20, 0),
    gsSP2Triangles(25, 24, 23, 0, 26, 27, 23, 0),
    gsSP2Triangles(20, 22, 28, 0, 27, 25, 23, 0),
    gsSP1Triangle(26, 23, 29, 0),
    gsSPVertex(D_040075B0_EEB60, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(5, 4, 3, 0, 6, 7, 3, 0),
    gsSP2Triangles(0, 2, 8, 0, 7, 5, 3, 0),
    gsSP2Triangles(6, 3, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 10, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 17, 13, 0, 10, 12, 18, 0),
    gsSP2Triangles(17, 15, 13, 0, 16, 13, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 24, 23, 0, 27, 28, 23, 0),
    gsSP2Triangles(23, 25, 20, 0, 28, 26, 23, 0),
    gsSP2Triangles(27, 23, 29, 0, 20, 22, 30, 0),
    gsSPVertex(D_040077A0_EED50, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 7, 8, 3, 0),
    gsSP2Triangles(3, 5, 0, 0, 8, 6, 3, 0),
    gsSP2Triangles(7, 3, 9, 0, 0, 2, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 15, 14, 0, 18, 19, 14, 0),
    gsSP2Triangles(14, 16, 11, 0, 19, 17, 14, 0),
    gsSP2Triangles(18, 14, 20, 0, 11, 13, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 26, 25, 0, 29, 30, 25, 0),
    gsSP2Triangles(25, 27, 22, 0, 30, 28, 25, 0),
    gsSP1Triangle(29, 25, 31, 0),
    gsSPVertex(D_040079A0_EEF50, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 7, 6, 0),
    gsSP2Triangles(10, 11, 6, 0, 6, 8, 3, 0),
    gsSP2Triangles(11, 9, 6, 0, 10, 6, 12, 0),
    gsSP1Triangle(3, 5, 13, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
