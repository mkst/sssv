When building SSSV with the crash screen, you will need to add this towards the end of the sssv.us.ld

```c
    crash_screen : {
        build/src.us/debug/crash_screen.c.o(.text .data .rodata .bss);
        build/lib/libultra_rom.a:getcurrfaultthread.o(.text);
        build/lib/libultra_rom.a:settime.o(.text)
    }
```
