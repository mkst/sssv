#include <ultra64.h>
#include "common.h"



void func_80131554(s32 arg0);
s32 func_80131908(u32 arg0, s32 arg1, s32 arg2);

// create audio thread
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131290.s")
// plenty more work to do here...
// void func_80131290(ALSynConfig *c, s32 priority) {
//     f32 temp_f0;
//
//     s32 temp_s2;
//     u32 temp_s0;
//     void *temp_s0_2;
//     void *temp_s1;
//     void *temp_v0_2;
//     void *temp_v1_2;
//     void *phi_s0;
//     void *phi_s1;
//     s32 phi_s2;
//     u32 phi_s0_2;
//     void *phi_s0_3;
//     s32 i;
//
//     D_80241758 = (u8)0;
//     c->dmaproc = func_80131AA0;
//     c->outputRate = osAiSetFrequency(32000);
//     temp_f0 = (c->outputRate * 1.0f) / D_80204294; // 50 or 60 hz
//     D_80241D0A = temp_f0;
//
//     if (D_80241D0A < temp_f0) {
//         D_80241D0A += 1 ;
//     }
//     // align to 16
//     if ((D_80241D0A & 0xF) != 0) {
//         D_80241D0A = (D_80241D0A & 0xFFF0) + 16;
//     }
//     D_80241D08 = D_80241D0A - 16;
//     D_80241D0C = D_80241D0A + 196;
//
//     // void alInit(ALGlobals *globals, ALSynConfig *c);
//     alInit(&D_8023F708, c);
//     // are these nodes?
//     D_80241768[0].cur = 0;
//     D_80241768[0].base = 0;
//
//     phi_s0 = &D_8024177C;
//     phi_s1 = &D_80241768;
//     phi_s2 = 0;
// // loop_5:
// //     // void    alLink(ALLink *element, ALLink *after);
// //     alLink(phi_s0, phi_s1);
// //     temp_s2 = phi_s2 + 1;
// //     temp_s1 = phi_s1 + 0x14;
// //     temp_s1->unk-4 = alHeapDBAlloc(0, 0, c->heap, 1, 0x400);
// //     phi_s0 = phi_s0 + 0x14;
// //     phi_s1 = temp_s1;
// //     phi_s2 = temp_s2;
// //     if (temp_s2 < 0x47) {
// //         goto loop_5;
// //     }
// //     temp_s1->unk10 = alHeapDBAlloc(0, 0, c->heap, 1, 0x400);
// //     phi_s0_2 = (u32) &D_8023F410;
// // loop_7:
// //     temp_s0 = phi_s0_2 + 4;
// //     temp_s0->unk-4 = alHeapDBAlloc(0, 0, c->heap, 1, 0x3E80);
// //     phi_s0_2 = temp_s0;
// //     if (temp_s0 < (u32) &D_8023F418) {
// //         goto loop_7;
// //     }
// //     phi_s0_3 = &D_8023F410;
// // loop_9:
// //     temp_v0_2 = alHeapDBAlloc(0, 0, c->heap, 1, 0x90);
// //     phi_s0_3->unk8 = temp_v0_2;
// //     temp_v0_2->unk70 = (u16)2;
// //     temp_v1_2 = phi_s0_3->unk8;
// //     temp_v1_2->unk74 = temp_v1_2;
// //     temp_s0_2 = phi_s0_3 + 4;
// //     phi_s0_3->unk8->unk0 = alHeapDBAlloc(0, 0, c->heap, 1, D_80241D0C * 4);
// //     phi_s0_3 = temp_s0_2;
// //     if (temp_s0_2 != &D_8023F41C) {
// //         goto loop_9;
// //     }
//     osCreateMesgQueue(&D_8023F670, &D_8023F688, 0x20);
//     osCreateMesgQueue(&D_8023F5D8, &D_8023F5F0, 0x20);
//     osCreateMesgQueue(&D_802423D0, &D_802423E8, 0x48);
//     osCreateThread(&gAudioThread, 3, &func_80131554, 0, &D_80241758, priority);
//     osStartThread(&gAudioThread);
// }

// audio thread
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131554.s")
// NON-MATCHING: 50% there...
// void func_80131554(s32 arg0) {
//     struct006 *mesg;
//     OSScClient sp48;
//     s16 errors;
//     s32 phi_s1;
//     s32 errorState;
//
//     osScAddClient(&D_801603D0, &sp48, &D_8023F5D8);
//
//     D_8028654C = (u16)0;
//     errors = (u16)0;
//     phi_s1 = 0;
//     errorState = 0;
//     do {
//         if (errors != 0) {
//             errors++;
//         }
//         D_8028654C = errors;
//         if ((s32) errors >= 21) {
//             errorState = 1;
//         }
//         osRecvMesg(&D_8023F5D8, &mesg, (u16)1);
//         switch (mesg->unk0->unk0) {
//             case 1:
//                 if (func_80131700((D_8023F410[D_80154680 % 3U])->unk8, phi_s1) != 0) {
//                     osRecvMesg(&D_8023F670, &mesg, OS_MESG_BLOCK);
//                     func_801318C8(mesg->unk4);
//                     phi_s1 = mesg->unk4;
//                 }
//                 break;
//             case 4:
//                 D_8028654C = (u16)1;
//                 break;
//             case 10:
//                 errorState = 1;
//                 break;
//         }
//         errors = D_8028654C;
//
//     } while (errorState == 0);
//
//     // deinit
//     alClose(&D_8023F708);
//
//     // spin forever
//     while (TRUE) {};
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131700.s")
// s32 func_80131700(struct019 *arg0, struct020 *arg1) {
//     s32 sp44;
//     s32 sp3C[4];
//     s32 temp_v1_2;
//
//     func_80131AD8();
//     sp44 = osVirtualToPhysical(arg0->unk0);
//     if (arg1 != NULL) {
//         osAiSetNextBuffer(arg1->unk0, arg1->unk4 * 4);
//     }
//     arg0->unk4 = ((D_80241D0A - (osAiGetLength() >> 2)) + 196) & 0xFFF0;
//
//     if (arg0->unk4 < D_80241D08) {
//         arg0->unk4 = D_80241D08;
//     }
//     temp_v1_2 = alAudioFrame(&D_8023F410[D_80154688], &sp3C, sp44, arg0->unk4);
//     if (sp3C == NULL) {
//         return 0;
//     }
//     arg0->unk8 = 0;
//     arg0->unk58 = &D_8023F670;
//     arg0->unk5C = &arg0->unk70;
//     arg0->unk10 = 2;
//     arg0->unk48 = &D_8023F410[D_80154688];
//     arg0->unk4C = ((s32) (temp_v1_2 - (s32)&D_8023F410[D_80154688] >> 3) << 3);
//     arg0->unk18 = 2;
//     arg0->unk20 = &D_8014D390;
//     arg0->unk24 = (&D_8014D460 - &D_8014D390);
//     arg0->unk1C = 0;
//     arg0->unk28 = &D_80150600;
//     arg0->unk30 = &D_8015DF10;
//     arg0->unk34 = 2048;
//     arg0->unk38 = 0;
//     arg0->unk3C = 0;
//     arg0->unk40 = 0;
//     arg0->unk44 = 0;
//     arg0->unk50 = 0;
//     arg0->unk54 = 0;
//     osSendMesg(osScGetCmdQ(&D_801603D0), &arg0->unk8, OS_MESG_BLOCK);
//     D_80154688 ^= 1;
//     return 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801318C8.s")
// ???
// void func_801318C8(s32 arg0) {
//     if (((osAiGetLength() >> 2) == 0) && (D_8015518C == 0)) {
//         D_8015518C = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131908.s")

void *func_80131AA0(s32 *arg0) {
    if (D_80241758.unk0 == 0) {
        D_80241758.unk4 = 0;
        D_80241758.unk8 = &D_80241768;
        D_80241758.unk0 = 1U;
    }
    *arg0 = &D_80241758;
    return func_80131908;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131AD8.s")
// need to determine type of D_80241758
// void func_80131AD8(void) {
//     s32 sp40[2];
//     struct040 *temp_a1;
//     struct040 *temp_v0;
//     u32 i;
//     struct040 *phi_s0_2;
//
//     for (i = 0; i < D_80154684; i++) {
//         osRecvMesg(&D_802423D0, &sp40, OS_MESG_NOBLOCK);
//     }
//
//     for (phi_s0_2 = D_80241758.unk4; phi_s0_2 != NULL; phi_s0_2 = phi_s0_2->unk0) {
//         temp_v0 = phi_s0_2->unk0;
//         if ((u32) (phi_s0_2->unkC + 2) < (u32) D_80154680) {
//             if ((s32)phi_s0_2 == D_80241758.unk4) {
//                 D_80241758.unk4 = temp_v0;
//             }
//             alUnlink(phi_s0_2);
//             temp_a1 = D_80241758.unk8;
//             if (temp_a1 != 0) {
//                 alLink(phi_s0_2, temp_a1);
//             } else {
//                 D_80241758.unk8 = phi_s0_2;
//                 phi_s0_2->unk0 = NULL;
//                 phi_s0_2->unk4 = 0;
//             }
//         }
//     }
//     D_80154684 = 0;
//     D_80154680 += 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131BF0.s")

// some kind of de-init?
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801320EC.s")
// NON-MATCHING: once D_80286338 is figured out...
// struct042 *func_801320EC(void) {
//     struct042 *temp_a0;
//     s32 i;
//
//     if (D_80155154 == 0) {
//         return NULL;
//     }
//     if (D_8015468C >= 21) {
//         return NULL;
//     }
//
//     for (i = 0; i < 20; i++) {
//         if (D_80286388[i] != -1) {
//             D_80286388[i] = -1;
//             break;
//         }
//     }
//     temp_a0 = &D_80286338[i]; // arghhh what type is this hold?
//     temp_a0->unk0->unk1E = i;
//     return temp_a0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132174.s")

void func_801322EC(struct026 *arg0, struct026 *arg1, struct026 *arg2) {
    if ((D_80155154 != 0) && (arg0 != NULL)) {
        func_80132044(arg0->unk1E);
        if (arg0 == arg1->unk0) {
            arg1->unk0 = arg0->next;
            if (arg1->unk0 != NULL) {
                arg1->unk0->prev = NULL;
            } else {
                arg2->unk0 = NULL;
            }
        } else {
            arg0->prev->next = arg0->next;
            if (arg0 != arg2->unk0) {
                arg0->next->prev = arg0->prev;
            } else {
                arg2->unk0 = arg0->prev;
            }
        }
    }
}

void func_80132394(void) {
    struct017 *snd;
    for (snd = D_8028631C; snd != NULL; snd = snd->next);
}

struct017 *func_801323B8(s16 slot) {
    struct017 *snd;

    if (D_80155154 == 0) {
        return NULL;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if (slot == snd->sndSlot) {
            return snd;
        }
    }
    return NULL;
}

struct017 *func_80132414(u16 id) {
    struct017 *snd;

    if (D_80155154 == 0) {
        return NULL;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if (id == snd->sndID) {
            return snd;
        }
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132474.s")

// used?
struct017 *func_80132568(void) {
    // FIXME: fakematch shenanigans
    struct017* foo;
    struct017** bar;

    bar = &foo;
    foo = &D_80286320;

    D_80286320 = 0;
    D_8028631C = 0;

    if (1) {}
    return *bar;
}

void *func_80132580(s32 arg0, s16 id) {
    struct017 *snd;

    if (D_80155154 == 0) {
        return NULL;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if ((arg0 == snd->unk28) && (id == snd->sndID)) {
            return snd;
        }
    }
    return NULL;
}

// load_sequence_array ?
void func_801325E8(s32 seqArrayIndex, s8 destIndex) {
    s32 offset;
    s16 length;

    if (D_80155154 != 0) {
        offset = D_8028630C->seqArray[seqArrayIndex].offset;
        length = D_8028630C->seqArray[seqArrayIndex].len;

        // align to 2 bytes
        if (length & 1) {
            length += 1;
        }

        osWritebackDCacheAll();
        dma_read(offset, D_80286314[destIndex], length);
    }
}

// get_seqp_state
s32 func_8013266C(s8 arg0) {
    if (D_80155154 == 0) {
        return 0;
    }
    return D_802863C8[arg0]->state;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801326A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801328F8.s")

void func_80132C48(s8 idx) {
    ALSeqPlayer *seqp;

    if (D_80155154 != 0) {
        seqp = D_802863C8[idx];
        if (seqp->state == 0) {
            D_80155168[idx] = 0;
        } else {
            alSeqpStop(seqp);
            D_80155168[idx] = 0;
        }
    }
}
