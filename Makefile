BASENAME  = sssv
VERSION  := us

# Directories

BUILD_DIR = build
ASM_DIRS  = asm \
            asm/libc \
            asm/libultra/audio \
            asm/data asm/data/libultra/audio asm/data/core asm/data/sssv asm/data/sssv/animals
BIN_DIRS  = assets assets/levels
SRC_DIR   = src.$(VERSION)

SRC_DIRS  = $(SRC_DIR) $(SRC_DIR)/core \
            $(SRC_DIR)/libultra/audio $(SRC_DIR)/libultra/libc \
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

LIBULTRA = lib/libultra_rom.a

# Language data

LANG_RNC_FILES      = $(wildcard assets/lang/*.dat.rnc)
LANG_RNC_O_FILES    = $(foreach file,$(LANG_RNC_FILES),$(BUILD_DIR)/$(file:.dat.rnc=.dat.rnc.o))

# Images

RGBA16_RNC_FILES    = $(shell find assets/img/ -name "*.rgba16.rnc.png" 2> /dev/null)
RGBA16_RNC_O_FILES  = $(foreach file,$(RGBA16_RNC_FILES),$(BUILD_DIR)/$(file:.rgba16.rnc.png=.rgba16.rnc.o))

# TODO: change this to find command?
RGBA16_FILES        = $(shell find assets/img/ -name "*.rgba16.png" 2> /dev/null)

RGBA16_O_FILES      = $(foreach file,$(RGBA16_FILES),$(BUILD_DIR)/$(file:.png=.png.o))

# Generic RNC compressed files
RNC_FILES       := $(wildcard assets/rnc*.bin) $(wildcard assets/levels/*.bin)
RNC_EXTRACTED   := $(foreach file,$(RNC_FILES),rnc/$(file))
RNC_COMPRESSED  := $(foreach file,$(RNC_FILES),build/$(file))

# function is not included unless explicitly undefined
UNDEFINED_SYMS  := osViGetCurrentLine

# Tools

CROSS    = mips-elf-

AS       = $(CROSS)as
CPP      = cpp
LD       = $(CROSS)ld
OBJDUMP  = $(CROSS)objdump
OBJCOPY  = $(CROSS)objcopy
PYTHON   = python3
GCC      = gcc

XGCC     = mips-linux-gnu-gcc

GREP     = grep -rl
CC       = $(TOOLS_DIR)/ido5.3_recomp/cc
RNC64    = $(TOOLS_DIR)/rnc_propack_source/rnc64
SPLAT    = $(TOOLS_DIR)/splat/split.py

# Flags

OPT_FLAGS      = -O2
LOOP_UNROLL    =

MIPSISET       = -mips2 -32

INCLUDE_CFLAGS = -I . -I include -I include/2.0 -I include/2.0/PR -I include/libc -I assets \
                 -I src.$(VERSION) -I src.$(VERSION)/libultra/os -I src.$(VERSION)/libultra/audio

ASFLAGS        = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include
OBJCOPYFLAGS   = -O binary

# Files requiring pre/post-processing
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null 2>/dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file).o)


DEFINES := -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI -DWIN32 -DSSSV -DNDEBUG

ifeq ($(VERSION),us)
DEFINES += -DVERSION_US
endif
ifeq ($(VERSION),eu)
DEFINES += -DVERSION_EU
endif

VERIFY = verify

ifeq ($(NON_MATCHING),1)
DEFINES += -DNON_MATCHING
VERIFY = no_verify
PROGRESS_NONMATCHING = --non-matching
endif

CFLAGS := -G 0 -Xfullwarn -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul
CFLAGS += $(DEFINES)
# ignore compiler warnings about anonymous structs
CFLAGS += -woff 649,838
CFLAGS += $(INCLUDE_CFLAGS)

CHECK_WARNINGS := -Wall -Wextra -Wno-format-security -Wno-unknown-pragmas -Wno-unused-parameter -Wno-unused-variable -Wno-missing-braces -Wno-int-conversion
CC_CHECK := $(GCC) -fsyntax-only -fno-builtin -fsigned-char -std=gnu90 -m32 $(CHECK_WARNINGS) $(INCLUDE_CFLAGS) $(DEFINES)

GCC_FLAGS := $(INCLUDE_CFLAGS) $(DEFINES)
GCC_FLAGS += -G 0 -mno-shared -march=vr4300 -mfix4300 -mabi=32 -mhard-float
GCC_FLAGS += -mdivide-breaks -fno-stack-protector -fno-common -fno-zero-initialized-in-bss -fno-PIC -mno-abicalls -fno-strict-aliasing -fno-inline-functions -ffreestanding -fwrapv
GCC_FLAGS += -Wall -Wextra -Wno-missing-braces

TARGET     = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT  = $(BASENAME).ld

LD_FLAGS   = -T $(LD_SCRIPT) -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt
LD_FLAGS  += -Map $(TARGET).map --no-check-sections

LD_FLAGS_EXTRA  = -Lbuild/lib -lultra_rom
LD_FLAGS_EXTRA += $(foreach sym,$(UNDEFINED_SYMS),-u $(sym))

ASM_PROCESSOR_DIR := $(TOOLS_DIR)/asm-processor

### Optimisation Overrides
$(BUILD_DIR)/$(SRC_DIR)/main_1050.c.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(SRC_DIR)/core/string.c.o: OPT_FLAGS := -O2
# $(BUILD_DIR)/$(SRC_DIR)/core/eeprom.c.o: OPT_FLAGS := -O2

$(BUILD_DIR)/$(SRC_DIR)/overlay2_6AB090.c.o: LOOP_UNROLL := -Wo,-loopunroll,0


### Targets

default: all

all: dirs $(VERIFY)

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

tools: $(RNC64)

check: .baserom.$(VERSION).ok

verify: $(TARGET).z64
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $(TARGET).z64" | sha1sum --check

no_verify: $(TARGET).z64
	@echo "Skipping SHA1SUM check!"

progress: dirs $(VERIFY) progress.csv

splat: $(SPLAT)

extract: splat check tools
	$(PYTHON) $(SPLAT) $(BASENAME).$(VERSION).yaml

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

$(TARGET).elf: $(BASENAME).ld $(BUILD_DIR)/$(LIBULTRA) $(O_FILES) $(LANG_RNC_O_FILES) $(RGBA16_RNC_O_FILES) $(RGBA16_O_FILES)
	$(LD) $(LD_FLAGS) $(LD_FLAGS_EXTRA) -o $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.c.o: %.c include/functions.$(VERSION).h include/variables.$(VERSION).h include/structs.h
	$(CC_CHECK) $<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	$(CC) -c -32 $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSISET) -o $@ $(BUILD_DIR)/$<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s
endif

# non asm-processor recipe
$(BUILD_DIR)/%.c.o: %.c
	$(CC_CHECK) $<
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSISET) -o $@ $<

# use modern gcc for data
$(BUILD_DIR)/$(SRC_DIR)/data/%.c.o: $(SRC_DIR)/data/%.c
	$(XGCC) -c $(GCC_FLAGS) -o $@ $<

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

$(BUILD_DIR)/$(LIBULTRA): $(LIBULTRA)
	@mkdir -p $$(dirname $@)
	@cp $< $@
	$(PYTHON) $(TOOLS_DIR)/set_o32abi_bit.py $@

rnc/%.bin: %.bin
	@mkdir -p rnc/assets/levels
	$(RNC64) u $< $@ >/dev/null

$(BUILD_DIR)/%.bin: rnc/%.bin
	$(RNC64) p $< $@ /f >/dev/null
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
	$(RNC64) p $< $@ /f >/dev/null
	@$(PYTHON) $(TOOLS_DIR)/pad.py $@ $@.pad
	@mv $@.pad $@

%.rnc.o: %.rnc
	$(LD) -r -b binary -o $@ $<

# progress
progress.csv: progress.main.csv progress.lib.csv progress.overlay1.csv progress.overlay2.csv
	cat $^ > $@

progress.main.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .main --version $(VERSION) $(PROGRESS_NONMATCHING) > $@
progress.lib.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .main_lib --version $(VERSION) $(PROGRESS_NONMATCHING) > $@
progress.overlay1.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .overlay1 --version $(VERSION) $(PROGRESS_NONMATCHING) > $@
progress.overlay2.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map .overlay2 --version $(VERSION) $(PROGRESS_NONMATCHING) > $@

# fake targets for better error handling
$(SPLAT):
	$(info Repo cloned without submodules, attempting to fetch them now...)
	@which git >/dev/null || echo "ERROR: git binary not found on PATH"
	@which git >/dev/null
	git submodule update --init --recursive

baserom.$(VERSION).z64:
	$(error Place the SSSV ROM, named '$@', in the root of this repo and try again.)

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
