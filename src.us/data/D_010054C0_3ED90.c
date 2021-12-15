#include <ultra64.h>

Vtx D_010050A0_3E970[12] = {
#include "data/inc/D_010050A0_3E970.inc.c"
};
Vtx D_01005160_3EA30[18] = {
#include "data/inc/D_01005160_3EA30.inc.c"
};
Vtx D_01005280_3EB50[18] = {
#include "data/inc/D_01005280_3EB50.inc.c"
};
Vtx D_010053A0_3EC70[18] = {
#include "data/inc/D_010053A0_3EC70.inc.c"
};

Gfx D_010054C0_3ED90[] = {
    gsSPVertex(D_010050A0_3E970, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 0, 0, 0, 6, 5, 0),
    gsSP2Triangles(5, 7, 4, 0, 7, 5, 6, 0),
    gsSP2Triangles(6, 8, 7, 0, 9, 8, 6, 0),
    gsSP2Triangles(1, 9, 0, 0, 6, 0, 9, 0),
    gsSP2Triangles(7, 8, 10, 0, 4, 10, 3, 0),
    gsSP2Triangles(10, 4, 7, 0, 10, 8, 11, 0),
    gsSP2Triangles(11, 8, 9, 0, 3, 11, 1, 0),
    gsSP2Triangles(11, 3, 10, 0, 9, 1, 11, 0),
    gsSPVertex(D_01005160_3EA30, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 11, 13, 12, 0),
    gsSP2Triangles(14, 16, 15, 0, 16, 14, 17, 0),
    gsSPVertex(D_01005280_3EB50, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 11, 13, 12, 0),
    gsSP2Triangles(14, 16, 15, 0, 16, 14, 17, 0),
    gsSPVertex(D_010053A0_3EC70, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 11, 13, 12, 0),
    gsSP2Triangles(14, 16, 15, 0, 16, 14, 17, 0),
    gsSPEndDisplayList(),
};
