# Project Name
TARGET = DaisyTemplate

# Sources
CPP_SOURCES = src/main.cpp

# Library Locations
LIBDAISY_DIR = lib/libdaisy
DAISYSP_DIR = lib/DaisySP

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

