# Makefile for dpf-webui
# Created by lucianoiam

CEF_URL = https://cef-builds.spotifycdn.com/cef_binary_88.1.6+g4fe33a1+chromium-88.0.4324.96_linux64_minimal.tar.bz2

NAME = d_dpf_webui

BIN = \
	$(NAME) \
	$(NAME)-vst.so \
	$(NAME).lv2 \
	$(NAME)-dssi \
	$(NAME)-dssi.so \
	chrome-sandbox \
	libEGL.so \
	libGLESv2.so \
	libcef.so \
	snapshot_blob.bin \
	swiftshader \
	v8_context_snapshot.bin \
	cef.pak \
	cef_100_percent.pak \
	cef_200_percent.pak \
	cef_extensions.pak \
	devtools_resources.pak \
	icudtl.dat \
	locales

FILES_BIN = $(BIN:%=bin/%)

all: plugin/dpf helper/cef $(FILES_BIN)

plugin/dpf:
	echo 'Cloning DPF...'
	git submodule update --init

helper/cef:
	echo 'Downloading CEF binaries...'
	@set -e ;\
	tmpdir=`mktemp --tmpdir -d`; \
	ceffile=`basename $(CEF_URL)`; \
	cefdir=`basename $$ceffile .tar.bz2`; \
	wget -P $$tmpdir $(CEF_URL); \
	echo 'Uncompressing...'; \
	tar -xvjf $$tmpdir/$$ceffile -C helper/; \
	mv helper/$$cefdir helper/cef; \
	rm -rf $$tmpdir

bin/%:
	cd helper && make all && cd plugin && make all
