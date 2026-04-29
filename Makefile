SHELL     = /bin/bash -e -o pipefail

BASENAME := sssv
VERSION  := us

COMPILER ?= ido

NON_MATCHING ?= 0
USE_GCC      ?= 0
CRASH_SCREEN ?= 0

# Colors

NO_COL  := \033[0m
RED     := \033[0;31m
RED2    := \033[1;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
PINK    := \033[0;35m
CYAN    := \033[0;36m

# Directories

BUILD_DIR := build
SRC_DIR   := src.$(VERSION)

TOOLS_DIR := tools

# Files

TARGET     = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT  = $(BASENAME).ld

LIBULTRA   = lib/libultra_rom.a
LIBGCC     = lib/libgcc.a

# Scrape linker script to determine what we need
ld_objs = $(shell sed -nE 's#.*(build/.*\.$(1)\.o).*#\1#p' $(LD_SCRIPT) 2>/dev/null)

# Source
ASM_OBJS        := $(call ld_objs,s)
C_OBJS          := $(call ld_objs,c)

# Binaries
BIN_OBJS        := $(call ld_objs,bin)
RNC_OBJS        := $(call ld_objs,rnc)

# Images
RGBA16_OBJS     := $(call ld_objs,rgba16.png)
I4_OBJS         := $(call ld_objs,i4.png)
I8_OBJS         := $(call ld_objs,i8.png)
IA16_OBJS       := $(call ld_objs,ia16.png)
CI4_OBJS        := $(call ld_objs,ci4.png)
CI4_PAL_OBJS    := $(call ld_objs,pal)
CI4_PAL_OBJS    += $(CI4_OBJS:.ci4.png.o=.pal.o)

ALL_IMAGE_OBJS  := $(RGBA16_OBJS) $(I4_OBJS) $(I8_OBJS) $(IA16_OBJS) $(CI4_OBJS) $(CI4_PAL_OBJS)

# Generic RNC compressed files
ALL_RNC_FILES      := $(wildcard assets/rnc*.bin) $(wildcard assets/levels/*.bin)
ALL_RNC_EXTRACTED  := $(foreach file,$(ALL_RNC_FILES),rnc/$(file))
ALL_RNC_COMPRESSED := $(foreach file,$(ALL_RNC_FILES),build/$(file))


# Compiler tooling

find-command = $(shell which $(1) 2>/dev/null)

IDO      = $(TOOLS_DIR)/ido5.3_recomp/cc

CROSS    = mips-linux-gnu-

AS       = $(CROSS)as
CPP      = cpp
LD       = $(CROSS)ld
OBJCOPY  = $(CROSS)objcopy
PYTHON   = python3
GCC      = gcc

XGCC     = $(CROSS)gcc

# prefer clang as CC_CHECK
ifneq (,$(call find-command,clang))
  HOSTCC = clang
  HOSTCC_CHECK_FLAGS = --target=i686-linux-gnu
else
  HOSTCC = gcc
  HOSTCC_CHECK_FLAGS = -m32
endif

# prefer modern gcc for data, but fall back to IDO if not available
ifneq (,$(call find-command,$(CROSS)gcc))
  DCC        = $(XGCC)
  DCC_CFLAGS = $(GCC_FLAGS)
else
  DCC        = $(CC)
  DCC_CFLAGS = $(CFLAGS)
endif

IDO_CFLAGS  = $(INCLUDE_CFLAGS) $(DEFINES)
IDO_CFLAGS += -G0 -mips2 -32 -Xfullwarn -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul -woff 649,838,807

ifeq ($(COMPILER),ido)
  CC = $(IDO)
  CFLAGS = $(IDO_CFLAGS)
else
  CC = $(XGCC)
  CFLAGS = $(GCC_FLAGS)
  NON_MATCHING = 1
endif

MAYBE_LIBGCC =
GCC_C_FILES =
GCC_C_OBJS =

ifeq ($(USE_GCC),1)
  GCC_C_FILES  = $(shell [ -f gcc_files.$(VERSION).txt ] && sed -e 's/#.*//' -e '/^[[:space:]]*$$/d' gcc_files.$(VERSION).txt)
  GCC_C_OBJS   = $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(GCC_C_FILES)))
  $(GCC_C_OBJS): CC = $(XGCC)
  $(GCC_C_OBJS): CFLAGS = $(GCC_FLAGS)
  $(GCC_C_OBJS): OPT_FLAGS = -O2
  ifneq ($(strip $(GCC_C_FILES)),)
	NON_MATCHING = 1
	LD_FLAGS_EXTRA += -lgcc
	MAYBE_LIBGCC = $(BUILD_DIR)/$(LIBGCC)
  endif
endif

# COMPILER=gcc
ifeq ($(COMPILER),gcc)
  OPT_FLAGS = -O2
  LD_FLAGS_EXTRA += -lgcc
  MAYBE_LIBGCC = $(BUILD_DIR)/$(LIBGCC)
endif

# Tools

GREP     = grep
RNC64    = $(TOOLS_DIR)/rnc_propack_source/rnc64
RNCU     = $(PYTHON) $(TOOLS_DIR)/rncu.py
SPLAT    = $(TOOLS_DIR)/splat/split.py
N64CRC   = $(TOOLS_DIR)/n64crc.py

IMG_CONVERT = $(PYTHON) $(TOOLS_DIR)/image_converter.py

LIBRNCU  = $(TOOLS_DIR)/librncu.so

# Flags

OPT_FLAGS     ?= -O2
LOOP_UNROLL    =

INCLUDE_CFLAGS = -I . -I include -I include/2.0 -I include/2.0/PR -I include/libc -I assets \
                 -I src.$(VERSION) -I src.$(VERSION)/libultra/audio

ASFLAGS        = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include
OBJCOPYFLAGS   = -O binary

# Files requiring pre/post-processing
GLOBAL_ASM_C_FILES := $(shell $(GREP) -Rl GLOBAL_ASM $(SRC_DIR) </dev/null 2>/dev/null)
GLOBAL_ASM_OBJS := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file).o)


DEFINES := -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI -DWIN32 -DSSSV -DNDEBUG

ifeq ($(VERSION),us)
  DEFINES += -DVERSION_US
endif
ifeq ($(VERSION),eu)
  DEFINES += -DVERSION_EU
endif

VERIFY = verify

$(info $(VERIFY) - $(NON_MATCHING))

ifeq ($(NON_MATCHING),1)
  $(info Building NON_MATCHING ROM...)
  DEFINES += -DNON_MATCHING -DAVOID_UB -DBUGFIX -DENABLE_CHEATS
  VERIFY = no_verify
  PROGRESS_NONMATCHING = --non-matching
endif

ifeq ($(CRASH_SCREEN),1)
  C_OBJS += build/src.us/debug/crash_screen.c.o
endif


CHECK_WARNINGS := -Wall -Wextra -Wno-format-security -Wno-unknown-pragmas -Wno-unused-parameter -Wno-unused-variable -Wno-missing-braces -Wno-int-conversion
# CHECK_WARNINGS += -Wdouble-promotion
CC_CHECK   = $(HOSTCC) $(HOSTCC_CHECK_FLAGS) -fsyntax-only -fno-builtin -fsigned-char -std=gnu90 $(CHECK_WARNINGS) $(INCLUDE_CFLAGS) $(DEFINES)

GCC_FLAGS  = $(INCLUDE_CFLAGS) $(DEFINES)
GCC_FLAGS += -G0 -mips3 -std=gnu90
GCC_FLAGS += -mno-shared -march=vr4300 -mfix4300 -mabi=32 -mhard-float -mdivide-breaks -mno-abicalls
GCC_FLAGS += -fno-builtin -fsigned-char -fno-stack-protector -fno-common -fno-zero-initialized-in-bss -fno-PIC -fno-inline-functions -ffreestanding -fno-strict-aliasing -fwrapv
GCC_FLAGS += $(CHECK_WARNINGS)

LD_FLAGS   = -T $(LD_SCRIPT) -Map $(TARGET).map --no-check-sections

ifeq ($(VERSION),eu)
  LD_FLAGS  +=  -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt
endif

ifeq ($(VERSION),us)
  LD_FLAGS_EXTRA  = -Lbuild/lib -lultra_rom
  # NOTE: this function is not included unless explicitly undefined
  LD_FLAGS_EXTRA += -u osViGetCurrentLine
else
  LD_FLAGS_EXTRA  =
endif

ASM_PROCESSOR_DIR := $(TOOLS_DIR)/asm-processor
ASM_PROCESSOR      = $(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py

### Optimisation Overrides
$(BUILD_DIR)/$(SRC_DIR)/main_1050.c.o: OPT_FLAGS := -O1

ifeq ($(NON_MATCHING),0)
ifeq ($(COMPILER),ido)
  $(BUILD_DIR)/$(SRC_DIR)/overlay2_6AB090.c.o: LOOP_UNROLL := -Wo,-loopunroll,0
endif
endif

### EU Overrides
$(BUILD_DIR)/src.eu/overlay1%.c.o: OPT_FLAGS := -g

### Targets

all: $(VERIFY)

tools: $(RNC64) $(LIBRNCU)

verify: $(TARGET).z64
	@sha1sum --check $(BASENAME).$(VERSION).sha1

no_verify: $(TARGET).z64
	@echo "Skipping SHA1SUM check, updating CRC"
	@$(PYTHON) $(N64CRC) $(TARGET).z64

progress: dirs $(VERIFY) progress.csv

extract: $(SPLAT) tools
	$(PYTHON) $(SPLAT) $(BASENAME).$(VERSION).yaml
	@$(PYTHON) $(TOOLS_DIR)/fixup_tlut.py

decompress: $(ALL_RNC_EXTRACTED)

compress: dirs $(ALL_RNC_COMPRESSED)
	# DO NOT UNCOMMENT NEXT LINE UNTIL COMPRESSION IS MATCHING
	#cp $(BUILD_DIR)/assets/rnc*.bin assets/

clean:
	rm -rf build

distclean: clean
	rm -rf asm
	rm -rf assets
	rm -f *auto.txt
	rm -f src.us/data/inc/*


### Recipes

$(TARGET).elf: $(BASENAME).ld $(BUILD_DIR)/$(LIBULTRA) $(ASM_OBJS) $(BIN_OBJS) $(C_OBJS) $(ALL_IMAGE_OBJS) $(RNC_OBJS) $(MAYBE_LIBGCC)
	@mkdir -p $$(dirname $@)
	@$(LD) $(LD_FLAGS) $(LD_FLAGS_EXTRA) -o $@
	@printf "[$(PINK) linker $(NO_COL)]  $<\n"

ifndef PERMUTER
$(GLOBAL_ASM_OBJS): $(BUILD_DIR)/%.c.o: %.c include/functions.$(VERSION).h include/variables.$(VERSION).h include/structs.h
	@mkdir -p $$(dirname $@)
	@$(CC_CHECK) $<
	@printf "[$(YELLOW) syntax $(NO_COL)] $<\n"
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	@$(IDO) -c $(IDO_CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) -o $@ $(BUILD_DIR)/$<
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.inc
	@printf "[$(GREEN) ido5.3 $(NO_COL)]  $<\n"
endif

# non asm-processor recipe
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $$(dirname $@)
	@$(CC_CHECK) $<
	@printf "[$(YELLOW) syntax $(NO_COL)]  $<\n"
	@$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) -o $@ $<
	@printf "[$(GREEN)   cc   $(NO_COL)]  $<\n"

# use modern gcc or IDO for data
$(BUILD_DIR)/$(SRC_DIR)/data/%.c.o: $(SRC_DIR)/data/%.c
	@mkdir -p $$(dirname $@)
	@$(DCC) -c $(DCC_CFLAGS) -o $@ $<
	@printf "[$(GREEN)  data  $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $$(dirname $@)
	@$(AS) $(ASFLAGS) -o $@ $<
	@printf "[$(GREEN)   as   $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.bin.o: %.bin
	@mkdir -p $$(dirname $@)
	@$(LD) -r -b binary -o $@ $<
	@printf "[$(PINK) linker $(NO_COL)]  $<\n"

$(TARGET).bin: $(TARGET).elf
	@mkdir -p $$(dirname $@)
	@$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
	@printf "[$(CYAN) objcpy $(NO_COL)]  $<\n"

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

$(BUILD_DIR)/$(LIBULTRA): $(LIBULTRA)
	@mkdir -p $$(dirname $@)
	@cp $< $@
	@$(PYTHON) $(TOOLS_DIR)/set_o32abi_bit.py --quiet $@

$(BUILD_DIR)/%.a: %.a
	@mkdir -p $$(dirname $@)
	@cp $< $@

rnc/%.bin: %.bin
	@mkdir -p rnc/assets/levels
	@$(RNCU) $< $@
	@printf "[$(RED) rnc u. $(NO_COL)]  $<\n"

$(RNC64): $(TOOLS_DIR)/rnc_propack_source/main.c
	make -C $(TOOLS_DIR)/rnc_propack_source rnc64

$(LIBRNCU): $(TOOLS_DIR)/rncu.c
	$(HOSTCC) -o $@ $< --shared -O3 -fPIC

# language files
%.dat.rnc.json: %.dat.rnc
	@mkdir -p $$(dirname $@)
	@$(PYTHON) $(TOOLS_DIR)/lang2json.py $< $@
	@printf "[$(YELLOW)  lang  $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.dat: %.dat.rnc.json
	@mkdir -p $$(dirname $@)
	@$(PYTHON) $(TOOLS_DIR)/lang2json.py $< $@ --encode
	@printf "[$(RED2)  lang  $(NO_COL)]  $<\n"

# compressed images
$(BUILD_DIR)/%.rgba16: %.rgba16.rnc.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) rgba16 $< $@
	@printf "[$(GREEN) rgba16 $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.i4: %.i4.rnc.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) i4 $< $@
	@printf "[$(GREEN)   i4   $(NO_COL)]  $<\n"

# uncompressed images
$(BUILD_DIR)/%.rgba16.png: %.rgba16.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) rgba16 $< $@
	@printf "[$(GREEN) rgba16 $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.i4.png: %.i4.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) i4 $< $@
	@printf "[$(GREEN)   i4   $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.i8.png: %.i8.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) i8 $< $@
	@printf "[$(GREEN)   i8   $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.ia16.png: %.ia16.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) ia16 $< $@
	@printf "[$(GREEN)  ia16  $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.ci4.png: %.ci4.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) ci4 $< $@
	@printf "[$(GREEN)  ci4   $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.pal: %.ci4.png
	@mkdir -p $$(dirname $@)
	@$(IMG_CONVERT) palette $< $@
	@printf "[$(GREEN)  pal   $(NO_COL)]  $<\n"

# BUILD_DIR prefix to suppress circular dependency
$(BUILD_DIR)/%.png.o: $(BUILD_DIR)/%.png
	@$(LD) -r -b binary -o $@ $<
	@printf "[$(PINK) linker $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.pal.o: $(BUILD_DIR)/%.pal
	@$(LD) -r -b binary -o $@ $<
	@printf "[$(PINK) linker $(NO_COL)]  $<\n"

# rnc compress
%.rnc: %
	@$(RNC64) p $< $@ /f >/dev/null
	@$(PYTHON) $(TOOLS_DIR)/pad.py $@ $@.pad
	@mv $@.pad $@
	@printf "[$(RED) rnc p. $(NO_COL)]  $<\n"

$(BUILD_DIR)/%.collision.rnc: %.collision.rnc
	@$(RNC64) p $< $@ /f >/dev/null
	@$(PYTHON) $(TOOLS_DIR)/pad.py $@ $@.pad
	@mv $@.pad $@
	@printf "[$(RED) rnc p. $(NO_COL)]  $<\n"

%.rnc.o: %.rnc
	@$(LD) -r -b binary -o $@ $<
	@printf "[$(PINK) linker $(NO_COL)]  $<\n"

# progress
progress.csv: progress.main.csv progress.lib.csv progress.overlay1.csv progress.overlay2.csv
	@awk "(NR == 1) || (FNR > 1)" $^ > $@

progress.main.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map _mainSegmentTextStart main_libultra_start_OFFSET main --version $(VERSION) $(PROGRESS_NONMATCHING) > $@
progress.lib.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map main_libultra_start_OFFSET _mainSegmentTextEnd lib --version $(VERSION) $(PROGRESS_NONMATCHING) > $@
progress.overlay1.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map _overlay1SegmentTextStart _overlay1SegmentTextEnd overlay1 --version $(VERSION) $(PROGRESS_NONMATCHING) > $@
progress.overlay2.csv: $(TARGET).elf
	$(PYTHON) $(TOOLS_DIR)/progress.py . $(TARGET).map _overlay2SegmentTextStart _overlay2SegmentTextEnd overlay2 --version $(VERSION) $(PROGRESS_NONMATCHING) > $@

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
.PHONY: all clean extract progress verify
.INTERMEDIATE: progress.main.csv progress.lib.csv progress.overlay1.csv progress.overlay2.csv
.DEFAULT_GOAL := all
