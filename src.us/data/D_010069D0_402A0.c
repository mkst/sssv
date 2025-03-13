#include <ultra64.h>

Vtx D_010066D0_3FFA0[8] = {
#include "data/inc/D_010066D0_3FFA0.inc.c"
};

Vtx D_01006750_40020[8] = {
#include "data/inc/D_01006750_40020.inc.c"
};

Vtx D_010067D0_400A0[8] = {
#include "data/inc/D_010067D0_400A0.inc.c"
};

Vtx D_01006850_40120[8] = {
#include "data/inc/D_01006850_40120.inc.c"
};

Vtx D_010068D0_401A0[8] = {
#include "data/inc/D_010068D0_401A0.inc.c"
};

Vtx D_01006950_40220[8] = {
#include "data/inc/D_01006950_40220.inc.c"
};

Gfx D_010069D0_402A0[] = {
    gsSPVertex(D_010066D0_3FFA0, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01006A08_402D8[] = {
    gsSPVertex(D_01006750_40020, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01006A40_40310[] = {
    gsSPVertex(D_010067D0_400A0, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01006A78_40348[] = {
    gsSPVertex(D_01006850_40120, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01006AB0_40380[] = {
    gsSPVertex(D_010068D0_401A0, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_01006AE8_403B8[] = {
    gsSPVertex(D_01006950_40220, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
