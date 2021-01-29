(NEEDS UPDATE)

Dependencies:

- DPF develop branch, already linked as a git submodule in lib/dpf
- CEF binaries: download from https://cef-builds.spotifycdn.com/index.html ,
  for now choose the "Standard Distribution". Then uncompress to lib/cef .
  There is a lot of stuff here, libcef.so, V8 blobs, a sample program... this
  framework can be used to build a full-blown web browser.

CEF spawns some helper processes; after a custom helper is developed based on
the "cefsimple" program, it will be possible to use the "Minimal Distribution"
as a dependency instead of the bigger "Standard Distribution".

First step is building the dependencies:

- DPF graphics library: cd lib/dpf && make dgl
- CEF, requires CMake: cd lib/cef && mkdir build && cd build && cmake .. && make

Then build dpf-webui: make

For now all CEF binaries and resource files need to be linked into the host
binary path, otherwise CRASH. The Makefile already does so for the standalone
JACK app built in ./bin

Watch out for the harcoded paths in WebEngineThread.cpp !! otherwise CRASH

Host will CRASH sooner or later anyways


CEF's libcef.so requires the following libraries to be present:

libatk1.0-0
libatk-bridge2.0-0
libpango1.0-0
libpangocairo-1.0-0
libnss3
libxcomposite1
libxrandr2
libcups2
