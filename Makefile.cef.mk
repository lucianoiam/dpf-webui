# Created by lucianoiam

link_cef_deps: link_cef_bin link_cef_res

FILES_CEF_BIN = \
	chrome-sandbox \
	libEGL.so \
	libGLESv2.so \
	libcef.so \
	snapshot_blob.bin \
	swiftshader \
	v8_context_snapshot.bin

CEF_BIN_LINKED = $(FILES_CEF_BIN:%=$(DPF_CUSTOM_TARGET_DIR)/%)

link_cef_bin: $(CEF_BIN_LINKED)

$(DPF_CUSTOM_TARGET_DIR)/%: $(CEF_PATH)/Release/%
	@echo "Symlinking $< -> $@"
	@ln -s ../$< $@

FILES_CEF_RES = \
	cef.pak \
	cef_100_percent.pak \
	cef_200_percent.pak \
	cef_extensions.pak \
	devtools_resources.pak \
	icudtl.dat \
	locales

CEF_RES_LINKED = $(FILES_CEF_RES:%=$(DPF_CUSTOM_TARGET_DIR)/%)

link_cef_res: $(CEF_RES_LINKED)

$(DPF_CUSTOM_TARGET_DIR)/%: $(CEF_PATH)/Resources/%
	@echo "Symlinking $< -> $@"
	@ln -s ../$< $@
