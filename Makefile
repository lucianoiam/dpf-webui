#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
# CEF support by lucianoiam

DPF_CUSTOM_PATH = ../DPF
DPF_CUSTOM_TARGET_DIR = bin
DPF_CUSTOM_BUILD_DIR = build

# --------------------------------------------------------------
# Chromium Embedded Framework, see include at the end
# https://github.com/lucianoiam/cef-boilerplate

CEF_BOILERPLATE_PATH = ../cef-boilerplate
CEF_TARGET_DIR = $(DPF_CUSTOM_TARGET_DIR)
CEF_BUILD_DIR = $(DPF_CUSTOM_BUILD_DIR)
CEF_PATH=/opt/cef_binary_87.1.13+g481a82a+chromium-87.0.4280.141_linux64_minimal
CEF_BIN_PATH = $(CEF_PATH)/Release
CEF_RES_PATH = $(CEF_PATH)/Resources
CEF_CXX = c++
CEF_CPPFLAGS = -I$(CEF_PATH)
CEF_CXXFLAGS = -DCEF_USE_SANDBOX -DNDEBUG -DWRAPPING_CEF_SHARED -D_FILE_OFFSET_BITS=64 -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -O3 -DNDEBUG -fno-strict-aliasing -fPIC -fstack-protector -funwind-tables -fvisibility=hidden --param=ssp-buffer-size=4 -pipe -pthread -Wall -Werror -Wno-missing-field-initializers -Wno-unused-parameter -Wno-error=comment -Wno-comment -m64 -march=x86-64 -fno-exceptions -fno-rtti -fno-threadsafe-statics -fvisibility-inlines-hidden -std=gnu++11 -Wsign-compare -Wno-undefined-var-template -Wno-literal-suffix -Wno-narrowing -Wno-attributes -O2 -fdata-sections -ffunction-sections -fno-ident -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2
CEF_LDFLAGS = -lcef_dll_wrapper -L$(BUILD_DIR) -lcef -L$(CEF_BIN_PATH) -lX11 -O3 -DNDEBUG -rdynamic -fPIC -pthread -Wl,--disable-new-dtags -Wl,--fatal-warnings -Wl,-rpath,. -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -m64 -Wl,-O1 -Wl,--as-needed -Wl,--gc-sections

# --------------------------------------------------------------
# DISTRHO project name, used for binaries

NAME = d_dpf_webview

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	WebViewPlugin.cpp

FILES_UI  = \
	WebViewUI.cpp \
	WebEngineThread.cpp \
	WebEngineMain.cpp \
	WebEngineHandler.cpp

# --------------------------------------------------------------
# Do some magic

UI_TYPE = cairo
include $(DPF_CUSTOM_PATH)/Makefile.plugins.mk

BASE_FLAGS += $(CEF_CPPFLAGS)
BASE_FLAGS += -Wno-unused-parameter 	# CEF headers throw a lot of these
LDFLAGS += $(CEF_LDFLAGS)
TARGETS += libcef_dll_wrapper

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

TARGETS += vst link_cef_bin link_cef_res

all: $(TARGETS)

include $(CEF_BOILERPLATE_PATH)/Makefile.deps.mk

# --------------------------------------------------------------
