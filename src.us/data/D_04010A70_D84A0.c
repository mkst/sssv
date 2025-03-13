#include <ultra64.h>

Vtx D_040107D0_D8200[31] = {
#include "data/inc/D_040107D0_D8200.inc.c"
};
Vtx D_040109C0_D83F0[11] = {
#include "data/inc/D_040109C0_D83F0.inc.c"
};

Gfx D_04010A70_D84A0[] = {
    gsSPVertex(D_040107D0_D8200, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(0, 5, 6, 0, 6, 7, 0, 0),
    gsSP2Triangles(6, 4, 3, 0, 3, 7, 6, 0),
    gsSP2Triangles(2, 5, 0, 0, 2, 1, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 13, 0),
    gsSP2Triangles(16, 15, 17, 0, 14, 11, 10, 0),
    gsSP2Triangles(17, 18, 16, 0, 9, 18, 17, 0),
    gsSP2Triangles(9, 8, 18, 0, 10, 19, 14, 0),
    gsSP2Triangles(13, 12, 15, 0, 14, 19, 12, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 25, 0, 28, 22, 26, 0),
    gsSP2Triangles(29, 30, 24, 0, 24, 23, 29, 0),
    gsSP1Triangle(25, 27, 23, 0),
    gsSPVertex(D_040109C0_D83F0, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 2, 4, 0, 9, 5, 10, 0),
    gsSP2Triangles(10, 5, 4, 0, 4, 2, 10, 0),
    gsSP1Quadrangle(10, 2, 1, 3, 0),
    gsSP1Triangle(10, 3, 9, 0),
    gsSPEndDisplayList(),
};

Vtx D_04010B28_D8558[32] = {
#include "data/inc/D_04010B28_D8558.inc.c"
};
Vtx D_04010D28_D8758[30] = {
#include "data/inc/D_04010D28_D8758.inc.c"
};
Vtx D_04010F08_D8938[30] = {
#include "data/inc/D_04010F08_D8938.inc.c"
};
Vtx D_040110E8_D8B18[32] = {
#include "data/inc/D_040110E8_D8B18.inc.c"
};
Vtx D_040112E8_D8D18[32] = {
#include "data/inc/D_040112E8_D8D18.inc.c"
};
Vtx D_040114E8_D8F18[31] = {
#include "data/inc/D_040114E8_D8F18.inc.c"
};
Vtx D_040116D8_D9108[25] = {
#include "data/inc/D_040116D8_D9108.inc.c"
};

Gfx D_04011868_D9298[] = {
    gsSPVertex(D_04010B28_D8558, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 13, 0),
    gsSP2Triangles(14, 16, 17, 0, 16, 6, 8, 0),
    gsSP2Triangles(6, 18, 7, 0, 19, 7, 18, 0),
    gsSP2Triangles(17, 20, 21, 0, 8, 22, 20, 0),
    gsSP2Triangles(7, 23, 22, 0, 21, 23, 7, 0),
    gsSP2Triangles(21, 20, 24, 0, 20, 22, 9, 0),
    gsSP2Triangles(10, 9, 22, 0, 11, 10, 23, 0),
    gsSP2Triangles(16, 14, 13, 0, 6, 25, 26, 0),
    gsSP2Triangles(27, 5, 28, 0, 29, 12, 30, 0),
    gsSP1Triangle(15, 29, 31, 0),
    gsSPVertex(D_04010D28_D8758, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 10, 0),
    gsSP2Triangles(11, 12, 9, 0, 7, 12, 13, 0),
    gsSP2Triangles(14, 15, 7, 0, 16, 17, 14, 0),
    gsSP2Triangles(18, 16, 9, 0, 15, 19, 18, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 20, 8, 0),
    gsSP2Triangles(24, 25, 23, 0, 21, 25, 26, 0),
    gsSP2Triangles(27, 28, 21, 0, 29, 5, 27, 0),
    gsSP2Triangles(3, 29, 23, 0, 28, 4, 3, 0),
    gsSPVertex(D_04010F08_D8938, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 1, 5, 7, 0),
    gsSP2Triangles(8, 9, 1, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 10, 3, 0, 9, 13, 12, 0),
    gsSP2Triangles(14, 7, 15, 0, 16, 17, 6, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 21, 22, 0),
    gsSP2Triangles(4, 2, 19, 0, 23, 4, 19, 0),
    gsSP2Triangles(17, 15, 7, 0, 24, 25, 15, 0),
    gsSP2Triangles(26, 14, 25, 0, 27, 28, 26, 0),
    gsSP2Triangles(29, 19, 2, 0, 14, 26, 29, 0),
    gsSPVertex(D_040110E8_D8B18, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 11, 0),
    gsSP2Triangles(17, 18, 16, 0, 15, 17, 16, 0),
    gsSP2Triangles(19, 20, 15, 0, 9, 16, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 24, 23, 25, 0),
    gsSP2Triangles(25, 26, 27, 0, 21, 24, 28, 0),
    gsSP2Triangles(28, 27, 29, 0, 16, 18, 24, 0),
    gsSP1Triangle(30, 20, 31, 0),
    gsSPVertex(D_040112E8_D8D18, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(0, 12, 13, 0, 14, 11, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 15, 6, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 10, 26, 0, 10, 9, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 29, 25, 31, 0),
    gsSPVertex(D_040114E8_D8F18, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(1, 4, 3, 0, 4, 5, 6, 0),
    gsSP2Triangles(5, 7, 6, 0, 5, 0, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 14, 8, 16, 0),
    gsSP2Triangles(16, 10, 17, 0, 10, 18, 17, 0),
    gsSP2Triangles(10, 12, 18, 0, 12, 15, 19, 0),
    gsSP2Triangles(15, 20, 19, 0, 15, 16, 20, 0),
    gsSP2Triangles(21, 8, 22, 0, 8, 14, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 21, 27, 0),
    gsSP2Triangles(27, 22, 28, 0, 22, 29, 28, 0),
    gsSP2Triangles(22, 23, 29, 0, 23, 26, 30, 0),
    gsSPVertex(D_040116D8_D9108, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 1, 13, 14, 0),
    gsSP2Triangles(15, 5, 4, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 0, 0),
    gsSP2Triangles(17, 16, 21, 0, 22, 23, 24, 0),
    gsSPEndDisplayList(),
};
