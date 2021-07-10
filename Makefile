BASENAME  = sssv
VERSION  := us

# Directories

BUILD_DIR = build
ASM_DIRS  = asm \
            asm/libc \
            asm/libultra asm/libultra/audio asm/libultra/gu asm/libultra/io asm/libultra/os asm/libultra/sched \
            asm/data asm/data/libultra/audio asm/data/libultra/os asm/data/core asm/data/sssv asm/data/sssv/animals
BIN_DIRS  = assets assets/levels
SRC_DIR   = src.$(VERSION)

SRC_DIRS  = $(SRC_DIR) $(SRC_DIR)/core \
            $(SRC_DIR)/libultra/audio $(SRC_DIR)/libultra/io $(SRC_DIR)/libultra/libc $(SRC_DIR)/libultra/os \
            $(SRC_DIR)/sssv $(SRC_DIR)/sssv/animals \
            $(SRC_DIR)/data

TOOLS_DIR = tools

# Files

S_FILES         = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES         = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
# H_FILES       = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))
BIN_FILES       = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file).o)

# Language data

LANG_RNC_FILES      = $(wildcard assets/lang/*.dat.rnc)
LANG_RNC_O_FILES    = $(foreach file,$(LANG_RNC_FILES),$(BUILD_DIR)/$(file:.dat.rnc=.dat.rnc.o))

# Images

RGBA16_RNC_FILES    = $(shell find assets/img/ -name "*.rgba16.rnc.png" 2> /dev/null)
RGBA16_RNC_O_FILES  = $(foreach file,$(RGBA16_RNC_FILES),$(BUILD_DIR)/$(file:.rgba16.rnc.png=.rgba16.rnc.o))

# TODO: change this to fine command?
RGBA16_FILES        = $(shell find assets/img/ -name "*.rgba16.png" 2> /dev/null)

RGBA16_O_FILES      = $(foreach file,$(RGBA16_FILES),$(BUILD_DIR)/$(file:.png=.png.o))

# Generic RNC compressed files
RNC_FILES       := $(wildcard assets/rnc*.bin)
RNC_EXTRACTED   := $(foreach file,$(RNC_FILES),rnc/$(file))
RNC_COMPRESSED  := $(foreach file,$(RNC_FILES),build/$(file))


# Tools

CROSS    = mips-linux-gnu-

AS       = $(CROSS)as
CPP      = cpp
LD       = $(CROSS)ld
OBJDUMP  = $(CROSS)objdump
OBJCOPY  = $(CROSS)objcopy
PYTHON   = python3

GREP     = grep -rl
CC       = $(TOOLS_DIR)/ido5.3_recomp/cc
RNC64    = $(TOOLS_DIR)/rnc_propack_source/rnc64

# Flags

OPT_FLAGS      = -O2
MIPSISET       = -mips2 -o32

INCLUDE_CFLAGS = -I . -I include -I include/2.0 -I include/2.0/PR -I include/libc -I src.$(VERSION) -I src.$(VERSION)/libultra/os -I src.$(VERSION)/libultra/audio

ASFLAGS        = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include
OBJCOPYFLAGS   = -O binary

# Files requiring pre/post-processing
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null 2>/dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file).o)


CFLAGS := -G 0 -Xfullwarn -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul
CFLAGS += -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI -DWIN32 -DSSSV
# ignore compiler warnings about anonymous structs
CFLAGS += -woff 649,838
CFLAGS += $(INCLUDE_CFLAGS)

ifeq ($(VERSION),us)
CFLAGS += -DVERSION_US
endif
ifeq ($(VERSION),eu)
CFLAGS += -DVERSION_EU
endif

TARGET     = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT  = $(BASENAME).ld

LDFLAGS = -T $(LD_SCRIPT) -Map $(TARGET).map -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T undefined_syms.$(VERSION).txt --no-check-sections


ASM_PROCESSOR_DIR := $(TOOLS_DIR)/asm-processor

### Optimisation Overrides
$(BUILD_DIR)/$(SRC_DIR)/main_1050.c.o: OPT_FLAGS := -O1
# $(BUILD_DIR)/$(SRC_DIR)/main_4790.c.o: OPT_FLAGS := -O2

# libultra
$(BUILD_DIR)/$(SRC_DIR)/libultra/os/%.c.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(SRC_DIR)/libultra/io/%.c.o: OPT_FLAGS := -O1

$(BUILD_DIR)/$(SRC_DIR)/libultra/libc/ll.c.o: MIPSISET := -mips3 -o32
$(BUILD_DIR)/$(SRC_DIR)/libultra/libc/ll.c.o: OPT_FLAGS := -O1

$(BUILD_DIR)/$(SRC_DIR)/libultra/libc/llcvt.c.o: MIPSISET := -mips3 -o32
$(BUILD_DIR)/$(SRC_DIR)/libultra/libc/llcvt.c.o: OPT_FLAGS := -O1

### Targets

default: all

all: dirs $(TARGET).z64 verify

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

tools: $(RNC64)

check: .baserom.$(VERSION).ok

verify: $(TARGET).z64
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $(TARGET).z64" | sha1sum --check

progress: verify progress.csv

extract: check tools
	$(PYTHON) $(TOOLS_DIR)/splat/split.py $(BASENAME).$(VERSION).yaml

decompress: $(RNC_EXTRACTED)

compress: dirs $(RNC_COMPRESSED)
	# DO NOT UNCOMMENT NEXT LINE UNTIL COMPRESSION IS MATCHING
	#cp $(BUILD_DIR)/assets/rnc*.bin assets/

clean:
	rm -rf asm
	rm -rf assets
	rm -rf build
	rm -f *auto.txt


### Recipes

.baserom.$(VERSION).ok: baserom.$(VERSION).z64
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $<" | sha1sum --check
	@touch $@

$(TARGET).elf: $(O_FILES) $(LANG_RNC_O_FILES) $(RGBA16_RNC_O_FILES) $(RGBA16_O_FILES)
	@$(LD) $(LDFLAGS) -o $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.c.o: %.c include/functions.$(VERSION).h include/variables.$(VERSION).h include/structs.h
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	$(CC) -c -32 $(CFLAGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $(BUILD_DIR)/$<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s
endif

# non asm-processor recipe
$(BUILD_DIR)/%.c.o: %.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<

# force mips2 bit
$(BUILD_DIR)/$(SRC_DIR)/libultra/libc/ll.c.o: $(SRC_DIR)/libultra/libc/ll.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
	$(PYTHON) $(TOOLS_DIR)/set_o32abi_bit.py $@

$(BUILD_DIR)/$(SRC_DIR)/libultra/libc/llcvt.c.o: $(SRC_DIR)/libultra/libc/llcvt.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
	$(PYTHON) $(TOOLS_DIR)/set_o32abi_bit.py $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

rnc/%.bin: %.bin
	@mkdir -p rnc/assets
	$(RNC64) u $< $@ >/dev/null

$(BUILD_DIR)/%.bin: rnc/%.bin
	$(TOOLS_DIR)/rnc_propack_source/rnc64 p $< $@ >/dev/null
	@$(PYTHON) $(TOOLS_DIR)/pad.py $@ $@.pad
	@mv $@.pad $@

$(RNC64): $(TOOLS_DIR)/rnc_propack_source/main.c
	make -C $(TOOLS_DIR)/rnc_propack_source rnc64

# language files
%.dat.rnc.json: %.dat.rnc
	@mkdir -p $$(dirname $@)
	$(PYTHON) $(TOOLS_DIR)/lang2json.py $< $@

$(BUILD_DIR)/%.dat: %.dat.rnc.json
	@mkdir -p $$(dirname $@)
	$(PYTHON) $(TOOLS_DIR)/lang2json.py $< $@ --encode

# images
$(BUILD_DIR)/%.rgba16: %.rgba16.rnc.png
	@mkdir -p $$(dirname $@)
	$(PYTHON) $(TOOLS_DIR)/png2rgba16.py $< $@

$(BUILD_DIR)/%.rgba16.png: %.rgba16.png
	@mkdir -p $$(dirname $@)
	$(PYTHON) $(TOOLS_DIR)/png2rgba16.py $< $@

# BUILD_DIR prefix to suppress circular dependency
$(BUILD_DIR)/%.png.o: $(BUILD_DIR)/%.png
	$(LD) -r -b binary -o $@ $<

# rnc compress
%.rnc: %
	$(RNC64) p $< $@ >/dev/null
	@$(PYTHON) $(TOOLS_DIR)/pad.py $@ $@.pad
	@mv $@.pad $@

%.rnc.o: %.rnc
	$(LD) -r -b binary -o $@ $<

# progress
progress.csv: progress.main.csv progress.lib.csv progress.overlay1.csv progress.overlay2.csv
	cat $^ > $@

progress.main.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .main --version $(VERSION) > $@
progress.lib.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .main_lib --version $(VERSION) > $@
progress.overlay1.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .overlay1 --version $(VERSION) > $@
progress.overlay2.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .overlay2 --version $(VERSION) > $@


### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
