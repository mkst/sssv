#include <ultra64.h>

Vtx D_04001590_C8FC0[4] = {
    #include "data/inc/D_04001590_C8FC0.inc.c"
};
Vtx D_040015D0_C9000[14] = {
    #include "data/inc/D_040015D0_C9000.inc.c"
};
Vtx D_040016B0_C90E0[14] = {
    #include "data/inc/D_040016B0_C90E0.inc.c"
};
Vtx D_04001790_C91C0[4] = {
#include "data/inc/D_04001790_C91C0.inc.c"
};
Vtx D_040017D0_C9200[14] = {
#include "data/inc/D_040017D0_C9200.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003548_3CE18[];

Gfx D_040018B0_C92E0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPTexture(0xC000, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_04001790_C91C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_040016B0_C90E0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSP2Triangles(4, 6, 5, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 8, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 10, 11, 0, 11, 13, 12, 0),
    gsSPTexture(0xC000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04001590_C8FC0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_040017D0_C9200, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSP2Triangles(5, 6, 4, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 8, 7, 0, 7, 11, 10, 0),
    gsSP2Triangles(12, 10, 11, 0, 11, 13, 12, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_040015D0_C9000, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 0, 4, 0, 4, 5, 1, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 7, 5, 0),
    gsSP2Triangles(7, 6, 8, 0, 8, 9, 7, 0),
    gsSP2Triangles(9, 8, 10, 0, 10, 11, 9, 0),
    gsSP2Triangles(11, 10, 12, 0, 12, 13, 11, 0),
    gsSPEndDisplayList(),
};
