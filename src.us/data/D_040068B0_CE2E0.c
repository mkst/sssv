#include <ultra64.h>

Vtx D_04006170_CDBA0[16] = {
#include "data/inc/D_04006170_CDBA0.inc.c"
};
Vtx D_04006270_CDCA0[16] = {
#include "data/inc/D_04006270_CDCA0.inc.c"
};
Vtx D_04006370_CDDA0[16] = {
#include "data/inc/D_04006370_CDDA0.inc.c"
};
Vtx D_04006470_CDEA0[12] = {
#include "data/inc/D_04006470_CDEA0.inc.c"
};
Vtx D_04006530_CDF60[8] = {
#include "data/inc/D_04006530_CDF60.inc.c"
};
Vtx D_040065B0_CDFE0[8] = {
#include "data/inc/D_040065B0_CDFE0.inc.c"
};
Vtx D_04006630_CE060[16] = {
#include "data/inc/D_04006630_CE060.inc.c"
};
Vtx D_04006730_CE160[16] = {
#include "data/inc/D_04006730_CE160.inc.c"
};
Vtx D_04006830_CE260[8] = {
#include "data/inc/D_04006830_CE260.inc.c"
};

Gfx D_040068B0_CE2E0[] = {
    gsSPVertex(D_04006170_CDBA0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 3, 5, 2, 0),
    gsSP2Triangles(4, 0, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 10, 11, 7, 0),
    gsSP2Triangles(11, 4, 7, 0, 4, 11, 12, 0),
    gsSP2Triangles(12, 3, 4, 0, 3, 12, 13, 0),
    gsSP2Triangles(5, 3, 13, 0, 13, 14, 5, 0),
    gsSP1Triangle(11, 10, 15, 0),
    gsSPVertex(D_04006270_CDCA0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 2, 0, 5, 0),
    gsSP2Triangles(5, 6, 2, 0, 6, 5, 7, 0),
    gsSP2Triangles(8, 6, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(9, 10, 6, 0, 10, 2, 6, 0),
    gsSP2Triangles(2, 10, 11, 0, 11, 1, 2, 0),
    gsSP2Triangles(1, 11, 12, 0, 4, 1, 12, 0),
    gsSP2Triangles(12, 13, 4, 0, 10, 9, 14, 0),
    gsSP2Triangles(14, 15, 10, 0, 15, 11, 10, 0),
    gsSPVertex(D_04006370_CDDA0, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 2, 0, 5, 0),
    gsSP2Triangles(5, 6, 2, 0, 4, 1, 7, 0),
    gsSP2Triangles(1, 8, 7, 0, 8, 1, 2, 0),
    gsSP2Triangles(2, 9, 8, 0, 9, 2, 6, 0),
    gsSP2Triangles(10, 9, 6, 0, 7, 11, 4, 0),
    gsSP2Triangles(6, 12, 10, 0, 9, 10, 13, 0),
    gsSP2Triangles(13, 14, 9, 0, 14, 8, 9, 0),
    gsSP2Triangles(8, 14, 15, 0, 15, 7, 8, 0),
    gsSPVertex(D_04006470_CDEA0, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 4, 1, 5, 0),
    gsSP2Triangles(1, 6, 5, 0, 6, 1, 2, 0),
    gsSP2Triangles(2, 7, 6, 0, 7, 2, 8, 0),
    gsSP2Triangles(9, 7, 8, 0, 8, 10, 9, 0),
    gsSP1Triangle(7, 9, 11, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPVertex(D_04006530_CDF60, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040065B0_CDFE0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04006630_CE060, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(1, 4, 0, 0, 4, 1, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 8, 7, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsSP2Triangles(13, 14, 12, 0, 14, 13, 15, 0),
    gsSPVertex(D_04006730_CE160, 16, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(5, 8, 4, 0, 8, 5, 9, 0),
    gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 12, 10, 0, 12, 11, 13, 0),
    gsSP2Triangles(13, 14, 12, 0, 14, 13, 15, 0),
    gsSPVertex(D_04006830_CE260, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 5, 7, 0),
    gsSPEndDisplayList(),
};
