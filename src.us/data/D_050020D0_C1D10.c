#include <ultra64.h>

Vtx D_05000D70_C09B0[8] = {
#include "data/inc/D_05000D70_C09B0.inc.c"
};
Vtx D_05000DF0_C0A30[31] = {
#include "data/inc/D_05000DF0_C0A30.inc.c"
};
Vtx D_05000FE0_C0C20[31] = {
#include "data/inc/D_05000FE0_C0C20.inc.c"
};
Vtx D_050011D0_C0E10[30] = {
#include "data/inc/D_050011D0_C0E10.inc.c"
};
Vtx D_050013B0_C0FF0[32] = {
#include "data/inc/D_050013B0_C0FF0.inc.c"
};
Vtx D_050015B0_C11F0[32] = {
#include "data/inc/D_050015B0_C11F0.inc.c"
};
Vtx D_050017B0_C13F0[32] = {
#include "data/inc/D_050017B0_C13F0.inc.c"
};
Vtx D_050019B0_C15F0[31] = {
#include "data/inc/D_050019B0_C15F0.inc.c"
};
Vtx D_05001BA0_C17E0[31] = {
#include "data/inc/D_05001BA0_C17E0.inc.c"
};
Vtx D_05001D90_C19D0[30] = {
#include "data/inc/D_05001D90_C19D0.inc.c"
};
Vtx D_05001F70_C1BB0[22] = {
#include "data/inc/D_05001F70_C1BB0.inc.c"
};

const Gfx D_050020D0_C1D10[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000D70_C09B0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05000DF0_C0A30, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 4, 7, 9, 0),
    gsSP1Quadrangle(0, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 15, 18, 20, 0),
    gsSP1Quadrangle(11, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 23, 0),
    gsSP2Triangles(27, 24, 26, 0, 28, 22, 27, 0),
    gsSP2Triangles(29, 25, 22, 0, 30, 27, 25, 0),
    gsSP2Triangles(24, 27, 22, 0, 23, 22, 25, 0),
    gsSP2Triangles(26, 25, 27, 0, 27, 30, 28, 0),
    gsSP2Triangles(22, 28, 29, 0, 25, 29, 30, 0),
    gsSPVertex(D_05000FE0_C0C20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 8, 9, 2, 0),
    gsSP2Triangles(4, 2, 9, 0, 6, 5, 9, 0),
    gsSP2Triangles(0, 10, 11, 0, 2, 1, 8, 0),
    gsSP2Triangles(6, 9, 8, 0, 0, 11, 1, 0),
    gsSP2Triangles(12, 13, 14, 0, 6, 8, 11, 0),
    gsSP2Triangles(11, 8, 1, 0, 9, 5, 4, 0),
    gsSP2Triangles(6, 11, 10, 0, 0, 3, 10, 0),
    gsSP2Triangles(10, 3, 7, 0, 6, 10, 7, 0),
    gsSP2Triangles(12, 15, 13, 0, 5, 7, 3, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 19, 20, 0),
    gsSP2Triangles(19, 16, 21, 0, 21, 18, 22, 0),
    gsSP2Triangles(18, 20, 23, 0, 20, 21, 24, 0),
    gsSP2Triangles(18, 21, 16, 0, 20, 18, 17, 0),
    gsSP2Triangles(21, 20, 19, 0, 22, 24, 21, 0),
    gsSP2Triangles(23, 22, 18, 0, 24, 23, 20, 0),
    gsSP2Triangles(13, 25, 14, 0, 26, 27, 28, 0),
    gsSP1Triangle(26, 29, 30, 0),
    gsSPVertex(D_050011D0_C0E10, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(2, 9, 0, 0, 2, 1, 5, 0),
    gsSP2Triangles(9, 6, 8, 0, 10, 11, 12, 0),
    gsSP2Triangles(6, 2, 5, 0, 9, 2, 6, 0),
    gsSP2Triangles(3, 4, 1, 0, 7, 6, 5, 0),
    gsSP2Triangles(7, 13, 8, 0, 14, 13, 7, 0),
    gsSP2Triangles(14, 7, 5, 0, 15, 16, 17, 0),
    gsSP2Triangles(13, 14, 4, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 22, 0),
    gsSP2Triangles(26, 23, 25, 0, 22, 20, 19, 0),
    gsSP2Triangles(25, 18, 20, 0, 23, 19, 18, 0),
    gsSP2Triangles(23, 26, 21, 0, 22, 21, 24, 0),
    gsSP2Triangles(25, 24, 26, 0, 19, 23, 22, 0),
    gsSP2Triangles(20, 22, 25, 0, 18, 25, 23, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_050013B0_C0FF0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 0, 5, 0, 6, 7, 1, 0),
    gsSP2Triangles(7, 8, 3, 0, 8, 6, 0, 0),
    gsSP2Triangles(2, 5, 0, 0, 4, 2, 1, 0),
    gsSP2Triangles(5, 4, 3, 0, 1, 0, 6, 0),
    gsSP2Triangles(3, 1, 7, 0, 0, 3, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 15, 0),
    gsSP2Triangles(14, 16, 15, 0, 17, 18, 15, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 21, 25, 0),
    gsSP2Triangles(21, 20, 26, 0, 29, 30, 31, 0),
    gsSPVertex(D_050015B0_C11F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 1, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 2, 15, 0),
    gsSP2Triangles(16, 6, 9, 0, 3, 6, 16, 0),
    gsSP2Triangles(17, 14, 18, 0, 3, 5, 19, 0),
    gsSP2Triangles(20, 21, 13, 0, 22, 16, 1, 0),
    gsSP2Triangles(3, 19, 23, 0, 24, 25, 11, 0),
    gsSP2Triangles(12, 17, 20, 0, 15, 21, 18, 0),
    gsSP2Triangles(26, 27, 17, 0, 25, 26, 12, 0),
    gsSP2Triangles(19, 5, 26, 0, 2, 10, 28, 0),
    gsSP2Triangles(13, 21, 29, 0, 29, 21, 28, 0),
    gsSP2Triangles(28, 21, 15, 0, 3, 16, 22, 0),
    gsSP2Triangles(29, 28, 10, 0, 14, 17, 27, 0),
    gsSP2Triangles(27, 26, 5, 0, 0, 27, 4, 0),
    gsSP2Triangles(2, 14, 0, 0, 8, 30, 31, 0),
    gsSPVertex(D_050017B0_C13F0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 2, 10, 0),
    gsSP2Triangles(7, 11, 12, 0, 2, 13, 14, 0),
    gsSP2Triangles(5, 0, 9, 0, 11, 3, 15, 0),
    gsSP2Triangles(12, 15, 16, 0, 15, 5, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 6, 1, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP2Triangles(20, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_050019B0_C15F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 0, 2, 0, 6, 7, 1, 0),
    gsSP1Quadrangle(6, 1, 8, 9, 0),
    gsSP2Triangles(6, 9, 10, 0, 11, 12, 4, 0),
    gsSP2Triangles(11, 4, 13, 0, 1, 7, 14, 0),
    gsSP2Triangles(1, 14, 2, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 17, 0, 16, 18, 17, 0),
    gsSP2Triangles(19, 20, 17, 0, 21, 22, 23, 0),
    gsSP2Triangles(23, 22, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 26, 0, 30, 27, 24, 0),
    gsSPVertex(D_05001BA0_C17E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(2, 5, 6, 0, 5, 2, 1, 0),
    gsSP2Triangles(3, 7, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(3, 8, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(7, 10, 11, 0, 3, 0, 9, 0),
    gsSP2Triangles(2, 10, 0, 0, 10, 9, 0, 0),
    gsSP2Triangles(2, 11, 10, 0, 4, 1, 0, 0),
    gsSP2Triangles(6, 11, 2, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 12, 14, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 21, 0),
    gsSP2Triangles(12, 18, 24, 0, 18, 14, 25, 0),
    gsSP2Triangles(21, 23, 26, 0, 12, 26, 23, 0),
    gsSP1Quadrangle(19, 27, 28, 29, 0),
    gsSP2Triangles(19, 29, 20, 0, 21, 20, 30, 0),
    gsSP2Triangles(21, 30, 22, 0, 12, 23, 22, 0),
    gsSP2Triangles(19, 25, 27, 0, 27, 25, 14, 0),
    gsSPVertex(D_05001D90_C19D0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 0, 8, 0),
    gsSP2Triangles(1, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 22, 0, 19, 13, 23, 0),
    gsSP2Triangles(19, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(10, 26, 25, 0, 2, 7, 0, 0),
    gsSP2Triangles(8, 28, 7, 0, 10, 2, 1, 0),
    gsSP2Triangles(29, 27, 9, 0, 26, 10, 9, 0),
    gsSP2Triangles(28, 25, 29, 0, 27, 29, 25, 0),
    gsSP2Triangles(25, 7, 10, 0, 25, 28, 7, 0),
    gsSPVertex(D_05001F70_C1BB0, 22, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 4, 7, 9, 0),
    gsSP1Quadrangle(0, 8, 9, 10, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 15, 18, 20, 0),
    gsSP1Quadrangle(11, 19, 20, 21, 0),
    gsSPEndDisplayList(),
};
