#include <ultra64.h>
#include "common.h"

#include "dan.h"

// ========================================================
// .text
// ========================================================

// load dan data?
void func_803973A0_7A8A50(s16 clip) {
    s32 len = D_803B6890_7C7F40[clip].romEnd - D_803B6890_7C7F40[clip].romStart;

    osInvalDCache(D_803B6890_7C7F40[clip].ramStart, D_803B6890_7C7F40[clip].ramEnd - D_803B6890_7C7F40[clip].ramStart);
    dma_read(D_803B6890_7C7F40[clip].romStart, D_803B6890_7C7F40[clip].ramDest, len);
}

void append_rig_modelview_transform_xlu(u8 push, f32 x_amt, f32 y_amt, f32 z_amt, f32 x_angle, f32 y_angle, f32 z_angle) {
    guTranslate(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], x_amt, y_amt, z_amt);
    if (push) {
        gSPMatrix(gXluDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    } else {
        gSPMatrix(gXluDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    }

    guRotate(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], y_angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gXluDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guRotate(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], z_angle, 0.0f, 0.0f, 1.0f);
    gSPMatrix(gXluDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guRotate(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], x_angle, 1.0f, 0.0f, 0.0f);
    gSPMatrix(gXluDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

// init/reset something
void func_803976E0_7A8D90(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        D_803F713C[i] = 0;
        D_803F7144[i] = 0;
        D_803F714C[i] = 0;
    }
}

// arg1 is 0 to 2
void func_80397734_7A8DE4(s16 clip, u8 slot) {
    s16 i;

    clip += D_803B6B24_7C81D4[slot];
    func_803973A0_7A8A50(clip);
    for (i = 0; i < 10; i++) {
        D_803F70F8[slot][i] = 0;
        gRigPoseStates[slot][i].elapsed = 0.0f;
        gRigPoseStates[slot][i].duration = 0.0f;
    }
    D_803F713C[slot] = 0x3FF; // 10x1, enable all?
    D_803F714C[slot] = 0;
    D_803F7144[slot] = 0;
    D_803F7134[slot] = clip;
}

void func_80397840_7A8EF0(void) {
    s16 i;
    s16 j;
    RigKeyframe *keyframe;
    f32 rotX, rotZ, rotY, posX, posZ, posY;

    for (i = 0; i < 3; i++) {

        if (D_803F713C[i] != 0) {

            while ((D_803B7000_7C86B0[D_803F7134[i]].sfx != NULL) &&
                   (D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].frame == D_803F714C[i])) {
                func_8032C508_73DBB8(
                    D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].id,
                    D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].volume,
                    0,
                    D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].pitch);
                D_803F7144[i]++;
            };

            for (j = 0; j < 10; j++) {
                if (D_803F713C[i] & (1 << j)) {

                    if (gRigPoseStates[i][j].duration <= gRigPoseStates[i][j].elapsed) {
                        s32 idx = D_803F70F8[i][j];
                        RigAnimation *anim = D_803B7000_7C86B0[D_803F7134[i]].anim;

                        if (anim->boneTrack[j].keyframeCount <= idx) {
                            D_803F713C[i] &= ~ (1 << j);  // clear bone mask
                            continue;
                        }

                        keyframe = &anim->boneTrack[j].keyframes[idx];
                        rotX =  ((keyframe->rotX * 180.0f) / 32768.0f);
                        rotZ = -((keyframe->rotZ * 180.0f) / 32768.0f);
                        rotY = -((keyframe->rotY * 180.0f) / 32768.0f);
                        posX =  (f32)keyframe->posX;
                        posZ = -(f32)keyframe->posZ;
                        posY = -(f32)keyframe->posY;
                        func_80397C58_7A9308(
                            rotX,
                            rotZ,
                            rotY,
                            posX,
                            posZ,
                            posY,
                            keyframe->duration,
                            j,
                            i);
                        D_803F70F8[i][j]++;
                    }
                }
            }
            func_80397D1C_7A93CC(i);
            D_803F714C[i]++;
        }
    }
}

// reset poses
void func_80397B84_7A9234(void) {
    s16 i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 3; k++) {
                gRigPoseStates[i][j].previous.rot[k] = 0.0f;
                gRigPoseStates[i][j].previous.pos[k] = 0.0f;

                gRigPoseStates[i][j].current.rot[k] = 0.0f;
                gRigPoseStates[i][j].current.pos[k] = 0.0f;

                gRigPoseStates[i][j].target.rot[k] = 0.0f;
                gRigPoseStates[i][j].target.pos[k] = 0.0f;
            }
            gRigPoseStates[i][j].elapsed = 0.0f;
            gRigPoseStates[i][j].duration = 0.0f;
            gRigPoseStates[i][j].active = 0;
        }
    }
}

void func_80397C58_7A9308(f32 rotX, f32 royZ, f32 rotY, f32 posX, f32 posZ, f32 posY, f32 duration, s16 phase, u8 idx) {
    RigPoseState *rps = &gRigPoseStates[idx][phase];

    rps->previous.rot[0] = rps->current.rot[0];
    rps->previous.rot[1] = rps->current.rot[1];
    rps->previous.rot[2] = rps->current.rot[2];

    rps->previous.pos[0] = rps->current.pos[0];
    rps->previous.pos[1] = rps->current.pos[1];
    rps->previous.pos[2] = rps->current.pos[2];

    rps->target.rot[0] = rotX;
    rps->target.rot[1] = royZ;
    rps->target.rot[2] = rotY;

    rps->target.pos[0] = posX;
    rps->target.pos[1] = posZ;
    rps->target.pos[2] = posY;

    rps->elapsed = 0.0f;
    rps->duration = duration;
    rps->active = 1;
}

void func_80397D1C_7A93CC(u8 arg0) {
    f32 pad[4];
    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f16;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f30;
    f32 tmp;
    f32 factor;
    s16 i;

    for (i = 0; i < 10; i++) {
        if (gRigPoseStates[arg0][i].active != 0) {
            factor = 2.0f;
            gRigPoseStates[arg0][i].elapsed += 1.0f;
            if (gRigPoseStates[arg0][i].duration <= gRigPoseStates[arg0][i].elapsed) {
                gRigPoseStates[arg0][i].current.rot[0] = gRigPoseStates[arg0][i].target.rot[0];
                gRigPoseStates[arg0][i].current.rot[1] = gRigPoseStates[arg0][i].target.rot[1];
                gRigPoseStates[arg0][i].current.rot[2] = gRigPoseStates[arg0][i].target.rot[2];
                gRigPoseStates[arg0][i].current.pos[0] = gRigPoseStates[arg0][i].target.pos[0];
                gRigPoseStates[arg0][i].current.pos[1] = gRigPoseStates[arg0][i].target.pos[1];
                gRigPoseStates[arg0][i].current.pos[2] = gRigPoseStates[arg0][i].target.pos[2];
                gRigPoseStates[arg0][i].active = 0;
            } else {
                temp_f22 = (gRigPoseStates[arg0][i].target.rot[0] - gRigPoseStates[arg0][i].previous.rot[0]) / factor;
                temp_f24 = (gRigPoseStates[arg0][i].target.rot[1] - gRigPoseStates[arg0][i].previous.rot[1]) / factor;
                temp_f26 = (gRigPoseStates[arg0][i].target.rot[2] - gRigPoseStates[arg0][i].previous.rot[2]) / factor;
                temp_f28 = (gRigPoseStates[arg0][i].target.pos[0] - gRigPoseStates[arg0][i].previous.pos[0]) / factor;
                temp_f30 = (gRigPoseStates[arg0][i].target.pos[1] - gRigPoseStates[arg0][i].previous.pos[1]) / factor;
                temp_f16 = (gRigPoseStates[arg0][i].target.pos[2] - gRigPoseStates[arg0][i].previous.pos[2]) / factor;
                tmp = ((gRigPoseStates[arg0][i].elapsed / gRigPoseStates[arg0][i].duration) * 180.0f);
                // this is not quite PI (3.14159265359)
                temp_f0 = cosf((SSSV_PI / 180) * tmp);
                gRigPoseStates[arg0][i].current.rot[0] = (gRigPoseStates[arg0][i].previous.rot[0] + temp_f22) - (temp_f22 * temp_f0);
                gRigPoseStates[arg0][i].current.rot[1] = (gRigPoseStates[arg0][i].previous.rot[1] + temp_f24) - (temp_f24 * temp_f0);
                gRigPoseStates[arg0][i].current.rot[2] = (gRigPoseStates[arg0][i].previous.rot[2] + temp_f26) - (temp_f26 * temp_f0);
                gRigPoseStates[arg0][i].current.pos[0] = (gRigPoseStates[arg0][i].previous.pos[0] + temp_f28) - (temp_f28 * temp_f0);
                gRigPoseStates[arg0][i].current.pos[1] = (gRigPoseStates[arg0][i].previous.pos[1] + temp_f30) - (temp_f30 * temp_f0);
                gRigPoseStates[arg0][i].current.pos[2] = (gRigPoseStates[arg0][i].previous.pos[2] + temp_f16) - (temp_f16 * temp_f0);
            }
        }
    }
}

void render_rig_instance_xlu(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5, u8 idx, u8 arg7) {
    s16 i;
    s16 j;
    s16 var_s2;

    if (arg7 == 2) {
        func_8034C8F8_75DFA8(
            gRigPoseStates[arg7][0].current.pos[0] + (arg0 >> 16),
            gRigPoseStates[arg7][0].current.pos[1] + (arg1 >> 16),
            gRigPoseStates[arg7][0].current.pos[2] + (arg2 >> 16),
            ((arg4 - gRigPoseStates[arg7][0].current.rot[2]) * 256) / 360,
            D_803A8370_7B9A20[1], // 0x1034190
            (arg5 << 3) >> 0x10,
            (arg5 << 4) >> 0x10,
            0x9B,
            0,
            0,
            0,
            8,
            1);
    }

    arg5 = arg5 / 5;
    func_80125FE0(
        &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs],
        arg0,
        arg1,
        arg2,
        arg3,
        arg4,
        arg5,
        arg5,
        arg5);

    gSPMatrix(gXluDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    append_rig_modelview_transform_xlu(
        0,
        gRigPoseStates[arg7][0].current.pos[0],
        gRigPoseStates[arg7][0].current.pos[1],
        gRigPoseStates[arg7][0].current.pos[2],
        gRigPoseStates[arg7][0].current.rot[0],
        gRigPoseStates[arg7][0].current.rot[1],
        gRigPoseStates[arg7][0].current.rot[2]
    );
    gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][6]);

    if (arg7 != 2) {
        var_s2 = 4;
        j = 0;

        for (i = 0; i < 2; i++) {
            // push
            append_rig_modelview_transform_xlu(
                1,
                gRigPoseStates[arg7][var_s2].current.pos[0],
                gRigPoseStates[arg7][var_s2].current.pos[1],
                gRigPoseStates[arg7][var_s2].current.pos[2],
                gRigPoseStates[arg7][var_s2].current.rot[0],
                gRigPoseStates[arg7][var_s2].current.rot[1],
                gRigPoseStates[arg7][var_s2].current.rot[2]
            );
            gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][j]);
            var_s2++;
            j++;

            // no push
            append_rig_modelview_transform_xlu(
                0,
                gRigPoseStates[arg7][var_s2].current.pos[0],
                gRigPoseStates[arg7][var_s2].current.pos[1],
                gRigPoseStates[arg7][var_s2].current.pos[2],
                gRigPoseStates[arg7][var_s2].current.rot[0],
                gRigPoseStates[arg7][var_s2].current.rot[1],
                gRigPoseStates[arg7][var_s2].current.rot[2]
            );
            gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][j]);
            var_s2++;
            j++;

            // no push
            append_rig_modelview_transform_xlu(
                0,
                gRigPoseStates[arg7][var_s2].current.pos[0],
                gRigPoseStates[arg7][var_s2].current.pos[1],
                gRigPoseStates[arg7][var_s2].current.pos[2],
                gRigPoseStates[arg7][var_s2].current.rot[0],
                gRigPoseStates[arg7][var_s2].current.rot[1],
                gRigPoseStates[arg7][var_s2].current.rot[2]
            );
            gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][j]);
            var_s2++;
            j++;

            gSPPopMatrix(gXluDL++, G_MTX_MODELVIEW);

        }
    }

    append_rig_modelview_transform_xlu(
        1,
        gRigPoseStates[arg7][1].current.pos[0],
        gRigPoseStates[arg7][1].current.pos[1],
        gRigPoseStates[arg7][1].current.pos[2],
        gRigPoseStates[arg7][1].current.rot[0],
        gRigPoseStates[arg7][1].current.rot[1],
        gRigPoseStates[arg7][1].current.rot[2]
    );
    gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][7]);

    if (arg7 != 2) {
        append_rig_modelview_transform_xlu(
            1,
            gRigPoseStates[arg7][2].current.pos[0],
            gRigPoseStates[arg7][2].current.pos[1],
            gRigPoseStates[arg7][2].current.pos[2],
            gRigPoseStates[arg7][2].current.rot[0],
            gRigPoseStates[arg7][2].current.rot[1],
            gRigPoseStates[arg7][2].current.rot[2]
        );
        gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][8]);
        gSPPopMatrix(gXluDL++, G_MTX_MODELVIEW);
    }
    append_rig_modelview_transform_xlu(
        1,
        gRigPoseStates[arg7][1].current.pos[0],
        gRigPoseStates[arg7][1].current.pos[1],
        gRigPoseStates[arg7][1].current.pos[2],
        gRigPoseStates[arg7][1].current.rot[0],
        gRigPoseStates[arg7][1].current.rot[1],
        gRigPoseStates[arg7][1].current.rot[2]
    );

    if (arg7 == 1) {
        gDPSetPrimColor(gXluDL++, 0, 0, 0xEA, 0xE6, 0xFF, 0xFF); // very light lilac
        gDPSetCombineLERP(gXluDL++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
    }

    append_rig_modelview_transform_xlu(
        1,
        gRigPoseStates[arg7][3].current.pos[0],
        gRigPoseStates[arg7][3].current.pos[1],
        gRigPoseStates[arg7][3].current.pos[2],
        gRigPoseStates[arg7][3].current.rot[0],
        gRigPoseStates[arg7][3].current.rot[1],
        gRigPoseStates[arg7][3].current.rot[2]
    );

    gSPDisplayList(gXluDL++, gRigPartDisplayLists[idx][9]);
    gSPPopMatrix(gXluDL++, G_MTX_MODELVIEW);
    gSPPopMatrix(gXluDL++, G_MTX_MODELVIEW);
    gSPPopMatrix(gXluDL++, G_MTX_MODELVIEW);
}
