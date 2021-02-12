#include <ultra64.h>
#include "common.h"


void func_80131AA0(void);
void func_80131554(s32 arg0);

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
//     osCreateThread(&D_8023F428, 3, &func_80131554, 0, &D_80241758, priority);
//     osStartThread(&D_8023F428);
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
//     if (0) {};
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
//         switch (mesg->unk0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801318C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80131BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801320EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801322EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801323B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801325E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_8013266C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801326A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801328F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132C48.s")
