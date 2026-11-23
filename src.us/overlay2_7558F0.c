#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

typedef struct {
  u16  flags;
  u8   unk2;  // texture mode/group? values >= 33 select animated texture types
  u8   unk3;  // texture scroll/control index queued in D_803E3130
} struct102_header; // size 0x4

typedef struct {
    s16 tc0;   // tc0 (u)
    s16 tc1;   // tc1 (v)
    s8  red;   // cn[0]
    s8  green; // cn[1]
    s8  blue;  // cn[2]
    u8  unk7;  // x
    s16 unk8;  // y
    u8  unkA;  // z
    u8  alpha; // cn[3]
} struct102_payload; // size 0xC

typedef struct {
  /* 0x00 */ struct102_header header;
  /* 0x04 */ struct102_payload unk4[4];
} struct102; // size 0x34?

typedef struct {
    /* 0x0  */ s16 idx;
    /* 0x2  */ s16 unused; // doesnt really force alignment..
    /* 0x4  */ s16 v[4];
    /* 0xC  */ s16 flags[4]; // per-vertex reuse flags
    /* 0x14 */ s16 unk14[4]; // unused?
    /* 0x1C */ s16 unk1C[4];
} struct115; // size 0x24

void func_803458B8_756F68(Gfx **dl, Vtx *vtx, s16 numVtxs);
void func_803458FC_756FAC(Gfx **dl, struct115 *faces, s16 numFaces);
void func_80346878_757F28(Gfx **dl, u8 idx);
void func_803469D4_758084(Gfx **dl, u8 idx);
void func_80346AB0_758160(Gfx **dl, u8 idx);
void func_80346BB4_758264(Gfx **dl, struct115 *faces, s16 numFaces);


#define VTX_TRIANGLE                0x1
#define VTX_CELL_END                0x2
#define VTX_NO_CULL_BACK            0x4
#define VTX_TRANSLUCENT             0x20
#define VTX_ALPHA_COMPARE_DITHER    0x40
#define VTX_RENDER_MODE_INTER       0x800
#define VTX_RENDER_MODE_DECAL       0x4000

#define GEO_TEXTURE_ANIMATED_MIN    32
#define GEO_SCROLL_CENTER_MIN       32
#define GEO_SCROLL_CENTER_MAX       48

#define REUSED_VTX_UPDATE_TC        0x1
#define REUSED_VTX_NO_TC_UPDATE     0x4

#define WORLD_CELL_COUNT_X          4
#define WORLD_CELL_COUNT_Z          6
#define CELL_FACE_BATCH_CAPACITY    50
#define TRANSLUCENT_BATCH_FACE_COUNT 8
#define OPAQUE_BATCH_FLUSH_THRESHOLD 28

#define NOT_FOUND                   -100

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (from D_803F2C80 to D_803F2CD0)
// ========================================================

static struct102 *D_803F2C80; // [0x34] big?
static s16  D_803F2C84;
static s16  D_803F2C86;
static s16  D_803F2C88;
static s16  D_803F2C8A;
static s16  D_803F2C8C;
static s16  D_803F2C8E;
static s16  D_803F2C90;
static s16  D_803F2C92;
static s16  D_803F2C94;
static u8   D_803F2C96;
static u8   D_803F2C97;
static u8   D_803F2C98;
static u8   D_803F2C99;
static u8   D_803F2C9A;
static u8   D_803F2C9B; // need to cull back?
static s16  D_803F2C9C;
static s16  D_803F2C9E;
static s16  D_803F2CA0;
static s16  D_803F2CA2; // cellX
static s16  D_803F2CA4; // cellZ
       s16  D_803F2CA6; // index into D_803E3130
       s8   gWorldCellTranslucentEnabled[4][6];  // whether DL is enabled or not?
static s64  D_803F2CC0;

// ========================================================
// .text
// ========================================================

// Build the per-cell opaque and translucent display lists and cull boxes.
void func_80344240_7558F0(void) {
    s32 opaqueBatchVertexCount;
    s32 centerIndex;

    s16 faceIndex;
    // Counts reused vertices; never read.
    s16 reuseCount;
    s16 cellOffsetX;
    s16 cellOffsetZ;
    s32 centerTileZ;
    s32 centerTileX;
    s16 batchVertexIndex;
    s16 vertexCount;

    s16 opaqueMaxY;
    s16 opaqueMaxZ;
    s16 opaqueMaxX;
    s16 opaqueMinY;
    s16 opaqueMinZ;
    s16 opaqueMinX;
    s16 translucentMaxY;
    s16 translucentMaxZ;
    s16 translucentMaxX;
    s16 translucentMinY;
    s16 translucentMinZ;
    s16 translucentMinX;
    s16 translucentVertexIndex;
    s16 opaqueBatchStart;
    s16 translucentFaceIndex;
    s16 opaqueFaceCount;
    s16 translucentVertexCount;
    s16 translucentBatchStart;
    s16 translucentBatchVertexCount;
    s16 translucentFaceCount;
    s16 opaqueCullBase;
    s16 cullVertexBase;
    Vtx *translucentVertex;
    s16 reusedVertexIndex;
    s16 vertexIndex;
    s16 opaqueVertexCount;
    s16 existingVertexIndex;
    s16 reuseFlags;
    u8 green;
    u8 scrollIndex;
    u8 red;
    u8 alpha;
    u8 blue;

    u8 textureIndex;

    s16 maxTileX;
    s16 maxTileZ;
    s16 minTileX;
    s16 minTileZ;

    s16 tc1;
    s16 tc0;

    // World X/Z in 64-unit tiles, used for animated translucent centers.
    u8  tileX[4];
    u8  tileZ[4];
    u16 translucentVertexIndices[4];

    struct115 opaqueFaces[CELL_FACE_BATCH_CAPACITY];
    struct115 translucentFaces[CELL_FACE_BATCH_CAPACITY];

    // Vertex normals for lit cells: the same bytes as red/green/blue, read signed.
    s8 normalX;
    s8 normalZ;
    s8 normalY;

    u16 faceFlags;
    Gfx *opaqueDL;
    Gfx *translucentDL;

    // Level geometry has already been loaded into D_80100000.
    D_803F2C80 = (struct102 *)D_80100000;

    gRenderMode2 = 0x110038;
    D_803F2CC0 = 0x1049D8; // translucent render mode

    D_803F2CA4 = 0;
    D_803F2CA6 = 0;
    D_803F2C99 = 0;
    D_803F2C9A = 0;
    D_803F2C9B = 0;
    D_803E4AC8 = 0;

    faceIndex = 0;
    opaqueVertexCount = 0;

    opaqueBatchStart = 0;
    opaqueFaceCount = 0;

    translucentVertexCount = 0;
    translucentBatchVertexCount = 0;

    translucentBatchStart = 0;
    translucentFaceCount = 0;
    reuseCount = 0;

    translucentDL = &D_80225650[0];
    opaqueDL = &D_80205470[0];
    gDPSetCombineMode(translucentDL++, G_CC_SHADE, G_CC_SHADE);

    while (D_803F2CA4 < WORLD_CELL_COUNT_Z) {
        for (D_803F2CA2 = 0; D_803F2CA2 < WORLD_CELL_COUNT_X; D_803F2CA2++) {
            D_803F2C8C = 0;
            D_803F2C8E = 0;
            D_803F2C90 = 0;

            gWorldCellTranslucentEnabled[D_803F2CA2][D_803F2CA4] = 0;

            D_803F2C86 = 1;
            D_803F2C88 = 1;
            D_803F2C8A = 1;

            D_803F2C84 = 1000;
            opaqueMaxX = -30000;
            opaqueMaxY = -30000;
            opaqueMaxZ = -30000;
            opaqueMinX = 30000;
            opaqueMinY = 30000;
            opaqueMinZ = 30000;
            translucentMaxX = -30000;
            translucentMaxY = -30000;
            translucentMaxZ = -30000;
            translucentMinX = 30000;
            translucentMinY = 30000;
            translucentMinZ = 30000;
            D_803F2C96 = 0xFF;
            D_803F2C98 = 0xFF;
            D_803F2C97 = 0xFF;

            gWorldCellOpaqueDisplayLists[D_803F2CA2][D_803F2CA4] = opaqueDL;
            gWorldCellTranslucentDisplayLists[D_803F2CA2][D_803F2CA4] = translucentDL;
            gSPClearGeometryMode(opaqueDL++, 0xFFFFFFFF);
            opaqueCullBase = (D_803F2CA2 << 3) + (D_803F2CA4 << 5);
            gSPVertex(
                opaqueDL++,
                K0_TO_PHYS(&D_80224870[opaqueCullBase]),
                8,
                0);
            gSPCullDisplayList(opaqueDL++, 0, 7);
            if (D_803F2D50.cellLightingModes[D_803F2CA2][D_803F2CA4] == 0) {
                gSPSetGeometryMode(opaqueDL++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_CLIPPING);
            } else {
                gSPSetGeometryMode(opaqueDL++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG |              G_SHADING_SMOOTH | G_CLIPPING);
            }
            gSPTexture(opaqueDL++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);

            gSPClearGeometryMode(translucentDL++, G_LIGHTING);
            // The two cull-vertex pools use the same per-cell index.
            cullVertexBase = (D_803F2CA2 << 3) + (D_803F2CA4 << 5);
            gSPVertex(
                translucentDL++,
                K0_TO_PHYS(&D_8022D350[cullVertexBase]),
                8,
                0);
            gSPCullDisplayList(translucentDL++, 0, 7);
            gDPPipelineMode(translucentDL++, G_PM_NPRIMITIVE);
            gSPTexture(translucentDL++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
            gDPSetTileSize(translucentDL++, G_TX_RENDERTILE, 0, 0, 124, 124);
            gDPSetAlphaCompare(translucentDL++, G_AC_NONE);
            gDPSetTileSize(translucentDL++, G_TX_RENDERTILE, 0, 0, 124, 124);
            gDPSetTileSize(translucentDL++, 1, 0, 0, 60, 60);
            gDPSetTileSize(translucentDL++, 2, 0, 0, 28, 28);
            gDPSetTileSize(translucentDL++, 5, 0, 0, 124, 124);
            gDPSetTileSize(translucentDL++, 6, 0, 0, 124, 124);
            gDPSetTile(translucentDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
            gDPSetTile(translucentDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
            gDPSetTile(translucentDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);

            gDPPipeSync(opaqueDL++);
            gDPSetAlphaCompare(opaqueDL++, G_AC_NONE);
            gDPSetRenderMode(opaqueDL++, gRenderMode1, gRenderMode2);
            gDPSetCombineMode(opaqueDL++, G_CC_TRILERP, G_CC_MODULATEI2);
            gDPSetCycleType(opaqueDL++, G_CYC_2CYCLE);
            gDPSetTextureLOD(opaqueDL++, G_TL_LOD);
            gDPSetPrimColor(opaqueDL++, 128, 128, 0x00, 0x00, 0x00, 0x00);
            gDPSetTileSize(opaqueDL++, G_TX_RENDERTILE, 0, 0, 124, 124);
            gDPSetTileSize(opaqueDL++, 1, 0, 0, 60, 60);
            gDPSetTileSize(opaqueDL++, 2, 0, 0, 28, 28);
            gDPSetTileSize(opaqueDL++, 3, 0, 0, 12, 12);
            gDPSetTileSize(opaqueDL++, 4, 0, 0, 4, 4);
            gDPSetTileSize(opaqueDL++, 5, 0, 0, 0, 0);
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 0, 5, G_TX_NOMIRROR | G_TX_WRAP, 0, 5);

            D_803F2C92 = 0;
            D_803F2C94 = 0;
            D_803F2C99 = 0;
            D_803F2C9A = 0;
            D_803F2C9B = 0;

            gDPPipeSync(opaqueDL++);

            cellOffsetX = D_803F2CA2 << 0xA;
            cellOffsetZ = D_803F2CA4 << 0xA;

            do {
                faceFlags = D_803F2C80[faceIndex].header.flags;
                textureIndex = D_803F2C80[faceIndex].header.unk2;
                scrollIndex = D_803F2C80[faceIndex].header.unk3;

                if (faceFlags & VTX_TRIANGLE) {
                    vertexCount = 3;
                } else {
                    vertexCount = 4;
                }

                if ((faceFlags & VTX_TRANSLUCENT) ||
                    (faceFlags & 0x10) ||
                    (faceFlags & 0x200) ||
                    (faceFlags & 0x8000)) {

                    gWorldCellTranslucentEnabled[D_803F2CA2][D_803F2CA4] = 1;
                    for (vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++) {
                        D_803F2C9C = (D_803F2C80[faceIndex].unk4[vertexIndex].unk7 << 6) + cellOffsetX + 0x100;
                        D_803F2C9E = (D_803F2C80[faceIndex].unk4[vertexIndex].unkA << 6) + cellOffsetZ + 0x200;
                        D_803F2CA0 = D_803F2C80[faceIndex].unk4[vertexIndex].unk8 * 8;
                        tileX[vertexIndex] = D_803F2C9C >> 6;
                        tileZ[vertexIndex] = D_803F2C9E >> 6;
                        translucentVertexIndex = translucentVertexCount;
                        translucentVertexIndices[vertexIndex] = translucentVertexIndex;

#ifdef __sgi
                        if (faceFlags & VTX_RENDER_MODE_DECAL) {
                            // Decal faces store the height back unchanged.
                            D_803F2CA0 = D_803F2CA0;
                        }
#endif

                        tc0 = D_803F2C80[faceIndex].unk4[vertexIndex].tc0 * 64;
                        tc1 = D_803F2C80[faceIndex].unk4[vertexIndex].tc1 * 64;

                        // Clamp nearly opaque alpha to 0xFF (this writes back into the level geometry).
                        if (D_803F2C80[faceIndex].unk4[vertexIndex].alpha > 250) {
                            D_803F2C80[faceIndex].unk4[vertexIndex].alpha = 0xFF;
                        }

                        red = D_803F2C80[faceIndex].unk4[vertexIndex].red;
                        green = D_803F2C80[faceIndex].unk4[vertexIndex].green;
                        blue = D_803F2C80[faceIndex].unk4[vertexIndex].blue;

                        if (textureIndex >= GEO_TEXTURE_ANIMATED_MIN) {
                            alpha = 0;
                        } else {
                            alpha = D_803F2C80[faceIndex].unk4[vertexIndex].alpha;
                        }

                        translucentVertex = &gTranslucentVtxPool[translucentVertexIndex];
                        translucentVertex->v.ob[0] = D_803F2C9C;
                        translucentVertex->v.ob[1] = D_803F2C9E;
                        translucentVertex->v.ob[2] = D_803F2CA0;

                        translucentVertex->v.cn[0] = red;
                        translucentVertex->v.cn[1] = green;
                        translucentVertex->v.cn[2] = blue;
                        translucentVertex->v.cn[3] = alpha;

                        translucentVertex->v.tc[0] = tc0;
                        translucentVertex->v.tc[1] = tc1;

                        translucentMinX = MIN(translucentMinX, D_803F2C9C);
                        translucentMinY = MIN(translucentMinY, D_803F2CA0);
                        translucentMinZ = MIN(translucentMinZ, D_803F2C9E);
                        translucentMaxX = MAX(translucentMaxX, D_803F2C9C);
                        translucentMaxY = MAX(translucentMaxY, D_803F2CA0);
                        translucentMaxZ = MAX(translucentMaxZ, D_803F2C9E);
                        translucentVertexCount++;
                    }

                    // Faces with scroll indices 32..47 also record their center tile for each vertex.
                    if ((scrollIndex >= GEO_SCROLL_CENTER_MIN) && (scrollIndex < GEO_SCROLL_CENTER_MAX)) {
                        if (vertexCount == 4) {
                            maxTileX = MAX(MAX(MAX(tileX[0], tileX[1]), tileX[2]), tileX[3]);
                            maxTileZ = MAX(MAX(MAX(tileZ[0], tileZ[1]), tileZ[2]), tileZ[3]);
                            minTileX = MIN(MIN(MIN(tileX[0], tileX[1]), tileX[2]), tileX[3]);
                            minTileZ = MIN(MIN(MIN(tileZ[0], tileZ[1]), tileZ[2]), tileZ[3]);
                        }
                        // Only quads update the bounds, so a triangle uses the bounds left from an
                        // earlier face (or uninitialized ones if it is the first).
                        for (vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++) {
                            centerIndex = D_803E4AC8 + vertexIndex;
                            centerTileX = (maxTileX + minTileX) >> 1;
                            D_803E4930[centerIndex] = centerTileX;
                            centerTileZ = (maxTileZ + minTileZ) >> 1;
                            D_803E4998[centerIndex] = centerTileZ;
                            D_803E4A00[centerIndex] = translucentVertexIndices[vertexIndex];
                        }
                        D_803E4AC8 += vertexCount;
                    }

                    translucentFaceIndex = translucentFaceCount;
                    translucentFaces[translucentFaceIndex].idx = faceIndex;
                    if (faceFlags & VTX_TRIANGLE) {
                        translucentBatchVertexCount += 3;
                    } else {
                        translucentBatchVertexCount += 4;
                    }

                    translucentFaceCount++;
                    faceIndex++;

                    if (translucentFaceCount >= TRANSLUCENT_BATCH_FACE_COUNT) {
                        func_803458B8_756F68(&translucentDL, &gTranslucentVtxPool[translucentBatchStart], translucentBatchVertexCount);
                        func_80346BB4_758264(&translucentDL, translucentFaces, TRANSLUCENT_BATCH_FACE_COUNT);
                        translucentBatchStart = translucentVertexCount;
                        translucentBatchVertexCount = 0;
                        translucentFaceCount = 0;
                    }
                } else {

                    for (vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++) {
                        D_803F2C9C = (D_803F2C80[faceIndex].unk4[vertexIndex].unk7 << 6) + cellOffsetX + 0x100;
                        D_803F2C9E = (D_803F2C80[faceIndex].unk4[vertexIndex].unkA << 6) + cellOffsetZ + 0x200;

                        D_803F2CA0 = D_803F2C80[faceIndex].unk4[vertexIndex].unk8 * 8;

#ifdef __sgi
                        if (faceFlags & VTX_RENDER_MODE_DECAL) {
                            // Decal faces store the height back unchanged.
                            D_803F2CA0 = D_803F2CA0;
                        }
#endif

                        existingVertexIndex = opaqueBatchStart;
                        reusedVertexIndex = NOT_FOUND;
                        tc0 = D_803F2C80[faceIndex].unk4[vertexIndex].tc0 * 64;
                        tc1 = D_803F2C80[faceIndex].unk4[vertexIndex].tc1 * 64;
                        normalX = D_803F2C80[faceIndex].unk4[vertexIndex].red;
                        normalZ = D_803F2C80[faceIndex].unk4[vertexIndex].green;
                        normalY = D_803F2C80[faceIndex].unk4[vertexIndex].blue;
                        red = D_803F2C80[faceIndex].unk4[vertexIndex].red;
                        green = D_803F2C80[faceIndex].unk4[vertexIndex].green;
                        blue = D_803F2C80[faceIndex].unk4[vertexIndex].blue;

                        while (existingVertexIndex < opaqueVertexCount) {
                            reuseFlags = 0;
                            if (D_803F2D50.cellLightingModes[D_803F2CA2][D_803F2CA4] == 0) {
                                if ((D_803F2C9C == gOpaqueVtxPool[existingVertexIndex].v.ob[0]) &&
                                    (D_803F2C9E == gOpaqueVtxPool[existingVertexIndex].v.ob[1]) &&
                                    (D_803F2CA0 == gOpaqueVtxPool[existingVertexIndex].v.ob[2]) &&
                                    (reusedVertexIndex == NOT_FOUND)) {
                                    if ((tc0 != gOpaqueVtxPool[existingVertexIndex].v.tc[0]) ||
                                        (tc1 != gOpaqueVtxPool[existingVertexIndex].v.tc[1])) {
                                        reuseFlags = REUSED_VTX_UPDATE_TC;
                                    }
                                    if (gOpaqueVtxPool[existingVertexIndex].v.flag != 0) {
                                        reuseFlags |= REUSED_VTX_UPDATE_TC;
                                    }
                                    gOpaqueVtxPool[existingVertexIndex].v.flag = 1;
                                    if (reuseFlags == 0) {
                                        reuseFlags = REUSED_VTX_NO_TC_UPDATE;
                                    }
                                }
                            } else {
                                if ((D_803F2C9C == gOpaqueVtxPool[existingVertexIndex].v.ob[0]) &&
                                    (D_803F2C9E == gOpaqueVtxPool[existingVertexIndex].v.ob[1]) &&
                                    (D_803F2CA0 == gOpaqueVtxPool[existingVertexIndex].v.ob[2]) &&
                                    ((red & 0xF0) == (gOpaqueVtxPool[existingVertexIndex].v.cn[0] & 0xF0)) &&
                                    ((green & 0xF0) == (gOpaqueVtxPool[existingVertexIndex].v.cn[1] & 0xF0)) &&
                                    ((blue & 0xF0) == (gOpaqueVtxPool[existingVertexIndex].v.cn[2] & 0xF0)) &&
                                    (reusedVertexIndex == NOT_FOUND)) {

                                    if (((tc0 & 0xFFFF00) != (gOpaqueVtxPool[existingVertexIndex].v.tc[0] & 0xFFFF00)) ||
                                        ((tc1 & 0xFFFF00) != (gOpaqueVtxPool[existingVertexIndex].v.tc[1] & 0xFFFF00))) {
                                        reuseFlags = REUSED_VTX_UPDATE_TC;
                                    }
                                    if (gOpaqueVtxPool[existingVertexIndex].v.flag != 0) {
                                        reuseFlags |= REUSED_VTX_UPDATE_TC;
                                    }
                                    gOpaqueVtxPool[existingVertexIndex].v.flag = 1;
                                    if (reuseFlags == 0) {
                                        reuseFlags = REUSED_VTX_NO_TC_UPDATE;
                                    }
                                }
                            }
                            if (reuseFlags != 0) {
                                reuseCount++;
                                reusedVertexIndex = existingVertexIndex;
                                existingVertexIndex = opaqueVertexCount;
                            } else {
                                existingVertexIndex += 1;
#ifdef __sgi
                                // fakematch: empty check, needed to match
                                if ((D_803F2CA2 < WORLD_CELL_COUNT_X) && (D_803F2CA4 < WORLD_CELL_COUNT_Z)) {}
#endif
                            }
                        }

                        if (reusedVertexIndex != NOT_FOUND) {
                            batchVertexIndex = reusedVertexIndex - opaqueBatchStart;
                            opaqueFaces[opaqueFaceCount].v[vertexIndex] = batchVertexIndex;
                            opaqueFaces[opaqueFaceCount].flags[vertexIndex] = reuseFlags;
                        } else {
                            gOpaqueVtxPool[opaqueVertexCount].v.flag = 0;
                            gOpaqueVtxPool[opaqueVertexCount].v.ob[0] = D_803F2C9C;
                            gOpaqueVtxPool[opaqueVertexCount].v.ob[1] = D_803F2C9E;
                            gOpaqueVtxPool[opaqueVertexCount].v.ob[2] = D_803F2CA0;

                            if (D_803F2D50.cellLightingModes[D_803F2CA2][D_803F2CA4] == 0) {
                                gOpaqueVtxPool[opaqueVertexCount].n.n[0] = normalX;
                                gOpaqueVtxPool[opaqueVertexCount].n.n[1] = normalZ;
                                gOpaqueVtxPool[opaqueVertexCount].n.n[2] = normalY;
                            } else {
                                gOpaqueVtxPool[opaqueVertexCount].v.cn[0] = red;
                                gOpaqueVtxPool[opaqueVertexCount].v.cn[1] = green;
                                gOpaqueVtxPool[opaqueVertexCount].v.cn[2] = blue;
                            }

                            gOpaqueVtxPool[opaqueVertexCount].v.cn[3] = 0xFF;
                            opaqueFaces[opaqueFaceCount].flags[vertexIndex] = 0;
                            batchVertexIndex = opaqueVertexCount - opaqueBatchStart;
                            opaqueFaces[opaqueFaceCount].v[vertexIndex] = batchVertexIndex;
                            opaqueFaces[opaqueFaceCount].unk1C[vertexIndex] = opaqueVertexCount;
                            gOpaqueVtxPool[opaqueVertexCount].v.tc[0] = tc0;
                            gOpaqueVtxPool[opaqueVertexCount].v.tc[1] = tc1;
                            opaqueVertexCount += 1;
                        }

                        if (opaqueMinX >= D_803F2C9C) {
                            opaqueMinX = D_803F2C9C;
                        }
                        if (opaqueMinY >= D_803F2CA0) {
                            opaqueMinY = D_803F2CA0;
                        }
                        if (opaqueMinZ >= D_803F2C9E) {
                            opaqueMinZ = D_803F2C9E;
                        }
                        if (D_803F2C9C >= opaqueMaxX) {
                            opaqueMaxX = D_803F2C9C;
                        }
                        if (D_803F2CA0 >= opaqueMaxY) {
                            opaqueMaxY = D_803F2CA0;
                        }
                        if (D_803F2C9E >= opaqueMaxZ) {
                            opaqueMaxZ = D_803F2C9E;
                        }
                    }

                    opaqueFaces[opaqueFaceCount++].idx = faceIndex++;

                    opaqueBatchVertexCount = opaqueVertexCount - opaqueBatchStart;
                    // Leave room for the next quad in the 32-vertex cache.
                    if (opaqueBatchVertexCount > OPAQUE_BATCH_FLUSH_THRESHOLD) {
                        func_803458B8_756F68(&opaqueDL, &gOpaqueVtxPool[opaqueBatchStart], opaqueBatchVertexCount);
                        func_803458FC_756FAC(&opaqueDL, opaqueFaces, opaqueFaceCount);
                        opaqueBatchStart = opaqueVertexCount;
                        opaqueFaceCount = 0;
                    }
                }
            } while (!(faceFlags & VTX_CELL_END));

            // Build the opaque cell's eight-vertex cull box (game axes x, z, y).
            D_80224870[cullVertexBase + 0].v.ob[0] = opaqueMinX;
            D_80224870[cullVertexBase + 0].v.ob[1] = opaqueMinZ;
            D_80224870[cullVertexBase + 0].v.ob[2] = opaqueMinY;

            D_80224870[cullVertexBase + 1].v.ob[0] = opaqueMaxX;
            D_80224870[cullVertexBase + 1].v.ob[1] = opaqueMinZ;
            D_80224870[cullVertexBase + 1].v.ob[2] = opaqueMinY;

            D_80224870[cullVertexBase + 2].v.ob[0] = opaqueMinX;
            D_80224870[cullVertexBase + 2].v.ob[1] = opaqueMaxZ;
            D_80224870[cullVertexBase + 2].v.ob[2] = opaqueMinY;

            D_80224870[cullVertexBase + 3].v.ob[0] = opaqueMaxX;
            D_80224870[cullVertexBase + 3].v.ob[1] = opaqueMaxZ;
            D_80224870[cullVertexBase + 3].v.ob[2] = opaqueMinY;

            D_80224870[cullVertexBase + 4].v.ob[0] = opaqueMinX;
            D_80224870[cullVertexBase + 4].v.ob[1] = opaqueMinZ;
            D_80224870[cullVertexBase + 4].v.ob[2] = opaqueMaxY;

            D_80224870[cullVertexBase + 5].v.ob[0] = opaqueMaxX;
            D_80224870[cullVertexBase + 5].v.ob[1] = opaqueMinZ;
            D_80224870[cullVertexBase + 5].v.ob[2] = opaqueMaxY;

            D_80224870[cullVertexBase + 6].v.ob[0] = opaqueMinX;
            D_80224870[cullVertexBase + 6].v.ob[1] = opaqueMaxZ;
            D_80224870[cullVertexBase + 6].v.ob[2] = opaqueMaxY;

            D_80224870[cullVertexBase + 7].v.ob[0] = opaqueMaxX;
            D_80224870[cullVertexBase + 7].v.ob[1] = opaqueMaxZ;
            D_80224870[cullVertexBase + 7].v.ob[2] = opaqueMaxY;

            // Build the translucent cell's cull box.
            D_8022D350[cullVertexBase + 0].v.ob[0] = translucentMinX;
            D_8022D350[cullVertexBase + 0].v.ob[1] = translucentMinZ;
            D_8022D350[cullVertexBase + 0].v.ob[2] = translucentMinY;

            D_8022D350[cullVertexBase + 1].v.ob[0] = translucentMaxX;
            D_8022D350[cullVertexBase + 1].v.ob[1] = translucentMinZ;
            D_8022D350[cullVertexBase + 1].v.ob[2] = translucentMinY;

            D_8022D350[cullVertexBase + 2].v.ob[0] = translucentMinX;
            D_8022D350[cullVertexBase + 2].v.ob[1] = translucentMaxZ;
            D_8022D350[cullVertexBase + 2].v.ob[2] = translucentMinY;

            D_8022D350[cullVertexBase + 3].v.ob[0] = translucentMaxX;
            D_8022D350[cullVertexBase + 3].v.ob[1] = translucentMaxZ;
            D_8022D350[cullVertexBase + 3].v.ob[2] = translucentMinY;

            D_8022D350[cullVertexBase + 4].v.ob[0] = translucentMinX;
            D_8022D350[cullVertexBase + 4].v.ob[1] = translucentMinZ;
            D_8022D350[cullVertexBase + 4].v.ob[2] = translucentMaxY;

            D_8022D350[cullVertexBase + 5].v.ob[0] = translucentMaxX;
            D_8022D350[cullVertexBase + 5].v.ob[1] = translucentMinZ;
            D_8022D350[cullVertexBase + 5].v.ob[2] = translucentMaxY;

            D_8022D350[cullVertexBase + 6].v.ob[0] = translucentMinX;
            D_8022D350[cullVertexBase + 6].v.ob[1] = translucentMaxZ;
            D_8022D350[cullVertexBase + 6].v.ob[2] = translucentMaxY;

            D_8022D350[cullVertexBase + 7].v.ob[0] = translucentMaxX;
            D_8022D350[cullVertexBase + 7].v.ob[1] = translucentMaxZ;
            D_8022D350[cullVertexBase + 7].v.ob[2] = translucentMaxY;

            if (opaqueFaceCount != 0) {
                opaqueBatchVertexCount = opaqueVertexCount - opaqueBatchStart;
                func_803458B8_756F68(&opaqueDL, &gOpaqueVtxPool[opaqueBatchStart], opaqueBatchVertexCount);
                func_803458FC_756FAC(&opaqueDL, opaqueFaces, opaqueFaceCount);
                opaqueBatchStart = opaqueVertexCount;
                opaqueFaceCount = 0;
            }
            if (translucentFaceCount != 0) {
                func_803458B8_756F68(&translucentDL, &gTranslucentVtxPool[translucentBatchStart], translucentBatchVertexCount);
                func_80346BB4_758264(&translucentDL, translucentFaces, translucentFaceCount);
                translucentBatchStart = translucentVertexCount;
                translucentBatchVertexCount = 0;
                translucentFaceCount = 0;
            }
            gSPEndDisplayList(opaqueDL++);
            gSPEndDisplayList(translucentDL++);
        }
        D_803F2CA4++;
    }
    gSPEndDisplayList(opaqueDL++);
    gSPEndDisplayList(translucentDL++);
}

void func_803458B8_756F68(Gfx **dl, Vtx *vtx, s16 num) {
    gSPVertex((*dl)++, K0_TO_PHYS(vtx), num, 0);
}

// Emit opaque faces from the level geometry using batch-local vertex slots.
void func_803458FC_756FAC(Gfx **dl, struct115 *faces, s16 numFaces) {
    s32 reuseFlags;
    s16 i;
    s16 cornersDrawn; // The target updates this tally without using the result.
    s16 j;

    u8 scrollIndex;
    u8 variant;
    u16 vtxFlags;

    s16 s;
    s16 t;
    u32 packedST;

    cornersDrawn = 0;

    for (i = 0; i < numFaces; i++) {
        u32 scrollType;

        vtxFlags = D_803F2C80[faces[i].idx].header.flags;
        variant = D_803F2C80[faces[i].idx].header.unk2;
        scrollIndex = D_803F2C80[faces[i].idx].header.unk3;

        if ((vtxFlags & 0x8) ||
            (vtxFlags & VTX_ALPHA_COMPARE_DITHER) ||
            (vtxFlags & 0x2000) ||
            (vtxFlags & 0x100)) {
            if (vtxFlags & 0x8) {
                if (D_803F2C86 != 4) {
                    gDPSetCombineLERP((*dl)++,
                        TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,
                        0, 0, 0, TEXEL0,
                        COMBINED, 0, SHADE, 0,
                        0, 0, 0, SHADE);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b,
                               2, 0x0180, 1, 0,
                               G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD,
                               G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                    gDPTileSync((*dl)++);

                    D_803F2C86 = 4;
                }
            }

            if (vtxFlags & 0x100) {
                scrollType = 6;
                if (D_803F2C86 != 12) {
                    gDPSetCombineLERP((*dl)++,
                        TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,
                        0, 0, 0, TEXEL0,
                        COMBINED, 0, SHADE, 0,
                        0, 0, 0, SHADE);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b,
                               1, 0x01C0, 1, 0,
                               G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD,
                               G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);

                    D_803F2C86 = 12;
                }
                D_803E3130[D_803F2CA6].flags |= 1;
                D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                D_803E3130[D_803F2CA6].type = scrollType;
                D_803E3130[D_803F2CA6].displayList = *dl;
                gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);

                D_803F2CA6++;
                D_803F2C92 = 1;
            }
        } else {
            if (variant > 40) {
                if (D_803F2C86 != 14) {
                    D_803F2C8E = 0;
                    gDPPipeSync((*dl)++);
                    gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                    gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                    gDPSetCombineMode((*dl)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                    gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_TEX_EDGE2);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 6, G_ON);

                    if (variant != D_803F2C96) {
                        scrollType = variant - 33;
                        // Queue the animated texture setup for later updates.
                        D_803E3130[D_803F2CA6].flags |= 1;
                        D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                        D_803E3130[D_803F2CA6].type = scrollType;
                        D_803E3130[D_803F2CA6].displayList = *dl;
                        D_803F2CA6++;

                        gDPLoadMultiBlock(
                            (*dl)++,
                            OS_K0_TO_PHYSICAL(img_D_0102C810_660E0_i8__png),
                            0x0000,
                            6,
                            G_IM_FMT_I,
                            G_IM_SIZ_8b,
                            32,
                            32,
                            0,
                            G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP,
                            5,
                            5,
                            G_TX_NOLOD,
                            G_TX_NOLOD);

                        D_803F2C96 = variant;
                        D_803F2C97 = 0xFF;
                    }
                    D_803F2C86 = 14;
                }
            } else if (!(vtxFlags & 0x8)) {
                if (D_803F2C86 != 1) {
                    gDPPipeSync((*dl)++);
                    gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                    gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
                    gDPSetTextureLOD((*dl)++, G_TL_LOD);
                    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                               4, 0x0100, 1, 0,
                               G_TX_NOMIRROR | G_TX_WRAP, 4, 1,
                               G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                    gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);

                    D_803F2C86 = 1;
                }
            }

            if (scrollIndex) {
                scrollType = 1;

                // The target stores 1 and then reloads and tests the state.
                D_803F2C86 = 1;
                if (D_803F2C86) {
                    D_803E3130[D_803F2CA6].flags |= 1;
                    D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                    D_803E3130[D_803F2CA6].type = scrollType;

                    D_803E3130[D_803F2CA6].displayList = *dl;

                    gDPSetTileSize((*dl)++, 0, 0, 0, (32 - 1) * 4, (32 - 1) * 4);
                    gDPSetTileSize((*dl)++, 1, 0, 0, (16 - 1) * 4, (16 - 1) * 4);
                    gDPSetTileSize((*dl)++, 2, 0, 0,  (8 - 1) * 4,  (8 - 1) * 4);
                    gDPTileSync((*dl)++);
                    gDPPipeSync((*dl)++);

                    D_803F2CA6++;
                    D_803F2C92 = 1;
                }
            }
        }

        if (vtxFlags & VTX_ALPHA_COMPARE_DITHER) {
            if (D_803F2C99 == 0) {
                gDPPipeSync((*dl)++);
                gSPTexture((*dl)++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEIDECALA);
                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_TEX_EDGE2);
                D_803F2C99 = 1;
            }
        } else {
            if (D_803F2C99 == 1) {
                gDPPipeSync((*dl)++);
                gSPTexture((*dl)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
                D_803F2C99 = 0;
            }
        }

        if (vtxFlags & VTX_RENDER_MODE_DECAL) {
            if (D_803F2C8E != 1) {
                D_803F2C8E = 1;
                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_ZB_OPA_DECAL2);
            }
        } else {
            if (D_803F2C8E != 0) {
                D_803F2C8E = 0;
                if (variant > 40) {
                    gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_TEX_EDGE2);
                } else {
                    gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);
                }
            }
        }

        if (vtxFlags & VTX_RENDER_MODE_INTER) {
            if (D_803F2C88 != 2) {
                D_803F2C88 = 2;
                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_OPA_INTER2);
            }
        } else if (D_803F2C88 != 1) {
            // D_803F2C88 is left unchanged here.
            gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);
        }

        if (variant != D_803F2C96) {
            if (variant < GEO_TEXTURE_ANIMATED_MIN) {
                func_80346878_757F28(dl, variant);
            }
            D_803F2C96 = variant;
            D_803F2C97 = 0xFF;
        }

        if (vtxFlags & VTX_NO_CULL_BACK) {
            if (D_803F2C9A == 0) {
                gSPClearGeometryMode((*dl)++, G_CULL_BACK);
                D_803F2C9A = 1;
            }
        }
        if ((vtxFlags & VTX_NO_CULL_BACK) == 0) {
            if (D_803F2C9A == 1) {
                gSPSetGeometryMode((*dl)++, G_CULL_BACK);
                D_803F2C9A = 0;
            }
        }

        if (vtxFlags & 0x80) {
            if (D_803F2C8A != 0) {
                D_803F2C8A = 0;
            }
        } else if (D_803F2C8A != 1) {
            D_803F2C8A = 1;
        }

        if (vtxFlags & 0x400) {
            if (D_803F2C8C != 1) {
                gDPSetCombineLERP((*dl)++,
                    TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,
                    TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,
                    COMBINED, PRIMITIVE, SHADE, 0,
                    0, 0, 0, SHADE);
                gDPSetPrimColor((*dl)++, 128, 128, 45, 45, 45, 0);
                D_803F2C8C = 1;
            }
        } else if (D_803F2C8C == 1) {
            gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
            D_803F2C8C = 0;
        }

        if (!scrollIndex) {
            if (D_803F2C92 != 0) {
                if ((vtxFlags & VTX_ALPHA_COMPARE_DITHER) == 0) {
                    gDPSetTileSize((*dl)++, 0, 0, 0, (32 - 1) * 4, (32 - 1) * 4);
                }
                gDPSetTileSize((*dl)++, 1, 0, 0, (16 - 1) * 4, (16 - 1) * 4);
                gDPSetTileSize((*dl)++, 2, 0, 0,  (8 - 1) * 4,  (8 - 1) * 4);
                gDPSetTileSize((*dl)++, 3, 0, 0,  (4 - 1) * 4,  (4 - 1) * 4);
                gDPSetTileSize((*dl)++, 4, 0, 0,  (2 - 1) * 4,  (2 - 1) * 4);
                gDPSetTileSize((*dl)++, 5, 0, 0,  (1 - 1) * 4,  (1 - 1) * 4);

                D_803F2C92 = 0;
            }
        }

        // Restore texture coordinates for reused slots before drawing the face.
        if (!(vtxFlags & VTX_TRIANGLE)) {
            for (j = 0; j < 4; j++) {
#ifdef __sgi
                // fakematch: Preserve IDO register allocation for the vertex updates.
                if (((j == -1) & (faces[i].v[0] == -2)) ||
                    ((j == -2) & (faces[i].v[0] == -1))) {
                }
#endif
                reuseFlags = faces[i].flags[j];
                if ((reuseFlags != 0) && (reuseFlags & REUSED_VTX_UPDATE_TC)) {
                    s = (s16)(D_803F2C80[faces[i].idx].unk4[j].tc0 * 32);
                    t = (s16)(D_803F2C80[faces[i].idx].unk4[j].tc1 * 32);

                    packedST = (((u32)s << 16) & 0xFFFF0000) | (t & 0xFFFF);
                    gSPModifyVertex((*dl)++, faces[i].v[j], G_MWO_POINT_ST, packedST);
                }
            }

            gSP2Triangles((*dl)++,
                          faces[i].v[2], faces[i].v[1], faces[i].v[0], 0,
                          faces[i].v[2], faces[i].v[3], faces[i].v[1], 0);

            cornersDrawn++;
        } else {
            for (j = 0; j < 3; j++) {
                reuseFlags = faces[i].flags[j];
                if ((reuseFlags != 0) && (reuseFlags & REUSED_VTX_UPDATE_TC)) {
                    s = (s16)(D_803F2C80[faces[i].idx].unk4[j].tc0 * 32);
                    t = (s16)(D_803F2C80[faces[i].idx].unk4[j].tc1 * 32);

                    packedST = (((u32)s << 16) & 0xFFFF0000) | (t & 0xFFFF);
                    gSPModifyVertex((*dl)++, faces[i].v[j], G_MWO_POINT_ST, packedST);
                }
            }

            gSP1Triangle((*dl)++, faces[i].v[2], faces[i].v[1], faces[i].v[0], 0);
        }
        cornersDrawn += 3;
    }
}

void func_80346878_757F28(Gfx **dl, u8 idx) {
    if (idx < 32) {
        gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760 + idx * 0xAB8);
        gDPTileSync((*dl)++);
        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTextureImage((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_800BA760 + idx * 0xAB8);
        gDPTileSync((*dl)++);
        gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    }
    gDPTileSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 1372, 0);
    gDPTileSync((*dl)++);
}

// load_metal_texture?
void func_803469D4_758084(Gfx **dl, u8 idx) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img_D_0102F010_688E0_rgba16__png + ((idx&0xFF) << 7));
    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 31, 256);
    gDPPipeSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 0);
}

// load_xlui_texture
void func_80346AB0_758160(Gfx **dl, u8 idx) {
    osSyncPrintf("load xlui texture - %d\n", idx);
    gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760 + idx * 0xAB8);
    gDPTileSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 1024, 0);
    gDPTileSync((*dl)++);
}

// Emit the translucent display list for a batch of faces, using sequential vertex indices.
void func_80346BB4_758264(Gfx **dl, struct115 *faces, s16 numFaces) {
    s32 scrollType;
    s16 i;
    s16 vertexBase;

    u16 vtxFlags;
    u8  scrollIndex;
    u8  textureIndex;
    s32 animationType;
    s16 loadBaseTexture;

    s16 vertexIndex;
    // isTriangle, textureChanged, drawCommand and isAnimatedTexture are needed to match;
    // inlining them changes the generated code.
    s32 isTriangle;
    s32 textureChanged;
    s32 disableBackfaceCull;
    Gfx *drawCommand;
    s32 isAnimatedTexture;

    s16 vertexCount;

    vertexBase = 0;

    for (i = 0; i < numFaces; i++) {
        loadBaseTexture = 1;

        vtxFlags = D_803F2C80[faces[i].idx].header.flags;
        scrollIndex = D_803F2C80[faces[i].idx].header.unk3;
        textureIndex = D_803F2C80[faces[i].idx].header.unk2;

        if ((vtxFlags & VTX_TRANSLUCENT) ||
            (vtxFlags & 0x10) ||
            (vtxFlags & 0x200) ||
            (vtxFlags & 0x8000) ||
            (vtxFlags & 0x100) ||
            (vtxFlags & 0x1000)) {

            if ((vtxFlags & 0x8000) && (D_803F2C84 != 7)) {
                gDPSetCombineMode((*dl)++, G_CC_MODULATEI, G_CC_PASS2);
                gDPSetRenderMode((*dl)++, G_RM_PASS, gRenderMode2);
                D_803F2C84 = 7;
            }

            if (vtxFlags & 0x10) {
                loadBaseTexture = 0;
                if (D_803F2C84 != 3) {
                    gDPPipeSync((*dl)++);
                    gDPSetCombineLERP((*dl)++,
                        TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0,
                        0, 0, 0, PRIMITIVE,
                        PRIMITIVE, SHADE, COMBINED, SHADE,
                        0, 0, 0, PRIMITIVE);
                    gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 5, G_ON);

                    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, img_D_0102B610_64EE0_i4__png);

                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x019E, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync((*dl)++);
                    gDPLoadTile((*dl)++, G_TX_LOADTILE, 0, 0, 62, 124);
                    gDPPipeSync((*dl)++);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x019E, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPPipeSync((*dl)++);
                    D_803F2C84 = 3;
                }

                D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                D_803E3130[D_803F2CA6].flags |= 1;

                if (scrollIndex) {
                    scrollType = 0;
                    D_803E3130[D_803F2CA6].type = scrollType;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*dl)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC);
                } else {
                    scrollType = 7;
                    D_803E3130[D_803F2CA6].type = scrollType;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0xDC);
                }
                D_803F2CA6++;
                D_803F2C94 = 1;
            }
            if (vtxFlags & 0x200) {
                loadBaseTexture = 0;
                if (D_803F2C84 != 6) {
                    gDPSetCombineLERP((*dl)++,
                        TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0,
                        TEXEL1, PRIMITIVE, SHADE, PRIMITIVE,
                        PRIMITIVE, SHADE, COMBINED, SHADE,
                        0, 0, 0, COMBINED);
                    gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 5, G_ON);
                    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, img_D_0102B810_650E0_i4__png);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x01A0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync((*dl)++);
                    gDPLoadTile((*dl)++, G_TX_LOADTILE, 0, 0, 62, 124);
                    gDPPipeSync((*dl)++);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x01A0, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPPipeSync((*dl)++);
                    D_803F2C84 = 6;
                }
                D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                D_803E3130[D_803F2CA6].flags |= 1;

                if (scrollIndex) {
                    scrollType = 3;
                    D_803E3130[D_803F2CA6].type = scrollType;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*dl)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC);
                } else {
                    scrollType = 7;
                    D_803E3130[D_803F2CA6].type = scrollType;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetPrimColor((*dl)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC);
                    gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                }
                D_803F2CA6++;
                D_803F2C94 = 1;
            }
            if (vtxFlags & 0x100) {
                loadBaseTexture = 0;
                if (D_803F2C84 != 11) {
                    gSPClearGeometryMode((*dl)++, G_FOG);
                    gDPSetCombineLERP((*dl)++,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);
                    gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 6, G_ON);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 6, 0x01DE, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);

                    D_803F2C84 = 11;
                }
                D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                D_803E3130[D_803F2CA6].flags |= 1;
                scrollType = 5;
                D_803E3130[D_803F2CA6].type = scrollType;
                D_803E3130[D_803F2CA6].displayList = *dl;
                gDPSetTileSize((*dl)++, 6, 0, 0, 60, 60);

                D_803F2CA6++;
                D_803F2C94 = 1;
            }
            if (vtxFlags & 0x1000) {
                loadBaseTexture = 0;
                if (D_803F2C84 != 13) {
                    gSPClearGeometryMode((*dl)++, G_FOG);
                    gDPSetCombineLERP((*dl)++,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        TEXEL0, SHADE, PRIMITIVE, SHADE,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);
                    gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 5, G_ON);

                    D_803F2C84 = 13;
                }
                D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                D_803E3130[D_803F2CA6].flags |= 1;
                scrollType = 5;
                D_803E3130[D_803F2CA6].type = scrollType;
                D_803E3130[D_803F2CA6].displayList = *dl;
                gDPSetTileSize((*dl)++, 5, 0, 0, 60, 60);

                D_803F2CA6++;
                D_803F2C94 = 1;
            }

            if ((vtxFlags & VTX_TRANSLUCENT) &&
                (!(vtxFlags & 0x10)) &&
                (!(vtxFlags & 0x200)) &&
                (!(vtxFlags & 0x100))) {

                // The flags are read from the face again here.
                {
                    const struct102 *geo = D_803F2C80;
                    s32 faceIndex = faces[i].idx;

                    vtxFlags = geo[faceIndex].header.flags;
                }

                isAnimatedTexture = textureIndex >= GEO_TEXTURE_ANIMATED_MIN;
                if (isAnimatedTexture) {
                    if (D_803F2C84 != 14) {
                        gDPPipeSync((*dl)++);
                        if (textureIndex > 40) {
                            gDPSetCombineMode((*dl)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                            gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                            gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x01);

                            if (vtxFlags & VTX_RENDER_MODE_DECAL) {
                                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_ZB_XLU_DECAL2);
                            } else {
                                gDPSetRenderMode((*dl)++, gRenderMode1, D_803F2CC0);
                            }
                            gDPSetTextureLOD((*dl)++, G_TL_TILE);
                            gSPTexture((*dl)++, 0x8000, 0x8000, 0, 6, G_ON);

                            D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                            D_803E3130[D_803F2CA6].flags |= 1;
                            D_803E3130[D_803F2CA6].displayList = *dl;
                            animationType = textureIndex - 33;
                            D_803E3130[D_803F2CA6].type = animationType;
                            D_803F2CA6++;

                            switch (animationType) {
                                case 9:
                                    gDPLoadTextureBlock((*dl)++, OS_K0_TO_PHYSICAL(img_D_0102C810_660E0_i8__png + 0x1000), G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                                default:
                                    gDPLoadTextureBlock((*dl)++, OS_K0_TO_PHYSICAL(img_D_0102C810_660E0_i8__png), G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
                                    break;
                            }
                            gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        } else {
                            gDPSetCombineLERP((*dl)++,
                                TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,
                                TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,
                                COMBINED, 0, SHADE, 0,
                                0, SHADE, 0, COMBINED);

                            if (vtxFlags & VTX_RENDER_MODE_DECAL) {
                                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_ZB_XLU_DECAL2);
                            } else {
                                gDPSetRenderMode((*dl)++, gRenderMode1, D_803F2CC0);
                            }

                            gDPSetTextureLOD((*dl)++, G_TL_LOD);
                            gSPTexture((*dl)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                            gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                            gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x01);

                            gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
                            gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                            gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                            gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                            gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                            gDPSetTile((*dl)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 0, 5, G_TX_NOMIRROR | G_TX_WRAP, 0, 5);
                            gDPSetTileSize((*dl)++, 5, 0, 0, 0, 0);

                            D_803F2C84 = 14;
                        }
                        if (scrollIndex) {
                            D_803E3130[D_803F2CA6].flags |= 1;
                            D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                            scrollType = 11;
                            D_803E3130[D_803F2CA6].type = scrollType;
                            D_803E3130[D_803F2CA6].displayList = *dl;
                            D_803F2CA6++;

                            D_803F2C94 = 1;

                            gDPSetTileSize((*dl)++, 0, 0, 0, 124, 124);
                            gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
                            gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
                        }
                    }
                } else {
                    vertexCount = (vtxFlags & VTX_TRIANGLE) ? 3 : 4;

                    // This increments the bound, not the index, so the loop only ends
                    // once vertexCount wraps negative.
                    vertexIndex = 0;
                    if (vertexIndex >= vertexCount) {
                        goto skipVertexLoop;
                    }
                    do {
#ifdef __sgi
                        // fakematch: empty check, needed to match
                        if ((D_803F2C80[faces[i].idx].header.flags != 0) || (vertexIndex == 0) || (vertexIndex < vertexCount)) {} else {}
#endif
                        vertexCount++;
                    } while (vertexIndex < vertexCount);
                skipVertexLoop:;

                    if ((D_803F2C84 != 9) && (textureIndex != 0)) {
                        gDPPipeSync((*dl)++);
                        gSPClearGeometryMode((*dl)++, G_FOG);
                        gDPSetEnvColor((*dl)++, 0x00, 0x00, 0x80, 0x80);

                        if (vtxFlags & VTX_RENDER_MODE_DECAL) {
                            gDPSetRenderMode((*dl)++, G_RM_PASS, G_RM_ZB_XLU_DECAL2);
                        } else {
                            gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                        }
                        if (vtxFlags & VTX_ALPHA_COMPARE_DITHER) {
                            gDPSetAlphaCompare((*dl)++, G_AC_DITHER);
                        } else {
                            gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                        }
                        gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
                        gSPTexture((*dl)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                        gDPSetTextureLOD((*dl)++, G_TL_LOD);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 0, 5, G_TX_NOMIRROR | G_TX_WRAP, 0, 5);
                        gDPSetTileSize((*dl)++, 5, 0, 0, 0, 0);

                        D_803F2C84 = 9;
                    }

                    if ((scrollIndex) &&
                        !(vtxFlags & 0x100) &&
                        !(vtxFlags & 0x10) &&
                        !(vtxFlags & 0x200)) {
                        D_803E3130[D_803F2CA6].scrollIndex = scrollIndex;
                        D_803E3130[D_803F2CA6].flags |= 1;
                        scrollType = 4;
                        D_803E3130[D_803F2CA6].type = scrollType;
                        D_803E3130[D_803F2CA6].displayList = *dl;

                        gDPSetTileSize((*dl)++, 0, 0, 0, 124, 124);
                        gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
                        gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
                        gDPTileSync((*dl)++);
                        gDPPipeSync((*dl)++);

                        D_803F2CA6++;
                        D_803F2C94 = 1;
                    }
                    if ((textureIndex == 0) && (D_803F2C84 != 10)) {
                        gDPPipeSync((*dl)++);
                        gSPClearGeometryMode((*dl)++, G_FOG);
                        gDPSetEnvColor((*dl)++, 0x00, 0x00, 0x80, 0x80);

                        if (vtxFlags & VTX_RENDER_MODE_DECAL) {
                            gDPSetRenderMode((*dl)++, G_RM_PASS, G_RM_ZB_XLU_DECAL2);
                        } else {
                            gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                        }

                        if (vtxFlags & VTX_ALPHA_COMPARE_DITHER) {
                            gDPSetAlphaCompare((*dl)++, G_AC_DITHER);
                        } else {
                            gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                        }
                        gDPSetCombineMode((*dl)++, G_CC_SHADE, G_CC_PASS2);

                        D_803F2C84 = 10;
                    }
                }
            }
            disableBackfaceCull = vtxFlags & VTX_NO_CULL_BACK;
        } else {
            disableBackfaceCull = vtxFlags & VTX_NO_CULL_BACK;
        }

        textureChanged = textureIndex != D_803F2C98;
        if (textureChanged) {
            if (loadBaseTexture == 1) {
                if (textureIndex <= 40) {
                    func_80346878_757F28(dl, textureIndex);
                    D_803F2C98 = textureIndex;
                } else {
                    D_803F2C98 = 100;
                }
            }
        }
        if (disableBackfaceCull) {
            if (D_803F2C9B == 0) {
                gSPClearGeometryMode((*dl)++, G_CULL_BACK);
                D_803F2C9B = 1;
            }
        } else if (D_803F2C9B == 1) {
            gSPSetGeometryMode((*dl)++, G_CULL_BACK);
            D_803F2C9B = 0;
        }
        if ((!scrollIndex) && (D_803F2C94 != 0)) {
            gDPSetTileSize((*dl)++, 0, 0, 0, 124, 124);
            gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
            gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
            gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
            gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
            D_803F2C94 = 0;
        }

        isTriangle = vtxFlags & VTX_TRIANGLE;
        if (!isTriangle) {
            drawCommand = (*dl)++;
            gSP2Triangles(drawCommand,
                          vertexBase + 2, vertexBase + 1, vertexBase, 0,
                          vertexBase + 2, vertexBase + 3, vertexBase + 1, 0);
            vertexBase++;
        } else {
            drawCommand = (*dl)++;
            gSP1Triangle(drawCommand, vertexBase + 2, vertexBase + 1, vertexBase, 0);
        }
        vertexBase += 3;
    }
}
