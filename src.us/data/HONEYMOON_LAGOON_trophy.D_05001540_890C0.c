#include <ultra64.h>

Vtx D_05000820_883A0[8] = {
#include "data/inc/D_05000820_883A0.inc.c"
};
Vtx D_050008A0_88420[32] = {
#include "data/inc/D_050008A0_88420.inc.c"
};
Vtx D_05000AA0_88620[31] = {
#include "data/inc/D_05000AA0_88620.inc.c"
};
Vtx D_05000C90_88810[3] = {
#include "data/inc/D_05000C90_88810.inc.c"
};
Vtx D_05000CC0_88840[31] = {
#include "data/inc/D_05000CC0_88840.inc.c"
};
Vtx D_05000EB0_88A30[30] = {
#include "data/inc/D_05000EB0_88A30.inc.c"
};
Vtx D_05001090_88C10[30] = {
#include "data/inc/D_05001090_88C10.inc.c"
};
Vtx D_05001270_88DF0[30] = {
#include "data/inc/D_05001270_88DF0.inc.c"
};
Vtx D_05001450_88FD0[15] = {
#include "data/inc/D_05001450_88FD0.inc.c"
};

Gfx D_05001540_890C0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000820_883A0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050008A0_88420, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 12, 19, 10, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05000AA0_88620, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 14, 27, 12, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05000C90_88810, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000CC0_88840, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05000EB0_88A30, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05001090_88C10, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05001270_88DF0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05001450_88FD0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPEndDisplayList(),
};
