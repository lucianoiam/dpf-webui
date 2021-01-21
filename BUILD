Dependencies:

* DPF develop branch, already linked as a git submodule
* CEF Makefile: https://github.com/lucianoiam/cef-boilerplate
* CEF binaries: https://cef-builds.spotifycdn.com/index.html


First step is running `make dgl` on lib/dpf and `make libcef_dll_wrapper`
on cef-boilerplate to build required static libraries

CEF spawns some helper processes; until a specialized target is developed
the "cefsimple" program is also needed: `make simple` on cef-boilerplate

For now all CEF binaries and resource files need to be linked into the host
binary path, otherwise CRASH

Watch out for the harcoded paths in WebEngineThread.cpp !! otherwise CRASH

Host will CRASH sooner or later anyways


CEF libcef.so requires the following libraries to be present:

libatk1.0-0
libatk-bridge2.0-0
libpango1.0-0
libpangocairo-1.0-0
libnss3
libxcomposite1
libxrandr2
libcups2
