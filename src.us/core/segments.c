#include <ultra64.h>
#include "common.h"


void load_segments(Gfx **dl, DisplayList *ddl) {
    gSPSegment((*dl)++, 0, 0);
    gSPSegment((*dl)++, 1, osVirtualToPhysical(gSegment1Base));
    gSPSegment((*dl)++, 2, osVirtualToPhysical(ddl));
    gSPSegment((*dl)++, 3, osVirtualToPhysical(gFontSegmentBase));
    gSPSegment((*dl)++, 5, osVirtualToPhysical(gSegment5Base));

    gDPSetDepthImage((*dl)++, osVirtualToPhysical(D_80100000));
}

void clear_depth_buffer(Gfx **dl) {
    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_FILL);
    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80100000));
    gDPSetFillColor((*dl)++, 0xFFFCFFFC);
    gDPFillRectangle((*dl)++, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void init_f3dex_render(Gfx **dl, DisplayList *ddl) {
    gDPPipeSync((*dl)++);
    gSPLoadUcodeEx((*dl)++, &gspF3DEX_fifoTextStart, &gspF3DEX_fifoDataStart, 2048);
    gDPPipeSync((*dl)++);

    load_segments(dl, ddl);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80100000));

    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPSetColorDither((*dl)++, G_CD_BAYER);
    gDPSetAlphaDither((*dl)++, G_AD_PATTERN);

    gSPClipRatio((*dl)++, FRUSTRATIO_3);
}

void begin_f3dex_render(Gfx **dl, DisplayList *ddl) {
    gDPPipeSync((*dl)++);

    load_segments(dl, ddl);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80100000));
    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPSetColorDither((*dl)++, G_CD_BAYER);
    gDPSetAlphaDither((*dl)++, G_AD_PATTERN);

    gSPClipRatio((*dl)++, FRUSTRATIO_3);
}

void begin_f3dex_render_sync(Gfx **dl, DisplayList *ddl) {
    gDPPipeSync((*dl)++);
    gDPPipeSync((*dl)++);

    load_segments(dl, ddl);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80100000));

    gSPClipRatio((*dl)++, FRUSTRATIO_3);

    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPSetColorDither((*dl)++, G_CD_BAYER);
    gDPSetAlphaDither((*dl)++, G_AD_PATTERN);
}
