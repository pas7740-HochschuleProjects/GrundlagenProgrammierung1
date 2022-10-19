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

TARGETS += $(BIN_DIR)/sizeOfPrimitiveDatatypes
TARGETS += $(BIN_DIR)/sizeOfArray
TARGETS += $(BIN_DIR)/sizeOfStruct
TARGETS += $(BIN_DIR)/sizeOfExpression
TARGETS += $(BIN_DIR)/sizeOfPointer

#################################################
# There is no need to edit below this line
#################################################

# Generate debugging symbols?
CFLAGS = -g -Wall

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

