Need to add this to the sssv.ld

```
    crash_screen : {
        build/src.us/debug/crash_screen.c.o(.text .data .rodata .bss);
        build/lib/libultra_rom.a:getcurrfaultthread.o(.text);
        build/lib/libultra_rom.a:settime.o(.text)
    }
```
