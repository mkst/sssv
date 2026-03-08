#include <ultra64.h>

#include "common.h"


void load_segments(Gfx **arg0, DisplayList *ddl) {

    gSPSegment((*arg0)++, 0, 0);
    gSPSegment((*arg0)++, 1, osVirtualToPhysical(gSegment1Base));
    gSPSegment((*arg0)++, 2, osVirtualToPhysical(ddl));
    gSPSegment((*arg0)++, 3, osVirtualToPhysical(gFontSegmentBase));
    gSPSegment((*arg0)++, 5, osVirtualToPhysical(gSegment5Base));

    gDPSetDepthImage((*arg0)++, osVirtualToPhysical(&D_80100000));
}

void clear_depth_buffer(Gfx **arg0) {
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 0, 0, gScreenWidth, gScreenHeight);
    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_FILL);
    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(&D_80100000));
    gDPSetFillColor((*arg0)++, 0xFFFCFFFC);
    gDPFillRectangle((*arg0)++, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void init_f3dex_render(Gfx **dl, DisplayList *ddl) {
    gDPPipeSync((*dl)++);
    gSPLoadUcodeEx((*dl)++, &gspF3DEX_fifoTextStart, &gspF3DEX_fifoDataStart, 2048);
    gDPPipeSync((*dl)++);

    load_segments(dl, ddl);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(&D_80100000));

    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPSetColorDither((*dl)++, G_CD_BAYER);
    gDPSetAlphaDither((*dl)++, G_AD_PATTERN);

    gSPClipRatio((*dl)++, FRUSTRATIO_3);
}

void begin_f3dex_render(Gfx **dl, DisplayList *ddl) {
    gDPPipeSync((*dl)++);

    load_segments(dl, ddl);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(&D_80100000));
    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPSetColorDither((*dl)++, G_CD_BAYER);
    gDPSetAlphaDither((*dl)++, G_AD_PATTERN);

    gSPClipRatio((*dl)++, FRUSTRATIO_3);
}

void begin_f3dex_render_sync(Gfx **dl, DisplayList *ddl) {
    gDPPipeSync((*dl)++);
    gDPPipeSync((*dl)++);

    load_segments(dl, ddl);

    gDPSetColorImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(&D_80100000));

    gSPClipRatio((*dl)++, FRUSTRATIO_3);

    gDPSetScissor((*dl)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPSetColorDither((*dl)++, G_CD_BAYER);
    gDPSetAlphaDither((*dl)++, G_AD_PATTERN);
}
