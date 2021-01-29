#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
# Web UI example by lucianoiam

DPF_CUSTOM_PATH = dpf
DPF_CUSTOM_TARGET_DIR = ../bin
DPF_CUSTOM_BUILD_DIR = ../build
#CEF_PATH = cef

# Keep debug symbols (DPF Makefile.base.mk@148)
SKIP_STRIPPING = true

# --------------------------------------------------------------
# DISTRHO project name, used for binaries

NAME = d_dpf_webui

# --------------------------------------------------------------
# Files to build

SRC_FILES_DSP = \
	WebPlugin.cpp

SRC_FILES_UI  = \
	WebUI.cpp

FILES_DSP = $(SRC_FILES_DSP:%=src/%)
FILES_UI = $(SRC_FILES_UI:%=src/%)

# --------------------------------------------------------------
# Do some magic

UI_TYPE = cairo
include $(DPF_CUSTOM_PATH)/Makefile.plugins.mk

BASE_FLAGS += -Isrc

# --------------------------------------------------------------
# DPF graphics library

dpf_dgl_cairo: $(DPF_CUSTOM_PATH)/build/libdgl-cairo.a

$(DPF_CUSTOM_PATH)/build/libdgl-cairo.a:
	cd $(DPF_CUSTOM_PATH) && make dgl

TARGETS += dpf_dgl_cairo

# --------------------------------------------------------------
# Enable all possible plugin types

ifeq ($(HAVE_JACK),true)
ifeq ($(HAVE_CAIRO),true)
TARGETS += jack
endif
endif

ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_CAIRO),true)
ifeq ($(HAVE_LIBLO),true)
TARGETS += dssi
endif
endif
endif

ifeq ($(HAVE_CAIRO),true)
TARGETS += lv2_sep
else
TARGETS += lv2_dsp
endif

TARGETS += vst

# Include target for linking required files into the output dir
#include Makefile.cef.mk
#TARGETS += link_cef_deps

# CEF headers generate a lot of these
#BASE_FLAGS += -Wno-unused-parameter

#BASE_FLAGS += -Isrc -I$(CEF_PATH)
#LDFLAGS += -Wl,-rpath,. \
#			-lpthread \
#			-lcef -L$(CEF_PATH)/Release \
#			-lcef_dll_wrapper -L$(CEF_PATH)/build/libcef_dll_wrapper

all: $(TARGETS)

# --------------------------------------------------------------
