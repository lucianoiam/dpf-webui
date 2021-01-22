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

#include "CefMain.hpp"
#include "DistrhoPluginInfo.h"

#include <string>

#include "include/cef_browser.h"
#include "include/wrapper/cef_helpers.h"

USE_NAMESPACE_DISTRHO

CefMain::CefMain(uintptr_t parentWindowId)
  : mParentWindowId(parentWindowId)
{
}

void CefMain::OnContextInitialized()
{
    CEF_REQUIRE_UI_THREAD();

    // BrowserHandler implements browser-level callbacks.
    mBrowserHandler = new BrowserHandler();

    // Specify CEF browser settings here.
    CefBrowserSettings browser_settings;

    // TODO - load content from disk
    std::string url = "https://distrho.sourceforge.io/";

    // Information used when creating the native window.
    CefWindowInfo window_info;

#if defined(OS_WIN)
    // On Windows we need to specify certain flags that will be passed to
    // CreateWindowEx().
    window_info.SetAsPopup(NULL, DISTRHO_PLUGIN_NAME);
#endif

    // TO DO
    window_info.parent_window = mParentWindowId;

    // Create the browser window.
    CefBrowserHost::CreateBrowser(window_info, mBrowserHandler, url, browser_settings,
                                nullptr, nullptr);
}