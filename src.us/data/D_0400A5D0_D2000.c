#include <ultra64.h>

Vtx D_04009ED0_D1900[8] = {
#include "data/inc/D_04009ED0_D1900.inc.c"
};
Vtx D_04009F50_D1980[31] = {
#include "data/inc/D_04009F50_D1980.inc.c"
};
Vtx D_0400A140_D1B70[31] = {
#include "data/inc/D_0400A140_D1B70.inc.c"
};
Vtx D_0400A330_D1D60[30] = {
#include "data/inc/D_0400A330_D1D60.inc.c"
};
Vtx D_0400A510_D1F40[12] = {
#include "data/inc/D_0400A510_D1F40.inc.c"
};

Gfx D_0400A5D0_D2000[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04009ED0_D1900, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_04009F50_D1980, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 20, 25, 0, 19, 18, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 27, 29, 0),
    gsSP2Triangles(30, 28, 27, 0, 30, 29, 28, 0),
    gsSPVertex(D_0400A140_D1B70, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(3, 1, 0, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
    gsSP2Triangles(7, 5, 4, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 10, 12, 0),
    gsSP2Triangles(13, 12, 9, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 14, 16, 0, 17, 15, 14, 0),
    gsSP2Triangles(17, 16, 15, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 18, 20, 0, 21, 19, 18, 0),
    gsSP2Triangles(21, 20, 19, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 22, 24, 0, 25, 23, 22, 0),
    gsSP2Triangles(25, 24, 23, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 28, 30, 0),
    gsSPVertex(D_0400A330_D1D60, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(1, 0, 10, 0, 2, 11, 0, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_0400A510_D1F40, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP1Triangle(9, 11, 10, 0),
    gsSPEndDisplayList(),
};
