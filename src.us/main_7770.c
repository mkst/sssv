#include <ultra64.h>

#include "common.h"

void load_overlay(u8 id) {
    s32 pad;

    stop_all_sounds();

    switch (id) {
    case 0:
        osInvalICache(_overlay2SegmentTextStart, _overlay2SegmentTextEnd - _overlay2SegmentTextStart);
        if (id == 0) {};
        osInvalDCache(_overlay2SegmentDataStart, _overlay2SegmentRoDataEnd - _overlay2SegmentDataStart);
        dma_read(_overlay2SegmentRomStart, func_80294E50_6A6500, _overlay2SegmentRomEnd - _overlay2SegmentRomStart);
        bzero(_overlay2SegmentBssStart, _overlay2SegmentBssEnd - _overlay2SegmentBssStart);
        break;
    case 1:
        osInvalICache(_overlay1SegmentTextStart, _overlay1SegmentTextEnd - _overlay1SegmentTextStart);
        if (id == 0) {};
        osInvalDCache(_overlay1SegmentDataStart, _overlay1SegmentRoDataEnd - _overlay1SegmentDataStart);
        dma_read(_overlay1SegmentRomStart, func_80294E50_6384F0, _overlay1SegmentRomEnd - _overlay1SegmentRomStart);
        bzero(_overlay1SegmentBssStart, _overlay1SegmentBssEnd - _overlay1SegmentBssStart);
        break;
    }

    if ((!pad) && (!pad)) {};
}
