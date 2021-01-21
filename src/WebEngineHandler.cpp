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

#include "WebEngineHandler.hpp"

#include <iostream>

#include "include/cef_app.h"
#include "include/wrapper/cef_helpers.h"

USE_NAMESPACE_DISTRHO

WebEngineHandler* g_instance = nullptr;

WebEngineHandler::WebEngineHandler() {
    DCHECK(!g_instance);
    g_instance = this;
}

WebEngineHandler::~WebEngineHandler() {
    g_instance = nullptr;
}

// static
WebEngineHandler* WebEngineHandler::GetInstance() {
    return g_instance;
}

bool WebEngineHandler::OnBeforePopup(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& target_url, const CefString& target_frame_name, CefLifeSpanHandler::WindowOpenDisposition target_disposition, bool user_gesture, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, CefRefPtr<CefClient>& client, CefBrowserSettings& settings, CefRefPtr<CefDictionaryValue>& extra_info, bool* no_javascript_access) {
    CEF_REQUIRE_UI_THREAD();

    // Disable popups, only the main browser is allowed
    return true;
}

void WebEngineHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
    CEF_REQUIRE_UI_THREAD();

    // Keep browser.
    mBrowserInstance = browser;
}

bool WebEngineHandler::DoClose(CefRefPtr<CefBrowser> browser) {
    CEF_REQUIRE_UI_THREAD();

    // Closing the main window requires special handling. See the DoClose()
    // documentation in the CEF header for a detailed destription of this
    // process.

    // Allow the close. For windowed browsers this will result in the OS close
    // event being sent.
    return false;
}

void WebEngineHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
    CEF_REQUIRE_UI_THREAD();

    // All browser windows have closed. Quit the application message loop.
    CefQuitMessageLoop();

    mBrowserInstance = nullptr;
}

void WebEngineHandler::OnLoadError(CefRefPtr<CefBrowser> browser,
                                    CefRefPtr<CefFrame> frame,
                                    ErrorCode errorCode,
                                    const CefString& errorText,
                                    const CefString& failedUrl) {
    CEF_REQUIRE_UI_THREAD();

    std::cout << errorText << std::endl;
}
