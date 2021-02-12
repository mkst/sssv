#ifndef COMMON_H
#define COMMON_H

#define TARGET_N64 1


#define MEME_RETURN(x) \
    if (TARGET_N64) { return x; } else { /* do nothing */ }


#ifdef VERSION_US
#include "common.us.h"
#endif

#ifdef VERSION_EU
#include "common.eu.h"
#endif

#endif
