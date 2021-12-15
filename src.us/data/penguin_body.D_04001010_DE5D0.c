#include <ultra64.h>


Vtx D_04000B60_DE120[21] = {
#include "data/inc/D_04000B60_DE120.inc.c"
};
Vtx D_04000CB0_DE270[32] = {
#include "data/inc/D_04000CB0_DE270.inc.c"
};
Vtx D_04000EB0_DE470[22] = {
#include "data/inc/D_04000EB0_DE470.inc.c"
};

extern Gfx D_010034C0_3CD90[];


Gfx D_04001010_DE5D0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04000B60_DE120, 21, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(3, 2, 4, 0, 5, 4, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 7, 5, 0),
    gsSP2Triangles(7, 9, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(11, 9, 12, 0, 13, 11, 12, 0),
    gsSP2Triangles(11, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(13, 16, 15, 0, 12, 16, 13, 0),
    gsSP2Triangles(16, 17, 15, 0, 18, 17, 16, 0),
    gsSP2Triangles(16, 12, 18, 0, 17, 18, 19, 0),
    gsSP2Triangles(18, 0, 19, 0, 12, 20, 18, 0),
    gsSP2Triangles(0, 18, 20, 0, 20, 12, 9, 0),
    gsSP2Triangles(5, 20, 9, 0, 2, 0, 20, 0),
    gsSP1Triangle(20, 5, 2, 0),
    gsSPTexture(32768, 32768, 0, 1, G_ON),
    gsSPVertex(D_04000CB0_DE270, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(4, 0, 1, 0, 5, 4, 1, 0),
    gsSP2Triangles(6, 2, 0, 0, 7, 3, 2, 0),
    gsSP2Triangles(2, 6, 7, 0, 8, 4, 5, 0),
    gsSP2Triangles(9, 0, 4, 0, 4, 8, 9, 0),
    gsSP2Triangles(0, 9, 6, 0, 9, 10, 6, 0),
    gsSP2Triangles(8, 11, 9, 0, 10, 9, 11, 0),
    gsSP2Triangles(6, 12, 7, 0, 12, 6, 10, 0),
    gsSP2Triangles(13, 12, 10, 0, 14, 10, 11, 0),
    gsSP2Triangles(10, 14, 13, 0, 14, 15, 13, 0),
    gsSP2Triangles(3, 7, 16, 0, 7, 17, 16, 0),
    gsSP2Triangles(17, 7, 12, 0, 18, 17, 12, 0),
    gsSP2Triangles(12, 13, 18, 0, 13, 19, 18, 0),
    gsSP2Triangles(19, 13, 15, 0, 20, 19, 15, 0),
    gsSP2Triangles(15, 21, 20, 0, 21, 15, 22, 0),
    gsSP2Triangles(15, 14, 22, 0, 21, 23, 20, 0),
    gsSP2Triangles(24, 22, 14, 0, 11, 24, 14, 0),
    gsSP2Triangles(24, 11, 25, 0, 11, 8, 25, 0),
    gsSP2Triangles(23, 21, 26, 0, 27, 26, 21, 0),
    gsSP2Triangles(22, 27, 21, 0, 26, 28, 23, 0),
    gsSP2Triangles(29, 28, 26, 0, 26, 27, 29, 0),
    gsSP2Triangles(30, 29, 27, 0, 31, 28, 29, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_04000EB0_DE470, 22, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 5, 2, 0),
    gsSP2Triangles(6, 5, 3, 0, 3, 4, 6, 0),
    gsSP2Triangles(7, 6, 4, 0, 8, 5, 6, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 5, 8, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 9, 7, 0, 7, 12, 11, 0),
    gsSP2Triangles(12, 7, 4, 0, 4, 13, 12, 0),
    gsSP2Triangles(13, 4, 0, 0, 0, 14, 13, 0),
    gsSP2Triangles(14, 0, 1, 0, 1, 15, 14, 0),
    gsSP2Triangles(12, 16, 11, 0, 16, 12, 17, 0),
    gsSP2Triangles(18, 16, 17, 0, 15, 1, 19, 0),
    gsSP2Triangles(19, 20, 15, 0, 20, 21, 15, 0),
    gsSPEndDisplayList(),
};
