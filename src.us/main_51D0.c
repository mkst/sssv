#include <ultra64.h>

#include "common.h"


// first function called after osInitialize
void clear_framebuffer(void) {
    bzero_sssv(gFramebuffer[0], sizeof(gFramebuffer[0]));
    bzero_sssv(gFramebuffer[1], sizeof(gFramebuffer[1]));
}
