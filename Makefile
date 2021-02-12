BASENAME  = sssv
VERSION  := us

BUILD_DIR = build
ASM_DIRS  = asm asm/libc asm/libultra asm/libultra/audio asm/libultra/gu asm/libultra/io asm/libultra/os asm/libultra/sched
BIN_DIRS  = bin
SRC_DIR   = src
SRC_DIRS  = $(SRC_DIR) $(SRC_DIR)/core $(SRC_DIR)/sssv

TOOLS_DIR := tools

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
H_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))

RNC_FILES := $(wildcard bin/rnc*.bin)
RNC_EXTRACTED := $(foreach file,$(RNC_FILES),assets/$(file))
RNC_COMPRESSED := $(foreach file,$(RNC_FILES),build/$(file))

TARGET = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT = $(BASENAME).ld

CROSS = mips-linux-gnu-
AS = $(CROSS)as
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3

OBJCOPYFLAGS = -O binary
# --remove-section=.reginfo --remove-section=.MIPS.abiflags --remove-section=.gnu.attributes --remove-section=.options

RNC64 = $(TOOLS_DIR)/rnc_propack_source/rnc64

CC := $(TOOLS_DIR)/ido5.3_recomp/cc

OPT_FLAGS := -O2
MIPSBIT := -mips2 -o32

INCLUDE_CFLAGS := -I . -I include -I include/2.0

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

# Files requiring pre/post-processing
GREP := grep -rl
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))

CFLAGS := -G 0 -Xfullwarn -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul
CFLAGS += -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI
# ignore compiler warnings about anonymous structs
CFLAGS += -woff 649,838
CFLAGS += $(INCLUDE_CFLAGS)

ifeq ($(VERSION),us)
CFLAGS += -DVERSION_US
endif
ifeq ($(VERSION),eu)
CFLAGS += -DVERSION_EU
endif

LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T undefined_syms.$(VERSION).txt --no-check-sections


ASM_PROCESSOR_DIR := $(TOOLS_DIR)/asm-processor

### Optimisation Overrides

$(BUILD_DIR)/$(SRC_DIR)/main_1050.o: OPT_FLAGS := -O1
$(BUILD_DIR)/$(SRC_DIR)/main_4790.o: OPT_FLAGS := -O2 -g3

$(BUILD_DIR)/$(SRC_DIR)/main_7770.o: OPT_FLAGS := -O2

### Targets

default: all

all: dirs $(TARGET).z64 verify

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

tools: $(RNC64)

symlinks:
	ln -nsf asm.$(VERSION) asm
	ln -nsf bin.$(VERSION) bin
	ln -nsf src.$(VERSION) src
	ln -nsf diff_settings.$(VERSION).py diff_settings.py

check: .baserom.$(VERSION).ok

verify: $(TARGET).z64
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $(TARGET).z64" | sha1sum --check

extract: check symlinks
	$(PYTHON) $(TOOLS_DIR)/splat/split.py $(BASENAME).$(VERSION).yaml --rom baserom.$(VERSION).z64 --outdir .

decompress: $(RNC_EXTRACTED)

compress: dirs $(RNC_COMPRESSED)
	# DO NOT REPLACE UNTIL COMPRESSION IS MATCHING
	#cp $(BUILD_DIR)/bin/rnc* bin/

clean:
	rm -rf asm/*
	rm -rf bin/*
	rm -rf build

### Recipes

.baserom.$(VERSION).ok: baserom.$(VERSION).z64
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $<" | sha1sum --check
	@touch $@

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.o: %.c include/functions.$(VERSION).h include/variables.$(VERSION).h include/structs.h
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	$(CC) -c -32 $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s
endif

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

assets/%.bin: %.bin $(RNC64)
	@mkdir -p assets/bin
	$(RNC64) u $< $@ >/dev/null

$(BUILD_DIR)/%.bin: assets/%.bin
	$(TOOLS_DIR)/rnc_propack_source/rnc64 p $< $@ >/dev/null
	@$(PYTHON) $(TOOLS_DIR)/pad.py $@ $@

$(RNC64):
	make -C $(TOOLS_DIR)/rnc_propack_source rnc64

### Settings
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
