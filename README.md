Very rough code for embedding a CEF web view in a DPF plugin
------------------------------------------------------------

Goal is to develop multiplatform audio plugins with web-based UIs based on the
great hassle-free DISTRHO Plugin Framework

* DPF project page: https://github.com/DISTRHO/DPF
* CEF project page: https://bitbucket.org/chromiumembedded/cef/

Depends on:

* DPF develop branch: https://github.com/DISTRHO/DPF/tree/develop
* CEF Makefile: https://github.com/lucianoiam/cef-boilerplate
* CEF binaries: https://cef-builds.spotifycdn.com/index.html

First step is running make on DPF and cef-boilerplate to build required static
libraries

For now all CEF binaries and resource files need to be linked into the host
binary path, otherwise CRASH

Watch out for the harcoded paths in WebEngineThread.cpp !! otherwise CRASH

I don't take responsibility of making your host CRASH because it will CRASH
sooner or later...

This is early work in progress...


![image](https://user-images.githubusercontent.com/930494/104860231-af54c980-592a-11eb-8c5a-49822eac6433.png)

![image](https://user-images.githubusercontent.com/930494/104858730-aad7e300-5921-11eb-9261-41bc3c3c7d2d.png)
