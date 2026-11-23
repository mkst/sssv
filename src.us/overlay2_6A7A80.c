#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

s32 func_802983D0_6A9A80(void);

// ========================================================
// .bss
// ========================================================

// FIXME: if these are defined in overlay2_6A6500 then it results in codegen changes
s64  gRenderMode1;
s64  gRenderMode2;
s64  gGeometryMode;
u16  gWorldPerspNorm; // matrix normalise

// ========================================================
// .text
// ========================================================

void initialize_water_grid(FrameContext *arg0) {
    static int t5;
    s16 i;
    s16 j;
    s16 k;

    s32 x;
    s32 y;

    s16 width;
    s16 height;

    s16 width2;

    gWaterAnimState.unk20A = 8;

    x = D_803F2D50.waterTileX;
    y = D_803F2D50.waterTileZ;
    width = D_803F2D50.waterTileWidth;
    height = D_803F2D50.waterTileDepth;

    if (width == 0 || height == 0) {
        return;
    }

    width2 = width + 1;

    for (i = 0; i < 2; i++) { // double-buffer

        for (j = 0; j < (width + 1); j++) { // x-direction

            for (k = 0; k < height; k++) { // y-direction
                Vtx *v = &arg0[i].dl.unk286E0[((k * width2) + j)];

                v->v.ob[0] = ((j + x) << 6);
                v->v.ob[1] = ((k + y) << 6);
#ifdef __sgi
                v->v.tc[0] = ((j + (t5 * 0)) << 6) << 3;
#else
                v->v.tc[0] = (j << 6) << 3;
#endif
                v->v.tc[1] = (k << 6) << 3;

                v->v.cn[0] = 0;
                v->v.cn[1] = 0;
                v->v.cn[2] = 0x7F;
                v->v.cn[3] = 0x80;
            }
        }
#ifdef __sgi
        if (width == height) {}
        if (width == height) {}
#endif
    }
}

void initialize_water_wave_tables(void) {
    f64 temp_f20;
    f64 temp_f22;
    f64 temp_f24;

    u8 i;

    gWaterAnimState.textureFrame = 0;
    gWaterAnimState.unk204 = 0;

    if (D_803F2D50.waterWaveMode == 0) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 1;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 3;
        }
    }
    if ((D_803F2D50.waterWaveMode == 1) || (D_803F2D50.waterWaveMode == 2)) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 7;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
    }
}

// X uses the high nibble and Z the low nibble, each with bit 3 as the sign.
#define WATER_FLOW_COMPONENT(magnitudeBits, signBits) \
    (((magnitudeBits) & 7) * (1 - (((signBits) & 8) >> 2)))
#define WATER_FLOW_X(flags) WATER_FLOW_COMPONENT(((flags) & 0xF0) >> 4, (flags) >> 4)
#define WATER_FLOW_Z(flags) WATER_FLOW_COMPONENT((flags) & 0xF, flags)
#define WATER_FLOW_FLAGS_AT(x, z) (D_803C0740[(x) >> 6][(z) >> 6].unk7)

void func_80296C8C_6A833C(struct063 grid[73][129]) {
    s16 x;
    s16 z;
    s16 curWater;
    s16 nextWaterX;
    s16 nextWaterZ;
    s16 particleX;
    s16 delta;
    u16 frame;

    u32 startX;
    u32 startZ;
    u32 endX;
    u32 endZ;

    const u8 *flowFlags;
    s16 particleZ;
    s32 prevFrame;

    startX = D_803F2D50.waterTileX;
    startZ = D_803F2D50.waterTileZ;
    endX = D_803F2D50.waterTileX + D_803F2D50.waterTileWidth;
    endZ = D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth;

    prevFrame = gWaterAnimState.unk20D;
#ifdef __sgi
    // fakematch: empty check, needed to match
    if (gWaterAnimState.unk20D >= 4) {}
#endif
    frame = (prevFrame + 1) & 3;
    gWaterAnimState.unk20D = frame;

#ifdef __sgi
    // fakematch: unused read and empty check, needed to match
    nextWaterX = grid[D_803F2D50.waterTileX][0].unk0;
    if ((nextWaterX == D_803F2D50.waterTileX) || (D_803F2D50.waterTileX != D_803F2D50.cellLightingModes[0][D_803F2D50.waterTileZ])) {}
#endif

    for (x = endX; (u32)x > startX; x--) {
        for (z = endZ; (u32)z > startZ; z--) {
            grid[x][z].unk7 = 0;

            if (grid[x][z].unk6 != 0) {
                curWater = grid[x][z].unk6;
                nextWaterX = grid[x + 1][z].unk6;
                if (SSSV_RAND(128) == 20) {
                    func_802D7AD4_6E9184(
                        SSSV_RAND(64) + (x << 6),
                        SSSV_RAND(64) + (z << 6),
                        D_803C0740[x][z].unk0 << 3,
                        0);
                }
                if (nextWaterX < curWater) {
                    delta = grid[x + 1][z].unk0;
                    if ((delta << 1) < curWater) {
                        if ((nextWaterX == 0) && (gWaterAnimState.unk20F == 0)) {
                            nextWaterX = delta << 1;
                        }
                        if ((delta < (grid[x][z].unk0 - 16)) && (nextWaterX < (grid[x][z].unk0 << 1))) {
                            delta = 0;
                        } else {
                            delta = (curWater - nextWaterX) / 2;
                            if (delta > 1) {
                                delta += SSSV_RAND(2);
                            }
                        }
                        delta = (delta < 0) ? 0 : delta;
                        curWater -= delta;
                        nextWaterX += delta;
                        grid[x][z].unk7 = (grid[x][z].unk7 & 0xF) + ((delta & 7) << 4);

                        curWater = (curWater > (grid[x][z].unk0 << 1)) ? curWater : 0;
                        if ((grid[x + 1][z].unk6 == 0) && (nextWaterX != 0)) {
                            grid[x + 1][z].unk4 |= 2;
                        } else {
                            grid[x + 1][z].unk4 &= ~2;
                        }
                        if ((grid[x][z].unk6 != 0) && (curWater == 0)) {
                            grid[x][z].unk4 |= 4;
                        } else {
                            grid[x][z].unk4 &= ~4;
                        }
                        grid[x][z].unk6 = curWater;
                        grid[x + 1][z].unk6 = nextWaterX;
                    }
                }

                curWater = grid[x][z].unk6;
                nextWaterZ = grid[x][z + 1].unk6;
                if (nextWaterZ < curWater) {
                    if (((grid[x][z + 1].unk0 + 1) << 1) < curWater) {
                        if ((nextWaterZ == 0) && (gWaterAnimState.unk20F == 0)) {
                            nextWaterZ = grid[x][z + 1].unk0 << 1;
                        }
                        if ((grid[x][z + 1].unk0 < grid[x][z].unk0) && (nextWaterZ < (grid[x][z].unk0 << 1))) {
                            delta = curWater - (grid[x][z].unk0 << 1);
                        } else {
                            delta = (curWater - nextWaterZ) / 2;
                            if (delta > 1) {
                                delta += SSSV_RAND(2);
                            }
                        }
                        delta = (delta > 0) ? delta : 0;
                        curWater -= delta;
                        nextWaterZ += delta;
                        grid[x][z].unk7 = ((u8)(grid[x][z].unk7 & 0xF0)) + (delta & 7);
                        if (curWater <= (grid[x][z].unk0 << 1)) {
                            curWater = 0;
                        }
                        grid[x][z + 1].unk6 = nextWaterZ;
                        grid[x][z].unk6 = curWater;
                    }
                }

                if ((guRandom() % 31) == 4) {
                    particleX = (guRandom() % 63) + (x << 6);
                    particleZ = (guRandom() % 63) + (z << 6);

                    if ((WATER_FLOW_X(WATER_FLOW_FLAGS_AT(particleX, particleZ)) != 0) ||
                        (WATER_FLOW_Z(WATER_FLOW_FLAGS_AT(particleX, particleZ)) != 0)) {
                        flowFlags = &WATER_FLOW_FLAGS_AT(particleX, particleZ);

                        create_particle_effect(
                            particleX,
                            particleZ,
                            0,
                            13,
                            WATER_FLOW_X(*flowFlags) << 16,
                            WATER_FLOW_Z(*flowFlags) << 16,
                            0,
                            SSSV_RAND(4) + 4,
                            0,
                            0,
                            0);
                    }
                }
            }
            if ((grid[x][z].unk0 * 2) >= grid[x][z].unk6) {
                grid[x][z].unk6 = 0;
            }
        }
    }
}

// update_water_level
void func_8029726C_6A891C(struct063 grid[73][129]) {
    u16 initialX;
    s16 xPos;
    s16 zPos;

    s16 delta;

    s16 curWater;
    s16 prevWater;

    s32 neighborLevel;
    s16 unusedCount;
    u32 startX;
    u32 startZ;
    u32 endX;
    u32 endZ;

    startX = D_803F2D50.waterTileX;
    endX = D_803F2D50.waterTileX + D_803F2D50.waterTileWidth;
    startZ = D_803F2D50.waterTileZ;
    endZ = D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth;

    // fakematch: without this check, IDO keeps endX in a register for the first loop test
    // and loads the gWaterAnimState address later, so the registers and instruction count differ
#ifdef __sgi
    if (((gWaterAnimState.unk20F & 7) != gWaterAnimState.unk20F) || (D_803F2D50.waterTileX != D_803F2D50.waterTileZ)) {}
#endif

    startX = (s16)(startX & 0xFFFF);
    initialX = startX;
    unusedCount = 0;

    for (xPos = initialX; (u32)xPos < endX; xPos++) {
        for (zPos = startZ; (u32)zPos <= endZ; zPos++) {
            if (!grid[xPos][zPos].unk6) {
                continue;
            }

            curWater = grid[xPos][zPos].unk6;
            prevWater = grid[xPos - 1][zPos].unk6;
            if (prevWater < curWater) {
                neighborLevel = grid[xPos - 1][zPos].unk0 * 2;
                if (neighborLevel < curWater) {
                    if ((prevWater == 0) && (gWaterAnimState.unk20F == 0)) {
                        prevWater = neighborLevel;
                    }

                    if (((grid[xPos][zPos].unk0 - 16) > grid[xPos - 1][zPos].unk0) &&
                        (prevWater < (grid[xPos][zPos].unk0 * 2))) {
                        delta = (curWater - (grid[xPos][zPos].unk0 * 2)) / 2;
                        if (delta < 1) {
                            delta = 0;
                        }
                    } else {
                        delta = ((curWater - prevWater) + (xPos & 1)) / 2;
                        if (delta > 1) {
                            delta += SSSV_RAND(2);
                        }
                    }

                    curWater  -= delta;
                    prevWater += delta;

                    // 1xxx____
                    grid[xPos][zPos].unk7 = ((u8)(grid[xPos][zPos].unk7 & 0xF) + ((delta & 7) << 4)) | 0x80;

                    if (curWater <= (grid[xPos][zPos].unk0 * 2)) {
                        curWater = 0;
                    }
                    grid[xPos][zPos].unk6 = curWater;
                    grid[xPos - 1][zPos].unk6 = prevWater;
                }
            }

            curWater = grid[xPos][zPos].unk6;
            prevWater = grid[xPos][zPos - 1].unk6;
            if (prevWater < curWater) {
                neighborLevel = grid[xPos][zPos - 1].unk0 * 2;
                if (neighborLevel < curWater) {
                    if ((prevWater == 0) && (gWaterAnimState.unk20F == 0)) {
                        prevWater = neighborLevel;
                    }

                    if (((grid[xPos][zPos - 1].unk0 + 4) < grid[xPos][zPos].unk0) &&
                        (prevWater <= (grid[xPos][zPos].unk0 * 2))) {
                        delta = (curWater - (grid[xPos][zPos].unk0 * 2)) / 2;
                        if (delta < 2) {
                            delta = 2;
                        }
                        unusedCount++;

                        curWater -= delta;
                        delta = 0;
                    } else {
                        delta = ((curWater + (zPos & 1)) - prevWater) / 2;
                        if (delta > 1) {
                            delta += SSSV_RAND(2);
                        }
                    }
                    if (delta < 0) {
                        delta = 0;
                    }

                    curWater  -= delta;
                    prevWater += delta;

                    // ____1xxx
                    grid[xPos][zPos].unk7 = ((u8)(grid[xPos][zPos].unk7 & 0xF0) + (delta & 7)) | 8;

                    if (curWater <= (grid[xPos][zPos].unk0 * 2)) {
                        curWater = 0;
                    }

                    grid[xPos][zPos].unk6 = curWater;
                    grid[xPos][zPos - 1].unk6 = prevWater;
                }
            }
        }
    }
}

extern Gfx D_010045A0_3DE70[];

#define WATER_VERTEX_HEIGHT(level) ((u16)((level) * 4))

// WATER_WAVE_ROW does not parenthesise its arguments, so for a neighbour at x + offset it
// expands to originX + x + offset * originZ + z.
#define WATER_WAVE_ROW(originX, x, originZ, z) originX + x * originZ + z
#define WATER_CENTER_PHASE(row, originX, x) (gWaterAnimState.unk204 + ((row) + WATER_WAVE_ROW(originX, x, originX, x)) * 8)
#define WATER_WAVE_SAMPLE(row, phase) (gWaterAnimState.unk0[(row) & 7][(u16)(phase) & 0x3F])
#define WATER_CENTER_WAVE(originX, x, originZ, z) \
    WATER_WAVE_SAMPLE(WATER_WAVE_ROW(originX, x, originZ, z), \
        WATER_CENTER_PHASE(WATER_WAVE_ROW(originX, x, originZ, z), originX, x))

// eastOffset and maxStripWidth are locals rather than literals because IDO's output depends on it.
void func_80297628_6A8CD8(struct063 terrain[73][129] UNUSED, DisplayList *displayList) {
    Vtx *clearVertex;
    s32 columnEnd;
    u16 x;
    s16 lastColumn;
    const s16 eastOffset = 1;
    u16 z;
    struct063 *tile;
    s32 rowBelow;
    u32 winding;
    s32 stripStart;
    s32 firstSlot;
    u16 northwestHeight;
    u16 southwestHeight;
    u16 southeastHeight;
    u16 northeastHeight;
    f32 normalZ;
    s32 row;
    f32 normalX;
    u32 waterOriginX;
    u32 waterOriginZ;
    f32 normalScale;
    f32 normalY;
    s16 stripWidth;
    u32 tileX;
    s32 pad[2] UNUSED;
    s32 northRowStart;
    s16 waterWidth;
    s16 waterDepth;
    s16 firstColumn;
    s16 vertsPerRow;
    s32 rowStart;
    s16 cullVertexIndex;
    s16 minHeight;
    s16 maxHeight;
    const s16 maxStripWidth = 16;
    s16 column;
    s16 rowsEmitted;
    Vtx *firstVertex;
    s16 vtxsEmitted;
    s32 quadCount;

    static s16 D_803A04F0_7B1BA0 = 0;
    // Unreferenced, but part of this file's data.
    static s16 D_803A04F4_7B1BA4 UNUSED = 0;
    static s16 D_803A04F8_7B1BA8 UNUSED = 1;

    if (D_803F2D50.waterTileWidth == 0) {
        return;
    }

    vtxsEmitted = 0;
    minHeight = 10000;
    maxHeight = -10000;

    gSPDisplayList(gLayer1DL++, D_01004270_3DB40);
    gSPDisplayList(gLayer1DL++, D_010045A0_3DE70);

    setup_water_grid_material(&gLayer1DL);

    gSPTexture(gLayer1DL++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gLayer1DL++, G_TL_TILE);
    gDPSetRenderMode(gLayer1DL++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gLayer1DL++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, PRIMITIVE);

    if (D_803F2D50.waterTileWidth != 0) {
        if (D_803F2D50.waterTileDepth != 0) {
            if (gCameraVisibilityMask[0] & 0x20) {
                s32 height;

                D_803A04F0_7B1BA0 += 2;
                if (D_803A04F0_7B1BA0 >= 128) {
                    D_803A04F0_7B1BA0 = 0;
                }

                waterOriginX = D_803F2D50.waterTileX;
                waterOriginZ = D_803F2D50.waterTileZ;
                waterWidth = D_803F2D50.waterTileWidth;
                waterDepth = D_803F2D50.waterTileDepth;
                vertsPerRow = waterWidth + 1;

                // reset water heights
                clearVertex = displayList->unk286E0;
                for (z = 0; z < (31 * 31); z++) {
                    clearVertex->v.ob[2] = 0;
                    clearVertex++;
                }

                gWaterAnimState.unk20E++;

                for (z = 0; z <= waterDepth; z++) {
                    for (x = 0; x <= waterWidth; x++) {

                        tile = &D_803C0740[x + waterOriginX][z + waterOriginZ];
                        northRowStart = (z - 1) * vertsPerRow;
                        height = WATER_VERTEX_HEIGHT(tile->unk6);
                        minHeight = (minHeight >= height) ? height : minHeight;
                        maxHeight = (height >= maxHeight) ? height : maxHeight;

                        if (WATER_VERTEX_HEIGHT(tile->unk6) != 0) {
                            f32 normalLen;
                            s32 centerPhase;
                            f32 tileSize = 64.0f;

                            tileX = x + waterOriginX;
                            northwestHeight = WATER_VERTEX_HEIGHT(D_803C0740[tileX - 1][z + waterOriginZ - 1].unk6);
                            southwestHeight = WATER_VERTEX_HEIGHT(D_803C0740[tileX - 1][z + waterOriginZ + 1].unk6);
                            southeastHeight = WATER_VERTEX_HEIGHT(D_803C0740[tileX + 1][z + waterOriginZ + 1].unk6);
                            northeastHeight = WATER_VERTEX_HEIGHT(D_803C0740[tileX + 1][z + waterOriginZ - 1].unk6);

                            displayList->unk286E0[(z * vertsPerRow) + x].v.ob[2] = WATER_CENTER_WAVE(waterOriginX, x, waterOriginZ, z) + height;

                            centerPhase = WATER_CENTER_PHASE(WATER_WAVE_ROW(waterOriginX, x, waterOriginZ, z), waterOriginX, x);
                            normalX = (f32)((WATER_CENTER_WAVE(waterOriginX, x + eastOffset, waterOriginZ, z)
                                + height + WATER_WAVE_SAMPLE(WATER_WAVE_ROW(waterOriginX, x, waterOriginZ, z), centerPhase))
                                - WATER_VERTEX_HEIGHT(D_803C0740[tileX + eastOffset][z + waterOriginZ].unk6));
                            normalX /= tileSize;
                            normalY = tileSize / tileSize;
                            normalZ = (f32)((WATER_WAVE_SAMPLE(WATER_WAVE_ROW(waterOriginX, x, waterOriginZ, z) + 1, centerPhase + 8)
                                + height + WATER_WAVE_SAMPLE(WATER_WAVE_ROW(waterOriginX, x, waterOriginZ, z), centerPhase))
                                - WATER_VERTEX_HEIGHT(D_803C0740[x + waterOriginX][z + waterOriginZ + 1].unk6));
                            normalZ /= tileSize;

                            normalLen = sqrtf(SQ(normalX) + SQ(normalZ) + SQ(normalY));
                            normalScale = 128.0f / normalLen;
                            normalX *= normalScale;
                            normalZ *= normalScale;
                            normalY *= normalScale;
                            displayList->unk286E0[(z * vertsPerRow) + x].n.n[0] = (s32) normalX;
                            displayList->unk286E0[(z * vertsPerRow) + x].n.n[1] = (s32) normalZ;
                            displayList->unk286E0[(z * vertsPerRow) + x].n.n[2] = (s32) normalY;

                            if (northwestHeight == 0) {
                                displayList->unk286E0[(northRowStart + x) - 1].v.ob[2] = height - WATER_CENTER_WAVE(waterOriginX, x, waterOriginZ, z);
                            }
                            if (southwestHeight == 0) {
                                displayList->unk286E0[(((z + 1) * vertsPerRow) + x) - 1].v.ob[2] = height - WATER_CENTER_WAVE(waterOriginX, x, waterOriginZ, z);
                            }
                            if (southeastHeight == 0) {
                                displayList->unk286E0[(((z + 1) * vertsPerRow) + x) + 1].v.ob[2] = height - WATER_CENTER_WAVE(waterOriginX, x, waterOriginZ, z);
                            }
                            if (northeastHeight == 0) {
                                displayList->unk286E0[(northRowStart + x) + 1].v.ob[2] = height - WATER_CENTER_WAVE(waterOriginX, x, waterOriginZ, z);
                            }
                        }
                    }
                }

                stripStart = 0;
                rowsEmitted = 0;
                cullVertexIndex = 0;
                // Each strip uses two rows of up to 16 vertices.
                for (; stripStart < waterWidth; stripStart += quadCount) {
                    winding = 1;
                    if (waterWidth < (stripStart + maxStripWidth)) {
                        stripWidth = (waterWidth - stripStart) + 1;
                    } else {
                        stripWidth = maxStripWidth;
                    }

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = (D_803F2D50.waterTileX << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = (D_803F2D50.waterTileZ << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = minHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = (D_803F2D50.waterTileX << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = ((D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = minHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = ((D_803F2D50.waterTileX + D_803F2D50.waterTileWidth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = ((D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = minHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = ((D_803F2D50.waterTileX + D_803F2D50.waterTileWidth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = (D_803F2D50.waterTileZ << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = minHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = (D_803F2D50.waterTileX << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = (D_803F2D50.waterTileZ << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = maxHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = (D_803F2D50.waterTileX << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = ((D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = maxHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = ((D_803F2D50.waterTileX + D_803F2D50.waterTileWidth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = ((D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = maxHeight;
                    cullVertexIndex++;

                    displayList->unk2C2F0[cullVertexIndex].v.ob[0] = ((D_803F2D50.waterTileX + D_803F2D50.waterTileWidth) << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[1] = (D_803F2D50.waterTileZ << 6);
                    displayList->unk2C2F0[cullVertexIndex].v.ob[2] = maxHeight;
                    cullVertexIndex++;

                    gSPVertex(gLayer1DL++, K0_TO_PHYS(&displayList->unk2C2F0[0]), 8, 0);

                    gSPCullDisplayList(gLayer1DL++, 0, 7);

                    gSPVertex(gLayer1DL++, K0_TO_PHYS(&displayList->unk286E0[stripStart]), stripWidth, 0);

                    for (row = 0; row < waterDepth - 1; ++row) {
                        gDPPipeSync(gLayer1DL++);
                        firstColumn = -100;
                        lastColumn = stripWidth;

                        // The scan ignores stripStart; only the vertex load and the quad test apply it.
                        for (column = 0; column < stripWidth; column++) {
                            if ((displayList->unk286E0[(row * vertsPerRow) + column].v.ob[2] != 0) ||
                                (displayList->unk286E0[((row + 1) * vertsPerRow) + column].v.ob[2] != 0)) {
                                if (firstColumn == -100) {
                                    firstColumn = column;
                                }
                                lastColumn = column;
                            }
                        }

                        // fakematch: IDO removes this empty block, but its basic blocks change the
                        // register allocation in the cull box.
#ifdef __sgi
                        if (stripWidth && stripWidth && stripWidth) {
                        }
#endif
                        if (firstColumn < 0) {
                            firstColumn = 0;
                        }

                        rowBelow = (row + 1) * vertsPerRow;
                        rowStart = row * vertsPerRow;
                        firstVertex = &displayList->unk286E0[rowBelow + stripStart + firstColumn];
                        rowsEmitted += 1;
                        columnEnd = lastColumn + 1;
                        vtxsEmitted += columnEnd - firstColumn;
                        firstSlot = (stripWidth * winding) + firstColumn;

                        gSPVertex(gLayer1DL++, K0_TO_PHYS(firstVertex), columnEnd - firstColumn, firstSlot);

                        for (x = 0; x < stripWidth - 1; x++) {
                            if (((D_803C0740[(stripStart + x) + waterOriginX][row + waterOriginZ].unk0 * 8) < displayList->unk286E0[(stripStart + x) + rowStart].v.ob[2]) ||
                                ((D_803C0740[(stripStart + x) + waterOriginX + 1][row + waterOriginZ].unk0 * 8) < displayList->unk286E0[(stripStart + x) + rowStart + 1].v.ob[2]) ||
                                ((D_803C0740[(stripStart + x) + waterOriginX + 1][row + waterOriginZ + 1].unk0 * 8) < displayList->unk286E0[(stripStart + x) + rowBelow + 1].v.ob[2]) ||
                                ((D_803C0740[(stripStart + x) + waterOriginX][row + waterOriginZ + 1].unk0 * 8) < displayList->unk286E0[(stripStart + x) + rowBelow].v.ob[2])) {

                                // Pack both triangle commands explicitly to preserve IDO's instruction order.
                                if (winding != 0) {
                                    // gSP2Triangles(dl, opposite, x + 1, opposite + 1, 0, opposite, x, x + 1, 0)
                                    s32 opposite = x + stripWidth;
                                    u32 nextField = _SHIFTL((x + 1) * 2, 0, 8);
                                    u32 farField = _SHIFTL((opposite + 1) * 2, 0, 8);
                                    Gfx *g = gLayer1DL++;

                                    g->words.w0 = _SHIFTL(G_TRI2, 24, 8) | (_SHIFTL(opposite * 2, 16, 8) | (nextField << 8) | farField);
                                    g->words.w1 = _SHIFTL(opposite * 2, 16, 8) | _SHIFTL(x * 2, 8, 8) | nextField;

                                } else {
                                    // gSP2Triangles(dl, x, bottomVertex + 1, x + 1, 0, x, bottomVertex, bottomVertex + 1, 0)
                                    u32 bottomVertex = stripWidth + x;
                                    u32 w0 = _SHIFTL(G_TRI2, 24, 8) | __gsSP1Triangle_w1f(x, bottomVertex + 1, x + 1, 0);
                                    u32 w1 = __gsSP1Triangle_w1f(x, bottomVertex, bottomVertex + 1, 0);
                                    Gfx *g = gLayer1DL++;

                                    g->words.w0 = w0;
                                    g->words.w1 = w1;
                                }
                            }
                        }

                        winding = 1 - winding;
                    }
                    quadCount = stripWidth - 1; // strips overlap by one column
                }

                gSPSetGeometryMode(gLayer1DL++, G_CULL_BACK);
                gSPTexture(gLayer1DL++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
            }
        }
    }
    func_802983D0_6A9A80();
}

#undef WATER_CENTER_WAVE
#undef WATER_WAVE_SAMPLE
#undef WATER_CENTER_PHASE
#undef WATER_WAVE_ROW
#undef WATER_VERTEX_HEIGHT

s32 func_802983D0_6A9A80(void) {
    s32 new_var UNUSED;
    s32 water_level = GET_WATER_LEVEL(D_803C0740, ((u16)gCameras[gCameraId].eyeX), ((u16)gCameras[gCameraId].eyeZ));
    // needed!
    new_var = water_level;
    return 0;
}

// draw_water
void setup_water_grid_material(Gfx **dl) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &gWaterTextureBuffer[gWaterAnimState.textureFrame << 9]);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 1024);
    gDPPipeSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(63));
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

    gDPSetEnvColor((*dl)++, gWaterEnvRed, gWaterEnvGreen, gWaterEnvBlue, D_803F2D50.waterEnvAlpha);

    gDPSetPrimColor((*dl)++, 128, gWaterAnimState.textureBlend, gWaterPrimRed, gWaterPrimGreen, gWaterPrimBlue, D_803F2D50.waterPrimAlpha);
}

void advance_water_animation(void) {
    // maximum 64
    gWaterAnimState.unk204 += 1;
    gWaterAnimState.unk204 &= 0x3F;

    // maximum 255
    gWaterAnimState.textureBlend += 64;
    if (gWaterAnimState.textureBlend >= 256) {
        gWaterAnimState.textureBlend &= 0xFF;
        gWaterAnimState.textureFrame += 1;
        gWaterAnimState.textureFrame &= 0xF;
    }

    gWaterAnimState.unk208 = 0;

    gWaterAnimState.unk206 += gWaterAnimState.unk20A;

    if (gWaterAnimState.unk206 == 240) {
        gWaterAnimState.unk20A = -8;
    }
    if (gWaterAnimState.unk206 == 0) {
        gWaterAnimState.unk20A = 8;
    }
    // maximum 31
    gWaterAnimState.unk20C += 1;
    gWaterAnimState.unk20C &= 0x1F;
}

// ESA: func_8002082C
s16 func_80298818_6A9EC8(s16 arg0, s16 arg1) {
    s16 phi_v1;
    s16 phi_t3;
    s16 phi_t4;
    s16 phi_a2;

    s16 a0;
    s16 a1;

    phi_v1 = (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) * (arg1 >> 6)) + 0) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) * (arg1 >> 6)) + ((arg0 >> 6) * (arg0 >> 6))) * 8)) +  0) & 0x3F];
    phi_t3 = (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) * (arg1 >> 6)) + 1) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) * (arg1 >> 6)) + ((arg0 >> 6) * (arg0 >> 6))) * 8)) +  8) & 0x3F];

    phi_t4 = (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) + (arg1 >> 6)) + 1) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) + (arg1 >> 6)) + ((arg0 >> 6) + (arg0 >> 6))) * 8)) + 16) & 0x3F];
    phi_a2 = (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) + (arg1 >> 6)) + 0) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) + (arg1 >> 6)) + ((arg0 >> 6) + (arg0 >> 6))) * 8)) +  8) & 0x3F];

    if (phi_v1 < 16) {
        phi_v1 = MAX(phi_a2, MAX(phi_t3, phi_t4));
    }
    if (phi_t3 < 16) {
        phi_t3 = MAX(phi_v1, MAX(phi_t4, phi_a2));
    }
    if (phi_t4 < 16) {
        phi_t4 = MAX(phi_v1, MAX(phi_t3, phi_a2));
    }
    if (phi_a2 < 16) {
        phi_a2 = MAX(phi_v1, MAX(phi_t3, phi_t4));
    }

    a0 = arg0 & 0x3F;
    a1 = arg1 & 0x3F;

    if (a0 < a1) {
        return (phi_v1 + ((((phi_t4 - phi_t3) * a0) + ((phi_t3 - phi_v1) * a1)) >> 6));
    } else {
        return (phi_v1 + ((((phi_a2 - phi_v1) * a0) + ((phi_t4 - phi_a2) * a1)) >> 6));
    }
}

s16 unused_80298B70_6AA220(s16 arg0, s16 arg1) {
    s16 temp_t3;
    s16 temp_v0;

    s16 temp_a2;
    s16 temp_a3;
    s16 temp_t0;
    s16 temp_v1;

    temp_v1 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2;
    temp_a2 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2;
    temp_a3 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2;
    temp_t0 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2;

    if ((temp_v1 + temp_a2 + temp_a3 + temp_t0) == 0) {
        return 0;
    }

    temp_v0 = arg0 & 0x3F;
    temp_t3 = arg1 & 0x3F;
    if (temp_v0 < temp_t3) {
        return (gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_a3 - temp_a2) * temp_v0) + ((temp_a2 - temp_v1) * temp_t3)) >> 6);
    } else {
        return (gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_t0 - temp_v1) * temp_v0) + ((temp_a3 - temp_t0) * temp_t3)) >> 6);
    }
}

void unused_80298D44_6AA3F4(Animal *arg0) {
    s16 x;
    s16 z;
    s32 tmp;
    s32 tmp2;

    x = (((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7 & 0xF0) >> 4) & 7) * (1 - (((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7 >> 4) & 8) >> 2));
    z = (u16)(((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7       )     ) & 7) * (1 - (((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7     ) & 8) >> 2));

    if (x != 0) {
        tmp = (arg0->xVelocity.w - (x << 17));
        arg0->xVelocity.w -= tmp >> 1;
    }
    if (z != 0) {
        tmp2 = (arg0->zVelocity.w - (z << 17));
        tmp = tmp2; // regalloc fix
        arg0->zVelocity.w -= tmp >> 1;
    }
}

// ESA: func_80020B38
s32 func_80298E08_6AA4B8(s16 arg0, s16 arg1) {
    // equivalent to dividing by 64
    arg0 >>= 6;
    arg1 >>= 6;

    if ((arg0 < D_803F2D50.waterTileX) ||
        (arg1 < D_803F2D50.waterTileZ) ||
        ((D_803F2D50.waterTileX + D_803F2D50.waterTileWidth) < arg0) ||
        ((D_803F2D50.waterTileZ + D_803F2D50.waterTileDepth) < arg1)) {
        return 0;
    }

    return 1;
}

// ESA: func_80020BB4
s16 func_80298E98_6AA548(s16 arg0, s16 arg1) {
    s16 tmp;
    s16 res;

    res = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;

    if (func_80298E08_6AA4B8(arg0, arg1)) {
        tmp = gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63];
        return res + tmp;
    } else {
        return res;
    }
}

// ESA: func_80020C8C
s16 func_80298F78_6AA628(s16 arg0, s16 arg1) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 temp_t4;
    s16 temp_t6;

    func_80299640_6AACF0(arg0 >> 6, arg1 >> 6, &sp36, &sp34, &sp32, &sp30);
    temp_t4 = arg0 & 0x3F;
    temp_t6 = arg1 & 0x3F;
    if ((temp_t4 + temp_t6) < 64) {
        return sp36 + ((((sp32 - sp36) * temp_t4) + ((sp34 - sp36) * temp_t6)) >> 6);
    } else {
        return sp30 + ((((sp34 - sp30) * (64 - temp_t4)) + ((sp32 - sp30) * (64 - temp_t6))) >> 6);
    }
}

s16 unused_802990A4_6AA754(s16 arg0, s16 arg1) {
    s16 tmp0;
    s16 tmp1;

    tmp0 = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;
    tmp1 = gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63] >> 1;

    return tmp0 + tmp1;
}

void func_80299140_6AA7F0(void) {
    s32 pad[2] UNUSED;
    s32 xPos; //sp5C;
    s32 zPos; //sp58;
    s32 yPos; //sp54;
    s16 i, j;
    s32 maxPoint;
    s16 temp_a3;
    s16 maxX;
    s16 maxZ;
    s16 minX;
    s16 minZ;
    s16 water_level;
    s32 newMax;

    maxPoint = 100000;

    minX = ((s32)gCameras[gCameraId].eyeX >> 6) - 25;
    minZ = ((s32)gCameras[gCameraId].eyeZ >> 6) - 25;
    maxX = ((s32)gCameras[gCameraId].eyeX >> 6) + 25;
    maxZ = ((s32)gCameras[gCameraId].eyeZ >> 6) + 25;

#ifdef __sgi
    if (1) { }
#endif

    if (minX < 4) {
        minX = 4;
    }
    if (minZ < 8) {
        minZ = 8;
    }
    if (maxX > 68) {
        maxX = 68;
    }
    if (maxZ > 104) {
        maxZ = 104;
    }

    for (i = minX; i <= maxX; i += 3) {
        for (j = minZ; j <= maxZ; j += 3) {
            temp_a3 = D_803C0740[i][j].unk6 << 2;
            if (temp_a3 != 0) {
                newMax = ABS((i << 6) - ((s16) gCameras[gCameraId].eyeX)) + ABS((j << 6) - (s16) gCameras[gCameraId].eyeZ) + ABS(temp_a3 - (s16) gCameras[gCameraId].eyeY);
                newMax = ABS(newMax);

                if (newMax < maxPoint) {
                    maxPoint = newMax;
                    xPos = (i << 6);
                    zPos = (j << 6);
                    yPos = temp_a3;
                }
            }
        }
    }

    if (maxPoint != 100000) {
        if ((D_803F2D50.waterMode == 0) || (D_803F2D50.waterMode == 2)) {
            water_level = ((GET_WATER_LEVEL(D_803C0740, (u16)gCameras[gCameraId].eyeX, (u16)gCameras[gCameraId].eyeZ)) << 2);
            if (water_level > (gCameras[gCameraId].eyeY - 12.0f)) {
                func_8032CD70_73E420((void*)&gWaterAnimState.unk204, SFX_UNKNOWN_12, 0x4718, 0, 0.28f, xPos, zPos, yPos); // D_803BAD00_7CC3B0
            } else {
                func_8032CD70_73E420((void*)&gWaterAnimState.unk204, SFX_UNKNOWN_12, 0x2800, 0, 1.0f, xPos, zPos, yPos);
            }
        }
        if (D_803F2D50.waterMode == 1) {
            func_8032CD70_73E420((void*)&gWaterAnimState.unk204, SFX_UNKNOWN_64, 0x7FFF, 0, 0.25f, xPos, zPos, yPos);
        }
    }
}

// ESA: func_80020D84
void func_80299640_6AACF0(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_a2;
    s16 temp_t7;

    if (func_80298E08_6AA4B8(arg0 << 6, arg1 << 6) == 0) {
        temp_a0 = D_803C0740[arg0 + 0][arg1 + 0].unk6 << 2;
        temp_a1 = D_803C0740[arg0 + 0][arg1 + 1].unk6 << 2;
        temp_a2 = D_803C0740[arg0 + 1][arg1 + 0].unk6 << 2;
        temp_t7 = D_803C0740[arg0 + 1][arg1 + 1].unk6 << 2;

        *arg2 = temp_a0;
        if (*arg2 == 0) {
            *arg2 = temp_a1;
            if (*arg2 == 0) {
                *arg2 = temp_a2;
                if (*arg2 == 0) {
                    *arg2 = temp_t7;
                }
            }
        }
        *arg4 = temp_a2;
        if (*arg4 == 0) {
            *arg4 = temp_a0;
            if (*arg4 == 0) {
                *arg4 = temp_t7;
                if (*arg4 == 0) {
                    *arg4 = temp_a1;
                }
            }
        }
        *arg3 = temp_a1;
        if (*arg3 == 0) {
            *arg3 = temp_t7;
            if (*arg3 == 0) {
                *arg3 = temp_a0;
                if (*arg3 == 0) {
                    *arg3 = temp_a2;
                }
            }
        }
        *arg5 = temp_t7;
        if (*arg5 == 0) {
            *arg5 = temp_a1;
            if (*arg5 == 0) {
                *arg5 = temp_a2;
                if (*arg5 == 0) {
                    *arg5 = temp_a0;
                }
            }
        }

        *arg2 += gWaterAnimState.unk0[((arg0 + 0) * (arg1 + 0)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 0) * (arg1 + 0)) + ((arg0 + 0) * (arg0 + 0))) << 3)) & 63] << 1;
        *arg4 += gWaterAnimState.unk0[((arg0 + 1) * (arg1 + 0)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 1) * (arg1 + 0)) + ((arg0 + 1) * (arg0 + 1))) << 3)) & 63] << 1;
        *arg3 += gWaterAnimState.unk0[((arg0 + 0) * (arg1 + 1)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 0) * (arg1 + 1)) + ((arg0 + 0) * (arg0 + 0))) << 3)) & 63] << 1;
        *arg5 += gWaterAnimState.unk0[((arg0 + 1) * (arg1 + 1)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 1) * (arg1 + 1)) + ((arg0 + 1) * (arg0 + 1))) << 3)) & 63] << 1;
    } else {
        s32 idx1;
        s32 idx2;
        u16 a;
        s16 b; // fuuuu
        u16 c;

        c = D_803F2D50.waterTileX;
        a = D_803F2D50.waterTileZ;
        b = D_803F2D50.waterTileWidth + 1;

        idx1 = ((((s16)(arg1 - a) + 0) * b) + (s16)(arg0 - c));
        idx2 = ((((s16)(arg1 - a) + 1) * b) + (s16)(arg0 - c));

        *arg2 = gDisplayListContext->unk286E0[idx1 + 0].v.ob[2];
        *arg3 = gDisplayListContext->unk286E0[idx2 + 0].v.ob[2];
        *arg5 = gDisplayListContext->unk286E0[idx2 + 1].v.ob[2];
        *arg4 = gDisplayListContext->unk286E0[idx1 + 1].v.ob[2];
    }
}
