#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make file for cross-platform compiling
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#     build: compiles all .o file and links them into final ELF file, c1m2.out;
#			 generates .map file and dependecies files
#	  compile-all: compiles all .o files, does not link
#     clean: cleans all generated files
#     <file>.o: creates object file from <file>.c
#     <file>.asm: creates assembly file from <file>.c
#     <file>.d: creates dependecies file from <file>.c
#     <file>.i: creates preprocessed file from <file>.c
#
# Platform Overrides:
#      PLATFORM=HOST: native compiling for UNIX systems
#	   PLATFORM=MSP432: cross-platform compiling for ARM-based platform MSP432 
#
#------------------------------------------------------------------------------
include sources.mk

# Compiler Flags and Defines - defaults to host when no platform is given
PLATFORM=HOST
DEBUG=""
COURSE=""
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES) -D$(PLATFORM)

ifeq ($(DEBUG),VERBOSE)
	CPPFLAGS += -D$(DEBUG)
endif

ifeq ($(COURSE),COURSE1)
	CPPFLAGS += -D$(COURSE)
endif

OUTPUT = c1m2
LDFLAGS = -Wl,--Map=$(OUTPUT).map
CC = gcc
SIZE = size
OBJDUMP = objdump

ifeq ($(PLATFORM),MSP432)
	# Platform specific flags
	CC = arm-none-eabi-gcc
	SOURCES += ./src/interrupts_msp432p401r_gcc.c \
			   ./src/startup_msp432p401r_gcc.c \
			   ./src/system_msp432p401r.c
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
	INCLUDES += -I./include/msp432 -I./include/CMSIS
	LDFLAGS += -T$(LINKER_FILE)
	CFLAGS += -mcpu=$(CPU) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -march=$(ARCH) --specs=$(SPECS)
endif

OBJS:=$(SOURCES:.c=.o)
DEPS:=$(SOURCES:.c=.d)

%.i:%.c
	$(CC) -o $@ -E $(CFLAGS) $(CPPFLAGS) $< 

%.asm:%.c
	$(CC) -o $@ -S $(CFLAGS) $(CPPFLAGS) $< 

%.o:%.c
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $<

%.d:%.c
	$(CC) -o $@ -MM $(CFLAGS) $(CPPFLAGS) $<

$(OUTPUT).asm: $(OUTPUT).out
	$(OBJDUMP) -S $^ >> $@

#compile eveything, do not link
.PHONY: compile-all
compile-all: $(OBJS)

$(OUTPUT).out: $(OBJS)
	$(CC) $^  $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

#compile everything and link -> executable + deps + map file
.PHONY: build
build: $(OUTPUT).out $(DEPS)
	$(SIZE) $<

.PHONY: clean
clean:
	rm -f *~ ./src/*.o *.map *.out ./src/*.asm ./src/*.i ./src/*.d *.asm