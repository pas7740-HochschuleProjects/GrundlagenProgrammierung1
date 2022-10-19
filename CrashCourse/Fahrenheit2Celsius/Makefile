############################################################
# General purpose makefile
#
# Works for all simple C-projects where
# - binaries are compiled into sub-dir bin
# - binaries are created from a single c-source of the same name
#
# Note: multiple targets (binaries) in ./bin are supported
#

# Please add all targets in ./bin here

TARGETS += $(BIN_DIR)/fahrenheit2celsius-V1
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V2
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V3
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V4
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V5
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V5a
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V5b
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V6
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V7
TARGETS += $(BIN_DIR)/doScan
TARGETS += $(BIN_DIR)/fahrenheit2celsius-V2.demo.for

#################################################
# There is no need to edit below this line
#################################################

# Generate debugging symbols?
CFLAGS = -g -Wall
#CFLAGS = -g -Wall -std=c99

#### Fixed variable definitions
CC = gcc
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin

####

all: $(BIN_DIR) $(TARGETS)

#### Fixed build rules
$(BIN_DIR)/% : %.c
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

.PHONY: clean
clean :
	$(RM_DIR) $(BIN_DIR)

