#include <ultra64.h>

Vtx D_04006340_E3900[] = {
#include "data/inc/D_04006340_E3900.inc.c"
};
Vtx D_04006410_E39D0[] = {
#include "data/inc/D_04006410_E39D0.inc.c"
};
Vtx D_040065B0_E3B70[] = {
#include "data/inc/D_040065B0_E3B70.inc.c"
};
Vtx D_04006620_E3BE0[] = {
#include "data/inc/D_04006620_E3BE0.inc.c"
};
Vtx D_04006660_E3C20[] = {
#include "data/inc/D_04006660_E3C20.inc.c"
};
Vtx D_040066A0_E3C60[] = {
#include "data/inc/D_040066A0_E3C60.inc.c"
};
Vtx D_04006710_E3CD0[] = {
#include "data/inc/D_04006710_E3CD0.inc.c"
};
Vtx D_040067A0_E3D60[] = {
#include "data/inc/D_040067A0_E3D60.inc.c"
};
Vtx D_04006800_E3DC0[] = {
#include "data/inc/D_04006800_E3DC0.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_04006860_E3E20[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04006340_E3900, 13, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(3, 2, 4, 0, 5, 4, 2, 0),
    gsSP2Triangles(0, 5, 2, 0, 0, 6, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 4, 5, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 0, 1, 9, 0),
    gsSP1Quadrangle(0, 9, 10, 6, 0),
    gsSP2Triangles(10, 8, 6, 0, 8, 10, 11, 0),
    gsSP2Triangles(9, 11, 10, 0, 1, 12, 9, 0),
    gsSP2Triangles(12, 1, 3, 0, 11, 9, 12, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_04006410_E39D0, 26, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(2, 4, 1, 0, 4, 2, 5, 0),
    gsSP2Triangles(6, 5, 2, 0, 0, 6, 2, 0),
    gsSP2Triangles(5, 7, 4, 0, 7, 5, 8, 0),
    gsSP2Triangles(9, 8, 5, 0, 5, 6, 9, 0),
    gsSP2Triangles(10, 9, 6, 0, 0, 10, 6, 0),
    gsSP1Quadrangle(11, 7, 8, 12, 0),
    gsSP2Triangles(8, 9, 12, 0, 13, 12, 9, 0),
    gsSP2Triangles(9, 10, 13, 0, 14, 13, 10, 0),
    gsSP2Triangles(0, 14, 10, 0, 11, 12, 15, 0),
    gsSP2Triangles(12, 13, 15, 0, 16, 15, 13, 0),
    gsSP2Triangles(13, 14, 16, 0, 17, 16, 14, 0),
    gsSP2Triangles(0, 17, 14, 0, 11, 15, 18, 0),
    gsSP2Triangles(15, 16, 18, 0, 19, 18, 16, 0),
    gsSP2Triangles(16, 17, 19, 0, 11, 18, 20, 0),
    gsSP2Triangles(18, 19, 20, 0, 0, 21, 17, 0),
    gsSP2Triangles(0, 3, 21, 0, 22, 1, 4, 0),
    gsSP2Triangles(1, 22, 3, 0, 4, 23, 22, 0),
    gsSP2Triangles(11, 23, 7, 0, 23, 4, 7, 0),
    gsSP2Triangles(3, 24, 21, 0, 24, 17, 21, 0),
    gsSP2Triangles(24, 20, 19, 0, 24, 3, 22, 0),
    gsSP2Triangles(24, 19, 17, 0, 22, 25, 24, 0),
    gsSP2Triangles(11, 25, 23, 0, 20, 24, 25, 0),
    gsSP2Triangles(11, 20, 25, 0, 25, 22, 23, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040065B0_E3B70, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(4, 3, 1, 0, 5, 4, 1, 0),
    gsSP2Triangles(6, 5, 1, 0, 2, 6, 1, 0),
    gsSPVertex(D_04006620_E3BE0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPVertex(D_04006660_E3C20, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPVertex(D_040066A0_E3C60, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(4, 3, 1, 0, 5, 4, 1, 0),
    gsSP2Triangles(6, 5, 1, 0, 2, 6, 1, 0),
    gsDPSetPrimColor(0, 0, 0x19, 0x19, 0x19, 0xFF),
    gsSPVertex(D_04006710_E3CD0, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(0, 1, 4, 0, 0, 5, 3, 0),
    gsSP2Triangles(0, 4, 6, 0, 0, 7, 5, 0),
    gsSP2Triangles(0, 8, 7, 0, 0, 6, 8, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040067A0_E3D60, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP1Triangle(5, 2, 0, 0),
    gsSPVertex(D_04006800_E3DC0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP1Triangle(5, 2, 0, 0),
    gsSPEndDisplayList(),
};
