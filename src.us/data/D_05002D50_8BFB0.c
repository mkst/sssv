#include <ultra64.h>

Vtx D_05001AA0_8AD00[8] = {
#include "data/inc/D_05001AA0_8AD00.inc.c"
};
Vtx D_05001B20_8AD80[30] = {
#include "data/inc/D_05001B20_8AD80.inc.c"
};
Vtx D_05001D00_8AF60[32] = {
#include "data/inc/D_05001D00_8AF60.inc.c"
};
Vtx D_05001F00_8B160[31] = {
#include "data/inc/D_05001F00_8B160.inc.c"
};
Vtx D_050020F0_8B350[31] = {
#include "data/inc/D_050020F0_8B350.inc.c"
};
Vtx D_050022E0_8B540[32] = {
#include "data/inc/D_050022E0_8B540.inc.c"
};
Vtx D_050024E0_8B740[12] = {
#include "data/inc/D_050024E0_8B740.inc.c"
};
Vtx D_050025A0_8B800[31] = {
#include "data/inc/D_050025A0_8B800.inc.c"
};
Vtx D_05002790_8B9F0[31] = {
#include "data/inc/D_05002790_8B9F0.inc.c"
};
Vtx D_05002980_8BBE0[26] = {
#include "data/inc/D_05002980_8BBE0.inc.c"
};
Vtx D_05002B20_8BD80[25] = {
#include "data/inc/D_05002B20_8BD80.inc.c"
};
Vtx D_05002CB0_8BF10[10] = {
#include "data/inc/D_05002CB0_8BF10.inc.c"
};

const Gfx D_05002D50_8BFB0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05001AA0_8AD00, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05001B20_8AD80, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 8, 0),
    gsSP2Triangles(8, 7, 9, 0, 4, 10, 5, 0),
    gsSP2Triangles(8, 11, 12, 0, 2, 4, 13, 0),
    gsSP2Triangles(14, 11, 8, 0, 15, 16, 17, 0),
    gsSP2Triangles(17, 18, 15, 0, 16, 15, 1, 0),
    gsSP2Triangles(19, 20, 18, 0, 21, 6, 5, 0),
    gsSP2Triangles(22, 3, 23, 0, 18, 20, 24, 0),
    gsSP2Triangles(15, 24, 23, 0, 1, 23, 3, 0),
    gsSP2Triangles(21, 5, 10, 0, 25, 24, 20, 0),
    gsSP2Triangles(20, 26, 25, 0, 24, 25, 27, 0),
    gsSP2Triangles(23, 27, 22, 0, 28, 8, 9, 0),
    gsSP2Triangles(21, 10, 29, 0, 26, 20, 19, 0),
    gsSP2Triangles(27, 23, 24, 0, 1, 0, 16, 0),
    gsSP2Triangles(24, 15, 18, 0, 23, 1, 15, 0),
    gsSP2Triangles(3, 2, 1, 0, 2, 13, 0, 0),
    gsSPVertex(D_05001D00_8AF60, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 0, 4, 0, 5, 4, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 3, 16, 17, 0),
    gsSP2Triangles(0, 17, 18, 0, 4, 18, 19, 0),
    gsSP2Triangles(10, 12, 20, 0, 21, 17, 16, 0),
    gsSP2Triangles(16, 22, 21, 0, 17, 21, 23, 0),
    gsSP2Triangles(15, 24, 13, 0, 10, 20, 25, 0),
    gsSP2Triangles(12, 11, 26, 0, 6, 26, 5, 0),
    gsSP2Triangles(23, 18, 17, 0, 4, 5, 1, 0),
    gsSP2Triangles(17, 0, 3, 0, 18, 4, 0, 0),
    gsSP2Triangles(19, 6, 4, 0, 27, 28, 14, 0),
    gsSP2Triangles(14, 13, 27, 0, 28, 27, 29, 0),
    gsSP1Triangle(30, 29, 31, 0),
    gsSPVertex(D_05001F00_8B160, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 10, 7, 0, 12, 7, 6, 0),
    gsSP2Triangles(1, 6, 13, 0, 3, 2, 13, 0),
    gsSP2Triangles(14, 10, 9, 0, 9, 15, 14, 0),
    gsSP2Triangles(10, 14, 16, 0, 7, 16, 5, 0),
    gsSP2Triangles(6, 5, 17, 0, 3, 13, 17, 0),
    gsSP2Triangles(2, 4, 0, 0, 1, 0, 18, 0),
    gsSP2Triangles(16, 7, 10, 0, 12, 18, 19, 0),
    gsSP2Triangles(10, 11, 8, 0, 7, 12, 11, 0),
    gsSP2Triangles(6, 1, 12, 0, 13, 2, 1, 0),
    gsSP2Triangles(17, 13, 6, 0, 20, 14, 15, 0),
    gsSP2Triangles(15, 21, 20, 0, 14, 20, 22, 0),
    gsSP2Triangles(16, 22, 23, 0, 5, 23, 24, 0),
    gsSP2Triangles(3, 17, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(21, 28, 29, 0, 20, 29, 27, 0),
    gsSP2Triangles(22, 27, 26, 0, 23, 26, 30, 0),
    gsSP1Triangle(3, 24, 30, 0),
    gsSPVertex(D_050020F0_8B350, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 0, 4, 0, 5, 4, 6, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 10, 8, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 13, 15, 0),
    gsSP2Triangles(4, 5, 1, 0, 16, 15, 17, 0),
    gsSP2Triangles(1, 18, 19, 0, 5, 16, 18, 0),
    gsSP2Triangles(7, 14, 16, 0, 10, 11, 14, 0),
    gsSP2Triangles(8, 10, 7, 0, 20, 21, 22, 0),
    gsSP2Triangles(19, 21, 20, 0, 20, 2, 19, 0),
    gsSP2Triangles(3, 2, 20, 0, 20, 23, 3, 0),
    gsSP2Triangles(24, 23, 20, 0, 20, 25, 24, 0),
    gsSP2Triangles(26, 25, 20, 0, 27, 28, 29, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(D_050022E0_8B540, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 10, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 13, 15, 0, 14, 16, 15, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 17, 19, 0),
    gsSP2Triangles(18, 20, 19, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 21, 23, 0, 22, 24, 23, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 25, 27, 0),
    gsSP2Triangles(26, 28, 27, 0, 29, 30, 31, 0),
    gsSPVertex(D_050024E0_8B740, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
    gsSP2Triangles(5, 7, 6, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 8, 10, 0, 9, 11, 10, 0),
    gsSPVertex(D_050025A0_8B800, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(1, 0, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 1, 9, 0, 10, 3, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 13, 7, 15, 0),
    gsSP2Triangles(0, 3, 16, 0, 3, 10, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(7, 6, 24, 0, 10, 12, 25, 0),
    gsSP2Triangles(21, 19, 26, 0, 22, 27, 28, 0),
    gsSP2Triangles(19, 21, 29, 0, 22, 21, 30, 0),
    gsSPVertex(D_05002790_8B9F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 3, 9, 10, 0),
    gsSP2Triangles(9, 3, 11, 0, 0, 9, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 6, 13, 16, 0),
    gsSP2Triangles(4, 3, 17, 0, 1, 0, 18, 0),
    gsSP2Triangles(1, 19, 20, 0, 13, 6, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 7, 6, 25, 0),
    gsSP2Triangles(26, 4, 27, 0, 9, 0, 28, 0),
    gsSP1Triangle(23, 29, 30, 0),
    gsSPVertex(D_05002980_8BBE0, 26, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 10, 0),
    gsSP2Triangles(11, 9, 12, 0, 13, 0, 14, 0),
    gsSP2Triangles(1, 0, 15, 0, 0, 13, 16, 0),
    gsSP2Triangles(3, 17, 18, 0, 13, 19, 20, 0),
    gsSP2Triangles(4, 3, 21, 0, 17, 1, 22, 0),
    gsSP1Triangle(23, 24, 25, 0),
    gsSPVertex(D_05002B20_8BD80, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 4, 0, 2, 5, 0, 0),
    gsSP2Triangles(1, 0, 3, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 7, 0, 4, 3, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 11, 13, 14, 0),
    gsSP2Triangles(15, 10, 16, 0, 17, 15, 18, 0),
    gsSP2Triangles(13, 17, 19, 0, 11, 10, 20, 0),
    gsSP2Triangles(10, 15, 21, 0, 15, 17, 22, 0),
    gsSP2Triangles(17, 13, 23, 0, 13, 11, 24, 0),
    gsSP2Triangles(12, 16, 10, 0, 14, 12, 11, 0),
    gsSP2Triangles(16, 18, 15, 0, 18, 19, 17, 0),
    gsSP2Triangles(19, 14, 13, 0, 20, 24, 11, 0),
    gsSP2Triangles(21, 20, 10, 0, 22, 21, 15, 0),
    gsSP2Triangles(23, 22, 17, 0, 24, 23, 13, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05002CB0_8BF10, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 1, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 7, 0, 1, 0, 9, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
