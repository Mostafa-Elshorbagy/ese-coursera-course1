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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk
# Platform Overrides
ifneq ($(PLATFORM),HOST)
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	LINKER_FILE = -T ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	MARCH = armv7e-m
	FLOAT_ABI = hard
	FPU=fpv4-sp-d16
	SPECS = nosys.specs
	ARCHFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=$(MARCH) -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU)

else
	CC = gcc
	SIZE = size
endif


# Compiler Flags and Defines
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=c1m2.map $(LINKER_FILE)
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -D$(PLATFORM) $(INCLUDES) -MD -MP

OBJS = $(SOURCES:.c=.o)
.PHONY: build compile-all clean
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(ARCHFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(ARCHFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(ARCHFLAGS) -o $@
	
build: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(ARCHFLAGS) -o c1m2.out
	$(SIZE) c1m2.out

	 
	

compile-all: $(OBJS)

clean:
	rm -f *.o *.i *.asm *.out *.map *.d c1m2 build
