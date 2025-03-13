#include <ultra64.h>
#include "common.h"

// ========================================================
// .bss
// ========================================================

OSThread    gThread6; // 0x80286570 (0x80286570)
OSThread    gThread7; // 0x80286720
OSThread    gThread1; // 0x802868D0 (idle after init)
OSThread    gThread9; // 0x80286A80

u64         thread6_stack[0x440];
u64         thread7_stack[0x440];

static u64  D_8028B030[0x400];  // unused?

OSMesgQueue D_8028D030;
OSMesgQueue D_8028D048;
OSMesgQueue D_8028D060;
OSMesgQueue D_8028D078;
OSMesgQueue D_8028D090;
OSMesgQueue D_8028D0A8; // OS_EVENT_SI events
OSIoMesg    D_8028D0C0; // single?

u64         thread1_stack[43]; // weird size? could add some padding before?

u64         thread9_stack[512]; // thread9_stack

u64         D_8028E230[642]; // unused maybe 640 + padding? TODO: make static

OSMesg      D_8028F640[800]; // cmdBuf for osCreatePiManager

OSMesg      D_802902C0[800];
OSMesg      D_80290F40[34]; // 32 + spare padding?
OSMesg      D_80290FC8[32];
OSMesg      D_80291048[1];
OSMesg      D_8029104C[1];

static OSMesg D_80291050[1]; // unused

OSMesg     *D_80291054;
OSMesg      D_80291058[1];
OSMesg      D_8029105C[1];
OSMesgQueue D_80291060;
OSMesgQueue D_80291078;


// ========================================================
// .text
// ========================================================

// second function called after osInitialize()
void init2(void) {
    osCreateThread(&gThread1, 1, (void*)thread1, NULL, &thread1_stack[sizeof(thread1_stack) / sizeof(u64)], 10);
    osStartThread(&gThread1);
}

void thread1(void) {
    osCreateThread(&gThread6, 6, (void *)thread6, NULL, &thread6_stack[sizeof(thread6_stack) / sizeof(u64)], 10);
    osCreateThread(&gThread7, 7, (void *)thread7, NULL, &thread7_stack[sizeof(thread7_stack) / sizeof(u64)], 8);
    osCreatePiManager(150, &D_8028D030, D_8028F640, 800);
    osStartThread(&gThread6);
    // set lowest priority for this thread
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);
    // loop forever
    while (TRUE) {};
}
