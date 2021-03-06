/*
 * dpf-webui
 * Copyright (C) 2021 Luciano Iam <lucianoiam@protonmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "CefMessageThread.hpp"

#include <syslog.h>

#include "include/cef_app.h"

USE_NAMESPACE_DISTRHO

void CefMessageThread::run()
{
    // copied from cefsimple_linux.cc

    // CEF applications have multiple sub-processes (render, plugin, GPU, etc)
    // that share the same executable. This function checks the command-line and,
    // if this is a sub-process, executes the appropriate logic.

    // TODO -- create helper target, use CEF supplied for now

    /*int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
    if (exit_code >= 0) {
    // The sub-process has completed so return here.
    return; // exit_code;
    }*/

    // Specify CEF global settings here.
    CefSettings settings;

    settings.no_sandbox = true;
    //settings.log_severity = LOGSEVERITY_DEBUG;

    CefString(&settings.browser_subprocess_path).FromASCII(
        "/home/user/src/dpf-webui/lib/cef/build/tests/cefsimple/Release/cefsimple");
    CefString(&settings.resources_dir_path).FromASCII(
        "/home/user/src/dpf-webui/lib/cef/Resources");

    // CefMain implements application-level callbacks for the browser process.
    // It will create the first browser instance in OnContextInitialized() after
    // CEF has initialized.
    mMain = new CefMain();

    // Initialize CEF for the browser process.
    // CefInitialize() can only be called once per process
    // see https://bitbucket.org/chromiumembedded/cef/issues/421
    CefInitialize(CefMainArgs(), settings, mMain, nullptr);

    mCefInit = true;
    mCefInitSignal.signal();

    // Run the CEF message loop. This will block until CefQuitMessageLoop() is
    // called.

    syslog(LOG_INFO, "%p Running CEF message loop...", this);

    while (!shouldThreadExit()) {
        CefDoMessageLoopWork();
        usleep(10000);
    }
    //CefRunMessageLoop();
    
    syslog(LOG_INFO, "%p Quit CEF message loop...", this);

    // Shut down CEF.
    CefShutdown();
}

void CefMessageThread::waitForInit()
{
    // Block until CefInitialize() is called
    if (!mCefInit) {
        mCefInitSignal.wait();
    }

    // Block until CefApp::OnContextInitialized() is called
    mMain->waitForInit();
}

CefRefPtr<CefMain> CefMessageThread::getCefMain()
{
    return mMain;
}
