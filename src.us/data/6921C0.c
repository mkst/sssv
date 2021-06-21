#include <ultra64.h>

Vtx D_802ED940[32] = {
#include "data/inc/D_802ED940.inc.c"
};

Vtx D_802EDB40[30] = {
#include "data/inc/D_802EDB40.inc.c"
};

Vtx D_802EDD20[32] = {
#include "data/inc/D_802EDD20.inc.c"
};

Vtx D_802EDF20[20] = {
#include "data/inc/D_802EDF20.inc.c"
};

Vtx D_802EE060[32] = {
#include "data/inc/D_802EE060.inc.c"
};

Vtx D_802EE260[31] = {
#include "data/inc/D_802EE260.inc.c"
};

Vtx D_802EE450[32] = {
#include "data/inc/D_802EE450.inc.c"
};

Vtx D_802EE650[32] = {
#include "data/inc/D_802EE650.inc.c"
};

Vtx D_802EE850[32] = {
#include "data/inc/D_802EE850.inc.c"
};

Vtx D_802EEA50[13] = {
#include "data/inc/D_802EEA50.inc.c"
};

const Gfx D_802EEB20[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_802ED940, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 0, 4, 0, 5, 4, 6, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 10, 8, 0),
    gsSP2Triangles(11, 12, 13, 0, 3, 14, 15, 0),
    gsSP2Triangles(0, 15, 13, 0, 4, 13, 12, 0),
    gsSP2Triangles(6, 12, 16, 0, 9, 8, 16, 0),
    gsSP2Triangles(17, 15, 14, 0, 14, 18, 17, 0),
    gsSP2Triangles(15, 17, 19, 0, 13, 19, 11, 0),
    gsSP2Triangles(12, 11, 20, 0, 9, 16, 20, 0),
    gsSP2Triangles(8, 10, 7, 0, 6, 7, 5, 0),
    gsSP2Triangles(19, 13, 15, 0, 4, 5, 1, 0),
    gsSP2Triangles(15, 0, 3, 0, 13, 4, 0, 0),
    gsSP2Triangles(12, 6, 4, 0, 16, 8, 6, 0),
    gsSP2Triangles(20, 16, 12, 0, 21, 17, 18, 0),
    gsSP2Triangles(18, 22, 21, 0, 17, 21, 23, 0),
    gsSP2Triangles(19, 23, 24, 0, 11, 24, 25, 0),
    gsSP2Triangles(9, 20, 25, 0, 26, 27, 28, 0),
    gsSP2Triangles(22, 29, 30, 0, 21, 30, 28, 0),
    gsSP2Triangles(23, 28, 27, 0, 24, 27, 31, 0),
    gsSPVertex(D_802EDB40, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 4, 3, 7, 0),
    gsSP2Triangles(8, 7, 9, 0, 10, 9, 11, 0),
    gsSP2Triangles(0, 2, 11, 0, 1, 12, 13, 0),
    gsSP2Triangles(14, 13, 15, 0, 7, 8, 4, 0),
    gsSP2Triangles(16, 15, 17, 0, 4, 18, 19, 0),
    gsSP2Triangles(8, 16, 18, 0, 10, 14, 16, 0),
    gsSP2Triangles(2, 1, 14, 0, 11, 2, 10, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 23, 20, 0),
    gsSP2Triangles(21, 20, 24, 0, 25, 24, 26, 0),
    gsSP2Triangles(27, 26, 28, 0, 0, 29, 28, 0),
    gsSPVertex(D_802EDD20, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 2, 0, 7, 2, 1, 0),
    gsSP2Triangles(8, 1, 9, 0, 10, 11, 9, 0),
    gsSP2Triangles(12, 5, 4, 0, 4, 13, 12, 0),
    gsSP2Triangles(5, 12, 14, 0, 2, 14, 0, 0),
    gsSP2Triangles(1, 0, 15, 0, 10, 9, 15, 0),
    gsSP2Triangles(11, 16, 17, 0, 8, 17, 18, 0),
    gsSP2Triangles(14, 2, 5, 0, 7, 18, 19, 0),
    gsSP2Triangles(5, 6, 3, 0, 2, 7, 6, 0),
    gsSP2Triangles(1, 8, 7, 0, 9, 11, 8, 0),
    gsSP2Triangles(15, 9, 1, 0, 20, 21, 22, 0),
    gsSP2Triangles(22, 23, 20, 0, 21, 20, 24, 0),
    gsSP2Triangles(25, 24, 26, 0, 27, 26, 28, 0),
    gsSP2Triangles(10, 29, 28, 0, 17, 30, 31, 0),
    gsSPVertex(D_802EDF20, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 10, 8, 0, 11, 2, 1, 0),
    gsSP2Triangles(1, 12, 11, 0, 2, 11, 13, 0),
    gsSP2Triangles(4, 13, 14, 0, 6, 14, 15, 0),
    gsSP2Triangles(9, 8, 15, 0, 10, 16, 17, 0),
    gsSP2Triangles(7, 17, 18, 0, 13, 4, 2, 0),
    gsSP2Triangles(5, 18, 19, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 10, 7, 0, 15, 8, 6, 0),
    gsDPPipeSync(),
    gsSPVertex(D_802EE060, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 0, 3, 7, 0),
    gsSP2Triangles(1, 8, 9, 0, 1, 0, 10, 0),
    gsSP2Triangles(11, 5, 12, 0, 13, 11, 14, 0),
    gsSP2Triangles(15, 13, 16, 0, 8, 15, 17, 0),
    gsSP2Triangles(13, 15, 18, 0, 15, 8, 19, 0),
    gsSP2Triangles(5, 11, 20, 0, 8, 1, 21, 0),
    gsSP2Triangles(3, 5, 22, 0, 11, 13, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 24, 28, 0),
    gsSP2Triangles(29, 27, 30, 0, 24, 27, 31, 0),
    gsSPVertex(D_802EE260, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 5, 9, 0),
    gsSP2Triangles(10, 8, 11, 0, 1, 10, 12, 0),
    gsSP2Triangles(8, 10, 13, 0, 10, 1, 14, 0),
    gsSP2Triangles(6, 5, 15, 0, 1, 0, 16, 0),
    gsSP2Triangles(17, 6, 18, 0, 5, 8, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 20, 24, 0),
    gsSP2Triangles(25, 23, 26, 0, 20, 23, 27, 0),
    gsSP2Triangles(21, 28, 29, 0, 21, 20, 30, 0),
    gsSPVertex(D_802EE450, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 5, 8, 0),
    gsSP2Triangles(3, 5, 9, 0, 5, 7, 10, 0),
    gsSP2Triangles(1, 0, 11, 0, 7, 12, 13, 0),
    gsSP2Triangles(14, 1, 15, 0, 0, 3, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 17, 21, 0),
    gsSP2Triangles(22, 20, 23, 0, 17, 20, 24, 0),
    gsSP2Triangles(18, 25, 26, 0, 18, 17, 27, 0),
    gsSP2Triangles(28, 22, 29, 0, 30, 28, 31, 0),
    gsSPVertex(D_802EE650, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(1, 0, 5, 0, 0, 3, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 3, 10, 11, 0),
    gsSP2Triangles(12, 7, 13, 0, 8, 1, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 15, 19, 0),
    gsSP2Triangles(20, 18, 21, 0, 15, 18, 22, 0),
    gsSP2Triangles(16, 23, 24, 0, 16, 15, 25, 0),
    gsSP2Triangles(26, 20, 27, 0, 28, 26, 29, 0),
    gsSP1Triangle(30, 28, 31, 0),
    gsSPVertex(D_802EE850, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
    gsSP2Triangles(1, 0, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(0, 9, 10, 0, 11, 6, 12, 0),
    gsSP2Triangles(7, 3, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 14, 18, 0, 19, 17, 20, 0),
    gsSP2Triangles(14, 17, 21, 0, 15, 22, 23, 0),
    gsSP2Triangles(15, 14, 24, 0, 25, 19, 26, 0),
    gsSP2Triangles(27, 25, 28, 0, 29, 27, 30, 0),
    gsSP1Triangle(22, 29, 31, 0),
    gsSPVertex(D_802EEA50, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 3, 8, 9, 0),
    gsSP2Triangles(10, 5, 11, 0, 6, 0, 12, 0),
    gsSPEndDisplayList(),
};
