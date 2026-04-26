#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

typedef struct {
  u16  flags;
  u8   unk2;  // texture index?
  u8   unk3;  // index? offset?
} struct102_header; // size 0x4

typedef struct {
    s16 tc0;   // tc0 (u)
    s16 tc1;   // tc1 (v)
    u8  red;   // cn[0]
    u8  green; // cn[1]
    u8  blue;  // cn[2]
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
    /* 0xC  */ s16 flags[4]; // has texture?
    /* 0x14 */ s16 unk14[4]; // unused?
    /* 0x1C */ s16 unk1C[4];
} struct115; // size 0x24

void func_803458B8_756F68(Gfx **dl, Vtx *vtx, s16 numVtxs);
void func_803458FC_756FAC(Gfx **dl, struct115 *arg1, s16 numVtxs);
void func_80346878_757F28(Gfx **dl, u8 idx);
void func_803469D4_758084(Gfx **dl, u8 idx);
void func_80346AB0_758160(Gfx **dl, u8 idx);
void func_80346BB4_758264(Gfx **dl, struct115* arg1, s16 numVtxs);


#define VTX_TRIANGLE                0x1
#define VTX_HAS_NEXT                0x2
#define VTX_CULL_BACK               0x4
#define VTX_TRANSLUCENT             0x20
#define VTX_ALPHA_COMPARE_DITHER    0x40
#define VTX_RENDER_MODE_DECAL       0x4000

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

#if 0
// CURRENT (22648)
// process_level_geo
void func_80344240_7558F0(void) {
    s16 spFC6; // faceIndex
    s16 spFC2; // cellXOffset
    s16 spFC0; // cellZOffset
    s16 vtxCount;

    s16 opaqueMaxZ; // maxZ
    s16 opaqueMaxY; // maxY
    s16 opaqueMaxX; // maxX
    s16 opaqueMinZ; // minZ
    s16 opaqueMinY; // minY
    s16 opaqueMinX; // minX

    s16 transMaxZ; // maxZ
    s16 transMaxY; // maxY
    s16 transMaxX; // maxX
    s16 transMinZ; // minZ
    s16 transMinY; // minY
    s16 transMinX; // minX

    s16 numOpaqueVtxsBatch; // opaqueBatchStart

    s16 numOpaqueVtxs; // spF94
    s16 totalTransVtxs; // translucentVertCountTotal
    s16 transVtxBatchIdx; // translucentBatchStart
    s16 numTransVtxsBatch; // spF8E
    s16 numTransVtxs; // spF8C
    s16 spF88; // cullBoxBaseIndex

    s16 batch;
    s16 batchIdx;
    s16 foundVtxIdx;
    s16 i;
    s16 flags; // flags
    s16 opaqueVtxsIdx;
    s16 j;
    u8 temp_t2; // red
    u8 temp_t3; // green
    u8 temp_t4; // blue
    u8 temp_t5_2;
    u8 alpha;

    s16 texIdx;

    s16 spF72;
    s16 spF70;
    s16 spF6E;
    s16 spF6C;

    s16 tc0;
    s16 tc1;

    u8  spF64[4];
    u8  spF60[4];
    u16 spF58[4];

    struct115 opaqueVtxs[50];      // sp 0x850 // (0xF58 - 0x850) / 0x24 => 50
    struct115 translucentVtxs[50]; // sp 0x148 // (0x850 - 0x148) / 0x24 => 50

    s8 sp147;
    s8 sp146;
    s8 sp145;

    s32 vtxFlags;
    Gfx *opaqueDL; // sp13C
    Gfx *translucentDL; // sp138

    s32 sp40;

    // NOTE: geo data has been copied into D_80100000 before this function is called
    D_803F2C80 = (struct102*)&D_80100000;

    gRenderMode2 = 0x110038;
    D_803F2CC0 = 0x1049D8; // renderMode

    D_803F2CA6 = 0;
    D_803F2C99 = 0;
    D_803F2C9A = 0;
    D_803F2C9B = 0;
    D_803E4AC8 = 0; // reset totalTris

    spFC6 = 0;
    opaqueVtxsIdx = 0;

    numOpaqueVtxsBatch = 0;
    numOpaqueVtxs = 0;

    totalTransVtxs = 0;
    numTransVtxsBatch = 0;

    transVtxBatchIdx = 0;
    numTransVtxs = 0;

    opaqueDL = &D_80205470[0];
    translucentDL = &D_80225650[1]; // +1 because we use [0] now:
    gDPSetCombineMode(D_80225650, G_CC_SHADE, G_CC_SHADE);

    for (D_803F2CA4 = 0; D_803F2CA4 < 6; D_803F2CA4++) {
        for (D_803F2CA2 = 0; D_803F2CA2 < 4; D_803F2CA2++) {
            D_803F2C8C = 0;
            D_803F2C8E = 0;
            D_803F2C90 = 0;

            gWorldCellTranslucentEnabled[D_803F2CA2][D_803F2CA4] = 0; // disabled

            D_803F2C86 = 1;
            D_803F2C88 = 1;
            D_803F2C8A = 1;

            D_803F2C84 = 1000; // some kind of state?
            D_803F2C96 = 0xFF; // -1?
            D_803F2C98 = 0xFF; // -1?
            D_803F2C97 = 0xFF; // only set, never checked

            opaqueMaxX = -30000;
            opaqueMaxY = -30000;
            opaqueMaxZ = -30000;
            opaqueMinX = 30000;
            opaqueMinY = 30000;
            opaqueMinZ = 30000;

            transMaxX = -30000;
            transMaxY = -30000;
            transMaxZ = -30000;
            transMinX = 30000;
            transMinY = 30000;
            transMinZ = 30000;

            gWorldCellOpaqueDisplayLists[D_803F2CA2][D_803F2CA4] = opaqueDL;
            gWorldCellTranslucentDisplayLists[D_803F2CA2][D_803F2CA4] = translucentDL;
            // opaqueDL->words.w0 = 0xB6000000;
            // opaqueDL->words.w1 = -1U;
            gSPClearGeometryMode(opaqueDL++, -1); // help
            // opaqueDL->words.w0 = 0x0400207F;
            // opaqueDL->words.w1 = (s32) (((s16) ((D_803F2CA2 << 3) + (D_803F2CA4 << 5)) * 0x10) + &D_80224870) & 0x1FFFFFFF;
            gSPVertex(
                opaqueDL++,
                K0_TO_PHYS(&D_80224870[(s16) ((D_803F2CA2 << 3) + (D_803F2CA4 << 5))]),
                8,
                0);
            // BE000000 0000000E
            gSPCullDisplayList(opaqueDL++, 0, 7);
            if (D_803F2D50.unk5C[D_803F2CA2][D_803F2CA4] == 0) {
                // lighting
                gSPSetGeometryMode(opaqueDL++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_CLIPPING);
            } else {
                // no lighting
                gSPSetGeometryMode(opaqueDL++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG |              G_SHADING_SMOOTH | G_CLIPPING);
            }
            // BB002801 80008000
            gSPTexture(opaqueDL++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
            // B6000000 00020000
            gSPClearGeometryMode(translucentDL++, G_LIGHTING);
            spF88 = (D_803F2CA2 << 3) + (D_803F2CA4 << 5);
            // temp_a0_2->unk0 = (Gfx *)0x0400207F;
            // temp_a0_2->unk4 = (s32) ((s32) ((temp_a2 * 0x10) + &D_8022D350) & 0x1FFFFFFF);
            gSPVertex(
                translucentDL++,
                K0_TO_PHYS(&D_8022D350[spF88]),
                8,
                0);
            // BE000000 0000000E
            gSPCullDisplayList(translucentDL++, 0, 7);
            // BA001701 00000000
            gDPPipelineMode(translucentDL++, G_PM_NPRIMITIVE);
            // BB002801 80008000
            gSPTexture(translucentDL++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
            // F2000000 0007C07C
            gDPSetTileSize(translucentDL++, G_TX_RENDERTILE, 0, 0, 124, 124);
            // B9000002 00000000
            gDPSetAlphaCompare(translucentDL++, G_AC_NONE);
            // F2000000 0007C07C
            gDPSetTileSize(translucentDL++, G_TX_RENDERTILE, 0, 0, 124, 124);
            // F2000000 0103C03C
            gDPSetTileSize(translucentDL++, 1, 0, 0, 60, 60);
            // F2000000 0201C01C
            gDPSetTileSize(translucentDL++, 2, 0, 0, 28, 28);
            // F2000000 0507C07C
            gDPSetTileSize(translucentDL++, 5, 0, 0, 124, 124);
            // F2000000 0607C07C
            gDPSetTileSize(translucentDL++, 6, 0, 0, 124, 124);
            // F5101000 00014050
            gDPSetTile(translucentDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
            // F5100900 01010441
            gDPSetTile(translucentDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
            // F5100540 0200C832
            gDPSetTile(translucentDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
            // E7000000 00000000
            gDPPipeSync(opaqueDL++);
            // B9000002 00000000
            gDPSetAlphaCompare(opaqueDL++, G_AC_NONE);
            // B900031D (D_803C0644 | D_803C064C)
            gDPSetRenderMode(opaqueDL++, gRenderMode1, gRenderMode2);
            // FC26A004 1FFC93FC
            gDPSetCombineMode(opaqueDL++, G_CC_TRILERP, G_CC_MODULATEI2);
            // BA001402 00100000
            gDPSetCycleType(opaqueDL++, G_CYC_2CYCLE);
            // BA001001 00010000
            gDPSetTextureLOD(opaqueDL++, G_TL_LOD);
            // FA00808000000000
            gDPSetPrimColor(opaqueDL++, 128, 128, 0x00, 0x00, 0x00, 0x00);
            // 0007C07C F2000000
            gDPSetTileSize(opaqueDL++, G_TX_RENDERTILE, 0, 0, 124, 124);
            // 0103C03C F2000000
            gDPSetTileSize(opaqueDL++, 1, 0, 0, 60, 60);
            // 0201C01C F2000000
            gDPSetTileSize(opaqueDL++, 2, 0, 0, 28, 28);
            // 0300C00C F2000000
            gDPSetTileSize(opaqueDL++, 3, 0, 0, 12, 12);
            // F2000000 04004004
            gDPSetTileSize(opaqueDL++, 4, 0, 0, 4, 4);
            // F2000000 05000000
            gDPSetTileSize(opaqueDL++, 5, 0, 0, 0, 0);
            // F5101000 00014050
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
            // F5100900 01010441
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
            // F5100540 0200C832
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
            // F5100350 03008C23
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
            // F5100354 04005014
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
            // F5100356 05001405
            gDPSetTile(opaqueDL++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 0, 5, G_TX_NOMIRROR | G_TX_WRAP, 0, 5);

            D_803F2C92 = 0;
            D_803F2C94 = 0;
            D_803F2C99 = 0;
            D_803F2C9A = 0;
            D_803F2C9B = 0;

            gDPPipeSync(opaqueDL++);

            spFC2 = D_803F2CA2 << 0xA;
            spFC0 = D_803F2CA4 << 0xA;

            do {
                vtxFlags = D_803F2C80[spFC6].header.flags; // flags
                texIdx = D_803F2C80[spFC6].header.unk2;
                temp_t5_2 = D_803F2C80[spFC6].header.unk3;

                if (vtxFlags & 1) {
                    vtxCount = 3; // triangle
                } else {
                    vtxCount = 4; // quad
                }

                if ((vtxFlags & VTX_TRANSLUCENT) ||
                    (vtxFlags & 0x10) ||
                    (vtxFlags & 0x200) ||
                    (vtxFlags & 0x8000)) {

                    // TRANSLUCENT

                    gWorldCellTranslucentEnabled[D_803F2CA2][D_803F2CA4] = 1; // enabled
                    for (i = 0; i < vtxCount; i++) {
                        D_803F2C9C = (D_803F2C80[spFC6].unk4[i].unk7 << 6) + spFC2 + 0x100;   // unkB
                        D_803F2C9E = (D_803F2C80[spFC6].unk4[i].unkA << 6) + spFC0 + 0x200;   // unkE
                        D_803F2CA0 = (D_803F2C80[spFC6].unk4[i].unk8 << 3);                   // unkC
                        spF64[i] = D_803F2C9C >> 6;
                        spF60[i] = D_803F2C9E >> 6;
                        spF58[i] = totalTransVtxs;

                        if ((vtxFlags & VTX_RENDER_MODE_DECAL) != 0) {
                            // erh? dev typo?
                            D_803F2CA0 = D_803F2CA0;
                        }
                        tc0 = D_803F2C80[spFC6].unk4[i].tc0 << 6; // unk4
                        tc1 = D_803F2C80[spFC6].unk4[i].tc1 << 6; // unk6

                        if (D_803F2C80[spFC6].unk4[i].alpha > 250) { // unkF
                            D_803F2C80[spFC6].unk4[i].alpha = 0xFF; // unkF
                        }

                        // maybe?
                        temp_t2 = D_803F2C80[spFC6].unk4[i].red;
                        temp_t3 = D_803F2C80[spFC6].unk4[i].green;
                        temp_t4 = D_803F2C80[spFC6].unk4[i].blue;

                        if (texIdx >= 32) {
                            alpha = 0;
                        } else {
                            alpha = D_803F2C80[spFC6].unk4[i].alpha; // unkF
                        }

                        gTranslucentVtxPool[totalTransVtxs].v.ob[0] = D_803F2C9C;
                        gTranslucentVtxPool[totalTransVtxs].v.ob[1] = D_803F2C9E;
                        gTranslucentVtxPool[totalTransVtxs].v.ob[2] = D_803F2CA0;

                        gTranslucentVtxPool[totalTransVtxs].v.cn[0] = temp_t2; // unk8
                        gTranslucentVtxPool[totalTransVtxs].v.cn[1] = temp_t3; // unk9
                        gTranslucentVtxPool[totalTransVtxs].v.cn[2] = temp_t4; // unkA
                        gTranslucentVtxPool[totalTransVtxs].v.cn[3] = alpha;

                        gTranslucentVtxPool[totalTransVtxs].v.tc[0] = tc0;
                        gTranslucentVtxPool[totalTransVtxs].v.tc[1] = tc1;

                        if (transMinX >= D_803F2C9C) {
                            transMinX = D_803F2C9C;
                        }
                        if (transMinZ >= D_803F2CA0) {
                            transMinZ = D_803F2CA0;
                        }
                        if (transMinY >= D_803F2C9E) {
                            transMinY = D_803F2C9E;
                        }
                        if (D_803F2C9C >= transMaxX) {
                            transMaxX = D_803F2C9C;
                        }
                        if (D_803F2CA0 >= transMaxZ) {
                            transMaxZ = D_803F2CA0;
                        }
                        if (D_803F2C9E >= transMaxY) {
                            transMaxY = D_803F2C9E;
                        }
                        totalTransVtxs++;
                    }

                    if ((temp_t5_2 >= 32) && (temp_t5_2 < 48)) {
                        if (vtxCount == 4) {
                            spF72 = MAX(MAX(MAX(spF64[0], spF64[1]), spF64[2]), spF64[3]);
                            spF70 = MAX(MAX(MAX(spF60[0], spF60[1]), spF60[2]), spF60[3]);
                            spF6E = MIN(MIN(MIN(spF64[0], spF64[1]), spF64[2]), spF64[3]);
                            spF6C = MIN(MIN(MIN(spF60[0], spF60[1]), spF60[2]), spF60[3]);
                        }
                        for (i = 0; i < vtxCount; i++) {
                            D_803E4930[D_803E4AC8 + i] = (spF72 + spF6E) >> 1;
                            D_803E4998[D_803E4AC8 + i] = (spF70 + spF6C) >> 1;
                            D_803E4A00[D_803E4AC8 + i] = spF58[i];
                        }
                        D_803E4AC8 += vtxCount;
                    }

                    translucentVtxs[numTransVtxs].idx = spFC6;
                    if (vtxFlags & 1) {
                        numTransVtxsBatch += 3;
                    } else {
                        numTransVtxsBatch += 4;
                    }

                    numTransVtxs++; // num translucent vtxs
                    spFC6++; // total vtxs?

                    // if we have 8 vtxs emit batch
                    if (numTransVtxs >= 8) {
                        batchIdx = transVtxBatchIdx;
                        transVtxBatchIdx = totalTransVtxs;
                        func_803458B8_756F68(&translucentDL, &gTranslucentVtxPool[batchIdx], numTransVtxsBatch);
                        func_80346BB4_758264(&translucentDL, translucentVtxs, 8);
                        numTransVtxsBatch = 0;
                        numTransVtxs = 0;
                    }
                } else {
                    // OPAQUE

                    sp40 = opaqueVtxsIdx - numOpaqueVtxsBatch; // calculate remaining?
                    // sp48 = vtxFlags & 0x4000;
                    for (i = 0; i < vtxCount; i++) {
                        D_803F2C9C = (D_803F2C80[spFC6].unk4[i].unk7 << 6) + spFC2 + 0x100;    // unkB
                        D_803F2C9E = (D_803F2C80[spFC6].unk4[i].unkA << 6) + spFC0 + 0x200;    // unkE

                        foundVtxIdx = NOT_FOUND;

                        D_803F2CA0 = D_803F2C80[spFC6].unk4[i].unk8 * 8;   // unkC
                        if (vtxFlags & VTX_RENDER_MODE_DECAL) {
                            D_803F2CA0 = D_803F2CA0;
                        }

                        temp_t2 = sp147 = D_803F2C80[spFC6].unk4[i].red;    // unk8
                        temp_t3 = sp146 = D_803F2C80[spFC6].unk4[i].green;  // unk9
                        temp_t4 = sp145 = D_803F2C80[spFC6].unk4[i].blue;   // unkA

                        tc0 = D_803F2C80[spFC6].unk4[i].tc0 << 6; // unk4
                        tc1 = D_803F2C80[spFC6].unk4[i].tc1 << 6; // unk6

                        for (j = numOpaqueVtxsBatch; j < opaqueVtxsIdx; ) {
                            flags = 0;
                            if (D_803F2D50.unk5C[D_803F2CA2][D_803F2CA4] == 0) {
                                // lighting
                                if ((D_803F2C9C == gOpaqueVtxPool[j].v.ob[0]) &&
                                    (D_803F2C9E == gOpaqueVtxPool[j].v.ob[1]) &&
                                    (D_803F2CA0 == gOpaqueVtxPool[j].v.ob[2]) &&
                                    (foundVtxIdx == NOT_FOUND)) {
                                    if ((tc0 != gOpaqueVtxPool[j].v.tc[0]) ||
                                        (tc1 != gOpaqueVtxPool[j].v.tc[1])) {
                                        flags = 1;
                                    }
                                    if (gOpaqueVtxPool[j].v.flag != 0) {
                                        flags |= 1;
                                    }
                                    gOpaqueVtxPool[j].v.flag = 1;
                                    if (flags == 0) {
                                        flags = 4;
                                    }
                                }
                            } else {
                                if ((D_803F2C9C == gOpaqueVtxPool[j].v.ob[0]) &&
                                    (D_803F2C9E == gOpaqueVtxPool[j].v.ob[1]) &&
                                    (D_803F2CA0 == gOpaqueVtxPool[j].v.ob[2]) &&
                                    ((temp_t2 & 0xF0) == (gOpaqueVtxPool[j].v.cn[0] & 0xF0)) &&
                                    ((temp_t3 & 0xF0) == (gOpaqueVtxPool[j].v.cn[1] & 0xF0)) &&
                                    ((temp_t4 & 0xF0) == (gOpaqueVtxPool[j].v.cn[2] & 0xF0)) &&
                                    (foundVtxIdx == NOT_FOUND)) {

                                    if (((tc0 & 0xFFFF00) != (gOpaqueVtxPool[j].v.tc[0] & 0xFFFF00)) ||
                                        ((tc1 & 0xFFFF00) != (gOpaqueVtxPool[j].v.tc[1] & 0xFFFF00))) {
                                        flags = 1;
                                    }
                                    if (gOpaqueVtxPool[j].v.flag != 0) {
                                        flags |= 1;
                                    }
                                    gOpaqueVtxPool[j].v.flag = 1;
                                    if (flags == 0) {
                                        flags = 4;
                                    }
                                }
                            }
                            if (flags != 0) {
                                foundVtxIdx = j;
                                j = opaqueVtxsIdx; // break?
                            } else {
                                j += 1;
                            }
                        }

                        if (foundVtxIdx != NOT_FOUND) {
                            // reuse existing
                            opaqueVtxs[numOpaqueVtxs].v[i] = (foundVtxIdx - numOpaqueVtxsBatch);
                            opaqueVtxs[numOpaqueVtxs].flags[i] = flags;
                        } else {
                            // add new vertex
                            gOpaqueVtxPool[opaqueVtxsIdx].v.flag = 0;
                            gOpaqueVtxPool[opaqueVtxsIdx].v.ob[0] = D_803F2C9C;
                            gOpaqueVtxPool[opaqueVtxsIdx].v.ob[1] = D_803F2C9E;
                            gOpaqueVtxPool[opaqueVtxsIdx].v.ob[2] = D_803F2CA0;

                            // something like this?
                            if (D_803F2D50.unk5C[D_803F2CA2][D_803F2CA4] == 0) {
                                // lighting
                                gOpaqueVtxPool[opaqueVtxsIdx].n.n[0] = sp147;
                                gOpaqueVtxPool[opaqueVtxsIdx].n.n[1] = sp146;
                                gOpaqueVtxPool[opaqueVtxsIdx].n.n[2] = sp145;

                            } else {
                                gOpaqueVtxPool[opaqueVtxsIdx].v.cn[0] = temp_t2;
                                gOpaqueVtxPool[opaqueVtxsIdx].v.cn[1] = temp_t3;
                                gOpaqueVtxPool[opaqueVtxsIdx].v.cn[2] = temp_t4;
                            }

                            opaqueVtxs[numOpaqueVtxs].flags[i] = 0;
                            opaqueVtxs[numOpaqueVtxs].unk1C[i] = opaqueVtxsIdx;
                            opaqueVtxs[numOpaqueVtxs].v[i] = sp40;

                            gOpaqueVtxPool[opaqueVtxsIdx].v.cn[3] = 0xFF;

                            gOpaqueVtxPool[opaqueVtxsIdx].v.tc[0] = tc0;
                            gOpaqueVtxPool[opaqueVtxsIdx].v.tc[1] = tc1;
                            opaqueVtxsIdx += 1;
                            sp40 = opaqueVtxsIdx - numOpaqueVtxsBatch;
                        }

                        if (opaqueMinX >= D_803F2C9C) {
                            opaqueMinX = D_803F2C9C;
                        }
                        if (opaqueMinZ >= D_803F2CA0) {
                            opaqueMinZ = D_803F2CA0;
                        }
                        if (opaqueMinY >= D_803F2C9E) {
                            opaqueMinY = D_803F2C9E;
                        }
                        if (D_803F2C9C >= opaqueMaxX) {
                            opaqueMaxX = D_803F2C9C;
                        }
                        if (D_803F2CA0 >= opaqueMaxZ) {
                            opaqueMaxZ = D_803F2CA0;
                        }
                        if (D_803F2C9E >= opaqueMaxY) {
                            opaqueMaxY = D_803F2C9E;
                        }
                    }

                    opaqueVtxs[numOpaqueVtxs++].idx = spFC6++;

                    if (sp40 > 28) {
                        batchIdx = numOpaqueVtxsBatch;
                        numOpaqueVtxsBatch = opaqueVtxsIdx;
                        func_803458B8_756F68(&opaqueDL, &gOpaqueVtxPool[batchIdx], sp40);
                        func_803458FC_756FAC(&opaqueDL, opaqueVtxs, numOpaqueVtxs);
                        numOpaqueVtxs = 0;
                    }
                }
            } while (vtxFlags & VTX_HAS_NEXT);

            // temp_v0_10 = (spF88 * 0x10) + &D_80224870;

            // D_80224870 is 5000 Vtx higher than gOpaqueVtxPool
            D_80224870[spF88 + 0].v.ob[0] = opaqueMinX; /* 0x00 */
            D_80224870[spF88 + 0].v.ob[1] = opaqueMinY; /* 0x02 */
            D_80224870[spF88 + 0].v.ob[2] = opaqueMinZ; /* 0x04 */

            D_80224870[spF88 + 1].v.ob[0] = opaqueMaxX; /* 0x10 */
            D_80224870[spF88 + 1].v.ob[1] = opaqueMinY; /* 0x12 */
            D_80224870[spF88 + 1].v.ob[2] = opaqueMinZ; /* 0x14 */

            D_80224870[spF88 + 2].v.ob[0] = opaqueMinX; /* 0x20 */
            D_80224870[spF88 + 2].v.ob[1] = opaqueMaxY; /* 0x22 */
            D_80224870[spF88 + 2].v.ob[2] = opaqueMinZ; /* 0x24 */

            D_80224870[spF88 + 3].v.ob[0] = opaqueMaxX;
            D_80224870[spF88 + 3].v.ob[1] = opaqueMaxY;
            D_80224870[spF88 + 3].v.ob[2] = opaqueMinZ;

            D_80224870[spF88 + 4].v.ob[0] = opaqueMinX;
            D_80224870[spF88 + 4].v.ob[1] = opaqueMinY;
            D_80224870[spF88 + 4].v.ob[2] = opaqueMaxZ;

            D_80224870[spF88 + 5].v.ob[0] = opaqueMaxX;
            D_80224870[spF88 + 5].v.ob[1] = opaqueMinY;
            D_80224870[spF88 + 5].v.ob[2] = opaqueMaxZ;

            D_80224870[spF88 + 6].v.ob[0] = opaqueMinX;
            D_80224870[spF88 + 6].v.ob[1] = opaqueMaxY;
            D_80224870[spF88 + 6].v.ob[2] = opaqueMaxZ;

            D_80224870[spF88 + 7].v.ob[0] = opaqueMaxX;
            D_80224870[spF88 + 7].v.ob[1] = opaqueMaxY;
            D_80224870[spF88 + 7].v.ob[2] = opaqueMaxZ;

            // D_8022D350 is 2222 Vtx higher than D_80224870
            // temp_v1_5 = (spF88 * 0x10) + &D_8022D350;
            D_8022D350[spF88 + 0].v.ob[0] = transMinX;
            D_8022D350[spF88 + 0].v.ob[1] = transMinY;
            D_8022D350[spF88 + 0].v.ob[2] = transMinZ;
            D_8022D350[spF88 + 1].v.ob[0] = transMaxX;
            D_8022D350[spF88 + 1].v.ob[1] = transMinY;
            D_8022D350[spF88 + 1].v.ob[2] = transMinZ;

            D_8022D350[spF88 + 2].v.ob[0] = transMinX;
            D_8022D350[spF88 + 2].v.ob[1] = transMaxY;
            D_8022D350[spF88 + 2].v.ob[2] = transMinZ;
            D_8022D350[spF88 + 3].v.ob[0] = transMaxX;
            D_8022D350[spF88 + 3].v.ob[1] = transMaxY;
            D_8022D350[spF88 + 3].v.ob[2] = transMinZ;

            D_8022D350[spF88 + 4].v.ob[1] = transMinY;
            D_8022D350[spF88 + 4].v.ob[0] = transMinX;
            D_8022D350[spF88 + 4].v.ob[2] = transMaxZ;
            D_8022D350[spF88 + 5].v.ob[0] = transMaxX;
            D_8022D350[spF88 + 5].v.ob[1] = transMinY;
            D_8022D350[spF88 + 5].v.ob[2] = transMaxZ;

            D_8022D350[spF88 + 6].v.ob[0] = transMinX;
            D_8022D350[spF88 + 6].v.ob[1] = transMaxY;
            D_8022D350[spF88 + 6].v.ob[2] = transMaxZ;
            D_8022D350[spF88 + 7].v.ob[0] = transMaxX;
            D_8022D350[spF88 + 7].v.ob[1] = transMaxY;
            D_8022D350[spF88 + 7].v.ob[2] = transMaxZ;

            if (numOpaqueVtxs != 0) {
                batchIdx = numOpaqueVtxsBatch;
                numOpaqueVtxsBatch = opaqueVtxsIdx;
                func_803458B8_756F68(&opaqueDL, &gOpaqueVtxPool[batchIdx], numOpaqueVtxsBatch - batchIdx);
                batch = numOpaqueVtxs;
                numOpaqueVtxs = 0;
                func_803458FC_756FAC(&opaqueDL, opaqueVtxs, batch);
            }
            if (numTransVtxs != 0) {
                batch = numTransVtxsBatch;
                numTransVtxsBatch = 0;
                batchIdx = transVtxBatchIdx;
                transVtxBatchIdx = totalTransVtxs; // total?
                func_803458B8_756F68(&translucentDL, &gTranslucentVtxPool[batchIdx], batch);
                batch = numTransVtxs;
                numTransVtxs = 0;
                func_80346BB4_758264(&translucentDL, translucentVtxs, batch);
            }
            gSPEndDisplayList(opaqueDL++);
            gSPEndDisplayList(translucentDL++);
        }
    }
    gSPEndDisplayList(opaqueDL++);
    gSPEndDisplayList(translucentDL++);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_80344240_7558F0.s")
#endif

void func_803458B8_756F68(Gfx **dl, Vtx *vtx, s16 num) {
    gSPVertex((*dl)++, K0_TO_PHYS(vtx), num, 0);
}

#if 0
// CURRENT (7467)
extern int COMBINED;
extern int SHADE_ALPHA;
extern int TEXEL0;
extern int TEXEL1;
extern int SHADE;
extern int LOD_FRACTION;
extern int PRIMITIVE;
extern int PRIM_LOD_FRAC;
void func_803458FC_756FAC(Gfx **dl, struct115 *arg1, s16 numVtxs) {
    s16 i;          // sp17A
    s16 vtxsUsed;   // sp178
    s16 j;

    u8  sp175;   //
    u8  index;   // texture index?
    u16 vtxFlags;
    s16 pad;

    s32 s;
    s32 t;

    s32 pad2;

    vtxsUsed = 0;

    for (i = 0; i < numVtxs; i++) {
        vtxFlags = D_803F2C80[arg1[i].idx].header.flags;
        index = D_803F2C80[arg1[i].idx].header.unk2;
        sp175 = D_803F2C80[arg1[i].idx].header.unk3;

        if ((vtxFlags & 8) ||
            (vtxFlags & 0x40) ||
            (vtxFlags & 0x2000) ||
            (vtxFlags & 0x100)) {

            if (vtxFlags & 8) {
                if (D_803F2C86 != 4) {
                    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0180, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                    gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
                    gDPTileSync((*dl)++);

                    D_803F2C86 = 4;
                }
            }

            if (vtxFlags & 0x100) {
                if (D_803F2C86 != 12) {
                    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01C0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);

                    D_803F2C86 = 12;
                }
                D_803E3130[D_803F2CA6].unk0 |= 1;
                D_803E3130[D_803F2CA6].unk2 = sp175;
                D_803E3130[D_803F2CA6].type = 6;
                D_803E3130[D_803F2CA6].displayList = *dl;
                gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);

                D_803F2CA6++;
                D_803F2C92 = 1;
            }
        } else {
            if (index > 40) {
                if (D_803F2C86 != 14) {
                    D_803F2C8E = 0;
                    gDPPipeSync((*dl)++);
                    gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                    gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                    gDPSetCombineMode((*dl)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                    gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_TEX_EDGE2);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 32768, 32768, 0, 6, G_ON);

                    if (index != D_803F2C96) {
                        D_803E3130[D_803F2CA6].unk0 |= 1;
                        D_803E3130[D_803F2CA6].unk2 = sp175;
                        D_803E3130[D_803F2CA6].type = index - 33;
                        D_803E3130[D_803F2CA6].displayList = *dl;
                        D_803F2CA6++;

                        // OS_PHYSICAL_TO_K0(D_0102C810_660E0_bin) ???
                        gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (D_0102C810_660E0_bin + 0x8000000));
                        gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPLoadSync((*dl)++);
                        gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 512);
                        gDPPipeSync((*dl)++);
                        gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);

                        D_803F2C96 = index;
                        D_803F2C97 = 0xFF;
                    }
                    D_803F2C86 = 14;
                }
            } else if (!(vtxFlags & 8)) {
                if (D_803F2C86 != 1) {
                    gDPPipeSync((*dl)++);
                    gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                    gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
                    gDPSetTextureLOD((*dl)++, G_TL_LOD);
                    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                    gSPTexture((*dl)++, 32768, 32768, 5, G_TX_RENDERTILE, G_ON);
                    gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);

                    D_803F2C86 = 1;
                }
            }

            if (sp175) {
                // force load of 1:
                u32 one = 1U;
                // was this a typo by original devs?
                if (D_803F2C86 = 1) {
                    D_803E3130[D_803F2CA6].unk0 |= 1;
                    D_803E3130[D_803F2CA6].unk2 = sp175;
                    D_803E3130[D_803F2CA6].type = one;

                    D_803E3130[D_803F2CA6].displayList = *dl;

                    gDPSetTileSize((*dl)++, 0, 0, 0, (32-1)*4, (32-1)*4);
                    gDPSetTileSize((*dl)++, 1, 0, 0, (16-1)*4, (16-1)*4);
                    gDPSetTileSize((*dl)++, 2, 0, 0,  (8-1)*4,  (8-1)*4);
                    gDPTileSync((*dl)++);
                    gDPPipeSync((*dl)++);

                    D_803F2CA6++;
                    D_803F2C92 = 1;
                }
            }
        }

        if (vtxFlags & 0x40) {
            if (D_803F2C99 == 0) {
                gDPPipeSync((*dl)++);
                gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEIDECALA);
                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_TEX_EDGE2);
                D_803F2C99 = 1;
            }
        } else {
            if (D_803F2C99 == 1) {
                gDPPipeSync((*dl)++);
                gSPTexture((*dl)++, 32768, 32768, 5, G_TX_RENDERTILE, G_ON);
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
                if (index > 40) {
                    gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_TEX_EDGE2);
                } else {
                    gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);
                }
            }
        }

        if (vtxFlags & 0x800) {
            if (D_803F2C88 != 2) {
                D_803F2C88 = 2;
                gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_OPA_INTER2);
            }
        } else if (D_803F2C88 != 1) {
            // NOTE: D_803F2C88 is not set to 1
            gDPSetRenderMode((*dl)++, gRenderMode1, gRenderMode2);
        }

        if (D_803F2C96 != index) {
            if (index < 32) {
                func_80346878_757F28(dl, index);
            }
            D_803F2C96 = index;
            D_803F2C97 = 0xFF;
        }

        if (vtxFlags & 4) {
            if (D_803F2C9A == 0) {
                gSPClearGeometryMode((*dl)++, G_CULL_BACK);
                D_803F2C9A = 1;
            }
        }
        if ((vtxFlags & 4) == 0) {
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
                gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, PRIMITIVE, SHADE, 0, 0, 0, 0, SHADE);
                gDPSetPrimColor((*dl)++, 128, 128, 45, 45, 45, 0x00);
                D_803F2C8C = 1;
            }
        } else if (D_803F2C8C == 1) {
            gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
            D_803F2C8C = 0;
        }

        if (!sp175) {
            if (D_803F2C92 != 0) {
                if ((vtxFlags & 0x40) == 0) {
                    gDPSetTileSize((*dl)++, 0, 0, 0, (32-1)*4, (32-1)*4);
                }
                gDPSetTileSize((*dl)++, 1, 0, 0, (16-1)*4, (16-1)*4);
                gDPSetTileSize((*dl)++, 2, 0, 0,  (8-1)*4,  (8-1)*4);
                gDPSetTileSize((*dl)++, 3, 0, 0,  (4-1)*4,  (4-1)*4);
                gDPSetTileSize((*dl)++, 4, 0, 0,  (2-1)*4,  (2-1)*4);
                gDPSetTileSize((*dl)++, 5, 0, 0,  (1-1)*4,  (1-1)*4);

                D_803F2C92 = 0;
            }
        }

        if ((vtxFlags & 1) == 0) {
            for (j = 0; j < 4; j++) {
                if ((arg1[i].flags[j] != 0) && (arg1[i].flags[j] & 1)) {
                    t = (D_803F2C80[arg1[i].idx].unk4[j].tc1 << 5);
                    s = (D_803F2C80[arg1[i].idx].unk4[j].tc0 << 5);

                    gSPModifyVertex(
                        (*dl)++,
                        arg1[i].v[j],
                        20,
                        ((s << 0x10) & 0xFFFF0000) | (t & 0xFFFF)
                    );
                }
            }

            gSP2Triangles(
            /* gdl   */ (*dl)++,
            /* v00   */ arg1[i].v[2],
            /* v01   */ arg1[i].v[1],
            /* v02   */ arg1[i].v[0],
            /* flag0 */ 0,
            /* v10   */ arg1[i].v[2],
            /* v11   */ arg1[i].v[3],
            /* v12   */ arg1[i].v[1],
            /* flag1 */ 0);

            vtxsUsed++;
        } else {
            for (j = 0; j < 3; j++) {
                if ((arg1[i].flags[j] != 0) && (arg1[i].flags[j] & 1)) {
                    t = (D_803F2C80[arg1[i].idx].unk4[j].tc1 << 5);
                    s = (D_803F2C80[arg1[i].idx].unk4[j].tc0 << 5);

                    gSPModifyVertex(
                        (*dl)++,
                        arg1[i].v[j],
                        20,
                        ((s << 0x10) & 0xFFFF0000) | (t & 0xFFFF)
                    );
                }
            }

            gSP1Triangle(
            /* gdl  */ (*dl)++,
            /* v0   */ arg1[i].v[2],
            /* v1   */ arg1[i].v[1],
            /* v2   */ arg1[i].v[0],
            /* flag */ 0);
        }
        vtxsUsed += 3;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_803458FC_756FAC.s")
#endif

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

#ifdef NON_MATCHING

extern int COMBINED;
extern int SHADE_ALPHA;
extern int TEXEL0;
extern int TEXEL1;
extern int SHADE;
extern int LOD_FRACTION;
extern int PRIMITIVE;

//CURRENT (2158)
void func_80346BB4_758264(Gfx **dl, struct115* arg1, s16 numVtxs) {
    s32 pad[0x1];
    s16 i;         // sp29A
    s16 vtxsUsed;  // sp298

    u16 vtxFlags;
    u8  textureIndex; // not tris
    u8  sp294; // image index?
    s32 sp290; // padding
    s16 sp28E; // needs image loading?

    s16 a1;
    s16 pad2[13];

    s16 var_v0;

    vtxsUsed = 0;

    for (i = 0; i < numVtxs; i++) {
        sp28E = 1;

        vtxFlags = D_803F2C80[arg1[i].idx].header.flags;
        textureIndex = D_803F2C80[arg1[i].idx].header.unk3;
        sp294  = D_803F2C80[arg1[i].idx].header.unk2;

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
                sp28E = 0;
                if (D_803F2C84 != 3) {
                    gDPPipeSync((*dl)++);
                    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, PRIMITIVE);
                    if (1) { } if (1) { } if (1) { } if (1) { }
                    gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 5, G_ON);

                    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, D_0102B610_64EE0_bin);

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

                D_803E3130[D_803F2CA6].unk2 = textureIndex;
                D_803E3130[D_803F2CA6].unk0 |= 1;

                if (textureIndex) {
                    D_803E3130[D_803F2CA6].type = 0;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*dl)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // 0x100*

                } else {
                    D_803E3130[D_803F2CA6].type = 7;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0xDC);

                }
                D_803F2CA6++;
                D_803F2C94 = 1;
            }
            if (vtxFlags & 0x200) {
                sp28E = 0;
                if (D_803F2C84 != 6) {
                    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0, TEXEL1, PRIMITIVE, SHADE, PRIMITIVE, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, COMBINED);
                    gDPSetRenderMode((*dl)++, G_RM_PASS, D_803F2CC0);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 0x8000, 0x8000, 0, 5, G_ON);
                    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, D_0102B810_650E0_bin);
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
                D_803E3130[D_803F2CA6].unk2 = textureIndex;
                D_803E3130[D_803F2CA6].unk0 |= 1;

                if (textureIndex) {
                    D_803E3130[D_803F2CA6].type = 3;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*dl)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC);
                } else {
                    D_803E3130[D_803F2CA6].type = 7;
                    D_803E3130[D_803F2CA6].displayList = *dl;
                    gDPSetPrimColor((*dl)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC);
                    gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
                }
                D_803F2CA6++;
                D_803F2C94 = 1;
            }
            if (vtxFlags & 0x100) {
                sp28E = 0;
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
                D_803E3130[D_803F2CA6].unk2 = textureIndex;
                D_803E3130[D_803F2CA6].unk0 |= 1;
                D_803E3130[D_803F2CA6].type = 5;
                D_803E3130[D_803F2CA6].displayList = *dl;
                gDPSetTileSize((*dl)++, 6, 0, 0, 60, 60);

                D_803F2CA6++;
                D_803F2C94 = 1;
            }
            if (vtxFlags & 0x1000) {
                sp28E = 0;
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
                D_803E3130[D_803F2CA6].unk2 = textureIndex;
                D_803E3130[D_803F2CA6].unk0 |= 1;
                D_803E3130[D_803F2CA6].type = 5;
                D_803E3130[D_803F2CA6].displayList = *dl;
                gDPSetTileSize((*dl)++, 5, 0, 0, 60, 60);

                D_803F2CA6++;
                D_803F2C94 = 1;
            }

            // continue here instead?
            if ((vtxFlags & VTX_TRANSLUCENT) &&
                (!(vtxFlags & 0x10)) &&
                (!(vtxFlags & 0x200)) &&
                (!(vtxFlags & 0x100))) {

                vtxFlags = D_803F2C80[arg1[i].idx].header.flags;
                if (sp294 >= 32) {
                    if (D_803F2C84 != 0xE) {
                        gDPPipeSync((*dl)++);
                        if (sp294 > 40) {
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

                            D_803E3130[D_803F2CA6].unk2 = textureIndex;
                            D_803E3130[D_803F2CA6].unk0 |= 1;
                            D_803E3130[D_803F2CA6].displayList = *dl;
                            // type = sp294 - 33;
                            D_803E3130[D_803F2CA6].type = sp294 - 33;
                            D_803F2CA6++;

                            if ((sp294 - 33) == 9) {
                                if (0) {};
                                // why cant we use OS_PHYSICAL_TO_K0 here?
                                gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (D_0102C810_660E0_bin + 0x8000000 + 0x1000));
                                gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync((*dl)++);
                                gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 512);
                                gDPPipeSync((*dl)++);
                                gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                            } else {

                                gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (D_0102C810_660E0_bin + 0x8000000));
                                gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync((*dl)++);
                                gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 512);
                                gDPPipeSync((*dl)++);
                                gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                            }
                            gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        } else {
                            gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, SHADE, 0, COMBINED);

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
                        if (textureIndex) {
                            D_803E3130[D_803F2CA6].unk0 |= 1;
                            D_803E3130[D_803F2CA6].unk2 = textureIndex;
                            D_803E3130[D_803F2CA6].type = 0xB;
                            D_803E3130[D_803F2CA6].displayList = *dl;
                            D_803F2CA6++;

                            D_803F2C94 = 1;

                            gDPSetTileSize((*dl)++, 0, 0, 0, 124, 124);
                            gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
                            gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
                        }
                    }
                } else {
                    // FAKE  & 0xFFFF
                    // var_v0 = (vtxFlags & VTX_TRIANGLE & 0xFFFF & 0xFFFF) ? 3 : 4;
                    var_v0 = (vtxFlags & VTX_TRIANGLE) ? 3 : 4;

                    // nonsense
                    for (a1 = 0; (a1 < var_v0); var_v0++) {
                        // ...
                    }

                    if ((D_803F2C84 != 9) && (sp294 != 0)) {
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
                                                                      /* line, tmem, tile, palette ... */
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, 0);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 0, 5, G_TX_NOMIRROR | G_TX_WRAP, 0, 5);
                        gDPSetTileSize((*dl)++, 5, 0, 0, 0, 0);

                        D_803F2C84 = 9;
                    }

                    if ((textureIndex) &&
                        !(vtxFlags & 0x100) &&
                        !(vtxFlags & 0x10) &&
                        !(vtxFlags & 0x200)) {
                        D_803E3130[D_803F2CA6].unk2 = textureIndex;
                        D_803E3130[D_803F2CA6].unk0 |= 1;
                        D_803E3130[D_803F2CA6].type = 4;
                        D_803E3130[D_803F2CA6].displayList = *dl;

                        gDPSetTileSize((*dl)++, 0, 0, 0, 124, 124);
                        gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
                        gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
                        gDPTileSync((*dl)++);
                        gDPPipeSync((*dl)++);

                        D_803F2CA6++;
                        D_803F2C94 = 1;
                    }
                    if ((sp294 == 0) && (D_803F2C84 != 10)) {
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
        } else {
            // IDO!?!
        }

        if (sp294 != D_803F2C98)
        {
            if (sp28E == 1) {
                if (sp294 <= 40) {
                    func_80346878_757F28(dl, sp294);
                    D_803F2C98 = sp294;
                } else {
                    D_803F2C98 = 100;
                }
            }
        }
        if (vtxFlags & VTX_CULL_BACK) {
            if (D_803F2C9B == 0) {
                gSPClearGeometryMode((*dl)++, G_CULL_BACK);
                D_803F2C9B = 1;
            }
        } else if (D_803F2C9B == 1) {
            gSPSetGeometryMode((*dl)++, G_CULL_BACK);
            D_803F2C9B = 0;
        }
        if ((!textureIndex) && (D_803F2C94 != 0)) {
            gDPSetTileSize((*dl)++, 0, 0, 0, 124, 124);
            gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
            gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
            gDPSetTileSize((*dl)++, 5, 0, 0, 124, 124);
            gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);
            D_803F2C94 = 0;
        }

        if (!(vtxFlags & VTX_TRIANGLE)) {
            gSP2Triangles(
            /* gdl   */ (*dl)++,
            /* v00   */ vtxsUsed + 2,
            /* v01   */ vtxsUsed + 1,
            /* v02   */ vtxsUsed + 0,
            /* flag0 */ 0,
            /* v10   */ vtxsUsed + 2,
            /* v11   */ vtxsUsed + 3,
            /* v12   */ vtxsUsed + 1,
            /* flag1 */ 0);
            vtxsUsed++; // 4 vtxs
        } else {
            gSP1Triangle((*dl)++,
            /* v2   */ vtxsUsed + 2,
            /* v1   */ vtxsUsed + 1,
            /* v0   */ vtxsUsed + 0,
            /* flag */ 0);
        }
        vtxsUsed += 3;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_80346BB4_758264.s")
#endif
