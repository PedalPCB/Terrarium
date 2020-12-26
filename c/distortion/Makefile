# Project Name
TARGET = distortion

# Sources
CPP_SOURCES = distortion.cpp

# Library Locations
DAISYSP_DIR ?= ../../../DaisyExamples/DaisySP
LIBDAISY_DIR ?= ../../../DaisyExamples/libdaisy

# Core location, and generic Makefile.
# Overwrite LIBDAISY Environment variable to the location of the lib on your machine.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
CFLAGS += -I../..

