#include <ultra64.h>

#include "common.h"


// load 32 bytes from offset 0x20 of the header
void read_rom_header(void) {
    dma_read(32, &D_80204240, 32);
}

void set_region(void) {
    switch (D_80204240.countryCode) {
        case 'J': // Japan
            D_80204240.mode = 0;
            break;
        case 'P': // European
            D_80204240.mode = 1;
            break;
        case 'E': // North America
            D_80204240.mode = 2;
            break;
        default:
            D_80204240.mode = 1;
            break;
    }
}

void dma_read(u32 devAddr, void *vAddr, s32 nbytes) {
    s32 mesg;

    osWritebackDCacheAll();
    osPiStartDma(&D_8028D0C0, 0, 0, devAddr, vAddr, nbytes, &D_8028D078);
    osRecvMesg(&D_8028D078, (OSMesg)&mesg, OS_MESG_BLOCK);
}
