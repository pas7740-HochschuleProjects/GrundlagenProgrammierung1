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

TARGETS += $(BIN_DIR)/euklid-V4.0
TARGETS += $(BIN_DIR)/euklid-V4.1
TARGETS += $(BIN_DIR)/euklid-V4.2
TARGETS += $(BIN_DIR)/euklid-V4.3
TARGETS += $(BIN_DIR)/euklid-V4.5
TARGETS += $(BIN_DIR)/euklid-V4.6

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

