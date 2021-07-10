#include <ultra64.h>


Vtx D_05002A70_82200[31] = {
#include "data/inc/D_05002A70_82200.inc.c"
};
Vtx D_05002C60_823F0[31] = {
#include "data/inc/D_05002C60_823F0.inc.c"
};
Vtx D_05002E50_825E0[31] = {
#include "data/inc/D_05002E50_825E0.inc.c"
};
Vtx D_05003040_827D0[32] = {
#include "data/inc/D_05003040_827D0.inc.c"
};
Vtx D_05003240_829D0[24] = {
#include "data/inc/D_05003240_829D0.inc.c"
};

const Gfx D_050033C0_82B50[] = {
    gsSPVertex(D_05002A70_82200, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 0, 2, 0, 6, 0, 7, 0),
    gsSP2Triangles(1, 6, 8, 0, 3, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 6, 17, 18, 0),
    gsSP2Triangles(19, 9, 8, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 6, 1, 0, 0),
    gsSP2Triangles(8, 3, 1, 0, 3, 9, 26, 0),
    gsSP2Triangles(17, 6, 14, 0, 18, 8, 6, 0),
    gsSP2Triangles(27, 24, 23, 0, 15, 14, 13, 0),
    gsSP2Triangles(23, 28, 27, 0, 19, 20, 29, 0),
    gsSP2Triangles(30, 27, 11, 0, 27, 28, 11, 0),
    gsSP2Triangles(30, 11, 10, 0, 27, 30, 29, 0),
    gsSP1Triangle(29, 25, 24, 0),
    gsSPVertex(D_05002C60_823F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 8, 10, 0, 10, 12, 13, 0),
    gsSP2Triangles(11, 10, 13, 0, 5, 7, 11, 0),
    gsSP2Triangles(5, 13, 14, 0, 5, 11, 13, 0),
    gsSP2Triangles(15, 8, 16, 0, 7, 6, 17, 0),
    gsSP2Triangles(15, 4, 8, 0, 18, 7, 17, 0),
    gsSP2Triangles(19, 20, 21, 0, 3, 21, 2, 0),
    gsSP2Triangles(15, 3, 4, 0, 18, 17, 19, 0),
    gsSP2Triangles(20, 22, 21, 0, 21, 0, 2, 0),
    gsSP2Triangles(10, 9, 23, 0, 9, 2, 24, 0),
    gsSP2Triangles(2, 1, 24, 0, 5, 14, 25, 0),
    gsSP2Triangles(19, 26, 27, 0, 28, 20, 17, 0),
    gsSP2Triangles(29, 30, 20, 0, 28, 29, 20, 0),
    gsSPVertex(D_05002E50_825E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 5, 8, 0),
    gsSP2Triangles(2, 1, 7, 0, 7, 9, 2, 0),
    gsSP2Triangles(2, 4, 0, 0, 4, 6, 3, 0),
    gsSP2Triangles(6, 8, 5, 0, 8, 9, 7, 0),
    gsSP2Triangles(10, 11, 12, 0, 11, 10, 13, 0),
    gsSP2Triangles(14, 13, 15, 0, 16, 15, 17, 0),
    gsSP2Triangles(18, 17, 19, 0, 20, 19, 10, 0),
    gsSP2Triangles(17, 18, 16, 0, 19, 20, 21, 0),
    gsSP2Triangles(13, 14, 11, 0, 15, 16, 14, 0),
    gsSP2Triangles(10, 12, 20, 0, 19, 21, 18, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 24, 26, 0),
    gsSP2Triangles(27, 26, 28, 0, 29, 28, 30, 0),
    gsSPVertex(D_05003040_827D0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 6, 0),
    gsSP2Triangles(10, 11, 9, 0, 1, 0, 11, 0),
    gsSP2Triangles(2, 3, 0, 0, 4, 7, 3, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 14, 16, 0),
    gsSP2Triangles(17, 16, 18, 0, 19, 18, 20, 0),
    gsSP2Triangles(21, 20, 22, 0, 23, 22, 13, 0),
    gsSP2Triangles(14, 15, 12, 0, 16, 17, 15, 0),
    gsSP2Triangles(18, 19, 17, 0, 20, 21, 19, 0),
    gsSP2Triangles(22, 23, 21, 0, 13, 12, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP2Triangles(27, 25, 24, 0, 28, 24, 30, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05003240_829D0, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 4, 1, 7, 0),
    gsSP2Triangles(1, 8, 7, 0, 4, 2, 1, 0),
    gsSP2Triangles(9, 3, 10, 0, 3, 5, 10, 0),
    gsSP2Triangles(9, 0, 3, 0, 7, 11, 10, 0),
    gsSP2Triangles(8, 9, 11, 0, 1, 0, 9, 0),
    gsSP2Triangles(2, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 10, 5, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 15, 13, 12, 0),
    gsSP2Triangles(16, 12, 18, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 19, 21, 0, 22, 21, 14, 0),
    gsSP2Triangles(23, 14, 13, 0, 14, 19, 12, 0),
    gsSP2Triangles(19, 18, 12, 0, 14, 21, 19, 0),
    gsSP2Triangles(17, 22, 15, 0, 22, 23, 15, 0),
    gsSP2Triangles(17, 20, 22, 0, 12, 16, 15, 0),
    gsSP2Triangles(18, 17, 16, 0, 19, 20, 17, 0),
    gsSP2Triangles(21, 22, 20, 0, 14, 23, 22, 0),
    gsSP1Triangle(13, 15, 23, 0),
    gsSPEndDisplayList(),
};
