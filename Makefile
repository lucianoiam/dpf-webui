# Makefile for dpf-webui
# Created by lucianoiam

NAME = d_dpf_webui

BIN = \
	$(NAME) \
	$(NAME)-vst.so \
	$(NAME).lv2 \
	$(NAME)-dssi \
	$(NAME)-dssi.so \

FILES_BIN = $(BIN:%=bin/%)

all: plugin/dpf $(FILES_BIN)

plugin/dpf:
	git submodule update --init

bin/%:
	cd plugin && make

