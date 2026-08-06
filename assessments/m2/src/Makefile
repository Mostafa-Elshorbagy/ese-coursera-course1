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
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
MARCH = armv7e-m
FLOAT_ABI = hard
FPU=fpv4-sp-d16
SPECS = nosys.specs

# Compiler Flags and Defines
ifneq ($(PLATFORM),HOST)
	CC = arm-none-eabi-gcc
else
	CC = gcc
LD = arm-none-eabi-ld
LDFLAGS = 
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=$(MARCH) -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU)
CPPFLAGS = 

