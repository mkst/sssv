#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

char *credits[] = {
    " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
    " ", " ", " ",
    "Executive Producer", "Sam Houser",
    " ", " ",
    "Technical Producer", "Gary J. Foreman",
    " ", " ",
    "Associate Producer", "Ken Jordan",
    " ", " ",
    "Product Manager", "Matt Gorman",
    " ", " ",
    "DMA Development Manager", "Jim Woods",
    " ", " ",
    "QA Supervisor", "Claire Cuthill",
    " ", " ",
    "Lead Programmer", "Leslie Benzies",
    " ", " ",
    "Programmers", "Obbe Vermeij", "Daniel Leyden", "Gordon Speirs",
    " ", " ",
    "Artists", "Aaron Garbut", "Andrew Strachan",
    " ", " ",
    "Editor Programmers", "Barnaby Dellar", "Adam Fowler",
    " ", " ",
    "Level Design", "Craig Filshie", "William Mills",
    " ", " ",
    "Character Design", "Jamie Bryan",
    " ", " ",
    "Additional Artwork", "Robert Jeffrey", "Craig Moore",
    " ", " ",
    "Sound Designer", "Allan Walker",
    " ", " ",
    "Music", "Stuart Ross",
    " ", " ",
    "Sample Trimmer", "Bert Reid",
    " ", " ",
    "Additional Audio Programmer", "Raymond Usher",
    " ", " ",
    "Take 2 QA Department", "Adam Rabin (Lead)", "Nick Sneddon", "Charles Johnstone",
                            "Gary Sims", "Lee Brown", "Julian Hoddy", "Ronnie Jackson",
                            "Michael Wenn", "Chris Lacey", "Nik Huggins", "Greg Mathews",
                            "Edward Hayden",
    " ", " ",
    "DMA QA Department", "Alan Jack",
    " ", " ",
    "Technical Support", "Mark Ettle", "Julian Glendinning", "Kevin Kelly",
    " ", " ",
    "Special Thanks", "Jamie King", "Dan Houser", "Lucien King", "Ian Thomson",
    " ", " ",
    "Splitters", "Andy Hay", "Kenny Mitchell", "Grant Salvona", "Allan Kelly",
    " ", " ",
    "Hygiene Engineer", "Cathy",
    " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
    " ", " ", " ", " ", " ",
    "END",
    " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "
};

// ========================================================
// .bss (D_803F6400 to D_803F6410)
// ========================================================

s16  entryOffset; // credit entry offset
s16  verticalPosition;  // credit vertical position


// ========================================================
// .text
// ========================================================

void reset_credits_counters(void) {
    entryOffset = 0;
    verticalPosition = 0;
}

s32 display_credits(void) {
    s16 i;
    s16 sp90[58];
    u8  sp50[64];

    load_default_display_list(&D_801D9E7C);
    set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
    select_font(0, FONT_COMIC_SANS, 0, 0);

    for (i = 0; i < 16; i++) {
        sprintf((char*)sp50, "%s", credits[i + entryOffset]);
        prepare_text(sp50, sp90);
        if ((sp50[0] == 'E') && (sp50[1] == 'N') && (sp50[2] == 'D')) {
            entryOffset = 0;
            i = 1000; // break
        } else {
            display_text_centered(&D_801D9E7C, sp90, gScreenWidth / 2, verticalPosition + (i * 16), 16.0f, 16.0f);
        }
    }

    verticalPosition -= 1;
    if (verticalPosition == -16) {
        entryOffset += 1;
        verticalPosition = 0;
    }

    if (i > 100) {
        return 1; // credits finished
    } else {
        return 0;
    }
}
