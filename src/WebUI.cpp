/*
 * dpf-webui
 * Copyright (C) 2021 Luciano Iam <lucianoiam@protonmail.com>
 *
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2019 Filipe Coelho <falktx@falktx.com>
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

#include "DistrhoUI.hpp"
#include "Window.hpp"
#include "CefMessageThread.hpp"

#include "BrowserHandler.hpp"

START_NAMESPACE_DISTRHO

class WebUI : public UI
{
public:
    WebUI()
        : UI(800, 600)
    {
        if (mInstances++ == 0) {
            sCefThread.startThread();
        }

        sCefThread.createBrowser(getParentWindow().getWindowId());

        // Also some hosts like REAPER recreate the parent window every time
        // the plugin UI is opened, we might let CEF create its own window
        // then reparent as needed -- possibly in onDisplay() ?
    }

    ~WebUI()
    {
        if (mInstances > 0) {
            mInstances--;
        
            if (mInstances == 0) {
                // TO DO -- cleanup browser but do not shutdown CEF as it cannot
                //          be re-initialized (insert link)
                //sCefThread.stopThread(1000);
            }
        }

        // Since the CEF window is a child of the DPF window, need to explicity
        // tell the browser to close. That will in turn call CefQuitMessageLoop()
        // effectively ending the CefMessageThread
        // https://bitbucket.org/chromiumembedded/cef/wiki/GeneralUsage#markdown-header-browser-life-span
        //mCefThread.closeBrowser();

        // Wait until CefQuitMessageLoop() is called
        //mCefThread.stopThread(1000);
    }

    void onDisplay()
    {
        // TODO
    }

    void parameterChanged(uint32_t index, float value)
    {
        // unused
        (void)index;
        (void)value;
    }

private:
    static CefMessageThread sCefThread;

    int mInstances;

};

CefMessageThread WebUI::sCefThread;

UI* createUI()
{
    return new WebUI;
}

END_NAMESPACE_DISTRHO
