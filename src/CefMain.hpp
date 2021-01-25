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

#ifndef CEF_MAIN_HPP
#define CEF_MAIN_HPP

#include "DistrhoUI.hpp"
#include "include/cef_app.h"

#include "BrowserHandler.hpp"

START_NAMESPACE_DISTRHO

// Implement application-level callbacks for the browser process.
class CefMain : public CefApp, public CefBrowserProcessHandler
{
public:
    CefMain();

    CefRefPtr<BrowserHandler> getBrowserHandler()
    {
        return mBrowserHandler;
    }

    void createBrowser(uintptr_t parentWindowId);
    
    // CefApp methods:
    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE
    {
        return this;
    }

    // CefBrowserProcessHandler methods:
    virtual void OnContextInitialized() OVERRIDE;

private:
    CefRefPtr<BrowserHandler> mBrowserHandler;

    bool mContextInitialized;

    // Include the default reference counting implementation.
    IMPLEMENT_REFCOUNTING(CefMain);
};

END_NAMESPACE_DISTRHO

#endif  // CEF_MAIN_HPP
