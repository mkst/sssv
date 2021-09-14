#include <ultra64.h>

Vtx D_05004980_84110[18] = {
#include "data/inc/D_05004980_84110.inc.c"
};
Vtx D_05004AA0_84230[31] = {
#include "data/inc/D_05004AA0_84230.inc.c"
};
Vtx D_05004C90_84420[14] = {
#include "data/inc/D_05004C90_84420.inc.c"
};
Vtx D_05004D70_84500[3] = {
#include "data/inc/D_05004D70_84500.inc.c"
};
Vtx D_05004DA0_84530[6] = {
#include "data/inc/D_05004DA0_84530.inc.c"
};

const Gfx D_05004E00_84590[] = {
    gsSPVertex(D_05004980_84110, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 5, 7, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(10, 12, 11, 0, 13, 12, 10, 0),
    gsSP2Triangles(14, 6, 2, 0, 15, 6, 14, 0),
    gsSP2Triangles(0, 6, 15, 0, 1, 2, 14, 0),
    gsSP2Triangles(9, 10, 13, 0, 8, 11, 12, 0),
    gsSP2Triangles(16, 5, 4, 0, 7, 5, 16, 0),
    gsSP2Triangles(17, 7, 16, 0, 7, 17, 3, 0),
    gsSP2Triangles(15, 14, 1, 0, 1, 0, 15, 0),
    gsSPVertex(D_05004AA0_84230, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 9, 10, 0),
    gsSP2Triangles(8, 9, 6, 0, 10, 11, 6, 0),
    gsSP2Triangles(11, 12, 6, 0, 13, 9, 14, 0),
    gsSP2Triangles(10, 9, 13, 0, 15, 6, 12, 0),
    gsSP2Triangles(16, 4, 17, 0, 18, 10, 13, 0),
    gsSP2Triangles(16, 17, 19, 0, 19, 17, 20, 0),
    gsSP2Triangles(20, 4, 21, 0, 17, 4, 20, 0),
    gsSP2Triangles(22, 23, 21, 0, 18, 13, 24, 0),
    gsSP2Triangles(20, 21, 23, 0, 5, 4, 16, 0),
    gsSP2Triangles(13, 14, 24, 0, 15, 7, 6, 0),
    gsSP2Triangles(2, 1, 25, 0, 21, 4, 22, 0),
    gsSP2Triangles(26, 5, 16, 0, 5, 26, 3, 0),
    gsSP2Triangles(27, 11, 10, 0, 18, 27, 10, 0),
    gsSP2Triangles(28, 24, 13, 0, 29, 30, 13, 0),
    gsSP1Triangle(13, 14, 29, 0),
    gsSPVertex(D_05004C90_84420, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(3, 5, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 13, 7, 0, 13, 3, 7, 0),
    gsSP1Triangle(0, 3, 13, 0),
    gsSPVertex(D_05004D70_84500, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_05004DA0_84530, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 0, 4, 0),
    gsSP1Triangle(1, 0, 5, 0),
    gsSPEndDisplayList(),
};
