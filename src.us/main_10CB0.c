#include <ultra64.h>

#include "common.h"


// second function called after osInitialize()
void init2(void) {
    osCreateThread(&gThread1, 1, (void*)thread1, 0, &D_8028D230, 10);
    osStartThread(&gThread1);
}

void thread1(void) {
    osCreateThread(&gThread6, 6, (void *)thread6, 0, &D_80288E30, 10);
    osCreateThread(&gThread7, 7, (void *)thread7, 0, &D_8028B030, 8);
    osCreatePiManager(150, &D_8028D030, &D_8028F640, 800);
    osStartThread(&gThread6);
    // set lowest priority for this thread
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);
    // loop forever
    while (TRUE) {};
}
